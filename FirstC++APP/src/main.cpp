#include <QApplication>
#include <QPushButton>

//int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
//    return QApplication::exec();
//}
// src/main.cpp
#include <QApplication>
#include "views/studentview.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StudentView studentView;
    studentView.show();

    return app.exec();
}
