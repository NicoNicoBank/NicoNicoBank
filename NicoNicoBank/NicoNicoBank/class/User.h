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
	bool sqlread();
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

