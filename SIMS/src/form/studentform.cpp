//
// Created by Lenovo on 24-5-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StudentForm.h" resolved

#include <QStandardItemModel>
#include <QGraphicsOpacityEffect>
#include <QMessageBox>
#include "studentform.h"
#include "ui_StudentForm.h"
#include "logincontroller.h"
#include <QTimer>

namespace SystemUi {
    StudentForm::StudentForm(QWidget *parent) :
            QWidget(parent), ui(new Ui::StudentForm) {
        ui->setupUi(this);
        ui->lineEditName->setReadOnly(true);
        ui->lineEditID->setReadOnly(true);
        ui->lineEditEmail->setReadOnly(true);
        ui->lineEditPhoneNumber->setReadOnly(true);
        ui->lineEditPhoneNumber->setReadOnly(true);
        ui->tableViewCourses->setEditTriggers(QAbstractItemView::NoEditTriggers);

        // Create a StudentController
        controller = new Controller::studentViewController(this);

        // Create a LoginController
        loginController = new Controller::LoginController();

        // Send a request to StudentController
        controller->requestStudentInfo();
        // Connect the error signal
        connect(controller, &Controller::studentViewController::errorOccured, this, &StudentForm::displayError);

        // Connect the success signal
        connect(controller, &Controller::studentViewController::operationSuccess, this,&StudentForm::displaySuccessMessage);

    }

    StudentForm::~StudentForm() {
        delete ui;
    }

    void StudentForm::displayStudentInfo(const std::string &studentId) {
        // 获取学生信息
        qDebug() << "displayStudentInfo function called";
        Model::StudentDTO Student = controller->getStudent(studentId);
        qDebug() << "Student info got successfully";

        if (Student.getName().empty() || Student.getId().empty() || Student.getEmail().empty() || Student.getPhoneNumber().empty()) {
            qDebug() << "No student info found";
            emit controller->errorOccured("No student info found");
            return;
        }
        ui->lineEditName->setText(QString::fromStdString(Student.getName()));
        ui->lineEditID->setText(QString::fromStdString(Student.getId()));
        ui->lineEditEmail->setText(QString::fromStdString(Student.getEmail()));
        ui->lineEditPhoneNumber->setText(QString::fromStdString(Student.getPhoneNumber()));

        // 获取课程信息
        std::vector<Model::Course> courses = controller->getStudentCourses(studentId);
        auto *model = new QStandardItemModel(courses.size(), 5, this);
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Course ID")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Course Name")));
        model->setHorizontalHeaderItem(2, new QStandardItem(QString("Teacher Name")));
        model->setHorizontalHeaderItem(3, new QStandardItem(QString("Teacher Email")));
        model->setHorizontalHeaderItem(4, new QStandardItem(QString("Score")));
        for (int i = 0; i < courses.size(); i++) {
            model->setItem(i, 0, new QStandardItem(QString::fromStdString(courses[i].getId())));
            model->setItem(i, 1, new QStandardItem(QString::fromStdString(courses[i].getName())));
            Model::TeacherInformation teacher = controller->getTeacherInfo(courses[i].getTeacherId());
            model->setItem(i, 2, new QStandardItem(QString::fromStdString(teacher.getName())));
            model->setItem(i, 3, new QStandardItem(QString::fromStdString(teacher.getEmail())));
            Model::StudentScore score = controller->getStudentScore(studentId, courses[i].getId());
            model->setItem(i, 4, new QStandardItem(QString::fromStdString(score.getScore())));

        }
        ui->tableViewCourses->setModel(model);
    }


    void StudentForm::onUserValidated(const std::string &userId) {
        qDebug() << "onUserValidated slot called";
        displayStudentInfo(userId);
    }


    void StudentForm::displayError(const QString &errorMessage) {
        QMessageBox::critical(this, "Database Error", errorMessage);
    }


    void StudentForm::displaySuccessMessage(const QString &successMessage) {
        auto *dialog = new QDialog(this, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint); // 移除标题行并保持在顶部
        dialog->setModal(false); // 设置为非模态

        // 设置对话框的透明度
        auto *effect = new QGraphicsOpacityEffect(this);
        effect->setOpacity(0.7); // 70% 透明度
        dialog->setGraphicsEffect(effect);

        // 设置对话框的位置在界面底部
        dialog->move(this->x(), this->y() + this->height() - dialog->height());
        dialog->setStyleSheet("background-color: white;"); // 设置背景颜色为白色

        auto *layout = new QVBoxLayout(dialog);
        auto *label = new QLabel(successMessage, dialog);
        label->setStyleSheet("QLabel { color : black; }"); // 设置文字颜色为黑色
        layout->addWidget(label);
        dialog->setLayout(layout);

        // 设置对话框的大小为长条状
        dialog->setFixedWidth(this->width());
        dialog->setFixedHeight(50); // 可以根据需要调整高度

        QTimer::singleShot(2000, dialog, &QDialog::accept); // 2秒后自动关闭
        dialog->show();
    }
}