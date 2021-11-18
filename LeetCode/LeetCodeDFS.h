#pragma once
#ifndef LeetCodeDFS_H
#define LeetCodeDFS_H
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
class LeetCodeDFS
{
public:
#pragma region DFS

    /// <summary>
    /// Palindrome Partitioning with cache
    /// </summary>
    vector<vector<string>> partitionPalindrome(string s, unordered_map<string, vector<vector<string>>>& partition);

    /// <summary>
    /// Leet code #131. Palindrome Partitioning       
    /// Given a string s, partition s such that every substring of the partition is a palindrome. 
    /// Return all possible palindrome partitioning of s. 
    /// For example, given s = "aab",
    /// Return 
    /// [
    ///  ["aa","b"],
    ///  ["a","a","b"]
    /// ]
    /// </summary>
    vector<vector<string>> partitionPalindrome(string s);

    /// <summary>
    /// Leet code #140. Word Break II
    /// Recursive break the word according to dictionary, return word list 
    /// </summary>
    vector<string> wordBreakII(string s, unordered_set<string>& wordDict,
        unordered_map<string, vector<string>>& search_map);

    /// <summary>
    /// Leet code #140. Word Break II  
    /// Given a string s and a dictionary of words dict, add spaces in s to 
    /// construct a sentence where each word is a valid dictionary word. 
    /// Return all such possible sentences.
    /// For example, given
    /// s = "catsanddog",
    /// dict = ["cat", "cats", "and", "sand", "dog"]. 
    /// A solution is ["cats and dog", "cat sand dog"].
    /// </summary>
    vector<string> wordBreakII(string s, vector<string>& wordDictt);

    /// <summary>
    /// Leet code #247. Strobogrammatic Number II 
    /// </summary>
    void findStrobogrammatic(int i, int n, string& str, vector<string>& result, map<char, char>& num_map);

    /// <summary>
    /// Leet code #247. Strobogrammatic Number II 
    /// 
    /// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
    /// Find all strobogrammatic numbers that are of length = n. 
    /// For example,
    /// Given n = 2, return ["11","69","88","96"].
    /// Hint:
    /// 1.Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
    /// </summary>
    vector<string> findStrobogrammatic(int n);

    /// <summary>
    /// Leet code #248. Strobogrammatic Number III 
    /// </summary>
    void strobogrammaticInRange(int i, int n, string low, string high, string& str, int& count, map<char, char>& num_map);

    /// <summary>
    /// Leet code #248. Strobogrammatic Number III 
    /// 
    /// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
    /// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high. 
    /// For example,
    /// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers. 
    /// Note:
    /// Because the range might be a large number, the low and high numbers are represented as string.
    /// </summary>
    int strobogrammaticInRange(string low, string high);

    /// <summary>
    /// Leet code #17. Letter Combinations of a Phone Number 
    /// </summary>
    void letterCombinations(string& digits, string& path, 
        unordered_map<char, string> &phone_keyboard, vector<string>& result);

    /// <summary>
    /// Leet code #17. Letter Combinations of a Phone Number
    ///
    /// Medium
    ///
    /// Given a string containing digits from 2-9 inclusive, return all 
    /// possible letter combinations that the number could represent.
    ///
    /// A mapping of digit to letters (just like on the telephone buttons)
    /// is given below. Note that 1 does not map to any letters.
    ///
    /// Example:
    ///
    /// Input: "23"
    /// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    /// Note:
    /// Although the above answer is in lexicographical order, your answer 
    /// could be in any order you want.
    /// </summary>
    vector<string> letterCombinations(string digits);

    /// <summary>
    /// Leet code #22. Generate Parentheses 
    /// </summary>
    void generateParenthesis(string& path, int n, int left, 
        int right, vector<string>& result);

    /// <summary>
    /// Leet code #22. Generate Parentheses 
    ///
    /// Given n pairs of parentheses, write a function to generate all 
    /// combinations of well-formed parentheses. 
    /// For example, given n = 3, a solution set is: 
    /// [
    ///   "((()))",
    ///   "(()())",
    ///   "(())()",
    ///   "()(())",
    ///   "()()()"
    /// ]
    /// </summary>
    vector<string> generateParenthesis(int n);

    /// <summary>
    /// Leet code #37. Sudoku Solver
    /// </summary>
    bool solveSudoku(
        vector<vector<char>>& board, vector<vector<int>>& row_visited,
        vector<vector<int>>& col_visited, vector<vector<int>>& square_visited,
        int x, int y);

    /// <summary>
    /// Leet code #37. Sudoku Solver
    /// Write a program to solve a Sudoku puzzle by filling the empty cells.
    /// Empty cells are indicated by the character '.'.
    /// You may assume that there will be only one unique solution.
    /// For example, the input is
    ///   53..7....
    ///   6..195...
    ///   .98....6.
    ///   8...6...3
    ///   4..8.3..1
    ///   7...2...6
    ///   .6....28.
    ///   ...419..5
    ///   ....8..79
    /// The output is:
    ///   534678912
    ///   672195348
    ///   198342567
    ///   859761423
    ///   426853791
    ///   713924856
    ///   961537284
    ///   287419635
    ///   345286179
    /// </summary>
    void solveSudoku(vector<vector<char>>& board);

    /// <summary>
    /// Leet code # 51. N-Queens 
    /// </summary>
    void solveNQueens(vector<string>& board, int row, vector<int>& columns,
        vector<int>& diag, vector<vector<string>>& result);

    /// <summary>
    /// Leet code # 51. N-Queens 
    /// 
    /// The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other. 
    /// Given an integer n, return all distinct solutions to the n-queens puzzle.
    ///	
    /// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
    /// both indicate a queen and an empty space respectively. 
    /// For example,
    /// There exist two distinct solutions to the 4-queens puzzle:
    /// [
    ///   [".Q..",  // Solution 1
    ///    "...Q",
    ///    "Q...",
    ///    "..Q."],
    ///
    ///   ["..Q.",  // Solution 2
    ///    "Q...",
    ///    "...Q",
    ///    ".Q.."]
    /// ]	
    /// </summary>
    vector<vector<string>> solveNQueens(int n);

    /// <summary>
    /// Leet code # 52. N-Queens II 
    /// </summary>
    void totalNQueens(int n, int row, vector<int>& columns, vector<int>& diag, int& count);

    /// <summary>
    /// Leet code # 52. N-Queens II 
    /// 
    /// Follow up for N-Queens problem. 
    /// Now, instead outputting board configurations, return the total number of distinct solutions.
    /// </summary>
    int totalNQueens(int n);

    /// <summary>
    /// Leet code #39. Combination Sum
    /// </summary>
    void combinationSum(vector<int>& candidates, int target, int index,
        vector<int>& path, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #39. Combination Sum
    ///
    /// Given a set of candidate numbers (C) and a target number (T), 
    /// find all unique combinations in C where the candidate numbers sums to T. 
    /// The same repeated number may be chosen from C unlimited number of times. 
    /// Note:
    /// All numbers (including target) will be positive integers.
    /// The solution set must not contain duplicate combinations.
    /// For example, given candidate set [2, 3, 6, 7] and target 7, 
    /// A solution set is: 
    /// [
    ///   [7],
    ///   [2, 2, 3]
    /// ]
    /// </summary>
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

    /// <summary>
    /// Leet code #40. Combination Sum II
    /// </summary>
    void combinationSum2(vector<int>& candidates, int target, int index, 
        vector<int>& path, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #40. Combination Sum II
    ///
    /// Medium
    ///
    /// Given a collection of candidate numbers (candidates) and a target 
    /// number (target), find all unique combinations in candidates where 
    /// the candidate numbers sums to target.
    ///
    /// Each number in candidates may only be used once in the combination.
    ///
    /// Note:
    ///
    /// All numbers (including target) will be positive integers.
    /// The solution set must not contain duplicate combinations.
    ///
    /// Example 1:
    /// Input: candidates = [10,1,2,7,6,1,5], target = 8,
    /// A solution set is:
    /// [
    ///   [1, 7],
    ///   [1, 2, 5],
    ///   [2, 6],
    ///   [1, 1, 6]
    /// ]
    ///
    /// Example 2:
    ///
    /// Input: candidates = [2,5,2,1,2], target = 5,
    /// A solution set is:
    /// [
    ///   [1,2,2],
    ///   [5]
    /// ]
    /// </summary>
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

    /// <summary>
    /// Leet code #46. Permutations 
    /// </summary>
    void permute(vector<int>& nums, vector<int>& path,
        vector<int>& visited, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #46. Permutations 
    /// Given a collection of distinct numbers, return all possible permutations. 
    /// For example,
    /// [1,2,3] have the following permutations:
    /// [
    ///   [1,2,3],
    ///   [1,3,2],
    ///   [2,1,3],
    ///   [2,3,1],
    ///   [3,1,2],
    ///   [3,2,1]
    /// ]
    /// </summary>
    vector<vector<int>> permute(vector<int>& nums);

    /// <summary>
    /// Leet code #47. Permutations II 
    /// </summary>
    void permuteUnique(vector<int>& nums, vector<int>& path,
        vector<int>& visited, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #47. Permutations II 
    /// Given a collection of numbers that might contain duplicates,
    /// return all possible unique permutations. 
    /// For example,
    /// [1,1,2] have the following unique permutations:
    /// [
    ///   [1,1,2],
    ///   [1,2,1],
    ///   [2,1,1]
    /// ]
    /// </summary>
    vector<vector<int>> permuteUnique(vector<int>& nums);

    /// <summary>
    /// Leet code #77. Combinations
    /// </summary>
    void combine(int n, int k, vector<int>& path, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #77. Combinations 
    ///
    /// Given two integers n and k, return all possible combinations of k 
    /// numbers out of 1 ... n. 
    /// For example,
    /// If n = 4 and k = 2, a solution is: 
    /// [
    ///  [2,4],
    ///  [3,4],
    ///  [2,3],
    ///  [1,2],
    ///  [1,3],
    ///  [1,4],
    /// ]
    /// </summary>
    vector<vector<int>> combine(int n, int k);

    /// <summary>
    /// Leet code #78. Subsets
    /// </summary>
    void subsets(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #78. Subsets
    /// Given a set of distinct integers, nums, return all possible subsets.  
    /// Note: The solution set must not contain duplicate subsets. 
    ///	For example,
    /// If nums = [1,2,3], a solution is: 
    /// [
    ///  [3],
    ///  [1],
    ///  [2],
    ///  [1,2,3],
    ///  [1,3],
    ///  [2,3],
    ///  [1,2],
    ///  []
    /// ]
    /// </summary>
    vector<vector<int>> subsets(vector<int>& nums);

    /// <summary>
    /// Leet code #90. Subsets II
    /// </summary>
    void subsetsWithDup(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #90. Subsets II
    ///
    /// Given a collection of integers that might contain duplicates, nums, 
    /// return all possible subsets.  
    /// Note: The solution set must not contain duplicate subsets. 
    ///	For example,
    /// If nums = [1,2,2], a solution is: 
    /// [
    ///  [2],
    ///  [1],
    ///  [1,2,2],
    ///  [2,2],
    ///  [1,2],
    ///  []
    /// ] 
    /// </summary>
    vector<vector<int>> subsetsWithDup(vector<int>& nums);

    /// <summary>
    /// Leet code #79. Word Search
    /// </summary>
    bool wordSearch(vector<vector<char>>& board, vector<vector<bool>>& flag,
        string word, int x, int y, int pos);

    /// <summary>
    /// Leet code #79. Word Search  
    ///
    /// Given a 2D board and a word, find if the word exists in the grid. 
    /// The word can be constructed from letters of sequentially adjacent 
    /// cell, where "adjacent" cells are those 
    /// horizontally or vertically neighboring. The same letter cell may not 
    /// be used more than once. 
    /// For example,
    /// Given board = 
    /// [
    ///   ['A','B','C','E'],
    ///   ['S','F','C','S'],
    ///   ['A','D','E','E']
    /// ]
    /// word = "ABCCED", -> returns true,
    /// word = "SEE", -> returns true,
    /// word = "ABCB", -> returns false.	
    /// </summary>
    bool wordSearch(vector<vector<char>>& board, string word);

    /// <summary>
    /// LeetCode #93. Restore IP Addresses
    ///
    /// Restore IP address by split into specified segment
    /// </summary>
    vector<string> restoreIpAddresses(string s, size_t segments);

    /// <summary>
    /// LeetCode #93. Restore IP Addresses  
    ///
    /// Given a string containing only digits, restore it by returning all 
    /// possible valid IP address combinations. 
    /// For example:
    /// Given "25525511135", 
    /// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
    /// </summary>
    vector<string> restoreIpAddresses(string s);

    /// <summary>
    /// Get word ladder path  
    /// </summary>
    vector<vector<string>> findWordLadderPath(string beginWord, string endWord,
        unordered_map<string, unordered_set<string>>& word_map);

    /// <summary>
    /// Leet code #126. Word Ladder II  
    ///
    /// Given two words (beginWord and endWord), and a dictionary's word list, 
    /// find the length of shortest transformation sequence from beginWord 
    /// to endWord, such that: 
    /// 1.Only one letter can be changed at a time.
    /// 2.Each intermediate word must exist in the word list.
    /// For example,
    /// Given:
    /// beginWord = "hit"
    /// endWord = "cog"
    /// wordList = ["hot","dot","dog","lot","log"]
    /// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", 
    /// Return
    /// [
    ///   ["hit", "hot", "dot", "dog", "cog"],
    ///   ["hit", "hot", "lot", "log", "cog"]
    /// ]
    /// Note:
    /// All words have the same length.
    /// All words contain only lowercase alphabetic characters.
    /// </summary>
    vector<vector<string>> findLadders(string beginWord, string endWord,
        unordered_set<string> &wordList);


    /// <summary>
    /// Leet code #216. Combination Sum III 
    /// </summary>
    vector<vector<int>> combinationSum3(int k, int n, int start);

    /// <summary>
    /// Leet code #216. Combination Sum III 
    ///
    /// Find all possible combinations of k numbers that add up to a number n, 
    /// given that only numbers from 1 to 9 can be used and each combination 
    /// should be a unique set of numbers.
    /// 
    /// Example 1:
    /// Input: k = 3, n = 7
    /// Output: 
    /// [[1,2,4]]
    ///
    /// Example 2:
    /// Input: k = 3, n = 9
    /// Output: 
    /// [[1,2,6], [1,3,5], [2,3,4]]
    /// </summary>
    vector<vector<int>> combinationSum3(int k, int n);

    /// <summary>
    /// Leet code #241. Different Ways to Add Parentheses 
    ///
    /// Given a string of numbers and operators, return all possible 
    /// results from computing all the different possible ways to group 
    /// numbers and operators. The valid operators are +, - and *.
    ///
    /// Example 1 
    /// Input: "2-1-1".
    /// ((2-1)-1) = 0
    /// (2-(1-1)) = 2
    /// Output: [0, 2]
    ///
    /// Example 2 
    /// Input: "2*3-4*5"
    /// (2*(3-(4*5))) = -34
    /// ((2*3)-(4*5)) = -14
    /// ((2*(3-4))*5) = -10
    /// (2*((3-4)*5)) = -10
    /// (((2*3)-4)*5) = 10
    /// Output: [-34, -14, -10, -10, 10]
    /// </summary>
    vector<int> diffWaysToCompute(string input);

    /// <summary>
    /// Leet code #329. Longest Increasing Path in a Matrix
    /// </summary>
    int longestIncreasingPath(vector<vector<int>>& matrix, 
        vector<vector<int>>& path, vector<vector<int>>& directions, 
        int i, int j);

    /// <summary>
    /// Leet code #329. Longest Increasing Path in a Matrix
    ///
    /// Hard
    ///
    /// Given an integer matrix, find the length of the longest increasing 
    /// path.
    /// From each cell, you can either move to four directions: left, right, 
    /// up or down. You may NOT move diagonally or move outside of the 
    /// boundary (i.e. wrap-around is not allowed).
    /// Example 1:
    /// Input: nums = 
    /// [
    ///  [9,9,4],
    ///  [6,6,8],
    ///  [2,1,1]
    /// ] 
    /// Output: 4 
    /// Explanation: The longest increasing path is [1, 2, 6, 9].
    ///
    /// Example 2:
    /// Input: nums = 
    /// [
    ///  [3,4,5],
    ///  [3,2,6],
    ///  [2,2,1]
    /// ] 
    /// Output: 4 
    /// Explanation: The longest increasing path is [3, 4, 5, 6]. 
    /// Moving diagonally is not allowed.
    /// </summary>
    int longestIncreasingPath(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #401. Binary Watch  
    /// </summary> 
    void readBinaryWatch(int num, vector<int>& path, int sum, vector<string>& result);

    /// <summary>
    /// Leet code #401. Binary Watch  
    ///
    /// A binary watch has 4 LEDs on the top which represent the hours (0-11), 
    /// and the 6 LEDs on the bottom represent the minutes (0-59). 
    /// Each LED represents a zero or one, with the least significant bit on 
    /// the right.
    /// Given a non-negative integer n which represents the number of LEDs 
    /// that are currently on, return all possible times the watch could 
    /// represent
    ///
    /// Example:
    /// Input: n = 1
    /// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", 
    ///          "0:08", "0:16", "0:32"]
    /// Note:
    /// The order of output does not matter.
    /// The hour must not contain a leading zero, for example "01:00" is not 
    /// valid, it should be "1:00".
    /// The minute must be consist of two digits and may contain a leading 
    /// zero, for example "10:2" is not valid, it should be "10:02".
    /// </summary> 
    vector<string> readBinaryWatch(int num);

    /// <summary>
    /// Leet code #401. Binary Watch  
    ///
    /// A binary watch has 4 LEDs on the top which represent the hours (0-11), 
    /// and the 6 LEDs on the bottom represent the minutes (0-59). 
    /// Each LED represents a zero or one, with the least significant bit on 
    /// the right.
    /// Given a non-negative integer n which represents the number of LEDs 
    /// that are currently on, return all possible times the watch could 
    /// represent
    ///
    /// Example:
    /// Input: n = 1
    /// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", 
    ///          "0:08", "0:16", "0:32"]
    /// Note:
    /// The order of output does not matter.
    /// The hour must not contain a leading zero, for example "01:00" is not 
    /// valid, it should be "1:00".
    /// The minute must be consist of two digits and may contain a leading 
    /// zero, for example "10:2" is not valid, it should be "10:02".
    /// </summary> 
    vector<string> readBinaryWatchII(int num);

    /// <summary>
    /// Leet code #416. Partition Equal Subset Sum
    /// </summary>
    bool canPartition(vector<int>& nums, size_t start, int sum);

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
    /// Leet code #464. Can I Win
    /// </summary>
    bool canIWin(int maxChoosableInteger, int desiredTotal, int signature,
        unordered_map<int, bool>& game_map);

    /// <summary>
    /// Leet code #464. Can I Win
    ///
    /// In the "100 game," two players take turns adding, to a running total, 
    /// any integer from 1..10. 
    /// The player who first causes the running total to reach or exceed 100 wins. 
    /// What if we change the game so that players cannot re-use integers? 
    /// For example, two players might take turns drawing from a common pool of 
    /// numbers of 1..15 without replacement until they reach a total >= 100.
    /// Given an integer maxChoosableInteger and another integer desiredTotal, 
    /// determine if the first player to move can force a win, assuming both 
    /// players play optimally. 
    /// You can always assume that maxChoosableInteger will not be larger than 20 
    /// and desiredTotal will not be larger than 300. 
    ///
    /// Example 
    /// Input:
    /// maxChoosableInteger = 10
    /// desiredTotal = 11
    /// Output:
    /// false
    /// Explanation:
    /// No matter which integer the first player choose, the first player will lose.
    /// The first player can choose an integer from 1 up to 10.
    /// If the first player choose 1, the second player can only choose integers 
    /// from 2 up to 10.
    /// The second player will win by choosing 10 and get a total = 11, which 
    /// is >= desiredTotal.
    /// Same with other integers chosen by the first player, the second player will
    /// always win.
    /// </summary>
    bool canIWin(int maxChoosableInteger, int desiredTotal);

    /// <summary>
    /// Leet code #491. Increasing Subsequences 
    /// </summary>
    void findSubsequences(vector<int>& nums, size_t start_index,
        vector<int>& sequence, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #491. Increasing Subsequences 
    /// 
    /// Given an integer array, your task is to find all the different 
    /// possible increasing subsequences of the given array, and the length 
    /// of an increasing subsequence should be at least 2 . 
    ///
    /// Example:
    /// Input: [4, 6, 7, 7]
    /// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
    /// Note:
    /// 1.The length of the given array will not exceed 15.
    /// 2.The range of integer in the given array is [-100,100].
    /// 3.The given array may contain duplicates, and two equal integers 
    ///   should also be considered as a special case of increasing sequence.
    /// </summary>
    vector<vector<int>> findSubsequences(vector<int>& nums);

    /// <summary>
    /// Leet code #526. Beautiful Arrangement
    /// </summary>
    int countArrangement(int N, int index, int visited, unordered_map<int, int>& cache);

    /// <summary>
    /// Leet code #526. Beautiful Arrangement
    ///
    /// Suppose you have N integers from 1 to N. We define a beautiful 
    /// arrangement as an array that is constructed by these N numbers 
    /// successfully if one of the following is true for the ith position 
    /// (1 ¡Ü i ¡Ü N) in this array: 
    /// 1.The number at the ith position is divisible by i.
    /// 2.i is divisible by the number at the ith position.
    ///
    /// Now given N, how many beautiful arrangements can you construct? 
    ///
    /// Example 1:
    /// 
    /// Input: 2
    /// Output: 2
    ///
    /// Explanation: 
    /// The first beautiful arrangement is [1, 2]:
    /// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
    /// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
    ///
    /// The second beautiful arrangement is [2, 1]:
    /// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
    /// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
    /// Note:
    /// 1.N is a positive integer and will not exceed 15.
    /// </summary>
    int countArrangement(int N);

    /// <summary>
    /// Leet code #1219. Path with Maximum Gold
    /// </summary>
    int getMaximumGold(vector<vector<int>>& grid, int r, int c);

    /// <summary>
    /// Leet code #1219. Path with Maximum Gold
    /// 
    /// In a gold mine grid of size m * n, each cell in this mine has an 
    /// integer representing the amount of gold in that cell, 0 if it is 
    /// empty.
    /// Return the maximum amount of gold you can collect under the 
    /// conditions:
    /// Every time you are located in a cell you will collect all the 
    /// gold in that cell.
    /// From your position you can walk one step to the left, right, up
    /// or down.
    /// You can't visit the same cell more than once.
    /// Never visit a cell with 0 gold.
    /// You can start and stop collecting gold from any position in the 
    /// grid that has some gold.
    ///
    /// Example 1:
    /// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
    /// Output: 24
    /// Explanation:
    /// [[0,6,0],
    ///  [5,8,7],
    ///  [0,9,0]]
    /// Path to get the maximum gold, 9 -> 8 -> 7.
    ///
    /// Example 2:
    /// Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
    /// Output: 28
    /// Explanation:
    /// [[1,0,7],
    ///  [2,0,6],
    ///  [3,4,5],
    /// [0,3,0],
    ///  [9,0,20]]
    /// Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
    /// 
    /// Constraints:
    /// 1. 1 <= grid.length, grid[i].length <= 15
    /// 2. 0 <= grid[i][j] <= 100
    /// 3. There are at most 25 cells containing gold.
    /// </summary>
    int getMaximumGold(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1240. Tiling a Rectangle with the Fewest Squares
    /// </summary>
    int tilingRectangle(int n, int m, vector<int>& heights, unordered_map<long long, int>&shape, int count, int result);

    /// <summary>
    /// Leet code #1240. Tiling a Rectangle with the Fewest Squares
    /// 
    /// Given a rectangle of size n x m, find the minimum number of integer-sided 
    /// squares that tile the rectangle.
    /// 
    /// Example 1:
    ///
    /// Input: n = 2, m = 3
    /// Output: 3
    /// Explanation: 3 squares are necessary to cover the rectangle.
    /// 2 (squares of 1x1)
    /// 1 (square of 2x2)
    ///
    /// Example 2:
    ///
    /// Input: n = 5, m = 8
    /// Output: 5
    ///
    /// Example 3:
    /// 
    /// Input: n = 11, m = 13
    /// Output: 6
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 13
    /// 2. 1 <= m <= 13
    /// </summary>
    int tilingRectangle(int n, int m);

 
    /// <summary>
    /// Leetcode #1307. Verbal Arithmetic Puzzle
    /// </summary>
    bool isSolvable(vector<int>& chars, int col, int row, vector<int>& digits,
        vector<string>& reverse_words, string& reverse_result, int sum, int max_len);

    /// <summary>
    /// Leetcode #1307. Verbal Arithmetic Puzzle
    ///
    /// Hard
    ///
    /// Given an equation, represented by words on left side and the result 
    /// on right side.
    ///
    /// You need to check if the equation is solvable under the following 
    /// rules:
    ///
    /// Each character is decoded as one digit (0 - 9).
    /// Every pair of different characters they must map to different digits.
    /// Each words[i] and result are decoded as one number without leading 
    /// zeros.
    /// Sum of numbers on left side (words) will equal to the number on right 
    /// side (result). 
    /// Return True if the equation is solvable otherwise return False.
    ///
    /// Example 1:
    /// Input: words = ["SEND","MORE"], result = "MONEY"
    /// Output: true
    /// Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 
    /// 'R'->8, 'Y'->'2'
    /// Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
    ///
    /// Example 2:
    /// Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
    /// Output: true
    /// Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 
    /// 'T'->1, 'W'->'3', 'Y'->4
    /// Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  
    ///  650 + 68782 + 68782 = 138214
    ///
    /// Example 3:
    /// Input: words = ["THIS","IS","TOO"], result = "FUNNY"
    /// Output: true
    ///
    /// Example 4:
    /// Input: words = ["LEET","CODE"], result = "POINT"
    /// Output: false
    /// 
    /// Constraints:
    /// 1. 2 <= words.length <= 5
    /// 2. 1 <= words[i].length, results.length <= 7
    /// 3. words[i], result contains only upper case English letters.
    /// 4. Number of different characters used on the expression is at most 10.
    /// </summary>
    bool isSolvable(vector<string>& words, string result);

    /// <summary>
    /// Leet code #1066. Campus Bikes II
    /// </summary>
    int assignBikesII(vector<vector<pair<int, int>>>& worker_distance, int worker,
        vector<int>& visited, int sum, unordered_map<int, int>& cache, int& result);

    /// <summary>
    /// Leet code #1066. Campus Bikes II
    /// 
    /// On a campus represented as a 2D grid, there are N workers and M bikes,
    /// with N <= M. Each worker and bike is a 2D coordinate on this grid.
    ///
    /// We assign one unique bike to each worker so that the sum of the 
    /// Manhattan distances between each worker and their assigned bike is 
    /// minimized.
    ///
    /// The Manhattan distance between two points p1 and p2 is 
    /// Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
    ///
    /// Return the minimum possible sum of Manhattan distances between each 
    /// worker and their assigned bike.
    ///
    /// Example 1:
    /// Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
    /// Output: 6
    /// Explanation: 
    /// We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan 
    /// distance of both assignments is 3, so the output is 6.
    ///
    /// Example 2:
    /// Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
    /// Output: 4
    /// Explanation: 
    /// We first assign bike 0 to worker 0, then assign bike 1 to worker 1 
    /// or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead 
    /// to sum of the Manhattan distances as 4.
    ///  
    /// Note:
    /// 1. 0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000
    /// 2. All worker and bike locations are distinct.
    /// 3. 1 <= workers.length <= bikes.length <= 10
    /// </summary>
    int assignBikesII(vector<vector<int>>& workers, vector<vector<int>>& bikes);

    /// <summary>
    /// Leet code #1349. Maximum Students Taking Exam
    /// </summary>
    int maxStudents(vector<vector<char>>& seats, int level, vector<vector<int>> &cache);

    /// <summary>
    /// Leet code #1349. Maximum Students Taking Exam
    ///
    /// Hard
    ///
    /// Given a m * n matrix seats  that represent seats distributions in a 
    /// classroom. If a seat is broken, it is denoted by '#' character 
    /// otherwise it is denoted by a '.' character.
    ///
    /// Students can see the answers of those sitting next to the left, right, 
    /// upper left and upper right, but he cannot see the answers of the 
    /// student sitting directly in front or behind him. Return the maximum 
    /// number of students that can take the exam together without any 
    /// cheating being possible..
    ///
    /// Students must be placed in seats in good condition.
    ///
    /// Example 1:
    /// Input: seats = [["#",".","#","#",".","#"],
    ///                 [".","#","#","#","#","."],
    ///                 ["#",".","#","#",".","#"]]
    /// Output: 4
    /// Explanation: Teacher can place 4 students in available seats so they 
    /// don't cheat on the exam.
    ///	
    /// Example 2:
    /// Input: seats = 
    /// [[".","#"],
    ///  ["#","#"],
    ///  ["#","."],
    ///  ["#","#"],
    ///  [".","#"]]
    /// Output: 3
    /// Explanation: Place all students in available seats. 
    ///
    /// Example 3:
    /// Input: seats = [["#",".",".",".","#"],
    ///                 [".","#",".","#","."],
    ///                 [".",".","#",".","."],
    ///                 [".","#",".","#","."],
    ///                 ["#",".",".",".","#"]]
    /// Output: 10
    /// Explanation: Place students in available seats in column 1, 3 and 5.
    ///
    /// Constraints:
    ///
    /// 1. seats contains only characters '.' and'#'.
    /// 2. m == seats.length
    /// 3. n == seats[i].length
    /// 4. 1 <= m <= 8
    /// 5. 1 <= n <= 8
    /// </summary>
    int maxStudents(vector<vector<char>>& seats);

    /// <summary>
    /// Leet code #212. Word Search II
    /// </summary>
    void wordSearchII(vector<vector<char>>& board, string& word, TrieNode * trie_node,
        int x, int y, unordered_set<string> &result);

    /// <summary>
    /// Leet code #212. Word Search II
    ///
    /// Given a 2D board and a list of words from the dictionary, find all 
    /// words in the board. 
    /// Each word must be constructed from letters of sequentially adjacent 
    /// cell, where "adjacent" cells are those horizontally or vertically 
    /// neighboring.
    /// The same letter cell may not be used more than once in a word.  
    ///
    /// For example,
    /// Given words = ["oath","pea","eat","rain"] and board = 
    /// [
    ///  ['o','a','a','n'],
    ///  ['e','t','a','e'],
    ///  ['i','h','k','r'],
    ///  ['i','f','l','v']
    /// ]
    /// Return ["eat","oath"]. 
    /// Note:
    /// You may assume that all inputs are consist of lowercase letters a-z. 
    /// </summary>
    vector<string> wordSearchII(vector<vector<char>>& board, vector<string>& words);

    /// <summary>
    /// Leet code #425. Word Squares
    /// </summary>
    void wordSquares(TrieNode *trie, vector<string>& wordSquare, vector<vector<string>>& result);

    /// <summary>
    /// Leet code #425. Word Squares
    ///
    /// Given a set of words (without duplicates), find all word squares you 
    /// can build from them.
    /// A sequence of words forms a valid word square if the kth row and column
    /// read the exact same string, where 0 ¡Ü k < max(numRows, numColumns).
    ///
    /// For example, the word sequence ["ball","area","lead","lady"] forms 
    /// a word square because each word reads the same both horizontally and 
    /// vertically.
    /// b a l l
    /// a r e a
    /// l e a d
    /// l a d y
    /// 
    /// Note:
    /// 1.There are at least 1 and at most 1000 words.
    /// 2.All words will have the exact same length.
    /// 3.Word length is at least 1 and at most 5.
    /// 4.Each word contains only lowercase English alphabet a-z.
    ///
    /// Example 1: 
    /// Input:
    /// ["area","lead","wall","lady","ball"]
    /// 
    /// Output:
    /// [
    ///   [ "wall",
    ///     "area",
    ///     "lead",
    ///     "lady"
    ///   ],
    ///   [ "ball",
    ///     "area",
    ///     "lead",
    ///     "lady"
    ///   ]
    /// ]
    ///
    /// Explanation:
    /// The output consists of two word squares. The order of output does not matter 
    /// (just the order of words in each word square matters).
    /// 
    /// Example 2: 
    /// Input:
    /// ["abat","baba","atan","atal"]
    ///
    /// Output:
    /// [
    ///   [ "baba",
    ///     "abat",
    ///     "baba",
    ///     "atan"
    ///   ],
    ///   [ "baba",
    ///     "abat",
    ///     "baba",
    ///     "atal"
    ///   ]
    /// ]
    ///
    /// Explanation:
    /// The output consists of two word squares. The order of output does not matter 
    /// (just the order of words in each word square matters).
    /// </summary>
    vector<vector<string>> wordSquares(vector<string>& words);

    /// <summary>
    /// Leet code #1397. Find All Good Strings
    /// </summary>
    int findGoodStrings(int index, string& s1, string& s2, string& evil,
        int pre_s1, int pre_s2, int pre_evil, vector<int> &kmp,
        vector<vector<vector<vector<int>>>> &cache);

    /// <summary>
    /// Leet code #1397. Find All Good Strings
    /// 
    /// Hard
    ///
    /// Given the strings s1 and s2 of size n, and the string evil. Return 
    /// the number of good strings.
    ///
    /// A good string has size n, it is alphabetically greater than or equal 
    /// to s1, it is alphabetically smaller than or equal to s2, and it does 
    /// not contain the string evil as a substring. Since the answer can be 
    /// a huge number, return this modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
    /// Output: 51 
    /// Explanation: There are 25 good strings starting with 'a': "aa","ac",
    /// "ad",...,"az". Then there are 25 good strings starting with 'c': 
    /// "ca","cc","cd",...,"cz" and finally there is one good string starting 
    /// with 'd': "da". 
    ///
    /// Example 2:
    /// Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
    /// Output: 0 
    /// Explanation: All strings greater than or equal to s1 and smaller than 
    /// or equal to s2 start with the prefix "leet", therefore, there is not 
    /// any good string.
    ///
    /// Example 3:
    /// Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
    /// Output: 2
    /// 
    /// Constraints:
    /// 1. s1.length == n
    /// 2. s2.length == n
    /// 3. 1 <= n <= 500
    /// 4. 1 <= evil.length <= 50
    /// 5. All strings consist of lowercase English letters.
    /// </summary>
    int findGoodStrings(int n, string s1, string s2, string evil);

    /// <summary>
    /// Leet code #679. 24 Game
    /// </summary>
    void getPoint24Rotation(vector<int>& nums, vector<int>& path, vector<bool>& visited, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #679. 24 Game
    /// </summary>
    bool calculatePoint24(vector<int>& nums);

    /// <summary>
    /// Leet code #679. 24 Game
    ///
    /// You have 4 cards each containing a number from 1 to 9. You need to 
    /// judge whether they could operated through *, /, +, -, (, ) to get 
    /// the value of 24.
    ///
    /// Example 1:
    /// Input: [4, 1, 8, 7]
    /// Output: True
    /// Explanation: (8-4) * (7-1) = 24
    /// Example 2:
    /// Input: [1, 2, 1, 2]
    /// Output: False
    /// Note:
    /// The division operator / represents real division, not integer 
    /// division. For example, 4 / (1 - 2/3) = 12.
    /// Every operation done is between two numbers. In particular, we cannot 
    /// use - as a unary operator. For example, with [1, 1, 1, 1] as input, 
    /// the expression -1 - 1 - 1 - 1 is not allowed.
    /// </summary>
    bool judgePoint24(vector<int>& nums);

    /// <summary>
    /// Leet code #422. Valid Word Square    
    /// 
    /// Given a sequence of words, check whether it forms a valid word square. 
    /// A sequence of words forms a valid word square if the kth row and column 
    /// read the exact same string, where 0 ¡Ü k < max(numRows, numColumns).
    /// Note:
    /// 1.The number of words given is at least 1 and does not exceed 500.
    /// 2.Word length will be at least 1 and does not exceed 500.
    /// 3.Each word contains only lowercase English alphabet a-z.
    /// Example 1: 
    /// Input:
    /// [
    ///  "abcd",
    ///  "bnrt",
    ///  "crmy",
    ///  "dtye"
    /// ]
    /// Output:
    /// true
    /// Explanation:
    /// The first row and first column both read "abcd".
    /// The second row and second column both read "bnrt".
    /// The third row and third column both read "crmy".
    /// The fourth row and fourth column both read "dtye".
    /// Therefore, it is a valid word square.
    ///
    /// Example 2: 
    /// Input:
    /// [
    ///  "abcd",
    ///  "bnrt",
    ///  "crm",
    ///  "dt"
    /// ]
    /// Output:
    /// true
    ///
    /// Explanation:
    /// The first row and first column both read "abcd".
    /// The second row and second column both read "bnrt".
    /// The third row and third column both read "crm".
    /// The fourth row and fourth column both read "dt".
    /// Therefore, it is a valid word square.
    /// Example 3: 
    /// Input:
    /// [
    ///  "ball",
    ///  "area",
    ///  "read",
    ///  "lady"
    /// ]
    ///
    /// Output:
    /// false
    /// Explanation:
    /// The third row reads "read" while the third column reads "lead".
    /// Therefore, it is NOT a valid word square.
    /// </summary>
    bool validWordSquare(vector<string>& words);

    /// <summary>
    /// Leet code #87. Scramble String 
    /// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively. 
    /// Below is one possible representation of s1 = "great": 
    ///      great
    ///     /    \
    ///    gr    eat
    ///   / \    /  \
    ///  g   r  e   at
    ///            / \
    ///           a   t
    ///
    /// To scramble the string, we may choose any non-leaf node and swap its two children. 
    /// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat". 
    ///      rgeat
    ///     /    \
    ///    rg    eat
    ///   / \    /  \
    ///  r   g  e   at
    ///            / \
    ///           a   t
    /// We say that "rgeat" is a scrambled string of "great". 
    /// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae". 
    ///      rgtae
    ///     /    \
    ///    rg    tae
    ///   / \    /  \
    ///  r   g  ta  e
    ///        / \
    ///       t   a
    /// We say that "rgtae" is a scrambled string of "great". 
    /// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
    /// </summary>
    bool isScramble(string s1, string s2);

    /// <summary>
    /// Leet code #1595. Minimum Cost to Connect Two Groups of Points
    /// </summary>
    int connectTwoGroups(vector<vector<int>>& cost, int index, vector<vector<int>>&cache, 
        int mask, vector<int>& min_s1, vector<int> &min_s2);

    /// <summary>
    /// Leet code #1595. Minimum Cost to Connect Two Groups of Points
    /// 
    /// Hard
    ///
    /// You are given two groups of points where the first group has size1 
    /// points, the second group has size2 points, and size1 >= size2.
    ///
    /// The cost of the connection between any two points are given in an 
    /// size1 x size2 matrix where cost[i][j] is the cost of connecting point i 
    /// of the first group and point j of the second group. The groups are 
    /// connected if each point in both groups is connected to one or more 
    /// points in the opposite group. In other words, each point in the first 
    /// group must be connected to at least one point in the second group, and 
    /// each point in the second group must be connected to at least one point 
    /// in the first group.
    ///
    /// Return the minimum cost it takes to connect the two groups.
    /// 
    /// Example 1:
    /// 
    /// Input: cost = [[15, 96], [36, 2]]
    /// Output: 17
    /// Explanation: The optimal way of connecting the groups is:
    /// 1--A
    /// 2--B
    /// This results in a total cost of 17.
    ///
    /// Example 2:
    /// Input: cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
    /// Output: 4
    /// Explanation: The optimal way of connecting the groups is:
    /// 1--A
    /// 2--B
    /// 2--C
    /// 3--A
    /// This results in a total cost of 4.
    /// Note that there are multiple points connected to point 2 in the first 
    /// group and point A in the second group. This does not matter as there 
    /// is no limit to the number of points that can be connected. We only 
    /// care about the minimum total cost.
    ///
    /// Example 3:
    ///
    /// Input: cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
    /// Output: 10
    ///
    /// Constraints:
    /// 1. size1 == cost.length
    /// 2. size2 == cost[i].length
    /// 3. 1 <= size1, size2 <= 12
    /// 4. size1 >= size2
    /// 5. 0 <= cost[i][j] <= 100
    /// </summary>
    int connectTwoGroups(vector<vector<int>>& cost);

    /// <summary>
    /// Leet code #1593. Split a String Into the Max Number of Unique 
    ///                  Substrings
    /// </summary>
    int maxUniqueSplit(string& s, vector<int> &dels, unordered_set<string>&set);

    /// <summary>
    /// Leet code #1593. Split a String Into the Max Number of Unique 
    ///                  Substrings
    /// 
    /// Medium
    ///
    /// Given a string s, return the maximum number of unique 
    /// substrings that the given string can be split into.
    ///
    /// You can split string s into any list of non-empty substrings, 
    /// where the concatenation of the substrings forms the original string. 
    /// However, you must split the substrings such that all of them are 
    /// unique.
    ///
    /// A substring is a contiguous sequence of characters within a string.
    /// 
    /// Example 1:
    /// Input: s = "ababccc"
    /// Output: 5
    /// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. 
    /// Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you 
    /// have 'a' and 'b' multiple times.
    ///
    /// Example 2:
    /// Input: s = "aba"
    /// Output: 2
    /// Explanation: One way to split maximally is ['a', 'ba'].
    ///
    /// Example 3:
    /// Input: s = "aa"
    /// Output: 1
    /// Explanation: It is impossible to split the string any further.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 16
    /// 2. s contains only lower case English letters.
    /// </summary>
    int maxUniqueSplit(string s);

    /// <summary>
    /// Leet code #1601. Maximum Number of Achievable Transfer Requests
    /// 
    /// Hard
    ///
    /// We have n buildings numbered from 0 to n - 1. Each building has a 
    /// number of employees. It's transfer season, and some employees want 
    /// to change the building they reside in.
    ///
    /// You are given an array requests where requests[i] = [from[i], to[i]] 
    /// represents an employee's request to transfer from building from[i] 
    /// to building to[i].
    ///
    /// All buildings are full, so a list of requests is achievable only if 
    /// for each building, the net change in employee transfers is zero. 
    /// This means the number of employees leaving is equal to the number 
    /// of employees moving in. For example if n = 3 and two employees are 
    /// leaving building 0, one is leaving building 1, and one is leaving 
    /// building 2, there should be two employees moving to building 0, one 
    /// employee moving to building 1, and one employee moving to building 2.
    ///
    /// Return the maximum number of achievable requests.
    ///
    /// Example 1:
    /// Input: n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
    /// Output: 5
    /// Explantion: Let's see the requests:
    /// From building 0 we have employees x and y and both want to move to 
    /// building 1.
    /// From building 1 we have employees a and b and they want to move to 
    /// buildings 2 and 0 respectively.
    /// From building 2 we have employee z and they want to move to building 0.
    /// From building 3 we have employee c and they want to move to building 4.
    /// From building 4 we don't have any requests.
    /// We can achieve the requests of users x and b by swapping their places.
    /// We can achieve the requests of users y, a and z by swapping the places 
    /// in the 3 buildings.
    ///
    /// Example 2:
    /// Input: n = 3, requests = [[0,0],[1,2],[2,1]]
    /// Output: 3
    /// Explantion: Let's see the requests:
    /// From building 0 we have employee x and they want to stay in the same 
    /// building 0.
    /// From building 1 we have employee y and they want to move to building 2.
    /// From building 2 we have employee z and they want to move to building 1.
    /// We can achieve all the requests. 
    ///
    /// Example 3:
    /// Input: n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
    /// Output: 4
    /// Constraints:
    /// 1. 1 <= n <= 20
    /// 2. 1 <= requests.length <= 16
    /// 3. requests[i].length == 2
    /// 4. 0 <= from[i], to[i] < n
    /// </summary>
    int maximumRequests(int n, vector<vector<int>>& requests);

    /// <summary>
    /// Leet code #1655. Distribute Repeating Integers
    /// </summary>
    bool canDistribute(vector<int>& nums, vector<int>& quantity, int index);

    /// <summary>
    /// Leet code #1655. Distribute Repeating Integers
    /// 
    /// Hard
    ///
    /// You are given an array of n integers, nums, where there are at most 50 
    /// unique values in the array. You are also given an array of m customer 
    /// order quantities, quantity, where quantity[i] is the amount of 
    /// integers the ith customer ordered. Determine if it is possible to 
    /// distribute nums such that:
    ///
    /// The ith customer gets exactly quantity[i] integers,
    /// The integers the ith customer gets are all equal, and
    /// Every customer is satisfied.
    /// Return true if it is possible to distribute nums according to the above 
    /// conditions.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,4], quantity = [2]
    /// Output: false
    /// Explanation: The 0th customer cannot be given two different integers.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,3], quantity = [2]
    /// Output: true
    /// Explanation: The 0th customer is given [3,3]. The integers [1,2] are 
    /// not used.
    ///
    /// Example 3:
    /// Input: nums = [1,1,2,2], quantity = [2,2]
    /// Output: true
    /// Explanation: The 0th customer is given [1,1], and the 1st customer is 
    /// given [2,2].
    ///
    /// Example 4:
    /// Input: nums = [1,1,2,3], quantity = [2,2]
    /// Output: false
    /// Explanation: Although the 0th customer could be given [1,1], the 1st 
    /// customer cannot be satisfied.
    ///
    /// Example 5:
    /// 
    /// Input: nums = [1,1,1,1,1], quantity = [2,3]
    /// Output: true
    /// Explanation: The 0th customer is given [1,1], and the 1st customer is 
    /// given [1,1,1].
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums[i] <= 1000
    /// 4. m == quantity.length
    /// 5. 1 <= m <= 10
    /// 6. 1 <= quantity[i] <= 10^5
    /// 7. There are at most 50 unique values in nums.
    /// </summary>
    bool canDistribute(vector<int>& nums, vector<int>& quantity);

    /// <summary>
    /// Leet code #1659. Maximize Grid Happiness
    /// </summary>
    int getMaxGridHappiness(int i, int j, vector<string>& grid);

    /// <summary>
    /// Leet code #1659. Maximize Grid Happiness
    /// </summary>
    int getMaxGridHappiness(int m, int n, int pos, int introvertsCount, 
        int extrovertsCount, int mask, vector<string> &grid, 
        vector<vector<vector<vector<int>>>>& cache);

    /// <summary>
    /// Leet code #1659. Maximize Grid Happiness
    /// 
    /// Hard
    ///
    /// You are given four integers, m, n, introvertsCount, and 
    /// extrovertsCount. You have an m x n grid, and there are two types 
    /// of people: introverts and extroverts. There are introvertsCount 
    /// introverts and extrovertsCount extroverts.
    ///
    /// You should decide how many people you want to live in the grid 
    /// and assign each of them one grid cell. Note that you do not have 
    /// to have all the people living in the grid.
    ///
    /// The happiness of each person is calculated as follows:
    ///
    /// Introverts start with 120 happiness and lose 30 happiness for each 
    /// neighbor (introvert or extrovert).
    /// Extroverts start with 40 happiness and gain 20 happiness for each 
    /// neighbor (introvert or extrovert).
    /// Neighbors live in the directly adjacent cells north, east, south, 
    /// and west of a person's cell.
    ///
    /// The grid happiness is the sum of each person's happiness. Return the 
    /// maximum possible grid happiness.
    ///
    /// Example 1:
    /// Input: m = 2, n = 3, introvertsCount = 1, extrovertsCount = 2
    /// Output: 240
    /// Explanation: Assume the grid is 1-indexed with coordinates 
    /// (row, column).
    /// We can put the introvert in cell (1,1) and put the extroverts in 
    /// cells (1,3) and (2,3).
    /// - Introvert at (1,1) happiness: 120 (starting happiness) - (0 * 30) 
    /// (0 neighbors) = 120
    /// - Extrovert at (1,3) happiness: 40 (starting happiness) + (1 * 20) 
    /// (1 neighbor) = 60
    /// - Extrovert at (2,3) happiness: 40 (starting happiness) + (1 * 20) 
    /// (1 neighbor) = 60
    /// The grid happiness is 120 + 60 + 60 = 240.
    /// The above figure shows the grid in this example with each person's 
    /// happiness. The introvert stays in the light green cell while the 
    /// extroverts live on the light purple cells.
    ///
    /// Example 2:
    /// Input: m = 3, n = 1, introvertsCount = 2, extrovertsCount = 1
    /// Output: 260
    /// Explanation: Place the two introverts in (1,1) and (3,1) and the 
    /// extrovert at (2,1).
    /// - Introvert at (1,1) happiness: 120 (starting happiness) - (1 * 30) 
    /// (1 neighbor) = 90
    /// - Extrovert at (2,1) happiness: 40 (starting happiness) + (2 * 20) 
    /// (2 neighbors) = 80
    /// - Introvert at (3,1) happiness: 120 (starting happiness) - (1 * 30) 
    /// (1 neighbor) = 90
    /// The grid happiness is 90 + 80 + 90 = 260.
    ///
    /// Example 3:
    /// Input: m = 2, n = 2, introvertsCount = 4, extrovertsCount = 0
    /// Output: 240
    /// 
    /// Constraints:
    /// 1. 1 <= m, n <= 5
    /// 2. 0 <= introvertsCount, extrovertsCount <= min(m * n, 6)
    /// </summary>
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount);


    /// <summary>
    /// Leet code #1681. Minimum Incompatibility
    /// </summary>
    int minimumIncompatibility(vector<int>& nums, int k, vector<int>&path, int bitmask,
        vector<int> &cache);

    /// <summary>
    /// Leet code #1681. Minimum Incompatibility
    /// 
    /// Hard
    /// 
    /// You are given an integer array nums and an integer k. You are asked 
    /// to distribute this array into k subsets of equal size such that there 
    /// are no two equal elements in the same subset.
    /// 
    /// A subset's incompatibility is the difference between the maximum and 
    /// minimum elements in that array.
    /// Return the minimum possible sum of incompatibilities of the k subsets 
    /// after distributing the array optimally, or return -1 if it is not 
    /// possible.
    /// A subset is a group integers that appear in the array with no 
    /// particular order.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,1,4], k = 2
    /// Output: 4
    /// Explanation: The optimal distribution of subsets is [1,2] and 
    /// [1,4].
    /// The incompatibility is (2-1) + (4-1) = 4.
    /// Note that [1,1] and [2,4] would result in a smaller sum, but the 
    /// first subset contains 2 equal elements.
    ///
    /// Example 2:
    /// Input: nums = [6,3,8,1,3,1,2,2], k = 4
    /// Output: 6
    /// Explanation: The optimal distribution of subsets is [1,2], [2,3], 
    /// [6,8], and [1,3].
    /// The incompatibility is (2-1) + (3-2) + (8-6) + (3-1) = 6.
    ///
    /// Example 3:
    /// Input: nums = [5,3,3,6,3,3], k = 3
    /// Output: -1
    /// Explanation: It is impossible to distribute nums into 3 subsets 
    /// where no two elements are equal in the same subset.
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 16
    /// 2. nums.length is divisible by k
    /// 3. 1 <= nums[i] <= nums.length
    /// </summary>
    int minimumIncompatibility(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #473. Matchsticks to Square  
    /// </summary>
    bool makesquare(vector<int>& nums, vector<int>& path, int bit_mask, int sum,
        int side_length, unordered_set<int>& cache);

    /// <summary>
    /// Leet code #473. Matchsticks to Square
    /// 
    /// Medium
    /// 
    /// Remember the story of Little Match Girl? By now, you know exactly what 
    /// matchsticks the little match girl has, please find out a way you can 
    /// make one square by using up all those matchsticks. You should not 
    /// break any stick, but you can link them up, and each matchstick must be 
    /// used exactly one time.
    ///
    /// Your input will be several matchsticks the girl has, represented with 
    /// their stick length. Your output will either be true or false, to 
    /// represent whether you could make one square using all the matchsticks 
    /// the little match girl has.
    /// 
    /// Example 1:
    /// Input: [1,1,2,2,2]
    /// Output: true
    ///
    /// Explanation: You can form a square with length 2, one side of the 
    /// square came two sticks with length 1.
    ///
    /// Example 2:
    /// Input: [3,3,3,3,4]
    /// Output: false
    /// Explanation: You cannot find a way to form a square with all the 
    /// matchsticks.
    ///
    /// Note:
    /// The length sum of the given matchsticks is in the range of 0 to 10^9.
    /// The length of the given matchstick array will not exceed 15.
    /// </summary>
    bool makesquare(vector<int>& nums);

    /// <summary>
    /// Leet code #1087. Brace Expansion
    /// </summary>
    void expand(string path, string S, vector<string>& result);

    /// <summary>
    /// Leet code #1087. Brace Expansion
    /// 
    /// A string S represents a list of words.
    ///
    /// Each letter in the word has 1 or more options.  If there is one 
    /// option, the letter is represented as is.  If there is more than 
    /// one option, then curly braces delimit the options.  For example, 
    /// "{a,b,c}" represents options ["a", "b", "c"].
    ///
    /// For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", 
    /// "bde", "bdf", "cde", "cdf"].
    ///
    /// Return all words that can be formed in this manner, in lexicographical 
    /// order.
    /// 
    /// Example 1:
    /// Input: "{a,b}c{d,e}f"
    /// Output: ["acdf","acef","bcdf","bcef"]
    ///
    /// Example 2:
    /// Input: "abcd"
    /// Output: ["abcd"]
    ///
    /// Note:
    ///
    /// 1. 1 <= S.length <= 50
    /// 2. There are no nested curly brackets.
    /// </summary>
    vector<string> expand(string S);

    /// <summary>
    /// Leet code #1140. Stone Game II
    /// </summary>
    int stoneGameII(vector<int>& sum, int start, int M, vector<vector<int>>& memo);

    /// <summary>
    /// Leet code #1140. Stone Game II
    /// 
    /// Alex and Lee continue their games with piles of stones.  There are a 
    /// number of piles arranged in a row, and each pile has a positive 
    /// integer number of stones piles[i].  The objective of the game is to 
    /// end with the most stones. 
    ///
    /// Alex and Lee take turns, with Alex starting first.  Initially, M = 1.
    ///
    /// On each player's turn, that player can take all the stones in the 
    /// first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
    ///
    /// The game continues until all the stones have been taken.
    ///
    /// Assuming Alex and Lee play optimally, return the maximum number of 
    /// stones Alex can get.
    ///
    /// Example 1:
    /// Input: piles = [2,7,9,4,4]
    /// Output: 10
    /// Explanation:  If Alex takes one pile at the beginning, Lee takes two 
    /// piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles 
    /// in total. If Alex takes two piles at the beginning, then Lee can take 
    /// all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. 
    /// So we return 10 since it's larger. 
    /// 
    /// Constraints:
    /// 1. 1 <= piles.length <= 100
    /// 2. 1 <= piles[i] <= 10 ^ 4
    /// </summary>
    int stoneGameII(vector<int>& piles);

    /// <summary>
    /// Leet code #1079. Letter Tile Possibilities
    /// </summary>
    int numTilePossibilities(string& word, string& tiles, vector<int>& visited);

    /// <summary>
    /// Leet code #1079. Letter Tile Possibilities
    /// 
    /// You have a set of tiles, where each tile has one letter tiles[i] printed 
    /// on it.  Return the number of possible non-empty sequences of letters you 
    /// can make.
    ///
    /// Example 1:
    /// Input: "AAB"
    /// Output: 8
    /// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", 
    /// "ABA", "BAA".
    ///
    /// Example 2:
    ///
    /// Input: "AAABBC"
    /// Output: 188
    /// Note:
    ///
    /// 1. 1 <= tiles.length <= 7
    /// 2. tiles consists of uppercase English letters.
    /// </summary>
    int numTilePossibilities(string tiles);

    /// <summary>
    /// Leet code #996. Number of Squareful Arrays
    /// </summary>
    int numSquarefulPerms(vector<int>& A, vector<int>& path, vector<int>& visited,
        int& result);

    /// <summary>
    /// Leet code #996. Number of Squareful Arrays
    /// 
    /// Given an array A of non-negative integers, the array is squareful if for 
    /// every pair of adjacent elements, their sum is a perfect square.
    ///
    /// Return the number of permutations of A that are squareful.  Two 
    /// permutations A1 and A2 differ if and only if there is some index i such 
    /// that A1[i] != A2[i].
    ///
    /// Example 1:
    ///
    /// Input: [1,17,8]
    /// Output: 2
    /// Explanation: 
    /// [1,8,17] and [17,8,1] are the valid permutations.
    ///
    /// Example 2:
    ///
    /// Input: [2,2,2]
    /// Output: 1
    ///
    ///
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 12
    /// 2. 0 <= A[i] <= 1e9
    /// 3. On a 2-dimensional grid, there are 4 types of squares:
    /// </summary>
    int numSquarefulPerms(vector<int>& A);

    /// <summary>
    /// Leet code #980. Unique Paths III
    /// </summary>
    void uniquePathsIII(vector<vector<int>>& grid, stack<pair<int, int>>& path,
        vector<vector<int>>& visited, int& remaining, int& result);

    /// <summary>
    /// Leet code #980. Unique Paths III
    /// 
    /// On a 2-dimensional grid, there are 4 types of squares:
    ///
    /// 1 represents the starting square.  There is exactly one starting square.
    /// 2 represents the ending square.  There is exactly one ending square.
    /// 0 represents empty squares we can walk over.
    /// -1 represents obstacles that we cannot walk over.
    /// Return the number of 4-directional walks from the starting square to the 
    /// ending square, that walk over every non-obstacle square exactly once.
    /// 
    /// Example 1:
    /// Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
    /// Output: 2
    /// Explanation: We have the following two paths: 
    /// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
    /// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
    ///
    /// Example 2:
    ///
    /// Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
    /// Output: 4
    /// Explanation: We have the following four paths: 
    /// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
    /// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
    /// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
    /// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
    ///
    /// Example 3:
    ///
    /// Input: [[0,1],[2,0]]
    /// Output: 0
    /// Explanation: 
    /// There is no path that walks over every empty square exactly once.
    /// Note that the starting and ending square can be anywhere in the grid.
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= grid.length * grid[0].length <= 20
    /// 2. Given a robot cleaner in a room modeled as a grid.
    /// </summary>
    int uniquePathsIII(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    void robotClean(vector<vector<int>>& room, int row, int col);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    bool robotMove(vector<vector<int>>& room, int& row, int& col, int direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    int robotTurnRight(int direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    int robotTurnLeft(int direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    void robotMoveNext(vector<vector<int>>& room, unordered_map<int, unordered_set<int>>& visited,
        int& row, int& col, int& direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    void robotMoveBack(vector<vector<int>>& room, unordered_map<int, unordered_set<int>>& visited,
        int& row, int& col, int& direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// 
    /// Given a robot cleaner in a room modeled as a grid.
    /// Each cell in the grid can be empty or blocked.
    ///
    /// The robot cleaner with 4 given APIs can move forward, turn left or turn 
    /// right. Each turn it made is 90 degrees.
    ///
    /// When it tries to move into a blocked cell, its bumper sensor detects 
    /// the obstacle and it stays on the current cell.
    ///
    /// Design an algorithm to clean the entire room using only the 4 given APIs 
    /// shown below.
    ///
    /// interface Robot {
    ///  // returns true if next cell is open and robot moves into the cell.
    ///  // returns false if next cell is obstacle and robot stays on the current 
    ///  // cell.
    ///  boolean move();
    ///
    ///  // Robot will stay on the same cell after calling turnLeft/turnRight.
    ///  // Each turn will be 90 degrees.
    ///  void turnLeft();
    ///  void turnRight();
    ///
    ///  // Clean the current cell.
    ///  void clean();
    /// }
    /// Example:
    ///
    /// Input:
    /// room = [
    ///  [1,1,1,1,1,0,1,1],
    ///  [1,1,1,1,1,0,1,1],
    ///  [1,0,1,1,1,1,1,1],
    ///  [0,0,0,1,0,0,0,0],
    ///  [1,1,1,1,1,1,1,1]
    /// ],
    /// row = 1,
    /// col = 3
    ///
    /// Explanation:
    /// All grids in the room are marked by either 0 or 1.
    /// 0 means the cell is blocked, while 1 means the cell is accessible.
    /// The robot initially starts at the position of row=1, col=3.
    /// From the top left corner, its position is one row below and three columns 
    /// right.
    /// Notes:
    ///
    /// The input is only given to initialize the room and the robot's position 
    /// internally. You must solve this problem "blindfolded". In other words, 
    /// you must control the robot using only the mentioned 4 APIs, without 
    /// knowing the room layout and the initial robot's position.
    /// The robot's initial position will always be in an accessible cell.
    /// The initial direction of the robot will be facing up.
    /// All accessible cells are connected, which means the all cells marked 
    /// as 1 will be accessible by the robot.
    /// Assume all four edges of the grid are all surrounded by wall.
    /// </summary>
    void cleanRoom(vector<vector<int>>& room, int row, int col);

    /// <summary>
    /// Leet code #856. Score of Parentheses
    /// </summary>
    int scoreOfParentheses(string S, int& index);

    /// <summary>
    /// Leet code #856. Score of Parentheses
    /// 
    /// Given a balanced parentheses string S, compute the score of the 
    /// string based on the following rule:
    ///
    /// () has score 1
    /// AB has score A + B, where A and B are balanced parentheses strings.
    /// (A) has score 2 * A, where A is a balanced parentheses string.
    /// 
    /// Example 1:
    ///
    /// Input: "()"
    /// Output: 1
    ///
    /// Example 2:
    /// Input: "(())"
    /// Output: 2
    ///
    /// Example 3:
    /// Input: "()()"
    /// Output: 2
    ///
    /// Example 4:
    /// Input: "(()(()))"
    /// Output: 6
    ///
    /// Note:
    /// 1. S is a balanced parentheses string, containing only ( and ).
    /// 2. 2 <= S.length <= 50
    /// </summary>
    int scoreOfParentheses(string S);

    /// <summary>
    /// Leet code #797. All Paths From Source to Target
    /// </summary>
    void allPathsSourceTarget(vector<vector<int>>& graph, vector<int>& path, unordered_set<int>& visited, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #797. All Paths From Source to Target
    /// 
    /// Given a directed, acyclic graph of N nodes.  Find all possible paths 
    /// from node 0 to node N-1, and return them in any order.
    ///
    /// The graph is given as follows:  the nodes are 0, 1, ..., 
    /// graph.length - 1.  graph[i] is a list of all nodes j for which the 
    /// edge (i, j) exists.
    ///
    /// Example:
    /// Input: [[1,2], [3], [3], []] 
    /// Output: [[0,1,3],[0,2,3]] 
    /// Explanation: The graph looks like this:
    /// 0--->1
    /// |    |
    /// v    v
    /// 2--->3
    /// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
    /// Note:
    ///
    /// 1. The number of nodes in the graph will be in the range [2, 15].
    /// 2. You can print different paths in any order, but you should keep the 
    ///    order of nodes inside one path.
    /// </summary>
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);

    /// <summary>
    /// Leetcode #784. Letter Case Permutation
    ///
    /// Given a string S, we can transform every letter individually to be 
    /// lowercase or uppercase to create another string.  Return a list of 
    /// all possible strings we could create.
    ///
    /// Examples:
    /// Input: S = "a1b2"
    /// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
    ///
    /// Input: S = "3z4"
    /// Output: ["3z4", "3Z4"]
    ///
    /// Input: S = "12345"
    /// Output: ["12345"]
    /// Note:
    ///
    /// 1. S will be a string with length at most 12.
    /// 2. S will consist only of letters or digits.
    /// </summary>
    vector<string> letterCasePermutation(string S);

    /// <summary>
    /// Leet code 1718. Construct the Lexicographically Largest Valid Sequence
    /// </summary>
    bool constructDistancedSequence(vector<int>& arr, int index, int bit_mask, int n);

    /// <summary>
    /// Leet code 1718. Construct the Lexicographically Largest Valid Sequence
    /// 
    /// Medium
    /// 
    /// Given an integer n, find a sequence that satisfies all of the 
    /// following:
    ///
    /// The integer 1 occurs once in the sequence.
    /// Each integer between 2 and n occurs twice in the sequence.
    /// For every integer i between 2 and n, the distance between the two 
    /// occurrences of i is exactly i.
    /// The distance between two numbers on the sequence, a[i] and a[j], is the 
    /// absolute difference of their indices, |j - i|.
    ///
    /// Return the lexicographically largest sequence. It is guaranteed that 
    /// under the given constraints, there is always a solution.
    ///
    /// A sequence a is lexicographically larger than a sequence b (of the 
    /// same length) if in the first position where a and b differ, sequence a 
    /// has a number greater than the corresponding number in b. For example, 
    /// [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first 
    /// position they differ is at the third number, and 9 is greater than 5.
    ///
    /// Example 1:
    /// Input: n = 3
    /// Output: [3,1,2,3,2]
    /// Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is 
    /// the lexicographically largest valid sequence.
    ///
    /// Example 2:
    /// Input: n = 5
    /// Output: [5,3,1,4,3,5,2,4,2]
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 20
    /// </summary>
    vector<int> constructDistancedSequence(int n);

    /// <summary>
    /// Leet code 1723. Find Minimum Time to Finish All Jobs
    /// </summary>
    void minimumTimeRequired(vector<int>& jobs, int index, vector<int>& workers, int max_time, int& result);

    /// <summary>
    /// Leet code 1723. Find Minimum Time to Finish All Jobs
    /// 
    /// Hard
    /// 
    /// You are given an integer array jobs, where jobs[i] is the amount of 
    /// time it takes to complete the ith job.
    ///
    /// There are k workers that you can assign jobs to. Each job should be 
    /// assigned to exactly one worker. The working time of a worker is the 
    /// sum of the time it takes to complete all jobs assigned to them. Your 
    /// goal is to devise an optimal assignment such that the maximum working 
    /// time of any worker is minimized.
    ///
    /// Return the minimum possible maximum working time of any assignment.
    /// 
    /// Example 1:
    /// Input: jobs = [3,2,3], k = 3
    /// Output: 3
    /// Explanation: By assigning each person one job, the maximum time is 3.
    ///
    /// Example 2:
    /// Input: jobs = [1,2,4,7,8], k = 2
    /// Output: 11
    /// Explanation: Assign the jobs the following way:
    /// Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
    /// Worker 2: 4, 7 (working time = 4 + 7 = 11)
    /// The maximum working time is 11.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= jobs.length <= 12
    /// 2. 1 <= jobs[i] <= 10^7
    /// </summary>
    int minimumTimeRequired(vector<int>& jobs, int k);

    /// <summary>
    /// Leet code 1728. Cat and Mouse II
    /// </summary>
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump, 
        vector<int> &cat, vector<int>& mouse, vector<vector<int>>&dirs,
        vector<int>& visited, int turn);

    /// <summary>
    /// Leet code 1728. Cat and Mouse II
    /// 
    /// Hard
    /// 
    /// A game is played by a cat and a mouse named Cat and Mouse.
    ///
    /// The environment is represented by a grid of size rows x cols, where 
    /// each element is a wall, floor, player (Cat, Mouse), or food. 
    ///
    /// Players are represented by the characters 'C'(Cat),'M'(Mouse).
    /// Floors are represented by the character '.' and can be walked on.
    /// Walls are represented by the character '#' and cannot be walked on.
    /// Food is represented by the character 'F' and can be walked on.
    /// There is only one of each character 'C', 'M', and 'F' in grid.
    /// Mouse and Cat play according to the following rules:
    ///
    /// Mouse moves first, then they take turns to move.
    /// During each turn, Cat and Mouse can jump in one of the four directions 
    /// (left, right, up, down). They cannot jump over the wall nor outside of 
    /// the grid.
    /// catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a 
    /// time, respectively. Cat and Mouse can jump less than the maximum 
    /// length.
    /// Staying in the same position is allowed.
    /// Mouse can jump over Cat.
    ///
    /// The game can end in 4 ways:
    /// 
    /// If Cat occupies the same position as Mouse, Cat wins.
    /// If Cat reaches the food first, Cat wins.
    /// If Mouse reaches the food first, Mouse wins.
    /// If Mouse cannot get to the food within 1000 turns, Cat wins.
    /// Given a rows x cols matrix grid and two integers catJump and mouseJump, 
    /// return true if Mouse can win the game if both Cat and Mouse play 
    /// optimally, otherwise return false.
    /// 
    /// Example 1:
    /// Input: grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
    /// Output: true
    /// Explanation: Cat cannot catch Mouse on its turn nor can it get the 
    /// food before Mouse.
    ///
    /// Example 2:
    /// Input: grid = ["M.C...F"], catJump = 1, mouseJump = 4
    /// Output: true
    ///
    /// Example 3:
    /// Input: grid = ["M.C...F"], catJump = 1, mouseJump = 3
    /// Output: false
    ///
    /// Example 4:
    /// Input: grid = ["C...#","...#F","....#","M...."], 
    /// catJump = 2, mouseJump = 5
    /// Output: false
    ///
    /// Example 5:
    /// Input: grid = [".M...","..#..","#..#.","C#.#.","...#F"], 
    /// catJump = 3, mouseJump = 1
    /// Output: true
    /// 
    /// Constraints:
    /// 1. rows == grid.length
    /// 2. cols = grid[i].length
    /// 3. 1 <= rows, cols <= 8
    /// 4. grid[i][j] consist only of characters 'C', 'M', 'F', '.', and '#'.
    /// 5. There is only one of each character 'C', 'M', and 'F' in grid.
    /// 6. 1 <= catJump, mouseJump <= 8
    /// </summary>
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump);

    /// <summary>
    /// Leet code 1770. Maximum Score from Performing Multiplication Operations
    /// </summary>
    int maximumScore(vector<int>& nums, vector<int>& multipliers, int left, int right, vector<vector<int>> &dp);

    /// <summary>
    /// Leet code 1770. Maximum Score from Performing Multiplication Operations
    /// 
    /// Medium
    /// 
    /// You are given two integer arrays nums and multipliers of size n and m 
    /// respectively, where n >= m. The arrays are 1-indexed.
    ///
    /// You begin with a score of 0. You want to perform exactly m operations. 
    /// On the ith operation (1-indexed), you will:
    ///
    /// Choose one integer x from either the start or the end of the array nums.
    /// Add multipliers[i] * x to your score.
    /// Remove x from the array nums.
    /// Return the maximum score after performing m operations.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3], multipliers = [3,2,1]
    /// Output: 14
    /// Explanation: An optimal solution is as follows:
    /// - Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
    /// - Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
    /// - Choose from the end, [1], adding 1 * 1 = 1 to the score.
    /// The total score is 9 + 4 + 1 = 14.
    ///
    /// Example 2:
    /// Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
    /// Output: 102
    /// Explanation: An optimal solution is as follows:
    /// - Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to 
    /// the score.
    /// - Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to 
    /// the score.
    /// - Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
    /// - Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
    /// - Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
    /// The total score is 50 + 15 - 9 + 4 + 42 = 102.
    /// Constraints:
    /// 1. n == nums.length
    /// 2. m == multipliers.length
    /// 3. 1 <= m <= 10^3
    /// 4. m <= n <= 10^5
    /// 5. -1000 <= nums[i], multipliers[i] <= 1000
    /// </summary>
    int maximumScore(vector<int>& nums, vector<int>& multipliers);

    /// <summary>
    /// Leet code 1799. Maximize Score After N Operations
    /// </summary>
    int maxScore(vector<int>& nums, int bitmask, vector<int>&cache);

    /// <summary>
    /// Leet code 1799. Maximize Score After N Operations
    /// 
    /// Hard
    /// 
    /// You are given nums, an array of positive integers of size 2 * n. You 
    /// must perform n operations on this array.
    ///
    /// In the ith operation (1-indexed), you will:
    ///
    /// Choose two elements, x and y.
    /// Receive a score of i * gcd(x, y).
    /// Remove x and y from nums.
    /// Return the maximum score you can receive after performing n operations.
    ///
    /// The function gcd(x, y) is the greatest common divisor of x and y.
    ///
    /// Example 1:
    /// Input: nums = [1,2]
    /// Output: 1
    /// Explanation: The optimal choice of operations is:
    /// (1 * gcd(1, 2)) = 1
    ///
    /// Example 2:
    /// Input: nums = [3,4,6,8]
    /// Output: 11
    /// Explanation: The optimal choice of operations is:
    /// (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
    ///
    /// Example 3:
    /// Input: nums = [1,2,3,4,5,6]
    /// Output: 14
    /// Explanation: The optimal choice of operations is:
    /// (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
    ///
    /// Constraints:
    /// 1. 1 <= n <= 7
    /// 2. nums.length == 2 * n
    /// 3. 1 <= nums[i] <= 10^6
    /// </summary>
    int maxScore(vector<int>& nums);

    /// <summary>
    /// Leet code 1766. Tree of Coprimes 
    /// </summary>
    void getCoprimes(vector<int>& nums, int node, unordered_map<int, unordered_set<int>>& tree, 
        unordered_map<int, vector<int>>& primes, vector<int>& visited,
        unordered_map<int, list<pair<int, int>>>& ancestors, vector<int> &result, int level);

    /// <summary>
    /// Leet code 1766. Tree of Coprimes 
    /// 
    /// Hard
    /// 
    /// There is a tree (i.e., a connected, undirected graph that has no 
    /// cycles) consisting of n nodes numbered from 0 to n - 1 and exactly 
    /// n - 1 edges. Each node has a value associated with it, and the root 
    /// of the tree is node 0.
    ///
    /// To represent this tree, you are given an integer array nums and a 2D 
    /// array edges. Each nums[i] represents the ith node's value, and each 
    /// edges[j] = [uj, vj] represents an edge between nodes uj and vj in the 
    /// tree.
    ///
    /// Two values x and y are coprime if gcd(x, y) == 1 where gcd(x, y) 
    /// is the greatest common divisor of x and y.
    ///
    /// An ancestor of a node i is any other node on the shortest path from 
    /// node i to the root. A node is not considered an ancestor of itself.
    ///
    /// Return an array ans of size n, where ans[i] is the closest ancestor 
    /// to node i such that nums[i] and nums[ans[i]] are coprime, or -1 if 
    /// there is no such ancestor.
    ///
    /// Example 1:
    /// Input: nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
    /// Output: [-1,0,0,1]
    /// Explanation: In the above figure, each node's value is in parentheses.
    /// - Node 0 has no coprime ancestors.
    /// - Node 1 has only one ancestor, node 0. Their values are coprime 
    ///   (gcd(2,3) == 1).
    /// - Node 2 has two ancestors, nodes 1 and 0. Node 1's value is not 
    ///   coprime (gcd(3,3) == 3), but node 0's
    ///   value is (gcd(2,3) == 1), so node 0 is the closest valid ancestor.
    /// - Node 3 has two ancestors, nodes 1 and 0. It is coprime with node 1 
    ///  (gcd(3,2) == 1), so node 1 is its
    ///  closest valid ancestor.
    ///
    /// Example 2:
    /// Input: nums = [5,6,10,2,3,6,15], 
    /// edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
    /// Output: [-1,0,-1,0,0,0,-1]
    ///
    /// Constraints:
    /// 1. nums.length == n
    /// 2. 1 <= nums[i] <= 50
    /// 3. 1 <= n <= 10^5
    /// 4. edges.length == n - 1
    /// 5. edges[j].length == 2
    /// 6. 0 <= uj, vj < n
    /// 7. uj != vj
    /// </summary>
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges);


    /// <summary>
    /// Leet code 1815. Maximum Number of Groups Getting Fresh Donuts
    /// </summary>
    int maxHappyGroups(int batchSize, int left, vector<int>& groups, int visited, unordered_map<int, int> &cache);

    /// <summary>
    /// Leet code 1815. Maximum Number of Groups Getting Fresh Donuts
    /// 
    /// Hard
    /// 
    /// There is a donuts shop that bakes donuts in batches of batchSize. 
    /// They have a rule where they must serve all of the donuts of a batch 
    /// before serving any donuts of the next batch. You are given an integer 
    /// batchSize and an integer array groups, where groups[i] denotes that 
    /// there is a group of groups[i] customers that will visit the shop. 
    /// Each customer will get exactly one donut.
    ///
    /// When a group visits the shop, all customers of the group must be 
    /// served before serving any of the following groups. A group will be 
    /// happy if they all get fresh donuts. That is, the first customer of 
    /// the group does not receive a donut that was left over from the 
    /// previous group.
    ///
    /// You can freely rearrange the ordering of the groups. Return the 
    /// maximum possible number of happy groups after rearranging the groups.
    ///
    /// Example 1:
    /// Input: batchSize = 3, groups = [1,2,3,4,5,6] 
    /// Output: 4
    /// Explanation: You can arrange the groups as [6,2,4,5,1,3]. Then 
    /// the 1st, 2nd, 4th, and 6th groups will be happy.
    ///
    /// Example 2:
    /// Input: batchSize = 4, groups = [1,3,2,5,2,2,1,6]
    /// Output: 4
    ///
    /// Constraints:
    /// 1. 1 <= batchSize <= 9
    /// 2. 1 <= groups.length <= 30
    /// 3. 1 <= groups[i] <= 10^9
    /// </summary>
    int maxHappyGroups(int batchSize, vector<int>& groups);

    /// <summary>
    /// Leet code 1849. Splitting a String Into Descending Consecutive Values
    /// </summary>
    bool splitString(string& s, int start_pos, long long last_num);

    /// <summary>
    /// Leet code 1849. Splitting a String Into Descending Consecutive Values
    /// 
    /// Medium
    /// 
    /// You are given a string s that consists of only digits.
    ///
    /// Check if we can split s into two or more non-empty substrings such that 
    /// the numerical values of the substrings are in descending order and the 
    /// difference between numerical values of every two adjacent substrings 
    /// is equal to 1.
    ///
    /// For example, the string s = "0090089" can be split into ["0090", "089"]
    /// with numerical values [90,89]. The values are in descending order and 
    /// adjacent values differ by 1, so this way is valid.
    /// Another example, the string s = "001" can be split into ["0", "01"], 
    /// ["00", "1"], or ["0", "0", "1"]. However all the ways are invalid 
    /// because they have numerical values [0,1], [0,1], and [0,0,1] 
    /// respectively, all of which are not in descending order.
    ///
    /// Return true if it is possible to split s as described above, or 
    /// false otherwise.
    ///
    /// A substring is a contiguous sequence of characters in a string.
    /// 
    /// Example 1:
    /// Input: s = "1234"
    /// Output: false
    /// Explanation: There is no valid way to split s.
    /// Example 2:
    ///
    /// Input: s = "050043"
    /// Output: true
    /// Explanation: s can be split into ["05", "004", "3"] with numerical 
    /// values [5,4,3].
    /// The values are in descending order with adjacent values differing by 1.
    ///
    /// Example 3:
    /// Input: s = "9080701"
    /// Output: false
    /// Explanation: There is no valid way to split s.
    ///
    /// Example 4:
    /// Input: s = "10009998"
    /// Output: true
    /// Explanation: s can be split into ["100", "099", "98"] with numerical 
    /// values [100,99,98].
    /// The values are in descending order with adjacent values differing by 1.
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 20
    /// 2. s only consists of digits.
    /// </summary>
    bool splitString(string s);

    /// <summary>
    /// Leet code 1879. Minimum XOR Sum of Two Arrays 
    /// </summary>
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2,
        int index, int bitmask, vector<int>& cache);

    /// <summary>
    /// Leet code 1879. Minimum XOR Sum of Two Arrays 
    /// 
    /// Hard
    /// 
    /// You are given two integer arrays nums1 and nums2 of length n.
    ///
    /// The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + 
    /// (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) 
    /// (0-indexed).
    ///
    /// For example, the XOR sum of [1,2,3] and [3,2,1] is equal to 
    /// (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
    /// Rearrange the elements of nums2 such that the resulting XOR sum 
    /// is minimized.
    ///
    /// Return the XOR sum after the rearrangement.
    ///
    /// Example 1:
    /// Input: nums1 = [1,2], nums2 = [2,3]
    /// Output: 2
    /// Explanation: Rearrange nums2 so that it becomes [3,2].
    /// The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.
    ///
    /// Example 2:
    /// Input: nums1 = [1,0,3], nums2 = [5,3,4]
    /// Output: 8
    /// Explanation: Rearrange nums2 so that it becomes [5,4,3]. 
    /// The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.
    /// 
    /// Constraints:
    /// 1. n == nums1.length
    /// 2. n == nums2.length
    /// 3. 1 <= n <= 14
    /// 4. 0 <= nums1[i], nums2[i] <= 10^7
    /// </summary>
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet code 1900. The Earliest and Latest Rounds Where Players Compete
    /// </summary>
    void earliestAndLatest(int bitmask, int i, int j, int n, int first, int second, int round, vector<int> &result);

    /// <summary>
    /// Leet code 1900. The Earliest and Latest Rounds Where Players Compete
    /// 
    /// Hard
    /// 
    /// There is a tournament where n players are participating. The players 
    /// are standing in a single row and are numbered from 1 to n based on 
    /// their initial standing position (player 1 is the first player in the 
    /// row, player 2 is the second player in the row, etc.).
    ///
    /// The tournament consists of multiple rounds (starting from round 
    /// number 1). In each round, the ith player from the front of the row 
    /// competes against the ith player from the end of the row, and the 
    /// winner advances to the next round. When the number of players is 
    /// odd for the current round, the player in the middle automatically 
    /// advances to the next round.
    ///
    /// For example, if the row consists of players 1, 2, 4, 6, 7 
    /// Player 1 competes against player 7.
    /// Player 2 competes against player 6.
    /// Player 4 automatically advances to the next round.
    /// After each round is over, the winners are lined back up in the row 
    /// based on the original ordering assigned to them initially (ascending 
    /// order).
    ///
    /// The players numbered firstPlayer and secondPlayer are the best in 
    /// the tournament. They can win against any other player before they 
    /// compete against each other. If any two other players compete against 
    /// each other, either of them might win, and thus you may choose the 
    /// outcome of this round.
    ///
    /// Given the integers n, firstPlayer, and secondPlayer, return an 
    /// integer array containing two values, the earliest possible round 
    /// number and the latest possible round number in which these two players 
    /// will compete against each other, respectively.
    ///
    /// Example 1:
    /// Input: n = 11, firstPlayer = 2, secondPlayer = 4
    /// Output: [3,4]
    /// Explanation:
    /// One possible scenario which leads to the earliest round number:
    /// First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    /// Second round: 2, 3, 4, 5, 6, 11
    /// Third round: 2, 3, 4
    /// One possible scenario which leads to the latest round number:
    /// First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    /// Second round: 1, 2, 3, 4, 5, 6
    /// Third round: 1, 2, 4
    /// Fourth round: 2, 4
    ///
    /// Example 2:
    /// Input: n = 5, firstPlayer = 1, secondPlayer = 5
    /// Output: [1,1]
    /// Explanation: The players numbered 1 and 5 compete in the first round.
    /// There is no way to make them compete in any other round.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 28
    /// 2. 1 <= firstPlayer < secondPlayer <= n
    /// </summary>
    vector<int> earliestAndLatest(int n, int first, int second);

    /// <summary>
    /// Leet code 1931. Painting a Grid With Three Different Colors
    /// </summary>
    int colorTheGrid(int i, int j, int m, int n, int value, vector<vector<int>>& grid, vector<vector<int>> &cache);

    /// <summary>
    /// Leet code 1931. Painting a Grid With Three Different Colors
    ///                                  
    /// Hard
    /// 
    /// You are given two integers m and n. Consider an m x n grid where each 
    /// cell is initially white. You can paint each cell red, green, or blue. 
    /// All cells must be painted.
    ///
    /// Return the number of ways to color the grid with no two adjacent 
    /// cells having the same color. Since the answer can be very large, 
    /// return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: m = 1, n = 1
    /// Output: 3
    /// Explanation: The three possible colorings are shown in the image above.
    ///
    /// Example 2:
    ///
    /// Input: m = 1, n = 2
    /// Output: 6
    /// Explanation: The six possible colorings are shown in the image above.
    ///
    /// Example 3:
    /// Input: m = 5, n = 5
    /// Output: 580986
    /// 
    /// Constraints:
    /// 1 <= m <= 5
    /// 1 <= n <= 1000
    /// </summary>
    int colorTheGrid(int m, int n);

    /// <summary>
    /// Leet code 2003. Smallest Missing Genetic Value in Each Subtree
    /// </summary>
    void smallestMissingValueSubtree(vector<vector<int>>& children, vector<int>& seen, vector<int>& visited,
        vector<int>& nums, int pos);


    /// <summary>
    /// Leet code 2003. Smallest Missing Genetic Value in Each Subtree
    ///                                                
    /// Hard
    /// 
    /// There is a family tree rooted at 0 consisting of n nodes numbered 0 to 
    /// n - 1. You are given a 0-indexed integer array parents, where 
    /// parents[i] is the parent for node i. Since node 0 is the root, 
    /// parents[0] == -1.
    ///
    /// There are 105 genetic values, each represented by an integer in the 
    /// inclusive range [1, 105]. You are given a 0-indexed integer array nums, 
    /// where nums[i] is a distinct genetic value for node i.
    ///
    /// Return an array ans of length n where ans[i] is the smallest genetic 
    /// value that is missing from the subtree rooted at node i.
    ///
    /// The subtree rooted at a node x contains node x and all of its 
    /// descendant nodes.
    ///
    /// Example 1:
    /// Input: parents = [-1,0,0,2], nums = [1,2,3,4]
    /// Output: [5,1,1,1]
    /// Explanation: The answer for each subtree is calculated as follows:
    /// - 0: The subtree contains nodes [0,1,2,3] with values [1,2,3,4]. 5 is 
    /// the smallest missing value.
    /// - 1: The subtree contains only node 1 with value 2. 1 is the smallest 
    /// missing value.
    /// - 2: The subtree contains nodes [2,3] with values [3,4]. 1 is the 
    /// smallest missing value.
    /// - 3: The subtree contains only node 3 with value 4. 1 is the smallest 
    /// missing value.
    ///
    /// Example 2:
    /// Input: parents = [-1,0,1,0,3,3], nums = [5,4,6,2,1,3]
    /// Output: [7,1,1,4,2,1]
    /// Explanation: The answer for each subtree is calculated as follows:
    /// - 0: The subtree contains nodes [0,1,2,3,4,5] with values 
    /// [5,4,6,2,1,3]. 7 is the smallest missing value.
    /// - 1: The subtree contains nodes [1,2] with values [4,6]. 1 is the 
    /// smallest missing value.
    /// - 2: The subtree contains only node 2 with value 6. 1 is the smallest 
    /// missing value.
    /// - 3: The subtree contains nodes [3,4,5] with values [2,1,3]. 4 is the 
    /// smallest missing value.
    /// - 4: The subtree contains only node 4 with value 1. 2 is the smallest 
    /// missing value.
    /// - 5: The subtree contains only node 5 with value 3. 1 is the smallest 
    /// missing value.
    ///
    /// Example 3:
    /// Input: parents = [-1,2,3,0,2,4,1], nums = [2,3,4,5,6,7,8]
    /// Output: [1,1,1,1,1,1,1]
    /// Explanation: The value 1 is missing from all the subtrees.
    ///
    /// Constraints:
    /// 1. n == parents.length == nums.length
    /// 2. 2 <= n <= 10^5
    /// 3. 0 <= parents[i] <= n - 1 for i != 0
    /// 4. parents[0] == -1
    /// 5. parents represents a valid tree.
    /// 6. 1 <= nums[i] <= 10^5
    /// 7. Each nums[i] is distinct.
    /// </summary>
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums);

    /// <summary>
    /// Leet code 2060. Check if an Original String Exists Given Two 
    ///                 Encoded Strings
    /// </summary>
    bool possiblyEquals(string& s1, string& s2, int i, int j, int d, int n, unordered_set<int>& seen);


    /// <summary>
    /// Leet code 2060. Check if an Original String Exists Given Two 
    ///                 Encoded Strings
    ///                                                
    /// Hard
    /// 
    /// An original string, consisting of lowercase English letters, can be 
    /// encoded by the following steps:
    ///
    /// Arbitrarily split it into a sequence of some number of non-empty 
    /// substrings.
    /// Arbitrarily choose some elements (possibly none) of the sequence, 
    /// and replace each with its length (as a numeric string).
    /// Concatenate the sequence as the encoded string.
    /// For example, one way to encode an original string "abcdefghijklmnop" 
    /// might be:
    ///
    /// Split it as a sequence: ["ab", "cdefghijklmn", "o", "p"].
    /// Choose the second and third elements to be replaced by their lengths, 
    /// respectively. The sequence becomes ["ab", "12", "1", "p"].
    /// Concatenate the elements of the sequence to get the encoded 
    /// string: "ab121p".
    /// Given two encoded strings s1 and s2, consisting of lowercase English 
    /// letters and digits 1-9 (inclusive), return true if there exists an 
    /// original string that could be encoded as both s1 and s2. Otherwise, 
    /// return false.
    ///
    /// Note: The test cases are generated such that the number of consecutive 
    /// digits in s1 and s2 does not exceed 3.
    /// 
    /// Example 1:
    ///
    /// Input: s1 = "internationalization", s2 = "i18n"
    /// Output: true
    /// Explanation: It is possible that "internationalization" was the 
    /// original string.
    /// - "internationalization" 
    ///  -> Split:       ["internationalization"]
    ///  -> Do not replace any element
    ///  -> Concatenate:  "internationalization", which is s1.
    /// - "internationalization"
    ///  -> Split:       ["i", "nternationalizatio", "n"]
    ///  -> Replace:     ["i", "18",                 "n"]
    ///  -> Concatenate:  "i18n", which is s2
    ///
    /// Example 2:
    /// Input: s1 = "l123e", s2 = "44"
    /// Output: true
    /// Explanation: It is possible that "leetcode" was the original string.
    /// - "leetcode" 
    ///   -> Split:     ["l", "e", "et", "cod", "e"] 
    ///   -> Replace:    ["l", "1", "2",  "3",   "e"]
    ///   -> Concatenate: "l123e", which is s1.
    /// - "leetcode" 
    ///   -> Split:      ["leet", "code"]
    ///  -> Replace:    ["4",    "4"]
    ///  -> Concatenate: "44", which is s2.
    ///
    /// Example 3:
    /// Input: s1 = "a5b", s2 = "c5b"
    /// Output: false
    /// Explanation: It is impossible.
    /// - The original string encoded as s1 must start with the letter 'a'.
    /// - The original string encoded as s2 must start with the letter 'c'.
    ///
    /// Example 4:
    /// Input: s1 = "112s", s2 = "g841"
    /// Output: true
    /// Explanation: It is possible that "gaaaaaaaaaaaas" was the original 
    /// string
    /// - "gaaaaaaaaaaaas"
    ///  -> Split:      ["g", "aaaaaaaaaaaa", "s"]
    ///  -> Replace:    ["1", "12",           "s"]
    ///  -> Concatenate: "112s", which is s1.
    /// - "gaaaaaaaaaaaas"
    ///   -> Split:      ["g", "aaaaaaaa", "aaaa", "s"]
    ///  -> Replace:    ["g", "8",        "4",    "1"]
    ///   -> Concatenate: "g841", which is s2.
    ///
    /// Example 5:
    ///
    /// Input: s1 = "ab", s2 = "a2"
    /// Output: false
    /// Explanation: It is impossible.
    /// - The original string encoded as s1 has two letters.
    /// - The original string encoded as s2 has three letters.
    ///
    /// Constraints:
    /// 1. 1 <= s1.length, s2.length <= 40
    /// 2. s1 and s2 consist of digits 1-9 (inclusive), and lowercase 
    ///    English letters only.
    /// 3. The number of consecutive digits in s1 and s2 does not exceed 3.
    /// </summary>
    bool possiblyEquals(string s1, string s2);

    /// <summary>
    /// Leet code 1994. The Number of Good Subsets
    /// </summary>
    long long numberOfGoodSubsets(vector<int>& dp, size_t index, int bit_mask, vector<int> &bit_masks, 
        long long count, long long& result);


    /// <summary>
    /// Leet code 1994. The Number of Good Subsets
    ///                                                                 
    /// Hard
    /// 
    /// You are given an integer array nums. We call a subset of nums good 
    /// if its product can be represented as a product of one or more 
    /// distinct prime numbers.
    /// 
    /// For example, if nums = [1, 2, 3, 4]:
    /// [2, 3], [1, 2, 3], and [1, 3] are good subsets with products 6 = 2*3, 
    /// 6 = 2*3, and 3 = 3 respectively.
    /// [1, 4] and [4] are not good subsets with products 4 = 2*2 and 
    /// 4 = 2*2 respectively.
    /// Return the number of different good subsets in nums modulo 10^9 + 7.
    ///
    /// A subset of nums is any array that can be obtained by deleting some 
    /// (possibly none or all) elements from nums. Two subsets are different 
    /// if and only if the chosen indices to delete are different.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3,4]
    /// Output: 6
    /// Explanation: The good subsets are:
    /// - [1,2]: product is 2, which is the product of distinct prime 2.
    /// - [1,2,3]: product is 6, which is the product of distinct primes 2 
    ///   and 3.
    /// - [1,3]: product is 3, which is the product of distinct prime 3.
    /// - [2]: product is 2, which is the product of distinct prime 2.
    /// - [2,3]: product is 6, which is the product of distinct primes 2 and 3.
    /// - [3]: product is 3, which is the product of distinct prime 3.
    ///
    /// Example 2:
    /// Input: nums = [4,2,3,15]
    /// Output: 5
    /// Explanation: The good subsets are:
    /// - [2]: product is 2, which is the product of distinct prime 2.
    /// - [2,3]: product is 6, which is the product of distinct primes 2 and 3.
    /// - [2,15]: product is 30, which is the product of distinct primes 2, 3, 
    ///   and 5.
    /// - [3]: product is 3, which is the product of distinct prime 3.
    /// - [15]: product is 15, which is the product of distinct primes 3 and 5.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 30
    /// </summary>
    int numberOfGoodSubsets(vector<int>& nums);
#pragma endregion
};

#endif  // LeetCodeDFS_H
