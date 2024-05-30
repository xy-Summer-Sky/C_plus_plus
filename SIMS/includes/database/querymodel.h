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


//查询数据库获取相关信息
namespace MYDB
{
class QueryModel {
    public:
        QueryModel();
        ~QueryModel();

        Model::StudentDTO getStudent(const std::string& studentId);
        Model::Course getCourse(const std::string& courseId);
        Model::StudentCourses getStudentCourse(const std::string& studentId);
        std::vector<Model::StudentDTO> getAllStudents();
        std::vector<Model::Course> getAllCourses();
        std::vector<Model::StudentCourses> getAllStudentCourses();
    private:


        std::vector<Model::StudentDTO> students_;
        std::vector<Model::Course> courses_;
        std::vector<Model::StudentCourses> studentCourses_;

private:
    sql::Driver* driver;
    sql::Connection * con;

private:
    bool openConnection();
    void closeConnection();


    };

}
#endif //SIMS_QUERYMODEL_H
