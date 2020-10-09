-----------------------------------------------------------------------
---  Leet code #1596. The Most Frequently Ordered Products for Each Customer
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
---  | name          | varchar |
---  +---------------+---------+
---  customer_id is the primary key for this table.
---  This table contains information about the customers.
--- 
---  Table: Orders
---
---  +---------------+---------+
---  | Column Name   | Type    |
---  +---------------+---------+
---  | order_id      | int     |
---  | order_date    | date    |
---  | customer_id   | int     |
---  | product_id    | int     |
---  +---------------+---------+
---  order_id is the primary key for this table.
---  This table contains information about the orders made by customer_id.
---  No customer will order the same product more than once in a single day.
--- 
---  Table: Products
---  +---------------+---------+
---  | Column Name   | Type    |
---  +---------------+---------+
---  | product_id    | int     |
---  | product_name  | varchar |
---  | price         | int     |
---  +---------------+---------+
---  product_id is the primary key for this table.
---  This table contains information about the products.
--- 
---  Write an SQL query to find the most frequently ordered product(s) 
---  for each customer.
---
---  The result table should have the product_id and product_name for 
---  each customer_id who ordered at least one order. Return the result table 
---  in any order.
---
---  The query result format is in the following example:
---
---  Customers
---  +-------------+-------+
---  | customer_id | name  |
---  +-------------+-------+
---  | 1           | Alice |
---  | 2           | Bob   |
---  | 3           | Tom   |
---  | 4           | Jerry |
---  | 5           | John  |
---  +-------------+-------+
---
---  Orders
---  +----------+------------+-------------+------------+
---  | order_id | order_date | customer_id | product_id |
---  +----------+------------+-------------+------------+
---  | 1        | 2020-07-31 | 1           | 1          |
---  | 2        | 2020-07-30 | 2           | 2          |
---  | 3        | 2020-08-29 | 3           | 3          |
---  | 4        | 2020-07-29 | 4           | 1          |
---  | 5        | 2020-06-10 | 1           | 2          |
---  | 6        | 2020-08-01 | 2           | 1          |
---  | 7        | 2020-08-01 | 3           | 3          |
---  | 8        | 2020-08-03 | 1           | 2          |
---  | 9        | 2020-08-07 | 2           | 3          |
---  | 10       | 2020-07-15 | 1           | 2          |
---  +----------+------------+-------------+------------+
---
---  Products
---  +------------+--------------+-------+
---  | product_id | product_name | price |
---  +------------+--------------+-------+
---  | 1          | keyboard     | 120   |
---  | 2          | mouse        | 80    |
---  | 3          | screen       | 600   |
---  | 4          | hard disk    | 450   |
---  +------------+--------------+-------+
---  Result table:
---  +-------------+------------+--------------+
---  | customer_id | product_id | product_name |
---  +-------------+------------+--------------+
---  | 1           | 2          | mouse        |
---  | 2           | 1          | keyboard     |
---  | 2           | 2          | mouse        |
---  | 2           | 3          | screen       |
---  | 3           | 3          | screen       |
---  | 4           | 1          | keyboard     |
---  +-------------+------------+--------------+
---
---  Alice (customer 1) ordered the mouse three times and the keyboard one 
---  time, so the mouse is the most frquently ordered product for them.
---  Bob (customer 2) ordered the keyboard, the mouse, and the screen one 
---  time, so those are the most frquently ordered products for them.
---  Tom (customer 3) only ordered the screen (two times), so that is the 
---  most frquently ordered product for them.
---  Jerry (customer 4) only ordered the keyboard (one time), so that is 
---  the most frquently ordered product for them.
---  John (customer 5) did not order anything, so we do not include them in 
---  the result table.
-----------------------------------------------------------------------
/* Write your T-SQL query statement below */

SELECT
    A.customer_id,
    A.product_id,
    B.product_name
FROM
(
    SELECT
        customer_id,
        product_id,
        orders,
        rank = RANK() OVER (PARTITION BY customer_id ORDER BY orders DESC) 
    FROM
    (
        SELECT
            customer_id,
            product_id,
            orders = SUM(1)
        FROM
            Orders AS A
        GROUP BY
            customer_id,
            product_id
    ) AS T
) AS A
INNER JOIN 
    Products AS B
ON 
    A.product_id = B.product_id
WHERE
    A.rank = 1
;