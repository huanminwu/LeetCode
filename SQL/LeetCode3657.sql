-----------------------------------------------------------------------
--- LeetCode 3657. Find Loyal Customers
---
--- Medium
---
--- SQL Schema
--- Pandas Schema
--- Table: customer_transactions
---
--- +------------------+---------+
--- | Column Name      | Type    | 
--- +------------------+---------+
--- | transaction_id   | int     |
--- | customer_id      | int     |
--- | transaction_date | date    |
--- | amount           | decimal |
--- | transaction_type | varchar |
--- +------------------+---------+
--- transaction_id is the unique identifier for this table.
--- transaction_type can be either 'purchase' or 'refund'.
--- Write a solution to find loyal customers. A customer is considered loyal 
--- if they meet ALL the following criteria:
---
--- Made at least 3 purchase transactions.
--- Have been active for at least 30 days.
--- Their refund rate is less than 20% .
--- Return the result table ordered by customer_id in ascending order.
---
--- The result format is in the following example.
---
--- 
--- Example:
--- Input:
--- customer_transactions table:
--- 
--- +----------------+-------------+------------------+--------+------------------+
--- | transaction_id | customer_id | transaction_date | amount | transaction_type |
--- +----------------+-------------+------------------+--------+------------------+
--- | 1              | 101         | 2024-01-05       | 150.00 | purchase         |
--- | 2              | 101         | 2024-01-15       | 200.00 | purchase         |
--- | 3              | 101         | 2024-02-10       | 180.00 | purchase         |
--- | 4              | 101         | 2024-02-20       | 250.00 | purchase         |
--- | 5              | 102         | 2024-01-10       | 100.00 | purchase         |
--- | 6              | 102         | 2024-01-12       | 120.00 | purchase         |
--- | 7              | 102         | 2024-01-15       | 80.00  | refund           |
--- | 8              | 102         | 2024-01-18       | 90.00  | refund           |
--- | 9              | 102         | 2024-02-15       | 130.00 | purchase         |
--- | 10             | 103         | 2024-01-01       | 500.00 | purchase         |
--- | 11             | 103         | 2024-01-02       | 450.00 | purchase         |
--- | 12             | 103         | 2024-01-03       | 400.00 | purchase         |
--- | 13             | 104         | 2024-01-01       | 200.00 | purchase         |
--- | 14             | 104         | 2024-02-01       | 250.00 | purchase         |
--- | 15             | 104         | 2024-02-15       | 300.00 | purchase         |
--- | 16             | 104         | 2024-03-01       | 350.00 | purchase         |
--- | 17             | 104         | 2024-03-10       | 280.00 | purchase         |
--- | 18             | 104         | 2024-03-15       | 100.00 | refund           |
--- +----------------+-------------+------------------+--------+------------------+
--- Output:
---
--- +-------------+
--- | customer_id |
--- +-------------+
--- | 101         |
--- | 104         |
--- +-------------+
--- Explanation:
---
--- Customer 101:
--- Purchase transactions: 4 (IDs: 1, 2, 3, 4) 
--- Refund transactions: 0
--- Refund rate: 0/4 = 0% (less than 20%) 
--- Active period: Jan 5 to Feb 20 = 46 days (at least 30 days) 
--- Qualifies as loyal 
--- Customer 102:
--- Purchase transactions: 3 (IDs: 5, 6, 9) 
--- Refund transactions: 2 (IDs: 7, 8)
--- Refund rate: 2/5 = 40% (exceeds 20%) 
--- Not loyal 
--- Customer 103:
--- Purchase transactions: 3 (IDs: 10, 11, 12) 
--- Refund transactions: 0
--- Refund rate: 0/3 = 0% (less than 20%) 
--- Active period: Jan 1 to Jan 3 = 2 days (less than 30 days) 
--- Not loyal 
--- Customer 104:
--- Purchase transactions: 5 (IDs: 13, 14, 15, 16, 17) 
--- Refund transactions: 1 (ID: 18)
--- Refund rate: 1/6 = 16.67% (less than 20%) 
--- Active period: Jan 1 to Mar 15 = 73 days (at least 30 days) 
--- Qualifies as loyal 
--- The result table is ordered by customer_id in ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    customer_id
FROM
(
    SELECT 
        customer_id,
        first_day = MIN(transaction_date),
        last_day = MAX(transaction_date),
        purchase = SUM(CASE WHEN transaction_type = 'purchase' THEN 1 ELSE 0 END),
        refund = SUM(CASE WHEN transaction_type = 'refund' THEN 1 ELSE 0 END)
    FROM 
        customer_transactions AS A
    GROUP bY
        customer_id
) AS A
WHERE
    DATEDIFF(DAY, first_day, last_day) >= 30 AND purchase >= 3 AND
    CONVERT(FLOAT, refund) / purchase <= 0.2
;