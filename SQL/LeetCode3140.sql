-----------------------------------------------------------------------
--- LeetCode 3140. Consecutive Available Seats II
--- 
--- Medium
---
--- SQL Schema
--- Pandas Schema
--- Table: Cinema
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | seat_id     | int  |
--- | free        | bool |
--- +-------------+------+
--- seat_id is an auto-increment column for this table.
--- Each row of this table indicates whether the ith seat is 
--- free or not. 1 means free while 0 means occupied.
--- Write a solution to find the length of longest consecutive 
--- sequence of available seats in the cinema.
---
--- Note:
--- 
--- There will always be at most one longest consecutive sequence.
--- If there are multiple consecutive sequences with the same length, 
--- include all of them in the output.
--- Return the result table ordered by first_seat_id in ascending order.
---
--- The result format is in the following example.
--- 
--- Example:
--- Input:
--- Cinema table:
--- 
--- +---------+------+
--- | seat_id | free |
--- +---------+------+
--- | 1       | 1    |
--- | 2       | 0    |
--- | 3       | 1    |
--- | 4       | 1    |
--- | 5       | 1    |
--- +---------+------+
--- Output:
---
--- +-----------------+----------------+-----------------------+
--- | first_seat_id   | last_seat_id   | consecutive_seats_len |
--- +-----------------+----------------+-----------------------+
--- | 3               | 5              | 3                     |
--- +-----------------+----------------+-----------------------+
--- Explanation:
---
--- Longest consecutive sequence of available seats starts from seat 3 and 
--- ends at seat 5 with a length of 3.
--- Output table is ordered by first_seat_id in ascending order.
---------------------------------------------------------------
SELECT
    first_seat_id,
    last_seat_id,
    consecutive_seats_len
FROM
(
    SELECT
        first_seat_id = MIN([seat_id]),
        last_seat_id = MAX([seat_id]),
        consecutive_seats_len = MAX([seat_id]) - MIN([seat_id]) + 1,
        RN = RANK() OVER(ORDER BY MAX([seat_id]) - MIN([seat_id]) + 1 DESC)
    FROM
    (
        SELECT
            [seat_id],
            offset = [seat_id] - [free_seats_id]
        FROM
        (
            SELECT
                [seat_id],
                free_seats_id = (SELECT SUM(CONVERT(INT, free)) FROM [Cinema] WHERE seat_id <= A.seat_id)
            FROM
                [Cinema] AS A
            WHERE free = 1
        ) AS T
    ) AS T
    GROUP BY offset
) AS T
WHERE RN = 1
ORDER BY first_seat_id
;
