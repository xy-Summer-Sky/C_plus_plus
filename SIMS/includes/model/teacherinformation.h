//
// Created by Lenovo on 24-6-3.
//

#ifndef SIMS_TEACHERINFORMATION_H
#define SIMS_TEACHERINFORMATION_H
#include <string>
namespace Model
{
    //教师信息类
    class TeacherInformation
    {
    public:
        TeacherInformation();

        TeacherInformation(const std::string &name, const std::string &id, const std::string &email, const std::string &phone_number);

        const std::string &getName();//获取教师名

        void setName(const std::string &name);//设置教师名

        const std::string &getId();//获取教师id

        void setId(const std::string &id);//设置教师id

        const std::string &getEmail();//获取教师邮箱

        void setEmail(const std::string &email);//设置教师邮箱

        const std::string &getPhoneNumber();//获取教师电话号码

        void setPhoneNumber(const std::string &phone_number);//设置教师电话号码

    private:
        std::string name_;
        std::string id_;
        std::string email_;
        std::string phone_number_;
    };
}
#endif //SIMS_TEACHERINFORMATION_H
