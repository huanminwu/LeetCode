-----------------------------------------------------------------------
--- LeetCode 2853. Highest Salaries Difference
--- 
--- Easy
---
--- SQL Schema
--- Table: Salaries
---
--- +-------------+---------+ 
--- | Column Name | Type    | 
--- +-------------+---------+ 
--- | emp_name    | varchar | 
--- | department  | varchar | 
--- | salary      | int     |
--- +-------------+---------+
--- (emp_name, department) is the primary key for this table.
--- Each row of this table contains emp_name, department and salary. There 
--- will be at least one entry for the engineering and marketing departments.
--- Write an SQL query to calculate the difference between the highest 
--- salaries in the marketing and engineering department. Output the 
--- absolute difference in salaries.
---
--- Return the result table.
---
--- The query result format is in the following example.
--- Example 1:
--- Input: 
--- Salaries table:
--- +----------+-------------+--------+
--- | emp_name | department  | salary |
--- +----------+-------------+--------+
--- | Kathy    | Engineering | 50000  |
--- | Roy      | Marketing   | 30000  |
--- | Charles  | Engineering | 45000  |
--- | Jack     | Engineering | 85000  | 
--- | Benjamin | Marketing   | 34000  |
--- | Anthony  | Marketing   | 42000  |
--- | Edward   | Engineering | 102000 |
--- | Terry    | Engineering | 44000  |
--- | Evelyn   | Marketing   | 53000  |
--- | Arthur   | Engineering | 32000  |
--- +----------+-------------+--------+
--- Output: 
--- +-------------------+
--- | salary_difference | 
--- +-------------------+
--- | 49000             | 
--- +-------------------+
--- Explanation: 
--- - The Engineering and Marketing departments have the highest salaries of 
---   102,000 and 53,000, respectively. Resulting in an absolute difference 
---   of 49,000.
---------------------------------------------------------------
SELECT
    salary_difference = ABS(ISNULL(A.max_salary, 0) - ISNULL(B.max_salary, 0))
FROM 
(
    SELECT max_salary = max(salary)
	FROM Salaries
	WHERE department = 'Engineering'
) AS A
CROSS JOIN
(
    SELECT max_salary = max(salary)
	FROM Salaries
	WHERE department = 'Marketing'
) AS B
;
