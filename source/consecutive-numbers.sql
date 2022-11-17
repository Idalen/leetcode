# Write your MySQL query statement below



SELECT DISTINCT num as ConsecutiveNums FROM

(

    SELECT num, LEAD(num) OVER(ORDER BY id) AS next, 

    LAG(num) OVER(ORDER BY id) AS last FROM Logs

)t

WHERE num = next AND num = last;

