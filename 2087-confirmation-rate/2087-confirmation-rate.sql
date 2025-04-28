SELECT 
    s.user_id,
    IFNULL(
        ROUND(
            SUM(CASE WHEN e.action = 'confirmed' THEN 1 ELSE 0 END) / COUNT(e.action),
            2
        ),
    0.00) AS confirmation_rate 
FROM Signups s
LEFT JOIN Confirmations e
    ON s.user_id = e.user_id
GROUP BY s.user_id;
