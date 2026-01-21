-----------------------------------------------------------------------
--- Leet Code 3808. Find Emotionally Consistent Users
---
--- Medium
---
--- SQL Schema
--- Pandas Schema
--- Table: reactions
---
--- +--------------+---------+
--- | Column Name  | Type    |
--- +--------------+---------+
--- | user_id      | int     |
--- | content_id   | int     |
--- | reaction     | varchar |
--- +--------------+---------+
--- (user_id, content_id) is the primary key (unique value) for this table.
--- Each row represents a reaction given by a user to a piece of content.
--- Write a solution to identify emotionally consistent users based on 
--- the following requirements:
---
--- For each user, count the total number of reactions they have given.
--- Only include users who have reacted to at least 5 different content items.
--- A user is considered emotionally consistent if at least 60% of their 
--- reactions are of the same type.
--- Return the result table ordered by reaction_ratio in descending order 
--- and then by user_id in ascending order.
---
--- Note:
--- reaction_ratio should be rounded to 2 decimal places
--- The result format is in the following example.
---
--- Example:
--- Input:
--- reactions table:
---
--- +---------+------------+----------+
--- | user_id | content_id | reaction |
--- +---------+------------+----------+
--- | 1       | 101        | like     |
--- | 1       | 102        | like     |
--- | 1       | 103        | like     |
--- | 1       | 104        | wow      |
--- | 1       | 105        | like     |
--- | 2       | 201        | like     |
--- | 2       | 202        | wow      |
--- | 2       | 203        | sad      |
--- | 2       | 204        | like     |
--- | 2       | 205        | wow      |
--- | 3       | 301        | love     |
--- | 3       | 302        | love     |
--- | 3       | 303        | love     |
--- | 3       | 304        | love     |
--- | 3       | 305        | love     |
--- +---------+------------+----------+
--- Output:
---
--- +---------+-------------------+----------------+
--- | user_id | dominant_reaction | reaction_ratio |
--- +---------+-------------------+----------------+
--- | 3       | love              | 1.00           |
--- | 1       | like              | 0.80           |
--- +---------+-------------------+----------------+
--- Explanation:
---
--- User 1:
--- Total reactions = 5
--- like appears 4 times
--- reaction_ratio = 4 / 5 = 0.80
--- Meets the 60% consistency requirement
--- User 2:
--- Total reactions = 5
--- Most frequent reaction appears only 2 times
--- reaction_ratio = 2 / 5 = 0.40
--- Does not meet the consistency requirement
--- User 3:
--- Total reactions = 5
--- 'love' appears 5 times
--- reaction_ratio = 5 / 5 = 1.00
--- Meets the consistency requirement
--- The Results table is ordered by reaction_ratio in descending order, 
--- then by user_id in ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    A.[user_id],
    [dominant_reaction] = B.[reaction],
    [reaction_ratio] = CONVERT(DECIMAL(5,2), CONVERT(FLOAT, B.[reaction_count]) / A.[content_count])
FROM
(
    SELECT
        [user_id],
        [content_count] = COUNT(DISTINCT content_id)
    FROM
        [reactions]
    GROUP BY
        [user_id]
) AS A
INNER JOIN
(
    SELECT
        [user_id],
        [reaction],
        [reaction_count],
        RN = ROW_NUMBER() OVER (PARTITION BY [user_id] ORDER BY [reaction_count] DESC)
    FROM
    (
        SELECT
            [user_id],
            [reaction],
            [reaction_count] = COUNT(*)
        FROM
            [reactions]
        GROUP BY
            [user_id],
            [reaction]
    ) AS T
) AS B
ON
    A.[user_id] = B.[user_id]
WHERE 
    A.[content_count] >= 5 AND  
    CONVERT(DECIMAL(5,2), CONVERT(FLOAT, B.[reaction_count]) / A.[content_count]) >= 0.60
ORDER BY
    [reaction_ratio] DESC,
    [user_id] ASC
;