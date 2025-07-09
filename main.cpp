#include <iostream>
#include "ClassThatUsesDB.h"

int main(int argc, char* argv[]){
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();

    ClassThatUsesDB clUseDB(DBConnection* dbconn);
}
