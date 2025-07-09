#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../ClassThatUsesDB.h"

std::string TEST_QUERY = "SELECT * FROM users";

class MockDBConnection : public DBConnection {
public:
	MOCK_METHOD(bool, open, (), (override)) {};
	MOCK_METHOD(bool, close, (), (override)) {};
	MOCK_METHOD(MYSQL_RES, execQuery, (std::string query), (override)) {};
};

TEST(ClassThatUsesDB, openConnection){
	MockDBConnection connection;
	EXPECT_CALL(connection, open).Times(::testing::AtLeast(1));
	ClassThatUsesDB userDB(&connection);
	userDB.openConnection();
}

TEST(ClassThatUsesDB, useConnection){
	MockDBConnection connection;
	EXPECT_CALL(connection, execQuery).Times(::testing::AtLeast(1));
	ClassThatUsesDB userDB(&connection);
	userDB.useConnection(TEST_QUERY);
}

TEST(ClassThatUsesDB, closeConnection){
	MockDBConnection connection;
	EXPECT_CALL(connection, close).Times(::testing::AtLeast(1));
	ClassThatUsesDB userDB(&connection);
	userDB.closeConnection();
}
