//
// Created by Lenovo on 24-5-21.
//

#include "logincontroller.h"

MYDB::DbManager* Controller::LoginController::m_db = nullptr;
Controller::LoginController::LoginController() {
    m_db = new MYDB::DbManager();
}

Controller::LoginController::~LoginController() {
    if (m_db != nullptr) {
        delete m_db;
        m_db = nullptr;
    }
}


bool Controller::LoginController::validateUser(const std::string &userID, const std::string &password,const std::string &userType) {

    if (m_db == nullptr) {
        m_db = new MYDB::DbManager();
    }
    bool status = MYDB::DbManager::validateUser(userID, password, userType);

    if (status == false) {
        delete m_db;
        m_db = nullptr;
    }

    return status;
}






