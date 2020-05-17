#pragma once
#ifndef LeetCodeArray_H
#define LeetCodeArray_H
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
class LeetCodeArray
{
public:
#pragma region Array

    /// <summary>
    /// Leet code #11. Container With Most Water 
    /// 
    /// Given n non-negative integers a1, a2, ..., an, where each represents 
    /// a point at coordinate (i, ai). n vertical lines are drawn such that 
    /// the two endpoints of line i is at (i, ai) and (i, 0). 
    /// Find two lines, which together with x-axis forms a container, such 
    /// that the container contains the most water. 
    /// Note: You may not slant the container. 
    /// </summary>
    int maxArea(vector<int>& height);

    /// <summary>
    /// Leet code #16. 3Sum Closest 
    /// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
    /// Return the sum of the three integers. You may assume that each input would have exactly one solution.
    /// For example, given array S = {-1 2 1 -4}, and target = 1.
    /// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    /// </summary>
    int threeSumClosest(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #42. Trapping Rain Water
    /// 
    /// Given n non-negative integers representing an elevation map where the 
    /// width of each bar is 1, compute how much water it is able to trap 
    /// after raining.
    /// For example, 
    /// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
    /// The above elevation map is represented by 
    /// array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water 
    /// (blue section) are being trapped. 
    /// Thanks Marcos for contributing this image!
    /// </summary>
    int trapWater(vector<int>& height);

    /// <summary>
    /// Leet code #27. Remove Element
    ///
    /// Given an array and a value, remove all instances of that value 
    /// in place and return the new length. 
    /// Do not allocate extra space for another array, you must do this 
    /// in place with constant memory.
    /// The order of elements can be changed. It doesn't matter what you 
    /// leave beyond the new length.
    /// Example:
    /// Given input array nums = [3,2,2,3], val = 3 
    /// Your function should return length = 2, with the first two elements 
    /// of nums being 2.	
    /// </summary> 
    int removeArrayElement(vector<int>& nums, int val);

    /// <summary>
    /// Leet code #283. Move Zeroes
    ///
    /// Given an array nums, write a function to move all 0's to the end 
    /// of it while maintaining the relative order of the non-zero elements.
    /// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].  
    /// Note:
    /// 1.You must do this in-place without making a copy of the array.
    /// 2.Minimize the total number of operations
    /// </summary>
    void moveZeroes(vector<int>& nums);

    /// <summary>
    /// Leet code #345. Reverse Vowels of a String 
    ///
    /// Write a function that takes a string as input and reverse only the vowels of a string.
    /// Example 1:
    /// Given s = "hello", return "holle". 
    /// Example 2:
    /// Given s = "leetcode", return "leotcede". 
    /// Note:
    /// The vowels does not include the letter "y". 
    /// </summary>
    string reverseVowels(string s);

    /// <summary>
    /// Leet code #167. Two Sum II - Input array is sorted
    ///
    /// Given an array of integers that is already sorted in ascending order, 
    /// find two numbers such that they add up to a specific target number.
    /// The function twoSum should return indices of the two numbers such that 
    /// they add up to the target, 
    /// where index1 must be less than index2. Please note that your returned 
    /// answers (both index1 and index2) are not zero-based.
    ///
    /// You may assume that each input would have exactly one solution. 
    /// Input: numbers={2, 7, 11, 15}, target=9
    ///
    /// Output: index1=1, index2=2 
    /// </summary>
    vector<int> twoSumII(vector<int>& numbers, int target);

    /// <summary>
    /// Leet code #209. Minimum Size Subarray Sum   
    /// 
    /// Medium
    ///
    /// Given an array of n positive integers and a positive integer s, find 
    /// the minimal length of a contiguous subarray of which the sum >= s. If 
    /// there isn't one, return 0 instead.
    ///
    /// Example: 
    /// Input: s = 7, nums = [2,3,1,2,4,3]
    /// Output: 2
    /// Explanation: the subarray [4,3] has the minimal length under the 
    /// problem constraint.
    /// Follow up:
    /// If you have figured out the O(n) solution, try coding another 
    /// solution of which the time complexity is O(n log n). 
    /// </summary>
    int minSubArrayLen(int s, vector<int>& nums);

    /// <summary>
    /// Leet code #228. Summary Ranges
    ///
    /// Given a sorted integer array without duplicates, return the summary 
    ///  of its ranges.
    /// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
    /// </summary>
    vector<string> summaryRanges(vector<int>& nums);

    /// <summary>
    /// Leet code #259. 3Sum Smaller  
    /// 
    /// Given an array of n integers nums and a target, find the number of index 
    /// triplets i, j, k with 0 <= i < j < k < n that satisfy the condition 
    /// nums[i] + nums[j] + nums[k] < target.
    /// For example, given nums = [-2, 0, 1, 3], and target = 2.
    /// Return 2. Because there are two triplets which sums are less than 2:
    /// [-2, 0, 1]
    /// [-2, 0, 3]
    /// Follow up:
    /// Could you solve it in O(n2) runtime? 
    /// </summary>
    int threeSumSmaller(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #487. Max Consecutive Ones II       
    /// 
    /// Given a binary array, find the maximum number of consecutive 1s in this 
    /// array if you can flip at most one 0.  
    /// Example 1: 
    /// Input: [1,0,1,1,0]
    ///
    /// Output: 4 
    /// Explanation: Flip the first zero will get the the maximum number of 
    /// consecutive 1s.
    /// After flipping, the maximum number of consecutive 1s is 4.
    ///	Note:
    /// The input array will only contain 0 and 1.
    /// The length of input array is a positive integer and will not exceed 10,000
    /// Follow up:
    /// What if the input numbers come in one by one as an infinite stream? In other words, 
    /// you can't store all numbers coming from the stream as it's too large to hold in memory. 
    /// Could you solve it efficiently? 
    /// </summary>
    int findMaxConsecutiveOnesII(vector<int>& nums);

    /// <summary>
    /// Leet code #544. Output Contest Matches 
    /// 
    /// During the NBA playoffs, we always arrange the rather strong team to 
    /// play with the rather weak team, like make the rank 1 team play with 
    /// the rank nth team, which is a good strategy to make the contest more 
    /// interesting. Now, you're given n teams, you need to output their final 
    /// contest matches in the form of a string.
    ///
    /// The n teams are given in the form of positive integers from 1 to n, 
    /// which represents their initial rank. (Rank 1 is the strongest team 
    /// and Rank n is the weakest team.) We'll use parentheses('(', ')') and 
    /// commas(',') to represent the contest team pairing - parentheses
    /// ('(' , ')') for pairing and commas(',') for partition. During the 
    /// pairing process in each round, you always need to follow the strategy 
    /// of making the rather strong one pair with the rather weak one.
    /// 
    /// Example 1:
    /// Input: 2
    /// Output: (1,2)
    /// Explanation: 
    /// Initially, we have the team 1 and the team 2, placed like: 1,2.
    /// Then we pair the team (1,2) together with '(', ')' and ',', which is 
    /// the final answer.
    /// Example 2:
    /// Input: 4
    /// Output: ((1,4),(2,3))
    /// Explanation: 
    /// In the first round, we pair the team 1 and 4, the team 2 and 3 
    /// together, as we need to make the strong team and weak team together.
    /// And we got (1,4),(2,3).
    /// In the second round, the winners of (1,4) and (2,3) need to play again 
    /// to generate the final winner, so you need to add the paratheses outside 
    /// them.
    /// And we got the final answer ((1,4),(2,3)).
    /// Example 3:
    /// Input: 8
    /// Output: (((1,8),(4,5)),((2,7),(3,6)))
    /// Explanation: 
    /// First round: (1,8),(2,7),(3,6),(4,5)
    /// Second round: ((1,8),(4,5)),((2,7),(3,6))
    /// Third round: (((1,8),(4,5)),((2,7),(3,6)))
    /// Since the third round will generate the final winner, you need to 
    /// output the answer (((1,8),(4,5)),((2,7),(3,6))).
    /// Note:
    /// The n is in range [2, 212].
    /// We ensure that the input n can be converted into the form 2^k, where k is a positive integer.
    /// </summary>
    string findContestMatch(int n);

    /// <summary>
    /// Leet code #680. Valid Palindrome II
    /// 
    /// Given a non-empty string s, you may delete at most one character. 
    /// Judge whether you can make it a palindrome.
    /// Example 1:
    /// Input: "aba"
    /// Output: True
    /// Example 2:
    /// Input: "abca"
    /// Output: True
    /// Explanation: You could delete the character 'c'.
    /// Note:
    /// The string will only contain lowercase characters a-z. The maximum 
    /// length of the string is 50000.
    /// </summary>
    bool validPalindrome(string s);

    /// <summary>
    /// Leet code #713. Subarray Product Less Than K
    /// Your are given an array of positive integers nums.
    /// 
    /// Count and print the number of (contiguous) subarrays where the product 
    /// of all the elements in the subarray is less than k.
    ///
    /// Example 1:
    /// Input: nums = [10, 5, 2, 6], k = 100
    /// Output: 8
    /// Explanation: The 8 subarrays that have product less than 100 are: 
    /// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
    /// Note that [10, 5, 2] is not included as the product of 100 is not 
    /// strictly less than k.
    /// Note:
    /// 
    /// 0 < nums.length <= 50000.
    /// 0 < nums[i] < 1000.
    /// 0 <= k < 10^6.
    /// </summary>
    int numSubarrayProductLessThanK(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #443. String Compression
    ///
    /// Given an array of characters, compress it in-place.
    ///
    /// The length after compression must always be smaller than or equal to 
    /// the original array.
    /// Every element of the array should be a character (not int) of length 1.
    /// After you are done modifying the input array in-place, return the new 
    /// length of the array.
    ///
    /// Follow up:
    /// Could you solve it using only O(1) extra space?
    ///
    /// Example 1:
    /// Input:
    /// ["a","a","b","b","c","c","c"]
    /// Output:
    /// Return 6, and the first 6 characters of the input array should be: 
    /// ["a","2","b","2","c","3"]
    ///
    /// Explanation:
    /// "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced 
    /// by "c3".
    ///
    /// Example 2:
    /// Input:
    /// ["a"]
    /// Output:
    /// Return 1, and the first 1 characters of the input array should be: 
    /// ["a"]
    ///
    /// Explanation:
    /// Nothing is replaced.
    /// Example 3:
    /// Input:
    /// ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    ///
    /// Output:
    /// Return 4, and the first 4 characters of the input array should be: 
    /// ["a","b","1","2"].
    ///
    /// Explanation:
    /// Since the character "a" does not repeat, it is not compressed. 
    /// "bbbbbbbbbbbb" is replaced by "b12".
    /// Notice each digit has it's own entry in the array.
    /// Note:
    /// All characters have an ASCII value in [35, 126].
    /// 1 <= len(chars) <= 1000.
    /// </summary>
    int compress(vector<char>& chars);

    /// <summary>
    /// Leet code #755. Pour Water    
    /// We are given an elevation map, heights[i] representing the height of the 
    /// terrain at that index. The width at each index is 1. After V units of 
    /// water fall at index K, how much water is at each index?
    ///
    /// Water first drops at index K and rests on top of the highest terrain or 
    /// water at that index. Then, it flows according to the following rules:
    ///
    /// If the droplet would eventually fall by moving left, then move left.
    /// Otherwise, if the droplet would eventually fall by moving right, then 
    /// move right.
    /// Otherwise, rise at it's current position.
    /// Here, "eventually fall" means that the droplet will eventually be at a 
    /// lower level if it moves in that direction. Also, "level" means the height 
    /// of the terrain plus any water in that column.
    /// We can assume there's infinitely high terrain on the two sides out of 
    /// bounds of the array. Also, there could not be partial water being spread 
    /// out evenly on more than 1 grid block - each unit of water has to be in 
    /// exactly one block.
    ///
    /// Example 1:
    /// Input: heights = [2,1,1,2,1,2,2], V = 4, K = 3
    /// Output: [2,2,2,3,2,2,2]
    /// Explanation:
    /// #       #
    /// #       #
    /// ##  # ###
    /// #########
    ///  0123456    <- index
    ///
    /// The first drop of water lands at index K = 3:
    /// 
    /// #       #
    /// #   w   #
    /// ##  # ###
    /// #########
    ///  0123456    
    /// 
    /// When moving left or right, the water can only move to the same level or a 
    /// lower level.
    /// (By level, we mean the total height of the terrain plus any water in that 
    /// column.)
    /// Since moving left will eventually make it fall, it moves left.
    /// (A droplet "made to fall" means go to a lower height than it was at 
    /// previously.)
    ///
    /// #       #
    /// #       #
    /// ## w# ###
    /// #########
    ///  0123456    
    ///
    /// Since moving left will not make it fall, it stays in place.  The next 
    /// droplet falls:
    ///
    /// #       #
    /// #   w   #
    /// ## w# ###
    /// #########
    ///  0123456  
    ///
    /// Since the new droplet moving left will eventually make it fall, it moves 
    /// left.
    /// Notice that the droplet still preferred to move left,
    /// even though it could move right (and moving right makes it fall quicker.)
    /// 
    /// #       #
    /// #  w    #
    /// ## w# ###
    /// #########
    /// 0123456  
    ///
    /// #       #
    /// #       #
    /// ##ww# ###
    /// #########
    ///  0123456  
    ///
    /// After those steps, the third droplet falls.
    /// Since moving left would not eventually make it fall, it tries to move 
    /// right.
    /// Since moving right would eventually make it fall, it moves right.
    ///
    /// #       #
    /// #   w   #
    /// ##ww# ###
    /// #########
    ///  0123456  
    /// 
    /// #       #
    /// #       #
    /// ##ww#w###
    /// #########
    ///  0123456  
    /// 
    /// Finally, the fourth droplet falls.
    /// Since moving left would not eventually make it fall, it tries to move 
    /// right.
    /// Since moving right would not eventually make it fall, it stays in place:
    /// 
    /// #       #
    /// #   w   #
    /// ##ww#w###
    /// #########
    ///  0123456  
    ///
    /// The final answer is [2,2,2,3,2,2,2]:
    ///
    ///    #    
    /// ####### 
    /// ####### 
    ///  0123456 
    /// Example 2:
    /// Input: heights = [1,2,3,4], V = 2, K = 2
    /// Output: [2,3,3,4]
    /// Explanation:
    /// The last droplet settles at index 1, since moving further left would not 
    /// cause it to eventually fall to a lower height.
    /// Example 3:
    /// Input: heights = [3,1,3], V = 5, K = 1
    /// Output: [4,4,4]
    /// Note:
    ///
    /// heights will have length in [1, 100] and contain integers in [0, 99].
    /// 1. V will be in range [0, 2000].
    /// 2. K will be in range [0, heights.length - 1].
    /// </summary>
    vector<int> pourWater(vector<int>& heights, int V, int K);

    /// <summary>
    /// Leet code #904. Fruit Into Baskets
    /// 
    /// In a row of trees, the i-th tree produces fruit with type tree[i].
    ///
    /// You start at any tree of your choice, then repeatedly perform the 
    /// following steps:
    ///
    /// 1. Add one piece of fruit from this tree to your baskets.  If you cannot, 
    /// stop.
    /// 2. Move to the next tree to the right of the current tree.  If there is no 
    /// tree to the right, stop.
    /// Note that you do not have any choice after the initial choice of starting 
    /// tree: you must perform step 1, then step 2, then back to step 1, then 
    /// step 2, and so on until you stop.
    ///
    /// You have two baskets, and each basket can carry any quantity of fruit, but 
    /// you want each basket to only carry one type of fruit each.
    ///
    /// What is the total amount of fruit you can collect with this procedure?
    ///
    /// Example 1:
    /// Input: [1,2,1]
    /// Output: 3
    /// Explanation: We can collect [1,2,1].
    ///
    /// Example 2:
    /// Input: [0,1,2,2]
    /// Output: 3
    /// Explanation: We can collect [1,2,2].
    /// If we started at the first tree, we would only collect [0, 1].
    ///
    /// Example 3:
    /// Input: [1,2,3,2,2]
    /// Output: 4
    /// Explanation: We can collect [2,3,2,2].
    /// If we started at the first tree, we would only collect [1, 2].
    ///
    /// Example 4:
    /// Input: [3,3,3,1,2,1,1,2,3,3,4]
    /// Output: 5
    /// Explanation: We can collect [1,2,1,1,2].
    /// If we started at the first tree or the eighth tree, we would only collect 
    /// 4 fruits.
    /// 
    /// Note:
    ///
    /// 1. 1 <= tree.length <= 40000
    /// 2. 0 <= tree[i] < tree.length
    /// </summary>
    int totalFruit(vector<int>& tree);

    /// <summary>
    /// Leet code #917. Reverse Only Letters
    /// 
    /// Given a string S, return the "reversed" string where all characters that 
    /// are not a letter stay in the same place, and all letters reverse their 
    /// positions.
    ///
    /// Example 1:
    ///
    /// Input: "ab-cd"
    /// Output: "dc-ba"g
    ///
    /// Input: "a-bC-dEf-ghIj"
    /// Output: "j-Ih-gfE-dCba"
    ///
    /// Example 3:
    /// Input: "Test1ng-Leet=code-Q!"
    /// Output: "Qedo1ct-eeLg=ntse-T!"
    ///  
    /// Note:
    /// 
    /// 1. S.length <= 100
    /// 2. 33 <= S[i].ASCIIcode <= 122 
    /// 3. S doesn't contain \ or "
    /// </summary>
    string reverseOnlyLetters(string S);

    /// <summary>
    /// Leet code #915. Partition Array into Disjoint Intervals
    /// 
    /// Given an array A, partition it into two (contiguous) subarrays left and 
    /// right so that:
    ///
    /// Every element in left is less than or equal to every element in right.
    /// left and right are non-empty.
    /// left has the smallest possible size.
    /// Return the length of left after such a partitioning.  It is guaranteed 
    /// that such a partitioning exists.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: [5,0,3,8,6]
    /// Output: 3
    /// Explanation: left = [5,0,3], right = [8,6]
    ///
    /// Example 2:
    ///
    /// Input: [1,1,1,0,6,12]
    /// Output: 4
    /// Explanation: left = [1,1,1,0], right = [6,12]
    /// 
    ///
    /// Note:
    ///
    /// 2 <= A.length <= 30000
    /// 0 <= A[i] <= 10^6
    /// It is guaranteed there is at least one way to partition A as described.
    /// </summary>
    int partitionDisjoint(vector<int>& A);

    /// <summary>
    /// Leet code #1100. Find K-Length Substrings With No Repeated Characters
    /// 
    /// Given a string S, return the number of substrings of length K with no 
    /// repeated characters.
    /// 
    /// Example 1:
    /// Input: S = "havefunonleetcode", K = 5
    /// Output: 6
    /// Explanation: 
    /// There are 6 substrings they are : 'havef','avefu','vefun','efuno',
    /// 'etcod','tcode'.
    ///
    /// Example 2:
    /// Input: S = "home", K = 5
    /// Output: 0
    /// Explanation: 
    /// Notice K can be larger than the length of S. In this case is not 
    /// possible to find any substring.
    /// 
    /// Note:
    /// 1 <= S.length <= 10^4
    /// 2. All characters of S are lowercase English letters.
    /// 3. 1 <= K <= 10^4
    /// </summary>
    int numKLenSubstrNoRepeats(string S, int K);

    /// <summary>
    /// Leet code #1150. Check If a Number Is Majority Element in a Sorted Array
    /// 
    /// Given an array nums sorted in non-decreasing order, and a number target, 
    /// return True if and only if target is a majority element.
    /// A majority element is an element that appears more than N/2 times in an 
    /// array of length N.
    /// 
    /// Example 1:
    /// Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
    /// Output: true
    /// Explanation: 
    /// The value 5 appears 5 times and the length of the array is 9.
    /// Thus, 5 is a majority element because 5 > 9/2 is true.
    ///
    /// Example 2:
    /// Input: nums = [10,100,101,101], target = 101
    /// Output: false
    /// Explanation: 
    /// The value 101 appears 2 times and the length of the array is 4.
    /// Thus, 101 is not a majority element because 2 > 4/2 is false.
    /// 
    /// Note:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= target <= 10^9
    /// </summary>
    bool isMajorityElement(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1156. Swap For Longest Repeated Character Substring
    /// 
    /// Given a string text, we are allowed to swap two of the characters in the 
    /// string. Find the length of the longest substring with repeated characters.
    /// 
    /// Example 1:
    /// Input: text = "ababa"
    /// Output: 3
    /// Explanation: We can swap the first 'b' with the last 'a', or the last 'b' 
    /// with the first 'a'. Then, the longest repeated character substring is 
    /// "aaa", which its length is 3.
    ///
    /// Example 2:
    /// Input: text = "aaabaaa"
    /// Output: 6
    /// Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get 
    /// longest repeated character substring "aaaaaa", which its length is 6.
    ///
    /// Example 3:
    /// Input: text = "aaabbaaa"
    /// Output: 4
    ///
    /// Example 4:
    /// Input: text = "aaaaa"
    /// Output: 5
    /// Explanation: No need to swap, longest repeated character substring is 
    /// "aaaaa", length is 5.
    ///
    /// Example 5:
    /// Input: text = "abcdef"
    /// Output: 1
    /// 
    /// Constraints:
    /// 1. 1 <= text.length <= 20000
    /// 2. text consist of lowercase English characters only.
    /// </summary>
    int maxRepOpt1(string text);

    /// <summary>
    /// Leet code #1180. Count Substrings with Only One Distinct Letter
    /// 
    /// Given a string S, return the number of substrings that have only one 
    /// distinct letter.
    /// 
    /// Example 1:
    /// Input: S = "aaaba"
    /// Output: 8
    /// Explanation: The substrings with one distinct letter are 
    /// "aaa", "aa", "a", "b".
    /// "aaa" occurs 1 time.
    /// "aa" occurs 2 times.
    /// "a" occurs 4 times.
    /// "b" occurs 1 time.
    /// So the answer is 1 + 2 + 4 + 1 = 8.
    ///
    /// Example 2:
    /// Input: S = "aaaaaaaaaa"
    /// Output: 55
    /// 
    /// Constraints:
    /// 1. 1 <= S.length <= 1000
    /// 2. S[i] consists of only lowercase English letters.
    /// </summary>
    int countLetters(string S);

    /// <summary>
    /// Leet code #364. Nested List Weight Sum II   
    /// </summary>
    int countDepth(vector<NestedInteger>& nestedList);

    /// <summary>
    /// Leet code #364. Nested List Weight Sum II   
    /// </summary>
    int depthSumInverse(vector<NestedInteger>& nestedList, int depth);

    /// <summary>
    /// Leet code #364. Nested List Weight Sum II  
    /// 
    /// Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
    /// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
    /// Different from the previous question where weight is increasing from root to leaf, now the weight is 
    /// defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
    /// Example 1:
    /// Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
    /// Example 2:
    /// Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27) 
    /// </summary>
    int depthSumInverse(vector<NestedInteger>& nestedList);

    /// <summary>
    /// Leet code #1198. Find Smallest Common Element in All Rows
    /// 
    /// Given a matrix mat where every row is sorted in increasing order, return 
    /// the smallest common element in all rows.
    ///
    /// If there is no common element, return -1.
    ///
    /// Example 1:
    ///
    /// Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
    /// Output: 5
    /// 
    ///
    /// Constraints:
    ///
    /// 1. 1 <= mat.length, mat[i].length <= 500
    /// 2. 1 <= mat[i][j] <= 10^4
    /// 3. mat[i] is sorted in increasing order.
    /// </summary>
    int smallestCommonElement(vector<vector<int>>& mat);

    /// <summary>
    /// Leet code #289. Game of Life 
    ///
    /// According to the Wikipedia's article: "The Game of Life, also known 
    /// simply as Life, is a cellular automaton devised by the British 
    /// mathematician John Horton Conway in 1970." 
    /// Given a board with m by n cells, each cell has an initial state 
    /// live (1) or dead (0). 
    /// Each cell interacts with its eight neighbors (horizontal, vertical, 
    /// diagonal) using the 
    /// following four rules (taken from the above Wikipedia article): 	
    /// 1.Any live cell with fewer than two live neighbors dies, as if caused 
    ///   by under-population.
    /// 2.Any live cell with two or three live neighbors lives on to the next 
    ///   generation.
    /// 3.Any live cell with more than three live neighbors dies, as if by 
    ///   over-population..
    /// 4.Any dead cell with exactly three live neighbors becomes a live cell, 
    ///   as if by reproduction.
    /// Write a function to compute the next state (after one update) of the 
    /// board given its current state.
    /// Follow up: 
    /// 1.Could you solve it in-place? Remember that the board needs to be 
    ///   updated at the same time: You cannot update some cells first and 
    ///   then use their updated values to update other cells.
    /// 2.In this question, we represent the board using a 2D array. In 
    ///   principle, the board is infinite, which would cause problems when 
    ///   the active area encroaches the border of the array. How would you 
    ///   address these problems?
    /// </summary>
    void gameOfLife(vector<vector<int>>& board);

    /// <summary>
    /// Leet code #1208. Get Equal Substrings Within Budget
    ///
    /// You are given two strings s and t of the same length. You want to change
    /// s to t. Changing the i-th character of s to i-th character of t costs 
    /// |s[i] - t[i]| that is, the absolute difference between the ASCII values 
    /// of the characters.
    ///
    /// You are also given an integer maxCost.
    ///
    /// Return the maximum length of a substring of s that can be changed to be 
    /// the same as the corresponding substring of twith a cost less than or equal 
    /// to maxCost.
    ///
    /// If there is no substring from s that can be changed to its corresponding 
    /// substring from t, return 0.
    ///
    /// Example 1:
    ///
    /// Input: s = "abcd", t = "bcdf", maxCost = 3
    /// Output: 3
    /// Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum 
    /// length is 3.
    ///
    /// Example 2:
    /// 
    /// Input: s = "abcd", t = "cdef", maxCost = 3
    /// Output: 1
    /// Explanation: Each character in s costs 2 to change to charactor in t, so 
    /// the maximum length is 1.
    ///
    /// Example 3:
    ///
    /// Input: s = "abcd", t = "acde", maxCost = 0
    /// Output: 1
    /// Explanation: You can't make any change, so the maximum length is 1.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length, t.length <= 10^5
    /// 2. 0 <= maxCost <= 10^6
    /// 3. s and t only contain lower case English letters.
    /// </summary>
    int equalSubstring(string s, string t, int maxCost);

    /// <summary>
    /// Leet code #1221. Split a String in Balanced Strings
    /// 
    /// Balanced strings are those who have equal quantity of 'L' and 'R' 
    /// characters.
    ///
    /// Given a balanced string s split it in the maximum amount of balanced 
    /// strings.
    ///
    /// Return the maximum amount of splitted balanced strings.
    ///
    /// Example 1:
    ///
    /// Input: s = "RLRRLLRLRL"
    /// Output: 4
    /// Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring 
    /// contains same number of 'L' and 'R'.
    ///
    /// Example 2:
    ///
    /// Input: s = "RLLLLRRRLR"
    /// Output: 3
    /// Explanation: s can be split into "RL", "LLLRRR", "LR", each substring 
    /// contains same number of 'L' and 'R'.
    ///
    /// Example 3:
    ///
    /// Input: s = "LLLLRRRR"
    /// Output: 1
    /// Explanation: s can be split into "LLLLRRRR".
    ///  
    /// Constraints:
    /// 
    /// 1. 1 <= s.length <= 1000
    /// 2. s[i] = 'L' or 'R'
    /// </summary>
    int balancedStringSplit(string s);

    /// <summary>
    /// Leet code #1222. Queens That Can Attack the King
    /// 
    /// On an 8x8 chessboard, there can be multiple Black Queens and one 
    /// White King.
    ///
    /// Given an array of integer coordinates queens that represents the 
    /// positions of the Black Queens, and a pair of coordinates king that 
    /// represent the position of the White King, return the coordinates 
    /// of all the queens (in any order) that can attack the King.
    ///
    /// 
    /// Example 1:
    /// 
    /// Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
    /// Output: [[0,1],[1,0],[3,3]]
    /// Explanation:  
    /// The queen at [0,1] can attack the king cause they're in the same row. 
    /// The queen at [1,0] can attack the king cause they're in the same column. 
    /// The queen at [3,3] can attack the king cause they're in the same diagnal.
    /// The queen at [0,4] can't attack the king cause it's blocked by the 
    /// queen at [0,1]. 
    /// The queen at [4,0] can't attack the king cause it's blocked by the 
    /// queen at [1,0]. 
    /// The queen at [2,4] can't attack the king cause it's not in the same 
    /// row/column/diagnal as the king.
    ///
    /// Example 2:
    /// Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
    /// Output: [[2,2],[3,4],[4,4]]
    ///
    /// Example 3:
    /// Input: queens = 
    /// [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],
    /// [0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],
    /// [0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
    /// Output: [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
    /// 
    /// Constraints:
    /// 1. 1 <= queens.length <= 63
    /// 2. queens[0].length == 2
    /// 3. 0 <= queens[i][j] < 8
    /// 4. king.length == 2
    /// 5. 0 <= king[0], king[1] < 8
    /// 6. At most one piece is allowed in a cell.
    /// </summary>
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king);

    /// <summary>
    /// Leet code #1228. Missing Number In Arithmetic Progression
    /// 
    /// In some array arr, the values were in arithmetic progression: the 
    /// values arr[i+1] - arr[i] are all equal for every 
    /// 0 <= i < arr.length - 1.
    ///
    /// Then, a value from arr was removed that was not the first or last 
    /// value in the array.
    ///
    /// Return the removed value.
    ///
    /// Example 1:
    ///
    /// Input: arr = [5,7,11,13]
    /// Output: 9
    /// Explanation: The previous array was [5,7,9,11,13].
    ///
    /// Example 2:
    /// Input: arr = [15,13,12]
    /// Output: 14
    /// Explanation: The previous array was [15,14,13,12].
    ///
    /// Constraints:
    /// 1. 3 <= arr.length <= 1000
    /// 2. 0 <= arr[i] <= 10^5
    /// </summary>
    int missingNumber(vector<int>& arr);

    /// <summary>
    /// Leet code #53. Maximum Subarray
    /// 
    /// Given an integer array nums, find the contiguous subarray (containing 
    /// at least one number) which has the largest sum and return its sum.
    ///
    /// Example:
    ///
    /// Input: [-2,1,-3,4,-1,2,1,-5,4],
    /// Output: 6
    /// Explanation: [4,-1,2,1] has the largest sum = 6.
    ///
    /// Follow up:
    /// If you have figured out the O(n) solution, try coding another solution 
    /// using the divide and conquer approach, which is more subtle.
    /// </summary>
    int maxSubArray(vector<int>& nums);

    /// <summary>
    /// Leet code #134. Gas Station
    /// 
    /// There are N gas stations along a circular route, where the amount of gas 
    /// at station i is gas[i].
    ///
    /// You have a car with an unlimited gas tank and it costs cost[i] of gas to 
    /// travel from station i to its next station (i+1). You begin the journey 
    /// with an empty tank at one of the gas stations.
    ///
    /// Return the starting gas station's index if you can travel around the 
    /// circuit once in the clockwise direction, otherwise return -1.
    ///
    /// Note:
    ///
    /// If there exists a solution, it is guaranteed to be unique.
    /// Both input arrays are non-empty and have the same length.
    /// Each element in the input arrays is a non-negative integer.
    ///
    /// Example 1:
    /// Input: 
    /// gas  = [1,2,3,4,5]
    /// cost = [3,4,5,1,2]
    /// Output: 3
    ///
    /// Explanation:
    /// 1. Start at station 3 (index 3) and fill up with 4 unit of gas. 
    ///    Your tank = 0 + 4 = 4
    /// 2. Travel to station 4. Your tank = 4 - 1 + 5 = 8
    /// 3. Travel to station 0. Your tank = 8 - 2 + 1 = 7
    /// 4. Travel to station 1. Your tank = 7 - 3 + 2 = 6
    /// 5. Travel to station 2. Your tank = 6 - 4 + 3 = 5
    /// 6. Travel to station 3. The cost is 5. Your gas is just enough to travel 
    ///    back to station 3.
    /// 7. Therefore, return 3 as the starting index.
    ///
    /// Example 2:
    /// Input: 
    /// gas  = [2,3,4]
    /// cost = [3,4,3]
    /// Output: -1
    /// 
    /// Explanation:
    /// 1. You can't start at station 0 or 1, as there is not enough gas to travel 
    ///    to the next station.
    /// 2. Let's start at station 2 and fill up with 4 unit of gas. Your 
    ///    tank = 0 + 4 = 4
    /// 3. Travel to station 0. Your tank = 4 - 3 + 2 = 3
    /// 4. Travel to station 1. Your tank = 3 - 3 + 3 = 3
    /// 5. You cannot travel back to station 2, as it requires 4 unit of gas but 
    ///    you only have 3.
    /// 6. Therefore, you can't travel around the circuit once no matter where 
    ///    you start.
    /// </summary>
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

    /// <summary>
    /// Leet code #152. Maximum Product Subarray
    /// 
    /// Given an integer array nums, find the contiguous subarray within an array 
    /// (containing at least one number) which has the largest product.
    ///
    /// Example 1:
    ///
    /// Input: [2,3,-2,4]
    /// Output: 6
    /// Explanation: [2,3] has the largest product 6.
    ///
    /// Example 2:
    ///
    /// Input: [-2,0,-1]
    /// Output: 0
    /// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
    /// </summary>
    int maxProduct(vector<int>& nums);

    /// <summary>
    /// Leet code #325. Maximum Size Subarray Sum Equals k
    /// 
    /// Given an array nums and a target value k, find the maximum length of a subarray that sums to k. 
    /// If there isn't one, return 0 instead. 
    /// Note:
    /// The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range. 
    ///
    /// Example 1:
    /// Given nums = [1, -1, 5, -2, 3], k = 3,
    /// return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest) 
    ///
    /// Example 2:
    /// Given nums = [-2, -1, 2, 1], k = 1,
    /// return 2. (because the subarray [-1, 2] sums to 1 and is the longest) 
    ///
    /// Follow Up:
    /// Can you do it in O(n) time? 
    /// </summary>
    int maxSubArrayLen(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #523. Continuous Subarray Sum   
    /// 
    /// Given a list of non-negative numbers and a target integer k, write a 
    /// function to check if the array has a continuous subarray of size at 
    /// least 2 that sums up to the multiple of k, that is, sums up to n*k 
    /// where n is also an integer.
    ///
    /// Example 1:
    /// Input: [23, 2, 4, 6, 7],  k=6
    /// Output: True
    /// Explanation: Because [2, 4] is a continuous subarray of size 2 and 
    /// sums up to 6.
    /// Example 2:
    /// Input: [23, 2, 6, 4, 7],  k=42
    /// Output: True
    /// Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of 
    /// size 5 and sums up to 42.
    /// Note:
    /// The length of the array won't exceed 10,000.
    /// You may assume the sum of all the numbers is in the range of a 
    /// signed 32-bit integer.
    /// </summary>
    bool checkSubarraySum(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #525. Contiguous Array    
    /// 
    /// Given a binary array, find the maximum length of a contiguous subarray 
    /// with equal number of 0 and 1. 
    /// Example 1:
    /// Input: [0,1]
    /// Output: 2
    /// Explanation: [0, 1] is the longest contiguous subarray with equal 
    /// number of 0 and 1.
    ///
    /// Example 2:
    /// Input: [0,1,0]
    /// Output: 2
    /// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with 
    /// equal number of 0 and 1.
    /// Note: The length of the given binary array will not exceed 50,000. 
    /// </summary>
    int findMaxLength(vector<int>& nums);

    /// <summary>
    /// Leet code #560. Subarray Sum Equals K
    /// Given an array of integers and an integer k, you need to find the 
    /// total number of continuous subarrays whose sum equals to k.
    /// Example 1:
    /// Input:nums = [1,1,1], k = 2 
    /// Output: 2
    ///
    /// Note:
    /// The length of the array is in range [1, 20,000].
    /// The range of numbers in the array is [-1000, 1000] and the range of 
    /// the integer k is [-1e7, 1e7].
    /// </summary>
    int subarraySum(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #930. Binary Subarrays With Sum
    /// 
    /// In an array A of 0s and 1s, how many non-empty subarrays have sum S?
    /// 
    /// Example 1:
    /// Input: A = [1,0,1,0,1], S = 2
    /// Output: 4
    /// Explanation: 
    /// The 4 subarrays are bolded below:
    /// [1,0,1,0,1]
    /// [1,0,1,0,1]
    /// [1,0,1,0,1]
    /// [1,0,1,0,1]
    /// 
    /// Note:
    /// 
    /// 1. A.length <= 30000
    /// 2. 0 <= S <= A.length
    /// 3. A[i] is either 0 or 1.
    /// </summary>
    int numSubarraysWithSum(vector<int>& A, int S);

    /// <summary>
    /// Leet code #974. Subarray Sums Divisible by K
    /// 
    /// Given an array A of integers, return the number of (contiguous, non-empty) 
    /// subarrays that have a sum divisible by K.
    ///
    /// Example 1:
    ///
    /// Input: A = [4,5,0,-2,-3,1], K = 5
    /// Output: 7
    /// Explanation: There are 7 subarrays with a sum divisible by K = 5:
    /// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], 
    /// [-2, -3]
    /// 
    /// Note:
    ///
    /// 1. 1 <= A.length <= 30000
    /// 2. -10000 <= A[i] <= 10000
    /// 3. 2 <= K <= 10000
    /// </summary>
    int subarraysDivByK(vector<int>& A, int K);

    /// <summary>
    /// Leet code #1243. Array Transformation
    ///  
    /// Given an initial array arr, every day you produce a new array using the 
    /// array of the previous day.
    ///
    /// On the i-th day, you do the following operations on the array of day 
    /// i-1 to produce the array of day i:
    ///
    /// If an element is smaller than both its left neighbor and its right 
    /// neighbor, then this element is incremented.
    /// If an element is bigger than both its left neighbor and its right 
    /// neighbor, then this element is decremented.
    /// The first and last elements never change.
    /// After some days, the array does not change. Return that final array.
    /// 
    /// Example 1:
    /// Input: arr = [6,2,3,4]
    /// Output: [6,3,3,4]
    /// Explanation: 
    /// On the first day, the array is changed from [6,2,3,4] to [6,3,3,4].
    /// No more operations can be done to this array.
    ///
    /// Example 2:
    /// Input: arr = [1,6,3,4,3,5]
    /// Output: [1,4,4,4,4,5]
    /// Explanation: 
    /// On the first day, the array is changed from [1,6,3,4,3,5] 
    /// to [1,5,4,3,4,5].
    /// On the second day, the array is changed from [1,5,4,3,4,5] 
    /// to [1,4,4,4,4,5].
    /// No more operations can be done to this array.
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 100
    /// 2. 1 <= arr[i] <= 100
    /// </summary>
    vector<int> transformArray(vector<int>& arr);

    /// <summary>
    /// Leet code #1248. Count Number of Nice Subarrays
    ///  
    /// Given an array of integers nums and an integer k. A subarray is called 
    /// nice if there are k odd numbers on it.
    ///
    /// Return the number of nice sub-arrays.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,1,2,1,1], k = 3
    /// Output: 2
    /// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] 
    /// and [1,2,1,1].
    ///
    /// Example 2:
    ///
    /// Input: nums = [2,4,6], k = 1
    /// Output: 0
    /// Explanation: There is no odd numbers in the array.
    ///
    /// Example 3:
    ///
    /// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    /// Output: 16
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 50000
    /// 2. 1 <= nums[i] <= 10^5
    /// 3. 1 <= k <= nums.length
    /// </summary>
    int numberOfSubarrays(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #41. First Missing Positive
    /// 
    /// Given an unsorted integer array, find the smallest missing positive 
    /// integer.
    ///
    /// Example 1:
    ///
    /// Input: [1,2,0]
    /// Output: 3
    ///
    /// Example 2:
    ///
    /// Input: [3,4,-1,1]
    /// Output: 2
    ///
    /// Example 3:
    ///
    /// Input: [7,8,9,11,12]
    /// Output: 1
    ///
    /// Note:
    /// 
    /// Your algorithm should run in O(n) time and uses constant extra space.
    /// </summary>
    int firstMissingPositive(vector<int>& nums);

    /// <summary>
    /// Leet code #48. Rotate Image
    /// 
    /// You are given an n x n 2D matrix representing an image.
    ///
    /// Rotate the image by 90 degrees (clockwise).
    ///
    /// Note:
    ///
    /// You have to rotate the image in-place, which means you have to 
    /// modify the input 2D matrix directly. DO NOT allocate another 2D 
    /// matrix and do the rotation.
    ///
    /// Example 1:
    ///
    /// Given input matrix = 
    /// [
    ///   [1,2,3],
    ///  [4,5,6],
    ///  [7,8,9]
    /// ],
    ///
    /// rotate the input matrix in-place such that it becomes:
    /// [
    ///  [7,4,1],
    ///  [8,5,2],
    ///  [9,6,3]
    /// ]
    ///
    /// Example 2:
    ///
    /// Given input matrix =
    /// [
    ///   [ 5, 1, 9,11],
    ///   [ 2, 4, 8,10],
    ///   [13, 3, 6, 7],
    ///   [15,14,12,16]
    /// ], 
    ///
    /// rotate the input matrix in-place such that it becomes:
    /// [
    ///   [15,13, 2, 5],
    ///   [14, 3, 4, 1],
    //    [12, 6, 8, 9],
    ///   [16, 7,10,11]
    /// ]
    /// </summary>
    void rotate(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #54. Spiral Matrix
    /// 
    /// Given a matrix of m x n elements (m rows, n columns), return all elements 
    /// of the matrix in spiral order.
    ///
    /// Example 1:
    ///
    /// Input:
    /// [
    ///  [ 1, 2, 3 ],
    ///  [ 4, 5, 6 ],
    ///  [ 7, 8, 9 ]
    /// ]
    /// Output: [1,2,3,6,9,8,7,4,5]
    ///
    /// Example 2:
    ///
    /// Input:
    /// [
    ///  [1, 2, 3, 4],
    ///   [5, 6, 7, 8],
    ///  [9,10,11,12]
    /// ]
    /// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    /// You are given an n x n 2D matrix representing an image.
    /// </summary>
    vector<int> spiralOrder(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #59. Spiral Matrix II
    /// 
    /// Given a positive integer n, generate a square matrix filled with elements
    /// from 1 to n2 in spiral order.
    ///
    /// Example:
    ///
    /// Input: 3
    /// Output:
    /// [
    ///  [ 1, 2, 3 ],
    ///  [ 8, 9, 4 ],
    ///  [ 7, 6, 5 ]
    /// ]
    /// </summary>
    vector<vector<int>> generateMatrix(int n);

    /// <summary>
    /// Leet code #287. Find the Duplicate Number
    /// 
    /// Given an array nums containing n + 1 integers where each integer is 
    /// between 1 and n (inclusive), prove that at least one duplicate number 
    /// must exist. Assume that there is only one duplicate number, find the 
    /// duplicate one.
    ///
    /// Example 1:
    ///
    /// Input: [1,3,4,2,2]
    /// Output: 2
    ///
    /// Example 2:
    ///
    /// Input: [3,1,3,4,2]
    /// Output: 3
    /// Note:
    ///
    /// You must not modify the array (assume the array is read only).
    /// You must use only constant, O(1) extra space.
    /// Your runtime complexity should be less than O(n2).
    /// There is only one duplicate number in the array, but it could be 
    /// repeated more than once.
    /// </summary>
    int findDuplicate(vector<int>& nums);

    /// <summary>
    /// Leet code #229. Majority Element II
    /// 
    /// Given an integer array of size n, find all elements that appear more than
    /// n/3 times.
    ///
    /// Note: The algorithm should run in linear time and in O(1) space.
    ///
    /// Example 1:
    /// 
    /// Input: [3,2,3]
    /// Output: [3]
    ///
    /// Example 2:
    /// 
    /// Input: [1,1,1,3,3,2,2,2]
    /// Output: [1,2]
    /// </summary>
    vector<int> majorityElementII(vector<int>& nums);

    /// <summary>
    /// Leet code #169. Majority Element
    /// 
    /// Given an array of size n, find the majority element. The majority element
    /// is the element that appears more than n/2 times.
    ///
    /// You may assume that the array is non-empty and the majority element 
    /// always exist in the array.
    ///
    /// Example 1:
    ///
    /// Input: [3,2,3]
    /// Output: 3
    ///
    /// Example 2:
    ///
    /// Input: [2,2,1,1,1,2,2]
    /// Output: 2
    /// </summary>
    int majorityElement(vector<int>& nums);

    /// <summary>
    /// Leet code #1252. Cells with Odd Values in a Matrix
    /// 
    /// Given n and m which are the dimensions of a matrix initialized by zeros 
    /// and given an array indices where indices[i] = [ri, ci]. For each pair 
    /// of [ri, ci] you have to increment all cells in row ri and column ci by 1.
    ///
    /// Return the number of cells with odd values in the matrix after applying 
    /// the increment to all indices.
    /// 
    /// Example 1:
    /// 
    /// Input: n = 2, m = 3, indices = [[0,1],[1,1]]
    /// Output: 6
    /// Explanation: Initial matrix = [[0,0,0],[0,0,0]].
    /// After applying first increment it becomes [[1,2,1],[0,1,0]].
    /// The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.
    ///
    /// Example 2:
    /// 
    /// Input: n = 2, m = 2, indices = [[1,1],[0,0]]
    /// Output: 0
    /// Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the 
    /// final matrix.
    /// 
    /// Constraints:
    ///
    /// 1. 1 <= n <= 50
    /// 2. 1 <= m <= 50
    /// 3. 1 <= indices.length <= 100
    /// 4. 0 <= indices[i][0] < n
    /// 5. 0 <= indices[i][1] < m
    /// </summary>
    int oddCells(int n, int m, vector<vector<int>>& indices);

    /// <summary>
    /// Leet code #1253. Reconstruct a 2-Row Binary Matrix
    /// 
    /// Given the following details of a matrix with n columns and 2 rows :
    ///
    /// The matrix is a binary matrix, which means each element in the matrix 
    /// can be 0 or 1.
    /// The sum of elements of the 0-th(upper) row is given as upper.
    /// The sum of elements of the 1-st(lower) row is given as lower.
    /// The sum of elements in the i-th column(0-indexed) is colsum[i], where 
    /// colsum is given as an integer array with length n.
    /// Your task is to reconstruct the matrix with upper, lower and colsum.
    ///
    /// Return it as a 2-D integer array.
    /// 
    /// If there are more than one valid solution, any of them will be accepted.
    ///
    /// If no valid solution exists, return an empty 2-D array.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: upper = 2, lower = 1, colsum = [1,1,1]
    /// Output: [[1,1,0],[0,0,1]]
    /// Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct 
    /// answers.
    ///
    /// Example 2:
    ///
    /// Input: upper = 2, lower = 3, colsum = [2,2,1,1]
    /// Output: []
    ///
    /// Example 3:
    ///
    /// Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
    /// Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
    ///
    /// Constraints:
    /// 1. 1 <= colsum.length <= 10^5
    /// 2. 0 <= upper, lower <= colsum.length
    /// 3. 0 <= colsum[i] <= 2
    /// </summary>
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum);

    /// <summary>
    /// Leet code #1260. Shift 2D Grid
    /// 
    /// Given a 2D grid of size n * m and an integer k. You need to shift 
    /// the grid k times.
    ///
    /// In one shift operation:
    ///
    /// Element at grid[i][j] becomes at grid[i][j + 1].
    /// Element at grid[i][m - 1] becomes at grid[i + 1][0].
    /// Element at grid[n - 1][m - 1] becomes at grid[0][0].
    /// Return the 2D grid after applying shift operation k times.
    /// 
    /// Example 1:
    ///
    /// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
    /// Output: [[9,1,2],[3,4,5],[6,7,8]]
    ///
    /// Example 2:
    ///
    /// Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
    /// Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
    ///
    /// Example 3:
    ///
    /// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
    /// Output: [[1,2,3],[4,5,6],[7,8,9]]
    /// 
    /// Constraints:
    ///
    /// 1. 1 <= grid.length <= 50
    /// 2. 1 <= grid[i].length <= 50
    /// 3. -1000 <= grid[i][j] <= 1000
    /// 4. 0 <= k <= 100
    /// </summary>
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k);

    /// <summary>
    /// Leet code #1267. Count Servers that Communicate
    /// 
    /// You are given a map of a server center, represented as a m * n integer 
    /// matrix grid, where 1 means that on that cell there is a server and 0 
    /// means that it is no server. Two servers are said to communicate if 
    /// they are on the same row or on the same column.
    ///
    /// Return the number of servers that communicate with any other server.
    ///
    /// Example 1:
    ///
    /// Input: grid = [[1,0],[0,1]]
    /// Output: 0
    /// Explanation: No servers can communicate with others.
    ///
    /// Example 2:
    ///
    /// Input: grid = [[1,0],[1,1]]
    /// Output: 3
    /// Explanation: All three servers can communicate with at least one other 
    /// server.
    ///
    /// Example 3:
    ///
    /// Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
    /// Output: 4
    /// Explanation: The two servers in the first row can communicate with each 
    /// other. The two servers in the third column can communicate with each 
    /// other. The server at right bottom corner can't communicate with any 
    /// other server.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m <= 250
    /// 4. 1 <= n <= 250
    /// 5. grid[i][j] == 0 or 1
    /// </summary>
    int countServers(vector<vector<int>>& grid);

    /// <summary>
    /// Leetcode #1275. Find Winner on a Tic Tac Toe Game
    /// 
    /// Tic-tac-toe is played by two players A and B on a 3 x 3 grid.
    ///
    /// Here are the rules of Tic-Tac-Toe:
    ///
    /// Players take turns placing characters into empty squares (" ").
    /// The first player A always places "X" characters, while the second 
    /// player B always places "O" characters.
    /// "X" and "O" characters are always placed into empty squares, never 
    /// on filled ones.
    /// The game ends when there are 3 of the same (non-empty) character 
    /// filling any row, column, or diagonal.
    /// The game also ends if all squares are non-empty.
    /// No more moves can be played if the game is over.
    /// Given an array moves where each element is another array of size 2 
    /// corresponding to the row and column of the grid where they mark 
    /// their respective character in the order in which A and B play.
    ///
    /// Return the winner of the game if it exists (A or B), in case the 
    /// game ends in a draw return "Draw", if there are still movements 
    /// to play return "Pending".
    ///
    /// You can assume that moves is valid (It follows the rules of 
    /// Tic-Tac-Toe), the grid is initially empty and A will play first.
    ///
    /// Example 1:
    ///
    /// Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
    /// Output: "A"
    /// Explanation: "A" wins, he always plays first.
    /// "X  "    "X  "    "X  "    "X  "    "X  "
    /// "   " -> "   " -> " X " -> " X " -> " X "
    /// "   "    "O  "    "O  "    "OO "    "OOX"
    ///
    /// Example 2:
    ///
    /// Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
    /// Output: "B"
    /// Explanation: "B" wins.
    /// "X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
    /// "   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
    /// "   "    "   "    "   "    "   "    "   "    "O  "
    ///
    /// Example 3:
    ///
    /// Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
    /// Output: "Draw"
    /// Explanation: The game ends in a draw since there are no moves to make.
    /// "XXO"
    /// "OOX"
    /// "XOX"
    ///
    /// Example 4:
    ///
    /// Input: moves = [[0,0],[1,1]]
    /// Output: "Pending"
    /// Explanation: The game has not finished yet.
    /// "X  "
    /// " O "
    /// "   "
    /// 
    /// Constraints:
    /// 1. 1 <= moves.length <= 9
    /// 2. moves[i].length == 2
    /// 3. 0 <= moves[i][j] <= 2
    /// 4. There are no repeated elements on moves.
    /// 5. moves follow the rules of tic tac toe.
    /// </summary>
    string tictactoe(vector<vector<int>>& moves);

    /// <summary>
    /// Leet code #1282. Group the People Given the Group Size They Belong To
    ///
    /// Medium
    ///
    /// There are n people whose IDs go from 0 to n - 1 and each person 
    /// belongs exactly to one group. Given the array groupSizes of 
    /// length n telling the group size each person belongs to, return the 
    /// groups there are and the people's IDs each group includes.
    ///
    /// You can return any solution in any order and the same applies for 
    /// IDs. Also, it is guaranteed that there exists at least one solution. 
    ///
    /// Example 1:
    ///
    /// Input: groupSizes = [3,3,3,3,3,1,3]
    /// Output: [[5],[0,1,2],[3,4,6]]
    /// Explanation: 
    /// Other possible solutions are [[2,1,6],[5],[0,4,3]] 
    /// and [[5],[0,6,2],[4,3,1]].
    ///
    /// Example 2:
    ///
    /// Input: groupSizes = [2,1,3,3,3,2]
    /// Output: [[1],[0,5],[2,3,4]]
    /// 
    /// Constraints:
    /// 1. groupSizes.length == n
    /// 2. 1 <= n <= 500
    /// 3. 1 <= groupSizes[i] <= n
    /// </summary>
    vector<vector<int>> groupThePeople(vector<int>& groupSizes);

    /// <summary>
    /// Leet code #1287. Element Appearing More Than 25% In Sorted Array
    /// 
    /// Easy
    ///
    /// Given an integer array sorted in non-decreasing order, there is 
    /// exactly one integer in the array that occurs more than 25% of the time.
    ///
    /// Return that integer.
    ///
    /// Example 1:
    ///
    /// Input: arr = [1,2,2,6,6,6,6,7,10]
    ///
    /// Output: 6
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^4
    /// 2. 0 <= arr[i] <= 10^5
    /// </summary>
    int findSpecialInteger(vector<int>& arr);

    /// <summary>
    /// Leet code #1292. Maximum Side Length of a Square with Sum Less than 
    /// or Equal to Threshold
    ///
    /// Medium
    ///
    /// Given a m x n matrix mat and an integer threshold. Return the maximum 
    /// side-length of a square with a sum less than or equal to threshold or 
    /// return 0 if there is no such square.
    /// 
    /// Example 1: 
    /// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], 
    /// threshold = 4
    /// Output: 2
    /// Explanation: The maximum side length of square with sum less than 4 
    /// is 2 as shown.
    ///
    /// Example 2:
    /// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],
    /// [2,2,2,2,2]], threshold = 1
    /// Output: 0
    ///
    /// Example 3:
    /// Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
    /// Output: 3
    ///
    /// Example 4:
    /// Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], 
    /// threshold = 40184
    /// Output: 2
    /// </summary>
    int maxSideLength(vector<vector<int>>& mat, int threshold);

    /// <summary>
    /// Leetcode #1296. Divide Array in Sets of K Consecutive Numbers
    /// 
    /// Given an array of integers nums and a positive integer k, find 
    /// whether it's possible to divide this array into sets of k 
    /// consecutive numbers
    /// Return True if its possible otherwise return False.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,2,3,3,4,4,5,6], k = 4
    /// Output: true
    /// Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
    ///
    /// Example 2:
    ///
    /// Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
    /// Output: true
    /// Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] 
    /// and [9,10,11].
    ///
    /// Example 3:
    ///
    /// Input: nums = [3,3,2,2,1,1], k = 3
    /// Output: true
    ///
    /// Example 4:
    ///
    /// Input: nums = [1,2,3,4], k = 3
    /// Output: false
    /// Explanation: Each array should be divided in subarrays of size 3.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= nums.length
    /// </summary>
    bool isPossibleDivide(vector<int>& nums, int k);

    /// <summary>
    /// Leetcode #1299. Replace Elements with Greatest Element on Right Side
    ///
    /// Easy	
    ///
    /// Given an array arr, replace every element in that array with the 
    /// greatest element among the elements to its right, and replace the 
    /// last element with -1.
    ///
    /// After doing so, return the array.
    /// 
    /// Example 1:
    /// Input: arr = [17,18,5,4,6,1]
    /// Output: [18,6,6,6,1,-1]
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^4
    /// 2. 1 <= arr[i] <= 10^5
    /// </summary>
    vector<int> replaceElements(vector<int>& arr);

    /// <summary>
    /// Leetcode #1306. Jump Game III
    ///
    /// Medium
    ///
    /// Given an array of non-negative integers arr, you are initially 
    /// positioned at start index of the array. When you are at index i, 
    /// you can jump to i + arr[i] or i - arr[i], check if you can reach 
    /// to any index with value 0.
    ///
    /// Notice that you can not jump outside of the array at any time.
    /// 
    /// Example 1:
    /// Input: arr = [4,2,3,0,3,1,2], start = 5
    /// Output: true
    /// Explanation: 
    /// All possible ways to reach at index 3 with value 0 are: 
    /// index 5 -> index 4 -> index 1 -> index 3 
    /// index 5 -> index 6 -> index 4 -> index 1 -> index 3 
    ///
    /// Example 2:
    /// Input: arr = [4,2,3,0,3,1,2], start = 0
    /// Output: true 
    /// Explanation: 
    /// One possible way to reach at index 3 with value 0 is: 
    /// index 0 -> index 4 -> index 1 -> index 3
    ///
    /// Example 3:
    /// Input: arr = [3,0,2,1,2], start = 2
    /// Output: false
    /// Explanation: There is no way to reach at index 1 with value 0.
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 5 * 10^4
    /// 2. 0 <= arr[i] < arr.length
    /// 3. 0 <= start < arr.length
    /// </summary>
    bool canReach(vector<int>& arr, int start);

    /// <summary>
    /// Leet code #448. Find All Numbers Disappeared in an Array
    ///
    /// Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), 
    /// some elements appear twice and others appear once.
    /// Find all the elements of [1, n] inclusive that do not appear in this 
    /// array.
    /// Could you do it without extra space and in O(n) runtime? You may 
    /// assume the returned list does not count as extra space.
    ///
    /// Example:
    ///
    /// Input:
    /// [4,3,2,7,8,2,3,1]
    /// Output:
    /// [5,6]
    /// </summary>
    vector<int> findDisappearedNumbers(vector<int>& nums);

    /// <summary>
    /// Leet code #36. Valid Sudoku
    ///
    /// Medium
    ///
    /// Determine if a 9x9 Sudoku board is valid. Only the filled cells need 
    /// to be validated according to the following rules:
    ///
    /// Each row must contain the digits 1-9 without repetition.
    /// Each column must contain the digits 1-9 without repetition.
    /// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 
    /// without repetition.
    /// 
    /// A partially filled sudoku which is valid.
    ///  
    /// The Sudoku board could be partially filled, where empty cells are 
    /// filled with the character '.'.
    ///
    /// Example 1:
    ///
    /// Input:
    /// [
    ///  ["5","3",".",".","7",".",".",".","."],
    ///  ["6",".",".","1","9","5",".",".","."],
    ///  [".","9","8",".",".",".",".","6","."],
    ///  ["8",".",".",".","6",".",".",".","3"],
    ///  ["4",".",".","8",".","3",".",".","1"],
    ///  ["7",".",".",".","2",".",".",".","6"],
    ///  [".","6",".",".",".",".","2","8","."],
    ///  [".",".",".","4","1","9",".",".","5"],
    ///  [".",".",".",".","8",".",".","7","9"]
    /// ]
    /// Output: true
    /// Example 2:
    ///
    /// Input:
    /// [
    ///  ["8","3",".",".","7",".",".",".","."],
    ///  ["6",".",".","1","9","5",".",".","."],
    ///  [".","9","8",".",".",".",".","6","."],
    ///  ["8",".",".",".","6",".",".",".","3"],
    ///  ["4",".",".","8",".","3",".",".","1"],
    ///  ["7",".",".",".","2",".",".",".","6"],
    ///  [".","6",".",".",".",".","2","8","."],
    ///  [".",".",".","4","1","9",".",".","5"],
    ///  [".",".",".",".","8",".",".","7","9"]
    /// ]
    /// Output: false
    /// Explanation: Same as Example 1, except with the 5 in the top left 
    /// corner being modified to 8. Since there are two 8's in the top 
    /// left 3x3 sub-box, it is invalid.
    /// Note:
    ///
    /// A Sudoku board (partially filled) could be valid but is not 
    /// necessarily solvable.
    /// Only the filled cells need to be validated according to the mentioned 
    /// rules.
    /// The given board contain only digits 1-9 and the character '.'.
    /// The given board size is always 9x9.
    /// </summary>
    bool isValidSudoku(vector<vector<char>>& board);

    /// <summary>
    /// Leet code #1310. XOR Queries of a Subarray
    /// 
    /// Medium
    ///
    /// Given the array arr of positive integers and the array queries where 
    /// queries[i] = [Li, Ri], for each query i compute the XOR of elements 
    /// from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
    /// Return an array containing the result for the given queries. 
    /// 
    /// Example 1:
    /// Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
    /// Output: [2,7,14,8] 
    /// Explanation: 
    /// The binary representation of the elements in the array are:
    /// 1 = 0001 
    /// 3 = 0011 
    /// 4 = 0100 
    /// 8 = 1000 
    /// The XOR values for queries are:
    /// [0,1] = 1 xor 3 = 2 
    /// [1,2] = 3 xor 4 = 7 
    /// [0,3] = 1 xor 3 xor 4 xor 8 = 14 
    /// [3,3] = 8
    ///
    /// Example 2:
    /// Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
    /// Output: [8,0,4,4]
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 3 * 10^4
    /// 2. 1 <= arr[i] <= 10^9
    /// 3. 1 <= queries.length <= 3 * 10^4
    /// 4. queries[i].length == 2
    /// 5. 0 <= queries[i][0] <= queries[i][1] < arr.length
    /// </summary>
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code #1313. Decompress Run-Length Encoded List
    ///
    /// Easy
    ///
    /// We are given a list nums of integers representing a list compressed with 
    /// run-length encoding.
    ///
    /// Consider each adjacent pair of elements [a, b] = [nums[2*i], nums[2*i+1]] 
    /// (with i >= 0).  For each such pair, there are a elements with value b in 
    /// the decompressed list.
    ///
    /// Return the decompressed list.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,2,3,4]
    /// Output: [2,4,4,4]
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 100
    /// 2. nums.length % 2 == 0
    /// 3. 1 <= nums[i] <= 100
    /// </summary>
    vector<int> decompressRLElist(vector<int>& nums);

    /// <summary>
    /// Leet code #1314. Matrix Block Sum
    ///
    /// Medium
    ///
    /// Given a m * n matrix mat and an integer K, return a matrix answer where 
    /// each answer[i][j] is the sum of all elements mat[r][c] for 
    /// i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position 
    /// in the matrix. 
    /// 
    /// Example 1:
    /// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
    /// Output: [[12,21,16],[27,45,33],[24,39,28]]
    ///
    /// Example 2:
    /// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
    /// Output: [[45,45,45],[45,45,45],[45,45,45]]
    /// 
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[i].length
    /// 3. 1 <= m, n, K <= 100
    /// 4. 1 <= mat[i][j] <= 100
    /// </summary>
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K);

    /// <summary>
    /// Leet code #413. Arithmetic Slices
    ///
    /// A sequence of number is called arithmetic if it consists of at least 
    /// three elements and if the difference between 
    /// any two consecutive elements is the same
    /// For example, these are arithmetic sequence:
    /// 1, 3, 5, 7, 9
    /// 7, 7, 7, 7
    /// 3, -1, -5, -9
    /// The following sequence is not arithmetic.
    /// 1, 1, 2, 5, 7
    /// A zero-indexed array A consisting of N numbers is given. A 
    /// slice of that array is any pair of integers (P, Q) such that 
    /// 0 <= P < Q < N.
    /// A slice (P, Q) of array A is called arithmetic if the sequence:
    /// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, 
    /// this means that P + 1 < Q.
    /// The function should return the number of arithmetic slices in the 
    /// array A. 
    /// Example: 
    /// A = [1, 2, 3, 4]
    /// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] 
    /// and [1, 2, 3, 4] itself.
    /// </summary>
    int numberOfArithmeticSlices(vector<int>& A);

    /// <summary>
    /// Leet code #485. Max Consecutive Ones  
    /// 
    /// Given a binary array, find the maximum number of consecutive 1s in this array. 
    /// Example 1:
    /// Input: [1,1,0,1,1,1]
    /// Output: 3
    /// Explanation: The first two digits or the last three digits are consecutive 1s.
    /// The maximum number of consecutive 1s is 3.
    /// Note: 
    /// The input array will only contain 0 and 1.
    /// The length of input array is a positive integer and will not exceed 10,000 
    /// </summary>
    int findMaxConsecutiveOnes(vector<int>& nums);

    /// <summary>
    /// Leet code #446. Arithmetic Slices II - Subsequence    
    /// 
    /// A sequence of numbers is called arithmetic if it consists of at 
    /// least three elements and if the difference between any two 
    /// consecutive elements is the same.
    ///
    /// For example, these are arithmetic sequences:
    /// 1, 3, 5, 7, 9
    /// 7, 7, 7, 7
    /// 3, -1, -5, -9
    ///
    /// The following sequence is not arithmetic.
    /// 1, 1, 2, 5, 7
    /// A zero-indexed array A consisting of N numbers is given. A 
    /// subsequence slice of that array is any sequence of integers 
    /// (P0, P1, ..., Pk) such that 0 ¡Ü P0 < P1 < ... < Pk < N.
    ///
    /// A subsequence slice (P0, P1, ..., Pk) of array A is called 
    /// arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] 
    /// is arithmetic. In particular, this means that k ¡Ý 2.
    /// 
    /// The function should return the number of arithmetic subsequence 
    /// slices in the array A. 
    ///
    /// The input contains N integers. Every integer is in the range of -2^31 
    /// and 2^31-1 and 0 ¡Ü N ¡Ü 1000. The output is guaranteed to be less than 2^31-1.
    ///
    /// Example: 
    /// Input: [2, 4, 6, 8, 10]
    /// Output: 7
    ///
    /// Explanation:
    /// All arithmetic subsequence slices are:
    /// [2,4,6]
    /// [4,6,8]
    /// [6,8,10]
    /// [2,4,6,8]
    /// [4,6,8,10]
    /// [2,4,6,8,10]
    /// [2,6,10]
    /// </summary>
    int numberOfArithmeticSlicesII(vector<int>& A);

    /// <summary>
    /// Leet code #368. Largest Divisible Subset 
    /// 
    /// Given a set of distinct positive integers, find the largest 
    /// subset such that every pair (Si, Sj) of elements in this subset 
    /// satisfies: Si % Sj = 0 or Sj % Si = 0. 
    ///
    /// If there are multiple solutions, return any subset is fine. 
    ///
    /// Example 1: 
    /// nums: [1,2,3]
    /// Result: [1,2] (of course, [1,3] will also be ok)
    ///
    /// Example 2: 
    /// nums: [1,2,4,8]
    /// Result: [1,2,4,8]
    /// </summary>
    vector<int> largestDivisibleSubset(vector<int>& nums);

    /// <summary>
    /// Leet code #26. Remove Duplicates from Sorted Array
    ///
    /// Given a sorted array, remove the duplicates in place such that 
    /// each element appear only once and return the new length.
    /// Do not allocate extra space for another array, you must do this in 
    /// place with constant memory. 
    /// For example,
    /// Given input array nums = [1,1,2], 
    /// Your function should return length = 2, with the first two elements 
    /// of nums being 1 and 2 respectively. 
    /// It doesn't matter what you leave beyond the new length. 
    /// </summary>
    int removeDuplicateSortedArray(vector<int>& nums);

    /// <summary>
    /// LeetCode #80. Remove Duplicates from Sorted Array II  
    ///
    /// Follow up for "Remove Duplicates": 
    /// What if duplicates are allowed at most twice? 
    /// For example, 
    /// Given sorted array nums = [1,1,1,2,2,3], 
    /// Your function should return length = 5, with the first five elements 
    /// of nums being 1, 1, 2, 2 and 3. 
    /// It doesn't matter what you leave beyond the new length.  
    /// </summary>
    int removeDuplicatesII(vector<int>& nums);

    /// <summary>
    /// LeetCode #73. Set Matrix Zeroes
    ///
    /// Given a m x n matrix, if an element is 0, set its entire row and column 
    /// to 0. Do it in place. 
    /// Did you use extra space?
    /// A straight forward solution using O(mn) space is probably a bad idea.
    /// A simple improvement uses O(m + n) space, but still not the best 
    /// solution.
    /// Could you devise a constant space solution? 
    /// </summary>
    void setZeroes(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #189. Rotate Array
    ///
    /// Rotate an array of n elements to the right by k steps.
    /// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is 
    /// rotated to [5,6,7,1,2,3,4]. 
    /// Note:
    /// Try to come up as many solutions as you can, there are at least 3 
    /// different ways to solve this problem. 
    /// Hint:
    /// Could you do it in-place with O(1) extra space? 
    /// Related problem: Reverse Words in a String II
    /// </summary>
    void rotateArray(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #419. Battleships in a Board  
    ///
    /// Given an 2D board, count how many different battleships are in it. 
    /// The battleships are represented with 'X's, empty slots are 
    /// represented with '.'s. You may assume the following rules: 
    /// You receive a valid board, made of only battleships or empty slots.
    /// Battleships can only be placed horizontally or vertically. In other 
    /// words, they can only be made of the shape 1xN (1 row, N columns) or 
    /// Nx1 (N rows, 1 column), where N can be of any size.
    /// At least one horizontal or vertical cell separates between two 
    /// battleships - there are no adjacent battleships.
    /// Example:
    /// X..X
    /// ...X
    /// ...X
    /// In the above board there are 2 battleships. 
    /// Invalid Example:
    /// ...X
    /// XXXX
    /// ...X
    /// This is an invalid board that you will not receive - as battleships 
    /// will always have a cell separating between them. 
    /// Follow up:
    /// Could you do it in one-pass, using only O(1) extra memory and 
    /// without modifying the value of the board?    
    /// </summary>
    int countBattleships(vector<vector<char>>& board);

    /// <summary>
    /// Leet code #442. Find All Duplicates in an Array
    ///
    /// Given an array of integers, 1 ¡Ü a[i] ¡Ü n (n = size of array), some 
    /// elements appear twice and others appear once.
    /// Find all the elements that appear twice in this array.
    /// Could you do it without extra space and in O(n) runtime?
    /// Example:
    /// Input:
    /// [4,3,2,7,8,2,3,1]
    /// Output:
    /// [2,3]
    /// </summary>
    vector<int> findDuplicates(vector<int>& nums);

    /// <summary>
    /// Leet code #243. Shortest Word Distance  
    /// 
    /// Given a list of words and two words word1 and word2, return the 
    /// shortest distance between these two words in the list. 
    /// For example,
    /// Assume that words = ["practice", "makes", "perfect", "coding", "makes"]
    /// Given word1 = "coding", word2 = "practice", return 3. 
    /// Given word1 = "makes", word2 = "coding", return 1.
    /// </summary>
    int shortestDistance(vector<string>& words, string word1, string word2);

    /// <summary>
    /// Leet code #245. Shortest Word Distance III  
    /// 
    /// This is a follow up of Shortest Word Distance. The only difference is 
    /// now word1 could be the same as word2.
    /// Given a list of words and two words word1 and word2, return the 
    /// shortest distance between these two words in the list.
    /// word1 and word2 may be the same and they represent two individual 
    /// words in the list.
    /// For example,
    /// Assume that words = ["practice", "makes", "perfect", "coding", "makes"]. 
    /// Given word1 = ¡°makes¡±, word2 = ¡°coding¡±, return 1.
    /// Given word1 = "makes", word2 = "makes", return 3. 
    /// Note:
    /// You may assume word1 and word2 are both in the list. 
    /// </summary>
    int shortestWordDistance(vector<string>& words, string word1, string word2);

    /// <summary>
    /// Leet code #1330. Reverse Subarray To Maximize Array Value 
    /// 
    /// Hard
    ///
    /// You are given an integer array nums. The value of this array is 
    /// defined as the sum of |nums[i]-nums[i+1]| for 
    /// all 0 <= i < nums.length-1.
    ///
    /// You are allowed to select any subarray of the given array and 
    /// reverse it. You can perform this operation only once.
    ///
    /// Find maximum possible value of the final array.
    /// 
    /// Example 1:
    /// Input: nums = [2,3,1,5,4]
    /// Output: 10
    /// Explanation: By reversing the subarray [3,1,5] the array 
    /// becomes [2,5,1,3,4] whose value is 10.
    ///
    /// Example 2:
    /// Input: nums = [2,4,9,24,2,1,10]
    /// Output: 68
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 3*10^4
    /// 2. -10^5 <= nums[i] <= 10^5
    /// </summary>
    int maxValueAfterReverse(vector<int>& nums);

    /// <summary>
    /// Leet code #1329. Sort the Matrix Diagonally 
    /// 
    /// Medium
    ///
    /// Given a m * n matrix mat of integers, sort it diagonally in ascending 
    /// order from the top-left to the bottom-right then return the sorted 
    /// array.
    /// 
    /// Example 1:
    /// Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
    /// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
    /// 
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[i].length
    /// 3. 1 <= m, n <= 100
    /// 4. 1 <= mat[i][j] <= 100
    /// </summary>
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat);

    /// <summary>
    /// Leet code #1333. Filter Restaurants by Vegan-Friendly, Price and Distance
    /// 
    /// Medium
    ///
    /// Given the array restaurants where  restaurants[i] = [idi, ratingi, 
    /// veganFriendlyi, pricei, distancei]. You have to filter the restaurants 
    /// using three filters.
    ///
    /// The veganFriendly filter will be either true (meaning you should only 
    /// include restaurants with veganFriendlyi set to true) or false (meaning 
    /// you can include any restaurant). In addition, you have the filters 
    /// maxPrice and maxDistance which are the maximum value for price and 
    /// distance of restaurants you should consider respectively.
    ///
    /// Return the array of restaurant IDs after filtering, ordered by rating 
    /// from highest to lowest. For restaurants with the same rating, order 
    /// them by id from highest to lowest. For simplicity veganFriendlyi and 
    /// veganFriendly take value 1 when it is true, and 0 when it is false.
    ///
    /// Example 1:
    /// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
    /// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, 
    /// maxDistance = 10
    /// Output: [3,1,5] 
    /// Explanation: 
    /// The restaurants are:
    /// Restaurant 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
    /// Restaurant 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
    /// Restaurant 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
    /// Restaurant 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
    /// Restaurant 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
    /// After filter restaurants with veganFriendly = 1, maxPrice = 50 and 
    /// maxDistance = 10 we have restaurant 3, restaurant 1 and restaurant 5 
    /// (ordered by rating from highest to lowest).
    ///	
    /// Example 2:
    /// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
    /// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, 
    /// maxDistance = 10
    /// Output: [4,3,2,1,5]
    /// Explanation: The restaurants are the same as in example 1, but in 
    /// this case the filter veganFriendly = 0, therefore all restaurants are
    /// considered.
    ///
    /// Example 3:
    /// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
    /// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, 
    /// maxDistance = 3
    /// Output: [4,5]
    ///
    /// Constraints:
    /// 1. 1 <= restaurants.length <= 10^4
    /// 2. restaurants[i].length == 5
    /// 3. 1 <= id[i], ratingi, pricei, distancei <= 10^5
    /// 4. 1 <= maxPrice, maxDistance <= 10^5
    /// 5. veganFriendlyi and veganFriendly are 0 or 1.
    /// 6. All id[i] are distinct.
    /// </summary>
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, 
        int veganFriendly, int maxPrice, int maxDistance);

    /// <summary>
    /// Leet code #1337. The K Weakest Rows in a Matrix 
    /// 
    /// Easy
    ///
    /// Given a m * n matrix mat of ones (representing soldiers) and zeros 
    /// (representing civilians), return the indexes of the k weakest rows 
    /// in the matrix ordered from the weakest to the strongest.
    /// 
    /// A row i is weaker than row j, if the number of soldiers in row i is 
    /// less than the number of soldiers in row j, or they have the same 
    /// number of soldiers but i is less than j. Soldiers are always stand 
    /// in the frontier of a row, that is, always ones may appear first and 
    /// then zeros.
    /// 
    /// Example 1:
    ///
    /// Input: mat = 
    /// [[1,1,0,0,0],
    ///  [1,1,1,1,0],
    ///  [1,0,0,0,0],
    ///  [1,1,0,0,0],
    ///  [1,1,1,1,1]], 
    /// k = 3
    /// Output: [2,0,3]
    /// Explanation: 
    /// The number of soldiers for each row is: 
    /// row 0 -> 2 
    /// row 1 -> 4 
    /// row 2 -> 1 
    /// row 3 -> 2 
    /// row 4 -> 5 
    /// Rows ordered from the weakest to the strongest are [2,0,3,1,4]
    /// 
    /// Example 2:
    ///
    /// Input: mat = 
    /// [[1,0,0,0],
    ///  [1,1,1,1],
    ///  [1,0,0,0],
    ///  [1,0,0,0]], 
    /// k = 2
    /// Output: [0,2]
    /// Explanation: 
    /// The number of soldiers for each row is: 
    /// row 0 -> 1 
    /// row 1 -> 4 
    /// row 2 -> 1 
    /// row 3 -> 1 
    /// Rows ordered from the weakest to the strongest are [0,2,3,1]
    /// 
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[i].length
    /// 3. 2 <= n, m <= 100
    /// 4. 1 <= k <= m
    /// 5. matrix[i][j] is either 0 or 1.
    /// </summary>
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k);

    /// <summary>
    /// Leet code #1338. Reduce Array Size to The Half 
    /// 
    /// Medium
    ///
    /// Given an array arr.  You can choose a set of integers and remove all 
    /// the occurrences of these integers in the array.
    ///
    /// Return the minimum size of the set so that at least half of the 
    /// integers of the array are removed.
    ///  
    /// Example 1:
    ///
    /// Input: arr = [3,3,3,3,5,5,5,2,2,7]
    /// Output: 2
    /// Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which 
    /// has size 5 (i.e equal to half of the size of the old array).
    /// Possible sets of size 2 are {3,5},{3,2},{5,2}.
    /// Choosing set {2,7} is not possible as it will make the new 
    /// array [3,3,3,3,5,5,5] which has size greater than half of the size of 
    /// the old array.
    ///
    /// Example 2:
    ///
    /// Input: arr = [7,7,7,7,7,7]
    /// Output: 1
    /// Explanation: The only possible set you can choose is {7}. This will make the new array empty.
    ///
    /// Example 3:
    ///
    /// Input: arr = [1,9]
    /// Output: 1
    ///
    /// Example 4:
    ///
    /// Input: arr = [1000,1000,3,7]
    /// Output: 1
    ///
    /// Example 5:
    ///
    /// Input: arr = [1,2,3,4,5,6,7,8,9,10]
    /// Output: 5
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. arr.length is even.
    /// 3. 1 <= arr[i] <= 10^5
    /// </summary>
    int minSetSize(vector<int>& arr);

    /// <summary>
    /// Leet code #1343. Number of Sub-arrays of Size K and Average Greater 
    /// than or Equal to Threshold
    ///
    /// Medium
    ///
    /// Given an array of integers arr and two integers k and threshold.
    ///
    /// Return the number of sub-arrays of size k and average greater than 
    /// or equal to threshold.
    ///
    /// Example 1:
    /// Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
    /// Output: 3
    /// Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have 
    /// averages 4, 5 and 6 respectively. All other sub-arrays of size 3 
    /// have averages less than 4 (the threshold).
    ///
    /// Example 2:
    /// Input: arr = [1,1,1,1,1], k = 1, threshold = 0
    /// Output: 5
    ///
    /// Example 3:
    /// Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
    /// Output: 6
    /// Explanation: The first 6 sub-arrays of size 3 have averages greater 
    /// than 5. Note that averages are not integers.
    ///
    /// Example 4:
    /// Input: arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
    /// Output: 1
    ///
    /// Example 5:
    /// Input: arr = [4,4,4,4], k = 4, threshold = 1
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 1 <= arr[i] <= 10^4
    /// 3. 1 <= k <= arr.length
    /// 4. 0 <= threshold <= 10^4
    /// </summary>
    int numOfSubarrays(vector<int>& arr, int k, int threshold);

    /// <summary>
    /// Leet code #1346. Check If N and Its Double Exist
    ///
    /// Easy
    ///
    /// Given an array arr of integers, check if there exists two integers 
    /// N and M such that N is the double of M ( i.e. N = 2 * M).
    ///
    /// More formally check if there exists two indices i and j such that :
    ///  
    /// i != j
    /// 0 <= i, j < arr.length
    /// arr[i] == 2 * arr[j]
    /// 
    /// Example 1:
    /// Input: arr = [10,2,5,3]
    /// Output: true
    /// Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
    ///
    /// Example 2:
    /// Input: arr = [7,1,14,11]
    /// Output: true
    /// Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
    ///
    /// Example 3:
    /// Input: arr = [3,1,7,11]
    /// Output: false
    /// Explanation: In this case does not exist N and M, such that N = 2 * M.
    ///
    /// Constraints:
    /// 1. 2 <= arr.length <= 500
    /// 2. -10^3 <= arr[i] <= 10^3
    /// </summary>
    bool checkIfExist(vector<int>& arr);

    /// <summary>
    /// Leet code #1200. Minimum Absolute Difference
    /// 
    /// Given an array of distinct integers arr, find all pairs of elements 
    /// with the minimum absolute difference of any two elements. 
    ///
    /// Return a list of pairs in ascending order(with respect to pairs), 
    /// each pair [a, b] follows
    ///
    /// a, b are from arr
    /// a < b
    /// b - a equals to the minimum absolute difference of any two elements in arr
    /// 
    ///
    /// Example 1:
    ///
    /// Input: arr = [4,2,1,3]
    /// Output: [[1,2],[2,3],[3,4]]
    /// Explanation: The minimum absolute difference is 1. List all pairs with 
    /// difference equal to 1 in ascending order.
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,3,6,10,15]
    /// Output: [[1,3]]
    ///
    /// Example 3:
    ///
    /// Input: arr = [3,8,-10,23,19,-4,-14,27]
    /// Output: [[-14,-10],[19,23],[23,27]]
    /// 
    /// Constraints:
    /// 1. 2 <= arr.length <= 10^5
    /// 2. -10^6 <= arr[i] <= 10^6
    /// </summary>
    vector<vector<int>> minimumAbsDifference(vector<int>& arr);

    /// <summary>
    /// Leet code #1186. Maximum Subarray Sum with One Deletion
    /// 
    /// Given an array of integers, return the maximum sum for a non-empty 
    /// subarray (contiguous elements) with at most one element deletion. 
    /// In other words, you want to choose a subarray and optionally delete 
    /// one element from it so that there is still at least one element left 
    /// and the sum of the remaining elements is maximum possible.
    /// Note that the subarray needs to be non-empty after deleting one element.
    /// 
    /// Example 1:
    /// Input: arr = [1,-2,0,3]
    /// Output: 4
    /// Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the 
    /// subarray [1, 0, 3] becomes the maximum value.
    ///
    /// Example 2:
    /// Input: arr = [1,-2,-2,3]
    /// Output: 3
    /// Explanation: We just choose [3] and it's the maximum sum.
    ///
    /// Example 3:
    /// Input: arr = [-1,-1,-1,-1]
    /// Output: -1
    /// Explanation: The final subarray needs to be non-empty. You can't 
    /// choose [-1] and delete -1 from it, then get an empty subarray to make 
    /// the sum equals to 0.
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. -10^4 <= arr[i] <= 10^4
    /// </summary>
    int maximumSum(vector<int>& arr);

    /// <summary>
    /// Leet code #1191. K-Concatenation Maximum Sum
    /// 
    /// Given an integer array arr and an integer k, modify the array by repeating 
    /// it k times.
    /// For example, if arr = [1, 2] and k = 3 then the modified array will 
    /// be [1, 2, 1, 2, 1, 2].
    /// Return the maximum sub-array sum in the modified array. Note that the 
    /// length of the sub-array can be 0 and its sum in that case is 0.
    ///
    /// As the answer can be very large, return the answer modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: arr = [1,2], k = 3
    /// Output: 9
    ///
    /// Example 2:
    /// Input: arr = [1,-2,1], k = 5
    /// Output: 2
    /// Example 3:
    /// Input: arr = [-1,-2], k = 7
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 1 <= k <= 10^5
    /// 3. -10^4 <= arr[i] <= 10^4
    /// </summary>
    int kConcatenationMaxSum(vector<int>& arr, int k);

    /// <summary>
    /// Leet code #1184. Distance Between Bus Stops
    /// 
    /// A bus has n stops numbered from 0 to n - 1 that form a circle. We know 
    /// the distance between all pairs of neighboring stops where distance[i] 
    /// is the distance between the stops number i and (i + 1) % n.
    /// The bus goes along both directions i.e. clockwise and counterclockwise.
    /// Return the shortest distance between the given start and destination 
    /// stops.
    /// 
    /// Example 1:
    ///
    /// Input: distance = [1,2,3,4], start = 0, destination = 1
    /// Output: 1
    /// Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
    /// 
    /// Example 2:
    ///
    /// Input: distance = [1,2,3,4], start = 0, destination = 2
    /// Output: 3
    /// Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
    ///  
    /// Example 3:
    ///
    /// Input: distance = [1,2,3,4], start = 0, destination = 3
    /// Output: 4
    /// Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// 2. distance.length == n
    /// 3. 0 <= start, destination < n
    /// 4. 0 <= distance[i] <= 10^4
    /// </summary>
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination);

    /// <summary>
    /// Leet code #1183. Maximum Number of Ones
    /// 
    /// Consider a matrix M with dimensions width * height, such that every cell
    /// has value 0 or 1, and any square sub-matrix of M of size 
    /// sideLength * sideLength has at most maxOnes ones.
    /// Return the maximum possible number of ones that the matrix M can have.
    /// 
    /// Example 1:
    /// Input: width = 3, height = 3, sideLength = 2, maxOnes = 1
    /// Output: 4
    /// Explanation:
    /// In a 3*3 matrix, no 2*2 sub-matrix can have more than 1 one.
    /// The best solution that has 4 ones is:
    /// [1,0,1]
    /// [0,0,0]
    /// [1,0,1]
    ///
    /// Example 2:
    /// Input: width = 3, height = 3, sideLength = 2, maxOnes = 2
    /// Output: 6
    /// Explanation:
    /// [1,0,1]
    /// [1,0,1]
    /// [1,0,1]
    /// 
    /// Constraints:
    /// 1. 1 <= width, height <= 100
    /// 2. 1 <= sideLength <= width, height
    /// 3. 0 <= maxOnes <= sideLength * sideLength
    /// </summary>
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes);

    /// <summary>
    /// Leet code #1176. Diet Plan Performance
    /// 
    /// A dieter consumes calories[i] calories on the i-th day.  For every 
    /// consecutive sequence of k days, they look at T, the total calories 
    /// consumed during that sequence of k days:
    /// If T < lower, they performed poorly on their diet and lose 1 point; 
    /// If T > upper, they performed well on their diet and gain 1 point;
    /// Otherwise, they performed normally and there is no change in points.
    /// Return the total number of points the dieter has after all 
    /// calories.length days.
    ///
    /// Note that: The total points could be negative.
    /// 
    /// Example 1:
    /// Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
    /// Output: 0
    /// Explaination: calories[0], calories[1] < lower and 
    /// calories[3], calories[4] > upper, total points = 0.
    ///
    /// Example 2:
    /// Input: calories = [3,2], k = 2, lower = 0, upper = 1
    /// Output: 1
    /// Explaination: calories[0] + calories[1] > upper, total points = 1.
    ///
    /// Example 3:
    /// Input: calories = [6,5,0,0], k = 2, lower = 1, upper = 5
    /// Output: 0
    /// Explaination: calories[0] + calories[1] > upper, 
    /// calories[2] + calories[3] < lower, total points = 0.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= calories.length <= 10^5
    /// 2. 0 <= calories[i] <= 20000
    /// 3. 0 <= lower <= upper
    /// </summary>
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper);

    /// <summary>
    /// Leet code #1138. Alphabet Board Path
    /// 
    /// On an alphabet board, we start at position (0, 0), corresponding to 
    /// character board[0][0].
    ///
    /// Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], 
    /// as shown in the diagram below.
    ///
    /// We may make the following moves:
    ///
    /// 'U' moves our position up one row, if the position exists on the 
    /// board;
    /// 'D' moves our position down one row, if the position exists on the 
    /// board;
    /// 'L' moves our position left one column, if the position exists on the 
    /// board;
    /// 'R' moves our position right one column, if the position exists on the 
    /// board;
    /// '!' adds the character board[r][c] at our current position (r, c) to the 
    /// answer.
    /// (Here, the only positions that exist on the board are positions with 
    ///  letters on them.)
    ///
    /// Return a sequence of moves that makes our answer equal to target in the 
    /// minimum number of moves.  You may return any path that does so.
    ///
    /// Example 1:
    /// Input: target = "leet"
    /// Output: "DDR!UURRR!!DDD!"
    ///
    /// Example 2:
    /// Input: target = "code"
    /// Output: "RR!DDRR!UUL!R!"
    ///  
    /// Constraints:
    /// 1. 1 <= target.length <= 100
    /// 2. target consists only of English lowercase letters.
    /// </summary>
    string alphabetBoardPath(string target);

    /// <summary>
    /// Leet code #1151. Minimum Swaps to Group All 1's Together
    /// 
    /// Given a binary array data, return the minimum number of swaps required 
    /// to group all 1¡¯s present in the array together in any place in the array.
    /// 
    /// Example 1:
    /// Input: [1,0,1,0,1]
    /// Output: 1
    /// Explanation: 
    /// There are 3 ways to group all 1's together:
    /// [1,1,1,0,0] using 1 swap.
    /// [0,1,1,1,0] using 2 swaps.
    /// [0,0,1,1,1] using 1 swap.
    /// The minimum is 1.
    ///
    /// Example 2:
    /// Input: [0,0,0,1,0]
    /// Output: 0
    /// Explanation: 
    /// Since there is only one 1 in the array, no swaps needed.
    ///
    /// Example 3:
    /// Input: [1,0,1,0,1,0,0,1,1,0,1]
    /// Output: 3
    /// Explanation: 
    /// One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
    /// 
    /// Note:
    /// 1. 1 <= data.length <= 10^5
    /// 2. 0 <= data[i] <= 1
    /// </summary>
    int minSwaps(vector<int>& data);

    /// <summary>
    /// Leet code #1124. Longest Well-Performing Interval
    /// 
    /// We are given hours, a list of the number of hours worked per day for a 
    /// given employee.
    /// A day is considered to be a tiring day if and only if the number of hours 
    /// worked is (strictly) greater than 8.
    /// A well-performing interval is an interval of days for which the number of 
    /// tiring days is strictly larger than the number of non-tiring days.
    /// Return the length of the longest well-performing interval.
    /// 
    /// Example 1:
    /// Input: hours = [9,9,6,0,6,6,9]
    /// Output: 3
    /// Explanation: The longest well-performing interval is [9,9,6].
    /// 
    /// Constraints:
    /// 1. 1 <= hours.length <= 10000
    /// 2. 0 <= hours[i] <= 16
    /// </summary>
    int longestWPI(vector<int>& hours);

    /// <summary>
    /// Leet code #1121. Divide Array Into Increasing Sequences
    /// 
    /// Given a non-decreasing array of positive integers nums and an integer K, 
    /// find out if this array can be divided into one or more disjoint 
    /// increasing subsequences of length at least K.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,2,3,3,4,4], K = 3
    /// Output: true
    /// Explanation: 
    /// The array can be divided into the two subsequences [1,2,3,4] and [2,3,4] 
    /// with lengths at least 3 each.
    ///
    /// Example 2:
    /// Input: nums = [5,6,6,7,8], K = 3
    /// Output: false
    /// Explanation: 
    /// There is no way to divide the array using the conditions required.
    /// 
    /// Note:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= K <= nums.length
    /// 3. 1 <= nums[i] <= 10^5
    /// </summary>
    bool canDivideIntoSubsequences(vector<int>& nums, int K);

    /// <summary>
    /// Leet code #1351. Count Negative Numbers in a Sorted Matrix
    ///
    /// Easy
    ///
    /// Given a m * n matrix grid which is sorted in non-increasing order 
    /// both row-wise and column-wise. 
    ///
    /// Return the number of negative numbers in grid.
    ///
    /// Example 1:
    /// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    /// Output: 8
    /// Explanation: There are 8 negatives number in the matrix.
    ///
    /// Example 2:
    /// Input: grid = [[3,2],[1,0]]
    /// Output: 0
    ///
    /// Example 3:
    /// Input: grid = [[1,-1],[-1,-1]]
    /// Output: 3
    ///
    /// Example 4:
    /// Input: grid = [[-1]]
    /// Output: 1
    /// 
    ///
    /// Constraints:
    ///
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 100
    /// 4. -100 <= grid[i][j] <= 100
    /// </summary>
    int countNegatives(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1380. Lucky Numbers in a Matrix
    ///
    /// Easy
    ///
    /// Given a m * n matrix of distinct numbers, return all lucky numbers 
    /// in the matrix in any order.
    /// A lucky number is an element of the matrix such that it is the 
    /// minimum element in its row and maximum in its column.
    ///
    /// Example 1:
    /// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
    /// Output: [15]
    /// Explanation: 15 is the only lucky number since it is the minimum 
    /// in its row and the maximum in its column
    ///
    /// Example 2:
    /// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
    /// Output: [12]
    /// Explanation: 12 is the only lucky number since it is the minimum in 
    /// its row and the maximum in its column.
    ///
    /// Example 3:
    /// Input: matrix = [[7,8],[1,2]]
    /// Output: [7]
    ///
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[i].length
    /// 3. 1 <= n, m <= 50
    /// 4. 1 <= matrix[i][j] <= 10^5.
    /// 5. All elements in the matrix are distinct.
    /// </summary>
    vector<int> luckyNumbers(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #1389. Create Target Array in the Given Order
    /// 
    /// Easy
    ///
    /// Given two arrays of integers nums and index. Your task is to create 
    /// target array under the following rules:
    ///
    /// Initially target array is empty.
    /// From left to right read nums[i] and index[i], insert at index index[i] 
    /// the value nums[i] in target array.
    /// Repeat the previous step until there are no elements to read in nums 
    /// and index.
    /// Return the target array.
    ///
    /// It is guaranteed that the insertion operations will be valid.
    ///
    /// Example 1:
    /// Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
    /// Output: [0,4,1,3,2]
    /// Explanation:
    /// nums       index     target
    /// 0            0        [0]
    /// 1            1        [0,1]
    /// 2            2        [0,1,2] 
    /// 3            2        [0,1,3,2]
    /// 4            1        [0,4,1,3,2]
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
    /// Output: [0,1,2,3,4]
    /// Explanation:
    /// nums       index     target
    /// 1            0        [1]
    /// 2            1        [1,2]
    /// 3            2        [1,2,3]
    /// 4            3        [1,2,3,4]
    /// 0            0        [0,1,2,3,4]
    ///
    /// Example 3:
    /// Input: nums = [1], index = [0]
    /// Output: [1]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length, index.length <= 100
    /// 2. nums.length == index.length
    /// 3. 0 <= nums[i] <= 100
    /// 4. 0 <= index[i] <= i
    /// </summary>
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index);

    /// <summary>
    /// Leet code #1395. Count Number of Teams
    /// 
    /// Medium
    ///
    /// There are n soldiers standing in a line. Each soldier is assigned a 
    /// unique rating value.
    ///
    /// You have to form a team of 3 soldiers amongst them under the following
    /// rules:
    ///
    /// Choose 3 soldiers with index (i, j, k) with rating (rating[i], 
    /// rating[j], rating[k]).
    /// A team is valid if:  (rating[i] < rating[j] < rating[k]) or 
    /// (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
    /// Return the number of teams you can form given the conditions. 
    /// (soldiers can be part of multiple teams).
    /// 
    /// Example 1:
    /// Input: rating = [2,5,3,4,1]
    /// Output: 3
    /// Explanation: We can form three teams given the conditions. 
    /// (2,3,4), (5,4,1), (5,3,1). 
    ///
    /// Example 2:
    /// Input: rating = [2,1,3]
    /// Output: 0
    /// Explanation: We can't form any team given the conditions.
    ///
    /// Example 3:
    /// Input: rating = [1,2,3,4]
    /// Output: 4
    ///
    /// Constraints:
    /// 1. n == rating.length
    /// 2. 1 <= n <= 200
    /// 3. 1 <= rating[i] <= 10^5
    /// </summary>
    int numTeams(vector<int>& rating);

    /// <summary>
    /// Leet code #1409. Queries on a Permutation With Key 
    /// 
    /// Medium
    ///
    /// Given the array queries of positive integers between 1 and m, 
    /// you have to process all queries[i] (from i=0 to 
    /// i=queries.length-1) according to the following rules:
    ///
    /// In the beginning, you have the permutation P=[1,2,3,...,m].
    /// For the current i, find the position of queries[i] in the 
    /// permutation P (indexing from 0) and then move this at the 
    /// beginning of the permutation P. Notice that the position of 
    /// queries[i] in P is the result for queries[i].
    /// Return an array containing the result for the given queries.
    /// 
    /// Example 1:
    /// Input: queries = [3,1,2,1], m = 5
    /// Output: [2,1,2,1] 
    /// Explanation: The queries are processed as follow: 
    /// For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, 
    /// then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
    /// For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, 
    /// then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
    /// For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, 
    /// then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
    /// For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, 
    /// then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
    /// Therefore, the array containing the result is [2,1,2,1].  
    ///
    /// Example 2:
    /// Input: queries = [4,1,2,2], m = 4
    /// Output: [3,1,2,0]
    ///
    /// Example 3:
    /// Input: queries = [7,5,5,8,3], m = 8
    /// Output: [6,5,0,7,5]
    ///
    /// Constraints:
    /// 1. 1 <= m <= 10^3
    /// 2. 1 <= queries.length <= m
    /// 3. 1 <= queries[i] <= m
    /// </summary>
    vector<int> processQueries(vector<int>& queries, int m);

    /// <summary>
    /// Leet code #1413. Minimum Value to Get Positive Step by Step Sum 
    /// 
    /// Easy
    ///
    /// Given an array of integers nums, you start with an initial positive 
    /// value startValue.
    ///
    /// In each iteration, you calculate the step by step sum of startValue 
    /// plus elements in nums (from left to right).
    ///
    /// Return the minimum positive value of startValue such that the step by 
    /// step sum is never less than 1.
    ///
    /// Example 1:
    /// Input: nums = [-3,2,-3,4,2]
    /// Output: 5
    /// Explanation: If you choose startValue = 4, in the third iteration your 
    /// step by step sum is less than 1.
    ///            step by step sum
    ///            startValue = 4 | startValue = 5 | nums
    ///              (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
    ///              (1 +2 ) = 3  | (2 +2 ) = 4    |   2
    ///              (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
    ///              (0 +4 ) = 4  | (1 +4 ) = 5    |   4
    ///              (4 +2 ) = 6  | (5 +2 ) = 7    |   2
    /// Example 2:
    /// Input: nums = [1,2]
    /// Output: 1
    /// Explanation: Minimum start value should be positive. 
    ///
    /// Example 3:
    /// Input: nums = [1,-2,-3]
    /// Output: 5
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. -100 <= nums[i] <= 100
    /// </summary>
    int minStartValue(vector<int>& nums);

    /// <summary>
    /// Leet code #1423. Maximum Points You Can Obtain from Cards
    /// 
    /// Medium
    ///
    /// There are several cards arranged in a row, and each card has an 
    /// associated number of points The points are given in the integer 
    /// array cardPoints.
    ///
    /// In one step, you can take one card from the beginning or from the 
    /// end of the row. You have to take exactly k cards.
    ///
    /// Your score is the sum of the points of the cards you have taken.
    ///
    /// Given the integer array cardPoints and the integer k, return 
    /// the maximum score you can obtain.
    ///
    /// Example 1:
    /// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    /// Output: 12
    /// Explanation: After the first step, your score will 
    /// always be 1. However, choosing the rightmost card first 
    /// will maximize your total score. The optimal strategy is 
    /// to take the three cards on the right, giving a final 
    /// score of 1 + 6 + 5 = 12.
    ///
    /// Example 2:
    /// Input: cardPoints = [2,2,2], k = 2
    /// Output: 4
    /// Explanation: Regardless of which two cards you take, your score will 
    /// always be 4.
    ///
    /// Example 3:
    /// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
    /// Output: 55
    /// Explanation: You have to take all the cards. Your score is the sum of 
    /// points of all cards.
    ///
    /// Example 4:
    /// Input: cardPoints = [1,1000,1], k = 1
    /// Output: 1
    /// Explanation: You cannot take the card in the middle. Your best score 
    /// is 1. 
    ///
    /// Example 5:
    /// Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
    /// Output: 202
    ///
    /// Constraints:
    /// 1. 1 <= cardPoints.length <= 10^5
    /// 2. 1 <= cardPoints[i] <= 10^4
    /// 3. 1 <= k <= cardPoints.length
    /// </summary>
    int maxScore(vector<int>& cardPoints, int k);

    /// <summary>
    /// Leet code #1424. Diagonal Traverse II
    /// 
    /// Medium
    ///
    /// Given a list of lists of integers, nums, return all elements of nums 
    /// in diagonal order as shown in the below images.
    /// 
    /// Example 1:
    /// Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
    /// Output: [1,4,2,7,5,3,8,6,9]
    ///
    /// Example 2:
    /// Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
    /// Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
    ///
    /// Example 3:
    /// Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
    /// Output: [1,4,2,5,3,8,6,9,7,10,11]
    ///
    /// Example 4:
    /// Input: nums = [[1,2,3,4,5,6]]
    /// Output: [1,2,3,4,5,6]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i].length <= 10^5
    /// 3. 1 <= nums[i][j] <= 10^9
    /// 4. There at most 10^5 elements in nums.
    /// </summary>
    vector<int> findDiagonalOrder(vector<vector<int>>& nums);

    /// <summary>
    /// Leet code #1431. Kids With the Greatest Number of Candies
    /// 
    /// Easy
    ///
    /// Given the array candies and the integer extraCandies, where candies[i] 
    /// represents the number of candies that the ith kid has.
    ///
    /// For each kid check if there is a way to distribute extraCandies among 
    /// the kids such that he or she can have the greatest number of candies 
    /// among them. Notice that multiple kids can have the greatest number of 
    /// candies.
    ///
    /// Example 1:
    /// Input: candies = [2,3,5,1,3], extraCandies = 3
    /// Output: [true,true,true,false,true] 
    /// Explanation: 
    /// Kid 1 has 2 candies and if he or she receives all extra candies (3) 
    /// will have 5 candies --- the greatest number of candies among the kids. 
    /// Kid 2 has 3 candies and if he or she receives at least 2 extra candies 
    /// will have the greatest number of candies among the kids. 
    /// Kid 3 has 5 candies and this is already the greatest number of candies 
    /// among the kids. 
    /// Kid 4 has 1 candy and even if he or she receives all extra candies will
    /// only have 4 candies. 
    /// Kid 5 has 3 candies and if he or she receives at least 2 extra candies 
    /// will have the greatest number of candies among the kids. 
    ///
    /// Example 2:
    /// Input: candies = [4,2,1,1,2], extraCandies = 1
    /// Output: [true,false,false,false,false] 
    /// Explanation: There is only 1 extra candy, therefore only kid 1 will 
    /// have the greatest number of candies among the kids regardless of who 
    /// takes the extra candy.
    ///
    /// Example 3:
    /// Input: candies = [12,1,12], extraCandies = 10
    /// Output: [true,false,true]
    /// Constraints:
    /// 1. 2 <= candies.length <= 100
    /// 2. 1 <= candies[i] <= 100
    /// 3. 1 <= extraCandies <= 50
    /// </summary>
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

    /// <summary>
    /// Leet code #1437. Check If All 1's Are at Least Length K Places Away
    /// 
    /// Medium
    ///
    /// Given an array nums of 0s and 1s and an integer k, return True if 
    /// all 1's are at least k places away from each other, otherwise return 
    /// False.
    ///
    /// Example 1:
    /// Input: nums = [1,0,0,0,1,0,0,1], k = 2
    /// Output: true
    /// Explanation: Each of the 1s are at least 2 places away from each 
    /// other.
    ///
    /// Example 2:
    /// Input: nums = [1,0,0,1,0,1], k = 2
    /// Output: false
    /// Explanation: The second 1 and third 1 are only one apart from each 
    /// other.
    ///
    /// Example 3:
    /// Input: nums = [1,1,1,1,1], k = 0
    /// Output: true
    ///
    /// Example 4:
    /// Input: nums = [0,1,0,1], k = 1
    /// Output: true
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= k <= nums.length
    /// 3. nums[i] is 0 or 1
    /// </summary>
    bool kLengthApart(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #1438. Longest Continuous Subarray With Absolute Diff 
    ///                  Less Than or Equal to Limit
    /// 
    /// Medium
    ///
    /// Given an array of integers nums and an integer limit, return the 
    /// size of the longest continuous subarray such that the absolute 
    /// difference between any two elements is less than or equal to limit.
    ///
    /// In case there is no subarray satisfying the given condition return 0.
    ///
    /// Example 1:
    /// Input: nums = [8,2,4,7], limit = 4
    /// Output: 2 
    /// Explanation: All subarrays are: 
    /// [8] with maximum absolute diff |8-8| = 0 <= 4.
    /// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
    /// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
    /// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
    /// [2] with maximum absolute diff |2-2| = 0 <= 4.
    /// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
    /// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
    /// [4] with maximum absolute diff |4-4| = 0 <= 4.
    /// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
    /// [7] with maximum absolute diff |7-7| = 0 <= 4. 
    /// Therefore, the size of the longest subarray is 2.
    ///
    /// Example 2:
    /// Input: nums = [10,1,2,4,7,2], limit = 5
    /// Output: 4 
    /// Explanation: The subarray [2,4,7,2] is the longest since the maximum 
    /// absolute diff is |2-7| = 5 <= 5.
    ///
    /// Example 3:
    /// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
    /// Output: 3
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 0 <= limit <= 10^9
    /// </summary>
    int longestSubarray(vector<int>& nums, int limit);

    /// <summary>
    /// Leet code #1441. Build an Array With Stack Operations
    ///
    /// Easy
    ///
    /// Given an array target and an integer n. In each iteration, you will read 
    /// a number from  list = {1,2,3..., n}.
    ///
    /// Build the target array using the following operations:
    ///
    /// Push: Read a new element from the beginning list, and push it in the array.
    /// Pop: delete the last element of the array.
    /// If the target array is already built, stop reading more elements.
    /// You are guaranteed that the target array is strictly increasing, only 
    /// containing numbers between 1 to n inclusive.
    ///
    /// Return the operations to build the target array.
    ///
    /// You are guaranteed that the answer is unique.
    /// 
    /// Example 1:
    ///
    /// Input: target = [1,3], n = 3
    /// Output: ["Push","Push","Pop","Push"]
    /// Explanation: 
    /// Read number 1 and automatically push in the array -> [1]
    /// Read number 2 and automatically push in the array then Pop it -> [1]
    /// Read number 3 and automatically push in the array -> [1,3]
    ///
    /// Example 2:
    /// Input: target = [1,2,3], n = 3
    /// Output: ["Push","Push","Push"]
    ///
    /// Example 3:
    /// Input: target = [1,2], n = 4
    /// Output: ["Push","Push"]
    /// Explanation: You only need to read the first 2 numbers and stop.
    ///
    /// Example 4:
    /// Input: target = [2,3,4], n = 4
    /// Output: ["Push","Pop","Push","Push","Push"]
    /// 
    /// Constraints:
    /// 1. 1 <= target.length <= 100
    /// 2. 1 <= target[i] <= 100
    /// 3. 1 <= n <= 100
    /// 4. target is strictly increasing.
    /// </summary>
    vector<string> buildArray(vector<int>& target, int n);

    /// <summary>
    /// Leet code #1442. Count Triplets That Can Form Two Arrays of Equal XOR
    ///
    /// Medium
    ///
    /// Given an array of integers arr.
    ///
    /// We want to select three indices i, j and k where 
    /// (0 <= i < j <= k < arr.length).
    ///
    /// Let's define a and b as follows:
    ///
    /// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
    /// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
    /// Note that ^ denotes the bitwise-xor operation.
    ///
    /// Return the number of triplets (i, j and k) Where a == b.
    /// 
    /// Example 1:
    /// Input: arr = [2,3,1,6,7]
    /// Output: 4
    /// Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
    ///
    /// Example 2:
    /// Input: arr = [1,1,1,1,1]
    /// Output: 10
    ///
    /// Example 3:
    /// Input: arr = [2,3]
    /// Output: 0
    ///
    /// Example 4:
    /// Input: arr = [1,3,5,7,9]
    /// Output: 3
    ///
    /// Example 5:
    /// Input: arr = [7,11,12,9,5,2,7,17,22]
    /// Output: 8
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 300
    /// 2. 1 <= arr[i] <= 10^8
    /// </summary>
    int countTriplets(vector<int>& arr);

    /// <summary>
    /// Leet code #1450. Number of Students Doing Homework at a Given Time
    /// 
    /// Easy
    ///
    /// Given two integer arrays startTime and endTime and given an integer 
    /// queryTime.
    /// 
    /// The ith student started doing their homework at the time startTime[i] 
    /// and finished it at time endTime[i].
    ///
    /// Return the number of students doing their homework at time queryTime. 
    /// More formally, return the number of students where queryTime lays in 
    /// the interval [startTime[i], endTime[i]] inclusive.
    /// 
    /// Example 1:
    /// Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
    /// Output: 1
    /// Explanation: We have 3 students where:
    /// The first student started doing homework at time 1 and finished at 
    /// time 3 and wasn't doing anything at time 4.
    /// The second student started doing homework at time 2 and finished at 
    /// time 2 and also wasn't doing anything at time 4.
    /// The third student started doing homework at time 3 and finished at 
    /// time 7 and was the only student doing homework at time 4.
    ///
    /// Example 2:
    /// Input: startTime = [4], endTime = [4], queryTime = 4
    /// Output: 1
    /// Explanation: The only student was doing their homework at the 
    /// queryTime.
    ///
    /// Example 3:
    /// Input: startTime = [4], endTime = [4], queryTime = 5
    /// Output: 0
    ///
    /// Example 4:
    /// Input: startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
    /// Output: 0
    ///
    /// Example 5:
    /// Input: startTime = [9,8,7,6,5,4,3,2,1], 
    /// endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
    /// Output: 5
    ///
    /// Constraints:
    /// 1. startTime.length == endTime.length
    /// 2. 1 <= startTime.length <= 100
    /// 3. 1 <= startTime[i] <= endTime[i] <= 1000
    /// 4. 1 <= queryTime <= 1000
    /// </summary>
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime);

#pragma endregion
};
#endif  // LeetCodeArray_H
