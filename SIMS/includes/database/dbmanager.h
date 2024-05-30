//
// Created by Lenovo on 24-5-21.
//

#ifndef SIMS_DBMANAGER_H
#define SIMS_DBMANAGER_H
#include <string>
#include <jdbc/cppconn/exception.h>
#include "jdbc/mysql_driver.h"

namespace MYDB {



    class DbManager {


    public:
        DbManager(const std::string &hostName, const std::string &dbName, const std::string &userName,
                  const std::string &password);
        ~DbManager();

    private:

        sql::Driver* driver;
        sql::Connection * con;
        bool openConnection();
        void closeConnection();

    //login validation
    public:
        bool validateUser(const std::string &userId, const std::string &password, const std::string &userType);


    //student operations
    public:
        bool addStudent(const std::string &name, const std::string &id, const std::string &email, const std::string &phoneNumber);
        bool deleteStudent(const std::string &id);
        bool updateStudent(const std::string &name, const std::string &id, const std::string &email, const std::string &phoneNumber);

    //course operations
    public:
        bool addCourse(const std::string &name, const std::string &id, const std::string &teacherId);
        bool deleteCourse(const std::string &id);
        bool updateCourse(const std::string &name, const std::string &id, const std::string &teacherId);

    //student course operations
    public:
        bool addStudentCourse(const std::string &studentId, const std::string &courseId);
        bool deleteStudentCourse(const std::string &studentId, const std::string &courseId);
        bool updateStudentCourse(const std::string &studentId, const std::string &courseId);


    };
}

#endif //SIMS_DBMANAGER_H
