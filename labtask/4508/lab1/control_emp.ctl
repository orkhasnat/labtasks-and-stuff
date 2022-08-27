LOAD DATA 
INFILE 'employee.csv'
INSERT INTO TABLE Employees
FIELDS TERMINATED BY ',' ,OPTIONALLY ENCLOSED BY '"'
TRAILING NULLCOLS
(
    id,
    name,
    salary,
    branch_id
)
