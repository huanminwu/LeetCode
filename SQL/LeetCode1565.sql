-----------------------------------------------------------------------
---  Leet code #1565. Unique Orders and Customers Per Month
--- 
---  Easy
---
---  SQL Schema
---  Table: Orders
---
---  +---------------+---------+
---  | Column Name   | Type    |
---  +---------------+---------+
---  | order_id      | int     |
---  | order_date    | date    |
---  | customer_id   | int     |
---  | invoice       | int     |
---  +---------------+---------+
---  order_id is the primary key for this table.
---  This table contains information about the orders made by customer_id.
--- 
---  Write an SQL query to find the number of unique orders and the number of 
---  unique customers with invoices > $20 for each different month.
---
---  Return the result table sorted in any order.
--- 
---  The query result format is in the following example:
---
---  Orders
---  +----------+------------+-------------+------------+
---  | order_id | order_date | customer_id | invoice    |
---  +----------+------------+-------------+------------+
---  | 1        | 2020-09-15 | 1           | 30         |
---  | 2        | 2020-09-17 | 2           | 90         |
---  | 3        | 2020-10-06 | 3           | 20         |
---  | 4        | 2020-10-20 | 3           | 21         |
---  | 5        | 2020-11-10 | 1           | 10         |
---  | 6        | 2020-11-21 | 2           | 15         |
---  | 7        | 2020-12-01 | 4           | 55         |
---  | 8        | 2020-12-03 | 4           | 77         |
---  | 9        | 2021-01-07 | 3           | 31         |
---  | 10       | 2021-01-15 | 2           | 20         |
---  +----------+------------+-------------+------------+
---
---  Result table:
---  +---------+-------------+----------------+
---  | month   | order_count | customer_count |
---  +---------+-------------+----------------+
---  | 2020-09 | 2           | 2              |
---  | 2020-10 | 1           | 1              |
---  | 2020-12 | 2           | 1              |
---  | 2021-01 | 1           | 1              |
---  +---------+-------------+----------------+
---  In September 2020 we have two orders from 2 different customers with 
---  invoices > $20.
---  In October 2020 we have two orders from 1 customer, and only one of 
---  the two orders has invoice > $20.
---  In November 2020 we have two orders from 2 different customers but 
---  invoices < $20, so we don't include that month.
---  In December 2020 we have two orders from 1 customer both with 
---  invoices > $20.
---  In January 2021 we have two orders from 2 different customers, but 
---  only one of them with invoice > $20.
-----------------------------------------------------------------------
SELECT
    month = SUBSTRING(CONVERT(varchar, order_date, 23), 1, 7),
    order_count = COUNT(DISTINCT order_id),
    customer_count = COUNT(DISTINCT customer_id)
FROM
    Orders AS A
WHERE 
    invoice > 20
GROUP BY
    SUBSTRING(CONVERT(varchar, order_date, 23), 1, 7)
;
