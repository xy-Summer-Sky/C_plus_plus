#include <QApplication>
#include"loginform.h"


int main(int argc,char *argv[]){

    // SetDllDirectoryW(L"F:\\CODE\\GIThub\\C_plus_plus\\Cmake\\loadlib\\mysqllib_c");
    QApplication a(argc,argv);
    SystemUi::LoginForm w;
    w.show();
    return QApplication::exec();
};