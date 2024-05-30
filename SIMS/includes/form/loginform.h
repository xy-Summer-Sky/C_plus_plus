//
// Created by Lenovo on 24-5-24.
//

#ifndef SIMS_LOGINFORM_H
#define SIMS_LOGINFORM_H

#include <QWidget>
#include<QLineEdit>
#include<QPushButton>
#include<QLabel>
#include<QRadioButton>
#include <QWidget>
#include<QMessageBox>
#include"studentform.h"
#include"adminform.h"
#include"logincontroller.h"

namespace SystemUi {
    QT_BEGIN_NAMESPACE
    namespace Ui { class LoginForm; }
    QT_END_NAMESPACE

    class LoginForm : public QWidget {
    Q_OBJECT

    public:
        explicit LoginForm(QWidget *parent = nullptr);

        ~LoginForm() override;
        void onLoginButtonClicked();

    private:
        Ui::LoginForm *ui;
        Controller::LoginController * loginController;
    };
} // SystemUi

#endif //SIMS_LOGINFORM_H
