-----------------------------------------------------------------------
--- LeetCode 3390. Longest Team Pass Streak
--- 
--- Hard
---
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
--- (pass_from, time_stamp) is the unique key for this table.
--- pass_from is a foreign key to player_id from Teams table.
--- Each row represents a pass made during a match, time_stamp represents 
--- the time in minutes (00:00-90:00) when the pass was made,
--- pass_to is the player_id of the player receiving the pass.
--- Write a solution to find the longest successful pass streak for each 
--- team during the match. The rules are as follows:
---
--- A successful pass streak is defined as consecutive passes where:
--- Both the pass_from and pass_to players belong to the same team
--- A streak breaks when either:
--- The pass is intercepted (received by a player from the opposing team)
--- Return the result table ordered by team_name in ascending order.
---
--- The result format is in the following example.
---
--- Example:
---
--- Input:
--- Teams table:
--- +-----------+-----------+
--- | player_id | team_name |
--- +-----------+-----------+
--- | 1         | Arsenal   |
--- | 2         | Arsenal   |
--- | 3         | Arsenal   |
--- | 4         | Arsenal   |
--- | 5         | Chelsea   |
--- | 6         | Chelsea   |
--- | 7         | Chelsea   |
--- | 8         | Chelsea   |
--- +-----------+-----------+
--- Passes table:
---
--- +-----------+------------+---------+
--- | pass_from | time_stamp | pass_to |
--- +-----------+------------+---------+
--- | 1         | 00:05      | 2       |
--- | 2         | 00:07      | 3       |
--- | 3         | 00:08      | 4       |
--- | 4         | 00:10      | 5       |
--- | 6         | 00:15      | 7       |
--- | 7         | 00:17      | 8       |
--- | 8         | 00:20      | 6       |
--- | 6         | 00:22      | 5       |
--- | 1         | 00:25      | 2       |
--- | 2         | 00:27      | 3       |
--- +-----------+------------+---------+
--- Output:
---
--- +-----------+----------------+
--- | team_name | longest_streak |
--- +-----------+----------------+
--- | Arsenal   | 3              |
--- | Chelsea   | 4              |
--- +-----------+----------------+
--- Explanation:
---
--- Arsenal's streaks:
--- First streak: 3 passes (1→2→3→4) ended when player 4 passed to Chelsea's 
--- player 5
--- Second streak: 2 passes (1→2→3)
--- Longest streak = 3
--- Chelsea's streaks:
--- First streak: 3 passes (6→7→8→6→5)
--- Longest streak = 4
---------------------------------------------------------------
/* Write your T-SQL query statement below */
WITH Team_Score AS
(
    SELECT
        team_name = pass_from, 
        time_stamp,
        score = CASE WHEN pass_from = pass_to THEN 1 ELSE 0 END,
        RN = ROW_NUMBER() OVER (PARTITION BY pass_from ORDER BY time_stamp)
    FROM
    (
        SELECT 
            pass_from = B.team_name, 
            time_stamp,
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
)
SELECT
    team_name,
    longest_streak = MAX(streak)
FROM
(
    SELECT
        team_name,
        period_id = RN - sum_score,
        streak = COUNT(*)
    FROM
    (
        SELECT 
            A.team_name,
            A.RN,
            sum_score = SUM(B.score)
        FROM 
            Team_Score AS A
        LEFT OUTER JOIN 
            Team_Score AS B
        ON
            A.team_name = B.team_name
        WHERE
            A.RN >= B.RN AND
            A.score = 1
        GROUP BY
            A.team_name,
            A.RN
    ) AS T   
    GROUP BY
        team_name,
        RN - sum_score
) AS T
GROUP BY team_name
;