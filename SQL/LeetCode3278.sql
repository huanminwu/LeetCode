-----------------------------------------------------------------------
--- LeetCode 3278. Find Candidates for Data Scientist Position II
--- 
--- Medium
--- 
--- SQL Schema
--- Pandas Schema
--- Table: Candidates
--- 
--- +--------------+---------+ 
--- | Column Name  | Type    | 
--- +--------------+---------+ 
--- | candidate_id | int     | 
--- | skill        | varchar |
--- | proficiency  | int     |
--- +--------------+---------+
--- (candidate_id, skill) is the unique key for this table.
--- Each row includes candidate_id, skill, and proficiency level (1-5).
---
--- Table: Projects
---
--- +--------------+---------+ 
--- | Column Name  | Type    | 
--- +--------------+---------+ 
--- | project_id   | int     | 
--- | skill        | varchar |
--- | importance   | int     |
--- +--------------+---------+
--- (project_id, skill) is the primary key for this table.
--- Each row includes project_id, required skill, and its importance (1-5) 
--- for the project.
--- Leetcode is staffing for multiple data science projects. Write a solution 
--- to find the best candidate for each project based on the following 
--- criteria:
---
--- Candidates must have all the skills required for a project.
--- Calculate a score for each candidate-project pair as follows:
--- Start with 100 points
--- Add 10 points for each skill where proficiency > importance
--- Subtract 5 points for each skill where proficiency < importance
--- Include only the top candidate (highest score) for each project. If 
--- there’s a tie, choose the candidate with the lower candidate_id. If 
--- there is no suitable candidate for a project, do not return that project.
---
--- Return a result table ordered by project_id in ascending order.
---
--- The result format is in the following example.
---
--- 
--- 
--- Example:
---
--- Input:
--- 
--- Candidates table:
--- 
--- +--------------+-----------+-------------+
--- | candidate_id | skill     | proficiency |
--- +--------------+-----------+-------------+
--- | 101          | Python    | 5           |
--- | 101          | Tableau   | 3           |
--- | 101          | PostgreSQL| 4           |
--- | 101          | TensorFlow| 2           |
--- | 102          | Python    | 4           |
--- | 102          | Tableau   | 5           |
--- | 102          | PostgreSQL| 4           |
--- | 102          | R         | 4           |
--- | 103          | Python    | 3           |
--- | 103          | Tableau   | 5           |
--- | 103          | PostgreSQL| 5           |
--- | 103          | Spark     | 4           |
--- +--------------+-----------+-------------+
--- Projects table:
---
--- +-------------+-----------+------------+
--- | project_id  | skill     | importance |
--- +-------------+-----------+------------+
--- | 501         | Python    | 4          |
--- | 501         | Tableau   | 3          |
--- | 501         | PostgreSQL| 5          |
--- | 502         | Python    | 3          |
--- | 502         | Tableau   | 4          |
--- | 502         | R         | 2          |
--- +-------------+-----------+------------+
--- Output:
--- 
--- --- +-------------+--------------+-------+
--- | project_id  | candidate_id | score |
--- +-------------+--------------+-------+
--- | 501         | 101          | 105   |
--- | 502         | 102          | 130   |
--- +-------------+--------------+-------+
--- Explanation:
---
--- For Project 501, Candidate 101 has the highest score of 105. All other 
--- candidates have the same score but Candidate 101 has the lowest 
--- candidate_id among them.
--- For Project 502, Candidate 102 has the highest score of 130.
--- The output table is ordered by project_id in ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    project_id,
    candidate_id,
    score = 100 + score
FROM
(
    SELECT 
        A.project_id,
        A.candidate_id,
        score = A.score,
        RN = ROW_NUMBER() OVER (PARTITION BY A.project_id ORDER BY A.score DESC, A.candidate_id ASC)
    FROM
    (
        SELECT
            project_id,
            candidate_id,
            score = SUM(score),
            [count] = COUNT(*)
        FROM
        (
            SELECT 
                A.project_id,
                B.candidate_id,
                score = 
                    CASE WHEN A.importance < B.proficiency THEN 10
                         WHEN A.importance > B.proficiency THEN -5
                         ELSE 0
                         END
            FROM
                Projects AS A
            INNER JOIN 
                Candidates AS B
            ON
                A.skill = B.skill
        ) AS T
        GROUP BY
            project_id, candidate_id
    ) AS A
    INNER JOIN 
    (
        SELECT
            project_id,
            [count] = COUNT(*)
        FROM
            Projects AS A
        GROUP BY
            project_id
    ) AS B
    ON
        A.project_id = B.project_id
    WHERE
        A.[count] = B.[count]
) AS T
WHERE RN = 1
;