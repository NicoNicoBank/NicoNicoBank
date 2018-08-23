#include "User.h"
#include "sqlite3.h"

User::User()
{
}


User::~User()
{
}

bool User::sqlread()
{
	sqlite3 * conn = NULL;
	char * err_msg = NULL;
	char sql[200] = "";

	if (sqlite3_open("bank", &conn) != SQLITE_OK) {
		return false;
	}

}
