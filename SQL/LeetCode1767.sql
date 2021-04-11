-----------------------------------------------------------------------
---  Leet code #1767. Find the Subtasks That Did Not Execute
--- 
---  Hard
--- 
---  SQL Schema
---  Table: Tasks
---  +----------------+---------+
---  | Column Name    | Type    |
---  +----------------+---------+
---  | task_id        | int     |
---  | subtasks_count | int     |
---  +----------------+---------+
---  task_id is the primary key for this table.
---  Each row in this table indicates that task_id was divided into 
---  subtasks_count subtasks labelled from 1 to subtasks_count.
---  It is guaranteed that 2 <= subtasks_count <= 20.
--- 
---  Table: Executed
---  +---------------+---------+
---  | Column Name   | Type    |
---  +---------------+---------+
---  | task_id       | int     |
---  | subtask_id    | int     |
---  +---------------+---------+
---  (task_id, subtask_id) is the primary key for this table.
---  Each row in this table indicates that for the task task_id, the subtask 
---  with ID subtask_id was executed successfully.
---  It is guaranteed that subtask_id <= subtasks_count for each task_id.
---  
---  Write an SQL query to report the IDs of the missing subtasks for each 
---  task_id.
--- 
---  Return the result table in any order.
---
---  The query result format is in the following example:
--- 
---  Tasks table:
---  +---------+----------------+
---  | task_id | subtasks_count |
---  +---------+----------------+
---  | 1       | 3              |
---  | 2       | 2              |
---  | 3       | 4              |
---  +---------+----------------+
---
---  Executed table:
---  +---------+------------+
---  | task_id | subtask_id |
---  +---------+------------+
---  | 1       | 2          |
---  | 3       | 1          |
---  | 3       | 2          |
---  | 3       | 3          |
---  | 3       | 4          |
---  +---------+------------+
---
---  Result table:
---  +---------+------------+
---  | task_id | subtask_id |
---  +---------+------------+
---  | 1       | 1          |
---  | 1       | 3          |
---  | 2       | 1          |
---  | 2       | 2          |
---  +---------+------------+
---  Task 1 was divided into 3 subtasks (1, 2, 3). Only subtask 2 was executed 
---  successfully, so we include (1, 1) and (1, 3) in the answer.
---  Task 2 was divided into 2 subtasks (1, 2). No subtask was executed 
---  successfully, so we include (2, 1) and (2, 2) in the answer.
---  Task 3 was divided into 4 subtasks (1, 2, 3, 4). All of the subtasks were 
---  executed successfully.
-----------------------------------------------------------------------
WITH Subtask_id AS (SELECT x.n
FROM (VALUES(1),(2),(3),(4),(5),(6),(7),(8),(9),(10),
            (11),(12),(13),(14),(15),(16),(17),(18),(19),(20)) x(n))
SELECT 
    A.task_id,
    B.n AS subtask_id   
FROM 
    Tasks A
CROSS JOIN
    Subtask_id AS B
LEFT OUTER JOIN
    Executed AS C
ON
    A.task_id = C.task_id AND
    B.n = C.subtask_id    
WHERE
    B.n <= A.subtasks_count AND 
    C.subtask_id IS NULL
;
