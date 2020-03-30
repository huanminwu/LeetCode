#pragma once
#ifndef LeetcodeHashtable_H
#define LeetCodeHashtable_H
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
using namespace std;
/// <summary>
/// The class is to implement dynamic programming  
/// </summary>
class LeetCodeHashtable
{
public:
    /// <summary>
    /// Leet code #1 Two Sum
    /// Given an array of integers, return indices of the two numbers such that they add up to 
    /// a specific target.
    /// You may assume that each input would have exactly one solution.
    /// Example:
    /// Given nums = [2, 7, 11, 15], target = 9,
    /// Because nums[0] + nums[1] = 2 + 7 = 9,
    /// return[0, 1]
    /// </summary>
    vector<int> twoSum(vector<int>& nums, int target);

    /// <summary>
    /// LeetCode #15. 3Sum
    /// Given an array S of n integers, are there elements a, b, c in S such 
    /// that a + b + c = 0? Find all unique triplets in the array which gives 
    /// the sum of zero.
    /// Note: The solution set must not contain duplicate triplets.
    /// For example, given array S = [-1, 0, 1, 1, 2, -1, -1, -4],
    /// A solution set is:
    /// [
    ///   [-1, 0, 1],
    ///   [-1, -1, 2]
    /// ]
    /// </summary>
    vector<vector<int>> threeSum(vector<int>& nums);

    /// <summary>
    /// LeetCode #15. 3Sum
    /// </summary>
    vector<vector<int>> threeSumII(vector<int>& nums);

    /// <summary>
    /// Leet code #454. 4Sum II  
    /// Given four lists A, B, C, D of integer values, compute how many 
    /// tuples (i, j, k, l) 
    /// there are such that A[i] + B[j] + C[k] + D[l] is zero.
    ///
    /// To make problem a bit easier, all A, B, C, D have same length of 
    /// N where 0 ¡Ü N ¡Ü 500. 
    /// All integers are in the range of -2^28 to 2^28 - 1 and the result 
    /// is guaranteed to be at most 2^31 - 1.	
    /// Example: 
    /// Input:
    /// A = [ 1, 2]
    /// B = [-2,-1]
    /// C = [-1, 2]
    /// D = [ 0, 2]
    ///
    /// Output:
    /// 2
    ///
    /// Explanation:
    /// The two tuples are:
    /// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
    /// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
    /// </summary>
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);

    /// <summary>
    /// Leet code #18. 4Sum 
    /// Given an array S of n integers, are there elements a, b, c, and d in S 
    /// such that a + b + c + d = target? 
    /// Find all unique quadruplets in the array which gives the sum of target.
    /// Note: The solution set must not contain duplicate quadruplets. 
    /// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
    ///
    /// A solution set is:
    /// [
    ///  [-1,  0, 0, 1],
    ///  [-2, -1, 1, 2],
    ///  [-2,  0, 0, 2]
    /// ]
    /// </summary>
    vector<vector<int>> fourSum(vector<int>& nums, int target);
 
    /// <summary>
    /// Leet code #18. 4Sum 
    /// </summary>
    vector<vector<int>> fourSumII(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1207. Unique Number of Occurrences
    ///
    /// Given an array of integers arr, write a function that returns 
    /// true if and only if the number of occurrences of each value in the 
    /// array is unique.
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: arr = [1,2,2,1,1,3]
    /// Output: true
    /// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No 
    /// two values have the same number of occurrences.
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,2]
    /// Output: false
    ///
    /// Example 3:
    ///
    /// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
    /// Output: true
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 1000
    /// 2. -1000 <= arr[i] <= 1000
    /// </summary>
    bool uniqueOccurrences(vector<int>& arr);

    /// <summary>
    /// Leet code #1218. Longest Arithmetic Subsequence of Given Difference
    /// 
    /// Given an integer array arr and an integer difference, return the length 
    /// of the longest subsequence in arr which is an arithmetic sequence such 
    /// that the difference between adjacent elements in the subsequence equals 
    /// difference.
    ///
    /// 
    /// Example 1:
    /// Input: arr = [1,2,3,4], difference = 1
    /// Output: 4
    /// Explanation: The longest arithmetic subsequence is [1,2,3,4].
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,3,5,7], difference = 1
    /// Output: 1
    /// Explanation: The longest arithmetic subsequence is any single element.
    ///
    /// Example 3:
    ///
    /// Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
    /// Output: 4
    /// Explanation: The longest arithmetic subsequence is [7,5,3,1].
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. -10^4 <= arr[i], difference <= 10^4
    /// </summary>
    int longestSubsequence(vector<int>& arr, int difference);

    /// <summary>
    /// Leet code #1224. Maximum Equal Frequency
    /// 
    /// Given an array nums of positive integers, return the longest possible 
    /// length of an array prefix of nums, such that it is possible to remove 
    /// exactly one element from this prefix so that every number that has 
    /// appeared in it will have the same number of occurrences.
    ///
    /// If after removing one element there are no remaining elements, it's 
    /// still considered that every appeared number has the same number of 
    /// ocurrences (0).
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: nums = [2,2,1,1,5,3,3,5]
    /// Output: 7
    /// Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we 
    /// remove nums[4]=5, we will get [2,2,1,1,3,3], so that each number 
    /// will appear exactly twice.
    ///
    /// Example 2:
    ///
    /// Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
    /// Output: 13
    ///
    /// Example 3:
    ///
    /// Input: nums = [1,1,1,2,2,2]
    /// Output: 5
    /// Example 4:
    ///
    /// Input: nums = [10,2,8,9,3,8,1,5,2,3,7,6]
    /// Output: 8
    /// 
    /// Constraints:
    /// 
    /// 1. 2 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int maxEqualFreq(vector<int>& nums);

    /// <summary>
    /// Leet code #1257. Smallest Common Region
    /// 
    /// You are given some lists of regions where the first region of each 
    /// list includes all other regions in that list.
    ///
    /// Naturally, if a region X contains another region Y then X is bigger 
    /// than Y.
    ///
    /// Given two regions region1, region2, find out the smallest region that 
    /// contains both of them.
    ///
    /// If you are given regions r1, r2 and r3 such that r1 includes r3, it 
    /// is guaranteed there is no r2 such that r2 includes r3.
    ///
    /// It's guaranteed the smallest region exists.
    ///
    /// Example 1:
    ///
    /// Input:
    /// regions = [["Earth","North America","South America"],
    /// ["North America","United States","Canada"],
    /// ["United States","New York","Boston"],
    /// ["Canada","Ontario","Quebec"],
    /// ["South America","Brazil"]],
    /// region1 = "Quebec",
    /// region2 = "New York"
    /// Output: "North America"
    ///
    /// Constraints:
    ///
    /// 1. 2 <= regions.length <= 10^4
    /// 2. region1 != region2
    /// 3. All strings consist of English letters and spaces with at 
    ///    most 20 letters.
    /// </summary>
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2);

    /// <summary>
    /// Leet code #1386. Cinema Seat Allocation
    /// 
    /// Medium
    ///
    /// A cinema has n rows of seats, numbered from 1 to n and there are ten 
    /// seats in each row, labelled from 1 to 10 as shown in the figure above.
    ///
    /// Given the array reservedSeats containing the numbers of seats already 
    /// reserved, for example, reservedSeats[i]=[3,8] means the seat located 
    /// in row 3 and labelled with 8 is already reserved. 
    ///
    /// Return the maximum number of four-person families you can allocate on 
    /// the cinema seats. A four-person family occupies fours seats in one 
    /// row, that are next to each other. Seats across an aisle (such 
    /// as [3,3] and [3,4]) are not considered to be next to each other, 
    /// however, It is permissible for the four-person family to be separated 
    /// by an aisle, but in that case, exactly two people have to sit on each 
    /// side of the aisle.
    ///
    /// Example 1:
    /// Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
    /// Output: 4
    /// Explanation: The figure above shows the optimal allocation for four 
    /// families, where seats mark with blue are already reserved and 
    /// contiguous seats mark with orange are for one family. 
    /// 
    /// Example 2:
    /// Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
    /// Output: 2
    ///
    /// Example 3:
    /// Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
    /// Output: 4
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^9
    /// 2. 1 <= reservedSeats.length <= min(10*n, 10^4)
    /// 3. reservedSeats[i].length == 2
    /// 4. 1 <= reservedSeats[i][0] <= n
    /// 5. 1 <= reservedSeats[i][1] <= 10
    /// 5. All reservedSeats[i] are distinct.
    /// </summary>
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats);

    /// <summary>
    /// Leet code #1394. Find Lucky Integer in an Array
    /// 
    /// Easy
    ///
    /// Given an array of integers arr, a lucky integer is an integer which 
    /// has a frequency in the array equal to its value.
    ///
    /// Return a lucky integer in the array. If there are multiple lucky 
    /// integers return the largest of them. If there is no lucky integer 
    /// return -1.
    /// 
    /// Example 1:
    /// Input: arr = [2,2,3,4]
    /// Output: 2
    /// Explanation: The only lucky number in the array is 2 because 
    /// frequency[2] == 2.
    ///
    /// Example 2:
    /// Input: arr = [1,2,2,3,3,3]
    /// Output: 3
    /// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of 
    /// them.
    ///
    /// Example 3:
    /// Input: arr = [2,2,2,3,3]
    /// Output: -1
    /// Explanation: There are no lucky numbers in the array.
    ///
    /// Example 4:
    /// Input: arr = [5]
    /// Output: -1
    /// Example 5:
    ///
    /// Input: arr = [7,7,7,7,7,7,7]
    /// Output: 7
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 500
    /// 2. 1 <= arr[i] <= 500
    /// </summary>
    int findLucky(vector<int>& arr);
};
#endif  // LeetCodeHashtable
