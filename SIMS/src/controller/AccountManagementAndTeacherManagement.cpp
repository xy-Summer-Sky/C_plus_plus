//
// Created by Lenovo on 24-6-9.
//
#include"admincontroller.h"
#include "teacherinformation.h"
#include "useraccount.h"
#include "dbmanager.h"
#include "StudentScore.h"
void Controller::AdminController::addAccount(const QString &username, const QString &password, const QString &userType) {
    try {
        Model::UserAccount account(username.toStdString(), password.toStdString(), userType.toStdString());
        MYDB::DbManager::addAccount(account);
        emit operationSuccess("Successfully added account with username " + username);
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
    }

}

void Controller::AdminController::deleteAccount(const QString &username) {
    try {
        MYDB::DbManager::deleteAccount(username.toStdString());
        emit operationSuccess("Successfully deleted account with username " + username);
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
    }

}

void Controller::AdminController::updateAccount(const QString &username, const QString &password, const QString &userType) {

    try {
        Model::UserAccount account(username.toStdString(), password.toStdString(), userType.toStdString());
        MYDB::DbManager::updateAccount(account);
        emit operationSuccess("Successfully updated account with username " + username);
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
    }

}

Model::UserAccount Controller::AdminController::queryAccount(const QString &username) {
    try {
        Model::UserAccount account = MYDB::DbManager::queryAccount(username.toStdString());
        emit operationSuccess("Successfully queried account with username " + username);
        return account;
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
        return {};
    }

}

std::vector<Model::UserAccount> Controller::AdminController::displayAllAccounts() {
    try {
        std::vector<Model::UserAccount> accounts = MYDB::DbManager::displayAllAccounts();
        emit operationSuccess("Successfully displayed all accounts");
        return accounts;
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
        return {};
    }

}

void Controller::AdminController::addTeacher(const QString &name, const QString &id, const QString &email, const QString &phone) {
    try {
        Model::TeacherInformation teacher(name.toStdString(), id.toStdString(), email.toStdString(), phone.toStdString());
        MYDB::DbManager::addTeacherInformation(teacher);
        emit operationSuccess("Successfully added teacher with id " + id);
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
    }

}

void Controller::AdminController::deleteTeacher(const QString &id) {
    try {
        MYDB::DbManager::deleteTeacherInformation(id.toStdString());
        emit operationSuccess("Successfully deleted teacher with id " + id);
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
    }

}

void Controller::AdminController::updateTeacher(const QString &id, const QString &name, const QString &email, const QString &phone) {
    try {
        Model::TeacherInformation teacher(name.toStdString(), id.toStdString(), email.toStdString(), phone.toStdString());
        MYDB::DbManager::updateTeacherInformation(teacher);
        emit operationSuccess("Successfully updated teacher with id " + id);
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
    }

}

Model::TeacherInformation Controller::AdminController::queryTeacher(const QString &id) {
    try {
        Model::TeacherInformation teacher = MYDB::DbManager::getTeacherInformation(id.toStdString());
        emit operationSuccess("Successfully queried teacher with id " + id);
        return teacher;
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
        return {};
    }

}

std::vector<Model::TeacherInformation> Controller::AdminController::displayAllTeachers() {
    try {
        std::vector<Model::TeacherInformation> teachers = MYDB::DbManager::displayAllTeachers();
        emit operationSuccess("Successfully displayed all teachers");
        return teachers;
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
        return {};
    }

}

Model::TeacherInformation Controller::AdminController::getTeacherInfo(const QString& basicString) {
    try{
        Model::TeacherInformation teacher = MYDB::DbManager::getTeacherInformation(basicString.toStdString());
        return teacher;
    }catch
    (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
        return {};
    }

}

void Controller::AdminController::updateScore(const QString &studentId, const QString &courseId, const QString &score) {
    try {
        Model::StudentScore studentscore(studentId.toStdString(), courseId.toStdString(), score.toStdString());
        MYDB::DbManager::updateScore(studentscore);
        emit operationSuccess("Successfully updated score for student with id " + studentId + " in course with id " + courseId);
    } catch (const std::runtime_error &e) {
        emit errorOccured(QString::fromStdString(e.what()));
    }

}





