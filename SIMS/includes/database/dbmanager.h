//
// Created by Lenovo on 24-5-21.
//

#ifndef SIMS_DBMANAGER_H
#define SIMS_DBMANAGER_H

#include <string>
#include <jdbc/cppconn/exception.h>
#include "jdbc/mysql_driver.h"
#include "student.h"
#include "course.h"
#include"useraccount.h"
#include "teacherinformation.h"
#include "StudentScore.h"

namespace MYDB {


    class DbManager {


    public:
        DbManager();

        ~DbManager();


    private:

        static sql::Driver *driver;
        static sql::Connection *con;

        static bool openConnection();

        static void closeConnection();

    private:
        static std::string translateSQLException(const sql::SQLException &e);
        //login validation
    public:
        static bool validateUser(const std::string &userId, const std::string &password, const std::string &userType);

        //student operations
    public:
        static void addStudent(const Model::StudentDTO &student);

        static bool deleteStudent(const std::string &id);

        static bool updateStudent(const Model::StudentDTO &student);

        static std::vector<Model::Course> getAllCoursesForStudent(const std::string &basicString);


        //course operations
    public:
        static bool addCourse(Model::Course course);

        static bool deleteCourse(const std::string &id);

        static bool updateCourse(Model::Course course);


        static Model::StudentDTO queryStudent(const std::string &basicString);

        static bool addCourseToStudent(const std::string &basicString, const std::string &basicString1);

        static void removeCourseFromStudent(const std::string &basicString, const std::string &basicString1);

        static std::vector<Model::Course> viewCourses();

    public:
        //老师信息的增删查改
        static Model::TeacherInformation getTeacherInformation(const std::string &teacherId);

        static void addTeacherInformation(Model::TeacherInformation teacher);

        static void deleteTeacherInformation(const std::string &teacherId);

        static void updateTeacherInformation(Model::TeacherInformation teacher);

        static std::vector<Model::TeacherInformation> displayAllTeachers();

        //account management
    public:
        static void addAccount(Model::UserAccount account);

        static void deleteAccount(const std::string &username);

        static void updateAccount(Model::UserAccount account);

        static Model::UserAccount queryAccount(const std::string &username);

        static std::vector<Model::UserAccount> displayAllAccounts();


        static void updateScore(const Model::StudentScore& score);

        static Model::StudentScore getStudentScore(const std::string& basicString, const std::string &basicString1);
    };
}

#endif
