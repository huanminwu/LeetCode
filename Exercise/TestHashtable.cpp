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

void TestLeetCode217(void)
{
    Logger::WriteMessage("Test Leet Code 217");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5, 3 };
    Logger::WriteMessage(nums);
    bool containsDuplicate = leetCode.containsDuplicate(nums);
    Logger::WriteMessage("The list " + string(containsDuplicate ? "contains " : "does not contain ") + "duplicates.");

    nums = { 1, 2, 2, 3, 4, 4, 3 };
    Logger::WriteMessage(nums);
    containsDuplicate = leetCode.containsDuplicate(nums);
    Logger::WriteMessage("The list " + string(containsDuplicate ? "contains " : "does not contain ") + "duplicates.");
}

void TestLeetCode575(void)
{
    LeetCodeHashtable leetCode;
    vector<int> candies = { 1, 1, 2, 2, 3, 3 };
    int result = leetCode.distributeCandies(candies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("result = " + to_string(result));

    candies = { 1, 1, 2, 3 };
    result = leetCode.distributeCandies(candies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode734(void)
{
    LeetCodeHashtable leetCode;
    vector<string> word1 = { "great", "acting", "skills" };
    vector<string> word2 = { "fine", "drama", "talent" };
    vector<pair<string, string>> pairs = { { "great", "fine" }, { "acting","drama" }, { "skills","talent" } };
    bool result = leetCode.areSentencesSimilar(word1, word2, pairs);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage((string)(result ? "similar" : "not similar"));

    word1 = { "great" };
    word2 = { "great" };
    pairs = { };
    result = leetCode.areSentencesSimilar(word1, word2, pairs);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage((string)(result ? "similar" : "not similar"));
}

void TestLeetCode760(void)
{
    Logger::WriteMessage("Test Leet Code 760");
    LeetCodeHashtable leetCode;
    vector<int> A = { 12, 28, 46, 32, 50 };
    vector<int> B = { 50, 12, 32, 46, 28 };
    vector<int> result = leetCode.anagramMappings(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
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
        {"facebook","microsoft" },
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

void TestLeetCode1487(void)
{
    Logger::WriteMessage("Test Leet Code 1487");
    LeetCodeHashtable leetCode;
    vector<string> names = { "pes", "fifa", "gta", "pes(2019)" };
    vector<string> result = leetCode.getFolderNames(names);
    Logger::WriteMessage(names);
    Logger::WriteMessage(result);

    names = { "gta","gta(1)","gta","avalon" };
    result = leetCode.getFolderNames(names);
    Logger::WriteMessage(names);
    Logger::WriteMessage(result);

    names = { "onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece" };
    result = leetCode.getFolderNames(names);
    Logger::WriteMessage(names);
    Logger::WriteMessage(result);

    names = { "wano","wano","wano","wano" };
    result = leetCode.getFolderNames(names);
    Logger::WriteMessage(names);
    Logger::WriteMessage(result);

    names = { "kaido","kaido(1)","kaido","kaido(1)" };
    result = leetCode.getFolderNames(names);
    Logger::WriteMessage(names);
    Logger::WriteMessage(result);
}

void TestLeetCode1496(void)
{
    Logger::WriteMessage("Test Leet Code 1496");
    LeetCodeHashtable leetCode;
    string path = "NES";
    bool result = leetCode.isPathCrossing(path);
    Logger::WriteMessage("path = " + path + "; result = " + (result ? "true" : "false"));

    path = "NESWW";
    result = leetCode.isPathCrossing(path);
    Logger::WriteMessage("path = " + path + "; result = " + (result ? "true" : "false"));

}

void TestLeetCode532(void)
{
    Logger::WriteMessage("Test Leet Code 532");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 3, 1, 4, 1, 5 };
    int k = 2;
    int result = leetCode.findPairs(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1, 2, 3, 4, 5 };
    k = 1;
    result = leetCode.findPairs(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1, 3, 1, 5, 4 };
    k = 0;
    result = leetCode.findPairs(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1, 1, 1, 1, 1 };
    k = 0;
    result = leetCode.findPairs(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode916(void)
{
    Logger::WriteMessage("Test Leet Code 916");
    LeetCodeHashtable leetCode;
    vector<string> A = { "amazon","apple","facebook","google","leetcode" };
    vector<string> B = { "e","o" };
    vector<string> result = leetCode.wordSubsets(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { "amazon","apple","facebook","google","leetcode" };
    B = { "l","e" };
    result = leetCode.wordSubsets(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { "amazon","apple","facebook","google","leetcode" };
    B = { "e","oo" };
    result = leetCode.wordSubsets(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { "amazon","apple","facebook","google","leetcode" };
    B = { "lo","eo" };
    result = leetCode.wordSubsets(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { "amazon","apple","facebook","google","leetcode" };
    B = { "ec","oc","ceo" };
    result = leetCode.wordSubsets(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);
}

void TestLeetCode884(void)
{
    Logger::WriteMessage("Test Leet Code 884");
    LeetCodeHashtable leetCode;
    string A = "this apple is sweet";
    string B = "this apple is sour";
    vector<string> result = leetCode.uncommonFromSentences(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B);
    Logger::WriteMessage(result);

    A = "apple apple";
    B = "banana";
    result = leetCode.uncommonFromSentences(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B);
    Logger::WriteMessage(result);
}

void TestLeetCode202(void)
{
    Logger::WriteMessage("Test Leet Code 202");
    LeetCodeHashtable leetCode;
    int n;
    bool isHappyNumber;
    n = 19;
    isHappyNumber = leetCode.isHappy(n);
    Logger::WriteMessage("The number " + to_string(n) + " is " + (isHappyNumber ? "" : "not") + " a happy number.");
    n = 25;
    isHappyNumber = leetCode.isHappy(n);
    Logger::WriteMessage("The number " + to_string(n) + " is " + (isHappyNumber ? "" : "not") + " a happy number.");
}

void TestLeetCode594(void)
{
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    int max_length = leetCode.findLHS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Longest_Harmonious_Subsequence = " + to_string(max_length));
}

void TestLeetCode205(void)
{
    Logger::WriteMessage("Test Leet Code 205");
    LeetCodeHashtable leetCode;
    string s = "egg";
    string t = "add";
    bool result = leetCode.isIsomorphic(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + (string)(result ? "true" : "false"));

    s = "foo";
    t = "bar";
    result = leetCode.isIsomorphic(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + (string)(result ? "true" : "false"));

    s = "paper"; 
    t = "title";
    result = leetCode.isIsomorphic(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + (string)(result ? "true" : "false"));

    s = "ab";
    t = "aa";
    result = leetCode.isIsomorphic(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode219(void)
{
    Logger::WriteMessage("Test Leet Code 219");
    LeetCodeHashtable leetCode;
    vector<int> nums;
    int k = 2;
    bool result;
    nums = { 1, 2, 3, 2, 1 };
    result = leetCode.containsNearbyDuplicate(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The array " + string(result ? "contains" : "does not contain") + " duplicates within " + to_string(k));
}

void TestLeetCode890(void)
{
    Logger::WriteMessage("Test Leet Code 890");
    LeetCodeHashtable leetCode;
    vector<string> words = { "abc","deq","mee","aqq","dkd","ccc" };
    string pattern = "abb";
    vector<string> result = leetCode.findAndReplacePattern(words, pattern);
    Logger::WriteMessage(words);
    Logger::WriteMessage(pattern);
    Logger::WriteMessage(result);
}

void TestLeetCode506(void)
{
    Logger::WriteMessage("Test Leet Code 506");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 5,3,4,2,1 };
    vector<string> ranks = leetCode.findRelativeRanks(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(ranks);
}

void TestLeetCode599(void)
{
    LeetCodeHashtable leetCode;
    vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    vector<string> list2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Steakhouse", "Shogun" };
    vector<string> result = leetCode.findRestaurant(list1, list2);
    Logger::WriteMessage(list1);
    Logger::WriteMessage(list2);
    Logger::WriteMessage(result);

    list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    list2 = { "KFC", "Shogun", "Burger King" };
    result = leetCode.findRestaurant(list1, list2);
    Logger::WriteMessage(list1);
    Logger::WriteMessage(list2);
    Logger::WriteMessage(result);
}

void TestLeetCode500(void)
{
    Logger::WriteMessage("Test Leet Code 500");
    LeetCodeHashtable leetCode;
    vector<string> words = { "Hello", "Alaska", "Dad", "Peace" };
    vector<string> result = leetCode.findWordsInOneRow(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCode166(void)
{
    Logger::WriteMessage("Test Leet Code 166");
    LeetCodeHashtable leetCode;
    int numerator, denominator;
    string result;
    numerator = -1;
    denominator = INT_MIN;
    result = leetCode.fractionToDecimal(numerator, denominator);
    Logger::WriteMessage(to_string(numerator) + "/" + to_string(denominator) + "=" + result);

    numerator = 4;
    denominator = 7;
    result = leetCode.fractionToDecimal(numerator, denominator);
    Logger::WriteMessage(to_string(numerator) + "/" + to_string(denominator) + "=" + result);
}

void TestLeetCode451(void)
{
    Logger::WriteMessage("Test Leet Code 451");
    LeetCodeHashtable leetCode;
    string s = "tree";
    string result = leetCode.frequencySort(s);
    Logger::WriteMessage("s=" + s + " ; result=" + result);
    s = "cccaaa";
    result = leetCode.frequencySort(s);
    Logger::WriteMessage("s=" + s + " ; result=" + result);
    s = "Aabb";
    result = leetCode.frequencySort(s);
    Logger::WriteMessage("s=" + s + " ; result=" + result);
}

void TestLeetCode299(void)
{
    Logger::WriteMessage("Test Leet Code 299");
    LeetCodeHashtable leetCode;
    string secret, guess, result;
    secret = "1807";
    guess = "7810";
    result = leetCode.getHint(secret, guess);
    Logger::WriteMessage("secret = " + secret + ", guess = " + guess + "; result = " + result);
    secret = "1123";
    guess = "0111";
    result = leetCode.getHint(secret, guess);
    Logger::WriteMessage("secret = " + secret + ", guess = " + guess + "; result = " + result);
}

void TestLeetCode349(void)
{
    Logger::WriteMessage("Test Leet Code 349");
    LeetCodeHashtable leetCode;
    vector<int> nums1, nums2, result;
    nums1 = { 1, 2, 2, 1 };
    nums2 = { 2, 2 };
    result = leetCode.intersectionArray(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);
}

void TestLeetCode350(void)
{
    Logger::WriteMessage("Test Leet Code 350");
    LeetCodeHashtable leetCode;
    vector<int> nums1, nums2, result;
    nums1 = { 1, 2, 2, 1 };
    nums2 = { 2, 2 };
    result = leetCode.intersectionArrayII(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);
}

void TestLeetCode1041(void)
{
    Logger::WriteMessage("Test Leet Code 1041");
    LeetCodeHashtable leetCode;
    string instructions = "GGLLGG";
    bool result = leetCode.isRobotBounded(instructions);
    Logger::WriteMessage("instruction = " + instructions + "; result = " + (string)(result ? "true" : "false"));

    instructions = "GG";
    result = leetCode.isRobotBounded(instructions);
    Logger::WriteMessage("instruction = " + instructions + "; result = " + (string)(result ? "true" : "false"));

    instructions = "GL";
    result = leetCode.isRobotBounded(instructions);
    Logger::WriteMessage("instruction = " + instructions + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode128(void)
{
    Logger::WriteMessage("Test Leet Code 128");
    LeetCodeHashtable leetCode;
    vector<int> nums;
    int longestConsecutive;
    nums = { 100, 4, 200, 1, 3, 2 };
    Logger::WriteMessage(nums);
    longestConsecutive = leetCode.longestConsecutive(nums);
    Logger::WriteMessage("The longest consecutive is " + to_string(longestConsecutive));
}

void TestLeetCode1152(void)
{
    Logger::WriteMessage("Test Leet Code 1152");
    LeetCodeHashtable leetCode;
    vector<string> username = { "joe","joe","joe","james","james","james", "james","mary","mary","mary" };
    vector<int> timestamp = { 1,2,3,4,5,6,7,8,9,10 };
    vector<string> website = { "home", "about", "career", "home", "cart", "maps", "home", "home", "about","career" };
    vector<string> result = leetCode.mostVisitedPattern(username, timestamp, website);
    Logger::WriteMessage(username);
    Logger::WriteMessage(timestamp);
    Logger::WriteMessage(website);
    Logger::WriteMessage(result);

    username = { "zkiikgv", "zkiikgv", "zkiikgv", "zkiikgv" };
    timestamp = { 436363475, 710406388, 386655081, 797150921 };
    website = { "wnaaxbfhxp", "mryxsjc", "oz", "wlarkzzqht" };
    result = leetCode.mostVisitedPattern(username, timestamp, website);
    Logger::WriteMessage(username);
    Logger::WriteMessage(timestamp);
    Logger::WriteMessage(website);
    Logger::WriteMessage(result);

    username = { "h", "eiy", "cq", "h", "cq", "txldsscx", "cq", "txldsscx", "h", "cq", "cq" };
    timestamp = { 527896567, 334462937, 517687281, 134127993, 859112386, 159548699, 51100299, 444082139, 926837079, 317455832, 411747930 };
    website = { "hibympufi", "hibympufi", "hibympufi", "hibympufi", "hibympufi", "hibympufi", "hibympufi", "hibympufi", "yljmntrclw", "hibympufi", "yljmntrclw" };
    result = leetCode.mostVisitedPattern(username, timestamp, website);
    Logger::WriteMessage(username);
    Logger::WriteMessage(timestamp);
    Logger::WriteMessage(website);
    Logger::WriteMessage(result);
}

void TestLeetCode1128(void)
{
    Logger::WriteMessage("Test Leet Code 1128");
    LeetCodeHashtable leetCode;
    vector<vector<int>> dominoes = { {1, 2},{2, 1},{3, 4},{5, 6} };
    int result = leetCode.numEquivDominoPairs(dominoes);
    Logger::WriteMessage(dominoes);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode792(void)
{
    Logger::WriteMessage("Test Leet Code 792");
    LeetCodeHashtable leetCode;
    string S = "abcde";
    vector<string> words = { "a", "bb", "acd", "ace" };
    int result = leetCode.numMatchingSubseq(S, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode1010(void)
{
    Logger::WriteMessage("Test Leet Code 1010");
    LeetCodeHashtable leetCode;
    vector<int> time = { 30,20,150,100,40 };
    int result = leetCode.numPairsDivisibleBy60(time);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));

    time = { 60,60,60 };
    result = leetCode.numPairsDivisibleBy60(time);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode957(void)
{
    Logger::WriteMessage("Test Leet Code 957");
    LeetCodeHashtable leetCode;
    vector<int> cells = { 0, 1, 0, 1, 1, 0, 0, 1 };
    int N = 7;
    vector<int> result = leetCode.prisonAfterNDays(cells, N);
    Logger::WriteMessage(cells);
    Logger::WriteMessage(result);

    cells = { 1,0,0,1,0,0,1,0 };
    N = 1000000000;
    result = leetCode.prisonAfterNDays(cells, N);
    Logger::WriteMessage(cells);
    Logger::WriteMessage(result);

    cells = { 0,0,1,0,0,1,0,0 };
    N = 44640906;
    result = leetCode.prisonAfterNDays(cells, N);
    Logger::WriteMessage(cells);
    Logger::WriteMessage(result);
}

void TestLeetCode748(void)
{
    Logger::WriteMessage("Test Leet Code 748");
    LeetCodeHashtable leetCode;
    string licensePlate = "1s3 PSt";
    vector<string> words = { "step", "steps", "stripe", "stepple" };
    string result = leetCode.shortestCompletingWord(licensePlate, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("licensePlate = " + licensePlate + "; result = " + result);

    licensePlate = "1s3 456";
    words = { "looks", "pest", "stew", "show" };
    result = leetCode.shortestCompletingWord(licensePlate, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("licensePlate = " + licensePlate + "; result = " + result);
}

void TestLeetCode347(void)
{
    Logger::WriteMessage("Test Leet Code 347");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1,1,1,2,2,3 };
    int k = 2;
    vector<int> result = leetCode.topKFrequent(nums, k);
    Logger::WriteMessage(nums);

    Logger::WriteMessage("Top K frequent items");
    Logger::WriteMessage(result);
}

void TestLeetCode811(void)
{
    Logger::WriteMessage("Test Leet Code 811");
    LeetCodeHashtable leetCode;

    vector<string> cpdomains = { "9001 discuss.leetcode.com" };
    vector<string> result = leetCode.subdomainVisits(cpdomains);

    Logger::WriteMessage(cpdomains);
    Logger::WriteMessage(result);

    cpdomains = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
    result = leetCode.subdomainVisits(cpdomains);

    Logger::WriteMessage(cpdomains);
    Logger::WriteMessage(result);
}

void TestLeetCode1512(void)
{
    Logger::WriteMessage("Test Leet Code 1512");
    LeetCodeHashtable leetCode;
    
    vector<int> nums = { 1, 2, 3, 1, 1, 3 };
    int result = leetCode.numIdenticalPairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,1,1 };
    result = leetCode.numIdenticalPairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3 };
    result = leetCode.numIdenticalPairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1577(void)
{
    Logger::WriteMessage("Test Leet Code 1577");
    LeetCodeHashtable leetCode;

    vector<int> nums1 = { 7, 4 };
    vector<int> nums2 = { 5, 2, 8, 9 };
    int result = leetCode.numTriplets(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1,1 };
    nums2 = { 1,1,1 };
    result = leetCode.numTriplets(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 7,7,8,3 };
    nums2 = { 1,2,9,7 };
    result = leetCode.numTriplets(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 4,7,9,11,23 };
    nums2 = { 3,5,1024,12,18 };
    result = leetCode.numTriplets(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1604(void)
{
    Logger::WriteMessage("Test Leet Code 1604");
    LeetCodeHashtable leetCode;
    vector<string> keyName =
    {
        "daniel", "daniel", "daniel", "luis", "luis", "luis",
        "luis"
    };
    vector<string> keyTime =
    {
        "10:00","10:40","11:00","09:00","11:00","13:00", "15:00"
    };

    vector<string> result = leetCode.alertNames(keyName, keyTime);
    Logger::WriteMessage(keyName);
    Logger::WriteMessage(keyTime);
    Logger::WriteMessage(result);

    keyName =
    {
        "alice","alice","alice","bob","bob","bob","bob"
    };
    keyTime =
    {
        "12:01","12:00","18:00","21:00","21:20","21:30","23:00"
    };
    result = leetCode.alertNames(keyName, keyTime);
    Logger::WriteMessage(keyName);
    Logger::WriteMessage(keyTime);
    Logger::WriteMessage(result);


    keyName =
    {
        "john","john","john"
    };
    keyTime =
    {
        "23:58","23:59","00:01"
    };
    result = leetCode.alertNames(keyName, keyTime);
    Logger::WriteMessage(keyName);
    Logger::WriteMessage(keyTime);
    Logger::WriteMessage(result);

    keyName =
    {
       "leslie","leslie","leslie","clare","clare","clare","clare"
    };
    keyTime =
    {
        "13:00","13:20","14:00","18:00","18:51","19:30","19:49"
    };
    result = leetCode.alertNames(keyName, keyTime);
    Logger::WriteMessage(keyName);
    Logger::WriteMessage(keyTime);
    Logger::WriteMessage(result);
}

void TestLeetCode1679(void)
{
    Logger::WriteMessage("Test Leet Code 1679");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    int k = 5;
    int result = leetCode.maxOperations(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 3,1,3,4,3 };
    k = 6;
    result = leetCode.maxOperations(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}


void TestLeetCode1711(void)
{
    Logger::WriteMessage("Test Leet Code 1711");
    LeetCodeHashtable leetCode;
    vector<int> deliciousness = { 1, 3, 5, 7, 9 };
    int result = leetCode.countPairs(deliciousness);
    Logger::WriteMessage(deliciousness);
    Logger::WriteMessage("result = " + to_string(result));

    deliciousness = { 1,1,1,3,3,3,7 };
    result = leetCode.countPairs(deliciousness);
    Logger::WriteMessage(deliciousness);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1714(void)
{
    Logger::WriteMessage("Test Leet Code 1714");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 0,1,2,3,4,5,6,7 };
    vector<vector<int>> queries = { {0, 3},{5, 1},{4, 2} };
    vector<int> result = leetCode.solve(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 100,200,101,201,102,202,103,203 };
    queries = { {0, 7} };
    result = leetCode.solve(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1748(void)
{
    Logger::WriteMessage("Test Leet Code 1748");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1,2,3,2 };
    int result = leetCode.sumOfUnique(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,1,1,1 };
    result = leetCode.sumOfUnique(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,5 };
    result = leetCode.sumOfUnique(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1755(void)
{
    Logger::WriteMessage("Test Leet Code 1755");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 5, -7, 3, 5 };
    int goal = 6;
    int result = leetCode.minAbsDifference(nums, goal);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("goal = " + to_string(goal) + "; result = " + to_string(result));

    nums = { 7,-9,15,-2 };
    goal = -5;
    result = leetCode.minAbsDifference(nums, goal);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("goal = " + to_string(goal) + "; result = " + to_string(result));

    nums = { 1,2,3 };
    goal = -7;
    result = leetCode.minAbsDifference(nums, goal);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("goal = " + to_string(goal) + "; result = " + to_string(result));
}

void TestLeetCode1733(void)
{
    Logger::WriteMessage("Test Leet Code 1733");
    LeetCodeHashtable leetCode;
    int n = 2;
    vector<vector<int>> languages = { {1},{2},{1, 2} };
    vector<vector<int>> friendships = { {1, 2},{1, 3},{2, 3} };
    int result = leetCode.minimumTeachings(n, languages, friendships);
    Logger::WriteMessage(languages);
    Logger::WriteMessage(friendships);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    languages = { {2},{1, 3},{1, 2},{3} };
    friendships = { {1, 4},{1, 2},{3, 4},{2, 3} };
    result = leetCode.minimumTeachings(n, languages, friendships);
    Logger::WriteMessage(languages);
    Logger::WriteMessage(friendships);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));   
 }

void TestLeetCode1773(void)
{
    Logger::WriteMessage("Test Leet Code 1773");
    LeetCodeHashtable leetCode;
    vector<vector<string>> items =
    {
        {"phone", "blue", "pixel"},
        {"computer", "silver", "lenovo"},
        {"phone", "gold", "iphone"}
    };
    string ruleKey = "color"; 
    string ruleValue = "silver";
    int result = leetCode.countMatches(items, ruleKey, ruleValue);
    Logger::WriteMessage(items);
    Logger::WriteMessage("ruleKey = " + ruleKey + "; ruleValue = " + ruleValue + "; result = " + to_string(result));

    items =
    {
        {"phone", "blue", "pixel"},
        {"computer", "silver", "lenovo"},
        {"phone", "gold", "iphone"}
    };
    ruleKey = "type";
    ruleValue = "phone";
    result = leetCode.countMatches(items, ruleKey, ruleValue);
    Logger::WriteMessage(items);
    Logger::WriteMessage("ruleKey = " + ruleKey + "; ruleValue = " + ruleValue + "; result = " + to_string(result));
}

void TestLeetCode1814(void)
{
    Logger::WriteMessage("Test Leet Code 1814");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 42, 11, 1, 97 };
    int result = leetCode.countNicePairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 13,10,35,24,76 };
    result = leetCode.countNicePairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1817(void)
{
    Logger::WriteMessage("Test Leet Code 1817");
    LeetCodeHashtable leetCode;
    vector<vector<int>> logs = { {0, 5},{1, 2},{0, 2},{0, 5},{1, 3} };
    int k = 5;
    vector<int> result = leetCode.findingUsersActiveMinutes(logs, k);
    Logger::WriteMessage(logs);
    Logger::WriteMessage(result);

    logs = { {1,1},{2,2},{2,3} };
    k = 4;
    result = leetCode.findingUsersActiveMinutes(logs, k);
    Logger::WriteMessage(logs);
    Logger::WriteMessage(result);
}


void TestLeetCode1941(void)
{
    Logger::WriteMessage("Test Leet Code 1941");
    LeetCodeHashtable leetCode;
    string s = "abacbc";
    bool result = leetCode.areOccurrencesEqual(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "aaabb";
    result = leetCode.areOccurrencesEqual(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2053(void)
{
    Logger::WriteMessage("Test Leet Code 2053");
    LeetCodeHashtable leetCode;
    vector<string> arr = { "d", "b", "c", "b", "c", "a" };
    int k = 2;
    string result = leetCode.kthDistinct(arr, k);   
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);

    arr = { "aaa","aa","a" };
    k = 1;
    result = leetCode.kthDistinct(arr, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);

    arr = { "a","b","a" };
    k = 3;
    result = leetCode.kthDistinct(arr, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);

    arr = { "b", "a", "c", "a" };
    k = 2;
    result = leetCode.kthDistinct(arr, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);
}

void TestLeetCode1995(void)
{
    Logger::WriteMessage("Test Leet Code 1995");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1,2,3,6 };
    int result = leetCode.countQuadruplets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,3,6,4,5 };
    result = leetCode.countQuadruplets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,1,3,5 };
    result = leetCode.countQuadruplets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 28, 8, 49, 85, 37, 90, 20, 8 };
    result = leetCode.countQuadruplets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2032(void)
{
    Logger::WriteMessage("Test Leet Code 2032");
    LeetCodeHashtable leetCode;
    vector<int> nums1 = { 1, 1, 3, 2 };
    vector<int> nums2 = { 2, 3 };
    vector<int> nums3 = { 3 };
    vector<int> result = leetCode.twoOutOfThree(nums1, nums2, nums3);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(nums3);
    Logger::WriteMessage(result);

    nums1 = { 3, 1 };
    nums2 = { 2, 3 };
    nums3 = { 1, 2 };
    result = leetCode.twoOutOfThree(nums1, nums2, nums3);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(nums3);
    Logger::WriteMessage(result);

    nums1 = { 1,2,2 };
    nums2 = { 4,3,3 };
    nums3 = { 5 };
    result = leetCode.twoOutOfThree(nums1, nums2, nums3);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(nums3);
    Logger::WriteMessage(result);
}

void TestLeetCode242(void)
{
    Logger::WriteMessage("Test Leet Code 242");
    LeetCodeHashtable leetCode;
    string s = "anagram";
    string t = "nagaram";
    bool result = leetCode.isAnagram(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1915(void)
{
    Logger::WriteMessage("Test Leet Code 1915");
    LeetCodeHashtable leetCode;
    string word = "aba";
    long long result = leetCode.wonderfulSubstrings(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "aabb";
    result = leetCode.wonderfulSubstrings(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "he";
    result = leetCode.wonderfulSubstrings(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));
}

void TestLeetCode2150(void)
{
    Logger::WriteMessage("Test Leet Code 2150");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 10, 6, 5, 8 };
    vector<int> result = leetCode.findLonely(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 1,3,5,3 };
    result = leetCode.findLonely(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2206(void)
{
    Logger::WriteMessage("Test Leet Code 2206");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 3, 2, 3, 2, 2, 2 };
    bool result = leetCode.divideArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,2,3,4 };
    result = leetCode.divideArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2244(void)
{
    Logger::WriteMessage("Test Leet Code 2244");
    LeetCodeHashtable leetCode;
    vector<int> tasks = { 2,2,3,3,2,4,4,4,4,4 };
    int result = leetCode.minimumRounds(tasks);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));

    tasks = { 2,3,3 };
    result = leetCode.minimumRounds(tasks);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2215(void)
{
    Logger::WriteMessage("Test Leet Code 2215");
    LeetCodeHashtable leetCode;
    vector<int>nums1 = { 1, 2, 3 };
    vector<int>nums2 = { 2, 4, 6 };
    vector<vector<int>> result = leetCode.findDifference(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);

    nums1 = { 1,2,3,3 };
    nums2 = { 1,1,2,2 };
    result = leetCode.findDifference(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);
}

void TestLeetCode2248(void)
{
    Logger::WriteMessage("Test Leet Code 2248");
    LeetCodeHashtable leetCode;
    vector<vector<int>> nums = { {3, 1, 2, 4, 5},{1, 2, 3, 4},{3, 4, 5, 6} };
    vector<int> result = leetCode.intersection(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { {1, 2, 3},{4, 5, 6} };
    result = leetCode.intersection(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2295(void)
{
    Logger::WriteMessage("Test Leet Code 2295");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 4, 6 };
    vector<vector<int>> operations = { {1, 3},{4, 7},{6, 1} };
    vector<int> result = leetCode.arrayChange(nums, operations);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(operations);
    Logger::WriteMessage(result);

    nums = { 1, 2 };
    operations = { {1, 3},{2, 1},{3, 2} };
    result = leetCode.arrayChange(nums, operations);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(operations);
    Logger::WriteMessage(result);

    nums = { 1, 2 };
    operations = { {1, 2},{2, 3},{3, 4} };
    result = leetCode.arrayChange(nums, operations);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(operations);
    Logger::WriteMessage(result);
}

void TestLeetCode2342(void)
{
    Logger::WriteMessage("Test Leet Code 2342");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 18,43,36,13,7 };
    int result = leetCode.maximumSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 10,12,19,14 };
    result = leetCode.maximumSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2347(void)
{
    Logger::WriteMessage("Test Leet Code 2347");
    LeetCodeHashtable leetCode;
    vector<int> ranks = { 13, 2, 3, 1, 9 };
    vector<char> suits = { 'a', 'a', 'a', 'a', 'a' };
    string result = leetCode.bestHand(ranks, suits);
    Logger::WriteMessage(ranks);
    Logger::WriteMessage(suits);
    Logger::WriteMessage("result = " + result);

    ranks = { 4,4,2,4,4 };
    suits = { 'd','a','a','b','c' };
    result = leetCode.bestHand(ranks, suits);
    Logger::WriteMessage(ranks);
    Logger::WriteMessage(suits);
    Logger::WriteMessage("result = " + result);

    ranks = { 10,10,2,12,9 };
    suits = { 'a','b','c','a','d' };
    result = leetCode.bestHand(ranks, suits);
    Logger::WriteMessage(ranks);
    Logger::WriteMessage(suits);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode2441(void)
{
    Logger::WriteMessage("Test Leet Code 2441");
    LeetCodeHashtable leetCode;
    vector<int> nums = { -1, 2, -3, 3 };
    int result = leetCode.findMaxK(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -1,10,6,7,-7,1 };
    result = leetCode.findMaxK(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -10,8,6,7,-2,-3 };
    result = leetCode.findMaxK(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2442(void)
{
    Logger::WriteMessage("Test Leet Code 2442");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1,13,10,12,31 };
    int result = leetCode.countDistinctIntegers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,2 };
    result = leetCode.countDistinctIntegers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2456(void)
{
    Logger::WriteMessage("Test Leet Code 2456");
    LeetCodeHashtable leetCode;
    vector<string> creators =  { "alice", "bob", "alice", "chris" }; 
    vector<string> ids = { "one", "two", "three", "four" };
    vector<int> views = { 5, 10, 5, 4 };
    vector<vector<string>> result = leetCode.mostPopularCreator(creators, ids, views);
    Logger::WriteMessage(creators);
    Logger::WriteMessage(ids);
    Logger::WriteMessage(views);
    Logger::WriteMessage(result);

    creators = { "alice","alice","alice" };
    ids = { "a","b","c" };
    views = { 1,2,2 };
    result = leetCode.mostPopularCreator(creators, ids, views);
    Logger::WriteMessage(creators);
    Logger::WriteMessage(ids);
    Logger::WriteMessage(views);
    Logger::WriteMessage(result);
}

void TestLeetCode2657(void)
{
    Logger::WriteMessage("Test Leet Code 2657");
    LeetCodeHashtable leetCode;
    vector<int> A = { 1, 3, 2, 4 };
    vector<int> B = { 3, 1, 2, 4 };
    vector<int> result = leetCode.findThePrefixCommonArray(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { 2,3,1 };
    B = { 3,1,2 };
    result = leetCode.findThePrefixCommonArray(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);
}

void TestLeetCode2670(void)
{
    Logger::WriteMessage("Test Leet Code 2670");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    vector<int> result = leetCode.distinctDifferenceArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 3,2,3,4,2 };
    result = leetCode.distinctDifferenceArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2766(void)
{
    Logger::WriteMessage("Test Leet Code 2766");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 6, 7, 8 };
    vector<int> moveFrom = { 1, 7, 2 };
    vector<int> moveTo = { 2, 9, 5 };
    vector<int> result = leetCode.relocateMarbles(nums, moveFrom, moveTo);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(moveFrom);
    Logger::WriteMessage(moveTo);
    Logger::WriteMessage(result);

    nums = { 1,1,3,3 };
    moveFrom = { 1,3 };
    moveTo = { 2,2 };
    result = leetCode.relocateMarbles(nums, moveFrom, moveTo);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(moveFrom);
    Logger::WriteMessage(moveTo);
    Logger::WriteMessage(result);
}

void TestLeetCode2815(void)
{
    Logger::WriteMessage("Test Leet Code 2815");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 51, 71, 17, 24, 42 };
    int result = leetCode.maxSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4 };
    result = leetCode.maxSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2829(void)
{
    Logger::WriteMessage("Test Leet Code 2829");
    LeetCodeHashtable leetCode;
    int n = 5, k = 4;
    int result = leetCode.minimumSum(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    n = 2, k = 6;
    result = leetCode.minimumSum(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2834(void)
{
    Logger::WriteMessage("Test Leet Code 2834");
    LeetCodeHashtable leetCode;
    int n = 2, target = 3;
    long long result = leetCode.minimumPossibleSum(n, target);
    Logger::WriteMessage("n = " + to_string(n) + "; target = " + to_string(target));
    Logger::WriteMessage("result = " + to_string(result));

    n = 3, target = 3;
    result = leetCode.minimumPossibleSum(n, target);
    Logger::WriteMessage("n = " + to_string(n) + "; target = " + to_string(target));
    Logger::WriteMessage("result = " + to_string(result));

    n = 1, target = 1;
    result = leetCode.minimumPossibleSum(n, target);
    Logger::WriteMessage("n = " + to_string(n) + "; target = " + to_string(target));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2857(void)
{
    Logger::WriteMessage("Test Leet Code 2857");
    LeetCodeHashtable leetCode;
    vector<vector<int>> coordinates =
    {
        {1, 2},{4, 2},{1, 3},{5, 2}
    };
    int k = 5;
    int result = leetCode.countPairs(coordinates, k);
    Logger::WriteMessage(coordinates);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    coordinates =
    {
        {1,3},{1,3},{1,3},{1,3},{1,3}
    };
    k = 0;
    result = leetCode.countPairs(coordinates, k);
    Logger::WriteMessage(coordinates);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2870(void)
{
    Logger::WriteMessage("Test Leet Code 2870");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 2, 3, 3, 2, 2, 4, 2, 3, 4 };
    int result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,1,2,2,3,3 };
    result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2956(void)
{
    Logger::WriteMessage("Test Leet Code 2956");
    LeetCodeHashtable leetCode;
    vector<int> nums1 = { 4, 3, 2, 3, 1 };
    vector<int> nums2 = { 2, 2, 5, 2, 3, 6 };
    vector<int> result = leetCode.findIntersectionValues(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);

    nums1 = { 3,4,2,3 };
    nums2 = { 1,5 };
    result = leetCode.findIntersectionValues(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);
}

void TestLeetCode2961(void)
{
    Logger::WriteMessage("Test Leet Code 2961");
    LeetCodeHashtable leetCode;
    vector<vector<int>> variables =
    { 
        {2, 3, 3, 10},{3, 3, 3, 1},{6, 1, 1, 4} 
    };
    int target = 2;
    vector<int> result = leetCode.getGoodIndices(variables, target);
    Logger::WriteMessage(variables);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(result);

    variables =
    {
        {39,3,1000,1000}
    };
    target = 17;
    result = leetCode.getGoodIndices(variables, target);
    Logger::WriteMessage(variables);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(result);

    variables =
    {
        {2,2,3,2}
    };
    target = 0;
    result = leetCode.getGoodIndices(variables, target);
    Logger::WriteMessage(variables);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(result);

    variables =
    {
        {8, 3, 5, 8}
    };
    target = 4;
    result = leetCode.getGoodIndices(variables, target);
    Logger::WriteMessage(variables);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(result);
}

void TestLeetCode2964(void)
{
    Logger::WriteMessage("Test Leet Code 2964");
    LeetCodeHashtable leetCode;
    vector<int> nums = {3,3,4,7,8};
    int d = 5;
    int result = leetCode.divisibleTripletCount(nums, d);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    nums = { 3,3,3,3 };
    d = 3;
    result = leetCode.divisibleTripletCount(nums, d);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    nums = { 3,3,3,3 };
    d = 6;
    result = leetCode.divisibleTripletCount(nums, d);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));
}

void TestLeetCode3002(void)
{
    Logger::WriteMessage("Test Leet Code 3002");
    LeetCodeHashtable leetCode;
    vector<int> nums1 = { 1, 2, 1, 2 };
    vector<int> nums2 = { 1, 1, 1, 1 };
    int result = leetCode.maximumSetSize(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1,2,3,4,5,6 };
    nums2 = { 2,3,2,3,2,3 };
    result = leetCode.maximumSetSize(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1,1,2,2,3,3 };
    nums2 = { 4,4,5,5,6,6 };
    result = leetCode.maximumSetSize(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode243(void)
{
    Logger::WriteMessage("Test Leet Code 243");
    LeetCodeHashtable leetCode;
    vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
    string word1 = "coding";
    string word2 = "practice";
    int distance = leetCode.shortestDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));

    word1 = "makes";
    word2 = "coding";
    distance = leetCode.shortestDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));
}

void TestLeetCode245(void)
{
    Logger::WriteMessage("Test Leet Code 245");
    LeetCodeHashtable leetCode;
    vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
    string word1 = "coding";
    string word2 = "practice";
    int distance = leetCode.shortestWordDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));

    word1 = "makes";
    word2 = "coding";
    distance = leetCode.shortestWordDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));

    word1 = "makes";
    word2 = "makes";
    distance = leetCode.shortestWordDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));
}

void TestLeetCode3005(void)
{
    Logger::WriteMessage("Test Leet Code 3005");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 2, 3, 1, 4 };
    int result = leetCode.maxFrequencyElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,5 };
    result = leetCode.maxFrequencyElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3016(void)
{
    Logger::WriteMessage("Test Leet Code 3016");
    LeetCodeHashtable leetCode;
    string word = "abcde";
    int result = leetCode.minimumPushesII(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "xyzxyzxyzxyz";
    result = leetCode.minimumPushesII(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "aabbccddeeffgghhiiiiii";
    result = leetCode.minimumPushesII(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));
}

void TestLeetCode3020(void)
{
    Logger::WriteMessage("Test Leet Code 3020");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 5, 4, 1, 2, 2 };
    int result = leetCode.maximumLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,3,2,4 };
    result = leetCode.maximumLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,1,1,1,1,1,1,1 };
    result = leetCode.maximumLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3046(void)
{
    Logger::WriteMessage("Test Leet Code 3046");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1,1,2,2,3,4 };
    bool result = leetCode.isPossibleToSplit(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,1,1 };
    result = leetCode.isPossibleToSplit(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode3092(void)
{
    Logger::WriteMessage("Test Leet Code 3092");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 2, 3, 2, 1 };
    vector<int> freq = { 3, 2, -3, 1 };
    vector<long long> result = leetCode.mostFrequentIDs(nums, freq);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(freq);
    Logger::WriteMessage(result);

    nums = { 5,5,3 };
    freq = { 2,-2,1 };
    result = leetCode.mostFrequentIDs(nums, freq);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(freq);
    Logger::WriteMessage(result);
}

void TestLeetCode3160(void)
{
    Logger::WriteMessage("Test Leet Code 3160");
    LeetCodeHashtable leetCode;
    int limit = 4;
    vector<vector<int>> queries = { {1, 4},{2, 5},{1, 3},{3, 4} };
    vector<int> result = leetCode.queryResults(limit, queries);
    Logger::WriteMessage("limit = " + to_string(limit));
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    limit = 4;
    queries = { {0, 1},{1, 2},{2, 2},{3, 4},{4, 5} };
    result = leetCode.queryResults(limit, queries);
    Logger::WriteMessage("limit = " + to_string(limit));
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode3158(void)
{
    Logger::WriteMessage("Test Leet Code 3158");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 1, 3 };
    int result = leetCode.duplicateNumbersXOR(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3 };
    result = leetCode.duplicateNumbersXOR(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,2,1 };
    result = leetCode.duplicateNumbersXOR(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3184(void)
{
    Logger::WriteMessage("Test Leet Code 3184");
    LeetCodeHashtable leetCode;
    vector<int> hours = { 12,12,30,24,24 };
    int result = leetCode.countCompleteDayPairsI(hours);
    Logger::WriteMessage(hours);
    Logger::WriteMessage("result = " + to_string(result));

    hours = { 72,48,24,3 };
    result = leetCode.countCompleteDayPairsI(hours);
    Logger::WriteMessage(hours);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3185(void)
{
    Logger::WriteMessage("Test Leet Code 3185");
    LeetCodeHashtable leetCode;
    vector<int> hours = { 12,12,30,24,24 };
    long long result = leetCode.countCompleteDayPairsII(hours);
    Logger::WriteMessage(hours);
    Logger::WriteMessage("result = " + to_string(result));

    hours = { 72,48,24,3 };
    result = leetCode.countCompleteDayPairsII(hours);
    Logger::WriteMessage(hours);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3289(void)
{
    Logger::WriteMessage("Test Leet Code 3289");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 0, 1, 1, 0 };
    vector<int> result = leetCode.getSneakyNumbers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 0,3,2,1,3,2 };
    result = leetCode.getSneakyNumbers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode3450(void)
{
    Logger::WriteMessage("Test Leet Code 3450");
    LeetCodeHashtable leetCode;
    vector<vector<int>> students = { {1, 2},{2, 2},{3, 3},{1, 3},{2, 3} };
    int result = leetCode.maxStudentsOnBench(students);
    Logger::WriteMessage(students);
    Logger::WriteMessage("result = "  + to_string(result));

    students = { {1, 1},{2, 1},{3, 1},{4, 2},{5, 2} };
    result = leetCode.maxStudentsOnBench(students);
    Logger::WriteMessage(students);
    Logger::WriteMessage("result = " + to_string(result));

    students = { {1, 1},{1, 1} };
    result = leetCode.maxStudentsOnBench(students);
    Logger::WriteMessage(students);
    Logger::WriteMessage("result = " + to_string(result));

    students = { };
    result = leetCode.maxStudentsOnBench(students);
    Logger::WriteMessage(students);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3471(void)
{
    Logger::WriteMessage("Test Leet Code 3471");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 3, 9, 2, 1, 7 };
    int k = 3;
    int result = leetCode.largestInteger(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 3, 9, 7, 2, 1, 7 };
    k = 4;
    result = leetCode.largestInteger(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 0,0 };
    k = 1;
    result = leetCode.largestInteger(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3487(void)
{
    Logger::WriteMessage("Test Leet Code 3487");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1,2,3,4,5 };
    int result = leetCode.maxSumII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,0,1,1 };
    result = leetCode.maxSumII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,-1,-2,1,0,-1 };
    result = leetCode.maxSumII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3527(void)
{
    Logger::WriteMessage("Test Leet Code 3527");
    LeetCodeHashtable leetCode;
    vector<vector<string>> responses =
    { 
        {"good", "ok", "good", "ok"},{"ok", "bad", "good", "ok", "ok"},{"good"},{"bad"} 
    };
    string result = leetCode.findCommonResponse(responses);
    Logger::WriteMessage(responses);
    Logger::WriteMessage("result = " + result);

    responses =
    {
        {"good","ok","good"} ,{"ok","bad"},{"bad","notsure"},{"great","good"}
    };
    result = leetCode.findCommonResponse(responses);
    Logger::WriteMessage(responses);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode3659(void)
{
    Logger::WriteMessage("Test Leet Code 3659");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    int k = 2;
    bool result = leetCode.partitionArray(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    nums = { 3,5,2,2 };
    k = 2;
    result = leetCode.partitionArray(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    nums = { 1,5,2,3 };
    k = 3;
    result = leetCode.partitionArray(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode3663(void)
{
    Logger::WriteMessage("Test Leet Code 3663");
    LeetCodeHashtable leetCode;
    int n = 1553322;
    int result = leetCode.getLeastFrequentDigit(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 723344511;
    result = leetCode.getLeastFrequentDigit(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode3668(void)
{
    Logger::WriteMessage("Test Leet Code 3668");
    LeetCodeHashtable leetCode;
    vector<int> order = { 3, 1, 2, 5, 4 };
    vector<int> friends = { 1, 3, 4 };
    vector<int> result = leetCode.recoverOrder(order, friends);
    Logger::WriteMessage(order);
    Logger::WriteMessage(friends);
    Logger::WriteMessage(result);

    order = { 1,4,5,3,2 };
    friends = { 2,5 };
    result = leetCode.recoverOrder(order, friends);
    Logger::WriteMessage(order);
    Logger::WriteMessage(friends);
    Logger::WriteMessage(result);
}

void TestLeetCode3678(void)
{
    Logger::WriteMessage("Test Leet Code 3678");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 3, 5 };
    int result = leetCode.smallestAbsent(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -1, 1, 2 };
    result = leetCode.smallestAbsent(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4, -1 };
    result = leetCode.smallestAbsent(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -84, 28, 12 };
    result = leetCode.smallestAbsent(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3692(void)
{
    Logger::WriteMessage("Test Leet Code 3692");
    LeetCodeHashtable leetCode;
    string s = "aaabbbccdddde";
    string result = leetCode.majorityFrequencyGroup(s);
    Logger::WriteMessage("s = "+ s + "; result = " + result);

    s = "abcd";
    result = leetCode.majorityFrequencyGroup(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "pfpfgi";
    result = leetCode.majorityFrequencyGroup(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode3712(void)
{
    Logger::WriteMessage("Test Leet Code 3712");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 2, 3, 3, 3, 3, 4 };
    int k = 2;
    int result = leetCode.sumDivisibleByK(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,3,4,5 };
    k = 2;
    result = leetCode.sumDivisibleByK(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 4,4,4,1,2,3 };
    k = 3;
    result = leetCode.sumDivisibleByK(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3718(void)
{
    Logger::WriteMessage("Test Leet Code 3718");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 8,2,3,4,6 };
    int k = 2;
    int result = leetCode.missingMultiple(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,4,7,10,15 };
    k = 5;
    result = leetCode.missingMultiple(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3731(void)
{
    Logger::WriteMessage("Test Leet Code 3731");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1,4,2,5 };
    vector<int> result = leetCode.findMissingElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 7,8,6,9 };
    result = leetCode.findMissingElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 5,1 };
    result = leetCode.findMissingElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode3761(void)
{
    Logger::WriteMessage("Test Leet Code 3761");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 12,21,45,33,54 };
    int result = leetCode.minMirrorPairDistance(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 120,21 };
    result = leetCode.minMirrorPairDistance(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 21,120 };
    result = leetCode.minMirrorPairDistance(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3810(void)
{
    Logger::WriteMessage("Test Leet Code 3810");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 3 };
    vector<int> target = { 2, 1, 3 };
    int result = leetCode.minOperations(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,1,4 };
    target = { 5,1,4 };
    result = leetCode.minOperations(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 7,3,7 };
    target = { 5,5,9 };
    result = leetCode.minOperations(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCodeHashtable(void)
{
    TestLeetCode3810();
    TestLeetCode3761();
    TestLeetCode3731();
    TestLeetCode3718();
    TestLeetCode3712();
    TestLeetCode3692();
    TestLeetCode3678();
    TestLeetCode3668();
    TestLeetCode3663();
    TestLeetCode3659();
    TestLeetCode3527();
    TestLeetCode3487();
    TestLeetCode3471();
    TestLeetCode3450();
    TestLeetCode3289();
    TestLeetCode3185();
    TestLeetCode3184();
    TestLeetCode3160();
    TestLeetCode3158();
    TestLeetCode3092();
    TestLeetCode3046();
    TestLeetCode3020();
    TestLeetCode3016();
    TestLeetCode3005();
    TestLeetCode245();
    TestLeetCode243();
    TestLeetCode3002();
    TestLeetCode2964();
    TestLeetCode2961();
    TestLeetCode2956();
    TestLeetCode2870();
    TestLeetCode2857();
    TestLeetCode2834();
    TestLeetCode2829();
    TestLeetCode2815();
    TestLeetCode2766();
    TestLeetCode2670();
    TestLeetCode2657();
    TestLeetCode217();
    TestLeetCode2456();
    TestLeetCode2442();
    TestLeetCode2441();
    TestLeetCode2347();
    TestLeetCode2342();
    TestLeetCode2295();
    TestLeetCode2248();
    TestLeetCode2244();
    TestLeetCode2215();
    TestLeetCode2206();
    TestLeetCode2150();
    TestLeetCode1915();
    TestLeetCode242();
    TestLeetCode205();
    TestLeetCode1452();
    TestLeetCode2032();
    TestLeetCode1995();
    TestLeetCode2053();
    TestLeetCode1941();
    TestLeetCode1817();
    TestLeetCode1814();
    TestLeetCode1773();
    TestLeetCode1733();
    TestLeetCode1755();
    TestLeetCode1748();
    TestLeetCode1714();
    TestLeetCode1711();
    TestLeetCode1679();
    TestLeetCode1604();
    TestLeetCode1577();
    TestLeetCode792();
    TestLeetCode1512();
    TestLeetCode811();
    TestLeetCode347();
    TestLeetCode748();
    TestLeetCode957();
    TestLeetCode1010();
    TestLeetCode1128();
    TestLeetCode1152();
    TestLeetCode128();
    TestLeetCode1041();
    TestLeetCode350();
    TestLeetCode349();
    TestLeetCode299();
    TestLeetCode451();
    TestLeetCode166();
    TestLeetCode500();
    TestLeetCode599();
    TestLeetCode506();
    TestLeetCode890();
    TestLeetCode594();
    TestLeetCode202();
    TestLeetCode884();
    TestLeetCode916();
    TestLeetCode532();
    TestLeetCode734();
    TestLeetCode760();
    TestLeetCode1496();
    TestLeetCode1487();
    TestLeetCode1481();
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
