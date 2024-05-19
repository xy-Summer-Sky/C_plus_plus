#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

// 前向声明，需要包含对应的 Qt UI 头文件
namespace Ui {
    class AdminView;
}

class AdminView : public QWidget {
Q_OBJECT

public:
    explicit AdminView(QWidget *parent = nullptr);
    ~AdminView();

private slots:
    void showAddStudentPage();
    void showEditStudentPage();
    void showGenerateReportsPage();

private:
    Ui::AdminView *ui;
};

#endif // ADMINVIEW_H
