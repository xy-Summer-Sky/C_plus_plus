#include <QApplication>
#include "ui/convert.h" // Include the header for the Convert class

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Convert convertWindow; // Create an instance of Convert
    convertWindow.show(); // Show the Convert window

    return QApplication::exec(); // Execute the application
}