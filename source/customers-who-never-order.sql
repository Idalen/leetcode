# Write your MySQL query statement below
SELECT name
FROM Customers C 
LEFT JOIN Orders A 
ON A.customerId = C.id 
WHERE A.customerId IS NULL

