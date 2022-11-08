--task1 

set serveroutput on;

create user ork identified by ork;
grant all privileges to ork;

create table Student(
    id int,
    name varchar(20),
    grade int, --check(grade>=0 and grade <=12),
    constraint id_pk primary key(id)
);
create table Friends(
    id1 int,
    id2 int,
    constraint rel primary key(id1,id2)
);


insert into Friends values(1,2);
insert into Friends values(1,3);
insert into Friends values(1,4);
insert into Friends values(1,5);
insert into Friends values(1,6);
insert into Friends values(7,8);
insert into Friends values(7,9);
insert into Friends values(7,10);


insert into Student values (1,'ash',10);
insert into Student values (2,'asha',10);
insert into Student values (3,'ashar',10);
insert into Student values (4,'ashari',10);
insert into Student values (5,'asharin',10);
insert into Student values (6,'asharina',10);
insert into Student values (7,'asma',8);
insert into Student values (8,'asman',8);
insert into Student values (9,'asmani',8);
insert into Student values (10,'asmanik',8);

create or replace trigger removeGraduate
after update 
on Student
begin
    delete from Student where grade>12;
end;
/

update Student set grade = 13 where id= 2;
select * from Student;


create or replace trigger updateFriends
after update 
on Student
for each row
declare
    PRAGMA AUTONOMOUS_TRANSACTION;
    cid int;
begin   
    cid:= :new.id;
    update Student set grade=grade+1 WHERE id in (SELECT id2 from Friends where id1=cid);
    commit;
end;
/

update Student set grade=grade+1 where id=1;
select * from Student;

