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

    nums = { 1,2,1,3,5,6,4 };
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

void TestLeetCode878(void)
{
    Logger::WriteMessage("Test Leet Code 878");
    LeetCodeBinarySearch leetCode;
    int n = 1;
    int a = 2;
    int b = 3;
    int result = leetCode.nthMagicalNumber(n, a, b);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) + "; b = " + to_string(b) + "; result = " + to_string(result));

    n = 4;
    a = 2;
    b = 3;
    result = leetCode.nthMagicalNumber(n, a, b);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) + "; b = " + to_string(b) + "; result = " + to_string(result));

    n = 5;
    a = 2;
    b = 4;
    result = leetCode.nthMagicalNumber(n, a, b);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) + "; b = " + to_string(b) + "; result = " + to_string(result));

    n = 3;
    a = 6;
    b = 4;
    result = leetCode.nthMagicalNumber(n, a, b);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) + "; b = " + to_string(b) + "; result = " + to_string(result));

    n = 1000000000;
    a = 40000;
    b = 40000;
    result = leetCode.nthMagicalNumber(n, a, b);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) + "; b = " + to_string(b) + "; result = " + to_string(result));
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

void TestLeetCode540(void)
{
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };
    Logger::WriteMessage(nums);
    int result = leetCode.singleNonDuplicate(nums);
    Logger::WriteMessage("result:" + to_string(result));

    nums = { 3, 3, 7, 7, 10, 11, 11 };
    Logger::WriteMessage(nums);
    result = leetCode.singleNonDuplicate(nums);
    Logger::WriteMessage("result:" + to_string(result));
}

void TestLeetCode668(void)
{
    LeetCodeBinarySearch leetCode;
    int m = 3, n = 3, k = 5;
    int result = leetCode.findKthNumber(m, n, k);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    m = 2, n = 3, k = 6;
    result = leetCode.findKthNumber(m, n, k);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    m = 1, n = 9, k = 7;
    result = leetCode.findKthNumber(m, n, k);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    m = 9, n = 1, k = 7;
    result = leetCode.findKthNumber(m, n, k);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode702(void)
{
    Logger::WriteMessage("Test Leet Code 702");
    LeetCodeBinarySearch leetCode;
    vector<int> reader = { -1, 0, 3, 5, 9, 12 };
    int target = 9;
    int result = leetCode.searchStream(reader, target);
    Logger::WriteMessage(reader);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    reader = { -1, 0, 3, 5, 9, 12 };
    target = 2;
    result = leetCode.searchStream(reader, target);
    Logger::WriteMessage(reader);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode74(void)
{
    Logger::WriteMessage("Test Leet Code 74");
    LeetCodeBinarySearch leetCode;
    vector<vector<int>> matrix;
    int target;
    bool found;
    target = 3;
    matrix = { {1}, {3} };
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
    matrix = { { 1,   3,  5,  7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
    target = 100;
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
    target = 9;
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
    target = 11;
    found = leetCode.searchMatrix(matrix, target);
    Logger::WriteMessage("The number " + to_string(target) + " is " + (found ? "found" : "not found"));
}

void TestLeetCode35(void)
{
    Logger::WriteMessage("Test Leet Code 35");
    LeetCodeBinarySearch leetCode;
    int result;
    int target;
    vector<int> nums = { 1,3,5,6 };
    target = 5;
    Logger::WriteMessage(nums);
    result = leetCode.searchInsert(nums, target);
    Logger::WriteMessage("Search " + to_string(target) + " -> " + to_string(result));
    target = 2;
    Logger::WriteMessage(nums);
    result = leetCode.searchInsert(nums, target);
    Logger::WriteMessage("Search " + to_string(target) + " -> " + to_string(result));
    target = 7;
    Logger::WriteMessage(nums);
    result = leetCode.searchInsert(nums, target);
    Logger::WriteMessage("Search " + to_string(target) + " -> " + to_string(result));
    target = 0;
    Logger::WriteMessage(nums);
    result = leetCode.searchInsert(nums, target);
    Logger::WriteMessage("Search " + to_string(target) + " -> " + to_string(result));
}


void TestLeetCode852(void)
{
    Logger::WriteMessage("Test Leet Code 856");
    LeetCodeBinarySearch leetCode;
    vector<int> A = { 0,1,0 };
    int result = leetCode.peakIndexInMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,2,1,0 };
    result = leetCode.peakIndexInMountainArray(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}


void TestLeetCode69(void)
{
    Logger::WriteMessage("Test Leet Code 69");
    LeetCodeBinarySearch leetCode;
    int num = 2147395599;
    string message;
    message.append("The sqrt(" + to_string(num) + ") = " + to_string(leetCode.mySqrt(num)));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode1060(void)
{
    Logger::WriteMessage("Test Leet Code 1060");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 4, 7, 9, 10 };
    int k = 1;
    int result = leetCode.missingElement(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 4, 7, 9, 10 };
    k = 3;
    result = leetCode.missingElement(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 1,2,4 };
    k = 3;
    result = leetCode.missingElement(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode704(void)
{
    Logger::WriteMessage("Test Leet Code 704");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { -1,0,3,5,9,12 };
    int target = 9;
    Logger::WriteMessage(nums);
    int result = leetCode.binarySearchI(nums, target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    nums = { -1,0,3,5,9,12 };
    target = 2;
    Logger::WriteMessage(nums);
    result = leetCode.binarySearchI(nums, target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode278(void)
{
    Logger::WriteMessage("Test Leet Code 278");
    LeetCodeBinarySearch leetCode;
    int n_version = 3, bad_version = 1;
    int result = leetCode.firstBadVersion(n_version, bad_version);
    Logger::WriteMessage("First Bad Verion = " + to_string(result));
}

void TestLeetCode367(void)
{
    Logger::WriteMessage("Test Leet Code 367");
    LeetCodeBinarySearch leetCode;
    int num;
    bool isPerfectSquare;
    num = 36;
    isPerfectSquare = leetCode.isPerfectSquare(num);
    Logger::WriteMessage(to_string(num) + string(isPerfectSquare ? " is " : " is not ") + "a perfect square");

    num = 32;
    isPerfectSquare = leetCode.isPerfectSquare(num);
    Logger::WriteMessage(to_string(num) + string(isPerfectSquare ? " is " : " is not ") + "a perfect square");
}

void TestLeetCode275(void)
{
    Logger::WriteMessage("Test Leet Code 275");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 3, 0, 6, 1, 5 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("H index =" + to_string(leetCode.hIndexII(nums)));
    nums = { 0, 0, 0, 0, 0 };
    Logger::WriteMessage(nums);
    Logger::WriteMessage("H index =" + to_string(leetCode.hIndexII(nums)));
}

void TestLeetCode374(void)
{
    Logger::WriteMessage("Test Leet Code 374");
    int n = 1;
    LeetCodeBinarySearch leetCode;
    int guess = leetCode.guessNumber(n, n);
    Logger::WriteMessage("Guess number in " + to_string(n) + " is " + to_string(guess));
    n = 100;
    guess = leetCode.guessNumber(n, n);
    Logger::WriteMessage("Guess number in " + to_string(n) + " is " + to_string(guess));
}

void TestLeetCode1064(void)
{
    Logger::WriteMessage("Test Leet Code 1064");
    LeetCodeBinarySearch leetCode;
    vector<int> A = { -10, -5, 0, 3, 7 };
    int result = leetCode.fixedPoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,2,5,8,17 };
    result = leetCode.fixedPoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { -10,-5,3,4,7,9 };
    result = leetCode.fixedPoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,1,2,3,4,5 };
    result = leetCode.fixedPoint(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1482(void)
{
    Logger::WriteMessage("Test Leet Code 1482");
    LeetCodeBinarySearch leetCode;
    vector<int> bloomDay = { 1, 10, 3, 10, 2 };
    int m = 3;
    int k = 1;
    int result = leetCode.minDays(bloomDay, m, k);
    Logger::WriteMessage(bloomDay);
    Logger::WriteMessage("m = " + to_string(m) + "; k = " + to_string(k) + "; result = " + to_string(result));

    bloomDay = { 1, 10, 3, 10, 2 };
    m = 3;
    k = 2;
    result = leetCode.minDays(bloomDay, m, k);
    Logger::WriteMessage(bloomDay);
    Logger::WriteMessage("m = " + to_string(m) + "; k = " + to_string(k) + "; result = " + to_string(result));

    bloomDay = { 7,7,7,7,12,7,7 };
    m = 2;
    k = 3;
    result = leetCode.minDays(bloomDay, m, k);
    Logger::WriteMessage(bloomDay);
    Logger::WriteMessage("m = " + to_string(m) + "; k = " + to_string(k) + "; result = " + to_string(result));

    bloomDay = { 1000000000,1000000000 };
    m = 1;
    k = 1;
    result = leetCode.minDays(bloomDay, m, k);
    Logger::WriteMessage(bloomDay);
    Logger::WriteMessage("m = " + to_string(m) + "; k = " + to_string(k) + "; result = " + to_string(result));

    bloomDay = { 1,10,2,9,3,8,4,7,5,6 };
    m = 4;
    k = 2;
    result = leetCode.minDays(bloomDay, m, k);
    Logger::WriteMessage(bloomDay);
    Logger::WriteMessage("m = " + to_string(m) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1552(void)
{
    Logger::WriteMessage("Test Leet Code 1552");
    LeetCodeBinarySearch leetCode;
    vector<int> position = { 1, 2, 3, 4, 7 };
    int m = 3;
    int result = leetCode.maxDistance(position, m);
    Logger::WriteMessage(position);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));

    position = { 5,4,3,2,1,1000000000 };
    m = 2;
    result = leetCode.maxDistance(position, m);
    Logger::WriteMessage(position);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));

    position = { 79, 74, 57, 22 };
    m = 4;
    result = leetCode.maxDistance(position, m);
    Logger::WriteMessage(position);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));
}

void TestLeetCode1760(void)
{
    Logger::WriteMessage("Test Leet Code 1760");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 9 };
    int maxOperations = 2;
    int result = leetCode.minimumSize(nums, maxOperations);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("maxOperations = " + to_string(maxOperations) + "; result = " + to_string(result));

    nums = { 2,4,8,2 };
    maxOperations = 4;
    result = leetCode.minimumSize(nums, maxOperations);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("maxOperations = " + to_string(maxOperations) + "; result = " + to_string(result));

    nums = { 7,17 };
    maxOperations = 2;
    result = leetCode.minimumSize(nums, maxOperations);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("maxOperations = " + to_string(maxOperations) + "; result = " + to_string(result));
}

void TestLeetCode1802(void)
{
    Logger::WriteMessage("Test Leet Code 1802");
    LeetCodeBinarySearch leetCode;
    int n = 4;
    int index = 2;
    int maxSum = 6;
    int result = leetCode.maxValue(n, index, maxSum);
    Logger::WriteMessage("n = " + to_string(n) + "; index = " + to_string(index) +
        "; maxSum = " + to_string(maxSum) + "; result = " + to_string(result));

    n = 6;
    index = 1;
    maxSum = 10;
    result = leetCode.maxValue(n, index, maxSum);
    Logger::WriteMessage("n = " + to_string(n) + "; index = " + to_string(index) +
        "; maxSum = " + to_string(maxSum) + "; result = " + to_string(result));

    n = 4;
    index = 0;
    maxSum = 4;
    result = leetCode.maxValue(n, index, maxSum);
    Logger::WriteMessage("n = " + to_string(n) + "; index = " + to_string(index) +
        "; maxSum = " + to_string(maxSum) + "; result = " + to_string(result));
}

void TestLeetCode1870(void)
{
    Logger::WriteMessage("Test Leet Code 1870");
    LeetCodeBinarySearch leetCode;
    vector<int> dist = { 1, 3, 2 };
    double hour = 6;
    int result = leetCode.minSpeedOnTime(dist, hour);
    Logger::WriteMessage(dist);
    Logger::WriteMessage("hour = " + to_string(hour) + "; result =" + to_string(result));

    dist = { 1, 3, 2 };
    hour = 2.7;
    result = leetCode.minSpeedOnTime(dist, hour);
    Logger::WriteMessage(dist);
    Logger::WriteMessage("hour = " + to_string(hour) + "; result =" + to_string(result));

    dist = { 1,3,2 };
    hour = 1.9;
    result = leetCode.minSpeedOnTime(dist, hour);
    Logger::WriteMessage(dist);
    Logger::WriteMessage("hour = " + to_string(hour) + "; result =" + to_string(result));
}

void TestLeetCode1923(void)
{
    Logger::WriteMessage("Test Leet Code 1923");
    LeetCodeBinarySearch leetCode;
    int n = 5;
    vector<vector<int>> paths =
    { 
        {0, 1, 2, 3, 4}, {2, 3, 4}, {4, 0, 1, 2, 3} 
    };
    int result = leetCode.longestCommonSubpath(n, paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage("result = " + to_string(result));

    n = 5;
    paths =
    {
        {0}, {1}, {2}
    };
    result = leetCode.longestCommonSubpath(n, paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage("result = " + to_string(result));

    n = 5;
    paths =
    {
        {0, 1, 2, 3, 4}, {4, 3, 2, 1, 0}
    };
    result = leetCode.longestCommonSubpath(n, paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1898(void)
{
    Logger::WriteMessage("Test Leet Code 1898");
    LeetCodeBinarySearch leetCode;
    string s = "abcacb";
    string p = "ab";
    vector<int> removable = { 3, 1, 0 };
    int result = leetCode.maximumRemovals(s, p, removable);
    Logger::WriteMessage(removable);
    Logger::WriteMessage("s = " + s + "; p = " + s +  "; result = " + to_string(result));

    s = "abcbddddd";
    p = "abcd";
    removable = { 3,2,1,4,5,6 };
    result = leetCode.maximumRemovals(s, p, removable);
    Logger::WriteMessage(removable);
    Logger::WriteMessage("s = " + s +"; p = " + s + "; result = " + to_string(result));

    s = "abcab";
    p = "abc";
    removable = { 0,1,2,3,4 };
    result = leetCode.maximumRemovals(s, p, removable);
    Logger::WriteMessage(removable);
    Logger::WriteMessage("s = " + s + "; p = " + s + "; result = " + to_string(result));

    s = "qobftgcueho";
    p = "obue";
    removable = { 5, 3, 0, 6, 4, 9, 10, 7, 2, 8 };
    result = leetCode.maximumRemovals(s, p, removable);
    Logger::WriteMessage(removable);
    Logger::WriteMessage("s = " + s + "; p = " + s + "; result = " + to_string(result));
}

void TestLeetCode2040(void)
{
    Logger::WriteMessage("Test Leet Code 2040");
    LeetCodeBinarySearch leetCode;
    vector<int> nums1 = { 2, 5 };
    vector<int> nums2 = { 3, 4 };
    int k = 2;
    long long result = leetCode.kthSmallestProduct(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums1 = { -4,-2,0,3 };
    nums2 = { 2,4 };
    k = 6;
    result = leetCode.kthSmallestProduct(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums1 = { -2,-1,0,1,2 };
    nums2 = { -3,-1,2,4,5 };
    k = 3;
    result = leetCode.kthSmallestProduct(nums1, nums2, k);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2089(void)
{
    Logger::WriteMessage("Test Leet Code 2089");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 1, 2, 5, 2, 3 };
    int target = 2;
    vector<int> result = leetCode.targetIndices(nums, target);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 1,2,5,2,3 };
    target = 3;
    result = leetCode.targetIndices(nums, target);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 1,2,5,2,3 };
    target = 5;
    result = leetCode.targetIndices(nums, target);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 1,2,5,2,3 };
    target = 4;
    result = leetCode.targetIndices(nums, target);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1891(void)
{
    Logger::WriteMessage("Test Leet Code 1891");
    LeetCodeBinarySearch leetCode;
    vector<int> ribbons = { 9, 7, 5 };
    int k = 3;
    int result = leetCode.maxLength(ribbons, k);
    Logger::WriteMessage(ribbons);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    ribbons = { 7,5,9 };
    k = 4;
    result = leetCode.maxLength(ribbons, k);
    Logger::WriteMessage(ribbons);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    ribbons = { 5,7,9 };
    k = 22;
    result = leetCode.maxLength(ribbons, k);
    Logger::WriteMessage(ribbons);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1918(void)
{
    Logger::WriteMessage("Test Leet Code 1918");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 2, 1, 3 };
    int k = 4;
    int result = leetCode.kthSmallestSubarraySum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 3,3,5,5 };
    k = 7;
    result = leetCode.kthSmallestSubarraySum(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2064(void)
{
    Logger::WriteMessage("Test Leet Code 2064");
    LeetCodeBinarySearch leetCode;
    int n = 6;
    vector<int> quantities = { 11, 6 };
    int result = leetCode.minimizedMaximum(n, quantities);
    Logger::WriteMessage(quantities);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7;
    quantities = { 15,10,10 };
    result = leetCode.minimizedMaximum(n, quantities);
    Logger::WriteMessage(quantities);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 1;
    quantities = { 100000 };
    result = leetCode.minimizedMaximum(n, quantities);
    Logger::WriteMessage(quantities);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2141(void)
{
    Logger::WriteMessage("Test Leet Code 2141");
    LeetCodeBinarySearch leetCode;
    int n = 2;
    vector<int> batteries = { 3, 3, 13 };
    long long result = leetCode.maxRunTime(n, batteries);
    Logger::WriteMessage(batteries);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    batteries = { 1, 1, 1, 1 };
    result = leetCode.maxRunTime(n, batteries);
    Logger::WriteMessage(batteries);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2137(void)
{
    Logger::WriteMessage("Test Leet Code 2137");
    LeetCodeBinarySearch leetCode;
    vector<int> buckets = { 1, 2, 7 };
    int loss = 80;
    double result = leetCode.equalizeWater(buckets, loss);
    Logger::WriteMessage(buckets);
    Logger::WriteMessage("loss = " + to_string(loss) + "; result = " + to_string(result));

    buckets = { 2,4,6 };
    loss = 50;
    result = leetCode.equalizeWater(buckets, loss);
    Logger::WriteMessage(buckets);
    Logger::WriteMessage("loss = " + to_string(loss) + "; result = " + to_string(result));

    buckets = { 3,3,3,3 };
    loss = 40;
    result = leetCode.equalizeWater(buckets, loss);
    Logger::WriteMessage(buckets);
    Logger::WriteMessage("loss = " + to_string(loss) + "; result = " + to_string(result));
}

void TestLeetCode2187(void)
{
    Logger::WriteMessage("Test Leet Code 2187");
    LeetCodeBinarySearch leetCode;
    vector<int> time = { 1, 2, 3 };
    int totalTrips = 5;
    long long result = leetCode.minimumTime(time, totalTrips);
    Logger::WriteMessage(time);
    Logger::WriteMessage("totalTrips = " + to_string(totalTrips) + "; result = " + to_string(result));

    time = { 2 };
    totalTrips = 1;
    result = leetCode.minimumTime(time, totalTrips);
    Logger::WriteMessage(time);
    Logger::WriteMessage("totalTrips = " + to_string(totalTrips) + "; result = " + to_string(result));

    time = { 690709, 79, 156068, 359659 };
    totalTrips = 985484;
    result = leetCode.minimumTime(time, totalTrips);
    Logger::WriteMessage(time);
    Logger::WriteMessage("totalTrips = " + to_string(totalTrips) + "; result = " + to_string(result));
}

void TestLeetCode2226(void)
{
    Logger::WriteMessage("Test Leet Code 2226");
    LeetCodeBinarySearch leetCode;
    vector<int> candies = { 5, 8, 6 };
    int k = 3;
    int result = leetCode.maximumCandies(candies, k);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    candies = { 2,5 };
    k = 11;
    result = leetCode.maximumCandies(candies, k);
    Logger::WriteMessage(candies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2468(void)
{
    Logger::WriteMessage("Test Leet Code 2468");
    LeetCodeBinarySearch leetCode;
    string message = "this is really a very awesome message";
    int limit = 9;
    vector<string> result = leetCode.splitMessage(message, limit);
    Logger::WriteMessage("message = " + message + "; limit = " + to_string(limit));
    Logger::WriteMessage(result);
    
    message = "short message";
    limit = 15;
    result = leetCode.splitMessage(message, limit);
    Logger::WriteMessage("message = " + message + "; limit = " + to_string(limit));
    Logger::WriteMessage(result);

    message = "abcdefghijklmnopqrstu";
    limit = 8;
    result = leetCode.splitMessage(message, limit);
    Logger::WriteMessage("message = " + message + "; limit = " + to_string(limit));
    Logger::WriteMessage(result);
}

void TestLeetCode2513(void)
{
    Logger::WriteMessage("Test Leet Code 2513");
    LeetCodeBinarySearch leetCode;
    int divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3;
    int result = leetCode.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    Logger::WriteMessage("divisor1 = " + to_string(divisor1) + "; divisor2 = " + to_string(divisor2));
    Logger::WriteMessage("uniqueCnt1 = " + to_string(uniqueCnt1) + "; uniqueCnt2 = " + to_string(uniqueCnt2));
    Logger::WriteMessage("result = " + to_string(result));

    divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1;
    result = leetCode.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    Logger::WriteMessage("divisor1 = " + to_string(divisor1) + "; divisor2 = " + to_string(divisor2));
    Logger::WriteMessage("uniqueCnt1 = " + to_string(uniqueCnt1) + "; uniqueCnt2 = " + to_string(uniqueCnt2));
    Logger::WriteMessage("result = " + to_string(result));

    divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2;
    result = leetCode.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    Logger::WriteMessage("divisor1 = " + to_string(divisor1) + "; divisor2 = " + to_string(divisor2));
    Logger::WriteMessage("uniqueCnt1 = " + to_string(uniqueCnt1) + "; uniqueCnt2 = " + to_string(uniqueCnt2));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2517(void)
{
    Logger::WriteMessage("Test Leet Code 2517");
    LeetCodeBinarySearch leetCode;
    vector<int> price = { 13, 5, 1, 8, 21, 2 };
    int k = 3;
    int result = leetCode.maximumTastiness(price, k);
    Logger::WriteMessage(price);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    price = { 1,3,1 };
    k = 2;
    result = leetCode.maximumTastiness(price, k);
    Logger::WriteMessage(price);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    price = { 7,7,7,7 };
    k = 2;
    result = leetCode.maximumTastiness(price, k);
    Logger::WriteMessage(price);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2528(void)
{
    Logger::WriteMessage("Test Leet Code 2528");
    LeetCodeBinarySearch leetCode;
    vector<int> stations = { 1, 2, 4, 5, 0 };
    int r = 1, k = 2;
    long long result = leetCode.maxPower(stations, r, k);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("r = " + to_string(r) + "; k = " + to_string(k) + "; result = " + to_string(result));

    stations = { 4,4,4,4 };
    r = 0, k = 3;
    result = leetCode.maxPower(stations, r, k);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("r = " + to_string(r) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2560(void)
{
    Logger::WriteMessage("Test Leet Code 2560");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 2, 3, 5, 9 };
    int k = 2;
    int result = leetCode.minCapability(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2, 7, 9, 3, 1 }; 
    k = 2;
    result = leetCode.minCapability(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2563(void)
{
    Logger::WriteMessage("Test Leet Code 2563");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 0,1,7,4,4,5 };
    int lower = 3;
    int upper = 6;
    long long result = leetCode.countFairPairs(nums, lower, upper);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("lower = " + to_string(lower) + "; upper = " + to_string(upper) + "; result = " + to_string(result));

    nums = { 1,7,9,2,5 };
    lower = 11;
    upper = 11;
    result = leetCode.countFairPairs(nums, lower, upper);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("lower = " + to_string(lower) + "; upper = " + to_string(upper) + "; result = " + to_string(result));
}

void TestLeetCode2604(void)
{
    Logger::WriteMessage("Test Leet Code 2604");
    LeetCodeBinarySearch leetCode;
    vector<int> hens = { 3, 6, 7 };
    vector<int> grains = { 2, 4, 7, 9 };
    int result = leetCode.minimumTime(hens, grains);
    Logger::WriteMessage(hens);
    Logger::WriteMessage(grains);
    Logger::WriteMessage("result = " + to_string(result));

    hens = { 4,6,109,111,213,215 };
    grains = { 5,110,214 };
    result = leetCode.minimumTime(hens, grains);
    Logger::WriteMessage(hens);
    Logger::WriteMessage(grains);
    Logger::WriteMessage("result = " + to_string(result));

    hens = { 1,9,4 };
    grains = { 8,9,2,4,1 };
    result = leetCode.minimumTime(hens, grains);
    Logger::WriteMessage(hens);
    Logger::WriteMessage(grains);
    Logger::WriteMessage("result = " + to_string(result));

    hens = { 6, 0, 4 };
    grains = { 8,7 };
    result = leetCode.minimumTime(hens, grains);
    Logger::WriteMessage(hens);
    Logger::WriteMessage(grains);
    Logger::WriteMessage("result = " + to_string(result));

    hens = { 10,5,7,8 };
    grains = { 1 };
    result = leetCode.minimumTime(hens, grains);
    Logger::WriteMessage(hens);
    Logger::WriteMessage(grains);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2616(void)
{
    Logger::WriteMessage("Test Leet Code 2616");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 10,1,2,7,1,3 };
    int p = 2;
    int result = leetCode.minimizeMax(nums, p);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("p = " + to_string(p) + "; result = " + to_string(result));

    nums = { 4,2,1,2 };
    p = 1;
    result = leetCode.minimizeMax(nums, p);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("p = " + to_string(p) + "; result = " + to_string(result));

    nums = { 1,2,1,2, 3, 5 };
    p = 3;
    result = leetCode.minimizeMax(nums, p);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("p = " + to_string(p) + "; result = " + to_string(result));
}

void TestLeetCode2702(void)
{
    Logger::WriteMessage("Test Leet Code 2702");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 3,4,1,7,6 };
    int x = 4, y = 2;
    int result = leetCode.minOperations(nums, x, y);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y));
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,1 };
    x = 2, y = 1;
    result = leetCode.minOperations(nums, x, y);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2819(void)
{
    Logger::WriteMessage("Test Leet Code 2819");
    LeetCodeBinarySearch leetCode;
    vector<int> prices = { 1, 9, 22, 10, 19 };
    vector<vector<int>> queries = { {18, 4},{5, 2} };
    vector<long long> result = leetCode.minimumRelativeLosses(prices, queries);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    prices = { 1, 5, 4, 3, 7, 11, 9 };
    queries = { {5, 4},{5, 7},{7, 3},{4, 5} };
    result = leetCode.minimumRelativeLosses(prices, queries);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    prices = { 5, 6, 7 };
    queries = { {10, 1} ,{5, 3},{3, 3} };
    result = leetCode.minimumRelativeLosses(prices, queries);
    Logger::WriteMessage(prices);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode2861(void)
{
    Logger::WriteMessage("Test Leet Code 2861");
    LeetCodeBinarySearch leetCode;
    int n = 3, k = 2, budget = 15;
    vector<vector<int>> composition = 
    { 
        {1, 1, 1},{1, 1, 10} 
    };
    vector<int> stock = { 0, 0, 0 };
    vector<int> cost = { 1, 2, 3 };
    int result = leetCode.maxNumberOfAlloys(n, k, budget, composition, stock, cost);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("budget = " + to_string(budget));
    Logger::WriteMessage(composition);
    Logger::WriteMessage(stock);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3, k = 2, budget = 15;
    composition =
    {
        {1, 1, 1},{1, 1, 10}
    };
    stock = { 0,0,100 };
    cost = { 1, 2, 3 };
    result = leetCode.maxNumberOfAlloys(n, k, budget, composition, stock, cost);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("budget = " + to_string(budget));
    Logger::WriteMessage(composition);
    Logger::WriteMessage(stock);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    n = 2, k = 3, budget = 10; 
    composition = { {2, 1},{1, 2},{1, 1} }; 
    stock = { 1, 1 }; 
    cost = { 5, 5 };
    result = leetCode.maxNumberOfAlloys(n, k, budget, composition, stock, cost);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("budget = " + to_string(budget));
    Logger::WriteMessage(composition);
    Logger::WriteMessage(stock);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    n = 1, k = 7, budget = 48;
    composition = { {2, 1},{1, 2},{1, 1} };
    stock = { 1, 1 };
    cost = { 5, 5 };
    result = leetCode.maxNumberOfAlloys(n, k, budget, composition, stock, cost);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("budget = " + to_string(budget));
    Logger::WriteMessage(composition);
    Logger::WriteMessage(stock);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2936(void)
{
    Logger::WriteMessage("Test Leet Code 2936");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 3, 3, 3, 3, 3 };
    int result = leetCode.countBlocks(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,1,1,3,9,9,9,2,10,10 };
    result = leetCode.countBlocks(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,5,6,7 };
    result = leetCode.countBlocks(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3007(void)
{
    Logger::WriteMessage("Test Leet Code 3007");
    LeetCodeBinarySearch leetCode;
    long long k = 9;
    int x = 1;
    long long result = leetCode.findMaximumNumber(k, x);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage("result = " + to_string(result));

    k = 7;
    x = 2;
    result = leetCode.findMaximumNumber(k, x);
    Logger::WriteMessage("k = " + to_string(k) + "; x = " + to_string(x));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3048(void)
{
    Logger::WriteMessage("Test Leet Code 3048");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 2,2,0 };
    vector<int> changeIndices = { 2,2,2,2,3,2,2,1 };
    int result = leetCode.earliestSecondToMarkIndicesI(nums, changeIndices);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(changeIndices);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,3 };
    changeIndices = { 1,1,1,2,1,1,1 };
    result = leetCode.earliestSecondToMarkIndicesI(nums, changeIndices);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(changeIndices);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0,1 };
    changeIndices = { 2,2,2 };
    result = leetCode.earliestSecondToMarkIndicesI(nums, changeIndices);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(changeIndices);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3049(void)
{
    Logger::WriteMessage("Test Leet Code 3049");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 3, 2, 3 };
    vector<int> changeIndices = { 1, 3, 2, 2, 2, 2, 3 };
    int result = leetCode.earliestSecondToMarkIndicesII(nums, changeIndices);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(changeIndices);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 0,0,1,2 };
    changeIndices = { 1,2,1,2,1,2,1,2 };
    result = leetCode.earliestSecondToMarkIndicesII(nums, changeIndices);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(changeIndices);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3 };
    changeIndices = { 1,2,3 };
    result = leetCode.earliestSecondToMarkIndicesII(nums, changeIndices);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(changeIndices);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3134(void)
{
    Logger::WriteMessage("Test Leet Code 3134");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 1,2,3 };
    int result = leetCode.medianOfUniquenessArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,4,3,4,5 };
    result = leetCode.medianOfUniquenessArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,3,5,4 };
    result = leetCode.medianOfUniquenessArray(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3181(void)
{
    Logger::WriteMessage("Test Leet Code 3181");
    LeetCodeBinarySearch leetCode;
    vector<int> start = { 6, 0, 3 };
    int d = 2;
    int result = leetCode.maxPossibleScore(start, d);
    Logger::WriteMessage(start);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));

    start = { 2,6,13,13 };
    d = 5;
    result = leetCode.maxPossibleScore(start, d);
    Logger::WriteMessage(start);
    Logger::WriteMessage("d = " + to_string(d) + "; result = " + to_string(result));
}

void TestLeetCode3350(void)
{
    Logger::WriteMessage("Test Leet Code 3350");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 2, 5, 7, 8, 9, 2, 3, 4, 3, 1 };
    int result = leetCode.maxIncreasingSubarrays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,4,4,4,5,6,7 };
    result = leetCode.maxIncreasingSubarrays(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3344(void)
{
    Logger::WriteMessage("Test Leet Code 3344");
    LeetCodeBinarySearch leetCode;
    long long s = 10;
    int result = leetCode.maxSizedArray(s);
    Logger::WriteMessage("s = " + to_string(s) + "; result = " + to_string(result));

    s = 0;
    result = leetCode.maxSizedArray(s);
    Logger::WriteMessage("s = " + to_string(s) + "; result = " + to_string(result));

    s = 1000000000000000;
    result = leetCode.maxSizedArray(s);
    Logger::WriteMessage("s = " + to_string(s) + "; result = " + to_string(result));
}

void TestLeetCode3357(void)
{
    Logger::WriteMessage("Test Leet Code 3357");
    LeetCodeBinarySearch leetCode;
    vector<int> nums = { 1, 2, -1, 10, 8 };
    int result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -1,-1,-1 };
    result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { -1,10,-1,8 };
    result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 12 };
    result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, -1, 4, -1, -1, 6 };
    result = leetCode.minDifference(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3398(void)
{
    Logger::WriteMessage("Test Leet Code 3398");
    LeetCodeBinarySearch leetCode;
    string s = "000001";
    int numOps = 1;
    int result = leetCode.minLengthI(s, numOps);
    Logger::WriteMessage("s = " + s + "; numOps = " + to_string(numOps) + "; result = " + to_string(result));

    s = "0000";
    numOps = 2;
    result = leetCode.minLengthI(s, numOps);
    Logger::WriteMessage("s = " + s + "; numOps = " + to_string(numOps) + "; result = " + to_string(result));

    s = "0101";
    numOps = 0;
    result = leetCode.minLengthI(s, numOps);
    Logger::WriteMessage("s = " + s + "; numOps = " + to_string(numOps) + "; result = " + to_string(result));
}

void TestLeetCode3399(void)
{
    Logger::WriteMessage("Test Leet Code 3399");
    LeetCodeBinarySearch leetCode;
    string s = "000001";
    int numOps = 1;
    int result = leetCode.minLengthI(s, numOps);
    Logger::WriteMessage("s = " + s + "; numOps = " + to_string(numOps) + "; result = " + to_string(result));

    s = "0000";
    numOps = 2;
    result = leetCode.minLengthI(s, numOps);
    Logger::WriteMessage("s = " + s + "; numOps = " + to_string(numOps) + "; result = " + to_string(result));

    s = "0101";
    numOps = 0;
    result = leetCode.minLengthI(s, numOps);
    Logger::WriteMessage("s = " + s + "; numOps = " + to_string(numOps) + "; result = " + to_string(result));
}

void TestLeetCode3453(void)
{
    Logger::WriteMessage("Test Leet Code 3453");
    LeetCodeBinarySearch leetCode;
    vector<vector<int>> squares = { {0, 0, 1},{2, 2, 1} };
    double result = leetCode.separateSquares(squares);
    Logger::WriteMessage(squares);
    Logger::WriteMessage("result = " + to_string(result));

    squares = { {0, 0, 2},{1, 1, 1} };
    result = leetCode.separateSquares(squares);
    Logger::WriteMessage(squares);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3449(void)
{
    Logger::WriteMessage("Test Leet Code 3449");
    LeetCodeBinarySearch leetCode;
    vector<int> points = { 2, 4 };
    int m = 3;
    long long result = leetCode.maxScore(points, m);
    Logger::WriteMessage(points);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));

    points = { 1,2,3 };
    m = 5;
    result = leetCode.maxScore(points, m);
    Logger::WriteMessage(points);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));

    points = { 1, 24, 2 };
    m = 25;
    result = leetCode.maxScore(points, m);
    Logger::WriteMessage(points);
    Logger::WriteMessage("m = " + to_string(m) + "; result = " + to_string(result));
}

void TestLeetCode3506(void)
{
    Logger::WriteMessage("Test Leet Code 3506");
    LeetCodeBinarySearch leetCode;
    vector<int> timeReq = { 10, 4, 5 };
    int splitTime = 2;
    long long result = leetCode.minEliminationTime(timeReq, splitTime);
    Logger::WriteMessage(timeReq);
    Logger::WriteMessage("splitTime = " + to_string(splitTime) + "; result = " + to_string(result));

    timeReq = { 10, 4 };
    splitTime = 5;
    result = leetCode.minEliminationTime(timeReq, splitTime);
    Logger::WriteMessage(timeReq);
    Logger::WriteMessage("splitTime = " + to_string(splitTime) + "; result = " + to_string(result));
}

void TestLeetCodeBinarySearch(void)
{
    TestLeetCode3506();
    TestLeetCode3449();
    TestLeetCode3453();
    TestLeetCode3399();
    TestLeetCode3398();
    TestLeetCode3357();
    TestLeetCode3344();
    TestLeetCode3350();
    TestLeetCode3181();
    TestLeetCode3134();
    TestLeetCode3048();
    TestLeetCode3049();
    TestLeetCode3007();
    TestLeetCode2936();
    TestLeetCode153();
    TestLeetCode162();
    TestLeetCode35();
    TestLeetCode2861();
    TestLeetCode2819();
    TestLeetCode2702();
    TestLeetCode2616();
    TestLeetCode2604();
    TestLeetCode2563();
    TestLeetCode2560();
    TestLeetCode2528();
    TestLeetCode2517();
    TestLeetCode2513();
    TestLeetCode2468();
    TestLeetCode2226();
    TestLeetCode2187();
    TestLeetCode2137();
    TestLeetCode2141();
    TestLeetCode2064();
    TestLeetCode1918();
    TestLeetCode1891();
    TestLeetCode2089();
    TestLeetCode2040();
    TestLeetCode1898();
    TestLeetCode1923();
    TestLeetCode1870();
    TestLeetCode1802();
    TestLeetCode1760();
    TestLeetCode1552();
    TestLeetCode1482();
    TestLeetCode1064();
    TestLeetCode374();
    TestLeetCode275();
    TestLeetCode367();
    TestLeetCode278();
    TestLeetCode704();
    TestLeetCode1060();
    TestLeetCode69();
    TestLeetCode852();
    TestLeetCode74();
    TestLeetCode702();
    TestLeetCode668();
    TestLeetCode540();
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
    TestLeetCode154();
    TestLeetCode240();
    TestLeetCode875();
    TestLeetCode878();
    TestLeetCode1011();
    TestLeetCode1231();
}