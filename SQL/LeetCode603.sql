-----------------------------------------------------------------------
--  LeetCode 603. Consecutive Available Seats
--  Easy
--
--  SQL Schema
--
--  Several friends at a cinema ticket office would like to reserve 
--  consecutive available seats.
--  Can you help to query all the consecutive available seats order by the 
--  seat_id using the following cinema table? 
--  | seat_id | free |
--  |---------|------|
--  | 1       | 1    |
--  | 2       | 0    |
--  | 3       | 1    |
--  | 4       | 1    |
--  | 5       | 1    |
-- 
--  Your query should return the following result for the sample case above.
--  
--  | seat_id |
--  |---------|
--  | 3       |
--  | 4       |
--  | 5       |
--  Note: 
--  The seat_id is an auto increment int, and free is bool ('1' means free,
--  and '0' means occupied.).
--  Consecutive available seats are more than 2(inclusive) seats 
--  consecutively available.
-----------------------------------------------------------------------
SELECT
    A.seat_id
FROM
    cinema AS A
LEFT OUTER JOIN 
    cinema AS B
ON
    A.seat_id = B.seat_id - 1
LEFT OUTER JOIN 
    cinema AS C
ON
    A.seat_id = C.seat_id + 1
WHERE A.free = 1 AND (B.free = 1 OR C.free = 1)
;