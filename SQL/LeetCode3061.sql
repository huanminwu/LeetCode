-----------------------------------------------------------------------
--- LeetCode 3061. Calculate Trapping Rain Water
--- 
--- Hard
---
--- SQL Schema
--- Pandas Schema
--- Table: Heights
---
--- +-------------+------+
--- | Column Name | Type |
--- +-------------+------+
--- | id          | int  |
--- | height      | int  |
--- +-------------+------+
--- id is the primary key (column with unique values) for this table, and it 
--- is guaranteed to be in sequential order.
--- Each row of this table contains an id and height.
--- Write a solution to calculate the amount of rainwater can be trapped 
--- between the bars in the landscape, considering that each bar has a width 
--- of 1 unit.
---
--- Return the result table in any order.
--- 
--- The result format is in the following example.
--- 
--- Example 1:
--- 
--- Input: 
--- Heights table:
--- +-----+--------+
--- | id  | height |
--- +-----+--------+
--- | 1   | 0      |
--- | 2   | 1      |
--- | 3   | 0      |
--- | 4   | 2      |
--- | 5   | 1      |
--- | 6   | 0      |
--- | 7   | 1      |
--- | 8   | 3      |
--- | 9   | 2      |
--- | 10  | 1      |
--- | 11  | 2      |
--- | 12  | 1      |
--- +-----+--------+
--- Output: 
--- +---------------------+
--- | total_trapped_water | 
--- +---------------------+
--- | 6                   | 
--- +---------------------+
--- Explanation: 
---
--- The elevation map depicted above (in the black section) is graphically 
--- represented with the x-axis denoting the id and the y-axis representing 
--- the heights [0,1,0,2,1,0,1,3,2,1,2,1]. In this scenario, 6 units of 
--- rainwater are trapped within the blue section.
---------------------------------------------------------------
SELECT 
    total_trapped_water = ISNULL(SUM([water]), 0)
FROM
(
    SELECT
        T.[id],
        [water] = CASE WHEN  [left_bar] < [right_bar] THEN [left_bar] - [height] ELSE [right_bar] - [height] END
    FROM
    (
        SELECT
            [id],
            [height],
            [left_bar] = ISNULL((SELECT MAX(height) FROM Heights AS B WHERE B.id < A.id), 0),
            [right_bar] = ISNULL((SELECT MAX(height) FROM Heights AS C WHERE C.id > A.id), 0)
        FROM
            Heights AS A
    ) AS T
) AS T
WHERE [water] > 0;
