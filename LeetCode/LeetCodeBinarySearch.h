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
    /// Leet code #275. H-Index II 
    /// Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm? 
    /// Hint:
    /// 1.Expected runtime complexity is in O(log n) and the input is sorted.
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
    /// Leet code #658. Find K Closest Elements
    /// 
    /// Given a sorted array, two integers k and x, find the k closest 
    /// elements to x in the array. The result should also be sorted in 
    /// ascending order. If there is a tie, the smaller elements are always 
    /// preferred. 
    /// 
    /// Example 1:
    /// Input: [1,2,3,4,5], k=4, x=3
    /// Output: [1,2,3,4]
    ///
    /// Example 2:
    /// Input: [1,2,3,4,5], k=4, x=-1
    /// Output: [1,2,3,4]
    /// 
    /// Note:
    /// 1. The value k is positive and will always be smaller than the length 
    ///    of the sorted array.
    /// 2. Length of the given array is positive and will not exceed 10^4
    /// 3. Absolute value of elements in the array and x will not exceed 10^4
    /// </summary>
    vector<int> findClosestElements(vector<int>& arr, int k, int x);

    /// <summary>
    /// Leet code #658. Find K Closest Elements
    /// 
    /// Given a sorted array, two integers k and x, find the k closest 
    /// elements to x in the array. The result should also be sorted in 
    /// ascending order. If there is a tie, the smaller elements are always 
    /// preferred. 
    /// 
    /// Example 1:
    /// Input: [1,2,3,4,5], k=4, x=3
    /// Output: [1,2,3,4]
    ///
    /// Example 2:
    /// Input: [1,2,3,4,5], k=4, x=-1
    /// Output: [1,2,3,4]
    /// 
    /// Note:
    /// 1. The value k is positive and will always be smaller than the length 
    ///    of the sorted array.
    /// 2. Length of the given array is positive and will not exceed 10^4
    /// 3. Absolute value of elements in the array and x will not exceed 10^4
    /// </summary>
    vector<int> findClosestElementsII(vector<int>& arr, int k, int x);

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
    /// Given an input array nums, where nums[i] ¡Ù nums[i+1], find a peak element 
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
    int shipWithinDays(vector<int>& weights, int D);

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
    int minEatingSpeed(vector<int>& piles, int H);

    /// <summary>
    /// Leet code #719. Find K-th Smallest Pair Distance
    /// Given an integer array, return the k-th smallest distance among all 
    /// the pairs. The distance of a pair (A, B) is defined as the absolute 
    /// difference between A and B.
    ///
    /// Example 1:
    /// Input:
    /// nums = [1,3,1]
    /// k = 1
    /// Output: 0 
    /// Explanation:
    /// Here are all the pairs:
    /// (1,3) -> 2
    /// (1,1) -> 0
    /// (3,1) -> 2
    /// Then the 1st smallest distance pair is (1,1), and its distance is 0.
    /// Note:
    /// 1. 2 <= len(nums) <= 10000.
    /// 2. 0 <= nums[i] < 1000000.
    /// 3. 1 <= k <= len(nums) * (len(nums) - 1) / 2.	
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
    /// Leet code #410. Split Array Largest Sum
    ///  
    /// Given an array which consists of non-negative integers and an integer m, 
    /// you can split the array into m non-empty continuous subarrays. Write an 
    /// algorithm to minimize the largest sum among these m subarrays.
    ///
    /// Note:
    /// If n is the length of array, assume the following constraints are 
    /// satisfied:
    ///
    /// 1. 1 ¡Ü n ¡Ü 1000
    /// 2. 1 ¡Ü m ¡Ü min(50, n)
    ///
    /// Examples:
    /// Input:
    /// nums = [7,2,5,10,8]
    /// m = 2
    ///
    /// Output:
    /// 18
    ///
    /// Explanation:
    /// There are four ways to split nums into two subarrays.
    /// The best way is to split it into [7,2,5] and [10,8],
    /// where the largest sum among the two subarrays is only 18.
    /// </summary>
    int splitArray(vector<int>& nums, int m);

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
#pragma endregion
};
#endif  // LeetCodeBinarySearch_H
