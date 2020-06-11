#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeArray.h"
#include "TestArray.h"

void TestLeetCode11(void)
{
    LeetCodeArray leetCode;
    Logger::WriteMessage("Test Leet Code 11");
    string message;
    vector<int> heights = { 2, 6, 7, 8, 3, 1 };
    Logger::WriteMessage(heights);
    int maxArea = leetCode.maxArea(heights);
    message.assign("Max Area = " + to_string(maxArea));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode16(void)
{
    LeetCodeArray leetCode;
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

void TestLeetCode42(void)
{
    Logger::WriteMessage("Test Leet Code 42");
    LeetCodeArray leetCode;
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

void TestLeetCode27(void)
{
    Logger::WriteMessage("Test Leet Code 27");
    LeetCodeArray leetCode;
    vector<int> nums;
    int result;
    nums = { 2, 3, 3, 2 };
    Logger::WriteMessage(nums);
    result = leetCode.removeArrayElement(nums, 3);
    Logger::WriteMessage(nums);
}

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

void TestLeetCode1313(void)
{
    Logger::WriteMessage("Test Leet Code 1313");
    LeetCodeArray leetCode;

    vector<int> nums = { 1, 2, 3, 4 };
    vector<int> result = leetCode.decompressRLElist(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1314(void)
{
    Logger::WriteMessage("Test Leet Code 1314");
    LeetCodeArray leetCode;

    vector<vector<int>> mat = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    int K = 1;
    vector<vector<int>> result = leetCode.matrixBlockSum(mat, K);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(result);

    K = 2;
    result = leetCode.matrixBlockSum(mat, K);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(result);
}

void TestLeetCode413(void)
{
    Logger::WriteMessage("Test Leet Code 413");
    LeetCodeArray leetCode;
    vector<int> nums = { -1, -2, -3 };
    Logger::WriteMessage(nums);
    int count = leetCode.numberOfArithmeticSlices(nums);
    Logger::WriteMessage("Number Of Arithmetic Slices = " + to_string(count));
}

void TestLeetCode485(void)
{
    Logger::WriteMessage("Test Leet Code 485");
    LeetCodeArray leetCode;
    vector<int> nums = { 1,1,0,1,1,1 };
    int result = leetCode.findMaxConsecutiveOnes(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Maximum Consecutive Ones = " + to_string(result));
}

void TestLeetCode446(void)
{
    Logger::WriteMessage("Test Leet Code 446");
    LeetCodeArray leetCode;
    vector<int> nums = { 2, 4, 6, 8, 10 };
    int count = leetCode.numberOfArithmeticSlicesII(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The arithmetic slice count = " + to_string(count));
}

void TestLeetCode368(void)
{
    Logger::WriteMessage("Test Leet Code 368");
    LeetCodeArray leetCode;
    vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> result = leetCode.largestDivisibleSubset(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode26(void)
{
    LeetCodeArray leetCode;
    Logger::WriteMessage("Test Leet Code 26");
    vector<int> nums = { 1, 2, 2, 3, 4, 4, 5 };
    Logger::WriteMessage(nums);
    string message;
    int length = leetCode.removeDuplicateSortedArray(nums);
    message.assign("The array lengh without duplicate is: " + length);
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode80(void)
{
    Logger::WriteMessage("Test Leet Code 80");
    LeetCodeArray leetCode;
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    Logger::WriteMessage(nums);
    int size = leetCode.removeDuplicatesII(nums);
    Logger::WriteMessage("New size = " + to_string(size));
    Logger::WriteMessage(nums);
}

void TestLeetCode73(void)
{
    Logger::WriteMessage("Test Leet Code 73");
    LeetCodeArray leetCode;
    vector<vector<int>> matrix = { { 1, 2, 3, 4 },{ 5, 0, 7, 8 },{ 9, 10, 0, 12 },{ 13,14,15,16 } };
    for (size_t i = 0; i < matrix.size(); i++)
    {
        Logger::WriteMessage(matrix[i]);
    }
    leetCode.setZeroes(matrix);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        Logger::WriteMessage(matrix[i]);
    }
}

void TestLeetCode189(void)
{
    Logger::WriteMessage("Test Leet Code 189");
    LeetCodeArray leetCode;
    vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
    int k = 3;
    Logger::WriteMessage(nums);
    leetCode.rotateArray(nums, k);
    Logger::WriteMessage(nums);
}

void TestLeetCode419(void)
{
    Logger::WriteMessage("Test Leet Code 419");
    LeetCodeArray leetCode;
    vector<vector<char>> board =
    {
        { 'X', '.', '.', 'X' },
        { '.', '.', '.', 'X' },
        { '.', '.', '.', 'X' }
    };
    Logger::WriteMessage("Total battle ship = " + to_string(leetCode.countBattleships(board)));
}

void TestLeetCode442(void)
{
    Logger::WriteMessage("Test Leet Code 442");
    LeetCodeArray leetCode;
    vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.findDuplicates(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode243(void)
{
    Logger::WriteMessage("Test Leet Code 243");
    LeetCodeArray leetCode;
    vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
    string word1 = "coding";
    string word2 = "practice";
    int distance = leetCode.shortestDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));

    word1 = "makes";
    word2 = "coding";
    distance = leetCode.shortestDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));
}

void TestLeetCode245(void)
{
    Logger::WriteMessage("Test Leet Code 245");
    LeetCodeArray leetCode;
    vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
    string word1 = "coding";
    string word2 = "practice";
    int distance = leetCode.shortestWordDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));

    word1 = "makes";
    word2 = "coding";
    distance = leetCode.shortestWordDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));

    word1 = "makes";
    word2 = "makes";
    distance = leetCode.shortestWordDistance(words, word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));
}

void TestLeetCode1330(void)
{
    Logger::WriteMessage("Test Leet Code 1330");
    LeetCodeArray leetCode;
    vector<int> nums = { 2, 3, 1, 5, 4 };
    int result = leetCode.maxValueAfterReverse(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,4,9,24,2,1,10 };
    result = leetCode.maxValueAfterReverse(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1329(void)
{
    Logger::WriteMessage("Test Leet Code 1329");
    LeetCodeArray leetCode;
    vector<vector<int>> mat = 
    {
        {3, 3, 1, 1},{2, 2, 1, 2}, {1, 1, 1, 2} 
    };
    vector<vector<int>> result = leetCode.diagonalSort(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage(result);
}

void TestLeetCode1333(void)
{
    Logger::WriteMessage("Test Leet Code 1333");
    LeetCodeArray leetCode;
    vector<vector<int>> restaurants =
    {
        {1,4,1,40,10},{2,8,0,50,5}, {3,8,1,30,4},
        {4,10,0,10,3},{5,1,1,15,1}
    };
    int veganFriendly = 1;
    int maxPrice = 50;
    int maxDistance = 10;
    vector<int> result = leetCode.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);
    Logger::WriteMessage(restaurants);
    Logger::WriteMessage(result);

    restaurants =
    {
        {1,4,1,40,10},{2,8,0,50,5}, {3,8,1,30,4},
        {4,10,0,10,3},{5,1,1,15,1}
    };
    veganFriendly = 0;
    maxPrice = 50;
    maxDistance = 10;
    result = leetCode.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);
    Logger::WriteMessage(restaurants);
    Logger::WriteMessage(result);

    restaurants =
    {
        {1,4,1,40,10},{2,8,0,50,5}, {3,8,1,30,4},
        {4,10,0,10,3},{5,1,1,15,1}
    };
    veganFriendly = 0;
    maxPrice = 30;
    maxDistance = 3;
    result = leetCode.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);
    Logger::WriteMessage(restaurants);
    Logger::WriteMessage(result);
}

void TestLeetCode1337(void)
{
    Logger::WriteMessage("Test Leet Code 1337");
    LeetCodeArray leetCode;
    vector<vector<int>> mat =
    {
        {1,1,0,0,0},{1,1,1,1,0}, {1,0,0,0,0},
        {1,1,0,0,0},{1,1,1,1,1}
    };
    int k = 3;
    vector<int> result = leetCode.kWeakestRows(mat, k);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    mat =
    {
        {1,0,0,0},{1,1,1,1}, {1,0,0,0},
        {1,0,0,0}
    };
    k = 2;
    result = leetCode.kWeakestRows(mat, k);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode1338(void)
{
    Logger::WriteMessage("Test Leet Code 1338");
    LeetCodeArray leetCode;
    vector<int> arr = { 3,3,3,3,5,5,5,2,2,7 };
    int result = leetCode.minSetSize(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 7,7,7,7,7,7 };
    result = leetCode.minSetSize(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,9 };
    result = leetCode.minSetSize(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1000,1000,3,7 };
    result = leetCode.minSetSize(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,2,3,4,5,6,7,8,9,10 };
    result = leetCode.minSetSize(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1343(void)
{
    Logger::WriteMessage("Test Leet Code 1343");
    LeetCodeArray leetCode;
    vector<int> arr = { 2,2,2,2,5,5,5,8 };
    int k = 3;
    int threshold = 4;
    int result = leetCode.numOfSubarrays(arr, k, threshold);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; threshold = " + to_string(threshold) + "; result = " + to_string(result));

    arr = { 1,1,1,1,1 };
    k = 1;
    threshold = 0;
    result = leetCode.numOfSubarrays(arr, k, threshold);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; threshold = " + to_string(threshold) + "; result = " + to_string(result));

    arr = { 11,13,17,23,29,31,7,5,2,3 };
    k = 3;
    threshold = 5;
    result = leetCode.numOfSubarrays(arr, k, threshold);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; threshold = " + to_string(threshold) + "; result = " + to_string(result));

    arr = { 7,7,7,7,7,7,7 };
    k = 7;
    threshold = 7;
    result = leetCode.numOfSubarrays(arr, k, threshold);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; threshold = " + to_string(threshold) + "; result = " + to_string(result));

    arr = { 4,4,4,4 };
    k = 4;
    threshold = 1;
    result = leetCode.numOfSubarrays(arr, k, threshold);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; threshold = " + to_string(threshold) + "; result = " + to_string(result));
}

void TestLeetCode1346(void)
{
    Logger::WriteMessage("Test Leet Code 1346");
    LeetCodeArray leetCode;
    vector<int> arr = { 10,2,5,3 };
    bool result = leetCode.checkIfExist(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));


    arr = { 7,1,14,11 };
    result = leetCode.checkIfExist(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    arr = { 3,1,7,11 };
    result = leetCode.checkIfExist(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1200(void)
{
    Logger::WriteMessage("Test Leet Code 1200");
    LeetCodeArray leetCode;
    vector<int> arr = { 4,2,1,3 };
    vector<vector<int>> result = leetCode.minimumAbsDifference(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 1,3,6,10,15 };
    result = leetCode.minimumAbsDifference(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 3, 8, -10, 23, 19, -4, -14, 27 };
    result = leetCode.minimumAbsDifference(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);
}

void TestLeetCode1191(void)
{
    Logger::WriteMessage("Test Leet Code 1191");
    LeetCodeArray leetCode;
    vector<int> arr = { 1, 2 };
    int k = 3;
    int result = leetCode.kConcatenationMaxSum(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 1, -2, 1 };
    k = 5;
    result = leetCode.kConcatenationMaxSum(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { -1, -2 };
    k = 7;
    result = leetCode.kConcatenationMaxSum(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 1, -1 };
    k = 1;
    result = leetCode.kConcatenationMaxSum(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 2, -3, 3 };
    k = 1;
    result = leetCode.kConcatenationMaxSum(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 2, -3, 3 };
    k = 2;
    result = leetCode.kConcatenationMaxSum(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 2, -3, 3 };
    k = 3;
    result = leetCode.kConcatenationMaxSum(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    arr = { 2, -7, 3 };
    k = 3;
    result = leetCode.kConcatenationMaxSum(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1186(void)
{
    Logger::WriteMessage("Test Leet Code 1186");
    LeetCodeArray leetCode;
    vector<int> arr = { 11, -10, -11, 8, 7, -6, 9, 4, 11, 6, 5, 0 };
    int result = leetCode.maximumSum(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1, -4, -5, -2, 5, 0, -1, 2 };
    result = leetCode.maximumSum(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,-2,0,3 };
    result = leetCode.maximumSum(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,-2,-2,3 };
    result = leetCode.maximumSum(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { -1,-1,-1,-1 };
    result = leetCode.maximumSum(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1184(void)
{
    Logger::WriteMessage("Test Leet Code 1184");
    LeetCodeArray leetCode;
    vector<int> distance = { 1, 2, 3, 4 };
    int start = 0;
    int destination = 1;
    int result = leetCode.distanceBetweenBusStops(distance, start, destination);
    Logger::WriteMessage("start = " + to_string(start) + "; destination = " + to_string(destination) +
        "; result = " + to_string(result));

    start = 0;
    destination = 2;
    distance = { 1, 2, 3, 4 };
    result = leetCode.distanceBetweenBusStops(distance, start, destination);
    Logger::WriteMessage("start = " + to_string(start) + "; destination = " + to_string(destination) +
        "; result = " + to_string(result));

    start = 0;
    destination = 3;
    distance = { 1, 2, 3, 4 };
    result = leetCode.distanceBetweenBusStops(distance, start, destination);
    Logger::WriteMessage("start = " + to_string(start) + "; destination = " + to_string(destination) +
        "; result = " + to_string(result));
}


void TestLeetCode1183(void)
{
    Logger::WriteMessage("Test Leet Code 1183");
    LeetCodeArray leetCode;
    int width = 3;
    int height = 3;
    int sideLength = 2;
    int maxOnes = 1;
    int result = leetCode.maximumNumberOfOnes(width, height, sideLength, maxOnes);
    Logger::WriteMessage("width = " + to_string(width) + "; height = " + to_string(height) +
        "; sideLength = " + to_string(sideLength) + "; maxOnes = " + to_string(maxOnes) +
        "; result = " + to_string(result));

    width = 3;
    height = 3;
    sideLength = 2;
    maxOnes = 2;
    result = leetCode.maximumNumberOfOnes(width, height, sideLength, maxOnes);
    Logger::WriteMessage("width = " + to_string(width) + "; height = " + to_string(height) +
        "; sideLength = " + to_string(sideLength) + "; maxOnes = " + to_string(maxOnes) +
        "; result = " + to_string(result));
}

void TestLeetCode1176(void)
{
    Logger::WriteMessage("Test Leet Code 1176");
    vector<int> calories = { 1, 2, 3, 4, 5 };
    int k = 1;
    int lower = 3;
    int upper = 3;
    LeetCodeArray leetCode;
    int result = leetCode.dietPlanPerformance(calories, k, lower, upper);
    Logger::WriteMessage(calories);
    Logger::WriteMessage("k = " + to_string(k) + "; lower = " + to_string(lower) +
        "; upper = " + to_string(upper) + "; result = " + to_string(result));

    calories = { 3,2 };
    k = 2;
    lower = 0;
    upper = 1;
    result = leetCode.dietPlanPerformance(calories, k, lower, upper);
    Logger::WriteMessage("k = " + to_string(k) + "; lower = " + to_string(lower) +
        "; upper = " + to_string(upper) + "; result = " + to_string(result));

    calories = { 6,5,0,0 };
    k = 2;
    lower = 1;
    upper = 5;
    result = leetCode.dietPlanPerformance(calories, k, lower, upper);
    Logger::WriteMessage("k = " + to_string(k) + "; lower = " + to_string(lower) +
        "; upper = " + to_string(upper) + "; result = " + to_string(result));
}

void TestLeetCode1138(void)
{
    Logger::WriteMessage("Test Leet Code 1138");
    LeetCodeArray leetCode;
    string target = "leet";
    string result = leetCode.alphabetBoardPath(target);
    Logger::WriteMessage("target = " + target + "; result = " + result);

    target = "code";
    result = leetCode.alphabetBoardPath(target);
    Logger::WriteMessage("target = " + target + "; result = " + result);
}

void TestLeetCode1151(void)
{
    Logger::WriteMessage("Test Leet Code 1151");
    LeetCodeArray leetCode;
    vector<int> data = { 1,0,1,0,1 };
    int result = leetCode.minSwaps(data);
    Logger::WriteMessage(data);
    Logger::WriteMessage("result = " + to_string(result));

    data = { 0,0,0,1,0 };
    result = leetCode.minSwaps(data);
    Logger::WriteMessage(data);
    Logger::WriteMessage("result = " + to_string(result));

    data = { 1,0,1,0,1,0,0,1,1,0,1 };
    result = leetCode.minSwaps(data);
    Logger::WriteMessage(data);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1124(void)
{
    Logger::WriteMessage("Test Leet Code 1124");
    LeetCodeArray leetCode;
    vector<int> hours = { 6,6,9 };
    int result = leetCode.longestWPI(hours);
    Logger::WriteMessage(hours);
    Logger::WriteMessage("result = " + to_string(result));

    hours = { 9,9,6,0,6,6,9 };
    result = leetCode.longestWPI(hours);
    Logger::WriteMessage(hours);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1121(void)
{
    Logger::WriteMessage("Test Leet Code 1121");
    LeetCodeArray leetCode;
    vector<int> nums = { 1, 2, 2, 3, 3, 4, 4 };
    int K = 3;
    bool result = leetCode.canDivideIntoSubsequences(nums, K);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + (string)(result ? "true" : "false"));

    nums = { 5,6,6,7,8 };
    K = 3;
    result = leetCode.canDivideIntoSubsequences(nums, K);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1351(void)
{
    Logger::WriteMessage("Test Leet Code 1351");
    LeetCodeArray leetCode;
    vector<vector<int>> grid = 
    {
        {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}
    };
    int result = leetCode.countNegatives(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {3,2},{1,0}
    };
    result = leetCode.countNegatives(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1,-1},{-1,-1}
    };
    result = leetCode.countNegatives(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {-1}
    };
    result = leetCode.countNegatives(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode289(void)
{
    Logger::WriteMessage("Test Leet Code 289");
    LeetCodeArray leetCode;
    vector<vector<int>> board;
    board = { {0,0,0, 0}, {0, 1, 1, 0}, {0,1,1,0}, {0,0,0,0} };
    for (size_t i = 0; i < board.size(); i++)
    {
        Logger::WriteMessage(board[i]);
    }
    Logger::WriteMessage("------------------------------");
    leetCode.gameOfLife(board);
    for (size_t i = 0; i < board.size(); i++)
    {
        Logger::WriteMessage(board[i]);
    }
    Logger::WriteMessage("------------------------------");
    board = { { 0, 0 } };
    for (size_t i = 0; i < board.size(); i++)
    {
        Logger::WriteMessage(board[i]);
    }
    Logger::WriteMessage("------------------------------");
    leetCode.gameOfLife(board);
    for (size_t i = 0; i < board.size(); i++)
    {
        Logger::WriteMessage(board[i]);
    }
}

void TestLeetCode1380(void)
{
    Logger::WriteMessage("Test Leet Code 1380");
    LeetCodeArray leetCode;
    vector<vector<int>> matrix =
    {
        {3, 7, 8},{9, 11, 13},{15, 16, 17}
    };
    vector<int> result = leetCode.luckyNumbers(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);

    matrix =
    {
        {1, 10, 4, 2},{9, 3, 8, 7},{15, 16, 17, 12}
    };
    result = leetCode.luckyNumbers(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);

    matrix =
    {
        {7, 8},{1, 2}
    };
    result = leetCode.luckyNumbers(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);
}

void TestLeetCode1389(void)
{
    Logger::WriteMessage("Test Leet Code 1389");
    LeetCodeArray leetCode;
    vector<int> nums = {0,1,2,3,4};
    vector<int> index = { 0,1,2,2,1 };
    vector<int> result = leetCode.createTargetArray(nums, index);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(index);
    Logger::WriteMessage(result);

    nums = { 1,2,3,4,0 };
    index = { 0,1,2,3,0 };
    result = leetCode.createTargetArray(nums, index);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(index);
    Logger::WriteMessage(result);

    nums = { 1 };
    index = { 0 };
    result = leetCode.createTargetArray(nums, index);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(index);
    Logger::WriteMessage(result);

    nums = { 4, 2, 4, 3, 2 };
    index = { 0, 0, 1, 3, 1 };
    result = leetCode.createTargetArray(nums, index);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(index);
    Logger::WriteMessage(result);
}

void TestLeetCode1395(void)
{
    Logger::WriteMessage("Test Leet Code 1395");
    LeetCodeArray leetCode;
    vector<int> rating = { 2, 5, 3, 4, 1 };
    int result = leetCode.numTeams(rating);
    Logger::WriteMessage("result = " + to_string(result));

    rating = { 2,1,3 };
    result = leetCode.numTeams(rating);
    Logger::WriteMessage("result = " + to_string(result));

    rating = { 1,2,3,4 };
    result = leetCode.numTeams(rating);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1409(void)
{
    Logger::WriteMessage("Test Leet Code 1409");
    LeetCodeArray leetCode;
    vector<int> queries = { 3, 1, 2, 1 };
    int m = 5;
    vector<int> result = leetCode.processQueries(queries, m);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("m = " + to_string(m));
    Logger::WriteMessage(result);

    queries = { 4,1,2,2 };
    m = 4;
    result = leetCode.processQueries(queries, m);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("m = " + to_string(m));
    Logger::WriteMessage(result);

    queries = { 7,5,5,8,3 };
    m = 8;
    result = leetCode.processQueries(queries, m);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("m = " + to_string(m));
    Logger::WriteMessage(result);
}

void TestLeetCode1413(void)
{
    Logger::WriteMessage("Test Leet Code 1413");
    LeetCodeArray leetCode;
    vector<int> nums = { -3, 2, -3, 4, 2 };
    int result = leetCode.minStartValue(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 2 };
    result = leetCode.minStartValue(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,-2,-3 };
    result = leetCode.minStartValue(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1423(void)
{
    Logger::WriteMessage("Test Leet Code 1423");
    LeetCodeArray leetCode;
    vector<int> cardPoints = { 1,2,3,4,5,6,1 };
    int k = 3;
    int result = leetCode.maxScore(cardPoints, k);
    Logger::WriteMessage(cardPoints);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    cardPoints = { 2,2,2 };
    k = 2;
    result = leetCode.maxScore(cardPoints, k);
    Logger::WriteMessage(cardPoints);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    cardPoints = { 9,7,7,9,7,7,9 };
    k = 7;
    result = leetCode.maxScore(cardPoints, k);
    Logger::WriteMessage(cardPoints);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    cardPoints = { 1,1000,1 };
    k = 1;
    result = leetCode.maxScore(cardPoints, k);
    Logger::WriteMessage(cardPoints);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    cardPoints = { 1,79,80,1,1,1,200,1 };
    k = 3;
    result = leetCode.maxScore(cardPoints, k);
    Logger::WriteMessage(cardPoints);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1424(void)
{
    Logger::WriteMessage("Test Leet Code 1424");
    LeetCodeArray leetCode;
    vector<vector<int>> nums = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    vector<int> result = leetCode.findDiagonalOrder(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { {1, 2, 3, 4, 5},{6, 7},{8},{9, 10, 11},{12, 13, 14, 15, 16} };
    result = leetCode.findDiagonalOrder(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { {1, 2, 3},{4},{5, 6, 7},{8},{9, 10, 11} };
    result = leetCode.findDiagonalOrder(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { {1, 2, 3, 4, 5, 6} };
    result = leetCode.findDiagonalOrder(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1431(void)
{
    Logger::WriteMessage("Test Leet Code 1431");
    LeetCodeArray leetCode;
    vector<int> candies = { 2, 3, 5, 1, 3 }; 
    int extraCandies = 3; 
    vector<bool> result = leetCode.kidsWithCandies(candies, extraCandies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(result);

    candies = { 4,2,1,1,2 };
    extraCandies = 1;
    result = leetCode.kidsWithCandies(candies, extraCandies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(result);

    candies = { 12,1,12 };
    extraCandies = 10;
    result = leetCode.kidsWithCandies(candies, extraCandies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(result);

    candies = { 12,1,12 };
    extraCandies = 10;
    result = leetCode.kidsWithCandies(candies, extraCandies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(result);
}

void TestLeetCode1437(void)
{
    Logger::WriteMessage("Test Leet Code 1437");
    LeetCodeArray leetCode;    
    vector<int> nums = { 1, 0, 0, 0, 1, 0, 0, 1 };
    int k = 2;
    bool result = leetCode.kLengthApart(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    nums = { 1,0,0,1,0,1 };
    k = 2;
    result = leetCode.kLengthApart(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,1,1,1 };
    k = 0;
    result = leetCode.kLengthApart(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    nums = { 0,1,0,1 };
    k = 1;
    result = leetCode.kLengthApart(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1438(void)
{
    Logger::WriteMessage("Test Leet Code 1438");
    LeetCodeArray leetCode;
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

void TestLeetCode1441(void)
{
    Logger::WriteMessage("Test Leet Code 1441");
    LeetCodeArray leetCode;
    vector<int> target = { 1, 3 };
    int n = 3;
    vector<string> result = leetCode.buildArray(target, n);
    Logger::WriteMessage(target);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    target = { 1, 2, 3 }; 
    n = 3;
    result = leetCode.buildArray(target, n);
    Logger::WriteMessage(target);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    target = { 1,2 };
    n = 4;
    result = leetCode.buildArray(target, n);
    Logger::WriteMessage(target);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    target = { 2,3,4 };
    n = 4;
    result = leetCode.buildArray(target, n);
    Logger::WriteMessage(target);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode1442(void)
{
    Logger::WriteMessage("Test Leet Code 1442");
    LeetCodeArray leetCode;
    vector<int> arr = { 2, 3, 1, 6, 7 };
    int result = leetCode.countTriplets(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,1,1,1,1 };
    result = leetCode.countTriplets(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 2,3 };
    result = leetCode.countTriplets(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 1,3,5,7,9 };
    result = leetCode.countTriplets(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 7, 11, 12, 9, 5, 2, 7, 17, 22 };
    result = leetCode.countTriplets(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode283(void)
{
    Logger::WriteMessage("Test Leet Code 283");
    LeetCodeArray leetCode;
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


void TestLeetCode345(void)
{
    Logger::WriteMessage("Test Leet Code 345");
    LeetCodeArray leetCode;
    string s = "hEllo";
    Logger::WriteMessage(s + "->" + leetCode.reverseVowels(s));
}

void TestLeetCode167(void)
{
    Logger::WriteMessage("Test Leet Code 117");
    LeetCodeArray leetCode;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    Logger::WriteMessage(nums);
    vector<int> result = leetCode.twoSumII(nums, target);
    Logger::WriteMessage(result);
}

void TestLeetCode228(void)
{
    Logger::WriteMessage("Test Leet Code 228");
    LeetCodeArray leetCode;
    vector<int> nums = { 0, 1, 2, 4, 5, 7 };
    Logger::WriteMessage(nums);
    vector<string> result = leetCode.summaryRanges(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode259(void)
{
    Logger::WriteMessage("Test Leet Code 259");
    LeetCodeArray leetCode;
    vector<int> nums = { -2, 0, 1, 3 };
    int target = 2;
    int result = leetCode.threeSumSmaller(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Target = " + to_string(target) + "; Number of triples smaller than target = " + to_string(result));
}

void TestLeetCode1150(void)
{
    Logger::WriteMessage("Test Leet Code 1150");
    LeetCodeArray leetCode;
    vector<int> nums = { 2, 4, 5, 5, 5, 5, 5, 6, 6 };
    int target = 5;
    bool result = leetCode.isMajorityElement(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + (string)(result ? "true" : "false"));

    nums = { 10, 100, 101, 101 };
    target = 101;
    result = leetCode.isMajorityElement(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1156(void)
{
    Logger::WriteMessage("Test Leet Code 1156");
    LeetCodeArray leetCode;
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

void TestLeetCode1180(void)
{
    Logger::WriteMessage("Test Leet Code 1180");
    LeetCodeArray leetCode;
    string S = "aaaba";
    int result = leetCode.countLetters(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "aaaaaaaaaa";
    result = leetCode.countLetters(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode1100(void)
{
    Logger::WriteMessage("Test Leet Code 1100");
    LeetCodeArray leetCode;
    string S = "havefunonleetcode";
    int K = 5;
    int result = leetCode.numKLenSubstrNoRepeats(S, K);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "home";
    K = 5;
    result = leetCode.numKLenSubstrNoRepeats(S, K);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode915(void)
{
    Logger::WriteMessage("Test Leet Code 915");
    LeetCodeArray leetCode;
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

void TestLeetCode917(void)
{
    Logger::WriteMessage("Test Leet Code 917");
    LeetCodeArray leetCode;
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

void TestLeetCode904(void)
{
    Logger::WriteMessage("Test Leet Code 904");
    LeetCodeArray leetCode;
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

void TestLeetCode443(void)
{
    LeetCodeArray leetCode;
    vector<char> chars = { 'a','a','b','b','c','c','c' };
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

void TestLeetCode544(void)
{
    LeetCodeArray leetCode;
    int n = 8;
    string result = leetCode.findContestMatch(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + result);
}

void TestLeetCode713(void)
{
    Logger::WriteMessage("Test Leet Code");
    LeetCodeArray leetCode;
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

void TestLeetCode755(void)
{
    Logger::WriteMessage("Test Leet Code 755");
    LeetCodeArray leetCode;
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

void TestLeetCode680(void)
{
    LeetCodeArray leetCode;
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

void TestLeetCode209(void)
{
    Logger::WriteMessage("Test Leet Code 209");
    LeetCodeArray leetCode;
    vector <int> nums = { 2,3,1,2,4,3 };
    int s = 7;
    Logger::WriteMessage(nums);
    int result = leetCode.minSubArrayLen(s, nums);
    int expect = 2;
    Logger::WriteMessage("result = " + to_string(result) + "; expect = " + to_string(expect));
}

void TestLeetCode487(void)
{
    Logger::WriteMessage("Test Leet Code 487");
    LeetCodeArray leetCode;
    vector<int> nums = { 1, 0, 1, 1, 0 };
    Logger::WriteMessage(nums);
    int max_length = leetCode.findMaxConsecutiveOnesII(nums);
    Logger::WriteMessage("maximum consecutiveones II = " + to_string(max_length));
}

void TestLeetCode1450(void)
{
    Logger::WriteMessage("Test Leet Code 1450");
    LeetCodeArray leetCode;
    vector<int> startTime = { 1, 2, 3 };
    vector<int> endTime = { 3, 2, 7 };
    int queryTime = 4;
    int result = leetCode.busyStudent(startTime, endTime, queryTime);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage("queryTime = " + to_string(queryTime) + "; result = " + to_string(result));

    startTime = { 4 };
    endTime = { 4 };
    queryTime = 4;
    result = leetCode.busyStudent(startTime, endTime, queryTime);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage("queryTime = " + to_string(queryTime) + "; result = " + to_string(result));

    startTime = { 4 };
    endTime = { 4 };
    queryTime = 5;
    result = leetCode.busyStudent(startTime, endTime, queryTime);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage("queryTime = " + to_string(queryTime) + "; result = " + to_string(result));

    startTime = { 1,1,1,1 };
    endTime = { 1,3,2,4 };
    queryTime = 7;
    result = leetCode.busyStudent(startTime, endTime, queryTime);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage("queryTime = " + to_string(queryTime) + "; result = " + to_string(result));

    startTime = { 9,8,7,6,5,4,3,2,1 };
    endTime = { 10,10,10,10,10,10,10,10,10 };
    queryTime = 5;
    result = leetCode.busyStudent(startTime, endTime, queryTime);
    Logger::WriteMessage(startTime);
    Logger::WriteMessage(endTime);
    Logger::WriteMessage("queryTime = " + to_string(queryTime) + "; result = " + to_string(result));
}


void TestLeetCode311(void)
{
    Logger::WriteMessage("Test Leet Code 311");
    LeetCodeArray leetCode;
    vector<vector<int>> A = { {1, 0, 0 } , { -1, 0, 3 } };
    vector<vector<int>> B = { { 7, 0, 0 } ,{ 0, 0, 0 }, { 0, 0, 1 } };
    vector<vector<int>> C = leetCode.multiply(A, B);
    Logger::WriteMessage(A);
    Logger::WriteMessage(B);
    Logger::WriteMessage(C);
}

void TestLeetCode667(void)
{
    LeetCodeArray leetCode;
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

void TestLeetCode661(void)
{
    LeetCodeArray leetCode;
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

void TestLeetCode539(void)
{
    LeetCodeArray leetCode;
    vector<string> timePoints = { "23:59","8:13","00:00" };
    int diff = leetCode.findMinDifference(timePoints);
    Logger::WriteMessage(timePoints);
    Logger::WriteMessage("diff = " + to_string(diff));
}

void TestLeetCode531(void)
{
    Logger::WriteMessage("Test Leet Code 531");
    LeetCodeArray leetCode;
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
    LeetCodeArray leetCode;
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

void TestLeetCode566(void)
{
    LeetCodeArray leetCode;
    vector<vector<int>> nums = { { 1, 2 },{ 3, 4 } };
    vector<vector<int>> result = leetCode.matrixReshape(nums, 1, 4);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode548(void)
{
    LeetCodeArray leetCode;
    vector<int> nums = { 1,2,1,2,1,2,1 };
    Logger::WriteMessage(nums);
    bool result = leetCode.splitArray(nums);
    Logger::WriteMessage("Can split into equal sum: " + (string)(result ? "true" : " false"));

    nums = { 1 };
    Logger::WriteMessage(nums);
    result = leetCode.splitArray(nums);
    Logger::WriteMessage("Can split into equal sum: " + (string)(result ? "true" : " false"));
}

void TestLeetCode575(void)
{
    LeetCodeArray leetCode;
    vector<int> candies = { 1, 1, 2, 2, 3, 3 };
    int result = leetCode.distributeCandies(candies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("result = " + to_string(result));

    candies = { 1, 1, 2, 3 };
    result = leetCode.distributeCandies(candies);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1089(void)
{
    Logger::WriteMessage("Test Leet Code 1089");
    LeetCodeArray leetCode;
    vector<int> arr = { 1, 0, 2, 3, 0, 4, 5, 0 };
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

void TestLeetCode1063(void)
{
    Logger::WriteMessage("Test Leet Code 1063");
    LeetCodeArray leetCode;
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

void TestLeetCode1074(void)
{
    Logger::WriteMessage("Test Leet Code 1074");
    LeetCodeArray leetCode;
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

void TestLeetCode363(void)
{
    Logger::WriteMessage("Test Leet Code 363");
    LeetCodeArray leetCode;
    vector<vector<int>> matrix =
    {
        { 1,  0, 1 },
        { 0, -2, 3 }
    };
    int k = 2;
    int result = leetCode.maxSumSubmatrix(matrix, k);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("k = " + to_string(k) + "; max sum no larger than k = " + to_string(result));
}

void TestLeetCode891(void)
{
    Logger::WriteMessage("Test Leet Code 891");
    LeetCodeArray leetCode;
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

void TestLeetCode475(void)
{
    Logger::WriteMessage("Test Leet Code 475");
    LeetCodeArray leetCode;
    vector<int> houses = { 1, 2, 3, 4 };
    Logger::WriteMessage(houses);
    vector<int> heaters = { 1, 4 };
    Logger::WriteMessage(heaters);
    int radius = leetCode.findRadius(houses, heaters);
    Logger::WriteMessage("Radius = " + to_string(radius));
}

void TestLeetCode1460(void)
{
    Logger::WriteMessage("Test Leet Code 1460");
    LeetCodeArray leetCode;
    vector<int> target = { 1, 2, 3, 4 };
    vector<int> arr = { 2, 4, 1, 3 };
    bool result = leetCode.canBeEqual(target, arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    target = { 7 };
    arr = { 7 };
    result = leetCode.canBeEqual(target, arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    target = { 1, 12 };
    arr = { 12, 1 };
    result = leetCode.canBeEqual(target, arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    target = { 3, 7, 9 };
    arr = { 3, 7, 11 };
    result = leetCode.canBeEqual(target, arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    target = { 1,1,1,1,1 };
    arr = { 1,1,1,1,1 };
    result = leetCode.canBeEqual(target, arr);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode370(void)
{
    Logger::WriteMessage("Test Leet Code 370");
    LeetCodeArray leetCode;
    vector<vector<int>> updates = { {1, 3, 2}, {2, 4, 3}, {0, 2, -2} };
    int length = 5;
    vector<int> result = leetCode.getModifiedArray(length, updates);
    Logger::WriteMessage(updates);
    Logger::WriteMessage(result);
}

void TestLeetCode565(void)
{
    LeetCodeArray leetCode;
    vector<int> nums = { 5, 4, 0, 3, 1, 6, 2 };
    int result = leetCode.arrayNesting(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode624(void)
{
    LeetCodeArray leetCode;
    vector<vector<int>> arrays = { { 1, 5 },{ 3, 4 } };
    Logger::WriteMessage(arrays);
    int maxDistance = leetCode.maxDistance(arrays);
    Logger::WriteMessage("maxDistance = " + to_string(maxDistance));
}

void TestLeetCode644(void)
{
    Logger::WriteMessage("Test Leet Code 644");
    LeetCodeArray leetCode;
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

void TestLeetCode643(void)
{
    Logger::WriteMessage("Test Leet Code 643");
    LeetCodeArray leetCode;
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

void TestLeetCode605(void)
{
    LeetCodeArray leetCode;
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

void TestLeetCode645(void)
{
    Logger::WriteMessage("Test Leet Code 645");
    LeetCodeArray leetCode;
    vector<int> nums = { 1, 2, 2, 4 };
    vector<int> result = leetCode.findErrorNums(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1470(void)
{
    Logger::WriteMessage("Test Leet Code 1470");
    LeetCodeArray leetCode;
    vector<int> nums = { 2, 5, 1, 3, 4, 7 };
    int n = 3;
    vector<int> result = leetCode.shuffle(nums, n);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 1,2,3,4,4,3,2,1 };
    n = 4;
    result = leetCode.shuffle(nums, n);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 1,1,2,2 };
    n = 2;
    result = leetCode.shuffle(nums, n);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1471(void)
{
    Logger::WriteMessage("Test Leet Code 1471");
    LeetCodeArray leetCode;
    vector<int> arr = { 1, 2, 3, 4, 5 };
    int k = 2;
    vector<int> result = leetCode.getStrongest(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    arr = { 1,1,3,5,5 };
    k = 2;
    result = leetCode.getStrongest(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    arr = { 6,7,11,7,6,8 };
    k = 5;
    result = leetCode.getStrongest(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    arr = { 6, -3, 7, 2, 11 };
    k = 3;
    result = leetCode.getStrongest(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    arr = { -7,22,17,3 };
    k = 2;
    result = leetCode.getStrongest(arr, k);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}


void TestLeetCode682(void)
{
    LeetCodeArray leetCode;
    vector<string> ops = { "5", "2", "C", "D", "+" };
    int sum = leetCode.calPoints(ops);
    Logger::WriteMessage(ops);
    Logger::WriteMessage("sum = " + to_string(sum));

    ops = { "5","-2","4","C","D","9","+","+" };
    sum = leetCode.calPoints(ops);
    Logger::WriteMessage(ops);
    Logger::WriteMessage("sum = " + to_string(sum));
}

void TestLeetCode659(void)
{
    LeetCodeArray leetCode;
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

void TestLeetCode723(void)
{
    LeetCodeArray leetCode;

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

void TestLeetCode747(void)
{
    Logger::WriteMessage("Test Leet Code 747");
    LeetCodeArray leetCode;
    vector<int> nums = { 3, 6, 1, 0 };
    int result = leetCode.dominantIndex(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 2, 3, 4 };
    result = leetCode.dominantIndex(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode717(void)
{
    Logger::WriteMessage("Test Leet Code 717");
    LeetCodeArray leetCode;
    vector<int> bits = { 1, 0, 0 };
    bool result = leetCode.isOneBitCharacter(bits);
    Logger::WriteMessage(bits);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    bits = { 1, 1, 1, 0 };
    result = leetCode.isOneBitCharacter(bits);
    Logger::WriteMessage(bits);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode860(void)
{
    Logger::WriteMessage("Test Leet Code 860");
    LeetCodeArray leetCode;
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

void TestLeetCode874(void)
{
    Logger::WriteMessage("Test Leet Code 874");
    LeetCodeArray leetCode;
    vector<int> commands = { 4, -1, 3 };
    vector<vector<int>> obstacles = {};
    unsigned int result = leetCode.robotSim(commands, obstacles);
    Logger::WriteMessage(commands);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage("result = " + to_string(result));

    commands = { 4,-1,4,-2,4 };
    obstacles = { { 2,4 } };
    result = leetCode.robotSim(commands, obstacles);
    Logger::WriteMessage(commands);
    Logger::WriteMessage(obstacles);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode697(void)
{
    LeetCodeArray leetCode;
    vector<int> nums = { 1, 2, 2, 3, 1 };
    int result = leetCode.findShortestSubArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,2,3,1,4,2 };
    result = leetCode.findShortestSubArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode649(void)
{
    LeetCodeArray leetCode;
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

void TestLeetCode750(void)
{
    Logger::WriteMessage("Test Leet Code 750");
    LeetCodeArray leetCode;
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

void TestLeetCode696(void)
{
    LeetCodeArray leetCode;
    string s = "00110011";
    int result = leetCode.countBinarySubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "10101";
    result = leetCode.countBinarySubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode724(void)
{
    LeetCodeArray leetCode;

    vector<int> nums = { 1, 7, 3, 6, 5, 6 };
    int result = leetCode.pivotIndex(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 2, 3 };
    result = leetCode.pivotIndex(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode498(void)
{
    Logger::WriteMessage("Test Leet Code 498");
    LeetCodeArray leetCode;
    vector<vector<int>> matrix =
    {
        { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }
    };
    vector<int> result = leetCode.findDiagonalOrder(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);
}


void TestLeetCode807(void)
{
    Logger::WriteMessage("Test Leet Code 807");
    LeetCodeArray leetCode;
    vector<vector<int>> grid = { {3, 0, 8, 4},{2, 4, 5, 7},{9, 2, 6, 3},{0, 3, 1, 0} };
    int result = leetCode.maxIncreaseKeepingSkyline(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode822(void)
{
    Logger::WriteMessage("Test Leet Code 822");
    LeetCodeArray leetCode;
    vector<int> fronts = { 1,2,4,4,7 };
    vector<int> backs = { 1,3,4,1,3 };
    int result = leetCode.flipgame(fronts, backs);
    Logger::WriteMessage(fronts);
    Logger::WriteMessage(backs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode821(void)
{
    Logger::WriteMessage("Test Leet Code 821");
    LeetCodeArray leetCode;
    string S = "loveleetcode";
    char C = 'e';
    vector<int> result = leetCode.shortestToChar(S, C);
    string c_str;
    Logger::WriteMessage("S = " + S + "; C = " + string(1, C));
    Logger::WriteMessage(result);
}

void TestLeetCode832(void)
{
    Logger::WriteMessage("Test Leet Code 832");
    LeetCodeArray leetCode;
    vector<vector<int>> A = { {1, 1, 0 },{ 1, 0, 1 },{ 0, 0, 0 } };
    vector<vector<int>> result = leetCode.flipAndInvertImage(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { {1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0} };
    result = leetCode.flipAndInvertImage(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode840(void)
{
    Logger::WriteMessage("Test Leet Code 840");
    LeetCodeArray leetCode;
    vector<vector<int>> grid = { {4,3,8,4}, {9,5,1,9}, { 2,7,6,2 } };
    int result = leetCode.numMagicSquaresInside(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode845(void)
{
    Logger::WriteMessage("Test Leet Code 845");
    LeetCodeArray leetCode;
    vector<int> A = { 2,1,4,7,3,2,5 };
    int result = leetCode.longestMountain(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2,2,2 };
    result = leetCode.longestMountain(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode896(void)
{
    Logger::WriteMessage("Test Leet Code 896");
    LeetCodeArray leetCode;
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

void TestLeetCode766(void)
{
    Logger::WriteMessage("Test Leet Code 766");
    LeetCodeArray leetCode;
    vector<vector<int>> matrix = { {1, 2, 3, 4},{5, 1, 2, 3},{9, 5, 1, 2} };
    Logger::WriteMessage(matrix);
    bool result = leetCode.isToeplitzMatrix(matrix);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    matrix = { { 1,2 },{ 2,2 } };
    Logger::WriteMessage(matrix);
    result = leetCode.isToeplitzMatrix(matrix);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode867(void)
{
    Logger::WriteMessage("Test Leet Code 867");
    LeetCodeArray leetCode;
    vector<vector<int>> A = { {1,2,3},{4,5,6}, {7,8,9} };
    vector<vector<int>> result = leetCode.transpose(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { { 1,2,3 },{ 4,5,6 } };
    result = leetCode.transpose(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode888(void)
{
    Logger::WriteMessage("Test Leet Code 888");
    LeetCodeArray leetCode;
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

void TestLeetCode885(void)
{
    Logger::WriteMessage("Test Leet Code 885");
    LeetCodeArray leetCode;
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

void TestLeetCode905(void)
{
    Logger::WriteMessage("Test Leet Code 905");
    LeetCodeArray leetCode;
    vector<int> A = { 3, 1, 2, 4 };
    vector<int> result = leetCode.sortArrayByParity(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode922(void)
{
    Logger::WriteMessage("Test Leet Code 922");
    LeetCodeArray leetCode;
    vector<int> A = { 4,2,5,7 };
    vector<int> result = leetCode.sortArrayByParityII(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}


void TestLeetCode927(void)
{
    Logger::WriteMessage("Test Leet Code 927");
    LeetCodeArray leetCode;
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

void TestLeetCode918(void)
{
    Logger::WriteMessage("Test Leet Code 918");
    LeetCodeArray leetCode;

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

void TestLeetCode926(void)
{
    Logger::WriteMessage("Test Leet Code 926");
    LeetCodeArray leetCode;
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

void TestLeetCode944(void)
{
    Logger::WriteMessage("Test Leet Code 944");
    LeetCodeArray leetCode;
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

void TestLeetCode945(void)
{
    Logger::WriteMessage("Test Leet Code 945");
    LeetCodeArray leetCode;
    vector<int> A = { 1,2,2 };
    int result = leetCode.minIncrementForUnique(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,2,1,2,1,7 };
    result = leetCode.minIncrementForUnique(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCodeArray(void)
{
    TestLeetCode945();
    TestLeetCode944();
    TestLeetCode926();
    TestLeetCode918();
    TestLeetCode927();
    TestLeetCode922();
    TestLeetCode905();
    TestLeetCode885();
    TestLeetCode888();
    TestLeetCode867();
    TestLeetCode766();
    TestLeetCode896();
    TestLeetCode845();
    TestLeetCode840();
    TestLeetCode832();
    TestLeetCode807();
    TestLeetCode821();
    TestLeetCode822();
    TestLeetCode498();
    TestLeetCode724();
    TestLeetCode696();
    TestLeetCode750();
    TestLeetCode649();
    TestLeetCode697();
    TestLeetCode874();
    TestLeetCode659();
    TestLeetCode717();
    TestLeetCode723();
    TestLeetCode747();
    TestLeetCode682();
    TestLeetCode1471();
    TestLeetCode1470();
    TestLeetCode645();
    TestLeetCode605();
    TestLeetCode643();
    TestLeetCode644();
    TestLeetCode624();
    TestLeetCode565();
    TestLeetCode370();
    TestLeetCode1460();
    TestLeetCode475();
    TestLeetCode891();
    TestLeetCode363();
    TestLeetCode1074();
    TestLeetCode1063();
    TestLeetCode1089();
    TestLeetCode575();
    TestLeetCode548();
    TestLeetCode566();
    TestLeetCode531();
    TestLeetCode533();
    TestLeetCode539();
    TestLeetCode661();
    TestLeetCode667();
    TestLeetCode311();
    TestLeetCode1450();
    TestLeetCode209();
    TestLeetCode487();
    TestLeetCode680();
    TestLeetCode755();
    TestLeetCode713();
    TestLeetCode544();
    TestLeetCode443();
    TestLeetCode904();
    TestLeetCode917();
    TestLeetCode915();
    TestLeetCode1100();
    TestLeetCode1156();
    TestLeetCode1150();
    TestLeetCode1180();
    TestLeetCode259();
    TestLeetCode228();
    TestLeetCode167();
    TestLeetCode283();
    TestLeetCode345();
    TestLeetCode1442();
    TestLeetCode1441();
    TestLeetCode1438();
    TestLeetCode1437();
    TestLeetCode1431();
    TestLeetCode1413();
    TestLeetCode1424();
    TestLeetCode1423();
    TestLeetCode1409();
    TestLeetCode1395();
    TestLeetCode1389();
    TestLeetCode1380();
    TestLeetCode289();
    TestLeetCode1351();
    TestLeetCode1151();
    TestLeetCode1138();
    TestLeetCode1176();
    TestLeetCode1183();
    TestLeetCode1184();
    TestLeetCode1186();
    TestLeetCode1191();
    TestLeetCode1200();
    TestLeetCode1346();
    TestLeetCode1343();
    TestLeetCode1338();
    TestLeetCode1337();
    TestLeetCode1333();
    TestLeetCode1329();
    TestLeetCode1330();
    TestLeetCode243();
    TestLeetCode245();
    TestLeetCode442();
    TestLeetCode419();
    TestLeetCode189();
    TestLeetCode26();
    TestLeetCode73();
    TestLeetCode80();
    TestLeetCode368();
    TestLeetCode446();
    TestLeetCode485();
    TestLeetCode413();
    TestLeetCode1314();
    TestLeetCode1313();
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
    TestLeetCode11();
    TestLeetCode16();
    TestLeetCode42();
    TestLeetCode27();
}