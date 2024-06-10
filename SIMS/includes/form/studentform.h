//
// Created by Lenovo on 24-5-24.
//

#ifndef SIMS_STUDENTFORM_H
#define SIMS_STUDENTFORM_H

#include <QWidget>
#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include "studentViewController.h"
#include "student.h"
#include "course.h"
#include "logincontroller.h"
#include<vector>

namespace Controller {
    class studentViewController;
    class LoginController;
}
namespace SystemUi {
    QT_BEGIN_NAMESPACE
    namespace Ui { class StudentForm; }
    QT_END_NAMESPACE

    class StudentForm : public QWidget {
    Q_OBJECT

    public:
        explicit StudentForm(QWidget *parent = nullptr);

        ~StudentForm() override;

        void displayStudentInfo(const std::string &studentId) ;


    private:
        Ui::StudentForm *ui;
        Controller::studentViewController *controller;
        Model::StudentDTO *student{};
        std::vector<Model::Course> *course{};
        Controller::LoginController * loginController;

    public
        slots:
        void onUserValidated(const std::string &userId);
        // Display error/success message
        void displayError(const QString& errorMessage);
        void displaySuccessMessage(const QString& successMessage);
    };
} // SystemUi

#endif //SIMS_STUDENTFORM_H
