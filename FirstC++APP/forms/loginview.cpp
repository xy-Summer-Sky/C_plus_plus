//
// Created by Lenovo on 24-5-18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_loginview.h" resolved

#include "loginview.h"
#include "ui_loginview.h"


loginview::loginview(QWidget *parent) :
        QWidget(parent), ui(new Ui::loginview) {
    ui->setupUi(this);
}

loginview::~loginview() {
    delete ui;
}
