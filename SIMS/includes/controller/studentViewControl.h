//
// Created by Lenovo on 24-5-24.
//

#ifndef SIMS_STUDENTVIEWCONTROL_H
#define SIMS_STUDENTVIEWCONTROL_H



#include <QObject>
#include"studentform.h"
#include "querymodel.h"
namespace SystemUi {
    class StudentForm;  // 前向声明
}

namespace Controller {
    class studentViewControl: public QObject {
    Q_OBJECT

    public:
        explicit studentViewControl(SystemUi::StudentForm *view, QObject *parent = nullptr);

    public slots:

        void requestStudentInfo();

    private:
        SystemUi::StudentForm * view;
        MYDB::QueryModel* queryModel;
    };

}



#endif //SIMS_STUDENTVIEWCONTROL_H
