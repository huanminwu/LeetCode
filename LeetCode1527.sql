-----------------------------------------------------------------------
---  Leet code #1527. Patients With a Condition 
--- 
---  Table: Patients
--- 
---  +--------------+---------+
---  | Column Name  | Type    |
---  +--------------+---------+
---  | patient_id   | int     |
---  | patient_name | varchar |
---  | conditions   | varchar |
---  +--------------+---------+
---  patient_id is the primary key for this table.
---  'conditions' contains 0 or more code separated by spaces. 
---  This table contains information of the patients in the hospital.
--- 
---  Write an SQL query to report the patient_id, patient_name all conditions 
---  of patients who have Type I Diabetes. Type I Diabetes always starts with 
---  DIAB1 prefix
--- 
---  Return the result table in any order.
---
---  The query result format is in the following example.
---
---  Patients
---  +------------+--------------+--------------+
---  | patient_id | patient_name | conditions   |
---  +------------+--------------+--------------+
---  | 1          | Daniel       | YFEV COUGH   |
---  | 2          | Alice        |              |
---  | 3          | Bob          | DIAB100 MYOP |
---  | 4          | George       | ACNE DIAB100 |
---  | 5          | Alain        | DIAB201      |
---  +------------+--------------+--------------+
---
---  Result table:
---  +------------+--------------+--------------+
---  | patient_id | patient_name | conditions   |
---  +------------+--------------+--------------+
---  | 3          | Bob          | DIAB100 MYOP |
---  | 4          | George       | ACNE DIAB100 | 
---  +------------+--------------+--------------+
---  Bob and George both have a condition that starts with DIAB1.
-----------------------------------------------------------------------
SELECT
    patient_id,
    patient_name,
    conditions
FROM
    Patients
WHERE
    conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%'
