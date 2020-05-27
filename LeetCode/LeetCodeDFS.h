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

#pragma endregion
};

#endif  // LeetCodeDFS_H
