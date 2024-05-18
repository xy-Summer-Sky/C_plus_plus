//
// Created by Lenovo on 24-5-18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_studentview.h" resolved

#include "studentview.h"
#include "ui_studentview.h"


studentview::studentview(QWidget *parent) :
        QWidget(parent), ui(new Ui::studentview) {
    ui->setupUi(this);
}

studentview::~studentview() {
    delete ui;
}
