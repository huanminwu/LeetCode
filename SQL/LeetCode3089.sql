-----------------------------------------------------------------------
--- LeetCode 3089. Find Bursty Behavior
--- 
--- Medium
--- SQL Schema
--- Pandas Schema
--- Table: Posts
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | post_id     | int     |
--- | user_id     | int     |
--- | post_date   | date    |
--- +-------------+---------+
--- post_id is the primary key (column with unique values) for this table.
--- Each row of this table contains post_id, user_id, and post_date.
--- Write a solution to find users who demonstrate bursty behavior in their 
--- posting patterns during February 2024. Bursty behavior is defined as any 
--- period of 7 consecutive days where a user's posting frequency is at least 
--- twice to their average weekly posting frequency for February 2024.
---
--- Note: Only include the dates from February 1 to February 28 in your 
--- analysis, which means you should count February as having exactly 4 
--- weeks.
---
--- Return the result table orderd by user_id in ascending order.
---
--- The result format is in the following example.
--- 
--- Example:
--- Input:
--- Posts table:
--- +---------+---------+------------+
--- | post_id | user_id | post_date  |
--- +---------+---------+------------+
--- | 1       | 1       | 2024-02-27 |
--- | 2       | 5       | 2024-02-06 |
--- | 3       | 3       | 2024-02-25 |
--- | 4       | 3       | 2024-02-14 |
--- | 5       | 3       | 2024-02-06 |
--- | 6       | 2       | 2024-02-25 |
--- +---------+---------+------------+
---
--- Output:
---
--- +---------+----------------+------------------+
--- | user_id | max_7day_posts | avg_weekly_posts |
--- +---------+----------------+------------------+
--- | 1       | 1              | 0.2500           |
--- | 2       | 1              | 0.2500           |
--- | 5       | 1              | 0.2500           |
--- +---------+----------------+------------------+
--- Explanation:
---
--- User 1: Made only 1 post in February, resulting in an average of 0.25 
--- posts per week and a max of 1 post in any 7-day period.
--- User 2: Also made just 1 post, with the same average and max 7-day 
--- posting frequency as User 1.
--- User 5: Like Users 1 and 2, User 5 made only 1 post throughout February, 
--- leading to the same average and max 7-day posting metrics.
--- User 3: Although User 3 made more posts than the others (3 posts), they 
--- did not reach twice the average weekly posts in their consecutive 7-day 
--- window, so they are not listed in the output.
--- Note: Output table is ordered by user_id in ascending order.
---------------------------------------------------------------
WITH Avg_User_Posts AS
(
    SELECT
        [user_id],
        [avg_weekly_posts] = CONVERT(decimal(18, 2), CONVERT(float, COUNT(*)) / 4)
    FROM
        [Posts]
    WHERE
        post_date BETWEEN '2024-02-01' AND '2024-02-28'
    GROUP BY
        [user_id]
),
Max_User_Post AS
(
    SELECT
        [user_id],
        [max_7day_posts] = max([count])
    FROM
    (
        SELECT
            [user_id],
            [post_date],
            [count] = 
            (
                SELECT COUNT(*) 
                FROM [Posts] 
                WHERE [user_id] = A.[user_id] AND [post_date] >= A.[post_date] 
                      AND [post_date] < DATEADD(DAY, 7,A.[post_date])
                      AND [post_date] BETWEEN '2024-02-01' AND '2024-02-28'
            )
        FROM 
            [Posts] AS A
        WHERE
            post_date BETWEEN '2024-02-01' AND '2024-02-28'
    ) AS T
    GROUP BY
        [user_id]
)
SELECT
    A.[user_id],
    A.[max_7day_posts],
    B.[avg_weekly_posts]
FROM
    Max_User_Post AS A
INNER JOIN
    Avg_User_Posts AS B
ON
    A.[user_id] = B.[user_id]
WHERE
    A.[max_7day_posts] >= 2 * B.[avg_weekly_posts]
ORDER BY [user_id]
;