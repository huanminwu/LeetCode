-----------------------------------------------------------------------
---  Leet code #1777. Product's Price for Each Store
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
---  | store       | enum    |
---  | price       | int     |
---  +-------------+---------+
---  (product_id,store) is the primary key for this table.
---  store is an ENUM of type ('store1', 'store2', 'store3') where each 
---  represents the store this product is available at.
---  price is the price of the product at this store.
--- 
---  Write an SQL query to find the price of each product in each store.
---
---  Return the result table in any order.
---
---  The query result format is in the following example:
--- 
---  Products table:
---  +-------------+--------+-------+
---  | product_id  | store  | price |
---  +-------------+--------+-------+
---  | 0           | store1 | 95    |
---  | 0           | store3 | 105   |
---  | 0           | store2 | 100   |
---  | 1           | store1 | 70    |
---  | 1           | store3 | 80    |
---  +-------------+--------+-------+
---  Result table:
---  +-------------+--------+--------+--------+
---  | product_id  | store1 | store2 | store3 |
---  +-------------+--------+--------+--------+
---  | 0           | 95     | 100    | 105    |
---  | 1           | 70     | null   | 80     |
---  +-------------+--------+--------+--------+
---  Product 0 price's are 95 for store1, 100 for store2 and, 105 for store3.
---  Product 1 price's are 70 for store1, 80 for store3 and, it's not sold 
---  in store2.
-----------------------------------------------------------------------
SELECT
    A.product_id,
	B.store1,
	C.store2,
	D.store3
FROM
(
	SELECT
		DISTINCT
		product_id
	FROM 
		Products
) AS A
LEFT OUTER JOIN
(
	SELECT
		product_id, 
		store1 = price
	FROM 
		Products
	WHERE 
	    store = 'store1'
) AS B
ON 
    A.product_id = B.product_id
LEFT OUTER JOIN
(
	SELECT
		product_id, 
		store2 = price
	FROM 
		Products
	WHERE 
	    store = 'store2'
) AS C
ON 
    A.product_id = C.product_id
LEFT OUTER JOIN
(
	SELECT
		product_id, 
		store3 = price
	FROM 
		Products
	WHERE 
	    store = 'store3'
) AS D
ON 
    A.product_id = D.product_id
