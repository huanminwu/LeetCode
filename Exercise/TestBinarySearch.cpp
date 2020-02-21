#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeBinarySearch.h"
#include "TestBinarySearch.h"

void TestLeetCode33(void)
{
    LeetCodeBinarySearch leetCode;
    Logger::WriteMessage("Test Leet Code 33");
    vector<int> data_list = { 4, 5, 6, 7, 0, 1, 2 };
    Logger::WriteMessage(data_list);
    string message;
    message.assign("Search for ").append(to_string(4));
    int index = leetCode.search(data_list, 4);
    message.append("; Index is ").append(to_string(index));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode34(void)
{
    Logger::WriteMessage("Test Leet Code 34");
    LeetCodeBinarySearch leetCode;
    vector<int> nums, result;
    int target = 8;
    nums = { 5, 7, 7, 8, 8, 10 };
    Logger::WriteMessage(nums);
    result = leetCode.searchRange(nums, target);
    Logger::WriteMessage(result);
}

void TestLeetCode153(void)
{
    Logger::WriteMessage("Test Leet Code 153");
    LeetCodeBinarySearch leetCode;
    vector <int> nums = { 5, 6, 7, 8, 0, 1, 2, 3, 4 };
    Logger::WriteMessage(nums);
    int min_value = leetCode.findMin(nums);
    Logger::WriteMessage("Min Value = " + to_string(min_value));
}

void TestLeetCode154(void)
{
    Logger::WriteMessage("Test Leet Code 154");
    LeetCodeBinarySearch leetCode;
    vector <int> nums = { 5, 6, 7, 8, 0, 0, 1, 2, 2, 3, 4 };
    Logger::WriteMessage(nums);
    int min_value = leetCode.findMinII(nums);
    Logger::WriteMessage("Min Value = " + to_string(min_value));

    nums = { 0, 0, 0, 0, 0 };
    Logger::WriteMessage(nums);
    min_value = leetCode.findMinII(nums);
    Logger::WriteMessage("Min Value = " + to_string(min_value));
}

void TestLeetCode1231(void)
{
    Logger::WriteMessage("Test Leet Code 1231");
    LeetCodeBinarySearch leetCode;
    vector<int> sweetness = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int K = 5;
    int result = leetCode.maximizeSweetness(sweetness, K);
    Logger::WriteMessage(sweetness);
    Logger::WriteMessage("result = " + to_string(result));

    sweetness = { 5,6,7,8,9,1,2,3,4 };
    K = 8;
    result = leetCode.maximizeSweetness(sweetness, K);
    Logger::WriteMessage(sweetness);
    Logger::WriteMessage("result = " + to_string(result));

    sweetness = { 1, 2, 2, 1, 2, 2, 1, 2, 2 };
    K = 2;
    result = leetCode.maximizeSweetness(sweetness, K);
    Logger::WriteMessage(sweetness);
    Logger::WriteMessage("result = " + to_string(result));    
}


void TestLeetCode81(void)
{
    LeetCodeBinarySearch leetCode;
    Logger::WriteMessage("Test Leet Code 81");
    vector<int> data_list = { 3, 5, 1 };
    Logger::WriteMessage(data_list);
    int target = 1;
    bool result = leetCode.searchII(data_list, target);
    Logger::WriteMessage("Search for " + to_string(target) + " target " + (string)(result ? "found" : "not found"));

    data_list = { 4, 5, 5, 6, 7, 0, 1, 2, 2 };
    Logger::WriteMessage(data_list);
    target = 6;
    result = leetCode.searchII(data_list, target);
    Logger::WriteMessage("Search for " + to_string(target) + " target " + (string)(result ? "found" : "not found"));
}

void TestLeetCode162(void)
{
    Logger::WriteMessage("Test Leet Code 162");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 1, 2, 3, 1 };
    Logger::WriteMessage(nums);
    int index = leetCode.findPeakElement(nums);
    Logger::WriteMessage("Peak Element is " + to_string(index));

    nums = { 3, 1, 2, 3 };
    Logger::WriteMessage(nums);
    index = leetCode.findPeakElement(nums);
    Logger::WriteMessage("Peak Element is " + to_string(index));
}

void TestLeetCode240(void)
{
    Logger::WriteMessage("Test Leet Code 240");
    vector<vector<int>> matrix =
    {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    LeetCodeBinarySearch leetCode;
    int target = 21;
    bool result = leetCode.searchMatrixII(matrix, target);
    Logger::WriteMessage("Target = " + to_string(target) + " ; " + (string)(result ? "existing" : "not existing"));
    target = 20;
    result = leetCode.searchMatrixII(matrix, target);
    Logger::WriteMessage("Target = " + to_string(target) + " ; " + (string)(result ? "existing" : "not existing"));
}

void TestLeetCode4(void)
{
    Logger::WriteMessage("Test Leet Code 4");
    LeetCodeBinarySearch leetCode;
    vector<vector<int>> nums =
    {
        {1, 2},{ 3, 4 }
    };
    double median = leetCode.findMedianSortedArrays(nums[0], nums[1]);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("median = " + to_string(median));

    Assert::IsTrue(median == 2.5);

    nums =
    {
        { 1, 2 },{ 3, 4, 5, 6, 7, 8, 9, 10, 11}
    };
    median = leetCode.findMedianSortedArrays(nums[0], nums[1]);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("median = " + to_string(median));
    Assert::IsTrue(median == 6);

    nums =
    {
        { 4 },{ 1,2,3,5,6 }
    };
    median = leetCode.findMedianSortedArrays(nums[0], nums[1]);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("median = " + to_string(median));
    Assert::IsTrue(median == 3.5);

    nums =
    {
        { 1,3,4 },{ 2 }
    };
    median = leetCode.findMedianSortedArrays(nums[0], nums[1]);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("median = " + to_string(median));
    Assert::IsTrue(median == 2.5);
}

void TestLeetCode1011(void)
{
    Logger::WriteMessage("Test Leet Code 1011");
    LeetCodeBinarySearch leetCode;
    vector<int> weights = { 1,2,3,4,5,6,7,8,9,10 };
    int D = 5;
    int result = leetCode.shipWithinDays(weights, D);
    Logger::WriteMessage(weights);
    Logger::WriteMessage("D = " + to_string(D) + "; result = " + to_string(result));

    weights = { 3,2,2,4,1,4 };
    D = 3;
    result = leetCode.shipWithinDays(weights, D);
    Logger::WriteMessage(weights);
    Logger::WriteMessage("D = " + to_string(D) + "; result = " + to_string(result));

    weights = { 1, 2, 3, 1, 1 };
    D = 4;
    result = leetCode.shipWithinDays(weights, D);
    Logger::WriteMessage(weights);
    Logger::WriteMessage("D = " + to_string(D) + "; result = " + to_string(result));
}

void TestLeetCode875(void)
{
    Logger::WriteMessage("Test Leet Code 875");
    LeetCodeBinarySearch leetCode;
    vector<int> piles = { 3, 6, 7, 11 };
    int H = 8;
    int result = leetCode.minEatingSpeed(piles, H);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("H = " + to_string(H) + "; result = " + to_string(result));

    piles = { 30,11,23,4,20 };
    H = 5;
    result = leetCode.minEatingSpeed(piles, H);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("H = " + to_string(H) + "; result = " + to_string(result));

    piles = { 30,11,23,4,20 };
    H = 6;
    result = leetCode.minEatingSpeed(piles, H);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("H = " + to_string(H) + "; result = " + to_string(result));
}

void TestLeetCode719(void)
{
    LeetCodeBinarySearch leetCode;

    vector<int> nums = { 1, 2, 3, 4, 5,6,7,8,9 };
    int k = 5;
    int result = leetCode.smallestDistancePair(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1, 3, 1 };
    k = 1;
    result = leetCode.smallestDistancePair(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2, 2, 0, 1, 1, 0, 0, 1, 2, 0 };
    k = 2;
    result = leetCode.smallestDistancePair(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
};

void TestLeetCode786(void)
{
    Logger::WriteMessage("Test Leet Code 786");
    LeetCodeBinarySearch leetCode;
    vector<int> A = { 1, 2, 3, 5 };
    int K = 3;
    vector<int> result = leetCode.kthSmallestPrimeFraction(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(result);

    A = { 1, 7 };
    K = 1;
    result = leetCode.kthSmallestPrimeFraction(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("K = " + to_string(K));
    Logger::WriteMessage(result);
}

void TestLeetCode378(void)
{
    Logger::WriteMessage("Test Leet Code 378");
    LeetCodeBinarySearch leetCode;
    vector<vector<int>> matrix =
    {
        { 1,  5,  9 },
        { 10, 11, 13 },
        { 12, 13, 15 }
    };
    int k = 6;
    int result = leetCode.kthSmallest(matrix, k);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage("The " + to_string(k) + "th element is " + to_string(result));
}

void TestLeetCode410(void)
{
    Logger::WriteMessage("Test Leet Code 410");
    LeetCodeBinarySearch leetCode;
    vector<int> nums =
    {
        7,2,5,10,8
    };
    Logger::WriteMessage(nums);
    int result = leetCode.splitArray(nums, 2);
    string message;
    message.assign("The minimum sum is: ");
    message.append(std::to_string(result));
    Logger::WriteMessage(message.c_str());

    nums =
    {
        7, 10
    };
    Logger::WriteMessage(nums);
    result = leetCode.splitArray(nums, 2);
    message.assign("The minimum sum is: ");
    message.append(std::to_string(result));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode1283(void)
{
    Logger::WriteMessage("Test Leet Code 1283");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    int result = leetCode.smallestDivisor(nums, threshold);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));

    nums = { 2, 3, 5, 7, 11 };
    threshold = 11;
    result = leetCode.smallestDivisor(nums, threshold);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));

    nums = { 19 };
    threshold = 5;
    result = leetCode.smallestDivisor(nums, threshold);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("threshold = " + to_string(threshold) + "; result = " + to_string(result));
}

void TestLeetCode1300(void)
{
    Logger::WriteMessage("Test LeetCode 1300");
    LeetCodeBinarySearch leetCode;
    vector<int> arr = { 4, 9, 3 };
    int target = 10;
    int result = leetCode.findBestValue(arr, target);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    arr = { 2,3,5 };
    target = 10;
    result = leetCode.findBestValue(arr, target);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    arr = { 60864,25176,27249,21296,20204 };
    target = 56803;
    result = leetCode.findBestValue(arr, target);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCodeBinarySearch(void)
{
    TestLeetCode1300();
    TestLeetCode1283();
    TestLeetCode378();
    TestLeetCode786();
    TestLeetCode410();
    TestLeetCode719();
    TestLeetCode4();
    TestLeetCode33();
    TestLeetCode34();
    TestLeetCode81();
    TestLeetCode153();
    TestLeetCode154();
    TestLeetCode162();
    TestLeetCode240();
    TestLeetCode875();
    TestLeetCode1011();
    TestLeetCode1231();
}