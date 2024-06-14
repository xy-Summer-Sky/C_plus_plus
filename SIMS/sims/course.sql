create table if not exists course
(
    courseName varchar(255) not null,
    courseID   varchar(255) null,
    id         int auto_increment
        primary key,
    teacher    varchar(255) not null,
    constraint course_pk
        unique (courseID),
    constraint `unique`
        unique (courseID)
);

create index course_teacherinformation_teacherId_fk
    on course (teacher);

r) references teacherinformation (teacherId)
);

