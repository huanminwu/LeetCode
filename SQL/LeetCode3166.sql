-----------------------------------------------------------------------
--- LeetCode 3166. Calculate Parking Fees and Duration
--- 
--- Medium
---
--- SQL Schema
--- Pandas Schema
--- Table: ParkingTransactions
---
--- +--------------+-----------+
--- | Column Name  | Type      |
--- +--------------+-----------+
--- | lot_id       | int       |
--- | car_id       | int       |
--- | entry_time   | datetime  |
--- | exit_time    | datetime  |
--- | fee_paid     | decimal   |
--- +--------------+-----------+
--- (lot_id, car_id, entry_time) is the primary key (combination of columns 
--- with unique values) for this table.
--- Each row of this table contains the ID of the parking lot, the ID of the 
--- car, the entry and exit times, and the fee paid for the parking duration.
--- Write a solution to find the total parking fee paid by each car across all 
--- parking lots, and the average hourly fee (rounded to 2 decimal places) 
--- paid by each car. Also, find the parking lot where each car spent the most 
--- total time.
---
--- Return the result table ordered by car_id in ascending order.
---
--- Note: Test cases are generated in such a way that an individual car cannot 
--- be in multiple parking lots at the same time.
---
--- The result format is in the following example.
--- 
--- Example:
--- Input:
--- ParkingTransactions table:
--- +--------+--------+---------------------+---------------------+----------+
--- | lot_id | car_id | entry_time          | exit_time           | fee_paid |
--- +--------+--------+---------------------+---------------------+----------+
--- | 1      | 1001   | 2023-06-01 08:00:00 | 2023-06-01 10:30:00 | 5.00     |
--- | 1      | 1001   | 2023-06-02 11:00:00 | 2023-06-02 12:45:00 | 3.00     |
--- | 2      | 1001   | 2023-06-01 10:45:00 | 2023-06-01 12:00:00 | 6.00     |
--- | 2      | 1002   | 2023-06-01 09:00:00 | 2023-06-01 11:30:00 | 4.00     |
--- | 3      | 1001   | 2023-06-03 07:00:00 | 2023-06-03 09:00:00 | 4.00     |
--- | 3      | 1002   | 2023-06-02 12:00:00 | 2023-06-02 14:00:00 | 2.00     |
--- +--------+--------+---------------------+---------------------+----------+
--- Output:
---
--- +--------+----------------+----------------+---------------+
--- | car_id | total_fee_paid | avg_hourly_fee | most_time_lot |
--- +--------+----------------+----------------+---------------+
--- | 1001   | 18.00          | 2.40           | 1             |
--- | 1002   | 6.00           | 1.33           | 2             |
--- +--------+----------------+----------------+---------------+
--- Explanation:
---
--- For car ID 1001:
--- From 2023-06-01 08:00:00 to 2023-06-01 10:30:00 in lot 1: 2.5 hours, fee 5.00
--- From 2023-06-02 11:00:00 to 2023-06-02 12:45:00 in lot 1: 1.75 hours, fee 3.00
--- From 2023-06-01 10:45:00 to 2023-06-01 12:00:00 in lot 2: 1.25 hours, fee 6.00
--- From 2023-06-03 07:00:00 to 2023-06-03 09:00:00 in lot 3: 2 hours, fee 4.00
--- Total fee paid: 18.00, total hours: 7.5, average hourly fee: 2.40, most time 
--- spent in lot 1: 4.25 hours.
--- For car ID 1002:
--- From 2023-06-01 09:00:00 to 2023-06-01 11:30:00 in lot 2: 2.5 hours, fee 4.00
--- From 2023-06-02 12:00:00 to 2023-06-02 14:00:00 in lot 3: 2 hours, fee 2.00
--- Total fee paid: 6.00, total hours: 4.5, average hourly fee: 1.33, most 
--- time spent in lot 2: 2.5 hours.
--- Note: Output table is ordered by car_id in ascending order.
---------------------------------------------------------------
WITH Car_Transaction AS 
(
    SELECT
        car_id,
        lot_id,
        duration_seconds = SUM(DATEDIFF(SECOND, entry_time,  exit_time)),
        fee_paid = SUM(fee_paid)
    FROM
        ParkingTransactions
    GROUP BY 
        car_id,lot_id
)
SELECT
    A.car_id, 
    A.total_fee_paid,
    A.avg_hourly_fee,
    most_time_lot = B.lot_id
FROM
(
    SELECT
        car_id = car_id,
        total_fee_paid = SUM(fee_paid),
        avg_hourly_fee = CONVERT(DECIMAL(18, 2), SUM(fee_paid) * 3600 / SUM(duration_seconds)) 
    FROM 
        Car_Transaction 
    GROUP BY 
        car_id
) AS A
INNER JOIN
(
    SELECT
        car_id,
        lot_id
    FROM
    (
        SELECT 
            car_id,
            lot_id,
            RN = ROW_NUMBER() OVER (PARTITION BY car_id ORDER BY duration_seconds DESC)
        FROM
            Car_Transaction
    ) AS T
    WHERE RN = 1
) AS B
ON
    A.car_id = B.car_id
ORDER BY 
    car_id
;