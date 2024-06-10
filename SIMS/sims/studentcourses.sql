create table if not exists studentcourses
(
    studentID  varchar(255) not null,
    courseID_1 varchar(255) null,
    id         int auto_increment
        primary key,
    courseID_2 varchar(255) null,
    courseID_3 varchar(255) null,
    courseID_4 varchar(255) null,
    constraint studentcourse_pk
        unique (studentID),
    constraint studentcourses_course_courseID_fk
        foreign key (courseID_1) references course (courseID),
    constraint studentcourses_course_courseID_fk_2
        foreign key (courseID_2) references course (courseID),
    constraint studentcourses_course_courseID_fk_3
        foreign key (courseID_3) references course (courseID),
    constraint studentcourses_course_courseID_fk_4
        foreign key (courseID_4) references course (courseID)
);

