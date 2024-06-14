//
// Created by Lenovo on 24-5-24.
//

#ifndef SIMS_STUDENTVIEWCONTROLLER_H
#define SIMS_STUDENTVIEWCONTROLLER_H


#include <QObject>
#include"studentform.h"
#include "querymodel.h"

namespace SystemUi {
    class StudentForm;  // 前向声明
}

namespace Controller {
    class studentViewController : public QObject {
    Q_OBJECT



    public:

        std::vector<Model::Course> getStudentCourses(const std::string &basicString);
        Model::StudentDTO getStudent(const std::string &basicString);
        Model::TeacherInformation getTeacherInfo(const std::string &basicString);
        Model::StudentScore getStudentScore(const std::string &basicString, const std::string &basicString1);


    public:
        explicit studentViewController(SystemUi::StudentForm *view, QObject *parent = nullptr);

    public slots:

        void requestStudentInfo();

    signals:
        void errorOccured(const QString &message);//错误信号

        void operationSuccess(const QString &successMessage);//操作成功信号

    private:
        SystemUi::StudentForm *view;
    };

}


#endif
