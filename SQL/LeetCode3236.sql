-----------------------------------------------------------------------
--- LeetCode 3236. CEO Subordinate Hierarchy
--- 
--- Hard
--- 
--- Topics
--- SQL Schema
--- Pandas Schema
--- Table: Employees
---
--- +---------------+---------+
--- | Column Name   | Type    |
--- +---------------+---------+
--- | employee_id   | int     |
--- | employee_name | varchar |
--- | manager_id    | int     |
--- | salary        | int     |
--- +---------------+---------+
--- employee_id is the unique identifier for this table.
--- manager_id is the employee_id of the employee's manager. The CEO has a 
--- NULL manager_id.
--- Write a solution to find subordinates of the CEO (both direct and 
--- indirect), along with their level in the hierarchy and their salary 
--- difference from the CEO.
---
--- The result should have the following columns:
---
--- The query result format is in the following example.
---
--- subordinate_id: The employee_id of the subordinate
--- subordinate_name: The name of the subordinate
--- hierarchy_level: The level of the subordinate in the hierarchy (1 for 
--- direct reports, 2 for their direct reports, and so on)
--- salary_difference: The difference between the subordinate's salary and 
--- the CEO's salary
--- Return the result table ordered by hierarchy_level ascending, and then by 
--- subordinate_id ascending.
---
--- The query result format is in the following example.
--- 
---
--- Example:
---
--- Input:
---
--- Employees table:
---
--- +-------------+----------------+------------+---------+
--- | employee_id | employee_name  | manager_id | salary  |
--- +-------------+----------------+------------+---------+
--- | 1           | Alice          | NULL       | 150000  |
--- | 2           | Bob            | 1          | 120000  |
--- | 3           | Charlie        | 1          | 110000  |
--- | 4           | David          | 2          | 105000  |
--- | 5           | Eve            | 2          | 100000  |
--- | 6           | Frank          | 3          | 95000   |
--- | 7           | Grace          | 3          | 98000   |
--- | 8           | Helen          | 5          | 90000   |
--- +-------------+----------------+------------+---------+
--- Output:
---
--- +----------------+------------------+------------------+-------------------+
--- | subordinate_id | subordinate_name | hierarchy_level  | salary_difference |
--- +----------------+------------------+------------------+-------------------+
--- | 2              | Bob              | 1                | -30000            |
--- | 3              | Charlie          | 1                | -40000            |
--- | 4              | David            | 2                | -45000            |
--- | 5              | Eve              | 2                | -50000            |
--- | 6              | Frank            | 2                | -55000            |
--- | 7              | Grace            | 2                | -52000            |
--- | 8              | Helen            | 3                | -60000            |
--- +----------------+------------------+------------------+-------------------+
--- Explanation:
--- 
--- Bob and Charlie are direct subordinates of Alice (CEO) and thus have a 
--- hierarchy_level of 1.
--- David and Eve report to Bob, while Frank and Grace report to Charlie, 
--- making them second-level subordinates (hierarchy_level 2).
--- Helen reports to Eve, making Helen a third-level subordinate 
--- (hierarchy_level 3).
--- Salary differences are calculated relative to Alice's salary of 150000.
--- The result is ordered by hierarchy_level ascending, and then by 
--- subordinate_id ascending.
--- Note: The output is ordered first by hierarchy_level in ascending order, 
--- then by subordinate_id in ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
WITH Recursion AS
(
    SELECT 
        subordinate_id = employee_id,
        subordinate_name = employee_name,
        salary,
        hierarchy_level = 0
    FROM Employees
    WHERE  manager_id IS NULL
    UNION ALL
    SELECT 
        subordinate_id = B.employee_id,
        subordinate_name = B.employee_name,
        B.salary,
        hierarchy_level = A.hierarchy_level + 1
    FROM
        Recursion AS A
    INNER JOIN 
        Employees AS B
    ON
        A.subordinate_id = B.manager_id
)
SELECT
    A.subordinate_id,
    A.subordinate_name,
    A.hierarchy_level,
    salary_difference = A.salary - B.salary
FROM
    Recursion AS A
CROSS JOIN
(
    SELECT salary FROM Employees WHERE manager_id IS NULL
) AS B
WHERE A.hierarchy_level > 0
ORDER BY A.hierarchy_level, A.subordinate_id
;