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
    /// between indices i and j (i ?ü j), inclusive.
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

#pragma endregion
};
#endif  // LeetCodeSort_H

