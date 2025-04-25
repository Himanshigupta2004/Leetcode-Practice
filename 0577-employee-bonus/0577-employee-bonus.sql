# Write your MySQL query statement below
SELECT name,bonus FROM Employee 
LEFT JOIN BONUS
ON employee.empID=bonus.empID
WHERE bonus<1000 or bonus IS NULL;