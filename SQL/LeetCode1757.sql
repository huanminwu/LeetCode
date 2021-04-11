-----------------------------------------------------------------------
---  Leet code #1757. Recyclable and Low Fat Products
--- 
---  Easy
---
---  SQL Schema
---  Table: Products
--- 
---  +-------------+---------+
---  | Column Name | Type    |
---  +-------------+---------+
---  | product_id  | int     |
---  | low_fats    | enum    |
---  | recyclable  | enum    |
---  +-------------+---------+
---  product_id is the primary key for this table.
---  low_fats is an ENUM of type ('Y', 'N') where 'Y' means this product 
---  is low fat and 'N' means it is not.
---  recyclable is an ENUM of types ('Y', 'N') where 'Y' means this product 
---  is recyclable and 'N' means it is not.
--- 
---  Write an SQL query to find the ids of products that are both low fat 
---  and recyclable.
---
---  Return the result table in any order.
---  
---  The query result format is in the following example:
--- 
---  Products table:
---  +-------------+----------+------------+
---  | product_id  | low_fats | recyclable |
---  +-------------+----------+------------+
---  | 0           | Y        | N          |
---  | 1           | Y        | Y          |
---  | 2           | N        | Y          |
---  | 3           | Y        | Y          |
---  | 4           | N        | N          |
---  +-------------+----------+------------+
---  Result table:
---  +-------------+
---  | product_id  |
---  +-------------+
---  | 1           |
---  | 3           |
---  +-------------+
---  Only products 1 and 3 are both low fat and recyclable.
-----------------------------------------------------------------------
SELECT
    product_id
FROM
    Products
WHERE
    low_fats = 'Y' AND recyclable = 'Y' 
;	
