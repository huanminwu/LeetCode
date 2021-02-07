-----------------------------------------------------------------------
---  Leet code #1729. Find Followers Count
--- 
---  Easy
--- 
---  SQL Schema
---  Table: Followers
---  
---  +-------------+------+
---  | Column Name | Type |
---  +-------------+------+
---  | user_id     | int  |
---  | follower_id | int  |
---  +-------------+------+
---  (user_id, follower_id) is the primary key for this table.
---  This table contains the IDs of a user and a follower in a social media 
---  app where the follower follows the user.
---  Write an SQL query that will, for each user, return the number of 
---  followers.
---
---  Return the result table ordered by user_id.
---
---  The query result format is in the following example:
--- 
---  Followers table:
---  +---------+-------------+
---  | user_id | follower_id |
---  +---------+-------------+
---  | 0       | 1           |
---  | 1       | 0           |
---  | 2       | 0           |
---  | 2       | 1           |
---  +---------+-------------+
---  Result table:
---  +---------+----------------+
---  | user_id | followers_count|
---  +---------+----------------+
---  | 0       | 1              |
---  | 1       | 1              |
---  | 2       | 2              |
---  +---------+----------------+
---  The followers of 0 are {1}
---  The followers of 1 are {0}
---  The followers of 2 are {0,1}
-----------------------------------------------------------------------
SELECT
    user_id,
    followers_count = COUNT(*)
FROM 
    Followers 
GROUP BY
    user_id
;
