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
};
#endif  // LeetCodeTwoPointer
