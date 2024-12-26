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

void TestLeetCode334(void)
{
    Logger::WriteMessage("Test Leet Code 334");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    bool result = leetCode.increasingTriplet(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("It" + (string)(result ? " is " : "  is not ") + "increasing triple");

    nums = { 5, 4, 3, 2, 1 };
    result = leetCode.increasingTriplet(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("It" + (string)(result ? " is " : "  is not ") + "increasing triple");
}

void TestLeetCode1705(void)
{
    Logger::WriteMessage("Test Leet Code 1705");
    LeetCodeSort leetCode;
    vector<int> apples = { 1, 2, 3, 5, 2 };
    vector<int> days = { 3, 2, 1, 4, 2 };
    int result = leetCode.eatenApples(apples, days);
    Logger::WriteMessage(apples);
    Logger::WriteMessage(days);
    Logger::WriteMessage("result = " + to_string(result));

    apples = { 3,0,0,0,0,2 };
    days = { 3,0,0,0,0,2 };
    result = leetCode.eatenApples(apples, days);
    Logger::WriteMessage(apples);
    Logger::WriteMessage(days);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1710(void)
{
    Logger::WriteMessage("Test Leet Code 1710");
    LeetCodeSort leetCode;
    vector<vector<int>> boxTypes = { {1, 3},{2, 2},{3, 1} };
    int truckSize = 4;
    int result = leetCode.maximumUnits(boxTypes, truckSize);
    Logger::WriteMessage(boxTypes);
    Logger::WriteMessage("truckSize = " + to_string(truckSize) + "; result = " + to_string(result));

    boxTypes = { {5, 10},{2, 5},{4, 7}, {3, 9} };
    truckSize = 10;
    result = leetCode.maximumUnits(boxTypes, truckSize);
    Logger::WriteMessage(boxTypes);
    Logger::WriteMessage("truckSize = " + to_string(truckSize) + "; result = " + to_string(result));
}

void TestLeetCode1752(void)
{
    Logger::WriteMessage("Test Leet Code 1752");
    LeetCodeSort leetCode;
    vector<int> nums = { 3, 4, 5, 1, 2 };
    bool result = leetCode.check(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 2,1,3,4 };
    result = leetCode.check(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,2,3 };
    result = leetCode.check(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,1 };
    result = leetCode.check(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 2,1 };
    result = leetCode.check(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}


void TestLeetCode1775(void)
{
    Logger::WriteMessage("Test Leet Code 1775");
    LeetCodeSort leetCode;
    vector<int> nums1 = { 1, 2, 3, 4, 5, 6 };
    vector<int> nums2 = { 1, 1, 2, 2, 2, 2 };
    int result = leetCode.minOperations(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1,1,1,1,1,1,1 };
    nums2 = { 6 };
    result = leetCode.minOperations(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 6,6 };
    nums2 = { 1 };
    result = leetCode.minOperations(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1801(void)
{
    Logger::WriteMessage("Test Leet Code 1801");
    LeetCodeSort leetCode;
    vector<vector<int>> orders = { {10, 5, 0},{15, 2, 1},{25, 1, 1},{30, 4, 0} };
    int result = leetCode.getNumberOfBacklogOrders(orders);
    Logger::WriteMessage(orders);
    Logger::WriteMessage("result = " + to_string(result));

    orders = { {7, 1000000000, 1},{15, 3, 0},{5, 999999995, 0},{5, 1, 1} };
    result = leetCode.getNumberOfBacklogOrders(orders);
    Logger::WriteMessage(orders);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1833(void)
{
    Logger::WriteMessage("Test Leet Code 1833");
    LeetCodeSort leetCode;
    vector<int> costs = { 1, 3, 2, 4, 1 };
    int coins = 7;
    int result = leetCode.maxIceCream(costs, coins);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("coins = " + to_string(coins) + "; result = " + to_string(result));

    costs = { 10,6,8,7,7,8 };
    coins = 5;
    result = leetCode.maxIceCream(costs, coins);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("coins = " + to_string(coins) + "; result = " + to_string(result));

    costs = { 1,6,3,1,2,5 };
    coins = 20;
    result = leetCode.maxIceCream(costs, coins);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("coins = " + to_string(coins) + "; result = " + to_string(result));
}

void TestLeetCode1834(void)
{
    Logger::WriteMessage("Test Leet Code 1834");
    LeetCodeSort leetCode;
    vector<vector<int>> tasks = { {1, 2},{2, 4},{3, 2},{4, 1} };
    vector<int> result = leetCode.getOrder(tasks);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(result);

    tasks = { {7, 10},{7, 12},{7, 5},{7, 4},{7, 2} };
    result = leetCode.getOrder(tasks);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(result);

    tasks = 
    { 
       {19, 13}, {16, 9}, {21, 10}, {32, 25}, {37, 4}, {49, 24}, {2, 15}, 
        {38, 41}, {37, 34}, {33, 6}, {45, 4}, {18, 18}, {46, 39}, {12, 24}
    };
    result = leetCode.getOrder(tasks);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(result);
}

void TestLeetCode1846(void)
{
    Logger::WriteMessage("Test Leet Code 1846");
    LeetCodeSort leetCode;
    vector<int>arr = { 2, 2, 1, 2, 1 };
    int result = leetCode.maximumElementAfterDecrementingAndRearranging(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 100,1,1000 };
    result = leetCode.maximumElementAfterDecrementingAndRearranging(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,2,3,4,5 };
    result = leetCode.maximumElementAfterDecrementingAndRearranging(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1847(void)
{
    Logger::WriteMessage("Test Leet Code 1847");
    LeetCodeSort leetCode;
    vector<vector<int>> rooms = { {2, 2},{1, 2}, {3, 2} };
    vector<vector<int>> queries = { {3, 1},{3, 3}, {5, 2} };
    vector<int> result = leetCode.closestRoom(rooms, queries);
    Logger::WriteMessage(rooms);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    rooms = { {1, 4},{2, 3},{3, 5},{4, 1}, {5, 2} };
    queries = { {2, 3},{2, 4},{2, 5} };
    result = leetCode.closestRoom(rooms, queries);
    Logger::WriteMessage(rooms);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1851(void)
{
    Logger::WriteMessage("Test Leet Code 1851");
    LeetCodeSort leetCode;
    vector<vector<int>> intervals = { {1, 4},{2, 4},{3, 6},{4, 4} };
    vector<int>  queries = { 2, 3, 4, 5 };
    vector<int> result = leetCode.minInterval(intervals, queries);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    intervals = { {2, 3},{2, 5},{1, 8},{20, 25} };
    queries = { 2,19,5,22 };
    result = leetCode.minInterval(intervals, queries);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1889(void)
{
    Logger::WriteMessage("Test Leet Code 1889");
    LeetCodeSort leetCode;
    vector<int> packages = { 2, 3, 5 };
    vector<vector<int>> boxes = { {4, 8},{2, 8} };
    int result = leetCode.minWastedSpace(packages, boxes);
    Logger::WriteMessage(packages);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("result = " + to_string(result));

    packages = { 2, 3, 5 };
    boxes = { {1, 4},{2, 3},{3, 4} };
    result = leetCode.minWastedSpace(packages, boxes);
    Logger::WriteMessage(packages);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("result = " + to_string(result));

    packages = { 3,5,8,10,11,12 };
    boxes = { {12},{11, 9},{10, 5, 14} };
    result = leetCode.minWastedSpace(packages, boxes);
    Logger::WriteMessage(packages);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1909(void)
{
    Logger::WriteMessage("Test Leet Code 1909");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 2, 10, 5, 7 };
    bool result = leetCode.canBeIncreasing(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" :"false"));

    nums = { 2,3,1,2 };
    result = leetCode.canBeIncreasing(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,1 };
    result = leetCode.canBeIncreasing(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,2,3 };
    result = leetCode.canBeIncreasing(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1913(void)
{
    Logger::WriteMessage("Test Leet Code 1913");
    LeetCodeSort leetCode;
    vector<int> nums = { 5, 6, 2, 7, 4 };
    int result = leetCode.maxProductDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,2,5,9,7,4,8 };
    result = leetCode.maxProductDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1877(void)
{
    Logger::WriteMessage("Test Leet Code 1877");
    LeetCodeSort leetCode;
    vector<int> nums = { 3,5,2,3 };
    int result = leetCode.minPairSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,5,4,2,4,6 };
    result = leetCode.minPairSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1881(void)
{
    Logger::WriteMessage("Test Leet Code 1881");
    LeetCodeSort leetCode;
    string n = "99";
    int x = 9;
    string result = leetCode.maxValue(n, x);
    Logger::WriteMessage("n = " + n + "; x = " + to_string(x) + "; result = " + result);
    
    n = "-13";
    x = 2;
    result = leetCode.maxValue(n, x);
    Logger::WriteMessage("n = " + n + "; x = " + to_string(x) + "; result = " + result);

    n = "28824579515";
    x = 8;
    result = leetCode.maxValue(n, x);
    Logger::WriteMessage("n = " + n + "; x = " + to_string(x) + "; result = " + result);
}

void TestLeetCode1887(void)
{
    Logger::WriteMessage("Test Leet Code 1887");
    LeetCodeSort leetCode;
    vector<int> nums = { 5, 1, 3 };
    int result = leetCode.reductionOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("; result = " + to_string(result));

    nums = { 1,1,1 };
    result = leetCode.reductionOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("; result = " + to_string(result));

    nums = { 1,1,2,2,3 };
    result = leetCode.reductionOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("; result = " + to_string(result));
}

void TestLeetCode1882(void)
{
    Logger::WriteMessage("Test Leet Code 1882");
    LeetCodeSort leetCode;
    vector<int> servers = { 3,3,2 };
    vector<int> tasks = { 1, 2, 3, 2, 1, 2 };
    vector<int> result = leetCode.assignTasks(servers, tasks);
    Logger::WriteMessage(servers);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(result);

    servers = { 5,1,4,3,2 };
    tasks = { 2,1,2,4,5,2,1 };
    result = leetCode.assignTasks(servers, tasks);
    Logger::WriteMessage(servers);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage(result);
}

void TestLeetCode1964(void)
{
    Logger::WriteMessage("Test Leet Code 1964");
    LeetCodeSort leetCode;
    vector<int> obstacles = { 1, 2, 3, 2 };
    vector<int> result = leetCode.longestObstacleCourseAtEachPosition(obstacles);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage(result);

    obstacles = { 2,2,1 };
    result = leetCode.longestObstacleCourseAtEachPosition(obstacles);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage(result);

    obstacles = { 3,1,5,6,4,2 };
    result = leetCode.longestObstacleCourseAtEachPosition(obstacles);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage(result);
}

void TestLeetCode2037(void)
{
    Logger::WriteMessage("Test Leet Code 2037");
    LeetCodeSort leetCode;
    vector<int> seats = { 3, 1, 5 };
    vector<int> students = { 2, 7, 4 };
    int result = leetCode.minMovesToSeat(seats, students);
    Logger::WriteMessage(seats);
    Logger::WriteMessage(students);
    Logger::WriteMessage("result = " + to_string(result));

    seats = { 4,1,5,9 };
    students = { 1,3,2,6 };
    result = leetCode.minMovesToSeat(seats, students);
    Logger::WriteMessage(seats);
    Logger::WriteMessage(students);
    Logger::WriteMessage("result = " + to_string(result));

    seats = { 2,2,6,6 };
    students = { 1,3,2,6 };
    result = leetCode.minMovesToSeat(seats, students);
    Logger::WriteMessage(seats);
    Logger::WriteMessage(students);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1984(void)
{
    Logger::WriteMessage("Test Leet Code 1984");
    LeetCodeSort leetCode;
    vector<int> nums = { 90 };
    int k = 1;
    int result = leetCode.minimumDifference(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 9,4,1,7 };
    k = 2;
    result = leetCode.minimumDifference(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1921(void)
{
    Logger::WriteMessage("Test Leet Code 1921");
    LeetCodeSort leetCode;
    vector<int> dist = { 1, 3, 4 };
    vector<int> speed = { 1, 1, 1 };
    int result = leetCode.eliminateMaximum(dist, speed);
    Logger::WriteMessage(dist);
    Logger::WriteMessage(speed);
    Logger::WriteMessage("result = " + to_string(result));

    dist = { 1,1,2,3 };
    speed = { 1,1,1,1 };
    result = leetCode.eliminateMaximum(dist, speed);
    Logger::WriteMessage(dist);
    Logger::WriteMessage(speed);
    Logger::WriteMessage("result = " + to_string(result));

    dist = { 3,2,4 };
    speed = { 5,3,2 };
    result = leetCode.eliminateMaximum(dist, speed);
    Logger::WriteMessage(dist);
    Logger::WriteMessage(speed);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1985(void)
{
    Logger::WriteMessage("Test Leet Code 1985");
    LeetCodeSort leetCode;
    vector<string> nums = { "3", "6", "7", "10" };
    int k = 4;
    string result = leetCode.kthLargestNumber(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);

    nums = { "2","21","12","1" };
    k = 3;
    result = leetCode.kthLargestNumber(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);

    nums = { "0","0" };
    k = 2;
    result = leetCode.kthLargestNumber(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);
}

void TestLeetCode1942(void)
{
    Logger::WriteMessage("Test Leet Code 1942");
    LeetCodeSort leetCode;
    vector<vector<int>> times = { {1, 4},{2, 3},{4, 6} };
    int targetFriend = 1;
    int result = leetCode.smallestChair(times, targetFriend);
    Logger::WriteMessage(times);
    Logger::WriteMessage("targetFriend = " + to_string(targetFriend) + "; result = " + to_string(result));

    times = { {3, 10},{1, 5},{2, 6} };
    targetFriend = 0;
    result = leetCode.smallestChair(times, targetFriend);
    Logger::WriteMessage(times);
    Logger::WriteMessage("targetFriend = " + to_string(targetFriend) + "; result = " + to_string(result));

    times = { {1, 4}, { 2, 3 }, { 4, 6 }, { 3, 4 }, { 5, 6 } };
    targetFriend = 2;
    result = leetCode.smallestChair(times, targetFriend);
    Logger::WriteMessage(times);
    Logger::WriteMessage("targetFriend = " + to_string(targetFriend) + "; result = " + to_string(result));
}

void TestLeetCode1962(void)
{
    Logger::WriteMessage("Test Leet Code 1962");
    LeetCodeSort leetCode;
    vector<int> piles = { 5, 4, 9 };
    int k = 2;
    int result = leetCode.minStoneSum(piles, k);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    piles = { 4,3,6,7 };
    k = 3;
    result = leetCode.minStoneSum(piles, k);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1996(void)
{
    Logger::WriteMessage("Test Leet Code 1996");
    LeetCodeSort leetCode;
    vector<vector<int>> properties = { {5, 5},{6, 3},{3, 6} };
    int result = leetCode.numberOfWeakCharacters(properties);
    Logger::WriteMessage(properties);
    Logger::WriteMessage("result = " + to_string(result));

    properties = { {2, 2},{3, 3} };
    result = leetCode.numberOfWeakCharacters(properties);
    Logger::WriteMessage(properties);
    Logger::WriteMessage("result = " + to_string(result));

    properties = { {1, 5},{10, 4},{4, 3} };
    result = leetCode.numberOfWeakCharacters(properties);
    Logger::WriteMessage(properties);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1966(void)
{
    Logger::WriteMessage("Test Leet Code 1966");
    LeetCodeSort leetCode;
    vector<int> nums = { 7 };
    int result = leetCode.binarySearchableNumbers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -1, 5, 2 };
    result = leetCode.binarySearchableNumbers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1968(void)
{
    Logger::WriteMessage("Test Leet Code 1968");
    LeetCodeSort leetCode;
    vector<int> nums = { 1,2,3,4,5 };
    vector<int> result = leetCode.rearrangeArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 6,2,0,9,7 };
    result = leetCode.rearrangeArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2098(void)
{
    Logger::WriteMessage("Test Leet Code 2098");
    LeetCodeSort leetCode;
    vector<int> nums = { 4, 1, 5, 3, 1 };
    int k = 3;
    long long result = leetCode.largestEvenSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 4,6,2 };
    k = 3;
    result = leetCode.largestEvenSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,3,5 };
    k = 1;
    result = leetCode.largestEvenSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2111(void)
{
    Logger::WriteMessage("Test Leet Code 2111");
    LeetCodeSort leetCode;
    vector<int> arr = { 5, 4, 3, 2, 1 };
    int k = 1;
    int result = leetCode.kIncreasing(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 4,1,5,2,6,2 };
    k = 2;
    result = leetCode.kIncreasing(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 4,1,5,2,6,2 };
    k = 3;
    result = leetCode.kIncreasing(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2070(void)
{
    Logger::WriteMessage("Test Leet Code 2070");
    LeetCodeSort leetCode;
    vector<vector<int>> items = 
    {
        {1, 2},{3, 2},{2, 4},{5, 6},{3, 5} 
    };
    vector<int> queries = { 1, 2, 3, 4, 5, 6 };
    vector<int> result = leetCode.maximumBeauty(items, queries);
    Logger::WriteMessage(items);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    items =
    {
        {1,2},{1,2},{1,3},{1,4}
    };
    queries = { 1 };
    result = leetCode.maximumBeauty(items, queries);
    Logger::WriteMessage(items);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    items =
    {
        {10,1000}
    };
    queries = { 5 };
    result = leetCode.maximumBeauty(items, queries);
    Logger::WriteMessage(items);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode962(void)
{
    Logger::WriteMessage("Test Leet Code 962");
    LeetCodeSort leetCode;
    vector<int> A = { 6,0,8,2,1,5 };
    int result = leetCode.maxWidthRamp(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 9,8,1,0,1,9,4,0,4,1 };
    result = leetCode.maxWidthRamp(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode912(void)
{
    Logger::WriteMessage("Test Leet Code 912");
    LeetCodeSort leetCode;
    vector<int> A = { 5,2,3,1 };
    vector<int> result = leetCode.sortArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 5,1,1,2,0,0 };
    result = leetCode.sortArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode1029(void)
{
    Logger::WriteMessage("Test Leet Code 1029");
    LeetCodeSort leetCode;
    vector<vector<int>> costs = { {10, 20},{30, 200},{400, 50},{30, 20} };
    int result = leetCode.twoCitySchedCost(costs);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("result = " + to_string(result));

    costs = { {259, 770},{448, 54},{926, 667},{184, 139},{840, 118},{577, 469} };
    result = leetCode.twoCitySchedCost(costs);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1051(void)
{
    Logger::WriteMessage("Test Leet Code 1051");
    LeetCodeSort leetCode;
    vector<int> heights = { 1,1,4,2,1,3 };
    int result = leetCode.heightChecker(heights);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1053(void)
{
    Logger::WriteMessage("Test Leet Code 1053");
    LeetCodeSort leetCode;
    vector<int> A = { 3,2,1 };
    vector<int> result = leetCode.prevPermOpt1(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 1,1,5 };
    result = leetCode.prevPermOpt1(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 1,9,4,6,7 };
    result = leetCode.prevPermOpt1(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 3,1,1,3 };
    result = leetCode.prevPermOpt1(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode692(void)
{
    LeetCodeSort leetCode;
    vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
    int k = 2;
    vector<string> result = leetCode.topKFrequent(words, k);
    Logger::WriteMessage(words);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    k = 4;
    result = leetCode.topKFrequent(words, k);
    Logger::WriteMessage(words);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode738(void)
{
    LeetCodeSort leetCode;
    int N = 10;
    int result = leetCode.monotoneIncreasingDigits(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 1234;
    result = leetCode.monotoneIncreasingDigits(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 332;
    result = leetCode.monotoneIncreasingDigits(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode480(void)
{
    Logger::WriteMessage("Test Leet Code 480");
    LeetCodeSort leetCode;
    int k = 4;
    vector<int> nums = { 4, 1, 7, 1, 8, 7, 8, 7, 7, 4 };
    vector<double> result = leetCode.medianSlidingWindow(nums, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    k = 3;
    nums = { 1,3,-1,-3,5,3,6,7 };
    result = leetCode.medianSlidingWindow(nums, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    k = 2;
    nums = { 2147483647, 2147483647 };
    result = leetCode.medianSlidingWindow(nums, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}


void TestLeetCode665(void)
{
    LeetCodeSort leetCode;
    vector<int> nums = { 4, 2, 3 };
    bool result = leetCode.checkPossibility(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Can be non-descreasing array = " + (string)(result ? "true" : "false"));

    nums = { 4, 2, 1 };
    result = leetCode.checkPossibility(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Can be non-descreasing array = " + (string)(result ? "true" : "false"));

    nums = { 3, 4, 2, 5 };
    result = leetCode.checkPossibility(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Can be non-descreasing array = " + (string)(result ? "true" : "false"));
}

void TestLeetCode581(void)
{
    LeetCodeSort leetCode;
    vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
    Logger::WriteMessage(nums);
    int length = leetCode.findUnsortedSubarray(nums);
    Logger::WriteMessage("length = " + to_string(length));
}

void TestLeetCode555(void)
{
    LeetCodeSort leetCode;
    vector<string> strs = { "abc", "xyz" };
    string max_str = leetCode.splitLoopedString(strs);
    Logger::WriteMessage(strs);
    Logger::WriteMessage("Max String = " + max_str);
}

void TestLeetCode556(void)
{
    LeetCodeSort leetCode;
    int num = 12443322;
    int result = leetCode.nextGreaterElement(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
    num = 1234;
    result = leetCode.nextGreaterElement(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
    num = 12;
    result = leetCode.nextGreaterElement(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
    num = 998;
    result = leetCode.nextGreaterElement(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}


void TestLeetCode561(void)
{
    LeetCodeSort leetCode;
    vector<int> nums = { 1,4,3,2 };
    int sum = leetCode.arrayPairSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("sum of min = " + to_string(sum));
}

void TestLeetCode440(void)
{
    Logger::WriteMessage("Test Leet Code 440");
    LeetCodeSort leetCode;
    int n = 13;
    int k = 2;
    int result = leetCode.findKthNumber(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 13;
    k = 7;
    result = leetCode.findKthNumber(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}


void TestLeetCode321(void)
{
    Logger::WriteMessage("Test Leet Code 321");
    LeetCodeSort leetCode;
    vector<int> nums1 = { 3, 9 };
    vector<int> nums2 = { 8, 9 };
    int k = 3;
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    vector<int> result = leetCode.maxNumber(nums1, nums2, k);
    Logger::WriteMessage(result);

    nums1 = { 3, 4, 6, 5 };
    nums2 = { 9, 1, 2, 5, 8, 3 };
    k = 5;
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    result = leetCode.maxNumber(nums1, nums2, k);
    Logger::WriteMessage(result);

    nums1 = { 6, 7 };
    nums2 = { 6, 0, 4 };
    k = 5;
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    result = leetCode.maxNumber(nums1, nums2, k);
    Logger::WriteMessage(result);

    nums1 = { 5, 5, 1 };
    nums2 = { 4, 0, 1 };
    k = 3;
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    result = leetCode.maxNumber(nums1, nums2, k);
    Logger::WriteMessage(result);
}

void TestLeetCode280(void)
{
    Logger::WriteMessage("Test Leet Code 280");
    LeetCodeSort leetCode;
    vector<int> nums = { 3, 5, 2, 1, 6, 4 };
    Logger::WriteMessage(nums);
    leetCode.wiggleSort(nums);
    Logger::WriteMessage(nums);
}

void TestLeetCode220(void)
{
    Logger::WriteMessage("Test Leet Code 220");
    LeetCodeSort leetCode;
    vector<int> nums = { -1, -1 };
    int k = 1;
    int t = 0;
    bool result = leetCode.containsNearbyAlmostDuplicate(nums, k, t);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("index distance = " + to_string(k) + " ; value distance = " + to_string(t));
    Logger::WriteMessage("Result= " + (string)(result ? "true" : "false"));

    nums = { 1, 2 };
    k = 0;
    t = 1;
    result = leetCode.containsNearbyAlmostDuplicate(nums, k, t);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("index distance = " + to_string(k) + " ; value distance = " + to_string(t));
    Logger::WriteMessage("Result= " + (string)(result ? "true" : "false"));

    nums = { 7, 1, 3 };
    k = 2;
    t = 3;
    result = leetCode.containsNearbyAlmostDuplicate(nums, k, t);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("index distance = " + to_string(k) + " ; value distance = " + to_string(t));
    Logger::WriteMessage("Result= " + (string)(result ? "true" : "false"));
}

void TestLeetCode406(void)
{
    Logger::WriteMessage("Test Leet Code 406");
    LeetCodeSort leetCode;
    vector<vector<int>> heights = { { 7, 0 },{ 4, 4 },{ 7, 1 },{ 5, 0 },{ 6, 1 },{ 5, 2 } };
    vector<vector<int>> result = leetCode.reconstructQueue(heights);
    Logger::WriteMessage(result);
}

void TestLeetCode179(void)
{
    Logger::WriteMessage("Test Leet Code 179");
    vector<int> nums = { 3, 30, 32, 5, 9 };
    LeetCodeSort leetCode;
    string result = leetCode.largestNumber(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Result = " + result);

    nums = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    result = leetCode.largestNumber(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Result = " + result);

    nums = { 12, 121 };
    result = leetCode.largestNumber(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Result = " + result);
}

void TestLeetCode376(void)
{
    Logger::WriteMessage("Test Leet Code 376");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 7, 4, 9, 2, 5 };
    int length = leetCode.wiggleMaxLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Maximum Wiggle Length = " + to_string(length));
    nums = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    length = leetCode.wiggleMaxLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Maximum Wiggle Length = " + to_string(length));
    nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    length = leetCode.wiggleMaxLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Maximum Wiggle Length = " + to_string(length));
}

void TestLeetCode324(void)
{
    Logger::WriteMessage("Test Leet Code 324");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 5, 1, 1, 6, 4 };
    Logger::WriteMessage(nums);
    leetCode.wiggleSortII(nums);
    Logger::WriteMessage(nums);
}

void TestLeetCode274(void)
{
    Logger::WriteMessage("Test Leet Code 274");
    LeetCodeSort leetCode;
    vector<int> nums = { 1 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("H index =" + to_string(leetCode.hIndex(nums)));

    nums = { 3, 0, 6, 1, 5 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("H index =" + to_string(leetCode.hIndex(nums)));
}

void TestLeetCode164(void)
{
    Logger::WriteMessage("Test Leet Code 164");
    LeetCodeSort leetCode;
    vector<int> numbers;
    int max_gap;
    numbers = { 0, 100000 };
    Logger::WriteMessage(numbers);
    max_gap = leetCode.maximumGap(numbers);
    Logger::WriteMessage("The maximum gap is " + to_string(max_gap));

    numbers = { 1, 1, 1, 1 };
    Logger::WriteMessage(numbers);
    max_gap = leetCode.maximumGap(numbers);
    Logger::WriteMessage("The maximum gap is " + to_string(max_gap));

    numbers = { 1, 7, 3, 4, 6, 2, 0 };
    Logger::WriteMessage(numbers);
    max_gap = leetCode.maximumGap(numbers);
    Logger::WriteMessage("The maximum gap is " + to_string(max_gap));

    numbers = {};
    Logger::WriteMessage(numbers);
    max_gap = leetCode.maximumGap(numbers);
    Logger::WriteMessage("The maximum gap is " + to_string(max_gap));
}

void TestLeetCode75(void)
{
    Logger::WriteMessage("Test Leet Code 75");
    LeetCodeSort leetCode;
    vector<int> nums;
    nums = { 0, 2, 0, 1, 0, 2, 1, 0, 2, 1 };
    Logger::WriteMessage(nums);
    leetCode.sortColors(nums);
    Logger::WriteMessage(nums);

    nums = { };
    Logger::WriteMessage(nums);
    leetCode.sortColors(nums);
    Logger::WriteMessage(nums);

    nums = { 2, 1, 1, 2 };
    Logger::WriteMessage(nums);
    leetCode.sortColors(nums);
    Logger::WriteMessage(nums);

    nums = { 1, 0 };
    Logger::WriteMessage(nums);
    leetCode.sortColors(nums);
    Logger::WriteMessage(nums);
}

void TestLeetCode744(void)
{
    Logger::WriteMessage("Test Leet Code 744");
    LeetCodeSort leetCode;
    vector<char> letters = { 'a', 'b' };
    char target = 'z';
    char result = leetCode.nextGreatestLetter(letters, target);
    Logger::WriteMessage(letters);
    string buffer = "target = ";
    buffer.push_back(target);
    buffer.push_back(';');
    buffer.append(" result = ");
    buffer.push_back(result);
    Logger::WriteMessage(buffer);

    letters = { 'c', 'f', 'j' };
    target = 'c';
    result = leetCode.nextGreatestLetter(letters, target);
    Logger::WriteMessage(letters);
    buffer = "target = ";
    buffer.push_back(target);
    buffer.push_back(';');
    buffer.append(" result = ");
    buffer.push_back(result);
    Logger::WriteMessage(buffer);

    letters = { 'c', 'f', 'j' };
    target = 'd';
    result = leetCode.nextGreatestLetter(letters, target);
    Logger::WriteMessage(letters);
    buffer = "target = ";
    buffer.push_back(target);
    buffer.push_back(';');
    buffer.append(" result = ");
    buffer.push_back(result);
    Logger::WriteMessage(buffer);

    letters = { 'c', 'f', 'j' };
    target = 'g';
    result = leetCode.nextGreatestLetter(letters, target);
    Logger::WriteMessage(letters);
    buffer = "target = ";
    buffer.push_back(target);
    buffer.push_back(';');
    buffer.append(" result = ");
    buffer.push_back(result);
    Logger::WriteMessage(buffer);

    letters = { 'c', 'f', 'j' };
    target = 'j';
    result = leetCode.nextGreatestLetter(letters, target);
    Logger::WriteMessage(letters);
    buffer = "target = ";
    buffer.push_back(target);
    buffer.push_back(';');
    buffer.append(" result = ");
    buffer.push_back(result);
    Logger::WriteMessage(buffer);

    letters = { 'c', 'f', 'j' };
    target = 'k';
    result = leetCode.nextGreatestLetter(letters, target);
    buffer = "target = ";
    buffer.push_back(target);
    buffer.push_back(';');
    buffer.append(" result = ");
    buffer.push_back(result);
    Logger::WriteMessage(buffer);
}

void TestLeetCode1182(void)
{
    Logger::WriteMessage("Test Leet Code 1182");
    LeetCodeSort leetCode;
    vector<int> colors = { 1, 1, 2, 1, 3, 2, 2, 3, 3 };
    vector<vector<int>> queries = { {1, 3},{2, 2},{6, 1} };
    vector<int> result = leetCode.shortestDistanceColor(colors, queries);
    Logger::WriteMessage(colors);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    colors = { 1,2 };
    queries = { {0,3} };
    result = leetCode.shortestDistanceColor(colors, queries);
    Logger::WriteMessage(colors);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1199(void)
{
    Logger::WriteMessage("Test Leet Code 1199");
    LeetCodeSort leetCode;
    vector<int> blocks = { 1 };
    int split = 1;
    int result = leetCode.minBuildTime(blocks, split);
    Logger::WriteMessage(blocks);
    Logger::WriteMessage("split = " + to_string(split) + "; result = " + to_string(result));

    blocks = { 1,2 };
    split = 5;
    result = leetCode.minBuildTime(blocks, split);
    Logger::WriteMessage(blocks);
    Logger::WriteMessage("split = " + to_string(split) + "; result = " + to_string(result));

    blocks = { 1,2,3 };
    split = 1;
    result = leetCode.minBuildTime(blocks, split);
    Logger::WriteMessage(blocks);
    Logger::WriteMessage("split = " + to_string(split) + "; result = " + to_string(result));
}

void TestLeetCode954(void)
{
    Logger::WriteMessage("Test Leet Code 954");
    LeetCodeSort leetCode;
    vector<int> A = { 3,1,3,6 };
    bool result = leetCode.canReorderDoubled(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 2,1,2,6 };
    result = leetCode.canReorderDoubled(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 4,-2,2,-4 };
    result = leetCode.canReorderDoubled(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 1,2,4,16,8,4 };
    result = leetCode.canReorderDoubled(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 2, 1, 2, 1, 1, 1, 2, 2 };
    result = leetCode.canReorderDoubled(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode955(void)
{
    Logger::WriteMessage("Test Leet Code 955");
    LeetCodeSort leetCode;
    vector<string> A = { "ca","bb","ac" };
    int result = leetCode.minDeletionSizeII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "xc","yb","za" };
    result = leetCode.minDeletionSizeII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "zyx","wvu","tsr" };
    result = leetCode.minDeletionSizeII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "wyx","zvu","tsr" };
    result = leetCode.minDeletionSizeII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "ayx","bvu","csr" };
    result = leetCode.minDeletionSizeII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode769(void)
{
    Logger::WriteMessage("Test Leet Code 769");
    LeetCodeSort leetCode;
    vector<int> arr = { 4,3,2,1,0 };
    int result = leetCode.maxChunksToSorted(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,0,2,3,4 };
    result = leetCode.maxChunksToSorted(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1167(void)
{
    Logger::WriteMessage("Test Leet Code 1167");
    LeetCodeSort leetCode;
    vector<int> sticks = { 2,4,3 };
    int result = leetCode.connectSticks(sticks);
    Logger::WriteMessage(sticks);
    Logger::WriteMessage("result = " + to_string(result));

    sticks = { 1,8,3,5 };
    result = leetCode.connectSticks(sticks);
    Logger::WriteMessage(sticks);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1122(void)
{
    Logger::WriteMessage("Test Leet Code 1122");
    LeetCodeSort leetCode;
    vector<int> arr1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
    vector<int> arr2 = { 2, 1, 4, 3, 9, 6 };
    vector<int> result = leetCode.relativeSortArray(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage(result);
}

void TestLeetCode1133(void)
{
    Logger::WriteMessage("Test Leet Code 1133");
    LeetCodeSort leetCode;
    vector<int> A = { 5, 7, 3, 9, 4, 9, 8, 3, 1 };
    int result = leetCode.largestUniqueNumber(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 9,9,8,8 };
    result = leetCode.largestUniqueNumber(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1169(void)
{
    Logger::WriteMessage("Test Leet Code 1169");
    LeetCodeSort leetCode;
    vector<string> transactions = { "alice,20,800,mtv", "alice,50,100,beijing" };
    vector<string> result = leetCode.invalidTransactions(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage(result);

    transactions = { "alice,20,800,mtv","alice,50,1200,mtv" };
    result = leetCode.invalidTransactions(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage(result);

    transactions = { "alice,20,1800,mtv","alice,50,200,shanghai" };
    result = leetCode.invalidTransactions(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage(result);

    transactions = { "alice,20,800,mtv","bob,50,1200,mtv" };
    result = leetCode.invalidTransactions(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage(result);
}

void TestLeetCode1099(void)
{
    Logger::WriteMessage("Test Leet Code 1099");
    LeetCodeSort leetCode;
    vector<int> A = { 34, 23, 1, 24, 75, 33, 54, 8 };
    int K = 60;
    int result = leetCode.twoSumLessThanK(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 10, 20, 30 };
    K = 15;
    result = leetCode.twoSumLessThanK(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1086(void)
{
    Logger::WriteMessage("Test Leet Code 1086");
    LeetCodeSort leetCode;
    vector<vector<int>> items =
    {
        {1, 91},{1, 92},{2, 93},{2, 97},{1, 60},{2, 77},{1, 65},{1, 87}, {1,100},{2,100},{2,76}
    };
    vector<vector<int>> result = leetCode.highFive(items);
    Logger::WriteMessage(items);
    Logger::WriteMessage(result);
}

void TestLeetCode1090(void)
{
    Logger::WriteMessage("Test Leet Code 1090");
    LeetCodeSort leetCode;
    vector<int> values = { 5, 4, 3, 2, 1 };
    vector<int> labels = { 1, 1, 2, 2, 3 };
    int num_wanted = 3;
    int use_limit = 1;
    int result = leetCode.largestValsFromLabels(values, labels, num_wanted, use_limit);
    Logger::WriteMessage(values);
    Logger::WriteMessage(labels);
    Logger::WriteMessage("num_wanted = " + to_string(num_wanted) +
        "; use_limit = " + to_string(use_limit) + "; result = " + to_string(result));

    values = { 5,4,3,2,1 };
    labels = { 1,3,3,3,2 };
    num_wanted = 3;
    use_limit = 2;
    result = leetCode.largestValsFromLabels(values, labels, num_wanted, use_limit);
    Logger::WriteMessage(values);
    Logger::WriteMessage(labels);
    Logger::WriteMessage("num_wanted = " + to_string(num_wanted) +
        "; use_limit = " + to_string(use_limit) + "; result = " + to_string(result));

    values = { 9,8,8,7,6 };
    labels = { 0,0,0,1,1 };
    num_wanted = 3;
    use_limit = 1;
    result = leetCode.largestValsFromLabels(values, labels, num_wanted, use_limit);
    Logger::WriteMessage(values);
    Logger::WriteMessage(labels);
    Logger::WriteMessage("num_wanted = " + to_string(num_wanted) +
        "; use_limit = " + to_string(use_limit) + "; result = " + to_string(result));

    values = { 9,8,8,7,6 };
    labels = { 0,0,0,20000,20000 };
    num_wanted = 3;
    use_limit = 2;
    result = leetCode.largestValsFromLabels(values, labels, num_wanted, use_limit);
    Logger::WriteMessage(values);
    Logger::WriteMessage(labels);
    Logger::WriteMessage("num_wanted = " + to_string(num_wanted) +
        "; use_limit = " + to_string(use_limit) + "; result = " + to_string(result));
}

void TestLeetCode1046(void)
{
    Logger::WriteMessage("Test Leet Code 1046");
    LeetCodeSort leetCode;
    vector<int> stones = { 2,7,4,1,8,1 };
    int result = leetCode.lastStoneWeight(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode775(void)
{
    Logger::WriteMessage("Test Leet Code 775");
    LeetCodeSort leetCode;
    vector<int> A = { 2, 0, 3, 1 };
    bool result = leetCode.isIdealPermutation(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 1,2,0 };
    result = leetCode.isIdealPermutation(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 1,0,2 };
    result = leetCode.isIdealPermutation(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode853(void)
{
    Logger::WriteMessage("Test Leet Code 853");
    LeetCodeSort leetCode;
    int target = 12;
    vector<int>position = { 10, 8, 0, 5, 3 };
    vector<int>speed = { 2, 4, 1, 1, 3 };
    int result = leetCode.carFleet(target, position, speed);
    Logger::WriteMessage(position);
    Logger::WriteMessage(speed);
    Logger::WriteMessage("result = " + to_string(result));

    target = 10;
    position = { 6, 8 };
    speed = { 3, 2 };
    result = leetCode.carFleet(target, position, speed);
    Logger::WriteMessage(position);
    Logger::WriteMessage(speed);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode870(void)
{
    Logger::WriteMessage("Test Leet Code 870");
    LeetCodeSort leetCode;
    vector<int> A = { 2,7,11,15 };
    vector<int> B = { 1,10,4,11 };
    vector<int> result = leetCode.advantageCount(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { 12,24,8,32 };
    B = { 13,25,32,11 };
    result = leetCode.advantageCount(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);
}

void TestLeetCode798(void)
{
    Logger::WriteMessage("Test Leet Code 798");
    LeetCodeSort leetCode;
    vector<int> A = { 2, 3, 1, 4, 0 };
    int result = leetCode.bestRotation(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode941(void)
{
    Logger::WriteMessage("Test Leet Code 941");
    LeetCodeSort leetCode;
    vector<int> A = { 2, 1 };
    bool result = leetCode.validMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 3,5,5 };
    result = leetCode.validMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 0,3,2,1 };
    result = leetCode.validMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode953(void)
{
    Logger::WriteMessage("Test Leet Code 953");
    LeetCodeSort leetCode;
    vector<string> words = { "hello","leetcode" };
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    bool result = leetCode.isAlienSorted(words, order);
    Logger::WriteMessage(words);
    Logger::WriteMessage("order = " + order);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    words = { "word","world","row" };
    order = "worldabcefghijkmnpqstuvxyz";
    result = leetCode.isAlienSorted(words, order);
    Logger::WriteMessage(words);
    Logger::WriteMessage("order = " + order);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    words = { "apple","app" };
    order = "abcdefghijklmnopqrstuvwxyz";
    result = leetCode.isAlienSorted(words, order);
    Logger::WriteMessage(words);
    Logger::WriteMessage("order = " + order);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}


void TestLeetCode942(void)
{
    Logger::WriteMessage("Test Leet Code 942");
    LeetCodeSort leetCode;
    string S = "IDID";
    vector<int> result = leetCode.diStringMatch(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "III";
    result = leetCode.diStringMatch(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "DDI";
    result = leetCode.diStringMatch(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode977(void)
{
    Logger::WriteMessage("Test Leet Code 977");
    LeetCodeSort leetCode;
    vector<int> A = { -4,-1,0,3,10 };
    vector<int> result = leetCode.sortedSquares(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { -7,-3,2,3,11 };
    result = leetCode.sortedSquares(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode2136(void)
{
    Logger::WriteMessage("Test Leet Code 2136");
    LeetCodeSort leetCode;
    vector<int> plantTime = { 1, 4, 3 };
    vector<int> growTime = { 2, 3, 1 };
    int result = leetCode.earliestFullBloom(plantTime, growTime);
    Logger::WriteMessage(plantTime);
    Logger::WriteMessage(growTime);
    Logger::WriteMessage("result = " + to_string(result));

    plantTime = { 1, 4, 3 };
    growTime = { 2, 3, 1 };
    result = leetCode.earliestFullBloom(plantTime, growTime);
    Logger::WriteMessage(plantTime);
    Logger::WriteMessage(growTime);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2126(void)
{
    Logger::WriteMessage("Test Leet Code 2126");
    LeetCodeSort leetCode;
    int mass = 10;
    vector<int> asteroids = { 3, 9, 19, 5, 21 };
    bool result = leetCode.asteroidsDestroyed(mass, asteroids);
    Logger::WriteMessage(asteroids);
    Logger::WriteMessage("mass = " + to_string(mass) + "; result = " + (string)(result ? "true" : "false"));

    mass = 5;
    asteroids = { 4,9,23,4 };
    result = leetCode.asteroidsDestroyed(mass, asteroids);
    Logger::WriteMessage(asteroids);
    Logger::WriteMessage("mass = " + to_string(mass) + "; result = " + (string)(result ? "true" :"false"));
}

void TestLeetCode2144(void)
{
    Logger::WriteMessage("Test Leet Code 2144");
    LeetCodeSort leetCode;
    vector<int> cost = { 1, 2, 3 };
    int result = leetCode.minimumCost(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    cost = { 6,5,7,9,2,2 };
    result = leetCode.minimumCost(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    cost = { 5,5 };
    result = leetCode.minimumCost(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2148(void)
{
    Logger::WriteMessage("Test Leet Code 2148");

    LeetCodeSort leetCode;
    vector<int> nums = { 11,7,2,15 };
    int result = leetCode.countElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -3,3,3,90 };
    result = leetCode.countElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,2,2 };
    result = leetCode.countElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2164(void)
{
    Logger::WriteMessage("Test Leet Code 2164");

    LeetCodeSort leetCode;
    vector<int> nums = { 4, 1, 2, 3 };
    vector<int> result = leetCode.sortEvenOdd(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 2,1 };
    result = leetCode.sortEvenOdd(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2165(void)
{
    Logger::WriteMessage("Test Leet Code 2165");

    LeetCodeSort leetCode;
    long long  num = 310;
    long long result = leetCode.smallestNumber(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = -7605;
    result = leetCode.smallestNumber(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode2171(void)
{
    Logger::WriteMessage("Test Leet Code 2171");

    LeetCodeSort leetCode;
    vector<int> beans = { 4, 1, 6, 5 };
    long long result = leetCode.minimumRemoval(beans);
    Logger::WriteMessage(beans);
    Logger::WriteMessage("result = " + to_string(result));

    beans = { 2,10,3,2 };
    result = leetCode.minimumRemoval(beans);
    Logger::WriteMessage(beans);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2263(void)
{
    Logger::WriteMessage("Test Leet Code 2263");

    LeetCodeSort leetCode;
    vector<int> nums = { 3, 2, 4, 5, 0 };
    int result = leetCode.convertArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,3,4 };
    result = leetCode.convertArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0 };
    result = leetCode.convertArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2250(void)
{
    Logger::WriteMessage("Test Leet Code 2250");

    LeetCodeSort leetCode;
    vector<vector<int>> rectangles = { {1, 2},{2, 3},{2, 5} };
    vector<vector<int>> points = { {2, 1},{1, 4} };
    vector<int> result = leetCode.countRectangles(rectangles, points);
    Logger::WriteMessage(rectangles);
    Logger::WriteMessage(points);
    Logger::WriteMessage(result);

    rectangles = { {1, 1},{2, 2},{3, 3} };
    points = { {1, 3},{1, 1} };
    result = leetCode.countRectangles(rectangles, points);
    Logger::WriteMessage(rectangles);
    Logger::WriteMessage(points);
    Logger::WriteMessage(result);

}

void TestLeetCode2279(void)
{
    Logger::WriteMessage("Test Leet Code 2279");
    LeetCodeSort leetCode;
    vector<int> capacity = { 2, 3, 4, 5 };
    vector<int> rocks = { 1, 2, 4, 4 };
    int additionalRocks = 2;
    int result = leetCode.maximumBags(capacity, rocks, additionalRocks);
    Logger::WriteMessage(capacity);
    Logger::WriteMessage(rocks);
    Logger::WriteMessage("additionalRocks = " + to_string(additionalRocks) + "; result = " + to_string(result));

    capacity = { 10,2,2 };
    rocks = { 2,2,0 };
    additionalRocks = 100;
    result = leetCode.maximumBags(capacity, rocks, additionalRocks);
    Logger::WriteMessage(capacity);
    Logger::WriteMessage(rocks);
    Logger::WriteMessage("additionalRocks = " + to_string(additionalRocks) + "; result = " + to_string(result));
}

void TestLeetCode2285(void)
{
    Logger::WriteMessage("Test Leet Code 2285");
    LeetCodeSort leetCode;
    int n = 5;
    vector<vector<int>> roads = { {0, 1},{1, 2},{2, 3},{0, 2},{1, 3},{2, 4} };
    long long result = leetCode.maximumImportance(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 5;
    roads = { {0, 3},{2, 4},{1, 3} };
    result = leetCode.maximumImportance(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2300(void)
{
    Logger::WriteMessage("Test Leet Code 2300");
    LeetCodeSort leetCode;
    vector<int> spells = { 5, 1, 3 };
    vector<int> potions = { 1, 2, 3, 4, 5 };
    long long success = 7;
    vector<int> result = leetCode.successfulPairs(spells, potions, success);
    Logger::WriteMessage(spells);
    Logger::WriteMessage(potions);
    Logger::WriteMessage("success = " + to_string(success));
    Logger::WriteMessage(result);

    spells = { 3,1,2 };
    potions = { 8,5,8 };
    success = 16;
    result = leetCode.successfulPairs(spells, potions, success);
    Logger::WriteMessage(spells);
    Logger::WriteMessage(potions);
    Logger::WriteMessage("success = " + to_string(success));
    Logger::WriteMessage(result);
}

void TestLeetCode2323(void)
{
    Logger::WriteMessage("Test Leet Code 2323");
    LeetCodeSort leetCode;
    vector<int> jobs = { 5, 2, 4 };
    vector<int> workers = { 1, 7, 5 };
    int result = leetCode.minimumTime(jobs, workers);
    Logger::WriteMessage(jobs);
    Logger::WriteMessage(workers);
    Logger::WriteMessage("result = " + to_string(result));

    jobs = { 3,18,15,9 };
    workers = { 6,5,1,3 };
    result = leetCode.minimumTime(jobs, workers);
    Logger::WriteMessage(jobs);
    Logger::WriteMessage(workers);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2332(void)
{
    Logger::WriteMessage("Test Leet Code 2332");
    LeetCodeSort leetCode;
    vector<int> buses = { 10, 20 };
    vector<int> passengers = { 2, 17, 18, 19 };
    int capacity = 2;
    int result = leetCode.latestTimeCatchTheBus(buses, passengers, capacity);
    Logger::WriteMessage(buses);
    Logger::WriteMessage(passengers);
    Logger::WriteMessage("capacity = " + to_string(capacity) + "; result = " + to_string(result));

    buses = { 20,30,10 };
    passengers = { 19,13,26,4,25,11,21 };
    capacity = 2;
    result = leetCode.latestTimeCatchTheBus(buses, passengers, capacity);
    Logger::WriteMessage(buses);
    Logger::WriteMessage(passengers);
    Logger::WriteMessage("capacity = " + to_string(capacity) + "; result = " + to_string(result));
}

void TestLeetCode2386(void)
{
    Logger::WriteMessage("Test Leet Code 2386");
    LeetCodeSort leetCode;
    vector<int> nums = { 2, 4, -2 };
    int k = 5;
    long long result = leetCode.kSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,-2,3,4,-10,12 };
    k = 16;
    result = leetCode.kSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 492634335, 899178915, 230945927 };
    k = 2;
    result = leetCode.kSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2387(void)
{
    Logger::WriteMessage("Test Leet Code 2387");
    LeetCodeSort leetCode;
    vector<vector<int>>  grid = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    int result = leetCode.matrixMedian(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1,1,3,3,4} };
    result = leetCode.matrixMedian(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2418(void)
{
    Logger::WriteMessage("Test Leet Code 2418");
    LeetCodeSort leetCode;
    vector<string>names = { "Mary", "John", "Emma" };
    vector<int> heights = { 180, 165, 170 };
    vector<string> result = leetCode.sortPeople(names, heights);
    Logger::WriteMessage(names);
    Logger::WriteMessage(heights);
    Logger::WriteMessage(result);

    names = { "Alice","Bob","Bob" };
    heights = { 155,185,150 };
    result = leetCode.sortPeople(names, heights);
    Logger::WriteMessage(names);
    Logger::WriteMessage(heights);
    Logger::WriteMessage(result);
}

void TestLeetCode2454(void)
{
    Logger::WriteMessage("Test Leet Code 2454");
    LeetCodeSort leetCode;
    vector<int> nums = { 2, 4, 0, 9, 6 };
    vector<int> result = leetCode.secondGreaterElement(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 3,3 };
    result = leetCode.secondGreaterElement(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2491(void)
{
    Logger::WriteMessage("Test Leet Code 2491");
    LeetCodeSort leetCode;
    vector<int> skill = { 3,2,5,1,3,4 };
    long long result = leetCode.dividePlayers(skill);
    Logger::WriteMessage(skill);
    Logger::WriteMessage("result = " + to_string(result));

    skill = { 3,4 };
    result = leetCode.dividePlayers(skill);
    Logger::WriteMessage(skill);
    Logger::WriteMessage("result = " + to_string(result));

    skill = { 1,1,2,3 };
    result = leetCode.dividePlayers(skill);
    Logger::WriteMessage(skill);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2519(void)
{
    Logger::WriteMessage("Test Leet Code 2519");
    LeetCodeSort leetCode;
    vector<int> nums = { 2, 3, 6, 5, 2, 3 };
    int k = 2;
    int result = leetCode.kBigIndices(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,1,1 };
    k = 3;
    result = leetCode.kBigIndices(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2530(void)
{
    Logger::WriteMessage("Test Leet Code 2530");
    LeetCodeSort leetCode;
    vector<int> nums = { 10,10,10,10,10 };
    int k = 5;
    long long result = leetCode.maxKelements(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,10,3,3,3 };
    k = 3;
    result = leetCode.maxKelements(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2548(void)
{
    Logger::WriteMessage("Test Leet Code 2548");
    LeetCodeSort leetCode;
    vector<vector<int>> items = { {50, 1},{10, 8} };
    int capacity = 5;
    double result = leetCode.maxPrice(items, capacity);
    Logger::WriteMessage(items);
    Logger::WriteMessage("capacity = " + to_string(capacity) + "; result = " + to_string(result));

    items = { {100, 30} };
    capacity = 50;
    result = leetCode.maxPrice(items, capacity);
    Logger::WriteMessage(items);
    Logger::WriteMessage("capacity = " + to_string(capacity) + "; result = " + to_string(result));
}

void TestLeetCode2551(void)
{
    Logger::WriteMessage("Test Leet Code 2551");
    LeetCodeSort leetCode;
    vector<int> weights = { 1, 3, 5, 1 };
    int k = 2;
    long long result = leetCode.putMarbles(weights, k);
    Logger::WriteMessage(weights);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    weights = { 1, 3 };
    k = 2;
    result = leetCode.putMarbles(weights, k);
    Logger::WriteMessage(weights);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2558(void)
{
    Logger::WriteMessage("Test Leet Code 2558");
    LeetCodeSort leetCode;
    vector<int> gifts = { 25, 64, 9, 4, 100 };
    int k = 4;
    long long result = leetCode.pickGifts(gifts, k);
    Logger::WriteMessage(gifts);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    gifts = { 1,1,1,1 };
    k = 4;
    result = leetCode.pickGifts(gifts, k);
    Logger::WriteMessage(gifts);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2561(void)
{
    Logger::WriteMessage("Test Leet Code 2561");
    LeetCodeSort leetCode;
    vector<int> basket1 = { 4,2,2,2 };
    vector<int> basket2 = { 1,4,1,2 };
    long long result = leetCode.minCost(basket1, basket2);
    Logger::WriteMessage(basket1);
    Logger::WriteMessage(basket2);
    Logger::WriteMessage("result = " + to_string(result));

    basket1 = { 2,3,4,1 };
    basket2 = { 3,2,5,1 };
    result = leetCode.minCost(basket1, basket2);
    Logger::WriteMessage(basket1);
    Logger::WriteMessage(basket2);
    Logger::WriteMessage("result = " + to_string(result));

    basket1 = { 1,1,2,2,3,3,4,4 };
    basket2 = { 5,5,6,6,7,7,8,8 };
    result = leetCode.minCost(basket1, basket2);
    Logger::WriteMessage(basket1);
    Logger::WriteMessage(basket2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2567(void)
{
    Logger::WriteMessage("Test Leet Code 2567");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 4, 3 };
    int result = leetCode.minimizeSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,4,7,8,5 };
    result = leetCode.minimizeSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2594(void)
{
    Logger::WriteMessage("Test Leet Code 2594");
    LeetCodeSort leetCode;
    vector<int> ranks = { 4, 2, 3, 1 };
    int cars = 10;
    long long result = leetCode.repairCars(ranks, cars);
    Logger::WriteMessage(ranks);
    Logger::WriteMessage("cars = " + to_string(cars) + "; result = " + to_string(result));

    ranks = { 5,1,8 };
    cars = 6;
    result = leetCode.repairCars(ranks, cars);
    Logger::WriteMessage(ranks);
    Logger::WriteMessage("cars = " + to_string(cars) + "; result = " + to_string(result));
}

void TestLeetCode2599(void)
{
    Logger::WriteMessage("Test Leet Code 2599");
    LeetCodeSort leetCode;
    vector<int> nums = { 2, 3, -5, 4 };
    int result = leetCode.makePrefSumNonNegative(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,-5,-2,6 };
    result = leetCode.makePrefSumNonNegative(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2611(void)
{
    Logger::WriteMessage("Test Leet Code 2611");
    LeetCodeSort leetCode;
    vector<int> reward1 = { 1, 1, 3, 4 };
    vector<int> reward2 = { 4, 4, 1, 1 };
    int k = 2;
    int result = leetCode.miceAndCheese(reward1, reward2, k);
    Logger::WriteMessage(reward1);
    Logger::WriteMessage(reward2);
    Logger::WriteMessage("k = " + to_string(k) + "; `result = " + to_string(result));

    reward1 = { 1,1 };
    reward2 = { 1,1 };
    k = 2;
    result = leetCode.miceAndCheese(reward1, reward2, k);
    Logger::WriteMessage(reward1);
    Logger::WriteMessage(reward2);
    Logger::WriteMessage("k = " + to_string(k) + "; `result = " + to_string(result));
}

void TestLeetCode2613(void)
{
    Logger::WriteMessage("Test Leet Code 2613");
    LeetCodeSort leetCode;
    vector<int> nums1 = { 1, 2, 3, 2, 4 }; 
    vector<int> nums2 = { 2, 3, 1, 2, 3 };
    vector<int> result = leetCode.beautifulPair(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);

    nums1 = { 1,2,4,3,2,5 };
    nums2 = { 1,4,2,3,5,1 };
    result = leetCode.beautifulPair(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);
}

void TestLeetCode2653(void)
{
    Logger::WriteMessage("Test Leet Code 2653");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, -1, -3, -2, 3 };
    int k = 3, x = 2;
    vector<int> result = leetCode.getSubarrayBeauty(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { -1,-2,-3,-4,-5 };
    k = 2, x = 2;
    result = leetCode.getSubarrayBeauty(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { -3,1,2,-3,0,-3 };
    k = 2, x = 1;
    result = leetCode.getSubarrayBeauty(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);
}

void TestLeetCode2659(void)
{
    Logger::WriteMessage("Test Leet Code 2659");
    LeetCodeSort leetCode;
    vector<int> nums = { 3, 4, -1 };
    long long result = leetCode.countOperationsToEmptyArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,4,3 };
    result = leetCode.countOperationsToEmptyArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3 };
    result = leetCode.countOperationsToEmptyArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2679(void)
{
    Logger::WriteMessage("Test Leet Code 2679");
    LeetCodeSort leetCode;
    vector<vector<int>> nums =
    {
        {7, 2, 1},{6, 4, 2}, {6, 5, 3},{3, 2, 1}
    };
    int result = leetCode.matrixSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums =
    {
        {1}
    };
    result = leetCode.matrixSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2740(void)
{
    Logger::WriteMessage("Test Leet Code 2740");
    LeetCodeSort leetCode;
    vector<int> nums = {1,3,2,4};
    int result = leetCode.findValueOfPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 100,1,10 };
    result = leetCode.findValueOfPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2736(void)
{
    Logger::WriteMessage("Test Leet Code 2736");
    LeetCodeSort leetCode;
    vector<int> nums1 = { 4, 3, 1, 2 };
    vector<int> nums2 = { 2, 4, 9, 5 }; 
    vector<vector<int>> queries = { {4, 1},{1, 3},{2, 5} };
    vector<int> result = leetCode.maximumSumQueries(nums1, nums2, queries);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    nums1 = { 3,2,5 };
    nums2 = { 2,3,4 };
    queries = { {4,4} ,{3,2},{1,1} };
    result = leetCode.maximumSumQueries(nums1, nums2, queries);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    nums1 = { 2,1 };
    nums2 = { 2,3 };
    queries = { {3,3} };
    result = leetCode.maximumSumQueries(nums1, nums2, queries);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    nums1 = { 13, 67, 90, 92, 47 };
    nums2 = { 52,60,69,49,73 };
    queries = { {32,70} };
    result = leetCode.maximumSumQueries(nums1, nums2, queries);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode2763(void)
{
    Logger::WriteMessage("Test Leet Code 2763");
    LeetCodeSort leetCode;
    vector<int> nums = { 2, 3, 1, 4 };
    int result = leetCode.sumImbalanceNumbers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,3,3,3,5 };
    result = leetCode.sumImbalanceNumbers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2817(void)
{
    Logger::WriteMessage("Test Leet Code 2817");
    LeetCodeSort leetCode;
    vector<int> nums = { 4, 3, 2, 4 };
    int x = 2;
    int result = leetCode.minAbsoluteDifference(nums, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    nums = { 5,3,2,10,15 };
    x = 1;
    result = leetCode.minAbsoluteDifference(nums, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    nums = { 1,2,3,4 };
    x = 3;
    result = leetCode.minAbsoluteDifference(nums, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));
}

void TestLeetCode2835(void)
{
    Logger::WriteMessage("Test Leet Code 2835");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 2, 8 };
    int target = 7;
    int result = leetCode.minOperations(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { 1, 32, 1, 2 };
    target = 12;
    result = leetCode.minOperations(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { 1,32,1 };
    target = 35;
    result = leetCode.minOperations(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode2838(void)
{
    Logger::WriteMessage("Test Leet Code 2838");
    LeetCodeSort leetCode;
    vector<int> heroes = { 1, 4, 2 };
    vector<int> monsters = { 1, 1, 5, 2, 3 };
    vector<int> coins = { 2, 3, 4, 5, 6 };
    vector<long long> result = leetCode.maximumCoins(heroes, monsters, coins);
    Logger::WriteMessage(heroes);
    Logger::WriteMessage(monsters);
    Logger::WriteMessage(coins);
    Logger::WriteMessage(result);

    heroes = { 5 };
    monsters = { 2,3,1,2 };
    coins = { 10,6,5,2 };
    result = leetCode.maximumCoins(heroes, monsters, coins);
    Logger::WriteMessage(heroes);
    Logger::WriteMessage(monsters);
    Logger::WriteMessage(coins);
    Logger::WriteMessage(result);
}

void TestLeetCode2855(void)
{
    Logger::WriteMessage("Test Leet Code 2855");
    LeetCodeSort leetCode;
    vector<int> nums = { 3, 4, 5, 1, 2 };
    int result = leetCode.minimumRightShifts(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,3,5 };
    result = leetCode.minimumRightShifts(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,1,4 };
    result = leetCode.minimumRightShifts(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2856(void)
{
    Logger::WriteMessage("Test Leet Code 2856");
    LeetCodeSort leetCode;
    vector<int> nums = { 1,3,4,9 };
    int result = leetCode.minLengthAfterRemovals(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,3,6,9 };
    result = leetCode.minLengthAfterRemovals(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,2 };
    result = leetCode.minLengthAfterRemovals(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2860(void)
{
    Logger::WriteMessage("Test Leet Code 2860");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 1 };
    int result = leetCode.countWays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 6, 0, 3, 3, 6, 7, 2, 7 };
    result = leetCode.countWays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2863(void)
{
    Logger::WriteMessage("Test Leet Code 2863");
    LeetCodeSort leetCode;
    vector<int> nums = { 7, 6, 5, 4, 3, 2, 1, 6, 10, 11 };
    int result = leetCode.maxSubarrayLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 57,55,50,60,61,58,63,59,64,60,63 };
    result = leetCode.maxSubarrayLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4 };
    result = leetCode.maxSubarrayLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -1, 600, 940, 401, -499, 988, -501 };
    result = leetCode.maxSubarrayLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2895(void)
{
    Logger::WriteMessage("Test Leet Code 2895");
    LeetCodeSort leetCode;
    vector<int> processorTime = { 8,10 };
    vector<int> tasks = { 2,2,3,1,8,7,4,5 };
    int result = leetCode.minProcessingTime(processorTime, tasks);
    Logger::WriteMessage(processorTime);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));

    processorTime = { 10,20 };
    tasks = { 2,3,1,2,5,8,4,3 };
    result = leetCode.minProcessingTime(processorTime, tasks);
    Logger::WriteMessage(processorTime);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2907(void)
{
    Logger::WriteMessage("Test Leet Code 2907");
    LeetCodeSort leetCode;
    vector<int> prices = { 10, 2, 3, 4 };
    vector<int> profits = { 100, 2, 7, 10 };
    int result = leetCode.maxProfit(prices, profits);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(profits);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 1,2,3,4,5 };
    profits = { 1,5,3,4,6 };
    result = leetCode.maxProfit(prices, profits);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(profits);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 4,3,2,1 };
    profits = { 33,20,19,87 };
    result = leetCode.maxProfit(prices, profits);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(profits);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 2, 8, 9, 9 };
    profits = { 34,20,13,64 };
    result = leetCode.maxProfit(prices, profits);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(profits);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2908(void)
{
    Logger::WriteMessage("Test Leet Code 2908");
    LeetCodeSort leetCode;
    vector<int> nums = { 8, 6, 1, 5, 3 };
    int result = leetCode.minimumSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5,4,8,7,10,2 };
    result = leetCode.minimumSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 6,5,4,3,4,5 };
    result = leetCode.minimumSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2909(void)
{
    Logger::WriteMessage("Test Leet Code 2909");
    LeetCodeSort leetCode;
    vector<int> nums = { 8, 6, 1, 5, 3 };
    int result = leetCode.minimumSumII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5,4,8,7,10,2 };
    result = leetCode.minimumSumII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 6,5,4,3,4,5 };
    result = leetCode.minimumSumII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2921(void)
{
    Logger::WriteMessage("Test Leet Code 2921");
    LeetCodeSort leetCode;
    vector<int> prices = { 10, 2, 3, 4 };
    vector<int> profits = { 100, 2, 7, 10 };
    int result = leetCode.maxProfitII(prices, profits);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(profits);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 1,2,3,4,5 };
    profits = { 1,5,3,4,6 };
    result = leetCode.maxProfitII(prices, profits);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(profits);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 4,3,2,1 };
    profits = { 33,20,19,87 };
    result = leetCode.maxProfitII(prices, profits);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(profits);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 2, 8, 9, 9 };
    profits = { 34,20,13,64 };
    result = leetCode.maxProfitII(prices, profits);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(profits);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2926(void)
{
    Logger::WriteMessage("Test Leet Code 2926");
    LeetCodeSort leetCode;
    vector<int> nums = { 3, 3, 5, 6 };
    long long result = leetCode.maxBalancedSubsequenceSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5,-1,-3,8 };
    result = leetCode.maxBalancedSubsequenceSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -2,-1 };
    result = leetCode.maxBalancedSubsequenceSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -3, -4, -2 };
    result = leetCode.maxBalancedSubsequenceSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2931(void)
{
    Logger::WriteMessage("Test Leet Code 2931");
    LeetCodeSort leetCode;
    vector<vector<int>> values = { {8, 5, 2},{6, 4, 1},{9, 7, 3} };
    long long result = leetCode.maxSpending(values);
    Logger::WriteMessage(values);
    Logger::WriteMessage("result = " + to_string(result));

    values = { {10, 8, 6, 4, 2},{9, 7, 5, 3, 2} };
    result = leetCode.maxSpending(values);
    Logger::WriteMessage(values);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2940(void)
{
    Logger::WriteMessage("Test Leet Code 2940");
    LeetCodeSort leetCode;
    vector<int> heights = { 6, 4, 8, 5, 2, 7 };
    vector<vector<int>> queries = { {0, 1},{0, 3},{2, 4},{3, 4},{2, 2} };
    vector<int> result = leetCode.leftmostBuildingQueries(heights, queries);
    Logger::WriteMessage(heights);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    heights = { 5, 3, 8, 2, 6, 1, 4, 6 };
    queries = { {0, 7},{3, 5},{5, 2},{3, 0},{1, 6} };
    result = leetCode.leftmostBuildingQueries(heights, queries);
    Logger::WriteMessage(heights);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    heights = { 1, 2, 1, 2, 1, 2 };
    queries = { {1, 2} };
    result = leetCode.leftmostBuildingQueries(heights, queries);
    Logger::WriteMessage(heights);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode2948(void)
{
    Logger::WriteMessage("Test Leet Code 2948");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 5, 3, 9, 8 };
    int limit = 2;
    vector<int> result = leetCode.lexicographicallySmallestArray(nums, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("limit = " +  to_string(limit));
    Logger::WriteMessage(result);

    nums = { 1,7,6,18,2,1 };
    limit = 3;
    result = leetCode.lexicographicallySmallestArray(nums, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("limit = " + to_string(limit));
    Logger::WriteMessage(result);

    nums = { 1,7,28,19,10 };
    limit = 3;
    result = leetCode.lexicographicallySmallestArray(nums, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("limit = " + to_string(limit));
    Logger::WriteMessage(result);

    nums = { 4, 52, 38, 59, 71, 27, 31, 83, 88, 10 };
    limit = 14;
    result = leetCode.lexicographicallySmallestArray(nums, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("limit = " + to_string(limit));
    Logger::WriteMessage(result);
}

void TestLeetCode3011(void)
{
    Logger::WriteMessage("Test Leet Code 3011");
    LeetCodeSort leetCode;
    vector<int> nums = { 8,4,2,30,15 };
    bool result = leetCode.canSortArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,2,3,4,5 };
    result = leetCode.canSortArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 3,16,8,4,2 };
    result = leetCode.canSortArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 18, 3, 8 };
    result = leetCode.canSortArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode3013(void)
{
    Logger::WriteMessage("Test Leet Code 3013");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 3, 2, 6, 4, 2 };
    int k = 3, dist = 3;
    long long result = leetCode.minimumCost(nums, k, dist);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; dist = " + to_string(dist));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 10,1,2,2,2,1 };
    k = 4, dist = 3;
    result = leetCode.minimumCost(nums, k, dist);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; dist = " + to_string(dist));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 10,8,18,9 };
    k = 3, dist = 1;
    result = leetCode.minimumCost(nums, k, dist);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; dist = " + to_string(dist));
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode3025(void)
{
    Logger::WriteMessage("Test Leet Code 3025");
    LeetCodeSort leetCode;
    vector<vector<int>> points = { {1, 1},{2, 2},{3, 3} };
    Logger::WriteMessage(points);
    int result = leetCode.numberOfPairsI(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {6, 2},{4, 4},{2, 6} };
    Logger::WriteMessage(points);
    result = leetCode.numberOfPairsI(points);
    Logger::WriteMessage("result = " + to_string(result));
    
    points = { {3, 1},{1, 3},{1, 1} };
    Logger::WriteMessage(points);
    result = leetCode.numberOfPairsI(points);
    Logger::WriteMessage("result = " + to_string(result));
    
    points = { {1, 1},{0, 4},{6, 3},{0, 5} };
    Logger::WriteMessage(points);
    result = leetCode.numberOfPairsI(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3027(void)
{
    Logger::WriteMessage("Test Leet Code 3027");
    LeetCodeSort leetCode;
    vector<vector<int>> points = { {1, 1},{2, 2},{3, 3} };
    Logger::WriteMessage(points);
    int result = leetCode.numberOfPairsII(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {6, 2},{4, 4},{2, 6} };
    Logger::WriteMessage(points);
    result = leetCode.numberOfPairsII(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {3, 1},{1, 3},{1, 1} };
    Logger::WriteMessage(points);
    result = leetCode.numberOfPairsII(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {1, 1},{0, 4},{6, 3},{0, 5} };
    Logger::WriteMessage(points);
    result = leetCode.numberOfPairsII(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3066(void)
{
    Logger::WriteMessage("Test Leet Code 3066");
    LeetCodeSort leetCode;
    vector<int> nums = { 2, 11, 10, 1, 3 };
    int k = 10;
    int result = leetCode.minOperationsII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,1,2,4,9 };
    k = 20;
    result = leetCode.minOperationsII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3073(void)
{
    Logger::WriteMessage("Test Leet Code 3073");
    LeetCodeSort leetCode;
    vector<int> nums = { 5, 6, 9 };
    int result = leetCode.maximumTripletValue(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,5,3,6 };
    result = leetCode.maximumTripletValue(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3074(void)
{
    Logger::WriteMessage("Test Leet Code 3074");
    LeetCodeSort leetCode;
    vector<int> apple = { 1, 3, 2 }, capacity = { 4, 3, 1, 5, 2 };
    int result = leetCode.minimumBoxes(apple, capacity);
    Logger::WriteMessage(apple);
    Logger::WriteMessage(capacity);
    Logger::WriteMessage("result = " + to_string(result));

    apple = { 5,5,5 }, capacity = { 2,4,2,7 };
    result = leetCode.minimumBoxes(apple, capacity);
    Logger::WriteMessage(apple);
    Logger::WriteMessage(capacity);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3075(void)
{
    Logger::WriteMessage("Test Leet Code 3075");
    LeetCodeSort leetCode;
    vector<int> happiness = { 1,2,3 };
    int k = 2;
    long long result = leetCode.maximumHappinessSum(happiness, k);
    Logger::WriteMessage(happiness);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    happiness = { 1,1,1,1 };
    k = 2;
    result = leetCode.maximumHappinessSum(happiness, k);
    Logger::WriteMessage(happiness);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    happiness = { 2,3,4,5 };
    k = 1;
    result = leetCode.maximumHappinessSum(happiness, k);
    Logger::WriteMessage(happiness);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3080(void)
{
    Logger::WriteMessage("Test Leet Code 3080");
    LeetCodeSort leetCode;
    vector<int> nums = { 1,2,2,1,2,3,1 };
    vector<vector<int>> queries = { {1, 2},{3, 3},{4, 2} };
    vector<long long> result = leetCode.unmarkedSumArray(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    nums = { 1,4,2,3 };
    queries = { {0,1} };
    result = leetCode.unmarkedSumArray(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode3224(void)
{
    Logger::WriteMessage("Test Leet Code 3224");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 0, 1, 2, 4, 3 };
    int k = 4;
    int result = leetCode.minChanges(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 0,1,2,3,3,6,5,4 };
    k = 6;
    result = leetCode.minChanges(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3231(void)
{
    Logger::WriteMessage("Test Leet Code 3231");
    LeetCodeSort leetCode;
    vector<int> nums = { 5,3,1,4,2 };
    int result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,5 };
    result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5,4,3,2,1 };
    result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3275(void)
{
    Logger::WriteMessage("Test Leet Code 3275");
    LeetCodeSort leetCode;
    vector<vector<int>> queries = { {1, 2},{3, 4},{2, 3},{-3, 0} };
    int k = 2;
    vector<int> result = leetCode.resultsArray(queries, k);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    queries = { {5, 5},{4, 4},{3, 3} };
    k = 1;
    result = leetCode.resultsArray(queries, k);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode3288(void)
{
    Logger::WriteMessage("Test Leet Code 3288");
    LeetCodeSort leetCode;
    vector<vector<int>> coordinates = { {3, 1},{2, 2},{4, 1},{0, 0},{5, 3} };
    int k = 1;
    int result = leetCode.maxPathLength(coordinates, k);
    Logger::WriteMessage(coordinates);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
    
    coordinates = { {2, 1},{7, 0},{5, 6} };
    k = 1;
    result = leetCode.maxPathLength(coordinates, k);
    Logger::WriteMessage(coordinates);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    coordinates = { {1, 8},{9, 8},{9, 9} };
    k = 1;
    result = leetCode.maxPathLength(coordinates, k);
    Logger::WriteMessage(coordinates);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3296(void)
{
    Logger::WriteMessage("Test Leet Code 3296");
    LeetCodeSort leetCode;
    int mountainHeight = 4;
    vector<int> workerTimes = { 2, 1, 1 };
    long long result = leetCode.minNumberOfSeconds(mountainHeight, workerTimes);
    Logger::WriteMessage(workerTimes);
    Logger::WriteMessage("mountainHeight = " + to_string(mountainHeight) + "; result = " + to_string(result));

    mountainHeight = 10;
    workerTimes = { 3, 2, 2, 4 };
    result = leetCode.minNumberOfSeconds(mountainHeight, workerTimes);
    Logger::WriteMessage(workerTimes);
    Logger::WriteMessage("mountainHeight = " + to_string(mountainHeight) + "; result = " + to_string(result));

    mountainHeight = 5;
    workerTimes = { 1 };
    result = leetCode.minNumberOfSeconds(mountainHeight, workerTimes);
    Logger::WriteMessage(workerTimes);
    Logger::WriteMessage("mountainHeight = " + to_string(mountainHeight) + "; result = " + to_string(result));
}

void TestLeetCode3301(void)
{
    Logger::WriteMessage("Test Leet Code 3301");
    LeetCodeSort leetCode;
    vector<int> maximumHeight = { 2, 3, 4, 3 };
    long long result = leetCode.maximumTotalSum(maximumHeight);
    Logger::WriteMessage(maximumHeight);
    Logger::WriteMessage("result = " + to_string(result));

    maximumHeight = { 15,10 };
    result = leetCode.maximumTotalSum(maximumHeight);
    Logger::WriteMessage(maximumHeight);
    Logger::WriteMessage("result = " + to_string(result));

    maximumHeight = { 2,2,1 };
    result = leetCode.maximumTotalSum(maximumHeight);
    Logger::WriteMessage(maximumHeight);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode3318(void)
{
    Logger::WriteMessage("Test Leet Code 3318");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 1, 2, 2, 3, 4, 2, 3 };
    int k = 6, x = 2;
    vector<int> result = leetCode.findXSumI(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { 3,8,7,8,7,5 };
    k = 2, x = 2;
    result = leetCode.findXSumI(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { 2, 1, 1, 4 };
    k = 2, x = 2;
    result = leetCode.findXSumI(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { 5, 1, 2, 6, 2, 1, 6, 5, 1, 5 };
    k = 4, x = 2;
    result = leetCode.findXSumI(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { 2, 5, 3, 5, 3, 5 };
    k = 4, x = 4;
    result = leetCode.findXSumI(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);
}

void TestLeetCode3321(void)
{
    Logger::WriteMessage("Test Leet Code 3321");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 1, 2, 2, 3, 4, 2, 3 };
    int k = 6, x = 2;
    vector<long long> result = leetCode.findXSumII(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { 3,8,7,8,7,5 };
    k = 2, x = 2;
    result = leetCode.findXSumII(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { 2, 1, 1, 4 };
    k = 2, x = 2;
    result = leetCode.findXSumII(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { 5, 1, 2, 6, 2, 1, 6, 5, 1, 5 };
    k = 4, x = 2;
    result = leetCode.findXSumII(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    nums = { 2, 5, 3, 5, 3, 5 };
    k = 4, x = 4;
    result = leetCode.findXSumII(nums, k, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);
}

void TestLeetCode3375(void)
{
    Logger::WriteMessage("Test Leet Code 3375");
    LeetCodeSort leetCode;
    vector<int> nums = { 5, 2, 5, 4, 5 };
    int k = 2;
    int result = leetCode.minOperationsIII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2,1,2 };
    k = 2;
    result = leetCode.minOperationsIII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 9,7,5,3 };
    k = 1;
    result = leetCode.minOperationsIII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3397(void)
{
    Logger::WriteMessage("Test Leet Code 3397");
    LeetCodeSort leetCode;
    vector<int> nums = { 1, 2, 2, 3, 3, 4 };
    int k = 2;
    int result = leetCode.maxDistinctElements(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 4,4,4,4 };
    k = 1;
    result = leetCode.maxDistinctElements(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCodeSort(void)
{
    TestLeetCode3397();
    TestLeetCode3375();
    TestLeetCode3321();
    TestLeetCode3318();
    TestLeetCode3301();
    TestLeetCode3296();
    TestLeetCode3288();
    TestLeetCode3275();
    TestLeetCode3231();
    TestLeetCode3224();
    TestLeetCode3080();
    TestLeetCode3075();
    TestLeetCode3074();
    TestLeetCode3073();
    TestLeetCode3066();
    TestLeetCode3027();
    TestLeetCode3025();
    TestLeetCode3013();
    TestLeetCode3011();
    TestLeetCode2948();
    TestLeetCode2940();
    TestLeetCode2931();
    TestLeetCode2926();
    TestLeetCode2908();
    TestLeetCode2907();
    TestLeetCode2895();
    TestLeetCode2863();
    TestLeetCode2860();
    TestLeetCode2856();
    TestLeetCode2855();
    TestLeetCode2838();
    TestLeetCode2835();
    TestLeetCode2817();
    TestLeetCode2763();
    TestLeetCode2736();
    TestLeetCode2740();
    TestLeetCode2679();
    TestLeetCode2659();
    TestLeetCode2653();
    TestLeetCode2613();
    TestLeetCode2611();
    TestLeetCode2599();
    TestLeetCode2594();
    TestLeetCode2567();
    TestLeetCode2561();
    TestLeetCode2558();
    TestLeetCode2551();
    TestLeetCode2548();
    TestLeetCode2530();
    TestLeetCode2519();
    TestLeetCode2491();
    TestLeetCode2454();
    TestLeetCode2418();
    TestLeetCode2387();
    TestLeetCode2386();
    TestLeetCode2332();
    TestLeetCode2323();
    TestLeetCode2300();
    TestLeetCode2285();
    TestLeetCode2279();
    TestLeetCode2250();
    TestLeetCode2263();
    TestLeetCode2171();
    TestLeetCode2165();
    TestLeetCode2164();
    TestLeetCode2148();
    TestLeetCode2144();
    TestLeetCode2126();
    TestLeetCode2136();
    TestLeetCode912();
    TestLeetCode977();
    TestLeetCode953();
    TestLeetCode941();
    TestLeetCode798();
    TestLeetCode870();
    TestLeetCode853();
    TestLeetCode775();
    TestLeetCode1046();
    TestLeetCode1090();
    TestLeetCode1086();
    TestLeetCode1099();
    TestLeetCode1169();
    TestLeetCode1133();
    TestLeetCode1122();
    TestLeetCode1167();
    TestLeetCode769();
    TestLeetCode955();
    TestLeetCode954();
    TestLeetCode1182();
    TestLeetCode1199();
    TestLeetCode744();
    TestLeetCode75();
    TestLeetCode164();
    TestLeetCode274();
    TestLeetCode324();
    TestLeetCode376();
    TestLeetCode179();
    TestLeetCode406();
    TestLeetCode220();
    TestLeetCode280();
    TestLeetCode321();
    TestLeetCode440();
    TestLeetCode561();
    TestLeetCode556();
    TestLeetCode555();
    TestLeetCode581();
    TestLeetCode665();
    TestLeetCode480();
    TestLeetCode738();
    TestLeetCode692();
    TestLeetCode1053();
    TestLeetCode1051();
    TestLeetCode1029();
    TestLeetCode962();
    TestLeetCode2070();
    TestLeetCode2111();
    TestLeetCode2098();
    TestLeetCode1968();
    TestLeetCode1966();
    TestLeetCode1996();
    TestLeetCode1962();
    TestLeetCode1942();
    TestLeetCode1985();
    TestLeetCode1921();
    TestLeetCode1984();
    TestLeetCode2037();
    TestLeetCode1964();
    TestLeetCode1882();
    TestLeetCode1887();
    TestLeetCode1881();
    TestLeetCode1877();
    TestLeetCode1913();
    TestLeetCode1909();
    TestLeetCode1889();
    TestLeetCode1851();
    TestLeetCode1847();
    TestLeetCode1846();
    TestLeetCode1834();
    TestLeetCode1833();
    TestLeetCode1801();
    TestLeetCode1775();
    TestLeetCode1752();
    TestLeetCode1710();
    TestLeetCode1705();
    TestLeetCode334();
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
