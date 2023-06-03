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

void TestLeetCode861(void)
{
    Logger::WriteMessage("Test Leet Code 861");
    LeetCodeBit leetCode;
    vector<vector<int>> A = { {0, 0, 1, 1},{1, 0, 1, 0},{1, 1, 0, 0} };
    int result = leetCode.matrixScore(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { {0, 1},{0, 1},{0, 1},{0, 0} };
    result = leetCode.matrixScore(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

}

void TestLeetCode1461(void)
{
    Logger::WriteMessage("Test Leet Code 1461");
    LeetCodeBit leetCode;
    string s = "00110110";
    int k = 2;
    bool result = leetCode.hasAllCodes(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    s = "00110";
    k = 2;
    result = leetCode.hasAllCodes(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    s = "0110";
    k = 1;
    result = leetCode.hasAllCodes(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    s = "0110";
    k = 2;
    result = leetCode.hasAllCodes(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    s = "0000000001011100";
    k = 4;
    result = leetCode.hasAllCodes(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1486(void)
{
    Logger::WriteMessage("Test Leet Code 1486");
    LeetCodeBit leetCode;
    int n = 5;
    int start = 0;
    int result = leetCode.xorOperation(n, start);
    Logger::WriteMessage("n = " + to_string(n) + "; start = " + to_string(start) + "; result = " + to_string(result));

    n = 4;
    start = 3;
    result = leetCode.xorOperation(n, start);
    Logger::WriteMessage("n = " + to_string(n) + "; start = " + to_string(start) + "; result = " + to_string(result));

    n = 1;
    start = 7;
    result = leetCode.xorOperation(n, start);
    Logger::WriteMessage("n = " + to_string(n) + "; start = " + to_string(start) + "; result = " + to_string(result));

    n = 10;
    start = 5;
    result = leetCode.xorOperation(n, start);
    Logger::WriteMessage("n = " + to_string(n) + "; start = " + to_string(start) + "; result = " + to_string(result));
}

void TestLeetCode1521(void)
{
    Logger::WriteMessage("Test Leet Code 1521");
    LeetCodeBit leetCode;
    vector<int> arr = { 9, 12, 3, 7, 15 };
    int target = 5;
    int result = leetCode.closestToTarget(arr, target);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    arr = { 1000000,1000000,1000000 };
    target = 1;
    result = leetCode.closestToTarget(arr, target);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    arr = { 1,2,4,8,16 };
    target = 0;
    result = leetCode.closestToTarget(arr, target);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode1529(void)
{
    Logger::WriteMessage("Test Leet Code 1529");
    LeetCodeBit leetCode;
    string target = "10111";
    int result = leetCode.minFlips(target);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    target = "101";
    result = leetCode.minFlips(target);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    target = "00000";
    result = leetCode.minFlips(target);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    target = "001011101";
    result = leetCode.minFlips(target);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));
}

void TestLeetCode1545(void)
{
    Logger::WriteMessage("Test Leet Code 1545");
    LeetCodeBit leetCode;
    int n = 3; 
    int k = 1;
    char result = leetCode.findKthBit(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + string(1, result));

    n = 4;
    k = 12;
    result = leetCode.findKthBit(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + string(1, result));

    n = 1;
    k = 1;
    result = leetCode.findKthBit(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + string(1, result));

    n = 2;
    k = 3;
    result = leetCode.findKthBit(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + string(1, result));
}

void TestLeetCode1707(void)
{
    Logger::WriteMessage("Test Leet Code 1707");
    LeetCodeBit leetCode;
    vector<int> nums = { 0, 1, 2, 3, 4 };
    vector<vector<int>> queries = { {3, 1},{1, 3},{5, 6} };
    vector<int> result = leetCode.maximizeXor(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    nums = { 5,2,4,6,6,3 };
    queries = { {12, 4},{8, 1},{6, 3} };
    result = leetCode.maximizeXor(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    nums = { 818702963, 153655392, 4096, 917434814, 4096 };
    queries = 
    { 
        {11886620, 881210474}, { 811373, 1000000000 }, 
        { 20352316, 1000000000 }, { 443746890, 860009574 }, 
        { 872954994, 1000000000 } 
    }
    ;
    result = leetCode.maximizeXor(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1734(void)
{
    Logger::WriteMessage("Test Leet Code 1734");
    LeetCodeBit leetCode;
    vector<int> encoded = { 3, 1 };
    vector<int> result = leetCode.decode(encoded);
    Logger::WriteMessage(encoded);
    Logger::WriteMessage(result);

    encoded = { 6,5,4,6 };
    result = leetCode.decode(encoded);
    Logger::WriteMessage(encoded);
    Logger::WriteMessage(result);
}

void TestLeetCode1803(void)
{
    Logger::WriteMessage("Test Leet Code 1803");
    LeetCodeBit leetCode;
    vector<int> nums = { 1, 4, 2, 7 };
    int low = 2;
    int high = 6;
    int result = leetCode.countPairs(nums, low, high);
    result = leetCode.countPairs2(nums, low, high);
    result = leetCode.countPairs3(nums, low, high);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high) + "; result = " + to_string(result));

    nums = { 9,8,4,2,1 };
    low = 5;
    high = 14;
    result = leetCode.countPairs(nums, low, high);
    result = leetCode.countPairs2(nums, low, high);
    result = leetCode.countPairs3(nums, low, high);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high) + "; result = " + to_string(result));

    nums = { 3856, 3174, 2182, 7497, 6155, 4589, 3581, 4548, 3982, 2508 };
    low = 6903;
    high = 6946;
    result = leetCode.countPairs(nums, low, high);
    result = leetCode.countPairs2(nums, low, high);
    result = leetCode.countPairs3(nums, low, high);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high) + "; result = " + to_string(result));        
}

void TestLeetCode1829(void)
{
    Logger::WriteMessage("Test Leet Code 1829");
    LeetCodeBit leetCode;
    vector<int> nums = { 0,1,1,3 };
    int maximumBit = 2;
    vector<int> result = leetCode.getMaximumXor(nums, maximumBit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("maximumBit = " + to_string(maximumBit));
    Logger::WriteMessage(result);

    nums = { 2,3,4,7 };
    maximumBit = 3;
    result = leetCode.getMaximumXor(nums, maximumBit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("maximumBit = " + to_string(maximumBit));
    Logger::WriteMessage(result);
}

void TestLeetCode1835(void)
{
    Logger::WriteMessage("Test Leet Code 1835");
    LeetCodeBit leetCode;
    vector<int> arr1 = { 1, 2, 3 };
    vector<int> arr2 = { 6, 5 };
    int result = leetCode.getXORSum(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("result = " + to_string(result));

    arr1 = { 12 };
    arr2 = { 4 };
    result = leetCode.getXORSum(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1863(void)
{
    Logger::WriteMessage("Test Leet Code 1863");
    LeetCodeBit leetCode;
    vector<int> nums = { 1, 3 };
    int result = leetCode.subsetXORSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5,1,6 };
    result = leetCode.subsetXORSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3, 4, 5, 6, 7, 8 };
    result = leetCode.subsetXORSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1938(void)
{
    Logger::WriteMessage("Test Leet Code 1938");
    LeetCodeBit leetCode;
    vector<int> parents = { -1, 0, 1, 1 };
    vector<vector<int>> queries = { {0, 2},{3, 2},{2, 5} };
    vector<int> result = leetCode.maxGeneticDifference(parents, queries);
    Logger::WriteMessage(parents);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    parents = { 3,7,-1,2,0,7,0,2 };
    queries = { {4, 6},{1, 15},{0, 5} };
    result = leetCode.maxGeneticDifference(parents, queries);
    Logger::WriteMessage(parents);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1980(void)
{
    Logger::WriteMessage("Test Leet Code 1980");
    LeetCodeBit leetCode;
    vector<string> nums = { "01", "10" };
    string result = leetCode.findDifferentBinaryString(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + result);

    nums = { "00","01" };
    result = leetCode.findDifferentBinaryString(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + result);

    nums = { "111","011","001" };
    result = leetCode.findDifferentBinaryString(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode2220(void)
{
    Logger::WriteMessage("Test Leet Code 2220");
    LeetCodeBit leetCode;
    int start = 10;
    int goal = 7;
    int result = leetCode.minBitFlips(start, goal);
    Logger::WriteMessage("start = " + to_string(start) + "; goal =" + to_string(goal));
    Logger::WriteMessage("result = " + to_string(result));

    start = 3;
    goal = 4;
    result = leetCode.minBitFlips(start, goal);
    Logger::WriteMessage("start = " + to_string(start) + "; goal =" + to_string(goal));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2275(void)
{
    Logger::WriteMessage("Test Leet Code 2275");
    LeetCodeBit leetCode;
    vector<int> candidates = { 16, 17, 71, 62, 12, 24, 14 };
    int result = leetCode.largestCombination(candidates);
    Logger::WriteMessage(candidates);
    Logger::WriteMessage("result = " + to_string(result));

    candidates = { 8,8 };
    result = leetCode.largestCombination(candidates);
    Logger::WriteMessage(candidates);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2317(void)
{
    Logger::WriteMessage("Test Leet Code 2317");
    LeetCodeBit leetCode;
    vector<int> nums = { 3,2,4,6 };
    int result = leetCode.maximumXOR(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,9,2 };
    result = leetCode.maximumXOR(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2354(void)
{
    Logger::WriteMessage("Test Leet Code 2354");
    LeetCodeBit leetCode;
    vector<int> nums = { 1, 2, 3, 1 };
    int k = 3;
    long long result = leetCode.countExcellentPairs(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 5,1,1 };
    k = 10;
    result = leetCode.countExcellentPairs(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2425(void)
{
    Logger::WriteMessage("Test Leet Code 2425");
    LeetCodeBit leetCode;
    vector<int> nums1 = { 2, 1, 3 };
    vector<int> nums2 = { 10, 2, 5, 0 };
    int result = leetCode.xorAllNums(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1,2 };
    nums2 = { 3,4 };
    result = leetCode.xorAllNums(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2429(void)
{
    Logger::WriteMessage("Test Leet Code 2429");
    LeetCodeBit leetCode;
    int num1 = 3, num2 = 5;
    int result = leetCode.minimizeXor(num1, num2);
    Logger::WriteMessage("num1 = " + to_string(num1) + "; num2 = " + to_string(num2) + 
        "; result = " + to_string(result));

    num1 = 1, num2 = 12;
    result = leetCode.minimizeXor(num1, num2);
    Logger::WriteMessage("num1 = " + to_string(num1) + "; num2 = " + to_string(num2) +
        "; result = " + to_string(result));
}

void TestLeetCode2433(void)
{
    Logger::WriteMessage("Test Leet Code 2433");
    LeetCodeBit leetCode;
    vector<int> pref = { 5, 2, 0, 3, 1 };
    vector<int> result = leetCode.findArray(pref);
    Logger::WriteMessage(pref);
    Logger::WriteMessage(result);

    pref = { 13 };
    result = leetCode.findArray(pref);
    Logger::WriteMessage(pref);
    Logger::WriteMessage(result);
}

void TestLeetCode2479(void)
{
    Logger::WriteMessage("Test Leet Code 2479");
    LeetCodeBit leetCode;
    int n = 6;
    vector<vector<int>> edges =
    {
        {0, 1},{0, 2},{1, 3},{1, 4},{2, 5}
    };
    vector<int> values = { 2, 8, 3, 6, 2, 5 };
    long long result = leetCode.maxXor(n, edges, values);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(values);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    edges =
    {
        {0,1},{1,2}
    };
    values = { 4, 6, 1 };
    result = leetCode.maxXor(n, edges, values);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(values);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2505(void)
{
    Logger::WriteMessage("Test Leet Code 2505");
    LeetCodeBit leetCode;
    vector<int> nums = { 2, 1, 0, 3 };
    long long result = leetCode.subsequenceSumOr(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0,0,0 };
    result = leetCode.subsequenceSumOr(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2527(void)
{
    Logger::WriteMessage("Test Leet Code 2527");
    LeetCodeBit leetCode;
    vector<int> nums = { 1, 4 };
    int result = leetCode.xorBeauty(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 15,45,20,2,34,35,5,44,32,30 };
    result = leetCode.xorBeauty(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2546(void)
{
    Logger::WriteMessage("Test Leet Code 2546");
    LeetCodeBit leetCode;
    string s = "1010", target = "0110";
    bool result = leetCode.makeStringsEqual(s, target);
    Logger::WriteMessage("s = "+ s + "; target =" + target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    s = "11", target = "00";
    result = leetCode.makeStringsEqual(s, target);
    Logger::WriteMessage("s = " + s + "; target =" + target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2564(void)
{
    Logger::WriteMessage("Test Leet Code 2564");
    LeetCodeBit leetCode;
    string s = "101101";
    vector<vector<int>> queries = { {0, 5},{1, 2} };
    vector<vector<int>> result = leetCode.substringXorQueries(s, queries);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    s = "0101";
    queries = { {12, 8} };
    result = leetCode.substringXorQueries(s, queries);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    s = "1"; 
    queries = { {4, 5} };
    result = leetCode.substringXorQueries(s, queries);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode2568(void)
{
    Logger::WriteMessage("Test Leet Code 2568");
    LeetCodeBit leetCode;
    vector<int> nums = { 2, 1 };
    int result = leetCode.minImpossibleOR(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5, 3, 2 };
    result = leetCode.minImpossibleOR(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2571(void)
{
    Logger::WriteMessage("Test Leet Code 2571");
    LeetCodeBit leetCode;
    int n = 39;
    int result = leetCode.minOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 54;
    result = leetCode.minOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2569(void)
{
    Logger::WriteMessage("Test Leet Code 2569");
    LeetCodeBit leetCode;
    vector<int> nums1 = { 1, 0, 1 };
    vector<int> nums2 = { 0, 0, 0 };
    vector<vector<int>> queries = { {1, 1, 1},{2, 1, 0},{3, 0, 0} };
    vector<long long> result = leetCode.handleQuery(nums1, nums2, queries);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    nums1 = { 1 };
    nums2 = { 5 };
    queries = { {2, 0, 0},{3, 0, 0} };
    result = leetCode.handleQuery(nums1, nums2, queries);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode2683(void)
{
    Logger::WriteMessage("Test Leet Code 2683");
    LeetCodeBit leetCode;
    vector<int> derived = { 1, 1, 0 };
    bool result = leetCode.doesValidArrayExist(derived);
    Logger::WriteMessage(derived);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    derived = { 1, 1 };
    result = leetCode.doesValidArrayExist(derived);
    Logger::WriteMessage(derived);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    derived = { 1, 0 };
    result = leetCode.doesValidArrayExist(derived);
    Logger::WriteMessage(derived);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2680(void)
{
    Logger::WriteMessage("Test Leet Code 2680");
    LeetCodeBit leetCode;
    vector<int> nums = { 12, 9 };
    int k = 1;
    long long result = leetCode.maximumOr(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 8,1,2 };
    k = 2;
    result = leetCode.maximumOr(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 84, 99999999, 99911223 };
    k = 1;
    result = leetCode.maximumOr(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCodeBit(void)
{
    TestLeetCode2680();
    TestLeetCode2683();
    TestLeetCode2569();
    TestLeetCode2571();
    TestLeetCode2568();
    TestLeetCode2564();
    TestLeetCode2546();
    TestLeetCode2527();
    TestLeetCode2505();
    TestLeetCode2479();
    TestLeetCode2433();
    TestLeetCode2429();
    TestLeetCode2425();
    TestLeetCode2354();
    TestLeetCode2317();
    TestLeetCode2275();
    TestLeetCode2220();
    TestLeetCode1980();
    TestLeetCode1938();
    TestLeetCode1863();
    TestLeetCode1835();
    TestLeetCode1829();
    TestLeetCode1803();
    TestLeetCode1734();
    TestLeetCode1707();
    TestLeetCode1545();
    TestLeetCode1529();
    TestLeetCode1521();
    TestLeetCode1486();
    TestLeetCode861();
    TestLeetCode1461();
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