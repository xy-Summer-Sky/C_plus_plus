/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace SystemUi {

class Ui_LoginForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *logintitle;
    QSpacerItem *spacertop;
    QHBoxLayout *Username_2;
    QLabel *Username;
    QLineEdit *InputUsername;
    QHBoxLayout *Password_2;
    QLabel *Password;
    QLineEdit *InputPassword;
    QSpacerItem *spacerlbottom;
    QHBoxLayout *UserTypeSelect;
    QRadioButton *Student;
    QRadioButton *Admin;
    QHBoxLayout *LoginorExit;
    QPushButton *LoginButton;
    QPushButton *ExitButton;

    void setupUi(QWidget *SystemUi__LoginForm)
    {
        if (SystemUi__LoginForm->objectName().isEmpty())
            SystemUi__LoginForm->setObjectName("SystemUi__LoginForm");
        SystemUi__LoginForm->setWindowModality(Qt::WindowModality::ApplicationModal);
        SystemUi__LoginForm->resize(516, 268);
        QFont font;
        font.setWeight(QFont::Medium);
        SystemUi__LoginForm->setFont(font);
        verticalLayout = new QVBoxLayout(SystemUi__LoginForm);
        verticalLayout->setObjectName("verticalLayout");
        logintitle = new QLabel(SystemUi__LoginForm);
        logintitle->setObjectName("logintitle");
        QFont font1;
        font1.setPointSize(12);
        font1.setWeight(QFont::Medium);
        logintitle->setFont(font1);
        logintitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(logintitle);

        spacertop = new QSpacerItem(30, 33, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(spacertop);

        Username_2 = new QHBoxLayout();
        Username_2->setObjectName("Username_2");
        Username = new QLabel(SystemUi__LoginForm);
        Username->setObjectName("Username");

        Username_2->addWidget(Username);

        InputUsername = new QLineEdit(SystemUi__LoginForm);
        InputUsername->setObjectName("InputUsername");
        InputUsername->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        Username_2->addWidget(InputUsername);


        verticalLayout->addLayout(Username_2);

        Password_2 = new QHBoxLayout();
        Password_2->setObjectName("Password_2");
        Password = new QLabel(SystemUi__LoginForm);
        Password->setObjectName("Password");

        Password_2->addWidget(Password);

        InputPassword = new QLineEdit(SystemUi__LoginForm);
        InputPassword->setObjectName("InputPassword");
        InputPassword->setContextMenuPolicy(Qt::ContextMenuPolicy::PreventContextMenu);
        InputPassword->setEchoMode(QLineEdit::EchoMode::Password);

        Password_2->addWidget(InputPassword);


        verticalLayout->addLayout(Password_2);

        spacerlbottom = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(spacerlbottom);

        UserTypeSelect = new QHBoxLayout();
        UserTypeSelect->setObjectName("UserTypeSelect");
        UserTypeSelect->setContentsMargins(164, -1, 22, -1);
        Student = new QRadioButton(SystemUi__LoginForm);
        Student->setObjectName("Student");

        UserTypeSelect->addWidget(Student);

        Admin = new QRadioButton(SystemUi__LoginForm);
        Admin->setObjectName("Admin");

        UserTypeSelect->addWidget(Admin);


        verticalLayout->addLayout(UserTypeSelect);

        LoginorExit = new QHBoxLayout();
        LoginorExit->setObjectName("LoginorExit");
        LoginorExit->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        LoginButton = new QPushButton(SystemUi__LoginForm);
        LoginButton->setObjectName("LoginButton");

        LoginorExit->addWidget(LoginButton);

        ExitButton = new QPushButton(SystemUi__LoginForm);
        ExitButton->setObjectName("ExitButton");

        LoginorExit->addWidget(ExitButton);


        verticalLayout->addLayout(LoginorExit);


        retranslateUi(SystemUi__LoginForm);
        QObject::connect(ExitButton, &QPushButton::clicked, SystemUi__LoginForm, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(SystemUi__LoginForm);
    } // setupUi

    void retranslateUi(QWidget *SystemUi__LoginForm)
    {
        SystemUi__LoginForm->setWindowTitle(QCoreApplication::translate("SystemUi::LoginForm", "LoginForm", nullptr));
        logintitle->setText(QCoreApplication::translate("SystemUi::LoginForm", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        Username->setText(QCoreApplication::translate("SystemUi::LoginForm", "UserName:", nullptr));
        Password->setText(QCoreApplication::translate("SystemUi::LoginForm", "Password:  ", nullptr));
        InputPassword->setPlaceholderText(QString());
        Student->setText(QCoreApplication::translate("SystemUi::LoginForm", "Student", nullptr));
        Admin->setText(QCoreApplication::translate("SystemUi::LoginForm", "Admin", nullptr));
        LoginButton->setText(QCoreApplication::translate("SystemUi::LoginForm", "Login", nullptr));
        ExitButton->setText(QCoreApplication::translate("SystemUi::LoginForm", "Exit", nullptr));
    } // retranslateUi

};

} // namespace SystemUi

namespace SystemUi {
namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui
} // namespace SystemUi

#endif // UI_LOGINFORM_H
