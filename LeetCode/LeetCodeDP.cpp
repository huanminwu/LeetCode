﻿#pragma once
#include <ctype.h>  /* is space */
#include <stdio.h>     /* printf */
#include <stdlib.h>  
#include <time.h>  
#include <functional>
#include <algorithm> 
#include <unordered_map> 
#include <unordered_set> 
#include <map> 
#include <numeric>
#include <stack>
#include <set>
#include <queue> 
#include <vector>
#include <iostream>
#include <fstream>
#include "Leetcode.h"
#include "LeetCodeDP.h"

#pragma region DynamicProgramming

/// <summary>
/// Leet Code 5. Longest Palindromic Substring
///  
/// Medium
///
/// Given a string s, return the longest palindromic substring in s.
/// 
/// Example 1:
/// Input: s = "babad"
/// Output: "bab"
/// Explanation: "aba" is also a valid answer.
///
/// Example 2:
/// Input: s = "cbbd"
/// Output: "bb"
///
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s consist of only digits and English letters.
/// </summary>
string LeetCodeDP::longestPalindrome(string s)
{
    string result;
    size_t n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (size_t j = 0; j < n; j++)
    {
        for (size_t  i = 0; i <= j; i++)
        {
            if (s[i] == s[j])
            {
                if ((j - i <= 2) || (dp[i + 1][j - 1] == 1))
                {
                    dp[i][j] = 1;
                    if ((j - i + 1) > result.size())
                    {
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
    }
    return result;
}


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
int LeetCodeDP::maxProfitOneTxn(vector<int>& prices)
{
    if (prices.size() == 0)
    {
        return 0;
    }
    int best_buy = INT_MAX;
    int best_profit = 0;
    for (size_t i = 0; i < prices.size(); i++)
    {
        best_buy = min(best_buy, prices[i]);
        best_profit = max(best_profit, prices[i] - best_buy);
    }
    return best_profit;
}

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
int LeetCodeDP::maxProfitManyTxns(vector<int>& prices)
{
    int prev_buy = INT_MIN;
    int prev_sell = 0;
    int result = 0;

    for (size_t i = 0; i < prices.size(); i++)
    {
        int buy = max(prev_sell - prices[i], prev_buy);
        int sell = max(prev_sell, prices[i] + prev_buy);
        result = max(result, sell);
        prev_buy = buy;
        prev_sell = sell;
    }
    return result;
}

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
int LeetCodeDP::maxProfitTwoTxns(vector<int>& prices)
{
    vector<int> prev_buy(2), prev_sell(2);
    vector<int> buy(2), sell(2);
    // This avoid us to special treat on first day buy
    prev_buy[0] = prev_buy[1] = INT_MIN;
    int result = 0;
    for (size_t i = 0; i < prices.size(); i++)
    {
        buy[0] = max(prev_buy[0], 0 - prices[i]);
        sell[0] = max(prev_sell[0], prev_buy[0] + prices[i]);
        buy[1] = max(prev_buy[1], prev_sell[0] - prices[i]);
        sell[1] = max(prev_sell[1], prev_buy[1] + prices[i]);
        result = max(result, max(sell[0], sell[1]));
        prev_buy = buy;
        prev_sell = sell;
    }
    return result;
}

/// <summary>
/// Leet code #188. Best Time to Buy and Sell Stock IV  
/// Say you have an array for which the ith element is the price of a given stock on day i.
/// Design an algorithm to find the maximum profit. You may complete at most k transactions.
/// Note:
/// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
/// </summary>
int LeetCodeDP::maxProfitKTxns(int k, vector<int>& prices)
{
    if (prices.size() == 0)
    {
        return 0;
    }
    if (k > (int)(prices.size() / 2))
    {
        return maxProfitManyTxns(prices);
    }
    vector<int> balance(prices.size(), 0);
    for (int s = 0; s < k; s++)
    {
        int best_buy = INT_MIN;
        int best_profit = 0;
        for (size_t i = 0; i < prices.size(); i++)
        {
            best_buy = max(best_buy, balance[i] - prices[i]);
            best_profit = max(best_profit, best_buy + prices[i]);
            balance[i] = best_profit;
        }
    }
    return balance[balance.size() - 1];
}

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
int LeetCodeDP::maxProfit(vector<int>& prices)
{
    int max_profit = 0;
    vector<int> buy(prices.size());
    vector<int> sell(prices.size());

    for (size_t i = 0; i < prices.size(); i++)
    {
        if (i == 0)
        {
            buy[i] = 0 - prices[i];
            sell[i] = 0;
        }
        else if (i == 1)
        {
            buy[i] = max(0 - prices[i], buy[i - 1]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        else
        {
            buy[i] = max(sell[i - 2] - prices[i], buy[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
        }
        max_profit = max(max_profit, sell[i]);
    }
    return max_profit;
}

/// <summary>
/// Leet code # 135. Candy
/// 
/// There are N children standing in a line. Each child is assigned a 
/// rating value.
/// You are giving candies to these children subjected to the 
/// following requirements: 
/// Each child must have at least one candy.
/// Children with a higher rating get more candies than their neighbors.
/// What is the minimum candies you must give?
/// </summary>
int LeetCodeDP::candy(vector<int>& ratings)
{
    vector<int> candy(ratings.size());
    // passing from left to right
    for (int i = 0; i < (int)ratings.size(); i++)
    {
        if (i == 0)
        {
            candy[i] = 1;
        }
        else if (ratings[i] > ratings[i - 1])
        {
            candy[i] = max(candy[i - 1] + 1, 1);
        }
        else
        {
            candy[i] = 1;
        }
    }
    // passing from right to left 
    for (int i = ratings.size() - 1; i >= 0; i--)
    {
        if (i == ratings.size() - 1)
        {
            candy[i] = max(candy[i], 1);
        }
        else if (ratings[i] > ratings[i + 1])
        {
            candy[i] = max(candy[i + 1] + 1, candy[i]);
        }
        else
        {
            candy[i] = max(candy[i], 1);
        }
    }
    int sumCandy = 0;
    for (size_t i = 0; i < candy.size(); i++)
    {
        sumCandy += candy[i];
    }
    return sumCandy;
}

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
bool LeetCodeDP::isMatchRegularExpression(string s, string p)
{
    vector<vector<bool>> matrix;
    matrix.push_back(vector<bool>(p.size() + 1));
    matrix[0][0] = true;
    for (size_t i = 0; i < p.size(); i++)
    {
        if ((p[i] == '*') && (i >= 1))
            matrix[0][i + 1] = matrix[0][i - 1];
        else
            matrix[0][i + 1] = false;
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        matrix.push_back(vector<bool>(p.size() + 1));
        matrix[i + 1][0] = false;
        for (size_t j = 0; j < p.size(); j++)
        {
            if ((s[i] == p[j]) || (p[j] == '.'))
            {
                matrix[i + 1][j + 1] = matrix[i][j];
            }
            else if ((p[j] == '*') && (j > 0))
            {
                // if character matches, and the pattern character is *, 
                // it can match under 3 conditions.
                // 1. if without *, it matches,
                // 2. if without * and the character before 
                //    (0 occurance for character), 
                // 3. match until the last character in source,
                //    This means multiple occurance.
                if (((s[i] == p[j - 1]) || (p[j - 1] == '.')))
                {
                    if (matrix[i + 1][j - 1] || matrix[i + 1][j] || matrix[i][j + 1])
                    {
                        matrix[i + 1][j + 1] = true;
                    }
                    else
                    {
                        matrix[i + 1][j + 1] = false;
                    }
                }
                else
                {
                    if (matrix[i + 1][j - 1])
                    {
                        matrix[i + 1][j + 1] = true;
                    }
                    else
                    {
                        matrix[i + 1][j + 1] = false;
                    }
                }
            }
            else
            {
                matrix[i + 1][j + 1] = false;
            }
        }
    }

    return matrix[s.size()][p.size()];
}

/// <summary>
/// Leet code #44. Wildcard Matching   
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
bool LeetCodeDP::isWildcardMatch(string s, string p)
{
    s = "x" + s;
    p = "x" + p;

    vector<vector<bool>> matrix(p.size(), vector<bool>(s.size()));
    for (size_t i = 0; i < p.size(); i++)
    {
        for (size_t j = 0; j < s.size(); j++)
        {
            if (i == 0)
            {
                if (j == 0) matrix[i][j] = true;
                else matrix[i][j] = false;
            }
            else if (j == 0)
            {
                if (p[i] == '*') matrix[i][j] = matrix[i - 1][j];
                else matrix[i][j] = false;
            }
            else if ((p[i] == s[j]) || (p[i] == '?'))
            {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else if (p[i] == '*')
            {
                matrix[i][j] = (matrix[i - 1][j - 1] || matrix[i][j - 1] || matrix[i - 1][j]);
            }
            else
            {
                matrix[i][j] = false;
            }
        }
    }
    return matrix[p.size() - 1][s.size() - 1];
}

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
bool LeetCodeDP::isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size()) return false;
    vector<set<pair<int, int>>> map(s3.size() + 1);
    map[0].insert(make_pair(0, 0));

    for (size_t i = 1; i <= s3.size(); i++)
    {
        set<pair<int, int>> list = map[i - 1];
        for (set<pair<int, int>>::iterator iterator = list.begin(); iterator != list.end(); ++iterator)
        {
            pair<int, int> pair = *iterator;
            if (s1[pair.first] == s3[i - 1])
            {
                map[i].insert(make_pair(pair.first + 1, pair.second));
            }
            if (s2[pair.second] == s3[i - 1])
            {
                map[i].insert(make_pair(pair.first, pair.second + 1));
            }
        }
        if (map[i].empty()) return false;
    }
    return true;
}

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
bool LeetCodeDP::canJump(vector<int>& nums)
{
    int right_most = 0;
    int index = 0;
    while (index < right_most + 1 && right_most < (int)nums.size() - 1)
    {
        right_most = max(right_most, index + nums[index]);
        index++;
    }
    if (right_most >= (int)nums.size() - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
int LeetCodeDP::jump(vector<int>& nums)
{
    int end = 0;
    int index = 0;
    int result = 0;
    while (end < (int)nums.size() - 1)
    {
        int right = end;
        result++;
        while (index <= right)
        {
            end = max(end, index + nums[index]);
            index++;
        }
    }
    return result;
}

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
/// 1. The number of stones is ≥ 2 and is < 1,100.
/// 2. Each stone's position will be a non-negative integer < 231.
/// 3. The first stone's position is always 0.
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
bool LeetCodeDP::canCross(vector<int>& stones)
{
    size_t size = stones.size();
    unordered_map<int, unordered_set<int>> dp;
    // initalize
    for (size_t i = 0; i < stones.size(); i++) dp[stones[i]];
    dp[0].insert(0);
    // iterate every stone
    for (size_t i = 0; i < stones.size(); i++)
    {
        for (auto s : dp[stones[i]])
        {
            for (int j = max(1, s - 1); j <= s + 1; j++)
            {
                int next = stones[i] + j;
                if (next == stones.back()) return true;
                if (dp.count(next) > 0)
                {
                    dp[next].insert(j);
                }
            }
        }
    }
    return false;
}

/// <summary>
/// Leet code #70. Climbing Stairs 
/// You are climbing a stair case. It takes n steps to reach to the top.
/// Each time you can either climb 1 or 2 steps. In how many distinct 
/// ways can you climb to the top? 
/// </summary>
int LeetCodeDP::climbStairs(int n)
{
    vector<int> steps;
    steps.push_back(1);
    steps.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        steps.push_back(steps[i - 2] + steps[i - 1]);
    }
    return steps[n];
}

/// <summary>
/// Leet code #72. Edit Distance 
/// Given two words word1 and word2, find the minimum number of steps 
/// required to convert word1 to word2. (each operation is 
/// counted as 1 step.) 
/// You have the following 3 operations permitted on a word: 
/// a) Insert a character
/// b) Delete a character
/// c) Replace a character
/// </summary> 
int LeetCodeDP::minDistance(string word1, string word2)
{
    int distance = 0;
    vector<vector<int>> distance_map;
    // The matrix should be [s.size() + 1][p.size() + 1] 
    // This is because the first row and first column
    // if left for empty string.
    for (size_t i = 0; i <= word1.size(); i++)
    {
        distance_map.push_back(vector<int>(word2.size() + 1));
    }
    for (size_t i = 0; i <= word1.size(); i++)
    {
        for (size_t j = 0; j <= word2.size(); j++)
        {
            // when word1 is empty string, the distance is to insert every 
            /// character in word2 
            if (i == 0)
            {
                distance_map[i][j] = j;
            }
            // when word2 is empty string, the distance is to delete every 
            // character of word1 
            else if (j == 0)
            {
                distance_map[i][j] = i;
            }
            else
            {
                // if the character match, we inherit the edit size from 
                // the subset
                if (word1[i - 1] == word2[j - 1])
                {
                    distance_map[i][j] = distance_map[i - 1][j - 1];
                }
                // otherwise, we increase the size by 1 from the subset,
                // by replacing a character
                else
                {
                    distance_map[i][j] = distance_map[i - 1][j - 1] + 1;
                }
                distance_map[i][j] = min(distance_map[i][j], distance_map[i - 1][j] + 1);
                distance_map[i][j] = min(distance_map[i][j], distance_map[i][j - 1] + 1);
            }
        }
    }
    return distance_map[word1.size()][word2.size()];
}

/// <summary>
/// Leet code #115. Distinct Subsequences  
/// Given a string S and a string T, count the number of distinct subsequences
/// of T in S.
/// A subsequence of a string is a new string which is formed from the original
/// string by deleting some (can be none) of the characters without disturbing 
/// the relative positions of the remaining characters. (ie, "ACE" is a 
/// subsequence of "ABCDE" while "AEC" is not). For example,
///   Here is an example:
///   S = "rabbbit", T = "rabbit" 
/// </summary>
int LeetCodeDP::numDistinct(string s, string t)
{
    if (s.empty() || t.empty()) return 0;
    vector<vector<unsigned int>> dp(t.size(), vector<unsigned int>(s.size()));
    for (size_t i = 0; i < t.size(); i++)
    {
        for (size_t j = 0; j < s.size(); j++)
        {
             if (t[i] == s[j])
             {
                 if (i == 0 && j == 0) dp[i][j] = 1;
                 else if (i == 0) dp[i][j] = (1 + dp[i][j - 1]);
                 else if (j == 0) dp[i][j] = 0;
                 else
                 {
            
                     dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]);
                 }
             }
             else
             {
                  if (j > 0) dp[i][j] = dp[i][j - 1];
             }
        }
    }
    return dp[t.size() - 1][s.size() - 1];
}

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
int LeetCodeDP::uniquePaths(int m, int n)
{
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0) && (j == 0))
            {
                matrix[i][j] = 1;
            }
            else if (i == 0)
            {
                matrix[i][j] = matrix[i][j - 1];
            }
            else if (j == 0)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
            }
        }
    }
    return matrix[m - 1][n - 1];
}

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
int LeetCodeDP::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                matrix[i][j] = 0;
            }
            else if ((i == 0) && (j == 0))
            {
                matrix[i][j] = 1;
            }
            else if (i == 0)
            {
                matrix[i][j] = matrix[i][j - 1];
            }
            else if (j == 0)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
            }
        }
    }
    return matrix[m - 1][n - 1];
}

/// <summary>
/// Leet code #64. Minimum Path Sum
///
/// Given a m x n grid filled with non-negative numbers, find a path from 
/// top left to bottom right 
/// which minimizes the sum of all numbers along its path.
///	Note: You can only move either down or right at any point in time. 
/// </summary>
int LeetCodeDP::minPathSum(vector<vector<int>>& grid)
{
    vector<vector<int>> matrix(grid.size(), vector<int>(grid[0].size()));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            if ((i == 0) && (j == 0))
            {
                matrix[i][j] = grid[i][j];
            }
            else if (i == 0)
            {
                matrix[i][j] = matrix[i][j - 1] + grid[i][j];
            }
            else if (j == 0)
            {
                matrix[i][j] = matrix[i - 1][j] + grid[i][j];
            }
            else
            {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]) + grid[i][j];
            }
        }
    }
    return matrix[grid.size() - 1][grid[0].size() - 1];
}

/// <summary>
/// Leet code #198. House Robber
/// You are a professional robber planning to rob houses along a street. Each 
/// house has a certain amount of money stashed, the only constraint stopping 
/// you from robbing each of them is that adjacent houses have security system 
/// connected and it will automatically contact the police if two adjacent 
/// houses were broken into on the same night.
/// Given a list of non-negative integers representing the amount of money of 
/// each house, determine the maximum amount of money you can rob tonight 
/// without alerting the police.
/// </summary>
int LeetCodeDP::rob(vector<int>& nums)
{
    if (nums.size() == 0) return 0;
    vector<int> matrix(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        // You start with first house
        if (i == 0)
        {
            matrix[i] = nums[i];
        }
        // when at the second house, you simply compare the value of these two houses
        else if (i == 1)
        {
            matrix[i] = max(nums[i - 1], nums[i]);
        }
        // when you have more than two houses, you need to think whether 
        // you should steal the current house or the previous house  
        else
        {
            matrix[i] = max(matrix[i - 2] + nums[i], matrix[i - 1]);
        }
    }
    return matrix[nums.size() - 1];
}

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
int LeetCodeDP::robII(vector<int>& nums)
{
    // special case
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    int last_prev = 0;
    int sum = 0;
    int result = 0;
    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        int prev = sum;
        sum = max(last_prev + nums[i], sum);
        last_prev = prev;
    }
    result = sum;

    last_prev = 0;
    sum = 0;
    for (size_t i = 1; i < nums.size(); i++)
    {
        int prev = sum;
        sum = max(last_prev + nums[i], sum);
        last_prev = prev;
    }
    result = max(result, sum);
    
    return result;
}

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
int LeetCodeDP::numDecodings(string s)
{
    if (s.empty()) return 0;
    vector<int> dp(s.size()+1);
    dp[0] = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != '0') dp[i+1] += dp[i];
        if (i < s.size() - 1)
        {
            if ((s[i] == '1') || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
            {
                dp[i + 2] += dp[i];
            }
        }
    }
    return dp[s.size()];
}

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
int LeetCodeDP::nthUglyNumber(int n)
{
    vector<int> result;
    vector<int> dp(3);
    vector<int> factor = { 2, 3, 5 };
    result.push_back(1);
    while (result.size() < (size_t)n)
    {
        int index = 0;
        int min_num = INT_MAX;
        for (size_t i = 0; i < dp.size(); i++)
        {
            if (min_num > result[dp[i]] * factor[i])
            {
                index = i;
                min_num = result[dp[i]] * factor[i];
            }
        }
        if (min_num > result.back()) result.push_back(min_num);
        dp[index]++;
    }
    return result.back();
}

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
int LeetCodeDP::numTrees(int n)
{
    vector<int> nums(n + 1);

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            nums[i] = 1;
        }
        else if (i == 1)
        {
            nums[i] = 1;
        }
        else
        {
            for (int j = 1; j <= i; j++)
            {
                nums[i] += nums[j - 1] * nums[i - j];
            }
        }
    }
    nums[0] = 0;
    return nums[n];
}

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
/// 3. 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
/// 4. The nth super ugly number is guaranteed to fit in a 32-bit signed 
///    integer.
/// </summary>
int LeetCodeDP::nthSuperUglyNumber(int n, vector<int>& primes)
{
    vector<int> result;
    vector<int> dp(primes.size());
    result.push_back(1);
    while (result.size() < (size_t)n)
    {
        int index = 0;
        int min_num = INT_MAX;
        for (size_t i = 0; i < dp.size(); i++)
        {
            int product = result[dp[i]] * primes[i];
            if (min_num > product)
            {
                index = i;
                min_num = product;
            }
        }
        if (min_num > result.back()) result.push_back(min_num);
        dp[index]++;
    }
    return result.back();
}

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
int LeetCodeDP::minimumTotal(vector<vector<int>>& triangle)
{
    vector<int> sum(triangle.size());
    if ((triangle.empty()) || (triangle[0].empty())) return 0;
    for (size_t i = 0; i < triangle.size(); i++)
    {
        int prev = sum[0];
        for (size_t j = 0; j < triangle[i].size(); j++)
        {
            int current = sum[j];
            if (i == 0)
            {
                sum[j] = triangle[i][j];
            }
            else if (j == 0)
            {
                sum[j] = sum[j] + triangle[i][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                sum[j] = prev + triangle[i][j];
            }
            else
            {
                sum[j] = min(prev, sum[j]) + triangle[i][j];
            }
            prev = current;
        }
    }
    int minimum_sum = sum[0];
    for (size_t i = 1; i < sum.size(); i++)
    {
        if (minimum_sum > sum[i])  minimum_sum = sum[i];
    }
    return minimum_sum;
}

/// <summary>
/// Leet code #279. Perfect Squares 
/// Given a positive integer n, find the least number of perfect square numbers 
/// (for example, 1, 4, 9, 16, ...) which sum to n.
/// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; 
/// given n = 13, return 2 because 13 = 4 + 9. 
/// </summary>
int LeetCodeDP::numSquares(int n)
{
    vector<int> square_count(n + 1, 0);
    vector<int> square;
    for (size_t i = 0; i <= (size_t)n; i++)
    {
        int r = square.size() * square.size();
        if (r == i)
        {
            square_count[i] = 1;
            square.push_back(r);
        }
        else
        {
            for (size_t j = 1; j < square.size(); j++)
            {
                if (j == 1)
                {
                    square_count[i] = square_count[i - square[j]] + 1;
                }
                else
                {
                    square_count[i] = min(square_count[i], square_count[i - square[j]] + 1);
                }
            }
        }
    }
    return square_count[n];
}

/// <summary>
/// Leet Code 377. Combination Sum IV
///                 
/// Medium
///
/// Given an array of distinct integers nums and a target integer target, 
/// return the number of possible combinations that add up to target.
///
/// The test cases are generated so that the answer can fit in a 32-bit 
/// integer.
/// 
/// Example 1:
/// Input: nums = [1,2,3], target = 4
/// Output: 7
/// Explanation:
/// The possible combination ways are:
/// (1, 1, 1, 1)
/// (1, 1, 2)
/// (1, 2, 1)
/// (1, 3)
/// (2, 1, 1)
/// (2, 2)
/// (3, 1)
/// Note that different sequences are counted as different combinations.
///
/// Example 2:
/// Input: nums = [9], target = 3
/// Output: 0
///
/// Constraints:
/// 1. 1 <= nums.length <= 200
/// 2. 1 <= nums[i] <= 1000
/// 3. All the elements of nums are unique.
/// 4. 1 <= target <= 1000
/// 
/// Follow up: What if negative numbers are allowed in the given array? 
/// How does it change the problem? What limitation we need to add to 
/// the question to allow negative numbers?
/// </summary>
int LeetCodeDP::combinationSum4(vector<int>& nums, int target)
{
    vector<size_t> sum(target + 1);
    sum[0] = 1;
    for (int i = 0; i <= target; i++)
    {
        // empty slot no need to calculate
        if (sum[i] == 0) continue;
        for (size_t j = 0; j < nums.size(); j++)
        {
            // protect not out of boundary
            if (i + nums[j] <= target)
            {
                sum[i + nums[j]] += sum[i];
            }
        }
    }
    return sum[target];
}

/// <summary>
/// Leet code #474. Ones and Zeroes
///
/// In the computer world, use restricted resource you have to generate 
/// maximum benefit is what we always want to pursue.
/// For now, suppose you are a dominator of m 0s and n 1s respectively. 
/// On the other hand, 
/// there is an array with strings consisting of only 0s and 1s.
/// Now your task is to find the maximum number of strings that you can 
/// form with given m 0s and n 1s. 
/// Each 0 and 1 can be used at most once. 
/// Note:
/// The given numbers of 0s and 1s will both not exceed 100
/// The size of given string array won't exceed 600.
/// Example 1:
/// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
/// Output: 4
///
/// Explanation: This are totally 4 strings can be formed by the using of 5 0s 
/// and 3 1s, which are “10,”0001”,”1”,”0”
///
/// Example 2:
/// Input: Array = {"10", "0", "1"}, m = 1, n = 1
/// Output: 2
///
/// Explanation: You could form "10", but then you'd have nothing left. 
/// Better form "0" and "1".
/// </summary>
int LeetCodeDP::findMaxOneZeroForm(vector<string>& strs, int m, int n)
{
    // we end by m, n, and 0, 0 is a virtual start 
    int result = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (size_t i = 0; i < strs.size(); i++)
    {
        string str = strs[i];
        int zero = std::count(str.begin(), str.end(), '0');
        int one = std::count(str.begin(), str.end(), '1');
        // scan from end to start so we do not duplicate new item itself
        for (int j = m; j >= zero; j--)
        {
            for (int k = n; k >= one; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                result = max(result, dp[j][k]);
            }
        }
    }
    return result;
}

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
int LeetCodeDP::numWaysPaintFence(int n, int k)
{
    int diff = 0, same = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            diff = 0;
            same = k;
        }
        else if (i == 2)
        {
            diff = k * (k - 1);
            same = k;
        }
        else
        {
            int temp = diff;
            diff = same * (k - 1) + diff * (k - 1);
            same = temp;
        }
    }
    return same + diff;
}


/// <summary>
/// Leet code 256. Paint House 
///
/// There are a row of n houses, each house can be painted with one of 
/// the three colors: red, blue or green. The cost of painting each 
/// house with a certain color is different. You have to paint all 
/// the houses such that no two adjacent houses have the same color.
///
/// The cost of painting each house with a certain color is 
/// represented by a n x 3 cost matrix. For example, costs[0][0] is 
/// the cost of painting house 0 with color red; costs[1][2] is the 
/// cost of painting house 1 with color green, and so on... Find the 
/// minimum cost to paint all houses.
///
/// Note:
/// All costs are positive integers.
///
/// Example:
/// Input: [[17,2,17],[16,16,5],[14,3,19]]
/// Output: 10
/// Explanation: Paint house 0 into blue, paint house 1 into green, paint 
/// house 2 into blue. 
/// Minimum cost: 2 + 5 + 3 = 10.
/// </summary>
int LeetCodeDP::minCost(vector<vector<int>>& costs)
{
    vector<vector<int>> sum;
    if (costs.size() == 0) return 0;
    for (size_t i = 0; i < costs.size(); i++)
    {
        sum.push_back(vector<int>(3));
        if (i == 0)
        {
            sum[i][0] = costs[i][0];
            sum[i][1] = costs[i][1];
            sum[i][2] = costs[i][2];
        }
        else
        {
            sum[i][0] = costs[i][0] + min(sum[i - 1][1], sum[i - 1][2]);
            sum[i][1] = costs[i][1] + min(sum[i - 1][0], sum[i - 1][2]);
            sum[i][2] = costs[i][2] + min(sum[i - 1][0], sum[i - 1][1]);
        }
    }
    return min(min(sum[costs.size() - 1][0], sum[costs.size() - 1][1]), sum[costs.size() - 1][2]);
}

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
int LeetCodeDP::minCostII(vector<vector<int>>& costs)
{
    int result = 0;
    if (costs.empty() || costs[0].empty()) return result;
    int n = costs.size();
    int m = costs[0].size();
    vector<pair<int, int>> prev_cost = { { INT_MAX, -1 }, { INT_MAX, -1 } };

    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int>> curr_cost = { { INT_MAX, -1 }, { INT_MAX, -1 } };
        for (int j = 0; j < m; j++)
        {
            pair<int, int> cost = make_pair(costs[i][j], j);
            if (i > 0)
            {
                for (int k = 0; k < 2; k++)
                {
                    if (cost.second != prev_cost[k].second)
                    {
                        cost.first += prev_cost[k].first;
                        break;
                    }
                }
            }
            for (int k = 0; k < 2; k++)
            {
                if (cost.first < curr_cost[k].first)
                {
                    swap(cost, curr_cost[k]);
                }
            }
        }
        prev_cost = curr_cost;
    }
    return prev_cost[0].first;
}

/// <summary>
/// Leet code #161. One Edit Distance 
/// 
/// Given two strings S and T, determine if they are both one edit distance apart. 
/// </summary>
bool LeetCodeDP::isOneEditDistance(string s, string t, size_t i, size_t j, size_t count)
{
    while (i < s.size() && j < t.size() && s[i] == t[j])
    {
        i++; j++;
    }
    if (i == s.size())
    {
        return (count + t.size() - j == 1);
    }
    else if (j == t.size())
    {
        return (count + s.size() - i == 1);
    }
    if (count > 1) return false;

    count++;
    if (isOneEditDistance(s, t, i + 1, j, count) ||
        isOneEditDistance(s, t, i, j + 1, count) ||
        isOneEditDistance(s, t, i + 1, j + 1, count))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #161. One Edit Distance 
/// 
/// Given two strings S and T, determine if they are both one edit distance apart. 
/// </summary>
bool LeetCodeDP::isOneEditDistance(string s, string t)
{
    return isOneEditDistance(s, t, 0, 0, 0);
}

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
int LeetCodeDP::maxKilledEnemies(vector<vector<char>>& grid)
{
    if (grid.size() == 0 || grid[0].size() == 0) return 0;
    int max_enemies = 0;
    pair<int, int> max_pos;
    vector<vector<pair<int, int>>> sum(grid.size(), vector<pair<int, int>>(grid[0].size()));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            pair<int, int> count;
            if (grid[i][j] == 'W')
            {
                count = make_pair(0, 0);
            }
            else if (grid[i][j] == '0')
            {
                if (i == 0) count.first = 0;
                else count.first = sum[i - 1][j].first;
                if (j == 0) count.second = 0;
                else count.second = sum[i][j - 1].second;
            }
            else if (grid[i][j] == 'E')
            {
                if (i == 0) count.first = 1;
                else count.first = sum[i - 1][j].first + 1;
                if (j == 0) count.second = 1;
                else count.second = sum[i][j - 1].second + 1;
            }
            sum[i][j] = count;
        }
    }
    for (int i = grid.size() - 1; i >= 0; i--)
    {
        for (int j = grid[i].size() - 1; j >= 0; j--)
        {
            if (grid[i][j] == 'W') continue;
            if (i < (int)grid.size() - 1)
            {
                sum[i][j].first = max(sum[i + 1][j].first, sum[i][j].first);
            }
            if (j < (int)grid[i].size() - 1)
            {
                sum[i][j].second = max(sum[i][j + 1].second, sum[i][j].second);
            }
            if (grid[i][j] == '0')
            {
                int enemies = sum[i][j].first + sum[i][j].second;
                if (enemies > max_enemies)
                {
                    max_enemies = enemies;
                    max_pos = make_pair(i, j);
                }
            }
        }
    }
    return max_enemies;
}

/// <summary>
/// Leet code #484. Find Permutation         
/// 
/// By now, you are given a secret signature consisting of character 'D' and 'I'. 
/// 'D' represents a decreasing relationship between two numbers, 'I' represents 
/// an increasing relationship between two numbers. And our secret signature was 
/// constructed by a special integer array, which contains uniquely all the 
/// different number from 1 to n (n is the length of the secret signature plus 1). 
/// For example, the secret signature "DI" can be constructed by array [2,1,3] or 
/// [3,1,2], but won't be constructed by array [3,2,4] or [2,1,3,4], which are both 
/// illegal constructing special string that can't represent the "DI" 
/// secret signature. 
/// On the other hand, now your job is to find the lexicographically smallest 
/// permutation of [1, 2, ... n] could refer to the given secret signature in the input. 
///
/// Example 1:
/// Input: "I"
/// Output: [1,2]
/// Explanation: [1,2] is the only legal initial spectial string can construct secret 
/// signature "I", where the number 1 and 2 construct an increasing relationship.
///
/// Example 2:
///
/// Input: "DI"
/// Output: [2,1,3]
/// Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature "DI", 
/// but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]
/// Note: 
/// The input string will only contain the character 'D' and 'I'.
/// The length of input string is a positive integer and will not exceed 10,000
/// </summary>
vector<int> LeetCodeDP::findPermutation(string s)
{
    int index = 0;
    int count = 0;
    vector<int> nums(s.size() + 1);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'D')
        {
            nums[i] = nums[i + 1] + 1;
        }
        else
        {
            nums[i] = 0;
        }
    }
    set<int> num_set;
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_set.insert(i + 1);
    }
    vector<int> result;
    for (size_t i = 0; i < nums.size(); i++)
    {
        set<int>::iterator itr = num_set.begin();
        for (int j = 0; j < nums[i]; j++)
        {
            itr++;
        }
        result.push_back(*itr);
        num_set.erase(itr);
    }
    return result;
}

/// <summary>
/// Leet code #375. Guess Number Higher or Lower II 
/// 
/// We are playing the Guess Game. The game is as follows:
/// I pick a number from 1 to n. You have to guess which number I picked. 
/// Every time you guess wrong, I'll tell you whether the number I picked 
/// is higher or lower. 
/// However, when you guess a particular number x, and you guess wrong, 
/// you pay $x. 
/// You win the game when you guess the number I picked.
/// Example: 
/// n = 10, I pick 8.
/// First round:  You guess 5, I tell you that it's higher. You pay $5.
/// Second round: You guess 7, I tell you that it's higher. You pay $7.
/// Third round:  You guess 9, I tell you that it's lower. You pay $9.
/// Game over. 8 is the number I picked.
/// You end up paying $5 + $7 + $9 = $21.
/// Given a particular n ≥ 1, find out how much money you need to have to 
/// guarantee a win.
/// </summary>
int LeetCodeDP::getMoneyAmount(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int step = 0; step < n; step++)
    {
        for (int i = 0; i < n; i++)
        {
            if (step == 0)
            {
                matrix[i][i + step] = 0;
            }
            else if ((step == 1) && (i + step < n))
            {
                matrix[i][i + step] = i + 1;
            }
            else if (i + step < n)
            {
                int min_value = INT_MAX;
                for (int k = i + 1; k < i + step; k++)
                {
                    int left = matrix[i][k - 1];
                    int right = matrix[k + 1][i + step];
                    int value = max(left, right) + k + 1;
                    min_value = min(min_value, value);
                }
                matrix[i][i + step] = min_value;
            }
            else
            {
                break;
            }
        }
    }
    return matrix[0][n - 1];
}

/// <summary>
/// Leet code #516. Longest Palindromic Subsequence         
/// 
/// Given a string s, find the longest palindromic subsequence's length in s. You may 
/// assume that the maximum length of s is 1000. 
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
int LeetCodeDP::longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int step = 0; step < n; step++)
    {
        for (int i = 0; i < n; i++)
        {
            if (step == 0)
            {
                matrix[i][i + step] = 1;
            }
            else if ((step == 1) && (i + step < n))
            {
                matrix[i][i + step] = (s[i] == s[i + step]) ? 2 : 1;
            }
            else if (i + step < n)
            {
                int max_value = INT_MIN;
                if (s[i] == s[i + step])
                {
                    max_value = max(max_value, 2 + matrix[i + 1][i + step - 1]);
                }
                max_value = max(max_value, matrix[i + 1][i + step]);
                max_value = max(max_value, matrix[i][i + step - 1]);
                matrix[i][i + step] = max_value;
            }
            else
            {
                break;
            }
        }
    }
    return matrix[0][n - 1];
}

/// <summary>
/// Leet code #312. Burst Balloons 
///
/// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a 
/// number on it represented by array nums. 
/// You are asked to burst all the balloons. If the you burst balloon i you 
/// will get nums[left] * nums[i] * nums[right] coins. 
/// Here left and right are adjacent indices of i. After the burst, the left 
/// and right then becomes adjacent.
/// Find the maximum coins you can collect by bursting the balloons wisely. 
/// Note: 
/// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore 
/// you can not burst them.
/// (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100 
/// Example: 
/// Given [3, 1, 5, 8] 
/// Return 167 
/// nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
/// coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167	
/// </summary>   
int LeetCodeDP::maxBurstBalloonCoins(vector<int>& nums)
{
    vector<int> balloons;
    balloons.push_back(1);
    for (size_t i = 0; i < nums.size(); i++)
    {
        balloons.push_back(nums[i]);
    }
    balloons.push_back(1);
    vector<vector<int>> coins(balloons.size(), vector<int>(balloons.size(), 0));

    for (size_t gap = 2; gap < balloons.size(); gap++)
    {
        for (size_t i = 0; i < balloons.size() - gap; i++)
        {
            size_t first = i;
            size_t last = i + gap;
            if (gap == 2)
            {
                coins[first][last] = balloons[first] * balloons[first + 1] * balloons[last];
            }
            else
            {
                int max_coins = 0;
                for (size_t j = first + 1; j < last; j++)
                {
                    int sum_coins =
                        coins[first][j] + coins[j][last] +
                        balloons[first] * balloons[j] * balloons[last];
                    max_coins = max(max_coins, sum_coins);
                }
                coins[first][last] = max_coins;
            }
        }
    }
    return coins[0][balloons.size() - 1];
}

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
bool LeetCodeDP::predictTheWinner(vector<int>& nums)
{
    if (nums.empty()) return true;
    vector<vector<pair<int, int>>> sum(nums.size(), vector<pair<int, int>>(nums.size()));
    for (size_t step = 0; step < nums.size(); step++)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            int first; // winner stone
            int second;  // loser stone
            if (step == 0)
            {
                first = nums[i];
                second = 0;
                sum[i][i + step] = make_pair(first, second);
            }
            else if (i + step < nums.size())
            {
                first = max(nums[i] + sum[i + 1][i + step].second, nums[i + step] + sum[i][i + step - 1].second);
                second = nums[i] + sum[i + 1][i + step].first + sum[i + 1][i + step].second - first;
                sum[i][i + step] = make_pair(first, second);
            }
        }
    }
    return (sum[0][nums.size() - 1].first >= sum[0][nums.size() - 1].second);
}

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
int LeetCodeDP::findRotateSteps(string ring, string key)
{
    vector<pair<int, int>> last_pos_list = { { 0, 0 } };
    unordered_map<char, vector<pair<int, int>>> char_map;
    for (size_t i = 0; i < ring.size(); i++)
    {
        char_map[ring[i]].push_back(make_pair(i, 0));
    }

    for (size_t i = 0; i < key.size(); i++)
    {
        for (size_t j = 0; j < char_map[key[i]].size(); j++)
        {
            int min_step = INT_MAX;
            int curr_pos = char_map[key[i]][j].first;
            for (pair<int, int> last_pos : last_pos_list)
            {
                min_step = min(min_step, 
                               last_pos.second + 
                               abs(curr_pos - last_pos.first));
                min_step = min(min_step, last_pos.second + (int)ring.size() - 
                                         abs(curr_pos - last_pos.first));
            }
            char_map[key[i]][j].second = min_step + 1;
        }
        last_pos_list = char_map[key[i]];
    }
    int result = INT_MAX;
    for (size_t i = 0; i < last_pos_list.size(); i++)
    {
        result = min(result, last_pos_list[i].second);
    }
    return result;
}

/// <summary>
/// Leet code #552. Student Attendance Record II
/// 
/// Given a positive integer n, return the number of all possible 
/// attendance records with length n, which will be regarded as 
/// rewardable. The answer may be very large, return it after 
/// mod 10^9 + 7.
/// A student attendance record is a string that only contains the 
/// following three characters:
///
/// 'A' : Absent. 
/// 'L' : Late.
/// 'P' : Present. 
/// A record is regarded as rewardable if it doesn't contain more 
/// than one 'A' (absent) or more than two continuous 'L' (late).
/// Example 1:
/// Input: n = 2
/// Output: 8 
/// Explanation:
/// There are 8 records with length 2 will be regarded as rewardable:
/// "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
/// Only "AA" won't be regarded as rewardable owing to more than one 
/// absent times. 
/// Note: The value of n won't exceed 100,000. 
/// </summary>
int LeetCodeDP::checkRecord(int n)
{
    unsigned long long M = 1000000007;

    vector<unsigned long long> P(n), L(n), A(n);
    // process for record 'P' and 'L', consider at position 
    // i we have 'P' or 'L', totally how many record we 
    // can get
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            P[i] = 1; L[i] = 1;
        }
        else
        {
            // for 'P' at i position, simply add count for 'P' and 'L'
            // at position of i - 1
            P[i] = P[i - 1] + L[i - 1];

            // for 'P' at i position, s add count for 'P' and 'L'
            // at position of i - 1, but should deduct 'LL'
            L[i] = P[i - 1] + L[i - 1];
            // count double LL in the lower significance and deduct it
            if (i == 2)  L[i] -= 1;
            else if (i > 2)
            {
                if (L[i] >= P[i - 3]) L[i] -= P[i - 3];
                else L[i] += M - P[i - 3];
            }
        }
        P[i] %= M;
        L[i] %= M;
    }
    // Now process for 'A' at i position    
    for (int i = 0; i < n; i++)
    {
        if (i == 0)  A[i] = 1;
        // for 'A' at i position, simply add count for 'P' and 'L'
        // at position of i - 1
        else A[i] = P[i - 1] + L[i - 1];
        A[i] %= M;
    }


    // Now add record 'A' and recalculate
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            P[i] = 1; L[i] = 1;
        }
        else
        {
            // for 'P' at i position, add count for 'P', 'L', 'A'
            // at position of i - 1
            P[i] = P[i - 1] + L[i - 1] + A[i - 1];

            // for 'P' at i position, s add count for 'P' and 'L'
            // at position of i - 1, but should deduct 'LL'
            L[i] = P[i - 1] + L[i - 1] + A[i - 1];
            // count double LL in the lower significance and deduct it
            if (i == 2)  L[i] -= 1;
            else if (i > 2)
            {
                if (L[i] >= P[i - 3] + A[i - 3])
                {
                    L[i] -= (P[i - 3] + A[i - 3]);
                }
                else
                {
                    L[i] += M - (P[i - 3] + A[i - 3]);
                }
            }
        }
        P[i] %= M;
        L[i] %= M;
    }

    return (int)((P[n - 1] + L[n - 1] + A[n - 1]) % M);
}

/// <summary>
/// Leet code #583. Delete Operation for Two Strings
/// 
/// Given two words word1 and word2, find the minimum number of steps required 
/// to make word1 and word2 the same, where in each step you can delete one 
/// character in either string. 
/// Example 1:
/// Input: "sea", "eat"
/// Output: 2
/// Explanation: You need one step to make "sea" to "ea" and another step to 
/// make "eat" to "ea".
/// Note:
/// 1. The length of given words won't exceed 500.
/// 2. Characters in given words can only be lower-case letters.
/// </summary>
int LeetCodeDP::minDeleteDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
    for (size_t i = 0; i < word1.size() + 1; i++)
    {
        for (size_t j = 0; j < word2.size() + 1; j++)
        {
            if (i == 0)
            {
                if (j == 0) dp[i][j] = 0;
                else dp[i][j] = dp[i][j - 1] + 1;
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + 2;
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }
    return dp[word1.size()][word2.size()];
}

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
int LeetCodeDP::findPaths(int m, int n, int N, int i, int j)
{
    vector<vector<int>> dp(m, vector<int>(n));
    dp[i][j] = 1;
    int result = 0;
    int M = 1000000007;
    
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int k = 0; k < N; k++)
    {
        vector<vector<int>> next_dp(m, vector<int>(n));
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (dp[r][c] == 0) continue;
                for (size_t d = 0; d < directions.size(); d++)
                {
                    int next_r = r + directions[d][0];
                    int next_c = c + directions[d][1];
                    if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n)
                    {
                        result = (result + dp[r][c]) % M;
                    }
                    else
                    {
                        next_dp[next_r][next_c] = (next_dp[next_r][next_c] + dp[r][c]) % M;
                    }
                }
            }
        }
        dp = next_dp;
    }
    return result;
}

/// <summary>
/// Leet code #600. Non-negative Integers without Consecutive Ones
/// 
/// Given a positive integer n, find the number of non-negative integers 
/// less than or equal to n, whose binary representations do NOT contain 
/// consecutive ones.
/// Example 1:
/// Input: 5
/// Output: 5
/// Explanation: 
/// Here are the non-negative integers <= 5 with their corresponding 
/// binary representations:
/// 0 : 0
/// 1 : 1
/// 2 : 10
/// 3 : 11
/// 4 : 100
/// 5 : 101
/// Among them, only integer 3 disobeys the rule (two consecutive ones) 
/// and the other 5 satisfy the rule. 
/// Note: 1 <= n <= 10^9 
/// </summary>
int LeetCodeDP::findIntegers(int num)
{
    vector<int> bit_map;
    int result = 0;
    while (num != 0)
    {
        bit_map.push_back(num % 2);
        num /= 2;
    }
    vector<vector<int>> dp(bit_map.size(), vector<int>(2));
    // count on every single bits when it is 0 or 1, how many answer we get in the lower bits
    for (size_t i = 0; i < bit_map.size(); i++)
    {
        if (i == 0)
        {
            dp[i][0] = 1;
            dp[i][1] = 2;
        }
        else
        {
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] = dp[i - 1][1];
        }
    }

    for (size_t i = 0; i < bit_map.size(); i++)
    {
        int bit_index = bit_map.size() - 1 - i;
        int bit_value = bit_map[bit_index];
        if (bit_index == 0)
        {
            result += dp[bit_index][bit_value];
        }
        else
        {
            if (bit_value == 1)
            {
                result += dp[bit_index][0];
                // if we hit "11", we return
                if ((i > 0) && (bit_map[bit_index + 1] == 1))
                {
                    break;
                }
            }
        }
    }
    return result;
}

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
/// 1.The length of the given array will be in range [3,10^4] and all 
///   elements are in the range [-1000, 1000].
/// 2.Multiplication of any three numbers in the input won't exceed the 
///   range of 32-bit signed integer.
/// </summary>
int LeetCodeDP::maximumProduct(vector<int>& nums)
{
    vector<pair<int, int>> product_array = vector<pair<int, int>>(3, make_pair(1, 1));
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (int k = (int)product_array.size() - 1; k >= 0; k--)
        {
            if (i <= (size_t)k)
            {
                product_array[k].first *= nums[i];
                product_array[k].second *= nums[i];
            }
            else if (k == 0)
            {
                product_array[k].first = min(product_array[k].first, nums[i]);
                product_array[k].second = max(product_array[k].second, nums[i]);
            }
            else
            {
                product_array[k].first = min(product_array[k].first, min(nums[i] * product_array[k - 1].first, nums[i] * product_array[k - 1].second));
                product_array[k].second = max(product_array[k].second, max(nums[i] * product_array[k - 1].first, nums[i] * product_array[k - 1].second));
            }
        }
    }
    return product_array[product_array.size() - 1].second;
}

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
int LeetCodeDP::kInversePairs(int n, int k)
{
    unsigned long long M = 1000000007;
    vector<vector<long long>> dp = vector<vector<long long>>(n + 1, vector<long long>(k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= k; ++j)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % M;
            if (j - i >= 0)
            {
                // It must + mod, If you don't know why, 
                // you can check the case 1000, 1000
                dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + M) % M;
            }
        }
    }
    return (int)dp[n][k];
}

/// <summary>
/// Leet code #634. Find the Derangement of An Array
/// 
/// In combinatorial mathematics, a derangement is a permutation of the 
/// elements of a set, such that no element appears in its original 
/// position.
/// 
/// There's originally an array consisting of n integers from 1 to n in 
/// ascending order, you need to find the number of derangement it can 
/// generate.
/// 
/// Also, since the answer may be very large, you should return the output 
/// mod 10^9 + 7.
///
/// Example 1:
/// Input: 3
/// Output: 2
/// Explanation: The original array is [1,2,3]. The two derangements are 
/// [2,3,1] and [3,1,2].
/// Note:
/// n is in the range of [1, 10^6].
/// </summary>
int LeetCodeDP::findDerangement(int n)
{
    int M = 1000000007;
    vector<int> dp = vector<int>(n + 1);
    dp[1] = 0;
    if (n > 1) dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (int)((((long long)i - 1) * ((long long)dp[i - 1] + (long long)dp[i - 2])) % M);
    }
    return dp[n];
}

/// <summary>
/// Leet code #639. Decode Ways II
/// 
/// A message containing letters from A-Z is being encoded to numbers using 
/// the following mapping way: 
/// 'A' -> 1
/// 'B' -> 2
/// ...
/// 'Z' -> 26
/// Beyond that, now the encoded string can also contain the character '*', 
/// which can be treated as one of the numbers from 1 to 9. 
/// Given the encoded message containing digits and the character '*', return 
/// the total number of ways to decode it. 
/// Also, since the answer may be very large, you should return the output 
/// mod 10^9 + 7. 
///
/// Example 1:
/// Input: "*"
/// Output: 9
/// Explanation: The encoded message can be decoded to the string: "A", "B", 
/// "C", "D", "E", "F", "G", "H", "I".
///
/// Example 2:
/// Input: "1*"
/// Output: 9 + 9 = 18
///
/// Note:
/// The length of the input string will fit in range [1, 10^5].
/// The input string will only contain the character '*' and digits '0' - '9'.
/// </summary>
int LeetCodeDP::numDecodingsII(string s)
{
    if (s.empty()) return 0;
    int M = 1000000007;
    vector<int> dp(s.size());
    for (size_t i = 0; i < s.size(); i++)
    {
        if ((s[i] >= '1') && (s[i] <= '9'))
        {
            if (i == 0) dp[i] += 1;
            else dp[i] = (dp[i] + dp[i - 1]) % M;
        }
        else if (s[i] == '*')
        {
            if (i == 0) dp[i] += 9;
            else dp[i] = (int)(((long long)dp[i] + 9 * (long long)dp[i - 1]) % M);
        }

        if (i > 0)
        {
            if ((s[i - 1] == '1' && s[i] >= '0' && s[i] <= '9') ||
                (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))
            {
                if (i == 1) dp[i] += 1;
                else dp[i] = (dp[i] + dp[i - 2]) % M;
            }
            else if (s[i - 1] == '1' && s[i] == '*')
            {
                if (i == 1) dp[i] += 9;
                else dp[i] = (int)(((long long)dp[i] + 9 * (long long)dp[i - 2]) % M);
            }
            else if (s[i - 1] == '2' && s[i] == '*')
            {
                if (i == 1) dp[i] += 6;
                else dp[i] = (int)(((long long)dp[i] + 6 * (long long)dp[i - 2]) % M);
            }
            else if (s[i - 1] == '*' && s[i] == '*')
            {
                if (i == 1) dp[i] += 15;
                else dp[i] = (int)(((long long)dp[i] + 15 * (long long)dp[i - 2]) % M);
            }
            else if (s[i - 1] == '*' && s[i] >= '0' && s[i] <= '6')
            {
                if (i == 1) dp[i] += 2;
                else dp[i] = (int)(((long long)dp[i] + 2 * (long long)dp[i - 2]) % M);
            }
            else if (s[i - 1] == '*' && s[i] >= '7' && s[i] <= '9')
            {
                if (i == 1) dp[i] += 1;
                else dp[i] = (int)(((long long)dp[i] + 1 * (long long)dp[i - 2]) % M);
            }
        }
    }
    return dp[s.size() - 1];
}

/// <summary>
/// Leet code #647. Palindromic Substrings
/// 
/// Given a string, your task is to count how many palindromic substrings 
/// in this string. 
/// The substrings with different start indexes or end indexes are counted 
/// as different substrings even they consist of same characters. 
/// Example 1:
/// Input: "abc"
/// Output: 3
/// Explanation: Three palindromic strings: "a", "b", "c".
/// 
/// Example 2:
/// Input: "aaa"
/// Output: 6
/// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
///    
/// Note:
/// The input string length won't exceed 1000.
/// </summary>
int LeetCodeDP::countSubstrings(string s)
{
    int n = s.size();
    int result = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (size_t k = 0; k < s.size(); k++)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (i + k >= s.size()) break;
            if (k == 0)
            {
                dp[i][i] = true;
                result++;
            }
            else if (s[i] == s[i + k])
            {
                if ((k == 1) || (dp[i + 1][i + k - 1]))
                {
                    dp[i][i + k] = true;
                    result++;
                }
            }
        }
    }
    return result;
}


/// <summary>
/// Leet code #650. 2 Keys Keyboard
/// 
/// Initially on a notepad only one character 'A' is present. You can 
/// perform two operations on this notepad for each step:
///
/// Copy All: You can copy all the characters present on the notepad 
/// (partial copy is not allowed).
/// Paste: You can paste the characters which are copied last time.
/// Given a number n. You have to get exactly n 'A' on the notepad by 
/// performing the minimum number of steps permitted. Output the minimum 
/// number of steps to get n 'A'.
/// 
/// Example 1:
/// Input: 3
/// Output: 3
/// Explanation:
/// Intitally, we have one character 'A'.
/// In step 1, we use Copy All operation.
/// In step 2, we use Paste operation to get 'AA'.
/// In step 3, we use Paste operation to get 'AAA'.
/// Note:
/// 1. The n will be in the range [1, 1000].
/// </summary>
int LeetCodeDP::minSteps(int n)
{
    if (n <= 0) return 0;
    vector<int> dp(n, n);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (n % (i + 1) == 0)
        {
            for (int j = 2 * i + 1; j < n; j += (i + 1))
            {
                if (j == 2 * i + 1) dp[j] = min(dp[j], dp[j - (i + 1)] + 2);
                else dp[j] = min(dp[j], dp[j - (i + 1)] + 1);
            }
        }
    }
    return dp[n - 1];
}

/// <summary>
/// Leet code #651. 4 Keys Keyboard
/// compare the new step with the existing stored set, if either position 
/// (first) or the step length win, we will insert the new step, 
/// otherwise throw away.
/// In the same trip, we retire the loser in the set
/// </summary>
void LeetCodeDP::insert_step(pair<int, int>&step, set<pair<int, int>> &step_set)
{
    for (set<pair<int, int>>::iterator itr = step_set.begin(); itr != step_set.end();)
    {
        // new step lose, we return
        if (step.first <= itr->first && step.second <= itr->second)
        {
            return;
        }
        else if (step.first >= itr->first && step.second >= itr->second)
        {
            set<pair<int, int>>::iterator tmp = itr;
            tmp++;
            step_set.erase(itr);
            itr = tmp;
        }
        else
        {
            itr++;
        }
    }
    step_set.insert(step);
}

/// <summary>
/// Leet code #651. 4 Keys Keyboard
/// 
/// Key 1: (A): Prints one 'A' on screen.
/// Key 2: (Ctrl-A): Select the whole screen.
/// Key 3: (Ctrl-C): Copy selection to buffer.
/// Key 4: (Ctrl-V): Print buffer on screen appending it after what has 
///        already been printed.
/// Now, you can only press the keyboard for N times (with the above four 
/// keys), find out the maximum numbers of 'A' you can print on screen.
/// Example 1:
/// Input: N = 3
/// Output: 3
/// Explanation: 
/// We can at most get 3 A's on screen by pressing following key sequence:
/// A, A, A
/// Example 2:
/// Input: N = 7
/// Output: 9
/// Explanation: 
/// We can at most get 9 A's on screen by pressing following key sequence:
/// A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
/// Note:
/// 1. 1 <= N <= 50
/// 2. Answers will be in the range of 32-bit signed integer.
/// </summary>
int LeetCodeDP::maxA(int N)
{
    // the pair is (position, step);
    vector<set<pair<int, int>>> key_map(N + 1);

    key_map[1].insert(make_pair(1, 1));
    for (int i = 1; i < N; i++)
    {
        for (auto& step : key_map[i])
        {
            // handle A or Ctrl V
            pair<int, int> new_step = 
                make_pair(step.first + step.second, step.second);
            insert_step(new_step, key_map[i + 1]);
            if (i + 3 <= N)
            {
                // handle  Ctrl A, Ctrl C, Ctrl V
                new_step = make_pair(step.first + step.first, step.first);
                insert_step(new_step, key_map[i + 3]);
            }
        }
    }
    int result = INT_MIN;
    for (auto& t : key_map[N])
    {
        result = max(result, t.first);
    }
    return result;
}

/// <summary>
/// Leet code #656. Coin Path
/// 
/// Given an array A (index starts at 1) consisting of N integers: A1, A2,
///	..., AN and an integer B. The integer B denotes that from any place 
/// (suppose the index is i) in the array A, you can jump to any one of 
/// the place in the array A indexed i+1, i+2, …, i+B if this place can 
/// be jumped to. Also, if you step on the index i, you have to pay Ai 
/// coins. If Ai is -1, it means you can’t jump to the place indexed i in 
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
vector<int> LeetCodeDP::cheapestJump(vector<int>& A, int B)
{
    vector<int> result;
    vector<pair<vector<int>, int>> dp(A.size());

    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == -1) continue;
        if (i == 0)
        {
            dp[i].first.push_back(1);
            dp[i].second = A[i];
        }
        else
        {
            if (dp[i].first.empty()) continue;
        }

        for (size_t j = 1; (j <= (size_t)B) && (i + j < A.size()); j++)
        {
            if (A[i + j] == -1) continue;
            vector<int> new_path = dp[i].first;
            new_path.push_back(i + j + 1);
            if ((dp[i + j].first.empty()) || 
                (dp[i + j].second > dp[i].second + A[i + j]) ||
                ((dp[i + j].second == dp[i].second + A[i + j]) && 
                 (dp[i + j].first > new_path)))
            {
                dp[i + j] = make_pair(new_path, dp[i].second + A[i + j]);
            }
        }
    }

    if (A.empty()) return result;
    result = dp[A.size() - 1].first;
    return result;
}

/// <summary>
/// Leet code #	660. Remove 9
/// Start from integer 1, remove any integer that contains 9 such as 9, 
/// 19, 29...
///
/// So now, you will have a new integer sequence: 1, 2, 3, 4, 5, 6, 7, 
/// 8, 10, 11, ...
///
/// Given a positive integer n, you need to return the n-th integer after 
/// removing. Note that 1 will be the first integer.
///
/// Example 1:
/// Input: 9
/// Output: 10
/// Hint: n will not exceed 9 x 10^8.
/// </summary>
int LeetCodeDP::newInteger(int n)
{
    // remeber each digit of the result;
    vector<int> nums;
    // A[i] stands for how many number in  i dights without 9
    // S[i] stands for how many numbers totally until i digits without 9
    vector<int> A, S;
    // A[0] = 1, which is 0
    A.push_back(1);
    S.push_back(1);

    // we add zero in front, so count n + 1
    while (S.back() < n + 1)
    {
        A.push_back(8 * S.back());
        S.push_back(S.back() + A.back());
    }

    while (S.size() > 1)
    {
        S.pop_back();
        int digit = n / S.back();
        nums.push_back(digit);
        n -= digit * S.back();
    }

    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        result = result * 10 + nums[i];
    }
    return result;
}

/// <summary>
/// Leet code #664. Strange Printer
/// 
/// There is a strange printer with the following two special requirements:
/// The printer can only print a sequence of the same character each time.
///
/// At each turn, the printer can print new characters starting from and 
/// ending at any places, and will cover the original existing characters.
/// Given a string consists of lower English letters only, your job is to 
/// count the minimum number of turns the printer needed in order to print 
/// it.
///
/// Example 1:
///
/// Input: "aaabbb"
/// Output: 2
/// Explanation: Print "aaa" first and then print "bbb".
///
/// Example 2:
/// Input: "aba"
/// Output: 2
/// Explanation: Print "aaa" first and then print "b" from the second 
/// place of the string, which will cover the existing character 'a'.
///
/// Hint: Length of the given string will not exceed 100.
/// </summary>
int LeetCodeDP::strangePrinter(string s)
{
    if (s.empty()) return 0;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), INT_MAX));
    for (size_t len = 0; len < s.size(); len++)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (i + len >= s.size()) break;
            if (len == 0)
            {
                dp[i][i + len] = 1;
                continue;
            }
            for (size_t j = i; j < i + len; j++)
            {
                int count = dp[i][j] + dp[j + 1][i + len];
                if (s[j] == s[i + len]) count--;

                dp[i][i + len] = min(dp[i][i + len], count);
            }
        }
    }
    return dp[0][s.size() - 1];
}

/// <summary>
/// Leet code #688. Knight Probability in Chessboard
///
/// On an NxN chessboard, a knight starts at the r-th row and c-th column 
/// and attempts to make exactly K moves. The rows and columns are 0 
/// indexed, so the top-left square is (0, 0), and the bottom-right square 
/// is (N-1, N-1).
/// A chess knight has 8 possible moves it can make, as illustrated below. 
/// Each move is two squares in a cardinal direction, then one square in 
/// an orthogonal direction.
/// 
/// Each time the knight is to move, it chooses one of eight possible moves 
/// uniformly at random (even if the piece would go off the chessboard) and 
/// moves there.
/// 
/// The knight continues moving until it has made exactly K moves or has 
/// moved off the chessboard. Return the probability that the knight 
/// remains on the board after it has stopped moving.
///
/// Example:
/// Input: 3, 2, 0, 0
/// Output: 0.0625
/// Explanation: There are two moves (to (1,2), (2,1)) that will keep the 
/// knight on the board.
/// From each of those positions, there are also two moves that will keep 
/// the knight on the board.
/// The total probability the knight stays on the board is 0.0625.
/// Note:
/// 1. N will be between 1 and 25.
/// 2. K will be between 0 and 100.
/// 3. The knight always initially starts on the board.
/// </summary>
double LeetCodeDP::knightProbability(int N, int K, int r, int c)
{
    vector<pair<int, int>> steps =
    {
        { -2, -1 },{ -1, -2 },{ 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 },{ -1, 2 },{ -2, 1 }
    };
    map<pair<int, int>, double> current_set;
    double possibility = (double) 1.0;
    current_set[make_pair(r, c)] = 1;
    for (int i = 0; i < K; i++)
    {
        map<pair<int, int>, double> next_set;
        double onboard_move = 0;
        double total_move = 0;
        for (auto &itr : current_set)
        {
            pair<int, int> pos = itr.first;
            for (size_t j = 0; j < steps.size(); j++)
            {
                pair<int, int> next = make_pair(pos.first + steps[j].first, pos.second + steps[j].second);
                if ((next.first < 0) || (next.first >= N) || (next.second < 0) || (next.second >= N))
                {
                    continue;
                }
                onboard_move += itr.second;
                next_set[next] += itr.second;
            }
            total_move += itr.second * 8;
        }
        if (total_move == 0) possibility = 0;
        else possibility = possibility * onboard_move / total_move;
        current_set = next_set;
    }
    return possibility;
}

/// <summary>
/// Leet code #712. Minimum ASCII Delete Sum for Two Strings
/// Given two strings s1, s2, find the lowest ASCII sum of deleted 
/// characters to make two strings equal.
///
/// Example 1:
/// Input: s1 = "sea", s2 = "eat"
/// Output: 231
/// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" 
/// (115) to the sum.
/// Deleting "t" from "eat" adds 116 to the sum.
/// At the end, both strings are equal, and 115 + 116 = 231 is the minimum 
/// sum possible to achieve this.
///
/// Example 2:
/// Input: s1 = "delete", s2 = "leet"
/// Output: 403
/// Explanation: Deleting "dee" from "delete" to turn the string into 
/// "let", adds 100{d}+101{e}+101{e} to the sum.  Deleting "e" from "leet" 
/// adds 101{e} to the sum.
/// At the end, both strings are equal to "let", and the answer is 
/// 100+101+101+101 = 403.
/// If instead we turned both strings into "lee" or "eet", we would get 
/// answers of 433 or 417, which are higher.
/// Note:
///
/// 0 < s1.length, s2.length <= 1000.
/// All elements of each string will have an ASCII value in {97, 122}.
/// </summary>
int LeetCodeDP::minimumDeleteSum(string s1, string s2)
{
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
    for (size_t i = 0; i <= s1.size(); i++)
    {
        for (size_t j = 0; j <= s2.size(); j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + (int)s2[j - 1];
                }
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + (int)s1[i - 1];
            }
            else
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + (int)s1[i - 1] + (int)s2[j - 1];
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (int)s1[i - 1]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (int)s2[j - 1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

/// <summary>
/// Leet code #718. Maximum Length of Repeated Subarray
///
/// Given two integer arrays A and B, return the maximum length of an 
/// subarray that appears in both arrays.
///
/// Example 1:
/// Input:
/// A: [1,2,3,2,1]
/// B: [3,2,1,4,7]
/// Output: 3
/// Explanation: 
/// The repeated subarray with maximum length is [3, 2, 1].
/// Note:
/// 1. 1 <= len(A), len(B) <= 1000
/// 2. 0 <= A[i], B[i] < 100
/// </summary>
int LeetCodeDP::findLength(vector<int>& A, vector<int>& B)
{
    int result = 0;
    vector<vector<int>> dp(A.size(), vector<int>(B.size()));
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < B.size(); j++)
        {
            if (A[i] == B[j])
            {
                if ((i == 0) || (j == 0)) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #689. Maximum Sum of 3 Non-Overlapping Subarrays
///
/// In a given array nums of positive integers, find three non-overlapping 
/// subarrays with maximum sum.
///
/// Each subarray will be of size k, and we want to maximize the sum of all
/// 3*k entries.
/// Return the result as a list of indices representing the starting 
/// position of each interval (0-indexed). If there are multiple answers, 
/// return the lexicographically smallest one.
/// 
/// Example:
/// Input: [1,2,1,2,6,7,5,1], 2
/// Output: [0, 3, 5]
/// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the 
/// starting indices [0, 3, 5].
/// We could have also taken [2, 1], but an answer of [1, 3, 5] would be 
/// lexicographically larger.
/// Note:
/// 1.nums.length will be between 1 and 20000.
/// 2.nums[i] will be between 1 and 65535.
/// 3.k will be between 1 and floor(nums.length / 3).
/// </summary>
vector<int> LeetCodeDP::maxSumOfThreeSubarrays(vector<int>& nums, int k)
{
    vector<int> result;
    vector<int> sum_k(nums.size());
    vector<pair<int, set<int>>> current(nums.size());
    int sum = 0;
    // calculate all consecutive;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (i >= (size_t)k) sum = sum - nums[i - k];
        if (i >= (size_t)k - 1) sum_k[i] = sum;
    }
    // calculate maximum subarray;
    for (size_t i = 0; i < 3; i++)
    {
        vector<pair<int, set<int>>> next(nums.size());
        for (size_t j = 0; j < sum_k.size(); j++)
        {
            if (j < (i + 1) * k - 1)
            {
                next[j].first = 0;
            }
            else if (i == 0 && j == k - 1)
            {
                next[j].first = sum_k[j];
                next[j].second.insert(j - (k - 1));
            }
            else
            {
                if (sum_k[j] + current[j - k].first > next[j - 1].first)
                {
                    next[j].first = sum_k[j] + current[j - k].first;
                    next[j].second = current[j - k].second;
                    next[j].second.insert(j - k + 1);
                }
                else
                {
                    next[j].first = next[j - 1].first;
                    next[j].second = next[j - 1].second;
                }
            }
        }
        current = next;
    }
    for (int index : current[nums.size() - 1].second)
    {
        result.push_back(index);
    }
    return result;
}

/// <summary>
/// Leet code #714. Best Time to Buy and Sell Stock with Transaction Fee
/// Your are given an array of integers prices, for which the i-th element 
/// is the price of a given stock on day i; and a non-negative integer fee 
/// representing a transaction fee.
///
/// You may complete as many transactions as you like, but you need to pay 
/// the transaction fee for each transaction. You may not buy more than 1 
/// share of a stock at a time (ie. you must sell the stock share before 
/// you buy again.)
///
/// Return the maximum profit you can make.
///
/// Example 1:
/// Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
/// Output: 8  
/// Explanation: The maximum profit can be achieved by:
/// Buying at prices[0] = 1
/// Selling at prices[3] = 8
/// Buying at prices[4] = 4
/// Selling at prices[5] = 9
/// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
/// Note:
///
/// 1. 0 < prices.length <= 50000.
/// 2. 0 < prices[i] < 50000.
/// 3. 0 <= fee < 50000.	
/// </summary>
int LeetCodeDP::maxProfitWithFee(vector<int>& prices, int fee)
{
    vector<int> dp;
    for (size_t i = 0; i < prices.size(); i++)
    {
        if (dp.empty()) dp.push_back(prices[i]);
        else if (prices[i] < dp.back())
        {
            // two consective price drops, we only keep one
            // if only one price there, also pop it
            if ((dp.size() == 1) || (dp.size() > 1 && dp.back() < dp[dp.size() - 2]))
            {
                dp.pop_back();
            }
            // price drop and gap is more than fee			
            if (dp.empty() || dp.back() - prices[i] > fee)
            {
                dp.push_back(prices[i]);
            }
        }
        else
        {
            // two consective price increase, we only keep one
            if (dp.size() > 1 && dp.back() > dp[dp.size() - 2])
            {
                dp.pop_back();
            }
            // price increase and gap is more than fee
            if (prices[i] - dp.back() > fee)
            {
                dp.push_back(prices[i]);
            }
        }
    }

    int result = 0;
    for (size_t i = 1; i < dp.size(); i += 2)
    {
        result += dp[i] - dp[i - 1] - fee;
    }
    return result;
}

/// <summary>
/// Leet code #727. Minimum Window Subsequence
///
/// Given strings S and T, find the minimum (contiguous) substring W of S,
/// so that T is a subsequence of W.
///
/// If there is no such window in S that covers all characters in T, return 
/// the empty string "". If there are multiple such minimum-length windows, 
/// return the one with the left-most starting index.
///
/// Example 1:
/// Input: 
/// S = "abcdebdde", T = "bde"
/// Output: "bcde"
/// Explanation: 
/// "bcde" is the answer because it occurs before "bdde" which has the same 
/// length.
/// "deb" is not a smaller window because the elements of T in the window 
/// must occur in order.
/// Note:
///
/// All the strings in the input will only contain lowercase letters.
/// The length of S will be in the range [1, 20000].
/// The length of T will be in the range [1, 100].
/// </summary>
string LeetCodeDP::minWindowIII(string S, string T)
{
    vector<int> prev(T.size(), -1);
    string result = "";
    for (size_t i = 0; i < S.size(); i++)
    {
        vector<int> curr(T.size(), -1);
        for (size_t j = 0; j < T.size(); j++)
        {
            if ((j != 0) && (prev[j - 1] < 0))
            {
                break;
            }
            if (S[i] == T[j])
            {
                if (j == 0) curr[j] = i;
                else curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        if (curr[T.size() - 1] >= 0)
        {
            int length = i - curr[T.size() - 1] + 1;
            if ((result == "") || (result.size() > (size_t)length))
            {
                result = S.substr(curr[T.size() - 1], length);
            }
        }
        prev = curr;
    }
    return result;
}

/// <summary>
/// Leet code #730. Count Different Palindromic Subsequences
///
/// Given a string S, find the number of different non-empty palindromic 
/// subsequences in S, and return that number modulo 10^9 + 7.
///
/// A subsequence of a string S is obtained by deleting 0 or more 
/// characters from S.
///
/// A sequence is palindromic if it is equal to the sequence reversed.
///
/// Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there 
/// is some i for which A_i != B_i.
///
/// Example 1:
/// Input: 
/// S = 'bccb'
/// Output: 6
/// Explanation: 
/// The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 
/// 'cc', 'bcb', 'bccb'.
/// Note that 'bcb' is counted only once, even though it occurs twice.
/// Example 2:
/// Input: 
/// S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
/// Output: 104860361
/// Explanation: 
/// There are 3104860382 different non-empty palindromic subsequences, 
/// which is 104860361 modulo 10^9 + 7.
/// Note:
///
/// 1. The length of S will be in the range [1, 1000].
/// 2. Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.
/// </summary>
/// <hint>
/// The key is that to think that starting from any position, with length as 
/// len, we count the total palindromic subsequences start with 
/// ch = 'a' to 'd' 
/// </hint>
int LeetCodeDP::countPalindromicSubsequences(string S)
{
    unsigned long long mod = 1000000007;
    vector<vector<map<char, int>>> dp(3, vector<map<char, int>>(S.size(), map<char, int>()));

    for (size_t len = 1; len <= S.size(); len++)
    {
        for (size_t i = 0; i + len <= S.size(); i++)
        {
            for (char ch = 'a'; ch <= 'd'; ch++)
            {
                if (len == 1)
                {
                    if (S[i] == ch) dp[2][i][ch] = 1;
                    else dp[2][i][ch] = 0;
                }
                else
                {
                    if (S[i] != ch) dp[2][i][ch] = dp[1][i + 1][ch];
                    else if (S[i + len - 1] != ch) dp[2][i][ch] = dp[1][i][ch];
                    else
                    {
                        dp[2][i][ch] = 2;
                        if (len > 2)
                        {
                            for (char k = 'a'; k <= 'd'; k++)
                            {
                                dp[2][i][ch] += dp[0][i + 1][k];
                                dp[2][i][ch] %= mod;
                            }
                        }
                    }
                }
            }
        }
        for (size_t j = 0; j < 2; j++)
        {
            dp[j] = dp[j + 1];
        }
    }
    int result = 0;
    for (char ch = 'a'; ch <= 'd'; ch++)
    {
        result += dp[2][0][ch];
        result %= mod;
    }
    return result;
}

/// <summary>
/// Leet code #740. Delete and Earn
///
/// Given an array nums of integers, you can perform operations on the 
/// array. 
/// In each operation, you pick any nums[i] and delete it to earn nums[i] 
/// points. After, you must delete every element equal to nums[i] - 1 or 
/// nums[i] + 1. 
/// You start with 0 points. Return the maximum number of points you can 
/// earn by applying such operations. 
///
/// Example 1:
/// Input: nums = [3, 4, 2]
/// Output: 6
/// Explanation: 
/// Delete 4 to earn 4 points, consequently 3 is also deleted.
/// Then, delete 2 to earn 2 points. 6 total points are earned.
///
/// Example 2:
/// Input: nums = [2, 2, 3, 3, 3, 4]
/// Output: 9
/// Explanation: 
/// Delete 3 to earn 3 points, deleting both 2's and the 4.
/// Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
/// 9 total points are earned.
///
/// Note: 
/// The length of nums is at most 20000.
/// Each element nums[i] is an integer in the range [1, 10000].
/// </summary> 
int LeetCodeDP::deleteAndEarn(vector<int>& nums)
{
    if (nums.empty()) return 0;
    int result = 0;
    map<int, int> sum_map;
    vector<pair<int, int>> sum_nums;
    for (size_t i = 0; i < nums.size(); i++) sum_map[nums[i]] += nums[i];
    for (auto &itr : sum_map)
    {
        sum_nums.push_back(make_pair(itr.first, itr.second));
    }
    vector<vector<int>> dp(sum_nums.size(), vector<int>(sum_nums.size()));
    for (size_t len = 0; len < sum_nums.size(); len++)
    {
        for (size_t i = 0; i + len < sum_nums.size(); i++)
        {
            if (len == 0)
            {
                dp[i][i] = sum_nums[i].second;
            }
            else
            {
                int right = 0;
                if (sum_nums[i].first < sum_nums[i + 1].first - 1)
                {
                    right = dp[i + 1][i + len] + dp[i][i];
                }
                else if (len > 1)
                {
                    right = max(dp[i + 1][i + len], dp[i + 2][i + len] + dp[i][i]);
                }
                else
                {
                    right = max(dp[i + 1][i + len], dp[i][i]);
                }
                dp[i][i + len] = max(dp[i][i + len], right);
            }
        }
    }
    return dp[0][sum_nums.size() - 1];
}

/// <summary>
/// Leet code #741. Cherry Pickup
///
/// In a N x N grid representing a field of cherries, each cell is one of 
/// three possible integers.
///
/// 0 means the cell is empty, so you can pass through;
/// 1 means the cell contains a cherry, that you can pick up and pass 
/// through;
/// -1 means the cell contains a thorn that blocks your way.
/// Your task is to collect maximum number of cherries possible by 
/// following the rules below:
///
/// Starting at the position (0, 0) and reaching (N-1, N-1) by moving 
/// right or down through valid path cells (cells with value 0 or 1);
/// After reaching (N-1, N-1), returning to (0, 0) by moving left or up 
/// through valid path cells;
/// When passing through a path cell containing a cherry, you pick it up 
/// and the cell becomes an empty cell (0);
/// If there is no valid path between (0, 0) and (N-1, N-1), then no 
/// cherries can be collected.
/// Example 1:
/// Input: grid =
/// [[0, 1, -1],
///  [1, 0, -1],
/// [1, 1,  1]]
/// Output: 5
/// Explanation: 
/// The player started at (0, 0) and went down, down, right right to reach 
/// (2, 2).
/// 4 cherries were picked up during this single trip, and the matrix 
/// becomes [[0,1,-1],[0,0,-1],[0,0,0]].
/// Then, the player went left, up, up, left to return home, picking up one
/// more cherry.
/// The total number of cherries picked up is 5, and this is the maximum 
/// possible.
///
/// Note:
/// grid is an N by N 2D array, with 1 <= N <= 50.
/// Each grid[i][j] is an integer in the set {-1, 0, 1}.
/// It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.
/// </summary> 
int LeetCodeDP::cherryPickup(vector<vector<int>>& grid)
{
    size_t n = grid.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = 0;
    // iterate 2 N - 1 steps
    for (size_t k = 0; k < 2 * grid.size() - 1; k++)
    {
        vector<vector<int>> next(n, vector<int>(n, -1));
        // path one has i steps down
        for (size_t i = 0; i < k && i < n; i++)
        {
            // too few steps down on total k steps
            if (k - i >= n) continue;
            // path two has j steps down
            for (size_t j = 0; j < k && j < n; j++)
            {
                // too few steps down on total k steps
                if (k - j >= n) continue;
                // there is a thorn in of them path not possible
                if ((grid[i][k - i] < 0) || (grid[j][k - j] < 0))
                {
                    continue;
                }
                // path one from left to right, path two from left to right
                int cherries = dp[i][j];
                // path one from up to down, path two from up to down
                if ((i > 0) && (j > 0)) cherries = max(cherries, dp[i - 1][j - 1]);
                // path one from up to down, path two from left to right
                if (i > 0) cherries = max(cherries, dp[i - 1][j]);
                // path one from left to right, path two from up to down
                if (j > 0) cherries = max(cherries, dp[i][j - 1]);
                // due to the block no way to reach the position

                if (cherries < 0) continue;

                // add the current position on path one
                cherries += grid[i][k - i];
                // add the current position on path two.
                if (i != j) cherries += grid[j][k - j];

                next[i][j] = cherries;

            }
        }
        // copy over current steps
        dp = next;
    }
    return max(0, dp[n - 1][n - 1]);
}

int LeetCodeDP::cherryPickupX(vector<vector<int>>& grid)
{
    int n = grid.size();
    if (n == 0) return 0;

    // on any position combination what is the maximum cherry pick at specific step.
    map<pair<pair<int, int>, pair<int, int>>, int> dp;
    // all possible position for perosn one and person two at specific step.
    vector<vector<int>> directions = { { 1, 0 },{ 0, 1 } };
    // iterate 2 N - 1 steps
    for (int k = 0; k < 2 * n - 1; k++)
    {
        map<pair<pair<int, int>, pair<int, int>>, int> next;
        if (k == 0)
        {
            pair<int, int> pos = make_pair(0, 0);
            next[make_pair(pos, pos)] = grid[0][0];
        }
        else
        {
            for (const auto& itr : dp)
            {
                pair<int, int> pos1 = itr.first.first;
                pair<int, int> pos2 = itr.first.second;
                for (size_t i = 0; i < 2; i++)
                {
                    pair<int, int> next_pos1 = pos1;
                    next_pos1.first += directions[i][0];
                    next_pos1.second += directions[i][1];
                    if ((next_pos1.first >= n) || (next_pos1.second >= n) || (grid[next_pos1.first][next_pos1.second] < 0))
                    {
                        continue;
                    }
                    for (size_t j = 0; j < 2; j++)
                    {
                        pair<int, int> next_pos2 = pos2;
                        next_pos2.first += directions[j][0];
                        next_pos2.second += directions[j][1];
                        if ((next_pos2.first >= n) || (next_pos2.second >= n) || (grid[next_pos2.first][next_pos2.second] < 0))
                        {
                            continue;
                        }

                        int value = dp[make_pair(pos1, pos2)] + grid[next_pos1.first][next_pos1.second];
                        if (next_pos1 != next_pos2)
                        {
                            value += grid[next_pos2.first][next_pos2.second];
                        }
                        next[make_pair(next_pos1, next_pos2)] = max(next[make_pair(next_pos1, next_pos2)], value);
                    }
                }
            }
        }
        dp = next;
    }
    pair<int, int> pos = make_pair(n - 1, n - 1);
    return dp[make_pair(pos, pos)];
}

/// <summary>
/// Leet code #746. Min Cost Climbing Stairs
///
/// On a staircase, the i-th step has some non-negative cost cost[i] 
/// assigned (0 indexed).
///
/// Once you pay the cost, you can either climb one or two steps. You need 
/// to find minimum cost to reach the top of the floor, and you can either 
/// start from the step with index 0, or the step with index 1.
///
/// Example 1:
/// Input: cost = [10, 15, 20]
/// Output: 15
/// Explanation: Cheapest is start on cost[1], pay that cost and go to 
/// the top.
/// Example 2:
/// Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
/// Output: 6
/// Explanation: Cheapest is start on cost[0], and only step on 1s, 
/// skipping cost[3].
/// Note:
/// 1. cost will have a length in the range [2, 1000].
/// 2. Every cost[i] will be an integer in the range [0, 999].
/// </summary>
int LeetCodeDP::minCostClimbingStairs(vector<int>& cost)
{
    vector<int> dp(cost.size() + 1);
    for (size_t i = 0; i <= cost.size(); i++)
    {
        if ((i == 0) || (i == 1)) dp[i] = 0;
        else
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
    }
    return dp[cost.size()];
}

/// <summary>
/// Leetcode #764. Largest Plus Sign
///
/// In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except 
/// those cells in the given list mines which are 0. What is the largest 
/// axis-aligned plus sign of 1s contained in the grid? Return the order of 
/// the plus sign. If there is none, return 0.
///
/// An "axis-aligned plus sign of 1s of order k" has some center 
/// grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, 
/// and right, and made of 1s. This is demonstrated in the diagrams below. 
/// Note that there could be 0s or 1s beyond the arms of the plus sign, 
/// only the relevant area of the plus sign is checked for 1s.
///
/// Examples of Axis-Aligned Plus Signs of Order k:
/// Order 1:
/// 000
/// 010
/// 000
///
/// Order 2:
/// 00000
/// 00100
/// 01110
/// 00100
/// 00000
///
/// Order 3:
/// 0000000
/// 0001000
/// 0001000
/// 0111110
/// 0001000
/// 0001000
/// 0000000
///
/// Example 1:
/// Input: N = 5, mines = [[4, 2]]
/// Output: 2
/// Explanation:
/// 11111
/// 11111
/// 11111
/// 11111
/// 11011
/// In the above grid, the largest plus sign can only be order 2.  One of 
/// them is marked in bold.
///
/// Example 2:
/// Input: N = 2, mines = []
/// Output: 1
/// Explanation:
/// There is no plus sign of order 2, but there is of order 1.
///
/// Example 3:
/// Input: N = 1, mines = [[0, 0]]
/// Output: 0
/// Explanation:
/// There is no plus sign, so return 0.
/// Note:
/// 1. N will be an integer in the range [1, 500].
/// 2. mines will have length at most 5000.
/// 3. mines[i] will be length 2 and consist of integers in the range 
/// [0, N-1].
/// (Additionally, programs submitted in C, C++, or C# will be judged 
/// with a slightly smaller time limit.)
/// </summary>
int LeetCodeDP::orderOfLargestPlusSign(int N, vector<vector<int>>& mines)
{
    int result = 0;
    vector<vector<int>> plus(N, vector<int>(N, INT_MAX));
    unordered_map<int, set<int>> rows;
    unordered_map<int, set<int>> cols;
    for (size_t i = 0; i < mines.size(); i++)
    {
        rows[mines[i][0]].insert(mines[i][1]);
        cols[mines[i][1]].insert(mines[i][0]);
    }
    for (size_t k = 0; k < 2; k++)
    {
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (rows.count(i) == 0 || rows[i].count(j) == 0)
                {
                    if (k == 0)
                    {
                        if (i > 0) dp[i][j] = dp[i - 1][j] + 1;
                        else dp[i][j] = 1;
                    }
                    else
                    {
                        if (j > 0) dp[i][j] = dp[i][j - 1] + 1;
                        else dp[i][j] = 1;
                    }
                    plus[i][j] = min(plus[i][j], dp[i][j]);
                }
                else
                {
                    plus[i][j] = 0;
                }
            }
        }
    }
    for (size_t k = 0; k < 2; k++)
    {
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (rows.count(i) == 0 || rows[i].count(j) == 0)
                {
                    if (k == 0)
                    {
                        if (i < N - 1) dp[i][j] = dp[i + 1][j] + 1;
                        else dp[i][j] = 1;
                    }
                    else
                    {
                        if (j < N - 1) dp[i][j] = dp[i][j + 1] + 1;
                        else dp[i][j] = 1;
                    }
                    plus[i][j] = min(plus[i][j], dp[i][j]);
                }
                else
                {
                    plus[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result = max(result, plus[i][j]);
        }
    }
    return result;
}

/// <summary>
/// Leetcode #788. Rotated Digits
/// return 0 if not rotate, 1 if rotate but same, 2 if rotate but diff
/// </summary>
int LeetCodeDP::checkIfRotateDigits(int N)
{
    map<int, int> number_map = { { 0, 0 },{ 1, 0 },{ 2, 1 },{ 5, 1 },{ 6, 1 },{ 8, 0 },{ 9, 1 } };
    int result = 1;
    while (N > 0)
    {
        int low_dight = N % 10;
        if (number_map.count(low_dight) == 0)
        {
            return 0;
        }
        else if (number_map[low_dight] == 1)
        {
            result = 2;
        }
        N = N / 10;
    }
    return result;
}

/// <summary>
/// Leetcode #788. Rotated Digits
/// </summary>
int LeetCodeDP::rotatedDigits(int N, bool is_diff)
{
    map<int, int> number_map = { { 0, 0 },{ 1, 0 },{ 2, 1 },{ 5, 1 },{ 6, 1 },{ 8, 0 },{ 9, 1 } };

    if (N == 0)
    {
        if (is_diff == 0) return 1;
        else return 0;
    }

    int low_digit = N % 10;
    int high_digits = N / 10;
    int same = 0;
    int diff = 0;
    for (int i = 0; i <= low_digit; i++)
    {
        if (number_map.count(i) == 0) continue;
        if (number_map[i] == 0) same++;
        else diff++;
    }
    int result = 0;
    int check = checkIfRotateDigits(high_digits);
    if (check == 1)
    {
        result = diff + (is_diff ? 0 : same);
    }
    else if (check == 2)
    {
        result = same + diff;
    }

    if (high_digits > 0)
    {
        if (is_diff)
        {
            result += 4 * rotatedDigits(high_digits - 1, false);
            result += 3 * rotatedDigits(high_digits - 1, true);
        }
        else
        {
            result += 7 * rotatedDigits(high_digits - 1, false);
        }
    }

    return result;
}

/// <summary>
/// Leetcode #788. Rotated Digits
///
/// X is a good number if after rotating each digit individually by 180 
/// degrees, we get a valid number that is different from X. A number is 
/// valid if each digit remains a digit after rotation. 0, 1, and 8 rotate 
/// to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each 
/// other, and the rest of the numbers do not rotate to any other number.
///
/// Now given a positive number N, how many numbers X from 1 to N are good?
///
/// Example:
/// Input: 10
/// Output: 4
/// Explanation: 
/// There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
/// Note that 1 and 10 are not good numbers, since they remain unchanged 
/// after rotating.
/// Note:
///
/// 1. N  will be in range [1, 10000].
/// </summary>
int LeetCodeDP::rotatedDigits(int N)
{
    return rotatedDigits(N, true);
}

/// <summary>
/// Leet code #790. Domino and Tromino Tiling
/// 
/// We have two types of tiles: a 2x1 domino shape, and an "L" tromino 
/// shape. These shapes may be rotated.
///
/// XX  <- domino
///
/// XX  <- "L" tromino
/// X
/// Given N, how many ways are there to tile a 2 x N board? Return your 
/// answer modulo 10^9 + 7.
///
/// (In a tiling, every square must be covered by a tile. Two tilings 
/// are different if and only if there are two 4-directionally adjacent 
/// cells on the board such that exactly one of the tilings has both 
/// squares occupied by a tile.)
///
/// Example:
/// Input: 3
/// Output: 5
/// Explanation: 
/// The five different ways are listed below, different letters indicates 
/// different tiles:
/// XYZ XXZ XYY XXY XYY
/// XYZ YYZ XZZ XYY XXY
/// Note:
///
/// 1. N  will be in range [1, 1000].
/// </summary>
int LeetCodeDP::numTilings(int N)
{
    unordered_map<int, int> dp = { { 0, 0 },{ 1, 1 },{ 2, 2 },{ 3, 5 } };
    int mod = 1000000007;
    if (dp.count(N) > 0) return dp[N];

    for (int i = 4; i <= N; i++)
    {
        dp[i] = (2 * dp[i - 1] % mod + dp[i - 3]) % mod;
    }
    return dp[N];
}

/// <summary>
/// Leet code #795. Number of Subarrays with Bounded Maximum
///
/// We are given an array A of positive integers, and two positive 
/// integers L and R (L <= R).
///
/// Return the number of (contiguous, non-empty) subarrays such that the 
/// value of the maximum array element in that subarray is at least L and 
/// at most R.
///
/// Example :
/// Input: 
/// A = [2, 1, 4, 3]
/// L = 2
/// R = 3
/// Output: 3
/// Explanation: There are three subarrays that meet the requirements: 
/// [2], [2, 1], [3].
/// Note:
/// 1. L, R  and A[i] will be an integer in the range [0, 10^9].
/// 2. The length of A will be in the range of [1, 50000].
/// </summary>
int LeetCodeDP::numSubarrayBoundedMax(vector<int>& A, int L, int R)
{
    int first = -1;
    size_t last = 0;
    vector<int> dp;
    int result = 0;
    while (last <= A.size())
    {
        if ((last == A.size()) || (A[last] > R))
        {
            if (!dp.empty()) dp.back() *= (last - first);
            while (!dp.empty())
            {
                result += dp.back();
                dp.pop_back();
            }
            first = last;
        }
        else if (A[last] >= L && A[last] <= R)
        {
            int new_count = 0;
            if (dp.empty())
            {
                new_count = last - first;
            }
            else
            {
                new_count = last - first + dp.back();
                dp.back() *= (last - first);
            }
            dp.push_back(new_count);
            first = last;
        }
        last++;
    }
    return result;
}

/// <summary>
/// Leet code #793. Preimage Size of Factorial Zeroes Function
///
/// Let f(x) be the number of zeroes at the end of x!. (Recall that x! = 
/// 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)
/// For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while 
/// f(11) = 2 because 11! = 39916800 has 2 zeroes at the end. Given K, 
/// find how many non-negative integers x have the property that f(x) = K.
/// Example 1:
/// Input: K = 0
/// Output: 5
/// Explanation: 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.
///
/// Example 2:
/// Input: K = 5
/// Output: 0
/// Explanation: There is no x such that x! ends in K = 5 zeroes.
/// Note:
/// 1. K will be an integer in the range [0, 10^9].
/// </summary>
int LeetCodeDP::preimageSizeFZF(int K)
{
    vector<int> dp = { 0 };
    while (K > 5 * dp.back())
    {
        dp.push_back(1 + 5 * dp.back());
    }

    while (K > 0)
    {
        if (K == 5 * dp.back()) return 0;
        else
        {
            K = K % dp.back();
            dp.pop_back();
        }
    }
    return 5;
}

/// <summary>
/// Leet code #799. Champagne Tower
/// 
/// We stack glasses in a pyramid, where the first row has 1 glass, the 
/// second row has 2 glasses, and so on until the 100th row.  Each glass 
/// holds one cup (250ml) of champagne.
///
/// Then, some champagne is poured in the first glass at the top.  When 
/// the top most glass is full, any excess liquid poured will fall equally 
/// to the glass immediately to the left and right of it.  When those 
/// glasses become full, any excess champagne will fall equally to the left
/// and right of those glasses, and so on.  (A glass at the bottom row has 
/// it's excess champagne fall on the floor.)
///
/// For example, after one cup of champagne is poured, the top most glass 
/// is full.  After two cups of champagne are poured, the two glasses on 
/// the second row are half full.  After three cups of champagne are 
/// poured, those two cups become full - there are 3 full glasses total 
/// now.  After four cups of champagne are poured, the third row has the 
/// middle glass half full, and the two outside glasses are a quarter 
/// full, as pictured below.
///
/// Then, some champagne is poured in the first glass at the top.  When 
/// the top most glass is full, any excess liquid poured will fall equally 
/// to the glass immediately to the left and right of it.  When those 
/// glasses become full, any excess champagne will fall equally to the left 
/// and right of those glasses, and so on.  (A glass at the bottom row has 
/// it's excess champagne fall on the floor.)
///
/// For example, after one cup of champagne is poured, the top most glass 
/// is full.  After two cups of champagne are poured, the two glasses on 
/// the second row are half full.  After three cups of champagne are 
/// poured, those two cups become full - there are 3 full glasses total 
/// now.  After four cups of champagne are poured, the third row has the 
/// middle glass half full, and the two outside glasses are a quarter 
/// full, as pictured below.
///
/// Example 1:
/// Input: poured = 1, query_glass = 1, query_row = 1
/// Output: 0.0
/// Explanation: We poured 1 cup of champange to the top glass of the tower 
/// (which is indexed as (0, 0)). There will be no excess liquid so all the 
/// glasses under the top glass will remain empty.
///
/// Example 2:
/// Input: poured = 2, query_glass = 1, query_row = 1
/// Output: 0.5
/// Explanation: We poured 2 cups of champange to the top glass of the 
/// tower (which is indexed as (0, 0)). There is one cup of excess liquid. 
/// The glass indexed as (1, 0) and the glass indexed as (1, 1) will share 
/// the excess liquid equally, and each will get half cup of champange.
///
/// Now after pouring some non-negative integer cups of champagne, return 
/// how full the j-th glass in the i-th row is (both i and j are 0 indexed.)
///
/// Note:
/// 1. poured will be in the range of [0, 10 ^ 9].
/// 2. query_glass and query_row will be in the range of [0, 99].
/// </summary>
double LeetCodeDP::champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> dp(query_row + 1);
    for (size_t i = 0; i <= (size_t)query_row; i++)
    {
        dp[i] = vector<double>(i + 1, 0.0);
        for (size_t j = 0; j <= i && j <= (size_t)query_glass; j++)
        {
            if (i == 0) dp[i][j] = poured;
            else
            {
                if (j < i)
                {
                    dp[i][j] += (dp[i - 1][j] > 1) ? 0.5 * (dp[i - 1][j] - 1) : 0;
                }
                if (j > 0)
                {
                    dp[i][j] += (dp[i - 1][j - 1] > 1) ? 0.5 * (dp[i - 1][j - 1] - 1) : 0;
                }
            }
        }
    }
    return dp[query_row][query_glass] > 1 ? 1 : dp[query_row][query_glass];
}

/// <summary>
/// Leet code #801. Minimum Swaps To Make Sequences Increasing
/// 
/// We have two integer sequences A and B of the same non-zero length.
/// We are allowed to swap elements A[i] and B[i].  Note that both elements
/// are in the same index position in their respective sequences.
///
/// At the end of some number of swaps, A and B are both strictly 
/// increasing.  (A sequence is strictly increasing if and only if 
/// A[0] < A[1] < A[2] < ... < A[A.length - 1].)
///
/// Given A and B, return the minimum number of swaps to make both 
/// sequences strictly increasing.  It is guaranteed that the given 
/// input always makes it possible.
///
/// Example:
/// Input: A = [1,3,5,4], B = [1,2,3,7]
/// Output: 1
/// Explanation: 
/// Swap A[3] and B[3].  Then the sequences are:
/// A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
/// which are both strictly increasing.
/// Note:
///
/// 1. A, B are arrays with the same length, and that length will be in the 
///    range [1, 1000].
/// 2. A[i], B[i] are integer values in the range [0, 2000].
/// </summary>
int LeetCodeDP::minSwap(vector<int>& A, vector<int>& B)
{
    vector<int> no_swap_dp;
    vector<int> swap_dp;

    for (size_t i = 0; i < A.size(); i++)
    {
        if (i == 0)
        {
            no_swap_dp.push_back(0);
            swap_dp.push_back(1);
        }
        else
        {
            int no_swap = INT_MAX;
            int swap = INT_MAX;
            if (A[i - 1] < A[i] && B[i - 1] < B[i])
            {
                no_swap = no_swap_dp.back();
                swap = swap_dp.back() + 1;
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i])
            {
                no_swap = min(no_swap, swap_dp.back());
                swap = min(swap, no_swap_dp.back() + 1);
            }
            no_swap_dp.push_back(no_swap);
            swap_dp.push_back(swap);
        }
    }
    return min(no_swap_dp.back(), swap_dp.back());
}

/// <summary>
/// Leet code #808. Soup Servings
/// </summary>
double LeetCodeDP::soupServings(int A, int B, unordered_map<int, unordered_map<int, double>> &possibility)
{
    double result = 0;
    if (possibility.count(A) > 0 && possibility[A].count(B) > 0)
    {
        return possibility[A][B];
    }
    if ((A <= 0) && (A == B))
    {
        result = 0.5;
    }
    else if (A <= 0 && A < B)
    {
        result = 1;
    }
    else if (B <= 0)
    {
        result = 0;
    }
    else
    {
        result = soupServings(A - 4, B, possibility);
        result += soupServings(A - 3, B - 1, possibility);
        result += soupServings(A - 2, B - 2, possibility);
        result += soupServings(A - 1, B - 3, possibility);
        result = 0.25 * result;
    }
    possibility[A][B] = result;
    return result;
}

/// <summary>
/// Leet code #808. Soup Servings
/// 
/// There are two types of soup: type A and type B. Initially we have N ml
/// of each type of soup. There are four kinds of operations:
///
/// Serve 100 ml of soup A and 0 ml of soup B
/// Serve 75 ml of soup A and 25 ml of soup B
/// Serve 50 ml of soup A and 50 ml of soup B
/// Serve 25 ml of soup A and 75 ml of soup B
/// When we serve some soup, we give it to someone and we no longer have 
/// it.  Each turn, we will choose from the four operations with equal 
/// probability 0.25. If the remaining volume of soup is not enough to 
/// complete the operation, we will serve as much as we can.  We stop 
/// once we no longer have some quantity of both types of soup.
///
/// Note that we do not have the operation where all 100 ml's of soup B are 
/// used first.  
///
/// Return the probability that soup A will be empty first, plus half the 
/// probability that A and B become empty at the same time.
///  
/// Example:
/// Input: N = 50
/// Output: 0.625
/// Explanation: 
/// If we choose the first two operations, A will become empty first. For 
/// the third operation, A and B will become empty at the same time. For 
/// the fourth operation, B will become empty first. So the total 
/// probability of A becoming empty first plus half the probability that A 
/// and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 
/// 0.625.
/// Notes:
/// 1. 0 <= N <= 10^9. 
/// 2. Answers within 10^-6 of the true value will be accepted as correct.
/// </summary>
double LeetCodeDP::soupServings(int N)
{
    N = (int)ceil(N / 25.0);
    unordered_map<int, unordered_map<int, double>> possibility;

    for (int n = 0; n <= N; n++)
    {
        for (int i = 0; i <= n; i++)
        {
            int start = 0;
            int end = 0;
            if (i == n)
            {
                start = 0; end = n;
            }
            else
            {
                start = n; end = n;
            }
            for (int j = start; j <= end; j++)
            {
                soupServings(i, j, possibility);
            }
            if (abs(possibility[n][n] - 1.0) < 0.000001) return possibility[n][n];
        }
    }
    return possibility[N][N];
}

/// <summary>
/// Leet code #813. Largest Sum of Averages
/// 
/// We partition a row of numbers A into at most K adjacent (non-empty) 
/// groups, then our score is the sum of the average of each group. 
/// What is the largest score we can achieve?
///
/// Note that our partition must use every number in A, and that scores 
/// are not necessarily integers.
///
/// Example:
/// Input: 
/// A = [9,1,2,3,9]
/// K = 3
/// Output: 20
/// Explanation: 
/// The best choice is to partition A into [9], [1, 2, 3], [9]. The 
/// answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
/// We could have also partitioned A into [9, 1], [2], [3, 9], for example.
/// That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
///
/// Note:
/// 1. 1 <= A.length <= 100.
/// 2. 1 <= A[i] <= 10000.
/// 3. 1 <= K <= A.length.
/// 4. Answers within 10^-6 of the correct answer will be accepted as 
///    correct.
/// </summary>
double LeetCodeDP::largestSumOfAverages(vector<int>& A, int K)
{
    vector<vector<double>> dp(K, vector<double>(A.size()));
    vector<double> sum(A.size());

    for (size_t i = 0; i < A.size(); i++)
    {
        if (i == 0) sum[i] = A[i];
        else sum[i] = sum[i - 1] + A[i];
    }

    for (size_t i = 0; i < (size_t)K; i++)
    {
        for (size_t j = 0; j < A.size(); j++)
        {
            if (i == 0) dp[i][j] = (double)sum[j] / ((double)j + 1);
            else
            {
                for (size_t k = 0; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + (sum[j] - sum[k]) / (j - k));
                }
            }
        }
    }
    return dp[K - 1][A.size() - 1];
}

/// <summary>
/// Leet code #823. Binary Trees With Factors
/// 
/// Given an array of unique integers, each integer is strictly greater 
/// than 1.
///
/// We make a binary tree using these integers and each number may be used 
/// for any number of times.
///
/// Each non-leaf node's value should be equal to the product of the 
/// values of it's children.
///
/// How many binary trees can we make?  Return the answer modulo 
/// 10 ** 9 + 7.
/// 
/// Example 1:
///
/// Input: A = [2, 4]
/// Output: 3
/// Explanation: We can make these trees: [2], [4], [4, 2, 2]
///  
/// Example 2:
///
/// Input: A = [2, 4, 5, 10]
/// Output: 7
/// Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], 
/// [10, 2, 5], [10, 5, 2].
/// 
/// Note:
/// 1. 1 <= A.length <= 1000.
/// 2. 2 <= A[i] <= 10 ^ 9.
/// </summary>
int LeetCodeDP::numFactoredBinaryTrees(vector<int>& A)
{
    sort(A.begin(), A.end());
    unordered_map<int, unsigned long long> dp;
    unsigned long long mod = 1000000007;
    for (size_t i = 0; i < A.size(); i++)
    {
        dp[A[i]] = 1;
        for (size_t j = 0; j < i; j++)
        {
            if (A[i] % A[j] != 0) continue;
            int d = A[i] / A[j];
            if (dp.count(d) > 0)
            {
                dp[A[i]] += (dp[A[j]] * dp[d]);
                dp[A[i]] %= mod;
            }
        }
    }

    unsigned long long result = 0;
    for (const auto& itr : dp)
    {
        result += itr.second;
        result %= mod;
    }
    return (int)result;
}

/// <summary>
/// Leet code #828. Unique Letter String
/// 
/// A character is unique in string S if it occurs exactly once in it.
///
/// For example, in string S = "LETTER", the only unique characters are 
/// "L" and "R".
///
/// Let's define UNIQ(S) as the number of unique characters in string S.
///
/// For example, UNIQ("LETTER") =  2.
///
/// Given a string S with only uppercases, calculate the sum of 
/// UNIQ(substring) over all non-empty substrings of S.
///
/// If there are two or more equal substrings at different positions in S, 
/// we consider them different.
///
/// Since the answer can be very large, retrun the answer modulo 
/// 10 ^ 9 + 7.
///
/// Example 1:
/// Input: "ABC"
/// Output: 10
/// Explanation: All possible substrings are: "A","B","C","AB","BC" and 
/// "ABC".
/// Evey substring is composed with only unique letters.
/// Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
///
/// Example 2:
/// Input: "ABA"
/// Output: 8
/// Explanation: The same as example 1, except uni("ABA") = 1.
///
/// Note: 0 <= S.length <= 10000.
/// </summary>
int LeetCodeDP::uniqueLetterString(string S)
{
    int mod = 1000000007;
    vector<int> prev_one(26, -1);
    vector<int> prev_two(26, -1);
    vector<int> dp(S.size());

    for (size_t i = 0; i < S.size(); i++)
    {
        int index = S[i] - 'A';
        if (i == 0)
        {
            dp[0] = 1;
        }
        else
        {
            dp[i] = dp[i - 1];
            // from current to last such character position
            dp[i] += (i - prev_one[index]);
            dp[i] %= mod;
            // from last character to previous one
            dp[i] -= (prev_one[index] - prev_two[index]);
            dp[i] += mod;
            dp[i] %= mod;
        }
        // shift position memory
        prev_two[index] = prev_one[index];
        prev_one[index] = i;
    }
    int result = 0;
    for (size_t i = 0; i < dp.size(); i++)
    {
        result += dp[i];
        result %= mod;
    }
    return result;
}

/// <summary>
/// Leet code #834. Sum of Distances in Tree
/// </summary>
void LeetCodeDP::calcuateChildrenDistance(int root, int parent, vector<vector<int>> &tree,
    unordered_map<int, pair<int, int>> &tree_stat)
{
    // node count
    tree_stat[root].first = 1;
    // distance
    tree_stat[root].second = 0;

    for (size_t i = 0; i < tree[root].size(); i++)
    {
        int child = tree[root][i];
        if (child != parent)
        {
            calcuateChildrenDistance(child, root, tree, tree_stat);
            tree_stat[root].first += tree_stat[child].first;
            tree_stat[root].second += tree_stat[child].second + tree_stat[child].first;
        }
    }
}

/// <summary>
/// Leet code #834. Sum of Distances in Tree
/// </summary>
void LeetCodeDP::calcuateAllDistance(int root, int parent, vector<vector<int>> &tree, unordered_map<int, pair<int, int>> &tree_stat)
{
    for (size_t i = 0; i < tree[root].size(); i++)
    {
        int child = tree[root][i];
        if (child != parent)
        {
            tree_stat[child].second = tree_stat[root].second + tree.size() - 2 * tree_stat[child].first;
            calcuateAllDistance(child, root, tree, tree_stat);
        }
    }
}

/// <summary>
/// Leet code #834. Sum of Distances in Tree
/// 
/// An undirected, connected tree with N nodes labelled 0...N-1 and N-1 
/// edges are given.
///
/// The ith edge connects nodes edges[i][0] and edges[i][1] together.
///
/// Return a list ans, where ans[i] is the sum of the distances between 
/// node i and all other nodes.
///
/// Example 1:
///
/// Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
/// Output: [8,12,6,10,10,10]
/// Explanation: 
/// Here is a diagram of the given tree:
///   0
///  / \
/// 1   2
///    /|\
///   3 4 5
/// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + 
/// dist(0,5)
/// equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
/// Note: 1 <= N <= 10000
/// </summary>
vector<int> LeetCodeDP::sumOfDistancesInTree(int N, vector<vector<int>>& edges)
{
    vector<int> result(N);
    vector<vector<int>> tree(N);
    unordered_map<int, pair<int, int>> tree_stat;
    vector<int> parent(N, -1);

    for (size_t i = 0; i < edges.size(); i++)
    {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    calcuateChildrenDistance(0, -1, tree, tree_stat);
    calcuateAllDistance(0, -1, tree, tree_stat);
    for (int i = 0; i < N; i++)
    {
        result[i] = tree_stat[i].second;
    }
    return result;
}

/// <summary>
/// Leet code #837. New 21 Game
/// 
/// Alice plays the following game, loosely based on the card game "21".
///
/// Alice starts with 0 points, and draws numbers while she has less than 
/// K points.  During each draw, she gains an integer number of points 
/// randomly from the range [1, W], where W is an integer.  Each draw is 
/// independent and the outcomes have equal probabilities.
///
/// Alice stops drawing numbers when she gets K or more points.  What is 
/// the probability that she has N or less points?
///
/// Example 1:
///
/// Input: N = 10, K = 1, W = 10
/// Output: 1.00000
/// Explanation:  Alice gets a single card, then stops.
///
/// Example 2:
///
/// Input: N = 6, K = 1, W = 10
/// Output: 0.60000
/// Explanation:  Alice gets a single card, then stops.
/// In 6 out of W = 10 possibilities, she is at or below N = 6 points.
/// Example 3:
///
/// Input: N = 21, K = 17, W = 10
/// Output: 0.73278
/// Note:
///
/// 1. 0 <= K <= N <= 10000
/// 2. 1 <= W <= 10000
/// 3. Answers will be accepted as correct if they are within 10^-5 of 
///    the correct answer.
/// 4. The judging time limit has been reduced for this question.
/// </summary>
double LeetCodeDP::new21Game(int N, int K, int W)
{
    vector<double> dp(N+1);
    dp[0] = 1.0;
    double sum = 0;
    double result = 0;
    if (K == 0) return 1.0;
    // for any dp[i], it can be either built from dp[0]/W or dp[x] /W, where i - W < x < K.
    for (int i = 1; i <= N; i++)
    {
        if (i <= K) sum += dp[i - 1];
        dp[i] = sum / W;
        if (i >= K) result += dp[i];
        if (i >= W) sum -= dp[i - W];
    }
    return result;
}

/// <summary>
/// Leet code #873. Length of Longest Fibonacci Subsequence
/// 
/// A sequence X_1, X_2, ..., X_n is fibonacci-like if:
///
/// n >= 3
/// X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
/// Given a strictly increasing array A of positive integers forming a 
/// sequence, find the length of the longest fibonacci-like subsequence 
/// of A.  If one does not exist, return 0.
///
/// (Recall that a subsequence is derived from another sequence A by 
/// deleting any number of elements (including none) from A, without 
/// changing the order of the remaining elements.  For example, 
/// [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)
/// 
/// Example 1:
/// Input: [1,2,3,4,5,6,7,8]
/// Output: 5
/// Explanation:
/// The longest subsequence that is fibonacci-like: [1,2,3,5,8].
///
/// Example 2:
/// Input: [1,3,7,11,12,14,18]
/// Output: 3
/// Explanation:
/// The longest subsequence that is fibonacci-like:
/// [1,11,12], [3,11,14] or [7,11,18].
///
/// Note:
/// 
/// 1. 3 <= A.length <= 1000
/// 2. 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9	/// </summary>
/// </summary>
int LeetCodeDP::lenLongestFibSubseq(vector<int>& A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 2));
    unordered_map<int, int> num_map;
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        num_map[A[i]] = i;
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = i + 1; j < A.size(); j++)
        {
            int sum = A[i] + A[j];
            if (num_map.count(sum) > 0)
            {
                dp[j][num_map[sum]] = dp[i][j] + 1;
                result = max(result, dp[j][num_map[sum]]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #877. Stone Game
/// 
/// Alex and Lee play a game with piles of stones.  There are an even 
/// number of piles arranged in a row, and each pile has a positive 
/// integer number of stones piles[i].
///
/// The objective of the game is to end with the most stones.  The 
/// total number of stones is odd, so there are no ties.
///
/// Alex and Lee take turns, with Alex starting first.  Each turn, 
/// a player takes the entire pile of stones from either the beginning 
/// or the end of the row.  This continues until there are no more piles 
/// left, at which point the person with the most stones wins.
///
/// Assuming Alex and Lee play optimally, return True if and only if Alex 
/// wins the game.
///
/// Example 1:
/// Input: [5,3,4,5]
/// Output: true
/// Explanation: 
/// Alex starts first, and can only take the first 5 or the last 5.
/// Say he takes the first 5, so that the row becomes [3, 4, 5].
/// If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win 
/// with 10 points.
/// If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 
/// to win with 9 points.
/// This demonstrated that taking the first 5 was a winning move for 
/// Alex, so we return true.
/// 
/// Note:
/// 1. 2 <= piles.length <= 500
/// 2. piles.length is even.
/// 3. 1 <= piles[i] <= 500
/// 4. sum(piles) is odd.
/// </summary>
bool LeetCodeDP::stoneGame(vector<int>& piles)
{
    size_t size = piles.size();
    vector<vector<int>> dp(size, vector<int>(size));
    for (size_t k = 0; k < size; k++)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (k == 0)
            {
                dp[i][i] = piles[i];
            }
            else
            {
                if (i + k >= size) break;
                dp[i][i + k] = max(piles[i] - dp[i + 1][i + k], piles[i+k] - dp[i][i+k-1]);
            }
        }
    }
    return (dp[0][size - 1] > 0);
}

/// <summary>
/// Leet code #887. Super Egg Drop
/// 
/// You are given K eggs, and you have access to a building with N floors from 
/// 1 to N. 
///
/// Each egg is identical in function, and if an egg breaks, you cannot drop 
/// it again.
///
/// You know that there exists a floor F with 0 <= F <= N such that any egg 
/// dropped at a floor higher than F will break, and any egg dropped at or 
/// below floor F will not break.
///
/// Each move, you may take an egg (if you have an unbroken one) and drop it 
/// from any floor X (with 1 <= X <= N). 
///
/// Your goal is to know with certainty what the value of F is.
///
/// What is the minimum number of moves that you need to know with certainty 
/// what F is, regardless of the initial value of F?
///
/// Example 1:
///
/// Input: K = 1, N = 2
/// Output: 2
/// Explanation: 
/// Drop the egg from floor 1.  If it breaks, we know with certainty that 
/// F = 0.
/// Otherwise, drop the egg from floor 2.  If it breaks, we know with 
/// certainty that F = 1.
/// If it didn't break, then we know with certainty F = 2.
/// Hence, we needed 2 moves in the worst case to know what F is with 
/// certainty.
///
/// Example 2:
/// Input: K = 2, N = 6
/// Output: 3
///
/// Example 3
/// Input: K = 3, N = 14
/// Output: 4
/// Note:
/// 1 <= K <= 100
/// 1 <= N <= 10000
/// </summary>
int LeetCodeDP::superEggDrop(int K, int N)
{
    vector<vector<int>> dp;
    int result = 0;
    while (true)
    {
        dp.push_back(vector<int>(K));
        for (int k = 0; k < K; k ++)
        {
            if (k == 0) dp[result][k] = result + 1;
            else if (result == 0)
            {
                dp[result][k] = 1;
            }
            else
            {
                dp[result][k] = 1 + dp[result - 1][k] + dp[result - 1][k - 1];
            }
            if (dp[result][k] >= N) return result + 1;
        }
        result++;
    }
}

/// <summary>
/// Leet code #880. Decoded String at Index
/// 
/// An encoded string S is given.  To find and write the decoded string to a 
/// tape, the encoded string is read one character at a time and the following 
/// steps are taken:
///
/// If the character read is a letter, that letter is written onto the tape.
/// If the character read is a digit (say d), the entire current tape is 
/// repeatedly written d-1 more times in total.
/// Now for some encoded string S, and an index K, find and return the K-th 
/// letter (1 indexed) in the decoded string.
///
/// Example 1:
/// Input: S = "leet2code3", K = 10
/// Output: "o"
/// Explanation: 
/// The decoded string is "leetleetcodeleetleetcodeleetleetcode".
/// The 10th letter in the string is "o".
///
/// Example 2:
/// Input: S = "ha22", K = 5
/// Output: "h"
/// Explanation: 
/// The decoded string is "hahahaha".  The 5th letter is "h".
///
/// Example 3:
/// Input: S = "a2345678999999999999999", K = 1
/// Output: "a"
/// Explanation: 
/// The decoded string is "a" repeated 8301530446056247680 times.  The 1st 
/// letter is "a".
/// 
/// Note:
/// 1. 2 <= S.length <= 100
/// 2. S will only contain lowercase letters and digits 2 through 9.
/// 3. S starts with a letter.
/// 4. 1 <= K <= 10^9
/// 5. The decoded string is guaranteed to have less than 2^63 letters.
/// </summary>
string LeetCodeDP::decodeAtIndex(string S, int K)
{
    stack<vector<long long>> sub_count;
    stack<string> sub_strings;
    long long str_len = 0;
    string token;
    int index = K - 1;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (isdigit(S[i]))
        {
            vector<long long> sub_lens;
            long long delta = (long long)S[i] - '0';
            if (token.empty())
            {
                sub_lens = sub_count.top();
                sub_count.pop();
                sub_lens[1] *= delta;
                sub_count.push(sub_lens);
            }
            else
            {
                sub_lens = { str_len, delta };
                sub_count.push(sub_lens);
                sub_strings.push(token);
                token.clear();
            }
            str_len *= delta;
        }
        else
        {
            str_len++;
            token.push_back(S[i]);
        }
        if (str_len > (long long)index)
        {
            if (!token.empty())
            {
                sub_strings.push(token);
                sub_count.push({str_len, 1});
            }
            break;
        }
    }
    string result;
    while (!sub_count.empty())
    {
        vector<long long> sub_lens = sub_count.top();
        sub_count.pop();
        string sub_str = sub_strings.top();
        sub_strings.pop();
        index %= sub_lens[0];
        if (index >= sub_lens[0] - sub_str.size())
        {
            result.push_back(sub_str[sub_str.size() - (int)(sub_lens[0] - index)]);
            return result;
        }
    }
    return result;
}

/// <summary>
/// Leet code #898. Bitwise ORs of Subarrays 
/// 
/// We have an array A of non-negative integers.
///
/// For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] 
/// (with i <= j), we take the bitwise OR of all the elements in B, 
/// obtaining a result A[i] | A[i+1] | ... | A[j].
///
/// Return the number of possible results.  (Results that occur more 
/// than once are only counted once in the final answer.)
///
/// Example 1:
/// Input: [0]
/// Output: 1
/// Explanation: 
/// There is only one possible result: 0.
///
/// Example 2:
/// Input: [1,1,2]
/// Output: 3
/// Explanation: 
/// The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
/// These yield the results 1, 1, 2, 1, 3, 3.
/// There are 3 unique values, so the answer is 3.
/// Example 3:
///
/// Input: [1,2,4]
/// Output: 6
/// Explanation: 
/// The possible results are 1, 2, 3, 4, 6, and 7.
///  
/// Note:
/// 
/// 1. 1 <= A.length <= 50000
/// 2. 0 <= A[i] <= 10^9
/// </summary>
int LeetCodeDP::subarrayBitwiseORs(vector<int>& A)
{
    unordered_set<int> next, result;
    for (size_t i = 0; i < A.size(); i++)
    {
        unordered_set<int> current = next;
        next.clear();
        if (i == 0)
        {
            next.insert(A[0]);
        }
        else
        {
            next.insert(A[i]);
            for (auto x : current)
            {
                next.insert(A[i] | x);
            }
        }
        result.insert(next.begin(), next.end());
    }
    return result.size();
}

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
int LeetCodeDP::atMostNGivenDigitSet(vector<string>& D, int N)
{
    int result = 0;
    if (D.empty()) return result;
    long long product = 10;
    vector<int> dp;
    dp.push_back(1);
    while (product <= N)
    {
        dp.push_back(dp.back() * D.size());
        result += dp.back();
        product *= 10;
    }

    vector<string> number;
    while (N > 0)
    {
        number.push_back(to_string(N % 10));
        N /= 10;
    }
    int one = 1;
    while (!number.empty())
    {
        string n = number.back();
        auto itr = lower_bound(D.begin(), D.end(), n);
        if (itr == D.end())
        {
            result += D.size() * dp.back();
        }
        else
        {
            result += (itr - D.begin()) * dp.back();
        }
        if (itr == D.end() || (*itr != n))
        {
            one = 0;
            break;
        }
        number.pop_back();
        dp.pop_back();
    }
    result += one;
    return result;
}

/// <summary>
/// Leet code #903. Valid Permutations for DI Sequence
/// 
/// We are given S, a length n string of characters from the set {'D', 'I'}. 
/// (These letters stand for "decreasing" and "increasing".)
///
/// A valid permutation is a permutation P[0], P[1], ..., P[n] of integers 
/// {0, 1, ..., n}, such that for all i:
///
/// If S[i] == 'D', then P[i] > P[i+1], and;
/// If S[i] == 'I', then P[i] < P[i+1].
/// How many valid permutations are there?  Since the answer may be large, 
/// return your answer modulo 10^9 + 7.
///
/// Example 1:
/// Input: "DID"
/// Output: 5
/// Explanation: 
/// The 5 valid permutations of (0, 1, 2, 3) are:
/// (1, 0, 3, 2)
/// (2, 0, 3, 1)
/// (2, 1, 3, 0)
/// (3, 0, 2, 1)
/// (3, 1, 2, 0)
/// 
/// Note:
/// 1. 1 <= S.length <= 200
/// 2. S consists only of characters from the set {'D', 'I'}.
/// </summary>
int LeetCodeDP::numPermsDISequence(string S)
{
    size_t M = 1000000007;
    vector<vector<int>> dp;
    int n = S.size() + 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp.push_back(vector<int>(n, 1));
            continue;
        }
        else
        {
            dp.push_back(vector<int>(n, 0));
            int sum = 0;
            if (S[i - 1] == 'I')
            {
                for (int j = 0; j < n - i; j++)
                {
                    dp[i][j] += sum + dp[i - 1][j];
                    sum += dp[i - 1][j];
                    dp[i][j] %= M;
                    sum %= M;
                }
            }
            else
            {
                for (int j = n - i - 1; j >= 0; j--)
                {
                    dp[i][j] += sum + dp[i - 1][j + 1];
                    sum += dp[i - 1][j + 1];
                    dp[i][j] %= M;
                    sum %= M;
                }
            }
        }
    }
    return dp[n - 1][0];
}

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
int LeetCodeDP::numMusicPlaylists(int N, int L, int K)
{
    size_t M = 1000000007;
    vector<vector<long long>> dp(L + 1, vector<long long>(N + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] += dp[i - 1][j - 1] * j % M;
            dp[i][j] += dp[i - 1][j] * max(j-K, 0) % M;
        }
    }
    int result = (int)dp[L][N];
    return result;
}


/// <summary>
/// Leet code #931. Minimum Falling Path Sum
/// 
/// Given a square array of integers A, we want the minimum sum of a falling 
/// path through A.
///
/// A falling path starts at any element in the first row, and chooses one 
/// element from each row.  The next row's choice must be in a column that is 
/// different from the previous row's column by at most one.
/// 
/// Example 1:
///
/// Input: [[1,2,3],[4,5,6],[7,8,9]]
/// Output: 12
/// Explanation: 
/// The possible falling paths are:
/// [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
/// [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
/// [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
/// The falling path with the smallest sum is [1,4,7], so the answer is 12.
///
/// Note:
/// 1. 1 <= A.length == A[0].length <= 100
/// 2. -100 <= A[i][j] <= 100
/// </summary>
int LeetCodeDP::minFallingPathSum(vector<vector<int>>& A)
{
    vector<int> prev(A.size());
    for (int i = 0; i < (int)A.size(); i++)
    {
        vector<int> curr(A.size(), INT_MAX);
        for (int j = 0; j < (int)A[i].size(); j++)
        {
            for (int k = j - 1; k < j + 2; k++)
            {
                if (k < 0 || k >=(int)A[i].size()) continue;
                {
                    curr[j] = min(curr[j], A[i][j] + prev[k]);
                }
            }
        }
        prev = curr;
    }

    int result = INT_MAX;
    for (size_t i = 0; i < prev.size(); i++) result = min(result, prev[i]);
    
    return result;
}

/// <summary>
/// Leet code #935. Knight Dialer
/// 
/// A chess knight can move as indicated in the chess diagram below:
///
/// This time, we place our chess knight on any numbered key of a phone pad 
/// (indicated above), and the knight makes N-1 hops.  Each hop must be from 
/// one key to another numbered key.
///
/// Each time it lands on a key (including the initial placement of the 
/// knight), it presses the number of that key, pressing N digits total.
///
/// How many distinct numbers can you dial in this manner?
///
/// Since the answer may be large, output the answer modulo 10^9 + 7.
///
/// Example 1:
/// Input: 1
/// Output: 10
///
/// Example 2:
/// Input: 2
/// Output: 20
///
/// Example 3:
/// Input: 3
/// Output: 46
/// Note:
/// 
/// 1 <= N <= 5000
/// </summary>
int LeetCodeDP::knightDialer(int N)
{
    int M = 1000000007;
    vector<vector<int>> key_jump =
    {
        {4, 6}, 
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    vector<int> current(10, 1);
    for (int i = 1; i < N; i++)
    {
        vector<int> next(10);
        for (size_t j = 0; j < 10; j++)
        {
            for (auto k : key_jump[j])
            {
                next[k] = (next[k] + current[j]) % M;
            }
        }
        current = next;
    }

    int result = 0;
    for (size_t i = 0; i < 10; i++)
    {
        result = (result + current[i]) % M;
    }
    return result;
}

/// <summary>
/// Leet code #940. Distinct Subsequences II
/// 
/// Given a string S, count the number of distinct, non-empty subsequences of 
/// S.
///
/// Since the result may be large, return the answer modulo 10^9 + 7.
///
/// Example 1:
/// Input: "abc"
/// Output: 7
/// Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", 
/// "bc", and "abc".
///
/// Example 2:
/// Input: "aba"
/// Output: 6
/// Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" 
/// and "aba".
///
/// Example 3:
/// 
/// Input: "aaa"
/// Output: 3
/// Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
///  
/// Note:
///
/// 1. S contains only lowercase letters.
/// 2. 1 <= S.length <= 2000
/// </summary>
int LeetCodeDP::distinctSubseqII(string S)
{
    int M = 1000000007;
    vector<int> dp(S.size()), sum(S.size());
    vector<int> pos(26, -1);

    for (size_t i = 0; i < S.size(); i++)
    {
        if (i == 0)
        {
            dp[i] = 1;
            sum[i] = 1;
        }
        else
        {
            if (pos[S[i] - 'a'] == -1)
            {
                dp[i] = (sum[i - 1] + 1) % M;
                sum[i] = (sum[i - 1] + dp[i]) % M;
            }
            else
            {
                int prev_index = pos[S[i] - 'a'];
                int prev_sum = (prev_index == 0) ? 0 : sum[prev_index - 1];
                dp[i] = (sum[i - 1]  - prev_sum + M) % M;
                sum[i] = (sum[i - 1] + dp[i]) % M;
            }
        }
        pos[S[i] - 'a'] = i;
    }
    return sum[S.size() - 1];
}

/// <summary>
/// Leet code #956. Tallest Billboard
/// 
/// You are installing a billboard and want it to have the largest height.
/// The billboard will have two steel supports, one on each side.  
/// Each steel support must be an equal height.
/// You have a collection of rods which can be welded together.  
/// For example, if you have rods of lengths 1, 2, and 3, you can weld 
/// them together to make a support of length 6.
///
/// Return the largest possible height of your billboard installation.  
/// If you cannot support the billboard, return 0.
///
/// 
/// Example 1:
/// Input: [1,2,3,6]
/// Output: 6
/// Explanation: We have two disjoint subsets {1,2,3} and {6}, which have 
/// the same sum = 6.
///
/// Example 2:
/// Input: [1,2,3,4,5,6]
/// Output: 10
/// Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which 
/// have the same sum = 10.
///
/// Example 3:
/// Input: [1,2]
/// Output: 0
/// Explanation: The billboard cannot be supported, so we return 0.
///
/// Note:
/// 1. 0 <= rods.length <= 20
/// 2. 1 <= rods[i] <= 1000
/// 3. The sum of rods is at most 5000.
/// </summary>
int LeetCodeDP::tallestBillboard(vector<int>& rods)
{
    int sum = 0;
    for (auto r : rods) sum += r;
    unordered_map<int, int> curr_map;
    unordered_map<int, int> next_map;
    next_map[0] = 0;
    for (size_t i = 0; i < rods.size(); i++)
    {
        curr_map = next_map;
        for (int j = -1; j < 2; j+=2)
        {
            int rod = j* rods[i];
            for (auto& itr : curr_map)
            {
                int new_sum = itr.first + rod;
                if (new_sum < -sum / 2 || new_sum > sum / 2) continue;
                if (j > 0)
                {
                    next_map[new_sum] = max(next_map[new_sum], curr_map[itr.first] + rod);
                }
                else
                {
                    next_map[new_sum] = max(next_map[new_sum], curr_map[itr.first]);
                }
            }
        }
    }
    return next_map[0];
}

/// <summary>
/// Leet code #960. Delete Columns to Make Sorted III
/// 
/// We are given an array A of N lowercase letter strings, all of the same 
/// length.
///
/// Now, we may choose any set of deletion indices, and for each string, we 
/// delete all the characters in those indices.
///
/// For example, if we have an array A = ["babca","bbazb"] and deletion 
/// indices {0, 1, 4}, then the final array after deletions is ["bc","az"].
///
/// Suppose we chose a set of deletion indices D such that after deletions, 
/// the final array has every element (row) in lexicographic order.
///
/// For clarity, A[0] is in lexicographic order 
/// (ie. A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]), A[1] is in 
/// lexicographic order (ie. A[1][0] <= A[1][1] <= ... <= 
/// A[1][A[1].length - 1]), and so on.
///
/// Return the minimum possible value of D.length.
///
/// Example 1:
/// Input: ["babca","bbazb"]
/// Output: 3
/// Explanation: After deleting columns 0, 1, and 4, the final array is 
/// A = ["bc", "az"].
/// Both these rows are individually in lexicographic order 
/// (ie. A[0][0] <= A[0][1] and A[1][0] <= A[1][1]).
/// Note that A[0] > A[1] - the array A isn't necessarily in lexicographic 
/// order.
///
/// Example 2:
/// Input: ["edcba"]
/// Output: 4
/// Explanation: If we delete less than 4 columns, the only row won't be 
/// lexicographically sorted.
///
/// Example 3:
/// Input: ["ghi","def","abc"]
/// Output: 0
/// Explanation: All rows are already lexicographically sorted.
/// 
///
/// Note:
/// 
/// 1. 1 <= A.length <= 100
/// 2. 1 <= A[i].length <= 100
/// </summary>
int LeetCodeDP::minDeletionSizeIII(vector<string>& A)
{
    // remeber with column i, what is the longest sequence.
    vector<int> dp(A[0].size());
    for (size_t i = 0; i < A[0].size(); i++)
    {
        unordered_set<int> ordered_columns;
        // assume all columns are in order for column i;
        for (size_t j = 0; j < i; j++) ordered_columns.insert(j);
        for (size_t j = 0; j < A.size(); j++)
        {
            auto itr = ordered_columns.begin();
            while (itr != ordered_columns.end())
            {
                auto temp = itr;
                itr++;
                // violation column, delete it.
                if (A[j][*temp] > A[j][i])
                {
                    ordered_columns.erase(temp);
                }
            }
        }
        // choose the longest sequence.
        for (auto col : ordered_columns) dp[i] = max(dp[i], dp[col]);
        dp[i]++;
    }
    int result = 0;
    for (size_t i = 0; i < dp.size(); i++) result = max(result, dp[i]);
    return A[0].size() - result;
}



/// <summary>
/// Leet code #975. Odd Even Jump
/// 
/// You are given an integer array A.  From some starting index, you can make 
/// a series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are 
/// called odd numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the 
/// series are called even numbered jumps.
///
/// You may from index i jump forward to index j (with i < j) in the following 
/// way:
///
/// During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index 
/// j such that A[i] <= A[j] and A[j] is the smallest possible value.  If there 
/// are multiple such indexes j, you can only jump to the smallest such 
/// index j.
/// During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index 
/// j such that A[i] >= A[j] and A[j] is the largest possible value.  If there 
/// are multiple such indexes j, you can only jump to the smallest such 
/// index j. 
/// (It may be the case that for some index i, there are no legal jumps.)
/// A starting index is good if, starting from that index, you can reach the 
/// end of the array (index A.length - 1) by jumping some number of times 
/// (possibly 0 or more than once.)
///
/// Return the number of good starting indexes.
///
/// Example 1:
///
/// Input: [10,13,12,14,15]
/// Output: 2
/// Explanation: 
/// From starting index i = 0, we can jump to i = 2 (since A[2] is the 
/// smallest among A[1], A[2], A[3], A[4] that is greater or equal to A[0]), 
/// then we can't jump any more.
/// From starting index i = 1 and i = 2, we can jump to i = 3, then we can't 
/// jump any more.
/// From starting index i = 3, we can jump to i = 4, so we've reached the end.
/// From starting index i = 4, we've reached the end already.
/// In total, there are 2 different starting indexes (i = 3, i = 4) where we 
/// can reach the end with some number of jumps.
///
/// Example 2:
/// 
/// Input: [2,3,1,1,4]
/// Output: 3
/// Explanation: 
/// From starting index i = 0, we make jumps to i = 1, i = 2, i = 3:
///
/// During our 1st jump (odd numbered), we first jump to i = 1 because A[1] 
/// is the smallest value in (A[1], A[2], A[3], A[4]) that is greater than 
/// or equal to A[0].
///
/// During our 2nd jump (even numbered), we jump from i = 1 to i = 2 because 
/// A[2] is the largest value in (A[2], A[3], A[4]) that is less than or equal 
/// to A[1].  A[3] is also the largest value, but 2 is a smaller index, so we 
/// can only jump to i = 2 and not i = 3.
///
/// During our 3rd jump (odd numbered), we jump from i = 2 to i = 3 because 
/// A[3] is the smallest value in (A[3], A[4]) that is greater than or equal to
/// A[2].
///
/// We can't jump from i = 3 to i = 4, so the starting index i = 0 is not good.
///
/// In a similar manner, we can deduce that:
/// From starting index i = 1, we jump to i = 4, so we reach the end.
/// From starting index i = 2, we jump to i = 3, and then we can't jump 
/// anymore.
/// From starting index i = 3, we jump to i = 4, so we reach the end.
/// From starting index i = 4, we are already at the end.
/// In total, there are 3 different starting indexes (i = 1, i = 3, i = 4) 
/// where we can reach the end with some number of jumps.
///
/// Example 3:
/// 
/// Input: [5,1,3,4,2]
/// Output: 3
/// Explanation: 
/// We can reach the end from starting indexes 1, 2, and 4.
///
/// Note:
///
/// 1. 1 <= A.length <= 20000
/// 2. 0 <= A[i] < 100000
/// </summary>
int LeetCodeDP::oddEvenJumps(vector<int>& A)
{
    vector<vector<int>> dp(A.size(), vector<int>(2));
    vector<pair<int, int>> num_list;
    vector<int> odd_next(A.size()), even_next(A.size());
    stack<int> num_stack;
    for (size_t i = 0; i < A.size(); i++)
    {
        num_list.push_back(make_pair(A[i], i));
    }
    sort(num_list.begin(), num_list.end());

    for (size_t i = 0; i < num_list.size(); i++)
    {
        int index = num_list[i].second;
        while (!num_stack.empty())
        {
            if (num_stack.top() > index) break;
            odd_next[num_stack.top()] = index;
            num_stack.pop();
        }
        num_stack.push(index);
    }
    num_list.clear();
    num_stack = stack<int>();
    for (size_t i = 0; i < A.size(); i++)
    {
        num_list.push_back(make_pair(-A[i], i));
    }
    sort(num_list.begin(), num_list.end());

    for (size_t i = 0; i < num_list.size(); i++)
    {
        int index = num_list[i].second;
        while (!num_stack.empty())
        {
            if (num_stack.top() > index) break;
            even_next[num_stack.top()] = index;
            num_stack.pop();
        }
        num_stack.push(index);
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        dp[i][0]++;
        if (odd_next[i] > (int)i) dp[odd_next[i]][1] += dp[i][0];
        if (even_next[i] > (int)i) dp[even_next[i]][0] += dp[i][1];
    }
    return dp[A.size() - 1][0] + dp[A.size() - 1][1];
}

/// <summary>
/// Leet code #978. Longest Turbulent Subarray
/// 
/// A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if 
/// and only if:
/// For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when 
/// k is even;
/// OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] 
/// when k is odd.
/// That is, the subarray is turbulent if the comparison sign flips 
/// between each adjacent pair of elements in the subarray.
/// Return the length of a maximum size turbulent subarray of A.
///
/// Example 1:
/// Input: [9,4,2,10,7,8,8,1,9]
/// Output: 5
/// Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
/// Example 2:
/// Input: [4,8,12,16]
/// Output: 2
///
/// Example 3:
/// Input: [100]
/// Output: 1
///
/// Note:
/// 1. 1 <= A.length <= 40000
/// 2. 0 <= A[i] <= 10^9
/// </summary>
int LeetCodeDP::maxTurbulenceSize(vector<int>& A)
{
    int last_sign = 0;
    int sign = 0;
    int accumulate = 1;
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (i == 0)
        {
            sign = 0;
            accumulate = 1;
        }
        else if (A[i] == A[i - 1])
        {
            sign = 0;
            accumulate = 1;
        }
        else
        {
            sign = (A[i] - A[i - 1]) / abs(A[i] - A[i - 1]);
            if (sign * last_sign == -1) accumulate++;
            else accumulate = 2;
        }
        last_sign = sign;
        result = max(result, accumulate);
    }
    return result;
}

/// <summary>
/// Leet code #982. Triples with Bitwise AND Equal To Zero
/// 
/// Given an array of integers A, find the number of triples of indices 
/// (i, j, k) such that:
/// 0 <= i < A.length
/// 0 <= j < A.length
/// 0 <= k < A.length
/// A[i] & A[j] & A[k] == 0, where & represents 
/// the bitwise-AND operator.
/// 
/// Example 1:
/// Input: [2,1,3]
/// Output: 12
/// Explanation: We could choose the following i, j, k triples:
/// (i=0, j=0, k=1) : 2 & 2 & 1
/// (i=0, j=1, k=0) : 2 & 1 & 2
/// (i=0, j=1, k=1) : 2 & 1 & 1
/// (i=0, j=1, k=2) : 2 & 1 & 3
/// (i=0, j=2, k=1) : 2 & 3 & 1
/// (i=1, j=0, k=0) : 1 & 2 & 2
/// (i=1, j=0, k=1) : 1 & 2 & 1
/// (i=1, j=0, k=2) : 1 & 2 & 3
/// (i=1, j=1, k=0) : 1 & 1 & 2
/// (i=1, j=2, k=0) : 1 & 3 & 2
/// (i=2, j=0, k=1) : 3 & 2 & 1
/// (i=2, j=1, k=0) : 3 & 1 & 2
/// 
/// Note:
/// 1. 1 <= A.length <= 1000
/// 2. 0 <= A[i] < 2^16
/// </summary>
int LeetCodeDP::countTriplets(vector<int>& A)
{
    unordered_map<int, int> prev, curr;
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        prev[A[i]]++;
    }
    for (size_t i = 0; i < A.size(); i++)
    {
        for (auto itr : prev)
        {
            int sum = itr.first & A[i];
            curr[sum] += itr.second;
        }
    }
    prev.clear();
    for (size_t i = 0; i < A.size(); i++)
    {
        for (auto itr : curr)
        {
            int sum = itr.first & A[i];
            if (sum == 0) result += itr.second;
        }
    }
    return result;
}

/// <summary>
/// Leet code #983. Minimum Cost For Tickets
/// </summary>
int LeetCodeDP::mincostTickets(int index, vector<int>& days, vector<int>& dp, vector<int>& costs)
{
    if (index >= (int)days.size()) return 0;
    else if (dp[index] > 0) return dp[index];
    int today = index;
    index++;
    int cost1 = costs[0] + mincostTickets(index, days, dp, costs);
    while (index < (int)days.size() && days[index] - days[today] < 7) index++;
    int cost7 = costs[1] + mincostTickets(index, days, dp, costs);
    while (index < (int)days.size() && days[index] - days[today] < 30) index++;
    int cost30 = costs[2] + mincostTickets(index, days, dp, costs);
    dp[today] = min(min(cost1, cost7), cost30);
    return dp[today];
}

/// <summary>
/// Leet code #983. Minimum Cost For Tickets
/// 
/// In a country popular for train travel, you have planned some train 
/// travelling one year in advance.  The days of the year that you will 
/// travel is given as an array days.  Each day is an integer from 1 to 365.
/// Train tickets are sold in 3 different ways:
/// 1. a 1-day pass is sold for costs[0] dollars;
/// 2. a 7-day pass is sold for costs[1] dollars;
/// 3. a 30-day pass is sold for costs[2] dollars.
/// The passes allow that many days of consecutive travel.  For example, if 
/// we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 
/// 5, 6, 7, and 8.
/// Return the minimum number of dollars you need to travel every day in the 
/// given list of days.
/// 
/// Example 1:
/// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
/// Output: 11
/// Explanation: 
/// For example, here is one way to buy passes that lets you travel your 
/// travel plan:
/// 1. On day 1, you bought a 1-day pass for costs[0] = $2, which covered 
///    day 1.
/// 2. On day 3, you bought a 7-day pass for costs[1] = $7, which covered 
///    days 3, 4, ..., 9.
/// 3. On day 20, you bought a 1-day pass for costs[0] = $2, which covered 
///    day 20.
/// 4. In total you spent $11 and covered all the days of your travel.
///
/// Example 2:
/// Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
/// Output: 17
/// Explanation: 
/// For example, here is one way to buy passes that lets you travel your 
/// travel plan:
/// 1. On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 
///    1, 2, ..., 30.
/// 2. On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 
///    31.
/// 3. In total you spent $17 and covered all the days of your travel.
///  
/// Note:
/// 1. 1 <= days.length <= 365
/// 2. 1 <= days[i] <= 365
/// 3. days is in strictly increasing order.
/// 4. costs.length == 3
/// 5. 1 <= costs[i] <= 1000
/// </summary>
int LeetCodeDP::mincostTickets(vector<int>& days, vector<int>& costs)
{
    vector<int> dp(days.size());
    return mincostTickets(0, days, dp, costs);
}

/// <summary>
/// Leet code #1025. Divisor Game
/// 
/// Alice and Bob take turns playing a game, with Alice starting first.
///
/// Initially, there is a number N on the chalkboard.  On each player's 
/// turn, that player makes a move consisting of:
///
/// Choosing any x with 0 < x < N and N % x == 0.
/// Replacing the number N on the chalkboard with N - x.
/// Also, if a player cannot make a move, they lose the game.
/// 
/// Return True if and only if Alice wins the game, assuming both players 
/// play optimally.
///
/// Example 1:
/// Input: 2
/// Output: true
/// Explanation: Alice chooses 1, and Bob has no more moves.
///
/// Example 2:
/// Input: 3
/// Output: false
/// Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
/// 
/// Note:
/// 1. 1 <= N <= 1000
/// </summary>
bool LeetCodeDP::divisorGame(int N)
{
    vector<bool> dp(N + 1);
    for (int i = 1; i <= N; i++)
    {
        if (i == 1) dp[i] = false;
        else
        {
            for (int j = 1; j <= (int)std::sqrt(i); j++)
            {
                if ((i % j) != 0) continue;
                if (dp[i - j] == false)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[N];
}

/// <summary>
/// Leet code #1027. Longest Arithmetic Sequence
/// 
/// Given an array A of integers, return the length of the longest arithmetic 
/// subsequence in A.
///
/// Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 
/// 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is 
/// arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < 
/// B.length - 1).
///
/// Example 1:
///
/// Input: [3,6,9,12]
/// Output: 4
/// Explanation: 
/// The whole array is an arithmetic sequence with steps of length = 3.
///
/// Example 2:
///
/// Input: [9,4,7,2,10]
/// Output: 3
/// Explanation: 
/// The longest arithmetic subsequence is [4,7,10].
///
/// Example 3:
///
/// Input: [20,1,15,3,10,5,8]
/// Output: 4
/// Explanation: 
/// The longest arithmetic subsequence is [20,15,10,5].
/// 
/// Note:
/// 
/// 1. 2 <= A.length <= 2000
/// 2. 0 <= A[i] <= 10000
/// </summary>
int LeetCodeDP::longestArithSeqLength(vector<int>& A)
{
    int result = 0;
    vector<unordered_map<int, int>> arithmeticCount(A.size());
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            int diff = A[i] - A[j];
            if (arithmeticCount[j].count(diff) > 0)
            {
                arithmeticCount[i][diff] = max(arithmeticCount[i][diff], arithmeticCount[j][diff] + 1);
            }
            else
            {
                arithmeticCount[i][diff] = max(arithmeticCount[i][diff], 2);
            }
            result = max(result, arithmeticCount[i][diff]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1031. Maximum Sum of Two Non-Overlapping Subarrays
/// 
/// Given an array A of non-negative integers, return the maximum sum of 
/// elements in two non-overlapping (contiguous) subarrays, which have 
/// lengths L and M.  (For clarification, the L-length subarray could occur 
/// before or after the M-length subarray.)
///
/// Formally, return the largest V for which V = (A[i] + A[i+1] + ... + 
/// A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
///
/// 0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
/// 0 <= j < j + M - 1 < i < i + L - 1 < A.length.
/// 
///
/// Example 1:
///
/// Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
/// Output: 20
/// Explanation: One choice of subarrays is [9] with length 1, and [6,5] with 
/// length 2.
///
/// Example 2:
///
/// Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
/// Output: 29
/// Explanation: One choice of subarrays is [3,8,1] with length 3, and 
/// [8,9] with length 2.
///
/// Example 3:
///
/// Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
/// Output: 31
/// Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] 
/// with length 3.
///
/// Note:
///
/// 1. L >= 1
/// 2. M >= 1
/// 3. L + M <= A.length <= 1000
/// 4. 0 <= A[i] <= 1000
/// </summary>
int LeetCodeDP::maxSumTwoNoOverlap(vector<int>& A, int L, int M)
{
    vector<int> sum(A.size() + 1);
    sum[0] = 0;
    vector<vector<int>> dp(A.size(), vector<int>(4));
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        sum[i+1] = sum[i] + A[i];
        if (i + 1 >= (size_t)L)
        {
            dp[i][0] = sum[i + 1] - sum[i + 1 - L];
            dp[i][2] = dp[i][0];
            if (i > 0) dp[i][2] = max(dp[i][2], dp[i - 1][2]);
        }
        if (i + 1 >= (size_t)M)
        {
            dp[i][1] = sum[i + 1] - sum[i + 1 - M];
            dp[i][3] = dp[i][1];
            if (i > 0) dp[i][3] = max(dp[i][3], dp[i - 1][3]);
        }

        if (i + 1 >= (size_t)(L + M))
        {
            result = max(result, dp[i][0] + dp[i - L][3]);
            result = max(result, dp[i][1] + dp[i - M][2]);
        }
    }

    return result;
}

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
int LeetCodeDP::maxUncrossedLines(vector<int>& A, vector<int>& B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1));
    dp[0][0] = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < B.size(); j++)
        {
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            if (A[i] == B[j]) dp[i + 1][j + 1] = max(dp[i + 1][j+1], dp[i][j] + 1);
        }
    }
    return dp[A.size()][B.size()];
}

/// <summary>
/// Leet code #1039. Minimum Score Triangulation of Polygon
/// </summary>
int LeetCodeDP::minScoreTriangulation(vector<int>& A, 
    int start, int end, 
    unordered_map<string, int>& cache)
{
    if (end - start < 2) return 0;
    string key = to_string(start) + "," + to_string(end);
    if (cache.count(key) > 0) return cache[key];
    int result = INT_MAX;
    for (int middle = start + 1; middle < end; middle++)
    {
        int sum = minScoreTriangulation(A, start, middle, cache);
        sum += A[start] * A[middle] * A[end];
        sum += minScoreTriangulation(A, middle, end, cache);
        result = min(result, sum);
    }
    cache[key] = result;
    return result;
}

/// <summary>
/// Leet code #1039. Minimum Score Triangulation of Polygon
/// 
/// Given N, consider a convex N-sided polygon with vertices labelled 
/// A[0], A[i], ..., A[N-1] in clockwise order.
///
/// Suppose you triangulate the polygon into N-2 triangles.  For each 
/// triangle, the value of that triangle is the product of the labels 
/// of the vertices, and the total score of the triangulation is the 
/// sum of these values over all N-2 triangles in the triangulation.
///
/// Return the smallest possible total score that you can achieve with some 
/// triangulation of the polygon.
/// 
/// Example 1:
///
/// Input: [1,2,3]
/// Output: 6
/// Explanation: The polygon is already triangulated, and the score of the 
/// only triangle is 6.
///
/// Example 2:
///
/// Input: [3,7,4,5]
/// Output: 144
/// Explanation: There are two triangulations, with possible scores: 3*7*5 + 
/// 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.
///
/// Example 3:
///
/// Input: [1,3,1,4,1,5]
/// Output: 13
/// Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 
/// 1*1*5 + 1*1*1 = 13.
/// 
///
/// Note:
///
/// 1. 3 <= A.length <= 50
/// 2. 1 <= A[i] <= 100
/// </summary>
int LeetCodeDP::minScoreTriangulationII(vector<int>& A)
{
    unordered_map<string, int> cache;

    return minScoreTriangulation(A, 0, A.size() - 1, cache);
}

/// <summary>
/// Leet code #1039. Minimum Score Triangulation of Polygon
/// </summary>
int LeetCodeDP::minScoreTriangulation(vector<int>& A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A.size()));
    for (size_t k = 2; k < A.size(); k++)
    {
        for (size_t i = 0; i < A.size(); i++)
        {
            size_t j = i + k;
            if (j >= A.size()) break;
            for (size_t m = i + 1; m < j; m++)
            {
                if (dp[i][j] == 0)
                {
                    dp[i][j] = dp[i][m] + A[i] * A[m] * A[j] + dp[m][j];
                }
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i][m] + A[i] * A[m] * A[j] + dp[m][j]);
                }
            }
        }
    }
    return dp[0][A.size() - 1];
}

/// <summary>
/// Leet code #1043. Partition Array for Maximum Sum
/// 
/// Given an integer array A, you partition the array into (contiguous) 
/// subarrays of length at most K.  After partitioning, each subarray has 
/// their values changed to become the maximum value of that subarray.
///
/// Return the largest sum of the given array after partitioning.
///
/// 
/// 
/// Example 1:
///
/// Input: A = [1,15,7,9,2,5,10], K = 3
/// Output: 84
/// Explanation: A becomes [15,15,15,9,10,10,10]
///  
///
/// Note:
///
/// 1. 1 <= K <= A.length <= 500
/// 2. 0 <= A[i] <= 10^6
/// </summary>
int LeetCodeDP::maxSumAfterPartitioning(vector<int>& A, int K)
{
    vector<int> result(A.size());
    vector<int> dp(A.size());
    for (int i = 0; i < (int)A.size(); i++)
    {
        dp[i] = A[i];
        for (int j = 0; j < K; j++)
        {
            int first = i - j;
            if (first < 0) break;
            dp[i] = max(dp[i], A[first]);
            int prev = first - 1;
            if (prev < 0)
            {
                result[i] = max(result[i], dp[i] * (j + 1));
            }
            else
            {
                result[i] = max(result[i], result[prev] + dp[i] * (j + 1));
            }
        }
    }
    return result[result.size() - 1];
}

/// <summary>
/// Leet code #1048. Longest String Chain
/// 
/// Given a list of words, each word consists of English lowercase letters.
///
/// Let's say word1 is a predecessor of word2 if and only if we can add 
/// exactly one letter anywhere in word1 to make it equal to word2.  For 
/// example, "abc" is a predecessor of "abac".
///
/// A word chain is a sequence of words [word_1, word_2, ..., word_k] 
/// with k >= 1, where word_1 is a predecessor of word_2, word_2 is a 
/// predecessor of word_3, and so on.
///
/// Return the longest possible length of a word chain with words chosen 
/// from the given list of words.
///
/// Example 1:
///
/// Input: ["a","b","ba","bca","bda","bdca"]
/// Output: 4
/// Explanation: one of the longest word chain is "a","ba","bda","bdca".
/// 
/// Note:
/// 1. 1 <= words.length <= 1000
/// 2. 1 <= words[i].length <= 16
/// 3. words[i] only consists of English lowercase letters.
/// </summary>
int LeetCodeDP::longestStrChain(vector<string>& words)
{
    unordered_map<string, int> word_set;
    map<int, vector<string>> word_index;
    for (string word : words)
    {
        word_set[word] = 1;
        word_index[word.size()].push_back(word);
    }
    int result = 0;
    for (auto itr : word_index)
    {
        for (string word : word_index[itr.first])
        {
            for (size_t j = 0; j < word.size(); j++)
            {
                string short_word = word;
                short_word.erase(j, 1);
                if (word_set.count(short_word) > 0)
                {
                    word_set[word] = max(word_set[word], word_set[short_word] + 1);
                }
            }
            result = max(result, word_set[word]);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1049. Last Stone Weight II
///                 
/// Medium
///
/// You are given an array of integers stones where stones[i] is the weight 
/// of the ith stone.
///
/// We are playing a game with the stones. On each turn, we choose any two 
/// stones and smash them together. Suppose the stones have weights x and y 
/// with x <= y. The result of this smash is:
///
/// If x == y, both stones are destroyed, and
/// If x != y, the stone of weight x is destroyed, and the stone of weight y 
/// has new weight y - x.
/// At the end of the game, there is at most one stone left.
///
/// Return the smallest possible weight of the left stone. If there are no 
/// stones left, return 0.
/// 
/// Example 1:
/// Input: stones = [2,7,4,1,8,1]
/// Output: 1
/// Explanation:
/// We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
/// we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
/// we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
/// we can combine 1 and 1 to get 0, so the array converts to [1], then that's 
/// the optimal value.
///
/// Example 2:
/// Input: stones = [31,26,33,21,40]
/// Output: 5
/// 
/// Constraints:
/// 1. 1 <= stones.length <= 30
/// 2. 1 <= stones[i] <= 100
/// </summary>
int LeetCodeDP::lastStoneWeightII(vector<int> &stones) 
{
    int sum = 0; 
    if (stones.size() == 1) return stones[0];
    for (size_t i = 0; i < stones.size(); i++)
    {
        sum += stones[i];
    }
    vector<int> dp(sum / 2 + 1);
    dp[0] = 1;
    for (int a : stones) 
    {
        for (int i = sum / 2; i >= a; --i)
        {
            dp[i] = (dp[i - a] == 1) ? 1 : dp[i];
        }
    }
    for (int i = sum / 2; i > 0; --i)
    {
        if (dp[i] == 1) return sum - i - i;
    }
    return 0;
}

/// <summary>
/// Leet code #1062. Longest Repeating Substring
/// 
/// Given a string S, find out the length of the longest repeating 
/// substring(s). Return 0 if no repeating substring exists.
///
/// Example 1:
/// Input: "abcd"
/// Output: 0
/// Explanation: There is no repeating substring.
///
/// Example 2:
/// Input: "abbaba"
/// Output: 2
/// Explanation: The longest repeating substrings are "ab" and "ba", each of 
/// which occurs twice.
///
/// Example 3:
/// Input: "aabcaabdaab"
/// Output: 3
/// Explanation: The longest repeating substring is "aab", which occurs 3 
/// times.
///
/// Example 4:
///
/// Input: "aaaaa"
/// Output: 4
/// Explanation: The longest repeating substring is "aaaa", which occurs twice.
///
/// Note:
/// 
/// 1. The string S consists of only lowercase English letters from 'a' - 'z'.
/// 2. 1 <= S.length <= 1500
/// </summary>
int LeetCodeDP::longestRepeatingSubstring(string S)
{
    vector<vector<int>> dp(S.size(), vector<int>(S.size()));
    int result = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (S[i] == S[j])
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
            result = max(result, dp[i][j]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1092. Shortest Common Supersequence
/// 
/// Given two strings str1 and str2, return the shortest string that has 
/// both str1 and str2 as subsequences.  If multiple answers exist, you 
/// may return any of them.
///
/// (A string S is a subsequence of string T if deleting some number of 
/// characters from T (possibly 0, and the characters are chosen anywhere 
/// from T) results in the string S.)
///
/// Example 1:
/// Input: str1 = "abac", str2 = "cab"
/// Output: "cabac"
/// Explanation: 
/// str1 = "abac" is a substring of "cabac" because we can delete the 
/// first "c".
/// str2 = "cab" is a substring of "cabac" because we can delete the last 
/// "ac".
/// The answer provided is the shortest such string that satisfies these 
/// properties.
/// 
/// Note:
/// 1. 1 <= str1.length, str2.length <= 1000
/// 2. str1 and str2 consist of lowercase English letters.
/// </summary>
string LeetCodeDP::shortestCommonSupersequence(string str1, string str2)
{
    vector<vector<int>> dp(str1.size(), vector<int>(str2.size()));
    for (size_t i = 0; i < str1.size(); i++)
    {
        for (size_t j = 0; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = 1;
                if (i > 0 && j > 0) dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
                if (i > 0) dp[i][j] = dp[i - 1][j];
                if (j > 0)dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    int i = str1.size() - 1;
    int j = str2.size() - 1;
    string result;
    while (i >= 0 || j >= 0)
    {
        if (i < 0)
        {
            result.push_back(str2[j]);
            j--;
        }
        else if (j < 0)
        {
            result.push_back(str1[i]);
            i--;
        }
        else if (str1[i] == str2[j])
        {
            result.push_back(str1[i]);
            i--;
            j--;
        }
        else if (j > 0 && dp[i][j] == dp[i][j - 1])
        {
            result.push_back(str2[j]);
            j--;
        }
        else if (i > 0 && dp[i][j] == dp[i - 1][j])
        {
            result.push_back(str1[i]);
            i--;
        }
        else
        {
            result.push_back(str1[i]);
            i--;
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

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
///
/// </summary>
int LeetCodeDP::minHeightShelves(vector<vector<int>>& books, int shelf_width)
{
    vector<int> dp;
    int result = 0;
    for (size_t i = 0; i < books.size(); i++)
    {
        if (i == 0)
        {
            result = books[i][1];
            dp.push_back(books[i][1]);
        }
        else
        {
            int height = books[i][1];
            int width = books[i][0];
            int index = dp.size() - 1;
            result = height + dp[index];
            while (index >= 0 && books[index][0] + width <= shelf_width)
            {
                height = max(height, books[index][1]);
                width += books[index][0];
                if (index == 0)
                {
                    result = min(result, height);
                }
                else
                {
                    result = min(result, dp[index - 1] + height);
                }
                index--;
            }
            dp.push_back(result);
        }
    }
    return result;
}

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
vector<int> LeetCodeDP::smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people)
{
    unordered_map<string, int> skill_ids;
    size_t n = req_skills.size();
    for (size_t i = 0; i < n; i++)
    {
        skill_ids[req_skills[i]] = (1 << i);
    }
    vector<vector<int>> team((1 << n), vector<int>());
    team[0] = vector<int>();
    for (size_t i = 0; i < people.size(); i++)
    {
        int people_skill = 0;
        for (size_t j = 0; j < people[i].size(); j++)
        {
            people_skill |= skill_ids[people[i][j]];
        }
        if (people_skill == 0) continue;
        for (size_t j = 0; j < team.size(); j++)
        {
            if ((j != 0) && (team[j].size() == 0))
            {
                continue;
            }
            int skill = ((int)j | people_skill);
            if (team[skill].size() == 0 || team[skill].size() > team[j].size() + 1)
            {
                team[skill] = team[j];
                team[skill].push_back(i);
            }
        }
    }
    return team[(1 << n) - 1];
}

/// <summary>
/// Leet code #1130. Minimum Cost Tree From Leaf Values
/// </summary>
int LeetCodeDP::mctFromLeafValuesII(vector<int>& arr)
{
    size_t n = arr.size();
    vector<int> dp;
    int result = 0;
    for (size_t i = 0; i < n; i++)
    {
        while ((dp.size() > 1) &&(dp[dp.size() - 1] <= dp[dp.size() - 2]) && 
               (dp[dp.size() - 1] <= arr[i]))
        {
            result += dp[dp.size() - 1] * min(dp[dp.size() - 2], arr[i]);
            dp.pop_back();
        }
        dp.push_back(arr[i]);
    }
    for (int i = 0; i < (int)dp.size() - 1; i++)
    {
        result += dp[i] * dp[i + 1];
    }
    return result;
}

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
int LeetCodeDP::mctFromLeafValues(vector<int>& arr)
{
    size_t n = arr.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

    for (size_t step = 0; step < n; step++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (step == 0)
            {
                dp[i][i] = make_pair(arr[i], 0);
            }
            else if (i + step >= n)
            {
                break;
            }
            else
            {
                size_t left = i;
                size_t right = i + step;
                int max_leaf = 0;
                int min_sum = INT_MAX;
                for (size_t k = 0; k < n; k++)
                {
                    if (left + k + 1 > right) break;
                    max_leaf = max(max_leaf, dp[left][left + k].first);
                    max_leaf = max(max_leaf, dp[left + k + 1][right].first);
                    int sum = dp[left][left + k].first * dp[left + k + 1][right].first;
                    sum += dp[left][left + k].second +  dp[left + k + 1][right].second;
                    min_sum = min(min_sum, sum);
                }
                dp[left][right].first = max_leaf;
                dp[left][right].second = min_sum;
            }
        }
    }
    return dp[0][n - 1].second;
}

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
int LeetCodeDP::largest1BorderedSquare(vector<vector<int>>& grid)
{
    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(2)));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            if (i == 0) dp[i][j][0] = grid[i][j];
            else
            {
                dp[i][j][0] = (grid[i][j] == 0) ? 0: dp[i - 1][j][0] + 1;
            }
            if (j == 0) dp[i][j][1] = grid[i][j];
            else
            {
                dp[i][j][1] = (grid[i][j] == 0) ? 0 : dp[i][j - 1][1] + 1;
            }
        }
    }
    int result = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            int d = min(dp[i][j][0], dp[i][j][1]);
            while (d > 0)
            {
                int pre_r = i - d + 1;
                int pre_c = j - d + 1;
                if (dp[pre_r][j][1] >= d && dp[i][pre_c][0] >= d)
                {
                    result = max(result, d * d);
                    break;
                }
                d--;
            }
        }
    }
    return result;
}


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
int LeetCodeDP::longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));
    for (size_t i = 0; i < text1.size(); i++)
    {
        for (size_t j = 0; j < text2.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                if (text1[i] == text2[j]) dp[i][j] = 1;
                else if (i > 0) dp[i][j] = dp[i-1][j];
                else if (j > 0) dp[i][j] = dp[i][j - 1];
                else dp[i][j] = 0;
            }
            else
            {
                if (text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.size() - 1][text2.size() - 1];
}

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
int LeetCodeDP::longestDecomposition(string text)
{
    vector<vector<int>> dp(text.size(), vector<int>(text.size()));

    for (int i = 0; i < (int)text.size(); i++)
    {
        for (int j = i; j < (int)text.size(); j++)
        {
            if (text[i] == text[j])
            {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int result = 0;
    for (int j = text.size() - 1; j >= (int)text.size() / 2;)
    {
        int start = (int)text.size() - 1 - j;
        for (int i =  start; i < (int)text.size(); i++)
        {
            if (i - start + 1 <= dp[i][j])
            {
                if (i != j) result += 2;                
                else result++;
                j -= i - start + 1;
                break;
            }
        }
    }
   
    return result;
}

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
int LeetCodeDP::numRollsToTarget(int d, int f, int target)
{
    vector<long long> dp(target + 1);
    unsigned long long M = 1000000007;

    for (int i = 0; i < d; i++)
    {
        vector<long long> next(target + 1);
        for (int j = 1; j <= f; j++)
        {
            if (i == 0)
            {
                if (j > target) break;
                next[j] = 1;
            }
            else
            {
                for (int k = 0; k < target; k++)
                {
                    if (k + j > target) break;
                    next[k + j] = (next[k + j] + dp[k]) % M;
                }
            }
        }
        dp = next;
    }
    return (int)dp[target];
}

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
int LeetCodeDP::makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
{
    vector<map<int, int>> dp(2000);
    // sort arr2 first
    sort(arr2.begin(), arr2.end());
    for (size_t i = 0; i < arr1.size(); i++)
    {
        if (i == 0)
        {
            dp[0][0] = arr1[0];
            if (arr2[0] < arr1[0]) dp[0][1] = arr2[0];
        }
        else
        {
            for (auto itr : dp[i - 1])
            {
                if (arr1[i] > itr.second)
                {
                    if (dp[i].count(itr.first) == 0)
                    {
                        dp[i][itr.first] = arr1[i];
                    }
                    else
                    {
                        dp[i][itr.first] = min(dp[i][itr.first], arr1[i]);
                    }
                }
                int index = upper_bound(arr2.begin(), arr2.end(), itr.second) - arr2.begin();
                if (index == arr2.size()) continue;
                if ((dp[i].count(itr.first) > 0) && (arr2[index] >= dp[i][itr.first])) continue;
                if (dp[i].count(itr.first + 1) == 0)
                {
                    dp[i][itr.first + 1] = arr2[index];
                }
                else
                {
                    dp[i][itr.first + 1] = min(dp[i][itr.first + 1], arr2[index]);
                }
            }
        }
    }
    if (dp[arr1.size() - 1].empty())
    {
        return -1;
    }
    else
    {
        return dp[arr1.size() - 1].begin()->first;
    }
}

/// <summary>
/// Leet Code 518. Coin Change II
///                 
/// Medium
///
/// You are given an integer array coins representing coins of different 
/// denominations and an integer amount representing a total amount of 
/// money.
///
/// Return the number of combinations that make up that amount. If that 
/// amount of money cannot be made up by any combination of the coins, 
/// return 0.
///
/// You may assume that you have an infinite number of each kind of coin.
///
/// The answer is guaranteed to fit into a signed 32-bit integer.
/// 
/// Example 1:
/// Input: amount = 5, coins = [1,2,5]
/// Output: 4
/// Explanation: there are four ways to make up the amount:
/// 5=5
/// 5=2+2+1
/// 5=2+1+1+1
/// 5=1+1+1+1+1
///
/// Example 2:
/// Input: amount = 3, coins = [2]
/// Output: 0
/// Explanation: the amount of 3 cannot be made up just with coins of 2.
///
/// Example 3:
/// Input: amount = 10, coins = [10]
/// Output: 1
///
/// Constraints:
/// 1. 1 <= coins.length <= 300
/// 2. 1 <= coins[i] <= 5000
/// 3. All the values of coins are unique.
/// 4. 0 <= amount <= 5000
/// </summary>
int LeetCodeDP::change(int amount, vector<int>& coins)
{
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (size_t i = 0; i < (int)coins.size(); i++)
    {
        for (int j = 0; j <= amount - coins[i]; j++)
        {
            dp[j + coins[i]] += dp[j];
        }
    }
    return dp[amount];
}

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
int LeetCodeDP::profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit)
{
    int result = 0;
    int mod = 1000000007;
    vector<vector<int>> schemes(G + 1, vector<int>(P + 1));
    schemes[0][0] = 1;
    for (size_t i = 0; i < group.size(); i++)
    {
        for (int j = G; j >= 0; j--)
        {
            int g = j + group[i];
            if (g > G) continue;
            for (int k = P; k >= 0; k--)
            {
                if (schemes[j][k] == 0) continue;
                int p = k + profit[i];
                if (p > P) p = P;
                int count = schemes[j][k];
                schemes[g][p] = (schemes[g][p] + count) % mod;
            }
        }
    }
    for (auto j = 0; j <= G; j++)
    {
        result = (result + schemes[j][P]) % mod;
    }
    return result;
}

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
int LeetCodeDP::findTargetSumWays(vector<int>& nums, int S)
{
    map<int, int> sum_way1, sum_way2;
    map<int, int>* p_curr = &sum_way1;
    map<int, int>* p_next = &sum_way2;
    sum_way1[0] = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (auto itr : *p_curr)
        {
            (*p_next)[itr.first + nums[i]] += itr.second;
            (*p_next)[itr.first - nums[i]] += itr.second;
        }
        swap(p_curr, p_next);
        p_next->clear();
    }
    return (*p_curr)[S];
}

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
/// Input: activities = {{0,3,1},{0,5,5},{5,6,1},{6,18,2}}
/// Output: 8
/// Explanation: with {0, 5, 5} => {5, 6, 1} => {6, 8, 2}
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
int LeetCodeDP::maxInterest(vector<vector<int>> activities)
{
    vector<pair<int, int>> schedule;
    for (size_t i = 0; i < activities.size(); i++)
    {
        schedule.push_back(make_pair(activities[i][1], i));
    }
    sort(schedule.begin(), schedule.end());
    vector<pair<int, int>> dp;
    // push a base node
    dp.push_back({ 0, 0 });
    
    for (size_t i = 0; i < schedule.size(); i++)
    {
        vector<int> activity = activities[schedule[i].second];

        int index = lower_bound(dp.begin(), dp.end(), make_pair(activity[0], 0)) - dp.begin();
        // last activity is ahead
        if (index == dp.size() || dp[index].first > activity[0])
        {
            index--;
        }
        int interest = dp[index].second + activity[2];
        if (dp.back().first == activity[1])
        {
            interest = max(interest, dp.back().second);
            dp.pop_back();
        }
        // keep accumulated interesting increasing
        if (interest > dp.back().second)
        {
            dp.push_back(make_pair(activity[1], interest));
        }
    }
    return dp.back().second;
}

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
int LeetCodeDP::longestLine(vector<vector<int>>& M)
{
    vector<vector<vector<int>>> dp;
    int max_length = 0;
    for (size_t i = 0; i < M.size(); i++)
    {
        dp.push_back(vector<vector<int>>(M[i].size(), vector<int>(4, 0)));
        for (size_t j = 0; j < M[i].size(); j++)
        {
            // if zero we ignore
            if (M[i][j] == 1)
            {
                dp[i][j][0] = (i > 0 && M[i - 1][j] == 1) ? 
                              dp[i - 1][j][0] + 1 : 1;
                dp[i][j][1] = (j > 0 && M[i][j - 1] == 1) ? 
                              dp[i][j - 1][1] + 1 : 1;
                dp[i][j][2] = (i > 0 && j > 0 && M[i - 1][j - 1] == 1) ? 
                              dp[i - 1][j - 1][2] + 1 : 1;
                dp[i][j][3] = (i > 0 && j < M[i].size() - 1 && 
                               M[i - 1][j + 1] == 1) ? 
                              dp[i - 1][j + 1][3] + 1 : 1;
            }
            for (size_t k = 0; k < 4; k++)
            {
                max_length = max(max_length, dp[i][j][k]);
            }
        }
    }
    return max_length;
}

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
vector<vector<int>> LeetCodeDP::generatePascalTriangle(int numRows)
{
    vector<vector<int>> result;
    if (numRows <= 0) return result;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> prev_level;
        if (i > 0) prev_level = result.back();
        vector<int> level;
        for (int j = 0; j <= i; j++)
        {
            if ((j == 0) || (j == i))
            {
                level.push_back(1);
            }
            else
            {
                level.push_back(prev_level[j - 1] + prev_level[j]);
            }
        }
        result.push_back(level);
    }
    return result;
}

/// <summary>
/// Leet code #119. Pascal's Triangle II 
/// Given an index k, return the kth row of the Pascal's triangle.
/// For example, given k = 3,
/// Return [1,3,3,1]. 
/// Note:
/// Could you optimize your algorithm to use only O(k) extra space? 
/// </summary>
vector<int> LeetCodeDP::getPascalTriangleRow(int rowIndex)
{
    vector<int> level;
    if (rowIndex < 0) return level;
    for (int i = 0; i <= rowIndex; i++)
    {
        vector<int> prev_level = level;
        level.clear();
        for (int j = 0; j <= i; j++)
        {
            if ((j == 0) || (j == i))
            {
                level.push_back(1);
            }
            else
            {
                level.push_back(prev_level[j - 1] + prev_level[j]);
            }
        }
    }
    return level;
}

/// <summary>
/// Leet Code 322. Coin Change
///                 
/// Medium
///
/// You are given an integer array coins representing coins of different 
/// denominations and an integer amount representing a total amount of money.
///
/// Return the fewest number of coins that you need to make up that amount. 
/// If that amount of money cannot be made up by any combination of the coins, 
/// return -1.
///
/// You may assume that you have an infinite number of each kind of coin.
/// 
/// Example 1:
/// Input: coins = [1,2,5], amount = 11
/// Output: 3
/// Explanation: 11 = 5 + 5 + 1
///
/// Example 2:
/// Input: coins = [2], amount = 3
/// Output: -1
///
/// Example 3:
/// Input: coins = [1], amount = 0
/// Output: 0
/// 
/// Constraints:
/// 1. 1 <= coins.length <= 12
/// 2. 1 <= coins[i] <= 2^31 - 1
/// 3. 0 <= amount <= 10^4
/// </summary>
int LeetCodeDP::coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    for (int i = 0; i <= amount; i++)
    {
        if (i == 0) dp[i] = 0;
        if (dp[i] == INT_MAX) continue;
        for (size_t j = 0; j < coins.size(); j++)
        {
            if (coins[j] > amount) continue;
            if (i + coins[j] > amount) continue;
            dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
        }
    }
    dp[amount] = (dp[amount] == INT_MAX) ? -1 : dp[amount];
    return dp[amount];
}

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
///Input: A = [1,1,2,2,2,2], target = 5
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
int LeetCodeDP::threeSumMulti(vector<int>& A, int target)
{
    int result = 0;
    size_t M = 1000000007;
    vector<unordered_map<int, int>> dp(2);

    for (size_t i = 0; i < A.size(); i++)
    {
        // find if any two sum add current item can form target
        if (dp[1].count(target - A[i]) > 0)
        {
            result = (result + dp[1][target - A[i]]) % M;
        }
        // build new two sum with current item and existing one sum
        for (auto itr : dp[0])
        {
            dp[1][itr.first + A[i]] = (dp[1][itr.first + A[i]] + itr.second) % M;
        }
        // add current number to one sum
        dp[0][A[i]] = (dp[0][A[i]] + 1) % M;
    }
    return result;
}

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
bool LeetCodeDP::isValidPalindrome(string s, int k)
{
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));

    for (size_t p = 0; p < s.size(); p++)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if ((i + p) >= s.size()) break;
            if (p == 0) dp[i][i] = 1;
            else if (p == 1)
            {
                if (s[i] == s[i + p])
                {
                    dp[i][i + p] = 2;
                }
                else
                {
                    dp[i][i + p] = 1;
                }
            }
            else
            {
                if (s[i] == s[i + p])
                {
                    dp[i][i + p] = 2 + dp[i + 1][i + p - 1];
                    dp[i][i + p] = max(dp[i][i + p], dp[i + 1][i + p]);
                    dp[i][i + p] = max(dp[i][i + p], dp[i][i + p - 1]);
                }
                else
                {
                    dp[i][i + p] = max(dp[i][i + p], dp[i + 1][i + p]);
                    dp[i][i + p] = max(dp[i][i + p], dp[i][i + p - 1]);
                }
            }
        }
    }
    if (dp[0][s.size() - 1] >= (int)s.size() - k) return true;
    else return false;
}

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
int LeetCodeDP::countVowelPermutation(int n)
{
    int M = 1000000007;
    vector<int> curr(5);

    for (int i = 0; i < n; i++)
    {
        vector<int> next(5);
        if (i == 0)
        {
            next[0] = 1;  // a
            next[1] = 1;  // e
            next[2] = 1;  // i
            next[3] = 1;  // o
            next[4] = 1;  // u
        }
        else
        {
            next[1] = (next[1] + curr[0]) % M;
            next[0] = (next[0] + curr[1]) % M;
            next[2] = (next[2] + curr[1]) % M;
            next[0] = (next[0] + curr[2]) % M;
            next[1] = (next[1] + curr[2]) % M;
            next[3] = (next[3] + curr[2]) % M;
            next[4] = (next[4] + curr[2]) % M;
            next[2] = (next[2] + curr[3]) % M;
            next[4] = (next[4] + curr[3]) % M;
            next[0] = (next[0] + curr[4]) % M;
        }
        curr = next;
    }
    int result = 0;
    for (auto itr : curr) result = (result + itr) % M;
    return result;
}

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
int LeetCodeDP::dieSimulator(int n, vector<int>& rollMax)
{
    int M = 1000000007;
    vector<vector<int>> dp(n, vector<int>(6));

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            if (i == 0) dp[i][j] = 1;
            else
            {
                for (size_t k = 0; k < 6; k++)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
                }
                if (i >= rollMax[j])
                {
                    // no previous sum, only 1 instance
                    if (i - rollMax[j] - 1 < 0) dp[i][j] = (dp[i][j] + M - 1) % M;
                    else
                    {
                        // deduct all previous invalid count
                        for (size_t l = 0; l < 6; l++)
                        {
                            if (l != j)
                            {
                                dp[i][j] = (dp[i][j] + M - dp[i - rollMax[j] - 1 ][l]) % M;
                            }
                        }
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < 6; i++)
    {
        result = (result + dp[n - 1][i]) % M;
    }

    return result;
}

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
double LeetCodeDP::probabilityOfHeads(vector<double>& prob, int target)
{
    vector<double> dp((prob.size() + 1) * 2);
    int curr = 0;
    int next = prob.size() + 1;
    for (int i = 0; i < (int)prob.size(); i++)
    {
        if (i == 0)
        {
            dp[0] = 1 - prob[0];
            dp[1] = prob[0];
        }
        else
        {
            for (int j = min(target, i); j >= 0; j--)
            {
                dp[next + j] = (1 - prob[i]) * dp[curr + j];
            }

            for (int j = min(target, i); j >= 0; j--)
            {
                dp[next + j + 1] += dp[curr + j] * prob[i];
            }
            curr = prob.size() + 1 - curr;
            next = prob.size() + 1 - next;
        }
    }
    return dp[curr + target];
}

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
int LeetCodeDP::jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
    vector<pair<int, int>> schedule;
    for (size_t i = 0; i < endTime.size(); i++)
    {
        schedule.push_back(make_pair(endTime[i], i));
    }
    sort(schedule.begin(), schedule.end());
    vector<pair<int, int>> dp;
    // push a base node
    dp.push_back({ 0, 0 });

    for (size_t i = 0; i < schedule.size(); i++)
    {
        int job_start = startTime[schedule[i].second];
        int job_end = schedule[i].first;
        int job_profit = profit[schedule[i].second];

        int index = lower_bound(dp.begin(), dp.end(), make_pair(job_start, 0)) - dp.begin();
        // last activity is ahead
        if (index == dp.size() || dp[index].first > job_start)
        {
            index--;
        }
        int total_profit = dp[index].second + job_profit;
        if (dp.back().first == job_end)
        {
            total_profit = max(total_profit, dp.back().second);
            dp.pop_back();
        }
        // keep accumulated interesting increasing
        if (total_profit > dp.back().second)
        {
            dp.push_back(make_pair(job_end, total_profit));
        }
    }
    return dp.back().second;
}

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
int LeetCodeDP::maxLength(vector<string>& arr)
{
    int result = 0;
    unordered_set<bitset<26>> unique;
    unordered_set<bitset<26>> buff;
    unique.insert(0);
    for (size_t i = 0; i < arr.size(); i++)
    {
        bitset<26> bit_c;
        for (char ch : arr[i])
        {
            bit_c.set(ch - 'a');
        }
        if (bit_c.count() != arr[i].size()) continue;
        for (bitset<26> x : unique)
        {
            if ((x & bit_c).any()) continue;
            bitset<26> bit_r = x | bit_c;
            result = max(result, (int)bit_r.count());
            buff.insert(bit_r);
        }
        unique.insert(buff.begin(), buff.end());
    }
    return result;
}


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
int LeetCodeDP::minimumMoves(vector<int>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));

    for (size_t k = 0; k < arr.size(); k++)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            if ((i + k) >= (int)arr.size()) continue;
            if (k == 0)
            {
                dp[i][i + k] = 1;
            }
            else if (k == 1)
            {
                if (arr[i] == arr[i + k])
                {
                    dp[i][i + k] = 1;
                }
                else
                {
                    dp[i][i + k] = 2;
                }
            }
            else
            {
                if (arr[i] == arr[i + k])
                {
                    dp[i][i + k] = dp[i + 1][i + k - 1];
                }
                else
                {
                    dp[i][i + k] = dp[i + 1][i + k - 1] + 2;
                }
                for (size_t t = i; t < i + k; t++)
                {
                    dp[i][i + k] = min(dp[i][i + k], dp[i][t] + dp[t + 1][i + k]);
                }
            }
        }
    }
    return dp[0][arr.size() - 1];
}

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
int LeetCodeDP::maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
{
    vector<int> letter_count(26);
    int result = 0;
    for (size_t i = 0; i < letters.size(); i++)
    {
        letter_count[letters[i] - 'a']++;
    }

    map<vector<int>, int> dp;
    dp[letter_count] = 0;
    for (size_t i = 0; i < words.size(); i++)
    {
        vector<int> word_count(26);
        for (size_t j = 0; j < words[i].size(); j++)
        {
            word_count[words[i][j] - 'a']++;
        }

        map<vector<int>, int> next;
        for (auto itr : dp)
        {
            bool hold = true;
            vector<int> prev_count = itr.first;
            int prev_score = itr.second;
            for (size_t j = 0; j < prev_count.size(); j++)
            {
                prev_count[j] -= word_count[j];
                prev_score += score[j] * word_count[j];
                if (prev_count[j] < 0)
                {
                    hold = false;
                    break;
                }
            }
            if (hold == false) continue;
            if (dp.count(prev_count) == 0 || dp[prev_count] < prev_score)
            {
                next[prev_count] = prev_score;
                result = max(result, prev_score);
            }
        }
        dp.insert(next.begin(), next.end());
    }
    return result;
}

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
int LeetCodeDP::numberOfWays(int num_people)
{
    long long M = 1000000007;
    vector<int>dp(num_people + 1);
    dp[0] = 1;
    for (int i = 2; i <= num_people; i+=2)
    {
        if (i == 2) dp[i] = 1;
        long long result = 0;
        for (int j = 2; j <= i; j += 2)
        {
            result += (long long)dp[j - 2] * (long long)dp[i - j] % M;
            result %= M;
        }
        dp[i] = (int)result;
    }
    return dp[num_people];
}

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
///
/// Example 2:
///
/// Input: steps = 2, arrLen = 4
/// Output: 2
/// Explanation: There are 2 differents ways to stay at index 0 after 2 steps
/// Right, Left
/// Stay, Stay
///
/// Example 3:
///
/// Input: steps = 4, arrLen = 2
/// Output: 8
///
/// Constraints:
/// 1. 1 <= steps <= 500
/// 2. 1 <= arrLen <= 10^6
/// </summary>
int LeetCodeDP::numWays(int steps, int arrLen)
{
    int M = 1000000007;
    vector<vector<int>> result(2, vector<int>(arrLen));

    int curr = 0;
    result[0][0] = 1;
    for (int i = 0; i < arrLen; i++)
    {
        int next = 1 - curr;

        for (int j = 0; j < arrLen; j++)    
        {
            if (j > i + 1 || j > steps - i) break;
            if (j == 0)
            {
                result[next][j] = (int)(((long long)result[curr][j] + (long long)result[curr][j + 1]) % M);
            }
            else if (j == arrLen - 1)
            {
                result[next][j] = (int)(((long long)result[curr][j] + (long long)result[curr][j - 1]) % M);
            }
            else
            {
                result[next][j] = (int)(((long long)result[curr][j - 1] + (long long)result[curr][j] + (long long)result[curr][j + 1]) % M);
            }
        }
        curr = next;
    }
    return result[curr][0];
}

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
int LeetCodeDP::countSquares(vector<vector<int>>& matrix)
{
    vector<vector<int>> count(matrix.size(), vector<int>(matrix[0].size()));
    int result = 0;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                count[i][j] = 0;
            }
            else
            {
                if (i == 0 || j == 0) count[i][j] = 1;
                else
                {
                    int prev_count = count[i - 1][j];
                    prev_count = min(prev_count, count[i][j - 1]);
                    prev_count = min(prev_count, count[i - 1][j - 1]);
                    count[i][j] = 1 + prev_count;
                }
                result += count[i][j];
            }
        }
    }
    return result;
}

/// <summary>
/// Leetcode #1278. Palindrome Partitioning III
/// </summary>
int LeetCodeDP::palindromePartition(string s, vector<vector<int>>& dp_change, int first, int last)
{
    if (dp_change[first][last] == -1)
    {
        int result = 0;
        while (first < last)
        {
            if (s[first] != s[last]) result++;
            first++;
            last--;
        }
        dp_change[first][last] = result;
    }
    return dp_change[first][last];
}

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
int LeetCodeDP::palindromePartition(string s, int k)
{
    int n = s.size();
    vector<vector<int>> dp_change(n, vector<int>(n, -1));
    vector<vector<int>> dp_count(n, vector<int>(k, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (j > i)  break;
            if (j == 0) dp_count[i][j] = palindromePartition(s, dp_change, 0, i);
            else
            {
                for (int l = j - 1; l < i; l++)
                {
                    int count = dp_count[l][j - 1] + palindromePartition(s, dp_change, l + 1, i);
                    dp_count[i][j] = min(dp_count[i][j], count);
                }
            }
        }
    }
    return dp_count[s.size() - 1][k - 1];
}

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
int LeetCodeDP::minFallingPathSumII(vector<vector<int>>& arr)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, -1 });
    pq.push({ 0, -1 });
    for (size_t i = 0; i < arr.size(); i++)
    {
        pair<int, int> second = pq.top();
        pq.pop();
        pair<int, int> first = pq.top();
        pq.pop();

        for (size_t j = 0; j < arr[i].size(); j++)
        {
            pair<int, int> next;
            if (first.second == j)
            {
                next.first = arr[i][j] + second.first;
            }
            else
            {
                next.first = arr[i][j] + first.first;
            }
            next.second = j;
            pq.push(next);
            if (pq.size() > 2) pq.pop();
        }
    }
    pair<int, int> result = pq.top();
    pq.pop();
    if (!pq.empty())
    {
        result = pq.top();
        pq.pop();
    }
    return result.first;
}

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
vector<int> LeetCodeDP::pathsWithMaxScore(vector<string>& board)
{
    int M = 1000000007;
    vector<vector<pair<int, int>>> dp(board.size(), vector<pair<int, int>>(board[0].size()));
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> directions = { {-1, 0}, {0, -1}, {-1, -1} };
    board[0][0] = '0';
    dp[n - 1][m - 1].second = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            for (size_t d = 0; d < directions.size(); d++)
            {
                int row = i + directions[d][0];
                int col = j + directions[d][1];

                if (row < 0 || col < 0) continue;
                if (board[row][col] == 'X') continue;
                // dead ponits.
                if (dp[i][j].first == 0 && board[i][j] != 'S') continue;

                int sum = dp[i][j].first + board[row][col] - '0';
                if (sum > dp[row][col].first)
                {
                    dp[row][col].first = sum;
                    dp[row][col].second = dp[i][j].second;
                }
                else if (sum == dp[row][col].first)
                {
                    dp[row][col].second = (dp[row][col].second + dp[i][j].second) % M;
                }
            }
        }
    }
    board[0][0] = 'E';
    vector<int> result = { dp[0][0].first, dp[0][0].second };
    return result;
}

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
int LeetCodeDP::minInsertions(string s)
{
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    for (size_t k = 0; k < s.size(); k++)
    {
        for (size_t i = 0; i + k < s.size(); i++)
        {
            if (k == 0) dp[i][i] = 0;
            else if (k == 1)
            {
                if (s[i] == s[i + k])
                {
                    dp[i][i + k] = 0;
                }
                else
                {
                    dp[i][i + k] = 1;
                }
            }
            else
            {
                dp[i][i + k] = INT_MAX;
                if (s[i] == s[i + k])
                {
                    dp[i][i+k] = min(dp[i][i+k], dp[i + 1][i + k - 1]);
                }
                dp[i][i + k] = min(dp[i][i + k], dp[i][i + k - 1] + 1);
                dp[i][i + k] = min(dp[i][i + k], dp[i + 1][i + k] + 1);
            }
        }
    }
    return dp[0][s.size() - 1];
}


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
int LeetCodeDP::minimumDistance(string word)
{
    vector<vector<int>> curr(27, vector<int>(27, INT_MAX));
    curr[26][26] = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        vector<vector<int>> next(27, vector<int>(27, INT_MAX));
        int digit = word[i] - 'A';

        for (size_t j = 0; j <= 26; j++)
        {
            for (size_t k = j; k <= 26; k++)
            {
                if (curr[j][k] == INT_MAX) continue;
                int x = j;
                int y = k;
                int cost = curr[j][k];
                if (x != 26)
                {
                    cost += abs(x / 6 - digit / 6) + abs(x % 6 - digit % 6);
                }
                x = digit;
                if (y < x) swap(x, y);
                next[x][y] = min(cost, next[x][y]);
                x = j;
                y = k;
                cost = curr[j][k];
                if (y != 26)
                {
                    cost += abs(y / 6 - digit / 6) + abs(y % 6 - digit % 6);
                }
                y = digit;
                if (y < x) swap(x, y);
                next[x][y] = min(cost, next[x][y]);
            }
        }
        curr = next;
    }
    int result = INT_MAX;
    for (size_t i = 0; i <= 26; i++)
    {
        for (size_t j = 0; j <= 26; j++)
        {
            result = min(result, curr[i][j]);
        }
    }
    return result;
}

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
int LeetCodeDP::minCut(string s)
{
    if (s.empty()) return 0;
    vector<vector<int>> pal(s.size(), vector<int>(s.size()));
    vector<int> dp(s.size(), s.size());
    dp[0] = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            if (s[j] != s[i]) continue;
            if (i - j > 2 && pal[j+1][i-1] != 1) continue;
            pal[j][i] = 1;
            // s.substring[j][i] is palindrome
            if (j == 0) dp[i] = 0;
            else
            {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[s.size() - 1];
}

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
int LeetCodeDP::minDifficulty(vector<int>& jobDifficulty, int d)
{
    int n = jobDifficulty.size();
    if (n < d) return -1;
    vector<vector<int>> dp(n, vector<int>(d, INT_MAX));
    
    for (int i = 0; i < n; i++)
    {
        int max_num = jobDifficulty[i];
        for (int j = i - 1; j >= 0; j--)
        {
            for (int k = 1; k < d; k++)
            {
                if (k - 1 > j) break;
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + max_num);
            }
            max_num = max(max_num, jobDifficulty[j]);
        }
        dp[i][0] = max_num;
    }
    return dp[n - 1][d - 1];
}

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
int LeetCodeDP::maxSizeSlices(vector<int>& slices)
{
    size_t n = slices.size() / 3;
    size_t size = slices.size();
    vector<vector<int>> dp(size, vector<int>(n));
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            dp[i][j] = slices[i];
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (i > 1 && j > 0)
            {
                dp[i][j] = max(dp[i][j], slices[i] + dp[i - 2][j - 1]);
            }
        }
    }
    int result = dp[size - 2][n - 1];
    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            dp[i][j] = slices[i];
            if (i > 1) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (i > 2 && j > 0)
            {
                dp[i][j] = max(dp[i][j], slices[i] + dp[i - 2][j - 1]);
            }
        }
    }
    result = max(result, dp[size - 1][n - 1]);
    
    return result;
}

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
string LeetCodeDP::stoneGameIII(vector<int>& stoneValue)
{
    int n = stoneValue.size();
    vector<int> sum(n);
    vector<int> dp(n, INT_MIN);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1) sum[i] = 0 + stoneValue[i];
        else sum[i] = sum[i + 1] + stoneValue[i];
        int s = 0;
        for (int j = 0; j < 3 && i + j < n; j++)
        {
            s += stoneValue[i + j];
            int p = ((i + j == n - 1) ? 0 : (sum[i +j + 1] - dp[i + j + 1])) + s;
            dp[i] = max(dp[i], p);
        }
    }
    if (dp[0] > sum[0] - dp[0])
    {
        return "Alice";
    }
    else if (dp[0] < sum[0] - dp[0])
    {
        return "Bob";
    }
    else
    {
        return "Tie";
    }
}

/// <summary>
/// Leet code #1411. Number of Ways to Paint N × 3 Grid
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
int LeetCodeDP::numOfWays(int n)
{
    long long M = 1000000007;
    vector<vector<long long>> dp(n, vector<long long>(2));

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            // pattern 121
            dp[i][0] = 6;
            // pattern 123
            dp[i][1] = 6;
        }
        else
        {
            // pattern 121
            dp[i][0] = (dp[i - 1][0] * 3 + dp[i - 1][1] * 2) % M;
            // pattern 123
            dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1] * 2) % M;
        }
    }
    return (int)((dp[n - 1][0] + dp[n - 1][1]) % M);
}

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
int LeetCodeDP::numberOfArrays(string s, int k)
{
    int M = 1000000007;
    vector<int> dp(s.size());
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == 0) dp[i] = 1;
        // can not start zero
        if (s[i] == '0') continue;

        for (size_t j = i + 1; j <= s.size(); j++)
        {
            string str = s.substr(i, j - i);
            if (atoll(str.c_str()) > (long long)k) break;
            if (j == s.size())
            {
                result = (result + dp[i]) % M;
            }
            else
            {
                dp[j] = (dp[j] + dp[i]) % M;
            }
        }
    }
    return result;
}

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
int LeetCodeDP::numOfArrays(int n, int m, int k)
{
    long long M = 1000000007;
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k, vector<long long>(m)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            long long sum = 0;
            for (int l = 0; l < m; l++)
            {
                if (i == 0)
                {
                    if (j == 0) dp[i][j][l] = 1;
                    else break;
                }
                else
                {
                    // for any cost l with max j when expand array,
                    // you can put any number <= j.
                    dp[i][j][l] = (dp[i][j][l] + dp[i - 1][j][l] * ((long long)l + 1)) % M;
                    if (j > 0 && l > 0)
                    {
                        // for any cost j and max number as l, 
                        // you can choose previous array as i-1 
                        // with cost j -1 and maxmimum number from 1 to l-1 
                        dp[i][j][l] = (dp[i][j][l] + sum) % M;
                    }
                    if (j > 0)
                    {
                        sum = (sum + dp[i - 1][j - 1][l]) % M;
                    }
                }
            }
        }
    }
    long long result = 0;
    for (int i = 0; i < m; i++)
    {
        result = (result + dp[n - 1][k - 1][i]) % M;
    }
    return (int)result;
}

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
int LeetCodeDP::numberWays(vector<vector<int>>& hats)
{
    int M = 1000000007;
    int n = hats.size();
    vector<int> prev(1 << n);
    int result = 0;
    prev[0] = 1;
    vector<vector<int>> hat_owners(40);

    for (size_t i = 0; i < hats.size(); i++)
    {
        for (size_t j = 0; j < hats[i].size(); j++)
        {
            int h = hats[i][j] - 1;
            hat_owners[h].push_back(i);
        }
    }

    for (size_t i = 0; i < hat_owners.size(); i++)
    {
        vector<int> curr = prev;
        result = 0;
        for (size_t j = 0; j < hat_owners[i].size(); j++)
        {
            for (int k = 0; k < (1 << n); k++)
            {
                if (prev[k] == 0) continue;
                int bag = k;
                if ((bag & (1 << hat_owners[i][j])) == 0)
                {
                    bag |= (1 << hat_owners[i][j]);
                    curr[bag] = (curr[bag] + prev[k]) % M;
                }
            }
        }
        prev = curr;
    }
    result = prev[(1 << n) - 1];
    return result;
}

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
int LeetCodeDP::ways(vector<string>& pizza, int k)
{
    int M = 1000000007;
    int r = pizza.size();
    int c = pizza[0].size();
    vector<vector<int>> apples(r, vector<int>(c));
    vector<vector<vector<int>>> dp(pizza.size(), vector<vector<int>>(pizza[0].size(), vector<int>(k)));
    int result = 0;
    for (int i = r-1; i >= 0; i--)
    {
        for (int j = c-1; j >= 0; j--)
        { 
            if (pizza[i][j] == 'A')
            {
                apples[i][j] = 1;
            }
            if (i < r - 1) apples[i][j] += apples[i + 1][j];
            if (j < c - 1) apples[i][j] += apples[i][j+1];
            if (i < r - 1 && j < c -1) apples[i][j] -= apples[i+1][j + 1];
        }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (apples[i][j] == 0) break;
            for (int l = 1; l < k; l++)
            {
                for (int x = 0; x < i; x++)
                {
                    if (apples[x][j] - apples[i][j] > 0)
                    {
                        dp[i][j][l] = (dp[i][j][l] + dp[x][j][l - 1]) % M;
                    }
                }
                for (int x = 0; x < j; x++)
                {
                    if (apples[i][x] - apples[i][j] > 0)
                    {
                        dp[i][j][l] = (dp[i][j][l] + dp[i][x][l - 1]) % M;
                    }
                }
            }
            result = (result + dp[i][j][k - 1]) % M;
        }
    }
    return result;
}

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
string LeetCodeDP::largestNumber(vector<int>& cost, int target)
{
    vector<pair<int, int>> dp(target+1);
    dp[target].first = 1;
    for (int i = target; i > 0; i--)
    {
        if (dp[i].first == 0) continue;
        for (size_t j = 0; j < cost.size(); j++)
        {
            pair<int, int> next = dp[i];
            next.first++;
            next.second = j;
            int index = i - cost[j];
            if (index < 0) continue;
            if (dp[index].first < next.first || 
                (dp[index].first == next.first && dp[index].second < next.second))
            {
                dp[index] = next;
            }
        }
    }
    string result = "";
    if (dp[0].first == 0) result = "0";
    else
    {
        for (int i = 0; i < target; i += cost[dp[i].second])
        {
            result.push_back('1' + dp[i].second);
        }
    }
    return result;
}

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
int LeetCodeDP::maxDotProduct(vector<int>& nums1, vector<int>& nums2)
{
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));
    for (size_t i = 0; i < nums1.size(); i++)
    {
        for (size_t j = 0; j < nums2.size(); j++)
        {
            dp[i][j] = nums1[i] * nums2[j];
            if (i > 0 && j > 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + dp[i][j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j > 0)dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    return dp[nums1.size() - 1][nums2.size() - 1];
}

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
int LeetCodeDP::cherryPickupII(vector<vector<int>>& grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
    dp[0][0][col-1] = grid[0][0] + grid[0][col-1];
    for (size_t i = 1; i < grid.size(); i++)
    {
        for (int robot1 = 0; robot1 < col; robot1++)
        {
            for (int robot2 = robot1 + 1; robot2 < col; robot2++)
            {
                if (dp[i-1][robot1][robot2] == -1) continue;
                for (int d1 = -1; d1 < 2; d1++)
                {
                    int next_robot1 = robot1 + d1;
                    if (next_robot1 < 0 || next_robot1 >= col)
                    {
                        continue;
                    }
                    for (int d2 = -1; d2 < 2; d2++)
                    {
                        int next_robot2 = robot2 + d2;
                        if (next_robot2 < 0 || next_robot2 >= col)
                        {
                            continue;
                        }
                        int sum = dp[i-1][robot1][robot2];
                        sum += grid[i][next_robot1];
                        if (next_robot1 != next_robot2)
                        {
                            sum += grid[i][next_robot2];
                        }
                        int x = min(next_robot1, next_robot2);
                        int y = max(next_robot1, next_robot2);
                        dp[i][x][y] = max(dp[i][x][y], sum);
                    }
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result = max(result, dp[row - 1][i][j]);
        }
    }
    return result;
}

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
int LeetCodeDP::minCost(vector<int>& houses, vector<vector<int>>& cost,
    int m, int n, int target)
{
    vector<vector<pair<int, int>>> prev;
    for (size_t i = 0; i < houses.size(); i++)
    {
        vector<vector<pair<int, int>>> dp = vector<vector<pair<int, int>>>(target, vector<pair<int, int>>());
        if (i == 0)
        {
            if (houses[i] != 0)
            {
                dp[0].push_back(make_pair(houses[i] - 1, 0));
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    dp[0].push_back(make_pair(j, cost[0][j]));
                }
            }
        }
        else
        {
            if (houses[i] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int t = 0; t < target; t++)
                    {
                        int same = INT_MAX;
                        int diff = INT_MAX;
                        for (size_t k = 0; k < prev[t].size(); k++)
                        {
                            if (prev[t][k].first == j)
                            {
                                same = min(same, prev[t][k].second + cost[i][j]);
                            }
                            else
                            {
                                diff = min(diff, prev[t][k].second + cost[i][j]);
                            }
                        }
                        if (same != INT_MAX) dp[t].push_back(make_pair(j, same));
                        if (t + 1 < target && diff != INT_MAX)
                        {
                            dp[t + 1].push_back(make_pair(j, diff));
                        }
                    }
                }
            }
            else
            {
                for (int t = 0; t < target; t++)
                {
                    int same = INT_MAX;
                    int diff = INT_MAX;
                    for (size_t k = 0; k < prev[t].size(); k++)
                    {
                        if (prev[t][k].first == houses[i] - 1)
                        {
                            same = min(same, prev[t][k].second);
                        }
                        else
                        {
                            diff = min(diff, prev[t][k].second);
                        }
                    }
                    if (same != INT_MAX) dp[t].push_back(make_pair(houses[i] - 1, same));
                    if (t + 1 < target && diff != INT_MAX)
                    {
                        dp[t + 1].push_back(make_pair(houses[i] - 1, diff));
                    }
                }
            }
        }
        prev = dp;
    }
    int result = INT_MAX;
    for (size_t i = 0; i < prev[target - 1].size(); i++)
    {
        result = min(result, prev[target - 1][i].second);
    }
    if (result == INT_MAX) result = -1;
    return result;
}

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
int LeetCodeDP::minDistance(vector<int>& houses, int k)
{
    sort(houses.begin(), houses.end());
    int n = houses.size();
    vector<vector<int>> dist(n, vector<int>(n));
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i + j >= n) continue;
            if (j == 1) dist[i][i + j] = houses[i + 1] - houses[i];
            else
            {
                dist[i][i + j] = houses[i + 1] - houses[i];
                dist[i][i + j] += houses[i + j] - houses[i + j - 1];
                dist[i][i + j] += dist[i + 1][i + j - 1];
                dist[i][i + j] += houses[i + j - 1] - houses[i + 1];
            }
        }
    }
    vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0) dp[i][j] = 0;
            else if (j == 0)
            {
                dp[i][j] = dist[0][i];
            }
            else
            {
                for (int m = 0; m < i; m++)
                {
                    dp[i][j] = min(dp[i][j], dp[m][j - 1] + dist[m + 1][i]);
                }
            }
        }
    }
    return dp[n - 1][k - 1];
}

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
bool LeetCodeDP::winnerSquareGame(int n)
{
    vector<int> sqaure;
    for (int i = 1; i <= n; i++)
    {
        int sq = i * i;
        if (sq > n) break;
        sqaure.push_back(sq);
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (size_t j = 0; j < sqaure.size(); j++)
        {
            int next = i + sqaure[j];
            if (next > n) break;
            if (dp[next] == 1) continue;
            dp[next] = 1 - dp[i];
        }
    }
    return dp[n] == 1;
}

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
int LeetCodeDP::maxNonOverlapping(vector<int>& nums, int target)
{
    unordered_map<int, int> sum_map;
    vector<int> dp(nums.size());
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == target) dp[i] = 1;
        if (sum_map.count(sum - target) > 0)
        {
            dp[i] = max(dp[i], dp[sum_map[sum - target]] + 1);
        }
        sum_map[sum] = i;
        if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    }
    return dp[nums.size() - 1];
}

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
int LeetCodeDP::minCost(int n, vector<int>& cuts)
{
    sort(cuts.begin(), cuts.end());
    vector<int> arr;
    for (size_t i = 0; i <= cuts.size(); i++)
    {
        if (i == 0) arr.push_back(cuts[i]);
        else if (i == cuts.size())
        {
            arr.push_back(n - cuts[cuts.size() - 1]);
        }
        else
        {
            arr.push_back(cuts[i] -cuts[i-1]);
        }
    }
    size_t size = arr.size();
    vector<vector<int>>dp(size, vector<int>(size, INT_MAX));
    for (int k = 0; k < (int)arr.size(); k++)
    {
        for (int i = 0; i < (int)arr.size(); i++)
        {
            if (k == 0)
            {
                dp[i][i] = 0;
            }
            else
            {
                if (i + k >= (int)arr.size()) break;
                int sum = 0;
                for (int j = i; j < i + k; j++)
                {
                    dp[i][i + k] = min(dp[i][j] + dp[j + 1][i + k], dp[i][i + k]);
                    sum += arr[j];
                }
                sum += arr[i + k];
                dp[i][i + k] += sum;
            }
        }
    }
    return dp[0][size - 1];
}

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
int LeetCodeDP::minDays(int n)
{
    unordered_map<int, int> dp;
    queue<pair<int, int>> queue;
    dp[n] = 0;
    queue.push(make_pair(n, 0));
    while (!queue.empty())
    {
        pair<int, int> p = queue.front();
        queue.pop();
        if (dp[p.first] < p.second)
        {
            continue;
        }
        pair<int, int> pair;
        if (p.first == 1)
        {
            pair.first = p.first -1;
            pair.second = 1 + p.second;
            if (dp.count(pair.first) == 0 || dp[pair.first] > pair.second)
            {
                dp[pair.first] = pair.second;
                queue.push(pair);
            }
        }
        if (p.first >= 3)
        { 
            pair.first = p.first / 3;
            pair.second = 1 + p.first % 3 + p.second;
            if (dp.count(pair.first) == 0 || dp[pair.first] > pair.second)
            {
                dp[pair.first] = pair.second;
                queue.push(pair);
            }
        }
        if (p.first >= 2)
        {
            pair.first = p.first / 2;
            pair.second = 1 + p.first % 2 + p.second;
            if (dp.count(pair.first) == 0 || dp[pair.first] > pair.second)
            {
                dp[pair.first] = pair.second;
                queue.push(pair);
            }
        }
    }
    return dp[0];
}

/// <summary>
/// Leet code #1563. Stone Game V
/// </summary>
int LeetCodeDP::stoneGameV(vector<int>& stoneValue, int first, int last, vector<int>& sum, vector<vector<int>>& dp)
{
    if (first == last) return 0;
    else if (dp[first][last] > 0) return dp[first][last];
    for (int i = first; i < last; i++)
    {
        int part1 = sum[i + 1] - sum[first];
        int part2 = sum[last + 1] - sum[i + 1];
        int sum_total = 0;
        if (part1 < part2)
        {
            sum_total = part1 + stoneGameV(stoneValue, first, i, sum, dp);
        }
        else if (part1 > part2)
        {
            sum_total = part2 + stoneGameV(stoneValue, i + 1, last, sum, dp);
        }
        else
        {
            sum_total = part1 + 
                max(stoneGameV(stoneValue, first, i, sum, dp), 
                    stoneGameV(stoneValue, i + 1, last, sum, dp));
        }
        dp[first][last] = max(dp[first][last], sum_total);
    }
    return dp[first][last];
}


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
int LeetCodeDP::stoneGameV(vector<int>& stoneValue)
{
    int n = stoneValue.size();
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + stoneValue[i];
    }
    vector<vector<int>> dp(n, vector<int>(n));
    return stoneGameV(stoneValue, 0, n - 1, sum, dp);
}

/// <summary>
/// Leet code #1569. Number of Ways to Reorder Array to Get Same BST
/// </summary>
long long LeetCodeDP::numOfWays(vector<int>& nums, vector<vector<int>>& permutation)
{
    long long M = 1000000007;
    if (nums.empty() || nums.size() == 1) return 1;
    int first = nums[0];
    vector<int> left;
    vector<int> right;

    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] < first) left.push_back(nums[i]);
        else right.push_back(nums[i]);
    }

    long long result = permutation[nums.size() - 1 - 1][left.size()];
    long long left_size = numOfWays(left, permutation);
    long long right_size = numOfWays(right, permutation);
    result = (result * left_size) % M;
    result = (result * right_size) % M;

    return result;
}

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
int LeetCodeDP::numOfWays(vector<int>& nums)
{
    int M = 1000000007;
    vector<vector<int>> permutation(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        permutation[i] = vector<int>(i + 2);
        for (size_t j = 0; j < i + 2; j++)
        { 
            if (j == 0 || j == i + 1) permutation[i][j] = 1;
            else
            {
                permutation[i][j] = (permutation[i - 1][j - 1] + permutation[i - 1][j]) % M;
            }
        }
    }
    return (int)numOfWays(nums, permutation) - 1;
}

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
/// Return the maximum non-negative product modulo 10^9 + 7. If the maximum 
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
int LeetCodeDP::maxProductPath(vector<vector<int>>& grid)
{
    long long M = 1000000007;
    vector < vector<pair<long long, long long>>> dp(grid.size(), vector<pair<long long, long long>>(grid[0].size()));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            dp[i][j].first = LLONG_MAX;
            dp[i][j].second = LLONG_MIN;
            if (i == 0 && j == 0)
            {
                dp[i][j].first = grid[i][j];
                dp[i][j].second = grid[i][j];
            }
            if (i > 0)
            {
                long long min_val = dp[i - 1][j].first * (long long)grid[i][j];
                long long max_val = dp[i - 1][j].second * (long long)grid[i][j];
                if (min_val > max_val) swap(min_val, max_val);

                dp[i][j].first = min(dp[i][j].first, min_val);
                dp[i][j].second = max(dp[i][j].first, max_val);
            }
            if (j > 0)
            {
                long long min_val = dp[i][j - 1].first * (long long)grid[i][j];
                long long max_val = dp[i][j - 1].second * (long long)grid[i][j];
                if (min_val > max_val) swap(min_val, max_val);

                dp[i][j].first = min(dp[i][j].first, min_val);
                dp[i][j].second = max(dp[i][j].second, max_val);
            }
        }
    }
    long long min_val = dp[grid.size() - 1][grid[0].size() - 1].first;
    long long max_val = dp[grid.size() - 1][grid[0].size() - 1].second;
    long long result = max(min_val, max_val);
    if (result < 0) return -1;
    else return (int)(result % M);
}

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
int LeetCodeDP::numberOfSets(int n, int k)
{
    int M = 1000000007;
    vector<vector<int>>dp(n+k, vector<int>(2*k+1));
    for (int i = 0; i <= n+k-1; i++)
    {
        for (int j = 0; j <= 2*k; j++)
        {
            if (j > i) break;
            if (j == 0) dp[i][j] = 1;
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % M;
            }
        }
    }
    return dp[n + k - 1][2*k];
}

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
int LeetCodeDP::numWays(vector<string>& words, string target)
{
    long long M = 1000000007;
    vector<vector<int>> char_count(26, vector<int>(words[0].size()));
    for (size_t i = 0; i < words.size(); i++)
    {
        for (size_t j = 0; j < words[i].size(); j++)
        {
            char_count[words[i][j] - 'a'][j]++;
        }
    }
    // the answer until kth position in target
    vector<long long> result(words[0].size());
    for (size_t i = 0; i < target.size(); i++)
    {
        for (int j = words[0].size() - 1; j >= 0; j--)
        {
            if (i == 0) result[j] = char_count[target[i] - 'a'][j];
            else if (j == 0)
            {
                result[j] = 0;
            }
            else
            {
                // the answer to kth position in target is built from answer to k-1th 
                result[j] = (result[j -1] * (long long)char_count[target[i] - 'a'][j]) % M;
            }
        }
        // calculate accumulated sum
        for (size_t j = 0; j < words[0].size()-1; j++)
        {
            result[j + 1] = (result[j + 1] + result[j]) % M;
        }
    }
    return (int)result[words[0].size() - 1];
}

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
int LeetCodeDP::countVowelStrings(int n)
{
    vector<vector<int>> count(2, vector<int>(5));
    vector<int>& prev = count[0];
    vector<int>& curr = count[1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0) curr[j] = 1;
            else curr[j] = prev[j];
            if (j > 0) curr[j] += curr[j - 1];
        }
        swap(prev, curr);
    }
    return prev[4];
}

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
int LeetCodeDP::minimumDeletions(string s)
{
    vector<pair<int, int>> dp(s.size());
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            dp[i].first = (s[i] == 'a' ? 0 : 1);
            dp[i].second = (s[i] == 'b' ? 0 : 1);
        }
        else
        {
            dp[i].first = dp[i - 1].first + (s[i] == 'a' ? 0 : 1);
            dp[i].second = min(dp[i - 1].first, dp[i - 1].second) + (s[i] == 'b' ? 0 : 1);
        }
    }
    return min(dp.back().first, dp.back().second);
}

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
int LeetCodeDP::stoneGameVII(vector<int>& stones)
{
    int n = stones.size();
    vector<int> sum(n+1);
    sum[0] = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) sum[i+1] = sum[i] + stones[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j >= n) break;
            if (i == 1) dp[j][j + 1] = max(stones[j], stones[j+1]);
            else
            {
                dp[j][j + i] = max(sum[j + i] - sum[j] - dp[j][j + i - 1], 
                                   sum[j + i + 1] - sum[j + 1] - dp[j + 1][j + i]);
            }
        }
    }
    return dp[0][n - 1];
}

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
int LeetCodeDP::boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight)
{
    int weight_count = 0;
    int n = boxes.size();
    // ports switch, trips
    vector<pair<int, int>> dp(n);
    int first = 0;
    int index = 0;
    for (int index = 0; index < n; index++)
    {
        weight_count += boxes[index][1];
        if (index == 0) dp[index].first = 0;
        else if (boxes[index][0] == boxes[index - 1][0])
        {
            dp[index].first = dp[index - 1].first;
        }
        else
        {
            dp[index].first = dp[index - 1].first + 1;
        }
        while ((index - first + 1 > maxBoxes) || (weight_count > maxWeight) ||
               (first < index && first > 0 && dp[first].second == dp[first - 1].second))
        {
            weight_count -= boxes[first][1];
            first++;
        }
        dp[index].second = dp[index].first - dp[first].first + 2;
        if (first > 0)
        {
            dp[index].second += dp[first -1].second;
        }
    }
    return dp[boxes.size() - 1].second;
}

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
int LeetCodeDP::waysToDistribute(int n, int k)
{
    long long M = 1000000007;
    vector<vector<long long>> dp(n+1, vector<long long>(k+1));
    for (int j = 1; j <= k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            // more bags than candies
            if (j > i) continue;
            // only one bag
            if (j == 1) dp[i][j] = 1;
            else
            {
                // a new candy can be placed in any bag allocated by i - 1 candies
                dp[i][j] = (dp[i][j] + (dp[i - 1][j] * j) % M) % M;
                // a new candy can only be placed in a new empty bag
                dp[i][j] = (dp[i][j] + dp[i - 1][j-1]) % M ;
            }
        }
    }
    return (int)dp[n][k];
}

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
int LeetCodeDP::longestPalindromeSubseqII(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> edge(n, vector<int>(n));
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i + k >= n) break;
            if (s[i] == s[i + k])
            {
                if (k == 1)
                {
                    dp[i][i + k] = 2;
                }
                else if (dp[i + 1][i + k - 1] == 0 || (s[i] - 'a') != edge[i + 1][i + k - 1])
                {
                    dp[i][i + k] = dp[i + 1][i + k - 1] + 2;
                }
                edge[i][i + k] = s[i] - 'a';
            }
            else
            {
                dp[i][i + k] = dp[i + 1][i + k - 1];
                edge[i][i + k] = edge[i + 1][i + k - 1];
            }
            if (dp[i][i + k - 1] > dp[i][i + k])
            {
                dp[i][i + k] = dp[i][i + k - 1];
                edge[i][i + k] = edge[i][i + k - 1];
            }
            if (dp[i + 1][i + k] > dp[i][i + k])
            {
                dp[i][i + k] = dp[i + 1][i + k];
                edge[i][i + k] = edge[i + 1][i + k];
            }
        }
    }
    return dp[0][n - 1];
}

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
int LeetCodeDP::maxSumAfterOperation(vector<int>& nums)
{
    int sum = 0, sum_op = 0;
    int result = INT_MIN;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            sum = nums[i];
            sum_op = nums[i] * nums[i];
        }
        else
        {
            sum_op = max(sum + nums[i] * nums[i], sum_op + nums[i]);
            sum = max(0, sum + nums[i]);
        }
        result = max(result, sum_op);
    }
    return result;
}

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
int LeetCodeDP::closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target)
{
    int delta = INT_MAX;
    set<int> topppings = { 0 };
    for (size_t i = 0; i < toppingCosts.size(); i++)
    {
        vector<int>arr(topppings.begin(), topppings.end());
        for (size_t j = 0; j < arr.size(); j++)
        {
            topppings.insert(arr[j] + toppingCosts[i]);
            topppings.insert(arr[j] + 2 * toppingCosts[i]);
        }
    }
    for (size_t i = 0; i < baseCosts.size(); i++)
    {
        auto itr = topppings.lower_bound(target - baseCosts[i]);
        if (itr != topppings.begin())
        {
            int delta1 = *prev(itr) - (target - baseCosts[i]);
            if (abs(delta1) <= abs(delta)) delta = delta1;
        }
        if (itr != topppings.end())
        {
            int delta1 = *itr - (target - baseCosts[i]);
            if (abs(delta1) < abs(delta)) delta = delta1;
        }
    }
    return target + delta;
}


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
int LeetCodeDP::minChanges(vector<int>& nums, int k)
{
    vector<vector<int>> fre(k, vector<int>(1024));
    vector<vector<int>> dp(k, vector<int>(1024));
    vector<unordered_set<int>> pos_nums(k);
    int prev_best = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        fre[i % k][nums[i]]++;
        pos_nums[i % k].insert(nums[i]);
    }
    for (int i = 0; i < k; i++)
    {
        int cnt_pos = (nums.size() + k - i -1) / k;
        int curr_best = INT_MAX;
        for (int j = 0; j < 1024; j++)
        {
            if (i == 0)
            {
                dp[i][j] = cnt_pos - fre[i][j];
            }
            else
            {
                dp[i][j] = prev_best + cnt_pos;
                for (auto n : pos_nums[i])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j ^ n] + cnt_pos - fre[i][n]);

                }
            }
            curr_best = min(curr_best, dp[i][j]);
        }
        prev_best = curr_best;
    }
    return dp[k - 1][0];
}

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
bool LeetCodeDP::checkPartitioning(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<int> split(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // the substring is palindrome 
        if ((s[0] == s[i]) && (i < 3 || dp[1][i - 1] == 1))
        {
            dp[0][i] = 1;
        }
        // check all prefix
        for (int j = 0; j < i; j++)
        {
            // postfix is palindrome
            if ((s[j + 1] == s[i]) && (i - j - 1 < 3 || dp[j + 2][i - 1] == 1))
            {
                dp[j + 1][i] = 1;
            }
            if (dp[j + 1][i] == 1)
            {
                if (dp[0][j] == 1) split[i] = 1;
                if (i == n - 1 && split[j] == 1) return true;
            }
        }
    }
    return false;
}

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
int LeetCodeDP::longestPalindrome(string word1, string word2)
{
    string word = word1 + word2;
    int result = 0;
    vector<vector<int>> dp(word.size(), vector<int>(word.size()));
    for (size_t j = 0; j < word.size(); j++)
    {
        for (int i = j; i >= 0; i--)
        {
            if (word[i] == word[j])
            {
                if (j - i == 0) dp[i][j] = 1;
                else if (j - i == 1) dp[i][j] = 2;
                else dp[i][j] = max(dp[i + 1][j - 1] + 2, dp[i][j]);
                if (i < (int)word1.size() && j >= (int)word1.size()) result = max(dp[i][j], result);
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    return result;
}


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
int LeetCodeDP::minSideJumps(vector<int>& obstacles)
{
    vector<vector<int>> dp(obstacles.size(), vector<int>(3));
    for (size_t i = 0; i < obstacles.size(); i++)
    {
        if (i == 0)
        {
            dp[i][1] = 0;
            dp[i][0] = 1;
            dp[i][2] = 1;
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = INT_MAX;
                if (obstacles[i] == j + 1) continue;
                if (dp[i - 1][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            for (int j = 0; j < 3; j++)
            {
                if (obstacles[i] == j + 1) continue;
                for (int k = 0; k < 3; k++)
                {
                    if (j != k)
                    {
                        if (dp[i][k] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][k] + 1);
                    }
                 }
            }
        }
    }
    int result = dp[obstacles.size() - 1][0];
    result = min(result, dp[obstacles.size() - 1][1]);
    result = min(result, dp[obstacles.size() - 1][2]);
    return result;
}


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
int LeetCodeDP::maxValue(vector<vector<int>>& events, int k)
{
    map<int, vector<int>> event_values;
    sort(events.begin(), events.end());
    vector<int> prev_event = { 0 };
    int result = 0;
    for (size_t i = 0; i < events.size(); i++)
    {
        int start = events[i][0];
        int end = events[i][1];
        int value = events[i][2];

        // collect all previous event maximum values
        while (!event_values.empty() && event_values.begin()->first < start)
        {
            auto itr = event_values.begin();
            for (size_t j = 0; j < itr->second.size(); j++)
            {
                if (j >= prev_event.size())
                {
                    prev_event.push_back(itr->second[j]);
                }
                else
                {
                    prev_event[j] = max(prev_event[j], itr->second[j]);
                }
            }
            event_values.erase(event_values.begin());
        }

        if (event_values.count(end) == 0)
        {
            event_values[end] = { 0 };
        }
        for (int j = 0; (j < (int)prev_event.size() && j < k); j++)
        {
            if (j + 1 >= (int)event_values[end].size())
            {
                event_values[end].push_back(prev_event[j] + value);
            }
            else
            {
                event_values[end][j+1] = max(event_values[end][j + 1], prev_event[j] + value);
            }
            result = max(result, event_values[end][j + 1]);
        }
    }
    return result;
}


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
int LeetCodeDP::rearrangeSticks(int n, int k)
{
    vector<vector<int>> dp(k, vector<int>(n));

    int M = 1000000007;
    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (j > 0)
                {
                    int s = (int)(((long long)j * (long long)dp[i][j - 1]) % (long long)M);
                    dp[i][j] = (dp[i][j] + s) % M;
                }
                if (i > 0 && j > 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % M;
                }
            }
        }
    }
    return dp[k - 1][n - 1];
}

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
int LeetCodeDP::stoneGameVIII(vector<int>& stones)
{
    int n = stones.size();
    vector<int> sum(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0) sum[i] = stones[i];
        else sum[i] = sum[i - 1] + stones[i];
    }
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1) dp[i] = 0;
        else if (i == n - 2)
        {
            dp[i] = sum[i+1] - dp[i + 1];
        }
        else
        {
            dp[i] = max(dp[i + 1], sum[i+1] - dp[i + 1]);
        }
    }
    return dp[0];
}

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
int LeetCodeDP::minSkips(vector<int>& dist, int speed, int hoursBefore)
{
    vector<vector<pair<int, int>>> dp(dist.size(), vector<pair<int, int>>(dist.size()));
    for (size_t i = 0; i < dist.size(); i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            dp[i][j].first = INT_MAX;
            if (i == 0)
            {
                pair<int, int> time;
                time.first = dist[i] / speed;
                time.second = dist[i] % speed;
                dp[i][j] = time;
            }
            else
            {
                if (j <= i - 1)
                {
                    pair<int, int> time;
                    time.first = dist[i] / speed + dp[i - 1][j].first;
                    if (dp[i - 1][j].second > 0) time.first++;
                    time.second = dist[i] % speed;
                    dp[i][j] = time;
                }

                if (j > 0)
                {
                    pair<int, int> time;
                    time.first = dist[i] / speed + dp[i - 1][j - 1].first;
                    time.second = dist[i] % speed + dp[i - 1][j - 1].second;
                    if (time.second >= speed)
                    {
                        time.first++;
                        time.second %= speed;
                    }
                    if ((time.first < dp[i][j].first) ||
                        (time.first == dp[i][j].first && time.second < dp[i][j].second))
                    {
                        dp[i][j] = time;
                    }
                }
            }
        }
    }
    int result = -1;
    for (size_t i = 0; i < dist.size(); i++)
    {
        int k = dist.size() - 1;
        if (dp[k][i].second > 0) dp[k][i].first++;
        if (dp[k][i].first <= hoursBefore)
        {
            result = i;
            break;
        }
    }
    return result;
}

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
int LeetCodeDP::countSpecialSubsequences(vector<int>& nums)
{
    long long M = 1000000007;
    vector<long long> dp(3);
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            dp[0] += dp[0] + 1;
            dp[0] %= M;
        }
        else if (nums[i] == 1)
        {
            dp[1] += dp[0] + dp[1];
            dp[1] %= M;
        }
        else if (nums[i] == 2)
        {
            dp[2] += dp[1] + dp[2];
            dp[2] %= M;
        }
    }
    return (int)dp[2];
}

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
long long LeetCodeDP::maxAlternatingSum(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<long long>> dp(n, vector<long long>(2));
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            dp[i][0] = nums[i];
            dp[i][1] = 0;
        }
        else
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - nums[i]);
        }
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

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
int LeetCodeDP::numberOfCombinations(string num)
{
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    int M = 1000000007;
    vector<int> common(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) count = 1;
        else if (num[i] != num[i - 1]) count = 1;
        else count++;
        common[i] = count;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int prev = i - j;
            if (prev < -1) break;
            dp[i][j] = dp[i][j - 1];
            if (num[prev + 1] == '0') continue;
            if (prev == -1)
            {
                dp[i][j] = (dp[i][j] + 1) % M;
            }
            else if (prev - j + 1 >= 0)
            {
                if (common[i] >= i - (prev - j))
                {
                    dp[i][j] = (dp[i][j] + dp[prev][j]) % M;
                }
                else
                {
                    string prev_str = num.substr(prev - j + 1, j);
                    string curr_str = num.substr(prev + 1, j);
                    if (curr_str[0] != '0')
                    {
                        if (prev_str <= curr_str) dp[i][j] = (dp[i][j] + dp[prev][j]) % M;
                        else dp[i][j] = (dp[i][j] + dp[prev][j - 1]) % M;
                    }
                }
            }
            else
            {
                dp[i][j] = (dp[i][j] + dp[prev][prev + 1]) % M;
            }
        }
    }
    return dp[n - 1][n];
}

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
int LeetCodeDP::numberOfUniqueGoodSubsequences(string binary)
{
    int M = 1000000007;
    int result = 0;
    int one = 0, zero = 0, has_zero = 0;
    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            one = (one + zero + 1) % M;
            result = one;
        }
        else
        {
            has_zero = 1;
            zero = (one + zero + 1) % M;
        }
    }
    result = (result + has_zero) % M;
    return result;
}

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
int LeetCodeDP::firstDayBeenInAllRooms(vector<int>& nextVisit)
{
    int M = 1000000007;
    vector<int> dp(nextVisit.size());
    for (size_t i = 0; i < dp.size(); i++)
    {
        if (i == 0) dp[i] = 0;
        else if (nextVisit[i - 1] == i - 1)
        {
            dp[i] = (dp[i - 1] + 2) % M;
        }
        else
        {
            dp[i] = (dp[i - 1] + 2 + (dp[i - 1] - dp[nextVisit[i - 1]] + M) % M) % M;
        }
    }
    return dp[dp.size() - 1];
}

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
int LeetCodeDP::minSpaceWastedKResizing(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(nums.size(), vector<int>(k+1, INT_MAX));

    for (int j = 0; j <= k; j++)
    {
        int max_val = INT_MIN;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (j == 0)
            {
                max_val = max(max_val, nums[i]);
                total += nums[i];
                dp[i][j] = max_val * (i + 1) - total;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                max_val = INT_MIN;
                total = 0;
                for (int s = i; s > 0; s--)
                {
                    max_val = max(max_val, nums[s]);
                    total += nums[s];
                    dp[i][j] = min(dp[i][j], max_val * (i - (s - 1)) - total + dp[s-1][j-1]);
                }
            }
        }
    }
    return dp[n - 1][k];
}

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
long long LeetCodeDP::maxTaxiEarnings(int n, vector<vector<int>>& rides)
{
    long long prev = 0;
    int index = 0;
    vector<long long> dp(n + 1);
    long long result = 0;
    sort(rides.begin(), rides.end());
    for (size_t i = 0; i < rides.size(); i++)
    {
        while (index <= rides[i][0])
        {
            prev = max(prev, dp[index]);
            index++;
        }
        int start = rides[i][0];
        int end = rides[i][1];
        int tip = rides[i][2];
        dp[end] = max(dp[end], prev + (long long)end - (long long)start + (long long)tip);
        result = max(result, dp[end]);
    }
    return result;
}

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
int LeetCodeDP::maxTwoEvents(vector<vector<int>>& events)
{
    sort(events.begin(), events.end());
    map<int, int> dp;
    dp[0] = 0;
    int prev = 0;
    int result = 0;
    for (size_t i = 0; i < events.size(); i++)
    {
        while (!dp.empty() && dp.begin()->first < events[i][0])
        {
            prev = max(prev, dp.begin()->second);
            dp.erase(dp.begin());
        }
        result = max(result, prev + events[i][2]);
        dp[events[i][1]] = max(dp[events[i][1]], events[i][2]);
    }
    return result;
}

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
long long LeetCodeDP::maximumAlternatingSubarraySum(vector<int>& nums)
{
    long long prev_positive = 0;
    long long prev_negative = 0;
    long long result = LONG_MIN;
    for (size_t i = 0; i < nums.size(); i++)
    {
        long long positive_sum = max(prev_negative + nums[i], (long long)nums[i]);
        result = max(result, positive_sum);
        // first elment can not have negative sum
        if (i > 0)
        {
            long long negative_sum = prev_positive - nums[i];
            result = max(result, negative_sum);
            prev_negative = negative_sum;
        }
        prev_positive = positive_sum;
    
    }
    return result;
}

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
int LeetCodeDP::maximalSquare(vector<vector<char>>& matrix)
{
    int result = 0;
    if (matrix.size() == 0 || matrix[0].size() == 0) return result;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '0') dp[i][j] = 0;
            else
            {
                if ((i == 0) || (j == 0))
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                    dp[i][j]++;
                }
                result = max(result, dp[i][j] * dp[i][j]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #174. Dungeon Game 
/// The demons had captured the princess (P) and imprisoned her in the 
/// bottom-right corner of a dungeon. The dungeon consists 
/// of M x N rooms laid out in a 2D grid. Our valiant knight (K) was 
/// initially positioned in the top-left room and must fight 
/// his way through the dungeon to rescue the princess. 
///
/// The knight has an initial health point represented by a positive 
/// integer. If at any point his health point drops to 0 
/// or below, he dies immediately. 
/// Some of the rooms are guarded by demons, so the knight loses health 
/// (negative integers) upon entering these rooms; 
/// other rooms are either empty (0's) or contain magic orbs that 
/// increase the knight's health (positive integers).
/// In order to reach the princess as quickly as possible, the 
/// knight decides to move only 
/// rightward or downward in each step. 
/// Write a function to determine the knight's minimum initial health 
/// so that he is able to rescue the princess.
/// For example, given the dungeon below, the initial health of the 
/// knight must be at least 7 if he follows the optimal path 
/// RIGHT-> RIGHT -> DOWN -> DOWN.
/// -2 (K) -3 3 
/// -5 -10 1 
/// 10 30 -5 (P) 
/// Notes: 
/// 1. The knight's health has no upper bound.
/// 2. Any room can contain threats or power-ups, even the first room the knight 
///    enters and the bottom-right room where the princess is imprisoned.
/// </summary>
int LeetCodeDP::calculateMinimumHP(vector<vector<int>>& dungeon)
{
    if ((dungeon.size() == 0) || dungeon[0].size() == 0) return 1;
    vector<vector<int>> min_hp(dungeon.size());
    for (int i = dungeon.size() - 1; i >= 0; i--)
    {
        min_hp[i] = vector<int>(dungeon[i].size());
        for (int j = dungeon[i].size() - 1; j >= 0; j--)
        {
            if ((i == dungeon.size() - 1) && (j == dungeon[i].size() - 1))
            {
                min_hp[i][j] = max(1, 0 - dungeon[i][j] + 1);
            }
            else if (i == dungeon.size() - 1)
            {
                min_hp[i][j] = max(1, min_hp[i][j + 1] - dungeon[i][j]);
            }
            else if (j == dungeon[i].size() - 1)
            {
                min_hp[i][j] = max(1, min_hp[i + 1][j] - dungeon[i][j]);
            }
            else
            {
                min_hp[i][j] = min(min_hp[i + 1][j], min_hp[i][j + 1]) - dungeon[i][j];
                min_hp[i][j] = max(1, min_hp[i][j]);
            }
        }
    }
    return  min_hp[0][0];
}

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
int LeetCodeDP::minimumCost(string sentence, int k)
{
    int n = sentence.size();
    if (n <= k) return 0;
    vector<int> dp(n, INT_MAX);
    int start = 0;
    int prev = 0;
    int result = INT_MAX;
    while (start < n - k)
    {
        for (int i = start; i <= start + k; i++)
        {
            if (isspace(sentence[i]))
            {
                dp[i] = min(dp[i], prev + (k - (i - start)) * (k - (i - start)));
                if (i + 1 + k >= n) result = min(result, dp[i]);
            }
        }
        while (!isspace(sentence[start])) start++;
        prev = dp[start];
        start++;
    }
    return result;
}

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
int LeetCodeDP::countMaxOrSubsets(vector<int>& nums)
{
    int n = 1 << nums.size();
    int result = 0;
    int max_bits = 0;
    for (int i = 1; i < n; i++)
    {
        int x = i;
        int bits = 0;
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (x == 0) break;
            if (x % 2 == 1) bits |= nums[j];
            x /= 2;
        }
        if (bits > max_bits)
        {
            max_bits = bits;
            result = 1;
        }
        else if (bits == max_bits)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 416. Partition Equal Subset Sum
///                 
/// Medium
///
/// Given an integer array nums, return true if you can partition the array 
/// into two subsets such that the sum of the elements in both subsets is 
/// equal or false otherwise.
///
/// Example 1:
/// Input: nums = [1,5,11,5]
/// Output: true
/// Explanation: The array can be partitioned as [1, 5, 5] and [11].
///
/// Example 2:
/// 
/// Input: nums = [1,2,3,5]
/// Output: false
/// Explanation: The array cannot be partitioned into equal sum subsets.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 200
/// 2. 1 <= nums[i] <= 100
/// </summary>
bool LeetCodeDP::canPartition(vector<int>& nums)
{
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum % 2 == 1) return false;
    sum = sum / 2;
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (int j = sum; j >= nums[i]; j--)
        {
            dp[j] = (dp[j - nums[i]] == 1) ? 1 : dp[j];
        }
    }
    return dp[sum] != 0;
}

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
long long LeetCodeDP::mostPoints(vector<vector<int>>& questions)
{
    int n = questions.size();
    vector<long long> dp(n);
    long long result = 0;
    long long prev = 0;
    for (int i = 0; i < n; i++)
    {
        prev = max(prev, dp[i]);
        long long points = prev + questions[i][0];
        result = max(result, points);
        int next = i + questions[i][1] + 1;
        if (next < n) dp[next] = max(dp[next], points);
    }
    return result;
}

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
int LeetCodeDP::countSubranges(vector<int>& nums1, vector<int>& nums2)
{
    int M = 1000000007;
    unordered_map<int, int> prev;
    int n = nums1.size();
    int result = 0;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += nums1[i];
        sum2 += nums2[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum1 -= nums1[i];
        sum2 -= nums2[i];
        unordered_map<int, int> curr;
        for (auto& itr : prev)
        {
            int value = nums1[i] + itr.first;
            if (value <= sum2)
            {
                curr[value] = (curr[value] + itr.second) % M;
            }
            value = -nums2[i] + itr.first;
            if (value >= 0 - sum1)
            {
                curr[value] = (curr[value] + itr.second) % M;
            }
        }
        curr[nums1[i]] = (curr[nums1[i]] + 1) % M;
        curr[-nums2[i]] = (curr[-nums2[i]] + 1) % M;
        result = (result + curr[0]) % M;
        prev = curr;
    }
    return result;
}

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
int LeetCodeDP::minimumTime(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(2));
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') dp[i][0] = prev;
        else
        {
            dp[i][0] = min(i + 1, prev + 2);
            prev = dp[i][0];
        }
    }
    prev = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0') dp[i][1] = prev;
        else
        {
            dp[i][1] = min(n - i, prev + 2);
            prev = dp[i][1];
        }
    }
    if (n == 1) return dp[0][0];
    int result = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        result = min(result, dp[i][0] + dp[i+1][1]);
    }
    return result;
}
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
int LeetCodeDP::buildWall(int height, int width, vector<int>& bricks)
{
    vector<unordered_map<int, int>> dp(2);
    int M = 1000000007;
    queue<pair<int, int>> queue;
    queue.push(make_pair(0, 0));
    int curr = 0;
    int next = 1;
    while (!queue.empty())
    {
        pair<int, int> pos = queue.front();
        queue.pop();
        if (pos.second == width)
        {
            dp[curr][pos.first]++;
            continue;
        }
        for (size_t i = 0; i < bricks.size(); i++)
        {
            if (pos.second + bricks[i] > width) continue;
            queue.push(make_pair((pos.first << bricks[i]) + 1, pos.second + bricks[i]));
        }
    }
    for (int i = 0; i < height - 1; i++)
    {
        dp[next].clear();
        for (auto itr1 : dp[curr])
        {
            for (auto itr2 : dp[curr])
            {
                if ((itr1.first & itr2.first) == 1)
                {
                    dp[next][itr1.first] = (dp[next][itr1.first] + dp[curr][itr2.first]) % M;
                }
            }
        }
        swap(curr, next);
    }
    int result = 0;
    for (auto itr : dp[curr])
    {
        result = (result + itr.second) % M;
    }
    return result;
}

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
int LeetCodeDP::minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps)
{
    int max_round = 0;
    vector<long long> bestTime(numLaps, LLONG_MAX);
    for (size_t i = 0; i < tires.size(); i++)
    {
        long long fi = tires[i][0];
        long long ri = 1;
        long long sum = 0;
        for (int j = 0; j < numLaps; j++)
        {
            if (fi * ri > changeTime + fi) break;
            sum += fi * ri;
            max_round = max(max_round, j);
            bestTime[j] = min(bestTime[j], sum);
            ri = ri * tires[i][1];
        }
    }
    vector<long long> dp(numLaps, INT_MAX);
    for (int i = 0; i < numLaps; i++)
    {
        if (i <= max_round) dp[i] = bestTime[i];
        for (int j = 0; j <= max_round; j++)
        {
            if (j >= i) break;
            dp[i] = min(dp[i], dp[i - j - 1] + changeTime + bestTime[j]);
        }
    }
    return (int)dp[numLaps - 1];
}

/// <summary>
/// Leet Code 2218. Maximum Value of K Coins From Piles
/// </summary>
int LeetCodeDP::maxValueOfCoins(vector<vector<int>>& piles, int i, int k, vector<vector<int>>& dp)
{
    if (k == 0) return 0;
    if (dp[i][k-1] != 0) return dp[i][k-1];
    int result = 0;
    if (i == (int)piles.size() - 1)
    {
        int sum = 0;
        for (int j = 0; j < k && j < (int)piles[i].size(); j++)
        {
            sum += piles[i][j];
            dp[i][j] = sum;
        }
        result = sum;
    }
    else
    {
        int sum = 0;
        result = max(result, maxValueOfCoins(piles, i + 1, k, dp));
        for (int j = 0; j < k && j < (int)piles[i].size(); j++)
        {
            sum += piles[i][j];
            result = max(result, sum + maxValueOfCoins(piles, i + 1, k - j - 1, dp));
        }
    }
    dp[i][k-1] = result;
    return result;
}

/// <summary>
/// Leet Code 2218. Maximum Value of K Coins From Piles
///                                                                                   
/// Hard
///
/// There are n piles of coins on a table. Each pile consists of a 
/// positive number of coins of assorted denominations.
///
/// In one move, you can choose any coin on top of any pile, remove it, 
/// and add it to your wallet.
///
/// Given a list piles, where piles[i] is a list of integers denoting 
/// the composition of the ith pile from top to bottom, and a positive 
/// integer k, return the maximum total value of coins you can have in 
/// your wallet if you choose exactly k coins optimally.
///
/// Example 1:
/// Input: piles = [[1,100,3],[7,8,9]], k = 2
/// Output: 101
/// Explanation:
/// The above diagram shows the different ways we can choose k coins.
/// The maximum total we can obtain is 101.
///
/// Example 2:
/// Input: piles = [[100],[100],[100],[100],[100],[100],
/// [1,1,1,1,1,1,700]], k = 7
/// Output: 706
/// Explanation:
/// The maximum total can be obtained if we choose all coins from the 
/// last pile.
///
/// Constraints:
/// 1. n == piles.length
/// 2. 1 <= n <= 1000
/// 3. 1 <= piles[i][j] <= 10^5
/// 4. 1 <= k <= sum(piles[i].length) <= 2000
/// </summary>
int LeetCodeDP::maxValueOfCoins(vector<vector<int>>& piles, int k)
{
    vector<vector<int>> dp(piles.size(), vector<int>(k));
    return maxValueOfCoins(piles, 0, k, dp);
}

/// <summary>
/// Leet Code 2222. Number of Ways to Select Buildings
///                                                                                   
/// Medium
///
/// You are given a 0-indexed binary string s which represents the types 
/// of buildings along a street where:
///
/// s[i] = '0' denotes that the ith building is an office and
/// s[i] = '1' denotes that the ith building is a restaurant.
/// As a city official, you would like to select 3 buildings for random 
/// inspection. However, to ensure variety, no two consecutive buildings 
/// out of the selected buildings can be of the same type.
///
/// For example, given s = "001101", we cannot select the 1st, 3rd, and 
/// 5th buildings as that would form "011" which is not allowed due to 
/// having two consecutive buildings of the same type.
/// Return the number of valid ways to select 3 buildings.
///
/// Example 1:
/// Input: s = "001101"
/// Output: 6
/// Explanation: 
/// The following sets of indices selected are valid:
/// - [0,2,4] from "001101" forms "010"
/// - [0,3,4] from "001101" forms "010"
/// - [1,2,4] from "001101" forms "010"
/// - [1,3,4] from "001101" forms "010"
/// - [2,4,5] from "001101" forms "101"
/// - [3,4,5] from "001101" forms "101"
/// No other selection is valid. Thus, there are 6 total ways.
///
/// Example 2:
/// Input: s = "11100"
/// Output: 0
/// Explanation: It can be shown that there are no valid selections.
/// 
/// Constraints:
/// 1. 3 <= s.length <= 10^5
/// 2. s[i] is either '0' or '1'.
/// </summary>
long long LeetCodeDP::numberOfWays(string s)
{
    vector<long long> dp00(s.size());
    vector<long long> dp01(s.size());
    vector<long long> dp10(s.size());
    vector<long long> dp11(s.size());
    vector<long long> dp20(s.size());
    vector<long long> dp21(s.size());
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '0')
        {
            dp00[i]++;
            if (i > 0)
            {
                dp10[i] += dp01[i - 1];
                dp20[i] += dp11[i - 1];
            }
        }
        else
        {
            dp01[i]++;
            if (i > 0)
            {
                dp11[i] += dp00[i - 1];
                dp21[i] += dp10[i - 1];
            }
        }
        if (i > 0)
        {
            dp00[i] += dp00[i - 1];
            dp01[i] += dp01[i - 1];
            dp10[i] += dp10[i - 1];
            dp11[i] += dp11[i - 1];
            dp20[i] += dp20[i - 1];
            dp21[i] += dp21[i - 1];
        }
    }
    long long result = 0;
    result += dp20[s.size() - 1];
    result += dp21[s.size() - 1];
    return result;
}

/// <summary>
/// Leet Code 2209. Minimum White Tiles After Covering With Carpets
///                                                                                   
/// Hard
///
/// You are given a 0-indexed binary string floor, which represents the 
/// colors of tiles on a floor:
///
/// floor[i] = '0' denotes that the ith tile of the floor is colored black.
/// On the other hand, floor[i] = '1' denotes that the ith tile of the 
/// floor is colored white.
/// You are also given numCarpets and carpetLen. You have numCarpets black 
/// carpets, each of length carpetLen tiles. Cover the tiles with the 
/// given carpets such that the number of white tiles still visible is 
/// minimum. Carpets may overlap one another.
///
/// Return the minimum number of white tiles still visible.
/// Example 1:
/// Input: floor = "10110101", numCarpets = 2, carpetLen = 2
/// Output: 2
/// Explanation: 
/// The figure above shows one way of covering the tiles with the carpets 
/// such that only 2 white tiles are visible.
/// No other way of covering the tiles with the carpets can leave less 
/// than 2 white tiles visible.
///
/// Example 2:
/// Input: floor = "11111", numCarpets = 2, carpetLen = 3
/// Output: 0
/// Explanation: 
/// The figure above shows one way of covering the tiles with the carpets 
/// such that no white tiles are visible.
/// Note that the carpets are able to overlap one another.
///
/// Constraints:
/// 1. 1 <= carpetLen <= floor.length <= 1000
/// 2. floor[i] is either '0' or '1'.
/// 3. 1 <= numCarpets <= 1000
/// </summary>
int LeetCodeDP::minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
{
    vector<int> sum(floor.size());
    vector<vector<int>> dp(floor.size(), vector<int>(numCarpets + 1, INT_MAX));
    for (size_t i = 0; i < floor.size(); i++)
    {
        if (floor[i] == '1')
        {
            sum[i] = 1;
        }
        if (i > 0) sum[i] += sum[i - 1];
    }
    for (int i = 0; i < (int)floor.size(); i++)
    {
        int prev = i - carpetLen;
        for (int j = 0; j <= numCarpets; j++)
        {
            if (j == 0)
            {
                dp[i][j] = sum[i];
                continue;
            }
            else
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                if (i > 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + sum[i] - sum[i-1]);
                }
                if (prev < 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = min(dp[i][j], dp[prev][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[prev][j] + sum[i] - sum[prev]);
                }
            }
        }
    }
    return dp[floor.size() - 1][numCarpets];
}

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
int LeetCodeDP::convertArrayII(vector<int>& nums)
{
    int result = INT_MAX;
    set<int> levels = set<int>(nums.begin(), nums.end());
    for (int k = 0; k < 2; k++)
    {
        if (k == 1) reverse(nums.begin(), nums.end());
        vector<int> dp(1001);
        for (size_t i = 0; i < nums.size(); i++)
        {
            int min_ops = INT_MAX;
            for (auto level : levels)
            {
                min_ops = min(min_ops, dp[level]);
                dp[level] = min_ops + std::abs(level - nums[i]);
            }
        }
        for (auto level : levels)
        {
            result = min(result, dp[level]);
        }
    }
    reverse(nums.begin(), nums.end());
    return result;
}

/// <summary>
/// Leet Code 2267. Check if There Is a Valid Parentheses String Path
///                                                           
/// Hard
/// 
/// A parentheses string is a non-empty string consisting only of '(' and 
/// ')'. It is valid if any of the following conditions is true:
///
/// It is ().
/// It can be written as AB (A concatenated with B), where A and B are 
/// valid parentheses strings.
/// It can be written as (A), where A is a valid parentheses string.
/// You are given an m x n matrix of parentheses grid. A valid parentheses 
/// string path in the grid is a path satisfying all of the following 
/// conditions:
///
/// The path starts from the upper left cell (0, 0).
/// The path ends at the bottom-right cell (m - 1, n - 1).
/// The path only ever moves down or right.
/// The resulting parentheses string formed by the path is valid.
/// Return true if there exists a valid parentheses string path in the 
/// grid. Otherwise, return false.
/// 
/// Example 1:
/// Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
/// Output: true
/// Explanation: The above diagram shows two possible paths that form valid 
/// parentheses strings.
/// The first path shown results in the valid parentheses string "()(())".
/// The second path shown results in the valid parentheses string "((()))".
/// Note that there may be other valid parentheses string paths.
///
/// Example 2:
/// Input: grid = [[")",")"],["(","("]]
/// Output: false
/// Explanation: The two possible paths form the parentheses strings "))(" 
/// and ")((". Since neither of them are valid parentheses strings, we 
/// return false.
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 100
/// 4. grid[i][j] is either '(' or ')'.
/// </summary>
bool LeetCodeDP::hasValidPath(vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    if ((m + n - 1) % 2 == 1)
    {
        return false;
    }
    int k = (m + n - 1) / 2;
    vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                if (grid[i][j] == ')') return false;
                else dp[i][j].insert(1);
            }
            if (i > 0)
            {
                for (auto x : dp[i - 1][j])
                {
                    int y = x;
                    if (grid[i][j] == '(') y++;
                    else y--;
                    if (y < 0 || y > min(m + n - 1 - (i + j), k)) continue;
                    dp[i][j].insert(y);
                }
            }
            if (j > 0)
            {
                for (auto x : dp[i][j - 1])
                {
                    int y = x;
                    if (grid[i][j] == '(') y++;
                    else y--;
                    if (y < 0 || y > min(m + n - 1 - (i+j), k)) continue;
                    dp[i][j].insert(y);
                }
            }
        }
    }
    if (dp[m - 1][n - 1].count(0) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet Code 2266. Count Number of Texts
///                                                           
/// Medium
/// 
/// Alice is texting Bob using her phone. The mapping of digits to letters 
/// is shown in the figure below.
///
/// In order to add a letter, Alice has to press the key of the 
/// corresponding digit i times, where i is the position of the letter in 
/// the key.
///
/// For example, to add the letter 's', Alice has to press '7' four times. 
/// Similarly, to add the letter 'k', Alice has to press '5' twice.
/// Note that the digits '0' and '1' do not map to any letters, so Alice 
/// does not use them.
/// However, due to an error in transmission, Bob did not receive Alice's 
/// text message but received a string of pressed keys instead.
///
/// For example, when Alice sent the message "bob", Bob received the 
/// string "2266622".
/// Given a string pressedKeys representing the string received by Bob, 
/// return the total number of possible text messages Alice could have 
/// sent.
///
/// Since the answer may be very large, return it modulo 10^9 + 7.
///
/// Example 1:
/// 
/// Input: pressedKeys = "22233"
/// Output: 8
/// Explanation:
/// The possible text messages Alice could have sent are:
/// "aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae", and "ce".
/// Since there are 8 possible messages, we return 8.
///
/// Example 2:
/// Input: pressedKeys = "222222222222222222222222222222222222"
/// Output: 82876089
/// Explanation:
/// There are 2082876103 possible text messages Alice could have sent.
/// Since we need to return the answer modulo 109 + 7, we return
/// 2082876103 % (10^9 + 7) = 82876089.
///
/// Constraints:
/// 1. 1 <= pressedKeys.length <= 10^5
/// 2. pressedKeys only consists of digits from '2' - '9'.
/// </summary>
int LeetCodeDP::countTexts(string pressedKeys)
{
    vector<int> dp(pressedKeys.size());
    int M = 1000000007;
    for (int i = 0; i < (int)pressedKeys.size(); i++)
    {
        int n = 3;
        if (pressedKeys[i] == '7' || pressedKeys[i] == '9')
        {
            n = 4;
        }
        for (int j = 1; j <= n; j++)
        {
            if (i - j < 0)
            {
                dp[i] = (dp[i] + 1) % M;
                break;
            }
            if (pressedKeys[i] != pressedKeys[i - j])
            {
                dp[i] = (dp[i] + dp[i - j]) % M;
                break;
            }
            else
            {
                dp[i] = (dp[i] + dp[i - j]) % M;
            }
        }
    }
    return dp.back();
}

/// <summary>
/// Leet Code 2291. Maximum Profit From Trading Stocks
///                                                           
/// Medium
/// 
/// You are given two 0-indexed integer arrays of the same length present 
/// and future where present[i] is the current price of the ith stock 
/// and future[i] is the price of the ith stock a year in the future. 
/// You may buy each stock at most once. You are also given an integer 
/// budget representing the amount of money you currently have.
///
/// Return the maximum amount of profit you can make.
/// 
/// Example 1:
/// Input: present = [5,4,6,2,3], future = [8,5,4,3,5], budget = 10
/// Output: 6
/// Explanation: One possible way to maximize your profit is to:
/// Buy the 0th, 3rd, and 4th stocks for a total of 5 + 2 + 3 = 10.
/// Next year, sell all three stocks for a total of 8 + 3 + 5 = 16.
/// The profit you made is 16 - 10 = 6.
/// It can be shown that the maximum profit you can make is 6.
///
/// Example 2:
/// Input: present = [2,2,5], future = [3,4,10], budget = 6
/// Output: 5
/// Explanation: The only possible way to maximize your profit is to:
/// Buy the 2nd stock, and make a profit of 10 - 5 = 5.
/// It can be shown that the maximum profit you can make is 5.
///
/// Example 3:
/// Input: present = [3,3,12], future = [0,3,15], budget = 10
/// Output: 0
/// Explanation: One possible way to maximize your profit is to:
/// Buy the 1st stock, and make a profit of 3 - 3 = 0.
/// It can be shown that the maximum profit you can make is 0.
/// 
/// Constraints:
/// 1. n == present.length == future.length
/// 2. 1 <= n <= 1000
/// 3. 0 <= present[i], future[i] <= 100
/// 4. 0 <= budget <= 1000
/// </summary>
int LeetCodeDP::maximumProfit(vector<int>& present, vector<int>& future, int budget)
{
    vector<int> dp(budget + 1);
    int result = 0;
    for (size_t i = 0; i < present.size(); i++)
    {
        int gain = future[i] - present[i];
        if (gain <= 0) continue;
        for (int j = present[i]; j <= budget; j++)
        {
            dp[j - present[i]] = max(dp[j - present[i]], dp[j] + gain);
            result = max(result, dp[j - present[i]]);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2312. Selling Pieces of Wood
///                                                           
/// Hard
///
/// You are given two integers m and n that represent the height and width 
/// of a rectangular piece of wood. You are also given a 2D integer array 
/// prices, where prices[i] = [hi, wi, pricei] indicates you can sell a 
/// rectangular piece of wood of height hi and width wi for pricei dollars.
///
/// To cut a piece of wood, you must make a vertical or horizontal cut 
/// across the entire height or width of the piece to split it into two 
/// smaller pieces. After cutting a piece of wood into some number of 
/// smaller pieces, you can sell pieces according to prices. You may 
/// sell multiple pieces of the same shape, and you do not have to sell 
/// all the shapes. The grain of the wood makes a difference, so you 
/// cannot rotate a piece to swap its height and width.
///
/// Return the maximum money you can earn after cutting an m x n piece 
/// of wood.
///
/// Note that you can cut the piece of wood as many times as you want.
///
/// Example 1:
/// Input: m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
/// Output: 19
/// Explanation: The diagram above shows a possible scenario. It 
/// consists of:
/// - 2 pieces of wood shaped 2 x 2, selling for a price of 2 * 7 = 14.
/// - 1 piece of wood shaped 2 x 1, selling for a price of 1 * 3 = 3.
/// - 1 piece of wood shaped 1 x 4, selling for a price of 1 * 2 = 2.
/// This obtains a total of 14 + 3 + 2 = 19 money earned.
/// It can be shown that 19 is the maximum amount of money that can be 
/// earned.
///
/// Example 2:
/// Input: m = 4, n = 6, prices = [[3,2,10],[1,4,2],[4,1,3]]
/// Output: 32
/// Explanation: The diagram above shows a possible scenario. It 
/// consists of:
/// - 3 pieces of wood shaped 3 x 2, selling for a price of 3 * 10 = 30.
/// - 1 piece of wood shaped 1 x 4, selling for a price of 1 * 2 = 2.
/// This obtains a total of 30 + 2 = 32 money earned.
/// It can be shown that 32 is the maximum amount of money that can be 
/// earned.
/// Notice that we cannot rotate the 1 x 4 piece of wood to obtain a 4 x 1 
/// piece of wood.
/// 
/// Constraints:
/// 1. 1 <= m, n <= 200
/// 2. 1 <= prices.length <= 2 * 10^4
/// 3. prices[i].length == 3
/// 4. 1 <= hi <= m
/// 5. 1 <= wi <= n
/// 6. 1 <= pricei <= 10^6
/// 7. All the shapes of wood (hi, wi) are pairwise distinct.
/// </summary>
long long LeetCodeDP::sellingWood(int m, int n, vector<vector<int>>& prices)
{
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
    for (size_t i = 0; i < prices.size(); i++)
    {
        dp[prices[i][0]][prices[i][1]] = prices[i][2];
    }
    for (int h = 1; h <= m; h++)
    {
        for (int w = 1; w <= n; w++)
        {
            for (int i = 1; i <= h / 2; i++)
            {
                dp[h][w] = max(dp[h][w], dp[h-i][w] + dp[i][w]);
            }
            for (int i = 1; i <= w / 2; i++)
            {
                dp[h][w] = max(dp[h][w], dp[h][w-i] + dp[h][i]);
            }
        }
    }
    return dp[m][n];
}

/// <summary>
/// Leet Code 2320. Count Number of Ways to Place Houses
///                                                           
/// Medium
///
/// There is a street with n * 2 plots, where there are n plots on each 
/// side of the street. The plots on each side are numbered from 1 to n. 
/// On each plot, a house can be placed.
///
/// Return the number of ways houses can be placed such that no two houses 
/// are adjacent to each other on the same side of the street. Since the 
/// answer may be very large, return it modulo 10^9 + 7.
///
/// Note that if a house is placed on the ith plot on one side of the 
/// street, a house can also be placed on the ith plot on the other side 
/// of the street.
/// 
/// Example 1:
/// Input: n = 1
/// Output: 4
/// Explanation: 
/// Possible arrangements:
/// 1. All plots are empty.
/// 2. A house is placed on one side of the street.
/// 3. A house is placed on the other side of the street.
/// 4. Two houses are placed, one on each side of the street.
///
/// Example 2:
/// Input: n = 2
/// Output: 9
/// Explanation: The 9 possible arrangements are shown in the diagram 
/// above.
///
/// Constraints:
/// 1. 1 <= n <= 10^4
/// </summary>
int LeetCodeDP::countHousePlacements(int n)
{
    int M = 1000000007;
    vector<vector<int>> dp(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        else
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % M;
            dp[i][1] = dp[i - 1][0];
        }
    }
    long long result = ((long long)dp[n - 1][0] + (long long)dp[n - 1][1]) % (long long)M;
    result = (result * result) % (long long)M;
    return (int)result;
}

/// <summary>
/// Leet Code 2318. Number of Distinct Roll Sequences
///                                                           
/// Hard
///
/// You are given an integer n. You roll a fair 6-sided dice n times. 
/// Determine the total number of distinct sequences of rolls possible 
/// such that the following conditions are satisfied:
///
/// The greatest common divisor of any adjacent values in the sequence 
/// is equal to 1.
/// There is at least a gap of 2 rolls between equal valued rolls. 
/// More formally, if the value of the ith roll is equal to the value 
/// of the jth roll, then abs(i - j) > 2.
/// Return the total number of distinct sequences possible. Since the 
/// answer may be very large, return it modulo 10^9 + 7.
/// 
/// Two sequences are considered distinct if at least one element is 
/// different.
///
/// Example 1:
/// Input: n = 4
/// Output: 184
/// Explanation: Some of the possible sequences are (1, 2, 3, 4), 
/// (6, 1, 2, 3), (1, 2, 3, 1), etc.
/// Some invalid sequences are (1, 2, 1, 3), (1, 2, 3, 6).
/// (1, 2, 1, 3) is invalid since the first and third roll have an equal 
/// value and abs(1 - 3) = 2 (i and j are 1-indexed).
/// (1, 2, 3, 6) is invalid since the greatest common divisor of 3 
/// and 6 = 3.
/// There are a total of 184 distinct sequences possible, so we return 184.
///
/// Example 2:
/// Input: n = 2
/// Output: 22
/// Explanation: Some of the possible sequences are (1, 2), (2, 1), (3, 2).
/// Some invalid sequences are (3, 6), (2, 4) since the greatest common 
/// divisor is not equal to 1.
/// There are a total of 22 distinct sequences possible, so we return 22.
/// 
/// Constraints:
/// 
/// 1. 1 <= n <= 10^4
/// </summary>
int LeetCodeDP::distinctSequences(int n)
{
    int M = 1000000007;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(7, vector<int>(7)));
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < 6; j++)
            {
                dp[i][j][0] = 1;
            }
        }
        else if (i == 1)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    if ((j + 1 == k + 1) || ((j + 1) % 2 == 0 && (k + 1) % 2 == 0) ||
                        ((j + 1) % 3 == 0 && (k + 1) % 3 == 0))
                    {
                        continue;
                    }
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][k][0]) % M;
                }
            }
        }
        else 
        {
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    for (int l = 0; l < 6; l++)
                    {
                        if ((j == k) || (j == l) || ((j + 1) % 2 == 0 && (k + 1) % 2 == 0) ||
                            ((j + 1) % 3 == 0 && (k + 1) % 3 == 0))
                        {
                            continue;
                        }
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][k][l]) % M;
                    }
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            result = (result + dp[n - 1][i][j]) % M;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2361. Minimum Costs Using the Train Line
///                                                  
/// Hard
///
/// A train line going through a city has two routes, the regular route 
/// and the express route. Both routes go through the same n + 1 stops 
/// labeled from 0 to n. Initially, you start on the regular route at 
/// stop 0.
/// 
/// You are given two 1-indexed integer arrays regular and express, 
/// both of length n. regular[i] describes the cost it takes to go from 
/// stop i - 1 to stop i using the regular route, and express[i] 
/// describes the cost it takes to go from stop i - 1 to stop i using 
/// the express route.
///
/// You are also given an integer expressCost which represents the 
/// cost to transfer from the regular route to the express route.
///
/// Note that:
///
/// There is no cost to transfer from the express route back to the 
/// regular route.
/// You pay expressCost every time you transfer from the regular 
/// route to the express route.
/// There is no extra cost to stay on the express route.
/// Return a 1-indexed array costs of length n, where costs[i] is 
/// the minimum cost to reach stop i from stop 0.
/// 
/// Note that a stop can be counted as reached from either route.
///
/// Example 1:
/// Input: regular = [1,6,9,5], express = [5,2,3,10], expressCost = 8
/// Output: [1,7,14,19]
/// Explanation: The diagram above shows how to reach stop 4 from 
/// stop 0 with minimum cost.
/// - Take the regular route from stop 0 to stop 1, costing 1.
/// - Take the express route from stop 1 to stop 2, costing 8 + 2 = 10.
/// - Take the express route from stop 2 to stop 3, costing 3.
/// - Take the regular route from stop 3 to stop 4, costing 5.
/// The total cost is 1 + 10 + 3 + 5 = 19.
/// Note that a different route could be taken to reach the other stops 
/// with minimum cost.
///
/// Example 2:
/// Input: regular = [11,5,13], express = [7,10,6], expressCost = 3
/// Output: [10,15,24]
/// Explanation: The diagram above shows how to reach stop 3 from 
/// stop 0 with minimum cost.
/// - Take the express route from stop 0 to stop 1, costing 3 + 7 = 10.
/// - Take the regular route from stop 1 to stop 2, costing 5.
/// - Take the express route from stop 2 to stop 3, costing 3 + 6 = 9.
/// The total cost is 10 + 5 + 9 = 24.
/// Note that the expressCost is paid again to transfer back to the 
/// express route.
/// 
/// Constraints:
/// 1. n == regular.length == express.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= regular[i], express[i], expressCost <= 10^5
/// </summary>
vector<long long> LeetCodeDP::minimumCosts(vector<int>& regular, vector<int>& express, int expressCost)
{
    int n = regular.size();
    vector<long long> regular_cost(n + 1), express_cost(n + 1);
    vector<long long> result(n);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            regular_cost[i] = 0;
            express_cost[i] = expressCost;
        }
        else
        {
            regular_cost[i] = regular_cost[i - 1] + (long long)regular[i - 1];
            express_cost[i] = express_cost[i - 1] + (long long)express[i - 1];
            express_cost[i] = min(express_cost[i], regular_cost[i] + (long long)expressCost);
            regular_cost[i] = min(regular_cost[i], express_cost[i]);
            result[i - 1] = min(regular_cost[i], express_cost[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2369. Check if There is a Valid Partition For The Array
///                                                  
/// Medium
///
/// You are given a 0-indexed integer array nums. You have to partition 
/// the array into one or more contiguous subarrays.
///
/// We call a partition of the array valid if each of the obtained 
/// subarrays satisfies one of the following conditions:
///
/// The subarray consists of exactly 2 equal elements. For example, the 
/// subarray [2,2] is good.
/// The subarray consists of exactly 3 equal elements. For example, the 
/// subarray [4,4,4] is good.
/// The subarray consists of exactly 3 consecutive increasing elements, 
/// that is, the difference between adjacent elements is 1. For example, 
/// the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
/// Return true if the array has at least one valid partition. Otherwise, 
/// return false.
///
/// Example 1:
/// Input: nums = [4,4,4,5,6]
/// Output: true
/// Explanation: The array can be partitioned into the subarrays 
/// [4,4] and [4,5,6].
/// This partition is valid, so we return true.
///
/// Example 2:
/// Input: nums = [1,1,1,2]
/// Output: false
/// Explanation: There is no valid partition for this array.
///
/// Constraints:
/// 1. 2 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^6
/// </summary>
bool LeetCodeDP::validPartition(vector<int>& nums)
{
    vector<int> dp(nums.size());
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i-1])
        {
            if (i == 1 || (i > 1 && dp[i - 2] == 1))
            {
                dp[i] = 1;
            }
        }
        if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
        {
            if (i == 2 || (i > 2 && dp[i - 3] == 1))
            {
                dp[i] = 1;
            }
        }
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
        {
            if (i == 2 || (i > 2 && dp[i - 3] == 1))
            {
                dp[i] = 1;
            }
        }
    }
    return (dp[nums.size() - 1] == 1);
}

/// <summary>
/// Leet Code 2370. Longest Ideal Subsequence
///                                                  
/// Medium
///
/// You are given a string s consisting of lowercase letters and an 
/// integer k. We call a string t ideal if the following conditions 
/// are satisfied:
///
/// t is a subsequence of the string s.
/// The absolute difference in the alphabet order of every two adjacent 
/// letters in t is less than or equal to k.
/// Return the length of the longest ideal string.
///
/// A subsequence is a string that can be derived from another string by 
/// deleting some or no characters without changing the order of the 
/// remaining characters.
///
/// Note that the alphabet order is not cyclic. For example, the absolute 
/// difference in the alphabet order of 'a' and 'z' is 25, not 1.
///
/// Example 1:
/// Input: s = "acfgbd", k = 2
/// Output: 4
/// Explanation: The longest ideal string is "acbd". The length of this 
/// string is 4, so 4 is returned.
/// Note that "acfgbd" is not ideal because 'c' and 'f' have a difference 
/// of 3 in alphabet order.
///
/// Example 2:
/// Input: s = "abcd", k = 3
/// Output: 4
/// Explanation: The longest ideal string is "abcd". The length of this 
/// string is 4, so 4 is returned.
/// 
/// Constraints:
///
/// 1. 1 <= s.length <= 10^5
/// 2. 0 <= k <= 25
/// 3. s consists of lowercase English letters.
/// </summary>
int LeetCodeDP::longestIdealString(string s, int k)
{
    vector<int> dp(26);
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        int v = 0;
        for (int j = c - k; j <= c + k; j++)
        {
            if (j < 0) continue;
            else if (j > 25) break;
            else
            {
                v = max(v, dp[j] + 1);
            }
        }
        dp[c] = v;
        result = max(result, v);
    }
    return result;
}

/// <summary>
/// Leet Code 2400. Number of Ways to Reach a Position After Exactly 
///                 k Steps
///                                                  
/// Medium
///
/// You are given two positive integers startPos and endPos. Initially, 
/// you are standing at position startPos on an infinite number line. 
/// With one step, you can move either one position to the left, or 
/// one position to the right.
///
/// Given a positive integer k, return the number of different ways 
/// to reach the position endPos starting from startPos, such that you 
/// perform exactly k steps. Since the answer may be very large, return 
/// it modulo 10^9 + 7.
///
/// Two ways are considered different if the order of the steps made 
/// is not exactly the same.
///
/// Note that the number line includes negative integers.
/// 
/// Example 1:
/// Input: startPos = 1, endPos = 2, k = 3
/// Output: 3
/// Explanation: We can reach position 2 from 1 in exactly 3 
/// steps in three ways:
/// - 1 -> 2 -> 3 -> 2.
/// - 1 -> 2 -> 1 -> 2.
/// - 1 -> 0 -> 1 -> 2.
/// It can be proven that no other way is possible, so we return 3.
///
/// Example 2:
/// Input: startPos = 2, endPos = 5, k = 10
/// Output: 0
/// Explanation: It is impossible to reach position 5 from position 2 
/// in exactly 10 steps.
///
/// Constraints:
/// 1. 1 <= startPos, endPos, k <= 1000
/// </summary>
int LeetCodeDP::numberOfWays(int startPos, int endPos, int k)
{
    int M = 1000000007;
    vector<map<int, int>> pos_arr(2);
    int curr = 0;
    int next = 1;
    pos_arr[curr][startPos] = 1;
    for (int i = 0; i < k; i++)
    {
        for (auto itr : pos_arr[curr])
        {
            for (int d = -1; d <= 1; d += 2)
            {
                int nextPos = itr.first + d;
                if (abs(endPos - nextPos) > k - i - 1)
                {
                    continue;
                }
                pos_arr[next][nextPos] = (pos_arr[next][nextPos] + itr.second) %M;
            }
        }
        swap(curr, next);
        pos_arr[next].clear();
    }
    return pos_arr[curr][endPos];
}

/// <summary>
/// Leet Code 2431. Maximize Total Tastiness of Purchased Fruits
/// </summary>
int LeetCodeDP::maxTastiness(vector<int>& price, vector<int>& tastiness, int i, int amount, int coupons, vector<vector<vector<int>>>& dp)
{
    if (i == price.size()) return 0;
    if (dp[i][amount][coupons] != -1)
    {
        return dp[i][amount][coupons];
    }
    if (tastiness[i] > 0)
    {
        if (amount >= price[i])
        {
            dp[i][amount][coupons] = max(dp[i][amount][coupons],
                tastiness[i] + maxTastiness(price, tastiness, i + 1,
                    amount - price[i], coupons, dp));
        }
        if (amount >= price[i] / 2 && coupons > 0)
        {
            dp[i][amount][coupons] = max(dp[i][amount][coupons],
                tastiness[i] + maxTastiness(price, tastiness, i + 1,
                    amount - price[i] / 2, coupons - 1, dp));
        }
    }
    dp[i][amount][coupons] = max(dp[i][amount][coupons],
        maxTastiness(price, tastiness, i + 1,
            amount, coupons, dp));
    return dp[i][amount][coupons];
}


/// <summary>
/// Leet Code 2431. Maximize Total Tastiness of Purchased Fruits
///                                                  
/// Medium
///
/// You are given two non-negative integer arrays price and tastiness, 
/// both arrays have the same length n. You are also given two 
/// non-negative integers maxAmount and maxCoupons.
///
/// For every integer i in range [0, n - 1]:
///
/// price[i] describes the price of ith fruit.
/// tastiness[i] describes the tastiness of ith fruit.
/// You want to purchase some fruits such that total tastiness is 
/// maximized and the total price does not exceed maxAmount.
///
/// Additionally, you can use a coupon to purchase fruit for half of 
/// its price (rounded down to the closest integer). You can use at 
/// most maxCoupons of such coupons.
///
/// Return the maximum total tastiness that can be purchased.
///
/// Note that:
///
/// You can purchase each fruit at most once.
/// You can use coupons on some fruit at most once.
///
/// Example 1:
/// Input: price = [10,20,20], tastiness = [5,8,8], maxAmount = 20, 
/// maxCoupons = 1
/// Output: 13
/// Explanation: It is possible to make total tastiness 13 in following 
/// way:
/// - Buy first fruit without coupon, so that total price = 0 + 10 and 
///   total tastiness = 0 + 5.
/// - Buy second fruit with coupon, so that total price = 10 + 10 and 
///   total tastiness = 5 + 8.
/// - Do not buy third fruit, so that total price = 20 and total 
///   tastiness = 13.
/// It can be proven that 13 is the maximum total tastiness that can 
/// be obtained.
///
/// Example 2:
/// Input: price = [10,15,7], tastiness = [5,8,20], maxAmount = 10, 
/// maxCoupons = 2
/// Output: 28
/// Explanation: It is possible to make total tastiness 20 in following 
/// way:
/// - Do not buy first fruit, so that total price = 0 and total 
///   tastiness = 0.
/// - Buy second fruit with coupon, so that total price = 0 + 7 and 
///   total tastiness = 0 + 8.
/// - Buy third fruit with coupon, so that total price = 7 + 3 and 
///   total tastiness = 8 + 20.
/// It can be proven that 28 is the maximum total tastiness that can 
/// be obtained.
///  
/// Constraints:
/// 1. n == price.length == tastiness.length
/// 2. 1 <= n <= 100
/// 3. 0 <= price[i], tastiness[i], maxAmount <= 1000
/// 4. 0 <= maxCoupons <= 5
/// </summary>
int LeetCodeDP::maxTastiness(vector<int>& price, vector<int>& tastiness,
    int maxAmount, int maxCoupons)
{
    vector<vector<vector<int>>> dp(price.size(), vector<vector<int>>(maxAmount + 1, vector<int>(maxCoupons + 1, -1)));
    return maxTastiness(price, tastiness, 0, maxAmount, maxCoupons, dp);
}


/// <summary>
/// Leet Code 2435. Paths in Matrix Whose Sum Is Divisible by K
///                                                  
/// Hard
///
/// You are given a 0-indexed m x n integer matrix grid and an integer k. 
/// You are currently at position (0, 0) and you want to reach position 
/// (m - 1, n - 1) moving only down or right.
///
/// Return the number of paths where the sum of the elements on the path 
/// is divisible by k. Since the answer may be very large, return it 
/// modulo 10^9 + 7.
///
/// Example 1:
/// Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
/// Output: 2
/// Explanation: There are two paths where the sum of the elements on the 
/// path is divisible by k.
/// The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 
/// which is divisible by 3.
/// The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 
/// which is divisible by 3.
///
/// Example 2:
/// Input: grid = [[0,0]], k = 5
/// Output: 1
/// Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which 
/// is divisible by 5.
///
/// Example 3:
/// Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
/// Output: 10
/// Explanation: Every integer is divisible by 1 so the sum of the 
/// elements on every possible path is divisible by k.
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 5 * 10^4
/// 4. 1 <= m * n <= 5 * 10^4
/// 5. 0 <= grid[i][j] <= 100
/// 6. 1 <= k <= 50
/// </summary>
int LeetCodeDP::numberOfPaths(vector<vector<int>>& grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));
    int M = 1000000007;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = grid[i][j] % k;
            if (i == 0 && j == 0)
            {
                dp[i][j][val] = 1;
            }
            else
            {
                if (i > 0)
                {
                    for (int p = 0; p < k; p++)
                    {
                        int x = (val + p) % k;
                        dp[i][j][x] = (dp[i][j][x] + dp[i - 1][j][p]) % M;
                    }
                }
                if (j > 0)
                {
                    for (int p = 0; p < k; p++)
                    {
                        int x = (val + p) % k;
                        dp[i][j][x] = (dp[i][j][x] + dp[i][j - 1][p]) % M;
                    }
                }
            }
        }
    }
    return dp[m - 1][n - 1][0];
}

/// <summary>
/// Leet Code 2495. Number of Subarrays Having Even Product
/// 
/// Medium
///	
/// Given a 0-indexed integer array nums, return the number of subarrays
/// of nums having an even product.
/// 
/// Example 1:
/// Input: nums = [9,6,7,13]
/// Output: 6
/// Explanation: There are 6 subarrays with an even product:
/// - nums[0..1] = 9 * 6 = 54.
/// - nums[0..2] = 9 * 6 * 7 = 378.
/// - nums[0..3] = 9 * 6 * 7 * 13 = 4914.
/// - nums[1..1] = 6.
/// - nums[1..2] = 6 * 7 = 42.
/// - nums[1..3] = 6 * 7 * 13 = 546.
///
/// Example 2:
/// Input: nums = [7,3,5]
/// Output: 0
/// Explanation: There are no subarrays with an even product.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^5
/// </summary>
long long LeetCodeDP::evenProduct(vector<int>& nums)
{
    long long result = 0;
    int last_even = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            last_even = i + 1;
        }
        result += (long long)last_even;
    }
    return result;
}

/// <summary>
/// Leet Code 2484. Count Palindromic Subsequences
/// 
/// Hard
///	
/// Given a string of digits s, return the number of palindromic 
/// subsequences of s having length 5. Since the answer may be very 
/// large, return it modulo 10^9 + 7.
///
/// Note:
/// A string is palindromic if it reads the same forward and backward.
/// A subsequence is a string that can be derived from another string by 
/// deleting some or no characters without changing the order of the 
/// remaining characters.
///  
/// Example 1:
/// Input: s = "103301"
/// Output: 2
/// Explanation: 
/// There are 6 possible subsequences of length 5: "10330","10331",
/// "10301","10301","13301","03301". 
/// Two of them (both equal to "10301") are palindromic.
///
/// Example 2:
/// Input: s = "0000000"
/// Output: 21
/// Explanation: All 21 subsequences are "00000", which is palindromic.
///
/// Example 3:
///
/// Input: s = "9999900000"
/// Output: 2
/// Explanation: The only two palindromic subsequences are "99999" 
/// and "00000".
///
/// Constraints:
/// 1. 1 <= s.length <= 10^4
/// 2. s consists of digits.
/// </summary>
int LeetCodeDP::countPalindromes(string s)
{
    long long M = 1000000007;
    int n = s.size();
    vector<int> digits(10);    
    vector<vector<vector<int>>> prefix(n, vector<vector<int>>(10, vector<int>(10)));
    vector<vector<vector<int>>> suffix(n, vector<vector<int>>(10, vector<int>(10)));
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (i > 0)
        {
            for (int j = 0; j < 10; j++)
            {
                prefix[i][j][s[i] - '0'] += digits[j];
                for (int k = 0; k < 10; k++)
                {
                    prefix[i][j][k] += prefix[i - 1][j][k];
                    prefix[i][j][k] %= (int)M;
                }
            }
        }
        digits[s[i] - '0'] ++;
    }
    digits = vector<int>(10);

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (i < (int)s.size() - 1)
        {
            for (int j = 0; j < 10; j++)
            {
                suffix[i][j][s[i] - '0'] += digits[j];
                for (int k = 0; k < 10; k++)
                {
                    suffix[i][j][k] += suffix[i + 1][j][k];
                    suffix[i][j][k] %= (int)M;
                }
            }
        }
        digits[s[i] - '0'] ++;
    }
    long long result = 0;
    for (int i = 2; i < (int)s.size() - 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
           for (int k = 0; k < 10; k++)
           {
                result += (long long)prefix[i-1][j][k] * (long long)suffix[i + 1][j][k];
                result = result % M;
           }
        }
    }
    return (int)result;
}

/// <summary>
/// Leet Code 2478. Number of Beautiful Partitions
/// 
/// Hard
///	
/// You are given a string s that consists of the digits '1' to '9' and 
/// two integers k and minLength.
///
/// A partition of s is called beautiful if:
///
/// s is partitioned into k non-intersecting substrings.
/// Each substring has a length of at least minLength.
/// Each substring starts with a prime digit and ends with a non-prime 
/// digit. Prime digits are '2', '3', '5', and '7', and the rest of the 
/// digits are non-prime.
/// Return the number of beautiful partitions of s. Since the answer may 
/// be very large, return it modulo 10^9 + 7.
///
/// A substring is a contiguous sequence of characters within a string.
///
/// Example 1:
/// Input: s = "23542185131", k = 3, minLength = 2
/// Output: 3
/// Explanation: There exists three ways to create a beautiful partition:
/// "2354 | 218 | 5131"
/// "2354 | 21851 | 31"
/// "2354218 | 51 | 31"
///
/// Example 2:
/// Input: s = "23542185131", k = 3, minLength = 3
/// Output: 1
/// Explanation: There exists one way to create a beautiful partition: 
/// "2354 | 218 | 5131".
///
/// Example 3:
/// Input: s = "3312958", k = 3, minLength = 1
/// Output: 1
/// Explanation: There exists one way to create a beautiful 
/// partition: "331 | 29 | 58".
///
///
/// Constraints:
/// 1. 1 <= k, minLength <= s.length <= 1000
/// 2. s consists of the digits '1' to '9'.
/// </summary>
int LeetCodeDP::beautifulPartitions(string s, int k, int minLength)
{
    int M = 1000000007;
    unordered_set<int> prime = { 2, 3, 5, 7 };
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(k));
    vector<int> accumulate(k);
    if (prime.count(s[0] - '0') == 0 || prime.count(s[s.size() - 1] - '0') == 1) return 0;
    list<int> prev;
    for (int i = 0; i < n; i++)
    {
        if ((i < n - 1 && prime.count(s[i] - '0') == 0 && prime.count(s[i + 1] - '0') == 1) ||
            (i == n - 1 && prime.count(s[i] - '0') == 0))
        {
            if (i >= minLength - 1) dp[i][0] = 1;
            int first = -1;
            while (!prev.empty() && i - prev.front() >= minLength)
            {
                first = prev.front();
                prev.pop_front();
                for (int j = 1; j < k; j++)
                {
                    accumulate[j] = (accumulate[j] + dp[first][j - 1]) % M;
                }
            }
            for (int j = 1; j < k; j++)
            {
                dp[i][j] = (dp[i][j] + accumulate[j]) % M;
            }
            prev.push_back(i);
        }
    }
    return dp[n - 1][k - 1];
}

/// <summary>
/// Leet Code 2464. Minimum Subarrays in a Valid Split
/// 
/// Medium
///
/// You are given an integer array nums.
/// Splitting of an integer array nums into subarrays is valid if:
/// the greatest common divisor of the first and last elements of 
/// each subarray is greater than 1, and
/// each element of nums belongs to exactly one subarray.
/// Return the minimum number of subarrays in a valid subarray 
/// splitting of nums. If a valid subarray splitting is not possible, 
/// return -1.
///
/// Note that:
/// The greatest common divisor of two numbers is the largest positive 
/// integer that evenly divides both numbers.
/// A subarray is a contiguous non-empty part of an array.
///
/// Example 1:
/// Input: nums = [2,6,3,4,3]
/// Output: 2
/// Explanation: We can create a valid split in the following way: 
/// [2,6] | [3,4,3].
/// - The starting element of the 1st subarray is 2 and the ending 
///   is 6. Their greatest common divisor is 2, which is greater than 1.
/// - The starting element of the 2nd subarray is 3 and the ending is 3. 
///   Their greatest common divisor is 3, which is greater than 1.
/// It can be proved that 2 is the minimum number of subarrays that we 
/// can obtain in a valid split.
///
/// Example 2:
/// Input: nums = [3,5]
/// Output: 2
/// Explanation: We can create a valid split in the following 
/// way: [3] | [5].
/// - The starting element of the 1st subarray is 3 and the ending is 3. 
/// Their greatest common divisor is 3, which is greater than 1.
/// - The starting element of the 2nd subarray is 5 and the ending is 5. 
/// Their greatest common divisor is 5, which is greater than 1.
/// It can be proved that 2 is the minimum number of subarrays that we 
/// can obtain in a valid split.
///
/// Example 3:
///
/// Input: nums = [1,2,1] 
/// Output: -1
/// Explanation: It is impossible to create valid split.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. 1 <= nums[i] <= 10^5
/// </summary>
int LeetCodeDP::validSubarraySplit(vector<int>& nums)
{
    int n = nums.size();
    vector<int>dp(n, -1);
    for (int i = 0; i < (int)nums.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int a = nums[i];
            int b = nums[j];
            while (a != 0 && b != 0)
            {
                if (a < b) swap(a, b);
                a = a % b;
            }
            if (b != 1)
            {
                if (j == 0) 
                {
                    dp[i] = 1;
                }
                else
                {
                    if (dp[j - 1] != -1)
                    {

                        if (dp[i] == -1) dp[i] = dp[j - 1] + 1;
                        else dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
    }
    return dp[n - 1];
}

/// <summary>
/// Leet Code 2466. Count Ways To Build Good Strings
/// 
/// Medium
///	
/// Given the integers zero, one, low, and high, we can construct a string 
/// by starting with an empty string, and then at each step perform either 
/// of the following:
///
/// Append the character '0' zero times.
/// Append the character '1' one times.
/// This can be performed any number of times.
///
/// A good string is a string constructed by the above process having a 
/// length between low and high (inclusive).
///
/// Return the number of different good strings that can be constructed 
/// satisfying these properties. Since the answer can be large, return 
/// it modulo 10^9 + 7.
///
/// 
/// Example 1:
/// Input: low = 3, high = 3, zero = 1, one = 1
/// Output: 8
/// Explanation: 
/// One possible valid good string is "011". 
/// It can be constructed as follows: "" -> "0" -> "01" -> "011". 
/// All binary strings from "000" to "111" are good strings in this 
/// example.
/// Example 2:
///
/// Input: low = 2, high = 3, zero = 1, one = 2
/// Output: 5
/// Explanation: The good strings are "00", "11", "000", "110", 
/// and "011".
///
/// Constraints:
/// 1. 1 <= low <= high <= 10^5
/// 2. 1 <= zero, one <= low
/// </summary>
int LeetCodeDP::countGoodStrings(int low, int high, int zero, int one)
{
    int M = 1000000007;
    vector<int> dp(high + 1);
    dp[0] = 1;
    for (int i = 0; i <= high; i++)
    {
        int next = i + zero;
        if (next <= high)
        {
            dp[next] = (dp[next] + dp[i]) % M;
        }
        next = i + one;
        if (next <= high)
        {
            dp[next] = (dp[next] + dp[i]) % M;
        }
    }
    int result = 0;
    for (int i = low; i <= high; i++)
    {
        result = (result + dp[i]) % M;
    }
    return result;
}

/// <summary>
/// Leet Code 2501. Longest Square Streak in an Array
/// 
/// Medium
///	
/// You are given an integer array nums. A subsequence of nums is called a 
/// square streak if:
///
/// The length of the subsequence is at least 2, and
/// after sorting the subsequence, each element (except the first element) 
/// is the square of the previous number.
/// Return the length of the longest square streak in nums, or return -1 
/// if there is no square streak.
///
/// A subsequence is an array that can be derived from another array by 
/// deleting some or no elements without changing the order of the 
/// remaining elements.
///
/// Example 1:
/// Input: nums = [4,3,6,16,8,2]
/// Output: 3
/// Explanation: Choose the subsequence [4,16,2]. After sorting it, it 
/// becomes [2,4,16].
/// - 4 = 2 * 2.
/// - 16 = 4 * 4.
/// Therefore, [4,16,2] is a square streak.
/// It can be shown that every subsequence of length 4 is not a square 
/// streak.
///
/// Example 2:
/// Input: nums = [2,3,5,6,7]
/// Output: -1
/// Explanation: There is no square streak in nums so return -1.
/// 
/// Constraints:
/// 1. 2 <= nums.length <= 10^5
/// 2. 2 <= nums[i] <= 10^5
/// </summary>
int LeetCodeDP::longestSquareStreak(vector<int>& nums)
{
    unordered_map<long long, int> streak;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++)
    {
        streak[nums[i]] = 1;
    }
    int result = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        long long square = (long long)nums[i] * (long long)nums[i];
        if (streak.count(square) == 0)
        {
            continue;
        }
        streak[square] = max(streak[square], streak[nums[i]] + 1);
        result = max(result, streak[square]);
    }
    return result;
}

/// <summary>
/// Leet Code 2472. Maximum Number of Non-overlapping Palindrome Substrings
/// 
/// Hard
///	
/// You are given a string s and a positive integer k.
///
/// Select a set of non-overlapping substrings from the string s that 
/// satisfy the following conditions:
///
/// The length of each substring is at least k.
/// Each substring is a palindrome.
/// Return the maximum number of substrings in an optimal selection.
///
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: s = "abaccdbbd", k = 3
/// Output: 2
/// Explanation: We can select the substrings underlined in 
/// s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a 
/// length of at least k = 3.
/// It can be shown that we cannot find a selection with more than two 
/// valid substrings.
///
/// Example 2:
/// Input: s = "adbcda", k = 2
/// Output: 0
/// Explanation: There is no palindrome substring of length at least 2 in 
/// the string.
/// Constraints:
/// 1. 1 <= k <= s.length <= 2000
/// 2. s consists of lowercase English letters.
/// </summary>
int LeetCodeDP::maxPalindromes(string s, int k)
{
    int n = s.size();
    vector<vector<int>> pal(n, vector<int>(n));
    vector<int>len(n, 1);
    for (int i = 0; i < n; i++)
    {
        pal[i][i] = 1;
        for (int j = i; j >= 0; j--)
        {
            if ((i == j) || (j == i - 1 && s[j] == s[i]) ||
                (s[j] == s[i] && pal[j + 1][i - 1] == 1))
            {
                len[i] = i - j + 1;
                pal[j][i] = 1;
            }
            if (len[i] >= k) break;
        }
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        if (len[i] >= k)
        {
            if (i - len[i] >= 0)  dp[i] = max(dp[i], dp[i - len[i]] + 1);
            else dp[i] = max(dp[i], 1);
        }
        if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    }
    return dp[n - 1];
}

/// <summary>
/// Leet Code 2463. Minimum Total Distance Traveled
///    repair every robot.
/// </summary>
long long LeetCodeDP::minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory,
    int r, int f, int k, vector<vector<vector<long long>>>& dp)
{
    if (r == robot.size()) return 0;
    if (f == factory.size()) return -1;
    if (k >= factory[f][1])
    {
        return minimumTotalDistance(robot, factory, r, f + 1, 0, dp);
    }
    if (dp[r][f][k] != -1)
    {
        return dp[r][f][k];
    }
    long long result = minimumTotalDistance(robot, factory, r, f + 1, 0, dp);
    long long distance = minimumTotalDistance(robot, factory, r + 1, f, k + 1, dp);
    if (result == -1 && distance == -1)
    {
        return -1;
    }
    else if (result == -1)
    {
        distance = distance + (long long)abs(robot[r] - factory[f][0]);
        result = distance;
    }
    else if (distance != -1)
    {
        distance = distance + (long long)abs(robot[r] - factory[f][0]);
        result = min(result, distance);
    }
    dp[r][f][k] = result;
    return result;
}

/// <summary>
/// Leet Code 2463. Minimum Total Distance Traveled
/// 
/// Hard
///	
/// There are some robots and factories on the X-axis. You are given an 
/// integer array robot where robot[i] is the position of the ith robot. 
/// You are also given a 2D integer array factory where 
/// factory[j] = [positionj, limitj] indicates that positionj is the 
/// position of the jth factory and that the jth factory can repair at 
/// most limitj robots.
///
/// The positions of each robot are unique. The positions of each factory 
/// are also unique. Note that a robot can be in the same position as a 
/// factory initially.
///
/// All the robots are initially broken; they keep moving in one direction. 
/// The direction could be the negative or the positive direction of the 
/// X-axis. When a robot reaches a factory that did not reach its limit, 
/// the factory repairs the robot, and it stops moving.
///
/// At any moment, you can set the initial direction of moving for some 
/// robot. Your target is to minimize the total distance traveled by all 
/// the robots.
///
/// Return the minimum total distance traveled by all the robots. The 
/// test cases are generated such that all the robots can be repaired.
///
/// Note that
/// 
/// All robots move at the same speed.
/// If two robots move in the same direction, they will never collide.
/// If two robots move in opposite directions and they meet at some 
/// point, they do not collide. They cross each other.
/// If a robot passes by a factory that reached its limits, it crosses 
/// it as if it does not exist.
/// If the robot moved from a position x to a position y, the distance 
/// it moved is |y - x|.
/// 
/// Example 1:
///
/// Input: robot = [0,4,6], factory = [[2,2],[6,2]]
/// Output: 4
/// Explanation: As shown in the figure:
/// - The first robot at position 0 moves in the positive direction. 
///   It will be repaired at the first factory.
/// - The second robot at position 4 moves in the negative direction. 
///   It will be repaired at the first factory.
/// - The third robot at position 6 will be repaired at the second 
///   factory. It does not need to move.
/// The limit of the first factory is 2, and it fixed 2 robots.
/// The limit of the second factory is 2, and it fixed 1 robot.
/// The total distance is |2 - 0| + |2 - 4| + |6 - 6| = 4. It can be 
/// shown that we cannot achieve a better total distance than 4.
///
/// Example 2:
/// Input: robot = [1,-1], factory = [[-2,1],[2,1]]
/// Output: 2
/// Explanation: As shown in the figure:
/// - The first robot at position 1 moves in the positive direction. 
///   It will be repaired at the second factory.
/// - The second robot at position -1 moves in the negative direction. 
///   It will be repaired at the first factory.
/// The limit of the first factory is 1, and it fixed 1 robot.
/// The limit of the second factory is 1, and it fixed 1 robot.
/// The total distance is |2 - 1| + |(-2) - (-1)| = 2. It can be shown 
/// that we cannot achieve a better total distance than 2.
/// 
/// Constraints:
/// 1. 1 <= robot.length, factory.length <= 100
/// 2. factory[j].length == 2
/// 3. -10^9 <= robot[i], positionj <= 10^9
/// 4. 0 <= limitj <= robot.length
/// 5. The input will be generated such that it is always possible to 
///    repair every robot.
/// </summary>
long long LeetCodeDP::minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory)
{
    int k = 0;
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    for (size_t i = 0; i < factory.size(); i++)
    {
        k = max(k, factory[i][1]);
    }
    int r = robot.size();
    int f = factory.size();
    vector<vector<vector<long long>>> dp(r, vector<vector<long long>>(f, vector<long long>(k, -1)));
    return minimumTotalDistance(robot, factory, 0, 0, 0, dp);
}

/// <summary>
/// Leet Code 2510. Check if There is a Path With Equal Number of 0's 
///                    And 1's
/// 
/// Medium
///	
/// You are given a 0-indexed m x n binary matrix grid. You can move from 
/// a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1).
///
/// Return true if there is a path from (0, 0) to (m - 1, n - 1) that 
/// visits an equal number of 0's and 1's. Otherwise return false.
///
/// Example 1:
/// Input: grid = [[0,1,0,0],[0,1,0,0],[1,0,1,0]]
/// Output: true
/// Explanation: The path colored in blue in the above diagram is a valid 
/// path because we have 3 cells with a value of 1 and 3 with a value 
/// of 0. Since there is a valid path, we return true.
///
/// Example 2:
/// Input: grid = [[1,1,0],[0,0,1],[1,0,0]]
/// Output: false
/// Explanation: There is no path in this grid with an equal number 
/// of 0's and 1's.
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 2 <= m, n <= 100
/// 4. grid[i][j] is either 0 or 1.
/// </summary>
bool LeetCodeDP::isThereAPath(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<unordered_set<int>>> matrix(m, vector<unordered_set<int>>(n));
    if (grid[0][0] == 0) matrix[0][0].insert(-1);
    else matrix[0][0].insert(1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int delta = 0;
            if (grid[i][j] == 0) delta = -1;
            else delta = 1;
            if (i > 0)
            {
                for (auto x : matrix[i - 1][j])
                {
                    matrix[i][j].insert(x + delta);
                }
            }
            if (j > 0)
            {
                for (auto x : matrix[i][j - 1])
                {
                    matrix[i][j].insert(x + delta);
                }
            }
        }
    }
    if (matrix[m - 1][n - 1].count(0) > 0) return true;
    return false;
}

/// <summary>
/// Leet Code 2518. Number of Great Partitions
/// 
/// Hard
///	
/// You are given an array nums consisting of positive integers and an 
/// integer k.
///
/// Partition the array into two ordered groups such that each element 
/// is in exactly one group. A partition is called great if the sum of 
/// elements of each group is greater than or equal to k.
///
/// Return the number of distinct great partitions. Since the answer 
/// may be too large, return it modulo 10^9 + 7.
///
/// Two partitions are considered distinct if some element nums[i] is 
/// in different groups in the two partitions.
///
/// Example 1:
/// Input: nums = [1,2,3,4], k = 4
/// Output: 6
/// Explanation: The great partitions are: ([1,2,3], [4]), ([1,3], 
/// [2,4]), ([1,4], [2,3]), ([2,3], [1,4]), ([2,4], [1,3]) and ([4], 
/// [1,2,3]).
///
/// Example 2:
/// Input: nums = [3,3,3], k = 4
/// Output: 0
/// Explanation: There are no great partitions for this array.
///
/// Example 3:
/// Input: nums = [6,6], k = 2
/// Output: 2
/// Explanation: We can either put nums[0] in the first partition or in 
/// the second partition.
/// The great partitions will be ([6], [6]) and ([6], [6]).
/// 
/// Constraints:
/// 1. 1 <= nums.length, k <= 1000
/// 2. 1 <= nums[i] <= 10^9
/// </summary>
int LeetCodeDP::countPartitions(vector<int>& nums, int k)
{
    long long sum = 0;
    long long M = 1000000007;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += (long long)nums[i];
    }
    if (sum < 2 * (long long) k) return 0;
    vector<long long> dp(k);
    dp[0] = 1;
    long long result = 1;
    for (auto a : nums)
    {
        for (int i = k - 1 - a; i >= 0; i--)
        {
            dp[i + a] = (dp[i + a] + dp[i]) % M;
        }
        result = (result * 2) % M;
    }
    for (int i = 0; i < k; i++)
    {
        result = (result - 2 * dp[i] + 2 * M) % M;
    }
    return (int)result;
}

/// <summary>
/// Leet Code 2430. Maximum Deletions on a String
///                                                  
/// Hard
///
/// You are given a string s consisting of only lowercase English 
/// letters. In one operation, you can:
///
/// Delete the entire string s, or
/// Delete the first i letters of s if the first i letters of s are 
/// equal to the following i letters in s, for any i in the range 
/// 1 <= i <= s.length / 2.
/// For example, if s = "ababc", then in one operation, you could 
/// delete the first two letters of s to get "abc", since the first 
/// two letters of s and the following two letters of s are both 
/// equal to "ab".
/// Return the maximum number of operations needed to delete all of s.
///
/// Example 1:
/// Input: s = "abcabcdabc"
/// Output: 2
/// Explanation:
/// - Delete the first 3 letters ("abc") since the next 3 letters are 
///   equal. Now, s = "abcdabc".
/// - Delete all the letters.
/// We used 2 operations so return 2. It can be proven that 2 is the 
/// maximum number of operations needed.
/// Note that in the second operation we cannot delete "abc" again 
/// because the next occurrence of "abc" does not happen in the next 3 
/// letters.
///
/// Example 2:
///
/// Input: s = "aaabaab"
/// Output: 4
/// Explanation:
/// - Delete the first letter ("a") since the next letter is equal. 
///   Now, s = "aabaab".
/// - Delete the first 3 letters ("aab") since the next 3 letters are equal. 
///   Now, s = "aab".
/// - Delete the first letter ("a") since the next letter is equal. 
///   Now, s = "ab".
/// - Delete all the letters.
/// We used 4 operations so return 4. It can be proven that 4 is the 
/// maximum number of operations needed.
///
/// Example 3:
/// Input: s = "aaaaa"
/// Output: 5
/// Explanation: In each operation, we can delete the first letter of s.
///
/// Constraints:
/// 1. 1 <= s.length <= 4000
/// 2. s consists only of lowercase English letters.
/// </summary>
int LeetCodeDP::deleteString(string s)
{
    int n = s.size();
    vector<vector<int>> lcs(n + 1, vector<int>(n + 1, 0));
    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                lcs[i][j] = lcs[i + 1][j + 1] + 1;
            }
            if (lcs[i][j] >= j - i)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[0];
}

/// <summary>
/// Leet Code 2533. Number of Good Binary Strings
/// 
/// Medium
///	
/// You are given four integers minLenght, maxLength, oneGroup and 
/// zeroGroup.
///
/// A binary string is good if it satisfies the following conditions:
///
/// The length of the string is in the range [minLength, maxLength].
/// The size of each block of consecutive 1's is a multiple of oneGroup.
/// For example in a binary string 00110111100 sizes of each block of 
/// consecutive ones are [2,4].
/// The size of each block of consecutive 0's is a multiple of zeroGroup.
/// For example, in a binary string 00110111100 sizes of each block of 
/// consecutive ones are [2,1,2].
/// Return the number of good binary strings. Since the answer may be too 
/// large, return it modulo 10^9 + 7.
///
/// Note that 0 is considered a multiple of all the numbers.
/// 
/// Example 1:
/// Input: minLength = 2, maxLength = 3, oneGroup = 1, zeroGroup = 2
/// Output: 5
/// Explanation: There are 5 good binary strings in this example: 
/// "00", "11", "001", "100", and "111".
/// It can be proven that there are only 5 good strings satisfying 
/// all conditions.
///
/// Example 2:
/// Input: minLength = 4, maxLength = 4, oneGroup = 4, zeroGroup = 3
/// Output: 1
/// Explanation: There is only 1 good binary string in this 
/// example: "1111".
/// It can be proven that there is only 1 good string satisfying all 
/// conditions.
/// Constraints:
/// 1. 1 <= minLength <= maxLength <= 10^5
/// 2. 1 <= oneGroup, zeroGroup <= maxLength
/// </summary>
int LeetCodeDP::goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup)
{
    vector<int> dp(maxLength + 1);
    int M = 1000000007;
    dp[0] = 1;
    for (int i = 0; i <= maxLength; i++)
    {
        int next = i + oneGroup;
        if (next <= maxLength)
        {
            dp[next] = (dp[next] + dp[i]) % M;
        }
        next = i + zeroGroup;
        if (next <= maxLength)
        {
            dp[next] = (dp[next] + dp[i]) % M;
        }
    }
    int result = 0;
    for (int i = minLength; i <= maxLength; i++)
    {
        result = (result + dp[i]) % M;
    }
    return result;
}

/// <summary>
/// Leet Code 2547. Minimum Cost to Split an Array
/// 
/// Hard
///	
/// You are given an integer array nums and an integer k.
///
/// Split the array into some number of non-empty subarrays. The cost of 
/// a split is the sum of the importance value of each subarray in the 
/// split.
/// Let trimmed(subarray) be the version of the subarray where all numbers 
/// which appear only once are removed.
/// For example, trimmed([3,1,2,4,3,4]) = [3,4,3,4].
/// The importance value of a subarray is k + trimmed(subarray).length.
///
/// For example, if a subarray is [1,2,3,3,3,4,4], then 
/// trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4].The importance value of this 
/// subarray will be k + 5.
/// Return the minimum possible cost of a split of nums.
///
/// A subarray is a contiguous non-empty sequence of elements within an 
/// array.
///
/// Example 1:
/// Input: nums = [1,2,1,2,1,3,3], k = 2
/// Output: 8
/// Explanation: We split nums to have two subarrays: [1,2], [1,2,1,3,3].
/// The importance value of [1,2] is 2 + (0) = 2.
/// The importance value of [1,2,1,3,3] is 2 + (2 + 2) = 6.
/// The cost of the split is 2 + 6 = 8. It can be shown that this is the 
/// minimum possible cost among all the possible splits.
///
/// Example 2:
/// Input: nums = [1,2,1,2,1], k = 2
/// Output: 6
/// Explanation: We split nums to have two subarrays: [1,2], [1,2,1].
/// The importance value of [1,2] is 2 + (0) = 2.
/// The importance value of [1,2,1] is 2 + (2) = 4.
/// The cost of the split is 2 + 4 = 6. It can be shown that this is the 
/// minimum possible cost among all the possible splits.
///
/// Example 3:
/// Input: nums = [1,2,1,2,1], k = 5
/// Output: 10
/// Explanation: We split nums to have one subarray: [1,2,1,2,1].
/// The importance value of [1,2,1,2,1] is 5 + (3 + 2) = 10.
/// The cost of the split is 10. It can be shown that this is the minimum 
/// possible cost among all the possible splits.
///
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. 0 <= nums[i] < nums.length
/// 3. 1 <= k <= 10^9
/// </summary>
int LeetCodeDP::minCost(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> num_count;
        int single = 0;
        for (int j = i; j >= 0; j--)
        {
            int x = nums[j];
            num_count[x]++;
            if (num_count[x] == 1) single++;
            else if (num_count[x] == 2) single--;
            int value = i - j + 1 - single + k;
            int prev = 0;
            if (j == 0) prev = 0;
            else prev = dp[j - 1];
            dp[i] = min(dp[i], prev + value);
        }
    }
    return dp[n - 1];
}

/// <summary>
/// Leet Code 2585. Number of Ways to Earn Points
/// 
/// Hard
///	
/// There is a test that has n types of questions. You are given an integer
/// target and a 0-indexed 2D integer array types where types[i] = 
/// [counti, marksi] indicates that there are counti questions of the ith 
/// type, and each one of them is worth marksi points.
///
/// Return the number of ways you can earn exactly target points in the 
/// exam. Since the answer may be too large, return it modulo 10^9 + 7.
///
/// Note that questions of the same type are indistinguishable.
///
/// For example, if there are 3 questions of the same type, then solving 
/// the 1st and 2nd questions is the same as solving the 1st and 3rd 
/// questions, or the 2nd and 3rd questions.
///
/// Example 1:
/// Input: target = 6, types = [[6,1],[3,2],[2,3]]
/// Output: 7
/// Explanation: You can earn 6 points in one of the seven ways:
/// - Solve 6 questions of the 0th type: 1 + 1 + 1 + 1 + 1 + 1 = 6
/// - Solve 4 questions of the 0th type and 1 question of the 1st 
///   type: 1 + 1 + 1 + 1 + 2 = 6
/// - Solve 2 questions of the 0th type and 2 questions of the 1st 
///   type: 1 + 1 + 2 + 2 = 6
/// - Solve 3 questions of the 0th type and 1 question of the 2nd 
///   type: 1 + 1 + 1 + 3 = 6
/// - Solve 1 question of the 0th type, 1 question of the 1st type 
///   and 1 question of the 2nd type: 1 + 2 + 3 = 6
/// - Solve 3 questions of the 1st type: 2 + 2 + 2 = 6
/// - Solve 2 questions of the 2nd type: 3 + 3 = 6
///
/// Example 2:
/// Input: target = 5, types = [[50,1],[50,2],[50,5]]
/// Output: 4
/// Explanation: You can earn 5 points in one of the four ways:
/// - Solve 5 questions of the 0th type: 1 + 1 + 1 + 1 + 1 = 5
/// - Solve 3 questions of the 0th type and 1 question of the 1st 
///   type: 1 + 1 + 1 + 2 = 5
/// - Solve 1 questions of the 0th type and 2 questions of the 1st 
///   type: 1 + 2 + 2 = 5
/// - Solve 1 question of the 2nd type: 5
///
/// Example 3:
/// Input: target = 18, types = [[6,1],[3,2],[2,3]]
/// Output: 1
/// Explanation: You can only earn 18 points by answering all questions.
///
/// Constraints:
/// 1. 1 <= target <= 1000
/// 2. n == types.length
/// 3. 1 <= n <= 50
/// 4. types[i].length == 2
/// 5. 1 <= counti, marksi <= 50
/// </summary>
int LeetCodeDP::waysToReachTarget(int target, vector<vector<int>>& types)
{
    int M = 1000000007;
    vector<pair<int, int>> dp(target + 1);
    for (size_t i = 0; i < types.size(); i++)
    {
        dp[0].first = 1;
        for (int j = 1; j <= types[i][0]; j++)
        {
            int score = j * types[i][1];
            for (int k = target; k >= score; k--)
            {
                dp[k].second = (dp[k].second + dp[k - score].first) % M;
            }
        }
        for (int j = 0; j <= target; j++)
        {
            dp[j].first = (dp[j].first + dp[j].second) % M;
            dp[j].second = 0;
        }
    }
    return dp[target].first;
}


/// <summary>
/// Leet Code 2638. Count the Number of K-Free Subsets
/// 
/// Medium
///	
/// You are given an integer array nums, which contains distinct elements 
/// and an integer k.
///
/// A subset is called a k-Free subset if it contains no two elements 
/// with an absolute difference equal to k. Notice that the empty set is a 
/// k-Free subset.
///
/// Return the number of k-Free subsets of nums.
///
/// A subset of an array is a selection of elements (possibly none) of 
/// the array.
/// 
/// Example 1:
/// Input: nums = [5,4,6], k = 1
/// Output: 5
/// Explanation: There are 5 valid subsets: {}, {5}, {4}, {6} and {4, 6}.
///
/// Example 2:
/// Input: nums = [2,3,5,8], k = 5
/// Output: 12
/// Explanation: There are 12 valid subsets: {}, {2}, {3}, {5}, {8}, 
/// {2, 3}, {2, 3, 5}, {2, 5}, {2, 5, 8}, {2, 8}, {3, 5} and {5, 8}.
///
/// Example 3:
/// Input: nums = [10,5,9,11], k = 20
/// Output: 16
/// Explanation: All subsets are valid. Since the total count of subsets 
/// is 24 = 16, so the answer is 16. 
///
/// Constraints:
///
/// 1. 1 <= nums.length <= 50
/// 2. 1 <= nums[i] <= 1000
/// 3. 1 <= k <= 1000
/// </summary>
long long LeetCodeDP::countTheNumOfKFreeSubsets(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> chains;
    vector<long long> fib = { 1, 1 };
    for (auto& x : nums)
    {
        chains[x] = 1 + chains[x - k];
        chains.erase(x - k);
        if (chains[x] >= (int)fib.size() - 2)
        {
            int n = fib.size();
            fib.push_back(fib[n-1] + fib[n - 2]);
        }
    }
    long long result = 1;
    for (auto& itr : chains)
    {
        result *= fib[itr.second + 1];
    }
    return result;
}

/// <summary>
/// Leet Code 2707. Extra Characters in a String
/// 
/// Medium
///
/// You are given a 0-indexed string s and a dictionary of words 
/// dictionary. You have to break s into one or more non-overlapping 
/// substrings such that each substring is present in dictionary. 
/// There may be some extra characters in s which are not present 
/// in any of the substrings.
///
/// Return the minimum number of extra characters left over if 
/// you break up s optimally.
///
/// Example 1:
/// Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
/// Output: 1
/// Explanation: We can break s in two substrings: "leet" from index 0 
/// to 3 and "code" from index 5 to 8. There is only 1 unused character 
/// (at index 4), so we return 1.
///
/// Example 2:
/// Input: s = "sayhelloworld", dictionary = ["hello","world"]
/// Output: 3
/// Explanation: We can break s in two substrings: "hello" from index 3 
/// to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 
/// are not used in any substring and thus are considered as extra 
/// characters. Hence, we return 3.
///
/// Constraints:
/// 1. 1 <= s.length <= 50
/// 2. 1 <= dictionary.length <= 50
/// 3. 1 <= dictionary[i].length <= 50
/// 4. dictionary[i] and s consists of only lowercase English letters
/// 5. dictionary contains distinct words
/// 6. You are given a 0-indexed integer array nums representing the score of 
/// </summary>
int LeetCodeDP::minExtraChar(string s, vector<string>& dictionary)
{
    unordered_set<string> dict;
    int min_len = INT_MAX;
    int max_len = 0;
    for (string str : dictionary)
    {
        dict.insert(str);
        min_len = min(min_len, (int)str.size());
        max_len = max(max_len, (int)str.size());
    }
    int n = s.size();
    vector<int>dp(n + 1, n);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0) dp[i] = 0;
        else dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int j = min_len; j <= max_len && i + j <= n; j++)
        {
            if (dict.count(s.substr(i, j)))
            {
                dp[i + j] = min(dp[i + j], dp[i]);
            }
        }
    }
    return dp[n];
}

/// <summary>
/// Leet Code 2712. Minimum Cost to Make All Characters Equal
/// 
/// Medium
///
/// You are given a 0-indexed binary string s of length n on which you can 
/// apply two types of operations:
///
/// Choose an index i and invert all characters from index 0 to index i 
/// (both inclusive), with a cost of i + 1
/// Choose an index i and invert all characters from index i to index 
/// n - 1 (both inclusive), with a cost of n - i
/// Return the minimum cost to make all characters of the string equal.
///
/// Invert a character means if its value is '0' it becomes '1' and 
/// vice-versa.
///
/// Example 1:
/// Input: s = "0011"
/// Output: 2
/// Explanation: Apply the second operation with i = 2 to obtain 
/// s = "0000" for a cost of 2. It can be shown that 2 is the 
/// minimum cost to make all characters equal.
/// Example 2:
///
/// Input: s = "010101"
/// Output: 9
/// Explanation: Apply the first operation with i = 2 to obtain 
/// s = "101101" for a cost of 3.
/// Apply the first operation with i = 1 to obtain s = "011101" 
/// for a cost of 2. 
/// Apply the first operation with i = 0 to obtain s = "111101" 
/// for a cost of 1. 
/// Apply the second operation with i = 4 to obtain s = "111110" 
/// for a cost of 2.
/// Apply the second operation with i = 5 to obtain s = "111111" 
/// for a cost of 1. 
/// The total cost to make all characters equal is 9. It can be 
/// shown that 9 is the minimum cost to make all characters equal.
/// 
/// Constraints:
/// 1. 1 <= s.length == n <= 10^5
/// 2. s[i] is either '0' or '1'
/// </summary>
long long LeetCodeDP::minimumCost(string s)
{
    int n = s.size();
    vector<vector<long long>> left(n, vector<long long>(2));
    vector<vector<long long>> right(n, vector<long long>(2));
    for (int i = 0; i < n; i++)
    {
        int v = s[i] - '0';
        if (i == 0)
        {
            left[i][v] = 0;
            left[i][1 - v] = 1;
        }
        else
        {
            left[i][v] = min(left[i - 1][v], left[i - 1][1 - v] + i);
            left[i][1 - v] = left[i - 1][v] + i + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int v = s[i] - '0';
        if (i == n-1)
        {
            right[i][v] = 0;
            right[i][1 - v] = 1;
        }
        else
        {
            right[i][v] = min(right[i + 1][v], right[i + 1][1 - v] + n - 1 - i);
            right[i][1 - v] = right[i + 1][v] + n - i;
        }
    }
    long long result = LLONG_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        result = min(result, left[i][0] + right[i + 1][0]);
        result = min(result, left[i][1] + right[i + 1][1]);
    }
    result = min(result, left[n - 1][0]);
    result = min(result, left[n - 1][1]);
    result = min(result, right[0][0]);
    result = min(result, right[0][1]);
    return result;
}

/// <summary>
/// Leet Code 2742. Painting the Walls
/// 
/// Hard
///
/// You are given two 0-indexed integer arrays, cost and time, of size n 
/// representing the costs and the time taken to paint n different walls 
/// respectively. There are two painters available:
///
/// A paid painter that paints the ith wall in time[i] units of time and 
/// takes cost[i] units of money.
/// A free painter that paints any wall in 1 unit of time at a cost of 0. 
/// But the free painter can only be used if the paid painter is already 
/// occupied.
/// Return the minimum amount of money required to paint the n walls.
/// 
/// Example 1:
/// Input: cost = [1,2,3,2], time = [1,2,3,2]
/// Output: 3
/// Explanation: The walls at index 0 and 1 will be painted by the paid 
/// painter, and it will take 3 units of time; meanwhile, the free painter 
/// will paint the walls at index 2 and 3, free of cost in 2 units of 
/// time. Thus, the total cost is 1 + 2 = 3.
///
/// Example 2:
/// Input: cost = [2,3,4,2], time = [1,1,1,1]
/// Output: 4
/// Explanation: The walls at index 0 and 3 will be painted by the paid 
/// painter, and it will take 2 units of time; meanwhile, the free painter 
/// will paint the walls at index 1 and 2, free of cost in 2 units of time.
/// Thus, the total cost is 2 + 2 = 4.
/// 
/// Constraints:
/// 1. 1 <= cost.length <= 500
/// 2. cost.length == time.length
/// 3. 1 <= cost[i] <= 10^6
/// 4. 1 <= time[i] <= 500
/// </summary>
int LeetCodeDP::paintWalls(vector<int>& cost, vector<int>& time)
{
    int n = cost.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (dp[j] == INT_MAX) continue;
            int new_time = min(j + 1 + time[i], n);
            int new_cost = dp[j] + cost[i];
            dp[new_time] = min(dp[new_time], new_cost);
        }
    }
    return dp[n];
}

/// <summary>
/// Leet Code 2767. Partition String Into Minimum Beautiful Substrings
/// 
/// Medium
///
/// Given a binary string s, partition the string into one or more 
/// substrings such that each substring is beautiful.
///
/// A string is beautiful if:
/// It doesn't contain leading zeros.
/// It's the binary representation of a number that is a power of 5.
/// Return the minimum number of substrings in such partition. If it 
/// is impossible to partition the string s into beautiful substrings, 
/// return -1.
///
/// A substring is a contiguous sequence of characters in a string.
/// 
/// Example 1:
/// Input: s = "1011"
/// Output: 2
/// Explanation: We can paritition the given string into ["101", "1"].
/// - The string "101" does not contain leading zeros and is the binary 
///   representation of integer 51 = 5.
/// - The string "1" does not contain leading zeros and is the binary 
///   representation of integer 50 = 1.
/// It can be shown that 2 is the minimum number of beautiful substrings 
/// that s can be partitioned into.
///
/// Example 2:
/// Input: s = "111"
/// Output: 3
/// Explanation: We can paritition the given string into ["1", "1", "1"].
/// - The string "1" does not contain leading zeros and is the binary 
///   representation of integer 50 = 1.
/// It can be shown that 3 is the minimum number of beautiful substrings 
/// that s can be partitioned into.
///
/// Example 3:
/// Input: s = "0"
/// Output: -1
/// Explanation: We can not partition the given string into beautiful 
/// substrings.
///
/// Constraints:
/// 1. 1 <= s.length <= 15
/// 2. s[i] is either '0' or '1'.
/// </summary>
int LeetCodeDP::minimumBeautifulSubstrings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i + 1] == INT_MAX) continue;
        if (s[i] == '0') continue;
        int power = 1;
        int num = 0;
        for (int j = i; j >= 0; j--)
        {
            num += (s[j] - '0') << (i - j);
            if (num > power)
            {
                power *= 5;
            }
            if (num == power)
            {
                if (s[j] == '1')
                {
                    dp[j] = min(dp[j], 1 + dp[i + 1]);
                }
            }
        }
    }
    if (dp[0] == INT_MAX)
    {
        dp[0] = -1;
    }
    return dp[0];
}

/// <summary>
/// Leet Code 2770. Maximum Number of Jumps to Reach the Last Index
/// 
/// Medium
///
/// You are given a 0-indexed array nums of n integers and an integer 
/// target.
///
/// You are initially positioned at index 0. In one step, you can jump 
/// from index i to any index j such that:
///
/// 0 <= i < j < n
/// -target <= nums[j] - nums[i] <= target
/// Return the maximum number of jumps you can make to reach index n - 1.
///
/// If there is no way to reach index n - 1, return -1.
/// 
/// Example 1:
/// Input: nums = [1,3,6,4,1,2], target = 2
/// Output: 3
/// Explanation: To go from index 0 to index n - 1 with the maximum number 
/// of jumps, you can perform the following jumping sequence:
/// - Jump from index 0 to index 1. 
/// - Jump from index 1 to index 3.
/// - Jump from index 3 to index 5.
/// It can be proven that there is no other jumping sequence that goes 
/// from 0 to n - 1 with more than 3 jumps. Hence, the answer is 3. 
///
/// Example 2:
/// Input: nums = [1,3,6,4,1,2], target = 3
/// Output: 5
/// Explanation: To go from index 0 to index n - 1 with the maximum number 
/// of jumps, you can perform the following jumping sequence:
/// - Jump from index 0 to index 1.
/// - Jump from index 1 to index 2.
/// - Jump from index 2 to index 3.
/// - Jump from index 3 to index 4.
/// - Jump from index 4 to index 5.
/// It can be proven that there is no other jumping sequence that goes 
/// from 0 to n - 1 with more than 5 jumps. Hence, the answer is 5. 
///
/// Example 3:
/// Input: nums = [1,3,6,4,1,2], target = 0
/// Output: -1
/// Explanation: It can be proven that there is no jumping sequence that 
/// goes from 0 to n - 1. Hence, the answer is -1. 
///
/// Constraints:
/// 1. 2 <= nums.length == n <= 1000
/// 2. -10^9 <= nums[i] <= 10^9
/// 3. 0 <= target <= 2 * 10^9
/// </summary>
int LeetCodeDP::maximumJumps(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == -1) continue;
        for (int j = i - 1; j >= 0; j--)
        {
            if (std::abs(nums[i] - nums[j]) <= target)
            {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    return dp[0];
}

/// <summary>
/// Leet Code 2771. Longest Non-decreasing Subarray From Two Arrays
/// 
/// Medium
///
/// You are given two 0-indexed integer arrays nums1 and nums2 of length n.
///
/// Let's define another 0-indexed integer array, nums3, of length n. For 
/// each index i in the range [0, n - 1], you can assign either nums1[i] 
/// or nums2[i] to nums3[i].
///
/// Your task is to maximize the length of the longest non-decreasing 
/// subarray in nums3 by choosing its values optimally.
///
/// Return an integer representing the length of the longest 
/// non-decreasing subarray in nums3.
///
/// Note: A subarray is a contiguous non-empty sequence of elements 
/// within an array.
/// 
/// Example 1:
/// Input: nums1 = [2,3,1], nums2 = [1,2,1]
/// Output: 2
/// Explanation: One way to construct nums3 is: 
/// nums3 = [nums1[0], nums2[1], nums2[2]] => [2,2,1]. 
/// The subarray starting from index 0 and ending at index 1, [2,2], 
/// forms a non-decreasing subarray of length 2. 
/// We can show that 2 is the maximum achievable length.
///
/// Example 2:
/// Input: nums1 = [1,3,2,1], nums2 = [2,2,3,4]
/// Output: 4
/// Explanation: One way to construct nums3 is: 
/// nums3 = [nums1[0], nums2[1], nums2[2], nums2[3]] => [1,2,3,4]. 
/// The entire array forms a non-decreasing subarray of length 4, making 
/// it the maximum achievable length.
///
/// Example 3:
/// Input: nums1 = [1,1], nums2 = [2,2]
/// Output: 2
/// Explanation: One way to construct nums3 is: 
/// nums3 = [nums1[0], nums1[1]] => [1,1]. 
/// The entire array forms a non-decreasing subarray of length 2, making 
/// it the maximum achievable length.
///
/// Constraints:
/// 1. 1 <= nums1.length == nums2.length == n <= 10^5
/// 2. 1 <= nums1[i], nums2[i] <= 10^9
/// </summary>
int LeetCodeDP::maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2)
{
    vector<pair<int, int>> dp(2);
    int result = 0;
    for (size_t i = 0; i < nums1.size(); i++)
    {
        int count1 = 1, count2 = 1;
        for (int j = 0; j < 2; j++)
        {
            if (nums1[i] >= dp[j].first)
            {
                count1 = max(count1, 1 + dp[j].second);
            }
            if (nums2[i] >= dp[j].first)
            {
                count2 = max(count2, 1 + dp[j].second);
            }
        }
        dp[0] = make_pair(nums1[i], count1);
        dp[1] = make_pair(nums2[i], count2);
        result = max(result, max(count1, count2));
    }
    return result;
}

/// <summary>
/// Leet Code 2786. Visit Array Positions to Maximize Score
/// 
/// Medium
///
/// You are given a 0-indexed integer array nums and a positive integer x.
///
/// You are initially at position 0 in the array and you can visit other 
/// positions according to the following rules:
///
/// If you are currently in position i, then you can move to any position 
/// j such that i < j.
/// For each position i that you visit, you get a score of nums[i].
/// If you move from a position i to a position j and the parities of 
/// nums[i] and nums[j] differ, then you lose a score of x.
///
/// Return the maximum total score you can get.
/// Note that initially you have nums[0] points.
///   
/// Example 1:
/// Input: nums = [2,3,6,1,9,2], x = 5
/// Output: 13
/// Explanation: We can visit the following positions in the 
/// array: 0 -> 2 -> 3 -> 4.
/// The corresponding values are 2, 6, 1 and 9. Since the integers 6 and 1 
/// have different parities, the move 2 -> 3 will make you lose a score 
/// of x = 5.
/// The total score will be: 2 + 6 + 1 + 9 - 5 = 13.
///
/// Example 2:
/// Input: nums = [2,4,6,8], x = 3
/// Output: 20
/// Explanation: All the integers in the array have the same parities, so 
/// we can visit all of them without losing any score.
/// The total score is: 2 + 4 + 6 + 8 = 20.
///
/// Constraints:
/// 1. 2 <= nums.length <= 10^5
/// 2. 1 <= nums[i], x <= 10^6
/// </summary>
long long LeetCodeDP::maxScore(vector<int>& nums, int x)
{
    vector<pair<int, long long>> prev(2, { -1, LLONG_MIN });
    for (size_t i = 0; i < nums.size(); i++)
    {
        int p = nums[i] % 2;
        if (i == 0)
        {
            prev[p].first = 0;
            prev[p].second = nums[i];
        }
        else
        {
            long long val = LLONG_MIN;
            for (int j = 0; j < 2; j++)
            {
                if (prev[j].first == -1) continue;
                if (p == j)
                {
                    val = max(val, prev[j].second + (long long)nums[i]);
                }
                else
                {
                    val = max(val, prev[j].second + (long long)nums[i] - (long long)x);
                }
            }
            prev[p].first = i;
            prev[p].second = max(prev[p].second, val);
        }
    }
    long long result = max(prev[0].second, prev[1].second);
    return result;
}

/// <summary>
/// Leet 2809. Minimum Time to Make Array Sum At Most x
/// 
/// Hard
///
/// You are given two 0-indexed integer arrays nums1 and nums2 of equal 
/// length. Every second, for all indices 0 <= i < nums1.length, value 
/// of nums1[i] is incremented by nums2[i]. After this is done, you can 
/// do the following operation:
///
/// Choose an index 0 <= i < nums1.length and make nums1[i] = 0.
/// You are also given an integer x.
///
/// Return the minimum time in which you can make the sum of all elements 
/// of nums1 to be less than or equal to x, or -1 if this is not possible.
///
/// Example 1:
/// Input: nums1 = [1,2,3], nums2 = [1,2,3], x = 4
/// Output: 3
/// Explanation: 
/// For the 1st second, we apply the operation on i = 0. Therefore 
/// nums1 = [0,2+2,3+3] = [0,4,6]. 
/// For the 2nd second, we apply the operation on i = 1. Therefore 
/// nums1 = [0+1,0,6+3] = [1,0,9]. 
/// For the 3rd second, we apply the operation on i = 2. Therefore 
/// nums1 = [1+1,0+2,0] = [2,2,0]. 
/// Now sum of nums1 = 4. It can be shown that these operations are 
/// optimal, so we return 3.
///
/// Example 2:
/// 
/// Input: nums1 = [1,2,3], nums2 = [3,3,3], x = 4
/// Output: -1
/// Explanation: It can be shown that the sum of nums1 will always be 
/// greater than x, no matter which operations are performed.
///
/// Constraints:
/// 1. 1 <= nums1.length <= 10^3
/// 2. 1 <= nums1[i] <= 10^3
/// 3. 0 <= nums2[i] <= 10^3
/// 4. nums1.length == nums2.length
/// 5. 0 <= x <= 10^6
/// </summary>
int LeetCodeDP::minimumTime(vector<int>& nums1, vector<int>& nums2, int x)
{
    int n = nums1.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(make_pair(nums2[i], nums1[i]));
    }
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    sort(arr.begin(), arr.end());
    vector<int> dp(n + 1);
    for (int j = 0; j < n; j++)
    {
        for (int i = j + 1; i > 0; i-- )
        {
            dp[i] = max(dp[i], dp[i-1] + arr[j].first * i + arr[j].second);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        int result = sum1 + sum2 * i - dp[i];
        if (result <= x) return i;
    }
    return -1;
}

/// <summary>
/// Leet Code 2826. Sorting Three Groups
/// 
/// Medium
///
/// You are given a 0-indexed integer array nums of length n.
///
/// The numbers from 0 to n - 1 are divided into three groups numbered 
/// from 1 to 3, where number i belongs to group nums[i]. Notice that 
/// some groups may be empty.
///
/// You are allowed to perform this operation any number of times:
///
/// Pick number x and change its group. More formally, change nums[x] to 
/// any number from 1 to 3.
/// A new array res is constructed using the following procedure:
/// 
/// Sort the numbers in each group independently.
/// Append the elements of groups 1, 2, and 3 to res in this order.
/// Array nums is called a beautiful array if the constructed array res is 
/// sorted in non-decreasing order.
///
/// Return the minimum number of operations to make nums a beautiful array.
/// 
/// Example 1:
/// Input: nums = [2,1,3,2,1]
/// Output: 3
/// Explanation: It's optimal to perform three operations:
/// 1. change nums[0] to 1.
/// 2. change nums[2] to 1.
/// 3. change nums[3] to 1.
/// After performing the operations and sorting the numbers in each group, 
/// group 1 becomes equal to [0,1,2,3,4] and group 2 and group 3 become 
/// empty. Hence, res is equal to [0,1,2,3,4] which is sorted in 
/// non-decreasing order.
/// It can be proven that there is no valid sequence of less than three 
/// operations.
///
/// Example 2:
/// Input: nums = [1,3,2,1,3,3]
/// Output: 2
/// Explanation: It's optimal to perform two operations:
/// 1. change nums[1] to 1.
/// 2. change nums[2] to 1.
/// After performing the operations and sorting the numbers in each group, 
/// group 1 becomes equal to [0,1,2,3], group 2 becomes empty, and group 3 
/// becomes equal to [4,5]. Hence, res is equal to [0,1,2,3,4,5] which is 
/// sorted in non-decreasing order.
/// It can be proven that there is no valid sequence of less than two 
/// operations.
///
/// Example 3:
/// Input: nums = [2,2,2,2,3,3]
/// Output: 0
/// Explanation: It's optimal to not perform operations.
/// After sorting the numbers in each group, group 1 becomes empty, 
/// group 2 becomes equal to [0,1,2,3] and group 3 becomes equal to [4,5]. 
/// Hence, res is equal to [0,1,2,3,4,5] which is sorted in non-decreasing 
/// order.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 1 <= nums[i] <= 3
/// </summary>
int LeetCodeDP::minimumOperations(vector<int>& nums)
{
    vector<int> prev(3);
    for (size_t i = 0; i < nums.size(); i++)
    {
        vector<int> dp(3, INT_MAX);
        for (int j = 1; j <= 3; j++)
        {
            int extra = 0;
            if (nums[i] != j) extra = 1;
            for (int k = 1; k <= j; k++)
            {
                dp[j - 1] = min(dp[j - 1], prev[k - 1]);
            }
            dp[j - 1] += extra;
        }
        prev = dp;
    }
    int result = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        result = min(result, prev[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 2896. Apply Operations to Make Two Strings Equal
/// </summary>
int LeetCodeDP::minOperationsDFS(vector<int>& diff, int x, int start, int end, vector<vector<int>>& dp)
{
    if (dp[start][end] != 0) return dp[start][end];
    if (start + 1 == end)
    {
        dp[start][end] = min(diff[end] - diff[start], x);
    }
    else
    {
        dp[start][end] = minOperationsDFS(diff, x, start + 1, end - 1, dp) + min(diff[end] - diff[start], x);
        for (int mid = start + 1; mid < end - 1; mid += 2)
            dp[start][end] = min(dp[start][end], minOperationsDFS(diff, x, start, mid, dp) + minOperationsDFS(diff, x, mid + 1, end, dp));
    }
    return dp[start][end];
}


/// <summary>
/// Leet Code 2896. Apply Operations to Make Two Strings Equal
/// 
/// Medium
/// 
/// You are given two 0-indexed binary strings s1 and s2, both of 
/// length n, and a positive integer x.
///
/// You can perform any of the following operations on the string 
/// s1 any number of times:
///
/// Choose two indices i and j, and flip both s1[i] and s1[j]. The 
/// cost of this operation is x.
/// Choose an index i such that i < n - 1 and flip both s1[i] and 
/// s1[i + 1]. The cost of this operation is 1.
/// Return the minimum cost needed to make the strings s1 and s2 equal, 
/// or return -1 if it is impossible.
///
/// Note that flipping a character means changing it from 0 to 1 or 
/// vice-versa.
///
/// Example 1:
/// Input: s1 = "1100011000", s2 = "0101001010", x = 2
/// Output: 4
/// Explanation: We can do the following operations:
/// - Choose i = 3 and apply the second operation. The resulting string 
///   is s1 = "1101111000".
/// - Choose i = 4 and apply the second operation. The resulting string 
///   is s1 = "1101001000".
/// - Choose i = 0 and j = 8 and apply the first operation. The resulting 
///   string is s1 = "0101001010" = s2.
/// The total cost is 1 + 1 + 2 = 4. It can be shown that it is the 
/// minimum cost possible.
///
/// Example 2:
/// Input: s1 = "10110", s2 = "00011", x = 4
/// Output: -1
/// Explanation: It is not possible to make the two strings equal.
///
/// Constraints:
/// 1. n == s1.length == s2.length
/// 2. 1 <= n, x <= 500
/// 3. s1 and s2 consist only of the characters '0' and '1'.
/// </summary>
int LeetCodeDP::minOperationsDFS(string s1, string s2, int x)
{
    vector<int> diff;
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            diff.push_back(i);
        }
    }
    int n = diff.size();
    if (n == 0) return 0;
    if (n % 2 == 1)
    {
        return -1;
    }
    vector<vector<int>> dp(n, vector<int>(n));
    minOperationsDFS(diff, x, 0, n - 1, dp);
    return dp[0][n - 1];
}

/// <summary>
/// Leet Code 2896. Apply Operations to Make Two Strings Equal
/// 
/// Medium
/// 
/// You are given two 0-indexed binary strings s1 and s2, both of 
/// length n, and a positive integer x.
///
/// You can perform any of the following operations on the string 
/// s1 any number of times:
///
/// Choose two indices i and j, and flip both s1[i] and s1[j]. The 
/// cost of this operation is x.
/// Choose an index i such that i < n - 1 and flip both s1[i] and 
/// s1[i + 1]. The cost of this operation is 1.
/// Return the minimum cost needed to make the strings s1 and s2 equal, 
/// or return -1 if it is impossible.
///
/// Note that flipping a character means changing it from 0 to 1 or 
/// vice-versa.
///
/// Example 1:
/// Input: s1 = "1100011000", s2 = "0101001010", x = 2
/// Output: 4
/// Explanation: We can do the following operations:
/// - Choose i = 3 and apply the second operation. The resulting string 
///   is s1 = "1101111000".
/// - Choose i = 4 and apply the second operation. The resulting string 
///   is s1 = "1101001000".
/// - Choose i = 0 and j = 8 and apply the first operation. The resulting 
///   string is s1 = "0101001010" = s2.
/// The total cost is 1 + 1 + 2 = 4. It can be shown that it is the 
/// minimum cost possible.
///
/// Example 2:
/// Input: s1 = "10110", s2 = "00011", x = 4
/// Output: -1
/// Explanation: It is not possible to make the two strings equal.
///
/// Constraints:
/// 1. n == s1.length == s2.length
/// 2. 1 <= n, x <= 500
/// 3. s1 and s2 consist only of the characters '0' and '1'.
/// </summary>
int LeetCodeDP::minOperations(string s1, string s2, int x)
{
    vector<int> diff;
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            diff.push_back(i);
        }
    }
    int n = diff.size();
    if (n == 0) return 0;
    if (n % 2 == 1)
    {
        return -1;
    }
    vector<vector<float>> dp(diff.size(), vector<float>(2));
    for (size_t i = 0; i < diff.size(); i++)
    {
        if (i == 0)
        {
            dp[i][0] = 0;
            dp[i][1] = (float)x/2;
        }
        else if (i == 1)
        {
            dp[i][0] = (float)min(x, diff[i] - diff[i - 1]);
            dp[i][1] = 0;
        }
        else if (i % 2 == 1)
        {
            dp[i][0] = dp[i - 2][0] + (float)min(x, (diff[i] - diff[i - 1]));
            dp[i][0] = min(dp[i][0],  dp[i - 1][1] + (float)x / 2);
            dp[i][1] = 0;
        }
        else
        {
            dp[i][0] = 0;
            dp[i][1] = dp[i - 2][1] + min(x, (diff[i] - diff[i - 1]));
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + (float)x / 2);
        }
    }
    int result = (int)dp[n - 1][0];
    return result;
}

/// <summary>
/// Leet Code 2902. Count of Sub-Multisets With Bounded Sum
/// 
/// Hard
/// 
/// You are given a 0-indexed array nums of non-negative integers, and two 
/// integers l and r.
///
/// Return the count of sub-multisets within nums where the sum of 
/// elements in each subset falls within the inclusive range of [l, r].
///
/// Since the answer may be large, return it modulo 10^9 + 7.
///
/// A sub-multiset is an unordered collection of elements of the array in 
/// which a given value x can occur 0, 1, ..., occ[x] times, where occ[x] 
/// is the number of occurrences of x in the array.
///
/// Note that:
/// Two sub-multisets are the same if sorting both sub-multisets results 
/// in identical multisets.
/// The sum of an empty multiset is 0.
/// Example 1:
/// Input: nums = [1,2,2,3], l = 6, r = 6
/// Output: 1
/// Explanation: The only subset of nums that has a sum of 6 is {1, 2, 3}.
///
/// Example 2:
/// Input: nums = [2,1,4,2,7], l = 1, r = 5
/// Output: 7
/// Explanation: The subsets of nums that have a sum within the range 
/// [1, 5] are {1}, {2}, {4}, {2, 2}, {1, 2}, {1, 4}, and {1, 2, 2}.
///
/// Example 3:
/// Input: nums = [1,2,1,3,5,2], l = 3, r = 5
/// Output: 9
/// Explanation: The subsets of nums that have a sum within the range 
/// [3, 5] are {3}, {5}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {1, 1, 2}, 
/// {1, 1, 3}, and {1, 2, 2}.
///
/// Constraints:
/// 1. 1 <= nums.length <= 2 * 10^4
/// 2. 0 <= nums[i] <= 2 * 10^4
/// 3. Sum of nums does not exceed 2 * 10^4.
/// 4. 0 <= l <= r <= 2 * 10^4
/// </summary>
int LeetCodeDP::countSubMultisets(vector<int>& nums, int l, int r)
{
    int M = 1000000007;
    vector<int> dp(r);
    dp[0] = 1;
    unordered_map<int, int> count;
    for (int a : nums)
        count[a]++;
    for (auto it = count.begin(); it != count.end(); ++it) 
    {
        int a = it->first, c = it->second;
        for (int i = r; i > max(0, r - a); --i) 
        {
            long v = 0;
            for (int k = 0; k < c && i - a * k >= 0; ++k) 
            {
                v += dp[i - a * k];
            }
            for (int j = i; j > 0; j -= a) 
            {
                if (j - a * c >= 0)
                {
                    v = (v + dp[j - a * c]) % M;
                }
                v = (v - dp[j] + M) % M;
                dp[j] = (dp[j] + v) % M;
            }
        }
    }
    long result = 0;
    for (int i = l; i <= r; ++i)
    {
        result = (result + dp[i]) % M;
    }
    return result * (count[0] + 1) % M;
}

/// <summary>
/// Leet Code 2915. Length of the Longest Subsequence That Sums to Target
/// 
/// Medium
///
/// You are given a 0-indexed array of integers nums, and an integer
/// target.
/// Return the length of the longest subsequence of nums that sums up 
/// to target. If no such subsequence exists, return -1.
///
/// A subsequence is an array that can be derived from another array by 
/// deleting some or no elements without changing the order of the 
/// remaining elements.
/// 
/// Example 1:
/// Input: nums = [1,2,3,4,5], target = 9
/// Output: 3
/// Explanation: There are 3 subsequences with a sum equal to 9: [4,5], 
/// [1,3,5], and [2,3,4]. The longest subsequences are [1,3,5], and 
/// [2,3,4]. Hence, the answer is 3.
///
/// Example 2:
/// Input: nums = [4,1,3,2,1,5], target = 7
/// Output: 4
/// Explanation: There are 5 subsequences with a sum equal to 7: [4,3], 
/// [4,1,2], [4,2,1], [1,1,5], and [1,3,2,1]. The longest subsequence 
/// is [1,3,2,1]. Hence, the answer is 4.
///
/// Example 3:
/// Input: nums = [1,1,5,4,5], target = 3
/// Output: -1
/// Explanation: It can be shown that nums has no subsequence that sums 
/// up to 3.
///
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. 1 <= nums[i] <= 1000
/// 3. 1 <= target <= 1000
/// </summary>
int LeetCodeDP::lengthOfLongestSubsequence(vector<int>& nums, int target)
{
    vector<int> dp(target + 1);
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (int j = target; j >= nums[i]; j--)
        {
            if (j == nums[i] || dp[j - nums[i]] != 0)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + 1);
            }
        }
    }
    return dp[target] == 0 ? -1 : dp[target];
}

/// <summary>
/// Leet Code 2919. Minimum Increment Operations to Make Array Beautiful
/// 
/// Medium
///
/// You are given a 0-indexed integer array nums having length n, and an 
/// integer k.
///
/// You can perform the following increment operation any number of times 
/// (including zero):
/// 
/// Choose an index i in the range [0, n - 1], and increase nums[i] by 1.
/// An array is considered beautiful if, for any subarray with a size of 3 
/// or more, its maximum element is greater than or equal to k.
///
/// Return an integer denoting the minimum number of increment operations 
/// needed to make nums beautiful.
///
/// A subarray is a contiguous non-empty sequence of elements within an 
/// array.
///
/// Example 1:
/// Input: nums = [2,3,0,0,2], k = 4
/// Output: 3
/// Explanation: We can perform the following increment operations to 
/// make nums beautiful:
/// Choose index i = 1 and increase nums[1] by 1 -> [2,4,0,0,2].
/// Choose index i = 4 and increase nums[4] by 1 -> [2,4,0,0,3].
/// Choose index i = 4 and increase nums[4] by 1 -> [2,4,0,0,4].
/// The subarrays with a size of 3 or more are: [2,4,0], [4,0,0], 
/// [0,0,4], [2,4,0,0], [4,0,0,4], [2,4,0,0,4].
/// In all the subarrays, the maximum element is equal to k = 4, so 
/// nums is now beautiful.
/// It can be shown that nums cannot be made beautiful with fewer 
/// than 3 increment operations.
/// Hence, the answer is 3.
///
/// Example 2:
/// Input: nums = [0,1,3,3], k = 5
/// Output: 2
/// Explanation: We can perform the following increment operations to make 
/// nums beautiful:
/// Choose index i = 2 and increase nums[2] by 1 -> [0,1,4,3].
/// Choose index i = 2 and increase nums[2] by 1 -> [0,1,5,3].
/// The subarrays with a size of 3 or more are: [0,1,5], [1,5,3], 
/// [0,1,5,3].
/// In all the subarrays, the maximum element is equal to k = 5, so nums 
/// is now beautiful.
/// It can be shown that nums cannot be made beautiful with fewer than 2 
/// increment operations.
/// Hence, the answer is 2.
///
/// Example 3:
/// Input: nums = [1,1,2], k = 1
/// Output: 0
/// Explanation: The only subarray with a size of 3 or more in this 
/// example is [1,1,2].
/// The maximum element, 2, is already greater than k = 1, so we don't 
/// need any increment operation.
/// Hence, the answer is 0.
/// 
/// Constraints:
/// 1. 3 <= n == nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^9
/// 3. 0 <= k <= 10^9
/// </summary>
long long LeetCodeDP::minIncrementOperations(vector<int>& nums, int k)
{
    set<pair<long long, int>> heap;
    queue<long long> queue;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        long long sum = max(0, k - nums[i]);
        if (queue.size() >= 3)
        {
            sum = sum + heap.begin()->first;
            heap.erase(make_pair(queue.front(), i - 3));
            queue.pop();
        }
        heap.insert(make_pair(sum, i));
        queue.push(sum);
    }
    return heap.begin()->first;
}

/// <summary>
/// Leet Code 2944. Minimum Number of Coins for Fruits
///  
/// Medium
///
/// You are at a fruit market with different types of exotic fruits on display.
///
/// You are given a 1-indexed array prices, where prices[i] denotes the number 
/// of coins needed to purchase the ith fruit.
///
/// The fruit market has the following offer:
///
/// If you purchase the ith fruit at prices[i] coins, you can get the next i 
/// fruits for free.
/// Note that even if you can take fruit j for free, you can still purchase it 
/// for prices[j] coins to receive a new offer.
///
/// Return the minimum number of coins needed to acquire all the fruits.
/// 
/// Example 1:
/// Input: prices = [3,1,2]
/// Output: 4
/// Explanation: You can acquire the fruits as follows:
/// - Purchase the 1st fruit with 3 coins, you are allowed to take the 2nd 
///   fruit for free.
/// - Purchase the 2nd fruit with 1 coin, you are allowed to take the 3rd 
///   fruit for free.
/// - Take the 3rd fruit for free.
/// Note that even though you were allowed to take the 2nd fruit for free, 
/// you purchased it because it is more optimal.
/// It can be proven that 4 is the minimum number of coins needed to acquire 
/// all the fruits.
///
/// Example 2:
/// Input: prices = [1,10,1,1]
/// Output: 2
/// Explanation: You can acquire the fruits as follows:
/// - Purchase the 1st fruit with 1 coin, you are allowed to take the 2nd 
///   fruit for free.
/// - Take the 2nd fruit for free.
/// - Purchase the 3rd fruit for 1 coin, you are allowed to take the 4th fruit 
///   for free.
/// - Take the 4th fruit for free.
/// It can be proven that 2 is the minimum number of coins needed to acquire 
/// all the fruits.
///
/// Constraints:
/// 1. 1 <= prices.length <= 1000
/// 2. 1 <= prices[i] <= 10^5
/// </summary>
int LeetCodeDP::minimumCoins(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    deque<pair<int, int>> future_prices;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = prices[i - 1] + dp[i - 1][1];
        while (!future_prices.empty() && future_prices.front().first < i)
        {
            future_prices.pop_front();
        }
        dp[i][1] = dp[i][0];
        if (!future_prices.empty()) dp[i][1] = min(dp[i][1], future_prices.front().second);
        while ((!future_prices.empty() && future_prices.back().second >= dp[i][0]))
        {
            future_prices.pop_back();
        }
        future_prices.push_back(make_pair(i * 2, dp[i][0]));
    }
    return dp[n][1];
}

/// <summary>
/// Leet Code 2969. Minimum Number of Coins for Fruits II
///  
/// Hard
///
/// You are at a fruit market with different types of exotic fruits on display.
///
/// You are given a 1-indexed array prices, where prices[i] denotes the number 
/// of coins needed to purchase the ith fruit.
///
/// The fruit market has the following offer:
///
/// If you purchase the ith fruit at prices[i] coins, you can get the next i 
/// fruits for free.
/// Note that even if you can take fruit j for free, you can still purchase it 
/// for prices[j] coins to receive a new offer.
///
/// Return the minimum number of coins needed to acquire all the fruits.
/// 
/// Example 1:
/// Input: prices = [3,1,2]
/// Output: 4
/// Explanation: You can acquire the fruits as follows:
/// - Purchase the 1st fruit with 3 coins, and you are allowed to take the 2nd 
///   fruit for free.
/// - Purchase the 2nd fruit with 1 coin, and you are allowed to take the 3rd 
///   fruit for free.
/// - Take the 3rd fruit for free.
/// Note that even though you were allowed to take the 2nd fruit for free, you 
/// purchased it because it is more optimal.
/// It can be proven that 4 is the minimum number of coins needed to acquire 
/// all the fruits.
///
/// Example 2:
/// Input: prices = [1,10,1,1]
/// Output: 2
/// Explanation: You can acquire the fruits as follows:
/// - Purchase the 1st fruit with 1 coin, and you are allowed to take the 2nd 
///   fruit for free.
/// - Take the 2nd fruit for free.
/// - Purchase the 3rd fruit for 1 coin, and you are allowed to take the 4th 
///   fruit for free.
/// - Take the 4th fruit for free.
///   It can be proven that 2 is the minimum number of coins needed to acquire 
///  all the fruits.
///  
/// Constraints:
/// 1. 1 <= prices.length <= 10^5
/// 2. 1 <= prices[i] <= 10^5
/// </summary>
int LeetCodeDP::minimumCoinsII(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    deque<pair<int, int>> future_prices;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = prices[i-1] + dp[i - 1][1];
        while (!future_prices.empty() && future_prices.front().first < i)
        {
            future_prices.pop_front();
        }
        dp[i][1] = dp[i][0];
        if (!future_prices.empty()) dp[i][1] = min(dp[i][1], future_prices.front().second);
        while ((!future_prices.empty() && future_prices.back().second >= dp[i][0]))
        {
            future_prices.pop_back();
        }
        future_prices.push_back(make_pair(i * 2, dp[i][0]));
    }
    return dp[n][1];
}

/// <summary>
/// Leet Code 3003. Maximize the Number of Partitions After Operations
///                 
/// Hard
///
/// You are given a 0-indexed string s and an integer k.
/// 
/// You are to perform the following partitioning operations until s is empty:
///
/// Choose the longest prefix of s containing at most k distinct characters.
/// Delete the prefix from s and increase the number of partitions by one. The 
/// remaining characters (if any) in s maintain their initial order.
/// Before the operations, you are allowed to change at most one index in s to 
/// another lowercase English letter.
///
/// Return an integer denoting the maximum number of resulting partitions 
/// after the operations by optimally choosing at most one index to change.
/// 
/// Example 1: 
/// Input: s = "accca", k = 2
/// Output: 3
/// Explanation: In this example, to maximize the number of resulting 
/// partitions, s[2] can be changed to 'b'.
/// s becomes "acbca".
/// The operations can now be performed as follows until s becomes empty:
/// - Choose the longest prefix containing at most 2 distinct characters, 
///   "acbca".
/// - Delete the prefix, and s becomes "bca". The number of partitions is 
///   now 1.
/// - Choose the longest prefix containing at most 2 distinct characters,
///   "bca".
/// - Delete the prefix, and s becomes "a". The number of partitions is 
///   now 2.
/// - Choose the longest prefix containing at most 2 distinct characters, 
///   "a".
/// - Delete the prefix, and s becomes empty. The number of partitions 
///   is now 3.
/// Hence, the answer is 3.
/// It can be shown that it is not possible to obtain more than 3 partitions.
///
/// Example 2:
/// Input: s = "aabaab", k = 3
/// Output: 1
/// Explanation: In this example, to maximize the number of resulting 
/// partitions we can leave s as it is.
/// The operations can now be performed as follows until s becomes empty: 
/// - Choose the longest prefix containing at most 3 distinct characters, 
///   "aabaab".
/// - Delete the prefix, and s becomes empty. The number of partitions 
///   becomes 1. 
/// Hence, the answer is 1. 
/// It can be shown that it is not possible to obtain more than 1 partition.
///
/// Example 3:
/// Input: s = "xxyz", k = 1
/// Output: 4
/// Explanation: In this example, to maximize the number of resulting 
/// partitions, s[1] can be changed to 'a'.
/// s becomes "xayz".
/// The operations can now be performed as follows until s becomes empty:
/// - Choose the longest prefix containing at most 1 distinct character, 
///   "xayz".
/// - Delete the prefix, and s becomes "ayz". The number of partitions is 
///   now 1.
/// - Choose the longest prefix containing at most 1 distinct character, 
///   "ayz".
/// - Delete the prefix, and s becomes "yz". The number of partitions is 
///   now 2.
/// - Choose the longest prefix containing at most 1 distinct character, 
///   "yz".
/// - Delete the prefix, and s becomes "z". The number of partitions is 
///   now 3.
/// - Choose the longest prefix containing at most 1 distinct character, 
///   "z".
/// - Delete the prefix, and s becomes empty. The number of partitions is 
///   now 4.
/// Hence, the answer is 4.
/// It can be shown that it is not possible to obtain more than 4 partitions.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^4
/// 2. s consists only of lowercase English letters.
/// 3. 1 <= k <= 26
/// </summary>
int LeetCodeDP::maxPartitionsAfterOperations(string s, int k)
{
    int n = s.size();
    vector<pair<int, int>> dp_parts(n), dp_bits(n);
    int bit_map = 0;
    int count = 0;
    int partitions = 0;
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if ((bit_map & (1 << (s[i] - 'a'))) == 0) 
        {
            count++;
            if (count > k)
            {
                partitions++;
                bit_map = 0;
                count = 1;
            }
        }
        bit_map |= (1 << (s[i] - 'a'));
        dp_parts[i].first = partitions;
        dp_bits[i].first = bit_map;
    }

    bit_map = 0;
    count = 0;
    partitions = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((bit_map & (1 << (s[i] - 'a'))) == 0)
        {
            count++;
            if (count > k)
            {
                partitions++;
                bit_map = 0;
                count = 1;
            }
        }
        bit_map |= (1 << (s[i] - 'a'));
        dp_parts[i].second = partitions;
        dp_bits[i].second = bit_map;
    }

    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 0, common = 0, center = 0;
        for (int j = 0; j < 26; j++)
        {
            if (i > 0 && (dp_bits[i - 1].first & (1 << j)) != 0) left++;
            if (i < n - 1 && (dp_bits[i + 1].second & (1 << j)) != 0) right++;
            if ((i > 0 && i < n - 1 && 
                ((dp_bits[i - 1].first & (1 << j)) == 0) &&
                ((dp_bits[i + 1].second & (1 << j)) == 0)) ||
                (i == 0 && i < n - 1 && ((dp_bits[i + 1].second & (1 << j)) == 0)) ||
                (i == n - 1 && i > 0 && ((dp_bits[i - 1].first & (1 << j)) == 0)))
            {
                center = 1;
            }
            if ((i > 0) && (i < n - 1) && 
                ((dp_bits[i - 1].first & (1 << j)) != 0) &&
                ((dp_bits[i + 1].second & (1 << j)) != 0))
            {
                common++;
            }
        }
        int left_parts = i > 0 ? dp_parts[i - 1].first : 0;
        int right_parts = i < n - 1 ? dp_parts[i + 1].second : 0;
        if (left == k && right == k && center == 1)
        {
            result = max(result, left_parts + right_parts + 3);
        }
        else if (left + right - common + center > k)
        {
            result = max(result, left_parts + right_parts + 2);
        }
        else
        {
            result = max(result, left_parts + right_parts + 1);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3041. Maximize Consecutive Elements in an Array After 
///                 Modification
///
/// Hard
///
/// You are given a 0-indexed array nums consisting of positive integers.
///
/// Initially, you can increase the value of any element in the array by 
/// at most 1.
///
/// After that, you need to select one or more elements from the final 
/// array such that those elements are consecutive when sorted in 
/// increasing order. For example, the elements [3, 4, 5] are consecutive 
/// while [3, 4, 6] and [1, 1, 2, 3] are not.
///
/// Return the maximum number of elements that you can select.
///  
/// Example 1:
/// Input: nums = [2,1,5,1,1]
/// Output: 3
/// Explanation: We can increase the elements at indices 0 and 3. The 
/// resulting array is nums = [3,1,5,2,1].
/// We select the elements [3,1,5,2,1] and we sort them to obtain [1,2,3], 
/// which are consecutive.
/// It can be shown that we cannot select more than 3 consecutive elements.
///
/// Example 2:
/// Input: nums = [1,4,7,10]
/// Output: 1
/// Explanation: The maximum consecutive elements that we can select is 1.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^6
/// </summary>
int LeetCodeDP::maxSelectedElements(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int prev_modified = 0, prev_natural = 0;;
    int count_modified = 0, count_natural = 0;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            prev_modified = prev_natural = nums[i];
            count_modified = count_natural = 1;
        }
        else if (nums[i] == prev_modified)
        {
            prev_modified = nums[i] + 1;
            count_modified++;
        }
        else if (nums[i] == prev_modified + 1)
        {
            prev_modified = nums[i];
            count_modified++;
        }
        else if (nums[i] > prev_modified + 1)
        {
            prev_modified = nums[i];
            count_modified = 1;
        }
        if (nums[i] == prev_natural + 1)
        {
            prev_natural = nums[i];
            count_natural++;
        }
        else if (nums[i] > prev_natural + 1)
        {
            if ((nums[i] == prev_natural + 2) && (count_modified < count_natural + 1))
            {
                prev_modified = nums[i];
                count_modified = count_natural + 1;
            }
            prev_natural = nums[i];
            count_natural = 1;
        }
        result = max(result, count_modified);
        result = max(result, count_natural);
    }
    return result;
}

/// <summary>
/// Leet Code 87. Scramble String
///
/// Hard
///
/// We can scramble a string s to get a string t using the following 
/// algorithm:
///
/// If the length of the string is 1, stop.
/// If the length of the string is > 1, do the following:
/// Split the string into two non-empty substrings at a random index, 
/// i.e., if the string is s, divide it to x and y where s = x + y.
/// Randomly decide to swap the two substrings or to keep them in the 
/// same order. i.e., after this step, s may become s = x + y or 
/// s = y + x.
/// Apply step 1 recursively on each of the two substrings x and y.
/// Given two strings s1 and s2 of the same length, return true if s2 
/// is a scrambled string of s1, otherwise, return false.
///
/// Example 1:
/// Input: s1 = "great", s2 = "rgeat"
/// Output: true
/// Explanation: One possible scenario applied on s1 is:
/// "great" --> "gr/eat" // divide at random index.
/// "gr/eat" --> "gr/eat" // random decision is not to swap the two 
/// substrings and keep them in order.
/// "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on 
/// both substrings. divide at random index each of them.
/// "g/r / e/at" --> "r/g / e/at" // random decision was to swap the 
/// first substring and to keep the second substring in the same order.
/// "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm 
/// recursively, divide "at" to "a/t".
/// "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both 
/// substrings in the same order.
/// The algorithm stops now, and the result string is "rgeat" which is s2.
/// As one possible scenario led s1 to be scrambled to s2, we return true.
/// 
/// Example 2:
/// Input: s1 = "abcde", s2 = "caebd"
/// Output: false
///
/// Example 3:
/// Input: s1 = "a", s2 = "a"
/// Output: true
///
/// Constraints:
/// 1. s1.length == s2.length
/// 2. 1 <= s1.length <= 30
/// 3. s1 and s2 consist of lowercase English letters.
/// </summary>
bool LeetCodeDP::isScramble(string s1, string s2)
{
    int n = s1.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i + k >= n) break;
            for (int j = 0; j < n; j++)
            {
                if (j + k >= n) break;
                if (k == 0)
                {
                    if (s1[i] == s2[j]) dp[i][j][k] = 1;
                    else dp[i][j][k] = -1;
                }
                else
                {
                    for (int p = 0; p < k; p++)
                    {
                        if ((dp[i][j][p] == 1 && dp[i + p + 1][j + p + 1][k - p - 1] == 1) ||
                            (dp[i][j + k - p][p] == 1 && dp[i + p + 1][j][k - p - 1] == 1))
                        {
                            dp[i][j][k] = 1;
                            break;
                        }
                    }
                    if (dp[i][j][k] == 0)
                    {
                        dp[i][j][k] = -1;
                    }
                }
            }
        }
    }
    return dp[0][0][n - 1] == 1;
}



/// <summary>
/// Leet 3070. Count Submatrices with Top-Left Element and Sum Less Than k
///
/// Medium
///
/// You are given a 0-indexed integer matrix grid and an integer k.
/// Return the number of submatrices that contain the top-left element of 
/// the grid, and have a sum less than or equal to k.
///
/// Example 1:
/// Input: grid = [[7,6,3],[6,6,1]], k = 18
/// Output: 4
/// Explanation: There are only 4 submatrices, shown in the image above, 
/// that contain the top-left element of grid, and have a sum less than 
/// or equal to 18.
///
/// Example 2:
/// Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
/// Output: 6
/// Explanation: There are only 6 submatrices, shown in the image above, 
/// that contain the top-left element of grid, and have a sum less than 
/// or equal to 20.
/// 
/// Constraints:
/// 1. m == grid.length 
/// 2. n == grid[i].length
/// 3. 1 <= n, m <= 1000 
/// 4. 0 <= grid[i][j] <= 1000
/// 5. 1 <= k <= 10^9
/// </summary>
int LeetCodeDP::countSubmatrices(vector<vector<int>>& grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();
    int result = 0;
    vector<vector<pair<long long, long long>>> sum(n, vector<pair<long long, long long>>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum[i][j].first = grid[i][j];
            if (j > 0) sum[i][j].first += sum[i][j - 1].first;
            sum[i][j].second = sum[i][j].first;
            if (i > 0) sum[i][j].second += sum[i - 1][j].second;
            if (sum[i][j].second <= (long long)k) result++;
        }
    }
    return result;
}

/// <summary>
/// Leet 3082. Find the Sum of the Power of All Subsequences
///
/// Hard
///
/// You are given an integer array nums of length n and a positive 
/// integer k.
/// The power of an array of integers is defined as the number of 
/// subsequences with their sum equal to k.
///
/// Return the sum of power of all subsequences of nums.
/// Since the answer may be very large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input:  nums = [1,2,3], k = 3 
/// Output:  6 
/// Explanation:
/// There are 5 subsequences of nums with non-zero power:
/// The subsequence [1,2,3] has 2 subsequences with sum == 3: [1,2,3] 
/// and [1,2,3].
/// The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
/// The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
/// The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
/// The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
/// Hence the answer is 2 + 1 + 1 + 1 + 1 = 6.
///
/// Example 2:
/// Input:  nums = [2,3,3], k = 5 
/// Output:  4 
/// Explanation:
/// There are 3 subsequences of nums with non-zero power:
/// The subsequence [2,3,3] has 2 subsequences with sum == 5: [2,3,3] 
/// and [2,3,3].
/// The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
/// The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
/// Hence the answer is 2 + 1 + 1 = 4.
///
/// Example 3:
/// Input:  nums = [1,2,3], k = 7 
/// Output:  0 
/// Explanation: There exists no subsequence with sum 7. Hence all 
/// subsequences of nums have power = 0.
/// 
/// Constraints:
/// 1. 1 <= n <= 100
/// 2. 1 <= nums[i] <= 10^4
/// 3. 1 <= k <= 100
/// </summary>
int LeetCodeDP::sumOfPower(vector<int>& nums, int k)
{
    long long M = 1000000007;
    int n = nums.size();
    vector<long long> power(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0) power[i] = 1;
        else power[i] = power[i - 1] * 2 % M;
    }
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (j == 0)
            {
                if (nums[i] <= k)
                {
                    dp[0][nums[i]] = (dp[0][nums[i]] + 1) % M;
                }
            }
            else
            {
                for (int p = 0; p <= k; p++)
                {
                    int target = p + nums[i];
                    if (target > k) continue;
                    dp[j][target] = (dp[j][target] + dp[j - 1][p]) % M;
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = (result + (int)(((long long)dp[i][k] * power[n - 1 - i]) % M)) % M;
    }
    return result;
}


/// <summary>
/// Leet 3077. Maximum Strength of K Disjoint Subarrays
///
/// Hard
///
/// You are given a 0-indexed array of integers nums of length n, and a 
/// positive odd integer k.
///
/// The strength of x subarrays is defined as strength = sum[1] * x - 
/// sum[2] * (x - 1) + sum[3] * (x - 2) - sum[4] * (x - 3) + ... + 
/// sum[x] * 1 where sum[i] is the sum of the elements in the ith subarray. 
/// Formally, strength is sum of (-1)i+1 * sum[i] * (x - i + 1) 
/// over all i's such that 1 <= i <= x.
///
/// You need to select k disjoint subarrays from nums, such that their 
/// strength is maximum.
///
/// Return the maximum possible strength that can be obtained.
/// Note that the selected subarrays don't need to cover the entire array.
/// 
/// Example 1:
/// Input: nums = [1,2,3,-1,2], k = 3
/// Output: 22
/// Explanation: The best possible way to select 3 subarrays is: 
/// nums[0..2], nums[3..3], and nums[4..4]. The strength is 
/// (1 + 2 + 3) * 3 - (-1) * 2 + 2 * 1 = 22.
///
/// Example 2:
/// Input: nums = [12,-2,-2,-2,-2], k = 5
/// Output: 64
/// Explanation: The only possible way to select 5 disjoint subarrays 
/// is: nums[0..0], nums[1..1], nums[2..2], nums[3..3], and nums[4..4]. 
/// The strength is 12 * 5 - (-2) * 4 + (-2) * 3 - (-2) * 2 + 
/// (-2) * 1 = 64.
///
/// Example 3:
/// Input: nums = [-1,-2,-3], k = 1
/// Output: -1
/// Explanation: The best possible way to select 1 subarray is: 
/// nums[0..0]. The strength is -1.
/// 
/// Constraints:
/// 1. 1 <= n <= 10^4
/// 2. -10^9 <= nums[i] <= 10^9
/// 3. 1 <= k <= n
/// 4. 1 <= n * k <= 10^6
/// 5. k is odd.
/// </summary>
long long LeetCodeDP::maximumStrength(vector<int>& nums, int k)
{
    vector<vector<long long>> dp(k, vector<long long>(nums.size(), 0));
    int n = nums.size();

    for (int i = 0; i < k; i++)
    {
        long long maxSum = LLONG_MIN;
        long long curr = 0;
        long long multiplier = (i % 2 == 0) ? (k - i) : (i - k);
        for (int j = i; j < n - (k - 1) + i; j++)
        {
            long long prev = (i == 0) ? 0 : dp[i - 1][j - 1];
            if (j == i) curr = prev + nums[j] * multiplier;
            else curr = max(curr + nums[j] * multiplier, prev + nums[j] * multiplier);
            maxSum = max(maxSum, curr);
            dp[i][j] = maxSum;
        }
    }
    return dp[k - 1][nums.size() - 1];
}

/// <summary>
/// LeetCode 3122. Minimum Number of Operations to Satisfy Conditions
///                
/// Medium
///
/// You are given a 2D matrix grid of size m x n. In one operation, you 
/// can change the value of any cell to any non-negative number. You need 
/// to perform some operations such that each cell grid[i][j] is:
///
/// Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it 
/// exists).
/// Different from the cell to its right, i.e. 
/// grid[i][j] != grid[i][j + 1] (if it exists).
/// Return the minimum number of operations needed.
/// 
/// Example 1:
/// Input: grid = [[1,0,2],[1,0,2]]
/// Output: 0
/// Explanation:
/// All the cells in the matrix already satisfy the properties.
///
/// Example 2:
/// Input: grid = [[1,1,1],[0,0,0]]
/// Output: 3
/// Explanation:
/// The matrix becomes [[1,0,1],[1,0,1]] which satisfies the properties, 
/// by doing these 3 operations:
///
/// Change grid[1][0] to 1.
/// Change grid[0][1] to 0.
/// Change grid[1][2] to 1.
/// Example 3:
/// Input: grid = [[1],[2],[3]]
/// Output: 2
/// Explanation:
/// There is a single column. We can change the value to 1 in each cell 
/// using 2 operations.
/// 
/// Constraints:
/// 1. 1 <= n, m <= 1000
/// 2. 0 <= grid[i][j] <= 9
/// </summary>
int LeetCodeDP::minimumOperationsGrid(vector<vector<int>>& grid)
{
    vector<int> prev(10);
    for (size_t i = 0; i < grid[0].size(); i++)
    {
        vector<int> frequency(10);
        for (size_t j = 0; j < grid.size(); j++)
        {
            frequency[grid[j][i]]++;
        }
        vector<int> dp(10);
        for (int j = 0; j < 10; j++)
        {
            dp[j] = INT_MAX;
            for (int k = 0; k < 10; k++)
            {
                if (j == k) continue;
                dp[j] = min(dp[j], prev[k]);
            }
            dp[j] += grid.size() - frequency[j];
        }
        prev = dp;
    }
    int result = INT_MAX;
    for (int i = 0; i < 10; i++)
    {
        result = min(result, prev[i]);
    }
    return result;
}

/// <summary>
/// LeetCode 3117. Minimum Sum of Values by Dividing Array
/// </summary>
int LeetCodeDP::minimumValueSum(vector<int>& nums, vector<int>& andValues, int numIndex, int andIndex,
    int value, vector<vector<unordered_map<int, int>>>& cache)
{
    if (numIndex == nums.size() && andIndex == andValues.size())
    {
        return 0;
    }
    else if (numIndex == nums.size()) return INT_MAX;
    else if (andIndex == andValues.size()) return INT_MAX;
    // return cache
    value &= nums[numIndex];
    if (cache[numIndex][andIndex].count(value) > 0) return cache[numIndex][andIndex][value];
    // test bit
    for (int i = 0; i < 20; i++)
    {
        int bit = (1 << i);
        if (((bit & value) == 0) && ((bit & andValues[andIndex]) != 0))
        {
            return INT_MAX;
        }
    }
    int result = INT_MAX;
    if (value == andValues[andIndex])
    {
        result = minimumValueSum(nums, andValues, numIndex + 1, andIndex + 1,
            ((1 << 20) - 1), cache);
        result = result == INT_MAX ? result : result + nums[numIndex];
    }
    result = min(result, minimumValueSum(nums, andValues, numIndex + 1, andIndex,
        value, cache));
    
    cache[numIndex][andIndex][value] = result;
    return result;
}

/// <summary>
/// LeetCode 3117. Minimum Sum of Values by Dividing Array
///                
/// Hard
///
/// You are given two arrays nums and andValues of length n and m 
/// respectively.
///
/// The value of an array is equal to the last element of that array.
///
/// You have to divide nums into m disjoint contiguous subarrays such 
/// that for the ith subarray [li, ri], the bitwise AND of the subarray 
/// elements is equal to andValues[i], in other words, 
/// nums[li] & nums[li + 1] & ... & nums[ri] == andValues[i] for 
/// all 1 <= i <= m, where & represents the bitwise AND operator.
///
/// Return the minimum possible sum of the values of the m subarrays 
/// nums is divided into. If it is not possible to divide nums into m 
/// subarrays satisfying these conditions, return -1.
///
/// Example 1:
/// Input: nums = [1,4,3,3,2], andValues = [0,3,3,2]
/// Output: 12
/// Explanation:
/// The only possible way to divide nums is:
/// [1,4] as 1 & 4 == 0.
/// [3] as the bitwise AND of a single element subarray is that element 
/// itself.
/// [3] as the bitwise AND of a single element subarray is that element 
/// itself.
/// [2] as the bitwise AND of a single element subarray is that element 
/// itself.
/// The sum of the values for these subarrays is 4 + 3 + 3 + 2 = 12.
///
/// Example 2:
/// Input: nums = [2,3,5,7,7,7,5], andValues = [0,7,5]
/// Output: 17
/// Explanation:
/// There are three ways to divide nums:
/// [[2,3,5],[7,7,7],[5]] with the sum of the values 5 + 7 + 5 == 17.
/// [[2,3,5,7],[7,7],[5]] with the sum of the values 7 + 7 + 5 == 19.
/// [[2,3,5,7,7],[7],[5]] with the sum of the values 7 + 7 + 5 == 19.
/// The minimum possible sum of the values is 17.
///
/// Example 3:
/// Input: nums = [1,2,3,4], andValues = [2]
/// Output: -1
/// Explanation:
/// The bitwise AND of the entire array nums is 0. As there is no 
/// possible way to divide nums into a single subarray to have the 
/// bitwise AND of elements 2, return -1.
/// 
/// Constraints:
/// 1. 1 <= n == nums.length <= 10^4
/// 2. 1 <= m == andValues.length <= min(n, 10)
/// 3. 1 <= nums[i] < 10^5
/// 4. 0 <= andValues[j] < 10^5
/// </summary>
int LeetCodeDP::minimumValueSum(vector<int>& nums, vector<int>& andValues)
{
    int n = nums.size();
    int m = andValues.size();
    vector<vector<unordered_map<int, int>>> cache(n, 
        vector<unordered_map<int, int>>(andValues.size()));
    int result = minimumValueSum(nums, andValues, 0, 0, nums[0], cache);
    result = (result == INT_MAX) ? -1 : result;
    return result;
}

/// <summary>
/// LeetCode 3129. Find All Possible Stable Binary Arrays I
///                
/// Medium
///
/// You are given 3 positive integers zero, one, and limit.
/// A binary array arr is called stable if:
///
/// The number of occurrences of 0 in arr is exactly zero.
/// The number of occurrences of 1 in arr is exactly one.
/// Each subarray of arr with a size greater than limit must contain 
/// both 0 and 1.
/// Return the total number of stable binary arrays.
/// Since the answer may be very large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: zero = 1, one = 1, limit = 2
/// Output: 2
/// Explanation:
/// The two possible stable binary arrays are [1,0] and [0,1], as both 
/// arrays have a single 0 and a single 1, and no subarray has a length 
/// greater than 2.
///
/// Example 2:
/// Input: zero = 1, one = 2, limit = 1
/// Output: 1
/// Explanation:
/// The only possible stable binary array is [1,0,1].
/// Note that the binary arrays [1,1,0] and [0,1,1] have subarrays of 
/// length 2 with identical elements, hence, they are not stable.
///
/// Example 3:
/// Input: zero = 3, one = 3, limit = 2
/// Output: 14
/// Explanation:
/// All the possible stable binary arrays are [0,0,1,0,1,1], 
/// [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], 
/// [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], 
/// [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], 
/// and [1,1,0,1,0,0].
///
/// Constraints:
/// 1. 1 <= zero, one, limit <= 200
/// </summary>
int LeetCodeDP::numberOfStableArraysI(int zero, int one, int limit)
{
    vector <vector<pair<long long, long long>>> dp(zero+1, vector<pair<long long, long long>>(one+1));
    long long M = 1000000007;

    for (int i = 0; i < zero+1; i++)
    {
        for (int j = 0; j < one+1; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j].first = 0;
                dp[i][j].second = 0;
            }
            else if (i == 0)
            {
                if (j <= limit) dp[i][j].second = 1;
            }
            else if (j == 0)
            {
                if (i <= limit) dp[i][j].first = 1;
            }
            else
            {
                dp[i][j].first = (dp[i - 1][j].first + dp[i - 1][j].second) % M;
                dp[i][j].second = (dp[i][j - 1].first + dp[i][j - 1].second) % M;
                if (i > limit) dp[i][j].first = (dp[i][j].first + M - dp[i - limit - 1][j].second) % M;
                if (j > limit) dp[i][j].second = (dp[i][j].second + M - dp[i][j - limit - 1].first) % M;
            }
        }
    }
    int result = (int)(dp[zero][one].first + dp[zero][one].second) % M;
    return result;
}

/// <summary>
/// LeetCode 3130. Find All Possible Stable Binary Arrays II
///                
/// Hard
///
/// You are given 3 positive integers zero, one, and limit.
/// A binary array arr is called stable if:
/// The number of occurrences of 0 in arr is exactly zero.
/// The number of occurrences of 1 in arr is exactly one.
/// Each subarray of arr with a size greater than limit must contain 
/// both 0 and 1.
/// Return the total number of stable binary arrays.
/// Since the answer may be very large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: zero = 1, one = 1, limit = 2
/// Output: 2
/// Explanation:
/// The two possible stable binary arrays are [1,0] and [0,1].
///
/// Example 2:
/// Input: zero = 1, one = 2, limit = 1
/// Output: 1
/// Explanation:
/// The only possible stable binary array is [1,0,1].
///
/// Example 3:
/// Input: zero = 3, one = 3, limit = 2
/// Output: 14
/// Explanation:
/// All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1],
/// [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], 
/// [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], 
/// [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].
///
/// Constraints:
/// 1. 1 <= zero, one, limit <= 1000
/// </summary>
int LeetCodeDP::numberOfStableArraysII(int zero, int one, int limit)
{
    vector <vector<pair<long long, long long>>> dp(zero + 1, vector<pair<long long, long long>>(one + 1));
    long long M = 1000000007;

    for (int i = 0; i < zero + 1; i++)
    {
        for (int j = 0; j < one + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j].first = 0;
                dp[i][j].second = 0;
            }
            else if (i == 0)
            {
                if (j <= limit) dp[i][j].second = 1;
            }
            else if (j == 0)
            {
                if (i <= limit) dp[i][j].first = 1;
            }
            else
            {
                dp[i][j].first = (dp[i - 1][j].first + dp[i - 1][j].second) % M;
                dp[i][j].second = (dp[i][j - 1].first + dp[i][j - 1].second) % M;
                if (i > limit) dp[i][j].first = (dp[i][j].first + M - dp[i - limit - 1][j].second) % M;
                if (j > limit) dp[i][j].second = (dp[i][j].second + M - dp[i][j - limit - 1].first) % M;
            }
        }
    }
    int result = (int)(dp[zero][one].first + dp[zero][one].second) % M;
    return result;
}

/// <summary>
/// LeetCode 3135. Equalize Strings by Adding or Removing Characters at 
///                Ends
/// 
/// Medium
///
/// Given two strings initial and target, your task is to modify initial 
/// by performing a series of operations to make it equal to target.
///
/// In one operation, you can add or remove one character only at the 
/// beginning or the end of the string initial.
///
/// Return the minimum number of operations required to transform initial 
/// into target.
/// 
/// Example 1:
/// Input: initial = "abcde", target = "cdef"
/// Output: 3
/// Explanation:
/// Remove 'a' and 'b' from the beginning of initial, then add 'f' to 
/// the end.
///
/// Example 2:
/// Input: initial = "axxy", target = "yabx"
/// Output: 6
/// Explanation:
/// Operation	Resulting String
/// Add 'y' to the beginning	"yaxxy"
/// Remove from end	"yaxx"
/// Remove from end	"yax"
/// Remove from end	"ya"
/// Add 'b' to the end	"yab"
/// Add 'x' to the end	"yabx"
///
/// Example 3:
/// Input: initial = "xyz", target = "xyz"
/// Output: 0
/// Explanation:
/// No operations are needed as the strings are already equal.
/// 
/// Constraints:
/// 1. 1 <= initial.length, target.length <= 1000
/// 2. initial and target consist only of lowercase English letters.
/// </summary>
int LeetCodeDP::minOperations(string initial, string target)
{
    vector<vector<int>>dp(initial.size(), vector<int>(target.size()));
    int max_len = 0;
    for (size_t i = 0; i < initial.size(); i++)
    {
        for (size_t j = 0; j < target.size(); j++)
        {
            if (initial[i] == target[j])
            {
                dp[i][j] = 1;
                if (i > 0 && j > 0)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                max_len = max(max_len, dp[i][j]);
            }
        }
    }
    return initial.size() + target.size() - 2 * max_len;
}

/// <summary>
/// LeetCode 3147. Taking Maximum Energy From the Mystic Dungeon
/// 
/// Medium
///
/// In a mystic dungeon, n magicians are standing in a line. Each magician 
/// has an attribute that gives you energy. Some magicians can give you 
/// negative energy, which means taking energy from you.
///
/// You have been cursed in such a way that after absorbing energy from 
/// magician i, you will be instantly transported to magician (i + k). 
/// This process will be repeated until you reach the magician where 
/// (i + k) does not exist.
///
/// In other words, you will choose a starting point and then teleport 
/// with k jumps until you reach the end of the magicians' sequence, 
/// absorbing all the energy during the journey.
///
/// You are given an array energy and an integer k. Return the maximum 
/// possible energy you can gain.
/// 
/// Example 1:
/// Input: energy = [5,2,-10,-5,1], k = 3
/// Output: 3
/// Explanation: We can gain a total energy of 3 by starting from 
/// magician 1 absorbing 2 + 1 = 3.
/// Example 2:
/// Input: energy = [-2,-3,-1], k = 2
///
/// Output: -1
/// Explanation: We can gain a total energy of -1 by starting from 
/// magician 2.
/// 
/// Constraints:
/// 1. 1 <= energy.length <= 10^5
/// 2. -1000 <= energy[i] <= 1000
/// 3. 1 <= k <= energy.length - 1
/// </summary>
int LeetCodeDP::maximumEnergy(vector<int>& energy, int k)
{
    vector<int> dp(energy.size());
    int result = INT_MIN;
    int prev = 0;
    for (int i = 0; i < (int)energy.size(); i++)
    {
        if (i - k < 0)
        {
            dp[i] = energy[i];
        }
        else
        {
            dp[i] = max(dp[i-k], 0) + energy[i];
        }
        if (i + k >= (int)dp.size()) result = max(result, dp[i]);
    }
    return result;
}

/// <summary>
/// LeetCode 3144. Minimum Substring Partition of Equal Character Frequency
/// 
/// Medium
///
/// Given a string s, you need to partition it into one or more balanced 
/// substrings. For example, if s == "ababcc" then ("abab", "c", "c"), 
/// ("ab", "abc", "c"), and ("ababcc") are all valid partitions, but 
/// ("a", "bab", "cc"), ("aba", "bc", "c"), and ("ab", "abcc") are not. 
/// The unbalanced substrings are bolded.
///
/// Return the minimum number of substrings that you can partition s into.
///
/// Note: A balanced string is a string where each character in the string 
/// occurs the same number of times.
/// 
/// Example 1:
/// Input: s = "fabccddg"
/// Output: 3
/// Explanation:
/// We can partition the string s into 3 substrings in one of the 
/// following ways: ("fab, "ccdd", "g"), or ("fabc", "cd", "dg").
///
/// Example 2:
/// Input: s = "abababaccddb"
///
/// Output: 2
/// Explanation:
/// We can partition the string s into 2 substrings like so: ("abab", 
/// "abaccddb").
/// 
/// 
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s consists only of English lowercase letters.
/// </summary>
int LeetCodeDP::minimumSubstringsInPartition(string s)
{
    vector<int> dp(s.size(), INT_MAX);
    dp[0] = 0;
    int result = INT_MAX;
    for (size_t i = 0; i < s.size(); i++)
    {
        vector<int> chars(26);
        set<pair<int, char>> char_set;
        for (size_t j = i; j < s.size(); j++)
        {
            int idx = s[j] - 'a';
            chars[idx]++;
            int max_f = chars[idx];
            bool balance = true;
            for (int k = 0; k < 26; k++)
            {
                if (chars[k] == 0) continue;
                if (chars[k] != max_f)
                {
                    balance = false;
                    break;
                }
            }
            if (balance == true)
            {
                if (j + 1 == s.size()) result = min(result, dp[i] + 1);
                else dp[j + 1] = min(dp[j+1], dp[i] + 1);
            }
        }
    }
    return result;
}

/// <summary>
/// LeetCode 3176. Find the Maximum Length of a Good Subsequence I
/// 
/// Medium
/// 
/// You are given an integer array nums and a non-negative integer k. A 
/// sequence of integers seq is called good if there are at most k indices 
/// i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
///
/// Return the maximum possible length of a good subsequence of nums.
///
/// Example 1:
/// Input: nums = [1,2,1,1,3], k = 2
/// Output: 4
/// Explanation:
/// The maximum length subsequence is [1,2,1,1,3].
///
/// Example 2:
/// Input: nums = [1,2,3,4,5,1], k = 0
/// Output: 2
/// Explanation:
/// The maximum length subsequence is [1,2,3,4,5,1].
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 500
/// 2. 1 <= nums[i] <= 10^9
/// 3. 0 <= k <= min(nums.length, 25)
/// </summary>
int LeetCodeDP::maximumLengthI(vector<int>& nums, int k)
{
    int result = 0;
    vector<unordered_map<int, int>>dp(k + 1);
    vector<int>max_length(k + 1);
    for (size_t i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        for (int j = k; j >= 0; j--)
        {
            dp[j][a] = dp[j][a] + 1;
            if (j > 0)
            {
                dp[j][a] = max(dp[j][a], max_length[j - 1] + 1);
            }
            max_length[j] = max(max_length[j], dp[j][a]);
            result = max(result, max_length[j]);
        }
    }
    return result;
}

/// <summary>
/// LeetCode 3177. Find the Maximum Length of a Good Subsequence II
/// 
/// Hard
///
/// You are given an integer array nums and a non-negative integer k. A 
/// sequence of integers seq is called good if there are at most k indices 
/// i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
///
/// Return the maximum possible length of a good subsequence of nums.
///
/// Example 1:
/// Input: nums = [1,2,1,1,3], k = 2
/// Output: 4
/// Explanation:
/// The maximum length subsequence is [1,2,1,1,3].
///
/// Example 2:
/// Input: nums = [1,2,3,4,5,1], k = 0
/// Output: 2
/// Explanation:
/// The maximum length subsequence is [1,2,3,4,5,1].
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 5 * 10^3
/// 2. 1 <= nums[i] <= 10^9
/// 3. 0 <= k <= min(50, nums.length)
/// </summary>
int LeetCodeDP::maximumLengthII(vector<int>& nums, int k)
{
    int result = 0;
    vector<unordered_map<int, int>>dp(k + 1);
    vector<int>max_length(k + 1);
    for (size_t i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        for (int j = k; j >= 0; j--)
        {
            dp[j][a] = dp[j][a] + 1;
            if (j > 0)
            {
                dp[j][a] = max(dp[j][a], max_length[j - 1] + 1);
            }
            max_length[j] = max(max_length[j], dp[j][a]);
            result = max(result, max_length[j]);
        }
    }
    return result;
}

/// <summary>
/// LeetCode 3180. Maximum Total Reward Using Operations I
/// 
/// Medium
///
/// You are given an integer array rewardValues of length n, representing 
/// the values of rewards.
///
/// Initially, your total reward x is 0, and all indices are unmarked. You 
/// are allowed to perform the following operation any number of times:
///
/// Choose an unmarked index i from the range [0, n - 1].
/// If rewardValues[i] is greater than your current total reward x, then 
/// add rewardValues[i] to x (i.e., x = x + rewardValues[i]), and mark the 
/// index i.
/// Return an integer denoting the maximum total reward you can collect by 
/// performing the operations optimally.
///
/// Example 1:
/// Input: rewardValues = [1,1,3,3]
/// Output: 4
/// Explanation:
/// During the operations, we can choose to mark the indices 0 and 2 in 
/// order, and the total reward will be 4, which is the maximum.
///
/// Example 2:
/// Input: rewardValues = [1,6,4,3,2]
///
/// Output: 11
/// Explanation:
/// Mark the indices 0, 2, and 1 in order. The total reward will then be 
/// 11, which is the maximum.
///
/// Constraints:
/// 1. 1 <= rewardValues.length <= 2000
/// 2. 1 <= rewardValues[i] <= 2000
/// </summary>
int LeetCodeDP::maxTotalRewardI(vector<int>& rewardValues)
{
    sort(rewardValues.begin(), rewardValues.end());
    int k = rewardValues.back();
    vector<int>dp(k);
    dp[0] = 1;
    int result = 0;
    for (size_t i = 0; i < rewardValues.size(); i++)
    {
        if (i > 0 && rewardValues[i] == rewardValues[i - 1]) continue;
        int m = rewardValues[i];
        if (m != k) m = min(m, k - rewardValues[i]);
        for (int j = m - 1; j >= 0; j--)
        {
            if (dp[j] == 1)
            {
                int p = j + rewardValues[i];
                result = max(result, p);
                if (p < k)
                {
                    dp[p] = 1;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// LeetCode 3186. Maximum Total Damage With Spell Casting
///
/// Medium
/// 
/// A magician has various spells.
///
/// You are given an array power, where each element represents the damage 
/// of a spell. Multiple spells can have the same damage value.
///
/// It is a known fact that if a magician decides to cast a spell with a 
/// damage of power[i], they cannot cast any spell with a damage of 
/// power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
///
/// Each spell can be cast only once.
/// Return the maximum possible total damage that a magician can cast.
/// 
/// Example 1:
/// Input: power = [1,1,3,4]
/// Output: 6
/// Explanation:
///  
/// The maximum possible damage of 6 is produced by casting spells 0, 1, 3 
/// with damage 1, 1, 4.
/// 
/// Example 2:
/// Input: power = [7,1,6,6]
/// Output: 13
/// Explanation:
/// The maximum possible damage of 13 is produced by casting spells 
/// 1, 2, 3 with damage 1, 6, 6.
///
/// Constraints:
/// 1. 1 <= power.length <= 10^5
/// 2. 1 <= power[i] <= 10^9
/// </summary>
long long LeetCodeDP::maximumTotalDamage(vector<int>& power)
{
    long long result = 0, prev = 0;
    map<int, long long> power_count;
    for (auto i : power) power_count[i] += i;
    queue<pair<int, long long>> queue;
    for (auto& itr : power_count)
    {
        while (!queue.empty() && queue.front().first + 2 < itr.first)
        {
            prev = max(prev, queue.front().second);
            queue.pop();
        }
        long long val = prev + itr.second;
        result = max(result, val);
        queue.push(make_pair(itr.first, val));
    }
    return result;
}

/// <summary>
/// LeetCode 3196. Maximize Total Cost of Alternating Subarrays 
///
/// Medium
/// 
/// You are given an integer array nums with length n.
/// The cost of a subarray 
/// nums[l..r], where 0 <= l <= r < n, is defined as:
///
/// cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)r − l
///
/// Your task is to split nums into subarrays such that the total 
/// cost of the subarrays is maximized, ensuring each element belongs 
/// to exactly one subarray.
/// Formally, if nums is split into k subarrays, where k > 1, at 
/// indices i1, i2, ..., ik − 1, where 0 <= i1 < i2 < ... < 
/// ik - 1 < n - 1, then the total cost will be:
///
/// cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik − 1 + 1, n − 1)
///
/// Return an integer denoting the maximum total cost of the subarrays 
/// after splitting the array optimally.
///
/// Note: If nums is not split into subarrays, i.e. k = 1, the total 
/// cost is simply cost(0, n - 1).
///
/// Example 1:
/// Input: nums = [1,-2,3,4]
/// Output: 10
/// Explanation:
/// One way to maximize the total cost is by splitting [1, -2, 3, 4] into 
/// subarrays [1, -2, 3] and [4]. The total cost will be 
/// (1 + 2 + 3) + 4 = 10.
///
/// Example 2:
/// Input: nums = [1,-1,1,-1]
/// Output: 4
/// Explanation:
/// One way to maximize the total cost is by splitting [1, -1, 1, -1] 
/// into subarrays [1, -1] and [1, -1]. The total cost will be (1 + 1) 
/// + (1 + 1) = 4.
///
/// Example 3:
/// Input: nums = [0]
/// Output: 0
/// Explanation:
/// We cannot split the array further, so the answer is 0.
///
/// Example 4:
/// Input: nums = [1,-1]
/// Output: 2
/// Explanation:
/// Selecting the whole array gives a total cost of 1 + 1 = 2, which is 
/// the maximum.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. -10^9 <= nums[i] <= 10^9
/// </summary>
long long LeetCodeDP::maximumTotalCost(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<long long>> dp(n, vector<long long>(2));
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i][0] = nums[0];
            dp[i][1] = nums[0];
        }
        else
        {
            dp[i][0] = dp[i - 1][1] + nums[i];
            dp[i][1] = max(dp[i - 1][0] - nums[i], dp[i - 1][1] + nums[i]);
        }
    }
    return dp[n-1][1];
}

/// <summary>
/// LeetCode 3193. Count the Number of Inversions
///
/// Hard
///
/// You are given an integer n and a 2D array requirements, where 
/// requirements[i] = [endi, cnti] represents the end index and the 
/// inversion count of each requirement.
///
/// A pair of indices (i, j) from an integer array nums is called an 
/// inversion if:
///
/// i < j and nums[i] > nums[j]
/// Return the number of permutations perm of [0, 1, 2, ..., n - 1] such 
/// that for all requirements[i], perm[0..endi] has exactly cnti 
/// inversions.
///
/// Since the answer may be very large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: n = 3, requirements = [[2,2],[0,0]]
/// Output: 2
/// Explanation:
/// The two permutations are: [2, 0, 1]
/// Prefix [2, 0, 1] has inversions (0, 1) and (0, 2).
/// Prefix [2] has 0 inversions. [1, 2, 0]
/// Prefix [1, 2, 0] has inversions (0, 2) and (1, 2).
/// Prefix [1] has 0 inversions.
///
/// Example 2:
/// Input: n = 3, requirements = [[2,2],[1,1],[0,0]]
/// Output: 1
/// Explanation:
/// The only satisfying permutation is [2, 0, 1]:
/// Prefix [2, 0, 1] has inversions (0, 1) and (0, 2).
/// Prefix [2, 0] has an inversion (0, 1).
/// Prefix [2] has 0 inversions.
///
/// Example 3:
/// Input: n = 2, requirements = [[0,0],[1,0]]
/// Output: 1
/// Explanation:
/// The only satisfying permutation is [0, 1]:
/// Prefix [0] has 0 inversions.
/// Prefix [0, 1] has an inversion (0, 1).
///
/// Constraints:
/// 1. 2 <= n <= 300
/// 2. 1 <= requirements.length <= n
/// 3. requirements[i] = [endi, cnti]
/// 4. 0 <= endi <= n - 1
/// 5. 0 <= cnti <= 400
/// 6. The input is generated such that there is at least one i such that 
///    endi == n - 1.
/// 7. The input is generated such that all endi are unique.
/// </summary>
int LeetCodeDP::numberOfPermutations(int n, vector<vector<int>>& requirements)
{
    sort(begin(requirements), end(requirements));
    int dp[2][401] = { 1 }, prev = 0, j = 0, mod = 1000000007;
    for (int N = 1; N <= n; ++N) 
    {
        for (int K = prev; K <= requirements[j][1]; ++K) 
        {
            dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % mod;
            if (K >= N)
                dp[N % 2][K] = (mod + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % mod;
        }
        if (N - 1 == requirements[j][0]) 
        {
            fill_n(begin(dp[0]) + prev, requirements[j][1] - prev, 0);
            fill_n(begin(dp[1]) + prev, requirements[j][1] - prev, 0);
            prev = requirements[j++][1];
        }
    }
    return dp[n % 2][requirements.back()[1]];
}

/// <summary>
/// LeetCode 3201. Find the Maximum Length of Valid Subsequence I
///
/// Medium
///
/// You are given an integer array nums.
/// A subsequence sub of nums with length x is called valid if it 
/// satisfies:
/// (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == 
/// (sub[x - 2] + sub[x - 1]) % 2.
/// Return the length of the longest valid subsequence of nums.
///
/// A subsequence is an array that can be derived from another array by 
/// deleting some or no elements without changing the order of the 
/// remaining elements.
///
/// Example 1:
/// Input: nums = [1,2,3,4]
/// Output: 4
///
/// Explanation:
/// The longest valid subsequence is [1, 2, 3, 4].
///
/// Example 2:
/// Input: nums = [1,2,1,1,2,1,2]
/// Output: 6
/// Explanation:
/// The longest valid subsequence is [1, 2, 1, 2, 1, 2].
///
/// Example 3:
/// Input: nums = [1,3]
/// Output: 2
///
/// Explanation:
/// The longest valid subsequence is [1, 3].
/// Constraints:
/// 1. 2 <= nums.length <= 2 * 10^5
/// 2. 1 <= nums[i] <= 10^7
/// </summary>
int LeetCodeDP::maximumLengthI(vector<int>& nums)
{
    vector<vector<int>>dp(2, vector<int>(2));
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int bit = nums[i] % 2;
        dp[bit][0] = dp[bit][0] + 1;
        dp[bit][1] = dp[1 - bit][1] + 1;
        result = max(result, dp[bit][0]);
        result = max(result, dp[bit][1]);
    }
    return result;
}

/// <summary>
/// LeetCode 3202. Find the Maximum Length of Valid Subsequence II
///
/// Medium
///
/// You are given an integer array nums and a positive integer k.
/// A subsequence sub of nums with length x is called valid if it 
/// satisfies:
///
/// (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + 
/// sub[x - 1]) % k.
/// Return the length of the longest valid subsequence of nums.
///
/// Example 1:
/// Input: nums = [1,2,3,4,5], k = 2
/// Output: 5
/// Explanation:
/// The longest valid subsequence is [1, 2, 3, 4, 5].
///
/// Example 2:
/// Input: nums = [1,4,2,3,1,4], k = 3
/// Output: 4
/// Explanation:
/// The longest valid subsequence is [1, 4, 1, 4].
///
/// Constraints:
/// 1. 2 <= nums.length <= 10^3
/// 2. 1 <= nums[i] <= 10^7
/// 3. 1 <= k <= 10^3
/// </summary>
int LeetCodeDP::maximumLengthModII(vector<int>& nums, int k)
{
    vector<int> exist(k);
    vector<vector<int>> dp(k, vector<int>(k));
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int m = nums[i] % k;
        for (int j = 0; j < k; j++)
        {
            if (exist[j] != 0)
            {
                int n = (j + m) % k;
                if (dp[j][n] != 0)
                {
                    dp[m][n] = dp[j][n] + 1;
                }
                else
                {
                    dp[m][n] = 2;
                }
                result = max(dp[m][n], result);
            }
        }
        exist[m] = 1;
    }
    return result;
}

/// <summary>
/// Leet Code 3247. Number of Subsequences with Odd Sum
/// 
/// Medium
///
/// Given an array nums, return the number of subsequences with an odd sum 
/// of elements.
/// Since the answer may be very large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: nums = [1,1,1]
/// Output: 4
///
/// Explanation:
/// The odd-sum subsequences are: [1, 1, 1], [1, 1, 1], [1, 1, 1], 
/// [1, 1, 1].
///
/// Example 2:
/// Input: nums = [1,2,2]
/// Output: 4
/// Explanation:
/// The odd-sum subsequences are: [1, 2, 2], [1, 2, 2], [1, 2, 2], 
/// [1, 2, 2].
/// 
/// Constraints:
/// 1. 1 <= nums.lnegth <= 10^5
/// 2. 1 <= nums[i] <= 10^9
/// </summary>
int LeetCodeDP::subsequenceCount(vector<int>& nums)
{
    long long prev_odd = 0, prev_even = 0, odd = 0, even = 0;
    long long M = 1000000007;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            even = (1 + prev_even + prev_even) % M;
            odd = (0 + prev_odd + prev_odd) % M;
        }
        else
        {
            odd = (1 + prev_even + prev_odd) % M;
            even = (prev_odd + prev_even) % M;
        }
        prev_even = even;
        prev_odd = odd;
    }
    return (int)odd;
}

/// <summary>
/// Leet Code 3250. Find the Count of Monotonic Pairs I
/// 
/// Hard
///
/// You are given an array of positive integers nums of length n.
/// We call a pair of non-negative integer arrays (arr1, arr2) monotonic 
/// if: The lengths of both arrays are n.
/// arr1 is monotonically non-decreasing, in other words, arr1[0] <= 
/// arr1[1] <= ... <= arr1[n - 1].
/// arr2 is monotonically non-increasing, in other words, arr2[0] >= 
/// arr2[1] >= ... >= arr2[n - 1].
/// arr1[i] + arr2[i] == nums[i] for all 0 <= i <= n - 1.
/// Return the count of monotonic pairs.
/// 
/// Since the answer may be very large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: nums = [2,3,2]
/// Output: 4
/// Explanation:
/// The good pairs are:
/// ([0, 1, 1], [2, 2, 1])
/// ([0, 1, 2], [2, 2, 0])
/// ([0, 2, 2], [2, 1, 0])
/// ([1, 2, 2], [1, 1, 0])
///
/// Example 2:
/// Input: nums = [5,5,5,5]
/// Output: 126
/// 
/// Constraints:
/// 1. 1 <= n == nums.length <= 2000
/// 2. 1 <= nums[i] <= 50
/// </summary>
int LeetCodeDP::countOfPairsI(vector<int>& nums)
{
    int M = 1000000007;
    vector<vector<int>> dp(2, vector<int>(51));
    int curr = 0, prev = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j <= nums[i]; j++)
        {
            if (i == 0) dp[curr][j] = 1;
            else
            {
                int prev_index = min(nums[i - 1] - nums[i] + j, j);
                if (prev_index < 0) dp[curr][j] = 0;
                else dp[curr][j] = dp[prev][prev_index];
            }
            if (j > 0) dp[curr][j] = (dp[curr][j - 1] + dp[curr][j]) % M;
        }
        for (int j = nums[i] + 1; j <= 50; j++)
        {
            dp[curr][j] = dp[curr][nums[i]];
        }
        curr = 1 - curr;
        prev = 1 - prev;
    }
    return dp[prev][50];
}

/// <summary>
/// Leet Code 3251. Find the Count of Monotonic Pairs II
/// 
/// Hard
///
/// You are given an array of positive integers nums of length n.
/// We call a pair of non-negative integer arrays (arr1, arr2) monotonic 
/// if:
/// The lengths of both arrays are n.
/// arr1 is monotonically non-decreasing, in other words, arr1[0] <= 
/// arr1[1] <= ... <= arr1[n - 1].
/// arr2 is monotonically non-increasing, in other words, arr2[0] >= 
/// arr2[1] >= ... >= arr2[n - 1].
/// arr1[i] + arr2[i] == nums[i] for all 0 <= i <= n - 1.
/// Return the count of monotonic pairs.
///
/// Since the answer may be very large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: nums = [2,3,2]
/// Output: 4
/// Explanation:
/// The good pairs are:
/// ([0, 1, 1], [2, 2, 1])
/// ([0, 1, 2], [2, 2, 0])
/// ([0, 2, 2], [2, 1, 0])
/// ([1, 2, 2], [1, 1, 0])
///
/// Example 2:
/// Input: nums = [5,5,5,5]
/// Output: 126
/// 
/// Constraints:
/// 1. 1 <= n == nums.length <= 2000
/// 2. 1 <= nums[i] <= 1000
/// </summary>
int LeetCodeDP::countOfPairsII(vector<int>& nums)
{
    int M = 1000000007;
    vector<vector<int>> dp(2, vector<int>(1001));
    int curr = 0, prev = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j <= nums[i]; j++)
        {
            if (i == 0) dp[curr][j] = 1;
            else
            {
                int prev_index = min(nums[i - 1] - nums[i] + j, j);
                if (prev_index < 0) dp[curr][j] = 0;
                else dp[curr][j] = dp[prev][prev_index];
            }
            if (j > 0) dp[curr][j] = (dp[curr][j - 1] + dp[curr][j]) % M;
        }
        for (int j = nums[i] + 1; j <= 1000; j++)
        {
            dp[curr][j] = dp[curr][nums[i]];
        }
        curr = 1 - curr;
        prev = 1 - prev;
    }
    return dp[prev][1000];
}

/// <summary>
/// Leet Code 3259. Maximum Energy Boost From Two Drinks
/// 
/// Medium
///
/// You are given two integer arrays energyDrinkA and energyDrinkB of the 
/// same length n by a futuristic sports scientist. These arrays represent 
/// the energy boosts per hour provided by two different energy drinks, A 
/// and B, respectively.
///
/// You want to maximize your total energy boost by drinking one energy 
/// drink per hour. However, if you want to switch from consuming one 
/// energy drink to the other, you need to wait for one hour to cleanse 
/// your system (meaning you won't get any energy boost in that hour).
///
/// Return the maximum total energy boost you can gain in the next n 
/// hours.
/// 
/// Note that you can start consuming either of the two energy drinks.
/// 
/// Example 1:
/// Input: energyDrinkA = [1,3,1], energyDrinkB = [3,1,1]
/// Output: 5
/// Explanation:
/// To gain an energy boost of 5, drink only the energy drink A 
/// (or only B).
///
/// Example 2:
/// Input: energyDrinkA = [4,1,1], energyDrinkB = [1,1,3]
/// Output: 7
/// Explanation:
/// To gain an energy boost of 7:
/// Drink the energy drink A for the first hour.
/// Switch to the energy drink B and we lose the energy boost of the 
/// second hour.
/// Gain the energy boost of the drink B in the third hour.
///
/// Constraints:
/// 1. n == energyDrinkA.length == energyDrinkB.length
/// 2. 3 <= n <= 105
/// 3. 1 <= energyDrinkA[i], energyDrinkB[i] <= 105
/// </summary>
long long LeetCodeDP::maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB)
{
    int n = energyDrinkA.size();
    vector<vector<long long>>dp(n, vector<long long>(2));
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i][0] = (long long)energyDrinkA[i];
            dp[i][1] = (long long)energyDrinkB[i];
        }
        else
        {
            dp[i][0] = dp[i - 1][0] + (long long)energyDrinkA[i];
            dp[i][1] = dp[i - 1][1] + (long long)energyDrinkB[i];
        }
        if (i >= 2)
        {
            dp[i][0] = max(dp[i][0], dp[i - 2][1] + (long long)energyDrinkA[i]);
            dp[i][1] = max(dp[i][1], dp[i - 2][0] + (long long)energyDrinkB[i]);
        }
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

/// <summary>
/// Leet Code 3269. Constructing Two Increasing Arrays
/// 
/// Hard
/// 
/// Given 2 integer arrays nums1 and nums2 consisting only of 0 and 1, 
/// your task is to calculate the minimum possible largest number in 
/// arrays nums1 and nums2, after doing the following.
///
/// Replace every 0 with an even positive integer and every 1 with an 
/// odd positive integer. After replacement, both arrays should be 
/// increasing and each integer should be used at most once.
///
/// Return the minimum possible largest number after applying the changes.
///
/// Example 1:
/// Input: nums1 = [], nums2 = [1,0,1,1]
/// Output: 5
/// Explanation:
/// After replacing, nums1 = [], and nums2 = [1, 2, 3, 5].
///
/// Example 2:
/// Input: nums1 = [0,1,0,1], nums2 = [1,0,0,1]
/// Output: 9
/// Explanation:
/// One way to replace, having 9 as the largest element is 
/// nums1 = [2, 3, 8, 9], and nums2 = [1, 4, 6, 7].
///
/// Example 3:
/// Input: nums1 = [0,1,0,0,1], nums2 = [0,0,0,1]
/// Output: 13
/// Explanation:
/// One way to replace, having 13 as the largest element is 
/// nums1 = [2, 3, 4, 6, 7], and nums2 = [8, 10, 12, 13].
///
/// Constraints:
/// 1. 0 <= nums1.length <= 1000
/// 2. 1 <= nums2.length <= 1000
/// 3. nums1 and nums2 consist only of 0 and 1.
/// </summary>
int LeetCodeDP::minLargest(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 2 - (dp[i - 1][j] + nums1[i - 1]) % 2);
            }
            if (j > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 2 - (dp[i][j - 1] + nums2[j - 1]) % 2);
            }
        }
    }
    return dp[n1][n2];
}

/// <summary>
/// Leet Code 3277. Maximum XOR Score Subarray Queries
/// 
/// Hard
///
/// You are given an array nums of n integers, and a 2D integer array 
/// queries of size q, where queries[i] = [li, ri].
///
/// For each query, you must find the maximum XOR score of any 
/// subarray of nums[li..ri].
/// The XOR score of an array a is found by repeatedly applying the 
/// following operations on a so that only one element remains, that is 
/// the score:
///
/// Simultaneously replace a[i] with a[i] XOR a[i + 1] for all 
/// indices i except the last one.
/// Remove the last element of a.
/// Return an array answer of size q where answer[i] is the answer to 
/// query i.
/// 
/// Example 1:
/// Input: nums = [2,8,4,32,16,1], queries = [[0,2],[1,4],[0,5]]
/// Output: [12,60,60]
/// Explanation:
/// In the first query, nums[0..2] has 6 subarrays [2], [8], [4], [2, 8], 
/// [8, 4], and [2, 8, 4] each with a respective XOR score of 2, 8, 4, 
/// 10, 12, and 6. The answer for the query is 12, the largest of all XOR 
/// scores.
///
/// In the second query, the subarray of nums[1..4] with the largest XOR 
/// score is nums[1..4] with a score of 60.
/// In the third query, the subarray of nums[0..5] with the largest XOR 
/// score is nums[1..4] with a score of 60.
///
/// Example 2:
/// Input: nums = [0,7,3,2,8,5,1], queries = [[0,3],[1,5],[2,4],[2,6],
/// [5,6]]
/// Output: [7,14,11,14,5]
/// Explanation:
/// Index	nums[li..ri]	Maximum XOR Score Subarray	Maximum Subarray 
/// XOR Score
/// 0	[0, 7, 3, 2]	[7]	7
/// 1	[7, 3, 2, 8, 5]	[7, 3, 2, 8]	14
/// 2	[3, 2, 8]	[3, 2, 8]	11
/// 3	[3, 2, 8, 5, 1]	[2, 8, 5, 1]	14
/// 4	[5, 1]	[5]	5
/// 
/// Constraints:
/// 1. 1 <= n == nums.length <= 2000
/// 2. 0 <= nums[i] <= 2^31 - 1
/// 3. 1 <= q == queries.length <= 10^5
/// 4. queries[i].length == 2 
/// 5. queries[i] = [li, ri]
/// 6. 0 <= li <= ri <= n - 1
/// </summary>
vector<int> LeetCodeDP::maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i + k < n; i++)
        {
            if (k == 0)
            {
                dp[i][i] = nums[i];
            }
            else
            {
                dp[i][i+k] = dp[i][i + k - 1] ^ dp[i + 1][i + k];
            }
        }
    }

    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i + k < n; i++)
        {
            dp[i][i + k] = max(dp[i][i+k], max(dp[i][i+ k - 1], dp[i + 1][i + k]));
        }
    }
    vector<int> result;
    for (size_t i = 0; i < queries.size(); i++)
    {
        result.push_back(dp[queries[i][0]][queries[i][1]]);
    }
    return result;
}

/// <summary>
/// Leet Code 3287. Find the Maximum Sequence Value of Array
/// 
/// Hard
///
/// You are given an integer array nums and a positive integer k.
/// The value of a sequence seq of size 2 * x is defined as:
/// (seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] 
/// OR ... OR seq[2 * x - 1]).
/// Return the maximum value of any subsequence of nums having size 2 * k.
/// 
/// Example 1:
///
/// Input: nums = [2,6,7], k = 1
/// Output: 5
/// Explanation:
/// The subsequence [2, 7] has the maximum value of 2 XOR 7 = 5.
///
/// Example 2:
///
/// Input: nums = [4,2,5,6,7], k = 2
/// Output: 2
/// Explanation:
///
/// The subsequence [4, 5, 6, 7] has the maximum value of (4 OR 5) 
/// XOR (6 OR 7) = 2.
///
/// Constraints:
/// 1. 2 <= nums.length <= 400
/// 2. 1 <= nums[i] < 27
/// 3. 1 <= k <= nums.length / 2
/// </summary>
int LeetCodeDP::maxValue(vector<int>& nums, int k)
{
    vector<vector<vector<int>>> left(nums.size(), vector<vector<int>>(k, vector<int>(128)));
    vector<vector<vector<int>>> right(nums.size(), vector<vector<int>>(k, vector<int>(128)));
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < min((int)i + 1, k); j++)
        {
            if (i > 0)
            {
                left[i][j] = left[i - 1][j];
            }
            if (j == 0)
            {
                left[i][j][nums[i]] = 1;
            }
            if (i > 0 && j > 0)
            {
                for (int p = 0; p < 128; p++)
                {
                    if (left[i - 1][j - 1][p] == 1)
                    {
                        left[i][j][nums[i] | p] = 1;
                    }
                }
            }
        }
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < min((int)nums.size() - (int)i, k); j++)
        {
            if (i < (int)nums.size() - 1)
            {
                right[i][j] = right[i + 1][j];
            }
            if (j == 0)
            {
                right[i][j][nums[i]] = 1;
            }
            if (i < (int)nums.size() - 1 && j > 0)
            {
                for (int p = 0; p < 128; p++)
                {
                    if (right[i + 1][j - 1][p] == 1)
                    {
                        right[i][j][nums[i] | p] = 1;
                    }
                }
            }
        }
    }
    int result = 0;
    for (int i = k - 1; i < (int)nums.size() - k; i++)
    {
        for (int p = 0; p < 128; p++)
        {
            for (int q = 0; q < 128; q++)
            {
                if (left[i][k-1][p] == 1 && right[i+1][k - 1][q] == 1)
                result = max(result, p ^ q);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3290. Maximum Multiplication Score
/// 
/// Medium
///
/// You are given an integer array a of size 4 and another integer array 
/// b of size at least 4.
///
/// You need to choose 4 indices i0, i1, i2, and i3 from the array b such 
/// that i0 < i1 < i2 < i3. Your score will be equal to the value a[0] * 
/// b[i0] + a[1] * b[i1] + a[2] * b[i2] + a[3] * b[i3].
///
/// Return the maximum score you can achieve.
///
/// Example 1:
/// Input: a = [3,2,5,6], b = [2,-6,4,-5,-3,2,-7]
///
/// Output: 26
/// Explanation:
/// We can choose the indices 0, 1, 2, and 5. The score will be 3 * 2 + 
/// 2 * (-6) + 5 * 4 + 6 * 2 = 26.
/// 
/// Example 2:
/// Input: a = [-1,4,5,-2], b = [-5,-1,-3,-2,-4]
/// Output: -1
/// Explanation:
/// We can choose the indices 0, 1, 3, and 4. The score will be (-1) * 
/// (-5) + 4 * (-1) + 5 * (-2) + (-2) * (-4) = -1.
///
/// Constraints:
/// 1. a.length == 4
/// 2. 4 <= b.length <= 10^5
/// 3. -10^5 <= a[i], b[i] <= 10^5
/// </summary>
long long LeetCodeDP::maxScore(vector<int>& a, vector<int>& b)
{
    vector<vector<long long>> dp(b.size(), vector<long long>(4));
    for (int i = 0; i < (int)b.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                if (i == 0) dp[i][j] = (long long)a[0] * (long long)b[0];
                else dp[i][0] = max(dp[i - 1][0], (long long)a[0] * (long long)b[i]);
            }
            else 
            {
                if (i >= j) dp[i][j] = dp[i - 1][j - 1] + (long long)a[j] * (long long)b[i];
                if (i > j) dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            }
        }
    }
    return dp[b.size() - 1][3];
}

/// <summary>
/// Leet Code 3302. Find the Lexicographically Smallest Valid Sequence 
///                
/// Medium
///
/// Companies
/// You are given two strings word1 and word2.
/// A string x is called almost equal to y if you can change at most one 
/// character in x to make it identical to y.
///
/// A sequence of indices seq is called valid if:
/// The indices are sorted in ascending order.
/// Concatenating the characters at these indices in word1 in the same 
/// order results in a string that is almost equal to word2.
/// Return an array of size word2.length representing the 
/// lexicographically smallest valid sequence of indices. If no such 
/// sequence of indices exists, return an empty array.
///
/// Note that the answer must represent the lexicographically smallest 
/// array, not the corresponding string formed by those indices.
///
/// Example 1:
/// Input: word1 = "vbcca", word2 = "abc"
/// Output: [0,1,2]
///
/// Explanation:
/// The lexicographically smallest valid sequence of indices is [0, 1, 2]:
///
/// Change word1[0] to 'a'.
/// word1[1] is already 'b'.
/// word1[2] is already 'c'.
///
/// Example 2:
/// Input: word1 = "bacdc", word2 = "abc"
/// Output: [1,2,4]
///
/// Explanation:
/// The lexicographically smallest valid sequence of indices is [1, 2, 4]:
/// word1[1] is already 'a'.
/// Change word1[2] to 'b'.
/// word1[4] is already 'c'.
///
/// Example 3:
/// Input: word1 = "aaaaaa", word2 = "aaabc"
/// Output: []
///
/// Explanation:
/// There is no valid sequence of indices.
/// Example 4:
/// Input: word1 = "abc", word2 = "ab"
/// Output: [0,1]
/// 
/// Constraints:
/// 1. 1 <= word2.length < word1.length <= 3 * 10^5
/// 2. word1 and word2 consist only of lowercase English letters.
/// </summary>
vector<int> LeetCodeDP::validSequence(string word1, string word2)
{
    vector<int> suffix(word1.size() + 1);
    vector<int> result;
    int prev = 0;
    int n = word1.size();
    int m = word2.size();
    int i = 0, j = 0;
    for (i = n - 1, j = m - 1; i >= 0; i--)
    {
        if (j >= 0 && word1[i] == word2[j])
        {
            prev++;
            j--;
        }
        suffix[i] = prev;
    }
    prev = 0;
    int point = -1;
    for (i = 0, j = 0; i < n && j < m; i++)
    {
        if (word1[i] == word2[j])
        {
            prev++;
            j++;
        }
        else if (prev + suffix[i + 1] >= m - 1)
        {
            point = i;
            break;
        }
    }
    if (point == -1 && j < m) return result;
    for (i = 0, j = 0; i < n && j < m; i++)
    {
        if (i == point || word1[i] == word2[j])
        {
            result.push_back(i);
            j++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3316. Find Maximum Removals From Source String 
/// </summary>
int LeetCodeDP::maxRemovals(string source, string pattern, int s, int p, vector<vector<int>>& dp, vector<int>& target)
{
    if (dp[s][p] != -1) return dp[s][p];
    int n = source.size();
    int m = pattern.size();
    dp[s][p] = INT_MIN;
    if (s < n && p < m)
    {
        if (source[s] == pattern[p])
        {
            dp[s][p] = max(dp[s][p], maxRemovals(source, pattern, s + 1, p + 1, dp, target));
        }
        int ret = maxRemovals(source, pattern, s + 1, p, dp, target);
        if (ret >= 0)
        {
            ret += target[s];
        }
        dp[s][p] = max(dp[s][p], ret);
    }
    else if (p == m)
    {
        int ret = target[s] + maxRemovals(source, pattern, s + 1, p, dp, target);
        dp[s][p] = max(dp[s][p], ret);
    }
    else if (s == n)
    {
        dp[s][p] = INT_MIN;
    }
    return dp[s][p];
}

/// <summary>
/// Leet Code 3316. Find Maximum Removals From Source String 
///                
/// Medium
///
/// You are given a string source of size n, a string pattern that is a 
/// subsequence of source, and a sorted integer array targetIndices that 
/// contains distinct numbers in the range [0, n - 1].
///
/// We define an operation as removing a character at an index idx from 
/// source such that:
///
/// idx is an element of targetIndices. pattern remains a subsequence
/// of source after removing the character.
/// Performing an operation does not change the indices of the other 
/// characters in source. For example, if you remove 'c' from "acb", 
/// the character at index 2 would still be 'b'.
///
/// Return the maximum number of operations that can be performed.
/// 
/// Example 1:
/// Input: source = "abbaa", pattern = "aba", targetIndices = [0,1,2]
/// Output: 1
/// Explanation:
/// We can't remove source[0] but we can do either of these two operations:
/// Remove source[1], so that source becomes "a_baa".
/// Remove source[2], so that source becomes "ab_aa".
///
/// Example 2:
/// Input: source = "bcda", pattern = "d", targetIndices = [0,3]
/// Output: 2
/// Explanation:
/// We can remove source[0] and source[3] in two operations.
///
/// Example 3:
/// Input: source = "dda", pattern = "dda", targetIndices = [0,1,2]
/// Output: 0
/// Explanation:
/// We can't remove any character from source.
///
/// Example 4:
/// Input: source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4]
/// Output: 2
/// Explanation:
/// We can remove source[2] and source[3] in two operations.
/// 
/// Constraints:
/// 1. 1 <= n == source.length <= 3 * 10^3
/// 2. 1 <= pattern.length <= n
/// 3. 1 <= targetIndices.length <= n
/// 4. targetIndices is sorted in ascending order.
/// 5. The input is generated such that targetIndices contains distinct elements 
///    in the range [0, n - 1].
/// 6. source and pattern consist only of lowercase English letters.
/// 7. The input is generated such that pattern appears as a subsequence in source. 
/// </summary>
int LeetCodeDP::maxRemovals(string source, string pattern, vector<int>& targetIndices)
{
    int n = source.size(), m = pattern.size();
    vector<int> target(n);
    for (int t : targetIndices) target[t] = 1;

    vector<int> dp(m + 1, INT_MIN);
    dp[m] = 0;
    for (int i = n - 1; i >= 0; i--) 
    {
        for (int j = 0; j <= m; j++) 
        {
            if (dp[j] >= 0) dp[j] += target[i];
            if (j < m && source[i] == pattern[j])
            {
                if (dp[j + 1] >= 0) dp[j] = max(dp[j], dp[j + 1]);
            }
        }
    }
    return dp[0];
}

/// <summary>
/// Leet Code 3320. Count The Number of Winning Sequences 
///              
/// Hard
///
/// Alice and Bob are playing a fantasy battle game consisting of n rounds 
/// where they summon one of three magical creatures each round: a Fire 
/// Dragon, a Water Serpent, or an Earth Golem. In each round, players 
/// simultaneously summon their creature and are awarded points as follows:
///
/// If one player summons a Fire Dragon and the other summons an Earth 
/// Golem, the player who summoned the Fire Dragon is awarded a point.
/// If one player summons a Water Serpent and the other summons a Fire 
/// Dragon, the player who summoned the Water Serpent is awarded a point.
/// If one player summons an Earth Golem and the other summons a 
/// Water Serpent, the player who summoned the Earth Golem is awarded a 
/// point.
/// If both players summon the same creature, no player is awarded a 
/// point.
/// You are given a string s consisting of n characters 'F', 'W', 
/// and 'E', representing the sequence of creatures Alice will summon 
/// in each round:
///
/// If s[i] == 'F', Alice summons a Fire Dragon.
/// If s[i] == 'W', Alice summons a Water Serpent.
/// If s[i] == 'E', Alice summons an Earth Golem.
/// Bob's sequence of moves is unknown, but it is guaranteed that Bob will 
/// never summon the same creature in two consecutive rounds. Bob beats 
/// Alice if the total number of points awarded to Bob after n rounds is 
/// strictly greater than the points awarded to Alice.
///
/// Return the number of distinct sequences Bob can use to beat Alice.
///
/// Since the answer may be very large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: s = "FFF"
/// Output: 3
/// Explanation:
/// Bob can beat Alice by making one of the following sequences of 
/// moves: "WFW", "FWF", or "WEW". Note that other winning sequences 
/// like "WWE" or "EWW" are invalid since Bob cannot make the same 
/// move twice in a row.
///
/// Example 2:
/// Input: s = "FWEFW"
/// Output: 18
/// Explanation:
/// Bob can beat Alice by making one of the following sequences of moves: 
/// "FWFWF", "FWFWE", "FWEFE", "FWEWE", "FEFWF", "FEFWE", "FEFEW", "FEWFE", 
/// "WFEFE", "WFEWE", "WEFWF", "WEFWE", "WEFEF", "WEFEW", "WEWFW", "WEWFE",
/// "EWFWE", or "EWEWE".
/// 
/// Constraints:
/// 1 <= s.length <= 1000
/// s[i] is one of 'F', 'W', or 'E'.
/// </summary>
int LeetCodeDP::countWinningSequences(string s)
{
    vector<int> creatures = { 'F', 'W', 'E' };
    long long M = 1000000007;
    vector<vector<long long>> prev(3, vector<long long>(2001));
    for (size_t i = 0; i < s.size(); i++)
    {
        vector<vector<long long>> curr(3, vector<long long>(2001));
        for (int j = 0; j < 3; j++)
        {
            if (creatures[j] == s[i])
            {
                if (i == 0)
                {
                    curr[j][1000] = 1;
                }
                else
                {
                    for (int k = 0; k < 3; k++)
                    {
                        if (j == k) continue;
                        for (int p = 0; p < 2001; p++)
                        {
                            curr[j][p] = (curr[j][p] + prev[k][p]) % M;
                        }
                    }
                }
            }
            else if ((creatures[j] == 'E' && s[i] == 'F') ||
                (creatures[j] == 'F' && s[i] == 'W') ||
                (creatures[j] == 'W' && s[i] == 'E'))
            {
                if (i == 0)
                {
                    curr[j][999] = 1;
                }
                else
                {
                    for (int k = 0; k < 3; k++)
                    {
                        if (j == k) continue;
                        for (int p = 1; p < 2001; p++)
                        {
                            curr[j][p-1] = (curr[j][p-1] + prev[k][p]) % M;
                        }
                    }
                }
            }
            else 
            {
                if (i == 0)
                {
                    curr[j][1001] = 1;
                }
                else
                {
                    for (int k = 0; k < 3; k++)
                    {
                        if (j == k) continue;
                        for (int p = 0; p < 2000; p++)
                        {
                            curr[j][p + 1] = (curr[j][p + 1] + prev[k][p]) % M;
                        }
                    }
                }
            }
        }
        prev = curr;
    }
    long long result = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1001; j < 2001; j++)
        {
            result = (result + prev[i][j]) % M;
        }
    }
    return (int)result;
}


/// <summary>
/// Leet Code 3332. Maximum Points Tourist Can Earn 
/// 
/// Medium
///
/// 	
/// You are given two integers, n and k, along with two 2D integer 
/// arrays, stayScore and travelScore.
///
/// A tourist is visiting a country with n cities, where each city is 
/// directly connected to every other city. The tourist's journey 
/// consists of exactly k 0-indexed days, and they can choose any 
/// city as their starting point.
///
/// Each day, the tourist has two choices:
/// Stay in the current city: If the tourist stays in their current 
/// city curr during day i, they will earn stayScore[i][curr] points.
/// Move to another city: If the tourist moves from their current 
/// city curr to city dest, they will earn travelScore[curr][dest] 
/// points.
/// Return the maximum possible points the tourist can earn.
/// 
/// Example 1:
/// Input: n = 2, k = 1, stayScore = [[2,3]], travelScore = [[0,2],[1,0]]
/// Output: 3
/// Explanation:
/// The tourist earns the maximum number of points by starting in city 1 
/// and staying in that city.
///
/// Example 2:
/// Input: n = 3, k = 2, stayScore = [[3,4,2],[2,1,2]], 
/// travelScore = [[0,2,1],[2,0,4],[3,2,0]]
///
/// Output: 8
/// Explanation:
/// The tourist earns the maximum number of points by starting in city 1, 
/// staying in that city on day 0, and traveling to city 2 on day 1.
///
/// Constraints:
/// 1. 1 <= n <= 200
/// 2. 1 <= k <= 200
/// 3. n == travelScore.length == travelScore[i].length == 
///    stayScore[i].length
/// 4. k == stayScore.length
/// 5. 1 <= stayScore[i][j] <= 100
/// 6. 0 <= travelScore[i][j] <= 100
/// 7. travelScore[i][i] == 0
/// </summary>
int LeetCodeDP::maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore)
{
    vector<vector<int>> dp(2, vector<int>(n));
    int curr = 0, next = 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[next][j] = dp[curr][j] + stayScore[i][j];
            for (int p = 0; p < n; p++)
            {
                dp[next][j] = max(dp[next][j], dp[curr][p] + travelScore[p][j]);
            }
        }
        swap(curr, next);
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, dp[curr][i]);
    }
    return result;
}

/// <summary>
/// Leet Code 3333. Find the Original Typed String II 
/// 
/// Hard
///
/// 	
/// Alice is attempting to type a specific string on her computer. 
/// However, she tends to be clumsy and may press a key for too long, 
/// resulting in a character being typed multiple times.
///
/// You are given a string word, which represents the final output 
/// displayed on Alice's screen. You are also given a positive 
/// integer k.
///
/// Return the total number of possible original strings that Alice 
/// might have intended to type, if she was trying to type a string 
/// of size at least k.
///
/// Since the answer may be very large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: word = "aabbccdd", k = 7
/// Output: 5
/// Explanation:
/// The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", 
/// and "abbccdd".
///
/// Example 2:
/// Input: word = "aabbccdd", k = 8
/// Output: 1
/// Explanation:
/// The only possible string is "aabbccdd".
///
/// Example 3:
/// Input: word = "aaabbb", k = 3
/// Output: 8
///
/// Constraints:
/// 1. 1 <= word.length <= 5 * 10^5
/// 2. word consists only of lowercase English letters.
/// 3. 1 <= k <= 2000
/// </summary>
int LeetCodeDP::possibleStringCount(string word, int k)
{
    long long M = 1000000007;
    long long product = 1;
    vector<int> groups;
    int count = 0;
    int n = word.size();
    for (size_t i = 1; i <= word.size(); i++) 
    {
        if (i < word.size() && word[i] == word[i - 1])
        {
            count++;
        }
        else 
        {
            groups.push_back(count);
            product = product * (count + 1) % M;
            count = 0;
        }
    }
    if (k <= (int)groups.size()) return (int)product;
    vector<vector<int>> dp(2, vector<int>(k + 1));
    dp[0][0] = 1;
    vector<int> prefix_sum(k + 1);
    prefix_sum[0] = 0;
    int sz = groups.size();
    for (int i = 0; i < sz; i++)
    {
        for (int p = 0; p < k - (int)groups.size(); p++)
        {
            prefix_sum[p + 1] = (prefix_sum[p] + dp[i%2][p]) % M;
            dp[1- i%2][p] = (prefix_sum[p + 1] - prefix_sum[max(0, p - groups[i])]) % M;
        }
    }
    long long result = product;
    for (int i = 0; i < k; i++)
    {
        result = (result - dp[sz%2][i] + M) % M;
    }
    return (int)result;
}

/// <summary>
/// Leet Code 3336. Find the Number of Subsequences With Equal GCD
/// 
/// Hard
/// 
/// You are given an integer array nums.
/// Your task is to find the number of pairs of non-empty subsequences
/// (seq1, seq2) of nums that satisfy the following conditions:
///
/// The subsequences seq1 and seq2 are disjoint, meaning no index of 
/// nums is common between them.
/// The GCD of the elements of seq1 is equal to the GCD of the elements 
/// of seq2.
/// Return the total number of such pairs.
///
/// Since the answer may be very large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: nums = [1,2,3,4]
/// Output: 10
/// Explanation:
/// The subsequence pairs which have the GCD of their elements equal to 1 
/// are:
///
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
/// ([1, 2, 3, 4], [1, 2, 3, 4])
///
/// Example 2:
/// Input: nums = [10,20,30]
/// Output: 2
/// Explanation:
/// The subsequence pairs which have the GCD of their elements equal to 10 
/// are:
/// ([10, 20, 30], [10, 20, 30])
/// ([10, 20, 30], [10, 20, 30])
///
/// Example 3:
/// Input: nums = [1,1,1,1]
/// Output: 50
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 200
/// 2. 1 <= nums[i] <= 200
/// </summary>
int LeetCodeDP::subsequencePairCount(vector<int>& nums)
{
    int M = 1000000007;
    int max_val = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        max_val = max(max_val, nums[i]);
    }
    max_val++;
    vector<vector<int>> curr(max_val, vector<int>(max_val));
    curr[0][0] = 1;
    for (size_t k = 0; k < nums.size(); k++)
    {
        vector<vector<int>> next(max_val, vector<int>(max_val));
        for (int i = 0; i < max_val; i++)
        {
            for (int j = 0; j < max_val; j++)
            {
                int a = gcd(i, nums[k]);
                int b = gcd(j, nums[k]);
                next[i][j] = (next[i][j] + curr[i][j]) % M;
                next[a][j] = (next[a][j] + curr[i][j]) % M;
                next[i][b] = (next[i][b] + curr[i][j]) % M;
            }
        }
        curr = next;
    }
    int result = 0;
    for (int i = 1; i < max_val; i++)
    {
        result = (result + curr[i][i]) % M;
    }
    return result;
}

/// <summary>
/// Leet Code 3339. Find the Number of K-Even Arrays
/// 
/// Medium
///
/// You are given three integers n, m, and k.
/// An array arr is called k-even if there are exactly k indices such 
/// that, for each of these indices i (0 <= i < n - 1):
/// (arr[i] * arr[i + 1]) - arr[i] - arr[i + 1] is even.
/// Return the number of possible k-even arrays of size n where all 
/// elements are in the range [1, m].
///
/// Since the answer may be very large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: n = 3, m = 4, k = 2
/// Output: 8
/// Explanation:
/// The 8 possible 2-even arrays are:
/// [2, 2, 2]
/// [2, 2, 4]
/// [2, 4, 2]
/// [2, 4, 4]
/// [4, 2, 2]
/// [4, 2, 4]
/// [4, 4, 2]
/// [4, 4, 4]
///
/// Example 2:
/// Input: n = 5, m = 1, k = 0
/// Output: 1
/// Explanation:
/// The only 0-even array is [1, 1, 1, 1, 1].
///
/// Example 3:
/// Input: n = 7, m = 7, k = 5
/// Output: 5832
/// 
/// Constraints:
/// 1. 1 <= n <= 750
/// 2. 0 <= k <= n - 1
/// 3. 1 <= m <= 1000
/// </summary>
int LeetCodeDP::countOfArrays(int n, int m, int k)
{
    long long M = 1000000007;
    vector<long long> curr_odd, curr_even;
    long long evens = m / 2, odds = m - m / 2;
    for (int i = 0; i < n; i++)
    {
        vector<long long> next_odd(k + 1), next_even(k + 1);
        if (i == 0)
        {
            next_odd[0] = odds;
            next_even[0] = evens;
        }
        else
        {
            for (int j = 0; j <= k; j++)
            {
                next_odd[j] = (next_odd[j] + curr_odd[j] * odds) % M;
                next_odd[j] = (next_odd[j] + curr_even[j] * odds) % M;
                next_even[j] = (next_even[j] + curr_odd[j] * evens) % M;
                if (j < k)
                {
                    next_even[j + 1] = (next_even[j + 1] + curr_even[j] * evens) % M;
                }
            }
        }
        curr_odd = next_odd;
        curr_even = next_even;
    }
    int result = (int)((curr_odd[k] + curr_even[k]) % M);
    return result;
}

/// <summary>
/// Leet Code 3366. Minimum Array Sum 
/// 
/// Medium
/// 
/// You are given an integer array nums and three integers k, op1, and op2.
/// You can perform the following operations on nums:
/// Operation 1: Choose an index i and divide nums[i] by 2, rounding up to 
/// the nearest whole number. You can perform this operation at most op1 
/// times, and not more than once per index.
/// Operation 2: Choose an index i and subtract k from nums[i], but only 
/// if nums[i] is greater than or equal to k. You can perform this 
/// operation at most op2 times, and not more than once per index.
/// Note: Both operations can be applied to the same index, but at most 
/// once each.
///
/// Return the minimum possible sum of all elements in nums after 
/// performing any number of operations.
///
/// Example 1:
/// Input: nums = [2,8,3,19,3], k = 3, op1 = 1, op2 = 1
/// Output: 23
/// Explanation:
/// Apply Operation 2 to nums[1] = 8, making nums[1] = 5.
/// Apply Operation 1 to nums[3] = 19, making nums[3] = 10.
/// The resulting array becomes [2, 5, 3, 10, 3], which has the minimum 
/// possible sum of 23 after applying the operations.
///
/// Example 2:
/// Input: nums = [2,4,3], k = 3, op1 = 2, op2 = 1
/// Output: 3
/// Explanation:
/// Apply Operation 1 to nums[0] = 2, making nums[0] = 1.
/// Apply Operation 1 to nums[1] = 4, making nums[1] = 2.
/// Apply Operation 2 to nums[2] = 3, making nums[2] = 0.
/// The resulting array becomes [1, 2, 0], which has the minimum possible 
/// sum of 3 after applying the operations.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 0 <= nums[i] <= 10^5
/// 3. 0 <= k <= 10^5
/// 4. 0 <= op1, op2 <= nums.length
/// </summary>
int LeetCodeDP::minArraySum(vector<int>& nums, int k, int op1, int op2)
{
    int n = nums.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, INT_MAX)));
    dp[0][0][0] = nums[0];
    if (op1 > 0)
    {
        dp[0][1][0] = (nums[0] + 1) / 2;
    }
    if (op2 > 0 && nums[0] >= k)
    {
        dp[0][0][1] = nums[0] - k;
    }
    if (op1 > 0 && op2 > 0 && nums[0] >= k)
    {
        if ((nums[0] + 1) / 2 >= k)
        {
            dp[0][1][1] = (nums[0] + 1) / 2 - k;
        }
        else
        {
            dp[0][1][1] = (nums[0] - k + 1) / 2;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= op1; j++)
        {
            for (int p = 0; p <= op2; p++)
            {
                if (dp[i - 1][j][p] == INT_MAX) break;
                dp[i][j][p] = min(dp[i][j][p], dp[i - 1][j][p] + nums[i]);
                if (j < op1)
                {
                    dp[i][j + 1][p] = min(dp[i][j + 1][p], dp[i - 1][j][p] + (nums[i] + 1) / 2);
                }
                if (p < op2 && nums[i] >= k)
                {
                    dp[i][j][p + 1] = min(dp[i][j][p + 1], dp[i - 1][j][p] + nums[i] - k);
                }
                if (j < op1 && p < op2 && nums[i] >= k)
                {
                    if ((nums[i] + 1) / 2 >= k)
                    {
                        dp[i][j + 1][p + 1] = min(dp[i][j + 1][p + 1], dp[i - 1][j][p] + (nums[i] + 1) / 2 - k);
                    }
                    else
                    {
                        dp[i][j + 1][p + 1] = min(dp[i][j + 1][p + 1], dp[i - 1][j][p] + (nums[i] - k + 1) / 2);
                    }
                }
            }
        }
    }
    int result = INT_MAX;
    for (int i = 0; i <= op1; i++)
    {
        for (int j = 0; j <= op2; j++)
        {
            result = min(result, dp[n - 1][i][j]);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3363. Find the Maximum Number of Fruits Collected 
/// 
/// Hard
///
/// There is a game dungeon comprised of n x n rooms arranged in a grid.
/// 
/// You are given a 2D array fruits of size n x n, where fruits[i][j] 
/// represents the number of fruits in the room (i, j). Three children 
/// will play in the game dungeon, with initial positions at the corner 
///  rooms (0, 0), (0, n - 1), and (n - 1, 0).
///
/// The children will make exactly n - 1 moves according to the following 
/// rules to reach the room (n - 1, n - 1):
///
/// The child starting from (0, 0) must move from their current 
/// room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), 
/// and (i, j + 1) if the target room exists.
/// The child starting from (0, n - 1) must move from their current 
/// room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), 
/// and (i + 1, j + 1) if the target room exists.
/// The child starting from (n - 1, 0) must move from their current 
/// room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), 
/// and (i + 1, j + 1) if the target room exists.
/// When a child enters a room, they will collect all the fruits there. 
/// If two or more children enter the same room, only one child will 
/// collect the fruits, and the room will be emptied after they leave.
///
/// Return the maximum number of fruits the children can collect from 
/// the dungeon.
/// 
/// Example 1:
/// Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]
/// Output: 100
/// Explanation:
///
/// In this example:
/// The 1st child (green) moves on the path (0,0) -> (1,1) -> (2,2) -> 
/// (3, 3).
/// The 2nd child (red) moves on the path (0,3) -> (1,2) -> (2,3) -> 
/// (3, 3).
/// The 3rd child (blue) moves on the path (3,0) -> (3,1) -> (3,2) -> 
/// (3, 3).
/// In total they collect 1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 
/// 100 fruits.
///
/// Example 2:
/// Input: fruits = [[1,1],[1,1]]
/// Output: 4
/// Explanation:
/// In this example:
/// The 1st child moves on the path (0,0) -> (1,1).
/// The 2nd child moves on the path (0,1) -> (1,1).
/// The 3rd child moves on the path (1,0) -> (1,1).
/// In total they collect 1 + 1 + 1 + 1 = 4 fruits.
/// 
/// Constraints:
/// 1. 2 <= n == fruits.length == fruits[i].length <= 1000
/// 2. 0 <= fruits[i][j] <= 1000
/// </summary>
int LeetCodeDP::maxCollectedFruits(vector<vector<int>>& fruits)
{
    int n = fruits.size();
    vector<vector<int>> dp(n, vector<int>(n));;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += fruits[i][i];
        fruits[i][i] = 0;
    }
    dp[0][n - 1] = fruits[0][n - 1];
    fruits[0][n - 1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (n - 1 - j > i || i == j) break;
            dp[i + 1][j] = max(dp[i + 1][j], fruits[i + 1][j] + dp[i][j]);
            dp[i + 1][j - 1] = max(dp[i + 1][j - 1], fruits[i + 1][j - 1] + dp[i][j]);
            if (j < n - 1)
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], fruits[i + 1][j + 1] + dp[i][j]);
            }
        }
    }
    result += dp[n - 1][n - 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[n - 1][0] = fruits[n - 1][0];
    fruits[n - 1][0] = 0;
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (n - 1 - i > j || i == j) break;
            dp[i][j + 1] = max(dp[i][j + 1], fruits[i][j + 1] + dp[i][j]);
            dp[i - 1][j + 1] = max(dp[i - 1][j + 1], fruits[i - 1][j + 1] + dp[i][j]);
            if (i < n - 1)
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], fruits[i + 1][j + 1] + dp[i][j]);
            }
        }
    }
    result += dp[n - 1][n - 1];
    return result;
}

/// <summary>
/// Leet Code 3388. Count Beautiful Splits in an Array
/// 
/// Medium
///
/// You are given an array nums.
/// A split of an array nums is beautiful if:
/// The array nums is split into three subarrays: nums1, nums2, and nums3, 
/// such that nums can be formed by concatenating nums1, nums2, and nums3 
/// in that order.
/// The subarray nums1 is a prefix of nums2 OR nums2 is a prefix of nums3.
///
/// Return the number of ways you can make this split.
/// 
/// Example 1:
/// Input: nums = [1,1,2,1]
/// Output: 2
/// Explanation:
/// The beautiful splits are:
/// A split with nums1 = [1], nums2 = [1,2], nums3 = [1].
/// A split with nums1 = [1], nums2 = [1], nums3 = [2,1].
///
/// Example 2:
/// Input: nums = [1,2,3,4]
/// Output: 0
/// Explanation:
/// There are 0 beautiful splits.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 5000
/// 2. 0 <= nums[i] <= 50
/// </summary>
int LeetCodeDP::beautifulSplits(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                dp[i][j] = 1;
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int len1 = i + 1;
            int len2 = j - i;
            int len3 = n - 1 - j;
            if ((len1 <= len2 && dp[i][i + len1] == len1) ||
                (len2 <= len3 && dp[j][j + len2] >= len2))
            {
                result++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3393. Count Paths With the Given XOR Value 
///   
/// Medium
/// 
/// You are given a 2D integer array grid with size m x n. You are also 
/// given an integer k.
///
/// Your task is to calculate the number of paths you can take from 
/// the top-left cell (0, 0) to the bottom-right cell (m - 1, n - 1) 
/// satisfying the following constraints:
///
/// You can either move to the right or down. Formally, from the cell 
/// (i, j) you may move to the cell (i, j + 1) or to the cell (i + 1, j) 
/// if the target cell exists.
/// The XOR of all the numbers on the path must be equal to k.
/// Return the total number of such paths.
///
/// Since the answer can be very large, return the result modulo 10^9 + 7.
///
/// Example 1:
/// Input: grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11
/// Output: 3
/// Explanation: 
/// The 3 paths are:
/// (0, 0) -> (1, 0) -> (2, 0) -> (2, 1) -> (2, 2)
/// (0, 0) -> (1, 0) -> (1, 1) -> (1, 2) -> (2, 2)
/// (0, 0) -> (0, 1) -> (1, 1) -> (2, 1) -> (2, 2)
///
/// Example 2:
/// Input: grid = [[1, 3, 3, 3], [0, 3, 3, 2], [3, 0, 1, 1]], k = 2
/// Output: 5
/// Explanation:
/// The 5 paths are:
/// (0, 0) -> (1, 0) -> (2, 0) -> (2, 1) -> (2, 2) -> (2, 3)
/// (0, 0) -> (1, 0) -> (1, 1) -> (2, 1) -> (2, 2) -> (2, 3)
/// (0, 0) -> (1, 0) -> (1, 1) -> (1, 2) -> (1, 3) -> (2, 3)
/// (0, 0) -> (0, 1) -> (1, 1) -> (1, 2) -> (2, 2) -> (2, 3)
/// (0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (2, 2) -> (2, 3)
////
/// Example 3:
/// Input: grid = [[1, 1, 1, 2], [3, 0, 3, 2], [3, 0, 2, 2]], k = 10
/// Output: 0
/// 
/// Constraints:
/// 1. 1 <= m == grid.length <= 300
/// 2. 1 <= n == grid[r].length <= 300
/// 4. 0 <= grid[r][c] < 16
/// 5. 0 <= k < 16
/// </summary>
int LeetCodeDP::countPathsWithXorValue(vector<vector<int>>& grid, int k)
{
    int M = 1000000007;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(16)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0) && (j == 0))
            {
                dp[i][j][grid[i][j]] = 1;
            }
            if (i > 0)
            {
                for (int k = 0; k < 16; k++)
                {
                    int val = k xor grid[i][j];
                    dp[i][j][val] = (dp[i][j][val] + dp[i - 1][j][k]) % M;
                }
            }
            if (j > 0)
            {
                for (int k = 0; k < 16; k++)
                {
                    int val = k xor grid[i][j];
                    dp[i][j][val] = (dp[i][j][val] + dp[i][j-1][k]) % M;
                }
            }
        }
    }
    return dp[n - 1][m - 1][k];
}

/// <summary>
/// Leet Code 3414. Maximum Score of Non-overlapping Intervals
/// </summary>
bool LeetCodeDP::maximumWeightSmaller(vector<int> arr1, vector<int> arr2)
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for (size_t i = 0; i < arr1.size() && i < arr2.size(); i++)
    {
        if (arr1[i] < arr2[i]) return true;
        else if (arr1[i] > arr2[i]) return false;
    }
    if (arr1.size() < arr2.size()) return true;
    else return false;
}


/// <summary>
/// Leet Code 3414. Maximum Score of Non-overlapping Intervals
///   
/// Hard
///
/// You are given a 2D integer array intervals, where intervals[i] = 
/// [li, ri, weighti]. Interval i starts at position li and ends at ri, 
/// and has a weight of weighti. You can choose up to 4 non-overlapping 
/// intervals. The score of the chosen intervals is defined as the total 
/// sum of their weights.
/// Return the lexicographically smallest array of at most 4 indices 
/// from intervals with maximum score, representing your choice of non-
/// overlapping intervals.
///
/// Two intervals are said to be non-overlapping if they do not share any 
/// points. In particular, intervals sharing a left or right boundary are 
/// considered overlapping.
/// 
/// Example 1:
/// Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]
/// Output: [2,3]
/// Explanation:
/// You can choose the intervals with indices 2, and 3 with respective 
/// weights of 5, and 3.
///
/// Example 2:
/// Input: intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],
/// [11,14,3],[3,5,5]]
///
/// Output: [1,3,5,6]
/// Explanation:
/// You can choose the intervals with indices 1, 3, 5, and 6 with 
/// respective weights of 7, 6, 3, and 5.
///
/// Constraints:
/// 1. 1 <= intevals.length <= 5 * 10^4
/// 2. intervals[i].length == 3
/// 3. intervals[i] = [li, ri, weighti]
/// 4. 1 <= li <= ri <= 10^9
/// 5. 1 <= weighti <= 10^9
/// </summary>
vector<int> LeetCodeDP::maximumWeight(vector<vector<int>>& intervals)
{
    map<int, vector<pair<long long, vector<int>>>> dp;
    set<pair<int, int>> arr;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        arr.insert(make_pair(intervals[i][1], i));
    }
    for (auto& itr : arr)
    {
        int i = itr.second;
        int left = intervals[i][0];
        int right = intervals[i][1];
        int weight = intervals[i][2];
        if (dp[right].empty())
        {
            dp[right].push_back(make_pair(weight, vector<int>()));
            dp[right][0].second.push_back(i);
        }
        else
        {
            if (weight > dp[right][0].first)
            {
                dp[right][0].first = weight;
                dp[right][0].second = { i };
            }
        }
        auto prev_itr = dp.lower_bound(left);
        if (prev_itr != dp.begin())
        {
            prev_itr = prev(prev_itr);
            vector<pair<long long, vector<int>>>& prev_arr = prev_itr->second;
            for (int k = 0; k < 3 && k < (int)prev_arr.size(); k++)
            {
                if (k + 1 >= (int) dp[right].size())
                {
                    dp[right].push_back(make_pair(weight + prev_arr[k].first, prev_arr[k].second));
                    dp[right][k + 1].second.push_back(i);
                }
                else if (weight + prev_arr[k].first > dp[right][k + 1].first)
                {
                    dp[right][k+1] = make_pair(weight + prev_arr[k].first, prev_arr[k].second);
                    dp[right][k + 1].second.push_back(i);
                }
                else if (weight + prev_arr[k].first == dp[right][k + 1].first)
                {
                    vector<int> arr1 = prev_arr[k].second;
                    arr1.push_back(i);
                    vector<int> arr2 = dp[right][k + 1].second;
                    if (maximumWeightSmaller(arr1, arr2))
                    {
                        dp[right][k + 1].second = arr1;
                    }
                }
            }
        }
        prev_itr = dp.lower_bound(right);
        if (prev_itr != dp.begin())
        {
            prev_itr = prev(prev_itr);
            vector<pair<long long, vector<int>>>& prev_arr = prev_itr->second;
            for (int k = 0; k < 4 && k < (int)prev_arr.size(); k++)
            {
                if (k >= (int)dp[right].size())
                {
                    dp[right].push_back(prev_arr[k]);
                }
                else if (prev_arr[k].first > dp[right][k].first)
                {
                    dp[right][k] = prev_arr[k];
                }
                else if (prev_arr[k].first == dp[right][k].first)
                {
                    if (maximumWeightSmaller(prev_arr[k].second, dp[right][k].second))
                    {
                        dp[right][k] = prev_arr[k];
                    }
                }
            }
        }
    }
    auto last = dp.rbegin()->second;
    long long sum = 0;
    vector<int> result;
    for (size_t i = 0; i < last.size(); i++)
    {
        if (last[i].first > sum)
        {
            sum = last[i].first;
            result = last[i].second;
        }
        else if (last[i].first == sum)
        {
            if (maximumWeightSmaller(last[i].second, result))
            {
                result = last[i].second;
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet Code 3418. Maximum Amount of Money Robot Can Earn
///   
/// Medium
///
/// You are given an m x n grid. A robot starts at the top-left corner of 
/// the grid (0, 0) and wants to reach the bottom-right corner 
/// (m - 1, n - 1). The robot can move either right or down at any point 
/// in time.
///
/// The grid contains a value coins[i][j] in each cell:
/// If coins[i][j] >= 0, the robot gains that many coins.
/// If coins[i][j] < 0, the robot encounters a robber, and the robber 
/// steals the absolute value of coins[i][j] coins.
/// The robot has a special ability to neutralize robbers in at most 2 
/// cells on its path, preventing them from stealing coins in those cells.
///
/// Note: The robot's total coins can be negative.
/// Return the maximum profit the robot can gain on the route.
///
/// Example 1:
/// Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]
/// Output: 8
///
/// Explanation:
/// An optimal path for maximum coins is:
/// Start at (0, 0) with 0 coins (total coins = 0).
/// Move to (0, 1), gaining 1 coin (total coins = 0 + 1 = 1).
/// Move to (1, 1), where there's a robber stealing 2 coins. The robot 
/// uses one neutralization here, avoiding the robbery (total coins = 1).
/// Move to (1, 2), gaining 3 coins (total coins = 1 + 3 = 4).
/// Move to (2, 2), gaining 4 coins (total coins = 4 + 4 = 8).
///
/// Example 2:
/// Input: coins = [[10,10,10],[10,10,10]]
/// Output: 40
/// Explanation:
/// An optimal path for maximum coins is:
/// Start at (0, 0) with 10 coins (total coins = 10).
/// Move to (0, 1), gaining 10 coins (total coins = 10 + 10 = 20).
/// Move to (0, 2), gaining another 10 coins (total coins = 20 + 10 = 30).
/// Move to (1, 2), gaining the final 10 coins 
/// (total coins = 30 + 10 = 40).
///
/// Constraints:
/// 1. m == coins.length
/// 2. n == coins[i].length
/// 3. 1 <= m, n <= 500
/// 4. -1000 <= coins[i][j] <= 1000
/// </summary>
int LeetCodeDP::maximumAmount(vector<vector<int>>& coins)
{
    int m = coins.size();
    int n = coins[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3)));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j][0] = coins[i][j];
                dp[i][j][1] = max(dp[i][j][0], 0);
                dp[i][j][2] = dp[i][j][1];
            }
            else if (i == 0)
            {
                dp[i][j][0] = dp[i][j - 1][0] + coins[i][j];
                dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1] + coins[i][j]);
                dp[i][j][1] = max(dp[i][j][0], dp[i][j][1]);
                dp[i][j][2] = max(dp[i][j - 1][1], dp[i][j - 1][2] + coins[i][j]);
                dp[i][j][2] = max(dp[i][j][1], dp[i][j][2]);
            }
            else if (j == 0)
            {
                dp[i][j][0] = dp[i - 1][j][0] + coins[i][j];
                dp[i][j][1] = max(dp[i-1][j][0], dp[i-1][j][1] + coins[i][j]);
                dp[i][j][1] = max(dp[i][j][0], dp[i][j][1]);
                dp[i][j][2] = max(dp[i-1][j][1], dp[i-1][j][2] + coins[i][j]);
                dp[i][j][2] = max(dp[i][j][1], dp[i][j][2]);
            }
            else
            {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + coins[i][j];
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) + coins[i][j];
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i][j - 1][2]) + coins[i][j];
                dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0]);
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][0]);
                dp[i][j][1] = max(dp[i][j][1], dp[i][j][0]);
                dp[i][j][2] = max(dp[i][j][2], dp[i][j - 1][1]);
                dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][1]);
                dp[i][j][2] = max(dp[i][j][2], dp[i][j][1]);
            }
        }
    }
    return dp[m - 1][n - 1][2];
}


/// <summary>
/// Leet Code 3429. Paint House IV
///   
/// Medium
/// You are given an even integer n representing the number of houses 
/// arranged in a straight line, and a 2D array cost of size n x 3, where 
/// cost[i][j] represents the cost of painting house i with color j + 1.
///
/// The houses will look beautiful if they satisfy the following 
/// conditions:
///
/// No two adjacent houses are painted the same color.
/// Houses equidistant from the ends of the row are not painted the same 
/// color. For example, if n = 6, houses at positions (0, 5), (1, 4), 
/// and (2, 3) are considered equidistant.
/// Return the minimum cost to paint the houses such that they look 
/// beautiful.
/// 
/// Example 1:
/// Input: n = 4, cost = [[3,5,7],[6,2,9],[4,8,1],[7,3,5]]
/// Output: 9
///
/// Explanation:
/// The optimal painting sequence is [1, 2, 3, 2] with corresponding 
/// costs [3, 2, 1, 3]. This satisfies the following conditions:
///
/// No adjacent houses have the same color.
/// Houses at positions 0 and 3 (equidistant from the ends) are not 
/// painted the same color (1 != 2).
/// Houses at positions 1 and 2 (equidistant from the ends) are not 
/// painted the same color (2 != 3).
/// The minimum cost to paint the houses so that they look beautiful 
/// is 3 + 2 + 1 + 3 = 9.
///
/// Example 2:
/// Input: n = 6, cost = [[2,4,6],[5,3,8],[7,1,9],[4,6,2],[3,5,7],[8,2,4]]
/// Output: 18
/// Explanation:
/// The optimal painting sequence is [1, 3, 2, 3, 1, 2] with corresponding 
/// costs [2, 8, 1, 2, 3, 2]. This satisfies the following conditions:
///
/// No adjacent houses have the same color.
/// Houses at positions 0 and 5 (equidistant from the ends) are not 
/// painted the same color (1 != 2).
/// Houses at positions 1 and 4 (equidistant from the ends) are not 
/// painted the same color (3 != 1).
/// Houses at positions 2 and 3 (equidistant from the ends) are not 
/// painted the same color (2 != 3).
/// The minimum cost to paint the houses so that they look beautiful is 
/// 2 + 8 + 1 + 2 + 3 + 2 = 18.
/// 
/// Constraints:
/// 1. 2 <= n <= 10^5
/// 2. n is even.
/// 3. cost.length == n
/// 4. cost[i].length == 3
/// 5. 0 <= cost[i][j] <= 10^5
/// </summary>
long long LeetCodeDP::minCostIV(int n, vector<vector<int>>& cost)
{
    int first = 0, last = n - 1;
    vector<vector<long long>> dp(3, vector<long long>(3));
    long long result = LLONG_MAX;
    while (first < last)
    {
        vector<vector<long long>> curr(3, vector<long long>(3,LLONG_MAX));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j) continue;
                for (int m = 0; m < 3; m++)
                {
                    if (i == m) continue;
                    for (int n = 0; n < 3; n++)
                    {
                        if (j == n) continue;
                        if (m == n) continue;
                        curr[i][j] = min(curr[i][j], dp[m][n] + cost[first][i] + cost[last][j]);
                    }
                }
            }
        }
        dp = curr;
        first++;
        last--;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j) continue;
            result = min(result, dp[i][j]);
        }
    }
    return result;
}


/// <summary>
/// Leet Code 3441. Minimum Cost Good Caption
///   
/// Hard
/// 
/// You are given a string caption of length n. A good caption is a string 
/// where every character appears in groups of at least 3 consecutive 
/// occurrences.
///
/// For example:
/// "aaabbb" and "aaaaccc" are good captions.
/// "aabbb" and "ccccd" are not good captions.
/// You can perform the following operation any number of times:
///
/// Choose an index i (where 0 <= i < n) and change the character at that 
/// index to either:
///
/// The character immediately before it in the alphabet 
/// (if caption[i] != 'a').
/// The character immediately after it in the alphabet 
/// (if caption[i] != 'z').
/// Your task is to convert the given caption into a good caption using 
/// the minimum number of operations, and return it. If there are multiple 
/// possible good captions, return the lexicographically smallest one 
/// among them. If it is impossible to create a good caption, return an 
/// empty string "".
///
/// Example 1:
/// Input: caption = "cdcd"
/// Output: "cccc"
/// Explanation:
/// It can be shown that the given caption cannot be transformed into a 
/// good caption with fewer than 2 operations. The possible good captions 
/// that can be created using exactly 2 operations are:
///
/// "dddd": Change caption[0] and caption[2] to their next character 'd'.
/// "cccc": Change caption[1] and caption[3] to their previous character 
/// 'c'.
/// Since "cccc" is lexicographically smaller than "dddd", return "cccc".
///
/// Example 2:
/// Input: caption = "aca"
/// Output: "aaa"
/// Explanation:
/// It can be proven that the given caption requires at least 2 operations 
/// to be transformed into a good caption. The only good caption that can 
/// be obtained with exactly 2 operations is as follows:
///
/// Operation 1: Change caption[1] to 'b'. caption = "aba".
/// Operation 2: Change caption[1] to 'a'. caption = "aaa".
/// Thus, return "aaa".
///
/// Example 3:
/// Input: caption = "bc"
/// Output: ""
/// Explanation:
/// It can be shown that the given caption cannot be converted to a good 
/// caption by using any number of operations.
/// 
/// Constraints:
/// 1. 1 <= caption.length <= 5 * 10^4
/// 2. caption consists only of lowercase English letters.
/// </summary>
string LeetCodeDP::minCostGoodCaption(string caption)
{
    int n = caption.size();
    pair<int, char> dp[5001][26][4];
    const pair<int, char> GOOD = { 0, '#' };
    const pair<int, char> BAD = { -1, '#' };
    if (n < 3) return "";
    for (char last = 0; last < 26; last++) 
    {
        for (int cnt = 0; cnt <= 3; cnt++) 
        {
            // Base case
            dp[n][last][cnt] = (cnt >= 3) ? GOOD : BAD;
        }
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        int captionChar = (caption[i] - 'a');
        for (char last = 0; last < 26; last++) 
        {
            for (int cnt = 0; cnt <= 3; cnt++) 
            {
                char bestChar = '#';
                int bestCost = -1;
                for (int ch = 0; ch < 26; ch++) 
                {
                    int changeCost = abs(captionChar - ch);
                    // if there was a previous char and its consecutive ends at cnt < 3, continue;
                    if (1 <= cnt && cnt < 3 && ch != last) continue;
                    int nextCnt = min(3, 1 + (ch == last) * cnt);

                    pair<int, char> res = dp[i + 1][ch][nextCnt];
                    if (res.first == -1) continue; // invalid
                    // if haven't found any, or this is better
                    if (bestCost == -1 || changeCost + res.first < bestCost) 
                    {
                        bestCost = changeCost + res.first;
                        bestChar = ch;
                    }
                }
                dp[i][last][cnt] = { bestCost, bestChar };
            }
        }
    }
    string result(n, '0');
    pair<int, char> curr = dp[0][0][0];
    int cnt = 0;
    for (int i = 0; i < n; i++) 
    {
        result[i] = curr.second;
        if (i != n - 1) 
        {
            int nextCnt = min(3, 1 + (i > 0 && result[i] == result[i - 1]) * cnt);
            cnt = nextCnt;
            curr = dp[i + 1][result[i]][nextCnt];
        }
    }
    for (char& c : result) c += 'a';
    return result;
}

/// <summary>
/// Leet Code 3469. Find Minimum Cost to Remove Array Elements
/// </summary>
int LeetCodeDP::minCostRemoveElements(int last, int index, vector<int>& nums,
    vector<vector<int>>& dp)
{
    if (index == nums.size()) return nums[last];

    // 2 Elements left
    if (index == nums.size() - 1) return max(nums[last], nums[index]);

    if (dp[last][index] != -1) return dp[last][index];

    // Trying all 3 cases of choosing 2 elements
    int f = max(nums[index], nums[index + 1]) + minCostRemoveElements(last, index + 2, nums, dp);
    int s = max(nums[last], nums[index + 1]) + minCostRemoveElements(index, index + 2, nums, dp);
    int t = max(nums[last], nums[index]) + minCostRemoveElements(index + 1, index + 2, nums, dp);

    //Returning min among the 3
    return dp[last][index] = min({ f, s, t });
}

/// <summary>
/// Leet Code 3469. Find Minimum Cost to Remove Array Elements
///   
/// Medium
///
/// You are given an integer array nums. Your task is to remove all elements 
/// from the array by performing one of the following operations at each 
/// step until nums is empty:
///
/// Choose any two elements from the first three elements of nums and remove 
/// them. The cost of this operation is the maximum of the two elements 
/// removed.
/// If fewer than three elements remain in nums, remove all the remaining 
/// elements in a single operation. The cost of this operation is the maximum 
/// of the remaining elements.
/// Return the minimum cost required to remove all the elements.
/// 
/// Example 1:
/// Input: nums = [6,2,8,4]
/// Output: 12
/// Explanation:
/// Initially, nums = [6, 2, 8, 4].
/// In the first operation, remove nums[0] = 6 and nums[2] = 8 with a cost of 
/// max(6, 8) = 8. Now, nums = [2, 4].
/// In the second operation, remove the remaining elements with a cost of 
/// max(2, 4) = 4.
/// The cost to remove all elements is 8 + 4 = 12. This is the minimum cost 
/// to remove all elements in nums. Hence, the output is 12.
///
/// Example 2:
/// Input: nums = [2,1,3,3]
/// Output: 5
/// Explanation:
/// Initially, nums = [2, 1, 3, 3].
/// In the first operation, remove nums[0] = 2 and nums[1] = 1 with a cost 
/// of max(2, 1) = 2. Now, nums = [3, 3].
/// In the second operation remove the remaining elements with a cost of 
/// max(3, 3) = 3.
/// The cost to remove all elements is 2 + 3 = 5. This is the minimum cost
/// to remove all elements in nums. Hence, the output is 5.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. 1 <= nums[i] <= 10^6
/// </summary>
int LeetCodeDP::minCostRemoveElements(vector<int>& nums)
{
    int n = nums.size();

    // Memoization Table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return minCostRemoveElements(0, 1, nums, dp);
}


/// <summary>
/// Leet Code 3466. Maximum Coin Collection 
///
/// Medium
///
/// Mario drives on a two-lane freeway with coins every mile. You are given 
/// two integer arrays, lane1 and lane2, where the value at the ith index 
/// represents the number of coins he gains or loses in the ith mile in that 
/// lane.
///
/// If Mario is in lane 1 at mile i and lane1[i] > 0, Mario gains lane1[i] 
/// coins.
/// If Mario is in lane 1 at mile i and lane1[i] < 0, Mario pays a toll 
/// and loses abs(lane1[i]) coins.
/// The same rules apply for lane2.
/// Mario can enter the freeway anywhere and exit anytime after traveling 
/// at least one mile. Mario always enters the freeway on lane 1 but can 
/// switch lanes at most 2 times.
///
/// A lane switch is when Mario goes from lane 1 to lane 2 or vice versa.
///
/// Return the maximum number of coins Mario can earn after performing at 
/// most 2 lane switches.
///
/// Note: Mario can switch lanes immediately upon entering or just before 
/// exiting the freeway.
///
/// Example 1:
/// Input: lane1 = [1,-2,-10,3], lane2 = [-5,10,0,1]
/// Output: 14
/// Explanation:
/// Mario drives the first mile on lane 1.
/// He then changes to lane 2 and drives for two miles.
/// He changes back to lane 1 for the last mile.
/// Mario collects 1 + 10 + 0 + 3 = 14 coins.
///
/// Example 2:
/// Input: lane1 = [1,-1,-1,-1], lane2 = [0,3,4,-5]
/// Output: 8
/// Explanation:
/// Mario starts at mile 0 in lane 1 and drives one mile.
/// He then changes to lane 2 and drives for two more miles. He exits the 
/// freeway before mile 3.
/// He collects 1 + 3 + 4 = 8 coins.
///
/// Example 3:
/// Input: lane1 = [-5,-4,-3], lane2 = [-1,2,3]
/// Output: 5
/// Explanation:
/// Mario enters at mile 1 and immediately switches to lane 2. He stays here 
/// the entire way.
/// He collects a total of 2 + 3 = 5 coins.
///
/// Example 4:
/// Input: lane1 = [-3,-3,-3], lane2 = [9,-2,4]
/// Output: 11
/// Explanation:
/// Mario starts at the beginning of the freeway and immediately switches to 
/// lane 2. He stays here the whole way.
/// He collects a total of 9 + (-2) + 4 = 11 coins.
///
/// Example 5:
///
/// Input: lane1 = [-10], lane2 = [-2]
/// Output: -2
/// Explanation:
/// Since Mario must ride on the freeway for at least one mile, he rides just 
/// one mile in lane 2.
/// He collects a total of -2 coins.
/// 
/// Constraints:
/// 1. 1 <= lane1.length == lane2.length <= 10^5
/// 2. -10^9 <= lane1[i], lane2[i] <= 10^9
/// </summary>
long long LeetCodeDP::maxCoins(vector<int>& lane1, vector<int>& lane2)
{
    int n = lane1.size();
    vector<vector<int>> lanes(2, vector<int>(n));
    lanes[0] = lane1;
    lanes[1] = lane2;
    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(n, vector<long long>(3)));
    long long result = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if ((i == 0 && k > 0) || (i == 1 && k > 1)) continue;
                if (j == 1 && k == 2) continue;
                if (i == 0)
                {
                    dp[j][i][0] = lanes[j][i];
                }
                else
                {
                    dp[j][i][k] = max((long long)0, dp[j][i - 1][k]) + lanes[j][i];
                    if (k > 0)
                    {
                        dp[j][i][k] = max(dp[j][i][k], dp[1 - j][i-1][k - 1] + lanes[j][i]);
                    }
                }
                result = max(result, dp[j][i][k]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3472. Longest Palindromic Subsequence After at Most K Operations
///
/// Medium
///
/// You are given a string s and an integer k.
/// 
/// In one operation, you can replace the character at any position with the 
/// next or previous letter in the alphabet (wrapping around so that 'a' is 
/// after 'z'). For example, replacing 'a' with the next letter results in 
/// 'b', and replacing 'a' with the previous letter results in 'z'. Similarly, 
/// replacing 'z' with the next letter results in 'a', and replacing 'z' with 
/// the previous letter results in 'y'.
///
/// Return the length of the longest palindromic subsequence of s that can be 
/// obtained after performing at most k operations.
///
/// Example 1:
/// Input: s = "abced", k = 2
/// Output: 3
/// Explanation:
/// Replace s[1] with the next letter, and s becomes "acced".
/// Replace s[4] with the previous letter, and s becomes "accec".
/// The subsequence "ccc" forms a palindrome of length 3, which is the maximum.
///
/// Example 2:
/// Input: s = "aaazzz", k = 4
/// Output: 6
/// Explanation:
/// Replace s[0] with the previous letter, and s becomes "zaazzz".
/// Replace s[4] with the next letter, and s becomes "zaazaz".
/// Replace s[3] with the next letter, and s becomes "zaaaaz".
/// The entire string forms a palindrome of length 6.
///
/// Constraints:
/// 1. 1 <= s.length <= 200
/// 2. 1 <= k <= 200
/// 3. s consists of only lowercase English letters.
/// </summary>
int LeetCodeDP::longestPalindromicSubsequence(string s, int k)
{
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, INT_MAX)));
    int result = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int start = i;
            int end = i + j;
            if (end >= n) break;
            dp[start][end][1] = 0;
            if (j == 0)
            {
                continue;
            }
            int operation = min(26 - abs(s[start] - s[end]), abs(s[start] - s[end]));
            if (operation <= k)
            {
                dp[start][end][2] = operation;
                result = max(result, 2);
            }
            for (int p = 1; p <= j; p++)
            {
               dp[start][end][p] = min(dp[start][end][p], dp[start + 1][end][p]);
               dp[start][end][p] = min(dp[start][end][p], dp[start][end - 1][p]);
               dp[start][end][p] = min(dp[start][end][p], dp[start + 1][end - 1][p]);
               if (dp[start + 1][end - 1][p] < INT_MAX && operation + dp[start + 1][end - 1][p] <= k)
               {
                   dp[start][end][p + 2] = min(dp[start][end][p + 2], operation + dp[start + 1][end - 1][p]);
                   result = max(result, p + 2);
               }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3473. Sum of K Subarrays With Length at Least M
///
/// Medium
///
/// You are given an integer array nums and two integers, k and m.
/// 
/// Return the maximum sum of k non-overlapping subarrays of nums, where each 
/// subarray has a length of at least m.
///
/// Example 1:
/// Input: nums = [1,2,-1,3,3,4], k = 2, m = 2
/// Output: 13
/// Explanation:
/// The optimal choice is:
/// Subarray nums[3..5] with sum 3 + 3 + 4 = 10 (length is 3 >= m).
/// Subarray nums[0..1] with sum 1 + 2 = 3 (length is 2 >= m).
/// The total sum is 10 + 3 = 13.
///
/// Example 2:
/// Input: nums = [-10,3,-1,-2], k = 4, m = 1
/// Output: -10
/// Explanation:
/// The optimal choice is choosing each element as a subarray. The output is 
/// (-10) + 3 + (-1) + (-2) = -10.
///
/// Constraints:
/// 1. 1 <= nums.length <= 2000
/// 2. -10^4 <= nums[i] <= 10^4
/// 3. 1 <= k <= floor(nums.length / m)
/// 4. 1 <= m <= 3
/// </summary>
int LeetCodeDP::maxSum(vector<int>& nums, int k, int m)
{
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = nums[i - 1] + prefix[i - 1];
    }
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MIN));
    for (int j = 0; j <= n; j++) 
    {
        dp[0][j] = 0;
    }

    for (int i = 0; i <= k; i++) 
    {
        int best = INT_MIN;
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (j > 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
                if (j >= m * i)
                {
                    best = max(best, dp[i - 1][j - m] == INT_MIN ? INT_MIN : dp[i-1][j - m] - prefix[j - m]);
                }
                if (best != INT_MIN)
                {
                    dp[i][j] = max(dp[i][j], prefix[j] + best);
                }
            }
        }
    }
    return dp[k][n];
}

/// <summary>
/// Leet Code 3489. Zero Array Transformation IV
///
/// Medium
///
/// You are given an integer array nums of length n and a 2D array queries, 
/// where queries[i] = [li, ri, vali].
///
/// Each queries[i] represents the following action on nums:
/// 
/// Select a subset of indices in the range [li, ri] from nums.
/// Decrement the value at each selected index by exactly vali.
/// A Zero Array is an array with all its elements equal to 0.
///
/// Return the minimum possible non-negative value of k, such that after 
/// processing the first k queries in sequence, nums becomes a Zero Array. 
/// If no such k exists, return -1.
/// 
/// Example 1:
/// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
/// Output: 2
/// Explanation:
/// For query 0 (l = 0, r = 2, val = 1):
/// Decrement the values at indices [0, 2] by 1.
/// The array will become [1, 0, 1].
/// For query 1 (l = 0, r = 2, val = 1):
/// Decrement the values at indices [0, 2] by 1.
/// The array will become [0, 0, 0], which is a Zero Array. Therefore, the 
/// minimum value of k is 2.
///
/// Example 2:
/// Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
/// Output: -1
/// Explanation:
/// It is impossible to make nums a Zero Array even after all the queries.
///
/// Example 3:
/// Input: nums = [1,2,3,2,1], queries = [[0,1,1],[1,2,1],[2,3,2],[3,4,1],
/// [4,4,1]]
/// Output: 4
/// Explanation:
/// For query 0 (l = 0, r = 1, val = 1):
/// Decrement the values at indices [0, 1] by 1.
/// The array will become [0, 1, 3, 2, 1].
/// For query 1 (l = 1, r = 2, val = 1):
/// Decrement the values at indices [1, 2] by 1.
/// The array will become [0, 0, 2, 2, 1].
/// For query 2 (l = 2, r = 3, val = 2):
/// Decrement the values at indices [2, 3] by 2.
/// The array will become [0, 0, 0, 0, 1].
/// For query 3 (l = 3, r = 4, val = 1):
/// Decrement the value at index 4 by 1.
/// The array will become [0, 0, 0, 0, 0]. Therefore, the minimum value of k 
/// is 4.
///
/// Example 4:
/// Input: nums = [1,2,3,2,6], queries = [[0,1,1],[0,2,1],[1,4,2],[4,4,4],
/// [3,4,1],[4,4,5]]
///
/// Output: 4
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10
/// 2. 0 <= nums[i] <= 1000
/// 3. 1 <= queries.length <= 1000
/// 4. queries[i] = [li, ri, vali]
/// 5. 0 <= li <= ri < nums.length
/// 6. 1 <= vali <= 10
/// </summary>
int LeetCodeDP::minZeroArrayIV(vector<int>& nums, vector<vector<int>>& queries)
{
    vector<vector<int>> dp(nums.size(), vector<int>());
    int count = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        dp[i].resize(nums[i] + 1);
        dp[i][0] = 1;
        if (nums[i] == 0) count++;
    }
    if (count == nums.size()) return 0;
    for (size_t i = 0; i < queries.size(); i++)
    {
        for (int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            if (dp[j][nums[j]] != 0) continue;
            for (int k = nums[j]; k >= queries[i][2]; k--)
            {
                if (dp[j][k - queries[i][2]] == 1)
                {
                    dp[j][k] = 1;
                }
            }
            if (dp[j][nums[j]] != 0) count++;
        }
        if (count == nums.size()) return i + 1;
    }
    return -1;
}

/// <summary>
/// Leet Code 3494. Find the Minimum Amount of Time to Brew Potions
///
/// Medium
/// You are given two integer arrays, skill and mana, of length n and m, 
/// respectively.
///
/// In a laboratory, n wizards must brew m potions in order. Each potion has 
/// a mana capacity mana[j] and must pass through all the wizards sequentially 
/// to be brewed properly. The time taken by the ith wizard on the jth potion 
/// is timeij = skill[i] * mana[j].
///
/// Since the brewing process is delicate, a potion must be passed to the next 
/// wizard immediately after the current wizard completes their work. This means 
/// the timing must be synchronized so that each wizard begins working on a 
/// potion exactly when it arrives. ​
///
/// Return the minimum amount of time required for the potions to be brewed 
/// properly.
///
/// Example 1:
/// Input: skill = [1,5,2,4], mana = [5,1,4,2]
/// Output: 110
/// Explanation:
/// Potion Number	Start time	Wizard 0 done by	Wizard 1 done by	
/// Wizard 2 done by	Wizard 3 done by
/// 0	0	5	30	40	60
/// 1	52	53	58	60	64
/// 2	54	58	78	86	102
/// 3	86	88	98	102	110
/// As an example for why wizard 0 cannot start working on the 1st potion 
/// before time t = 52, consider the case where the wizards started preparing 
/// the 1st potion at time t = 50. At time t = 58, wizard 2 is done with the 
/// 1st potion, but wizard 3 will still be working on the 0th potion till 
/// time t = 60.
///
/// Example 2:
/// Input: skill = [1,1,1], mana = [1,1,1]
/// Output: 5
/// Explanation:
/// Preparation of the 0th potion begins at time t = 0, and is completed by 
/// time t = 3.
/// Preparation of the 1st potion begins at time t = 1, and is completed by 
/// time t = 4.
/// Preparation of the 2nd potion begins at time t = 2, and is completed by 
/// time t = 5.
///
/// Example 3:
/// Input: skill = [1,2,3,4], mana = [1,2]
/// Output: 21
/// 
/// Constraints:
/// 1. n == skill.length
/// 2. m == mana.length
/// 3. 1 <= n, m <= 5000
/// 4. 1 <= mana[i], skill[i] <= 5000
/// </summary>
long long LeetCodeDP::minTime(vector<int>& skill, vector<int>& mana)
{
    int n = skill.size();
    vector<long long> dp(n);
    for (size_t i = 0; i < mana.size(); i++)
    {
        for (size_t j = 0; j < skill.size(); j++)
        {
            if (j == 0) dp[j] = dp[j] + skill[j] * mana[i];
            else dp[j] = max(dp[j - 1], dp[j]) + skill[j] * mana[i];
        }
        for (int j = skill.size() - 2; j >= 0; j--)
        {
            dp[j] = dp[j + 1] - skill[j + 1] * mana[i];
            
        }
    }
    return dp[n - 1];
}

/// <summary>
/// Leet Code 3509. Maximum Product of Subsequences With an Alternating Sum 
///                 Equal to K
/// Hard
///
/// You are given an integer array nums and two integers, k and limit. Your 
/// task is to find a non-empty subsequence of nums that:
///
/// Has an alternating sum equal to k.
/// Maximizes the product of all its numbers without the product exceeding 
/// limit.
/// Return the product of the numbers in such a subsequence. If no subsequence 
/// satisfies the requirements, return -1.
///
/// The alternating sum of a 0-indexed array is defined as the sum of the 
/// elements at even indices minus the sum of the elements at odd indices.
///
/// Example 1:
/// Input: nums = [1,2,3], k = 2, limit = 10
/// Output: 6
/// Explanation:
/// The subsequences with an alternating sum of 2 are:
/// [1, 2, 3]
/// Alternating Sum: 1 - 2 + 3 = 2
/// Product: 1 * 2 * 3 = 6
/// [2]
/// Alternating Sum: 2
/// Product: 2
/// The maximum product within the limit is 6.
/// 
/// Example 2:
/// Input: nums = [0,2,3], k = -5, limit = 12
/// Output: -1
/// Explanation:
/// A subsequence with an alternating sum of exactly -5 does not exist.
/// 
/// Example 3:
/// Input: nums = [2,2,3,3], k = 0, limit = 9
/// Output: 9
/// Explanation:
/// The subsequences with an alternating sum of 0 are:
/// [2, 2]
/// Alternating Sum: 2 - 2 = 0
/// Product: 2 * 2 = 4
/// [3, 3]
/// Alternating Sum: 3 - 3 = 0
/// Product: 3 * 3 = 9
/// [2, 2, 3, 3]
/// Alternating Sum: 2 - 2 + 3 - 3 = 0
/// Product: 2 * 2 * 3 * 3 = 36
/// The subsequence [2, 2, 3, 3] has the greatest product with an alternating 
/// sum equal to k, but 36 > 9. The next greatest product is 9, which is 
/// within the limit.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 150
/// 2. 0 <= nums[i] <= 12
/// 3. -10^5 <= k <= 10^5
/// 4. 1 <= limit <= 5000
/// </summary>
int LeetCodeDP::maxProduct(vector<int>& nums, int k, int limit)
{
    vector<unordered_map<int, unordered_set<int>>> dp(2);
    int result = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        unordered_map<int, unordered_set<int>> alt1;
        if (nums[i] <= limit)
        {
            alt1[nums[i]].insert(nums[i]);
        }
        for (auto itr : dp[1])
        {
            int sum = itr.first + nums[i];
            for (auto product : itr.second)
            {
                if (product == -1 && nums[i] != 0)
                {
                    alt1[sum].insert((int)-1);
                }
                else
                {
                    long long p = (long long)product * nums[i];
                    if (p > (long long)limit)
                    {
                        p = -1;
                    }
                    alt1[sum].insert((int)p);
                }
            }
        }
        unordered_map<int, unordered_set<int>> alt2;
        for (auto itr : dp[0])
        {
            int sum = itr.first - nums[i];
            for (auto product : itr.second)
            {
                if (product == -1 && nums[i] != 0)
                {
                    alt2[sum].insert((int)-1);
                }
                else
                {
                    long long p = (long long)product * nums[i];
                    if (p > (long long)limit)
                    {
                        p = -1;
                    }
                    alt2[sum].insert((int)p);
                }
            }
        }
        for (auto itr : alt1)
        {
            dp[0][itr.first].insert(itr.second.begin(), itr.second.end());
        }
        for (auto itr : alt2)
        {
            dp[1][itr.first].insert(itr.second.begin(), itr.second.end());
        }
    }
    for (auto itr : dp[0][k])
    {
        result = max(result, itr);
    }
    for (auto itr : dp[1][k])
    {
        result = max(result, itr);
    }
    return result;
}

/// <summary>
/// Leet Code 3524. Find X Value of Array I
///
/// Medium
///
/// You are given an array of positive integers nums, and a positive integer k.
///
/// You are allowed to perform an operation once on nums, where in each 
/// operation you can remove any non-overlapping prefix and suffix from nums 
/// such that nums remains non-empty.
///
/// You need to find the x-value of nums, which is the number of ways to 
/// perform this operation so that the product of the remaining elements 
/// leaves a remainder of x when divided by k.
///
/// Return an array result of size k where result[x] is the x-value of nums 
/// for 0 <= x <= k - 1.
///
/// A prefix of an array is a subarray that starts from the beginning of 
/// the array and extends to any point within it.
///
/// A suffix of an array is a subarray that starts at any point within the 
/// array and extends to the end of the array.
///
/// Note that the prefix and suffix to be chosen for the operation can be 
/// empty.
///
/// Example 1:
/// Input: nums = [1,2,3,4,5], k = 3
/// Output: [9,2,4]
/// Explanation:
/// For x = 0, the possible operations include all possible ways to remove 
/// non-overlapping prefix/suffix that do not remove nums[2] == 3.
/// For x = 1, the possible operations are:
/// Remove the empty prefix and the suffix [2, 3, 4, 5]. nums becomes [1].
/// Remove the prefix [1, 2, 3] and the suffix [5]. nums becomes [4].
/// For x = 2, the possible operations are:
/// Remove the empty prefix and the suffix [3, 4, 5]. nums becomes [1, 2].
/// Remove the prefix [1] and the suffix [3, 4, 5]. nums becomes [2].
/// Remove the prefix [1, 2, 3] and the empty suffix. nums becomes [4, 5].
/// Remove the prefix [1, 2, 3, 4] and the empty suffix. nums becomes [5].
///
/// Example 2:
/// Input: nums = [1,2,4,8,16,32], k = 4
/// Output: [18,1,2,0]
/// Explanation:
/// For x = 0, the only operations that do not result in x = 0 are:
/// Remove the empty prefix and the suffix [4, 8, 16, 32]. nums becomes [1, 2].
/// Remove the empty prefix and the suffix [2, 4, 8, 16, 32]. nums becomes [1].
/// Remove the prefix [1] and the suffix [4, 8, 16, 32]. nums becomes [2].
/// For x = 1, the only possible operation is:
/// Remove the empty prefix and the suffix [2, 4, 8, 16, 32]. nums becomes [1].
/// For x = 2, the possible operations are:
/// Remove the empty prefix and the suffix [4, 8, 16, 32]. nums becomes [1, 2].
/// Remove the prefix [1] and the suffix [4, 8, 16, 32]. nums becomes [2].
/// For x = 3, there is no possible way to perform the operation.
///
/// Example 3:
/// Input: nums = [1,1,2,1,1], k = 2
/// Output: [9,6]
/// 
/// Constraints:
/// 1. 1 <= nums[i] <= 10^9
/// 2. 1 <= nums.length <= 10^5
/// 3. 1 <= k <= 5
/// </summary>
vector<long long> LeetCodeDP::resultArrayI(vector<int>& nums, int k)
{
    vector<long long> result(k);
    vector<long long> prev(k);
    for (size_t i = 0; i < nums.size(); i++)
    {
        int r = nums[i] % k;
        vector<long long> curr(k);
        for (int j = 0; j < k; j++)
        {
            curr[r * j % k] += prev[j];
        }
        curr[r]++;
        for (int j = 0; j < k; j++)
        {
            result[j] += curr[j];
        }
        prev = curr;
    }
    return result;
}

/// <summary>
/// Leet Code 3557. Find Maximum Number of Non Intersecting Substrings
///
/// Medium
///
/// You are given a string word.
/// Return the maximum number of non-intersecting substrings of word that are 
/// at least four characters long and start and end with the same letter.
/// 
/// Example 1:
/// Input: word = "abcdeafdef"
/// Output: 2
/// Explanation:
/// The two substrings are "abcdea" and "fdef".
///
/// Example 2:
/// Input: word = "bcdaaaab"
/// Output: 1
/// Explanation:
/// The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" 
/// since it intersects with the other substring.
///
/// Constraints:
/// 1. 1 <= word.length <= 2 * 10^5
/// 2. word consists only of lowercase English letters.
/// </summary>
int LeetCodeDP::maxSubstrings(string word)
{
    vector<vector<int>> char_pos(26);
    vector<int> dp(word.size() + 1);
    for (size_t i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        for (int j = (int)char_pos[index].size() - 1; j >= 0; j--)
        {
            if (i - char_pos[index][j] > 2)
            {
                dp[i + 1] = max(dp[i + 1], dp[char_pos[index][j]] + 1);
                break;
            }
        }
        char_pos[index].push_back(i);
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }
    return dp[word.size()];
}

/// <summary>
/// Leet Code 3578. Count Partitions With Max-Min Difference at Most K
///
/// Medium
///
/// You are given an integer array nums and an integer k. Your task is to 
/// partition nums into one or more non-empty contiguous segments such that 
/// in each segment, the difference between its maximum and minimum elements 
/// is at most k.
///
/// Return the total number of ways to partition nums under this condition.
///
/// Since the answer may be too large, return it modulo 10^9 + 7.
/// Example 1:
/// Input: nums = [9,4,1,3,7], k = 4
/// Output: 6
/// 
/// Explanation:
/// There are 6 valid partitions where the difference between the maximum and 
/// minimum elements in each segment is at most k = 4:
///
/// [[9], [4], [1], [3], [7]]
/// [[9], [4], [1], [3, 7]]
/// [[9], [4], [1, 3], [7]]
/// [[9], [4, 1], [3], [7]]
/// [[9], [4, 1], [3, 7]]
/// [[9], [4, 1, 3], [7]]
///
/// Example 2:
/// Input: nums = [3,3,4], k = 0
/// Output: 2
/// Explanation:
/// There are 2 valid partitions that satisfy the given conditions:
/// [[3], [3], [4]]
/// [[3, 3], [4]]
/// 
/// Constraints:
/// 1. 2 <= nums.length <= 5 * 10^4
/// 2. 1 <= nums[i] <= 10^9
/// 3. 0 <= k <= 10^9
/// </summary>
int LeetCodeDP::countPartitionsII(vector<int>& nums, int k)
{
    int M = 1000000007;
    int n = nums.size();
    vector<int> dp(n + 1), sum(n + 1);
    dp[0] = 1;
    sum[0] = 0;
    map<int, int> heap;
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        heap[nums[i]]++;
        while (heap.rbegin()->first - heap.begin()->first > k)
        {
            heap[nums[left]]--;
            if (heap[nums[left]] == 0)
            {
                heap.erase(nums[left]);
            }
            left++;
        }
        dp[i + 1] = (sum[i] - sum[left] + dp[left] + M) % M;
        sum[i + 1] = (sum[i] + dp[i + 1]) % M;
    }
    return dp[n];
}

/// <summary>
/// Leet Code 3573. Best Time to Buy and Sell Stock V
///
/// Medium
///
/// You are given an integer array prices where prices[i] is the price of a 
/// stock in dollars on the ith day, and an integer k.
///
/// You are allowed to make at most k transactions, where each transaction 
/// can be either of the following:
///
/// Normal transaction: Buy on day i, then sell on a later day j where i < j. 
/// You profit prices[j] - prices[i].
///
/// Short selling transaction: Sell on day i, then buy back on a later day j 
/// where i < j. You profit prices[i] - prices[j].
///
/// Note that you must complete each transaction before starting another. 
/// Additionally, you can't buy or sell on the same day you are selling or 
/// buying back as part of a previous transaction.
///
/// Return the maximum total profit you can earn by making at most k 
/// transactions.
/// 
/// Example 1:
/// Input: prices = [1,7,9,8,2], k = 2
/// Output: 14
/// Explanation:
/// We can make $14 of profit through 2 transactions:
/// A normal transaction: buy the stock on day 0 for $1 then sell it on 
/// day 2 for $9.
/// A short selling transaction: sell the stock on day 3 for $8 then buy back 
/// on day 4 for $2.
///
/// Example 2:
/// Input: prices = [12,16,19,19,8,1,19,13,9], k = 3
/// Output: 36
/// Explanation:
/// We can make $36 of profit through 3 transactions:
/// A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 
/// for $19.
/// A short selling transaction: sell the stock on day 3 for $19 then buy back 
/// on day 4 for $8.
/// A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 
/// for $19.
/// 
/// Constraints:
/// 1. 2 <= prices.length <= 10^3
/// 2. 1 <= prices[i] <= 10^9
/// 3. 1 <= k <= prices.length / 2
/// </summary>
long long LeetCodeDP::maximumProfit(vector<int>& prices, int k)
{
    vector<long long>transaction(k + 1, LLONG_MIN), buy(k + 1, LLONG_MIN), sell(k + 1, LLONG_MIN);
    transaction[0] = 0;
    for (size_t i = 0; i < prices.size(); i++)
    {
        for (int j = k; j > 0; j--)
        {
            if (buy[j] != LLONG_MIN && sell[j] != LLONG_MIN)
            {
                transaction[j] = max(transaction[j], buy[j] + prices[i]);
                transaction[j] = max(transaction[j], sell[j] - prices[i]);
            }
            if (transaction[j - 1] != LLONG_MIN)
            {
                buy[j] = max(buy[j], transaction[j - 1] - prices[i]);
                sell[j] = max(sell[j], transaction[j - 1] + prices[i]);
            }
        }
    }
    long long result = LLONG_MIN;
    for (int i = 0; i <= k; i++)
    {
        result = max(result, transaction[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 3592. Inverse Coin Change 
///
/// Medium
///
/// You are given a 1-indexed integer array numWays, where numWays[i] 
/// represents the number of ways to select a total amount i using an 
/// infinite supply of some fixed coin denominations. Each denomination 
/// is a positive integer with value at most numWays.length.
///
/// However, the exact coin denominations have been lost. Your task is 
/// to recover the set of denominations that could have resulted in the 
/// given numWays array.
///
/// Return a sorted array containing unique integers which represents 
/// this set of denominations.
///
/// If no such set exists, return an empty array.
/// 
/// Example 1:
/// Input: numWays = [0,1,0,2,0,3,0,4,0,5]
/// Output: [2,4,6]
///
/// Explanation:
/// Amount  Number of ways  Explanation
/// 1   0   There is no way to select coins with total value 1.
/// 2   1   The only way is [2].
/// 3   0   There is no way to select coins with total value 3.
/// 4   2   The ways are [2, 2] and [4].
/// 5   0   There is no way to select coins with total value 5.
/// 6   3   The ways are [2, 2, 2], [2, 4], and [6].
/// 7   0   There is no way to select coins with total value 7.
/// 8   4   The ways are [2, 2, 2, 2], [2, 2, 4], [2, 6], and [4, 4].
/// 9   0   There is no way to select coins with total value 9.
/// 10  5   The ways are [2, 2, 2, 2, 2], [2, 2, 2, 4], [2, 4, 4], [2, 2, 6], and [4, 6].
///
/// Example 2:
/// Input: numWays = [1,2,2,3,4]
/// Output: [1,2,5]
/// Explanation:
///
/// Amount  Number of ways  Explanation
/// 1   1   The only way is [1].
/// 2   2   The ways are [1, 1] and [2].
/// 3   2   The ways are [1, 1, 1] and [1, 2].
/// 4   3   The ways are [1, 1, 1, 1], [1, 1, 2], and [2, 2].
/// 5   4   The ways are [1, 1, 1, 1, 1], [1, 1, 1, 2], [1, 2, 2], and [5].
///
/// Example 3:
/// Input: numWays = [1,2,3,4,15]
/// Output: []
/// Explanation:
/// No set of denomination satisfies this array.
/// 
/// Constraints:
/// 1. 1 <= numWays.length <= 100
/// 2. 0 <= numWays[i] <= 2 * 10^8
/// </summary>
vector<int> LeetCodeDP::findCoins(vector<int>& numWays)
{
    vector<int> result;
    vector<int> dp(numWays.size());
    for (size_t i = 0; i < numWays.size(); i++)
    {
        if (numWays[i] != dp[i] &&  numWays[i] != dp[i] + 1)
        {
            return vector<int>();
        }
        if (numWays[i] == dp[i] + 1)
        {
            dp[i]++;
            result.push_back(i + 1);
            for (size_t j = 0; j + i + 1< numWays.size(); j++)
            {
                dp[j + i + 1] += dp[j];
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3599. Partition Array to Minimize XOR
///
/// Medium
/// You are given an integer array nums and an integer k.
///
/// Your task is to partition nums into k non-empty subarrays. For each 
/// subarray, compute the bitwise XOR of all its elements.
///
/// Return the minimum possible value of the maximum XOR among these k 
/// subarrays.
///
/// Example 1:
/// Input: nums = [1,2,3], k = 2
/// Output: 1
/// Explanation:
/// The optimal partition is [1] and [2, 3].
/// XOR of the first subarray is 1.
/// XOR of the second subarray is 2 XOR 3 = 1.
/// The maximum XOR among the subarrays is 1, which is the minimum possible.
///
/// Example 2:
/// Input: nums = [2,3,3,2], k = 3
/// Output: 2
/// Explanation:
/// The optimal partition is [2], [3, 3], and [2].
/// XOR of the first subarray is 2.
/// XOR of the second subarray is 3 XOR 3 = 0.
/// XOR of the third subarray is 2.
/// The maximum XOR among the subarrays is 2, which is the minimum possible.
///
/// Example 3:
/// Input: nums = [1,1,2,3,1], k = 2
/// Output: 0
/// Explanation:
/// The optimal partition is [1, 1] and [2, 3, 1].
/// XOR of the first subarray is 1 XOR 1 = 0.
/// XOR of the second subarray is 2 XOR 3 XOR 1 = 0.
/// The maximum XOR among the subarrays is 0, which is the minimum possible.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 250
/// 2. 1 <= nums[i] <= 10^9
/// 3. 1 <= k <= n
/// </summary>
int LeetCodeDP::minXor(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        if (i == 0) dp[i][0] = nums[i];
        else dp[i][0] = dp[i - 1][0] ^ nums[i];
        for (int j = 0; j < i; j++)
        {
            for (int p = 0; p <= j && p < k - 1; p++)
            {
                int val = max(dp[j][p], dp[i][0] ^ dp[j][0]);
                dp[i][p + 1] = min(dp[i][p + 1], val);
            }
        }
    }
    return dp[n - 1][k - 1];
}

/// <summary>
/// Leet Code 3610. Minimum Number of Primes to Sum to Target
///
/// Medium
///
/// You are given two integers n and m.
/// 
/// You have to select a multiset of prime numbers from the first m prime 
/// numbers such that the sum of the selected primes is exactly n. You may 
/// use each prime number multiple times.
///
/// Return the minimum number of prime numbers needed to sum up to n, or -1 
/// if it is not possible.
/// 
/// Example 1:
/// Input: n = 10, m = 2
/// Output: 4
/// Explanation:
/// The first 2 primes are [2, 3]. The sum 10 can be formed as 2 + 2 + 3 + 3, 
/// requiring 4 primes.
///
/// Example 2:
/// Input: n = 15, m = 5
/// Output: 3
/// Explanation:
/// The first 5 primes are [2, 3, 5, 7, 11]. The sum 15 can be formed 
/// as 5 + 5 + 5, requiring 3 primes.
///
/// Example 3:
/// Input: n = 7, m = 6
/// Output: 1
/// Explanation:
/// The first 6 primes are [2, 3, 5, 7, 11, 13]. The sum 7 can be formed 
/// directly by prime 7, requiring only 1 prime.
/// 
/// Constraints:
/// 1. 1 <= n <= 1000
/// 2. 1 <= m <= 1000
/// </summary>
int LeetCodeDP::minNumberOfPrimes(int n, int m)
{
    vector<int> dp(n + 1), primes;
    for (int i = 2; i <= n; i++)
    {
        if (primes.size() == m) break;
        if (isPrime(i)) primes.push_back(i);
        if (i % 2 == 1) i++;
    }
    for (int i = 2; i <= n; i++)
    {
        for (size_t j = 0; j < primes.size(); j++)
        {
            if (primes[j] > i) break;
            if ((i - primes[j] == 0) || (dp[i - primes[j]] > 0))
            {
                if (dp[i] == 0)
                {
                    dp[i] = dp[i - primes[j]] + 1;
                }
                else
                {
                    dp[i] = min(dp[i], dp[i - primes[j]] + 1);
                }
            }
        }
    }
    if (dp[n] == 0) return -1;
    else return dp[n];
}


/// <summary>
/// Leet Code 3603. Minimum Cost Path with Alternating Directions II
///
/// Medium
///
/// You are given two integers m and n representing the number of rows and 
/// columns of a grid, respectively.
///
/// The cost to enter cell (i, j) is defined as (i + 1) * (j + 1).
///
/// You are also given a 2D integer array waitCost where waitCost[i][j] 
/// defines the cost to wait on that cell.
///
/// You start at cell (0, 0) at second 1.
///
/// At each step, you follow an alternating pattern:
///
/// On odd-numbered seconds, you must move right or down to an adjacent cell, 
/// paying its entry cost.
/// On even-numbered seconds, you must wait in place, paying waitCost[i][j].
/// Return the minimum total cost required to reach (m - 1, n - 1).
///
/// Example 1:
/// Input: m = 1, n = 2, waitCost = [[1,2]]
/// Output: 3
/// Explanation:
/// The optimal path is:
/// Start at cell (0, 0) at second 1 with entry cost (0 + 1) * (0 + 1) = 1.
/// Second 1: Move right to cell (0, 1) with entry cost (0 + 1) * (1 + 1) = 2.
/// Thus, the total cost is 1 + 2 = 3.
///
/// Example 2:
/// Input: m = 2, n = 2, waitCost = [[3,5],[2,4]]
/// Output: 9
/// Explanation:
/// The optimal path is:
/// Start at cell (0, 0) at second 1 with entry cost (0 + 1) * (0 + 1) = 1.
/// Second 1: Move down to cell (1, 0) with entry cost (1 + 1) * (0 + 1) = 2.
/// Second 2: Wait at cell (1, 0), paying waitCost[1][0] = 2.
/// Second 3: Move right to cell (1, 1) with entry cost (1 + 1) * (1 + 1) = 4.
/// Thus, the total cost is 1 + 2 + 2 + 4 = 9.
///
/// Example 3:
/// Input: m = 2, n = 3, waitCost = [[6,1,4],[3,2,5]]
/// Output: 16
/// Explanation:
/// The optimal path is:
/// Start at cell (0, 0) at second 1 with entry cost (0 + 1) * (0 + 1) = 1.
/// Second 1: Move right to cell (0, 1) with entry cost (0 + 1) * (1 + 1) = 2.
/// Second 2: Wait at cell (0, 1), paying waitCost[0][1] = 1.
/// Second 3: Move down to cell (1, 1) with entry cost (1 + 1) * (1 + 1) = 4.
/// Second 4: Wait at cell (1, 1), paying waitCost[1][1] = 2.
/// Second 5: Move right to cell (1, 2) with entry cost (1 + 1) * (2 + 1) = 6.
/// Thus, the total cost is 1 + 2 + 1 + 4 + 2 + 6 = 16.
/// 
/// Constraints:
/// 1. 1 <= m, n <= 10^5
/// 2. 2 <= m * n <= 10^5
/// 3. waitCost.length == m
/// 4. waitCost[0].length == n
/// 5. 0 <= waitCost[i][j] <= 10^5
/// </summary>
long long LeetCodeDP::minCost(int m, int n, vector<vector<int>>& waitCost)
{
    vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = (i + 1) * (j + 1);
            }
            else
            {
                if (i > 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                }
                if (j > 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                }
                dp[i][j] += (long long)(i + 1) * (long long)(j + 1);
                if (i == m- 1 && j == n - 1) break;
                dp[i][j] += waitCost[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}

#pragma endregion

