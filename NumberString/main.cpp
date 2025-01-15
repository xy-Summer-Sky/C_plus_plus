#include <QApplication>
#include <QPushButton>
#include "ui/convert.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Convert convertWindow; // Create an instance of Convert
    convertWindow.show(); // Show the Convert window

    return QApplication::exec(); // Execute the application
    return QApplication::exec();
}
