-----------------------------------------------------------------------
--- LeetCode 3374. First Letter Capitalization II
--- 
--- Hard
---
---
--- SQL Schema
--- Pandas Schema
--- Table: user_content
---
--- +-------------+---------+
--- | Column Name | Type    |
--- +-------------+---------+
--- | content_id  | int     |
--- | content_text| varchar |
--- +-------------+---------+
--- content_id is the unique key for this table.
--- Each row contains a unique ID and the corresponding text content.
--- Write a solution to transform the text in the content_text column by 
--- applying the following rules:
---
--- Convert the first letter of each word to uppercase and the remaining 
--- letters to lowercase
--- Special handling for words containing special characters:
--- For words connected with a hyphen -, both parts should be capitalized 
--- (e.g., top-rated → Top-Rated)
--- All other formatting and spacing should remain unchanged
--- Return the result table that includes both the original content_text 
--- and the modified text following the above rules.
---
--- The result format is in the following example.
---
--- Example:
---
--- Input:
---
--- user_content table:
---
--- +------------+---------------------------------+
--- | content_id | content_text                    |
--- +------------+---------------------------------+
--- | 1          | hello world of SQL              |
--- | 2          | the QUICK-brown fox             |
--- | 3          | modern-day DATA science         |
--- | 4          | web-based FRONT-end development |
--- +------------+---------------------------------+
--- Output:
---
--- +------------+---------------------------------+---------------------------------+
--- | content_id | original_text                   | converted_text                  |
--- +------------+---------------------------------+---------------------------------+
--- | 1          | hello world of SQL              | Hello World Of Sql              |
--- | 2          | the QUICK-brown fox             | The Quick-Brown Fox             |
--- | 3          | modern-day DATA science         | Modern-Day Data Science         |
--- | 4          | web-based FRONT-end development | Web-Based Front-End Development |
--- +------------+---------------------------------+---------------------------------+
--- Explanation:
---
--- For content_id = 1:
--- Each word's first letter is capitalized: "Hello World Of Sql"
--- For content_id = 2:
--- Contains the hyphenated word "QUICK-brown" which becomes "Quick-Brown"
--- Other words follow normal capitalization rules
--- For content_id = 3:
--- Hyphenated word "modern-day" becomes "Modern-Day"
--- "DATA" is converted to "Data"
--- For content_id = 4:
--- Contains two hyphenated words: "web-based" → "Web-Based"
--- And "FRONT-end" → "Front-End"
---------------------------------------------------------------
/* Write your T-SQL query statement below */
SELECT
    content_id,
    original_text,
    converted_text = STRING_AGG(word, ' ')  WITHIN GROUP ( ORDER BY [word_key] ASC )
FROM
(
     SELECT
         [content_id],
         [original_text],
         [word_key],
         [word] = STRING_AGG([phase], '-') WITHIN GROUP ( ORDER BY [phase_key] ASC )
     FROM
     (
        SELECT
              A.[content_id], 
              A.[original_text],
              A.[word_key],
              A.[word],
              [phase_key] = CONVERT(INT, B.[key]),
              [phase] = UPPER(SUBSTRING(B.value, 1, 1)) + LOWER(SUBSTRING(B.value, 2, LEN(B.value)))  
        FROM
        (
          SELECT 
              A.content_id, 
              original_text = A.content_text,
              [word_key] = CONVERT(INT, B.[key]),
              word = B.[value]
          FROM 
              user_content AS A
          CROSS APPLY 
              OpenJSON('["' + replace(A.content_text, ' ','","')+'"]') AS B
        ) AS A
        CROSS APPLY 
            OpenJSON('["' + replace(A.[word], '-','","')+'"]') AS B
    ) AS T
    GROUP BY content_id, original_text, word_key
) AS T
GROUP BY content_id, original_text
ORDER BY content_id;
