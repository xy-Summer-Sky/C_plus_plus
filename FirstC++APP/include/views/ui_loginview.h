//
// Created by Lenovo on 24-5-18.
//

#ifndef FIRSTC__APP_UI_LOGINVIEW_H
#define FIRSTC__APP_UI_LOGINVIEW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ui_loginview; }
QT_END_NAMESPACE

class loginview : public QWidget {
Q_OBJECT

public:
    explicit loginview(QWidget *parent = nullptr);

    ~loginview() override;

private:
    Ui::ui_loginview *ui;
};


#endif //FIRSTC__APP_UI_LOGINVIEW_H
