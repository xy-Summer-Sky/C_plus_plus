/********************************************************************************
** Form generated from reading UI file 'studentform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTFORM_H
#define UI_STUDENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace SystemUi {

class Ui_StudentForm
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableViewCourses;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelID;
    QLineEdit *lineEditID;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelPhoneNumber;
    QLineEdit *lineEditPhoneNumber;

    void setupUi(QWidget *SystemUi__StudentForm)
    {
        if (SystemUi__StudentForm->objectName().isEmpty())
            SystemUi__StudentForm->setObjectName("SystemUi__StudentForm");
        SystemUi__StudentForm->resize(560, 405);
        SystemUi__StudentForm->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        verticalLayout = new QVBoxLayout(SystemUi__StudentForm);
        verticalLayout->setObjectName("verticalLayout");
        tableViewCourses = new QTableView(SystemUi__StudentForm);
        tableViewCourses->setObjectName("tableViewCourses");
        tableViewCourses->setStyleSheet(QString::fromUtf8("QTableWidget { color: black; }"));

        verticalLayout->addWidget(tableViewCourses);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelName = new QLabel(SystemUi__StudentForm);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelName);

        lineEditName = new QLineEdit(SystemUi__StudentForm);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditName);

        labelID = new QLabel(SystemUi__StudentForm);
        labelID->setObjectName("labelID");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelID);

        lineEditID = new QLineEdit(SystemUi__StudentForm);
        lineEditID->setObjectName("lineEditID");
        lineEditID->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditID);

        labelEmail = new QLabel(SystemUi__StudentForm);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(SystemUi__StudentForm);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditEmail);

        labelPhoneNumber = new QLabel(SystemUi__StudentForm);
        labelPhoneNumber->setObjectName("labelPhoneNumber");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelPhoneNumber);

        lineEditPhoneNumber = new QLineEdit(SystemUi__StudentForm);
        lineEditPhoneNumber->setObjectName("lineEditPhoneNumber");
        lineEditPhoneNumber->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditPhoneNumber);


        verticalLayout->addLayout(formLayout);


        retranslateUi(SystemUi__StudentForm);

        QMetaObject::connectSlotsByName(SystemUi__StudentForm);
    } // setupUi

    void retranslateUi(QWidget *SystemUi__StudentForm)
    {
        SystemUi__StudentForm->setWindowTitle(QCoreApplication::translate("SystemUi::StudentForm", "Student View", nullptr));
        labelName->setText(QCoreApplication::translate("SystemUi::StudentForm", "Name:", nullptr));
        labelID->setText(QCoreApplication::translate("SystemUi::StudentForm", "Student ID:", nullptr));
        labelEmail->setText(QCoreApplication::translate("SystemUi::StudentForm", "Email:", nullptr));
        labelPhoneNumber->setText(QCoreApplication::translate("SystemUi::StudentForm", "Phone Number:", nullptr));
    } // retranslateUi

};

} // namespace SystemUi

namespace SystemUi {
namespace Ui {
    class StudentForm: public Ui_StudentForm {};
} // namespace Ui
} // namespace SystemUi

#endif // UI_STUDENTFORM_H
