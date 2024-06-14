//
// Created by Lenovo on 24-5-21.
//

#ifndef SIMS_COURSE_H
#define SIMS_COURSE_H

#include <string>

namespace Model {

    //课程类
    class Course {
    public:
        Course();

        Course(const std::string &name, const std::string &id, const std::string &teacherId);

        const std::string &getName();//获取课程名

        void setName(const std::string &name);//设置课程名

        const std::string &getId();//获取课程id

        void setId(const std::string &id);//设置课程id

        const std::string &getTeacherId();//获取教师id

        void setTeacherId(const std::string &teacherId);//设置教师id
    private:
        std::string name_;
        std::string id_;
        std::string teacherId_;
    };

}


#endif //SIMS_COURSE_H
