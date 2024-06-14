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

        static bool openConnection();//open connection

        static void closeConnection();//close connection

    private:
        //exception handling
        static std::string translateSQLException(const sql::SQLException &e);

    public:
        //user operations
        static bool validateUser(const std::string &userId, const std::string &password, const std::string &userType);


    public:
        //student operations
        static void addStudent(const Model::StudentDTO &student);//add student

        static bool deleteStudent(const std::string &id);//delete student

        static bool updateStudent(const Model::StudentDTO &student);//update student

        static std::vector<Model::Course> getAllCoursesForStudent(const std::string &basicString);//get all courses for student



    public:
        //course operations
        static bool addCourse(Model::Course course);//add course

        static bool deleteCourse(const std::string &id);//delete course

        static bool updateCourse(Model::Course course);//update course

        static Model::StudentDTO queryStudent(const std::string &basicString);//query student

        static bool addCourseToStudent(const std::string &basicString, const std::string &basicString1);//add course to student

        static void removeCourseFromStudent(const std::string &basicString, const std::string &basicString1);//remove course from student

        static std::vector<Model::Course> viewCourses();//view all courses

    public:
        //teacher operations
        static Model::TeacherInformation getTeacherInformation(const std::string &teacherId);//get teacher information

        static void addTeacherInformation(Model::TeacherInformation teacher);//add teacher

        static void deleteTeacherInformation(const std::string &teacherId);//delete teacher

        static void updateTeacherInformation(Model::TeacherInformation teacher);//update teacher

        static std::vector<Model::TeacherInformation> displayAllTeachers();//display all teachers


    public:
        //account management
        static void addAccount(Model::UserAccount account);//add account

        static void deleteAccount(const std::string &username);//delete account

        static void updateAccount(Model::UserAccount account); //update account

        static Model::UserAccount queryAccount(const std::string &username);//query account

        static std::vector<Model::UserAccount> displayAllAccounts();//display all accounts

        static void updateScore(const Model::StudentScore& score);//update score

        static Model::StudentScore getStudentScore(const std::string& basicString, const std::string &basicString1);//get student score

        static Model::Course getCourse(const std::string &basicString);//get course

        static std::vector<Model::StudentDTO> displayAllStudents();//display all students
    };
}

#endif
