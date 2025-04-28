# Write your MySQL query statement below
SELECT name FROM employee 
WHERE id in (SELECT managerId from Employee GROUP BY managerId having COUNT(*)>=5);