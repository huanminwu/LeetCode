#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeStack.h"
#include "TestStack.h"
void TestLeetCode20(void)
{
    Logger::WriteMessage("Test Leet Code 20");
    LeetCodeStack leetCode;
    string message;
    string parentheses = "()[]{}";
    Logger::WriteMessage("The parentheses are " + parentheses);
    Logger::WriteMessage(leetCode.isValidParentheses(parentheses) ? "is valid" : "is not valid");

    parentheses = "([)]";
    Logger::WriteMessage("The parentheses are " + parentheses);
    Logger::WriteMessage(leetCode.isValidParentheses(parentheses) ? "is valid" : "is not valid");
}

void TestLeetCode32(void)
{
    Logger::WriteMessage("Test Leet Code 32");
    LeetCodeStack leetCode;
    int result;
    string s;
    s.assign("(()");
    result = leetCode.longestValidParentheses(s);
    Logger::WriteMessage("s = " + s + " longest valid parentheses = " + to_string(result));
    s.assign(")()())");
    result = leetCode.longestValidParentheses(s);
    Logger::WriteMessage("s = " + s + " longest valid parentheses = " + to_string(result));
}

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

void TestLeetCode921(void)
{
    Logger::WriteMessage("Test Leet Code 921");
    LeetCodeStack leetCode;
    string S = "())";
    int result = leetCode.minAddToMakeValid(S);
    Logger::WriteMessage(S);
    Logger::WriteMessage("result = " + to_string(result));

    S = "(((";
    result = leetCode.minAddToMakeValid(S);
    Logger::WriteMessage(S);
    Logger::WriteMessage("result = " + to_string(result));

    S = "()";
    result = leetCode.minAddToMakeValid(S);
    Logger::WriteMessage(S);
    Logger::WriteMessage("result = " + to_string(result));

    S = "()))((";
    result = leetCode.minAddToMakeValid(S);
    Logger::WriteMessage(S);
    Logger::WriteMessage("result = " + to_string(result));
}
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

void TestLeetCode1249(void)
{
    Logger::WriteMessage("Test Leet Code 1249");
    LeetCodeStack leetCode;
    string s = "lee(t(c)o)de)";
    string result = leetCode.minRemoveToMakeValid(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "a)b(c)d";
    result = leetCode.minRemoveToMakeValid(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "))((";
    result = leetCode.minRemoveToMakeValid(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
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

void TestLeetCode1865(void)
{
    Logger::WriteMessage("Test Leet Code 1865");
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

void TestLeetCodeStack(void)
{
    TestLeetCode1865();
    TestLeetCode503();
    TestLeetCode496();
    TestLeetCode1475();
    TestLeetCode1425();
    TestLeetCode739();
    TestLeetCode1249();
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
    TestLeetCode921();
    TestLeetCode735();
    TestLeetCode439();
    TestLeetCode394();
    TestLeetCode385();
    TestLeetCode150();
    TestLeetCode32();
    TestLeetCode20();
}