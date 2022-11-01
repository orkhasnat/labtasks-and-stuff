-- task 1
set
    serveroutput on;

create table Employees(
    id int,
    name varchar(20),
    salary int,
    designation varchar(20),
    constraint emp_pk primary key(id)
);

insert into
    Employees
values
    (1, 'ash', 50000, 'manager');

insert into
    Employees
values
    (2, 'asha', 35000, 'assistant-manager');

insert into
    Employees
values
    (3, 'ashar', 45000, 'assistant-manager');

insert into
    Employees
values
    (4, 'ashari', 35000, 'assistant-manager');

insert into
    Employees
values
    (5, 'asharin', 75000, 'manager');

insert into
    Employees
values
    (6, 'asharina', 25000, 'assistant-manager');

insert into
    Employees
values
    (7, 'ash', 5000, 'manager');

insert into
    Employees
values
    (8, 'ash', 5000, 'manager');

-- main
declare total_rows number;

begin
update
    Employees
set
    salary = salary + salary * 0.10
where
    (
        salary > 50000
        and designation = 'manager'
    );

total_rows := sql % rowcount;

update
    Employees
set
    salary = salary - salary * 0.10
where
    (
        salary > 20000
        and designation = 'assistant-manager'
    );

total_rows := total_rows + sql % rowcount;

if total_rows = 0 then 
    dbms_output.put_line('No Employees Selected');

else 
    dbms_output.put_line(total_rows || ' Employees Selected');

end if;
end;
/