cmake_minimum_required(VERSION 3.28)
project(Cmake)
#set(MYSQL_ROOT_DIR "F:/MySQL/mysql-8.3.0-winx64")
set(CMAKE_PREFIX_PATH  "F:/MySQL/MySQLConnectorC++8.4" )
set(MYSQL_CONNECTOR_CPP_DIR "F:/MySQL/MySQLConnectorC++8.4")
include_directories(
        ${MYSQL_CONNECTOR_CPP_DIR}
        ${MYSQL_CONNECTOR_CPP_DIR}/include
        ${MYSQL_CONNECTOR_CPP_DIR}/lib64
        ${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc
        ${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc/cppconn
)

add_executable(Cmake main.cpp)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/lib64)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/bin)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc/cppconn)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14)
target_link_libraries(${PROJECT_NAME} mysqlcppconn8)
target_link_libraries(${PROJECT_NAME} mysqlcppconn)







