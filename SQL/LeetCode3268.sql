-----------------------------------------------------------------------
--- LeetCode 3268. Find Overlapping Shifts II
--- 
--- Hard
--- 
--- SQL Schema
--- Pandas Schema
--- Table: EmployeeShifts
--- 
--- +------------------+----------+
--- | Column Name      | Type     |
--- +------------------+----------+
--- | employee_id      | int      |
--- | start_time       | datetime |
--- | end_time         | datetime |
--- +------------------+----------+
--- (employee_id, start_time) is the unique key for this table.
--- This table contains information about the shifts worked by employees, 
--- including the start time, and end time.
--- Write a solution to analyze overlapping shifts for each employee. Two 
--- shifts are considered overlapping if they occur on the same date and one 
--- shift's end_time is later than another shift's start_time.
---
--- For each employee, calculate the following:
---
--- The maximum number of shifts that overlap at any given time.
--- The total duration of all overlaps in minutes.
--- Return the result table ordered by employee_id in ascending order.
---
--- The query result format is in the following example.
---
--- Example:
--- Input:
--- EmployeeShifts table:
--- 
--- +-------------+---------------------+---------------------+
--- | employee_id | start_time          | end_time            |
--- +-------------+---------------------+---------------------+
--- | 1           | 2023-10-01 09:00:00 | 2023-10-01 17:00:00 |
--- | 1           | 2023-10-01 15:00:00 | 2023-10-01 23:00:00 |
--- | 1           | 2023-10-01 16:00:00 | 2023-10-02 00:00:00 |
--- | 2           | 2023-10-01 09:00:00 | 2023-10-01 17:00:00 |
--- | 2           | 2023-10-01 11:00:00 | 2023-10-01 19:00:00 |
--- | 3           | 2023-10-01 09:00:00 | 2023-10-01 17:00:00 |
--- +-------------+---------------------+---------------------+
--- Output:
--- 
--- +-------------+---------------------------+------------------------+
--- | employee_id | max_overlapping_shifts    | total_overlap_duration |
--- +-------------+---------------------------+------------------------+
--- | 1           | 3                         | 600                    |
--- | 2           | 2                         | 360                    |
--- | 3           | 1                         | 0                      |
--- +-------------+---------------------------+------------------------+
--- Explanation:
---
--- Employee 1 has 3 shifts:
--- 2023-10-01 09:00:00 to 2023-10-01 17:00:00
--- 2023-10-01 15:00:00 to 2023-10-01 23:00:00
--- 2023-10-01 16:00:00 to 2023-10-02 00:00:00
--- The maximum number of overlapping shifts is 3 (from 16:00 to 17:00). The 
--- total overlap duration is: - 2 hours (15:00-17:00) between 1st and 2nd 
--- shifts - 1 hour (16:00-17:00) between 1st and 3rd shifts - 7 hours 
--- (16:00-23:00) between 2nd and 3rd shifts Total: 10 hours = 600 minutes
--- Employee 2 has 2 shifts:
--- 2023-10-01 09:00:00 to 2023-10-01 17:00:00
--- 2023-10-01 11:00:00 to 2023-10-01 19:00:00
--- The maximum number of overlapping shifts is 2. The total overlap duration 
--- is 6 hours (11:00-17:00) = 360 minutes.
--- Employee 3 has only 1 shift, so there are no overlaps.
--- The output table contains the employee_id, the maximum number of 
--- simultaneous overlaps, and the total overlap duration in minutes for each 
--- employee, ordered by employee_id in ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
WITH max_overlapping_shifts AS
(
    SELECT
        employee_id,
        max_overlapping_shifts = MAX(overlapping_shifts)
    FROM
    (
        SELECT 
            A.employee_id,
            A.start_time,
            overlapping_shifts = COUNT(*)
        FROM
            EmployeeShifts AS A
        INNER JOIN
            EmployeeShifts AS B
        ON
            A.employee_id = B.employee_id
        WHERE
            B.start_time < A.start_time AND
            B.end_time > A.start_time
        GROUP BY
            A.employee_id,
            A.start_time
    ) AS T
    GROUP BY 
           employee_id
),
total_overlap_duration AS
(
    SELECT
        employee_id,
        total_overlap_duration = SUM(overlap_duration)
    FROM
    (
        SELECT 
            A.employee_id,
            A.start_time,
            overlap_duration = SUM(DATEDIFF(MINUTE, B.start_time, A.end_time))
        FROM
            EmployeeShifts AS A
        INNER JOIN
            EmployeeShifts AS B
        ON
            A.employee_id = B.employee_id
        WHERE
            B.start_time > A.start_time AND
            B.start_time < A.end_time
        GROUP BY
            A.employee_id,
            A.start_time
    ) AS T
    GROUP BY 
           employee_id
)
SELECT
    A.employee_id,
    max_overlapping_shifts = ISNULL(B.max_overlapping_shifts, 0) + 1,
    total_overlap_duration = ISNULL(C.total_overlap_duration, 0)
FROM
(
    SELECT DISTINCT employee_id FROM EmployeeShifts
) AS A
LEFT OUTER JOIN
    max_overlapping_shifts AS B
ON
    A.employee_id = B.employee_id
LEFT OUTER JOIN
    total_overlap_duration AS C
ON
    A.employee_id = C.employee_id
;