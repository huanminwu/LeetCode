-----------------------------------------------------------------------
--- Leet code 2173. Longest Winning Streak
---
--- Hard
--- SQL Schema
--- Table: Matches
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | player_id   | int  |
--- | match_day   | date |
--- | result      | enum |
--- +-------------+------+
--- (player_id, match_day) is the primary key for this table.
--- Each row of this table contains the ID of a player, the day of the match 
--- they played, and the result of that match.
--- The result column is an ENUM type of ('Win', 'Draw', 'Lose').
--- 
--- The winning streak of a player is the number of consecutive wins 
--- uninterrupted by draws or losses.
---
--- Write an SQL query to count the longest winning streak for each player.
---
--- Return the result table in any order.
---
--- The query result format is in the following example.
--- 
--- Example 1:
--- Input: 
--- Matches table:
--- +-----------+------------+--------+
--- | player_id | match_day  | result |
--- +-----------+------------+--------+
--- | 1         | 2022-01-17 | Win    |
--- | 1         | 2022-01-18 | Win    |
--- | 1         | 2022-01-25 | Win    |
--- | 1         | 2022-01-31 | Draw   |
--- | 1         | 2022-02-08 | Win    |
--- | 2         | 2022-02-06 | Lose   |
--- | 2         | 2022-02-08 | Lose   |
--- | 3         | 2022-03-30 | Win    |
--- +-----------+------------+--------+
--- Output: 
--- +-----------+----------------+
--- | player_id | longest_streak |
--- +-----------+----------------+
--- | 1         | 3              |
--- | 2         | 0              |
--- | 3         | 1              |
--- +-----------+----------------+
--- Explanation: 
--- Player 1:
--- From 2022-01-17 to 2022-01-25, player 1 won 3 consecutive matches.
--- On 2022-01-31, player 1 had a draw.
--- On 2022-02-08, player 1 won a match.
--- The longest winning streak was 3 matches.
---
--- Player 2:
--- From 2022-02-06 to 2022-02-08, player 2 lost 2 consecutive matches.
--- The longest winning streak was 0 matches.
---
--- Player 3:
--- On 2022-03-30, player 3 won a match.
--- The longest winning streak was 1 match.
---------------------------------------------------------------
WITH MatchesPlayers AS
(
    SELECT
        player_id,
		Win = CASE WHEN result = 'Win' THEN 1 ELSE 0 END,
		RN = ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY match_day)
	FROM
	    Matches
)
SELECT
    A.player_id,
    longest_streak = ISNULL (B.longest_streak, 0)
FROM
(
    SELECT
        DISTINCT
        player_id 
    FROM
        MatchesPlayers
) AS A
LEFT OUTER JOIN
(
    SELECT
        player_id,
        longest_streak = MAX(Win_Day - Lose_Day)
    FROM
    (
        SELECT
            player_id,
	        Win,
	        Win_Day = RN,
	        Lose_Day = ISNULL((SELECT MAX(RN) FROM MatchesPlayers WHERE Win = 0 AND RN < A.RN AND player_id = A.player_id), 0)
        FROM 
            MatchesPlayers AS A
        WHERE 
            Win = 1
    ) AS T
    GROUP BY
        player_id
) AS B
ON 
   A.player_id = B.player_id
