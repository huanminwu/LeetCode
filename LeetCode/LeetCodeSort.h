#pragma once
#ifndef LeetCodeSort_H
#define LeetCodeSort_H
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
/// The class is to implement array related algorithm  
/// </summary>

/// <summary>
/// Leet code #295. Find Median from Data Stream
///  
/// Median is the middle value in an ordered integer list. If the size of 
/// the list is even, there is no middle value. So the median is the mean 
/// of the two middle value.
///
/// For example,
/// [2,3,4], the median is 3
///
/// [2,3], the median is (2 + 3) / 2 = 2.5
///
/// Design a data structure that supports the following two operations:
///
/// void addNum(int num) - Add a integer number from the data stream to 
/// the data structure.
/// double findMedian() - Return the median of all elements so far.
///
/// Example:
///
/// addNum(1)
/// addNum(2)
/// findMedian() -> 1.5
/// addNum(3) 
/// findMedian() -> 2
/// 
/// Follow up:
/// 
/// If all integer numbers from the stream are between 0 and 100, how 
/// would you optimize it?
/// If 99% of all integer numbers from the stream are between 0 and 
/// 100, how would you optimize it?
/// </summary>
class MedianFinder
{
private:
    priority_queue<int, vector<int>, greater<int>> m_Large;
    priority_queue<int> m_Small;
public:
    // Default constructor.
    MedianFinder()
    {
    }

    // Adds a number into the data structure.
    void addNum(int num)
    {
        if ((m_Small.size() == 0) || (m_Small.top() > num))
        {
            m_Small.push(num);
        }
        else
        {
            m_Large.push(num);
        }
        if (m_Small.size() > m_Large.size() + 1)
        {
            m_Large.push(m_Small.top());
            m_Small.pop();
        }
        if (m_Large.size() > m_Small.size())
        {
            m_Small.push(m_Large.top());
            m_Large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        double value;
        if (m_Small.size() == m_Large.size() + 1)
        {
            value = (double)m_Small.top();
        }
        else
        {
            value = ((double)m_Small.top() + (double)m_Large.top()) / 2;
        }
        return value;
    }
};

class LeetCodeSort
{
public:
#pragma region Sort

    /// <summary>
    /// Leet code #1213. Intersection of Three Sorted Arrays      
    ///
    /// Given three integer arrays arr1, arr2 and arr3 sorted in strictly 
    /// increasing order, return a sorted array of only the integers that 
    /// appeared in all three arrays.
    /// 
    /// Example 1:
    /// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
    /// Output: [1,5]
    /// Explanation: Only 1 and 5 appeared in the three arrays.
    /// 
    /// Constraints:
    /// 1. 1 <= arr1.length, arr2.length, arr3.length <= 1000
    /// 2. 1 <= arr1[i], arr2[i], arr3[i] <= 2000
    /// </summary>
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3);

    /// <summary>
    /// Leet code #373. Find K Pairs with Smallest Sums 
    ///
    /// Define a pair (u,v) which consists of one element from the first array 
    /// and one element from the second array. 
    /// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums. 
    ///
    /// Example 1:
    /// Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
    /// Return: [1,2],[1,4],[1,6]
    /// The first 3 pairs are returned from the sequence:
    /// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
    /// 
    /// Example 2:
    /// Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
    /// Return: [1,1],[1,1]
    /// The first 2 pairs are returned from the sequence: 
    /// [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
    /// 
    /// Example 3:
    /// Given nums1 = [1,2], nums2 = [3],  k = 3 
    /// Return: [1,3],[2,3]
    /// All possible pairs are returned from the sequence:
    /// [1,3],[2,3]
    /// </summary>
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);

    /// <summary>
    /// Leet code #683. K Empty Slots
    ///
    /// There is a garden with N slots. In each slot, there is a flower. The 
    /// N flowers will bloom one by one in N days. In each day, there will be 
    /// exactly one flower blooming and it will be in the status of blooming 
    /// since then.
    ///
    /// Given an array flowers consists of number from 1 to N. Each number in 
    /// the array represents the place where the flower will open in that day.
    ///
    /// For example, flowers[i] = x means that the unique flower that blooms 
    /// at day i will be at position x, where i and x will be in the range 
    /// from 1 to N.
    ///
    /// Also given an integer k, you need to output in which day there exists 
    /// two flowers in the status of blooming, and also the number of flowers 
    /// between them is k and these flowers are not blooming.
    /// 
    /// If there isn't such day, output -1.
    ///
    /// Example 1:
    /// Input: 
    /// flowers: [1,3,2]
    /// k: 1
    /// Output: 2
    /// Explanation: In the second day, the first and the third flower have 
    /// become blooming.
    ///
    /// Example 2:
    /// Input: 
    /// flowers: [1,2,3]
    /// k: 1
    /// Output: -1
    ///
    /// Note:
    /// The given array will be in the range [1, 20000].
    /// </summary>
    int kEmptySlots(vector<int>& flowers, int k);

    /// <summary>
    /// Leetcode #774. Minimize Max Distance to Gas Station
    ///
    /// On a horizontal number line, we have gas stations at positions 
    /// stations[0], stations[1], ..., stations[N-1], where 
    /// N = stations.length.
    /// 
    /// Now, we add K more gas stations so that D, the maximum distance 
    /// between adjacent gas stations, is minimized.
    /// 
    /// Return the smallest possible value of D.
    /// Example:
    /// Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
    /// Output: 0.500000
    /// Note:
    ///
    /// 1.stations.length will be an integer in range [10, 2000].
    /// 2. stations[i] will be an integer in range [0, 10^8].
    /// 3. K will be an integer in range [1, 10^6].
    /// 4. Answers within 10^-6 of the true value will be accepted as correct.
    /// </summary>
    double minmaxGasDist(vector<int>& stations, int K);

    /// <summary>
    /// Leet code #846. Hand of Straights
    /// 
    /// Alice has a hand of cards, given as an array of integers.
    ///
    /// Now she wants to rearrange the cards into groups so that each group 
    /// is size W, and consists of W consecutive cards.
    ///
    /// Return true if and only if she can.
    ///
    /// Example 1:
    /// Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
    /// Output: true
    /// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
    ///
    /// Example 2:
    /// Input: hand = [1,2,3,4,5], W = 4
    /// Output: false
    /// Explanation: Alice's hand can't be rearranged into groups of 4.
    /// 
    /// Note:
    /// 1. 1 <= hand.length <= 10000
    /// 2. 0 <= hand[i] <= 10^9
    /// 3. 1 <= W <= hand.length
    /// </summary>
    bool isNStraightHand(vector<int>& hand, int W);

    /// <summary>
    /// Leet code #857. Minimum Cost to Hire K Workers
    /// 
    /// There are N workers.  The i-th worker has a quality[i] and a minimum 
    /// wage expectation wage[i].
    ///
    /// Now we want to hire exactly K workers to form a paid group.  When hiring 
    /// a group of K workers, we must pay them according to the following rules:
    ///
    /// Every worker in the paid group should be paid in the ratio of their 
    /// quality compared to other workers in the paid group.
    /// Every worker in the paid group must be paid at least their minimum wage 
    /// expectation.
    /// Return the least amount of money needed to form a paid group satisfying 
    /// the above conditions.
    ///
    /// 
    /// Example 1:
    /// Input: quality = [10,20,5], wage = [70,50,30], K = 2
    /// Output: 105.00000
    /// Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
    ///
    /// Example 2:
    /// Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
    /// Output: 30.66667
    /// Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers 
    /// seperately. 
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= K <= N <= 10000, where N = quality.length = wage.length
    /// 2. 1 <= quality[i] <= 10000
    /// 3. 1 <= wage[i] <= 10000
    /// 4. Answers within 10^-5 of the correct answer will be considered correct.
    /// </summary>
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K);

    /// <summary>
    /// Leet code #300. Longest Increasing Subsequence
    ///  
    /// Given an unsorted array of integers, find the length of longest 
    /// increasing subsequence.
    ///
    /// Example:
    ///
    /// Input: [10,9,2,5,3,7,101,18]
    /// Output: 4 
    /// Explanation: The longest increasing subsequence is [2,3,7,101], 
    /// therefore the length is 4. 
    /// Note:
    ///
    /// There may be more than one LIS combination, it is only necessary for 
    /// you to return the length.
    /// Your algorithm should run in O(n2) complexity.
    /// Follow up: Could you improve it to O(n log n) time complexity?
    /// </summary>
    int lengthOfLIS(vector<int>& nums);

    /// <summary>
    /// Leet code #673. Number of Longest Increasing Subsequence
    ///
    /// Given an unsorted array of integers, find the number of longest 
    /// increasing subsequence.
    /// 
    /// Example 1:
    /// Input: [1,3,5,4,7]
    /// Output: 2
    /// Explanation: The two longest increasing subsequence are [1, 3, 4, 7] 
    /// and [1, 3, 5, 7].
    ///
    /// Example 2:
    /// Input: [2,2,2,2,2]
    /// Output: 5
    /// Explanation: The length of longest continuous increasing subsequence 
    /// is 1, and there are 5 subsequences' length is 1, so output 5.
    ///
    /// Note: Length of the given array will be not exceed 2000 and the answer 
    /// is guaranteed to be fit in 32-bit signed int.
    /// </summary>
    int findNumberOfLIS(vector<int>& nums);

    /// <summary>
    /// Leet code #354. Russian Doll Envelopes
    ///  
    /// You have a number of envelopes with widths and heights given as a 
    /// pair of integers (w, h). One envelope can fit into another if and 
    /// only if both the width and height of one envelope is greater than 
    /// the width and height of the other envelope.
    ///
    /// What is the maximum number of envelopes can you Russian doll?
    /// (put one inside other)
    ///
    /// Note:
    /// Rotation is not allowed.
    ///
    /// Example:
    ///
    /// Input: [[5,4],[6,4],[6,7],[2,3]]
    /// Output: 3 
    /// Explanation: The maximum number of envelopes you can Russian doll 
    /// is 3 ([2,3] => [5,4] => [6,7]).
    /// </summary>
    int maxEnvelopes(vector<pair<int, int>>& envelopes);

    /// <summary>
    /// Leet code #88. Merge Sorted Array 
    /// 
    /// Given two sorted integer arrays nums1 and nums2, merge nums2 into 
    /// nums1 as one sorted array.
    ///
    /// Note:
    ///
    /// The number of elements initialized in nums1 and nums2 are m and n 
    /// respectively.
    /// You may assume that nums1 has enough space (size that is greater 
    /// or equal to m + n) to hold additional elements from nums2.
    ///
    /// Example:
    /// Input:
    /// nums1 = [1,2,3,0,0,0], m = 3
    /// nums2 = [2,5,6],       n = 3
    ///
    /// Output: [1,2,2,3,5,6]
    /// </summary>
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// </summary>
    void mergeSortCountSmaller(vector<pair<int, int>>& nums, int begin, int end, vector<int>& result);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// 
    /// You are given an integer array nums and you have to return a new counts array. 
    /// The counts array has the property where counts[i] is the number of smaller 
    /// elements to the right of nums[i]. 
    ///
    /// Example:
    ///
    /// Given nums = [5, 2, 6, 1]
    /// To the right of 5 there are 2 smaller elements (2 and 1).
    /// To the right of 2 there is only 1 smaller element (1).
    /// To the right of 6 there is 1 smaller element (1).
    /// To the right of 1 there is 0 smaller element.
    /// Return the array [2, 1, 1, 0]. 
    /// </summary>
    vector<int> countSmaller(vector<int>& nums);

    /// <summary>
    /// Leet code #327. Count of Range Sum   
    /// </summary>
    int mergeCountRangeSum(vector<long long>& sums, int begin, int end, int lower, int upper);

    /// <summary>
    /// Leet code #327. Count of Range Sum   
    /// 
    /// Given an integer array nums, return the number of range sums that 
    /// lie in [lower, upper] inclusive.
    /// Range sum S(i, j) is defined as the sum of the elements in nums 
    /// between indices i and j (i ¡Ü j), inclusive.
    /// 
    /// Note:
    /// A naive algorithm of O(n^2) is trivial. You MUST do better than that. 
    /// Example:
    /// Given nums = [-2, 5, -1], lower = -2, upper = 2,
    /// Return 3.
    /// The three ranges are : [0, 0], [2, 2], [0, 2] and their respective 
    /// sums are: -2, -1, 2. 
    /// </summary>
    int countRangeSum(vector<int>& nums, int lower, int upper);

    /// <summary>
    /// Leet code #493. Reverse Pairs   
    /// </summary>
    int mergeSortReversePairs(vector<int>& nums, int begin, int end);

    /// <summary>
    /// Leet code #493. Reverse Pairs   
    /// 
    /// Given an array nums, we call (i, j) an important reverse pair if 
    /// i < j and nums[i] > 2*nums[j]. 
    /// You need to return the number of important reverse pairs in the given array. 
    /// 
    /// Example1: 
    /// Input: [1,3,2,3,1]
    /// Output: 2
    ///
    /// Example2: 
    /// Input: [2,4,3,5,1]
    /// Output: 3
    ///
    /// Note:
    /// 1.The length of the given array will not exceed 50,000.
    /// 2.All the numbers in the input array are in the range of 32-bit integer.
    /// </summary>
    int reversePairs(vector<int>& nums);

    /// <summary>
    /// Leet code #632. Smallest Range 
    /// 
    /// You have k lists of sorted integers in ascending order. Find the 
    /// smallest range that includes at least one number from each of the 
    /// k lists. 
    /// We define the range [a,b] is smaller than range [c,d] if b-a < 
    /// d-c or a < c if b-a == d-c.
    /// Example 1:
    /// Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
    /// Output: [20,24]
    /// Explanation: 
    /// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    /// List 2: [0, 9, 12, 20], 20 is in range [20,24].
    /// List 3: [5, 18, 22, 30], 22 is in range [20,24].
    ///
    /// Note:
    /// The given list may contain duplicates, so ascending order means 
    /// >= here.
    /// 1 <= k <= 3500
    /// -10^5 <= value of elements <= 10^5.
    /// For Java users, please note that the input type has been changed to 
    /// List<List<Integer>>. And after you reset the code template, you'll see 
    /// this point.
    /// </summary>
    vector<int> smallestRange(vector<vector<int>>& nums);

    /// <summary>
    /// Leet code #973. K Closest Points to Origin
    /// 
    /// We have a list of points on the plane.  Find the K closest points to the 
    /// origin (0, 0).
    ///
    /// (Here, the distance between two points on a plane is the Euclidean 
    /// distance.)
    ///
    /// You may return the answer in any order.  The answer is guaranteed to be 
    /// unique (except for the order that it is in.)
    ///
    /// Example 1:
    ///
    /// Input: points = [[1,3],[-2,2]], K = 1
    /// Output: [[-2,2]]
    /// Explanation: 
    /// The distance between (1, 3) and the origin is sqrt(10).
    /// The distance between (-2, 2) and the origin is sqrt(8).
    /// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    /// We only want the closest K = 1 points from the origin, so the answer is 
    /// just [[-2,2]].
    ///
    /// Example 2:
    /// 
    /// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
    /// Output: [[3,3],[-2,4]]
    /// (The answer [[-2,4],[3,3]] would also be accepted.)
    /// 
    /// Note:
    /// 
    /// 1. 1 <= K <= points.length <= 10000
    /// 2. -10000 < points[i][0] < 10000
    /// 3. -10000 < points[i][1] < 10000
    /// </summary>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K);

    /// <summary>
    /// Leet code #414. Third Maximum Number 
    ///
    /// Given a non-empty array of integers, return the third maximum number 
    /// in this array. If it does not exist, 
    /// return the maximum number. The time complexity must be in O(n).
    /// Example 1:
    /// Input: [3, 2, 1]
    /// Output: 1
    /// Explanation: The third maximum is 1.
    /// 
    /// Example 2:
    /// Input: [1, 2]
    /// Output: 2
    /// Explanation: The third maximum does not exist, so the maximum (2) is 
    /// returned instead.
    ///
    /// Example 3:
    /// Input: [2, 2, 3, 1]
    /// Output: 1
    /// Explanation: Note that the third maximum here means the third 
    /// maximum distinct number.
    /// Both numbers with value 2 are both considered as second maximum.
    /// </summary>
    int thirdMax(vector<int>& nums);

    /// <summary>
    /// Leet code #215. Kth Largest Element in an Array
    ///
    /// Find the kth largest element in an unsorted array. Note that it 
    /// is the kth largest element 
    /// in the sorted order, not the kth distinct element.  
    /// For example,
    /// Given [3,2,1,5,6,4] and k = 2, return 5. 
    /// </summary>
    int findKthLargest(vector<int>& nums, int k);

#pragma endregion
};
#endif  // LeetCodeSort_H
