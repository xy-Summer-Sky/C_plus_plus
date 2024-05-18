//
// Created by Lenovo on 24-5-18.
//



#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>
class DBManager {
public:
    explicit DBManager(const QString& path);
    bool isOpen() const;  // 检查数据库是否成功打开
private:
    QSqlDatabase m_db;
};
#endif // DBMANAGER_H

