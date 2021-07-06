-----------------------------------------------------------------------
---  Leet code 1919. Leetcodify Similar Friends
--- 
--- Hard
---
--- SQL Schema
--- Table: Listens
--- 
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | user_id     | int     |
--- | song_id     | int     |
--- | day         | date    |
--- +-------------+---------+
--- There is no primary key for this table. It may contain duplicates.
--- Each row of this table indicates that the user user_id listened to the 
--- song song_id on the day day.
---
--- Table: Friendship
--- +---------------+---------+
--- | Column Name   | Type    |
--- +---------------+---------+
--- | user1_id      | int     |
--- | user2_id      | int     |
--- +---------------+---------+
--- (user1_id, user2_id) is the primary key for this table.
--- Each row of this table indicates that the users user1_id and user2_id are 
--- friends.
--- Note that user1_id < user2_id.
--- 
--- Write an SQL query to report the similar friends of Leetcodify users. 
--- A user x and user y are similar friends if:
---
--- Users x and y are friends, and
--- Users x and y listened to the same three or more different songs on the 
--- same day.
--- Return the result table in any order. Note that you must return the 
--- similar pairs of friends the same way they were represented in the input 
--- (i.e., always user1_id < user2_id).
---
--- The query result format is in the following example:
--- 
--- Listens table:
--- +---------+---------+------------+
--- | user_id | song_id | day        |
--- +---------+---------+------------+
--- | 1       | 10      | 2021-03-15 |
--- | 1       | 11      | 2021-03-15 |
--- | 1       | 12      | 2021-03-15 |
--- | 2       | 10      | 2021-03-15 |
--- | 2       | 11      | 2021-03-15 |
--- | 2       | 12      | 2021-03-15 |
--- | 3       | 10      | 2021-03-15 |
--- | 3       | 11      | 2021-03-15 |
--- | 3       | 12      | 2021-03-15 |
--- | 4       | 10      | 2021-03-15 |
--- | 4       | 11      | 2021-03-15 |
--- | 4       | 13      | 2021-03-15 |
--- | 5       | 10      | 2021-03-16 |
--- | 5       | 11      | 2021-03-16 |
--- | 5       | 12      | 2021-03-16 |
--- +---------+---------+------------+
---
--- Friendship table:
--- +----------+----------+
--- | user1_id | user2_id |
--- +----------+----------+
--- | 1        | 2        |
--- | 2        | 4        |
--- | 2        | 5        |
--- +----------+----------+
---
--- Result table:
--- +----------+----------+
--- | user1_id | user2_id |
--- +----------+----------+
--- | 1        | 2        |
--- +----------+----------+
---
--- Users 1 and 2 are friends, and they listened to songs 10, 11, and 12 on 
--- the same day. They are similar friends.
--- Users 1 and 3 listened to songs 10, 11, and 12 on the same day, but 
--- they are not friends.
--- Users 2 and 4 are friends, but they did not listen to the same three 
--- different songs.
--- Users 2 and 5 are friends and listened to songs 10, 11, and 12, but 
--- they did not listen to them on the same day.
-----------------------------------------------------------------------
WITH Recommendations AS
(
    SELECT user1_id = A.user_id, user2_id = B.user_id 
	FROM Listens AS A INNER JOIN Listens AS B 
    ON A.user_id < B.user_id and A.song_id = B.song_id and A.day = B.day 
	GROUP BY A.user_id, B.user_id,A.day 
	HAVING count(distinct A.song_id) >=3
)
SELECT
     DISTINCT user1_id, user2_id 
FROM Recommendations R 
WHERE EXISTS 
(
    SELECT 1 from Friendship F WHERE F.user1_id  = R.user1_id and F.user2_id = R.user2_id
) 
