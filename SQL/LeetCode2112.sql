-----------------------------------------------------------------------
--- Leet code 2112. The Airport With the Most Traffic
---
--- Medium
--- SQL Schema
---
--- Table: Flights
---
--- +-------------------+------+
--- | Column Name       | Type |
--- +-------------------+------+
--- | departure_airport | int  |
--- | arrival_airport   | int  |
--- | flights_count     | int  |
--- +-------------------+------+
--- (departure_airport, arrival_airport) is the primary key column for this 
--- table.
--- Each row of this table indicates that there were flights_count that 
--- departed from departure_airport and arrived at arrival_airport.
--- 
--- Write an SQL query to report the ID of the airport with the most traffic. 
--- The airport with the most traffic is the airport that has the largest 
--- number of flights that either departed from or arrived at the airport. 
--- If there is more than one airport with the most traffic, report them all.
---
--- Return the result table in any order.
---
--- The query result format is in the following example.
---
--- Example 1:
--- 
--- Input: 
--- Flights table:
--- +-------------------+-----------------+---------------+
--- | departure_airport | arrival_airport | flights_count |
--- +-------------------+-----------------+---------------+
--- | 1                 | 2               | 4             |
--- | 2                 | 1               | 5             |
--- | 2                 | 4               | 5             |
--- +-------------------+-----------------+---------------+
--- Output: 
--- +------------+
--- | airport_id |
--- +------------+
--- | 2          |
--- +------------+
--- Explanation: 
--- Airport 1 was engaged with 9 flights.
--- Airport 2 was engaged with 14 flights.
--- Airport 4 was engaged with 5 flights.
--- The airport with the most traffic is airport 2.
---
--- Example 2:
---
--- Input: 
--- Flights table:
--- +-------------------+-----------------+---------------+
--- | departure_airport | arrival_airport | flights_count |
--- +-------------------+-----------------+---------------+
--- | 1                 | 2               | 4             |
--- | 2                 | 1               | 5             |
--- | 3                 | 4               | 5             |
--- | 4                 | 3               | 4             |
--- | 5                 | 6               | 7             |
--- +-------------------+-----------------+---------------+
--- Output: 
--- +------------+
--- | airport_id |
--- +------------+
--- | 1          |
--- | 2          |
--- | 3          |
--- | 4          |
--- +------------+
--- Explanation: 
--- Airport 1 was engaged with 9 flights.
--- Airport 2 was engaged with 9 flights.
--- Airport 3 was engaged with 9 flights.
--- Airport 4 was engaged with 9 flights.
--- Airport 5 was engaged with 7 flights.
--- Airport 6 was engaged with 7 flights.
--- The airports with the most traffic are airports 1, 2, 3, and 4.
---
---------------------------------------------------------------
SELECT 
    airport_id = airport
FROM
(
	SELECT
		airport,
		RN = RANK() OVER (ORDER BY flights_count DESC)
	FROM
	(
		SELECT
			airport,
			flights_count = SUM(flights_count)
		FROM
		(
			SELECT
				airport = departure_airport,
				flights_count
			FROM 
				Flights
			UNION ALL
			SELECT
				airport = arrival_airport,
				flights_count
			FROM 
				Flights
		) AS T
		GROUP BY
			airport
	) AS T
) AS T
WHERE 
    RN = 1
ORDER BY
    airport
;
