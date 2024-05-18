//
// Created by Lenovo on 24-5-18.
//

// include/database/querymodel.h
#ifndef QUERYMODEL_H
#define QUERYMODEL_H

#include <QSqlQueryModel>

class QueryModel : public QSqlQueryModel {
public:
    explicit QueryModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;
};

#endif // QUERYMODEL_H

