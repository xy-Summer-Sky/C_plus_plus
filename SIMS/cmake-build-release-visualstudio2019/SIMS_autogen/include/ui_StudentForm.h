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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace SystemUi {

class Ui_StudentForm
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetCourses;
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
        SystemUi__StudentForm->resize(449, 321);
        SystemUi__StudentForm->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        verticalLayout = new QVBoxLayout(SystemUi__StudentForm);
        verticalLayout->setObjectName("verticalLayout");
        tableWidgetCourses = new QTableWidget(SystemUi__StudentForm);
        if (tableWidgetCourses->columnCount() < 8)
            tableWidgetCourses->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetCourses->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetCourses->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetCourses->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetCourses->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidgetCourses->rowCount() < 6)
            tableWidgetCourses->setRowCount(6);
        tableWidgetCourses->setObjectName("tableWidgetCourses");
        tableWidgetCourses->setStyleSheet(QString::fromUtf8("QTableWidget { color: black; }"));
        tableWidgetCourses->setRowCount(6);
        tableWidgetCourses->setColumnCount(8);

        verticalLayout->addWidget(tableWidgetCourses);

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
        QTableWidgetItem *___qtablewidgetitem = tableWidgetCourses->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SystemUi::StudentForm", "\350\257\276\347\250\213ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetCourses->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SystemUi::StudentForm", "\350\257\276\347\250\213\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetCourses->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SystemUi::StudentForm", "\344\273\273\350\257\276\346\225\231\345\270\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetCourses->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SystemUi::StudentForm", "\350\257\276\347\250\213\345\276\227\345\210\206", nullptr));
        tableWidgetCourses->setProperty("horizontalHeaderLabels", QVariant(QStringList{
            QCoreApplication::translate("SystemUi::StudentForm", "Course ID", nullptr),
            QCoreApplication::translate("SystemUi::StudentForm", "Course Name", nullptr),
            QCoreApplication::translate("SystemUi::StudentForm", "Instructor Name", nullptr),
            QCoreApplication::translate("SystemUi::StudentForm", "Grade", nullptr)}));
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
