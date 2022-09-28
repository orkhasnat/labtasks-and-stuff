-- Task 2
SET SERVEROUTPUT ON;

CREATE OR REPLACE FUNCTION GENERATE_PRIMES(
    NUM INTEGER
) RETURN INTEGER IS
    SS    INTEGER := 0;
    TOTAL NUMBER :=0;
    FLAG  NUMBER :=0;
    J     NUMBER;
BEGIN
    FOR I IN 2 ..(NUM) LOOP
        FLAG :=0;
        FOR J IN 2 ..(SQRT(I)) LOOP
            IF MOD(I, J)=0 THEN
                FLAG:=1;
                EXIT;
            ELSE
                FLAG:=1;
            END IF;
        END LOOP;
        IF FLAG=0 THEN
            TOTAL :=TOTAL +I;
            IF TOTAL>NUM THEN
                EXIT;
            ELSE
                DBMS_OUTPUT.PUT_LINE(I);
            END IF;
        END IF;
    END LOOP;
    RETURN SS;
END;
/

DECLARE
    S  INTEGER;
    SS INTEGER;
BEGIN
    S:= &S;
    SS:=GENERATE_PRIMES(S);
END;
/