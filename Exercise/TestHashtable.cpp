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

void TestLeetCodeHashtable(void)
{
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
    TestLeetCode219();
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