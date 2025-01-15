//
// Created by Lenovo on 24-7-15.
//

#ifndef NUMBERSTRING_CONVERT_H
#define NUMBERSTRING_CONVERT_H

#include <QWidget>
#include<stack>

QT_BEGIN_NAMESPACE
namespace Ui { class Convert; }
QT_END_NAMESPACE

class Convert : public QWidget {
Q_OBJECT

public:
    explicit Convert(QWidget *parent = nullptr);

    ~Convert() override;

public slots:
    void convertAndDisplay();


private:
    Ui::Convert *ui;

    QString numberToTraditionalChinese(const QString& qString);
};


#endif //NUMBERSTRING_CONVERT_H
