-----------------------------------------------------------------------
--- LeetCode 3451. Find Invalid IP Addresses
--- 
--- Hard
---
--- SQL Schema
--- Pandas Schema
--- Table:  logs
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | log_id      | int     |
--- | ip          | varchar |
--- | status_code | int     |
--- +-------------+---------+
--- log_id is the unique key for this table.
--- Each row contains server access log information including IP address 
--- and HTTP status code.
--- Write a solution to find invalid IP addresses. An IPv4 address is invalid 
--- if it meets any of these conditions:
---
--- Contains numbers greater than 255 in any octet
--- Has leading zeros in any octet (like 01.02.03.04)
--- Has less or more than 4 octets
--- Return the result table ordered by invalid_count, ip in descending order 
--- respectively. 
---
--- The result format is in the following example.
---
--- Example:
--- Input:
--- logs table:
---
--- +--------+---------------+-------------+
--- | log_id | ip            | status_code | 
--- +--------+---------------+-------------+
--- | 1      | 192.168.1.1   | 200         | 
--- | 2      | 256.1.2.3     | 404         | 
--- | 3      | 192.168.001.1 | 200         | 
--- | 4      | 192.168.1.1   | 200         | 
--- | 5      | 192.168.1     | 500         | 
--- | 6      | 256.1.2.3     | 404         | 
--- | 7      | 192.168.001.1 | 200         | 
--- +--------+---------------+-------------+
--- Output:
---
--- +---------------+--------------+
--- | ip            | invalid_count|
--- +---------------+--------------+
--- | 256.1.2.3     | 2            |
--- | 192.168.001.1 | 2            |
--- | 192.168.1     | 1            |
--- +---------------+--------------+
--- Explanation:
---
--- 256.1.2.3 is invalid because 256 > 255
--- 192.168.001.1 is invalid because of leading zeros
--- 192.168.1 is invalid because it has only 3 octets
--- The output table is ordered by invalid_count, ip in descending order 
--- respectively.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
WITH IPAddress_Octet AS
(
    SELECT
        [log_id],
        [ip],
        [octet] = [value],
        [octet_value] = TRY_CONVERT(INT, [value])
    FROM [logs]  
    CROSS APPLY STRING_SPLIT([ip], '.')
)
SELECT
    [ip],
    [invalid_count] = COUNT(*)
FROM
(
    SELECT
        [log_id],
        [ip],
        [octet_count] = COUNT(*),
        [octet_outofrange] = 
            SUM(CASE WHEN [octet_value] > 255 OR [octet_value] < 0 OR [octet_value] IS NULL THEN 1 ELSE 0 END),
        [octet_leadingzero] = SUM(CASE WHEN [octet] LIKE '0%' THEN 1 ELSE 0 END)
    FROM 
        IPAddress_Octet
    GROUP BY
        [log_id],
        [ip]
) AS T
WHERE
    [octet_count] != 4 OR
    [octet_outofrange] > 0 OR
    [octet_leadingzero] > 0
GROUP BY
    [ip]
ORDER BY
    [invalid_count] DESC,
    [ip] DESC
;
