create table if not exists teacherinformation
(
    teacherId          varchar(255) not null,
    teacherName        varchar(255) not null,
    teacherPhonenumber varchar(255) not null,
    id                 int auto_increment
        primary key,
    teacherEmail       varchar(255) null,
    constraint teacherinformation_pk
        unique (teacherId)
);

