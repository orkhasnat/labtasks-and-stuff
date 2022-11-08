-- task2 
-- not sure if this works or not

create or replace trigger F1_insert
after insert on Friends 
for each row
declare
pragma autonomous_transaction;
begin
    insert into Friends values (:new.id2 , :new:id1);
end;
/

insert into Friends values(5,7)
select * from Friends;


create or replace trigger F1_Del
after delete on Friends
for each row 
declare
pragma autonomous_transaction;
begin
    delete from Friends
    where (id1 = :old.id2 and id2 =:old.id1);
    commit;
end;
/
delete from Friends where id1=5 and id2=7;
select * from Friends;
