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

        void deleteStudent(const QString &id);

        void addCourse(const QString &name, const QString &id, const QString &teacherId);

        void updateCourse(const QString &id, const QString &name, const QString &teacherId);

        void deleteCourse(const QString &id);

        void saveStudent(const Model::StudentDTO &dto);

        Model::StudentDTO queryStudent(const std::string &basicString);

        void addCourseToStudent(const std::string &basicString, const std::string &basicString1);

        void removeCourseFromStudent(const std::string &basicString, const std::string &basicString1);

        std::vector<Model::Course> viewCourses();

        void updateStudent(const Model::StudentDTO &dto);

        std::vector<Model::Course> getALLCoursesForStudent(const std::string& basicString);

        Model::TeacherInformation getTeacherInfo(const QString& basicString);


        //Account management
        void addAccount(const QString &username, const QString &password, const QString &userType);
        void deleteAccount(const QString &username);
        void updateAccount(const QString &username, const QString &password, const QString &userType);
        Model::UserAccount queryAccount(const QString &username);
        std::vector<Model::UserAccount> displayAllAccounts();

        //teacher management
        void addTeacher(const QString &name, const QString &id, const QString &email, const QString &phone);
        void deleteTeacher(const QString &id);
        void updateTeacher(const QString &id, const QString &name, const QString &email, const QString &phone);
        Model::TeacherInformation queryTeacher(const QString &id);
        std::vector<Model::TeacherInformation> displayAllTeachers();

        //score management
        void updateScore(const QString &studentId, const QString &courseId, const QString &score);
        Model::StudentScore getStudentScore(const std::string& basicString, const std::string &basicString1);
    private:
        static MYDB::DbManager *dbManager;


    signals:

        void errorOccured(const QString &message);

        void operationSuccess(const QString &successMessage);



    };


};

#endif //SIMS_ADMINCONTROLLER_H
