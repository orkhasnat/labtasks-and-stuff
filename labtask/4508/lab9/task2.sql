create table accounts(
id int,
Name varchar2(20),
Acccode int,
Balance number,
LastDateofInterest date,
constraint accounts_pk primary key(id) 
);

create table acc_type(
pid int,
Name varchar2(20),
interestRate number,
gp int,
constraint ap_fk foreign key(pid) references accounts(id)
);




DELETE FROM acc_type;
DELETE FROM accounts;

insert into accounts values(1,'a',101,500,DATE '2022-11-03');
insert into accounts values(2,'b',102,1500,DATE '2022-5-13');
insert into accounts values(3,'c',103,3500,DATE '2020-9-13');

insert into acc_type values(1,'a',0.1,1);
insert into acc_type values(2,'b',.2,2);
insert into acc_type values(3,'c',.3,3);





SELECT * FROM accounts;

DECLARE
    CURSOR MYCURSOR_ACC IS SELECT id, Balance, LastDateofInterest FROM accounts;
    ACC_ID INT;
    ACC_BALANCE Accounts.BALANCE%type;
    Countt NUMBER;
    DAYS INT;
    LastIntDate date; 
    gp_type int;
    int_rate number;
BEGIN
    OPEN MYCURSOR_ACC;

	LOOP
    	FETCH MYCURSOR_ACC into ACC_ID, ACC_BALANCE, LastIntDate;
    	EXIT WHEN MYCURSOR_ACC%notfound;
    
    	SELECT (SYSDATE  - LastIntDate) INTO DAYS FROM DUAL;
		SELECT gp INTO gp_type FROM acc_type where pid=ACC_ID;
    	dbms_output.put_line('id : ' || ACC_ID || ' with gp ' || gp_type ||' days ' || DAYS);
	
    	SELECT interestRate INTO int_rate FROM acc_type where pid = ACC_ID;
		
        IF gp_type = 1 THEN
        	WHILE DAYS>0
        	LOOP
            	ACC_BALANCE := ACC_BALANCE + ACC_BALANCE*(int_rate);
            	DAYS:= DAYS - 1;
        	END LOOP;
        
        ELSIF gp_type = 2 THEN
        	WHILE DAYS>0
        	LOOP
            	ACC_BALANCE := ACC_BALANCE + ACC_BALANCE*(int_rate);
            	DAYS:= DAYS - 30;
	        END LOOP;

    	ELSIF gp_type = 3 THEN
        	WHILE DAYS>0
        	LOOP
        		ACC_BALANCE := ACC_BALANCE + ACC_BALANCE*(int_rate);
        		DAYS:= DAYS - 365;
        	END LOOP;
        		
 		END IF;

 	update accounts set Balance = ACC_BALANCE, LastDateofInterest = (select sysdate from dual) where ID=ACC_ID;
    
    
	END LOOP;


	CLOSE MYCURSOR_ACC;

END;

SELECT * FROM accounts;
SELECT * FROM acc_type;