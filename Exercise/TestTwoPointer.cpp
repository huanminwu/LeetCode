#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeTwoPointer.h"
#include "TestTwoPointer.h"
void TestLeetCode881(void)
{
    Logger::WriteMessage("Test Leet Code 881");
    LeetCodeTwoPointer leetCode;
    vector<int> people = { 1, 2 };
    int limit = 3;
    int result = leetCode.numRescueBoats(people, limit);
    Logger::WriteMessage(people);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    people = { 3,2,2,1 };
    limit = 3;
    result = leetCode.numRescueBoats(people, limit);
    Logger::WriteMessage(people);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    people = { 3,5,3,4 };
    limit = 5;
    result = leetCode.numRescueBoats(people, limit);
    Logger::WriteMessage(people);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));
}

void TestLeetCode1852(void)
{
    Logger::WriteMessage("Test Leet Code 1852");
    LeetCodeTwoPointer leetCode;
    vector<int> nums = { 1,2,3,2,2,1,3 };
    int k = 3;
    vector<int> result = leetCode.distinctNumbers(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    nums = { 1,1,1,1,2,3,4 };
    k = 4;
    result = leetCode.distinctNumbers(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode2062(void)
{
    Logger::WriteMessage("Test Leet Code 2062");
    LeetCodeTwoPointer leetCode;
    string word = "aeiouu";
    int result = leetCode.countVowelSubstrings(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "unicornarihan";
    result = leetCode.countVowelSubstrings(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "cuaieuouac";
    result = leetCode.countVowelSubstrings(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));
}

void TestLeetCode2106(void)
{
    Logger::WriteMessage("Test Leet Code 2106");
    LeetCodeTwoPointer leetCode;
    vector<vector<int>> fruits = { {2, 8},{6, 3},{8, 6} };
    int startPos = 5;
    int k = 4;
    int result = leetCode.maxTotalFruits(fruits, startPos, k);
    Logger::WriteMessage("startPos = " + to_string(startPos) + "; k = " + to_string(k) + "; result = " + to_string(result));

    fruits = { {0, 9},{4, 1},{5, 7},{6, 2},{7, 4},{10, 9} };
    startPos = 5;
    k = 4;
    result = leetCode.maxTotalFruits(fruits, startPos, k);
    Logger::WriteMessage("startPos = " + to_string(startPos) + "; k = " + to_string(k) + "; result = " + to_string(result));

    fruits = { {0, 3},{6, 4},{8, 5}};
    startPos = 3;
    k = 2;
    result = leetCode.maxTotalFruits(fruits, startPos, k);
    Logger::WriteMessage("startPos = " + to_string(startPos) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2107(void)
{
    Logger::WriteMessage("Test Leet Code 2107");
    LeetCodeTwoPointer leetCode;
    vector<int> candies = { 1, 2, 2, 3, 4, 3 };
    int k = 3;
    int result = leetCode.shareCandies(candies, k);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    candies = { 2,2,2,2,3,3 };
    k = 2;
    result = leetCode.shareCandies(candies, k);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    candies = { 2,4,5 };
    k = 0;
    result = leetCode.shareCandies(candies, k);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    candies = { 2,4,5 };
    k = 3;
    result = leetCode.shareCandies(candies, k);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2105(void)
{
    Logger::WriteMessage("Test Leet Code 2105");
    LeetCodeTwoPointer leetCode;
    vector<int> plants = { 2, 2, 3, 3 };
    int capacityA = 5;
    int capacityB = 5;
    int result = leetCode.minimumRefill(plants, capacityA, capacityB);
    Logger::WriteMessage(plants);
    Logger::WriteMessage("capacityA = " + to_string(capacityA) + "; capacityB = " + to_string(capacityB) + 
        "; result = " + to_string(result));

    plants = { 2, 2, 3, 3 };
    capacityA = 3;
    capacityB = 4;
    result = leetCode.minimumRefill(plants, capacityA, capacityB);
    Logger::WriteMessage(plants);
    Logger::WriteMessage("capacityA = " + to_string(capacityA) + "; capacityB = " + to_string(capacityB) +
        "; result = " + to_string(result));

    plants = { 5 };
    capacityA = 10;
    capacityB = 8;
    result = leetCode.minimumRefill(plants, capacityA, capacityB);
    Logger::WriteMessage(plants);
    Logger::WriteMessage("capacityA = " + to_string(capacityA) + "; capacityB = " + to_string(capacityB) +
        "; result = " + to_string(result));
}

void TestLeetCode2302(void)
{
    Logger::WriteMessage("Test Leet Code 2302");
    LeetCodeTwoPointer leetCode;
    vector<int> nums = { 2, 1, 4, 3, 5 };
    long long k = 10;
    long long result = leetCode.countSubarrays(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,1,1 };
    k = 5;
    result = leetCode.countSubarrays(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2327(void)
{
    Logger::WriteMessage("Test Leet Code 2327");
    LeetCodeTwoPointer leetCode;
    int n = 6, delay = 2, forget = 4;
    int result = leetCode.peopleAwareOfSecret(n, delay, forget);
    Logger::WriteMessage("n = " + to_string(n) + "; delay = " + to_string(delay) +
        "; forget = " + to_string(forget) + "; result = " + to_string(result));

    n = 4, delay = 1, forget = 3;
    result = leetCode.peopleAwareOfSecret(n, delay, forget);
    Logger::WriteMessage("n = " + to_string(n) + "; delay = " + to_string(delay) +
        "; forget = " + to_string(forget) + "; result = " + to_string(result));
}

void TestLeetCode2330(void)
{
    Logger::WriteMessage("Test Leet Code 2330");
    LeetCodeTwoPointer leetCode;
    string s = "abcdba";
    bool result = leetCode.makePalindrome(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "aa";
    result = leetCode.makePalindrome(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "abcdef";
    result = leetCode.makePalindrome(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2379(void)
{
    Logger::WriteMessage("Test Leet Code 2330");
    LeetCodeTwoPointer leetCode;
    string blocks = "WBBWWBBWBW";
    int k = 7;
    int result = leetCode.minimumRecolors(blocks, k);
    Logger::WriteMessage("blocks = " + blocks + "; result = " + to_string(result));

    blocks = "WBWBBBW";
    k = 2;
    result = leetCode.minimumRecolors(blocks, k);
    Logger::WriteMessage("blocks = " + blocks + "; result = " + to_string(result));
}

void TestLeetCode2422(void)
{
    Logger::WriteMessage("Test Leet Code 2422");
    LeetCodeTwoPointer leetCode;
    vector<int>nums = { 4, 3, 2, 1, 2, 3, 1 };
    int result = leetCode.minimumOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4 };
    result = leetCode.minimumOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2461(void)
{
    Logger::WriteMessage("Test Leet Code 2461");
    LeetCodeTwoPointer leetCode;
    vector<int>nums = { 1,5,4,2,9,9,9 };
    int k = 3;
    long long result = leetCode.maximumSubarraySum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 4,4,4 };
    k = 3;
    result = leetCode.maximumSubarraySum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2462(void)
{
    Logger::WriteMessage("Test Leet Code 2462");
    LeetCodeTwoPointer leetCode;
    vector<int> costs = { 17, 12, 10, 2, 7, 2, 11, 20, 8 };
    int k = 3;
    int candidates = 4;
    long long result = leetCode.totalCost(costs, k, candidates);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("k = " + to_string(k) + "; candidates = " + to_string(candidates) + "; result = " + to_string(result));

    costs = { 1,2,4,1 };
    k = 3;
    candidates = 3;
    result = leetCode.totalCost(costs, k, candidates);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("k = " + to_string(k) + "; candidates = " + to_string(candidates) + "; result = " + to_string(result));

    costs = { 31, 25, 72, 79, 74, 65, 84, 91, 18, 59, 27, 9, 81, 33, 17, 58 };
    k = 11;
    candidates = 2;
    result = leetCode.totalCost(costs, k, candidates);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("k = " + to_string(k) + "; candidates = " + to_string(candidates) + "; result = " + to_string(result));
}

void TestLeetCode2448(void)
{
    Logger::WriteMessage("Test Leet Code 2448");
    LeetCodeTwoPointer leetCode;
    vector<int> nums = { 1, 3, 5, 2 };
    vector<int> cost = { 2, 3, 1, 14 };
    long long result = leetCode.minCost(nums, cost);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,2,2,2 };
    cost = { 4,2,8,1,3 };
    result = leetCode.minCost(nums, cost);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));
    
    nums = { 387, 341, 26 };
    cost = { 12, 3, 2 };
    result = leetCode.minCost(nums, cost);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2537(void)
{
    Logger::WriteMessage("Test Leet Code 2537");
    LeetCodeTwoPointer leetCode;
    vector<int> nums = { 1, 1, 1, 1, 1 };
    int k = 10;
    long long result = leetCode.countGood(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 3,1,4,3,2,2,4 };
    k = 2;
    result = leetCode.countGood(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2576(void)
{
    Logger::WriteMessage("Test Leet Code 2576");
    LeetCodeTwoPointer leetCode;
    vector<int> nums = { 3, 5, 2, 4 };
    int result = leetCode.maxNumOfMarkedIndices(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 9,2,5,4 };
    result = leetCode.maxNumOfMarkedIndices(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 7,6,8 };
    result = leetCode.maxNumOfMarkedIndices(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2555(void)
{
    Logger::WriteMessage("Test Leet Code 2555");
    LeetCodeTwoPointer leetCode;
    vector<int> prizePositions = { 1, 1, 2, 2, 3, 3, 5 };
    int k = 2;
    int result = leetCode.maximizeWin(prizePositions, 2);
    Logger::WriteMessage(prizePositions);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    prizePositions = { 1,2,3,4 };
    k = 0;
    result = leetCode.maximizeWin(prizePositions, 0);
    Logger::WriteMessage(prizePositions);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2743(void)
{
    Logger::WriteMessage("Test Leet Code 2743");
    LeetCodeTwoPointer leetCode;
    string s = "abcd";
    int result = leetCode.numberOfSpecialSubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "ooo";
    result = leetCode.numberOfSpecialSubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "abab";
    result = leetCode.numberOfSpecialSubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode2762(void)
{
    Logger::WriteMessage("Test Leet Code 2762");
    LeetCodeTwoPointer leetCode;
    vector<int> nums = { 5, 4, 2, 4 };
    long long result = leetCode.continuousSubarrays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3 };
    result = leetCode.continuousSubarrays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2779(void)
{
    Logger::WriteMessage("Test Leet Code 2779");
    LeetCodeTwoPointer leetCode;
    vector<int> nums = { 4, 6, 1, 2 };
    int k = 2;
    int result = leetCode.maximumBeauty(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,1,1 };
    k = 10;
    result = leetCode.maximumBeauty(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCodeTwoPointer(void)
{
    TestLeetCode2779();
    TestLeetCode2762();
    TestLeetCode2743();
    TestLeetCode2555();
    TestLeetCode2576();
    TestLeetCode2537();
    TestLeetCode2448();
    TestLeetCode2462();
    TestLeetCode2461();
    TestLeetCode2422();
    TestLeetCode2379();
    TestLeetCode2330();
    TestLeetCode2327();
    TestLeetCode2302();
    TestLeetCode2105();
    TestLeetCode2107();
    TestLeetCode2106();
    TestLeetCode2062();
    TestLeetCode1852();
    TestLeetCode881();
}