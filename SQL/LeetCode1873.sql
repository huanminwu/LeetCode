-----------------------------------------------------------------------
---  Leet code 1873. Calculate Special Bonus
--- 
--- Easy
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
--- Each row of this table indicates the employee ID, employee name, and 
--- salary.
--- 
--- Write an SQL query to calculate the bonus of each employee. The bonus
--- of an employee is 100% of their salary if the ID of the employee is an
--- odd number and the employee name does not start with the character 'M'. 
--- The bonus of an employee is 0 otherwise.
---
--- Return the result table ordered by employee_id.
---
--- The query result format is in the following example:
---
--- Employees table:
--- +-------------+---------+--------+
--- | employee_id | name    | salary |
--- +-------------+---------+--------+
--- | 2           | Meir    | 3000   |
--- | 3           | Michael | 3800   |
--- | 7           | Addilyn | 7400   |
--- | 8           | Juan    | 6100   |
--- | 9           | Kannon  | 7700   |
--- +-------------+---------+--------+
---
--- Result table:
--- +-------------+-------+
--- | employee_id | bonus |
--- +-------------+-------+
--- | 2           | 0     |
--- | 3           | 0     |
--- | 7           | 7400  |
--- | 8           | 0     |
--- | 9           | 7700  |
--- +-------------+-------+
---
--- The employees with IDs 2 and 8 get 0 bonus because they have an even 
--- employee_id.
--- The employee with ID 3 gets 0 bonus because their name starts with 'M'.
--- The rest of the employees get a 100% bonus.
-----------------------------------------------------------------------
SELECT 
    employee_id,
	bonus = 
	    CASE WHEN employee_id % 2 = 0 OR SUBSTRING(name, 1, 1) = 'M' THEN 0 ELSE salary END
FROM 
    Employees
;