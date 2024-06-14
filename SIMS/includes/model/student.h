//
// Created by Lenovo on 24-5-21.
//

#ifndef SIMS_STUDENT_H
#define SIMS_STUDENT_H
#include <vector>
#include <string>
namespace Model {
    //学生类
    class StudentDTO {
    public:
        StudentDTO();

        StudentDTO(const std::string &name, const std::string &id, const std::string &email,const std::string &phoneNumber);

        const std::string &getName() const;//获取学生名

        void setName(const std::string &name);//设置学生名

        const std::string &getId() const;//获取学生id

        void setId(const std::string &id);//设置学生id

        std::string getEmail() const;//获取学生邮箱

        void setEmail(const std::string &email);//设置学生邮箱

        std::string getPhoneNumber() const;//获取学生电话号码

        void setPhoneNumber(const std::string &phoneNumber);//设置学生电话号码

    private:
        std::string name_;
        std::string id_;
        std::string email_;
        std::string phoneNumber_;


    };
};

#endif //SIMS_STUDENT_H

