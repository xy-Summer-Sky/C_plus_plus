//
// Created by Lenovo on 24-5-21.
//

#ifndef SIMS_QUERYMODEL_H
#define SIMS_QUERYMODEL_H

#include"student.h"
#include"course.h"
#include"StudentCourses.h"
#include <vector>
#include <string>
#include <iostream>
#include "mysql_driver.h"
#include <jdbc/cppconn/exception.h>
#include"cppconn/prepared_statement.h"
#include "teacherinformation.h"
#include "StudentScore.h"


//查询数据库获取相关信息
namespace MYDB {
    class QueryModel {
    public:
        QueryModel();

        ~QueryModel();

        static Model::StudentDTO getStudent(const std::string &studentId);

        static Model::Course getCourse(const std::string &courseId);

        static std::vector<Model::Course> getStudentCourses(const std::string &basicString);

        static Model::TeacherInformation getTeacherInfo(const std::string &basicString);

        static Model::StudentScore getStudentScore(const std::string &basicString, const std::string &basicString1);

    private:
        static std::vector<Model::StudentDTO> students_;

    private:
        static sql::Driver *driver;
        static sql::Connection *con;

    private:
        static bool openConnection();

        static void closeConnection();


    };

}
#endif //SIMS_QUERYMODEL_H
