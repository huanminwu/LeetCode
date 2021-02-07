-----------------------------------------------------------------------
---  Leet code #1731. The Number of Employees Which Report to Each Employee
--- 
---  Easy
--- 
---  SQL Schema
---  Table: Employees
---
---  +-------------+----------+
---  | Column Name | Type     |
---  +-------------+----------+
---  | employee_id | int      |
---  | name        | varchar  |
---  | reports_to  | int      |
---  | age         | int      |
---  +-------------+----------+
---  employee_id is the primary key for this table.
---  This table contains information about the employees and the id of the 
---  manager they report to. Some employees do not report to anyone 
---  (reports_to is null). 
--- 
---  For this problem, we will consider a manager an employee who has at 
---  least 1 other employee reporting to them.
---
---  Write an SQL query to report the ids and the names of all managers, the 
---  number of employees who report directly to them, and the average age of 
---  the reports rounded to the nearest integer.
---
---  Return the result table ordered by employee_id.
---
---  The query result format is in the following example:
---  Employees table:
---  +-------------+---------+------------+-----+
---  | employee_id | name    | reports_to | age |
---  +-------------+---------+------------+-----+
---  | 9           | Hercy   | null       | 43  |
---  | 6           | Alice   | 9          | 41  |
---  | 4           | Bob     | 9          | 36  |
---  | 2           | Winston | null       | 37  |
---  +-------------+---------+------------+-----+
---
---  Result table:
---  +-------------+-------+---------------+-------------+
---  | employee_id | name  | reports_count | average_age |
---  +-------------+-------+---------------+-------------+
---  | 9           | Hercy | 2             | 39          |
---  +-------------+-------+---------------+-------------+
---  Hercy has 2 people report directly to him, Alice and Bob. Their average 
---  age is (41+36)/2 = 38.5, which is 39 after rounding it to the nearest 
---  integer.
-----------------------------------------------------------------------
SELECT
    employee_id = A.reports_to,
    name = MAX(B.name),
	reports_count = COUNT(*),
	average_age = CONVERT(int, ROUND(AVG(CONVERT(float, A.age)), 0))
FROM 
    Employees AS A
INNER JOIN
    Employees AS B
ON
    A.reports_to = B.employee_id
WHERE 
    A.reports_to IS NOT NULL
GROUP BY
    A.reports_to
;
