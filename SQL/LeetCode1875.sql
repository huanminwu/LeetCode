-----------------------------------------------------------------------
---  Leet code 1875. Group Employees of the Same Salary
--- 
--- Medium
---
--- SQL Schema
--- Table: Employees
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | employee_id | int     |
--- | name        | varchar |
--- | salary      | int     |
--- +-------------+---------+
--- employee_id is the primary key for this table.
--- Each row of this table indicates the employee ID, employee name, and salary.
---
--- A company wants to divide the employees into teams such that all the 
--- members on each team have the same salary. The teams should follow these 
--- criteria:
---
--- Each team should consist of at least two employees.
--- All the employees on a team should have the same salary.
--- All the employees of the same salary should be assigned to the same team.
--- If the salary of an employee is unique, we do not assign this employee to 
--- any team.
--- A team's ID is assigned based on the rank of the team's salary relative 
--- to the other teams' salaries, where the team with the lowest salary has 
--- team_id = 1. Note that the salaries for employees not on a team are not 
--- included in this ranking.
--- Write an SQL query to get the team_id of each employee that is in a team.
---
--- Return the result table ordered by team_id in ascending order. In case of 
--- a tie, order it by employee_id in ascending order.
---
--- The query result format is in the following example:
--- 
--- Employees table:
--- +-------------+---------+--------+
--- | employee_id | name    | salary |
--- +-------------+---------+--------+
--- | 2           | Meir    | 3000   |
--- | 3           | Michael | 3000   |
--- | 7           | Addilyn | 7400   |
--- | 8           | Juan    | 6100   |
--- | 9           | Kannon  | 7400   |
--- +-------------+---------+--------+
---
--- Result table:
--- +-------------+---------+--------+---------+
--- | employee_id | name    | salary | team_id |
--- +-------------+---------+--------+---------+
--- | 2           | Meir    | 3000   | 1       |
--- | 3           | Michael | 3000   | 1       |
--- | 7           | Addilyn | 7400   | 2       |
--- | 9           | Kannon  | 7400   | 2       |
--- +-------------+---------+--------+---------+
---
--- Meir (employee_id=2) and Michael (employee_id=3) are in the same team 
--- because they have the same salary of 3000.
--- Addilyn (employee_id=7) and Kannon (employee_id=9) are in the same team 
--- because they have the same salary of 7400.
--- Juan (employee_id=8) is not included in any team because their salary 
--- of 6100 is unique (i.e. no other employee has the same salary).
--- The team IDs are assigned as follows (based on salary ranking, lowest first):
--- team_id=1: Meir and Michael, salary of 3000
--- team_id=2: Addilyn and Kannon, salary of 7400
--- Juan's salary of 6100 is not included in the ranking because they are not on 
--- a team.
-----------------------------------------------------------------------
WITH Salary AS
(
    SELECT
	    salary,
        RANK() OVER (ORDER BY salary) AS team_id
	FROM
	(
		SELECT
			salary,
			COUNT(*) AS [Count]
		FROM 
			Employees
		GROUP BY
			salary
	) AS T
    WHERE [Count] > 1
)
SELECT
    A.employee_id,
	A.name,
	A.salary,
	B.team_id
FROM
    Employees AS A
INNER JOIN 
    Salary AS B
ON 
    A.salary = B.salary 
ORDER BY 
    team_id, employee_id
;