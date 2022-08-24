-----------------------------------------------------------------------
--- LeetCode 2377. Sort the Olympic Table
--- 
--- Easy
--- SQL Schema
--- Table: Olympic
---
--- +---------------+---------+
--- | Column Name   | Type    |
--- +---------------+---------+
--- | country       | varchar |
--- | gold_medals   | int     |
--- | silver_medals | int     |
--- | bronze_medals | int     |
--- +---------------+---------+
--- country is the primary key for this table.
--- Each row in this table shows a country name and the number of gold, 
--- silver, and bronze medals it won in the Olympic games.
--- 
---
--- The Olympic table is sorted according to the following rules:
---
--- The country with more gold medals comes first.
--- If there is a tie in the gold medals, the country with more silver medals 
--- comes first.
--- If there is a tie in the silver medals, the country with more bronze medals 
--- comes first.
--- If there is a tie in the bronze medals, the countries with the tie are 
--- sorted in ascending order lexicographically.
--- Write an SQL query to sort the Olympic table
--- 
--- The query result format is shown in the following example.
---
---  
--- Example 1:
--- 
--- Input: 
--- Olympic table:
--- +-------------+-------------+---------------+---------------+
--- | country     | gold_medals | silver_medals | bronze_medals |
--- +-------------+-------------+---------------+---------------+
--- | China       | 10          | 10            | 20            |
--- | South Sudan | 0           | 0             | 1             |
--- | USA         | 10          | 10            | 20            |
--- | Israel      | 2           | 2             | 3             |
--- | Egypt       | 2           | 2             | 2             |
--- +-------------+-------------+---------------+---------------+
--- Output: 
--- +-------------+-------------+---------------+---------------+
--- | country     | gold_medals | silver_medals | bronze_medals |
--- +-------------+-------------+---------------+---------------+
--- | China       | 10          | 10            | 20            |
--- | USA         | 10          | 10            | 20            |
--- | Israel      | 2           | 2             | 3             |
--- | Egypt       | 2           | 2             | 2             |
--- | South Sudan | 0           | 0             | 1             |
--- +-------------+-------------+---------------+---------------+
--- Explanation: 
--- The tie between China and USA is broken by their lexicographical names. 
--- Since "China" is lexicographically smaller than "USA", it comes first.
--- Israel comes before Egypt because it has more bronze medals.
---------------------------------------------------------------
SELECT
    country,
	gold_medals,
	silver_medals,
	bronze_medals
FROM
	Olympic
ORDER BY
	gold_medals DESC,
	silver_medals DESC,
	bronze_medals DESC,
	country
;