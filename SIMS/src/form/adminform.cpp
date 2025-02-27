//
// Created by Lenovo on 24-5-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdminForm.h" resolved

#include <QMessageBox>
#include <QGraphicsOpacityEffect>
#include "adminform.h"
#include "ui_AdminForm.h"
#include "dbmanager.h"
#include "student.h"
#include "QTimer"
#include "QMessageBox"
#include "QStandardItemModel"

namespace SystemUi {
    AdminForm::AdminForm(QWidget *parent) :
            QWidget(parent), ui(new Ui::AdminForm) {
        ui->setupUi(this);
        adminController = new Controller::AdminController();
        // Connect the student save button
        connect(ui->buttonSaveStudent, &QPushButton::clicked, this, &AdminForm::onSaveStudent);
        connect(ui->QueryStudent, &QPushButton::clicked, this, &AdminForm::onQueryStudent);
        connect(ui->deleteStudent, &QPushButton::clicked, this, &AdminForm::onDeleteStudent);
        connect(ui->UpdateStudent, &QPushButton::clicked, this, &AdminForm::onUpdateStudent);
        connect(ui->buttonAddCourse, &QPushButton::clicked, this, &AdminForm::onAddCourseToStudent);
        connect(ui->buttonRemoveCourse, &QPushButton::clicked, this, &AdminForm::onRemoveCourseFromStudent);
        connect(ui->addCourseButton, &QPushButton::clicked, this, &AdminForm::onAddCourse);
        connect(ui->updateCourseButton, &QPushButton::clicked, this, &AdminForm::onUpdateCourse);
        connect(ui->deleteCourseButton, &QPushButton::clicked, this, &AdminForm::onDeleteCourse);
        connect(ui->viewCoursesButton, &QPushButton::clicked, this, &AdminForm::onViewCourses);
        connect(ui->buttonAddAccount, &QPushButton::clicked, this, &AdminForm::onAddAccount);
        connect(ui->buttonUpdateAccount, &QPushButton::clicked, this, &AdminForm::onUpdateAccount);
        connect(ui->buttonDeleteAccount, &QPushButton::clicked, this, &AdminForm::onDeleteAccount);
        connect(ui->buttonQueryAccount, &QPushButton::clicked, this, &AdminForm::onQueryAccount);
        connect(ui->buttonListAllAccount, &QPushButton::clicked, this, &AdminForm::displayAccountInfo);
        connect(ui->ButtonAddTeacher, &QPushButton::clicked, this, &AdminForm::onAddTeacher);
        connect(ui->ButtonUpdateTeacher, &QPushButton::clicked, this, &AdminForm::onUpdateTeacher);
        connect(ui->ButtonDeleteTeacher, &QPushButton::clicked, this, &AdminForm::onDeleteTeacher);
        connect(ui->ButtonQueryTeacher, &QPushButton::clicked, this, &AdminForm::onQueryTeacher);
        connect(ui->ListAllTeachers, &QPushButton::clicked, this, &AdminForm::displayTeacherInfo);
        connect(ui->ScoreButton, &QPushButton::clicked, this, &AdminForm::onUpdateScore);
        connect(ui->ButtonListAllStudents, &QPushButton::clicked, this, &AdminForm::displayAllStudentInfo);
        connect(ui->ButtonQueryCourse, &QPushButton::clicked, this, &AdminForm::onQueryCourse);
        // Connect the error signal
        connect(adminController, &Controller::AdminController::errorOccured, this, &AdminForm::displayError);

        // Connect the success signal
        connect(adminController, &Controller::AdminController::operationSuccess, this,
                &AdminForm::displaySuccessMessage);
    }

    void AdminForm::onSaveStudent() {
        //确保输入不为空
        if(ui->lineEditName->text().isEmpty() || ui->lineEditID->text().isEmpty() || ui->lineEditEmail->text().isEmpty() || ui->lineEditPhone->text().isEmpty())
        {
            QMessageBox::warning(this, "Save Failed", "Please enter all the information.");
            return;
        }

        Model::StudentDTO studentDTO(ui->lineEditName->text().toStdString(), ui->lineEditID->text().toStdString(),
                                     ui->lineEditEmail->text().toStdString(), ui->lineEditPhone->text().toStdString());
        adminController->saveStudent(studentDTO);
    }

    void AdminForm::onQueryStudent() {
        if(ui->lineEditID->text().isEmpty())
        {
            QMessageBox::warning(this, "Query Failed", "Please enter the student ID.");
            return;
        }
        Model::StudentDTO studentDTO = adminController->queryStudent(ui->lineEditID->text().toStdString());
        ui->lineEditName->setText(QString::fromStdString(studentDTO.getName()));
        ui->lineEditEmail->setText(QString::fromStdString(studentDTO.getEmail()));
        ui->lineEditPhone->setText(QString::fromStdString(studentDTO.getPhoneNumber()));

        // 获取学生的课程信息
        std::vector<Model::Course> courses = adminController->getALLCoursesForStudent(
                ui->lineEditID->text().toStdString());

        // 显示课程信息
        auto *model = new QStandardItemModel(courses.size(), 6, this); // 注意这里列数变为5
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Course ID")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Course Name")));
        model->setHorizontalHeaderItem(2, new QStandardItem(QString("Teacher ID")));
        model->setHorizontalHeaderItem(3, new QStandardItem(QString("Teacher Name"))); // 新增
        model->setHorizontalHeaderItem(4, new QStandardItem(QString("Teacher Email"))); // 新增
        model->setHorizontalHeaderItem(5, new QStandardItem(QString("Score"))); // 新增
        for (int i = 0; i < courses.size(); i++) {
            model->setItem(i, 0, new QStandardItem(QString::fromStdString(courses[i].getId())));
            model->setItem(i, 1, new QStandardItem(QString::fromStdString(courses[i].getName())));
            model->setItem(i, 2, new QStandardItem(QString::fromStdString(courses[i].getTeacherId())));
            Model::TeacherInformation teacher = adminController->getTeacherInfo(
                    QString::fromStdString(courses[i].getTeacherId())); // 新增
            model->setItem(i, 3, new QStandardItem(QString::fromStdString(teacher.getName()))); // 新增
            model->setItem(i, 4, new QStandardItem(QString::fromStdString(teacher.getEmail())));
            //同时显示成绩
            Model::StudentScore score = adminController->getStudentScore(ui->lineEditID->text().toStdString(),
                                                                         courses[i].getId());
            model->setItem(i, 5, new QStandardItem(QString::fromStdString(score.getScore())));
        }
        ui->tableViewCourses->setModel(model);
        ui->tableViewCourses->resizeColumnsToContents();
        ui->tableViewCourses->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewCourses->show();
    }

    void AdminForm::onDeleteStudent() {
        if(ui->lineEditID->text().isEmpty())
        {
            QMessageBox::warning(this, "Delete Failed", "Please enter the student ID.");
            return;
        }
        adminController->deleteStudent(ui->lineEditID->text());
    }

    void AdminForm::onAddCourseToStudent() {
        if(ui->lineEditID->text().isEmpty() || ui->addCourseId->text().isEmpty())
        {
            QMessageBox::warning(this, "Add Failed", "Please enter the student ID and course ID.");
            return;
        }
        adminController->addCourseToStudent(ui->lineEditID->text().toStdString(),
                                            ui->addCourseId->text().toStdString());
    }

    void AdminForm::onRemoveCourseFromStudent() {
        if(ui->lineEditID->text().isEmpty() || ui->deleteCOURSEid->text().isEmpty())
        {
            QMessageBox::warning(this, "Remove Failed", "Please enter the student ID and course ID.");
            return;
        }
        adminController->removeCourseFromStudent(ui->lineEditID->text().toStdString(),
                                                 ui->deleteCOURSEid->text().toStdString());
    }

    void AdminForm::onAddCourse() {
        if(ui->courseNameLineEdit->text().isEmpty() || ui->courseIDLineEdit->text().isEmpty() || ui->teacherIDLineEdit->text().isEmpty())
        {
            QMessageBox::warning(this, "Add Failed", "Please enter all the information.");
            return;
        }
        adminController->addCourse(ui->courseNameLineEdit->text(), ui->courseIDLineEdit->text(),
                                   ui->teacherIDLineEdit->text());
    }

    void AdminForm::onUpdateCourse() {

        if(ui->courseNameLineEdit->text().isEmpty() || ui->courseIDLineEdit->text().isEmpty() || ui->teacherIDLineEdit->text().isEmpty())
        {
            QMessageBox::warning(this, "Update Failed", "Please enter all the information.");
            return;
        }
        adminController->updateCourse(ui->courseIDLineEdit->text(), ui->courseNameLineEdit->text(),
                                      ui->teacherIDLineEdit->text());
    }

    void AdminForm::onDeleteCourse() {
        if(ui->courseIDLineEdit->text().isEmpty())
        {
            QMessageBox::warning(this, "Delete Failed", "Please enter the course ID.");
            return;
        }
        adminController->deleteCourse(ui->courseIDLineEdit->text());
    }

    void AdminForm::onViewCourses() {
        std::vector<Model::Course> courses = adminController->viewCourses();
        auto *model = new QStandardItemModel(courses.size(), 5, this); // 注意这里列数变为5
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Course ID")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Course Name")));
        model->setHorizontalHeaderItem(2, new QStandardItem(QString("Teacher ID")));
        model->setHorizontalHeaderItem(3, new QStandardItem(QString("Teacher Name"))); // 新增
        model->setHorizontalHeaderItem(4, new QStandardItem(QString("Teacher Email"))); // 新增
        for (int i = 0; i < courses.size(); i++) {
            model->setItem(i, 0, new QStandardItem(QString::fromStdString(courses[i].getId())));
            model->setItem(i, 1, new QStandardItem(QString::fromStdString(courses[i].getName())));
            model->setItem(i, 2, new QStandardItem(QString::fromStdString(courses[i].getTeacherId())));
            Model::TeacherInformation teacher = adminController->getTeacherInfo(
                    QString::fromStdString(courses[i].getTeacherId())); // 新增
            model->setItem(i, 3, new QStandardItem(QString::fromStdString(teacher.getName()))); // 新增
            model->setItem(i, 4, new QStandardItem(QString::fromStdString(teacher.getEmail()))); // 新增
        }
        //不可修改
        ui->courseTableView->resizeColumnsToContents();
        ui->courseTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->courseTableView->setModel(model);
    }


    void AdminForm::displayError(const QString &errorMessage) {
        QMessageBox::critical(this, "Database Error", errorMessage);
    }


    void AdminForm::displaySuccessMessage(const QString &successMessage) {
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


    AdminForm::~AdminForm() {
        delete ui;
    }

    void AdminForm::onUpdateStudent() {
        if(ui->lineEditName->text().isEmpty() || ui->lineEditID->text().isEmpty() || ui->lineEditEmail->text().isEmpty() || ui->lineEditPhone->text().isEmpty())
        {
            QMessageBox::warning(this, "Update Failed", "Please enter all the information.");
            return;
        }
        Model::StudentDTO studentDTO(ui->lineEditName->text().toStdString(), ui->lineEditID->text().toStdString(),
                                     ui->lineEditEmail->text().toStdString(), ui->lineEditPhone->text().toStdString());
        adminController->updateStudent(studentDTO);

    }

    void AdminForm::onUpdateScore() {
        if(ui->studentIDLineEditScore->text().isEmpty() || ui->courseIDLineEditScore->text().isEmpty() || ui->scoreLineEdit->text().isEmpty())
        {
            QMessageBox::warning(this, "Update Failed", "Please enter all the information.");
            return;
        }
        adminController->updateScore(ui->studentIDLineEditScore->text(), ui->courseIDLineEditScore->text(),
                                     ui->scoreLineEdit->text());
    }

    void AdminForm::displayAllStudentInfo() {
        std::vector<Model::StudentDTO> students = adminController->displayAllStudents();
        auto *model = new QStandardItemModel(students.size(), 4, this);
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Student ID")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Student Name")));
        model->setHorizontalHeaderItem(2, new QStandardItem(QString("Student Email")));
        model->setHorizontalHeaderItem(3, new QStandardItem(QString("Student Phone")));
        for (int i = 0; i < students.size(); i++) {
            model->setItem(i, 0, new QStandardItem(QString::fromStdString(students[i].getId())));
            model->setItem(i, 1, new QStandardItem(QString::fromStdString(students[i].getName())));
            model->setItem(i, 2, new QStandardItem(QString::fromStdString(students[i].getEmail())));
            model->setItem(i, 3, new QStandardItem(QString::fromStdString(students[i].getPhoneNumber())));
        }
        //不可修改
        ui->tableViewCourses->resizeColumnsToContents();
        ui->tableViewCourses->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewCourses->setModel(model);

    }

    void AdminForm::onQueryCourse() {
        if(ui->courseIDLineEdit->text().isEmpty())
        {
            QMessageBox::warning(this, "Query Failed", "Please enter the course ID.");
            return;
        }
        Model::Course course = adminController->queryCourse(ui->courseIDLineEdit->text().toStdString());
        // 创建一个新的 QStandardItemModel
        auto *model = new QStandardItemModel(1, 5, this); // 注意这里列数变为5
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Course ID")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Course Name")));
        model->setHorizontalHeaderItem(2, new QStandardItem(QString("Teacher ID")));
        model->setHorizontalHeaderItem(3, new QStandardItem(QString("Teacher Name"))); // 新增
        model->setHorizontalHeaderItem(4, new QStandardItem(QString("Teacher Email"))); // 新增

        model->setItem(0, 0, new QStandardItem(QString::fromStdString(course.getId())));
        model->setItem(0, 1, new QStandardItem(QString::fromStdString(course.getName())));
        model->setItem(0, 2, new QStandardItem(QString::fromStdString(course.getTeacherId())));
        if(course.getTeacherId().empty())
        {
            return;
        }
        Model::TeacherInformation teacher = adminController->getTeacherInfo(
                QString::fromStdString(course.getTeacherId())); // 新增
        model->setItem(0, 3, new QStandardItem(QString::fromStdString(teacher.getName()))); // 新增
        model->setItem(0, 4, new QStandardItem(QString::fromStdString(teacher.getEmail()))); // 新增

        //不可修改
        ui->courseTableView->resizeColumnsToContents();
        ui->courseTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->courseTableView->setModel(model);
    }


} // SystemUi
