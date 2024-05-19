#include "ui_adminview.h"

AdminView::AdminView(QWidget *parent) :
        QWidget(parent),

        ui(new Ui::AdminView) {
    ui->setupUi(this);

    // 连接按钮信号到对应的槽以切换页面
    connect(ui->buttonAddStudent, &QPushButton::clicked, this, &AdminView::showAddStudentPage);
    connect(ui->buttonEditStudent, &QPushButton::clicked, this, &AdminView::showEditStudentPage);
    connect(ui->buttonGenerateReports, &QPushButton::clicked, this, &AdminView::showGenerateReportsPage);
}


AdminView::~AdminView() {
    delete ui;
}

void AdminView::showAddStudentPage() {
    ui->stackedWidget->setCurrentWidget(ui->pageAddStudent);
}

void AdminView::showEditStudentPage() {
    ui->stackedWidget->setCurrentWidget(ui->pageEditStudent);
}

void AdminView::showGenerateReportsPage() {
    ui->stackedWidget->setCurrentWidget(ui->pageGenerateReports);
}
