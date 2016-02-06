#pragma once
#include <stdio.h>
#include "sqlite3.h"

class SqlCreator
{
private:
	sqlite3* m_sqlObject;
	char* m_err_msg;
	bool m_isConnectedToDB;
public:
	SqlCreator(char* dbname);
	~SqlCreator();

	void openDB(char* dbname);
	void query(char* request);
	void query(char* request, int(*callback)(void*, int, char**, char**));
	
	bool isConnectedToDB();
};