# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE B
FROM Person A 
LEFT JOIN Person B 
ON A.email = B.email
WHERE A.id < B.id  