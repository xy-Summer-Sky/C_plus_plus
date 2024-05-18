//
// Created by Lenovo on 24-5-18.
//

#ifndef FIRSTC__APP_STUDENTVIEW_H
#define FIRSTC__APP_STUDENTVIEW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class studentview; }
QT_END_NAMESPACE

class studentview : public QWidget {
Q_OBJECT

public:
    explicit studentview(QWidget *parent = nullptr);

    ~studentview() override;

private:
    Ui::studentview *ui;
};


#endif //FIRSTC__APP_STUDENTVIEW_H
