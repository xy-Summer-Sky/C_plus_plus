// Last modified: 2021.04.10 01:00:00
#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include "dbmanager.h"
#include <string>

namespace Controller{

class LoginController {
public:
    LoginController();
     ~LoginController();

    bool validateUser(const std::string &userId, const std::string &password, const std::string &userType) ;


private:
    MYDB::DbManager* m_db;
};

}

#endif
