#pragma once
#ifndef LeetCodeBFS_H
#define LeetCodeBFS_H
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
class LeetCodeBFS
{
public:
#pragma region BFS

    /// <summary>
    /// Leet code #1197. Minimum Knight Moves
    /// 
    /// In an infinite chess board with coordinates from -infinity to +infinity,
    /// you have a knight at square [0, 0].
    ///
    /// A knight has 8 possible moves it can make, as illustrated below. Each 
    /// move is two squares in a cardinal direction, then one square in an 
    /// orthogonal direction.
    ///
    /// Return the minimum number of steps needed to move the knight to the 
    /// square [x, y].  It is guaranteed the answer exists.
    /// 
    /// Example 1:
    ///
    /// Input: x = 2, y = 1
    /// Output: 1
    /// Explanation: [0, 0] -> [2, 1]
    ///
    /// Example 2:
    /// 
    /// Input: x = 5, y = 5
    /// Output: 4
    /// Explanation: [0, 0] -> [2, 1] -> [4, 2] -> [3, 4] -> [5, 5]
    /// 
    /// Constraints:
    /// 1. |x| + |y| <= 300
    /// </summary>
    int minKnightMoves(int x, int y);

    /// <summary>
    /// Leet code #1215. Stepping Numbers
    /// 
    /// A Stepping Number is an integer such that all of its adjacent digits have 
    /// an absolute difference of exactly 1. For example, 321 is a Stepping Number 
    /// while 421 is not.
    ///
    /// Given two integers low and high, find and return a sorted list of all the 
    /// Stepping Numbers in the range [low, high] inclusive.
    ///
    /// Example 1:
    ///
    /// Input: low = 0, high = 21
    /// Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]
    /// 
    ///
    /// Constraints:
    /// 
    /// 1. 0 <= low <= high <= 2 * 10^9
    /// </summary>
    vector<int> countSteppingNumbers(int low, int high);

    /// <summary>
    /// Leet code #1284. Minimum Number of Flips to Convert Binary Matrix 
    /// to Zero Matrix
    ///
    /// Hard
    ///
    /// Given a m x n binary matrix mat. In one step, you can choose one cell 
    /// and flip it and all the four neighbours of it if they exist (Flip is 
    /// changing 1 to 0 and 0 to 1). A pair of cells are called neighboors if 
    /// they share one edge.
    ///
    /// Return the minimum number of steps required to convert mat to a zero 
    /// matrix or -1 if you cannot.
    ///
    /// Binary matrix is a matrix with all cells equal to 0 or 1 only.
    /// 
    /// Zero matrix is a matrix with all cells equal to 0.
    /// 
    /// Example 1:
    /// 
    /// Input: mat = [[0,0],[0,1]]
    /// Output: 3
    /// Explanation: One possible solution is to flip (1, 0) then (0, 1) and 
    /// finally (1, 1) as shown.
    ///
    /// Example 2:
    /// Input: mat = [[0]]
    /// Output: 0
    /// Explanation: Given matrix is a zero matrix. We don't need to change it.
    /// 
    /// Example 3:
    /// Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
    /// Output: 6
    ///
    /// Example 4:
    ///
    /// Input: mat = [[1,0,0],[1,0,0]]
    /// Output: -1
    /// Explanation: Given matrix can't be a zero matrix
    ///
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[0].length
    /// 3. 1 <= m <= 3
    /// 4. 1 <= n <= 3
    /// 5. mat[i][j] is 0 or 1.
    /// </summary>
    int minFlips(vector<vector<int>>& mat);

    /// <summary>
    /// Leet code #1334. Find the City With the Smallest Number of Neighbors 
    ///                  at a Threshold Distance
    /// 
    /// Medium
    ///
    /// There are n cities numbered from 0 to n-1. Given the array edges 
    /// where edges[i] = [from[i], to[i], weight[i]] represents a bidirectional 
    /// and weighted edge between cities fromi and toi, and given the 
    /// integer distanceThreshold.
    /// 
    /// Return the city with the smallest number of cities that are reachable 
    /// through some path and whose distance is at most distanceThreshold, 
    /// If there are multiple such cities, return the city with the greatest 
    /// number.
    ///
    /// Notice that the distance of a path connecting cities i and j is equal 
    /// to the sum of the edges' weights along that path.
    /// 
    /// Example 1: 
    /// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], 
    /// distanceThreshold = 4
    /// Output: 3
    /// Explanation: The figure above describes the graph. 
    /// The neighboring cities at a distanceThreshold = 4 for each city are:
    /// City 0 -> [City 1, City 2] 
    /// City 1 -> [City 0, City 2, City 3] 
    /// City 2 -> [City 0, City 1, City 3] 
    /// City 3 -> [City 1, City 2] 
    /// Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, 
    /// but we have to return city 3 since it has the greatest number.
    ///
    /// Example 2:
    /// Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],
    /// [3,4,1]], distanceThreshold = 2
    /// Output: 0
    /// Explanation: The figure above describes the graph. 
    /// The neighboring cities at a distanceThreshold = 2 for each city are:
    /// City 0 -> [City 1] 
    /// City 1 -> [City 0, City 4] 
    /// City 2 -> [City 3, City 4] 
    /// City 3 -> [City 2, City 4]
    /// City 4 -> [City 1, City 2, City 3] 
    /// The city 0 has 1 neighboring city at a distanceThreshold = 2.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 100
    /// 2. 1 <= edges.length <= n * (n - 1) / 2
    /// 3. edges[i].length == 3
    /// 4. 0 <= from[i] < to[i] < n
    /// 5. 1 <= weight[i], distanceThreshold <= 10^4
    /// 6. All pairs (from[i], to[i]) are distinct.
    /// </summary>
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold);
#pragma endregion
};
#endif  // LeetCodeBFS_H
