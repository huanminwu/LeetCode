-----------------------------------------------------------------------
--- LeetCode 3087. Find Trending Hashtags
--- 
--- Medium
---
--- SQL Schema
--- Pandas Schema
--- Table: Tweets
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | user_id     | int     |
--- | tweet_id    | int     |
--- | tweet_date  | date    |
--- | tweet       | varchar |
--- +-------------+---------+
--- tweet_id is the primary key (column with unique values) for this table.
--- Each row of this table contains user_id, tweet_id, tweet_date and tweet.
--- Write a solution to find the top 3 trending hashtags in February 2024.
---
--- Return the result table orderd by count of hashtag, hastag in descending 
--- order.
---
--- The result format is in the following example.
--- 
--- Example 1:
---
--- Input:
--- Tweets table:
--- +---------+----------+----------------------------------------------+------------+
--- | user_id | tweet_id | tweet                                        | tweet_date |
--- +---------+----------+----------------------------------------------+------------+
--- | 135     | 13       | Enjoying a great start to the day! #HappyDay | 2024-02-01 |
--- | 136     | 14       | Another #HappyDay with good vibes!           | 2024-02-03 |
--- | 137     | 15       | Productivity peaks! #WorkLife                | 2024-02-04 |
--- | 138     | 16       | Exploring new tech frontiers. #TechLife      | 2024-02-04 |
--- | 139     | 17       | Gratitude for today's moments. #HappyDay     | 2024-02-05 |
--- | 140     | 18       | Innovation drives us. #TechLife              | 2024-02-07 |
--- | 141     | 19       | Connecting with nature's serenity. #Nature   | 2024-02-09 |
--- +---------+----------+----------------------------------------------+------------+
--- 
--- Output:
---
--- +-----------+--------------+
--- | hashtag   | hashtag_count|
--- +-----------+--------------+
--- | #HappyDay | 3            |
--- | #TechLife | 2            |
--- | #WorkLife | 1            |
--- +-----------+--------------+
---
--- Explanation:
--- #HappyDay: Appeared in tweet IDs 13, 14, and 17, with a total count of 
--- 3 mentions.
--- #TechLife: Appeared in tweet IDs 16 and 18, with a total count of 2 
--- mentions.
--- #WorkLife: Appeared in tweet ID 15, with a total count of 1 mention.
--- Note: Output table is sorted in descending order by hashtag_count and 
--- hashtag respectively.
---------------------------------------------------------------
SELECT
    TOP 3
    [HASHTAG],
    [HASHTAG_COUNT] = COUNT(*)
FROM
(
    SELECT
        [tweet_id],
        [HASHTAG] = SUBSTRING(
            [tweet], 
            [hashtag_index],  
            CASE 
                WHEN [space_index] = 0 
                THEN LEN(tweet) + 1 - [hashtag_index] 
                ELSE [space_index] - [hashtag_index] 
                END)
    FROM
    (
        SELECT
            [tweet_id],
            [hashtag_index],
            [space_index] = CHARINDEX(' ', tweet, [hashtag_index] + 1),
            [tweet]
        FROM
        (
            SELECT
                [tweet_id],
                [hashtag_index] = PATINDEX('%#[^ ]%', tweet),
                [tweet]
            FROM
                [Tweets]
        ) AS T
    ) AS T
) AS T
GROUP BY [HASHTAG]
ORDER BY 
    [HASHTAG_COUNT] DESC, [HASHTAG] DESC
;
