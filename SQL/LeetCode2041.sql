-----------------------------------------------------------------------
--- Leet code 2041. Accepted Candidates From the Interviews
--- 
--- Medium
--- 
--- SQL Schema
--- Table: Candidates
---
--- +--------------+----------+
--- | Column Name  | Type     |
--- +--------------+----------+
--- | candidate_id | int      |
--- | name         | varchar  |
--- | years_of_exp | int      |
--- | interview_id | int      |
--- +--------------+----------+
--- candidate_id is the primary key column for this table.
--- Each row of this table indicates the name of a candidate, their number of 
--- years of experience, and their interview ID.
---
--- Table: Rounds
---
--- +--------------+------+
--- | Column Name  | Type |
--- +--------------+------+
--- | interview_id | int  |
--- | round_id     | int  |
--- | score        | int  |
--- +--------------+------+
--- (interview_id, round_id) is the primary key column for this table.
--- Each row of this table indicates the score of one round of an interview.
---
--- Write an SQL query to report the IDs of the candidates who have at least 
--- two years of experience and the sum of the score of their interview rounds 
--- is strictly greater than 15.
---
--- Return the result table in any order.
---
--- The query result format is in the following example.
---
--- Example 1:
---
--- Input: 
--- Candidates table:
--- +--------------+---------+--------------+--------------+
--- | candidate_id | name    | years_of_exp | interview_id |
--- +--------------+---------+--------------+--------------+
--- | 11           | Atticus | 1            | 101          |
--- | 9            | Ruben   | 6            | 104          |
--- | 6            | Aliza   | 10           | 109          |
--- | 8            | Alfredo | 0            | 107          |
--- +--------------+---------+--------------+--------------+
---
--- Rounds table:
--- +--------------+----------+-------+
--- | interview_id | round_id | score |
--- +--------------+----------+-------+
--- | 109          | 3        | 4     |
--- | 101          | 2        | 8     |
--- | 109          | 4        | 1     |
--- | 107          | 1        | 3     |
--- | 104          | 3        | 6     |
--- | 109          | 1        | 4     |
--- | 104          | 4        | 7     |
--- | 104          | 1        | 2     |
--- | 109          | 2        | 1     |
--- | 104          | 2        | 7     |
--- | 107          | 2        | 3     |
--- | 101          | 1        | 8     |
--- +--------------+----------+-------+
--- Output: 
--- +--------------+
--- | candidate_id |
--- +--------------+
--- | 9            |
--- +--------------+
--- Explanation: 
--- Candidate 11: The total score is 16, and they have one year of 
--- experience. We do not include them in the result table because of 
--- their years of experience.
--- Candidate 9: The total score is 22, and they have six years of experience. 
--- We include them in the result table.
--- Candidate 6: The total score is 10, and they have ten years of experience. 
--- We do not include them in the result table because the score is not good 
--- enough.
--- Candidate 8: The total score is 6, and they have zero years of experience. 
--- We do not include them in the result table because of their years of 
--- experience and the score.
-------------------------------------------------------------------
SELECT
	A.candidate_id
FROM
    Candidates AS A
LEFT OUTER JOIN
(
    SELECT 
	    interview_id, 
        score = SUM(score)
    FROM 
        Rounds
    GROUP BY 
	    interview_id
) AS B
ON
    A.interview_id = B.interview_id
WHERE 
    A.years_of_exp >= 2 AND B.score > 15
;