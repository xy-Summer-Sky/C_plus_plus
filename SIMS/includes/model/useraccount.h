//
// Created by Lenovo on 24-6-9.
//

#ifndef SIMS_USERACCOUNT_H
#define SIMS_USERACCOUNT_H
#include<string>
namespace Model {

    //用户账户类
    class UserAccount {
    private:
        std::string username_;
        std::string password_;
        std::string userType_;
    public:
        UserAccount();
        UserAccount(const std::string &username, const std::string &password, const std::string &userType);
        const std::string &getUsername();//获取用户名
        void setUsername(const std::string &username);//设置用户名
        const std::string &getPassword();//获取密码
        void setPassword(const std::string &password);//设置密码
        const std::string &getUserType();//获取用户类型
        void setUserType(const std::string &userType);//设置用户类型

    };

}
#endif //SIMS_USERACCOUNT_H
