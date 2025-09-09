-----------------------------------------------------------------------
--- LeetCode 3642. Find Books with Polarized Opinions
---
--- Easy
---
--- SQL Schema
--- Pandas Schema
--- Table: books
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | book_id     | int     |
--- | title       | varchar |
--- | author      | varchar |
--- | genre       | varchar |
--- | pages       | int     |
--- +-------------+---------+
--- book_id is the unique ID for this table.
--- Each row contains information about a book including its genre and page 
--- count.
--- Table: reading_sessions
---
--- +----------------+---------+
--- | Column Name    | Type    |
--- +----------------+---------+
--- | session_id     | int     |
--- | book_id        | int     |
--- | reader_name    | varchar |
--- | pages_read     | int     |
--- | session_rating | int     |
--- +----------------+---------+
--- session_id is the unique ID for this table.
--- Each row represents a reading session where someone read a portion of a 
--- book. session_rating is on a scale of 1-5.
--- Write a solution to find books that have polarized opinions - books that 
--- receive both very high ratings and very low ratings from different readers.
---
--- A book has polarized opinions if it has at least one rating >= 4 and at 
--- least one rating <= 2
--- Only consider books that have at least 5 reading sessions
--- Calculate the rating spread as (highest_rating - lowest_rating)
--- Calculate the polarization score as the number of extreme ratings 
--- (ratings <= 2 or >= 4) divided by total sessions
--- Only include books where polarization score >= 0.6 
--- (at least 60% extreme ratings)
--- Return the result table ordered by polarization score in descending 
--- order, then by title in descending order.
---
--- The result format is in the following example.
---
--- 
--- Example:
--- Input:
--- books table:
---
--- +---------+------------------------+---------------+----------+-------+
--- | book_id | title                  | author        | genre    | pages |
--- +---------+------------------------+---------------+----------+-------+
--- | 1       | The Great Gatsby       | F. Scott      | Fiction  | 180   |
--- | 2       | To Kill a Mockingbird  | Harper Lee    | Fiction  | 281   |
--- | 3       | 1984                   | George Orwell | Dystopian| 328   |
--- | 4       | Pride and Prejudice    | Jane Austen   | Romance  | 432   |
--- | 5       | The Catcher in the Rye | J.D. Salinger | Fiction  | 277   |
--- +---------+------------------------+---------------+----------+-------+
--- reading_sessions table:
---
--- +------------+---------+-------------+------------+----------------+
--- | session_id | book_id | reader_name | pages_read | session_rating |
--- +------------+---------+-------------+------------+----------------+
--- | 1          | 1       | Alice       | 50         | 5              |
--- | 2          | 1       | Bob         | 60         | 1              |
--- | 3          | 1       | Carol       | 40         | 4              |
--- | 4          | 1       | David       | 30         | 2              |
--- | 5          | 1       | Emma        | 45         | 5              |
--- | 6          | 2       | Frank       | 80         | 4              |
--- | 7          | 2       | Grace       | 70         | 4              |
--- | 8          | 2       | Henry       | 90         | 5              |
--- | 9          | 2       | Ivy         | 60         | 4              |
--- | 10         | 2       | Jack        | 75         | 4              |
--- | 11         | 3       | Kate        | 100        | 2              |
--- | 12         | 3       | Liam        | 120        | 1              |
--- | 13         | 3       | Mia         | 80         | 2              |
--- | 14         | 3       | Noah        | 90         | 1              |
--- | 15         | 3       | Olivia      | 110        | 4              |
--- | 16         | 3       | Paul        | 95         | 5              |
--- | 17         | 4       | Quinn       | 150        | 3              |
--- | 18         | 4       | Ruby        | 140        | 3              |
--- | 19         | 5       | Sam         | 80         | 1              |
--- | 20         | 5       | Tara        | 70         | 2              |
--- +------------+---------+-------------+------------+----------------+
--- Output:
--- 
--- +---------+------------------+---------------+-----------+-------+---------------+--------------------+
--- | book_id | title            | author        | genre     | pages | rating_spread | polarization_score |
--- +---------+------------------+---------------+-----------+-------+---------------+--------------------+
--- | 1       | The Great Gatsby | F. Scott      | Fiction   | 180   | 4             | 1.00               |
--- | 3       | 1984             | George Orwell | Dystopian | 328   | 4             | 1.00               |
--- +---------+------------------+---------------+-----------+-------+---------------+--------------------+
--- Explanation:
---
--- The Great Gatsby (book_id = 1):
--- Has 5 reading sessions (meets minimum requirement)
--- Ratings: 5, 1, 4, 2, 5
--- Has ratings >= 4: 5, 4, 5 (3 sessions)
--- Has ratings <= 2: 1, 2 (2 sessions)
--- Rating spread: 5 - 1 = 4
--- Extreme ratings (<=2 or >=4): All 5 sessions (5, 1, 4, 2, 5)
--- Polarization score: 5/5 = 1.00 (>= 0.6, qualifies)
--- 1984 (book_id = 3):
--- Has 6 reading sessions (meets minimum requirement)
--- Ratings: 2, 1, 2, 1, 4, 5
--- Has ratings >= 4: 4, 5 (2 sessions)
--- Has ratings <= 2: 2, 1, 2, 1 (4 sessions)
--- Rating spread: 5 - 1 = 4
--- Extreme ratings (<=2 or >=4): All 6 sessions (2, 1, 2, 1, 4, 5)
--- Polarization score: 6/6 = 1.00 (>= 0.6, qualifies)
--- Books not included:
--- To Kill a Mockingbird (book_id = 2): All ratings are 4-5, no low 
--- ratings (<=2)
--- Pride and Prejudice (book_id = 4): Only 2 sessions (< 5 minimum)
--- The Catcher in the Rye (book_id = 5): Only 2 sessions (< 5 minimum)
--- The result table is ordered by polarization score in descending order, 
--- then by book title in descending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT 
    book_id,
    title,
    author,
    genre,
    pages,
    rating_spread,
    polarization_score
FROM
(
    SELECT
        A.book_id,
        B.title,
        B.author,
        B.genre,
        B.pages,
        rating_spread = A.highest_rating - A.lowest_rating,
        polarization_score = CONVERT(decimal(5, 2), CONVERT(float, A.high_rating + A.low_rating) / A.session_count),
        A.high_rating,
        A.low_rating,
        A.session_count
    FROM
    (
        SELECT 
            book_id,
            high_rating = SUM(CASE WHEN session_rating >= 4 THEN 1 ELSE 0 END),
            low_rating = SUM(CASE WHEN session_rating <=2 THEN 1 ELSE 0 END),
            highest_rating = MAX(session_rating),
            lowest_rating = MIN(session_rating),
            session_count = COUNT(*)
        FROM 
            reading_sessions AS A
        GROUP bY
            book_id
    ) AS A
    INNER JOIN
       books AS B
    ON
        A.book_id = B.book_id
) AS T
WHERE
    session_count >= 5 AND high_rating > 0 AND low_rating > 0 AND polarization_score >= 0.6
ORDER BY 
    polarization_score DESC, title DESC
;