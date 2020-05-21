#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeBit.h"
#include "TestBit.h"

void TestLeetCode477(void)
{
    Logger::WriteMessage("Test Leet Code 377");
    LeetCodeBit leetCode;
    vector<int> nums = { 4, 14, 2 };
    Logger::WriteMessage(nums);
    int total = leetCode.totalHammingDistance(nums);
    Logger::WriteMessage("Total Hamming Distance = " + to_string(total));
}

void TestLeetCode405(void)
{
    Logger::WriteMessage("Test Leet Code 405");
    LeetCodeBit leetCode;
    int num = -3;
    Logger::WriteMessage("num = " + to_string(num));
    string result = leetCode.toHex(num);
    Logger::WriteMessage("to Hex = " + result);
}

void TestLeetCode805(void)
{
    Logger::WriteMessage("Test Leet Code 805");
    LeetCodeBit leetCode;

    vector<int> A = { 16, 19, 5, 0, 2, 3 };
    bool result = leetCode.splitArraySameAverageII(A);

    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

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

void TestLeetCode260(void)
{
    Logger::WriteMessage("Test Leet Code 260");
    LeetCodeBit leetCode;
    vector<int> nums = { 1, 2, 1, 3, 2, 5 };
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.singleNumberIII(nums);
    Logger::WriteMessage("The single numbers are");
    Logger::WriteMessage(result);
}

void TestLeetCode137(void)
{
    Logger::WriteMessage("Test Leet Code 137");
    LeetCodeBit leetCode;
    vector<int> nums = { 1,1,1,2,3,3,3 };
    int result = leetCode.singleNumberII(nums);
    Logger::WriteMessage("result = " + to_string(result));

    Logger::WriteMessage("Test Leet Code 137");
    nums = { 1,1,1,-2,-3,-3,-3 };
    result = leetCode.singleNumberII(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode136(void)
{
    Logger::WriteMessage("Test Leet Code 136");
    LeetCodeBit leetCode;
    vector<int> data = { 1, 1, 2, 3, 3 };
    Logger::WriteMessage(data);
    int number = leetCode.singleNumber(data);
    Logger::WriteMessage(to_string(number));
}

void TestLeetCode190(void)
{
    Logger::WriteMessage("Test Leet Code 190");
    LeetCodeBit leetCode;
    uint32_t n = 43261596;
    Logger::WriteMessage("n = " + to_string(n) + "; reverse bits = " + to_string(leetCode.reverseBits(n)));
}

void TestLeetCode693(void)
{
    LeetCodeBit leetCode;
    int n = 5;
    bool result = leetCode.hasAlternatingBits(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));

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

void TestLeetCode762(void)
{
    Logger::WriteMessage("Test Leet Code 762");
    LeetCodeBit leetCode;
    int L = 10, R = 15;
    int result = leetCode.countPrimeSetBits(L, R);
    Logger::WriteMessage("L = " + to_string(L) + "; R = " + to_string(R) + "; result = " + to_string(result));
}

void TestLeetCode201(void)
{
    Logger::WriteMessage("Test Leet Code 201");
    LeetCodeBit leetCode;
    int m = 7, n = 5;
    int sum = leetCode.rangeBitwiseAnd(m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage("sum = " + to_string(sum));
}

void TestLeetCode1016(void)
{
    Logger::WriteMessage("Test Leet Code 1016");
    LeetCodeBit leetCode;
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

void TestLeetCode1018(void)
{
    Logger::WriteMessage("Test Leet Code 1018");
    LeetCodeBit leetCode;
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

void TestLeetCode268(void)
{
    Logger::WriteMessage("Test Leet Code 268");
    LeetCodeBit leetCode;
    vector<int> nums = { 0, 1, 3 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The missing number = " + to_string(leetCode.missingNumber(nums)));
}

void TestLeetCode318(void)
{
    Logger::WriteMessage("Test Leet Code 318");
    LeetCodeBit leetCode;
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

void TestLeetCode1072(void)
{
    Logger::WriteMessage("Test Leet Code 1072");
    LeetCodeBit leetCode;
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

void TestLeetCode390(void)
{
    LeetCodeBit leetCode;
    Logger::WriteMessage("Test Leet Code 390");
    int n = 9;
    int lastRemaining = leetCode.lastRemaining(n);
    Logger::WriteMessage("n = " + to_string(n) + "; last remaining = " + to_string(lastRemaining));
}

void TestLeetCode342(void)
{
    Logger::WriteMessage("Test Leet Code 342");
    LeetCodeBit leetCode;
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

void TestLeetCode397(void)
{
    Logger::WriteMessage("Test Leet Code 397");
    LeetCodeBit leetCode;
    uint32_t n;
    n = 7;
    Logger::WriteMessage("n = " + to_string(n) + "; minimum replacement = " + to_string(leetCode.integerReplacement(n)));
    n = 3;
    Logger::WriteMessage("n = " + to_string(n) + "; minimum replacement = " + to_string(leetCode.integerReplacement(n)));
}

void TestLeetCode191(void)
{
    LeetCodeBit leetCode;
    uint32_t n = 11;
    Logger::WriteMessage("Total 1 bits in " + to_string(n) + " is " + to_string(leetCode.hammingWeight(n)));
}

void TestLeetCode1073(void)
{
    Logger::WriteMessage("Test Leet Code 1073");
    LeetCodeBit leetCode;
    vector<int> arr1 = { 1, 1, 1, 1, 1 };
    vector<int> arr2 = { 1, 0, 1 };
    vector<int> result = leetCode.addNegabinary(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage(result);
}

void TestLeetCode1017(void)
{
    Logger::WriteMessage("Test Leet Code 1017");
    LeetCodeBit leetCode;
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

void TestLeetCode868(void)
{
    Logger::WriteMessage("Test Leet Code 868");
    LeetCodeBit leetCode;
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

void TestLeetCode1009(void)
{
    Logger::WriteMessage("Test Leet Code 1009");
    LeetCodeBit leetCode;
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

void TestLeetCode1238(void)
{
    Logger::WriteMessage("Test Leet Code 1238");
    LeetCodeBit leetCode;
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

void TestLeetCode338(void)
{
    Logger::WriteMessage("Test Leet Code 338");
    LeetCodeBit leetCode;
    int num = 12;
    Logger::WriteMessage("num = " + to_string(num));
    vector<int> result = leetCode.countBits(num);
    Logger::WriteMessage("Bits are ");
    Logger::WriteMessage(result);
}

void TestLeetCode476(void)
{
    Logger::WriteMessage("Test Leet Code 476");
    LeetCodeBit leetCode;
    int num = 5;
    int complement = leetCode.findComplement(num);
    Logger::WriteMessage("num = " + to_string(num) + "; complement = " + to_string(complement));

    num = 1;
    complement = leetCode.findComplement(num);
    Logger::WriteMessage("num = " + to_string(num) + "; complement = " + to_string(complement));
}

void TestLeetCode421(void)
{
    Logger::WriteMessage("Test Leet Code 421");
    LeetCodeBit leetCode;
    vector<int> nums = { 3, 10, 5, 25, 2, 8 };
    Logger::WriteMessage(nums);
    int maximumXOR = leetCode.findMaximumXOR(nums);
    Logger::WriteMessage("Maximum XOR = " + to_string(maximumXOR));
}

void TestLeetCode389(void)
{
    Logger::WriteMessage("Test Leet Code 389");
    LeetCodeBit leetCode;
    string s("abcd");
    string t("abcde");
    Logger::WriteMessage("s = " + s + " " + "t=" + t);
    char ch = leetCode.findTheDifference(s, t);
    string message;
    message.assign("difference = ");
    message.push_back(ch);
    Logger::WriteMessage(message);
}

void TestLeetCode371(void)
{
    LeetCodeBit leetCode;
    int a = 11, b = 13;
    Logger::WriteMessage(to_string(a) + " + " + to_string(b) + " = " + to_string(leetCode.getSum(a, b)));
}

void TestLeetCode89(void)
{
    Logger::WriteMessage("Test Leet Code 69");
    LeetCodeBit leetCode;
    int n = 4;
    vector<int> grayCode = leetCode.grayCode(n);
    Logger::WriteMessage(grayCode);
}

void TestLeetCode461(void)
{
    Logger::WriteMessage("Test Leet Code 461");
    LeetCodeBit leetCode;
    int x = 1, y = 4;
    int count = leetCode.hammingDistance(x, y);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; Haming Distance = " + to_string(count));
}

void TestLeetCodeBit(void)
{
    TestLeetCode89();
    TestLeetCode136();
    TestLeetCode137();
    TestLeetCode190();
    TestLeetCode191();
    TestLeetCode201();
    TestLeetCode260();
    TestLeetCode268();
    TestLeetCode318();
    TestLeetCode338();
    TestLeetCode342();
    TestLeetCode371();
    TestLeetCode389();
    TestLeetCode390();
    TestLeetCode397();
    TestLeetCode693();
    TestLeetCode405();
    TestLeetCode421();
    TestLeetCode461();
    TestLeetCode476();
    TestLeetCode477();
    TestLeetCode762();
    TestLeetCode805();
    TestLeetCode868();
    TestLeetCode1009();
    TestLeetCode1016();
    TestLeetCode1017();
    TestLeetCode1018();
    TestLeetCode1072();
    TestLeetCode1073();
    TestLeetCode1238();
}