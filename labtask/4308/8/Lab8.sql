-- 190041113
-- Tasnimul Hasnat

-- Task 1:

CREATE TABLE Citizen
(
	NID INT,
	Name VARCHAR2(10),
	Dob VARCHAR2(10),
	Bld_grp VARCHAR(4),
	Address VARCHAR2(20),
	Profession VARCHAR2(10),
	Salary INT,
	CONSTRAINT pk_citizen PRIMARY KEY NID
);
CREATE TABLE License
(
	L_no INT,
	Name_of_Cit VARCHAR2(10),
	Address VARCHAR2(20),
	Dob VARCHAR2(10),
	Lic_iss_date VARCHAR2(10),
	Lic_exp_date VARCHAR2(10),
	Cit_NID INT UNIQUE,
	CONSTRAINT pk_license PRIMARY KEY L_No,
	CONSTRAINT fk_license FOREIGN KEY Cit_NID REFERENCES Citizen(NID) ON DELETE CASCADE
);
CREATE TABLE Hospital
(
	Name VARCHAR2(10),
	Location VARCHAR2(20),
	Estd_year INT,
	Tot_capacity INT,
	CONSTRAINT pk_hospital PRIMARY KEY Name
);
CREATE TABLE Admit
(
	Cit_NID INT,
	Hos_Name VARCHAR2(10),
	CONSTRAINT pk_admit PRIMARY KEY NID, Hos_Name,
	CONSTRAINT fk_admit_cit FOREIGN KEY Cit_NID REFERENCES Citizen(NID) ON DELETE CASCADE,
	CONSTRAINT fk_admit_hos FOREIGN KEY Hos_Name REFERENCES Hospital(Name) ON DELETE CASCADE
);
CREATE TABLE Publisher
(
	Name VARCHAR2(10),
	Country VARCHAR2(10),
	Estd_year NUMBER(4,2),
	Reputation VARCHAR2(10),
	CONSTRAINT pk_publisher PRIMARY KEY Name, Country
);
CREATE TABLE Book
(
	Title VARCHAR2(10),
	Author VARCHAR2(10),
	Price INT,
	Study_area VARCHAR(10),
	Pub_Name VARCHAR2(10),
	CONSTRAINT pk_book PRIMARY KEY Title, Author
	CONSTRAINT fk_book FOREIGN KEY Pub_Name REFERENCES Publisher(Name)
);
-- cascading delete not require here as deleting a publisher shouldn't delete a book.

CREATE TABLE Borrow
(
	Cit_NID INT,
	Book_Title VARCHAR2(10),
	Book_Author VARCHAR2(10),
	Borrow_date DATE,
	Return_date DATE,
	CONSTRAINT pk_borrow PRIMARY KEY NID, Book_Title, Author
	CONSTRAINT fk_borrow_cit FOREIGN KEY Cit_NID REFERENCES Citizen(NID) ON DELETE CASCADE,
	CONSTRAINT fk_borrow_book_T FOREIGN KEY Book_Title REFERENCES Book(Title) ON DELETE CASCADE,
	CONSTRAINT fk_borrow_book_A FOREIGN KEY Book_Author REFERENCES Book(Author) ON DELETE CASCADE
);

-- Task 2:


CREATE VIEW Borrow_Record AS
SELECT NID, Citizen.Name, Title, Author, Study_area, Publisher.Name , Country 
FROM Citizen NATURAL JOIN Borrow NATURAL JOIN Book NATURAL JOIN Publisher

CREATE VIEW Citizen_Borrowal_Count AS 
SELECT NID, count(Citizen.NID) FROM Borrow_Record
GROUP BY NID;


-- Task 3:

CREATE VIEW License_Holder_Info AS
SELECT License.L_No, License.Lic_iss_date,  License.Lic_exp_date, Citizen.Name ,Citizen.Profession
FROM Citizen, License WHERE Citizen.NID = License.Cit_NID

-- Task 4:

CREATE USER library_admin1 IDENTIFIED BY adminpass;
CREATE USER clerk1 IDENTIFIED BY clerkpass;
CREATE USER citizen1 IDENTIFIED BY citizenpass;
GRANT CREATE SESSION TO library_admin1;
GRANT CREATE SESSION TO clerk1;
GRANT CREATE SESSION TO citizen1;

CREATE ROLE ROLE_CITIZEN;
GRANT SELECT ON Citizen TO ROLE_CITIZEN;
GRANT SELECT ON License TO ROLE_CITIZEN;

CREATE ROLE ROLE_CLERK ;
GRANT SELECT ON Admit To Clerk;


CREATE ROLE ROLE_LIB_ADMIN ;
GRANT INSERT ON borrow TO ROLE_LIB_ADMIN;
GRANT DELETE ON borrow TO ROLE_LIB_ADMIN;
GRANT UPDATE ON borrow TO ROLE_LIB_ADMIN; 
GRANT INSERT ON book TO ROLE_LIB_ADMIN;
GRANT DELETE ON book TO ROLE_LIB_ADMIN;
GRANT UPDATE ON book TO ROLE_LIB_ADMIN; 
GRANT INSERT ON Publisher TO ROLE_LIB_ADMIN;
GRANT DELETE ON Publisher TO ROLE_LIB_ADMIN;
GRANT UPDATE ON Publisher TO ROLE_LIB_ADMIN;

GRANT ROLE_LIB_ADMIN TO library_admin1;
GRANT ROLE_CLERK TO clerk1;
GRANT ROLE_CITIZEN TO citizen1;
