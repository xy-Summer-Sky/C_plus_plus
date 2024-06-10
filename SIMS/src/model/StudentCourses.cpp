#include"StudentCourses.h"

Model::StudentCourses::StudentCourses(const std::string &studentId) {
    student_id_ = studentId;
}


const std::string &Model::StudentCourses::getStudentId() const {
    return student_id_;
}

void Model::StudentCourses::setStudentId(const std::string &studentId) {
    student_id_ = studentId;
}

const std::vector<std::string> &Model::StudentCourses::getCourseIDs() {

    return courses;
}

void Model::StudentCourses::addCourse(const std::string &courseId) {
    courses.push_back(courseId);
}

void Model::StudentCourses::removeCourse(const std::string &courseId) {
    courses.erase(std::remove(courses.begin(), courses.end(), courseId), courses.end());
}

// Created by Lenovo on 24-5-21.