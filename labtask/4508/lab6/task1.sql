-- Task 1
set serveroutput on;

create table Users(
	username varchar2(20),
	password_length number,
	constraint pk_username primary key(username)
);

insert into Users values('ash',10);
insert into Users values('asha',11);
insert into Users values('ashar',7);
insert into Users values('asharo',4);

-- select max(password_length) from Users; 



create or replace function highestPassLength
return number is
	high number := 0;
begin
	select max(password_length) into high from Users;
	return high;
end;
/


create or replace function lowestPassLength
return number is
	high number := 0;
begin
	select min(password_length) into high from Users;
	return high;
end;
/

create or replace function findPermutation(pass_len in number)
return number is
	fact number :=1;
	num number :=52;
begin
	for count in 1..pass_len
	loop
		fact:=num * fact;
		num:=num -1;
	end loop;
	
	return fact;
end;
/


-- main
declare 
	len number;
	minlen number;
	perm number;
begin
	len:= highestPassLength();
	minlen := lowestPassLength();
	perm:= findPermutation(len);

	dbms_output.put_line('Highest Password Length: ' || len);
	dbms_output.put_line('Lowest Password Length: ' || minlen);
	dbms_output.put_line('Total Permutations : ' || perm);
end;
/