#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student {
public:
    Student(int id, const QString& name, int age);

    bool loadFromDB(int id);
    bool saveToDB();

    // Getters and Setters
    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString& value);

    int getAge() const;
    void setAge(int value);

private:
    int id;
    QString name;
    int age;
};

#endif // STUDENT_H
