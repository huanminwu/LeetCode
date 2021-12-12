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

void TestLeetCodeTwoPointer(void)
{
    TestLeetCode2062();
    TestLeetCode1852();
    TestLeetCode881();
}