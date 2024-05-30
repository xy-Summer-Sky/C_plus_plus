//
// Created by Lenovo on 24-5-21.
//
#include"course.h"
Model::Course::Course(const std::string &name, const std::string &id, const std::string &teacherId) {
    name_ = name;
    id_ = id;
    teacherId_ = teacherId;
}

const std::string &Model::Course::getName() {
    return name_;
}

void Model::Course::setName(const std::string &name) {
    name_ = name;
}

const std::string &Model::Course::getId() {
    return id_;
}

void Model::Course::setId(const std::string &id) {
    id_ = id;
}

const std::string &Model::Course::getTeacherId() {
    return teacherId_;
}

void Model::Course::setTeacherId(const std::string &teacherId) {
    teacherId_ = teacherId;
}

// Created by Lenovo on 24-5-21.