-----------------------------------------------------------------------
--- LeetCode 2504. Concatenate the Name and the Profession
--- 
--- Easy
---
--- SQL Schema
--- Table: Person
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | person_id   | int     |
--- | name        | varchar |
--- | profession  | ENUM    |
--- +-------------+---------+
--- person_id is the primary key for this table.
--- Each row in this table contains a person's ID, name, and profession.
--- The profession   column in an enum of the type ('Doctor', 'Singer', 
--- 'Actor', 'Player', 'Engineer', or 'Lawyer')
---  
---
--- Write an SQL query to report each person's name followed by the first 
--- letter of their profession enclosed in parentheses.
---
--- Return the result table ordered by person_id in descending order.
---
--- The query result format is shown in the following example.
---
--- Example 1:
---
--- Input: 
--- Person table:
--- +-----------+-------+------------+
--- | person_id | name  | profession |
--- +-----------+-------+------------+
--- | 1         | Alex  | Singer     |
--- | 3         | Alice | Actor      |
--- | 2         | Bob   | Player     |
--- | 4         | Messi | Doctor     |
--- | 6         | Tyson | Engineer   |
--- | 5         | Meir  | Lawyer     |
--- +-----------+-------+------------+
--- Output: 
--- +-----------+----------+
--- | person_id | name     |
--- +-----------+----------+
--- | 6         | Tyson(E) |
--- | 5         | Meir(L)  |
--- | 4         | Messi(D) |
--- | 3         | Alice(A) |
--- | 2         | Bob(P)   |
--- | 1         | Alex(S)  |
--- +-----------+----------+
--- Explanation: Note that there should not be any white space between the 
--- name and the first letter of the profession.
---------------------------------------------------------------
SELECT
    person_id, 
	name + '(' + substr(profession, 1, 1) + ')' AS name
FROM 
    Person
ORDER BY 
    person_id DESC
;