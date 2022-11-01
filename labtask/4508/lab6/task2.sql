-- Task 2

set serveroutput on;
create or replace procedure PrintSpace(str in varchar2)
is
    ret varchar2(40);
begin
    ret := substr(str,1,1);
    for i in 2..length(str)
    loop
        ret:=ret || ' ' || substr(str,i,1);
    end loop;
    dbms_output.put_line('Spaced Output : ' || ret);
end;
/

create or replace procedure RPrintPalindrome(str in varchar2)
is
    rev varchar2(40);
begin
    rev := substr(str,length(str),1);
    for i in 1..length(str)-1
    loop
        rev:= rev || substr(str,length(str)-i,1);
    end loop;
    if rev = str then
        dbms_output.put_line('yes');
    else 
        dbms_output.put_line('no');
    end if;
end;
/
create or replace procedure PrintPalindrome(str in varchar2)
is
    rev varchar2(40);
begin
    rev := substr(str,length(str),1);
    for i in reverse 1..length(str)-1
    loop
        rev:= rev || substr(str,i,1);
    end loop;
    if rev = str then
        dbms_output.put_line('yes');
    else 
        dbms_output.put_line('no');
    end if;
end;
/

--main
declare
    str varchar2(20) := '&string';
begin
    PrintSpace(str);
    PrintPalindrome(str);
    -- RPrintPalindrome(str);
end;
/