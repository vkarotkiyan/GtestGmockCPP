#pragma once
#include <string>
#if defined (_WIN64) || defined(_WIN32)
#include <mysql.h>
#elif defined (__linux__)
#include <mysql/mysql.h>
#endif

class DBConnection{
public:
	virtual ~DBConnection() = default;
	virtual bool open() = 0;
	virtual bool close() = 0;
	virtual MYSQL_RES execQuery(std::string query) = 0;
};
