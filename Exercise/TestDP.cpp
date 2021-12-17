#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeDP.h"
#include "TestDP.h"
void TestLeetCode5(void)
{
    Logger::WriteMessage("Test Leet Code 5");
    LeetCodeDP leetCode;

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

void TestLeetCode120(void)
{
    Logger::WriteMessage("Test Leet Code 120");
    LeetCodeDP leetCode;
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

void TestLeetCode494(void)
{
    Logger::WriteMessage("Test Leet Code 494");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 1, 1, 1, 1 };
    int S = 3;
    Logger::WriteMessage(nums);
    Logger::WriteMessage("S = " + to_string(S));
    int count = leetCode.findTargetSumWays(nums, S);
    Logger::WriteMessage("count = " + to_string(count));
}

void TestLeetCode121(void)
{
    Logger::WriteMessage("Test Leet Code 121");
    LeetCodeDP leetCode;
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

void TestLeetCode518(void)
{
    Logger::WriteMessage("Test Leet Code 518");
    LeetCodeDP leetCode;
    int amount = 5;
    vector<int> coins = { 1, 2, 5 };
    int result = leetCode.change(amount, coins);
    Logger::WriteMessage(coins);
    Logger::WriteMessage("amount = " + to_string(amount) + "; result = " + to_string(result));

    amount = 3;
    coins = { 2 };
    result = leetCode.change(amount, coins);
    Logger::WriteMessage(coins);
    Logger::WriteMessage("amount = " + to_string(amount) + "; result = " + to_string(result));

    amount = 10;
    coins = { 10 };
    result = leetCode.change(amount, coins);
    Logger::WriteMessage(coins);
    Logger::WriteMessage("amount = " + to_string(amount) + "; result = " + to_string(result));
}

void TestLeetCode879(void)
{
    Logger::WriteMessage("Test Leet Code 879");
    LeetCodeDP leetCode;
    vector<int> group = { 2, 2 };
    vector<int> profit = { 2, 3 };
    int G = 5;
    int P = 3;
    int result = leetCode.profitableSchemes(G, P, group, profit);
    Logger::WriteMessage(group);
    Logger::WriteMessage(profit);
    Logger::WriteMessage("G = " + to_string(G) + "; P = " + to_string(P) + "; result = " + to_string(result));

    group = { 2, 3, 5 };
    profit = { 6, 7, 8 };
    G = 10;
    P = 5;
    result = leetCode.profitableSchemes(G, P, group, profit);
    Logger::WriteMessage(group);
    Logger::WriteMessage(profit);
    Logger::WriteMessage("G = " + to_string(G) + "; P = " + to_string(P) + "; result = " + to_string(result));
}

void TestLeetCode1143(void)
{
    Logger::WriteMessage("Test Leet Code 1143");
    LeetCodeDP leetCode;
    string text1 = "abcde";
    string text2 = "ace";
    int result = leetCode.longestCommonSubsequence(text1, text2);
    Logger::WriteMessage("text1 =" + text1 + "; text2 = " + text2 + "; result = " + to_string(result));

    text1 = "abc";
    text2 = "abc";
    result = leetCode.longestCommonSubsequence(text1, text2);
    Logger::WriteMessage("text1 =" + text1 + "; text2 = " + text2 + "; result = " + to_string(result));

    text1 = "abc";
    text2 = "def";
    result = leetCode.longestCommonSubsequence(text1, text2);
    Logger::WriteMessage("text1 =" + text1 + "; text2 = " + text2 + "; result = " + to_string(result));
}

void TestLeetCode1147(void)
{
    Logger::WriteMessage("Test Leet Code 1147");
    LeetCodeDP leetCode;
    string text = "ghiabcdefhelloadamhelloabcdefghi";
    int result = leetCode.longestDecomposition(text);
    Logger::WriteMessage("text =" + text + "; result = " + to_string(result));

    text = "merchant";
    result = leetCode.longestDecomposition(text);
    Logger::WriteMessage("text =" + text + "; result = " + to_string(result));

    text = "antaprezatepzapreanta";
    result = leetCode.longestDecomposition(text);
    Logger::WriteMessage("text =" + text + "; result = " + to_string(result));

    text = "aaa";
    result = leetCode.longestDecomposition(text);
    Logger::WriteMessage("text =" + text + "; result = " + to_string(result));

    text = "nufbkflwjjlwjjnufbkf";
    result = leetCode.longestDecomposition(text);
    Logger::WriteMessage("text =" + text + "; result = " + to_string(result));
}

void TestLeetCode1155(void)
{
    Logger::WriteMessage("Test Leet Code 1155");
    LeetCodeDP leetCode;
    int d = 1;
    int f = 6;
    int target = 3;
    int result = leetCode.numRollsToTarget(d, f, target);
    Logger::WriteMessage("d = " + to_string(d) + "; f = " + to_string(f) +
        "; target = " + to_string(target) + "; result = " + to_string(result));

    d = 2;
    f = 6;
    target = 7;
    result = leetCode.numRollsToTarget(d, f, target);
    Logger::WriteMessage("d = " + to_string(d) + "; f = " + to_string(f) +
        "; target = " + to_string(target) + "; result = " + to_string(result));

    d = 2;
    f = 5;
    target = 10;
    result = leetCode.numRollsToTarget(d, f, target);
    Logger::WriteMessage("d = " + to_string(d) + "; f = " + to_string(f) +
        "; target = " + to_string(target) + "; result = " + to_string(result));

    d = 1;
    f = 2;
    target = 3;
    result = leetCode.numRollsToTarget(d, f, target);
    Logger::WriteMessage("d = " + to_string(d) + "; f = " + to_string(f) +
        "; target = " + to_string(target) + "; result = " + to_string(result));

    d = 30;
    f = 30;
    target = 500;
    result = leetCode.numRollsToTarget(d, f, target);
    Logger::WriteMessage("d = " + to_string(d) + "; f = " + to_string(f) +
        "; target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode9905(void)
{
    Logger::WriteMessage("Test Leet Code 9905");
    LeetCodeDP leetCode;
    vector<vector<int>> activities = { {0, 3, 1}, {0, 5, 5}, {5, 6, 1}, {6, 18, 2} };
    int result = leetCode.maxInterest(activities);
    Logger::WriteMessage(activities);
    Logger::WriteMessage("result = " + to_string(result));

    activities = 
    { 
        {8, 9, 5}, { 8, 12, 7 }, { 9, 12, 4 }, { 12, 14, 2 },  {13, 16, 3}, {14, 15, 4} 
    };
    result = leetCode.maxInterest(activities);
    Logger::WriteMessage(activities);
    Logger::WriteMessage("result = " + to_string(result));

    activities =
    {
        {8, 10, 3}, {9, 12, 2}, {12, 14, 1}
    };
    result = leetCode.maxInterest(activities);
    Logger::WriteMessage(activities);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode562(void)
{
    LeetCodeDP leetCode;
    vector<vector<int>> M = { { 0,1,1,0 }, { 0,1,1,0 }, { 0,0,0,1 } };
    int max_length = leetCode.longestLine(M);
    Logger::WriteMessage(M);
    Logger::WriteMessage("max_length = " + to_string(max_length));
}

void TestLeetCode213(void)
{
    Logger::WriteMessage("Test Leet Code 213");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    int result = leetCode.robII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,3,2 };
    result = leetCode.robII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,1 };
    result = leetCode.robII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1 };
    result = leetCode.robII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode118(void)
{
    Logger::WriteMessage("Test Leet Code 118");
    int n = 5;
    Logger::WriteMessage("Level  = " + to_string(n));
    LeetCodeDP leetCode;
    vector<vector<int>> result = leetCode.generatePascalTriangle(n);
    for (size_t i = 0; i < result.size(); i++)
    {
        Logger::WriteMessage(result[i]);
    }
}

void TestLeetCode119(void)
{
    Logger::WriteMessage("Test Leet Code 119");
    int n = 5;
    Logger::WriteMessage("Level  = " + to_string(n));
    LeetCodeDP leetCode;
    vector<int> result = leetCode.getPascalTriangleRow(n);
    Logger::WriteMessage(result);
}

void TestLeetCode322(void)
{
    Logger::WriteMessage("Test Leet Code 322");
    LeetCodeDP leetCode;
    vector<int> coins;
    int amount, num;
    coins = { 1, 2, 5 };
    amount = 11;
    Logger::WriteMessage("The conins are:");
    Logger::WriteMessage(coins);
    num = leetCode.coinChange(coins, amount);
    Logger::WriteMessage("The amount is " + to_string(amount) + ", we need " + to_string(num) + " coins.");
    coins = { 2, 5 };
    amount = 3;
    Logger::WriteMessage("The conins are:");
    Logger::WriteMessage(coins);
    num = leetCode.coinChange(coins, amount);
    Logger::WriteMessage("The amount is " + to_string(amount) + ", we need " + to_string(num) + " coins.");
}

void TestLeetCode91(void)
{
    Logger::WriteMessage("Test Leet Code 91");
    LeetCodeDP leetCode;
    string s = "12321";
    int result = leetCode.numDecodings(s);
    Logger::WriteMessage("s = " + s + "result = " + to_string(result));

    s = "12";
    result = leetCode.numDecodings(s);
    Logger::WriteMessage("s = " + s + "result = " + to_string(result));

    s = "226";
    result = leetCode.numDecodings(s);
    Logger::WriteMessage("s = " + s + "result = " + to_string(result));
}

void TestLeetCode576(void)
{
    LeetCodeDP leetCode;
    int m = 2, n = 2, N = 2, i = 0, j = 0;
    int paths = leetCode.findPaths(m, n, N, i, j);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; N = " + to_string(N) +
        "; i = " + to_string(i) + "; j = " + to_string(j) + "; result = " + to_string(paths));

    m = 1; n = 3; N = 3; i = 0; j = 1;
    paths = leetCode.findPaths(m, n, N, i, j);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; N = " + to_string(N) +
        "; i = " + to_string(i) + "; j = " + to_string(j) + "; result = " + to_string(paths));

    m = 8; n = 50; N = 23; i = 5; j = 26;
    paths = leetCode.findPaths(m, n, N, i, j);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; N = " + to_string(N) +
        "; i = " + to_string(i) + "; j = " + to_string(j) + "; result = " + to_string(paths));
}

void TestLeetCode45(void)
{
    Logger::WriteMessage("Test Leet Code 45");
    vector<int> nums = { 1, 1, 1, 0 };
    LeetCodeDP leetCode;
    Logger::WriteMessage(nums);
    int result = leetCode.jump(nums);
    Logger::WriteMessage("Jump to the end take " + to_string(result) + " steps");

    nums = { 2, 3, 1, 1, 4 };
    Logger::WriteMessage(nums);
    result = leetCode.jump(nums);
    Logger::WriteMessage("Jump to the end take " + to_string(result) + " steps");

    nums = { 3, 2, 1, 0, 4 };
    Logger::WriteMessage(nums);
    result = leetCode.jump(nums);
    Logger::WriteMessage("Jump to the end take " + to_string(result) + " steps");

    nums = { 0 };
    Logger::WriteMessage(nums);
    result = leetCode.jump(nums);
    Logger::WriteMessage("Jump to the end take " + to_string(result) + " steps");
}

void TestLeetCode403(void)
{
    Logger::WriteMessage("Test Leet Code 403");
    LeetCodeDP leetCode;

    vector<int> stones = { 0,1,3,5,6,8,12,17 };
    bool result = leetCode.canCross(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    stones = { 0,1,2,3,4,8,9,11 };
    result = leetCode.canCross(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode264(void)
{
    Logger::WriteMessage("Test Leet Code 264");
    LeetCodeDP leetCode;
    int n = 10;
    int result = leetCode.nthUglyNumber(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode313(void)
{
    Logger::WriteMessage("Test Leet Code 313");
    LeetCodeDP leetCode;
    vector<int> primes = { 2, 3, 5 };
    int n = 4;
    Logger::WriteMessage(primes);
    int result = leetCode.nthSuperUglyNumber(n, primes);
    Logger::WriteMessage("The " + to_string(n) + "th ugly number = " + to_string(result));

    primes = { 2, 7, 13, 19 };
    n = 12;
    Logger::WriteMessage(primes);
    result = leetCode.nthSuperUglyNumber(n, primes);
    Logger::WriteMessage("The " + to_string(n) + "th ugly number = " + to_string(result));
}

void TestLeetCode514(void)
{
    Logger::WriteMessage("Test Leet Code 514");
    LeetCodeDP leetCode;
    string ring = "godding";
    string key = "dd";
    int result = leetCode.findRotateSteps(ring, key);
    Logger::WriteMessage("ring = " + ring + "; key = " + key + "; result = " + to_string(result));
}

void TestLeetCode656(void)
{
    LeetCodeDP leetCode;
    vector<int> A = { 1,2,4,-1,2 };
    int B = 2;
    vector<int> result = leetCode.cheapestJump(A, B);

    Logger::WriteMessage(A);
    Logger::WriteMessage("B = " + to_string(B));
    Logger::WriteMessage(result);

    B = 1;
    result = leetCode.cheapestJump(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage("B = " + to_string(B));
    Logger::WriteMessage(result);

    A = { 0,0,0,0,0,0 };
    B = 3;
    result = leetCode.cheapestJump(A, B);

    Logger::WriteMessage(A);
    Logger::WriteMessage("B = " + to_string(B));
    Logger::WriteMessage(result);
}

void TestLeetCode629(void)
{
    LeetCodeDP leetCode;
    int n = 3, k = 0;
    int result = leetCode.kInversePairs(n, k);
    Logger::WriteMessage("n = " + to_string(n) + ";k = " + to_string(k) + ";result = " + to_string(result));

    n = 3, k = 10;
    result = leetCode.kInversePairs(n, k);
    Logger::WriteMessage("n = " + to_string(n) + ";k = " + to_string(k) + ";result = " + to_string(result));
}

void TestLeetCode920(void)
{
    Logger::WriteMessage("Test Leet Code 920");
    LeetCodeDP leetCode;
    int N = 3, L = 3, K = 1;
    int result = leetCode.numMusicPlaylists(N, L, K);
    Logger::WriteMessage("N = " + to_string(N) + "; L = " + to_string(L) + "; K = " + to_string(K) + "; result = " + to_string(result));

    N = 2, L = 3, K = 0;
    result = leetCode.numMusicPlaylists(N, L, K);
    Logger::WriteMessage("N = " + to_string(N) + "; L = " + to_string(L) + "; K = " + to_string(K) + "; result = " + to_string(result));

    N = 2, L = 3, K = 1;
    result = leetCode.numMusicPlaylists(N, L, K);
    Logger::WriteMessage("N = " + to_string(N) + "; L = " + to_string(L) + "; K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode923(void)
{
    Logger::WriteMessage("Test Leet Code 923");
    LeetCodeDP leetCode;
    vector<int> A = { 1,1,2,2,3,3,4,4,5,5 };
    int target = 8;
    int result = leetCode.threeSumMulti(A, target);
    Logger::WriteMessage(A);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    A = { 1,1,2,2,2,2 };
    target = 5;
    result = leetCode.threeSumMulti(A, target);
    Logger::WriteMessage(A);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode474(void)
{
    Logger::WriteMessage("Test Leet Code 474");
    LeetCodeDP leetCode;
    vector<string> strs = { "10", "0", "1" };
    int m = 1;
    int n = 1;
    int result = leetCode.findMaxOneZeroForm(strs, m, n);
    Logger::WriteMessage(strs);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));

    strs = { "10", "0001", "111001", "1", "0" };
    m = 5;
    n = 3;
    result = leetCode.findMaxOneZeroForm(strs, m, n);
    Logger::WriteMessage(strs);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode377(void)
{
    Logger::WriteMessage("Test Leet Code 377");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3 };
    int target = 4;
    Logger::WriteMessage(nums);
    int result = leetCode.combinationSum4(nums, target);
    Logger::WriteMessage("Target = " + to_string(target) + ", Result = " + to_string(result));
}

void TestLeetCode1216(void)
{
    Logger::WriteMessage("Test Leet Code 1216");
    LeetCodeDP leetCode;
    string s = "abctdeca";
    int k = 2;
    bool result = leetCode.isValidPalindrome(s, k);
    Logger::WriteMessage("s = " + s + "; k= " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1220(void)
{
    Logger::WriteMessage("Test Leet Code 1220");
    LeetCodeDP leetCode;
    int n = 2;
    int result = leetCode.countVowelPermutation(n);
    Logger::WriteMessage("n= " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1223(void)
{
    Logger::WriteMessage("Test Leet Code 1223");
    LeetCodeDP leetCode;
    int n = 2;
    vector<int> rollMax = { 1, 1, 2, 2, 2, 3 };
    int result = leetCode.dieSimulator(n, rollMax);
    Logger::WriteMessage(rollMax);
    Logger::WriteMessage("n= " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    rollMax = { 1,1,1,1,1,1 };
    result = leetCode.dieSimulator(n, rollMax);
    Logger::WriteMessage(rollMax);
    Logger::WriteMessage("n= " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    rollMax = { 1,1,1,2,2,3 };
    result = leetCode.dieSimulator(n, rollMax);
    Logger::WriteMessage(rollMax);
    Logger::WriteMessage("n= " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1230(void)
{
    Logger::WriteMessage("Test Leet Code 1230");
    LeetCodeDP leetCode;
    vector<double> prob = { 0.4 };
    int target = 1;
    double result = leetCode.probabilityOfHeads(prob, target);
    Logger::WriteMessage(prob);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    prob = { 0.5, 0.5, 0.5, 0.5, 0.5 };
    target = 0;
    result = leetCode.probabilityOfHeads(prob, target);
    Logger::WriteMessage(prob);
    Logger::WriteMessage("target = "+ to_string(target) + "; result = " + to_string(result));

    prob = { 0.1, 0.2, 0.3, 0.4, 0.5 };
    target = 3;
    result = leetCode.probabilityOfHeads(prob, target);
    Logger::WriteMessage(prob);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode1235(void)
{
    Logger::WriteMessage("Test Leet Code 1235");
    LeetCodeDP leetCode;
    vector<int> startTime = { 1, 2, 3, 3 }; 
    vector<int> endTime = { 3, 4, 5, 6 };
    vector<int> profit = { 50, 10, 40, 70 };
    int result = leetCode.jobScheduling(startTime, endTime, profit);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage(profit);
    Logger::WriteMessage("result = " + to_string(result));

    startTime = { 1,2,3,4,6 };
    endTime = { 3,5,10,6,9 };
    profit = { 20,20,100,70,60 };
    result = leetCode.jobScheduling(startTime, endTime, profit);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage(profit);
    Logger::WriteMessage("result = " + to_string(result));

    startTime = { 1,1,1 };
    endTime = { 2,3,4 };
    profit = { 5,6,4 };
    result = leetCode.jobScheduling(startTime, endTime, profit);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage(profit);
    Logger::WriteMessage("result = " + to_string(result));

    startTime = { 4, 2, 4, 8, 2 };
    endTime = { 5, 5, 5, 10, 8 };
    profit = { 1, 2, 8, 10, 4 };
    result = leetCode.jobScheduling(startTime, endTime, profit);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage(profit);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1239(void)
{
    Logger::WriteMessage("Test Leet Code 1239");
    LeetCodeDP leetCode;
    vector<string> arr = { "un", "iq", "ue" };
    int result = leetCode.maxLength(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { "cha","r","act","ers" };
    result = leetCode.maxLength(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { "abcdefghijklmnopqrstuvwxyz" };
    result = leetCode.maxLength(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1246(void)
{
    Logger::WriteMessage("Test Leet Code 1246");
    LeetCodeDP leetCode;
    vector<int> arr = { 1, 2 };
    int result = leetCode.minimumMoves(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,3,4,1,5 };
    result = leetCode.minimumMoves(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 17, 6, 5, 18, 17, 4, 18, 8, 16, 8, 12, 1, 5, 14, 14, 6, 17, 18, 2, 19, 11, 15, 8, 18, 7, 8, 20, 2, 10, 3, 18, 17, 18, 18, 8, 9, 20, 3, 16, 19, 6, 9, 8, 8, 16, 19, 13, 8, 5, 20 };
    result = leetCode.minimumMoves(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1255(void)
{
    Logger::WriteMessage("Test Leet Code 1255");
    LeetCodeDP leetCode;
    vector<string> words = { "dog", "cat", "dad", "good" };
    vector<char> letters = { 'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o' };
    vector<int> score = { 1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int result = leetCode.maxScoreWords(words, letters, score);
    Logger::WriteMessage(words);
    Logger::WriteMessage(letters);
    Logger::WriteMessage(score);
    Logger::WriteMessage("result = " + to_string(result));

    words = { "xxxz","ax","bx","cx" };
    letters = { 'z','a','b','c','x','x','x' };
    score = { 4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10 };
    result = leetCode.maxScoreWords(words, letters, score);
    Logger::WriteMessage(words);
    Logger::WriteMessage(letters);
    Logger::WriteMessage(score);
    Logger::WriteMessage("result = " + to_string(result));

    words = { "leetcode" };
    letters = { 'l', 'e', 't', 'c', 'o', 'd' };
    score = { 0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0 };
    result = leetCode.maxScoreWords(words, letters, score);
    Logger::WriteMessage(words);
    Logger::WriteMessage(letters);
    Logger::WriteMessage(score);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1259(void)
{
    Logger::WriteMessage("Test Leet Code 1259");
    LeetCodeDP leetCode;
    int num_people = 2;
    int result = leetCode.numberOfWays(num_people);
    Logger::WriteMessage("num_people = " + to_string(num_people) + "; result = " + to_string(result));

    num_people = 4;
    result = leetCode.numberOfWays(num_people);
    Logger::WriteMessage("num_people = " + to_string(num_people) + "; result = " + to_string(result));

    num_people = 6;
    result = leetCode.numberOfWays(num_people);
    Logger::WriteMessage("num_people = " + to_string(num_people) + "; result = " + to_string(result));

    num_people = 8;
    result = leetCode.numberOfWays(num_people);
    Logger::WriteMessage("num_people = " + to_string(num_people) + "; result = " + to_string(result));
}

void TestLeetCode1269(void)
{
    Logger::WriteMessage("Test Leet Code 1269");
    LeetCodeDP leetCode;
    int steps = 3;
    int arrLen = 2;
    int result = leetCode.numWays(steps, arrLen);
    Logger::WriteMessage("steps = " + to_string(steps) + "; arrLen = " + to_string(arrLen) + "; result = " + to_string(result));

    steps = 2;
    arrLen = 4;
    result = leetCode.numWays(steps, arrLen);
    Logger::WriteMessage("steps = " + to_string(steps) + "; arrLen = " + to_string(arrLen) + "; result = " + to_string(result));

    steps = 4;
    arrLen = 2;
    result = leetCode.numWays(steps, arrLen);
    Logger::WriteMessage("steps = " + to_string(steps) + "; arrLen = " + to_string(arrLen) + "; result = " + to_string(result));
}

void TestLeetCode1277(void)
{
    Logger::WriteMessage("Test Leet Code 1277");
    LeetCodeDP leetCode;
    vector<vector<int>> matrix =
    {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int result = leetCode.countSquares(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("result = " + to_string(result));

    matrix =
    {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    result = leetCode.countSquares(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1278(void)
{
    Logger::WriteMessage("Test Leet Code 1278");
    LeetCodeDP leetCode;
    string s = "abc"; 
    int k = 2;
    int result = leetCode.palindromePartition(s, k);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aabbc";
    k = 3;
    result = leetCode.palindromePartition(s, k);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "leetcode";
    k = 8;
    result = leetCode.palindromePartition(s, k);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1289(void)
{
    Logger::WriteMessage("Test Leet Code 1289");
    LeetCodeDP leetCode;
    vector<vector<int>> arr = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    int result = leetCode.minFallingPathSum(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { {1} };
    result = leetCode.minFallingPathSum(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1301(void)
{
    Logger::WriteMessage("Test Leet Code 1301");
    LeetCodeDP leetCode;
    vector<string> board = { "E23", "2X2", "12S" };
    vector<int> result = leetCode.pathsWithMaxScore(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage(result);

    board = { "E12","1X1","21S" };
    result = leetCode.pathsWithMaxScore(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage(result);

    board = { "E11","XXX","11S" };
    result = leetCode.pathsWithMaxScore(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage(result);
}

void TestLeetCode1312(void)
{
    Logger::WriteMessage("Test Leet Code 1312");
    LeetCodeDP leetCode;
    string s = "zzazz";
    int result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "mbadm";
    result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "leetcode";
    result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "g";
    result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "no";
    result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode10(void)
{
    LeetCodeDP leetCode;

    string str = "bbbba";
    string pat = ".*a*a";
    bool result = leetCode.isMatchRegularExpression(str, pat);
    Logger::WriteMessage("str =" + str + "; pat =" + pat + 
        "; result = " + (string)(result ? "true" : "false"));

    str = "aab";
    pat = "c*a*b";
    result = leetCode.isMatchRegularExpression(str, pat);
    Logger::WriteMessage("str =" + str + "; pat =" + pat +
        "; result = " + (string)(result ? "true" : "false"));

    str = "aaa";
    pat = "a*a";
    result = leetCode.isMatchRegularExpression(str, pat);
    Logger::WriteMessage("str =" + str + "; pat =" + pat +
        "; result = " + (string)(result ? "true" : "false"));

    str = "aaa";
    pat = "ab*a*c*a";
    result = leetCode.isMatchRegularExpression(str, pat);
    Logger::WriteMessage("str =" + str + "; pat =" + pat +
        "; result = " + (string)(result ? "true" : "false"));
    str = "ab";
    pat = ".*";
    result = leetCode.isMatchRegularExpression(str, pat);
    Logger::WriteMessage("str =" + str + "; pat =" + pat +
        "; result = " + (string)(result ? "true" : "false"));

    str = "ab";
    pat = ".*c";
    result = leetCode.isMatchRegularExpression(str, pat);
    Logger::WriteMessage("str =" + str + "; pat =" + pat +
        "; result = " + (string)(result ? "true" : "false"));

    str = "ab";
    pat = "c*..";
    result = leetCode.isMatchRegularExpression(str, pat);
    Logger::WriteMessage("str =" + str + "; pat =" + pat +
        "; result = " + (string)(result ? "true" : "false"));

    str = "ab";
    pat = "";
    result = leetCode.isMatchRegularExpression(str, pat);
    Logger::WriteMessage("str =" + str + "; pat =" + pat +
        "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode135(void)
{
    Logger::WriteMessage("Test Leet Code 135");
    LeetCodeDP leetCode;
    vector<int> ratings = { 1,2,3,4,4,5,6,4,3,2,1 };
    int result = leetCode.candy(ratings);
    Logger::WriteMessage(ratings);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode44(void)
{
    Logger::WriteMessage("Test Leet Code 59");
    LeetCodeDP leetCode;
    string s, p;
    bool result;
    s = "aa"; p = "a";
    result = leetCode.isWildcardMatch(s, p);
    Logger::WriteMessage("(" + s + "," + p + ")" + "-> " + (result ? "true" : "false"));

    s = "aa"; p = "aa";
    result = leetCode.isWildcardMatch(s, p);
    Logger::WriteMessage("(" + s + "," + p + ")" + "-> " + (result ? "true" : "false"));

    s = "aaa"; p = "aa";
    result = leetCode.isWildcardMatch(s, p);
    Logger::WriteMessage("(" + s + "," + p + ")" + "-> " + (result ? "true" : "false"));

    s = "aa"; p = "*";
    result = leetCode.isWildcardMatch(s, p);
    Logger::WriteMessage("(" + s + "," + p + ")" + "-> " + (result ? "true" : "false"));

    s = "aa"; p = "a*";
    result = leetCode.isWildcardMatch(s, p);
    Logger::WriteMessage("(" + s + "," + p + ")" + "-> " + (result ? "true" : "false"));

    s = "aa"; p = "?*";
    result = leetCode.isWildcardMatch(s, p);
    Logger::WriteMessage("(" + s + "," + p + ")" + "-> " + (result ? "true" : "false"));

    s = "aab"; p = "c*a*b";
    result = leetCode.isWildcardMatch(s, p);
    Logger::WriteMessage("(" + s + "," + p + ")" + "-> " + (result ? "true" : "false"));
}

void TestLeetCode72(void)
{
    Logger::WriteMessage("Test Leet Code 72");
    LeetCodeDP leetCode;
    string word1 = "abcde";
    string word2 = "abce";

    int distance = leetCode.minDistance(word1, word2);
    Logger::WriteMessage("The distance between " + word1 + " and " + word2 + " is " + to_string(distance));

    word1 = "bat";
    word2 = "bot";

    distance = leetCode.minDistance(word1, word2);
    Logger::WriteMessage("The distance between " + word1 + " and " + word2 + " is " + to_string(distance));
}

void TestLeetCode70(void)
{
    Logger::WriteMessage("Test Leet Code 70");
    int n = 5;
    LeetCodeDP leetCode;
    int distinct_steps = leetCode.climbStairs(n);
    Logger::WriteMessage("The distinct steps in " + to_string(5) + " steps stairs is " + to_string(distinct_steps));
}

void TestLeetCode115(void)
{
    Logger::WriteMessage("Test Leet Code 115");
    LeetCodeDP leetCode;
    int num_distinct;
    string s = "rabbbit", t = "rabbit";
    num_distinct = leetCode.numDistinct(s, t);
    Logger::WriteMessage("s = " + s + " t = " + t);
    Logger::WriteMessage("number of distinct sequence = " + to_string(num_distinct));
}

void TestLeetCode55(void)
{
    Logger::WriteMessage("Test Leet Code 55");
    vector<int> nums = { 1, 1, 1, 0 };
    LeetCodeDP leetCode;
    Logger::WriteMessage(nums);
    bool result = leetCode.canJump(nums);
    if (result)
    {
        Logger::WriteMessage("Can jump to the end");
    }
    else
    {
        Logger::WriteMessage("Cannot jump to the end");
    }

    nums = { 2, 3, 1, 1, 4 };
    Logger::WriteMessage(nums);
    result = leetCode.canJump(nums);
    if (result)
    {
        Logger::WriteMessage("Can jump to the end");
    }
    else
    {
        Logger::WriteMessage("Cannot jump to the end");
    }

    nums = { 3, 2, 1, 0, 4 };
    Logger::WriteMessage(nums);
    result = leetCode.canJump(nums);
    if (result)
    {
        Logger::WriteMessage("Can jump to the end");
    }
    else
    {
        Logger::WriteMessage("Cannot jump to the end");
    }

    nums = { 0 };
    Logger::WriteMessage(nums);
    result = leetCode.canJump(nums);
    if (result)
    {
        Logger::WriteMessage("Can jump to the end");
    }
    else
    {
        Logger::WriteMessage("Cannot jump to the end");
    }
}

void TestLeetCode62(void)
{
    Logger::WriteMessage("Test Leet Code 62");
    int m, n;
    m = 3; n = 7;
    LeetCodeDP leetCode;
    int uniquePaths = leetCode.uniquePaths(m, n);
    Logger::WriteMessage("Unique Paths(" + to_string(m) + "," + to_string(n) + ") = " + to_string(uniquePaths));
}

void TestLeetCode63(void)
{
    Logger::WriteMessage("Test Leet Code 63");
    LeetCodeDP leetCode;
    vector<vector<int>> obstacleGrid =
    {
        { 0,0,0 }, { 0,1,0 }, { 0,0,0 }
    };
    int uniquePaths = leetCode.uniquePathsWithObstacles(obstacleGrid);
    for (size_t i = 0; i < obstacleGrid.size(); i++)
    {
        Logger::WriteMessage(obstacleGrid[i]);
    }
    Logger::WriteMessage("Unique Paths =" + to_string(uniquePaths));
}

void TestLeetCode64(void)
{
    Logger::WriteMessage("Test Leet Code 64");
    LeetCodeDP leetCode;
    vector<vector<int>> grid = { {1,2,3}, {4,5,6} };
    for (size_t i = 0; i < grid.size(); i++)
    {
        Logger::WriteMessage(grid[i]);
    }
    int minSum = leetCode.minPathSum(grid);
    Logger::WriteMessage("The minimum path sum is " + to_string(minSum));
}

void TestLeetCode1139(void)
{
    Logger::WriteMessage("Test Leet Code 1139");
    LeetCodeDP leetCode;
    vector<vector<int>> grid = { {1, 1, 1},{1, 0, 1},{1, 1, 1} };
    int result = leetCode.largest1BorderedSquare(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 1, 0, 0} };
    result = leetCode.largest1BorderedSquare(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1320(void)
{
    Logger::WriteMessage("Test Leet Code 1320");
    LeetCodeDP leetCode;
    string word = "CAKE";
    int result = leetCode.minimumDistance(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "HAPPY";
    result = leetCode.minimumDistance(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "NEW";
    result = leetCode.minimumDistance(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "YEAR";
    result = leetCode.minimumDistance(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));
}

void TestLeetCode132(void)
{
    Logger::WriteMessage("Test Leet Code 132");
    LeetCodeDP leetCode;
    string s = "aab";
    Logger::WriteMessage(s);
    int minCut = leetCode.minCut(s);
    Logger::WriteMessage("Min Cut = " + to_string(minCut));
}

void TestLeetCode1130(void)
{
    Logger::WriteMessage("Test Leet Code 1130");
    LeetCodeDP leetCode;
    vector<int> arr = { 6,2,4 };
    Logger::WriteMessage(arr);
    int result = leetCode.mctFromLeafValues(arr);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.mctFromLeafValuesII(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 8,6,4,2,10 };
    Logger::WriteMessage(arr);
    result = leetCode.mctFromLeafValues(arr);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.mctFromLeafValuesII(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 2,3,4,5,1 };
    Logger::WriteMessage(arr);
    result = leetCode.mctFromLeafValues(arr);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.mctFromLeafValuesII(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,2,3,4,5 };
    Logger::WriteMessage(arr);
    result = leetCode.mctFromLeafValues(arr);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.mctFromLeafValuesII(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 5,4,3,2,1 };
    Logger::WriteMessage(arr);
    result = leetCode.mctFromLeafValues(arr);
    Logger::WriteMessage("result = " + to_string(result));
    result = leetCode.mctFromLeafValuesII(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1035(void)
{
    Logger::WriteMessage("Test Leet Code 1035");
    LeetCodeDP leetCode;
    vector<int> A = { 1, 4, 2 };
    vector<int> B = { 1, 2, 4 };
    int result = leetCode.maxUncrossedLines(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result " + to_string(result));

    A = { 2,5,1,2,5 };
    B = { 10,5,2,1,5,2 };
    result = leetCode.maxUncrossedLines(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result " + to_string(result));

    A = { 1,3,7,1,7,5 };
    B = { 1,9,2,5,1 };
    result = leetCode.maxUncrossedLines(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage("result " + to_string(result));
}


void TestLeetCode361(void)
{
    Logger::WriteMessage("Test Leet Code 361");
    LeetCodeDP leetCode;
    vector<vector<char>> grid = { {'0', 'E', '0', '0'}, {'E', '0', 'W', 'E' }, {'0', 'E', '0', '0' } };
    Logger::WriteMessage(grid);
    int max_enemies = leetCode.maxKilledEnemies(grid);
    Logger::WriteMessage("Kill max enemies = " + to_string(max_enemies));

    grid = { { '0' }, {'0'}, {'0'} };
    Logger::WriteMessage(grid);
    max_enemies = leetCode.maxKilledEnemies(grid);
    Logger::WriteMessage("Kill max enemies = " + to_string(max_enemies));
}

void TestLeetCode516(void)
{
    Logger::WriteMessage("Test Leet Code 516");
    LeetCodeDP leetCode;
    string s = "bbbab";
    int result = leetCode.longestPalindromeSubseq(s);
    Logger::WriteMessage("s = " + s + "; longest palindrome sub sequence = " + to_string(result));
    s = "cbbd";
    result = leetCode.longestPalindromeSubseq(s);
    Logger::WriteMessage("s = " + s + "; longest palindrome sub sequence = " + to_string(result));
}

void TestLeetCode312(void)
{
    Logger::WriteMessage("Test Leet Code 312");
    LeetCodeDP leetCode;
    vector<int> nums;
    int max_coins;
    nums = { 3, 1, 5, 8 };
    max_coins = leetCode.maxBurstBalloonCoins(nums);
    Logger::WriteMessage("Balloons:");
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Maximum Coins = " + to_string(max_coins));
}

void TestLeetCode486(void)
{
    Logger::WriteMessage("Test Leet Code 486");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 5, 2 };
    bool result = leetCode.predictTheWinner(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Play 1 " + (string)(result ? "can win" : "cannot win"));

    nums = { 1, 5, 233, 7 };
    result = leetCode.predictTheWinner(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Play 1 " + (string)(result ? "can win" : "cannot win"));
}

void TestLeetCode1335(void)
{
    Logger::WriteMessage("Test Leet Code 1335");
    LeetCodeDP leetCode;
    vector<int> jobDifficulty = { 6, 5, 4, 3, 2, 1 };
    int d = 2;
    int result = leetCode.minDifficulty(jobDifficulty, d);
    Logger::WriteMessage(jobDifficulty);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    jobDifficulty = { 9,9,9 };
    d = 4;
    result = leetCode.minDifficulty(jobDifficulty, d);
    Logger::WriteMessage(jobDifficulty);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    jobDifficulty = { 1,1,1 };
    d = 3;
    result = leetCode.minDifficulty(jobDifficulty, d);
    Logger::WriteMessage(jobDifficulty);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    jobDifficulty = { 7,1,7,1,7,1 };
    d = 3;
    result = leetCode.minDifficulty(jobDifficulty, d);
    Logger::WriteMessage(jobDifficulty);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    jobDifficulty = { 11,111,22,222,33,333,44,444 };
    d = 6;
    result = leetCode.minDifficulty(jobDifficulty, d);
    Logger::WriteMessage(jobDifficulty);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    jobDifficulty = { 186, 398, 479, 206, 885, 423, 805, 112, 925, 656, 16, 932, 740, 292, 671, 360 };
    d = 4;
    result = leetCode.minDifficulty(jobDifficulty, d);
    Logger::WriteMessage(jobDifficulty);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));
}

void TestLeetCode1388(void)
{
    Logger::WriteMessage("Test Leet Code 1388");
    LeetCodeDP leetCode;
    vector<int> slices = { 1, 2, 3, 4, 5, 6 };
    int result = leetCode.maxSizeSlices(slices);
    Logger::WriteMessage(slices);
    Logger::WriteMessage("result = " + to_string(result));

    slices = { 8,9,8,6,1,1 };
    result = leetCode.maxSizeSlices(slices);
    Logger::WriteMessage(slices);
    Logger::WriteMessage("result = " + to_string(result));

    slices = { 4,1,2,5,8,3,1,9,7 };
    result = leetCode.maxSizeSlices(slices);
    Logger::WriteMessage(slices);
    Logger::WriteMessage("result = " + to_string(result));

    slices = { 3,1,2 };
    result = leetCode.maxSizeSlices(slices);
    Logger::WriteMessage(slices);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1406(void)
{
    Logger::WriteMessage("Test Leet Code 1406");
    LeetCodeDP leetCode;
    vector<int> stoneValues = { 1,2,3,7 };
    string result = leetCode.stoneGameIII(stoneValues);
    Logger::WriteMessage(stoneValues);
    Logger::WriteMessage("result = " + result);

    stoneValues = { 1,2,3,-9 };
    result = leetCode.stoneGameIII(stoneValues);
    Logger::WriteMessage(stoneValues);
    Logger::WriteMessage("result = " + result);

    stoneValues = { 1,2,3,6 };
    result = leetCode.stoneGameIII(stoneValues);
    Logger::WriteMessage(stoneValues);
    Logger::WriteMessage("result = " + result);

    stoneValues = { 1,2,3,-1,-2,-3,7 };
    result = leetCode.stoneGameIII(stoneValues);
    Logger::WriteMessage(stoneValues);
    Logger::WriteMessage("result = " + result);

    stoneValues = { -1,-2,-3 };
    result = leetCode.stoneGameIII(stoneValues);
    Logger::WriteMessage(stoneValues);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode1411(void)
{
    Logger::WriteMessage("Test Leet Code 1411");
    LeetCodeDP leetCode;
    int n = 1;
    int result = leetCode.numOfWays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    result = leetCode.numOfWays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    result = leetCode.numOfWays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7;
    result = leetCode.numOfWays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 5000;
    result = leetCode.numOfWays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1416(void)
{
    Logger::WriteMessage("Test Leet Code 1416");
    LeetCodeDP leetCode;
    string s = "1000";
    int k = 10000;
    int result = leetCode.numberOfArrays(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "1000";
    k = 10;
    result = leetCode.numberOfArrays(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "1317";
    k = 2000;
    result = leetCode.numberOfArrays(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "2020";
    k = 30;
    result = leetCode.numberOfArrays(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "1234567890";
    k = 90;
    result = leetCode.numberOfArrays(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1420(void)
{
    Logger::WriteMessage("Test Leet Code 1420");
    LeetCodeDP leetCode;
    int n = 2;
    int m = 3;
    int k = 1;
    int result = leetCode.numOfArrays(n, m, k);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + 
        "; k = " + to_string(k)  + "; result = " + to_string(result));

    n = 5; 
    m = 2; 
    k = 3;
    result = leetCode.numOfArrays(n, m, k);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) +
        "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 9; 
    m = 1; 
    k = 1;
    result = leetCode.numOfArrays(n, m, k);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) +
        "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 50;
    m = 100;
    k = 25;
    result = leetCode.numOfArrays(n, m, k);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) +
        "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 37;
    m = 17;
    k = 7;
    result = leetCode.numOfArrays(n, m, k);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) +
        "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1434(void)
{
    Logger::WriteMessage("Test Leet Code 1434");
    LeetCodeDP leetCode;
    vector<vector<int>>hats = { {3, 4},{4, 5},{5} };
    int result = leetCode.numberWays(hats);
    Logger::WriteMessage(hats);
    Logger::WriteMessage("result = " + to_string(result));

    hats = { {3,5,1} ,{3,5} };
    result = leetCode.numberWays(hats);
    Logger::WriteMessage(hats);
    Logger::WriteMessage("result = " + to_string(result));

    hats = { {1,2,3,4} ,{1,2,3,4},{1,2,3,4},{1,2,3,4} };
    result = leetCode.numberWays(hats);
    Logger::WriteMessage(hats);
    Logger::WriteMessage("result = " + to_string(result));

    hats = { {1,2,3} ,{2,3,5,6}, {1,3,7,9}, {1,8,9}, {2,5,7} };
    result = leetCode.numberWays(hats);
    Logger::WriteMessage(hats);
    Logger::WriteMessage("result = " + to_string(result));

    hats = { {4, 15, 16, 26, 28}, {1, 2, 3, 4, 6, 7, 8, 10, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 25, 27, 28, 29, 30}, {1, 2, 3, 4, 5, 7, 9, 10, 11, 12, 14, 15, 17, 18, 19, 20, 21, 22, 23, 24, 25, 28, 29, 30}, {2, 3, 6, 7, 14, 16, 17, 18, 19, 20, 21, 24, 25, 27, 28, 29}, {1, 10}, {1, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 19, 20, 21, 22, 24, 25, 27, 28}, {2, 5, 10, 14, 16, 19, 21, 22, 23, 27, 30} };
    result = leetCode.numberWays(hats);
    Logger::WriteMessage(hats);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1444(void)
{
    Logger::WriteMessage("Test Leet Code 1444");
    LeetCodeDP leetCode;
    vector<string> pizza = { ".A..A", "A.A.." };
    int k = 5;
    int result = leetCode.ways(pizza, k);
    Logger::WriteMessage(pizza);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    pizza = { "A..","AA.","..." };
    k = 3;
    result = leetCode.ways(pizza, k);
    Logger::WriteMessage(pizza);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    pizza = { "A..","A..","..." };
    k = 1;
    result = leetCode.ways(pizza, k);
    Logger::WriteMessage(pizza);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    pizza = { "A..", "AAA", "..." };
    k = 3;
    result = leetCode.ways(pizza, k);
    Logger::WriteMessage(pizza);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1449(void)
{
    Logger::WriteMessage("Test Leet Code 1449");
    LeetCodeDP leetCode;

    vector<int> cost = {21, 25, 18, 23, 25, 23, 20, 18, 38};
    int target = 84;
    string result = leetCode.largestNumber(cost, target);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);

    cost = { 5, 6, 7, 3, 4, 6, 7, 4, 8 };
    target = 29;
    result = leetCode.largestNumber(cost, target);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);

    cost = { 4, 3, 2, 5, 6, 7, 2, 5, 5 };
    target = 9;
    result = leetCode.largestNumber(cost, target);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);

    cost = { 7,6,5,5,5,6,8,7,8 };
    target = 12;
    result = leetCode.largestNumber(cost, target);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);

    cost = { 2,4,6,2,4,6,4,4,4 };
    target = 5;
    result = leetCode.largestNumber(cost, target);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);

    cost = { 6,10,15,40,40,40,40,40,40 };
    target = 47;
    result = leetCode.largestNumber(cost, target);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);

    cost = { 1,2,3,4,5,6,7,8,9 };
    target = 5000;
    result = leetCode.largestNumber(cost, target);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);
}

void TestLeetCode1458(void)
{
    Logger::WriteMessage("Test Leet Code 1458");
    LeetCodeDP leetCode;

    vector<int> nums1 = { 2, 1, -2, 5 };
    vector<int> nums2 = { 3, 0, -6 };
    int result = leetCode.maxDotProduct(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 3,-2 };
    nums2 = { 2,-6,7 };
    result = leetCode.maxDotProduct(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { -1, -1 };
    nums2 = { 1, 1 };
    result = leetCode.maxDotProduct(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1463(void)
{
    Logger::WriteMessage("Test Leet Code 1463");
    LeetCodeDP leetCode;
    vector<vector<int>> grid = 
    { 
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1} 
    };
    int result = leetCode.cherryPickup(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = 
    {
        {1, 0, 0, 0, 0, 0, 1},
        {2, 0, 0, 0, 0, 3, 0},
        {2, 0, 9, 0, 0, 0, 0},
        {0, 3, 0, 5, 4, 0, 0},
        {1, 0, 2, 3, 0, 0, 6}
    };
    result = leetCode.cherryPickup(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1,0,0,3},
        {0,0,0,3},
        {0,0,3,3},
        {9,0,3,3}
    };
    result = leetCode.cherryPickup(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1,1},
        {1,1}
    };
    result = leetCode.cherryPickup(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1473(void)
{
    Logger::WriteMessage("Test Leet Code 1473");
    LeetCodeDP leetCode;
    vector<int> houses = { 0, 0, 0, 0, 0 };
    vector<vector<int>> cost = { {1, 10},{10, 1},{10, 1},{1, 10},{5, 1} };
    int m = 5;
    int n = 2;
    int target = 3;
    int result = leetCode.minCost(houses, cost, m, n, target);
    Logger::WriteMessage(houses);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) +
        "; target = " + to_string(target) + "; result = " + to_string(result));

    houses = { 0,2,1,2,0 };
    cost = { {1, 10},{10, 1},{10, 1},{1, 10},{5, 1} };
    m = 5;
    n = 2;
    target = 3;
    result = leetCode.minCost(houses, cost, m, n, target);
    Logger::WriteMessage(houses);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) +
        "; target = " + to_string(target) + "; result = " + to_string(result));

    houses = { 0,0,0,0,0 };
    cost = { {1, 10},{10, 1},{1, 10},{10, 1},{1, 10} };
    m = 5;
    n = 2;
    target = 5;
    result = leetCode.minCost(houses, cost, m, n, target);
    Logger::WriteMessage(houses);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) +
        "; target = " + to_string(target) + "; result = " + to_string(result));

    houses = { 3,1,2,3 };
    cost = { {1, 1, 1},{1, 1, 1},{1, 1, 1},{1, 1, 1} };
    m = 4;
    n = 3;
    target = 3;
    result = leetCode.minCost(houses, cost, m, n, target);
    Logger::WriteMessage(houses);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) +
        "; target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode1478(void)
{
    Logger::WriteMessage("Test Leet Code 1478");
    LeetCodeDP leetCode;
    vector<int> houses = { 1, 4, 8, 10, 20 };
    int k = 3;
    int result = leetCode.minDistance(houses, k);
    Logger::WriteMessage(houses);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    houses = { 2,3,5,12,18 };
    k = 5;
    result = leetCode.minDistance(houses, k);
    Logger::WriteMessage(houses);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    houses = { 7,4,6,1 };
    k = 1;
    result = leetCode.minDistance(houses, k);
    Logger::WriteMessage(houses);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    houses = { 3,6,14,10 };
    k = 4;
    result = leetCode.minDistance(houses, k);
    Logger::WriteMessage(houses);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1510(void)
{
    Logger::WriteMessage("Test Leet Code 1510");
    LeetCodeDP leetCode;
    int n = 1;
    bool result = leetCode.winnerSquareGame(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));

    n = 2;
    result = leetCode.winnerSquareGame(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));

    n = 4;
    result = leetCode.winnerSquareGame(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));

    n = 7;
    result = leetCode.winnerSquareGame(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));

    n = 17;
    result = leetCode.winnerSquareGame(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));
}


void TestLeetCode309(void)
{
    Logger::WriteMessage("Test Leet Code 351");
    LeetCodeDP leetCode;
    vector<int> prices = { 1, 2, 3, 0, 2 };
    int max_profit = leetCode.maxProfit(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("max profit = " + to_string(max_profit));
}

void TestLeetCode96(void)
{
    Logger::WriteMessage("Test Leet Code 96");
    LeetCodeDP leetCode;
    int n;
    int result;
    n = 3;
    result = leetCode.numTrees(n);
    Logger::WriteMessage("n = " + to_string(n) + " , " + "number of trees = " + to_string(result));
}

void TestLeetCode198(void)
{
    Logger::WriteMessage("Test Leet Code 198");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    Logger::WriteMessage(nums);
    int amount = leetCode.rob(nums);
    Logger::WriteMessage("The maximum amount the robber can get is " + to_string(amount));
}



void TestLeetCode279(void)
{
    Logger::WriteMessage("Test Leet Code 279");
    LeetCodeDP leetCode;
    int n = 12;
    int result = leetCode.numSquares(n);
    Logger::WriteMessage("n = " + to_string(n) + " ; number of sqaures = " + to_string(result));

    n = 100;
    result = leetCode.numSquares(n);
    Logger::WriteMessage("n = " + to_string(n) + " ; number of sqaures = " + to_string(result));
}

void TestLeetCode256(void)
{
    Logger::WriteMessage("Test Leet Code 256");
    LeetCodeDP leetCode;
    vector<vector<int>> costs = { {1,2,3}, {4, 1, 2} , {7, 9, 2} };
    Logger::WriteMessage(costs);
    int min_cost = leetCode.minCost(costs);
    Logger::WriteMessage("Minimum Cost = " + to_string(min_cost));
}

void TestLeetCode276(void)
{
    Logger::WriteMessage("Test Leet Code 276");
    LeetCodeDP leetCode;
    int n = 3;
    int k = 3;
    int numWays = leetCode.numWaysPaintFence(n, k);;
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; numWays = " + to_string(numWays));
}

void TestLeetCode265(void)
{
    Logger::WriteMessage("Test Leet Code 265");
    LeetCodeDP leetCode;
    vector<vector<int>> costs = { { 8 } };
    Logger::WriteMessage(costs);
    int min_cost = leetCode.minCostII(costs);
    Logger::WriteMessage("Minimum Cost = " + to_string(min_cost));

    costs = { { 1,2,3 },{ 4, 1, 2 } ,{ 7, 9, 2 } };
    Logger::WriteMessage(costs);
    min_cost = leetCode.minCostII(costs);
    Logger::WriteMessage("Minimum Cost = " + to_string(min_cost));
}

void TestLeetCode1546(void)
{
    Logger::WriteMessage("Test Leet Code 1546");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 1, 1, 1, 1 };
    int target = 2;
    int result = leetCode.maxNonOverlapping(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { -1,3,5,1,4,2,-9 };
    target = 6;
    result = leetCode.maxNonOverlapping(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { -2,6,6,3,5,4,1,2,8 };
    target = 10;
    result = leetCode.maxNonOverlapping(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { 0,0,0 };
    target = 0;
    result = leetCode.maxNonOverlapping(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode1547(void)
{
    Logger::WriteMessage("Test Leet Code 1547");
    LeetCodeDP leetCode;
    int n = 7;
    vector<int> cuts = { 1, 3, 4, 5 };
    int result = leetCode.minCost(n, cuts);
    Logger::WriteMessage(cuts);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 9;
    cuts = { 5,6,1,4,2 };
    result = leetCode.minCost(n, cuts);
    Logger::WriteMessage(cuts);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1553(void)
{
    Logger::WriteMessage("Test Leet Code 1553");
    LeetCodeDP leetCode;
    int n = 123;
    int result = leetCode.minDays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 6;
    result = leetCode.minDays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 1;
    result = leetCode.minDays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 56;
    result = leetCode.minDays(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1563(void)
{
    Logger::WriteMessage("Test Leet Code 1563");
    LeetCodeDP leetCode;
    vector<int> stoneValue = { 6, 2, 3, 4, 5, 5 };
    int result = leetCode.stoneGameV(stoneValue);
    Logger::WriteMessage(stoneValue);
    Logger::WriteMessage("result = " + to_string(result));

    stoneValue = { 7,7,7,7,7,7,7 };
    result = leetCode.stoneGameV(stoneValue);
    Logger::WriteMessage(stoneValue);
    Logger::WriteMessage("result = " + to_string(result));

    stoneValue = { 4 };
    result = leetCode.stoneGameV(stoneValue);
    Logger::WriteMessage(stoneValue);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1569(void)
{
    Logger::WriteMessage("Test Leet Code 1569");
    LeetCodeDP leetCode;
    vector<int> nums = { 2, 1, 3 };
    int result = leetCode.numOfWays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,4,5,1,2 };
    result = leetCode.numOfWays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3 };
    result = leetCode.numOfWays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,1,2,5,4,6 };
    result = leetCode.numOfWays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 9,4,2,1,3,6,5,7,8,14,11,10,12,13,16,15,17,18 };
    result = leetCode.numOfWays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1594(void)
{
    Logger::WriteMessage("Test Leet Code 1594");
    LeetCodeDP leetCode;
    vector<vector<int>> grid =
    {
        {-1,-2,-3},
        {-2,-3,-3},
        {-3,-3,-2}
    };
    int result = leetCode.maxProductPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1,-2,1},
        {1,-2,1},
        {3,-4,1}
    };
    result = leetCode.maxProductPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1, 3},
        {0,-4}
    };
    result = leetCode.maxProductPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));


    grid =
    {
        {1, 4, 4,0},
        {-2, 0,0,1},
        {1,-1,1,1}
    };
    result = leetCode.maxProductPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode1621(void)
{
    Logger::WriteMessage("Test Leet Code 1621");
    LeetCodeDP leetCode;
    int n = 4;
    int k = 2;
    int result = leetCode.numberOfSets(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = 2" + to_string(k)+ "; result = " + to_string(result));

    n = 3;
    k = 1;
    result = leetCode.numberOfSets(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = 2" + to_string(k) + "; result = " + to_string(result));

    n = 30;
    k = 7;
    result = leetCode.numberOfSets(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = 2" + to_string(k) + "; result = " + to_string(result));

    n = 5;
    k = 3;
    result = leetCode.numberOfSets(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = 2" + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1639(void)
{
    Logger::WriteMessage("Test Leet Code 1639");
    LeetCodeDP leetCode;
    vector<string> words = { "acca", "bbbb", "caca" };
    string target = "aba";
    int result = leetCode.numWays(words, target);
    Logger::WriteMessage(words);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    words = { "abba", "baab" };
    target = "aba";
    result = leetCode.numWays(words, target);
    Logger::WriteMessage(words);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    words = { "abcd" };
    target = "abcd";
    result = leetCode.numWays(words, target);
    Logger::WriteMessage(words);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    words = { "abab","baba","abba","baab" };
    target = "abba";
    result = leetCode.numWays(words, target);
    Logger::WriteMessage(words);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));
}

void TestLeetCode1641(void)
{
    Logger::WriteMessage("Test Leet Code 1641");
    LeetCodeDP leetCode;
    int n = 1;
    int result = leetCode.countVowelStrings(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    result = leetCode.countVowelStrings(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 33;
    result = leetCode.countVowelStrings(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1653(void)
{
    Logger::WriteMessage("Test Leet Code 1653");
    LeetCodeDP leetCode;
    string s = "aababbab";
    int result = leetCode.minimumDeletions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "bbaaaaabb";
    result = leetCode.minimumDeletions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "bbabb";
    result = leetCode.minimumDeletions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1690(void)
{
    Logger::WriteMessage("Test Leet Code 1690");
    LeetCodeDP leetCode;
    vector<int> stones = { 5, 3, 1, 4, 2 };
    int result = leetCode.stoneGameVII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { 7,90,5,1,100,10,10,2 };
    result = leetCode.stoneGameVII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1687(void)
{
    Logger::WriteMessage("Test Leet Code 1687");
    LeetCodeDP leetCode;
    vector<vector<int>> boxes = { {1, 1},{1, 1},{1, 1}, {1, 1},{1, 1},{1, 1} };
    int portsCount = 2;
    int maxBoxes = 10;
    int maxWeight = 10;
    int result = leetCode.boxDelivering(boxes, portsCount, maxBoxes, maxWeight);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("portsCount = " + to_string(portsCount) + 
        "; maxBoxes = " + to_string(maxBoxes) + 
        "; maxWeight = " + to_string(maxWeight) + 
        "result = " + to_string(result));

    boxes = { {1, 2},{3, 3},{3, 1},{3, 1},{2, 4} };
    portsCount = 3;
    maxBoxes = 3;
    maxWeight = 6;
    result = leetCode.boxDelivering(boxes, portsCount, maxBoxes, maxWeight);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("portsCount = " + to_string(portsCount) +
        "; maxBoxes = " + to_string(maxBoxes) +
        "; maxWeight = " + to_string(maxWeight) +
        "result = " + to_string(result));

    boxes = { {1, 4},{1, 2},{2, 1},{2, 1},{3, 2},{3, 4} };
    portsCount = 3;
    maxBoxes = 6;
    maxWeight = 7;
    result = leetCode.boxDelivering(boxes, portsCount, maxBoxes, maxWeight);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("portsCount = " + to_string(portsCount) +
        "; maxBoxes = " + to_string(maxBoxes) +
        "; maxWeight = " + to_string(maxWeight) +
        "result = " + to_string(result));

    boxes = { {2, 4},{2, 5},{3, 1},{3, 2},{3, 7},{3, 1},{4, 4},{1, 3},{5, 2} };
    portsCount = 5;
    maxBoxes = 5;
    maxWeight = 7;
    result = leetCode.boxDelivering(boxes, portsCount, maxBoxes, maxWeight);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("portsCount = " + to_string(portsCount) +
        "; maxBoxes = " + to_string(maxBoxes) +
        "; maxWeight = " + to_string(maxWeight) +
        "result = " + to_string(result));
}

void TestLeetCode1105(void)
{
    Logger::WriteMessage("Test Leet Code 1105");
    LeetCodeDP leetCode;
    vector<vector<int>> books =
    {
        {1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}
    };
    int shelf_width = 4;
    int result = leetCode.minHeightShelves(books, shelf_width);
    Logger::WriteMessage(books);
    Logger::WriteMessage("shelf_width = " + to_string(shelf_width) + "; result = " + to_string(result));

    books =
    {
        {9,9},{5,4},{3,1},{1,5},{7,3}
    };
    shelf_width = 10;
    result = leetCode.minHeightShelves(books, shelf_width);
    Logger::WriteMessage(books);
    Logger::WriteMessage("shelf_width = " + to_string(shelf_width) + "; result = " + to_string(result));

    books =
    {
        {2, 7} ,{9, 1},{6, 1},{4, 2},{3, 3},{8, 6},{10, 3},{1, 10}
    };
    shelf_width = 10;
    result = leetCode.minHeightShelves(books, shelf_width);
    Logger::WriteMessage(books);
    Logger::WriteMessage("shelf_width = " + to_string(shelf_width) + "; result = " + to_string(result));
}

void TestLeetCode1692(void)
{
    Logger::WriteMessage("Test Leet Code 1692");
    LeetCodeDP leetCode;
    int n = 3;
    int k = 2;
    int result = leetCode.waysToDistribute(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 4;
    k = 2;
    result = leetCode.waysToDistribute(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 20;
    k = 5;
    result = leetCode.waysToDistribute(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1682(void)
{
    Logger::WriteMessage("Test Leet Code 1682");
    LeetCodeDP leetCode;
    string  s = "bbabab";
    int result = leetCode.longestPalindromeSubseqII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "dcbccacdb";
    result = leetCode.longestPalindromeSubseqII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}


void TestLeetCode1746(void)
{
    Logger::WriteMessage("Test Leet Code 1746");
    LeetCodeDP leetCode;
    vector<int> nums = { 2, -1, -4, -3 };
    int result = leetCode.maxSumAfterOperation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,-1,1,1,-1,-1,1 };
    result = leetCode.maxSumAfterOperation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1774(void)
{
    Logger::WriteMessage("Test Leet Code 1774");
    LeetCodeDP leetCode;
    vector<int> baseCosts = { 1, 7 };
    vector<int> toppingCosts = { 3, 4 };
    int target = 10;
    int result = leetCode.closestCost(baseCosts, toppingCosts, target);
    Logger::WriteMessage(baseCosts);
    Logger::WriteMessage(toppingCosts);
    Logger::WriteMessage("result = " + to_string(result));

    baseCosts = { 2, 3 };
    toppingCosts = { 4, 5, 100 };
    target = 18;
    result = leetCode.closestCost(baseCosts, toppingCosts, target);
    Logger::WriteMessage(baseCosts);
    Logger::WriteMessage(toppingCosts);
    Logger::WriteMessage("result = " + to_string(result));

    baseCosts = { 3, 10 };
    toppingCosts = { 2, 5 };
    target = 9;
    result = leetCode.closestCost(baseCosts, toppingCosts, target);
    Logger::WriteMessage(baseCosts);
    Logger::WriteMessage(toppingCosts);
    Logger::WriteMessage("result = " + to_string(result));

    baseCosts = { 10 };
    toppingCosts = { 1 };
    target = 1;
    result = leetCode.closestCost(baseCosts, toppingCosts, target);
    Logger::WriteMessage(baseCosts);
    Logger::WriteMessage(toppingCosts);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1787(void)
{
    Logger::WriteMessage("Test Leet Code 1787");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 0, 3, 0 };
    int k = 1;
    int result = leetCode.minChanges(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 3,4,5,2,1,7,3,4,7 };
    k = 3;
    result = leetCode.minChanges(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,4,1,2,5,1,2,6 };
    k = 3;
    result = leetCode.minChanges(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1745(void)
{
    Logger::WriteMessage("Test Leet Code 1745");
    LeetCodeDP leetCode;
    string s = "abcbdd";
    bool result = leetCode.checkPartitioning(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true":"false"));

    s = "bcbddxy";
    result = leetCode.checkPartitioning(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "aab";
    result = leetCode.checkPartitioning(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "abbab";
    result = leetCode.checkPartitioning(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "accab";
    result = leetCode.checkPartitioning(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "aaaaa";
    result = leetCode.checkPartitioning(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "plbqrqbhafkaktrbsaaxpxiobebmkkeivlformfspcdtygcmgpbrekkwpgvujyfpysjsqeclwkkmntaahxferzsyxbivyrohptketkabbmzhxdffvdjbbdvpmeygvygsiglucsavhjdoyosysqmiobvcbwatprfyjnxuuihissatgfjmnzwmbhdfwjyxdxelsxsutugmsthjsblgrjtxylzwlifzuhpfvssovovblhwngcimcoxgmiirecxsawfsahwxdkpdctgozzpfdvnbrpsdevqaaxnrczldpcodubfkoevcpbonckkgnjibzxmztoilwqanashooiytjljrwwznjtmkbyhukvcqhmnnibypxcqevoggsanfgybnxujpjsecynkoguinzypssnsnmbkurkncqhgqiuglqvtwidvbprhkgdvvxgulzlacjmqtbpapdrvanifjuautebqqpfxsetvciazpdrxbtgscvczfnydhpydcbbrmlhjszigimcjjevrxqduaawvoarusqhwsjtpvygdfxyhyytwjyqyezzsrdwwbcrytgiwqqomjsusmhzjfqnihccufgcohdlxcwtitxbevzfuhytrbtqfcpedmfvuhvxsrqqxkrmnnxmyuvkngm";
    result = leetCode.checkPartitioning(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1771(void)
{
    Logger::WriteMessage("Test Leet Code 1771");
    LeetCodeDP leetCode;
    string word1 = "cacb";
    string word2 = "cbba";
    int result = leetCode.longestPalindrome(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; result = " + to_string(result));

    word1 = "ab";
    word2 = "ab";
    result = leetCode.longestPalindrome(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; result = " + to_string(result));

    word1 = "aa";
    word2 = "bb";
    result = leetCode.longestPalindrome(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; result = " + to_string(result));

    word1 = "afaaadacb";
    word2 = "ca";
    result = leetCode.longestPalindrome(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; result = " + to_string(result));
}

void TestLeetCode1824(void)
{
    Logger::WriteMessage("Test Leet Code 1824");
    LeetCodeDP leetCode;
    vector<int> obstacles = { 0, 1, 2, 3, 0 };
    int result = leetCode.minSideJumps(obstacles);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage("result = " + to_string(result));

    obstacles = { 0,1,1,3,3,0 };
    result = leetCode.minSideJumps(obstacles);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage("result = " + to_string(result));

    obstacles = { 0,2,1,0,3,0 };
    result = leetCode.minSideJumps(obstacles);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode1872(void)
{
    Logger::WriteMessage("Test Leet Code 1872");
    LeetCodeDP leetCode;
    vector<int> stones = { -1, 2, -3, 4, -5 };
    int result = leetCode.stoneGameVIII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { 7,-6,5,10,5,-2,-6 };
    result = leetCode.stoneGameVIII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { -10,-12 };
    result = leetCode.stoneGameVIII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1883(void)
{
    Logger::WriteMessage("Test Leet Code 1883");
    LeetCodeDP leetCode;
    vector<int> dist = { 1, 3, 2 };
    int speed = 4;
    int hoursBefore = 2;
    int result = leetCode.minSkips(dist, speed, hoursBefore);
    Logger::WriteMessage("speed = " + to_string(speed) + 
        "; hoursBefore = " + to_string(hoursBefore) +  
        "; result = " + to_string(result));

    dist = { 7,3,5,5 };
    speed = 2;
    hoursBefore = 10;
    result = leetCode.minSkips(dist, speed, hoursBefore);
    Logger::WriteMessage("speed = " + to_string(speed) +
        "; hoursBefore = " + to_string(hoursBefore) +
        "; result = " + to_string(result));

    dist = { 7,3,5,5 };
    speed = 1;
    hoursBefore = 10;
    result = leetCode.minSkips(dist, speed, hoursBefore);
    Logger::WriteMessage("speed = " + to_string(speed) +
        "; hoursBefore = " + to_string(hoursBefore) +
        "; result = " + to_string(result));
}

void TestLeetCode1955(void)
{
    Logger::WriteMessage("Test Leet Code 1955");
    LeetCodeDP leetCode;
    vector<int> nums = { 0, 1, 2, 2 };
    int result = leetCode.countSpecialSubsequences(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,0,0 };
    result = leetCode.countSpecialSubsequences(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0,1,2,0,1,2 };
    result = leetCode.countSpecialSubsequences(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1911(void)
{
    Logger::WriteMessage("Test Leet Code 1911");
    LeetCodeDP leetCode;
    vector<int> nums = { 4,2,5,3 };
    long long result = leetCode.maxAlternatingSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5,6,7,8 };
    result = leetCode.maxAlternatingSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 6,2,1,2,4,5 };
    result = leetCode.maxAlternatingSum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1977(void)
{
    Logger::WriteMessage("Test Leet Code 1977");
    LeetCodeDP leetCode;
    string num = "506";
    int result = leetCode.numberOfCombinations(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));

    num = "5060";
    result = leetCode.numberOfCombinations(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));

    num = "327";
    result = leetCode.numberOfCombinations(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));

    num = "094";
    result = leetCode.numberOfCombinations(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));

    num = "0";
    result = leetCode.numberOfCombinations(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));

    num = "9999999999999";
    result = leetCode.numberOfCombinations(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));
}

void TestLeetCode1987(void)
{
    Logger::WriteMessage("Test Leet Code 1987");
    LeetCodeDP leetCode;
    string num = "001";
    int result = leetCode.numberOfUniqueGoodSubsequences(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));

    num = "11";
    result = leetCode.numberOfUniqueGoodSubsequences(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));

    num = "101";
    result = leetCode.numberOfUniqueGoodSubsequences(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));

    num = "1001";
    result = leetCode.numberOfUniqueGoodSubsequences(num);
    Logger::WriteMessage("num = " + num + "; result = " + to_string(result));
}

void TestLeetCode1997(void)
{
    Logger::WriteMessage("Test Leet Code 1997");
    LeetCodeDP leetCode;
    vector<int> nextVisit = { 0, 0 };
    int result = leetCode.firstDayBeenInAllRooms(nextVisit);
    Logger::WriteMessage(nextVisit);
    Logger::WriteMessage("result = " + to_string(result));

    nextVisit = { 0,0,2 };
    result = leetCode.firstDayBeenInAllRooms(nextVisit);
    Logger::WriteMessage(nextVisit);
    Logger::WriteMessage("result = " + to_string(result));

    nextVisit = { 0,1,2,0 };
    result = leetCode.firstDayBeenInAllRooms(nextVisit);
    Logger::WriteMessage(nextVisit);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1959(void)
{
    Logger::WriteMessage("Test Leet Code 1959");
    LeetCodeDP leetCode;
    vector<int> nums = { 10,20 };
    int k = 0;
    int result = leetCode.minSpaceWastedKResizing(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 10,20,30 };
    k = 1;
    result = leetCode.minSpaceWastedKResizing(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 10,20,15,30,20 };
    k = 2;
    result = leetCode.minSpaceWastedKResizing(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode122(void)
{
    Logger::WriteMessage("Test Leet Code 122");
    LeetCodeDP leetCode;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    int result = leetCode.maxProfitManyTxns(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 1, 2 };
    result = leetCode.maxProfitManyTxns(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 1, 2, 3, 4, 5 };
    result = leetCode.maxProfitManyTxns(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 7,6,4,3,1 };
    result = leetCode.maxProfitManyTxns(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode123(void)
{
    Logger::WriteMessage("Test Leet Code 123");
    LeetCodeDP leetCode;
    vector<int> prices = { 3,3,5,0,0,3,1,4 };
    int result = leetCode.maxProfitTwoTxns(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 1,2,3,4,5 };
    result = leetCode.maxProfitTwoTxns(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 7,6,4,3,1 };
    result = leetCode.maxProfitTwoTxns(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 1 };
    result = leetCode.maxProfitTwoTxns(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1751(void)
{
    Logger::WriteMessage("Test Leet Code 1751");
    LeetCodeDP leetCode;
    vector<vector<int>> events = { {1, 2, 4},{3, 4, 3},{2, 3, 1} };
    int k = 2;
    int result = leetCode.maxValue(events, k);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));

    events = { {1, 2, 4},{3, 4, 3},{2, 3, 10} };
    k = 2;
    result = leetCode.maxValue(events, k);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));

    events = { {1, 1, 1},{2, 2, 2},{3, 3, 3},{4, 4, 4} };
    k = 3;
    result = leetCode.maxValue(events, k);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2008(void)
{
    Logger::WriteMessage("Test Leet Code 2008");
    LeetCodeDP leetCode;
    vector<vector<int>> rides = { {2,5,4},{1,5,1} };
    int n = 5;
    long long result = leetCode.maxTaxiEarnings(n, rides);
    Logger::WriteMessage(rides);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    rides = { {1, 6, 1},{3, 10, 2},{10, 12, 3},{11, 12, 2},{12, 15, 2},{13, 18, 1} };
    n = 20;
    result = leetCode.maxTaxiEarnings(n, rides);
    Logger::WriteMessage(rides);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2054(void)
{
    Logger::WriteMessage("Test Leet Code 2054");
    LeetCodeDP leetCode;
    vector<vector<int>> events = { {1, 3, 2},{4, 5, 2},{2, 4, 3} };
    int result = leetCode.maxTwoEvents(events);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));

    events = { {1, 3, 2},{4, 5, 2},{1, 5, 5} };
    result = leetCode.maxTwoEvents(events);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));

    events = { {1, 5, 3},{1, 5, 1},{6, 6, 5} };
    result = leetCode.maxTwoEvents(events);
    Logger::WriteMessage(events);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2036(void)
{
    Logger::WriteMessage("Test Leet Code 2036");
    LeetCodeDP leetCode;
    vector<int> nums = { 3, -1, 1, 2 };
    long long result = leetCode.maximumAlternatingSubarraySum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,2,2,2 };
    result = leetCode.maximumAlternatingSubarraySum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1 };
    result = leetCode.maximumAlternatingSubarraySum(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode628(void)
{
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    Logger::WriteMessage(nums);
    int result = leetCode.maximumProduct(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -1, -2, -3, -4 };
    Logger::WriteMessage(nums);
    result = leetCode.maximumProduct(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1125(void)
{
    Logger::WriteMessage("Test Leet Code 1125");
    LeetCodeDP leetCode;
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

void TestLeetCode221(void)
{
    Logger::WriteMessage("Test Leet Code 221");
    LeetCodeDP leetCode;
    vector<vector<char>> matrix =
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

void TestLeetCode174(void)
{
    Logger::WriteMessage("Test Leet Code 174");
    LeetCodeDP leetCode;
    vector<vector<int>> dungeon;
    int min_hp;
    dungeon = { { -2,-3, 3 }, {-5, -10, 1}, {10, 30, -5} };
    for (size_t i = 0; i < dungeon.size(); i++)
    {
        Logger::WriteMessage(dungeon[i]);
    }
    min_hp = leetCode.calculateMinimumHP(dungeon);
    Logger::WriteMessage("Minimum HP = " + to_string(min_hp));
    dungeon = { { 1, -3, 3 },{ 0, -2, 0 },{ -3, -3, -3 } };
    for (size_t i = 0; i < dungeon.size(); i++)
    {
        Logger::WriteMessage(dungeon[i]);
    }
    min_hp = leetCode.calculateMinimumHP(dungeon);
    Logger::WriteMessage("Minimum HP = " + to_string(min_hp));
}

void TestLeetCodeDP(void)
{
    TestLeetCode174();
    TestLeetCode221();
    TestLeetCode1125();
    TestLeetCode628();
    TestLeetCode2036();
    TestLeetCode2054();
    TestLeetCode2008();
    TestLeetCode1751();
    TestLeetCode123();
    TestLeetCode122();
    TestLeetCode1682();
    TestLeetCode1959();
    TestLeetCode1997();
    TestLeetCode1987();
    TestLeetCode1977();
    TestLeetCode1911();
    TestLeetCode1955();
    TestLeetCode1883();
    TestLeetCode1872();
    TestLeetCode1751();
    TestLeetCode1824();
    TestLeetCode1771();
    TestLeetCode1745();
    TestLeetCode1787();
    TestLeetCode1774();
    TestLeetCode1746();
    TestLeetCode1692();
    TestLeetCode1105();
    TestLeetCode1687();
    TestLeetCode1690();
    TestLeetCode1653();
    TestLeetCode1641();
    TestLeetCode1639();
    TestLeetCode1621();
    TestLeetCode1594();
    TestLeetCode1569();
    TestLeetCode1563();
    TestLeetCode1553();
    TestLeetCode1547();
    TestLeetCode1546();
    TestLeetCode265();
    TestLeetCode276();
    TestLeetCode256();
    TestLeetCode279();
    TestLeetCode120();
    TestLeetCode198();
    TestLeetCode96();
    TestLeetCode309();
    TestLeetCode5();
    TestLeetCode121();
    TestLeetCode1510();
    TestLeetCode1478();
    TestLeetCode1473();
    TestLeetCode1463();
    TestLeetCode1458();
    TestLeetCode1449();
    TestLeetCode1444();
    TestLeetCode1434();
    TestLeetCode1420();
    TestLeetCode1416();
    TestLeetCode1411();
    TestLeetCode1406();
    TestLeetCode1388();
    TestLeetCode1335();
    TestLeetCode486();
    TestLeetCode312();
    TestLeetCode516();
    TestLeetCode361();
    TestLeetCode1035();
    TestLeetCode132();
    TestLeetCode1320();
    TestLeetCode1139();
    TestLeetCode1312();
    TestLeetCode1301();
    TestLeetCode1289();
    TestLeetCode1278();
    TestLeetCode1277();
    TestLeetCode1269();
    TestLeetCode1259();
    TestLeetCode1255();
    TestLeetCode1246();
    TestLeetCode1239();
    TestLeetCode1235();
    TestLeetCode1230();
    TestLeetCode1223();
    TestLeetCode1220();
    TestLeetCode1216();
    TestLeetCode377();
    TestLeetCode474();
    TestLeetCode923();
    TestLeetCode920();
    TestLeetCode123();
    TestLeetCode629();
    TestLeetCode514();
    TestLeetCode264();
    TestLeetCode313();
    TestLeetCode403();
    TestLeetCode45();
    TestLeetCode576();
    TestLeetCode91();
    TestLeetCode322();
    TestLeetCode118();
    TestLeetCode119();
    TestLeetCode213();
    TestLeetCode9905();
    TestLeetCode494();
    TestLeetCode518();
    TestLeetCode562();
    TestLeetCode879();
    TestLeetCode1143();
    TestLeetCode1147();
    TestLeetCode1155();
    TestLeetCode10();
    TestLeetCode44();
    TestLeetCode70();
    TestLeetCode72();
    TestLeetCode135();
    TestLeetCode115();
    TestLeetCode55();
    TestLeetCode62();
    TestLeetCode63();
    TestLeetCode64();
}
