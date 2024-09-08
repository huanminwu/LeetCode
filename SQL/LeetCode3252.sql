-----------------------------------------------------------------------
--- LeetCode 3252. Premier League Table Ranking II
--- 
--- Medium
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
--- Write a solution to calculate the points, position, and tier for each team 
--- in the league. Points are calculated as follows:
---
--- 3 points for a win
--- 1 point for a draw
--- 0 points for a loss
--- Note: Teams with the same points must be assigned the same position.
---
--- Tier ranking:
---
--- Divide the league into 3 tiers based on points:
--- Tier 1: Top 33% of teams
--- Tier 2: Middle 33% of teams
--- Tier 3: Bottom 34% of teams
--- In case of ties at tier boundaries, place tied teams in the higher tier.
--- Return the result table ordered by points in descending, and then by 
--- team_name in ascending order.
---
--- The query result format is in the following example.
---
--- Example:
---
--- Input:
---
--- TeamStats table:
---
--- +---------+-------------------+----------------+------+-------+--------+
--- | team_id | team_name         | matches_played | wins | draws | losses |
--- +---------+-------------------+----------------+------+-------+--------+
--- | 1       | Chelsea           | 22             | 13   | 2     | 7      |
--- | 2       | Nottingham Forest | 27             | 6    | 6     | 15     |
--- | 3       | Liverpool         | 17             | 1    | 8     | 8      |
--- | 4       | Aston Villa       | 20             | 1    | 6     | 13     |
--- | 5       | Fulham            | 31             | 18   | 1     | 12     |
--- | 6       | Burnley           | 26             | 6    | 9     | 11     |
--- | 7       | Newcastle United  | 33             | 11   | 10    | 12     |
--- | 8       | Sheffield United  | 20             | 18   | 2     | 0      |
--- | 9       | Luton Town        | 5              | 4    | 0     | 1      |
--- | 10      | Everton           | 14             | 2    | 6     | 6      |
--- +---------+-------------------+----------------+------+-------+--------+
--- Output:
---
--- +-------------------+--------+----------+---------+
--- | team_name         | points | position | tier    |
--- +-------------------+--------+----------+---------+
--- | Sheffield United  | 56     | 1        | Tier 1  |
--- | Fulham            | 55     | 2        | Tier 1  |
--- | Newcastle United  | 43     | 3        | Tier 1  |
--- | Chelsea           | 41     | 4        | Tier 1  |
--- | Burnley           | 27     | 5        | Tier 2  |
--- | Nottingham Forest | 24     | 6        | Tier 2  |
--- | Everton           | 12     | 7        | Tier 2  |
--- | Luton Town        | 12     | 7        | Tier 2  |
--- | Liverpool         | 11     | 9        | Tier 3  |
--- | Aston Villa       | 9      | 10       | Tier 3  |
--- +-------------------+--------+----------+---------+
--- Explanation:
---
--- Sheffield United has 56 points (18 wins * 3 points + 2 draws * 1 point) 
--- and is in position 1.
--- Fulham has 55 points (18 wins * 3 points + 1 draw * 1 point) and is in 
--- position 2.
--- Newcastle United has 43 points (11 wins * 3 points + 10 draws * 1 point) 
--- and is in position 3.
--- Chelsea has 41 points (13 wins * 3 points + 2 draws * 1 point) and is in 
--- position 4.
--- Burnley has 27 points (6 wins * 3 points + 9 draws * 1 point) and is in 
--- position 5.
--- Nottingham Forest has 24 points (6 wins * 3 points + 6 draws * 1 point) 
--- and is in position 6.
--- Everton and Luton Town both have 12 points, with Everton having 2 wins * 
--- 3 points + 6 draws * 1 point, and Luton Town having 4 wins * 3 points. 
--- Both teams share position 7.
--- Liverpool has 11 points (1 win * 3 points + 8 draws * 1 point) and is in 
--- position 9.
--- Aston Villa has 9 points (1 win * 3 points + 6 draws * 1 point) and is in 
--- position 10.
--- Tier Calculation:
---
--- Tier 1: The top 33% of teams based on points. Sheffield United, Fulham, 
--- Newcastle United, and Chelsea fall into Tier 1.
--- Tier 2: The middle 33% of teams. Burnley, Nottingham Forest, Everton, and 
--- Luton Town fall into Tier 2.
--- Tier 3: The bottom 34% of teams. Liverpool and Aston Villa fall into Tier 3.
---------------------------------------------------------------
/* Write your T-SQL query statement below */

SELECT
    team_name,
    points,
    position,
    tier = 
        CASE WHEN position <= CEILING((SELECT COUNT(*) FROM TeamStats) *0.33) THEN 'Tier 1'
             WHEN position <= CEILING((SELECT COUNT(*) FROM TeamStats) *0.66) THEN 'Tier 2'
             ELSE 'Tier 3'
             END
FROM
(
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
) AS T
ORDER BY 
    position, team_name
;
