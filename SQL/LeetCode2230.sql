-----------------------------------------------------------------------
--- Leet Code 2230. The Users That Are Eligible for Discount
--- 
--- Easy
---
--- SQL Schema
--- Table: Purchases
---
--- +-------------+----------+
--- | Column Name | Type     |
--- +-------------+----------+
--- | user_id     | int      |
--- | time_stamp  | datetime |
--- | amount      | int      |
--- +-------------+----------+
--- (user_id, time_stamp) is the primary key for this table.
--- Each row contains information about the purchase time and the amount paid 
--- for the user with ID user_id.
--- 
--- A user is eligible for a discount if they had a purchase in the inclusive 
--- interval of time [startDate, endDate] with at least minAmount amount.
---
--- Write an SQL query to report the IDs of the users that are eligible for a 
--- discount.
---
--- Return the result table ordered by user_id.
---
--- The query result format is in the following example.
--- 
--- Example 1:
--- Input: 
--- Purchases table:
--- +---------+---------------------+--------+
--- | user_id | time_stamp          | amount |
--- +---------+---------------------+--------+
--- | 1       | 2022-04-20 09:03:00 | 4416   |
--- | 2       | 2022-03-19 19:24:02 | 678    |
--- | 3       | 2022-03-18 12:03:09 | 4523   |
--- | 3       | 2022-03-30 09:43:42 | 626    |
--- +---------+---------------------+--------+
--- startDate = 2022-03-08, endDate = 2022-03-20, minAmount = 1000
--- Output: 
--- +---------+
--- | user_id |
--- +---------+
--- | 3       |
--- +---------+
--- Explanation:
--- Out of the three users, only User 3 is eligible for a discount.
--- User 1 had one purchase with at least minAmount amount, but not within 
--- the time interval.
--- User 2 had one purchase within the time interval, but with less than 
--- minAmount amount.
--- User 3 is the only user who had a purchase that satisfies both conditions.
---------------------------------------------------------------
CREATE PROCEDURE getUserIDs(@startDate DATE, @endDate DATE, @minAmount INT) AS
BEGIN
    SELECT
        DISTINCT [user_id]
    FROM
        [Purchases]
    WHERE 
        time_stamp BETWEEN @startDate  AND @endDate AND [amount] >= @minAmount
END