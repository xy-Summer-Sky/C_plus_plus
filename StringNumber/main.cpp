#include <QApplication>
#include "ui/convert.h" // Include the header for the Convert class
#include <QTextCodec>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    Convert convertWindow; // Create an instance of Convert
    convertWindow.show(); // Show the Convert window

    return QApplication::exec(); // Execute the application
}