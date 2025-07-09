project(tests)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY http://github.com/google/googletest.git 
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
add_library(GMock::GMock INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
target_link_libraries(GMock::GMock INTERFACE gmock_main)

add_executable(
    ${PROJECT_NAME}
#    test_placeholder.cpp
    test_dbconn.cpp
    ../ClassThatUsesDB.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::GTest)
target_link_libraries(${PROJECT_NAME} PRIVATE GMock::GMock)
