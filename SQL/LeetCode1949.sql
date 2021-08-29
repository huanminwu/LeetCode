-----------------------------------------------------------------------
--- Leet code 1949. Strong Friendship
--- 
--- Medium
---
--- SQL Schema
--- Table: Friendship
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | user1_id    | int  |
--- | user2_id    | int  |
--- +-------------+------+
--- (user1_id, user2_id) is the primary key for this table.
--- Each row of this table indicates that the users user1_id and user2_id are 
--- friends.
--- Note that user1_id < user2_id.
---
--- A friendship between a pair of friends x and y is strong if x and y have 
--- at least three common friends.
---
--- Write an SQL query to find all the strong friendships.
---
--- Note that the result table should not contain duplicates with 
--- user1_id < user2_id.
---
--- Return the result table in any order.
--- The query result format is in the following example:
--- 
--- Friendship table:
--- +----------+----------+
--- | user1_id | user2_id |
--- +----------+----------+
--- | 1        | 2        |
--- | 1        | 3        |
--- | 2        | 3        |
--- | 1        | 4        |
--- | 2        | 4        |
--- | 1        | 5        |
--- | 2        | 5        |
--- | 1        | 7        |
--- | 3        | 7        |
--- | 1        | 6        |
--- | 3        | 6        |
--- | 2        | 6        |
--- +----------+----------+
---
--- Result table:
--- +----------+----------+---------------+
--- | user1_id | user2_id | common_friend |
--- +----------+----------+---------------+
--- | 1        | 2        | 4             |
--- | 1        | 3        | 3             |
--- +----------+----------+---------------+
--- Users 1 and 2 have 4 common friends (3, 4, 5, and 6).
--- Users 1 and 3 have 3 common friends (2, 6, and 7).
--- We did not include the friendship of users 2 and 3 because they only have 
--- two common friends (1 and 6).
--- 
-------------------------------------------------------------------
WITH Friendship_Union 
AS
(
	SELECT
		user1_id,
		user2_id
	FROM
	   Friendship
	UNION
	SELECT
		user1_id = user2_id,
		user2_id = user1_id
	FROM
	   Friendship
),
Friendship_CTE
AS
(
	SELECT
		A.user1_id,
		A.user2_id,
		friend = B.user2_id
	FROM
	   Friendship AS A
	INNER JOIN 
	   Friendship_Union AS B
	ON
	   A.user1_id = B.user1_id
	INNER JOIN 
	   Friendship_Union AS C
	ON
	   A.user2_id = C.user1_id AND
       B.user2_id = C.user2_id
	WHERE
	   B.user2_id != A.user2_id
)
SELECT 
    user1_id, user2_id, common_friend = COUNT(*)
FROM 
    Friendship_CTE
GROUP BY 
    user1_id, user2_id
HAVING
    COUNT(*) >= 3