//
// Created by Lenovo on 24-5-21.
//
#include"student.h"

Model::StudentDTO::StudentDTO(const std::string &name, const std::string &id, const std::string &email,
                              const std::string &phoneNumber) {
    name_ = name;
    id_ = id;
    email_ = email;
    phoneNumber_ = phoneNumber;
}

const std::string &Model::StudentDTO::getName() const {
    return name_;
}

void Model::StudentDTO::setName(const std::string &name) {
    name_ = name;
}

const std::string &Model::StudentDTO::getId() const {
    return id_;
}

void Model::StudentDTO::setId(const std::string &id) {
    id_ = id;
}

std::string Model::StudentDTO::getEmail() const {
    return email_;
}

void Model::StudentDTO::setEmail(const std::string &email) {
    email_ = email;
}

std::string Model::StudentDTO::getPhoneNumber() const {
    return phoneNumber_;
}

void Model::StudentDTO::setPhoneNumber(const std::string &phoneNumber) {
    phoneNumber_ = phoneNumber;
}

Model::StudentDTO::StudentDTO() = default;

// Created by Lenovo on 24-5-21.
