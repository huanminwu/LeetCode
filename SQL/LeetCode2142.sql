-----------------------------------------------------------------------
--- Leet code 2142. The Number of Passengers in Each Bus I
---
--- Medium
---
--- SQL Schema
---
--- Table: Buses
--- 
--- +--------------+------+
--- | Column Name  | Type |
--- +--------------+------+
--- | bus_id       | int  |
--- | arrival_time | int  |
--- +--------------+------+
--- bus_id is the primary key column for this table.
--- Each row of this table contains information about the arrival time of a 
--- bus at the Leetcode station.
--- There will be no two buses that arrive at the same time.
--- 
---
--- Table: Passengers
--- +--------------+------+
--- | Column Name  | Type |
--- +--------------+------+
--- | passenger_id | int  |
--- | arrival_time | int  |
--- +--------------+------+
--- passenger_id is the primary key column for this table.
--- Each row of this table contains information about the arrival time of a 
--- passenger at the Leetcode station.
--- 
--- Buses and passengers arrive at the Leetcode station. If a bus arrives at 
--- the station at a time tbus and a passenger arrived at a time tpassenger 
--- where tpassenger <= tbus and the passenger did not catch any bus, the 
--- passenger will use that bus.
---
--- Write an SQL query to report the number of users that used each bus.
---
--- Return the result table ordered by bus_id in ascending order.
---
--- The query result format is in the following example.
--- 
--- Example 1:
--- 
--- Input: 
--- Buses table:
--- +--------+--------------+
--- | bus_id | arrival_time |
--- +--------+--------------+
--- | 1      | 2            |
--- | 2      | 4            |
--- | 3      | 7            |
--- +--------+--------------+
---
--- Passengers table:
--- +--------------+--------------+
--- | passenger_id | arrival_time |
--- +--------------+--------------+
--- | 11           | 1            |
--- | 12           | 5            |
--- | 13           | 6            |
--- | 14           | 7            |
--- +--------------+--------------+
--- Output: 
--- +--------+----------------+
--- | bus_id | passengers_cnt |
--- +--------+----------------+
--- | 1      | 1              |
--- | 2      | 0              |
--- | 3      | 3              |
--- +--------+----------------+
--- Explanation: 
--- Passenger 11 arrives at time 1.
--- Bus 1 arrives at time 2 and collects passenger 11.
---
--- Bus 2 arrives at time 4 and does not collect any passengers.
---
--- Passenger 12 arrives at time 5.
--- Passenger 13 arrives at time 6.
--- Passenger 14 arrives at time 7.
--- Bus 3 arrives at time 7 and collects passengers 12, 13, and 14.
---
---------------------------------------------------------------
SELECT
    A.bus_id,
	passengers_cnt = ISNULL(COUNT(DISTINCT B.passenger_id), 0)
FROM
   Buses AS A
LEFT OUTER JOIN
(
	SELECT
		A.passenger_id,
		A.arrival_time,
		bus_arrival_time = (SELECT TOP 1 arrival_time FROM Buses AS B WHERE A.arrival_time <= B.arrival_time ORDER BY B.arrival_time) 
	FROM 
	   Passengers AS A
) AS B
ON
   A.arrival_time = B.bus_arrival_time
GROUP BY
   A.bus_id
;