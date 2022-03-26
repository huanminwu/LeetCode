#pragma once
#ifndef LeetcodeDP_H
#define LeetCodeDP_H
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
class LeetCodeDP
{
public:
    /// <summary>
    /// Leet code #5. Longest Palindromic Substring 
    /// Given a string S, find the longest palindromic substring in S. 
    /// You may assume that the maximum length of S is 1000, 
    ///  and there exists one unique longest palindromic substring
    /// </summary>
    string longestPalindrome(string s);

    /// <summary>
    /// Leet Code 45. Jump Game II
    ///                                                                 
    /// Medium
    ///
    /// Given an array of non-negative integers nums, you are initially 
    /// positioned at the first index of the array.
    ///
    /// Each element in the array represents your maximum jump length at that 
    /// position.
    ///
    /// Your goal is to reach the last index in the minimum number of jumps.
    ///
    /// You can assume that you can always reach the last index.
    ///
    /// Example 1:
    /// Input: nums = [2,3,1,1,4]
    /// Output: 2
    /// Explanation: The minimum number of jumps to reach the last index is 2. 
    /// Jump 1 step from index 0 to 1, then 3 steps to the last index.
    ///
    /// Example 2:
    /// Input: nums = [2,3,0,1,4]
    /// Output: 2
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^4
    /// 2. 0 <= nums[i] <= 1000
    /// </summary>
    int jump(vector<int>& nums);

    /// <summary>
    /// Leet code #264. Ugly Number II
    /// 
    /// Write a program to find the n-th ugly number.
    ///
    /// Ugly numbers are positive numbers whose prime factors only 
    /// include 2, 3, 5. 
    ///
    /// Example:
    ///
    /// Input: n = 10
    /// Output: 12
    /// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of 
    /// the first 10 ugly numbers.
    /// Note:  
    ///
    /// 1. 1 is typically treated as an ugly number.
    /// 2. n does not exceed 1690.
    /// </summary>
    int nthUglyNumber(int n);

    /// <summary>
    /// LeetCode #120. Triangle   
    /// Given a triangle, find the minimum path sum from top to bottom. 
    /// Each step you may move to adjacent numbers on the row below.
    /// For example, given the following triangle
    /// [
    ///     [2],
    ///    [3,4],
    ///   [6,5,7],
    ///  [4,1,8,3]
    /// ]
    /// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
    /// Note:
    /// Bonus point if you are able to do this using only O(n) extra space, 
    /// where n is the total number of rows in the triangle. 
    /// </summary>
    int minimumTotal(vector<vector<int>>& triangle);

    /// <summary>
    /// Leet code #279. Perfect Squares 
    /// Given a positive integer n, find the least number of perfect square numbers 
    /// (for example, 1, 4, 9, 16, ...) which sum to n.
    /// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; 
    /// given n = 13, return 2 because 13 = 4 + 9. 
    /// </summary>
    int numSquares(int n);

    /// <summary>
    /// Leet Code 276. Paint Fence
    ///                                                                 
    /// Medium
    ///
    /// You are painting a fence of n posts with k different colors. You must 
    /// paint the posts following these rules:
    ///
    /// Every post must be painted exactly one color.
    /// There cannot be three or more consecutive posts with the same color.
    /// Given the two integers n and k, return the number of ways you can paint
    /// the fence.
    ///
    /// Example 1:
    /// Input: n = 3, k = 2
    /// Output: 6
    /// Explanation: All the possibilities are shown.
    /// Note that painting all the posts red or all the posts green is invalid 
    /// because there cannot be three posts in a row with the same color.
    ///
    /// Example 2:
    /// Input: n = 1, k = 1
    /// Output: 1
    ///
    /// Example 3:
    /// Input: n = 7, k = 2
    /// Output: 42
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 50
    /// 2. 1 <= k <= 10^5
    /// 3. The testcases are generated such that the answer is in the range 
    ///    [0, 2^31 - 1] for the given n and k.
    /// </summary>
    int numWaysPaintFence(int n, int k);

    /// <summary>
    /// Leet code #256. Paint House 
    /// 
    /// There are a row of n houses, each house can be painted with one of 
    /// the three colors: red, blue or green. The cost of painting each house 
    /// with a certain color is different. You have to paint all the houses 
    /// such that no two adjacent houses have the same color. 
    /// The cost of painting each house with a certain color is represented 
    /// by a n x 3 cost matrix. For example, costs[0][0] is the cost of 
    /// painting house 0 with color red; costs[1][2] is the cost of painting 
    /// house 1 with color green, and so on...
    /// Find the minimum cost to paint all houses. 
    /// Note:
    /// All costs are positive integers.
    /// </summary>
    int minCost(vector<vector<int>>& costs);

    /// <summary>
    /// Leet code #265. Paint House II
    /// 
    /// Hard
    ///
    /// There are a row of n houses, each house can be painted with one of the k 
    /// colors. The cost of painting each house with a certain color is different. 
    /// You have to paint all the houses such that no two adjacent houses have 
    /// the same color.
    ///
    /// The cost of painting each house with a certain color is represented by 
    /// a n x k cost matrix. For example, costs[0][0] is the cost of painting 
    /// house 0 with color 0; costs[1][2] is the cost of painting house 1 with 
    /// color 2, and so on... Find the minimum cost to paint all houses.
    ///
    /// Note:
    /// All costs are positive integers.
    ///
    /// Example:
    ///
    /// Input: [[1,5,3],[2,9,4]]
    /// Output: 5
    /// Explanation: Paint house 0 into color 0, paint house 1 into color 2. 
    /// Minimum cost: 1 + 4 = 5; Or paint house 0 into color 2, paint house 1 
    /// into color 0. Minimum cost: 3 + 2 = 5. 
    /// Follow up:
    /// Could you solve it in O(nk) runtime?
    /// </summary>
    int minCostII(vector<vector<int>>& costs);

    /// <summary>
    /// Leet Code 121. Best Time to Buy and Sell Stock
    ///                                                                 
    /// Easy
    ///
    /// You are given an array prices where prices[i] is the price of a given 
    /// stock on the ith day.
    ///
    /// You want to maximize your profit by choosing a single day to buy one 
    /// stock and choosing a different day in the future to sell that stock.
    ///
    /// Return the maximum profit you can achieve from this transaction. If 
    /// you cannot achieve any profit, return 0.
    ///
    ///
    /// Example 1:
    /// Input: prices = [7,1,5,3,6,4]
    /// Output: 5
    /// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), 
    /// profit = 6-1 = 5.
    /// Note that buying on day 2 and selling on day 1 is not allowed because 
    /// you must buy before you sell.
    ///
    /// Example 2:
    /// Input: prices = [7,6,4,3,1]
    /// Output: 0
    /// Explanation: In this case, no transactions are done and the max 
    /// profit = 0.
    /// 
    /// Constraints:
    /// 1. 1 <= prices.length <= 10^5
    /// 2. 0 <= prices[i] <= 10^4
    /// </summary>
    int maxProfitOneTxn(vector<int>& prices);

    /// <summary>
    /// Leet Code 122. Best Time to Buy and Sell Stock II
    ///                                                                 
    /// Medium
    ///
    /// You are given an integer array prices where prices[i] is the price of 
    /// a given stock on the ith day.
    ///
    /// On each day, you may decide to buy and/or sell the stock. You can only 
    /// hold at most one share of the stock at any time. However, you can buy
    /// it then immediately sell it on the same day.
    ///
    /// Find and return the maximum profit you can achieve.
    /// 
    /// Example 1:
    /// Input: prices = [7,1,5,3,6,4]
    /// Output: 7
    /// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), 
    /// profit = 5-1 = 4.
    /// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), 
    /// profit = 6-3 = 3.
    /// Total profit is 4 + 3 = 7.
    ///
    /// Example 2:
    /// Input: prices = [1,2,3,4,5]
    /// Output: 4
    /// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), 
    /// profit = 5-1 = 4.
    /// Total profit is 4.
    ///
    /// Example 3:
    /// Input: prices = [7,6,4,3,1]
    /// Output: 0
    /// Explanation: There is no way to make a positive profit, so we never buy the 
    /// stock to achieve the maximum profit of 0.
    /// 
    /// Constraints:
    /// 1. 1 <= prices.length <= 3 * 10^4
    /// 2. 0 <= prices[i] <= 10^4
    /// </summary>
    int maxProfitManyTxns(vector<int>& prices);

    /// <summary>
    /// Leet code #188. Best Time to Buy and Sell Stock IV  
    /// Say you have an array for which the ith element is the price of a given stock on day i.
    /// Design an algorithm to find the maximum profit. You may complete at most k transactions.
    /// Note:
    /// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    /// </summary>
    int maxProfitKTxns(int k, vector<int>& prices);

    /// <summary>
    /// Leet code # 309. Best Time to Buy and Sell Stock with Cooldown 
    ///
    /// Say you have an array for which the ith element is the price of a given stock on day i.
    ///
    /// Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
    /// (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
    /// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    /// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
    /// 
    /// Example:
    /// prices = [1, 2, 3, 0, 2] 
    /// maxProfit = 3
    /// transactions = [buy, sell, cooldown, buy, sell]
    /// </summary>
    int maxProfit(vector<int>& prices);

    /// <summary>
    /// Leet code #198. House Robber
    ///
    /// You are a professional robber planning to rob houses along a street. 
    /// Each house has a certain amount of money stashed, the only constraint 
    /// stopping you from robbing each of them is that adjacent houses have 
    /// security system connected and it will automatically contact the police 
    /// if two adjacent houses were broken into on the same night.
    /// Given a list of non-negative integers representing the amount of money 
    /// of each house, determine the maximum amount of money you can rob 
    /// tonight without alerting the police.
    /// </summary>
    int rob(vector<int>& nums);

    /// <summary>
    /// Leet code #96. Unique Binary Search Trees    
    /// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?  
    /// For example,
    /// Given n = 3, there are a total of 5 unique BST's.
    ///   1         3     3      2      1
    ///    \       /     /      / \      \
    ///     3     2     1      1   3      2
    ///    /     /       \                 \
    ///   2     1         2                 3
    /// </summary>
    int numTrees(int n);

    /// <summary>
    /// Leet code #313. Super Ugly Number
    /// 
    /// Write a program to find the nth super ugly number.
    ///
    /// Super ugly numbers are positive numbers whose all prime factors 
    /// are in the given prime list primes of size k.
    ///
    /// Example:
    ///
    /// Input: n = 12, primes = [2,7,13,19]
    /// Output: 32 
    /// Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the
    /// first 12 super ugly numbers given primes = [2,7,13,19] of size 4. 
    /// Note:
    ///
    /// 1. 1 is a super ugly number for any given primes.
    /// 2. The given numbers in primes are in ascending order.
    /// 3. 0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.
    /// 4. The nth super ugly number is guaranteed to fit in a 32-bit signed 
    ///    integer.
    /// </summary>
    int nthSuperUglyNumber(int n, vector<int>& primes);

    /// <summary>
    /// Leet code #403. Frog Jump
    /// 
    /// A frog is crossing a river. The river is divided into x units and at 
    /// each unit there may or may not exist a stone. The frog can jump on a 
    /// stone, but it must not jump into the water.
    ///
    /// Given a list of stones' positions (in units) in sorted ascending order, 
    /// determine if the frog is able to cross the river by landing on the 
    /// last stone. Initially, the frog is on the first stone and assume the 
    /// first jump must be 1 unit.
    ///
    /// If the frog's last jump was k units, then its next jump must be either 
    /// k - 1, k, or k + 1 units. Note that the frog can only jump in the 
    /// forward direction.
    ///
    /// Note:
    ///
    /// The number of stones is ¡Ý 2 and is < 1,100.
    /// Each stone's position will be a non-negative integer < 231.
    /// The first stone's position is always 0.
    ///
    /// Example 1:
    ///
    /// [0,1,3,5,6,8,12,17]
    ///
    /// There are a total of 8 stones.
    /// The first stone at the 0th unit, second stone at the 1st unit,
    /// third stone at the 3rd unit, and so on...
    /// The last stone at the 17th unit.
    /// 
    /// Return true. The frog can jump to the last stone by jumping 
    /// 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
    /// 2 units to the 4th stone, then 3 units to the 6th stone, 
    /// 4 units to the 7th stone, and 5 units to the 8th stone.
    ///
    /// Example 2:
    ///
    /// [0,1,2,3,4,8,9,11]
    ///
    /// Return false. There is no way to jump to the last stone as 
    /// the gap between the 5th and 6th stone is too large.
    /// </summary>
    bool canCross(vector<int>& stones);

    /// <summary>
    /// Leet code #494. Target Sum   
    /// 
    /// You are given a list of non-negative integers, a1, a2, ..., an, and a 
    /// target, S. 
    /// Now you have 2 symbols + and -. For each integer, you should choose one 
    /// from + and - as its new symbol. 
    /// Find out how many ways to assign symbols to make sum of integers equal 
    /// to target S. 
    /// Example 1:
    /// Input: nums is [1, 1, 1, 1, 1], S is 3. 
    /// Output: 5
    /// Explanation: 
    ///
    /// -1+1+1+1+1 = 3
    /// +1-1+1+1+1 = 3
    /// +1+1-1+1+1 = 3
    /// +1+1+1-1+1 = 3
    /// +1+1+1+1-1 = 3
    /// 
    /// There are 5 ways to assign symbols to make the sum of nums be target 3.
    ///  
    /// Note:
    /// 1.The length of the given array is positive and will not exceed 20. 
    /// 2.The sum of elements in the given array will not exceed 1000.
    /// 3.Your output answer is guaranteed to be fitted in a 32-bit integer.
    /// </summary>
    int findTargetSumWays(vector<int>& nums, int S);

    /// <summary>
    /// Leet code #514. Freedom Trail
    /// 
    /// In the video game Fallout 4, the quest "Road to Freedom" requires 
    /// players to reach a metal dial called the "Freedom Trail Ring", and 
    /// use the dial to spell a specific keyword in order to open the door.
    ///
    /// Given a string ring, which represents the code engraved on the outer 
    /// ring and another string key, which represents the keyword needs to be 
    /// spelled. You need to find the minimum number of steps in order to 
    /// spell all the characters in the keyword.
    ///
    /// Initially, the first character of the ring is aligned at 12:00 
    /// direction. You need to spell all the characters in the string key one 
    /// by one by rotating the ring clockwise or anticlockwise to make each 
    /// character of the string key aligned at 12:00 direction and then by 
    /// pressing the center button.
    ///
    /// At the stage of rotating the ring to spell the key character key[i]:
    ///
    /// You can rotate the ring clockwise or anticlockwise one place, which 
    /// counts as 1 step. The final purpose of the rotation is to align one 
    /// of the string ring's characters at the 12:00 direction, where this 
    /// character must equal to the character key[i].
    /// If the character key[i] has been aligned at the 12:00 direction, you 
    /// need to press the center button to spell, which also counts as 1 step. 
    /// After the pressing, you could begin to spell the next character in the 
    /// key (next stage), otherwise, you've finished all the spelling.
    ///
    /// Example:
    /// Input: ring = "godding", key = "gd"
    /// Output: 4
    /// Explanation:
    /// For the first key character 'g', since it is already in place, we just 
    /// need 1 step to spell this character. 
    /// For the second key character 'd', we need to rotate the ring "godding" 
    /// anticlockwise by two steps to make it become "ddinggo".
    /// Also, we need 1 more step for spelling.
    /// So the final output is 4.
    ///
    /// Note:
    /// 1. Length of both ring and key will be in range 1 to 100.
    /// 2. There are only lowercase letters in both strings and might be some 
    ///    duplcate characters in both strings.
    /// 3. It's guaranteed that string key could always be spelled by rotating 
    ///    the string ring.
    /// </summary>
    int findRotateSteps(string ring, string key);

    /// <summary>
    /// Leet code #518. Coin Change 2
    /// 
    /// You are given coins of different denominations and a total amount of 
    /// money. Write a function to compute the number of combinations that 
    /// make up that amount. You may assume that you have infinite number of 
    /// each kind of coin.
    ///
    /// Note: You can assume that
    ///
    /// 1. 0 <= amount <= 5000
    /// 2. 1 <= coin <= 5000
    /// 3. the number of coins is less than 500
    /// 4. the answer is guaranteed to fit into signed 32-bit integer
    /// 
    /// Example 1:
    /// Input: amount = 5, coins = [1, 2, 5]
    /// Output: 4
    /// Explanation: there are four ways to make up the amount:
    /// 5=5
    /// 5=2+2+1
    /// 5=2+1+1+1
    /// 5=1+1+1+1+1
    /// 
    ///
    /// Example 2:
    /// Input: amount = 3, coins = [2]
    /// Output: 0
    /// Explanation: the amount of 3 cannot be made up just with coins of 2.
    /// 
    ///
    /// Example 3:
    /// Input: amount = 10, coins = [10] 
    /// Output: 1
    /// </summary>
    int change(int amount, vector<int>& coins);

    /// <summary>
    /// Leet code #879. Profitable Schemes
    /// 
    /// There are G people in a gang, and a list of various crimes they could 
    /// commit.
    ///
    /// The i-th crime generates a profit[i] and requires group[i] gang 
    /// members to participate.
    ///
    /// If a gang member participates in one crime, that member can't 
    /// participate in another crime.
    ///
    /// Let's call a profitable scheme any subset of these crimes that 
    /// generates at least P profit, and the total number of gang members 
    /// participating in that subset of crimes is at most G.
    ///
    /// How many schemes can be chosen?  Since the answer may be very large, 
    /// return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: G = 5, P = 3, group = [2,2], profit = [2,3]
    /// Output: 2
    /// Explanation: 
    /// To make a profit of at least 3, the gang could either commit crimes 
    /// 0 and 1, or just crime 1.
    /// In total, there are 2 schemes.
    ///
    /// Example 2:
    ///
    /// Input: G = 10, P = 5, group = [2,3,5], profit = [6,7,8]
    /// Output: 7
    /// Explanation: 
    /// To make a profit of at least 5, the gang could commit any crimes, as 
    /// long as they commit one.
    /// There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and 
    /// (0,1,2).
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= G <= 100
    /// 2. 0 <= P <= 100
    /// 3. 1 <= group[i] <= 100
    /// 4. 0 <= profit[i] <= 100
    /// 5. 1 <= group.length = profit.length <= 100
    /// </summary>
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit);

    /// <summary>
    /// Leet code #1143. Longest Common Subsequence
    /// 
    /// Given two strings text1 and text2, return the length of their longest 
    /// common subsequence.
    ///
    /// A subsequence of a string is a new string generated from the original 
    /// string with some characters(can be none) deleted without changing the 
    /// relative order of the remaining characters. (eg, "ace" is a 
    /// subsequence of "abcde" while "aec" is not). A common subsequence of 
    /// two strings is a subsequence that is common to both strings.
    /// 
    /// If there is no common subsequence, return 0.
    /// 
    /// Example 1:
    /// Input: text1 = "abcde", text2 = "ace" 
    /// Output: 3  
    /// Explanation: The longest common subsequence is "ace" and its length is 3.
    ///
    /// Example 2:
    /// Input: text1 = "abc", text2 = "abc"
    /// Output: 3
    /// Explanation: The longest common subsequence is "abc" and its length is 3.
    ///
    /// Example 3:
    /// Input: text1 = "abc", text2 = "def"
    /// Output: 0
    /// Explanation: There is no such common subsequence, so the result is 0.
    /// 
    ///
    /// Constraints:
    /// 1. 1 <= text1.length <= 1000
    /// 2. 1 <= text2.length <= 1000
    /// 3. The input strings consist of lowercase English characters only.
    /// </summary>
    int longestCommonSubsequence(string text1, string text2);

    /// <summary>
    /// Leet code #1147. Longest Chunked Palindrome Decomposition
    /// 
    /// Return the largest possible k such that there exists a_1, a_2, ..., a_k
    /// such that:
    ///
    /// Each a_i is a non-empty string;
    /// Their concatenation a_1 + a_2 + ... + a_k is equal to text;
    /// For all 1 <= i <= k,  a_i = a_{k+1 - i}.
    /// 
    /// Example 1:
    /// Input: text = "ghiabcdefhelloadamhelloabcdefghi"
    /// Output: 7
    /// Explanation: We can split the string on 
    /// "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
    ///
    /// Example 2:
    /// Input: text = "merchant"
    /// Output: 1
    /// Explanation: We can split the string on "(merchant)".
    ///
    /// Example 3:
    /// Input: text = "antaprezatepzapreanta"
    /// Output: 11
    /// Explanation: We can split the string on 
    /// "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".
    ///
    /// Example 4:
    /// Input: text = "aaa"
    /// Output: 3
    /// Explanation: We can split the string on "(a)(a)(a)".
    /// 
    /// Constraints:
    /// 1. text consists only of lowercase English characters.
    /// 2. 1 <= text.length <= 1000
    /// </summary>
    int longestDecomposition(string text);

    /// <summary>
    /// Leet code #1155. Number of Dice Rolls With Target Sum
    /// 
    /// You have d dice, and each die has f faces numbered 1, 2, ..., f.
    /// Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 
    /// to roll the dice so the sum of the face up numbers equals target.
    /// 
    /// Example 1:
    /// Input: d = 1, f = 6, target = 3
    /// Output: 1
    /// Explanation: 
    /// You throw one dice with 6 faces.  There is only one way to get a sum of 3.
    ///
    /// Example 2:
    /// Input: d = 2, f = 6, target = 7
    /// Output: 6
    /// Explanation: 
    /// You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
    /// 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
    ///
    /// Example 3:
    /// Input: d = 2, f = 5, target = 10
    /// Output: 1
    /// Explanation: 
    /// You throw two dice, each with 5 faces.  There is only one way to get a sum of 
    /// 10: 5+5.
    ///
    /// Example 4:
    /// Input: d = 1, f = 2, target = 3
    /// Output: 0
    /// Explanation: 
    /// You throw one die with 2 faces.  There is no way to get a sum of 3.
    ///
    /// Example 5:
    /// Input: d = 30, f = 30, target = 500
    /// Output: 222616187
    /// Explanation: 
    /// The answer must be returned modulo 10^9 + 7.
    ///
    /// Constraints:
    /// 1. 1 <= d, f <= 30
    /// 2. 1 <= target <= 1000
    /// </summary>
    int numRollsToTarget(int d, int f, int target);

    /// <summary>
    /// Leet code #1187. Make Array Strictly Increasing
    /// 
    /// Given two integer arrays arr1 and arr2, return the minimum number of 
    /// operations (possibly zero) needed to make arr1 strictly increasing.
    /// In one operation, you can choose two indices 0 <= i < arr1.length and 
    /// 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
    /// If there is no way to make arr1 strictly increasing, return -1.
    /// 
    /// Example 1:
    /// Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
    /// Output: 1
    /// Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
    ///
    /// Example 2:
    /// Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
    /// Output: 2
    /// Explanation: Replace 5 with 3 and then replace 3 with 4. 
    /// arr1 = [1, 3, 4, 6, 7].
    ///
    /// Example 3:
    /// Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
    /// Output: -1
    /// Explanation: You can't make arr1 strictly increasing.
    ///
    /// Constraints:
    /// 1. 1 <= arr1.length, arr2.length <= 2000
    /// 2. 0 <= arr1[i], arr2[i] <= 10^9
    /// </summary>
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2);

    /// <summary>
    /// Leet code #9905. Maximum Interest
    /// 
    /// There are a series of activities with [startTime, endTime, interest]. 
    /// Please arrange the activities to get the maximum total interest.
    ///
    /// Note: You can assume that
    ///
    /// 1. 0 <= startTime < endTime <= 500000
    /// 2. 1 <= interest <= 1000
    /// 
    /// Example 1:
    /// Input: activities = [0,3,1][0,5,5][5,6,1][6,18,2]
    /// Output: 8
    /// Explanation: with [0, 5, 5] => [5, 6, 1] => [6, 8, 2]
    /// 5 + 1 + 2 = 8
    ///
    /// Example 2:
    /// Input: activities = {{8, 9, 5}, {8, 12, 7}, {9, 12, 4}, {12, 14, 2}, 
    ///                      {13, 16, 3}, {14, 15, 4}};
    /// Output: 15
    /// Explanation: {8, 9, 5} => {9, 12 , 4} => {12, 14, 2} => {14, 15, 4}
    ///
    /// Example 3:
    /// Input: activities = {{8, 10, 3}, {9, 12, 2}, {12, 14, 1}}; 
    /// Output: 4
    /// Explanation: {8, 10, 3} => {12, 14, 1}
    /// </summary>
    int maxInterest(vector<vector<int>> activities);

    /// <summary>
    /// Leet code #562. Longest Line of Consecutive One in Matrix
    /// Given a 01 matrix M, find the longest line of consecutive one in the 
    /// matrix. The line could be horizontal, vertical, diagonal or 
    /// anti-diagonal. 
    /// 
    /// Example:
    /// 
    /// Input:
    /// [
    ///   [0,1,1,0],
    ///   [0,1,1,0],
    ///   [0,0,0,1]
    /// ]
    /// Output: 3
    /// Hint: The number of elements in the given matrix will not exceed 10,000. 
    /// </summary>
    int longestLine(vector<vector<int>>& M);

    /// <summary>
    /// Leet code #213. House Robber II
    /// 
    /// You are a professional robber planning to rob houses along a street. 
    /// Each house has a certain amount of money stashed. All houses at this 
    /// place are arranged in a circle. That means the first house is the 
    /// neighbor of the last one. Meanwhile, adjacent houses have security 
    /// system connected and it will automatically contact the police if two 
    /// adjacent houses were broken into on the same night.
    ///
    /// Given a list of non-negative integers representing the amount of money 
    /// of each house, determine the maximum amount of money you can rob 
    /// tonight without alerting the police.
    ///
    /// Example 1:
    ///
    /// Input: [2,3,2]
    /// Output: 3
    /// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 
    /// (money = 2), because they are adjacent houses.
    ///
    /// Example 2:
    /// 
    /// Input: [1,2,3,1]
    /// Output: 4
    /// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    /// Total amount you can rob = 1 + 3 = 4.
    /// </summary>
    int robII(vector<int>& nums);

    /// <summary>
    /// Leet code #118. Pascal's Triangle 
    /// Given numRows, generate the first numRows of Pascal's triangle.
    /// For example, given numRows = 5,
    ///
    /// Return 
    /// [
    ///     [1],
    ///    [1,1],
    ///   [1,2,1],
    ///  [1,3,3,1],
    /// [1,4,6,4,1]
    /// ]
    /// </summary>
    vector<vector<int>> generatePascalTriangle(int numRows);

    /// <summary>
    /// Leet code #119. Pascal's Triangle II 
    /// Given an index k, return the kth row of the Pascal's triangle.
    /// For example, given k = 3,
    /// Return [1,3,3,1]. 
    /// Note:
    /// Could you optimize your algorithm to use only O(k) extra space? 
    /// </summary>
    vector<int> getPascalTriangleRow(int rowIndex);

    /// <summary>
    /// Leet code #322. Coin Change 
    /// You are given coins of different denominations and a total amount 
    /// of money amount. Write a function to 
    /// compute the fewest number of coins that you need to make up that 
    /// amount. If that amount of money cannot 
    /// be made up by any combination of the coins, return -1. 	
    /// Example 1:
    /// coins = [1, 2, 5], amount = 11
    /// return 3 (11 = 5 + 5 + 1) 
    /// Example 2:
    /// coins = [2], amount = 3
    /// return -1. 
    /// Note:
    /// You may assume that you have an infinite number of each kind of coin. 
    /// </summary>
    int coinChange(vector<int>& coins, int amount);

    /// <summary>
    /// Leet code 91. Decode Ways 
    ///
    /// A message containing letters from A-Z is being encoded to numbers using 
    /// the following mapping:
    ///
    /// 'A' -> 1
    /// 'B' -> 2
    /// ...
    /// 'Z' -> 26
    /// Given a non-empty string containing only digits, determine the total 
    /// number of ways to decode it.
    ///
    /// Example 1:
    ///
    /// Input: "12"
    /// Output: 2
    /// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
    ///
    /// Example 2:
    ///
    /// Input: "226"
    /// Output: 3
    /// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" 
    /// (2 2 6).
    /// </summary>
    int numDecodings(string s);

    /// <summary>
    /// Leet code #576. Out of Boundary Paths
    /// 
    /// There is an m by n grid with a ball. Given the start coordinate (i,j) of 
    /// the ball, you can move the ball to adjacent cell or cross the grid boundary 
    /// in four directions (up, down, left, right). However, you can at most move N
    /// times. Find out the number of paths to move the ball out of grid boundary. 
    /// The answer may be very large, return it after mod 10^9 + 7.
    ///
    /// Example 1:
    /// Input:m = 2, n = 2, N = 2, i = 0, j = 0
    /// Output: 6
    /// Explanation:
    ///
    ///
    /// Example 2:
    /// Input:m = 1, n = 3, N = 3, i = 0, j = 1
    /// Output: 12
    /// Explanation:
    /// 
    /// Note:
    /// Once you move the ball out of boundary, you cannot move it back.
    /// The length and height of the grid is in range [1,50].
    /// N is in range [0,50].
    /// </summary>
    int findPaths(int m, int n, int N, int i, int j);

    /// <summary>
    /// Leet code #656. Coin Path
    /// 
    /// Given an array A (index starts at 1) consisting of N integers: A1, A2,
    ///	..., AN and an integer B. The integer B denotes that from any place 
    /// (suppose the index is i) in the array A, you can jump to any one of 
    /// the place in the array A indexed i+1, i+2, ¡­, i+B if this place can 
    /// be jumped to. Also, if you step on the index i, you have to pay Ai 
    /// coins. If Ai is -1, it means you can¡¯t jump to the place indexed i in 
    /// the array.
    ///
    /// Now, you start from the place indexed 1 in the array A, and your aim 
    /// is to reach the place indexed N using the minimum coins. You need to 
    /// return the path of indexes (starting from 1 to N) in the array you 
    /// should take to get to the place indexed N using minimum coins.
    /// 
    /// If there are multiple paths with the same cost, return the 
    /// lexicographically smallest such path.
    ///
    /// If it's not possible to reach the place indexed N then you need to 
    /// return an empty array.
    ///
    /// Example 1:
    /// Input: [1,2,4,-1,2], 2
    /// Output: [1,3,5]
    ///
    /// Example 2:
    /// Input: [1,2,4,-1,2], 1
    /// Output: []
    /// Note:
    /// Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, 
    /// ..., Pbm, if and only if at the first i where Pai and Pbi differ, 
    /// Pai < Pbi; when no such i exists, then n < m.
    /// A1 >= 0. A2, ..., AN (if exist) will in the range of [-1, 100].
    /// Length of A is in the range of [1, 1000].
    /// B is in the range of [1, 100].
    /// </summary>
    vector<int> cheapestJump(vector<int>& A, int B);

    /// <summary>
    /// Leet code #629. K Inverse Pairs Array
    /// 
    /// Given two integers n and k, find how many different arrays consist of 
    /// numbers from 1 to n such that there are exactly k inverse pairs. 
    /// We define an inverse pair as following: For ith and jth element in the 
    /// array, if i < j and a[i] > a[j] then it's an inverse pair; 
    /// Otherwise, it's not. 
    /// Since the answer may very large, the answer should be modulo 10^9 + 7.
    /// Example 1:
    /// Input: n = 3, k = 0
    /// Output: 1
    /// Explanation: 
    /// Only the array [1,2,3] which consists of numbers from 1 to 3 has 
    /// exactly 0 inverse pair.
    ///
    /// Example 2:
    /// Input: n = 3, k = 1
    /// Output: 2
    /// Explanation: 
    /// The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
    /// 
    /// Note:
    /// The integer n is in the range [1, 1000] and k is in the range 
    /// [0, 1000].
    /// </summary>
    int kInversePairs(int n, int k);

    /// <summary>
    /// Leet Code 123. Best Time to Buy and Sell Stock III
    ///                                                                 
    /// Hard
    ///
    /// You are given an array prices where prices[i] is the price of a given 
    /// stock on the ith day.
    ///
    /// Find the maximum profit you can achieve. You may complete at most two 
    /// transactions.
    ///
    /// Note: You may not engage in multiple transactions simultaneously 
    /// (i.e., you must sell the stock before you buy again).
    ///
    /// Example 1:
    /// Input: prices = [3,3,5,0,0,3,1,4]
    /// Output: 6
    /// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), 
    /// profit = 3-0 = 3.
    /// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), 
    /// profit = 4-1 = 3.
    ///
    /// Example 2:
    /// Input: prices = [1,2,3,4,5]
    /// Output: 4
    /// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), 
    /// profit = 5-1 = 4.
    /// Note that you cannot buy on day 1, buy on day 2 and sell them later, 
    /// as you are engaging multiple transactions at the same time. You must 
    /// sell before buying again.
    ///
    /// Example 3:
    /// Input: prices = [7,6,4,3,1]
    /// Output: 0
    /// Explanation: In this case, no transaction is done, i.e. max profit = 0.
    ///
    /// Example 4:
    /// Input: prices = [1]
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= prices.length <= 10^5
    /// 2. 0 <= prices[i] <= 10^5
    /// </summary>
    int maxProfitTwoTxns(vector<int>& prices);

    /// <summary>
    /// Leet code #920. Number of Music Playlists
    /// 
    /// Your music player contains N different songs and she wants to listen to L 
    /// (not necessarily different) songs during your trip.  You create a playlist 
    /// so that:
    ///
    /// Every song is played at least once
    /// A song can only be played again only if K other songs have been played
    /// Return the number of possible playlists.  As the answer can be very large, 
    /// return it modulo 10^9 + 7.
    /// 
    /// 
    /// Example 1:
    /// Input: N = 3, L = 3, K = 1
    /// Output: 6
    /// Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], 
    /// [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
    ///
    /// Example 2:
    /// Input: N = 2, L = 3, K = 0
    /// Output: 6
    /// Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], 
    /// [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
    ///
    /// Example 3:
    /// Input: N = 2, L = 3, K = 1
    /// Output: 2
    /// Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
    ///  
    /// Note:
    /// 1. 0 <= K < N <= L <= 100
    /// </summary>
    int numMusicPlaylists(int N, int L, int K);

    /// <summary>
    /// Leet code #923. 3Sum With Multiplicity
    /// 
    /// Given an integer array A, and an integer target, return the number of 
    /// tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.
    ///
    /// As the answer can be very large, return it modulo 10^9 + 7.
    /// 
    //// Example 1:
    ///
    /// Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
    /// Output: 20
    /// Explanation: 
    /// Enumerating by the values (A[i], A[j], A[k]):
    /// (1, 2, 5) occurs 8 times;
    /// (1, 3, 4) occurs 8 times;
    /// (2, 2, 4) occurs 2 times;
    /// (2, 3, 3) occurs 2 times.
    ///
    /// Example 2:
    ///
    /// Input: A = [1,1,2,2,2,2], target = 5
    /// Output: 12
    /// Explanation: 
    /// A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
    /// We choose one 1 from [1,1] in 2 ways,
    /// and two 2s from [2,2,2,2] in 6 ways.
    /// 
    ///
    /// Note:
    /// 
    /// 1. 3 <= A.length <= 3000
    /// 2. 0 <= A[i] <= 100
    /// 3. 0 <= target <= 300
    /// </summary>
    int threeSumMulti(vector<int>& A, int target);

    /// <summary>
    /// Leet code #474. Ones and Zeroes
    ///
    /// In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
    /// For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, 
    /// there is an array with strings consisting of only 0s and 1s.
    /// Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. 
    /// Each 0 and 1 can be used at most once. 
    /// Note:
    /// The given numbers of 0s and 1s will both not exceed 100
    /// The size of given string array won't exceed 600.
    /// Example 1:
    /// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
    /// Output: 4
    ///
    /// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are "10,"0001","1","0"
    ///
    /// Example 2:
    /// Input: Array = {"10", "0", "1"}, m = 1, n = 1
    /// Output: 2
    ///
    /// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
    /// </summary>
    int findMaxOneZeroForm(vector<string>& strs, int m, int n);


    /// <summary>
    /// Leet code #377. Combination Sum IV 
    ///
    /// Given an integer array with all positive numbers and no duplicates, 
    /// find the number of possible combinations that add up to a positive integer target.
    /// 
    /// Example: 
    /// nums = [1, 2, 3]
    /// target = 4
    /// The possible combination ways are:
    /// (1, 1, 1, 1)
    /// (1, 1, 2)
    /// (1, 2, 1)
    /// (1, 3)
    /// (2, 1, 1)
    /// (2, 2)
    /// (3, 1)
    /// Note that different sequences are counted as different combinations.
    /// Therefore the output is 7.
    /// Follow up:
    /// What if negative numbers are allowed in the given array?
    /// How does it change the problem?
    /// What limitation we need to add to the question to allow negative numbers? 
    /// </summary>
    int combinationSum4(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1216. Valid Palindrome III
    /// 
    /// Given a string s and an integer k, find out if the given string is a 
    /// K-Palindrome or not.
    ///
    /// A string is K-Palindrome if it can be transformed into a palindrome 
    /// by removing at most k characters from it.
    ///
    /// Example 1:
    ///
    /// Input: s = "abcdeca", k = 2
    /// Output: true
    /// Explanation: Remove 'b' and 'e' characters.
    /// Constraints:
    /// 1. 1 <= s.length <= 1000
    /// 2. s has only lowercase English letters.
    /// 3. 1 <= k <= s.length
    /// </summary>
    bool isValidPalindrome(string s, int k);

    /// <summary>
    /// Leet code #1220. Count Vowels Permutation
    /// 
    /// Given an integer n, your task is to count how many strings of length n 
    /// can be formed under the following rules:
    ///
    /// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
    /// Each vowel 'a' may only be followed by an 'e'.
    /// Each vowel 'e' may only be followed by an 'a' or an 'i'.
    /// Each vowel 'i' may not be followed by another 'i'.
    /// Each vowel 'o' may only be followed by an 'i' or a 'u'.
    /// Each vowel 'u' may only be followed by an 'a'.
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: n = 1
    /// Output: 5
    /// Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
    ///
    /// Example 2:
    ///
    /// Input: n = 2
    /// Output: 10
    /// Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", 
    ///              "io", "iu", "oi", "ou" and "ua".
    /// Example 3: 
    ///
    /// Input: n = 5
    /// Output: 68
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 2 * 10^4
    /// </summary>
    int countVowelPermutation(int n);

    /// <summary>
    /// Leet code #1223. Dice Roll Simulation
    /// 
    /// A die simulator generates a random number from 1 to 6 for each roll. 
    /// You introduced a constraint to the generator such that it cannot roll 
    /// the number i more than rollMax[i] (1-indexed) consecutive times. 
    ///
    /// Given an array of integers rollMax and an integer n, return the number 
    /// of distinct sequences that can be obtained with exact n rolls.
    ///
    /// Two sequences are considered different if at least one element differs 
    /// from each other. Since the answer may be too large, return it 
    /// modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: n = 2, rollMax = [1,1,2,2,2,3]
    /// Output: 34
    /// Explanation: There will be 2 rolls of die, if there are no constraints 
    /// on the die, there are 6 * 6 = 36 possible combinations. In this case, 
    /// looking at rollMax array, the numbers 1 and 2 appear at most once 
    /// consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the 
    /// final answer is 36-2 = 34.
    ///
    /// Example 2:
    ///
    /// Input: n = 2, rollMax = [1,1,1,1,1,1]
    /// Output: 30
    ///
    /// Example 3:
    ///
    /// Input: n = 3, rollMax = [1,1,1,2,2,3]
    /// Output: 181
    ///  
    /// Constraints:
    /// 
    /// 1. 1 <= n <= 5000
    /// 2. rollMax.length == 6
    /// 3. 1 <= rollMax[i] <= 15
    /// </summary>
    int dieSimulator(int n, vector<int>& rollMax);

    /// <summary>
    /// Leet code #1230. Toss Strange Coins
    /// 
    /// You have some coins.  The i-th coin has a probability prob[i] of 
    /// facing heads when tossed.
    ///
    /// Return the probability that the number of coins facing heads equals 
    /// target if you toss every coin exactly once.
    /// 
    /// Example 1:
    ///
    /// Input: prob = [0.4], target = 1
    /// Output: 0.40000
    ///
    /// Example 2:
    ///
    /// Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
    /// Output: 0.03125
    ///
    /// Constraints:
    ///
    /// 1. 1 <= prob.length <= 1000
    /// 2. 0 <= prob[i] <= 1
    /// 3. 0 <= target <= prob.length
    /// 4. Answers will be accepted as correct if they are within 10^-5 of 
    ///    the correct answer.
    /// </summary>
    double probabilityOfHeads(vector<double>& prob, int target);

    /// <summary>
    /// Leet code #1235. Maximum Profit in Job Scheduling
    /// 
    /// We have n jobs, where every job is scheduled to be done from 
    /// startTime[i] to endTime[i], obtaining a profit of profit[i].
    ///
    /// You're given the startTime , endTime and profit arrays, you 
    /// need to output the maximum profit you can take such that 
    /// there are no 2 jobs in the subset with overlapping time range.
    ///
    /// If you choose a job that ends at time X you will be able to 
    /// start another job that starts at time X.
    ///
    /// Example 1:
    /// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], 
    /// profit = [50,10,40,70]
    /// Output: 120
    /// Explanation: The subset chosen is the first and fourth job. 
    /// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
    ///
    /// Example 2:
    /// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], 
    /// profit = [20,20,100,70,60]
    /// Output: 150
    /// Explanation: The subset chosen is the first, fourth and fifth job. 
    /// Profit obtained 150 = 20 + 70 + 60.
    ///
    /// Example 3:
    /// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
    /// Output: 6
    /// 
    /// Constraints:
    ///
    /// 1. 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
    /// 2. 1 <= startTime[i] < endTime[i] <= 10^9
    /// 3. 1 <= profit[i] <= 10^4
    /// </summary>
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);

    /// <summary>
    /// Leet code #1239. Maximum Length of a Concatenated String with 
    ///                  Unique Characters
    /// 
    /// Given an array of strings arr. String s is a concatenation of a 
    /// sub-sequence of arr which have unique characters.
    ///
    /// Return the maximum possible length of s.
    ///
    /// Example 1:
    ///
    /// Input: arr = ["un","iq","ue"]
    /// Output: 4
    /// Explanation: All possible concatenations are "","un","iq","ue","uniq" 
    /// and "ique".
    /// Maximum length is 4.
    ///
    /// Example 2:
    /// Input: arr = ["cha","r","act","ers"]
    /// Output: 6
    /// Explanation: Possible solutions are "chaers" and "acters".
    ///
    /// Example 3:
    ///
    /// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
    /// Output: 26
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 16
    /// 2. 1 <= arr[i].length <= 26
    /// 3. arr[i] contains only lower case English letters.
    /// </summary>
    int maxLength(vector<string>& arr);

    /// <summary>
    /// Leet code #1246. Palindrome Removal
    ///  
    /// Given an integer array arr, in one move you can select a palindromic 
    /// subarray arr[i], arr[i+1], ..., arr[j] where i <= j, and remove that 
    /// subarray from the given array. Note that after removing a subarray, 
    /// the elements on the left and on the right of that subarray move to fill 
    /// the gap left by the removal.
    ///
    /// Return the minimum number of moves needed to remove all numbers from 
    /// the array.
    /// 
    /// Example 1:
    ///
    /// Input: arr = [1,2]
    /// Output: 2
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,3,4,1,5]
    /// Output: 3
    /// Explanation: Remove [4] then remove [1,3,1] then remove [5].
    ///  
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 100
    /// 2. 1 <= arr[i] <= 20
    /// </summary>
    int minimumMoves(vector<int>& arr);

    /// <summary>
    /// Leet code #1255. Maximum Score Words Formed by Letters
    ///  
    /// Given a list of words, list of  single letters (might be repeating) 
    /// and score of every character.
    ///
    /// Return the maximum score of any valid set of words formed by using 
    /// the given letters (words[i] cannot be used two or more times).
    ///
    /// It is not necessary to use all characters in letters and each letter 
    /// can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is 
    /// given by score[0], score[1], ... , score[25] respectively.
    /// 
    /// Example 1:
    ///
    /// Input: words = ["dog","cat","dad","good"], 
    /// letters = ["a","a","c","d","d","d","g","o","o"], 
    /// score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
    /// Output: 23
    /// Explanation:
    /// Score  a=1, c=9, d=5, g=3, o=2
    /// Given letters, we can form the words "dad" (5+1+5) and 
    /// "good" (3+2+2+5) with a score of 23.
    /// Words "dad" and "dog" only get a score of 21.
    ///
    /// Example 2:
    ///
    /// Input: words = ["xxxz","ax","bx","cx"], 
    /// letters = ["z","a","b","c","x","x","x"], 
    /// score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
    /// Output: 27
    /// Explanation:
    /// Score  a=4, b=4, c=4, x=5, z=10
    /// Given letters, we can form the words "ax" (4+5), "bx" (4+5) and 
    /// "cx" (4+5) with a score of 27.
    /// Word "xxxz" only get a score of 25.
    ///
    /// Example 3:
    ///
    /// Input: words = ["leetcode"], 
    /// letters = ["l","e","t","c","o","d"], 
    /// score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
    /// Output: 0
    /// Explanation:
    /// Letter "e" can only be used once.
    ///
    /// Constraints:
    ///
    /// 1. 1 <= words.length <= 14
    /// 2. 1 <= words[i].length <= 15
    /// 3. 1 <= letters.length <= 100
    /// 4. letters[i].length == 1
    /// 5. score.length == 26
    /// 6. 0 <= score[i] <= 10
    /// 7. words[i], letters[i] contains only lower case English letters.
    /// </summary>
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score);

    /// <summary>
    /// Leet code #1259. Handshakes That Don't Cross
    /// 
    /// You are given an even number of people num_people that stand around 
    /// a circle and each person shakes hands with someone else, so that 
    /// there are num_people / 2 handshakes total.
    ///
    /// Return the number of ways these handshakes could occur such that 
    /// none of the handshakes cross.
    ///
    /// Since this number could be very big, return the answer mod 10^9 + 7
    ///
    /// Example 1:
    /// 
    /// Input: num_people = 2
    /// Output: 1
    ///
    /// Example 2:
    ///
    /// Input: num_people = 4
    /// Output: 2
    /// Explanation: There are two ways to do it, the first way is 
    // [(1,2),(3,4)] and the second one is [(2,3),(4,1)].
    ///
    /// Example 3:
    ///
    /// Input: num_people = 6
    /// Output: 5
    ///
    /// Example 4:
    ///
    /// Input: num_people = 8
    /// Output: 14
    ///
    /// Constraints:
    /// 
    /// 1. 2 <= num_people <= 1000
    /// 2. num_people % 2 == 0
    /// </summary>
    int numberOfWays(int num_people);

    /// <summary>
    /// Leet code #1269. Number of Ways to Stay in the Same Place After 
    //  Some Steps
    /// 
    /// You have a pointer at index 0 in an array of size arrLen. At each step, 
    /// you can move 1 position to the left, 1 position to the right in the 
    /// array or stay in the same place  (The pointer should not be placed 
    /// outside the array at any time).
    ///
    /// Given two integers steps and arrLen, return the number of ways such 
    /// that your pointer still at index 0 after exactly steps steps.
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: steps = 3, arrLen = 2
    /// Output: 4
    /// Explanation: There are 4 differents ways to stay at index 0 after 3 
    /// steps.
    /// Right, Left, Stay
    /// Stay, Right, Left
    /// Right, Stay, Left
    /// Stay, Stay, Stay
    /// Example 2:
    ///
    /// Input: steps = 2, arrLen = 4
    /// Output: 2
    /// Explanation: There are 2 differents ways to stay at index 0 after 2 steps
    /// Right, Left
    /// Stay, Stay
    /// Example 3:
    ///
    /// Input: steps = 4, arrLen = 2
    /// Output: 8
    ///
    /// Constraints:
    /// 1. 1 <= steps <= 500
    /// 2. 1 <= arrLen <= 10^6
    /// </summary>
    int numWays(int steps, int arrLen);

    /// <summary>
    /// Leetcode #1277. Count Square Submatrices with All Ones
    /// 
    /// Given a m * n matrix of ones and zeros, return how many square 
    /// submatrices have all ones.
    ///
    /// Example 1:
    ///
    /// Input: matrix =
    /// [
    ///   [0,1,1,1],
    ///   [1,1,1,1],
    ///   [0,1,1,1]
    /// ]
    /// Output: 15
    /// Explanation: 
    /// There are 10 squares of side 1.
    /// There are 4 squares of side 2.
    /// There is  1 square of side 3.
    /// Total number of squares = 10 + 4 + 1 = 15.
    ///
    /// Example 2:
    ///
    /// Input: matrix = 
    /// [
    ///   [1,0,1],
    ///   [1,1,0],
    ///   [1,1,0]
    /// ]
    /// Output: 7
    /// Explanation: 
    /// There are 6 squares of side 1.  
    /// There is 1 square of side 2. 
    /// Total number of squares = 6 + 1 = 7.
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 300
    /// 2. 1 <= arr[0].length <= 300
    /// 3. 0 <= arr[i][j] <= 1
    /// </summary>
    int countSquares(vector<vector<int>>& matrix);

    /// <summary>
    /// Leetcode #1278. Palindrome Partitioning III
    /// </summary>
    int palindromePartition(string s, vector<vector<int>>& dp_change, int first, int last);

    /// <summary>
    /// Leetcode #1278. Palindrome Partitioning III
    /// 
    /// You are given a string s containing lowercase letters and an 
    /// integer k. You need to :
    ///
    /// First, change some characters of s to other lowercase English 
    /// letters.
    /// Then divide s into k non-empty disjoint substrings such that each 
    /// substring is palindrome.
    /// Return the minimal number of characters that you need to change to 
    /// divide the string.
    ///
    /// Example 1:
    ///
    /// Input: s = "abc", k = 2
    /// Output: 1
    /// Explanation: You can split the string into "ab" and "c", and 
    /// change 1 character in "ab" to make it palindrome.
    ///
    /// Example 2:
    ///
    /// Input: s = "aabbc", k = 3
    /// Output: 0
    /// Explanation: You can split the string into "aa", "bb" and "c", all 
    /// of them are palindrome.
    ///
    /// Example 3:
    ///
    /// Input: s = "leetcode", k = 8
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= k <= s.length <= 100.
    /// 2. s only contains lowercase English letters.
    /// </summary>
    int palindromePartition(string s, int k);

    /// <summary>
    /// Leetcode #1289. Minimum Falling Path Sum II
    /// 
    /// Given a square grid of integers arr, a falling path with non-zero 
    /// shifts is a choice of exactly one element from each row of arr, such 
    /// that no two elements chosen in adjacent rows are in the same column.
    ///
    /// Return the minimum sum of a falling path with non-zero shifts.
    /// 
    /// Example 1:
    ///
    /// Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
    /// Output: 13
    /// Explanation: 
    /// The possible falling paths are:
    /// [1,5,9], [1,5,7], [1,6,7], [1,6,8],
    /// [2,4,8], [2,4,9], [2,6,7], [2,6,8],
    /// [3,4,8], [3,4,9], [3,5,7], [3,5,9]
    /// The falling path with the smallest sum is [1,5,7], so the answer is 13.
    ///
    /// Constraints:
    /// 1. 1 <= arr.length == arr[i].length <= 200
    /// 2. -99 <= arr[i][j] <= 99
    /// </summary>
    int minFallingPathSum(vector<vector<int>>& arr);

    /// <summary>
    /// Leetcode #1301. Number of Paths with Max Score
    ///
    /// Hard
    ///
    /// You are given a square board of characters. You can move on the board 
    /// starting at the bottom right square marked with the character 'S'.
    ///
    /// You need to reach the top left square marked with the character 'E'. 
    /// The rest of the squares are labeled either with a numeric 
    /// character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go
    /// up, left or up-left (diagonally) only if there is no obstacle there.
    ///
    /// Return a list of two integers: the first integer is the maximum sum 
    /// of numeric characters you can collect, and the second is the number 
    /// of such paths that you can take to get that maximum sum, taken modulo 
    /// 10^9 + 7.
    ///
    /// In case there is no path, return [0, 0].
    ///
    /// Example 1:
    /// Input: board = ["E23","2X2","12S"]
    /// Output: [7,1]
    /// Example 2:
    ///
    /// Input: board = ["E12","1X1","21S"]
    /// Output: [4,2]
    ///
    /// Example 3:
    ///
    /// Input: board = ["E11","XXX","11S"]
    /// Output: [0,0]
    /// 
    ///
    /// Constraints:
    ///
    /// 1. 2 <= board.length == board[i].length <= 100
    /// </summary>
    vector<int> pathsWithMaxScore(vector<string>& board);

    /// <summary>
    /// Leet code #1312. Minimum Insertion Steps to Make a String Palindrome
    /// 
    /// Hard
    ///
    /// Given a string s. In one step you can insert any character at any 
    /// index of the string.
    /// Return the minimum number of steps to make s palindrome.
    /// A Palindrome String is one that reads the same backward as well as 
    /// forward.
    /// 
    /// Example 1:
    /// Input: s = "zzazz"
    /// Output: 0
    /// Explanation: The string "zzazz" is already palindrome we don't need 
    /// any insertions.
    ///
    /// Example 2:
    /// Input: s = "mbadm"
    /// Output: 2
    /// Explanation: String can be "mbdadbm" or "mdbabdm".
    ///
    /// Example 3:
    /// Input: s = "leetcode"
    /// Output: 5
    /// Explanation: Inserting 5 characters the string becomes "leetcodocteel".
    ///
    /// Example 4:
    /// Input: s = "g"
    /// Output: 0
    ///
    /// Example 5:
    /// Input: s = "no"
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 500
    /// 2. All characters of s are lower case English letters.
    /// </summary>
    int minInsertions(string s);

    /// <summary>
    /// Leet code # 10. Regular Expression Matching
    /// 
    /// Implement regular expression matching with support for '.' and '*'.
    /// 
    /// '.' Matches any single character.
    /// '*' Matches zero or more of the preceding element.
    ///
    /// The matching should cover the entire input string (not partial).
    /// The function prototype should be:
    ///
    /// bool isMatchRegularExpression(const char *s, const char *p)
    ///
    /// Some examples:
    /// isMatch("aa","a")       -> false
    /// isMatch("aa","aa")      -> true
    /// isMatch("aaa","aa")     -> false
    /// isMatch("aa", "a*")     -> true
    /// isMatch("aa", ".*")     -> true
    /// isMatch("ab", ".*")     -> true
    /// isMatch("aab", "c*a*b") -> true
    /// </summary>
    bool isMatchRegularExpression(string s, string p);

    /// <summary>
    /// Leet code #44. Wildcard Matching   
    ///
    /// Implement wildcard pattern matching with support for '?' and '*'.  
    /// '?' Matches any single character.
    /// '*' Matches any sequence of characters (including the empty sequence).
    /// The matching should cover the entire input string (not partial).
    /// The function prototype should be:
    /// bool isWildcardMatch(const char *s, const char *p);
    /// Some examples:
    /// isWildcardMatch("aa","a") -> false
    /// isWildcardMatch("aa","aa") -> true
    /// isWildcardMatch("aaa","aa") -> false
    /// isWildcardMatch("aa", "*") -> true
    /// isWildcardMatch("aa", "a*") -> true
    /// isWildcardMatch("ab", "?*") -> true
    /// isWildcardMatch("aab", "c*a*b") -> false
    /// </summary>
    bool isWildcardMatch(string s, string p);

    /// <summary>
    /// Leet code #70. Climbing Stairs
    ///
    /// You are climbing a stair case. It takes n steps to reach to the top.
    /// Each time you can either climb 1 or 2 steps. In how many distinct ways 
    /// can you climb to the top? 
    /// </summary>
    int climbStairs(int n);

    /// <summary>
    /// Leet code #72. Edit Distance 
    ///
    /// Given two words word1 and word2, find the minimum number of steps 
    /// required to convert word1 to 
    /// word2. (each operation is counted as 1 step.) 
    /// You have the following 3 operations permitted on a word: 
    /// a) Insert a character
    /// b) Delete a character
    /// c) Replace a character
    /// </summary> 
    int minDistance(string word1, string word2);

    /// <summary>
    /// Leet code # 135. Candy
    /// 
    /// There are N children standing in a line. Each child is assigned a rating value.
    /// You are giving candies to these children subjected to the following requirements: 
    /// Each child must have at least one candy.
    /// Children with a higher rating get more candies than their neighbors.
    /// What is the minimum candies you must give?
    /// </summary>
    int candy(vector<int>& ratings);

    /// <summary>
    /// Leet code #115. Distinct Subsequences  
    ///
    /// Given a string S and a string T, count the number of distinct 
    /// subsequences of T in S.
    /// A subsequence of a string is a new string which is formed from the 
    /// original string by deleting some (can be none) 
    /// of the characters without disturbing the relative positions of the 
    /// remaining characters. (ie, "ACE" is a subsequence 
    /// of "ABCDE" while "AEC" is not). For example,
    ///   Here is an example:
    ///   S = "rabbbit", T = "rabbit" 
    /// </summary>
    int numDistinct(string s, string t);

    /// <summary>
    /// Leet Code 55. Jump Game
    ///                                                                 
    /// Medium
    ///
    /// You are given an integer array nums. You are initially positioned at 
    /// the array's first index, and each element in the array represents 
    /// your maximum jump length at that position.
    ///
    /// Return true if you can reach the last index, or false otherwise.
    ///
    /// Example 1:
    /// Input: nums = [2,3,1,1,4]
    /// Output: true
    /// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last 
    /// index.
    ///
    /// Example 2:
    /// Input: nums = [3,2,1,0,4]
    /// Output: false
    /// Explanation: You will always arrive at index 3 no matter what. Its 
    /// maximum jump length is 0, which makes it impossible to reach the last 
    /// index.
    ///  
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^4
    /// 2. 0 <= nums[i] <= 10^5
    /// </summary>
    bool canJump(vector<int>& nums);

    /// <summary>
    /// Leet code #62. Unique Paths 
    ///
    /// A robot is located at the top-left corner of a m x n grid (marked 
    /// 'Start' in the diagram below). 
    /// The robot can only move either down or right at any point in time. 
    /// The robot is trying to reach the bottom-right corner of the grid 
    /// (marked 'Finish' in the diagram below). 
    ///	How many possible unique paths are there?
    /// Above is a 3 x 7 grid. How many possible unique paths are there?  
    /// Note: m and n will be at most 100.
    /// </summary>
    int uniquePaths(int m, int n);

    /// <summary>
    /// Leet code #63. Unique Paths II  
    ///
    /// Follow up for "Unique Paths": 
    /// Now consider if some obstacles are added to the grids. How many unique 
    /// paths would there be? 
    /// An obstacle and empty space is marked as 1 and 0 respectively in the grid. 
    ///	For example,
    /// [
    ///   [0,0,0],
    ///   [0,1,0],
    ///   [0,0,0]
    /// ]
    /// There is one obstacle in the middle of a 3x3 grid as illustrated below.  
    /// The total number of unique paths is 2.
    /// Note: m and n will be at most 100.
    /// </summary>
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

    /// <summary>
    /// Leet code #64. Minimum Path Sum
    ///
    /// Given a m x n grid filled with non-negative numbers, find a path from 
    /// top left to bottom right 
    /// which minimizes the sum of all numbers along its path.
    ///	Note: You can only move either down or right at any point in time. 
    /// </summary>
    int minPathSum(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1139. Largest 1-Bordered Square
    /// 
    /// Given a 2D grid of 0s and 1s, return the number of elements in the 
    /// largest square subgrid that has all 1s on its border, or 0 if such 
    /// a subgrid doesn't exist in the grid.
    /// 
    /// Example 1:
    /// Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
    /// Output: 9
    ///
    /// Example 2:
    /// Input: grid = [[1,1,0,0]]
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= grid.length <= 100
    /// 2. 1 <= grid[0].length <= 100
    /// 3. grid[i][j] is 0 or 1
    /// </summary>
    int largest1BorderedSquare(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1320. Minimum Distance to Type a Word Using Two Fingers
    ///
    /// Hard
    ///
    /// You have a keyboard layout as shown above in the XY plane, where each 
    /// English uppercase letter is located at some coordinate, for example, 
    /// the letter A is located at coordinate (0,0), the letter B is located 
    /// at coordinate (0,1), the letter P is located at coordinate (2,3) and 
    /// the letter Z is located at coordinate (4,1).
    ///
    /// Given the string word, return the minimum total distance to type such 
    /// string using only two fingers. The distance between coordinates (x1,y1) 
    /// and (x2,y2) is |x1 - x2| + |y1 - y2|. 
    ///
    /// Note that the initial positions of your two fingers are considered free 
    /// so don't count towards your total distance, also your two fingers do not 
    /// have to start at the first letter or the first two letters.
    ///
    /// Example 1:
    /// Input: word = "CAKE"
    /// Output: 3
    /// Explanation: 
    /// Using two fingers, one optimal way to type "CAKE" is: 
    /// Finger 1 on letter 'C' -> cost = 0 
    /// Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
    /// Finger 2 on letter 'K' -> cost = 0 
    /// Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
    /// Total distance = 3
    ///
    /// Example 2:
    /// Input: word = "HAPPY"
    /// Output: 6
    /// Explanation: 
    /// Using two fingers, one optimal way to type "HAPPY" is:
    /// Finger 1 on letter 'H' -> cost = 0
    /// Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
    /// Finger 2 on letter 'P' -> cost = 0
    /// Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
    /// Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
    /// Total distance = 6
    ///
    /// Example 3:
    /// Input: word = "NEW"
    /// Output: 3
    ///
    /// Example 4:
    /// Input: word = "YEAR"
    /// Output: 7
    /// 
    /// Constraints:
    /// 1. 2 <= word.length <= 300
    /// 2. Each word[i] is an English uppercase letter.
    /// </summary>
    int minimumDistance(string word);

    /// <summary>
    /// Leet code #132. Palindrome Partitioning II
    ///
    /// Hard
    ///
    /// Given a string s, partition s such that every substring of the 
    /// partition is a palindrome.
    ///
    /// Return the minimum cuts needed for a palindrome partitioning of s.
    ///
    /// Example:
    /// Input: "aab"
    /// Output: 1
    /// Explanation: The palindrome partitioning ["aa","b"] could be produced 
    /// using 1 cut.
    /// </summary>
    int minCut(string s);
    /// <summary>
    /// Leet code #1130. Minimum Cost Tree From Leaf Values
    /// 
    /// Given an array arr of positive integers, consider all binary trees such 
    /// that:
    ///
    /// Each node has either 0 or 2 children;
    /// The values of arr correspond to the values of each leaf in an in-order 
    /// traversal of the tree.  (Recall that a node is a leaf if and only if it 
    /// has 0 children.)
    /// The value of each non-leaf node is equal to the product of the largest 
    /// leaf value in its left and right subtree respectively.
    /// Among all possible binary trees considered, return the smallest possible 
    /// sum of the values of each non-leaf node.  It is guaranteed this sum fits 
    /// into a 32-bit integer.
    ///
    /// 
    /// Example 1:
    /// Input: arr = [6,2,4]
    /// Output: 32
    /// Explanation:
    /// There are two possible trees.  The first has non-leaf node sum 36, and 
    /// the second has non-leaf node sum 32.
    ///
    ///     24            24
    ///    /  \          /  \
    ///   12   4        6    8
    ///  /  \               / \
    /// 6    2             2   4
    ///  
    /// Constraints:
    /// 1. 2 <= arr.length <= 40
    /// 2. 1 <= arr[i] <= 15
    /// 3. It is guaranteed that the answer fits into a 32-bit signed integer 
    ///   (ie. it is less than 2^31).
    /// </summary>
    int mctFromLeafValues(vector<int>& arr);

    /// <summary>
    /// Leet code #1130. Minimum Cost Tree From Leaf Values
    /// </summary>
    int mctFromLeafValuesII(vector<int>& arr);

    /// <summary>
    /// Leet code #1035. Uncrossed Lines
    /// 
    /// We write the integers of A and B (in the order they are given) on two 
    /// separate horizontal lines.
    ///
    /// Now, we may draw a straight line connecting two numbers A[i] and B[j] 
    /// as long as A[i] == B[j], and the line we draw does not intersect any 
    /// other connecting (non-horizontal) line.
    ///
    /// Return the maximum number of connecting lines we can draw in this way.
    ///
    /// 
    /// Example 1:
    /// Input: A = [1,4,2], B = [1,2,4]
    /// Output: 2
    /// Explanation: We can draw 2 uncrossed lines as in the diagram.
    /// We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 
    /// will intersect the line from A[2]=2 to B[1]=2.
    ///
    /// Example 2:
    /// Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
    /// Output: 3
    ///
    /// Example 3:
    /// Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
    /// Output: 2
    /// </summary>
    int maxUncrossedLines(vector<int>& A, vector<int>& B);

    /// <summary>
    /// Leet code #361. Bomb Enemy
    /// 
    /// Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' 
    /// (the number zero), return the maximum enemies you can kill using one bomb.
    /// The bomb kills all the enemies in the same row and column from the planted 
    /// point until it hits the wall since the wall is too strong to be destroyed.
    /// Note that you can only put the bomb at an empty cell. 
    /// 
    /// Example:
    ///
    /// For the given grid
    /// 0 E 0 0
    /// E 0 W E
    /// 0 E 0 0
    ///
    /// return 3. (Placing a bomb at (1,1) kills 3 enemies)
    /// </summary>
    int maxKilledEnemies(vector<vector<char>>& grid);

    /// <summary>
    /// Leet code #516. Longest Palindromic Subsequence   
    /// 
    /// Given a string s, find the longest palindromic subsequence's length 
    /// in s. You may assume that the maximum length of s is 1000. 
    ///
    /// Example 1:
    /// Input: 
    /// "bbbab"
    /// Output: 4
    /// One possible longest palindromic subsequence is "bbbb". 
    ///
    /// Example 2:
    /// Input: 
    /// "cbbd"
    /// Output: 2
    /// One possible longest palindromic subsequence is "bb". 
    /// </summary>
    int longestPalindromeSubseq(string s);

    /// <summary>
    /// Leet code #312. Burst Balloons 
    ///
    /// Given n balloons, indexed from 0 to n-1. Each balloon is painted 
    /// with a number on it represented by array nums. 
    /// You are asked to burst all the balloons. If the you burst balloon i 
    /// you will get nums[left] * nums[i] * nums[right] coins. 
    /// Here left and right are adjacent indices of i. After the burst, the 
    /// left and right then becomes adjacent.
    /// Find the maximum coins you can collect by bursting the balloons wisely. 
    /// Note: 
    /// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
    /// (2) 0 ¡Ü n ¡Ü 500, 0 ¡Ü nums[i] ¡Ü 100 
    /// Example: 
    /// Given [3, 1, 5, 8] 
    /// Return 167 
    /// nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
    /// coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167	
    /// </summary>   
    int maxBurstBalloonCoins(vector<int>& nums);

    /// <summary>
    /// Leet code #486. Predict the Winner
    ///
    /// Given an array of scores that are non-negative integers. Player 1 picks 
    /// one of the numbers from either end of the array followed by the player 2 
    /// and then player 1 and so on. Each time a player picks a number, that 
    /// number will not be available for the next player. This continues until 
    /// all the scores have been chosen. The player with the maximum score wins. 
    ///
    /// Given an array of scores, predict whether player 1 is the winner. You 
    /// can assume each player plays to maximize his score. 
    ///
    /// Example 1:
    /// Input: [1, 5, 2]
    /// Output: False
    /// Explanation: Initially, player 1 can choose between 1 and 2. 
    /// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. 
    /// If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
    /// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
    /// Hence, player 1 will never be the winner and you need to return False.
    ///
    /// Example 2:
    /// Input: [1, 5, 233, 7]
    /// Output: True
    /// Explanation: Player 1 first chooses 1. Then player 2 have to choose 
    /// between 5 and 7. No matter which number player 2 choose, player 1 can 
    /// choose 233.
    /// Finally, player 1 has more score (234) than player 2 (12), so you need 
    /// to return True representing player1 can win.
    ///
    /// Note:
    /// 1.1 <= length of the array <= 20. 
    /// 2.Any scores in the given array are non-negative integers and will not 
    ///   exceed 10,000,000.
    /// 3.If the scores of both players are equal, then player 1 is still the winner.
    /// </summary>
    bool predictTheWinner(vector<int>& nums);

    /// <summary>
    /// Leet code #1105. Filling Bookcase Shelves
    /// 
    /// We have a sequence of books: the i-th book has thickness books[i][0] 
    /// and height books[i][1].
    ///
    /// We want to place these books in order onto bookcase shelves that have 
    /// total width shelf_width.
    ///
    /// We choose some of the books to place on this shelf (such that the sum 
    /// of their thickness is <= shelf_width), then build another level of 
    /// shelf of the bookcase so that the total height of the bookcase has 
    /// increased by the maximum height of the books we just put down.  
    /// We repeat this process until there are no more books to place.
    ///
    /// Note again that at each step of the above process, the order of the 
    /// books we place is the same order as the given sequence of books.  
    /// For example, if we have an ordered list of 5 books, we might place 
    /// the first and second book onto the first shelf, the third book on the 
    /// second shelf, and the fourth and fifth book on the last shelf.
    ///
    /// Return the minimum possible height that the total bookshelf can be after 
    /// placing shelves in this manner.
    ///
    /// Example 1:
    ///
    ///
    /// Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
    /// Output: 6
    /// Explanation:
    /// The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
    /// Notice that book number 2 does not have to be on the first shelf.
    /// 
    ///
    /// Constraints:
    ///
    /// 1. 1 <= books.length <= 1000
    /// 2. 1 <= books[i][0] <= shelf_width <= 1000
    /// 3. 1 <= books[i][1] <= 1000
    /// </summary>
    int minHeightShelves(vector<vector<int>>& books, int shelf_width);

    /// <summary>
    /// Leet code #1335. Minimum Difficulty of a Job Schedule
    /// 
    /// Hard
    ///
    /// You want to schedule a list of jobs in d days. Jobs are dependent 
    /// (i.e To work on the i-th job, you have to finish all the jobs j 
    /// where 0 <= j < i).
    ///
    /// You have to finish at least one task every day. The difficulty of 
    /// a job schedule is the sum of difficulties of each day of the d days.
    /// The difficulty of a day is the maximum difficulty of a job done in 
    /// that day.
    /// Given an array of integers jobDifficulty and an integer d. The 
    /// difficulty of the i-th job is jobDifficulty[i].
    ///
    /// Return the minimum difficulty of a job schedule. If you cannot find 
    /// a schedule for the jobs return -1.
    /// 
    /// Example 1:
    /// Input: jobDifficulty = [6,5,4,3,2,1], d = 2
    /// Output: 7
    /// Explanation: First day you can finish the first 5 jobs, total 
    /// difficulty = 6.
    /// Second day you can finish the last job, total difficulty = 1.
    /// The difficulty of the schedule = 6 + 1 = 7 
    ///
    /// Example 2:
    /// Input: jobDifficulty = [9,9,9], d = 4
    /// Output: -1
    /// Explanation: If you finish a job per day you will still have a free 
    /// day. you cannot find a schedule for the given jobs.
    ///
    /// Example 3:
    /// Input: jobDifficulty = [1,1,1], d = 3
    /// Output: 3
    /// Explanation: The schedule is one job per day. total difficulty will 
    /// be 3.
    ///
    /// Example 4:
    /// Input: jobDifficulty = [7,1,7,1,7,1], d = 3
    /// Output: 15
    ///
    /// Example 5:
    /// Input: jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
    /// Output: 843
    /// Constraints:
    /// 1. 1 <= jobDifficulty.length <= 300
    /// 2. 0 <= jobDifficulty[i] <= 1000
    /// 3. 1 <= d <= 10
    /// </summary>
    int minDifficulty(vector<int>& jobDifficulty, int d);

    /// <summary>
    /// Leet code #1388. Pizza With 3n Slices
    /// 
    /// Hard
    ///
    /// There is a pizza with 3n slices of varying size, you and your friends 
    /// will take slices of pizza as follows:
    ///
    /// You will pick any pizza slice.
    /// Your friend Alice will pick next slice in anti clockwise direction of 
    /// your pick. 
    /// Your friend Bob will pick next slice in clockwise direction of your 
    /// pick.
    /// Repeat until there are no more slices of pizzas.
    /// Sizes of Pizza slices is represented by circular array slices in 
    /// clockwise direction.
    ///
    /// Return the maximum possible sum of slice sizes which you can have.
    ///
    /// Example 1:
    /// Input: slices = [1,2,3,4,5,6]
    /// Output: 10
    /// Explanation: Pick pizza slice of size 4, Alice and Bob will pick 
    /// slices with size 3 and 5 respectively. Then Pick slices with size 6, 
    /// finally Alice and Bob will pick slice of size 2 and 1 respectively. 
    /// Total = 4 + 6.
    ///
    /// Example 2:
    /// Input: slices = [8,9,8,6,1,1]
    /// Output: 16
    /// Output: Pick pizza slice of size 8 in each turn. If you pick slice 
    /// with size 9 your partners will pick slices of size 8.
    ///
    /// Example 3:
    /// Input: slices = [4,1,2,5,8,3,1,9,7]
    /// Output: 21
    ///
    /// Example 4:
    /// Input: slices = [3,1,2]
    /// Output: 3
    ///
    /// Constraints:
    /// 1. 1 <= slices.length <= 500
    /// 2. slices.length % 3 == 0
    /// 3. 1 <= slices[i] <= 1000
    /// </summary>
    int maxSizeSlices(vector<int>& slices);

    /// <summary>
    /// Leet code #1406. Stone Game III
    /// 
    /// Hard
    ///
    /// Alice and Bob continue their games with piles of stones. There are 
    /// several stones arranged in a row, and each stone has an associated 
    /// value which is an integer given in the array stoneValue.
    ///
    /// Alice and Bob take turns, with Alice starting first. On each player's 
    /// turn, that player can take 1, 2 or 3 stones from the first remaining 
    /// stones in the row.
    ///
    /// The score of each player is the sum of values of the stones taken. 
    /// The score of each player is 0 initially.
    ///
    /// The objective of the game is to end with the highest score, and the 
    /// winner is the player with the highest score and there could be a tie. 
    /// The game continues until all the stones have been taken.
    ///
    /// Assume Alice and Bob play optimally.
    ///
    /// Return "Alice" if Alice will win, "Bob" if Bob will win or "Tie" if 
    /// they end the game with the same score.
    ///
    /// Example 1:
    /// Input: values = [1,2,3,7]
    /// Output: "Bob"
    /// Explanation: Alice will always lose. Her best move will be to take 
    /// three piles and the score become 6. Now the score of Bob is 7 and Bob 
    /// wins.
    ///
    /// Example 2:
    /// Input: values = [1,2,3,-9]
    /// Output: "Alice"
    /// Explanation: Alice must choose all the three piles at the first move 
    /// to win and leave Bob with negative score.
    /// If Alice chooses one pile her score will be 1 and the next move Bob's 
    /// score becomes 5. The next move Alice will take the pile with 
    /// value = -9 and lose.
    /// If Alice chooses two piles her score will be 3 and the next move Bob's 
    /// score becomes 3. The next move Alice will take the pile with 
    /// value = -9 and also lose.
    /// Remember that both play optimally so here Alice will choose the 
    /// scenario that makes her win.
    ///
    /// Example 3:
    /// Input: values = [1,2,3,6]
    /// Output: "Tie"
    /// Explanation: Alice cannot win this game. She can end the game in a 
    /// draw if she decided to choose all the first three piles, otherwise 
    /// she will lose.
    ///
    /// Example 4:
    /// Input: values = [1,2,3,-1,-2,-3,7]
    /// Output: "Alice"
    ///
    /// Example 5:
    /// Input: values = [-1,-2,-3]
    /// Output: "Tie"
    ///
    /// Constraints:
    /// 1. 1 <= values.length <= 50000
    /// 2. -1000 <= values[i] <= 1000
    /// </summary>
    string stoneGameIII(vector<int>& stoneValue);

    /// <summary>
    /// Leet code #1411. Number of Ways to Paint N x 3 Grid
    /// 
    /// Hard
    ///
    /// You have a grid of size n x 3 and you want to paint each cell of the 
    /// grid with exactly one of the three colours: Red, Yellow or Green 
    /// while making sure that no two adjacent cells have the same colour 
    /// (i.e no two cells that share vertical or horizontal sides have the 
    /// same colour).
    /// 
    /// You are given n the number of rows of the grid.
    ///
    /// Return the number of ways you can paint this grid. As the answer may 
    /// grow large, the answer must be computed modulo 10^9 + 7.
    ///
    ///
    ///
    /// Example 1:
    /// Input: n = 1
    /// Output: 12
    /// Explanation: There are 12 possible way to paint the grid as shown:
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 54
    ///
    /// Example 3:
    /// Input: n = 3
    /// Output: 246
    ///
    /// Example 4:
    /// Input: n = 7
    /// Output: 106494
    ///
    /// Example 5:
    /// Input: n = 5000
    /// Output: 30228214
    /// 
    /// Constraints:
    /// 1. n == grid.length
    /// 2. grid[i].length == 3
    /// 3. 1 <= n <= 5000
    /// </summary>
    int numOfWays(int n);

    /// <summary>
    /// Leet code #1416. Restore The Array
    /// 
    /// Hard
    ///
    /// A program was supposed to print an array of integers. The program 
    /// forgot to print whitespaces and the array is printed as a string of 
    /// digits and all we know is that all integers in the array were in the 
    /// range [1, k] and there are no leading zeros in the array.
    ///
    /// Given the string s and the integer k. There can be multiple ways to 
    /// restore the array.
    ///
    /// Return the number of possible array that can be printed as a string 
    /// s using the mentioned program.
    ///
    /// The number of ways could be very large so return it modulo 10^9 + 7
    /// 
    /// Example 1:
    ///
    /// Input: s = "1000", k = 10000
    /// Output: 1
    /// Explanation: The only possible array is [1000]
    ///
    /// Example 2:
    /// 
    /// Input: s = "1000", k = 10
    /// Output: 0
    /// Explanation: There cannot be an array that was printed this way and 
    /// has all integer >= 1 and <= 10.
    ///
    /// Example 3:
    /// Input: s = "1317", k = 2000
    /// Output: 8
    /// Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],
    /// [13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
    ///
    /// Example 4:
    /// Input: s = "2020", k = 30
    /// Output: 1
    /// Explanation: The only possible array is [20,20]. [2020] is invalid 
    /// because 2020 > 30. [2,020] is ivalid because 020 contains leading 
    /// zeros.
    ///
    /// Example 5:
    /// Input: s = "1234567890", k = 90
    /// Output: 34
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5.
    /// 2. s consists of only digits and doesn't contain leading zeros.
    /// 3. 1 <= k <= 10^9.
    /// </summary>
    int numberOfArrays(string s, int k);

    /// <summary>
    /// Leet code #1420. Build Array Where You Can Find The Maximum Exactly 
    ///                  K Comparisons
    /// 
    /// Hard
    ///
    /// Given three integers n, m and k. Consider the following algorithm to 
    /// find the maximum element of an array of positive integers:
    ///
    /// You should build the array arr which has the following properties:
    /// 
    /// arr has exactly n integers.
    /// 1 <= arr[i] <= m where (0 <= i < n).
    /// After applying the mentioned algorithm to arr, the value search_cost 
    /// is equal to k.
    /// Return the number of ways to build the array arr under the mentioned 
    /// conditions. As the answer may grow large, the answer must be computed 
    /// modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 2, m = 3, k = 1
    /// Output: 6
    /// Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], 
    /// [3, 2] [3, 3]
    ///
    /// Example 2:
    /// Input: n = 5, m = 2, k = 3
    /// Output: 0
    /// Explanation: There are no possible arrays that satisify the mentioned 
    /// conditions.
    ///
    /// Example 3:
    /// Input: n = 9, m = 1, k = 1
    /// Output: 1
    /// Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
    ///
    /// Example 4:
    /// Input: n = 50, m = 100, k = 25
    /// Output: 34549172
    /// Explanation: Don't forget to compute the answer modulo 1000000007
    ///
    /// Example 5:
    /// Input: n = 37, m = 17, k = 7
    /// Output: 418930126
    ///
    /// Constraints:
    /// 1. 1 <= n <= 50
    /// 2. 1 <= m <= 100
    /// 3. 0 <= k <= n
    /// </summary>
    int numOfArrays(int n, int m, int k);

    /// <summary>
    /// Leet code #1434. Number of Ways to Wear Different Hats to Each Other
    /// 
    /// Hard
    ///
    /// There are n people and 40 types of hats labeled from 1 to 40.
    ///
    /// Given a list of list of integers hats, where hats[i] is a list of all 
    /// hats preferred by the i-th person.
    ///
    /// Return the number of ways that the n people wear different hats to each 
    /// other.
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: hats = [[3,4],[4,5],[5]]
    /// Output: 1
    /// Explanation: There is only one way to choose hats given the conditions. 
    /// First person choose hat 3, Second person choose hat 4 and last one hat 5.
    ///
    /// Example 2:
    /// Input: hats = [[3,5,1],[3,5]]
    /// Output: 4
    /// Explanation: There are 4 ways to choose hats
    /// (3,5), (5,3), (1,3) and (1,5)
    ///
    /// Example 3: 
    /// Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
    /// Output: 24
    /// Explanation: Each person can choose hats labeled from 1 to 4.
    /// Number of Permutations of (1,2,3,4) = 24.
    ///
    /// Example 4:
    /// Input: hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
    /// Output: 111
    ///
    /// Constraints:
    /// 1. n == hats.length
    /// 2. 1 <= n <= 10
    /// 3. 1 <= hats[i].length <= 40
    /// 4. 1 <= hats[i][j] <= 40
    /// 5. hats[i] contains a list of unique integers.
    /// </summary>
    int numberWays(vector<vector<int>>& hats);

    /// <summary>
    /// Leet code #1444. Number of Ways of Cutting a Pizza
    ///
    /// Hard
    ///
    /// Given a rectangular pizza represented as a rows x cols matrix containing 
    /// the following characters: 'A' (an apple) and '.' (empty cell) and given 
    /// the integer k. You have to cut the pizza into k pieces using k-1 cuts. 
    ///
    /// For each cut you choose the direction: vertical or horizontal, then you 
    /// choose a cut position at the cell boundary and cut the pizza into two 
    /// pieces. If you cut the pizza vertically, give the left part of the pizza 
    /// to a person. If you cut the pizza horizontally, give the upper part of 
    /// the pizza to a person. Give the last piece of pizza to the last person.
    ///
    /// Return the number of ways of cutting the pizza such that each piece 
    /// contains at least one apple. Since the answer can be a huge number, 
    /// return this modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: pizza = ["A..","AAA","..."], k = 3
    /// Output: 3 
    /// Explanation: The figure above shows the three ways to cut the pizza. 
    /// Note that pieces must contain at least one apple.
    ///
    /// Example 2:
    /// Input: pizza = ["A..","AA.","..."], k = 3
    /// Output: 1
    ///
    /// Example 3:
    /// Input: pizza = ["A..","A..","..."], k = 1
    /// Output: 1
    /// 
    /// Constraints:
    /// 1. 1 <= rows, cols <= 50
    /// 2. rows == pizza.length
    /// 3. cols == pizza[i].length
    /// 4. 1 <= k <= 10
    /// 5. pizza consists of characters 'A' and '.' only.
    /// </summary>
    int ways(vector<string>& pizza, int k);

    /// <summary>
    /// Leet code #1449. Form Largest Integer With Digits That Add up to Target
    ///
    /// Hard
    ///
    /// Given an array of integers cost and an integer target. Return the 
    /// maximum integer you can paint under the following rules:
    ///
    /// The cost of painting a digit (i+1) is given by cost[i] (0 indexed).
    /// The total cost used must be equal to target.
    /// Integer does not have digits 0.
    /// Since the answer may be too large, return it as string.
    /// If there is no way to paint any integer given the condition, 
    /// return "0".
    ///
    /// Example 1:
    /// Input: cost = [4,3,2,5,6,7,2,5,5], target = 9
    /// Output: "7772"
    /// Explanation:  The cost to paint the digit '7' is 2, and the 
    /// digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also 
    /// paint "997", but "7772" is the largest number.
    /// Digit    cost
    ///  1  ->   4
    ///  2  ->   3
    ///  3  ->   2
    ///  4  ->   5
    ///  5  ->   6
    ///  6  ->   7
    ///  7  ->   2
    ///  8  ->   5
    ///   9  ->   5
    ///
    /// Example 2:
    /// Input: cost = [7,6,5,5,5,6,8,7,8], target = 12
    /// Output: "85"
    /// Explanation: The cost to paint the digit '8' is 7, and the 
    /// digit '5' is 5. Then cost("85") = 7 + 5 = 12.
    ///
    /// Example 3:
    /// Input: cost = [2,4,6,2,4,6,4,4,4], target = 5
    /// Output: "0"
    /// Explanation: It's not possible to paint any integer with total cost 
    /// equal to target.
    ///
    /// Example 4:
    /// Input: cost = [6,10,15,40,40,40,40,40,40], target = 47
    /// Output: "32211"
    /// Constraints:
    /// 1. cost.length == 9
    /// 2. 1 <= cost[i] <= 5000
    /// 3. 1 <= target <= 5000
    /// </summary>
    string largestNumber(vector<int>& cost, int target);

    /// <summary>
    /// Leet code #1458. Max Dot Product of Two Subsequences
    ///                
    /// Hard
    /// 
    /// Given two arrays nums1 and nums2.
    /// Return the maximum dot product between non-empty subsequences of 
    /// nums1 and nums2 with the same length.
    ///
    /// A subsequence of a array is a new array which is formed from the 
    /// original array by deleting some (can be none) of the characters 
    /// without disturbing the relative positions of the remaining 
    /// characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] 
    /// while [1,5,3] is not).
    ///
    /// Example 1:
    /// Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
    /// Output: 18
    /// Explanation: Take subsequence [2,-2] from nums1 and subsequence 
    /// [3,-6] from nums2.
    /// Their dot product is (2*3 + (-2)*(-6)) = 18.
    ///
    /// Example 2:
    /// Input: nums1 = [3,-2], nums2 = [2,-6,7]
    /// Output: 21
    /// Explanation: Take subsequence [3] from nums1 and subsequence [7] 
    /// from nums2.
    /// Their dot product is (3*7) = 21.
    ///
    /// Example 3:
    /// Input: nums1 = [-1,-1], nums2 = [1,1]
    /// Output: -1
    /// Explanation: Take subsequence [-1] from nums1 and subsequence [1] 
    /// from nums2.
    /// Their dot product is -1.
    ///
    /// Constraints:
    /// 1. 1 <= nums1.length, nums2.length <= 500
    /// 2. -1000 <= nums1[i], nums2[i] <= 1000
    /// </summary>
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet code #1463. Cherry Pickup II
    /// 
    /// Hard
    ///
    /// Given a rows x cols matrix grid representing a field of cherries. 
    /// Each cell in grid represents the number of cherries that you can 
    /// collect.
    /// 
    /// You have two robots that can collect cherries for you, Robot #1 
    /// is located at the top-left corner (0,0) , and Robot #2 is located 
    /// at the top-right corner (0, cols-1) of the grid.
    ///
    /// Return the maximum number of cherries collection using both robots 
    /// by following the rules below:
    ///
    /// From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) 
    /// or (i+1, j+1).
    /// When any robot is passing through a cell, It picks it up all cherries, 
    /// and the cell becomes an empty cell (0).
    /// When both robots stay on the same cell, only one of them takes the 
    /// cherries.
    /// Both robots cannot move outside of the grid at any moment.
    /// Both robots should reach the bottom row in the grid.
    ///
    /// Example 1:
    /// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
    /// Output: 24
    /// Explanation: Path of robot #1 and #2 are described in color green and 
    /// blue respectively.
    /// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
    /// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
    /// Total of cherries: 12 + 12 = 24.
    ///
    /// Example 2:
    /// Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],
    /// [0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
    /// Output: 28
    /// Explanation: Path of robot #1 and #2 are described in color green and 
    /// blue respectively.
    /// Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
    /// Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
    /// Total of cherries: 17 + 11 = 28.
    ///
    /// Example 3:
    /// Input: grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
    /// Output: 22
    ///
    /// Example 4:
    ///
    /// Input: grid = [[1,1],[1,1]]
    /// Output: 4
    ///
    /// Constraints:
    /// 1. rows == grid.length
    /// 2. cols == grid[i].length
    /// 3. 2 <= rows, cols <= 70
    /// 4. 0 <= grid[i][j] <= 100 
    /// </summary>
    int cherryPickup(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1473. Paint House III
    ///                
    /// Hard
    /// 
    /// There is a row of m houses in a small city, each house must be painted 
    /// with one of the n colors (labeled from 1 to n), some houses that has 
    /// been painted last summer should not be painted again.
    ///
    /// A neighborhood is a maximal group of continuous houses that are 
    /// painted with the same color. (For example: houses = [1,2,2,3,3,2,1,1] 
    /// contains 5 neighborhoods  [{1}, {2,2}, {3,3}, {2}, {1,1}]).
    ///
    /// Given an array houses, an m * n matrix cost and an integer target 
    /// where:
    /// houses[i]: is the color of the house i, 0 if the house is not 
    /// painted yet.
    /// cost[i][j]: is the cost of paint the house i with the color j+1.
    /// Return the minimum cost of painting all the remaining houses in such 
    /// a way that there are exactly target neighborhoods, if not possible 
    /// return -1.
    ///
    /// Example 1:
    /// Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],
    /// [5,1]], m = 5, n = 2, target = 3
    /// Output: 9
    /// Explanation: Paint houses of this way [1,2,2,1,1]
    /// This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
    /// Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.
    ///
    /// Example 2:
    /// Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],
    /// [5,1]], m = 5, n = 2, target = 3
    /// Output: 11
    /// Explanation: Some houses are already painted, Paint the houses of 
    /// this way [2,2,1,2,2]
    /// This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
    /// Cost of paint the first and last house (10 + 1) = 11.
    ///
    /// Example 3:
    /// Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],
    /// [1,10]], m = 5, n = 2, target = 5
    /// Output: 5
    ///
    /// Example 4:
    /// Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], 
    /// m = 4, n = 3, target = 3
    /// Output: -1
    /// Explanation: Houses are already painted with a total of 4 
    /// neighborhoods [{3},{1},{2},{3}] different of target = 3.
    ///
    /// Constraints:
    /// 1. m == houses.length == cost.length
    /// 2. n == cost[i].length
    /// 3. 1 <= m <= 100
    /// 4. 1 <= n <= 20
    /// 5. 1 <= target <= m
    /// 6. 0 <= houses[i] <= n
    /// 7. 1 <= cost[i][j] <= 10^4
    /// </summary>
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target);

    /// <summary>
    /// Leet code #1478. Allocate Mailboxes
    ///
    /// Hard
    ///
    /// Given the array houses and an integer k. where houses[i] is the 
    /// location of the ith house along a street, your task is to allocate 
    /// k mailboxes in the street.
    ///  
    /// Return the minimum total distance between each house and its nearest 
    /// mailbox.
    /// The answer is guaranteed to fit in a 32-bit signed integer.
    /// 
    /// Example 1:
    /// Input: houses = [1,4,8,10,20], k = 3
    /// Output: 5
    /// Explanation: Allocate mailboxes in position 3, 9 and 20.
    /// Minimum total distance from each houses to nearest mailboxes is 
    /// |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
    ///
    /// Example 2:
    /// Input: houses = [2,3,5,12,18], k = 2
    /// Output: 9
    /// Explanation: Allocate mailboxes in position 3 and 14.
    /// Minimum total distance from each houses to nearest mailboxes is 
    /// |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
    ///
    /// Example 3:
    /// Input: houses = [7,4,6,1], k = 1
    /// Output: 8
    ///
    /// Example 4:
    /// Input: houses = [3,6,14,10], k = 4
    /// Output: 0
    /// 1. Constraints:
    /// 2. n == houses.length
    /// 3. 1 <= n <= 100
    /// 4. 1 <= houses[i] <= 10^4
    /// 5. 1 <= k <= n
    /// 6. Array houses contain unique integers.
    /// </summary> 
    int minDistance(vector<int>& houses, int k);

    /// <summary>
    /// Leet code #1510. Stone Game IV
    /// 
    /// Hard
    ///
    /// Alice and Bob take turns playing a game, with Alice starting first.
    /// Initially, there are n stones in a pile.  On each player's turn, that 
    /// player makes a move consisting of removing any non-zero square number 
    /// of stones in the pile.
    /// 
    /// Also, if a player cannot make a move, he/she loses the game.
    /// 
    /// Given a positive integer n. Return True if and only if Alice wins the 
    /// game otherwise return False, assuming both players play optimally.
    /// 
    /// Example 1:
    /// Input: n = 1
    /// Output: true
    /// Explanation: Alice can remove 1 stone winning the game because Bob 
    /// doesn't have any moves.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: false
    /// Explanation: Alice can only remove 1 stone, after that Bob removes 
    /// the last one winning the game (2 -> 1 -> 0).
    ///
    /// Example 3:
    /// Input: n = 4
    /// Output: true
    /// Explanation: n is already a perfect square, Alice can win with one 
    /// move, removing 4 stones (4 -> 0).
    ///
    /// Example 4:
    /// Input: n = 7
    /// Output: false
    /// Explanation: Alice can't win the game if Bob plays optimally.
    /// If Alice starts removing 4 stones, Bob will remove 1 stone then Alice 
    /// should remove only 1 stone and finally Bob removes the last 
    /// one (7 -> 3 -> 2 -> 1 -> 0). 
    /// If Alice starts removing 1 stone, Bob will remove 4 stones then Alice 
    /// only can remove 1 stone and finally Bob removes the last 
    /// one (7 -> 6 -> 2 -> 1 -> 0).
    ///
    /// Example 5:
    /// Input: n = 17
    /// Output: false
    /// Explanation: Alice can't win the game if Bob plays optimally.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// </summary>
    bool winnerSquareGame(int n);

    /// <summary>
    /// Leet code #1546. Maximum Number of Non-Overlapping Subarrays With 
    ///                  Sum Equals Target
    /// 
    /// Medium
    ///
    /// Given an array nums and an integer target.
    ///
    /// Return the maximum number of non-empty non-overlapping subarrays such 
    /// that the sum of values in each subarray is equal to target.
    /// 
    /// Example 1:
    /// Input: nums = [1,1,1,1,1], target = 2
    /// Output: 2
    /// Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
    ///
    /// Example 2:
    /// Input: nums = [-1,3,5,1,4,2,-9], target = 6
    /// Output: 2
    /// Explanation: There are 3 subarrays with sum equal to 6.
    /// ([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
    ///
    /// Example 3:
    /// Input: nums = [-2,6,6,3,5,4,1,2,8], target = 10
    /// Output: 3
    ///
    /// Example 4:
    /// Input: nums = [0,0,0], target = 0
    /// Output: 3
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^4 <= nums[i] <= 10^4
    /// 3. 0 <= target <= 10^6
    /// </summary>
    int maxNonOverlapping(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1547. Minimum Cost to Cut a Stick 
    /// 
    /// Hard
    ///
    /// Given a wooden stick of length n units. The stick is labelled from 0 
    /// to n. For example, a stick of length 6 is labelled as follows:
    ///
    /// Given an integer array cuts where cuts[i] denotes a position you 
    /// should perform a cut at.
    ///
    /// You should perform the cuts in order, you can change the order of 
    /// the cuts as you wish.
    ///
    /// The cost of one cut is the length of the stick to be cut, the total 
    /// cost is the sum of costs of all cuts. When you cut a stick, it will 
    /// be split into two smaller sticks (i.e. the sum of their lengths is 
    /// the length of the stick before the cut). Please refer to the first 
    /// example for a better explanation.
    ///
    /// Return the minimum total cost of the cuts.
    ///
    /// Example 1:
    /// Input: n = 7, cuts = [1,3,4,5]
    /// Output: 16
    /// Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads 
    /// to the following scenario:
    ///
    /// The first cut is done to a rod of length 7 so the cost is 7. The 
    /// second cut is done to a rod of length 6 (i.e. the second part of the 
    /// first cut), the third is done to a rod of length 4 and the last cut 
    /// is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
    /// Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a 
    /// scenario with total cost = 16 (as shown in the example photo 
    /// 7 + 4 + 3 + 2 = 16).
    ///
    /// Example 2:
    /// Input: n = 9, cuts = [5,6,1,4,2]
    /// Output: 22
    /// Explanation: If you try the given cuts ordering the cost will be 25.
    /// There are much ordering with total cost <= 25, for example, the order 
    /// [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^6
    /// 2. 1 <= cuts.length <= min(n - 1, 100)
    /// 3. 1 <= cuts[i] <= n - 1
    /// 4. All the integers in cuts array are distinct.
    /// </summary>
    int minCost(int n, vector<int>& cuts);

    /// <summary>
    /// Leet code #1553. Minimum Number of Days to Eat N Oranges
    /// 
    /// Hard
    ///
    /// There are n oranges in the kitchen and you decided to eat some of 
    /// these oranges every day as follows:
    /// Eat one orange.
    /// If the number of remaining oranges (n) is divisible by 2 then you 
    /// can eat  n/2 oranges.
    /// If the number of remaining oranges (n) is divisible by 3 then you 
    /// can eat  2*(n/3) oranges.
    /// You can only choose one of the actions per day.
    ///
    /// Return the minimum number of days to eat n oranges.
    ///
    /// Example 1:
    /// Input: n = 10
    /// Output: 4
    /// Explanation: You have 10 oranges.
    /// Day 1: Eat 1 orange,  10 - 1 = 9.  
    /// Day 2: Eat 6 oranges, 9 - 2*(9/3) = 9 - 6 = 3. (Since 9 is divisible 
    /// by 3)
    /// Day 3: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. 
    /// Day 4: Eat the last orange  1 - 1  = 0.
    /// You need at least 4 days to eat the 10 oranges.
    ///
    /// Example 2:
    ///
    /// Input: n = 6
    /// Output: 3
    /// Explanation: You have 6 oranges.
    /// Day 1: Eat 3 oranges, 6 - 6/2 = 6 - 3 = 3. (Since 6 is divisible by 2).
    /// Day 2: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. (Since 3 is divisible by 3)
    /// Day 3: Eat the last orange  1 - 1  = 0.
    /// You need at least 3 days to eat the 6 oranges.
    ///
    /// Example 3:
    /// Input: n = 1
    /// Output: 1
    ///
    /// Example 4:
    /// Input: n = 56
    /// Output: 6
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 2*10^9
    /// </summary>
    int minDays(int n);

    /// <summary>
    /// Leet code #1563. Stone Game V
    /// </summary>
    int stoneGameV(vector<int>& stoneValue, int first, int last, vector<int>&sum, vector<vector<int>> &dp);


    /// <summary>
    /// Leet code #1563. Stone Game V
    /// 
    /// Hard
    ///
    /// There are several stones arranged in a row, and each stone has an 
    /// associated value which is an integer given in the array stoneValue.
    ///
    /// In each round of the game, Alice divides the row into two non-empty 
    /// rows (i.e. left row and right row), then Bob calculates the value of 
    /// each row which is the sum of the values of all the stones in this row. 
    /// Bob throws away the row which has the maximum value, and Alice's score 
    /// increases by the value of the remaining row. If the value of the two 
    /// rows are equal, Bob lets Alice decide which row will be thrown away. 
    /// The next round starts with the remaining row.
    ///
    /// The game ends when there is only one stone remaining. Alice's is 
    /// initially zero.
    ///
    /// Return the maximum score that Alice can obtain.
    /// Example 1:
    /// Input: stoneValue = [6,2,3,4,5,5]
    /// Output: 18
    /// Explanation: In the first round, Alice divides the row to [6,2,3], 
    /// [4,5,5]. The left row has the value 11 and the right row has value 14. 
    /// Bob throws away the right row and Alice's score is now 11.
    /// In the second round Alice divides the row to [6], [2,3]. This time Bob 
    /// throws away the left row and Alice's score becomes 16 (11 + 5).
    /// The last round Alice has only one choice to divide the row which 
    /// is [2], [3]. Bob throws away the right row and Alice's score is 
    /// now 18 (16 + 2). The game ends because only one stone is remaining in 
    /// the row.
    ///
    /// Example 2:
    /// Input: stoneValue = [7,7,7,7,7,7,7]
    /// Output: 28
    ///
    /// Example 3:
    /// Input: stoneValue = [4]
    /// Output: 0
    /// Constraints:
    /// 1. 1 <= stoneValue.length <= 500
    /// 2. 1 <= stoneValue[i] <= 10^6
    /// </summary>
    int stoneGameV(vector<int>& stoneValue);

    /// <summary>
    /// Leet code #1569. Number of Ways to Reorder Array to Get Same BST
    /// </summary>
    long long numOfWays(vector<int>& nums, vector<vector<int>> &permutation);

    /// <summary>
    /// Leet code #1569. Number of Ways to Reorder Array to Get Same BST
    /// 
    /// Hard
    ///
    /// Given an array nums that represents a permutation of integers from 1 
    /// to n. We are going to construct a binary search tree (BST) by 
    /// inserting the elements of nums in order into an initially empty BST. 
    /// Find the number of different ways to reorder nums so that the 
    /// constructed BST is identical to that formed from the original array 
    /// nums.
    ///
    /// For example, given nums = [2,1,3], we will have 2 as the root, 1 as a 
    /// left child, and 3 as a right child. The array [2,3,1] also yields the 
    /// same BST but [3,2,1] yields a different BST.
    ///
    /// Return the number of ways to reorder nums such that the BST formed is 
    /// identical to the original BST formed from nums.
    ///
    /// Since the answer may be very large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: nums = [2,1,3]
    /// Output: 1
    /// Explanation: We can reorder nums to be [2,3,1] which will yield the 
    /// same BST. There are no other ways to reorder nums which will yield the 
    /// same BST.
    ///
    /// Example 2:
    /// Input: nums = [3,4,5,1,2]
    /// Output: 5
    /// Explanation: The following 5 arrays will yield the same BST: 
    /// [3,1,2,4,5]
    /// [3,1,4,2,5]
    /// [3,1,4,5,2]
    /// [3,4,1,2,5]
    /// [3,4,1,5,2]
    ///
    /// Example 3:
    /// Input: nums = [1,2,3]
    /// Output: 0
    /// Explanation: There are no other orderings of nums that will yield the 
    /// same BST.
    ///
    /// Example 4:
    /// Input: nums = [3,1,2,5,4,6]
    /// Output: 19
    ///
    /// Example 5:
    /// Input: nums = [9,4,2,1,3,6,5,7,8,14,11,10,12,13,16,15,17,18]
    /// Output: 216212978
    /// Explanation: The number of ways to reorder nums to get the same BST 
    /// is 3216212999. Taking this number modulo 10^9 + 7 gives 216212978.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= nums.length
    /// 3. All integers in nums are distinct.
    /// </summary>
    int numOfWays(vector<int>& nums);

    /// <summary>
    /// Leet code #1594. Maximum Non Negative Product in a Matrix 
    /// 
    /// Medium
    ///
    /// You are given a rows x cols matrix grid. Initially, you are located 
    /// at the top-left corner (0, 0), and in each step, you can only move 
    /// right or down in the matrix.
    ///
    /// Among all possible paths starting from the top-left corner (0, 0) 
    /// and ending in the bottom-right corner (rows - 1, cols - 1), find the 
    /// path with the maximum non-negative product. The product of a path is 
    /// the product of all integers in the grid cells visited along the path.
    /// 
    /// Return the maximum non-negative product modulo 109 + 7. If the maximum 
    /// product is negative return -1.
    /// 
    /// Notice that the modulo is performed after getting the maximum product.
    /// 
    /// Example 1:
    /// Input: grid = [[-1,-2,-3],
    ///           [-2,-3,-3],
    ///           [-3,-3,-2]]
    /// Output: -1
    /// Explanation: It's not possible to get non-negative product in the path 
    /// from (0, 0) to (2, 2), so return -1.
    ///
    /// Example 2:
    /// Input: grid = [[1,-2,1],
    ///           [1,-2,1],
    ///           [3,-4,1]]
    /// Output: 8
    /// Explanation: Maximum non-negative product is in bold 
    /// (1 * 1 * -2 * -4 * 1 = 8).
    ///
    /// Example 3:
    /// Input: grid = [[1, 3],
    ///                [0,-4]]
    /// Output: 0
    /// Explanation: Maximum non-negative product is in bold (1 * 0 * -4 = 0).
    ///
    /// Example 4:
    /// Input: grid = [[ 1, 4,4,0],
    ///                   [-2, 0,0,1],
    ///           [ 1,-1,1,1]]
    /// Output: 2
    /// Explanation: Maximum non-negative product is in bold 
    /// (1 * -2 * 1 * -1 * 1 * 1 = 2).
    /// 
    /// Constraints:
    /// 1. 1 <= rows, cols <= 15
    /// 2. -4 <= grid[i][j] <= 4
    /// </summary>
    int maxProductPath(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1621. Number of Sets of K Non-Overlapping Line Segments
    /// 
    /// Medium
    ///
    /// Given n points on a 1-D plane, where the ith point (from 0 to n-1) 
    /// is at x = i, find the number of ways we can draw exactly k 
    /// non-overlapping line segments such that each segment covers two or 
    /// more points. The endpoints of each segment must have integral 
    /// coordinates. The k line segments do not have to cover all n points, 
    /// and they are allowed to share endpoints.
    /// 
    /// Return the number of ways we can draw k non-overlapping line segments. 
    /// Since this number can be huge, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 4, k = 2
    /// Output: 5
    /// Explanation: 
    /// The two line segments are shown in red and blue.
    /// The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),
    /// (1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
    ///
    /// Example 2:
    /// Input: n = 3, k = 1
    /// Output: 3
    /// Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
    ///
    /// Example 3:
    /// Input: n = 30, k = 7
    /// Output: 796297179
    /// Explanation: The total number of possible ways to draw 7 line segments 
    /// is 3796297200. Taking this number modulo 10^9 + 7 gives us 796297179.
    ///
    /// Example 4:
    /// Input: n = 5, k = 3
    /// Output: 7
    ///
    /// Example 5:
    /// 
    /// Input: n = 3, k = 2
    /// Output: 1
    ///  
    /// Constraints:
    /// 1. 2 <= n <= 1000
    /// 2. 1 <= k <= n-1
    /// </summary>
    int numberOfSets(int n, int k);

    /// <summary>
    /// Leet code #1639. Number of Ways to Form a Target String Given a 
    ///                  Dictionary
    /// 
    /// Hard
    ///
    /// You are given a list of strings of the same length words and a string 
    /// target.
    ///
    /// Your task is to form target using the given words under the following 
    /// rules:
    ///
    /// target should be formed from left to right. 
    /// To form the ith character (0-indexed) of target, you can choose the 
    /// kth character of the jth string in words if target[i] = words[j][k].
    /// Once you use the kth character of the jth string of words, you can 
    /// no longer use the xth character of any string in words where x <= k. 
    /// In other words, all characters to the left of or at index k become 
    /// unusuable for every string.
    /// Repeat the process until you form the string target.
    /// Notice that you can use multiple characters from the same string in 
    /// words provided the conditions above are met.
    ///
    /// Return the number of ways to form target from words. Since the 
    /// answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: words = ["acca","bbbb","caca"], target = "aba"
    /// Output: 6
    /// Explanation: There are 6 ways to form target.
    /// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
    /// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
    /// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
    /// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
    /// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
    /// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
    ///
    /// Example 2:
    /// Input: words = ["abba","baab"], target = "bab"
    /// Output: 4
    /// Explanation: There are 4 ways to form target.
    /// "bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
    /// "bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
    /// "bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
    /// "bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
    ///
    /// Example 3:
    /// Input: words = ["abcd"], target = "abcd"
    /// Output: 1
    ///
    /// Example 4:
    /// Input: words = ["abab","baba","abba","baab"], target = "abba"
    /// Output: 16
    /// 
    /// Constraints:
    /// 1. 1 <= words.length <= 1000
    /// 2. 1 <= words[i].length <= 1000
    /// 3. All strings in words have the same length.
    /// 4. 1 <= target.length <= 1000
    /// 5. words[i] and target contain only lowercase English letters.
    /// </summary>
    int numWays(vector<string>& words, string target);

    /// <summary>
    /// Leet code #1641. Count Sorted Vowel Strings
    /// 
    /// Medium
    ///
    /// Given an integer n, return the number of strings of length n that consist 
    /// only of vowels (a, e, i, o, u) and are lexicographically sorted.
    ///
    /// A string s is lexicographically sorted if for all valid i, s[i] is the same
    /// as or comes before s[i+1] in the alphabet.
    ///
    /// Example 1:
    /// Input: n = 1
    /// Output: 5
    /// Explanation: The 5 sorted strings that consist of vowels only are 
    /// ["a","e","i","o","u"].
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 15
    /// Explanation: The 15 sorted strings that consist of vowels only are
    /// ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo",
    ///  "ou","uu"].
    /// Note that "ea" is not a valid string since 'e' comes after 'a' in the 
    /// alphabet.
    ///
    /// Example 3:
    /// Input: n = 33
    /// Output: 66045
    ///
    /// Constraints:
    /// 1. 1 <= n <= 50 
    /// </summary>
    int countVowelStrings(int n);

    /// <summary>
    /// Leet code #1653. Minimum Deletions to Make String Balanced
    /// 
    /// Medium
    ///
    /// You are given a string s consisting only of characters 'a' and 'b'
    ///
    /// You can delete any number of characters in s to make s balanced. s is 
    /// balanced if there is no pair of indices (i,j) such that i < j and 
    /// s[i] = 'b' and s[j]= 'a'.
    ///
    /// Return the minimum number of deletions needed to make s balanced.
    /// 
    /// Example 1:
    /// Input: s = "aababbab"
    /// Output: 2
    /// Explanation: You can either:
    /// Delete the characters at 0-indexed positions 2 and 6 
    /// ("aababbab" -> "aaabbb"), or
    /// Delete the characters at 0-indexed positions 3 and 6 
    /// ("aababbab" -> "aabbbb").
    ///
    /// Example 2:
    /// Input: s = "bbaaaaabb"
    /// Output: 2
    /// Explanation: The only solution is to delete the first two characters.
    /// Constraints:
    /// 1. 1 <= s.length <= 105
    /// 2. s[i] is 'a' or 'b'.
    /// </summary>
    int minimumDeletions(string s);

    /// <summary>
    /// Leet code #1690. Stone Game VII
    /// 
    /// Medium
    /// 
    /// Alice and Bob take turns playing a game, with Alice starting first.
    /// There are n stones arranged in a row. On each player's turn, they can 
    /// remove either the leftmost stone or the rightmost stone from the row and 
    /// receive points equal to the sum of the remaining stones' values in the 
    /// row. The winner is the one with the higher score when there are no stones 
    /// left to remove.
    ///
    /// Bob found that he will always lose this game (poor Bob, he always loses), 
    /// so he decided to minimize the score's difference. Alice's goal is to 
    /// maximize the difference in the score.
    /// Given an array of integers stones where stones[i] represents the value 
    /// of the ith stone from the left, return the difference in Alice and Bob's 
    /// score if they both play optimally.
    /// 
    /// Example 1:
    /// Input: stones = [5,3,1,4,2]
    /// Output: 6
    /// Explanation: 
    /// - Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, 
    ///   stones = [5,3,1,4].
    /// - Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, 
    ///   stones = [3,1,4].
    /// - Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, 
    ///   stones = [1,4].
    /// - Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
    /// - Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
    /// The score difference is 18 - 12 = 6.
    ///
    /// Example 2:
    /// Input: stones = [7,90,5,1,100,10,10,2]
    /// Output: 122
    ///
    /// Constraints:
    /// 1. n == stones.length
    /// 2. 2 <= n <= 1000
    /// 3. 1 <= stones[i] <= 1000
    /// </summary>
    int stoneGameVII(vector<int>& stones);

    /// <summary>
    /// Leet code #1687. Delivering Boxes from Storage to Ports
    /// 
    /// Hard
    /// 
    /// You have the task of delivering some boxes from storage to their ports 
    /// using only one ship. However, this ship has a limit on the number of 
    /// boxes and the total weight that it can carry.
    /// You are given an array boxes, where boxes[i] = [ports[i] weight[i]], 
    /// and three integers portsCount, maxBoxes, and maxWeight.
    ///
    /// ports[i] is the port where you need to deliver the ith box and weights[i]
    /// is the weight of the ith box.
    /// portsCount is the number of ports.
    /// maxBoxes and maxWeight are the respective box and weight limits of the 
    /// ship.
    /// The boxes need to be delivered in the order they are given. The ship will 
    /// follow these steps:
    ///
    /// The ship will take some number of boxes from the boxes queue, not 
    /// violating the maxBoxes and maxWeight constraints.
    /// For each loaded box in order, the ship will make a trip to the port the 
    /// box needs to be delivered to and deliver it. If the ship is already at 
    /// the correct port, no trip is needed, and the box can immediately be 
    /// delivered.
    /// The ship then makes a return trip to storage to take more boxes from
    /// the queue.
    /// The ship must end at storage after all the boxes have been delivered.
    ///
    /// Return the minimum number of trips the ship needs to make to deliver all 
    /// boxes to their respective ports.
    /// 
    /// Example 1:
    ///
    /// Input: boxes = [[1,1],[2,1],[1,1]], portsCount = 2, maxBoxes = 3, 
    /// maxWeight = 3
    /// Output: 4
    /// Explanation: The optimal strategy is as follows: 
    /// - The ship takes all the boxes in the queue, goes to port 1, then port 2, 
    /// then port 1 again, then returns to storage. 4 trips.
    /// So the total number of trips is 4.
    /// Note that the first and third boxes cannot be delivered together because the 
    /// boxes need to be delivered in order (i.e. the second box needs to be 
    /// delivered at port 2 before the third box).
    ///
    /// Example 2:
    /// Input: boxes = [[1,2],[3,3],[3,1],[3,1],[2,4]], portsCount = 3, 
    /// maxBoxes = 3, maxWeight = 6
    /// Output: 6
    /// Explanation: The optimal strategy is as follows: 
    /// - The ship takes the first box, goes to port 1, then returns to storage. 2 
    /// trips.
    /// - The ship takes the second, third and fourth boxes, goes to port 3, then 
    /// returns to storage. 2 trips.
    /// - The ship takes the fifth box, goes to port 3, then returns to storage. 2 
    /// trips.
    /// So the total number of trips is 2 + 2 + 2 = 6.
    ///
    /// Example 3:
    /// Input: boxes = [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]], portsCount = 3, 
    /// maxBoxes = 6, maxWeight = 7
    /// Output: 6
    /// Explanation: The optimal strategy is as follows:
    /// - The ship takes the first and second boxes, goes to port 1, then returns 
    ///   to storage. 2 trips.
    /// - The ship takes the third and fourth boxes, goes to port 2, then returns 
    ///   to storage. 2 trips.
    /// - The ship takes the fifth and sixth boxes, goes to port 3, then returns 
    ///   to storage. 2 trips.
    /// So the total number of trips is 2 + 2 + 2 = 6.
    ///
    /// Example 4:
    /// Input: boxes = [[2,4],[2,5],[3,1],[3,2],[3,7],[3,1],[4,4],[1,3],[5,2]], 
    /// portsCount = 5, maxBoxes = 5, maxWeight = 7
    /// Output: 14
    /// Explanation: The optimal strategy is as follows:
    /// - The ship takes the first box, goes to port 2, then storage. 2 trips.
    /// - The ship takes the second box, goes to port 2, then storage. 2 trips.
    /// - The ship takes the third and fourth boxes, goes to port 3, then storage. 
    /// 2 trips.
    /// - The ship takes the fifth box, goes to port 3, then storage. 2 
    /// trips.
    /// - The ship takes the sixth and seventh boxes, goes to port 3, then port 4, 
    /// then storage. 3 trips. 
    /// - The ship takes the eighth and ninth boxes, goes to port 1, then port 5, 
    /// then storage. 3 trips.
    /// So the total number of trips is 2 + 2 + 2 + 2 + 3 + 3 = 14.
    ///
    /// Constraints:
    /// 1. 1 <= boxes.length <= 10^5
    /// 2. 1 <= portsCount, maxBoxes, maxWeight <= 10^5
    /// 3. 1 <= ports[i] <= portsCount
    /// 4. 1 <= weights[i] <= maxWeight
    /// </summary>
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight);

    /// <summary>
    /// Leet code #1692. Count Ways to Distribute Candies
    /// 
    /// Hard
    /// 
    /// There are n unique candies (labeled 1 through n) and k bags. You are 
    /// asked to distribute all the candies into the bags such that every bag 
    /// has at least one candy.
    ///
    /// There can be multiple ways to distribute the candies. Two ways are 
    /// considered different if the candies in one bag in the first way are 
    /// not all in the same bag in the second way. The order of the bags and 
    /// the order of the candies within each bag do not matter.
    ///
    /// For example, (1), (2,3) and (2), (1,3) are considered different 
    /// because candies 2 and 3 in the bag (2,3) in the first way are not in 
    /// the same bag in the second way (they are split between the bags (2) and 
    /// (1,3)). However, (1), (2,3) and (3,2), (1) are considered the same 
    /// because the candies in each bag are all in the same bags in both ways.
    ///
    /// Given two integers, n and k, return the number of different ways to 
    /// distribute the candies. As the answer may be too large, return it 
    /// modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: n = 3, k = 2
    /// Output: 3
    /// Explanation: You can distribute 3 candies into 2 bags in 3 ways:
    /// (1), (2,3)
    /// (1,2), (3)
    /// (1,3), (2)
    ///
    /// Example 2:
    /// Input: n = 4, k = 2
    /// Output: 7
    /// Explanation: You can distribute 4 candies into 2 bags in 7 ways:
    /// (1), (2,3,4)
    /// (1,2), (3,4)
    /// (1,3), (2,4)
    /// (1,4), (2,3)
    /// (1,2,3), (4)
    /// (1,2,4), (3)
    /// (1,3,4), (2)
    ///
    /// Example 3:
    /// Input: n = 20, k = 5
    /// Output: 206085257
    /// Explanation: You can distribute 20 candies into 5 bags in 
    /// 1881780996 ways. 1881780996 modulo 10^9 + 7 = 206085257.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= n <= 1000
    /// </summary>
    int waysToDistribute(int n, int k);

    /// <summary>
    /// Leet code #1682. Longest Palindromic Subsequence II
    /// 
    /// Medium
    /// 
    /// A subsequence of a string s is considered a good palindromic 
    /// subsequence if:
    ///
    /// It is a subsequence of s.
    /// It is a palindrome (has the same value if reversed).
    /// It has an even length.
    /// No two consecutive characters are equal, except the two middle ones.
    /// For example, if s = "abcabcabb", then "abba" is considered a good 
    /// palindromic subsequence, while "bcb" (not even length) and "bbbb" 
    /// (has equal consecutive characters) are not.
    ///
    /// Given a string s, return the length of the longest good palindromic 
    /// subsequence in s.
    ///
    /// Example 1:
    /// Input: s = "bbabab"
    /// Output: 4
    /// Explanation: The longest good palindromic subsequence of s is "baab".
    ///
    /// Example 2:
    /// Input: s = "dcbccacdb"
    /// Output: 4
    /// Explanation: The longest good palindromic subsequence of s is "dccd".
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 250
    /// 2. s consists of lowercase English letters.
    /// </summary>
    int longestPalindromeSubseqII(string s);

    /// <summary>
    /// Leet code 1746. Maximum Subarray Sum After One Operation
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums. You must perform exactly one 
    /// operation where you can replace one element nums[i] with 
    /// nums[i] * nums[i]. 
    /// Return the maximum possible subarray sum after exactly one operation. 
    /// The subarray must be non-empty.
    ///
    /// Example 1: 
    /// Input: nums = [2,-1,-4,-3]
    /// Output: 17
    /// Explanation: You can perform the operation on index 2 
    /// (0-indexed) to make nums = [2,-1,16,-3]. Now, the maximum 
    /// subarray sum is 2 + -1 + 16 = 17.
    ///
    /// Example 2:
    /// Input: nums = [1,-1,1,1,-1,-1,1]
    /// Output: 4
    /// Explanation: You can perform the operation on index 1 (0-indexed) 
    /// to make nums = [1,1,1,1,-1,-1,1]. Now, the maximum subarray 
    /// sum is 1 + 1 + 1 + 1 = 4.
    ///
    /// Constraints:
    ///  1. 1 <= nums.length <= 10^5
    /// -10^4 <= nums[i] <= 10^4
    /// </summary>
    int maxSumAfterOperation(vector<int>& nums);

    /// <summary>
    /// Leet code 1774. Closest Dessert Cost
    /// 
    /// Medium
    /// 
    /// You would like to make dessert and are preparing to buy the 
    /// ingredients. You have n ice cream base flavors and m types of 
    /// toppings to choose from. You must follow these rules when 
    /// making your dessert:
    ///
    /// There must be exactly one ice cream base.
    /// You can add one or more types of topping or have no toppings at all.
    /// There are at most two of each type of topping.
    /// You are given three inputs:
    /// baseCosts, an integer array of length n, where each baseCosts[i] 
    /// represents the price of the ith ice cream base flavor.
    /// toppingCosts, an integer array of length m, where each toppingCosts[i]
    /// is the price of one of the ith topping. 
    /// target, an integer representing your target price for dessert.
    /// You want to make a dessert with a total cost as close to target as 
    /// possible.
    ///
    /// Return the closest possible cost of the dessert to target. If there 
    /// are multiple, return the lower one.
    ///
    /// Example 1:
    /// Input: baseCosts = [1,7], toppingCosts = [3,4], target = 10
    /// Output: 10
    /// Explanation: Consider the following combination (all 0-indexed):
    /// - Choose base 1: cost 7
    /// - Take 1 of topping 0: cost 1 x 3 = 3
    /// - Take 0 of topping 1: cost 0 x 4 = 0
    /// Total: 7 + 3 + 0 = 10.
    ///
    /// Example 2:
    /// Input: baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
    /// Output: 17
    /// Explanation: Consider the following combination (all 0-indexed):
    /// - Choose base 1: cost 3
    /// - Take 1 of topping 0: cost 1 x 4 = 4
    /// - Take 2 of topping 1: cost 2 x 5 = 10
    /// - Take 0 of topping 2: cost 0 x 100 = 0
    /// Total: 3 + 4 + 10 + 0 = 17. You cannot make a dessert with a 
    /// total cost of 18.
    ///
    /// Example 3:
    /// Input: baseCosts = [3,10], toppingCosts = [2,5], target = 9
    /// Output: 8
    /// Explanation: It is possible to make desserts with cost 8 and 10. 
    /// Return 8 as it is the lower cost.
    ///
    /// Example 4:
    /// Input: baseCosts = [10], toppingCosts = [1], target = 1
    /// Output: 10
    /// Explanation: Notice that you don't have to have any toppings, 
    /// but you must have exactly one base.
    ///  
    /// Constraints:
    /// 1. n == baseCosts.length
    /// 2. m == toppingCosts.length
    /// 3. 1 <= n, m <= 10
    /// 4. 1 <= baseCosts[i], toppingCosts[i] <= 10^4
    /// 5. 1 <= target <= 10^4
    /// </summary>
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target);

    /// <summary>
    /// Leet code 1787. Make the XOR of All Segments Equal to Zero
    /// 
    /// Hard
    /// 
    /// You are given an array nums and an integer k. The XOR of a 
    /// segment [left, right] where left <= right is the XOR of all 
    /// the elements with indices between left and right, inclusive: 
    /// nums[left] XOR nums[left+1] XOR ... XOR nums[right].
    ///
    /// Return the minimum number of elements to change in the array 
    /// such that the XOR of all segments of size k is equal to zero.
    ///
    /// Example 1:
    /// Input: nums = [1,2,0,3,0], k = 1
    /// Output: 3
    /// Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].
    ///
    /// Example 2:
    /// Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
    /// Output: 3
    /// Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to 
    /// [3,4,7,3,4,7,3,4,7].
    ///
    /// Example 3:
    /// Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
    /// Output: 3
    /// Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to 
    /// [1,2,3,1,2,3,1,2,3].
    /// 
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 2000
    /// 2. 0 <= nums[i] < 2^10
    /// </summary>
    int minChanges(vector<int>& nums, int k);

    /// <summary>
    /// Leet code 1745. Palindrome Partitioning IV
    /// 
    /// Hard
    /// 
    /// Given a string s, return true if it is possible to split the string 
    /// s into three non-empty palindromic substrings. Otherwise, return false.
    ///
    /// A string is said to be palindrome if it the same string when reversed.
    /// 
    /// Example 1:
    /// Input: s = "abcbdd"
    /// Output: true
    /// Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings 
    /// are palindromes.
    ///
    /// Example 2:
    /// Input: s = "bcbddxy"
    /// Output: false
    /// Explanation: s cannot be split into 3 palindromes.
    /// Constraints:
    /// 1. 3 <= s.length <= 2000
    /// 2. s consists only of lowercase English letters.
    /// </summary>
    bool checkPartitioning(string s);

    /// <summary>
    /// Leet code 1771. Maximize Palindrome Length From Subsequences
    /// 
    /// Hard
    /// 
    /// Choose some non-empty subsequence subsequence1 from word1.
    /// Choose some non-empty subsequence subsequence2 from word2.
    /// Concatenate the subsequences: subsequence1 + subsequence2, to make 
    /// the string.
    /// Return the length of the longest palindrome that can be constructed 
    /// in the described manner. If no palindromes can be constructed, 
    /// return 0.
    ///
    /// A subsequence of a string s is a string that can be made by 
    /// deleting some (possibly none) characters from s without changing 
    /// the order of the remaining characters.
    ///
    /// A palindrome is a string that reads the same forward as well as 
    /// backward.
    /// 
    /// Example 1:
    /// Input: word1 = "cacb", word2 = "cbba"
    /// Output: 5
    /// Explanation: Choose "ab" from word1 and "cba" from word2 to make 
    /// "abcba", which is a palindrome.
    ///
    /// Example 2:
    /// Input: word1 = "ab", word2 = "ab"
    /// Output: 3
    /// Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", 
    /// which is a palindrome.
    ///
    /// Example 3:
    /// Input: word1 = "aa", word2 = "bb"
    /// Output: 0
    /// Explanation: You cannot construct a palindrome from the described 
    /// method, so return 0.
    ///
    /// Constraints:
    /// 1. 1 <= word1.length, word2.length <= 1000
    /// 2. word1 and word2 consist of lowercase English letters.
    /// </summary>
    int longestPalindrome(string word1, string word2);

    /// <summary>
    /// Leet code 1824. Minimum Sideway Jumps
    /// 
    /// Medium
    /// 
    /// There is a 3 lane road of length n that consists of n + 1 points 
    /// labeled from 0 to n. A frog starts at point 0 in the second lane 
    /// and wants to jump to point n. However, there could be obstacles along 
    /// the way.
    ///
    /// You are given an array obstacles of length n + 1 where each 
    /// obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane 
    /// obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles 
    /// at point i. There will be at most one obstacle in the 3 lanes at each 
    /// point.
    ///
    /// For example, if obstacles[2] == 1, then there is an obstacle on 
    /// lane 1 at point 2.
    /// The frog can only travel from point i to point i + 1 on the same lane 
    /// if there is not an obstacle on the lane at point i + 1. To avoid 
    /// obstacles, the frog can also perform a side jump to jump to another 
    /// lane (even if they are not adjacent) at the same point if there is no 
    /// obstacle on the new lane.
    ///
    /// For example, the frog can jump from lane 3 at point 3 to lane 1 at 
    /// point 3.
    /// Return the minimum number of side jumps the frog needs to reach any 
    /// lane at point n starting from lane 2 at point 0.
    ///
    /// Note: There will be no obstacles on points 0 and n.
    /// 
    /// Example 1:
    /// Input: obstacles = [0,1,2,3,0]
    /// Output: 2 
    /// Explanation: The optimal solution is shown by the arrows above. 
    /// There are 2 side jumps (red arrows).
    /// Note that the frog can jump over obstacles only when making side 
    /// jumps (as shown at point 2).
    ///
    /// Example 2:
    /// Input: obstacles = [0,1,1,3,3,0]
    /// Output: 0
    /// Explanation: There are no obstacles on lane 2. No side jumps 
    /// are required.
    ///
    /// Example 3:
    /// Input: obstacles = [0,2,1,0,3,0]
    /// Output: 2
    /// Explanation: The optimal solution is shown by the arrows above. There 
    /// are 2 side jumps.
    ///
    /// Constraints:
    /// 1. obstacles.length == n + 1
    /// 2. 1 <= n <= 5 * 10^5
    /// 3. 0 <= obstacles[i] <= 3
    /// 4. obstacles[0] == obstacles[n] == 0
    /// </summary>
    int minSideJumps(vector<int>& obstacles);

    /// <summary>
    /// Leet code 1751. Maximum Number of Events That Can Be Attended II
    /// 
    /// Hard
    /// 
    /// You are given an array of events where events[i] = [startDayi, 
    /// endDayi, valuei]. The ith event starts at startDayi and ends at 
    /// endDayi, and if you attend this event, you will receive a value of 
    /// valuei. You are also given an integer k which represents the 
    /// maximum number of events you can attend.
    ///
    /// You can only attend one event at a time. If you choose to attend 
    /// an event, you must attend the entire event. Note that the end day 
    /// is inclusive: that is, you cannot attend two events where one of 
    /// them starts and the other ends on the same day.
    ///
    /// Return the maximum sum of values that you can receive by attending 
    /// events.
    ///
    /// Example 1:
    /// Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
    /// Output: 7
    /// Explanation: Choose the green events, 0 and 1 (0-indexed) for a total 
    /// value of 4 + 3 = 7.
    ///
    /// Example 2:
    /// 
    /// Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
    /// Output: 10
    /// Explanation: Choose event 2 for a total value of 10.
    /// Notice that you cannot attend any other event as they overlap, and 
    /// that you do not have to attend k events.
    ///
    /// Example 3:
    /// Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
    /// Output: 9
    /// Explanation: Although the events do not overlap, you can only attend 
    /// 3 events. Pick the highest valued three.
    ///
    /// Constraints:
    /// 1. 1 <= k <= events.length
    /// 2. 1 <= k * events.length <= 10^6
    /// 3. 1 <= startDayi <= endDayi <= 10^9
    /// 4. 1 <= valuei <= 10^6
    /// </summary>
    int maxValue(vector<vector<int>>& events, int k);

    /// <summary>
    /// Leet code 1866. Number of Ways to Rearrange Sticks With K Sticks 
    ///                 Visible
    /// 
    /// Hard
    /// 
    /// There are n uniquely-sized sticks whose lengths are integers from 1 to 
    /// n. You want to arrange the sticks such that exactly k sticks are 
    /// visible from the left. A stick is visible from the left if there are no 
    /// longer sticks to the left of it.
    ///  
    /// For example, if the sticks are arranged [1,3,2,5,4], then the sticks 
    /// with lengths 1, 3, and 5 are visible from the left.
    /// Given n and k, return the number of such arrangements. Since the answer 
    /// may be large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: n = 3, k = 2
    /// Output: 3
    /// Explanation: [1,3,2], [2,3,1], and [2,1,3] are the only arrangements 
    /// such that exactly 2 sticks are visible.
    /// The visible sticks are underlined.
    ///
    /// Example 2:
    /// Input: n = 5, k = 5
    /// Output: 1
    /// Explanation: [1,2,3,4,5] is the only arrangement such that all 5 sticks
    /// are visible.
    /// The visible sticks are underlined.
    ///
    /// Example 3:
    /// Input: n = 20, k = 11
    /// Output: 647427950
    /// Explanation: There are 647427950 (mod 10^9 + 7) ways to rearrange the 
    /// sticks such that exactly 11 sticks are visible.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// 2. 1 <= k <= n
    /// </summary>
    int rearrangeSticks(int n, int k);

    /// <summary>
    /// Leet code 1872. Stone Game VIII 
    /// 
    /// Hard
    /// 
    /// Alice and Bob take turns playing a game, with Alice starting first. 
    /// There are n stones arranged in a row. On each player's turn, while the 
    /// number of stones is more than one, they will do the following:
    ///
    /// Choose an integer x > 1, and remove the leftmost x stones from the row.
    /// Add the sum of the removed stones' values to the player's score.
    /// Place a new stone, whose value is equal to that sum, on the left side 
    /// of the row.
    /// The game stops when only one stone is left in the row.
    ///
    /// The score difference between Alice and Bob is (Alice's score - Bob's 
    /// score). Alice's goal is to maximize the score difference, and Bob's 
    /// goal is the minimize the score difference.
    /// Given an integer array stones of length n where stones[i] represents 
    /// the value of the ith stone from the left, return the score difference 
    /// between Alice and Bob if they both play optimally.
    /// 
    /// Example 1:
    /// Input: stones = [-1,2,-3,4,-5]
    /// Output: 5
    /// Explanation:
    /// - Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to 
    /// her score, and places a stone of
    /// value 2 on the left. stones = [2,-5].
    /// - Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, 
    /// and places a stone of value -3 on the left. stones = [-3].
    /// The difference between their scores is 2 - (-3) = 5.
    ///
    /// Example 2:
    /// Input: stones = [7,-6,5,10,5,-2,-6]
    /// Output: 13
    /// Explanation:
    /// - Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + 
    /// (-6) = 13 to her score, and places a
    /// stone of value 13 on the left. stones = [13].
    /// The difference between their scores is 13 - 0 = 13.
    ///
    /// Example 3:
    /// Input: stones = [-10,-12]
    /// Output: -22
    /// Explanation:
    /// - Alice can only make one move, which is to remove both stones. She 
    ///   adds (-10) + (-12) = -22 to her
    /// score and places a stone of value -22 on the left. stones = [-22].
    /// The difference between their scores is (-22) - 0 = -22.
    ///
    /// Constraints:
    /// 1. n == stones.length
    /// 2. 2 <= n <= 10^5
    /// 3. -10^4 <= stones[i] <= 10^4
    /// </summary>
    int stoneGameVIII(vector<int>& stones);

    /// <summary>
    /// Leet code 1883. Minimum Skips to Arrive at Meeting On Time
    /// 
    /// Hard
    /// 
    /// You are given an integer hoursBefore, the number of hours you 
    /// have to travel to your meeting. To arrive at your meeting, you 
    /// have to travel through n roads. The road lengths are given as 
    /// an integer array dist of length n, where dist[i] describes the 
    /// length of the ith road in kilometers. In addition, you are 
    /// given an integer speed, which is the speed (in km/h) you will 
    /// travel at.
    ///
    /// After you travel road i, you must rest and wait for the next 
    /// integer hour before you can begin traveling on the next road. 
    /// Note that you do not have to rest after traveling the last road 
    /// because you are already at the meeting.
    ///
    /// For example, if traveling a road takes 1.4 hours, you must wait 
    /// until the 2 hour mark before traveling the next road. If traveling 
    /// a road takes exactly 2 hours, you do not need to wait.
    /// However, you are allowed to skip some rests to be able to arrive 
    /// on time, meaning you do not need to wait for the next integer hour. 
    /// Note that this means you may finish traveling future roads at 
    /// different hour marks.
    ///
    /// For example, suppose traveling the first road takes 1.4 hours and 
    /// traveling the second road takes 0.6 hours. Skipping the rest after 
    /// the first road will mean you finish traveling the second road right 
    /// at the 2 hour mark, letting you start traveling the third road 
    /// immediately.
    /// Return the minimum number of skips required to arrive at the meeting 
    /// on time, or -1 if it is impossible.
    /// 
    /// Example 1:
    /// Input: dist = [1,3,2], speed = 4, hoursBefore = 2
    /// Output: 1
    /// Explanation:
    /// Without skipping any rests, you will arrive in (1/4 + 3/4) + 
    /// (3/4 + 1/4) + (2/4) = 2.5 hours.
    /// You can skip the first rest to arrive in ((1/4 + 0) + (3/4 + 0)) + 
    /// (2/4) = 1.5 hours.
    /// Note that the second rest is shortened because you finish traveling 
    /// the second road at an integer hour due to skipping the first rest.
    ///
    /// Example 2:
    /// Input: dist = [7,3,5,5], speed = 2, hoursBefore = 10
    /// Output: 2
    /// Explanation:
    /// Without skipping any rests, you will arrive in (7/2 + 1/2) + 
    /// (3/2 + 1/2) + (5/2 + 1/2) + (5/2) = 11.5 hours.
    /// You can skip the first and third rest to arrive in ((7/2 + 0) + 
    /// (3/2 + 0)) + ((5/2 + 0) + (5/2)) = 10 hours.
    ///
    /// Example 3:
    /// Input: dist = [7,3,5,5], speed = 1, hoursBefore = 10
    /// Output: -1
    /// Explanation: It is impossible to arrive at the meeting on time even if 
    /// you skip all the rests.
    ///
    /// Constraints:
    /// 1. n == dist.length
    /// 2. 1 <= n <= 1000
    /// 3. 1 <= dist[i] <= 10^5
    /// 4. 1 <= speed <= 10^6
    /// 5. 1 <= hoursBefore <= 10^7
    /// </summary>
    int minSkips(vector<int>& dist, int speed, int hoursBefore);

    /// <summary>
    /// Leet code 1955. Count Number of Special Subsequences
    ///                                  
    /// Hard
    /// 
    /// A sequence is special if it consists of a positive number of 0s, 
    /// followed by a positive number of 1s, then a positive number of 2s.
    /// For example, [0,1,2] and [0,0,1,1,1,2] are special.
    /// In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
    /// Given an array nums (consisting of only integers 0, 1, and 2), return 
    /// the number of different subsequences that are special. Since the 
    /// answer may be very large, return it modulo 10^9 + 7.
    ///
    /// A subsequence of an array is a sequence that can be derived from the 
    /// array by deleting some or no elements without changing the order of 
    /// the remaining elements. Two subsequences are different if the set of 
    /// indices chosen are different.
    /// 
    /// Example 1:
    /// Input: nums = [0,1,2,2]
    /// Output: 3
    /// Explanation: The special subsequences are [0,1,2,2], [0,1,2,2], 
    /// and [0,1,2,2].
    ///
    /// Example 2:
    /// Input: nums = [2,2,0,0]
    /// Output: 0
    /// Explanation: There are no special subsequences in [2,2,0,0].
    ///
    /// Example 3:
    /// Input: nums = [0,1,2,0,1,2]
    /// Output: 7
    /// Explanation: The special subsequences are:
    /// - [0,1,2,0,1,2]
    /// - [0,1,2,0,1,2]
    /// - [0,1,2,0,1,2]
    /// - [0,1,2,0,1,2]
    /// - [0,1,2,0,1,2]
    /// - [0,1,2,0,1,2]
    /// - [0,1,2,0,1,2]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 2
    /// </summary>
    int countSpecialSubsequences(vector<int>& nums);

    /// <summary>
    /// Leet code 1911. Maximum Alternating Subsequence Sum
    ///                                                
    /// Medium
    /// 
    /// The alternating sum of a 0-indexed array is defined as the sum of the 
    /// elements at even indices minus the sum of the elements at odd indices.
    ///
    /// For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
    /// Given an array nums, return the maximum alternating sum of any 
    /// subsequence of nums (after reindexing the elements of the subsequence).
    ///
    /// A subsequence of an array is a new array generated from the original 
    /// array by deleting some elements (possibly none) without changing the 
    /// remaining elements' relative order. For example, [2,7,4] is a 
    /// subsequence of [4,2,3,7,2,1,4] (the underlined elements), while 
    /// [2,4,2] is not.
    /// 
    /// Example 1:
    /// Input: nums = [4,2,5,3]
    /// Output: 7
    /// Explanation: It is optimal to choose the subsequence [4,2,5] with 
    /// alternating sum (4 + 5) - 2 = 7.
    ///
    /// Example 2:
    /// Input: nums = [5,6,7,8]
    /// Output: 8
    /// Explanation: It is optimal to choose the subsequence [8] with 
    /// alternating sum 8.
    ///
    /// Example 3:
    /// Input: nums = [6,2,1,2,4,5]
    /// Output: 10
    /// Explanation: It is optimal to choose the subsequence [6,1,5] with 
    /// alternating sum (6 + 5) - 1 = 10.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    long long maxAlternatingSum(vector<int>& nums);


    /// <summary>
    /// Leet code 1977. Number of Ways to Separate Numbers
    ///                                                                 
    /// Hard
    /// 
    /// You wrote down many positive integers in a string called num. However,
    /// you realized that you forgot to add commas to seperate the different 
    /// numbers. You remember that the list of integers was non-decreasing 
    /// and that no integer had leading zeros.
    ///
    /// Return the number of possible lists of integers that you could have 
    /// written down to get the string num. Since the answer may be large, 
    /// return it modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: num = "327"
    /// Output: 2
    /// Explanation: You could have written down the numbers:
    /// 3, 27
    /// 327
    ///
    /// Example 2:
    /// Input: num = "094"
    /// Output: 0
    /// Explanation: No numbers can have leading zeros and all numbers must be 
    /// positive.
    ///
    /// Example 3:
    /// Input: num = "0"
    /// Output: 0
    /// Explanation: No numbers can have leading zeros and all numbers must 
    /// be positive.
    ///
    /// Example 4:
    /// Input: num = "9999999999999"
    /// Output: 101
    ///
    /// Constraints:
    /// 1. 1 <= num.length <= 3500
    /// 2. num consists of digits '0' through '9'.
    /// </summary>
    int numberOfCombinations(string num);

    /// <summary>
    /// Leet code 1987. Number of Unique Good Subsequences
    ///                                                                 
    /// Hard
    /// 
    /// You are given a binary string binary. A subsequence of binary is 
    /// considered good if it is not empty and has no leading zeros (with 
    /// the exception of "0").
    ///
    /// Find the number of unique good subsequences of binary.
    ///
    /// For example, if binary = "001", then all the good subsequences are 
    /// ["0", "0", "1"], so the unique good subsequences are "0" and "1". 
    /// Note that subsequences "00", "01", and "001" are not good because 
    /// they have leading zeros.
    /// Return the number of unique good subsequences of binary. Since the 
    /// answer may be very large, return it modulo 10^9 + 7.
    ///
    /// A subsequence is a sequence that can be derived from another sequence 
    /// by deleting some or no elements without changing the order of the 
    /// remaining elements.
    /// 
    /// Example 1:
    /// Input: binary = "001"
    /// Output: 2
    /// Explanation: The good subsequences of binary are ["0", "0", "1"].
    /// The unique good subsequences are "0" and "1".
    ///
    /// Example 2:
    /// Input: binary = "11"
    /// Output: 2
    /// Explanation: The good subsequences of binary are ["1", "1", "11"].
    /// The unique good subsequences are "1" and "11".
    ///
    /// Example 3:
    /// Input: binary = "101"
    /// Output: 5
    /// Explanation: The good subsequences of binary are ["1", "0", "1", "10",
    /// "11", "101"]. 
    /// The unique good subsequences are "0", "1", "10", "11", and "101".
    /// 
    /// Constraints:
    /// 1. 1 <= binary.length <= 10^5
    /// 2. binary consists of only '0's and '1's.
    /// </summary>
    int numberOfUniqueGoodSubsequences(string binary);

    /// <summary>
    /// Leet 1997. First Day Where You Have Been in All the Rooms
    ///                                                                 
    /// Medium
    /// 
    /// There are n rooms you need to visit, labeled from 0 to n - 1. Each day 
    /// is labeled, starting from 0. You will go in and visit one room a day.
    ///
    /// Initially on day 0, you visit room 0. The order you visit the rooms 
    /// for the coming days is determined by the following rules and a given 
    /// 0-indexed array nextVisit of length n:
    ///
    /// Assuming that on a day, you visit room i,
    /// if you have been in room i an odd number of times (including the 
    /// current visit), on the next day you will visit a room with a lower or 
    /// equal room number specified by nextVisit[i] where 
    /// 0 <= nextVisit[i] <= i;
    /// if you have been in room i an even number of times (including the 
    /// current visit), on the next day you will visit room (i + 1) mod n.
    /// Return the label of the first day where you have been in all the rooms. 
    /// It can be shown that such a day exists. Since the answer may be very 
    /// large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: nextVisit = [0,0]
    /// Output: 2
    /// Explanation:
    /// - On day 0, you visit room 0. The total times you have been in 
    ///   room 0 is 1, which is odd.
    ///   On the next day you will visit room nextVisit[0] = 0
    /// - On day 1, you visit room 0, The total times you have been in 
    ///   room 0 is 2, which is even.
    ///   On the next day you will visit room (0 + 1) mod 2 = 1
    /// - On day 2, you visit room 1. This is the first day where you 
    ///   have been in all the rooms.
    ///
    /// Example 2:
    /// Input: nextVisit = [0,0,2]
    /// Output: 6
    /// Explanation:
    /// Your room visiting order for each day is: [0,0,1,0,0,1,2,...].
    /// Day 6 is the first day where you have been in all the rooms.
    ///
    /// Example 3:
    /// Input: nextVisit = [0,1,2,0]
    /// Output: 6
    /// Explanation:
    /// Your room visiting order for each day is: [0,0,1,1,2,2,3,...].
    /// Day 6 is the first day where you have been in all the rooms.
    /// 
    /// Constraints:
    /// 1. n == nextVisit.length
    /// 2. 2 <= n <= 10^5
    /// 3. 0 <= nextVisit[i] <= i
    /// </summary>
    int firstDayBeenInAllRooms(vector<int>& nextVisit); 

    /// <summary>
    /// Leet Code 1959. Minimum Total Space Wasted With K Resizing Operations
    ///                                                                 
    /// Medium
    /// 
    /// You are currently designing a dynamic array. You are given a 0-indexed 
    /// integer array nums, where nums[i] is the number of elements that will 
    /// be in the array at time i. In addition, you are given an integer k, 
    /// the maximum number of times you can resize the array (to any size).
    ///
    /// The size of the array at time t, sizet, must be at least nums[t] 
    /// because there needs to be enough space in the array to hold all the 
    /// elements. The space wasted at time t is defined as sizet - nums[t], 
    /// and the total space wasted is the sum of the space wasted across 
    /// every time t where 0 <= t < nums.length.
    ///
    /// Return the minimum total space wasted if you can resize the array at 
    /// most k times.
    /// 
    /// Note: The array can have any size at the start and does not count 
    /// towards the number of resizing operations.
    ///
    /// Example 1:
    /// Input: nums = [10,20], k = 0
    /// Output: 10
    /// Explanation: size = [20,20].
    /// We can set the initial size to be 20.
    /// The total wasted space is (20 - 10) + (20 - 20) = 10.
    ///
    /// Example 2:
    /// Input: nums = [10,20,30], k = 1
    /// Output: 10
    /// Explanation: size = [20,20,30].
    /// We can set the initial size to be 20 and resize to 30 at time 2. 
    /// The total wasted space is (20 - 10) + (20 - 20) + (30 - 30) = 10.
    ///
    /// Example 3:
    /// Input: nums = [10,20,15,30,20], k = 2
    /// Output: 15
    /// Explanation: size = [10,20,20,30,30].
    /// We can set the initial size to 10, resize to 20 at time 1, and 
    /// resize to 30 at time 3.
    /// The total wasted space is (10 - 10) + (20 - 20) + (20 - 15) + 
    /// (30 - 30) + (30 - 20) = 15.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 200
    /// 2. 1 <= nums[i] <= 10^6
    /// 3. 0 <= k <= nums.length - 1
    /// </summary>
    int minSpaceWastedKResizing(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2008. Maximum Earnings From Taxi
    ///                                                                 
    /// Medium
    ///
    /// There are n points on a road you are driving your taxi on. The n 
    /// points on the road are labeled from 1 to n in the direction you 
    /// are going, and you want to drive from point 1 to point n to make 
    /// money by picking up passengers. You cannot change the direction 
    /// of the taxi.
    ///
    /// The passengers are represented by a 0-indexed 2D integer array 
    /// rides, where rides[i] = [starti, endi, tipi] denotes the ith 
    /// passenger requesting a ride from point starti to point endi who 
    /// is willing to give a tipi dollar tip.
    ///
    /// For each passenger i you pick up, you earn endi - starti + tipi 
    /// dollars. You may only drive at most one passenger at a time.
    ///
    /// Given n and rides, return the maximum number of dollars you can 
    /// earn by picking up the passengers optimally.
    ///
    /// Note: You may drop off a passenger and pick up a different 
    /// passenger at the same point.
    ///
    /// Example 1:
    ///
    /// Input: n = 5, rides = [[2,5,4],[1,5,1]]
    /// Output: 7
    /// Explanation: We can pick up passenger 0 to earn 5 - 2 + 4 = 7 
    /// dollars.
    ///
    /// Example 2:
    ///
    /// Input: n = 20, rides = [[1,6,1],[3,10,2],[10,12,3],[11,12,2],
    /// [12,15,2],[13,18,1]]
    /// Output: 20
    /// Explanation: We will pick up the following passengers:
    /// - Drive passenger 1 from point 3 to point 10 for a profit of 
    ///   10 - 3 + 2 = 9 dollars.
    /// - Drive passenger 2 from point 10 to point 12 for a profit 
    ///   of 12 - 10 + 3 = 5 dollars.
    /// - Drive passenger 5 from point 13 to point 18 for a profit 
    ///   of 18 - 13 + 1 = 6 dollars.
    /// We earn 9 + 5 + 6 = 20 dollars in total.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. 1 <= rides.length <= 3 * 10^4
    /// 3. rides[i].length == 3
    /// 4. 1 <= starti < endi <= n
    /// 5. 1 <= tipi <= 10^5
    /// </summary>
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides);

    /// <summary>
    /// Leet Code 2054. Two Best Non-Overlapping Events
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed 2D integer array of events where 
    /// events[i] = [startTimei, endTimei, valuei]. The ith event 
    /// starts at startTimei and ends at endTimei, and if you attend this 
    /// event, you will receive a value of valuei. You can choose at most 
    /// two non-overlapping events to attend such that the sum of their 
    /// values is maximized.
    ///
    /// Return this maximum sum.
    ///  
    /// Note that the start time and end time is inclusive: that is, you 
    /// cannot attend two events where one of them starts and the other 
    /// ends at the same time. More specifically, if you attend an event 
    /// with end time t, the next event must start at or after t + 1.
    /// 
    /// Example 1:
    /// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
    /// Output: 4
    /// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
    ///
    /// Example 2:
    /// Example 1 Diagram
    /// Input: events = [[1,3,2],[4,5,2],[1,5,5]]
    /// Output: 5
    /// Explanation: Choose event 2 for a sum of 5.
    ///
    /// Example 3:
    /// Input: events = [[1,5,3],[1,5,1],[6,6,5]]
    /// Output: 8
    /// Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
    /// 
    /// Constraints:
    /// 1. 2 <= events.length <= 10^5
    /// 2. events[i].length == 3
    /// 3. 1 <= startTimei <= endTimei <= 10^9
    /// 4. 1 <= valuei <= 10^6
    /// </summary>
    int maxTwoEvents(vector<vector<int>>& events);

    /// <summary>
    /// Leet Code 2036. Maximum Alternating Subarray Sum
    ///                                                                 
    /// Medium
    ///
    /// A subarray of a 0-indexed integer array is a contiguous non-empty 
    /// sequence of elements within an array.
    ///
    /// The alternating subarray sum of a subarray that ranges from 
    /// index i to j (inclusive, 0 <= i <= j < nums.length) is 
    /// nums[i] - nums[i+1] + nums[i+2] - ... +/- nums[j].
    ///
    /// Given a 0-indexed integer array nums, return the maximum alternating 
    /// subarray sum of any subarray of nums.
    ///
    /// Example 1:
    /// Input: nums = [3,-1,1,2]
    /// Output: 5
    /// Explanation:
    /// The subarray [3,-1,1] has the largest alternating subarray sum.
    /// The alternating subarray sum is 3 - (-1) + 1 = 5.
    ///
    /// Example 2:
    /// Input: nums = [2,2,2,2,2]
    /// Output: 2
    /// Explanation:
    /// The subarrays [2], [2,2,2], and [2,2,2,2,2] have the largest 
    /// alternating subarray sum.
    /// The alternating subarray sum of [2] is 2.
    /// The alternating subarray sum of [2,2,2] is 2 - 2 + 2 = 2.
    /// The alternating subarray sum of [2,2,2,2,2] is 2 - 2 + 2 - 2 + 2 = 2.
    ///
    /// Example 3:
    /// Input: nums = [1]
    /// Output: 1
    /// Explanation:
    /// There is only one non-empty subarray, which is [1].
    /// The alternating subarray sum is 1.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^5 <= nums[i] <= 10^5
    /// </summary>
    long long maximumAlternatingSubarraySum(vector<int>& nums);

    /// <summary>
    /// Leet code #628. Maximum Product of Three Numbers
    /// 
    /// Given an integer array, find three numbers whose product is maximum 
    /// and output the maximum product.
    ///
    /// Example 1:
    /// Input: [1,2,3]
    /// Output: 6
    ///
    /// Example 2:
    /// Input: [1,2,3,4]
    /// Output: 24
    ///
    /// Note:
    /// 1.The length of the given array will be in range [3,104] and all 
    ///   elements are in the range [-1000, 1000].
    /// 2.Multiplication of any three numbers in the input won't exceed the 
    ///   range of 32-bit signed integer.
    /// </summary>
    int maximumProduct(vector<int>& nums);

    /// <summary>
    /// Leet code #1125. Smallest Sufficient Team
    /// 
    /// In a project, you have a list of required skills req_skills, and a list 
    /// of people.  The i-th person people[i] contains a list of skills that 
    /// person has.
    /// Consider a sufficient team: a set of people such that for every required
    /// skill in req_skills, there is at least one person in the team who has 
    /// that skill.  We can represent these teams by the index of each person: 
    /// for example, team = [0, 1, 3] represents the people with skills people[0], 
    /// people[1], and people[3].
    /// Return any sufficient team of the smallest possible size, represented by 
    /// the index of each person.
    /// You may return the answer in any order.  It is guaranteed an answer exists.
    /// 
    /// Example 1:
    /// Input: req_skills = ["java","nodejs","reactjs"], 
    /// people = [["java"],["nodejs"],["nodejs","reactjs"]]
    /// Output: [0,2]
    ///
    /// Example 2:
    /// Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], 
    /// people = [["algorithms","math","java"],["algorithms","math","reactjs"],
    /// ["java","csharp","aws"],["reactjs","csharp"],
    /// ["csharp","math"],["aws","java"]]
    /// Output: [1,2]
    /// 
    /// Constraints:
    /// 1. 1 <= req_skills.length <= 16
    /// 2. 1 <= people.length <= 60
    /// 3. 1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
    /// 4. Elements of req_skills and people[i] are (respectively) distinct.
    /// 5. req_skills[i][j], people[i][j][k] are lowercase English letters.
    /// 6. It is guaranteed a sufficient team exists.
    /// </summary>
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people);

    /// <summary>
    /// Leet code #221. Maximal Square  
    /// 
    /// Given a 2D binary matrix filled with 0's and 1's, find the largest square 
    /// containing only 1's and return its area. 
    /// For example, given the following matrix: 
    /// 1 0 1 0 0
    /// 1 0 1 1 1
    /// 1 1 1 1 1
    /// 1 0 0 1 0
    /// Return 4. 
    /// </summary>
    int maximalSquare(vector<vector<char>>& matrix);

    /// <summary>
     /// Leet code #174. Dungeon Game 
     /// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists 
     /// of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight 
     /// his way through the dungeon to rescue the princess. 
     ///
     /// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 
     /// or below, he dies immediately. 
     /// Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
     /// other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
     /// In order to reach the princess as quickly as possible, the knight decides to move only 
     /// rightward or downward in each step. 
     /// Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
     /// For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path 
     /// RIGHT-> RIGHT -> DOWN -> DOWN.
     /// -2 (K) -3 3 
     /// -5 -10 1 
     /// 10 30 -5 (P) 
     /// Notes: 
     /// The knight's health has no upper bound.
     /// Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
     /// </summary>
    int calculateMinimumHP(vector<vector<int>>& dungeon);

    /// <summary>
    /// Leet code #902. Numbers At Most N Given Digit Set 
    /// 
    /// We have a sorted set of digits D, a non-empty subset of 
    /// {'1','2','3','4','5','6','7','8','9'}.  (Note that '0' is not included.)
    /// Now, we write numbers using these digits, using each digit as many times 
    /// as we want.  For example, if D = {'1','3','5'}, we may write numbers such 
    /// as '13', '551', '1351315'.
    ///
    /// Return the number of positive integers that can be written (using the 
    /// digits of D) that are less than or equal to N.
    ///
    /// Example 1:
    /// Input: D = ["1","3","5","7"], N = 100
    /// Output: 20
    /// Explanation: 
    /// The 20 numbers that can be written are:
    /// 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
    /// Example 2:
    ///
    /// Input: D = ["1","4","9"], N = 1000000000
    /// Output: 29523
    /// Explanation: 
    /// We can write 3 one digit numbers, 9 two digit numbers, 27 three digit 
    /// numbers,
    /// 81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
    /// 2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit 
    /// numbers.
    /// In total, this is 29523 integers that can be written using the digits of D.
    ///
    /// Note:
    /// D is a subset of digits '1'-'9' in sorted order.
    /// 1 <= N <= 10^9
    /// </summary>
    int atMostNGivenDigitSet(vector<string>& D, int N);

    /// <summary>
    /// Leet code #97. Interleaving String
    /// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
    /// For example,
    /// Given:
    /// s1 = "aabcc",
    /// s2 = "dbbca", 
    /// When s3 = "aadbbcbcac", return true.
    /// When s3 = "aadbbbaccc", return false. 
    /// </summary>
    bool isInterleave(string s1, string s2, string s3);

    /// <summary>
    /// Leet code #161. One Edit Distance
    /// 
    /// Given two strings S and T, determine if they are both one edit distance apart. 
    /// </summary>
    bool isOneEditDistance(string s, string t, size_t i, size_t j, size_t count);

    /// <summary>
    /// Leet code #161. One Edit Distance 
    /// 
    /// Given two strings S and T, determine if they are both one edit distance apart. 
    /// </summary>
    bool isOneEditDistance(string s, string t);

    /// <summary>
    /// Leet Code 2052. Minimum Cost to Separate Sentence Into Rows 
    ///                                                                 
    /// Medium
    ///
    /// You are given a string sentence containing words separated by spaces, 
    /// and an integer k. Your task is to separate sentence into rows where 
    /// the number of characters in each row is at most k. You may assume that 
    /// sentence does not begin or end with a space, and the words in sentence 
    /// are separated by a single space.
    /// You can split sentence into rows by inserting line breaks between words
    /// in sentence. A word cannot be split between two rows. Each word must be 
    /// used exactly once, and the word order cannot be rearranged. Adjacent 
    /// words in a row should be separated by a single space, and rows should 
    /// not begin or end with spaces.
    ///
    /// The cost of a row with length n is (k - n)2, and the total cost is the 
    /// sum of the costs for all rows except the last one.
    ///
    /// For example if sentence = "i love leetcode" and k = 12:
    /// Separating sentence into "i", "love", and "leetcode" has a cost of 
    /// (12 - 1)^2 + (12 - 4)^2 = 185.
    /// Separating sentence into "i love", and "leetcode" has a cost of 
    /// (12 - 6)^2 = 36.
    /// Separating sentence into "i", and "love leetcode" is not possible 
    /// because the length of "love leetcode" is greater than k.
    /// Return the minimum possible total cost of separating sentence into 
    /// rows.
    /// 
    /// Example 1:
    /// Input: sentence = "i love leetcode", k = 12
    /// Output: 36
    /// Explanation:
    /// Separating sentence into "i", "love", and "leetcode" has a cost of 
    /// (12 - 1)^2 + (12 - 4)^2 = 185.
    /// Separating sentence into "i love", and "leetcode" has a cost of 
    /// (12 - 6)^2 = 36.
    /// Separating sentence into "i", "love leetcode" is not possible 
    /// because "love leetcode" has length 13.
    /// 36 is the minimum possible total cost so return it.
    ///
    /// Example 2:
    /// Input: sentence = "apples and bananas taste great", k = 7
    /// Output: 21
    /// Explanation
    /// Separating sentence into "apples", "and", "bananas", "taste", and 
    /// "great" has a cost of (7 - 6)2 + (7 - 3)2 + (7 - 7)2 + (7 - 5)2 = 21.
    /// 21 is the minimum possible total cost so return it.
    ///
    /// Example 3:
    /// Input: sentence = "a", k = 5
    /// Output: 0
    /// Explanation:
    /// The cost of the last row is not included in the total cost, and since 
    /// there is only one row, return 0.
    ///
    /// Constraints:
    /// 1. 1 <= sentence.length <= 5000
    /// 2. 1 <= k <= 5000
    /// 3. The length of each word in sentence is at most k.
    /// 3. sentence consists of only lowercase English letters and spaces.
    /// 4. sentence does not begin or end with a space.
    /// 5. Words in sentence are separated by a single space.
    /// </summary>
    int minimumCost(string sentence, int k);

    /// <summary>
    /// Leet Code 2044. Count Number of Maximum Bitwise-OR Subsets
    ///                                                                 
    /// Medium
    ///
    /// Given an integer array nums, find the maximum possible bitwise OR 
    /// of a subset of nums and return the number of different non-empty 
    /// subsets with the maximum bitwise OR.
    ///
    /// An array a is a subset of an array b if a can be obtained from b 
    /// by deleting some (possibly zero) elements of b. Two subsets are 
    /// considered different if the indices of the elements chosen are 
    /// different.
    /// The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR 
    /// a[a.length - 1] (0-indexed).
    ///
    /// Example 1:
    /// Input: nums = [3,1]
    /// Output: 2
    /// Explanation: The maximum possible bitwise OR of a subset is 3. 
    /// There are 2 subsets with a bitwise OR of 3:
    /// - [3]
    /// - [3,1]
    ///
    /// Example 2:
    /// Input: nums = [2,2,2]
    /// Output: 7
    /// Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. 
    /// There are 23 - 1 = 7 total subsets.
    ///
    /// Example 3:
    /// Input: nums = [3,2,1,5]
    /// Output: 6
    /// Explanation: The maximum possible bitwise OR of a subset is 7. There 
    /// are 6 subsets with a bitwise OR of 7:
    /// - [3,5]
    /// - [3,1,5]
    /// - [3,2,5]
    /// - [3,2,1,5]
    /// - [2,5]
    /// - [2,1,5]
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 16
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int countMaxOrSubsets(vector<int>& nums);

    /// <summary>
    /// Leet code #416. Partition Equal Subset Sum 
    ///
    /// Given a non-empty array containing only positive integers, find if 
    /// the array can be partitioned into two subsets such that the sum of 
    /// elements in both subsets is equal. 
    /// Note:
    /// Each of the array element will not exceed 100.
    /// The array size will not exceed 200.
    /// Example 1: 
    /// Input: [1, 5, 11, 5]
    /// Output: true
    /// Explanation: The array can be partitioned as [1, 5, 5] and [11].
    /// Example 2: 
    /// Input: [1, 2, 3, 5]
    /// Output: false
    /// Explanation: The array cannot be partitioned into equal sum subsets.
    /// </summary>
    bool canPartition(vector<int>& nums);

    /// <summary>
    /// Leet code #1049. Last Stone Weight II
    /// 
    /// We have a collection of rocks, each rock has a positive integer weight.
    ///
    /// Each turn, we choose any two rocks and smash them together.  Suppose 
    /// the stones have weights x and y with x <= y.  The result of this smash is:
    ///
    /// If x == y, both stones are totally destroyed;
    /// If x != y, the stone of weight x is totally destroyed, and the stone of 
    /// weight y has new weight y-x.
    /// At the end, there is at most 1 stone left.  Return the smallest possible 
    /// weight of this stone (the weight is 0 if there are no stones left.)
    ///
    /// 
    /// Example 1:
    ///
    /// Input: [2,7,4,1,8,1]
    /// Output: 1
    /// Explanation: 
    /// We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
    /// we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
    /// we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
    /// we can combine 1 and 1 to get 0 so the array converts to [1] then that's the
    /// optimal value.
    /// 
    /// Note:
    /// 
    /// 1. 1 <= stones.length <= 30
    /// 2. 1 <= stones[i] <= 100
    /// </summary>
    int lastStoneWeightII(vector<int>& stones);

    /// <summary>
    /// Leet Code 2140. Solving Questions With Brainpower
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed 2D integer array questions where 
    /// questions[i] = [pointsi, brainpoweri].
    ///
    /// The array describes the questions of an exam, where you have to 
    /// process the questions in order (i.e., starting from question 0) and 
    /// make a decision whether to solve or skip each question. Solving 
    /// question i will earn you pointsi points but you will be unable to 
    /// solve each of the next brainpoweri questions. If you skip question i, 
    /// you get to make the decision on the next question.
    ///
    /// For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
    /// If question 0 is solved, you will earn 3 points but you will be 
    /// unable to solve questions 1 and 2.
    /// If instead, question 0 is skipped and question 1 is solved, you will 
    /// earn 4 points but you will be unable to solve questions 2 and 3.
    /// Return the maximum points you can earn for the exam.
    /// 
    /// Example 1:
    /// Input: questions = [[3,2],[4,3],[4,4],[2,5]]
    /// Output: 5
    /// Explanation: The maximum points can be earned by solving questions 0 
    /// and 3.
    /// - Solve question 0: Earn 3 points, will be unable to solve the 
    ///   next 2 questions
    /// - Unable to solve questions 1 and 2
    /// - Solve question 3: Earn 2 points
    /// Total points earned: 3 + 2 = 5. There is no other way to earn 5 or 
    ///  more points.
    ///
    /// Example 2:
    /// Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
    /// Output: 7
    /// Explanation: The maximum points can be earned by solving 
    /// questions 1 and 4.
    /// - Skip question 0
    /// - Solve question 1: Earn 2 points, will be unable to solve the 
    /// next 2 questions
    /// - Unable to solve questions 2 and 3
    /// - Solve question 4: Earn 5 points
    /// Total points earned: 2 + 5 = 7. There is no other way to earn 7 or 
    /// more points.
    ///
    /// Constraints:
    /// 1. 1 <= questions.length <= 10^5
    /// 2. questions[i].length == 2
    /// 3. 1 <= pointsi, brainpoweri <= 10^5
    /// </summary>
    long long mostPoints(vector<vector<int>>& questions);

    /// <summary>
    /// Leet Code 2143. Choose Numbers From Two Arrays in Range
    ///                                                                 
    /// Hard
    ///
    /// You are given two 0-indexed integer arrays nums1 and nums2 of length n.
    ///
    /// A range [l, r] (inclusive) where 0 <= l <= r < n is balanced if:
    ///
    /// For every i in the range [l, r], you pick either nums1[i] or nums2[i].
    /// The sum of the numbers you pick from nums1 equals to the sum of the 
    /// numbers you pick from nums2 (the sum is considered to be 0 if you pick 
    /// no numbers from an array).
    /// Two balanced ranges from [l1, r1] and [l2, r2] are considered to be 
    /// different if at least one of the following is true:
    ///
    /// l1 != l2
    /// r1 != r2
    /// nums1[i] is picked in the first range, and nums2[i] is picked in the 
    /// second range or vice versa for at least one i.
    /// Return the number of different ranges that are balanced. Since the 
    /// answer may be very large, return it modulo 109 + 7.
    /// 
    /// Example 1:
    ///
    /// Input: nums1 = [1,2,5], nums2 = [2,6,3]
    /// Output: 3
    /// Explanation: The balanced ranges are:
    /// - [0, 1] where we choose nums2[0], and nums1[1].
    /// The sum of the numbers chosen from nums1 equals the sum of the 
    /// numbers chosen from nums2: 2 = 2.
    /// - [0, 2] where we choose nums1[0], nums2[1], and nums1[2].
    /// The sum of the numbers chosen from nums1 equals the sum of the numbers 
    /// chosen from nums2: 1 + 5 = 6.
    /// - [0, 2] where we choose nums1[0], nums1[1], and nums2[2].
    /// The sum of the numbers chosen from nums1 equals the sum of the numbers 
    /// chosen from nums2: 1 + 2 = 3.
    /// Note that the second and third balanced ranges are different.
    /// In the second balanced range, we choose nums2[1] and in the third 
    /// balanced range, we choose nums1[1].
    ///
    /// Example 2:
    /// Input: nums1 = [0,1], nums2 = [1,0]
    /// Output: 4
    /// Explanation: The balanced ranges are:
    /// - [0, 0] where we choose nums1[0].
    /// The sum of the numbers chosen from nums1 equals the sum of the numbers 
    /// chosen from nums2: 0 = 0.
    /// - [1, 1] where we choose nums2[1].
    /// The sum of the numbers chosen from nums1 equals the sum of the numbers
    /// chosen from nums2: 0 = 0.
    /// - [0, 1] where we choose nums1[0] and nums2[1].
    /// The sum of the numbers chosen from nums1 equals the sum of the numbers 
    /// chosen from nums2: 0 = 0.
    /// - [0, 1] where we choose nums2[0] and nums1[1].
    /// The sum of the numbers chosen from nums1 equals the sum of the numbers 
    /// chosen from nums2: 1 = 1.
    ///
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 1 <= n <= 100
    /// 3. 0 <= nums1[i], nums2[i] <= 100
    /// </summary>
    int countSubranges(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2167. Minimum Time to Remove All Cars Containing Illegal 
    ///                 Goods
    ///                                                                 
    /// Hard
    ///
    /// You are given a 0-indexed binary string s which represents a sequence 
    /// of train cars. s[i] = '0' denotes that the ith car does not contain 
    /// illegal goods and s[i] = '1' denotes that the ith car does contain 
    /// illegal goods.
    ///
    /// As the train conductor, you would like to get rid of all the cars 
    /// containing illegal goods. You can do any of the following three 
    /// operations any number of times:
    /// 
    /// Remove a train car from the left end (i.e., remove s[0]) which takes 
    /// 1 unit of time.
    /// Remove a train car from the right end (i.e., remove s[s.length - 1]) 
    /// which takes 1 unit of time.
    /// Remove a train car from anywhere in the sequence which takes 2 
    /// units of time.
    /// Return the minimum time to remove all the cars containing illegal 
    /// goods.
    ///
    /// Note that an empty sequence of cars is considered to have no cars 
    /// containing illegal goods.
    /// 
    /// Example 1:
    /// 
    /// Input: s = "1100101"
    /// Output: 5
    /// Explanation: 
    /// One way to remove all the cars containing illegal goods from the 
    /// sequence is to
    /// - remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
    /// - remove a car from the right end. Time taken is 1.
    /// - remove the car containing illegal goods found in the middle. Time 
    ///   taken is 2.
    /// This obtains a total time of 2 + 1 + 2 = 5. 
    ///
    /// An alternative way is to
    /// - remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
    /// - remove a car from the right end 3 times. Time taken is 3 * 1 = 3.
    /// This also obtains a total time of 2 + 3 = 5.
    /// 5 is the minimum time taken to remove all the cars containing 
    /// illegal goods. 
    /// There are no other ways to remove them with less time.
    ///
    /// Example 2:
    /// Input: s = "0010"
    /// Output: 2
    /// Explanation:
    /// One way to remove all the cars containing illegal goods from the 
    /// sequence is to
    /// - remove a car from the left end 3 times. Time taken is 3 * 1 = 3.
    /// This obtains a total time of 3.
    ///
    /// Another way to remove all the cars containing illegal goods from 
    /// the sequence is to
    /// - remove the car containing illegal goods found in the middle. 
    /// Time taken is 2.
    /// This obtains a total time of 2.
    ///
    /// Another way to remove all the cars containing illegal goods from 
    /// the sequence is to 
    /// - remove a car from the right end 2 times. Time taken is 2 * 1 = 2. 
    /// This obtains a total time of 2.
    ///
    /// 2 is the minimum time taken to remove all the cars containing 
    /// illegal goods. 
    /// There are no other ways to remove them with less time.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 2 * 10^5
    /// 2. s[i] is either '0' or '1'.
    /// </summary>
    int minimumTime(string s);

    /// <summary>
    /// Leet Code 2184. Number of Ways to Build Sturdy Brick Wall
    ///                                                                                   
    /// Medium
    /// You are given integers height and width which specify the dimensions 
    /// of a brick wall you are building. You are also given a 0-indexed 
    /// array of unique integers bricks, where the ith brick has a height 
    /// of 1 and a width of bricks[i]. You have an infinite supply of each 
    /// type of brick and bricks may not be rotated.
    /// 
    /// Each row in the wall must be exactly width units long. For the wall 
    /// to be sturdy, adjacent rows in the wall should not join bricks at the 
    /// same location, except at the ends of the wall.
    ///
    /// Return the number of ways to build a sturdy wall. Since the answer may 
    /// be very large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// 
    /// Input: height = 2, width = 3, bricks = [1,2]
    /// Output: 2
    /// Explanation:
    /// The first two walls in the diagram show the only two ways to build 
    /// a sturdy brick wall.
    /// Note that the third wall in the diagram is not sturdy because adjacent 
    /// rows join bricks 2 units from the left.
    /// Example 2:
    ///
    /// Input: height = 1, width = 1, bricks = [5]
    /// Output: 0
    /// Explanation:
    /// There are no ways to build a sturdy wall because the only type of 
    /// brick we have is longer than the width of the wall.
    /// 
    /// Constraints:
    /// 1. 1 <= height <= 100
    /// 2. 1 <= width <= 10
    /// 3. 1 <= bricks.length <= 10
    /// 4. 1 <= bricks[i] <= 10
    /// 5. All the values of bricks are unique.
    /// </summary>
    int buildWall(int height, int width, vector<int>& bricks);

    /// <summary>
    /// Leet Code 2188. Minimum Time to Finish the Race
    ///                                                                                   
    /// Hard
    ///
    /// You are given a 0-indexed 2D integer array tires where 
    /// tires[i] = [fi, ri] indicates that the ith tire can finish its xth 
    /// successive lap in fi * ri^(x-1) seconds.
    ///
    /// For example, if fi = 3 and ri = 2, then the tire would finish its 1st 
    /// lap in 3 seconds, its 2nd lap in 3 * 2 = 6 seconds, its 3rd lap 
    /// in 3 * 22 = 12 seconds, etc.
    /// You are also given an integer changeTime and an integer numLaps.
    ///
    /// The race consists of numLaps laps and you may start the race with any 
    /// tire. You have an unlimited supply of each tire and after every lap, 
    /// you may change to any given tire (including the current tire type) if 
    /// you wait changeTime seconds.
    ///
    /// Return the minimum time to finish the race.
    /// 
    /// Example 1:
    /// Input: tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
    /// Output: 21
    /// Explanation: 
    /// Lap 1: Start with tire 0 and finish the lap in 2 seconds.
    /// Lap 2: Continue with tire 0 and finish the lap in 2 * 3 = 6 seconds.
    /// Lap 3: Change tires to a new tire 0 for 5 seconds and then finish the 
    ///        lap in another 2 seconds.
    /// Lap 4: Continue with tire 0 and finish the lap in 2 * 3 = 6 seconds.
    /// Total time = 2 + 6 + 5 + 2 + 6 = 21 seconds.
    /// The minimum time to complete the race is 21 seconds.
    ///
    /// Example 2:
    /// Input: tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5
    /// Output: 25
    /// Explanation: 
    /// Lap 1: Start with tire 1 and finish the lap in 2 seconds.
    /// Lap 2: Continue with tire 1 and finish the lap in 2 * 2 = 4 seconds.
    /// Lap 3: Change tires to a new tire 1 for 6 seconds and then finish 
    ///        the lap in another 2 seconds.
    /// Lap 4: Continue with tire 1 and finish the lap in 2 * 2 = 4 seconds.
    /// Lap 5: Change tires to tire 0 for 6 seconds then finish the lap in 
    ///        another 1 second.
    /// Total time = 2 + 4 + 6 + 2 + 4 + 6 + 1 = 25 seconds.
    /// The minimum time to complete the race is 25 seconds. 
    ///
    /// Constraints:
    /// 1. 1 <= tires.length <= 10^5
    /// 2. tires[i].length == 2
    /// 3. 1 <= fi, changeTime <= 10^5
    /// 4. 2 <= ri <= 10^5
    /// 5. 1 <= numLaps <= 1000
    /// </summary>
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps);
};


#endif  // LeetCodeDP
