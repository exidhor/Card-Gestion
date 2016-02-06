#include "SqlCreator.h"

SqlCreator::SqlCreator(char* dbname)
{
	m_sqlObject = 0;
	m_err_msg = 0;
	m_isConnectedToDB = false;

	openDB(dbname);
}

SqlCreator::~SqlCreator()
{
	sqlite3_close(m_sqlObject);
}

void SqlCreator::openDB(char* dbname)
{
	int rc = sqlite3_open(dbname, &m_sqlObject);

	if (rc != SQLITE_OK) {

		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(m_sqlObject));
		sqlite3_close(m_sqlObject);
		m_isConnectedToDB = false;
	}
	else
	{
		m_isConnectedToDB = true;
	}
}

void SqlCreator::query(char* request)
{
	if (!isConnectedToDB())
		return;

	int rc = sqlite3_exec(m_sqlObject, request, 0, 0, &m_err_msg);

	if (rc != SQLITE_OK) {

		fprintf(stderr, "SQL error: %s\n", m_err_msg);

		sqlite3_free(m_err_msg);
		sqlite3_close(m_sqlObject);
	}
}

void SqlCreator::query(char* request, int(*callback)(void*, int, char**, char**))
{
	if (!isConnectedToDB())
		return;

	int rc = sqlite3_exec(m_sqlObject, request, callback, 0, &m_err_msg);

	if (rc != SQLITE_OK) {

		fprintf(stderr, "SQL error: %s\n", m_err_msg);

		sqlite3_free(m_err_msg);
		sqlite3_close(m_sqlObject);
	}
}

bool SqlCreator::isConnectedToDB()
{
	if (!m_isConnectedToDB)
	{
		"SQL is not linked to a DB";
		return false;
	}
	return true;
}