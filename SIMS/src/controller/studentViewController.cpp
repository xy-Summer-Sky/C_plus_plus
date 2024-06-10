


#include "studentViewController.h"


Controller::studentViewController::studentViewController(SystemUi::StudentForm *view, QObject *parent) :
        QObject(parent),
        view(view) {
}

void Controller::studentViewController::requestStudentInfo() {

}

Model::StudentDTO Controller::studentViewController::getStudent(const std::string &studentId) {
    qDebug() << "getStudent function called";
    try
    {
        Model::StudentDTO student = MYDB::QueryModel::getStudent(studentId);
        emit operationSuccess("Student information fetched successfully");
        return student;
    }
    catch (const std::runtime_error &e)
    {
        emit errorOccured(QString::fromStdString(e.what()));
        return {};
    }

}

std::vector<Model::Course> Controller::studentViewController::getStudentCourses(const std::string &studentId) {
    try
    {
        std::vector<Model::Course> courses = MYDB::QueryModel::getStudentCourses(studentId);
        emit operationSuccess("Student courses fetched successfully");
        return courses;
    }
    catch (const std::runtime_error &e)
    {
        emit errorOccured(QString::fromStdString(e.what()));
        return {};
    }

}

Model::TeacherInformation Controller::studentViewController::getTeacherInfo(const std::string &basicString) {

    try
    {
       Model::TeacherInformation teacherInfo = MYDB::QueryModel::getTeacherInfo(basicString);
       emit operationSuccess("Teacher information fetched successfully");
       return teacherInfo;

    }
    catch (const std::runtime_error &e)
    {
        emit errorOccured(QString::fromStdString(e.what()));
        return{};
    }



}

Model::StudentScore
Controller::studentViewController::getStudentScore(const std::string &basicString, const std::string &basicString1) {
    try{
        Model::StudentScore studentScore = MYDB::QueryModel::getStudentScore(basicString, basicString1);
        emit operationSuccess("Student score fetched successfully");
        return studentScore;
    }
    catch (const std::runtime_error &e)
    {
        emit errorOccured(QString::fromStdString(e.what()));
        return{};
    }

}
