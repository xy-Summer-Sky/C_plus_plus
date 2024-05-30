/********************************************************************************
** Form generated from reading UI file 'adminform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace SystemUi {

class Ui_AdminForm
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabAddStudent;
    QFormLayout *formLayoutAdd;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelID;
    QLineEdit *lineEditID;
    QPushButton *buttonAdd;
    QWidget *tabEditStudent;
    QVBoxLayout *verticalLayoutEdit;
    QLineEdit *lineEditSearch;
    QPushButton *buttonSearch;
    QWidget *tabGenerateReports;
    QVBoxLayout *verticalLayoutReports;
    QPushButton *buttonReport;

    void setupUi(QWidget *SystemUi__AdminForm)
    {
        if (SystemUi__AdminForm->objectName().isEmpty())
            SystemUi__AdminForm->setObjectName("SystemUi__AdminForm");
        SystemUi__AdminForm->resize(800, 600);
        verticalLayout = new QVBoxLayout(SystemUi__AdminForm);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(SystemUi__AdminForm);
        tabWidget->setObjectName("tabWidget");
        tabAddStudent = new QWidget();
        tabAddStudent->setObjectName("tabAddStudent");
        formLayoutAdd = new QFormLayout(tabAddStudent);
        formLayoutAdd->setObjectName("formLayoutAdd");
        labelName = new QLabel(tabAddStudent);
        labelName->setObjectName("labelName");

        formLayoutAdd->setWidget(0, QFormLayout::LabelRole, labelName);

        lineEditName = new QLineEdit(tabAddStudent);
        lineEditName->setObjectName("lineEditName");

        formLayoutAdd->setWidget(0, QFormLayout::FieldRole, lineEditName);

        labelID = new QLabel(tabAddStudent);
        labelID->setObjectName("labelID");

        formLayoutAdd->setWidget(1, QFormLayout::LabelRole, labelID);

        lineEditID = new QLineEdit(tabAddStudent);
        lineEditID->setObjectName("lineEditID");

        formLayoutAdd->setWidget(1, QFormLayout::FieldRole, lineEditID);

        buttonAdd = new QPushButton(tabAddStudent);
        buttonAdd->setObjectName("buttonAdd");

        formLayoutAdd->setWidget(2, QFormLayout::SpanningRole, buttonAdd);

        tabWidget->addTab(tabAddStudent, QString());
        tabEditStudent = new QWidget();
        tabEditStudent->setObjectName("tabEditStudent");
        verticalLayoutEdit = new QVBoxLayout(tabEditStudent);
        verticalLayoutEdit->setObjectName("verticalLayoutEdit");
        lineEditSearch = new QLineEdit(tabEditStudent);
        lineEditSearch->setObjectName("lineEditSearch");

        verticalLayoutEdit->addWidget(lineEditSearch);

        buttonSearch = new QPushButton(tabEditStudent);
        buttonSearch->setObjectName("buttonSearch");

        verticalLayoutEdit->addWidget(buttonSearch);

        tabWidget->addTab(tabEditStudent, QString());
        tabGenerateReports = new QWidget();
        tabGenerateReports->setObjectName("tabGenerateReports");
        verticalLayoutReports = new QVBoxLayout(tabGenerateReports);
        verticalLayoutReports->setObjectName("verticalLayoutReports");
        buttonReport = new QPushButton(tabGenerateReports);
        buttonReport->setObjectName("buttonReport");

        verticalLayoutReports->addWidget(buttonReport);

        tabWidget->addTab(tabGenerateReports, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(SystemUi__AdminForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemUi__AdminForm);
    } // setupUi

    void retranslateUi(QWidget *SystemUi__AdminForm)
    {
        labelName->setText(QCoreApplication::translate("SystemUi::AdminForm", "Student Name:", nullptr));
        labelID->setText(QCoreApplication::translate("SystemUi::AdminForm", "Student ID:", nullptr));
        buttonAdd->setText(QCoreApplication::translate("SystemUi::AdminForm", "Add Student", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAddStudent), QCoreApplication::translate("SystemUi::AdminForm", "Add Student", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("SystemUi::AdminForm", "Search by ID or Name", nullptr));
        buttonSearch->setText(QCoreApplication::translate("SystemUi::AdminForm", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEditStudent), QCoreApplication::translate("SystemUi::AdminForm", "Edit Student", nullptr));
        buttonReport->setText(QCoreApplication::translate("SystemUi::AdminForm", "Generate Report", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGenerateReports), QCoreApplication::translate("SystemUi::AdminForm", "Generate Reports", nullptr));
        (void)SystemUi__AdminForm;
    } // retranslateUi

};

} // namespace SystemUi

namespace SystemUi {
namespace Ui {
    class AdminForm: public Ui_AdminForm {};
} // namespace Ui
} // namespace SystemUi

#endif // UI_ADMINFORM_H
