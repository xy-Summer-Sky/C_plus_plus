//
// Created by Lenovo on 24-5-21.
//
// StudentCourse.h
#ifndef SIMS_STUDENTCOURSES_H
#define SIMS_STUDENTCOURSES_H

#include <string>
#include <vector>

namespace Model {

    //学生课程类
    class StudentCourses {
    public:
        explicit StudentCourses(const std::string &studentId);

        ~StudentCourses() = default;

        //获取学生id
        const std::string &getStudentId() const;

        void setStudentId(const std::string &studentId);//设置学生id

        const std::vector<std::string> &getCourseIDs();//获取课程id

        void addCourse(const std::string &courseId);//添加课程

        void removeCourse(const std::string &courseId);//移除课程


    private:
        std::string student_id_;
        std::vector<std::string> courses;
    };

}

#endif