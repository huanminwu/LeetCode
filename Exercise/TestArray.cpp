#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeArray.h"
#include "TestArray.h"
void TestLeetCode364(void)
{
    Logger::WriteMessage("Test Leet Code 364");
    LeetCodeArray leetCode;
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
    int depthSum = leetCode.depthSumInverse(input);
    Logger::WriteMessage("Depth Sum = " + to_string(depthSum));

    n1.clear();
    n1.push_back(6);
    n3.clear();
    n3.push_back(4);
    n3.push_back(n1);
    input.clear();
    input.push_back(1);
    input.push_back(n3);
    depthSum = leetCode.depthSumInverse(input);
    Logger::WriteMessage("Depth Sum = " + to_string(depthSum));
}

void TestLeetCode1198(void)
{
    Logger::WriteMessage("Test Leet Code 1198");
    LeetCodeArray leetCode;
    vector<vector<int>> mat =
    {
        {1, 2, 3, 4, 5}, {2, 4, 5, 8, 10}, {3, 5, 7, 9, 11}, {1, 3, 6, 7, 9}
    };
    int result = leetCode.smallestCommonElement(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));

    mat =
    {
        {1, 2, 3, 4, 5}, {2, 4, 5, 8, 10}, {3, 5, 7, 9, 11}, {1, 3, 5, 7, 9}
    };
    result = leetCode.smallestCommonElement(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1208(void)
{
    Logger::WriteMessage("Test Leet Code 1208");
    LeetCodeArray leetCode;
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    int result = leetCode.equalSubstring(s, t, maxCost);
    Logger::WriteMessage("s = " + s + "; t = " + t +
        "; maxCost = " + to_string(maxCost) + "; result = " + to_string(result));

    s = "abcd";
    t = "cdef";
    maxCost = 3;
    result = leetCode.equalSubstring(s, t, maxCost);
    Logger::WriteMessage("s = " + s + "; t = " + t +
        "; maxCost = " + to_string(maxCost) + "; result = " + to_string(result));

    s = "abcd";
    t = "acde";
    maxCost = 0;
    result = leetCode.equalSubstring(s, t, maxCost);
    Logger::WriteMessage("s = " + s + "; t = " + t +
        "; maxCost = " + to_string(maxCost) + "; result = " + to_string(result));
}

void TestLeetCode1221(void)
{
    Logger::WriteMessage("Test Leet Code 1221");
    LeetCodeArray leetCode;
    string s = "RLRRLLRLRL";
    int result = leetCode.balancedStringSplit(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "RLLLLRRRLR";
    result = leetCode.balancedStringSplit(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "LLLLRRRR";
    result = leetCode.balancedStringSplit(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1222(void)
{
    Logger::WriteMessage("Test Leet Code 1222");
    LeetCodeArray leetCode;
    vector<vector<int>> queens = { {0, 1},{1, 0},{4, 0},{0, 4},{3, 3},{2, 4} };
    vector<int> king = { 0, 0 };
    vector<vector<int>> result = leetCode.queensAttacktheKing(queens, king);
    Logger::WriteMessage(queens);
    Logger::WriteMessage(king);
    Logger::WriteMessage(result);

    queens = { {0, 0},{1, 1},{2, 2},{3, 4},{3, 5},{4, 4},{4, 5} };
    king = { 3,3 };
    result = leetCode.queensAttacktheKing(queens, king);
    Logger::WriteMessage(queens);
    Logger::WriteMessage(king);
    Logger::WriteMessage(result);

    queens = 
    { 
        {5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},
        {0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},
        {2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}
    };
    king = { 3,4 };
    result = leetCode.queensAttacktheKing(queens, king);
    Logger::WriteMessage(queens);
    Logger::WriteMessage(king);
    Logger::WriteMessage(result);
}

void TestLeetCode1228(void)
{
    Logger::WriteMessage("Test Leet Code 1228");
    LeetCodeArray leetCode;
    vector<int> arr = { 5, 7, 11, 13 };
    int result = leetCode.missingNumber(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 15,13,12 };
    result = leetCode.missingNumber(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode53(void)
{
    Logger::WriteMessage("Test Leet Code 53");
    LeetCodeArray leetCode;
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    Logger::WriteMessage(nums);
    int amount = leetCode.maxSubArray(nums);
    Logger::WriteMessage("The maximum subarray is " + to_string(amount));
}

void TestLeetCode134(void)
{
    Logger::WriteMessage("Test Leet Code 145");
    LeetCodeArray leetCode;
    string message;
    vector<int> gas = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };
    Logger::WriteMessage("Gas:");
    Logger::WriteMessage(gas);
    Logger::WriteMessage("Cost:");
    Logger::WriteMessage(cost);
    int startIndex = leetCode.canCompleteCircuit(gas, cost);
    Logger::WriteMessage("StartIndex:" + to_string(startIndex));
    gas = { 2, 4 };
    cost = { 3, 4 };
    Logger::WriteMessage("Gas:");
    Logger::WriteMessage(gas);
    Logger::WriteMessage("Cost:");
    Logger::WriteMessage(cost);
    startIndex = leetCode.canCompleteCircuit(gas, cost);
    Logger::WriteMessage("StartIndex:" + to_string(startIndex));
}

void TestLeetCode152(void)
{
    Logger::WriteMessage("Test Leet Code 152");
    LeetCodeArray leetCode;
    vector<int> nums;
    int product;
    nums = { 2, -5, -2, -4, 3 };
    Logger::WriteMessage(nums);
    product = leetCode.maxProduct(nums);
    Logger::WriteMessage("The maximum product is " + to_string(product));
    nums = { 2,3,-2,4 };
    Logger::WriteMessage(nums);
    product = leetCode.maxProduct(nums);
    Logger::WriteMessage("The maximum product is " + to_string(product));
    nums = { -1,-1 };
    Logger::WriteMessage(nums);
    product = leetCode.maxProduct(nums);
    Logger::WriteMessage("The maximum product is " + to_string(product));
    nums = { 3, -1, 4 };
    Logger::WriteMessage(nums);
    product = leetCode.maxProduct(nums);
    Logger::WriteMessage("The maximum product is " + to_string(product));
}

void TestLeetCode325(void)
{
    Logger::WriteMessage("Test Leet Code 325");
    LeetCodeArray leetCode;
    vector<int> nums = { 1, -1, 5, -2, 3 };
    int k = 3;
    int max_length = leetCode.maxSubArrayLen(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; max_length = " + to_string(max_length));

    nums = { -2, -1, 2, 1 };
    k = 1;
    max_length = leetCode.maxSubArrayLen(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; max_length = " + to_string(max_length));
}

void TestLeetCode523(void)
{
    Logger::WriteMessage("Test Leet Code 523");
    LeetCodeArray leetCode;
    vector<int> nums = { 23, 2, 4, 6, 7 };
    int k = 6;
    bool result = leetCode.checkSubarraySum(nums, k);
    Logger::WriteMessage("k = " + to_string(k) + "; continuous subarray sum = " + (string)(result ? "true" : "false"));

    nums = { 23, 2, 4, 6, 7 };
    k = 42;
    result = leetCode.checkSubarraySum(nums, k);
    Logger::WriteMessage("k = " + to_string(k) + "; continuous subarray sum = " + (string)(result ? "true" : "false"));
}

void TestLeetCode525(void)
{
    Logger::WriteMessage("Test Leet Code 525");
    LeetCodeArray leetCode;
    vector<int> nums = { 0, 1 };
    int max_length = leetCode.findMaxLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("max_length = " + to_string(max_length));

    nums = { 0, 1, 0 };
    max_length = leetCode.findMaxLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("max_length = " + to_string(max_length));

    nums = { 0, 0, 1, 0, 0, 1 };
    max_length = leetCode.findMaxLength(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("max_length = " + to_string(max_length));
}

void TestLeetCode560(void)
{
    LeetCodeArray leetCode;
    vector<int> nums = { 1,1,1 };
    int k = 2;
    int count = leetCode.subarraySum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("count of sum (" + to_string(k) + ") = " + to_string(count));
}

void TestLeetCode930(void)
{
    Logger::WriteMessage("Test Leet Code 930");
    LeetCodeArray leetCode;
    vector<int> A = { 1, 0, 1, 0, 1 };
    int S = 2;
    int result = leetCode.numSubarraysWithSum(A, S);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0, 0, 0, 0, 0 };
    S = 0;
    result = leetCode.numSubarraysWithSum(A, S);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode974(void)
{
    Logger::WriteMessage("Test Leet Code 974");
    LeetCodeArray leetCode;
    vector<int> A = { -3, 3, 7, 4, 6 };
    int K = 10;
    int result = leetCode.subarraysDivByK(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { 4,5,0,-2,-3,1 };
    K = 5;
    result = leetCode.subarraysDivByK(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    A = { -1, 2, 9 };
    K = 2;
    result = leetCode.subarraysDivByK(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode1243(void)
{
    Logger::WriteMessage("Test Leet Code 1243");
    LeetCodeArray leetCode;
    vector<int> arr = { 6, 2, 3, 4 };
    vector<int> result = leetCode.transformArray(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 1,6,3,4,3,5 };
    result = leetCode.transformArray(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);
}

void TestLeetCode1248(void)
{
    Logger::WriteMessage("Test Leet Code 1248");
    LeetCodeArray leetCode;
    vector<int> nums = { 1,1,2,1,1 };
    int k = 3;
    int result = leetCode.numberOfSubarrays(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2,4,6 };
    k = 1;
    result = leetCode.numberOfSubarrays(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2, 2, 2, 1, 2, 2, 1, 2, 2, 2 };
    k = 2;
    result = leetCode.numberOfSubarrays(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode41(void)
{
    Logger::WriteMessage("Test Leet Code 41");
    LeetCodeArray leetCode;
    vector<int> nums = { 3, 4, -1, 1 };
    int missingPositive = leetCode.firstMissingPositive(nums);
    Logger::WriteMessage(nums);
    string message;
    message.assign("The first missing positive is :").append(to_string(missingPositive));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode48(void)
{
    Logger::WriteMessage("Test Leet Code 48");
    LeetCodeArray leetCode;
    vector<vector<int>> matrix =
    {
        { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 }, { 13,14,15,16 }
    };
    for (size_t i = 0; i < matrix.size(); i++)
    {
        Logger::WriteMessage(matrix[i]);
    }
    leetCode.rotate(matrix);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        Logger::WriteMessage(matrix[i]);
    }
}

void TestLeetCode54(void)
{
    Logger::WriteMessage("Test Leet Code 54");
    LeetCodeArray leetCode;
    vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    for (size_t i = 0; i < matrix.size(); i++)
    {
        Logger::WriteMessage(matrix[i]);
    }
    vector<int> result = leetCode.spiralOrder(matrix);
    Logger::WriteMessage(result);

    matrix = {};
    for (size_t i = 0; i < matrix.size(); i++)
    {
        Logger::WriteMessage(matrix[i]);
    }
    result = leetCode.spiralOrder(matrix);
    Logger::WriteMessage(result);

    matrix = { {1,2,3} };
    for (size_t i = 0; i < matrix.size(); i++)
    {
        Logger::WriteMessage(matrix[i]);
    }
    result = leetCode.spiralOrder(matrix);
    Logger::WriteMessage(result);
}

void TestLeetCode59(void)
{
    Logger::WriteMessage("Test Leet Code 59");
    LeetCodeArray leetCode;
    vector<vector<int>> result;
    int n = 3;
    Logger::WriteMessage("n =" + to_string(n));
    result = leetCode.generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        Logger::WriteMessage(result[i]);
    }

    n = 1;
    Logger::WriteMessage("n =" + to_string(n));
    result = leetCode.generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        Logger::WriteMessage(result[i]);
    }
}

void TestLeetCode287(void)
{
    Logger::WriteMessage("Test Leet Code 287");
    LeetCodeArray leetCode;
    vector<int> nums = { 1,3,4,2,2 };
    int result = leetCode.findDuplicate(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result =" + to_string(result));

    nums = { 3,1,3,4,2 };
    result = leetCode.findDuplicate(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result =" + to_string(result));
}

void TestLeetCode229(void)
{
    Logger::WriteMessage("Test Leet Code 229");
    LeetCodeArray leetCode;
    vector<int> nums = { 1, 2, 2, 3, 2, 1, 1, 3 };
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.majorityElementII(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode169(void)
{
    Logger::WriteMessage("Test Leet Code 169");
    LeetCodeArray leetCode;
    vector<int> nums = { 1, 2, 2, 2, 3 };
    Logger::WriteMessage(nums);
    int major_element = leetCode.majorityElement(nums);
    Logger::WriteMessage("The major element is " + to_string(major_element));
}

void TestLeetCode1252(void)
{
    Logger::WriteMessage("Test Leet Code 1252");
    LeetCodeArray leetCode;
    int n = 2;
    int m = 3;
    vector<vector<int>> indices = { {0, 1},{1, 1} };
    int result = leetCode.oddCells(n, m, indices);
    Logger::WriteMessage(indices);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 2;
    m = 2;
    indices = { {1, 1},{0, 0} };
    result = leetCode.oddCells(n, m, indices);
    Logger::WriteMessage(indices);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));
}

void TestLeetCode1253(void)
{
    Logger::WriteMessage("Test Leet Code 1253");
    LeetCodeArray leetCode;
    int upper = 2;
    int lower = 1;
    vector<int> colsum = { 1, 1, 1 };
    vector<vector<int>> result = leetCode.reconstructMatrix(upper, lower, colsum);
    Logger::WriteMessage(colsum);
    Logger::WriteMessage("upper = " + to_string(upper) + "; lower = " + to_string(lower));
    Logger::WriteMessage(result);

    upper = 2;
    lower = 3;
    colsum = { 2, 2, 1, 1 };
    result = leetCode.reconstructMatrix(upper, lower, colsum);
    Logger::WriteMessage(colsum);
    Logger::WriteMessage("upper = " + to_string(upper) + "; lower = " + to_string(lower));
    Logger::WriteMessage(result);

    upper = 5;
    lower = 5;
    colsum = { 2,1,2,0,1,0,1,2,0,1 };
    result = leetCode.reconstructMatrix(upper, lower, colsum);
    Logger::WriteMessage(colsum);
    Logger::WriteMessage("upper = " + to_string(upper) + "; lower = " + to_string(lower));
    Logger::WriteMessage(result);
}

void TestLeetCode1260(void)
{
    Logger::WriteMessage("Test Leet Code 1260");
    LeetCodeArray leetCode;
    vector<vector<int>> grid = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    int k = 1;
    vector<vector<int>> result = leetCode.shiftGrid(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    grid = { {3, 8, 1, 9},{19, 7, 2, 5},{4, 6, 11, 10},{12, 0, 21, 13} };
    k = 4;
    result = leetCode.shiftGrid(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    grid = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    k = 9;
    result = leetCode.shiftGrid(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode1267(void)
{
    Logger::WriteMessage("Test Leet Code 1267");
    LeetCodeArray leetCode;
    vector<vector<int>> grid = { {1, 0},{0, 1} };
    int result = leetCode.countServers(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
 
    grid = { {1, 0},{1, 1} };
    result = leetCode.countServers(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 1, 0, 0},{0, 0, 1, 0},{0, 0, 1, 0},{0, 0, 0, 1} };
    result = leetCode.countServers(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1275(void)
{
    Logger::WriteMessage("Test Leet Code 1275");
    LeetCodeArray leetCode;
    vector<vector<int>>  moves = { {0, 0},{2, 0},{1, 1},{2, 1},{2, 2} };
    string result = leetCode.tictactoe(moves);
    Logger::WriteMessage(moves);
    Logger::WriteMessage("result = " + result);

    moves = { {0, 0},{1, 1},{0, 1},{0, 2},{1, 0},{2, 0} };
    result = leetCode.tictactoe(moves);
    Logger::WriteMessage(moves);
    Logger::WriteMessage("result = " + result);

    moves = { {0, 0},{1, 1},{2, 0},{1, 0},{1, 2},{2, 1},{0, 1},{0, 2},{2, 2} };
    result = leetCode.tictactoe(moves);
    Logger::WriteMessage(moves);
    Logger::WriteMessage("result = " + result);

    moves = { {0, 0},{1, 1} };
    result = leetCode.tictactoe(moves);
    Logger::WriteMessage(moves);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode1282(void)
{
    Logger::WriteMessage("Test Leet Code 1282");
    LeetCodeArray leetCode;
    vector<int> groupSizes = { 3, 3, 3, 3, 3, 1, 3 };
    vector<vector<int>> result = leetCode.groupThePeople(groupSizes);
    Logger::WriteMessage(groupSizes);
    Logger::WriteMessage(result);

    groupSizes = { 2,1,3,3,3,2 };
    result = leetCode.groupThePeople(groupSizes);
    Logger::WriteMessage(groupSizes);
    Logger::WriteMessage(result);
}

void TestLeetCode1287(void)
{
    Logger::WriteMessage("Test Leet Code 1287");
    LeetCodeArray leetCode;
    vector<int> arr = { 1,2,2,6,6,6,6,7,10 };
    int result = leetCode.findSpecialInteger(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1292(void)
{
    Logger::WriteMessage("Test Leet Code 1292");
    LeetCodeArray leetCode;
    vector<vector<int>> mat = 
    { 
        {1, 1, 3, 2, 4, 3, 2},
        {1, 1, 3, 2, 4, 3, 2},
        {1, 1, 3, 2, 4, 3, 2} 
    };
    int threshold = 4;
    int result = leetCode.maxSideLength(mat, threshold);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));

    mat =
    {
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2}
    };
    threshold = 1;
    result = leetCode.maxSideLength(mat, threshold);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));

    mat =
    {
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    threshold = 6;
    result = leetCode.maxSideLength(mat, threshold);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));

    mat =
    {
        {18, 70},
        {61, 1},
        {25, 85},
        {14, 40},
        {11, 96},
        {97, 96},
        {63, 45}
    };
    threshold = 40184;
    result = leetCode.maxSideLength(mat, threshold);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));
}

void TestLeetCode1296(void)
{
    Logger::WriteMessage("Test Leet Code 1296");
    LeetCodeArray leetCode;
    vector<int> nums = { 1, 2, 3, 3, 4, 4, 5, 6 };
    int k = 4;
    bool result = leetCode.isPossibleDivide(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    nums = { 3,2,1,2,3,4,3,4,5,9,10,11 };
    k = 3;
    result = leetCode.isPossibleDivide(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 3,3,2,2,1,1 };
    k = 3;
    result = leetCode.isPossibleDivide(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,2,3,4 };
    k = 3;
    result = leetCode.isPossibleDivide(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1299(void)
{
    Logger::WriteMessage("Test Leet Code 1299");
    LeetCodeArray leetCode;    
    vector<int> arr = { 17, 18, 5, 4, 6, 1 };
    int k = 4;
    vector<int> result = leetCode.replaceElements(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);
}

void TestLeetCode1306(void)
{
    Logger::WriteMessage("Test Leet Code 1306");
    LeetCodeArray leetCode;
    vector<int> arr = { 4, 2, 3, 0, 3, 1, 2 };
    int start = 5;
    Logger::WriteMessage(arr);
    bool result = leetCode.canReach(arr, start);
    Logger::WriteMessage("start = " + to_string(start) + "; result = " + (string)(result? "true" : "false"));

    arr = { 4, 2, 3, 0, 3, 1, 2 };
    start = 0;
    Logger::WriteMessage(arr);
    result = leetCode.canReach(arr, start);
    Logger::WriteMessage("start = " + to_string(start) + "; result = " + (string)(result ? "true" : "false"));

    arr = { 3,0,2,1,2 };
    start = 2;
    Logger::WriteMessage(arr);
    result = leetCode.canReach(arr, start);
    Logger::WriteMessage("start = " + to_string(start) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode448(void)
{
    Logger::WriteMessage("Test Leet Code 448");
    LeetCodeArray leetCode;
    vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.findDisappearedNumbers(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode36(void)
{
    Logger::WriteMessage("Test Leet Code 36");
    LeetCodeArray leetCode;
    vector<vector<char>> board =
    {
        { '5','3','.','.','7','.','.','.','.' },{ '6','.','.','1','9','5','.','.','.' },
        { '.','9','8','.','.','.','.','6','.' },{ '8','.','.','.','6','.','.','.','3' },
        { '4','.','.','8','.','3','.','.','1' },{ '7','.','.','.','2','.','.','.','6' },
        { '.','6','.','.','.','.','2','8','.' },{ '.','.','.','4','1','9','.','.','5' },
        { '.','.','.','.','8','.','.','7','9' }
    };
    Logger::WriteMessage(board);

    bool result = leetCode.isValidSudoku(board);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    board =
    {
        { '8','3','.','.','7','.','.','.','.' },{ '6','.','.','1','9','5','.','.','.' },
        { '.','9','8','.','.','.','.','6','.' },{ '8','.','.','.','6','.','.','.','3' },
        { '4','.','.','8','.','3','.','.','1' },{ '7','.','.','.','2','.','.','.','6' },
        { '.','6','.','.','.','.','2','8','.' },{ '.','.','.','4','1','9','.','.','5' },
        { '.','.','.','.','8','.','.','7','9' }
    };
    Logger::WriteMessage(board);

    result = leetCode.isValidSudoku(board);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1310(void)
{
    Logger::WriteMessage("Test Leet Code 1310");
    LeetCodeArray leetCode;
    vector<int> arr = { 1, 3, 4, 8 };
    vector<vector<int>>queries = { {0, 1},{1, 2},{0, 3},{3, 3} };
    vector<int> result = leetCode.xorQueries(arr, queries);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    arr = { 4,8,2,10 };
    queries = { {2, 3},{1, 3},{0, 0},{0, 3} };
    result = leetCode.xorQueries(arr, queries);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCodeArray(void)
{
    TestLeetCode1310();
    TestLeetCode36();
    TestLeetCode448();
    TestLeetCode1306();
    TestLeetCode1299();
    TestLeetCode1296();
    TestLeetCode1292();
    TestLeetCode1287();
    TestLeetCode1282();
    TestLeetCode1275();
    TestLeetCode1267();
    TestLeetCode1260();
    TestLeetCode1253();
    TestLeetCode1252();
    TestLeetCode169();
    TestLeetCode229();
    TestLeetCode287();
    TestLeetCode59();
    TestLeetCode41();
    TestLeetCode48();
    TestLeetCode54();
    TestLeetCode1248();
    TestLeetCode1243();
    TestLeetCode974();
    TestLeetCode930();
    TestLeetCode560();
    TestLeetCode525();
    TestLeetCode523();
    TestLeetCode325();
    TestLeetCode152();
    TestLeetCode53();
    TestLeetCode134();
    TestLeetCode1228();
    TestLeetCode1222();
    TestLeetCode1221();
    TestLeetCode1198();
    TestLeetCode1208();
    TestLeetCode1228();
}