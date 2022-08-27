LOAD DATA 
INFILE 'branch.csv'
INSERT INTO TABLE Branch
FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '"'
TRAILING NULLCOLS
(
    branch_id,
    branch_name
)

