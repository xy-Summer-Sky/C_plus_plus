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
        void onSaveStudent();
        void onQueryStudent();
        void onDeleteStudent();
        void onUpdateStudent();
        void onAddCourseToStudent();
        void onRemoveCourseFromStudent();
        void onAddCourse();
        void onUpdateCourse();
        void onDeleteCourse();
        void onViewCourses();
    public slots:
        void onAddAccount();
        void onUpdateAccount();
        void onDeleteAccount();
        void onQueryAccount();
        void displayAccountInfo();

    public slots:
        void onAddTeacher();
        void onUpdateTeacher();
        void onDeleteTeacher();
        void onQueryTeacher();
        void displayTeacherInfo();

    public slots:
        void onUpdateScore();
        // Display error/success message
        void displayError(const QString& errorMessage);
        void displaySuccessMessage(const QString& successMessage);



    private:
        Ui::AdminForm *ui;
        Controller::AdminController * adminController;

    };
}

#endif //SIMS_ADMINFORM_H
