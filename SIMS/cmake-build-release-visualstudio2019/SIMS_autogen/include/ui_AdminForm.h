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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace SystemUi {

class Ui_AdminForm
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabStudent;
    QVBoxLayout *verticalLayoutStudent;
    QFormLayout *formLayoutStudent;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelID;
    QLineEdit *lineEditID;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelPhone;
    QLineEdit *lineEditPhone;
    QPushButton *buttonSaveStudent;
    QPushButton *QueryStudent;
    QPushButton *UpdateStudent;
    QPushButton *deleteStudent;
    QHBoxLayout *horizontalLayoutCourses;
    QTableWidget *tableWidgetCourses;
    QVBoxLayout *verticalLayoutCourseButtons;
    QPushButton *buttonAddCourse;
    QLineEdit *addCourseId;
    QPushButton *buttonRemoveCourse;
    QLineEdit *deleteCOURSEid;
    QWidget *tabCourseManagement;
    QVBoxLayout *verticalLayoutCourseManagement;
    QFormLayout *formLayoutCourseDetails;
    QLabel *courseIDLabel;
    QLineEdit *courseIDLineEdit;
    QLabel *courseNameLabel;
    QLineEdit *courseNameLineEdit;
    QLabel *teacherIDLabel;
    QLineEdit *teacherIDLineEdit;
    QHBoxLayout *horizontalLayoutCourseActions;
    QPushButton *addCourseButton;
    QPushButton *updateCourseButton;
    QPushButton *deleteCourseButton;
    QPushButton *viewCoursesButton;
    QTableView *courseTableView;
    QWidget *tabGenerateReports;
    QVBoxLayout *verticalLayoutReports;
    QFormLayout *formLayoutSelection;
    QLabel *labelSelectStudentOrCourse;
    QComboBox *comboBoxSelection;
    QPushButton *buttonGenerateReport;
    QTextEdit *reportDisplayTextEdit;

    void setupUi(QWidget *SystemUi__AdminForm)
    {
        if (SystemUi__AdminForm->objectName().isEmpty())
            SystemUi__AdminForm->setObjectName("SystemUi__AdminForm");
        SystemUi__AdminForm->resize(743, 601);
        verticalLayout = new QVBoxLayout(SystemUi__AdminForm);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(SystemUi__AdminForm);
        tabWidget->setObjectName("tabWidget");
        tabStudent = new QWidget();
        tabStudent->setObjectName("tabStudent");
        verticalLayoutStudent = new QVBoxLayout(tabStudent);
        verticalLayoutStudent->setObjectName("verticalLayoutStudent");
        formLayoutStudent = new QFormLayout();
        formLayoutStudent->setObjectName("formLayoutStudent");
        labelName = new QLabel(tabStudent);
        labelName->setObjectName("labelName");

        formLayoutStudent->setWidget(0, QFormLayout::LabelRole, labelName);

        lineEditName = new QLineEdit(tabStudent);
        lineEditName->setObjectName("lineEditName");

        formLayoutStudent->setWidget(0, QFormLayout::FieldRole, lineEditName);

        labelID = new QLabel(tabStudent);
        labelID->setObjectName("labelID");

        formLayoutStudent->setWidget(1, QFormLayout::LabelRole, labelID);

        lineEditID = new QLineEdit(tabStudent);
        lineEditID->setObjectName("lineEditID");

        formLayoutStudent->setWidget(1, QFormLayout::FieldRole, lineEditID);

        labelEmail = new QLabel(tabStudent);
        labelEmail->setObjectName("labelEmail");

        formLayoutStudent->setWidget(2, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(tabStudent);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayoutStudent->setWidget(2, QFormLayout::FieldRole, lineEditEmail);

        labelPhone = new QLabel(tabStudent);
        labelPhone->setObjectName("labelPhone");

        formLayoutStudent->setWidget(3, QFormLayout::LabelRole, labelPhone);

        lineEditPhone = new QLineEdit(tabStudent);
        lineEditPhone->setObjectName("lineEditPhone");

        formLayoutStudent->setWidget(3, QFormLayout::FieldRole, lineEditPhone);


        verticalLayoutStudent->addLayout(formLayoutStudent);

        buttonSaveStudent = new QPushButton(tabStudent);
        buttonSaveStudent->setObjectName("buttonSaveStudent");

        verticalLayoutStudent->addWidget(buttonSaveStudent);

        QueryStudent = new QPushButton(tabStudent);
        QueryStudent->setObjectName("QueryStudent");

        verticalLayoutStudent->addWidget(QueryStudent);

        UpdateStudent = new QPushButton(tabStudent);
        UpdateStudent->setObjectName("UpdateStudent");

        verticalLayoutStudent->addWidget(UpdateStudent);

        deleteStudent = new QPushButton(tabStudent);
        deleteStudent->setObjectName("deleteStudent");

        verticalLayoutStudent->addWidget(deleteStudent);

        horizontalLayoutCourses = new QHBoxLayout();
        horizontalLayoutCourses->setObjectName("horizontalLayoutCourses");
        tableWidgetCourses = new QTableWidget(tabStudent);
        if (tableWidgetCourses->columnCount() < 4)
            tableWidgetCourses->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetCourses->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetCourses->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetCourses->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetCourses->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetCourses->setObjectName("tableWidgetCourses");

        horizontalLayoutCourses->addWidget(tableWidgetCourses);

        verticalLayoutCourseButtons = new QVBoxLayout();
        verticalLayoutCourseButtons->setObjectName("verticalLayoutCourseButtons");
        buttonAddCourse = new QPushButton(tabStudent);
        buttonAddCourse->setObjectName("buttonAddCourse");

        verticalLayoutCourseButtons->addWidget(buttonAddCourse);

        addCourseId = new QLineEdit(tabStudent);
        addCourseId->setObjectName("addCourseId");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addCourseId->sizePolicy().hasHeightForWidth());
        addCourseId->setSizePolicy(sizePolicy);

        verticalLayoutCourseButtons->addWidget(addCourseId);

        buttonRemoveCourse = new QPushButton(tabStudent);
        buttonRemoveCourse->setObjectName("buttonRemoveCourse");

        verticalLayoutCourseButtons->addWidget(buttonRemoveCourse);

        deleteCOURSEid = new QLineEdit(tabStudent);
        deleteCOURSEid->setObjectName("deleteCOURSEid");
        sizePolicy.setHeightForWidth(deleteCOURSEid->sizePolicy().hasHeightForWidth());
        deleteCOURSEid->setSizePolicy(sizePolicy);

        verticalLayoutCourseButtons->addWidget(deleteCOURSEid);


        horizontalLayoutCourses->addLayout(verticalLayoutCourseButtons);


        verticalLayoutStudent->addLayout(horizontalLayoutCourses);

        tabWidget->addTab(tabStudent, QString());
        tabCourseManagement = new QWidget();
        tabCourseManagement->setObjectName("tabCourseManagement");
        verticalLayoutCourseManagement = new QVBoxLayout(tabCourseManagement);
        verticalLayoutCourseManagement->setObjectName("verticalLayoutCourseManagement");
        formLayoutCourseDetails = new QFormLayout();
        formLayoutCourseDetails->setObjectName("formLayoutCourseDetails");
        courseIDLabel = new QLabel(tabCourseManagement);
        courseIDLabel->setObjectName("courseIDLabel");

        formLayoutCourseDetails->setWidget(0, QFormLayout::LabelRole, courseIDLabel);

        courseIDLineEdit = new QLineEdit(tabCourseManagement);
        courseIDLineEdit->setObjectName("courseIDLineEdit");

        formLayoutCourseDetails->setWidget(0, QFormLayout::FieldRole, courseIDLineEdit);

        courseNameLabel = new QLabel(tabCourseManagement);
        courseNameLabel->setObjectName("courseNameLabel");

        formLayoutCourseDetails->setWidget(1, QFormLayout::LabelRole, courseNameLabel);

        courseNameLineEdit = new QLineEdit(tabCourseManagement);
        courseNameLineEdit->setObjectName("courseNameLineEdit");

        formLayoutCourseDetails->setWidget(1, QFormLayout::FieldRole, courseNameLineEdit);

        teacherIDLabel = new QLabel(tabCourseManagement);
        teacherIDLabel->setObjectName("teacherIDLabel");

        formLayoutCourseDetails->setWidget(2, QFormLayout::LabelRole, teacherIDLabel);

        teacherIDLineEdit = new QLineEdit(tabCourseManagement);
        teacherIDLineEdit->setObjectName("teacherIDLineEdit");

        formLayoutCourseDetails->setWidget(2, QFormLayout::FieldRole, teacherIDLineEdit);


        verticalLayoutCourseManagement->addLayout(formLayoutCourseDetails);

        horizontalLayoutCourseActions = new QHBoxLayout();
        horizontalLayoutCourseActions->setObjectName("horizontalLayoutCourseActions");
        addCourseButton = new QPushButton(tabCourseManagement);
        addCourseButton->setObjectName("addCourseButton");

        horizontalLayoutCourseActions->addWidget(addCourseButton);

        updateCourseButton = new QPushButton(tabCourseManagement);
        updateCourseButton->setObjectName("updateCourseButton");

        horizontalLayoutCourseActions->addWidget(updateCourseButton);

        deleteCourseButton = new QPushButton(tabCourseManagement);
        deleteCourseButton->setObjectName("deleteCourseButton");

        horizontalLayoutCourseActions->addWidget(deleteCourseButton);

        viewCoursesButton = new QPushButton(tabCourseManagement);
        viewCoursesButton->setObjectName("viewCoursesButton");

        horizontalLayoutCourseActions->addWidget(viewCoursesButton);


        verticalLayoutCourseManagement->addLayout(horizontalLayoutCourseActions);

        courseTableView = new QTableView(tabCourseManagement);
        courseTableView->setObjectName("courseTableView");

        verticalLayoutCourseManagement->addWidget(courseTableView);

        tabWidget->addTab(tabCourseManagement, QString());
        tabGenerateReports = new QWidget();
        tabGenerateReports->setObjectName("tabGenerateReports");
        verticalLayoutReports = new QVBoxLayout(tabGenerateReports);
        verticalLayoutReports->setObjectName("verticalLayoutReports");
        formLayoutSelection = new QFormLayout();
        formLayoutSelection->setObjectName("formLayoutSelection");
        labelSelectStudentOrCourse = new QLabel(tabGenerateReports);
        labelSelectStudentOrCourse->setObjectName("labelSelectStudentOrCourse");

        formLayoutSelection->setWidget(0, QFormLayout::LabelRole, labelSelectStudentOrCourse);

        comboBoxSelection = new QComboBox(tabGenerateReports);
        comboBoxSelection->setObjectName("comboBoxSelection");

        formLayoutSelection->setWidget(0, QFormLayout::FieldRole, comboBoxSelection);


        verticalLayoutReports->addLayout(formLayoutSelection);

        buttonGenerateReport = new QPushButton(tabGenerateReports);
        buttonGenerateReport->setObjectName("buttonGenerateReport");

        verticalLayoutReports->addWidget(buttonGenerateReport);

        reportDisplayTextEdit = new QTextEdit(tabGenerateReports);
        reportDisplayTextEdit->setObjectName("reportDisplayTextEdit");
        reportDisplayTextEdit->setReadOnly(true);

        verticalLayoutReports->addWidget(reportDisplayTextEdit);

        tabWidget->addTab(tabGenerateReports, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(SystemUi__AdminForm);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SystemUi__AdminForm);
    } // setupUi

    void retranslateUi(QWidget *SystemUi__AdminForm)
    {
        labelName->setText(QCoreApplication::translate("SystemUi::AdminForm", "Student Name:", nullptr));
        labelID->setText(QCoreApplication::translate("SystemUi::AdminForm", "Student ID:", nullptr));
        labelEmail->setText(QCoreApplication::translate("SystemUi::AdminForm", "Email:", nullptr));
        labelPhone->setText(QCoreApplication::translate("SystemUi::AdminForm", "Phone Number:", nullptr));
        buttonSaveStudent->setText(QCoreApplication::translate("SystemUi::AdminForm", "Save Student", nullptr));
        QueryStudent->setText(QCoreApplication::translate("SystemUi::AdminForm", "Query Student", nullptr));
        UpdateStudent->setText(QCoreApplication::translate("SystemUi::AdminForm", "Update Student", nullptr));
        deleteStudent->setText(QCoreApplication::translate("SystemUi::AdminForm", "Delete Student", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetCourses->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SystemUi::AdminForm", "\350\257\276\347\250\213ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetCourses->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SystemUi::AdminForm", "\350\257\276\347\250\213\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetCourses->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SystemUi::AdminForm", "\344\273\273\350\257\276\346\225\231\345\270\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetCourses->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SystemUi::AdminForm", "\350\257\276\347\250\213\346\210\220\347\273\251", nullptr));
#if QT_CONFIG(tooltip)
        tableWidgetCourses->setToolTip(QCoreApplication::translate("SystemUi::AdminForm", "Student's Courses", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonAddCourse->setText(QCoreApplication::translate("SystemUi::AdminForm", "Add Course", nullptr));
        buttonRemoveCourse->setText(QCoreApplication::translate("SystemUi::AdminForm", "Remove Course", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStudent), QCoreApplication::translate("SystemUi::AdminForm", "Students", nullptr));
        courseIDLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "Course ID:", nullptr));
        courseNameLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "Course Name:", nullptr));
        teacherIDLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "Teacher ID:", nullptr));
        addCourseButton->setText(QCoreApplication::translate("SystemUi::AdminForm", "Add Course", nullptr));
        updateCourseButton->setText(QCoreApplication::translate("SystemUi::AdminForm", "Update Course", nullptr));
        deleteCourseButton->setText(QCoreApplication::translate("SystemUi::AdminForm", "Delete Course", nullptr));
        viewCoursesButton->setText(QCoreApplication::translate("SystemUi::AdminForm", "View Courses", nullptr));
#if QT_CONFIG(tooltip)
        courseTableView->setToolTip(QCoreApplication::translate("SystemUi::AdminForm", "Full List of Courses", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tabCourseManagement), QCoreApplication::translate("SystemUi::AdminForm", "Course Management", nullptr));
        labelSelectStudentOrCourse->setText(QCoreApplication::translate("SystemUi::AdminForm", "Select a student or course:", nullptr));
#if QT_CONFIG(tooltip)
        comboBoxSelection->setToolTip(QCoreApplication::translate("SystemUi::AdminForm", "Choose a student ID or course ID to generate a report", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonGenerateReport->setText(QCoreApplication::translate("SystemUi::AdminForm", "Generate Report", nullptr));
        reportDisplayTextEdit->setPlaceholderText(QCoreApplication::translate("SystemUi::AdminForm", "The generated report will be displayed here.", nullptr));
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
