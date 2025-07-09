#pragma once
#include "DBConnection.h"

class ClassThatUsesDB{
public:
	ClassThatUsesDB(DBConnection* connection);
	~ClassThatUsesDB() = default;
	bool openConnection();
	MYSQL_RES useConnection(std::string query);
	bool closeConnection();
private:
	DBConnection* m_connection;
};
