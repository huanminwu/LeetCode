-----------------------------------------------------------------------
--- LeetCode 3103. Find Trending Hashtags II 
--- 
--- Hard
---
--- SQL Schema
---
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
--- Every tweet may contain several hashtags.
---
--- Return the result table orderd by count of hashtag, hashtag in descending 
--- order.
---
--- The result format is in the following example.
---
--- Example 1:
--- Input:
--- Tweets table:
--- +---------+----------+------------------------------------------------------------+------------+
--- | user_id | tweet_id | tweet                                                      | tweet_date |
--- +---------+----------+------------------------------------------------------------+------------+
--- | 135     | 13       | Enjoying a great start to the day. #HappyDay #MorningVibes | 2024-02-01 |
--- | 136     | 14       | Another #HappyDay with good vibes! #FeelGood               | 2024-02-03 |
--- | 137     | 15       | Productivity peaks! #WorkLife #ProductiveDay               | 2024-02-04 |
--- | 138     | 16       | Exploring new tech frontiers. #TechLife #Innovation        | 2024-02-04 |
--- | 139     | 17       | Gratitude for today's moments. #HappyDay #Thankful         | 2024-02-05 |
--- | 140     | 18       | Innovation drives us. #TechLife #FutureTech                | 2024-02-07 |
--- | 141     | 19       | Connecting with nature's serenity. #Nature #Peaceful       | 2024-02-09 |
--- +---------+----------+------------------------------------------------------------+------------+
--- 
--- Output:
---
--- +-----------+-------+
--- | hashtag   | count |
--- +-----------+-------+
--- | #HappyDay | 3     |
--- | #TechLife | 2     |
--- | #WorkLife | 1     |
--- +-----------+-------+
---
--- Explanation:
---
--- #HappyDay: Appeared in tweet IDs 13, 14, and 17, with a total count of 3 
--- mentions.
--- #TechLife: Appeared in tweet IDs 16 and 18, with a total count of 2 
--- mentions.
--- #WorkLife: Appeared in tweet ID 15, with a total count of 1 mention.
--- Note: Output table is sorted in descending order by count and hashtag 
--- respectively.
---------------------------------------------------------------
WITH HashStart AS 
(
    SELECT
        user_id,
        tweet_id,
        tweet, 
        CHARINDEX('#', tweet, 1) AS StartPosition
	FROM 
        Tweets
    WHERE 
        CHARINDEX('#', tweet, 1) > 0
    UNION ALL
    SELECT
        user_id,
        tweet_id,
        tweet,
	    CHARINDEX('#', tweet, StartPosition + 1) AS StartPosition
    FROM 
        HashStart
    WHERE 
        CHARINDEX('#', tweet, StartPosition + 1) > 0
),
HashEnd AS
(
    SELECT 
        *, 
        EndPosition = CHARINDEX(' ', tweet, StartPosition + 1) 
    FROM 
        HashStart
),
HashTags AS
(
    SELECT 
        *, 
        [HASHTAG] = SUBSTRING(
            [tweet], 
            [StartPosition],  
            CASE 
                WHEN [EndPosition] = 0 
                THEN LEN(tweet) + 1 - [StartPosition] 
                ELSE [EndPosition] - [StartPosition] 
                END)
    FROM 
        HashEnd
)
SELECT
    TOP 3
    [hashtag],
    [count] = COUNT(*)
FROM
    HashTags
GROUP BY [hashtag]
ORDER BY 
    [count] DESC, [hashtag] DESC
;