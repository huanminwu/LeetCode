-----------------------------------------------------------------------
--- Leet code 1972. First and Last Call On the Same Day
--- 
--- Hard
---
--- SQL Schema
--- Table: Calls
---
--- +--------------+----------+
--- | Column Name  | Type     |
--- +--------------+----------+
--- | caller_id    | int      |
--- | recipient_id | int      |
--- | call_time    | datetime |
--- +--------------+----------+
--- (caller_id, recipient_id, call_time) is the primary key for this table.
--- Each row contains information about the time of a phone call between 
--- caller_id and recipient_id.
---
--- Write an SQL query to report the IDs of the users whose first and last 
--- calls on any day were with the same person. Calls are counted regardless 
--- of being the caller or the recipient.
---
--- Return the result table in any order.
---
--- The query result format is in the following example:
--- 
--- Calls table:
--- +-----------+--------------+---------------------+
--- | caller_id | recipient_id | call_time           |
--- +-----------+--------------+---------------------+
--- | 8         | 4            | 2021-08-24 17:46:07 |
--- | 4         | 8            | 2021-08-24 19:57:13 |
--- | 5         | 1            | 2021-08-11 05:28:44 |
--- | 8         | 3            | 2021-08-17 04:04:15 |
--- | 11        | 3            | 2021-08-17 13:07:00 |
--- | 8         | 11           | 2021-08-17 22:22:22 |
--- +-----------+--------------+---------------------+
---
--- Result table:
--- +---------+
--- | user_id |
--- +---------+
--- | 1       |
--- | 4       |
--- | 5       |
--- | 8       |
--- +---------+
---
--- On 2021-08-24, the first and last call of this day for user 8 was with 
--- user 4. User 8 should be included in the answer.
--- Similary, user 4 on 2021-08-24 had their first and last call with user 8. 
--- User 4 should be included in the answer.
--- On 2021-08-11, user 1 and 5 had a call. This call was the only call for 
--- both of them on this day. Since this call is the first and last call of 
--- the day for both of them, they should both be included in the answer.
-------------------------------------------------------------------
WITH Caller_Union 
AS
(
	SELECT
		caller_id,
		recipient_id,
		[date] = CONVERT(DATE, call_time),
		call_time 
	FROM
	   Calls
	UNION
	SELECT
		caller_id = recipient_id,
		recipient_id = caller_id,
		[date] = CONVERT(DATE, call_time),
		call_time 
	FROM
	   Calls
),
Caller_CTE
AS
(
	SELECT
		caller_id,
		recipient_id,
		[date],
		order_id = ROW_NUMBER() OVER (PARTITION BY caller_id, [date] ORDER BY call_time), 
		revorder_id = ROW_NUMBER() OVER (PARTITION BY caller_id, [date] ORDER BY call_time DESC) 
	FROM
	   Caller_Union		
),
Caller_JOIN 
AS
(
    SELECT
	    A.caller_id,
		A.recipient_id,
		A.[date]
	FROM
	(
		SELECT
			caller_id,
			recipient_id,
			[date]
		FROM
		   Caller_CTE
		WHERE
		   order_id = 1
    ) AS A
    INNER JOIN
    (
		SELECT
			caller_id,
			recipient_id,
			[date]
		FROM
		   Caller_CTE
		WHERE
		   revorder_id = 1
    ) AS B
	ON
	  A.caller_id = B.caller_id AND
	  A.[date] = B.[date]
	WHERE 
	   A.recipient_id = B.recipient_id	   
)
SELECT DISTINCT user_id = caller_id FROM Caller_JOIN
order by user_id
