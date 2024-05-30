//
// Created by Lenovo on 24-5-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LoginForm.h" resolved

#include "loginform.h"
#include "ui_LoginForm.h"

namespace SystemUi {
    LoginForm::LoginForm(QWidget *parent) :QWidget(parent), ui(new Ui::LoginForm) {\
        loginController = new Controller::LoginController();
        this->setWindowIcon(QIcon(":images/loginicon"));
        ui->setupUi(this);
        connect(ui->LoginButton, &QPushButton::clicked, this, &LoginForm::onLoginButtonClicked);

    }

    LoginForm::~LoginForm() {
        delete ui;
        delete ui;
        if(loginController != nullptr)
            delete loginController;
    }

    void SystemUi::LoginForm::onLoginButtonClicked() {
        std::string userID = ui->InputUsername->text().toStdString();
        std::string password = ui->InputPassword->text().toStdString();

        if (userID.empty() || password.empty()) {
            QMessageBox::warning(this, "Login Failed", "Please enter username and password.");
            return;
        }


        std::string userType;

        if (ui->Student->isChecked()) {
            userType = "student";
        } else if (ui->Admin->isChecked()) {
            userType = "admin";
        } else {
            QMessageBox::warning(this, "Login Failed", "Please select user type.");
            return;
        }


        if (loginController->validateUser(userID, password, userType)) {
            if (userType == "student") {
                // 跳转到学生界面
                auto *studentView = new StudentForm();
                studentView->show();
            } else if (userType == "admin") {
                // 跳转到管理员界面
                auto *adminView = new AdminForm();
                adminView->show();
            } else {
                QMessageBox::warning(this, "Login Failed", "Please select user type.");
            }


            this->close();
            return;
        } else {

            QMessageBox::warning(this, "Login Failed", "Username or password is incorrect.");
            ui->InputPassword->clear();

            return;
        }
    }

    } // SystemUi


