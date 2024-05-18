//
// Created by Lenovo on 24-5-18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_adminview.h" resolved

#include "adminview.h"
#include "ui_adminview.h"


adminview::adminview(QWidget *parent) :
        QWidget(parent), ui(new Ui::adminview) {
    ui->setupUi(this);
}

adminview::~adminview() {
    delete ui;
}
