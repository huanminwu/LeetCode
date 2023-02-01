#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeGreedy.h"
#include "TestGreedy.h"

void TestLeetCode56(void)
{
    Logger::WriteMessage("Test Leet Code 56");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = {{ 1, 3 },{ 2, 6 },{ 8, 10 },{ 15, 18 }};
    vector<vector<int>> result = leetCode.merge(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(result);

    intervals = { {1, 4},{4, 5} };
    result = leetCode.merge(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(result);
}

void TestLeetCode57(void)
{
    Logger::WriteMessage("Test Leet Code 57");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = { {1, 3},{6, 9} };
    vector<int> newInterval = { 2, 5 };
    vector<vector<int>> result = leetCode.insert(intervals, newInterval);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(newInterval);
    Logger::WriteMessage(result);

    intervals = { {1, 2},{3, 5},{6, 7},{8, 10},{12, 16} };
    newInterval = { 4,8 };
    result = leetCode.insert(intervals, newInterval);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(newInterval);
    Logger::WriteMessage(result);

    intervals = { };
    newInterval = { 5,7 };
    result = leetCode.insert(intervals, newInterval);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(newInterval);
    Logger::WriteMessage(result);

    intervals = { {1,5} };
    newInterval = { 2,3 };
    result = leetCode.insert(intervals, newInterval);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(newInterval);
    Logger::WriteMessage(result);

    intervals = { {1,5} };
    newInterval = { 2,7 };
    result = leetCode.insert(intervals, newInterval);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(newInterval);
    Logger::WriteMessage(result);
}

void TestLeetCode452(void)
{
    Logger::WriteMessage("Test Leet Code 452");
    LeetCodeGreedy leetCode;
    vector<vector<int>> points = { {10, 16},{2, 8},{1, 6},{7, 12} };
    Logger::WriteMessage(points);
    int result = leetCode.findMinArrowShots(points);
    Logger::WriteMessage("Min Arrow Shots = " + to_string(result));

    points = { {1, 2},{3, 4},{5, 6},{7, 8} };
    Logger::WriteMessage(points);
    result = leetCode.findMinArrowShots(points);
    Logger::WriteMessage("Min Arrow Shots = " + to_string(result));

    points = { {1, 2},{2, 3},{3, 4},{4, 5} };
    Logger::WriteMessage(points);
    result = leetCode.findMinArrowShots(points);
    Logger::WriteMessage("Min Arrow Shots = " + to_string(result));

    points = { {1, 2} };
    Logger::WriteMessage(points);
    result = leetCode.findMinArrowShots(points);
    Logger::WriteMessage("Min Arrow Shots = " + to_string(result));

    points = { {2, 3},{2, 3} };
    Logger::WriteMessage(points);
    result = leetCode.findMinArrowShots(points);
    Logger::WriteMessage("Min Arrow Shots = " + to_string(result));
}

void TestLeetCode495(void)
{
    Logger::WriteMessage("Test Leet Code 495");
    LeetCodeGreedy leetCode;
    vector<int> timeSeries = { 1, 4 };
    int duration = 2;
    int total_time = leetCode.findPoisonedDuration(timeSeries, 2);
    Logger::WriteMessage(timeSeries);
    Logger::WriteMessage("Duration = " + to_string(duration) + "; Total Time =" + to_string(total_time));

    timeSeries = { 1, 2 };
    duration = 2;
    total_time = leetCode.findPoisonedDuration(timeSeries, 2);
    Logger::WriteMessage(timeSeries);
    Logger::WriteMessage("Duration = " + to_string(duration) + "; Total Time =" + to_string(total_time));
}

void TestLeetCode598(void)
{
    LeetCodeGreedy leetCode;
    int m = 3, n = 3;
    vector<vector<int>> ops = { { 2, 2 },{ 3, 3 } };
    int result = leetCode.maxCount(m, n, ops);

    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));
}

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

void TestLeetCode1665(void)
{
    Logger::WriteMessage("Test Leet Code 1665");
    LeetCodeGreedy leetCode;
    vector<vector<int>> tasks = { {1, 2},{2, 4},{4, 8} };
    int result = leetCode.minimumEffort(tasks);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));

    tasks = { {1, 3},{2, 4},{10, 11},{10, 12},{8, 9} };
    result = leetCode.minimumEffort(tasks);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));

    tasks = { {1, 7},{2, 8},{3, 9},{4, 10},{5, 11},{6, 12} };
    result = leetCode.minimumEffort(tasks);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1642(void)
{
    Logger::WriteMessage("Test Leet Code 1642");
    LeetCodeGreedy leetCode;
    vector<int> heights = { 4, 2, 7, 6, 9, 14, 12 };
    int bricks = 5;
    int ladders = 1;
    int result = leetCode.furthestBuilding(heights, bricks, ladders);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("ladders = " + to_string(ladders) + "; result = " + to_string(result));

    heights = { 4,12,2,7,3,18,20,3,19 };
    bricks = 10;
    ladders = 2;
    result = leetCode.furthestBuilding(heights, bricks, ladders);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("ladders = " + to_string(ladders) + "; result = " + to_string(result));

    heights = { 14,3,19,3 };
    bricks = 17;
    ladders = 0;
    result = leetCode.furthestBuilding(heights, bricks, ladders);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("ladders = " + to_string(ladders) + "; result = " + to_string(result));
}

void TestLeetCode330(void)
{
    Logger::WriteMessage("Test Leet Code 330");
    LeetCodeGreedy leetCode;
    vector<int> nums = { 1, 3 };
    int n = 6;
    int result = leetCode.minPatches(nums, n);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("To reach " + to_string(n) + ", we should patch " + to_string(result) + " numbers");

    nums = { 1, 5, 10 };
    n = 20;
    result = leetCode.minPatches(nums, n);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("To reach " + to_string(n) + ", we should patch " + to_string(result) + " numbers");

    nums = { 1, 2, 2 };
    n = 5;
    result = leetCode.minPatches(nums, n);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("To reach " + to_string(n) + ", we should patch " + to_string(result) + " numbers");
}

void TestLeetCode163(void)
{
    Logger::WriteMessage("Test Leet Code 163");
    LeetCodeGreedy leetCode;
    vector<int> nums = { 0, 1, 3, 50, 75 };
    int lower = 0, upper = 99;
    Logger::WriteMessage(nums);
    vector<string> result = leetCode.findMissingRanges(nums, lower, upper);
    Logger::WriteMessage(result);
}

void TestLeetCode218(void)
{
    Logger::WriteMessage("Test Leet Code 218");
    LeetCodeGreedy leetCode;
    vector<vector<int>> buildings = { {0, 3, 3},{1, 5, 3},{2, 4, 3},{3, 7, 3} };
    Logger::WriteMessage(buildings);
    vector<vector<int>> skyline = leetCode.getSkyline(buildings);
    Logger::WriteMessage(skyline);

    buildings = { { 2, 9, 10 },{ 3, 7, 15 },{ 5, 12, 12 },{ 15, 20, 10 },{ 19, 24, 8 } };
    Logger::WriteMessage(buildings);
    skyline = leetCode.getSkyline(buildings);
    Logger::WriteMessage(skyline);

    buildings = { { 1, 2, 1 },{ 1, 2, 2 },{ 1, 2, 3 } };
    Logger::WriteMessage(buildings);
    skyline = leetCode.getSkyline(buildings);
    Logger::WriteMessage(skyline);
}

void TestLeetCode228(void)
{
    Logger::WriteMessage("Test Leet Code 228");
    LeetCodeGreedy leetCode;
    vector<int> nums = { 0, 1, 2, 4, 5, 7 };
    Logger::WriteMessage(nums);
    vector<string> result = leetCode.summaryRanges(nums);
    Logger::WriteMessage(result);

    nums = { 0, 2, 3, 4, 6, 8, 9 };
    Logger::WriteMessage(nums);
    result = leetCode.summaryRanges(nums);
    Logger::WriteMessage(result);

    nums = { };
    Logger::WriteMessage(nums);
    result = leetCode.summaryRanges(nums);
    Logger::WriteMessage(result);

    nums = { -1 };
    Logger::WriteMessage(nums);
    result = leetCode.summaryRanges(nums);
    Logger::WriteMessage(result);

    nums = { 0 };
    Logger::WriteMessage(nums);
    result = leetCode.summaryRanges(nums);
    Logger::WriteMessage(result);
}


void TestLeetCode252(void)
{
    Logger::WriteMessage("Test Leet Code 252");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = { { 0, 30 },{ 5, 10 },{ 15, 20 } };
    Logger::WriteMessage(intervals);
    bool result = leetCode.canAttendMeetings(intervals);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " attend all the meetings");

    intervals = { { 7, 10 },{ 2, 4 } };
    Logger::WriteMessage(intervals);
    result = leetCode.canAttendMeetings(intervals);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " attend all the meetings");
}

void TestLeetCode253(void)
{
    Logger::WriteMessage("Test Leet Code 253");
    LeetCodeGreedy leetCode;
    vector<vector<int>> meetings = { { 14, 20 },{ 6, 14 },{ 4, 9 } };
    int min_rooms = leetCode.minMeetingRooms(meetings);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("minimum meeting rooms:" + to_string(min_rooms));

    meetings = { { 0, 30 },{5, 10}, {15, 20} };
    min_rooms = leetCode.minMeetingRooms(meetings);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("minimum meeting rooms:" + to_string(min_rooms));
}

void TestLeetCode358(void)
{
    Logger::WriteMessage("Test Leet Code 358");
    LeetCodeGreedy leetCode;
    string s = "aabbcc";
    int k = 3;
    string result = leetCode.rearrangeString(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);

    s = "aaabc";
    k = 3;
    result = leetCode.rearrangeString(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);

    s = "aaadbbcc";
    k = 2;
    result = leetCode.rearrangeString(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);
}

void TestLeetCode435(void)
{
    Logger::WriteMessage("Test Leet Code 435");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = { { 1, 2 },{ 2, 3 },{ 3, 4 },{ 1, 3 } };
    int count = leetCode.eraseOverlapIntervals(intervals);
    Logger::WriteMessage("Remove " + to_string(count) + " intervals");

    intervals = { { 1, 2 },{ 1, 2 },{ 1, 2 } };
    count = leetCode.eraseOverlapIntervals(intervals);
    Logger::WriteMessage("Remove " + to_string(count) + " intervals");

    intervals = { { 1, 2 },{ 2, 3 } };
    count = leetCode.eraseOverlapIntervals(intervals);
    Logger::WriteMessage("Remove " + to_string(count) + " intervals");
}

void TestLeetCode436(void)
{
    Logger::WriteMessage("Test Leet Code 436");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = { { 1,2 } };
    Logger::WriteMessage(intervals);
    vector<int> result = leetCode.findRightInterval(intervals);
    Logger::WriteMessage(result);

    intervals = { { 3, 4 }, { 2, 3 }, { 1, 2 } };
    Logger::WriteMessage(intervals);
    result = leetCode.findRightInterval(intervals);
    Logger::WriteMessage(result);

    intervals = { { 1, 4 },{ 2, 3 },{ 3, 4 } };
    Logger::WriteMessage(intervals);
    result = leetCode.findRightInterval(intervals);
    Logger::WriteMessage(result);
}

void TestLeetCode699(void)
{
    LeetCodeGreedy leetCode;
    vector<vector<int>> positions = { {1, 2},{2, 3},{6, 1} };
    vector<int> result = leetCode.fallingSquares(positions);

    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);

    positions = { {100, 100},{200, 100} };
    result = leetCode.fallingSquares(positions);

    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);

    positions = { {1, 5},{2, 2}, {7, 5} };
    result = leetCode.fallingSquares(positions);

    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);
}


void TestLeetCode502(void)
{
    Logger::WriteMessage("Test Leet Code 502");
    LeetCodeGreedy leetCode;
    int k = 2;
    int W = 0;
    vector<int> Profits = { 1, 3, 2 };
    vector<int> Capital = { 0, 1, 1 };
    int result = leetCode.findMaximizedCapital(k, W, Profits, Capital);
    Logger::WriteMessage("k = " + to_string(k) + "; W = " + to_string(W));
    Logger::WriteMessage(Profits);
    Logger::WriteMessage(Capital);
    Logger::WriteMessage("Result = " + to_string(result));
}

void TestLeetCode630(void)
{
    LeetCodeGreedy leetCode;
    vector<vector<int>> courses = { { 100, 200 },{ 200, 1300 },{ 1000, 1250 },{ 2000, 3200 } };
    int result = leetCode.scheduleCourse(courses);
    Logger::WriteMessage("result = " + to_string(result));

    courses = { { 5, 5 },{ 4, 6 },{ 2, 6 } };
    result = leetCode.scheduleCourse(courses);
    Logger::WriteMessage("result = " + to_string(result));

    courses = { { 9, 14 },{ 7, 12 },{ 1, 11 },{ 4, 7 } };
    result = leetCode.scheduleCourse(courses);
    Logger::WriteMessage("result = " + to_string(result));

    courses = { { 9, 20 },{ 4, 14 },{ 4, 10 },{ 6, 7 },{ 2, 14 },{ 8, 10 },{ 6, 6 },{ 5, 7 } };
    result = leetCode.scheduleCourse(courses);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode554(void)
{
    LeetCodeGreedy leetCode;
    vector<vector<int>> wall = { { 1, 2, 2, 1 },{ 3, 1, 2 },{ 1, 3, 2 },{ 2, 4 },{ 3, 1, 2 },{ 1, 3, 1, 1 } };
    int min_bricks = leetCode.leastBricks(wall);
    Logger::WriteMessage(wall);
    Logger::WriteMessage("Least Bricks = " + to_string(min_bricks));
}

void TestLeetCode621(void)
{
    LeetCodeGreedy leetCode;
    vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
    int n = 2;
    int result = leetCode.leastInterval(tasks, n);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1109(void)
{
    Logger::WriteMessage("Test Leet Code 1109");
    LeetCodeGreedy leetCode;
    vector<vector<int>> bookings = { {1, 2, 10},{2, 3, 20},{2, 5, 25} };
    int n = 5;
    vector<int> result = leetCode.corpFlightBookings(bookings, n);
    Logger::WriteMessage(bookings);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode1094(void)
{
    Logger::WriteMessage("Test Leet Code 1094");
    LeetCodeGreedy leetCode;
    vector<vector<int>> trips = { {2, 1, 5},{3, 3, 7} };
    int capacity = 4;
    bool result = leetCode.carPooling(trips, capacity);
    Logger::WriteMessage(trips);
    Logger::WriteMessage("capacity = " + to_string(capacity) + "; result = " + (string)(result ? "true" : "false"));

    trips = { {2, 1, 5},{3, 3, 7} };
    capacity = 5;
    result = leetCode.carPooling(trips, capacity);
    Logger::WriteMessage(trips);
    Logger::WriteMessage("capacity = " + to_string(capacity) + "; result = " + (string)(result ? "true" : "false"));

    trips = { {2, 1, 5},{3, 5, 7} };
    capacity = 3;
    result = leetCode.carPooling(trips, capacity);
    Logger::WriteMessage(trips);
    Logger::WriteMessage("capacity = " + to_string(capacity) + "; result = " + (string)(result ? "true" : "false"));

    trips = { {3, 2, 7},{3, 7, 9},{8, 3, 9} };
    capacity = 11;
    result = leetCode.carPooling(trips, capacity);
    Logger::WriteMessage(trips);
    Logger::WriteMessage("capacity = " + to_string(capacity) + "; result = " + (string)(result ? "true" : "false"));
}


void TestLeetCode1054(void)
{
    Logger::WriteMessage("Test Leet Code 1054");
    LeetCodeGreedy leetCode;
    vector<int> barcodes = { 1,1,1,1,2,2,3,3 };
    vector<int> result = leetCode.rearrangeBarcodes(barcodes);
    Logger::WriteMessage(barcodes);
    Logger::WriteMessage(result);
}

void TestLeetCode948(void)
{
    Logger::WriteMessage("Test Leet Code 948");
    LeetCodeGreedy leetCode;
    vector<int> tokens = { 100 };
    int P = 50;
    int result = leetCode.bagOfTokensScore(tokens, P);
    Logger::WriteMessage(tokens);
    Logger::WriteMessage("P = " + to_string(P) + "; result = " + to_string(result));

    tokens = { 100,200 };
    P = 150;
    result = leetCode.bagOfTokensScore(tokens, P);
    Logger::WriteMessage(tokens);
    Logger::WriteMessage("P = " + to_string(P) + "; result = " + to_string(result));

    tokens = { 100,200,300,400 };
    P = 200;
    result = leetCode.bagOfTokensScore(tokens, P);
    Logger::WriteMessage(tokens);
    Logger::WriteMessage("P = " + to_string(P) + "; result = " + to_string(result));
}

void TestLeetCode759(void)
{
    Logger::WriteMessage("Test Leet Code 759");
    LeetCodeGreedy leetCode;
    vector<vector<Interval>> schedule = { {{1, 2}, {5, 6}},{{1, 3}},{{4, 10}} };
    vector<Interval> result = leetCode.employeeFreeTime(schedule);
    Logger::WriteMessage(schedule);
    Logger::WriteMessage(result);

    schedule = { {{1, 3},{6, 7}},{{2, 4}},{{2, 5},{9, 12}} };
    result = leetCode.employeeFreeTime(schedule);
    Logger::WriteMessage(schedule);
    Logger::WriteMessage(result);
}


void TestLeetCode646(void)
{
    LeetCodeGreedy leetCode;

    // Test Leet Code #646 
    Logger::WriteMessage("Test Leet Code 646");
    vector<vector<int>> nums = { {1, 2},{2, 3},{3, 4} };
    int result = leetCode.findLongestChain(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode986(void)
{
    Logger::WriteMessage("Test Leet Code 986");
    LeetCodeGreedy leetCode;
    vector<vector<int>> A = { {0, 2},{5, 10},{13, 23},{24, 25} };
    vector<vector<int>> B = { {1, 5},{8, 12},{15, 24},{25, 26} };
    vector<vector<int>> result = leetCode.intervalIntersection(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);
}

void TestLeetCode850(void)
{
    Logger::WriteMessage("Test Leet Code 850");
    LeetCodeGreedy leetCode;
    vector<vector<int>> rectangles = { {0, 0, 2, 2},{1, 0, 2, 3},{1, 0, 3, 1} };
    int result = leetCode.rectangleArea(rectangles);
    Logger::WriteMessage(rectangles);
    Logger::WriteMessage("result = " + to_string(result));

    rectangles = { {0, 0, 1000000000, 1000000000} };
    result = leetCode.rectangleArea(rectangles);
    Logger::WriteMessage(rectangles);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode984(void)
{
    Logger::WriteMessage("Test Leet Code 984");
    LeetCodeGreedy leetCode;
    int A = 1;
    int B = 2;
    string result = leetCode.strWithout3a3b(A, B);
    Logger::WriteMessage("A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + result);

    A = 4;
    B = 1;
    result = leetCode.strWithout3a3b(A, B);
    Logger::WriteMessage("A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + result);
}

void TestLeetCode1024(void)
{
    Logger::WriteMessage("Test Leet Code 1024");
    LeetCodeGreedy leetCode;
    vector<vector<int>> clips = { {0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9} };
    int T = 10;
    int result = leetCode.videoStitching(clips, T);
    Logger::WriteMessage(clips);
    Logger::WriteMessage("T = " + to_string(T) + "; result = " + to_string(result));

    clips = { {0, 1},{1, 2} };
    T = 5;
    result = leetCode.videoStitching(clips, T);
    Logger::WriteMessage(clips);
    Logger::WriteMessage("T = " + to_string(T) + "; result = " + to_string(result));

    clips =
    {
        {0, 1}, {6, 8}, {0, 2}, {5, 6}, {0, 4}, {0, 3}, {6, 7}, {1, 3},
        {4, 7}, {1, 4}, {2, 5}, {2, 6}, {3, 4}, {4, 5}, {5, 7}, {6, 9}
    };
    T = 9;
    result = leetCode.videoStitching(clips, T);
    Logger::WriteMessage(clips);
    Logger::WriteMessage("T = " + to_string(T) + "; result = " + to_string(result));

    clips = { {0, 4}, {2, 8} };
    T = 5;
    result = leetCode.videoStitching(clips, T);
    Logger::WriteMessage(clips);
    Logger::WriteMessage("T = " + to_string(T) + "; result = " + to_string(result));

    clips = { {5, 7}, {1, 8}, {0, 0}, {2, 3}, {4, 5}, {0, 6}, {5, 10}, {7, 10} };
    T = 5;
    result = leetCode.videoStitching(clips, T);
    Logger::WriteMessage(clips);
    Logger::WriteMessage("T = " + to_string(T) + "; result = " + to_string(result));
}

void TestLeetCode1674(void)
{
    Logger::WriteMessage("Test Leet Code 1674");
    LeetCodeGreedy leetCode;
    vector<int> nums = { 1, 2, 4, 3 };
    int limit = 4;
    int result = leetCode.minMoves(nums, limit);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    nums = { 1,2,2,1 };
    limit = 2;
    result = leetCode.minMoves(nums, limit);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    nums = { 1,2,1,2 };
    limit = 2;
    result = leetCode.minMoves(nums, 4);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));
}

void TestLeetCode757(void)
{
    Logger::WriteMessage("Test Leet Code 757");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = { {1, 3},{1, 4},{2, 5},{3, 5} };
    int result = leetCode.intersectionSizeTwo(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage("result = " + to_string(result));

    intervals = { {1, 2},{2, 3},{2, 4},{4, 5} };
    result = leetCode.intersectionSizeTwo(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage("result = " + to_string(result));

    intervals = { { 7, 16 },{ 3, 12 },{ 7, 16 },{ 2, 15 }, { 14, 19 } };
    result = leetCode.intersectionSizeTwo(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage("result = " + to_string(result));


    intervals = { { 33, 44 },{ 42,43 },{ 13,37 },{ 24,33 },{ 24,33 },{ 25,48 },{ 10,47 },{ 18,24 },{ 29,37 },{ 7,34 } };
    result = leetCode.intersectionSizeTwo(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage("result = " + to_string(result));

    intervals =
    {
        { 3, 14 },{ 4,14 },{ 3,9 },{ 5,13 },{ 10,17 },{ 8,20 },{ 7,12 },{ 15,19 },{ 11,17 },{ 6,18 },
        { 16,20 }, { 2,18 },{ 3,5 }, { 15,18 },{ 9,12 },{ 3,14 },{ 10,15 },{ 1,13 },{ 8,10 },{ 0,20 }
    };
    result = leetCode.intersectionSizeTwo(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1792(void)
{
    Logger::WriteMessage("Test Leet Code 1792");
    LeetCodeGreedy leetCode;
    vector<vector<int>> classes = { {1, 2},{3, 5},{2, 2} };
    int extraStudents = 2;
    double result = leetCode.maxAverageRatio(classes, extraStudents);
    Logger::WriteMessage(classes);
    Logger::WriteMessage("extraStudents = " + to_string(extraStudents) + "; result = " + to_string(result));

    classes = { {2, 4},{3, 9},{4, 5},{2, 10} };
    extraStudents = 4;
    result = leetCode.maxAverageRatio(classes, extraStudents);
    Logger::WriteMessage(classes);
    Logger::WriteMessage("extraStudents = " + to_string(extraStudents) + "; result = " + to_string(result));
}

void TestLeetCode1854(void)
{
    Logger::WriteMessage("Test Leet Code 1854");
    LeetCodeGreedy leetCode;
    vector<vector<int>> logs = { {1993, 1999},{2000, 2010} };
    int result = leetCode.maximumPopulation(logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage("result = " + to_string(result));

    logs = { {1950, 1961},{1960, 1971},{1970, 1981} };
    result = leetCode.maximumPopulation(logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage("result = " + to_string(result));


    logs = 
    { 
        {2008, 2026}, {2004, 2008}, {2034, 2035}, {1999, 2050}, {2049, 2050}, 
        {2011, 2035}, {1966, 2033}, {2044, 2049} 
    };
    result = leetCode.maximumPopulation(logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage("result = " + to_string(result));
    
}

void TestLeetCode1893(void)
{
    Logger::WriteMessage("Test Leet Code 1893");
    LeetCodeGreedy leetCode;
    vector<vector<int>> ranges = { {1, 2},{3, 4},{5, 6} };
    int left = 2;
    int right = 5;
    bool result = leetCode.isCovered(ranges, left, right);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("left = " + to_string(left) + "; right = " + to_string(right) + 
        "; result = " + (string)(result ? "true" : "false"));

    ranges = { {1, 10},{10, 20} };
    left = 21;
    right = 21;
    result = leetCode.isCovered(ranges, left, right);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("left = " + to_string(left) + "; right = " + to_string(right) +
        "; result = " + (string)(result ? "true" : "false"));

    ranges = { {1, 2},{4, 10} };
    left = 3;
    right = 5;
    result = leetCode.isCovered(ranges, left, right);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("left = " + to_string(left) + "; right = " + to_string(right) +
        "; result = " + (string)(result ? "true" : "false"));

    ranges = { {1, 2},{4, 10} };
    left = 5;
    right = 6;
    result = leetCode.isCovered(ranges, left, right);
    Logger::WriteMessage(ranges);
    Logger::WriteMessage("left = " + to_string(left) + "; right = " + to_string(right) +
        "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1943(void)
{
    Logger::WriteMessage("Test Leet Code 1943");
    LeetCodeGreedy leetCode;
    vector<vector<int>> segments = { {1, 4, 5},{4, 7, 7},{1, 7, 9} };
    vector<vector<long long>> result = leetCode.splitPainting(segments);
    Logger::WriteMessage(segments);
    Logger::WriteMessage(result);

    segments = { {1, 7, 9},{6, 8, 15},{8, 10, 7}};
    result = leetCode.splitPainting(segments);
    Logger::WriteMessage(segments);
    Logger::WriteMessage(result);

    segments = { {1, 4, 5},{1, 4, 7},{4, 7, 1},{4, 7, 11} };
    result = leetCode.splitPainting(segments);
    Logger::WriteMessage(segments);
    Logger::WriteMessage(result);
}

void TestLeetCode2071(void)
{
    Logger::WriteMessage("Test Leet Code 2071");
    LeetCodeGreedy leetCode;
    vector<int> tasks = { 3, 2, 1 };
    vector<int> workers = { 0, 3, 3 };
    int pills = 1;
    int strength = 1;
    int result = leetCode.maxTaskAssign(tasks, workers, pills, strength);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(workers);
    Logger::WriteMessage("pills = " + to_string(pills) + "; strength = " + to_string(strength) +
        "; result = " + to_string(result));

    tasks = { 5,4 };
    workers = { 0, 0, 0 };
    pills = 1;
    strength = 5;
    result = leetCode.maxTaskAssign(tasks, workers, pills, strength);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(workers);
    Logger::WriteMessage("pills = " + to_string(pills) + "; strength = " + to_string(strength) +
        "; result = " + to_string(result));

    tasks = { 10,15,30 };
    workers = { 0,10,10,10,10 };
    pills = 3;
    strength = 10;
    result = leetCode.maxTaskAssign(tasks, workers, pills, strength);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(workers);
    Logger::WriteMessage("pills = " + to_string(pills) + "; strength = " + to_string(strength) +
        "; result = " + to_string(result));

    tasks = { 5, 9, 8, 5, 9 };
    workers = { 1, 6, 4, 2, 6 };
    pills = 1;
    strength = 5;
    result = leetCode.maxTaskAssign(tasks, workers, pills, strength);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(workers);
    Logger::WriteMessage("pills = " + to_string(pills) + "; strength = " + to_string(strength) +
        "; result = " + to_string(result));
}

void TestLeetCode2021(void)
{
    Logger::WriteMessage("Test Leet Code 2021");
    LeetCodeGreedy leetCode;
    vector<vector<int>> lights = { {-3, 2},{1, 2},{3, 3} };
    int result = leetCode.brightestPosition(lights);
    Logger::WriteMessage(lights);
    Logger::WriteMessage("result = " + to_string(result));

    lights = { {1, 0},{0, 1} };
    result = leetCode.brightestPosition(lights);
    Logger::WriteMessage(lights);
    Logger::WriteMessage("result = " + to_string(result));

    lights = { {1, 2} };
    result = leetCode.brightestPosition(lights);
    Logger::WriteMessage(lights);
    Logger::WriteMessage("result = " + to_string(result));

    lights = { {-10, 2},{0, 3},{5, 1} };
    result = leetCode.brightestPosition(lights);
    Logger::WriteMessage(lights);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1989(void)
{
    Logger::WriteMessage("Test Leet Code 1989");
    LeetCodeGreedy leetCode;
    vector<int> team = { 0, 1, 0, 1, 0 };
    int dist = 3;
    int result = leetCode.catchMaximumAmountofPeople(team, dist);
    Logger::WriteMessage(team);
    Logger::WriteMessage("result = " + to_string(result));

    team = { 1 };
    dist = 1;
    result = leetCode.catchMaximumAmountofPeople(team, dist);
    Logger::WriteMessage(team);
    Logger::WriteMessage("result = " + to_string(result));

    team = { 0 };
    dist = 1;
    result = leetCode.catchMaximumAmountofPeople(team, dist);
    Logger::WriteMessage(team);
    Logger::WriteMessage("result = " + to_string(result));

    team = { 0, 0, 0, 1, 1, 1 };
    dist = 3;
    result = leetCode.catchMaximumAmountofPeople(team, dist);
    Logger::WriteMessage(team);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2015(void)
{
    Logger::WriteMessage("Test Leet Code 2015");
    LeetCodeGreedy leetCode;
    vector<vector<int>> buildings = { {1, 4, 2},{3, 9, 4} };
    vector<vector<int>> result = leetCode.averageHeightOfBuildings(buildings);
    Logger::WriteMessage(buildings);
    Logger::WriteMessage(result);

    buildings = { {1, 3, 2},{2, 5, 3}, {2, 8, 3} };
    result = leetCode.averageHeightOfBuildings(buildings);
    Logger::WriteMessage(buildings);
    Logger::WriteMessage(result);

    buildings = { {1, 2, 1},{5, 6, 1} };
    result = leetCode.averageHeightOfBuildings(buildings);
    Logger::WriteMessage(buildings);
    Logger::WriteMessage(result);
}

void TestLeetCode2158(void)
{
    Logger::WriteMessage("Test Leet Code 2158");
    LeetCodeGreedy leetCode;
    vector<vector<int>> paint = { {1, 4},{4, 7},{5, 8} };
    vector<int> result = leetCode.amountPainted(paint);
    Logger::WriteMessage(paint);
    Logger::WriteMessage(result);

    paint = { {1, 4},{5, 8},{4, 7} };
    result = leetCode.amountPainted(paint);
    Logger::WriteMessage(paint);
    Logger::WriteMessage(result);

    paint = { {1, 5},{2, 4} };
    result = leetCode.amountPainted(paint);
    Logger::WriteMessage(paint);
    Logger::WriteMessage(result);
}

void TestLeetCode2182(void)
{
    Logger::WriteMessage("Test Leet Code 2182");
    LeetCodeGreedy leetCode;
    string s = "cczazcc";
    int repeatLimit = 3;
    string result = leetCode.repeatLimitedString(s, repeatLimit);
    Logger::WriteMessage("s = " + s + "; repeatLimit = " + to_string(repeatLimit));
    Logger::WriteMessage("result = " + result);

    s = "aababab";
    repeatLimit = 2;
    result = leetCode.repeatLimitedString(s, repeatLimit);
    Logger::WriteMessage("s = " + s + "; repeatLimit = " + to_string(repeatLimit));
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode2213(void)
{
    Logger::WriteMessage("Test Leet Code 2213");
    LeetCodeGreedy leetCode;
    string s = "babacc";
    string queryCharacters = "bcb";
    vector<int> queryIndices = { 1, 3, 3 };
    vector<int> result = leetCode.longestRepeating(s, queryCharacters, queryIndices);
    Logger::WriteMessage("s = " + s + "; queryCharacters = " + queryCharacters);
    Logger::WriteMessage(queryIndices);
    Logger::WriteMessage(result);

    s = "abyzz";
    queryCharacters = "aa";
    queryIndices = { 2, 1 };
    result = leetCode.longestRepeating(s, queryCharacters, queryIndices);
    Logger::WriteMessage("s = " + s + "; queryCharacters = " + queryCharacters);
    Logger::WriteMessage(queryIndices);
    Logger::WriteMessage(result);
}

void TestLeetCode2237(void)
{
    Logger::WriteMessage("Test Leet Code 2237");
    LeetCodeGreedy leetCode;
    int n = 5;
    vector<vector<int>> lights = { {0, 1},{2, 1},{3, 2} };
    vector<int> requirement = { 0, 2, 1, 4, 1 };
    int result = leetCode.meetRequirement(n, lights, requirement);
    Logger::WriteMessage(lights);
    Logger::WriteMessage(requirement);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 1;
    lights = { {0, 1} };
    requirement = { 2 };
    result = leetCode.meetRequirement(n, lights, requirement);
    Logger::WriteMessage(lights);
    Logger::WriteMessage(requirement);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}


void TestLeetCode2234(void)
{
    Logger::WriteMessage("Test Leet Code 2234");
    LeetCodeGreedy leetCode;
    vector<int> flowers = { 1, 3, 1, 1 };
    long long newFlowers = 7;
    int target = 6;
    int full = 12;
    int partial = 1;
    long long result = leetCode.maximumBeauty(flowers, newFlowers, target, full, partial);
    Logger::WriteMessage(flowers);
    Logger::WriteMessage("newFlowers = " + to_string(newFlowers) + "; target = " + to_string(target));
    Logger::WriteMessage("full = " + to_string(full) + "; partial = " + to_string(partial));
    Logger::WriteMessage("result = " + to_string(result));

    flowers = { 2,4,5,3 };
    newFlowers = 10;
    target = 5;
    full = 2;
    partial = 6;
    result = leetCode.maximumBeauty(flowers, newFlowers, target, full, partial);
    Logger::WriteMessage(flowers);
    Logger::WriteMessage("newFlowers = " + to_string(newFlowers) + "; target = " + to_string(target));
    Logger::WriteMessage("full = " + to_string(full) + "; partial = " + to_string(partial));
    Logger::WriteMessage("result = " + to_string(result));

    flowers = { 8,2 };
    newFlowers = 24;
    target = 18;
    full = 6;
    partial = 3;
    result = leetCode.maximumBeauty(flowers, newFlowers, target, full, partial);
    Logger::WriteMessage(flowers);
    Logger::WriteMessage("newFlowers = " + to_string(newFlowers) + "; target = " + to_string(target));
    Logger::WriteMessage("full = " + to_string(full) + "; partial = " + to_string(partial));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2274(void)
{
    Logger::WriteMessage("Test Leet Code 2274");
    LeetCodeGreedy leetCode;
    int bottom = 2;
    int top = 9;
    vector<int> special = { 4, 6 };
    int result = leetCode.maxConsecutive(bottom, top, special);
    Logger::WriteMessage(special);
    Logger::WriteMessage("bottom = " + to_string(bottom) + "; top = " + to_string(top));
    Logger::WriteMessage("result = " + to_string(result));

    bottom = 6;
    top = 8;
    special = { 7, 6, 8 };
    result = leetCode.maxConsecutive(bottom, top, special);
    Logger::WriteMessage(special);
    Logger::WriteMessage("bottom = " + to_string(bottom) + "; top = " + to_string(top));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2251(void)
{
    Logger::WriteMessage("Test Leet Code 2251");
    LeetCodeGreedy leetCode;
    vector<vector<int>> flowers = { {1, 6},{3, 7},{9, 12},{4, 13} };
    vector<int> persons = { 2, 3, 7, 11 };
    vector<int> result = leetCode.fullBloomFlowers(flowers, persons);
    Logger::WriteMessage(flowers);
    Logger::WriteMessage(persons);
    Logger::WriteMessage(result);

    flowers = { {1, 10},{3, 3} };
    persons = { 3,3,2 };
    result = leetCode.fullBloomFlowers(flowers, persons);
    Logger::WriteMessage(flowers);
    Logger::WriteMessage(persons);
    Logger::WriteMessage(result);
}

void TestLeetCode2271(void)
{
    Logger::WriteMessage("Test Leet Code 2271");
    LeetCodeGreedy leetCode;
    vector<vector<int>> tiles = { {1, 5},{10, 11},{12, 18}, {20, 25}, {30, 32} };
    int carpetLen = 10;
    int result = leetCode.maximumWhiteTiles(tiles, carpetLen);
    Logger::WriteMessage(tiles);
    Logger::WriteMessage("carpetLen = " + to_string(carpetLen) + "; result = " + to_string(result));

    tiles = { {10, 11},{1, 1} };
    carpetLen = 2;
    result = leetCode.maximumWhiteTiles(tiles, carpetLen);
    Logger::WriteMessage(tiles);
    Logger::WriteMessage("carpetLen = " + to_string(carpetLen) + "; result = " + to_string(result));
}

void TestLeetCode2381(void)
{
    Logger::WriteMessage("Test Leet Code 2381");
    LeetCodeGreedy leetCode;
    string s = "abc";
    vector<vector<int>> shifts = { {0, 1, 0},{1, 2, 1},{0, 2, 1} };
    string result = leetCode.shiftingLetters(s, shifts);
    Logger::WriteMessage(shifts);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "dztz";
    shifts = { {0, 0, 0},{1, 1, 1} };
    result = leetCode.shiftingLetters(s, shifts);
    Logger::WriteMessage(shifts);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode2365(void)
{
    Logger::WriteMessage("Test Leet Code 2365");
    LeetCodeGreedy leetCode;
    vector<int> tasks = { 1, 2, 1, 2, 3, 1 };
    int space = 3;
    long long result = leetCode.taskSchedulerII(tasks, space);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("space = " + to_string(space) + "; result = " + to_string(result));

    tasks = { 5,8,8,5 };
    space = 2;
    result = leetCode.taskSchedulerII(tasks, space);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("space = " + to_string(space) + "; result = " + to_string(result));
}

void TestLeetCode2382(void)
{
    Logger::WriteMessage("Test Leet Code 2382");
    LeetCodeGreedy leetCode;
    vector<int> nums = { 1, 2, 5, 6, 1 };
    vector<int> removeQueries = { 0, 3, 2, 4, 1 };
    vector<long long> result = leetCode.maximumSegmentSum(nums, removeQueries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(removeQueries);
    Logger::WriteMessage(result);

    nums = { 3,2,11,1 };
    removeQueries = { 3,2,1,0 };
    result = leetCode.maximumSegmentSum(nums, removeQueries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(removeQueries);
    Logger::WriteMessage(result);
}

void TestLeetCode2407(void)
{
    Logger::WriteMessage("Test Leet Code 2407");
    LeetCodeGreedy leetCode;
    vector<int> nums = { 4,2,1,4,3,4,5,8,15 };
    int k = 3;
    int result = leetCode.lengthOfLIS(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 7,4,5,1,8,12,4,7 };
    k = 5;
    result = leetCode.lengthOfLIS(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1, 5 };
    k = 1;
    result = leetCode.lengthOfLIS(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2412(void)
{
    Logger::WriteMessage("Test Leet Code 2412");
    LeetCodeGreedy leetCode;
    vector<vector<int>> transactions = { {2, 1},{5, 0},{4, 2} };
    long long result = leetCode.minimumMoney(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage("result = " + to_string(result));

    transactions = { {3, 0},{0, 3} };
    result = leetCode.minimumMoney(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2410(void)
{
    Logger::WriteMessage("Test Leet Code 2410");
    LeetCodeGreedy leetCode;
    vector<int> players = { 4, 7, 9 };
    vector<int> trainers = { 8, 2, 5, 8 };
    int result = leetCode.matchPlayersAndTrainers(players, trainers);
    Logger::WriteMessage(players);
    Logger::WriteMessage(trainers);
    Logger::WriteMessage("result = " + to_string(result));

    players = { 1,1,1 };
    trainers = { 10 };
    result = leetCode.matchPlayersAndTrainers(players, trainers);
    Logger::WriteMessage(players);
    Logger::WriteMessage(trainers);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2406(void)
{
    Logger::WriteMessage("Test Leet Code 2406");
    LeetCodeGreedy leetCode;
    vector<vector<int>> intervals = { {5, 10},{6, 8},{1, 5},{2, 3},{1, 10} };
    int result = leetCode.minGroups(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage("result = " + to_string(result));

    intervals = { {1, 3},{5, 6},{8, 10},{11, 13} };
    result = leetCode.minGroups(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2402(void)
{
    Logger::WriteMessage("Test Leet Code 2402");
    LeetCodeGreedy leetCode;
    int n = 2;
    vector<vector<int>> meetings = { {0, 10},{1, 5},{2, 7},{3, 4} };
    int result = leetCode.mostBooked(n, meetings);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3;
    meetings = { {1, 20},{2, 10},{3, 5},{4, 9},{6, 8} };
    result = leetCode.mostBooked(n, meetings);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2532(void)
{
    Logger::WriteMessage("Test Leet Code 2532");
    LeetCodeGreedy leetCode;
    int n = 1, k = 3;
    vector<vector<int>>time = { {1, 1, 2, 1},{1, 1, 3, 1},{1, 1, 4, 1} };
    int result = leetCode.findCrossingTime(n, k, time);
    Logger::WriteMessage(time);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) +  "; result = " + to_string(result));

    n = 3, k = 2;
    time = { {1, 9, 1, 8},{10, 10, 10, 10} };
    result = leetCode.findCrossingTime(n, k, time);
    Logger::WriteMessage(time);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 10, k = 6;
    time = { {2, 10, 5, 8},{3, 5, 2, 2},{5, 8, 10, 10},{7, 8, 8, 5},{5, 6, 6, 10},{6, 10, 6, 2} };
    result = leetCode.findCrossingTime(n, k, time);
    Logger::WriteMessage(time);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2534(void)
{
    Logger::WriteMessage("Test Leet Code 2534");
    LeetCodeGreedy leetCode;
    vector<int> arrival = { 0, 1, 1, 2, 4 };
    vector<int> state = { 0, 1, 0, 0, 1 };
    vector<int> result = leetCode.timeTaken(arrival, state);
    Logger::WriteMessage(arrival);
    Logger::WriteMessage(state);
    Logger::WriteMessage(result);

    arrival = { 0,0,0 };
    state = { 1,0,1 };
    result = leetCode.timeTaken(arrival, state);
    Logger::WriteMessage(arrival);
    Logger::WriteMessage(state);
    Logger::WriteMessage(result);

    arrival = { 1, 1, 2, 3, 3, 3, 3, 3, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    state = { 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1 };
    result = leetCode.timeTaken(arrival, state);
    Logger::WriteMessage(arrival);
    Logger::WriteMessage(state);
    Logger::WriteMessage(result);
}

void TestLeetCode2542(void)
{
    Logger::WriteMessage("Test Leet Code 2542");
    LeetCodeGreedy leetCode;
    vector<int> nums1 = { 1, 3, 3, 2 }, nums2 = { 2, 1, 3, 4 };
    int k = 3;
    long long result = leetCode.maxScore(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums1 = { 4,2,3,1,1 }, nums2 = { 7,5,10,9,6 };
    k = 1;
    result = leetCode.maxScore(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums1 = { 2,1,14,12 }, nums2 = { 11,7,13,6 };
    k = 3;
    result = leetCode.maxScore(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCodeGreedy(void)
{
    TestLeetCode2542();
    TestLeetCode2534();
    TestLeetCode2532();
    TestLeetCode2406();
    TestLeetCode2410();
    TestLeetCode2412();
    TestLeetCode2407();
    TestLeetCode2382();
    TestLeetCode2365();
    TestLeetCode2381();
    TestLeetCode2271();
    TestLeetCode2251();
    TestLeetCode2274();
    TestLeetCode2234();
    TestLeetCode2237();
    TestLeetCode2213();
    TestLeetCode2182();
    TestLeetCode2158();
    TestLeetCode2015();
    TestLeetCode1989();
    TestLeetCode2021();
    TestLeetCode2071();
    TestLeetCode1943();
    TestLeetCode1893();
    TestLeetCode1854();
    TestLeetCode1792();
    TestLeetCode757();
    TestLeetCode1674();
    TestLeetCode1024();
    TestLeetCode850();
    TestLeetCode986();
    TestLeetCode646();
    TestLeetCode759();
    TestLeetCode948();
    TestLeetCode621();
    TestLeetCode1054();
    TestLeetCode1094();
    TestLeetCode1109();
    TestLeetCode598();
    TestLeetCode554();
    TestLeetCode630();
    TestLeetCode502();
    TestLeetCode699();
    TestLeetCode495();
    TestLeetCode452();
    TestLeetCode435();
    TestLeetCode358();
    TestLeetCode253();
    TestLeetCode252();
    TestLeetCode228();
    TestLeetCode218();
    TestLeetCode163();
    TestLeetCode330();
    TestLeetCode57();
    TestLeetCode56();
    TestLeetCode1642();
    TestLeetCode1665();
    TestLeetCode1589();
    TestLeetCode1520();
    TestLeetCode826();
    TestLeetCode1419();
    TestLeetCode1405();
    TestLeetCode1383();
    TestLeetCode1353();
    TestLeetCode1326();
    TestLeetCode1288();
    TestLeetCode1272();
    TestLeetCode1229();
}
