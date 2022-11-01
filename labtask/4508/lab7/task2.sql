--task 2
set
    serveroutput on;

create table loan_type(
    scheme number check(
        scheme > 0
        and scheme < 4
    ),
    number_installments number,
    charge number,
    total_transactions number,
    constraint loan_pk primary key(scheme)
);

insert into
    loan_type
values
(1, 30, 0.05, 2000000);

insert into
    loan_type
values
(2, 20, 0.1, 1000000);

insert into
    loan_type
values
(3, 15, 0.15, 500000);

create table transaction(user_id int, amount number, t_date date);

insert into
    transaction
values
(1, 10000000, DATE '2022-5-10');

insert into
    transaction
values
(1, 10000000, DATE '2022-6-10');

insert into
    transaction
values
(1, 5000000, DATE '2022-9-10');

insert into
    transaction
values
(2, 5000000, DATE '2022-6-10');

insert into
    transaction
values
(2, 5000000, DATE '2022-5-10');

insert into
    transaction
values
(3, 10000, DATE '2022-6-10');

insert into
    transaction
values
(3, 1000, DATE '2022-5-10');

insert into
    transaction
values
(3, 1000, DATE '2022-6-10');

--PL/SQL CODE
create
or replace function scheme_number(uid in number) return number is scheme_no number;

total_transactions number;

min_transactions number;

flag number := 0;

cursor c_loan_type is
select
    scheme,
    total_transactions
from
    loan_type;

cursor c_transaction is
select
    sum(amount)
from
    transaction
where
    user_id = uid
    and (sysdate - t_date < 365);

begin open c_transaction;

fetch c_transaction into total_transactions;

open c_loan_type;

loop fetch c_loan_type into scheme_no,
min_transactions;

exit when c_loan_type % notfound;

if(total_transactions >= min_transactions) then flag := 1;

dbms_output.put_line('scheme no ' || scheme_no);

exit;

end if;

end loop;

if flag = 0 then dbms_output.put_line('no scheme');

end if;

close c_loan_type;

close c_transaction;

return scheme_no;

end;

/ 
-- MAIN FUNCTION
declare ans number;

u_id number := '&u_id';

begin ans := scheme_number(u_id);

end;

/