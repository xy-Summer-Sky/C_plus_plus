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
        Controller::studentViewController *controller;//学生视图控制器
        Model::StudentDTO *student{};//学生
        std::vector<Model::Course> *course{};//课程
        Controller::LoginController * loginController;

    public
        slots:
        void onUserValidated(const std::string &userId);//用户验证
        void displayError(const QString& errorMessage);//显示错误
        void displaySuccessMessage(const QString& successMessage);//显示成功信息
    };
} // SystemUi

#endif //SIMS_STUDENTFORM_H
