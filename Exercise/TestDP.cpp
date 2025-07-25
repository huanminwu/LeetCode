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

    nums = { 1, 2, 3, 4};
    target = 15;
    Logger::WriteMessage(nums);
    result = leetCode.combinationSum4(nums, target);
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

void TestLeetCode902(void)
{
    Logger::WriteMessage("Test Leet Code 902");
    LeetCodeDP leetCode;
    vector<string> D = { "1", "3", "5", "7" };
    int N = 960;
    int result = leetCode.atMostNGivenDigitSet(D, N);
    Logger::WriteMessage(D);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode97(void)
{
    Logger::WriteMessage("Test Leet Code 97");
    LeetCodeDP leetCode;
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

void TestLeetCode161(void)
{
    Logger::WriteMessage("Test Leet Code 161");
    LeetCodeDP leetCode;
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

void TestLeetCode2052(void)
{
    LeetCodeDP leetCode;
    string sentence = "i love leetcode";
    int k = 12;
    int result = leetCode.minimumCost(sentence, 12);
    Logger::WriteMessage("sentence = " + sentence + "; k = " + to_string(k) + "; result = " + to_string(result));

    sentence = "apples and bananas taste great";
    k = 7;
    result = leetCode.minimumCost(sentence, k);
    Logger::WriteMessage("sentence = " + sentence + "; k = " + to_string(k) + "; result = " + to_string(result));

    sentence = "a";
    k = 5;
    result = leetCode.minimumCost(sentence, k);
    Logger::WriteMessage("sentence = " + sentence + "; k = " + to_string(k) + "; result = " + to_string(result));

    sentence = "ks kdu mcjd";
    k = 5;
    result = leetCode.minimumCost(sentence, k);
    Logger::WriteMessage("sentence = " + sentence + "; k = " + to_string(k) + "; result = " + to_string(result));

    sentence = "jjjjj ss eee jjjjj";
    k = 8;
    result = leetCode.minimumCost(sentence, k);
    Logger::WriteMessage("sentence = " + sentence + "; k = " + to_string(k) + "; result = " + to_string(result));

    sentence = "eyojph rira djqe h hmljvvdfhjctk";
    k = 16;
    result = leetCode.minimumCost(sentence, k);
    Logger::WriteMessage("sentence = " + sentence + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2044(void)
{
    LeetCodeDP leetCode;
    vector<int> nums = { 3, 1 };
    int result = leetCode.countMaxOrSubsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,2 };
    result = leetCode.countMaxOrSubsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,2,1,5 };
    result = leetCode.countMaxOrSubsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode416(void)
{
    Logger::WriteMessage("Test Leet Code 416");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 5, 11, 5 };
    bool result = leetCode.canPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " partition into equal subset.");

    nums = { 1, 2, 3, 5 };
    result = leetCode.canPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " partition into equal subset.");

    nums = { 2, 2, 1, 1 };
    result = leetCode.canPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " partition into equal subset.");
}

void TestLeetCode1049(void)
{
    Logger::WriteMessage("Test Leet Code 1049");
    LeetCodeDP leetCode;
    vector<int> stones = { 2, 1, 6, 4, 5 };
    int result = leetCode.lastStoneWeightII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { 1, 1, 1, 1, 1 };
    result = leetCode.lastStoneWeightII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { 1, 1, 4, 2, 2 };
    result = leetCode.lastStoneWeightII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { 2,7,4,1,8,1 };
    result = leetCode.lastStoneWeightII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2140(void)
{
    Logger::WriteMessage("Test Leet Code 2140");
    LeetCodeDP leetCode;
    vector<vector<int>> questions = { {3, 2},{4, 3},{4, 4},{2, 5} };
    long long result = leetCode.mostPoints(questions);
    Logger::WriteMessage(questions);
    Logger::WriteMessage("result = " + to_string(result));

    questions = { {1, 1},{2, 2},{3, 3},{4, 4},{5, 5} };
    result = leetCode.mostPoints(questions);
    Logger::WriteMessage(questions);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2143(void)
{
    Logger::WriteMessage("Test Leet Code 2143");
    LeetCodeDP leetCode;
    vector<int> nums1 = { 1, 2, 5 };
    vector<int> nums2 = { 2, 6, 3 };
    int result = leetCode.countSubranges(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 0, 1 };
    nums2 = { 1,0 };
    result = leetCode.countSubranges(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2167(void)
{
    Logger::WriteMessage("Test Leet Code 2167");
    LeetCodeDP leetCode;
    string s = "1100101";
    int result = leetCode.minimumTime(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "0010";
    result = leetCode.minimumTime(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "11110";
    result = leetCode.minimumTime(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode2184(void)
{
    Logger::WriteMessage("Test Leet Code 2184");
    LeetCodeDP leetCode;
    int height = 2;
    int width = 3;
    vector<int> bricks = { 1, 2 };
    int result = leetCode.buildWall(height, width, bricks);
    Logger::WriteMessage(bricks);
    Logger::WriteMessage("height = " + to_string(height) + "; width = " + to_string(width) + "; result = " + to_string(result));

    height = 1;
    width = 1;
    bricks = { 5 };
    result = leetCode.buildWall(height, width, bricks);
    Logger::WriteMessage(bricks);
    Logger::WriteMessage("height = " + to_string(height) + "; width = " + to_string(width) + "; result = " + to_string(result));
}

void TestLeetCode2188(void)
{
    Logger::WriteMessage("Test Leet Code 2188");
    LeetCodeDP leetCode;
    vector<vector<int>> tires = { {2, 3},{3, 4} };
    int changeTime = 5;
    int numLaps = 4;
    int result = leetCode.minimumFinishTime(tires, changeTime, numLaps);
    Logger::WriteMessage(tires);
    Logger::WriteMessage("changeTime = " + to_string(changeTime) + 
        "; numLaps = " + to_string(numLaps) + 
        "; result = " + to_string(result));

    tires = { {1, 10},{2, 2},{3, 4} };
    changeTime = 6;
    numLaps = 5;
    result = leetCode.minimumFinishTime(tires, changeTime, numLaps);
    Logger::WriteMessage(tires);
    Logger::WriteMessage("changeTime = " + to_string(changeTime) +
        "; numLaps = " + to_string(numLaps) +
        "; result = " + to_string(result));
}

void TestLeetCode2218(void)
{
    Logger::WriteMessage("Test Leet Code 2218");
    LeetCodeDP leetCode;
    vector<vector<int>> piles = { {1, 100, 3},{7, 8, 9} };
    int k = 2;
    int result = leetCode.maxValueOfCoins(piles, k);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    piles = { {100}, { 100 }, { 100 }, { 100 }, { 100 }, { 100 }, { 1, 1, 1, 1, 1, 1, 700 } };
    k = 7;
    result = leetCode.maxValueOfCoins(piles, k);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2222(void)
{
    Logger::WriteMessage("Test Leet Code 2222");
    LeetCodeDP leetCode;
    string s = "001101";
    long long result = leetCode.numberOfWays(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "11100";
    result = leetCode.numberOfWays(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode2209(void)
{
    Logger::WriteMessage("Test Leet Code 2209");
    LeetCodeDP leetCode;
    string floor = "10110101";
    int numCarpets = 2;
    int carpetLen = 2;
    int result = leetCode.minimumWhiteTiles(floor, numCarpets, carpetLen);
    Logger::WriteMessage("floor = " + floor + "; numCarpets = " + to_string(numCarpets));
    Logger::WriteMessage("carpetLen = " + to_string(carpetLen) + "; result = " + to_string(result));
 
    floor = "11111";
    numCarpets = 2;
    carpetLen = 3;
    result = leetCode.minimumWhiteTiles(floor, numCarpets, carpetLen);
    Logger::WriteMessage("floor = " + floor + "; numCarpets = " + to_string(numCarpets));
    Logger::WriteMessage("carpetLen = " + to_string(carpetLen) + "; result = " + to_string(result));
}

void TestLeetCode2263II(void)
{
    Logger::WriteMessage("Test Leet Code 2263");

    LeetCodeDP leetCode;
    vector<int> nums = { 3, 2, 4, 5, 0 };
    int result = leetCode.convertArrayII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,3,4 };
    result = leetCode.convertArrayII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0 };
    result = leetCode.convertArrayII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2267(void)
{
    Logger::WriteMessage("Test Leet Code 2267");

    LeetCodeDP leetCode;
    vector<vector<char>>grid =
    {
        {'(','(','('},{')','(',')'},{'(','(',')'},{'(','(',')'}
    };
    bool result = leetCode.hasValidPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    grid =
    { 
        {')',')'},{'(','('} 
    };
    result = leetCode.hasValidPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
    
    grid =
    { {'(', '(', '(', '(', '('}, { '(','(',')',')',')' }, { ')','(',')',')','(' }, { '(','(',')',')',')' } };
    result = leetCode.hasValidPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2266(void)
{
    Logger::WriteMessage("Test Leet Code 2266");

    LeetCodeDP leetCode;
    string pressedKeys = "22233";
    int result = leetCode.countTexts(pressedKeys);
    Logger::WriteMessage("pressedKeys = " + pressedKeys);
    Logger::WriteMessage("result = " + to_string(result));

    pressedKeys = "222222222222222222222222222222222222";
    result = leetCode.countTexts(pressedKeys);
    Logger::WriteMessage("pressedKeys = " + pressedKeys);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2291(void)
{
    Logger::WriteMessage("Test Leet Code 2291");

    LeetCodeDP leetCode;
    vector<int> present = { 5, 4, 6, 2, 3 };
    vector<int> future = { 8, 5, 4, 3, 5 };
    int budget = 10;
    int result = leetCode.maximumProfit(present, future, budget);
    Logger::WriteMessage("budget = " + to_string(budget) + "; result = " + to_string(result));

    present = { 2,2,5 };
    future = { 3,4,10 };
    budget = 6;
    result = leetCode.maximumProfit(present, future, budget);
    Logger::WriteMessage("budget = " + to_string(budget) + "; result = " + to_string(result));

    present = { 3,3,12 };
    future = { 0,3,15 };
    budget = 10;
    result = leetCode.maximumProfit(present, future, budget);
    Logger::WriteMessage("budget = " + to_string(budget) + "; result = " + to_string(result));
}

void TestLeetCode2312(void)
{
    Logger::WriteMessage("Test Leet Code 2312");
    LeetCodeDP leetCode;
    int m = 3;
    int n = 5;
    vector<vector<int>> prices = { {1, 4, 2},{2, 2, 7},{2, 1, 3} };
    long long result = leetCode.sellingWood(m, n, prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));

    m = 4;
    n = 6;
    prices = { {3, 2, 10},{1, 4, 2},{4, 1, 3} };
    result = leetCode.sellingWood(m, n, prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2318(void)
{
    Logger::WriteMessage("Test Leet Code 2318");
    LeetCodeDP leetCode;
    int n = 2;
    int result = leetCode.distinctSequences(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    result = leetCode.distinctSequences(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2320(void)
{
    Logger::WriteMessage("Test Leet Code 2320");
    LeetCodeDP leetCode;
    int n = 1;
    int result = leetCode.countHousePlacements(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    result = leetCode.countHousePlacements(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}


void TestLeetCode2361(void)
{
    Logger::WriteMessage("Test Leet Code 2361");
    LeetCodeDP leetCode;
    vector<int> regular = { 1, 6, 9, 5 };
    vector<int> express = { 5, 2, 3, 10 };
    int expressCost = 8;
    vector<long long> result = leetCode.minimumCosts(regular, express, expressCost);
    Logger::WriteMessage("expressCost = " + to_string(expressCost));
    Logger::WriteMessage(regular);
    Logger::WriteMessage(express);
    Logger::WriteMessage(result);

    regular = { 11,5,13 };
    express = { 7,10,6 };
    expressCost = 3;
    result = leetCode.minimumCosts(regular, express, expressCost);
    Logger::WriteMessage("expressCost = " + to_string(expressCost));
    Logger::WriteMessage(regular);
    Logger::WriteMessage(express);
    Logger::WriteMessage(result);
}

void TestLeetCode2369(void)
{
    Logger::WriteMessage("Test Leet Code 2369");
    LeetCodeDP leetCode;
    vector<int> nums = { 4, 4, 4, 5, 6 };
    bool result = leetCode.validPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,1,2 };
    result = leetCode.validPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2370(void)
{
    Logger::WriteMessage("Test Leet Code 2370");
    LeetCodeDP leetCode;
    string s = "acfgbd";
    int k = 2;
    int result = leetCode.longestIdealString(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "abcd";
    k = 3;
    result = leetCode.longestIdealString(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2400(void)
{
    Logger::WriteMessage("Test Leet Code 2400");
    LeetCodeDP leetCode;
    int startPos = 1, endPos = 2, k = 3;
    int result = leetCode.numberOfWays(startPos, endPos, k);
    Logger::WriteMessage("startPos = " + to_string(startPos) + 
        "; endPos = " + to_string(endPos) + "; k = " + to_string(k) + 
        "; result = " + to_string(result));

    startPos = 2, endPos = 5, k = 10;
    result = leetCode.numberOfWays(startPos, endPos, k);
    Logger::WriteMessage("startPos = " + to_string(startPos) +
        "; endPos = " + to_string(endPos) + "; k = " + to_string(k) +
        "; result = " + to_string(result));
}

void TestLeetCode2431(void)
{
    Logger::WriteMessage("Test Leet Code 2431");
    LeetCodeDP leetCode;
    vector<int> price = { 10, 20, 20 };
    vector<int> tastiness = { 5, 8, 8 };
    int maxAmount = 20;
    int maxCoupons = 1;
    int result = leetCode.maxTastiness(price, tastiness, maxAmount, maxCoupons);
    Logger::WriteMessage(price);
    Logger::WriteMessage(tastiness);
    Logger::WriteMessage("maxAmount = " + to_string(maxAmount) +
        "; maxCoupons = " + to_string(maxCoupons) +
        "; result = " + to_string(result));

    price = { 10,15,7 };
    tastiness = { 5,8,20 };
    maxAmount = 10;
    maxCoupons = 2;
    result = leetCode.maxTastiness(price, tastiness, maxAmount, maxCoupons);
    Logger::WriteMessage(price);
    Logger::WriteMessage(tastiness);
    Logger::WriteMessage("maxAmount = " + to_string(maxAmount) +
        "; maxCoupons = " + to_string(maxCoupons) +
        "; result = " + to_string(result));
}

void TestLeetCode2435(void)
{
    Logger::WriteMessage("Test Leet Code 2435");
    LeetCodeDP leetCode;
    vector<vector<int>> grid = { {5, 2, 4},{3, 0, 5},{0, 7, 2} };
    int k = 3;
    int result = leetCode.numberOfPaths(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    grid = { {0, 0} };
    k = 5;
    result = leetCode.numberOfPaths(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    grid = { {7, 3, 4, 9},{2, 3, 6, 2},{2, 3, 7, 0} };
    k = 1;
    result = leetCode.numberOfPaths(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2495(void)
{
    Logger::WriteMessage("Test Leet Code 2495");
    LeetCodeDP leetCode;
    vector<int> nums = { 9, 6, 7, 13 };
    long long result = leetCode.evenProduct(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 7,3,5 };
    result = leetCode.evenProduct(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2484(void)
{
    Logger::WriteMessage("Test Leet Code 2484");
    LeetCodeDP leetCode;
    string s = "103301";
    int result = leetCode.countPalindromes(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

     s = "0000000";
    result = leetCode.countPalindromes(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "9999900000";
    result = leetCode.countPalindromes(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode2478(void)
{
    Logger::WriteMessage("Test Leet Code 2478");
    LeetCodeDP leetCode;
    string s = "23542185131";
    int k = 3;
    int minLength = 2;
    int result = leetCode.beautifulPartitions(s, k, minLength);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("minLength = " + to_string(minLength) + "; result = " + to_string(result));

    s = "23542185131";
    k = 3;
    minLength = 3;
    result = leetCode.beautifulPartitions(s, k, minLength);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("minLength = " + to_string(minLength) + "; result = " + to_string(result));

    s = "3312958";
    k = 3;
    minLength = 1;
    result = leetCode.beautifulPartitions(s, k, minLength);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("minLength = " + to_string(minLength) + "; result = " + to_string(result));

    s = "783938233588472343879134266968";
    k = 4;
    minLength = 6;
    result = leetCode.beautifulPartitions(s, k, minLength);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("minLength = " + to_string(minLength) + "; result = " + to_string(result));

}

void TestLeetCode2464(void)
{
    Logger::WriteMessage("Test Leet Code 2464");
    LeetCodeDP leetCode;
    vector<int>nums = { 2, 6, 3, 4, 3 };
    int result = leetCode.validSubarraySplit(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,5 };
    result = leetCode.validSubarraySplit(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,1 };
    result = leetCode.validSubarraySplit(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, 6, 3, 4, 1, 2, 5, 7, 6, 8, 9, 1, 3 };
    result = leetCode.validSubarraySplit(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2466(void)
{
    Logger::WriteMessage("Test Leet Code 2466");
    LeetCodeDP leetCode;
    int low = 3;
    int high = 3;
    int zero = 1;
    int one = 1;
    int result = leetCode.countGoodStrings(low, high, zero, one);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high));
    Logger::WriteMessage("zero = " + to_string(zero) + "; one = " + to_string(one));
    Logger::WriteMessage("result = " + to_string(result));

    low = 2; 
    high = 3; 
    zero = 1; 
    one = 2;
    result = leetCode.countGoodStrings(low, high, zero, one);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high));
    Logger::WriteMessage("zero = " + to_string(zero) + "; one = " + to_string(one));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2501(void)
{
    Logger::WriteMessage("Test Leet Code 2501");
    LeetCodeDP leetCode;
    vector<int> nums = { 4, 3, 6, 16, 8, 2 };
    int result = leetCode.longestSquareStreak(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,3,5,6,7 };
    result = leetCode.longestSquareStreak(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2472(void)
{
    Logger::WriteMessage("Test Leet Code 2472");
    LeetCodeDP leetCode;
    string s = "abaccdbbd";
    int k = 3;
    int result = leetCode.maxPalindromes(s, k);
    Logger::WriteMessage(s);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    s = "adbcda";
    k = 2;
    result = leetCode.maxPalindromes(s, k);
    Logger::WriteMessage(s);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    s = "fttfjofpnpfydwdwdnns";
    k = 2;
    result = leetCode.maxPalindromes(s, k);
    Logger::WriteMessage(s);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    s = "iqqibcecvrbxxj";
    k = 1;
    result = leetCode.maxPalindromes(s, k);
    Logger::WriteMessage(s);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2463(void)
{
    Logger::WriteMessage("Test Leet Code 2463");
    LeetCodeDP leetCode;
    vector<int> robot = { 0, 4, 6 };
    vector<vector<int>> factory = { {2, 2},{6, 2} };
    long long result = leetCode.minimumTotalDistance(robot, factory);
    Logger::WriteMessage(robot);
    Logger::WriteMessage(factory);
    Logger::WriteMessage(";result = " + to_string(result));

    robot = { 1,-1 };
    factory = { {-2,1},{2,1} };
    result = leetCode.minimumTotalDistance(robot, factory);
    Logger::WriteMessage(robot);
    Logger::WriteMessage(factory);
    Logger::WriteMessage(";result = " + to_string(result));
}

void TestLeetCode2510(void)
{
    Logger::WriteMessage("Test Leet Code 2510");
    LeetCodeDP leetCode;
    vector<vector<int>> grid = 
    { 
        {0, 1, 0, 0},{0, 1, 0, 0},{1, 0, 1, 0} 
    };
    bool result = leetCode.isThereAPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    grid =
    {
        {1,1,0},{0,0,1},{1,0,0}
    };
    result = leetCode.isThereAPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2518(void)
{
    Logger::WriteMessage("Test Leet Code 2518");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    int k = 4;
    int result = leetCode.countPartitions(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 3,3,3 };
    k = 4;
    result = leetCode.countPartitions(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 6, 6 };
    k = 4;
    result = leetCode.countPartitions(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2430(void)
{
    Logger::WriteMessage("Test Leet Code 2430");
    LeetCodeDP leetCode;
    string s = "abcabcdabc";
    int result = leetCode.deleteString(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aaabaab";
    result = leetCode.deleteString(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aaaaa";
    result = leetCode.deleteString(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode2533(void)
{
    Logger::WriteMessage("Test Leet Code 2533");
    LeetCodeDP leetCode;
    int minLength = 2, maxLength = 3, oneGroup = 1, zeroGroup = 2;
    int result = leetCode.goodBinaryStrings(minLength, maxLength, oneGroup, zeroGroup);
    Logger::WriteMessage("minLength = " + to_string(minLength) + "; maxLength = " + to_string(maxLength));
    Logger::WriteMessage("oneGroup = " + to_string(oneGroup) + "; zeroGroup = " + to_string(zeroGroup));
    Logger::WriteMessage("result = " + to_string(result));

    minLength = 4, maxLength = 4, oneGroup = 4, zeroGroup = 3;
    result = leetCode.goodBinaryStrings(minLength, maxLength, oneGroup, zeroGroup);
    Logger::WriteMessage("minLength = " + to_string(minLength) + "; maxLength = " + to_string(maxLength));
    Logger::WriteMessage("oneGroup = " + to_string(oneGroup) + "; zeroGroup = " + to_string(zeroGroup));
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

void TestLeetCode2547(void)
{
    Logger::WriteMessage("Test Leet Code 2547");
    LeetCodeDP leetCode;
    vector<int> nums = { 1,2,1,2,1,3,3 };
    int k = 2;
    int result = leetCode.minCost(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,1,2,1 };
    k = 2;
    result = leetCode.minCost(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,1,2,1 };
    k = 5;
    result = leetCode.minCost(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2585(void)
{
    Logger::WriteMessage("Test Leet Code 2585");
    LeetCodeDP leetCode;
    int target = 6; 
    vector<vector<int>> types = { {6, 1},{3, 2},{2, 3} };
    int result = leetCode.waysToReachTarget(target, types);
    Logger::WriteMessage(types);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    target = 5;
    types = { {50, 1},{50, 2},{50, 5} };
    result = leetCode.waysToReachTarget(target, types);
    Logger::WriteMessage(types);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    target = 18;
    types = { {6, 1},{3, 2},{2, 3} };
    result = leetCode.waysToReachTarget(target, types);
    Logger::WriteMessage(types);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode2638(void)
{
    Logger::WriteMessage("Test Leet Code 2638");
    LeetCodeDP leetCode;
    vector<int>nums = { 5, 4, 6 };
    int k = 1;
    long long result = leetCode.countTheNumOfKFreeSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2,3,5,8 };
    k = 5;
    result = leetCode.countTheNumOfKFreeSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 10, 5, 9, 11 };
    k = 20;
    result = leetCode.countTheNumOfKFreeSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1, 5, 9, 2, 6 };
    k = 4;
    result = leetCode.countTheNumOfKFreeSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2707(void)
{
    Logger::WriteMessage("Test Leet Code 2707");
    LeetCodeDP leetCode;
    string s = "leetscode";
    vector<string> dictionary = { "leet", "code", "leetcode" };
    int result = leetCode.minExtraChar(s, dictionary);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "sayhelloworld";
    dictionary = { "hello", "world" };
    result = leetCode.minExtraChar(s, dictionary);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "abcdefg";
    dictionary = { "abc", "cdefg" };
    result = leetCode.minExtraChar(s, dictionary);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode2712(void)
{
    Logger::WriteMessage("Test Leet Code 2712");
    LeetCodeDP leetCode;
    string s = "0011";
    int64_t result = leetCode.minimumCost(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "010101";
    result = leetCode.minimumCost(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode2742(void)
{
    Logger::WriteMessage("Test Leet Code 2742");
    LeetCodeDP leetCode;
    vector<int> cost = { 1, 2, 3, 2 };
    vector<int> time = { 1, 2, 3, 2 };
    int result = leetCode.paintWalls(cost, time);
    Logger::WriteMessage(cost);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));

    cost = { 2,3,4,2 };
    time = { 1,1,1,1 };
    result = leetCode.paintWalls(cost, time);
    Logger::WriteMessage(cost);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));

    cost = { 1,2,3,4,5,6,7,8,9,10 };
    time = { 1,2,3,4,5,6,7,8,9,10 };
    result = leetCode.paintWalls(cost, time);
    Logger::WriteMessage(cost);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2767(void)
{
    Logger::WriteMessage("Test Leet Code 2767");
    LeetCodeDP leetCode;
    string s = "1011";
    int result = leetCode.minimumBeautifulSubstrings(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("result = " + to_string(result));

    s = "111";
    result = leetCode.minimumBeautifulSubstrings(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("result = " + to_string(result));

    s = "0";
    result = leetCode.minimumBeautifulSubstrings(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2770(void)
{
    Logger::WriteMessage("Test Leet Code 2770");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 3, 6, 4, 1, 2 };
    int target = 2;
    int result = leetCode.maximumJumps(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { 1,3,6,4,1,2 };
    target = 3;
    result = leetCode.maximumJumps(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { 1,3,6,4,1,2 };
    target = 0;
    result = leetCode.maximumJumps(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode2771(void)
{
    Logger::WriteMessage("Test Leet Code 2771");
    LeetCodeDP leetCode;
    vector<int> nums1 = { 2, 3, 1 };
    vector<int> nums2 = { 1, 2, 1 };
    int result = leetCode.maxNonDecreasingLength(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1, 3, 2, 1 };
    nums2 = { 2, 2, 3, 4 };
    result = leetCode.maxNonDecreasingLength(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1, 1 };
    nums2 = { 2, 2 };
    result = leetCode.maxNonDecreasingLength(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 14, 4 };
    nums2 = { 2, 13 };
    result = leetCode.maxNonDecreasingLength(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2786(void)
{
    Logger::WriteMessage("Test Leet Code 2786");
    LeetCodeDP leetCode;
    vector<int> nums = { 2,3,6,1,9,2 };
    int x = 5;
    long long result = leetCode.maxScore(nums, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,4,6,8 };
    x = 3;
    result = leetCode.maxScore(nums, x);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode741(void)
{
    LeetCodeDP leetCode;
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

void TestLeetCode1092(void)
{
    Logger::WriteMessage("Test Leet Code 1092");
    LeetCodeDP leetCode;
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

void TestLeetCode1062(void)
{
    Logger::WriteMessage("Test Leet Code 1062");
    LeetCodeDP leetCode;
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

void TestLeetCode1025(void)
{
    Logger::WriteMessage("Test Leet Code 1025");
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
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

void TestLeetCode1031(void)
{
    Logger::WriteMessage("Test Leet Code 1031");
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
    vector<int> A = { 1, 15, 7, 9, 2, 5, 10 };
    int K = 3;
    int result = leetCode.maxSumAfterPartitioning(A, K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode1048(void)
{
    Logger::WriteMessage("Test Leet Code 1048");
    LeetCodeDP leetCode;
    vector<string> words = { "a","b","ba","bca","bda","bdca" };
    int result = leetCode.longestStrChain(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode983(void)
{
    Logger::WriteMessage("Test Leet Code 983");
    LeetCodeDP leetCode;
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

void TestLeetCode982(void)
{
    Logger::WriteMessage("Test Leet Code 982");
    LeetCodeDP leetCode;
    vector<int> A = { 2, 1, 3 };
    int result = leetCode.countTriplets(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode956(void)
{
    Logger::WriteMessage("Test Leet Code 956");
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
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


void TestLeetCode975(void)
{
    Logger::WriteMessage("Test Leet Code 975");
    LeetCodeDP leetCode;
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

void TestLeetCode978(void)
{
    Logger::WriteMessage("Test Leet Code 978");
    LeetCodeDP leetCode;
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

void TestLeetCode887(void)
{
    Logger::WriteMessage("Test Leet Code 887");
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
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

void TestLeetCode931(void)
{
    Logger::WriteMessage("Test Leet Code 931");
    LeetCodeDP leetCode;
    vector<vector<int>> A = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    int result = leetCode.minFallingPathSum(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

}

void TestLeetCode935(void)
{
    Logger::WriteMessage("Test Leet Code 935");
    LeetCodeDP leetCode;
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

void TestLeetCode903(void)
{
    Logger::WriteMessage("Test Leet Code 903");
    string S = "DID";
    LeetCodeDP leetCode;
    int result = leetCode.numPermsDISequence(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode940(void)
{
    Logger::WriteMessage("Test Leet Code 940");
    LeetCodeDP leetCode;
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

void TestLeetCode764(void)
{
    Logger::WriteMessage("Test Leet Code 764");
    LeetCodeDP leetCode;
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


void TestLeetCode788(void)
{
    Logger::WriteMessage("Test Leet Code 788");
    LeetCodeDP leetCode;
    int N = 110;
    int result = leetCode.rotatedDigits(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode790(void)
{
    Logger::WriteMessage("Test Leet Code 790");
    LeetCodeDP leetCode;
    int N = 4;
    int result = leetCode.numTilings(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode795(void)
{
    Logger::WriteMessage("Test Leet Code 795");
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
    int K = 0;
    int result = leetCode.preimageSizeFZF(K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    K = 5;
    result = leetCode.preimageSizeFZF(K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode799(void)
{
    Logger::WriteMessage("Test Leet Code 799");
    LeetCodeDP leetCode;

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
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
    int N = 50;
    double result = leetCode.soupServings(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode813(void)
{
    Logger::WriteMessage("Test Leet Code 813");
    LeetCodeDP leetCode;
    vector<int> A = { 9, 1, 2, 3, 9 };
    int K = 3;
    double result = leetCode.largestSumOfAverages(A, K);
    Logger::WriteMessage(A);

    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode823(void)
{
    Logger::WriteMessage("Test Leet Code 823");
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
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

void TestLeetCode873(void)
{
    Logger::WriteMessage("Test Leet Code 873");
    LeetCodeDP leetCode;
    vector<int> A = { 1,2,3,4,5,6,7,8 };
    int result = leetCode.lenLongestFibSubseq(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1, 3, 7, 11, 12, 14, 18 };
    result = leetCode.lenLongestFibSubseq(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode689(void)
{
    LeetCodeDP leetCode;
    vector<int> nums = { 1,2,1,2,6,7,5,1 };
    int k = 2;
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    vector<int> result = leetCode.maxSumOfThreeSubarrays(nums, k);
    Logger::WriteMessage(result);
}


void TestLeetCode714(void)
{
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
    string S = "abcdebdde";
    string T = "bde";
    string result = leetCode.minWindowIII(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + result);
};

void TestLeetCode730(void)
{
    LeetCodeDP leetCode;
    string S = "bccb";
    int result = leetCode.countPalindromicSubsequences(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    result = leetCode.countPalindromicSubsequences(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
};

void TestLeetCode740(void)
{
    LeetCodeDP leetCode;
    vector<int> nums = { 3, 4, 2 };
    int result = leetCode.deleteAndEarn(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, 2, 3, 3, 3, 4 };
    result = leetCode.deleteAndEarn(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode712(void)
{
    Logger::WriteMessage("Test Leet Code");
    LeetCodeDP leetCode;
    string s1 = "sea";
    string s2 = "eat";
    int result = leetCode.minimumDeleteSum(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + to_string(result));

    s1 = "delete";
    s2 = "leet";
    result = leetCode.minimumDeleteSum(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + to_string(result));
}

void TestLeetCode898(void)
{
    Logger::WriteMessage("Test Leet Code 898");
    LeetCodeDP leetCode;
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

void TestLeetCode877(void)
{
    Logger::WriteMessage("Test Leet Code 877");
    LeetCodeDP leetCode;
    vector<int> piles = { 5,3,4,5 };
    bool result = leetCode.stoneGame(piles);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("First player can win: " + (string)(result ? "true" : "false"));
}

void TestLeetCode718(void)
{
    LeetCodeDP leetCode;

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

void TestLeetCode746(void)
{
    Logger::WriteMessage("Test Leet Code 746");
    LeetCodeDP leetCode;
    vector<int> cost = { 10, 15, 20 };
    int result = leetCode.minCostClimbingStairs(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    result = leetCode.minCostClimbingStairs(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode660(void)
{
    LeetCodeDP leetCode;
    int n = 9;
    int result = leetCode.newInteger(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 100;
    result = leetCode.newInteger(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode664(void)
{
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
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

void TestLeetCode484(void)
{
    Logger::WriteMessage("Test Leet Code 484");

    string s = "I";
    LeetCodeDP leetCode;
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
    LeetCodeDP leetCode;
    int n = 10;
    int money = leetCode.getMoneyAmount(n);
    Logger::WriteMessage("n = " + to_string(n) + "; money = " + to_string(money));
}

void TestLeetCode552(void)
{
    LeetCodeDP leetCode;
    int n = 65;
    int result = leetCode.checkRecord(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode583(void)
{
    LeetCodeDP leetCode;
    string word1 = "sea", word2 = "eat";
    int result = leetCode.minDeleteDistance(word1, word2);

    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; min del distance = " + to_string(result));
}

void TestLeetCode600(void)
{
    LeetCodeDP leetCode;
    int num = 5;
    int result = leetCode.findIntegers(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode634(void)
{
    LeetCodeDP leetCode;
    int n = 3;
    int result = leetCode.findDerangement(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode639(void)
{
    LeetCodeDP leetCode;
    string s = "1*";
    int result = leetCode.numDecodingsII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode647(void)
{
    LeetCodeDP leetCode;
    string s = "abc";
    int result = leetCode.countSubstrings(s);
    Logger::WriteMessage("string = " + s + "; palindromic count = " + to_string(result));

    s = "aaa";
    result = leetCode.countSubstrings(s);
    Logger::WriteMessage("string = " + s + "; palindromic count = " + to_string(result));
}

void TestLeetCode650(void)
{
    LeetCodeDP leetCode;
    int n = 4;
    int result = leetCode.minSteps(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode651(void)
{
    LeetCodeDP leetCode;
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

void TestLeetCode2809(void)
{
    LeetCodeDP leetCode;
    vector<int> nums1 = { 1, 2, 3 };
    vector<int> nums2 = { 1, 2, 3 };
    int x = 4;
    int result = leetCode.minimumTime(nums1, nums2, x);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    nums1 = { 1,2,3 };
    nums2 = { 3,3,3 };
    x = 4;
    result = leetCode.minimumTime(nums1, nums2, x);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    nums1 = { 8, 2, 3 };
    nums2 = { 1, 4, 2 };
    x = 13;
    result = leetCode.minimumTime(nums1, nums2, x);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    nums1 = { 6, 6, 8, 7, 1, 7 };
    nums2 = { 2, 2, 1, 1, 2, 3 };
    x = 27;
    result = leetCode.minimumTime(nums1, nums2, x);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));
}

void TestLeetCode2826(void)
{
    LeetCodeDP leetCode;
    vector<int> nums = { 2, 1, 3, 2, 1 };
    int result = leetCode.minimumOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,3,2,1,3,3 };
    result = leetCode.minimumOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,2,2,2,3,3 };
    result = leetCode.minimumOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2896(void)
{
    LeetCodeDP leetCode;
    string s1 = "1100011000";
    string s2 = "0101001010";
    int x = 2;
    int result = leetCode.minOperationsDFS(s1, s2, x);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    s1 = "10110";
    s2 = "00011";
    x = 4;
    result = leetCode.minOperationsDFS(s1, s2, x);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    s1 = "0101101001111010111001000111";
    s2 = "1001000010101001010111000110";
    x = 6;
    result = leetCode.minOperationsDFS(s1, s2, x);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));
}

void TestLeetCode2915(void)
{
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    int target = 9;
    int result = leetCode.lengthOfLongestSubsequence(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { 4,1,3,2,1,5 };
    target = 7;
    result = leetCode.lengthOfLongestSubsequence(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { 1,1,5,4,5 };
    target = 3;
    result = leetCode.lengthOfLongestSubsequence(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}


void TestLeetCode2919(void)
{
    Logger::WriteMessage("Test Leet Code 2919");
    LeetCodeDP leetCode;
    vector<int> nums = { 2, 3, 0, 0, 2 };
    int k = 4;
    long long result = leetCode.minIncrementOperations(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 0,1,3,3 };
    k = 5;
    result = leetCode.minIncrementOperations(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,1,2 };
    k = 1;
    result = leetCode.minIncrementOperations(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 4, 0, 10, 2, 10, 6 };
    k = 8;
    result = leetCode.minIncrementOperations(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 13, 34, 0, 13, 9, 19 };
    k = 82;
    result = leetCode.minIncrementOperations(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2944(void)
{
    Logger::WriteMessage("Test Leet Code 2944");
    LeetCodeDP leetCode;
    vector<int> prices = { 3, 1, 2 };
    int result = leetCode.minimumCoins(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 1,10,1,1 };
    result = leetCode.minimumCoins(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 26, 18, 6, 12, 49, 7, 45, 45 };
    result = leetCode.minimumCoins(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2969(void)
{
    Logger::WriteMessage("Test Leet Code 2969");
    LeetCodeDP leetCode;
    vector<int> prices = { 3,1,2 };
    int result = leetCode.minimumCoins(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 1,10,1,1 };
    result = leetCode.minimumCoins(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));

    prices = { 26, 18, 6, 12, 49, 7, 45, 45 };
    result = leetCode.minimumCoins(prices);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3003(void)
{
    Logger::WriteMessage("Test Leet Code 3003");
    LeetCodeDP leetCode;
    string s = "accca";
    int k = 2;
    int result = leetCode.maxPartitionsAfterOperations(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    s = "aabaab";
    k = 3;
    result = leetCode.maxPartitionsAfterOperations(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    s = "xxyz";
    k = 1;
    result = leetCode.maxPartitionsAfterOperations(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    s = "tzaxomrbtieqpkduclsjhdyxonfwwbnbqgbvdxaqhbip";
    k = 26;
    result = leetCode.maxPartitionsAfterOperations(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3041(void)
{
    Logger::WriteMessage("Test Leet Code 3041");
    LeetCodeDP leetCode;
    vector<int> nums = { 2, 1, 5, 1, 1 };
    Logger::WriteMessage(nums);
    int result = leetCode.maxSelectedElements(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,4,7,10 };
    Logger::WriteMessage(nums);
    result = leetCode.maxSelectedElements(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode87(void)
{
    Logger::WriteMessage("Test Leet Code 87");
    LeetCodeDP leetCode;
    string s1 = "great", s2 = "rgeat";
    bool result = leetCode.isScramble(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result? "true" : "false"));
    s1 = "abc", s2 = "bca";
    result = leetCode.isScramble(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode3070(void)
{
    Logger::WriteMessage("Test Leet Code 3070");
    LeetCodeDP leetCode;
    vector<vector<int>> grid = { {7, 6, 3},{6, 6, 1} };
    int k = 18;
    int result = leetCode.countSubmatrices(grid, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    grid = { {7, 2, 9},{1, 5, 0},{2, 6, 6} };
    k = 20;
    result = leetCode.countSubmatrices(grid, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3082(void)
{
    Logger::WriteMessage("Test Leet Code 3082");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3 };
    int k = 3;
    int result = leetCode.sumOfPower(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2,3,3 };
    k = 5;
    result = leetCode.sumOfPower(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,3 };
    k = 7;
    result = leetCode.sumOfPower(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3077(void)
{
    Logger::WriteMessage("Test Leet Code 3077");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, -1, 2 };
    int k = 3;
    long long result = leetCode.maximumStrength(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 12,-2,-2,-2,-2 };
    k = 5;
    result = leetCode.maximumStrength(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { -1,-2,-3 };
    k = 1;
    result = leetCode.maximumStrength(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3122(void)
{
    Logger::WriteMessage("Test Leet Code 3122");
    LeetCodeDP leetCode;
    vector<vector<int>> grid = { {1, 0, 2},{1, 0, 2} };
    int result = leetCode.minimumOperationsGrid(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1,1,1} ,{0,0,0} };
    result = leetCode.minimumOperationsGrid(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1},{2},{3} };
    result = leetCode.minimumOperationsGrid(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3117(void)
{
    Logger::WriteMessage("Test Leet Code 3117");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 4, 3, 3, 2 };
    vector<int> andValues = { 0, 3, 3, 2 };
    int result = leetCode.minimumValueSum(nums, andValues);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,3,5,7,7,7,5 };
    andValues = { 0,7,5 };
    result = leetCode.minimumValueSum(nums, andValues);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4 };
    andValues = { 2 };
    result = leetCode.minimumValueSum(nums, andValues);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4, 8, 10, 7, 6 };
    andValues = { 0, 6 };
    result = leetCode.minimumValueSum(nums, andValues);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3129(void)
{
    Logger::WriteMessage("Test Leet Code 3129");
    LeetCodeDP leetCode;
    int zero = 1, one = 1, limit = 2;
    int result = leetCode.numberOfStableArraysI(zero, one, limit);
    Logger::WriteMessage("zero = " + to_string(zero) + "; one = " + to_string(one));
    Logger::WriteMessage("limit = " + to_string(zero) + "; result = " + to_string(result));

    zero = 1, one = 2, limit = 1;
    result = leetCode.numberOfStableArraysI(zero, one, limit);
    Logger::WriteMessage("zero = " + to_string(zero) + "; one = " + to_string(one));
    Logger::WriteMessage("limit = " + to_string(zero) + "; result = " + to_string(result));

    zero = 3, one = 3, limit = 2;
    result = leetCode.numberOfStableArraysI(zero, one, limit);
    Logger::WriteMessage("zero = " + to_string(zero) + "; one = " + to_string(one));
    Logger::WriteMessage("limit = " + to_string(zero) + "; result = " + to_string(result));
}

void TestLeetCode3130(void)
{
    Logger::WriteMessage("Test Leet Code 3130");
    LeetCodeDP leetCode;
    int zero = 1, one = 1, limit = 2;
    int result = leetCode.numberOfStableArraysII(zero, one, limit);
    Logger::WriteMessage("zero = " + to_string(zero) + "; one = " + to_string(one));
    Logger::WriteMessage("limit = " + to_string(zero) + "; result = " + to_string(result));

    zero = 1, one = 2, limit = 1;
    result = leetCode.numberOfStableArraysII(zero, one, limit);
    Logger::WriteMessage("zero = " + to_string(zero) + "; one = " + to_string(one));
    Logger::WriteMessage("limit = " + to_string(zero) + "; result = " + to_string(result));

    zero = 3, one = 3, limit = 2;
    result = leetCode.numberOfStableArraysII(zero, one, limit);
    Logger::WriteMessage("zero = " + to_string(zero) + "; one = " + to_string(one));
    Logger::WriteMessage("limit = " + to_string(zero) + "; result = " + to_string(result));
}

void TestLeetCode3135(void)
{
    Logger::WriteMessage("Test Leet Code 3135");
    LeetCodeDP leetCode;
    string initial = "abcde", target = "cdef";
    int result = leetCode.minOperations(initial, target);
    Logger::WriteMessage("initial = " + initial + "; target = " + target);
    Logger::WriteMessage("result = " + to_string(result));

    initial = "axxy", target = "yabx";
    result = leetCode.minOperations(initial, target);
    Logger::WriteMessage("initial = " + initial + "; target = " + target);
    Logger::WriteMessage("result = " + to_string(result));

    initial = "xyz", target = "xyz";
    result = leetCode.minOperations(initial, target);
    Logger::WriteMessage("initial = " + initial + "; target = " + target);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3144(void)
{
    Logger::WriteMessage("Test Leet Code 3144");
    LeetCodeDP leetCode;
    string s = "fabccddg";
    int result = leetCode.minimumSubstringsInPartition(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "abababaccddb";
    result = leetCode.minimumSubstringsInPartition(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode3147(void)
{
    Logger::WriteMessage("Test Leet Code 3147");
    LeetCodeDP leetCode;
    vector<int>energy = { 5, 2, -10, -5, 1 };
    int k = 3;
    int result = leetCode.maximumEnergy(energy, k);
    Logger::WriteMessage(energy);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    energy = { -2,-3,-1 };
    k = 2;
    result = leetCode.maximumEnergy(energy, k);
    Logger::WriteMessage(energy);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3176(void)
{
    Logger::WriteMessage("Test Leet Code 3176");
    LeetCodeDP leetCode;
    vector<int>nums = { 1,2,1,1,3 };
    int k = 2;
    int result = leetCode.maximumLengthI(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,3,4,5,1 };
    k = 0;
    result = leetCode.maximumLengthI(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3177(void)
{
    Logger::WriteMessage("Test Leet Code 3177");
    LeetCodeDP leetCode;
    vector<int>nums = { 1,2,1,1,3 };
    int k = 2;
    int result = leetCode.maximumLengthII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,3,4,5,1 };
    k = 0;
    result = leetCode.maximumLengthII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3180(void)
{
    Logger::WriteMessage("Test Leet Code 3180");
    LeetCodeDP leetCode;
    vector<int>nums = { 1,1,3,3 };
    int result = leetCode.maxTotalRewardI(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,6,4,3,2 };
    result = leetCode.maxTotalRewardI(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3186(void)
{
    Logger::WriteMessage("Test Leet Code 3186");
    LeetCodeDP leetCode;
    vector<int> power = { 1, 1, 3, 4 };
    long long result = leetCode.maximumTotalDamage(power);
    Logger::WriteMessage(power);
    Logger::WriteMessage("result = " + to_string(result));

    power = { 7,1,6,6 };
    result = leetCode.maximumTotalDamage(power);
    Logger::WriteMessage(power);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3196(void)
{
    Logger::WriteMessage("Test Leet Code 3196");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, -2, 3, 4 };
    long long result = leetCode.maximumTotalCost(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,-1,1,-1 };
    result = leetCode.maximumTotalCost(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0 };
    result = leetCode.maximumTotalCost(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,-1 };
    result = leetCode.maximumTotalCost(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3193(void)
{
    Logger::WriteMessage("Test Leet Code 3193");
    LeetCodeDP leetCode;
    int n = 3;
    vector<vector<int>> requirements = { {2, 2},{0, 0} };
    int result = leetCode.numberOfPermutations(n, requirements);
    Logger::WriteMessage(requirements);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    requirements = { {2, 2},{1, 1},{0, 0} };
    result = leetCode.numberOfPermutations(n, requirements);
    Logger::WriteMessage(requirements);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    requirements = { {0, 0},{1, 0} };
    result = leetCode.numberOfPermutations(n, requirements);
    Logger::WriteMessage(requirements);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode3201(void)
{
    Logger::WriteMessage("Test Leet Code 3201");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    int result = leetCode.maximumLengthI(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,1,1,2,1,2 };
    result = leetCode.maximumLengthI(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,3 };
    result = leetCode.maximumLengthI(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3202(void)
{
    Logger::WriteMessage("Test Leet Code 3202");
    LeetCodeDP leetCode;
    vector<int> nums = { 1,2,3,4,5 };
    int k = 2;
    int result = leetCode.maximumLengthModII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,4,2,3,1,4 };
    k = 3;
    result = leetCode.maximumLengthModII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3247(void)
{
    Logger::WriteMessage("Test Leet Code 3247");
    LeetCodeDP leetCode;
    vector<int> nums = { 1,1,1 };
    int result = leetCode.subsequenceCount(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,2 };
    result = leetCode.subsequenceCount(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3250(void)
{
    Logger::WriteMessage("Test Leet Code 3250");
    LeetCodeDP leetCode;
    vector<int> nums = { 2,3,2 };
    int result = leetCode.countOfPairsI(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5,5,5,5 };
    result = leetCode.countOfPairsI(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3259(void)
{
    Logger::WriteMessage("Test Leet Code 3259");
    LeetCodeDP leetCode;
    vector<int> energyDrinkA = { 1, 3, 1 };
    vector<int> energyDrinkB = { 3, 1, 1 };
    long long result = leetCode.maxEnergyBoost(energyDrinkA, energyDrinkB);
    Logger::WriteMessage(energyDrinkA);
    Logger::WriteMessage(energyDrinkB);
    Logger::WriteMessage("result = " + to_string(result));

    energyDrinkA = { 4,1,1 };
    energyDrinkB = { 1,1,3 };
    result = leetCode.maxEnergyBoost(energyDrinkA, energyDrinkB);
    Logger::WriteMessage(energyDrinkA);
    Logger::WriteMessage(energyDrinkB);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3269(void)
{
    Logger::WriteMessage("Test Leet Code 3269");
    LeetCodeDP leetCode;
    vector<int>  nums1 = {};
    vector<int>  nums2 = { 1, 0, 1, 1 };
    int result = leetCode.minLargest(nums1,nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 0,1,0,1 };
    nums2 = { 1,0,0,1 };
    result = leetCode.minLargest(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 0,1,0,0,1 };
    nums2 = { 0,0,0,1 };
    result = leetCode.minLargest(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3277(void)
{
    Logger::WriteMessage("Test Leet Code 3277");
    LeetCodeDP leetCode;
    vector<int>  nums = { 2, 8, 4, 32, 16, 1 };
    vector<vector<int>> queries = { {0, 2},{1, 4},{0, 5} };
    vector<int> result = leetCode.maximumSubarrayXor(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    nums = { 0,7,3,2,8,5,1 };
    queries = { {0,3} ,{1,5},{2,4},{2,6},{5,6} };
    result = leetCode.maximumSubarrayXor(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode3287(void)
{
    Logger::WriteMessage("Test Leet Code 3287");
    LeetCodeDP leetCode;
    vector<int>  nums = { 2, 6, 7 };
    int k = 1;
    int result = leetCode.maxValue(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 4,2,5,6,7 };
    k = 2;
    result = leetCode.maxValue(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3290(void)
{
    Logger::WriteMessage("Test Leet Code 3290");
    LeetCodeDP leetCode;
    vector<int> a = { 3, 2, 5, 6 };
    vector<int> b = { 2, -6, 4, -5, -3, 2, -7 };
    long long result = leetCode.maxScore(a, b);
    Logger::WriteMessage(a);
    Logger::WriteMessage(b);
    Logger::WriteMessage("result = " + to_string(result));

    a = { -1,4,5,-2 };
    b = { -5,-1,-3,-2,-4 };
    result = leetCode.maxScore(a, b);
    Logger::WriteMessage(a);
    Logger::WriteMessage(b);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3302(void)
{
    Logger::WriteMessage("Test Leet Code 3302");
    LeetCodeDP leetCode;
    string word1 = "vbcca", word2 = "abc";
    vector<int> result = leetCode.validSequence(word1, word2);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(result);

    word1 = "bacdc", word2 = "abc";
    result = leetCode.validSequence(word1, word2);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(result);
    
    word1 = "aaaaaa", word2 = "aaabc";
    result = leetCode.validSequence(word1, word2);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(result);

    word1 = "abc", word2 = "ab";
    result = leetCode.validSequence(word1, word2);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(result);
}

void TestLeetCode3316(void)
{
    Logger::WriteMessage("Test Leet Code 3316");
    LeetCodeDP leetCode;
    string source = "abbaa", pattern = "aba";
    vector<int> targetIndices = { 0, 1, 2 };
    int result = leetCode.maxRemovals(source, pattern, targetIndices);
    Logger::WriteMessage("source = " + source + "; pattern = " + pattern);
    Logger::WriteMessage(targetIndices);
    Logger::WriteMessage("result = " + to_string(result));

    source = "bcda", pattern = "d";
    targetIndices = { 0, 3 };
    result = leetCode.maxRemovals(source, pattern, targetIndices);
    Logger::WriteMessage("source = " + source + "; pattern = " + pattern);
    Logger::WriteMessage(targetIndices);
    Logger::WriteMessage("result = " + to_string(result));

    source = "dda", pattern = "dda";
    targetIndices = { 0, 1, 2 };
    result = leetCode.maxRemovals(source, pattern, targetIndices);
    Logger::WriteMessage("source = " + source + "; pattern = " + pattern);
    Logger::WriteMessage(targetIndices);
    Logger::WriteMessage("result = " + to_string(result));

    source = "yeyeykyded", pattern = "yeyyd";
    targetIndices = { 0, 2, 3, 4 };
    result = leetCode.maxRemovals(source, pattern, targetIndices);
    Logger::WriteMessage("source = " + source + "; pattern = " + pattern);
    Logger::WriteMessage(targetIndices);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3320(void)
{
    Logger::WriteMessage("Test Leet Code 3320");
    LeetCodeDP leetCode;
    string s = "FFF";
    int result = leetCode.countWinningSequences(s);
    Logger::WriteMessage("source = " + s);
    Logger::WriteMessage("result = " + to_string(result));

    s = "FWEFW";
    result = leetCode.countWinningSequences(s);
    Logger::WriteMessage("source = " + s);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3332(void)
{
    Logger::WriteMessage("Test Leet Code 3332");
    LeetCodeDP leetCode;
    int n = 2, k = 1;
    vector<vector<int>> stayScore = { {2, 3} };
    vector<vector<int>> travelScore = { {0, 2},{1, 0} };
    int result = leetCode.maxScore(n, k, stayScore, travelScore);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(stayScore);
    Logger::WriteMessage(travelScore);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3, k = 2;
    stayScore = { {3, 4, 2},{2, 1, 2} };
    travelScore = { {0, 2, 1},{2, 0, 4},{3, 2, 0} };
    result = leetCode.maxScore(n, k, stayScore, travelScore);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(stayScore);
    Logger::WriteMessage(travelScore);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3336(void)
{
    Logger::WriteMessage("Test Leet Code 3336");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    int result = leetCode.subsequencePairCount(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 10,20,30 };
    result = leetCode.subsequencePairCount(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,1,1 };
    result = leetCode.subsequencePairCount(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3339(void)
{
    Logger::WriteMessage("Test Leet Code 3339");
    LeetCodeDP leetCode;
    int n = 3, m = 4, k = 2;
    int result = leetCode.countOfArrays(n, m, k);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 7, m = 7, k = 5;
    result = leetCode.countOfArrays(n, m, k);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 5, m = 1, k = 0;
    result = leetCode.countOfArrays(n, m, k);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));
}

void TestLeetCode3366(void)
{
    Logger::WriteMessage("Test Leet Code 3366");
    LeetCodeDP leetCode;
    vector<int> nums = { 2, 8, 3, 19, 3 };
    int k = 3, op1 = 1, op2 = 1;
    int result = leetCode.minArraySum(nums, k, op1, op2);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; op1 = " + to_string(op1));
    Logger::WriteMessage("op2 = " + to_string(op2) + "; result = " + to_string(result));

    nums = { 2,4,3 };
    k = 3, op1 = 2, op2 = 1;
    result = leetCode.minArraySum(nums, k, op1, op2);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; op1 = " + to_string(op1));
    Logger::WriteMessage("op2 = " + to_string(op2) + "; result = " + to_string(result));

    nums = { 3 };
    k = 6, op1 = 1, op2 = 1;
    result = leetCode.minArraySum(nums, k, op1, op2);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; op1 = " + to_string(op1));
    Logger::WriteMessage("op2 = " + to_string(op2) + "; result = " + to_string(result));
}

void TestLeetCode3363(void)
{
    Logger::WriteMessage("Test Leet Code 3363");
    LeetCodeDP leetCode;
    vector<vector<int>>fruits = { {1, 2, 3, 4},{5, 6, 8, 7},{9, 10, 11, 12},{13, 14, 15, 16} };
    Logger::WriteMessage(fruits);
    int result = leetCode.maxCollectedFruits(fruits);
    Logger::WriteMessage("result = " + to_string(result));

    fruits = { {1, 1},{1, 1} };
    Logger::WriteMessage(fruits);
    result = leetCode.maxCollectedFruits(fruits);
    Logger::WriteMessage("result = " + to_string(result));

    fruits = { {8, 5, 0, 17, 15},{6, 0, 15, 6, 0},{7, 19, 16, 8, 18},{11, 3, 2, 12, 13},{17, 15, 15, 4, 6} };
    Logger::WriteMessage(fruits);
    result = leetCode.maxCollectedFruits(fruits);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3388(void)
{
    Logger::WriteMessage("Test Leet Code 3388");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 1, 2, 1 };
    int result = leetCode.beautifulSplits(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4 };
    result = leetCode.beautifulSplits(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3393(void)
{
    Logger::WriteMessage("Test Leet Code 3393");
    LeetCodeDP leetCode;
    vector<vector<int>> grid = { {2, 1, 5},{7, 10, 0},{12, 6, 4} };
    int k = 11;
    int result = leetCode.countPathsWithXorValue(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    grid = { {1, 3, 3, 3},{0, 3, 3, 2},{3, 0, 1, 1} };
    k = 2;
    result = leetCode.countPathsWithXorValue(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    grid = { {1, 1, 1, 2},{3, 0, 3, 2},{3, 0, 2, 2} };
    k = 10;
    result = leetCode.countPathsWithXorValue(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3414(void)
{
    Logger::WriteMessage("Test Leet Code 3414");
    LeetCodeDP leetCode;
    vector<vector<int>> intervals = { {1, 3, 2},{4, 5, 2},{1, 5, 5},{6, 9, 3},{6, 7, 1},{8, 9, 1} };
    vector<int> result = leetCode.maximumWeight(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(result);

    intervals = { {5, 8, 1},{6, 7, 7},{4, 7, 3},{9, 10, 6},{7, 8, 2},{11, 14, 3},{3, 5, 5} };
    result = leetCode.maximumWeight(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(result);

    intervals = { {4, 4, 1},{2, 5, 3},{2, 3, 2} };
    result = leetCode.maximumWeight(intervals);
    Logger::WriteMessage(intervals);
    Logger::WriteMessage(result);    
}

void TestLeetCode3418(void)
{
    Logger::WriteMessage("Test Leet Code 3418");
    LeetCodeDP leetCode;
    vector<vector<int>>coins = { {0, 1, -1},{1, -2, 3},{2, -3, 4} };
    int result = leetCode.maximumAmount(coins);
    Logger::WriteMessage(coins);
    Logger::WriteMessage("result = " + to_string(result));

    coins = { {10, 10, 10},{10, 10, 10} };
    result = leetCode.maximumAmount(coins);
    Logger::WriteMessage(coins);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3429(void)
{
    Logger::WriteMessage("Test Leet Code 3429");
    LeetCodeDP leetCode;
    int n = 4;
    vector<vector<int>> cost = { {3, 5, 7},{6, 2, 9},{4, 8, 1},{7, 3, 5} };
    long long result = leetCode.minCostIV(n, cost);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    n = 6; 
    cost = { {2, 4, 6},{5, 3, 8},{7, 1, 9},{4, 6, 2},{3, 5, 7},{8, 2, 4} };
    result = leetCode.minCostIV(n, cost);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3441(void)
{
    Logger::WriteMessage("Test Leet Code 3441");
    LeetCodeDP leetCode;
    string caption = "abc";
    string result = leetCode.minCostGoodCaption(caption);
    Logger::WriteMessage("caption = " + caption);
    Logger::WriteMessage("result = " + result);


    caption = "cdcd";
    result = leetCode.minCostGoodCaption(caption);
    Logger::WriteMessage("caption = " + caption);
    Logger::WriteMessage("result = " + result);

    caption = "aca";
    result = leetCode.minCostGoodCaption(caption);
    Logger::WriteMessage("caption = " + caption);
    Logger::WriteMessage("result = " + result);

    caption = "bc";
    result = leetCode.minCostGoodCaption(caption);
    Logger::WriteMessage("caption = " + caption);
    Logger::WriteMessage("result = " + result);

    caption = "owsjeo";
    result = leetCode.minCostGoodCaption(caption);
    Logger::WriteMessage("caption = " + caption);
    Logger::WriteMessage("result = " + result);

    caption = "antwfdps";
    result = leetCode.minCostGoodCaption(caption);
    Logger::WriteMessage("caption = " + caption);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode3469(void)
{
    Logger::WriteMessage("Test Leet Code 3469");
    LeetCodeDP leetCode;
    vector<int> nums = { 6, 2, 8, 4 };
    int result = leetCode.minCostRemoveElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,1,3,3 };
    result = leetCode.minCostRemoveElements(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3466(void)
{
    Logger::WriteMessage("Test Leet Code 3466");
    LeetCodeDP leetCode;
    vector<int> lane1 = { 1, -2, -10, 3 };
    vector<int> lane2 = { -5, 10, 0, 1 };
    long long result = leetCode.maxCoins(lane1, lane2);
    Logger::WriteMessage(lane1);
    Logger::WriteMessage(lane2);
    Logger::WriteMessage("result = " + to_string(result));

    lane1 = { 1,-1,-1,-1 };
    lane2 = { 0,3,4,-5 };
    result = leetCode.maxCoins(lane1, lane2);
    Logger::WriteMessage(lane1);
    Logger::WriteMessage(lane2);
    Logger::WriteMessage("result = " + to_string(result));

    lane1 = { -5,-4,-3 };
    lane2 = { -1,2,3 };
    result = leetCode.maxCoins(lane1, lane2);
    Logger::WriteMessage(lane1);
    Logger::WriteMessage(lane2);
    Logger::WriteMessage("result = " + to_string(result));

    lane1 = { -3,-3,-3 };
    lane2 = { 9,-2,4 };
    result = leetCode.maxCoins(lane1, lane2);
    Logger::WriteMessage(lane1);
    Logger::WriteMessage(lane2);
    Logger::WriteMessage("result = " + to_string(result));

    lane1 = { -10 };
    lane2 = { -2 };
    result = leetCode.maxCoins(lane1, lane2);
    Logger::WriteMessage(lane1);
    Logger::WriteMessage(lane2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3472(void)
{
    Logger::WriteMessage("Test Leet Code 3472");
    LeetCodeDP leetCode;
    string s = "abced";
    int  k = 2;
    int result = leetCode.longestPalindromicSubsequence(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    s = "aaazzz";
    k = 4;
    result = leetCode.longestPalindromicSubsequence(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    s = "wehzr";
    k = 3;
    result = leetCode.longestPalindromicSubsequence(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    s = "nyjejp";
    k = 8;
    result = leetCode.longestPalindromicSubsequence(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode3473(void)
{
    Logger::WriteMessage("Test Leet Code 3473");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, -1, 3, 3, 4 };
    int k = 2, m = 2;
    int result = leetCode.maxSum(nums, k, m);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; m = " + to_string(m));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -10,3,-1,-2 };
    k = 4, m = 1;
    result = leetCode.maxSum(nums, k, m);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; m = " + to_string(m));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,5 };
    k = 4, m = 1;
    result = leetCode.maxSum(nums, k, m);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; m = " + to_string(m));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3489(void)
{
    Logger::WriteMessage("Test Leet Code 3489");
    LeetCodeDP leetCode;
    vector<int> nums = { 2, 0, 2 };
    vector<vector<int>> queries = { {0, 2, 1},{0, 2, 1},{1, 1, 3} };
    int result = leetCode.minZeroArrayIV(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,3,2,1 };
    queries = { {1, 3, 2},{0, 2, 1} };
    result = leetCode.minZeroArrayIV(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,2,1 };
    queries = { {0, 1, 1},{1, 2, 1},{2, 3, 2},{3, 4, 1},{4, 4, 1} };
    result = leetCode.minZeroArrayIV(nums, queries);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3494(void)
{
    Logger::WriteMessage("Test Leet Code 3494");
    LeetCodeDP leetCode;
    vector<int> skill = { 1, 5, 2, 4 };
    vector<int> mana = { 5, 1, 4, 2 };
    long long result = leetCode.minTime(skill, mana);
    Logger::WriteMessage(skill);
    Logger::WriteMessage(mana);
    Logger::WriteMessage("result = " + to_string(result));

    skill = { 1, 1, 1 };
    mana = { 1, 1, 1 };
    result = leetCode.minTime(skill, mana);
    Logger::WriteMessage(skill);
    Logger::WriteMessage(mana);
    Logger::WriteMessage("result = " + to_string(result));

    skill = { 1,2,3,4 };
    mana = { 1,2 };
    result = leetCode.minTime(skill, mana);
    Logger::WriteMessage(skill);
    Logger::WriteMessage(mana);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3509(void)
{
    Logger::WriteMessage("Test Leet Code 3509");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3 };
    int k = 2, limit = 10;
    int result = leetCode.maxProduct(nums, k, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; limit = " + to_string(limit));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0,2,3 };
    k = -5, limit = 12;
    result = leetCode.maxProduct(nums, k, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; limit = " + to_string(limit));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, 2, 3, 3 };
    k = 0, limit = 9;
    result = leetCode.maxProduct(nums, k, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; limit = " + to_string(limit));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0 };
    k = 0;
    limit = 10;
    result = leetCode.maxProduct(nums, k, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; limit = " + to_string(limit));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0, 8 };
    k = -8;
    limit = 20;
    result = leetCode.maxProduct(nums, k, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; limit = " + to_string(limit));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 10,10,9,0 };
    k = 1;
    limit = 20;
    result = leetCode.maxProduct(nums, k, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; limit = " + to_string(limit));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 12, 0, 9 };
    k = 21;
    limit = 20;
    result = leetCode.maxProduct(nums, k, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; limit = " + to_string(limit));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,10,0,9 };
    k = 1;
    limit = 20;
    result = leetCode.maxProduct(nums, k, limit);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; limit = " + to_string(limit));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3524(void)
{
    Logger::WriteMessage("Test Leet Code 3524");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    int k = 3;
    vector<long long> result = leetCode.resultArrayI(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) );
    Logger::WriteMessage(result);

    nums = { 1,2,4,8,16,32 };
    k = 4;
    result = leetCode.resultArrayI(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    nums = { 1, 1, 2, 1, 1 };
    k = 2;
    result = leetCode.resultArrayI(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}


void TestLeetCode3557(void)
{
    Logger::WriteMessage("Test Leet Code 3557");
    LeetCodeDP leetCode;
    string word = "abcdeafdef";
    int result = leetCode.maxSubstrings(word);
    Logger::WriteMessage("word = " + word);
    Logger::WriteMessage("result = " + to_string(result));

    word = "bcdaaaab";
    result = leetCode.maxSubstrings(word);
    Logger::WriteMessage("word = " + word);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode3578(void)
{
    Logger::WriteMessage("Test Leet Code 3578");
    LeetCodeDP leetCode;
    vector<int> nums = { 9, 4, 1, 3, 7 };
    int k = 4;
    int result = leetCode.countPartitionsII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 3,3,4 };
    k = 0;
    result = leetCode.countPartitionsII(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3573(void)
{
    Logger::WriteMessage("Test Leet Code 3573");
    LeetCodeDP leetCode;
    vector<int> prices = { 1, 7, 9, 8, 2 };
    int k = 2;
    long long result = leetCode.maximumProfit(prices, k);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    prices = { 12,16,19,19,8,1,19,13,9 };
    k = 3;
    result = leetCode.maximumProfit(prices, k);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3592(void)
{
    Logger::WriteMessage("Test Leet Code 3592");
    LeetCodeDP leetCode;
    vector<int> numWays = { 0, 1, 0, 2, 0, 3, 0, 4, 0, 5 };
    vector<int> result = leetCode.findCoins(numWays);
    Logger::WriteMessage(numWays);
    Logger::WriteMessage(result);

    numWays = { 1,2,2,3,4 };
    result = leetCode.findCoins(numWays);
    Logger::WriteMessage(numWays);
    Logger::WriteMessage(result);

    numWays = { 1,2,3,4,15 };
    result = leetCode.findCoins(numWays);
    Logger::WriteMessage(numWays);
    Logger::WriteMessage(result);
}

void TestLeetCode3599(void)
{
    Logger::WriteMessage("Test Leet Code 3599");
    LeetCodeDP leetCode;
    vector<int> nums = { 1, 2, 3 };
    int k = 2;
    int result = leetCode.minXor(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2,3,3,2 };
    k = 3;
    result = leetCode.minXor(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,1,2,3,1 };
    k = 2;
    result = leetCode.minXor(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3610(void)
{
    Logger::WriteMessage("Test Leet Code 3610");
    LeetCodeDP leetCode;
    int n = 10, m = 2;
    int result = leetCode.minNumberOfPrimes(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m));
    Logger::WriteMessage("result = " + to_string(result));

    n = 15, m = 5;
    result = leetCode.minNumberOfPrimes(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m));
    Logger::WriteMessage("result = " + to_string(result));

    n = 7, m = 6;
    result = leetCode.minNumberOfPrimes(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3603(void)
{
    Logger::WriteMessage("Test Leet Code 3603");
    LeetCodeDP leetCode;
    int m = 1, n = 2;
    vector<vector<int>> waitCost = { {1, 2} };
    long long result = leetCode.minCost(m, n, waitCost);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage(waitCost);
    Logger::WriteMessage("result = " + to_string(result));

    m = 2, n = 2;
    waitCost = { {3, 5},{2, 4} };
    result = leetCode.minCost(m, n, waitCost);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage(waitCost);
    Logger::WriteMessage("result = " + to_string(result));

    m = 2, n = 3;
    waitCost = { {6, 1, 4},{3, 2, 5} };
    result = leetCode.minCost(m, n, waitCost);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage(waitCost);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCodeDP(void)
{
    TestLeetCode3603();
    TestLeetCode3610();
    TestLeetCode3599();
    TestLeetCode3592();
    TestLeetCode3573();
    TestLeetCode3578();
    TestLeetCode3557();
    TestLeetCode3524();
    TestLeetCode3509();
    TestLeetCode3494();
    TestLeetCode3489();
    TestLeetCode3473();
    TestLeetCode3472();
    TestLeetCode3466();
    TestLeetCode3469();
    TestLeetCode3441();
    TestLeetCode3429();
    TestLeetCode3418();
    TestLeetCode3414();
    TestLeetCode3393();
    TestLeetCode3388();
    TestLeetCode3363();
    TestLeetCode3366();
    TestLeetCode3339();
    TestLeetCode3336();
    TestLeetCode3332();
    TestLeetCode3320();
    TestLeetCode3316();
    TestLeetCode3302();
    TestLeetCode3290();
    TestLeetCode3287();
    TestLeetCode3277();
    TestLeetCode3269();
    TestLeetCode3259();
    TestLeetCode3250();
    TestLeetCode3247();
    TestLeetCode3202();
    TestLeetCode3201();
    TestLeetCode3193();
    TestLeetCode3196();
    TestLeetCode3186();
    TestLeetCode3180();
    TestLeetCode3177();
    TestLeetCode3176();
    TestLeetCode3144();
    TestLeetCode3147();
    TestLeetCode3135();
    TestLeetCode3130();
    TestLeetCode3129();
    TestLeetCode3117();
    TestLeetCode3122();
    TestLeetCode3077();
    TestLeetCode3082();
    TestLeetCode3070();
    TestLeetCode87();
    TestLeetCode3041();
    TestLeetCode377();
    TestLeetCode416();
    TestLeetCode518();
    TestLeetCode3003();
    TestLeetCode801();
    TestLeetCode2969();
    TestLeetCode2944();
    TestLeetCode2919();
    TestLeetCode2915();
    TestLeetCode2896();
    TestLeetCode2826();
    TestLeetCode2809();
    TestLeetCode2786();
    TestLeetCode2771();
    TestLeetCode2770();
    TestLeetCode2767();
    TestLeetCode2742();
    TestLeetCode2712();
    TestLeetCode2707();
    TestLeetCode2638();
    TestLeetCode2585();
    TestLeetCode2547();
    TestLeetCode2533();
    TestLeetCode2430();
    TestLeetCode2518();
    TestLeetCode2510();
    TestLeetCode2463();
    TestLeetCode2472();
    TestLeetCode2501();
    TestLeetCode2466();
    TestLeetCode2464();
    TestLeetCode2478();
    TestLeetCode2484();
    TestLeetCode2495();
    TestLeetCode2435();
    TestLeetCode2431();
    TestLeetCode2400();
    TestLeetCode2370();
    TestLeetCode2369();
    TestLeetCode2361();
    TestLeetCode2318();
    TestLeetCode2320();
    TestLeetCode2312();
    TestLeetCode2291();
    TestLeetCode2266();
    TestLeetCode2267();
    TestLeetCode2263II();
    TestLeetCode2209();
    TestLeetCode2222();
    TestLeetCode2218();
    TestLeetCode2188();
    TestLeetCode2184();
    TestLeetCode2167();
    TestLeetCode2143();
    TestLeetCode2140();
    TestLeetCode1049();
    TestLeetCode940();
    TestLeetCode935();
    TestLeetCode931();
    TestLeetCode903();
    TestLeetCode898();
    TestLeetCode880();
    TestLeetCode887();
    TestLeetCode877();
    TestLeetCode873();
    TestLeetCode837();
    TestLeetCode834();
    TestLeetCode828();
    TestLeetCode823();
    TestLeetCode813();
    TestLeetCode808();
    TestLeetCode799();
    TestLeetCode793();
    TestLeetCode795();
    TestLeetCode790();
    TestLeetCode788();
    TestLeetCode764();
    TestLeetCode746();
    TestLeetCode740();
    TestLeetCode712();
    TestLeetCode730();
    TestLeetCode727();
    TestLeetCode714();
    TestLeetCode718();
    TestLeetCode689();
    TestLeetCode688();
    TestLeetCode664();
    TestLeetCode660();
    TestLeetCode2044();
    TestLeetCode2052();
    TestLeetCode161();
    TestLeetCode97();
    TestLeetCode902();
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
    TestLeetCode982();
    TestLeetCode1062();
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
    TestLeetCode983();
    TestLeetCode486();
    TestLeetCode312();
    TestLeetCode516();
    TestLeetCode361();
    TestLeetCode1035();
    TestLeetCode132();
    TestLeetCode1320();
    TestLeetCode1139();
    TestLeetCode1187();
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
    TestLeetCode474();
    TestLeetCode923();
    TestLeetCode920();
    TestLeetCode629();
    TestLeetCode514();
    TestLeetCode264();
    TestLeetCode313();
    TestLeetCode651();
    TestLeetCode650();
    TestLeetCode647();
    TestLeetCode639();
    TestLeetCode403();
    TestLeetCode634();
    TestLeetCode583();
    TestLeetCode375();
    TestLeetCode484();
    TestLeetCode552();
    TestLeetCode45();
    TestLeetCode576();
    TestLeetCode91();
    TestLeetCode322();
    TestLeetCode118();
    TestLeetCode119();
    TestLeetCode213();
    TestLeetCode9905();
    TestLeetCode494();
    TestLeetCode562();
    TestLeetCode879();
    TestLeetCode1143();
    TestLeetCode1147();
    TestLeetCode1155();
    TestLeetCode1092();
    TestLeetCode1039();
    TestLeetCode1048();
    TestLeetCode1043();
    TestLeetCode1027();
    TestLeetCode1025();
    TestLeetCode1031();
    TestLeetCode978();
    TestLeetCode975();
    TestLeetCode960();
    TestLeetCode956();
    TestLeetCode741();
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
    TestLeetCode45();
    TestLeetCode55();
    TestLeetCode5();
}
