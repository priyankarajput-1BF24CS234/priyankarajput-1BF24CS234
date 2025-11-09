create database employee_database;
use employee_database;

create table dept(deptno int primary key,dname varchar(30),dloc varchar(30));
insert into dept values
(10,'HR','Bengaluru'),
(20,'Finance','Hyderabad'),
(30,'IT','Mysuru'),
(40,'Marketing','Chennai'),
(50,'Operation','Delhi');

create table employee(empno int primary key,ename varchar(30),mgr_no int,hiredate date,sal decimal(10,2),deptno int,foreign key (deptno) references dept(deptno));
insert into employee values
(1001,'Asha',NULL,'2020-05-12',55000,10),
(1002,'Rahul',1001,'2021-01-18',48000,20),
(1003,'Sneha',1001,'2019-08-21',60000,30),
(1004,'Kiran',1003,'2022-04-15',45000,40),
(1005,'Vikram',1002,'2020-09-12',52000,50),
(1006,'Asha',1003,'2023-03-10',47000,30);

create table project(pno int primary key,pname varchar(30),ploc varchar(30));
insert into project values
(501,'ERP upgrade','Bengaluru'),
(502,'payroll automation','hyderabad'),
(503,'Ai chatbot','mysuru'),
(504,'market survey','delhi'),
(505,'data migration','chennai');

create table assigned_to(empno int,pno int,job_role varchar(30),
primary key(empno,pno),
foreign key(empno) references employee(empno),
foreign key(pno) references project (pno));
insert into assigned_to values
(1001,501,'manager'),
(1002,502,'analyst'),
(1003,503,'developer'),
(1004,505,'executive'),
(1005,504,'coordinator'),
(1006,503,'tester'),
(1003,501,'consultant');

create table incentives(empno int,incentive_date date,incentive_amount decimal(10,2),foreign key (empno) references employee(empno));
insert into incentives values
(1001,'2023-12-10',5000),
(1003,'2024-01-20',7000),
(1005,'2024-03-15',6000),
(1006,'2024-04-25',3000),
(1002,'2023-10-05',4000);

select * from dept;
select * from employee;
select * from assigned_to;
select * from incentives;

select distinct a.empno
from assigned_to a
join project p on a.pno=p.pno
where p.ploc in ('bengaluru','hyderabad','mysuru');

select empno
from employee
where empno not in (select empno from incentives);

select e.ename,e.empno,d.dloc as dept_location, p.ploc as project_location
from employee e
join dept d on e.deptno=d.deptno
join assigned_to a on e.empno=a.empno
join project p on a.pno=p.pno
where d.dloc=p.ploc;

SELECT e.ename AS manager_name, COUNT(m.empno) AS total_employees
FROM employee e
JOIN employee m ON e.empno = m.mgr_no
GROUP BY e.empno, e.ename
HAVING COUNT(m.empno) = (SELECT MAX(emp_count)
FROM (SELECT COUNT(*) AS emp_count
FROM employee
WHERE mgr_no IS NOT NULL
GROUP BY mgr_no) AS counts);


select m.ename as manager_name from employee m
where m.sal>( select avg(e.sal) from employee e where e.mgr_no=m.mgr_no );

select e.ename as second_level_manager,d.dname as department from employee e
join dept d on e.deptno=d.deptno
where e.mgr_no in (
select empno from employee where mgr_no is null);

select * from incentives where incentive_date between '2019-01-01'and '2019-01-31'
and incentive_amount=(select max(incentive_amount) from incentives where incentive_date between '2019-01-01'and '2019-01-31'
and incentive_amount<(select max(incentive_amount) from incentives where incentive_date between '2019-01-01' and '2019-01-31')
);

select e.ename as employee, m.ename as manager, d.dname as department from employee e
join employee m on e.mgr_no=m.empno
join dept d on e.deptno=d.deptno
where e.deptno=m.deptno;
