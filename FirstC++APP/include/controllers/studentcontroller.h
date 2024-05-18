//
// Created by Lenovo on 24-5-18.
//

#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include "student.h"

class StudentController {
public:
    StudentController();

    void addStudent(const QString& name, int age);
    void editStudent(int id, const QString& name, int age);
    void deleteStudent(int id);

private:
    Student student;
};

#endif // STUDENTCONTROLLER_H

