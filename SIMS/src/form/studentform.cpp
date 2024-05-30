//
// Created by Lenovo on 24-5-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StudentForm.h" resolved

#include "studentform.h"
#include "ui_StudentForm.h"

namespace SystemUi {
    StudentForm::StudentForm(QWidget *parent) :
            QWidget(parent), ui(new Ui::StudentForm) {
        ui->setupUi(this);
        ui->lineEditName->setReadOnly(true);
        ui->lineEditID->setReadOnly(true);
        ui->lineEditEmail->setReadOnly(true);
        ui->lineEditPhoneNumber->setReadOnly(true);
        ui->tableWidgetCourses->setEditTriggers(QAbstractItemView::NoEditTriggers);

        // Create a StudentController
        controller = new Controller::studentViewControl(this);

        // Send a request to StudentController
        controller->requestStudentInfo();
    }

    StudentForm::~StudentForm() {
        delete ui;
    }

    void StudentForm::updateStudentInfo(const std::string& name, const std::string& id, const std::string& email, const std::string& phone_number) {

    }
}