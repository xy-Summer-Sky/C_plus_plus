//
// Created by Lenovo on 24-5-18.
//
// src/database/querymodel.cpp
#include "querymodel.h"

QueryModel::QueryModel(QObject *parent) : QSqlQueryModel(parent) {}

QVariant QueryModel::data(const QModelIndex &index, int role) const {
    if (role < Qt::UserRole)
        return QSqlQueryModel::data(index, role);
    else
        return QSqlQueryModel::data(this->index(index.row(), role - Qt::UserRole - 1), Qt::DisplayRole);
}
