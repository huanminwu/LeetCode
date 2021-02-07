-----------------------------------------------------------------------
---  Leet code #1709. Biggest Window Between Visits
--- 
---  Medium
--- 
---  SQL Schema
---  Table: UserVisits
---
---  +-------------+------+
---  | Column Name | Type |
---  +-------------+------+
---  | user_id     | int  |
---  | visit_date  | date |
---  +-------------+------+
---  This table does not have a primary key.
---  This table contains logs of the dates that users vistied a certain 
---  retailer.
--- 
---  Assume today's date is '2021-1-1'.
---  
---  Write an SQL query that will, for each user_id, find out the largest 
---  window of days between each visit and the one right after it (or today 
---  if you are considering the last visit).
--- 
---  Return the result table ordered by user_id.
---  The query result format is in the following example:
---  UserVisits table:
---  +---------+------------+
---  | user_id | visit_date |
---  +---------+------------+
---  | 1       | 2020-11-28 |
---  | 1       | 2020-10-20 |
---  | 1       | 2020-12-3  |
---  | 2       | 2020-10-5  |
---  | 2       | 2020-12-9  |
---  | 3       | 2020-11-11 |
---  +---------+------------+
---  Result table:
---  +---------+---------------+
---  | user_id | biggest_window|
---  +---------+---------------+
---  | 1       | 39            |
---  | 2       | 65            |
---  | 3       | 51            |
---  +---------+---------------+
---  For the first user, the windows in question are between dates:
---    - 2020-10-20 and 2020-11-28 with a total of 39 days. 
---    - 2020-11-28 and 2020-12-3 with a total of 5 days. 
---    - 2020-12-3 and 2021-1-1 with a total of 29 days.
---  Making the biggest window the one with 39 days.
---  For the second user, the windows in question are between dates:
---    - 2020-10-5 and 2020-12-9 with a total of 65 days.
---    - 2020-12-9 and 2021-1-1 with a total of 23 days.
---  Making the biggest window the one with 65 days.
---  For the third user, the only window in question is between 
---  dates 2020-11-11 and 2021-1-1 with a total of 51 days.
-----------------------------------------------------------------------
WITH 
   User_Visits_CTE
AS
(
	SELECT
		user_id,
		visit_date,
		Row_Id = ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY visit_date)
	FROM
	(
		SELECT
			user_id,
			visit_date
		FROM
			UserVisits
		UNION ALL
		SELECT 
			user_id,
			visit_date
		FROM
		(
			SELECT
				DISTINCT
				user_id
			FROM 
			   UserVisits
		) AS A
		CROSS JOIN
		(
			SELECT
				visit_date = CONVERT(DATETIME, '2021-01-01')
		) AS B
	) AS T
)
SELECT
    user_id,
	biggest_window = MAX(window)
FROM
(
	SELECT
		A.user_id,
		window = DATEDIFF (DAY , A.visit_date , B.visit_date)
	FROM
		User_Visits_CTE AS A
	INNER JOIN
		User_Visits_CTE AS B
	ON
		A.user_id = B.user_id AND
		A.Row_Id + 1= B.Row_Id
) AS T
GROUP BY
    user_id
;
