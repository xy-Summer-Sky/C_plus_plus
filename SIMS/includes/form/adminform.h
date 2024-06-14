//
// Created by Lenovo on 24-5-24.
//

#ifndef SIMS_ADMINFORM_H
#define SIMS_ADMINFORM_H

#include <QWidget>
#include <QPushButton>
#include <QStandardItemModel>
#include <QComboBox>
#include "dbmanager.h"
#include "admincontroller.h"

namespace SystemUi {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AdminForm; }
    QT_END_NAMESPACE

    class AdminForm : public QWidget {
    Q_OBJECT

    public:
        explicit AdminForm(QWidget *parent = nullptr);

        ~AdminForm() override;
    public slots:
        // Student operations
        void onSaveStudent();
        void onQueryStudent();
        void onDeleteStudent();
        void onUpdateStudent();
        void displayAllStudentInfo();
        void onAddCourseToStudent();
        void onRemoveCourseFromStudent();
    public slots:
        // Course operations
        void onAddCourse();
        void onUpdateCourse();
        void onDeleteCourse();
        void onQueryCourse();
        void onViewCourses();
    public slots:
        // Account operations
        void onAddAccount();
        void onUpdateAccount();
        void onDeleteAccount();
        void onQueryAccount();
        void displayAccountInfo();

    public slots:
        // Teacher operations
        void onAddTeacher();
        void onUpdateTeacher();
        void onDeleteTeacher();
        void onQueryTeacher();
        void displayTeacherInfo();

    public slots:
        // Score operations
        void onUpdateScore();
    public slots:
        // Display error/success message
        void displayError(const QString& errorMessage);
        void displaySuccessMessage(const QString& successMessage);

    private:
        Ui::AdminForm *ui;
        Controller::AdminController * adminController;

    };
}

#endif //SIMS_ADMINFORM_H
