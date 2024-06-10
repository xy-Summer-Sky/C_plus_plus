create table if not exists studeninformation
(
    studentID   varchar(255) not null,
    studentName varchar(255) not null,
    email       varchar(255) null,
    phonenumber varchar(255) not null,
    id          int auto_increment
        primary key,
    constraint studeninformation_pk
        unique (studentID),
    constraint uniqueInfo
        unique (studentID, phonenumber)
);

