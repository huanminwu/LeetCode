-----------------------------------------------------------------------
---  Leet code #1633. Percentage of Users Attended a Contest
--- 
---  Easy
---
---  SQL Schema
---  Table: Users
---  +-------------+---------+
---  | Column Name | Type    |
---  +-------------+---------+
---  | user_id     | int     |
---  | user_name   | varchar |
---  +-------------+---------+
---  user_id is the primary key for this table.
---  Each row of this table contains the name and the id of a user.
--- 
---
---  Table: Register
---  +-------------+---------+
---  | Column Name | Type    |
---  +-------------+---------+
---  | contest_id  | int     |
---  | user_id     | int     |
---  +-------------+---------+
---  (contest_id, user_id) is the primary key for this table.
---  Each row of this table contains the id of a user and the contest they 
---  registered into.
--- 
---  Write an SQL query to find the percentage of the users registered in 
---  each contest rounded to two decimals.
---
---  Return the result table ordered by percentage in descending order. In 
---  case of a tie, order it by contest_id in ascending order.
---
---  The query result format is in the following example.
---
---  Users table:
---  +---------+-----------+
---  | user_id | user_name |
---  +---------+-----------+
---  | 6       | Alice     |
---  | 2       | Bob       |
---  | 7       | Alex      |
---  +---------+-----------+
---
---  Register table:
---  +------------+---------+
---  | contest_id | user_id |
---  +------------+---------+
---  | 215        | 6       |
---  | 209        | 2       |
---  | 208        | 2       |
---  | 210        | 6       |
---  | 208        | 6       |
---  | 209        | 7       |
---  | 209        | 6       |
---  | 215        | 7       |
---  | 208        | 7       |
---  | 210        | 2       |
---  | 207        | 2       |
---  | 210        | 7       |
---  +------------+---------+
---
---  Result table:
---  +------------+------------+
---  | contest_id | percentage |
---  +------------+------------+
---  | 208        | 100.0      |
---  | 209        | 100.0      |
---  | 210        | 100.0      |
---  | 215        | 66.67      |
---  | 207        | 33.33      |
---  +------------+------------+
---  All the users registered in contests 208, 209, and 210. The percentage 
---  is 100% and we sort them in the answer table by contest_id in ascending 
---  order.
----  Alice and Alex registered in contest 215 and the percentage is 
---  ((2/3) * 100) = 66.67%
---  Bob registered in contest 207 and the percentage is ((1/3) * 100) = 33.33%
-----------------------------------------------------------------------
SELECT
    contest_id,
    percentage = ROUND(CONVERT(FLOAT, A.users) / B.users * 100, 2)
FROM
(
    SELECT
        contest_id,
        users = COUNT(*)
    FROM
        Register
    GROUP BY
        contest_id
) AS A
CROSS JOIN
(
    SELECT users = COUNT(*)
    FROM Users
) AS B
ORDER BY
    percentage DESC, contest_id ASC
;