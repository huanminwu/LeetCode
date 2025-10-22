-----------------------------------------------------------------------
--- Leet Code 3705. Find Golden Hour Customers
---
--- Medium
--- SQL Schema
--- Pandas Schema
--- Table: restaurant_orders
---
--- +------------------+----------+
--- | Column Name      | Type     | 
--- +------------------+----------+
--- | order_id         | int      |
--- | customer_id      | int      |
--- | order_timestamp  | datetime |
--- | order_amount     | decimal  |
--- | payment_method   | varchar  |
--- | order_rating     | int      |
--- +------------------+----------+
--- order_id is the unique identifier for this table.
--- payment_method can be cash, card, or app.
--- order_rating is between 1 and 5, where 5 is the best (NULL if not rated).
--- order_timestamp contains both date and time information.
--- Write a solution to find golden hour customers - customers who 
--- consistently order during peak hours and provide high satisfaction. 
--- A customer is a golden hour customer if they meet ALL the following 
--- criteria:
---
--- Made at least 3 orders.
--- At least 60% of their orders are during peak hours 
--- (11:00-14:00 or 18:00-21:00).
--- Their average rating for rated orders is at least 4.0, round it to 2 
--- decimal places.
--- Have rated at least 50% of their orders.
--- Return the result table ordered by average_rating in descending order, 
--- then by customer_id​​​​​​​ in descending order.
---
--- The result format is in the following example.
---
--- Example:
--- 
--- Input:
--- 
--- restaurant_orders table:
--- 
--- +----------+-------------+---------------------+--------------+----------------+--------------+
--- | order_id | customer_id | order_timestamp     | order_amount | payment_method | order_rating |
--- +----------+-------------+---------------------+--------------+----------------+--------------+
--- | 1        | 101         | 2024-03-01 12:30:00 | 25.50        | card           | 5            |
--- | 2        | 101         | 2024-03-02 19:15:00 | 32.00        | app            | 4            |
--- | 3        | 101         | 2024-03-03 13:45:00 | 28.75        | card           | 5            |
--- | 4        | 101         | 2024-03-04 20:30:00 | 41.00        | app            | NULL         |
--- | 5        | 102         | 2024-03-01 11:30:00 | 18.50        | cash           | 4            |
--- | 6        | 102         | 2024-03-02 12:00:00 | 22.00        | card           | 3            |
--- | 7        | 102         | 2024-03-03 15:30:00 | 19.75        | cash           | NULL         |
--- | 8        | 103         | 2024-03-01 19:00:00 | 55.00        | app            | 5            |
--- | 9        | 103         | 2024-03-02 20:45:00 | 48.50        | app            | 4            |
--- | 10       | 103         | 2024-03-03 18:30:00 | 62.00        | card           | 5            |
--- | 11       | 104         | 2024-03-01 10:00:00 | 15.00        | cash           | 3            |
--- | 12       | 104         | 2024-03-02 09:30:00 | 18.00        | cash           | 2            |
--- | 13       | 104         | 2024-03-03 16:00:00 | 20.00        | card           | 3            |
--- | 14       | 105         | 2024-03-01 12:15:00 | 30.00        | app            | 4            |
--- | 15       | 105         | 2024-03-02 13:00:00 | 35.50        | app            | 5            |
--- | 16       | 105         | 2024-03-03 11:45:00 | 28.00        | card           | 4            |
--- +----------+-------------+---------------------+--------------+----------------+--------------+
--- Output:
---
--- +-------------+--------------+----------------------+----------------+
--- | customer_id | total_orders | peak_hour_percentage | average_rating |
--- +-------------+--------------+----------------------+----------------+
--- | 103         | 3            | 100                  | 4.67           |
--- | 101         | 4            | 75                   | 4.67           |
--- | 105         | 3            | 100                  | 4.33           |
--- +-------------+--------------+----------------------+----------------+
--- Explanation:
---
--- Customer 101:
--- Total orders: 4 (at least 3) 
--- Peak hour orders: 3 out of 4 (12:30, 19:15, 13:45, and 20:30 are in peak hours)
--- Peak hour percentage: 3/4 = 75% (at least 60%) 
--- Rated orders: 3 out of 4 (75% rating completion) 
--- Average rating: (5+4+5)/3 = 4.67 (at least 4.0) 
--- Result: Golden hour customer
--- Customer 102:
--- Total orders: 3 (at least 3) 
--- Peak hour orders: 2 out of 3 (11:30, 12:00 are in peak hours; 15:30 is not)
--- Peak hour percentage: 2/3 = 66.67% (at least 60%) 
--- Rated orders: 2 out of 3 (66.67% rating completion) 
--- Average rating: (4+3)/2 = 3.5 (less than 4.0) 
--- Result: Not a golden hour customer (average rating too low)
--- Customer 103:
--- Total orders: 3 (at least 3) 
--- Peak hour orders: 3 out of 3 (19:00, 20:45, 18:30 all in evening peak)
--- Peak hour percentage: 3/3 = 100% (at least 60%) 
--- Rated orders: 3 out of 3 (100% rating completion) 
--- Average rating: (5+4+5)/3 = 4.67 (at least 4.0) 
--- Result: Golden hour customer
--- Customer 104:
--- Total orders: 3 (at least 3) 
--- Peak hour orders: 0 out of 3 (10:00, 09:30, 16:00 all outside peak hours)
--- Peak hour percentage: 0/3 = 0% (less than 60%) 
--- Result: Not a golden hour customer (insufficient peak hour orders)
--- Customer 105:
--- Total orders: 3 (at least 3) 
--- Peak hour orders: 3 out of 3 (12:15, 13:00, 11:45 all in lunch peak)
--- Peak hour percentage: 3/3 = 100% (at least 60%) 
--- Rated orders: 3 out of 3 (100% rating completion) 
--- Average rating: (4+5+4)/3 = 4.33 (at least 4.0) 
--- Result: Golden hour customer
--- The results table is ordered by average_rating DESC, then customer_id DESC.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    [customer_id],
    [total_orders],
    [peak_hour_percentage] = 
        CONVERT(DECIMAL(5,0), CONVERT(FLOAT, [peak_orders]) * 100 / [total_orders]),
    [average_rating]
FROM
(
    SELECT 
        [customer_id],
        [total_orders] = COUNT(*),
        [rated_orders] = SUM(CASE WHEN order_rating IS NOT NULL THEN 1 ELSE 0 END),
        [peak_orders] = SUM
        (
            CASE WHEN CONVERT(TIME, order_timestamp) BETWEEN '11:00' AND '14:00' THEN 1 
                 WHEN CONVERT(TIME, order_timestamp) BETWEEN '18:00' AND '21:00' THEN 1
                 ELSE 0 
                 END
        ),
        [average_rating] = CONVERT(DECIMAL(5,2), AVG(CONVERT(FLOAT, order_rating)))
    FROM 
        [restaurant_orders] AS A
    GROUP BY
        [customer_id]
) AS A
WHERE
    [total_orders] >= 3 
    AND [rated_orders] >= 0.5 * [total_orders]
    AND [peak_orders] >= 0.6 * [total_orders]
    AND [average_rating] >= 4.0
ORDER BY 
   [average_rating] DESC,
   [customer_id] DESC
;