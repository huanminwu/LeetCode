-----------------------------------------------------------------------
--- LeetCode 3401. Find Circular Gift Exchange Chains
--- 
--- Hard
---
--- SQL Schema
--- Pandas Schema
--- Table: SecretSanta
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | giver_id    | int  |
--- | receiver_id | int  |
--- | gift_value  | int  |
--- +-------------+------+
--- (giver_id, receiver_id) is the unique key for this table.   
--- Each row represents a record of a gift exchange between two employees, 
--- giver_id represents the employee who gives a gift, receiver_id represents 
--- the employee who receives the gift and gift_value represents the value of 
--- the gift given.  
--- Write a solution to find the total gift value and length of circular 
--- chains of Secret Santa gift exchanges:
---
--- A circular chain is defined as a series of exchanges where:
---
--- Each employee gives a gift to exactly one other employee.
--- Each employee receives a gift from exactly one other employee.
--- The exchanges form a continuous loop (e.g., employee A gives a gift to B, 
--- B gives to C, and C gives back to A).
--- Return the result ordered by the chain length and total gift value of the 
--- chain in descending order. 
---
--- The result format is in the following example.
---
--- Example:
---
--- Input:
---
--- SecretSanta table:
---
--- +----------+-------------+------------+
--- | giver_id | receiver_id | gift_value |
--- +----------+-------------+------------+
--- | 1        | 2           | 20         |
--- | 2        | 3           | 30         |
--- | 3        | 1           | 40         |
--- | 4        | 5           | 25         |
--- | 5        | 4           | 35         |
--- +----------+-------------+------------+
--- Output:
---
--- +----------+--------------+------------------+
--- | chain_id | chain_length | total_gift_value |
--- +----------+--------------+------------------+
--- | 1        | 3            | 90               |
--- | 2        | 2            | 60               |
--- +----------+--------------+------------------+
--- Explanation:
---
--- Chain 1 involves employees 1, 2, and 3:
--- Employee 1 gives a gift to 2, employee 2 gives a gift to 3, 
--- and employee 3 gives a gift to 1.
--- Total gift value for this chain = 20 + 30 + 40 = 90.
--- Chain 2 involves employees 4 and 5:
--- Employee 4 gives a gift to 5, and employee 5 gives a gift to 4.
--- Total gift value for this chain = 25 + 35 = 60.
--- The result table is ordered by the chain length and total gift 
--- value of the chain in descending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
WITH Recursion AS 
(
    SELECT 
        giver_id, 
        receiver_id, 
        1 AS [length], 
        gift_value 
    FROM SecretSanta
    UNION ALL
    SELECT 
        a.giver_id, 
        b.receiver_id, 
        a.[length] + 1 AS [leng], 
        a.gift_value + b.gift_value AS gift_value 
    FROM 
        Recursion a
    INNER JOIN 
        SecretSanta b 
    ON 
        a.giver_id <> a.receiver_id AND a.receiver_id = b.giver_id 
)
SELECT 
    RANK() OVER (ORDER BY chain_length DESC, total_gift_value DESC) AS chain_id, 
    chain_length, 
    total_gift_value 
FROM 
(
    SELECT 
        DISTINCT 
        length AS chain_length, 
        gift_value AS total_gift_value 
     FROM 
        Recursion 
     WHERE 
        giver_id = receiver_id
) T
