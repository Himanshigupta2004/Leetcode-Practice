# Write your MySQL query statement below
SELECT V.customer_id,Count(V.visit_id) AS count_no_trans FROM Visits V 
LEFT JOIN Transactions t
ON t.visit_id = V.visit_id
WHERE t.transaction_id IS NULL
GROUP BY V.customer_id;