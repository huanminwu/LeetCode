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
    /// Leet code #456. 132 Pattern
    /// Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence 
    /// ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes 
    /// a list of n numbers as input and checks whether there is a 132 pattern in the list.
    /// Note: n will be less than 15,000.    
    /// Example 1:
    /// Input: [1, 2, 3, 4]
    /// Output: False
    /// Explanation: There is no 132 pattern in the sequence.
    ///
    /// Example 2:
    /// Input: [3, 1, 4, 2]
    /// Output: True
    /// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
    /// Example 3:
    /// Input: [-1, 3, 2, 0]
    /// Output: True
    /// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
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
#pragma endregion
};
#endif  // LeetCodeSort_H
