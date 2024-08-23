-----------------------------------------------------------------------
--- LeetCode 3246. Premier League Table Ranking
--- 
--- Easy
--- 
--- SQL Schema
--- Pandas Schema
--- Table: TeamStats
---
--- +------------------+---------+
--- | Column Name      | Type    |
--- +------------------+---------+
--- | team_id          | int     |
--- | team_name        | varchar |
--- | matches_played   | int     |
--- | wins             | int     |
--- | draws            | int     |
--- | losses           | int     |
--- +------------------+---------+
--- team_id is the unique key for this table.
--- This table contains team id, team name, matches_played, wins, draws, and 
--- losses.
--- Write a solution to calculate the points and rank for each team in the 
--- league. Points are calculated as follows:
---
--- 3 points for a win
--- 1 point for a draw
--- 0 points for a loss
--- Note: Teams with the same points must be assigned the same rank.
---
--- Return the result table ordered by points in descending, and then by 
--- team_name in ascending order.
---
--- The query result format is in the following example.
---
--- Example:
--- Input:
--- TeamStats table:
---
--- +---------+-----------------+----------------+------+-------+--------+
--- | team_id | team_name       | matches_played | wins | draws | losses |
--- +---------+-----------------+----------------+------+-------+--------+
--- | 1       | Manchester City | 10             | 6    | 2     | 2      |
--- | 2       | Liverpool       | 10             | 6    | 2     | 2      |
--- | 3       | Chelsea         | 10             | 5    | 3     | 2      |
--- | 4       | Arsenal         | 10             | 4    | 4     | 2      |
--- | 5       | Tottenham       | 10             | 3    | 5     | 2      |
--- +---------+-----------------+----------------+------+-------+--------+
--- Output:
---
--- +---------+-----------------+--------+----------+
--- | team_id | team_name       | points | position |
--- +---------+-----------------+--------+----------+
--- | 2       | Liverpool       | 20     | 1        |
--- | 1       | Manchester City | 20     | 1        |
--- | 3       | Chelsea         | 18     | 3        |
--- | 4       | Arsenal         | 16     | 4        |
--- | 5       | Tottenham       | 14     | 5        |
--- +---------+-----------------+--------+----------+
--- Explanation:
---
--- Manchester City and Liverpool both have 20 points (6 wins * 3 points + 
--- 2 draws * 1 point), so they share position 1.
--- Chelsea has 18 points (5 wins * 3 points + 3 draws * 1 point) and is 
--- position 3rd.
--- Arsenal has 16 points (4 wins * 3 points + 4 draws * 1 point) and is 
--- position 4th.
--- Tottenham has 14 points (3 wins * 3 points + 5 draws * 1 point) and is 
--- position 5th.
--- The output table is ordered by points in descending order, then by 
--- team_name in ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    team_id,
    team_name,
    points,
    position = RANK() OVER (ORDER BY points DESC)
FROM
(
    SELECT 
        team_id,
        team_name,
        points = wins * 3 + draws
    FROM
        TeamStats
) AS T
ORDER BY 
    position, team_name
;