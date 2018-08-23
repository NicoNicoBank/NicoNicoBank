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
	int id;  //唯一标识
	string account; // 账号
	string userName;  // 姓名
	string password; // 密码
	string address;// 地址
	string IDNumber;// 身份证号码
	Date openDate;// 开户日期
	bool isLost;// 是否挂失
	Date lostDate;// 挂失日期

};

