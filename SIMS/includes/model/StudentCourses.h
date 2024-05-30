//
// Created by Lenovo on 24-5-21.
//
// StudentCourse.h
#ifndef SIMS_STUDENTCOURSES_H
#define SIMS_STUDENTCOURSES_H

#include <string>
#include <vector>

namespace Model {

    class StudentCourses {
    public:
        explicit StudentCourses(const std::string& studentId);

        ~StudentCourses()= default;

        const std::string &getStudentId() const;

        void setStudentId(const std::string &studentId);

        const std::vector<std::string>& getCourseIDs();

        void addCourse(const std::string& courseId);

        void removeCourse(const std::string& courseId);




    private:
        std::string student_id_;
        std::vector<std::string> courses;
    };

}

#endif //SIMS_STUDENTCOURSES_H