-----------------------------------------------------------------------
--- LeetCode 3358. Books with NULL Ratings
--- 
--- Easy
---
--- Topics
--- SQL Schema
--- Pandas Schema
--- Table: books
---
--- +----------------+---------+
--- | Column Name    | Type    |
--- +----------------+---------+
--- | book_id        | int     |
--- | title          | varchar |
--- | author         | varchar |
--- | published_year | int     |
--- | rating         | decimal |
--- +----------------+---------+
--- book_id is the unique key for this table.
--- Each row of this table contains information about a book including its 
--- unique ID, title, author, publication year, and rating.
--- rating can be NULL, indicating that the book hasn't been rated yet.
--- Write a solution to find all books that have not been rated yet 
--- (i.e., have a NULL rating).
---
--- Return the result table ordered by book_id in ascending order.
---
--- The result format is in the following example.
--- 
--- Example:
--- Input:
--- books table:
--- 
--- +---------+------------------------+------------------+----------------+--------+
--- | book_id | title                  | author           | published_year | rating |
--- +---------+------------------------+------------------+----------------+--------+
--- | 1       | The Great Gatsby       | F. Scott         | 1925           | 4.5    |
--- | 2       | To Kill a Mockingbird  | Harper Lee       | 1960           | NULL   |
--- | 3       | Pride and Prejudice    | Jane Austen      | 1813           | 4.8    |
--- | 4       | The Catcher in the Rye | J.D. Salinger    | 1951           | NULL   |
--- | 5       | Animal Farm            | George Orwell    | 1945           | 4.2    |
--- | 6       | Lord of the Flies      | William Golding  | 1954           | NULL   |
--- +---------+------------------------+------------------+----------------+--------+
--- Output:

--- +---------+------------------------+------------------+----------------+
--- | book_id | title                  | author           | published_year |
--- +---------+------------------------+------------------+----------------+
--- | 2       | To Kill a Mockingbird  | Harper Lee       | 1960           |
--- | 4       | The Catcher in the Rye | J.D. Salinger    | 1951           |
--- | 6       | Lord of the Flies      | William Golding  | 1954           |
--- +---------+------------------------+------------------+----------------+
--- Explanation:
---
--- The books with book_id 2, 4, and 6 have NULL ratings.
--- These books are included in the result table.
--- The other books (book_id 1, 3, and 5) have ratings and are not included.
--- The result is ordered by book_id in ascending order
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    [book_id],
    [title],
    [author],
    [published_year]
FROM
    books
WHERE
    rating IS NULL
ORDER BY
    [book_id]
;