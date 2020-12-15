#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeSort.h"
#include "TestSort.h"
void TestLeetCode414(void)
{
    Logger::WriteMessage("Test Leet Code 414");
    LeetCodeSort leetCode;
    vector<int> nums;
    int third_max;
    nums = { 3, 2, 1 };
    Logger::WriteMessage(nums);
    third_max = leetCode.thirdMax(nums);
    Logger::WriteMessage("Third max number in the list is " + to_string(third_max));

    nums = { 1, 2 };
    Logger::WriteMessage(nums);
    third_max = leetCode.thirdMax(nums);
    Logger::WriteMessage("Third max number in the list is " + to_string(third_max));

    nums = { 2, 2, 3, 1 };
    Logger::WriteMessage(nums);
    third_max = leetCode.thirdMax(nums);
    Logger::WriteMessage("Third max number in the list is " + to_string(third_max));
}

void TestLeetCode1213(void)
{
    Logger::WriteMessage("Test Leet Code 1213");
    LeetCodeSort leetCode;
    vector<int> arr1 = { 1, 2, 3, 4, 5 };
    vector<int> arr2 = { 1, 2, 5, 7, 9 };
    vector<int> arr3 = { 1, 3, 4, 5, 8 };
    vector<int> result = leetCode.arraysIntersection(arr1, arr2, arr3);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage(arr3);
    Logger::WriteMessage(result);
}

void TestLeetCode373(void)
{
    Logger::WriteMessage("Test Leet Code 373");
    LeetCodeSort leetCode;
    vector<int> nums1 = { 0, 0, 0, 0, 0 };
    vector<int> nums2 = { -3, 22, 35, 56, 76 };
    int k = 22;
    vector<vector<int>> result = leetCode.kSmallestPairs(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    nums1 = { 1,7,11 };
    nums2 = { 2,4,6 };
    k = 3;
    result = leetCode.kSmallestPairs(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    nums1 = { 1, 1, 2 };
    nums2 = { 1, 2, 3 };
    k = 2;
    result = leetCode.kSmallestPairs(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    nums1 = { 1, 2 };
    nums2 = { 3 };
    k = 3;
    result = leetCode.kSmallestPairs(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode683(void)
{
    LeetCodeSort leetCode;
    vector<int> flowers = { 6, 5, 8, 9, 7, 1, 10, 2, 3, 4 };
    int k = 2;
    int result = leetCode.kEmptySlots(flowers, k);
    Logger::WriteMessage(flowers);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    flowers = { 1, 3, 2 };
    k = 1;
    result = leetCode.kEmptySlots(flowers, k);
    Logger::WriteMessage(flowers);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    flowers = { 1, 2, 3 };
    k = 1;
    result = leetCode.kEmptySlots(flowers, k);
    Logger::WriteMessage(flowers);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode774(void)
{
    Logger::WriteMessage("Test Leet Code 774");
    LeetCodeSort leetCode;
    vector<int> stations = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int K = 9;
    double result = leetCode.minmaxGasDist(stations, K);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("result = " + to_string(result));

    stations = { 191487, 226099, 229330, 275915, 347493, 361220, 438140, 517380, 569432, 591085, 637975, 673423 };
    K = 954;
    result = leetCode.minmaxGasDist(stations, K);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode846(void)
{
    Logger::WriteMessage("Test Leet Code 845");
    LeetCodeSort leetCode;
    vector<int> hand = { 1,2,3,6,2,3,4,7,8 };
    int W = 3;
    bool result = leetCode.isNStraightHand(hand, W);
    Logger::WriteMessage(hand);
    Logger::WriteMessage("W = " + to_string(W) + "; result = " + (result ? "true" : "false"));

    hand = { 1,2,3,4,5 };
    W = 4;
    result = leetCode.isNStraightHand(hand, W);
    Logger::WriteMessage(hand);
    Logger::WriteMessage("W = " + to_string(W) + "; result = " + (result ? "true" : "false"));
}

void TestLeetCode857(void)
{
    Logger::WriteMessage("Test Leet Code 857");
    LeetCodeSort leetCode;
    vector<int> quality = { 10, 20, 5 };
    vector<int> wage = { 70, 50, 30 };
    int K = 2;
    double result = leetCode.mincostToHireWorkers(quality, wage, K);
    Logger::WriteMessage(quality);
    Logger::WriteMessage(wage);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    quality = { 3,1,10,10,1 };
    wage = { 4,8,2,2,7 };
    K = 3;
    result = leetCode.mincostToHireWorkers(quality, wage, K);
    Logger::WriteMessage(quality);
    Logger::WriteMessage(wage);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode295(void)
{
    Logger::WriteMessage("Test Leet Code 295");
    vector<string> commands =
    {
        "MedianFinder", "addNum", "findMedian", "addNum", "findMedian", 
        "addNum", "findMedian", "addNum", "findMedian", "addNum", "findMedian", 
        "addNum", "findMedian", "addNum", "findMedian"
    };
    vector<int> data =
    {
        0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0
    };

    MedianFinder* medianFinder = nullptr;

    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MedianFinder")
        {
            medianFinder = new MedianFinder();
            result.push_back("null");
        }
        else if (commands[i] == "addNum")
        {
            medianFinder->addNum(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "findMedian")
        {
            double value = medianFinder->findMedian();
            result.push_back(to_string(value));
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode673(void)
{
    LeetCodeSort leetCode;
    vector<int> nums = { 1,3,5,4,7 };
    int result = leetCode.findNumberOfLIS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,2,2,2 };
    result = leetCode.findNumberOfLIS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 2, 4, 3, 5, 4, 7, 2 };
    result = leetCode.findNumberOfLIS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode300(void)
{
    Logger::WriteMessage("Test Leet Code 300");
    LeetCodeSort leetCode;
    vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
    Logger::WriteMessage(nums);
    int result = leetCode.lengthOfLIS(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode354(void)
{
    Logger::WriteMessage("Test Leet Code 354");
    LeetCodeSort leetCode;
    vector<pair<int, int>> envelopes =
    {
        { 1, 2 },{ 2, 3 }, { 3, 1 }, {4, 2}, {5, 3}
    };
    int result = leetCode.maxEnvelopes(envelopes);
    Logger::WriteMessage(envelopes);
    Logger::WriteMessage("result = " + to_string(result));

    envelopes =
    {
        { 5, 4 }, { 6, 4 }, { 6, 7 }, { 2, 3 }
    };
    result = leetCode.maxEnvelopes(envelopes);
    Logger::WriteMessage(envelopes);
    Logger::WriteMessage("result = " + to_string(result));

    envelopes =
    {
        { 1, 1 }
    };
    result = leetCode.maxEnvelopes(envelopes);
    Logger::WriteMessage(envelopes);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode88(void)
{
    Logger::WriteMessage("Test Leet Code 88");
    LeetCodeSort leetCode;
    vector<int> nums1 = { 1,2,3,4,6,8, 10, 0, 0, 0 };
    vector<int> nums2 = { 5, 6, 7 };
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    leetCode.merge(nums1, 7, nums2, 3);
    Logger::WriteMessage(nums1);
}

void TestLeetCode315(void)
{
    Logger::WriteMessage("Test Leet Code 315");
    LeetCodeSort leetCode;

    vector<int> nums = { 5, 2, 6, 1 };
    vector<int> result = leetCode.countSmaller(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums =
    {
        26, 78, 27, 100, 33, 67, 90, 23, 66, 5, 38, 7, 35, 23, 52, 22, 83,
        51, 98, 69, 81, 32, 78, 28, 94, 13, 2, 97, 3, 76, 99, 51, 9, 21,
        84, 66, 65, 36, 100, 41
    };
    result = leetCode.countSmaller(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode327(void)
{
    Logger::WriteMessage("Test Leet Code 327");
    LeetCodeSort leetCode;

    vector<int> nums = { -1, 1 };
    int lower = 0, upper = 0;
    int count = leetCode.countRangeSum(nums, lower, upper);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("lower = " + to_string(lower) + " upper = " + to_string(upper) + " count = " + to_string(count));

    nums = { -2147483647, 0, -2147483647, 2147483647 };
    lower = -564, upper = 3864;
    count = leetCode.countRangeSum(nums, lower, upper);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("lower = " + to_string(lower) + " upper = " + to_string(upper) + " count = " + to_string(count));


    nums = { -2, 5, -1 };
    lower = -2, upper = 2;
    count = leetCode.countRangeSum(nums, lower, upper);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("lower = " + to_string(lower) + " upper = " + to_string(upper) + " count = " + to_string(count));
}

void TestLeetCode632(void)
{
    LeetCodeSort leetCode;
    vector<vector<int>> nums = { { 4, 10, 15, 24, 26 },{ 0, 9, 12, 20 },{ 5, 18, 22, 30 } };

    vector<int> result = leetCode.smallestRange(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode493(void)
{
    Logger::WriteMessage("Test Leet Code 493");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 3, 2, 3, 1 };
    int result = leetCode.reversePairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("reverse pairs = " + to_string(result));

    nums = { 2, 4, 3, 5, 1 };
    result = leetCode.reversePairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("reverse pairs = " + to_string(result));

    nums = {};
    result = leetCode.reversePairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("reverse pairs = " + to_string(result));
}

void TestLeetCode973(void)
{
    Logger::WriteMessage("Test Leet Code 973");
    LeetCodeSort leetCode;
    vector<vector<int>> points = { {1, 3},{-2, 2} };
    int K = 1;
    vector<vector<int>> result = leetCode.kClosest(points, K);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(points);
    Logger::WriteMessage(result);

    points = { { 3, 3 },{ 5, -1 },{ -2, 4 } };
    K = 2;
    result = leetCode.kClosest(points, K);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(points);
    Logger::WriteMessage(result);
}

void TestLeetCode1331(void)
{
    Logger::WriteMessage("Test Leet Code 1331");
    LeetCodeSort leetCode;
    vector<int> arr = { 40, 10, 20, 30 };
    vector<int> result = leetCode.arrayRankTransform(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 100,100,100 };
    result = leetCode.arrayRankTransform(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 37,12,28,9,100,56,80,5,12 };
    result = leetCode.arrayRankTransform(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);
}

void TestLeetCode1196(void)
{
    Logger::WriteMessage("Test Leet Code 1196");
    LeetCodeSort leetCode;
    vector<int> arr = { 100,200,150,1000 };
    int result = leetCode.maxNumberOfApples(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 900,950,800,1000,700,800 };
    result = leetCode.maxNumberOfApples(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1365(void)
{
    Logger::WriteMessage("Test Leet Code 1365");
    LeetCodeSort leetCode;
    vector<int> nums = { 8,1,2,2,3 };
    vector<int> result = leetCode.smallerNumbersThanCurrent(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 6,5,4,8 };
    result = leetCode.smallerNumbersThanCurrent(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 7,7,7,7 };
    result = leetCode.smallerNumbersThanCurrent(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1366(void)
{
    Logger::WriteMessage("Test Leet Code 1366");
    LeetCodeSort leetCode;
    vector<string> votes = { "ABC", "ACB", "ABC", "ACB", "ACB" };
    string result = leetCode.rankTeams(votes);
    Logger::WriteMessage(votes);
    Logger::WriteMessage(result);

    votes = { "WXYZ","XYZW" };
    result = leetCode.rankTeams(votes);
    Logger::WriteMessage(votes);
    Logger::WriteMessage(result);

    votes = { "ZMNAGUEDSJYLBOPHRQICWFXTVK" };
    result = leetCode.rankTeams(votes);
    Logger::WriteMessage(votes);
    Logger::WriteMessage(result);

    votes = { "BCA","CAB","CBA","ABC","ACB","BAC" };
    result = leetCode.rankTeams(votes);
    Logger::WriteMessage(votes);
    Logger::WriteMessage(result);
  
    votes = { "M", "M", "M", "M" };
    result = leetCode.rankTeams(votes);
    Logger::WriteMessage(votes);
    Logger::WriteMessage(result);
}

void TestLeetCode1387(void)
{
    Logger::WriteMessage("Test Leet Code 1387");
    LeetCodeSort leetCode;
    int lo = 12;
    int hi = 15;
    int k = 2;
    int result = leetCode.getKth(lo, hi, k);
    Logger::WriteMessage("lo = " + to_string(lo) + "; hi = " + to_string(hi));
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    lo = 1;
    hi = 1;
    k = 1;
    result = leetCode.getKth(lo, hi, k);
    Logger::WriteMessage("lo = " + to_string(lo) + "; hi = " + to_string(hi));
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    lo = 7;
    hi = 11;
    k = 4;
    result = leetCode.getKth(lo, hi, k);
    Logger::WriteMessage("lo = " + to_string(lo) + "; hi = " + to_string(hi));
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    lo = 10;
    hi = 20;
    k = 5;
    result = leetCode.getKth(lo, hi, k);
    Logger::WriteMessage("lo = " + to_string(lo) + "; hi = " + to_string(hi));
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    lo = 1;
    hi = 1000;
    k = 777;
    result = leetCode.getKth(lo, hi, k);
    Logger::WriteMessage("lo = " + to_string(lo) + "; hi = " + to_string(hi));
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1385(void)
{
    Logger::WriteMessage("Test Leet Code 1385");
    LeetCodeSort leetCode;
    vector<int> arr1 = { 4, 5, 8 };
    vector<int> arr2 = { 10, 9, 1, 8 };
    int d = 2;
    int result = leetCode.findTheDistanceValue(arr1, arr2, d);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    arr1 = { 1,4,2,3 };
    arr2 = { -4,-3,6,10,20,30 };
    d = 3;
    result = leetCode.findTheDistanceValue(arr1, arr2, d);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    arr1 = { 2,1,100,3 };
    arr2 = { -5,-2,10,-3,7 };
    d = 6;
    result = leetCode.findTheDistanceValue(arr1, arr2, d);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));
}

void TestLeetCode1402(void)
{
    Logger::WriteMessage("Test Leet Code 1402");
    LeetCodeSort leetCode;
    vector<int> satisfaction = { -1, -8, 0, 5, -9 };
    int result = leetCode.maxSatisfaction(satisfaction);
    Logger::WriteMessage(satisfaction);
    Logger::WriteMessage("result = " + to_string(result));

    satisfaction = { 4,3,2 };
    result = leetCode.maxSatisfaction(satisfaction);
    Logger::WriteMessage(satisfaction);
    Logger::WriteMessage("result = " + to_string(result));

    satisfaction = { -1,-4,-5 };
    result = leetCode.maxSatisfaction(satisfaction);
    Logger::WriteMessage(satisfaction);
    Logger::WriteMessage("result = " + to_string(result));

    satisfaction = { -2,5,-1,0,3,-3 };
    result = leetCode.maxSatisfaction(satisfaction);
    Logger::WriteMessage(satisfaction);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1403(void)
{
    Logger::WriteMessage("Test Leet Code 1403");
    LeetCodeSort leetCode;
    vector<int> nums = { 4, 3, 10, 9, 8 };
    vector<int> result = leetCode.minSubsequence(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 4,4,7,6,7 };
    result = leetCode.minSubsequence(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 6 };
    result = leetCode.minSubsequence(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1439(void)
{
    Logger::WriteMessage("Test Leet Code 1439");
    LeetCodeSort leetCode;
    vector<vector<int>> mat =
    {
        {1, 3, 11},
        {2, 4, 6}
    };
    int k = 5;
    int result = leetCode.kthSmallest(mat, k);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    mat =
    {
        {1, 3, 11},
        {2, 4, 6}
    };
    k = 9;
    result = leetCode.kthSmallest(mat, k);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    mat =
    {
        {1, 10, 10},
        {1, 4, 5},
        {2, 3, 6}
    };
    k = 7;
    result = leetCode.kthSmallest(mat, k);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    mat =
    {
        {1, 1, 10},
        {2, 2, 9}
    };
    k = 7;
    result = leetCode.kthSmallest(mat, k);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}


void TestLeetCode674(void)
{
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 3, 5, 4, 7 };
    int result = leetCode.findLengthOfLCIS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, 2, 2, 2 };
    result = leetCode.findLengthOfLCIS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1499(void)
{
    LeetCodeSort leetCode;
    vector <vector<int>> points = { {1, 3},{2, 0},{5, 10},{6, -10} };
    int k = 1;
    int result = leetCode.findMaxValueOfEquation(points, k);
    Logger::WriteMessage(points);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    points = { {0, 0},{3, 0},{9, 2} };
    k = 3;
    result = leetCode.findMaxValueOfEquation(points, k);
    Logger::WriteMessage(points);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1505(void)
{
    LeetCodeSort leetCode;
    string num = "4321";
    int k = 4;
    string result = leetCode.minInteger(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; result = " + result);
    
    num = "100";
    k = 1;
    result = leetCode.minInteger(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; result = " + result);
    num = "100";

    num = "36789";
    k = 1000;
    result = leetCode.minInteger(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; result = " + result);

    num = "22";
    k = 22;
    result = leetCode.minInteger(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; result = " + result);

    num = "9438957234785635408";
    k = 23;
    result = leetCode.minInteger(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; result = " + result);

    num = "294984148179";
    k = 11;
    result = leetCode.minInteger(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; result = " + result);
}

void TestLeetCode1509(void)
{
    LeetCodeSort leetCode;
    vector<int> nums = { 5,3,2,4 };
    int result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,5,0,10,14 };
    result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 6,6,0,1,1,4,6 };
    result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,5,6,14,15 };
    result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode456(void)
{
    Logger::WriteMessage("Test Leet Code 456");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    Logger::WriteMessage(nums);
    bool result = leetCode.find132pattern(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 3, 1, 4, 2 };
    Logger::WriteMessage(nums);
    result = leetCode.find132pattern(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { -1, 3, 2, 0 };
    Logger::WriteMessage(nums);
    result = leetCode.find132pattern(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1535(void)
{
    Logger::WriteMessage("Test Leet Code 1535");
    LeetCodeSort leetCode;
    vector<int> arr = { 2,1,3,5,4,6,7 };
    int k = 2;
    int result = leetCode.getWinner(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 3,2,1 };
    k = 10;
    result = leetCode.getWinner(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 1,9,8,2,3,7,6,4,5 };
    k = 7;
    result = leetCode.getWinner(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 1,11,22,33,44,55,66,77,88,99 };
    k = 1000000000;
    result = leetCode.getWinner(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1536(void)
{
    Logger::WriteMessage("Test Leet Code 1536");
    LeetCodeSort leetCode;
    vector<vector<int>> grid = { {0, 0, 1},{1, 1, 0},{1, 0, 0} };
    int result = leetCode.minSwaps(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 1, 1, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 1, 1, 0} };
    result = leetCode.minSwaps(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 0, 0},{1, 1, 0},{1, 1, 1} };
    result = leetCode.minSwaps(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1585(void)
{
    Logger::WriteMessage("Test Leet Code 1585");
    LeetCodeSort leetCode;
    string s = "84532";
    string t = "34852";
    bool result = leetCode.isTransformable(s, t);
    Logger::WriteMessage("s = " + s + "; t = "+ t +"; result = " + (string)(result ? "true" : "false"));

    s = "34521";
    t = "23415";
    result = leetCode.isTransformable(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + (string)(result ? "true" : "false"));

    s = "12345";
    t = "12435";
    result = leetCode.isTransformable(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + (string)(result ? "true" : "false"));

    s = "1";
    t = "2";
    result = leetCode.isTransformable(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1608(void)
{
    Logger::WriteMessage("Test Leet Code 1608");
    LeetCodeSort leetCode;
    vector<int> nums = { 3, 5 };
    int result = leetCode.specialArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0,0 };
    result = leetCode.specialArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0,4,3,0,4 };
    result = leetCode.specialArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,6,7,7,0 };
    result = leetCode.specialArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1606(void)
{
    Logger::WriteMessage("Test Leet Code 1606");
    LeetCodeSort leetCode;
    int k = 3;
    vector<int> arrival = { 1, 2, 3, 4, 5 };
    vector<int> load = { 5, 2, 3, 3, 3 };
    vector<int> result = leetCode.busiestServers(k, arrival, load);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(arrival);
    Logger::WriteMessage(load);
    Logger::WriteMessage(result);

    k = 3;
    arrival = { 1,2,3,4 };
    load = { 1,2,1,2 };
    result = leetCode.busiestServers(k, arrival, load);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(arrival);
    Logger::WriteMessage(load);
    Logger::WriteMessage(result);

    k = 3;
    arrival = { 1,2,3 };
    load = { 10,12,11 };
    result = leetCode.busiestServers(k, arrival, load);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(arrival);
    Logger::WriteMessage(load);
    Logger::WriteMessage(result);

    k = 3;
    arrival = { 1,2,3,4,8,9,10 };
    load = { 5,2,10,3,1,2,2 };
    result = leetCode.busiestServers(k, arrival, load);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(arrival);
    Logger::WriteMessage(load);
    Logger::WriteMessage(result);

    k = 1;
    arrival = { 1 };
    load = { 1 };
    result = leetCode.busiestServers(k, arrival, load);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(arrival);
    Logger::WriteMessage(load);
    Logger::WriteMessage(result);
}

void TestLeetCode1564(void)
{
    Logger::WriteMessage("Test Leet Code 1564");
    LeetCodeSort leetCode;
    vector<int> boxes = { 4, 3, 4, 1 };
    vector<int> warehouse = { 5, 3, 3, 4, 1 };
    int result = leetCode.maxBoxesInWarehouse(boxes, warehouse);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage(warehouse);
    Logger::WriteMessage("result = " + to_string(result));

    boxes = { 1,2,2,3,4 };
    warehouse = { 3,4,1,2 };
    result = leetCode.maxBoxesInWarehouse(boxes, warehouse);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage(warehouse);
    Logger::WriteMessage("result = " + to_string(result));

    boxes = { 1,2,3 };
    warehouse = { 1,2,3,4 };
    result = leetCode.maxBoxesInWarehouse(boxes, warehouse);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage(warehouse);
    Logger::WriteMessage("result = " + to_string(result));

    boxes = { 4,5,6 };
    warehouse = { 3,3,3,3,3 };
    result = leetCode.maxBoxesInWarehouse(boxes, warehouse);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage(warehouse);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1580(void)
{
    Logger::WriteMessage("Test Leet Code 1580");
    LeetCodeSort leetCode;
    vector<int> boxes = { 1,2,2,3,4 };
    vector<int> warehouse = { 3,4,1,2 };
    int result = leetCode.maxBoxesInWarehouseII(boxes, warehouse);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage(warehouse);
    Logger::WriteMessage("result = " + to_string(result));

    boxes = { 3,5,5,2 };
    warehouse = { 2,1,3,4,5 };
    result = leetCode.maxBoxesInWarehouseII(boxes, warehouse);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage(warehouse);
    Logger::WriteMessage("result = " + to_string(result));

    boxes = { 1,2,3 };
    warehouse = { 1,2,3,4 };
    result = leetCode.maxBoxesInWarehouseII(boxes, warehouse);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage(warehouse);
    Logger::WriteMessage("result = " + to_string(result));

    boxes = { 4,5,6 };
    warehouse = { 3,3,3,3,3 };
    result = leetCode.maxBoxesInWarehouseII(boxes, warehouse);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage(warehouse);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1626(void)
{
    Logger::WriteMessage("Test Leet Code 1626");
    LeetCodeSort leetCode;
    vector<int> scores = { 1, 3, 5, 10, 15 };
    vector<int> ages = { 1, 2, 3, 4, 5 };
    int result = leetCode.bestTeamScore(scores, ages);
    Logger::WriteMessage(scores);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    scores = { 4,5,6,5 };
    ages = { 2,1,2,1 };
    result = leetCode.bestTeamScore(scores, ages);
    Logger::WriteMessage(scores);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    scores = { 1,2,3,5 };
    ages = { 8,9,10,1 };
    result = leetCode.bestTeamScore(scores, ages);
    Logger::WriteMessage(scores);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1632(void)
{
    Logger::WriteMessage("Test Leet Code 1632");
    LeetCodeSort leetCode;
    vector<vector<int>> matrix = { {1, 2},{3, 4} };
    vector<vector<int>> result = leetCode.matrixRankTransform(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);

    matrix = { {7, 7},{7, 7} };
    result = leetCode.matrixRankTransform(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);

    matrix =
    {
        {20, -21, 14},
        {-19, 4, 19},
        {22, -47, 24},
        {-19, 4, 19}
    };
    result = leetCode.matrixRankTransform(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);

    matrix =
    {
        {7,3,6},{1,4,5}, {9, 8, 2} 
    };
    result = leetCode.matrixRankTransform(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);

    matrix =
    {
        {1,2,2},{-1,1,3}, {2, 2, 3}
    };
    result = leetCode.matrixRankTransform(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);

    matrix =
    { 
        {-44,31,-46,13,-48,-5},{-44,-5,14,-47,48,7},{24,39,-6,-27,20,-1}
    };
    result = leetCode.matrixRankTransform(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);
}

void TestLeetCode1649(void)
{
    Logger::WriteMessage("Test Leet Code 1649");
    LeetCodeSort leetCode;
    vector<int> instructions = { 1,5,6,2 };
    int result = leetCode.createSortedArray(instructions);
    Logger::WriteMessage(instructions);
    Logger::WriteMessage("result = " + to_string(result));

    instructions = { 1,2,3,6,5,4 };
    result = leetCode.createSortedArray(instructions);
    Logger::WriteMessage(instructions);
    Logger::WriteMessage("result = " + to_string(result));

    instructions = { 1,3,3,3,2,4,2,1,2 };
    result = leetCode.createSortedArray(instructions);
    Logger::WriteMessage(instructions);
    Logger::WriteMessage("result = " + to_string(result));


    instructions = { 4, 14, 10 };
    result = leetCode.createSortedArrayI(instructions);
    Logger::WriteMessage(instructions);
    Logger::WriteMessage("result = " + to_string(result));

    instructions = { 4, 14, 81615 };
    result = leetCode.createSortedArrayI(instructions);
    Logger::WriteMessage(instructions);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1675(void)
{
    Logger::WriteMessage("Test Leet Code 1675");
    LeetCodeSort leetCode;
    vector<int> nums = { 1,2,3,4 };
    int result = leetCode.minimumDeviation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,1,5,20,3 };
    result = leetCode.minimumDeviation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, 10, 8 };
    result = leetCode.minimumDeviation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 399, 908, 648, 357, 693, 502, 331, 649, 596, 698 };
    result = leetCode.minimumDeviation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1686(void)
{
    Logger::WriteMessage("Test Leet Code 1686");
    LeetCodeSort leetCode;
    vector<int> aliceValues = { 1, 3 };
    vector<int> bobValues = { 2, 1 };
    int result = leetCode.stoneGameVI(aliceValues, bobValues);
    Logger::WriteMessage(aliceValues);
    Logger::WriteMessage(bobValues);
    Logger::WriteMessage("result = " + to_string(result));

    aliceValues = { 1,2 };
    bobValues = { 3, 1 };
    result = leetCode.stoneGameVI(aliceValues, bobValues);
    Logger::WriteMessage(aliceValues);
    Logger::WriteMessage(bobValues);
    Logger::WriteMessage("result = " + to_string(result));

    aliceValues = { 2,4,3 };
    bobValues = { 1,6,7 };
    result = leetCode.stoneGameVI(aliceValues, bobValues);
    Logger::WriteMessage(aliceValues);
    Logger::WriteMessage(bobValues);
    Logger::WriteMessage("result = " + to_string(result));

    aliceValues = { 60, 7, 38, 66, 73, 61, 62, 10, 49, 12 };
    bobValues = { 87, 62, 8, 43, 79, 93, 7, 15, 98, 39 };
    result = leetCode.stoneGameVI(aliceValues, bobValues);
    Logger::WriteMessage(aliceValues);
    Logger::WriteMessage(bobValues);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCodeSort(void)
{
    TestLeetCode1686();
    TestLeetCode1675();
    TestLeetCode1649();
    TestLeetCode1632();
    TestLeetCode1626();
    TestLeetCode1580();
    TestLeetCode1564();
    TestLeetCode1606();
    TestLeetCode1608();
    TestLeetCode1585();
    TestLeetCode1536();
    TestLeetCode1535();
    TestLeetCode456();
    TestLeetCode1509();
    TestLeetCode1505();
    TestLeetCode1499();
    TestLeetCode1439();
    TestLeetCode1403();
    TestLeetCode1402();
    TestLeetCode1385();
    TestLeetCode1387();
    TestLeetCode1366();
    TestLeetCode1365();
    TestLeetCode1196();
    TestLeetCode1331();
    TestLeetCode973();
    TestLeetCode493();
    TestLeetCode632();
    TestLeetCode327();
    TestLeetCode88();
    TestLeetCode300();
    TestLeetCode354();
    TestLeetCode673();
    TestLeetCode674();
    TestLeetCode295();
    TestLeetCode373();
    TestLeetCode683(); 
    TestLeetCode774();
    TestLeetCode846();
    TestLeetCode857();
    TestLeetCode1213();
}