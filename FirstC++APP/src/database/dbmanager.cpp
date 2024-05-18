//
// Created by Lenovo on 24-5-18.
//
// dbmanager.cpp
#include "dbmanager.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

DBManager::DBManager(const QString& path) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("student_info_system");
    db.setUserName("your_username");
    db.setPassword("your_password");
    if (!db.open()) {
        qDebug() << "Error: Connection with database fail";
    } else {
        qDebug() << "Database: connection ok";
    }
}
