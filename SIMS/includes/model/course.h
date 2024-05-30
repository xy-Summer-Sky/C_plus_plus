//
// Created by Lenovo on 24-5-21.
//

#ifndef SIMS_COURSE_H
#define SIMS_COURSE_H

#include <string>

namespace Model {

    class Course {
    public:
        Course(const std::string &name, const std::string &id, const std::string &teacherId);

        const std::string &getName();

        void setName(const std::string &name);


        const std::string &getId();

        void setId(const std::string &id);

        const std::string &getTeacherId();

        void setTeacherId(const std::string &teacherId);
    private:
        std::string name_;
        std::string id_;
        std::string teacherId_;
    };

}


#endif //SIMS_COURSE_H
