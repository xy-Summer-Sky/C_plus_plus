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
    QTableView *tableViewCourses;
    QVBoxLayout *verticalLayoutCourseButtons;
    QPushButton *buttonAddCourse;
    QLineEdit *addCourseId;
    QPushButton *buttonRemoveCourse;
    QLineEdit *deleteCOURSEid;
    QPushButton *ScoreButton;
    QFormLayout *ScoreFormLayout;
    QLabel *courseIDLabelScore;
    QLineEdit *courseIDLineEditScore;
    QLabel *studentIDLabelScore;
    QLineEdit *studentIDLineEditScore;
    QLabel *scoreLabel;
    QLineEdit *scoreLineEdit;
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
    QWidget *tabAccountsManagement;
    QVBoxLayout *verticalLayoutReports;
    QFormLayout *formLayoutSelection;
    QLabel *labelUserType;
    QComboBox *UserType;
    QLabel *useridLabel;
    QLineEdit *useridLineEdit;
    QLabel *passwordLabel_2;
    QLineEdit *passwordLineEditAccountManagement;
    QPushButton *buttonUpdateAccount;
    QPushButton *buttonDeleteAccount;
    QPushButton *buttonAddAccount;
    QPushButton *buttonQueryAccount;
    QPushButton *buttonListAllAccount;
    QTableView *AccountList;
    QWidget *tabTeacher;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *teacherNameLabel;
    QLineEdit *teacherNameLineEdit;
    QLabel *teacherIdLabel;
    QLineEdit *teacherIdLineEdit;
    QLabel *teacherEmailLabel;
    QLineEdit *teacherEmailLineEdit;
    QLabel *teacherPhoneNumberLabel;
    QLineEdit *teacherPhoneNumberLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonAddTeacher;
    QPushButton *ButtonDeleteTeacher;
    QPushButton *ButtonUpdateTeacher;
    QPushButton *ButtonQueryTeacher;
    QPushButton *ListAllTeachers;
    QTableView *TeachersTableView;

    void setupUi(QWidget *SystemUi__AdminForm)
    {
        if (SystemUi__AdminForm->objectName().isEmpty())
            SystemUi__AdminForm->setObjectName("SystemUi__AdminForm");
        SystemUi__AdminForm->resize(904, 702);
        verticalLayout = new QVBoxLayout(SystemUi__AdminForm);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(SystemUi__AdminForm);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabBarAutoHide(true);
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
        tableViewCourses = new QTableView(tabStudent);
        tableViewCourses->setObjectName("tableViewCourses");

        horizontalLayoutCourses->addWidget(tableViewCourses);

        verticalLayoutCourseButtons = new QVBoxLayout();
        verticalLayoutCourseButtons->setObjectName("verticalLayoutCourseButtons");
        buttonAddCourse = new QPushButton(tabStudent);
        buttonAddCourse->setObjectName("buttonAddCourse");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonAddCourse->sizePolicy().hasHeightForWidth());
        buttonAddCourse->setSizePolicy(sizePolicy);

        verticalLayoutCourseButtons->addWidget(buttonAddCourse);

        addCourseId = new QLineEdit(tabStudent);
        addCourseId->setObjectName("addCourseId");
        sizePolicy.setHeightForWidth(addCourseId->sizePolicy().hasHeightForWidth());
        addCourseId->setSizePolicy(sizePolicy);

        verticalLayoutCourseButtons->addWidget(addCourseId);

        buttonRemoveCourse = new QPushButton(tabStudent);
        buttonRemoveCourse->setObjectName("buttonRemoveCourse");
        sizePolicy.setHeightForWidth(buttonRemoveCourse->sizePolicy().hasHeightForWidth());
        buttonRemoveCourse->setSizePolicy(sizePolicy);

        verticalLayoutCourseButtons->addWidget(buttonRemoveCourse);

        deleteCOURSEid = new QLineEdit(tabStudent);
        deleteCOURSEid->setObjectName("deleteCOURSEid");
        sizePolicy.setHeightForWidth(deleteCOURSEid->sizePolicy().hasHeightForWidth());
        deleteCOURSEid->setSizePolicy(sizePolicy);

        verticalLayoutCourseButtons->addWidget(deleteCOURSEid);

        ScoreButton = new QPushButton(tabStudent);
        ScoreButton->setObjectName("ScoreButton");
        sizePolicy.setHeightForWidth(ScoreButton->sizePolicy().hasHeightForWidth());
        ScoreButton->setSizePolicy(sizePolicy);
        ScoreButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        verticalLayoutCourseButtons->addWidget(ScoreButton);

        ScoreFormLayout = new QFormLayout();
        ScoreFormLayout->setObjectName("ScoreFormLayout");
        courseIDLabelScore = new QLabel(tabStudent);
        courseIDLabelScore->setObjectName("courseIDLabelScore");

        ScoreFormLayout->setWidget(0, QFormLayout::LabelRole, courseIDLabelScore);

        courseIDLineEditScore = new QLineEdit(tabStudent);
        courseIDLineEditScore->setObjectName("courseIDLineEditScore");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(courseIDLineEditScore->sizePolicy().hasHeightForWidth());
        courseIDLineEditScore->setSizePolicy(sizePolicy1);

        ScoreFormLayout->setWidget(0, QFormLayout::FieldRole, courseIDLineEditScore);

        studentIDLabelScore = new QLabel(tabStudent);
        studentIDLabelScore->setObjectName("studentIDLabelScore");

        ScoreFormLayout->setWidget(1, QFormLayout::LabelRole, studentIDLabelScore);

        studentIDLineEditScore = new QLineEdit(tabStudent);
        studentIDLineEditScore->setObjectName("studentIDLineEditScore");
        sizePolicy1.setHeightForWidth(studentIDLineEditScore->sizePolicy().hasHeightForWidth());
        studentIDLineEditScore->setSizePolicy(sizePolicy1);

        ScoreFormLayout->setWidget(1, QFormLayout::FieldRole, studentIDLineEditScore);

        scoreLabel = new QLabel(tabStudent);
        scoreLabel->setObjectName("scoreLabel");

        ScoreFormLayout->setWidget(2, QFormLayout::LabelRole, scoreLabel);

        scoreLineEdit = new QLineEdit(tabStudent);
        scoreLineEdit->setObjectName("scoreLineEdit");
        sizePolicy1.setHeightForWidth(scoreLineEdit->sizePolicy().hasHeightForWidth());
        scoreLineEdit->setSizePolicy(sizePolicy1);

        ScoreFormLayout->setWidget(2, QFormLayout::FieldRole, scoreLineEdit);


        verticalLayoutCourseButtons->addLayout(ScoreFormLayout);


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
        tabAccountsManagement = new QWidget();
        tabAccountsManagement->setObjectName("tabAccountsManagement");
        verticalLayoutReports = new QVBoxLayout(tabAccountsManagement);
        verticalLayoutReports->setObjectName("verticalLayoutReports");
        formLayoutSelection = new QFormLayout();
        formLayoutSelection->setObjectName("formLayoutSelection");
        labelUserType = new QLabel(tabAccountsManagement);
        labelUserType->setObjectName("labelUserType");

        formLayoutSelection->setWidget(2, QFormLayout::LabelRole, labelUserType);

        UserType = new QComboBox(tabAccountsManagement);
        UserType->addItem(QString());
        UserType->addItem(QString());
        UserType->addItem(QString());
        UserType->setObjectName("UserType");

        formLayoutSelection->setWidget(2, QFormLayout::FieldRole, UserType);

        useridLabel = new QLabel(tabAccountsManagement);
        useridLabel->setObjectName("useridLabel");

        formLayoutSelection->setWidget(0, QFormLayout::LabelRole, useridLabel);

        useridLineEdit = new QLineEdit(tabAccountsManagement);
        useridLineEdit->setObjectName("useridLineEdit");

        formLayoutSelection->setWidget(0, QFormLayout::FieldRole, useridLineEdit);

        passwordLabel_2 = new QLabel(tabAccountsManagement);
        passwordLabel_2->setObjectName("passwordLabel_2");

        formLayoutSelection->setWidget(1, QFormLayout::LabelRole, passwordLabel_2);

        passwordLineEditAccountManagement = new QLineEdit(tabAccountsManagement);
        passwordLineEditAccountManagement->setObjectName("passwordLineEditAccountManagement");

        formLayoutSelection->setWidget(1, QFormLayout::FieldRole, passwordLineEditAccountManagement);


        verticalLayoutReports->addLayout(formLayoutSelection);

        buttonUpdateAccount = new QPushButton(tabAccountsManagement);
        buttonUpdateAccount->setObjectName("buttonUpdateAccount");

        verticalLayoutReports->addWidget(buttonUpdateAccount);

        buttonDeleteAccount = new QPushButton(tabAccountsManagement);
        buttonDeleteAccount->setObjectName("buttonDeleteAccount");

        verticalLayoutReports->addWidget(buttonDeleteAccount);

        buttonAddAccount = new QPushButton(tabAccountsManagement);
        buttonAddAccount->setObjectName("buttonAddAccount");

        verticalLayoutReports->addWidget(buttonAddAccount);

        buttonQueryAccount = new QPushButton(tabAccountsManagement);
        buttonQueryAccount->setObjectName("buttonQueryAccount");

        verticalLayoutReports->addWidget(buttonQueryAccount);

        buttonListAllAccount = new QPushButton(tabAccountsManagement);
        buttonListAllAccount->setObjectName("buttonListAllAccount");

        verticalLayoutReports->addWidget(buttonListAllAccount);

        AccountList = new QTableView(tabAccountsManagement);
        AccountList->setObjectName("AccountList");

        verticalLayoutReports->addWidget(AccountList);

        tabWidget->addTab(tabAccountsManagement, QString());
        tabTeacher = new QWidget();
        tabTeacher->setObjectName("tabTeacher");
        tabTeacher->setEnabled(true);
        tabTeacher->setMouseTracking(false);
        tabTeacher->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(tabTeacher);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        teacherNameLabel = new QLabel(tabTeacher);
        teacherNameLabel->setObjectName("teacherNameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, teacherNameLabel);

        teacherNameLineEdit = new QLineEdit(tabTeacher);
        teacherNameLineEdit->setObjectName("teacherNameLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, teacherNameLineEdit);

        teacherIdLabel = new QLabel(tabTeacher);
        teacherIdLabel->setObjectName("teacherIdLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, teacherIdLabel);

        teacherIdLineEdit = new QLineEdit(tabTeacher);
        teacherIdLineEdit->setObjectName("teacherIdLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, teacherIdLineEdit);

        teacherEmailLabel = new QLabel(tabTeacher);
        teacherEmailLabel->setObjectName("teacherEmailLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, teacherEmailLabel);

        teacherEmailLineEdit = new QLineEdit(tabTeacher);
        teacherEmailLineEdit->setObjectName("teacherEmailLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, teacherEmailLineEdit);

        teacherPhoneNumberLabel = new QLabel(tabTeacher);
        teacherPhoneNumberLabel->setObjectName("teacherPhoneNumberLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, teacherPhoneNumberLabel);

        teacherPhoneNumberLineEdit = new QLineEdit(tabTeacher);
        teacherPhoneNumberLineEdit->setObjectName("teacherPhoneNumberLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, teacherPhoneNumberLineEdit);


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        ButtonAddTeacher = new QPushButton(tabTeacher);
        ButtonAddTeacher->setObjectName("ButtonAddTeacher");

        horizontalLayout->addWidget(ButtonAddTeacher);

        ButtonDeleteTeacher = new QPushButton(tabTeacher);
        ButtonDeleteTeacher->setObjectName("ButtonDeleteTeacher");

        horizontalLayout->addWidget(ButtonDeleteTeacher);

        ButtonUpdateTeacher = new QPushButton(tabTeacher);
        ButtonUpdateTeacher->setObjectName("ButtonUpdateTeacher");

        horizontalLayout->addWidget(ButtonUpdateTeacher);

        ButtonQueryTeacher = new QPushButton(tabTeacher);
        ButtonQueryTeacher->setObjectName("ButtonQueryTeacher");

        horizontalLayout->addWidget(ButtonQueryTeacher);


        verticalLayout_2->addLayout(horizontalLayout);

        ListAllTeachers = new QPushButton(tabTeacher);
        ListAllTeachers->setObjectName("ListAllTeachers");

        verticalLayout_2->addWidget(ListAllTeachers);

        TeachersTableView = new QTableView(tabTeacher);
        TeachersTableView->setObjectName("TeachersTableView");

        verticalLayout_2->addWidget(TeachersTableView);

        tabWidget->addTab(tabTeacher, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(SystemUi__AdminForm);

        tabWidget->setCurrentIndex(0);


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
#if QT_CONFIG(tooltip)
        tableViewCourses->setToolTip(QCoreApplication::translate("SystemUi::AdminForm", "Student's Courses", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonAddCourse->setText(QCoreApplication::translate("SystemUi::AdminForm", "Add Course", nullptr));
        buttonRemoveCourse->setText(QCoreApplication::translate("SystemUi::AdminForm", "Remove Course", nullptr));
        ScoreButton->setText(QCoreApplication::translate("SystemUi::AdminForm", "Score", nullptr));
        courseIDLabelScore->setText(QCoreApplication::translate("SystemUi::AdminForm", "courseID", nullptr));
        studentIDLabelScore->setText(QCoreApplication::translate("SystemUi::AdminForm", "studentID", nullptr));
        scoreLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "Score", nullptr));
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
        labelUserType->setText(QCoreApplication::translate("SystemUi::AdminForm", "UserType", nullptr));
        UserType->setItemText(0, QCoreApplication::translate("SystemUi::AdminForm", "admin", nullptr));
        UserType->setItemText(1, QCoreApplication::translate("SystemUi::AdminForm", "student", nullptr));
        UserType->setItemText(2, QCoreApplication::translate("SystemUi::AdminForm", "teacher", nullptr));

#if QT_CONFIG(tooltip)
        UserType->setToolTip(QCoreApplication::translate("SystemUi::AdminForm", "Choose a student ID or course ID to generate a report", nullptr));
#endif // QT_CONFIG(tooltip)
        useridLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "UserID", nullptr));
        passwordLabel_2->setText(QCoreApplication::translate("SystemUi::AdminForm", "Password", nullptr));
        buttonUpdateAccount->setText(QCoreApplication::translate("SystemUi::AdminForm", "UpdateAccount", nullptr));
        buttonDeleteAccount->setText(QCoreApplication::translate("SystemUi::AdminForm", "DeleteButton", nullptr));
        buttonAddAccount->setText(QCoreApplication::translate("SystemUi::AdminForm", "AddAccount", nullptr));
        buttonQueryAccount->setText(QCoreApplication::translate("SystemUi::AdminForm", "QueryAccount", nullptr));
        buttonListAllAccount->setText(QCoreApplication::translate("SystemUi::AdminForm", "ListAllAccount", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAccountsManagement), QCoreApplication::translate("SystemUi::AdminForm", "AccountsManagement", nullptr));
        teacherNameLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "TeacherName", nullptr));
        teacherIdLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "TeacherId", nullptr));
        teacherEmailLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "TeacherEmail", nullptr));
        teacherPhoneNumberLabel->setText(QCoreApplication::translate("SystemUi::AdminForm", "TeacherPhoneNumber", nullptr));
        ButtonAddTeacher->setText(QCoreApplication::translate("SystemUi::AdminForm", "AddTeacher", nullptr));
        ButtonDeleteTeacher->setText(QCoreApplication::translate("SystemUi::AdminForm", "DeleteTeacher", nullptr));
        ButtonUpdateTeacher->setText(QCoreApplication::translate("SystemUi::AdminForm", "UpdateTeacher", nullptr));
        ButtonQueryTeacher->setText(QCoreApplication::translate("SystemUi::AdminForm", "QueryTeacher", nullptr));
        ListAllTeachers->setText(QCoreApplication::translate("SystemUi::AdminForm", "AllTeachers", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTeacher), QCoreApplication::translate("SystemUi::AdminForm", "Teachers", nullptr));
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
