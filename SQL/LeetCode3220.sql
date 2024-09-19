-----------------------------------------------------------------------
--- LeetCode 3220. Odd and Even Transactions
--- 
--- Medium
--- SQL Schema
--- Pandas Schema
--- Table: transactions
---
--- +------------------+------+
--- | Column Name      | Type | 
--- +------------------+------+
--- | transaction_id   | int  |
--- | amount           | int  |
--- | transaction_date | date |
--- +------------------+------+
--- The transactions_id column uniquely identifies each row in this table.
--- Each row of this table contains the transaction id, amount and transaction 
--- date.
--- Write a solution to find the sum of amounts for odd and even transactions 
--- for each day. If there are no odd or even transactions for a specific 
--- date, display as 0.
---
--- Return the result table ordered by transaction_date in ascending order.
---
--- The result format is in the following example.
---
---
--- Example:
---
--- Input:
--- 
--- transactions table:
---
--- +----------------+--------+------------------+
--- | transaction_id | amount | transaction_date |
--- +----------------+--------+------------------+
--- | 1              | 150    | 2024-07-01       |
--- | 2              | 200    | 2024-07-01       |
--- | 3              | 75     | 2024-07-01       |
--- | 4              | 300    | 2024-07-02       |
--- | 5              | 50     | 2024-07-02       |
--- | 6              | 120    | 2024-07-03       |
--- +----------------+--------+------------------+
---
--- Output:
---
--- +------------------+---------+----------+
--- | transaction_date | odd_sum | even_sum |
--- +------------------+---------+----------+
--- | 2024-07-01       | 75      | 350      |
--- | 2024-07-02       | 0       | 350      |
--- | 2024-07-03       | 0       | 120      |
--- +------------------+---------+----------+
---  
--- Explanation:
---
--- For transaction dates:
--- 2024-07-01:
--- Sum of amounts for odd transactions: 75
--- Sum of amounts for even transactions: 150 + 200 = 350
--- 2024-07-02:
--- Sum of amounts for odd transactions: 0
--- Sum of amounts for even transactions: 300 + 50 = 350
--- 2024-07-03:
--- Sum of amounts for odd transactions: 0
--- Sum of amounts for even transactions: 120
--- Note: The output table is ordered by transaction_date in ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT 
    transaction_date,
    odd_sum = SUM(CASE WHEN amount % 2 = 1 THEN amount ELSE 0 END),
    even_sum = SUM(CASE WHEN amount % 2 = 0 THEN amount ELSE 0 END)
FROM transactions
GROUP BY 
    transaction_date
;