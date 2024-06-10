//
// Created by Lenovo on 24-6-9.
//

#ifndef SIMS_USERACCOUNT_H
#define SIMS_USERACCOUNT_H
#include<string>
namespace Model {

    class UserAccount {
    private:
        std::string username_;
        std::string password_;
        std::string userType_;
    public:
        UserAccount();
        UserAccount(const std::string &username, const std::string &password, const std::string &userType);
        const std::string &getUsername();
        void setUsername(const std::string &username);
        const std::string &getPassword();
        void setPassword(const std::string &password);
        const std::string &getUserType();
        void setUserType(const std::string &userType);

    };

} // Model

#endif //SIMS_USERACCOUNT_H
