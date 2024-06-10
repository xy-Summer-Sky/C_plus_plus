//
// Created by Lenovo on 24-6-3.
//

#ifndef SIMS_TEACHERINFORMATION_H
#define SIMS_TEACHERINFORMATION_H
#include <string>
namespace Model
{
    class TeacherInformation
    {
    public:
        TeacherInformation();

        TeacherInformation(const std::string &name, const std::string &id, const std::string &email, const std::string &phone_number);

        const std::string &getName();

        void setName(const std::string &name);

        const std::string &getId();

        void setId(const std::string &id);

        const std::string &getEmail();

        void setEmail(const std::string &email);

        const std::string &getPhoneNumber();

        void setPhoneNumber(const std::string &phone_number);

    private:
        std::string name_;
        std::string id_;
        std::string email_;
        std::string phone_number_;
    };
}
#endif //SIMS_TEACHERINFORMATION_H
