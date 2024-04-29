-----------------------------------------------------------------------
--- LeetCode 3126. Server Utilization Time
--- 
--- Medium
---
--- SQL Schema
--- Pandas Schema
--- Table: Servers
---
--- +----------------+----------+
--- | Column Name    | Type     |
--- +----------------+----------+
--- | server_id      | int      |
--- | status_time    | datetime |
--- | session_status | enum     |
--- +----------------+----------+
--- (server_id, status_time, session_status) is the primary key (combination 
--- of columns with unique values) for this table.
--- session_status is an ENUM (category) type of ('start', 'stop').
--- Each row of this table contains server_id, status_time, and session_status.
--- Write a solution to find the total time when servers were running. The 
--- output should be rounded down to the nearest number of full days.
---
--- Return the result table in any order.
---
--- The result format is in the following example.
---
--- Example:
--- 
--- Input:
---
--- Servers table:
--- +-----------+---------------------+----------------+
--- | server_id | status_time         | session_status |
--- +-----------+---------------------+----------------+
--- | 3         | 2023-11-04 16:29:47 | start          |
--- | 3         | 2023-11-05 01:49:47 | stop           |
--- | 3         | 2023-11-25 01:37:08 | start          |
--- | 3         | 2023-11-25 03:50:08 | stop           |
--- | 1         | 2023-11-13 03:05:31 | start          |
--- | 1         | 2023-11-13 11:10:31 | stop           |
--- | 4         | 2023-11-29 15:11:17 | start          |
--- | 4         | 2023-11-29 15:42:17 | stop           |
--- | 4         | 2023-11-20 00:31:44 | start          |
--- | 4         | 2023-11-20 07:03:44 | stop           |
--- | 1         | 2023-11-20 00:27:11 | start          |
--- | 1         | 2023-11-20 01:41:11 | stop           |
--- | 3         | 2023-11-04 23:16:48 | start          |
--- | 3         | 2023-11-05 01:15:48 | stop           |
--- | 4         | 2023-11-30 15:09:18 | start          |
--- | 4         | 2023-11-30 20:48:18 | stop           |
--- | 4         | 2023-11-25 21:09:06 | start          |
--- | 4         | 2023-11-26 04:58:06 | stop           |
--- | 5         | 2023-11-16 19:42:22 | start          |
--- | 5         | 2023-11-16 21:08:22 | stop           |
--- +-----------+---------------------+----------------+
--- Output:
---
--- +-------------------+
--- | total_uptime_days |
--- +-------------------+
--- | 1                 |
--- +-------------------+
--- Explanation:
---
--- For server ID 3:
--- From 2023-11-04 16:29:47 to 2023-11-05 01:49:47: ~9.3 hours
--- From 2023-11-25 01:37:08 to 2023-11-25 03:50:08: ~2.2 hours
--- From 2023-11-04 23:16:48 to 2023-11-05 01:15:48: ~1.98 hours
--- Total for server 3: ~13.48 hours
--- For server ID 1:
--- From 2023-11-13 03:05:31 to 2023-11-13 11:10:31: ~8 hours
--- From 2023-11-20 00:27:11 to 2023-11-20 01:41:11: ~1.23 hours
--- Total for server 1: ~9.23 hours
--- For server ID 4:
--- From 2023-11-29 15:11:17 to 2023-11-29 15:42:17: ~0.52 hours
--- From 2023-11-20 00:31:44 to 2023-11-20 07:03:44: ~6.53 hours
--- From 2023-11-30 15:09:18 to 2023-11-30 20:48:18: ~5.65 hours
--- From 2023-11-25 21:09:06 to 2023-11-26 04:58:06: ~7.82 hours
--- Total for server 4: ~20.52 hours
--- For server ID 5:
--- From 2023-11-16 19:42:22 to 2023-11-16 21:08:22: ~1.43 hours
--- Total for server 5: ~1.43 hours
--- The accumulated runtime for all servers totals approximately 44.46 hours, 
--- equivalent to one full day plus some additional hours. However, since we 
--- consider only full days, the final output is rounded to 1 full day.
---------------------------------------------------------------
WITH ServerTime AS
(
    SELECT
        [server_id],
        [status_time],
        [session_status],
        RN = ROW_NUMBER() OVER (PARTITION BY [server_id] ORDER BY [status_time] ASC, [session_status] ASC)
    FROM
        [Servers]
),
ServerDuration AS
(
    SELECT
        A.[server_id],
        [diff_seconds] = DATEDIFF(SECOND, A.[status_time], B.[status_time])
    FROM
        ServerTime AS A
    INNER JOIN 
        ServerTime AS B
    ON
        A.[server_id] = B.[server_id] AND
        A.RN + 1  = B.RN AND
        A.[session_status] = 'start'
)
SELECT 
    total_uptime_days = SUM([diff_seconds]) / 3600/24
FROM
    ServerDuration
;