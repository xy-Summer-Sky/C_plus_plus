//
// Created by Lenovo on 24-5-18.
//

#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QWidget>
#include <QTableView>
#include <QPushButton>

class StudentView : public QWidget {
Q_OBJECT
public:
    explicit StudentView(QWidget *parent = nullptr);

private slots:
    void onAddStudentClicked();
    void onEditStudentClicked();
    void onDeleteStudentClicked();

private:
    QTableView* tableView;
    QPushButton* addButton;
    QPushButton* editButton;
    QPushButton* deleteButton;

    void setupUi();
    void connectSignals();


};

#endif // STUDENTVIEW_H

