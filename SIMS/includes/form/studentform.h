//
// Created by Lenovo on 24-5-24.
//

#ifndef SIMS_STUDENTFORM_H
#define SIMS_STUDENTFORM_H

#include <QWidget>
#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include "studentViewControl.h"
#include "student.h"
#include "course.h"
#include<vector>
namespace Controller {
   class studentViewControl;
}
namespace SystemUi {
    QT_BEGIN_NAMESPACE
    namespace Ui { class StudentForm; }
    QT_END_NAMESPACE

    class StudentForm : public QWidget {
    Q_OBJECT

    public:
        explicit StudentForm(QWidget *parent = nullptr);

        ~StudentForm() override;

        void updateStudentInfo(const std::string& name, const std::string& id, const std::string& email, const std::string& phone_number);


    private:
        Ui::StudentForm *ui;
        Controller::studentViewControl * controller;
        Model::StudentDTO * student;
        std::vector<Model::Course> * course;


    };
} // SystemUi

#endif //SIMS_STUDENTFORM_H
