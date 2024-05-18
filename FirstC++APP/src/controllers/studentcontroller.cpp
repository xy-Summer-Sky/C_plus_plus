//
// Created by Lenovo on 24-5-18.
//
// studentcontroller.cpp
#include "studentcontroller.h"
#include "studentview.h"
#include "student.h"

StudentController::StudentController(StudentView *view) : view(view) {
    connect(view, &StudentView::loadRequested, this, &StudentController::handleLoadRequest);
}

void StudentController::handleLoadRequest(int studentId) {
    Student student;
    if (student.loadFromDB(studentId)) {
        view->showStudentDetails(student);
    } else {
        view->showError("Load failed", "Could not load student.");
    }
}
