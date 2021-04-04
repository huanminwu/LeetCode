#pragma once
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
#include "LeetCodeDFS.h"
#include "LeetCodeMath.h"


#pragma region BackTracking

/// <summary>
/// Leet code #37. Sudoku Solver
/// </summary>
bool LeetCodeDFS::solveSudoku(
    vector<vector<char>>& board, vector<vector<int>> &row_visited,
    vector<vector<int>> &col_visited, vector<vector<int>> &square_visited,
    int r, int c)
{
    // find a empty cell,
    while (r < 9 && c < 9)
    {
        if (board[r][c] == '.')
        {
            break;
        }
        c++;
        if (c == 9)
        {
            c = 0;
            r++;
        }
    }
    // we fill all teh cells, it is solution
    if (r == 9) return true;

    // calculate which square
    int s = r / 3  * 3 + c / 3;
    for (int v = 0; v < 9; v++)
    {
        // if number conflict, skip it
        if ((row_visited[r][v] != 0) || (col_visited[c][v] != 0) || (square_visited[s][v] != 0))
        {
            continue;
        }
        
        row_visited[r][v] = 1;
        col_visited[c][v] = 1;
        square_visited[s][v] = 1;
        board[r][c] = (char)v + '1';
        
        // if solution found return true and finish search
        if (solveSudoku(board, row_visited, col_visited, square_visited, r, c))
        {
            return true;
        }
        // otherwise search fail, we revert current choice
        else
        {
            row_visited[r][v] = 0;
            col_visited[c][v] = 0;
            square_visited[s][v] = 0;
            board[r][c] = '.';
        }
    }
    return false;
}

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
void LeetCodeDFS::solveSudoku(vector<vector<char>>&  board)
{
    vector<vector<int>> row_visited(9, vector<int>(9));
    vector<vector<int>> col_visited(9, vector<int>(9));
    vector<vector<int>> square_visited(9, vector<int>(9));
    // set initial state
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (board[r][c] != '.')
            {
                // calculate which square
                int s = r / 3 * 3 + c / 3;
                row_visited[r][board[r][c] - '1'] = 1;
                col_visited[c][board[r][c] - '1'] = 1;
                square_visited[s][board[r][c] - '1'] = 1;
            }
        }
    }
    solveSudoku(board, row_visited, col_visited, square_visited, 0, 0);
 }

/// <summary>
/// Leet code # 51. N-Queens 
/// </summary>
void LeetCodeDFS::solveNQueens(vector<string> &board, int row, 
    vector<int> &columns, vector<int>&diag, vector<vector<string>> &result)
{
    size_t n = board.size();
    if (row == n)
    {
        result.push_back(board);
        return;
    }
    for (size_t col = 0; col < n; col++)
    {
        if ((columns[col] == 1) || (diag[row + col] == 1) ||
            (diag[row - col + 3 * n] == 1))
        {
            continue;
        }
        board[row][col] = 'Q';
        columns[col] = 1;
        diag[row + col] = 1;
        diag[row - col + 3 * n] = 1;
        solveNQueens(board, row + 1, columns, diag, result);
        board[row][col] = '.';
        columns[col] = 0;
        diag[row + col] = 0;
        diag[row - col + 3 * n] = 0;
    }
}


/// <summary>
/// Leet code # 51. N-Queens 
/// 
/// The n-queens puzzle is the problem of placing n queens on an n×n 
/// chessboard such that no two queens attack each other. 
/// Given an integer n, return all distinct solutions to the n-queens puzzle.
///	
/// Each solution contains a distinct board configuration of the n-queens' 
/// placement, where 'Q' and '.' 
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
vector<vector<string>> LeetCodeDFS::solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<int> columns(n);
    vector<int>diag(4 * n);
    vector<vector<string>> result;
    solveNQueens(board, 0, columns, diag, result);
    return result;
}

/// <summary>
/// Leet code # 52. N-Queens II 
/// </summary>
void LeetCodeDFS::totalNQueens(int n, int row, vector<int> &columns, vector<int>&diag, int &count)
{
    if (row == n)
    {
        count++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if ((columns[col] == 1) || (diag[row + col] == 1) ||
            (diag[row - col + 3 * n] == 1))
        {
            continue;
        }
        columns[col] = 1;
        diag[row + col] = 1;
        diag[row - col + 3 * n] = 1;
        totalNQueens(n, row + 1, columns, diag, count);
        columns[col] = 0;
        diag[row + col] = 0;
        diag[row - col + 3 * n] = 0;
    }
}

/// <summary>
/// Leet code # 52. N-Queens II 
/// 
/// Follow up for N-Queens problem. 
/// Now, instead outputting board configurations, return the total number of distinct solutions.
/// </summary>
int LeetCodeDFS::totalNQueens(int n)
{
    vector<int> columns(n);
    vector<int>diag(4 * n);
    int result = 0;
    totalNQueens(n, 0, columns, diag, result);
    return result;
}

/// <summary>
/// Leet code #17. Letter Combinations of a Phone Number 
/// </summary>
void LeetCodeDFS::letterCombinations(string& digits, string &path, 
    unordered_map<char, string>& phone_keyboard, vector<string> &result)
{
    if (path.size() == digits.size())
    {
        if (!path.empty()) result.push_back(path);
        return;
    }
    char digit = digits[path.size()];
    string target_str = phone_keyboard[digit];
    for (char ch : target_str)
    {
        path.push_back(ch);
        letterCombinations(digits, path, phone_keyboard, result);
        path.pop_back();
    }
}

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
vector<string> LeetCodeDFS::letterCombinations(string digits)
{
    unordered_map<char, string> phone_keyboard =
    {
        { '2', "abc" },{ '3', "def" },{ '4', "ghi" },{ '5', "jkl" },
        { '6', "mno" },{ '7', "pqrs" },{ '8', "tuv" },{ '9', "wxyz" },
        { '*', "+" }
    };
    string path;
    vector<string> result;
    letterCombinations(digits, path, phone_keyboard, result);
    return result;
}

/// <summary>
/// Leet code #22. Generate Parentheses 
/// </summary>
void LeetCodeDFS::generateParenthesis(string &path, int n, int left, 
    int right, vector<string> &result)
{
    if (path.size() == 2 * n)
    {
        result.push_back(path);
        return;
    }
    for (size_t i = 0; i < 2; i++)
    {
        if ((i == 0) && (left >= n)) continue;
        if ((i == 1) && (left <= right)) continue;
        if (i == 0)
        {
            left++;
            path.push_back('(');
        }
        else
        {
            right++;
            path.push_back(')');
        }
        generateParenthesis(path, n, left, right, result);
        if (i == 0) left--;
        else right--;
        path.pop_back();
    }
}

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
vector<string> LeetCodeDFS::generateParenthesis(int n)
{
    vector<string> result;
    string path;
    int left = 0, right = 0;
    generateParenthesis(path, n, left, right, result);
    return result;
}

/// <summary>
/// Leet code #39. Combination Sum
/// </summary>
void LeetCodeDFS::combinationSum(vector<int>& candidates, int target, int index, 
    vector<int>& path, vector<vector<int>>&result)
{
    if (target == 0)
    {
        if (!path.empty()) result.push_back(path);
        return;
    }

    for (size_t i = index; i < candidates.size(); i++)
    {
        if (candidates[i] > target) break;
        target -= candidates[i];
        path.push_back(candidates[i]);
        combinationSum(candidates, target, i, path, result);
        target += candidates[i];
        path.pop_back();
    }
}

/// <summary>
/// Leet code #39. Combination Sum
/// Given a set of candidate numbers (C) and a target number (T), find all 
/// unique combinations in C where the candidate numbers sums to T. 
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
vector<vector<int>> LeetCodeDFS::combinationSum(vector<int>& candidates, int target)
{
    vector<int> path;
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, target, 0, path, result);
    return result;
}

/// <summary>
/// Leet code #40. Combination Sum II
/// </summary>
void LeetCodeDFS::combinationSum2(vector<int>& candidates, int target, int index, 
    vector<int>& path, vector<vector<int>>&result)
{
    if (target == 0)
    {
        if (!path.empty()) result.push_back(path);
        return;
    }

    for (size_t i = index; i < candidates.size(); i++)
    {
        if (candidates[i] > target) break;
        if ((i > (size_t)index) && (candidates[i] == candidates[i - 1])) continue;
        target -= candidates[i];
        path.push_back(candidates[i]);
        combinationSum2(candidates, target, i + 1, path, result);
        target += candidates[i];
        path.pop_back();
    }
}

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
vector<vector<int>> LeetCodeDFS::combinationSum2(vector<int>& candidates, 
    int target)
{
    vector<int> path;
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    combinationSum2(candidates, target, 0, path, result);
    return result;
}

/// <summary>
/// Leet code #77. Combinations
/// </summary>
void LeetCodeDFS::combine(int n, int k, vector<int>& path, 
    vector<vector<int>>&result)
{
    if (path.size() == k)
    {
        result.push_back(path);
        return;
    }
    int index = 0;
    if (!path.empty()) index = path.back();
    for (int i = index + 1; i <= n; i++)
    {
        path.push_back(i);
        combine(n, k, path, result);
        path.pop_back();
    }
}

/// <summary>
/// Leet code #77. Combinations 
/// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. 
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
vector<vector<int>> LeetCodeDFS::combine(int n, int k)
{
    vector<vector<int>> result;
    vector<int> path;
    combine(n, k, path, result);
    return result;
}

/// <summary>
/// Leet code #46. Permutations 
/// </summary>
void LeetCodeDFS::permute(vector<int>& nums, vector<int>&path,
    vector<int>&visited, vector<vector<int>> &result)
{
    if (path.size() == nums.size())
    {
        result.push_back(path);
        return;
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        path.push_back(nums[i]);
        permute(nums, path, visited, result);
        path.pop_back();
        visited[i] = 0;
    }
}

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
vector<vector<int>> LeetCodeDFS::permute(vector<int>& nums)
{
    vector<int> visited(nums.size());
    vector<int> path;
    vector<vector<int>> result;
    permute(nums, path, visited, result);
    return result;
}

/// <summary>
/// Leet code #47. Permutations II 
/// </summary>
void LeetCodeDFS::permuteUnique(vector<int>& nums, vector<int>&path,
    vector<int>&visited, vector<vector<int>> &result)
{
    if (path.size() == nums.size())
    {
        result.push_back(path);
        return;
    }
    unordered_set<int> visited_set;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (visited[i] == 1) continue;
        if (visited_set.count(nums[i]) > 0) continue;
        visited_set.insert(nums[i]);
        visited[i] = 1;
        path.push_back(nums[i]);
        permuteUnique(nums, path, visited, result);
        path.pop_back();
        visited[i] = 0;
    }
}

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
vector<vector<int>> LeetCodeDFS::permuteUnique(vector<int>& nums)
{
    vector<int> visited(nums.size());
    vector<int> path;
    vector<vector<int>> result;
    permuteUnique(nums, path, visited, result);
    return result;
}

/// <summary>
/// Leet code #329. Longest Increasing Path in a Matrix
/// </summary>
int LeetCodeDFS::longestIncreasingPath(vector<vector<int>>& matrix,
    vector<vector<int>>& path, vector<vector<int>>& directions,
    int i, int j)
{
    if (path[i][j] > 0) return path[i][j];
    path[i][j] = 1;
    for (size_t d = 0; d < directions.size(); d++)
    {
        int r = i + directions[d][0];
        int c = j + directions[d][1];
        if (r < 0 || r >= (int)matrix.size() || c < 0 || c >= (int)matrix[0].size())
        {
            continue;
        }
        if (matrix[r][c] > matrix[i][j])
        {
            path[i][j] = max(path[i][j], 1 + longestIncreasingPath(matrix, path, directions, r, c));
        }
    }
    return path[i][j];
}

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
int LeetCodeDFS::longestIncreasingPath(vector<vector<int>>& matrix)
{
    int result = 0;
    if (matrix.empty()) return result;
    vector<vector<int>> path(matrix.size(), vector<int>(matrix[0].size()));
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            result = max(result, longestIncreasingPath(matrix, path, directions, i, j));
        }
    }
    return result;
}

/// <summary>
/// Get word ladder path  
/// </summary>
vector<vector<string>> LeetCodeDFS::findWordLadderPath(string beginWord, string endWord,
    unordered_map<string, unordered_set<string>>& word_map)
{
    vector<vector<string>> result;
    vector<pair<string, unordered_set<string>::iterator>> word_stack;
    word_stack.push_back(make_pair(endWord, word_map[endWord].begin()));
    while (!word_stack.empty())
    {
        pair<string, unordered_set<string>::iterator> pair = word_stack.back();
        if (pair.first != beginWord)
        {
            if (pair.second != word_map[pair.first].end())
            {
                string word = *pair.second;
                word_stack.push_back(make_pair(word, word_map[word].begin()));
                continue;
            }
        }
        else
        {
            vector<string> one_result;
            for (size_t i = 0; i < word_stack.size(); i++)
            {
                one_result.push_back(word_stack[word_stack.size() - 1 - i].first);
            }
            result.push_back(one_result);
        }
        word_stack.pop_back();
        if (!word_stack.empty())
        {
            pair = word_stack.back();
            word_stack.pop_back();
            pair.second++;
            word_stack.push_back(pair);
        }
    }
    return result;
}

/// <summary>
/// Leet code #126. Word Ladder II  
/// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest 
/// transformation sequence from beginWord to endWord, such that: 
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
vector<vector<string>> LeetCodeDFS::findLadders(string beginWord, string endWord,
    unordered_set<string> &wordList)
{
    unordered_map<string, unordered_set<string>> word_map;
    unordered_set<string> visited_word;
    wordList.insert(endWord);
    int step = 1;
    bool end = false;
    queue<string> word_search;
    word_search.push(beginWord);
    wordList.erase(beginWord);
    while (!word_search.empty())
    {
        size_t size = word_search.size();
        for (size_t i = 0; i < size; i++)
        {
            string word = word_search.front();
            word_search.pop();
            if (word == endWord)
            {
                end = true;
                continue;
            }
            for (size_t j = 0; j < word.size(); j++)
            {
                string original_word = word;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[j] = ch;
                    if (wordList.find(word) != wordList.end())
                    {
                        word_map[word].insert(original_word);
                        word_search.push(word);
                        visited_word.insert(word);
                    }
                }
                word = original_word;
            }
        }
        if (end == true) break;
        for (string word : visited_word)
        {
            wordList.erase(word);
        }
        visited_word.clear();
        step++;
    }
    return findWordLadderPath(beginWord, endWord, word_map);
}

/// <summary>
/// Leet code #401. Binary Watch  
/// </summary> 
void LeetCodeDFS::readBinaryWatch(int num, vector<int>&path, int sum, vector<string> &result)
{
    vector<int> time_metrics = { 1, 2, 4, 8, 16, 32, 100, 200, 400, 800 };

    if (path.size() == num)
    {
        string time = to_string(sum / 100);
        time.append(":");
        sum = sum % 100;
        if (sum < 10) time.append("0");
        time.append(to_string(sum));
        result.push_back(time);
        return;
    }

    int start = path.empty() ? 0 : path.back() + 1;
    for (size_t i = start; i < time_metrics.size(); i++)
    {
        sum += time_metrics[i];
        path.push_back(i);
        if ((sum % 100 < 60) && (sum / 100 < 12))
        {
            readBinaryWatch(num, path, sum, result);
        }
        path.pop_back();
        sum -= time_metrics[i];
    }
}

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
vector<string> LeetCodeDFS::readBinaryWatch(int num)
{
    vector<string> result;
    vector<int> path;
    int sum = 0;
    readBinaryWatch(num, path, sum, result);
    return result;
}

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
vector<string> LeetCodeDFS::readBinaryWatchII(int num)
{
    vector<int> time_metrics = { 1, 2, 4, 8, 16, 32, 100, 200, 400, 800 };
    vector<int> search_stack;
    vector<string> result;
    size_t index = 0;
    while (true)
    {
        if ((int)search_stack.size() < num)
        {
            if (index < time_metrics.size())
            {
                search_stack.push_back(index);
                index++;
                continue;
            }
        }
        else
        {
            int sum = 0;
            for (size_t i = 0; i < search_stack.size(); i++)
            {
                sum += time_metrics[search_stack[i]];
            }
            if ((sum % 100 < 60) && (sum / 100 < 12))
            {
                string time = to_string(sum / 100);
                time.append(":");
                sum = sum % 100;
                if (sum < 10) time.append("0");
                time.append(to_string(sum));
                result.push_back(time);
            }
        }
        // either we just get a result or we search out of boundary
        if (search_stack.empty())
        {
            break;
        }
        else
        {
            index = search_stack.back() + 1;
            search_stack.pop_back();
        }
    }
    return result;
}

/// <summary>
/// Leet code #78. Subsets
/// </summary>
void LeetCodeDFS::subsets(vector<int>& nums, int index, vector<int>& path, 
    vector<vector<int>> &result)
{
    result.push_back(path);
    for (size_t i = index; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        subsets(nums, i + 1, path, result);
        path.pop_back();
    }
}

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
vector<vector<int>> LeetCodeDFS::subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> path;
    subsets(nums, 0, path, result);
    return result;
}

/// <summary>
/// Leet code #90. Subsets II
/// </summary>
void LeetCodeDFS::subsetsWithDup(vector<int>& nums, int index, vector<int>& path, 
    vector<vector<int>> &result)
{
    result.push_back(path);
    for (size_t i = index; i < nums.size(); i++)
    {
        if ((i >(size_t)index) && (nums[i] == nums[i - 1])) continue;
        path.push_back(nums[i]);
        subsetsWithDup(nums, i + 1, path, result);
        path.pop_back();
    }
}

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
vector<vector<int>> LeetCodeDFS::subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> path;
    sort(nums.begin(), nums.end());
    subsetsWithDup(nums, 0, path, result);
    return result;
}

/// <summary>
/// Leet code #79. Word Search
/// </summary>
bool LeetCodeDFS::wordSearch(vector<vector<char>>& board, 
    vector<vector<bool>>& flag, string word, int x, int y, int pos)
{
    if (pos == word.size()) return true;
    if ((x < 0) || (x == board.size()) || (y < 0) || (y == board[0].size()))
    {
        return false;
    }
    if (board[x][y] != word[pos])
    {
        return false;
    }
    if (flag[x][y] == true) return false;
    bool found = false;
    flag[x][y] = true;
    if (wordSearch(board, flag, word, x - 1, y, pos + 1) ||
        wordSearch(board, flag, word, x + 1, y, pos + 1) ||
        wordSearch(board, flag, word, x, y - 1, pos + 1) ||
        wordSearch(board, flag, word, x, y + 1, pos + 1))
    {
        found = true;
    }
    flag[x][y] = false;
    return found;
}

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
bool LeetCodeDFS::wordSearch(vector<vector<char>>& board, string word)
{
    vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size()));
    for (size_t x = 0; x < board.size(); x++)
    {
        for (size_t y = 0; y < board[0].size(); y++)
        {
            if (wordSearch(board, flag, word, x, y, 0))
            {
                return true;
            }
        }
    }
    return false;
}

/// <summary>
/// Leet code #212. Word Search II
/// </summary>
void LeetCodeDFS::wordSearchII(vector<vector<char>>& board, string& word,
    TrieNode * trie_node, int x, int y, unordered_set<string> &result)
{
    if (x < 0 || x >= (int)board.size() || y < 0 || y >= (int)board[0].size())
    {
        return;
    }
    if (board[x][y] == '#') return;
    char c = board[x][y];
    trie_node = (TrieNode *)trie_node->next(board[x][y]);
    if (trie_node == nullptr)
    {
        return;
    }
    board[x][y] = '#';
    word.push_back(c);
    if (trie_node->is_end) result.insert(word);
    wordSearchII(board, word, trie_node, x - 1, y, result);
    wordSearchII(board, word, trie_node, x + 1, y, result);
    wordSearchII(board, word, trie_node, x, y - 1, result);
    wordSearchII(board, word, trie_node, x, y + 1, result);
    board[x][y] = c;
    word.pop_back();
}

/// <summary>
/// Leet code #212. Word Search II  
///
/// Given a 2D board and a list of words from the dictionary, find all words 
/// in the board.
/// Each word must be constructed from letters of sequentially adjacent cell, 
/// where "adjacent" cells are 
/// those horizontally or vertically neighboring. The same letter cell may not 
/// be used more than once in a word.
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
vector<string> LeetCodeDFS::wordSearchII(vector<vector<char>>& board, vector<string>& words)
{
    unordered_set<string> result;
    TrieNode * root = new TrieNode();

    for (string word : words)
    {
        root->insert(word, 0);
    }

    for (size_t x = 0; x < board.size(); x++)
    {
        for (size_t y = 0; y < board[0].size(); y++)
        {
            string word;
            wordSearchII(board, word, root, x, y, result);
        }
    }
    delete root;
    return vector<string>(result.begin(), result.end());
}

/// <summary>
/// LeetCode #93. Restore IP Addresses
///
/// Restore IP address by split into specified segment
/// </summary>
vector<string> LeetCodeDFS::restoreIpAddresses(string s, size_t segments)
{
    vector<string> result;
    if ((s.size() < segments) || (s.size() > segments * 3))
    {
        return result;
    }

    for (size_t i = 1; i < 4; i++)
    {
        if (i > s.size()) break;
        string word = s.substr(0, i);
        if ((word[0] == '0') && (word.size() != 1)) break;
        int number = atoi(word.c_str());
        if (number <= 255)
        {
            if ((segments == 1) && (i == s.size()))
            {
                result.push_back(s);
            }
            else
            {
                vector<string> sub_address_list = restoreIpAddresses(s.substr(i), segments - 1);
                for (string sub_address : sub_address_list)
                {
                    result.push_back(word + "." + sub_address);
                }
            }
        }
    }
    return result;
}

/// <summary>
/// LeetCode #93. Restore IP Addresses  
///
/// Given a string containing only digits, restore it by returning all 
/// possible valid IP address combinations. 
/// For example:
/// Given "25525511135", 
/// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
/// </summary>
vector<string> LeetCodeDFS::restoreIpAddresses(string s)
{
    return restoreIpAddresses(s, 4);
}

/// <summary>
/// Palindrome Partitioning with cache
/// </summary>
vector<vector<string>> LeetCodeDFS::partitionPalindrome(string s, unordered_map<string, vector<vector<string>>> &partition)
{
    if (partition.find(s) != partition.end())
    {
        return partition[s];
    }
    vector<vector<string>> result;

    for (size_t i = 0; i < s.size(); i++)
    {
        string substring = s.substr(0, i + 1);
        if (substring == string(substring.rbegin(), substring.rend()))
        {
            if (i + 1 == s.size())
            {
                result.push_back(vector<string>({ substring }));
            }
            else
            {
                vector<vector<string>> sub_result = partitionPalindrome(s.substr(i + 1), partition);
                for (vector<string> one_result : sub_result)
                {
                    one_result.insert(one_result.begin(), substring);
                    result.push_back(one_result);
                }
            }
        }
    }
    partition[s] = result;
    return result;
}

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
vector<vector<string>> LeetCodeDFS::partitionPalindrome(string s)
{
    unordered_map<string, vector<vector<string>>> partition;
    return partitionPalindrome(s, partition);
}

/// <summary>
/// Leet code #464. Can I Win
/// </summary>
bool LeetCodeDFS::canIWin(int maxChoosableInteger, int desiredTotal, 
    int signature, unordered_map<int, bool> &game_map)
{
    if (game_map.count(signature) > 0)
    {
        return game_map[signature];
    }
    for (int i = maxChoosableInteger; i > 0; i--)
    {
        int bit = (1 << (i - 1));
        if ((signature & bit) == 0)
        {
            desiredTotal = desiredTotal - i;
            if ((desiredTotal <= 0) || 
                !canIWin(maxChoosableInteger, desiredTotal, signature | bit, game_map))
            {
                game_map[signature] = true;
                return true;
            }
            desiredTotal = desiredTotal + i;
        }
    }
    game_map[signature] = false;
    return false;
}

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
bool LeetCodeDFS::canIWin(int maxChoosableInteger, int desiredTotal)
{
    unordered_map<int, bool> game_map;
    int signature = 0;

    // No one can win
    if ((1 + maxChoosableInteger) * maxChoosableInteger < desiredTotal * 2)
    {
        return false;
    }
    return canIWin(maxChoosableInteger, desiredTotal, signature, game_map);
}


/// <summary>
/// Leet code #416. Partition Equal Subset Sum
/// </summary>
bool LeetCodeDFS::canPartition(vector<int>& nums, size_t start, int sum)
{
    for (size_t i = start; i < nums.size(); i++)
    {
        if (nums[i] > sum) return false;
        if (nums[i] == sum) return true;
        if (i > start && nums[i] == nums[i - 1]) continue;
        if (canPartition(nums, i + 1, sum - nums[i]))
        {
            return true;
        }
    }
    return false;
}

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
bool LeetCodeDFS::canPartition(vector<int>& nums)
{
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum % 2 == 1) return false;
    sum = sum / 2;
    sort(nums.begin(), nums.end());
    return canPartition(nums, 0, sum);
}

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
vector<int> LeetCodeDFS::diffWaysToCompute(string input)
{
    vector<int> result;
    for (size_t i = 0; i <= input.size(); i++)
    {
        if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*'))
        {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            for (size_t j = 0; j < left.size(); j++)
            {
                for (size_t k = 0; k < right.size(); k++)
                {
                    if (input[i] == '+') result.push_back(left[j] + right[k]);
                    else if (input[i] == '-') result.push_back(left[j] - right[k]);
                    else if (input[i] == '*') result.push_back(left[j] * right[k]);
                }
            }
        }
    }
    if (result.empty())
    {
        result.push_back(atoi(input.c_str()));
    }
    return result;
}

/// <summary>
/// Leet code #282. Expression Add Operators
/// </summary>
void LeetCode::calculate(vector<string> & result, string path, string num, long long target, long long eval, long long product)
{
    if (num.empty())
    {
        if (eval == target) result.push_back(path);
        return;
    }
    for (size_t i = 0; i < num.size(); i++)
    {
        string cur_string = num.substr(0, i + 1);
        if ((cur_string.size() > 1) && (cur_string[0] == '0')) continue;
        long long cur_value = atol(cur_string.substr(0, i + 1).c_str());
        if (path.empty())
        {
            calculate(result, cur_string, num.substr(i + 1), target, cur_value, cur_value);
        }
        else
        {
            calculate(result, path + "+" + cur_string, num.substr(i + 1), target, eval + cur_value, cur_value);
            calculate(result, path + "-" + cur_string, num.substr(i + 1), target, eval - cur_value, -cur_value);
            calculate(result, path + "*" + cur_string, num.substr(i + 1), target, eval - product + product*cur_value, product*cur_value);
        }
    }
}

/// <summary>
/// Leet code #282. Expression Add Operators
///
/// Given a string that contains only digits 0-9 and a target value, return all possibilities to 
/// add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value. 
/// 
/// Examples:  
/// "123", 6 -> ["1+2+3", "1*2*3"] 
/// "232", 8 -> ["2*3+2", "2+3*2"]
/// "105", 5 -> ["1*0+5","10-5"]
/// "00", 0 -> ["0+0", "0-0", "0*0"]
/// "3456237490", 9191 -> []
/// </summary>
vector<string> LeetCode::addOperators(string num, int target)
{
    vector<string> result;
    unordered_map<string, unordered_map<string, int>> cache;
    if (num.empty()) return result;

    calculate(result, "", num, target, 0, 1);
    return result;
}

/// <summary>
/// Leet code #216. Combination Sum III 
/// </summary>
vector<vector<int>> LeetCodeDFS::combinationSum3(int k, int n, int start)
{
    vector<vector<int>> result;
    if (k == 0)
    {
        if (n == 0)
        {
            result.push_back(vector<int>());
        }
    }
    else
    {
        for (size_t i = start; i < 10; i++)
        {
            if ((size_t)n < i) break;
            vector<vector<int>> sub_result = combinationSum3(k - 1, n - i, i + 1);
            for (vector<int> one_result : sub_result)
            {
                one_result.push_back(i);
                result.push_back(one_result);
            }
        }
    }
    return result;
}

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
vector<vector<int>> LeetCodeDFS::combinationSum3(int k, int n)
{
    return combinationSum3(k, n, 1);
}

/// <summary>
/// Leet code #301. Remove Invalid Parentheses 
/// </summary>
void LeetCode::removeInvalidParentheses(
    string s, vector<char> p, int scan, int remove, vector<string> &result)
{
    int count = 0;
    for (size_t i = scan; i < s.size(); i++)
    {
        if (s[i] == p[0]) count++;
        else if (s[i] == p[1]) count--;
        if (count >= 0) continue;
        for (size_t j = remove; j <= i; j++)
        {
            if ((s[j] == p[1]) && ((j == remove) || s[j] != s[j - 1]))
            {
                removeInvalidParentheses(s.substr(0, j) + s.substr(j + 1), p, i, j, result);
            }
        }
        return;
    }
    std::reverse(s.begin(), s.end());
    if (p[0] == '(')
    {
        swap(p[0], p[1]);
        removeInvalidParentheses(s, p, 0, 0, result);
    }
    else
    {
        result.push_back(s);
    }
}

/// <summary>
/// Leet code #301. Remove Invalid Parentheses 
/// 
/// Remove the minimum number of invalid parentheses in order to make 
/// the input string valid. Return all possible results.
/// Note: The input string may contain letters other than the parentheses ( and ). 
/// Examples:
/// "()())()" -> ["()()()", "(())()"]
/// "(a)())()" -> ["(a)()()", "(a())()"]
/// ")(" -> [""]
/// </summary>
vector<string> LeetCode::removeInvalidParentheses(string s)
{
    vector<string> result;
    vector<char> p = { '(', ')' };
    removeInvalidParentheses(s, p, 0, 0, result);
    return result;
}

/// <summary>
/// Leet code #254. Factor Combinations    
/// </summary>
void LeetCode::getFactors(int n, vector<int> factors, vector<vector<int>> &result)
{
    int start = 2;
    if (!factors.empty()) start = factors.back();
    for (int i = start; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            getFactors(n / i, factors, result);
            factors.pop_back();
        }
    }
    factors.push_back(n);
    if (factors.size() != 1) result.push_back(factors);
}

/// <summary>
/// Leet code #254. Factor Combinations    
/// 
/// Numbers can be regarded as product of its factors. For example, 
/// 8 = 2 x 2 x 2; = 2 x 4.
/// Write a function that takes an integer n and return all possible combinations of its factors. 
/// Note: 
/// 1.You may assume that n is always positive. 
/// 2.Factors should be greater than 1 and less than n.
/// </summary>
vector<vector<int>> LeetCode::getFactors(int n)
{
    vector<vector<int>>  result;
    vector<int> factors;
    getFactors(n, factors, result);
    return result;
}

/// <summary>
/// Leet code #320. Generalized Abbreviation  
/// </summary>
vector<string> LeetCode::generateAbbreviations(string word,
    unordered_map<string, vector<string>> &cache)
{
    vector<string> result;
    if (word.empty())
    {
        result.push_back("");
        return result;
    }
    if (cache.count(word) != 0) return cache[word];
    result.push_back(to_string(word.size()));
    for (size_t i = 0; i < word.size(); i++)
    {
        string left_str = i == 0 ? "" : to_string(i);
        string right_string = word.substr(i + 1);
        vector<string> right_abbr = generateAbbreviations(right_string, cache);
        for (string right_str : right_abbr)
        {
            string str = left_str;
            str.push_back(word[i]);
            str.append(right_str);
            result.push_back(str);
        }
    }
    cache[word] = result;
    return result;
}

/// <summary>
/// Leet code #320. Generalized Abbreviation  
/// 
/// Write a function to generate the generalized abbreviations of a word.
/// Example:
/// Given word = "word", return the following list (order does not matter):
/// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", 
///  "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
/// </summary>
vector<string> LeetCode::generateAbbreviations(string word)
{
    vector<string> result;
    unordered_map<string, vector<string>> cache;
    result = generateAbbreviations(word, cache);
    return result;
}

/// <summary>
/// Leet code #320. Generalized Abbreviation  
/// 
/// Write a function to generate the generalized abbreviations of a word.
/// Example:
/// Given word = "word", return the following list (order does not matter):
/// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", 
///  "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
/// </summary>
vector<string> LeetCode::generateAbbreviationsII(string word)
{
    vector<string> result;
    if (word.empty())
    {
        result.push_back("");
        return result;
    }
    size_t max_bit = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        max_bit = (max_bit << 1) + 1;
    }
    for (size_t i = 0; i < max_bit + 1; i++)
    {
        string str;
        size_t bit = 1;
        bit <<= (word.size() - 1);
        int count = 0;
        for (size_t j = 0; j < word.size(); j++)
        {
            if ((i & bit) == bit)
            {
                count++;
            }
            else
            {
                if (count != 0)
                {
                    str.append(to_string(count));
                    count = 0;
                }
                str.push_back(word[j]);
            }
            bit = bit >> 1;
        }
        if (count != 0)
        {
            str.append(to_string(count));
            count = 0;
        }
        result.push_back(str);
    }
    return result;
}

/// <summary>
/// Leet code #411. Minimum Unique Word Abbreviation         
/// </summary>
void LeetCode::getAbbrBits(int index, int digits, int target_digits, string &abbr_bits, vector<string> &result)
{
    if (digits == target_digits)
    {
        result.push_back(abbr_bits);
    }
    while (index < (int)abbr_bits.size())
    {
        abbr_bits[index] = '1';
        getAbbrBits(index + 1, digits + 1, target_digits, abbr_bits, result);
        abbr_bits[index] = '0';
        index++;
    }
}

/// <summary>
/// Leet code #411. Minimum Unique Word Abbreviation         
/// </summary>
string LeetCode::getAbbrWord(string word, string abbr_bits, int& length)
{
    if (word.size() != abbr_bits.size())
    {
        return "";
    }
    string str;
    int count = 0;
    for (size_t i = 0; i < abbr_bits.size(); i++)
    {
        if (abbr_bits[i] == '1')
        {
            if (count != 0)
            {
                length++;
                str.append(to_string(count));
                count = 0;
            }
            length++;
            str.push_back(word[i]);
        }
        else
        {
            count++;
        }
    }
    if (count != 0)
    {
        length++;
        str.append(to_string(count));
        count = 0;
    }
    return str;
}

/// <summary>
/// Leet code #411. Minimum Unique Word Abbreviation         
/// 
/// A string such as "word" contains the following abbreviations:
/// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", 
///  "2r1", "3d", "w3", "4"]
/// Given a target string and a set of strings in a dictionary, find an abbreviation of this 
/// target string with the smallest possible length such that it does not conflict with 
/// abbreviations of the strings in the dictionary. 
///
/// Each number or letter in the abbreviation is considered length = 1. 
/// For example, the abbreviation "a32bc" has length = 4.
///
/// Note:
/// In the case of multiple answers as shown in the second example below, you may return any one of them.
/// Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, 
/// and log2(n) + m ≤ 20.
/// 
/// Examples:
///
/// "apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")
///
/// "apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", 
/// "2p2", "3le", "3l1").
/// </summary>
string LeetCode::minAbbreviation(string target, vector<string>& dictionary)
{
    string result = target;
    int min_length = target.size();
    for (size_t i = 0; i < target.size(); i++)
    {
        if (i >(size_t)min_length) break;
        vector<string> abbr_list;
        string abbr_bits = string(target.size(), '0');
        getAbbrBits(0, 0, i, abbr_bits, abbr_list);
        for (string abbr_bits : abbr_list)
        {
            int length = 0;
            string target_abbr = getAbbrWord(target, abbr_bits, length);
            if (length > min_length) continue;
            bool unique = true;
            for (string word : dictionary)
            {
                int length;
                string word_abbr = getAbbrWord(word, abbr_bits, length);
                if (word_abbr == target_abbr)
                {
                    unique = false;
                    break;
                }
            }
            if (unique)
            {
                result = target_abbr;
                min_length = length;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #473. Matchsticks to Square  
/// </summary>
bool LeetCodeDFS::makesquare(vector<int>& nums, vector<int>& path, int bit_mask, int sum,
    int side_length, unordered_set<int>& cache)
{
    if (path.size() == nums.size()) return true;
    if (cache.count(bit_mask) > 0) return false;
    int start = 0;
    sum %= side_length;
    if (sum > 0)
    {
        start = path.back() + 1;
    }
    int n = nums.size();
    bool result = false;
    for (int i = start; i < n; i++)
    {
        if (sum + nums[i] > side_length) break;
        int bit = 1 << i;
        if ((bit_mask & bit) != 0) continue;
        path.push_back(i);
        result = makesquare(nums, path, bit_mask | bit, sum + nums[i], side_length, cache);
        path.pop_back();
        if (result == true) break;
    }
    if (result == false) cache.insert(bit_mask);
    return result;
}

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
bool LeetCodeDFS::makesquare(vector<int>& nums)
{
    unordered_set<int> cache;
    sort(nums.begin(), nums.end());
    vector<int> path;
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++) sum += nums[i];
    if ((sum == 0) || (sum % 4 != 0)) return false;
    int side_length = sum / 4;
    return makesquare(nums, path, 0, 0, side_length, cache);
}

/// <summary>
/// Leet code #267. Palindrome Permutation II 
/// </summary>
void LeetCode::generatePalindromes(string s, string partial_result, unordered_set<int>&visited, vector<string>& result)
{
    if (s.size() == partial_result.size())
    {
        result.push_back(partial_result);
        return;
    }
    int last = -1;
    for (size_t i = 0; i < s.size(); i++)
    {
        if ((visited.count(i) == 0) && ((last == -1) || s[i] != s[last]))
        {
            last = i;
            visited.insert(i);
            partial_result.push_back(s[i]);
            generatePalindromes(s, partial_result, visited, result);
            visited.erase(i);
            partial_result.pop_back();
        }
    }
    return;
}

/// <summary>
/// Leet code #267. Palindrome Permutation II 
/// 
/// Given a string s, return all the palindromic permutations (without duplicates) of it. 
/// Return an empty list if no palindromic permutation could be form. 
/// For example: 
/// 
/// Given s = "aabb", return ["abba", "baab"]. 
/// Given s = "abc", return []. 
/// Hint:
/// 1.If a palindromic permutation exists, we just need to generate the first half of the string.
/// 2.To generate all distinct permutations of a (half of) string, use a similar approach from: 
///   Permutations II or Next Permutation.
/// </summary>
vector<string> LeetCode::generatePalindromes(string s)
{
    unordered_map<char, int> char_map;
    vector<string> result;
    string str;
    char singleton = 0;
    for (char ch : s)
    {
        char_map[ch]++;
    }
    for (auto itr : char_map)
    {
        if (itr.second % 2 == 0)
        {
            str.append(itr.second / 2, itr.first);
        }
        else if (singleton == 0)
        {
            str.append((itr.second - 1) / 2, itr.first);
            singleton = itr.first;
        }
        else
        {
            return result;
        }
    }
    string partial_result;
    unordered_set<int> visited;
    vector<string> half_result;
    generatePalindromes(str, partial_result, visited, half_result);
    for (string str : half_result)
    {
        string rev = str;
        std::reverse(rev.begin(), rev.end());
        if (singleton != 0)
        {
            str.push_back(singleton);
        }
        str.append(rev);
        result.push_back(str);
    }
    return result;
}


/// <summary>
/// Leet code #294. Flip Game II  
/// </summary>
bool LeetCode::canWin(string s, unordered_map<string, bool>& cache)
{
    for (int i = 0; i < (int)s.size() - 1; i++)
    {
        if ((s[i] == '+') && (s[i + 1] == '+'))
        {
            s[i] = '-'; s[i + 1] = '-';
            bool win = canWin(s, cache);
            s[i] = '+'; s[i + 1] = '+';
            if (!win)
            {
                cache[s] = true;
                return true;
            }
        }
    }
    cache[s] = false;
    return false;
}

/// <summary>
/// Leet code #294. Flip Game II  
/// 
/// You are playing the following Flip Game with your friend: Given a string that 
/// contains only these two characters: + and -, you and your friend take turns to 
/// flip two consecutive "++" into "--". The game ends when a person can no longer 
/// make a move and therefore the other person will be the winner. 
/// Write a function to determine if the starting player can guarantee a win. 
/// For example, given s = "++++", return true. The starting player can guarantee 
/// a win by flipping the middle "++" to become "+--+". 
/// Follow up:
/// Derive your algorithm's runtime complexity. 
/// </summary>
bool LeetCode::canWin(string s)
{
    unordered_map<string, bool> cache;
    return canWin(s, cache);
}


/// <summary>
/// Leet code #291. Word Pattern II    
/// </summary>
bool LeetCode::wordPatternMatch(string& pattern, string& str, int pat_index, int str_index,
    map<char, string>& pat_map, map<string, char>& str_map)
{
    if (pat_index == pattern.size() && str_index == str.size())
    {
        return true;
    }
    else if ((pat_index == pattern.size() && str_index != str.size()) || (pat_index != pattern.size() && str_index == str.size()))
    {
        return false;
    }
    char pat_ch = pattern[pat_index];
    if (pat_map.count(pat_ch) > 0)
    {
        string target = pat_map[pat_ch];
        if (str.substr(str_index, target.size()) != target)
        {
            return false;
        }
        pat_index++;
        str_index += target.size();
        return wordPatternMatch(pattern, str, pat_index, str_index, pat_map, str_map);
    }

    for (size_t i = str_index; i < str.size(); i++)
    {
        string str_str = str.substr(str_index, i + 1 - str_index);
        if (str_map.count(str_str) > 0) continue;
        pat_map[pat_ch] = str_str;
        str_map[str_str] = pat_ch;
        if (wordPatternMatch(pattern, str, pat_index + 1, i + 1, pat_map, str_map))
        {
            return true;
        }
        pat_map.erase(pat_ch);
        str_map.erase(str_str);
    }
    return false;
}

/// <summary>
/// Leet code #291. Word Pattern II    
/// 
/// Given a pattern and a string str, find if str follows the same pattern. 
/// Here follow means a full match, such that there is a bijection between a letter in pattern 
/// and a non-empty substring in str. 
/// Examples:
/// 1.pattern = "abab", str = "redblueredblue" should return true.
/// 2.pattern = "aaaa", str = "asdasdasdasd" should return true.
/// 3.pattern = "aabb", str = "xyzabcxzyabc" should return false.
/// 
/// Notes:
/// You may assume both pattern and str contains only lowercase letters. 
/// </summary>
bool LeetCode::wordPatternMatch(string pattern, string str)
{
    map<char, string> pat_map;
    map<string, char> str_map;
    return wordPatternMatch(pattern, str, 0, 0, pat_map, str_map);
}

/// <summary>
/// Leet code #491. Increasing Subsequences  
/// </summary>
void LeetCodeDFS::findSubsequences(vector<int>& nums, size_t start_index, 
    vector<int> &sequence, vector<vector<int>> &result)
{
    if (start_index == nums.size())
    {
        return;
    }
    set<int> visited;
    for (size_t i = start_index; i < nums.size(); i++)
    {
        if (visited.count(nums[i]) > 0)
        {
            continue;
        }
        if (!sequence.empty() && nums[i] < sequence.back())
        {
            continue;
        }
        visited.insert(nums[i]);
        sequence.push_back(nums[i]);
        if (sequence.size() >= 2)
        {
            result.push_back(sequence);
        }
        findSubsequences(nums, i + 1, sequence, result);
        sequence.pop_back();
    }
}

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
vector<vector<int>> LeetCodeDFS::findSubsequences(vector<int>& nums)
{
    vector<int> sequence;
    vector<vector<int>> result;
    findSubsequences(nums, 0, sequence, result);
    return result;
}

/// <summary>
/// Leet code #488. Zuma Game
/// </summary>
void LeetCode::shrinkZuma(string &board)
{
    size_t first = 0, last = 0;
    while (last < board.size())
    {
        while (last < board.size() && board[first] == board[last])
        {
            last++;
        }
        if (first + 2 < last)
        {
            board.erase(first, last - first);
            first = 0;
            last = 0;
        }
        else
        {
            first = last;
        }
    }
}

/// <summary>
/// Leet code #488. Zuma Game
/// </summary>
int LeetCode::findMinStep(string board, unordered_map<char, int>& hand_map, unordered_map<string, int>& cache)
{
    shrinkZuma(board);
    if (cache.count(board) > 0) return cache[board];
    if (board.empty())
    {
        cache[board] = 0;
        return 0;
    }
    for (char ch : board)
    {
        if (count(board.begin(), board.end(), ch) + hand_map[ch] < 3)
        {
            cache[board] = -1;
            return -1;
        }
    }
    int min_steps = INT_MAX;
    for (int i = 0; i < (int)board.size(); i++)
    {
        if (i > 0 && board[i] == board[i - 1]) continue;
        int j = i;
        while (j < (int)board.size() && board[i] == board[j]) j++;
        if (3 - (j - i) >(int)hand_map[board[i]]) continue;
        string smaller_board = board.substr(0, i) + board.substr(j);
        hand_map[board[i]] -= 3 - (j - i);
        int steps = findMinStep(smaller_board, hand_map, cache);
        if (steps != -1) min_steps = min(min_steps, steps + (3 - (j - i)));
        hand_map[board[i]] += 3 - (j - i);
    }
    if (min_steps == INT_MAX) min_steps = -1;
    cache[board] = min_steps;
    return min_steps;
}

/// <summary>
/// Leet code #488. Zuma Game
///
/// Think about Zuma Game. You have a row of balls on the table, colored red(R), 
/// yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.
/// Each time, you may choose a ball in your hand, and insert it into the row (including 
/// the leftmost place and rightmost place). Then, if there is a group of 3 or more balls 
/// in the same color touching, remove these balls. Keep doing this until no more 
/// balls can be removed.
///
/// Find the minimal balls you have to insert to remove all the balls on the table. If 
/// you cannot remove all the balls, output -1. 
/// Examples:
///  
/// Input: "WRRBBW", "RB"
/// Output: -1
/// Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
///
/// Input: "WWRRBBWW", "WRBRW"
/// Output: 2
/// Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty
/// 
/// Input:"G", "GGGGG"
/// Output: 2
/// Explanation: G -> G[G] -> GG[G] -> empty 
///
/// Input: "RBYYBBRRB", "YRBGB"
/// Output: 3
/// Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 
///
/// Note:
/// 1.You may assume that the initial row of balls on the table won’t have any 3 or more 
///   consecutive balls with the same color.
/// 2.The number of balls on the table won't exceed 20, and the string represents these 
///   balls is called "board" in the input.
/// 3.The number of balls in your hand won't exceed 5, and the string represents these balls 
///   is called "hand" in the input.
/// 4.Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.
/// </summary>
int LeetCode::findMinStep(string board, string hand)
{
    unordered_map<char, int> hand_map;
    unordered_map<string, int> cache;
    for (size_t i = 0; i < hand.size(); i++)
    {
        hand_map[hand[i]]++;
    }
    int min_steps = findMinStep(board, hand_map, cache);
    return min_steps;
}

/// <summary>
/// Leet code #465. Optimal Account Balancing
/// </summary>
int LeetCode::minTransfers(vector<int>& debt, size_t index)
{
    int min_count = INT_MAX;
    while (index < debt.size() && debt[index] == 0) index++;
    if (index == debt.size()) return 0;

    int debt_value = debt[index];
    debt[index] = 0;
    for (size_t i = index + 1; i < debt.size(); i++)
    {
        if (debt[i] == 0 || debt[i] * debt_value > 0) continue;
        debt[i] += debt_value;
        min_count = min(min_count, minTransfers(debt, index + 1) + 1);
        debt[i] -= debt_value;
    }
    debt[index] = debt_value;
    return min_count;
}

/// <summary>
/// Leet code #465. Optimal Account Balancing
/// A group of friends went on holiday and sometimes lent each other money. 
/// For example, Alice paid for Bill's lunch for $10. Then later Chris gave 
/// Alice $5 for a taxi ride. We can model each transaction as a tuple 
/// (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, 
/// and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), 
/// the transactions can be represented as [[0, 1, 10], [2, 0, 5]].
///
/// Given a list of transactions between a group of people, return the minimum 
/// number of transactions required to settle the debt.
///
/// Note: 
/// 1.A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
/// 2.Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we 
///   could also have the persons 0, 2, 6.
/// Example 1: 
/// Input:
/// [[0,1,10], [2,0,5]]
///
/// Output:
/// 2
///
/// Explanation:
/// Person #0 gave person #1 $10.
/// Person #2 gave person #0 $5.
///
/// Two transactions are needed. One way to settle the debt is person #1 
/// pays person #0 and #2 $5 each.
/// Example 2: 
/// Input:
/// [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
/// Output:
/// 1
///
/// Explanation:
/// Person #0 gave person #1 $10.
/// Person #1 gave person #0 $1.
/// Person #1 gave person #2 $5.
/// Person #2 gave person #0 $5.
///
/// Therefore, person #1 only need to give person #0 $4, and all debt is settled.
/// </summary>
int LeetCode::minTransfers(vector<vector<int>>& transactions)
{
    unordered_map<int, int> balances;
    for (size_t i = 0; i < transactions.size(); i++)
    {
        balances[transactions[i][0]] -= transactions[i][2];
        balances[transactions[i][1]] += transactions[i][2];
    }
    vector<int> debt;
    unordered_map<int, vector<int>> value_map;
    for (auto itr : balances)
    {
        debt.push_back(itr.second);
        value_map[itr.second].push_back(debt.size() - 1);
    }
    int count = 0;
    for (auto itr : value_map)
    {
        while ((itr.first != 0) && (!itr.second.empty()) && (!value_map[-itr.first].empty()))
        {
            int first = value_map[itr.first].back();
            value_map[itr.first].pop_back();
            int last = value_map[-itr.first].back();
            value_map[-itr.first].pop_back();
            debt[first] = 0;
            debt[last] = 0;
            count++;
        }
    }
    count += minTransfers(debt, 0);
    return count;
}

/// <summary>
/// Leet code #472. Concatenated Words
/// </summary>
bool LeetCode::findAllConcatenatedWordsInADict(string word, int start, unordered_set<string>& dictionary)
{
    if ((start == word.size()) && (start != 0)) return true;
    for (size_t end = start + 1; end <= word.size(); end++)
    {
        string sub_word = word.substr(start, end - start);
        if ((start == 0) && (end == word.size())) return false;
        if (dictionary.count(sub_word) > 0)
        {
            if (findAllConcatenatedWordsInADict(word, end, dictionary))
            {
                return true;
            }
        }
    }
    return false;
}

/// <summary>
/// Leet code #472. Concatenated Words
///
/// Given a list of words (without duplicates), please write a program that 
/// returns all concatenated words in the given list of words. 
///
/// A concatenated word is defined as a string that is comprised entirely of at 
/// least two shorter words in the given array.
/// Example:
/// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
/// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
/// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
/// "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
/// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
///
/// Note:
/// 1.The number of elements of the given array will not exceed 10,000  
/// 2.The length sum of elements in the given array will not exceed 600,000. 
/// 3.All the input string will only include lower case letters.
/// 4.The returned elements order does not matter. 
/// </summary>
vector<string> LeetCode::findAllConcatenatedWordsInADict(vector<string>& words)
{
    vector<string> result;
    unordered_set<string>  dictionary;
    for (size_t i = 0; i < words.size(); i++)
    {
        dictionary.insert(words[i]);
    }
    for (size_t i = 0; i < words.size(); i++)
    {
        if (findAllConcatenatedWordsInADict(words[i], 0, dictionary))
        {
            result.push_back(words[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #425. Word Squares
/// </summary>
void LeetCodeDFS::wordSquares(TrieNode *root, vector<string>& wordSquare, vector<vector<string>>& result)
{
    if ((!wordSquare.empty()) && (wordSquare.size() == wordSquare[0].size()))
    {
        result.push_back(wordSquare);
        return;
    }

    string prefix;
    for (size_t i = 0; i < wordSquare.size(); i++)
    {
        prefix.push_back(wordSquare[i][wordSquare.size()]);
    }
    vector<string> words;
    TrieNode * trie = root;
    for (size_t i = 0; i < prefix.size(); i++)
    {
        trie = trie->next(prefix[i]);
        if (trie == nullptr) break;
    }
    if (trie != nullptr)
    { 
        trie->get_words(prefix, words);
        for (size_t i = 0; i < words.size(); i++)
        {
            wordSquare.push_back(words[i]);
            wordSquares(root, wordSquare, result);
            wordSquare.pop_back();
        }
    }
}

/// <summary>
/// Leet code #425. Word Squares
///
/// Given a set of words (without duplicates), find all word squares you 
/// can build from them.
/// A sequence of words forms a valid word square if the kth row and column
/// read the exact same string, where 0 ≤ k < max(numRows, numColumns).
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
/// The output consists of two word squares. The order of output does not 
/// matter 
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
vector<vector<string>> LeetCodeDFS::wordSquares(vector<string>& words)
{
    vector<string> wordSquare;
    vector<vector<string>> result;
    TrieNode *trie = new TrieNode();
    for (size_t i = 0; i < words.size(); i++)
    {
        trie->insert(words[i], 0);
    }
    wordSquares(trie, wordSquare, result);
    delete trie;
    return result;
}

/// <summary>
/// Leet code #351. Android Unlock Patterns
/// </summary>
void LeetCode::nextPattern(vector<int> &keys, vector<int> &visited, int m, int n, int &count)
{
    unordered_map<int, set<int>> key_map =
    {
        { 1,{ 3, 7, 9 } },{ 3,{ 1, 7, 9 } },{ 9,{ 1, 3, 7 } },{ 7,{ 1, 3, 9 } },{ 2,{ 8 } },{ 4,{ 6 } },{ 6,{ 4 } },{ 8,{ 2 } }
    };

    if ((keys.size() >= (size_t)m) && (keys.size() <= (size_t)n)) count++;
    if (keys.size() == n) return;

    int last_key = keys.back();
    for (size_t i = 1; i < 10; i++)
    {
        if (visited[i] == 1) continue;
        if ((key_map[last_key].count(i) > 0) && (visited[(last_key + i) / 2] == 0)) continue;
        visited[i] = 1;
        keys.push_back(i);
        nextPattern(keys, visited, m, n, count);
        keys.pop_back();
        visited[i] = 0;
    }
}

/// <summary>
/// Leet code #351. Android Unlock Patterns
/// </summary>
int LeetCode::nextPattern(int key, int m, int n)
{
    vector<int> keys;
    vector<int> visited(10);
    int count = 0;
    keys.push_back(key);
    visited[key] = 1;
    nextPattern(keys, visited, m, n, count);
    return count;
}

/// <summary>
/// Leet code #351. Android Unlock Patterns
///
/// Given an Android 3x3 key lock screen and two integers m and n, where 
/// 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android 
/// lock screen, which consist of minimum of m keys and maximum n keys.
/// 
/// Rules for a valid pattern:
/// 1.Each pattern must connect at least m keys and at most n keys.
/// 2.All the keys must be distinct.
/// 3.If the line connecting two consecutive keys in the pattern passes 
///   through any other keys, the other keys must have previously selected 
///   in the pattern. No jumps through non selected key is allowed.
/// 4.The order of keys used matters.
///
/// Explanation:
/// | 1 | 2 | 3 |
/// | 4 | 5 | 6 |
/// | 7 | 8 | 9 |
///
/// Invalid move: 4 - 1 - 3 - 6 
/// Line 1 - 3 passes through key 2 which had not been selected in the pattern.
///
/// Invalid move: 4 - 1 - 9 - 2 
/// Line 1 - 9 passes through key 5 which had not been selected in the pattern.
///
/// Valid move: 2 - 4 - 1 - 3 - 6
/// Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern
///
/// Valid move: 6 - 5 - 4 - 1 - 9 - 2
/// Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
/// Example:
/// Given m = 1, n = 1, return 9. 
/// </summary>
int LeetCode::numberOfPatterns(int m, int n)
{
    int result = 0;
    result += nextPattern(1, m, n) * 4;
    result += nextPattern(2, m, n) * 4;
    result += nextPattern(5, m, n);

    return result;
}

/// <summary>
/// Leet code #526. Beautiful Arrangement
/// </summary>
int LeetCodeDFS::countArrangement(int N, int index, int visited, unordered_map<int, int>& cache)
{
    int result = 0;
    if (index == N)
    {
        return 1;
    }
    if (cache.count(visited) > 0)
    {
        return cache[visited];
    }

    for (int i = 1; i <= N; i++)
    {
        int bit = (1 << (i - 1));
        if (((index + 1) % i != 0) && (i % (index + 1) != 0)) continue;
        if ((visited & bit) == 0)
        {
            result += countArrangement(N, index + 1, visited | bit, cache);
        }
    }
    cache[visited] = result;
    return result;
}

/// <summary>
/// Leet code #526. Beautiful Arrangement
///
/// Suppose you have N integers from 1 to N. We define a beautiful 
/// arrangement as an array that is constructed by these N numbers 
/// successfully if one of the following is true for the ith position 
/// (1 ≤ i ≤ N) in this array: 
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
int LeetCodeDFS::countArrangement(int N)
{
    int visited = 0 ;
    unordered_map<int, int> cache;
    return countArrangement(N, 0, visited, cache);
}

/// <summary>
/// Leet code #140. Word Break II
/// Recursive break the word according to dictionary, return word list 
/// </summary>
vector<string> LeetCodeDFS::wordBreakII(string s, unordered_set<string>& wordDict,
    unordered_map<string, vector<string>>&search_map)
{
    vector<string> result;

    if (s.size() == 0)
    {
        return result;
    }
    if (search_map.find(s) != search_map.end())
    {
        return search_map[s];
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        string sub_word = s.substr(0, i + 1);
        if (wordDict.find(sub_word) != wordDict.end())
        {
            if (i == s.size() - 1)
            {
                result.push_back(sub_word);
            }
            else
            {
                vector<string> sentence_list = wordBreakII(s.substr(i + 1), wordDict, search_map);
                for (string sentence : sentence_list)
                {
                    result.push_back(sub_word + " " + sentence);
                }
            }
        }
    }
    search_map[s] = result;
    return result;
}

/// <summary>
/// Leet code #140. Word Break II  
/// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
/// Return all such possible sentences.
/// For example, given
/// s = "catsanddog",
/// dict = ["cat", "cats", "and", "sand", "dog"]. 
/// A solution is ["cats and dog", "cat sand dog"].
/// </summary>
vector<string> LeetCodeDFS::wordBreakII(string s, vector<string>& wordDict)
{
    unordered_map<string, vector<string>> search_map;
    unordered_set<string> word_set;
    for (string str : wordDict) word_set.insert(str);
    return wordBreakII(s, word_set, search_map);
}

/// <summary>
/// Leet code #247. Strobogrammatic Number II 
/// </summary>
void LeetCodeDFS::findStrobogrammatic(int i, int n, string& str, vector<string>& result, map<char, char>& num_map)
{
    if (i == (n + 1) / 2)
    {
        result.push_back(str);
    }
    else
    {
        for (auto itr : num_map)
        {
            if (((i == 0) && (n != 1)) && (itr.first == '0')) continue;
            if ((i == (n + 1) / 2 - 1) && (n - 1 - i == i) && ((itr.first == '6') || (itr.first == '9'))) continue;
            str[i] = itr.first;
            if (n - 1 - i > i)
            {
                str[n - 1 - i] = itr.second;
            }
            findStrobogrammatic(i + 1, n, str, result, num_map);
        }
    }
}

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
vector<string> LeetCodeDFS::findStrobogrammatic(int n)
{
    string str = string(n, '0');
    vector<string> result;
    map<char, char> num_map = { { '0', '0' },{ '1', '1' },{ '6', '9' },{ '9', '6' },{ '8', '8' } };
    findStrobogrammatic(0, n, str, result, num_map);
    return result;
}

/// <summary>
/// Leet code #248. Strobogrammatic Number III 
/// </summary>
void LeetCodeDFS::strobogrammaticInRange(int i, int n, string low, string high, string& str, int &count, map<char, char>& num_map)
{
    if (i == (n + 1) / 2)
    {
        if (str.size() == low.size() && str < low) return;
        if (str.size() == high.size() && str > high) return;
        count++;
    }
    else
    {
        for (auto itr : num_map)
        {
            if (((i == 0) && (n != 1)) && (itr.first == '0')) continue;
            if ((i == (n + 1) / 2 - 1) && (n - 1 - i == i) && ((itr.first == '6') || (itr.first == '9'))) continue;
            str[i] = itr.first;
            if (n - 1 - i > i)
            {
                str[n - 1 - i] = itr.second;
            }
            strobogrammaticInRange(i + 1, n, low, high, str, count, num_map);
        }
    }
}

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
int LeetCodeDFS::strobogrammaticInRange(string low, string high)
{
    map<char, char> num_map = { { '0', '0' },{ '1', '1' },{ '6', '9' },{ '9', '6' },{ '8', '8' } };
    int count = 0;
    for (size_t n = low.size(); n <= high.size(); n++)
    {
        string str = string(n, '0');
        strobogrammaticInRange(0, n, low, high, str, count, num_map);
    }
    return count;
}

/// <summary>
/// Leet code #9901. Get Maximum Expression 
/// 
/// Assume you are given a list of integer and you can add '+', '*' or '(' , ')'.  
/// Please try to get the maximum result.
/// </summary>
pair<int, int> LeetCode::getMaxExprResult(vector<int>& nums, int start, int end,
    unordered_map<string, pair<int, int>> &cache)
{
    pair<int, int> min_max;
    string str = to_string(start) + "," + to_string(end);
    if (cache.count(str) > 0) return cache[str];
    if (start == end)
    {
        min_max = make_pair(nums[start], nums[start]);
    }
    else if (start + 1 == end)
    {
        min_max.first = min(nums[start] + nums[end], nums[start] * nums[end]);
        min_max.second = max(nums[start] + nums[end], nums[start] * nums[end]);
    }
    else
    {
        min_max.first = INT_MAX;
        min_max.second = INT_MIN;
        for (int i = start + 1; i <= end; i++)
        {
            pair<int, int> left_min_max = getMaxExprResult(nums, start, i - 1, cache);
            pair<int, int> right_min_max = getMaxExprResult(nums, i, end, cache);
            min_max.first = min(min_max.first, left_min_max.first + right_min_max.first);
            min_max.first = min(min_max.first, left_min_max.first * right_min_max.first);
            min_max.first = min(min_max.first, left_min_max.first * right_min_max.second);
            min_max.first = min(min_max.first, left_min_max.second * right_min_max.first);
            min_max.first = min(min_max.first, left_min_max.second * right_min_max.second);

            min_max.second = max(min_max.second, left_min_max.second + right_min_max.second);
            min_max.second = max(min_max.second, left_min_max.first * right_min_max.first);
            min_max.second = max(min_max.second, left_min_max.first * right_min_max.second);
            min_max.second = max(min_max.second, left_min_max.second * right_min_max.first);
            min_max.second = max(min_max.second, left_min_max.second * right_min_max.second);
        }
    }
    cache[str] = min_max;
    return min_max;
}

/// <summary>
/// Leet code #901. Get Maximum Expression 
/// 
/// Assume you are given a list of integer and you can add '+', '*' or '(' , ')'.  
/// Please try to get the maximum result.
/// </summary>
int LeetCode::getMaxExprResult(vector<int> nums)
{
    unordered_map<string, pair<int, int>> cache;
    pair<int, int>  min_max = getMaxExprResult(nums, 0, nums.size() - 1, cache);
    return min_max.second;
}

/// <summary>
/// Leet code #546. Remove Boxes 
/// </summary>
string LeetCode::toString(vector<int>& boxes)
{
    string result;
    for (size_t i = 0; i < boxes.size(); i++)
    {
        if (!result.empty()) result.push_back(',');
        result += to_string(boxes[i]);
    }
    return result;
}

/// <summary>
/// Leet code #546. Remove Boxes 
/// </summary>
int LeetCode::calculatePoints(vector<int>&boxes, int start, int end, int k, vector<vector<vector<int>>>scores)
{
    if (start > end) return 0;
    if (scores[start][end][k] != 0) return scores[start][end][k];
    while ((start < end) && (boxes[end - 1] == boxes[end]))
    {
        end--;
        k++;
    }

    scores[start][end][k] = calculatePoints(boxes, start, end - 1, 0, scores) + (k + 1) * (k + 1);

    for (int i = start; i < end; i++)
    {
        if (boxes[i] == boxes[end])
        {
            scores[start][end][k] =
                max(scores[start][end][k],
                    calculatePoints(boxes, start, i, k + 1, scores) + calculatePoints(boxes, i + 1, end - 1, 0, scores));
        }
    }
    return scores[start][end][k];
}

/// <summary>
/// Leet code #546. Remove Boxes 
/// 
/// Given several boxes with different colors represented by different 
/// positive numbers. 
/// You may experience several rounds to remove boxes until there is no 
/// box left. Each time you can choose some continuous boxes with the same 
/// color (composed of k boxes, k >= 1), remove them and get k*k points.
/// Find the maximum points you can get.
///
/// Example 1:
/// Input:
/// [1, 3, 2, 2, 2, 3, 4, 3, 1]
/// Output:
/// 23
/// Explanation:
/// [1, 3, 2, 2, 2, 3, 4, 3, 1] 
/// ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
/// ----> [1, 3, 3, 3, 1] (1*1=1 points) 
/// ----> [1, 1] (3*3=9 points) 
/// ----> [] (2*2=4 points)
/// Note: The number of boxes n would not exceed 100.
/// </summary>
int LeetCode::removeBoxes(vector<int>& boxes)
{
    vector<vector<vector<int>>> scores(20, vector<vector<int>>(20, vector<int>(20)));
    return calculatePoints(boxes, 0, boxes.size() - 1, 0, scores);
}

/// <summary>
/// Leet code #638. Shopping Offers
/// </summary>
int LeetCode::tryOffer(vector<vector<int>>& special, vector<int>& needs, int index)
{
    for (size_t i = 0; i < needs.size(); i++)
    {
        if (special[index][i] > needs[i]) return -1;
    }
    for (size_t i = 0; i < needs.size(); i++)
    {
        needs[i] -= special[index][i];
    }
    return special[index][needs.size()];
}

/// <summary>
/// Leet code #638. Shopping Offers
/// </summary>
void LeetCode::shoppingOffers(vector<int>& price, vector<vector<int>>& special,
    vector<int>& needs, int index, int&total_price, int& min_price)
{
    if (index == special.size())
    {
        int single_sum = 0;
        for (size_t i = 0; i < needs.size(); i++)
        {
            single_sum += price[i] * needs[i];
        }
        min_price = min(total_price + single_sum, min_price);
        return;
    }

    shoppingOffers(price, special, needs, index + 1, total_price, min_price);
    int offer_count = 0;
    while (tryOffer(special, needs, index) >= 0)
    {
        offer_count++;
        total_price += special[index][needs.size()];
        shoppingOffers(price, special, needs, index + 1, total_price, min_price);
    }

    // retire all this special offers
    total_price -= offer_count * special[index][needs.size()];
    for (size_t i = 0; i < needs.size(); i++)
    {
        needs[i] += offer_count * special[index][i];
    }
    return;
}

/// <summary>
/// Leet code #638. Shopping Offers
/// 
/// In LeetCode Store, there are some kinds of items to sell. Each item has a 
/// price. 
/// However, there are some special offers, and a special offer consists of one
/// or more different kinds of items with a sale price. 
/// You are given the each item's price, a set of special offers, and the 
/// number we need to buy for each item. The job is to output the lowest price 
/// you have to pay for exactly certain items as given, where you could make 
/// optimal use of the special offers. 
/// Each special offer is represented in the form of an array, the last number 
/// represents the price you need to pay for this special offer, other numbers 
/// represents how many specific items you could get if you buy this offer. 
/// You could use any of special offers as many times as you want.
///
/// Example 1:
/// Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
/// Output: 14
/// Explanation: 
/// There are two kinds of items, A and B. Their prices are $2 and $5 
/// respectively. 
/// In special offer 1, you can pay $5 for 3A and 0B
/// In special offer 2, you can pay $10 for 1A and 2B. 
/// You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer 
/// #2), and $4 for 2A.
///
/// Example 2:
/// Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
/// Output: 11
/// Explanation: 
/// The price of A is $2, and $3 for B, $4 for C. 
/// You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
/// You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special 
/// offer #1), and $3 for 1B, $4 for 1C. 
/// You cannot add more items, though only $9 for 2A ,2B and 1C.
/// 
/// Note:
/// 1. There are at most 6 kinds of items, 100 special offers.
/// 2. For each item, you need to buy at most 6 of them.
/// 3. You are not allowed to buy more items than you want, even if that would 
/// lower the overall price.
/// </summary>
int LeetCode::shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
    int total_price = 0;
    int min_price = INT_MAX;
    shoppingOffers(price, special, needs, 0, total_price, min_price);
    return min_price;
}

/// <summary>
/// Leet code #681. Next Closest Time
/// </summary>
bool LeetCode::isValidTime(string& time)
{
    if (time[0] > '2') return false;
    if (time[0] == '2' && time[1] > '4') return false;
    if (time[3] > '5') return false;
    return true;
}

/// <summary>
/// Leet code #681. Next Closest Time
/// </summary>
bool LeetCode::NextTime(string& time, int index, set<char>& nums)
{
    if (index == time.size()) return true;
    if (time[index] == '#')
    {
        for (char ch : nums)
        {
            time[index] = ch;
            if (isValidTime(time)) return true;
        }
        return false;
    }
    else
    {
        set<char>::iterator itr = nums.lower_bound(time[index]);
        itr++;
        if (itr == nums.end())
        {
            return false;
        }
        else
        {
            time[index] = *itr;
            if (!isValidTime(time))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

/// <summary>
/// Leet code #681. Next Closest Time
/// 
/// Given a time represented in the format "HH:MM", form the next closest 
/// time by reusing the current digits. There is no limit on how many 
/// times a digit can be reused.
///
/// You may assume the given input string is always valid. For example, 
/// "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
///
/// Example 1:
///
/// Input: "19:34"
/// Output: "19:39"
/// Explanation: The next closest time choosing from digits 1, 9, 3, 4, 
/// is 19:39, which occurs 5 minutes later.  It is not 19:33, because 
/// this occurs 23 hours and 59 minutes later.
///
/// Example 2:
///
/// Input: "23:59"
/// Output: "22:22"
/// Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 
/// 22:22. It may be assumed that the returned time is next day's time 
/// since it is smaller than the input time numerically.
/// </summary>
string LeetCode::nextClosestTime(string time)
{
    set<char> nums;
    for (size_t i = 0; i < time.size(); i++)
    {
        if (time[i] == ':') continue;
        nums.insert(time[i]);
    }
    int index = time.size() - 1;
    while (index >= 0 && index < (int)time.size())
    {
        if (NextTime(time, index, nums))
        {
            index++;
            if (time[index] == ':') index++;
        }
        else
        {
            time[index] = '#';
            if (index > 0) index--;
            if (time[index] == ':') index--;
        }
    }
    return time;
}

/// <summary>
/// Leet code #698. Partition to K Equal Sum Subsets
/// </summary>
bool LeetCode::buildPartitionKSubsets(vector<int>& nums, int index, vector<vector<int>> &path,
    int partition_id, int partition_count, int sum, vector<int>& visited,
    unordered_map<string, int> &search_map)
{
    // we have k partitions, we succeed
    if (partition_id == partition_count)
    {
        return true;
    }

    // calculate signature
    string signature(nums.size(), '0');
    for (size_t i = 0; i < path[partition_id].size(); i++)
    {
        signature[path[partition_id][i]] = '1';
    }
    // check if signature already exhausted
    if (search_map.count(signature))
    {
        return false;
    }

    // calculate partition sum
    int partition_sum = 0;
    for (size_t i = 0; i < path[partition_id].size(); i++)
    {
        partition_sum += nums[path[partition_id][i]];
    }
    // one partition is good, we build next partiton;
    if (partition_sum == sum)
    {
        // search next partition
        partition_id++;
        unordered_map<string, int> search_map;
        // if successful, we return true;
        int index = (partition_id == 0) ? 0 : path[partition_id - 1][0];
        if (buildPartitionKSubsets(nums, index, path, partition_id, partition_count, sum, visited, search_map))
        {
            return true;
        }
    }
    else
    {
        for (size_t i = index; i < nums.size(); i++)
        {
            // assume nums are in order, so we can not find any item if partition overflow
            if (partition_sum + nums[i] > sum) break;
            // only take not visited
            if (visited[i] == 0)
            {
                visited[i] = 1;
                path[partition_id].push_back(i);
                // if successful, we return true;
                if (buildPartitionKSubsets(nums, i, path, partition_id, partition_count, sum, visited, search_map))
                {
                    return true;
                }
                // otherwise next candidate
                path[partition_id].pop_back();
                visited[i] = 0;
            }
        }
    }

    // no possible solution
    search_map[signature] = 0;
    return false;
}

/// <summary>
/// Leet code #698. Partition to K Equal Sum Subsets
/// Given an array of integers nums and a positive integer k, find whether 
/// it's possible to divide this array into k non-empty subsets whose sums 
/// are all equal.
///
/// Example 1:
/// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
/// Output: True
/// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), 
/// (2,3), (2,3) with equal sums.
/// Note:
///
/// 1 <= k <= len(nums) <= 16.
/// 0 < nums[i] < 10000.
/// </summary>
bool LeetCode::canPartitionKSubsets(vector<int>& nums, int k)
{
    vector<vector<int>> path(k, vector<int>());
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if ((sum % k) != 0) return false;
    sum /= k;
    unordered_map<string, int> search_map;
    vector<int> visited(nums.size());
    sort(nums.begin(), nums.end());
    return buildPartitionKSubsets(nums, 0, path, 0, k, sum, visited, search_map);
}

/// <summary>
/// Leet code #691. Stickers to Spell Word
///
/// search target
/// </summary>
int LeetCode::searchTarget(vector<vector<int>>&sticker_chars, vector<bool>& sticker_visited, string& target,
    unordered_map<string, int> &cache)
{
    int result = -1;
    // we resolve the target
    if (target.empty()) return 0;
    if (cache.count(target) > 0) return cache[target];

    for (size_t i = 0; i < sticker_chars.size(); i++)
    {
        if (sticker_visited[i]) continue;
        if (sticker_chars[i][target[0] - 'a'] == 0) continue;
        string temp = target;
        reduceTarget(sticker_chars[i], temp);
        int temp_result = searchTarget(sticker_chars, sticker_visited, temp, cache);
        if (temp_result == -1)
        {
            break;
        }
        else
        {
            if (result == -1)
            {
                result = 1 + temp_result;
            }
            else
            {
                result = min(result, 1 + temp_result);
            }
        }
    }
    cache[target] = result;
    return result;
}

/// <summary>
/// Leet code #691. Stickers to Spell Word
///
/// check dominated stickers
/// </summary>
void LeetCode::checkDominatedStickers(vector<vector<int>>&sticker_chars, vector<bool>& sticker_visited)
{
    for (size_t i = 0; i < sticker_chars.size(); i++)
    {
        for (size_t j = 0; j < sticker_chars.size(); j++)
        {
            if (i == j) continue;
            // if two stickers are same, remove the front one
            if (sticker_chars[i] == sticker_chars[j])
            {
                if (i < j) sticker_visited[i] = true;
                break;
            }
            // otherwise check if sticker[i] belong to sticker[j]
            sticker_visited[i] = true;
            for (size_t k = 0; k < 26; k++)
            {
                if (sticker_chars[i][k] > sticker_chars[j][k])
                {
                    sticker_visited[i] = false;
                    break;
                }
            }
            if (sticker_visited[i]) break;
        }
    }
}

/// <summary>
/// Leet code #691. Stickers to Spell Word
///
/// Convert string to characters count
/// </summary>
void LeetCode::convertStringToCharCount(string& word, vector<int>&char_count, vector<int>& target_count)
{
    for (char ch : word)
    {
        if (target_count.empty() || target_count[ch - 'a'] > 0)
        {
            char_count[ch - 'a']++;
        }
    }
}


/// <summary>
/// Leet code #691. Stickers to Spell Word
///
/// reduce the target by sticker
/// </summary>
void LeetCode::reduceTarget(vector<int>&sticker_count, string &target)
{
    string buffer;
    vector<int> target_count(26);
    for (char ch : target)
    {
        int index = ch - 'a';
        target_count[index]++;
        if (target_count[index] > sticker_count[index]) buffer.push_back(ch);
    }
    target = buffer;
}

/// <summary>
/// Leet code #691. Stickers to Spell Word
///
/// We are given N different types of stickers. Each sticker has a 
/// lowercase English word on it.
///
/// You would like to spell out the given target string by cutting 
/// individual letters from your collection of stickers and rearranging 
/// them.
///
/// You can use each sticker more than once if you want, and you have 
/// infinite quantities of each sticker.
///  
/// What is the minimum number of stickers that you need to spell out the 
/// target? If the task is impossible, return -1.
/// 
/// Example 1:
///
/// Input:
///
/// ["with", "example", "science"], "thehat"
/// Output:
///
/// 3
/// Explanation:
///
/// We can use 2 "with" stickers, and 1 "example" sticker.
/// After cutting and rearrange the letters of those stickers, we can form 
/// the target "thehat".
/// Also, this is the minimum number of stickers necessary to form the 
/// target string.
///
/// Example 2:
///
/// Input:
///
/// ["notice", "possible"], "basicbasic"
/// Output:
///
/// -1
/// Explanation:
///
/// We can't form the target "basicbasic" from cutting letters from the 
/// given stickers.
/// Note:
///
/// stickers has length in the range [1, 50].
/// stickers consists of lowercase English words (without apostrophes).
/// target has length in the range [1, 15], and consists of lowercase 
/// English letters.
/// In all test cases, all words were chosen randomly from the 1000 most 
/// common US English words, and the target was chosen as a concatenation 
/// of two random words.
/// The time limit may be more challenging than usual. It is expected 
/// that a 50 sticker test case can be solved within 35ms on average.
/// </summary>
int LeetCode::minStickers(vector<string>& stickers, string target)
{
    int result = 0;

    vector<vector<int>> sticker_chars(stickers.size(), vector<int>(26));
    vector<int> target_chars(26), dummy;
    vector<bool> sticker_visited(stickers.size());
    convertStringToCharCount(target, target_chars, dummy);
    for (size_t i = 0; i < stickers.size(); i++)
    {
        convertStringToCharCount(stickers[i], sticker_chars[i], target_chars);
    }

    checkDominatedStickers(sticker_chars, sticker_visited);
    int index = 0, sticker_count = 0;

    unordered_map<string, int> cache;
    result = searchTarget(sticker_chars, sticker_visited, target, cache);
    return result;
}

/// <summary>
/// Leet code #753. Cracking the Safe
/// </summary>
void LeetCode::crackSafe(string& result, unordered_set<string>& password_set, int n, int k)
{
    size_t total_count = (size_t)pow(k, n);
    if (password_set.size() == total_count) return;
    for (int i = 0; i < k; i++)
    {
        string password;
        result.push_back((char)('0' + i));
        if (result.size() >= (size_t)n)
        {
            password = result.substr(result.size() - n);
            if (password_set.count(password) > 0)
            {
                password.clear();
                result.pop_back();
                continue;
            }
            else
            {
                password_set.insert(password);
            }
        }
        crackSafe(result, password_set, n, k);
        if (password_set.size() == total_count) return;
        if (!password.empty()) password_set.erase(password);
        result.pop_back();
    }
}

/// <summary>
/// Leet code #753. Cracking the Safe
///
/// There is a box protected by a password. The password is n digits, 
/// where each letter can be one of the first k digits 0, 1, ..., k-1.
///
/// You can keep inputting the password, the password will automatically 
/// be matched against the last n digits entered.
///
/// For example, assuming the password is "345", I can open it when I type 
/// "012345", but I enter a total of 6 digits.
///
/// Please return any string of minimum length that is guaranteed to open 
/// the box after the entire string is inputted.
///
/// Example 1:
/// Input: n = 1, k = 2
/// Output: "01"
/// Note: "10" will be accepted too.
/// Example 2:
/// Input: n = 2, k = 2
/// Output: "00110"
/// Note: "01100", "10011", "11001" will be accepted too.
/// Note:
/// 1. n will be in the range [1, 4].
/// 2. k will be in the range [1, 10].
/// 3. k^n will be at most 4096.
/// </summary>
string LeetCode::crackSafe(int n, int k)
{
    string result;
    unordered_set<string> password_set;
    crackSafe(result, password_set, n, k);
    return result;
}

/// <summary>
/// Leet code #756. Pyramid Transition Matrix
/// </summary>
void LeetCode::nextPyramidTop(string& bottom, string &top, unordered_map<char, unordered_map<char, set<char>>> &allowed_map)

{
    char ch = 'A';
    if (!top.empty())
    {
        ch = top.back() + 1;
        top.pop_back();
    }
    while (top.size() < bottom.size() - 1)
    {
        if (allowed_map[bottom[top.size()]][bottom[top.size() + 1]].empty())
        {
            top.clear();
            return;
        }
        for (; ch <= 'Z'; ch++)
        {
            if (allowed_map[bottom[top.size()]][bottom[top.size() + 1]].count(ch) > 0)
            {
                if ((top.empty()) || (!allowed_map[top.back()][ch].empty()))
                {
                    top.push_back(ch);
                    ch = 'A';
                    break;
                }
            }
        }
        if (ch > 'Z')
        {
            if (top.empty()) return;
            ch = top.back() + 1;
            top.pop_back();
        }
    }
    return;
}


/// <summary>
/// Leet code #756. Pyramid Transition Matrix
/// </summary>
bool LeetCode::buildPyramidTransition(string& bottom, unordered_map<char, unordered_map<char, set<char>>> &allowed_map)
{
    if (bottom.size() == 1)
    {
        return true;
    }
    string top;
    while (true)
    {
        nextPyramidTop(bottom, top, allowed_map);
        if (top.empty())
        {
            break;
        }
        if (buildPyramidTransition(top, allowed_map))
        {
            return true;
        }

    }
    return false;
}

/// <summary>
/// Leet code #756. Pyramid Transition Matrix
///
/// We are stacking blocks to form a pyramid. Each block has a color which 
/// is a one letter string, like 'Z'.
///
/// For every block of color 'C' we place not in the bottom row, we are 
/// placing it on top of a left block of color 'A' and right block of 
/// color 'B'. We are allowed to place the block there only if '(A, B, C)' 
/// is an allowed triple.
///
/// We start with a bottom row of bottom, represented as a single string. 
/// We also start with a list of allowed triples allowed. Each allowed 
/// triple is represented as a string of length 3.
///
/// Return true if we can build the pyramid all the way to the top, 
/// otherwise false.
///
/// Example 1:
/// Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
/// Output: true
/// Explanation:
/// We can stack the pyramid like this:
///      A
///     / \
///    D   E
///   / \ / \
///  X   Y   Z
///
/// This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and 
/// ('D', 'E', 'A') are allowed triples.
/// Example 1:
/// Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
/// Output: false
/// Explanation:
/// We can't stack the pyramid to the top.
/// Note that there could be allowed triples (A, B, C) and (A, B, D) 
/// with C != D.
/// Note:
/// 1. bottom will be a string with length in range [2, 100]. 
/// 2. allowed will have length in range [0, 350].
/// 3. Letters in all strings will be chosen from the set 
///    {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
/// </summary>
bool LeetCode::pyramidTransition(string bottom, vector<string>& allowed)
{
    unordered_set<string> top_set;
    unordered_set<string> bottom_set;
    bottom_set.insert(bottom);
    if (bottom.empty()) return false;
    unordered_map<char, unordered_map<char, set<char>>> allowed_map;
    for (size_t i = 0; i < allowed.size(); i++)
    {
        allowed_map[allowed[i][0]][allowed[i][1]].insert(allowed[i][2]);
    }
    unordered_set<string> invalid;
    return buildPyramidTransition(bottom, allowed_map);
}


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
vector<string> LeetCodeDFS::letterCasePermutation(string S)
{
    vector<string> result;
    if (S.empty())
    {
        result.push_back("");
        return result;
    }

    vector<string> sub_result = letterCasePermutation(S.substr(1));
    for (size_t i = 0; i < sub_result.size(); i++)
    {
        string str;
        if (isdigit(S[0]))
        {
            str.push_back(S[0]);
            str.append(sub_result[i]);
            result.push_back(str);
        }
        else if (isalpha(S[0]))
        {
            str.push_back(toupper(S[0]));
            str.append(sub_result[i]);
            result.push_back(str);
            str.clear();
            str.push_back(tolower(S[0]));
            str.append(sub_result[i]);
            result.push_back(str);
        }
    }
    return result;
}

/// <summary>
/// Leet code #797. All Paths From Source to Target
/// </summary>
void LeetCodeDFS::allPathsSourceTarget(vector<vector<int>>& graph, vector<int> &path,
    unordered_set<int> &visited, vector<vector<int>>& result)
{
    if (path.back() == graph.size() - 1)
    {
        result.push_back(path);
        return;
    }
    int current = path.back();
    for (size_t i = 0; i < graph[current].size(); i++)
    {
        int next = graph[current][i];
        if (visited.count(next) == 0)
        {
            path.push_back(next);
            visited.insert(next);
            allPathsSourceTarget(graph, path, visited, result);
            path.pop_back();
            visited.erase(next);
        }
    }
}

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
vector<vector<int>> LeetCodeDFS::allPathsSourceTarget(vector<vector<int>>& graph)
{
    vector<vector<int>> result;
    vector<int> path = { 0 };
    unordered_set<int> visited = { 0 };
    allPathsSourceTarget(graph, path, visited, result);
    return result;
}

/// <summary>
/// Leet code #856. Score of Parentheses
/// </summary>
int LeetCodeDFS::scoreOfParentheses(string S, int &index)
{
    int result = 0;
    index++;
    while (index < (int)S.size())
    {
        if (S[index] == '(') result += scoreOfParentheses(S, index);
        else if (S[index] == ')')
        {
            index++;
            result = (result == 0) ? 1 : result * 2;
            break;
        }
    }
    return result;
}

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
int LeetCodeDFS::scoreOfParentheses(string S)
{
    int index = 0;
    int result = 0;
    while (index < (int)S.size())
    {
        result += scoreOfParentheses(S, index);
    }

    return result;
}

/// <summary>
/// Leet code #489. Robot Room Cleaner
/// </summary>
void LeetCodeDFS::robotClean(vector<vector<int>>& room, int row, int col)
{
    room[row][col] = 2;
}

/// <summary>
/// Leet code #489. Robot Room Cleaner
/// </summary>
bool LeetCodeDFS::robotMove(vector<vector<int>>& room, int &row, int& col, int direction)
{
    vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int next_row = row + directions[direction][0];
    int next_col = col + directions[direction][1];
    if (next_row < 0 || next_row >= (int)room.size() || next_col < 0 || next_col >= (int)room[0].size())
    {
        return false;
    }
    if (room[next_row][next_col] == 0)
    {
        return false;
    }
    row = next_row;
    col = next_col;
    return true;
}

/// <summary>
/// Leet code #489. Robot Room Cleaner
/// </summary>
int LeetCodeDFS::robotTurnRight(int direction)
{
    direction = (direction + 1) % 4;
    return direction;
}

/// <summary>
/// Leet code #489. Robot Room Cleaner
/// </summary>
int LeetCodeDFS::robotTurnLeft(int direction)
{
    direction = (direction + 4 - 1) % 4;
    return direction;
}

/// <summary>
/// Leet code #489. Robot Room Cleaner
/// </summary>
void LeetCodeDFS::robotMoveNext(vector<vector<int>>& room, unordered_map<int, unordered_set<int>>& visited,
    int& row, int& col, int& direction)
{
    for (size_t i = 0; i < 4; i++)
    {
        direction = robotTurnRight(direction);
        if (!robotMove(room, row, col, direction)) continue;
        if (visited[row].count(col) == 0)
        {
            robotClean(room, row, col);
            visited[row].insert(col);
            robotMoveNext(room, visited, row, col, direction);
        }
        robotMoveBack(room, visited, row, col, direction);
    }
    return;
}

/// <summary>
/// Leet code #489. Robot Room Cleaner
/// </summary>
void LeetCodeDFS::robotMoveBack(vector<vector<int>>& room, unordered_map<int, unordered_set<int>>& visited,
    int& row, int& col, int& direction)
{
    direction = robotTurnRight(direction);
    direction = robotTurnRight(direction);
    robotMove(room, row, col, direction);
    direction = robotTurnRight(direction);
    direction = robotTurnRight(direction);
}

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
void LeetCodeDFS::cleanRoom(vector<vector<int>>& room, int row, int col)
{
    unordered_map<int, unordered_set<int>> visited;
    int direction = 0;
    robotClean(room, row, col);
    visited[row].insert(col);
    robotMoveNext(room, visited, row, col, direction);
}

/// <summary>
/// Leet code #980. Unique Paths III
/// </summary>
void LeetCodeDFS::uniquePathsIII(vector<vector<int>>& grid, stack<pair<int, int>> &path, 
    vector<vector<int>>& visited, int &remaining, int &result)
{
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    pair<int, int> pos = path.top();
    for (size_t i = 0; i < directions.size(); i++)
    {
        pair<int, int> next_pos;
        next_pos.first = pos.first + directions[i][0];
        next_pos.second = pos.second + directions[i][1];
        if (next_pos.first < 0 || next_pos.first >= (int)grid.size() ||
            next_pos.second < 0 || next_pos.second >= (int)grid[0].size())
        {
            continue;
        }
        if (visited[next_pos.first][next_pos.second])
        {
            continue;
        }
        if (grid[next_pos.first][next_pos.second] == 0)
        {
            visited[next_pos.first][next_pos.second] = 1;
            path.push(next_pos);
            remaining--;
            uniquePathsIII(grid, path, visited, remaining, result);
            remaining++;
            path.pop();
            visited[next_pos.first][next_pos.second] = 0;
        }
        else if (grid[next_pos.first][next_pos.second] == -1)
        {
            continue;
        }
        else // end
        {
            if (remaining == 0)
            {
                result++;
                break;
            }
            else
            {
                continue;
            }
        }
    }
}

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
int LeetCodeDFS::uniquePathsIII(vector<vector<int>>& grid)
{
    stack<pair<int, int>> path;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
    int remaining = 0;
    int result = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                path.push({ i, j });
                visited[i][j] = 1;
            }
            else if (grid[i][j] == 0)
            {
                remaining++;
            }
        }
    }
    uniquePathsIII(grid, path, visited, remaining, result);
    return result;
}

/// <summary>
/// Leet code #996. Number of Squareful Arrays
/// </summary>
int LeetCodeDFS::numSquarefulPerms(vector<int>& A, vector<int> &path, vector<int> &visited, int &result)
{
    if (path.size() == A.size())
    {
        result++;
        return result;
    }
    for (size_t i = 0; i < A.size(); i++)
    {
        if (visited[i] == 1) continue;
        if (i > 0)
        {
            // duplicate, skip
            if (visited[i - 1] == 0 && A[i - 1] == A[i]) continue;
        }
        if (path.size() > 0)
        {
            int num = A[path.back()] + A[i];
            if ((int)sqrt(num) * (int)sqrt(num) != num) continue;
        }
        path.push_back(i);
        visited[i] = 1;
        numSquarefulPerms(A, path, visited, result);
        path.pop_back();
        visited[i] = 0;
    }
    return result;
}

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
int LeetCodeDFS::numSquarefulPerms(vector<int>& A)
{
    vector<int> path;
    int result = 0;
    vector<int> visited(A.size());
    sort(A.begin(), A.end());
    return numSquarefulPerms(A, path, visited, result);
}

/// <summary>
/// Leet code #1079. Letter Tile Possibilities
/// </summary>
int LeetCodeDFS::numTilePossibilities(string& word, string& tiles, vector<int> &visited)
{
    int result = 0;
    int last = -1;
    for (size_t i = 0; i < tiles.size(); i++)
    {
        // skip duplicates.
        if (last != -1 && tiles[i] == tiles[last]) continue;
        if (visited[i] == 1) continue;
        last = i;
        word.push_back(tiles[i]);
        result++;
        visited[i] = 1;
        result += numTilePossibilities(word, tiles, visited);
        visited[i] = 0;
        word.pop_back();
    }
    return result;
}

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
int LeetCodeDFS::numTilePossibilities(string tiles)
{
    vector<int> visited(tiles.size());
    string word;
    sort(tiles.begin(), tiles.end());
    return numTilePossibilities(word, tiles, visited);
}

/// <summary>
/// Leet code #1087. Brace Expansion
/// </summary>
void LeetCodeDFS::expand(string path, string S, vector<string>& result)
{
    if (S.empty())
    {
        result.push_back(path);
        return;
    }

    vector<char> rep;
    size_t i = 0;
    if (S[0] == '{')
    {
        for (i = 0; S[i] != '}'; i++)
        {
            if (S[i] == ',' || S[i] == '{' || S[i] == '}') continue;
            rep.push_back(S[i]);
        }
    }
    else
    {
        rep.push_back(S[0]);
    }
    S = S.substr(i + 1);
    for (i = 0; i < rep.size(); i++)
    {
        path.push_back(rep[i]);
        expand(path, S, result);
        path.pop_back();
    }
}

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
vector<string> LeetCodeDFS::expand(string S)
{
    vector<string> result;
    string path;
    expand(path, S, result);
    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #1066. Campus Bikes II
/// </summary>
int LeetCodeDFS::assignBikesII(vector<vector<pair<int, int>>> &worker_distance, int worker,
    vector<int> &visited, int sum, unordered_map<int, int>& cache, int& result)
{
    if (worker == worker_distance.size())
    {
        result = min(sum, result);
        return result;
    }
    for (size_t i = 0; i < worker_distance[worker].size(); i++)
    {
        int bike = worker_distance[worker][i].second;
        if (visited[bike] == 1) continue;
        visited[bike] = 1;
        sum += worker_distance[worker][i].first;
        int key = 0;
        for (size_t j = 0; j < visited.size(); j++)
        {
            key = (key << 1) | visited[j];
        }
        if (cache.count(key) == 0 || cache[key] > sum)
        {
            cache[key] = sum;
            result = assignBikesII(worker_distance, worker + 1, visited, sum, cache, result);
        }
        sum -= worker_distance[worker][i].first;
        visited[bike] = 0;
    }
    return result;
}

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
int LeetCodeDFS::assignBikesII(vector<vector<int>>& workers, vector<vector<int>>& bikes)
{
    vector<vector<pair<int, int>>> worker_distance(workers.size());
    for (size_t i = 0; i < workers.size(); i++)
    {
        for (size_t j = 0; j < bikes.size(); j++)
        {
            int distance = std::abs(workers[i][0] - bikes[j][0]) +
                std::abs(workers[i][1] - bikes[j][1]);
            worker_distance[i].push_back(make_pair(distance, j));
        }
        sort(worker_distance[i].begin(), worker_distance[i].end());
    }
    vector<int> visited(bikes.size());
    int sum = 0;
    int result = INT_MAX;
    unordered_map<int, int> cache;
    assignBikesII(worker_distance, 0, visited, sum, cache, result);
    return result;
}


/// <summary>
/// Leet code #1140. Stone Game II
/// </summary>
int LeetCodeDFS::stoneGameII(vector<int>& sum, int start, int M, vector<vector<int>>& memo)
{
    int result = 0;
    if (start + 2 * M >= (int)sum.size() - 1)
    {
        result = sum[sum.size() - 1] - sum[start];
    }
    else if (memo[start][M] > 0)
    {
        result = memo[start][M];
    }
    else
    {
        for (int i = start; i < start + 2 * M; i++)
        {
            result = max(result, sum[i+1] - sum[start] + sum[sum.size() - 1] - sum[i+1] -
                stoneGameII(sum, i + 1, max(i - start + 1, M), memo));
        }
    }
    memo[start][M] = result;
    return result;
}

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
int LeetCodeDFS::stoneGameII(vector<int>& piles)
{
    vector<int> sum;
    sum.push_back(0);
    for (size_t i = 0; i < piles.size(); i++)
    {
        sum.push_back(sum.back() + piles[i]);
    }
    vector<vector<int>> memo(piles.size() + 1, vector<int>(piles.size()));

    return stoneGameII(sum, 0, 1, memo);
}

/// <summary>
/// Leet code #1219. Path with Maximum Gold
/// </summary>
int LeetCodeDFS::getMaximumGold(vector<vector<int>>& grid, int r, int c)
{
    int result = 0;
    if (r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size())
    {
        return result;
    }
    if (grid[r][c] == 0) return result;
    result = grid[r][c];
    grid[r][c] = 0;
    // due to the DFS fact, please do not set directions as local variable.
    int more = 0;
    more = max(more, getMaximumGold(grid, r + 1, c));
    more = max(more, getMaximumGold(grid, r - 1, c));
    more = max(more, getMaximumGold(grid, r, c + 1));
    more = max(more, getMaximumGold(grid, r, c - 1));
    grid[r][c] = result;
    return result + more;
}

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
int LeetCodeDFS::getMaximumGold(vector<vector<int>>& grid)
{
    int result = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            result = max(result, getMaximumGold(grid, i, j));
        }
    }
    return result;
}

/// <summary>
/// Leet code #1240. Tiling a Rectangle with the Fewest Squares
/// </summary>
int LeetCodeDFS::tilingRectangle(int n, int m, vector<int>& heights, unordered_map<long long, int>& shape, int count, int result)
{
    bool isFull = true;
    int min_height = m;
    int pos = 0;
    if (count >= result) return result;

    long long key = 0;
    for (size_t i = 0; i < heights.size(); i++)
    {
        if (heights[i] < m) isFull = false;
        if (heights[i] < min_height)
        {
            pos = i;
            min_height = heights[i];
        }
        key = key * ((long long)m + 1) + (long long)heights[i];
    }
    if (isFull) return count;
    if ((shape.count(key) > 0) && (shape[key] <= count))
    {
        return result;
    }
    shape[key] = count;
    int end = pos;
    for (end = pos; end < n; end++)
    {
        if (heights[end] != heights[pos]) break;
        if (end - pos + 1 > m - heights[pos]) break;
    }
    for (int h = end - pos; h > 0; h--)
    {
        for (int i = pos; i < pos + h; i++)
        {
            heights[i] += h;
        }
        result = min(result, tilingRectangle(n, m, heights, shape, count + 1, result));
        for (int i = pos; i < pos + h; i++)
        {
            heights[i] -= h;
        }
    }
    return result;
}

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
int LeetCodeDFS::tilingRectangle(int n, int m)
{
    if (n == m) return 1;
    else if (n < m) std::swap(n, m);
    vector<int> heights(n);
    unordered_map<long long, int>shape;
    int result = tilingRectangle(n, m, heights, shape, 0, m*n);
    return result;
}

/// <summary>
/// Leetcode #1307. Verbal Arithmetic Puzzle
/// </summary>
bool LeetCodeDFS::isSolvable(vector<int>& chars, int col, int row, vector<int>& digits,
    vector<string>& reverse_words, string& reverse_result, int sum, int max_len)
{
    if (col == max_len)
    {
        return (sum == 0) ? true : false; 
    }
    if (row == reverse_words.size())
    {
        int letter = reverse_result[col] - 'A';       
        int d = sum % 10;
        if (chars[letter] != -1 && chars[letter] != d)
        {
            return false;
        }
        else
        {
            if (chars[letter] == -1)
            {
                if (digits[d] > 0) return false;
                chars[letter] = d;
            }
            digits[d]++;
            sum = sum / 10;
            bool ret = isSolvable(chars, col + 1, 0, digits, reverse_words, reverse_result, sum, max_len);
            if (ret) return true;
            // revert right digit
            digits[d]--;
            if (digits[d] == 0) chars[letter] = -1;
            return false;
        }
    }
    else
    {
        // exceed the current word length
        if (col >= (int)reverse_words[row].size())
        {
            bool ret = isSolvable(chars, col, row + 1, digits, reverse_words, reverse_result, sum, max_len);
            if (ret) return true;
            else return false;
        }
        else
        {
            int letter = reverse_words[row][col] - 'A';
            if (chars[letter] != -1)
            {
                sum += chars[letter];
                bool ret = isSolvable(chars, col, row + 1, digits, reverse_words, reverse_result, sum, max_len);
                if (ret) return true;
                else
                {
                    sum -= chars[letter];
                    return false;
                }
            }
            else
            {
                for (int i = 0; i < 10; i++)
                {
                    // used?
                    if (digits[i] > 0) continue;
                    digits[i] = 1;
                    chars[letter] = i;
                    sum += chars[letter];
                    bool ret = isSolvable(chars, col, row + 1, digits, reverse_words, reverse_result, sum, max_len);
                    if (ret) return true;
                    else
                    {
                        sum -= chars[letter];
                        digits[i] = 0;
                        chars[letter] = -1;
                    }
                }
                return false;
            }
        }
    }
    return false;
}


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
bool LeetCodeDFS::isSolvable(vector<string>& words, string result)
{
    vector<string> reverse_words;
    string reverse_result = result;
    std::reverse(reverse_result.begin(), reverse_result.end());
    vector<int> digits(10);
    vector<int> chars(26, -1);
    size_t max_len = 0;
    int sum = 0;
    for (string str : words)
    {
        std::reverse(str.begin(), str.end());
        reverse_words.push_back(str);
        max_len = max(max_len, str.size());
    }
    max_len = max(max_len, reverse_result.size());
    return isSolvable(chars, 0, 0, digits, reverse_words, reverse_result, sum, max_len);
}

/// <summary>
/// Leet code #1349. Maximum Students Taking Exam
/// </summary>
int LeetCodeDFS::maxStudents(vector<vector<char>>& seats, int level, vector<vector<int>> &cache)
{
    if (level == seats.size()) return 0;
    int bits = 0;
    vector<int> slots;
    for (size_t i = 0; i < seats[level].size(); i++)
    {
        if (seats[level][i] == '.')
        {
            slots.push_back(i);
            bits = (bits << 1) | 1;
        }
    }

    int result = 0;
    while (bits >= 0)
    {
        int students = 0;
        int bit_set = 1 << slots.size();
        for (size_t i = 0; i < slots.size(); i++)
        {
            bit_set = bit_set >> 1;
            if ((bit_set & bits) == 0) seats[level][slots[i]] = '0';
            else
            {
                    // left has student
                if ((slots[i] > 0 && seats[level][slots[i] - 1] == '1') ||
                    // left front
                    (level > 0 && slots[i] > 0 && seats[level - 1][slots[i] - 1] == '1') ||
                    // right front
                    (level > 0 && slots[i] < (int)seats[0].size() - 1 && seats[level - 1][slots[i] + 1] == '1'))
                {
                    bits = bits ^ bit_set;
                    seats[level][slots[i]] = '0';
                }
                else
                {
                    seats[level][slots[i]] = '1';
                    students++;
                }
            }
        }
        if (cache[level][bits] == -1)
        {
            cache[level][bits] = maxStudents(seats, level + 1, cache);
        }
        result = max(result, students + cache[level][bits]);
        // clean up current positions
        for (size_t i = 0; i < slots.size(); i++) seats[level][slots[i]] = '.';
        bits--;
    }
    return result;
}

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
///
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
///
/// Constraints:
///
/// 1. seats contains only characters '.' and'#'.
/// 2. m == seats.length
/// 3. n == seats[i].length
/// 4. 1 <= m <= 8
/// 5. 1 <= n <= 8
/// </summary>
int LeetCodeDFS::maxStudents(vector<vector<char>>& seats)
{
    vector<vector<int>> cache(seats.size(), vector<int>(256, -1));
    int level = 0;
    int result = maxStudents(seats, level, cache);
    return result;
}

/// <summary>
/// Leet code #1397. Find All Good Strings
/// </summary>
int LeetCodeDFS::findGoodStrings(int index, string& s1, string& s2, string& evil,
    int pre_s1, int pre_s2, int pre_evil, vector<int> &kmp,
    vector<vector<vector<vector<int>>>> &cache)
{
    int M = 1000000007;
    if (pre_evil == evil.size()) return 0;
    if (index == s1.size()) return 1;
    if (cache[index][pre_evil][pre_s1][pre_s2] != -1)
    {
        return cache[index][pre_evil][pre_s1][pre_s2];
    }
    char first = (pre_s1 == 1) ? s1[index] : 'a';
    char last = (pre_s2 == 1) ? s2[index] : 'z';
    int result = 0;
    for (char c = first; c <= last; c++)
    {
        int next_evil = pre_evil;
        while (next_evil > 0 && c != evil[next_evil])
        {
            next_evil = kmp[next_evil - 1];
        }
        if (c == evil[next_evil]) next_evil++;
        int next_s1 = (pre_s1 == 1 && c == first) ? 1 : 0;
        int next_s2 = (pre_s2 == 1 && c == last) ? 1 : 0;
        result += findGoodStrings(index + 1, s1, s2, evil, next_s1,
            next_s2, next_evil, kmp, cache);
        result %= M;
    }
    cache[index][pre_evil][pre_s1][pre_s2] = result;
    return cache[index][pre_evil][pre_s1][pre_s2];
}

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
int LeetCodeDFS::findGoodStrings(int n, string s1, string s2, string evil)
{
    vector<int> kmp(evil.size());
    int i = 1;
    int j = 0;
    while (i < (int)evil.size())
    {
        if (evil[i] == evil[j])
        {
            j++;
            kmp[i] = j;
            i++;
        }
        else if (j == 0)
        {
            kmp[i] = 0;
            i++;
        }
        else
        {
            j = kmp[j - 1];
        }
    }
    vector<vector<vector<vector<int>>>>
        cache(n, vector<vector<vector<int>>>(evil.size(),
            vector<vector<int>>(2, vector<int>(2, -1))));
    return findGoodStrings(0, s1, s2, evil, 1, 1, 0, kmp, cache);
}

/// <summary>
/// Leet code #679. 24 Game
/// </summary>
void LeetCodeDFS::getPoint24Rotation(vector<int>& nums, vector<int>& path, 
    vector<bool>& visited, vector<vector<int>>& result)
{
    if (path.size() == nums.size())
    {
        result.push_back(path);
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (visited[i]) continue;
        path.push_back(nums[i]);
        visited[i] = true;
        getPoint24Rotation(nums, path, visited, result);
        path.pop_back();
        visited[i] = false;
    }
}

/// <summary>
/// Leet code #679. 24 Game
/// </summary>
bool LeetCodeDFS::calculatePoint24(vector<int>& nums)
{
    vector<vector<vector<double>>> dp =
        vector<vector<vector<double>>>(nums.size(), vector <vector<double>>(nums.size(), vector<double>()));
    for (int len = 0; len < 4; len++)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i + len >= nums.size()) continue;
            if (len == 0)
            {
                dp[i][i + len].push_back(nums[i]);
            }
            else
            {
                for (size_t j = i; j < i + len; j++)
                {
                    for (double first : dp[i][j])
                    {
                        for (double second : dp[j + 1][i + len])
                        {
                            dp[i][i + len].push_back(first + second);
                            dp[i][i + len].push_back(first - second);
                            dp[i][i + len].push_back(first * second);
                            if (abs(second) > 0.001) dp[i][i + len].push_back(first / second);
                        }
                    }
                }
            }
        }
    }
    for (double value : dp[0][nums.size() - 1])
    {
        if (abs(value - (double)24.0) < 0.001) return true;
    }
    return false;
}


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
bool LeetCodeDFS::judgePoint24(vector<int>& nums)
{
    vector<bool> visited(nums.size());

    vector<int> path;
    vector<vector<int>> result;
    getPoint24Rotation(nums, path, visited, result);
    for (size_t i = 0; i < result.size(); i++)
    {
        if (calculatePoint24(result[i])) return true;
    }
    return false;
}

/// <summary>
/// Leet code #422. Valid Word Square    
/// 
/// Given a sequence of words, check whether it forms a valid word square. 
/// A sequence of words forms a valid word square if the kth row and column 
/// read the exact same string, where 0 ≤ k < max(numRows, numColumns).
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
bool LeetCodeDFS::validWordSquare(vector<string>& words)
{
    for (size_t i = 0; i < words.size(); i++)
    {
        for (size_t j = 0; j < words[i].size(); j++)
        {
            if (j >= words.size() || i >= words[j].size())
            {
                return false;
            }
            if (words[i][j] != words[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

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
bool LeetCodeDFS::isScramble(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    if (s1 == s2) return true;
    size_t len = s1.size();

    vector<int> alpha_table(26, 0);

    for (size_t i = 0; i < len; i++)
    {
        alpha_table[s1[i] - 'a']++;
    }
    for (size_t i = 0; i < len; i++)
    {
        alpha_table[s2[i] - 'a']--;
    }
    for (size_t i = 0; i < 26; i++)
    {
        if (alpha_table[i] != 0) return false;
    }

    for (size_t i = 1; i < len; i++)
    {
        string sub1 = s1.substr(0, i);
        string sub2 = s1.substr(i, len - i);

        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i, len - i), s2.substr(i, len - i)))
        {
            return true;
        }

        if (isScramble(s1.substr(0, i), s2.substr(len - i, i)) &&
            isScramble(s1.substr(i, len - i), s2.substr(0, len - i)))
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #1595. Minimum Cost to Connect Two Groups of Points
/// </summary>
int LeetCodeDFS::connectTwoGroups(vector<vector<int>>& cost, int index, vector<vector<int>>& cache,
    int mask, vector<int>& min_s1, vector<int>& min_s2)
{
    int result = 0;
    if (index == min_s1.size())
    {
        for (size_t i = 0; i < min_s2.size(); i++)
        {
            int bit = 1 << i;
            if ((mask & bit) == 0)
            {
                result += min_s2[i];
            }
        }
    }
    else
    {
        if (cache[index][mask] == INT_MAX)
        {
            for (size_t i = 0; i < min_s2.size(); i++)
            {
                int bit = 1 << i;
                if (((mask & bit) != 0) && (cost[index][i] != min_s1[index]))
                {
                    continue;
                }
                result = cost[index][i] +
                    connectTwoGroups(cost, index + 1, cache, mask | bit, min_s1, min_s2);
                cache[index][mask] = min(cache[index][mask], result);
            }
        }
        result = cache[index][mask];
    }
    return result;
}

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
int LeetCodeDFS::connectTwoGroups(vector<vector<int>>& cost)
{
    vector<int> min_s1(cost.size(), INT_MAX);
    vector<int> min_s2(cost[0].size(), INT_MAX);
    vector<vector<int>> cache(cost.size(), vector<int>(1 << cost[0].size(), INT_MAX));
    for (size_t i = 0; i < cost.size(); i++)
    {
        for (size_t j = 0; j < cost[0].size(); j++)
        {
            min_s1[i] = min(min_s1[i], cost[i][j]);
            min_s2[j] = min(min_s2[j], cost[i][j]);
        }
    }
    return connectTwoGroups(cost, 0, cache, 0, min_s1, min_s2);
}

/// <summary>
/// Leet code #1593. Split a String Into the Max Number of Unique 
///                  Substrings
/// </summary>
int LeetCodeDFS::maxUniqueSplit(string& s, vector<int>& dels, unordered_set<string>& set)
{
    int start = 0;
    if (!dels.empty()) start = dels.back() + 1;
    if (start == s.size()) return 0;
    int result = -1;
    for (size_t i = start; i < s.size(); i++)
    {
        string sub_str = s.substr(start, i - start + 1);
        if (set.count(sub_str) == 0)
        {
            set.insert(sub_str);
            dels.push_back(i);
            int next = maxUniqueSplit(s, dels, set);
            if (next >= 0)
            {
                result = max(result, 1 + next);
            }
            set.erase(sub_str);
            dels.pop_back();
        }
        if ((int)s.size() - 1 - (int)i < result) break;
    }
    return result;
}


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
int LeetCodeDFS::maxUniqueSplit(string s)
{
    vector<int> dels;
    unordered_set<string> set;
    return maxUniqueSplit(s, dels, set);
}

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
int LeetCodeDFS::maximumRequests(int n, vector<vector<int>>& requests)
{
    int num = 1 << requests.size();
    int result = 0;
    for (int i = 0; i < num; i++)
    {
        vector<int> dp(n);
        int count = 0;
        int bits = i;
        for (size_t j = 0; j < requests.size(); j++)
        {
            if (bits == 0) break;
            if (bits % 2 == 1)
            {
                dp[requests[j][0]]--;
                dp[requests[j][1]]++;
                count++;
            }
            bits /= 2;
        }
        bool b_match = true;
        for (int j = 0; j < n; j++)
        {
            if (dp[j] != 0)
            {
                b_match = false;
                break;
            }
        }
        if (b_match) result = max(result, count);
    }
    return result;
}

/// <summary>
/// Leet code #1655. Distribute Repeating Integers
/// </summary>
bool LeetCodeDFS::canDistribute(vector<int>& nums, vector<int>& quantity, int index)
{
    // we just need first nums.
    if (index >= (int)quantity.size())
    {
        return true;
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        // not enough
        if (nums[i] < quantity[index]) continue;
    
        nums[i] -= quantity[index];
        bool ret = canDistribute(nums, quantity, index+1);
        if (ret) return true;
        nums[i] += quantity[index];
    }
    return false;
}

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
bool LeetCodeDFS::canDistribute(vector<int>& nums, vector<int>& quantity)
{
    unordered_map<int, int> num_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_map[nums[i]]++;
    }
    vector<int> num_count;
    for (auto itr : num_map)
    {
        num_count.push_back(itr.second);
    }
    sort(num_count.begin(), num_count.end(), greater<int>());
    sort(quantity.begin(), quantity.end(), greater<int>());
    if (num_count.size() > quantity.size()) num_count.resize(quantity.size());
    return canDistribute(num_count, quantity, 0);
}

/// <summary>
/// Leet code #1659. Maximize Grid Happiness
/// </summary>
int LeetCodeDFS::getMaxGridHappiness(int i, int j, vector<string>& grid)
{
    int result = 0, delta = 0;
    if (grid[i][j] == 'I')
    {
        result = 120;
        delta = -30;
    }
    else if (grid[i][j] == 'E')
    {
        result = 40;
        delta = 20;
    }
    if (i > 0 && grid[i - 1][j] == 'I') result += delta-30;
    if (j > 0 && grid[i][j-1] == 'I') result += delta - 30;
    if (i > 0 && grid[i - 1][j] == 'E') result += delta + 20;
    if (j > 0 && grid[i][j - 1] == 'E') result += delta + 20;
    return result;
}


/// <summary>
/// Leet code #1659. Maximize Grid Happiness
/// </summary>
int LeetCodeDFS::getMaxGridHappiness(int m, int n, int pos, int introvertsCount,
    int extrovertsCount, int mask, vector<string>& grid,
    vector<vector<vector<vector<int>>>>& cache)
{
    if (pos >= n * m)
    {
        return 0;
    }
    if (cache[pos][mask][introvertsCount][extrovertsCount] != INT_MIN)
    {
        return cache[pos][mask][introvertsCount][extrovertsCount];
    }
    int r = pos / m;
    int c = pos % m;
    int full_mask = 1;
    for (int i = 0; i < m; i++) full_mask = full_mask * 3;
    int next_mask = mask * 3 % full_mask;
    int result = getMaxGridHappiness(m, n, pos + 1, introvertsCount, extrovertsCount, next_mask, grid, cache);
    if (introvertsCount > 0)
    {
        grid[r][c] = 'I';
        int delta = getMaxGridHappiness(r, c, grid);
        int next_mask = mask * 3 % full_mask + 1;
        delta = delta + getMaxGridHappiness(m, n, pos + 1, introvertsCount - 1, extrovertsCount, next_mask, grid, cache);
        result = max(result, delta);
        grid[r][c] = ' ';
    }
    if (extrovertsCount > 0)
    {
        grid[r][c] = 'E';
        int delta = getMaxGridHappiness(r, c, grid);
        int next_mask = mask * 3 % full_mask + 2;
        delta = delta + getMaxGridHappiness(m, n, pos + 1, introvertsCount, extrovertsCount - 1, next_mask, grid, cache);
        result = max(result, delta);
        grid[r][c] = ' ';
    }
    cache[pos][mask][introvertsCount][extrovertsCount] = result;
    return result;
}

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
int LeetCodeDFS::getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount)
{
    vector<string> grid(n, string(m, ' '));
    int full_mask = 1;
    for (int i = 0; i < m; i++) full_mask = full_mask * 3;
    vector<vector<vector<vector<int>>>> cache(n*m,
        vector<vector<vector<int>>>((full_mask),
            vector<vector<int>>(introvertsCount + 1, 
                vector<int>(extrovertsCount + 1, INT_MIN))));

    return getMaxGridHappiness(m, n, 0, introvertsCount, 
        extrovertsCount, 0, grid, cache);
}

/// <summary>
/// Leet code #1681. Minimum Incompatibility
/// </summary>
int LeetCodeDFS::minimumIncompatibility(vector<int>& nums, int n, vector<int>& path, int bitmask, 
    vector<int>& cache)
{
    int diff = 0;
    if (!path.empty() && path.size() % n == 0)
    {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (size_t i = path.size() - n; i < path.size(); i++)
        {
            min_val = min(min_val, nums[path[i]]);
            max_val = max(max_val, nums[path[i]]);
        }
        diff = max_val - min_val;
    }
    if (path.size() == nums.size())
    {
        cache[bitmask] = 0;
        return diff;
    }
    if (path.size() % n == 0 && cache[bitmask] != INT_MAX)
    {
        if (cache[bitmask] == -1) return cache[bitmask];
        else return diff + cache[bitmask];
    }
    int start = 0;
    if (path.size() % n != 0)
    {
        start = path.back() + 1;
    }
    else if (!path.empty())
    {
        start = path[path.size() - n] + 1;
    }
    int tail = INT_MAX;
    for (size_t i = start; i < nums.size(); i++)
    {
        int bit = 1 << i;
        if ((bit & bitmask) != 0) continue;
        if (path.size() % n != 0 && nums[path.back()] == nums[i]) continue;
        path.push_back(i);
        int ret = minimumIncompatibility(nums, n, path, bitmask | bit, cache);
        path.pop_back();
        if (ret != -1) tail = min(tail, ret);
    }
    if (path.size() % n == 0)
    {
        cache[bitmask] = min(cache[bitmask], tail);
        if (cache[bitmask] == INT_MAX)
        {
            cache[bitmask] = -1;
        }
    }
    if (tail == INT_MAX) return -1;
    else return diff + tail;
}


/// <summary>
/// Leet code #1681. Minimum Incompatibility
/// 
/// Hard
/// 
/// You are given an integer array nums​​​ and an integer k. You are asked 
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
int LeetCodeDFS::minimumIncompatibility(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());
    vector<int> cache(1 << nums.size(), INT_MAX);
    vector<int> path;
    int result = minimumIncompatibility(nums, nums.size() / k, path, 0, cache);
    return result;
}

/// <summary>
/// Leet code 1718. Construct the Lexicographically Largest Valid Sequence
/// </summary>
bool LeetCodeDFS::constructDistancedSequence(vector<int>& arr, int index, int bit_mask, int n)
{
    if (index == arr.size()) return true;
    // skip occupied cells
    if (arr[index] != 0)
    {
        return constructDistancedSequence(arr, index + 1, bit_mask, n);
    }
    for (int i = n; i > 0; i--)
    {
        int bit = 1 << i;
        // number already used
        if ((bit_mask & bit) != 0) continue;
        // slot occupied
        if (i != 1)
        {
            if ((index + i >= 2 * n - 1) || (arr[index + i] != 0)) continue;
        }
        bit_mask = bit_mask | bit;
        arr[index] = i;
        if (i != 1) arr[index + i] = i;
        bool ret = constructDistancedSequence(arr, index + 1, bit_mask, n);
        if (ret == true) return ret;
        bit_mask = bit_mask ^ bit;
        arr[index] = 0;
        if (i != 1) arr[index + i] = 0;
    }
    return false;
}

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
vector<int> LeetCodeDFS::constructDistancedSequence(int n)
{
    vector<int> result(2 * n - 1);
    constructDistancedSequence(result, 0, 0, n);
    return result;
}

/// <summary>
/// Leet code 1723. Find Minimum Time to Finish All Jobs
/// </summary>
void LeetCodeDFS::minimumTimeRequired(vector<int>& jobs, int index, vector<int>& workers, int max_time, int& result)
{
    if (index == jobs.size())
    {
        result = min(max_time, result);
        return;
    }
    if (max_time >= result) return;
    unordered_set<int> seen;
    for (size_t i = 0; i < workers.size(); i++)
    {
        if (seen.count(workers[i]) == 0)
        {
            seen.insert(workers[i]);
            workers[i] += jobs[index];
            minimumTimeRequired(jobs, index + 1, workers, max(max_time, workers[i]), result);
            workers[i] -= jobs[index];
        }
    }
}

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
int LeetCodeDFS::minimumTimeRequired(vector<int>& jobs, int k)
{
    vector<int> workers(k);
    int result = INT_MAX;
    sort(jobs.begin(), jobs.end(), greater<int>());
    minimumTimeRequired(jobs, 0, workers, 0, result);
    return result;
}


/// <summary>
/// Leet code 1728. Cat and Mouse II
/// </summary>
bool LeetCodeDFS::canMouseWin(vector<string>& grid, int catJump, int mouseJump,
    vector<int>& cat, vector<int>& mouse, vector<vector<int>>& dirs,
    vector<int>& visited, int turn)
{
    int n = grid.size();
    int m = grid[0].size();
    int pos = (cat[0] * 8 + cat[1]) * 64 * 71 +
        (mouse[0] * 8 + mouse[1]) * 71 + turn;
    if (mouse == cat) return false; //mouse is caught by the cat, losing position for the mouse
    if (turn >= 70) return false;//mouse can't win, it used many moves and it couldnt get the food 
    if (grid[mouse[0]][mouse[1]] == 'F') return true;//winner position, mouse got the food
    if (grid[cat[0]][cat[1]] == 'F') return false;//losing position, cat got the food

    if (visited[pos] != 0)
    {
        return visited[pos] == 1 ? true : false;
    }
    // mouse
    if ((turn % 2) == 0)
    {
        for (size_t d = 0; d < dirs.size(); d++)
        {
            vector<int> next_mouse = mouse;
            for (int k = 0; k <= mouseJump; k++)
            {
                next_mouse[0] = mouse[0] + k * dirs[d][0];
                next_mouse[1] = mouse[1] + k * dirs[d][1];
                // invalid position
                if (next_mouse[0] < 0 || next_mouse[0] >= n ||
                    next_mouse[1] < 0 || next_mouse[1] >= m)
                {
                    break;
                }
                // wall
                if (grid[next_mouse[0]][next_mouse[1]] == '#')
                {
                    break;
                }
                if (canMouseWin(grid, catJump, mouseJump, cat, next_mouse, dirs, visited, turn + 1))
                {
                    visited[pos] = 1;
                    return true;
                }
            }
        }
        visited[pos] = -1;
        return false;
    }
    // cat
    else
    {
        for (size_t d = 0; d < dirs.size(); d++)
        {
            vector<int> next_cat = cat;
            for (int k = 0; k <= catJump; k++)
            {
                next_cat[0] = cat[0] + k * dirs[d][0];
                next_cat[1] = cat[1] + k * dirs[d][1];
                // invalid position
                if (next_cat[0] < 0 || next_cat[0] >= n ||
                    next_cat[1] < 0 || next_cat[1] >= m)
                {
                    break;
                }
                // wall
                if (grid[next_cat[0]][next_cat[1]] == '#')
                {
                    break;
                }
                if (!canMouseWin(grid, catJump, mouseJump, next_cat, mouse, dirs, visited, turn + 1))
                {
                    visited[pos] = -1;
                    return false;
                }
            }
        }
        visited[pos] = 1;
        return true;
    }
}


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
bool LeetCodeDFS::canMouseWin(vector<string>& grid, int catJump, int mouseJump)
{
    vector<int> mouse(2), cat(2);
    vector<int> visited(64 * 64 * 71);
    vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
 
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'C')
            {
                cat[0] = i; cat[1] = j;
            }
            else if (grid[i][j] == 'M')
            {
                mouse[0] = i; mouse[1] = j;
            }
        }
    }
    return canMouseWin(grid, catJump, mouseJump, cat, mouse, dirs, visited, 0);
}

/// <summary>
/// Leet code 1770. Maximum Score from Performing Multiplication Operations
/// </summary>
int LeetCodeDFS::maximumScore(vector<int>& nums, vector<int>& multipliers, int left, int right, vector<vector<int>>& dp)
{
    if (left + right == multipliers.size())
    {
        dp[left][right] = 0;
        return 0;
    }
    if (dp[left][right] != INT_MAX) return dp[left][right];
    int left_score = nums[left] * multipliers[left + right];
    int right_score = nums[nums.size() - 1 - right] * multipliers[left + right];
    int left_max = maximumScore(nums, multipliers, left + 1, right, dp);
    int right_max = maximumScore(nums, multipliers, left, right + 1, dp);
    dp[left][right] = max(left_score + left_max, right_score + right_max);
    return dp[left][right];
}

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
int LeetCodeDFS::maximumScore(vector<int>& nums, vector<int>& multipliers)
{
    int left = 0;
    int right = 0;
    int m = multipliers.size();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MAX));
    return maximumScore(nums, multipliers, 0, 0, dp);
}

/// <summary>
/// Leet code 1799. Maximize Score After N Operations
/// </summary>
int LeetCodeDFS::maxScore(vector<int>& nums, int bitmask, vector<int>& cache)
{
    LeetCodeMath lm;
    int bit = 1;
    int count = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if ((bitmask & (1 << i)) != 0) count++;
    }
    if (count == nums.size()) return 0;
    if (cache[bitmask] != 0) return cache[bitmask];
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if ((bitmask & (1 << i)) != 0) continue;
        bitmask |= (1 << i);
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if ((bitmask & (1 << j)) != 0) continue;
            bitmask |= (1 << j);
            cache[bitmask] = maxScore(nums, bitmask, cache);
            result = max(result, cache[bitmask] + (count / 2 + 1) * (int)lm.gcd(nums[i], nums[j]));
            bitmask ^= (1 << j);
        }
        bitmask ^= (1 << i);
    }
    return result;
}

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
int LeetCodeDFS::maxScore(vector<int>& nums)
{
    vector<int> cache(1 << nums.size());
    return maxScore(nums, 0, cache);
}

/// <summary>
/// Leet code 1766. Tree of Coprimes 
/// </summary>
void LeetCodeDFS::getCoprimes(vector<int>& nums, int node, unordered_map<int, unordered_set<int>>& tree, 
        unordered_map<int, vector<int>>& primes, vector<int>& visited,
        unordered_map<int, list<pair<int, int>>>& ancestors, vector<int> &result, int level)
{
    int my_level = -1;
    for (auto &prime : primes[nums[node]])
    {
        auto &v = ancestors[prime];
        if (!v.empty() && v.front().second > my_level)
        {
            result[node] = v.front().first;
            my_level = v.front().second;
        }
    }
    visited[node] = 1;
    ancestors[nums[node]].push_front(make_pair(node, level));
    for (int child : tree[node])
    {
        if (visited[child] == 1) continue;
        getCoprimes(nums, child, tree, primes, visited, ancestors, result, level + 1);
    }
    ancestors[nums[node]].pop_front();
}

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
vector<int> LeetCodeDFS::getCoprimes(vector<int>& nums, vector<vector<int>>& edges)
{
    unordered_map<int, unordered_set<int>> tree;
    unordered_set<int> num_set(nums.begin(), nums.end());
    unordered_map<int, vector<int>> primes;
    LeetCodeMath lm;
    for (int s1 : num_set)
    {
        for (int s2 : num_set)
        {
            if (lm.gcd(s1, s2) == 1) primes[s1].push_back(s2);
        }
    }
    for (size_t i = 0; i < edges.size(); i++)
    {
        tree[edges[i][0]].insert(edges[i][1]);
        tree[edges[i][1]].insert(edges[i][0]);
    }
    vector<int> visited(nums.size());
    unordered_map<int, list<pair<int, int>>> ancestors;
    vector<int> result(nums.size(), -1);
    getCoprimes(nums, 0, tree, primes, visited, ancestors, result, 0);
    return result;
}

/// <summary>
/// Leet code 1815. Maximum Number of Groups Getting Fresh Donuts
/// </summary>
int LeetCodeDFS::maxHappyGroups(int batchSize, int left, vector<int>& groups, int visited, unordered_map<int, int>& cache)
{
    if (visited == (1 << groups.size()) - 1)
    {
        return 0;
    }
    if (cache.count(visited) > 0) return cache[visited];
    int result = 0;
    int mask = 0;
    for (size_t i = 0; i < groups.size(); i++)
    {
        if (((1 << i) & visited) != 0) continue;
        mask = mask | (1 << (groups[i] % batchSize));
    }
    if ((mask & (1 << left)) != 0) mask = 1 << left;
    for (size_t i = 0; i < groups.size(); i++)
    {
        if (((1 << i) & visited) != 0) continue;
        if ((mask & (1 << (groups[i] % batchSize))) == 0) continue;
        mask ^= (1 << (groups[i] % batchSize));
        visited |= 1 << i;
        result = max(result, maxHappyGroups(batchSize, (left + batchSize - groups[i] % batchSize) % batchSize,
            groups, visited, cache));
        visited ^= 1 << i;
    }
    if (left == 0) result++;
    cache[visited] = result;
    return result;
}


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
int LeetCodeDFS::maxHappyGroups(int batchSize, vector<int>& groups)
{
    int visited = 0;
    unordered_map<int, int> cache;
    return maxHappyGroups(batchSize, 0, groups, visited, cache);
}

#pragma endregion



