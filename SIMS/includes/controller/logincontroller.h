// Last modified: 2021.04.10 01:00:00
#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include "dbmanager.h"
#include "studentform.h"
#include <string>
#include <QObject>
#include <QString>

namespace Controller {

    class LoginController :public QObject{
        Q_OBJECT

    public:

    public:
        LoginController();

        ~LoginController() override;

        bool validateUser(const std::string &userId, const std::string &password, const std::string &userType);


    signals:
        void userValidated(const std::string &userId);
        void errorOccured(const QString &message);
        void operationSuccess(const QString &successMessage);


    private:
        static MYDB::DbManager *m_db;

    };

}

#endif
