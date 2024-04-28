#pragma once
#ifndef LeetCodeBinarySearch_H
#define LeetCodeBinarySearch_H
#include <stdint.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> 
#include <functional> 
#include <bitset> 
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <vector> 
#include <stack> 
#include "leetcode.h"
using namespace std;
/// <summary>
/// The class is to implement binary search related algorithm  
/// </summary>
class LeetCodeBinarySearch
{
public:
#pragma region BinarySearch

    /// <summary>
    /// Leet code #35. Search Insert Position   
    /// Given a sorted array and a target value, return the index if the target is found. If not, 
    /// return the index where it would be if it were inserted in order. 
    /// You may assume no duplicates in the array. 
    /// Here are few examples.
    /// [1,3,5,6], 5 -> 2
    /// [1,3,5,6], 2 -> 1
    /// [1,3,5,6], 7 -> 4
    /// [1,3,5,6], 0 -> 0 
    /// </summary>
    int searchInsert(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #74. Search a 2D Matrix   
    /// Write an efficient algorithm that searches for a value in an m x n matrix. 
    /// This matrix has the following properties:
    /// Integers in each row are sorted from left to right. 
    /// The first integer of each row is greater than the last integer of the 
    /// previous row.	
    /// For example, 
    /// Consider the following matrix:
    /// [
    ///   [1,   3,  5,  7],
    ///   [10, 11, 16, 20],
    ///   [23, 30, 34, 50]
    /// ]
    /// Given target = 3, return true.
    /// </summary>
    bool searchMatrix(vector<vector<int>>& matrix, int target);

    /// <summary>
    /// Leet code #374. Guess Number Higher or Lower 
    /// We are playing the Guess Game. The game is as follows:
    /// I pick a number from 1 to n. You have to guess which number I picked.
    /// Every time you guess wrong, I'll tell you whether the number is higher or lower.
    /// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
    /// -1 : My number is lower
    /// 1 : My number is higher
    /// 0 : Congrats! You got it!
    /// Example:
    /// n = 10, I pick 6.
    /// Return 6.
    /// </summary>
    int guessNumber(int n, int guess);

    /// <summary>
    /// Leet code #69. Sqrt(x) 
    /// Implement int sqrt(int x). 
    /// Compute and return the square root of x. 
    /// </summary>
    int mySqrt(int x);

    /// <summary>
    /// Leet code #367. Valid Perfect Square 
    /// Given a positive integer num, write a function which returns True if num is a perfect square else False.
    /// Note: Do not use any built-in library function such as sqrt. 
    /// Example 1: 
    /// Input: 16
    /// Returns: True
    ///
    /// Example 2: 
    /// Input: 14
    /// Returns: False
    /// </summary>
    bool isPerfectSquare(int num);

    /// <summary>
    /// Leet code #278. First Bad Version  
    /// You are a product manager and currently leading a team to develop a new product. 
    /// Unfortunately, the latest version of your product fails the quality check. Since each version 
    /// is developed based on the previous version, all the versions after a bad version are also bad. 
    /// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad. 
    /// You are given an API bool isBadVersion(version) which will return whether version is bad. 
    /// Implement a function to find the first bad version. You should minimize the number of calls to the API. 
    /// </summary>
    int firstBadVersion(int n, int bad_version);

    /// <summary>
    /// Leet Code 275. H-Index II
    ///                                                                 
    /// Medium
    /// 
    /// Given an array of integers citations where citations[i] is the number 
    /// of citations a researcher received for their ith paper and citations 
    /// is sorted in an ascending order, return compute the researcher's 
    /// h-index.
    ///
    /// According to the definition of h-index on Wikipedia: A scientist has 
    /// an index h if h of their n papers have at least h citations each, and 
    /// the other n - h papers have no more than h citations each.
    /// 
    /// If there are several possible values for h, the maximum one is taken 
    /// as the h-index.
    ///
    /// You must write an algorithm that runs in logarithmic time.
    /// 
    /// Example 1:
    /// Input: citations = [0,1,3,5,6]
    /// Output: 3
    /// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total 
    /// and each of them had received 0, 1, 3, 5, 6 citations respectively.
    /// Since the researcher has 3 papers with at least 3 citations each and 
    /// the remaining two with no more than 3 citations each, their h-index 
    /// is 3.
    ///
    /// Example 2:
    /// Input: citations = [1,2,100]
    /// Output: 2
    ///
    /// Constraints:
    /// 1. n == citations.length
    /// 2. 1 <= n <= 10^5
    /// 3. 0 <= citations[i] <= 1000
    /// 4. citations is sorted in ascending order.
    /// </summary>
    int hIndexII(vector<int>& citations);

    /// <summary>
    /// Leet code #540. Single Element in a Sorted Array
    /// 
    /// Given a sorted array consisting of only integers where every element 
    /// appears twice except for one element which appears once. Find this 
    /// single element that appears only once. 
    /// Example 1:
    /// Input: [1,1,2,3,3,4,4,8,8]
    /// Output: 2
    ///
    /// Example 2:
    /// Input: [3,3,7,7,10,11,11]
    /// Output: 10
    /// Note: Your solution should run in O(log n) time and O(1) space. 
    /// </summary>
    int singleNonDuplicate(vector<int>& nums);


    /// <summary>
    /// Leet code #668. Kth Smallest Number in Multiplication Table
    /// Nearly every one have used the Multiplication Table. But could you 
    /// find out the k-th smallest number quickly from the multiplication 
    /// table?
    ///
    /// Given the height m and the length n of a m * n Multiplication Table, 
    /// and a positive integer k, you need to return the k-th smallest number 
    /// in this table.
    ///
    /// Example 1:
    /// Input: m = 3, n = 3, k = 5
    /// Output: 3 
    /// Explanation: 
    /// The Multiplication Table:
    /// 1    2    3
    /// 2    4    6
    /// 3    6    9
    ///
    /// The 5-th smallest number is 3 (1, 2, 2, 3, 3).
    /// Example 2:
    /// Input: m = 2, n = 3, k = 6
    /// Output: 
    /// Explanation: 
    /// The Multiplication Table:
    /// 1    2    3
    /// 2    4    6
    ///
    /// The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
    /// Note:
    /// The m and n will be in the range [1, 30000].
    /// The k will be in the range [1, m * n]
    /// </summary>
    int findKthNumber(int m, int n, int k);


    /// <summary>
    /// Leet code #852. Peak Index in a Mountain Array
    /// 
    /// Let's call an array A a mountain if the following properties hold:
    ///
    /// A.length >= 3
    /// There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] 
    /// < A[i] > A[i+1] > ... > A[A.length - 1]
    /// Given an array that is definitely a mountain, return any i such that 
    /// A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
    ///
    /// Example 1:
    ///
    /// Input: [0,1,0]
    /// Output: 1
    ///
    /// Example 2:
    ///
    /// Input: [0,2,1,0]
    /// Output: 1
    /// Note:
    /// 
    /// 1. 3 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 10^6
    /// 3. A is a mountain, as defined above.
    /// </summary>
    int peakIndexInMountainArray(vector<int>& A);

    /// <summary>
    /// Leet code #704. Binary Search
    /// 
    /// Given a sorted (in ascending order) integer array nums of n elements 
    /// and a target value, write a function to search target in nums. If 
    /// target exists, then return its index, otherwise return -1.
    ///
    /// Example 1:
    ///
    /// Input: nums = [-1,0,3,5,9,12], target = 9
    /// Output: 4
    /// Explanation: 9 exists in nums and its index is 4
    ///
    /// Example 2:
    ///
    /// Input: nums = [-1,0,3,5,9,12], target = 2
    /// Output: -1
    /// Explanation: 2 does not exist in nums so return -1
    /// 
    /// Note:
    /// 1. You may assume that all elements in nums are unique.
    /// 2. n will be in the range [1, 10000].
    /// 3. The value of each element in nums will be in the range 
    /// [-9999, 9999].
    /// </summary>
    int binarySearchI(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #702. Search in a Sorted Array of Unknown Size
    /// 
    /// Given an integer array sorted in ascending order, write a function to 
    /// search target in nums.  If target exists, then return its index, otherwise 
    /// return -1. However, the array size is unknown to you. You may only access 
    /// the array using an ArrayReader interface, where ArrayReader.get(k) 
    /// returns the element of the array at index k (0-indexed).
    ///
    /// You may assume all integers in the array are less than 10000, and if you 
    /// access the array out of bounds, ArrayReader.get will return 2147483647.
    ///
    /// Example 1:
    /// Input: array = [-1,0,3,5,9,12], target = 9
    /// Output: 4
    /// Explanation: 9 exists in nums and its index is 4
    ///
    /// Example 2:
    /// Input: array = [-1,0,3,5,9,12], target = 2
    /// Output: -1
    /// Explanation: 2 does not exist in nums so return -1
    /// 
    /// Note:
    ///
    /// 1. You may assume that all elements in the array are unique.
    /// 2. The value of each element in the array will be in the range 
    ///    [-9999, 9999].
    /// </summary>
    int searchStream(const vector<int>& reader, int target);


    /// <summary>
    /// Leet code #1064. Fixed Point
    /// 
    /// Given an array A of distinct integers sorted in ascending order, return 
    /// the smallest index i that satisfies A[i] == i.  Return -1 if no such i 
    /// exists.
    ///
    /// Example 1:
    ///
    /// Input: [-10,-5,0,3,7]
    /// Output: 3
    /// Explanation: 
    /// For the given array, A[0] = -10, A[1] = -5, A[2] = 0, A[3] = 3, thus the 
    /// output is 3.
    ///
    /// Example 2:
    ///
    /// Input: [0,2,5,8,17]
    /// Output: 0
    /// Explanation: 
    /// A[0] = 0, thus the output is 0.
    ///
    /// Example 3:
    ///
    /// Input: [-10,-5,3,4,7,9]
    /// Output: -1
    /// Explanation: 
    /// There is no such i that A[i] = i, thus the output is -1.
    /// 
    /// Note:
    /// 1. 1 <= A.length < 10^4
    /// 2. -10^9 <= A[i] <= 10^9
    /// </summary>
    int fixedPoint(vector<int>& A);

    /// <summary>
    /// Leet code 1060. Missing Element in Sorted Array
    /// 
    /// Given a sorted array A of unique numbers, find the K-th missing number 
    /// starting from the leftmost number of the array.
    ///
    /// Example 1:
    /// Input: A = [4,7,9,10], K = 1
    /// Output: 5
    /// Explanation: 
    /// The first missing number is 5.
    ///
    /// Example 2:
    /// Input: A = [4,7,9,10], K = 3
    /// Output: 8
    /// Explanation: 
    /// The missing numbers are [5,6,8,...], hence the third missing number is 8.
    ///
    /// Example 3:
    /// Input: A = [1,2,4], K = 3
    /// Output: 6
    /// Explanation: 
    /// The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 50000
    /// 2. 1 <= A[i] <= 1e7
    /// 3. 1 <= K <= 1e8
    /// </summary>
    int missingElement(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #33. Search in Rotated Sorted Array
    ///  
    /// Suppose an array sorted in ascending order is rotated at some pivot 
    /// unknown to you beforehand.
    ///
    /// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
    ///
    /// You are given a target value to search. If found in the array return 
    /// its index, otherwise return -1.
    ///
    /// You may assume no duplicate exists in the array.
    ///
    /// Your algorithm's runtime complexity must be in the order of O(log n).
    ///
    /// Example 1:
    ///
    /// Input: nums = [4,5,6,7,0,1,2], target = 0
    /// Output: 4
    ///
    /// Example 2:
    ///
    /// Input: nums = [4,5,6,7,0,1,2], target = 3
    /// Output: -1
    /// </summary>
    int search(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #34. Find First and Last Position of Element in Sorted Array
    ///  
    /// Given an array of integers nums sorted in ascending order, find the 
    /// starting and ending position of a given target value.
    /// Your algorithm's runtime complexity must be in the order of O(log n).
    /// If the target is not found in the array, return [-1, -1].
    /// Example 1:
    /// Input: nums = [5,7,7,8,8,10], target = 8
    /// Output: [3,4]
    ///
    /// Example 2:
    /// Input: nums = [5,7,7,8,8,10], target = 6
    /// Output: [-1,-1]
    /// </summary>
    vector<int> searchRange(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #81. Search in Rotated Sorted Array II
    ///  
    /// Suppose an array sorted in ascending order is rotated at some pivot 
    /// unknown to you beforehand.
    ///
    /// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
    ///
    /// You are given a target value to search. If found in the array return true,
    /// otherwise return false.
    ///
    /// Example 1:
    ///
    /// Input: nums = [2,5,6,0,0,1,2], target = 0
    /// Output: true
    ///
    /// Example 2:
    /// 
    /// Input: nums = [2,5,6,0,0,1,2], target = 3
    /// Output: false
    /// Follow up:
    ///
    /// This is a follow up problem to Search in Rotated Sorted Array, where nums 
    /// may contain duplicates.
    /// Would this affect the run-time complexity? How and why?
    /// </summary>
    bool searchII(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #153. Find Minimum in Rotated Sorted Array
    ///  
    /// Suppose an array sorted in ascending order is rotated at some pivot 
    /// unknown to you beforehand.
    ///
    /// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
    ///
    /// Find the minimum element.
    ///
    /// You may assume no duplicate exists in the array.
    ///
    /// Example 1:
    ///
    /// Input: [3,4,5,1,2] 
    /// Output: 1
    ///
    /// Example 2:
    ///
    /// Input: [4,5,6,7,0,1,2]
    /// Output: 0
    /// </summary>
    int findMin(vector<int>& nums);

    /// <summary>
    /// Leet code #154. Find Minimum in Rotated Sorted Array II
    ///  
    /// Suppose an array sorted in ascending order is rotated at some pivot 
    /// unknown to you beforehand.
    ///
    /// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
    ///
    /// Find the minimum element.
    ///
    /// The array may contain duplicates.
    /// 
    /// Example 1:
    ///
    /// Input: [1,3,5]
    /// Output: 1
    ///
    /// Example 2:
    ///
    /// Input: [2,2,2,0,1]
    /// Output: 0
    /// Note:
    /// 
    /// This is a follow up problem to Find Minimum in Rotated Sorted Array.
    /// Would allow duplicates affect the run-time complexity? How and why?
    /// </summary>
    int findMinII(vector<int>& nums);

    /// <summary>
    /// Leet code #162. Find Peak Element
    ///  
    /// A peak element is an element that is greater than its neighbors.
    ///
    /// Given an input array nums, where nums[i] ?ù nums[i+1], find a peak element 
    /// and return its index.
    ///
    /// The array may contain multiple peaks, in that case return the index to 
    /// any one of the peaks is fine.
    ///
    /// You may imagine that nums[-1] = nums[n] = INT_MIN.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,2,3,1]
    /// Output: 2
    /// Explanation: 3 is a peak element and your function should return the 
    /// index number 2.
    ///
    /// Example 2:
    ///
    /// Input: nums = [1,2,1,3,5,6,4]
    /// Output: 1 or 5 
    /// Explanation: Your function can return either index number 1 where the 
    /// peak element is 2, or index number 5 where the peak element is 6.
    ///
    /// Note:
    /// Your solution should be in logarithmic complexity.
    /// </summary>
    int findPeakElement(vector<int>& nums);

    /// <summary>
    /// Leet code #1231. Divide Chocolate
    /// 
    /// You have one chocolate bar that consists of some chunks. Each chunk  
    /// has its own sweetness given by the array sweetness.
    ///
    /// You want to share the chocolate with your K friends so you start 
    /// cutting the chocolate bar into K+1 pieces using K cuts, each piece 
    /// consists of some consecutive chunks.
    /// Being generous, you will eat the piece with the minimum total 
    /// sweetness and give the other pieces to your friends.
    ///
    /// Find the maximum total sweetness of the piece you can get by cutting 
    /// the chocolate bar optimally.
    /// 
    /// Example 1:
    /// Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
    /// Output: 6
    /// Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], 
    /// [7], [8], [9]
    ///
    /// Example 2:
    /// Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
    /// Output: 1
    /// Explanation: There is only one way to cut the bar into 9 pieces.
    ///
    /// Example 3:
    ///
    /// Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
    /// Output: 5
    /// Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
    ///
    ///
    /// Constraints:
    /// 1. 0 <= K < sweetness.length <= 10^4
    /// 2. 1 <= sweetness[i] <= 10^5
    /// </summary>
    int maximizeSweetness(vector<int>& sweetness, int K);

    /// <summary>
    /// Leet code #240. Search a 2D Matrix II 
    ///
    /// Write an efficient algorithm that searches for a value in an m x n matrix. 
    /// This matrix has the following properties: 
    /// Integers in each row are sorted in ascending from left to right.
    /// Integers in each column are sorted in ascending from top to bottom.
    ///
    /// For example,
    /// Consider the following matrix: 
    /// [
    ///   [1,   4,  7, 11, 15],
    ///   [2,   5,  8, 12, 19],
    ///   [3,   6,  9, 16, 22],
    ///   [10, 13, 14, 17, 24],
    ///   [18, 21, 23, 26, 30]
    /// ]
    ///
    /// Given target = 5, return true.
    /// Given target = 20, return false.
    /// </summary>
    bool searchMatrixII(vector<vector<int>>& matrix, int target);

    /// <summary>
    /// LeetCode #4. Median of Two Sorted Arrays
    /// </summary>
    int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, size_t s1, size_t s2, size_t k);

    /// <summary>
    /// LeetCode #4. Median of Two Sorted Arrays
    ///  
    /// There are two sorted arrays nums1 and nums2 of size m and n respectively.
    ///
    /// Find the median of the two sorted arrays. The overall run time complexity 
    /// should be O(log (m+n)).
    ///
    /// You may assume nums1 and nums2 cannot be both empty.
    ///
    /// Example 1:
    ///
    /// nums1 = [1, 3]
    /// nums2 = [2]
    ///
    /// The median is 2.0
    ///
    /// Example 2:
    ///
    /// nums1 = [1, 2]
    /// nums2 = [3, 4]
    ///
    /// The median is (2 + 3)/2 = 2.5
    /// </summary>
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet code #1011. Capacity To Ship Packages Within D Days
    /// 
    /// A conveyor belt has packages that must be shipped from one port to another 
    /// within D days.
    ///
    /// The i-th package on the conveyor belt has a weight of weights[i].  Each 
    /// day, we load the ship with packages on the conveyor belt (in the order 
    /// given by weights). We may not load more weight than the maximum weight 
    /// capacity of the ship.
    ///
    /// Return the least weight capacity of the ship that will result in all the 
    /// packages on the conveyor belt being shipped within D days.
    ///
    /// Example 1:
    ///
    /// Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
    /// Output: 15
    /// Explanation: 
    /// A ship capacity of 15 is the minimum to ship all the packages in 5 days 
    /// like this:
    /// 1st day: 1, 2, 3, 4, 5
    /// 2nd day: 6, 7
    /// 3rd day: 8
    /// 4th day: 9
    /// 5th day: 10
    ///
    /// Note that the cargo must be shipped in the order given, so using a ship 
    /// of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), 
    /// (1, 6, 7), (8), (9), (10) is not allowed. 
    ///
    /// Example 2:
    ///
    /// Input: weights = [3,2,2,4,1,4], D = 3
    /// Output: 6
    /// Explanation: 
    /// A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
    /// 1st day: 3, 2
    /// 2nd day: 2, 4
    /// 3rd day: 1, 4
    ///
    /// Example 3:
    ///
    /// Input: weights = [1,2,3,1,1], D = 4
    /// Output: 3
    /// Explanation: 
    /// 1st day: 1
    /// 2nd day: 2
    /// 3rd day: 3
    /// 4th day: 1, 1
    ///
    /// Note:
    ///
    /// 1. 1 <= D <= weights.length <= 50000
    /// 2. 1 <= weights[i] <= 500
    /// </summary>
    int shipWithinDays(vector<int>& weights, int days);

    /// <summary>
    /// LeetCode #875. Koko Eating Bananas
    /// 
    /// Koko loves to eat bananas.  There are N piles of bananas, the i-th 
    /// pile has piles[i] bananas.  The guards have gone and will come back 
    /// in H hours.
    /// 
    /// Koko can decide her bananas-per-hour eating speed of K.  Each hour, 
    /// she chooses some pile of bananas, and eats K bananas from that pile. 
    /// If the pile has less than K bananas, she eats all of them instead, 
    /// and won't eat any more bananas during this hour.
    ///
    /// Koko likes to eat slowly, but still wants to finish eating all the 
    /// bananas before the guards come back.
    ///
    /// Return the minimum integer K such that she can eat all the bananas 
    /// within H hours.
    ///
    /// Example 1:
    /// Input: piles = [3,6,7,11], H = 8
    /// Output: 4
    ///
    /// Example 2:
    /// Input: piles = [30,11,23,4,20], H = 5
    /// Output: 30
    ///
    /// Example 3:
    /// Input: piles = [30,11,23,4,20], H = 6
    /// Output: 23
    ///  
    /// Note:
    /// 1. 1 <= piles.length <= 10^4
    /// 2. piles.length <= H <= 10^9
    /// 3. 1 <= piles[i] <= 10^9
    /// </summary>
    int minEatingSpeed(vector<int>& piles, int h);

    /// <summary>
    /// Leet Code 719. Find K-th Smallest Pair Distance
    ///  
    /// Hard
    ///
    /// The distance of a pair of integers a and b is defined as the absolute 
    /// difference between a and b.
    ///
    /// Given an integer array nums and an integer k, return the kth smallest 
    /// distance among all the pairs nums[i] and nums[j] where 
    /// 0 <= i < j < nums.length.
    ///
    /// Example 1:
    /// Input: nums = [1,3,1], k = 1
    /// Output: 0
    /// Explanation: Here are all the pairs:
    /// (1,3) -> 2
    /// (1,1) -> 0
    /// (3,1) -> 2
    /// Then the 1st smallest distance pair is (1,1), and its distance is 0.
    ///
    /// Example 2:
    /// Input: nums = [1,1,1], k = 2
    /// Output: 0
    ///
    /// Example 3:
    /// Input: nums = [1,6,1], k = 3
    /// Output: 5
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 2 <= n <= 10^4
    /// 3. 0 <= nums[i] <= 10^6
    /// 4. 1 <= k <= n * (n - 1) / 2
    /// </summary>
    int smallestDistancePair(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #786. K-th Smallest Prime Fraction    
    ///
    /// A sorted list A contains 1, plus some number of primes.  Then, for 
    /// every p < q in the list, we consider the fraction p/q.
    ///
    /// What is the K-th smallest fraction considered?  Return your answer as 
    /// an array of ints, where answer[0] = p and answer[1] = q.
    ///
    /// Examples:
    /// Input: A = [1, 2, 3, 5], K = 3
    /// Output: [2, 5]
    /// Explanation:
    /// The fractions to be considered in sorted order are:
    /// 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
    /// The third fraction is 2/5.
    ///
    /// Input: A = [1, 7], K = 1
    /// Output: [1, 7]
    /// Note:
    /// 1. A will have length between 2 and 2000.
    /// 2. Each A[i] will be between 1 and 30000.
    /// 3. K will be between 1 and A.length * (A.length + 1) / 2.
    /// </summary>
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K);

    /// <summary>
    /// Leet Code 410. Split Array Largest Sum
    ///  
    /// Hard
    ///
    /// Given an integer array nums and an integer k, split nums into k 
    /// non-empty subarrays such that the largest sum of any subarray is 
    /// minimized.
    ///
    /// Return the minimized largest sum of the split.
    /// A subarray is a contiguous part of the array.
    ///
    /// Example 1:
    /// Input: nums = [7,2,5,10,8], k = 2
    /// Output: 18
    /// Explanation: There are four ways to split nums into two subarrays.
    /// The best way is to split it into [7,2,5] and [10,8], where the 
    /// largest sum among the two subarrays is only 18.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,5], k = 2
    /// Output: 9
    /// Explanation: There are four ways to split nums into two subarrays.
    /// The best way is to split it into [1,2,3] and [4,5], where the largest 
    /// sum among the two subarrays is only 9.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 0 <= nums[i] <= 10^6 
    /// 3. 1 <= k <= min(50, nums.length)
    /// </summary>
    int splitArray(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #378. Kth Smallest Element in a Sorted Matrix   
    /// </summary>
    int countNoGreaterValue(vector<vector<int>>& matrix, int value, int k);

    /// <summary>
    /// Leet code #378. Kth Smallest Element in a Sorted Matrix   
    /// 
    /// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
    /// Note that it is the kth smallest element in the sorted order, not the kth distinct element. 
    /// Example: 
    /// matrix = 
    /// [
    ///   [ 1,  5,  9],
    ///   [10, 11, 13],
    ///   [12, 13, 15]
    /// ],
    /// k = 8,
    /// return 13.
    /// </summary>
    int kthSmallest(vector<vector<int>>& matrix, int k);

    /// <summary>
    /// Leet code #878. Nth Magical Number
    /// 
    /// A positive integer is magical if it is divisible by either A or B.
    ///
    /// Return the N-th magical number.  Since the answer may be very large, 
    /// return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: N = 1, A = 2, B = 3
    /// Output: 2
    ///
    /// Example 2:
    /// Input: N = 4, A = 2, B = 3
    /// Output: 6
    ///
    /// Example 3:
    /// Input: N = 5, A = 2, B = 4
    /// Output: 10
    ///
    /// Example 4:
    /// Input: N = 3, A = 6, B = 4
    /// Output: 8
    ///
    /// Note:
    /// 1. 1 <= N <= 10^9
    /// 2. 2 <= A <= 40000
    /// 3. 2 <= B <= 40000
    /// </summary>
    int nthMagicalNumber(int n, int a, int b);

    /// <summary>
    /// Leet code #1283. Find the Smallest Divisor Given a Threshold
    ///
    /// Medium
    ///
    /// Given an array of integers nums and an integer threshold, we will 
    /// choose a positive integer divisor and divide all the array by it 
    /// and sum the result of the division. Find the smallest divisor such 
    /// that the result mentioned above is less than or equal to threshold.
    ///
    /// Each result of division is rounded to the nearest integer greater 
    /// than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
    ///
    /// It is guaranteed that there will be an answer.
    ///
    /// Example 1:
    /// Input: nums = [1,2,5,9], threshold = 6
    /// Output: 5
    ///
    /// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
    /// If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the 
    /// divisor is 5 the sum will be 5 (1+1+1+2). 
    ///
    /// Example 2:
    /// Input: nums = [2,3,5,7,11], threshold = 11
    /// Output: 3
    ///
    /// Example 3:
    /// Input: nums = [19], threshold = 5
    /// Output: 4
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 5 * 10^4
    /// 2. 1 <= nums[i] <= 10^6
    /// 3. nums.length <= threshold <= 10^6	
    /// </summary>
    int smallestDivisor(vector<int>& nums, int threshold);

    /// <summary>
    /// Leetcode #1300. Sum of Mutated Array Closest to Target
    ///
    /// Medium
    ///
    /// Given an integer array arr and a target value target, return the 
    /// integer value such that when we change all the integers larger than 
    /// value in the given array to be equal to value, the sum of the array 
    /// gets as close as possible (in absolute difference) to target.
    ///
    /// In case of a tie, return the minimum such integer.
    ///
    /// Notice that the answer is not neccesarilly a number from arr.
    ///
    /// Example 1:
    ///
    /// Input: arr = [4,9,3], target = 10
    /// Output: 3
    /// Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 
    /// and that's the optimal answer.
    /// Example 2:
    ///
    /// Input: arr = [2,3,5], target = 10
    /// Output: 5
    /// Example 3:
    ///
    /// Input: arr = [60864,25176,27249,21296,20204], target = 56803
    /// Output: 11361
    ///  
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^4
    /// 2. 1 <= arr[i], target <= 10^5
    /// </summary>
    int findBestValue(vector<int>& arr, int target);

    /// <summary>
    /// Leet code #1482. Minimum Number of Days to Make m Bouquets
    ///
    /// Medium
    ///
    /// Given an integer array bloomDay, an integer m and an integer k.
    /// We need to make m bouquets. To make a bouquet, you need to use 
    /// k adjacent flowers from the garden.
    /// 
    /// The garden consists of n flowers, the ith flower will bloom in the 
    /// bloomDay[i] and then can be used in exactly one bouquet.
    ///
    /// Return the minimum number of days you need to wait to be able to 
    /// make m bouquets from the garden. If it is impossible to make m 
    /// bouquets return -1.
    /// 
    /// Example 1:
    /// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
    /// Output: 3
    /// Explanation: Let's see what happened in the first three days. 
    /// x means flower bloomed and _ means flower didn't bloom in the garden.
    /// We need 3 bouquets each should contain 1 flower.
    /// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
    /// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
    /// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer 
    /// is 3.
    ///
    /// Example 2:
    /// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
    /// Output: -1
    /// Explanation: We need 3 bouquets each has 2 flowers, that means we 
    /// need 6 flowers. We only have 5 flowers so it is impossible to get 
    /// the needed bouquets and we return -1.
    ///
    /// Example 3:
    /// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
    /// Output: 12
    /// Explanation: We need 2 bouquets each should have 3 flowers.
    /// Here's the garden after the 7 and 12 days:
    /// After day 7: [x, x, x, x, _, x, x]
    /// We can make one bouquet of the first three flowers that bloomed. 
    /// We cannot make another bouquet from the last three flowers that 
    /// bloomed because they are not adjacent.
    /// After day 12: [x, x, x, x, x, x, x]
    /// It is obvious that we can make two bouquets in different ways.
    ///
    /// Example 4:
    /// Input: bloomDay = [1000000000,1000000000], m = 1, k = 1
    /// Output: 1000000000
    /// Explanation: You need to wait 1000000000 days to have a flower 
    /// ready for a bouquet.
    ///
    /// Example 5:
    /// 
    /// Input: bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
    /// Output: 9
    ///
    /// Constraints:
    /// 1. bloomDay.length == n
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= bloomDay[i] <= 10^9
    /// 4. 1 <= m <= 10^6
    /// 5. 1 <= k <= n
    /// </summary> 
    int minDays(vector<int>& bloomDay, int m, int k);

    /// <summary>
    /// Leet code #1552. Magnetic Force Between Two Balls
    /// 
    /// Medium
    ///
    /// In universe Earth C-137, Rick discovered a special form of magnetic 
    /// force between two balls if they are put in his new invented basket. 
    /// Rick has n empty baskets, the ith basket is at position[i], Morty 
    /// has m balls and needs to distribute the balls into the baskets such 
    /// that the minimum magnetic force between any two balls is maximum.
    ///
    /// Rick stated that magnetic force between two different balls at 
    /// positions x and y is |x - y|.
    ///
    /// Given the integer array position and the integer m. Return the 
    /// required force.
    /// 
    /// Example 1:
    /// Input: position = [1,2,3,4,7], m = 3
    /// Output: 3
    /// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will 
    /// make the magnetic force between ball pairs [3, 3, 6]. The minimum 
    /// magnetic force is 3. We cannot achieve a larger minimum magnetic 
    /// force than 3.
    ///
    /// Example 2:
    /// Input: position = [5,4,3,2,1,1000000000], m = 2
    /// Output: 999999999
    /// Explanation: We can use baskets 1 and 1000000000.
    /// 
    /// Constraints:
    /// 1. n == position.length
    /// 2. 2 <= n <= 10^5
    /// 3. 1 <= position[i] <= 10^9
    /// 4. All integers in position are distinct.
    /// 5. 2 <= m <= position.length
    /// </summary>
    int maxDistance(vector<int>& position, int m);

    /// <summary>
    /// Leet code 1760. Minimum Limit of Balls in a Bag
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums where the ith bag contains 
    /// nums[i] balls. You are also given an integer maxOperations.
    ///
    /// You can perform the following operation at most maxOperations times:
    ///
    /// Take any bag of balls and divide it into two new bags with a positive 
    /// number of balls.
    /// For example, a bag of 5 balls can become two new bags of 1 and 4
    /// balls, or two new bags of 2 and 3 balls.
    /// Your penalty is the maximum number of balls in a bag. You want to 
    /// minimize your penalty after the operations.
    ///
    /// Return the minimum possible penalty after performing the operations.
    /// 
    /// Example 1:
    /// Input: nums = [9], maxOperations = 2
    /// Output: 3
    /// Explanation: 
    /// - Divide the bag with 9 balls into two bags of 
    ///   sizes 6 and 3. [9] -> [6,3].
    /// - Divide the bag with 6 balls into two bags of sizes 3 and 3. 
    ///   [6,3] -> [3,3,3].
    /// The bag with the most number of balls has 3 balls, so your 
    /// penalty is 3 and you should return 3.
    ///
    /// Example 2:
    /// Input: nums = [2,4,8,2], maxOperations = 4
    /// Output: 2
    /// Explanation:
    /// - Divide the bag with 8 balls into two bags of sizes 4 and 4. 
    /// [2,4,8,2] -> [2,4,4,4,2].
    /// - Divide the bag with 4 balls into two bags of sizes 2 and 2. 
    /// [2,4,4,4,2] -> [2,2,2,4,4,2].
    /// - Divide the bag with 4 balls into two bags of sizes 2 and 2. 
    /// [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
    /// - Divide the bag with 4 balls into two bags of sizes 2 and 2. 
    /// [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
    /// The bag with the most number of balls has 2 balls, so your penalty 
    /// is 2 an you should return 2.
    ///
    /// Example 3:
    /// Input: nums = [7,17], maxOperations = 2
    /// Output: 7
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= maxOperations, nums[i] <= 10^9
    /// </summary>
    int minimumSize(vector<int>& nums, int maxOperations);

    /// <summary>
    /// Leet code 1802. Maximum Value at a Given Index in a Bounded Array
    /// 
    /// Medium
    /// 
    /// You are given three positive integers n, index and maxSum. You want 
    /// to construct an array nums (0-indexed) that satisfies the following 
    /// conditions:
    ///
    /// nums.length == n
    /// nums[i] is a positive integer where 0 <= i < n.
    /// abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
    /// The sum of all the elements of nums does not exceed maxSum.
    /// nums[index] is maximized.
    /// Return nums[index] of the constructed array.
    /// Note that abs(x) equals x if x >= 0, and -x otherwise.
    ///  
    /// Example 1:
    /// Input: n = 4, index = 2,  maxSum = 6
    /// Output: 2
    /// Explanation: The arrays [1,1,2,1] and [1,2,2,1] satisfy all the conditions. There 
    /// are no other valid arrays with a larger value at the given index.
    ///
    /// Example 2:
    /// Input: n = 6, index = 1,  maxSum = 10
    /// Output: 3
    ///
    /// Constraints:
    /// 1. 1 <= n <= maxSum <= 10^9
    /// 2. 0 <= index < n
    /// </summary>
    int maxValue(int n, int index, int maxSum);

    /// <summary>
    /// Leet code 1870. Minimum Speed to Arrive on Time
    ///                  
    /// Medium
    /// 
    /// You are given a floating-point number hour, representing the amount 
    /// of time you have to reach the office. To commute to the office, you 
    /// must take n trains in sequential order. You are also given an integer 
    /// array dist of length n, where dist[i] describes the distance 
    /// (in kilometers) of the ith train ride.
    ///
    /// Each train can only depart at an integer hour, so you may need to 
    /// wait in between each train ride.
    ///
    /// For example, if the 1st train ride takes 1.5 hours, you must wait for 
    /// an additional 0.5 hours before you can depart on the 2nd train ride 
    /// at the 2 hour mark.
    /// Return the minimum positive integer speed (in kilometers per hour) 
    /// that all the trains must travel at for you to reach the office on 
    /// time, or -1 if it is impossible to be on time.
    /// 
    /// Tests are generated such that the answer will not exceed 10^7 and 
    /// hour will have at most two digits after the decimal point.
    /// 
    /// Example 1:
    ///
    /// Input: dist = [1,3,2], hour = 6
    /// Output: 1
    /// Explanation: At speed 1:
    /// - The first train ride takes 1/1 = 1 hour.
    /// - Since we are already at an integer hour, we depart immediately at 
    ///   the 1 hour mark. The second train takes 3/1 = 3 hours.
    /// - Since we are already at an integer hour, we depart immediately at 
    ///   the 4 hour mark. The third train takes 2/1 = 2 hours.
    /// - You will arrive at exactly the 6 hour mark.
    ///
    /// Example 2:
    /// Input: dist = [1,3,2], hour = 2.7
    /// Output: 3
    /// Explanation: At speed 3:
    /// - The first train ride takes 1/3 = 0.33333 hours.
    /// - Since we are not at an integer hour, we wait until the 1 hour mark 
    ///   to depart. The second train ride takes 3/3 = 1 hour.
    /// - Since we are already at an integer hour, we depart immediately at 
    ///   the 2 hour mark. The third train takes 2/3 = 0.66667 hours.
    /// - You will arrive at the 2.66667 hour mark.
    ///
    /// Example 3:
    /// Input: dist = [1,3,2], hour = 1.9
    /// Output: -1
    /// Explanation: It is impossible because the earliest the third train 
    /// can depart is at the 2 hour mark.
    ///
    /// Constraints:
    /// 1. n == dist.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= dist[i] <= 10^5
    /// 4. 1 <= hour <= 10^9
    /// 5. There will be at most two digits after the decimal point in hour.
    /// </summary>
    int minSpeedOnTime(vector<int>& dist, double hour);

    /// <summary>
    /// Leet code 1923. Longest Common Subpath
    ///                                  
    /// Hard
    /// 
    /// There is a country of n cities numbered from 0 to n - 1. In this 
    /// country, there is a road connecting every pair of cities.
    ///
    /// There are m friends numbered from 0 to m - 1 who are traveling through
    /// the country. Each one of them will take a path consisting of some 
    /// cities. Each path is represented by an integer array that contains the 
    /// visited cities in order. The path may contain a city more than once, 
    /// but the same city will not be listed consecutively.
    ///
    /// Given an integer n and a 2D integer array paths where paths[i] is an 
    /// integer array representing the path of the ith friend, return the 
    /// length of the longest common subpath that is shared by every friend's 
    /// path, or 0 if there is no common subpath at all.
    ///
    /// A subpath of a path is a contiguous sequence of cities within that 
    /// path.
    /// Example 1:
    ///
    /// Input: n = 5, paths = [[0,1,2,3,4],
    ///                        [2,3,4],
    ///                        [4,0,1,2,3]]
    /// Output: 2
    /// Explanation: The longest common subpath is [2,3].
    ///
    /// Example 2:
    /// Input: n = 3, paths = [[0],[1],[2]]
    /// Output: 0
    /// Explanation: There is no common subpath shared by the three paths.
    ///
    /// Example 3:
    ///
    /// Input: n = 5, paths = [[0,1,2,3,4],
    ///                        [4,3,2,1,0]]
    /// Output: 1
    /// Explanation: The possible longest common subpaths are [0], 
    /// [1], [2], [3], and [4]. All have a length of 1.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. m == paths.length
    /// 3. 2 <= m <= 10^5
    /// 4. sum(paths[i].length) <= 105
    /// 5. 0 <= paths[i][j] < n
    /// 6. The same city is not listed multiple times consecutively in 
    ///    paths[i].
    /// </summary>
    int longestCommonSubpath(int n, vector<vector<int>>& paths);

    /// <summary>
    /// Leet code 1898. Maximum Number of Removable Characters
    ///                                  
    /// Medium
    /// 
    /// You are given two strings s and p where p is a subsequence of s. 
    /// You are also given a distinct 0-indexed integer array removable 
    /// containing a subset of indices of s (s is also 0-indexed).
    ///
    /// You want to choose an integer k (0 <= k <= removable.length) such 
    /// that, after removing k characters from s using the first k indices 
    /// in removable, p is still a subsequence of s. More formally, you will 
    /// mark the character at s[removable[i]] for each 0 <= i < k, then 
    /// remove all marked characters and check if p is still a subsequence.
    ///
    /// Return the maximum k you can choose such that p is still a subsequence 
    /// of s after the removals.
    ///
    /// A subsequence of a string is a new string generated from the original 
    /// string with some characters (can be none) deleted without changing the 
    /// relative order of the remaining characters.
    /// 
    /// Example 1:
    /// Input: s = "abcacb", p = "ab", removable = [3,1,0]
    /// Output: 2
    /// Explanation: After removing the characters at indices 3 and 1, 
    /// "abcacb" becomes "accb".
    /// "ab" is a subsequence of "accb".
    /// If we remove the characters at indices 3, 1, and 0, "abcacb" becomes 
    /// "ccb", and "ab" is no longer a subsequence.
    /// Hence, the maximum k is 2.
    ///
    /// Example 2:
    /// Input: s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
    /// Output: 1
    /// Explanation: After removing the character at index 3, "abcbddddd" 
    /// becomes "abcddddd".
    /// "abcd" is a subsequence of "abcddddd".
    ///
    /// Example 3:
    /// Input: s = "abcab", p = "abc", removable = [0,1,2,3,4]
    /// Output: 0
    /// Explanation: If you remove the first index in the array removable, 
    /// "abc" is no longer a subsequence.
    ///
    /// Constraints:
    /// 1. 1 <= p.length <= s.length <= 10^5
    /// 2. 0 <= removable.length < s.length
    /// 3. 0 <= removable[i] < s.length
    /// 4. p is a subsequence of s.
    /// 5. s and p both consist of lowercase English letters.
    /// 6. The elements in removable are distinct.
    /// </summary>
    int maximumRemovals(string s, string p, vector<int>& removable);

    /// <summary>
    /// Leet Code 2040. Kth Smallest Product of Two Sorted Arrays
    /// </summary>
    long long kthSmallestProductCount(vector<int>& nums1, vector<int>& nums2, long long value);

    /// <summary>
    /// Leet Code 2040. Kth Smallest Product of Two Sorted Arrays
    ///                                                                 
    /// Hard
    /// 
    /// Given two sorted 0-indexed integer arrays nums1 and nums2 as well as 
    /// an integer k, return the kth (1-based) smallest product of nums1[i] 
    /// * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
    ///
    /// Example 1:
    /// Input: nums1 = [2,5], nums2 = [3,4], k = 2
    /// Output: 8
    /// Explanation: The 2 smallest products are:
    /// - nums1[0] * nums2[0] = 2 * 3 = 6
    /// - nums1[0] * nums2[1] = 2 * 4 = 8
    /// The 2nd smallest product is 8.
    ///
    /// Example 2:
    /// Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
    /// Output: 0
    /// Explanation: The 6 smallest products are:
    /// - nums1[0] * nums2[1] = (-4) * 4 = -16
    /// - nums1[0] * nums2[0] = (-4) * 2 = -8 
    /// - nums1[1] * nums2[1] = (-2) * 4 = -8
    /// - nums1[1] * nums2[0] = (-2) * 2 = -4
    /// - nums1[2] * nums2[0] = 0 * 2 = 0
    /// - nums1[2] * nums2[1] = 0 * 4 = 0
    /// The 6th smallest product is 0.
    ///
    /// Example 3:
    /// Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
    /// Output: -6
    /// Explanation: The 3 smallest products are:
    /// - nums1[0] * nums2[4] = (-2) * 5 = -10
    /// - nums1[0] * nums2[3] = (-2) * 4 = -8
    /// - nums1[4] * nums2[0] = 2 * (-3) = -6
    /// The 3rd smallest product is -6.
    /// 
    /// Constraints:
    /// 1. 1 <= nums1.length, nums2.length <= 5 * 10^4
    /// 2. -10^5 <= nums1[i], nums2[j] <= 10^5
    /// 3. 1 <= k <= nums1.length * nums2.length
    /// 4. nums1 and nums2 are sorted.
    /// </summary>
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k);

    /// <summary>
    /// Leet Code 2089. Find Target Indices After Sorting Array
    ///                                                                 
    /// Easy
    /// 
    /// You are given a 0-indexed integer array nums and a target element 
    /// target.
    ///
    /// A target index is an index i such that nums[i] == target.
    ///
    /// Return a list of the target indices of nums after sorting nums in 
    /// non-decreasing order. If there are no target indices, return an 
    /// empty list. The returned list must be sorted in increasing order.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,5,2,3], target = 2
    /// Output: [1,2]
    /// Explanation: After sorting, nums is [1,2,2,3,5].
    /// The indices where nums[i] == 2 are 1 and 2.
    ///
    /// Example 2:
    /// Input: nums = [1,2,5,2,3], target = 3
    /// Output: [3]
    /// Explanation: After sorting, nums is [1,2,2,3,5].
    /// The index where nums[i] == 3 is 3.
    ///
    /// Example 3:
    /// Input: nums = [1,2,5,2,3], target = 5
    /// Output: [4]
    /// Explanation: After sorting, nums is [1,2,2,3,5].
    /// The index where nums[i] == 5 is 4.
    ///
    /// Example 4:
    /// Input: nums = [1,2,5,2,3], target = 4
    /// Output: []
    /// Explanation: There are no elements in nums with value 4.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i], target <= 100
    /// </summary>
    vector<int> targetIndices(vector<int>& nums, int target);

    /// <summary>
    /// Leet Code 1891. Cutting Ribbons
    ///                                                                 
    /// Medium
    ///
    /// You are given an integer array ribbons, where ribbons[i] represents 
    /// the length of the ith ribbon, and an integer k. You may cut any of 
    /// the ribbons into any number of segments of positive integer lengths, 
    /// or perform no cuts at all.
    ///
    /// For example, if you have a ribbon of length 4, you can:
    /// Keep the ribbon of length 4,
    /// Cut it into one ribbon of length 3 and one ribbon of length 1,
    /// Cut it into two ribbons of length 2,
    /// Cut it into one ribbon of length 2 and two ribbons of length 1, or
    /// Cut it into four ribbons of length 1.
    /// Your goal is to obtain k ribbons of all the same positive integer 
    /// length. You are allowed to throw away any excess ribbon as a result 
    /// of cutting.
    ///
    /// Return the maximum possible positive integer length that you can 
    /// obtain k ribbons of, or 0 if you cannot obtain k ribbons of the 
    /// same length.
    /// 
    /// Example 1:
    /// Input: ribbons = [9,7,5], k = 3
    /// Output: 5
    /// Explanation:
    /// - Cut the first ribbon to two ribbons, one of length 5 and one of 
    ///   length 4.
    /// - Cut the second ribbon to two ribbons, one of length 5 and one of 
    ///   length 2.
    /// - Keep the third ribbon as it is.
    /// Now you have 3 ribbons of length 5.
    ///
    /// Example 2:
    ///
    /// Input: ribbons = [7,5,9], k = 4
    /// Output: 4
    /// Explanation:
    /// - Cut the first ribbon to two ribbons, one of length 4 and one of 
    ///   length 3.
    /// - Cut the second ribbon to two ribbons, one of length 4 and one of 
    ///   length 1.
    /// - Cut the third ribbon to three ribbons, two of length 4 and one of 
    ///   length 1.
    /// Now you have 4 ribbons of length 4.
    ///
    /// Example 3:
    /// Input: ribbons = [5,7,9], k = 22
    /// Output: 0
    /// Explanation: You cannot obtain k ribbons of the same positive integer 
    /// length.
    ///
    /// Constraints:
    /// 1. 1 <= ribbons.length <= 10^5
    /// 2. 1 <= ribbons[i] <= 10^5
    /// 3. 1 <= k <= 10^9	
    /// </summary>
    int maxLength(vector<int>& ribbons, int k);

    /// <summary>
    /// Leet Code 1918. Kth Smallest Subarray Sum
    ///                                                                 
    /// Medium
    ///
    /// Given an integer array nums of length n and an integer k, return the 
    /// kth smallest subarray sum.
    ///
    /// A subarray is defined as a non-empty contiguous sequence of elements 
    /// in an array. A subarray sum is the sum of all elements in the subarray.
    /// 
    /// Example 1:
    /// Input: nums = [2,1,3], k = 4
    /// Output: 3
    /// Explanation: The subarrays of [2,1,3] are:
    /// - [2] with sum 2
    /// - [1] with sum 1
    /// - [3] with sum 3
    /// - [2,1] with sum 3
    /// - [1,3] with sum 4
    /// - [2,1,3] with sum 6 
    /// Ordering the sums from smallest to largest gives 1, 2, 3, 3, 4, 6. 
    /// The 4th smallest is 3.
    ///
    /// Example 2:
    /// Input: nums = [3,3,5,5], k = 7
    /// Output: 10
    /// Explanation: The subarrays of [3,3,5,5] are:
    /// - [3] with sum 3
    /// - [3] with sum 3
    /// - [5] with sum 5
    /// - [5] with sum 5
    /// - [3,3] with sum 6
    /// - [3,5] with sum 8
    /// - [5,5] with sum 10
    /// - [3,3,5], with sum 11
    /// - [3,5,5] with sum 13
    /// - [3,3,5,5] with sum 16
    /// Ordering the sums from smallest to largest gives 3, 3, 5, 5, 6, 8, 
    /// 10, 11, 13, 16. The 7th smallest is 10.
    ///
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 2 * 10^4
    /// 3. 1 <= nums[i] <= 5 * 10^4
    /// 4. 1 <= k <= n * (n + 1) / 2
    /// </summary>
    int kthSmallestSubarraySum(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2064. Minimized Maximum of Products Distributed to Any Store
    ///                                                                 
    /// Medium
    ///
    /// You are given an integer n indicating there are n specialty retail 
    /// stores. There are m product types of varying amounts, which are 
    /// given as a 0-indexed integer array quantities, where quantities[i] 
    /// represents the number of products of the ith product type.
    ///
    /// You need to distribute all products to the retail stores following 
    /// these rules:
    ///
    /// A store can only be given at most one product type but can be given 
    /// any amount of it.
    /// After distribution, each store will have been given some number of 
    /// products (possibly 0). Let x represent the maximum number of products 
    /// given to any store. You want x to be as small as possible, i.e., you 
    /// want to minimize the maximum number of products that are given to any 
    /// store.
    /// Return the minimum possible x.
    /// Example 1:
    /// Input: n = 6, quantities = [11,6]
    /// Output: 3
    /// Explanation: One optimal way is:
    /// - The 11 products of type 0 are distributed to the first four stores 
    ///   in these amounts: 2, 3, 3, 3
    /// - The 6 products of type 1 are distributed to the other two stores in 
    ///   these amounts: 3, 3
    /// The maximum number of products given to any store is max(2, 3, 3, 3, 
    /// 3, 3) = 3. 
    ///
    /// Example 2:
    /// Input: n = 7, quantities = [15,10,10]
    /// Output: 5
    /// Explanation: One optimal way is:
    /// - The 15 products of type 0 are distributed to the first three stores 
    ///   in these amounts: 5, 5, 5
    /// - The 10 products of type 1 are distributed to the next two stores in 
    ///   these amounts: 5, 5
    /// - The 10 products of type 2 are distributed to the last two stores in 
    ///   these amounts: 5, 5
    /// The maximum number of products given to any store is max(5, 5, 5, 5, 
    /// 5, 5, 5) = 5.
    ///
    /// Example 3:
    /// Input: n = 1, quantities = [100000]
    /// Output: 100000
    /// Explanation: The only optimal way is:
    /// - The 100000 products of type 0 are distributed to the only store.
    /// The maximum number of products given to any store is max(100000) = 100000.
    ///
    /// Constraints:
    /// 1. m == quantities.length
    /// 2. 1 <= m <= n <= 10^5
    /// 3. 1 <= quantities[i] <= 10^5
    /// </summary>
    int minimizedMaximum(int n, vector<int>& quantities);

    /// <summary>
    /// Leet Code 2141. Maximum Running Time of N Computers
    ///                                                                 
    /// Hard
    ///
    /// You have n computers. You are given the integer n and a 0-indexed 
    /// integer array batteries where the ith battery can run a computer for 
    /// batteries[i] minutes. You are interested in running all n computers 
    /// simultaneously using the given batteries.
    ///
    /// Initially, you can insert at most one battery into each computer. After 
    /// that and at any integer time moment, you can remove a battery from a 
    /// computer and insert another battery any number of times. The inserted 
    /// battery can be a totally new battery or a battery from another 
    /// computer. You may assume that the removing and inserting processes 
    /// take no time.
    ///
    /// Note that the batteries cannot be recharged.
    /// Return the maximum number of minutes you can run all the n computers 
    /// simultaneously.
    ///
    /// Example 1:
    ///Input: n = 2, batteries = [3,3,3]
    /// Output: 4
    /// Explanation: 
    /// Initially, insert battery 0 into the first computer and battery 1 
    /// into the second computer.
    /// After two minutes, remove battery 1 from the second computer and 
    /// insert battery 2 instead. Note that battery 1 can still run for one 
    /// minute.
    /// At the end of the third minute, battery 0 is drained, and you need 
    /// to remove it from the first computer and insert battery 1 instead.
    /// By the end of the fourth minute, battery 1 is also drained, and the 
    /// first computer is no longer running.
    /// We can run the two computers simultaneously for at most 4 minutes, 
    /// so we return 4.
    ///
    /// Example 2:
    /// Input: n = 2, batteries = [1,1,1,1]
    /// Output: 2
    /// Explanation: 
    /// Initially, insert battery 0 into the first computer and battery 2 
    /// into the second computer. 
    /// After one minute, battery 0 and battery 2 are drained so you need to 
    /// remove them and insert battery 1 into the first computer and battery 
    /// 3 into the second computer. 
    /// After another minute, battery 1 and battery 3 are also drained so the 
    /// first and second computers are no longer running.
    /// We can run the two computers simultaneously for at most 2 minutes, so 
    /// we return 2.
    ///
    /// Constraints:
    /// 1. 1 <= n <= batteries.length <= 10^5
    /// 2. 1 <= batteries[i] <= 10^9
    /// </summary>
    long long maxRunTime(int n, vector<int>& batteries);

    /// <summary>
    /// Leet Code 2137. Pour Water Between Buckets to Make Water Levels Equal
    ///                                                                 
    /// Medium
    ///
    /// You have n buckets each containing some gallons of water in it, 
    /// represented by a 0-indexed integer array buckets, where the ith bucket 
    /// contains buckets[i] gallons of water. You are also given an integer 
    /// loss.
    ///
    /// You want to make the amount of water in each bucket equal. You can 
    /// pour any amount of water from one bucket to another bucket (not 
    /// necessarily an integer). However, every time you pour k gallons of 
    /// water, you spill loss percent of k.
    ///
    /// Return the maximum amount of water in each bucket after making the 
    /// amount of water equal. Answers within 10-5 of the actual answer will 
    /// be accepted.
    /// 
    /// Example 1:
    /// Input: buckets = [1,2,7], loss = 80
    /// Output: 2.00000
    /// Explanation: Pour 5 gallons of water from buckets[2] to buckets[0].
    /// 5 * 80% = 4 gallons are spilled and buckets[0] only receives 5 - 4 = 1 
    /// gallon of water.
    /// All buckets have 2 gallons of water in them so return 2.
    ///
    /// Example 2:
    /// Input: buckets = [2,4,6], loss = 50
    /// Output: 3.50000
    /// Explanation: Pour 0.5 gallons of water from buckets[1] to buckets[0].
    /// 0.5 * 50% = 0.25 gallons are spilled and buckets[0] only receives 
    /// 0.5 - 0.25 = 0.25 gallons of water.
    /// Now, buckets = [2.25, 3.5, 6].
    /// Pour 2.5 gallons of water from buckets[2] to buckets[0].
    /// 2.5 * 50% = 1.25 gallons are spilled and buckets[0] only receives 
    /// 2.5 - 1.25 = 1.25 gallons of water.
    /// All buckets have 3.5 gallons of water in them so return 3.5.
    ///
    /// Example 3:
    /// Input: buckets = [3,3,3,3], loss = 40
    /// Output: 3.00000
    /// Explanation: All buckets already have the same amount of water in them.
    /// 
    /// Constraints:
    /// 1. 1 <= buckets.length <= 10^5
    /// 2. 0 <= buckets[i] <= 10^5
    /// 3. 0 <= loss <= 99
    /// </summary>
    double equalizeWater(vector<int>& buckets, int loss);

    /// <summary>
    /// Leet Code 2187. Minimum Time to Complete Trips
    ///                                                                                   
    /// Medium
    ///
    /// You are given an array time where time[i] denotes the time taken by 
    /// the ith bus to complete one trip.
    ///
    /// Each bus can make multiple trips successively; that is, the next trip 
    /// can start immediately after completing the current trip. Also, each 
    /// bus operates independently; that is, the trips of one bus do not 
    /// influence the trips of any other bus.
    ///
    /// You are also given an integer totalTrips, which denotes the number 
    /// of trips all buses should make in total. Return the minimum time 
    /// required for all buses to complete at least totalTrips trips.
    ///
    /// Example 1:
    /// Input: time = [1,2,3], totalTrips = 5
    /// Output: 3
    /// Explanation:
    /// - At time t = 1, the number of trips completed by each bus are [1,0,0]. 
    ///   The total number of trips completed is 1 + 0 + 0 = 1.
    /// - At time t = 2, the number of trips completed by each bus are [2,1,0]. 
    ///   The total number of trips completed is 2 + 1 + 0 = 3.
    /// - At time t = 3, the number of trips completed by each bus are [3,1,1]. 
    ///   The total number of trips completed is 3 + 1 + 1 = 5.
    /// So the minimum time needed for all buses to complete at least 5 trips is 3.
    ///
    /// Example 2:
    /// Input: time = [2], totalTrips = 1
    /// Output: 2
    /// Explanation:
    /// There is only one bus, and it will complete its first trip at t = 2.
    /// So the minimum time needed to complete 1 trip is 2.
    /// 
    /// Constraints:
    ///  1. 1 <= time.length <= 10^5
    /// 2. 1 <= time[i], totalTrips <= 10^7
    /// </summary>
    long long minimumTime(vector<int>& time, int totalTrips);

    /// <summary>
    /// Leet Code 2226. Maximum Candies Allocated to K Children
    ///                                                                                   
    /// Medium
    ///
    /// You are given a 0-indexed integer array candies. Each element in the 
    /// array denotes a pile of candies of size candies[i]. You can divide 
    /// each pile into any number of sub piles, but you cannot merge two 
    /// piles together.
    ///
    /// You are also given an integer k. You should allocate piles of candies 
    /// to k children such that each child gets the same number of candies. 
    /// Each child can take at most one pile of candies and some piles of 
    /// candies may go unused.
    ///
    /// Return the maximum number of candies each child can get.
    /// 
    /// Example 1:
    /// Input: candies = [5,8,6], k = 3
    /// Output: 5
    /// Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and 
    /// candies[2] into 2 piles of size 5 and 1. We now have five piles of 
    /// candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of 
    /// size 5 to 3 children. It can be proven that each child cannot receive 
    /// more than 5 candies.
    ///
    /// Example 2:
    /// Input: candies = [2,5], k = 11
    /// Output: 0
    /// Explanation: There are 11 children but only 7 candies in total, so it 
    /// is impossible to ensure each child receives at least one candy. Thus, 
    /// each child gets no candy and the answer is 0.
    ///
    /// Constraints:
    /// 1. 1 <= candies.length <= 10^5
    /// 2. 1 <= candies[i] <= 10^7
    /// 3. 1 <= k <= 10^12
    /// </summary>
    int maximumCandies(vector<int>& candies, long long k);

    /// <summary>
    /// Leet Code 2468. Split Message Based on Limit
    /// 
    /// Hard
    ///	
    /// You are given a string, message, and a positive integer, limit.
    ///
    /// You must split message into one or more parts based on limit. Each 
    /// resulting part should have the suffix "<a/b>", where "b" is to be 
    /// replaced with the total number of parts and "a" is to be replaced 
    /// with the index of the part, starting from 1 and going up to b. 
    /// Additionally, the length of each resulting part (including its 
    /// suffix) should be equal to limit, except for the last part whose 
    /// length can be at most limit.
    ///
    /// The resulting parts should be formed such that when their suffixes 
    /// are removed and they are all concatenated in order, they should be 
    /// equal to message. Also, the result should contain as few parts as 
    /// possible.
    ///
    /// Return the parts message would be split into as an array of strings. 
    /// If it is impossible to split message as required, return an empty 
    /// array.
    /// 
    /// Example 1:
    ///
    /// Input: message = "this is really a very awesome message", 
    /// limit = 9
    /// Output: ["thi<1/14>","s i<2/14>","s r<3/14>","eal<4/14>",
    /// "ly <5/14>","a v<6/14>","ery<7/14>"," aw<8/14>","eso<9/14>",
    /// "me<10/14>"," m<11/14>","es<12/14>","sa<13/14>","ge<14/14>"]
    /// Explanation:
    /// The first 9 parts take 3 characters each from the beginning 
    /// of message.
    /// The next 5 parts take 2 characters each to finish splitting 
    /// message. 
    /// In this example, each part, including the last, has length 9. 
    /// It can be shown it is not possible to split message into less 
    /// than 14 parts.
    ///
    /// Example 2:
    /// Input: message = "short message", limit = 15
    /// Output: ["short mess<1/2>","age<2/2>"]
    /// Explanation:
    /// Under the given constraints, the string can be split into 
    /// two parts: 
    /// - The first part comprises of the first 10 characters, 
    ///   and has a length 15.
    /// - The next part comprises of the last 3 characters, and has a length 8.
    /// 
    /// Constraints:
    /// 1. 1 <= message.length <= 10^4
    /// 2. message consists only of lowercase English letters and ' '.
    /// 3. 1 <= limit <= 10^4
    /// </summary>
    vector<string> splitMessage(string message, int limit);

    /// <summary>
    /// Leet Code 2513. Minimize the Maximum of Two Arrays
    /// 
    /// Medium
    ///	
    /// We have two arrays arr1 and arr2 which are initially empty. You need 
    /// to add positive integers to them such that they satisfy all the 
    /// following conditions:
    ///
    /// arr1 contains uniqueCnt1 distinct positive integers, each of which 
    /// is not divisible by divisor1.
    /// arr2 contains uniqueCnt2 distinct positive integers, each of which 
    /// is not divisible by divisor2.
    /// No integer is present in both arr1 and arr2.
    /// Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the 
    /// minimum possible maximum integer that can be present in either array.
    ///
    /// Example 1:
    /// Input: divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
    /// Output: 4
    /// Explanation: 
    /// We can distribute the first 4 natural numbers into arr1 and arr2.
    /// arr1 = [1] and arr2 = [2,3,4].
    /// We can see that both arrays satisfy all the conditions.
    /// Since the maximum value is 4, we return it.
    ///
    /// Example 2:
    /// Input: divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1
    /// Output: 3
    /// Explanation: 
    /// Here arr1 = [1,2], and arr2 = [3] satisfy all conditions.
    /// Since the maximum value is 3, we return it.
    ///
    /// Example 3:
    /// Input: divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
    /// Output: 15
    /// Explanation: 
    /// Here, the final possible arrays can be arr1 = [1,3,5,7,9,11,13,15], 
    /// and arr2 = [2,6].
    /// It can be shown that it is not possible to obtain a lower maximum 
    /// satisfying all conditions. 
    ///
    /// Constraints:
    /// 1. 2 <= divisor1, divisor2 <= 10^5
    /// 2. 1 <= uniqueCnt1, uniqueCnt2 < 10^9
    /// 3. 2 <= uniqueCnt1 + uniqueCnt2 <= 10^9
    /// </summary>
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2);

    /// <summary>
    /// Leet Code 2517. Maximum Tastiness of Candy Basket
    /// 
    /// Medium
    ///	
    /// You are given an array of positive integers price where price[i] 
    /// denotes the price of the ith candy and a positive integer k.
    ///
    /// The store sells baskets of k distinct candies. The tastiness of a 
    /// candy basket is the smallest absolute difference of the prices of 
    /// any two candies in the basket. 
    ///
    /// Return the maximum tastiness of a candy basket.
    ///
    /// Example 1:
    /// Input: price = [13,5,1,8,21,2], k = 3
    /// Output: 8
    /// Explanation: Choose the candies with the prices [13,5,21].
    /// The tastiness of the candy basket is: min(|13 - 5|, |13 - 21|, 
    /// |5 - 21|) = min(8, 8, 16) = 8.
    /// It can be proven that 8 is the maximum tastiness that can be achieved.
    ///
    /// Example 2:
    /// Input: price = [1,3,1], k = 2
    /// Output: 2
    /// Explanation: Choose the candies with the prices [1,3].
    /// The tastiness of the candy basket is: min(|1 - 3|) = min(2) = 2.
    /// It can be proven that 2 is the maximum tastiness that can be achieved.
    ///
    /// Example 3:
    /// Input: price = [7,7,7,7], k = 2
    /// Output: 0
    /// Explanation: Choosing any two distinct candies from the candies we 
    /// have will result in a tastiness of 0.
    /// 
    /// Constraints:
    /// 1. 2 <= k <= price.length <= 10^5
    /// 2. 1 <= price[i] <= 10^9
    /// </summary>
    int maximumTastiness(vector<int>& price, int k);

    /// <summary>
    /// Leet Code 2528. Maximize the Minimum Powered City
    /// 
    /// Hard
    ///	
    /// You are given a 0-indexed integer array stations of length n, where 
    /// stations[i] represents the number of power stations in the ith city.
    ///
    /// Each power station can provide power to every city in a fixed range. 
    /// In other words, if the range is denoted by r, then a power station 
    /// at city i can provide power to all cities j such that |i - j| <= r 
    /// and 0 <= i, j <= n - 1.
    ///
    /// Note that |x| denotes absolute value. For example, |7 - 5| = 2 
    /// and |3 - 10| = 7.
    /// The power of a city is the total number of power stations it is 
    /// being provided power from.
    ///
    /// The government has sanctioned building k more power stations, each of 
    /// which can be built in any city, and have the same range as the 
    /// pre-existing ones.
    ///
    /// Given the two integers r and k, return the maximum possible minimum 
    /// power of a city, if the additional power stations are built optimally.
    ///
    /// Note that you can build the k power stations in multiple cities.
    /// 
    /// Example 1:
    /// Input: stations = [1,2,4,5,0], r = 1, k = 2
    /// Output: 5
    /// Explanation: 
    /// One of the optimal ways is to install both the power stations at city 1. 
    /// So stations will become [1,4,4,5,0].
    /// - City 0 is provided by 1 + 4 = 5 power stations.
    /// - City 1 is provided by 1 + 4 + 4 = 9 power stations.
    /// - City 2 is provided by 4 + 4 + 5 = 13 power stations.
    /// - City 3 is provided by 5 + 4 = 9 power stations.
    /// - City 4 is provided by 5 + 0 = 5 power stations.
    /// So the minimum power of a city is 5.
    /// Since it is not possible to obtain a larger power, we return 5.
    /// Example 2:
    ///
    /// Input: stations = [4,4,4,4], r = 0, k = 3
    /// Output: 4
    /// Explanation: 
    /// It can be proved that we cannot make the minimum power of a 
    /// city greater than 4.
    ///
    /// Constraints:
    /// 1. n == stations.length
    /// 2. 1 <= n <= 10^5
    /// 3. 0 <= stations[i] <= 10^5
    /// 4. 0 <= r <= n - 1
    /// 5. 0 <= k <= 10^9
    /// </summary>
    long long maxPower(vector<int>& stations, int r, int k);

    /// <summary>
    /// Leet Code 2560. House Robber IV
    /// 
    /// Medium
    ///	
    /// There are several consecutive houses along a street, each of which has 
    /// some money inside. There is also a robber, who wants to steal money 
    /// from the homes, but he refuses to steal from adjacent homes.
    ///
    /// The capability of the robber is the maximum amount of money he steals 
    /// from one house of all the houses he robbed.
    ///
    /// You are given an integer array nums representing how much money is 
    /// stashed in each house. More formally, the ith house from the left 
    /// has nums[i] dollars.
    ///
    /// You are also given an integer k, representing the minimum number 
    /// of houses the robber will steal from. It is always possible to 
    /// steal at least k houses.
    ///
    /// Return the minimum capability of the robber out of all the possible 
    /// ways to steal at least k houses.
    ///
    /// Example 1:
    /// Input: nums = [2,3,5,9], k = 2
    /// Output: 5
    /// Explanation: 
    /// There are three ways to rob at least 2 houses:
    /// - Rob the houses at indices 0 and 2. Capability is 
    ///   max(nums[0], nums[2]) = 5.
    /// - Rob the houses at indices 0 and 3. Capability is 
    ///   max(nums[0], nums[3]) = 9.
    /// - Rob the houses at indices 1 and 3. Capability is 
    ///   max(nums[1], nums[3]) = 9.
    /// Therefore, we return min(5, 9, 9) = 5.
    ///
    /// Example 2:
    /// Input: nums = [2,7,9,3,1], k = 2
    /// Output: 2
    /// Explanation: There are 7 ways to rob the houses. The way which leads 
    /// to minimum capability is to rob the house at index 0 and 4. Return 
    /// max(nums[0], nums[4]) = 2.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= (nums.length + 1)/2
    /// </summary>
    int minCapability(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2563. Count the Number of Fair Pairs
    /// 
    /// Medium
    ///	
    /// Given a 0-indexed integer array nums of size n and two integers lower 
    /// and upper, return the number of fair pairs.
    ///
    /// A pair (i, j) is fair if:
    /// 
    /// 0 <= i < j < n, and
    /// lower <= nums[i] + nums[j] <= upper
    ///
    /// Example 1:
    /// Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
    /// Output: 6
    /// Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), 
    /// (1,4), and (1,5).
    ///
    /// Example 2:
    /// Input: nums = [1,7,9,2,5], lower = 11, upper = 11
    /// Output: 1
    /// Explanation: There is a single fair pair: (2,3).
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. nums.length == n
    /// 3. -10^9 <= nums[i] <= 10^9
    /// 4. -10^9 <= lower <= upper <= 10^9
    /// </summary>
    long long countFairPairs(vector<int>& nums, int lower, int upper);

    /// <summary>
    /// Leet Code 2604. Minimum Time to Eat All Grains
    /// 
    /// Hard
    ///	
    /// There are n hens and m grains on a line. You are given the initial 
    /// positions of the hens and the grains in two integer arrays hens 
    /// and grains of size n and m respectively.
    ///
    /// Any hen can eat a grain if they are on the same position. The time 
    /// taken for this is negligible. One hen can also eat multiple grains.
    ///
    /// In 1 second, a hen can move right or left by 1 unit. The hens can move 
    /// simultaneously and independently of each other.
    ///
    /// Return the minimum time to eat all grains if the hens act optimally. 
    ///
    /// Example 1:
    /// Input: hens = [3,6,7], grains = [2,4,7,9]
    /// Output: 2
    /// Explanation: 
    /// One of the ways hens eat all grains in 2 seconds is described below:
    /// - The first hen eats the grain at position 2 in 1 second. 
    /// - The second hen eats the grain at position 4 in 2 seconds. 
    /// - The third hen eats the grains at positions 7 and 9 in 2 seconds. 
    /// So, the maximum time needed is 2.
    /// It can be proven that the hens cannot eat all grains before 2 seconds.
    ///
    /// Example 2:
    /// Input: hens = [4,6,109,111,213,215], grains = [5,110,214]
    /// Output: 1
    /// Explanation: 
    /// One of the ways hens eat all grains in 1 second is described below:
    /// - The first hen eats the grain at position 5 in 1 second. 
    /// - The fourth hen eats the grain at position 110 in 1 second.
    /// - The sixth hen eats the grain at position 214 in 1 second. 
    /// - The other hens do not move. 
    /// So, the maximum time needed is 1.
    ///
    /// Constraints:
    /// 1. 1 <= hens.length, grains.length <= 2*10^4
    /// 2. 0 <= hens[i], grains[j] <= 109
    /// </summary>
    int minimumTime(vector<int>& hens, vector<int>& grains);

    /// <summary>
    /// Leet Code 2616. Minimize the Maximum Difference of Pairs
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums and an integer p. Find p 
    /// pairs of indices of nums such that the maximum difference amongst all 
    /// the pairs is minimized. Also, ensure no index appears more than once 
    /// amongst the p pairs.
    ///
    /// Note that for a pair of elements at the index i and j, the difference 
    /// of this pair is |nums[i] - nums[j]|, where |x| represents the 
    /// absolute value of x.
    ///
    /// Return the minimum maximum difference among all p pairs.
    /// Example 1:
    /// Input: nums = [10,1,2,7,1,3], p = 2
    /// Output: 1
    /// Explanation: The first pair is formed from the indices 1 and 4, and 
    /// the second pair is formed from the indices 2 and 5. 
    /// The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - 
    /// nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
    ///
    /// Example 2:
    /// Input: nums = [4,2,1,2], p = 1
    /// Output: 0
    /// Explanation: Let the indices 1 and 3 form a pair. The difference of 
    /// that pair is |2 - 2| = 0, which is the minimum we can attain.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// 3. 0 <= p <= (nums.length)/2
    /// </summary>
    int minimizeMax(vector<int>& nums, int p);

    /// <summary>
    /// Leet Code 2702. Minimum Operations to Make Numbers Non-positive
    /// 
    /// Hard
    ///	
    /// You are given a 0-indexed integer array nums and two integers x and y. 
    /// In one operation, you must choose an index i such that 
    /// 0 <= i < nums.length and perform the following:
    ///
    /// Decrement nums[i] by x.
    /// Decrement values by y at all indices except the ith one.
    /// Return the minimum number of operations to make all the integers in 
    /// nums less than or equal to zero.
    /// 
    /// Example 1:
    /// Input: nums = [3,4,1,7,6], x = 4, y = 2
    /// Output: 3
    /// Explanation: You will need three operations. One of the optimal 
    /// sequence of operations is:
    /// Operation 1: Choose i = 3. Then, nums = [1,2,-1,3,4]. 
    /// Operation 2: Choose i = 3. Then, nums = [-1,0,-3,-1,2].
    /// Operation 3: Choose i = 4. Then, nums = [-3,-2,-5,-3,-2].
    /// Now, all the numbers in nums are non-positive. Therefore, we return 3.
    ///
    /// Example 2:
    /// Input: nums = [1,2,1], x = 2, y = 1
    /// Output: 1
    /// Explanation: We can perform the operation once on i = 1. Then, nums 
    /// becomes [0,0,0]. All the positive numbers are removed, and therefore, 
    /// we return 1.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= y < x <= 10^9
    /// </summary>
    int minOperations(vector<int>& nums, int x, int y);

    /// <summary>
    /// Leet 2819. Minimum Relative Loss After Buying Chocolates
    /// 
    /// Hard
    ///
    /// You are given an integer array prices, which shows the chocolate 
    /// prices and a 2D integer array queries, where queries[i] = [ki, mi].
    ///
    /// Alice and Bob went to buy some chocolates, and Alice suggested a way 
    /// to pay for them, and Bob agreed.
    ///
    /// The terms for each query are as follows:
    ///
    /// If the price of a chocolate is less than or equal to ki, Bob pays 
    /// for it.
    /// Otherwise, Bob pays ki of it, and Alice pays the rest.
    /// Bob wants to select exactly mi chocolates such that his relative loss 
    /// is minimized, more formally, if, in total, Alice has paid ai and Bob 
    /// has paid bi, Bob wants to minimize bi - ai.
    ///
    /// Return an integer array ans where ans[i] is Bob's minimum relative 
    /// loss possible for queries[i].
    ///
    /// Example 1:
    /// Input: prices = [1,9,22,10,19], queries = [[18,4],[5,2]]
    /// Output: [34,-21]
    /// Explanation: For the 1st query Bob selects the chocolates with prices 
    /// [1,9,10,22]. He pays 1 + 9 + 10 + 18 = 38 and Alice pays 
    /// 0 + 0 + 0 + 4 = 4. So Bob's relative loss is 38 - 4 = 34.
    /// For the 2nd query Bob selects the chocolates with prices [19,22]. He 
    /// pays 5 + 5 = 10 and Alice pays 14 + 17 = 31. So Bob's relative loss 
    /// is 10 - 31 = -21.
    /// It can be shown that these are the minimum possible relative losses.
    ///
    /// Example 2:
    /// Input: prices = [1,5,4,3,7,11,9], queries = [[5,4],[5,7],[7,3],[4,5]]
    /// Output: [4,16,7,1]
    /// Explanation: For the 1st query Bob selects the chocolates with prices 
    /// [1,3,9,11]. He pays 1 + 3 + 5 + 5 = 14 and Alice pays 0 + 0 + 4 + 6 = 10. 
    /// So Bob's relative loss is 14 - 10 = 4.
    /// For the 2nd query Bob has to select all the chocolates. He pays 1 + 5 + 
    /// 4 + 3 + 5 + 5 + 5 = 28 and Alice pays 0 + 0 + 0 + 0 + 2 + 6 + 4 = 12. So 
    /// Bob's relative loss is 28 - 12 = 16.
    /// For the 3rd query Bob selects the chocolates with prices [1,3,11] and 
    /// he pays 1 + 3 + 7 = 11 and Alice pays 0 + 0 + 4 = 4. So Bob's relative 
    /// loss is 11 - 4 = 7.
    /// For the 4th query Bob selects the chocolates with prices [1,3,7,9,11] 
    /// and he pays 1 + 3 + 4 + 4 + 4 = 16 and Alice pays 0 + 0 + 3 + 5 + 7 
    /// = 15. So Bob's relative loss is 16 - 15 = 1.
    /// It can be shown that these are the minimum possible relative losses.
    ///
    /// Example 3:
    /// Input: prices = [5,6,7], queries = [[10,1],[5,3],[3,3]]
    /// Output: [5,12,0]
    /// Explanation: For the 1st query Bob selects the chocolate with price 5 
    /// and he pays 5 and Alice pays 0. So Bob's relative loss is 5 - 0 = 5.
    /// For the 2nd query Bob has to select all the chocolates. He pays 5 + 
    /// 5 + 5 = 15 and Alice pays 0 + 1 + 2 = 3. So Bob's relative loss 
    /// is 15 - 3 = 12.
    /// For the 3rd query Bob has to select all the chocolates. He pays 
    /// 3 + 3 + 3 = 9 and Alice pays 2 + 3 + 4 = 9. So Bob's relative loss 
    /// is 9 - 9 = 0.
    /// It can be shown that these are the minimum possible relative losses.
    ///
    /// Constraints:
    /// 1. 1 <= prices.length == n <= 10^5
    /// 2. 1 <= prices[i] <= 10^9
    /// 3. 1 <= queries.length <= 10^5
    /// 4. queries[i].length == 2
    /// 5. 1 <= ki <= 10^9
    /// 6. 1 <= mi <= n
    /// </summary>
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2861. Maximum Number of Alloys
    /// 
    /// Medium
    ///
    /// You are the owner of a company that creates alloys using various types 
    /// of metals. There are n different types of metals available, and you 
    /// have access to k machines that can be used to create alloys. Each 
    /// machine requires a specific amount of each metal type to create an 
    /// alloy.
    /// 
    /// For the ith machine to create an alloy, it needs composition[i][j] 
    /// units of metal of type j. Initially, you have stock[i] units of metal 
    /// type i, and purchasing one unit of metal type i costs cost[i] coins.
    ///
    /// Given integers n, k, budget, a 1-indexed 2D array composition, and 
    /// 1-indexed arrays stock and cost, your goal is to maximize the number 
    /// of alloys the company can create while staying within the budget of 
    /// budget coins.
    ///
    /// All alloys must be created with the same machine.
    /// Return the maximum number of alloys that the company can create.
    ///
    /// Example 1:
    /// Input: n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], 
    /// stock = [0,0,0], cost = [1,2,3]
    /// Output: 2
    /// Explanation: It is optimal to use the 1st machine to create alloys.
    /// To create 2 alloys we need to buy the:
    /// - 2 units of metal of the 1st type.
    /// - 2 units of metal of the 2nd type.
    /// - 2 units of metal of the 3rd type.
    /// In total, we need 2 * 1 + 2 * 2 + 2 * 3 = 12 coins, which is smaller 
    /// than or equal to budget = 15.
    /// Notice that we have 0 units of metal of each type and we have to buy 
    /// all the required units of metal.
    /// It can be proven that we can create at most 2 alloys.
    ///
    /// Example 2:
    /// Input: n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], 
    /// stock = [0,0,100], cost = [1,2,3]
    /// Output: 5
    /// Explanation: It is optimal to use the 2nd machine to create alloys.
    /// To create 5 alloys we need to buy:
    /// - 5 units of metal of the 1st type.
    /// - 5 units of metal of the 2nd type.
    /// - 0 units of metal of the 3rd type.
    /// In total, we need 5 * 1 + 5 * 2 + 0 * 3 = 15 coins, which is smaller
    /// than or equal to budget = 15.
    /// It can be proven that we can create at most 5 alloys.
    ///
    /// Example 3:
    /// Input: n = 2, k = 3, budget = 10, composition = [[2,1],[1,2],[1,1]], 
    /// stock = [1,1], cost = [5,5]
    /// Output: 2
    /// Explanation: It is optimal to use the 3rd machine to create alloys.
    /// To create 2 alloys we need to buy the:
    /// - 1 unit of metal of the 1st type.
    /// - 1 unit of metal of the 2nd type.
    /// In total, we need 1 * 5 + 1 * 5 = 10 coins, which is smaller than or 
    /// equal to budget = 10.
    /// It can be proven that we can create at most 2 alloys.
    /// 
    /// Constraints:
    /// 1. 1 <= n, k <= 100
    /// 2. 0 <= budget <= 10^8
    /// 3. composition.length == k
    /// 4. composition[i].length == n
    /// 5. 1 <= composition[i][j] <= 100
    /// 6. stock.length == cost.length == n
    /// 7. 0 <= stock[i] <= 10^8
    /// 8. 1 <= cost[i] <= 100
    /// </summary>
    int maxNumberOfAlloys(int n, int k, int budget, 
        vector<vector<int>>& composition,
        vector<int>& stock, vector<int>& cost);

    /// <summary>
    /// Leet Code 2936. Number of Equal Numbers Blocks
    ///  
    /// Medium
    ///
    /// You are given a 0-indexed array of integers, nums. The following 
    /// property holds for nums:
    ///
    /// All occurrences of a value are adjacent. In other words, if there are 
    /// two indices i < j such that nums[i] == nums[j], then for every index 
    /// k that i < k < j, nums[k] == nums[i].
    /// Since nums is a very large array, you are given an instance of the 
    /// class BigArray which has the following functions:
    ///
    /// int at(long long index): Returns the value of nums[i].
    /// void size(): Returns nums.length.
    /// Let's partition the array into maximal blocks such that each block 
    /// contains equal values. Return the number of these blocks.
    ///
    /// Note that if you want to test your solution using a custom test, 
    /// behavior for tests with nums.length > 10 is undefined.
    ///
    ///
    /// Example 1:
    ///
    /// Input: nums = [3,3,3,3,3]
    /// Output: 1
    /// Explanation: There is only one block here which is the whole array 
    /// (because all numbers are equal) and that is: [3,3,3,3,3]. So the 
    /// answer would be 1. 
    ///
    /// Example 2:
    /// Input: nums = [1,1,1,3,9,9,9,2,10,10]
    /// Output: 5
    /// Explanation: There are 5 blocks here:
    /// Block number 1: [1,1,1,3,9,9,9,2,10,10]
    /// Block number 2: [1,1,1,3,9,9,9,2,10,10]
    /// Block number 3: [1,1,1,3,9,9,9,2,10,10]
    /// Block number 4: [1,1,1,3,9,9,9,2,10,10]
    /// Block number 5: [1,1,1,3,9,9,9,2,10,10]
    /// So the answer would be 5.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3,4,5,6,7]
    /// Output: 7
    /// Explanation: Since all numbers are distinct, there are 7 blocks here 
    /// and each element representing one block. So the answer would be 7. 
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^15
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. The input is generated such that all equal values are adjacent.
    /// 4. The sum of the elements of nums is at most 10^15.
    /// </summary>
    int countBlocks(vector<int> nums);

    /// <summary>
    /// Leet Code 3007. Maximum Number That Sum of the Prices Is Less Than or 
    ///                 Equal to K
    ///                 
    /// Medium
    ///
    /// You are given an integer k and an integer x.
    ///
    /// Consider s is the 1-indexed binary representation of an integer num. The 
    /// price of a number num is the number of i's such that i % x == 0 and s[i] 
    /// is a set bit.
    ///
    /// Return the greatest integer num such that the sum of prices of all numbers 
    /// from 1 to num is less than or equal to k.
    ///
    /// Note:
    ///
    /// In the binary representation of a number set bit is a bit of value 1.
    /// The binary representation of a number will be indexed from right to left. 
    /// For example, if s == 11100, s[4] == 1 and s[2] == 0.
    ///
    /// Example 1:
    /// Input: k = 9, x = 1
    /// Output: 6
    /// Explanation: The numbers 1, 2, 3, 4, 5, and 6 can be written in binary 
    /// representation as "1", "10", "11", "100", "101", and "110" respectively.
    /// Since x is equal to 1, the price of each number is the number of its set 
    /// bits.
    /// The number of set bits in these numbers is 9. So the sum of the prices 
    /// of the first 6 numbers is 9.
    /// So the answer is 6.
    ///
    /// Example 2:
    /// Input: k = 7, x = 2
    /// Output: 9
    /// Explanation: Since x is equal to 2, we should just check eventh bits.
    /// The second bit of binary representation of numbers 2 and 3 is a set bit. 
    /// So the sum of their prices is 2.
    /// The second bit of binary representation of numbers 6 and 7 is a set bit. 
    /// So the sum of their prices is 2.
    /// The fourth bit of binary representation of numbers 8 and 9 is a set bit 
    /// but their second bit is not. So the sum of their prices is 2.
    /// Numbers 1, 4, and 5 don't have set bits in their eventh bits in their 
    /// binary representation. So the sum of their prices is 0.
    /// The second and the fourth bit of the binary representation of the 
    /// number 10 are a set bit. So its price is 2.
    /// The sum of the prices of the first 9 numbers is 6.
    /// Because the sum of the prices of the first 10 numbers is 8, the answer 
    /// is 9.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= 10^15
    /// 2. 1 <= x <= 8
    /// </summary>
    long long findMaximumNumber(long long k, int x);


    /// <summary>
    /// Leet Code 3048. Earliest Second to Mark Indices I
    ///
    /// Medium
    ///
    /// You are given two 1-indexed integer arrays, nums and, changeIndices, 
    /// having lengths n and m, respectively.
    ///
    /// Initially, all indices in nums are unmarked. Your task is to mark 
    /// all indices in nums.
    /// In each second, s, in order from 1 to m (inclusive), you can perform 
    /// one of the following operations:
    ///
    /// 1. Choose an index i in the range [1, n] and decrement nums[i] by 1.
    /// 2. If nums[changeIndices[s]] is equal to 0, mark the index 
    ///    changeIndices[s].
    /// 3. Do nothing.
    /// Return an integer denoting the earliest second in the range [1, m] 
    /// when all indices in nums can be marked by choosing operations 
    /// optimally, or -1 if it is impossible.
    /// 
    /// Example 1:
    /// Input: nums = [2,2,0], changeIndices = [2,2,2,2,3,2,2,1]
    /// Output: 8
    /// Explanation: In this example, we have 8 seconds. The following 
    /// operations can be performed to mark all indices:
    /// Second 1: Choose index 1 and decrement nums[1] by one. nums 
    /// becomes [1,2,0].
    /// Second 2: Choose index 1 and decrement nums[1] by one. nums 
    /// becomes [0,2,0].
    /// Second 3: Choose index 2 and decrement nums[2] by one. nums 
    /// becomes [0,1,0].
    /// Second 4: Choose index 2 and decrement nums[2] by one. nums 
    /// becomes [0,0,0].
    /// Second 5: Mark the index changeIndices[5], which is marking index 3, 
    /// since nums[3] is equal to 0.
    /// Second 6: Mark the index changeIndices[6], which is marking index 2, 
    /// since nums[2] is equal to 0.
    /// Second 7: Do nothing.
    /// Second 8: Mark the index changeIndices[8], which is marking index 1, 
    /// since nums[1] is equal to 0.
    /// Now all indices have been marked.
    /// It can be shown that it is not possible to mark all indices earlier 
    /// than the 8th second.
    /// Hence, the answer is 8.
    ///
    /// Example 2:
    /// Input: nums = [1,3], changeIndices = [1,1,1,2,1,1,1]
    /// Output: 6
    /// Explanation: In this example, we have 7 seconds. The following 
    /// operations can be performed to mark all indices:
    /// Second 1: Choose index 2 and decrement nums[2] by one. nums 
    /// becomes [1,2].
    /// Second 2: Choose index 2 and decrement nums[2] by one. nums 
    /// becomes [1,1].
    /// Second 3: Choose index 2 and decrement nums[2] by one. nums 
    /// becomes [1,0].
    /// Second 4: Mark the index changeIndices[4], which is marking 
    /// index 2, since nums[2] is equal to 0.
    /// Second 5: Choose index 1 and decrement nums[1] by one. nums 
    /// becomes [0,0].
    /// Second 6: Mark the index changeIndices[6], which is marking 
    /// index 1, since nums[1] is equal to 0.
    /// Now all indices have been marked.
    /// It can be shown that it is not possible to mark all indices 
    /// earlier than the 6th second.
    /// Hence, the answer is 6.
    ///
    /// Example 3:
    /// Input: nums = [0,1], changeIndices = [2,2,2]
    /// Output: -1
    /// Explanation: In this example, it is impossible to mark all 
    /// indices because index 1 isn't in changeIndices.
    /// Hence, the answer is -1.
    ///
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 2000
    /// 2. 0 <= nums[i] <= 10^9
    /// 3. 1 <= m == changeIndices.length <= 2000
    /// 4. 1 <= changeIndices[i] <= n
    /// </summary>
    int earliestSecondToMarkIndicesI(vector<int>& nums, vector<int>& changeIndices);

    /// <summary>
    /// Leet Code 3049. Earliest Second to Mark Indices II
    ///
    /// Hard
    ///
    /// You are given two 1-indexed integer arrays, nums and, changeIndices, 
    /// having lengths n and m, respectively.
    ///
    /// Initially, all indices in nums are unmarked. Your task is to mark all 
    /// indices in nums.
    ///
    /// In each second, s, in order from 1 to m (inclusive), you can perform 
    /// one of the following operations:
    ///
    /// 1. Choose an index i in the range [1, n] and decrement nums[i] by 1.
    /// 2. Set nums[changeIndices[s]] to any non-negative value.
    /// 3. Choose an index i in the range [1, n], where nums[i] is equal to 0, 
    ///    and mark index i.
    /// 4. Do nothing.
    /// Return an integer denoting the earliest second in the range [1, m] 
    /// when all indices in nums can be marked by choosing operations 
    /// optimally, or -1 if it is impossible.
    ///
    /// Example 1:
    /// Input: nums = [3,2,3], changeIndices = [1,3,2,2,2,2,3]
    /// Output: 6
    /// Explanation: In this example, we have 7 seconds. The following 
    /// operations can be performed to mark all indices:
    /// Second 1: Set nums[changeIndices[1]] to 0. nums becomes [0,2,3].
    /// Second 2: Set nums[changeIndices[2]] to 0. nums becomes [0,2,0].
    /// Second 3: Set nums[changeIndices[3]] to 0. nums becomes [0,0,0].
    /// Second 4: Mark index 1, since nums[1] is equal to 0.
    /// Second 5: Mark index 2, since nums[2] is equal to 0.
    /// Second 6: Mark index 3, since nums[3] is equal to 0.
    /// Now all indices have been marked.
    /// It can be shown that it is not possible to mark all indices earlier 
    /// than the 6th second.
    /// Hence, the answer is 6.
    ///
    /// Example 2:
    /// Input: nums = [0,0,1,2], changeIndices = [1,2,1,2,1,2,1,2]
    /// Output: 7
    /// Explanation: In this example, we have 8 seconds. The following 
    /// operations can be performed to mark all indices:
    /// Second 1: Mark index 1, since nums[1] is equal to 0.
    /// Second 2: Mark index 2, since nums[2] is equal to 0.
    /// Second 3: Decrement index 4 by one. nums becomes [0,0,1,1].
    /// Second 4: Decrement index 4 by one. nums becomes [0,0,1,0].
    /// Second 5: Decrement index 3 by one. nums becomes [0,0,0,0].
    /// Second 6: Mark index 3, since nums[3] is equal to 0.
    /// Second 7: Mark index 4, since nums[4] is equal to 0.
    /// Now all indices have been marked.
    /// It can be shown that it is not possible to mark all indices earlier 
    /// than the 7th second.
    /// Hence, the answer is 7.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3], changeIndices = [1,2,3]
    /// Output: -1
    /// Explanation: In this example, it can be shown that it is impossible 
    /// to mark all indices, as we don't have enough seconds. 
    /// Hence, the answer is -1.
    /// 
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 5000
    /// 2. 0 <= nums[i] <= 10^9 
    /// 3. 1 <= m == changeIndices.length <= 5000
    /// 4. 1 <= changeIndices[i] <= n
    /// </summary>
    int earliestSecondToMarkIndicesII(vector<int>& nums, vector<int>& changeIndices);

    /// <summary>
    /// LeetCode 3134. Find the Median of the Uniqueness Array
    ///                
    /// Hard
    ///
    /// You are given an integer array nums. The uniqueness array of nums is 
    /// the sorted array that contains the number of distinct elements of all 
    /// the subarrays of nums. In other words, it is a sorted array consisting 
    /// of distinct(nums[i..j]), for all 0 <= i <= j < nums.length.
    ///
    /// Here, distinct(nums[i..j]) denotes the number of distinct elements in 
    /// the subarray that starts at index i and ends at index j.
    ///
    /// Return the median of the uniqueness array of nums.
    /// 
    /// Note that the median of an array is defined as the middle element of 
    /// the array when it is sorted in non-decreasing order. If there are two 
    /// choices for a median, the smaller of the two values is taken.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3]
    /// Output: 1
    /// Explanation:
    /// The uniqueness array of nums is [distinct(nums[0..0]), 
    /// distinct(nums[1..1]), distinct(nums[2..2]), distinct(nums[0..1]), 
    /// distinct(nums[1..2]), distinct(nums[0..2])] which is equal to 
    /// [1, 1, 1, 2, 2, 3]. The uniqueness array has a median of 1. Therefore, 
    /// the answer is 1.
    ///
    /// Example 2:
    /// Input: nums = [3,4,3,4,5]
    /// Output: 2
    /// Explanation:
    ///
    /// The uniqueness array of nums is [1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 
    /// 3, 3, 3]. The uniqueness array has a median of 2. Therefore, the 
    /// answer is 2.
    ///
    /// Example 3:
    /// Input: nums = [4,3,5,4]
    /// Output: 2
    /// Explanation:
    /// The uniqueness array of nums is [1, 1, 1, 1, 2, 2, 2, 3, 3, 3]. The 
    /// uniqueness array has a median of 2. Therefore, the answer is 2.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int medianOfUniquenessArray(vector<int>& nums);
#pragma endregion
};
#endif  // LeetCodeBinarySearch_H
