#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeHashtable.h"
#include "TestHashtable.h"
void TestLeetCode1(void)
{
    Logger::WriteMessage("Test Leet Code 1");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 19, 21, 15, 2, 7, 11, 18, 23, 25 };
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.twoSum(nums, 25);
    Logger::WriteMessage(result);
}

void TestLeetCode15(void)
{
    Logger::WriteMessage("Test Leet Code 15");
    LeetCodeHashtable leetCode;
    vector<int> nums =
    {
        -1, 0, 1, 2, -1, -1, -4
    };
    vector<vector<int>> result;
    result = leetCode.threeSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
    result = leetCode.threeSumII(nums);
    Logger::WriteMessage(result);

    nums = { -1, 0, 1, 2, -1, -4 };
    result = leetCode.threeSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
    result = leetCode.threeSumII(nums);
    Logger::WriteMessage(result);

    nums = { 0, 0, 0, 0 };
    result = leetCode.threeSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
    result = leetCode.threeSumII(nums);
    Logger::WriteMessage(result);

    nums = {};
    result = leetCode.threeSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
    result = leetCode.threeSumII(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode454(void)
{
    Logger::WriteMessage("Test Leet Code 454");
    LeetCodeHashtable leetCode;
    vector<int> A = { 1, 2 };
    vector<int> B = { -2,-1 };
    vector<int> C = { -1, 2 };
    vector<int> D = { 0, 2 };
    int result = leetCode.fourSumCount(A, B, C, D);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(C);
    Logger::WriteMessage(D);
    Logger::WriteMessage("Result = " + to_string(result));
}

void TestLeetCode18(void)
{
    LeetCodeHashtable leetCode;
    Logger::WriteMessage("Test Leet Code 18");
    vector<int> nums = { 1, 0, -1, 0, -2, 2 };
    int target = 0;
    Logger::WriteMessage(nums);
    vector<vector<int>> result = leetCode.fourSum(nums, target);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(result);
    result = leetCode.fourSumII(nums, target);
    Logger::WriteMessage(result);

    nums = { -1, 2, 2, -5, 0, -1, 4 };
    target = 3;
    Logger::WriteMessage(nums);
    result = leetCode.fourSum(nums, target);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(result);
    result = leetCode.fourSumII(nums, target);
    Logger::WriteMessage(result);

    nums =
    {
        -3, -2, -1, 0, 0, 1, 2, 3
    };
    Logger::WriteMessage(nums);
    target = 0;
    Logger::WriteMessage("target = " + to_string(target));
    result = leetCode.fourSum(nums, target);
    Logger::WriteMessage(result);
    result = leetCode.fourSumII(nums, target);
    Logger::WriteMessage(result);


    nums =
    {
        -491, -477, -450, -436, -431, -410, -402, -402, -391, -381, -380, -377, -355, -346, -344,
        -325, -320, -318, -290, -286, -278, -278, -272, -261, -261, -259, -235, -234, -232, -220,
        -212, -206, -201, -196, -191, -186, -173, -164, -158, -133, -120, -98, -91, -87, -82, -73,
        -62, -55, -27, 0, 14, 19, 23, 37, 48, 52, 53, 53, 57, 83, 85, 106, 161, 170, 174, 183, 188,
        191, 197, 211, 212, 222, 231, 243, 250, 274, 284, 302, 313, 319, 332, 338, 356, 358, 369,
        374, 396, 406, 416, 420, 425, 440, 441, 443, 469, 471, 496
    };
    Logger::WriteMessage(nums);
    target = -2402;
    Logger::WriteMessage("target = " + to_string(target));
    result = leetCode.fourSum(nums, target);
    Logger::WriteMessage(result);
    result = leetCode.fourSumII(nums, target);
    Logger::WriteMessage(result);

    nums =
    {
        0, 0, 0, 0
    };
    Logger::WriteMessage(nums);
    target = 0;
    Logger::WriteMessage("target = " + to_string(target));
    result = leetCode.fourSum(nums, target);
    Logger::WriteMessage(result);
    result = leetCode.fourSumII(nums, target);
    Logger::WriteMessage(result);

    nums =
    {
    };
    Logger::WriteMessage(nums);
    target = 0;
    Logger::WriteMessage("target = " + to_string(target));
    result = leetCode.fourSum(nums, target);
    Logger::WriteMessage(result);
    result = leetCode.fourSumII(nums, target);
    Logger::WriteMessage(result);
}

void TestLeetCode1207(void)
{
    Logger::WriteMessage("Test Leet Code 1207");
    LeetCodeHashtable leetCode;
    vector<int> arr = { 1, 2, 2, 1, 1, 3 };
    bool result = leetCode.uniqueOccurrences(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    arr = { 1, 2 };
    result = leetCode.uniqueOccurrences(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    arr = { -3, 0, 1, -3, 1, 1, 1, -3, 10, 0 };
    result = leetCode.uniqueOccurrences(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1218(void)
{
    Logger::WriteMessage("Test Leet Code 1218");
    LeetCodeHashtable leetCode;
    vector<int> arr = { 1,2,3,4 };
    int difference = 1;
    int result = leetCode.longestSubsequence(arr, difference);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("difference = " + to_string(difference) + "; result = " + to_string(result));

    arr = { 1,3,5,7 };
    difference = 1;
    result = leetCode.longestSubsequence(arr, difference);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("difference = " + to_string(difference) + "; result = " + to_string(result));

    arr = { 1,5,7,8,5,3,4,2,1 };
    difference = -2;
    result = leetCode.longestSubsequence(arr, difference);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("difference = " + to_string(difference) + "; result = " + to_string(result));
}

void TestLeetCode1224(void)
{
    Logger::WriteMessage("Test Leet Code 1224");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 2, 2, 1, 1, 5, 3, 3, 5 };
    int result = leetCode.maxEqualFreq(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5 };
    result = leetCode.maxEqualFreq(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
    
    nums = { 1,1,1,2,2,2 };
    result = leetCode.maxEqualFreq(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 10,2,8,9,3,8,1,5,2,3,7,6 };
    result = leetCode.maxEqualFreq(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1257(void)
{
    Logger::WriteMessage("Test Leet Code 1257");
    LeetCodeHashtable leetCode;
    vector<vector<string>> regions =
    {
        {"Earth", "North America", "South America"},
        {"North America","United States","Canada"},
        {"United States","New York","Boston"},
        {"Canada","Ontario","Quebec"},
        {"South America","Brazil"}
    };
    string region1 = "Quebec";
    string region2 = "New York";
    string result = leetCode.findSmallestRegion(regions, region1, region2);
    Logger::WriteMessage(regions);
    Logger::WriteMessage("region1 = " + region1 + "; region2 = " + region2 + "; result = " + result);

    region1 = "Quebec";
    region2 = "Canada";
    result = leetCode.findSmallestRegion(regions, region1, region2);
    Logger::WriteMessage(regions);
    Logger::WriteMessage("region1 = " + region1 + "; region2 = " + region2 + "; result = " + result);

    region1 = "Earth";
    region2 = "New York";
    result = leetCode.findSmallestRegion(regions, region1, region2);
    Logger::WriteMessage(regions);
    Logger::WriteMessage("region1 = " + region1 + "; region2 = " + region2 + "; result = " + result);
}

void TestLeetCode1386(void)
{
    Logger::WriteMessage("Test Leet Code 1386");
    LeetCodeHashtable leetCode;
    int n = 3;
    vector<vector<int>> reservedSeats =
    {
        {1, 2},{1, 3},{1, 8},{2, 6},{3, 1},{3, 10}
    };
    int result = leetCode.maxNumberOfFamilies(n, reservedSeats);
    Logger::WriteMessage(reservedSeats);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    reservedSeats =
    {
        {2,1},{1,8},{2,6}
    };
    result = leetCode.maxNumberOfFamilies(n, reservedSeats);
    Logger::WriteMessage(reservedSeats);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    reservedSeats =
    {
        {4,3},{1,4},{4,6},{1,7}
    };
    result = leetCode.maxNumberOfFamilies(n, reservedSeats);
    Logger::WriteMessage(reservedSeats);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    reservedSeats =
    {
        {1, 2},{1, 3},{1, 8},{2, 6},{3, 2}
    };
    result = leetCode.maxNumberOfFamilies(n, reservedSeats);
    Logger::WriteMessage(reservedSeats);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1394(void)
{
    Logger::WriteMessage("Test Leet Code 1394");
    LeetCodeHashtable leetCode;
    vector<int> arr = { 2, 2, 3, 4 };
    int result = leetCode.findLucky(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,2,2,3,3,3 };
    result = leetCode.findLucky(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 2,2,2,3,3 };
    result = leetCode.findLucky(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 5 };
    result = leetCode.findLucky(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 7,7,7,7,7,7,7 };
    result = leetCode.findLucky(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1418(void)
{
    Logger::WriteMessage("Test Leet Code 1418");
    LeetCodeHashtable leetCode;
    vector<vector<string>> orders =
    {
        {"David", "3", "Ceviche"},
        {"Corina", "10", "Beef Burrito"},
        {"David", "3", "Fried Chicken"},
        {"Carla", "5", "Water"},
        {"Carla", "5", "Ceviche"},
        {"Rous", "3", "Ceviche"}
    };
    vector<vector<string>> result = leetCode.displayTable(orders);
    Logger::WriteMessage(orders);
    Logger::WriteMessage(result);

    orders =
    {
        {"James", "12", "Fried Chicken"},
        {"Ratesh", "12", "Fried Chicken"},
        {"Amadeus", "12", "Fried Chicken"},
        {"Adam", "1", "Canadian Waffles"},
        {"Brianna", "1", "Canadian Waffles"}
    };
    result = leetCode.displayTable(orders);
    Logger::WriteMessage(orders);
    Logger::WriteMessage(result);

    orders =
    {
        {"Laura","2","Bean Burrito"},
        {"Jhon","2","Beef Burrito"},
        {"Melissa","2","Soda"}
    };
    result = leetCode.displayTable(orders);
    Logger::WriteMessage(orders);
    Logger::WriteMessage(result);
}

void TestLeetCode1426(void)
{
    Logger::WriteMessage("Test Leet Code 1426");
    LeetCodeHashtable leetCode;
    vector<int> arr = { 1,2,3 };
    int result = leetCode.countElements(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,1,3,3,5,5,7,7 };
    result = leetCode.countElements(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,3,2,3,5,0 };
    result = leetCode.countElements(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,1,2,2 };
    result = leetCode.countElements(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,1,2 };
    result = leetCode.countElements(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1452(void)
{
    Logger::WriteMessage("Test Leet Code 1452");
    LeetCodeHashtable leetCode;
    vector<vector<string>> favoriteCompanies =
    {
        {"leetcode", "google", "facebook"},
        {"google","microsoft"},
        {"google","facebook"},
        {"google"},
        {"amazon"}
    };
    vector<int> result = leetCode.peopleIndexes(favoriteCompanies);
    Logger::WriteMessage(favoriteCompanies);
    Logger::WriteMessage(result);

    favoriteCompanies =
    {
        {"leetcode","google","facebook"},
        {"leetcode","amazon"},
        {"facebook","google"}
    };
    result = leetCode.peopleIndexes(favoriteCompanies);
    Logger::WriteMessage(favoriteCompanies);
    Logger::WriteMessage(result);

    favoriteCompanies =
    {
        {"leetcode"},
        {"google"},
        {"facebook"},
        {"amazon"},
    };
    result = leetCode.peopleIndexes(favoriteCompanies);
    Logger::WriteMessage(favoriteCompanies);
    Logger::WriteMessage(result);
}

void TestLeetCode1481(void)
{
    Logger::WriteMessage("Test Leet Code 1481");
    LeetCodeHashtable leetCode;
    vector<int> arr = { 5, 5, 4 };
    int k = 1;
    int result = leetCode.findLeastNumOfUniqueInts(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = 1 " + to_string(k) + "; result = " + to_string(result));

    arr = { 4,3,1,1,3,3,2 };
    k = 3;
    result = leetCode.findLeastNumOfUniqueInts(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = 1 " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCodeHashtable(void)
{
    TestLeetCode1481();
    TestLeetCode1452();
    TestLeetCode1426();
    TestLeetCode1418();
    TestLeetCode1394();
    TestLeetCode1386();
    TestLeetCode170();
    TestLeetCode1257();
    TestLeetCode1224();
    TestLeetCode1218();
    TestLeetCode1();
    TestLeetCode15();
    TestLeetCode18();
    TestLeetCode454();
    TestLeetCode1207();
}