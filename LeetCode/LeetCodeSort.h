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
    set<pair<int, int>> m_small, m_large;
    long long m_small_sum, m_large_sum;
private:
    void adjust()
    {
        if (m_small.size() > m_large.size() + 1)
        {
            m_large_sum += m_small.rbegin()->first;
            m_small_sum -= m_small.rbegin()->first;
            m_large.insert(*m_small.rbegin());
            m_small.erase(*m_small.rbegin());
        }
        if (m_large.size() > m_small.size())
        {
            m_small_sum += m_large.begin()->first;
            m_large_sum -= m_large.begin()->first;
            m_small.insert(*m_large.begin());
            m_large.erase(*m_large.begin());
        }
    }
public:
    // Default constructor.
    MedianFinder()
    {
        m_small_sum = 0;
        m_large_sum = 0;
    }

    // Adds a number into the data structure.
    void addNum(int num, int i = 0)
    {
        if ((m_small.empty()) || (m_small.rbegin()->first > num))
        {
            m_small.insert(make_pair(num, i));
            m_small_sum += num;
        }
        else
        {
            m_large.insert(make_pair(num, i));
            m_large_sum += num;
        }
        adjust();
    }

    void eraseNum(int num, int i = 0)
    {
        pair<int, int> p = make_pair(num, i);
        if (m_small.find(p) != m_small.end())
        {
            m_small.erase(p);
            m_small_sum -= p.first;
        }
        else
        {
            m_large.erase(p);
            m_large_sum -= p.first;
        }
        adjust();
    }

    // Returns the median of current data stream
    double findMedian()
    {
        double value;
        if (m_small.size() == m_large.size() + 1)
        {
            value = (double)m_small.rbegin()->first;
        }
        else
        {
            value = ((double)m_small.rbegin()->first + (double)m_large.begin()->first) / 2;
        }
        return value;
    }

    // Returns the median of current data stream
    long long get_distance()
    {
        long long result = (long long)(m_small.rbegin()->first) * m_small.size() - m_small_sum;
        result += m_large_sum - (long long)(m_small.rbegin()->first) * m_large.size();
        return result;
    }
};

class LeetCodeSort
{
public:
#pragma region Sort

    /// <summary>
    /// Leet code #456. 132 Pattern
    /// 
    /// Medium
    /// 
    /// Given an array of n integers nums, a 132 pattern is a subsequence of 
    /// three integers nums[i], nums[j] and nums[k] such that i < j < k and 
    /// nums[i] < nums[k] < nums[j].
    ///
    /// Return true if there is a 132 pattern in nums, otherwise, return false.
    ///
    /// Example 1:
    /// Input: nums = [1, 2, 3, 4]
    /// Output : false
    /// Explanation : There is no 132 pattern in the sequence.
    ///
    /// Example 2 :
    /// Input : nums = [3, 1, 4, 2]
    /// Output : true
    /// Explanation : There is a 132 pattern in the sequence : [1, 4, 2] .
    ///
    /// Example 3 :
    /// Input : nums = [-1, 3, 2, 0]
    /// Output : true
    /// Explanation : There are three 132 patterns in the sequence : 
    /// [-1, 3, 2] , [-1, 3, 0] and [-1, 2, 0].
    /// 
    /// Constraints :
    /// 1. n == nums.length
    /// 2. 1 <= n <= 2 * 10^5
    /// 3. - 10^9 <= nums[i] <= 10^9
    /// </summary>
    bool find132pattern(vector<int>& nums);

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
    /// between indices i and j (i < j), inclusive.
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

    /// <summary>
    /// Leet code #1331. Rank Transform of an Array 
    /// 
    /// Easy
    ///
    /// Given an array of integers arr, replace each element with its rank.
    ///
    /// The rank represents how large the element is. The rank has the 
    /// following rules:
    ///
    /// Rank is an integer starting from 1.
    /// The larger the element, the larger the rank. If two elements are 
    /// equal, their rank must be the same.
    /// Rank should be as small as possible.
    ///
    /// Example 1:
    /// Input: arr = [40,10,20,30]
    /// Output: [4,1,2,3]
    /// Explanation: 40 is the largest element. 10 is the smallest. 20 is 
    /// the second smallest. 30 is the third smallest.
    ///
    /// Example 2:
    /// Input: arr = [100,100,100]
    /// Output: [1,1,1]
    /// Explanation: Same elements share the same rank.
    ///
    /// Example 3:
    /// Input: arr = [37,12,28,9,100,56,80,5,12]
    /// Output: [5,3,4,2,8,6,7,1,3]
    ///
    /// 
    /// Constraints:
    /// 1. 0 <= arr.length <= 10^5
    /// 2. -10^9 <= arr[i] <= 10^9
    /// </summary>
    vector<int> arrayRankTransform(vector<int>& arr);

    /// <summary>
    /// Leet code #1196. How Many Apples Can You Put into the Basket
    /// 
    /// You have some apples, where arr[i] is the weight of the i-th apple.  
    /// You also have a basket that can carry up to 5000 units of weight.
    ///
    /// Return the maximum number of apples you can put in the basket.
    /// 
    /// Example 1:
    ///
    /// Input: arr = [100,200,150,1000]
    /// Output: 4
    /// Explanation: All 4 apples can be carried by the basket since their 
    /// sum of weights is 1450.
    ///
    /// Example 2:
    ///
    /// Input: arr = [900,950,800,1000,700,800]
    /// Output: 5
    /// Explanation: The sum of weights of the 6 apples exceeds 5000 so we 
    /// choose any 5 of them.
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^3
    /// 2. 1 <= arr[i] <= 10^3
    /// </summary>
    int maxNumberOfApples(vector<int>& arr);

    /// <summary>
    /// Leet code #1365. How Many Numbers Are Smaller Than the Current Number
    ///
    /// Easy
    ///
    /// Given the array nums, for each nums[i] find out how many numbers 
    /// in the array are smaller than it. That is, for each nums[i] you have 
    /// to count the number of valid j's such that j != i and nums[j] < 
    /// nums[i].
    ///
    /// Return the answer in an array.
    /// 
    /// Example 1:
    /// Input: nums = [8,1,2,2,3]
    /// Output: [4,0,1,1,3]
    /// Explanation: 
    /// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
    /// For nums[1]=1 does not exist any smaller number than it.
    /// For nums[2]=2 there exist one smaller number than it (1). 
    /// For nums[3]=2 there exist one smaller number than it (1). 
    /// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
    ///
    /// Example 2:
    /// Input: nums = [6,5,4,8]
    /// Output: [2,1,0,3]
    ///
    /// Example 3:
    /// Input: nums = [7,7,7,7]
    /// Output: [0,0,0,0]
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 500
    /// 2. 0 <= nums[i] <= 100
    /// </summary>
    vector<int> smallerNumbersThanCurrent(vector<int>& nums);

    /// <summary>
    /// Leet code #1366. Rank Teams by Votes
    ///
    /// Medium
    ///
    /// In a special ranking system, each voter gives a rank from highest 
    /// to lowest to all teams participated in the competition.
    ///
    /// The ordering of teams is decided by who received the most position-one
    /// votes. If two or more teams tie in the first position, we consider 
    /// the second position to resolve the conflict, if they tie again, we 
    /// continue this process until the ties are resolved. If two or more 
    /// teams are still tied after considering all positions, we rank them 
    /// alphabetically based on their team letter.
    ///
    /// Given an array of strings votes which is the votes of all voters in 
    /// the ranking systems. Sort all teams according to the ranking system 
    /// described above.
    ///
    /// Return a string of all teams sorted by the ranking system.
    /// 
    /// Example 1:
    /// Input: votes = ["ABC","ACB","ABC","ACB","ACB"]
    /// Output: "ACB"
    /// Explanation: Team A was ranked first place by 5 voters. No other 
    /// team was voted as first place so team A is the first team.
    /// Team B was ranked second by 2 voters and was ranked third by 3 voters.
    /// Team C was ranked second by 3 voters and was ranked third by 2 voters.
    /// As most of the voters ranked C second, team C is the second team and 
    /// team B is the third.
    ///
    /// Example 2: 
    /// Input: votes = ["WXYZ","XYZW"]
    /// Output: "XWYZ"
    /// Explanation: X is the winner due to tie-breaking rule. X has same votes
    /// as W for the first position but X has one vote as second position while 
    /// W doesn't have any votes as second position. 
    ///
    /// Example 3:
    /// Input: votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
    /// Output: "ZMNAGUEDSJYLBOPHRQICWFXTVK"
    /// Explanation: Only one voter so his votes are used for the ranking.
    ///
    /// Example 4:
    /// Input: votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]
    /// Output: "ABC"
    /// Explanation: 
    /// Team A was ranked first by 2 voters, second by 2 voters and third 
    /// by 2 voters.
    /// Team B was ranked first by 2 voters, second by 2 voters and third 
    /// by 2 voters.
    /// Team C was ranked first by 2 voters, second by 2 voters and third 
    /// by 2 voters.
    /// There is a tie and we rank teams ascending by their IDs.
    ///
    /// Example 5:
    /// Input: votes = ["M","M","M","M"]
    /// Output: "M"
    /// Explanation: Only team M in the competition so it has the first rank.
    ///
    /// Constraints:
    /// 1. 1 <= votes.length <= 1000
    /// 2. 1 <= votes[i].length <= 26
    /// 3. votes[i].length == votes[j].length for 0 <= i, j < votes.length.
    /// 4. votes[i][j] is an English upper-case letter.
    /// 5. All characters of votes[i] are unique.
    /// 6. All the characters that occur in votes[0] also occur in votes[j] 
    ///    where 1 <= j < votes.length.
    /// </summary>
    string rankTeams(vector<string>& votes);

    /// <summary>
    /// Leet code #1387. Sort Integers by The Power Value
    /// 
    /// Medium
    ///
    /// The power of an integer x is defined as the number of steps needed 
    /// to transform x into 1 using the following steps:
    ///
    /// if x is even then x = x / 2
    /// if x is odd then x = 3 * x + 1
    /// For example, the power of x = 3 is 7 because 3 needs 7 steps to 
    /// become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
    ///
    /// Given three integers lo, hi and k. The task is to sort all integers 
    /// in the interval [lo, hi] by the power value in ascending order, if 
    /// two or more integers have the same power value sort them by ascending 
    /// order.
    ///
    /// Return the k-th integer in the range [lo, hi] sorted by the power 
    /// value.
    ///
    /// Notice that for any integer x (lo <= x <= hi) it is guaranteed that x 
    /// will transform into 1 using these steps and that the power of x is 
    /// will fit in 32 bit signed integer.
    ///
    /// Example 1:
    /// Input: lo = 12, hi = 15, k = 2
    /// Output: 13
    /// Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 
    /// 16 --> 8 --> 4 --> 2 --> 1)
    /// The power of 13 is 9 
    /// The power of 14 is 17
    /// The power of 15 is 17
    /// The interval sorted by the power value [12,13,14,15]. For k = 2 answer 
    /// is the second element which is 13.
    /// Notice that 12 and 13 have the same power value and we sorted them in 
    /// ascending order. Same for 14 and 15.
    ///
    /// Example 2:
    /// Input: lo = 1, hi = 1, k = 1
    /// Output: 1
    ///
    /// Example 3:
    /// Input: lo = 7, hi = 11, k = 4
    /// Output: 7
    /// Explanation: The power array corresponding to the 
    /// interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
    /// The interval sorted by power is [8, 10, 11, 7, 9].
    /// The fourth number in the sorted array is 7.
    ///
    /// Example 4:
    ///
    /// Input: lo = 10, hi = 20, k = 5
    /// Output: 13
    ///
    /// Example 5:
    /// Input: lo = 1, hi = 1000, k = 777
    /// Output: 570
    ///
    /// Constraints:
    /// 1. 1 <= lo <= hi <= 1000
    /// 2. 1 <= k <= hi - lo + 1
    /// </summary>
    int getKth(int lo, int hi, int k);

    /// <summary>
    /// Leet code #1385. Find the Distance Value Between Two Arrays
    /// 
    /// Easy
    ///
    /// Given two integer arrays arr1 and arr2, and the integer d, return 
    /// the distance value between the two arrays.
    ///
    /// The distance value is defined as the number of elements arr1[i] such 
    /// that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
    ///
    /// Example 1:
    /// Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
    /// Output: 2
    /// Explanation: 
    /// For arr1[0]=4 we have: 
    /// |4-10|=6 > d=2 
    /// |4-9|=5 > d=2 
    /// |4-1|=3 > d=2 
    /// |4-8|=4 > d=2 
    /// For arr1[1]=5 we have: 
    /// |5-10|=5 > d=2 
    /// |5-9|=4 > d=2 
    /// |5-1|=4 > d=2 
    /// |5-8|=3 > d=2
    /// For arr1[2]=8 we have:
    /// |8-10|=2 <= d=2
    /// |8-9|=1 <= d=2
    /// |8-1|=7 > d=2
    /// |8-8|=0 <= d=2
    ///
    /// Example 2:
    /// Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
    /// Output: 2
    ///
    /// Example 3:
    /// Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
    /// Output: 1
    /// 
    /// Constraints:
    /// 1. 1 <= arr1.length, arr2.length <= 500
    /// 2. -10^3 <= arr1[i], arr2[j] <= 10^3
    /// 3. 0 <= d <= 100
    /// </summary>
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d);

    /// <summary>
    /// Leet code #1402. Reducing Dishes
    /// 
    /// Hard
    ///
    /// A chef has collected data on the satisfaction level of his n dishes. 
    /// Chef can cook any dish in 1 unit of time.
    ///
    /// Like-time coefficient of a dish is defined as the time taken to cook 
    /// that dish including previous dishes multiplied by its satisfaction 
    /// level  i.e.  time[i]*satisfaction[i]
    ///
    /// Return the maximum sum of Like-time coefficient that the chef can 
    /// obtain after dishes preparation.
    ///
    /// Dishes can be prepared in any order and the chef can discard some 
    /// dishes to get this maximum value.
    /// 
    /// Example 1:
    /// Input: satisfaction = [-1,-8,0,5,-9]
    /// Output: 14
    /// Explanation: After Removing the second and last dish, the maximum 
    /// total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). 
    /// Each dish is prepared in one unit of time.
    ///
    /// Example 2:
    /// Input: satisfaction = [4,3,2]
    /// Output: 20
    /// Explanation: Dishes can be prepared in any order, 
    /// (2*1 + 3*2 + 4*3 = 20)
    ///
    /// Example 3:
    /// Input: satisfaction = [-1,-4,-5]
    /// Output: 0
    /// Explanation: People don't like the dishes. No dish is prepared.
    ///
    /// Example 4:
    /// Input: satisfaction = [-2,5,-1,0,3,-3]
    /// Output: 35
    ///
    /// Constraints:
    /// 1. n == satisfaction.length
    /// 2. 1 <= n <= 500
    /// 3. -10^3 <= satisfaction[i] <= 10^3
    /// </summary>
    int maxSatisfaction(vector<int>& satisfaction);

    /// <summary>
    /// Leet code #1403. Minimum Subsequence in Non-Increasing Order
    /// 
    /// Easy
    ///
    /// Given the array nums, obtain a subsequence of the array whose sum 
    /// of elements is strictly greater than the sum of the non included 
    /// elements in such subsequence. 
    /// 
    /// If there are multiple solutions, return the subsequence with minimum 
    /// size and if there still exist multiple solutions, return the 
    /// subsequence with the maximum total sum of all its elements. A 
    /// subsequence of an array can be obtained by erasing some 
    /// (possibly zero) elements from the array. 
    ///
    /// Note that the solution with the given constraints is guaranteed to 
    /// be unique. Also return the answer sorted in non-increasing order.
    /// 
    /// Example 1:
    /// Input: nums = [4,3,10,9,8]
    /// Output: [10,9] 
    /// Explanation: The subsequences [10,9] and [10,8] are minimal such 
    /// that the sum of their elements is strictly greater than the sum of 
    /// elements not included, however, the subsequence [10,9] has the 
    /// maximum total sum of its elements. 
    ///
    /// Example 2:
    /// Input: nums = [4,4,7,6,7]
    /// Output: [7,7,6] 
    /// Explanation: The subsequence [7,7] has the sum of its elements 
    /// equal to 14 which is not strictly greater than the sum of 
    /// elements not included (14 = 4 + 4 + 6). Therefore, the 
    /// subsequence [7,6,7] is the minimal satisfying the conditions. 
    /// Note the subsequence has to returned in non-decreasing order.  
    ///
    /// Example 3:
    /// Input: nums = [6]
    /// Output: [6]
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 500
    /// 2. 1 <= nums[i] <= 100
    /// </summary>
    vector<int> minSubsequence(vector<int>& nums);

    /// <summary>
    /// Leet code #1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
    /// 
    /// Hard
    ///
    /// You are given an m * n matrix, mat, and an integer k, which has its rows 
    /// sorted in non-decreasing order.
    ///
    /// You are allowed to choose exactly 1 element from each row to form an 
    /// array. Return the Kth smallest array sum among all possible arrays.
    ///
    /// Example 1:
    /// Input: mat = [[1,3,11],[2,4,6]], k = 5
    /// Output: 7
    /// Explanation: Choosing one element from each row, the first k smallest 
    /// sum are:
    /// [1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  
    ///
    /// Example 2:
    /// Input: mat = [[1,3,11],[2,4,6]], k = 9
    /// Output: 17
    ///
    /// Example 3:
    /// Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
    /// Output: 9
    /// Explanation: Choosing one element from each row, the first k smallest 
    /// sum are:
    /// [1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. 
    /// Where the 7th sum is 9.  
    ///
    /// Example 4:
    /// Input: mat = [[1,1,10],[2,2,9]], k = 7
    /// Output: 12
    ///
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat.length[i]
    /// 3. 1 <= m, n <= 40
    /// 4. 1 <= k <= min(200, n ^ m)
    /// 5. 1 <= mat[i][j] <= 5000
    /// 6. mat[i] is a non decreasing array.
    /// </summary>
    int kthSmallest(vector<vector<int>>& mat, int k);

    /// <summary>
    /// Leet code #674. Longest Continuous Increasing Subsequence 
    /// 
    /// Given an unsorted array of integers, find the length of longest 
    /// continuous increasing subsequence.
    ///
    /// Example 1:
    /// Input: [1,3,5,4,7]
    /// Output: 3
    /// Explanation: The longest continuous increasing subsequence is [1,3,5], 
    /// its length is 3. 
    /// Even though [1,3,5,7] is also an increasing subsequence, it's not a 
    /// continuous one where 5 and 7 are separated by 4. 
    ///
    /// Example 2:
    /// Input: [2,2,2,2,2]
    /// Output: 1
    /// Explanation: The longest continuous increasing subsequence is [2], 
    /// its length is 1.
    ///	
    /// Note: Length of the array will not exceed 10,000.
    /// </summary>
    int findLengthOfLCIS(vector<int>& nums);

    /// <summary>
    /// Leet code #1499. Max Value of Equation
    /// 
    /// Hard
    ///
    /// Given an array points containing the coordinates of points on a 2D 
    /// plane, sorted by the x-values, where points[i] = [xi, yi] such that 
    /// xi < xj for all 1 <= i < j <= points.length. You are also given an 
    /// integer k.
    ///
    /// Find the maximum value of the equation yi + yj + |xi - xj| 
    /// where |xi - xj| <= k and 1 <= i < j <= points.length. It is guaranteed 
    /// that there exists at least one pair of points that satisfy the 
    /// constraint |xi - xj| <= k.
    ///
    /// Example 1:
    /// Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
    /// Output: 4
    /// Explanation: The first two points satisfy the condition |xi - xj| <= 1 
    /// and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and 
    /// fourth points also satisfy the condition and give a value of 10 + -10 + 
    /// |5 - 6| = 1.
    /// No other pairs satisfy the condition, so we return the max of 4 and 1.
    ///
    /// Example 2: 
    /// Input: points = [[0,0],[3,0],[9,2]], k = 3
    /// Output: 3
    /// Explanation: Only the first two points have an absolute difference of 3 
    /// or less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
    ///
    /// Constraints:
    /// 1. 2 <= points.length <= 10^5
    /// 2. points[i].length == 2
    /// 3. -10^8 <= points[i][0], points[i][1] <= 10^8
    /// 4. 0 <= k <= 2 * 10^8
    /// 5. points[i][0] < points[j][0] for all 1 <= i < j <= points.length
    /// 6. xi form a strictly increasing sequence.
    /// </summary>
    int findMaxValueOfEquation(vector<vector<int>>& points, int k);

    /// <summary>
    /// Leet code #1505. Minimum Possible Integer After at Most K Adjacent 
    ///                  Swaps On Digits
    /// Hard
    ///
    /// Given a string num representing the digits of a very large integer 
    /// and an integer k.
    ///
    /// You are allowed to swap any two adjacent digits of the integer at 
    /// most k times.
    ///
    /// Return the minimum integer you can obtain also as a string.
    ///
    /// Example 1:
    /// Input: num = "4321", k = 4
    /// Output: "1342"
    /// Explanation: The steps to obtain the minimum integer from 4321 
    /// with 4 adjacent swaps are shown.
    ///
    /// Example 2:
    /// Input: num = "100", k = 1
    /// Output: "010"
    /// Explanation: It's ok for the output to have leading zeros, but 
    /// the input is guaranteed not to have any leading zeros.
    ///
    /// Example 3:
    /// Input: num = "36789", k = 1000
    /// Output: "36789"
    /// Explanation: We can keep the number without any swaps.
    ///
    /// Example 4:
    /// Input: num = "22", k = 22
    /// Output: "22"
    ///
    /// Example 5:
    /// Input: num = "9438957234785635408", k = 23
    /// Output: "0345989723478563548"
    /// Constraints:
    /// 1. 1 <= num.length <= 30000
    /// 2. num contains digits only and doesn't have leading zeros.
    /// 3. 1 <= k <= 10^9
    /// </summary>
    string minInteger(string num, int k);

    /// <summary>
    /// Leet code #1509. Minimum Difference Between Largest and Smallest Value 
    ///                  in Three Moves
    ///
    /// Medium
    ///	
    /// Given an array nums, you are allowed to choose one element of nums and 
    /// change it by any value in one move.
    ///
    /// Return the minimum difference between the largest and smallest value 
    /// of nums after perfoming at most 3 moves.
    ///
    /// Example 1:
    /// Input: nums = [5,3,2,4]
    /// Output: 0
    /// Explanation: Change the array [5,3,2,4] to [2,2,2,2].
    /// The difference between the maximum and minimum is 2-2 = 0.
    ///
    /// Example 2:
    /// Input: nums = [1,5,0,10,14]
    /// Output: 1
    /// Explanation: Change the array [1,5,0,10,14] to [1,1,0,1,1]. 
    /// The difference between the maximum and minimum is 1-0 = 1.
    ///
    /// Example 3:
    /// Input: nums = [6,6,0,1,1,4,6]
    /// Output: 2
    ///
    /// Example 4:
    /// Input: nums = [1,5,6,14,15]
    /// Output: 1
    /// 1. Constraints:
    /// 2. 1 <= nums.length <= 10^5
    /// 3. -10^9 <= nums[i] <= 10^9
    /// </summary>
    int minDifference(vector<int>& nums);

    /// <summary>
    /// Leet code #1535. Find the Winner of an Array Game
    /// 
    /// Medium
    ///
    /// Given an integer array arr of distinct integers and an integer k.
    ///
    /// A game will be played between the first two elements of the array 
    /// (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] 
    /// with arr[1], the larger integer wins and remains at position 0 and the 
    /// smaller integer moves to the end of the array. The game ends when an 
    /// integer wins k consecutive rounds.
    ///
    /// Return the integer which will win the game.
    ///
    /// It is guaranteed that there will be a winner of the game.
    /// 
    /// Example 1:
    /// Input: arr = [2,1,3,5,4,6,7], k = 2
    /// Output: 5
    /// Explanation: Let's see the rounds of the game:
    /// Round |       arr       | winner | win_count
    ///   1   | [2,1,3,5,4,6,7] | 2      | 1
    ///   2   | [2,3,5,4,6,7,1] | 3      | 1
    ///   3   | [3,5,4,6,7,1,2] | 5      | 1
    ///   4   | [5,4,6,7,1,2,3] | 5      | 2
    /// So we can see that 4 rounds will be played and 5 is the winner because 
    /// it wins 2 consecutive games.
    ///
    /// Example 2:
    /// Input: arr = [3,2,1], k = 10
    /// Output: 3
    /// Explanation: 3 will win the first 10 rounds consecutively.
    ///
    /// Example 3:
    /// Input: arr = [1,9,8,2,3,7,6,4,5], k = 7
    /// Output: 9
    ///
    /// Example 4:
    /// Input: arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
    /// Output: 99
    ///
    /// Constraints:
    /// 1. 2 <= arr.length <= 10^5
    /// 2. 1 <= arr[i] <= 10^6
    /// 3. arr contains distinct integers.
    /// 4. 1 <= k <= 10^9
    /// </summary>
    int getWinner(vector<int>& arr, int k);

    /// <summary>
    /// Leet code #1536. Minimum Swaps to Arrange a Binary Grid
    /// 
    /// Medium
    ///
    /// Given an n x n binary grid, in one step you can choose two adjacent rows 
    /// of the grid and swap them.
    ///
    /// A grid is said to be valid if all the cells above the main diagonal are 
    /// zeros.
    ///
    /// Return the minimum number of steps needed to make the grid valid, or -1 
    /// if the grid cannot be valid.
    ///
    /// The main diagonal of a grid is the diagonal that starts at cell (1, 1) 
    /// and ends at cell (n, n).
    ///
    /// Example 1:
    /// Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
    /// Output: 3
    ///
    /// Example 2:
    /// Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
    /// Output: -1
    /// Explanation: All rows are similar, swaps have no effect on the grid.
    ///
    /// Example 3:
    /// Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. n == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= n <= 200
    /// 4. grid[i][j] is 0 or 1
    /// </summary>
    int minSwaps(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1585. Check If String Is Transformable With Substring Sort 
    ///                  Operations
    /// 
    /// Hard
    ///
    /// Given two strings s and t, you want to transform string s into 
    /// string t using the following operation any number of times:
    ///
    /// Choose a non-empty substring in s and sort it in-place so the 
    /// characters are in ascending order.
    /// For example, applying the operation on the underlined substring 
    /// in "14234" results in "12344".
    ///
    /// Return true if it is possible to transform string s into string t. 
    /// Otherwise, return false.
    ///
    /// A substring is a contiguous sequence of characters within a string.
    /// 
    /// Example 1:
    /// Input: s = "84532", t = "34852"
    /// Output: true
    /// Explanation: You can transform s into t using the following sort 
    /// operations:
    /// "84532" (from index 2 to 3) -> "84352"
    /// "84352" (from index 0 to 2) -> "34852"
    //
    /// Example 2:
    /// Input: s = "34521", t = "23415"
    /// Output: true
    /// Explanation: You can transform s into t using the following sort 
    /// operations:
    /// "34521" -> "23451"
    /// "23451" -> "23415"
    ///
    /// Example 3:
    ///
    /// Input: s = "12345", t = "12435"
    /// Output: false
    ///
    /// Example 4:
    /// Input: s = "1", t = "2"
    ///
    /// Output: false
    /// 
    /// Constraints:
    /// 1. s.length == t.length
    /// 2. 1 <= s.length <= 105
    /// 3. s and t only contain digits from '0' to '9'.
    /// </summary>
    bool isTransformable(string s, string t);

    /// <summary>
    /// Leet code #1608. Special Array With X Elements Greater Than or Equal X
    /// 
    /// Easy
    ///
    /// You are given an array nums of non-negative integers. nums is 
    /// considered special if there exists a number x such that there are 
    /// exactly x numbers in nums that are greater than or equal to x.
    ///
    /// Notice that x does not have to be an element in nums.
    ///
    /// Return x if the array is special, otherwise, return -1. It can be 
    /// proven that if nums is special, the value for x is unique.
    /// 
    /// Example 1:
    /// Input: nums = [3,5]
    /// Output: 2
    /// Explanation: There are 2 values (3 and 5) that are greater than or 
    /// equal to 2.
    ///
    /// Example 2:
    /// Input: nums = [0,0]
    /// Output: -1
    /// Explanation: No numbers fit the criteria for x.
    /// If x = 0, there should be 0 numbers >= x, but there are 2.
    /// If x = 1, there should be 1 number >= x, but there are 0.
    /// If x = 2, there should be 2 numbers >= x, but there are 0.
    /// x cannot be greater since there are only 2 numbers in nums.
    ///
    /// Example 3:
    /// Input: nums = [0,4,3,0,4]
    /// Output: 3
    /// Explanation: There are 3 values that are greater than or equal to 3.
    ///
    /// Example 4:
    /// Input: nums = [3,6,7,7,0]
    /// Output: -1
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 0 <= nums[i] <= 1000
    /// </summary>
    int specialArray(vector<int>& nums);

    /// <summary>
    /// Leet code #1606. Find Servers That Handled Most Number of Requests 
    /// 
    /// Hard
    ///
    /// You have k servers numbered from 0 to k-1 that are being used to 
    /// handle multiple requests simultaneously. Each server has infinite 
    /// computational capacity but cannot handle more than one request at 
    /// a time. The requests are assigned to servers according to a specific 
    /// algorithm:
    ///
    /// The ith (0-indexed) request arrives.
    /// If all servers are busy, the request is dropped (not handled at all).
    /// If the (i % k)th server is available, assign the request to that 
    /// server.
    /// Otherwise, assign the request to the next available server (wrapping 
    /// around the list of servers and starting from 0 if necessary). For 
    /// example, if the ith server is busy, try to assign the request to the 
    /// (i+1)th server, then the (i+2)th server, and so on.
    /// You are given a strictly increasing array arrival of positive 
    /// integers, where arrival[i] represents the arrival time of the ith 
    /// request, and another array load, where load[i] represents the load 
    /// of the ith request (the time it takes to complete). Your goal is to 
    /// find the busiest server(s). A server is considered busiest if it 
    /// handled the most number of requests successfully among all the servers.
    ///
    /// Return a list containing the IDs (0-indexed) of the busiest server(s). 
    /// You may return the IDs in any order.
    ///
    /// Example 1:
    /// Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
    /// Output: [1] 
    /// Explanation:
    /// All of the servers start out available.
    /// The first 3 requests are handled by the first 3 servers in order.
    /// Request 3 comes in. Server 0 is busy, so it's assigned to the next 
    /// available server, which is 1.
    /// Request 4 comes in. It cannot be handled since all servers are busy, 
    /// so it is dropped.
    /// Servers 0 and 2 handled one request each, while server 1 handled two 
    /// requests. Hence server 1 is the busiest server.
    ///
    /// Example 2:
    /// Input: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
    /// Output: [0]
    /// Explanation:
    /// The first 3 requests are handled by first 3 servers.
    /// Request 3 comes in. It is handled by server 0 since the server is 
    /// available.
    /// Server 0 handled two requests, while servers 1 and 2 handled one 
    /// request each. Hence server 0 is the busiest server.
    ///
    /// Example 3:
    /// Input: k = 3, arrival = [1,2,3], load = [10,12,11]
    /// Output: [0,1,2]
    /// Explanation: Each server handles a single request, so they are all 
    /// considered the busiest.
    ///
    /// Example 4:
    /// Input: k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
    /// Output: [1]
    ///
    /// Example 5:
    /// Input: k = 1, arrival = [1], load = [1]
    /// Output: [0]
    /// 
    /// Constraints:
    /// 1. 1 <= k <= 105
    /// 2. 1 <= arrival.length, load.length <= 105
    /// 3. arrival.length == load.length
    /// 4. 1 <= arrival[i], load[i] <= 10^9
    /// 5. arrival is strictly increasing.
    /// </summary>
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load);

    /// <summary>
    /// Leet code #1564. Put Boxes Into the Warehouse I
    /// 
    /// Medium
    ///
    /// You are given two arrays of positive integers, boxes and warehouse, 
    /// representing the heights of some boxes of unit width and the heights 
    /// of n rooms in a warehouse respectively. The warehouse's rooms are 
    /// labelled from 0 to n - 1 from left to right where warehouse[i] 
    /// (0-indexed) is the height of the ith room.
    ///
    /// Boxes are put into the warehouse by the following rules:
    /// Boxes cannot be stacked.
    /// You can rearrange the insertion order of the boxes.
    /// Boxes can only be pushed into the warehouse from left to right only.
    /// If the height of some room in the warehouse is less than the height 
    /// of a box, then that box and all other boxes behind it will be stopped 
    /// before that room.
    /// Return the maximum number of boxes you can put into the warehouse.
    ///
    /// Example 1:
    /// Input: boxes = [4,3,4,1], warehouse = [5,3,3,4,1]
    /// Output: 3
    /// Explanation: 
    /// We can first put the box of height 1 in room 4. Then we can put the 
    /// box of height 3 in either of the 3 rooms 1, 2, or 3. Lastly, we can 
    /// put one box of height 4 in room 0.
    /// There is no way we can fit all 4 boxes in the warehouse.
    ///
    /// Example 2:
    /// Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
    /// Output: 3
    /// Explanation: 
    /// Notice that it's not possible to put the box of height 4 into the 
    /// warehouse since it cannot pass the first room of height 3.
    /// Also, for the last two rooms, 2 and 3, only boxes of height 1 can fit.
    /// We can fit 3 boxes maximum as shown above. The yellow box can also be 
    /// put in room 2 instead.
    /// Swapping the orange and green boxes is also valid, or swapping one of 
    /// them with the red box.
    ///
    /// Example 3:
    /// Input: boxes = [1,2,3], warehouse = [1,2,3,4]
    /// Output: 1
    /// Explanation: Since the first room in the warehouse is of height 1, we 
    /// can only put boxes of height 1.
    ///
    /// Example 4:
    /// Input: boxes = [4,5,6], warehouse = [3,3,3,3,3]
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. n == warehouse.length
    /// 2. 1 <= boxes.length, warehouse.length <= 10^5
    /// 3. 1 <= boxes[i], warehouse[i] <= 10^9
    /// </summary>
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse);

    /// <summary>
    /// Leet code #1580. Put Boxes Into the Warehouse II
    /// 
    /// Medium
    ///
    /// You are given two arrays of positive integers, boxes and warehouse, 
    /// representing the heights of some boxes of unit width and the heights 
    /// of n rooms in a warehouse respectively. The warehouse's rooms are 
    /// labeled from 0 to n - 1 from left to right where warehouse[i] 
    /// (0-indexed) is the height of the ith room.
    ///
    /// Boxes are put into the warehouse by the following rules:
    /// Boxes cannot be stacked.
    /// You can rearrange the insertion order of the boxes.
    /// Boxes can be pushed into the warehouse from either side (left or right)
    /// If the height of some room in the warehouse is less than the height of 
    /// a box, then that box and all other boxes behind it will be stopped 
    /// before that room.
    /// Return the maximum number of boxes you can put into the warehouse.
    ///
    /// Example 1:
    /// Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
    /// Output: 4
    /// Explanation:
    /// We can store the boxes in the following order:
    /// 1- Put the yellow box in room 2 from either the left or right side.
    /// 2- Put the orange box in room 3 from the right side.
    /// 3- Put the green box in room 1 from the left side.
    /// 4- Put the red box in room 0 from the left side.
    /// Notice that there are other valid ways to put 4 boxes such as swapping 
    /// the red and green boxes or the red and orange boxes.
    ///
    /// Example 2:
    /// Input: boxes = [3,5,5,2], warehouse = [2,1,3,4,5]
    /// Output: 3
    /// Explanation:
    /// It's not possible to put the two boxes of height 5 in the warehouse 
    /// since there's only 1 room of height >= 5.
    /// Other valid solutions are to put the green box in room 2 or to put the 
    /// orange box first in room 2 before putting the green and red boxes.
    ///
    /// Example 3:
    /// Input: boxes = [1,2,3], warehouse = [1,2,3,4]
    /// Output: 3
    ///
    /// Example 4:
    /// Input: boxes = [4,5,6], warehouse = [3,3,3,3,3]
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. n == warehouse.length
    /// 2. 1 <= boxes.length, warehouse.length <= 10^5
    /// 3. 1 <= boxes[i], warehouse[i] <= 10^9
    /// </summary>
    int maxBoxesInWarehouseII(vector<int>& boxes, vector<int>& warehouse);

    /// <summary>
    /// Leet code #1626. Best Team With No Conflicts
    /// 
    /// Medium
    ///
    /// You are the manager of a basketball team. For the upcoming tournament, 
    /// you want to choose the team with the highest overall score. The score 
    /// of the team is the sum of scores of all the players in the team.
    ///
    /// However, the basketball team is not allowed to have conflicts. A 
    /// conflict exists if a younger player has a strictly higher score than 
    /// an older player. A conflict does not occur between players of the same 
    /// age.
    ///
    /// Given two lists, scores and ages, where each scores[i] and ages[i] 
    /// represents the score and age of the ith player, respectively, return 
    /// the highest overall score of all possible basketball teams.
    ///
    /// Example 1:
    /// Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
    /// Output: 34
    /// Explanation: You can choose all the players.
    ///
    /// Example 2:
    /// Input: scores = [4,5,6,5], ages = [2,1,2,1]
    /// Output: 16
    /// Explanation: It is best to choose the last 3 players. Notice that 
    /// you are allowed to choose multiple people of the same age.
    ///
    /// Example 3:
    /// Input: scores = [1,2,3,5], ages = [8,9,10,1]
    /// Output: 6
    /// Explanation: It is best to choose the first 3 players. 
    ///
    /// Constraints:
    /// 1. 1 <= scores.length, ages.length <= 1000
    /// 2. scores.length == ages.length
    /// 3. 1 <= scores[i] <= 10^6
    /// 4. 1 <= ages[i] <= 1000
    /// </summary>
    int bestTeamScore(vector<int>& scores, vector<int>& ages);

    /// <summary>
    /// Leet code #1632. Rank Transform of a Matrix
    /// 
    /// Hard
    ///
    /// Given an m x n matrix, return a new matrix answer where 
    /// answer[row][col] is the rank of matrix[row][col].
    ///
    /// The rank is an integer that represents how large an element 
    /// is compared to other elements. It is calculated using the 
    /// following rules:
    ///
    /// The rank is an integer starting from 1.
    /// If two elements p and q are in the same row or column, then:
    /// If p < q then rank(p) < rank(q)
    /// If p == q then rank(p) == rank(q)
    /// If p > q then rank(p) > rank(q)
    /// The rank should be as small as possible.
    /// It is guaranteed that answer is unique under the given rules.
    ///
    /// Example 1:
    /// 
    ///
    /// Input: matrix = [[1,2],[3,4]]
    /// Output: [[1,2],[2,3]]
    /// Explanation:
    /// The rank of matrix[0][0] is 1 because it is the smallest 
    /// integer in its row and column.
    /// The rank of matrix[0][1] is 2 because matrix[0][1] > 
    /// matrix[0][0] and matrix[0][0] is rank 1.
    /// The rank of matrix[1][0] is 2 because matrix[1][0] > 
    /// matrix[0][0] and matrix[0][0] is rank 1.
    /// The rank of matrix[1][1] is 3 because matrix[1][1] > matrix[0][1], 
    /// matrix[1][1] > matrix[1][0], and both matrix[0][1] and matrix[1][0] 
    /// are rank 2.
    ///
    /// Example 2:
    /// Input: matrix = [[7,7],[7,7]]
    /// Output: [[1,1],[1,1]]
    ///
    /// Example 3:
    /// Input: matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
    /// Output: [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
    ///
    /// Example 4:
    /// Input: matrix = [[7,3,6],[1,4,5],[9,8,2]]
    /// Output: [[5,1,4],[1,2,3],[6,3,1]]
    /// 
    /// Constraints:
    /// 1. m == matrix.length
    /// 2. n == matrix[i].length 
    /// 3. 1 <= m, n <= 500
    /// 4. -10^9 <= matrix[row][col] <= 10^9
    /// </summary>
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #1649. Create Sorted Array through Instructions
    /// 
    /// Hard
    ///
    /// Given an integer array instructions, you are asked to create a sorted 
    /// array from the elements in instructions. You start with an empty 
    /// container nums. For each element from left to right in instructions, 
    /// insert it into nums. The cost of each insertion is the minimum of the 
    /// following:
    ///
    /// The number of elements currently in nums that are strictly less than 
    /// instructions[i].
    /// The number of elements currently in nums that are strictly greater 
    /// than instructions[i].
    /// For example, if inserting element 3 into nums = [1,2,3,5], the cost of 
    /// insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is 
    /// greater than 3) and nums will become [1,2,3,3,5].
    ///
    /// Return the total cost to insert all elements from instructions into nums. 
    /// Since the answer may be large, return it modulo 10^9 + 7
    /// 
    /// Example 1: 
    /// Input: instructions = [1,5,6,2]
    /// Output: 1
    /// Explanation: Begin with nums = [].
    /// Insert 1 with cost min(0, 0) = 0, now nums = [1].
    /// Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
    /// Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
    /// Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
    /// The total cost is 0 + 0 + 0 + 1 = 1.
    ///
    /// Example 2:
    /// Input: instructions = [1,2,3,6,5,4]
    /// Output: 3
    /// Explanation: Begin with nums = [].
    /// Insert 1 with cost min(0, 0) = 0, now nums = [1].
    /// Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
    /// Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
    /// Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
    /// Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
    /// Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
    /// The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
    ///
    /// Example 3:
    /// Input: instructions = [1,3,3,3,2,4,2,1,2]
    /// Output: 4
    /// Explanation: Begin with nums = [].
    /// Insert 1 with cost min(0, 0) = 0, now nums = [1].
    /// Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
    /// Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
    /// Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
    /// Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
    /// Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
    /// Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
    /// Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
    /// The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4
    /// 
    /// Constraints:
    /// 1. 1 <= instructions.length <= 10^5
    /// 2. 1 <= instructions[i] <= 10^5
    /// </summary>
    int createSortedArray(vector<int>& instructions);

    /// <summary>
    /// Leet code #1649. Create Sorted Array through Instructions
    /// 
    /// Hard
    ///
    /// Given an integer array instructions, you are asked to create a sorted 
    /// array from the elements in instructions. You start with an empty 
    /// container nums. For each element from left to right in instructions, 
    /// insert it into nums. The cost of each insertion is the minimum of the 
    /// following:
    ///
    /// The number of elements currently in nums that are strictly less than 
    /// instructions[i].
    /// The number of elements currently in nums that are strictly greater 
    /// than instructions[i].
    /// For example, if inserting element 3 into nums = [1,2,3,5], the cost of 
    /// insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is 
    /// greater than 3) and nums will become [1,2,3,3,5].
    ///
    /// Return the total cost to insert all elements from instructions into nums. 
    /// Since the answer may be large, return it modulo 10^9 + 7
    /// 
    /// Example 1: 
    /// Input: instructions = [1,5,6,2]
    /// Output: 1
    /// Explanation: Begin with nums = [].
    /// Insert 1 with cost min(0, 0) = 0, now nums = [1].
    /// Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
    /// Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
    /// Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
    /// The total cost is 0 + 0 + 0 + 1 = 1.
    ///
    /// Example 2:
    /// Input: instructions = [1,2,3,6,5,4]
    /// Output: 3
    /// Explanation: Begin with nums = [].
    /// Insert 1 with cost min(0, 0) = 0, now nums = [1].
    /// Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
    /// Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
    /// Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
    /// Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
    /// Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
    /// The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
    ///
    /// Example 3:
    /// Input: instructions = [1,3,3,3,2,4,2,1,2]
    /// Output: 4
    /// Explanation: Begin with nums = [].
    /// Insert 1 with cost min(0, 0) = 0, now nums = [1].
    /// Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
    /// Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
    /// Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
    /// Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
    /// Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
    /// Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
    /// Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
    /// The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4
    /// 
    /// Constraints:
    /// 1. 1 <= instructions.length <= 10^5
    /// 2. 1 <= instructions[i] <= 10^5
    /// </summary>
    int createSortedArrayI(vector<int>& instructions);

    /// <summary>
    /// Leet code #1675. Minimize Deviation in Array
    /// 
    /// Hard
    /// 
    /// You are given an array nums of n positive integers.
    ///
    /// You can perform two types of operations on any element of the array any 
    /// number of times:
    ///
    /// If the element is even, divide it by 2.
    /// For example, if the array is [1,2,3,4], then you can do this operation on 
    /// the last element, and the array will be [1,2,3,2].
    /// If the element is odd, multiply it by 2.
    /// For example, if the array is [1,2,3,4], then you can do this operation on 
    /// the first element, and the array will be [2,2,3,4].
    /// The deviation of the array is the maximum difference between any two 
    /// elements in the array.
    ///
    /// Return the minimum deviation the array can have after performing some 
    /// number of operations.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,4]
    /// Output: 1
    /// Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], 
    /// then the deviation will be 3 - 2 = 1.
    ///
    /// Example 2:
    /// Input: nums = [4,1,5,20,3]
    /// Output: 3
    /// Explanation: You can transform the array after two operations to 
    /// [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
    ///
    /// Example 3:
    /// Input: nums = [2,10,8]
    /// Output: 3
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 2 <= n <= 10^5
    /// 3. 1 <= nums[i] <= 10^9
    /// </summary>
    int minimumDeviation(vector<int>& nums);

    /// <summary>
    /// Leet code #1686. Stone Game VI
    /// 
    /// Medium
    /// 
    /// Alice and Bob take turns playing a game, with Alice starting first.
    ///
    /// There are n stones in a pile. On each player's turn, they can remove a 
    /// stone from the pile and receive points based on the stone's value. Alice 
    /// and Bob may value the stones differently.
    ///
    /// You are given two integer arrays of length n, aliceValues and bobValues. 
    /// Each aliceValues[i] and bobValues[i] represents how Alice and Bob, 
    /// respectively, value the ith stone.
    ///
    /// The winner is the person with the most points after all the stones are 
    /// chosen. If both players have the same amount of points, the game results 
    /// in a draw. Both players will play optimally.
    ///
    /// Determine the result of the game, and:
    ///
    /// If Alice wins, return 1.
    /// If Bob wins, return -1.
    /// If the game results in a draw, return 0.
    /// 
    /// Example 1:
    /// Input: aliceValues = [1,3], bobValues = [2,1]
    /// Output: 1
    /// Explanation:
    /// If Alice takes stone 1 (0-indexed) first, Alice will receive 3 points.
    /// Bob can only choose stone 0, and will only receive 2 points.
    /// Alice wins.
    ///
    /// Example 2:
    /// Input: aliceValues = [1,2], bobValues = [3,1]
    /// Output: 0
    /// Explanation:
    /// If Alice takes stone 0, and Bob takes stone 1, they will both have 1 point.
    /// Draw.
    ///
    /// Example 3:
    /// Input: aliceValues = [2,4,3], bobValues = [1,6,7]
    /// Output: -1
    /// Explanation:
    /// Regardless of how Alice plays, Bob will be able to have more points than 
    /// Alice.
    /// For example, if Alice takes stone 1, Bob can take stone 2, and Alice takes 
    /// stone 0, Alice will have 6 points to Bob's 7.
    /// Bob wins.
    ///
    /// Constraints:
    /// 1. n == aliceValues.length == bobValues.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= aliceValues[i], bobValues[i] <= 100
    /// </summary>
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues);

    /// <summary>
    /// Leet code #334. Increasing Triplet Subsequence
    /// 
    /// Medium
    /// 
    /// Given an integer array nums, return true if there exists a triple of 
    /// indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
    /// If no such indices exists, return false.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,4,5]
    /// Output: true
    /// Explanation: Any triplet where i < j < k is valid.
    ///
    /// Example 2:
    /// Input: nums = [5,4,3,2,1]
    /// Output: false
    /// Explanation: No triplet exists.
    ///
    /// Example 3:
    /// Input: nums = [2,1,5,0,4,6]
    /// Output: true
    /// Explanation: The triplet (3, 4, 5) is valid 
    /// because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -2^31 <= nums[i] <= 2^31 - 1
    ///
    /// Follow up: Could you implement a solution that runs in O(n) 
    /// time complexity and O(1) space complexity?
    /// </summary>
    bool increasingTriplet(vector<int>& nums);

    /// <summary>
    /// Leet code #1705. Maximum Number of Eaten Apples
    /// 
    /// Medium
    /// 
    /// There is a special kind of apple tree that grows apples every day 
    /// for n days. On the ith day, the tree grows apples[i] apples that 
    /// will rot after days[i] days, that is on day i + days[i] the apples 
    /// will be rotten and cannot be eaten. On some days, the apple tree 
    /// does not grow any apples, which are denoted by apples[i] == 0 
    /// and days[i] == 0.
    ///
    /// You decided to eat at most one apple a day (to keep the doctors away). 
    /// Note that you can keep eating after the first n days.
    ///
    /// Given two integer arrays days and apples of length n, return the 
    /// maximum number of apples you can eat.
    /// 
    /// Example 1:
    /// Input: apples = [1,2,3,5,2], days = [3,2,1,4,2]
    /// Output: 7
    /// Explanation: You can eat 7 apples:
    /// - On the first day, you eat an apple that grew on the first day.
    /// - On the second day, you eat an apple that grew on the second day.
    /// - On the third day, you eat an apple that grew on the second day. 
    ///   After this day, the apples that grew on the third day rot.
    /// - On the fourth to the seventh days, you eat apples that grew on the 
    ///   fourth day.
    ///
    /// Example 2:
    /// Input: apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
    /// Output: 5
    /// Explanation: You can eat 5 apples:
    /// - On the first to the third day you eat apples that grew on the first 
    ///   day.
    /// - Do nothing on the fouth and fifth days.
    /// - On the sixth and seventh days you eat apples that grew on the sixth 
    ///   day.
    /// 
    /// Constraints:
    /// 1. apples.length == n
    /// 2. days.length == n
    /// 3. 1 <= n <= 2 * 10^4
    /// 4. 0 <= apples[i], days[i] <= 2 * 10^4
    /// 5. days[i] = 0 if and only if apples[i] = 0.
    /// </summary>
    int eatenApples(vector<int>& apples, vector<int>& days);

    /// <summary>
    /// Leet code #1710. Maximum Units on a Truck
    /// 
    /// Easy
    /// 
    /// You are assigned to put some amount of boxes onto one truck. You are 
    /// given a 2D array boxTypes, where boxTypes[i] = 
    /// [numberOfBoxesi, numberOfUnitsPerBoxi]:
    ///
    /// numberOfBoxesi is the number of boxes of type i.
    /// numberOfUnitsPerBoxi is the number of units in each box of the type i.
    /// You are also given an integer truckSize, which is the maximum number 
    /// of boxes that can be put on the truck. You can choose any boxes to put 
    /// on the truck as long as the number of boxes does not exceed truckSize.
    ///
    /// Return the maximum total number of units that can be put on the truck.
    ///
    /// Example 1:
    /// Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
    /// Output: 8
    /// Explanation: There are:
    /// - 1 box of the first type that contains 3 units.
    /// - 2 boxes of the second type that contain 2 units each.
    /// - 3 boxes of the third type that contain 1 unit each.
    /// You can take all the boxes of the first and second types, and one 
    /// box of the third type.
    /// The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
    ///
    /// Example 2:
    /// Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
    /// Output: 91
    /// Constraints:
    /// 1. 1 <= boxTypes.length <= 1000
    /// 2. 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
    /// 3. 1 <= truckSize <= 10^6
    /// </summary>
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize);

    /// <summary>
    /// Leet code 1752. Check if Array Is Sorted and Rotated
    /// 
    /// Easy
    /// 
    /// Given an array nums, return true if the array was originally 
    /// sorted in non-decreasing order, then rotated some number of 
    /// positions (including zero). Otherwise, return false.
    ///
    /// There may be duplicates in the original array.
    ///
    /// Note: An array A rotated by x positions results in an array B 
    /// of the same length such that A[i] == B[(i+x) % A.length], 
    /// where % is the modulo operation.
    /// 
    /// Example 1:
    /// Input: nums = [3,4,5,1,2]
    /// Output: true
    /// Explanation: [1,2,3,4,5] is the original sorted array.
    /// You can rotate the array by x = 3 positions to begin on the the 
    /// element of value 3: [3,4,5,1,2].
    ///
    /// Example 2:
    /// Input: nums = [2,1,3,4]
    /// Output: false
    /// Explanation: There is no sorted array once rotated that can make nums.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3]
    /// Output: true
    /// Explanation: [1,2,3] is the original sorted array.
    /// You can rotate the array by x = 0 positions (i.e. no rotation) to 
    /// make nums.
    ///
    /// Example 4:
    /// Input: nums = [1,1,1]
    /// Output: true
    /// Explanation: [1,1,1] is the original sorted array.
    /// You can rotate any number of positions to make nums.
    ///
    /// Example 5:
    /// Input: nums = [2,1]
    /// Output: true
    /// Explanation: [1,2] is the original sorted array.
    /// You can rotate the array by x = 5 positions to begin on the element 
    /// of value 2: [2,1].
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// </summary>
    bool check(vector<int>& nums);

    /// <summary>
    /// Leet code 1775. Equal Sum Arrays With Minimum Number of Operations
    /// 
    /// Medium
    /// 
    /// You are given two arrays of integers nums1 and nums2, possibly of 
    /// different lengths. The values in the arrays are between 1 and 6, 
    /// inclusive.
    ///
    /// In one operation, you can change any integer's value in any of the 
    /// arrays to any value between 1 and 6, inclusive.
    ///
    /// Return the minimum number of operations required to make the sum of 
    /// values in nums1 equal to the sum of values in nums2. Return -1 if 
    /// it is not possible to make the sum of the two arrays equal.
    /// 
    /// Example 1:
    /// Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
    /// Output: 3
    /// Explanation: You can make the sums of nums1 and nums2 equal with 3 
    /// operations. All indices are 0-indexed.
    /// - Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
    /// - Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
    /// - Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
    ///
    /// Example 2:
    /// Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
    /// Output: -1
    /// Explanation: There is no way to decrease the sum of nums1 or to 
    /// increase the sum of nums2 to make them equal.
    ///
    /// Example 3:
    /// Input: nums1 = [6,6], nums2 = [1]
    /// Output: 3
    /// Explanation: You can make the sums of nums1 and nums2 equal with 3 
    /// operations. All indices are 0-indexed. 
    /// - Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
    /// - Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
    /// - Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
    ///
    /// Constraints:
    /// 1. 1 <= nums1.length, nums2.length <= 105
    /// 2. 1 <= nums1[i], nums2[i] <= 6
    /// </summary>
    int minOperations(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet code 1801. Number of Orders in the Backlog
    /// 
    /// Medium
    /// 
    /// You are given a 2D integer array orders, where each orders[i] = 
    /// [pricei, amounti, orderTypei] denotes that amounti orders have been 
    /// placed of type orderTypei at the price pricei. The orderTypei is:
    ///
    /// 0 if it is a batch of buy orders, or
    /// 1 if it is a batch of sell orders.
    /// Note that orders[i] represents a batch of amounti independent orders 
    /// with the same price and order type. All orders represented by 
    /// orders[i] will be placed before all orders represented by orders[i+1] 
    /// for all valid i.
    ///
    /// There is a backlog that consists of orders that have not been executed. 
    /// The backlog is initially empty. When an order is placed, the following 
    /// happens:
    ///
    /// If the order is a buy order, you look at the sell order with the 
    /// smallest price in the backlog. If that sell order's price is smaller 
    /// than or equal to the current buy order's price, they will match and be 
    /// executed, and that sell order will be removed from the backlog. Else, 
    /// the buy order is added to the backlog.
    /// Vice versa, if the order is a sell order, you look at the buy order 
    /// with the largest price in the backlog. If that buy order's price is 
    /// larger than or equal to the current sell order's price, they will match 
    /// and be executed, and that buy order will be removed from the backlog. 
    /// Else, the sell order is added to the backlog.
    /// Return the total amount of orders in the backlog after placing all the 
    /// orders from the input. Since this number can be large, return it 
    /// modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
    /// Output: 6
    /// Explanation: Here is what happens with the orders:
    /// - 5 orders of type buy with price 10 are placed. There are no sell 
    /// orders, so the 5 orders are added to the backlog.
    /// - 2 orders of type sell with price 15 are placed. There are no buy 
    /// orders with prices larger than or equal to 15, so the 2 orders are 
    /// added to the backlog.
    /// - 1 order of type sell with price 25 is placed. There are no buy orders 
    /// with prices larger than or equal to 25 in the backlog, so this order is 
    /// added to the backlog.
    /// - 4 orders of type buy with price 30 are placed. The first 2 orders are 
    /// matched with the 2 sell orders of the least price, which is 15 and 
    /// these 2 sell orders are removed from the backlog. The 3rd order is 
    /// matched with the sell order of the least price, which is 25 and this 
    /// sell order is removed from the backlog. Then, there are no more sell 
    /// orders in the backlog, so the 4th order is added to the backlog.
    /// Finally, the backlog has 5 buy orders with price 10, and 1 buy order 
    /// with price 30. So the total number of orders in the backlog is 6.
    ///
    /// Example 2:
    /// Input: orders = [[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]
    /// Output: 999999984
    /// Explanation: Here is what happens with the orders:
    /// - 10^9 orders of type sell with price 7 are placed. There are no buy 
    /// orders, so the 109 orders are added to the backlog.
    /// - 3 orders of type buy with price 15 are placed. They are matched with 
    /// the 3 sell orders with the least price which is 7, and those 3 sell 
    /// orders are removed from the backlog.
    /// - 999999995 orders of type buy with price 5 are placed. The least 
    /// price of a sell order is 7, so the 999999995 orders are added to the 
    /// backlog.
    /// - 1 order of type sell with price 5 is placed. It is matched with the 
    /// buy order of the highest price, which is 5, and that buy order is 
    /// removed from the backlog.
    /// Finally, the backlog has (1000000000-3) sell orders with price 7, 
    /// and (999999995-1) buy orders with price 5. So the total number of 
    /// orders = 1999999991, which is equal to 999999984 % (10^9 + 7).
    /// 
    /// Constraints:
    /// 1. 1 <= orders.length <= 10^5
    /// 2. orders[i].length == 3
    /// 3. 1 <= pricei, amounti <= 10^9
    /// 4. orderTypei is either 0 or 1.
    /// </summary>
    int getNumberOfBacklogOrders(vector<vector<int>>& orders);

    /// <summary>
    /// Leet code 1833. Maximum Ice Cream Bars
    /// 
    /// Medium
    /// 
    /// It is a sweltering summer day, and a boy wants to buy some ice cream 
    /// bars.
    ///
    /// At the store, there are n ice cream bars. You are given an array costs 
    /// of length n, where costs[i] is the price of the ith ice cream bar in 
    /// coins. The boy initially has coins coins to spend, and he wants to buy 
    /// as many ice cream bars as possible. 
    ///
    /// Return the maximum number of ice cream bars the boy can buy with coins. 
    /// 
    /// Note: The boy can buy the ice cream bars in any order.
    /// 
    /// Example 1:
    /// Input: costs = [1,3,2,4,1], coins = 7
    /// Output: 4
    /// Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a 
    /// total price of 1 + 3 + 2 + 1 = 7.
    ///
    /// Example 2:
    /// Input: costs = [10,6,8,7,7,8], coins = 5
    /// Output: 0
    /// Explanation: The boy cannot afford any of the ice cream bars.
    ///
    /// Example 3:
    /// Input: costs = [1,6,3,1,2,5], coins = 20
    /// Output: 6
    /// Explanation: The boy can buy all the ice cream bars for a total price 
    /// of 1 + 6 + 3 + 1 + 2 + 5 = 18.
    /// 
    /// Constraints:
    /// 1. costs.length == n
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= costs[i] <= 10^5
    /// 4. 1 <= coins <= 10^8
    /// </summary>
    int maxIceCream(vector<int>& costs, int coins);

    /// <summary>
    /// Leet code 1834. Single-Threaded CPU
    /// 
    /// Medium
    /// 
    /// You are given n tasks labeled from 0 to n - 1 represented by a 2D 
    /// integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] 
    /// means that the ith task will be available to process at enqueueTimei 
    /// and will take processingTimei to finish processing.
    ///
    /// You have a single-threaded CPU that can process at most one task at 
    /// a time and will act in the following way:
    ///
    /// If the CPU is idle and there are no available tasks to process, the 
    /// CPU remains idle.
    /// If the CPU is idle and there are available tasks, the CPU will choose 
    /// the one with the shortest processing time. If multiple tasks have the 
    /// same shortest processing time, it will choose the task with the 
    /// smallest index.
    /// Once a task is started, the CPU will process the entire task without 
    /// stopping.
    /// The CPU can finish a task then start a new one instantly.
    /// Return the order in which the CPU will process the tasks.
    /// 
    /// Example 1:
    /// Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
    /// Output: [0,2,3,1]
    /// Explanation: The events go as follows: 
    /// - At time = 1, task 0 is available to process. Available tasks = {0}.
    /// - Also at time = 1, the idle CPU starts processing task 0. 
    ///   Available tasks = {}.
    /// - At time = 2, task 1 is available to process. Available tasks = {1}.
    /// - At time = 3, task 2 is available to process. Available 
    ///   tasks = {1, 2}.
    /// - Also at time = 3, the CPU finishes task 0 and starts processing 
    ///   task 2 as it is the shortest. Available tasks = {1}.
    /// - At time = 4, task 3 is available to process. Available 
    ///   tasks = {1, 3}.
    /// - At time = 5, the CPU finishes task 2 and starts processing task 3 
    ///   as it is the shortest. Available tasks = {1}.
    /// - At time = 6, the CPU finishes task 3 and starts processing task 1. 
    ///   Available tasks = {}.
    /// - At time = 10, the CPU finishes task 1 and becomes idle.
    ///  
    /// Example 2:
    /// 
    /// Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
    /// Output: [4,3,2,0,1]
    /// Explanation: The events go as follows:
    /// - At time = 7, all the tasks become available. Available 
    ///   tasks = {0,1,2,3,4}.
    /// - Also at time = 7, the idle CPU starts processing task 4. 
    ///   Available tasks = {0,1,2,3}.
    /// - At time = 9, the CPU finishes task 4 and starts processing task 3. 
    ///   Available tasks = {0,1,2}.
    /// - At time = 13, the CPU finishes task 3 and starts processing task 2. 
    ///   Available tasks = {0,1}.
    /// - At time = 18, the CPU finishes task 2 and starts processing task 0. 
    ///   Available tasks = {1}.
    /// - At time = 28, the CPU finishes task 0 and starts processing task 1. 
    ///   Available tasks = {}.
    /// - At time = 40, the CPU finishes task 1 and becomes idle.
    /// 
    /// Constraints:
    /// 1. tasks.length == n
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= enqueueTimei, processingTimei <= 10^9
    /// </summary>
    vector<int> getOrder(vector<vector<int>>& tasks);

    /// <summary>
    /// Leet code 1846. Maximum Element After Decreasing and Rearranging
    /// 
    /// Medium
    /// 
    /// You are given an array of positive integers arr. Perform some 
    /// operations (possibly none) on arr so that it satisfies these 
    /// conditions:
    ///
    /// The value of the first element in arr must be 1.
    /// The absolute difference between any 2 adjacent elements must be less 
    /// than or equal to 1. In other words, abs(arr[i] - arr[i - 1]) <= 1 
    /// for each i where 1 <= i < arr.length (0-indexed). abs(x) is the 
    /// absolute value of x.
    /// There are 2 types of operations that you can perform any number of 
    /// times:
    ///
    /// Decrease the value of any element of arr to a smaller positive integer.
    /// Rearrange the elements of arr to be in any order.
    /// Return the maximum possible value of an element in arr after 
    /// performing the operations to satisfy the conditions.
    /// 
    /// Example 1:
    /// Input: arr = [2,2,1,2,1]
    /// Output: 2
    /// Explanation: 
    /// We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
    /// The largest element in arr is 2.
    ///
    /// Example 2:
    /// Input: arr = [100,1,1000]
    /// Output: 3
    /// Explanation: 
    /// One possible way to satisfy the conditions is by doing the following:
    /// 1. Rearrange arr so it becomes [1,100,1000].
    /// 2. Decrease the value of the second element to 2.
    /// 3. Decrease the value of the third element to 3.
    /// Now arr = [1,2,3], which satisfies the conditions.
    /// The largest element in arr is 3.
    ///
    /// Example 3:
    /// Input: arr = [1,2,3,4,5]
    /// Output: 5
    /// Explanation: The array already satisfies the conditions, and the largest 
    /// element is 5.
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 1 <= arr[i] <= 10^9
    /// </summary>
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr);

    /// <summary>
    /// Leet code 1847. Closest Room
    /// 
    /// Hard
    /// 
    /// There is a hotel with n rooms. The rooms are represented by a 2D 
    /// integer array rooms where rooms[i] = [roomIdi, sizei] denotes that 
    /// there is a room with room number roomIdi and size equal to sizei. 
    /// Each roomIdi is guaranteed to be unique.
    ///
    /// You are also given k queries in a 2D array queries where 
    /// queries[j] = [preferredj, minSizej]. The answer to the jth query 
    /// is the room number id of a room such that:
    ///
    /// The room has a size of at least minSizej, and
    /// abs(id - preferredj) is minimized, where abs(x) is the absolute 
    /// value of x.
    /// If there is a tie in the absolute difference, then use the room 
    /// with the smallest such id. If there is no such room, the answer 
    /// is -1.
    /// Return an array answer of length k where answer[j] contains the 
    /// answer to the jth query.
    ///
    /// Example 1:
    /// Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
    /// Output: [3,-1,3]
    /// Explanation: The answers to the queries are as follows:
    /// Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, 
    /// and its size of 2 is at least 1. The answer is 3.
    /// Query = [3,3]: There are no rooms with a size of at least 3, so 
    /// the answer is -1.
    /// Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, 
    /// and its size of 2 is at least 2. The answer is 3.
    ///
    /// Example 2:
    /// Input: rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], 
    /// queries = [[2,3],[2,4],[2,5]]
    /// Output: [2,1,3]
    /// Explanation: The answers to the queries are as follows:
    /// Query = [2,3]: Room number 2 is the closest as abs(2 - 2) = 0, 
    /// and its size of 3 is at least 3. The answer is 2.
    /// Query = [2,4]: Room numbers 1 and 3 both have sizes of at least 4. 
    /// The answer is 1 since it is smaller.
    /// Query = [2,5]: Room number 3 is the only room with a size of at 
    /// least 5. The answer is 3.
    /// 
    /// Constraints:
    /// 1. n == rooms.length
    /// 2. 1 <= n <= 10^5
    /// 3. k == queries.length
    /// 4. 1 <= k <= 10^4
    /// 5. 1 <= roomIdi, preferredj <= 10^7
    /// 6. 1 <= sizei, minSizej <= 10^7
    /// </summary>
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code 1851. Minimum Interval to Include Each Query
    /// 
    /// Hard
    /// 
    /// You are given a 2D integer array intervals, where intervals[i] = 
    /// [lefti, righti] describes the ith interval starting at lefti and 
    /// ending at righti (inclusive). The size of an interval is defined 
    /// as the number of integers it contains, or more formally 
    /// righti - lefti + 1.
    ///
    /// You are also given an integer array queries. The answer to the 
    /// jth query is the size of the smallest interval i such that 
    /// lefti <= queries[j] <= righti. If no such interval exists, the 
    /// answer is -1.
    ///
    /// Return an array containing the answers to the queries.
    /// Example 1:
    /// Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
    /// Output: [3,3,1,4]
    /// Explanation: The queries are processed as follows:
    /// - Query = 2: The interval [2,4] is the smallest interval containing 2. 
    ///   The answer is 4 - 2 + 1 = 3.
    /// - Query = 3: The interval [2,4] is the smallest interval containing 3. 
    ///   The answer is 4 - 2 + 1 = 3.
    /// - Query = 4: The interval [4,4] is the smallest interval containing 4. 
    ///   The answer is 4 - 4 + 1 = 1.
    /// - Query = 5: The interval [3,6] is the smallest interval containing 5. 
    /// The answer is 6 - 3 + 1 = 4.
    ///
    /// Example 2:
    /// Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
    /// Output: [2,-1,4,6]
    /// Explanation: The queries are processed as follows:
    /// - Query = 2: The interval [2,3] is the smallest interval containing 2. 
    ///   The answer is 3 - 2 + 1 = 2.
    /// - Query = 19: None of the intervals contain 19. The answer is -1.
    /// - Query = 5: The interval [2,5] is the smallest interval containing 5. 
    ///   The answer is 5 - 2 + 1 = 4.
    /// - Query = 22: The interval [20,25] is the smallest interval 
    ///   containing 22. The answer is 25 - 20 + 1 = 6.
    /// 
    /// Constraints:
    /// 1. 1 <= intervals.length <= 10^5
    /// 2. 1 <= queries.length <= 10^5
    /// 3. queries[i].length == 2
    /// 4. 1 <= lefti <= righti <= 10^7
    /// 5. 1 <= queries[j] <= 10^7
    /// </summary>
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries);

    /// <summary>
    /// Leet code 1889. Minimum Space Wasted From Packaging
    /// 
    /// Hard
    /// 
    /// You have n packages that you are trying to place in boxes, one package 
    /// in each box. There are m suppliers that each produce boxes of different 
    /// sizes (with infinite supply). A package can be placed in a box if the 
    /// size of the package is less than or equal to the size of the box.
    ///
    /// The package sizes are given as an integer array packages, where 
    /// packages[i] is the size of the ith package. The suppliers are given as 
    /// a 2D integer array boxes, where boxes[j] is an array of box sizes that 
    /// the jth supplier produces.
    ///
    /// You want to choose a single supplier and use boxes from them such that 
    /// the total wasted space is minimized. For each package in a box, we 
    /// define the space wasted to be size of the box - size of the package. 
    /// The total wasted space is the sum of the space wasted in all the boxes.
    ///
    /// For example, if you have to fit packages with sizes [2,3,5] and the 
    /// supplier offers boxes of sizes [4,8], you can fit the packages of 
    /// size-2 and size-3 into two boxes of size-4 and the package with size-5 
    /// into a box of size-8. This would result in a waste of (4-2) + (4-3) + 
    /// (8-5) = 6.
    /// Return the minimum total wasted space by choosing the box supplier 
    /// optimally, or -1 if it is impossible to fit all the packages inside 
    /// boxes. Since the answer may be large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: packages = [2,3,5], boxes = [[4,8],[2,8]]
    /// Output: 6
    /// Explanation: It is optimal to choose the first supplier, using two 
    /// size-4 boxes and one size-8 box.
    /// The total waste is (4-2) + (4-3) + (8-5) = 6.
    ///
    /// Example 2:
    /// Input: packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
    /// Output: -1
    /// Explanation: There is no box that the package of size 5 can fit in.
    ///
    /// Example 3:
    /// Input: packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
    /// Output: 9
    /// Explanation: It is optimal to choose the third supplier, using two 
    /// size-5 boxes, two size-10 boxes, and two size-14 boxes.
    /// The total waste is (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9.
    /// 
    /// Constraints:
    /// 1. n == packages.length
    /// 2. m == boxes.length
    /// 3. 1 <= n <= 10^5
    /// 4. 1 <= m <= 10^5
    /// 5. 1 <= packages[i] <= 10^5
    /// 6. 1 <= boxes[j].length <= 10^5
    /// 7. 1 <= boxes[j][k] <= 10^5
    /// 8. sum(boxes[j].length) <= 10^5
    /// 9. The elements in boxes[j] are distinct.
    /// </summary>
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes);

    /// <summary>
    /// Leet code 1909. Remove One Element to Make the Array Strictly 
    ///                 Increasing
    /// 
    /// Easy
    /// 
    /// Given a 0-indexed integer array nums, return true if it can be made 
    /// strictly increasing after removing exactly one element, or false 
    /// otherwise. If the array is already strictly increasing, return true.
    ///
    /// The array nums is strictly increasing if nums[i - 1] < nums[i] for 
    /// each index (1 <= i < nums.length).
    ///
    /// Example 1:
    /// Input: nums = [1,2,10,5,7]
    /// Output: true
    /// Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
    /// [1,2,5,7] is strictly increasing, so return true.
    ///
    /// Example 2:
    /// Input: nums = [2,3,1,2]
    /// Output: false
    /// Explanation:
    /// [3,1,2] is the result of removing the element at index 0.
    /// [2,1,2] is the result of removing the element at index 1.
    /// [2,3,2] is the result of removing the element at index 2.
    /// [2,3,1] is the result of removing the element at index 3.
    /// No resulting array is strictly increasing, so return false.
    ///
    /// Example 3:
    /// Input: nums = [1,1,1]
    /// Output: false
    /// Explanation: The result of removing any element is [1,1].
    /// [1,1] is not strictly increasing, so return false.
    ///
    /// Example 4:
    /// Input: nums = [1,2,3]
    /// Output: true
    /// Explanation: [1,2,3] is already strictly increasing, so 
    /// return true.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 1000
    /// </summary>
    bool canBeIncreasing(vector<int>& nums);

    /// <summary>
    /// Leet code 1913. Maximum Product Difference Between Two Pairs
    /// 
    /// Easy
    /// 
    /// The product difference between two pairs (a, b) and (c, d) is defined 
    /// as (a * b) - (c * d).
    ///
    /// For example, the product difference between (5, 6) and (2, 7) is 
    /// (5 * 6) - (2 * 7) = 16.
    /// Given an integer array nums, choose four distinct indices w, x, y, 
    /// and z such that the product difference between pairs (nums[w], 
    /// nums[x]) and (nums[y], nums[z]) is maximized.
    ///
    /// Return the maximum such product difference.
    ///
    /// Example 1:
    /// Input: nums = [5,6,2,7,4]
    /// Output: 34
    /// Explanation: We can choose indices 1 and 3 for the first pair 
    /// (6, 7) and indices 2 and 4 for the second pair (2, 4).
    /// The product difference is (6 * 7) - (2 * 4) = 34.
    ///
    /// Example 2:
    /// Input: nums = [4,2,5,9,7,4,8]
    /// Output: 64
    /// Explanation: We can choose indices 3 and 6 for the first pair (9, 8) 
    /// and indices 1 and 5 for the second pair (2, 4).
    /// The product difference is (9 * 8) - (2 * 4) = 64.
    ///
    /// Constraints:
    /// 1. 4 <= nums.length <= 10^4
    /// 2. 1 <= nums[i] <= 10^4
    /// </summary>
    int maxProductDifference(vector<int>& nums);

    /// <summary>
    /// Leet code 1877. Minimize Maximum Pair Sum in Array
    ///                  
    /// Medium
    /// 
    /// The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum 
    /// is the largest pair sum in a list of pairs.
    ///
    /// For example, if we have pairs (1,5), (2,3), and (4,4), the maximum 
    /// pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
    /// Given an array nums of even length n, pair up the elements of nums 
    /// into n / 2 pairs such that:
    ///
    /// Each element of nums is in exactly one pair, and
    /// The maximum pair sum is minimized.
    /// Return the minimized maximum pair sum after optimally pairing up the 
    /// elements.
    /// 
    /// Example 1:
    /// Input: nums = [3,5,2,3]
    /// Output: 7
    /// Explanation: The elements can be paired up into pairs (3,3) and (5,2).
    /// The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
    ///
    /// Example 2:
    /// Input: nums = [3,5,4,2,4,6]
    /// Output: 8
    /// Explanation: The elements can be paired up into pairs (3,5), (4,4), 
    /// and (6,2).
    /// The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
    /// 
    /// Constraints:
    ///
    /// 1. n == nums.length
    /// 2. 2 <= n <= 10^5
    /// 3. n is even.
    /// 4. 1 <= nums[i] <= 10^5
    /// </summary>
    int minPairSum(vector<int>& nums);

    /// <summary>
    /// Leet code 1881. Maximum Value after Insertion
    ///                  
    /// Medium
    /// 
    /// You are given a very large integer n, represented as a string, and an 
    /// integer digit x. The digits in n and the digit x are in the 
    /// inclusive range [1, 9], and n may represent a negative number.
    ///
    /// You want to maximize n's numerical value by inserting x anywhere in 
    /// the decimal representation of n. You cannot insert x to the left of 
    /// the negative sign.
    ///
    /// For example, if n = 73 and x = 6, it would be best to insert it 
    /// between 7 and 3, making n = 763.
    /// If n = -55 and x = 2, it would be best to insert it before the 
    /// first 5, making n = -255.
    /// Return a string representing the maximum value of n after the 
    /// insertion.
    /// 
    /// Example 1:
    /// Input: n = "99", x = 9
    /// Output: "999"
    /// Explanation: The result is the same regardless of where you insert 9.
    ///
    /// Example 2:
    /// Input: n = "-13", x = 2
    /// Output: "-123"
    /// Explanation: You can make n one of {-213, -123, -132}, and the 
    /// largest of those three is -123.
    ///
    /// Constraints:
    /// 1. 1 <= n.length <= 105
    /// 2. 1 <= x <= 9
    /// 3. The digits in n are in the range [1, 9].
    /// 4. n is a valid representation of an integer.
    /// 5. In the case of a negative n, it will begin with '-'.
    /// </summary>
    string maxValue(string n, int x);

    /// <summary>
    /// Leet code 1887. Reduction Operations to Make the Array Elements Equal 
    ///                                  
    /// Medium
    /// 
    /// Given an integer array nums, your goal is to make all elements in nums 
    /// equal. To complete one operation, follow these steps:
    ///
    /// Find the largest value in nums. Let its index be i (0-indexed) and its 
    /// value be largest. If there are multiple elements with the largest 
    /// value, pick the smallest i.
    /// Find the next largest value in nums strictly smaller than largest. Let 
    /// its value be nextLargest.
    /// Reduce nums[i] to nextLargest.
    /// Return the number of operations to make all elements in nums equal.
    ///
    /// Example 1:
    /// Input: nums = [5,1,3]
    /// Output: 3
    /// Explanation: It takes 3 operations to make all elements in nums equal:
    /// 1. largest = 5 at index 0. nextLargest = 3. Reduce nums[0] to 3. 
    ///    nums = [3,1,3].
    /// 2. largest = 3 at index 0. nextLargest = 1. Reduce nums[0] to 1. 
    ///    nums = [1,1,3].
    /// 3. largest = 3 at index 2. nextLargest = 1. Reduce nums[2] to 1. 
    ///    nums = [1,1,1].
    ///
    /// Example 2:
    /// Input: nums = [1,1,1]
    /// Output: 0
    /// Explanation: All elements in nums are already equal.
    ///
    /// Example 3:
    /// Input: nums = [1,1,2,2,3]
    /// Output: 4
    /// Explanation: It takes 4 operations to make all elements in nums equal:
    /// 1. largest = 3 at index 4. nextLargest = 2. Reduce nums[4] to 2. 
    ///    nums = [1,1,2,2,2].
    /// 2. largest = 2 at index 2. nextLargest = 1. Reduce nums[2] to 1. 
    ///    nums = [1,1,1,2,2].
    /// 3. largest = 2 at index 3. nextLargest = 1. Reduce nums[3] to 1. 
    ///    nums = [1,1,1,1,2].
    /// 4. largest = 2 at index 4. nextLargest = 1. Reduce nums[4] to 1. 
    ///    nums = [1,1,1,1,1].
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 5 * 10^4
    /// 2. 1 <= nums[i] <= 5 * 10^4
    /// </summary>
    int reductionOperations(vector<int>& nums);

    /// <summary>
    /// Leet code 1882. Process Tasks Using Servers
    ///                                  
    /// Medium
    /// 
    /// You are given two 0-indexed integer arrays servers and tasks of lengths 
    /// n and m respectively. servers[i] is the weight of the ith server, and 
    /// tasks[j] is the time needed to process the jth task in seconds.
    ///
    /// Tasks are assigned to the servers using a task queue. Initially, all 
    /// servers are free, and the queue is empty.
    ///
    /// At second j, the jth task is inserted into the queue (starting with 
    /// the 0th task being inserted at second 0). As long as there are free 
    /// servers and the queue is not empty, the task in the front of the queue 
    /// will be assigned to a free server with the smallest weight, and in 
    /// case of a tie, it is assigned to a free server with the smallest index.
    ///
    /// If there are no free servers and the queue is not empty, we wait until 
    /// a server becomes free and immediately assign the next task. If multiple
    /// servers become free at the same time, then multiple tasks from the 
    /// queue will be assigned in order of insertion following the weight and 
    /// index priorities above.
    ///
    /// A server that is assigned task j at second t will be free again at 
    /// second t + tasks[j].
    ///
    /// Build an array ans of length m, where ans[j] is the index of the 
    /// server the jth task will be assigned to.
    ///
    /// Return the array ans.
    /// 
    /// Example 1:
    /// Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
    /// Output: [2,2,0,2,1,2]
    /// Explanation: Events in chronological order go as follows:
    /// - At second 0, task 0 is added and processed using server 2 until 
    ///   second 1.
    /// - At second 1, server 2 becomes free. Task 1 is added and 
    ///   processed using server 2 until second 3.
    /// - At second 2, task 2 is added and processed using server 0 until 
    ///   second 5.
    /// - At second 3, server 2 becomes free. Task 3 is added and processed 
    ///   using server 2 until second 5.
    /// - At second 4, task 4 is added and processed using server 1 until 
    ///   second 5.
    /// - At second 5, all servers become free. Task 5 is added and processed 
    ///   using server 2 until second 7.
    ///
    /// Example 2:
    /// Input: servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
    /// Output: [1,4,1,4,1,3,2]
    /// Explanation: Events in chronological order go as follows: 
    /// - At second 0, task 0 is added and processed using server 1 until 
    ///   second 2.
    /// - At second 1, task 1 is added and processed using server 4 until 
    ///   second 2.
    /// - At second 2, servers 1 and 4 become free. Task 2 is added and 
    ///   processed using server 1 until second 4. 
    /// - At second 3, task 3 is added and processed using server 4 until 
    ///   second 7.
    /// - At second 4, server 1 becomes free. Task 4 is added and processed 
    ///   using server 1 until second 9. 
    /// - At second 5, task 5 is added and processed using server 3 until 
    ///   second 7.
    /// - At second 6, task 6 is added and processed using server 2 until 
    ///   second 7.
    ///
    ///  Constraints:
    /// 1. servers.length == n
    /// 2. tasks.length == m
    /// 3. 1 <= n, m <= 2 * 10^5
    /// 4. 1 <= servers[i], tasks[j] <= 2 * 10^5
    /// </summary>
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks);

    /// <summary>
    /// Leet code 1964. Find the Longest Valid Obstacle Course at Each Position
    ///                                                
    /// Hard
    /// 
    /// You want to build some obstacle courses. You are given a 0-indexed 
    /// integer array obstacles of length n, where obstacles[i] describes 
    /// the height of the ith obstacle.
    /// 
    /// For every index i between 0 and n - 1 (inclusive), find the length 
    /// of the longest obstacle course in obstacles such that:
    /// 
    /// You choose any number of obstacles between 0 and i inclusive.
    /// You must include the ith obstacle in the course.
    /// You must put the chosen obstacles in the same order as they appear in 
    /// obstacles.
    /// Every obstacle (except the first) is taller than or the same height as 
    /// the obstacle immediately before it.
    /// Return an array ans of length n, where ans[i] is the length of the 
    /// longest obstacle course for index i as described above.
    ///
    /// Example 1:
    /// Input: obstacles = [1,2,3,2]
    /// Output: [1,2,3,3]
    /// Explanation: The longest valid obstacle course at each position is:
    /// - i = 0: [1], [1] has length 1.
    /// - i = 1: [1,2], [1,2] has length 2.
    /// - i = 2: [1,2,3], [1,2,3] has length 3.
    /// - i = 3: [1,2,3,2], [1,2,2] has length 3.
    ///
    /// Example 2:
    /// Input: obstacles = [2,2,1]
    /// Output: [1,2,1]
    /// Explanation: The longest valid obstacle course at each position is:
    /// - i = 0: [2], [2] has length 1.
    /// - i = 1: [2,2], [2,2] has length 2.
    /// - i = 2: [2,2,1], [1] has length 1.
    ///
    /// Example 3:
    /// Input: obstacles = [3,1,5,6,4,2]
    /// Output: [1,1,2,3,2,2]
    /// Explanation: The longest valid obstacle course at each position is:
    /// - i = 0: [3], [3] has length 1.
    /// - i = 1: [3,1], [1] has length 1.
    /// - i = 2: [3,1,5], [3,5] has length 2. [1,5] is also valid.
    /// - i = 3: [3,1,5,6], [3,5,6] has length 3. [1,5,6] is also valid.
    /// - i = 4: [3,1,5,6,4], [3,4] has length 2. [1,4] is also valid.
    /// - i = 5: [3,1,5,6,4,2], [1,2] has length 2.
    /// 
    /// Constraints:
    /// 1. n == obstacles.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= obstacles[i] <= 10^7
    /// </summary>
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles);

    /// <summary>
    /// Leet code 2037. Minimum Number of Moves to Seat Everyone
    ///                                                
    /// Easy
    /// 
    /// There are n seats and n students in a room. You are given an array 
    /// seats of length n, where seats[i] is the position of the ith seat. 
    /// You are also given the array students of length n, where students[j] 
    /// is the position of the jth student.
    ///
    /// You may perform the following move any number of times:
    ///
    /// Increase or decrease the position of the ith student by 1 (i.e., 
    /// moving the ith student from position x to x + 1 or x - 1)
    /// Return the minimum number of moves required to move each student to 
    /// a seat such that no two students are in the same seat.
    ///
    /// Note that there may be multiple seats or students in the same 
    /// position at the beginning.
    /// 
    /// Example 1:
    /// Input: seats = [3,1,5], students = [2,7,4]
    /// Output: 4
    /// Explanation: The students are moved as follows:
    /// - The first student is moved from from position 2 to position 1 
    ///   using 1 move.
    /// - The second student is moved from from position 7 to position 5 
    ///   using 2 moves.
    /// - The third student is moved from from position 4 to position 3 
    ///   using 1 move.
    /// In total, 1 + 2 + 1 = 4 moves were used.
    ///
    /// Example 2:
    /// Input: seats = [4,1,5,9], students = [1,3,2,6]
    /// Output: 7
    /// Explanation: The students are moved as follows:
    /// - The first student is not moved.
    /// - The second student is moved from from position 3 to position 4 
    ///   using 1 move.
    /// - The third student is moved from from position 2 to position 5 
    ///   using 3 moves.
    /// - The fourth student is moved from from position 6 to position 9 
    ///   using 3 moves.
    /// In total, 0 + 1 + 3 + 3 = 7 moves were used.
    ///
    /// Example 3:
    /// Input: seats = [2,2,6,6], students = [1,3,2,6]
    /// Output: 4
    /// Explanation: Note that there are two seats at position 2 and two 
    /// seats at position 6.
    /// The students are moved as follows:
    /// - The first student is moved from from position 1 to position 2 
    ///   using 1 move.
    /// - The second student is moved from from position 3 to position 6 
    ///   using 3 moves.
    /// - The third student is not moved.
    /// - The fourth student is not moved.
    /// In total, 1 + 3 + 0 + 0 = 4 moves were used.
    /// 
    /// Constraints:
    /// 1. n == seats.length == students.length
    /// 2. 1 <= n <= 100
    /// 3. 1 <= seats[i], students[j] <= 100
    /// </summary>
    int minMovesToSeat(vector<int>& seats, vector<int>& students);

    /// <summary>
    /// Leet code 1984. Minimum Difference Between Highest and Lowest of K 
    ///                 Scores
    ///                                                
    /// Easy
    /// 
    /// You are given a 0-indexed integer array nums, where nums[i] 
    /// represents the score of the ith student. You are also given an 
    /// integer k.
    ///
    /// Pick the scores of any k students from the array so that the 
    /// difference between the highest and the lowest of the k scores is 
    /// minimized.
    /// 
    /// Return the minimum possible difference.
    /// 
    /// Example 1:
    /// Input: nums = [90], k = 1
    /// Output: 0
    /// Explanation: There is one way to pick score(s) of one student:
    /// - [90]. The difference between the highest and lowest score 
    ///   is 90 - 90 = 0.
    /// The minimum possible difference is 0.
    ///
    /// Example 2:
    /// Input: nums = [9,4,1,7], k = 2
    /// Output: 2
    /// Explanation: There are six ways to pick score(s) of two students:
    /// - [9,4,1,7]. The difference between the highest and lowest 
    ///   score is 9 - 4 = 5.
    /// - [9,4,1,7]. The difference between the highest and lowest 
    /// score is 9 - 1 = 8.
    /// - [9,4,1,7]. The difference between the highest and lowest 
    ///   score is 9 - 7 = 2.
    /// - [9,4,1,7]. The difference between the highest and lowest 
    ///   score is 4 - 1 = 3.
    /// - [9,4,1,7]. The difference between the highest and lowest 
    ///   score is 7 - 4 = 3.
    /// - [9,4,1,7]. The difference between the highest and lowest 
    ///   score is 7 - 1 = 6.
    /// The minimum possible difference is 2.
    ///
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 1000
    /// 2. 0 <= nums[i] <= 10^5
    /// </summary>
    int minimumDifference(vector<int>& nums, int k);

    /// <summary>
    /// Leet code 1921. Eliminate Maximum Number of Monsters
    ///                                                
    /// Medium
    /// 
    /// You are playing a video game where you are defending your city from 
    /// a group of n monsters. You are given a 0-indexed integer array dist 
    /// of size n, where dist[i] is the initial distance in kilometers of 
    /// the ith monster from the city.
    ///
    /// The monsters walk toward the city at a constant speed. The speed of 
    /// each monster is given to you in an integer array speed of size n, 
    /// where speed[i] is the speed of the ith monster in kilometers per 
    /// minute.
    ///
    /// You have a weapon that, once fully charged, can eliminate a single 
    /// monster. However, the weapon takes one minute to charge.The weapon 
    /// is fully charged at the very start.
    ///
    /// You lose when any monster reaches your city. If a monster reaches 
    /// the city at the exact moment the weapon is fully charged, it counts 
    /// as a loss, and the game ends before you can use your weapon.
    ///
    /// Return the maximum number of monsters that you can eliminate before 
    /// you lose, or n if you can eliminate all the monsters before they 
    /// reach the city.
    /// 
    /// Example 1:
    /// Input: dist = [1,3,4], speed = [1,1,1]
    /// Output: 3
    /// Explanation:
    /// In the beginning, the distances of the monsters are [1,3,4]. You 
    /// eliminate the first monster.
    /// After a minute, the distances of the monsters are [X,2,3]. You 
    /// eliminate the second monster.
    /// After a minute, the distances of the monsters are [X,X,2]. You 
    /// eliminate the thrid monster.
    /// All 3 monsters can be eliminated.
    ///
    /// Example 2:
    /// Input: dist = [1,1,2,3], speed = [1,1,1,1]
    /// Output: 1
    /// Explanation:
    /// In the beginning, the distances of the monsters are [1,1,2,3]. 
    /// You eliminate the first monster.
    /// After a minute, the distances of the monsters are [X,0,1,2], so you 
    /// lose.
    /// You can only eliminate 1 monster.
    ///
    /// Example 3:
    /// Input: dist = [3,2,4], speed = [5,3,2]
    /// Output: 1
    /// Explanation:
    /// In the beginning, the distances of the monsters are [3,2,4]. 
    /// You eliminate the first monster.
    /// After a minute, the distances of the monsters are [X,0,2], so you lose.
    /// You can only eliminate 1 monster.
    /// 
    /// Constraints:
    /// 1. n == dist.length == speed.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= dist[i], speed[i] <= 10^5
    /// </summary>
    int eliminateMaximum(vector<int>& dist, vector<int>& speed);

    /// <summary>
    /// Leet 1985. Find the Kth Largest Integer in the Array
    ///                                                                 
    /// Medium
    /// 
    /// You are given an array of strings nums and an integer k. Each string 
    /// in nums represents an integer without leading zeros.
    ///
    /// Return the string that represents the kth largest integer in nums.
    ///
    /// Note: Duplicate numbers should be counted distinctly. For example, if 
    /// nums is ["1","2","2"], "2" is the first largest integer, "2" is the 
    /// second-largest integer, and "1" is the third-largest integer. 
    /// 
    /// Example 1:
    /// Input: nums = ["3","6","7","10"], k = 4
    /// Output: "3"
    /// Explanation:
    /// The numbers in nums sorted in non-decreasing order are 
    /// ["3","6","7","10"].
    /// The 4th largest integer in nums is "3".
    /// Example 2:
    ///
    /// Input: nums = ["2","21","12","1"], k = 3
    /// Output: "2"
    /// Explanation:
    /// The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
    /// The 3rd largest integer in nums is "2".
    /// Example 3:
    ///
    /// Input: nums = ["0","0"], k = 2
    /// Output: "0"
    /// Explanation:
    /// The numbers in nums sorted in non-decreasing order are ["0","0"].
    /// The 2nd largest integer in nums is "0".
    /// 
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 10^4
    /// 2. 1 <= nums[i].length <= 100 
    /// 3. nums[i] consists of only digits.
    /// 4. nums[i] will not have any leading zeros.
    /// </summary>
    string kthLargestNumber(vector<string>& nums, int k);

    /// <summary>
    /// Leet Code 1942. The Number of the Smallest Unoccupied Chair
    ///                                                                 
    /// Medium
    /// 
    /// There is a party where n friends numbered from 0 to n - 1 are 
    /// attending. There is an infinite number of chairs in this party 
    /// that are numbered from 0 to infinity. When a friend arrives at 
    /// the party, they sit on the unoccupied chair with the smallest 
    /// number.
    ///
    /// For example, if chairs 0, 1, and 5 are occupied when a friend 
    /// comes, they will sit on chair number 2.
    /// When a friend leaves the party, their chair becomes unoccupied 
    /// at the moment they leave. If another friend arrives at that 
    /// same moment, they can sit in that chair.
    ///
    /// You are given a 0-indexed 2D integer array times where 
    /// times[i] = [arrivali, leavingi], indicating the arrival and 
    /// leaving times of the ith friend respectively, and an integer 
    /// targetFriend. All arrival times are distinct.
    ///
    /// Return the chair number that the friend numbered targetFriend 
    /// will sit on.
    ///
    /// Example 1:
    /// Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
    /// Output: 1 
    /// Explanation: 
    /// - Friend 0 arrives at time 1 and sits on chair 0.
    /// - Friend 1 arrives at time 2 and sits on chair 1.
    /// - Friend 1 leaves at time 3 and chair 1 becomes empty.
    /// - Friend 0 leaves at time 4 and chair 0 becomes empty.
    /// - Friend 2 arrives at time 4 and sits on chair 0.
    /// Since friend 1 sat on chair 1, we return 1.
    ///
    /// Example 2:
    /// Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
    /// Output: 2
    /// Explanation: 
    /// - Friend 1 arrives at time 1 and sits on chair 0.
    /// - Friend 2 arrives at time 2 and sits on chair 1.
    /// - Friend 0 arrives at time 3 and sits on chair 2.
    /// - Friend 1 leaves at time 5 and chair 0 becomes empty.
    /// - Friend 2 leaves at time 6 and chair 1 becomes empty.
    /// - Friend 0 leaves at time 10 and chair 2 becomes empty. 
    /// Since friend 0 sat on chair 2, we return 2.
    /// 
    /// Constraints:
    /// 1. n == times.length
    /// 2. 2 <= n <= 104
    /// 3. times[i].length == 2
    /// 4. 1 <= arrivali < leavingi <= 10^5
    /// 5. 0 <= targetFriend <= n - 1
    /// 6. Each arrivali time is distinct.
    /// </summary>
    int smallestChair(vector<vector<int>>& times, int targetFriend);

    /// <summary>
    /// Leet Code 1962. Remove Stones to Minimize the Total
    ///                                                                 
    /// Medium
    /// 
    /// You are given a 0-indexed integer array piles, where piles[i] 
    /// represents the number of stones in the ith pile, and an integer 
    /// k. You should apply the following operation exactly k times:
    ///
    /// Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
    /// Notice that you can apply the operation on the same pile more than 
    /// once.
    /// 
    /// Return the minimum possible total number of stones remaining after 
    /// applying the k operations.
    ///
    /// floor(x) is the greatest integer that is smaller than or equal to x 
    /// (i.e., rounds x down).
    ///
    /// Example 1:
    /// Input: piles = [5,4,9], k = 2
    /// Output: 12
    /// Explanation: Steps of a possible scenario are:
    /// - Apply the operation on pile 2. The resulting piles are [5,4,5].
    /// - Apply the operation on pile 0. The resulting piles are [3,4,5].
    /// The total number of stones in [3,4,5] is 12.
    ///
    /// Example 2:
    /// Input: piles = [4,3,6,7], k = 3
    /// Output: 12
    /// Explanation: Steps of a possible scenario are:
    /// - Apply the operation on pile 2. The resulting piles are [4,3,3,7].
    /// - Apply the operation on pile 3. The resulting piles are [4,3,3,4].
    /// - Apply the operation on pile 0. The resulting piles are [2,3,3,4].
    /// The total number of stones in [2,3,3,4] is 12.
    /// 
    /// Constraints:
    /// 1. 1 <= piles.length <= 10^5
    /// 2. 1 <= piles[i] <= 10^4
    /// 3. 1 <= k <= 10^5
    /// </summary>
    int minStoneSum(vector<int>& piles, int k);

    /// <summary>
    /// Leet Code 1996. The Number of Weak Characters in the Game
    ///                                                                 
    /// Medium
    /// 
    /// You are playing a game that contains multiple characters, and each of 
    /// the characters has two main properties: attack and defense. You are 
    /// given a 2D integer array properties where properties[i] = [attacki, 
    /// defensei] represents the properties of the ith character in the game.
    ///
    /// A character is said to be weak if any other character has both attack 
    /// and defense levels strictly greater than this character's attack and 
    /// defense levels. More formally, a character i is said to be weak if 
    /// there exists another character j where attackj > attacki and 
    /// defensej > defensei.
    ///  
    /// Return the number of weak characters.
    ///
    /// Example 1:
    /// Input: properties = [[5,5],[6,3],[3,6]]
    /// Output: 0
    /// Explanation: No character has strictly greater attack and defense 
    /// than the other.
    ///
    /// Example 2:
    /// Input: properties = [[2,2],[3,3]]
    /// Output: 1
    /// Explanation: The first character is weak because the second character 
    /// has a strictly greater attack and defense.
    ///
    /// Example 3:
    /// Input: properties = [[1,5],[10,4],[4,3]]
    /// Output: 1
    /// Explanation: The third character is weak because the second character 
    /// has a strictly greater attack and defense.
    ///
    /// Constraints:
    /// 1. 2 <= properties.length <= 10^5
    /// 2. properties[i].length == 2
    /// 3. 1 <= attacki, defensei <= 10^5
    /// </summary>
    int numberOfWeakCharacters(vector<vector<int>>& properties);

    /// <summary>
    /// Leet Code 1966. Binary Searchable Numbers in an Unsorted Array 
    ///                                                                 
    /// Medium
    /// 
    /// Consider a function that implements an algorithm similar to Binary 
    /// Search. The function has two input parameters: sequence is a sequence 
    /// of integers, and target is an integer value. The purpose of the 
    /// function is to find if the target exists in the sequence.
    ///
    /// The pseudocode of the function is as follows:
    ///
    /// func(sequence, target)
    /// while sequence is not empty
    /// randomly choose an element from sequence as the pivot
    /// if pivot = target, return true
    /// else if pivot < target, remove pivot and all elements to its left 
    /// from the sequence
    /// else, remove pivot and all elements to its right from the sequence
    /// end while
    /// return false
    /// When the sequence is sorted, the function works correctly for all 
    /// values. When the sequence is not sorted, the function does not work 
    /// for all values, but may still work for some values.
    /// Given an integer array nums, representing the sequence, that contains 
    /// unique numbers and may or may not be sorted, return the number of 
    /// values that are guaranteed to be found using the function, for every 
    /// possible pivot selection.
    /// 
    /// Example 1:
    /// Input: nums = [7]
    /// Output: 1
    /// Explanation: 
    /// Searching for value 7 is guaranteed to be found.
    /// Since the sequence has only one element, 7 will be chosen as the 
    /// pivot. Because the pivot equals the target, the function will return 
    /// true.
    ///
    /// Example 2:
    /// Input: nums = [-1,5,2]
    /// Output: 1
    /// Explanation: 
    /// Searching for value -1 is guaranteed to be found.
    /// If -1 was chosen as the pivot, the function would return true.
    /// If 5 was chosen as the pivot, 5 and 2 would be removed. In the next 
    /// loop, the sequence would have only -1 and the function would return 
    /// true.
    /// If 2 was chosen as the pivot, 2 would be removed. In the next loop, 
    /// the sequence would have -1 and 5. No matter which number was chosen 
    /// as the next pivot, the function would find -1 and return true.
    ///
    /// Searching for value 5 is NOT guaranteed to be found.
    /// If 2 was chosen as the pivot, -1, 5 and 2 would be removed. The 
    /// sequence would be empty and the function would return false.
    ///
    /// Searching for value 2 is NOT guaranteed to be found.
    /// If 5 was chosen as the pivot, 5 and 2 would be removed. In the next 
    /// loop, the sequence would have only -1 and the function would 
    /// return false.
    ///
    /// Because only -1 is guaranteed to be found, you should return 1.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^5 <= nums[i] <= 10^5
    /// 3. All the values of nums are unique.
    /// Follow-up: If nums has duplicates, would you modify your algorithm? 
    /// If so, how?
    /// </summary>
    int binarySearchableNumbers(vector<int>& nums);

    /// <summary>
    /// Leet Code 1968. Array With Elements Not Equal to Average of Neighbors 
    ///                                                                 
    /// Medium
    /// 
    /// You are given a 0-indexed array nums of distinct integers. You want to 
    /// rearrange the elements in the array such that every element in the 
    /// rearranged array is not equal to the average of its neighbors.
    ///
    /// More formally, the rearranged array should have the property such that 
    /// for every i in the range 1 <= i < nums.length - 1, (nums[i-1] + 
    /// nums[i+1]) / 2 is not equal to nums[i].
    ///
    /// Return any rearrangement of nums that meets the requirements.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,4,5]
    /// Output: [1,2,4,5,3]
    /// Explanation:
    /// When i=1, nums[i] = 2, and the average of its neighbors is 
    /// (1+4) / 2 = 2.5.
    /// When i=2, nums[i] = 4, and the average of its neighbors is 
    /// (2+5) / 2 = 3.5.
    /// When i=3, nums[i] = 5, and the average of its neighbors is 
    /// (4+3) / 2 = 3.5.
    ///
    /// Example 2:
    /// Input: nums = [6,2,0,9,7]
    /// Output: [9,7,6,2,0]
    /// Explanation:
    /// When i=1, nums[i] = 7, and the average of its neighbors is 
    /// (9+6) / 2 = 7.5.
    /// When i=2, nums[i] = 6, and the average of its neighbors is 
    /// (7+2) / 2 = 4.5.
    /// When i=3, nums[i] = 2, and the average of its neighbors is 
    /// (6+0) / 2 = 3.
    /// 
    /// Constraints:
    /// 1. 3 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^5
    /// </summary>
    vector<int> rearrangeArray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2098. Subsequence of Size K With the Largest Even Sum
    ///                                                                 
    /// Medium
    ///
    /// You are given an integer array nums and an integer k. Find the 
    /// largest even sum of any subsequence of nums that has a length of k.
    ///
    /// Return this sum, or -1 if such a sum does not exist.
    ///
    /// A subsequence is an array that can be derived from another array 
    /// by deleting some or no elements without changing the order of the 
    /// remaining elements.
    /// 
    /// Example 1:
    /// Input: nums = [4,1,5,3,1], k = 3
    /// Output: 12
    /// Explanation:
    /// The subsequence with the largest possible even sum is [4,5,3]. It 
    /// has a sum of 4 + 5 + 3 = 12.
    ///
    /// Example 2:
    /// Input: nums = [4,6,2], k = 3
    /// Output: 12
    /// Explanation:
    /// The subsequence with the largest possible even sum is [4,6,2]. It 
    /// has a sum of 4 + 6 + 2 = 12.
    ///
    /// Example 3:
    /// Input: nums = [1,3,5], k = 1
    /// Output: -1
    /// Explanation:
    /// No subsequence of nums with length 1 has an even sum.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^5
    /// 3. 1 <= k <= nums.length
    /// </summary>
    long long largestEvenSum(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2111. Minimum Operations to Make the Array K-Increasing
    ///                                                                 
    /// Hard
    ///
    /// You are given a 0-indexed array arr consisting of n positive 
    /// integers, and a positive integer k.
    ///
    /// The array arr is called K-increasing if arr[i-k] <= arr[i] holds 
    /// for every index i, where k <= i <= n-1.
    ///
    /// For example, arr = [4, 1, 5, 2, 6, 2] is K-increasing for k = 2 
    /// because:
    /// arr[0] <= arr[2] (4 <= 5)
    /// arr[1] <= arr[3] (1 <= 2)
    /// arr[2] <= arr[4] (5 <= 6)
    /// arr[3] <= arr[5] (2 <= 2)
    /// However, the same arr is not K-increasing for k = 1 (because 
    /// arr[0] > arr[1]) or k = 3 (because arr[0] > arr[3]).
    /// In one operation, you can choose an index i and change arr[i] into 
    /// any positive integer.
    ///
    /// Return the minimum number of operations required to make the array 
    /// K-increasing for the given k.
    ///
    /// Example 1:
    ///
    /// Input: arr = [5,4,3,2,1], k = 1
    /// Output: 4
    /// Explanation:
    /// For k = 1, the resultant array has to be non-decreasing.
    /// Some of the K-increasing arrays that can be formed are [5,6,7,8,9], 
    /// [1,1,1,1,1], [2,2,3,4,4]. All of them require 4 operations.
    /// It is suboptimal to change the array to, for example, [6,7,8,9,10]
    /// because it would take 5 operations.
    /// It can be shown that we cannot make the array K-increasing in less 
    /// than 4 operations.
    ///
    /// Example 2:
    /// Input: arr = [4,1,5,2,6,2], k = 2
    /// Output: 0
    /// Explanation:
    /// This is the same example as the one in the problem description.
    /// Here, for every index i where 2 <= i <= 5, arr[i-2] <= arr[i].
    /// Since the given array is already K-increasing, we do not need to 
    /// perform any operations.
    ///
    /// Example 3:
    /// Input: arr = [4,1,5,2,6,2], k = 3
    /// Output: 2
    /// Explanation:
    /// Indices 3 and 5 are the only ones not satisfying arr[i-3] <= arr[i] 
    /// for 3 <= i <= 5.
    /// One of the ways we can make the array K-increasing is by changing 
    /// arr[3] to 4 and arr[5] to 5.
    /// The array will now be [4,1,5,4,6,5].
    /// Note that there can be other ways to make the array K-increasing, but 
    /// none of them require less than 2 operations.
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 1 <= arr[i], k <= arr.length
    /// </summary>
    int kIncreasing(vector<int>& arr, int k);

    /// <summary>
    /// Leet Code 2070. Most Beautiful Item for Each Query
    ///                                                                 
    /// Medium
    ///
    /// You are given a 2D integer array items where items[i] = 
    /// [pricei, beautyi] denotes the price and beauty of an item respectively.
    ///
    /// You are also given a 0-indexed integer array queries. For each 
    /// queries[j], you want to determine the maximum beauty of an item whose 
    /// price is less than or equal to queries[j]. If no such item exists, 
    /// then the answer to this query is 0.
    ///
    /// Return an array answer of the same length as queries where answer[j] 
    /// is the answer to the jth query.
    /// 
    /// Example 1:
    /// Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
    /// Output: [2,4,5,5,6,6]
    /// Explanation:
    /// - For queries[0]=1, [1,2] is the only item which has price <= 1. 
    ///   Hence, the answer for this query is 2.
    /// - For queries[1]=2, the items which can be considered are [1,2] 
    ///   and [2,4]. 
    /// The maximum beauty among them is 4.
    /// - For queries[2]=3 and queries[3]=4, the items which can be considered 
    ///   are [1,2], [3,2], [2,4], and [3,5].
    /// The maximum beauty among them is 5.
    /// - For queries[4]=5 and queries[5]=6, all items can be considered.
    /// Hence, the answer for them is the maximum beauty of all items, i.e., 6.
    ///
    /// Example 2:
    /// Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
    /// Output: [4]
    /// Explanation: 
    /// The price of every item is equal to 1, so we choose the item with 
    /// the maximum beauty 4. 
    /// Note that multiple items can have the same price and/or beauty.  
    /// Example 3:
    /// Input: items = [[10,1000]], queries = [5]
    /// Output: [0]
    /// Explanation:
    /// No item has a price less than or equal to 5, so no item can be chosen.
    /// Hence, the answer to the query is 0.
    /// 
    /// Constraints:
    /// 1. 1 <= items.length, queries.length <= 10^5
    /// 2. items[i].length == 2
    /// 3. 1 <= pricei, beautyi, queries[j] <= 10^9
    /// </summary>
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries);

    /// <summary>
    /// Leet code #164. Maximum Gap 
    /// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
    /// Try to solve it in linear time/space.
    /// Return 0 if the array contains less than 2 elements.
    /// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    /// </summary>
    int maximumGap(vector<int>& nums);

    /// <summary>
    /// Leet Code 75. Sort Colors
    /// 
    /// Medium
    ///
    /// Given an array nums with n objects colored red, white, or blue, sort 
    /// them in-place so that objects of the same color are adjacent, with 
    /// the colors in the order red, white, and blue.
    ///
    /// We will use the integers 0, 1, and 2 to represent the color red, 
    /// white, and blue, respectively.
    ///
    /// You must solve this problem without using the library's sort function.
    ///
    /// Example 1:
    /// Input: nums = [2,0,2,1,1,0]
    /// Output: [0,0,1,1,2,2]
    ///
    /// Example 2:
    /// Input: nums = [2,0,1]
    /// Output: [0,1,2]
    ///
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 300
    /// 3. nums[i] is either 0, 1, or 2.
    /// </summary>
    void sortColors(vector<int>& nums);

    /// <summary>
    /// Leet Code 274. H-Index
    /// 
    /// Medium
    ///
    /// Given an array of integers citations where citations[i] is the number 
    /// of citations a researcher received for their ith paper, return the 
    /// researcher's h-index.
    ///
    /// According to the definition of h-index on Wikipedia: The h-index is 
    /// defined as the maximum value of h such that the given researcher has 
    /// published at least h papers that have each been cited at least h times.
    ///
    /// Example 1:
    /// Input: citations = [3,0,6,1,5]
    /// Output: 3
    /// Explanation: [3,0,6,1,5] means the researcher has 5 papers in total 
    /// and each of them had received 3, 0, 6, 1, 5 citations respectively.
    /// Since the researcher has 3 papers with at least 3 citations each and 
    /// the remaining two with no more than 3 citations each, their 
    /// h-index is 3.
    ///
    /// Example 2:
    /// Input: citations = [1,3,1]
    /// Output: 1
    ///
    /// Constraints:
    /// 1. n == citations.length
    /// 2. 1 <= n <= 5000
    /// 3. 0 <= citations[i] <= 1000
    /// </summary>
    int hIndex(vector<int>& citations);

    /// <summary>
    /// Leet code #324. Wiggle Sort II  
    /// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3].... 
    /// Example:
    /// (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
    /// (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2]. 
    /// Note:
    /// You may assume all input has valid answer. 
    /// Follow Up:
    /// Can you do it in O(n) time and/or in-place with O(1) extra space? 
    /// </summary>
    void wiggleSortII(vector<int>& nums);

    /// <summary>
    /// Leet code #179. Largest Number        
    /// Given a list of non negative integers, arrange them such that they form the largest number.  
    /// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
    /// Note: The result may be very large, so you need to return a string instead of an integer.
    /// </summary>
    string largestNumber(vector<int>& nums);

    /// <summary>
    /// Leet Code 406. Queue Reconstruction by Height
    /// 
    /// Medium
    ///
    /// You are given an array of people, people, which are the attributes of 
    /// some people in a queue (not necessarily in order). Each 
    /// people[i] = [hi, ki] represents the ith person of height hi with 
    /// exactly ki other people in front who have a height greater than or 
    /// equal to hi.
    ///
    /// Reconstruct and return the queue that is represented by the input 
    /// array people. The returned queue should be formatted as an array 
    /// queue, where queue[j] = [hj, kj] is the attributes of the jth person 
    /// in the queue (queue[0] is the person at the front of the queue).
    ///
    /// Example 1:
    /// Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    /// Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
    /// Explanation:
    /// Person 0 has height 5 with no other people taller or the same height 
    /// in front.
    /// Person 1 has height 7 with no other people taller or the same height 
    /// in front.
    /// Person 2 has height 5 with two persons taller or the same height in 
    /// front, which is person 0 and 1.
    /// Person 3 has height 6 with one person taller or the same height in 
    /// front, which is person 1.
    /// Person 4 has height 4 with four people taller or the same height in 
    /// front, which are people 0, 1, 2, and 3.
    /// Person 5 has height 7 with one person taller or the same height in 
    /// front, which is person 1.
    /// Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
    ///
    /// Example 2:
    /// Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
    /// Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
    ///
    /// Constraints:
    /// 1. 1 <= people.length <= 2000
    /// 2. 0 <= hi <= 10^6
    /// 3. 0 <= ki < people.length
    /// 4. It is guaranteed that the queue can be reconstructed.
    /// </summary>
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people);

    /// <summary>
    /// Leet code #220. Contains Duplicate III
    /// Given an array of integers, find out whether there are two distinct 
    /// indices i and j in the array such that the difference between 
    /// nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
    /// </summary>
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// 
    /// You are given an integer array nums and you have to return a new counts array. 
    /// The counts array has the property where counts[i] is the number of smaller 
    /// elements to the right of nums[i]. 
    /// Example:
    /// Given nums = [5, 2, 6, 1]
    /// To the right of 5 there are 2 smaller elements (2 and 1).
    /// To the right of 2 there is only 1 smaller element (1).
    /// To the right of 6 there is 1 smaller element (1).
    /// To the right of 1 there is 0 smaller element.
    /// Return the array [2, 1, 1, 0]. 
    /// </summary>
    vector<int> countSmallerII(vector<int>& nums);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// </summary>
    void addBIT(int index, vector<long long>& accu_slot, long long val = 1);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// </summary>
    long long sumBIT(int index, vector<long long>& accu_slot);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// 
    /// You are given an integer array nums and you have to return a new counts array. 
    /// The counts array has the property where counts[i] is the number of smaller 
    /// elements to the right of nums[i]. 
    /// Example:
    /// Given nums = [5, 2, 6, 1]
    /// To the right of 5 there are 2 smaller elements (2 and 1).
    /// To the right of 2 there is only 1 smaller element (1).
    /// To the right of 6 there is 1 smaller element (1).
    /// To the right of 1 there is 0 smaller element.
    /// Return the array [2, 1, 1, 0]. 
    /// </summary>
    vector<int> countSmallerIV(vector<int>& nums);

    /// <summary>
    /// Leet Code 280. Wiggle Sort
    /// 
    /// Medium
    ///
    /// Given an integer array nums, reorder it such that 
    /// nums[0] <= nums[1] >= nums[2] <= nums[3]
    ///
    /// You may assume the input array always has a valid answer.
    /// Example 1:
    /// Input: nums = [3,5,2,1,6,4]
    /// Output: [3,5,1,6,2,4]
    /// Explanation: [1,6,2,5,3,4] is also accepted.
    ///
    /// Example 2:
    /// Input: nums = [6,6,5,6,3,8]
    /// Output: [6,6,5,6,3,8]
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 5 * 10^4
    /// 2. 0 <= nums[i] <= 10^4
    /// 3. It is guaranteed that there will be an answer for the given input 
    ///    nums.
    /// </summary>
    void wiggleSort(vector<int>& nums);

    /// <summary>
    /// Leet code # 440. K-th Smallest in Lexicographical Order  
    ///
    /// Given integers n and k, find the lexicographically k-th smallest 
    /// integer in the range from 1 to n. 
    /// Note: 1 <= k <= n <= 109.
    /// 
    /// Example: 
    /// Input:
    /// n: 13   k: 2
    ///
    /// Output:
    /// 10
    /// 
    /// Explanation:
    /// The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], 
    /// so the second smallest number is 10.
    /// </summary>
    int findKthNumber(int n, int k);

    /// <summary>
    /// Leet code #480. Sliding Window Median
    ///
    /// Median is the middle value in an ordered integer list. If the size of 
    /// the list is even, there is no middle value. So the median is the mean 
    /// of the two middle value.
    /// Examples: 
    /// [2,3,4] , the median is 3
    /// [2,3], the median is (2 + 3) / 2 = 2.5 
    /// Given an array nums, there is a sliding window of size k which is 
    /// moving from the very left of the array to the very right. You can 
    /// only see the k numbers in the window. Each time the sliding window 
    /// moves right by one position. Your job is to output the median array 
    /// for each window in the original array.
    ///
    /// For example,
    /// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
    /// Window position                Median
    /// ---------------               -----
    /// [1  3  -1] -3  5  3  6  7       1
    /// 1 [3  -1  -3] 5  3  6  7       -1
    /// 1  3 [-1  -3  5] 3  6  7       -1
    /// 1  3  -1 [-3  5  3] 6  7       3
    /// 1  3  -1  -3 [5  3  6] 7       5
    /// 1  3  -1  -3  5 [3  6  7]      6
    ///
    /// Therefore, return the median sliding window as [1,-1,-1,3,5,6].
    /// Note: 
    /// You may assume k is always valid, ie: 1 <= k <= input array's size for non-empty 
    /// array.
    /// </summary>
    vector<double> medianSlidingWindow(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #556. Next Greater Element III  
    /// 
    /// Given a positive 32-bit integer n, you need to find the smallest 32-bit 
    /// integer which has exactly the same digits existing in the integer n and 
    /// is greater in value than n. If no such positive 32-bit integer exists, 
    /// you need to return -1.
    /// Example 1:
    /// Input: 12
    /// Output: 21
    ///
    /// Example 2:
    /// Input: 21
    /// Output: -1
    /// </summary>
    int nextGreaterElement(int n);

    /// <summary>
    /// Leet code #321. Create Maximum Number 
    /// </summary>
    string createMaxNumber(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #321. Create Maximum Number 
    /// </summary>
    void createMaxNumber(string num1, string num2, string& result);

    /// <summary>
    /// Leet code #321. Create Maximum Number 
    /// 
    /// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of 
    /// length k <= m + n from digits of the two. The relative order of the digits from the same array must be 
    /// preserved. Return an array of the k digits. You should try to optimize your time and space complexity. 
    /// Example 1: 
    /// nums1 = [3, 4, 6, 5]
    /// nums2 = [9, 1, 2, 5, 8, 3] 
    /// k = 5
    /// return [9, 8, 6, 5, 3]
    /// 
    /// Example 2:
    /// nums1 = [6, 7]
    /// nums2 = [6, 0, 4]
    /// k = 5
    /// return [6, 7, 6, 0, 4] 
    /// 
    /// Example 3:
    /// nums1 = [3, 9]
    /// nums2 = [8, 9]
    /// k = 3
    /// return [9, 8, 9]
    /// </summary>
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);

    /// <summary>
    /// Leet code #555. Split Assembled Strings 
    /// 
    /// Given a list of strings, you could assemble these strings together into 
    /// a loop. Among all the possible loops, you need to find the 
    /// lexicographically biggest string after cutting and making one 
    /// breakpoint of the loop, which will make a looped string into a regular one.
    ///
    /// So, to find the lexicographically biggest string, you need to experience 
    /// two phases: 
    /// 1.Assemble all the strings into a loop, where you can reverse some strings 
    ///   or not and connect them in the same order as given.
    /// 2.Cut and make one breakpoint in any place of the loop, which will make a 
    ///   looped string into a regular string starting from the character at the 
    ///   cutting point. 
    /// And your job is to find the lexicographically biggest one among all the 
    /// regular strings.
    /// 
    /// Example:
    /// Input: "abc", "xyz"
    /// Output: "zyxcba"
    /// Explanation: You can get the looped string "-abcxyz-", "-abczyx-", 
    /// "-cbaxyz-", "-cbazyx-", 
    /// where '-' represents the looped status. 
    /// The answer string came from the fourth looped one, 
    /// where you could cut from the middle and get "zyxcba".
    /// Note:
    /// 1.The input strings will only contain lowercase letters.
    /// 2.The total length of all the strings will not over 1000.
    /// </summary>
    string splitLoopedString(vector<string>& strs);

    /// <summary>
    /// Leet code #561. Array Partition I Add to List?????? 
    /// 
    /// Given an array of 2n integers, your task is to group these integers 
    /// into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which 
    /// makes sum of min(ai, bi) for all i from 1 to n as large as possible.
    ///
    /// Example 1:
    /// Input: [1,4,3,2]
    ///
    /// Output: 4
    /// Explanation: n is 2, and the maximum sum of pairs is 4.
    /// Note:
    /// n is a positive integer, which is in the range of [1, 10000].
    /// All the integers in the array will be in the range of [-10000, 10000].
    /// </summary>
    int arrayPairSum(vector<int>& nums);

    /// <summary>
    /// Leet code #581. Shortest Unsorted Continuous Subarray
    /// Given an integer array, you need to find one continuous subarray that 
    /// if you only sort this subarray in ascending order, then the whole 
    /// array will be sorted in ascending order, too. 
    /// 
    /// You need to find the shortest such subarray and output its length.
    /// Example 1:
    /// 
    /// Input: [2, 6, 4, 8, 10, 9, 15]
    /// Output: 5
    /// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to 
    /// make the whole array sorted in ascending order.
    /// Note:
    /// 1.Then length of the input array is in range [1, 10,000].
    /// 2.The input array may contain duplicates, so ascending order here means 
    /// <=. 
    /// </summary>
    int findUnsortedSubarray(vector<int>& nums);

    /// <summary>
    /// Leet code #665. Non-decreasing Array
    /// 
    /// Given an array with n integers, your task is to check if it could 
    /// become non-decreasing by modifying at most 1 element. 
    /// We define an array is non-decreasing if array[i] <= array[i + 1] holds 
    /// for every i (1 <= i < n). 
    /// Example 1:
    /// Input: [4,2,3]
    /// Output: True
    /// Explanation: You could modify the first 
    /// 4
    /// to 
    /// 1
    /// to get a non-decreasing array.
    ///
    /// Example 2:
    /// Input: [4,2,1]
    /// Output: False
    /// Explanation: You can't get a non-decreasing array by modify at most one 
    /// element.
    /// 
    /// Note: The n belongs to [1, 10,000]. 
    /// </summary>
    bool checkPossibility(vector<int>& nums);

    /// <summary>
    /// Leet code #692. Top K Frequent Words
    ///
    /// Given a non-empty list of words, return the k most frequent elements.
    /// Your answer should be sorted by frequency from highest to lowest. If 
    /// two words have the same frequency, then the word with the lower 
    /// alphabetical order comes first.
    ///
    /// Example 1:
    /// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
    /// Output: ["i", "love"]
    /// Explanation: "i" and "love" are the two most frequent words.
    /// Note that "i" comes before "love" due to a lower alphabetical order.
    /// Example 2:
    /// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", 
    /// "is", "is"], k = 4
    /// Output: ["the", "is", "sunny", "day"]
    /// Explanation: "the", "is", "sunny" and "day" are the four most frequent 
    /// words, with the number of occurrence being 4, 3, 2 and 1 respectively.
    /// Note:
    /// You may assume k is always valid, 1 <= k <= number of unique elements.
    /// Input words contain only lowercase letters.
    /// Follow up:
    /// 1. Try to solve it in O(n log k) time and O(n) extra space.
    /// 2. Can you solve it in O(n) time with only O(k) extra space?
    /// </summary>
    vector<string> topKFrequent(vector<string>& words, int k);

    /// <summary>
    /// Leet code #738. Monotone Increasing Digits
    ///
    /// Given a non-negative integer N, find the largest number that is less than 
    /// or equal to N with monotone increasing digits.
    ///
    /// (Recall that an integer has monotone increasing digits if and only if each 
    /// pair of adjacent digits x and y satisfy x <= y.)
    /// 
    /// Example 1:
    /// Input: N = 10
    /// Output: 9
    /// Example 2:
    /// Input: N = 1234
    /// Output: 1234
    /// Example 3:
    /// Input: N = 332
    /// Output: 299
    /// Note: N is an integer in the range [0, 10^9].
    /// </summary>
    int monotoneIncreasingDigits(int N);

    /// <summary>
    /// Leet code #744. Find Smallest Letter Greater Than Target
    ///
    /// Given a list of sorted characters letters containing only lowercase 
    /// letters, and given a target letter target, find the smallest element 
    /// in the list that is larger than the given target.
    ///
    /// Letters also wrap around. For example, if the target is target = 'z' 
    /// and letters = ['a', 'b'], the answer is 'a'.
    ///
    /// Examples:
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "a"
    /// Output: "c"
    ///
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "c"
    /// Output: "f"
    ///  
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "d"
    /// Output: "f"
    ///
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "g"
    /// Output: "j"
    ///
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "j"
    /// Output: "c"
    ///
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "k"
    /// Output: "c"
    /// Note:
    /// 1. letters has a length in range [2, 10000].
    /// 2. letters consists of lowercase letters, and contains at least 2 
    /// unique letters.
    /// target is a lowercase letter.
    /// </summary> 
    char nextGreatestLetter(vector<char>& letters, char target);

    /// <summary>
    /// Leet code #769. Max Chunks To Make Sorted   
    ///
    /// Given an array arr that is a permutation of 
    /// [0, 1, ..., arr.length - 1], we split the array into some number of 
    /// "chunks" (partitions), and individually sort each chunk.  After 
    /// concatenating them, the result equals the sorted array.
    ///
    /// What is the most number of chunks we could have made?
    ///
    /// Example 1:
    ///
    /// Input: arr = [4,3,2,1,0]
    /// Output: 1
    /// Explanation:
    /// Splitting into two or more chunks will not return the required result.
    /// For example, splitting into [4, 3], [2, 1, 0] will result in 
    /// [3, 4, 0, 1, 2], which isn't sorted.
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,0,2,3,4]
    /// Output: 4
    /// Explanation:
    /// We can split into two chunks, such as [1, 0], [2, 3, 4].
    /// However, splitting into [1, 0], [2], [3], [4] is the highest number of
    /// chunks possible.
    /// Note:
    /// arr will have length in range [1, 10].
    /// arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
    /// </summary>
    int maxChunksToSorted(vector<int>& arr);

    /// <summary>
    /// Leetcode #768. Max Chunks To Make Sorted II
    ///
    /// This question is the same as "Max Chunks to Make Sorted" except the 
    /// integers of the given array are not necessarily distinct, the input 
    /// array could be up to length 2000, and the elements could be up to 
    /// 10**8.
    ///
    /// Given an array arr of integers (not necessarily distinct), we split 
    /// the array into some number of "chunks" (partitions), and individually 
    /// sort each chunk.  After concatenating them, the result equals the 
    /// sorted array.
    ///
    /// What is the most number of chunks we could have made?
    ///
    /// Example 1:
    ///
    /// Input: arr = [5,4,3,2,1]
    /// Output: 1
    /// Explanation:
    /// Splitting into two or more chunks will not return the required result.
    /// For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 
    /// 2, 3], which isn't sorted.
    ///
    /// Example 2:
    /// Input: arr = [2,1,3,4,4]
    /// Output: 4
    /// Explanation:
    /// We can split into two chunks, such as [2, 1], [3, 4, 4].
    /// However, splitting into [2, 1], [3], [4], [4] is the highest number of 
    /// chunks possible.
    ///
    /// Note:
    /// arr will have length in range [1, 2000].
    /// arr[i] will be an integer in range [0, 10**8].
    /// </summary>
    int maxChunksToSortedII(vector<int>& arr);

    /// <summary>
    /// Leetcode #775. Global and Local Inversions
    ///
    /// We have some permutation A of [0, 1, ..., N - 1], where N is the length
    /// of A.
    ///
    /// The number of (global) inversions is the number of i < j with 
    /// 0 <= i < j < N and A[i] > A[j].
    ///
    /// The number of local inversions is the number of i with 0 <= i < N and 
    /// A[i] > A[i+1].
    ///
    /// Return true if and only if the number of global inversions is equal to 
    /// the number of local inversions.
    ///
    /// Example 1:
    /// Input: A = [1,0,2]
    /// Output: true
    /// Explanation: There is 1 global inversion, and 1 local inversion.
    ///
    /// Example 2:
    /// Input: A = [1,2,0]
    /// Output: false
    /// Explanation: There are 2 global inversions, and 1 local inversion.
    /// Note:
    /// 
    /// A will be a permutation of [0, 1, ..., A.length - 1].
    /// A will have length in range [1, 5000].
    /// The time limit for this problem has been reduced.
    /// </summary>
    bool isIdealPermutation(vector<int>& A);

    /// <summary>
    /// Leetcode #775. Global and Local Inversions
    ///
    /// We have some permutation A of [0, 1, ..., N - 1], where N is the length
    /// of A.
    ///
    /// The number of (global) inversions is the number of i < j with 
    /// 0 <= i < j < N and A[i] > A[j].
    ///
    /// The number of local inversions is the number of i with 0 <= i < N and 
    /// A[i] > A[i+1].
    ///
    /// Return true if and only if the number of global inversions is equal to 
    /// the number of local inversions.
    ///
    /// Example 1:
    /// Input: A = [1,0,2]
    /// Output: true
    /// Explanation: There is 1 global inversion, and 1 local inversion.
    ///
    /// Example 2:
    /// Input: A = [1,2,0]
    /// Output: false
    /// Explanation: There are 2 global inversions, and 1 local inversion.
    /// Note:
    /// 
    /// A will be a permutation of [0, 1, ..., A.length - 1].
    /// A will have length in range [1, 5000].
    /// The time limit for this problem has been reduced.
    /// </summary>
    bool isIdealPermutationII(vector<int>& A);

    /// <summary>
    /// Leet code #798. Smallest Rotation with Highest Score
    ///
    /// Given an array A, we may rotate it by a non-negative integer K so that 
    /// the array becomes A[K], A[K+1], A{K+2], ... A[A.length - 1], A[0], 
    /// A[1], ..., A[K-1].  Afterward, any entries that are less than or equal 
    /// to their index are worth 1 point. 
    /// For example, if we have [2, 4, 1, 3, 0], and we rotate by K = 2, it 
    /// becomes [1, 3, 0, 2, 4].  This is worth 3 points because 1 > 0 
    /// [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 
    /// 4 <= 4 [one point].
    /// Over all possible rotations, return the rotation index K that 
    /// corresponds to the highest score we could receive.  If there are 
    /// multiple answers, return the smallest such index K.
    /// Example 1:
    /// Input: [2, 3, 1, 4, 0]
    /// Output: 3
    /// Explanation:  
    /// Scores for each K are listed below: 
    /// K = 0,  A = [2,3,1,4,0],    score 2
    /// K = 1,  A = [3,1,4,0,2],    score 3
    /// K = 2,  A = [1,4,0,2,3],    score 3
    /// K = 3,  A = [4,0,2,3,1],    score 4
    /// K = 4,  A = [0,2,3,1,4],    score 3
    /// So we should choose K = 3, which has the highest score.
    ///
    /// Example 2:
    /// Input: [1, 3, 0, 2, 4]
    /// Output: 0
    /// Explanation:  A will always have 3 points no matter how it shifts.
    /// So we will choose the smallest K, which is 0.
    /// Note:
    /// 1. A will have length at most 20000.
    /// 2. A[i] will be in the range [0, A.length].
    /// </summary> 
    int bestRotation(vector<int>& A);

    /// <summary>
    /// Leet code #853. Car Fleet
    /// 
    /// N cars are going to the same destination along a one lane road.  The 
    /// destination is target miles away.
    ///
    /// Each car i has a constant speed speed[i] (in miles per hour), and initial 
    /// position position[i] miles towards the target along the road.
    ///
    /// A car can never pass another car ahead of it, but it can catch up to it, 
    /// and drive bumper to bumper at the same speed.
    ///
    /// The distance between these two cars is ignored - they are assumed to have 
    /// the same position.
    ///
    /// A car fleet is some non-empty set of cars driving at the same position 
    /// and same speed.  Note that a single car is also a car fleet.
    ///
    /// If a car catches up to a car fleet right at the destination point, it 
    /// will still be considered as one car fleet.
    /// 
    /// How many car fleets will arrive at the destination?
    /// 
    /// Example 1:
    ///
    /// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
    /// Output: 3
    /// Explanation:
    /// The cars starting at 10 and 8 become a fleet, meeting each other at 12.
    /// The car starting at 0 doesn't catch up to any other car, so it is a fleet 
    /// by itself.
    /// The cars starting at 5 and 3 become a fleet, meeting each other at 6.
    /// Note that no other cars meet these fleets before the destination, so the 
    /// answer is 3.
    ///
    /// Note:
    ///
    /// 1. 0 <= N <= 10 ^ 4
    /// 2. 0 < target <= 10 ^ 6
    /// 3. 0 < speed[i] <= 10 ^ 6
    /// 4. 0 <= position[i] < target
    /// 5. All initial positions are different.
    /// </summary>
    int carFleet(int target, vector<int>& position, vector<int>& speed);

    /// <summary>
    /// Leet code #870. Advantage Shuffle
    /// 
    /// Given two arrays A and B of equal size, the advantage of A with respect 
    /// to B is the number of indices i for which A[i] > B[i].
    ///
    /// Return any permutation of A that maximizes its advantage with respect 
    /// to B.
    /// 
    /// Example 1:
    /// Input: A = [2,7,11,15], B = [1,10,4,11]
    /// Output: [2,11,7,15]
    ///
    /// Example 2:
    /// Input: A = [12,24,8,32], B = [13,25,32,11]
    /// Output: [24,32,8,12]
    /// 
    /// Note:
    /// 1. 1 <= A.length = B.length <= 10000
    /// 2. 0 <= A[i] <= 10^9
    /// 3. 0 <= B[i] <= 10^9
    /// </summary>
    vector<int> advantageCount(vector<int>& A, vector<int>& B);

    /// <summary>
    /// Leet code #941. Valid Mountain Array
    /// 
    /// Given an array A of integers, return true if and only if it is a valid 
    /// mountain array.
    ///
    /// Recall that A is a mountain array if and only if:
    ///
    /// A.length >= 3
    /// There exists some i with 0 < i < A.length - 1 such that:
    /// A[0] < A[1] < ... A[i-1] < A[i]
    /// A[i] > A[i+1] > ... > A[B.length - 1]
    /// 
    ///
    /// Example 1:
    /// Input: [2,1]
    /// Output: false
    ///
    /// Example 2:
    /// Input: [3,5,5]
    /// Output: false
    ///
    /// Example 3:
    /// Input: [0,3,2,1]
    /// Output: true
    ///
    /// Note:
    /// 1. 0 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 10000 
    /// </summary>
    bool validMountainArray(vector<int>& A);

    /// <summary>
    /// Leet code #942. DI String Match
    /// 
    /// Given a string S that only contains "I" (increase) or "D" (decrease), 
    /// let N = S.length.
    ///
    /// Return any permutation A of [0, 1, ..., N] such that for all 
    /// i = 0, ..., N-1:
    ///
    /// If S[i] == "I", then A[i] < A[i+1]
    /// If S[i] == "D", then A[i] > A[i+1]
    /// 
    /// Example 1:
    /// Input: "IDID"
    /// Output: [0,4,1,3,2]
    ///
    /// Example 2:
    /// Input: "III"
    /// Output: [0,1,2,3]
    ///
    /// Example 3:
    /// Input: "DDI"
    /// Output: [3,2,0,1]
    /// 
    ///
    /// Note:
    /// 
    /// 1. 1 <= S.length <= 10000
    /// 2. S only contains characters "I" or "D".
    /// </summary>
    vector<int> diStringMatch(string S);

    /// <summary>
    /// Leet code #953. Verifying an Alien Dictionary
    /// 
    /// In an alien language, surprisingly they also use english lowercase 
    /// letters, but possibly in a different order. The order of the alphabet 
    /// is some permutation of lowercase letters.
    ///
    /// Given a sequence of words written in the alien language, and the order 
    /// of the alphabet, return true if and only if the given words are sorted 
    /// lexicographicaly in this alien language.
    ///
    /// Example 1:
    /// Input: words = ["hello","leetcode"], 
    /// order = "hlabcdefgijkmnopqrstuvwxyz"
    /// Output: true
    /// Explanation: As 'h' comes before 'l' in this language, then the 
    /// sequence is sorted.
    ///
    /// Example 2:
    /// Input: words = ["word","world","row"], 
    /// order = "worldabcefghijkmnpqstuvxyz"
    /// Output: false
    /// Explanation: As 'd' comes after 'l' in this language, then 
    /// words[0] > words[1], hence the sequence is unsorted.
    ///
    /// Example 3:
    /// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
    /// Output: false
    /// Explanation: The first three characters "app" match, and the second 
    /// string is shorter (in size.) According to lexicographical rules 
    /// "apple" > "app", because 'l' > '\0', where '\0' is defined as the 
    /// blank character which is less than any other character (More info).
    /// 
    /// Note:
    /// 1. 1 <= words.length <= 100
    /// 2. 1 <= words[i].length <= 20
    /// 3. order.length == 26
    /// 4. All characters in words[i] and order are english lowercase letters.
    /// </summary>
    bool isAlienSorted(vector<string>& words, string order);

    /// <summary>
    /// Leet code #954. Array of Doubled Pairs
    /// 
    /// Given an array of integers A with even length, return true if and only 
    /// if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] 
    /// for every 0 <= i < len(A) / 2.
    ///  
    /// Example 1:
    /// Input: [3,1,3,6]
    /// Output: false
    ///
    /// Example 2:
    /// Input: [2,1,2,6]
    /// Output: false
    ///
    /// Example 3:
    /// Input: [4,-2,2,-4]
    /// Output: true
    /// Explanation: We can take two groups, [-2,-4] and [2,4] to form 
    /// [-2,-4,2,4] or [2,4,-2,-4].
    ///
    /// Example 4:
    /// Input: [1,2,4,16,8,4]
    /// Output: false
    ///
    /// Note:
    /// 1. 0 <= A.length <= 30000
    /// 2. A.length is even
    /// 3. -100000 <= A[i] <= 100000
    /// </summary>
    bool canReorderDoubled(vector<int>& A);

    /// <summary>
    /// Leet code #955. Delete Columns to Make Sorted II
    /// 
    /// We are given an array A of N lowercase letter strings, all of the same 
    /// length.
    ///
    /// Now, we may choose any set of deletion indices, and for each string, 
    /// we delete all the characters in those indices.
    ///
    /// For example, if we have an array A = ["abcdef","uvwxyz"] and deletion 
    /// indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].
    ///
    /// Suppose we chose a set of deletion indices D such that after deletions, 
    /// the final array has its elements in lexicographic order 
    /// (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).
    ///
    /// Return the minimum possible value of D.length.
    ///
    /// Example 1:
    /// Input: ["ca","bb","ac"]
    /// Output: 1
    /// Explanation: 
    /// After deleting the first column, A = ["a", "b", "c"].
    /// Now A is in lexicographic order (ie. A[0] <= A[1] <= A[2]).
    /// We require at least 1 deletion since initially A was not in 
    /// lexicographic order, so the answer is 1.
    ///
    /// Example 2:
    /// Input: ["xc","yb","za"]
    /// Output: 0
    /// Explanation: 
    /// A is already in lexicographic order, so we don't need to delete 
    /// anything.
    /// Note that the rows of A are not necessarily in lexicographic order:
    /// ie. it is NOT necessarily true that (A[0][0] <= A[0][1] <= ...)
    ///
    /// Example 3:
    /// Input: ["zyx","wvu","tsr"]
    /// Output: 3
    /// Explanation: 
    /// We have to delete every column.
    ///  
    /// Note:
    /// 1. 1 <= A.length <= 100
    /// 2. 1 <= A[i].length <= 100
    /// </summary>
    int minDeletionSizeII(vector<string>& A);

    /// <summary>
    /// Leet code #962. Maximum Width Ramp
    /// 
    /// Given an array A of integers, a ramp is a tuple (i, j) for which i < j 
    /// and A[i] <= A[j].  The width of such a ramp is j - i.
    ///
    /// Find the maximum width of a ramp in A.  If one doesn't exist, return 0.
    /// 
    /// Example 1:
    ///
    /// Input: [6,0,8,2,1,5]
    /// Output: 4
    /// Explanation: 
    /// The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and 
    /// A[5] = 5.
    ///
    /// Example 2:
    ///
    /// Input: [9,8,1,0,1,9,4,0,4,1]
    /// Output: 7
    /// Explanation: 
    /// The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and 
    /// A[9] = 1.
    ///
    /// Note:
    ///
    /// 1. 2 <= A.length <= 50000
    /// 2. 0 <= A[i] <= 50000
    /// </summary>
    int maxWidthRamp(vector<int>& A);

    /// <summary>
    /// Leet code #977. Squares of a Sorted Array
    /// 
    /// Given an array of integers A sorted in non-decreasing order, return 
    /// an array of the squares of each number, also in sorted 
    /// non-decreasing order.
    /// 
    /// Example 1:
    /// Input: [-4,-1,0,3,10]
    /// Output: [0,1,9,16,100]
    ///
    /// Example 2:
    /// Input: [-7,-3,2,3,11]
    /// Output: [4,9,9,49,121]
    ///
    /// Note:
    /// 1. 1 <= A.length <= 10000
    /// 2. -10000 <= A[i] <= 10000
    /// 3. A is sorted in non-decreasing order.
    /// </summary>
    vector<int> sortedSquares(vector<int>& A);

    /// <summary>
    /// Leet code #912. Sort an Array
    /// 
    /// Given an array of integers nums, sort the array in ascending order.
    /// 
    /// Example 1:
    /// 
    /// Input: [5,2,3,1]
    /// Output: [1,2,3,5]
    ///
    /// Example 2:
    ///
    /// Input: [5,1,1,2,0,0]
    /// Output: [0,0,1,1,2,5]
    /// 
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 10000
    /// 2. -50000 <= A[i] <= 50000
    /// </summary>
    vector<int> sortArray(vector<int>& nums);

    /// <summary>
    /// Leet code #1029. Two City Scheduling
    /// 
    /// There are 2N people a company is planning to interview. The cost of flying 
    /// the i-th person to city A is costs[i][0], and the cost of flying the i-th 
    /// person to city B is costs[i][1].
    /// 
    /// Return the minimum cost to fly every person to a city such that exactly N 
    /// people arrive in each city.
    /// 
    /// Example 1:
    ///
    /// Input: [[10,20],[30,200],[400,50],[30,20]]
    /// Output: 110
    /// Explanation: 
    /// The first person goes to city A for a cost of 10.
    /// The second person goes to city A for a cost of 30.
    /// The third person goes to city B for a cost of 50.
    /// The fourth person goes to city B for a cost of 20.
    ///
    /// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people 
    /// interviewing in each city.
    ///  
    /// Note:
    /// 1. 1 <= costs.length <= 100
    /// 2. It is guaranteed that costs.length is even.
    /// 3. 1 <= costs[i][0], costs[i][1] <= 1000
    /// </summary>
    int twoCitySchedCost(vector<vector<int>>& costs);

    /// <summary>
    /// Leet code #1046. Last Stone Weight
    /// 
    /// We have a collection of rocks, each rock has a positive integer weight.
    /// Each turn, we choose the two heaviest rocks and smash them together.  
    /// Suppose the stones have weights x and y with x <= y.  The result of this 
    /// smash is:
    /// If x == y, both stones are totally destroyed;
    /// If x != y, the stone of weight x is totally destroyed, and the stone of 
    /// weight y has new weight y-x.
    /// At the end, there is at most 1 stone left.  Return the weight of this 
    /// stone (or 0 if there are no stones left.)
    /// 
    /// Example 1:
    /// Input: [2,7,4,1,8,1]
    /// Output: 1
    /// Explanation: 
    /// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
    /// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
    /// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
    /// we combine 1 and 1 to get 0 so the array converts to [1] then that's the 
    /// value of last stone.
    /// 
    /// Note:
    /// 1. 1 <= stones.length <= 30
    /// 2. 1 <= stones[i] <= 1000
    /// </summary>
    int lastStoneWeight(vector<int>& stones);

    /// <summary>
    /// Leet code #1051. Height Checker
    /// 
    /// Students are asked to stand in non-decreasing order of heights for an 
    /// annual photo.
    ///
    /// Return the minimum number of students not standing in the right 
    /// positions.  (This is the number of students that must move in order 
    /// for all students to be standing in non-decreasing order of height.)
    ///
    /// Example 1:
    ///
    /// Input: [1,1,4,2,1,3]
    /// Output: 3
    /// Explanation: 
    /// Students with heights 4, 3 and the last 1 are not standing in the right 
    /// positions.
    /// 
    /// Note:
    /// 
    /// 1. 1 <= heights.length <= 100
    /// 2. 1 <= heights[i] <= 100
    /// </summary>
    int heightChecker(vector<int>& heights);

    /// <summary>
    /// Leet code #1053. Previous Permutation With One Swap
    /// 
    /// Given an array A of positive integers (not necessarily distinct), return 
    /// the lexicographically largest permutation that is smaller than A, that 
    /// can be made with one swap (A swap exchanges the positions of two numbers 
    /// A[i] and A[j]).  If it cannot be done, then return the same array.
    ///
    /// Example 1:
    ///
    /// Input: [3,2,1]
    /// Output: [3,1,2]
    /// Explanation: Swapping 2 and 1.
    ///
    /// Example 2:
    ///
    /// Input: [1,1,5]
    /// Output: [1,1,5]
    /// Explanation: This is already the smallest permutation.
    ///
    /// Example 3:
    ///
    /// Input: [1,9,4,6,7]
    /// Output: [1,7,4,6,9]
    /// Explanation: Swapping 9 and 7.
    ///
    /// Example 4:
    ///
    /// Input: [3,1,1,3]
    /// Output: [1,3,1,3]
    /// Explanation: Swapping 1 and 3.
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= A.length <= 10000
    /// 2. 1 <= A[i] <= 10000
    /// </summary>
    vector<int> prevPermOpt1(vector<int>& A);

    /// <summary>
    /// Leet code #1090. Largest Values From Labels
    /// 
    /// We have a set of items: the i-th item has value values[i] and label 
    /// labels[i].
    ///
    /// Then, we choose a subset S of these items, such that:
    /// |S| <= num_wanted
    /// For every label L, the number of items in S with label L is <= 
    /// use_limit.
    /// Return the largest possible sum of the subset S.
    ///
    /// Example 1:
    /// Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, 
    /// use_limit = 1
    /// Output: 9
    /// Explanation: The subset chosen is the first, third, and fifth item.
    ///
    /// Example 2: 
    /// Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, 
    /// use_limit = 2
    /// Output: 12
    /// Explanation: The subset chosen is the first, second, and third item.
    ///
    /// Example 3:
    /// Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, 
    /// use_limit = 1
    /// Output: 16
    /// Explanation: The subset chosen is the first and fourth item.
    ///
    /// Example 4:
    /// Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, 
    /// use_limit = 2
    /// Output: 24
    /// Explanation: The subset chosen is the first, second, and fourth item.
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= values.length == labels.length <= 20000
    /// 2. 0 <= values[i], labels[i] <= 20000
    /// 3. 1 <= num_wanted, use_limit <= values.length
    /// </summary>
    int largestValsFromLabels(vector<int>& values, vector<int>& labels,
        int num_wanted, int use_limit);

    /// <summary>
    /// Leet code #1086. High Five
    /// 
    /// Given a list of scores of different students, return the average 
    /// score of each student's top five scores in the order of each 
    /// student's id.
    /// Each entry items[i] has items[i][0] the student's id, and items[i][1] 
    /// the student's score.  The average score is calculated using integer 
    /// division.
    ///
    /// Example 1:
    /// Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],
    ///        [1,100],[2,100],[2,76]]
    /// Output: [[1,87],[2,88]]
    /// Explanation: 
    /// The average of the student with id = 1 is 87.
    /// The average of the student with id = 2 is 88.6. But with integer 
    /// division their average converts to 88.
    ///
    /// Note:
    /// 1. 1 <= items.length <= 1000
    /// 2. items[i].length == 2
    /// 3. The IDs of the students is between 1 to 1000
    /// 4. The score of the students is between 1 to 100
    /// 5. For each student, there are at least 5 scores
    /// </summary>
    vector<vector<int>> highFive(vector<vector<int>>& items);

    /// <summary>
    /// Leet code #1099. Two Sum Less Than K
    /// 
    /// Given an array A of integers and integer K, return the maximum S such 
    /// that there exists i < j with A[i] + A[j] = S and S < K. If no i, j 
    /// exist satisfying this equation, return -1.
    /// 
    /// Example 1:
    /// Input: A = [34,23,1,24,75,33,54,8], K = 60
    /// Output: 58
    /// Explanation: 
    /// We can use 34 and 24 to sum 58 which is less than 60.
    ///
    /// Example 2:
    /// Input: A = [10,20,30], K = 15
    /// Output: -1
    /// Explanation: 
    /// In this case it's not possible to get a pair sum less that 15.
    /// </summary>
    int twoSumLessThanK(vector<int>& A, int K);

    /// <summary>
    /// Leet code #1122. Relative Sort Array
    /// 
    /// Given two arrays arr1 and arr2, the elements of arr2 are distinct, 
    /// and all elements in arr2 are also in arr1.
    ///
    /// Sort the elements of arr1 such that the relative ordering of items 
    /// in arr1 are the same as in arr2.  Elements that don't appear in arr2 
    /// should be placed at the end of arr1 in ascending order.
    ///
    /// 
    /// Example 1:
    /// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
    /// Output: [2,2,2,1,4,3,3,9,6,7,19]
    /// 
    /// 
    /// Constraints:
    ///
    /// 1. arr1.length, arr2.length <= 1000
    /// 2. 0 <= arr1[i], arr2[i] <= 1000
    /// 3. Each arr2[i] is distinct.
    /// 4. Each arr2[i] is in arr1.
    /// </summary>
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2);

    /// <summary>
    /// Leet code #1133. Largest Unique Number
    /// 
    /// Given an array of integers A, return the largest integer that only occurs 
    /// once.
    ///
    /// If no integer occurs once, return -1.
    ///
    /// Example 1:
    /// Input: [5,7,3,9,4,9,8,3,1]
    /// Output: 8
    /// Explanation: 
    /// The maximum integer in the array is 9 but it is repeated. The number 8 
    /// occurs only once, so it's the answer.
    ///
    /// Example 2:
    /// Input: [9,9,8,8]
    /// Output: -1
    /// Explanation: 
    /// There is no number that occurs only once.
    /// Note:
    /// 1. 1 <= A.length <= 2000
    /// 2. 0 <= A[i] <= 1000
    /// </summary>
    int largestUniqueNumber(vector<int>& A);

    /// <summary>
    /// Leet code #376. Wiggle Subsequence
    /// A sequence of numbers is called a wiggle sequence if the differences between successive numbers 
    /// strictly alternate between positive and negative. The first difference (if one
    /// exists) may be either positive or negative. A sequence with fewer than two elements is trivially 
    /// a wiggle sequence. 
    /// 
    /// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are 
    /// alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are 
    /// not wiggle sequences, the first because its first two differences are 
    /// positive and the second because its last difference is zero.
    ///
    /// Given a sequence of integers, return the length of the longest subsequence that is a 
    /// wiggle sequence. A subsequence is obtained by deleting some number of elements 
    /// (eventually, also zero) from the original sequence, leaving the remaining elements 
    /// in their original order.
    /// 
    /// Examples:
    /// Input: [1,7,4,9,2,5]
    /// Output: 6
    /// The entire sequence is a wiggle sequence.
    ///
    /// Input: [1,17,5,10,13,15,10,5,16,8]
    /// Output: 7
    /// There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
    ///
    /// Input: [1,2,3,4,5,6,7,8,9]
    /// Output: 2
    /// Follow up:
    /// Can you do it in O(n) time? 
    /// </summary>
    int wiggleMaxLength(vector<int>& nums);

    /// <summary>
    /// Leet code #1169. Invalid Transactions
    ///
    /// A transaction is possibly invalid if:
    ///
    /// the amount exceeds $1000, or;
    /// if it occurs within (and including) 60 minutes of another transaction 
    /// with the same name in a different city.
    /// Each transaction string transactions[i] consists of comma separated 
    /// values representing the name, time (in minutes), amount, and city of 
    /// the transaction.
    ///
    /// Given a list of transactions, return a list of transactions that are 
    /// possibly invalid.  You may return the answer in any order.
    ///
    /// 
    ///
    /// Example 1:
    /// Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
    /// Output: ["alice,20,800,mtv","alice,50,100,beijing"]
    /// Explanation: The first transaction is invalid because the second 
    /// transaction occurs within a difference of 60 minutes, have the same 
    /// name and is in a different city. Similarly the second one is 
    /// invalid too.
    ///
    /// Example 2:
    ///
    /// Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
    /// Output: ["alice,50,1200,mtv"]
    ///
    /// Example 3:
    ///
    /// Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
    /// Output: ["bob,50,1200,mtv"]
    ///  
    /// Constraints:
    /// 
    /// 1. transactions.length <= 1000
    /// 2. Each transactions[i] takes the form "{name},{time},{amount},{city}"
    /// 3. Each {name} and {city} consist of lowercase English letters, and have 
    ///    lengths between 1 and 10.
    /// 3. Each {time} consist of digits, and represent an integer between 
    ///    0 and 1000.
    /// 4. Each {amount} consist of digits, and represent an integer between 
    ///    0 and 2000.
    /// </summary>
    vector<string> invalidTransactions(vector<string>& transactions);

    /// <summary>
    /// Leet code #1167. Minimum Cost to Connect Sticks
    /// 
    /// You have some sticks with positive integer lengths.
    /// You can connect any two sticks of lengths X and Y into one stick by 
    /// paying a cost of X + Y.  You perform this action until there is one 
    /// stick remaining.
    /// Return the minimum cost of connecting all the given sticks into one 
    /// stick in this way.
    /// 
    /// Example 1:
    /// Input: sticks = [2,4,3]
    /// Output: 14
    ///
    /// Example 2:
    /// Input: sticks = [1,8,3,5]
    /// Output: 30
    ///  
    /// Constraints:
    /// 1 <= sticks.length <= 10^4
    /// 1 <= sticks[i] <= 10^4
    /// </summary>
    int connectSticks(vector<int>& sticks);

    /// <summary>
    /// Leet code #1182. Shortest Distance to Target Color
    /// 
    /// You are given an array colors, in which there are three colors: 1, 2 and 3.
    /// You are also given some queries. Each query consists of two integers i 
    /// and c, return the shortest distance between the given index i and the 
    /// target color c. If there is no solution return -1.
    /// 
    /// Example 1:
    /// Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
    /// Output: [3,0,3]
    /// Explanation: 
    /// The nearest 3 from index 1 is at index 4 (3 steps away).
    /// The nearest 2 from index 2 is at index 2 itself (0 steps away).
    /// The nearest 1 from index 6 is at index 3 (3 steps away).
    ///
    /// Example 2:
    /// Input: colors = [1,2], queries = [[0,3]]
    /// Output: [-1]
    /// Explanation: There is no 3 in the array.
    ///  
    /// Constraints:
    /// 1. 1 <= colors.length <= 5*10^4
    /// 2. 1 <= colors[i] <= 3
    /// 3. 1 <= queries.length <= 5*10^4
    /// 4. queries[i].length == 2
    /// 5. 0 <= queries[i][0] < colors.length
    /// 6. 1 <= queries[i][1] <= 3
    /// </summary>
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code #1199. Minimum Time to Build Blocks
    /// 
    /// You are given a list of blocks, where blocks[i] = t means that the i-th 
    /// block needs t units of time to be built. A block can only be built by 
    /// exactly one worker.
    ///
    /// A worker can either split into two workers (number of workers increases 
    /// by one) or build a block then go home. Both decisions cost some time.
    ///
    /// The time cost of spliting one worker into two workers is given as an 
    /// integer split. Note that if two workers split at the same time, they 
    /// split in parallel so the cost would be split.
    ///
    /// Output the minimum time needed to build all blocks.
    ///
    /// Initially, there is only one worker.
    /// 
    /// Example 1:
    /// Input: blocks = [1], split = 1
    /// Output: 1
    /// Explanation: We use 1 worker to build 1 block in 1 time unit.
    ///
    /// Example 2:
    /// Input: blocks = [1,2], split = 5
    /// Output: 7
    /// Explanation: We split the worker into 2 workers in 5 time units then 
    /// assign each of them to a block so the cost is 5 + max(1, 2) = 7.
    ///
    /// Example 3:
    /// Input: blocks = [1,2,3], split = 1
    /// Output: 4
    /// Explanation: Split 1 worker into 2, then assign the first worker to 
    /// the last block and split the second worker into 2.
    /// Then, use the two unassigned workers to build the first two blocks.
    /// The cost is 1 + max(3, 1 + max(1, 2)) = 4.
    /// 
    ///
    /// Constraints:
    ///
    /// 1. 1 <= blocks.length <= 1000
    /// 2. 1 <= blocks[i] <= 10^5
    /// 3. 1 <= split <= 100
    /// </summary>
    int minBuildTime(vector<int>& blocks, int split);

    /// <summary>
    /// Leet Code 2136. Earliest Possible Day of Full Bloom
    ///                                                                 
    /// Hard
    ///
    /// You have n flower seeds. Every seed must be planted first before it 
    /// can begin to grow, then bloom. Planting a seed takes time and so does 
    /// the growth of a seed. You are given two 0-indexed integer arrays 
    /// plantTime and growTime, of length n each:
    ///
    /// plantTime[i] is the number of full days it takes you to plant the ith 
    /// seed. Every day, you can work on planting exactly one seed. You do not 
    /// have to work on planting the same seed on consecutive days, but the 
    /// planting of a seed is not complete until you have worked plantTime[i] 
    /// days on planting it in total.
    /// growTime[i] is the number of full days it takes the ith seed to grow 
    /// after being completely planted. After the last day of its growth, the 
    /// flower blooms and stays bloomed forever.
    /// From the beginning of day 0, you can plant the seeds in any order.
    ///
    /// Return the earliest possible day where all seeds are blooming.
    ///
    /// Example 1:
    /// Input: plantTime = [1,4,3], growTime = [2,3,1]
    /// Output: 9
    /// Explanation: The grayed out pots represent planting days, colored pots 
    /// represent growing days, and the flower represents the day it blooms.
    /// One optimal way is:
    /// On day 0, plant the 0th seed. The seed grows for 2 full days and 
    /// blooms on day 3.
    /// On days 1, 2, 3, and 4, plant the 1st seed. The seed grows for 3 full 
    /// days and blooms on day 8.
    /// On days 5, 6, and 7, plant the 2nd seed. The seed grows for 1 full day 
    /// and blooms on day 9.
    /// Thus, on day 9, all the seeds are blooming.
    ///
    /// Example 2:
    /// Input: plantTime = [1,2,3,2], growTime = [2,1,2,1]
    /// Output: 9
    /// Explanation: The grayed out pots represent planting days, colored pots 
    /// represent growing days, and the flower represents the day it blooms.
    /// One optimal way is:
    /// On day 1, plant the 0th seed. The seed grows for 2 full days and 
    /// blooms on day 4.
    /// On days 0 and 3, plant the 1st seed. The seed grows for 1 full day and 
    /// blooms on day 5.
    /// On days 2, 4, and 5, plant the 2nd seed. The seed grows for 2 full 
    /// days and blooms on day 8.
    /// On days 6 and 7, plant the 3rd seed. The seed grows for 1 full day 
    /// and blooms on day 9.
    /// Thus, on day 9, all the seeds are blooming.
    ///
    /// Example 3:
    /// Input: plantTime = [1], growTime = [1]
    /// Output: 2
    /// Explanation: On day 0, plant the 0th seed. The seed grows for 1 full 
    /// day and blooms on day 2.
    /// Thus, on day 2, all the seeds are blooming.
    ///
    /// Constraints:
    /// 1. n == plantTime.length == growTime.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= plantTime[i], growTime[i] <= 10^4
    /// </summary>
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime);

    /// <summary>
    /// Leet Code 2126. Destroying Asteroids
    ///                                                                 
    /// Medium
    ///
    /// You are given an integer mass, which represents the original mass of 
    /// a planet. You are further given an integer array asteroids, where 
    /// asteroids[i] is the mass of the ith asteroid.
    ///
    /// You can arrange for the planet to collide with the asteroids in any 
    /// arbitrary order. If the mass of the planet is greater than or equal 
    /// to the mass of the asteroid, the asteroid is destroyed and the planet 
    /// gains the mass of the asteroid. Otherwise, the planet is destroyed.
    /// 
    /// Return true if all asteroids can be destroyed. Otherwise, return false.
    ///
    /// 
    /// Example 1:
    /// Input: mass = 10, asteroids = [3,9,19,5,21]
    /// Output: true
    /// Explanation: One way to order the asteroids is [9,19,5,3,21]:
    /// - The planet collides with the asteroid with a mass of 9. New planet 
    ///   mass: 10 + 9 = 19
    /// - The planet collides with the asteroid with a mass of 19. New planet 
    ///   mass: 19 + 19 = 38
    /// - The planet collides with the asteroid with a mass of 5. New planet 
    ///   mass: 38 + 5 = 43
    /// - The planet collides with the asteroid with a mass of 3. New planet 
    ///   mass: 43 + 3 = 46
    /// - The planet collides with the asteroid with a mass of 21. New planet 
    ///   mass: 46 + 21 = 67
    /// All asteroids are destroyed.
    ///
    /// Example 2:
    /// Input: mass = 5, asteroids = [4,9,23,4]
    /// Output: false
    /// Explanation: 
    /// The planet cannot ever gain enough mass to destroy the asteroid with a 
    /// mass of 23.
    /// After the planet destroys the other asteroids, it will have a mass 
    /// of 5 + 4 + 9 + 4 = 22.
    /// This is less than 23, so a collision would not destroy the last 
    /// asteroid.
    /// 
    /// Constraints:
    /// 1. 1 <= mass <= 10^5
    /// 2. 1 <= asteroids.length <= 10^5
    /// 3. 1 <= asteroids[i] <= 10^5
    /// </summary>
    bool asteroidsDestroyed(int mass, vector<int>& asteroids);

    /// <summary>
    /// Leet Code 2144. Minimum Cost of Buying Candies With Discount
    ///                                                                 
    /// Easy
    ///
    /// A shop is selling candies at a discount. For every two candies sold, 
    /// the shop gives a third candy for free.
    ///
    /// The customer can choose any candy to take away for free as long as 
    /// the cost of the chosen candy is less than or equal to the minimum 
    /// cost of the two candies bought.
    ///
    /// For example, if there are 4 candies with costs 1, 2, 3, and 4, and 
    /// the customer buys candies with costs 2 and 3, they can take the candy 
    /// with cost 1 for free, but not the candy with cost 4.
    /// Given a 0-indexed integer array cost, where cost[i] denotes the cost 
    /// of the ith candy, return the minimum cost of buying all the candies.
    ///
    /// Example 1:
    /// Input: cost = [1,2,3]
    /// Output: 5
    /// Explanation: We buy the candies with costs 2 and 3, and take the candy 
    /// with cost 1 for free.
    /// The total cost of buying all candies is 2 + 3 = 5. This is the only 
    /// way we can buy the candies.
    /// Note that we cannot buy candies with costs 1 and 3, and then take the 
    /// candy with cost 2 for free.
    /// The cost of the free candy has to be less than or equal to the minimum 
    /// cost of the purchased candies.
    ///
    /// Example 2:
    /// Input: cost = [6,5,7,9,2,2]
    /// Output: 23
    /// Explanation: The way in which we can get the minimum cost is described 
    /// below:
    /// - Buy candies with costs 9 and 7
    /// - Take the candy with cost 6 for free
    /// - We buy candies with costs 5 and 2
    /// - Take the last remaining candy with cost 2 for free
    /// Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
    ///
    /// Example 3:
    /// Input: cost = [5,5]
    /// Output: 10
    /// Explanation: Since there are only 2 candies, we buy both of them. 
    /// There is not a third candy we can take for free.
    /// Hence, the minimum cost to buy all candies is 5 + 5 = 10.
    ///
    /// Constraints:
    /// 1. 1 <= cost.length <= 100
    /// 2. 1 <= cost[i] <= 100
    /// </summary>
    int minimumCost(vector<int>& cost);

    /// <summary>
    /// Leet Code 2148. Count Elements With Strictly Smaller and Greater 
    ///                 Elements
    ///                                                                 
    /// Easy
    ///
    /// Given an integer array nums, return the number of elements that have 
    /// both a strictly smaller and a strictly greater element appear in nums.
    ///
    /// Example 1:
    /// Input: nums = [11,7,2,15]
    /// Output: 2
    /// Explanation: The element 7 has the element 2 strictly smaller than it 
    /// and the element 11 strictly greater than it.
    /// Element 11 has element 7 strictly smaller than it and element 15 
    /// strictly greater than it.
    /// In total there are 2 elements having both a strictly smaller and a 
    /// strictly greater element appear in nums.
    ///
    /// Example 2:
    /// Input: nums = [-3,3,3,90]
    /// Output: 2
    /// Explanation: The element 3 has the element -3 strictly smaller than 
    /// it and the element 90 strictly greater than it.
    /// Since there are two elements with the value 3, in total there are 2 
    /// elements having both a strictly smaller and a strictly greater element 
    /// appear in nums.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. -10^5 <= nums[i] <= 10^5
    /// </summary>
    int countElements(vector<int>& nums);


    /// <summary>
    /// Leet Code 2164. Sort Even and Odd Indices Independently
    ///                                                                 
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums. Rearrange the values 
    /// of nums according to the following rules:
    ///
    /// Sort the values at odd indices of nums in non-increasing order.
    /// For example, if nums = [4,1,2,3] before this step, it 
    /// becomes [4,3,2,1] after. The values at odd indices 1 and 3 are 
    /// sorted in non-increasing order.
    /// Sort the values at even indices of nums in non-decreasing order.
    /// For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] 
    /// after. The values at even indices 0 and 2 are sorted in non-decreasing 
    /// order.
    /// Return the array formed after rearranging the values of nums.
    ///
    /// Example 1:
    /// Input: nums = [4,1,2,3]
    /// Output: [2,3,4,1]
    /// Explanation: 
    /// First, we sort the values present at odd indices (1 and 3) in 
    /// non-increasing order.
    /// So, nums changes from [4,1,2,3] to [4,3,2,1].
    /// Next, we sort the values present at even indices (0 and 2) in 
    /// non-decreasing order.
    /// So, nums changes from [4,1,2,3] to [2,3,4,1].
    /// Thus, the array formed after rearranging the values is [2,3,4,1].
    ///
    /// Example 2:
    /// Input: nums = [2,1]
    /// Output: [2,1]
    /// Explanation: 
    /// Since there is exactly one odd index and one even index, no 
    /// rearrangement of values takes place.
    /// The resultant array formed is [2,1], which is the same as the initial 
    /// array. 
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// </summary>
    vector<int> sortEvenOdd(vector<int>& nums);

    /// <summary>
    /// Leet Code 2165. Smallest Value of the Rearranged Number
    ///                                                                 
    /// Medium
    ///
    /// You are given an integer num. Rearrange the digits of num such that 
    /// its value is minimized and it does not contain any leading zeros.
    ///
    /// Return the rearranged number with minimal value.
    /// Note that the sign of the number does not change after rearranging 
    /// the digits.
    ///
    /// Example 1:
    /// Input: num = 310
    /// Output: 103
    /// Explanation: The possible arrangements for the digits of 310 
    /// are 013, 031, 103, 130, 301, 310. 
    /// The arrangement with the smallest value that does not contain any 
    /// leading zeros is 103.
    ///
    /// Example 2:
    /// Input: num = -7605
    /// Output: -7650
    /// Explanation: Some possible arrangements for the digits of -7605 
    /// are -7650, -6705, -5076, -0567.
    /// The arrangement with the smallest value that does not contain 
    /// any leading zeros is -7650.
    ///
    /// Constraints:
    /// 1. -10^15 <= num <= 10^15
    /// </summary>
    long long smallestNumber(long long num);

    /// <summary>
    /// Leet Code 2171. Removing Minimum Number of Magic Beans
    ///                                                                                  
    /// Medium
    ///
    /// You are given an array of positive integers beans, where each integer 
    /// represents the number of magic beans found in a particular magic bag.
    ///
    /// Remove any number of beans (possibly none) from each bag such that 
    /// the number of beans in each remaining non-empty bag (still containing 
    /// at least one bean) is equal. Once a bean has been removed from a bag, 
    /// you are not allowed to return it to any of the bags.
    ///
    /// Return the minimum number of magic beans that you have to remove.
    /// 
    /// Example 1:
    /// Input: beans = [4,1,6,5]
    /// Output: 4
    /// Explanation: 
    /// - We remove 1 bean from the bag with only 1 bean.
    /// This results in the remaining bags: [4,0,6,5]
    /// - Then we remove 2 beans from the bag with 6 beans.
    ///   This results in the remaining bags: [4,0,4,5]
    /// - Then we remove 1 bean from the bag with 5 beans.
    ///   This results in the remaining bags: [4,0,4,4]
    /// We removed a total of 1 + 2 + 1 = 4 beans to make the remaining 
    /// non-empty bags have an equal number of beans.
    /// There are no other solutions that remove 4 beans or fewer.
    ///
    /// Example 2:
    /// Input: beans = [2,10,3,2]
    /// Output: 7
    /// Explanation:
    /// - We remove 2 beans from one of the bags with 2 beans.
    ///  This results in the remaining bags: [0,10,3,2]
    /// - Then we remove 2 beans from the other bag with 2 beans.
    ///  This results in the remaining bags: [0,10,3,0]
    /// - Then we remove 3 beans from the bag with 3 beans. 
    /// This results in the remaining bags: [0,10,0,0]
    /// We removed a total of 2 + 2 + 3 = 7 beans to make the remaining 
    /// non-empty bags have an equal number of beans.
    /// There are no other solutions that removes 7 beans or fewer.
    /// 
    /// Constraints:
    /// 1. 1 <= beans.length <= 10^5
    /// 2. 1 <= beans[i] <= 10^5
    /// </summary>
    long long minimumRemoval(vector<int>& beans);

    /// <summary>
    /// Leet Code 2263. Make Array Non-decreasing or Non-increasing
    ///                                                                                      
    /// Hard
    /// 
    /// You are given a 0-indexed integer array nums. In one operation, you 
    /// can:
    ///
    /// Choose an index i in the range 0 <= i < nums.length
    /// Set nums[i] to nums[i] + 1 or nums[i] - 1
    /// Return the minimum number of operations to make nums non-decreasing 
    /// or non-increasing.
    /// 
    /// Example 1:
    /// Input: nums = [3,2,4,5,0]
    /// Output: 4
    /// Explanation:
    /// One possible way to turn nums into non-increasing order is to:
    /// - Add 1 to nums[1] once so that it becomes 3.
    /// - Subtract 1 from nums[2] once so it becomes 3.
    /// - Subtract 1 from nums[3] twice so it becomes 3.
    /// After doing the 4 operations, nums becomes [3,3,3,3,0] which is in 
    /// non-increasing order.
    /// Note that it is also possible to turn nums into [4,4,4,4,0] in 4 
    /// operations.
    /// It can be proven that 4 is the minimum number of operations needed.
    ///
    /// Example 2:
    /// Input: nums = [2,2,3,4]
    /// Output: 0
    /// Explanation: nums is already in non-decreasing order, so no operations 
    /// are needed and we return 0.
    ///
    /// Example 3:
    /// Input: nums = [0]
    /// Output: 0
    /// Explanation: nums is already in non-decreasing order, so no operations 
    /// are needed and we return 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 0 <= nums[i] <= 1000
    /// </summary>
    int convertArray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2250. Count Number of Rectangles Containing Each Point
    ///                                                           
    /// Medium
    /// 
    /// You are given a 2D integer array rectangles where rectangles[i] = 
    /// [li, hi] indicates that ith rectangle has a length of li and a height 
    /// of hi. You are also given a 2D integer array points where points[j] = 
    /// [xj, yj] is a point with coordinates (xj, yj).
    ///
    /// The ith rectangle has its bottom-left corner point at the 
    /// coordinates (0, 0) and its top-right corner point at (li, hi).
    ///
    /// Return an integer array count of length points.length where count[j] 
    /// is the number of rectangles that contain the jth point.
    ///
    /// The ith rectangle contains the jth point if 0 <= xj <= li and 
    /// 0 <= yj <= hi. Note that points that lie on the edges of a rectangle 
    /// are also considered to be contained by that rectangle.
    ///
    /// Example 1:
    /// Input: rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
    /// Output: [2,1]
    /// Explanation: 
    /// The first rectangle contains no points.
    /// The second rectangle contains only the point (2, 1).
    /// The third rectangle contains the points (2, 1) and (1, 4).
    /// The number of rectangles that contain the point (2, 1) is 2.
    /// The number of rectangles that contain the point (1, 4) is 1.
    /// Therefore, we return [2, 1].
    ///
    /// Example 2:
    /// Input: rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
    /// Output: [1,3]
    /// Explanation:
    /// The first rectangle contains only the point (1, 1).
    /// The second rectangle contains only the point (1, 1).
    /// The third rectangle contains the points (1, 3) and (1, 1).
    /// The number of rectangles that contain the point (1, 3) is 1.
    /// The number of rectangles that contain the point (1, 1) is 3.
    ///
    /// Therefore, we return [1, 3].
    /// 
    /// Constraints:
    /// 1. 1 <= rectangles.length, points.length <= 5 * 10^4
    /// 2. rectangles[i].length == points[j].length == 2
    /// 3. 1 <= li, xj <= 10^9
    /// 4. 1 <= hi, yj <= 100
    /// 5. All the rectangles are unique.
    /// 6. All the points are unique.
    /// </summary>
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points);


    /// <summary>
    /// Leet Code 2279. Maximum Bags With Full Capacity of Rocks
    ///                                                           
    /// Medium
    /// 
    /// You have n bags numbered from 0 to n - 1. You are given two 0-indexed 
    /// integer arrays capacity and rocks. The ith bag can hold a maximum of 
    /// capacity[i] rocks and currently contains rocks[i] rocks. You are also 
    /// given an integer additionalRocks, the number of additional rocks you 
    /// can place in any of the bags.
    ///
    /// Return the maximum number of bags that could have full capacity after 
    /// placing the additional rocks in some bags.
    ///
    /// Example 1:
    /// Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
    /// Output: 3
    /// Explanation:
    /// Place 1 rock in bag 0 and 1 rock in bag 1.
    /// The number of rocks in each bag are now [2,3,4,4].
    /// Bags 0, 1, and 2 have full capacity.
    /// There are 3 bags at full capacity, so we return 3.
    /// It can be shown that it is not possible to have more than 3 bags at 
    /// full capacity.
    /// Note that there may be other ways of placing the rocks that result in 
    /// an answer of 3.
    ///
    /// Example 2:
    /// Input: capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
    /// Output: 3
    /// Explanation:
    /// Place 8 rocks in bag 0 and 2 rocks in bag 2.
    /// The number of rocks in each bag are now [10,2,2].
    /// Bags 0, 1, and 2 have full capacity.
    /// There are 3 bags at full capacity, so we return 3.
    /// It can be shown that it is not possible to have more than 3 bags at 
    /// full capacity.
    /// Note that we did not use all of the additional rocks.
    /// 
    /// Constraints:
    /// 1. n == capacity.length == rocks.length
    /// 2. 1 <= n <= 5 * 10^4
    /// 3. 1 <= capacity[i] <= 10^9
    /// 4. 0 <= rocks[i] <= capacity[i]
    /// 5. 1 <= additionalRocks <= 10^9
    /// </summary>
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks);

    /// <summary>
    /// Leet Code 2285. Maximum Total Importance of Roads
    ///                                                           
    /// Medium
    /// 
    /// You are given an integer n denoting the number of cities in a country. 
    /// The cities are numbered from 0 to n - 1.
    ///
    /// You are also given a 2D integer array roads where roads[i] = [ai, bi] 
    /// denotes that there exists a bidirectional road connecting cities ai 
    /// and bi.
    ///
    /// You need to assign each city with an integer value from 1 to n, where 
    /// each value can only be used once. The importance of a road is then 
    /// defined as the sum of the values of the two cities it connects.
    ///
    /// Return the maximum total importance of all roads possible after 
    /// assigning the values optimally.
    /// 
    /// Example 1:
    /// Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
    /// Output: 43
    /// Explanation: The figure above shows the country and the assigned 
    /// values of [2,4,5,3,1].
    /// - The road (0,1) has an importance of 2 + 4 = 6.
    /// - The road (1,2) has an importance of 4 + 5 = 9.
    /// - The road (2,3) has an importance of 5 + 3 = 8.
    /// - The road (0,2) has an importance of 2 + 5 = 7.
    /// - The road (1,3) has an importance of 4 + 3 = 7.
    /// - The road (2,4) has an importance of 5 + 1 = 6.
    /// The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
    /// It can be shown that we cannot obtain a greater total importance 
    /// than 43.
    ///
    /// Example 2:
    /// Input: n = 5, roads = [[0,3],[2,4],[1,3]]
    /// Output: 20
    /// Explanation: The figure above shows the country and the assigned 
    /// values of [4,3,2,5,1].
    /// - The road (0,3) has an importance of 4 + 5 = 9.
    /// - The road (2,4) has an importance of 2 + 1 = 3.
    /// - The road (1,3) has an importance of 3 + 5 = 8.
    /// The total importance of all roads is 9 + 3 + 8 = 20.
    /// It can be shown that we cannot obtain a greater total importance 
    /// than 20.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 5 * 10^4
    /// 2. 1 <= roads.length <= 5 * 10^4
    /// 3. roads[i].length == 2
    /// 4. 0 <= ai, bi <= n - 1
    /// 5. ai != bi
    /// 6. There are no duplicate roads.
    /// </summary>
    long long maximumImportance(int n, vector<vector<int>>& roads);

    /// <summary>
    /// Leet Code 2300. Successful Pairs of Spells and Potions
    ///                                                           
    /// Medium
    /// 
    /// You are given two positive integer arrays spells and potions, of 
    /// length n and m respectively, where spells[i] represents the strength 
    /// of the ith spell and potions[j] represents the strength of the jth 
    /// potion.
    ///
    /// You are also given an integer success. A spell and potion pair is 
    /// considered successful if the product of their strengths is at 
    /// least success.
    ///
    /// Return an integer array pairs of length n where pairs[i] is the number 
    /// of potions that will form a successful pair with the ith spell.
    ///
    ///
    /// Example 1:
    /// Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
    /// Output: [4,0,3]
    /// Explanation:
    /// - 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
    /// - 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
    /// - 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
    /// Thus, [4,0,3] is returned.
    ///
    /// Example 2:
    /// Input: spells = [3,1,2], potions = [8,5,8], success = 16
    /// Output: [2,0,2]
    /// Explanation:
    /// - 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
    /// - 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
    /// - 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful. 
    /// Thus, [2,0,2] is returned.
    /// 
    /// Constraints:
    /// 1. n == spells.length
    /// 2. m == potions.length
    /// 3. 1 <= n, m <= 10^5
    /// 4. 1 <= spells[i], potions[i] <= 10^5
    /// 5. 1 <= success <= 10^10
    /// </summary>
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success);

    /// <summary>
    /// Leet Code 2323. Find Minimum Time to Finish All Jobs II
    ///                                                           
    /// Medium
    ///
    /// You are given two 0-indexed integer arrays jobs and workers of equal 
    /// length, where jobs[i] is the amount of time needed to complete the 
    /// ith job, and workers[j] is the amount of time the jth worker can work 
    /// each day.
    ///
    /// Each job should be assigned to exactly one worker, such that each 
    /// worker completes exactly one job.
    ///
    /// Return the minimum number of days needed to complete all the jobs 
    /// after assignment.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: jobs = [5,2,4], workers = [1,7,5]
    /// Output: 2
    /// Explanation:
    /// - Assign the 2nd worker to the 0th job. It takes them 1 day to finish 
    ///   the job.
    /// - Assign the 0th worker to the 1st job. It takes them 2 days to finish 
    ///   the job.
    /// - Assign the 1st worker to the 2nd job. It takes them 1 day to finish 
    ///   the job.
    /// It takes 2 days for all the jobs to be completed, so return 2.
    /// It can be proven that 2 days is the minimum number of days needed.
    ///
    /// Example 2:
    /// Input: jobs = [3,18,15,9], workers = [6,5,1,3]
    /// Output: 3
    /// Explanation:
    /// - Assign the 2nd worker to the 0th job. It takes them 3 days to finish 
    ///   the job.
    /// - Assign the 0th worker to the 1st job. It takes them 3 days to finish 
    ///   the job.
    /// - Assign the 1st worker to the 2nd job. It takes them 3 days to finish 
    ///   the job.
    /// - Assign the 3rd worker to the 3rd job. It takes them 3 days to finish 
    ///   the job.
    /// It takes 3 days for all the jobs to be completed, so return 3.
    /// It can be proven that 3 days is the minimum number of days needed.
    ///
    /// Constraints:
    /// 1. n == jobs.length == workers.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= jobs[i], workers[i] <= 10^5
    /// </summary>
    int minimumTime(vector<int>& jobs, vector<int>& workers);

    /// <summary>
    /// Leet Code 2332. The Latest Time to Catch a Bus
    ///                                                           
    /// Medium
    ///
    /// You are given a 0-indexed integer array buses of length n, where 
    /// buses[i] represents the departure time of the ith bus. You are also 
    /// given a 0-indexed integer array passengers of length m, where 
    /// passengers[j] represents the arrival time of the jth passenger. All 
    /// bus departure times are unique. All passenger arrival times are unique.
    ///
    /// You are given an integer capacity, which represents the maximum number 
    /// of passengers that can get on each bus.
    ///
    /// When a passenger arrives, they will wait in line for the next 
    /// available bus. You can get on a bus that departs at x minutes if you 
    /// arrive at y minutes where y <= x, and the bus is not full. Passengers 
    /// with the earliest arrival times get on the bus first.
    ///
    /// More formally when a bus arrives, either:
    ///
    /// If capacity or fewer passengers are waiting for a bus, they will all 
    /// get on the bus, or
    /// The capacity passengers with the earliest arrival times will get on 
    /// the bus.
    /// Return the latest time you may arrive at the bus station to catch a 
    /// bus. You cannot arrive at the same time as another passenger.
    ///
    /// Note: The arrays buses and passengers are not necessarily sorted.
    ///
    /// Example 1:
    /// Input: buses = [10,20], passengers = [2,17,18,19], capacity = 2
    /// Output: 16
    /// Explanation: Suppose you arrive at time 16.
    /// At time 10, the first bus departs with the 0th passenger. 
    /// At time 20, the second bus departs with you and the 1st passenger.
    /// Note that you may not arrive at the same time as another passenger, 
    /// which is why you must arrive before the 1st passenger to catch the bus.
    ///
    /// Example 2:
    /// Input: buses = [20,30,10], passengers = [19,13,26,4,25,11,21], 
    /// capacity = 2
    /// Output: 20
    /// Explanation: Suppose you arrive at time 20.
    /// At time 10, the first bus departs with the 3rd passenger. 
    /// At time 20, the second bus departs with the 5th and 1st 
    /// passengers.
    /// At time 30, the third bus departs with the 0th passenger and you.
    /// Notice if you had arrived any later, then the 6th passenger would have 
    /// taken your seat on the third bus.
    ///
    /// Constraints:
    /// 1. n == buses.length
    /// 2. m == passengers.length
    /// 3. 1 <= n, m, capacity <= 10^5
    /// 4. 2 <= buses[i], passengers[i] <= 10^9
    /// 5. Each element in buses is unique.
    /// 6. Each element in passengers is unique.
    /// </summary>
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity);

    /// <summary>
    /// Leet Code 2386. Find the K-Sum of an Array
    ///                                                  
    /// Hard
    ///
    /// You are given an integer array nums and a positive integer k. You 
    /// can choose any subsequence of the array and sum all of its elements 
    /// together.
    ///
    /// We define the K-Sum of the array as the kth largest subsequence sum 
    /// that can be obtained (not necessarily distinct).
    ///
    /// Return the K-Sum of the array.
    /// A subsequence is an array that can be derived from another array 
    /// by deleting some or no elements without changing the order of the 
    /// remaining elements.
    ///
    /// Note that the empty subsequence is considered to have a sum of 0.
    ///
    /// Example 1:
    /// Input: nums = [2,4,-2], k = 5
    /// Output: 2
    /// Explanation: All the possible subsequence sums that we can obtain are 
    /// the following sorted in decreasing order:
    /// - 6, 4, 4, 2, 2, 0, 0, -2.
    /// The 5-Sum of the array is 2.
    ///
    /// Example 2:
    /// Input: nums = [1,-2,3,4,-10,12], k = 16
    /// Output: 10
    /// Explanation: The 16-Sum of the array is 10.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^5
    /// 3. -10^9 <= nums[i] <= 10^9
    /// 4. 1 <= k <= min(2000, 2^n)
    /// </summary>
    long long kSum(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2387. Median of a Row Wise Sorted Matrix
    ///                                                  
    /// Medium
    ///
    /// Given an m x n matrix grid containing an odd number of integers where 
    /// each row is sorted in non-decreasing order, return the median of the 
    /// matrix.
    ///
    /// You must solve the problem in less than O(m * n) time complexity.
    /// 
    /// Example 1:
    /// Input: grid = [[1,1,2],[2,3,3],[1,3,4]]
    /// Output: 2
    /// Explanation: The elements of the matrix in sorted order are 
    /// 1,1,1,2,2,3,3,3,4. The median is 2.
    ///
    /// Example 2:
    /// Input: grid = [[1,1,3,3,4]]
    /// Output: 3
    /// Explanation: The elements of the matrix in sorted order are 
    /// 1,1,3,3,4. The median is 3.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 500
    /// 4. m and n are both odd.
    /// 5. 1 <= grid[i][j] <= 10^6
    /// 6. grid[i] is sorted in non-decreasing order.
    /// </summary>
    int matrixMedian(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2418. Sort the People
    ///                                                  
    /// Easy
    ///
    /// You are given an array of strings names, and an array heights that 
    /// consists of distinct positive integers. Both arrays are of length n.
    ///
    /// For each index i, names[i] and heights[i] denote the name and height 
    /// of the ith person.
    ///
    /// Return names sorted in descending order by the people's heights.
    ///
    /// Example 1:
    /// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
    /// Output: ["Mary","Emma","John"]
    /// Explanation: Mary is the tallest, followed by Emma and John.
    ///
    /// Example 2:
    /// Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
    /// Output: ["Bob","Alice","Bob"]
    /// Explanation: The first Bob is the tallest, followed by Alice and 
    /// the second Bob.
    /// 
    /// Constraints:
    /// 1. n == names.length == heights.length
    /// 2. 1 <= n <= 10^3
    /// 3. 1 <= names[i].length <= 20
    /// 4. 1 <= heights[i] <= 10^5
    /// 5. names[i] consists of lower and upper case English letters.
    /// 6. All the values of heights are distinct.
    /// </summary>
    vector<string> sortPeople(vector<string>& names, vector<int>& heights);

    /// <summary>
    /// Leet Code 2454. Next Greater Element IV
    /// 
    /// Hard
    ///	
    /// You are given a 0-indexed array of non-negative integers nums. For 
    /// each integer in nums, you must find its respective second greater 
    /// integer.
    ///
    /// The second greater integer of nums[i] is nums[j] such that:
    ///
    /// j > i
    /// nums[j] > nums[i]
    /// There exists exactly one index k such that nums[k] > nums[i] 
    /// and i < k < j.
    /// If there is no such nums[j], the second greater integer is 
    /// considered to be -1.
    ///
    /// For example, in the array [1, 2, 4, 3], the second greater 
    /// integer of 1 is 4, 2 is 3, and that of 3 and 4 is -1.
    /// Return an integer array answer, where answer[i] is the second 
    /// greater integer of nums[i].
    ///
    /// Example 1:
    /// Input: nums = [2,4,0,9,6]
    /// Output: [9,6,6,-1,-1]
    /// Explanation:
    /// 0th index: 4 is the first integer greater than 2, and 9 is 
    /// the second integer greater than 2, to the right of 2.
    /// 1st index: 9 is the first, and 6 is the second integer greater 
    /// than 4, to the right of 4.
    /// 2nd index: 9 is the first, and 6 is the second integer greater 
    /// than 0, to the right of 0.
    /// 3rd index: There is no integer greater than 9 to its right, so the 
    /// second greater integer is considered to be -1.
    /// 4th index: There is no integer greater than 6 to its right, so the 
    /// second greater integer is considered to be -1.
    /// Thus, we return [9,6,6,-1,-1].
    ///
    /// Example 2:
    /// Input: nums = [3,3]
    /// Output: [-1,-1]
    /// Explanation:
    /// We return [-1,-1] since neither integer has any integer greater than 
    /// it.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// </summary>
    vector<int> secondGreaterElement(vector<int>& nums);

    /// <summary>
    /// Leet Code 2491. Divide Players Into Teams of Equal Skill
    /// 
    /// Medium
    ///
    /// You are given a positive integer array skill of even length n where 
    /// skill[i] denotes the skill of the ith player. Divide the players into 
    /// n / 2 teams of size 2 such that the total skill of each team is equal.
    ///
    /// The chemistry of a team is equal to the product of the skills of the 
    /// players on that team.
    ///
    /// Return the sum of the chemistry of all the teams, or return -1 if 
    /// there is no way to divide the players into teams such that the total 
    /// skill of each team is equal.
    ///
    /// Example 1:
    /// Input: skill = [3,2,5,1,3,4]
    /// Output: 22
    /// Explanation: 
    /// Divide the players into the following teams: (1, 5), (2, 4), (3, 3), 
    /// where each team has a total skill of 6.
    /// The sum of the chemistry of all the teams is: 
    /// 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
    ///
    /// Example 2:
    /// Input: skill = [3,4]
    /// Output: 12
    /// Explanation: 
    /// The two players form a team with a total skill of 7.
    /// The chemistry of the team is 3 * 4 = 12.
    ///
    /// Example 3:
    /// Input: skill = [1,1,2,3]
    /// Output: -1
    /// Explanation: 
    /// There is no way to divide the players into teams such that the total 
    /// skill of each team is equal.
    /// 
    /// Constraints:
    /// 1. 2 <= skill.length <= 10^5
    /// 2. skill.length is even.
    /// 3. 1 <= skill[i] <= 1000
    /// </summary>
    long long dividePlayers(vector<int>& skill);

    /// <summary>
    /// Leet Code 2519. Count the Number of K-Big Indices
    /// 
    /// Hard
    ///	
    /// You are given a 0-indexed integer array nums and a positive integer k.
    ///
    /// We call an index i k-big if the following conditions are satisfied:
    ///
    /// There exist at least k different indices idx1 such that idx1 < i and 
    /// nums[idx1] < nums[i].
    /// There exist at least k different indices idx2 such that idx2 > i and 
    /// nums[idx2] < nums[i].
    /// Return the number of k-big indices.
    /// 
    /// Example 1:
    ///Input: nums = [2,3,6,5,2,3], k = 2
    /// Output: 2
    /// Explanation: There are only two 2-big indices in nums:
    /// - i = 2 --> There are two valid idx1: 0 and 1. There are three valid 
    /// idx2: 3, 4, and 5.
    /// - i = 3 --> There are two valid idx1: 0 and 1. There are two valid 
    /// idx2: 4 and 5.
    ///
    /// Example 2:
    /// Input: nums = [1,1,1], k = 3
    /// Output: 0
    /// Explanation: There are no 3-big indices in nums.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i], k <= nums.length
    /// </summary>
    int kBigIndices(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2530. Maximal Score After Applying K Operations
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums and an integer k. You 
    /// have a starting score of 0.
    ///
    /// In one operation:
    ///
    /// choose an index i such that 0 <= i < nums.length,
    /// increase your score by nums[i], and
    /// replace nums[i] with ceil(nums[i] / 3).
    /// Return the maximum possible score you can attain after applying 
    /// exactly k operations.
    ///
    /// The ceiling function ceil(val) is the least integer greater 
    /// than or equal to val.
    /// 
    /// Example 1:
    /// Input: nums = [10,10,10,10,10], k = 5
    /// Output: 50
    /// Explanation: Apply the operation to each array element exactly once. 
    /// The final score is 10 + 10 + 10 + 10 + 10 = 50.
    ///
    /// Example 2:
    /// Input: nums = [1,10,3,3,3], k = 3
    /// Output: 17
    /// Explanation: You can do the following operations:
    /// Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. 
    /// Your score increases by 10.
    /// Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. 
    /// Your score increases by 4.
    /// Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. 
    /// Your score increases by 3.
    /// The final score is 10 + 4 + 3 = 17.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length, k <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    long long maxKelements(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2548. Maximum Price to Fill a Bag
    /// 
    /// Medium
    ///	
    /// You are given a 2D integer array items where items[i] = 
    /// [pricei, weighti] denotes the price and weight of the ith item, 
    /// respectively.
    ///
    /// You are also given a positive integer capacity.
    /// 
    /// Each item can be divided into two items with ratios part1 and part2, 
    /// where part1 + part2 == 1.
    ///
    /// The weight of the first item is weighti * part1 and the price of the 
    /// first item is pricei * part1.
    /// Similarly, the weight of the second item is weighti * part2 and the 
    /// price of the second item is pricei * part2.
    /// Return the maximum total price to fill a bag of capacity capacity 
    /// with given items. If it is impossible to fill a bag return -1. Answers 
    /// within 10-5 of the actual answer will be considered accepted.
    ///
    /// Example 1:
    /// Input: items = [[50,1],[10,8]], capacity = 5
    /// Output: 55.00000
    /// Explanation: 
    /// We divide the 2nd item into two parts with part1 = 0.5 and part2 = 0.5.
    /// The price and weight of the 1st item are 5, 4. And similarly, the price
    /// and the weight of the 2nd item are 5, 4.
    /// The array items after operation becomes [[50,1],[5,4],[5,4]]. 
    /// To fill a bag with capacity 5 we take the 1st element with a price 
    /// of 50 and the 2nd element with a price of 5.
    /// It can be proved that 55.0 is the maximum total price that we can 
    /// achieve.
    ///
    /// Example 2:
    /// Input: items = [[100,30]], capacity = 50
    /// Output: -1.00000
    /// Explanation: It is impossible to fill a bag with the given item.
    ///
    /// Constraints:
    /// 1. 1 <= items.length <= 10^5
    /// 2. items[i].length == 2
    /// 3. 1 <= pricei, weighti <= 10^4
    /// 4. 1 <= capacity <= 10^9
    /// </summary>
    double maxPrice(vector<vector<int>>& items, int capacity);

    /// <summary>
    /// Leet Code 2551. Put Marbles in Bags
    /// 
    /// Hard
    ///	
    /// You have k bags. You are given a 0-indexed integer array weights where 
    /// weights[i] is the weight of the ith marble. You are also given the 
    /// integer k.
    /// Divide the marbles into the k bags according to the following rules:
    /// 
    /// No bag is empty.
    /// If the ith marble and jth marble are in a bag, then all marbles with 
    /// an index between the ith and jth indices should also be in that same 
    /// bag.
    /// If a bag consists of all the marbles with an index from i to j 
    /// inclusively, then the cost of the bag is weights[i] + weights[j].
    /// The score after distributing the marbles is the sum of the costs of 
    /// all the k bags.
    ///
    /// Return the difference between the maximum and minimum scores among 
    /// marble distributions.
    /// 
    /// Example 1:
    /// Input: weights = [1,3,5,1], k = 2
    /// Output: 4
    /// Explanation: 
    /// The distribution [1],[3,5,1] results in the minimal score of 
    /// (1+1) + (3+1) = 6. 
    /// The distribution [1,3],[5,1], results in the maximal score of 
    /// (1+3) + (5+1) = 10. 
    /// Thus, we return their difference 10 - 6 = 4.
    ///
    /// Example 2:
    /// Input: weights = [1, 3], k = 2
    /// Output: 0
    /// Explanation: The only distribution possible is [1],[3]. 
    /// Since both the maximal and minimal score are the same, we return 0.
    ///
    /// Constraints:
    /// 1. 1 <= k <= weights.length <= 10^5
    /// 2. 1 <= weights[i] <= 10^9
    /// </summary>
    long long putMarbles(vector<int>& weights, int k);

    /// <summary>
    /// Leet Code 2558. Take Gifts From the Richest Pile
    /// 
    /// Easy
    ///	
    /// You are given an integer array gifts denoting the number of gifts 
    /// in various piles. Every second, you do the following:
    ///
    /// Choose the pile with the maximum number of gifts.
    /// If there is more than one pile with the maximum number of gifts, 
    /// choose any.
    /// Leave behind the floor of the square root of the number of gifts 
    /// in the pile. Take the rest of the gifts.
    /// Return the number of gifts remaining after k seconds.
    /// 
    /// Example 1:
    /// Input: gifts = [25,64,9,4,100], k = 4
    /// Output: 29
    /// Explanation: 
    /// The gifts are taken in the following way:
    /// - In the first second, the last pile is chosen and 10 gifts are left 
    ///   behind.
    /// - Then the second pile is chosen and 8 gifts are left behind.
    /// - After that the first pile is chosen and 5 gifts are left behind.
    /// - Finally, the last pile is chosen again and 3 gifts are left behind.
    /// The final remaining gifts are [5,8,9,4,3], so the total number of 
    /// gifts remaining is 29.
    ///
    /// Example 2:
    /// Input: gifts = [1,1,1,1], k = 4
    /// Output: 4
    /// Explanation: 
    /// In this case, regardless which pile you choose, you have to leave 
    /// behind 1 gift in each pile. 
    /// That is, you can't take any pile with you. 
    /// So, the total gifts remaining are 4.
    ///
    /// Constraints:
    /// 1. 1 <= gifts.length <= 10^3
    /// 2. 1 <= gifts[i] <= 10^9
    /// 3. 1 <= k <= 10^3
    /// </summary>
    long long pickGifts(vector<int>& gifts, int k);

    /// <summary>
    /// Leet Code 2561. Rearranging Fruits
    /// 
    /// Hard
    ///	
    /// You have two fruit baskets containing n fruits each. You are given 
    /// two 0-indexed integer arrays basket1 and basket2 representing the 
    /// cost of fruit in each basket. You want to make both baskets equal. 
    /// To do so, you can use the following operation as many times as you 
    /// want:
    ///
    /// Chose two indices i and j, and swap the ith fruit of basket1 with 
    /// the jth fruit of basket2.
    /// The cost of the swap is min(basket1[i],basket2[j]).
    /// Two baskets are considered equal if sorting them according to the 
    /// fruit cost makes them exactly the same baskets.
    ///
    /// Return the minimum cost to make both the baskets equal or -1 if 
    /// impossible.
    ///
    /// Example 1:
    /// Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
    /// Output: 1
    /// Explanation: Swap index 1 of basket1 with index 0 of basket2, which 
    /// has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. 
    /// Rearranging both the arrays makes them equal.
    ///
    /// Example 2:
    /// Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
    /// Output: -1
    /// Explanation: It can be shown that it is impossible to make both the 
    /// baskets equal.
    /// 
    /// Constraints:
    /// 1. basket1.length == bakste2.length
    /// 2. 1 <= basket1.length <= 10^5
    /// 3. 1 <= basket1[i],basket2[i] <= 10^9
    /// </summary>
    long long minCost(vector<int>& basket1, vector<int>& basket2);

    /// <summary>
    /// Leet Code 2567. Minimum Score by Changing Two Elements
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums.
    ///
    /// The low score of nums is the minimum value of |nums[i] - nums[j]| 
    /// over all 0 <= i < j < nums.length.
    /// The high score of nums is the maximum value of |nums[i] - nums[j]| 
    /// over all 0 <= i < j < nums.length.
    /// The score of nums is the sum of the high and low scores of nums.
    /// To minimize the score of nums, we can change the value of at most 
    /// two elements of nums.
    ///
    /// Return the minimum possible score after changing the value of at 
    /// most two elements of nums.
    ///
    /// Note that |x| denotes the absolute value of x.
    ///
    /// Example 1:
    /// Input: nums = [1,4,3]
    /// Output: 0
    /// Explanation: Change value of nums[1] and nums[2] to 1 so that nums 
    /// becomes [1,1,1]. Now, the value of |nums[i] - nums[j]| is always 
    /// equal to 0, so we return 0 + 0 = 0.
    ///
    /// Example 2:
    /// Input: nums = [1,4,7,8,5]
    /// Output: 3
    /// Explanation: Change nums[0] and nums[1] to be 6. Now nums 
    /// becomes [6,6,7,8,5]. 
    /// Our low score is achieved when i = 0 and j = 1, in which 
    /// case |nums[i] - nums[j]| = |6 - 6| = 0.
    /// Our high score is achieved when i = 3 and j = 4, in which 
    /// case |nums[i] - nums[j]| = |8 - 5| = 3.
    /// The sum of our high and low score is 3, which we can prove to 
    /// be minimal.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    int minimizeSum(vector<int>& nums);

    /// <summary>
    /// Leet Code 2594. Minimum Time to Repair Cars
    /// 
    /// Medium
    ///	
    /// You are given an integer array ranks representing the ranks of some 
    /// mechanics. ranksi is the rank of the ith mechanic. A mechanic with a 
    /// rank r can repair n cars in r * n2 minutes.
    ///
    /// You are also given an integer cars representing the total number of 
    /// cars waiting in the garage to be repaired.
    ///
    /// Return the minimum time taken to repair all the cars.
    ///
    /// Note: All the mechanics can repair the cars simultaneously.
    ///
    /// Example 1:
    /// Input: ranks = [4,2,3,1], cars = 10
    /// Output: 16
    /// Explanation: 
    /// - The first mechanic will repair two cars. The time required 
    ///   is 4 * 2 * 2 = 16 minutes.
    /// - The second mechanic will repair two cars. The time required 
    ///   is 2 * 2 * 2 = 8 minutes.
    /// - The third mechanic will repair two cars. The time required 
    ///   is 3 * 2 * 2 = 12 minutes.
    /// - The fourth mechanic will repair four cars. The time required 
    ///   is 1 * 4 * 4 = 16 minutes.
    /// It can be proved that the cars cannot be repaired in less than 16 
    /// minutes.
    ///
    /// Example 2:
    /// Input: ranks = [5,1,8], cars = 6
    /// Output: 16
    /// Explanation: 
    /// - The first mechanic will repair one car. The time required 
    ///   is 5 * 1 * 1 = 5 minutes.
    /// - The second mechanic will repair four cars. The time required 
    ///   is 1 * 4 * 4 = 16 minutes.
    /// - The third mechanic will repair one car. The time required 
    ///   is 8 * 1 * 1 = 8 minutes.
    /// It can be proved that the cars cannot be repaired in less 
    /// than 16 minutes.
    ///
    /// Constraints:
    /// 1. 1 <= ranks.length <= 10^5
    /// 2. 1 <= ranks[i] <= 100
    /// 3. 1 <= cars <= 106
    /// </summary>
    long long repairCars(vector<int>& ranks, int cars);

    /// <summary>
    /// Leet Code 2599. Make the Prefix Sum Non-negative
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums. You can apply the 
    /// following operation any number of times:
    ///
    /// Pick any element from nums and put it at the end of nums.
    /// The prefix sum array of nums is an array prefix of the same length 
    /// as nums such that prefix[i] is the sum of all the integers nums[j] 
    /// where j is in the inclusive range [0, i].
    ///
    /// Return the minimum number of operations such that the prefix sum 
    /// array does not contain negative integers. The test cases are generated 
    /// such that it is always possible to make the prefix sum array 
    /// non-negative.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [2,3,-5,4]
    /// Output: 0
    /// Explanation: we do not need to do any operations.
    /// The array is [2,3,-5,4]. The prefix sum array is [2, 5, 0, 4].
    ///
    /// Example 2:
    ///
    /// Input: nums = [3,-5,-2,6]
    /// Output: 1
    /// Explanation: we can do one operation on index 1.
    /// The array after the operation is [3,-2,6,-5]. The prefix sum 
    /// array is [3, 1, 7, 2].
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// </summary>
    int makePrefSumNonNegative(vector<int>& nums);

    /// <summary>
    /// Leet Code 2611. Mice and Cheese
    /// 
    /// Medium
    ///	
    /// There are two mice and n different types of cheese, each type of 
    /// cheese should be eaten by exactly one mouse.
    ///
    /// A point of the cheese with index i (0-indexed) is:
    ///
    /// reward1[i] if the first mouse eats it.
    /// reward2[i] if the second mouse eats it.
    /// You are given a positive integer array reward1, a positive integer 
    /// array reward2, and a non-negative integer k.
    ///
    /// Return the maximum points the mice can achieve if the first mouse 
    /// eats exactly k types of cheese.
    ///
    /// Example 1:
    ///
    /// Input: reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
    /// Output: 15
    /// Explanation: In this example, the first mouse eats the 2nd (0-indexed) 
    /// and the 3rd types of cheese, and the second mouse eats the 0th and 
    /// the 1st types of cheese.
    /// The total points are 4 + 4 + 3 + 4 = 15.
    /// It can be proven that 15 is the maximum total points that the mice 
    /// can achieve.
    ///
    /// Example 2:
    /// Input: reward1 = [1,1], reward2 = [1,1], k = 2
    /// Output: 2
    /// Explanation: In this example, the first mouse eats the 0th (0-indexed) 
    /// and 1st types of cheese, and the second mouse does not eat any cheese.
    /// The total points are 1 + 1 = 2.
    /// It can be proven that 2 is the maximum total points that the mice can 
    /// achieve.
    /// 
    /// Constraints:
    /// 1. 1 <= n == reward1.length == reward2.length <= 10^5
    /// 2. 1 <= reward1[i], reward2[i] <= 1000
    /// 3. 0 <= k <= n
    /// </summary>
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k);

    /// <summary>
    /// Leet Code 2613. Beautiful Pairs
    /// 
    /// Hard
    ///	
    /// You are given two 0-indexed integer arrays nums1 and nums2 of the same 
    /// length. A pair of indices (i,j) is called beautiful 
    /// if|nums1[i] - nums1[j]| + |nums2[i] - nums2[j]| is the smallest 
    /// amongst all possible indices pairs where i < j.
    ///
    /// Return the beautiful pair. In the case that there are multiple 
    /// beautiful pairs, return the lexicographically smallest pair.
    ///
    /// Note that
    /// |x| denotes the absolute value of x.
    /// A pair of indices (i1, j1) is lexicographically smaller than (i2, j2) 
    /// if i1 < i2 or i1 == i2 and j1 < j2.
    ///
    /// Example 1:
    /// Input: nums1 = [1,2,3,2,4], nums2 = [2,3,1,2,3]
    /// Output: [0,3]
    /// Explanation: Consider index 0 and index 3. The value of 
    /// |nums1[i]-nums1[j]| + |nums2[i]-nums2[j]| is 1, which is the smallest 
    /// value we can achieve.
    ///
    /// Example 2:
    /// Input: nums1 = [1,2,4,3,2,5], nums2 = [1,4,2,3,5,1]
    /// Output: [1,4]
    /// Explanation: Consider index 1 and index 4. The value of 
    /// |nums1[i]-nums1[j]| + |nums2[i]-nums2[j]| is 1, which is the smallest 
    /// value we can achieve.
    ///
    /// Constraints:
    /// 1. 2 <= nums1.length, nums2.length <= 10^5
    /// 2. nums1.length == nums2.length
    /// 3. 0 <= nums1i <= nums1.length
    /// 4. 0 <= nums2i <= nums2.length
    /// </summary>
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2653. Sliding Subarray Beauty
    /// 
    /// Medium
    ///	
    /// Given an integer array nums containing n integers, find the beauty of 
    /// each subarray of size k.
    ///
    /// The beauty of a subarray is the xth smallest integer in the subarray 
    /// if it is negative, or 0 if there are fewer than x negative integers.
    ///
    /// Return an integer array containing n - k + 1 integers, which denote 
    /// the beauty of the subarrays in order from the first index in the array.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    /// 
    /// Example 1:
    /// Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
    /// Output: [-1,-2,-2]
    /// Explanation: There are 3 subarrays with size k = 3. 
    /// The first subarray is [1, -1, -3] and the 2nd smallest negative 
    /// integer is -1. 
    /// The second subarray is [-1, -3, -2] and the 2nd smallest negative 
    /// integer is -2. 
    /// The third subarray is [-3, -2, 3] and the 2nd smallest negative 
    /// integer is -2.
    ///
    /// Example 2:
    /// Input: nums = [-1,-2,-3,-4,-5], k = 2, x = 2
    /// Output: [-1,-2,-3,-4]
    /// Explanation: There are 4 subarrays with size k = 2.
    /// For [-1, -2], the 2nd smallest negative integer is -1.
    /// For [-2, -3], the 2nd smallest negative integer is -2.
    /// For [-3, -4], the 2nd smallest negative integer is -3.
    /// For [-4, -5], the 2nd smallest negative integer is -4. 
    ///
    /// Example 3:
    /// Input: nums = [-3,1,2,-3,0,-3], k = 2, x = 1
    /// Output: [-3,0,-3,-3,-3]
    /// Explanation: There are 5 subarrays with size k = 2.
    /// For [-3, 1], the 1st smallest negative integer is -3.
    /// For [1, 2], there is no negative integer so the beauty is 0.
    /// For [2, -3], the 1st smallest negative integer is -3.
    /// For [-3, 0], the 1st smallest negative integer is -3.
    /// For [0, -3], the 1st smallest negative integer is -3.
    ///
    /// Constraints:
    /// 1. n == nums.length 
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= k <= n
    /// 4. 1 <= x <= k 
    /// 5. -50 <= nums[i] <= 50 
    /// </summary>
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x);

    /// <summary>
    /// Leet Code 2659. Make Array Empty
    /// 
    /// Hard
    ///	
    /// You are given an integer array nums containing distinct numbers, and 
    /// you can perform the following operations until the array is empty:
    ///
    /// If the first element has the smallest value, remove it
    /// Otherwise, put the first element at the end of the array.
    /// Return an integer denoting the number of operations it takes to make 
    /// nums empty.
    ///
    /// Example 1:
    ///
    /// Input: nums = [3,4,-1]
    /// Output: 5
    /// Operation Array
    /// 1 [4, -1, 3]
    /// 2 [-1, 3, 4]
    /// 3 [3, 4]
    /// 4 [4]
    /// 5 []
    ///
    /// Example 2:
    /// Input: nums = [1,2,4,3]
    /// Output: 5
    /// Operation Array
    /// 1 [2, 4, 3]
    /// 2 [4, 3]
    /// 3 [3, 4]
    /// 4 [4]
    /// 5 []
    ///
    /// Example 3:
    /// Input: nums = [1,2,3]
    /// Output: 3
    /// Operation Array
    /// 1 [2, 3]
    /// 2 [3]
    /// 3 []
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// 3. All values in nums are distinct.
    /// </summary>
    long long countOperationsToEmptyArray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2679. Sum in a Matrix
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed 2D integer array nums. Initially, your score 
    /// is 0. Perform the following operations until the matrix becomes empty:
    ///
    /// From each row in the matrix, select the largest number and remove it. 
    /// In the case of a tie, it does not matter which number is chosen.
    /// Identify the highest number amongst all those removed in step 1. Add 
    /// that number to your score.
    /// Return the final score.
    /// 
    /// Example 1:
    /// Input: nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
    /// Output: 15
    /// Explanation: In the first operation, we remove 7, 6, 6, and 3. We 
    /// then add 7 to our score. Next, we remove 2, 4, 5, and 2. We add 5 to 
    /// our score. Lastly, we remove 1, 2, 3, and 1. We add 3 to our score. 
    /// Thus, our final score is 7 + 5 + 3 = 15.
    ///
    /// Example 2:
    /// Input: nums = [[1]]
    /// Output: 1
    /// Explanation: We remove 1 and add it to the answer. We return 1.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 300
    /// 2. 1 <= nums[i].length <= 500
    /// 3. 0 <= nums[i][j] <= 10^3
    /// </summary>
    int matrixSum(vector<vector<int>>& nums);

    /// <summary>
    /// Leet Code 2740. Find the Value of the Partition
    /// 
    /// Medium
    ///
    /// You are given a positive integer array nums.
    /// Partition nums into two arrays, nums1 and nums2, such that:
    /// Each element of the array nums belongs to either the array nums1 or 
    /// the array nums2.
    /// Both arrays are non-empty.
    /// The value of the partition is minimized.
    /// The value of the partition is |max(nums1) - min(nums2)|.
    ///
    /// Here, max(nums1) denotes the maximum element of the array nums1, and 
    /// min(nums2) denotes the minimum element of the array nums2.
    ///
    /// Return the integer denoting the value of such partition.
    ///
    /// Example 1:
    /// Input: nums = [1,3,2,4]
    /// Output: 1
    /// Explanation: We can partition the array nums into nums1 = [1,2] and 
    /// nums2 = [3,4].
    /// - The maximum element of the array nums1 is equal to 2.
    /// - The minimum element of the array nums2 is equal to 3.
    /// The value of the partition is |2 - 3| = 1. 
    /// It can be proven that 1 is the minimum value out of all partitions.
    ///
    /// Example 2:
    /// Input: nums = [100,1,10]
    /// Output: 9
    /// Explanation: We can partition the array nums into nums1 = [10] and 
    /// nums2 = [100,1].
    /// - The maximum element of the array nums1 is equal to 10.
    /// - The minimum element of the array nums2 is equal to 1.
    /// The value of the partition is |10 - 1| = 9.
    /// It can be proven that 9 is the minimum value out of all partitions.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    int findValueOfPartition(vector<int>& nums);

    /// <summary>
    /// Leet Code 2736. Maximum Sum Queries
    /// 
    /// Hard
    ///
    /// You are given two 0-indexed integer arrays nums1 and nums2, each of 
    /// length n, and a 1-indexed 2D array queries where queries[i] = [xi, yi].
    ///
    /// For the ith query, find the maximum value of nums1[j] + nums2[j] among 
    /// all indices j (0 <= j < n), where nums1[j] >= xi and nums2[j] >= yi, 
    /// or -1 if there is no j satisfying the constraints.
    ///
    /// Return an array answer where answer[i] is the answer to the ith query.
    /// 
    /// Example 1:
    /// Input: nums1 = [4,3,1,2], nums2 = [2,4,9,5], 
    /// queries = [[4,1],[1,3],[2,5]]
    /// Output: [6,10,7]
    /// Explanation: 
    /// For the 1st query xi = 4 and yi = 1, we can select index j = 0 since 
    /// nums1[j] >= 4 and nums2[j] >= 1. The sum nums1[j] + nums2[j] is 6, 
    /// and we can show that 6 is the maximum we can obtain.
    ///
    /// For the 2nd query xi = 1 and yi = 3, we can select index j = 2 since 
    /// nums1[j] >= 1 and nums2[j] >= 3. The sum nums1[j] + nums2[j] is 10, 
    /// and we can show that 10 is the maximum we can obtain. 
    ///
    /// For the 3rd query xi = 2 and yi = 5, we can select index j = 3 since 
    /// nums1[j] >= 2 and nums2[j] >= 5. The sum nums1[j] + nums2[j] is 7, 
    /// and we can show that 7 is the maximum we can obtain.
    ///
    /// Therefore, we return [6,10,7].
    ///
    /// Example 2:
    /// Input: nums1 = [3,2,5], nums2 = [2,3,4], queries = [[4,4],[3,2],[1,1]]
    /// Output: [9,9,9]
    /// Explanation: For this example, we can use index j = 2 for all the 
    /// queries since it satisfies the constraints for each query.
    ///
    /// Example 3:
    /// Input: nums1 = [2,1], nums2 = [2,3], queries = [[3,3]]
    /// Output: [-1]
    /// Explanation: There is one query in this example with xi = 3 and yi = 3. 
    /// For every index, j, either nums1[j] < xi or nums2[j] < yi. Hence, there 
    /// is no solution. 
    /// 
    /// Constraints:
    /// 1. nums1.length == nums2.length 
    /// 2. n == nums1.length 
    /// 3. 1 <= n <= 10^5
    /// 4. 1 <= nums1[i], nums2[i] <= 10^9 
    /// 5. 1 <= queries.length <= 10^5
    /// 6. queries[i].length == 2
    /// 7. xi == queries[i][1]
    /// 8. yi == queries[i][2]
    /// 9. 1 <= xi, yi <= 10^9
    /// </summary>
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, 
        vector<vector<int>>& queries);


    /// <summary>
    /// Leet Code 2763. Sum of Imbalance Numbers of All Subarrays
    /// 
    /// Hard
    ///
    /// The imbalance number of a 0-indexed integer array arr of length n is 
    /// defined as the number of indices in sarr = sorted(arr) such that:
    ///
    /// 0 <= i < n - 1, and
    /// sarr[i+1] - sarr[i] > 1
    /// Here, sorted(arr) is the function that returns the sorted version of 
    /// arr.
    /// 
    /// Given a 0-indexed integer array nums, return the sum of imbalance 
    /// numbers of all its subarrays.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    ///  
    /// Example 1:
    /// Input: nums = [2,3,1,4]
    /// Output: 3
    /// Explanation: There are 3 subarrays with non-zero imbalance numbers:
    /// - Subarray [3, 1] with an imbalance number of 1.
    /// - Subarray [3, 1, 4] with an imbalance number of 1.
    /// - Subarray [1, 4] with an imbalance number of 1.
    /// The imbalance number of all other subarrays is 0. Hence, the sum of 
    /// imbalance numbers of all the subarrays of nums is 3. 
    ///
    /// Example 2:
    /// Input: nums = [1,3,3,3,5]
    /// Output: 8
    /// Explanation: There are 7 subarrays with non-zero imbalance numbers:
    /// - Subarray [1, 3] with an imbalance number of 1.
    /// - Subarray [1, 3, 3] with an imbalance number of 1.
    /// - Subarray [1, 3, 3, 3] with an imbalance number of 1.
    /// - Subarray [1, 3, 3, 3, 5] with an imbalance number of 2. 
    /// - Subarray [3, 3, 3, 5] with an imbalance number of 1. 
    /// - Subarray [3, 3, 5] with an imbalance number of 1.
    /// - Subarray [3, 5] with an imbalance number of 1.
    /// The imbalance number of all other subarrays is 0. Hence, the sum of 
    /// imbalance numbers of all the subarrays of nums is 8. 
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= nums.length
    /// </summary>
    int sumImbalanceNumbers(vector<int>& nums);

    /// <summary>
    /// Leet 2817. Minimum Absolute Difference Between Elements With Constraint
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums and an integer x.
    ///
    /// Find the minimum absolute difference between two elements in the array 
    /// that are at least x indices apart.
    ///
    /// In other words, find two indices i and j such that abs(i - j) >= x and 
    /// abs(nums[i] - nums[j]) is minimized.
    ///
    /// Return an integer denoting the minimum absolute difference between two 
    /// elements that are at least x indices apart.
    ///
    /// Example 1:
    /// Input: nums = [4,3,2,4], x = 2
    /// Output: 0
    /// Explanation: We can select nums[0] = 4 and nums[3] = 4. 
    /// They are at least 2 indices apart, and their absolute difference is 
    /// the minimum, 0. 
    /// It can be shown that 0 is the optimal answer.
    ///
    /// Example 2:
    /// Input: nums = [5,3,2,10,15], x = 1
    /// Output: 1
    /// Explanation: We can select nums[1] = 3 and nums[2] = 2.
    /// They are at least 1 index apart, and their absolute difference is the 
    /// minimum, 1.
    /// It can be shown that 1 is the optimal answer.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3,4], x = 3
    /// Output: 3
    /// Explanation: We can select nums[0] = 1 and nums[3] = 4.
    /// They are at least 3 indices apart, and their absolute difference is 
    /// the minimum, 3.
    /// It can be shown that 3 is the optimal answer.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 0 <= x < nums.length
    /// </summary>
    int minAbsoluteDifference(vector<int>& nums, int x);

    /// <summary>
    /// Leet Code 2835. Minimum Operations to Form Subsequence With Target Sum
    /// 
    /// Hard
    ///
    /// You are given a 0-indexed array nums consisting of non-negative powers 
    /// of 2, and an integer target.
    ///
    /// In one operation, you must apply the following changes to the array:
    ///
    /// Choose any element of the array nums[i] such that nums[i] > 1.
    /// Remove nums[i] from the array.
    /// Add two occurrences of nums[i] / 2 to the end of nums.
    /// Return the minimum number of operations you need to perform so that 
    /// nums contains a subsequence whose elements sum to target. If it is 
    /// impossible to obtain such a subsequence, return -1.
    ///
    /// A subsequence is an array that can be derived from another array by 
    /// deleting some or no elements without changing the order of the 
    /// remaining elements.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,2,8], target = 7
    /// Output: 1
    /// Explanation: In the first operation, we choose element nums[2]. 
    /// The array becomes equal to nums = [1,2,4,4].
    /// At this stage, nums contains the subsequence [1,2,4] which sums 
    /// up to 7.
    /// It can be shown that there is no shorter sequence of operations 
    /// that results in a subsequnce that sums up to 7.
    ///
    /// Example 2:
    /// Input: nums = [1,32,1,2], target = 12
    /// Output: 2
    /// Explanation: In the first operation, we choose element nums[1]. 
    /// The array becomes equal to nums = [1,1,2,16,16].
    /// In the second operation, we choose element nums[3]. The array 
    /// becomes equal to nums = [1,1,2,16,8,8]
    /// At this stage, nums contains the subsequence [1,1,2,8] which 
    /// sums up to 12.
    /// It can be shown that there is no shorter sequence of operations 
    /// that results in a subsequence that sums up to 12.
    ///
    /// Example 3:
    /// Input: nums = [1,32,1], target = 35
    /// Output: -1
    /// Explanation: It can be shown that no sequence of operations 
    /// results in a subsequence that sums up to 35.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 2^30
    /// 3. nums consists only of non-negative powers of two.
    /// 4. 1 <= target < 2^31
    /// </summary>
    int minOperations(vector<int>& nums, int target);

    /// <summary>
    /// Leet Code 2838. Maximum Coins Heroes Can Collect
    /// 
    /// Medium
    ///
    /// There is a battle and n heroes are trying to defeat m monsters. You 
    /// are given two 1-indexed arrays of positive integers heroes and 
    /// monsters of length n and m, respectively. heroes[i] is the power of 
    /// ith hero, and monsters[i] is the power of ith monster.
    ///
    /// The ith hero can defeat the jth monster if monsters[j] <= heroes[i].
    ///
    /// You are also given a 1-indexed array coins of length m consisting of 
    /// positive integers. coins[i] is the number of coins that each hero 
    /// earns after defeating the ith monster.
    ///
    /// Return an array ans of length n where ans[i] is the maximum number 
    /// of coins that the ith hero can collect from this battle.
    ///
    /// Notes
    ///
    /// The health of a hero doesn't get reduced after defeating a monster.
    /// Multiple heroes can defeat a monster, but each monster can be 
    /// defeated by a given hero only once.
    ///
    /// Example 1:
    /// Input: heroes = [1,4,2], monsters = [1,1,5,2,3], coins = [2,3,4,5,6]
    /// Output: [5,16,10]
    /// Explanation: For each hero, we list the index of all the monsters 
    /// he can defeat:
    /// 1st hero: [1,2] since the power of this hero is 1 and monsters[1], 
    /// monsters[2] <= 1. So this hero collects coins[1] + coins[2] = 5 coins.
    /// 2nd hero: [1,2,4,5] since the power of this hero is 4 and monsters[1], 
    /// monsters[2], monsters[4], monsters[5] <= 4. So this hero collects 
    /// coins[1] + coins[2] + coins[4] + coins[5] = 16 coins.
    /// 3rd hero: [1,2,4] since the power of this hero is 2 and monsters[1], 
    /// monsters[2], monsters[4] <= 2. So this hero collects 
    /// coins[1] + coins[2] + coins[4] = 10 coins.
    /// So the answer would be [5,16,10].
    ///
    /// Example 2:
    ///
    /// Input: heroes = [5], monsters = [2,3,1,2], coins = [10,6,5,2]
    /// Output: [23]
    /// Explanation: This hero can defeat all the monsters since 
    /// monsters[i] <= 5. So he collects all of the coins: coins[1] + 
    /// coins[2] + coins[3] + coins[4] = 23, and the answer would be [23].
    ///
    /// Example 3:
    /// Input: heroes = [4,4], monsters = [5,7,8], coins = [1,1,1]
    /// Output: [0,0]
    /// Explanation: In this example, no hero can defeat a monster. So the 
    /// answer would be [0,0],
    /// 
    /// Constraints:
    /// 1. 1 <= n == heroes.length <= 10^5
    /// 2. 1 <= m == monsters.length <= 10^5
    /// 3. coins.length == m
    /// 4. 1 <= heroes[i], monsters[i], coins[i] <= 10^9
    /// </summary>
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins);

    /// <summary>
    /// Leet Code 2855. Minimum Right Shifts to Sort the Array
    /// 
    /// Easy
    ///
    /// You are given a 0-indexed array nums of length n containing distinct 
    /// positive integers. Return the minimum number of right shifts required 
    /// to sort nums and -1 if this is not possible.
    ///
    /// A right shift is defined as shifting the element at index i to index 
    /// (i + 1) % n, for all indices.
    ///
    /// Example 1: 
    /// Input: nums = [3,4,5,1,2]
    /// Output: 2
    /// Explanation: 
    /// After the first right shift, nums = [2,3,4,5,1].
    /// After the second right shift, nums = [1,2,3,4,5].
    /// Now nums is sorted; therefore the answer is 2.
    ///
    /// Example 2:
    /// Input: nums = [1,3,5]
    /// Output: 0
    /// Explanation: nums is already sorted therefore, the answer is 0.
    ///
    /// Example 3:
    /// Input: nums = [2,1,4]
    /// Output: -1
    /// Explanation: It's impossible to sort the array using right shifts.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// 3. nums contains distinct integers.
    /// </summary>
    int minimumRightShifts(vector<int>& nums);

    /// <summary>
    /// Leet Code 2856. Minimum Array Length After Pair Removals
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed sorted array of integers nums.
    ///
    /// You can perform the following operation any number of times:
    ///
    /// Choose two indices, i and j, where i < j, such that nums[i] < nums[j].
    ///
    /// Then, remove the elements at indices i and j from nums. The remaining 
    /// elements retain their original order, and the array is re-indexed.
    /// Return an integer that denotes the minimum length of nums after 
    /// performing the operation any number of times (including zero).
    ///
    /// Note that nums is sorted in non-decreasing order.
    /// Example 1:
    /// Input: nums = [1,3,4,9]
    /// Output: 0
    /// Explanation: Initially, nums = [1, 3, 4, 9].
    /// In the first operation, we can choose index 0 and 1 because 
    /// nums[0] < nums[1] <=> 1 < 3.
    /// Remove indices 0 and 1, and nums becomes [4, 9].
    /// For the next operation, we can choose index 0 and 1 because 
    /// nums[0] < nums[1] <=> 4 < 9.
    /// Remove indices 0 and 1, and nums becomes an empty array [].
    /// Hence, the minimum length achievable is 0.
    ///
    /// Example 2:
    /// Input: nums = [2,3,6,9]
    /// Output: 0
    /// Explanation: Initially, nums = [2, 3, 6, 9]. 
    /// In the first operation, we can choose index 0 and 2 because 
    /// nums[0] < nums[2] <=> 2 < 6. 
    /// Remove indices 0 and 2, and nums becomes [3, 9]. 
    /// For the next operation, we can choose index 0 and 1 because 
    /// nums[0] < nums[1] <=> 3 < 9. 
    /// Remove indices 0 and 1, and nums becomes an empty array []. 
    /// Hence, the minimum length achievable is 0.
    ///
    /// Example 3:
    /// Input: nums = [1,1,2]
    /// Output: 1
    /// Explanation: Initially, nums = [1, 1, 2].
    /// In an operation, we can choose index 0 and 2 because 
    /// nums[0] < nums[2] <=> 1 < 2. 
    /// Remove indices 0 and 2, and nums becomes [1]. 
    /// It is no longer possible to perform an operation on the array. 
    /// Hence, the minimum achievable length is 1. 
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. nums is sorted in non-decreasing order.
    /// </summary>
    int minLengthAfterRemovals(vector<int>& nums);

    /// <summary>
    /// Leet Code 2860. Happy Students
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums of length n where n is 
    /// the total number of students in the class. The class teacher tries 
    /// to select a group of students so that all the students remain happy.
    ///
    /// The ith student will become happy if one of these two conditions is 
    /// met:
    ///
    /// The student is selected and the total number of selected students is 
    /// strictly greater than nums[i].
    /// The student is not selected and the total number of selected students 
    /// is strictly less than nums[i].
    /// Return the number of ways to select a group of students so that 
    /// everyone remains happy.
    ///
    /// Example 1:
    /// Input: nums = [1,1]
    /// Output: 2
    /// Explanation: 
    /// The two possible ways are:
    /// The class teacher selects no student.
    /// The class teacher selects both students to form the group. 
    /// If the class teacher selects just one student to form a group then the 
    /// both students will not be happy. Therefore, there are only two 
    /// possible ways.
    ///
    /// Example 2:
    /// Input: nums = [6,0,3,3,6,7,2,7]
    /// Output: 3
    /// Explanation: 
    /// The three possible ways are:
    /// The class teacher selects the student with index = 1 to form the group.
    /// The class teacher selects the students with index = 1, 2, 3, 6 to form 
    /// the group.
    /// The class teacher selects all the students to form the group.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] < nums.length
    /// </summary>
    int countWays(vector<int>& nums);

    /// <summary>
    /// Leet Code 2863. Maximum Length of Semi-Decreasing Subarrays
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums.
    /// Return the length of the longest semi-decreasing subarray of 
    /// nums, and 0 if there are no such subarrays.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within 
    /// an array.
    /// A non-empty array is semi-decreasing if its first element is 
    /// strictly greater than its last element.
    ///
    /// Example 1:
    /// Input: nums = [7,6,5,4,3,2,1,6,10,11]
    /// Output: 8
    /// Explanation: Take the subarray [7,6,5,4,3,2,1,6].
    /// The first element is 7 and the last one is 6 so the condition is met.
    /// Hence, the answer would be the length of the subarray or 8.
    /// It can be shown that there aren't any subarrays with the given 
    /// condition with a length greater than 8.
    ///
    /// Example 2:
    /// Input: nums = [57,55,50,60,61,58,63,59,64,60,63]
    /// Output: 6
    /// Explanation: Take the subarray [61,58,63,59,64,60].
    /// The first element is 61 and the last one is 60 so the condition is met.
    /// Hence, the answer would be the length of the subarray or 6.
    /// It can be shown that there aren't any subarrays with the given 
    /// condition with a length greater than 6.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3,4]
    /// Output: 0
    /// Explanation: Since there are no semi-decreasing subarrays in the given 
    /// array, the answer is 0.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// </summary>
    int maxSubarrayLength(vector<int>& nums);

    /// <summary>
    /// Leet Code 2895. Minimum Processing Time
    /// 
    /// Medium
    /// 
    /// You have n processors each having 4 cores and n * 4 tasks that need to 
    /// be executed such that each core should perform only one task.
    ///
    /// Given a 0-indexed integer array processorTime representing the time at 
    /// which each processor becomes available for the first time and a 
    /// 0-indexed integer array tasks representing the time it takes to 
    /// execute each task, return the minimum time when all of the tasks have 
    /// been executed by the processors.
    ///
    /// Note: Each core executes the task independently of the others.
    /// 
    /// Example 1:
    /// Input: processorTime = [8,10], tasks = [2,2,3,1,8,7,4,5]
    /// Output: 16
    /// Explanation: 
    /// It's optimal to assign the tasks at indexes 4, 5, 6, 7 to the first 
    /// processor which becomes available at time = 8, and the tasks at 
    /// indexes 0, 1, 2, 3 to the second processor which becomes available 
    /// at time = 10. 
    /// Time taken by the first processor to finish execution of all 
    /// tasks = max(8 + 8, 8 + 7, 8 + 4, 8 + 5) = 16.
    /// Time taken by the second processor to finish execution of all 
    /// tasks = max(10 + 2, 10 + 2, 10 + 3, 10 + 1) = 13.
    /// Hence, it can be shown that the minimum time taken to execute all the 
    /// tasks is 16.
    ///
    /// Example 2:
    /// Input: processorTime = [10,20], tasks = [2,3,1,2,5,8,4,3]
    /// Output: 23
    /// Explanation: 
    /// It's optimal to assign the tasks at indexes 1, 4, 5, 6 to the first 
    /// processor which becomes available at time = 10, and the tasks at 
    /// indexes 0, 2, 3, 7 to the second processor which becomes available 
    /// at time = 20.
    /// Time taken by the first processor to finish execution of all 
    /// tasks = max(10 + 3, 10 + 5, 10 + 8, 10 + 4) = 18.
    /// Time taken by the second processor to finish execution of all 
    /// tasks = max(20 + 2, 20 + 1, 20 + 2, 20 + 3) = 23.
    /// Hence, it can be shown that the minimum time taken to execute all 
    /// the tasks is 23.
    ///
    /// Constraints:
    /// 1. 1 <= n == processorTime.length <= 25000
    /// 2. 1 <= tasks.length <= 10^5
    /// 3. 0 <= processorTime[i] <= 10^9
    /// 3. 1 <= tasks[i] <= 10^9
    /// 4. tasks.length == 4 * n
    /// </summary>
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks);

    /// <summary>
    /// Leet Code 2907. Maximum Profitable Triplets With Increasing Prices I 
    /// 
    /// Medium
    ///
    /// Given the 0-indexed arrays prices and profits of length n. There are n 
    /// items in an store where the ith item has a price of prices[i] and a 
    /// profit of profits[i].
    ///
    /// We have to pick three items with the following condition:
    /// prices[i] < prices[j] < prices[k] where i < j < k.
    /// If we pick items with indices i, j and k satisfying the above 
    /// condition, the profit would be profits[i] + profits[j] + profits[k].
    ///
    /// Return the maximum profit we can get, and -1 if it's not possible 
    /// to pick three items with the given condition.
    ///
    /// Example 1:
    /// Input: prices = [10,2,3,4], profits = [100,2,7,10]
    /// Output: 19
    /// Explanation: We can't pick the item with index i=0 since there are no 
    /// indices j and k such that the condition holds.
    /// So the only triplet we can pick, are the items with indices 1, 2 and 3 
    /// and it's a valid pick since prices[1] < prices[2] < prices[3].
    /// The answer would be sum of their profits which is 2 + 7 + 10 = 19.
    ///
    /// Example 2:
    /// Input: prices = [1,2,3,4,5], profits = [1,5,3,4,6]
    /// Output: 15
    /// Explanation: We can select any triplet of items since for each triplet 
    /// of indices i, j and k such that i < j < k, the condition holds.
    /// Therefore the maximum profit we can get would be the 3 most profitable 
    /// items which are indices 1, 3 and 4.
    /// The answer would be sum of their profits which is 5 + 4 + 6 = 15.
    ///
    /// Example 3:
    /// Input: prices = [4,3,2,1], profits = [33,20,19,87]
    /// Output: -1
    /// Explanation: We can't select any triplet of indices such that the 
    /// condition holds, so we return -1.
    /// 
    /// Constraints:
    /// 1. 3 <= prices.length == profits.length <= 2000
    /// 2. 1 <= prices[i] <= 10^6
    /// 3. 1 <= profits[i] <= 10^6
    /// </summary>
    int maxProfit(vector<int>& prices, vector<int>& profits);

    /// <summary>
    /// Leet Code 2908. Minimum Sum of Mountain Triplets I 
    /// 
    /// Easy
    ///
    /// You are given a 0-indexed array nums of integers.
    ///
    /// A triplet of indices (i, j, k) is a mountain if:
    /// 
    /// i < j < k
    /// nums[i] < nums[j] and nums[k] < nums[j]
    /// Return the minimum possible sum of a mountain triplet of nums. If no 
    /// such triplet exists, return -1.
    ///
    /// Example 1:
    /// Input: nums = [8,6,1,5,3]
    /// Output: 9
    /// Explanation: Triplet (2, 3, 4) is a mountain triplet of sum 9 since: 
    /// - 2 < 3 < 4
    /// - nums[2] < nums[3] and nums[4] < nums[3]
    /// And the sum of this triplet is nums[2] + nums[3] + nums[4] = 9. It 
    /// can be shown that there are no mountain triplets with a sum of less 
    /// than 9.
    ///
    /// Example 2:
    /// Input: nums = [5,4,8,7,10,2]
    /// Output: 13
    /// Explanation: Triplet (1, 3, 5) is a mountain triplet of sum 13 since: 
    /// - 1 < 3 < 5
    /// - nums[1] < nums[3] and nums[5] < nums[3]
    /// And the sum of this triplet is nums[1] + nums[3] + nums[5] = 13. It 
    /// can be shown that there are no mountain triplets with a sum of less 
    /// than 13.
    ///
    /// Example 3:
    /// Input: nums = [6,5,4,3,4,5]
    /// Output: -1
    /// Explanation: It can be shown that there are no mountain triplets in 
    /// nums.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 50
    /// 2. 1 <= nums[i] <= 50
    /// </summary>
    int minimumSum(vector<int>& nums);

    /// <summary>
    /// Leet Code 2909. Minimum Sum of Mountain Triplets II
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed array nums of integers.
    ///
    /// A triplet of indices (i, j, k) is a mountain if:
    /// i < j < k
    /// nums[i] < nums[j] and nums[k] < nums[j]
    /// Return the minimum possible sum of a mountain triplet of nums. If no 
    /// such triplet exists, return -1.
    /// 
    /// Example 1:
    /// Input: nums = [8,6,1,5,3]
    /// Output: 9
    /// Explanation: Triplet (2, 3, 4) is a mountain triplet of sum 9 since: 
    /// - 2 < 3 < 4
    /// - nums[2] < nums[3] and nums[4] < nums[3]
    /// And the sum of this triplet is nums[2] + nums[3] + nums[4] = 9. It can 
    /// be shown that there are no mountain triplets with a sum of less than 9.
    ///
    /// Example 2:
    /// Input: nums = [5,4,8,7,10,2]
    /// Output: 13
    /// Explanation: Triplet (1, 3, 5) is a mountain triplet of sum 13 since: 
    /// - 1 < 3 < 5
    /// - nums[1] < nums[3] and nums[5] < nums[3]
    /// And the sum of this triplet is nums[1] + nums[3] + nums[5] = 13. It 
    /// can be shown that there are no mountain triplets with a sum of less 
    /// than 13.
    ///
    /// Example 3:
    /// Input: nums = [6,5,4,3,4,5]
    /// Output: -1
    /// Explanation: It can be shown that there are no mountain triplets in 
    /// nums.
    /// 
    /// Constraints:
    /// 1. 3 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^8
    /// </summary>
    int minimumSumII(vector<int>& nums);

    /// <summary>
    /// Leet Code 2921. Maximum Profitable Triplets With Increasing Prices II
    ///  
    /// Hard
    ///
    /// Given the 0-indexed arrays prices and profits of length n. There are n 
    /// items in an store where the ith item has a price of prices[i] and a 
    /// profit of profits[i].
    ///
    /// We have to pick three items with the following condition:
    ///
    /// prices[i] < prices[j] < prices[k] where i < j < k.
    /// If we pick items with indices i, j and k satisfying the above 
    /// condition, the profit would be profits[i] + profits[j] + profits[k].
    ///
    /// Return the maximum profit we can get, and -1 if it's not possible to 
    /// pick three items with the given condition.
    /// 
    /// Example 1:
    ///
    /// Input: prices = [10,2,3,4], profits = [100,2,7,10]
    /// Output: 19
    /// Explanation: We can't pick the item with index i=0 since there are no 
    /// indices j and k such that the condition holds.
    /// So the only triplet we can pick, are the items with indices 1, 2 and 3 
    /// and it's a valid pick since prices[1] < prices[2] < prices[3].
    /// The answer would be sum of their profits which is 2 + 7 + 10 = 19.
    ///
    /// Example 2:
    ///
    /// Input: prices = [1,2,3,4,5], profits = [1,5,3,4,6]
    /// Output: 15
    /// Explanation: We can select any triplet of items since for each triplet 
    /// of indices i, j and k such that i < j < k, the condition holds.
    /// Therefore the maximum profit we can get would be the 3 most profitable 
    /// items which are indices 1, 3 and 4.
    /// The answer would be sum of their profits which is 5 + 4 + 6 = 15.
    ///
    /// Example 3:
    /// Input: prices = [4,3,2,1], profits = [33,20,19,87]
    /// Output: -1
    /// Explanation: We can't select any triplet of indices such that the 
    /// condition holds, so we return -1.
    ///
    ///
    /// Constraints:
    /// 1. 3 <= prices.length == profits.length <= 50000
    /// 2. 1 <= prices[i] <= 5000
    /// 3. 1 <= profits[i] <= 10^6
    /// </summary>
    int maxProfitII(vector<int>& prices, vector<int>& profits);

    /// <summary>
    /// Leet Code 2926. Maximum Balanced Subsequence Sum
    ///  
    /// Hard
    ///
    /// You are given a 0-indexed integer array nums.
    ///
    /// A subsequence of nums having length k and consisting of indices 
    /// i0 < i1 < ... < ik-1 is balanced if the following holds:
    ///
    /// nums[ij] - nums[ij-1] >= ij - ij-1, for every j in the range 
    /// [1, k - 1].
    /// A subsequence of nums having length 1 is considered balanced.
    ///
    /// Return an integer denoting the maximum possible sum of elements in a 
    /// balanced subsequence of nums.
    ///
    /// A subsequence of an array is a new non-empty array that is formed 
    /// from the original array by deleting some (possibly none) of the 
    /// elements without disturbing the relative positions of the remaining 
    /// elements.
    /// 
    /// Example 1:
    /// Input: nums = [3,3,5,6]
    /// Output: 14
    /// Explanation: In this example, the subsequence [3,5,6] consisting of 
    /// indices 0, 2, and 3 can be selected.
    /// nums[2] - nums[0] >= 2 - 0.
    /// nums[3] - nums[2] >= 3 - 2.
    /// Hence, it is a balanced subsequence, and its sum is the maximum among 
    /// the balanced subsequences of nums.
    /// The subsequence consisting of indices 1, 2, and 3 is also valid.
    /// It can be shown that it is not possible to get a balanced subsequence 
    /// with a sum greater than 14.
    ///
    /// Example 2:
    /// Input: nums = [5,-1,-3,8]
    /// Output: 13
    /// Explanation: In this example, the subsequence [5,8] consisting of 
    /// indices 0 and 3 can be selected.
    /// nums[3] - nums[0] >= 3 - 0.
    /// Hence, it is a balanced subsequence, and its sum is the maximum among 
    /// the balanced subsequences of nums.
    /// It can be shown that it is not possible to get a balanced subsequence 
    /// with a sum greater than 13.
    ///
    /// Example 3:
    /// Input: nums = [-2,-1]
    /// Output: -1
    /// Explanation: In this example, the subsequence [-1] can be selected.
    /// It is a balanced subsequence, and its sum is the maximum among the 
    /// balanced subsequences of nums.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// </summary>
    long long maxBalancedSubsequenceSum(vector<int>& nums);

    /// <summary>
    /// Leet Code 2931. Maximum Spending After Buying Items
    ///  
    /// Hard
    ///
    /// You are given a 0-indexed m * n integer matrix values, representing 
    /// the values of m * n different items in m different shops. Each shop 
    /// has n items where the jth item in the ith shop has a value of 
    /// values[i][j]. Additionally, the items in the ith shop are sorted 
    /// in non-increasing order of value. That is, 
    /// values[i][j] >= values[i][j + 1] for all 0 <= j < n - 1.
    ///
    /// On each day, you would like to buy a single item from one of the 
    /// shops. Specifically, On the dth day you can:
    ///
    /// Pick any shop i.
    /// Buy the rightmost available item j for the price of values[i][j] * d. 
    /// That is, find the greatest index j such that item j was never bought 
    /// before, and buy it for the price of values[i][j] * d.
    /// Note that all items are pairwise different. For example, if you have 
    /// bought item 0 from shop 1, you can still buy item 0 from any other 
    /// shop.
    ///
    /// Return the maximum amount of money that can be spent on buying all 
    /// m * n products.
    ///
    /// Example 1:
    /// Input: values = [[8,5,2],[6,4,1],[9,7,3]]
    /// Output: 285
    /// Explanation: On the first day, we buy product 2 from shop 1 for a 
    /// price of values[1][2] * 1 = 1.
    /// On the second day, we buy product 2 from shop 0 for a price of 
    /// values[0][2] * 2 = 4.
    /// On the third day, we buy product 2 from shop 2 for a price of 
    /// values[2][2] * 3 = 9.
    /// On the fourth day, we buy product 1 from shop 1 for a price of 
    /// values[1][1] * 4 = 16.
    /// On the fifth day, we buy product 1 from shop 0 for a price of 
    /// values[0][1] * 5 = 25.
    /// On the sixth day, we buy product 0 from shop 1 for a price of 
    /// values[1][0] * 6 = 36.
    /// On the seventh day, we buy product 1 from shop 2 for a price of 
    /// values[2][1] * 7 = 49.
    /// On the eighth day, we buy product 0 from shop 0 for a price of 
    /// values[0][0] * 8 = 64.
    /// On the ninth day, we buy product 0 from shop 2 for a price of 
    /// values[2][0] * 9 = 81.
    /// Hence, our total spending is equal to 285.
    /// It can be shown that 285 is the maximum amount of money that 
    /// can be spent buying all m * n products. 
    ///
    /// Example 2:
    /// Input: values = [[10,8,6,4,2],[9,7,5,3,2]]
    /// Output: 386
    /// Explanation: On the first day, we buy product 4 from shop 0 for a 
    /// price of values[0][4] * 1 = 2.
    /// On the second day, we buy product 4 from shop 1 for a price of 
    /// values[1][4] * 2 = 4.
    /// On the third day, we buy product 3 from shop 1 for a price of 
    /// values[1][3] * 3 = 9.
    /// On the fourth day, we buy product 3 from shop 0 for a price of 
    /// values[0][3] * 4 = 16.
    /// On the fifth day, we buy product 2 from shop 1 for a price of 
    /// values[1][2] * 5 = 25.
    /// On the sixth day, we buy product 2 from shop 0 for a price of 
    /// values[0][2] * 6 = 36.
    /// On the seventh day, we buy product 1 from shop 1 for a price of 
    /// values[1][1] * 7 = 49.
    /// On the eighth day, we buy product 1 from shop 0 for a price of 
    /// values[0][1] * 8 = 64
    /// On the ninth day, we buy product 0 from shop 1 for a price of 
    /// values[1][0] * 9 = 81.
    /// On the tenth day, we buy product 0 from shop 0 for a price of 
    /// values[0][0] * 10 = 100.
    /// Hence, our total spending is equal to 386.
    /// It can be shown that 386 is the maximum amount of money that can be 
    /// spent buying all m * n products.
    /// 
    /// Constraints:
    /// 1. 1 <= m == values.length <= 10
    /// 2. 1 <= n == values[i].length <= 10^4
    /// 3. 1 <= values[i][j] <= 10^6
    /// 4. values[i] are sorted in non-increasing order.
    /// </summary>
    long long maxSpending(vector<vector<int>>& values);

    /// <summary>
    /// Leet Code 2940. Find Building Where Alice and Bob Can Meet
    ///  
    /// Hard
    ///
    /// You are given a 0-indexed array heights of positive integers, where 
    /// heights[i] represents the height of the ith building.
    ///  
    /// If a person is in building i, they can move to any other building j if 
    /// and only if i < j and heights[i] < heights[j].
    /// 
    /// You are also given another array queries where queries[i] = [ai, bi]. 
    /// On the ith query, Alice is in building ai while Bob is in building bi.
    ///
    /// Return an array ans where ans[i] is the index of the leftmost building 
    /// where Alice and Bob can meet on the ith query. If Alice and Bob cannot 
    /// move to a common building on query i, set ans[i] to -1.
    /// 
    /// Example 1:
    /// Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
    /// Output: [2,5,-1,5,2]
    /// Explanation: In the first query, Alice and Bob can move to building 2 
    /// since heights[0] < heights[2] and heights[1] < heights[2]. 
    /// In the second query, Alice and Bob can move to building 5 since 
    /// heights[0] < heights[5] and heights[3] < heights[5]. 
    /// In the third query, Alice cannot meet Bob since Alice cannot move to any 
    /// other building.
    /// In the fourth query, Alice and Bob can move to building 5 since 
    /// heights[3] < heights[5] and heights[4] < heights[5].
    /// In the fifth query, Alice and Bob are already in the same building.  
    /// For ans[i] != -1, It can be shown that ans[i] is the leftmost building 
    /// where Alice and Bob can meet.
    /// For ans[i] == -1, It can be shown that there is no building where Alice 
    /// and Bob can meet.
    ///
    /// Example 2:
    /// Input: heights = [5,3,8,2,6,1,4,6], 
    /// queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
    /// Output: [7,6,-1,4,6]
    /// Explanation: In the first query, Alice can directly move to Bob's building 
    /// since heights[0] < heights[7].
    /// In the second query, Alice and Bob can move to building 6 since 
    /// heights[3] < heights[6] and heights[5] < heights[6].
    /// In the third query, Alice cannot meet Bob since Bob cannot move to any 
    /// other building.
    /// In the fourth query, Alice and Bob can move to building 4 since 
    /// heights[3] < heights[4] and heights[0] < heights[4].
    /// In the fifth query, Alice can directly move to Bob's building since 
    /// heights[1] < heights[6].
    /// For ans[i] != -1, It can be shown that ans[i] is the leftmost building 
    /// where Alice and Bob can meet.
    /// For ans[i] == -1, It can be shown that there is no building where Alice 
    /// and Bob can meet.
    /// 
    /// Constraints:
    /// 1. 1 <= heights.length <= 5 * 10^4
    /// 2. 1 <= heights[i] <= 10^9
    /// 3. 1 <= queries.length <= 5 * 10^4
    /// 4. queries[i] = [ai, bi]
    /// 5. 0 <= ai, bi <= heights.length - 1
    /// </summary>
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2948. Make Lexicographically Smallest Array by Swapping Elements
    ///  
    /// Medium
    ///
    /// You are given a 0-indexed array of positive integers nums and a positive 
    /// integer limit.
    ///
    /// In one operation, you can choose any two indices i and j and swap nums[i] 
    /// and nums[j] if |nums[i] - nums[j]| <= limit.
    ///
    /// Return the lexicographically smallest array that can be obtained by 
    /// performing the operation any number of times.
    ///
    /// An array a is lexicographically smaller than an array b if in the first 
    /// position where a and b differ, array a has an element that is less than 
    /// the corresponding element in b. For example, the array [2,10,3] is 
    /// lexicographically smaller than the array [10,2,3] because they differ 
    /// at index 0 and 2 < 10.
    ///
    /// Example 1:
    /// Input: nums = [1,5,3,9,8], limit = 2
    /// Output: [1,3,5,8,9]
    /// Explanation: Apply the operation 2 times:
    /// - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
    /// - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
    /// We cannot obtain a lexicographically smaller array by applying any more 
    /// operations.
    /// Note that it may be possible to get the same result by doing different 
    /// operations.
    ///
    /// Example 2:
    /// Input: nums = [1,7,6,18,2,1], limit = 3
    /// Output: [1,6,7,18,1,2]
    /// Explanation: Apply the operation 3 times:
    /// - Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
    /// - Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
    /// - Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
    /// We cannot obtain a lexicographically smaller array by applying any more 
    /// operations.
    ///
    /// Example 3:
    /// Input: nums = [1,7,28,19,10], limit = 3
    /// Output: [1,7,28,19,10]
    /// Explanation: [1,7,28,19,10] is the lexicographically smallest array we 
    /// can obtain because we cannot apply the operation on any two indices.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= limit <= 10^9
    /// </summary>
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit);

    /// <summary>
    /// Leet Code 3011. Find if Array Can Be Sorted
    ///                 
    /// Medium
    ///
    /// You are given a 0-indexed array of positive integers nums.
    ///
    /// In one operation, you can swap any two adjacent elements if they have 
    /// the same number of set bits
    /// You are allowed to do this operation any number of times (including zero).
    /// 
    /// Return true if you can sort the array, else return false.
    /// 
    /// Example 1:
    /// 
    /// Input: nums = [8,4,2,30,15]
    /// Output: true
    /// Explanation: Let's look at the binary representation of every element. 
    /// The numbers 2, 4, and 8 have one set bit each with binary representation 
    /// "10", "100", and "1000" respectively. The numbers 15 and 30 have four set 
    /// bits each with binary representation "1111" and "11110".
    /// We can sort the array using 4 operations:
    /// - Swap nums[0] with nums[1]. This operation is valid because 8 and 4 have 
    ///   one set bit each. The array becomes [4,8,2,30,15].
    /// - Swap nums[1] with nums[2]. This operation is valid because 8 and 2 have 
    ///   one set bit each. The array becomes [4,2,8,30,15].
    /// - Swap nums[0] with nums[1]. This operation is valid because 4 and 2 have 
    ///   one set bit each. The array becomes [2,4,8,30,15].
    /// - Swap nums[3] with nums[4]. This operation is valid because 30 and 15 
    ///   have four set bits each. The array becomes [2,4,8,15,30].
    /// The array has become sorted, hence we return true.
    /// Note that there may be other sequences of operations which also sort the 
    /// array.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,5]
    /// Output: true
    /// Explanation: The array is already sorted, hence we return true.
    ///
    /// Example 3:
    /// Input: nums = [3,16,8,4,2]
    /// Output: false
    /// Explanation: It can be shown that it is not possible to sort the input 
    /// array using any number of operations.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 2^8
    /// </summary>
    bool canSortArray(vector<int>& nums);

    /// <summary>
    /// Leet Code 3013. Divide an Array Into Subarrays With Minimum Cost II
    ///                 
    /// Hard
    ///
    /// You are given a 0-indexed array of integers nums of length n, and two 
    /// positive integers k and dist.
    ///
    /// The cost of an array is the value of its first element. For example, 
    /// the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
    ///
    /// You need to divide nums into k disjoint contiguous subarrays, such that 
    /// the difference between the starting index of the second subarray and 
    /// the starting index of the kth subarray should be less than or equal to 
    /// dist. In other words, if you divide nums into the subarrays 
    /// nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], 
    /// then ik-1 - i1 <= dist.
    ///
    /// Return the minimum possible sum of the cost of these subarrays.
    /// 
    /// Example 1:
    /// Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
    /// Output: 5
    /// Explanation: The best possible way to divide nums into 3 subarrays is: 
    /// [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 
    /// is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + 
    /// nums[2] + nums[5] which is 1 + 2 + 2 = 5.
    /// It can be shown that there is no possible way to divide nums into 3 
    /// subarrays at a cost lower than 5.
    ///
    /// Example 2:
    /// Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
    /// Output: 15
    /// Explanation: The best possible way to divide nums into 4 subarrays 
    /// is: [10], [1], [2], and [2,2,1]. This choice is valid because ik-1 - i1 
    /// is 3 - 1 = 2 which is less than dist. The total cost is nums[0] + 
    /// nums[1] + nums[2] + nums[3] which is 10 + 1 + 2 + 2 = 15.
    /// The division [10], [1], [2,2,2], and [1] is not valid, because the 
    /// difference between ik-1 and i1 is 5 - 1 = 4, which is greater than dist.
    /// It can be shown that there is no possible way to divide nums into 4 
    /// subarrays at a cost lower than 15.
    ///
    /// Example 3:
    /// Input: nums = [10,8,18,9], k = 3, dist = 1
    /// Output: 36
    /// Explanation: The best possible way to divide nums into 4 subarrays is: 
    /// [10], [8], and [18,9]. This choice is valid because ik-1 - i1 is 2 - 1 = 1 
    /// which is equal to dist.The total cost is nums[0] + nums[1] + nums[2] which 
    /// is 10 + 8 + 18 = 36.
    /// The division [10], [8,18], and [9] is not valid, because the difference 
    /// between ik-1 and i1 is 3 - 1 = 2, which is greater than dist.
    /// It can be shown that there is no possible way to divide nums into 3 
    /// subarrays at a cost lower than 36.
    /// 
    /// Constraints:
    /// 1. 3 <= n <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 3 <= k <= n
    /// 4. k - 2 <= dist <= n - 2
    /// </summary>
    long long minimumCost(vector<int>& nums, int k, int dist);

    /// <summary>
    /// Leet Code 3025. Find the Number of Ways to Place People I
    ///
    /// Medium
    ///
    /// You are given a 2D array points of size n x 2 representing integer 
    /// coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
    /// We define the right direction as positive x-axis (increasing 
    /// x-coordinate) and the left direction as negative x-axis (decreasing 
    /// x-coordinate). Similarly, we define the up direction as positive 
    /// y-axis (increasing y-coordinate) and the down direction as negative 
    /// y-axis (decreasing y-coordinate)
    ///
    /// You have to place n people, including Chisato and Takina, at these 
    /// points such that there is exactly one person at every point. Chisato 
    /// wants to be alone with Takina, so Chisato will build a rectangular 
    /// fence with Chisato's position as the upper left corner and Takina's 
    /// position as the lower right corner of the fence (Note that the 
    /// fence might not enclose any area, i.e. it can be a line). If any 
    /// person other than Chisato and Takina is either inside the fence 
    /// or on the fence, Chisato will be sad.
    ///
    /// Return the number of pairs of points where you can place Chisato and 
    /// Takina, such that Chisato does not become sad on building the fence.
    ///
    /// Note that Chisato can only build a fence with Chisato's position as the 
    /// upper left corner, and Takina's position as the lower right corner. For 
    /// example, Chisato cannot build either of the fences in the picture below 
    /// with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:
    /// With Chisato at (3, 3) and Takina at (1, 1), Chisato's position is not 
    /// the upper left corner and Takina's position is not the lower right 
    /// corner of the fence.
    /// With Chisato at (1, 3) and Takina at (1, 1), Takina's position is not 
    /// the lower right corner of the fence.
    ///
    /// Example 1:
    /// 
    /// Input: points = [[1,1],[2,2],[3,3]]
    /// Output: 0
    /// Explanation: There is no way to place Chisato and Takina such that 
    /// Chisato can build a fence with Chisato's position as the upper left 
    /// corner and Takina's position as the lower right corner. Hence we 
    /// return 0. 
    ///
    /// Example 2:
    /// Input: points = [[6,2],[4,4],[2,6]]
    /// Output: 2
    /// Explanation: There are two ways to place Chisato and Takina such 
    /// that Chisato will not be sad:
    /// - Place Chisato at (4, 4) and Takina at (6, 2).
    /// - Place Chisato at (2, 6) and Takina at (4, 4).
    /// You cannot place Chisato at (2, 6) and Takina at (6, 2) because 
    /// the person at (4, 4) will be inside the fence.
    ///
    /// Example 3:
    /// Input: points = [[3,1],[1,3],[1,1]]
    /// Output: 2
    /// Explanation: There are two ways to place Chisato and Takina such that 
    /// Chisato will not be sad:
    /// - Place Chisato at (1, 1) and Takina at (3, 1).
    /// - Place Chisato at (1, 3) and Takina at (1, 1).
    /// You cannot place Chisato at (1, 3) and Takina at (3, 1) because the 
    /// person at (1, 1) will be on the fence.
    /// Note that it does not matter if the fence encloses any area, the first 
    /// and second fences in the image are valid.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 50
    /// 2. points[i].length == 2
    /// 3. 0 <= points[i][0], points[i][1] <= 50
    /// 4. All points[i] are distinct.
    /// </summary>
    int numberOfPairsI(vector<vector<int>>& points);

    /// <summary>
    /// Leet Code 3027. Find the Number of Ways to Place People II
    ///
    /// Hard
    ///
    /// You are given a 2D array points of size n x 2 representing integer 
    /// coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
    ///
    /// We define the right direction as positive x-axis (increasing 
    /// x-coordinate) and the left direction as negative x-axis (decreasing x-
    /// coordinate). Similarly, we define the up direction as positive y-axis 
    /// (increasing y-coordinate) and the down direction as negative y-axis 
    /// (decreasing y-coordinate)
    ///
    /// You have to place n people, including Alice and Bob, at these points 
    /// such that there is exactly one person at every point. Alice wants to 
    /// be alone with Bob, so Alice will build a rectangular fence with 
    /// Alice's position as the upper left corner and Bob's position as the 
    /// lower right corner of the fence (Note that the fence might not 
    /// enclose any area, i.e. it can be a line). If any person other than 
    /// Alice and Bob is either inside the fence or on the fence, Alice will 
    /// be sad.
    ///
    /// Return the number of pairs of points where you can place Alice and 
    /// Bob, such that Alice does not become sad on building the fence.
    ///
    /// Note that Alice can only build a fence with Alice's position as the 
    /// upper left corner, and Bob's position as the lower right corner. 
    /// For example, Alice cannot build either of the fences in the picture 
    /// below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:
    /// 
    /// With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the 
    /// upper left corner and Bob's position is not the lower right corner 
    /// of the fence.
    /// With Alice at (1, 3) and Bob at (1, 1), Bob's position is not the 
    /// lower right corner of the fence.
    /// 
    /// Example 1:
    /// Input: points = [[1,1],[2,2],[3,3]]
    /// Output: 0
    /// Explanation: There is no way to place Alice and Bob such that Alice 
    /// can build a fence with Alice's position as the upper left corner 
    /// and Bob's position as the lower right corner. Hence we return 0. 
    ///
    /// Example 2:
    /// Input: points = [[6,2],[4,4],[2,6]]
    /// Output: 2
    /// Explanation: There are two ways to place Alice and Bob such that 
    /// Alice will not be sad:
    /// - Place Alice at (4, 4) and Bob at (6, 2).
    /// - Place Alice at (2, 6) and Bob at (4, 4).
    /// You cannot place Alice at (2, 6) and Bob at (6, 2) because the 
    /// person at (4, 4) will be inside the fence.
    ///
    /// Example 3:
    /// Input: points = [[3,1],[1,3],[1,1]]
    /// Output: 2
    /// Explanation: There are two ways to place Alice and Bob such that 
    /// Alice will not be sad:
    /// - Place Alice at (1, 1) and Bob at (3, 1).
    /// - Place Alice at (1, 3) and Bob at (1, 1).
    /// You cannot place Alice at (1, 3) and Bob at (3, 1) because the 
    /// person at (1, 1) will be on the fence.
    /// Note that it does not matter if the fence encloses any area, the first 
    /// and second fences in the image are valid.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 1000
    /// 2. points[i].length == 2
    /// 3. -10^9 <= points[i][0], points[i][1] <= 10^9
    /// 4. All points[i] are distinct.
    /// </summary>
    int numberOfPairsII(vector<vector<int>>& points);


    /// <summary>
    /// Leet Code 3066. Minimum Operations to Exceed Threshold Value II
    ///
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums, and an integer k.
    ///
    /// In one operation, you will:
    /// Take the two smallest integers x and y in nums.
    /// Remove x and y from nums.
    /// Add min(x, y) * 2 + max(x, y) anywhere in the array.
    /// Note that you can only apply the described operation if nums 
    /// contains at least two elements.
    ///
    /// Return the minimum number of operations needed so that all elements 
    /// of the array are greater than or equal to k.
    ///
    /// Example 1:
    /// Input: nums = [2,11,10,1,3], k = 10
    /// Output: 2
    /// Explanation: In the first operation, we remove elements 1 and 2, 
    /// then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
    /// In the second operation, we remove elements 3 and 4, then add 
    /// 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
    /// At this stage, all the elements of nums are greater than or equal 
    /// to 10 so we can stop.
    /// It can be shown that 2 is the minimum number of operations needed so 
    /// that all elements of the array are greater than or equal to 10.
    ///
    /// Example 2:
    /// Input: nums = [1,1,2,4,9], k = 20
    /// Output: 4
    /// Explanation: After one operation, nums becomes equal to [2, 4, 9, 3].
    /// After two operations, nums becomes equal to [7, 4, 9].
    /// After three operations, nums becomes equal to [15, 9].
    /// After four operations, nums becomes equal to [33].
    /// At this stage, all the elements of nums are greater than 20 so we can 
    /// stop.
    /// It can be shown that 4 is the minimum number of operations needed so 
    /// that all elements of the array are greater than or equal to 20.
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 2 * 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= 10^9
    /// 4. The input is generated such that an answer always exists. That is, 
    ///    there exists some sequence of operations after which all elements
    ///    of the array are greater than or equal to k.
    /// </summary>
    int minOperationsII(vector<int>& nums, int k);


    /// <summary>
    /// Leet 3073. Maximum Increasing Triplet Value
    ///
    /// Medium
    ///
    /// Given an array nums, return the maximum value of a triplet (i, j, k) 
    /// such that i < j < k and nums[i] < nums[j] < nums[k].
    ///
    /// The value of a triplet (i, j, k) is nums[i] - nums[j] + nums[k].
    /// 
    /// Example 1:
    /// Input: nums = [5,6,9] 
    /// Output: 8 
    /// Explanation: We only have one choice for an increasing triplet and 
    /// that is choosing all three elements. The value of this triplet would 
    /// be 5 - 6 + 9 = 8.
    ///
    /// Example 2:
    /// Input:  nums = [1,5,3,6] 
    /// Output:  4 
    /// Explanation: There are only two increasing triplets:
    /// (0, 1, 3): The value of this triplet is nums[0] - nums[1] + nums[3] = 
    /// 1 - 5 + 6 = 2.
    /// (0, 2, 3): The value of this triplet is nums[0] - nums[2] + nums[3] = 
    /// 1 - 3 + 6 = 4.
    /// Thus the answer would be 4.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 10^5 
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. The input is generated such that at least one triplet meets the 
    ///    given condition.
    /// </summary>
    int maximumTripletValue(vector<int>& nums);

    /// <summary>
    /// Leet 3074. Apple Redistribution into Boxes
    ///
    /// Easy
    ///
    /// You are given an array apple of size n and an array capacity of size m.
    /// There are n packs where the ith pack contains apple[i] apples. There 
    /// are m boxes as well, and the ith box has a capacity of capacity[i] 
    /// apples.
    ///
    /// Return the minimum number of boxes you need to select to redistribute
    /// these n packs of apples into boxes.
    ///
    /// Note that, apples from the same pack can be distributed into different 
    /// boxes.
    ///
    /// Example 1:
    /// Input: apple = [1,3,2], capacity = [4,3,1,5,2]
    /// Output: 2
    /// Explanation: We will use boxes with capacities 4 and 5.
    /// It is possible to distribute the apples as the total capacity is 
    /// greater than or equal to the total number of apples.
    ///
    /// Example 2:
    /// Input: apple = [5,5,5], capacity = [2,4,2,7]
    /// Output: 4
    /// Explanation: We will need to use all the boxes.
    ///
    /// Constraints:
    /// 1. 1 <= n == apple.length <= 50
    /// 2. 1 <= m == capacity.length <= 50
    /// 3. 1 <= apple[i], capacity[i] <= 50
    /// 4. The input is generated such that it's possible to redistribute 
    ///    packs of apples into boxes.
    /// </summary>
    int minimumBoxes(vector<int>& apple, vector<int>& capacity);


    /// <summary>
    /// Leet 3075. Maximize Happiness of Selected Children
    ///
    /// Medium
    ///
    /// You are given an array happiness of length n, and a positive integer k.
    ///
    /// There are n children standing in a queue, where the ith child has 
    /// happiness value happiness[i]. You want to select k children from these 
    /// n children in k turns.
    ///
    /// In each turn, when you select a child, the happiness value of all the 
    /// children that have not been selected till now decreases by 1. Note that 
    /// the happiness value cannot become negative and gets decremented only if 
    /// it is positive.
    ///
    /// Return the maximum sum of the happiness values of the selected 
    /// children you can achieve by selecting k children.
    ///
    /// Example 1:
    /// Input: happiness = [1,2,3], k = 2
    /// Output: 4
    /// Explanation: We can pick 2 children in the following way:
    /// - Pick the child with the happiness value == 3. The happiness value 
    ///   of the remaining children becomes [0,1].
    /// - Pick the child with the happiness value == 1. The happiness value 
    ///   of the remaining child becomes [0]. Note that the happiness value 
    ///   cannot become less than 0.
    /// The sum of the happiness values of the selected children is 3 + 1 = 4.
    ///
    /// Example 2:
    /// Input: happiness = [1,1,1,1], k = 2
    /// Output: 1
    /// Explanation: We can pick 2 children in the following way:
    /// - Pick any child with the happiness value == 1. The happiness value 
    ///   of the remaining children becomes [0,0,0].
    /// - Pick the child with the happiness value == 0. The happiness value 
    ///   of the remaining child becomes [0,0].
    /// The sum of the happiness values of the selected children is 1 + 0 = 1.
    ///
    /// Example 3:
    /// Input: happiness = [2,3,4,5], k = 1
    ///
    /// Output: 5
    /// Explanation: We can pick 1 child in the following way:
    /// - Pick the child with the happiness value == 5. The happiness value 
    ///   of the remaining children becomes [1,2,3].
    /// The sum of the happiness values of the selected children is 5.
    ///
    /// Constraints:
    /// 1. 1 <= n == happiness.length <= 2 * 10^5
    /// 2. 1 <= happiness[i] <= 10^8
    /// 3. 1 <= k <= n
    /// </summary>
    long long maximumHappinessSum(vector<int>& happiness, int k);


    /// <summary>
    /// Leet 3080. Mark Elements on Array by Performing Queries
    ///
    /// Medium
    ///
    /// You are given a 0-indexed array nums of size n consisting of positive 
    /// integers.
    ///
    /// You are also given a 2D array queries of size m where 
    /// queries[i] = [indexi, ki].
    ///
    /// Initially all elements of the array are unmarked.
    /// You need to apply m queries on the array in order, where on the ith 
    /// query you do the following:
    ///
    /// Mark the element at index indexi if it is not already marked.
    /// Then mark ki unmarked elements in the array with the smallest values. 
    /// If multiple such elements exist, mark the ones with the smallest 
    /// indices. And if less than ki unmarked elements exist, then mark all 
    /// of them.
    /// Return an array answer of size m where answer[i] is the sum of 
    /// unmarked elements in the array after the ith query.
    ///
    /// Example 1:
    /// Input: nums = [1,2,2,1,2,3,1], queries = [[1,2],[3,3],[4,2]]
    /// Output: [8,3,0]
    ///
    /// Explanation:
    /// We do the following queries on the array:
    /// Mark the element at index 1, and 2 of the smallest unmarked elements 
    /// with the smallest indices if they exist, the marked elements now are 
    /// nums = [1,2,2,1,2,3,1]. The sum of unmarked elements 
    /// is 2 + 2 + 3 + 1 = 8.
    /// Mark the element at index 3, since it is already marked we skip it. 
    /// Then we mark 3 of the smallest unmarked elements with the smallest 
    /// indices, the marked elements now are nums = [1,2,2,1,2,3,1]. The sum 
    /// of unmarked elements is 3.
    /// Mark the element at index 4, since it is already marked we skip it. 
    /// Then we mark 2 of the smallest unmarked elements with the smallest 
    /// indices if they exist, the marked elements now are 
    /// nums = [1,2,2,1,2,3,1]. The sum of unmarked elements is 0.
    ///
    /// Example 2:
    /// Input: nums = [1,4,2,3], queries = [[0,1]]
    /// Output: [7]
    /// Explanation: We do one query which is mark the element at index 0 
    /// and mark the smallest element among unmarked elements. The marked 
    /// elements will be nums = [1,4,2,3], and the sum of unmarked elements 
    /// is 4 + 3 = 7.
    ///
    /// Constraints:
    /// 1. n == nums.length
    /// 2. m == queries.length
    /// 3. 1 <= m <= n <= 10^5
    /// 4. 1 <= nums[i] <= 10^5
    /// 5. queries[i].length == 2
    /// 6. 0 <= indexi, ki <= n - 1
    /// </summary>
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 3224. Minimum Array Changes to Make Differences Equal
    ///
    /// Medium
    ///
    /// You are given an integer array nums of size n where n is even, and an 
    /// integer k.
    ///
    /// You can perform some changes on the array, where in one change you can 
    /// replace any element in the array with any integer in the range from 0 
    /// to k.
    ///
    /// You need to perform some changes (possibly none) such that the final 
    /// array satisfies the following condition:
    ///
    /// There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for 
    /// all (0 <= i < n).
    /// Return the minimum number of changes required to satisfy the above 
    /// condition.
    /// 
    /// Example 1:
    /// Input: nums = [1,0,1,2,4,3], k = 4
    /// Output: 2
    /// Explanation:
    /// We can perform the following changes:
    /// 
    /// Replace nums[1] by 2. The resulting array is nums = [1,2,1,2,4,3].
    /// Replace nums[3] by 3. The resulting array is nums = [1,2,1,3,4,3].
    /// The integer X will be 2.
    ///
    /// Example 2:
    /// Input: nums = [0,1,2,3,3,6,5,4], k = 6
    /// Output: 2
    /// Explanation:
    /// We can perform the following operations:
    /// Replace nums[3] by 0. The resulting array is nums = [0,1,2,0,3,6,5,4].
    /// Replace nums[4] by 4. The resulting array is nums = [0,1,2,0,4,6,5,4].
    /// The integer X will be 4.
    /// 
    /// Constraints:
    /// 1. 2 <= n == nums.length <= 10^5
    /// 2. n is even.
    /// 3. 0 <= nums[i] <= k <= 10^5
    /// </summary>
    int minChanges(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3231. Minimum Number of Increasing Subsequence to Be Removed
    ///
    /// Hard
    ///
    /// Given an array of integers nums, you are allowed to perform the 
    /// following operation any number of times:
    ///
    /// Remove a strictly increasing subsequence from the array.
    /// Your task is to find the minimum number of operations required to make 
    /// the array empty.
    ///
    /// Example 1:
    /// Input: nums = [5,3,1,4,2]
    /// Output: 3
    /// Explanation:
    /// We remove subsequences [1, 2], [3, 4], [5].
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,5]
    /// Output: 1
    ///
    /// Example 3:
    /// Input: nums = [5,4,3,2,1]
    /// Output: 5
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int minOperations(vector<int>& nums);

    /// <summary>
    /// Leet Code 3275. K-th Nearest Obstacle Queries
    /// 
    /// Medium
    ///
    /// There is an infinite 2D plane.
    ///
    /// You are given a positive integer k. You are also given a 2D array 
    /// queries, which contains the following queries:
    ///
    /// queries[i] = [x, y]: Build an obstacle at coordinate (x, y) in the 
    /// plane. It is guaranteed that there is no obstacle at this coordinate 
    /// when this query is made.
    /// After each query, you need to find the distance of the kth nearest 
    /// obstacle from the origin.
    ///
    /// Return an integer array results where results[i] denotes the kth 
    /// nearest obstacle after query i, or results[i] == -1 if there are 
    /// less than k obstacles.
    ///
    /// Note that initially there are no obstacles anywhere.
    /// The distance of an obstacle at coordinate (x, y) from the origin is 
    /// given by |x| + |y|.
    ///
    /// Example 1:
    /// Input: queries = [[1,2],[3,4],[2,3],[-3,0]], k = 2
    /// Output: [-1,7,5,3]
    /// Explanation:
    /// Initially, there are 0 obstacles.
    /// After queries[0], there are less than 2 obstacles.
    /// After queries[1], there are obstacles at distances 3 and 7.
    /// After queries[2], there are obstacles at distances 3, 5, and 7.
    /// After queries[3], there are obstacles at distances 3, 3, 5, and 7.
    ///
    /// Example 2:
    /// Input: queries = [[5,5],[4,4],[3,3]], k = 1
    /// Output: [10,8,6]
    /// Explanation:
    /// After queries[0], there is an obstacle at distance 10.
    /// After queries[1], there are obstacles at distances 8 and 10.
    /// After queries[2], there are obstacles at distances 6, 8, and 10.
    ///
    /// Constraints:
    /// 1. 1 <= queries.length <= 2 * 105
    /// 2. All queries[i] are unique.
    /// 3. -10^9 <= queries[i][0], queries[i][1] <= 10^9
    /// 4. 1 <= k <= 10^5
    /// </summary>
    vector<int> resultsArray(vector<vector<int>>& queries, int k);

    /// <summary>
    /// Leet Code 3288. Length of the Longest Increasing Path
    /// 
    /// Hard
    ///
    /// You are given a 2D array of integers coordinates of length n and an 
    /// integer k, where 0 <= k < n.
    /// coordinates[i] = [xi, yi] indicates the point (xi, yi) in a 2D plane.
    ///
    /// An increasing path of length m is defined as a list of points (x1, 
    /// y1), (x2, y2), (x3, y3), ..., (xm, ym) such that:
    ///
    /// xi < xi + 1 and yi < yi + 1 for all i where 1 <= i < m.
    /// (xi, yi) is in the given coordinates for all i where 1 <= i <= m.
    /// Return the maximum length of an increasing path that contains 
    /// coordinates[k].
    ///
    /// Example 1:
    /// Input: coordinates = [[3,1],[2,2],[4,1],[0,0],[5,3]], k = 1
    ///
    /// Output: 3
    ///
    /// Explanation:
    /// (0, 0), (2, 2), (5, 3) is the longest increasing path that 
    /// contains (2, 2).
    ///
    /// Example 2:
    /// 
    /// Input: coordinates = [[2,1],[7,0],[5,6]], k = 2
    /// Output: 2
    /// Explanation:
    /// (2, 1), (5, 6) is the longest increasing path that contains (5, 6).
    ///
    /// Constraints:
    /// 1. 1 <= n == coordinates.length <= 10^5
    /// 2. coordinates[i].length == 2
    /// 3. 0 <= coordinates[i][0], coordinates[i][1] <= 10^9
    /// 4. All elements in coordinates are distinct.
    /// 5. 0 <= k <= n - 1
    /// </summary>
    int maxPathLength(vector<vector<int>>& coordinates, int k);

    /// <summary>
    /// Leet Code 3296. Minimum Number of Seconds to Make Mountain Height Zero
    /// 
    /// Medium
    /// 
    /// You are given an integer mountainHeight denoting the height of a 
    /// mountain.
    ///
    /// You are also given an integer array workerTimes representing the 
    /// work time of workers in seconds.
    ///
    /// The workers work simultaneously to reduce the height of the mountain. 
    /// For worker i:
    ///
    /// To decrease the mountain's height by x, it takes workerTimes[i] + 
    /// workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example:
    /// To reduce the height of the mountain by 1, it takes workerTimes[i] 
    /// seconds.
    /// To reduce the height of the mountain by 2, it takes workerTimes[i] + 
    /// workerTimes[i] * 2 seconds, and so on.
    /// Return an integer representing the minimum number of seconds 
    /// required for the workers to make the height of the mountain 0.
    ///
    /// Example 1:
    /// Input: mountainHeight = 4, workerTimes = [2,1,1]
    /// Output: 3
    /// Explanation:
    ///
    /// One way the height of the mountain can be reduced to 0 is:
    /// Worker 0 reduces the height by 1, taking workerTimes[0] = 2 seconds.
    /// Worker 1 reduces the height by 2, taking workerTimes[1] + 
    /// workerTimes[1] * 2 = 3 seconds.
    /// Worker 2 reduces the height by 1, taking workerTimes[2] = 1 second.
    /// Since they work simultaneously, the minimum time needed is 
    /// max(2, 3, 1) = 3 seconds.
    ///
    /// Example 2:
    ///
    /// Input: mountainHeight = 10, workerTimes = [3,2,2,4]
    ///
    /// Output: 12
    /// Explanation:
    /// Worker 0 reduces the height by 2, taking workerTimes[0] + 
    /// workerTimes[0] * 2 = 9 seconds.
    /// Worker 1 reduces the height by 3, taking workerTimes[1] + 
    /// workerTimes[1] * 2 + workerTimes[1] * 3 = 12 seconds.
    /// Worker 2 reduces the height by 3, taking workerTimes[2] + 
    /// workerTimes[2] * 2 + workerTimes[2] * 3 = 12 seconds.
    /// Worker 3 reduces the height by 2, taking workerTimes[3] + 
    /// workerTimes[3] * 2 = 12 seconds.
    /// The number of seconds needed is max(9, 12, 12, 12) = 12 seconds.
    ///
    /// Example 3:
    /// Input: mountainHeight = 5, workerTimes = [1]
    ///
    /// Output: 15
    /// Explanation:
    /// There is only one worker in this example, so the answer is 
    /// workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 + 
    /// workerTimes[0] * 4 + workerTimes[0] * 5 = 15.
    ///
    /// Constraints:
    /// 1. 1 <= mountainHeight <= 10^5
    /// 2. 1 <= workerTimes.length <= 10^4
    /// 3. 1 <= workerTimes[i] <= 10^6
    /// </summary>
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes);

    /// <summary>
    /// Leet Code 3301. Maximize the Total Height of Unique Towers
    /// 
    /// Medium
    /// 
    /// You are given an array maximumHeight, where maximumHeight[i] denotes 
    /// the maximum height the ith tower can be assigned.
    ///
    /// Your task is to assign a height to each tower so that:
    /// The height of the ith tower is a positive integer and does not exceed 
    /// maximumHeight[i].
    /// No two towers have the same height.
    /// Return the maximum possible total sum of the tower heights. If it's 
    /// not possible to assign heights, return -1.
    /// 
    /// Example 1:
    /// Input: maximumHeight = [2,3,4,3]
    /// Output: 10
    /// Explanation:
    /// We can assign heights in the following way: [1, 2, 4, 3].
    ///
    /// Example 2:
    /// Input: maximumHeight = [15,10]
    /// Output: 25
    /// Explanation:
    /// We can assign heights in the following way: [15, 10].
    ///
    /// Example 3:
    /// Input: maximumHeight = [2,2,1]
    /// Output: -1
    /// Explanation:
    /// It's impossible to assign positive heights to each index so that no 
    /// two towers have the same height.
    /// 
    /// Constraints:
    /// 1. 1 <= maximumHeight.length <= 10^5
    /// 2. 1 <= maximumHeight[i] <= 10^9
    /// </summary>
    long long maximumTotalSum(vector<int>& maximumHeight);

    /// <summary>
    /// Leet Code 3318. Find X-Sum of All K-Long Subarrays I
    /// 
    /// Easy
    ///
    /// You are given an array nums of n integers and two integers k and x.
    ///
    /// The x-sum of an array is calculated by the following procedure:
    ///
    /// Count the occurrences of all elements in the array.
    /// Keep only the occurrences of the top x most frequent elements. If two 
    /// elements have the same number of occurrences, the element with the 
    /// bigger value is considered more frequent.
    /// Calculate the sum of the resulting array.
    /// Note that if an array has less than x distinct elements, its x-sum is 
    /// the sum of the array.
    ///
    /// Return an integer array answer of length n - k + 1 where answer[i] is 
    /// the x-sum of the subarray nums[i..i + k - 1].
    ///  
    /// Example 1:
    /// Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
    /// Output: [6,10,12]
    /// Explanation:
    /// For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in 
    /// the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
    /// For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in 
    /// the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is 
    /// kept in the array since it is bigger than 3 and 1 which occur the same 
    /// number of times.
    /// For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the 
    /// resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
    ///
    /// Example 2:
    /// Input: nums = [3,8,7,8,7,5], k = 2, x = 2
    /// Output: [11,15,15,15,12]
    /// Explanation:
    /// Since k == x, answer[i] is equal to the sum of the subarray 
    /// nums[i..i + k - 1].
    /// 
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 50
    /// 2. 1 <= nums[i] <= 50
    /// 3. 1 <= x <= k <= nums.length
    /// </summary>
    vector<int> findXSumI(vector<int>& nums, int k, int x);

    /// <summary>
    /// Leet Code 3321. Find X-Sum of All K-Long Subarrays II
    /// 
    /// Hard
    ///
    /// You are given an array nums of n integers and two integers k and x.
    ///
    /// The x-sum of an array is calculated by the following procedure:
    ///
    /// Count the occurrences of all elements in the array.
    /// Keep only the occurrences of the top x most frequent elements. If 
    /// two elements have the same number of occurrences, the element with 
    /// the bigger value is considered more frequent.
    /// Calculate the sum of the resulting array.
    /// Note that if an array has less than x distinct elements, its x-sum 
    /// is the sum of the array.
    ///
    /// Return an integer array answer of length n - k + 1 where answer[i] 
    /// is the x-sum of the subarray nums[i..i + k - 1].
    ///
    /// Example 1:
    /// Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
    /// Output: [6,10,12]
    /// Explanation:
    /// For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be 
    /// kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
    /// For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be 
    /// kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. 
    /// Note that 4 is kept in the array since it is bigger than 3 and 1 
    /// which occur the same number of times.
    /// For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in 
    /// the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
    ///
    /// Example 2:
    /// Input: nums = [3,8,7,8,7,5], k = 2, x = 2
    /// Output: [11,15,15,15,12]
    /// Explanation:
    /// Since k == x, answer[i] is equal to the sum of the subarray 
    /// nums[i..i + k - 1].
    /// 
    /// Constraints:
    /// 1. nums.length == n
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums[i] <= 10^9
    /// 4. 1 <= x <= k <= nums.length
    /// </summary>
    vector<long long>findXSumII(vector<int>& nums, int k, int x);

    /// <summary>
    /// Leet Code 3375. Minimum Operations to Make Array Values Equal to K 
    /// 
    /// Easy
    ///
    /// You are given an integer array nums and an integer k.
    /// 
    /// An integer h is called valid if all values in the array that are 
    /// strictly greater than h are identical.
    ///
    /// For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 
    /// because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.
    ///
    /// You are allowed to perform the following operation on nums:
    ///
    /// Select an integer h that is valid for the current values in nums.
    /// For each index i where nums[i] > h, set nums[i] to h.
    /// Return the minimum number of operations required to make every element 
    /// in nums equal to k. If it is impossible to make all elements equal 
    /// to k, return -1.
    /// 
    /// Example 1:
    /// Input: nums = [5,2,5,4,5], k = 2
    /// Output: 2
    /// Explanation:
    /// The operations can be performed in order using valid integers 4 and then 2.
    /// 
    /// Example 2:
    /// Input: nums = [2,1,2], k = 2
    /// Output: -1
    /// Explanation:
    /// It is impossible to make all the values equal to 2.
    /// Example 3:
    /// Input: nums = [9,7,5,3], k = 1
    /// Output: 4
    /// Explanation:
    /// The operations can be performed using valid integers in the 
    /// order 7, 5, 3, and 1.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100 
    /// 2. 1 <= nums[i] <= 100
    /// 3. 1 <= k <= 100
    /// </summary>
    int minOperationsIII(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3397. Maximum Number of Distinct Elements After Operations
    ///   
    /// Medium
    ///
    /// You are given an integer array nums and an integer k.
    /// You are allowed to perform the following operation on each element of 
    /// the array at most once:
    ///
    /// Add an integer in the range [-k, k] to the element.
    /// Return the maximum possible number of distinct elements in nums after 
    /// performing the operations.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,2,3,3,4], k = 2
    /// Output: 6
    /// Explanation:
    /// nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the 
    /// first four elements.
    ///
    /// Example 2:
    /// Input: nums = [4,4,4,4], k = 1
    /// Output: 3
    /// Explanation:
    /// By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].
    ///  
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 0 <= k <= 10^9
    /// </summary>
    int maxDistinctElements(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3409. Longest Subsequence With Decreasing Adjacent Difference
    ///   
    /// Medium
    ///
    /// 
    /// You are given an array of integers nums.
    /// Your task is to find the length of the longest subsequence seq of nums, 
    /// such that the absolute differences between consecutive elements form a 
    /// non-increasing sequence of integers. In other words, for a subsequence 
    /// seq0, seq1, seq2, ..., seqm of nums, |seq1 - seq0| >= |seq2 - seq1| 
    /// >= ... >= |seqm - seqm - 1|.
    ///
    /// Return the length of such a subsequence.
    /// 
    /// Example 1:
    /// Input: nums = [16,6,3]
    /// Output: 3
    /// Explanation: 
    /// The longest subsequence is [16, 6, 3] with the absolute adjacent 
    /// differences [10, 3].
    ///
    /// Example 2:
    /// Input: nums = [6,5,3,4,2,1]
    /// Output: 4
    /// Explanation:
    /// The longest subsequence is [6, 4, 2, 1] with the absolute adjacent 
    /// differences [2, 2, 1].
    ///
    /// Example 3:
    /// Input: nums = [10,20,10,19,10,20]
    /// Output: 5
    /// Explanation: 
    /// The longest subsequence is [10, 20, 10, 19, 10] with the absolute 
    /// adjacent differences [10, 10, 9, 9].
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^4
    /// 2. 1 <= nums[i] <= 300
    /// </summary>
    int longestSubsequence(vector<int>& nums);

    /// <summary>
    /// Leet Code 3422. Minimum Operations to Make Subarray Elements Equal
    ///   
    /// Medium
    ///
    /// You are given an integer array nums and an integer k. You can 
    /// perform the following operation any number of times:
    ///
    /// Increase or decrease any element of nums by 1.
    /// Return the minimum number of operations required to ensure that at 
    /// least one subarray of size k in nums has all elements equal.
    ///
    /// Example 1:
    /// Input: nums = [4,-3,2,1,-4,6], k = 3
    /// Output: 5
    /// Explanation:
    /// Use 4 operations to add 4 to nums[1]. The resulting array is 
    /// [4, 1, 2, 1, -4, 6].
    /// Use 1 operation to subtract 1 from nums[2]. The resulting array is 
    /// [4, 1, 1, 1, -4, 6].
    /// The array now contains a subarray [1, 1, 1] of size k = 3 with all 
    /// elements equal. Hence, the answer is 5.
    ///
    /// Example 2:
    /// Input: nums = [-2,-2,3,1,4], k = 2
    /// Output: 0
    /// Explanation:
    /// The subarray [-2, -2] of size k = 2 already contains all equal 
    /// elements, so no operations are needed. Hence, the answer is 0.
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. -10^6 <= nums[i] <= 10^6
    /// 3. 2 <= k <= nums.length
    /// </summary>
    long long minOperationsIV(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3457. Eat Pizzas!
    ///   
    /// Medium
    ///
    /// You are given an integer array pizzas of size n, where pizzas[i] 
    /// represents the weight of the ith pizza. Every day, you eat exactly 4 
    /// pizzas. Due to your incredible metabolism, when you eat pizzas of 
    /// weights W, X, Y, and Z, where W <= X <= Y <= Z, you gain the weight of 
    /// only 1 pizza!
    ///
    /// On odd-numbered days (1-indexed), you gain a weight of Z.
    /// On even-numbered days, you gain a weight of Y.
    /// Find the maximum total weight you can gain by eating all pizzas optimally.
    ///
    /// Note: It is guaranteed that n is a multiple of 4, and each pizza can be 
    /// eaten only once.
    ///
    /// Example 1:
    /// Input: pizzas = [1,2,3,4,5,6,7,8]
    /// Output: 14
    /// Explanation:
    /// 
    /// On day 1, you eat pizzas at indices [1, 2, 4, 7] = [2, 3, 5, 8]. You gain 
    /// a weight of 8.
    /// On day 2, you eat pizzas at indices [0, 3, 5, 6] = [1, 4, 6, 7]. You gain 
    /// a weight of 6.
    /// The total weight gained after eating all the pizzas is 8 + 6 = 14.
    ///
    /// Example 2:
    /// Input: pizzas = [2,1,1,1,1,1,1,1]
    /// Output: 3
    /// Explanation:
    /// On day 1, you eat pizzas at indices [4, 5, 6, 0] = [1, 1, 1, 2]. You gain 
    /// a weight of 2.
    /// On day 2, you eat pizzas at indices [1, 2, 3, 7] = [1, 1, 1, 1]. You gain 
    /// a weight of 1.
    /// The total weight gained after eating all the pizzas is 2 + 1 = 3.
    ///
    /// Constraints:
    /// 1. 4 <= n == pizzas.length <= 2 * 10^5
    /// 2. 1 <= pizzas[i] <= 10^5
    /// 3. n is a multiple of 4.
    /// </summary>
    long long maxWeight(vector<int>& pizzas);

    /// <summary>
    /// Leet Code 3462. Maximum Sum With at Most K Elements
    ///   
    /// Medium
    ///
    /// You are given a 2D integer matrix grid of size n x m, an integer array 
    /// limits of length n, and an integer k. The task is to find the maximum 
    /// sum of at most k elements from the matrix grid such that:
    ///
    /// The number of elements taken from the ith row of grid does not exceed 
    /// limits[i].
    ///
    /// Return the maximum sum.
    /// Example 1:
    ///
    /// Input: grid = [[1,2],[3,4]], limits = [1,2], k = 2
    /// Output: 7
    /// Explanation:
    /// From the second row, we can take at most 2 elements. The elements taken 
    /// are 4 and 3.
    /// The maximum possible sum of at most 2 selected elements is 4 + 3 = 7.
    ///
    /// Example 2:
    /// Input: grid = [[5,3,7],[8,2,6]], limits = [2,2], k = 3
    /// Output: 21
    /// Explanation:
    /// From the first row, we can take at most 2 elements. The element taken 
    /// is 7.
    /// From the second row, we can take at most 2 elements. The elements taken 
    /// are 8 and 6.
    /// The maximum possible sum of at most 3 selected elements is 7 + 8 + 6 = 21.
    ///
    /// Constraints:
    /// 1. n == grid.length == limits.length
    /// 2. m == grid[i].length
    /// 3. 1 <= n, m <= 500
    /// 4. 0 <= grid[i][j] <= 10^5
    /// 5. 0 <= limits[i] <= m
    /// 6. 0 <= k <= min(n * m, sum(limits))
    /// </summary>
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k);

    /// <summary>
    /// Leet Code 3476. Maximize Profit from Task Assignment
    ///
    /// Medium
    ///
    /// You are given an integer array workers, where workers[i] represents the 
    /// skill level of the ith worker. You are also given a 2D integer array 
    /// tasks, where:
    ///
    /// tasks[i][0] represents the skill requirement needed to complete the task.
    /// tasks[i][1] represents the profit earned from completing the task.
    /// Each worker can complete at most one task, and they can only take a task 
    /// if their skill level is equal to the task's skill requirement. An 
    /// additional worker joins today who can take up any task, regardless of 
    /// the skill requirement.
    ///
    /// Return the maximum total profit that can be earned by optimally assigning 
    /// the tasks to the workers.
    ///
    /// 
    /// Example 1:
    /// Input: workers = [1,2,3,4,5], tasks = [[1,100],[2,400],[3,100],[3,400]]
    /// Output: 1000
    /// Explanation:
    /// Worker 0 completes task 0.
    /// Worker 1 completes task 1.
    /// Worker 2 completes task 3.
    /// The additional worker completes task 2.
    ///
    /// Example 2:
    /// Input: workers = [10,10000,100000000], tasks = [[1,100]]
    /// Output: 100
    /// Explanation:
    /// Since no worker matches the skill requirement, only the additional worker 
    /// can complete task 0.
    ///
    /// Example 3:
    /// Input: workers = [7], tasks = [[3,3],[3,3]]
    /// Output: 3
    /// Explanation:
    /// The additional worker completes task 1. Worker 0 cannot work since no 
    /// task has a skill requirement of 7.
    /// 
    /// Constraints:
    /// 1. 1 <= workers.length <= 10^5
    /// 2. 1 <= workers[i] <= 10^9
    /// 3. 1 <= tasks.length <= 10^5
    /// 4. tasks[i].length == 2
    /// 5. 1 <= tasks[i][0], tasks[i][1] <= 10^9
    /// </summary>
    long long maxProfitIII(vector<int>& workers, vector<vector<int>>& tasks);

    /// <summary>
    /// Leet Code 3478. Choose K Elements With Maximum Sum
    ///
    /// Medium
    ///
    // You are given two integer arrays, nums1 and nums2, both of length n, 
    /// along with a positive integer k.
    ///
    /// For each index i from 0 to n - 1, perform the following:
    ///
    /// Find all indices j where nums1[j] is less than nums1[i].
    /// Choose at most k values of nums2[j] at these indices to maximize the 
    /// total sum.
    /// Return an array answer of size n, where answer[i] represents the result 
    /// for the corresponding index i.
    ///
    /// Example 1:
    /// Input: nums1 = [4,2,1,5,3], nums2 = [10,20,30,40,50], k = 2
    /// Output: [80,30,0,80,50]
    /// Explanation:
    ///
    /// For i = 0: Select the 2 largest values from nums2 at indices [1, 2, 4] 
    /// where nums1[j] < nums1[0], resulting in 50 + 30 = 80.
    /// For i = 1: Select the 2 largest values from nums2 at index [2] where 
    /// nums1[j] < nums1[1], resulting in 30.
    /// For i = 2: No indices satisfy nums1[j] < nums1[2], resulting in 0.
    /// For i = 3: Select the 2 largest values from nums2 at indices [0, 1, 2, 4] 
    /// where nums1[j] < nums1[3], resulting in 50 + 30 = 80.
    /// For i = 4: Select the 2 largest values from nums2 at indices [1, 2] 
    /// where nums1[j] < nums1[4], resulting in 30 + 20 = 50.
    ///
    /// Example 2:
    /// Input: nums1 = [2,2,2,2], nums2 = [3,1,2,3], k = 1
    ///
    /// Output: [0,0,0,0]
    ///
    /// Explanation:
    /// Since all elements in nums1 are equal, no indices satisfy the condition 
    //// nums1[j] < nums1[i] for any i, resulting in 0 for all positions.
    ///
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums1[i], nums2[i] <= 10^6
    /// 4. 1 <= k <= n
    /// </summary>
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k);

    /// <summary>
    /// Leet Code 3502. Minimum Cost to Reach Every Position
    ///
    /// Easy
    /// You are given an integer array cost of size n. You are currently at 
    /// position n (at the end of the line) in a line of n + 1 people (numbered 
    /// from 0 to n).
    ///
    /// You wish to move forward in the line, but each person in front of you 
    /// charges a specific amount to swap places. The cost to swap with person 
    /// i is given by cost[i].
    ///
    /// You are allowed to swap places with people as follows:
    /// If they are in front of you, you must pay them cost[i] to swap with them.
    /// If they are behind you, they can swap with you for free.
    /// Return an array answer of size n, where answer[i] is the minimum total 
    /// cost to reach each position i in the line.
    ///
    /// Example 1:
    /// Input: cost = [5,3,4,1,3,2]
    /// Output: [5,3,3,1,1,1]
    /// Explanation:
    /// We can get to each position in the following way:
    /// 1. i = 0. We can swap with person 0 for a cost of 5.
    /// 2. i = 1. We can swap with person 1 for a cost of 3.
    /// 3. i = 2. We can swap with person 1 for a cost of 3, then swap with 
    ///    person 2 for free.
    /// 4. i = 3. We can swap with person 3 for a cost of 1.
    /// 5. i = 4. We can swap with person 3 for a cost of 1, then swap with 
    ///    person 4 for free.
    /// 6. i = 5. We can swap with person 3 for a cost of 1, then swap with 
    ///    person 5 for free.
    ///
    /// Example 2:
    /// Input: cost = [1,2,4,6,7]
    /// Output: [1,1,1,1,1]
    /// Explanation:
    /// We can swap with person 0 for a cost of 1, then we will be able to reach 
    /// any position i for free.
    /// 
    /// Constraints:
    /// 1. 1 <= n == cost.length <= 100
    /// 2. 1 <= cost[i] <= 100
    /// </summary>
    vector<int> minCosts(vector<int>& cost);

    /// <summary>
    /// Leet Code 3505. Minimum Operations to Make Elements Within K Subarrays 
    ///                 Equal
    ///
    /// Hard
    /// 
    /// You are given an integer array nums and two integers, x and k. You can 
    /// perform the following operation any number of times (including zero):
    ///
    /// Increase or decrease any element of nums by 1.
    /// Return the minimum number of operations needed to have at least k non-
    /// overlapping subarrays of size exactly x in nums, where all elements 
    /// within each subarray are equal.
    ///
    /// 
    /// Example 1:
    /// Input: nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2
    /// Output: 8
    /// Explanation:
    /// Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 
    /// from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
    /// Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 
    /// from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
    /// Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) 
    /// and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations 
    /// were used, 8 is the output.
    ///
    /// Example 2:
    /// Input: nums = [9,-2,-2,-2,1,5], x = 2, k = 2
    /// Output: 3
    /// Explanation:
    /// Use 3 operations to subtract 3 from nums[4]. The resulting array 
    /// is [9, -2, -2, -2, -2, 5].
    /// Now, all elements within each subarray [-2, -2] (from indices 1 to 2) 
    /// and [-2, -2] (from indices 3 to 4) are equal. Since 3 operations were 
    /// used, 3 is the output.
    ///  
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. -10^6 <= nums[i] <= 10^6
    /// 3. 2 <= x <= nums.length
    /// 4. 1 <= k <= 15
    /// 5. 2 <= k * x <= nums.length
    /// </summary>
    long long minOperations(vector<int>& nums, int x, int k);

    /// <summary>
    /// Leet Code 3507. Minimum Pair Removal to Sort Array I 
    ///
    /// Easy
    /// 
    /// Given an array nums, you can perform the following operation any number of 
    /// times:
    ///
    /// Select the adjacent pair with the minimum sum in nums. If multiple such 
    /// pairs exist, choose the leftmost one.
    /// Replace the pair with their sum.
    /// Return the minimum number of operations needed to make the array non-
    /// decreasing.
    ///
    /// An array is said to be non-decreasing if each element is greater than or 
    /// equal to its previous element (if it exists).
    ///
    /// Example 1:
    /// Input: nums = [5,2,3,1]
    /// Output: 2
    /// Explanation:
    /// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    /// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
    /// The array nums became non-decreasing in two operations.
    ///
    /// Example 2:
    /// Input: nums = [1,2,2]
    /// Output: 0
    /// Explanation:
    /// The array nums is already sorted.
    ///  
    /// Constraints:
    /// 1. 1 <= nums.length <= 50
    /// 2. -1000 <= nums[i] <= 1000
    /// </summary>
    int minimumPairRemovalI(vector<int>& nums);

    /// <summary>
    /// Leet Code 3510. Minimum Pair Removal to Sort Array II
    ///
    /// Hard
    ///
    /// Given an array nums, you can perform the following operation any number of 
    /// times:
    ///
    /// Select the adjacent pair with the minimum sum in nums. If multiple such 
    /// pairs exist, choose the leftmost one.
    /// Replace the pair with their sum.
    /// Return the minimum number of operations needed to make the array 
    /// non-decreasing.
    ///
    /// An array is said to be non-decreasing if each element is greater than or 
    /// equal to its previous element (if it exists).
    ///
    /// Example 1:
    /// Input: nums = [5,2,3,1]
    /// Output: 2
    /// Explanation:
    /// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    /// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
    /// The array nums became non-decreasing in two operations.
    ///
    /// Example 2:
    /// Input: nums = [1,2,2]
    /// Output: 0
    /// Explanation:
    /// The array nums is already sorted.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// </summary>
    int minimumPairRemovalII(vector<int>& nums);

    /// <summary>
    /// Leet Code 3531. Count Covered Buildings
    ///
    /// Medium
    ///
    /// You are given a positive integer n, representing an n x n city. You are 
    /// also given a 2D grid buildings, where buildings[i] = [x, y] denotes a 
    /// unique building located at coordinates [x, y].
    ///
    /// A building is covered if there is at least one building in all four 
    /// directions: left, right, above, and below.
    ///
    /// Return the number of covered buildings.
    /// 
    /// Example 1:
    /// Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
    /// Output: 1
    /// Explanation:
    /// Only building [2,2] is covered as it has at least one building:
    /// above ([1,2])
    /// below ([3,2])
    /// left ([2,1])
    /// right ([2,3])
    /// Thus, the count of covered buildings is 1.
    ///
    /// Example 2:
    /// Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]
    /// Output: 0
    /// Explanation:
    /// No building has at least one building in all four directions.
    ///
    /// Example 3:
    /// Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]
    /// Output: 1
    /// Explanation:
    /// Only building [3,3] is covered as it has at least one building:
    /// above ([1,3])
    /// below ([5,3])
    /// left ([3,2])
    /// right ([3,5])
    /// Thus, the count of covered buildings is 1.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 105
    /// 2. 1 <= buildings.length <= 105 
    /// 3. buildings[i] = [x, y]
    /// 4. 1 <= x, y <= n
    /// 5. All coordinates of buildings are unique.
    /// </summary>
    int countCoveredBuildings(int n, vector<vector<int>>& buildings);

    /// <summary>
    /// Leet Code 3536. Maximum Product of Two Digits 
    ///
    /// Easy
    ///
    /// You are given a positive integer n.
    /// Return the maximum product of any two digits in n.
    /// Note: You may use the same digit twice if it appears more than once in n.
    ///
    /// Example 1:
    /// Input: n = 31
    /// Output: 3
    /// Explanation:
    /// The digits of n are [3, 1].
    /// The possible products of any two digits are: 3 * 1 = 3.
    /// The maximum product is 3.
    ///
    /// Example 2:
    /// Input: n = 22
    /// Output: 4
    /// Explanation:
    /// The digits of n are [2, 2].
    /// The possible products of any two digits are: 2 * 2 = 4.
    /// The maximum product is 4.
    ///
    /// Example 3:
    /// Input: n = 124
    /// Output: 8
    /// Explanation:
    /// The digits of n are [1, 2, 4].
    /// The possible products of any two digits are: 1 * 2 = 2, 1 * 4 = 4, 
    /// 2 * 4 = 8.
    /// The maximum product is 8.
    ///
    /// Constraints:
    /// 1. 10 <= n <= 10^9
    /// </summary>
    int maxProduct(int n);

    /// <summary>
    /// Leet Code 3555. Smallest Subarray to Sort in Every Sliding Window
    ///
    /// Medium
    ///
    /// You are given an integer array nums and an integer k.
    ///
    /// For each contiguous subarray of length k, determine the minimum length of 
    /// a continuous segment that must be sorted so that the entire window becomes 
    /// non‑decreasing; if the window is already sorted, its required length is 
    /// zero.
    ///
    /// Return an array of length n − k + 1 where each element corresponds to the 
    /// answer for its window.
    /// 
    /// Example 1:
    /// Input: nums = [1,3,2,4,5], k = 3
    /// Output: [2,2,0]
    /// Explanation:
    /// nums[0...2] = [1, 3, 2]. Sort [3, 2] to get [1, 2, 3], the answer is 2.
    /// nums[1...3] = [3, 2, 4]. Sort [3, 2] to get [2, 3, 4], the answer is 2.
    /// nums[2...4] = [2, 4, 5] is already sorted, so the answer is 0.
    ///
    /// Example 2:
    /// Input: nums = [5,4,3,2,1], k = 4
    /// Output: [4,4]
    /// Explanation:
    /// nums[0...3] = [5, 4, 3, 2]. The whole subarray must be sorted, so the 
    /// answer is 4.
    /// nums[1...4] = [4, 3, 2, 1]. The whole subarray must be sorted, so the 
    /// answer is 4.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= k <= nums.length
    /// 3. 1 <= nums[i] <= 10^6
    /// </summary>
    vector<int> minSubarraySort(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3572. Maximize Y‑Sum by Picking a Triplet of Distinct X‑Values
    ///
    /// Medium
    ///
    /// You are given two integer arrays x and y, each of length n. You must 
    /// choose three distinct indices i, j, and k such that:
    ///
    /// x[i] != x[j]
    /// x[j] != x[k]
    /// x[k] != x[i]
    /// Your goal is to maximize the value of y[i] + y[j] + y[k] under these 
    /// conditions. Return the maximum possible sum that can be obtained by 
    /// choosing such a triplet of indices.
    ///
    /// If no such triplet exists, return -1.
    /// 
    /// Example 1:
    /// Input: x = [1,2,1,3,2], y = [5,3,4,6,2]
    /// Output: 14
    /// Explanation:
    /// Choose i = 0 (x[i] = 1, y[i] = 5), j = 1 (x[j] = 2, y[j] = 3), k = 3 
    /// (x[k] = 3, y[k] = 6).
    /// All three values chosen from x are distinct. 5 + 3 + 6 = 14 is the maximum 
    /// we can obtain. Hence, the output is 14.
    ///
    /// Example 2:
    /// Input: x = [1,2,1,2], y = [4,5,6,7]
    /// Output: -1
    /// Explanation:
    /// There are only two distinct values in x. Hence, the output is -1.
    /// 
    /// Constraints:
    /// 1. n == x.length == y.length
    /// 2. 3 <= n <= 10^5
    /// 3. 1 <= x[i], y[i] <= 10^6
    /// </summary>
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y);

    /// <summary>
    /// Leet Code 3627. Maximum Median Sum of Subsequences of Size 3
    ///
    /// Medium
    ///
    /// You are given an integer array nums with a length divisible by 3.
    ///
    /// You want to make the array empty in steps. In each step, you can select 
    /// any three elements from the array, compute their median, and remove the 
    /// selected elements from the array.
    ///
    /// The median of an odd-length sequence is defined as the middle element of 
    /// the sequence when it is sorted in non-decreasing order.
    ///
    /// Return the maximum possible sum of the medians computed from the selected 
    /// elements.
    /// 
    /// Example 1:
    /// Input: nums = [2,1,3,2,1,3]
    /// Output: 5
    /// Explanation:
    /// In the first step, select elements at indices 2, 4, and 5, which have a 
    /// median 3. After removing these elements, nums becomes [2, 1, 2].
    /// In the second step, select elements at indices 0, 1, and 2, which have 
    /// a median 2. After removing these elements, nums becomes empty.
    /// Hence, the sum of the medians is 3 + 2 = 5.
    ///
    /// Example 2:
    /// Input: nums = [1,1,10,10,10,10]
    /// Output: 20
    /// 
    /// Explanation:
    /// In the first step, select elements at indices 0, 2, and 3, which have a
    /// median 10. After removing these elements, nums becomes [1, 10, 10].
    /// In the second step, select elements at indices 0, 1, and 2, which have a 
    /// median 10. After removing these elements, nums becomes empty.
    /// Hence, the sum of the medians is 10 + 10 = 20.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 5 * 10^5
    /// 2. nums.length % 3 == 0
    /// 3. 1 <= nums[i] <= 10^9
    /// </summary>
    long long maximumMedianSum(vector<int>& nums);

    /// <summary>
    /// Leet Code 3631. Sort Threats by Severity and Exploitability
    ///
    /// Medium
    ///
    /// You are given a 2D integer array threats, where each 
    /// threats[i] = [IDi, sevi, expi]
    ///
    /// IDi: Unique identifier of the threat.
    /// sevi: Indicates the severity of the threat.
    /// expi: Indicates the exploitability of the threat.
    /// The score of a threat i is defined as: score = 2 × sevi + expi
    ///
    /// Your task is to return threats sorted in descending order of score.
    /// If multiple threats have the same score, sort them by ascending ID.
    /// 
    /// Example 1:
    /// Input: threats = [[101,2,3],[102,3,2],[103,3,3]]
    /// Output: [[103,3,3],[102,3,2],[101,2,3]]
    /// Explanation:
    /// Threat  ID  sev exp Score = 2 × sev + exp
    /// threats[0]  101 2   3   2 × 2 + 3 = 7
    /// threats[1]  102 3   2   2 × 3 + 2 = 8
    /// threats[2]  103 3   3   2 × 3 + 3 = 9
    /// Sorted Order: [[103, 3, 3], [102, 3, 2], [101, 2, 3]]
    ///
    /// Example 2:
    /// Input: threats = [[101,4,1],[103,1,5],[102,1,5]]
    /// Output: [[101,4,1],[102,1,5],[103,1,5]]
    /// Explanation:
    /// Threat  ID  sev exp Score = 2 × sev + exp
    /// threats[0]  101 4   1   2 × 4 + 1 = 9
    /// threats[1]  103 1   5   2 × 1 + 5 = 7
    /// threats[2]  102 1   5   2 × 1 + 5 = 7
    /// threats[1] and threats[2] have same score, thus sort them by ascending ID.
    ///
    /// Sorted Order: [[101, 4, 1], [102, 1, 5], [103, 1, 5]]
    ///
    /// Constraints:
    /// 1. 1 <= threats.length <= 10^5
    /// 2. threats[i] == [IDi, sevi, expi]
    /// 3. 1 <= IDi <= 10^6
    /// 4. 1 <= sevi <= 10^9
    /// 5. 1 <= expi <= 10^9
    /// 6. All IDi are unique
    /// </summary>
    vector<vector<int>> sortThreats(vector<vector<int>>& threats);

    /// <summary>
    /// Leet Code 3633. Earliest Finish Time for Land and Water Rides I
    ///
    /// Easy
    ///
    /// You are given two categories of theme park attractions: land rides and 
    /// water rides.
    ///
    /// Land rides
    /// landStartTime[i] – the earliest time the ith land ride can be boarded.
    /// landDuration[i] – how long the ith land ride lasts.
    /// Water rides
    /// waterStartTime[j] – the earliest time the jth water ride can be boarded.
    /// waterDuration[j] – how long the jth water ride lasts.
    /// A tourist must experience exactly one ride from each category, in either 
    /// order.
    ///
    /// A ride may be started at its opening time or any later moment.
    /// If a ride is started at time t, it finishes at time t + duration.
    /// Immediately after finishing one ride the tourist may board the other (if 
    /// it is already open) or wait until it opens.
    /// Return the earliest possible time at which the tourist can finish both 
    /// rides.
    /// 
    /// Example 1:
    /// Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], 
    /// waterDuration = [3]
    /// Output: 9
    /// Explanation:
    /// Plan A (land ride 0 → water ride 0):
    /// Start land ride 0 at time landStartTime[0] = 2. 
    /// Finish at 2 + landDuration[0] = 6.
    /// Water ride 0 opens at time waterStartTime[0] = 6. Start immediately at 6, 
    /// finish at 6 + waterDuration[0] = 9.
    /// Plan B (water ride 0 → land ride 1):
    /// Start water ride 0 at time waterStartTime[0] = 6. 
    /// Finish at 6 + waterDuration[0] = 9.
    /// Land ride 1 opens at landStartTime[1] = 8. Start at time 9, 
    /// finish at 9 + landDuration[1] = 10.
    /// Plan C (land ride 1 → water ride 0):
    /// Start land ride 1 at time landStartTime[1] = 8. 
    /// Finish at 8 + landDuration[1] = 9.
    /// Water ride 0 opened at waterStartTime[0] = 6. Start at time 9, 
    /// finish at 9 + waterDuration[0] = 12.
    /// Plan D (water ride 0 → land ride 0):
    /// Start water ride 0 at time waterStartTime[0] = 6. 
    /// Finish at 6 + waterDuration[0] = 9.
    /// Land ride 0 opened at landStartTime[0] = 2. Start at time 9, 
    /// finish at 9 + landDuration[0] = 13.
    /// Plan A gives the earliest finish time of 9.
    ///
    /// Example 2:
    /// Input: landStartTime = [5], landDuration = [3], waterStartTime = [1], 
    /// waterDuration = [10]
    /// 
    /// Output: 14
    /// Explanation:
    /// Plan A (water ride 0 → land ride 0):
    /// Start water ride 0 at time waterStartTime[0] = 1. 
    /// Finish at 1 + waterDuration[0] = 11.
    /// Land ride 0 opened at landStartTime[0] = 5. Start immediately at 11 and 
    /// finish at 11 + landDuration[0] = 14.
    /// Plan B (land ride 0 → water ride 0):
    /// Start land ride 0 at time landStartTime[0] = 5. 
    /// Finish at 5 + landDuration[0] = 8.
    /// Water ride 0 opened at waterStartTime[0] = 1. Start immediately at 8 and 
    /// finish at 8 + waterDuration[0] = 18.
    /// Plan A provides the earliest finish time of 14.
    /// 
    /// Constraints:
    /// 1. 1 <= n, m <= 100
    /// 2. landStartTime.length == landDuration.length == n
    /// 3. waterStartTime.length == waterDuration.length == m
    /// 4. 1 <= landStartTime[i], landDuration[i], waterStartTime[j], 
    ///    waterDuration[j] <= 1000
    /// </summary>
    int earliestFinishTimeI(vector<int>& landStartTime, vector<int>& landDuration,
        vector<int>& waterStartTime, vector<int>& waterDuration);

    /// <summary>
    /// Leet Code 3634. Minimum Removals to Balance Array
    ///
    /// Medium
    ///
    /// You are given an integer array nums and an integer k.
    ///
    /// An array is considered balanced if the value of its maximum element is at 
    /// most k times the minimum element.
    ///
    /// You may remove any number of elements from nums without making it empty.
    ///
    /// Return the minimum number of elements to remove so that the remaining 
    /// array is balanced.
    /// Note: An array of size 1 is considered balanced as its maximum and minimum 
    /// are equal, and the condition always holds true.
    /// 
    /// Example 1:
    /// Input: nums = [2,1,5], k = 2
    /// Output: 1
    /// Explanation:
    /// Remove nums[2] = 5 to get nums = [2, 1].
    /// Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.
    ///
    /// Example 2:
    /// Input: nums = [1,6,2,9], k = 3
    /// Output: 2
    /// Explanation:
    /// Remove nums[0] = 1 and nums[3] = 9 to get nums = [6, 2].
    /// Now max = 6, min = 2 and max <= min * k as 6 <= 2 * 3. Thus, the answer is 2.
    ///
    /// Example 3:
    /// Input: nums = [4,6], k = 2
    /// Output: 0
    /// Explanation:
    /// Since nums is already balanced as 6 <= 4 * 2, no elements need to be removed.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= 10^5
    /// </summary>
    int minRemoval(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3635. Earliest Finish Time for Land and Water Rides II
    ///
    /// Medium
    ///
    /// You are given two categories of theme park attractions: land rides 
    /// and water rides.
    ///
    /// Land rides
    /// landStartTime[i] – the earliest time the ith land ride can be boarded.
    /// landDuration[i] – how long the ith land ride lasts.
    /// Water rides
    /// waterStartTime[j] – the earliest time the jth water ride can be boarded.
    /// waterDuration[j] – how long the jth water ride lasts.
    /// A tourist must experience exactly one ride from each category, in either 
    /// order.
    ///
    /// A ride may be started at its opening time or any later moment.
    /// If a ride is started at time t, it finishes at time t + duration.
    /// Immediately after finishing one ride the tourist may board the other (if 
    /// it is already open) or wait until it opens.
    /// Return the earliest possible time at which the tourist can finish both 
    /// rides.
    /// 
    /// Example 1:
    /// Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], 
    /// waterDuration = [3]
    /// Output: 9
    /// Explanation:
    /// Plan A (land ride 0 → water ride 0):
    /// Start land ride 0 at time landStartTime[0] = 2. Finish at 
    /// 2 + landDuration[0] = 6.
    /// Water ride 0 opens at time waterStartTime[0] = 6. Start immediately at 6, 
    /// finish at 6 + waterDuration[0] = 9.
    /// Plan B (water ride 0 → land ride 1):
    /// Start water ride 0 at time waterStartTime[0] = 6. Finish at 
    /// 6 + waterDuration[0] = 9.
    /// Land ride 1 opens at landStartTime[1] = 8. Start at time 9, finish at 
    /// 9 + landDuration[1] = 10.
    /// Plan C (land ride 1 → water ride 0):
    /// Start land ride 1 at time landStartTime[1] = 8. Finish at 
    /// 8 + landDuration[1] = 9.
    /// Water ride 0 opened at waterStartTime[0] = 6. Start at time 9, finish 
    /// at 9 + waterDuration[0] = 12.
    /// Plan D (water ride 0 → land ride 0):
    /// Start water ride 0 at time waterStartTime[0] = 6. Finish at 
    /// 6 + waterDuration[0] = 9.
    /// Land ride 0 opened at landStartTime[0] = 2. Start at time 9, 
    /// finish at 9 + landDuration[0] = 13.
    /// Plan A gives the earliest finish time of 9.
    ///
    /// Example 2:
    /// Input: landStartTime = [5], landDuration = [3], waterStartTime = [1], 
    /// waterDuration = [10]
    /// Output: 14
    /// Explanation:
    /// Plan A (water ride 0 → land ride 0):
    /// Start water ride 0 at time waterStartTime[0] = 1. Finish at 
    /// 1 + waterDuration[0] = 11.
    /// Land ride 0 opened at landStartTime[0] = 5. Start immediately at 11 and 
    /// finish at 11 + landDuration[0] = 14.
    /// Plan B (land ride 0 → water ride 0):
    /// Start land ride 0 at time landStartTime[0] = 5. Finish at 
    /// 5 + landDuration[0] = 8.
    /// Water ride 0 opened at waterStartTime[0] = 1. Start immediately at 8 and 
    /// finish at 8 + waterDuration[0] = 18.
    /// Plan A provides the earliest finish time of 14.
    /// 
    /// Constraints:
    /// 1. 1 <= n, m <= 5 * 10^4
    /// 2. landStartTime.length == landDuration.length == n
    /// 3. waterStartTime.length == waterDuration.length == m
    /// 4. 1 <= landStartTime[i], landDuration[i], waterStartTime[j], 
    ///    waterDuration[j] <= 10^5
    /// </summary>
    int earliestFinishTimeII(vector<int>& landStartTime, vector<int>& landDuration,
        vector<int>& waterStartTime, vector<int>& waterDuration);
    /// <summary>
    /// Leet Code 3645. Maximum Total from Optimal Activation Order
    ///
    /// Medium
    ///
    /// You are given two integer arrays value and limit, both of length n.
    ///
    /// Initially, all elements are inactive. You may activate them in any order.
    ///
    /// To activate an inactive element at index i, the number of currently active 
    /// elements must be strictly less than limit[i].
    /// When you activate the element at index i, it adds value[i] to the total 
    /// activation value (i.e., the sum of value[i] for all elements that have 
    /// undergone activation operations).
    /// After each activation, if the number of currently active elements 
    /// becomes x, then all elements j with limit[j] <= x become permanently 
    /// inactive, even if they are already active.
    /// Return the maximum total you can obtain by choosing the activation order 
    /// optimally.
    /// 
    /// Example 1:
    /// Input: value = [3,5,8], limit = [2,1,3]
    /// Output: 16
    /// Explanation:
    /// One optimal activation order is:
    /// Step    Activated i value[i]    Active Before i Active After i  Becomes 
    /// Inactive j  Inactive Elements   Total
    /// 1   1   5   0   1   j = 1 as limit[1] = 1   [1] 5
    /// 2   0   3   0   1   -   [1] 8
    /// 3   2   8   1   2   j = 0 as limit[0] = 2   [0, 1]  16
    /// Thus, the maximum possible total is 16.
    ///
    /// Example 2:
    /// Input: value = [4,2,6], limit = [1,1,1]
    /// Output: 6
    /// Explanation:
    /// One optimal activation order is:
    /// Step    Activated i value[i]    Active Before i Active After i  Becomes 
    /// Inactive j  Inactive Elements   Total
    /// 1   2   6   0   1   j = 0, 1, 2 as limit[j] = 1 [0, 1, 2]   6
    /// Thus, the maximum possible total is 6.
    ///
    /// Example 3:
    /// Input: value = [4,1,5,2], limit = [3,3,2,3]
    /// Output: 12
    /// Explanation:
    /// One optimal activation order is:
    /// Step    Activated i value[i]    Active Before i Active After i  
    /// Becomes Inactive j  Inactive Elements   Total
    /// 1   2   5   0   1   -   [ ] 5
    /// 2   0   4   1   2   j = 2 as limit[2] = 2   [2] 9
    /// 3   1   1   1   2   -   [2] 10
    /// 4   3   2   2   3   j = 0, 1, 3 as limit[j] = 3 [0, 1, 2, 3]    12
    /// Thus, the maximum possible total is 12.
    ///
    /// Constraints:
    /// 1. 1 <= n == value.length == limit.length <= 10^5
    /// 2. 1 <= value[i] <= 10^5
    /// 3. 1 <= limit[i] <= n
    /// </summary>
    long long maxTotal(vector<int>& value, vector<int>& limit);

    /// <summary>
    /// Leet Code 3660. Jump Game IX
    ///
    /// Medium
    ///
    /// You are given an integer array nums.
    ///
    /// From any index i, you can jump to another index j under the following 
    /// rules:
    ///
    /// Jump to index j where j > i is allowed only if nums[j] < nums[i].
    /// Jump to index j where j < i is allowed only if nums[j] > nums[i].
    /// For each index i, find the maximum value in nums that can be reached by 
    /// following any sequence of valid jumps starting at i.
    ///
    /// Return an array ans where ans[i] is the maximum value reachable starting 
    /// from index i.
    ///
    ///
    /// Example 1:
    /// Input: nums = [2,1,3]
    /// Output: [2,2,3]
    /// Explanation:
    /// For i = 0: No jump increases the value.
    /// For i = 1: Jump to j = 0 as nums[j] = 2 is greater than nums[i].
    /// For i = 2: Since nums[2] = 3 is the maximum value in nums, no jump 
    /// increases the value.
    /// Thus, ans = [2, 2, 3].
    ///
    /// Example 2:
    /// Input: nums = [2,3,1]
    /// Output: [3,3,3]
    /// Explanation:
    /// For i = 0: Jump forward to j = 2 as nums[j] = 1 is less than nums[i] = 2, 
    /// then from i = 2 jump to j = 1 as nums[j] = 3 is greater than nums[2].
    /// For i = 1: Since nums[1] = 3 is the maximum value in nums, no jump 
    /// increases the value.
    /// For i = 2: Jump to j = 1 as nums[j] = 3 is greater than nums[2] = 1.
    /// Thus, ans = [3, 3, 3].
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    vector<int> maxValue(vector<int>& nums);

    /// <summary>
    /// Leet Code 3667. Sort Array By Absolute Value
    ///
    /// Easy
    ///
    /// You are given an integer array nums.
    /// Rearrange elements of nums in non-decreasing order of their absolute value.
    ///
    /// Return any rearranged array that satisfies this condition.
    /// Note: The absolute value of an integer x is defined as:
    /// x if x >= 0
    /// -x if x < 0
    /// 
    /// Example 1:
    /// Input: nums = [3,-1,-4,1,5]
    /// Output: [-1,1,3,-4,5]
    /// Explanation:
    /// The absolute values of elements in nums are 3, 1, 4, 1, 5 respectively.
    /// Rearranging them in increasing order, we get 1, 1, 3, 4, 5.
    /// This corresponds to [-1, 1, 3, -4, 5]. Another possible rearrangement 
    /// is [1, -1, 3, -4, 5].
    ///
    /// Example 2:
    /// Input: nums = [-100,100]
    /// Output: [-100,100]
    /// Explanation:
    /// The absolute values of elements in nums are 100, 100 respectively.
    /// Rearranging them in increasing order, we get 100, 100.
    /// This corresponds to [-100, 100]. Another possible rearrangement 
    /// is [100, -100].
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. -100 <= nums[i] <= 100
    /// </summary>
    vector<int> sortByAbsoluteValue(vector<int>& nums);

    /// <summary>
    /// Leet Code 3684. Maximize Sum of At Most K Distinct Elements
    ///
    /// Easy
    ///
    /// You are given a positive integer array nums and an integer k.
    ///
    /// Choose at most k elements from nums so that their sum is maximized. 
    /// However, the chosen numbers must be distinct.
    ///
    /// Return an array containing the chosen numbers in strictly descending order.
    /// 
    /// Example 1:
    /// Input: nums = [84,93,100,77,90], k = 3
    /// Output: [100,93,90]
    /// Explanation:
    /// The maximum sum is 283, which is attained by choosing 93, 100 and 90. We 
    /// rearrange them in strictly descending order as [100, 93, 90].
    ///
    /// Example 2:
    /// Input: nums = [84,93,100,77,93], k = 3
    /// Output: [100,93,84]
    /// Explanation:
    /// The maximum sum is 277, which is attained by choosing 84, 93 and 100. We 
    /// rearrange them in strictly descending order as [100, 93, 84]. We cannot 
    /// choose 93, 100 and 93 because the chosen numbers must be distinct.
    ///
    /// Example 3:
    /// Input: nums = [1,1,1,2,2,2], k = 6
    /// Output: [2,1]
    /// Explanation:
    /// The maximum sum is 3, which is attained by choosing 1 and 2. We rearrange 
    /// them in strictly descending order as [2, 1].
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= nums.length
    /// </summary>
    vector<int> maxKDistinct(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3711. Maximum Transactions Without Negative Balance
    ///
    /// Medium
    ///
    /// You are given an integer array transactions, where transactions[i] 
    /// represents the amount of the ith transaction:
    ///
    /// A positive value means money is received.
    /// A negative value means money is sent.
    /// The account starts with a balance of 0, and the balance must never become 
    /// negative. Transactions must be considered in the given order, but you are 
    /// allowed to skip some transactions.
    ///
    /// Return an integer denoting the maximum number of transactions that can 
    /// be performed without the balance ever going negative.
    ///
    /// Example 1:
    /// Input: transactions = [2,-5,3,-1,-2]
    /// Output: 4
    /// Explanation:
    /// One optimal sequence is [2, 3, -1, -2], balance: 0 -> 2 -> 5 -> 4 -> 2.
    ///
    /// Example 2:
    /// Input: transactions = [-1,-2,-3]
    /// Output: 0
    /// Explanation:
    /// All transactions are negative. Including any would make the balance 
    /// negative.
    ///
    /// Example 3:
    /// Input: transactions = [3,-2,3,-2,1,-1]
    /// Output: 6
    /// Explanation:
    /// All transactions can be taken in order, balance: 
    /// 0 -> 3 -> 1 -> 4 -> 2 -> 3 -> 2.
    ///
    /// Constraints:
    /// 1. 1 <= transactions.length <= 10^5
    /// 2. -10^9 <= transactions[i] <= 10^9
    /// </summary>
    int maxTransactions(vector<int>& transactions);

    /// <summary>
    /// Leet Code 3727. Maximum Alternating Sum of Squares
    ///
    /// Medium
    ///
    /// You are given an integer array nums. You may rearrange the elements in any 
    /// order.
    ///
    /// The alternating score of an array arr is defined as:
    ///
    /// score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
    /// Return an integer denoting the maximum possible alternating score of nums 
    /// after rearranging its elements.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3]
    /// Output: 12
    /// Explanation:
    ///
    /// A possible rearrangement for nums is [2,1,3], which gives the maximum 
    /// alternating score among all possible rearrangements.
    /// The alternating score is calculated as:
    /// score = 2^2 - 1^2 + 3^2 = 4 - 1 + 9 = 12
    ///
    /// Example 2:
    /// Input: nums = [1,-1,2,-2,3,-3]
    /// Output: 16
    /// Explanation:
    /// A possible rearrangement for nums is [-3,-1,-2,1,3,2], which gives the 
    /// maximum alternating score among all possible rearrangements.
    /// The alternating score is calculated as:
    ///
    /// score = (-3)^2 - (-1)^2 + (-2)^2 - (1)^2 + (3)^2 - (2)^2 
    /// = 9 - 1 + 4 - 1 + 9 - 4 = 16
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -4 * 10^4 <= nums[i] <= 4 * 10^4
    /// </summary>
    long long maxAlternatingSum(vector<int>& nums);

    /// <summary>
    /// Leet Code 3730. Maximum Calories Burnt from Jumps
    ///
    /// Medium
    ///
    /// You are given an integer array heights of size n, where heights[i] 
    /// represents the height of the ith block in an exercise routine.
    ///
    /// You start on the ground (height 0) and must jump onto each block 
    /// exactly once in any order.
    ///
    /// The calories burned for a jump from a block of height a to a 
    /// block of height b is (a - b)2.
    /// The calories burned for the first jump from the ground to the 
    /// chosen first block heights[i] is (0 - heights[i])^2.
    /// Return the maximum total calories you can burn by selecting an 
    /// optimal jumping sequence.
    /// Note: Once you jump onto the first block, you cannot return to 
    /// the ground.
    ///
    /// Example 1:
    /// Input: heights = [1,7,9]
    /// Output: 181
    /// Explanation: he optimal sequence is [9, 1, 7].
    ///
    /// Initial jump from the ground to heights[2] = 9: (0 - 9)^2 = 81.
    /// Next jump to heights[0] = 1: (9 - 1)^2 = 64.
    /// Final jump to heights[1] = 7: (1 - 7)^2 = 36.
    /// Total calories burned = 81 + 64 + 36 = 181.
    ///
    /// Example 2:
    /// Input: heights = [5,2,4]
    /// Output: 38
    /// Explanation:
    /// The optimal sequence is [5, 2, 4].
    /// Initial jump from the ground to heights[0] = 5: (0 - 5)^2 = 25.
    /// Next jump to heights[1] = 2: (5 - 2)^2 = 9.
    /// Final jump to heights[2] = 4: (2 - 4)^2 = 4.
    /// Total calories burned = 25 + 9 + 4 = 38.
    ///
    /// Example 3:
    /// Input: heights = [3,3]
    /// Output: 9
    /// Explanation:
    /// The optimal sequence is [3, 3].
    /// Initial jump from the ground to heights[0] = 3: (0 - 3)^2 = 9.
    /// Next jump to heights[1] = 3: (3 - 3)^2 = 0.
    /// Total calories burned = 9 + 0 = 9.
    /// 
    /// Constraints:
    /// 1. 1 <= n == heights.length <= 10^5
    /// 2. 1 <= heights[i] <= 10^5
    /// </summary>
    long long maxCaloriesBurnt(vector<int>& heights);

    /// <summary>
    /// Leet Code 3745. Maximize Expression of Three Elements 
    ///
    /// Easy
    ///
    /// You are given an integer array nums.
    /// Choose three elements a, b, and c from nums at distinct indices such that 
    /// the value of the expression a + b - c is maximized.
    ///
    /// Return an integer denoting the maximum possible value of this expression.
    ///
    /// Example 1:
    /// Input: nums = [1,4,2,5]
    /// Output: 8
    /// Explanation:
    /// We can choose a = 4, b = 5, and c = 1. The expression value is 
    /// 4 + 5 - 1 = 8, which is the maximum possible.
    ///
    /// Example 2:
    /// Input: nums = [-2,0,5,-2,4]
    /// Output: 11
    /// Explanation:
    /// We can choose a = 5, b = 4, and c = -2. The expression value is 
    /// 5 + 4 - (-2) = 11, which is the maximum possible.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 100
    /// 2. -100 <= nums[i] <= 100
    /// </summary>
    int maximizeExpressionOfThree(vector<int>& nums);

    /// <summary>
    /// Leet Code 3763. Maximum Total Sum with Threshold Constraints
    /// 
    /// Medium
    /// 
    /// You are given two integer arrays nums and threshold, both of length n.
    /// Starting at step = 1, you perform the following repeatedly :
    ///
    /// Choose an unused index i such that threshold[i] <= step.
    /// If no such index exists, the process ends.
    /// Add nums[i] to your running total.
    /// Mark index i as used and increment step by 1.
    /// Return the maximum total sum you can obtain by choosing indices 
    /// optimally.
    ///
    /// Example 1:
    /// Input: nums = [1, 10, 4, 2, 1, 6], threshold = [5, 1, 5, 5, 2, 2]
    ///
    /// Output : 17
    ///
    /// Explanation :
    /// At step = 1, choose i = 1 since threshold[1] <= step.The total sum 
    /// becomes 10. Mark index 1.
    /// At step = 2, choose i = 4 since threshold[4] <= step.The total sum 
    /// becomes 11. Mark index 4.
    /// At step = 3, choose i = 5 since threshold[5] <= step.The total sum 
    /// becomes 17. Mark index 5.
    /// At step = 4, we cannot choose indices 0, 2, or 3 because their 
    /// thresholds are > 4, so we end the process.
    ///
    /// Example 2:
    /// Input: nums = [4, 1, 5, 2, 3], threshold = [3, 3, 2, 3, 3]
    /// Output : 0
    /// Explanation :
    /// At step = 1 there is no index i with threshold[i] <= 1, so the 
    /// process ends immediately.Thus, the total sum is 0.
    ///
    /// Example 3 :
    /// Input : nums = [2, 6, 10, 13], threshold = [2, 1, 1, 1]
    /// Output : 31
    /// Explanation :
    /// At step = 1, choose i = 3 since threshold[3] <= step.The total sum 
    /// becomes 13. Mark index 3.
    /// At step = 2, choose i = 2 since threshold[2] <= step.The total sum
    /// becomes 23. Mark index 2.
    /// At step = 3, choose i = 1 since threshold[1] <= step.The total 
    /// sum becomes 29. Mark index 1.
    /// At step = 4, choose i = 0 since threshold[0] <= step.The total sum 
    /// becomes 31. Mark index 0.
    /// After step = 4 all indices have been chosen, so the process ends.
    ///
    /// Constraints:
    /// 1. n == nums.length == threshold.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums[i] <= 10^9
    /// 4. 1 <= threshold[i] <= n
    /// </summary>
    long long maxSum(vector<int>& nums, vector<int>& threshold);

    /// <summary>
    /// Leet Code 3759. Count Elements With at Least K Greater Values
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums of length n and an integer k.
    /// 
    /// An element in nums is said to be qualified if there exist at least 
    /// k elements in the array that are strictly greater than it.
    ///
    /// Return an integer denoting the total number of qualified elements 
    /// in nums.
    ///
    /// Example 1:
    /// Input: nums = [3, 1, 2], k = 1
    /// Output: 2
    /// Explanation:
    /// The elements 1 and 2 each have at least k = 1 element greater 
    /// than themselves.
    /// No element is greater than 3. Therefore, the answer is 2.
    ///
    /// Example 2 :
    /// Input : nums = [5, 5, 5], k = 2
    /// Output : 0
    /// Explanation :
    /// Since all elements are equal to 5, no element is greater than the 
    /// other.Therefore, the answer is 0.
    /// 
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 0 <= k < n
    /// </summary>
    int countElements(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3767. Maximize Points After Choosing K Tasks
    /// 
    /// Medium
    /// 
    /// You are given two integer arrays, technique1 and technique2, each of 
    /// length n, where n represents the number of tasks to complete.
    ///
    /// If the ith task is completed using technique 1, you earn technique1[i] 
    /// points.
    /// If it is completed using technique 2, you earn technique2[i] points.
    /// You are also given an integer k, representing the minimum number of 
    /// tasks that must be completed using technique 1.
    /// You must complete at least k tasks using technique 1 (they do not need 
    /// to be the first k tasks).
    ///
    /// The remaining tasks may be completed using either technique.
    /// Return an integer denoting the maximum total points you can earn.
    /// 
    /// Example 1:
    /// Input: technique1 = [5, 2, 10], technique2 = [10, 3, 8], k = 2
    /// Output : 22
    /// Explanation :
    /// We must complete at least k = 2 tasks using technique1.
    /// Choosing technique1[1] and technique1[2](completed using technique 1), 
    /// and technique2[0](completed using technique 2), yields the maximum 
    /// points : 2 + 10 + 10 = 22.
    ///
    /// Example 2 :
    /// Input : technique1 = [10, 20, 30], technique2 = [5, 15, 25], k = 2
    /// Output : 60
    /// Explanation :
    /// We must complete at least k = 2 tasks using technique1.
    /// Choosing all tasks using technique 1 yields the maximum points : 
    /// 10 + 20 + 30 = 60.
    ///
    /// Example 3 :
    /// Input : technique1 = [1, 2, 3], technique2 = [4, 5, 6], k = 0
    /// Output : 15
    /// Explanation :
    /// Since k = 0, we are not required to choose any task using technique1.
    /// Choosing all tasks using technique 2 yields the maximum points : 
    /// 4 + 5 + 6 = 15.
    ///
    /// Constraints:
    /// 1. 1 <= n == technique1.length == technique2.length <= 10^5
    /// 2. 1 <= technique1[i], technique2[i] <= 10^5
    /// 3. 0 <= k <= n
    /// </summary>
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k);

    /// <summary>
    /// Leet Code 3771. Total Score of Dungeon Runs
    /// 
    /// Medium
    /// 
    /// You are given a positive integer hp and two positive 1 - indexed 
    /// integer arrays damage and requirement.
    ///
    /// There is a dungeon with n trap rooms numbered from 1 to n.
    /// Entering room i reduces your health points by damage[i].After 
    /// that reduction, if your remaining health points are at least 
    /// requirement[i], you earn 1 point for that room.
    /// 
    /// Let score(j) be the number of points you get if you start with hp 
    /// health points and enter the rooms j, j + 1, ..., n in this order.
    ///
    /// Return the integer score(1) + score(2) + ... + score(n), the 
    /// sum of scores over all starting rooms.
    ///
    /// Note: You cannot skip rooms.You can finish your journey even if 
    /// your health points become non - positive.
    ///
    /// Example 1 :
    /// Input : hp = 11, damage = [3, 6, 7], requirement = [4, 2, 5]
    /// Output : 3
    /// Explanation :
    /// score(1) = 2, score(2) = 1, score(3) = 0. The total score 
    /// is 2 + 1 + 0 = 3.
    /// As an example, score(1) = 2 because you get 2 points if you start 
    /// from room 1.
    ///
    /// You start with 11 health points.
    /// Enter room 1. Your health points are now 11 - 3 = 8. You get 1 
    /// point because 8 >= 4.
    /// Enter room 2. Your health points are now 8 - 6 = 2. You get 1 
    /// point because 2 >= 2.
    /// Enter room 3. Your health points are now 2 - 7 = -5. You do 
    /// not get any points because - 5 < 5.
    ///
    /// Example 2:
    /// Input: hp = 2, damage = [10000, 1], requirement = [1, 1]
    /// Output : 1
    /// Explanation :
    /// score(1) = 0, score(2) = 1. The total score is 0 + 1 = 1.
    /// score(1) = 0 because you do not get any points if you start from 
    /// room 1.
    ///
    /// You start with 2 health points.
    /// Enter room 1. Your health points are now 2 - 10000 = -9998. 
    /// You do not get any points because - 9998 < 1.
    /// Enter room 2. Your health points are now - 9998 - 1 = -9999. 
    /// You do not get any points because - 9999 < 1.
    /// score(2) = 1 because you get 1 point if you start from room 2.
    /// 
    /// You start with 2 health points.
    /// Enter room 2. Your health points are now 2 - 1 = 1. You get 1 
    /// point because 1 >= 1.
    /// 
    /// Constraints:
    /// 1. 1 <= hp <= 10^9
    /// 2. 1 <= n == damage.length == requirement.length <= 10^5
    /// 3. 1 <= damage[i], requirement[i] <= 10^4
    /// </summary>
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement);

    /// <summary>
    /// Leet Code 3774. Absolute Difference Between Maximum and Minimum K 
    ///                 Elements
    /// 
    /// Easy
    /// 
    /// You are given an integer array nums and an integer k.
    /// Find the absolute difference between :
    /// the sum of the k largest elements in the array; and
    /// the sum of the k smallest elements in the array.
    /// Return an integer denoting this difference.
    ///
    /// Example 1:
    /// Input: nums = [5, 2, 2, 4], k = 2
    /// Output : 5
    /// Explanation :
    /// The k = 2 largest elements are 4 and 5. Their sum is 4 + 5 = 9.
    /// The k = 2 smallest elements are 2 and 2. Their sum is 2 + 2 = 4.
    /// The absolute difference is abs(9 - 4) = 5.
    ///
    /// Example 2 :
    /// Input : nums = [100], k = 1
    /// Output : 0
    /// Explanation :
    /// The largest element is 100.
    /// The smallest element is 100.
    /// The absolute difference is abs(100 - 100) = 0.
    ///
    /// Constraints :
    /// 1. 1 <= n == nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// 3. 1 <= k <= n
    /// </summary>
    int absDifference(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3781. Maximum Score After Binary Swaps 
    /// 
    /// Medium
    ///
    /// You are given an integer array nums of length n and a binary string 
    /// s of the same length.
    ///
    /// Initially, your score is 0. Each index i where s[i] = '1' contributes 
    /// nums[i] to the score.
    ///
    /// You may perform any number of operations(including zero).In one 
    /// operation, you may choose an index i such that 0 <= i < n - 1, where 
    /// s[i] = '0', and s[i + 1] = '1', and swap these two characters.
    ///
    /// Return an integer denoting the maximum possible score you can achieve.
    ///
    /// Example 1:
    /// Input: nums = [2, 1, 5, 2, 3], s = "01010"
    /// Output : 7
    /// Explanation :
    /// We can perform the following swaps :
    /// Swap at index i = 0 : "01010" changes to "10010"
    /// Swap at index i = 2 : "10010" changes to "10100"
    /// Positions 0 and 2 contain '1', contributing nums[0] + nums[2] = 
    /// 2 + 5 = 7. This is maximum score achievable.
    ///
    /// Example 2 :
    /// Input : nums = [4, 7, 2, 9], s = "0000"
    /// Output : 0
    /// Explanation :
    /// There are no '1' characters in s, so no swaps can be performed.
    /// The score remains 0.
    /// 
    /// Constraints:
    /// 1. n == nums.length == s.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums[i] <= 10^9
    /// 4. s[i] is either '0' or '1'
    /// </summary>
    long long maximumScore(vector<int>& nums, string s);

    /// <summary>
    /// Leet Code 3796. Find Maximum Value in a Constrained Sequence 
    /// 
    /// Medium
    ///
    /// You are given an integer n, a 2D integer array restrictions, and an 
    /// integer array diff of length n - 1. Your task is to construct a 
    /// sequence of length n, denoted by a[0], a[1], ..., a[n - 1], such that 
    /// it satisfies the following conditions :
    ///
    /// a[0] is 0.
    /// All elements in the sequence are non - negative.
    /// For every index i(0 <= i <= n - 2), abs(a[i] - a[i + 1]) <= diff[i].
    /// For each restrictions[i] = [idx, maxVal], the value at position idx 
    /// in the sequence must not exceed maxVal(i.e., a[idx] <= maxVal).
    /// Your goal is to construct a valid sequence that maximizes the largest 
    /// value within the sequence while satisfying all the above conditions.
    ///
    /// Return an integer denoting the largest value present in such an 
    /// optimal sequence.
    ///
    /// Example 1:
    /// Input: n = 10, restrictions = [[3, 1], [8, 1]], 
    /// diff = [2, 2, 3, 1, 4, 5, 1, 1, 2]
    /// Output : 6
    /// Explanation :
    /// The sequence a = [0, 2, 4, 1, 2, 6, 2, 1, 1, 3] satisfies the given 
    /// constraints(a[3] <= 1 and a[8] <= 1).
    /// The maximum value in the sequence is 6.
    ///
    /// Example 2 :
    /// Input : n = 8, restrictions = [[3, 2]], diff = [3, 5, 2, 4, 2, 3, 1]
    /// Output : 12
    /// Explanation :
    /// The sequence a = [0, 3, 3, 2, 6, 8, 11, 12] satisfies the given 
    /// constraints(a[3] <= 2).
    /// The maximum value in the sequence is 12.
    /// 
    /// Constraints :
    /// 1. 2 <= n <= 10^5
    /// 2. 1 <= restrictions.length <= n - 1
    /// 3. restrictions[i].length == 2
    /// 4. restrictions[i] = [idx, maxVal]
    /// 5. 1 <= idx < n
    /// 6. 1 <= maxVal <= 10^6
    /// 7. diff.length == n - 1
    /// 8. 1 <= diff[i] <= 10
    /// 9. The values of restrictions[i][0] are unique.
    /// </summary>
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff);

    /// <summary>
    /// Leet Code 3814. Maximum Capacity Within Budget 
    ///  
    /// Medium
    ///
    /// You are given two integer arrays costs and capacity, both of length n, 
    /// where costs[i] represents the purchase cost of the ith machine and 
    /// capacity[i] represents its performance capacity.
    ///
    /// You are also given an integer budget.
    /// You may select at most two distinct machines such that the total cost 
    /// of the selected machines is strictly less than budget.
    ///
    /// Return the maximum achievable total capacity of the selected machines.
    /// 
    /// Example 1:
    /// Input: costs = [4, 8, 5, 3], capacity = [1, 5, 2, 7], budget = 8
    /// Output : 8
    /// Explanation :
    /// Choose two machines with costs[0] = 4 and costs[3] = 3.
    /// The total cost is 4 + 3 = 7, which is strictly less 
    /// than budget = 8.
    /// The maximum total capacity is 
    /// capacity[0] + capacity[3] = 1 + 7 = 8.
    ///
    /// Example 2 :
    /// Input : costs = [3, 5, 7, 4], capacity = [2, 4, 3, 6], budget = 7
    /// Output : 6
    /// Explanation :
    /// Choose one machine with costs[3] = 4.
    /// The total cost is 4, which is strictly less than budget = 7.
    /// The maximum total capacity is capacity[3] = 6.
    ///
    /// Example 3 :
    /// Input : costs = [2, 2, 2], capacity = [3, 5, 4], budget = 5
    /// Output : 9
    /// Explanation :
    /// Choose two machines with costs[1] = 2 and costs[2] = 2.
    /// The total cost is 2 + 2 = 4, which is strictly less than budget = 5.
    /// The maximum total capacity is capacity[1] + capacity[2] = 5 + 4 = 9.
    ///
    /// Constraints :
    /// 1. 1 <= n == costs.length == capacity.length <= 10^5
    /// 2. 1 <= costs[i], capacity[i] <= 10^5
    /// 3. 1 <= budget <= 2 * 10^5
    /// </summary>
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget);


    /// <summary>
    /// Leet Code 3825. Longest Strictly Increasing Subsequence With 
    ///                 Non - Zero Bitwise AND 
    /// 
    /// Medium
    ///
    /// You are given an integer array nums.
    ///
    /// Return the length of the longest strictly increasing subsequence in 
    /// nums whose bitwise AND is non - zero.If no such subsequence exists, 
    /// return 0.
    ///
    /// Example 1:
    ///
    /// Input: nums = [5, 4, 7]
    /// Output : 2
    /// Explanation :
    /// 
    /// One longest strictly increasing subsequence is[5, 7].The bitwise AND 
    /// is 5 AND 7 = 5, which is non - zero.
    ///
    /// Example 2 :
    /// Input : nums = [2, 3, 6]
    /// Output : 3
    /// Explanation :
    /// The longest strictly increasing subsequence is[2, 3, 6].The bitwise 
    /// AND is 2 AND 3 AND 6 = 2, which is non - zero.
    ///
    /// Example 3 :
    /// Input : nums = [0, 1]
    /// Output : 1
    /// Explanation :
    /// One longest strictly increasing subsequence is[1].The bitwise 
    /// AND is 1, which is non - zero.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// </summary>
    int longestSubsequenceAndNonZero(vector<int>& nums);

    /// <summary>
    /// Leet Code 3828. Final Element After Subarray Deletions 
    /// 
    /// Medium
    ///
    /// You are given an integer array nums.
    ///
    /// Two players, Alice and Bob, play a game in turns, with Alice playing 
    /// first.
    ///
    /// In each turn, the current player chooses any subarray nums[l..r] such 
    /// that r - l + 1 < m, where m is the current length of the array.
    /// The selected subarray is removed, and the remaining elements are 
    /// concatenated to form the new array.
    /// The game continues until only one element remains.
    /// Alice aims to maximize the final element, while Bob aims to minimize 
    /// it.Assuming both play optimally, return the value of the final 
    /// remaining element.
    ///
    /// Example 1:
    /// Input: nums = [1, 5, 2]
    /// Output : 2
    /// Explanation :
    /// One valid optimal strategy :
    /// Alice removes[1], array becomes[5, 2].
    /// Bob removes[5], array becomes[2]. Thus, the answer is 2.
    ///
    /// Example 2 :
    /// Input : nums = [3, 7]
    /// Output : 7
    /// Explanation :
    /// Alice removes[3], leaving the array[7].Since Bob cannot play a turn 
    /// now, the answer is 7.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int finalElement(vector<int>& nums);
 
#pragma endregion
};
#endif  // LeetCodeSort_H
