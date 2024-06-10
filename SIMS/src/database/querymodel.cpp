//
// Created by Lenovo on 24-5-21.
//

#include "querymodel.h"
// Define static members
std::vector<Model::StudentDTO> MYDB::QueryModel::students_;
sql::Driver* MYDB::QueryModel::driver = nullptr;
sql::Connection* MYDB::QueryModel::con = nullptr;
//initialize the mysql connection
MYDB::QueryModel::QueryModel() {

    driver = sql::mysql::get_driver_instance();
    try {
        con = driver->connect("localhost:3306", "root", "helloworld");
        if (con == nullptr) {
            std::cout << "Connection failed!" << std::endl;
            return;
        }
        con->setSchema("sims");
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error("Failed to connect to database");
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
    if(con != nullptr &&!con->isClosed())
    {
        std::cout<<"Connection already open"<<std::endl;
        return true;
    }
    driver = sql::mysql::get_driver_instance();
    try {
        con = driver->connect("localhost:3306", "root", "helloworld");
        if (con == nullptr) {
            std::cout << "Connection failed!" << std::endl;
            return false;
        }
        con->setSchema("sims");
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error("Failed to connect to database");
    }
    return true;
}

MYDB::QueryModel::~QueryModel() {

    closeConnection();
    delete con;

}

//查询数据库中获取学生信息
Model::StudentDTO MYDB::QueryModel::getStudent(const std::string &studentId) {
    Model::StudentDTO student;
    if(!openConnection())
    {
        std::cout<<"Connection failed"<<std::endl;
        return student;
    }

    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
                "SELECT studentID, studentName, email, phonenumber FROM studentinformation WHERE studentID = ?"));
        pstmt->setString(1, studentId);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        if (res->next()) {
            student.setId(res->getString("studentID"));
            student.setName(res->getString("studentName"));
            student.setEmail(res->getString("email"));
            student.setPhoneNumber(res->getString("phonenumber"));
        } else {
            throw std::runtime_error("Student not found");
        }
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
        throw std::runtime_error("Failed to get student");
    }
    return student;
}
//getCourse function
Model::Course MYDB::QueryModel::getCourse(const std::string &courseId) {
    Model::Course course;
    if(!openConnection())
    {
        std::cout<<"Connection failed"<<std::endl;
        return course;
    };
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(
                con->prepareStatement("SELECT courseName, teacher FROM course WHERE courseID = ?"));
        pstmt->setString(1, courseId);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        if (res->next()) {
            course.setId(courseId);
            course.setName(res->getString("courseName"));
            course.setTeacherId(res->getString("teacher"));
        } else {
            throw std::runtime_error("Course not found");
        }
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
        throw std::runtime_error("Failed to get course");
    }
    return course;
}

std::vector<Model::Course> MYDB::QueryModel::getStudentCourses(const std::string &studentId) {
    std::vector<Model::Course> courses;
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
                "SELECT courseID_1, courseID_2, courseID_3, courseID_4 FROM studentcourses WHERE studentID = ?"));
        pstmt->setString(1, studentId);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        if (res->next()) {
            for (int i = 1; i <= 4; i++) {
                std::string courseId = res->getString(i);
                if (!courseId.empty()) {
                    courses.push_back(getCourse(courseId));
                }
            }
        }
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
        throw std::runtime_error("Failed to get student courses");
    }
    return courses;
}

Model::TeacherInformation MYDB::QueryModel::getTeacherInfo(const std::string &basicString) {
    if(!openConnection())
    {
        std::cout<<"Connection failed"<<std::endl;
        return {};
    }
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
                "SELECT teacherName, teacherEmail FROM teacherinformation WHERE teacherId = ?"));
        pstmt->setString(1, basicString);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        if (res->next()) {
            Model::TeacherInformation teacher;
            teacher.setId(basicString);
            teacher.setName(res->getString("teacherName"));
            teacher.setEmail(res->getString("teacherEmail"));
            return teacher;
        }
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
        throw std::runtime_error("Failed to get teacher information");
    }



    return {};
}

Model::StudentScore MYDB::QueryModel::getStudentScore(const std::string &basicString, const std::string &basicString1) {

    if(!openConnection())
    {
        std::cout<<"Connection failed"<<std::endl;
        return {};
    }
    try{
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
                "SELECT score FROM studentscore WHERE studentID = ? AND courseID = ?"));
        pstmt->setString(1, basicString);
        pstmt->setString(2, basicString1);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        if(res->next())
        {
            Model::StudentScore score;
            score.setStudentId(basicString);
            score.setCourseId(basicString1);
            score.setScore(res->getString("score"));
            return score;
        }
    }
    catch(sql::SQLException &e)
    {
        std::cerr<<"SQL Error: "<<e.what()<<" (MySQL error code: "<<e.getErrorCode()<<")"<<std::endl;
        throw std::runtime_error("Failed to get student score");
    }
    return {};
}

// Created by Lenovo on 24-5-21.

