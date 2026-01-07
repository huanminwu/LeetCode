-----------------------------------------------------------------------
--- Leet Code 3793. Find Users with High Token Usage
---
--- Easy
---
--- SQL Schema
--- Pandas Schema
--- Table: prompts
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | user_id     | int     |
--- | prompt      | varchar |
--- | tokens      | int     |
--- +-------------+---------+
--- (user_id, prompt) is the primary key (unique value) for this table.
--- Each row represents a prompt submitted by a user to an AI system along 
--- with the number of tokens consumed.
--- Write a solution to analyze AI prompt usage patterns based on the following
--- requirements:
---
--- For each user, calculate the total number of prompts they have submitted.
--- For each user, calculate the average tokens used per prompt (Rounded to 2 
--- decimal places).
--- Only include users who have submitted at least 3 prompts.
--- Only include users who have submitted at least one prompt with tokens 
--- greater than their own average token usage.
--- Return the result table ordered by average tokens in descending order, 
--- and then by user_id in ascending order.
---
--- The result format is in the following example.
--- 
--- Example:
--- 
--- Input:
--- prompts table:
--- 
--- +---------+--------------------------+--------+
--- | user_id | prompt                   | tokens |
--- +---------+--------------------------+--------+
--- | 1       | Write a blog outline     | 120    |
--- | 1       | Generate SQL query       | 80     |
--- | 1       | Summarize an article     | 200    |
--- | 2       | Create resume bullet     | 60     |
--- | 2       | Improve LinkedIn bio     | 70     |
--- | 3       | Explain neural networks  | 300    |
--- | 3       | Generate interview Q&A   | 250    |
--- | 3       | Write cover letter       | 180    |
--- | 3       | Optimize Python code     | 220    |
--- +---------+--------------------------+--------+
--- Output:
---
--- +---------+---------------+------------+
--- | user_id | prompt_count  | avg_tokens |
--- +---------+---------------+------------+
--- | 3       | 4             | 237.5      |
--- | 1       | 3             | 133.33     |
--- +---------+---------------+------------+
--- Explanation:
---
--- User 1:
--- Total prompts = 3
--- Average tokens = (120 + 80 + 200) / 3 = 133.33
--- Has a prompt with 200 tokens, which is greater than the average
--- Included in the result
--- User 2:
--- Total prompts = 2 (less than the required minimum)
--- Excluded from the result
--- User 3:
--- Total prompts = 4
--- Average tokens = (300 + 250 + 180 + 220) / 4 = 237.5
--- Has prompts with 300 and 250 tokens, both greater than the average
--- Included in the result
--- The Results table is ordered by avg_tokens in descending order, then 
--- by user_id in ascending order
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    [user_id],
    [prompt_count],
    [avg_tokens]
FROM
(
    SELECT
        [user_id],
        [prompt_count] = COUNT(*),
        [avg_tokens] = CONVERT(decimal(18, 2), AVG(CONVERT(decimal(18, 2), tokens))),
        [max_token] = MAX(tokens)
    FROM
        [prompts]
    GROUP BY
        [user_id]
) AS T
WHERE [max_token] > [avg_tokens] AND  [prompt_count] >= 3 
ORDER BY
    [avg_tokens] DESC,
    [user_id] ASC
;