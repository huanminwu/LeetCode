-----------------------------------------------------------------------
--- LeetCode 2687. Bikes Last Time Used
--- 
--- Easy
---
--- SQL Schema
---
--- Table: Bikes
---
--- +-------------+----------+ 
--- | Column Name | Type     | 
--- +-------------+----------+ 
--- | ride_id     | int      | 
--- | bike_number | int      | 
--- | start_time  | datetime |
--- | end_time    | datetime |
--- +-------------+----------+
--- ride_id is the primary key for this table.
--- Each row contains a ride information that includes ride_id, bike number, 
--- start and end time of the ride.
--- Write an SQL query to find the last time when each bike was used.
---
--- Return the result table ordered by the bikes that were most recently used.
---
--- The query result format is in the following example.
---
--- Example 1:
--- Input:
--- Bikes table:
--- +---------+-------------+---------------------+---------------------+ 
--- | ride_id | bike_number | start_time          | end_time            |  
--- +---------+-------------+---------------------+---------------------+
--- | 1       | W00576      | 2012-03-25 11:30:00 | 2012-03-25 12:40:00 |
--- | 2       | W00300      | 2012-03-25 10:30:00 | 2012-03-25 10:50:00 |
--- | 3       | W00455      | 2012-03-26 14:30:00 | 2012-03-26 17:40:00 |
--- | 4       | W00455      | 2012-03-25 12:30:00 | 2012-03-25 13:40:00 |
--- | 5       | W00576      | 2012-03-25 08:10:00 | 2012-03-25 09:10:00 |
--- | 6       | W00576      | 2012-03-28 02:30:00 | 2012-03-28 02:50:00 |
--- +---------+-------------+---------------------+---------------------+ 
---
--- Output:
--- +-------------+---------------------+ 
--- | bike_number | end_time            |  
--- +-------------+---------------------+
--- | W00576      | 2012-03-28 02:50:00 |
--- | W00455      | 2012-03-26 17:40:00 |
--- | W00300      | 2012-03-25 10:50:00 |
--- +-------------+---------------------+ 
--- Explanation: 
--- bike with number W00576 has three rides, out of that, most recent ride 
--- is with ride_id 6 which ended on 2012-03-28 02:50:00.
--- bike with number W00300 has only 1 ride so we will include end_time in 
--- output directly. 
--- bike with number W00455 has two rides, out of that, most recent ride 
--- is with ride_id 3 which ended on 2012-03-26 17:40:00. 
--- Returning output in order by the bike that were most recently used.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    bike_number,
    end_time
FROM
(
    SELECT 
        bike_number,
        end_time,
        RN = ROW_NUMBER() OVER (PARTITION BY bike_number ORDER BY end_time DESC)
    FROM
        Bikes
) AS T
WHERE
   RN = 1
;
