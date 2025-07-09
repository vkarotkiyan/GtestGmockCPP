cmake_minimum_required(VERSION 3.10)

project(DBConnectionTests LANGUAGES CXX)

set(
    CMAKE_CXX_STANDARD 20
    CMAKE_CXX_STANDARD_REQUIRED ON 
    CXX_EXTENSIONS NO 
)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

if(WIN32)
    include_directories("C:/Program\ Files/MySQL/MySQL\ Server\ 8.0/include")
    target_link_libraries(${PROJECT_NAME} "C:/Program\ Files/MySQL/MySQL\ Server 8.0/lib/libmysql.lib")
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} /usr/lib/x86_64-linux-gnu/libmysqlclient.so)
endif()

add_subdirectory(tests)
