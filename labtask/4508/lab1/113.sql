--Task 1

CREATE TABLE Branch(
    branch_id INT NOT NULL PRIMARY KEY,
    branch_name VARCHAR(255)
);


CREATE TABLE Employees(
	id INT NOT NULL PRIMARY KEY,
    name VARCHAR(255),
	salary INT,
    branch_id INT,
    FOREIGN KEY (branch_id) REFERENCES Branch(branch_id)
);



-- Task 2

-- sqlldr userid=newish/cse13 control=control_branch.ctl log=track.log
-- sqlldr userid=newish/cse13 control=control_emp.ctl log=track.log


-- Task 3A

SELECT COUNT(*) FROM Employees
WHERE branch_id IN (SELECT branch_id FROM Branch
                        WHERE branch_name = 'scantron')
AND salary > (SELECT AVG(salary) FROM Employees);

-- Task 3b

SELECT branch_name FROM Branch
WHERE branch_id IN ( SELECT Branch FROM Employees WHERE id=35);


