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
    bool isSolvable(vector<int>& chars, int index, vector<int>& digits,
        vector<int>& left_count, vector<int>& right_count, 
        int &left_sum, int &right_sum, vector<int> &leading_chars);

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

#pragma endregion
};

/// <summary>
/// Leet code #1286. Iterator for Combination
///
/// Medium
///
/// Design an Iterator class, which has:
///
/// A constructor that takes a string characters of sorted distinct 
/// lowercase English letters and a number combinationLength as arguments.
/// A function next() that returns the next combination of length 
/// combinationLength in lexicographical order.
/// A function hasNext() that returns True if and only if there exists a 
/// next combination.
///
/// Example:
/// CombinationIterator iterator = 
///   new CombinationIterator("abc", 2);  // creates the iterator.
///
/// iterator.next(); // returns "ab"
/// iterator.hasNext(); // returns true
/// iterator.next(); // returns "ac"
/// iterator.hasNext(); // returns true
/// iterator.next(); // returns "bc"
/// iterator.hasNext(); // returns false
/// 
/// Constraints:
/// 1. 1 <= combinationLength <= characters.length <= 15
/// 2. There will be at most 10^4 function calls per test.
/// 3. It's guaranteed that all calls of the function next are valid.
/// </summary>
class CombinationIterator
{
private:
    vector<int> m_index;
    string m_string;
    void move_next(void)
    {
        if (hasNext())
        {
            int pos = m_index.size() - 1;
            while (true)
            {
                m_index[pos]++;
                if (m_index[pos] < (int)m_string.size())
                {
                    pos++;
                    if (pos == (int)m_index.size()) break;
                    else
                    {
                        m_index[pos] = m_index[pos - 1];
                    }
                }
                else
                {
                    pos--;
                    if (pos < 0) break;
                }
            }
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) 
    {
        m_string = characters;
        for (int i = 0; i < combinationLength; i++)
        {
            m_index.push_back(i);
        }
    }

    string next() 
    {
        string result;
        for (size_t i = 0; i < m_index.size(); i++)
        {
            result.push_back(m_string[m_index[i]]);
        }
        move_next();
        return result;
    }

    bool hasNext() 
    {
        if (m_index[0] == m_string.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
#endif  // LeetCodeDFS_H
