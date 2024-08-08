# Write your MySQL query statement below
select employee_id, department_id from employee 
where primary_flag = 'Y' or employee_id 
in (select employee_id from Employee group by employee_id having count(*) = 1);