#pragma once
#ifndef LeetcodeTwoPointer_H
#define LeetCodeTwoPointer_H
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
/// The class is to implement two pointers  
/// </summary>
class LeetCodeTwoPointer
{
public:
    /// <summary>
    /// Leet code #881. Boats to Save People
    /// 
    /// The i-th person has weight people[i], and each boat can carry a maximum 
    /// weight of limit.
    ///
    /// Each boat carries at most 2 people at the same time, provided the sum of 
    /// the weight of those people is at most limit.
    ///
    /// Return the minimum number of boats to carry every given person.  (It is 
    /// guaranteed each person can be carried by a boat.)
    ///
    /// Example 1:
    ///
    /// Input: people = [1,2], limit = 3
    /// Output: 1
    /// Explanation: 1 boat (1, 2)
    ///
    /// Example 2:
    ///
    /// Input: people = [3,2,2,1], limit = 3
    /// Output: 3
    /// Explanation: 3 boats (1, 2), (2) and (3)
    ///
    /// Example 3:
    /// 
    /// Input: people = [3,5,3,4], limit = 5
    /// Output: 4
    /// Explanation: 4 boats (3), (3), (4), (5)
    /// Note:
    /// 
    /// 1. 1 <= people.length <= 50000
    /// 2. 1 <= people[i] <= limit <= 30000
    /// </summary>
    int numRescueBoats(vector<int>& people, int limit);

    /// <summary>
    /// Leet Code 1852. Distinct Numbers in Each Subarray
    ///                                                                 
    /// Medium
    ///
    /// Given an integer array nums and an integer k, you are asked to 
    /// construct the array ans of size n-k+1 where ans[i] is the number 
    /// of distinct numbers in the subarray nums[i:i+k-1] = [nums[i], 
    /// nums[i+1], ..., nums[i+k-1]].
    ///
    /// Return the array ans.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,2,2,1,3], k = 3
    /// Output: [3,2,2,2,3]
    /// Explanation: The number of distinct elements in each subarray goes 
    /// as follows:
    /// - nums[0:2] = [1,2,3] so ans[0] = 3
    /// - nums[1:3] = [2,3,2] so ans[1] = 2
    /// - nums[2:4] = [3,2,2] so ans[2] = 2
    /// - nums[3:5] = [2,2,1] so ans[3] = 2
    /// - nums[4:6] = [2,1,3] so ans[4] = 3
    ///
    /// Example 2:
    /// Input: nums = [1,1,1,1,2,3,4], k = 4
    /// Output: [1,2,3,4]
    /// Explanation: The number of distinct elements in each subarray goes 
    /// as follows:
    /// - nums[0:3] = [1,1,1,1] so ans[0] = 1
    /// - nums[1:4] = [1,1,1,2] so ans[1] = 2
    /// - nums[2:5] = [1,1,2,3] so ans[2] = 3
    /// - nums[3:6] = [1,2,3,4] so ans[3] = 4
    ///
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    vector<int> distinctNumbers(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2062. Count Vowel Substrings of a String
    ///                                                                 
    /// Easy
    ///
    /// A substring is a contiguous (non-empty) sequence of characters within 
    /// a string.
    ///
    /// A vowel substring is a substring that only consists of vowels 
    /// ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
    /// Given a string word, return the number of vowel substrings in word.
    ///
    /// Example 1:
    /// Input: word = "aeiouu"
    /// Output: 2
    /// Explanation: The vowel substrings of word are as follows (underlined):
    /// - "aeiouu"
    /// - "aeiouu"
    ///
    /// Example 2:
    /// Input: word = "unicornarihan"
    /// Output: 0
    /// Explanation: Not all 5 vowels are present, so there are no vowel 
    /// substrings.
    ///
    /// Example 3:
    /// Input: word = "cuaieuouac"
    /// Output: 7
    /// Explanation: The vowel substrings of word are as follows (underlined):
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    ///
    /// Example 4:
    /// Input: word = "bbaeixoubb"
    /// Output: 0
    /// Explanation: The only substrings that contain all five vowels also 
    /// contain 
    /// consonants, so there are no vowel substrings.
    /// 
    /// Constraints:
    /// 1. 1 <= word.length <= 100
    /// 2. word consists of lowercase English letters only.
    /// </summary>
    int countVowelSubstrings(string word);

    /// <summary>
    /// Leet Code 2106. Maximum Fruits Harvested After at Most K Steps
    ///                                                                 
    /// Hard
    ///
    /// Fruits are available at some positions on an infinite x-axis. You are 
    /// given a 2D integer array fruits where fruits[i] = [positioni, amounti] 
    /// depicts amounti fruits at the position positioni. fruits is already 
    /// sorted by positioni in ascending order, and each positioni is unique.
    ///
    /// You are also given an integer startPos and an integer k. Initially, 
    /// you are at the position startPos. From any position, you can either 
    /// walk to the left or right. It takes one step to move one unit on the 
    /// x-axis, and you can walk at most k steps in total. For every position 
    /// you reach, you harvest all the fruits at that position, and the 
    /// fruits will disappear from that position.
    ///
    /// Return the maximum total number of fruits you can harvest.
    /// 
    /// Example 1:
    /// Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
    /// Output: 9
    /// Explanation: 
    /// The optimal way is to:
    /// - Move right to position 6 and harvest 3 fruits
    /// - Move right to position 8 and harvest 6 fruits
    /// You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
    ///
    /// Example 2:
    /// Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], 
    /// startPos = 5, k = 4
    /// Output: 14
    /// Explanation: 
    /// You can move at most k = 4 steps, so you cannot reach position 0 
    /// nor 10.
    /// The optimal way is to:
    /// - Harvest the 7 fruits at the starting position 5
    /// - Move left to position 4 and harvest 1 fruit
    /// - Move right to position 6 and harvest 2 fruits
    /// - Move right to position 7 and harvest 4 fruits
    /// You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 
    /// fruits in total.
    ///
    /// Example 3:
    /// Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
    /// Output: 0
    /// Explanation:
    /// You can move at most k = 2 steps and cannot reach any position with 
    /// fruits.
    /// 
    /// Constraints:
    /// 1. 1 <= fruits.length <= 10^5
    /// 2. fruits[i].length == 2
    /// 3. 0 <= startPos, positioni <= 2 * 10^5
    /// 4. positioni-1 < positioni for any i > 0 (0-indexed)
    /// 5. 1 <= amounti <= 10^4
    /// 6. 0 <= k <= 2 * 10^5
    /// </summary>
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k);
};
#endif  // LeetCodeTwoPointer
