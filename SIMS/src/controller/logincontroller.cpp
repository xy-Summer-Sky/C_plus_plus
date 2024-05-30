//
// Created by Lenovo on 24-5-21.
//

#include "logincontroller.h"


    Controller::LoginController::LoginController() {
        m_db = new MYDB::DbManager("localhost", "sims", "root", "helloworld");
    }

    Controller::LoginController::~LoginController() {
        if (m_db != nullptr) {
            delete m_db;
            m_db = nullptr;
        }
    }


    bool Controller::LoginController::validateUser(const std::string &userID, const std::string &password,const std::string &userType) {



        if(m_db==nullptr)
        {
            m_db=new MYDB::DbManager("localhost", "sims", "root", "helloworld");
        }
        bool status=m_db->validateUser(userID, password, userType);
        if(status==false)
        {
            delete m_db;
            m_db=nullptr;
        }

        return status;
    }


