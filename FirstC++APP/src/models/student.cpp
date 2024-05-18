//
// Created by Lenovo on 24-5-18.
//
// student.cpp
#include "student.h"
#include <QSqlQuery>
#include <QVariant>

bool Student::loadFromDB(int id) {
    QSqlQuery query;
    query.prepare("SELECT name, age FROM students WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "load student failed: " << query.lastError();
        return false;
    }
    if (query.first()) {
        name = query.value(0).toString();
        age = query.value(1).toInt();
        return true;
    }
    return false;
}

bool Student::saveToDB() {
    QSqlQuery query;
    query.prepare("UPDATE students SET name = :name, age = :age WHERE id = :id");
    query.bindValue(":name", name);
    query.bindValue(":age", age);
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "save student failed: " << query.lastError();
        return false;
    }
    return true;
}
