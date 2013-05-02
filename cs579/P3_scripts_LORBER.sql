/* Terry Lorber <tgl@bu.edu> */
/* CS579 Spring 2013 */
/* Project Part3 */

/* CREATE TABLES */

create table person (
       ssn       char(9) primary key,
       name      varchar(32) unique not null,
       phone     char(10),
       address	 varchar(30),
       employer	 varchar(15) not null,
       insurer 	 varchar(15) not null,
       pcp    	 smallint not null
);

create table physician (
       pid   	   smallint primary key,
       name        varchar(32) unique not null,
       specialty  varchar(15),
       address	   varchar(30),
       phone	   char(10)
);

create table visit (
       ssn   	   char(9) not null,
       pid   	   smallint not null,
       date  	   date not null,
       diagnosis   varchar(255),
       pcp_or_not  boolean,
       primary key (ssn, pid, date),
       foreign key (ssn) references person(ssn) on delete restrict,
       foreign key (pid) references physician(pid) on delete restrict
);      
       
create table claim (
       cid   	 smallint primary key,
       amount	 float,
       file_date date,
       paid_date date,
       ssn	 char(9) not null,
       pid	 smallint not null,
       date 	 date not null,
       insurer	 varchar(15) not null,
       foreign key (ssn, pid, date) references visit(ssn, pid, date) on delete restrict
);

create table employer (
       name    varchar(15) primary key,
       address varchar(30),
       phone   char(10) unique not null
);

create table insurer (
       name    varchar(15) primary key,
       address varchar(30),
       phone   char(10) unique not null
);

create table hospital (
       name    varchar(15) primary key,
       address varchar(30),
       phone   char(10) unique not null
);

create table emp_insurer (
       emp_name		 varchar(15) not null,
       ins_name		 varchar(15) not null,
       primary key (emp_name, ins_name),
       foreign key (emp_name) references employer(name) on delete cascade,
       foreign key (ins_name) references insurer(name) on delete cascade	
);

create table phy_insurer (
       pid		 smallint not null,
       ins_name		 varchar(15) not null,
       primary key (pid, ins_name),
       foreign key (pid) references physician(pid) on delete cascade,
       foreign key (ins_name) references insurer(name) on delete cascade
);
       
create table affiliation (
       pid   		 smallint not null,
       hospital_name	 varchar(15) not null,
       primary key (pid, hospital_name),
       foreign key (pid) references physician(pid) on delete cascade,
       foreign key (hospital_name) references hospital(name) on delete cascade	
);

alter table person add foreign key (employer) references employer(name) on delete restrict;
alter table person add foreign key (insurer) references insurer(name) on delete restrict;
alter table person add foreign key (pcp) references physician(pid) on delete restrict;

alter table claim add foreign key (insurer) references insurer(name) on delete restrict;

/* CREATE TUBLES */

insert into employer (name, phone, address)
values
('Acme Inc.', '2075551212', '42 Main St'),
('XYZ Corp.', '2075553333', '40 Main St'),
('Amalgamated', '2075554444', '11 Main St'),
('Not Bankrupt', '2075557777', '100 Elm St'),
('Affiliated', '2075558888', '4 Beech St'),
('LMC Corp.', '2075559999', '1 Oak St'),
('Mom & Pop Co.', '2075552222', '101 Elm St'),
('Apex Ltd.', '2076661212', '44 Main St');

insert into insurer (name, phone, address)
values
('Trust Me', '6174441212', '42 Mane St'),
('We Pay Big', '6174443333', '40 Mane St'),
('GetLife', '6174444444', '11 Mane St'),
('LibertyMucus', '6174447777', '100 Elm St'),
('Providential', '6174448888', '4 Beech St'),
('The Rock', '6174449999', '1 Oak St'),
('Friendly', '6174442222', '101 Elm St'),
('NotFriendly', '6175551212', '44 Mane St');

insert into hospital (name, phone, address)
values
('Spec. Hospital', '7818881212', '82 Mane St'),
('The Brigham', '7818883333', '80 Mane St'),
('Beth Israel', '7818888888', '11 Mane St'),
('Salem Hospital', '7818887777', '100 Elm St'),
('Union Hospital', '6178888888', '8 Beech St'),
('Mustard Clinic', '7818889999', '1 Oak St'),
('Cinci Clinic', '7818882222', '101 Elm St'),
('Mount Sinus', '7815551212', '88 Mane St');

insert into physician (pid,name,specialty,address,phone)
values
(1,'Doc Watson','Knees','44 Oak Sq','7812223333'),
(2,'Doc Marten','Eyes','58 Cherry St','7812221111'),
(3,'Doc Halliday','Ears','1 Elm St','7812224444'),
(4,'Dr Jones','Throat','111 Main St','7812225555'),
(5,'Dr Smith','Heart','44 Oak St','7812226666'),
(6,'Doctor Obvious','Lung','64 Orchard St','7812227777'),
(7,'Doctor Who','Stomach','55 Elm St', '7815558888'),
(8,'Dr Livingstone','Funny Bone','11 South St','7812229999');

insert into person (ssn,name,phone,address,employer,insurer,pcp)
values
('111223333', 'Tom', '7810003333', '33 Elm St', 'XYZ Corp.', 'Providential', 1),
('222223333', 'Dick', '7811113333', '66 Elm St', 'XYZ Corp.', 'Providential', 1),
('333223333', 'Harry', '7812223333', '99 Elm St', 'XYZ Corp.', 'Trust Me', 3),
('444223333', 'Moe', '7813333333', '1212 Elm St', 'Acme Inc.', 'We Pay Big', 3),
('555223333', 'Larry', '7814443333', '2424 Elm St', 'Apex Ltd.', 'Friendly', 3),
('666223333', 'Curly', '7815553333', '3636 Elm St', 'Mom & Pop Co.', 'Friendly', 4),
('777223333', 'Bogart', '7816663333', '4848 Elm St', 'Affiliated', 'NotFriendly', 5),
('888223333', 'Bacall', '7817773333', '6060 Elm St', 'Affiliated', 'LibertyMucus', 6),
('999223333', 'Tracy', '7818883333', '7272 Elm St', 'Not Bankrupt', 'GetLife', 6);

insert into affiliation (pid, hospital_name)
values
(1, 'Spec. Hospital'),
(1, 'Mount Sinus'),
(1, 'Cinci Clinic'),
(2, 'Spec. Hospital'),
(2, 'Mount Sinus'),
(2, 'Cinci Clinic'),
(3, 'Spec. Hospital'),
(3, 'Mount Sinus'),
(3, 'Cinci Clinic'),
(4, 'Spec. Hospital'),
(4, 'Mount Sinus'),
(4, 'Cinci Clinic');

insert into emp_insurer (emp_name, ins_name)
values
('XYZ Corp.', 'Providential'),
('XYZ Corp.', 'Trust Me'),
('XYZ Corp.', 'We Pay Big'),
('Not Bankrupt', 'Providential'),
('Not Bankrupt', 'Trust Me'),
('Not Bankrupt', 'We Pay Big'),
('Not Bankrupt', 'Friendly'),
('Not Bankrupt', 'NotFriendly'),
('Acme Inc.', 'We Pay Big'),
('Acme Inc.', 'Providential'),
('Acme Inc.', 'Trust Me'),
('Acme Inc.', 'Friendly');

insert into phy_insurer (pid, ins_name)
values
(1, 'Providential'),
(2, 'Trust Me'),
(3, 'We Pay Big'),
(4, 'Providential'),
(5, 'Trust Me'),
(5, 'We Pay Big'),
(5, 'Friendly'),
(6, 'NotFriendly'),
(7, 'We Pay Big'),
(8, 'Providential'),
(8, 'Trust Me'),
(8, 'Friendly');

insert into visit (ssn,pid,date,diagnosis,pcp_or_not)
values
('888223333',6,'2013-03-01','Improving',true),
('888223333',6,'2013-03-02','All clear',true),
('888223333',5,'2013-03-31','Not Good',false),
('111223333',2,'2013-03-01','Take two and call',false),
('222223333',1,'2013-01-01','Better than average',true),
('333223333',3,'2013-02-01','No change',true),
('333223333',4,'2013-02-05','Come again',false),
('444223333',3,'2013-03-05','Good',true),
('444223333',4,'2013-03-06','Better',false),
('555223333',8,'2013-03-07','Best',false),
('555223333',8,'2013-03-08','Hypochondriac',false);

insert into claim (cid,amount,file_date,paid_date,ssn,pid,date,insurer)
values
(1,42.11,'2013-04-01',NULL,'888223333',6,'2013-03-01','Providential'),
(2,50.00,'2013-04-01',NULL,'888223333',6,'2013-03-01','Trust Me'),
(3,101.00,'2013-04-01','2013-04-02','555223333',8,'2013-03-07','The Rock'),
(4,101.00,'2013-04-01','2013-04-02','555223333',8,'2013-03-07','GetLife'),
(5,101.00,'2013-04-01','2013-04-02','555223333',8,'2013-03-08','Providential'),
(6,101.00,'2013-04-01','2013-04-02','555223333',8,'2013-03-08','LibertyMucus'),
(7,0.10,'2013-04-01',NULL,'444223333',3,'2013-03-05','NotFriendly'),
(8,11.10,'2013-04-01','2013-04-02','333223333',3,'2013-02-01','We Pay Big'),
(9,10.10,'2013-04-01','2013-04-02','333223333',4,'2013-02-05','GetLife'),
(10,1.00,'2013-04-01','2013-04-02','555223333',8,'2013-03-07','LibertyMucus');

/* QUERIES */

select ins_name from phy_insurer i, physician p
where i.pid = p.pid and p.name = 'Dr Livingstone';

select v.date, p.name, v.pcp_or_not, v.diagnosis                    
from visit v, physician p, person i
where v.pid = p.pid and v.ssn = i.ssn
and i.name = 'Bacall' and v.date > '2013-01-01' and v.date < '2013-04-01';

select i.name from insurer i, person p, emp_insurer e
where i.name = e.ins_name and p.employer = e.emp_name 
and p.name = 'Tracy';

select c.* from claim c, physician p
where c.pid = p.pid
and c.paid_date is null
and p.name = 'Doctor Obvious';
