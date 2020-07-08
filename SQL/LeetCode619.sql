-----------------------------------------------------------------------
--  LeetCode 619. Biggest Single Number
--  Easy
--
--  SQL Schema
--
--  Table my_numbers contains many numbers in column num including duplicated 
--  ones.
--  Can you write a SQL query to find the biggest number, which only appears 
--  once.
--  +---+
--  |num|
--  +---+
--  | 8 |
--  | 8 |
--  | 3 |
--  | 3 |
--  | 1 |
--  | 4 |
--  | 5 |
--  | 6 | 
--  For the sample data above, your query should return the following result: 
--  +---+
--  |num|
--  +---+
--  | 6 |
--  Note:
--  If there is no such number, just output null. 
--  ----------------------------------------------------------------
DECLARE  @biggestNumber BIGINT;
SELECT  @biggestNumber = num 
FROM 
(
    SELECT
        num,
        RANK() OVER (ORDER BY num DESC) AS Rank
    FROM 
        my_numbers
    GROUP BY
        num
    HAVING 
        COUNT(*) = 1
) AS T
WHERE Rank = 1
SELECT  @biggestNumber AS num
;
