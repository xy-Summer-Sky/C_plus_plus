//
// Created by Lenovo on 24-6-9.
//

#include "useraccount.h"

namespace Model {
    UserAccount::UserAccount(const std::string &username, const std::string &password, const std::string &userType) {
        username_ = username;
        password_ = password;
        userType_ = userType;


    }

    const std::string &UserAccount::getUsername() {
        return username_;
    }

    void UserAccount::setUsername(const std::string &username) {
        username_ = username;
    }

    const std::string &UserAccount::getPassword() {
        return password_;
    }

    void UserAccount::setPassword(const std::string &password) {
        password_ = password;
    }

    const std::string &UserAccount::getUserType() {
        return userType_;
    }

    void UserAccount::setUserType(const std::string &userType) {
        userType_ = userType;
    }

    UserAccount::UserAccount() {

    }

} // Model