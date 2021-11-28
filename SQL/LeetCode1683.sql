-----------------------------------------------------------------------
---  Leet code #1683. Invalid Tweets
--- 
---  Easy
--- 
---  SQL Schema
---  Table: Tweets
--- 
---  +----------------+---------+
---  | Column Name    | Type    |
---  +----------------+---------+
---  | tweet_id       | int     |
---  | content        | varchar |
---  +----------------+---------+
---  tweet_id is the primary key for this table.
---  This table contains all the tweets in a social media app.
--- 
---  Write an SQL query to find the IDs of the invalid tweets. The tweet 
---  is invalid if the number of characters used in the content of the 
---  tweet is strictly greater than 15.
--- 
---  Return the result table in any order.
---  The query result format is in the following example:
---  
---  Tweets table:
---  +----------+----------------------------------+
---  | tweet_id | content                          |
---  +----------+----------------------------------+
---  | 1        | Vote for Biden                   |
---  | 2        | Let us make America great again! |
---  +----------+----------------------------------+
---  
---  Result table:
---  +----------+
---  | tweet_id |
---  +----------+
---  | 2        |
---  +----------+
---  Tweet 1 has length = 14. It is a valid tweet.
---  Tweet 2 has length = 32. It is an invalid tweet.
-----------------------------------------------------------------------
SELECT
    tweet_id
FROM
    Tweets
WHERE 
    LEN(content) > 15
;