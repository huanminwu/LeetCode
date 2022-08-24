-----------------------------------------------------------------------
--- LeetCode 2362. Generate the Invoice
--- 
--- Hard
--- SQL Schema
--- Table: Products
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | product_id  | int  |
--- | price       | int  |
--- +-------------+------+
--- product_id is the primary key for this table.
--- Each row in this table shows the ID of a product and the price of one unit.
--- 
---
--- Table: Purchases
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | invoice_id  | int  |
--- | product_id  | int  |
--- | quantity    | int  |
--- +-------------+------+
--- (invoice_id, product_id) is the primary key for this table.
--- Each row in this table shows the quantity ordered from one product in an 
--- invoice. 
---
--- Write an SQL query to show the details of the invoice with the highest 
--- price. If two or more invoices have the same price, return the details 
--- of the one with the smallest invoice_id.
---
--- Return the result table in any order.
---
--- The query result format is shown in the following example.
---
--- Example 1:
---
--- Input: 
--- Products table:
--- +------------+-------+
--- | product_id | price |
--- +------------+-------+
--- | 1          | 100   |
--- | 2          | 200   |
--- +------------+-------+
--- Purchases table:
--- +------------+------------+----------+
--- | invoice_id | product_id | quantity |
--- +------------+------------+----------+
--- | 1          | 1          | 2        |
--- | 3          | 2          | 1        |
--- | 2          | 2          | 3        |
--- | 2          | 1          | 4        |
--- | 4          | 1          | 10       |
--- +------------+------------+----------+
--- Output: 
--- +------------+----------+-------+
--- | product_id | quantity | price |
--- +------------+----------+-------+
--- | 2          | 3        | 600   |
--- | 1          | 4        | 400   |
--- +------------+----------+-------+
--- Explanation: 
--- Invoice 1: price = (2 * 100) = $200
--- Invoice 2: price = (4 * 100) + (3 * 200) = $1000
--- Invoice 3: price = (1 * 200) = $200
--- Invoice 4: price = (10 * 100) = $1000
---
--- The highest price is $1000, and the invoices with the highest prices 
--- are 2 and 4. We return the details of the one with the smallest ID, 
--- which is invoice 2.
---------------------------------------------------------------
WITH Invoice_Sum AS
(
	SELECT 
	    A.invoice_id,
		total_price = SUM(A.quantity  * B.price)
	FROM 
		Purchases AS A
	INNER JOIN 
	    Products AS B
	ON
	    A.product_id  = B.product_id
	GROUP BY
	    A.invoice_id
),
Invoice_Rank AS
(
	SELECT 
	    invoice_id,
		invoice_rank = ROW_NUMBER() OVER (ORDER BY total_price DESC, invoice_id ASC)
	FROM 
		Invoice_Sum
)
SELECT
    A.product_id,
	A.quantity,
    price = A.quantity * B.price
FROM
	Purchases AS A
INNER JOIN
    Products AS B
ON
    A.product_id  = B.product_id
WHERE A.invoice_id IN
(
	SELECT invoice_id FROM Invoice_Rank WHERE invoice_rank = 1
)
;