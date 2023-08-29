#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeStack.h"
#include "TestStack.h"


void TestLeetCode150(void)
{
    Logger::WriteMessage("Test Leet Code 150");
    LeetCodeStack leetCode;
    vector<string> tokens;
    int result;
    tokens = { "4", "13", "5", "/", "+" };
    result = leetCode.evalRPN(tokens);
    Logger::WriteMessage(tokens);
    Logger::WriteMessage("result = " + to_string(result));
    tokens = { "2", "1", "+", "3", "*" };
    result = leetCode.evalRPN(tokens);
    Logger::WriteMessage(tokens);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode316(void)
{
    Logger::WriteMessage("Test Leet Code 316");
    LeetCodeStack leetCode;
    string s = "bcabc";
    string result = leetCode.removeDuplicateLetters(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "cbacdcbc";
    result = leetCode.removeDuplicateLetters(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "abacb";
    result = leetCode.removeDuplicateLetters(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}
void TestLeetCode385(void)
{
    Logger::WriteMessage("Test Leet Code 385");
    LeetCodeStack leetCode;
    string s = "324";
    NestedInteger ni = leetCode.deserializeNestedInteger(s);

    s = "[123,[456,[789]]]";
    ni = leetCode.deserializeNestedInteger(s);
}

void TestLeetCode394(void)
{
    Logger::WriteMessage("Test Leet Code 394");
    LeetCodeStack leetCode;
    string s = "3[a2[c]]";
    Logger::WriteMessage("s = " + s);
    string result = leetCode.decodeString(s);
    Logger::WriteMessage(result);

    s = "3[a]2[bc]";
    Logger::WriteMessage("s = " + s);
    result = leetCode.decodeString(s);
    Logger::WriteMessage(result);

    s = "2[abc]3[cd]ef";
    Logger::WriteMessage("s = " + s);
    result = leetCode.decodeString(s);
    Logger::WriteMessage(result);

    s = "";
    Logger::WriteMessage("s = " + s);
    result = leetCode.decodeString(s);
    Logger::WriteMessage(result);
}

void TestLeetCode439(void)
{
    Logger::WriteMessage("Test Leet Code 439");
    LeetCodeStack leetCode;

    string expression = "T?T?F?7:T?T?F?3:F?T?0:1:0:6:1:0:5";
    string result = leetCode.parseTernaryII(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);

    expression = "T?2:3";
    result = leetCode.parseTernaryII(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);

    expression = "F?1:T?4:5";
    result = leetCode.parseTernaryII(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);

    expression = "T?T?F:5:3";
    result = leetCode.parseTernaryII(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);
}

void TestLeetCode735(void)
{
    LeetCodeStack leetCode;
    vector<int> asteroids = { 5, 10, -5 };
    vector<int> result = leetCode.asteroidCollision(asteroids);
    Logger::WriteMessage(asteroids);
    Logger::WriteMessage(result);

    asteroids = { 8, -8 };
    result = leetCode.asteroidCollision(asteroids);
    Logger::WriteMessage(asteroids);
    Logger::WriteMessage(result);

    asteroids = { 10, 2, -5 };
    result = leetCode.asteroidCollision(asteroids);
    Logger::WriteMessage(asteroids);
    Logger::WriteMessage(result);

    asteroids = { -2, -1, 1, 2 };
    result = leetCode.asteroidCollision(asteroids);
    Logger::WriteMessage(asteroids);
    Logger::WriteMessage(result);
};

void TestLeetCode946(void)
{
    Logger::WriteMessage("Test Leet Code 946");
    LeetCodeStack leetCode;
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4, 5, 3, 2, 1 };

    bool result = leetCode.validateStackSequences(pushed, popped);
    Logger::WriteMessage(pushed);
    Logger::WriteMessage(popped);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    pushed = { 1,2,3,4,5 };
    popped = { 4,3,5,1,2 };
    result = leetCode.validateStackSequences(pushed, popped);
    Logger::WriteMessage(pushed);
    Logger::WriteMessage(popped);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1003(void)
{
    Logger::WriteMessage("Test Leet Code 1003");
    LeetCodeStack leetCode;
    string S = "aabcbc";
    bool result = leetCode.isValidAbc(S);
    Logger::WriteMessage("S = " + S + "; result = " + (string)(result ? "true" : "false"));

    S = "abcabcababcc";
    result = leetCode.isValidAbc(S);
    Logger::WriteMessage("S = " + S + "; result = " + (string)(result ? "true" : "false"));

    S = "abccba";
    result = leetCode.isValidAbc(S);
    Logger::WriteMessage("S = " + S + "; result = " + (string)(result ? "true" : "false"));

    S = "cababc";
    result = leetCode.isValidAbc(S);
    Logger::WriteMessage("S = " + S + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1047(void)
{
    Logger::WriteMessage("Test Leet Code 1047");
    LeetCodeStack leetCode;
    string S = "abbaca";
    string result = leetCode.removeDuplicates(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode1081(void)
{
    Logger::WriteMessage("Test Leet Code 1081");
    LeetCodeStack leetCode;
    string text = "cdadabcc";
    string result = leetCode.smallestSubsequence(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "abcd";
    result = leetCode.smallestSubsequence(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "ecbacba";
    result = leetCode.smallestSubsequence(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "leetcode";
    result = leetCode.smallestSubsequence(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "bcbcbcababa";
    result = leetCode.smallestSubsequence(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);
}

void TestLeetCode1190(void)
{
    Logger::WriteMessage("Test Leet Code 1190");
    LeetCodeStack leetCode;
    string  s = "(abcd)";
    string result = leetCode.reverseParentheses(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "(u(love)i)";
    result = leetCode.reverseParentheses(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "(ed(et(oc))el)";
    result = leetCode.reverseParentheses(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "a(bcdefghijkl(mno)p)q";
    result = leetCode.reverseParentheses(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1209(void)
{
    Logger::WriteMessage("Test Leet Code 1209");
    LeetCodeStack leetCode;
    string  s = "abcd";
    int k = 2;
    string result = leetCode.removeDuplicates(s, k);
    Logger::WriteMessage("s = " + s + "; k =" + to_string(k) + "; result = " + result);

    s = "deeedbbcccbdaa";
    k = 3;
    result = leetCode.removeDuplicates(s, k);
    Logger::WriteMessage("s = " + s + "; k =" + to_string(k) + "; result = " + result);

    s = "pbbcggttciiippooaais";
    k = 2;
    result = leetCode.removeDuplicates(s, k);
    Logger::WriteMessage("s = " + s + "; k =" + to_string(k) + "; result = " + result);
}

void TestLeetCode339(void)
{
    Logger::WriteMessage("Test Leet Code 339");
    LeetCodeStack leetCode;
    vector<NestedInteger> n1;
    n1.push_back(1);
    n1.push_back(1);
    NestedInteger n2 = 2;
    vector<NestedInteger> n3;
    n3.push_back(1);
    n3.push_back(1);
    vector<NestedInteger> input;
    input.push_back(n1);
    input.push_back(n2);
    input.push_back(n1);
    int depthSum = leetCode.depthSum(input);
    Logger::WriteMessage("Depth Sum = " + to_string(depthSum));

    n1.clear();
    n1.push_back(6);
    n3.clear();
    n3.push_back(4);
    n3.push_back(n1);
    input.clear();
    input.push_back(1);
    input.push_back(n3);
    depthSum = leetCode.depthSum(input);
    Logger::WriteMessage("Depth Sum = " + to_string(depthSum));
}

void TestLeetCode402(void)
{
    Logger::WriteMessage("Test Leet Code 402");
    LeetCodeStack leetCode;
    string num = "1432219";
    int k = 3;
    string min_num = leetCode.removeKdigits(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; min_num = " + min_num);

    num = "10200";
    k = 1;
    min_num = leetCode.removeKdigits(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; min_num = " + min_num);

    num = "10";
    k = 2;
    min_num = leetCode.removeKdigits(num, k);
    Logger::WriteMessage("num = " + num + "; k = " + to_string(k) + "; min_num = " + min_num);
}

void TestLeetCode907(void)
{
    Logger::WriteMessage("Test Leet Code 907");
    LeetCodeStack leetCode;
    vector<int> A = { 3,1,2,4 };
    int result = leetCode.sumSubarrayMins(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode636(void)
{
    Logger::WriteMessage("Test Leet Code 636");
    LeetCodeStack leetCode;
    vector<string> logs = { "0:start:0", "1:start:2", "1:end:5", "0:end:6" };
    int n = 2;
    vector<int> result = leetCode.exclusiveTime(n, logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage(result);
}

void TestLeetCode739(void)
{
    LeetCodeStack leetCode;
    vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> result = leetCode.dailyTemperatures(temperatures);
    Logger::WriteMessage(temperatures);
    Logger::WriteMessage(result);

    temperatures = { 89, 62, 70, 58, 47, 47, 46, 76, 100, 70 };
    result = leetCode.dailyTemperatures(temperatures);
    Logger::WriteMessage(temperatures);
    Logger::WriteMessage(result);
}

void TestLeetCode1425(void)
{
    LeetCodeStack leetCode;
    vector<int>  nums = { 10, 2, -10, 5, 20 };
    int k = 2;
    int result = leetCode.constrainedSubsetSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result  = " + to_string(result));

    nums = { -1,-2,-3 };
    k = 1;
    result = leetCode.constrainedSubsetSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result  = " + to_string(result));

    nums = { 10,-2,-10,-5,20 };
    k = 2;
    result = leetCode.constrainedSubsetSum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result  = " + to_string(result));
}

void TestLeetCode239(void)
{
    Logger::WriteMessage("Test Leet Code 239");
    LeetCodeStack leetCode;
    vector<int> nums;
    vector<int> result;
    int k;
    nums = { 1,  3, -1, -3,  5, 3,  6,  7 };
    k = 3;
    Logger::WriteMessage(nums);
    result = leetCode.maxSlidingWindow(nums, k);
    Logger::WriteMessage(result);
}

void TestLeetCode1475(void)
{
    LeetCodeStack leetCode;
    vector<int> prices = { 8, 4, 6, 2, 3 };
    vector<int> result = leetCode.finalPrices(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(result);

    prices = { 1,2,3,4,5 };
    result = leetCode.finalPrices(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(result);

    prices = { 10,1,1,6 };
    result = leetCode.finalPrices(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(result);
}

void TestLeetCode496(void)
{
    Logger::WriteMessage("Test Leet Code 496");
    LeetCodeStack leetCode;
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
    LeetCodeStack leetCode;
    vector<int> nums = { 1, 2, 1 };
    vector<int> result = leetCode.nextGreaterElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1856(void)
{
    Logger::WriteMessage("Test Leet Code 1856");
    LeetCodeStack leetCode;
    vector<int> nums = { 1, 2, 3, 2 };
    int result = leetCode.maxSumMinProduct(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,3,3,1,2 };
    result = leetCode.maxSumMinProduct(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,1,5,6,4,2 };
    result = leetCode.maxSumMinProduct(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1944(void)
{
    Logger::WriteMessage("Test Leet Code 1944");
    LeetCodeStack leetCode;
    vector<int> nums = { 10,6,8,5,11,9 };
    vector<int> result = leetCode.canSeePersonsCount(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 5,1,2,3,10 };
    result = leetCode.canSeePersonsCount(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2030(void)
{
    Logger::WriteMessage("Test Leet Code 2030");
    LeetCodeStack leetCode;
    string s = "leet";
    int k = 3;
    char letter = 'e';
    int repetition = 1;
    string result = leetCode.smallestSubsequence(s, k, letter, repetition);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; letter = " + string(1, letter) +"; result = " + result);

    s = "leetcode";
    k = 4;
    letter = 'e';
    repetition = 2;
    result = leetCode.smallestSubsequence(s, k, letter, repetition);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; letter = " + string(1, letter) + "; result = " + result);

    s = "bb";
    k = 2;
    letter = 'b';
    repetition = 2;
    result = leetCode.smallestSubsequence(s, k, letter, repetition);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; letter = " + string(1, letter) + "; result = " + result);

    s = "mmmxmxymmm";
    k = 8;
    letter = 'm';
    repetition = 4;
    result = leetCode.smallestSubsequence(s, k, letter, repetition);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; letter = " + string(1, letter) + "; result = " + result);
}

void TestLeetCode1776(void)
{
    Logger::WriteMessage("Test Leet Code 1776");
    LeetCodeStack leetCode;
    vector<vector<int>> cars = { {1, 2},{2, 1},{4, 3},{7, 2} };
    vector<double> result = leetCode.getCollisionTimes(cars);
    Logger::WriteMessage(cars);
    Logger::WriteMessage(result);

    cars = { {3, 4},{5, 4},{6, 3},{9, 1} };
    result = leetCode.getCollisionTimes(cars);
    Logger::WriteMessage(cars);
    Logger::WriteMessage(result);
}

void TestLeetCode84(void)
{
    Logger::WriteMessage("Test Leet Code 84");
    LeetCodeStack leetCode;
    vector<int> heights;
    int max_area;

    heights = { 3, 6, 5, 7, 4, 8, 1, 0 };
    max_area = leetCode.largestRectangleArea(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleAreaByStack = " + to_string(max_area));

    heights = { 9, 0 };
    max_area = leetCode.largestRectangleArea(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area));

    heights = { 4, 2, 0, 3, 2, 5 };
    max_area = leetCode.largestRectangleArea(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area));

    heights = { 2,1,5,6,2,3 };
    max_area = leetCode.largestRectangleArea(heights);

    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area));

    heights = {};
    max_area = leetCode.largestRectangleArea(heights);

    heights = { 2,1,2 };
    max_area = leetCode.largestRectangleArea(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area));

    heights = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    max_area = leetCode.largestRectangleArea(heights);
    Logger::WriteMessage("Heights are");
    Logger::WriteMessage(heights);
    Logger::WriteMessage("LargestRectangleArea = " + to_string(max_area));
}

void TestLeetCode85(void)
{
    Logger::WriteMessage("Test Leet Code 85");
    LeetCodeStack leetCode;
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

void TestLeetCode1438(void)
{
    Logger::WriteMessage("Test Leet Code 1438");
    LeetCodeStack leetCode;
    vector<int> nums = { 8, 2, 4, 7 };
    int limit = 4;
    int result = leetCode.longestSubarray(nums, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    nums = { 10,1,2,4,7,2 };
    limit = 5;
    result = leetCode.longestSubarray(nums, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    nums = { 4,2,2,2,4,4,2,2 };
    limit = 0;
    result = leetCode.longestSubarray(nums, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));
}

void TestLeetCode862(void)
{
    Logger::WriteMessage("Test Leet Code 862");
    LeetCodeStack leetCode;
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

void TestLeetCode1950(void)
{
    Logger::WriteMessage("Test Leet Code 1950");
    LeetCodeStack leetCode;
    vector<int> nums = { 0, 1, 2, 4 };
    vector<int> result = leetCode.findMaximums(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 10,20,50,10 };
    result = leetCode.findMaximums(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 4,3,2, 1};
    result = leetCode.findMaximums(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 4, 3, 2, 1, 6, 5, 2, 3, 4, 9, 0 };
    result = leetCode.findMaximums(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2104(void)
{
    Logger::WriteMessage("Test Leet Code 2104");
    LeetCodeStack leetCode;
    vector<int> nums = { 1,2,3 };
    long long result = leetCode.subArrayRanges(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,3,3 };
    result = leetCode.subArrayRanges(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,-2,-3,4,1 };
    result = leetCode.subArrayRanges(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1696(void)
{
    Logger::WriteMessage("Test Leet Code 1696");
    LeetCodeStack leetCode;
    vector<int> nums = { 1, -1, -2, 4, -7, 3 };
    int k = 2;
    int result = leetCode.maxResult(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 10,-5,-2,4,0,3 };
    k = 3;
    result = leetCode.maxResult(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,-5,-20,4,-1,3,-6,-3 };
    k = 2;
    result = leetCode.maxResult(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2211(void)
{
    Logger::WriteMessage("Test Leet Code 2211");
    LeetCodeStack leetCode;
    string directions = "RLRSLL";
    int result = leetCode.countCollisions(directions);
    Logger::WriteMessage("directions = " + directions + "; result = " + to_string(result));

    directions = "LLRR";
    result = leetCode.countCollisions(directions);
    Logger::WriteMessage("directions = " + directions + "; result = " + to_string(result));
}

void TestLeetCode2281(void)
{
    Logger::WriteMessage("Test Leet Code 2281");
    LeetCodeStack leetCode;
    vector<int> strength = { 1, 3, 1, 2 };
    int result = leetCode.totalStrength(strength);
    Logger::WriteMessage(strength);
    Logger::WriteMessage("result = " + to_string(result));

    strength = { 5,4,6 };
    result = leetCode.totalStrength(strength);
    Logger::WriteMessage(strength);
    Logger::WriteMessage("result = " + to_string(result));

    strength = { 1,2,3 };
    result = leetCode.totalStrength(strength);
    Logger::WriteMessage(strength);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode2289(void)
{
    Logger::WriteMessage("Test Leet Code 2289");
    LeetCodeStack leetCode;
    vector<int> nums = { 5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11 };
    int result = leetCode.totalSteps(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,5,7,7,13 };
    result = leetCode.totalSteps(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2282(void)
{
    Logger::WriteMessage("Test Leet Code 2282");
    LeetCodeStack leetCode;
    vector<vector<int>> heights = { {3, 1, 4, 2, 5} };
    vector<vector<int>> result = leetCode.seePeople(heights);
    Logger::WriteMessage(heights);
    Logger::WriteMessage(result);

    heights = { {5, 1},{3, 1},{4, 1} };
    result = leetCode.seePeople(heights);
    Logger::WriteMessage(heights);
    Logger::WriteMessage(result);
}

void TestLeetCode2297(void)
{
    Logger::WriteMessage("Test Leet Code 2297");
    LeetCodeStack leetCode;
    vector<int> nums = { 3, 2, 4, 4, 1 };
    vector<int> costs = { 3, 7, 6, 4, 2 };
    long long result = leetCode.minCost(nums, costs);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0,1,2 };
    costs = { 1,1,1 };
    result = leetCode.minCost(nums, costs);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(costs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2334(void)
{
    Logger::WriteMessage("Test Leet Code 2334");
    LeetCodeStack leetCode;
    vector<int> nums = { 1, 3, 4, 3, 1 };
    int threshold = 6;
    int result = leetCode.validSubarraySize(nums, threshold);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));

    nums = { 6,5,6,5,8 };
    threshold = 7;
    result = leetCode.validSubarraySize(nums, threshold);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));
}

void TestLeetCode2355(void)
{
    Logger::WriteMessage("Test Leet Code 2355");
    LeetCodeStack leetCode;
    vector<int> books = { 8,5,2,7,9 };
    long long result = leetCode.maximumBooks(books);
    Logger::WriteMessage(books);
    Logger::WriteMessage("result = " + to_string(result));

    books = { 7,0,3,4,5 };
    result = leetCode.maximumBooks(books);
    Logger::WriteMessage(books);
    Logger::WriteMessage("result = " + to_string(result));

    books = { 8,2,3,7,3,4,0,1,4,3 };
    result = leetCode.maximumBooks(books);
    Logger::WriteMessage(books);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2345(void)
{
    Logger::WriteMessage("Test Leet Code 2345");
    LeetCodeStack leetCode;
    vector<vector<int>> peaks = { {2, 2},{6, 3},{5, 4} };
    int result = leetCode.visibleMountains(peaks);
    Logger::WriteMessage(peaks);
    Logger::WriteMessage("result = " + to_string(result));

    peaks = { {1, 3},{1, 3} };
    result = leetCode.visibleMountains(peaks);
    Logger::WriteMessage(peaks);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2398(void)
{
    Logger::WriteMessage("Test Leet Code 2398");
    LeetCodeStack leetCode;
    vector<int> chargeTimes = { 3, 6, 1, 3, 4 };
    vector<int> runningCosts = { 2, 1, 3, 4, 5 };
    int budget = 25;
    int result = leetCode.maximumRobots(chargeTimes, runningCosts, budget);
    Logger::WriteMessage(chargeTimes);
    Logger::WriteMessage(runningCosts);
    Logger::WriteMessage("budget = " + to_string(budget) + "; result = " + to_string(result));

    chargeTimes = { 11, 12, 19 };
    runningCosts = { 10, 8, 7 };
    budget = 19;
    result = leetCode.maximumRobots(chargeTimes, runningCosts, budget);
    Logger::WriteMessage(chargeTimes);
    Logger::WriteMessage(runningCosts);
    Logger::WriteMessage("budget = " + to_string(budget) + "; result = " + to_string(result));
}

void TestLeetCode2434(void)
{
    Logger::WriteMessage("Test Leet Code 2434");
    LeetCodeStack leetCode;
    string s = "zza";
    string result = leetCode.robotWithString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "bac";
    result = leetCode.robotWithString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "bdda";
    result = leetCode.robotWithString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode2439(void)
{
    Logger::WriteMessage("Test Leet Code 2434");
    LeetCodeStack leetCode;
    vector<int> nums = { 3, 7, 1, 6 };
    int result = leetCode.minimizeArrayValue(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 10,1 };
    result = leetCode.minimizeArrayValue(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2751(void)
{
    Logger::WriteMessage("Test Leet Code 2751");
    LeetCodeStack leetCode;
    vector<int> positions =
    {
        5, 4, 3, 2, 1
    };
    vector<int> healths =
    {
        2, 17, 9, 15, 10
    }; 
    string directions = "RRRRR";
    vector<int> result = leetCode.survivedRobotsHealths(positions, healths, directions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(healths);
    Logger::WriteMessage("directions = "  + directions);
    Logger::WriteMessage(result);

    positions =
    {
        3,5,2,6
    };
    healths =
    {
        10,10,15,12
    };
    directions = "RLRL";
    result = leetCode.survivedRobotsHealths(positions, healths, directions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(healths);
    Logger::WriteMessage("directions = " + directions);
    Logger::WriteMessage(result);

    positions =
    {
        1,2,5,6
    };
    healths =
    {
       10,10,11,11
    };
    directions = "RLRL";
    result = leetCode.survivedRobotsHealths(positions, healths, directions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(healths);
    Logger::WriteMessage("directions = " + directions);
    Logger::WriteMessage(result);
}


void TestLeetCode2832(void)
{
    Logger::WriteMessage("Test Leet Code 2832");
    LeetCodeStack leetCode;
    vector<int> nums = { 1, 5, 4, 3, 6 };
    vector<int> result = leetCode.maximumLengthOfRanges(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 1,2,3,4,5 };
    result = leetCode.maximumLengthOfRanges(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCodeStack(void)
{
    TestLeetCode2832();
    TestLeetCode2751();
    TestLeetCode2439();
    TestLeetCode2434();
    TestLeetCode2398();
    TestLeetCode2345();
    TestLeetCode2355();
    TestLeetCode2334();
    TestLeetCode2297();
    TestLeetCode2282();
    TestLeetCode2289();
    TestLeetCode2281();
    TestLeetCode2211();
    TestLeetCode1696();
    TestLeetCode2104();
    TestLeetCode1950();
    TestLeetCode862();
    TestLeetCode1438();
    TestLeetCode84();
    TestLeetCode85();
    TestLeetCode1776();
    TestLeetCode2030();
    TestLeetCode1944();
    TestLeetCode1856();
    TestLeetCode503();
    TestLeetCode496();
    TestLeetCode1475();
    TestLeetCode1425();
    TestLeetCode739();
    TestLeetCode636();
    TestLeetCode1003();
    TestLeetCode907();
    TestLeetCode339();
    TestLeetCode316();
    TestLeetCode1209();
    TestLeetCode1190();
    TestLeetCode1081();
    TestLeetCode1047();
    TestLeetCode946();
    TestLeetCode735();
    TestLeetCode439();
    TestLeetCode394();
    TestLeetCode385();
    TestLeetCode150();
}