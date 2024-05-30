// Constructor
#include "dbmanager.h"
#include"cppconn/prepared_statement.h"
MYDB::DbManager::DbManager(const std::string& hostName, const std::string& dbName, const std::string& userName, const std::string& password) {
    driver = sql::mysql::get_driver_instance();
    try {
        con=driver->connect("localhost:3306","root","helloworld");
        if(con==nullptr)
        {
            std::cout<<"Connection failed!"<<std::endl;
            return;
        }
        con->setSchema(dbName);
    } catch (const sql::SQLException& e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
}

// Destructor
MYDB::DbManager::~DbManager() {
    closeConnection();
}

// Validate user
bool MYDB::DbManager::validateUser(const std::string& userID, const std::string& password, const std::string& userType) {
    if (!openConnection()) {
        return false;
    }

    try {

        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement("SELECT * FROM useraccounts WHERE USERID = ? AND PASSWORD = ? AND TYPE = ?"));
        stmt->setString(1, userID);
        stmt->setString(2, password);
        stmt->setString(3, userType);
        sql::ResultSet* res=stmt->executeQuery();

        if (res->next()) {
            std::cout << "User exists" << std::endl;
            return true;
        } else {
            std::cout << "User does not exist" << std::endl;
            return false;
        }
    } catch (const sql::SQLException& e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        return false;
    }
}

// Open Connection
bool MYDB::DbManager::openConnection() {
    return con != nullptr && !con->isClosed();
}

// Close Connection
void MYDB::DbManager::closeConnection() {
    if (con != nullptr && !con->isClosed()) {
        con->close();
    }
}


