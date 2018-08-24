#include "User.h"
#include "sqlite3.h"
#include "Func.h"
User::User()
{
}


User::~User()
{
}

User::User(string account, string userName, string password, string address, string IDNumber, Date openDate, bool isLost, Date lostDate, int id = -1)
{
	this->id = id;
	this->account = account;
	this->userName = userName;
	this->password = password;
	this->address = address;
	this->IDNumber = IDNumber;
	this->openDate = openDate;
	this->isLost = isLost;
	this->lostDate = lostDate;
}

bool User::sqlread()
{	
	sqlite3 * conn = NULL;
	char * err_msg = NULL;
	char sql[200] = "";
	string sql_temp = "SELECT * From user where id = " + to_string(id);
	if (sqlite3_open("D:\\c++ study\\nicobank\\NicoNicoBank\\NicoNicoBank\\database\\bank", &conn) != SQLITE_OK) {
		return false;
	}
	char** result;
	int nrow;
	int ncolumn;
	sqlite3_get_table(conn, sql_temp.c_str(), &result, &nrow, &ncolumn, &err_msg);
	if (nrow == 0) {
		return false;
	}
	this->id = id;
	//��ȡǰ5���ı�
	string temp(result[1 * ncolumn + 1]);
	this->account = temp;
	temp = result[1 * ncolumn + 2];
	this->userName = temp;
	temp = result[1 * ncolumn + 3];
	this->password = temp;
	temp = result[1 * ncolumn + 4];
	this->address = temp;
	temp = result[1 * ncolumn + 5];
	this->IDNumber = temp;
	//��ȡ���ڵ�����, 6 7 8Ϊ��������, 9Ϊ�Ƿ��ʧ,10 11 12 Ϊ��ʧ����
	sqlite3_stmt* stmt = NULL;
	sqlite3_prepare_v2(conn, sql_temp.c_str(), -1, &stmt, 0);
	int resultCode = sqlite3_step(stmt);
	int year = sqlite3_column_int(stmt, 6);
	int month = sqlite3_column_int(stmt, 7);
	int day = sqlite3_column_int(stmt, 8);
	this->openDate.setDate(year, month, day);
	int islost = sqlite3_column_int(stmt, 9);
	this->isLost = islost;
	year = sqlite3_column_int(stmt, 10);
	month = sqlite3_column_int(stmt, 11);
	day = sqlite3_column_int(stmt, 12);
	this->lostDate.setDate(year, month, day);
	sqlite3_finalize(stmt);
	return true;
}

bool User::sqlwrite()
{	
	string sql = "";
	bool flag = false;
	if (sqlread() && id != -1) {
		flag = true;
		sql = "update user set account = ?,userName = ?,password = ?,address = ?,IDNumber = ?,openDate_year = ?,openDate_month = ?,openDate_day = ?,isLost = ?,lostDate_year = ?,lostDate_month = ?,lostDate_day = ? where id = ?;";
	}
	else {
		sql = "insert into user (account, userName, password, address, IDNumber, openDate_year,openDate_month, openDate_day, isLost, lostDate_year, lostDate_month, lostDate_day) values  (?,?,?,?,?,?,?,?,?,?,?,?);";
	}
	
	//sqlite3_bind_blob(stat, 1, &(date), sizeof(this->openDate), NULL);
	//sqlite3_bind_int(stmt, 1, id);
	string tempStr[] = { this->account, this->userName, this->password, this->address, this->IDNumber };
	int tempInt[] = { openDate.get(0), openDate.get(1), openDate.get(2), isLost, lostDate.get(0), lostDate.get(1), lostDate.get(2) };
	
	sqlite3 * conn;
	if (sqlite3_open("d:\\c++ study\\nicobank\\niconicobank\\niconicobank\\database\\bank.db", &conn) != SQLITE_OK) {
		return false;
	}
	sqlite3_stmt * stmt = NULL;
	//sql���׼��
	//string sql = "insert into user (account, userName, password, address, IDNumber, openDate_year,openDate_month, openDate_day, isLost, lostDate_year, lostDate_month, lostDate_day) values  (?,?,?,?,?,?,?,?,?,?,?,?);";
	//(id, account, username, password, address, idnumber, opendate_year,opendate_month, opendate_day, islost, lostdate_year, lostdate_month, lostdate_day)
	//�����������
	sqlite3_prepare_v2(conn, sql.c_str(), -1, &stmt, 0);
	for (int i = 1; i <= 5; i++) {
		sqlite3_bind_text(stmt, i, tempStr[i - 1].c_str(), -1, NULL);
	}
	for (int i = 6; i <= 12; i++) {
		sqlite3_bind_int(stmt, i, tempInt[i - 6]);
	}
	if (flag) {
		sqlite3_bind_int(stmt, 13, id);
	}
	//ִ��
	int result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	return false;
}


