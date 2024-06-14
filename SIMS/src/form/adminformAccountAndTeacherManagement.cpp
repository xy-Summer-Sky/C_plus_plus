//
// Created by Lenovo on 24-6-7.
//
#include <QMessageBox>
#include"adminform.h"
#include"admincontroller.h"
#include"ui_AdminForm.h"

void SystemUi::AdminForm::onAddAccount() {
    if(ui->useridLineEdit->text().isEmpty()||ui->passwordLineEditAccountManagement->text().isEmpty())
    {
        QMessageBox::warning(this, "Add Account Failed", "Please enter username and password.");
        return;
    }

    adminController->addAccount(ui->useridLineEdit->text(), ui->passwordLineEditAccountManagement->text(), ui->UserType->currentText());
}

void SystemUi::AdminForm::onUpdateAccount() {
    if(ui->useridLineEdit->text().isEmpty()||ui->passwordLineEditAccountManagement->text().isEmpty())
    {
        QMessageBox::warning(this, "Update Account Failed", "Please enter username and password.");
        return;
    }
   adminController->updateAccount(ui->useridLineEdit->text(), ui->passwordLineEditAccountManagement->text(), ui->UserType->currentText());
}

void SystemUi::AdminForm::onDeleteAccount() {
    if(ui->useridLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Delete Account Failed", "Please enter username.");
        return;
    }
    adminController->deleteAccount(ui->useridLineEdit->text());
}

void SystemUi::AdminForm::onQueryAccount() {
    if(ui->useridLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Query Account Failed", "Please enter username.");
        return;
    }
    Model::UserAccount userAccount=adminController->queryAccount(ui->useridLineEdit->text());
    ui->useridLineEdit->setText(userAccount.getUsername().c_str());
    ui->passwordLineEditAccountManagement->setText(userAccount.getPassword().c_str());
    ui->UserType->setCurrentText(userAccount.getUserType().c_str());

}

void SystemUi::AdminForm::displayAccountInfo() {

    std::vector<Model::UserAccount> accounts =adminController->displayAllAccounts();
    // 创建一个新的模型
    auto *model = new QStandardItemModel(accounts.size(), 3, this); // 4列，分别为账户ID、密码、角色和用户名

    // 设置表头

    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Password")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Role")));
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Username")));

    // 填充数据
    for (int i = 0; i < accounts.size(); i++) {

        model->setItem(i, 1, new QStandardItem(QString::fromStdString(accounts[i].getPassword())));
        model->setItem(i, 2, new QStandardItem(QString::fromStdString(accounts[i].getUserType())));
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(accounts[i].getUsername())));
    }

    // 将模型设置到视图
    ui->AccountList->resizeColumnsToContents();
    ui->AccountList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->AccountList->setModel(model);

}

void SystemUi::AdminForm::onAddTeacher() {
    if(ui->teacherNameLineEdit->text().isEmpty()||ui->teacherIdLineEdit->text().isEmpty()||ui->teacherEmailLineEdit->text().isEmpty()||ui->teacherPhoneNumberLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Add Teacher Failed", "Please enter teacher's name, id, email and phone number.");
        return;
    }
    adminController->addTeacher(ui->teacherNameLineEdit->text(), ui->teacherIdLineEdit->text(), ui->teacherEmailLineEdit->text(), ui->teacherPhoneNumberLineEdit->text());
}

void SystemUi::AdminForm::onUpdateTeacher() {
    if(ui->teacherNameLineEdit->text().isEmpty()||ui->teacherIdLineEdit->text().isEmpty()||ui->teacherEmailLineEdit->text().isEmpty()||ui->teacherPhoneNumberLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Update Teacher Failed", "Please enter teacher's name, id, email and phone number.");
        return;
    }
    adminController->updateTeacher(ui->teacherIdLineEdit->text(), ui->teacherNameLineEdit->text(), ui->teacherEmailLineEdit->text(), ui->teacherPhoneNumberLineEdit->text());
}

void SystemUi::AdminForm::onDeleteTeacher() {
    if(ui->teacherIdLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Delete Teacher Failed", "Please enter teacher's id.");
        return;
    }
    adminController->deleteTeacher(ui->teacherIdLineEdit->text());
}

void SystemUi::AdminForm::onQueryTeacher() {
    if(ui->teacherIdLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Query Teacher Failed", "Please enter teacher's id.");
        return;
    }
    Model::TeacherInformation teacher = adminController->queryTeacher(ui->teacherIdLineEdit->text());
    if(teacher.getId().empty()||teacher.getName().empty()||teacher.getEmail().empty()||teacher.getPhoneNumber().empty())
    {return;
    }
    ui->teacherIdLineEdit->setText(teacher.getId().c_str());
    ui->teacherNameLineEdit->setText(teacher.getName().c_str());
    ui->teacherEmailLineEdit->setText(teacher.getEmail().c_str());
    ui->teacherPhoneNumberLineEdit->setText(teacher.getPhoneNumber().c_str());
}

void SystemUi::AdminForm::displayTeacherInfo() {
    std::vector<Model::TeacherInformation> teachers = adminController->displayAllTeachers();
    // 创建一个新的模型
    if(teachers.empty())
    {
        return;
    }
    auto *model = new QStandardItemModel(teachers.size(), 4, this); // 4列，分别为教师ID、姓名、邮箱和电话

    // 设置表头
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Teacher ID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Teacher Name")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Teacher Email")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Teacher Phone")));

    // 填充数据
    for (int i = 0; i < teachers.size(); i++) {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(teachers[i].getId())));
        model->setItem(i, 1, new QStandardItem(QString::fromStdString(teachers[i].getName())));
        model->setItem(i, 2, new QStandardItem(QString::fromStdString(teachers[i].getEmail())));
        model->setItem(i, 3, new QStandardItem(QString::fromStdString(teachers[i].getPhoneNumber())));
    }

    // 将模型设置到视图
    ui->TeachersTableView->resizeColumnsToContents();
    ui->TeachersTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TeachersTableView->setModel(model);

}


