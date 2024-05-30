//
// Created by Lenovo on 24-5-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdminForm.h" resolved

#include "adminform.h"
#include "ui_AdminForm.h"

namespace SystemUi {
    AdminForm::AdminForm(QWidget *parent) :
            QWidget(parent), ui(new Ui::AdminForm) {
        ui->setupUi(this);
    }

    AdminForm::~AdminForm() {
        delete ui;
    }
} // SystemUi
