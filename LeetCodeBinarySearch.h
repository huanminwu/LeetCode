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
#pragma endregion
};


/// <summary>
/// Leet code #1274. Number of Ships in a Rectangle
/// 
/// On the sea represented by a cartesian plane, each ship is located at 
/// an integer point, and each integer point may contain at most 1 ship.
///
/// You have a function Sea.hasShips(topRight, bottomLeft) which takes 
/// two points as arguments and returns true if and only if there is at 
/// least one ship in the rectangle represented by the two points, 
/// including on the boundary.
///
/// Given two points, which are the top right and bottom left corners of 
/// a rectangle, return the number of ships present in that rectangle.  
/// It is guaranteed that there are at most 10 ships in that rectangle.
///
/// Submissions making more than 400 calls to hasShips will be judged 
/// Wrong Answer.  Also, any solutions that attempt to circumvent the 
/// judge will result in disqualification.
/// 
/// 
/// Example :
/// 
/// Input: 
/// ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
/// Output: 3
/// Explanation: From [0,0] to [4,4] we can count 3 ships within the range.
///
/// Constraints:
/// 1. On the input ships is only given to initialize the map internally. 
/// 2. You must solve this problem "blindfolded". In other words, you must 
///    find the answer using the given hasShips API, without knowing the 
///	   ships position.
/// 3. 0 <= bottomLeft[0] <= topRight[0] <= 1000
/// 4. 0 <= bottomLeft[1] <= topRight[1] <= 1000
/// </summary>
class Sea
{
private:
    vector<vector<int>> m_ship;

    // Return true if there is ship within rectangle.
    bool hasShips(vector<int>& topRight, vector<int>& bottomLeft)
    {
        for (size_t i = 0; i < m_ship.size(); i++)
        {
            if (m_ship[i][0] >= bottomLeft[0] && m_ship[i][0] <= topRight[0] &&
                m_ship[i][1] >= bottomLeft[1] && m_ship[i][1] <= topRight[1])
            {
                return true;
            }
        }
        return false;
    };
public:
    // Constructure on ships.
    Sea(vector<vector<int>>& ship)
    {
        m_ship = ship;
    };

    // Return true if there is ship within rectangle.
    int countShips(vector<int>& topRight, vector<int>& bottomLeft)
    {
        int result = 0;
        queue<pair<vector<int>, vector<int>>> search;
        search.push(make_pair(topRight, bottomLeft));

        while (!search.empty())
        {
            vector<int> top_right = search.front().first;
            vector<int> bottom_left  = search.front().second;
            search.pop();

            if (!hasShips(top_right, bottom_left)) continue;

            if (top_right == bottom_left)
            {
                result++;
            }
            else
            {
                if (top_right[0] != bottom_left[0])
                {
                    vector<int> middle = { (bottom_left[0] + top_right[0]) / 2, top_right[1] };
                    search.push(make_pair(middle, bottom_left));
                    middle = { (bottom_left[0] + top_right[0]) / 2 + 1, bottom_left[1] };
                    search.push(make_pair(top_right, middle));
                }
                else
                {
                    vector<int> middle = { top_right[0], (bottom_left[1] + top_right[1]) / 2};
                    search.push(make_pair(middle, bottom_left));
                    middle = { bottom_left[0], (bottom_left[1] + top_right[1]) / 2 + 1 };
                    search.push(make_pair(top_right, middle));
                }
            }
        }
        return result;
    };

};

#endif  // LeetCodeBinarySearch_H
