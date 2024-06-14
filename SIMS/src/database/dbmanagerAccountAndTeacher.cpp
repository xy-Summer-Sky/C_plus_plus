//
// Created by Lenovo on 24-6-9.
//
#include"dbmanager.h"
#include "useraccount.h"
#include <cppconn/prepared_statement.h>
//Account information
void MYDB::DbManager::addAccount(Model::UserAccount account) {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("INSERT INTO useraccounts (USERID,PASSWORD, TYPE) VALUES (?, ?, ?)");
        pstmt->setString(1, account.getUsername());
        pstmt->setString(2, account.getPassword());
        pstmt->setString(3, account.getUserType());
        pstmt->execute();


    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }

}

void MYDB::DbManager::deleteAccount(const std::string &username) {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        Model::UserAccount account = MYDB::DbManager::queryAccount(username);
        if(account.getUsername().empty())
            throw std::runtime_error("Account not found");
        if(account.getUserType()=="student")
        {
            //检查学生是否存在
            sql::PreparedStatement *checkpstmt;
            checkpstmt = con->prepareStatement("SELECT * FROM studentinformation WHERE studentID = ?");
            checkpstmt->setString(1, username);
            sql::ResultSet *checkres = checkpstmt->executeQuery();
            if(checkres->next())
            {
                //学生存在，则先删除学生信息
                sql::PreparedStatement *deletepstmt;
                deletepstmt = con->prepareStatement("DELETE FROM studentinformation WHERE studentID = ?");
                deletepstmt->setString(1, username);
                deletepstmt->execute();
            }


        }
        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("DELETE FROM useraccounts WHERE USERID = ?");
        pstmt->setString(1, username);
        pstmt->execute();

    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }

}

void MYDB::DbManager::updateAccount(Model::UserAccount account) {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        Model::UserAccount existingAccount = queryAccount(account.getUsername());
        if (existingAccount.getUsername().empty()) {
            throw std::runtime_error("Account not found");
        }

        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("UPDATE useraccounts SET PASSWORD = ?, TYPE = ? WHERE USERID = ?");
        pstmt->setString(1, account.getPassword());
        pstmt->setString(2, account.getUserType());
        pstmt->setString(3, account.getUsername());
        pstmt->execute();
        delete pstmt;

    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }

}

std::vector<Model::UserAccount> MYDB::DbManager::displayAllAccounts() {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        sql::Statement *stmt;
        stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM useraccounts");
        std::vector<Model::UserAccount> accounts;
        while (res->next()) {
            Model::UserAccount account;
            account.setUsername(res->getString("USERID"));
            account.setPassword(res->getString("PASSWORD"));
            account.setUserType(res->getString("TYPE"));
            accounts.push_back(account);
        }
        delete res;
        delete stmt;

        return accounts;
    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }
}

//teacher information
Model::UserAccount MYDB::DbManager::queryAccount(const std::string &username) {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT * FROM useraccounts WHERE USERID = ?");
        pstmt->setString(1, username);
        sql::ResultSet *res = pstmt->executeQuery();
        Model::UserAccount account;
        if (res->next()) {
            account.setUsername(res->getString("USERID"));
            account.setPassword(res->getString("PASSWORD"));
            account.setUserType(res->getString("TYPE"));
        }
        else{
            throw std::runtime_error("Account not found");
        }
        delete res;
        delete pstmt;

        return account;
    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }
}

void MYDB::DbManager::addTeacherInformation(Model::TeacherInformation teacher) {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement(
                "INSERT INTO teacherinformation (teacherName, teacherId, teacherEmail, teacherPhonenumber) VALUES (?, ?, ?, ?)");
        pstmt->setString(1, teacher.getName());
        pstmt->setString(2, teacher.getId());
        pstmt->setString(3, teacher.getEmail());
        pstmt->setString(4, teacher.getPhoneNumber());
        pstmt->execute();
        delete pstmt;

    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }
}

void MYDB::DbManager::deleteTeacherInformation(const std::string &teacherId) {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");

    }
    try {

        Model::TeacherInformation teacher = MYDB::DbManager::getTeacherInformation(teacherId);
        if(teacher.getId().empty())
            throw std::runtime_error("Teacher not found");
        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("DELETE FROM teacherinformation WHERE teacherId = ?");
        pstmt->setString(1, teacherId);
        pstmt->execute();
        delete pstmt;
    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }
}

Model::TeacherInformation MYDB::DbManager::getTeacherInformation(const std::string &teacherId) {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT * FROM teacherinformation WHERE teacherId = ?");
        pstmt->setString(1, teacherId);
        sql::ResultSet *res = pstmt->executeQuery();
        Model::TeacherInformation teacher;
        if (res->next()) {
            teacher.setName(res->getString("teacherName"));
            teacher.setId(res->getString("teacherId"));
            teacher.setEmail(res->getString("teacherEmail"));
            teacher.setPhoneNumber(res->getString("teacherPhonenumber"));
        }
        delete res;
        delete pstmt;

        std::cout<<"teacher id: "<<teacher.getId()<<std::endl;
        if(teacher.getId().empty())
            //详细解释报错信息
            throw std::runtime_error("Teacher "+teacherId +" not found");
        return teacher;
    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }
}

void MYDB::DbManager::updateTeacherInformation(Model::TeacherInformation teacher) {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        Model::TeacherInformation existingTeacher = getTeacherInformation(teacher.getId());
        if (existingTeacher.getId().empty()) {
            throw std::runtime_error("Teacher not found");
        }
        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement(
                "UPDATE teacherinformation SET teacherName = ?, teacherEmail = ?, teacherPhonenumber = ? WHERE teacherId = ?");
        pstmt->setString(1, teacher.getName());
        pstmt->setString(2, teacher.getEmail());
        pstmt->setString(3, teacher.getPhoneNumber());
        pstmt->setString(4, teacher.getId());
        pstmt->execute();
        delete pstmt;
    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }
}

std::vector<Model::TeacherInformation> MYDB::DbManager::displayAllTeachers() {
    if (!openConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
    try {
        sql::Statement *stmt;
        stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM teacherinformation");
        std::vector<Model::TeacherInformation> teachers;
        while (res->next()) {
            Model::TeacherInformation teacher;
            teacher.setName(res->getString("teacherName"));
            teacher.setId(res->getString("teacherId"));
            teacher.setEmail(res->getString("teacherEmail"));
            teacher.setPhoneNumber(res->getString("teacherPhonenumber"));
            teachers.push_back(teacher);
        }
        delete res;
        delete stmt;
        return teachers;
    } catch (sql::SQLException &e) {
        throw std::runtime_error(translateSQLException(e));
    }
}