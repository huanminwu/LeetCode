-----------------------------------------------------------------------
--- LeetCode 3156. Employee Task Duration and Concurrent Tasks
--- 
--- Hard
---
--- SQL Schema
--- Pandas Schema
--- Table: Tasks
---
--- +---------------+----------+
--- | Column Name   | Type     |
--- +---------------+----------+
--- | task_id       | int      |
--- | employee_id   | int      |
--- | start_time    | datetime |
--- | end_time      | datetime |
--- +---------------+----------+
--- (task_id, employee_id) is the primary key for this table.
--- Each row in this table contains the task identifier, the employee 
--- identifier, and the start and end times of each task.
--- Write a solution to find the total duration of tasks for each 
--- employee and the maximum number of concurrent tasks an employee 
--- handled at any point in time. The total duration should be rounded 
--- down to the nearest number of full hours.
---
--- Return the result table ordered by employee_id ascending order.
---
--- The result format is in the following example.
---
--- Example:
--- 
--- Input:
--- 
--- Tasks table:
--- 
--- +---------+-------------+---------------------+---------------------+
--- | task_id | employee_id | start_time          | end_time            |
--- +---------+-------------+---------------------+---------------------+
--- | 1       | 1001        | 2023-05-01 08:00:00 | 2023-05-01 09:00:00 |
--- | 2       | 1001        | 2023-05-01 08:30:00 | 2023-05-01 10:30:00 |
--- | 3       | 1001        | 2023-05-01 11:00:00 | 2023-05-01 12:00:00 |
--- | 7       | 1001        | 2023-05-01 13:00:00 | 2023-05-01 15:30:00 |
--- | 4       | 1002        | 2023-05-01 09:00:00 | 2023-05-01 10:00:00 |
--- | 5       | 1002        | 2023-05-01 09:30:00 | 2023-05-01 11:30:00 |
--- | 6       | 1003        | 2023-05-01 14:00:00 | 2023-05-01 16:00:00 |
--- +---------+-------------+---------------------+---------------------+
--- Output:
--- 
--- +-------------+------------------+----------------------+
--- | employee_id | total_task_hours | max_concurrent_tasks |
--- +-------------+------------------+----------------------+
--- | 1001        | 6                | 2                    |
--- | 1002        | 2                | 2                    |
--- | 1003        | 2                | 1                    |
--- +-------------+------------------+----------------------+
--- Explanation:
---
--- For employee ID 1001:
--- Task 1 and Task 2 overlap from 08:30 to 09:00 (30 minutes).
--- Task 7 has a duration of 150 minutes (2 hours and 30 minutes).
--- Total task time: 60 (Task 1) + 120 (Task 2) + 60 (Task 3) + 150 (Task 7) - 
--- 30 (overlap) = 360 minutes = 6 hours.
--- Maximum concurrent tasks: 2 (during the overlap period).
--- For employee ID 1002:
--- Task 4 and Task 5 overlap from 09:30 to 10:00 (30 minutes).
--- Total task time: 60 (Task 4) + 120 (Task 5) - 30 (overlap) = 150 minutes 
--- = 2 hours and 30 minutes.
--- Total task hours (rounded down): 2 hours.
--- Maximum concurrent tasks: 2 (during the overlap period).
--- For employee ID 1003:
--- No overlapping tasks.
--- Total task time: 120 minutes = 2 hours.
--- Maximum concurrent tasks: 1.
--- Note: Output table is ordered by employee_id in ascending order.
---------------------------------------------------------------
SELECT
    employee_id,
    total_task_hours = SUM(DATEDIFF(SECOND, start_time, end_time)) / 3600,
    max_concurrent_tasks = MAX(concurrent_tasks) + 1
FROM
(
    SELECT
        A.task_id,
        A.employee_id, 
        start_time = 
            CASE WHEN ISNULL(MAX(B.end_time), A.start_time)  < A.start_time THEN  A.start_time
                 WHEN ISNULL(MAX(B.end_time), A.start_time) > A.end_time THEN A.end_time
                 ELSE ISNULL(MAX(B.end_time), A.start_time)
                 END,
        A.end_time,
        concurrent_tasks = SUM(CASE WHEN B.end_time > A.start_time THEN 1 ELSE 0 END)
    FROM
        Tasks AS A
    LEFT OUTER JOIN
        Tasks AS B
    ON
        A.employee_id = B.employee_id AND
        A.start_time > B.start_time 
    GROUP BY 
        A.task_id, A.employee_id, A.start_time, A.end_time
) AS T
GROUP BY
    employee_id;