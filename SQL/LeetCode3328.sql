-----------------------------------------------------------------------
--- LeetCode 3328. Premier League Table Ranking III
--- 
--- Medium
---
--- SQL Schema
--- Pandas Schema
--- Table: cities
--- +-------------+---------+
--- | Column Name | Type    | 
--- +-------------+---------+
--- | state       | varchar |
--- | city        | varchar |
--- +-------------+---------+
--- (state, city) is the combination of columns with unique values for 
--- this table.
--- Each row of this table contains the state name and the city name 
--- within that state.
--- Write a solution to find all the cities in each state and analyze them 
--- based on the following requirements:
---
--- Combine all cities into a comma-separated string for each state.
--- Only include states that have at least 3 cities.
--- Only include states where at least one city starts with the same 
--- letter as the state name.
--- Return the result table ordered by the count of matching-letter cities 
--- in descending order and then by state name in ascending order.
---
--- The result format is in the following example.
--- 
--- Example:
--- Input:
--- cities table:
--- +--------------+---------------+
--- | state        | city          |
--- +--------------+---------------+
--- | New York     | New York City |
--- | New York     | Newark        |
--- | New York     | Buffalo       |
--- | New York     | Rochester     |
--- | California   | San Francisco |
--- | California   | Sacramento    |
--- | California   | San Diego     |
--- | California   | Los Angeles   |
--- | Texas        | Tyler         |
--- | Texas        | Temple        |
--- | Texas        | Taylor        |
--- | Texas        | Dallas        |
--- | Pennsylvania | Philadelphia  |
--- | Pennsylvania | Pittsburgh    |
--- | Pennsylvania | Pottstown     |
--- +--------------+---------------+
--- Output:
----
--- +-------------+-------------------------------------------+-----------------------+
--- | state       | cities                                    | matching_letter_count |
--- +-------------+-------------------------------------------+-----------------------+
--- | Pennsylvania| Philadelphia, Pittsburgh, Pottstown       | 3                     |
--- | Texas       | Dallas, Taylor, Temple, Tyler             | 2                     |
--- | New York    | Buffalo, Newark, New York City, Rochester | 2                     |
--- +-------------+-------------------------------------------+-----------------------+
--- Explanation:
---
--- Pennsylvania:
--- Has 3 cities (meets minimum requirement)
--- All 3 cities start with 'P' (same as state)
--- matching_letter_count = 3
--- Texas:
--- Has 4 cities (meets minimum requirement)
--- 2 cities (Temple, Tyler) start with 'T' (same as state)
--- matching_letter_count = 2
--- New York:
--- Has 4 cities (meets minimum requirement)
--- 2 cities (Newark, New York City) start with 'N' (same as state)
--- matching_letter_count = 2
--- California is not included in the output because:
--- Although it has 4 cities (meets minimum requirement)
--- No cities start with 'C' (doesn't meet the matching letter requirement)
--- Note:
---
--- Results are ordered by matching_letter_count in descending order
--- When matching_letter_count is the same (Texas and New York both have 2), 
--- they are ordered by state name alphabetically
--- Cities in each row are ordered alphabetically
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    A.[state],
    A.[cities],
    B.[matching_letter_count]
FROM
(
    SELECT
        [state],
        [cities] = STRING_AGG(city, ', ') WITHIN GROUP (ORDER BY city ASC)
    FROM
        cities
    GROUP BY
        [state]
) AS A
INNER JOIN
(
    SELECT
        [state],
        [matching_letter_count] = count(*)
    FROM
        cities
    WHERE 
        SUBSTRING([state], 1, 1) = SUBSTRING([city], 1, 1)
    GROUP BY
        [state]
) AS B
ON
    A.[state] = B.[state]
INNER JOIN
(
    SELECT
        [state],
        [count] = count(*)
    FROM
        cities
    GROUP BY
        [state]
) AS C
ON
   A.[state] = C.[state]
WHERE
    C.[count] >= 3
ORDER BY
    [matching_letter_count] DESC
;