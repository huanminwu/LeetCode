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

void TestLeetCodeGreedy(void)
{
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
