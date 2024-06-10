//
// Created by Lenovo on 24-6-10.
//

#ifndef SIMS_STUDENTSCORE_H
#define SIMS_STUDENTSCORE_H
#include <string>
namespace Model {
    class StudentScore;

    class StudentScore {
    private:
        std::string studentId;
        std::string courseId;
        std::string score;
    public:
        StudentScore();

        StudentScore(const std::string &studentId, const std::string &courseId, const std::string &score);

        const std::string &getStudentId() const;

        void setStudentId(const std::string &string);

        const std::string &getCourseId() const;

        void setCourseId(const std::string &id);

        const std::string &getScore() const;

        void setScore(const std::string &score);


    };
}

#endif //SIMS_STUDENTSCORE_H
