//
// Created by Lenovo on 24-6-10.
//

#include "StudentScore.h"
Model::StudentScore::StudentScore() = default;
Model::StudentScore::StudentScore(const std::string &studentId, const std::string &courseId, const std::string &score) : studentId(studentId), courseId(courseId), score(score) {

    this->studentId = studentId;
    this->courseId = courseId;
    this->score = score;
}


const std::string & Model::StudentScore::getStudentId() const {
    return studentId;
}

void Model::StudentScore::setStudentId(const std::string &string) {
    StudentScore::studentId = string;
}

const std::string &Model::StudentScore::getCourseId() const {
    return courseId;
}

void Model::StudentScore::setCourseId(const std::string &id) {
    StudentScore::courseId = id;
}

const std::string &Model::StudentScore::getScore() const {
    return score;
}

void Model::StudentScore::setScore(const std::string &studentScore) {
    StudentScore::score = studentScore;
}

// Created by Lenovo on 24-6-10.