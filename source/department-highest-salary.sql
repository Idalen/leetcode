# Write your MySQL query statement below

SELECT departmentName as Department, name as Employee, salary as Salary FROM

    (SELECT Employees.departmentId, name, salary FROM

        (SELECT departmentId, MAX(salary) as maxSalary FROM Employee

        GROUP BY departmentId) Salaries

    INNER JOIN

        (SELECT departmentId, name, salary FROM Employee) Employees

    ON Employees.departmentId = Salaries.departmentId

    WHERE salary = maxSalary) t1

INNER JOIN

    (SELECT id, name as departmentName FROM Department) t2

ON t1.departmentId = t2.id;



