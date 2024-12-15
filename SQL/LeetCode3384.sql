-----------------------------------------------------------------------
--- LeetCode 3384. Team Dominance by Pass Success
--- 
--- Hard
---
--- Topics
--- SQL Schema
--- Pandas Schema
--- Table: Teams
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | player_id   | int     |
--- | team_name   | varchar | 
--- +-------------+---------+
--- player_id is the unique key for this table.
--- Each row contains the unique identifier for player and the name of one of 
--- the teams participating in that match.
---
--- Table: Passes
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | pass_from   | int     |
--- | time_stamp  | varchar |
--- | pass_to     | int     |
--- +-------------+---------+
--- (pass_from, time_stamp) is the primary key for this table.
--- pass_from is a foreign key to player_id from Teams table.
--- Each row represents a pass made during a match, time_stamp represents 
--- the time in minutes (00:00-90:00) when the pass was made,
--- pass_to is the player_id of the player receiving the pass.
---
--- Write a solution to calculate the dominance score for each team in both 
--- halves of the match. The rules are as follows:
---
--- A match is divided into two halves: first half (00:00-45:00 minutes) and 
--- second half (45:01-90:00 minutes)
--- The dominance score is calculated based on successful and intercepted 
--- passes:
--- When pass_to is a player from the same team: +1 point
--- When pass_to is a player from the opposing team (interception): -1 point
--- A higher dominance score indicates better passing performance
--- Return the result table ordered by team_name and half_number in ascending 
--- order.
---
--- The result format is in the following example.
---
--- Example:
--- 
--- Input:
--- Teams table:
---
--- +------------+-----------+
--- | player_id  | team_name |
--- +------------+-----------+
--- | 1          | Arsenal   |
--- | 2          | Arsenal   |
--- | 3          | Arsenal   |
--- | 4          | Chelsea   |
--- | 5          | Chelsea   |
--- | 6          | Chelsea   |
--- +------------+-----------+
--- Passes table:
---
--- +-----------+------------+---------+
--- | pass_from | time_stamp | pass_to |
--- +-----------+------------+---------+
--- | 1         | 00:15      | 2       |
--- | 2         | 00:45      | 3       |
--- | 3         | 01:15      | 1       |
--- | 4         | 00:30      | 1       |
--- | 2         | 46:00      | 3       |
--- | 3         | 46:15      | 4       |
--- | 1         | 46:45      | 2       |
--- | 5         | 46:30      | 6       |
--- +-----------+------------+---------+
--- Output:
---
--- +-----------+-------------+-----------+
--- | team_name | half_number | dominance |
--- +-----------+-------------+-----------+
--- | Arsenal   | 1           | 3         |
--- | Arsenal   | 2           | 1         |
--- | Chelsea   | 1           | -1        |
--- | Chelsea   | 2           | 1         |
--- +-----------+-------------+-----------+
--- Explanation:
---
--- First Half (00:00-45:00):
--- Arsenal's passes:
--- 1 → 2 (00:15): Successful pass (+1)
--- 2 → 3 (00:45): Successful pass (+1)
--- 3 → 1 (01:15): Successful pass (+1)
--- Chelsea's passes:
--- 4 → 1 (00:30): Intercepted by Arsenal (-1)
--- Second Half (45:01-90:00):
--- Arsenal's passes:
--- 2 → 3 (46:00): Successful pass (+1)
--- 3 → 4 (46:15): Intercepted by Chelsea (-1)
--- 1 → 2 (46:45): Successful pass (+1)
--- Chelsea's passes:
--- 5 → 6 (46:30): Successful pass (+1)
--- The results are ordered by team_name and then half_number
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    [team_name],
    [half_number],
    [dominance] = SUM(score)
FROM
(
    SELECT
        team_name = pass_from, 
        half_number,
        score = CASE WHEN pass_from = pass_to THEN 1 ELSE -1 END
    FROM
    (
        SELECT 
            pass_from = B.team_name, 
            half_number = CASE WHEN time_stamp <= '45:00' THEN 1 ELSE 2 END,
            pass_to = C.team_name
        FROM 
            Passes AS A
        INNER JOIN
            Teams AS B
        ON
            A.pass_from = B.player_id
        INNER JOIN
            Teams AS C
        ON
            A.pass_to = C.player_id
    ) AS T
) AS T
GROUP BY
    [team_name],
    [half_number]
ORDER BY 
    [team_name];
