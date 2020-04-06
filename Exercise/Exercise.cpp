// Exercise.cpp : Defines the entry point for the console application.
//
#include <assert.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>
#include <map>
#include <iostream>
#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeDesign.h"
#include "..\LeetCode\LeetCodeDP.h"
#include "..\LeetCode\LeetCodeGraph.h"
#include "..\LeetCode\LeetCodeArray.h"
#include "..\LeetCode\LeetCodeLinkedList.h"
#include "..\LeetCode\LeetCodeTree.h"
#include "..\LeetCode\LeetCodeSort.h"
#include "..\LeetCode\LeetCodeDFS.h"
#include "..\LeetCode\LeetCodeGreedy.h"
#include "..\LeetCode\LeetCodeString.h"
#include "..\LeetCode\LeetCodeBinarySearch.h"
#include "..\LeetCode\LeetCodeUnionFind.h"
#include "TestMath.h"
#include "TestDP.h"
#include "TestHashtable.h"
#include "TestStack.h"
#include "TestGraph.h"
#include "TestArray.h"
#include "TestLinkedList.h"
#include "TestTree.h"
#include "TestSort.h"
#include "TestBFS.h"
#include "TestDFS.h"
#include "TestDesign.h"
#include "TestGreedy.h"
#include "TestString.h"
#include "TestBinarySearch.h"
#include "TestUnionFind.h"
#include "TestTwoPointers.h"

void TestLeetCode121(void)
{
    Logger::WriteMessage("Test Leet Code 121");
    LeetCode leetCode;
    string message;
    Logger::WriteMessage("The stock price is ");
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    Logger::WriteMessage(prices);
    int maxProfit = leetCode.maxProfitOneTxn(prices);    
    message.assign("The max profit is ");
    message.append(std::to_string(maxProfit));
    Logger::WriteMessage(message.c_str());
    
    Logger::WriteMessage("The stock price is ");
    prices = { 1, 2 };
    maxProfit = leetCode.maxProfitOneTxn(prices);
    message.assign("The max profit is ");
    message.append(std::to_string(maxProfit));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode122(void)
{
    Logger::WriteMessage("Test Leet Code 122");
    LeetCode leetCode;
    vector<int> prices;
    int maxProfit;
    string message;
    Logger::WriteMessage("The stock price is ");
    prices = { 7, 1, 5, 3, 6, 4 };
    Logger::WriteMessage(prices);
    maxProfit = leetCode.maxProfitManyTxns(prices);
    message.assign("The max profit is ");
    message.append(std::to_string(maxProfit));
    Logger::WriteMessage(message);

    Logger::WriteMessage("The stock price is ");
    prices = { 1, 2 };
    maxProfit = leetCode.maxProfitManyTxns(prices);
    message.assign("The max profit is ");
    message.append(std::to_string(maxProfit));
    Logger::WriteMessage(message);
}

void TestLeetCode56(void)
{
    Logger::WriteMessage("Test Leet Code 56");
    LeetCode leetCode;
    vector<Interval> test =
    {
        { 1, 3 },
        { 2, 6 },
        { 8, 10 },
        { 15, 18 }
    };
    vector<Interval> result;

    result = leetCode.mergeIntervals(test);
}


void TestLeetCode69(void)
{
    Logger::WriteMessage("Test Leet Code 69");
    LeetCode leetCode;
    int num = 2147395599;
    string message;
    message.append("The sqrt(" + to_string(num) + ") = " + to_string(leetCode.mySqrt(num)));
    Logger::WriteMessage(message.c_str());
}


void TestLeetCode89(void)
{
    Logger::WriteMessage("Test Leet Code 69");
    LeetCode leetCode;
    int n = 4;
    vector<int> grayCode = leetCode.grayCode(n);
    Logger::WriteMessage(grayCode);
}



void TestLeetCode12(void)
{
    LeetCode leetCode;
    Logger::WriteMessage("Test Leet Code 12");
    int num = 20;
    string message;
    message.assign("Number is " + to_string(num));
    string result = leetCode.intToRoman(num);
    message.append("; Roman is " + result);
    Logger::WriteMessage(message.c_str());

    num = 999;
    message.assign("Number is " + to_string(num));
    result = leetCode.intToRoman(num);
    message.append("; Roman is " + result);
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode13(void)
{
    LeetCode leetCode;
    Logger::WriteMessage("Test Leet Code 13");
    string roman = "XX";
    string message;
    message.assign("Roman is " + roman);
    int num = leetCode.romanToInt(roman);
    message.append("; Number is " + to_string(num));
    Logger::WriteMessage(message.c_str());

    roman = "CMXCIX";
    message.assign("Roman is " + roman);
    num = leetCode.romanToInt(roman);
    message.append("; Number is " + to_string(num));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode11(void)
{
    LeetCode leetCode;
    Logger::WriteMessage("Test Leet Code 11");
    string message;
    vector<int> heights = { 2, 6, 7, 8, 3, 1 };
    Logger::WriteMessage(heights);
    int maxArea = leetCode.maxArea(heights);
    message.assign("Max Area = " + to_string(maxArea));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode155(void)
{
    MinStack minStack;
    Logger::WriteMessage("minStack.push(-2)");
    minStack.push(-2);
    Logger::WriteMessage("minStack.push(0)");
    minStack.push(0);
    Logger::WriteMessage("minStack.push(-3)");
    minStack.push(-3);
    Logger::WriteMessage(("minStack.getMin()" + to_string(minStack.getMin())).c_str());
    minStack.getMin();
    Logger::WriteMessage("minStack.pop()");
    minStack.pop();
    Logger::WriteMessage(("minStack.top()" + to_string(minStack.getMin())).c_str());
    minStack.top();
    Logger::WriteMessage(("minStack.getMin()" + to_string(minStack.getMin())).c_str());
    minStack.getMin();
}

void TestLeetCode371(void)
{
    LeetCode leetCode;
    int a = 11, b = 13;
    Logger::WriteMessage(to_string(a) + " + " + to_string(b) + " = " + to_string(leetCode.getSum(a, b)));
}

void TestLeetCode191(void)
{
    LeetCode leetCode;
    uint32_t n = 11;
    Logger::WriteMessage("Total 1 bits in " + to_string(n) + " is " + to_string(leetCode.hammingWeight(n)));
}

void TestLeetCode16(void)
{
    LeetCode leetCode;
    Logger::WriteMessage("Test Leet Code 16");
    vector<int> nums =
    {
        1, 1, 1, 0
    };

    Logger::WriteMessage(nums);

    int sum = leetCode.threeSumClosest(nums, 100);
    string message;
    message.assign("Three Sum Closet is " + to_string(sum));
    Logger::WriteMessage(message.c_str());

    nums =
    {
        43, 75, -90, 47, -49, 72, 17, -31, -68, -22, -21, -30, 65, 88, -75, 23, 97, -61, 53, 87, -3, 33,
        20, 51, -79, 43, 80, -9, 34, -89, -7, 93, 43, 55, -94, 29, -32, -49, 25, 72, -6, 35, 53, 63, 6,
        -62, -96, -83, -73, 66, -11, 96, -90, -27, 78, -51, 79, 35, -63, 85, -82, -15, 100, -82, 1, -4,
        -41, -21, 11, 12, 12, 72, -82, -22, 37, 47, -18, 61, 60, 55, 22, -6, 26, -60, -42, -92, 68, 45, -1,
        -26, 5, -56, -1, 73, 92, -55, -20, -43, -56, -15, 7, 52, 35, -90, 63, 41, -55, -58, 46, -84, -92, 17,
        -66, -23, 96, -19, -44, 77, 67, -47, -48, 99, 51, -25, 19, 0, -13, -88, -10, -67, 14, 7, 89, -69, -83,
        86, -70, -66, -38, -50, 66, 0, -67, -91, -65, 83, 42, 70, -6, 52, -21, -86, -87, -44, 8, 49, -76, 86,
        -3, 87, -32, 81, -58, 37, -55, 19, -26, 66, -89, -70, -69, 37, 0, 19, -65, 38, 7, 3, 1, -96, 96, -65,
        -52, 66, 5, -3, -87, -16, -96, 57, -74, 91, 46, -79, 0, -69, 55, 49, -96, 80, 83, 73, 56, 22, 58, -44,
        -40, -45, 95, 99, -97, -22, -33, -92, -51, 62, 20, 70, 90
    };

    Logger::WriteMessage(nums);

    sum = leetCode.threeSumClosest(nums, 284);
    message;
    message.assign("Three Sum Closet is " + to_string(sum));
    Logger::WriteMessage(message.c_str());

}

void TestLeetCode22(void)
{
    Logger::WriteMessage("Test Leet Code 22");
    LeetCodeDFS leetCode;
    int n = 3;
    Logger::WriteMessage("n= " + to_string(n));
    vector<string> result = leetCode.generateParenthesis(n);
    Logger::WriteMessage("Parenthesis combinations are: ");
    Logger::WriteMessage(result);
}

void TestLeetCode60(void)
{
    Logger::WriteMessage("Test Leet Code 60");
    LeetCode leetCode;
    int n = 9, k = 10000;
    string result = leetCode.getPermutation(n, k);
    Logger::WriteMessage("The " + to_string(k) + "th permutation in " + to_string(n) + "! sequence is " + result);
}

void TestLeetCode97(void)
{
    Logger::WriteMessage("Test Leet Code 97");
    LeetCode leetCode;
    string s1, s2, s3, message;

    s1.assign("aabcc");
    s2.assign("dbbca");
    s3.assign("aadbbcbcac");
    Logger::WriteMessage("s1 = " + s1);
    Logger::WriteMessage("s2 = " + s2);
    Logger::WriteMessage("s3 = " + s3);
    bool isInterLeave = leetCode.isInterleave(s1, s2, s3);
    Logger::WriteMessage(isInterLeave ? "s3 is interleave of s1 and s2" : "s3 is not interleave of s1 and s2");
    s3.assign("aadbbbaccc");
    Logger::WriteMessage("s3 = " + s3);
    isInterLeave = leetCode.isInterleave(s1, s2, s3);
    Logger::WriteMessage(isInterLeave ? "s3 is interleave of s1 and s2" : "s3 is not interleave of s1 and s2");
}

void TestLeetCode5(void)
{
    Logger::WriteMessage("Test Leet Code 5");
    LeetCode leetCode;
    
    string s = "abaaba";
    string result = leetCode.longestPalindrome(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
    
    s = "abcc";
    result = leetCode.longestPalindrome(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "";
    result = leetCode.longestPalindrome(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "babad";
    result = leetCode.longestPalindrome(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "cbbd";
    result = leetCode.longestPalindrome(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode57(void)
{
    Logger::WriteMessage("Test Leet Code 57");
    LeetCode leetCode;
    string message;
    vector<Interval> intervals = { {1,3},{6,9} };
    message.assign("[");
    for (size_t i = 0; i < intervals.size(); i++)
    {
        message.append("[" + to_string(intervals[i].start) + "," + to_string(intervals[i].end) + "]");
    }
    message.append("]");
    Logger::WriteMessage("Original Intervals " + message);
    Interval newInterval = { 2, 5 };
    message.assign("[" + to_string(newInterval.start) + "," + to_string(newInterval.end) + "]");
    Logger::WriteMessage("New Interval " + message);
    vector<Interval> result;
    result = leetCode.insertInterval(intervals, newInterval);
    message.assign("[");
    for (size_t i = 0; i < result.size(); i++)
    {
        message.append("[" + to_string(result[i].start) + "," + to_string(result[i].end) + "]");
    }
    message.append("]");
    Logger::WriteMessage("Merged Intervals " + message);

    intervals = { {1, 2},{3, 5},{6, 7},{8, 10},{12, 16} };
    message.assign("[");
    for (size_t i = 0; i < intervals.size(); i++)
    {
        message.append("[" + to_string(intervals[i].start) + "," + to_string(intervals[i].end) + "]");
    }
    message.append("]");
    Logger::WriteMessage("Original Intervals " + message);
    newInterval = { 4, 9 };
    message.assign("[" + to_string(newInterval.start) + "," + to_string(newInterval.end) + "]");
    Logger::WriteMessage("New Interval " + message);
    result = leetCode.insertInterval(intervals, newInterval);
    message.assign("[");
    for (size_t i = 0; i < result.size(); i++)
    {
        message.append("[" + to_string(result[i].start) + "," + to_string(result[i].end) + "]");
    }
    message.append("]");
    Logger::WriteMessage("Merged Intervals " + message);
}

void TestLeetCode42(void)
{
    Logger::WriteMessage("Test Leet Code 42");
    LeetCode leetCode;
    string message;
    vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    Logger::WriteMessage("The array of heights is ");
    Logger::WriteMessage(heights);
    int sum = leetCode.trapWater(heights);
    message.assign("Trap water = " + to_string(sum));
    Logger::WriteMessage(message);

    heights = { 0,1,2,3,4,5,6 };
    Logger::WriteMessage("The array of heights is ");
    Logger::WriteMessage(heights);
    sum = leetCode.trapWater(heights);
    message.assign("Trap water = " + to_string(sum));
    Logger::WriteMessage(message);
}



void TestLeetCode231(void)
{
    Logger::WriteMessage("Test Leet Code 231");
    LeetCode leetCode;
    int n = 128;
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(leetCode.isPowerOfTwo(n) ? "is power of two" : "is not power of two");
    n = 0;
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(leetCode.isPowerOfTwo(n) ? "is power of two" : "is not power of two");
    n = INT_MIN;
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(leetCode.isPowerOfTwo(n) ? "is power of two" : "is not power of two");
}

void TestLeetCode338(void)
{
    Logger::WriteMessage("Test Leet Code 338");
    LeetCode leetCode;
    int num = 12;
    Logger::WriteMessage("num = " + to_string(num));
    vector<int> result = leetCode.countBits(num);
    Logger::WriteMessage("Bits are ");
    Logger::WriteMessage(result);
}


void TestLeetCode342(void)
{
    Logger::WriteMessage("Test Leet Code 342");
    LeetCode leetCode;
    int n = 256;
    Logger::WriteMessage("N = " + to_string(n));
    string message;
    message.assign("N is ");
    message.append(leetCode.isPowerOfFour(n) ? "" : " not ").append("Power of four");
    Logger::WriteMessage(message);

    n = 128;
    Logger::WriteMessage("N = " + to_string(n));
    message.assign("N is ");
    message.append(leetCode.isPowerOfFour(n) ? "" : " not ").append("Power of four");
    Logger::WriteMessage(message);
}


void TestLeetCode171(void)
{
    Logger::WriteMessage("Test Leet Code 171");
    string column = "AB";
    LeetCode leetCode;
    int number = leetCode.titleToNumber(column);
    Logger::WriteMessage("Column tile = " + column + " number = " + to_string(number));
}

void TestLeetCode168(void)
{
    Logger::WriteMessage("Test Leet Code 168");
    int number = 26 * 26;

    LeetCode leetCode;
    string column = leetCode.convertToTitle(number);
    Logger::WriteMessage("Column number = " + to_string(number) + " title = " + column);
}

void TestLeetCode136(void)
{
    Logger::WriteMessage("Test Leet Code 136");
    LeetCode leetCode;
    vector<int> data = { 1, 1, 2, 3, 3 };
    Logger::WriteMessage(data);
    int number = leetCode.singleNumber(data);
    Logger::WriteMessage(to_string(number));
}

void TestLeetCode263(void)
{
    Logger::WriteMessage("Test Leet Code 263");
    LeetCode leetCode;
    int data = 18;
    bool is_ugly = leetCode.isUgly(data);
    Logger::WriteMessage(to_string(data) + " is " + (is_ugly ? "" : " not ") + "ugly number");
}


void TestLeetCode389(void)
{
    Logger::WriteMessage("Test Leet Code 389");
    LeetCode leetCode;
    string s("abcd");
    string t("abcde");
    Logger::WriteMessage("s = " + s + " " + "t=" + t);
    char ch = leetCode.findTheDifference(s, t);
    string message;
    message.assign("difference = ");
    message.push_back(ch);
    Logger::WriteMessage(message);
}

void TestLeetCode420(void)
{
    Logger::WriteMessage("Test Leet Code 420");
    LeetCode leetCode;
    string password;
    int change;
  
    password.assign("aaaaabbbb1234567890ABA");
    change = leetCode.strongPasswordChecker(password);
    Logger::WriteMessage("pasword = " + password + " change =" + to_string(change));

    password.assign("aaaaaaaAAAAAA6666bbbbaaaaaaABBC");
    change = leetCode.strongPasswordChecker(password);
    Logger::WriteMessage("pasword = " + password + " change =" + to_string(change));

    password.assign("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    change = leetCode.strongPasswordChecker(password);
    Logger::WriteMessage("pasword = " + password + " change =" + to_string(change));

    password.assign("aaa111");
    change = leetCode.strongPasswordChecker(password);
    Logger::WriteMessage("pasword = " + password + " change =" + to_string(change));

}




void TestLeetCode30(void)
{
    Logger::WriteMessage("Test Leet Code 30");
    LeetCode leetCode;
    vector<string> words;
    vector<int> result;
    string s;
    s.assign("wordgoodgoodgoodbestword");
    words = { "word", "good", "best", "good" };
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("word list ");
    Logger::WriteMessage(words);
    result = leetCode.findSubstring(s, words);
    Logger::WriteMessage(result);

    s.assign("barfoothefoobarman");
    words = { "foo", "bar" };
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("word list ");
    Logger::WriteMessage(words);
    result = leetCode.findSubstring(s, words);
    Logger::WriteMessage(result);

    s.assign("mississippi");
    words = { "mississippis" };
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("word list ");
    Logger::WriteMessage(words);
    result = leetCode.findSubstring(s, words);
    Logger::WriteMessage(result);

    s.assign("barfoofoobarthefoobarman");
    words = { "bar", "foo", "the" };
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("word list ");
    Logger::WriteMessage(words);
    result = leetCode.findSubstring(s, words);
    Logger::WriteMessage(result);
}

void TestLeetCode84(void)
{
    Logger::WriteMessage("Test Leet Code 84");
    LeetCode leetCode;
    vector<int> heights;
    int max_area_by_stack;
    int max_area_by_divide;

    heights = { 3, 6, 5, 7, 4, 8, 1, 0 };
    max_area_by_stack = leetCode.largestRectangleAreaByStack(heights);
    max_area_by_divide = leetCode.largestRectangleAreaByDivide(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleAreaByStack = " + to_string(max_area_by_stack));
    Logger::WriteMessage("LargestRectangleAreaByDivide = " + to_string(max_area_by_divide));

    heights = { 9, 0 };
    max_area_by_stack = leetCode.largestRectangleAreaByStack(heights);
    max_area_by_divide = leetCode.largestRectangleAreaByDivide(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area_by_stack));
    Logger::WriteMessage("LargestRectangleAreaByDivide = " + to_string(max_area_by_divide));

    heights = { 4, 2, 0, 3, 2, 5 };
    max_area_by_stack = leetCode.largestRectangleAreaByStack(heights);
    max_area_by_divide = leetCode.largestRectangleAreaByDivide(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area_by_stack));
    Logger::WriteMessage("LargestRectangleAreaByDivide = " + to_string(max_area_by_divide));

    heights = { 2,1,5,6,2,3 };
    max_area_by_stack = leetCode.largestRectangleAreaByStack(heights);
    max_area_by_divide = leetCode.largestRectangleAreaByDivide(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area_by_stack));
    Logger::WriteMessage("LargestRectangleAreaByDivide = " + to_string(max_area_by_divide));

    heights = {};
    max_area_by_stack = leetCode.largestRectangleAreaByStack(heights);
    max_area_by_divide = leetCode.largestRectangleAreaByDivide(heights);

    heights = { 2,1,2 };
    max_area_by_stack = leetCode.largestRectangleAreaByStack(heights);
    max_area_by_divide = leetCode.largestRectangleAreaByDivide(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area_by_stack));
    Logger::WriteMessage("LargestRectangleAreaByDivide = " + to_string(max_area_by_divide));

    heights = { 0, 0, 0, 0, 0, 0, 0, 0, 2147483647 };
    heights = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    max_area_by_stack = leetCode.largestRectangleAreaByStack(heights);
    max_area_by_divide = leetCode.largestRectangleAreaByDivide(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area_by_stack));
    Logger::WriteMessage("LargestRectangleAreaByDivide = " + to_string(max_area_by_divide));
}




void TestLeetCode87(void)
{
    Logger::WriteMessage("Test Leet Code 87");
    LeetCode leetCode;
    string s1, s2;
    bool is_scramble;
    s1.assign("great");
    s2.assign("rgeat");
    is_scramble = leetCode.isScramble(s1, s2);
    Logger::WriteMessage(s1 + " and " + s2 + (is_scramble ? " are " : " are not ") + "scramble string");
    s2.assign("rgtae");
    is_scramble = leetCode.isScramble(s1, s2);
    Logger::WriteMessage(s1 + " and " + s2 + (is_scramble ? " are " : " are not ") + "scramble string");
}


void TestLeetCode164(void)
{
    Logger::WriteMessage("Test Leet Code 164");
    LeetCode leetCode;
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

void TestLeetCode128(void)
{
    Logger::WriteMessage("Test Leet Code 128");
    LeetCode leetCode;
    vector<int> nums;
    int longestConsecutive;
    nums = { 100, 4, 200, 1, 3, 2 };
    Logger::WriteMessage(nums);
    longestConsecutive = leetCode.longestConsecutive(nums);
    Logger::WriteMessage("The longest consecutive is " + to_string(longestConsecutive));
}



void TestLeetCode239(void)
{
    Logger::WriteMessage("Test Leet Code 239");
    LeetCode leetCode;
    vector<int> nums;
    vector<int> result;
    int k;
    nums = { 1,  3, -1, -3,  5, 3,  6,  7 };
    k = 3;
    Logger::WriteMessage(nums);
    result = leetCode.maxSlidingWindow(nums, k);
    Logger::WriteMessage(result);
}

void TestLeetCode27(void)
{
    Logger::WriteMessage("Test Leet Code 27");
    LeetCode leetCode;
    vector<int> nums;
    int result;
    nums = { 2, 3, 3, 2 };
    Logger::WriteMessage(nums);
    result = leetCode.removeArrayElement(nums, 3);
    Logger::WriteMessage(nums);
}

void TestLeetCode283(void)
{
    Logger::WriteMessage("Test Leet Code 283");
    LeetCode leetCode;
    vector<int> nums;
    nums = { 0, 1, 0, 3, 12 };
    Logger::WriteMessage("Original numbers:");
    Logger::WriteMessage(nums);
    leetCode.moveZeroes(nums);
    Logger::WriteMessage("After move:");
    Logger::WriteMessage(nums);
    nums = { 0, 0 };
    Logger::WriteMessage("Original numbers:");
    Logger::WriteMessage(nums);
    leetCode.moveZeroes(nums);
    Logger::WriteMessage("After move:");
    Logger::WriteMessage(nums);
    nums = { };
    Logger::WriteMessage("Original numbers:");
    Logger::WriteMessage(nums);
    leetCode.moveZeroes(nums);
    Logger::WriteMessage("After move:");
    Logger::WriteMessage(nums);
}



void TestLeetCode31(void)
{
    Logger::WriteMessage("Test Leet Code 31");
    vector<int> nums;
    LeetCode leetCode;
    nums = { 1,2,3 };
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
    nums = { 3,2,1 };
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
    nums = { 1,5,1 };
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
    nums = { 1,1,5 };
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
    nums = {};
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
}

void TestLeetCode166(void)
{
    Logger::WriteMessage("Test Leet Code 166");
    LeetCode leetCode;
    int numerator, denominator;
    string result;
    numerator = -1;
    denominator = INT_MIN;
    result = leetCode.fractionToDecimal(numerator, denominator);
    Logger::WriteMessage(to_string(numerator) + "/" + to_string(denominator) + "=" + result);

    numerator = 4; 
    denominator = 7; 
    result = leetCode.fractionToDecimal(numerator, denominator);
    Logger::WriteMessage(to_string(numerator) + "/" + to_string(denominator)+ "=" + result);
}


void TestLeetCode198(void)
{
    Logger::WriteMessage("Test Leet Code 198");
    LeetCode leetCode;
    vector<int> nums = {  1, 2, 3, 4, 5, 6 };
    Logger::WriteMessage(nums);
    int amount = leetCode.rob(nums);
    Logger::WriteMessage("The maximum amount the robber can get is " + to_string(amount));
}

void TestLeetCode35(void)
{
    Logger::WriteMessage("Test Leet Code 35");
    LeetCode leetCode;
    int result;
    int target;
    vector<int> nums = { 1,3,5,6 };
    target = 5;
    Logger::WriteMessage(nums);
    result = leetCode.searchInsert(nums, target);
    Logger::WriteMessage("Search " + to_string(target) + " -> " + to_string(result));
    target = 2;
    Logger::WriteMessage(nums);
    result = leetCode.searchInsert(nums, target);
    Logger::WriteMessage("Search " + to_string(target) + " -> " + to_string(result));
    target = 7;
    Logger::WriteMessage(nums);
    result = leetCode.searchInsert(nums, target);
    Logger::WriteMessage("Search " + to_string(target) + " -> " + to_string(result));
    target = 0;
    Logger::WriteMessage(nums);
    result = leetCode.searchInsert(nums, target);
    Logger::WriteMessage("Search " + to_string(target) + " -> " + to_string(result));
}

void TestLeetCode75(void)
{
    Logger::WriteMessage("Test Leet Code 75");
    LeetCode leetCode;
    vector<int> nums;
    nums = { 0, 2, 0, 1, 0, 2, 1, 0, 2, 1 };
    Logger::WriteMessage(nums);
    leetCode.sortColors(nums);
    Logger::WriteMessage(nums);

    nums = { };
    Logger::WriteMessage(nums);
    leetCode.sortColors(nums);
    Logger::WriteMessage(nums);

    nums = {2, 1, 1, 2};
    Logger::WriteMessage(nums);
    leetCode.sortColors(nums);
    Logger::WriteMessage(nums);

    nums = { 1, 0 };
    Logger::WriteMessage(nums);
    leetCode.sortColors(nums);
    Logger::WriteMessage(nums);
}

void TestLeetCode345(void)
{
    Logger::WriteMessage("Test Leet Code 345");
    LeetCode leetCode;
    string s = "hEllo";
    Logger::WriteMessage(s + "->" + leetCode.reverseVowels(s));
}

void TestLeetCode74(void)
{
    Logger::WriteMessage("Test Leet Code 74");
    LeetCode leetCode;
    vector<vector<int>> matrix;
    int target;
    bool found;
    target = 3;
    matrix = { {1}, {3} };
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
    matrix = { { 1,   3,  5,  7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
    target = 100;
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
    target = 9;
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
    target = 11;
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
}

void TestLeetCode202(void)
{
    Logger::WriteMessage("Test Leet Code 202");
    LeetCode leetCode;
    int n;
    bool isHappyNumber;
    n = 19;
    isHappyNumber = leetCode.isHappy(n);
    Logger::WriteMessage("The number " + to_string(n) + " is " + (isHappyNumber ? "" : "not") + " a happy number." );
    n = 25;
    isHappyNumber = leetCode.isHappy(n);
    Logger::WriteMessage("The number " + to_string(n) + " is " + (isHappyNumber ? "" : "not") + " a happy number.");
}


void TestLeetCode374(void)
{
    Logger::WriteMessage("Test Leet Code 374");
    int n = 1;
    LeetCode leetCode;
    int guess = leetCode.guessNumber(n, n);
    Logger::WriteMessage("Guess number in " + to_string(n) + " is " + to_string(guess));
    n = 100;
    guess = leetCode.guessNumber(n, n);
    Logger::WriteMessage("Guess number in " + to_string(n) + " is " + to_string(guess));
}

void TestLeetCode217(void)
{
    Logger::WriteMessage("Test Leet Code 217");
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5, 3 };
    Logger::WriteMessage(nums);
    bool containsDuplicate = leetCode.containsDuplicate(nums);
    Logger::WriteMessage("The list " + string(containsDuplicate? "contains ": "does not contain ") + "duplicates.");

    nums = { 1, 2, 2, 3, 4, 4, 3 };
    Logger::WriteMessage(nums);
    containsDuplicate = leetCode.containsDuplicate(nums);
    Logger::WriteMessage("The list " + string(containsDuplicate ? "contains " : "does not contain ") + "duplicates.");
}


void TestLeetCode96(void)
{
    Logger::WriteMessage("Test Leet Code 96");
    LeetCode leetCode;
    int n;
    int result;
    n = 3;
    result = leetCode.numTrees(n);
    Logger::WriteMessage("n = " + to_string(n) + " , " + "number of trees = " + to_string(result));
}

void TestLeetCode95(void)
{
    Logger::WriteMessage("Test Leet Code 95");
    LeetCode leetCode;
    int n;
    n = 0;
    vector<TreeNode*> result;
    result = leetCode.generateTrees(n);
    for (size_t i = 0; i < result.size(); i++)
    {
        TreeNode * root = result[i];
        string output = leetCode.serialize(root);
        Logger::WriteMessage(output);
        leetCode.freeTreeNodes(root);
    }
}

void TestLeetCode299(void)
{
    Logger::WriteMessage("Test Leet Code 299");
    LeetCode leetCode;
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
    LeetCode leetCode;
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
    LeetCode leetCode;
    vector<int> nums1, nums2, result;
    nums1 = { 1, 2, 2, 1 };
    nums2 = { 2, 2 };
    result = leetCode.intersectionArrayII(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);
}

void TestLeetCode219(void)
{
    Logger::WriteMessage("Test Leet Code 219");
    LeetCode leetCode;
    vector<int> nums;
    int k = 2;
    bool result;
    nums = { 1, 2, 3, 2, 1 };
    result = leetCode.containsNearbyDuplicate(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The array " + string(result ? "contains":"does not contain") + " duplicates within " + to_string(k));
}

void TestLeetCode225(void)
{
    Logger::WriteMessage("Test Leet Code 225");
    StackByQueue stackByQueue;
    string output;
    stackByQueue.push(1);
    stackByQueue.push(2);
    stackByQueue.push(3);
    output = "push(1), push(2), push(3)";
    Logger::WriteMessage(output);
    output = "pop(" + to_string(stackByQueue.top()) + ")";
    stackByQueue.pop();
    Logger::WriteMessage(output);
    output = "pop(" + to_string(stackByQueue.top()) + ")";
    stackByQueue.pop();
    Logger::WriteMessage(output);
    output = "pop(" + to_string(stackByQueue.top()) + ")";
    stackByQueue.pop();
    Logger::WriteMessage(output);
    stackByQueue.empty();
    Logger::WriteMessage("The stack " + string(stackByQueue.empty()? "is":"is not") + " empty");
}

void TestLeetCode232(void)
{
    Logger::WriteMessage("Test Leet Code 232");
    QueueByStack queueByStack;
    string output;
    queueByStack.push(1);
    queueByStack.push(2);
    queueByStack.push(3);
    output = "push(1), push(2), push(3)";
    Logger::WriteMessage(output);
    output = "pop(" + to_string(queueByStack.peek()) + ")";
    queueByStack.pop();
    Logger::WriteMessage(output);
    output = "pop(" + to_string(queueByStack.peek()) + ")";
    queueByStack.pop();
    Logger::WriteMessage(output);
    output = "pop(" + to_string(queueByStack.peek()) + ")";
    queueByStack.pop();
    Logger::WriteMessage(output);
    Logger::WriteMessage("The queue " + string(queueByStack.empty() ? "is" : "is not") + " empty");
}


void TestLeetCode233(void)
{
    Logger::WriteMessage("Test Leet Code 233");
    LeetCode leetCode;
    int n = 123;
    int count = leetCode.countDigitOne(n);
    Logger::WriteMessage("Count digit one for " + to_string(n) + "; count = " + to_string(count));
}

void TestLeetCode357(void)
{
    Logger::WriteMessage("Test Leet Code 357");
    LeetCode leetCode;
    int n = 2;
    int count = leetCode.countNumbersWithUniqueDigits(n);
    Logger::WriteMessage("Count numbers with unique digits with " + to_string(n) + "; count = " + to_string(count));
}

void TestLeetCode400(void)
{
    Logger::WriteMessage("Test Leet Code 400");
    LeetCode leetCode;
    int n = 1000000000;
    int digit = leetCode.findNthDigit(n);
    Logger::WriteMessage("The " + to_string(n) + "th digit is " + to_string(digit));
}

void TestLeetCode337(void)
{
    Logger::WriteMessage("Test Leet Code 337");
    LeetCode leetCode;
    string input = "[3,4,5,1,3,null,1]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    int sum = leetCode.robIII(root);
    Logger::WriteMessage("Maximum rob money is " + to_string(sum));
    leetCode.freeTreeNodes(root);

    input = "[3,2,3,null,3, null, 1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    sum = leetCode.robIII(root);
    Logger::WriteMessage("Maximum rob money is " + to_string(sum));
    leetCode.freeTreeNodes(root);
             
    input = "[4, 1, null, 2, null, 3]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    sum = leetCode.robIII(root);
    Logger::WriteMessage("Maximum rob money is " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode124(void)
{
    Logger::WriteMessage("Test Leet Code 124");
    LeetCode leetCode;
    string input = "[100,-2,1]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    int sum = leetCode.maxPathSum(root);
    Logger::WriteMessage("Maximum path sum is " + to_string(sum));
    leetCode.freeTreeNodes(root);
}


void TestLeetCode85(void)
{
    Logger::WriteMessage("Test Leet Code 85");
    LeetCode leetCode;
    vector<vector<char>> matrix =
    {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' }
    };
    int max_rectangle = leetCode.maximalRectangle(matrix);
    Logger::WriteMessage("The maximum rectangle area is " + to_string(max_rectangle));
}

void TestLeetCode278(void)
{
    Logger::WriteMessage("Test Leet Code 278");
    LeetCode leetCode;
    int n_version = 3, bad_version = 1;
    int result = leetCode.firstBadVersion(n_version, bad_version);
    Logger::WriteMessage("First Bad Verion = " +  to_string(result));
}


void TestLeetCode405(void)
{
    Logger::WriteMessage("Test Leet Code 405");
    LeetCode leetCode;
    int num = -3;
    Logger::WriteMessage("num = " + to_string(num));
    string result = leetCode.toHex(num); 
    Logger::WriteMessage("to Hex = " + result);
}

void TestLeetCode137(void)
{
    Logger::WriteMessage("Test Leet Code 137");
    LeetCode leetCode;
    vector<int> nums = { 1,1,1,2,3,3,3 };
    int result = leetCode.singleNumberII(nums);
    Logger::WriteMessage("result = " + to_string(result));

    Logger::WriteMessage("Test Leet Code 137");
    nums = { 1,1,1,-2,-3,-3,-3 };
    result = leetCode.singleNumberII(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode139(void)
{
    Logger::WriteMessage("Test Leet Code 139");
    LeetCode leetCode;
    string s;
    unordered_set<string> wordDict;
    bool result;
    s = "leetcode";
    wordDict = unordered_set<string>({ "leet", "code" });
    result = leetCode.wordBreak(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("The string " + string(result ? "can" : "cannot") + " be broken into words.");

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    wordDict = unordered_set<string>({ "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" });
    result = leetCode.wordBreak(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("The string " + string(result ? "can" : "cannot") + " be broken into words.");

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    wordDict = unordered_set<string>({ "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" });
    result = leetCode.wordBreak(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("The string " + string(result ? "can" : "cannot") + " be broken into words.");
}

void TestLeetCode190(void)
{
    Logger::WriteMessage("Test Leet Code 190");
    LeetCode leetCode;
    uint32_t n = 43261596;
    Logger::WriteMessage("n = " + to_string(n) + "; reverse bits = " + to_string(leetCode.reverseBits(n)));
}

void TestLeetCode397(void)
{
    Logger::WriteMessage("Test Leet Code 397");
    LeetCode leetCode;
    uint32_t n;
    n = 7;
    Logger::WriteMessage("n = " + to_string(n) + "; minimum replacement = " + to_string(leetCode.integerReplacement(n)));
    n = 3;
    Logger::WriteMessage("n = " + to_string(n) + "; minimum replacement = " + to_string(leetCode.integerReplacement(n)));
}



void TestLeetCode201(void)
{
    Logger::WriteMessage("Test Leet Code 201");
    LeetCode leetCode;
    int m = 7, n = 5;
    int sum = leetCode.rangeBitwiseAnd(m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage("sum = " + to_string(sum));
}

void TestLeetCode318(void)
{
    Logger::WriteMessage("Test Leet Code 318");
    LeetCode leetCode;
    vector<string> words;
    int result;
    words = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
    Logger::WriteMessage(words);
    result = leetCode.maxProductWordLength(words);
    Logger::WriteMessage("maximum word length = " + to_string(result));

    words = { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
    Logger::WriteMessage(words);
    result = leetCode.maxProductWordLength(words);
    Logger::WriteMessage("maximum word length = " + to_string(result));

    words = { "a", "aa", "aaa", "aaaa" };
    Logger::WriteMessage(words);
    result = leetCode.maxProductWordLength(words);
    Logger::WriteMessage("maximum word length = " + to_string(result));
}

void TestLeetCode268(void)
{
    Logger::WriteMessage("Test Leet Code 268");
    LeetCode leetCode;
    vector<int> nums = { 0, 1, 3 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The missing number = " + to_string(leetCode.missingNumber(nums)));
}

void TestLeetCode260(void)
{
    Logger::WriteMessage("Test Leet Code 260");
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 1, 3, 2, 5 };
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.singleNumberIII(nums);
    Logger::WriteMessage("The single numbers are");
    Logger::WriteMessage(result);
}

void TestLeetCode173(void)
{
    Logger::WriteMessage("Test Leet Code 173");
    LeetCode leetCode;
    string input = "[4,2,6,1,3,5,7]";
    TreeNode * root = leetCode.deserialize(input);
    BSTIterator iterator(root);
    vector<int> node_list;
    while (iterator.hasNext())
    {
        node_list.push_back(iterator.next());
    }
    Logger::WriteMessage(node_list);
    leetCode.freeTreeNodes(root);
}



void TestLeetCode120(void)
{
    Logger::WriteMessage("Test Leet Code 120");
    LeetCode leetCode;
    vector<vector<int>> triangle;
    int minimum_total;
    triangle = { { -1 },{ 2, 3 },{ 1, -1, -3 } };
    for (size_t i = 0; i < triangle.size(); i++)
    {
        Logger::WriteMessage(triangle[i]);
    }
    minimum_total = leetCode.minimumTotal(triangle);
    Logger::WriteMessage("Minimum total is " + to_string(minimum_total));

    triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
    for (size_t i = 0; i < triangle.size(); i++)
    {
        Logger::WriteMessage(triangle[i]);
    }
    minimum_total = leetCode.minimumTotal(triangle);
    Logger::WriteMessage("Minimum total is " + to_string(minimum_total));
}

void TestLeetCode437(void)
{
    Logger::WriteMessage("Test Leet Code 437");
    LeetCode leetCode;
    string input;
    int sum;
    TreeNode * root;
    int total_paths;
    input = "[10,5,-3,3,2,null,11,3,-2,null,1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    sum = 8;
    total_paths = leetCode.pathSumIII(root, sum);
    Logger::WriteMessage("The total path to sum " + to_string(sum) + " is " + to_string(total_paths));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode303(void)
{
    Logger::WriteMessage("Test Leet Code 303");
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray numArray(nums);
    Logger::WriteMessage(nums);
    int i, j;
    i = 0; j = 2;
    Logger::WriteMessage("sum [" + to_string(i) + "," + to_string(j) + "] = " + to_string(numArray.sumRange(i,j)));
    i = 2; j = 5;
    Logger::WriteMessage("sum [" + to_string(i) + "," + to_string(j) + "] = " + to_string(numArray.sumRange(i,j)));
    i = 0; j = 5;
    Logger::WriteMessage("sum [" + to_string(i) + "," + to_string(j) + "] = " + to_string(numArray.sumRange(i,j)));
}


void TestLeetCode367(void)
{
    Logger::WriteMessage("Test Leet Code 367");
    LeetCode leetCode;
    int num;
    bool isPerfectSquare;
    num = 36;
    isPerfectSquare = leetCode.isPerfectSquare(num);
    Logger::WriteMessage(to_string(num) + string(isPerfectSquare ? " is " : " is not ") + "a perfect square");

    num = 32;
    isPerfectSquare = leetCode.isPerfectSquare(num);
    Logger::WriteMessage(to_string(num) + string(isPerfectSquare ? " is " : " is not ") + "a perfect square");
}

void TestLeetCode274(void)
{
    Logger::WriteMessage("Test Leet Code 274");
    LeetCode leetCode;
    vector<int> nums = { 1 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("H index =" + to_string(leetCode.hIndex(nums)));

    nums = { 3, 0, 6, 1, 5 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("H index =" + to_string(leetCode.hIndex(nums)));
}

void TestLeetCode275(void)
{
    Logger::WriteMessage("Test Leet Code 275");
    LeetCode leetCode;
    vector<int> nums = { 3, 0, 6, 1, 5 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("H index =" + to_string(leetCode.hIndexII(nums)));
    nums = { 0, 0, 0, 0, 0 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("H index =" + to_string(leetCode.hIndexII(nums)));
}


void TestLeetCode116(void)
{
    Logger::WriteMessage("Test Leet Code 116");
    LeetCode leetCode;
    string input;
    TreeLinkNode * root;
    input = "[1,2,3,4,5,6,7]";
    Logger::WriteMessage(input);
    root = leetCode.deserializeLinkTree(input);
    leetCode.connectRight(root);
    Logger::WriteMessage(leetCode.serializeLinkTree(root));
    leetCode.freeLinkTreeNodes(root);
}

void TestLeetCode117(void)
{
    Logger::WriteMessage("Test Leet Code 117");
    LeetCode leetCode;
    string input;
    TreeLinkNode * root;
    input = "[1,2,3,4,5,6,7]";
    Logger::WriteMessage(input);
    root = leetCode.deserializeLinkTree(input);
    leetCode.connectRightII(root);
    Logger::WriteMessage(leetCode.serializeLinkTree(root));
    leetCode.freeLinkTreeNodes(root);
}

void TestLeetCode211(void)
{
    Logger::WriteMessage("Test Leet Code 211");
    WordDictionary wordDictionary;
    bool isWord;
    wordDictionary.addWord("at");
    wordDictionary.addWord("and");
    wordDictionary.addWord("an");
    wordDictionary.addWord("add");
    isWord = wordDictionary.search("a");
    Logger::WriteMessage("search(a)->" + string(isWord ? "true" : "false"));
    isWord = wordDictionary.search(".at");
    Logger::WriteMessage("search(.at)->" + string(isWord ? "true" : "false"));
    wordDictionary.addWord("bat");
    isWord = wordDictionary.search(".at");
    Logger::WriteMessage("search(.at)->" + string(isWord ? "true" : "false"));  
    isWord = wordDictionary.search("an.");
    Logger::WriteMessage("search(an.)->" + string(isWord ? "true" : "false"));
    isWord = wordDictionary.search("a.d.");
    Logger::WriteMessage("search(a.d.)->" + string(isWord ? "true" : "false"));
    isWord = wordDictionary.search("b.");
    Logger::WriteMessage("search(b.)->" + string(isWord ? "true" : "false"));
    isWord = wordDictionary.search("a.d");
    Logger::WriteMessage("search(a.d)->" + string(isWord ? "true" : "false"));
    isWord = wordDictionary.search(".");
    Logger::WriteMessage("search(.)->" + string(isWord ? "true" : "false"));
}

void TestLeetCode167(void)
{
    Logger::WriteMessage("Test Leet Code 117");
    LeetCode leetCode;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.twoSumII(nums, target);
    Logger::WriteMessage(result);
}

void TestLeetCode238(void)
{
    Logger::WriteMessage("Test Leet Code 238");
    LeetCode leetCode;
    vector<int> nums = { 1,2,3,4 };
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.productExceptSelf(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode398(void)
{
    Logger::WriteMessage("Test Leet Code 398");
    LeetCode leetCode;
    vector<int> nums = { 1,2,3,3,3 };
    int target = 2;
    int index = leetCode.pickRandom(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The random pick " + to_string(target) + " is " + to_string(index));
    target = 1;
    index = leetCode.pickRandom(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The random pick " + to_string(target) + " is " + to_string(index));
    target = 3;
    index = leetCode.pickRandom(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The random pick " + to_string(target) + " is " + to_string(index));
}


void TestLeetCode384(void)
{
    Logger::WriteMessage("Test Leet Code 384");
    LeetCode leetCode;
    vector<int> nums = { 1,2,3 };
    vector<int> result = leetCode.shuffle(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode131(void)
{
    Logger::WriteMessage("Test Leet Code 131");
    LeetCode leetCode;
    string s = "aab";
    Logger::WriteMessage(s);
    vector<vector<string>> partitions = leetCode.partitionPalindrome(s);
    Logger::WriteMessage(partitions);
}

void TestLeetCode421(void)
{
    Logger::WriteMessage("Test Leet Code 421");
    LeetCode leetCode;
    vector<int> nums = { 3, 10, 5, 25, 2, 8 };
    Logger::WriteMessage(nums);
    int maximumXOR = leetCode.findMaximumXOR(nums);
    Logger::WriteMessage("Maximum XOR = " + to_string(maximumXOR));
}

void TestLeetCode304(void)
{
    Logger::WriteMessage("Test Leet Code 304");
    vector<vector<int>> matrix = 
    {
        { 3, 0, 1, 4, 2 },
        { 5, 6, 3, 2, 1 },
        { 1, 2, 0, 1, 5 },
        { 4, 1, 0, 1, 7 },
        { 1, 0, 3, 0, 5 }
    };
    Logger::WriteMessage(matrix);
    NumMatrix numMatrix(matrix);
    int sum = numMatrix.sumRegion(2, 1, 4, 3);
    Logger::WriteMessage("Sum of Region(2,1,4,3) = " + to_string(sum));
    sum = numMatrix.sumRegion(1, 1, 2, 2);
    Logger::WriteMessage("Sum of Region(1,1,2,2) = " + to_string(sum));
    sum = numMatrix.sumRegion(1, 2, 2, 4);
    Logger::WriteMessage("Sum of Region(1,2,2,4) = " + to_string(sum));
}


void TestLeetCode392(void)
{
    Logger::WriteMessage("Test Leet Code 392");
    LeetCode leetCode;
    string s = "abc", t = "ahbgdc";
    bool isSequence = leetCode.isSubsequence(s, t);
    Logger::WriteMessage("s=" + s + ";" + "t=" + t + (string)(isSequence? " is " : " is not ") + "sub sequence.");
    s = "axc", t = "ahbgdc";
    isSequence = leetCode.isSubsequence(s, t);
    Logger::WriteMessage("s=" + s + ";" + "t=" + t + (string)(isSequence ? " is " : " is not ") + "sub sequence.");
}

void TestLeetCode376(void)
{
    Logger::WriteMessage("Test Leet Code 376");
    LeetCode leetCode;
    vector<int> nums = {1, 7, 4, 9, 2, 5};
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
    LeetCode leetCode;
    vector<int> nums = { 1, 5, 1, 1, 6, 4 };
    Logger::WriteMessage(nums);
    leetCode.wiggleSortII(nums);
    Logger::WriteMessage(nums);
}

void TestLeetCode222(void)
{
    Logger::WriteMessage("Test Leet Code 222");
    LeetCode leetCode;
    string input;
    TreeNode * root;
    input = "[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    Logger::WriteMessage("Count complete tree = " + to_string(leetCode.countCompleteTreeNodes(root)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode230(void)
{
    Logger::WriteMessage("Test Leet Code 230");
    LeetCode leetCode;
    string input;
    TreeNode * root;
    input = "[9,5,13,3,7,11,15,2,4,6,8,10,12,14,16,1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    int k = 7;
    Logger::WriteMessage("Kth smallest item = " + to_string(leetCode.kthSmallest(root, k)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode347(void)
{
    Logger::WriteMessage("Test Leet Code 347");
    LeetCode leetCode;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = leetCode.topKFrequent(nums, k);
    Logger::WriteMessage(nums);

    Logger::WriteMessage("Top K frequent items");
    Logger::WriteMessage(result);
}

void TestLeetCode461(void)
{
    Logger::WriteMessage("Test Leet Code 461");
    LeetCode leetCode;
    int x = 1, y = 4;
    int count = leetCode.hammingDistance(x, y);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; Haming Distance = " + to_string(count));
}

void TestLeetCode450(void)
{
    Logger::WriteMessage("Test Leet Code 450");
    LeetCode leetCode;
    
    string input = "[1,null,2]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    root = leetCode.deleteNode(root, 2);
    string output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[3,2,4,1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    root = leetCode.deleteNode(root, 3);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[5,3,6,2,4,null,7]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    root = leetCode.deleteNode(root, 3);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[9,5,13,3,7,11,15,2,4,6,8,10,12,14,16,1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    root = leetCode.deleteNode(root, 13);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode475(void)
{
    Logger::WriteMessage("Test Leet Code 475");
    LeetCode leetCode;
    vector<int> houses = { 1, 2, 3, 4 };
    Logger::WriteMessage(houses);
    vector<int> heaters = { 1, 4 };
    Logger::WriteMessage(heaters);
    int radius = leetCode.findRadius(houses, heaters);
    Logger::WriteMessage("Radius = " + to_string(radius));
}

void TestLeetCode179(void)
{
    Logger::WriteMessage("Test Leet Code 179");
    vector<int> nums = { 3, 30, 32, 5, 9 };
    LeetCode leetCode;
    string result = leetCode.largestNumber(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Result = " + result);

    nums = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    result = leetCode.largestNumber(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Result = " + result);

    nums = { 12, 121};
    result = leetCode.largestNumber(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Result = " + result);
}

void TestLeetCode307(void)
{
    Logger::WriteMessage("Test Leet Code 307");
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArrayMutable numArrayMutable(nums);
    Logger::WriteMessage(nums);
    int i, j;
    i = 0; j = 2;
    Logger::WriteMessage("sum [" + to_string(i) + "," + to_string(j) + "] = " + to_string(numArrayMutable.sumRange(i, j)));
    i = 2; j = 5;
    Logger::WriteMessage("sum [" + to_string(i) + "," + to_string(j) + "] = " + to_string(numArrayMutable.sumRange(i, j)));
    i = 0; j = 5;
    Logger::WriteMessage("sum [" + to_string(i) + "," + to_string(j) + "] = " + to_string(numArrayMutable.sumRange(i, j)));
    numArrayMutable.update(1, 2);
    i = 0; j = 5;
    Logger::WriteMessage("sum [" + to_string(i) + "," + to_string(j) + "] = " + to_string(numArrayMutable.sumRange(i, j)));
}

void TestLeetCode306(void)
{
    Logger::WriteMessage("Test Leet Code 306");
    LeetCode leetCode;
    string num = "19910011992";
    bool isAdditiveNumber = leetCode.isAdditiveNumber(num);
    Logger::WriteMessage("num = " + num + (string)(isAdditiveNumber ? " is " : " is not ") + "additive number.");
    num = "199100199";
    isAdditiveNumber = leetCode.isAdditiveNumber(num);
    Logger::WriteMessage("num = " + num + (string)(isAdditiveNumber ? " is " : " is not ") + "additive number.");
    num = "112358";
    isAdditiveNumber = leetCode.isAdditiveNumber(num);
    Logger::WriteMessage("num = " + num + (string)(isAdditiveNumber ? " is " : " is not ") + "additive number.");
}

void TestLeetCode477(void)
{
    Logger::WriteMessage("Test Leet Code 377");
    LeetCode leetCode;
    vector<int> nums = { 4, 14, 2 };
    Logger::WriteMessage(nums);
    int total = leetCode.totalHammingDistance(nums);
    Logger::WriteMessage("Total Hamming Distance = " + to_string(total));
}

void TestLeetCode228(void)
{
    Logger::WriteMessage("Test Leet Code 228");
    LeetCode leetCode;
    vector<int> nums = { 0, 1, 2, 4, 5, 7 };
    Logger::WriteMessage(nums);
    vector<string> result = leetCode.summaryRanges(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode456(void)
{
    Logger::WriteMessage("Test Leet Code 456");
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    Logger::WriteMessage(nums);
    bool result = leetCode.find132pattern(nums);
    Logger::WriteMessage("This " + (string)(result ? "is" : "is not") + " 132 pattern");

    nums = { 3, 1, 4, 2 };
    Logger::WriteMessage(nums);
    result = leetCode.find132pattern(nums);
    Logger::WriteMessage("This " + (string)(result ? "is" : "is not") + " 132 pattern");

    nums = { -1, 3, 2, 0 };
    Logger::WriteMessage(nums);
    result = leetCode.find132pattern(nums);
    Logger::WriteMessage("This " + (string)(result ? "is" : "is not") + " 132 pattern");
}

void TestLeetCode406(void)
{
    Logger::WriteMessage("Test Leet Code 406");
    LeetCode leetCode;
    vector<pair<int, int>> heights = { { 7, 0 },{ 4, 4 },{ 7, 1 },{ 5, 0 },{ 6, 1 },{ 5, 2 } };
    vector<pair<int, int>> result = leetCode.reconstructQueue(heights);
    Logger::WriteMessage(result);
}

void TestLeetCode451(void)
{
    Logger::WriteMessage("Test Leet Code 451");
    LeetCode leetCode;
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

void TestLeetCode279(void)
{
    Logger::WriteMessage("Test Leet Code 279");
    LeetCode leetCode;
    int n = 12;
    int result = leetCode.numSquares(n);
    Logger::WriteMessage("n = " + to_string(n) + " ; number of sqaures = " + to_string(result));

    n = 100;
    result = leetCode.numSquares(n);
    Logger::WriteMessage("n = " + to_string(n) + " ; number of sqaures = " + to_string(result));
}

void TestLeetCode220(void)
{
    Logger::WriteMessage("Test Leet Code 220");
    LeetCode leetCode;
    vector<int> nums = { -1, -1 };
    int k = 1;
    int t = 0;
    bool result = leetCode.containsNearbyAlmostDuplicate(nums, k, t);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("index distance = " + to_string(k) + " ; value distance = " + to_string(t));
    Logger::WriteMessage("Result= " + (string)(result ? "true":"false"));

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

void TestLeetCode436(void)
{
    Logger::WriteMessage("Test Leet Code 436");
    LeetCode leetCode;
    vector<Interval> intervals = { { 1,2 } };
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

void TestLeetCode390(void)
{
    LeetCode leetCode;
    Logger::WriteMessage("Test Leet Code 390");
    int n = 9;
    int lastRemaining = leetCode.lastRemaining(n);
    Logger::WriteMessage("n = " + to_string(n) + "; last remaining = " + to_string(lastRemaining));
}

void TestLeetCode330(void)
{
    Logger::WriteMessage("Test Leet Code 330");
    LeetCode leetCode;
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

void TestLeetCode282(void)
{
    Logger::WriteMessage("Test Leet Code 282");
    LeetCode leetCode;

    string num = "232";
    int target = 8;
    vector<string> result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);

    num = "123";
    target = 6;
    result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);


    num = "105";
    target = 5;
    result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);

    num = "00";
    target = 0;
    result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);

    num = "3456237490";
    target = 9191;
    result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);
}


void TestLeetCode386(void)
{
    Logger::WriteMessage("Test Leet Code 386");
    LeetCode leetCode;
    int n = 220;
    vector<int> result = leetCode.lexicalOrder(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode435(void)
{
    Logger::WriteMessage("Test Leet Code 435");
    LeetCode leetCode;
    vector <Interval> intervals = { { 1, 2 },{ 2, 3 },{ 3, 4 },{ 1, 3 } };
    int count = leetCode.eraseOverlapIntervals(intervals);
    Logger::WriteMessage("Remove " + to_string(count) + " intervals");

    intervals = { { 1, 2 },{ 1, 2 },{ 1, 2 } };
    count = leetCode.eraseOverlapIntervals(intervals);
    Logger::WriteMessage("Remove " + to_string(count) + " intervals");

    intervals = { { 1, 2 },{ 2, 3 } };
    count = leetCode.eraseOverlapIntervals(intervals);
    Logger::WriteMessage("Remove " + to_string(count) + " intervals");
}


void TestLeetCode452(void)
{
    Logger::WriteMessage("Test Leet Code 452");
    LeetCode leetCode;
    vector<pair<int, int>> points = { {10, 16},{2, 8},{1, 6},{7, 12} };
    Logger::WriteMessage(points);
    int result = leetCode.findMinArrowShots(points);
    Logger::WriteMessage("Min Arrow Shots = " + to_string(result));
}

void TestLeetCode301(void)
{
    Logger::WriteMessage("Test Leet Code 301");
    LeetCode leetCode;
    string s = "()())()";
    vector<string> result = leetCode.removeInvalidParentheses(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    s = "(a)())()";
    result = leetCode.removeInvalidParentheses(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    s = ")(";
    result = leetCode.removeInvalidParentheses(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);
                      
    s = "(r(()()(";
    result = leetCode.removeInvalidParentheses(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);
}

void TestLeetCode359(void)
{
    Logger::WriteMessage("Test Leet Code 359");
    Logger1 logger;
    bool result;
    result = logger.shouldPrintMessage(1, "foo"); 
    result = logger.shouldPrintMessage(2,"bar"); 
    result = logger.shouldPrintMessage(3,"foo"); 
    result = logger.shouldPrintMessage(8,"bar"); 
    result = logger.shouldPrintMessage(10, "foo");
    result = logger.shouldPrintMessage(11, "foo");
}

void TestLeetCode362(void)
{
    Logger::WriteMessage("Test Leet Code 362");
    HitCounter counter;
    int result;
    counter.hit(1);
    counter.hit(2);
    counter.hit(3);
    result = counter.getHits(4);
    Logger::WriteMessage("Get Hits(4)" + to_string(result));
    counter.hit(300);
    result = counter.getHits(300);
    Logger::WriteMessage("Get Hits(300)" + to_string(result));
    result = counter.getHits(301);
    Logger::WriteMessage("Get Hits(301)" + to_string(result));
}

void TestLeetCode346(void)
{
    Logger::WriteMessage("Test Leet Code 346");
    MovingAverage m(3);
    Logger::WriteMessage("MovingAverage(3)");
    double result;
    result = m.next(1);
    Logger::WriteMessage("m.next(1)" + to_string(result));
    result = m.next(10);
    Logger::WriteMessage("m.next(10)" + to_string(result));
    result = m.next(3);
    Logger::WriteMessage("m.next(3)" + to_string(result));
    result = m.next(5);
    Logger::WriteMessage("m.next(5)" + to_string(result));
}

void TestLeetCode266(void)
{
    Logger::WriteMessage("Test Leet Code 266");
    LeetCode leetCode;
    string s = "code";
    bool result = leetCode.canPermutePalindrome(s);
    Logger::WriteMessage(s + "->" + (string) (result? "true":"false"));
    s = "aab";
    result = leetCode.canPermutePalindrome(s);
    Logger::WriteMessage(s + "->" + (string)(result ? "true" : "false"));
    s = "carerac";
    result = leetCode.canPermutePalindrome(s);
    Logger::WriteMessage(s + "->" + (string)(result ? "true" : "false"));
}

void TestLeetCode244(void)
{
    Logger::WriteMessage("Test Leet Code 244");
    vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
    WordDistance wordDistance(words);
    string word1 = "coding";
    string word2 = "practice";
    int distance = wordDistance.shortest(word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));

    word1 = "makes";
    word2 = "coding";
    distance = wordDistance.shortest(word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));
}

void TestLeetCode252(void)
{
    Logger::WriteMessage("Test Leet Code 252");
    LeetCode leetCode;
    vector<Interval> intervals = { { 0, 30 },{ 5, 10 },{ 15, 20 } };
    Logger::WriteMessage(intervals);
    bool result = leetCode.canAttendMeetings(intervals);
    Logger::WriteMessage((string)(result? "Can" : "Can not") + " attend all the meetings");
}

void TestLeetCode246(void)
{
    Logger::WriteMessage("Test Leet Code 246");
    LeetCode leetCode;
    string s = "6801089";
    bool result = leetCode.isStrobogrammatic(s);
    Logger::WriteMessage("s=" + s + "; It " + (string)(result ? "is" : "is not") + " strobogrammatic");
    s = "6803089";
    result = leetCode.isStrobogrammatic(s);
    Logger::WriteMessage("s=" + s + "; It " + (string)(result ? "is" : "is not") + " strobogrammatic");
}


void TestLeetCode249(void)
{
    Logger::WriteMessage("Test Leet Code 249");
    LeetCode leetCode;
    vector<string> strings = { "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
    Logger::WriteMessage(strings);
    vector<vector<string>> result = leetCode.groupStrings(strings);
    Logger::WriteMessage(result);
}

void TestLeetCode270(void)
{
    Logger::WriteMessage("Test Leet Code 270");
    LeetCode leetCode;
    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    double target = 100;
    int result = leetCode.closestValue(root, target);
    Logger::WriteMessage("Closet value:" + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode422(void)
{
    Logger::WriteMessage("Test Leet Code 422");
    LeetCode leetCode;
    vector<string> words = { "abcd",  "bnrt", "crmy",  "dtye" };
    bool isWordSquare = leetCode.validWordSquare(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("It is" + (string)(isWordSquare? " ": " not ") + "a valid word square");

    words = { "abcd",  "bnrt", "crm",  "dt" };
    isWordSquare = leetCode.validWordSquare(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("It is" + (string)(isWordSquare ? " " : " not ") + "a valid word square");

    words = { "ball",  "area", "read",  "lady" };
    isWordSquare = leetCode.validWordSquare(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("It is" + (string)(isWordSquare ? " " : " not ") + "a valid word square");
}


void TestLeetCode408(void)
{
    Logger::WriteMessage("Test Leet Code 288");
    string word = "internationalization";
    string abbr = "i12iz4n";
    LeetCode leetCode;
    bool result = leetCode.validWordAbbreviation(word, abbr);
    Logger::WriteMessage("word = " + word + "; abbr = " + abbr + "; validWordAbbreviation = " + (string)(result ? "true" :"false"));
    
    word = "apple";
    abbr = "a2e";
    result = leetCode.validWordAbbreviation(word, abbr);
    Logger::WriteMessage("word = " + word + "; abbr = " + abbr + "; validWordAbbreviation = " + (string)(result ? "true" : "false"));

    word = "internationalization";
    abbr = "i5a11o1";
    result = leetCode.validWordAbbreviation(word, abbr);
    Logger::WriteMessage("word = " + word + "; abbr = " + abbr + "; validWordAbbreviation = " + (string)(result ? "true" : "false"));

    word = "hi";
    abbr = "1";
    result = leetCode.validWordAbbreviation(word, abbr);
    Logger::WriteMessage("word = " + word + "; abbr = " + abbr + "; validWordAbbreviation = " + (string)(result ? "true" : "false"));

}

void TestLeetCode476(void)
{
    Logger::WriteMessage("Test Leet Code 476");
    LeetCode leetCode;
    int num = 5;
    int complement = leetCode.findComplement(num);
    Logger::WriteMessage("num = " + to_string(num) + "; complement = " + to_string(complement));

    num = 1;
    complement = leetCode.findComplement(num);
    Logger::WriteMessage("num = " + to_string(num) + "; complement = " + to_string(complement));
}

void TestLeetCode254(void)
{
    Logger::WriteMessage("Test Leet Code 254");
    LeetCode leetCode;
    int num = 1;
    vector<vector<int>> result = leetCode.getFactors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);

    num = 37;
    result = leetCode.getFactors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);

    num = 12;
    result = leetCode.getFactors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);

    num = 32;
    result = leetCode.getFactors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);
}

void TestLeetCode276(void)
{
    Logger::WriteMessage("Test Leet Code 276");
    LeetCode leetCode;
    int n = 3;
    int k = 3;
    int numWays = leetCode.numWays(n, k);;
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; numWays = " + to_string(numWays));
}

void TestLeetCode366(void)
{
    Logger::WriteMessage("Test Leet Code 366");
    LeetCode leetCode;
    string input = "[1,2,3,4,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.findLeaves(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode280(void)
{
    Logger::WriteMessage("Test Leet Code 280");
    LeetCode leetCode;
    vector<int> nums = { 3, 5, 2, 1, 6, 4 };
    Logger::WriteMessage(nums);
    leetCode.wiggleSort(nums);
    Logger::WriteMessage(nums);
}

void TestLeetCode370(void)
{
    Logger::WriteMessage("Test Leet Code 370");
    LeetCode leetCode;
    vector<vector<int>> updates = { {1, 3, 2}, {2, 4, 3}, {0, 2, -2} }; 
    int length = 5;
    vector<int> result = leetCode.getModifiedArray(length, updates);
    Logger::WriteMessage(updates);
    Logger::WriteMessage(result);
}



void TestLeetCode311(void)
{
    Logger::WriteMessage("Test Leet Code 311");
    LeetCode leetCode;
    vector<vector<int>> A = { {1, 0, 0 } , { -1, 0, 3 } };
    vector<vector<int>> B = { { 7, 0, 0 } ,{ 0, 0, 0 }, { 0, 0, 1 } };
    vector<vector<int>> C = leetCode.multiply(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(C);
}

void TestLeetCode320(void)
{
    Logger::WriteMessage("Test Leet Code 320");
    LeetCode leetCode;

    string word = "word";
    vector<string> result = leetCode.generateAbbreviations(word);
    Logger::WriteMessage("word = " + word);
    Logger::WriteMessage(result);
}


void TestLeetCode221(void)
{
    Logger::WriteMessage("Test Leet Code 221");
    LeetCode leetCode;
    vector<vector<char>> matrix  =
    {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1' ,'1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' }
    };
    int max_area = leetCode.maximalSquare(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("max_area = " + to_string(max_area));
}

void TestLeetCode334(void)
{
    Logger::WriteMessage("Test Leet Code 334");
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    bool result = leetCode.increasingTriplet(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("It" + (string)(result ? " is ": "  is not ") + "increasing triple");

    nums = { 5, 4, 3, 2, 1 };
    result = leetCode.increasingTriplet(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("It" + (string)(result ? " is " : "  is not ") + "increasing triple");
}

void TestLeetCode473(void)
{
    Logger::WriteMessage("Test Leet Code 473");
    LeetCode leetCode;
    vector<int> nums = { 2, 2, 2, 2, 2, 6 };
    bool result = leetCode.makesquare(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("It" + (string)(result ? " can " : " can not ") + "make sqaure");

    nums = { 1,1,2,2,2 };
    result = leetCode.makesquare(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("It" + (string)(result ? " can " : " can not ") + "make sqaure");

    nums = { 3,3,3,3,4 };
    result = leetCode.makesquare(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("It" + (string)(result ? " can " : " can not ") + "make sqaure");

}

void TestLeetCode259(void)
{
    Logger::WriteMessage("Test Leet Code 259");
    LeetCode leetCode;
    vector<int> nums = { -2, 0, 1, 3 };
    int target = 2;
    int result = leetCode.threeSumSmaller(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Target = " + to_string(target) + "; Number of triples smaller than target = " + to_string(result));
}

void TestLeetCode156(void)
{
    Logger::WriteMessage("Test Leet Code 156");
    LeetCode leetCode;
    string input = "[1,2,3,4,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    root = leetCode.upsideDownBinaryTree(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("Upside Down Path:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode250(void)
{
    Logger::WriteMessage("Test Leet Code 250");
    LeetCode leetCode;
    string input = "[5,1,5,5,5,null,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.countUnivalSubtrees(root);
    Logger::WriteMessage("Count Unique Value Subtrees:" + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode298(void)
{
    Logger::WriteMessage("Test Leet Code 298");
    LeetCode leetCode;
    string input = "[1,null,3,2,4,null,null,null,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.longestConsecutive(root);
    Logger::WriteMessage("Longest Consecutive Subtrees:" + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[2,null,3,2,null,1,null]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.longestConsecutive(root);
    Logger::WriteMessage("Longest Consecutive Subtrees:" + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode255(void)
{
    Logger::WriteMessage("Test Leet Code 255");
    LeetCode leetCode;
    vector<int> nums = { 4, 2, 1, 3, 6, 5, 7 };
    bool result = leetCode.verifyPreorder(nums);
    Logger::WriteMessage("It" + (string)(result? " is ":" is not ") + "preorder traverse." );
}


void TestLeetCode314(void)
{
    Logger::WriteMessage("Test Leet Code 314");
    LeetCode leetCode;
    string input = "[3,9,20,null,null,15,7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.verticalOrder(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
    
    input = "[3, 9, 8, 4, 0, 1, 7]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.verticalOrder(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[3,9,8,4,0,1,7,null,null,null,2,5]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.verticalOrder(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode333(void)
{
    Logger::WriteMessage("Test Leet Code 333");
    LeetCode leetCode;
    string input = "[10,5,15,1,8,null,7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.largestBSTSubtree(root);
    Logger::WriteMessage("Largest BST Subtree = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode285(void)
{
    Logger::WriteMessage("Test Leet Code 285");
    LeetCode leetCode;
    string input = "[4, 2, 6, 1, 3, 5, 7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    TreeNode * node = new TreeNode(3);
    TreeNode * next_node = leetCode.inorderSuccessor(root, node);
    Logger::WriteMessage("Next node of " + to_string(node->val) + " is " + (string)(next_node == nullptr? "null" : to_string(next_node->val)));
    leetCode.freeTreeNodes(node);

    node = new TreeNode(4);
    next_node = leetCode.inorderSuccessor(root, node);
    Logger::WriteMessage("Next node of " + to_string(node->val) + " is " + (string)(next_node == nullptr ? "null" : to_string(next_node->val)));
    leetCode.freeTreeNodes(node);

    node = new TreeNode(7);
    next_node = leetCode.inorderSuccessor(root, node);
    Logger::WriteMessage("Next node of " + to_string(node->val) + " is " + (string)(next_node == nullptr ? "null" : to_string(next_node->val)));
    leetCode.freeTreeNodes(node);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode481(void)
{
    Logger::WriteMessage("Test Leet Code 481");
    LeetCode leetCode;
    int n = 20;
    int result = leetCode.magicalString(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode256(void)
{
    Logger::WriteMessage("Test Leet Code 256");
    LeetCode leetCode;
    vector<vector<int>> costs = { {1,2,3}, {4, 1, 2} , {7, 9, 2} };
    Logger::WriteMessage(costs);
    int min_cost = leetCode.minCost(costs);
    Logger::WriteMessage("Minimum Cost = " + to_string(min_cost));
}

void TestLeetCode9901(void)
{
    Logger::WriteMessage("Test Leet Code 9901");
    LeetCode leetCode;
    vector<int> nums = { 1,2,-3, 4, -1 };
    Logger::WriteMessage(nums);
    int result = leetCode.getMaxExprResult(nums);
    Logger::WriteMessage("Maximum Result = " + to_string(result));
}

void TestLeetCode163(void)
{
    Logger::WriteMessage("Test Leet Code 163");
    LeetCode leetCode;
    vector<int> nums = { 0, 1, 3, 50, 75 };
    int lower = 0, upper = 99;
    Logger::WriteMessage(nums);
    vector<string> result = leetCode.findMissingRanges(nums, lower, upper);
    Logger::WriteMessage(result);
}

void TestLeetCode267(void)
{
    Logger::WriteMessage("Test Leet Code 267");
    LeetCode leetCode;
    string s = "aabbbbcz";
    vector<string> result;
    Logger::WriteMessage("s = " + s);
    result = leetCode.generatePalindromes(s);
    Logger::WriteMessage(result);
} 

void TestLeetCode294(void)
{
    Logger::WriteMessage("Test Leet Code 294");
    LeetCode leetCode;
    string s = "++++++";
    Logger::WriteMessage("s = " + s);
    bool result = leetCode.canWin(s);
    Logger::WriteMessage("Can Win = " + (string)(result ? "true" : "false"));
}

void TestLeetCode157(void)
{
    Logger::WriteMessage("Test Leet Code 157");
    LeetCode leetCode;
    string s = "abcdefghijklmnopqrstuvwxyz";
    int n= 9;
    char buff[256];
    int n_read = leetCode.readNChars(buff, n, s);
    Logger::WriteMessage("buff = " + (string)buff);
}

void TestLeetCode158(void)
{
    Logger::WriteMessage("Test Leet Code 158");
    LeetCode leetCode;
    string s = "abcdefghijklmnopqrstuvwxyz";
    Logger::WriteMessage("s = " + s);
    char buff[256];
    int n = 3;
    int index = 0;
    string m_buffer;
    int n_read = leetCode.readNCharsII(buff, n, s, index, m_buffer);
    Logger::WriteMessage("buff = " + (string)buff);

    n = 1;
    n_read = leetCode.readNCharsII(buff, n, s, index, m_buffer);
    Logger::WriteMessage("buff = " + (string)buff);

    n = 5;
    n_read = leetCode.readNCharsII(buff, n, s, index, m_buffer);
    Logger::WriteMessage("buff = " + (string)buff);
}

void TestLeetCode253(void)
{
    Logger::WriteMessage("Test Leet Code 253");
    LeetCode leetCode;
    vector<Interval> meetings = { { 14, 20 },{ 6, 14 },{ 4, 9 } };
    int min_rooms = leetCode.minMeetingRooms(meetings);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("minimum meeting rooms:" + to_string(min_rooms));

    meetings = { { 0, 30 },{5, 10}, {15, 20} };
    min_rooms = leetCode.minMeetingRooms(meetings);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("minimum meeting rooms:" + to_string(min_rooms));
}

void TestLeetCode159(void)
{
    Logger::WriteMessage("Test Leet Code 159");
    LeetCode leetCode;
    string s = "eceba";
    int max_length = leetCode.lengthOfLongestSubstringTwoDistinct(s);
    Logger::WriteMessage("s = " + s + "; max_length = " + to_string(max_length));
}

void TestLeetCode340(void)
{
    Logger::WriteMessage("Test Leet Code 340");
    LeetCode leetCode;
    string s = "eceba";
    int k = 2;
    int max_length = leetCode.lengthOfLongestSubstringKDistinct(s, k);
    Logger::WriteMessage("s = " + s + "; max_length = " + to_string(max_length));
}

void TestLeetCode265(void)
{
    Logger::WriteMessage("Test Leet Code 265");
    LeetCode leetCode;
    vector<vector<int>> costs = { { 8 }};
    Logger::WriteMessage(costs);
    int min_cost = leetCode.minCostII(costs);
    Logger::WriteMessage("Minimum Cost = " + to_string(min_cost));

    costs = { { 1,2,3 },{ 4, 1, 2 } ,{ 7, 9, 2 } };
    Logger::WriteMessage(costs);
    min_cost = leetCode.minCostII(costs);
    Logger::WriteMessage("Minimum Cost = " + to_string(min_cost));
}

void TestLeetCode161(void)
{
    Logger::WriteMessage("Test Leet Code 161");
    LeetCode leetCode;
    string s = "abcde";
    string t = "abce";

    bool isOneEditDistance = leetCode.isOneEditDistance(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + ";" + (string)(isOneEditDistance ? " is " : " is not ") + "one distance");

    s = "bat";
    t = "bot";
    isOneEditDistance = leetCode.isOneEditDistance(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + ";" + (string)(isOneEditDistance ? " is " : " is not ") + "one distance");
 
    s = "aaaaaaaaa";
    t = "aaaaaaaaaa";
    isOneEditDistance = leetCode.isOneEditDistance(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + ";" + (string)(isOneEditDistance ? " is " : " is not ") + "one distance");         

    s = "a";
    t = "ac";
    isOneEditDistance = leetCode.isOneEditDistance(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + ";" + (string)(isOneEditDistance ? " is " : " is not ") + "one distance");
}

void TestLeetCode487(void)
{
    Logger::WriteMessage("Test Leet Code 487");
    LeetCode leetCode;
    vector<int> nums = { 1, 0, 1, 1, 0 };
    Logger::WriteMessage(nums);
    int max_length = leetCode.findMaxConsecutiveOnesII(nums);
    Logger::WriteMessage("maximum consecutiveones II = " + to_string(max_length));
}

void TestLeetCode247(void)
{
    Logger::WriteMessage("Test Leet Code 247");
    LeetCode leetCode;
    int n = 3;
    vector<string> result = leetCode.findStrobogrammatic(n);
    Logger::WriteMessage(result);
}

void TestLeetCode248(void)
{
    Logger::WriteMessage("Test Leet Code 248");
    LeetCode leetCode;
    string low = "50", high = "100";
    int count = leetCode.strobogrammaticInRange(low, high);
    Logger::WriteMessage("count = " + to_string(count));
}

void TestLeetCode321(void)
{
    Logger::WriteMessage("Test Leet Code 321");
    LeetCode leetCode;
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

void TestLeetCode291(void)
{
    Logger::WriteMessage("Test Leet Code 291");
    LeetCode leetCode;
    string pattern = "abab", str = "redblueredblue";
    bool match = leetCode.wordPatternMatch(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; match = " + (match? "true" :"false"));
    pattern = "aaaa", str = "asdasdasdasd";
    match = leetCode.wordPatternMatch(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; match = " + (match ? "true" : "false"));
    pattern = "aabb", str = "xyzabcxzyabc";
    match = leetCode.wordPatternMatch(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; match = " + (match ? "true" : "false"));
}

void TestLeetCode418(void)
{
    Logger::WriteMessage("Test Leet Code 418");
    LeetCode leetCode;
    int rows = 2, cols = 8;
    vector<string> sentence = { "hello", "world" };
    int count = leetCode.wordsTyping(sentence, rows, cols);
    Logger::WriteMessage(sentence);
    Logger::WriteMessage("rows = " + to_string(rows) + "; cols = " + to_string(cols) + "; sentence count = " + to_string(count));

    rows = 3, cols = 6;
    sentence = { "a", "bcd", "e" };
    count = leetCode.wordsTyping(sentence, rows, cols);
    Logger::WriteMessage(sentence);
    Logger::WriteMessage("rows = " + to_string(rows) + "; cols = " + to_string(cols) + "; sentence count = " + to_string(count));

    rows = 4, cols = 5;
    sentence = { "I", "had", "apple", "pie" };
    count = leetCode.wordsTyping(sentence, rows, cols);
    Logger::WriteMessage(sentence);
    Logger::WriteMessage("rows = " + to_string(rows) + "; cols = " + to_string(cols) + "; sentence count = " + to_string(count));
}

void TestLeetCode467(void)
{
    Logger::WriteMessage("Test Leet Code 467");
    LeetCode leetCode;
    string s = "a";
    int str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));

    s = "cac";
    str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));

    s = "zab";
    str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));

    s = "abcdefghijklmnopqrstuvwxyz";
    str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));     

    s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));
}

void TestLeetCode484(void)
{
    Logger::WriteMessage("Test Leet Code 484");

    string s = "I";
    LeetCode leetCode;
    vector<int> nums = leetCode.findPermutation(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(nums);

    s = "DI";
    nums = leetCode.findPermutation(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(nums);

    s = "DDIIDI";
    nums = leetCode.findPermutation(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(nums);
}

void TestLeetCode500(void)
{
    Logger::WriteMessage("Test Leet Code 500");
    LeetCode leetCode;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> result = leetCode.findWordsInOneRow(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCode375(void)
{
    Logger::WriteMessage("Test Leet Code 375");
    LeetCode leetCode;
    int n = 10;
    int money = leetCode.getMoneyAmount(n);
    Logger::WriteMessage("n = " + to_string(n) + "; money = " + to_string(money));
}

void TestLeetCode506(void)
{
    Logger::WriteMessage("Test Leet Code 506");
    LeetCode leetCode;
    vector<int> nums = { 5,3,4,2,1 };
    vector<string> ranks = leetCode.findRelativeRanks(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(ranks);
}

void TestLeetCode501(void)
{
    Logger::WriteMessage("Test Leet Code 501");
    LeetCode leetCode;
    string input = "[1,null,2,2]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    vector<int> result = leetCode.findMode(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode508(void)
{
    Logger::WriteMessage("Test Leet Code 508");
    LeetCode leetCode;
    string input = "[5,2,-3]";
    TreeNode * root = leetCode.deserialize(input);
    vector<int> result = leetCode.findFrequentTreeSum(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[5,2,-5]";
    root = leetCode.deserialize(input);
    result = leetCode.findFrequentTreeSum(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode495(void)
{
    Logger::WriteMessage("Test Leet Code 495");
    LeetCode leetCode;
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

void TestLeetCode498(void)
{
    Logger::WriteMessage("Test Leet Code 498");
    LeetCode leetCode;
    vector<vector<int>> matrix = 
    {
        { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }
    };
    vector<int> result = leetCode.findDiagonalOrder(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);
}

void TestLeetCode308(void)
{
    Logger::WriteMessage("Test Leet Code 308");
    vector<vector<int>> matrix =
    {
        { 3, 0, 1, 4, 2 },
        { 5, 6, 3, 2, 1 },
        { 1, 2, 0, 1, 5 }, 
        { 4, 1, 0, 1, 7 }, 
        { 1, 0, 3, 0, 5 }
    };
    NumMatrixMutable numMatrix = NumMatrixMutable(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("sumRegion(2, 1, 4, 3) -> " + to_string(numMatrix.sumRegion(2, 1, 4, 3)));
    numMatrix.update(3, 2, 2);
    Logger::WriteMessage("sumRegion(2, 1, 4, 3) -> " + to_string(numMatrix.sumRegion(2, 1, 4, 3)));
}

void TestLeetCode411(void)
{
    Logger::WriteMessage("Test Leet Code 411");
    LeetCode leetCode;
    string target = "apple";
    vector<string> dictionary = { "blade" };
    string abbr = leetCode.minAbbreviation(target, dictionary);
    Logger::WriteMessage("target = " + target);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("abbreviation = " + abbr);

    target = "apple";
    dictionary = { "plain", "amber", "blade" };
    abbr = leetCode.minAbbreviation(target, dictionary);
    Logger::WriteMessage("target = " + target);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("abbreviation = " + abbr);

    target = "leetcode";
    dictionary = { "lyftcode", "leetcold", "litecode", "lietcode", "leetccod", "lyftcold" };
    abbr = leetCode.minAbbreviation(target, dictionary);
    Logger::WriteMessage("target = " + target);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("abbreviation = " + abbr);

    target = "abcdefghijklmnop";
    dictionary = { };
    abbr = leetCode.minAbbreviation(target, dictionary);
    Logger::WriteMessage("target = " + target);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("abbreviation = " + abbr);
}

void TestLeetCode515(void)
{
    Logger::WriteMessage("Test Leet Code 515");
    LeetCode leetCode;
    string input = "[1,3,2,5,3,null,9]";
    TreeNode * root = leetCode.deserialize(input);
    vector<int> result = leetCode.largestValues(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode513(void)
{
    Logger::WriteMessage("Test Leet Code 513");
    LeetCode leetCode;
    string input = "[2,1,3]";
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.findBottomLeftValue(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1, 2, 3, 4, null, 5, 6, null, null, 7]";
    root = leetCode.deserialize(input);
    result = leetCode.findBottomLeftValue(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode272(void)
{
    Logger::WriteMessage("Test Leet Code 270");
    LeetCode leetCode;
    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    double target = 3.2;
    int k = 3;
    vector<int> result = leetCode.closestKValues(root, target, k);
    Logger::WriteMessage("target = " + to_string(target) + "; k = " + to_string(k));
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode496(void)
{
    Logger::WriteMessage("Test Leet Code 496");
    LeetCode leetCode;
    vector<int> nums1 = { 4, 1, 2 };
    vector<int> nums2 = { 1, 3, 4, 2 };
    vector<int> result = leetCode.nextGreaterElement(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);

    nums1 = { 2, 4 };
    nums2 = { 1, 2, 3, 4 };
    result = leetCode.nextGreaterElement(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(result);
}

void TestLeetCode503(void)
{
    Logger::WriteMessage("Test Leet Code 503");
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 1 };
    vector<int> result = leetCode.nextGreaterElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode488(void)
{
    Logger::WriteMessage("Test Leet Code 488");
    LeetCode leetCode;
    string board = "RBBRYRWWYYWRYY";
    string hand = "RYBBR";
    int min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));

        
    board = "WRRBBW";
    hand = "RB";
    min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));

    board = "WWRRBBWW";
    hand = "WRBRW";
    min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));

    board = "G";
    hand = "GGGGG";
    min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));

    board = "RBYYBBRRB";
    hand = "YRBGB";
    min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));
}


void TestLeetCode358(void)
{
    Logger::WriteMessage("Test Leet Code 358");
    LeetCode leetCode;
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

void TestLeetCode465(void)
{
    Logger::WriteMessage("Test Leet Code 465");
    LeetCode leetCode;
    vector<vector<int>> transactions = { { 2, 0, 5 },{ 3, 4, 4 } };
    int result = leetCode.minTransfers(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage("min transfers = " + to_string(result));

    transactions = { { 0,1,10 },{ 2,0,5 } };
    result = leetCode.minTransfers(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage("min transfers = " + to_string(result));

    transactions = { {0,1,10},{1,0,1},{1,2,5},{2,0,5} };
    result = leetCode.minTransfers(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage("min transfers = " + to_string(result));
}

void TestLeetCode472(void)
{
    Logger::WriteMessage("Test Leet Code 472");
    LeetCode leetCode;
    vector<string> words = { "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
    vector<string> result = leetCode.findAllConcatenatedWordsInADict(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    words = { "" };
    result = leetCode.findAllConcatenatedWordsInADict(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCode351(void)
{
    Logger::WriteMessage("Test Leet Code 351");
    LeetCode leetCode;
    int m = 1;
    int n = 2;
    int result = leetCode.numberOfPatterns(m, n);
    Logger::WriteMessage("m = " + to_string(m) + ";n = " + to_string(n) + ";result =" + to_string(result));
}

void TestLeetCode309(void)
{
    Logger::WriteMessage("Test Leet Code 351");
    LeetCode leetCode;
    vector<int> prices = { 1, 2, 3, 0, 2 };
    int max_profit = leetCode.maxProfit(prices);
    Logger::WriteMessage(prices);    
    Logger::WriteMessage("max profit = " + to_string(max_profit));
}

void TestLeetCode363(void)
{
    Logger::WriteMessage("Test Leet Code 363");
    LeetCode leetCode;
    vector<vector<int>> matrix = 
    { 
        { 1,  0, 1 },
        { 0, -2, 3 }
    };
    int k = 2;
    int result = leetCode.maxSumSubmatrixII(matrix, k);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("k = " + to_string(k) + "; max sum no larger than k = " + to_string(result));
}

void TestLeetCode471(void)
{
    Logger::WriteMessage("Test Leet Code 471");
    LeetCode leetCode;   
    
    string s = "aaaaaaaaaabbbaaaaabbb";
    string result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "abbbabbbcabbbabbbc";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "aabcaabcd";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "aaaaaaaaaa";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "aaa";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "aaaaa";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);
}

void TestLeetCode440(void)
{
    Logger::WriteMessage("Test Leet Code 440");
    LeetCode leetCode;
    int n = 13;
    int k = 2;
    int result = leetCode.findKthNumber(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 13;
    k = 7;
    result = leetCode.findKthNumber(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode466(void)
{
    Logger::WriteMessage("Test Leet Code 466");
    LeetCode leetCode;
    string s1 = "acb";
    int n1 = 4;
    string s2 = "ab";
    int n2 = 2;
    int result = leetCode.getMaxRepetitions(s1, n1, s2, n2);
    Logger::WriteMessage("s1 = " + s1 + "; n1 = " + to_string(n1) + "; s2 = " + s2 + 
        "; n2 = " + to_string(n2) + "; result = " + to_string(result));
}

void TestLeetCode502(void)
{
    Logger::WriteMessage("Test Leet Code 502");
    LeetCode leetCode;
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

void TestLeetCode517(void)
{
    Logger::WriteMessage("Test Leet Code 517");
    LeetCode leetCode;
    vector<int> nums = { 1,0,5 };
    Logger::WriteMessage(nums);
    int result = leetCode.findMinMoves(nums);
    Logger::WriteMessage("Minimum Move =" + to_string(result));
    
    nums = { 9, 1, 8, 8, 9 };
    Logger::WriteMessage(nums);
    result = leetCode.findMinMoves(nums);
    Logger::WriteMessage("Minimum Move =" + to_string(result));

    nums = { 0,3,0 };
    Logger::WriteMessage(nums);
    result = leetCode.findMinMoves(nums);
    Logger::WriteMessage("Minimum Move =" + to_string(result));

    nums = { 0,2,0 };
    Logger::WriteMessage(nums);
    result = leetCode.findMinMoves(nums);
    Logger::WriteMessage("Minimum Move =" + to_string(result));
}


void TestLeetCode531(void)
{
    Logger::WriteMessage("Test Leet Code 531");
    LeetCode leetCode;
    vector<vector<char>> picture =
    {
      {'W', 'W', 'B'},
      {'W', 'B', 'W'},
      {'B', 'W', 'W'}
    };

    int result = leetCode.findLonelyPixel(picture);
    Logger::WriteMessage(picture);
    Logger::WriteMessage("lonely pixel = " + to_string(result));
}

void TestLeetCode533(void)
{
    Logger::WriteMessage("Test Leet Code 533");
    LeetCode leetCode;
    vector<vector<char>> picture =
    {
        {'W','B','B','W','W','B','W','W','W','W','W','B','B','W','W'},
        {'W','B','B','W','W','B','W','W','W','W','W','B','B','W','W'},
        {'W','W','W','W','W','B','B','B','W','B','W','W','W','W','B'},    
        {'W','W','B','W','B','W','W','W','W','B','B','W','B','W','W'},
        {'W','B','B','W','W','B','W','W','W','W','W','B','B','W','W'},
        {'W','W','B','W','B','W','W','W','W','B','B','W','B','W','W'},
        {'W','W','B','W','B','W','W','W','W','B','B','W','B','W','W'},
        {'W','W','B','W','B','W','W','W','W','B','B','W','B','W','W'}
    };
    int N = 5;
    int result = leetCode.findLonelyPixel(picture, N);
    Logger::WriteMessage(picture);
    Logger::WriteMessage("N = " + to_string(N) + "; lonely pixel = " + to_string(result));

    picture =
    {
        { 'W', 'B', 'W', 'B', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'B', 'W' },
        { 'W', 'W', 'B', 'W', 'B', 'W' }
    };
    N = 3;
    result = leetCode.findLonelyPixel(picture, N);
    Logger::WriteMessage(picture);
    Logger::WriteMessage("N = " + to_string(N) + "; lonely pixel = " + to_string(result));
}

void TestLeetCode532(void)
{
    Logger::WriteMessage("Test Leet Code 532");
    LeetCode leetCode;
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

void TestLeetCode530(void)
{
    Logger::WriteMessage("Test Leet Code 530");
    LeetCode leetCode;
    string input = "[1,null,3,2,null]";
    Logger::WriteMessage(input);
    TreeNode *root = leetCode.deserialize(input);
    int min_value = leetCode.getMinimumDifference(root);
    Logger::WriteMessage("min_value = " + to_string(min_value));
}

void TestLeetCode524(void)
{
    Logger::WriteMessage("Test Leet Code 524");
    LeetCode leetCode;
    string s = "abpcplea";
    vector<string> d = { "ale", "apple", "monkey", "plea" };
    string result = leetCode.findLongestWord(s, d);
    Logger::WriteMessage(d);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode257(void)
{
    LeetCode leetCode;
    string input = "[1,2,3,null,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    vector<string> tree_paths = leetCode.binaryTreePaths(root);
    Logger::WriteMessage("Tree Path:");
    Logger::WriteMessage(tree_paths);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode541(void)
{
    LeetCode leetCode;
    string s = "abcdefg";
    int k = 2;
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    string result = leetCode.reverseStr(s, k);
    Logger::WriteMessage("reverse = " + result);
}

void TestLeetCode527(void)
{
    LeetCode leetCode;
    vector<string> dict =
    {
        "like", "god", "internal", "me", "internet",
        "interval", "intension", "face", "intrusion"
    };
    vector<string> result = leetCode.wordsAbbreviation(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage(result);

    dict =
    {
        "aa", "aaa"
    };
    result = leetCode.wordsAbbreviation(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage(result);

    dict =
    {
        "meet", "met"
    };
    result = leetCode.wordsAbbreviation(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage(result);
}


void TestLeetCode536(void)
{
    LeetCode leetCode;
    string s = "4(2(3)(1))(6(5))";
    TreeNode * root = leetCode.str2tree(s);
    string result = leetCode.serialize(root);
    Logger::WriteMessage(s);
    Logger::WriteMessage(result);

    s = "4(2(3)())(6(5))";
    root = leetCode.str2tree(s);
    result = leetCode.serialize(root);
    Logger::WriteMessage(s);
    Logger::WriteMessage(result);

    s = "";
    root = leetCode.str2tree(s);
    result = leetCode.serialize(root);
    Logger::WriteMessage(s);
    Logger::WriteMessage(result);
}

void TestLeetCode539(void)
{
    LeetCode leetCode;
    vector<string> timePoints = { "23:59","8:13","00:00" };
    int diff = leetCode.findMinDifference(timePoints);
    Logger::WriteMessage(timePoints);
    Logger::WriteMessage("diff = " + to_string(diff));
}

void TestLeetCode544(void)
{
    LeetCode leetCode;
    int n = 8;
    string result = leetCode.findContestMatch(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + result);
}

void TestLeetCode545(void)
{
    LeetCode leetCode;
    string input = "[1,2,3,4,5,6,null,null,null,7,8,9,10]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    vector<int> result = leetCode.boundaryOfBinaryTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,null, 2, 3, 4]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    result = leetCode.boundaryOfBinaryTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    result = leetCode.boundaryOfBinaryTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode543(void)
{
    LeetCode leetCode;
    string input = "[1,2,3,4,5]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    int diameter = leetCode.diameterOfBinaryTree(root);
    Logger::WriteMessage("diameter = " + to_string(diameter));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode548(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1,2,1,2,1,2,1 };
    Logger::WriteMessage(nums);
    bool result = leetCode.splitArray(nums);
    Logger::WriteMessage("Can split into equal sum: " + (string)(result ? "true" : " false"));

    nums = { 1 };
    Logger::WriteMessage(nums);
    result = leetCode.splitArray(nums);
    Logger::WriteMessage("Can split into equal sum: " + (string)(result ? "true" : " false"));
}

void TestLeetCode538(void)
{
    LeetCode leetCode;
    string input = "[5, 2, 13]";
    Logger::WriteMessage("old tree: "+ input);
    TreeNode * root = leetCode.deserialize(input);
    TreeNode * new_root = leetCode.convertBST(root);
    string output = leetCode.serialize(new_root);
    Logger::WriteMessage("new tree: " + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(new_root);

    input = "[2, 0, 3, -4, 1]";
    Logger::WriteMessage("old tree: " + input);
    root = leetCode.deserialize(input);
    new_root = leetCode.convertBST(root);
    output = leetCode.serialize(new_root);
    Logger::WriteMessage("new tree: " + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(new_root);
}

void TestLeetCode521(void)
{
    LeetCode leetCode;
    string a = "aba";
    string b = "cdc";
    int result = leetCode.findLUSlength(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + to_string(result));
}

void TestLeetCode522(void)
{
    LeetCode leetCode;
    vector<string> strs = { "aba", "cdc", "eae" };
    int result = leetCode.findLUSlength(strs);
    Logger::WriteMessage(strs);
    Logger::WriteMessage("result = " + to_string(result));

    strs = { "abc", "abc", "ac", "d" };
    result = leetCode.findLUSlength(strs);
    Logger::WriteMessage(strs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode557(void)
{
    LeetCode leetCode;
    string s = "Let's take LeetCode contest";
    string result = leetCode.reverseWordsIII(s);
    Logger::WriteMessage(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode556(void)
{
    LeetCode leetCode;
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

void TestLeetCode549(void)
{
    LeetCode leetCode;
    string input = "[24,25,25,26,24,26,24,25,27,23,23,25,25,23,23,26,24,26,28,24,22,22,24,26,26,26,26,22,24,22,22,null,27,null,25,null,25,null,27,null,25,null,21,null,23,23,23,null,25,null,25,null,27,27,25,null,23,null,23,null,21,21,21]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    int max_length = leetCode.longestConsecutiveII(root);
    Logger::WriteMessage("Max Length = " + to_string(max_length));

    input = "[2,1,3]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    max_length = leetCode.longestConsecutiveII(root);
    Logger::WriteMessage("Max Length = " + to_string(max_length));

    input = "[3,2,4,1]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    max_length = leetCode.longestConsecutiveII(root);
    Logger::WriteMessage("Max Length = " + to_string(max_length));

    input = "[3,2,1,1]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    max_length = leetCode.longestConsecutiveII(root);
    Logger::WriteMessage("Max Length = " + to_string(max_length));
}

void TestLeetCode554(void)
{
    LeetCode leetCode;
    vector<vector<int>> wall = { { 1, 2, 2, 1 },{ 3, 1, 2 },{ 1, 3, 2 },{ 2, 4 },{ 3, 1, 2 },{ 1, 3, 1, 1 } };
    int min_bricks = leetCode.leastBricks(wall);
    Logger::WriteMessage(wall);
    Logger::WriteMessage("Least Bricks = " + to_string(min_bricks));
}

void TestLeetCode546(void)
{
    LeetCode leetCode;
    vector<int> boxes = { 1, 3, 2, 2, 2, 3, 4, 3, 1 };
    int max_score = leetCode.removeBoxes(boxes);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("Maximum Score = " + to_string(max_score));
}

void TestLeetCode555(void)
{
    LeetCode leetCode;
    vector<string> strs = { "abc", "xyz" };
    string max_str = leetCode.splitLoopedString(strs);
    Logger::WriteMessage(strs);
    Logger::WriteMessage("Max String = " + max_str);
}

void TestLeetCode551(void)
{
    LeetCode leetCode;
    string record = "PPALLP";
    bool reward = leetCode.checkRecord(record);
    Logger::WriteMessage("Record = " + record + "; Reward = " + (string)(reward ? "true" : "false"));

    record = "PPALLL";
    reward = leetCode.checkRecord(record);
    Logger::WriteMessage("Record = " + record + "; Reward = " + (string)(reward ? "true" : "false"));

    record = "LALL";
    reward = leetCode.checkRecord(record);
    Logger::WriteMessage("Record = " + record + "; Reward = " + (string)(reward ? "true" : "false"));

}

void TestLeetCode552(void)
{
    LeetCode leetCode;
    int n = 65;
    int result = leetCode.checkRecord(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode561(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1,4,3,2 };
    int sum = leetCode.arrayPairSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("sum of min = " + to_string(sum));
}

void TestLeetCode563(void)
{
    LeetCode leetCode;
    string input = "[1,2,3,null,null,4,5]";
    TreeNode * root = leetCode.deserialize(input);
    Logger::WriteMessage(input);
    int tilt = leetCode.findTilt(root);
    Logger::WriteMessage("tilt = " + to_string(tilt));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode572(void)
{
    LeetCode leetCode;
    string input = "[3,4,5,1,2,null,null]";
    Logger::WriteMessage("s = " + input);
    TreeNode * s = leetCode.deserialize(input);
    input = "[4,1,2]";
    Logger::WriteMessage("t = " + input);
    TreeNode * t = leetCode.deserialize(input);
    Logger::WriteMessage("t is subtree of s ? " + (string)(leetCode.isSubtree(s, t) ? "true" : "false"));
    leetCode.freeTreeNodes(s);
    leetCode.freeTreeNodes(t);

    input = "[3,4,5,1,2,null,null, 0, null]";
    Logger::WriteMessage("s = " + input);
    s = leetCode.deserialize(input);
    input = "[4,1,2]";
    Logger::WriteMessage("t = " + input);
    t = leetCode.deserialize(input);
    Logger::WriteMessage("t is subtree of s ? " + (string)(leetCode.isSubtree(s, t) ? "true" : "false"));
    leetCode.freeTreeNodes(s);
    leetCode.freeTreeNodes(t);
}

void TestLeetCode566(void)
{
    LeetCode leetCode;
    vector<vector<int>> nums = { { 1, 2 },{ 3, 4 } };
    vector<vector<int>> result = leetCode.matrixReshape(nums, 1, 4);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode575(void)
{
    LeetCode leetCode;
    vector<int> candies = { 1, 1, 2, 2, 3, 3 };
    int result = leetCode.distributeCandies(candies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("result = " + to_string(result));

    candies = { 1, 1, 2, 3 };
    result = leetCode.distributeCandies(candies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode581(void)
{
    LeetCode leetCode;
    vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
    Logger::WriteMessage(nums);
    int length = leetCode.findUnsortedSubarray(nums);
    Logger::WriteMessage("length = " + to_string(length));
}


void TestLeetCode594(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    int max_length = leetCode.findLHS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Longest_Harmonious_Subsequence = " + to_string(max_length));
}

void TestLeetCode583(void)
{
    LeetCode leetCode;
    string word1 = "sea", word2 = "eat";
    int result = leetCode.minDeleteDistance(word1, word2);

    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; min del distance = " + to_string(result));
}

void TestLeetCode567(void)
{
    LeetCode leetCode;
    string s1 = "ab", s2 = "eidbaooo";
    bool result = leetCode.checkInclusion(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "ab";
    s2 = "eidboaoo";
    result = leetCode.checkInclusion(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "adc";
    s2 = "dcda";
    result = leetCode.checkInclusion(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));
}


void TestLeetCode599(void)
{
    LeetCode leetCode;
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

void TestLeetCode598(void)
{
    LeetCode leetCode;
    int m = 3, n = 3;
    vector<vector<int>> ops = { { 2, 2 },{ 3, 3 } };
    int result = leetCode.maxCount(m, n, ops);

    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode600(void)
{
    LeetCode leetCode;
    int num = 5;
    int result = leetCode.findIntegers(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode609(void)
{
    LeetCode leetCode;
    vector<string> paths = { "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)" };
    Logger::WriteMessage(paths);
    vector<vector<string>> result = leetCode.findDuplicate(paths);
    Logger::WriteMessage(result);
}

void TestLeetCode605(void)
{
    LeetCode leetCode;
    vector<int> flowerbed = { 1, 0, 0, 0, 1 };
    int n = 1;
    Logger::WriteMessage(flowerbed);
    bool result = leetCode.canPlaceFlowers(flowerbed, n);
    Logger::WriteMessage("n = " + to_string(n) + ";" + (string)(result ? " can " : " can not ") + "place the flower");

    n = 2;
    Logger::WriteMessage(flowerbed);
    result = leetCode.canPlaceFlowers(flowerbed, n);
    Logger::WriteMessage("n = " + to_string(n) + ";" + (string)(result ? " can " : " can not ") + "place the flower");
}

void TestLeetCode606(void)
{
    LeetCode leetCode;
    string input = "[1,2,3,4]";
    TreeNode * root = leetCode.deserialize(input);
    string result = leetCode.tree2str(root);
    Logger::WriteMessage("input = " + input + "; result = " + result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,null,4]";
    root = leetCode.deserialize(input);
    result = leetCode.tree2str(root);
    Logger::WriteMessage("input = " + input + "; result = " + result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode617(void)
{
    LeetCode leetCode;
    string input = "[1,3,2,5,null]";
    TreeNode * tree1 = leetCode.deserialize(input);
    Logger::WriteMessage("tree1 = " + input);
    input = "[2,1,3,null,4,null,7]";
    TreeNode * tree2 = leetCode.deserialize(input);
    Logger::WriteMessage("tree2 = " + input);
    TreeNode * root = leetCode.mergeTrees(tree1, tree2);
    Logger::WriteMessage("result = " + leetCode.serialize(root));
    leetCode.freeTreeNodes(tree1);
    leetCode.freeTreeNodes(tree2);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode616(void)
{
    LeetCode leetCode;
    string s = "abcxyz123";
    vector<string> dict = { "abc", "123" };
    string result = leetCode.addBoldTag(s, dict);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("result = " + result);

    s = "aaabbcc";
    dict = { "aaa", "aab", "bc" };
    result = leetCode.addBoldTag(s, dict);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode621(void)
{
    LeetCode leetCode;
    vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
    int n = 2;
    int result = leetCode.leastInterval(tasks, n);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode623(void)
{
    LeetCode leetCode;
    string input = "[4,2,null,3,1]";
    TreeNode * root = leetCode.deserialize(input);
    root = leetCode.addOneRow(root, 1, 3);
    string output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("original tree = " + input + "; new tree = " + output);

    input = "[4,2,6,3,1,5,null]";
    root = leetCode.deserialize(input);
    root = leetCode.addOneRow(root, 1, 2);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("original tree = " + input + "; new tree = " + output);
}

void TestLeetCode624(void)
{
    LeetCode leetCode;
    vector<vector<int>> arrays = { { 1, 5 },{ 3, 4 } };
    Logger::WriteMessage(arrays);
    int maxDistance = leetCode.maxDistance(arrays);
    Logger::WriteMessage("maxDistance = " + to_string(maxDistance));
}

void TestLeetCode591(void)
{
    LeetCode leetCode;

    Logger::WriteMessage("Valid Examples");
    string code = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    bool result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    Logger::WriteMessage("Invalid Examples");
    code = "<A>  <B> </A>   </B>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV>  div tag is not closed  <DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV>  unmatched <  </DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV>  unmatched start tag <B>  and unmatched end tag </C> </DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "!!!<A>123</A>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode628(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    Logger::WriteMessage(nums);
    int result = leetCode.maximumProduct(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -1, -2, -3, -4 };
    Logger::WriteMessage(nums);
    result = leetCode.maximumProduct(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode630(void)
{
    LeetCode leetCode;
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

void TestLeetCode634(void)
{
    LeetCode leetCode;
    int n = 3;
    int result = leetCode.findDerangement(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode635(void)
{
    LogSystem logSystem;

    logSystem.put(1, "2017:01:01:23:59:59");
    logSystem.put(2, "2017:01:01:22:59:59");
    logSystem.put(2, "2016:01:01:00:00:00");

    vector<int> result = logSystem.retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour");
    Logger::WriteMessage(result);
}


void TestLeetCode110(void)
{
    LeetCode leetCode;
    string input = "[1,2,2,3,null,null,3,4,null,null,4]";
    Logger::WriteMessage("Original Path:" + input);

    TreeNode * root = leetCode.deserialize(input);
    bool isBalanced = leetCode.isBalanced(root);
    Logger::WriteMessage("It " + (string)(isBalanced ? "is" : "is not") + " balanced binary tree.");
    leetCode.freeTreeNodes(root);
}

void TestLeetCode236(void)
{
    // Test Leet Code #236
    LeetCode leetCode;
    TreeNode* p;
    TreeNode* q;
    TreeNode* ancestor;
    string input = "[6,2,8,0,4,7,9,null,null,3,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    p = leetCode.findTreeNode(root, 2);
    q = leetCode.findTreeNode(root, 8);
    ancestor = leetCode.lowestCommonAncestor(root, p, q);
    Logger::WriteMessage("The lowest common ancester for " +
        ((p == nullptr) ? "null" : to_string(p->val)) + " and " +
        ((q == nullptr) ? "null" : to_string(q->val)) + " is " +
        ((ancestor == nullptr) ? "null" : to_string(ancestor->val)));

    p = leetCode.findTreeNode(root, 2);
    q = leetCode.findTreeNode(root, 4);
    ancestor = leetCode.lowestCommonAncestor(root, p, q);
    Logger::WriteMessage("The lowest common ancester for " +
        ((p == nullptr) ? "null" : to_string(p->val)) + " and " +
        ((q == nullptr) ? "null" : to_string(q->val)) + " is " +
        ((ancestor == nullptr) ? "null" : to_string(ancestor->val)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode637(void)
{
    LeetCode leetCode;
    string input = "[3,9,20,null,null,15,7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode *root = leetCode.deserialize(input);
    vector<double> result = leetCode.averageOfLevels(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode638(void)
{
    LeetCode leetCode;
    vector<int> prices = { 2, 5 };
    vector<vector<int>> special = { { 3, 0, 5 },{ 1, 2, 10 } };
    vector<int> needs = { 3, 2 };
    Logger::WriteMessage(prices);
    Logger::WriteMessage(special);
    Logger::WriteMessage(needs);
    int min_price = leetCode.shoppingOffers(prices, special, needs);
    Logger::WriteMessage("min_price:" + to_string(min_price));

    prices = { 2, 3, 4 };
    special = { { 1, 1, 0, 4 },{ 2, 2, 1, 9 } };
    needs = { 1, 2, 1 };
    Logger::WriteMessage(prices);
    Logger::WriteMessage(special);
    Logger::WriteMessage(needs);
    min_price = leetCode.shoppingOffers(prices, special, needs);
    Logger::WriteMessage("min_price:" + to_string(min_price));
}

void TestLeetCode640(void)
{
    LeetCode leetCode;
    string equation = "x+5-3+x=6+x-2";
    string result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);

    equation = "x=x";
    result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);

    equation = "2x=x";
    result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);

    equation = "2x+3x-6x=x+2";
    result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);

    equation = "x=x+2";
    result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);
}

void TestLeetCode639(void)
{
    LeetCode leetCode;
    string s = "1*";
    int result = leetCode.numDecodingsII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode218(void)
{
    Logger::WriteMessage("Test Leet Code 218");
    LeetCode leetCode;
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

void TestLeetCode297(void)
{
    Logger::WriteMessage("Test Leet Code 297");
    LeetCode leetCode;
    string input = "[1,2,3,null,null,4,5]";
    Logger::WriteMessage("Deserialize and Serialize Test:");
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    string output = leetCode.serialize(root);
    if (input == output)
    {
        Logger::WriteMessage("Test Pass");
    }
    else
    {
        Logger::WriteMessage("Test Fail");
    }
    leetCode.freeTreeNodes(root);
}

void TestLeetCode144(void)
{
    Logger::WriteMessage("Test Leet Code 144");
    LeetCode leetCode;
    string input = "[1,null,2,3]";
    TreeNode * root = leetCode.deserialize(input);
    Logger::WriteMessage("PreorderTraversal");
    vector<int> result = leetCode.preorderTraversal(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode94(void)
{
    Logger::WriteMessage("Test Leet Code 94");
    LeetCode leetCode;
    string input = "[1,null,2,3]";
    TreeNode * root = leetCode.deserialize(input);
    Logger::WriteMessage("InorderTraversal");
    vector<int> result = leetCode.inorderTraversal(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}


void TestLeetCode145(void)
{
    Logger::WriteMessage("Test Leet Code 145");
    LeetCode leetCode;
    string input = "[1,null,2,3]";
    TreeNode * root = leetCode.deserialize(input);
    Logger::WriteMessage("PostorderTraversal");
    vector<int> result = leetCode.postorderTraversal(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode103(void)
{
    Logger::WriteMessage("Test Leet Code 103");
    LeetCode leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.zigzagLevelOrder(root);
    Logger::WriteMessage("ZigzagLevelOrderTraversal");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode107(void)
{
    Logger::WriteMessage("Test Leet Code 107");
    LeetCode leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.levelOrderBottom(root);
    Logger::WriteMessage("LevelorderBottomupTraversal");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode111(void)
{
    Logger::WriteMessage("Test Leet Code 111");
    LeetCode leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    int min_level = leetCode.minDepth(root);
    Logger::WriteMessage("Minimum depth = " + to_string(min_level));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode104(void)
{
    Logger::WriteMessage("Test Leet Code 104");
    LeetCode leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    int max_level = leetCode.maxDepth(root);
    Logger::WriteMessage("Maximum depth = " + to_string(max_level));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode643(void)
{
    Logger::WriteMessage("Test Leet Code 643");
    LeetCode leetCode;
    vector<int> nums = { 1, 12, -5, -6, 50, 3 };
    int k = 4;
    double max_avg = leetCode.findMaxAverage(nums, 4);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; Maximum Average = " + to_string(max_avg));

    nums = { 1, 2, 3, 4, -1, -2, -3, -4 };
    k = 4;
    max_avg = leetCode.findMaxAverage(nums, 4);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; Maximum Average = " + to_string(max_avg));
}

void TestLeetCode644(void)
{
    Logger::WriteMessage("Test Leet Code 644");
    LeetCode leetCode;
    vector<int> nums = { 1, 12, -5, -6, 50, 3 };
    int k = 4;
    double max_avg = leetCode.findMaxAverageII(nums, 4);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; Maximum Average = " + to_string(max_avg));

    nums = { 1, 2, 3, 4, -1, -2, -3, -4 };
    k = 4;
    max_avg = leetCode.findMaxAverageII(nums, 4);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; Maximum Average = " + to_string(max_avg));
}

void TestLeetCode226(void)
{
    Logger::WriteMessage("Test Leet Code 226");
    LeetCode leetCode;
    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    root = leetCode.invertTree(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("Invert Tree:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode199(void)
{
    Logger::WriteMessage("Test Leet Code 199");
    LeetCode leetCode;
    string input = "[1,2,3,null,5,null,4]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    vector<int> result = leetCode.rightSideView(root);
    Logger::WriteMessage("Right Side View:");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode98(void)
{
    Logger::WriteMessage("Test Leet Code 98");
    LeetCode leetCode;
    string input = "[]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    Logger::WriteMessage("It " + (string)(leetCode.isValidBST(root) ? "is" : "is not") + " valid BST.");
    leetCode.freeTreeNodes(root);
}

void TestLeetCode331(void)
{
    Logger::WriteMessage("Test Leet Code 331");
    LeetCode leetCode;
    string input = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("It " + (string)(leetCode.isValidPreorderSerialization(input) ? "is" : "is not") + " valid preorder serialization.");

    input = "1,#";
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("It " + (string)(leetCode.isValidPreorderSerialization(input) ? "is" : "is not") + " valid preorder serialization.");

    input = "9,#,#,1";
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("It " + (string)(leetCode.isValidPreorderSerialization(input) ? "is" : "is not") + " valid preorder serialization.");
}

void TestLeetCode114(void)
{
    Logger::WriteMessage("Test Leet Code 114");
    LeetCode leetCode;
    string input = "[1,2,5,3,4,6]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    leetCode.flatten(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("Flatten Tree:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode112(void)
{
    Logger::WriteMessage("Test Leet Code 112");
    LeetCode leetCode;
    string input = "[5,4,8,11,null,13,4,7,2,null, null, null, 1]";

    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = 22;
    Logger::WriteMessage("The tree " + (string)(leetCode.hasPathSum(root, sum) ? "has" : "does not have") + " the sum of " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode113(void)
{
    Logger::WriteMessage("Test Leet Code 113");
    LeetCode leetCode;
    string input = "[5,4,8,11,null,13,4,7,2,null, null, 5, 1]";

    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = 22;
    vector<vector<int>> paths = leetCode.pathSum(root, sum);
    Logger::WriteMessage("Paths with sum = " + to_string(sum));
    Logger::WriteMessage(paths);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode129(void)
{
    Logger::WriteMessage("Test Leet Code 129");
    LeetCode leetCode;
    string input = "[1,2,3]";

    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = leetCode.sumNumbers(root);
    Logger::WriteMessage("Sum number = " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode404(void)
{
    // Test Leet Code #404 
    Logger::WriteMessage("Test Leet Code 404");
    LeetCode leetCode;
    string input = "[3, 9, 20, null, null, 15, 7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = leetCode.sumOfLeftLeaves(root);
    Logger::WriteMessage("The sum of left leaves is: " + to_string(sum));
    leetCode.freeTreeNodes(root);

    input = "[-9, -3, 2, null, 4, 4, 0, -6, null, -5]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    sum = leetCode.sumOfLeftLeaves(root);
    Logger::WriteMessage("The sum of left leaves is: " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode109(void)
{
    LeetCode leetCode;
    LeetCodeLinkedList leetCodeLinkedList;

    // Test Leet Code #109 
    Logger::WriteMessage("Test Leet Code 109");
    vector<int> nums = { 0 };
    ListNode * head = leetCodeLinkedList.generateListNodes(nums);
    TreeNode* root = leetCode.sortedListToBST(head);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("The tree is: " + output);
    leetCode.freeTreeNodes(root);

    nums = { 1,2,3,4,5,6,7 };
    head = leetCodeLinkedList.generateListNodes(nums);
    root = leetCode.sortedListToBST(head);
    output = leetCode.serialize(root);
    Logger::WriteMessage("The tree is: " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode108(void)
{
    LeetCode leetCode;

    // Test Leet Code #108 
    Logger::WriteMessage("Test Leet Code 108");
    vector<int> nums = { 1,2,3,4,5,6,7 };
    TreeNode* root = leetCode.sortedArrayToBST(nums);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("The tree is: " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode101(void)
{
    LeetCode leetCode;

    // Test Leet Code #101 
    Logger::WriteMessage("Test Leet Code 101");
    string input = "[1, 2, 3, 3, null, 2, null]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * root = leetCode.deserialize(input);
    bool isSymmetric = leetCode.isSymmetric(root);
    Logger::WriteMessage("The tree " + string(isSymmetric ? "is " : "is not ") + "symmetric.");
    leetCode.freeTreeNodes(root);

    input = "[1, 2, 2, 3, 4, 4, 3]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    isSymmetric = leetCode.isSymmetric(root);
    Logger::WriteMessage("The tree " + string(isSymmetric ? "is " : "is not ") + "symmetric.");
    leetCode.freeTreeNodes(root);

    input = "[1, 2, 2, null, 3, null, 3]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    isSymmetric = leetCode.isSymmetric(root);
    Logger::WriteMessage("The tree " + string(isSymmetric ? "is " : "is not ") + "symmetric.");
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("===========================================================");
}

void TestLeetCode99(void)
{
    LeetCode leetCode;

    Logger::WriteMessage("Test Leet Code 99");
    // Test Leet Code #99
    string input = "[2, null, 1]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    leetCode.recoverTree(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("After recovered:" + output);
    leetCode.freeTreeNodes(root);

    input = "[0,1]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    leetCode.recoverTree(root);
    output = leetCode.serialize(root);
    Logger::WriteMessage("After recovered:" + output);
    leetCode.freeTreeNodes(root);

    input = "[4,2,3,1,6,5,7]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    leetCode.recoverTree(root);
    output = leetCode.serialize(root);
    Logger::WriteMessage("After recovered:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode100(void)
{
    LeetCode leetCode;

    // Test Leet Code #100 
    Logger::WriteMessage("Test Leet Code 100");

    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode * tree1 = leetCode.deserialize(input);
    TreeNode * tree2 = leetCode.deserialize(input);
    Logger::WriteMessage("These two trees " + (string)(leetCode.isSameTree(tree1, tree2) ? "are" : "are not") + " same.");
    leetCode.freeTreeNodes(tree1);
    leetCode.freeTreeNodes(tree2);
}

void TestLeetCode105(void)
{
    LeetCode leetCode;

    // Test Leet Code #105 
    Logger::WriteMessage("Test Leet Code 105");

    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<int> preorder = leetCode.preorderTraversal(root);
    vector<int> inorder = leetCode.inorderTraversal(root);
    leetCode.freeTreeNodes(root);
    root = leetCode.buildTreeFromPreorderandInorder(preorder, inorder);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("New Tree:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode106(void)
{
    LeetCode leetCode;

    // Test Leet Code #106 
    Logger::WriteMessage("Test Leet Code 106");

    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<int> inorder = leetCode.inorderTraversal(root);
    vector<int> postorder = leetCode.postorderTraversal(root);
    leetCode.freeTreeNodes(root);
    root = leetCode.buildTreeFromInorderAndPostorder(inorder, postorder);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("New Tree:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode646(void)
{
    LeetCode leetCode;

    // Test Leet Code #646 
    Logger::WriteMessage("Test Leet Code 646");
    vector<vector<int>> nums = { {1, 2},{2, 3},{3, 4} };
    int result = leetCode.findLongestChain(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode645(void)
{
    Logger::WriteMessage("Test Leet Code 645");
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 2, 4 };
    vector<int> result = leetCode.findErrorNums(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode565(void)
{
    LeetCode leetCode;
    vector<int> nums = { 5, 4, 0, 3, 1, 6, 2 };
    int result = leetCode.arrayNesting(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    result = leetCode.arrayNestingII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode647(void)
{
    LeetCode leetCode;
    string s = "abc";
    int result = leetCode.countSubstrings(s);
    Logger::WriteMessage("string = " + s + "; palindromic count = " + to_string(result));

    s = "aaa";
    result = leetCode.countSubstrings(s);
    Logger::WriteMessage("string = " + s + "; palindromic count = " + to_string(result));
}

void TestLeetCode648(void)
{
    LeetCode leetCode;
    vector<string> dict = { "cat", "bat", "rat" };
    string sentence = "the cattle was rattled by the battery";
    string result = leetCode.replaceWords(dict, sentence);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("sentence = " + sentence + "; result = " + result);
}

void TestLeetCode650(void)
{
    LeetCode leetCode;
    int n = 4;
    int result = leetCode.minSteps(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode651(void)
{
    LeetCode leetCode;
    int N = 3;
    int result = leetCode.maxA(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
    N = 4;
    result = leetCode.maxA(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
    N = 7;
    result = leetCode.maxA(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
    N = 50;
    result = leetCode.maxA(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode652(void)
{
    LeetCode leetCode;
    string input = "[1,2,3,4,null,2,4,null,null,4]";
    TreeNode * root = leetCode.deserialize(input);
    vector<TreeNode *> result = leetCode.findDuplicateSubtrees(root);
    Logger::WriteMessage("input = " + input);
    for (TreeNode *node : result)
    {
        string output = leetCode.serialize(node);
        Logger::WriteMessage("subtree = " + output);
    }
    leetCode.freeTreeNodes(root);
}

void TestLeetCode649(void)
{
    LeetCode leetCode;
    string senate = "RDRDDD";
    string result = leetCode.predictPartyVictory(senate);
    Logger::WriteMessage("senate = " + senate + "; result = " + result);

    senate = "RD";
    result = leetCode.predictPartyVictory(senate);
    Logger::WriteMessage("senate = " + senate + "; result = " + result);

    senate = "RDD";
    result = leetCode.predictPartyVictory(senate);
    Logger::WriteMessage("senate = " + senate + "; result = " + result);
}

void TestLeetCode653(void)
{
    LeetCode leetCode;
    string input = "[5,3,6,2,4,null,7]";
    int k = 9;
    Logger::WriteMessage("input = " + input);
    TreeNode * root = leetCode.deserialize(input);
    bool result = leetCode.findTarget(root, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    k = 28;
    result = leetCode.findTarget(root, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode654(void)
{
    LeetCode leetCode;
    vector<int> nums = { 3, 2, 1, 6, 0, 5 };
    Logger::WriteMessage(nums);
    TreeNode * root = leetCode.constructMaximumBinaryTree(nums);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("tree = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode655(void)
{
    LeetCode leetCode;
    string input = "[1,2,null]";
    Logger::WriteMessage("input = " + input);
    TreeNode * root = leetCode.deserialize(input);
    vector<vector<string>> result = leetCode.printTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,null,4]";
    Logger::WriteMessage("input = " + input);
    root = leetCode.deserialize(input);
    result = leetCode.printTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,5,3,null,null,null,4]";
    Logger::WriteMessage("input = " + input);
    root = leetCode.deserialize(input);
    result = leetCode.printTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}




void TestLeetCode661(void)
{
    LeetCode leetCode;
    vector<vector<int>> M =
    {
        { 1, 4, 1 },
        { 1, 0, 1 },
        { 1, 2, 10 }
    };

    vector<vector<int>> result = leetCode.imageSmoother(M);
    Logger::WriteMessage(M);
    Logger::WriteMessage(result);
}

void TestLeetCode665(void)
{
    LeetCode leetCode;
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

void TestLeetCode658(void)
{
    LeetCode leetCode;
    vector<int> arr = { 1, 2, 3, 4, 5 };
    int k = 4, x = 3;
    Logger::WriteMessage(arr);
    vector<int> result = leetCode.findClosestElements(arr, k, x);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);

    arr = { 1, 3, 5, 7, 9 };
    k = 2;  x = 4;
    Logger::WriteMessage(arr);
    result = leetCode.findClosestElements(arr, k, x);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage(result);
}

void TestLeetCode663(void)
{
    LeetCode leetCode;
    string input = "[5, 10, 10, null, null, 2, 3]";
    Logger::WriteMessage("Tree:" + input);
    TreeNode *root = leetCode.deserialize(input);
    bool result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[1, 2, 10, null, null, 2, 20]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);


    input = "[0]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[0, 0]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[-9, -3, 2, null, 4, 4, 0, -6, null, -5]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode662(void)
{
    LeetCode leetCode;
    string input = "[1, 3, 2, 5, 3, null, 9]";
    Logger::WriteMessage("Tree:" + input);
    TreeNode *root = leetCode.deserialize(input);
    int width = leetCode.widthOfBinaryTree(root);
    Logger::WriteMessage("Tree width = " + to_string(width));
    leetCode.freeTreeNodes(root);

    input = "[1, 3, null, 5, 3]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    width = leetCode.widthOfBinaryTree(root);
    Logger::WriteMessage("Tree width = " + to_string(width));
    leetCode.freeTreeNodes(root);


    input = "[1,3,2,5]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    width = leetCode.widthOfBinaryTree(root);
    Logger::WriteMessage("Tree width = " + to_string(width));
    leetCode.freeTreeNodes(root);

    input = "[1,3,2,5,null,null,9,6,null,null,7]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    width = leetCode.widthOfBinaryTree(root);
    Logger::WriteMessage("Tree width = " + to_string(width));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode666(void)
{
    LeetCode leetCode;
    vector<int> nums = { 113, 215, 221 };
    Logger::WriteMessage(nums);
    int result = leetCode.pathSumIV(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 113, 221 };
    Logger::WriteMessage(nums);
    result = leetCode.pathSumIV(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode659(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 3, 3, 4, 5 };
    Logger::WriteMessage(nums);
    bool result = leetCode.isPossible(nums);
    Logger::WriteMessage("Possible to split array = " + (string)(result ? "true" : "false"));

    nums = { 1, 2, 3, 3, 4, 4, 5, 5 };
    Logger::WriteMessage(nums);
    result = leetCode.isPossible(nums);
    Logger::WriteMessage("Possible to split array = " + (string)(result ? "true" : "false"));

    nums = { 1, 2, 3, 4, 4, 5 };
    Logger::WriteMessage(nums);
    result = leetCode.isPossible(nums);
    Logger::WriteMessage("Possible to split array = " + (string)(result ? "true" : "false"));
}

void TestLeetCode667(void)
{
    LeetCode leetCode;
    int n = 3;
    int k = 1;
    vector<int> result = leetCode.constructArray(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(result);

    n = 3;
    k = 2;
    result = leetCode.constructArray(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(result);

    n = 4;
    k = 2;
    result = leetCode.constructArray(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode669(void)
{
    LeetCode leetCode;
    string input = "[1, 0, 2]";
    Logger::WriteMessage("Tree:" + input);
    TreeNode *root = leetCode.deserialize(input);
    TreeNode *result = leetCode.trimBST(root, 1, 2);
    string output = leetCode.serialize(result);
    Logger::WriteMessage("After Trim:" + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(result);


    input = "[3, 0, 4, null, 2, null, null, 1]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.trimBST(root, 1, 3);
    output = leetCode.serialize(result);
    Logger::WriteMessage("After Trim:" + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(result);

    input = "[1, null, 2]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.trimBST(root, 2, 4);
    output = leetCode.serialize(result);
    Logger::WriteMessage("After Trim:" + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(result);
}

void TestLeetCode671(void)
{
    LeetCode leetCode;
    string input = "[2, 2, 5, null, null, 5, 7]";
    Logger::WriteMessage("Tree:" + input);
    TreeNode *root = leetCode.deserialize(input);
    int result = leetCode.findSecondMinimumValue(root);
    Logger::WriteMessage("The second smallest value:" + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[2, 2, 2]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.findSecondMinimumValue(root);
    Logger::WriteMessage("The second smallest value:" + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[5, 8, 5]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.findSecondMinimumValue(root);
    Logger::WriteMessage("The second smallest value:" + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode670(void)
{
    LeetCode leetCode;
    int num = 1993;
    int result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 2736;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 9973;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 3203;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 912939;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 12939;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode674(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1, 3, 5, 4, 7 };
    int result = leetCode.findLengthOfLCIS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, 2, 2, 2 };
    result = leetCode.findLengthOfLCIS(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode680(void)
{
    LeetCode leetCode;
    string s = "acbca";
    bool result = leetCode.validPalindrome(s);
    Logger::WriteMessage("s = " + s + "; valid palindrome = " + (string)(result ? " true" : "false"));

    s = "abcda";
    result = leetCode.validPalindrome(s);
    Logger::WriteMessage("s = " + s + "; valid palindrome = " + (string)(result ? " true" : "false"));

    s = "aba";
    result = leetCode.validPalindrome(s);
    Logger::WriteMessage("s = " + s + "; valid palindrome = " + (string)(result ? " true" : "false"));

    s = "abca";
    result = leetCode.validPalindrome(s);
    Logger::WriteMessage("s = " + s + "; valid palindrome = " + (string)(result ? " true" : "false"));

    s = "abcca";
    result = leetCode.validPalindrome(s);
    Logger::WriteMessage("s = " + s + "; valid palindrome = " + (string)(result ? " true" : "false"));

}

void TestLeetCode682(void)
{
    LeetCode leetCode;
    vector<string> ops = {"5", "2", "C", "D", "+"};
    int sum = leetCode.calPoints(ops);
    Logger::WriteMessage(ops);
    Logger::WriteMessage("sum = " + to_string(sum));
   
    ops = { "5","-2","4","C","D","9","+","+" };
    sum = leetCode.calPoints(ops);
    Logger::WriteMessage(ops);
    Logger::WriteMessage("sum = " + to_string(sum));
}

void TestLeetCode681(void)
{
    LeetCode leetCode;
    string time = "19:34";
    string next_time = leetCode.nextClosestTime(time);
    Logger::WriteMessage("time = " + time + "; next time = " + next_time);

    time = "23:59";
    next_time = leetCode.nextClosestTime(time);
    Logger::WriteMessage("time = " + time + "; next time = " + next_time);
}

void TestLeetCode678(void)
{
    LeetCode leetCode;
    string s = "()";
    bool isValid = leetCode.checkValidString(s);
    Logger::WriteMessage("s = " + s + "; is valid = " + (string)(isValid ? "true": "false"));

    s = "(*)";
    isValid = leetCode.checkValidString(s);
    Logger::WriteMessage("s = " + s + "; is valid = " + (string)(isValid ? "true" : "false"));

    s = "(*))";
    isValid = leetCode.checkValidString(s);
    Logger::WriteMessage("s = " + s + "; is valid = " + (string)(isValid ? "true" : "false"));

    s = "())*";
    isValid = leetCode.checkValidString(s);
    Logger::WriteMessage("s = " + s + "; is valid = " + (string)(isValid ? "true" : "false"));
}

void TestLeetCode660(void)
{
    LeetCode leetCode;
    int n = 9;
    int result = leetCode.newInteger(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 100;
    result = leetCode.newInteger(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode687(void)
{
    LeetCode leetCode;
    string input = "[1, 2, 2, 2, 2, 2, 2, 2]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int max_path = leetCode.longestUnivaluePath(root);
    Logger::WriteMessage("Max Path Length = " + to_string(max_path));
    leetCode.freeTreeNodes(root);

    input = "[5,4,5,1,1,null,5]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    max_path = leetCode.longestUnivaluePath(root);
    Logger::WriteMessage("Max Path Length = " + to_string(max_path));
    leetCode.freeTreeNodes(root);
    
    input = "[1,4,5,4,4,null,5]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    max_path = leetCode.longestUnivaluePath(root);
    Logger::WriteMessage("Max Path Length = " + to_string(max_path));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode664(void)
{
    LeetCode leetCode;
    string s = "cccaaabbbaaabbbccc";
    int result = leetCode.strangePrinter(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aaabbb";
    result = leetCode.strangePrinter(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aba";
    result = leetCode.strangePrinter(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode693(void)
{
    LeetCode leetCode;
    int n = 5;
    bool result = leetCode.hasAlternatingBits(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string) (result? "true" : "false"));

    n = 7;
    result = leetCode.hasAlternatingBits(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));

    n = 11;
    result = leetCode.hasAlternatingBits(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));

    n = 10;
    result = leetCode.hasAlternatingBits(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));
}


void TestLeetCode668(void)
{
    LeetCode leetCode;
    int m = 3, n = 3, k = 5;
    int result = leetCode.findKthNumber(m, n, k);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    m = 2, n = 3, k = 6;
    result = leetCode.findKthNumber(m, n, k);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    m = 1, n = 9, k = 7;
    result = leetCode.findKthNumber(m, n, k);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    m = 9, n = 1, k = 7;
    result = leetCode.findKthNumber(m, n, k);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}


void TestLeetCode688(void)
{
    LeetCode leetCode;
    int N = 3;
    int K = 2;
    int r = 1;
    int c = 1;
    double possibility = leetCode.knightProbability(N, K, r, c);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) +
        "; r = " + to_string(r) + "; c = " + to_string(c) + "; possibility = " + to_string(possibility));

    N = 8;
    K = 30;
    r = 6;
    c = 4;
    possibility = leetCode.knightProbability(N, K, r, c);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) +
        "; r = " + to_string(r) + "; c = " + to_string(c) + "; possibility = " + to_string(possibility));

    N = 3;
    K = 2;
    r = 0;
    c = 0;
    possibility = leetCode.knightProbability(N, K, r, c);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) +
        "; r = " + to_string(r) + "; c = " + to_string(c) + "; possibility = " + to_string(possibility));
}

void TestLeetCode692(void)
{
    LeetCode leetCode;
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

void TestLeetCode679(void)
{
    LeetCode leetCode;
    vector<int> nums = { 4, 1, 8, 7 };
    bool result = leetCode.judgePoint24(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    nums = { 1, 2, 1, 2 };
    result = leetCode.judgePoint24(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode140(void)
{
    Logger::WriteMessage("Test Leet Code 140");
    LeetCode leetCode;
    string s;
    vector<string> wordDict;
    vector<string> result;

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
    result = leetCode.wordBreakII(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage(result);

    s = "catsanddog";
    wordDict = { "cat", "cats", "and", "sand", "dog" };
    result = leetCode.wordBreakII(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage(result);
}

void TestLeetCode697(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1, 2, 2, 3, 1 };
    int result = leetCode.findShortestSubArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,2,3,1,4,2 };
    result = leetCode.findShortestSubArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode696(void)
{
    LeetCode leetCode;
    string s = "00110011";
    int result = leetCode.countBinarySubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "10101";
    result = leetCode.countBinarySubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}


void TestLeetCode698(void)
{
    LeetCode leetCode;
    vector<int> nums = { 4, 3, 2, 3, 5, 2, 2 };
    int k = 4;
    bool result = leetCode.canPartitionKSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string) (result ? "true" : " false"));
}




void TestLeetCode713(void)
{
    Logger::WriteMessage("Test Leet Code");
    LeetCode leetCode;
    vector<int> nums = { 10, 2, 2, 5, 4 };
    int k = 289;
    int result = leetCode.numSubarrayProductLessThanK(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 10, 5, 2, 6 };
    k = 100;
    result = leetCode.numSubarrayProductLessThanK(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode717(void)
{
    Logger::WriteMessage("Test Leet Code 717");
    LeetCode leetCode;
    vector<int> bits = { 1, 0, 0 };
    bool result = leetCode.isOneBitCharacter(bits);
    Logger::WriteMessage(bits);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    bits = { 1, 1, 1, 0 };
    result = leetCode.isOneBitCharacter(bits);
    Logger::WriteMessage(bits);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode712(void)
{
    Logger::WriteMessage("Test Leet Code");
    LeetCode leetCode;
    string s1 = "sea";
    string s2 = "eat";
    int result = leetCode.minimumDeleteSum(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + to_string(result));

    s1 = "delete";
    s2 = "leet";
    result = leetCode.minimumDeleteSum(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + to_string(result));
}


void TestLeetCode443(void)
{
    LeetCode leetCode;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    Logger::WriteMessage(chars);
    int length = leetCode.compress(chars);
    chars.resize(length);
    Logger::WriteMessage(chars);
    Logger::WriteMessage("length = " + to_string(length));

    chars = { 'a' };
    Logger::WriteMessage(chars);
    length = leetCode.compress(chars);
    chars.resize(length);
    Logger::WriteMessage(chars);
    Logger::WriteMessage("length = " + to_string(length));

    chars = { 'a','b','b','b','b','b','b','b','b','b','b','b','b' };
    Logger::WriteMessage(chars);
    length = leetCode.compress(chars);
    chars.resize(length);
    Logger::WriteMessage(chars);
    Logger::WriteMessage("length = " + to_string(length));
}



void TestLeetCode720(void)
{
    LeetCode leetCode;
    vector<string> words = { "w","wo","wor","worl", "world" };
    string longestWord = leetCode.longestWord(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("Longest word = " + longestWord);

    words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    longestWord = leetCode.longestWord(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("Longest word = " + longestWord);
}



void TestLeetCode691(void)
{
    LeetCode leetCode;

    vector<string> stickers = { "old", "center", "shape", "fig", "skin", "come" };
    Logger::WriteMessage(stickers);
    string target = "togethernear";
    Logger::WriteMessage("target = " + target);
    int result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage("result = " + to_string(result));

    stickers = { "city", "would", "feel", "effect", "cell", "paint" };
    Logger::WriteMessage(stickers);
    target = "putcat";
    Logger::WriteMessage("target = " + target);
    result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage("result = " + to_string(result));

    stickers = { "these", "guess", "about", "garden", "him" };
    Logger::WriteMessage(stickers);
    target = "atomher";
    Logger::WriteMessage("target = " + target);
    result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage("result = " + to_string(result));

    stickers = { "with", "example", "science" };
    Logger::WriteMessage(stickers);
    target = "thehat";
    Logger::WriteMessage("target = " + target);
    result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage("result = " + to_string(result));

    stickers = { "notice", "possible" };
    target = "basicbasic";
    Logger::WriteMessage(stickers);
    Logger::WriteMessage("target = " + target);
    result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage(stickers);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode723(void)
{
    LeetCode leetCode;

    vector<vector<int>> board = 
    {
        {110,5,112,113,114 }, { 210, 211, 5, 213, 214 }, { 310, 311, 3, 313, 314 },
        {410,411,412,5,414}, {5,1,512,3,3}, {610,4,1,613,614}, {710,1,2,713,714},
        {810,1,2,1,1},{1,1,2,2,2}, {4,1,4,4,1014}
    };
    Logger::WriteMessage(board);
    vector<vector<int>> result = leetCode.candyCrush(board);
    Logger::WriteMessage(result);
}


void TestLeetCode722(void)
{
    LeetCode leetCode;

    vector<string> source =
    { 
        "/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test",
        "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}" 
    };
    vector<string> result = leetCode.removeComments(source);
    Logger::WriteMessage(source);
    Logger::WriteMessage(result);

    source = { "a/*comment", "line", "more_comment*/b" };
    result = leetCode.removeComments(source);
    Logger::WriteMessage(source);
    Logger::WriteMessage(result);
}

void TestLeetCode724(void)
{
    LeetCode leetCode;

    vector<int> nums = { 1, 7, 3, 6, 5, 6 };
    int result = leetCode.pivotIndex(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 2, 3 };
    result = leetCode.pivotIndex(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode718(void)
{
    LeetCode leetCode;

    vector<int> A = { 1,2,3,2,1 };
    vector<int> B = { 3,2,1,4,7 };
    int result = leetCode.findLength(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0, 0, 0, 0, 0 };
    B = { 0, 0, 0, 0, 0 };
    result = leetCode.findLength(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode728(void)
{
    LeetCode leetCode;
    int left = 1, right = 22;
    vector<int> result = leetCode.selfDividingNumbers(left, right);
    Logger::WriteMessage("left = " + to_string(left) + "; right = " + to_string(right));
    Logger::WriteMessage(result);
}

void TestLeetCode729(void)
{
    MyCalendar myCalendar = MyCalendar();
    vector<pair<int, int>> booking = { { 10, 20 },{ 15, 25 },{ 20, 30 } };
    vector<int> result;
    for (size_t i = 0; i < booking.size(); i++)
    {
        if (myCalendar.book(booking[i].first, booking[i].second))
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode731(void)
{
    MyCalendarTwo myCalendarTwo = MyCalendarTwo();
    vector<pair<int, int>> booking = { {24, 40},{43, 50},{27, 43},{5, 21},{30, 40},{14, 29},{3, 19},{3, 14},{25, 39},{6, 19} };
    vector<int> result;
    for (size_t i = 0; i < booking.size(); i++)
    {
        if (myCalendarTwo.book(booking[i].first, booking[i].second))
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }
    }
    Logger::WriteMessage(result);

    myCalendarTwo = MyCalendarTwo();
    booking = { { 10, 20 },{ 50, 60 },{ 10, 40 },{ 5, 15 },{ 5, 10 },{ 25, 55 } };
    result.clear();
    for (size_t i = 0; i < booking.size(); i++)
    {
        if (myCalendarTwo.book(booking[i].first, booking[i].second))
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode715(void)
{
    RangeModule rangeModule;
    vector<string> action = { "addRange", "removeRange", "removeRange", "addRange", "removeRange", "addRange", "queryRange", "queryRange", "queryRange" };
    vector<pair<int, int>> range = { { 6, 8 }, { 7, 8 },  { 8, 9 }, { 8, 9 }, { 1, 3 }, { 1, 8 }, { 2, 4 }, { 2, 9 }, { 4, 6 } };
    vector<string> result;
    for (size_t i = 0; i < action.size(); i++)
    {
        if (action[i] == "addRange")
        {
            rangeModule.addRange(range[i].first, range[i].second);
            result.push_back("null");
        }
        else if (action[i] == "removeRange")
        {
            rangeModule.removeRange(range[i].first, range[i].second);
            result.push_back("null");
        }
        else
        {
            if (rangeModule.queryRange(range[i].first, range[i].second))
            {
                result.push_back("true");
            }
            else
            {
                result.push_back("false");
            }
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode689(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1,2,1,2,6,7,5,1 };
    int k = 2;
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    vector<int> result = leetCode.maxSumOfThreeSubarrays(nums, k);
    Logger::WriteMessage(result);
}

void TestLeetCode699(void)
{
    LeetCode leetCode;
    vector<pair<int, int>> positions = { {1, 2},{2, 3},{6, 1} };
    vector<int> result = leetCode.fallingSquares(positions);

    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);

    positions = { {100, 100},{200, 100} };
    result = leetCode.fallingSquares(positions);

    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);
}

void TestLeetCode714(void)
{
    LeetCode leetCode;
    vector<int> prices = { 4, 5, 2, 4, 3, 3, 1, 2, 5, 4 };
    int fee = 1;
    int result = leetCode.maxProfitWithFee(prices, fee);

    Logger::WriteMessage(prices);
    Logger::WriteMessage("fee = " + to_string(fee) + "; result = " + to_string(result));

    prices = { 1, 3, 7, 5, 10, 3 };
    fee = 2;
    result = leetCode.maxProfitWithFee(prices, fee);

    Logger::WriteMessage(prices);
    Logger::WriteMessage("fee = " + to_string(fee) + "; result = " + to_string(result));

    prices = { 1, 3, 2, 8, 4, 9 };
    fee = 2;
    result = leetCode.maxProfitWithFee(prices, fee);

    Logger::WriteMessage(prices);
    Logger::WriteMessage("fee = " + to_string(fee) + "; result = " + to_string(result));
}

void TestLeetCode726(void)
{
    LeetCode leetCode;
    
    string formula = "H2O";
    string result = leetCode.countOfAtoms(formula);
    Logger::WriteMessage("formula = " + formula + "; result = " + result);

    formula = "Mg(OH)2";
    result = leetCode.countOfAtoms(formula);
    Logger::WriteMessage("formula = " + formula + "; result = " + result);

    formula = "K4(ON(SO3)2)2";
    result = leetCode.countOfAtoms(formula);
    Logger::WriteMessage("formula = " + formula + "; result = " + result);

    formula = "(Be22)8((Ge4)46)13";
    result = leetCode.countOfAtoms(formula);
    Logger::WriteMessage("formula = " + formula + "; result = " + result);
};


void TestLeetCode727(void)
{
    LeetCode leetCode;
    string S = "abcdebdde";
    string T = "bde";
    string result = leetCode.minWindowIII(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + result);
};

void TestLeetCode730(void)
{
    LeetCode leetCode;
    string S = "bccb";
    int result = leetCode.countPalindromicSubsequences(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    result = leetCode.countPalindromicSubsequences(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
};

void TestLeetCode734(void)
{
    LeetCode leetCode;
    vector<string> word1 = { "great", "acting", "skills" };
    vector<string> word2 = { "fine", "drama", "talent" };
    vector<pair<string, string>> pairs = { { "great", "fine" }, { "acting","drama" }, { "skills","talent" } };
    bool result = leetCode.areSentencesSimilar(word1, word2, pairs);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage((string)(result ? "similar": "not similar"));

    word1 = { "great"};
    word2 = { "great"};
    pairs = { };
    result = leetCode.areSentencesSimilar(word1, word2, pairs);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage((string)(result ? "similar" : "not similar"));
}



void TestLeetCode732(void)
{
    MyCalendarThree myCalendarThree = MyCalendarThree();
    vector<pair<int, int>> booking = { { 10, 20 },{ 50, 60 },{ 10, 40 },{ 5, 15 },{ 5, 10 },{ 25, 55 } };
    vector<int> result;

    for (size_t i = 0; i < booking.size(); i++)
    {
        result.push_back((myCalendarThree.book(booking[i].first, booking[i].second)));
    }
    Logger::WriteMessage(result);
}

void TestLeetCode738(void)
{
    LeetCode leetCode;
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

void TestLeetCode740(void)
{
    LeetCode leetCode;
    vector<int> nums = { 3, 4, 2 };
    int result = leetCode.deleteAndEarn(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, 2, 3, 3, 3, 4 };
    result = leetCode.deleteAndEarn(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode480(void)
{
    Logger::WriteMessage("Test Leet Code 480");
    LeetCode leetCode;
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

void TestLeetCode741(void)
{
    LeetCode leetCode;
    vector<vector<int>> grid = { { 1, 1, -1 },{ 1, -1, 1 },{ -1, 1, 1 } };
    Logger::WriteMessage(grid);
    int result = leetCode.cherryPickup(grid);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.cherryPickupII(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 0, 1, -1 },{ 1, 0, -1 },{ 1, 1, 1 } };
    Logger::WriteMessage(grid);
    result = leetCode.cherryPickup(grid);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.cherryPickupII(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 1 } };
    Logger::WriteMessage(grid);
    result = leetCode.cherryPickup(grid);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.cherryPickupII(grid);
    Logger::WriteMessage("result = " + to_string(result));

}

void TestSalesOrg(void)
{
    SalesOrg salesOrg;
    vector<vector<string>> input = 
    { 
        { "Alice","","5" },{ "Bob","Alice","3" },{ "Carol","Bob","2" }, 
        { "David","Bob","3" }, {"Eve","Alice","2"}, { "Ferris","Eve","1" } 
    };
    Logger::WriteMessage(input);
    for (size_t i = 0; i < input.size(); i++)
    {
        salesOrg.addSalesRecord(input[i][0], input[i][1], atoi(input[i][2].c_str()));
    }
    vector<string> result = salesOrg.print();
    for (size_t i = 0; i < result.size(); i++)
    {
        Logger::WriteMessage(result[i]);
    }
}

void TestLeetCode744(void)
{
    Logger::WriteMessage("Test Leet Code 744");
    LeetCode leetCode;
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

void TestLeetCode540(void)
{
    LeetCode leetCode;
    vector<int> nums = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };
    Logger::WriteMessage(nums);
    int result = leetCode.singleNonDuplicate(nums);
    Logger::WriteMessage("result:" + to_string(result));

    nums = { 3, 3, 7, 7, 10, 11, 11 };
    Logger::WriteMessage(nums);
    result = leetCode.singleNonDuplicate(nums);
    Logger::WriteMessage("result:" + to_string(result));
}

void TestLeetCode742(void)
{
    Logger::WriteMessage("Test Leet Code 742");
    LeetCode leetCode;
    string input = "[1, 2, 3, 4, null, null, 7, 8, 9, null, null, 12, null, null, null, null, 13, null, 14]";
    int k = 8;
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.findClosestLeaf(root, k);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));

    input = "[1, 3, 2]";
    k = 1;
    root = leetCode.deserialize(input);
    result = leetCode.findClosestLeaf(root, k);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));

    input = "[1]";
    k = 1;
    root = leetCode.deserialize(input);
    result = leetCode.findClosestLeaf(root, k);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));

    input = "[1,2,3,4,null,null,null,5,null,6]";
    k = 2;
    root = leetCode.deserialize(input);
    result = leetCode.findClosestLeaf(root, k);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode746(void)
{
    Logger::WriteMessage("Test Leet Code 746");
    LeetCode leetCode;
    vector<int> cost = { 10, 15, 20 };
    int result = leetCode.minCostClimbingStairs(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    result = leetCode.minCostClimbingStairs(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode748(void)
{
    Logger::WriteMessage("Test Leet Code 748");
    LeetCode leetCode;
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

void TestLeetCode750(void)
{
    Logger::WriteMessage("Test Leet Code 750");
    LeetCode leetCode;
    vector<vector<int>> grids = 
    { 
        { 1, 0, 0, 1, 0 },
        { 0, 0, 1, 0, 1 },
        { 0, 0, 0, 1, 0 },
        { 1, 0, 1, 0, 1 }
    };

    int result = leetCode.countCornerRectangles(grids);
    Logger::WriteMessage(grids);
    Logger::WriteMessage("result = " + to_string(result));

    grids =
    {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 }
    };

    result = leetCode.countCornerRectangles(grids);
    Logger::WriteMessage(grids);
    Logger::WriteMessage("result = " + to_string(result));

    grids =
    {
        { 1, 1, 1, 1 }
    };

    result = leetCode.countCornerRectangles(grids);
    Logger::WriteMessage(grids);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode747(void)
{
    Logger::WriteMessage("Test Leet Code 747");
    LeetCode leetCode;
    vector<int> nums = { 3, 6, 1, 0 };
    int result = leetCode.dominantIndex(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 2, 3, 4 };
    result = leetCode.dominantIndex(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode753(void)
{
    Logger::WriteMessage("Test Leet Code 753");
    LeetCode leetCode;
    int n = 1, k = 2;
    string result = leetCode.crackSafe(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + result);

    n = 2, k = 2;
    result = leetCode.crackSafe(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode751(void)
{
    Logger::WriteMessage("Test Leet Code 752");
    LeetCode leetCode;
    string ip = "255.0.0.7";
    int n = 10;
    vector<string> result = leetCode.ipToCIDR(ip, n);
    Logger::WriteMessage("ip = " + ip + "; n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode341(void)
{
    Logger::WriteMessage("Test Leet Code 341");
    vector<NestedInteger> n10;
    n10.push_back(1);
    n10.push_back(1);
    NestedInteger n1 = n10;
    NestedInteger n2 = 2;
    vector<NestedInteger> n30;
    n30.push_back(1);
    n30.push_back(1);
    NestedInteger n3 = n30;
    vector<NestedInteger> n4;
    vector<NestedInteger> input;
    input.push_back(n1);
    input.push_back(n2);
    input.push_back(n3);
    input.push_back(n4);
    NestedIterator nested_iterator(input);
    vector<int> result;
    while (nested_iterator.hasNext())
    {
        result.push_back(nested_iterator.next());
    }
    Logger::WriteMessage(result);
}


void TestLeetCode756(void)
{
    Logger::WriteMessage("Test Leet Code 756");
    LeetCode leetCode;
    string bottom = "XYZ";
    vector<string> allowed = { "XYD", "YZE", "DEA", "FFF" };
    bool result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string) (result? "true": "false"));

    bottom = "XXYX";
    allowed = { "XXX", "XXY", "XYX", "XYY", "YXZ" };
    result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));

    
    bottom = "ABDBACAAAC";
    allowed = 
    { 
        "ACC", "AAC", "AAB", "BCB", "BAD", "CAC", "CCD", "CAA", "CCB", "DAD", "ACD", "DCB", "ABB", "BDA", "BDC", 
        "BDB", "BBD", "BBC", "BBB", "ADB", "ADC", "DDC", "DDB", "CDD", "CBC", "CBA", "CBD", "CDC", "DBC" 
    };
    result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));

    bottom = "AABCCBABBB";
    allowed =
    {
        "AAA", "AAB", "BCD", "BCA", "BCB", "BAD", "BAB", "BAA", "CCD", "BDD", "CCA", "CAA", "CAD", "DAD", "DAA", "DAC", 
        "DCD", "DCB", "DCA", "CDD", "ABA", "ABB", "BBC", "BBB", "BBA", "ADC", "CBB", "CBA", "CDB", "CDC", "DBC", "DBB"
    };
    result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));
    
    bottom = "AAAA";
    allowed =
    {
        "AAB", "AAC", "BCD", "BBE", "DEF"
    };
    result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode757(void)
{
    Logger::WriteMessage("Test Leet Code 757");
    LeetCode leetCode;
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

void TestLeetCode755(void)
{
    Logger::WriteMessage("Test Leet Code 755");
    LeetCode leetCode;
    vector<int> heights = { 2,1,1,2,1,2,2 };
    int V = 4;
    int K = 3;
    vector<int> result = leetCode.pourWater(heights, V, K);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("V = " + to_string(V) + "; K = " + to_string(K));
    Logger::WriteMessage(result);

    heights = { 1,2,3,4 };
    V = 2;
    K = 2;
    result = leetCode.pourWater(heights, V, K);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("V = " + to_string(V) + "; K = " + to_string(K));
    Logger::WriteMessage(result);

    heights = { 3,1,3 };
    V = 5;
    K = 1;
    result = leetCode.pourWater(heights, V, K);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("V = " + to_string(V) + "; K = " + to_string(K));
    Logger::WriteMessage(result);
}

void TestLeetCode761(void)
{
    Logger::WriteMessage("Test Leet Code 761");
    LeetCode leetCode;
    string S = "11011000";
    string result = leetCode.makeLargestSpecial(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode760(void)
{
    Logger::WriteMessage("Test Leet Code 760");
    LeetCode leetCode;
    vector<int> A = { 12, 28, 46, 32, 50 };
    vector<int> B = { 50, 12, 32, 46, 28 };
    vector<int> result = leetCode.anagramMappings(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);
}

void TestLeetCode759(void)
{
    Logger::WriteMessage("Test Leet Code 759");
    LeetCode leetCode;
    vector<vector<Interval>> schedule = { {{1, 2}, {5, 6}},{{1, 3}},{{4, 10}} };
    vector<Interval> result = leetCode.employeeFreeTime(schedule);
    Logger::WriteMessage(schedule);
    Logger::WriteMessage(result);

    schedule = { {{1, 3},{6, 7}},{{2, 4}},{{2, 5},{9, 12}} };
    result = leetCode.employeeFreeTime(schedule);
    Logger::WriteMessage(schedule);
    Logger::WriteMessage(result);
}

void TestLeetCode758(void)
{
    Logger::WriteMessage("Test Leet Code 758");
    LeetCode leetCode;
    vector<string> words = { "ab", "bc" };
    string S = "aabcd";
    string result = leetCode.boldWords(words, S);
    Logger::WriteMessage(words);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode762(void)
{
    Logger::WriteMessage("Test Leet Code 762");
    LeetCode leetCode;
    int L = 10, R = 15;
    int result = leetCode.countPrimeSetBits(L, R);
    Logger::WriteMessage("L = " + to_string(L) + "; R = " + to_string(R) + "; result = " + to_string(result));
}

void TestLeetCode766(void)
{
    Logger::WriteMessage("Test Leet Code 766");
    LeetCode leetCode;
    vector<vector<int>> matrix = { {1, 2, 3, 4},{5, 1, 2, 3},{9, 5, 1, 2} };
    Logger::WriteMessage(matrix);
    bool result = leetCode.isToeplitzMatrix(matrix);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    matrix = { { 1,2 },{ 2,2 } };
    Logger::WriteMessage(matrix);
    result = leetCode.isToeplitzMatrix(matrix);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}



void TestLeetCode769(void)
{
    Logger::WriteMessage("Test Leet Code 769");
    LeetCode leetCode;
    vector<int> arr = { 4,3,2,1,0 };
    int result = leetCode.maxChunksToSorted(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,0,2,3,4 };
    result = leetCode.maxChunksToSorted(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode771(void)
{
    Logger::WriteMessage("Test Leet Code 771");
    LeetCode leetCode;
    string J = "aA";
    string S = "aAAbbbb";
    int result = leetCode.numJewelsInStones(J, S);
    Logger::WriteMessage("J = " + J + "; S = " + S + "; result = " + to_string(result));
    J = "z";
    S = "ZZ";
    result = leetCode.numJewelsInStones(J, S);
    Logger::WriteMessage("J = " + J + "; S = " + S + "; result = " + to_string(result));
}

void TestLeetCode764(void)
{
    Logger::WriteMessage("Test Leet Code 764");
    LeetCode leetCode;
    int N = 5;
    vector<vector<int>> mines = { {4, 2} };
    int result = leetCode.orderOfLargestPlusSign(N, mines);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(mines);
    Logger::WriteMessage("result = " + to_string(result));

    N = 2;
    mines = { };
    result = leetCode.orderOfLargestPlusSign(N, mines);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(mines);
    Logger::WriteMessage("result = " + to_string(result));

    N = 1;
    mines = { {0, 0} };
    result = leetCode.orderOfLargestPlusSign(N, mines);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(mines);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode763(void)
{
    Logger::WriteMessage("Test Leet Code 763");
    LeetCode leetCode;
    string S = "ababcbacadefegdehijhklij";
    vector<int> result = leetCode.partitionLabels(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode767(void)
{
    Logger::WriteMessage("Test Leet Code 767");
    LeetCode leetCode;
    string S = "aab";
    string result = leetCode.reorganizeString(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "aaab";
    result = leetCode.reorganizeString(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode775(void)
{
    Logger::WriteMessage("Test Leet Code 775");
    LeetCode leetCode;
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

void TestLeetCode776(void)
{
    Logger::WriteMessage("Test Leet Code 776");
    LeetCode leetCode;
    string input = "[4,2,6,1,3,5,7]";
    int V = 2;
    Logger::WriteMessage("input = " + input);
    TreeNode * root = leetCode.deserialize(input);
    vector<TreeNode *> result = leetCode.splitBST(root, V);
    string smallTree = leetCode.serialize(result[0]);
    string largeTree = leetCode.serialize(result[1]);
    Logger::WriteMessage("smallTree = " + smallTree);
    Logger::WriteMessage("largeTree = " + largeTree);
    leetCode.freeTreeNodes(result[0]);
    leetCode.freeTreeNodes(result[1]);
}

void TestLeetCode777(void)
{
    Logger::WriteMessage("Test Leet Code 777");
    LeetCode leetCode;
    string start = "RXXLRXRXL";
    string end = "XRLXXRRLX";
    bool result = leetCode.canTransform(start, end);
    Logger::WriteMessage("start = " + start + "; end = " + end + "; result = " + (string)(result? "true" : "false"));

    start = "RXXLRXRXL";
    end = "XLRXXRRLX";
    result = leetCode.canTransform(start, end);
    Logger::WriteMessage("start = " + start + "; end = " + end + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode779(void)
{
    Logger::WriteMessage("Test Leet Code 779");
    LeetCode leetCode;
    int N = 1;
    int K = 1;
    int result = leetCode.kthGrammar(N, K);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) + "; result = " + to_string(result));

    N = 2;
    K = 1;
    result = leetCode.kthGrammar(N, K);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) + "; result = " + to_string(result));

    N = 2;
    K = 2;
    result = leetCode.kthGrammar(N, K);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) + "; result = " + to_string(result));
    
    N = 4;
    K = 5;
    result = leetCode.kthGrammar(N, K);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode784(void)
{
    Logger::WriteMessage("Test Leet Code 784");
    LeetCode leetCode;
    string S = "a1b2";
    vector<string> result = leetCode.letterCasePermutation(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "3z4";
    result = leetCode.letterCasePermutation(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "12345";
    result = leetCode.letterCasePermutation(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode783(void)
{
    Logger::WriteMessage("Test Leet Code 783");
    LeetCode leetCode;
    string input = "[4,2,6,1,3,null,null]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    int min_diff = leetCode.minDiffInBST(root);
    Logger::WriteMessage("min_diff = " + to_string(min_diff));
}

void TestLeetCode782(void)
{
    Logger::WriteMessage("Test Leet Code 782");
    LeetCode leetCode;
    vector<vector<int>> board = { {0, 1, 1, 0},{0, 1, 1, 0},{1, 0, 0, 1},{1, 0, 0, 1} };
    int result = leetCode.movesToChessboard(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board = { {0, 1},{1, 0} };
    result = leetCode.movesToChessboard(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board = { {1, 0},{1, 0} };
    result = leetCode.movesToChessboard(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode788(void)
{
    Logger::WriteMessage("Test Leet Code 788");
    LeetCode leetCode;
    int N = 110;
    int result = leetCode.rotatedDigits(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode789(void)
{
    Logger::WriteMessage("Test Leet Code 789");
    LeetCode leetCode;
    vector<vector<int>> ghosts = { { 1, 0 },{ 0, 3 } };
    vector<int> target = { 0, 1 };
    bool result = leetCode.escapeGhosts(ghosts, target);
    Logger::WriteMessage(ghosts);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    ghosts = { { 1, 0 } };
    target = { 2, 0 };
    result = leetCode.escapeGhosts(ghosts, target);
    Logger::WriteMessage(ghosts);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    ghosts = { { 2, 0 } };
    target = { 1, 0 };
    result = leetCode.escapeGhosts(ghosts, target);
    Logger::WriteMessage(ghosts);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode790(void)
{
    Logger::WriteMessage("Test Leet Code 790");
    LeetCode leetCode;
    int N = 4;
    int result = leetCode.numTilings(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode791(void)
{
    Logger::WriteMessage("Test Leet Code 791");
    LeetCode leetCode;
    string S = "cba";
    string T = "abcd";
    string result = leetCode.customSortString(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + result);
}


void TestLeetCode792(void)
{
    Logger::WriteMessage("Test Leet Code 792");
    LeetCode leetCode;
    string S = "abcde";
    vector<string> words = { "a", "bb", "acd", "ace" };
    int result = leetCode.numMatchingSubseq(S, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode795(void)
{
    Logger::WriteMessage("Test Leet Code 795");
    LeetCode leetCode;
    vector<int> A = { 2, 1, 4, 3 };
    int L = 2;
    int R = 3;
    int result = leetCode.numSubarrayBoundedMax(A, L, R);
    Logger::WriteMessage(A);
    Logger::WriteMessage("L = " + to_string(L) + "; R = " + to_string(R) + "; result = " + to_string(result));

    A = { 2, 1, 1, 3, 1, 1, 4, 3, 1, 1, 3, 5 };
    L = 2;
    R = 3;
    result = leetCode.numSubarrayBoundedMax(A, L, R);
    Logger::WriteMessage(A);
    Logger::WriteMessage("L = " + to_string(L) + "; R = " + to_string(R) + "; result = " + to_string(result));
}

void TestLeetCode793(void)
{
    Logger::WriteMessage("Test Leet Code 793");
    LeetCode leetCode;
    int K = 0;
    int result = leetCode.preimageSizeFZF(K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    K = 5;
    result = leetCode.preimageSizeFZF(K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode797(void)
{
    Logger::WriteMessage("Test Leet Code 797");
    LeetCode leetCode;
    vector<vector<int>> graph = { {1, 2},{3},{3},{} };
    vector<vector<int>> result = leetCode.allPathsSourceTarget(graph);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(result);
}

void TestLeetCode798(void)
{
    Logger::WriteMessage("Test Leet Code 798");
    LeetCode leetCode;
    vector<int> A = { 2, 3, 1, 4, 0 };
    int result = leetCode.bestRotation(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode799(void)
{
    Logger::WriteMessage("Test Leet Code 799");
    LeetCode leetCode;
    int poured = 1;
    int query_glass = 1;
    int query_row = 1;
    double result = leetCode.champagneTower(poured, query_row, query_glass);
    Logger::WriteMessage("poured = " + to_string(poured) + "; query_row = " + to_string(query_row) +
        "; query_glass = " + to_string(query_glass) + "; result = " + to_string(result));

    poured = 2;
    query_glass = 1;
    query_row = 1;
    result = leetCode.champagneTower(poured, query_row, query_glass);
    Logger::WriteMessage("poured = " + to_string(poured) + "; query_row = " + to_string(query_row) +
        "; query_glass = " + to_string(query_glass) + "; result = " + to_string(result));
}



void TestLeetCode801(void)
{
    Logger::WriteMessage("Test Leet Code 801");
    LeetCode leetCode;
    vector<int> A = { 1, 3, 5, 4 };
    vector<int> B = { 1, 2, 3, 7 };
    int result = leetCode.minSwap(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result = " + to_string(result));
}




void TestLeetCode804(void)
{
    Logger::WriteMessage("Test Leet Code 804");
    LeetCode leetCode;
    vector<string> words = { "gin", "zen", "gig", "msg" };
    int result = leetCode.uniqueMorseRepresentations(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode806(void)
{
    Logger::WriteMessage("Test Leet Code 806");
    LeetCode leetCode;
    vector<int> widths = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    string S = "abcdefghijklmnopqrst";
    vector<int> result = leetCode.numberOfLines(widths, S);
    Logger::WriteMessage(widths);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    widths = { 4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,100 };
    S = "bbbcccdddaaa";
    result = leetCode.numberOfLines(widths, S);
    Logger::WriteMessage(widths);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode807(void)
{
    Logger::WriteMessage("Test Leet Code 807");
    LeetCode leetCode;
    vector<vector<int>> grid = { {3, 0, 8, 4},{2, 4, 5, 7},{9, 2, 6, 3},{0, 3, 1, 0} };
    int result = leetCode.maxIncreaseKeepingSkyline(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode805(void)
{
    Logger::WriteMessage("Test Leet Code 805");
    LeetCode leetCode;

    vector<int> A = { 16, 19, 5, 0, 2, 3 };
    bool result = leetCode.splitArraySameAverageII(A);

    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    A = { 13, 1, 7, 7, 19, 13, 6 };
    result = leetCode.splitArraySameAverage(A);

    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 7, 0, 16, 11, 10, 9, 10, 9, 8 };
    result = leetCode.splitArraySameAverage(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));


    A = { 3, 1 };
    result = leetCode.splitArraySameAverage(A);

    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 1,2,3,4,5,6,7,8 };
    result = leetCode.splitArraySameAverage(A);

    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode811(void)
{
    Logger::WriteMessage("Test Leet Code 811");
    LeetCode leetCode;

    vector<string> cpdomains = { "9001 discuss.leetcode.com" };
    vector<string> result = leetCode.subdomainVisits(cpdomains);

    Logger::WriteMessage(cpdomains);
    Logger::WriteMessage(result);

    cpdomains = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
    result = leetCode.subdomainVisits(cpdomains);

    Logger::WriteMessage(cpdomains);
    Logger::WriteMessage(result);
}

void TestLeetCode808(void)
{
    Logger::WriteMessage("Test Leet Code 808");
    LeetCode leetCode;
    int N = 50;
    double result = leetCode.soupServings(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode809(void)
{
    Logger::WriteMessage("Test Leet Code 809");
    LeetCode leetCode;
    string S = "heeellooo";
    vector<string> words = { "hello", "hi", "helo" };
    int result = leetCode.expressiveWords(S, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode814(void)
{
    Logger::WriteMessage("Test Leet Code 814");
    LeetCode leetCode;
    string input = "[1,null,0,0,1]";
    Logger::WriteMessage("input = " + input);
    TreeNode * root = leetCode.deserialize(input);
    root = leetCode.pruneTree(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("output = " + output);
    leetCode.freeTreeNodes(root);

    input = "[1,0,1,0,0,0,1]";
    Logger::WriteMessage("input = " + input);
    root = leetCode.deserialize(input);
    root = leetCode.pruneTree(root);
    output = leetCode.serialize(root);
    Logger::WriteMessage("output = " + output);
    leetCode.freeTreeNodes(root);

    input = "[1,1,0,1,1,0,1,0]";
    Logger::WriteMessage("input = " + input);
    root = leetCode.deserialize(input);
    root = leetCode.pruneTree(root);
    output = leetCode.serialize(root);
    Logger::WriteMessage("output = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode813(void)
{
    Logger::WriteMessage("Test Leet Code 813");
    LeetCode leetCode;
    vector<int> A = { 9, 1, 2, 3, 9 };
    int K = 3;
    double result = leetCode.largestSumOfAverages(A, K);
    Logger::WriteMessage(A);

    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}


void TestLeetCode819(void)
{
    Logger::WriteMessage("Test Leet Code 819");
    LeetCode leetCode;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = { "hit" };
    string result = leetCode.mostCommonWord(paragraph, banned);
    Logger::WriteMessage(paragraph);
    Logger::WriteMessage(banned);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode821(void)
{
    Logger::WriteMessage("Test Leet Code 821");
    LeetCode leetCode;
    string S = "loveleetcode";
    char C = 'e';
    vector<int> result = leetCode.shortestToChar(S, C);
    string c_str; 
    Logger::WriteMessage("S = " + S + "; C = " + string(1, C));
    Logger::WriteMessage(result);
}

void TestLeetCode816(void)
{
    Logger::WriteMessage("Test Leet Code 816");
    LeetCode leetCode;
    string S = "(123)";
    vector<string> result = leetCode.ambiguousCoordinates(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "(00011)";
    result = leetCode.ambiguousCoordinates(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "(0123)";
    result = leetCode.ambiguousCoordinates(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "(100)";
    result = leetCode.ambiguousCoordinates(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode820(void)
{
    Logger::WriteMessage("Test Leet Code 820");
    LeetCode leetCode;
    vector<string> words = { "time", "me", "bell" };	
    int result = leetCode.minimumLengthEncoding(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode824(void)
{
    Logger::WriteMessage("Test Leet Code 824");
    LeetCode leetCode;
    string S = "I speak Goat Latin";
    string result = leetCode.toGoatLatin(S);
    Logger::WriteMessage("S= " + S + "; result = " + result);

    S = "The quick brown fox jumped over the lazy dog";
    result = leetCode.toGoatLatin(S);
    Logger::WriteMessage("S= " + S + "; result = " + result);
}

void TestLeetCode822(void)
{
    Logger::WriteMessage("Test Leet Code 822");
    LeetCode leetCode;
    vector<int> fronts = { 1,2,4,4,7 };
    vector<int> backs = { 1,3,4,1,3 };
    int result = leetCode.flipgame(fronts, backs);
    Logger::WriteMessage(fronts);
    Logger::WriteMessage(backs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode736(void)
{
    LeetCode leetCode;
    string expression = "(add 1 2)";
    int expected = 3;
    int result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(mult 3 (add 2 3))";
    expected = 15;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 2 (mult x 5))";
    expected = 10;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
    expected = 14;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 3 x 2 x)";
    expected = 2;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 1 y 2 x (add x y) (add x y))";
    expected = 5;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 2 (add (let x 3 (let x 4 x)) x))";
    expected = 6;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let a1 3 b2 (add a1 1) b2)";
    expected = 4;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
}

void TestLeetCode823(void)
{
    Logger::WriteMessage("Test Leet Code 823");
    LeetCode leetCode;
    vector<int> A = { 2, 4 };
    int result = leetCode.numFactoredBinaryTrees(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2, 4, 5, 10 };
    result = leetCode.numFactoredBinaryTrees(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode825(void)
{
    Logger::WriteMessage("Test Leet Code 825");
    LeetCode leetCode;
    vector<int> ages = { 16,16 };
    int result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    ages = { 16,17,18 };
    result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    ages = { 20,30,100,110,120 };
    result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    ages = { 108, 115, 5, 24, 82 };
    result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    ages = { 73, 106, 39, 6, 26, 15, 30, 100, 71, 35, 46, 112, 6, 60, 110 };
    result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode826(void)
{
    Logger::WriteMessage("Test Leet Code 826");
    LeetCode leetCode;
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

void TestLeetCode831(void)
{
    Logger::WriteMessage("Test Leet Code 831");
    LeetCode leetCode;
    string S = "LeetCode@LeetCode.com";
    string result = leetCode.maskPII(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "AB@qq.com";
    result = leetCode.maskPII(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "1(234)567-890";
    result = leetCode.maskPII(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "86-(10)12345678";
    result = leetCode.maskPII(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode829(void)
{
    Logger::WriteMessage("Test Leet Code 829");
    LeetCode leetCode;
    int N = 5;
    int result = leetCode.consecutiveNumbersSum(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 9;
    result = leetCode.consecutiveNumbersSum(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 15;
    result = leetCode.consecutiveNumbersSum(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 27;
    result = leetCode.consecutiveNumbersSum(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode828(void)
{
    Logger::WriteMessage("Test Leet Code 828");
    LeetCode leetCode;
    string S = "ABC";
    int result = leetCode.uniqueLetterString(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "ABA";
    result = leetCode.uniqueLetterString(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode832(void)
{
    Logger::WriteMessage("Test Leet Code 832");
    LeetCode leetCode;
    vector<vector<int>> A = { {1, 1, 0 },{ 1, 0, 1 },{ 0, 0, 0 } };
    vector<vector<int>> result = leetCode.flipAndInvertImage(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { {1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0} };
    result = leetCode.flipAndInvertImage(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode835(void)
{
    Logger::WriteMessage("Test Leet Code 835");
    LeetCode leetCode;
    vector<vector<int>> A = { { 1,1,0 },{ 1,1,0 },{ 0,1,0 } };
    vector<vector<int>> B = { { 0,0,0 },{ 0,1,1 },{ 0,0,1 } };
    int result = leetCode.largestOverlap(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode833(void)
{
    Logger::WriteMessage("Test Leet Code 833");
    LeetCode leetCode;
    string S = "abcd";
    vector<int> indexes = { 0, 2 };
    vector<string> sources = { "a", "cd" };
    vector<string> targets = { "eee","ffff" };
    string result = leetCode.findReplaceString(S, indexes, sources, targets);
    Logger::WriteMessage(indexes);
    Logger::WriteMessage(sources);
    Logger::WriteMessage(targets);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "abcd";
    indexes = { 0, 2 };
    sources = { "ab","ec" };
    targets = { "eee","ffff" };
    result = leetCode.findReplaceString(S, indexes, sources, targets);
    Logger::WriteMessage(indexes);
    Logger::WriteMessage(sources);
    Logger::WriteMessage(targets);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "vmokgggqzp";
    indexes = { 3, 5, 1 };
    sources = { "kg", "ggq", "mo" };
    targets = { "s", "so", "bfr" };
    result = leetCode.findReplaceString(S, indexes, sources, targets);
    Logger::WriteMessage(indexes);
    Logger::WriteMessage(sources);
    Logger::WriteMessage(targets);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode834(void)
{
    Logger::WriteMessage("Test Leet Code 834");
    LeetCode leetCode;
    int N = 6;
    vector<vector<int>> edges = { {0,1},{0,2},{2,3},{2,4},{2,5} };
    vector<int> result = leetCode.sumOfDistancesInTree(N, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(result);
}

void TestLeetCode836(void)
{
    Logger::WriteMessage("Test Leet Code 836");
    LeetCode leetCode;
    vector<int> rec1 = { 0, 0, 2, 2 };
    vector<int> rec2 = { 1, 1, 3, 3 };
    Logger::WriteMessage(rec1);
    Logger::WriteMessage(rec2);
    bool result = leetCode.isRectangleOverlap(rec1, rec2);
    Logger::WriteMessage("Overlap = " + (string)(result ? "true" : "false"));

    rec1 = { 0, 0, 1, 1 };
    rec2 = { 1, 0, 2, 1 };
    Logger::WriteMessage(rec1);
    Logger::WriteMessage(rec2);
    result = leetCode.isRectangleOverlap(rec1, rec2);
    Logger::WriteMessage("Overlap = " + (string)(result ? "true" : "false"));
}

void TestLeetCode838(void)
{
    Logger::WriteMessage("Test Leet Code 838");
    LeetCode leetCode;
    string dominoes = ".L.R...LR..L..";
    string result = leetCode.pushDominoes(dominoes);
    Logger::WriteMessage("dominoes = " + dominoes + "; result = " + result);

    dominoes = "RR.L";
    result = leetCode.pushDominoes(dominoes);
    Logger::WriteMessage("dominoes = " + dominoes + "; result = " + result);

    dominoes = "LL";
    result = leetCode.pushDominoes(dominoes);
    Logger::WriteMessage("dominoes = " + dominoes + "; result = " + result);

}

void TestLeetCode837(void)
{
    Logger::WriteMessage("Test Leet Code 837");
    LeetCode leetCode;
    int N = 10; 
    int K = 1;
    int W = 10;
    double result = leetCode.new21Game(N, K, W);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) + "; W = " + to_string(W) + "; result = " + to_string(result));

    N = 6;
    K = 1;
    W = 10;
    result = leetCode.new21Game(N, K, W);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) + "; W = " + to_string(W) + "; result = " + to_string(result));

    N = 21;
    K = 17;
    W = 10;
    result = leetCode.new21Game(N, K, W);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K) + "; W = " + to_string(W) + "; result = " + to_string(result));
}

void TestLeetCode843(void)
{
    Logger::WriteMessage("Test Leet Code 843");
    LeetCode leetCode;
    Master master("acckzz");
    vector<string> wordlist = { "acckzz", "ccbazz", "eiowzz", "abcczz" };
    string result = leetCode.findSecretWord(wordlist, master);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode840(void)
{
    Logger::WriteMessage("Test Leet Code 840");
    LeetCode leetCode;
    vector<vector<int>> grid = { {4,3,8,4}, {9,5,1,9}, { 2,7,6,2 } };
    int result = leetCode.numMagicSquaresInside(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode842(void)
{
    Logger::WriteMessage("Test Leet Code 842");
    LeetCode leetCode;
    string S = "123456579";
    vector<int> result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "11235813";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "112358130";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "0123";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "1101111";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);	

    S = "011";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "214748364721474836422147483641";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode844(void)
{
    Logger::WriteMessage("Test Leet Code 844");
    LeetCode leetCode;
    string S = "ab#c";
    string T = "ad#c";
    bool result = leetCode.backspaceCompare(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T);
    Logger::WriteMessage(result ? "true" : "false");

    S = "ab##";
    T = "c#d#";
    result = leetCode.backspaceCompare(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T);
    Logger::WriteMessage(result ? "true" : "false");

    S = "a##c";
    T = "#a#c";
    result = leetCode.backspaceCompare(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T);
    Logger::WriteMessage(result ? "true" : "false");

    S = "a#c"; 
    T = "b";
    result = leetCode.backspaceCompare(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T);
    Logger::WriteMessage(result ? "true" : "false");
}


void TestLeetCode845(void)
{
    Logger::WriteMessage("Test Leet Code 845");
    LeetCode leetCode;
    vector<int> A = { 2,1,4,7,3,2,5 };
    int result = leetCode.longestMountain(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2,2,2 };
    result = leetCode.longestMountain(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode849(void)
{
    Logger::WriteMessage("Test Leet Code 849");
    LeetCode leetCode;
    vector<int> seats = { 1,0,0,0,1,0,1 };
    int result = leetCode.maxDistToClosest(seats);
    Logger::WriteMessage(seats);
    Logger::WriteMessage("result = " + to_string(result));

    seats = { 1,0,0,0 };
    result = leetCode.maxDistToClosest(seats);
    Logger::WriteMessage(seats);
    Logger::WriteMessage("result = " + to_string(result));

    seats = { 0,0,0,1 };
    result = leetCode.maxDistToClosest(seats);
    Logger::WriteMessage(seats);
    Logger::WriteMessage("result = " + to_string(result));

    seats = { 0, 1, 0, 0, 0, 1 };
    result = leetCode.maxDistToClosest(seats);
    Logger::WriteMessage(seats);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode850(void)
{
    Logger::WriteMessage("Test Leet Code 850");
    LeetCode leetCode;
    vector<vector<int>> rectangles = { {0, 0, 2, 2},{1, 0, 2, 3},{1, 0, 3, 1} };
    int result = leetCode.rectangleArea(rectangles);
    Logger::WriteMessage(rectangles);
    Logger::WriteMessage("result = " + to_string(result));

    rectangles = { {0, 0, 1000000000, 1000000000} };
    result = leetCode.rectangleArea(rectangles);
    Logger::WriteMessage(rectangles);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode852(void)
{
    Logger::WriteMessage("Test Leet Code 856");
    LeetCode leetCode;
    vector<int> A = { 0,1,0 };
    int result = leetCode.peakIndexInMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,2,1,0 };
    result = leetCode.peakIndexInMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode848(void)
{
    Logger::WriteMessage("Test Leet Code 848");
    LeetCode leetCode;
    string S = "abc"; 
    vector<int> shifts = { 3,5,9 };
    string result = leetCode.shiftingLetters(S, shifts);
    Logger::WriteMessage(shifts);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "mkgfzkkuxownxvfvxasy";
    shifts = 
    { 
        505870226, 437526072, 266740649, 224336793, 532917782, 311122363, 567754492, 595798950, 
        81520022, 684110326, 137742843, 275267355, 856903962, 148291585, 919054234, 467541837, 
        622939912, 116899933, 983296461, 536563513 
    };		
    result = leetCode.shiftingLetters(S, shifts);
    Logger::WriteMessage(shifts);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode853(void)
{
    Logger::WriteMessage("Test Leet Code 853");
    LeetCode leetCode;
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

void TestLeetCode855(void)
{
    Logger::WriteMessage("Test Leet Code 855");
    vector<string> commands = { "ExamRoom","seat","seat","seat","seat","leave","seat" };
    vector<int> parameters = { 10, -1, -1, -1, -1, 4, -1 };
    vector<int> result(commands.size());
    ExamRoom *exam_room = nullptr;

    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "ExamRoom")
        {
            exam_room = new ExamRoom(parameters[0]);
            result[i] = -1;
        }
        else if (commands[i] == "seat")
        {
            result[i] = exam_room->seat();
        }
        else
        {
            exam_room->leave(parameters[i]);
            result[i] = -1;
        }
    }
    if (exam_room != nullptr) delete exam_room;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);
}

void TestLeetCode859(void)
{
    Logger::WriteMessage("Test Leet Code 859");
    LeetCode leetCode;
    string A = "ab";
    string B = "ba";
    bool result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));

    A = "ab";
    B = "ab";
    result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));

    A = "aa";
    B = "aa";
    result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));

    A = "aaaaaaabc";
    B = "aaaaaaacb";
    result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));

    A = "";
    B = "aa";
    result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode856(void)
{
    Logger::WriteMessage("Test Leet Code 856");
    LeetCode leetCode;
    string S = "()";
    int result = leetCode.scoreOfParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "(())";
    result = leetCode.scoreOfParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "()()";
    result = leetCode.scoreOfParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "(()(()))";
    result = leetCode.scoreOfParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode209(void)
{
    Logger::WriteMessage("Test Leet Code 209");
    LeetCode leetCode;
    vector <int> nums = { 2,3,1,2,4,3 };
    int s = 7;
    Logger::WriteMessage(nums);
    int result = leetCode.minSubArrayLen(s, nums);
    int expect = 2;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = {};
    s = -1;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = -1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { -1 };
    s = 1;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = -1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { 2 };
    s = 1;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { -2, 2 };
    s = 1;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { 4, -2, 5 };
    s = 6;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 3;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { 4, -2, 5 };
    s = 4;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { 4, -2, 5 };
    s = 5;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { 7, -9, 12 };
    s = 11;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { -1, 2, 3, -3, 10, 0, -1 };
    s = -1;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { -1, 2, 3, -3, 10, 0, -1 };
    s = 5;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { -1, 2, 3, -3, 10, 0, -1 };
    s = 10;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { -1, 2, 3, -3, 10, 0, -1 };
    s = 12;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 4;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { -1, 2, 3, -3, 10, 0, -1 };
    s = 13;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = -1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { 5, 1, -5, 10 };
    s = 7;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { 0 };
    s = 0;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));

    nums = { -1 };
    s = -2;
    Logger::WriteMessage(nums);
    result = leetCode.minSubArrayLen(s, nums);
    expect = 1;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));
}

void TestLeetCode860(void)
{
    Logger::WriteMessage("Test Leet Code 860");
    LeetCode leetCode;
    vector<int> bills = { 5,5,5,10,20 };
    bool result = leetCode.lemonadeChange(bills);
    Logger::WriteMessage(bills);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    bills = { 5,5,10 };
    result = leetCode.lemonadeChange(bills);
    Logger::WriteMessage(bills);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    bills = { 10,10 };
    result = leetCode.lemonadeChange(bills);
    Logger::WriteMessage(bills);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    bills = { 5,5,10,10,20 };
    result = leetCode.lemonadeChange(bills);
    Logger::WriteMessage(bills);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode861(void)
{
    Logger::WriteMessage("Test Leet Code 861");
    LeetCode leetCode;
    vector<vector<int>> A = { {0, 0, 1, 1},{1, 0, 1, 0},{1, 1, 0, 0} };
    int result = leetCode.matrixScore(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { {0, 1},{0, 1},{0, 1},{0, 0} };
    result = leetCode.matrixScore(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
    
}

void TestLeetCode863(void)
{
    Logger::WriteMessage("Test Leet Code 863");
    LeetCode leetCode;
    string input = "[3,5,1,6,2,0,8,null,null,7,4]";
    int value = 5;
    int K = 2;
    TreeNode * root = leetCode.deserialize(input);
    TreeNode * target = new TreeNode(value);
    vector<int> result = leetCode.distanceK(root, target, K);
    Logger::WriteMessage(input);
    Logger::WriteMessage("value = " + to_string(value) + "; target = " + to_string(target->val) + "; K = " + to_string(K));
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(target);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    value = 1;
    K = 3;
    root = leetCode.deserialize(input);
    target = new TreeNode(value);
    result = leetCode.distanceK(root, target, K);
    Logger::WriteMessage(input);
    Logger::WriteMessage("value = " + to_string(value) + "; target = " + to_string(target->val) + "; K = " + to_string(K));
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(target);
}

void TestLeetCode862(void)
{
    Logger::WriteMessage("Test Leet Code 862");
    LeetCode leetCode;
    vector<int> A = { 1 };
    int K = 1;
    int result = leetCode.shortestSubarray(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 1,2 };
    K = 4;
    result = leetCode.shortestSubarray(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 2, -1, 2 };
    K = 3;
    result = leetCode.shortestSubarray(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode710(void)
{
    Logger::WriteMessage("Test Leet Code 710");
    Solution * solution;
    vector<string> command = { "Solution","pick","pick","pick" };
    int N = 1;
    vector<int> blacklist = {};
    vector<int> result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);

    command = { "Solution","pick","pick","pick" };
    N = 2;
    blacklist = {};
    result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);

    command = { "Solution","pick","pick","pick" };
    N = 3;
    blacklist = {1};
    result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);

    command = { "Solution","pick","pick","pick","pick","pick","pick" };
    N = 4;
    blacklist = { 2 };
    result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);

    command = { "Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick" };
    N = 4;
    blacklist = { 2, 1 };
    result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);
}

void TestLeetCode867(void)
{
    Logger::WriteMessage("Test Leet Code 867");
    LeetCode leetCode;
    vector<vector<int>> A = { {1,2,3},{4,5,6}, {7,8,9} };
    vector<vector<int>> result = leetCode.transpose(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { { 1,2,3 },{ 4,5,6 } };
    result = leetCode.transpose(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode865(void)
{
    Logger::WriteMessage("Test Leet Code 865");
    LeetCode leetCode;
    string input = "[3,5,1,6,2,0,8,null,null,7,4]";
    TreeNode * root = leetCode.deserialize(input);
    TreeNode * result = leetCode.subtreeWithAllDeepest(root);
    string output = leetCode.serialize(result);
    Logger::WriteMessage("input = " + input + "; output = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode868(void)
{
    Logger::WriteMessage("Test Leet Code 868");
    LeetCode leetCode;
    int N = 22;
    int result = leetCode.binaryGap(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 5;
    result = leetCode.binaryGap(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 6;
    result = leetCode.binaryGap(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 8;
    result = leetCode.binaryGap(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}


void TestLeetCode870(void)
{
    Logger::WriteMessage("Test Leet Code 870");
    LeetCode leetCode;
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


void TestLeetCode872(void)
{
    Logger::WriteMessage("Test Leet Code 872");
    LeetCode leetCode;
    string input1 = "[1, 2]";
    string input2 = "[2, 2]";
    TreeNode * tree1 = leetCode.deserialize(input1);
    TreeNode * tree2 = leetCode.deserialize(input2);
    bool result = leetCode.leafSimilar(tree1, tree2);
    Logger::WriteMessage("leaf similiar = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(tree1);
    leetCode.freeTreeNodes(tree2);
}

void TestLeetCode874(void)
{
    Logger::WriteMessage("Test Leet Code 874");
    LeetCode leetCode;
    vector<int> commands = { 4, -1, 3 };
    vector<vector<int>> obstacles = {};
    unsigned int result = leetCode.robotSim(commands, obstacles);
    Logger::WriteMessage(commands);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage("result = " + to_string(result));

    commands = { 4,-1,4,-2,4 };
    obstacles = {{ 2,4 }};
    result = leetCode.robotSim(commands, obstacles);
    Logger::WriteMessage(commands);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode873(void)
{
    Logger::WriteMessage("Test Leet Code 873");
    LeetCode leetCode;
    vector<int> A = { 1,2,3,4,5,6,7,8 };
    int result = leetCode.lenLongestFibSubseq(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1, 3, 7, 11, 12, 14, 18 };
    result = leetCode.lenLongestFibSubseq(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode700(void)
{
    Logger::WriteMessage("Test Leet Code 700");
    LeetCode leetCode;
    string input = "[4, 2, 7, 1, 3]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    int value = 2;
    TreeNode * result = leetCode.searchBST(root, value);
    string output = leetCode.serialize(result);
    Logger::WriteMessage(output);

    value = 5;
    result = leetCode.searchBST(root, value);
    output = leetCode.serialize(result);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode701(void)
{
    Logger::WriteMessage("Test Leet Code 701");
    LeetCode leetCode;
    string input = "[4, 2, 7, 1, 3]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    int value = 5;
    root = leetCode.insertIntoBST(root, value);
    string output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode428(void)
{
    Logger::WriteMessage("Test Leet Code 428");
    LeetCode leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node * root = treeCodec.deserialize(input);
    string output = treeCodec.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeNodes(root);
}

void TestLeetCode559(void)
{
    Logger::WriteMessage("Test Leet Code 559");
    LeetCode leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node * root = treeCodec.deserialize(input);
    int result = leetCode.maxDepth(root);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeNodes(root);
}

void TestLeetCode589(void)
{
    Logger::WriteMessage("Test Leet Code 589");
    LeetCode leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node * root = treeCodec.deserialize(input);
    vector<int> result = leetCode.preorder(root);
    Logger::WriteMessage(result);
    leetCode.freeNodes(root);
}

void TestLeetCode429(void)
{
    Logger::WriteMessage("Test Leet Code 429");
    LeetCode leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node * root = treeCodec.deserialize(input);
    vector<vector<int>> result = leetCode.levelOrder(root);
    Logger::WriteMessage(result);
    leetCode.freeNodes(root);
}

void TestLeetCode590(void)
{
    Logger::WriteMessage("Test Leet Code 590");
    LeetCode leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node * root = treeCodec.deserialize(input);
    vector<int> result = leetCode.postorder(root);
    Logger::WriteMessage(result);
    leetCode.freeNodes(root);
}

void TestLeetCode704(void)
{
    Logger::WriteMessage("Test Leet Code 704");
    LeetCode leetCode;
    vector<int> nums = { -1,0,3,5,9,12 };
    int target = 9;
    Logger::WriteMessage(nums);
    int result = leetCode.binarySearchI(nums, target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { -1,0,3,5,9,12 };
    target = 2;
    Logger::WriteMessage(nums);
    result = leetCode.binarySearchI(nums, target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}


void TestLeetCode877(void)
{
    Logger::WriteMessage("Test Leet Code 877");
    LeetCode leetCode;
    vector<int> piles = { 5,3,4,5 };
    bool result = leetCode.stoneGame(piles);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("First player can win: " + (string)(result? "true":"false"));
}

void TestLeetCode528(void)
{
    Logger::WriteMessage("Test Leet Code 528");
    vector<string> commands =
    {
        "Solution","pickIndex","pickIndex","pickIndex","pickIndex", "pickIndex","pickIndex","pickIndex","pickIndex","pickIndex", "pickIndex"
    };
    vector<vector<int>> data =
    {
        {3, 14, 1, 7},{},{},{},{},{}
    };
    vector<string> result;
    RandomWithWeight * solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            vector<int> parameter;
            for (size_t j = 0; j < data[i].size(); j++)
            {
                parameter.push_back(data[i][j]);
            }
            solution = new RandomWithWeight(parameter);
            result.push_back("null");
        }
        else if (commands[i] == "pickIndex")
        {
            solution->pickIndex();
            result.push_back(to_string(solution->pickIndex()));
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode519(void)
{
    Logger::WriteMessage("Test Leet Code 519");
    vector<string> commands =
    {
        "Solution","flip","flip","flip","flip"
    };
    vector<vector<int>> data =
    {
        { 2,3 },{},{},{},{}
    };
    vector<string> result;
    RandomFlipMatrix* solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomFlipMatrix(data[i][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "flip")
        {
            vector<int> position = solution->flip();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
        else if (commands[i] == "reset")
        {
            solution->reset();
            result.push_back("null");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);

    commands =
    {
        "Solution","flip","flip","reset","flip"
    };
    data =
    {
        { 1,2 },{},{},{},{}
    };
    result.clear();
    solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomFlipMatrix(data[i][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "flip")
        {
            vector<int> position = solution->flip();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
        else if (commands[i] == "reset")
        {
            solution->reset();
            result.push_back("null");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}


void TestLeetCode478(void)
{
    Logger::WriteMessage("Test Leet Code 478");
    vector<string> commands =
    {
        "Solution","randPoint","randPoint","randPoint"
    };
    vector<vector<double>> data =
    {
        { 1, 0, 0 },{},{},{}
    };
    vector<string> result;
    RandomCirclePoint* solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomCirclePoint(data[i][0], data[i][1], data[i][2]);
            result.push_back("null");
        }
        else if (commands[i] == "randPoint")
        {
            vector<double> position = solution->randPoint();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);

    commands =
    {
        "Solution","randPoint","randPoint","randPoint"
    };
    data =
    {
        { 10, 5, -7.5 },{},{},{}
    };
    result.clear();
    solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomCirclePoint(data[i][0], data[i][1], data[i][2]);
            result.push_back("null");
        }
        else if (commands[i] == "randPoint")
        {
            vector<double> position = solution->randPoint();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode497(void)
{
    Logger::WriteMessage("Test Leet Code 497");
    vector<string> commands =
    {
        "Solution","pick","pick","pick", "pick","pick","pick","pick","pick","pick", "pick","pick","pick"
    };
    vector<vector<vector<int>>> data =
    {
        {{ 1, 1, 5, 5 }}, {}, {}, {},{}, {}, {},{},{},{},{},{},{}
    };
    vector<string> result;
    RandomRectanglePoint* solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomRectanglePoint(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "pick")
        {
            vector<int> position = solution->pick();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data[0]);
    Logger::WriteMessage(result);

    commands =
    {
        "Solution","pick","pick","pick","pick","pick"
    };
    data =
    {
        {{-2,-2,-1,-1},{1,0,3,0}}, {}, {}, {}, {}, {}
    };
    result.clear();
    solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomRectanglePoint(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "pick")
        {
            vector<int> position = solution->pick();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data[0]);
    Logger::WriteMessage(result);
}

void TestLeetCode622(void)
{
    Logger::WriteMessage("Test Leet Code 622");
    vector<string> commands =
    {
        "MyCircularQueue","enQueue","enQueue","enQueue", "enQueue", "Rear", "isFull","deQueue","enQueue", "Rear","deQueue","deQueue","deQueue","deQueue","isEmpty"
    };
    vector<vector<int>> data =
    {
        {3},{ 1 },{ 2 },{ 3 },{ 4 },{ },{ },{ },{ 4 },{}, {}, {}, {}, {}, {}
    };
    vector<string> result;
    MyCircularQueue* queue = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MyCircularQueue")
        {
            queue = new MyCircularQueue(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "enQueue")
        {
            bool success = queue->enQueue(data[i][0]);
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "Rear")
        {
            int value = queue->Rear();
            result.push_back(to_string(value));
        }
        else if (commands[i] == "deQueue")
        {
            bool success = queue->deQueue();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "isFull")
        {
            bool success = queue->isFull();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "isEmpty")
        {
            bool success = queue->isEmpty();
            result.push_back(success ? "true" : "false");
        }
    }
    delete queue;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode641(void)
{
    Logger::WriteMessage("Test Leet Code 641");
    vector<string> commands =
    {
        "MyCircularDeque","insertLast","insertLast","insertFront", "insertFront", "getRear", "isFull","deleteLast","insertFront", "getFront","deleteFront","deleteFront","deleteFront","deleteFront","isEmpty"
    };
    vector<vector<int>> data =
    {
        { 3 },{ 1 },{ 2 },{ 3 },{ 4 },{},{},{},{ 4 },{},{},{},{},{},{}
    };
    vector<string> result;
    MyCircularDeque* deque = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MyCircularDeque")
        {
            deque = new MyCircularDeque(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "insertFront")
        {
            bool success = deque->insertFront(data[i][0]);
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "insertLast")
        {
            bool success = deque->insertLast(data[i][0]);
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "getFront")
        {
            int value = deque->getFront();
            result.push_back(to_string(value));
        }
        else if (commands[i] == "getRear")
        {
            int value = deque->getRear();
            result.push_back(to_string(value));
        }
        else if (commands[i] == "deleteFront")
        {
            bool success = deque->deleteFront();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "deleteLast")
        {
            bool success = deque->deleteLast();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "isFull")
        {
            bool success = deque->isFull();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "isEmpty")
        {
            bool success = deque->isEmpty();
            result.push_back(success ? "true" : "false");
        }
    }
    delete deque;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode883(void)
{
    Logger::WriteMessage("Test Leet Code 883");
    LeetCode leetCode;
    vector<vector<int>> grid = 
    { 
        {2}
    };
    int result = leetCode.projectionArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1,2},{3,4}
    };
    result = leetCode.projectionArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        { 1,0 },{ 0,2 }
    };
    result = leetCode.projectionArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1,1,1},{1,0,1},{1,1,1}
    };
    result = leetCode.projectionArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {2,2,2},{2,1,2},{2,2,2}
    };
    result = leetCode.projectionArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode881(void)
{
    Logger::WriteMessage("Test Leet Code 881");
    LeetCode leetCode;
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

void TestLeetCode457(void)
{
    Logger::WriteMessage("Test Leet Code 457");
    LeetCode leetCode;
    vector<int> nums = { 2, -1, 1, 2, 2 };
    bool result = leetCode.circularArrayLoop(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { -1, 2 };
    result = leetCode.circularArrayLoop(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 2, -1, 1, -2, -2 };
    result = leetCode.circularArrayLoop(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { -2, 1, -1, -2, -2 };
    result = leetCode.circularArrayLoop(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 3, 1, 2 };
    result = leetCode.circularArrayLoop(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode426(void)
{
    Logger::WriteMessage("Test Leet Code 426");
    LeetCode leetCode;
    string input = "[4,2,5,1,3]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    TreeNode * head = leetCode.treeToDoublyList(root);
    string output;
    TreeNode * node = head;
    size_t size = 0;
    while (true)
    {
        output.append(to_string(node->val) + " ");
        size++;
        node = node->right;
        if (node == head) break;
    }
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
    node = head;
    for (size_t i = 0; i < size; i++)
    {
        node = head->right;
        delete head;
        head = node;
    }
}

void TestLeetCode703(void)
{
    Logger::WriteMessage("Test Leet Code 703");
    vector<string> commands =
    {
        "KthLargest","add","add","add", "add", "add"
    };
    vector<vector<vector<int>>> data =
    {
        { {3}, {4, 5, 8, 2 }},{ {3} },{ {5} },{ {10} },{ {9} },{{4}}
    };
    vector<string> result;
    KthLargest* kthLargest = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "KthLargest")
        {
            kthLargest = new KthLargest(data[i][0][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "add")
        {
            int value = kthLargest->add(data[i][0][0]);
            result.push_back(to_string(value));
        }
    }
    delete kthLargest;
    Logger::WriteMessage(commands);
    for (size_t i = 0; i < data.size(); i++)
    {
        Logger::WriteMessage(data[i]);
    }
    Logger::WriteMessage(result);
}

void TestLeetCode702(void)
{
    Logger::WriteMessage("Test Leet Code 702");
    LeetCode leetCode;
    vector<int> reader = { -1, 0, 3, 5, 9, 12 };
    int target = 9;
    int result = leetCode.searchStream(reader, target);
    Logger::WriteMessage(reader);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    reader = { -1, 0, 3, 5, 9, 12 };
    target = 2;
    result = leetCode.searchStream(reader, target);
    Logger::WriteMessage(reader);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode431(void)
{
    Logger::WriteMessage("Test Leet Code 431");
    LeetCode leetCode;
    NaryTreeCodec  treeCodec;
    NaryTreeBinaryCodec b_treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node * root = treeCodec.deserialize(input);
    TreeNode * b_tree = b_treeCodec.encode(root);
    Node * nary_tree = b_treeCodec.decode(b_tree);
    string output = treeCodec.serialize(nary_tree);
    Logger::WriteMessage(output);
    leetCode.freeNodes(root);
    leetCode.freeTreeNodes(b_tree);
    leetCode.freeNodes(nary_tree);
}

void TestLeetCode489(void)
{
    Logger::WriteMessage("Test Leet Code 489");
    LeetCode leetCode;
    vector<vector<int>> room = 
    {
        {1,1,1,1,1,0,1,1},
        {1,1,1,1,1,0,1,1},
        {1,0,1,1,1,1,1,1},
        {0,0,0,1,0,0,0,0},
        {1,1,1,1,1,1,1,1}
    };
    int row = 1;
    int col = 3;
    Logger::WriteMessage(room);
    leetCode.cleanRoom(room, row, col);
    Logger::WriteMessage(room);
}

void TestLeetCode884(void)
{
    Logger::WriteMessage("Test Leet Code 884");
    LeetCode leetCode;
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

void TestLeetCode887(void)
{
    Logger::WriteMessage("Test Leet Code 887");
    LeetCode leetCode;
    int K = 1;
    int N = 2;
    int result = leetCode.superEggDrop(K, N);
    Logger::WriteMessage("K = " + to_string(K) + "; N = " + to_string(N) + "; result = " + to_string(result));

    K = 2;
    N = 6;
    result = leetCode.superEggDrop(K, N);
    Logger::WriteMessage("K = " + to_string(K) + "; N = " + to_string(N) + "; result = " + to_string(result));

    K = 3;
    N = 14;
    result = leetCode.superEggDrop(K, N);
    Logger::WriteMessage("K = " + to_string(K) + "; N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode880(void)
{
    Logger::WriteMessage("Test Leet Code 880");
    LeetCode leetCode;
    string S = "leet2code3";
    int K = 10;
    string result = leetCode.decodeAtIndex(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "ha22";
    K = 5;
    result = leetCode.decodeAtIndex(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "a2345678999999999999999";
    K = 1;
    result = leetCode.decodeAtIndex(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "vzpp636m8y";
    K = 2920;
    result = leetCode.decodeAtIndex(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);
}

void TestLeetCode885(void)
{
    Logger::WriteMessage("Test Leet Code 885");
    LeetCode leetCode;
    int R = 1;
    int C = 4;
    int r0 = 0;
    int c0 = 0;
    vector<vector<int>> result = leetCode.spiralMatrixIII(R, C, r0, c0);
    Logger::WriteMessage("R = " + to_string(R) + "; C = " + to_string(C) + "; r0 = " + to_string(r0) + "; c0 = " + to_string(c0));
    Logger::WriteMessage(result);

    R = 5;
    C = 6;
    r0 = 1;
    c0 = 4;
    result = leetCode.spiralMatrixIII(R, C, r0, c0);
    Logger::WriteMessage("R = " + to_string(R) + "; C = " + to_string(C) + "; r0 = " + to_string(r0) + "; c0 = " + to_string(c0));
    Logger::WriteMessage(result);
}

void TestLeetCode888(void)
{
    Logger::WriteMessage("Test Leet Code 888");
    LeetCode leetCode;
    vector<int> A = { 1, 1 };
    vector<int> B = { 2, 2 };
    vector<int> result = leetCode.fairCandySwap(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { 1, 2 };
    B = { 2, 3 };
    result = leetCode.fairCandySwap(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { 2 };
    B = { 1, 3 };
    result = leetCode.fairCandySwap(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);

    A = { 1, 2, 5 };
    B = { 2, 4 };
    result = leetCode.fairCandySwap(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);
}

void TestLeetCode889(void)
{
    Logger::WriteMessage("Test Leet Code 889");
    LeetCode leetCode;
    vector<int> pre = { 1, 2, 4, 5, 3, 6, 7 };
    vector<int> post = { 4, 5, 2, 6, 7, 3, 1 };
    TreeNode * result = leetCode.constructFromPrePost(pre, post);
    string output = leetCode.serialize(result);
    Logger::WriteMessage(pre);
    Logger::WriteMessage(post);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(result);

    pre = { 1, 2, 4, 5 };
    post = { 4, 5, 2, 1 };
    result = leetCode.constructFromPrePost(pre, post);
    output = leetCode.serialize(result);
    Logger::WriteMessage(pre);
    Logger::WriteMessage(post);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(result);
}

void TestLeetCode890(void)
{
    Logger::WriteMessage("Test Leet Code 890");
    LeetCode leetCode;
    vector<string> words = { "abc","deq","mee","aqq","dkd","ccc" };
    string pattern = "abb";
    vector<string> result = leetCode.findAndReplacePattern(words, pattern);
    Logger::WriteMessage(words);
    Logger::WriteMessage(pattern);
    Logger::WriteMessage(result);
}

void TestLeetCode891(void)
{
    Logger::WriteMessage("Test Leet Code 891");
    LeetCode leetCode;
    vector<int> A = 
    { 
        5, 69, 89, 92, 31, 16, 25, 45, 63, 40, 16, 56, 24, 40, 75, 82, 40, 12, 50, 62, 92, 44, 67, 38, 92, 
        22, 91, 24, 26, 21, 100, 42, 23, 56, 64, 43, 95, 76, 84, 79, 89, 4, 16, 94, 16, 77, 92, 9, 30, 13 
    };
    int result = leetCode.sumSubseqWidths(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2, 1, 3 };
    result = leetCode.sumSubseqWidths(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode892(void)
{
    Logger::WriteMessage("Test Leet Code 892");
    LeetCode leetCode;
    vector<vector<int>> grid = {{2}};
    int result = leetCode.surfaceArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 1,2 },{ 3,4 } };
    result = leetCode.surfaceArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 1,0 },{ 0,2 } };
    result = leetCode.surfaceArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 1,0 },{ 0,2 } };
    result = leetCode.surfaceArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 1,1,1 },{ 1,0,1 }, { 1,1,1 } };
    result = leetCode.surfaceArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 2,2,2 },{ 2,1,2 },{ 2,2,2 } };
    result = leetCode.surfaceArea(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode893(void)
{
    Logger::WriteMessage("Test Leet Code 893");
    LeetCode leetCode;
    vector<string> A = { "a","b","c","a","c","c" };
    int result = leetCode.numSpecialEquivGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "aa","bb","ab","ba" };
    result = leetCode.numSpecialEquivGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "abc","acb","bac","bca","cab","cba" };
    result = leetCode.numSpecialEquivGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "abcd","cdab","adcb","cbad" };
    result = leetCode.numSpecialEquivGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode894(void)
{
    Logger::WriteMessage("Test Leet Code 894");
    LeetCode leetCode;
    int N = 7;
    vector<TreeNode *> result = leetCode.allPossibleFBT(N);
    for (size_t i = 0; i < result.size(); i++)
    {
        string output = leetCode.serialize(result[i]);
        Logger::WriteMessage(output);
        leetCode.freeTreeNodes(result[i]);
    }
}

void TestLeetCode9900(void)
{
    Logger::WriteMessage("Test Leet Code 9900");
    LeetCode leetCode;
    string str = "abc";
    int k = 2;
    int result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));

    str = "aba";
    k = 2;
    result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));

    str = "aa";
    k = 1;
    result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));

    str = "abcaaaab";
    k = 3;
    result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));

    str = "abcbaa";
    k = 3;
    result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode896(void)
{
    Logger::WriteMessage("Test Leet Code 896");
    LeetCode leetCode;
    vector<int> A = { 1, 2, 2, 3 };
    bool result = leetCode.isMonotonic(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 6, 5, 4, 4 };
    result = leetCode.isMonotonic(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 1, 3, 2 };
    result = leetCode.isMonotonic(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 1, 2, 4, 5 };
    result = leetCode.isMonotonic(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 1, 1, 1 };
    result = leetCode.isMonotonic(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode897(void)
{
    Logger::WriteMessage("Test Leet Code 897");
    LeetCode leetCode;
    string input = "[5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]";
    TreeNode * root = leetCode.deserialize(input);
    TreeNode * new_tree = leetCode.increasingBST(root);
    string output = leetCode.serialize(new_tree);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + output);
    leetCode.freeTreeNodes(new_tree);
}

void TestLeetCode898(void)
{
    Logger::WriteMessage("Test Leet Code 898");
    LeetCode leetCode;
    vector<int> A = { 0 };
    int result = leetCode.subarrayBitwiseORs(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,1,2 };
    result = leetCode.subarrayBitwiseORs(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,2,4 };
    result = leetCode.subarrayBitwiseORs(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode899(void)
{
    Logger::WriteMessage("Test Leet Code 899");
    LeetCode leetCode;
    string S = "cba";
    int K = 1;
    string result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "baaca";
    K = 3;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "abcedaa";
    K = 3;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "v";
    K = 1;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "kuh";
    K = 1;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "pplpkohe";
    K = 3;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);
}

void TestLeetCode901(void)
{
    Logger::WriteMessage("Test Leet Code 901");
    vector<string> commands =
    {
        "StockSpanner","next","next","next","next","next","next","next"
    };
    vector<vector<int>> data =
    {
        { },{ 100 },{ 80 },{ 60 },{ 70 },{ 60 },{ 75 },{ 85 }
    };
    vector<string> result;
    StockSpanner* stockSpanner = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "StockSpanner")
        {
            stockSpanner = new StockSpanner();
            result.push_back("null");
        }
        else if (commands[i] == "next")
        {
            int value = stockSpanner->next(data[i][0]);
            result.push_back(to_string(value));
        }
    }
    delete stockSpanner;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}


void TestLeetCode903(void)
{
    Logger::WriteMessage("Test Leet Code 903");
    string S = "DID";
    LeetCode leetCode;
    int result = leetCode.numPermsDISequence(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode905(void)
{
    Logger::WriteMessage("Test Leet Code 905");
    LeetCode leetCode;
    vector<int> A = { 3, 1, 2, 4 };
    vector<int> result = leetCode.sortArrayByParity(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode904(void)
{
    Logger::WriteMessage("Test Leet Code 904");
    LeetCode leetCode;
    vector<int> tree = { 1,2,1 };
    int result = leetCode.totalFruit(tree);
    Logger::WriteMessage(tree);
    Logger::WriteMessage("result = " + to_string(result));

    tree = { 0,1,2,2 };
    result = leetCode.totalFruit(tree);
    Logger::WriteMessage(tree);
    Logger::WriteMessage("result = " + to_string(result));

    tree = { 1,2,3,2,2 };
    result = leetCode.totalFruit(tree);
    Logger::WriteMessage(tree);
    Logger::WriteMessage("result = " + to_string(result));

    tree = { 3,3,3,1,2,1,1,2,3,3,4 };
    result = leetCode.totalFruit(tree);
    Logger::WriteMessage(tree);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode902(void)
{
    Logger::WriteMessage("Test Leet Code 902");
    LeetCode leetCode;
    vector<string> D = { "1", "3", "5", "7" };
    int N = 960;
    int result = leetCode.atMostNGivenDigitSet(D, N);
    Logger::WriteMessage(D);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}


void TestLeetCode908(void)
{
    Logger::WriteMessage("Test Leet Code 908");
    LeetCode leetCode;
    vector<int> A = { 1 };
    int K = 0;
    int result = leetCode.smallestRangeI(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,10 };
    K = 2;
    result = leetCode.smallestRangeI(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,3,6 };
    K = 3;
    result = leetCode.smallestRangeI(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode910(void)
{
    Logger::WriteMessage("Test Leet Code 910");
    LeetCode leetCode;
    vector<int> A = { 1 };
    int K = 0;
    int result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,10 };
    K = 2;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,3,6 };
    K = 3;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 6, 4, 10 };
    K = 5;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3, 1, 10 };
    K = 4;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 7, 8, 8 };
    K = 5;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode917(void)
{
    Logger::WriteMessage("Test Leet Code 917");
    LeetCode leetCode;
    string S = "ab-cd";
    string result = leetCode.reverseOnlyLetters(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "a-bC-dEf-ghIj";
    result = leetCode.reverseOnlyLetters(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "Test1ng-Leet=code-Q!";
    result = leetCode.reverseOnlyLetters(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}


void TestLeetCode915(void)
{
    Logger::WriteMessage("Test Leet Code 915");
    LeetCode leetCode;
    vector<int> A = { 5,0,3,8,6 };
    int result = leetCode.partitionDisjoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,1,1,0,6,12 };
    result = leetCode.partitionDisjoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,8,1,2,6,7,9 };
    result = leetCode.partitionDisjoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode916(void)
{
    Logger::WriteMessage("Test Leet Code 916");
    LeetCode leetCode;
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


void TestLeetCode922(void)
{
    Logger::WriteMessage("Test Leet Code 922");
    LeetCode leetCode;
    vector<int> A = { 4,2,5,7};
    vector<int> result = leetCode.sortArrayByParityII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode919(void)
{
    Logger::WriteMessage("Test Leet Code 919");
    LeetCode leetCode;
    vector<string> commands = { "CBTInserter", "insert", "get_root" };
    vector<string> data = { "[1]", "2", "" };
    vector<string> result;
    CBTInserter * cbtInserter = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "CBTInserter")
        {
            TreeNode * root = leetCode.deserialize(data[i]);
            cbtInserter = new CBTInserter(root);
            result.push_back("null");
        }
        else if (commands[i] == "insert")
        {
            int value = cbtInserter->insert(atoi(data[i].c_str()));
            result.push_back(to_string(value));
        }
        else if (commands[i] == "get_root")
        {
            TreeNode * root = cbtInserter->get_root();
            string value = leetCode.serialize(root);
            result.push_back(value);
        }
    }
    TreeNode * root = cbtInserter->get_root();
    leetCode.freeTreeNodes(root);
    delete cbtInserter;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);

    commands = { "CBTInserter", "insert", "insert", "get_root" };
    data = { "[1,2,3,4,5,6]", "7", "8", "" };
    result.clear();
    cbtInserter = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "CBTInserter")
        {
            TreeNode * root = leetCode.deserialize(data[i]);
            cbtInserter = new CBTInserter(root);
            result.push_back("null");
        }
        else if (commands[i] == "insert")
        {
            int value = cbtInserter->insert(atoi(data[i].c_str()));
            result.push_back(to_string(value));
        }
        else if (commands[i] == "get_root")
        {
            TreeNode * root = cbtInserter->get_root();
            string value = leetCode.serialize(root);
            result.push_back(value);
        }
    }
    root = cbtInserter->get_root();
    leetCode.freeTreeNodes(root);
    delete cbtInserter;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode911(void)
{
    Logger::WriteMessage("Test Leet Code 911");
    vector<string> commands = { "TopVotedCandidate","q","q","q","q","q","q" };
    vector<vector<int>> data = { {0,1,1,0,0,1,0, 0, 5,10,15,20,25,30} , { 3 }, { 12 }, { 25 }, { 15 }, { 24 }, { 8 } };
    vector<string> result;
    TopVotedCandidate * topVotedCandidate = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "TopVotedCandidate")
        {
            vector<int> persons;
            vector<int> times;
            for (size_t j = 0; j < data[i].size() / 2; j++)
            {
                persons.push_back(data[i][j]);
                times.push_back(data[i][j + data[i].size() / 2]);
            }

            topVotedCandidate = new TopVotedCandidate(persons, times);
            result.push_back("null");
        }
        else if (commands[i] == "q")
        {
            int value = topVotedCandidate->q(data[i][0]);
            result.push_back(to_string(value));
        }
    }
    delete topVotedCandidate;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode918(void)
{
    Logger::WriteMessage("Test Leet Code 918");
    LeetCode leetCode;

    vector<int> A = { 1,-2,3,-2 };
    int result = leetCode.maxSubarraySumCircular(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 5,-3,5 };
    result = leetCode.maxSubarraySumCircular(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,-1,2,-1 };
    result = leetCode.maxSubarraySumCircular(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,-2,2,-3 };
    result = leetCode.maxSubarraySumCircular(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { -2,-3,-1 };
    result = leetCode.maxSubarraySumCircular(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode925(void)
{
    Logger::WriteMessage("Test Leet Code 925");
    LeetCode leetCode;
    string name = "alex";
    string typed = "aaleex";
    bool result = leetCode.isLongPressedName(name, typed);
    Logger::WriteMessage("name = " + name + "; typed = " + typed + "; result = " + (string)(result ? "true" : "false"));

    name = "saeed";
    typed = "ssaaedd";
    result = leetCode.isLongPressedName(name, typed);
    Logger::WriteMessage("name = " + name + "; typed = " + typed + "; result = " + (string)(result ? "true" : "false"));

    name = "leelee";
    typed = "lleeelee";
    result = leetCode.isLongPressedName(name, typed);
    Logger::WriteMessage("name = " + name + "; typed = " + typed + "; result = " + (string)(result ? "true" : "false"));

    name = "laiden";
    typed = "laiden";
    result = leetCode.isLongPressedName(name, typed);
    Logger::WriteMessage("name = " + name + "; typed = " + typed + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode926(void)
{
    Logger::WriteMessage("Test Leet Code 926");
    LeetCode leetCode;
    string S = "00110";
    int result = leetCode.minFlipsMonoIncr(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "010110";
    result = leetCode.minFlipsMonoIncr(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "00011000";
    result = leetCode.minFlipsMonoIncr(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}


void TestLeetCode927(void)
{
    Logger::WriteMessage("Test Leet Code 927");
    LeetCode leetCode;
    vector<int> A = { 0, 1, 0, 1, 1 };
    vector<int> result = leetCode.threeEqualParts(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 1, 0, 1, 0, 1 };
    result = leetCode.threeEqualParts(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 1,1,0,1,1 };
    result = leetCode.threeEqualParts(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0 };
    result = leetCode.threeEqualParts(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode929(void)
{
    Logger::WriteMessage("Test Leet Code 929");
    LeetCode leetCode;
    vector<string> emails =
    {
        "test.email+alex@leetcode.com", 
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    int result = leetCode.numUniqueEmails(emails);
    Logger::WriteMessage(emails);
    Logger::WriteMessage("result = " + to_string(result));

}

void TestLeetCode932(void)
{
    Logger::WriteMessage("Test Leet Code 932");
    LeetCode leetCode;
    int N = 4;
    vector<int> result = leetCode.beautifulArray(N);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(result);

    N = 5;
    result = leetCode.beautifulArray(N);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(result);
}



void TestLeetCode931(void)
{
    Logger::WriteMessage("Test Leet Code 931");
    LeetCode leetCode;
    vector<vector<int>> A = { {1, 2, 3},{4, 5, 6},{7, 8, 9}	};
    int result = leetCode.minFallingPathSum(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

}

void TestLeetCode9904(void)
{
    Logger::WriteMessage("Test Leet Code 9904");
    LeetCode leetCode;
    vector<string> lines = 
    { 
        "John,Smith,john.smith@gmail.com,Los Angeles,1",
        "Jane, Roberts, janer@msn.com, \"San Francisco, CA\", 0",
        "Huanmin, Wu,,,",
        "\"Alexandra \"\"Alex\"\"\", Menendez, alex.menendez@gmail.com, Miami, 1",
        "\"\"\"Alexandra Alex\"\"\""
    };
    vector<vector<string>> result = leetCode.parseCSV(lines);
    for (string line : lines)Logger::WriteMessage(line);
    Logger::WriteMessage(result);
}


void TestLeetCode936(void)
{
    Logger::WriteMessage("Test Leet Code 936");
    LeetCode leetCode;
    string stamp = "abc";
    string target = "ababc";
    
    vector<int> result = leetCode.movesToStamp(stamp, target);
    Logger::WriteMessage("stamp = " + stamp + "; target = " + target);
    Logger::WriteMessage(result);

    stamp = "abca";
    target = "aabcaca";
    result = leetCode.movesToStamp(stamp, target);
    Logger::WriteMessage("stamp = " + stamp + "; target = " + target);
    Logger::WriteMessage(result);
}

void TestLeetCode935(void)
{
    Logger::WriteMessage("Test Leet Code 935");
    LeetCode leetCode;
    int N = 1;
    int result = leetCode.knightDialer(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 2;
    result = leetCode.knightDialer(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 3;
    result = leetCode.knightDialer(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode937(void)
{
    Logger::WriteMessage("Test Leet Code 937");
    LeetCode leetCode;
    vector<string> logs =
    {
        "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"
    };
    vector<string> result = leetCode.reorderLogFiles(logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage(result);
}

void TestLeetCode938(void)
{
    Logger::WriteMessage("Test Leet Code 938");
    LeetCode leetCode;
    string input = "[10,5,15,3,7,null,18]";
    TreeNode * root = leetCode.deserialize(input);
    int L = 7;
    int R = 15;
    int result = leetCode.rangeSumBST(root, L, R);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[10,5,15,3,7,13,18,1,null,6]";
    root = leetCode.deserialize(input);
    L = 6;
    R = 10;
    result = leetCode.rangeSumBST(root, L, R);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode939(void)
{
    Logger::WriteMessage("Test Leet Code 939");
    LeetCode leetCode;
    vector<vector<int>> points = { {1, 1},{1, 3},{3, 1},{3, 3},{2, 2} };
    int result = leetCode.minAreaRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { { 1, 1 },{ 1, 3 },{ 3, 1 },{ 3, 3 },{4,1},{4,3} };
    result = leetCode.minAreaRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode940(void)
{
    Logger::WriteMessage("Test Leet Code 940");
    LeetCode leetCode;
    string S = "lee";
    int result = leetCode.distinctSubseqII(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "aaa";
    result = leetCode.distinctSubseqII(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "aba";
    result = leetCode.distinctSubseqII(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "abc";
    result = leetCode.distinctSubseqII(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode941(void)
{
    Logger::WriteMessage("Test Leet Code 941");
    LeetCode leetCode;
    vector<int> A = { 2, 1 };
    bool result = leetCode.validMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    A = { 3,5,5 };
    result = leetCode.validMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 0,3,2,1 };
    result = leetCode.validMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode944(void)
{
    Logger::WriteMessage("Test Leet Code 944");
    LeetCode leetCode;
    vector<string> A = { "cba","daf","ghi" };
    int result = leetCode.minDeletionSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "a","b" };
    result = leetCode.minDeletionSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "zyx","wvu","tsr" };
    result = leetCode.minDeletionSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode942(void)
{
    Logger::WriteMessage("Test Leet Code 942");
    LeetCode leetCode;
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


void TestLeetCode945(void)
{
    Logger::WriteMessage("Test Leet Code 945");
    LeetCode leetCode;
    vector<int> A = { 1,2,2 };
    int result = leetCode.minIncrementForUnique(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,2,1,2,1,7 };
    result = leetCode.minIncrementForUnique(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode948(void)
{
    Logger::WriteMessage("Test Leet Code 948");
    LeetCode leetCode;
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


void TestLeetCode950(void)
{
    Logger::WriteMessage("Test Leet Code 950");
    LeetCode leetCode;
    vector<int> deck = { 17,13,11,2,3,5,7 };
    vector<int> result = leetCode.deckRevealedIncreasing(deck);
    Logger::WriteMessage(deck);
    Logger::WriteMessage(result);
}

void TestLeetCode951(void)
{
    Logger::WriteMessage("Test Leet Code 951");
    LeetCode leetCode;
    string tree1 = "[1, 2, 3, 4, 5, 6, null, null, null, 7, 8]";
    string tree2 = "[1,3,2,null,6,4,5,null,null,null,null,8,7]"; 
    TreeNode * root1 = leetCode.deserialize(tree1);
    TreeNode * root2 = leetCode.deserialize(tree2);
    bool result = leetCode.flipEquiv(root1, root2);
    Logger::WriteMessage(tree1);
    Logger::WriteMessage(tree2);
    Logger::WriteMessage("result = " + (string) (result? "true" : "false"));
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);
}

void TestLeetCode953(void)
{
    Logger::WriteMessage("Test Leet Code 953");
    LeetCode leetCode;
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

void TestLeetCode954(void)
{
    Logger::WriteMessage("Test Leet Code 954");
    LeetCode leetCode;
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
    LeetCode leetCode;
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

void TestLeetCode956(void)
{
    Logger::WriteMessage("Test Leet Code 956");
    LeetCode leetCode;
    vector<int> rods = { 1,2,3,6 };
    int result = leetCode.tallestBillboard(rods);
    Logger::WriteMessage(rods);
    Logger::WriteMessage("result = " + to_string(result));

    rods = { 1,2,3,4,5,6 };
    result = leetCode.tallestBillboard(rods);
    Logger::WriteMessage(rods);
    Logger::WriteMessage("result = " + to_string(result));

    rods = { 1,2 };
    result = leetCode.tallestBillboard(rods);
    Logger::WriteMessage(rods);
    Logger::WriteMessage("result = " + to_string(result));

    rods = { 1,4,3, 2 };
    result = leetCode.tallestBillboard(rods);
    Logger::WriteMessage(rods);
    Logger::WriteMessage("result = " + to_string(result));

    rods = { 61,45,43,54,40,53,55,47,51,59,42 };
    result = leetCode.tallestBillboard(rods);
    Logger::WriteMessage(rods);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode957(void)
{
    Logger::WriteMessage("Test Leet Code 957");
    LeetCode leetCode;
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

void TestLeetCode958(void)
{
    Logger::WriteMessage("Test Leet Code 958");
    LeetCode leetCode;
    string input = "[1,2,3,4,5,6]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    bool result = leetCode.isCompleteTree(root);
    Logger::WriteMessage("Result = " + (string) (result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,4,5,null,7]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    result = leetCode.isCompleteTree(root);
    Logger::WriteMessage("Result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}



void TestLeetCode960(void)
{
    Logger::WriteMessage("Test Leet Code 960");
    LeetCode leetCode;
    vector<string> A = { "babca","bbazb" };
    int result = leetCode.minDeletionSizeIII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "edcba" };
    result = leetCode.minDeletionSizeIII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "ghi","def","abc" };
    result = leetCode.minDeletionSizeIII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode961(void)
{
    Logger::WriteMessage("Test Leet Code 961");
    LeetCode leetCode;
    vector<int> A = { 1,2,3,3 };
    int result = leetCode.repeatedNTimes(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2,1,2,5,3,2 };
    result = leetCode.repeatedNTimes(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 5,1,5,2,5,3,5,4 };
    result = leetCode.repeatedNTimes(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2, 0, 2, 2, 1, 2, 9, 7 };
    result = leetCode.repeatedNTimes(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode964(void)
{
    Logger::WriteMessage("Test Leet Code 964");
    LeetCode leetCode;
    int x = 3;
    int target = 19;
    int result = leetCode.leastOpsExpressTarget(x, target);
    Logger::WriteMessage("x = " + to_string(x) + "; target = " + to_string(target) + "; result = " + to_string(result));

    x = 5;
    target = 501;
    result = leetCode.leastOpsExpressTarget(x, target);
    Logger::WriteMessage("x = " + to_string(x) + "; target = " + to_string(target) + "; result = " + to_string(result));

    x = 100;
    target = 100000000;
    result = leetCode.leastOpsExpressTarget(x, target);
    Logger::WriteMessage("x = " + to_string(x) + "; target = " + to_string(target) + "; result = " + to_string(result));

    x = 2;
    target = 125046;
    result = leetCode.leastOpsExpressTarget(x, target);
    Logger::WriteMessage("x = " + to_string(x) + "; target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode962(void)
{
    Logger::WriteMessage("Test Leet Code 962");
    LeetCode leetCode;
    vector<int> A = { 6,0,8,2,1,5 };
    int result = leetCode.maxWidthRamp(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 9,8,1,0,1,9,4,0,4,1 };
    result = leetCode.maxWidthRamp(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode968(void)
{
    Logger::WriteMessage("Test Leet Code 968");
    LeetCode leetCode;
    string input = "[0,0,null,0,0]";
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.minCameraCover(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));

    input = "[0,0,null,0,null,0,null,null,0]";
    root = leetCode.deserialize(input);
    result = leetCode.minCameraCover(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
}

void TestLeetCode965(void)
{
    Logger::WriteMessage("Test Leet Code 965");
    LeetCode leetCode;
    string input = "[1,1,1,1,1,null,1]";
    TreeNode * root = leetCode.deserialize(input);
    bool result = leetCode.isUnivalTree(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));

    input = "[2,2,2,5,2]";
    root = leetCode.deserialize(input);
    result = leetCode.isUnivalTree(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode970(void)
{
    Logger::WriteMessage("Test Leet Code 970");
    LeetCode leetCode;
    int x = 2;
    int y = 3;
    int bound = 10;
    vector<int> result = leetCode.powerfulIntegers(x, y, bound);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; bound = " + to_string(bound));
    Logger::WriteMessage(result);

    x = 3;
    y = 5;
    bound = 15;
    result = leetCode.powerfulIntegers(x, y, bound);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; bound = " + to_string(bound));
    Logger::WriteMessage(result);
}

void TestLeetCode969(void)
{
    Logger::WriteMessage("Test Leet Code 969");
    LeetCode leetCode;
    vector<int> A = { 3,2,4,1 };
    Logger::WriteMessage(A);
    vector<int> result = leetCode.pancakeSort(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode971(void)
{
    Logger::WriteMessage("Test Leet Code 971");
    LeetCode leetCode;
    string input = "[1, 2]";
    TreeNode * root = leetCode.deserialize(input);
    vector<int> voyage = { 2, 1 };
    vector<int> result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3]";
    root = leetCode.deserialize(input);
    voyage = { 1,3,2 };
    result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3]";
    root = leetCode.deserialize(input);
    voyage = { 1,2,3 };
    result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3, null, null, null, 4, 6, 5]";
    root = leetCode.deserialize(input);
    voyage = { 1, 2, 3, 4, 5, 6 };
    result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,3,2, null, null, null, 4, 6, 7]";
    root = leetCode.deserialize(input);
    voyage = { 1, 2, 3, 4, 5, 6 };
    result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode975(void)
{
    Logger::WriteMessage("Test Leet Code 975");
    LeetCode leetCode;
    vector<int> A = { 1, 2, 3, 2, 1, 4, 4, 5 };
    int result = leetCode.oddEvenJumps(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 10,13,12,14,15 };
    result = leetCode.oddEvenJumps(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 5, 1, 3, 4, 2 };
    result = leetCode.oddEvenJumps(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 84 };
    result = leetCode.oddEvenJumps(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode977(void)
{
    Logger::WriteMessage("Test Leet Code 977");
    LeetCode leetCode;
    vector<int> A = { -4,-1,0,3,10 };
    vector<int> result = leetCode.sortedSquares(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { -7,-3,2,3,11 };
    result = leetCode.sortedSquares(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

}

void TestLeetCode979(void)
{
    Logger::WriteMessage("Test Leet Code 979");
    LeetCode leetCode;
    string input = "[3,0,0]";
    TreeNode *root = leetCode.deserialize(input);
    int result = leetCode.distributeCoins(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[0,3,0]";
    root = leetCode.deserialize(input);
    result = leetCode.distributeCoins(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,0,2]";
    root = leetCode.deserialize(input);
    result = leetCode.distributeCoins(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,0,0,null,3]";
    root = leetCode.deserialize(input);
    result = leetCode.distributeCoins(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode978(void)
{
    Logger::WriteMessage("Test Leet Code 978");
    LeetCode leetCode;
    vector<int> A = { 9,4,2,10,7,8,8,1,9 };
    int result = leetCode.maxTurbulenceSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
 
    A = { 4,8,12,16 };
    result = leetCode.maxTurbulenceSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 100 };
    result = leetCode.maxTurbulenceSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode980(void)
{
    Logger::WriteMessage("Test Leet Code 980");
    LeetCode leetCode;
    vector<vector<int>> grid = { {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
    int result = leetCode.uniquePathsIII(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 2} };
    result = leetCode.uniquePathsIII(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 1},{2, 0} };
    result = leetCode.uniquePathsIII(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode984(void)
{
    Logger::WriteMessage("Test Leet Code 984");
    LeetCode leetCode;
    int A = 1;
    int B = 2;
    string result = leetCode.strWithout3a3b(A, B);
    Logger::WriteMessage("A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + result);

    A = 4;
    B = 1;
    result = leetCode.strWithout3a3b(A, B);
    Logger::WriteMessage("A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + result);
}

void TestLeetCode982(void)
{
    Logger::WriteMessage("Test Leet Code 982");
    LeetCode leetCode;
    vector<int> A = { 2, 1, 3 };
    int result = leetCode.countTriplets(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage( "result = " + to_string(result));
}

void TestLeetCode983(void)
{
    Logger::WriteMessage("Test Leet Code 983");
    LeetCode leetCode;
    vector<int> days = { 1,4,6,7,8,20 };
    vector<int> costs = { 2,7,15 };
    int result = leetCode.mincostTickets(days, costs);
    Logger::WriteMessage(days);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("result = " + to_string(result));

    days = { 1,2,3,4,5,6,7,8,9,10,30,31 };
    costs = { 2,7,15 };
    result = leetCode.mincostTickets(days, costs);
    Logger::WriteMessage(days);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode985(void)
{
    Logger::WriteMessage("Test Leet Code 985");
    LeetCode leetCode;
    vector<int> A = { 1,2,3,4 };
    vector<vector<int>> queries = { {1, 0},{-3, 1},{-4, 0},{2, 3} };
    vector<int> result = leetCode.sumEvenAfterQueries(A, queries);
    Logger::WriteMessage(A);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode986(void)
{
    Logger::WriteMessage("Test Leet Code 986");
    LeetCode leetCode;
    vector<Interval> A = { {0, 2},{5, 10},{13, 23},{24, 25} };
    vector<Interval> B = { {1, 5},{8, 12},{15, 24},{25, 26} };
    vector<Interval> result = leetCode.intervalIntersection(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(result);
}

void TestLeetCode987(void)
{
    Logger::WriteMessage("Test Leet Code 987");
    LeetCode leetCode;
    string input = "[3, 9, 20, null, null, 15, 7]";
    TreeNode * root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[1,2,3,4,5,6,7]";
    root = leetCode.deserialize(input);
    result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[0, 8, 1, null, null, 3, 2, null, 4, 5, null, null, 7, 6]";
    root = leetCode.deserialize(input);
    result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[0, 2, 1, 3, null, null, null, 4, 5, null, 7, 6, null, 10, 8, 11, 9]";
    root = leetCode.deserialize(input);
    result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[0, 2, 1, 3, null, 5, 22, 9, 4, 12, 25, null, null, 13, 14, 8, 6, null, null, null, null, null, 27, 24, 26, null, 17, 7, null, 28, null, null, null, null, null, 19, null, 11, 10, null, null, null, 23, 16, 15, 20, 18, null, null, null, null, null, 21, null, null, 29]";
    root = leetCode.deserialize(input);
    result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);
}

void TestLeetCode988(void)
{
    Logger::WriteMessage("Test Leet Code 988");
    LeetCode leetCode;
    string input = "[0,1,2,3,4,3,4]";
    TreeNode * root = leetCode.deserialize(input);
    string result = leetCode.smallestFromLeaf(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[25,1,3,1,3,0,2]";
    root = leetCode.deserialize(input);
    result = leetCode.smallestFromLeaf(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[2,2,1,null,1,0,null,0]";
    root = leetCode.deserialize(input);
    result = leetCode.smallestFromLeaf(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);
    
    input = "[0, null, 1]";
    root = leetCode.deserialize(input);
    result = leetCode.smallestFromLeaf(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);
}

void TestLeetCode510(void)
{
    Logger::WriteMessage("Test Leet Code 510");
    LeetCode leetCode;
    string input = "[2,1,3]";
    int n = 1;
    TreeNode * root = leetCode.deserialize(input);
    TreeNode * result = leetCode.inorderSuccessor(leetCode.findTreeNode(root, n));
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result->val));
    leetCode.freeTreeNodes(root);

    input = "[5,3,6,2,4,null,null,1]";
    n = 6;
    root = leetCode.deserialize(input);
    result = leetCode.inorderSuccessor(leetCode.findTreeNode(root, n));
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + (string)((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9,null]";
    n = 15;
    root = leetCode.deserialize(input);
    result = leetCode.inorderSuccessor(leetCode.findTreeNode(root, n));
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result->val));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode989(void)
{
    Logger::WriteMessage("Test Leet Code 989");
    LeetCode leetCode;
    vector<int> A = { 1,2,0,0 };
    int K = 34;
    vector<int> result = leetCode.addToArrayForm(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(result);

    A = { 2,7,4 };
    K = 181;
    result = leetCode.addToArrayForm(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(result);

    A = { 2,1,5 };
    K = 806;
    result = leetCode.addToArrayForm(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(result);

    A = { 9,9,9,9,9,9,9,9,9,9 };
    K = 1;
    result = leetCode.addToArrayForm(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(result);
}


void TestLeetCode992(void)
{
    Logger::WriteMessage("Test Leet Code 992");
    LeetCode leetCode;
    vector<int> A = { 1,2,1,2,3 };
    int K = 2;
    int result = leetCode.subarraysWithKDistinct(A, K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 1,2,1,3,4 };
    K = 3;
    result = leetCode.subarraysWithKDistinct(A, K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A =
    {
        48, 18, 15, 17, 35, 33, 3, 22, 14, 52, 18, 32, 45, 33, 39,
        7, 52, 2, 4, 22, 13, 41, 4, 29, 3, 7, 34, 31, 4, 49, 3, 8,
        20, 42, 12, 11, 35, 42, 3, 21, 27, 29, 37, 21, 40, 50, 22,
        7, 2, 32, 1, 1, 22, 33, 19, 52, 38, 34, 36, 48, 40, 28, 47,
        8, 7, 46, 17, 7, 2, 21, 49, 6, 7, 50, 15, 31, 50, 52, 1, 27,
        3, 15, 5, 6, 23, 26, 34, 50, 15, 22, 26, 39, 28, 25, 25, 21, 37, 28, 45
    };
    K = 30;
    result = leetCode.subarraysWithKDistinct(A, K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode996(void)
{
    Logger::WriteMessage("Test Leet Code 996");
    LeetCode leetCode;
    vector<int> A = { 1,17,8 };
    int result = leetCode.numSquarefulPerms(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2,2,2 };
    result = leetCode.numSquarefulPerms(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2,2,2,2,7,7,7 };
    result = leetCode.numSquarefulPerms(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode993(void)
{
    Logger::WriteMessage("Test Leet Code 993");
    LeetCode leetCode;
    string input = "[1,2,3,4]"; 
    int x = 4;
    int y = 3;
    TreeNode * root = leetCode.deserialize(input);
    bool result = leetCode.isCousins(root, x, y);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + (string) (result? "true" : "false"));

    input = "[1,2,3,null,4,null,5]";
    x = 5;
    y = 4;
    root = leetCode.deserialize(input);
    result = leetCode.isCousins(root, x, y);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + (string)(result ? "true" : "false"));

    input = "[1, 2, 3, null, 4]";
    x = 2;
    y = 3;
    root = leetCode.deserialize(input);
    result = leetCode.isCousins(root, x, y);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode995(void)
{
    Logger::WriteMessage("Test Leet Code 995");
    LeetCode leetCode;
    vector<int> A = { 0,1,0 };
    int K = 1;
    int result = leetCode.minKBitFlips(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 1,1,0 };
    K = 2;
    result = leetCode.minKBitFlips(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 0, 0, 0, 1, 0, 1, 1, 0 };
    K = 3;
    result = leetCode.minKBitFlips(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}


void TestLeetCode999(void)
{
    Logger::WriteMessage("Test Leet Code 999");
    LeetCode leetCode;
    vector<vector<char>> board = 
    {
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','.','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    int result = leetCode.numRookCaptures(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board =
    {
        {'.','.','.','.','.','.','.','.'},
        {'.','p','p','p','p','p','.','.'},
        {'.','p','p','B','p','p','.','.'},
        {'.','p','B','R','B','p','.','.'},
        {'.','p','p','B','p','p','.','.'},
        {'.','p','p','p','p','p','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    result = leetCode.numRookCaptures(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board =
    {
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'p','p','.','R','.','p','B','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','B','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    result = leetCode.numRookCaptures(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1001(void)
{
    Logger::WriteMessage("Test Leet Code 1001");
    LeetCode leetCode;
    int N = 5;
    vector<vector<int>> lamps = { {0,0},{4,4} };
    vector<vector<int>> queries = { {1, 1},{1, 0} };
    vector<int> result = leetCode.gridIllumination(N, lamps, queries);
    Logger::WriteMessage(lamps);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    N = 5;
    lamps = { {0, 0},{1, 0} };
    queries = { {1, 1},{1, 1} };
    result = leetCode.gridIllumination(N, lamps, queries);
    Logger::WriteMessage(lamps);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode997(void)
{
    Logger::WriteMessage("Test Leet Code 997");
    LeetCode leetCode;
    int N = 2;
    vector<vector<int>> trust = { {1, 2} };
    int result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 3;
    trust = { {1, 3},{2, 3} };
    result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 3;
    trust = { {1, 3},{2, 3},{3, 1} };
    result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 3;
    trust = { {1, 2},{2, 3} };
    result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 4;
    trust = { {1, 3}, { 1, 4 }, { 2, 3 }, { 2, 4 }, { 4, 3 } };
    result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode998(void)
{
    Logger::WriteMessage("Test Leet Code 998");
    LeetCode leetCode;
    string input = "[4, 1, 3, null, null, 2]";
    TreeNode * root = leetCode.deserialize(input);
    int val = 5;
    root = leetCode.insertIntoMaxTree(root, val);
    string output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("output = " + output);
 
    input = "[5,2,4,null,1]";
    root = leetCode.deserialize(input);
    val = 3;
    root = leetCode.insertIntoMaxTree(root, val);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("output = " + output);

    input = "[5,2,3,null,1]";
    root = leetCode.deserialize(input);
    val = 4;
    root = leetCode.insertIntoMaxTree(root, val);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("output = " + output);
}

void TestLeetCode1000(void)
{
    Logger::WriteMessage("Test Leet Code 1000");
    LeetCode leetCode;
    vector<int> stones = { 3, 2, 4, 1 };
    int K = 2;
    int result = leetCode.mergeStones(stones, K);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    stones = { 3,2,4,1 };
    K = 3;
    result = leetCode.mergeStones(stones, K);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    stones = { 3, 5, 1, 2, 6 };
    K = 3;
    result = leetCode.mergeStones(stones, K);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
    
}

void TestLeetCode1002(void)
{
    Logger::WriteMessage("Test Leet Code 1002");
    LeetCode leetCode;
    vector<string> A = { "bella", "label", "roller" };
    vector<string> result = leetCode.commonChars(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { "cool", "lock", "cook" };
    result = leetCode.commonChars(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode1004(void)
{
    Logger::WriteMessage("Test Leet Code 1004");
    LeetCode leetCode;
    vector<int> A = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int K = 2;
    int result = leetCode.longestOnes(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    K = 3;
    result = leetCode.longestOnes(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode1005(void)
{
    Logger::WriteMessage("Test Leet Code 1005");
    LeetCode leetCode;
    vector<int> A = { 4,2,3 };
    int K = 1;
    int result = leetCode.largestSumAfterKNegations(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 3,-1,0,2 };
    K = 3;
    result = leetCode.largestSumAfterKNegations(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 2,-3,-1,5,-4 };
    K = 2;
    result = leetCode.largestSumAfterKNegations(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode1007(void)
{
    Logger::WriteMessage("Test Leet Code 1007");
    LeetCode leetCode;
    vector<int> A = { 2,1,2,4,2,2 };
    vector<int> B = { 5,2,6,2,3,2 };
    int result = leetCode.minDominoRotations(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,5,1,2,3 };
    B = { 3,6,3,3,4 };
    result = leetCode.minDominoRotations(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1, 2, 1, 1, 1, 2, 2, 2 };
    B = { 2, 1, 2, 2, 2, 2, 2, 2 };
    result = leetCode.minDominoRotations(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1008(void)
{
    Logger::WriteMessage("Test Leet Code 1008");
    LeetCode leetCode;
    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode * root = leetCode.bstFromPreorder(preorder);
    string result = leetCode.serialize(root);
    Logger::WriteMessage(preorder);
    Logger::WriteMessage("result = " + result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1006(void)
{
    Logger::WriteMessage("Test Leet Code 1006");
    LeetCode leetCode;
    int N = 4;
    int result = leetCode.clumsy(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 10;
    result = leetCode.clumsy(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode1012(void)
{
    Logger::WriteMessage("Test Leet Code 1012");
    LeetCode leetCode;
    int N = 210;
    int result = leetCode.numDupDigitsAtMostN(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 10;
    result = leetCode.numDupDigitsAtMostN(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 100;
    result = leetCode.numDupDigitsAtMostN(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode1009(void)
{
    Logger::WriteMessage("Test Leet Code 1009");
    LeetCode leetCode;
    int N = 5;
    int result = leetCode.bitwiseComplement(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 7;
    result = leetCode.bitwiseComplement(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 10;
    result = leetCode.bitwiseComplement(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 0;
    result = leetCode.bitwiseComplement(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode1010(void)
{
    Logger::WriteMessage("Test Leet Code 1010");
    LeetCode leetCode;
    vector<int> time = { 30,20,150,100,40 };
    int result = leetCode.numPairsDivisibleBy60(time);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));

    time = { 60,60,60 };
    result = leetCode.numPairsDivisibleBy60(time);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1016(void)
{
    Logger::WriteMessage("Test Leet Code 1016");
    LeetCode leetCode;
    string S = "0110";
    int N = 3;
    bool result = leetCode.queryString(S, N);
    Logger::WriteMessage("S = " + S + "; N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    S = "0110";
    N = 4;
    result = leetCode.queryString(S, N);
    Logger::WriteMessage("S = " + S + "; N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    S = "110101011011000011011111000000";
    N = 15;
    result = leetCode.queryString(S, N);
    Logger::WriteMessage("S = " + S + "; N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1013(void)
{
    Logger::WriteMessage("Test Leet Code 1013");
    LeetCode leetCode;
    vector<int> A = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    int result = leetCode.canThreePartsEqualSum(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 0,2,1,-6,6,7,9,-1,2,0,1 };
    result = leetCode.canThreePartsEqualSum(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { 3,3,6,5,-2,2,5,1,-9,4 };
    result = leetCode.canThreePartsEqualSum(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" :"false"));

    A = { -1,1,2,-2,3,-3 };
    result = leetCode.canThreePartsEqualSum(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    A = { -1,1,2,-2};
    result = leetCode.canThreePartsEqualSum(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1014(void)
{
    Logger::WriteMessage("Test Leet Code 1014");
    LeetCode leetCode;
    vector<int> A = { 8,1,5,2,6 };
    int result = leetCode.maxScoreSightseeingPair(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 7, 2, 6, 6, 9, 4, 3 };
    result = leetCode.maxScoreSightseeingPair(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1017(void)
{
    Logger::WriteMessage("Test Leet Code 1017");
    LeetCode leetCode;
    int N = 2;
    string result = leetCode.baseNeg2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + result);

    N = 3;
    result = leetCode.baseNeg2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + result);

    N = 4;
    result = leetCode.baseNeg2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + result);

    N = -10;
    result = leetCode.baseNeg2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + result);
}


void TestLeetCode1018(void)
{
    Logger::WriteMessage("Test Leet Code 1018");
    LeetCode leetCode;
    vector<int> A = { 0,1,1 };
    vector<bool> result;
    result = leetCode.prefixesDivBy5(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 1, 1, 1 };
    result = leetCode.prefixesDivBy5(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 0,1,1,1,1,1 };
    result = leetCode.prefixesDivBy5(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { 1,1,1,0,1 };
    result = leetCode.prefixesDivBy5(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode1021(void)
{
    Logger::WriteMessage("Test Leet Code 1021");
    LeetCode leetCode;
    string S = "(()())(())";
    string result = leetCode.removeOuterParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
    
    S = "(()())(())(()(()))";
    result = leetCode.removeOuterParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "()()";
    result = leetCode.removeOuterParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode1022(void)
{
    Logger::WriteMessage("Test Leet Code 1022");
    LeetCode leetCode;
    string input = "[1,0,1,0,1,0,1]";
    Logger::WriteMessage(input);
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.sumRootToLeaf(root);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1023(void)
{
    Logger::WriteMessage("Test Leet Code 1023");
    LeetCode leetCode;
    vector<string> queries = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
    string pattern = "FB";
    vector<bool> result = leetCode.camelMatch(queries, pattern);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("pattern = " + pattern);
    Logger::WriteMessage(result);

    queries = { "FooBar","FooBarTest","FootBall","FrameBuffer", "ForceFeedBack" };
    pattern = "FoBa";
    result = leetCode.camelMatch(queries, pattern);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("pattern = " + pattern);
    Logger::WriteMessage(result);

    queries = { "FooBar","FooBarTest","FootBall","FrameBuffer", "ForceFeedBack" };
    pattern = "FoBaT";
    result = leetCode.camelMatch(queries, pattern);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("pattern = " + pattern);
    Logger::WriteMessage(result);
}

void TestLeetCode1024(void)
{
    Logger::WriteMessage("Test Leet Code 1024");
    LeetCode leetCode;
    vector<vector<int>> clips = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
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

void TestLeetCode1025(void)
{
    Logger::WriteMessage("Test Leet Code 1025");
    LeetCode leetCode;
    int N = 2;
    bool result = leetCode.divisorGame(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 3;
    result = leetCode.divisorGame(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1026(void)
{
    Logger::WriteMessage("Test Leet Code 1026");
    LeetCode leetCode;
    string input = "[8,3,10,1,6,null,14,null,null,4,7,13]";
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.maxAncestorDiff(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1028(void)
{
    Logger::WriteMessage("Test Leet Code 1028");
    LeetCode leetCode;
    string S = "1-2--3--4-5--6--7";
    TreeNode * root = leetCode.recoverFromPreorder(S);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("S = " + S + "; result = " + output);
    leetCode.freeTreeNodes(root);

    S = "1-2--3---4-5--6---7";
    root = leetCode.recoverFromPreorder(S);
    output = leetCode.serialize(root);
    Logger::WriteMessage("S = " + S + "; result = " + output);
    leetCode.freeTreeNodes(root);

    S = "1-401--349---90--88";
    root = leetCode.recoverFromPreorder(S);
    output = leetCode.serialize(root);
    Logger::WriteMessage("S = " + S + "; result = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1027(void)
{
    Logger::WriteMessage("Test Leet Code 1027");
    LeetCode leetCode;
    vector<int> A = { 3, 6, 9, 12 };
    int result = leetCode.longestArithSeqLength(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 9,4,7,2,10 };
    result = leetCode.longestArithSeqLength(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 20,1,15,3,10,5,8 };
    result = leetCode.longestArithSeqLength(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode912(void)
{
    Logger::WriteMessage("Test Leet Code 912");
    LeetCode leetCode;
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
    LeetCode leetCode;
    vector<vector<int>> costs = { {10, 20},{30, 200},{400, 50},{30, 20} };
    int result = leetCode.twoCitySchedCost(costs);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("result = " + to_string(result));

    costs = { {259, 770},{448, 54},{926, 667},{184, 139},{840, 118},{577, 469} };
    result = leetCode.twoCitySchedCost(costs);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1031(void)
{
    Logger::WriteMessage("Test Leet Code 1031");
    LeetCode leetCode;
    vector<int> A = { 0, 6, 5, 2, 2, 5, 1, 9, 4 };
    int L = 1, M = 2;
    int result = leetCode.maxSumTwoNoOverlap(A, L, M);
    Logger::WriteMessage(A);
    Logger::WriteMessage("L = " + to_string(L) + "; M = " + to_string(M) + "; result = " + to_string(result));

    A = { 3,8,1,3,2,1,8,9,0 };
    L = 3, M = 2;
    result = leetCode.maxSumTwoNoOverlap(A, L, M);
    Logger::WriteMessage(A);
    Logger::WriteMessage("L = " + to_string(L) + "; M = " + to_string(M) + "; result = " + to_string(result));

    A = { 2,1,5,6,0,9,5,0,3,8 };
    L = 4, M = 3;
    result = leetCode.maxSumTwoNoOverlap(A, L, M);
    Logger::WriteMessage(A);
    Logger::WriteMessage("L = " + to_string(L) + "; M = " + to_string(M) + "; result = " + to_string(result));

    A = { 1,0,1 };
    L = 1, M = 1;
    result = leetCode.maxSumTwoNoOverlap(A, L, M);
    Logger::WriteMessage(A);
    Logger::WriteMessage("L = " + to_string(L) + "; M = " + to_string(M) + "; result = " + to_string(result));
}


void TestLeetCode1038(void)
{
    Logger::WriteMessage("Test Leet Code 1038");
    LeetCode leetCode;
    string input = "[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]";
    TreeNode * root = leetCode.deserialize(input);
    root = leetCode.bstToGst(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("input = " + input + "; output = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1039(void)
{
    Logger::WriteMessage("Test Leet Code 1039");
    LeetCode leetCode;
    vector<int> A = { 1,2,3 };
    int result = leetCode.minScoreTriangulation(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.minScoreTriangulationII(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,7,4,5 };
    result = leetCode.minScoreTriangulation(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.minScoreTriangulationII(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,3,1,4,1,5 };
    result = leetCode.minScoreTriangulation(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.minScoreTriangulationII(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1041(void)
{
    Logger::WriteMessage("Test Leet Code 1041");
    LeetCode leetCode;
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

void TestLeetCode1036(void)
{
    Logger::WriteMessage("Test Leet Code 1036");
    LeetCode leetCode;
    vector<vector<int>> blocked = { {0, 1},{1, 0} };
    vector<int> source = { 0, 0 };
    vector<int> target = { 0, 2 };
    Logger::WriteMessage(blocked);
    Logger::WriteMessage(source);
    Logger::WriteMessage(target);
    bool result = leetCode.isEscapePossible(blocked, source, target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    blocked = { };
    source = { 0, 0 };
    target = {999999, 999999};
    Logger::WriteMessage(blocked);
    Logger::WriteMessage(source);
    Logger::WriteMessage(target);
    result = leetCode.isEscapePossible(blocked, source, target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1043(void)
{
    Logger::WriteMessage("Test Leet Code 1043");
    LeetCode leetCode;
    vector<int> A = { 1, 15, 7, 9, 2, 5, 10 };
    int K = 3;
    int result = leetCode.maxSumAfterPartitioning(A, K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode1046(void)
{
    Logger::WriteMessage("Test Leet Code 1046");
    LeetCode leetCode;
    vector<int> stones = { 2,7,4,1,8,1 };
    int result = leetCode.lastStoneWeight(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1049(void)
{
    Logger::WriteMessage("Test Leet Code 1049");
    LeetCode leetCode;
    vector<int> stones = { 2, 1, 6, 4, 5 };
    int result = leetCode.lastStoneWeightII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.lastStoneWeightIIA(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { 1, 1, 1, 1, 1 };
    result = leetCode.lastStoneWeightII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.lastStoneWeightIIA(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { 1, 1, 4, 2, 2 };
    result = leetCode.lastStoneWeightII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.lastStoneWeightIIA(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { 2,7,4,1,8,1 };
    result = leetCode.lastStoneWeightII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.lastStoneWeightIIA(stones);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1048(void)
{
    Logger::WriteMessage("Test Leet Code 1048");
    LeetCode leetCode;
    vector<string> words = { "a","b","ba","bca","bda","bdca" };
    int result = leetCode.longestStrChain(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1051(void)
{
    Logger::WriteMessage("Test Leet Code 1051");
    LeetCode leetCode;
    vector<int> heights = { 1,1,4,2,1,3 };
    int result = leetCode.heightChecker(heights);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1054(void)
{
    Logger::WriteMessage("Test Leet Code 1054");
    LeetCode leetCode;
    vector<int> barcodes = { 1,1,1,1,2,2,3,3 };
    vector<int> result = leetCode.rearrangeBarcodes(barcodes);
    Logger::WriteMessage(barcodes);
    Logger::WriteMessage(result);
}

void TestLeetCode1052(void)
{
    Logger::WriteMessage("Test Leet Code 1052");
    LeetCode leetCode;
    vector<int> customers = { 1,0,1,2,1,1,7,5 };
    vector<int> grumpy = { 0,1,0,1,0,1,0,1 };
    int X = 3;
    int result = leetCode.maxSatisfied(customers, grumpy, X);
    Logger::WriteMessage(customers);
    Logger::WriteMessage(grumpy);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1053(void)
{
    Logger::WriteMessage("Test Leet Code 1053");
    LeetCode leetCode;
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

void TestLeetCode1074(void)
{
    Logger::WriteMessage("Test Leet Code 1074");
    LeetCode leetCode;
    vector<vector<int>> matrix = { {0, 1, 0},{1, 1, 1},{0, 1, 0} };
    int target = 0;
    int result = leetCode.numSubmatrixSumTarget(matrix, target);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("target = " + to_string(target) + "result = " + to_string(result));

    matrix = { {1, -1},{-1, 1} };
    target = 0;
    result = leetCode.numSubmatrixSumTarget(matrix, target);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}


void TestLeetCode1072(void)
{
    Logger::WriteMessage("Test Leet Code 1072");
    LeetCode leetCode;
    vector<vector<int>> matrix = { {0, 1},{1, 1} };
    int result = leetCode.maxEqualRowsAfterFlips(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("result = " + to_string(result));

    matrix = { {0, 1},{1, 0} };
    result = leetCode.maxEqualRowsAfterFlips(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("result = " + to_string(result));

    matrix = { {0, 0, 0},{0, 0, 1},{1, 1, 0} };
    result = leetCode.maxEqualRowsAfterFlips(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1073(void)
{
    Logger::WriteMessage("Test Leet Code 1073");
    LeetCode leetCode;
    vector<int> arr1 = { 1, 1, 1, 1, 1 };
    vector<int> arr2 = { 1, 0, 1 };
    vector<int> result = leetCode.addNegabinary(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage(result);
}

void TestLeetCode1056(void)
{
    Logger::WriteMessage("Test Leet Code 1056");
    LeetCode leetCode;
    int N = 6;
    bool result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string) (result? "true" : "false"));

    N = 89;
    result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 11;
    result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 25;
    result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 689;
    result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1064(void)
{
    Logger::WriteMessage("Test Leet Code 1064");
    LeetCode leetCode;
    vector<int> A = { -10, -5, 0, 3, 7 };
    int result = leetCode.fixedPoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,2,5,8,17 };
    result = leetCode.fixedPoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { -10,-5,3,4,7,9 };
    result = leetCode.fixedPoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,1,2,3,4,5 };
    result = leetCode.fixedPoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1079(void)
{
    Logger::WriteMessage("Test Leet Code 1079");
    LeetCode leetCode;
    string tiles = "AAB";
    int result = leetCode.numTilePossibilities(tiles);
    Logger::WriteMessage("tiles = " + tiles + "; result = " + to_string(result));

    tiles = "AAABBC";
    result = leetCode.numTilePossibilities(tiles);
    Logger::WriteMessage("tiles = " + tiles + "; result = " + to_string(result));
}

void TestLeetCode1080(void)
{
    Logger::WriteMessage("Test Leet Code 1080");
    LeetCode leetCode;
    string input = "[1, 2, 3, 4, -99, -99, 7, 8, 9, -99, -99, 12, 13, -99, 14]";
    int limit = 1;
    TreeNode * root = leetCode.deserialize(input);
    root = leetCode.sufficientSubset(root, limit);
    string output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("text = " + input + "; result = " + output);

    input = "[5,4,8,11,null,17,4,7,1,null,null,5,3]";
    limit = 22;
    root = leetCode.deserialize(input);
    root = leetCode.sufficientSubset(root, limit);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("text = " + input + "; result = " + output);

    input = "[10,5,10]";
    limit = 21;
    root = leetCode.deserialize(input);
    root = leetCode.sufficientSubset(root, limit);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("text = " + input + "; result = " + output);
}

void TestLeetCode1060(void)
{
    Logger::WriteMessage("Test Leet Code 1060");
    LeetCode leetCode;
    vector<int> nums = { 4, 7, 9, 10 };
    int k = 1;
    int result = leetCode.missingElement(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 4, 7, 9, 10 };
    k = 3;
    result = leetCode.missingElement(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,4 };
    k = 3;
    result = leetCode.missingElement(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}


void TestLeetCode1062(void)
{
    Logger::WriteMessage("Test Leet Code 1062");
    LeetCode leetCode;
    string S = "abcd";
    int result = leetCode.longestRepeatingSubstring(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "abbaba";
    result = leetCode.longestRepeatingSubstring(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "aabcaabdaab";
    result = leetCode.longestRepeatingSubstring(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "aaaaa";
    result = leetCode.longestRepeatingSubstring(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "abcda";
    result = leetCode.longestRepeatingSubstring(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode1063(void)
{
    Logger::WriteMessage("Test Leet Code 1063");
    LeetCode leetCode;
    vector<int> nums = { 1, 4, 2, 5, 3 };
    int result = leetCode.validSubarrays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,2,1 };
    result = leetCode.validSubarrays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,2 };
    result = leetCode.validSubarrays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1089(void)
{
    Logger::WriteMessage("Test Leet Code 1089");
    LeetCode leetCode;
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    Logger::WriteMessage(arr);
    leetCode.duplicateZeros(arr);
    Logger::WriteMessage(arr);
 
    arr = { 1,2,3 };
    Logger::WriteMessage(arr);
    leetCode.duplicateZeros(arr);
    Logger::WriteMessage(arr);
 
    arr = { 0, 0, 0, 0, 0, 0, 0 };
    Logger::WriteMessage(arr);
    leetCode.duplicateZeros(arr);
    Logger::WriteMessage(arr);

    arr = { 1, 2, 3, 4, 0 };
    Logger::WriteMessage(arr);
    leetCode.duplicateZeros(arr);
    Logger::WriteMessage(arr);
}

void TestLeetCode1090(void)
{
    Logger::WriteMessage("Test Leet Code 1090");
    LeetCode leetCode;
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

void TestLeetCode1092(void)
{
    Logger::WriteMessage("Test Leet Code 1092");
    LeetCode leetCode;
    string str1 = "abac";
    string str2 = "cab";
    string result = leetCode.shortestCommonSupersequence(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + result);

    str1 = "abbca";
    str2 = "cbc";
    result = leetCode.shortestCommonSupersequence(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + result);

    str1 = "";
    str2 = "cbc";
    result = leetCode.shortestCommonSupersequence(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + result);
}

void TestLeetCode1086(void)
{
    Logger::WriteMessage("Test Leet Code 1086");
    LeetCode leetCode;
    vector<vector<int>> items =
    { 
        {1, 91},{1, 92},{2, 93},{2, 97},{1, 60},{2, 77},{1, 65},{1, 87}, {1,100},{2,100},{2,76} 
    };
    vector<vector<int>> result = leetCode.highFive(items);
    Logger::WriteMessage(items);
    Logger::WriteMessage(result);
}

void TestLeetCode1087(void)
{
    Logger::WriteMessage("Test Leet Code 1087");
    LeetCode leetCode;
    string S = "{a,b}c{d,e}f";
    vector<string> result = leetCode.expand(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "abcd";
    result = leetCode.expand(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode1067(void)
{
    Logger::WriteMessage("Test Leet Code 1067");
    LeetCode leetCode;
    int d = 0;
    int low = 1;
    int high = 100;
    int result = leetCode.digitsCount(d, low, high);
    Logger::WriteMessage("d = " + to_string(d) + "; low = " + to_string(low) + 
        "; high = " + to_string(high) + "; result = " + to_string(result));

    d = 1;
    low = 1;
    high = 13;
    result = leetCode.digitsCount(d, low, high);
    Logger::WriteMessage("d = " + to_string(d) + "; low = " + to_string(low) +
        "; high = " + to_string(high) + "; result = " + to_string(result));

    d = 3;
    low = 100;
    high = 250;
    result = leetCode.digitsCount(d, low, high);
    Logger::WriteMessage("d = " + to_string(d) + "; low = " + to_string(low) +
        "; high = " + to_string(high) + "; result = " + to_string(result));
}

void TestLeetCode1094(void)
{
    Logger::WriteMessage("Test Leet Code 1094");
    LeetCode leetCode;
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

void TestLeetCode1095(void)
{
    Logger::WriteMessage("Test Leet Code 1095");
    vector<int> a = { 1,2,3,4,5,3,1 };
    int target = 3;
    MountainArray mountainArr;
    mountainArr = a;
    int result = mountainArr.findInMountainArray(target, mountainArr);
    Logger::WriteMessage(a);
    Logger::WriteMessage("result = " + (string)(to_string(result)));
    target = 1;
    result = mountainArr.findInMountainArray(target, mountainArr);
    Logger::WriteMessage(a);
    Logger::WriteMessage("result = " + (string)(to_string(result)));

    target = 5;
    result = mountainArr.findInMountainArray(target, mountainArr);
    Logger::WriteMessage(a);
    Logger::WriteMessage("result = " + (string)(to_string(result)));

    a = { 0,1,2,4,2,1 };
    target = 3;
    mountainArr = a;
    result = mountainArr.findInMountainArray(target, mountainArr);
    Logger::WriteMessage(a);
    Logger::WriteMessage("result = " + (string)(to_string(result)));

    a = { 1,5,2 };
    target = 1;
    mountainArr = a;
    result = mountainArr.findInMountainArray(target, mountainArr);
    Logger::WriteMessage(a);
    Logger::WriteMessage("result = " + (string)(to_string(result)));

    a = { 3, 5, 3, 2, 0 };
    target = 0;
    mountainArr = a;
    result = mountainArr.findInMountainArray(target, mountainArr);
    Logger::WriteMessage(a);
    Logger::WriteMessage("result = " + (string)(to_string(result)));
}

void TestLeetCode1104(void)
{
    Logger::WriteMessage("Test Leet Code 1104");
    LeetCode leetCode;
    int label = 14;
    vector<int> result = leetCode.pathInZigZagTree(label);
    Logger::WriteMessage("label = " + to_string(label));
    Logger::WriteMessage(result);

    label = 26;
    result = leetCode.pathInZigZagTree(label);
    Logger::WriteMessage("label = " + to_string(label));
    Logger::WriteMessage(result);
}

void TestLeetCode1099(void)
{
    Logger::WriteMessage("Test Leet Code 1099");
    LeetCode leetCode;
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

void TestLeetCode1100(void)
{
    Logger::WriteMessage("Test Leet Code 1100");
    LeetCode leetCode;
    string S = "havefunonleetcode";
    int K = 5;
    int result = leetCode.numKLenSubstrNoRepeats(S, K);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "home";
    K = 5;
    result = leetCode.numKLenSubstrNoRepeats(S, K);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode1105(void)
{
    Logger::WriteMessage("Test Leet Code 1105");
    LeetCode leetCode;
    vector<vector<int>> books =
    {
        {1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2} 
    };
    int shelf_width = 4;
    int result = leetCode.minHeightShelves(books, shelf_width);
    Logger::WriteMessage(books);
    Logger::WriteMessage("shelf_width = " + to_string(shelf_width) + "; result = " + to_string(result));
}

void TestLeetCode1109(void)
{
    Logger::WriteMessage("Test Leet Code 1109");
    LeetCode leetCode;
    vector<vector<int>> bookings = { {1, 2, 10},{2, 3, 20},{2, 5, 25} };
    int n = 5;
    vector<int> result = leetCode.corpFlightBookings(bookings, n);
    Logger::WriteMessage(bookings);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode1110(void)
{
    Logger::WriteMessage("Test Leet Code 1110");
    LeetCode leetCode;
    string input = "[1, 2, 3, 4, 5, 6, 7]";
    TreeNode * root = leetCode.deserialize(input);
    vector<int> to_delete = { 3, 5 };
    vector<TreeNode*> result = leetCode.delNodes(root, to_delete);
    vector<string> output;
    for (size_t i = 0; i < result.size(); i++)
    {
        output.push_back(leetCode.serialize(result[i]));
    }
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(to_delete);
    Logger::WriteMessage(output);

    input = "[1, 2, 3, null, null, null, 4]";
    root = leetCode.deserialize(input);
    to_delete = { 2, 1 };
    result = leetCode.delNodes(root, to_delete);
    output.clear();
    for (size_t i = 0; i < result.size(); i++)
    {
        output.push_back(leetCode.serialize(result[i]));
    }
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(to_delete);
    Logger::WriteMessage(output);
}

void TestLeetCode1122(void)
{
    Logger::WriteMessage("Test Leet Code 1122");
    LeetCode leetCode;
    vector<int> arr1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
    vector<int> arr2 = { 2, 1, 4, 3, 9, 6 };
    vector<int> result = leetCode.relativeSortArray(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage(result);
}

void TestLeetCode1120(void)
{
    Logger::WriteMessage("Test Leet Code 1120");
    LeetCode leetCode;
    string input = "[0, 6, 5, 3, 2, null, null, null, 4, null, null, null, 1]";
    TreeNode* root = leetCode.deserialize(input);
    double result = leetCode.maximumAverageSubtree(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + to_string(result));
    
}

void TestLeetCode1123(void)
{
    Logger::WriteMessage("Test Leet Code 1123");
    LeetCode leetCode;
    string input = "[0, 6, 5, 3, 2, null, null, null, 4, null, null, null, 1]";
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* result = leetCode.lcaDeepestLeaves(root);
    string output = leetCode.serialize(result);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + output);


    input = "[1, 2, 3]";
    root = leetCode.deserialize(input);
    result = leetCode.lcaDeepestLeaves(root);
    output = leetCode.serialize(result);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + output);

    input = "[1,2,3,4]";
    root = leetCode.deserialize(input);
    result = leetCode.lcaDeepestLeaves(root);
    output = leetCode.serialize(result);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + output);

    input = "[1,2,3,4,5]";
    root = leetCode.deserialize(input);
    result = leetCode.lcaDeepestLeaves(root);
    output = leetCode.serialize(result);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + output);
}

void TestLeetCode1125(void)
{
    Logger::WriteMessage("Test Leet Code 1125");
    LeetCode leetCode;
    vector<string> req_skills = { "java", "nodejs", "reactjs" };
    vector<vector<string>> people = { {"java"},{"nodejs"},{"nodejs", "reactjs"} };
    vector<int> result = leetCode.smallestSufficientTeam(req_skills, people);
    Logger::WriteMessage(req_skills);
    Logger::WriteMessage(people);
    Logger::WriteMessage(result);

    req_skills = { "algorithms","math","java","reactjs","csharp","aws" };
    people =
    {
        {"algorithms", "math", "java"},{"algorithms", "math", "reactjs"},
        {"java","csharp","aws"},{"reactjs","csharp"},
        {"csharp","math"},{"aws","java"}
    };
    result = leetCode.smallestSufficientTeam(req_skills, people);
    Logger::WriteMessage(req_skills);
    Logger::WriteMessage(people);
    Logger::WriteMessage(result);

    req_skills =
    {
        "zp", "jpphhnhwpw", "pscleb", "arn", "acrsxqvus", "fseqih", "fpqbjbbxglivyonn", "cjozlkyodt", "mvtwffgkhjrtibto", "kumdvfwsvrht", "i", "s", "ucr", "oo", "yqkqkhhhwngyjrg", "odiwidzqw"
    };
    people =
    {
        {"acrsxqvus"}, { "zp" }, {}, { "fpqbjbbxglivyonn" }, {}, {}, { "kumdvfwsvrht" }, {}, { "oo" }, {}, { "fseqih" }, {}, { "arn" }, {}, {}, { "yqkqkhhhwngyjrg" }, {}, {}, {}, { "kumdvfwsvrht" }, { "s" }, {}, {}, { "zp","ucr" }, {}, { "pscleb" }, {}, {}, {}, {}, {}, {}, {}, { "jpphhnhwpw" }, {}, {}, {}, { "oo" }, {}, { "i" }, { "pscleb" }, {}, {}, {}, {}, {}, {}, { "i" }, {}, { "mvtwffgkhjrtibto","odiwidzqw" }, {}, { "cjozlkyodt","odiwidzqw" }, { "arn" }, {}, {}, { "acrsxqvus" }, {}, {}, {}, { "ucr" }
    };
    result = leetCode.smallestSufficientTeam(req_skills, people);
    Logger::WriteMessage(req_skills);
    Logger::WriteMessage(people);
    Logger::WriteMessage(result);
}

void TestLeetCode1128(void)
{
    Logger::WriteMessage("Test Leet Code 1128");
    LeetCode leetCode;
    vector<vector<int>> dominoes = { {1, 2},{2, 1},{3, 4},{5, 6} };
    int result = leetCode.numEquivDominoPairs(dominoes);
    Logger::WriteMessage(dominoes);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1133(void)
{
    Logger::WriteMessage("Test Leet Code 1133");
    LeetCode leetCode;
    vector<int> A = { 5, 7, 3, 9, 4, 9, 8, 3, 1 };
    int result = leetCode.largestUniqueNumber(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 9,9,8,8 };
    result = leetCode.largestUniqueNumber(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1140(void)
{
    Logger::WriteMessage("Test Leet Code 1140");
    LeetCode leetCode;
    vector<int> piles = { 2, 7, 9, 4, 4 };
    int result = leetCode.stoneGameII(piles);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1145(void)
{
    Logger::WriteMessage("Test Leet Code 1145");
    LeetCode leetCode;
    string input = "[1,2,3,4,5,6,7,8,9,10,11]";
    TreeNode* root = leetCode.deserialize(input);
    int n = 11;
    int x = 3;
    bool result = leetCode.btreeGameWinningMove(root, n, x);
    Logger::WriteMessage("input =" + input + "; n = " + to_string(n) + "; x = " + to_string(x) + "; result = " + (string) (result ? "true": "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1150(void)
{
    Logger::WriteMessage("Test Leet Code 1150");
    LeetCode leetCode;
    vector<int> nums = { 2, 4, 5, 5, 5, 5, 5, 6, 6 };
    int target = 5;
    bool result = leetCode.isMajorityElement(nums, target);
    Logger::WriteMessage(nums);   
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + (string)(result? "true" : "false"));

    nums = { 10, 100, 101, 101 };
    target = 101;
    result = leetCode.isMajorityElement(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + (string)(result ? "true" : "false"));
}


void TestLeetCode1157(void)
{
    Logger::WriteMessage("Test Leet Code 1157");
    vector<string> command = { "MajorityChecker","query","query","query" };
    vector<vector<int>> params = { {1,1,2,2,1,1}, {0,5,4}, {0,3,3}, {2,3,2} };
    vector<string> result;
    class MajorityChecker* majorityChecker = nullptr;
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "MajorityChecker")
        {
            majorityChecker = new MajorityChecker(params[i]);
            result.push_back("null");
        }
        else if (command[i] == "query")
        {
            int value = majorityChecker->query(params[i][0], params[i][1], params[i][2]);
            result.push_back(to_string(value));
        }
    }
    Logger::WriteMessage(result);
    if (majorityChecker != nullptr)
    {
        delete majorityChecker;
        majorityChecker = nullptr;
    }
}

void TestLeetCode1156(void)
{
    Logger::WriteMessage("Test Leet Code 1156");
    LeetCode leetCode;
    string text = "ababa";
    int result = leetCode.maxRepOpt1(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));

    text = "aaabaaa";
    result = leetCode.maxRepOpt1(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));

    text = "aaabbaaa";
    result = leetCode.maxRepOpt1(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));

    text = "aaaaa";
    result = leetCode.maxRepOpt1(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));

    text = "abcdef";
    result = leetCode.maxRepOpt1(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));
}

void TestLeetCode1152(void)
{
    Logger::WriteMessage("Test Leet Code 1152");
    LeetCode leetCode;
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

void TestLeetCode1161(void)
{
    Logger::WriteMessage("Test Leet Code 1161");
    LeetCode leetCode;
    string input = "[1,7,0,7,-8,null,null]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.maxLevelSum(root);
    Logger::WriteMessage("input = " + input + "result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1163(void)
{
    Logger::WriteMessage("Test Leet Code 1163");
    LeetCode leetCode;
    string s = "abab";
    string result = leetCode.lastSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "leetcode";
    result = leetCode.lastSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1169(void)
{
    Logger::WriteMessage("Test Leet Code 1169");
    LeetCode leetCode;
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


void TestLeetCode1166(void)
{
    Logger::WriteMessage("Test Leet Code 1166");
    vector<string> commands =
    {
        "FileSystem","create","get"
    };
    vector<vector<string>> data =
    {
        {}, {"/a", "1"}, {"/a"}
    };

    FileSystemII *fileSystemII = nullptr;

    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FileSystem")
        {
            fileSystemII = new FileSystemII();
            result.push_back("null");
        }
        else if (commands[i] == "create")
        {
            bool ret = fileSystemII->create(data[i][0], atoi(data[i][1].c_str()));
            result.push_back((string)(ret ? "true" : "false"));
        }
        else if (commands[i] == "get")
        {
            int ret = fileSystemII->get(data[i][0]);
            result.push_back(to_string(ret));
        }
    }
    Logger::WriteMessage(result);

    commands =
    {
       "FileSystem","create","create","get","create","get"
    };
    data =
    {
        {} ,{"/leet","1"},{"/leet/code","2"},{"/leet/code"},{"/c/d","1"},{"/c"}
    };

    fileSystemII = nullptr;

    result.clear();
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FileSystem")
        {
            fileSystemII = new FileSystemII();
            result.push_back("null");
        }
        else if (commands[i] == "create")
        {
            bool ret = fileSystemII->create(data[i][0], atoi(data[i][1].c_str()));
            result.push_back((string)(ret ? "true" : "false"));
        }
        else if (commands[i] == "get")
        {
            int ret = fileSystemII->get(data[i][0]);
            result.push_back(to_string(ret));
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode1167(void)
{
    Logger::WriteMessage("Test Leet Code 1167");
    LeetCode leetCode;
    vector<int> sticks = { 2,4,3 };
    int result = leetCode.connectSticks(sticks);
    Logger::WriteMessage(sticks);
    Logger::WriteMessage("result = " + to_string(result));

    sticks = { 1,8,3,5 };
    result = leetCode.connectSticks(sticks);
    Logger::WriteMessage(sticks);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode1172(void)
{
    Logger::WriteMessage("Test Leet Code 1172");
    vector<string> commands =
    {
        "DinnerPlates", "push", "push", "push", "push", "push", "popAtStack",
        "push","push","popAtStack","popAtStack","pop","pop","pop","pop","pop"
    };

    vector<vector<int>> data =
    {
        {2} ,{1},{2},{3},{4},{5},{0},{20},{21},{0},{2},{},{},{},{},{}
    };

    DinnerPlates* dinnerPlates = nullptr;

    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "DinnerPlates")
        {
            dinnerPlates = new DinnerPlates(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "push")
        {
            dinnerPlates->push(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "pop")
        {
            int ret = dinnerPlates->pop();
            result.push_back(to_string(ret));
        }
        else if (commands[i] == "popAtStack")
        {
            int ret = dinnerPlates->popAtStack(data[i][0]);
            result.push_back(to_string(ret));
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode1187(void)
{
    Logger::WriteMessage("Test Leet Code 1187");
    LeetCodeDP leetCode;
    vector<int> arr1 = { 1, 5, 3, 6, 7 };
    vector<int> arr2 = { 1, 3, 2, 4 };
    int result = leetCode.makeArrayIncreasing(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("result = " + to_string(result));

    arr1 = { 1, 5, 3, 6, 7 };
    arr2 = { 4, 3, 1 };
    result = leetCode.makeArrayIncreasing(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("result = " + to_string(result));

    arr1 = { 1, 5, 3, 6, 7 };
    arr2 = { 1, 6, 3, 3 };
    result = leetCode.makeArrayIncreasing(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode1180(void)
{
    Logger::WriteMessage("Test Leet Code 1180");
    LeetCode leetCode;
    string S = "aaaba";
    int result = leetCode.countLetters(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "aaaaaaaaaa";
    result = leetCode.countLetters(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode1182(void)
{
    Logger::WriteMessage("Test Leet Code 1182");
    LeetCode leetCode;
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
    LeetCode leetCode;
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


void TestLeetCode1206(void)
{
    Logger::WriteMessage("Test Leet Code 1206");
    vector<string> commands =
    {
        "Skiplist", "add", "add", "add", "add", "add", "add", "add","add", 
        "add", "add", "add", "add", "add", "add", "add","add",
        "search", "add", "search", "erase","erase","search","erase", "erase"
    };

    vector<int> data =
    {
        -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 4, 1, 0, 1, 1, 8, 12
    };

    Skiplist* skipList = nullptr;

    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Skiplist")
        {
            skipList = new Skiplist();
            result.push_back("null");
            skipList->print();
        }
        else if (commands[i] == "add")
        {
            skipList->add(data[i]);
            result.push_back("null");
            skipList->print();
        }
        else if (commands[i] == "search")
        {
            bool ret = skipList->search(data[i]);
            skipList->print();
            result.push_back((string)(ret? "true" : "false"));
        }
        else if (commands[i] == "erase")
        {
            bool ret = skipList->erase(data[i]);
            skipList->print();
            result.push_back((string)(ret ? "true" : "false"));
        }
    }
    Logger::WriteMessage(result);

    commands =
    {
        "Skiplist", "add", "add", "add", "add", "add", "add",  "add", "add", "add", "erase",
        "search", "add", "erase", "erase", "erase", "add", "search", "search", "search",
        "erase", "search", "add", "add", "add", "erase", "search", "add", "search", "erase",
        "search", "search", "erase", "erase", "add", "erase", "search", "erase", "erase",
        "search", "add", "add", "erase", "erase", "erase", "add", "erase", "add",  
        "erase", "erase", "add", "add", "add", "search", "search", "add", "erase",
        "search", "add", "add", "search", "add", "search", "erase", "erase", "search",
        "search", "erase", "search", "add", "erase", "search", "erase", "search", "erase",
        "erase", "search", "search", "add", "add", "add", "add", "search", "search", "search",
        "search", "search", "search", "search", "search", "search"
     };
    
    data =
    {
        -1,16,5,14,13,0,3,12,9,12,3,6,7,0,1,10,5,12,7,16,7,0,9,
        16,3,2,17,2,17,0,9,14,1,6,1,16,9,10,9,2,3,16,15,12,7,4,3,2,
        1,14,13,12,3,6,17,2,3,14,11,0,13,2,1,10,17,0,5,8,9,8,11,
        10,11,10,9,8,15,14,1,6,17,16,13,4,5,4,17,16,7,14,1
    };

    result.clear();
    for (size_t i = 0; i < commands.size(); i++)
    {
        Logger::WriteMessage("command = " + commands[i] + ";data = " + to_string(data[i]));
        if (commands[i] == "Skiplist")
        {
            skipList = new Skiplist();
            result.push_back("null");
            skipList->print();
        }
        else if (commands[i] == "add")
        {
            skipList->add(data[i]);
            result.push_back("null");
            skipList->print();
        }
        else if (commands[i] == "search")
        {
            bool ret = skipList->search(data[i]);
            skipList->print();
            result.push_back((string)(ret ? "true" : "false"));
        }
        else if (commands[i] == "erase")
        {
            bool ret = skipList->erase(data[i]);
            skipList->print();
            result.push_back((string)(ret ? "true" : "false"));
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode1238(void)
{
    Logger::WriteMessage("Test Leet Code 1238");
    LeetCode leetCode;
    int n = 2; 
    int start = 3;
    vector<int> result = leetCode.circularPermutation(n, start);
    Logger::WriteMessage("n = " + to_string(n) + "; start = " + to_string(start));
    Logger::WriteMessage(result);

    n = 3;
    start = 2;
    result = leetCode.circularPermutation(n, start);
    Logger::WriteMessage("n = " + to_string(n) + "; start = " + to_string(start));
    Logger::WriteMessage(result);
}

void main(int argc, char* argv[])
{
    TestLeetCodeDP();
    TestLeetCodeGreedy();
    TestLeetCodeString();
    TestLeetCodeSort();
    TestLeetCodeMath();
    TestLeetCodeDFS();
    TestLeetCodeDesign();
    TestLeetCodeArray();
    TestLeetCodeHashtable();
    TestLeetCodeBFS();
    TestLeetCodeTree();
    TestLeetCodeGraph();
    TestLeetCodeTree();
    TestLeetCodeTwoPointers();
    TestLeetCodeUnionFind();
    TestLeetCodeBinarySearch();
    TestLeetCodeLinkedList();
    TestLeetCode915();
    TestLeetCodeStack();
    TestLeetCode1238();
    TestLeetCode89();
    TestLeetCode902();
    TestLeetCode1206();
    TestLeetCode1199();
    TestLeetCode5();
    TestLeetCode1192();
    TestLeetCode1182();
    TestLeetCode1180();
    TestLeetCode1185();
    TestLeetCode1187();
    TestLeetCode778();
    TestLeetCode773();
    TestLeetCode815();
    TestLeetCode444();
    TestLeetCode269();
    TestLeetCode1176();
    TestLeetCode1172();
    TestLeetCode1168();
    TestLeetCode1167();
    TestLeetCode1166();
    TestLeetCode1171();
    TestLeetCode1169();
    TestLeetCode1063();
    TestLeetCode1163();
    TestLeetCode1161();
    TestLeetCode1152();
    TestLeetCode1156();
    TestLeetCode1153();
    TestLeetCode1157();
    TestLeetCode1150();
    TestLeetCode1146();
    TestLeetCode1145();
    TestLeetCode1139();
    TestLeetCode1136();
    TestLeetCode1135();
    TestLeetCode1140();
    TestLeetCode1133();
    TestLeetCode1129();
    TestLeetCode218();
    TestLeetCode1128();
    TestLeetCode1125();
    TestLeetCode1121();
    TestLeetCode1124();
    TestLeetCode1123();
    TestLeetCode1120();
    TestLeetCode1122();
    TestLeetCode1110();
    TestLeetCode1109();
    TestLeetCode1105();
    TestLeetCode1102();
    TestLeetCode1100();
    TestLeetCode1099();
    TestLeetCode1104();
    TestLeetCode1103();
    TestLeetCode1095();
    TestLeetCode1094();
    TestLeetCode1093();
    TestLeetCode1067();
    TestLeetCode1066();
    TestLeetCode1087();
    TestLeetCode1086();
    TestLeetCode1092();
    TestLeetCode1090();
    TestLeetCode1089();
    TestLeetCode1062();
    TestLeetCode1060();
    TestLeetCode1059();
    TestLeetCode1058();
    TestLeetCode1057();
    TestLeetCode1080();
    TestLeetCode1079();
    TestLeetCode1078();
    TestLeetCode1065();
    TestLeetCode1064();
    TestLeetCode1056();
    TestLeetCode1073();
    TestLeetCode1072();
    TestLeetCode1074();
    TestLeetCode1053();
    TestLeetCode1052();
    TestLeetCode1054();
    TestLeetCode1051();
    TestLeetCode1049();
    TestLeetCode1039();
    TestLeetCode1048();
    TestLeetCode1046();
    TestLeetCode1043();
    TestLeetCode1036();
    TestLeetCode1041();
    TestLeetCode1040();
    TestLeetCode1038();
    TestLeetCode1037();
    TestLeetCode1031();
    TestLeetCode1029();
    TestLeetCode912();
    TestLeetCode1027();
    TestLeetCode1028();
    TestLeetCode1026();
    TestLeetCode1025();
    TestLeetCode1024();
    TestLeetCode1023();
    TestLeetCode1021();
    TestLeetCode1022();
    TestLeetCode1018();
    TestLeetCode1017();
    TestLeetCode1014();
    TestLeetCode1013();
    TestLeetCode1016();
    TestLeetCode1014();
    TestLeetCode1010();
    TestLeetCode1012();
    TestLeetCode1009();
    TestLeetCode1011();
    TestLeetCode1001();
    TestLeetCode1006();
    TestLeetCode1008();
    TestLeetCode1007();
    TestLeetCode1005();
    TestLeetCode1004();
    TestLeetCode1002();
    TestLeetCode1000();
    TestLeetCode998();
    TestLeetCode997();
    TestLeetCode999();
    TestLeetCode995();
    TestLeetCode993();
    TestLeetCode996();
    TestLeetCode9900();
    TestLeetCode992();
    TestLeetCode989();
    TestLeetCode510();
    TestLeetCode988();
    TestLeetCode987();
    TestLeetCode986();
    TestLeetCode985();
    TestLeetCode983();
    TestLeetCode982();
    TestLeetCode984();
    TestLeetCode980();
    TestLeetCode978();
    TestLeetCode979();
    TestLeetCode977();
    TestLeetCode975();
    TestLeetCode971();
    TestLeetCode969();
    TestLeetCode970();
    TestLeetCode965();
    TestLeetCode968();
    TestLeetCode200();
    TestLeetCode962();
    TestLeetCode964();
    TestLeetCode961();
    TestLeetCode960();
    TestLeetCode959();
    TestLeetCode958();
    TestLeetCode957();
    TestLeetCode956();
    TestLeetCode955();
    TestLeetCode954();
    TestLeetCode953();
    TestLeetCode951();
    TestLeetCode950();
    TestLeetCode948();
    TestLeetCode945();
    TestLeetCode944();
    TestLeetCode942();
    TestLeetCode941();
    TestLeetCode940();
    TestLeetCode939();
    TestLeetCode938();
    TestLeetCode937();
    TestLeetCode935();
    TestLeetCode936();
    TestLeetCode933();
    TestLeetCode9904();
    TestLeetCode931();
    TestLeetCode932();
    TestLeetCode929();
    TestLeetCode918();
    TestLeetCode927();
    TestLeetCode926();
    TestLeetCode925();
    TestLeetCode911();
    TestLeetCode919();
    TestLeetCode922();
    TestLeetCode923();
    TestLeetCode916();
    TestLeetCode915();
    TestLeetCode917();
    TestLeetCode920();
    TestLeetCode913();
    TestLeetCode910();
    TestLeetCode908();
    TestLeetCode907();
    TestLeetCode904();
    TestLeetCode905();
    TestLeetCode903();
    TestLeetCode900();
    TestLeetCode901();
    TestLeetCode902();
    TestLeetCode899();
    TestLeetCode898();
    TestLeetCode897();
    TestLeetCode896();
    TestLeetCode894();
    TestLeetCode893();
    TestLeetCode892();
    TestLeetCode891();
    TestLeetCode890();
    TestLeetCode889();
    TestLeetCode888();
    TestLeetCode886();
    TestLeetCode885();
    TestLeetCode880();
    TestLeetCode887();
    TestLeetCode884();
    TestLeetCode881();
    TestLeetCode883();
    TestLeetCode4();
    TestLeetCode877();
    TestLeetCode641();
    TestLeetCode622();
    TestLeetCode590();
    TestLeetCode589();
    TestLeetCode559();
    TestLeetCode528();
    TestLeetCode519();
    TestLeetCode497();
    TestLeetCode489();
    TestLeetCode478();
    TestLeetCode457();
    TestLeetCode433();
    TestLeetCode431();
    TestLeetCode429();
    TestLeetCode428();
    TestLeetCode426();
    TestLeetCode710();
    TestLeetCode707();
    TestLeetCode704();
    TestLeetCode703();
    TestLeetCode702();
    TestLeetCode701();
    TestLeetCode700();
    TestLeetCode873();
    TestLeetCode874();
    TestLeetCode872();
    TestLeetCode871();
    TestLeetCode870();
    TestLeetCode868();
    TestLeetCode865();
    TestLeetCode867();
    TestLeetCode868();
    TestLeetCode862();
    TestLeetCode863();
    TestLeetCode861();
    TestLeetCode860();
    TestLeetCode209();
    TestLeetCode856();
    TestLeetCode859();
    TestLeetCode855();
    TestLeetCode853();
    TestLeetCode851();
    TestLeetCode848();
    TestLeetCode852();
    TestLeetCode850();
    TestLeetCode849();
    TestLeetCode845();
    TestLeetCode847();
    TestLeetCode844();
    TestLeetCode842();
    TestLeetCode841();
    TestLeetCode840();
    TestLeetCode843();
    TestLeetCode837();
    TestLeetCode838();
    TestLeetCode836();
    TestLeetCode834();
    TestLeetCode833();
    TestLeetCode835();
    TestLeetCode832();
    TestLeetCode828();
    TestLeetCode829();
    TestLeetCode831();
    TestLeetCode826();
    TestLeetCode825();
    TestLeetCode823();
    TestLeetCode736();
    TestLeetCode822();
    TestLeetCode824();
    TestLeetCode820();
    TestLeetCode816();
    TestLeetCode821();
    TestLeetCode819();
    TestLeetCode813();
    TestLeetCode814();
    TestLeetCode809();
    TestLeetCode808();
    TestLeetCode811();
    TestLeetCode805();
    TestLeetCode807();
    TestLeetCode806();
    TestLeetCode804();
    TestLeetCode802();
    TestLeetCode801();
    TestLeetCode799();
    TestLeetCode797();
    TestLeetCode796();
    TestLeetCode793();
    TestLeetCode795();
    TestLeetCode792();
    TestLeetCode794();
    TestLeetCode791();
    TestLeetCode790();
    TestLeetCode789();
    TestLeetCode788();
    TestLeetCode786();
    TestLeetCode782();
    TestLeetCode785();
    TestLeetCode780();
    TestLeetCode783();
    TestLeetCode784();
    TestLeetCode779();
    TestLeetCode777();
    TestLeetCode776();
    TestLeetCode775();
    TestLeetCode774();
    TestLeetCode767();
    TestLeetCode763();
    TestLeetCode764();
    TestLeetCode771();
    TestLeetCode769();
    TestLeetCode765();
    TestLeetCode766();
    TestLeetCode762();
    TestLeetCode758();
    TestLeetCode759();
    TestLeetCode760();
    TestLeetCode761();
    TestLeetCode755();
    TestLeetCode754();
    TestLeetCode757();
    TestLeetCode756();
    TestLeetCode341();
    TestLeetCode460();
    TestLeetCode751();
    TestLeetCode752();
    TestLeetCode753();
    TestLeetCode747();
    TestLeetCode749();
    TestLeetCode750();
    TestLeetCode748();
    TestLeetCode746();
    TestLeetCode742();
    TestLeetCode743();
    TestLeetCode540();
    TestLeetCode744();
    TestLeetCode378();
    TestSalesOrg();
    TestLeetCode741();
    TestLeetCode480();
    TestLeetCode738();
    TestLeetCode741();
    TestLeetCode740();
    TestLeetCode736();
    TestLeetCode732();	
    TestLeetCode734();
    TestLeetCode733();
    TestLeetCode730();
    TestLeetCode727();
    TestLeetCode726();
    TestLeetCode714();
    TestLeetCode699();
    TestLeetCode689();
    TestLeetCode715();
    TestLeetCode729();
    TestLeetCode731();
    TestLeetCode728();

    TestLeetCode718();
    TestLeetCode724();
    TestLeetCode722();
    TestLeetCode723();
    TestLeetCode691();
    TestLeetCode720();
    TestLeetCode685();
    TestLeetCode443();
    TestLeetCode711();
    TestLeetCode712();
    TestLeetCode717();
    TestLeetCode713();
    TestLeetCode684();
    TestLeetCode313();
    TestLeetCode698();
    TestLeetCode696();
    TestLeetCode697();
    TestLeetCode139();
    TestLeetCode140();
    TestLeetCode679();
    TestLeetCode692();
    TestLeetCode688();
    TestLeetCode694();
    TestLeetCode668();
    TestLeetCode693();
    TestLeetCode664();
    TestLeetCode687();
    TestLeetCode660();
    TestLeetCode678();
    TestLeetCode681();
    TestLeetCode682();
    TestLeetCode680();
    TestLeetCode417();
    TestLeetCode674();
    TestLeetCode670();
    TestLeetCode672();
    TestLeetCode671();
    TestLeetCode669();
    TestLeetCode667();
    TestLeetCode659();
    TestLeetCode666();
    TestLeetCode662();
    TestLeetCode663();
    TestLeetCode658();
    TestLeetCode665();
    TestLeetCode661();
    TestLeetCode655();
    TestLeetCode654();
    TestLeetCode653();
    TestLeetCode649();
    TestLeetCode652();
    TestLeetCode651();
    TestLeetCode650();
    TestLeetCode648();
    TestLeetCode647();
    TestLeetCode565();
    TestLeetCode645();
    TestLeetCode646();
    TestLeetCode106();
    TestLeetCode105();
    TestLeetCode100();
    TestLeetCode99();
    TestLeetCode101();
    TestLeetCode108();
    TestLeetCode109();
    TestLeetCode404();
    TestLeetCode129();
    TestLeetCode113();
    TestLeetCode112();
    TestLeetCode114();
    TestLeetCode331();
    TestLeetCode98();
    TestLeetCode199();
    TestLeetCode226();
    TestLeetCode644();
    TestLeetCode643();
    TestLeetCode104();
    TestLeetCode111();
    TestLeetCode107();
    TestLeetCode103();
    TestLeetCode145();
    TestLeetCode94();
    TestLeetCode144();
    TestLeetCode297();
    TestLeetCode639();
    TestLeetCode640();
    TestLeetCode638();
    TestLeetCode637();
    TestLeetCode479();
    TestLeetCode236();
    TestLeetCode110();
    TestLeetCode480();
    TestLeetCode120();
    TestLeetCode632();
    TestLeetCode635();
    TestLeetCode634();
    TestLeetCode630();
    TestLeetCode629();
    TestLeetCode628();
    TestLeetCode591();
    TestLeetCode621();
    TestLeetCode623();
    TestLeetCode625();
    TestLeetCode624();
    TestLeetCode616();
    TestLeetCode617();
    TestLeetCode604();
    TestLeetCode606();
    TestLeetCode605();
    TestLeetCode609();
    TestLeetCode567();
    TestLeetCode583();
    TestLeetCode568();
    TestLeetCode587();
    TestLeetCode582();
    TestLeetCode560();
    TestLeetCode594();
    TestLeetCode581();
    TestLeetCode573();
    TestLeetCode575();
    TestLeetCode566();
    TestLeetCode572();
    TestLeetCode563();
    TestLeetCode207();
    TestLeetCode561();
    TestLeetCode552();
    TestLeetCode551();
    TestLeetCode555();
    TestLeetCode546();
    TestLeetCode554();
    TestLeetCode549();
    TestLeetCode556();
    TestLeetCode557();
    TestLeetCode522();
    TestLeetCode521();
    TestLeetCode542();
    TestLeetCode538();
    TestLeetCode543();
    TestLeetCode548();
    TestLeetCode545();
    TestLeetCode544();
    TestLeetCode450();
    TestLeetCode539();
    TestLeetCode536();
    TestLeetCode527();
    TestLeetCode541();
    TestLeetCode337();
    TestLeetCode274();
    TestLeetCode75();
    TestLeetCode257();
    TestLeetCode529();
    TestLeetCode524();
    TestLeetCode530();
    TestLeetCode532();
    TestLeetCode533();
    TestLeetCode531();
    TestLeetCode514();
    TestLeetCode401();
    TestLeetCode517();
    TestLeetCode502();
    TestLeetCode466();
    TestLeetCode440();
    TestLeetCode17();
    TestLeetCode22();
    TestLeetCode267();
    TestLeetCode471();
    TestLeetCode363();
    TestLeetCode309();
    TestLeetCode351();
    TestLeetCode472();
    TestLeetCode465();
    TestLeetCode358();
    TestLeetCode493();
    TestLeetCode488();
    TestLeetCode503();
    TestLeetCode496();
    TestLeetCode272();
    TestLeetCode513();
    TestLeetCode515();
    TestLeetCode504();
    TestLeetCode411();
    TestLeetCode308();
    TestLeetCode498();
    TestLeetCode495();
    TestLeetCode508();
    TestLeetCode501();
    TestLeetCode506();
    TestLeetCode375();
    TestLeetCode500();
    TestLeetCode484();
    TestLeetCode467();
    TestLeetCode317();
    TestLeetCode296();
    TestLeetCode286();
    TestLeetCode361();
    TestLeetCode418();
    TestLeetCode291();
    TestLeetCode494();
    TestLeetCode353();
    TestLeetCode321();
    TestLeetCode248();
    TestLeetCode247();
    TestLeetCode487();
    TestLeetCode161();
    TestLeetCode265();
    TestLeetCode360();
    TestLeetCode340();
    TestLeetCode159();
    TestLeetCode253();
    TestLeetCode158();
    TestLeetCode157();
    TestLeetCode277();
    TestLeetCode294();
    TestLeetCode163();
    TestLeetCode9901();
    TestLeetCode256();
    TestLeetCode348();
    TestLeetCode325();
    TestLeetCode323();
    TestLeetCode481();
    TestLeetCode285();
    TestLeetCode333();
    TestLeetCode314();
    TestLeetCode261();
    TestLeetCode255();
    TestLeetCode298();
    TestLeetCode250();
    TestLeetCode156();
    TestLeetCode259();
    TestLeetCode473();
    TestLeetCode334();
    TestLeetCode186();
    TestLeetCode221();
    TestLeetCode271();
    TestLeetCode320();
    TestLeetCode245();
    TestLeetCode244();    
    TestLeetCode311();
    TestLeetCode370();
    TestLeetCode280();
    TestLeetCode366();
    TestLeetCode276();
    TestLeetCode254();
    TestLeetCode476();
    TestLeetCode408();
    TestLeetCode422();
    TestLeetCode270();
    TestLeetCode249();
    TestLeetCode246();
    TestLeetCode252();
    TestLeetCode243();
    TestLeetCode266();
    TestLeetCode346();
    TestLeetCode362();
    TestLeetCode359();
    TestLeetCode399();
    TestLeetCode301();
    TestLeetCode332();
    TestLeetCode310();
    TestLeetCode388();
    TestLeetCode452();
    TestLeetCode435();
    TestLeetCode386();
    TestLeetCode216();
    TestLeetCode282();
    TestLeetCode130();
    TestLeetCode390();
    TestLeetCode81();
    TestLeetCode436();
    TestLeetCode220();
    TestLeetCode279();
    TestLeetCode240();
    TestLeetCode445();
    TestLeetCode451();
    TestLeetCode406();
    TestLeetCode456();
    TestLeetCode228();
    TestLeetCode477();
    TestLeetCode306();
    TestLeetCode307();
    TestLeetCode468();
    TestLeetCode179();
    TestLeetCode432();
    TestLeetCode475();
    TestLeetCode461();
    TestLeetCode347();
    TestLeetCode230();
    TestLeetCode222();
    TestLeetCode300();
    TestLeetCode324();
    TestLeetCode376();
    TestLeetCode392();
    TestLeetCode304();
    TestLeetCode421();
    TestLeetCode131();
    TestLeetCode384();
    TestLeetCode328();
    TestLeetCode398();
    TestLeetCode162();
    TestLeetCode238();
    TestLeetCode210();
    TestLeetCode167();
    TestLeetCode211();
    TestLeetCode116();
    TestLeetCode303();
    TestLeetCode234();
    TestLeetCode290();
    TestLeetCode438();
    TestLeetCode437();
    TestLeetCode462();
    TestLeetCode147();
    TestLeetCode160();
    TestLeetCode133();
    TestLeetCode48();
    TestLeetCode93();
    TestLeetCode173();
    TestLeetCode453();
    TestLeetCode260();
    TestLeetCode268();
    TestLeetCode318();
    TestLeetCode201();
    TestLeetCode393();
    TestLeetCode397();
    TestLeetCode190();
    TestLeetCode137();
    TestLeetCode405();
    TestLeetCode212();
    TestLeetCode126();
    TestLeetCode278();
    TestLeetCode85();
    TestLeetCode124();
    TestLeetCode383();
    TestLeetCode455();
    TestLeetCode463();
    TestLeetCode38();
    TestLeetCode400();
    TestLeetCode357();
    TestLeetCode233();
    TestLeetCode125();
    TestLeetCode232();
    TestLeetCode225();
    TestLeetCode223();
    TestLeetCode219();
    TestLeetCode350();
    TestLeetCode349();
    TestLeetCode299();
    TestLeetCode95();
    TestLeetCode96();
    TestLeetCode59();
    TestLeetCode217();
    TestLeetCode374();
    TestLeetCode127();
    TestLeetCode202();
    TestLeetCode74();
    TestLeetCode35();
    TestLeetCode34();
    TestLeetCode322();
    TestLeetCode198();
    TestLeetCode166();
    TestLeetCode123();
    TestLeetCode90();
    TestLeetCode78();
    TestLeetCode31();
    TestLeetCode283();
    TestLeetCode122();
    TestLeetCode273();
    TestLeetCode27();
    TestLeetCode239();
    TestLeetCode128();
    TestLeetCode164();
    TestLeetCode264();
    TestLeetCode87();
    TestLeetCode84();
    TestLeetCode30();
    TestLeetCode335();
    TestLeetCode420();
    TestLeetCode263();
    TestLeetCode389();
    TestLeetCode136();
    TestLeetCode168();
    TestLeetCode171();
    TestLeetCode203();
    TestLeetCode92();
    TestLeetCode206();
    TestLeetCode342();
    TestLeetCode338();
    TestLeetCode231();
    TestLeetCode42();
    TestLeetCode57();
    TestLeetCode45();
    TestLeetCode55();
    TestLeetCode97();
    TestLeetCode60();
    TestLeetCode86();
    TestLeetCode82();
    TestLeetCode83();
    TestLeetCode61();
    TestLeetCode21();
    TestLeetCode16();
    TestLeetCode191();
    TestLeetCode371();
    TestLeetCode155();
    TestLeetCode11();
    TestLeetCode151();
    TestLeetCode12();
    TestLeetCode13();
    TestLeetCode12();
    TestLeetCode13();
    TestLeetCode89();
    TestLeetCode69();
    TestLeetCode410();
    TestLeetCode66();
    TestLeetCode354();
    TestLeetCode56();
    TestLeetCode121();

    printf("Please press a key to end");
    int key = _getch();
    return;
}

