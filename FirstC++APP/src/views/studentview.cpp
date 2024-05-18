// studentview.cpp
#include "studentview.h"


StudentView::StudentView(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::StudentView) {
    ui->setupUi(this);
    connect(ui->loadButton, &QPushButton::clicked, this, &StudentView::onLoadButtonClicked);
}

StudentView::~StudentView() {
    delete ui;
}

void StudentView::onLoadButtonClicked() {
    int studentId = ui->studentIdLineEdit->text().toInt();
    Student student;
    if (student.loadFromDB(studentId)) {
        ui->nameLineEdit->setText(student.name);
        ui->ageLineEdit->setText(QString::number(student.age));
    } else {
        QMessageBox::warning(this, "Load failed", "Could not load student from database.");
    }
}
