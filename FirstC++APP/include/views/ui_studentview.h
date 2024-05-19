//
// Created by Lenovo on 24-5-18.
//

#ifndef FIRSTC__APP_UI_STUDENTVIEW_H
#define FIRSTC__APP_UI_STUDENTVIEW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class StudentView; }
QT_END_NAMESPACE

class StudentView : public QWidget {
Q_OBJECT

public:
    explicit StudentView(QWidget *parent = nullptr);

    ~StudentView() override;

private:
    StudentView *ui;
};


#endif //FIRSTC__APP_UI_STUDENTVIEW_H
