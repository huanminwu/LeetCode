-----------------------------------------------------------------------
--- Leet Code 3764. Most Common Course Pairs
---
--- Hard
---
--- SQL Schema
--- Pandas Schema
--- Table: course_completions
---
--- +-------------------+---------+
--- | Column Name       | Type    | 
--- +-------------------+---------+
--- | user_id           | int     |
--- | course_id         | int     |
--- | course_name       | varchar |
--- | completion_date   | date    |
--- | course_rating     | int     |
--- +-------------------+---------+
--- (user_id, course_id) is the combination of columns with unique values 
--- for this table.
--- Each row represents a completed course by a user with their rating 
--- (1-5 scale).
--- Write a solution to identify skill mastery pathways by analyzing course 
--- completion sequences among top-performing students:
---
--- Consider only top-performing students (those who completed at least 5 
--- courses with an average rating of 4 or higher).
--- For each top performer, identify the sequence of courses they completed 
--- in chronological order.
--- Find all consecutive course pairs (Course A -> Course B) taken by these 
--- students.
--- Return the pair frequency, identifying which course transitions are 
--- most common among high achievers.
--- Return the result table ordered by pair frequency in descending order 
--- and then by first course name and second course name in ascending order.
---
--- The result format is in the following example.
---
--- Example:
--- Input:
--- course_completions table:
---
--- +---------+-----------+------------------+-----------------+---------------+
--- | user_id | course_id | course_name      | completion_date | course_rating |
--- +---------+-----------+------------------+-----------------+---------------+
--- | 1       | 101       | Python Basics    | 2024-01-05      | 5             |
--- | 1       | 102       | SQL Fundamentals | 2024-02-10      | 4             |
--- | 1       | 103       | JavaScript       | 2024-03-15      | 5             |
--- | 1       | 104       | React Basics     | 2024-04-20      | 4             |
--- | 1       | 105       | Node.js          | 2024-05-25      | 5             |
--- | 1       | 106       | Docker           | 2024-06-30      | 4             |
--- | 2       | 101       | Python Basics    | 2024-01-08      | 4             |
--- | 2       | 104       | React Basics     | 2024-02-14      | 5             |
--- | 2       | 105       | Node.js          | 2024-03-20      | 4             |
--- | 2       | 106       | Docker           | 2024-04-25      | 5             |
--- | 2       | 107       | AWS Fundamentals | 2024-05-30      | 4             |
--- | 3       | 101       | Python Basics    | 2024-01-10      | 3             |
--- | 3       | 102       | SQL Fundamentals | 2024-02-12      | 3             |
--- | 3       | 103       | JavaScript       | 2024-03-18      | 3             |
--- | 3       | 104       | React Basics     | 2024-04-22      | 2             |
--- | 3       | 105       | Node.js          | 2024-05-28      | 3             |
--- | 4       | 101       | Python Basics    | 2024-01-12      | 5             |
--- | 4       | 108       | Data Science     | 2024-02-16      | 5             |
--- | 4       | 109       | Machine Learning | 2024-03-22      | 5             |
--- +---------+-----------+------------------+-----------------+---------------+
--- Output:
--- 
--- +------------------+------------------+------------------+
--- | first_course     | second_course    | transition_count |
--- +------------------+------------------+------------------+
--- | Node.js          | Docker           | 2                |
--- | React Basics     | Node.js          | 2                |
--- | Docker           | AWS Fundamentals | 1                |
--- | JavaScript       | React Basics     | 1                |
--- | Python Basics    | React Basics     | 1                |
--- | Python Basics    | SQL Fundamentals | 1                |
--- | SQL Fundamentals | JavaScript       | 1                |
--- +------------------+------------------+------------------+
--- Explanation:
---
--- User 1: Completed 6 courses with average rating 4.5 (qualifies as top performer)
--- User 2: Completed 5 courses with average rating 4.4 (qualifies as top performer)
--- User 3: Completed 5 courses but average rating is 2.8 (does not qualify)
--- User 4: Completed only 3 courses (does not qualify)
--- Course Pairs Among Top Performers:
--- User 1: Python Basics -> SQL Fundamentals -> JavaScript -> 
---         React Basics -> Node.js -> Docker
--- User 2: Python Basics -> React Basics -> Node.js -> 
---         Docker -> AWS Fundamentals
--- Most common transitions: Node.js -> Docker (2 times), 
---         React Basics -> Node.js (2 times)
--- Results are ordered by transition_count in descending order, 
--- then by first_course in ascending order, and then by second_course in 
--- ascending order.
---------------------------------------------------------------
/* Write your T-SQL query statement below */
WITH TopPerformerCourse AS
(
    SELECT
        [user_id],
        course_name,
        completion_date,
        RN = ROW_NUMBER() OVER (PARTITION BY [user_id] ORDER BY completion_date)
    FROM 
        course_completions
    WHERE 
        [user_id] IN
    (
        SELECT
            [user_id]
        FROM
        (
            SELECT
                [user_id],
                course_count = COUNT (DISTINCT course_id),
                avg_rating = AVG(course_rating) 
            FROM
                course_completions
            GROUP BY
                [user_id]
        ) AS T
        WHERE course_count >= 5 AND avg_rating >= 4
    )
)
SELECT
    [first_course],
    [second_course],
    [transition_count] = COUNT(*)
FROM
(
    SELECT
        [user_id] = A.[user_id],
        [first_course] = A.[course_name],
        [second_course] = B.[course_name]
    FROM
        TopPerformerCourse AS A
    INNER JOIN 
        TopPerformerCourse AS B
    ON
        A.[user_id] = B.[user_id] AND
        A.[RN] + 1 = B.[RN]
) AS T
GROUP BY 
    [first_course], 
    [second_course]
ORDER BY
    [transition_count] DESC,
    [first_course] ASC,
    [second_course] ASC
;