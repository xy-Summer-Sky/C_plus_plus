create table if not exists useraccounts
(
    USERID   varchar(255)                         not null,
    PASSWORD varchar(255)                         not null,
    TYPE     enum ('admin', 'student', 'teacher') not null,
    id       int auto_increment
        primary key,
    constraint account
        unique (USERID)
);

