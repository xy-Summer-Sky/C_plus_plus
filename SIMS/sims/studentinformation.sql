create table if not exists studentinformation
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
        unique (studentID, phonenumber),
    constraint studentinformation_useraccounts_USERID_fk
        foreign key (studentID) references useraccounts (USERID)
);

