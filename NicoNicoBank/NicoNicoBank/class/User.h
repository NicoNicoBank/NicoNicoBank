#pragma once
#include <string>
#include <cstring>
#include "Date.h"
#include <windows.h>
using namespace std;
class User
{
public:
	User();
	~User();
	/*
	Date���ʼ������С��0�����ɴ�����ֵ
	*/
	User(string account, string userName, string password, string address, string IDNumber, Date openDate, bool isLost, Date lostDate, int id);
	/*
	���ݵ�ǰidֵ��ȡ���и�idֵ�µ�user���е�����
	*/
	bool read();
	/*
	����ǰ��������д�����ݿ�, id������Ϊ���£�idΪ-1���ʾ����
	*/
	bool save();
private:
	int id;  //Ψһ��ʶ
	string account; // �˺�
	string userName;  // ����
	string password; // ����
	string address;// ��ַ
	string IDNumber;// ���֤����
	Date openDate;// ��������
	bool isLost;// �Ƿ��ʧ
	Date lostDate;// ��ʧ����

};

