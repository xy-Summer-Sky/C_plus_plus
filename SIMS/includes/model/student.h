//
// Created by Lenovo on 24-5-21.
//

#ifndef SIMS_STUDENT_H
#define SIMS_STUDENT_H
#include <vector>
#include <string>
namespace Model {
    class StudentDTO {
    public:
        StudentDTO(const std::string &name, const std::string &id, const std::string &email,
                   const std::string &phoneNumber);

        const std::string &getName() const;

        void setName(const std::string &name);


        const std::string &getId() const;


        void setId(const std::string &id);

        const std::string getEmail() const;

        void setEmail(const std::string &email);

        const std::string getPhoneNumber() const;

        void setPhoneNumber(const std::string &phoneNumber);


    private:
        std::string name_;
        std::string id_;
        std::string email_;
        std::string phoneNumber_;


    };
};

#endif //SIMS_STUDENT_H

