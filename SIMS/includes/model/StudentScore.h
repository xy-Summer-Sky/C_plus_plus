//
// Created by Lenovo on 24-6-10.
//

#ifndef SIMS_STUDENTSCORE_H
#define SIMS_STUDENTSCORE_H
#include <string>
namespace Model {
    class StudentScore;

    //学生成绩类
    class StudentScore {
    private:
        std::string studentId;
        std::string courseId;
        std::string score;
    public:
        StudentScore();

        StudentScore(const std::string &studentId, const std::string &courseId, const std::string &score);

        const std::string &getStudentId() const;//获取学生id

        void setStudentId(const std::string &string);//设置学生id

        const std::string &getCourseId() const;//获取课程id

        void setCourseId(const std::string &id);//设置课程id

        const std::string &getScore() const;//获取成绩

        void setScore(const std::string &score);//设置成绩


    };
}

#endif
