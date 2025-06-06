-----------------------------------------------------------------------
--- LeetCode 3570. Find Books with No Available Copies
---
--- Easy
---
--- SQL Schema
--- Pandas Schema
--- Table: library_books
---
--- +------------------+---------+
--- | Column Name      | Type    |
--- +------------------+---------+
--- | book_id          | int     |
--- | title            | varchar |
--- | author           | varchar |
--- | genre            | varchar |
--- | publication_year | int     |
--- | total_copies     | int     |
--- +------------------+---------+
--- book_id is the unique identifier for this table.
--- Each row contains information about a book in the library, including the 
--- total number of copies owned by the library.
--- Table: borrowing_records
---
--- +---------------+---------+
--- | Column Name   | Type    |
--- +---------------+---------+
--- | record_id     | int     |
--- | book_id       | int     |
--- | borrower_name | varchar |
--- | borrow_date   | date    |
--- | return_date   | date    |
--- +---------------+---------+
--- record_id is the unique identifier for this table.
--- Each row represents a borrowing transaction and return_date is NULL if 
--- the book is currently borrowed and hasn't been returned yet.
--- Write a solution to find all books that are currently borrowed (not 
--- returned) and have zero copies available in the library.
---
--- A book is considered currently borrowed if there exists a borrowing 
--- record with a NULL return_date
--- Return the result table ordered by current borrowers in descending order, 
--- then by book title in ascending order.
---
--- The result format is in the following example.
---
--- Example:
--- Input:
--- library_books table:
--- +---------+------------------------+------------------+----------+------------------+--------------+
--- | book_id | title                  | author           | genre    | publication_year | total_copies |
--- +---------+------------------------+------------------+----------+------------------+--------------+
--- | 1       | The Great Gatsby       | F. Scott         | Fiction  | 1925             | 3            |
--- | 2       | To Kill a Mockingbird  | Harper Lee       | Fiction  | 1960             | 3            |
--- | 3       | 1984                   | George Orwell    | Dystopian| 1949             | 1            |
--- | 4       | Pride and Prejudice    | Jane Austen      | Romance  | 1813             | 2            |
--- | 5       | The Catcher in the Rye | J.D. Salinger    | Fiction  | 1951             | 1            |
--- | 6       | Brave New World        | Aldous Huxley    | Dystopian| 1932             | 4            |
--- +---------+------------------------+------------------+----------+------------------+--------------+
--- borrowing_records table:
---
--- +-----------+---------+---------------+-------------+-------------+
--- | record_id | book_id | borrower_name | borrow_date | return_date |
--- +-----------+---------+---------------+-------------+-------------+
--- | 1         | 1       | Alice Smith   | 2024-01-15  | NULL        |
--- | 2         | 1       | Bob Johnson   | 2024-01-20  | NULL        |
--- | 3         | 2       | Carol White   | 2024-01-10  | 2024-01-25  |
--- | 4         | 3       | David Brown   | 2024-02-01  | NULL        |
--- | 5         | 4       | Emma Wilson   | 2024-01-05  | NULL        |
--- | 6         | 5       | Frank Davis   | 2024-01-18  | 2024-02-10  |
--- | 7         | 1       | Grace Miller  | 2024-02-05  | NULL        |
--- | 8         | 6       | Henry Taylor  | 2024-01-12  | NULL        |
--- | 9         | 2       | Ivan Clark    | 2024-02-12  | NULL        |
--- | 10        | 2       | Jane Adams    | 2024-02-15  | NULL        |
--- +-----------+---------+---------------+-------------+-------------+
--- Output:
---
--- +---------+------------------+---------------+-----------+------------------+-------------------+
--- | book_id | title            | author        | genre     | publication_year | current_borrowers |
--- +---------+------------------+---------------+-----------+------------------+-------------------+
--- | 1       | The Great Gatsby | F. Scott      | Fiction   | 1925             | 3                 | 
--- | 3       | 1984             | George Orwell | Dystopian | 1949             | 1                 |
--- +---------+------------------+---------------+-----------+------------------+-------------------+
--- Explanation:
---
--- The Great Gatsby (book_id = 1):
--- Total copies: 3
--- Currently borrowed by Alice Smith, Bob Johnson, and Grace Miller 
--- (3 borrowers)
--- Available copies: 3 - 3 = 0
--- Included because available_copies = 0
--- 1984 (book_id = 3):
--- Total copies: 1
--- Currently borrowed by David Brown (1 borrower)
--- Available copies: 1 - 1 = 0
--- Included because available_copies = 0
--- Books not included:
--- To Kill a Mockingbird (book_id = 2): Total copies = 3, current 
--- borrowers = 2, available = 1
--- Pride and Prejudice (book_id = 4): Total copies = 2, current borrowers = 1, 
--- available = 1
--- The Catcher in the Rye (book_id = 5): Total copies = 1, current borrowers = 0, 
--- available = 1
--- Brave New World (book_id = 6): Total copies = 4, current borrowers = 1, 
--- available = 3
--- Result ordering:
--- The Great Gatsby appears first with 3 current borrowers
--- 1984 appears second with 1 current borrower
--- Output table is ordered by current_borrowers in descending order, then by 
--- book_title in 
--- ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    A.book_id,
    A.title,
    A.author,
    A.genre,
    A.publication_year,
    B.current_borrowers
FROM
    library_books AS A
INNER JOIN
(
    SELECT
        book_id,
        current_borrowers = COUNT(*)
    FROM
        borrowing_records
    WHERE
        return_date IS NULL
    GROUP BY 
        book_id
) AS B
ON
    A.book_id = B.book_id
WHERE
    A.total_copies = B.current_borrowers
ORDER BY 
    B.current_borrowers DESC,
    A.title ASC
;