#include "ClassThatUsesDB.h"

ClassThatUsesDB::ClassThatUsesDB(DBConnection* connection) : m_connection(connection) {}

bool ClassThatUsesDB::openConnection(){
	return m_connection->open();
}

MYSQL_RES ClassThatUsesDB::useConnection(std::string query){
	return m_connection->execQuery(query);
}

bool ClassThatUsesDB::closeConnection(){
	return m_connection->close();
}
