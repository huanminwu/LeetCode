-----------------------------------------------------------------------
---  Leet code #1613. Find the Missing IDs
--- 
---  Medium
---
---  SQL Schema
---  Table: Customers
---
---  +---------------+---------+
---  | Column Name   | Type    |
---  +---------------+---------+
---  | customer_id   | int     |
---  | customer_name | varchar |
---  +---------------+---------+
---  customer_id is the primary key for this table.
---  Each row of this table contains the name and the id customer.
--- 
---  Write an SQL query to find the missing customer IDs. The missing IDs are 
---  ones that are not in the Customers table but are in the range between 1 
---  and the maximum customer_id present in the table.
---
---  Notice that the maximum customer_id will not exceed 100.
---  Return the result table ordered by ids in ascending order.
---
---  The query result format is in the following example.
--- 
---  Customer table:
---  +-------------+---------------+
---  | customer_id | customer_name |
---  +-------------+---------------+
---  | 1           | Alice         |
---  | 4           | Bob           |
---  | 5           | Charlie       |
---  +-------------+---------------+
---
---  Result table:
---  +-----+
---  | ids |
---  +-----+
---  | 2   |
---  | 3   |
---  +-----+
---  The maximum customer_id present in the table is 5, so in the range [1,5], 
---  IDs 2 and 3 are missing from the table.
-----------------------------------------------------------------------
/* Write your T-SQL query statement below */
WITH x AS (SELECT n FROM (VALUES (0),(1),(2),(3),(4),(5),(6),(7),(8),(9)) v(n))
SELECT
    ids = A.ordinal
FROM
(
    SELECT ordinal = ones.n + 10*tens.n + 100*hundreds.n 
    FROM x ones,     x tens,      x hundreds
) AS A
LEFT OUTER JOIN 
(
    SELECT
        customer_id
    FROM
        Customers
) AS B
ON 
    A.ordinal = B.customer_id
WHERE
    A.ordinal > 0 AND B.customer_id IS NULL AND
    A.ordinal <= (SELECT MAX (customer_id) FROM Customers)
ORDER BY
   ids
;

