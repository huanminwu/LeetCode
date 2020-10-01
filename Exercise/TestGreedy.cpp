#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeGreedy.h"
#include "TestGreedy.h"

void TestLeetCode826(void)
{
    Logger::WriteMessage("Test Leet Code 826");
    LeetCodeGreedy leetCode;
    vector<int> difficulty = { 2, 4, 6, 8, 10 };
    vector<int> profit = { 10, 20, 30, 40, 50 };
    vector<int> worker = { 4, 5, 6, 7 };
    int result = leetCode.maxProfitAssignment(difficulty, profit, worker);
    Logger::WriteMessage(difficulty);
    Logger::WriteMessage(profit);
    Logger::WriteMessage(worker);
    Logger::WriteMessage("result = " + to_string(result));


    difficulty = { 66, 1, 28, 73, 53, 35, 45, 60, 100, 44, 59, 94, 27, 88, 7, 18, 83, 18, 72, 63 };
    profit = { 66, 20, 84, 81, 56, 40, 37, 82, 53, 45, 43, 96, 67, 27, 12, 54, 98, 19, 47, 77 };
    worker = { 23, 66, 70, 14, 51, 94, 18, 28, 78, 100, 16, 61, 33, 68, 38, 63, 45, 1, 10, 53 };
    result = leetCode.maxProfitAssignment(difficulty, profit, worker);
    Logger::WriteMessage(difficulty);
    Logger::WriteMessage(profit);
    Logger::WriteMessage(worker);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1229(void)
{
    Logger::WriteMessage("Test Leet Code 1229");
    LeetCodeGreedy leetCode;
    vector<vector<int>> slots1 = { {10, 50},{60, 120},{140, 210} };
    vector<vector<int>> slots2 = { {0, 15}, { 60, 70 }};
    int duration = 8;
    vector<int> result = leetCode.minAvailableDuration(slots1, slots2, duration);
    Logger::WriteMessage(slots1);
    Logger::WriteMessage(slots2);
    Logger::WriteMessage("duration = " + to_string(duration));
    Logger::WriteMessage(result);

    slots1 = { {10, 50},{60, 120},{140, 210} };
    slots2 = { {0, 15}, { 60, 70 } };
    duration = 12;
    result = leetCode.minAvailableDuration(slots1, slots2, duration);
    Logger::WriteMessage(slots1);
    Logger::WriteMessage(slots2);
    Logger::WriteMessage("duration = " + to_string(duration));
    Logger::WriteMessage(result);
}

void TestLeetCode1272(void)
{
    Logger::WriteMessage("Test Leet Code 1272");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = { {0, 2},{3, 4},{5, 7} };
    vector<int> toBeRemoved = { 1, 6 };
    vector<vector<int>> result = leetCode.removeInterval(intervals, toBeRemoved);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(toBeRemoved);
    Logger::WriteMessage(result);

    intervals = { {0,5} };
    toBeRemoved = { 2,3 };
    result = leetCode.removeInterval(intervals, toBeRemoved);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(toBeRemoved);
    Logger::WriteMessage(result);

    intervals = { {0, 4},{3, 5},{7, 10} };
    toBeRemoved = { 4,6 };
    result = leetCode.removeInterval(intervals, toBeRemoved);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(toBeRemoved);
    Logger::WriteMessage(result);
}

void TestLeetCode1288(void)
{
    Logger::WriteMessage("Test Leet Code 1288");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = { {1, 4},{3, 6},{2, 8} };
    Logger::WriteMessage(intervals);
    int result = leetCode.removeCoveredIntervals(intervals);
    Logger::WriteMessage("result = " + to_string(result));

    intervals = { {1, 2},{1, 8},{2, 5},{2, 9} };
    Logger::WriteMessage(intervals);
    result = leetCode.removeCoveredIntervals(intervals);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1326(void)
{
    Logger::WriteMessage("Test Leet Code 1326");
    LeetCodeGreedy leetCode;
    int n = 5;
    vector<int> ranges = { 3, 4, 1, 1, 0, 0 };
    int result = leetCode.minTaps(n, ranges);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    ranges = { 0,0,0,0 };
    result = leetCode.minTaps(n, ranges);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7;
    ranges = { 1,2,1,0,2,1,0,1 };
    result = leetCode.minTaps(n, ranges);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 8;
    ranges = { 4,0,0,0,0,0,0,0,4 };
    result = leetCode.minTaps(n, ranges);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 8;
    ranges = { 4,0,0,0,4,0,0,0,4 };
    result = leetCode.minTaps(n, ranges);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 9;
    ranges = { 0, 5, 0, 3, 3, 3, 1, 4, 0, 4 };
    result = leetCode.minTaps(n, ranges);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 17;
    ranges = { 0, 3, 3, 2, 2, 4, 2, 1, 5, 1, 0, 1, 2, 3, 0, 3, 1, 1 };
    result = leetCode.minTaps(n, ranges);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1353(void)
{
    Logger::WriteMessage("Test Leet Code 1353");
    LeetCodeGreedy leetCode;
    vector<vector<int>> events = { {1, 2},{2, 3},{3, 4} };
    int result = leetCode.maxEvents(events);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));

    events = { {1,2},{2,3},{3,4},{1,2} };
    result = leetCode.maxEvents(events);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));

    events = { {1, 100000} };
    result = leetCode.maxEvents(events);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));

    events = { {1, 1},{1, 2},{1, 3},{1, 4},{1, 5},{1, 6},{1, 7} };
    result = leetCode.maxEvents(events);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1383(void)
{
    Logger::WriteMessage("Test Leet Code 1383");
    LeetCodeGreedy leetCode;
    int n = 6;
    vector<int> speed = { 2, 10, 3, 1, 5, 8 };
    vector<int> efficiency = { 5, 4, 3, 9, 7, 2 };
    int k = 2;
    int result = leetCode.maxPerformance(n, speed, efficiency, k);
    Logger::WriteMessage(speed);
    Logger::WriteMessage(efficiency);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 6;
    speed = { 2, 10, 3, 1, 5, 8 };
    efficiency = { 5, 4, 3, 9, 7, 2 };
    k = 3;
    result = leetCode.maxPerformance(n, speed, efficiency, k);
    Logger::WriteMessage(speed);
    Logger::WriteMessage(efficiency);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 6;
    speed = { 2, 10, 3, 1, 5, 8 };
    efficiency = { 5, 4, 3, 9, 7, 2 };
    k = 4;
    result = leetCode.maxPerformance(n, speed, efficiency, k);
    Logger::WriteMessage(speed);
    Logger::WriteMessage(efficiency);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 6;
    speed = { 10, 5, 1, 7, 4, 2 };
    efficiency = { 2, 1, 1, 1, 7, 3 };
    k = 6;
    result = leetCode.maxPerformance(n, speed, efficiency, k);
    Logger::WriteMessage(speed);
    Logger::WriteMessage(efficiency);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 8;
    speed = { 9, 9, 4, 6, 9, 7, 9, 8 };
    efficiency = { 1, 9, 1, 9, 8, 1, 10, 1 };
    k = 4;
    result = leetCode.maxPerformance(n, speed, efficiency, k);
    Logger::WriteMessage(speed);
    Logger::WriteMessage(efficiency);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 5;
    speed = { 10, 10, 7, 9, 8 };
    efficiency = { 9, 8, 3, 6, 9 };
    k = 1;
    result = leetCode.maxPerformance(n, speed, efficiency, k);
    Logger::WriteMessage(speed);
    Logger::WriteMessage(efficiency);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1405(void)
{
    Logger::WriteMessage("Test Leet Code 1405");
    LeetCodeGreedy leetCode;
    int a = 1;
    int b = 1;
    int c = 7;
    string result = leetCode.longestDiverseString(a, b, c);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) + 
        "; c = " + to_string(c) + "; result = " + result);

    a = 2;
    b = 2;
    c = 1;
    result = leetCode.longestDiverseString(a, b, c);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) +
        "; c = " + to_string(c) + "; result = " + result);

    a = 7;
    b = 1;
    c = 0;
    result = leetCode.longestDiverseString(a, b, c);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) +
        "; c = " + to_string(c) + "; result = " + result);
}

void TestLeetCode1419(void)
{
    Logger::WriteMessage("Test Leet Code 1419");
    LeetCodeGreedy leetCode;
    string croakOfFrogs = "croakcroak";
    int result = leetCode.minNumberOfFrogs(croakOfFrogs);
    Logger::WriteMessage("croakOfFrogs = " + croakOfFrogs + "; result = " + to_string(result));

    croakOfFrogs = "crcoakroak";
    result = leetCode.minNumberOfFrogs(croakOfFrogs);
    Logger::WriteMessage("croakOfFrogs = " + croakOfFrogs + "; result = " + to_string(result));

    croakOfFrogs = "croakcrook";
    result = leetCode.minNumberOfFrogs(croakOfFrogs);
    Logger::WriteMessage("croakOfFrogs = " + croakOfFrogs + "; result = " + to_string(result));

    croakOfFrogs = "croakcroa";
    result = leetCode.minNumberOfFrogs(croakOfFrogs);
    Logger::WriteMessage("croakOfFrogs = " + croakOfFrogs + "; result = " + to_string(result));
}

void TestLeetCode1520(void)
{
    Logger::WriteMessage("Test Leet Code 1520");
    LeetCodeGreedy leetCode;
    string s = "adefaddaccc";
    vector<string> result = leetCode.maxNumOfSubstrings(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    s = "abbaccd";
    result = leetCode.maxNumOfSubstrings(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);
}

void TestLeetCode1562(void)
{
    Logger::WriteMessage("Test Leet Code 1562");
    LeetCodeGreedy leetCode;
    vector<int> arr = { 3,5,1,2,4 };
    int m = 1;
    int result = leetCode.findLatestStep(arr, m);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));

    arr = { 3,1,5,4,2 };
    m = 2;
    result = leetCode.findLatestStep(arr, m);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));

    arr = { 1 };
    m = 1;
    result = leetCode.findLatestStep(arr, m);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));

    arr = { 2, 1 };
    m = 2;
    result = leetCode.findLatestStep(arr, m);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));
}

void TestLeetCode1589(void)
{
    Logger::WriteMessage("Test Leet Code 1589");
    LeetCodeGreedy leetCode;
    vector<int> nums = { 1,2,3,4,5 };
    vector<vector<int>> requests = { {1, 3},{0, 1} };
    int result = leetCode.maxSumRangeQuery(nums, requests);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(requests);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,5,6 };
    requests = { {0, 1} };
    result = leetCode.maxSumRangeQuery(nums, requests);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(requests);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,5,10 };
    requests = { {0,2} ,{1,3},{1,1} };
    result = leetCode.maxSumRangeQuery(nums, requests);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(requests);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCodeGreedy(void)
{
    TestLeetCode1589();
    TestLeetCode1520();
    TestLeetCode826();
    TestLeetCode1419();
    TestLeetCode1405();
    TestLeetCode1383();
    TestLeetCode1353();
    TestLeetCode352();
    TestLeetCode1326();
    TestLeetCode1288();
    TestLeetCode1272();
    TestLeetCode1229();
}
