//
// Created by Lenovo on 24-5-21.
//
#include "admincontroller.h"
#include "student.h"
#include "course.h"

namespace Controller {
    MYDB::DbManager *Controller::AdminController::dbManager = nullptr;

    AdminController::AdminController() {
        dbManager = new MYDB::DbManager();

    };


    AdminController::~AdminController() {
        if (dbManager != nullptr) {
            delete dbManager;
            dbManager = nullptr;
        }
    }

    void AdminController::deleteStudent(const QString &id) {
        try {
            bool success = MYDB::DbManager::deleteStudent(id.toStdString());
            if (success) {
                emit operationSuccess("Successfully deleted student with id " + id);
            } else {
                emit errorOccured("Failed to delete student with id " + id);
            }
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
        }
    }

    void AdminController::addCourse(const QString &name, const QString &id, const QString &teacherId) {
        try {
            Model::Course course(name.toStdString(), id.toStdString(), teacherId.toStdString());
            MYDB::DbManager::addCourse(course);
            emit operationSuccess("Successfully added course with id " + id);
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
        }
    }


    void AdminController::updateCourse(const QString &id, const QString &name, const QString &teacherId) {
        try {
            Model::Course course(name.toStdString(), id.toStdString(), teacherId.toStdString());
            MYDB::DbManager::updateCourse(course);
            emit operationSuccess("Successfully updated course with id " + id);
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
        }
    }

    void AdminController::deleteCourse(const QString &id) {
        try {
            bool success = MYDB::DbManager::deleteCourse(id.toStdString());
            if (success) {
                emit operationSuccess("Successfully deleted course with id " + id);
            } else {
                emit errorOccured("Failed to delete course with id " + id);
            }
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
        }
    }

    void AdminController::saveStudent(const Model::StudentDTO &dto) {
        try {
            std::cout << "2" << std::endl;
            MYDB::DbManager::addStudent(dto);
            std::cout << "1" << std::endl;
            emit operationSuccess("Successfully added student with id " + QString::fromStdString(dto.getId()));
        } catch (const std::runtime_error &e) {
            std::cout << "4" << std::endl;
            emit errorOccured(QString::fromStdString(e.what()));
            std::cout << "3" << std::endl;
            return;
        }

    }

    auto AdminController::queryStudent(const std::string &String) -> Model::StudentDTO {

        try {
            Model::StudentDTO student = MYDB::DbManager::queryStudent(String);
            if (student.getId().empty())
                    emit errorOccured("Student not found");
            else
                emit operationSuccess("Successfully queried student with id " + QString::fromStdString(student.getId()));
            return student;
        }
        catch (const std::runtime_error &e) {

            emit errorOccured(QString::fromStdString(e.what()));
            return {};
        }
    }

    //给某个学生添加课程
    void AdminController::addCourseToStudent(const std::string &basicString, const std::string &basicString1) {

        try {
            MYDB::DbManager::addCourseToStudent(basicString, basicString1);
            emit operationSuccess("Successfully added course with id " + QString::fromStdString(basicString1) + " to student with id " + QString::fromStdString(basicString));
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
        }


    }

    void AdminController::removeCourseFromStudent(const std::string &basicString, const std::string &basicString1) {

        try {
            MYDB::DbManager::removeCourseFromStudent(basicString, basicString1);
            emit operationSuccess("Successfully removed course with id " + QString::fromStdString(basicString1) + " from student with id " + QString::fromStdString(basicString));
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
        }

    }


    std::vector<Model::Course> AdminController::viewCourses() {

        try {
            emit operationSuccess("Successfully displayed all courses");
            return MYDB::DbManager::viewCourses();
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
            return {};
        }
    }


    void AdminController::updateStudent(const Model::StudentDTO &dto) {
        try {
            emit operationSuccess("Successfully updated student with id " + QString::fromStdString(dto.getId()));
            MYDB::DbManager::updateStudent(dto);
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
        }
    }

    std::vector<Model::Course> AdminController::getALLCoursesForStudent(const std::string &basicString) {

        try {
            emit operationSuccess("Successfully displayed all courses for student with id " + QString::fromStdString(basicString));
            return MYDB::DbManager::getAllCoursesForStudent(basicString);
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
        }
        return {};
    }

    Model::StudentScore
    AdminController::getStudentScore(const std::string& basicString, const std::string &basicString1) {
        try {
            emit operationSuccess("Successfully queried score for student with id " + QString::fromStdString(basicString) + " in course with id " + QString::fromStdString(basicString1));
            return MYDB::DbManager::getStudentScore(basicString, basicString1);
        } catch (const std::runtime_error &e) {
            emit errorOccured(QString::fromStdString(e.what()));
            return {};
        }
    }

}