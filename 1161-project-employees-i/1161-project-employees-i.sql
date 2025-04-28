# Write your MySQL query statement below
SELECT s.project_id,ROUND(AVG(e.experience_years),2) AS average_years FROM Project s
JOIN Employee e
ON s.employee_id=e.employee_id
GROUP BY s.project_id;