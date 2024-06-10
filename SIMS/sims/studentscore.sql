create table if not exists studentscore
(
    id        int auto_increment
        primary key,
    studentID varchar(255) null,
    courseID  varchar(255) not null,
    score     varchar(255) not null
);

