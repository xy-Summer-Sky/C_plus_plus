#include "ui_studentview.h"  // 假设这是正确的头文件名

StudentView::StudentView(QWidget *parent) : QWidget(parent), ui(new StudentView) {

}

StudentView::~StudentView() {
    delete ui;
}
