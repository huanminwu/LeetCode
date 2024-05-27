-----------------------------------------------------------------------
--- LeetCode 3150. Invalid Tweets II
--- 
--- Easy
---
--- Topics
--- SQL Schema
--- Pandas Schema
--- Table: Tweets
---
--- +----------------+---------+
--- | Column Name    | Type    |
--- +----------------+---------+
--- | tweet_id       | int     |
--- | content        | varchar |
--- +----------------+---------+
--- tweet_id is the primary key (column with unique values) for this table.
--- This table contains all the tweets in a social media app.
--- Write a solution to find invalid tweets. A tweet is considered invalid 
--- if it meets any of the following criteria:
---
--- It exceeds 140 characters in length.
--- It has more than 3 mentions.
--- It includes more than 3 hashtags.
--- Return the result table ordered by tweet_id in ascending order.
---
--- The result format is in the following example.
---
--- Example:
--- 
--- Input:
---
--- Tweets table:
---
---  +----------+-----------------------------------------------------------------------------------+
---  | tweet_id | content                                                                           |
---  +----------+-----------------------------------------------------------------------------------+
---  | 1        | Traveling, exploring, and living my best life @JaneSmith @SaraJohnson @LisaTaylor |
---  |          | @MikeBrown #Foodie #Fitness #Learning                                             | 
---  | 2        | Just had the best dinner with friends! #Foodie #Friends #Fun                      |
---  | 4        | Working hard on my new project #Work #Goals #Productivity #Fun                    |
---  +----------+-----------------------------------------------------------------------------------+
---  
--- Output:
---
---  +----------+
---  | tweet_id |
---  +----------+
---  | 1        |
---  | 4        |
---  +----------+
---  
--- Explanation:
---
--- tweet_id 1 contains 4 mentions.
--- tweet_id 4 contains 4 hashtags.
--- Output table is ordered by tweet_id in ascending order.
---------------------------------------------------------------
SELECT
    tweet_id
FROM
    Tweets
WHERE
    LEN(content) > 140 OR
    LEN(content) - LEN(REPLACE(content, '#', '')) > 3 OR
    LEN(content) - LEN(REPLACE(content, '@', '')) > 3
    