-----------------------------------------------------------------------
--- LeetCode 3124. Find Longest Calls
--- 
--- Medium
--- SQL Schema
--- Table: Contacts
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | id          | int     |
--- | first_name  | varchar |
--- | last_name   | varchar |
--- +-------------+---------+
--- id is the primary key (column with unique values) of this table.
--- id is a foreign key (reference column) to Calls table.
--- Each row of this table contains id, first_name, and last_name.
--- Table: Calls
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | contact_id  | int  |
--- | type        | enum |
--- | duration    | int  |
--- +-------------+------+
--- (contact_id, type, duration) is the primary key (column with unique 
--- values) of this table.
--- type is an ENUM (category) type of ('incoming', 'outgoing').
--- Each row of this table contains information about calls, comprising of 
--- contact_id, type, and duration in seconds.
--- Write a solution to find the three longest incoming and outgoing calls.
---
--- Return the result table ordered by type, duration, and first_name in 
--- descending order and duration must be formatted as HH:MM:SS.
---
--- The result format is in the following example.
--- 
--- 
---
--- Example 1:
--- Input:
--- Contacts table:
--- 
--- +----+------------+-----------+
--- | id | first_name | last_name |
--- +----+------------+-----------+
--- | 1  | John       | Doe       |
--- | 2  | Jane       | Smith     |
--- | 3  | Alice      | Johnson   |
--- | 4  | Michael    | Brown     |
--- | 5  | Emily      | Davis     |
--- +----+------------+-----------+        
---
--- Calls table:
--- +------------+----------+----------+
--- | contact_id | type     | duration |
--- +------------+----------+----------+
--- | 1          | incoming | 120      |
--- | 1          | outgoing | 180      |
--- | 2          | incoming | 300      |
--- | 2          | outgoing | 240      |
--- | 3          | incoming | 150      |
--- | 3          | outgoing | 360      |
--- | 4          | incoming | 420      |
--- | 4          | outgoing | 200      |
--- | 5          | incoming | 180      |
--- | 5          | outgoing | 280      |
--- +------------+----------+----------+
---        
--- Output:
---
--- +-----------+----------+-------------------+
--- | first_name| type     | duration_formatted|
--- +-----------+----------+-------------------+
--- | Michael   | incoming | 00:07:00          |
--- | Jane      | incoming | 00:05:00          |
--- | Emily     | incoming | 00:03:00          |
--- | Alice     | outgoing | 00:06:00          |
--- | Emily     | outgoing | 00:04:40          |
--- | Jane      | outgoing | 00:04:00          |
--- +-----------+----------+-------------------+
---        
--- Explanation:
---
--- Michael had an incoming call lasting 7 minutes.
--- Jane had an incoming call lasting 5 minutes.
--- Emily had an incoming call lasting 3 minutes.
--- Alice had an outgoing call lasting 6 minutes.
--- Emily had an outgoing call lasting 4 minutes and 40 seconds.
--- Jane had an outgoing call lasting 4 minutes.
--- Note: Output table is sorted by type, duration, and first_name in 
--- descending order.
---------------------------------------------------------------
SELECT
    [first_name],
    [type],
    [duration_formatted] = FORMAT([hours],'D2') + ':' + FORMAT([minutes],'D2') + ':' + FORMAT([seconds],'D2')
FROM
(
    SELECT
        [first_name],
        [type],
        [duration],
        [seconds] = [duration] % 60,
        [minutes] = [duration] / 60 % 60,
        [hours] = [duration] / 60 / 60,
        RN = ROW_NUMBER() OVER (PARTITION BY [type] ORDER BY [duration] DESC, [first_name] DESC)
    FROM
    (
        SELECT
            A.[first_name],
            B.[type],
            B.[duration]
        FROM
            Contacts AS A
        INNER JOIN
            Calls AS B
        ON
            A.[id] = B.[contact_id] 
    ) AS T
) AS T
WHERE RN <=3 
ORDER BY  [type], [duration_formatted] DESC, [first_name]