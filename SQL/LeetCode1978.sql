-----------------------------------------------------------------------
--- Leet code 1978. Employees Whose Manager Left the Company
--- 
--- Easy
---
--- SQL Schema
--- Table: Employees
---
--- +-------------+----------+
--- | Column Name | Type     |
--- +-------------+----------+
--- | employee_id | int      |
--- | name        | varchar  |
--- | manager_id  | int      |
--- | salary      | int      |
--- +-------------+----------+
--- employee_id is the primary key for this table.
--- This table contains information about the employees, their salary, and the 
--- id of their manager. Some employees do not have a manager (manager_id is 
--- null). 
---
--- Write an SQL query to report the ids of the employees whose manager left 
--- the company and their salary is strictly less than $30000. When a manager 
--- leaves the company, their information is deleted from the Employees table.
---
--- Return the result table ordered by employee_id.
--- 
--- The query result format is in the following example.
--- 
--- Example 1:
--- Input:  
--- Employees table:
--- +-------------+-----------+------------+--------+
--- | employee_id | name      | manager_id | salary |
--- +-------------+-----------+------------+--------+
--- | 3           | Mila      | 9          | 60301  |
--- | 12          | Antonella | null       | 31000  |
--- | 13          | Emery     | null       | 67084  |
--- | 1           | Kalel     | 11         | 21241  |
--- | 9           | Mikaela   | null       | 50937  |
--- | 11          | Joziah    | 6          | 28485  |
--- +-------------+-----------+------------+--------+
--- Output: 
--- +-------------+
--- | employee_id |
--- +-------------+
--- | 11          |
--- +-------------+
--- 
--- Explanation: 
--- The employees with a salary less than $30000 are 1 and 11.
--- The manager of employee 1 is still in the company.
--- The manager of employee 11 is employee 6 who left the company, so we 
--- return employee 11.
-------------------------------------------------------------------
SELECT
    A.employee_id
FROM
    Employees AS A
LEFT OUTER JOIN
    Employees AS B
ON
    A.manager_id = B.employee_id
WHERE
    A.manager_id IS NOT NULL AND B.employee_id IS NULL AND A.salary < 30000
ORDER BY
    A.employee_id
;
