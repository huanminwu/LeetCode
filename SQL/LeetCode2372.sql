-----------------------------------------------------------------------
--- LeetCode 2372. Calculate the Influence of Each Salesperson
--- 
--- Medium
--- SQL Schema
--- Table: Salesperson
---
--- +----------------+---------+
--- | Column Name    | Type    |
--- +----------------+---------+
--- | salesperson_id | int     |
--- | name           | varchar |
--- +----------------+---------+
--- salesperson_id is the primary key for this table.
--- Each row in this table shows the ID of a salesperson.
--- 
---
--- Table: Customer
--- 
--- +----------------+------+
--- | Column Name    | Type |
--- +----------------+------+
--- | customer_id    | int  |
--- | salesperson_id | int  |
--- +----------------+------+
--- customer_id is the primary key for this table.
--- salesperson_id is a foreign key from the Salesperson table.
--- Each row in this table shows the ID of a customer and the ID of the 
--- salesperson. 
---
--- Table: Sales
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | sale_id     | int  |
--- | customer_id | int  |
--- | price       | int  |
--- +-------------+------+
--- sale_id is the primary key for this table.
--- customer_id is a foreign key from the Customer table.
--- Each row in this table shows ID of a customer and the price they paid for 
--- the sale with sale_id.
--- 
--- Write an SQL query to report the sum of prices paid by the customers of 
--- each salesperson. If a salesperson does not have any customers, the total 
--- value should be 0.
---
--- Return the result table in any order.
---
--- The query result format is shown in the following example.
--- 
--- Example 1:
--- Input: 
--- Salesperson table:
--- +----------------+-------+
--- | salesperson_id | name  |
--- +----------------+-------+
--- | 1              | Alice |
--- | 2              | Bob   |
--- | 3              | Jerry |
--- +----------------+-------+
--- Customer table:
--- +-------------+----------------+
--- | customer_id | salesperson_id |
--- +-------------+----------------+
--- | 1           | 1              |
--- | 2           | 1              |
--- | 3           | 2              |
--- +-------------+----------------+
--- Sales table:
--- +---------+-------------+-------+
--- | sale_id | customer_id | price |
--- +---------+-------------+-------+
--- | 1       | 2           | 892   |
--- | 2       | 1           | 354   |
--- | 3       | 3           | 988   |
--- | 4       | 3           | 856   |
--- +---------+-------------+-------+
--- Output: 
--- +----------------+-------+-------+
--- | salesperson_id | name  | total |
--- +----------------+-------+-------+
--- | 1              | Alice | 1246  |
--- | 2              | Bob   | 1844  |
--- | 3              | Jerry | 0     |
--- +----------------+-------+-------+
--- Explanation: 
--- Alice is the salesperson for customers 1 and 2.
---  - Customer 1 made one purchase with 354.
---  - Customer 2 made one purchase with 892.
--- The total for Alice is 354 + 892 = 1246.
---
--- Bob is the salesperson for customers 3.
---  - Customer 1 made one purchase with 988 and 856.
--- The total for Bob is 988 + 856 = 1844.
---
--- Jerry is not the salesperson of any customer.
--- The total for Jerry is 0.
---------------------------------------------------------------
SELECT
    A.salesperson_id,
	A.name,
    total = SUM(ISNULL(C.price, 0))
FROM
	Salesperson AS A
LEFT OUTER JOIN
    Customer AS B
ON
    A.salesperson_id = B.salesperson_id
LEFT OUTER JOIN
    Sales AS C
ON
    B.customer_id = C.customer_id
GROUP BY
    A.salesperson_id,
	A.name
;