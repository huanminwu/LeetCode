#pragma once
#include <ctype.h>  /* is space */
#include <stdio.h>     /* printf */
#include <stdlib.h>  
#include <time.h>  
#include <functional>
#include <algorithm> 
#include <unordered_map> 
#include <unordered_set> 
#include <map> 
#include <numeric>
#include <stack>
#include <set>
#include <queue> 
#include <vector>
#include <iostream>
#include <fstream>
#include "Leetcode.h"
#include "LeetCodeBinarySearch.h"
#pragma region BinarySearch
/// <summary>
/// Leet code #35. Search Insert Position   
/// Given a sorted array and a target value, return the index if the target 
/// is found. If not, return the index where it would be if it were inserted 
/// in order. 
/// You may assume no duplicates in the array. 
/// Here are few examples.
/// [1,3,5,6], 5 -> 2
/// [1,3,5,6], 2 -> 1
/// [1,3,5,6], 7 -> 4
/// [1,3,5,6], 0 -> 0 
/// </summary>
int LeetCodeBinarySearch::searchInsert(vector<int>& nums, int target)
{
    // assign the first as 0, last can be the last item or out of boundary
    int first = 0, last = nums.size() - 1;
    int result = nums.size();
    // when first == last break out
    while (first <= last)
    {
        // check the middle point, make sure out overflow
        // please remember this is an int, so always left bias
        int middle = first + (last - first) / 2;
        // if target is located at second half, should go 
        // beyond middle point to avoid dead loop.
        if (nums[middle] >= target)
        {
            result = middle;
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    // you can return middle or first, return first is better 
    // because no need to keep track middle
    return result;
}

/// <summary>
/// Leet code #74. Search a 2D Matrix   
///
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
bool LeetCodeBinarySearch::searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int r = 0;
    int c = matrix[0].size() - 1;
    while (c >= 0 && r < n)
    {
        if (matrix[r][c] == target) return true;
        else if (matrix[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    return false;
}

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
int LeetCodeBinarySearch::guessNumber(int n, int guess)
{
    int first = 1;
    int last = n;
    int middle = first;
    while (first < last)
    {
        middle = first + (last - first) / 2;
        int guess_result = (guess == middle) ? 0 : guess < middle ? -1 : 1;
        if (guess_result == 0) break;
        if (guess_result == 1)
        {
            first = middle + 1;
            middle++;
        }
        else
        {
            last = middle;
        }
    }
    return middle;
}

/// <summary>
/// Leet code #69. Sqrt(x) 
/// Implement int sqrt(int x). 
/// Compute and return the square root of x. 
/// </summary>
int LeetCodeBinarySearch::mySqrt(int x)
{
    int first = 0;
    int last = min(x, (int)sqrt(INT_MAX));
    while (first < last)
    {
        int mid = (first + last + 1) / 2;
        if (mid * mid > x)
        {
            last = mid - 1;
        }
        else
        {
            first = mid;
        }
    }
    return first;
}

/// <summary>
/// Leet code #367. Valid Perfect Square 
/// Given a positive integer num, write a function which returns True if num is a 
/// perfect square else False.
/// Note: Do not use any built-in library function such as sqrt. 
/// Example 1: 
/// Input: 16
/// Returns: True
///
/// Example 2: 
/// Input: 14
/// Returns: False
/// </summary>
bool LeetCodeBinarySearch::isPerfectSquare(int num)
{
    unsigned long long first = 1;
    unsigned long long last = num;
    unsigned long long middle = first;
    unsigned long long target = num;
    while (first < last)
    {
        middle = first + (last - first) / 2;
        if (middle * middle < target)
        {
            first = middle + 1;
            middle++;
        }
        else
        {
            last = middle;
        }
    }
    if (middle * middle == target)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
vector<int> LeetCodeBinarySearch::searchRange(vector<int>& nums, int target)
{
    vector<int> result = { -1, -1 };
    if (nums.empty()) return result;
    int first = 0, last = nums.size() - 1;
    while (first < last)
    {
        int middle = first + (last - first) / 2;
        if (target > nums[middle])
        {
            first = middle + 1;
        }
        else
        {
            last = middle;
        }
    }
    if (first < (int)nums.size() && nums[first] == target)
    {
        last = first;
        while ((last < (int)(nums.size() - 1)) && (nums[last + 1] == target))
        {
            last++;
        }
        result = { first, last };
    }
    return result;
}

/// <summary>
/// Leet code #278. First Bad Version  
/// You are a product manager and currently leading a team to develop a new product. 
/// Unfortunately, the latest version of your product fails the quality check. Since each version 
/// is developed based on the previous version, all the versions after a bad version are also bad. 
/// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad. 
/// You are given an API bool isBadVersion(version) which will return whether version is bad. 
/// Implement a function to find the first bad version. You should minimize the number of calls to the API. 
/// </summary>
int LeetCodeBinarySearch::firstBadVersion(int n, int bad_version)
{
    int first = 1;
    int last = n;
    int middle = first;
    while (first < last)
    {
        middle = first + (last - first) / 2;
        if (middle < bad_version)
        {
            first = middle + 1;
            middle++;
        }
        else
        {
            last = middle;
        }
    }
    return middle;
}

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
int LeetCodeBinarySearch::hIndexII(vector<int>& citations)
{
    int first = 0;
    int last = citations.size() - 1;
    int result = 0;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        if (citations[middle] >= (int)citations.size() - middle)
        {
            result = (int)citations.size() - middle;
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::findPeakElement(vector<int>& nums)
{
    int first = 0;
    int last = nums.size() - 1;
    int middle = last;
    while (first < last)
    {
        middle = first + (last - first) / 2;
        if (nums[middle] < nums[middle + 1])
        {
            first = middle + 1;
        }
        else
        {
            last = middle;
        }
    }
    return last;
}

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
bool LeetCodeBinarySearch::searchMatrixII(vector<vector<int>>& matrix, int target)
{
    if ((matrix.size() == 0) || (matrix[0].size() == 0))
    {
        return false;
    }
    // starting from the end of first row
    int row = 0;
    int col = matrix[0].size() - 1;
    while ((row < (int)matrix.size()) && (col >= 0))
    {
        // if target is greater than the specified position, exclude the row
        if (matrix[row][col] < target)
        {
            row++;
        }
        // if target is greater than the specified position, exclude the column
        else if (matrix[row][col] > target)
        {
            col--;
        }
        else
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #378. Kth Smallest Element in a Sorted Matrix   
/// </summary>
int LeetCodeBinarySearch::countNoGreaterValue(vector<vector<int>>& matrix, int value, int k)
{
    int i = 0, j = matrix[0].size() - 1;
    int count = 0;
    while (i < (int)matrix.size() && j >= 0)
    {
        if (matrix[i][j] <= value)
        {
            i++;
            count += j + 1;
            if (count > k) return count;
        }
        else j--;
    }
    return count;
}

/// <summary>
/// Leet code #378. Kth Smallest Element in a Sorted Matrix   
/// 
/// Given a n x n matrix where each of the rows and columns are sorted 
/// in ascending order, 
/// find the kth smallest element in the matrix. Note that it is the kth 
/// smallest element in the sorted order, not the kth distinct element. 
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
int LeetCodeBinarySearch::kthSmallest(vector<vector<int>>& matrix, int k)
{
    int low = matrix[0][0];
    int high = matrix[matrix.size() - 1][matrix[0].size() - 1];
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (countNoGreaterValue(matrix, mid, k) < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

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
int LeetCodeBinarySearch::search(vector<int>& nums, int target)
{
    int first = 0, last = nums.size() - 1;
    while (first <= last)
    {
        size_t middle = first + (last - first) / 2;
        if (target == nums[middle])
        {
            return middle;
        }
        // because a range can be one item, so = is important.
        else if (nums[first] <= nums[middle])
        {
            // if the target is not within ordered range 
            if ((target < nums[first]) || (target > nums[middle]))
            {
                first = middle + 1;
            }
            else // if not in another range.
            {
                last = middle - 1;
            }
        }
        else
        {
            if ((target > nums[middle]) && (target <= nums[last]))
            {
                first = middle + 1;
            }
            else
            {
                last = middle - 1;
            }
        }
    }
    return -1;
}

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
bool LeetCodeBinarySearch::searchII(vector<int>& nums, int target)
{
    int first = 0;
    // because we need to compare with right end, so must point to a solid item.
    int last = nums.size() - 1;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        if (target == nums[middle])
        {
            return true;
        }
        else if (nums[first] < nums[middle])
        {
            // first check the target is within the ordered range, if not must be
            // in a disordered range
            if (target < nums[first] || target > nums[middle])
            {
                first = middle + 1;
            }
            else
            {
                last = middle - 1;
            }
        }
        else if (nums[middle] < nums[last])
        {
            if (target < nums[middle] || target > nums[last])
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1;
            }
        }
        // otherwise we move the first or the last until we find a disordered one
        else if (nums[first] == nums[middle])
        {
            first++;
        }
        else if (nums[last] == nums[middle])
        {
            last--;
        }
    }
    return false;
}

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
int LeetCodeBinarySearch::findMin(vector<int>& nums)
{
    int first = 0;
    int last = nums.size() - 1;
    int result = INT_MAX;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        // If first is greater than last, then the minimum item must be 
        // within the range
        if (nums[first] > nums[middle])
        {
            result = min(result, nums[middle]);
            last = middle - 1;
        }
        else if (nums[middle] > nums[last])
        {
            result = min(result, nums[last]);
            first = middle + 1;
        }
        else
        {
            result = min(result, nums[first]);
            break;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::findMinII(vector<int>& nums)
{
    if (nums.size() == 0) return 0;
    int first = 0;
    int last = nums.size() - 1;
    while (first < last)
    {
        int middle = first + (last - first) / 2;
        // The first part disordered, the minimum is in first part
        if (nums[first] > nums[middle])
        {
            last = middle;
        }
        // The second part is disordered, the minimum is in the second part.
        else if (nums[middle] > nums[last])
        {
            first = middle + 1;
        }
        // The second part is in order, the minimum is in the first part.
        // regardless first part is in order or not.
        else if (nums[middle] < nums[last])
        {
            last = middle;
        }
        // We can not determine the second part is in order or not, discard last.
        else if (nums[middle] == nums[last])
        {
            last--;
        }
    }
    return nums[first];
}

/// <summary>
/// LeetCode #4 Median of Two Sorted Arrays
///
/// There are two sorted arrays nums1 and nums2 of size m and n respectively.
/// Find the median of the two sorted arrays.The overall run time complexity 
/// should be O(log(m + n)).
///
/// Example 1:
/// num1 = [1, 3]
/// nums2 = [2]
/// The median is 2.0
///
/// Example 2:
/// nums1 = [1, 2]
/// nums2 = [3, 4]
/// The median is (2 + 3)/2 = 2.5
/// </summary>
double LeetCodeBinarySearch::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    double value;
    // transfer the problem to find the kth item (middle point) in two arrays
    size_t size = nums1.size() + nums2.size();
    value = (double)findMedianSortedArrays(nums1, nums2, nums1.size(), nums2.size(), size / 2);
    value += (double)findMedianSortedArrays(nums1, nums2, nums1.size(), nums2.size(), (size - 1) / 2);
    return value / 2;
}

/// <summary>
/// LeetCode #4. Median of Two Sorted Arrays
/// </summary>
int LeetCodeBinarySearch::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, size_t s1, size_t s2, size_t k)
{
    if (s1 < s2) return findMedianSortedArrays(nums2, nums1, s2, s1, k);
    if (s2 == 0) return nums1[s1 - k - 1];

    if (k == 0)
    {
        if (nums1[s1 - 1] >= nums2[s2 - 1]) return nums1[s1 - 1];
        else return nums2[s2 - 1];
    }
    else
    {
        size_t n_k = 1;
        if (k > 1) n_k = k / 2;
        n_k = min(min(n_k, s1), s2);
        if (nums1[s1 - n_k] < nums2[s2 - n_k])
        {
            return findMedianSortedArrays(nums1, nums2, s1, s2 - n_k, k - n_k);
        }
        else
        {
            return findMedianSortedArrays(nums1, nums2, s1 - n_k, s2, k - n_k);
        }
    }
}

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
/// 1. 1 ?ü n ?ü 1000
/// 2. 1 ?ü m ?ü min(50, n)
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
int LeetCodeBinarySearch::splitArray(vector<int>& nums, int m)
{
    unsigned long long first = 0;
    unsigned long long last = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        last += (unsigned long long) nums[i];
        first = max(first, (unsigned long long)nums[i]);
    }
    // the maximum slice size must be between the maximum number and the total 
    // sum of the slice, try all possible by binary search.
    while (first < last)
    {
        // assume the mid is the sum of maximum slice
        unsigned long long mid = (first + last) / 2;

        int count = 1;
        unsigned long long subTotal = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (subTotal + nums[i] > mid)
            {
                count++;
                if (count > m)
                {
                    break;
                }
                else
                {
                    subTotal = 0;
                }
            }
            subTotal += nums[i];
        }
        // if count is greater than m, it means bursted
        if (count > m)
        {
            first = mid + 1;
        }
        else // if not bursted, find the smaller sum greedily
        {
            last = mid;
        }
    }
    return (int)last;
}

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
int LeetCodeBinarySearch::singleNonDuplicate(vector<int>& nums)
{
    int begin = 0, end = nums.size();
    while (begin < end - 1)
    {
        int mid = begin + (end - begin) / 2;
        if ((mid - begin) % 2 == 0) mid++;
        if ((mid < end) && (nums[mid] == nums[mid - 1]))
        {
            begin = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return nums[begin];
}

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
vector<int> LeetCodeBinarySearch::findClosestElements(vector<int>& arr, int k, int x)
{
    vector<int> result;

    vector<int>::iterator last = lower_bound(arr.begin(), arr.end(), x);
    vector<int>::iterator first = last;

    while (k > 0)
    {
        if (first == arr.begin())
        {
            last += k;
            k = 0;
        }
        else if (last == arr.end())
        {
            first -= k;
            k = 0;
        }
        else
        {
            first = first - 1;
            // if previous item has more gap, we move forward
            if (abs(*first - x) > abs(*last - x))
            {
                first++;
                last++;
            }
            k--;
        }
    }

    // copy the array to result
    result.assign(first, last);
    return result;
}

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
vector<int> LeetCodeBinarySearch::findClosestElementsII(vector<int>& arr, int k, int x)
{
    vector<int> result;

    vector<int>::iterator last = lower_bound(arr.begin(), arr.end(), x);
    vector<int>::iterator first = last;

    while (k > 0)
    {
        if (first == arr.begin())
        {
            last += k;
            k = 0;
        }
        else if (last == arr.end())
        {
            first -= k;
            k = 0;
        }
        else
        {
            int delta = 0;
            if (k == 1)
            {
                delta = 1;
                first--;
                // if previous item has more gap, we move forward
                if (abs(*first - x) > abs(*last - x))
                {
                    first++;
                    last++;
                }
            }
            else
            {
                delta = k / 2;
                int dis = abs(std::distance(first, arr.begin()));
                delta = min(dis, delta);
                dis = abs(std::distance(arr.end(), last));
                delta = min(dis, delta);
                first -= delta;
                last += delta;
                // if previous item has more gap, we move forward
                if (abs(*first - x) > abs(*last - x))
                {
                    first += delta;
                }
                else
                {
                    last -= delta;
                }
            }
            k -= delta;
        }
    }

    // copy the array to result
    result.assign(first, last);
    return result;
}

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
int LeetCodeBinarySearch::findKthNumber(int m, int n, int k)
{
    int first = 1, last = m * n;
    while (first < last)
    {
        int v = (first + last) / 2;
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            count += min(n, v / i);
        }
        if (count < k) first = v + 1;
        else last = v;
    }
    return first;
}

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
int LeetCodeBinarySearch::smallestDistancePair(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());
    // Minimum absolute difference
    int low = nums[1] - nums[0];
    for (int i = 1; i < (int)nums.size() - 1; i++)
    {
        low = min(low, nums[i + 1] - nums[i]);
    }
    int high = nums[nums.size() - 1] - nums[0];
    while (low < high)
    {
        int mid = (low + high) / 2;

        int count = 0;
        int first = 0;
        int last = 1;
        while (first < (int)nums.size())
        {
            while (last < (int)nums.size() && nums[last] - nums[first] <= mid)
            {
                last++;
            }
            count += last - first - 1;
            if (count > k) break;
            first++;
        }
        if (count >= k) high = mid;
        else low = mid + 1;
    }
    return low;
}

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
vector<int> LeetCodeBinarySearch::kthSmallestPrimeFraction(vector<int>& A, int K)
{
    double min_value = 0;
    double abs_min = (double)1 / (2 * (double)A[A.size() - 1] * (double)A[A.size() - 2]);
    double max_value = 1;
    vector<int> result(2);

    while (max_value - min_value >= abs_min)
    {
        double middle = (min_value + max_value) / 2;
        double current_max = 0;
        size_t first = 0;
        size_t last = 1;
        int count = 0;
        while (last < A.size())
        {
            if (first == last)
            {
                count += first;
                last++;
            }
            else
            {
                double current_value = (double)A[first] / A[last];
                if (current_value <= middle)
                {
                    if (current_value > current_max)
                    {
                        result[0] = A[first];
                        result[1] = A[last];
                        current_max = current_value;
                    }
                    first++;
                }
                else
                {
                    count += first;
                    last++;
                }
            }
        }

        if (count == K) break;
        else if (count > K) max_value = middle;
        else min_value = middle;
    }
    return result;
}


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
int LeetCodeBinarySearch::peakIndexInMountainArray(vector<int>& A)
{
    int first = 0;
    int last = A.size();
    while (first < last)
    {
        int middle = first + (last - first) / 2;
        if (middle > first)
        {
            if (A[middle] > A[middle - 1])
            {
                first = middle;
            }
            else
            {
                last = middle;
            }
        }
        else if ((middle + 1 < (int)A.size()) && (A[middle] < A[middle + 1]))
        {
            first = middle + 1;
        }
        else
        {
            last--;
        }
    }
    return first;
}

/// <summary>
/// Leet code #875. Koko Eating Bananas
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
int LeetCodeBinarySearch::minEatingSpeed(vector<int>& piles, int H)
{
    int first = 1;
    int last = 1;
    int result = 0;
    for (size_t i = 0; i < piles.size(); i++)
    {
        last = max(last, piles[i]);
    }
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        int count = 0;
        for (size_t i = 0; i < piles.size(); i++)
        {
            count += piles[i] / middle;
            if (piles[i] % middle != 0) count++;
            if (count > H) break;
        }
        if (count > H)
        {
            first = middle + 1;
        }
        else
        {
            result = middle;
            last = middle - 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::binarySearchI(vector<int>& nums, int target)
{
    int first = 0;
    int last = nums.size() - 1;
    int result = -1;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        if (nums[middle] < target)
        {
            first = middle + 1;
        }
        else if (nums[middle] > target)
        {
            last = middle - 1;
        }
        else
        {
            result = middle;
            break;
        }
    }
    return result;
}


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
int LeetCodeBinarySearch::searchStream(const vector<int>& reader, int target)
{
    int index = 0;
    int step = 1;
    while (true)
    {
        if (index >= (int)reader.size() || reader[index] > target)
        {
            if (step == 1) break;
            step = (step > 0) ? -1 : step * 2;
        }
        else if (index < 0 || reader[index] < target)
        {
            if (step == -1) break;
            step = (step < 0) ? 1 : step * 2;
        }
        else
        {
            return index;
        }
        index += step;
    }
    return -1;
}

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
int LeetCodeBinarySearch::shipWithinDays(vector<int>& weights, int D)
{
    int sum = 0;
    for (size_t i = 0; i < weights.size(); i++) sum += weights[i];
    int first = 1;
    int last = sum;
    int result = 0;
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        int d = 1;
        int sum = 0;
        for (size_t i = 0; i < weights.size(); i++)
        {
            if (sum + weights[i] > mid)
            {
                // a single cargo may bust
                if (sum == 0) d = D + 1;
                else
                {
                    sum = 0;
                    d++;
                }
            }
            if (d > D) break;
            sum += weights[i];
        }
        // ship too small
        if (d > D)
        {
            first = mid + 1;
        }
        else
        {
            result = mid;
            last = mid - 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::fixedPoint(vector<int>& A)
{
    int first = 0;
    int last = A.size();
    while (first < last)
    {
        int mid = first + (last - first) / 2;
        if (A[mid] < mid)
        {
            first = mid + 1;
        }
        else
        {
            last = mid;
        }
    }
    if (last == A.size() || A[last] != last) return -1;
    else return last;
}

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
int LeetCodeBinarySearch::missingElement(vector<int>& nums, int k)
{
    int first = 0;
    int last = nums.size() - 1;
    int pos = first;
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (nums[mid] - mid - nums[0] < k)
        {
            pos = mid;
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return k + pos + nums[0];
}

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
int LeetCodeBinarySearch::maximizeSweetness(vector<int>& sweetness, int K)
{
    int last = 0;
    for (size_t i = 0; i < sweetness.size(); i++)
    {
        last += sweetness[i];
    }
    int first = 0;
    int result = first;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        int index = 0;
        int sum = 0;
        for (int k = 0; k <= K; k++)
        {
            sum = 0;
            while (index < (int)sweetness.size() && sum < middle)
            {
                sum += sweetness[index];
                index++;
            }
            if (sum < middle) break;
        }
        if (sum < middle)
        {
            last = middle - 1;
        }
        else
        {
            result = middle;
            first = middle + 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::smallestDivisor(vector<int>& nums, int threshold)
{
    int first = 1;
    int last = 1000000;

    while (first < last)
    {
        int middle = first + (last - first) / 2;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i] / middle;
            if (nums[i] % middle != 0) sum++;
        }
        if (sum > threshold) first = middle + 1;
        else last = middle;
    }
    return first;
}

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
int LeetCodeBinarySearch::findBestValue(vector<int>& arr, int target)
{
    int first = 0;
    int last = 100000;
    int result = 0;
    int diff = 100000;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        int sum = 0;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i] > middle) sum += middle;
            else sum += arr[i];
        }
        if (abs(sum - target) < diff || (abs(sum - target) == diff) && (middle < result))
        {
            result = middle;
            diff = abs(sum - target);
        }
        if (sum < target)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::minDays(vector<int>& bloomDay, int m, int k)
{
    int first = 0;
    int last = 1000000000;
    int result = -1;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        int k_count = 0;
        int m_count = 0;
        for (size_t i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= middle)
            {
                k_count++;
            }
            else
            {
                k_count = 0;
            }
            if (k_count == k)
            {
                m_count++;
                k_count = 0;
            }
        }
        if (m_count >= m)
        {
            result = middle;
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::maxDistance(vector<int>& position, int m)
{
    std::sort(position.begin(), position.end());
    int first = 1;
    int last = position.back() - position[0];
    int result = last;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        int prev = position[0];
        int curr = 1;
        for (int j = 1; j < m; j++)
        {
            while (curr < (int)position.size() && position[curr] < prev + middle) curr++;
            if (curr == position.size()) break;
            prev = position[curr];
        }
        if (curr == position.size())
        {
            last = middle - 1;
        }
        else
        {
            result = middle;
            first = middle + 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::minimumSize(vector<int>& nums, int maxOperations)
{
    int first = 1;
    int last = INT_MIN;
    for (size_t i = 0; i < nums.size(); i++)
    {
        last = max(last, nums[i]);
    }
    int result = INT_MAX;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > middle) count += (nums[i] + middle - 1) / middle - 1;
        }
        if (count <= maxOperations)
        {
            result = min(result, middle);
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::maxValue(int n, int index, int maxSum)
{
    int first = 1;
    int last = maxSum;
    int result = 0;
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        int left = max((mid - index), 1);
        int right = max(mid - ((n - 1) - index), 1);
        int left_extra = max((index + 1 - mid), 0);
        int right_extra = max((n - index - mid), 0);
        long long sum = ((long long)left + (long long)mid) * ((long long)mid - (long long)left + 1) / 2;
        sum += ((long long)right + (long long)mid) * ((long long)mid - (long long)right + 1) / 2;
        sum -= mid;
        sum += (long long)left_extra + (long long)right_extra;
        if (sum > maxSum) last = mid - 1;
        else
        {
            result = max(result, mid);
            first = mid + 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::minSpeedOnTime(vector<int>& dist, double hour)
{
    int low = 1;
    int high = 10000000;
    int result = -1;
    while (low <= high)
    {
        int speed = low + (high - low) / 2;
        double time = 0;
        for (size_t i = 0; i < dist.size(); i++)
        {
            if (i == dist.size() - 1) time += (double)dist[i] / speed;
            else time += (dist[i] + speed - 1) / speed;
            if (time > hour) break;
        }
        if (time <= hour)
        {
            result = speed;
            high = speed - 1;
        }
        else
        {
            low = speed + 1;
        }
    }
    return result;
}

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
/// 4. sum(paths[i].length) <= 10^5
/// 5. 0 <= paths[i][j] < n
/// 6. The same city is not listed multiple times consecutively in 
///    paths[i].
/// </summary>
int LeetCodeBinarySearch::longestCommonSubpath(int n, vector<vector<int>>& paths)
{
    long long base = 100000;
    long long M = 1000000007;
    int first = 1;
    int last = paths[0].size();
    int result = 0;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        unordered_map<long long, vector<int>> hs;
        for (int i = 0; i < (int)paths.size(); i++)
        {
            long long hash = 0, d = 1;
            unordered_map<long long, vector<int>> hs1;
            for (int j = 0; j < (int)paths[i].size(); j++)
            {
                hash = (hash * base + paths[i][j]) % M;
                if (j >= mid)
                    hash = (M + hash - d * paths[i][j - mid] % M) % M;
                else
                    d = d * base % M;
                if (j >= mid - 1)
                {
                    if (i == 0)
                    {
                        hs1[hash].push_back(j - mid + 1);
                    }
                    else if (hs.count(hash) > 0)
                    {
                        for (auto pos : hs[hash])
                        {
                            if (equal(paths[0].begin() + pos, paths[0].begin() + pos + mid,
                                paths[i].begin() + j - (mid - 1)))
                            {
                                hs1[hash].push_back(pos);
                                break;
                            }
                        }
                    }
                }
            }
            hs = hs1;
            if (hs.empty()) break;
        }
        if (!hs.empty())
        {
            result = mid;
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::maximumRemovals(string s, string p, vector<int>& removable)
{
    int first = 0;
    int last = removable.size();
    unordered_map<int, int> removable_positions;
    for (size_t i = 0; i < removable.size(); i++)
    {
        removable_positions[removable[i]] = i;
    }
    int result = 0;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        size_t j = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (removable_positions.count(i) > 0 && removable_positions[i] < mid)
            {
                continue;
            }
            if (s[i] == p[j])
            {
                j++;
                if (j == p.size()) break;
            }
        }

        if (j == p.size())
        {
            result = mid;
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2040. Kth Smallest Product of Two Sorted Arrays
/// </summary>
long long LeetCodeBinarySearch::kthSmallestProductCount(vector<int>& nums1, vector<int>& nums2, long long value)
{
    long long cnt = 0;
    for (int p1 = 0, p2 = nums2.size() - 1; p1 < (int)nums1.size(); ++p1)
    {
        while (p2 >= 0 && (long long)nums1[p1] * nums2[p2] > value)
        {
            --p2;
        }
        cnt += (long long)p2 + 1;
    }
    return cnt;
}

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
long long LeetCodeBinarySearch::kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k)
{
    long long first = (long long)-100000 * (long long)100000;
    long long last = (long long)100000 * (long long)100000;

    auto itr1 = lower_bound(nums1.begin(), nums1.end(), 0);
    auto itr2 = lower_bound(nums2.begin(), nums2.end(), 0);
    vector<int> neg_num1(nums1.begin(), itr1);
    vector<int> neg_num2(nums2.begin(), itr2);
    vector<int> pos_num1(itr1, nums1.end());
    vector<int> pos_num2(itr2, nums2.end());
    vector<int> pos_rev1(pos_num1.rbegin(), pos_num1.rend());
    vector<int> pos_rev2(pos_num2.rbegin(), pos_num2.rend());
    vector<int> neg_rev1(neg_num1.rbegin(), neg_num1.rend());
    vector<int> neg_rev2(neg_num2.rbegin(), neg_num2.rend());
    long long result = 0;
    while (first <= last)
    {
        long long middle = first + (last - first) / 2;
        long long count = 0;
        if (middle < 0)
        {
            count = kthSmallestProductCount(neg_num1, pos_rev2, middle) +
                kthSmallestProductCount(neg_num2, pos_rev1, middle);
        }
        else
        {
            count = kthSmallestProductCount(pos_num1, pos_num2, middle) +
                kthSmallestProductCount(neg_rev1, neg_rev2, middle) +
                (long long)neg_num1.size() * (long long)pos_num2.size() +
                (long long)neg_num2.size() * (long long)pos_num1.size();
        }
        if (count >= k)
        {
            result = middle;
            last = middle - 1;
        }
        else if (count < k)
        {
            first = middle + 1;
        }
    }
    return result;
}

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
vector<int> LeetCodeBinarySearch::targetIndices(vector<int>& nums, int target)
{
    vector<int> result;
    sort(nums.begin(), nums.end());
    auto itr = lower_bound(nums.begin(), nums.end(), target);
    if (itr == nums.end() || *itr > target)
    {
        return result;
    }
    else
    {
        while (itr != nums.end() && *itr == target)
        {
            result.push_back(itr - nums.begin());
            itr++;
        }
    }
    return result;
}

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
int LeetCodeBinarySearch::maxLength(vector<int>& ribbons, int k)
{
    int last = 0;
    for (auto l : ribbons) last = max(last, l);
    int first = 1;
    int result = 0;

    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        int count = 0;
        for (size_t i = 0; i < ribbons.size(); i++)
        {
            count += ribbons[i] / middle;
        }
        if (count >= k)
        {
            result = middle;
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }
    return result;
}
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
int LeetCodeBinarySearch::kthSmallestSubarraySum(vector<int>& nums, int k)
{
    vector<int> dp(nums.size()+1);
    int last = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        dp[i+1] = last + nums[i];
        last += nums[i];
    }
    int first = 1;
    int result = 0;
    while (first <= last)
    {
        int middle = first + (last - first) / 2;
        int count = 0;
        for (size_t i = 1; i < dp.size(); i++)
        {
            auto itr = lower_bound(dp.begin(), dp.begin() + i, dp[i] - middle);
            count += dp.begin() + i - itr;
        }
        if (count >= k)
        {
            result = middle;
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return result;
}


#pragma endregion  
