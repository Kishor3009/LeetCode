# Write your MySQL query statement below
select distinct customer_number from orders 
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC
LIMIT 1