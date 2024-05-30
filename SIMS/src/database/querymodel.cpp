//
// Created by Lenovo on 24-5-21.
//

#include "querymodel.h"

//initialize the mysql connection
MYDB::QueryModel::QueryModel() {
    //initialize the mysql connection
    driver = sql::mysql::get_driver_instance();
    try {
        con=driver->connect("localhost:3306","root","helloworld");
        if(con==nullptr)
        {
            std::cout<<"Connection failed!"<<std::endl;
            return;
        }
        con->setSchema("sims");

    } catch (const sql::SQLException& e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
    }

//close the connection
void MYDB::QueryModel::closeConnection() {
    if (con != nullptr && !con->isClosed()) {
        con->close();
    }
}

//open the connection
bool MYDB::QueryModel::openConnection() {
    return con != nullptr && !con->isClosed();
}

MYDB::QueryModel::~QueryModel() {

    closeConnection();
}

//查询数据库中获取学生信息
Model::StudentDTO MYDB::QueryModel::getStudent(const std::string &studentId) {


    Model::StudentDTO student("", "default", "", "");
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT studentID, studentName, email, phoneNumber FROM Students WHERE studentID = ?"));
        pstmt->setString(1, studentId);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        if (res->next()) {
            student.setId(res->getString("studentID"));
            student.setName(res->getString("studentName"));
            student.setEmail(res->getString("email"));
            student.setPhoneNumber(res->getString("phoneNumber"));
        }
        else {
            throw std::runtime_error("Student not found");

        }
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    return student;


}

//getCourse function
Model::Course MYDB::QueryModel::getCourse(const std::string &courseId) {

    Model::Course course("", "default", "");
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT courseID, courseName, teacherID FROM Courses WHERE courseID = ?"));
        pstmt->setString(1, courseId);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        if (res->next()) {
            course.setId(res->getString("courseID"));
            course.setName(res->getString("courseName"));
            course.setTeacherId(res->getString("teacherID"));
        }
        else {
            throw std::runtime_error("Course not found");

        }
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    return course;

}

Model::StudentCourses MYDB::QueryModel::getStudentCourse(const std::string &studentId) {
    Model::StudentCourses studentCourse("default");
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT studentID, courseID_1,courseID_2,courseID_3,courseID_4 FROM StudentCourses WHERE studentID = ?"));
        pstmt->setString(1, studentId);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        if (res->next()) {
            studentCourse.setStudentId(res->getString("studentID"));
            studentCourse.addCourse(res->getString("courseID_1"));
            studentCourse.addCourse(res->getString("courseID_2"));
            studentCourse.addCourse(res->getString("courseID_3"));
            studentCourse.addCourse(res->getString("courseID_4"));

        }
        else {
            throw std::runtime_error("StudentCourse not found");
        }
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    return studentCourse;
}

std::vector<Model::StudentDTO> MYDB::QueryModel::getAllStudents() {
    return students_;
}

std::vector<Model::Course> MYDB::QueryModel::getAllCourses() {
    return courses_;
}

std::vector<Model::StudentCourses> MYDB::QueryModel::getAllStudentCourses() {
    return studentCourses_;
}

// Created by Lenovo on 24-5-21.

