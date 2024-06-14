//
// Created by Lenovo on 24-5-21.
//

#ifndef SIMS_ADMINCONTROLLER_H
#define SIMS_ADMINCONTROLLER_H

#include <string>
#include <QString>
#include "dbmanager.h"
#include <QObject>

namespace Controller {
    class AdminController : public QObject {

    Q_OBJECT

    public:
        AdminController();

        ~AdminController() override;

    public:

        //Student management
        void deleteStudent(const QString &id);//delete student

        void saveStudent(const Model::StudentDTO &dto);//add student

        Model::StudentDTO queryStudent(const std::string &basicString);//query student

        void updateStudent(const Model::StudentDTO &dto);//update student

        std::vector<Model::Course> getALLCoursesForStudent(const std::string &basicString);//get all courses for student

        std::vector<Model::StudentDTO> displayAllStudents();//display all students

        void addCourseToStudent(const std::string &basicString, const std::string &basicString1);//add course to student

        void removeCourseFromStudent(const std::string &basicString, const std::string &basicString1);//remove course from student

        //Course management
        void addCourse(const QString &name, const QString &id, const QString &teacherId);//add course

        void updateCourse(const QString &id, const QString &name, const QString &teacherId);//update course

        void deleteCourse(const QString &id);//delete course

        Model::Course queryCourse(const std::string &basicString);//query course

        std::vector<Model::Course> viewCourses();//view courses

        Model::TeacherInformation getTeacherInfo(const QString& basicString);//get teacher information


        //Account management
        void addAccount(const QString &username, const QString &password, const QString &userType);//add account
        void deleteAccount(const QString &username);//delete account
        void updateAccount(const QString &username, const QString &password, const QString &userType);//update account
        Model::UserAccount queryAccount(const QString &username);//query account
        std::vector<Model::UserAccount> displayAllAccounts();//display all accounts

        //teacher management
        void addTeacher(const QString &name, const QString &id, const QString &email, const QString &phone);//add teacher
        void deleteTeacher(const QString &id);//delete teacher
        void updateTeacher(const QString &id, const QString &name, const QString &email, const QString &phone);//update teacher
        Model::TeacherInformation queryTeacher(const QString &id);//query teacher
        std::vector<Model::TeacherInformation> displayAllTeachers();//display all teachers

        //score management
        void updateScore(const QString &studentId, const QString &courseId, const QString &score);//update score
        Model::StudentScore getStudentScore(const std::string& basicString, const std::string &basicString1);//get student score
    private:
        static MYDB::DbManager *dbManager;


    signals:

        void errorOccured(const QString &message);//error signal

        void operationSuccess(const QString &successMessage);//success signal



    };


};

#endif //SIMS_ADMINCONTROLLER_H
