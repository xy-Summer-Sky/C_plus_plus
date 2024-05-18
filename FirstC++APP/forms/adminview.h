//
// Created by Lenovo on 24-5-18.
//

#ifndef FIRSTC__APP_ADMINVIEW_H
#define FIRSTC__APP_ADMINVIEW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class adminview; }
QT_END_NAMESPACE

class adminview : public QWidget {
Q_OBJECT

public:
    explicit adminview(QWidget *parent = nullptr);

    ~adminview() override;

private:
    Ui::adminview *ui;
};


#endif //FIRSTC__APP_ADMINVIEW_H
