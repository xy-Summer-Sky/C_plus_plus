#include<windows.h>
#include "F:\MySQL\MySQLConnectorC++8.4\include\jdbc\cppconn\statement.h"
#include "F:\MySQL\MySQLConnectorC++8.4\include\jdbc\cppconn\exception.h"
#include "F:\MySQL\MySQLConnectorC++8.4\include\jdbc\mysql_driver.h"
#include <iostream>
#include <string>
#include"cppconn/prepared_statement.h"
#include <memory>
#include <cppconn/resultset.h>



int main() {
    std::string sql1 = "select * from useraccounts";//sql1用于创建testmysql数据库
    SetConsoleOutputCP(CP_UTF8);

    sql::mysql::MySQL_Driver* driver = nullptr;
    sql::Statement* stmt;
    // 注册MySQL驱动程序

    driver = sql::mysql::get_mysql_driver_instance();

    sql::Connection * con=driver->connect("localhost:3306","root","helloworld");
    if(con==NULL)
    {
        std::cout<<"Connection failed!"<<std::endl;//打印连接失败的消息
        return 1;
    }
    std::cout<<"Connection successful!"<<std::endl;//打印连接成功的消息
//    std::cout<<"Connecting to database testmysql"<<std::endl;
std::cout<<"1";
    con->setSchema("sims");
    std::cout<<"2";

    stmt = con->createStatement();
    std::cout<<"3";
    sql::ResultSet *res = stmt->executeQuery("SELECT USERID from useraccounts");
    std::cout<<"4";
    while (res->next()) {
        std::cout << "USERID: " << res->getString("USERID") << std::endl;
    }

    std::cout<<"5";

    std::string userID = "1";
    std::string password = "1";
    std::string userType = "admin";
    std::unique_ptr<sql::PreparedStatement> stmt2(con->prepareStatement("SELECT * FROM useraccounts WHERE USERID = ? AND PASSWORD = ? AND TYPE = ?"));
    stmt2->setString(1, userID);
    stmt2->setString(2, password);
    stmt2->setString(3, userType);
    sql::ResultSet *res3=stmt2->executeQuery();
    while (res3->next()) {
        std::cout << "USERID: " << res3->getString("USERID") << std::endl;
    }
    delete res;


    return 0;
}