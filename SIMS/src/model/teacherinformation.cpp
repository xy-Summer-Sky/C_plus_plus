//
// Created by Lenovo on 24-6-3.
//
#include"teacherinformation.h"
Model::TeacherInformation::TeacherInformation() = default;

Model::TeacherInformation::TeacherInformation(const std::string &name, const std::string &id, const std::string &email,
                                              const std::string &phone_number) {
    name_ = name;
    id_ = id;
    email_ = email;
    phone_number_ = phone_number;
}

const std::string &Model::TeacherInformation::getName() {
    return name_;
}

void Model::TeacherInformation::setName(const std::string &name) {
    name_ = name;
}

const std::string &Model::TeacherInformation::getId() {
    return id_;
}

void Model::TeacherInformation::setId(const std::string &id) {
    id_ = id;
}

const std::string &Model::TeacherInformation::getEmail() {
    return email_;
}

void Model::TeacherInformation::setEmail(const std::string &email) {
    email_ = email;
}

const std::string &Model::TeacherInformation::getPhoneNumber() {
    return phone_number_;
}

void Model::TeacherInformation::setPhoneNumber(const std::string &phone_number) {
    phone_number_ = phone_number;
}

// Created by Lenovo on 24-6-3.