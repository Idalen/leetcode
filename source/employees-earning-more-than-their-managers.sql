# Write your MySQL query statement below
SELECT name AS Employee FROM Employee as e
    WHERE e.salary > (SELECT salary FROM Employee as m 
                     WHERE m.id = e.managerId)