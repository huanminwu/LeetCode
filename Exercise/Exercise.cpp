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
#include "..\LeetCode\LeetCodeBit.h"
#include "..\LeetCode\LeetCodeThread.h"
#include "..\LeetCode\USACO.h"
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
#include "TestBit.h"
#include "TestTwoPointer.h"
#include "TestUSACO.h"


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






void TestLeetCode217(void)
{
    Logger::WriteMessage("Test Leet Code 217");
    LeetCodeHashtable leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5, 3 };
    Logger::WriteMessage(nums);
    bool containsDuplicate = leetCode.containsDuplicate(nums);
    Logger::WriteMessage("The list " + string(containsDuplicate? "contains ": "does not contain ") + "duplicates.");

    nums = { 1, 2, 2, 3, 4, 4, 3 };
    Logger::WriteMessage(nums);
    containsDuplicate = leetCode.containsDuplicate(nums);
    Logger::WriteMessage("The list " + string(containsDuplicate ? "contains " : "does not contain ") + "duplicates.");
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


void TestLeetCode406(void)
{
    Logger::WriteMessage("Test Leet Code 406");
    LeetCode leetCode;
    vector<pair<int, int>> heights = { { 7, 0 },{ 4, 4 },{ 7, 1 },{ 5, 0 },{ 6, 1 },{ 5, 2 } };
    vector<pair<int, int>> result = leetCode.reconstructQueue(heights);
    Logger::WriteMessage(result);
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




void TestLeetCode280(void)
{
    Logger::WriteMessage("Test Leet Code 280");
    LeetCode leetCode;
    vector<int> nums = { 3, 5, 2, 1, 6, 4 };
    Logger::WriteMessage(nums);
    leetCode.wiggleSort(nums);
    Logger::WriteMessage(nums);
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

void TestLeetCode9901(void)
{
    Logger::WriteMessage("Test Leet Code 9901");
    LeetCode leetCode;
    vector<int> nums = { 1,2,-3, 4, -1 };
    Logger::WriteMessage(nums);
    int result = leetCode.getMaxExprResult(nums);
    Logger::WriteMessage("Maximum Result = " + to_string(result));
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



void TestLeetCode375(void)
{
    Logger::WriteMessage("Test Leet Code 375");
    LeetCode leetCode;
    int n = 10;
    int money = leetCode.getMoneyAmount(n);
    Logger::WriteMessage("n = " + to_string(n) + "; money = " + to_string(money));
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









void TestLeetCode581(void)
{
    LeetCode leetCode;
    vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
    Logger::WriteMessage(nums);
    int length = leetCode.findUnsortedSubarray(nums);
    Logger::WriteMessage("length = " + to_string(length));
}



void TestLeetCode583(void)
{
    LeetCode leetCode;
    string word1 = "sea", word2 = "eat";
    int result = leetCode.minDeleteDistance(word1, word2);

    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; min del distance = " + to_string(result));
}

void TestLeetCode600(void)
{
    LeetCode leetCode;
    int num = 5;
    int result = leetCode.findIntegers(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
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



void TestLeetCode639(void)
{
    LeetCode leetCode;
    string s = "1*";
    int result = leetCode.numDecodingsII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
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








void TestLeetCode698(void)
{
    LeetCode leetCode;
    vector<int> nums = { 4, 3, 2, 3, 5, 2, 2 };
    int k = 4;
    bool result = leetCode.canPartitionKSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string) (result ? "true" : " false"));
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






void TestLeetCode784(void)
{
    Logger::WriteMessage("Test Leet Code 784");
    LeetCodeDFS leetCode;
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


void TestLeetCode788(void)
{
    Logger::WriteMessage("Test Leet Code 788");
    LeetCode leetCode;
    int N = 110;
    int result = leetCode.rotatedDigits(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode790(void)
{
    Logger::WriteMessage("Test Leet Code 790");
    LeetCode leetCode;
    int N = 4;
    int result = leetCode.numTilings(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
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









void TestLeetCode808(void)
{
    Logger::WriteMessage("Test Leet Code 808");
    LeetCode leetCode;
    int N = 50;
    double result = leetCode.soupServings(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
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

void TestLeetCode589(void)
{
    Logger::WriteMessage("Test Leet Code 589");
    LeetCodeTree leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node * root = treeCodec.deserialize(input);
    vector<int> result = leetCode.preorder(root);
    Logger::WriteMessage(result);
    leetCode.freeNodes(root);
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











void TestLeetCode457(void)
{
    Logger::WriteMessage("Test Leet Code 457");
    LeetCodeArray leetCode;
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





void TestLeetCode903(void)
{
    Logger::WriteMessage("Test Leet Code 903");
    string S = "DID";
    LeetCode leetCode;
    int result = leetCode.numPermsDISequence(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
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

void TestLeetCode1023(void)
{
    Logger::WriteMessage("Test Leet Code 1023");
    LeetCodeString leetCode;
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

void main(int argc, char* argv[])
{ 
    TestLeetCodeDP();
    TestLeetCodeGraph();
    TestLeetCodeStack();
    TestLeetCodeBinarySearch();
    TestLeetCodeString();
    TestLeetCodeArray();
    TestLeetCodeMath();
    TestLeetCodeLinkedList();
    TestLeetCodeSort();
    TestLeetCodeGreedy();
    TestLeetCodeTwoPointer();
    TestLeetCodeDesign();
    TestLeetCodeTree();
    TestLeetCodeDFS();
    TestLeetCodeGraph();
    TestLeetCodeBit();
    TestLeetCodeHashtable();
    TestLeetCodeBFS();
    TestLeetCodeHashtable();
    TestLeetCode211();
    TestUSACO();
    TestLeetCode1199();
    TestLeetCode5();
    TestLeetCode1192();
    TestLeetCode1182();
    TestLeetCode1185();
    TestLeetCode1187();
    TestLeetCode778();
    TestLeetCode773();
    TestLeetCode815();
    TestLeetCode444();
    TestLeetCode269();
    TestLeetCode1176();
    TestLeetCode1168();
    TestLeetCode1167();
    TestLeetCode1171();
    TestLeetCode1169();
    TestLeetCode1153();
    TestLeetCode1146();
    TestLeetCode1139();
    TestLeetCode1136();
    TestLeetCode1135();
    TestLeetCode1133();
    TestLeetCode1129();
    TestLeetCode1121();
    TestLeetCode1124();
    TestLeetCode1122();
    TestLeetCode1102();
    TestLeetCode1099();
    TestLeetCode1103();
    TestLeetCode1095();
    TestLeetCode1093();
    TestLeetCode1066();
    TestLeetCode1086();
    TestLeetCode1092();
    TestLeetCode1090();
    TestLeetCode1062();
    TestLeetCode1059();
    TestLeetCode1058();
    TestLeetCode1057();
    TestLeetCode1078();
    TestLeetCode1065();
    TestLeetCode1053();
    TestLeetCode1051();
    TestLeetCode1039();
    TestLeetCode1048();
    TestLeetCode1046();
    TestLeetCode1043();
    TestLeetCode1040();
    TestLeetCode1037();
    TestLeetCode1031();
    TestLeetCode1029();
    TestLeetCode912();
    TestLeetCode1027();
    TestLeetCode1025();
    TestLeetCode1023();
    TestLeetCode1011();
    TestLeetCode983();
    TestLeetCode982();
    TestLeetCode978();
    TestLeetCode977();
    TestLeetCode975();
    TestLeetCode200();
    TestLeetCode962();
    TestLeetCode960();
    TestLeetCode959();
    TestLeetCode956();
    TestLeetCode955();
    TestLeetCode954();
    TestLeetCode953();
    TestLeetCode942();
    TestLeetCode941();
    TestLeetCode940();
    TestLeetCode935();
    TestLeetCode933();
    TestLeetCode931();
    TestLeetCode923();
    TestLeetCode920();
    TestLeetCode913();
    TestLeetCode907();
    TestLeetCode903();
    TestLeetCode900();
    TestLeetCode898();
    TestLeetCode886();
    TestLeetCode880();
    TestLeetCode887();
    TestLeetCode4();
    TestLeetCode877();
    TestLeetCode589();
    TestLeetCode457();
    TestLeetCode433();
    TestLeetCode707();
    TestLeetCode873();
    TestLeetCode871();
    TestLeetCode870();
    TestLeetCode853();
    TestLeetCode851();
    TestLeetCode847();
    TestLeetCode841();
    TestLeetCode837();
    TestLeetCode834();
    TestLeetCode828();
    TestLeetCode823();
    TestLeetCode813();
    TestLeetCode808();
    TestLeetCode802();
    TestLeetCode801();
    TestLeetCode799();
    TestLeetCode796();
    TestLeetCode793();
    TestLeetCode795();
    TestLeetCode794();
    TestLeetCode790();
    TestLeetCode788();
    TestLeetCode786();
    TestLeetCode785();
    TestLeetCode780();
    TestLeetCode784();
    TestLeetCode775();
    TestLeetCode774();
    TestLeetCode764();
    TestLeetCode769();
    TestLeetCode765();
    TestLeetCode754();
    TestLeetCode756();
    TestLeetCode341();
    TestLeetCode460();
    TestLeetCode752();
    TestLeetCode753();
    TestLeetCode749();
    TestLeetCode746();
    TestLeetCode743();
    TestLeetCode744();
    TestLeetCode378();
    TestSalesOrg();
    TestLeetCode741();
    TestLeetCode480();
    TestLeetCode738();
    TestLeetCode741();
    TestLeetCode740();
    TestLeetCode733();
    TestLeetCode730();
    TestLeetCode727();
    TestLeetCode714();
    TestLeetCode689();
    TestLeetCode729();
    TestLeetCode718();
    TestLeetCode691();
    TestLeetCode685();
    TestLeetCode711();
    TestLeetCode712();
    TestLeetCode684();
    TestLeetCode313();
    TestLeetCode698();
    TestLeetCode692();
    TestLeetCode688();
    TestLeetCode694();
    TestLeetCode664();
    TestLeetCode660();
    TestLeetCode681();
    TestLeetCode417();
    TestLeetCode672();
    TestLeetCode665();
    TestLeetCode651();
    TestLeetCode650();
    TestLeetCode647();
    TestLeetCode639();
    TestLeetCode638();
    TestLeetCode479();
    TestLeetCode480();
    TestLeetCode632();
    TestLeetCode635();
    TestLeetCode634();
    TestLeetCode629();
    TestLeetCode625();
    TestLeetCode604();
    TestLeetCode583();
    TestLeetCode568();
    TestLeetCode587();
    TestLeetCode582();
    TestLeetCode560();
    TestLeetCode581();
    TestLeetCode573();
    TestLeetCode207();
    TestLeetCode561();
    TestLeetCode552();
    TestLeetCode555();
    TestLeetCode546();
    TestLeetCode556();
    TestLeetCode542();
    TestLeetCode274();
    TestLeetCode75();
    TestLeetCode529();
    TestLeetCode514();
    TestLeetCode401();
    TestLeetCode440();
    TestLeetCode17();
    TestLeetCode22();
    TestLeetCode267();
    TestLeetCode351();
    TestLeetCode472();
    TestLeetCode465();
    TestLeetCode493();
    TestLeetCode488();
    TestLeetCode504();
    TestLeetCode411();
    TestLeetCode308();
    TestLeetCode375();
    TestLeetCode484();
    TestLeetCode317();
    TestLeetCode296();
    TestLeetCode286();
    TestLeetCode361();
    TestLeetCode291();
    TestLeetCode494();
    TestLeetCode353();
    TestLeetCode321();
    TestLeetCode360();
    TestLeetCode277();
    TestLeetCode294();
    TestLeetCode9901();
    TestLeetCode348();
    TestLeetCode325();
    TestLeetCode323();
    TestLeetCode261();
    TestLeetCode186();
    TestLeetCode271();
    TestLeetCode320();
    TestLeetCode245();
    TestLeetCode280();
    TestLeetCode254();
    TestLeetCode243();
    TestLeetCode346();
    TestLeetCode362();
    TestLeetCode359();
    TestLeetCode399();
    TestLeetCode301();
    TestLeetCode332();
    TestLeetCode310();
    TestLeetCode388();
    TestLeetCode216();
    TestLeetCode282();
    TestLeetCode130();
    TestLeetCode81();
    TestLeetCode220();
    TestLeetCode240();
    TestLeetCode445();
    TestLeetCode406();
    TestLeetCode307();
    TestLeetCode468();
    TestLeetCode179();
    TestLeetCode432();
    TestLeetCode300();
    TestLeetCode324();
    TestLeetCode376();
    TestLeetCode304();
    TestLeetCode328();
    TestLeetCode162();
    TestLeetCode210();
    TestLeetCode211();
    TestLeetCode303();
    TestLeetCode234();
    TestLeetCode290();
    TestLeetCode438();
    TestLeetCode462();
    TestLeetCode147();
    TestLeetCode160();
    TestLeetCode133();
    TestLeetCode48();
    TestLeetCode93();
    TestLeetCode453();
    TestLeetCode393();
    TestLeetCode212();
    TestLeetCode126();
    TestLeetCode85();
    TestLeetCode383();
    TestLeetCode455();
    TestLeetCode463();
    TestLeetCode38();
    TestLeetCode125();
    TestLeetCode232();
    TestLeetCode223();
    TestLeetCode59();
    TestLeetCode217();
    TestLeetCode127();
    TestLeetCode34();
    TestLeetCode322();
    TestLeetCode123();
    TestLeetCode90();
    TestLeetCode78();
    TestLeetCode273();
    TestLeetCode164();
    TestLeetCode264();
    TestLeetCode335();
    TestLeetCode203();
    TestLeetCode92();
    TestLeetCode206();
    TestLeetCode45();
    TestLeetCode55();
    TestLeetCode86();
    TestLeetCode82();
    TestLeetCode83();
    TestLeetCode61();
    TestLeetCode21();
    TestLeetCode11();
    TestLeetCode151();
    TestLeetCode410();
    TestLeetCode66();
    TestLeetCode354();
    TestLeetCode56();

    printf("Please press a key to end");
    int key = _getch();
    return;
}

