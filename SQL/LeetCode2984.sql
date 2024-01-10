-----------------------------------------------------------------------
--- LeetCode 2984. Find Peak Calling Hours for Each City
--- 
--- Medium
--- SQL Schema
--- Table: Calls
---
--- +--------------+----------+
--- | Column Name  | Type     |
--- +--------------+----------+
--- | caller_id    | int      |
--- | recipient_id | int      |
--- | call_time    | datetime |
--- | city         | varchar  |
--- +--------------+----------+
--- (caller_id, recipient_id, call_time) is the primary key (combination of 
--- columns with unique values) for this table.
--- Each row contains caller id, recipient id, call time, and city.
--- Write a solution to find the peak calling hour for each city. If multiple 
--- hours have the same number of calls, all of those hours will be recognized 
--- as peak hours for that specific city.
---
--- Return the result table ordered by peak calling hour and city in 
--- descending order.
---
--- The result format is in the following example.
---
--- Example 1:
--- Input: 
--- Calls table:
--- +-----------+--------------+---------------------+----------+
--- | caller_id | recipient_id | call_time           | city     |
--- +-----------+--------------+---------------------+----------+
--- | 8         | 4            | 2021-08-24 22:46:07 | Houston  |
--- | 4         | 8            | 2021-08-24 22:57:13 | Houston  |  
--- | 5         | 1            | 2021-08-11 21:28:44 | Houston  |  
--- | 8         | 3            | 2021-08-17 22:04:15 | Houston  |
--- | 11        | 3            | 2021-08-17 13:07:00 | New York |
--- | 8         | 11           | 2021-08-17 14:22:22 | New York |
--- +-----------+--------------+---------------------+----------+
--- Output: 
--- +----------+-------------------+-----------------+
--- | city     | peak_calling_hour | number_of_calls |
--- +----------+-------------------+-----------------+
--- | Houston  | 22                | 3               |
--- | New York | 14                | 1               |
--- | New York | 13                | 1               |
--- +----------+-------------------+-----------------+
--- Explanation: 
--- For Houston:
---   - The peak time is 22:00, with a total of 3 calls recorded. 
---     For New York:
---   - Both 13:00 and 14:00 hours have equal call counts of 1, so both times 
---     are considered peak hours.
--- Output table is ordered by peak_calling_hour and city in descending order.
---------------------------------------------------------------
WITH CallingHour
AS
(
    SELECT
        city,
        calling_hour = DATEPART(HH, call_time),
        number_of_calls = SUM(1)
    FROM
        Calls
    GROUP BY
        city,
        DATEPART(HH, call_time)
)
SELECT
    city,
    peak_calling_hour,
    number_of_calls
FROM
(
    SELECT 
        city,
        peak_calling_hour = calling_hour,
        number_of_calls = number_of_calls,
        RN = RANK() OVER (PARTITION BY city ORDER BY number_of_calls DESC)
    FROM 
        CallingHour 
) AS T
WHERE RN = 1
ORDER BY peak_calling_hour DESC, city DESC 
;