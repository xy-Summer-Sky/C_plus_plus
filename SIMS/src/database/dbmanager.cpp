// Constructor
#include "dbmanager.h"
#include"cppconn/prepared_statement.h"

sql::Connection *MYDB::DbManager::con = nullptr;
sql::Driver *MYDB::DbManager::driver = nullptr;

MYDB::DbManager::DbManager() {
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
    }
}

// Destructor
MYDB::DbManager::~DbManager() {
    closeConnection();
}

std::string MYDB::DbManager::translateSQLException(const sql::SQLException &e) {
    std::cout << "exception" << std::endl;
    switch (e.getErrorCode()) {
        case 1045:  // "28000" SQLSTATE = Access denied
            return "Database access denied. Please check your username and password.";
        case 2002:  // "HY000" SQLSTATE = Can't connect to local MySQL server through socket
            return "Can't connect to database server. Please check your configuration.";
        case 1049:  // "42000" SQLSTATE = Unknown database
            return "Database not found. Please check your configuration.";
            //违反唯一性约束
        case 1062:
            std::cout << "exception-1062" << std::endl;
            return "Duplicate entry. Please check your input.";
        case 1146:  // "42S02" SQLSTATE = Table not found
            return "Table not found. Please check your configuration.";


        default:
            std::cout << "exception-default" << std::endl;
            try {
                return "Database error: " + std::string(e.what());
            } catch (const std::exception &ex) {
                return "Database error: An error occurred while translating the exception.";
            }
    }


}


// Validate user
bool
MYDB::DbManager::validateUser(const std::string &userID, const std::string &password, const std::string &userType) {
    if (!openConnection()) {
        return false;
    }

    try {

        std::unique_ptr<sql::PreparedStatement> stmt(
                con->prepareStatement("SELECT * FROM useraccounts WHERE USERID = ? AND PASSWORD = ? AND TYPE = ?"));
        stmt->setString(1, userID);
        stmt->setString(2, password);
        stmt->setString(3, userType);
        sql::ResultSet *res = stmt->executeQuery();

        if (res->next()) {
            std::cout << "User exists" << std::endl;
            return true;
        } else {
            std::cout << "User does not exist" << std::endl;
            return false;
        }
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        return false;
    }
}

// Open Connection
bool MYDB::DbManager::openConnection() {
    if (con != nullptr && !con->isClosed()) {
        std::cout << "Connection already open" << std::endl;
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

// Close Connection
void MYDB::DbManager::closeConnection() {
    if (con != nullptr && !con->isClosed()) {
        con->close();
    }
}

//Student
void MYDB::DbManager::addStudent(const Model::StudentDTO &student) {
    if (!openConnection()) {
        return;
    }

    try {

        //检查账户是否已经存在。避免外键冲突
        std::unique_ptr<sql::PreparedStatement> checkStmt(
                con->prepareStatement("SELECT * FROM useraccounts WHERE USERID = ?"));
        checkStmt->setString(1, student.getId());
        std::unique_ptr<sql::ResultSet> res(checkStmt->executeQuery());
        if (!res->next()) {
            throw std::runtime_error("Account with id " + student.getId() + " does not exist");
        }
        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement(
                "INSERT INTO studentinformation (studentname, studentid, EMAIL, PHONEnumber) VALUES (?, ?, ?, ?)"));
        stmt->setString(1, student.getName());
        stmt->setString(2, student.getId());
        stmt->setString(3, student.getEmail());
        stmt->setString(4, student.getPhoneNumber());
        stmt->execute();


        // 添加学生课程表记录
        std::unique_ptr<sql::PreparedStatement> stmtCourse(
                con->prepareStatement("INSERT INTO studentcourses (studentID) VALUES (?)"));
        stmtCourse->setString(1, student.getId());
        stmtCourse->execute();

        return;
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }
}

bool MYDB::DbManager::deleteStudent(const std::string &id) {
    if (!openConnection()) {
        return false;
    }
    try {

        std::unique_ptr<sql::PreparedStatement> stmt2(
                con->prepareStatement("DELETE FROM studentscore WHERE studentID = ?")
        );
        stmt2->setString(1, id);
        stmt2->executeUpdate();


        std::unique_ptr<sql::PreparedStatement> stmt1(
                con->prepareStatement("DELETE FROM studentcourses WHERE studentId = ?")
        );
        stmt1->setString(1, id);
        stmt1->executeUpdate();
        // 检查学生是否存在
        std::unique_ptr<sql::PreparedStatement> checkStmt(
                con->prepareStatement("SELECT * FROM studentinformation WHERE studentid = ?"));
        checkStmt->setString(1, id);
        std::unique_ptr<sql::ResultSet> res(checkStmt->executeQuery());

        if (!res->next()) {
            // 如果学生不存在，抛出一个异常
            throw std::runtime_error("Student with id " + id + " does not exist");
        }

        std::unique_ptr<sql::PreparedStatement> stmt(
                con->prepareStatement("DELETE FROM studentinformation WHERE studentid = ?"));
        stmt->setString(1, id);
        int affectedRows = stmt->executeUpdate();
        return affectedRows > 0;
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }


}

bool MYDB::DbManager::updateStudent(const Model::StudentDTO &student) {
    if (!openConnection()) {
        return false;
    }

    try {
        std::unique_ptr<sql::PreparedStatement> checkStmt(
                con->prepareStatement("SELECT * FROM studentinformation WHERE studentID = ?"));
        checkStmt->setString(1, student.getId());
        std::unique_ptr<sql::ResultSet> res(checkStmt->executeQuery());
        if (!res->next()) {
            throw std::runtime_error("Student with id " + student.getId() + " does not exist");
        }
        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement(
                "UPDATE studentinformation SET studentNAME = ?, EMAIL = ?, PHONEnumber = ? WHERE studentID = ?"));
        stmt->setString(1, student.getName());
        stmt->setString(2, student.getEmail());
        stmt->setString(3, student.getPhoneNumber());
        stmt->setString(4, student.getId());
        stmt->execute();
        return true;
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));

    }
}

//Course

bool MYDB::DbManager::addCourse(Model::Course course) {
    if (course.getId().empty() || course.getName().empty() || course.getTeacherId().empty()) {
        throw std::runtime_error("Course information is incomplete");

    }
    if (!openConnection()) {
        return false;
    }

    try {
        std::unique_ptr<sql::PreparedStatement> checkTeacherStmt(
                con->prepareStatement("SELECT * FROM teacherinformation WHERE teacherId = ?"));
        checkTeacherStmt->setString(1, course.getTeacherId());
        std::unique_ptr<sql::ResultSet> res(checkTeacherStmt->executeQuery());
        if (!res->next()) {
            throw std::runtime_error("Teacher with id " + course.getTeacherId() + " does not exist");
        }
        std::unique_ptr<sql::PreparedStatement> stmt(
                con->prepareStatement("INSERT INTO course (courseName, courseID, teacher) VALUES (?, ?, ?)"));
        stmt->setString(1, course.getName());
        stmt->setString(2, course.getId());
        stmt->setString(3, course.getTeacherId());
        stmt->execute();
        return true;
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));

    }
}

bool MYDB::DbManager::deleteCourse(const std::string &id) {
    if (!openConnection()) {
        return false;
    }

    try {
        std::unique_ptr<sql::PreparedStatement> checkStmt(
                con->prepareStatement("SELECT * FROM course WHERE courseID = ?"));
        checkStmt->setString(1, id);
        std::unique_ptr<sql::ResultSet> res(checkStmt->executeQuery());
        if (!res->next()) {
            throw std::runtime_error("Course with id " + id + " does not exist");
        }

        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement("DELETE FROM course WHERE courseID = ?"));
        stmt->setString(1, id);
        stmt->execute();
        return true;
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));

    }
}

bool MYDB::DbManager::updateCourse(Model::Course course) {
    if (!openConnection()) {
        return false;
    }

    try {
        // 检查教师是否存在
        std::unique_ptr<sql::PreparedStatement> checkTeacherStmt(
                con->prepareStatement("SELECT * FROM teacherinformation WHERE teacherId = ?"));
        checkTeacherStmt->setString(1, course.getTeacherId());
        std::unique_ptr<sql::ResultSet> res1(checkTeacherStmt->executeQuery());
        if (!res1->next()) {
            throw std::runtime_error("Teacher with id " + course.getTeacherId() + " does not exist");
        }
        std::unique_ptr<sql::PreparedStatement> checkStmt(
                con->prepareStatement("SELECT * FROM course WHERE courseID = ?"));
        checkStmt->setString(1, course.getId());
        std::unique_ptr<sql::ResultSet> res(checkStmt->executeQuery());
        if (!res->next()) {
            throw std::runtime_error("Course with id " + course.getId() + " does not exist");
        }
        std::unique_ptr<sql::PreparedStatement> stmt(
                con->prepareStatement("UPDATE course SET courseName = ?, TEACHER = ? WHERE courseID = ?"));
        stmt->setString(1, course.getName());
        stmt->setString(2, course.getTeacherId());
        stmt->setString(3, course.getId());
        stmt->execute();
        return true;
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));

    }
}

Model::StudentDTO MYDB::DbManager::queryStudent(const std::string &studentId) {
    if (!openConnection()) {
        return {};
    }

    try {

        // Prepare the SQL query
        std::unique_ptr<sql::PreparedStatement> stmt(
                con->prepareStatement("SELECT * FROM studentinformation WHERE studentid = ?"));
        stmt->setString(1, studentId);

        // Execute the query
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

        // If the query returns a result, create a StudentDTO object with the student's information
        if (res->next()) {
            std::string name = res->getString("studentName");
            std::string id = res->getString("studentID");
            std::string email = res->getString("email");
            std::string phoneNumber = res->getString("phonenumber");

            return {name, id, email, phoneNumber};
        } else {

            return {};
        }
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));

    }
}

bool MYDB::DbManager::addCourseToStudent(const std::string &studentId, const std::string &courseId) {
    if (!openConnection()) {
        return false;
    }

    try {
        //判断是否存在这个课程id和学生id
        std::unique_ptr<sql::PreparedStatement> checkCourseStmt(
                con->prepareStatement("SELECT * FROM course WHERE courseID = ?"));
        checkCourseStmt->setString(1, courseId);
        std::unique_ptr<sql::ResultSet> res1(checkCourseStmt->executeQuery());
        if (!res1->next()) {
            throw std::runtime_error("Course with id " + courseId + " does not exist");
        }
        //检查学生是否存在
        std::unique_ptr<sql::PreparedStatement> checkStudentStmt(
                con->prepareStatement("SELECT * FROM studentinformation WHERE studentID = ?"));
        checkStudentStmt->setString(1, studentId);
        std::unique_ptr<sql::ResultSet> res2(checkStudentStmt->executeQuery());
        if (!res2->next()) {
            throw std::runtime_error("Student with id " + studentId + " does not exist");
        }
        // 首先，我们需要找到一个空的 courseID 字段
        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement(
                "SELECT * FROM studentcourses WHERE studentID = ?"
        ));
        stmt->setString(1, studentId);
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

        // 如果没有找到空的 courseID 字段，那么这个学生已经有4门课程了，我们不能再添加更多的课程
        if (!res->next()) {
            return false;
        }

        std::string updateQuery = "UPDATE studentcourses SET ";

        if (res->getString("courseID_1")->empty()) {
            updateQuery += "courseID_1 = ? ";
        } else if (res->getString("courseID_2")->empty()) {
            updateQuery += "courseID_2 = ? ";
        } else if (res->getString("courseID_3")->empty()) {
            updateQuery += "courseID_3 = ? ";
        } else if (res->getString("courseID_4")->empty()) {
            updateQuery += "courseID_4 = ? ";
        } else {
            // All course slots are filled
            return false;
        }

        updateQuery += "WHERE studentID = ?";

        std::unique_ptr<sql::PreparedStatement> updateStmt(con->prepareStatement(updateQuery));
        updateStmt->setString(1, courseId);
        updateStmt->setString(2, studentId);
        updateStmt->execute();

        return true;
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }
}

void MYDB::DbManager::removeCourseFromStudent(const std::string &studentId, const std::string &courseId) {
    if (!openConnection()) {
        return;
    }

    try {
        //首先判断这个课程是否存在
        std::unique_ptr<sql::PreparedStatement> checkCourseStmt(
                con->prepareStatement(
                        "SELECT * FROM studentcourses WHERE studentID = ? AND (courseID_1 = ? OR courseID_2 = ? OR courseID_3 = ? OR courseID_4 = ?)"));
        checkCourseStmt->setString(1, studentId);
        checkCourseStmt->setString(2, courseId);
        checkCourseStmt->setString(3, courseId);
        checkCourseStmt->setString(4, courseId);
        checkCourseStmt->setString(5, courseId);
        std::unique_ptr<sql::ResultSet> res1(checkCourseStmt->executeQuery());
        if (!res1->next()) {
            throw std::runtime_error("The student has not chosen this course");
        }
        else {
            //先判断课程成绩是否存在，如果存在然后删除
            sql::PreparedStatement *stmt0;
            stmt0 = con->prepareStatement("SELECT * FROM studentscore WHERE studentID = ? AND courseID = ?");
            stmt0->setString(1, studentId);
            stmt0->setString(2, courseId);
            sql::ResultSet *res0 = stmt0->executeQuery();
            if (res0->next()) {

                std::unique_ptr<sql::PreparedStatement> stmt1(
                        con->prepareStatement("DELETE FROM studentscore WHERE studentID = ? AND courseID = ?"));
                         stmt1->setString(1, studentId);
                stmt1->setString(2, courseId);
                stmt1->execute();
            }
        }

        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement(
                "UPDATE studentcourses SET courseID_1 = IF(courseID_1 = ?, NULL, courseID_1), courseID_2 = IF(courseID_2 = ?, NULL, courseID_2), courseID_3 = IF(courseID_3 = ?, NULL, courseID_3), courseID_4 = IF(courseID_4 = ?, NULL, courseID_4) WHERE studentID = ?"
        ));
        stmt->setString(1, courseId);
        stmt->setString(2, courseId);
        stmt->setString(3, courseId);
        stmt->setString(4, courseId);
        stmt->setString(5, studentId);
        stmt->execute();
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }
}

std::vector<Model::Course> MYDB::DbManager::viewCourses() {
    std::vector<Model::Course> courses;

    if (!openConnection()) {
        return courses;
    }

    try {
        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement("SELECT * FROM course"));
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

        while (res->next()) {
            std::string name = res->getString("courseName");
            std::string id = res->getString("courseID");
            std::string teacherId = res->getString("teacher");

            Model::Course course(name, id, teacherId);
            courses.push_back(course);
        }
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }

    return courses;
}


std::vector<Model::Course> MYDB::DbManager::getAllCoursesForStudent(const std::string &studentId) {
    std::vector<Model::Course> courses;

    if (!openConnection()) {
        return courses;
    }

    try {
        // Prepare the SQL query
        std::unique_ptr<sql::PreparedStatement> stmt(
                con->prepareStatement(
                        "SELECT course.* FROM studentcourses "
                        "JOIN course ON (course.courseID = studentcourses.courseID_1 OR "
                        "course.courseID = studentcourses.courseID_2 OR "
                        "course.courseID = studentcourses.courseID_3 OR "
                        "course.courseID = studentcourses.courseID_4) "
                        "WHERE studentcourses.studentID = ?"
                )
        );
        stmt->setString(1, studentId);

        // Execute the query
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

        // If the query returns a result, create a Course object with the course's information
        while (res->next()) {
            std::string name = res->getString("courseName");
            std::string id = res->getString("courseID");
            std::string teacherId = res->getString("teacher");

            Model::Course course(name, id, teacherId);
            courses.push_back(course);
        }
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }

    return courses;
}

void MYDB::DbManager::updateScore(const Model::StudentScore &score) {
    if (!openConnection()) {
        return;
    }

    try {
        //检查学生是否选过这个课程
        std::unique_ptr<sql::PreparedStatement> checkCourseStmt(
                con->prepareStatement(
                        "SELECT * FROM studentcourses WHERE studentID = ? AND (courseID_1 = ? OR courseID_2 = ? OR courseID_3 = ? OR courseID_4 = ?)"));
        checkCourseStmt->setString(1, score.getStudentId());
        checkCourseStmt->setString(2, score.getCourseId());
        checkCourseStmt->setString(3, score.getCourseId());
        checkCourseStmt->setString(4, score.getCourseId());
        checkCourseStmt->setString(5, score.getCourseId());
        std::unique_ptr<sql::ResultSet> res1(checkCourseStmt->executeQuery());
        // 如果查询结果为空，说明学生没有选择这门课程，抛出一个异常
        if (!res1->next()) {
            throw std::runtime_error("The student has not chosen this course");
        }
        //检查是否存在数据库记录，如果没有则直接插入
        std::unique_ptr<sql::PreparedStatement> checkStmt(
                con->prepareStatement("SELECT * FROM studentscore WHERE studentID = ? AND courseID = ?"));
        checkStmt->setString(1, score.getStudentId());
        checkStmt->setString(2, score.getCourseId());
        std::unique_ptr<sql::ResultSet> res(checkStmt->executeQuery());
        if (!res->next()) {
            std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement(
                    "INSERT INTO studentscore (studentID, courseID, score) VALUES (?, ?, ?)"));
            stmt->setString(1, score.getStudentId());
            stmt->setString(2, score.getCourseId());
            stmt->setString(3, score.getScore());
            stmt->execute();
            return;
        }
        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement(
                "UPDATE studentscore SET score = ? WHERE studentID = ? AND courseID = ?"));
        stmt->setString(1, score.getScore());
        stmt->setString(2, score.getStudentId());
        stmt->setString(3, score.getCourseId());
        stmt->execute();
        return;
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }

}

Model::StudentScore MYDB::DbManager::getStudentScore(const std::string &basicString, const std::string &basicString1) {
    if (!openConnection()) {
        return {};
    }
    try {
        std::unique_ptr<sql::PreparedStatement> stmt(
                con->prepareStatement("SELECT * FROM studentscore WHERE studentID = ? AND courseID = ?"));
        stmt->setString(1, basicString);
        stmt->setString(2, basicString1);
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());
        if (res->next()) {
            std::string studentId = res->getString("studentID");
            std::string courseId = res->getString("courseID");
            std::string score = res->getString("score");
            return {studentId, courseId, score};
        } else {
            return {};
        }
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }

}

Model::Course MYDB::DbManager::getCourse(const std::string &basicString) {
    try {
        if (!openConnection()) {
            return {};
        }
        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement("SELECT * FROM course WHERE courseID = ?"));
        stmt->setString(1, basicString);
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());
        if (res->next()) {
            std::string name = res->getString("courseName");
            std::string id = res->getString("courseID");
            std::string teacherId = res->getString("teacher");
            return {name, id, teacherId};
        }
    } catch (const sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        throw std::runtime_error(translateSQLException(e));
    }
    return {};
}

std::vector<Model::StudentDTO> MYDB::DbManager::displayAllStudents() {
    try {
        if (!openConnection()) {
            return {};
        }
        std::vector<Model::StudentDTO> students;
        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement("SELECT * FROM studentinformation"));
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());
        while (res->next()) {
            std::string name = res->getString("studentName");
            std::string id = res->getString("studentID");
            std::string email = res->getString("email");
            std::string phoneNumber = res->getString("phonenumber");
            students.emplace_back(name, id, email, phoneNumber);
        }
        return students;
    } catch (const sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }

}


