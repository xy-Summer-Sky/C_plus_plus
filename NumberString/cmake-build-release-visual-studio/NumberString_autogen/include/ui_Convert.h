/********************************************************************************
** Form generated from reading UI file 'convert.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERT_H
#define UI_CONVERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Convert
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *inputLayout;
    QLabel *labelBefore;
    QLineEdit *lineEdit;
    QComboBox *comboBoxSymbol;
    QLineEdit *lineEditNumber;
    QLabel *labelAfter;
    QLineEdit *lineEdit_2;
    QHBoxLayout *outputLayout;
    QLabel *outputLabel;
    QLineEdit *outputLineEdit;

    void setupUi(QWidget *Convert)
    {
        if (Convert->objectName().isEmpty())
            Convert->setObjectName("Convert");
        Convert->resize(600, 78);
        mainLayout = new QVBoxLayout(Convert);
        mainLayout->setObjectName("mainLayout");
        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName("inputLayout");
        labelBefore = new QLabel(Convert);
        labelBefore->setObjectName("labelBefore");

        inputLayout->addWidget(labelBefore);

        lineEdit = new QLineEdit(Convert);
        lineEdit->setObjectName("lineEdit");

        inputLayout->addWidget(lineEdit);

        comboBoxSymbol = new QComboBox(Convert);
        comboBoxSymbol->addItem(QString());
        comboBoxSymbol->setObjectName("comboBoxSymbol");

        inputLayout->addWidget(comboBoxSymbol);

        lineEditNumber = new QLineEdit(Convert);
        lineEditNumber->setObjectName("lineEditNumber");

        inputLayout->addWidget(lineEditNumber);

        labelAfter = new QLabel(Convert);
        labelAfter->setObjectName("labelAfter");

        inputLayout->addWidget(labelAfter);

        lineEdit_2 = new QLineEdit(Convert);
        lineEdit_2->setObjectName("lineEdit_2");

        inputLayout->addWidget(lineEdit_2);


        mainLayout->addLayout(inputLayout);

        outputLayout = new QHBoxLayout();
        outputLayout->setObjectName("outputLayout");
        outputLabel = new QLabel(Convert);
        outputLabel->setObjectName("outputLabel");

        outputLayout->addWidget(outputLabel);

        outputLineEdit = new QLineEdit(Convert);
        outputLineEdit->setObjectName("outputLineEdit");
        outputLineEdit->setReadOnly(true);

        outputLayout->addWidget(outputLineEdit);


        mainLayout->addLayout(outputLayout);


        retranslateUi(Convert);

        QMetaObject::connectSlotsByName(Convert);
    } // setupUi

    void retranslateUi(QWidget *Convert)
    {
        Convert->setWindowTitle(QCoreApplication::translate("Convert", "Convert", nullptr));
        labelBefore->setText(QCoreApplication::translate("Convert", "\346\261\211\345\255\227", nullptr));
        comboBoxSymbol->setItemText(0, QCoreApplication::translate("Convert", "+", nullptr));

        lineEditNumber->setPlaceholderText(QCoreApplication::translate("Convert", "\350\276\223\345\205\245\346\225\260\345\255\227", nullptr));
        labelAfter->setText(QCoreApplication::translate("Convert", "\346\261\211\345\255\227", nullptr));
        outputLabel->setText(QCoreApplication::translate("Convert", "\350\276\223\345\207\272\347\273\223\346\236\234\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Convert: public Ui_Convert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERT_H
