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
    /// Leet code #130. Surrounded Regions   
    /// 
    /// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
    /// A region is captured by flipping all 'O's into 'X's in that surrounded region.
    /// For example,
    /// X X X X
    /// X O O X
    /// X X O X
    /// X O X X
    /// 
    /// After running your function, the board should be: 
    /// X X X X
    /// X X X X
    /// X X X X
    /// X O X X
    /// </summary>
    void solveSurrounding(vector<vector<char>>& board);

    /// <summary>
    /// Leet code #127. Word Ladder   
    ///
    /// Given two words (beginWord and endWord), and a dictionary's word list, 
    /// find the length of shortest 
    /// transformation sequence from beginWord to endWord, such that: 
    /// 1.Only one letter can be changed at a time.
    /// 2.Each intermediate word must exist in the word list.
    /// For example,
    /// Given:
    /// beginWord = "hit"
    /// endWord = "cog"
    /// wordList = ["hot","dot","dog","lot","log"]
    /// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", 
    /// return its length 5.
    /// Note:
    /// Return 0 if there is no such transformation sequence.
    /// All words have the same length.
    /// All words contain only lowercase alphabetic characters.
    /// </summary>
    int wordLadderLength(string beginWord, string endWord, unordered_set<string>& wordList);

    /// <summary>
    /// Leet code #200. Number of Islands
    /// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
    /// An island is surrounded by water and is formed by connecting adjacent lands horizontally 
    /// or vertically. You may assume all four edges of the grid are all surrounded by water.
    /// Example 1:
    /// 11110
    /// 11010
    /// 11000
    /// 00000
    /// Answer : 1
    /// Example 2 :
    /// 11000
    /// 11000
    /// 00100
    /// 00011
    /// Answer : 3
    /// </summary>
    int numIslands(vector<vector<char>>& grid);

    /// <summary>
    /// Leet code #302. Smallest Rectangle Enclosing Black Pixels  
    /// 
    /// An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. 
    /// The black pixels are connected, i.e., there is only one black region. Pixels are connected 
    /// horizontally and vertically. Given the location (x, y) of one of the black pixels, return 
    /// the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
    /// For example, given the following image: 
    /// [
    ///  "0010",
    ///  "0110",
    ///  "0100"
    /// ]
    /// and x = 0, y = 2, 
    /// Return 6. 
    /// </summary>
    int minArea(vector<vector<char>>& image, int x, int y);

    /// <summary>
    /// LeetCode #417. Pacific Atlantic Water Flow
    //
    /// Given an m x n matrix of non-negative integers representing the 
    /// height of each unit cell in a continent, the "Pacific ocean" touches 
    /// the left and top edges of the matrix and the "Atlantic ocean" touches 
    /// the right and bottom edges.
    /// Water can only flow in four directions (up, down, left, or right) from 
    /// a cell to another one with height equal or lower.
    /// Find the list of grid coordinates where water can flow to both the 
    /// Pacific and Atlantic ocean.
    /// Note:
    /// 1.The order of returned grid coordinates does not matter.
    /// 2.Both m and n are less than 150.
    /// Example: 
    /// Given the following 5x5 matrix:
    /// Pacific ~   ~   ~   ~   ~  ~  ~
    ///         ~  1   2   2   3  (5) *
    ///         ~  3   2   3  (4) (4) *
    ///         ~  2   4  (5)  3   1  *
    ///         ~ (6) (7)  1   4   5  *
    ///         ~ (5)  1   1   2   4  *
    ///         *  *   *   *   *   *  * Atlantic
    /// Return:
    /// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions 
    /// with parentheses in above matrix).
    /// </summary>
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix);


    /// <summary>
    /// Leet code #433. Minimum Genetic Mutation
    /// 
    /// A gene string can be represented by an 8-character long string, with 
    /// choices from "A", "C", "G", "T".
    ///
    /// Suppose we need to investigate about a mutation (mutation from "start" 
    /// to "end"), where ONE mutation is defined as ONE single character changed 
    /// in the gene string.
    ///
    /// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
    ///
    /// Also, there is a given gene "bank", which records all the valid gene 
    /// mutations. A gene must be in the bank to make it a valid gene string.
    ///
    /// Now, given 3 things - start, end, bank, your task is to determine 
    /// what is the minimum number of mutations needed to mutate from 
    /// "start" to "end". If there is no such a mutation, return -1.
    ///
    /// Note:
    ///
    /// Starting point is assumed to be valid, so it might not be included in 
    /// the bank.
    /// If multiple mutations are needed, all mutations during in the sequence 
    /// must be valid.
    /// You may assume start and end string is not the same.
    ///
    ///
    /// Example 1:
    /// start: "AACCGGTT"
    /// end:   "AACCGGTA"
    /// bank: ["AACCGGTA"]
    /// return: 1
    /// 
    ///
    /// Example 2:
    /// start: "AACCGGTT"
    /// end:   "AAACGGTA"
    /// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
    /// return: 2
    /// 
    ///
    /// Example 3:
    /// start: "AAAAACCC"
    /// end:   "AACCCCCC"
    /// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
    /// return: 3
    /// </summary>
    int minMutation(string start, string end, vector<string>& bank);

    /// <summary>
    /// Leet code #542. 01 Matrix 
    /// 
    /// Given a matrix consists of 0 and 1, find the distance of the nearest 0 
    /// for each cell.
    ///
    /// The distance between two adjacent cells is 1.
    /// Example 1: 
    /// Input:
    /// 0 0 0
    /// 0 1 0
    /// 0 0 0
    /// Output:
    /// 0 0 0
    /// 0 1 0
    /// 0 0 0
    /// Example 2: 
    /// Input:
    /// 0 0 0
    /// 0 1 0
    /// 1 1 1
    /// Output:
    /// 0 0 0
    /// 0 1 0
    /// 1 2 1
    /// Note:
    /// The number of elements of the given matrix will not exceed 10,000.
    /// There are at least one 0 in the given matrix.
    /// The cells are adjacent in only four directions: up, down, left and right.
    /// </summary>
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #690. Employee Importance
    /// You are given a data structure of employee information, which 
    /// includes the employee's unique id, his importance value and his 
    /// direct subordinates' id.
    ///
    /// For example, employee 1 is the leader of employee 2, and employee 2 
    /// is the leader of employee 3. They have importance value 15, 10 and 5, 
    /// respectively. Then employee 1 has a data structure like [1, 15, [2]], 
    /// and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. 
    /// Note that although employee 3 is also a subordinate of employee 1, 
    /// the relationship is not direct.
    /// 
    /// Now given the employee information of a company, and an employee id, 
    /// you need to return the total importance value of this employee and all
    /// his subordinates.
    ///
    /// Example 1:
    /// Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
    /// Output: 11
    /// Explanation:
    /// Employee 1 has importance value 5, and he has two direct subordinates: 
    /// employee 2 and employee 3. They both have importance value 3. So the 
    /// total importance value of employee 1 is 5 + 3 + 3 = 11.
    /// Note:
    /// One employee has at most one direct leader and may have several 
    /// subordinates.
    /// The maximum number of employees won't exceed 2000.
    /// </summary>
    int getImportance(vector<Employee*> employees, int id);

    /// <summary>
    /// Leet code #733. Flood Fill
    ///
    /// An image is represented by a 2-D array of integers, each integer 
    /// representing the pixel value of the image (from 0 to 65535).
    ///
    /// Given a coordinate (sr, sc) representing the starting pixel 
    /// (row and column) of the flood fill, and a pixel value newColor, 
    /// "flood fill" the image.
    ///
    /// To perform a "flood fill", consider the starting pixel, plus any 
    /// pixels connected 4-directionally to the starting pixel of the same 
    /// color as the starting pixel, plus any pixels connected 4-directionally 
    /// to those pixels (also with the same color as the starting pixel), and 
    /// so on. Replace the color of all of the aforementioned pixels with the 
    /// newColor.
    ///
    /// At the end, return the modified image.
    ///
    /// Example 1:
    /// Input: 
    /// image = [[1,1,1],[1,1,0],[1,0,1]]
    /// sr = 1, sc = 1, newColor = 2
    /// Output: [[2,2,2],[2,2,0],[2,0,1]]
    /// Explanation: 
    /// From the center of the image (with position (sr, sc) = (1, 1)), all 
    /// pixels connected by a path of the same color as the starting pixel are 
    /// colored with the new color.
    /// Note the bottom corner is not colored 2, because it is not 
    /// 4-directionally connected to the starting pixel.
    /// Note:
    ///
    /// The length of image and image[0] will be in the range [1, 50].
    /// The given starting pixel will satisfy 0 <= sr < image.length and 
    /// 0 <= sc < image[0].length.
    /// The value of each color in image[i][j] and newColor will be an 
    /// integer in [0, 65535].
    /// </summary>
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);

    /// <summary>
    /// Leet code #752. Open the Lock
    ///
    /// You have a lock in front of you with 4 circular wheels. Each wheel has 
    /// 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels 
    /// can rotate freely and wrap around: for example we can turn '9' to be 
    /// '0', or '0' to be '9'. Each move consists of turning one wheel one 
    /// slot.
    ///
    /// The lock initially starts at '0000', a string representing the state 
    /// of the 4 wheels.
    ///
    /// You are given a list of deadends dead ends, meaning if the lock 
    /// displays any of these codes, the wheels of the lock will stop turning 
    /// and you will be unable to open it.
    ///
    /// Given a target representing the value of the wheels that will unlock 
    /// the lock, return the minimum total number of turns required to open 
    /// the lock, or -1 if it is impossible.
    ///
    /// Example 1:
    /// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
    /// Output: 6
    /// Explanation:
    /// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> 
    /// "1200" -> "1201" -> "1202" -> "0202".
    /// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> 
    /// "0202" would be invalid,
    /// because the wheels of the lock become stuck after the display 
    /// becomes the dead end "0102".
    /// Example 2:
    /// Input: deadends = ["8888"], target = "0009"
    /// Output: 1
    /// Explanation:
    /// We can turn the last wheel in reverse to move from "0000" -> "0009".
    /// Example 3:
    /// Input: deadends = ["8887","8889","8878","8898","8788","8988","7888",
    /// "9888"], target = "8888"
    /// Output: -1
    /// Explanation:
    /// We can't reach the target without getting stuck.
    /// Example 4:
    /// Input: deadends = ["0000"], target = "8888"
    /// Output: -1
    /// Note:
    /// The length of deadends will be in the range [1, 500].
    /// target will not be in the list deadends.
    /// Every string in deadends and the string target will be a string of 4 
    /// digits from the 10,000 possibilities '0000' to '9999'. 
    /// </summary>
    int openLock(vector<string>& deadends, string target);

    /// <summary>
    /// Leetcode #773. Sliding Puzzle
    ///
    /// On a 2x3 board, there are 5 tiles represented by the integers 1 
    /// through 5, and an empty square represented by 0.
    ///
    /// A move consists of choosing 0 and a 4-directionally adjacent number 
    /// and swapping it.
    ///
    /// The state of the board is solved if and only if the board is 
    /// [[1,2,3],[4,5,0]].
    ///
    /// Given a puzzle board, return the least number of moves required so 
    /// that the state of the board is solved. If it is impossible for the 
    /// state of the board to be solved, return -1.
    ///
    /// Examples:
    ///
    /// Input: board = [[1,2,3],[4,0,5]]
    /// Output: 1
    /// Explanation: Swap the 0 and the 5 in one move.
    ///
    /// Input: board = [[1,2,3],[5,4,0]]
    /// Output: -1
    /// Explanation: No number of moves will make the board solved.
    ///
    /// Input: board = [[4,1,2],[5,0,3]]
    /// Output: 5
    /// Explanation: 5 is the smallest number of moves that solves the board.
    /// An example path:
    /// After move 0: [[4,1,2],[5,0,3]]
    /// After move 1: [[4,1,2],[0,5,3]]
    /// After move 2: [[0,1,2],[4,5,3]]
    /// After move 3: [[1,0,2],[4,5,3]]
    /// After move 4: [[1,2,0],[4,5,3]]
    /// After move 5: [[1,2,3],[4,5,0]]
    ///
    /// Input: board = [[3,2,4],[1,5,0]]
    /// Output: 14
    /// Note:
    /// board will be a 2 x 3 array as described above.
    /// board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
    /// </summary>
    int slidingPuzzle(vector<vector<int>>& board);

    /// <summary>
    /// Leet code #818. Race Car
    /// 
    /// Your car starts at position 0 and speed +1 on an infinite number line.  
    /// (Your car can go into negative positions.)
    ///
    /// Your car drives automatically according to a sequence of instructions 
    /// A (accelerate) and R (reverse).
    ///
    /// When you get an instruction "A", your car does the following: 
    /// position += speed, speed *= 2.
    ///
    /// When you get an instruction "R", your car does the following: if your 
    /// speed is positive then speed = -1 , otherwise speed = 1.  
    /// (Your position stays the same.)
    ///
    /// For example, after commands "AAR", your car goes to positions 
    /// 0->1->3->3, and your speed goes to 1->2->4->-1.
    /// 
    /// Now for some target position, say the length of the shortest sequence 
    /// of instructions to get there.
    ///
    /// Example 1:
    /// Input: 
    /// target = 3
    /// Output: 2
    /// Explanation: 
    /// The shortest instruction sequence is "AA".
    /// Your position goes from 0->1->3.
    /// Example 2:
    /// Input: 
    /// target = 6
    /// Output: 5
    /// Explanation: 
    /// The shortest instruction sequence is "AAARA".
    /// Your position goes from 0->1->3->7->7->6.
    ///
    /// Note:
    /// 1. 1 <= target <= 10000.
    /// </summary>
    int racecar(int target);

    /// <summary>
    /// Leet code #854. K-Similar Strings
    /// 
    /// Strings A and B are K-similar (for some non-negative integer K) if we 
    /// can swap the positions of two letters in A exactly K times so that the 
    /// resulting string equals B.
    ///
    /// Given two anagrams A and B, return the smallest K for which A and B are 
    /// K-similar.
    ///
    /// Example 1:
    /// Input: A = "ab", B = "ba"
    /// Output: 1
    ///
    /// Example 2:
    /// Input: A = "abc", B = "bca"
    /// Output: 2
    ///
    /// Example 3:
    /// Input: A = "abac", B = "baca"
    /// Output: 2

    /// Example 4:
    /// Input: A = "aabc", B = "abca"
    /// Output: 2
    /// Note:
    ///
    /// 1 <= A.length == B.length <= 20
    /// A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 
    /// 'e', 'f'}
    /// </summary>
    int kSimilarity(string A, string B);

    /// <summary>
    /// Leet code #864. Shortest Path to Get All Keys
    /// 
    /// We are given a 2-dimensional grid. "." is an empty cell, "#" is a 
    /// wall, "@" is the starting point, ("a", "b", ...) are keys, and 
    /// ("A", "B", ...) are locks.
    ///
    /// We start at the starting point, and one move consists of walking one 
    /// space in one of the 4 cardinal directions.  We cannot walk outside 
    /// the grid, or walk into a wall.  If we walk over a key, we pick it up. 
    /// We can't walk over a lock unless we have the corresponding key.
    ///
    /// For some 1 <= K <= 6, there is exactly one lowercase and one uppercase 
    /// letter of the first K letters of the English alphabet in the grid.  
    /// This means that there is exactly one key for each lock, and one lock 
    /// for each key; and also that the letters used to represent the keys and 
    /// locks were chosen in the same order as the English alphabet.
    ///
    /// Return the lowest number of moves to acquire all keys.  If it's 
    /// impossible, return -1.
    ///
    /// Example 1:
    /// Input: ["@.a.#","###.#","b.A.B"]
    /// Output: 8
    ///
    /// Example 2:
    /// Input: ["@..aA","..B#.","....b"]
    /// Output: 6
    ///
    /// Note:
    /// 1. 1 <= grid.length <= 30
    /// 2. 1 <= grid[0].length <= 30
    /// 3. grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
    /// 4. The number of keys is in [1, 6].  Each key has a different letter 
    /// and opens exactly one lock.
    /// </summary>
    int shortestPathAllKeys(vector<string>& grid);

    /// <summary>
    /// Leet code #882. Reachable Nodes In Subdivided Graph
    /// 
    /// Starting with an undirected graph (the "original graph") with nodes from 
    /// 0 to N-1, subdivisions are made to some of the edges.
    ///
    /// The graph is given as follows: edges[k] is a list of integer pairs 
    /// (i, j, n) such that (i, j) is an edge of the original graph,
    /// 
    /// and n is the total number of new nodes on that edge. 
    ///
    /// Then, the edge (i, j) is deleted from the original graph, n new nodes 
    /// (x_1, x_2, ..., x_n) are added to the original graph,
    ///
    /// and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n), 
    /// (x_n, j) are added to the original graph.
    ///
    /// Now, you start at node 0 from the original graph, and in each move, you 
    /// travel along one edge. 
    ///
    /// Return how many nodes you can reach in at most M moves.
    /// 
    /// Example 1:
    ///
    /// Input: edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
    /// Output: 13
    /// Explanation: 
    /// The nodes that are reachable in the final graph after M = 6 moves are 
    /// indicated below.
    ///
    /// Example 2:
    ///
    /// Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
    /// Output: 23
    ///
    /// Note:
    ///
    /// 1. 0 <= edges.length <= 10000
    /// 2. 0 <= edges[i][0] < edges[i][1] < N
    /// 3. There does not exist any i != j for which edges[i][0] == edges[j][0] and 
    ///    edges[i][1] == edges[j][1].
    /// 4. The original graph has no parallel edges.
    /// 5. 0 <= edges[i][2] <= 10000
    /// 6. 0 <= M <= 10^9
    /// 7. 1 <= N <= 3000
    /// 8. reachable node is a node that can be travelled to using at most M moves 
    ///    starting from node 0.
    /// </summary>
    int reachableNodes(vector<vector<int>>& edges, int M, int N);

    /// <summary>
    /// Leet code #909. Snakes and Ladders
    /// 
    /// On an N x N board, the numbers from 1 to N*N are written 
    /// boustrophedonically starting from the bottom left of the board, and 
    /// alternating direction each row.  For example, for a 6 x 6 board, the 
    /// numbers are written as follows:
    /// 
    /// You start on square 1 of the board (which is always in the last row 
    /// and first column).  Each move, starting from square x, consists of 
    /// the following:
    ///
    /// You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, 
    /// or x+6, provided this number is <= N*N.
    /// (This choice simulates the result of a standard 6-sided die roll: ie., 
    /// there are always at most 6 destinations.)
    /// If S has a snake or ladder, you move to the destination of that snake 
    /// or ladder.  Otherwise, you move to S.
    /// A board square on row r and column c has a "snake or ladder" if 
    /// board[r][c] != -1.  The destination of that snake or ladder is board[r][c].
    ///
    /// Note that you only take a snake or ladder at most once per move: if the 
    /// destination to a snake or ladder is the start of another snake or ladder, 
    /// you do not continue moving.  (For example, if the board is 
    /// "[[4,-1],[-1,3]]", and on the first move your destination square is "2", 
    /// then you finish your first move at "3", because you do not continue moving
    /// to "4".)
    ///
    /// Return the least number of moves required to reach square N*N.  If it is 
    /// not possible, return -1.
    ///
    /// Example 1:
    ///
    /// Input: [
    /// [-1,-1,-1,-1,-1,-1],
    /// [-1,-1,-1,-1,-1,-1],
    /// [-1,-1,-1,-1,-1,-1],
    /// [-1,35,-1,-1,13,-1],
    /// [-1,-1,-1,-1,-1,-1],
    /// [-1,15,-1,-1,-1,-1]]
    /// Output: 4
    /// Explanation: 
    /// At the beginning, you start at square 1 [at row 5, column 0].
    /// You decide to move to square 2, and must take the ladder to square 15.
    /// You then decide to move to square 17 (row 3, column 5), and must take 
    /// the snake to square 13.
    /// You then decide to move to square 14, and must take the ladder to square 35.
    /// You then decide to move to square 36, ending the game.
    /// It can be shown that you need at least 4 moves to reach the N*N-th square, 
    /// so the answer is 4.
    /// Note:
    ///
    /// 2 <= board.length = board[0].length <= 20
    /// board[i][j] is between 1 and N*N or is equal to -1.
    /// The board square with number 1 has no snake or ladder.
    /// The board square with number N*N has no snake or ladder.
    /// </summary>
    int snakesAndLadders(vector<vector<int>>& board);

    /// <summary>
    /// Leet code #924. Minimize Malware Spread
    /// 
    /// In a network of nodes, each node i is directly connected to another node j 
    /// if and only if graph[i][j] = 1.
    ///
    /// Some nodes initial are initially infected by malware.  Whenever two nodes 
    /// are directly connected and at least one of those two nodes is infected by 
    /// malware, both nodes will be infected by malware.  This spread of malware 
    /// will continue until no more nodes can be infected in this manner.
    ///
    /// Suppose M(initial) is the final number of nodes infected with malware in 
    /// the entire network, after the spread of malware stops.
    ///
    /// We will remove one node from the initial list.  Return the node that if 
    /// removed, would minimize M(initial).  If multiple nodes could be removed to 
    /// minimize M(initial), return such a node with the smallest index.
    ///
    /// Note that if a node was removed from the initial list of infected nodes, 
    /// it may still be infected later as a result of the malware spread.
    ///
    /// Example 1:
    /// Input: graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
    /// Output: 0
    ///
    /// Example 2:
    /// Input: graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
    /// Output: 0
    ///
    /// Example 3:
    /// Input: graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
    /// Output: 1
    /// 
    /// Note:
    /// 
    /// 1. 1 < graph.length = graph[0].length <= 300
    /// 2. 0 <= graph[i][j] == graph[j][i] <= 1
    /// 3. graph[i][i] = 1
    /// 4. 1 <= initial.length < graph.length
    /// 5. 0 <= initial[i] < graph.length
    /// </summary>
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial);

    /// <summary>
    /// Leet code #928. Minimize Malware Spread II
    /// 
    /// In a network of nodes, each node i is directly connected to another node j 
    /// if and only if graph[i][j] = 1.
    ///
    /// Some nodes initial are initially infected by malware.  Whenever two nodes 
    /// are directly connected and at least one of those two nodes is infected by 
    /// malware, both nodes will be infected by malware.  This spread of malware 
    /// will continue until no more nodes can be infected in this manner.
    ///
    /// Suppose M(initial) is the final number of nodes infected with malware in 
    /// the entire network, after the spread of malware stops.
    ///
    /// We will remove one node from the initial list, completely removing it and 
    /// any connections from this node to any other node. Return the node that if 
    /// removed, would minimize M(initial).  If multiple nodes could be removed to 
    /// minimize M(initial), return such a node with the smallest index.
    ///
    /// Note that if a node was removed from the initial list of infected nodes, 
    /// it may still be infected later as a result of the malware spread.
    ///
    /// Example 1:
    /// Input: graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
    /// Output: 0
    ///
    /// Example 2:
    /// Input: graph = [[1,1,0],[1,1,1],[0,1,1]], initial = [0,1]
    /// Output: 1
    ///
    /// Example 3:
    /// Input: graph = [[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]], initial = [0,1]
    /// Output: 1
    /// 
    /// Note:
    /// 
    /// 1. 1 < graph.length = graph[0].length <= 300
    /// 2. 0 <= graph[i][j] == graph[j][i] <= 1
    /// 3. graph[i][i] = 1
    /// 4. 1 <= initial.length < graph.length
    /// 5. 0 <= initial[i] < graph.length
    /// </summary>
    int minMalwareSpreadII(vector<vector<int>>& graph, vector<int>& initial);

    /// <summary>
    /// Leet code #934. Shortest Bridge
    /// </summary>
    int shortestBridgePath(vector<vector<int>>& A);

    /// <summary>
    /// Leet code #934. Shortest Bridge
    /// </summary>
    void shortestBridgeFill(vector<vector<int>>& A, int row, int col);

    /// <summary>
    /// Leet code #934. Shortest Bridge
    /// 
    /// In a given 2D binary array A, there are two islands.  (An island is a 
    /// 4-directionally connected group of 1s not connected to any other 1s.)
    ///
    /// Now, we may change 0s to 1s so as to connect the two islands together 
    /// to form 1 island.
    ///
    /// Return the smallest number of 0s that must be flipped.  (It is guaranteed 
    /// that the answer is at least 1.)
    ///
    /// Example 1:
    ///
    /// Input: [[0,1],[1,0]]
    /// Output: 1
    /// Example 2:
    ///
    /// Input: [[0,1,0],[0,0,0],[0,0,1]]
    /// Output: 2
    ///
    /// Example 3:
    ///
    /// Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
    /// Output: 1
    /// 
    ///
    /// Note:
    ///
    /// 1 <= A.length = A[0].length <= 100
    /// A[i][j] == 0 or A[i][j] == 1
    /// </summary>
    int shortestBridge(vector<vector<int>>& A);

    /// <summary>
    /// Leet code #967. Numbers With Same Consecutive Differences
    /// 
    /// Return all non-negative integers of length N such that the absolute 
    /// difference between every two consecutive digits is K.
    ///
    /// Note that every number in the answer must not have leading zeros except 
    /// for the number 0 itself. For example, 01 has one leading zero and is 
    /// invalid, but 0 is valid.
    ///
    /// You may return the answer in any order.
    /// 
    /// Example 1:
    /// Input: N = 3, K = 7
    /// Output: [181,292,707,818,929]
    /// Explanation: Note that 070 is not a valid number, because it has leading 
    /// zeroes.
    ///
    /// Example 2:
    /// Input: N = 2, K = 1
    /// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
    /// 
    /// Note:
    /// 
    /// 1. 1 <= N <= 9
    /// 2. 0 <= K <= 9
    /// </summary>
    vector<int> numsSameConsecDiff(int N, int K);

    /// <summary>
    /// Leet code #994. Rotting Oranges
    /// 
    /// In a given grid, each cell can have one of three values:
    ///
    /// the value 0 representing an empty cell;
    /// the value 1 representing a fresh orange;
    /// the value 2 representing a rotten orange.
    /// Every minute, any fresh orange that is adjacent (4-directionally) to a 
    /// rotten orange becomes rotten.
    ///
    /// Return the minimum number of minutes that must elapse until no cell has 
    /// a fresh orange.  If this is impossible, return -1 instead.
    ///
    /// Example 1:
    /// 
    /// Input: [[2,1,1],[1,1,0],[0,1,1]]
    /// Output: 4
    ///
    /// Example 2:
    ///
    /// Input: [[2,1,1],[0,1,1],[1,0,1]]
    /// Output: -1
    /// Explanation:  The orange in the bottom left corner (row 2, column 0) 
    /// is never rotten, because rotting only happens 4-directionally.
    ///
    /// Example 3:
    ///
    /// Input: [[0,2]]
    /// Output: 0
    /// Explanation:  Since there are already no fresh oranges at minute 0, the 
    /// answer is just 0.
    /// 
    /// Note:
    ///
    /// 1. 1 <= grid.length <= 10
    /// 2. 1 <= grid[0].length <= 10
    /// 3. grid[i][j] is only 0, 1, or 2.
    /// </summary>
    int orangesRotting(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1020. Number of Enclaves
    /// 
    /// Given a 2D array A, each cell is 0 (representing sea) or 1 (representing 
    /// land)
    ///
    /// A move consists of walking from one land square 4-directionally to another 
    /// land square, or off the boundary of the grid.
    ///
    /// Return the number of land squares in the grid for which we cannot walk off 
    /// the boundary of the grid in any number of moves.  
    ///
    /// Example 1:
    /// Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    /// Output: 3
    /// Explanation: 
    /// There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed 
    /// because its on the boundary.
    ///
    /// Example 2:
    /// Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    /// Output: 0
    /// Explanation: 
    /// All 1s are either on the boundary or can reach the boundary.
    ///  
    /// 
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 500
    /// 2. 1 <= A[i].length <= 500
    /// 3. 0 <= A[i][j] <= 1
    /// 4. All rows have the same size.
    /// </summary>
    int numEnclaves(vector<vector<int>>& A);

    /// <summary>
    /// Leet code #1030. Matrix Cells in Distance Order
    /// 
    /// We are given a matrix with R rows and C columns has cells with integer 
    /// coordinates (r, c), where 0 <= r < R and 0 <= c < C.
    ///
    /// Additionally, we are given a cell in that matrix with coordinates (r0, c0).
    ///
    /// Return the coordinates of all cells in the matrix, sorted by their distance 
    /// from (r0, c0) from smallest distance to largest distance.  Here, the 
    /// distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance,
    /// |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that 
    /// satisfies this condition.)
    /// 
    /// Example 1:
    /// 
    /// Input: R = 1, C = 2, r0 = 0, c0 = 0
    /// Output: [[0,0],[0,1]]
    /// Explanation: The distances from (r0, c0) to other cells are: [0,1]
    ///
    /// Example 2:
    ///
    /// Input: R = 2, C = 2, r0 = 0, c0 = 1
    /// Output: [[0,1],[0,0],[1,1],[1,0]]
    /// Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
    /// The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
    ///
    /// Example 3:
    ///
    /// Input: R = 2, C = 3, r0 = 1, c0 = 2
    /// Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
    /// Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
    /// There are other answers that would also be accepted as correct, such as 
    /// [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
    /// 
    /// Note:
    ///
    /// 1. 1 <= R <= 100
    /// 2. 1 <= C <= 100
    /// 3. 0 <= r0 < R
    /// 4. 0 <= c0 < C
    /// </summary>
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0);

    /// <summary>
    /// Leet code #1034. Coloring A Border
    /// 
    /// Given a 2-dimensional grid of integers, each value in the grid represents 
    /// the color of the grid square at that location.
    ///
    /// Two squares belong to the same connected component if and only if they have 
    /// the same color and are next to each other in any of the 4 directions.
    ///
    /// The border of a connected component is all the squares in the connected 
    /// component that are either 4-directionally adjacent to a square not in the 
    /// component, or on the boundary of the grid (the first or last row or column).
    ///
    /// Given a square at location (r0, c0) in the grid and a color, color the border 
    /// of the connected component of that square with the given color, and return 
    /// the final grid.
    ///
    /// Example 1:
    /// 
    /// Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
    /// Output: [[3, 3], [3, 2]]
    /// Example 2:
    /// 
    /// Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
    /// Output: [[1, 3, 3], [2, 3, 3]]
    /// Example 3:
    ///
    /// Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
    /// Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
    ///  
    /// 
    /// Note:
    /// 
    /// 1. 1 <= grid.length <= 50
    /// 2. 1 <= grid[0].length <= 50
    /// 3. 1 <= grid[i][j] <= 1000
    /// 4. 0 <= r0 < grid.length
    /// 5. 0 <= c0 < grid[0].length
    /// 6. 1 <= color <= 1000
    /// </summary>
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color);

    /// <summary>
    /// Leet code #1042. Flower Planting With No Adjacent
    /// 
    /// You have N gardens, labelled 1 to N.  In each garden, you want to plant 
    /// one of 4 types of flowers.
    ///
    /// paths[i] = [x, y] describes the existence of a bidirectional path from 
    /// garden x to garden y.
    ///
    /// Also, there is no garden that has more than 3 paths coming into or leaving 
    /// it.
    ///
    /// Your task is to choose a flower type for each garden such that, for any 
    /// two gardens connected by a path, they have different types of flowers.
    ///
    /// Return any such a choice as an array answer, where answer[i] is the type 
    /// of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 
    /// 2, 3, or 4.  It is guaranteed an answer exists.
    ///
    /// Example 1:
    ///
    /// Input: N = 3, paths = [[1,2],[2,3],[3,1]]
    /// Output: [1,2,3]
    ///
    /// Example 2:
    ///
    /// Input: N = 4, paths = [[1,2],[3,4]]
    /// Output: [1,2,1,2]
    ///
    /// Example 3:
    ///
    /// Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
    /// Output: [1,2,3,4]
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= N <= 10000
    /// 2. 0 <= paths.size <= 20000
    /// 3. No garden has 4 or more paths coming into or leaving it.
    /// 4. It is guaranteed an answer exists.
    /// </summary>
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths);

    /// <summary>
    /// Leet code #1091. Shortest Path in Binary Matrix
    /// 
    /// In an N by N square grid, each cell is either empty (0) or blocked (1).
    ///
    /// A clear path from top-left to bottom-right has length k if and only if 
    /// it is composed of cells C_1, C_2, ..., C_k such that:
    ///
    /// Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., 
    /// they are different and share an edge or corner)
    /// C_1 is at location (0, 0) (ie. has value grid[0][0])
    /// C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
    /// If C_i is located at (r, c), then grid[r][c] is empty 
    /// (ie. grid[r][c] == 0).
    /// Return the length of the shortest such clear path from top-left to 
    /// bottom-right.  If such a path does not exist, return -1.
    ///
    /// Example 1:
    /// Input: [[0,1],[1,0]]
    /// Output: 2
    ///
    /// Example 2:
    /// Input: [[0,0,0],[1,1,0],[1,1,0]]
    /// Output: 4
    ///
    /// Note:
    /// 1. 1 <= grid.length == grid[0].length <= 100
    /// 2. grid[r][c] is 0 or 1
    /// </summary>
    int shortestPathBinaryMatrix(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1162. As Far from Land as Possible
    /// 
    /// Given an N x N grid containing only values 0 and 1, where 0 represents 
    /// water and 1 represents land, find a water cell such that its distance 
    /// to the nearest land cell is maximized and return the distance.
    /// The distance used in this problem is the Manhattan distance: the distance 
    /// between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
    /// If no land or water exists in the grid, return -1.
    /// 
    /// Example 1:
    ///
    /// Input: [[1,0,1],[0,0,0],[1,0,1]]
    /// Output: 2
    /// Explanation: 
    /// The cell (1, 1) is as far as possible from all the land with distance 2.
    ///
    /// Example 2:
    ///
    /// Input: [[1,0,0],[0,0,0],[0,0,0]]
    /// Output: 4
    /// Explanation: 
    /// The cell (2, 2) is as far as possible from all the land with distance 4.
    /// 
    /// Note:
    /// 1. 1 <= grid.length == grid[0].length <= 100
    /// 2. grid[i][j] is 0 or 1
    /// </summary>
    int maxLandDistance(vector<vector<int>>& grid);

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

    /// <summary>
    /// Leet code #1391. Check if There is a Valid Path in a Grid
    /// 
    /// Medium
    ///
    /// Given a m x n grid. Each cell of the grid represents a street. The 
    /// street of grid[i][j] can be:
    /// 1 which means a street connecting the left cell and the right cell. 
    /// 2 which means a street connecting the upper cell and the lower cell.
    /// 3 which means a street connecting the left cell and the lower cell.
    /// 4 which means a street connecting the right cell and the lower cell.
    /// 5 which means a street connecting the left cell and the upper cell.
    /// 6 which means a street connecting the right cell and the upper cell.
    /// You will initially start at the street of the upper-left cell (0,0). 
    /// A valid path in the grid is a path which starts from the upper left 
    /// cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The 
    /// path should only follow the streets.
    ///
    /// Notice that you are not allowed to change any street.
    /// Return true if there is a valid path in the grid or false otherwise.
    /// 
    /// Example 1:
    /// Input: grid = [[2,4,3],[6,5,2]]
    /// Output: true
    /// Explanation: As shown you can start at cell (0, 0) and visit all the 
    /// cells of the grid to reach (m - 1, n - 1).
    ///
    /// Example 2:
    /// Input: grid = [[1,2,1],[1,2,1]]
    /// Output: false
    /// Explanation: As shown you the street at cell (0, 0) is not connected 
    /// with any street of any other cell and you will get stuck at cell (0, 0)
    ///
    /// Example 3:
    /// Input: grid = [[1,1,2]]
    /// Output: false
    /// Explanation: You will get stuck at cell (0, 1) and you cannot reach 
    /// cell (0, 2).
    ///
    /// Example 4:
    /// Input: grid = [[1,1,1,1,1,1,3]]
    /// Output: true
    ///
    /// Example 5:
    /// Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
    /// Output: true
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 300
    /// 4. 1 <= grid[i][j] <= 6
    /// </summary>
    bool hasValidPath(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code 1871. Jump Game VII
    ///                  
    /// Medium
    /// 
    /// You are given a 0-indexed binary string s and two integers minJump 
    /// and maxJump. In the beginning, you are standing at index 0, which 
    /// is equal to '0'. You can move from index i to index j if the 
    /// following conditions are fulfilled:
    ///
    /// i + minJump <= j <= min(i + maxJump, s.length - 1), and
    /// s[j] == '0'.
    /// Return true if you can reach index s.length - 1 in s, or false 
    /// otherwise.
    /// 
    /// Example 1:
    /// Input: s = "011010", minJump = 2, maxJump = 3
    /// Output: true
    /// Explanation:
    /// In the first step, move from index 0 to index 3. 
    /// In the second step, move from index 3 to index 5.
    ///
    /// Example 2:
    /// Input: s = "01101110", minJump = 2, maxJump = 3
    /// Output: false
    /// Constraints:
    /// 1. 2 <= s.length <= 10^5
    /// 2. s[i] is either '0' or '1'.
    /// 3. s[0] == '0'
    /// 4. 1 <= minJump <= maxJump < s.length
    /// </summary>
    bool canReach(string s, int minJump, int maxJump);

    /// <summary>
    /// Leet code 2014. Longest Subsequence Repeated k Times
    /// </summary>
    bool longestSubsequenceRepeatedK(string s, string target, int k);

    /// <summary>
    /// Leet code 2014. Longest Subsequence Repeated k Times
    ///                                                
    /// Hard
    /// 
    /// You are given a string s of length n, and an integer k. You are tasked 
    /// to find the longest subsequence repeated k times in string s.
    ///
    /// A subsequence is a string that can be derived from another string by 
    /// deleting some or no characters without changing the order of the 
    /// remaining characters.
    ///
    /// A subsequence seq is repeated k times in the string s if seq * k is a 
    /// subsequence of s, where seq * k represents a string constructed by 
    /// concatenating seq k times.
    ///
    /// For example, "bba" is repeated 2 times in the string "bababcba", 
    /// because the string "bbabba", constructed by concatenating "bba" 2 
    /// times, is a subsequence of the string "bababcba".
    /// Return the longest subsequence repeated k times in string s. If 
    /// multiple such subsequences are found, return the lexicographically 
    /// largest one. If there is no such subsequence, return an empty string.
    /// 
    /// Example 1:
    /// example 1
    /// Input: s = "letsleetcode", k = 2
    /// Output: "let"
    /// Explanation: There are two longest subsequences repeated 2 times: 
    /// "let" and "ete".
    /// "let" is the lexicographically largest one.
    ///
    /// Example 2:
    /// Input: s = "bb", k = 2
    /// Output: "b"
    /// Explanation: The longest subsequence repeated 2 times is "b".
    ///
    /// Example 3:
    /// Input: s = "ab", k = 2
    /// Output: ""
    /// Explanation: There is no subsequence repeated 2 times. Empty 
    /// string is returned.
    ///
    /// Example 4:
    /// Input: s = "bbabbabbbbabaababab", k = 3
    /// Output: "bbbb"
    /// Explanation: The longest subsequence "bbbb" is repeated 3 times 
    /// in "bbabbabbbbabaababab".
    ///
    /// Constraints:
    /// 1. n == s.length
    /// 2. 2 <= n, k <= 2000
    /// 3. 2 <= n < k * 8
    /// 4. s consists of lowercase English letters.
    /// </summary>
    string longestSubsequenceRepeatedK(string s, int k);

    /// <summary>
    /// Leet Code 3387. Maximize Amount After Two Days of Conversions
    /// 
    /// Medium
    ///
    /// You are given a string initialCurrency, and you start with 1.0 of 
    /// initialCurrency.
    ///
    /// You are also given four arrays with currency pairs (strings) and rates 
    /// (real numbers):
    ///
    /// pairs1[i] = [startCurrencyi, targetCurrencyi] denotes that you can 
    /// convert from startCurrencyi to targetCurrencyi at a rate of rates1[i] 
    /// on day 1.
    /// pairs2[i] = [startCurrencyi, targetCurrencyi] denotes that you can 
    /// convert from startCurrencyi to targetCurrencyi at a rate of rates2[i] 
    /// on day 2.
    /// Also, each targetCurrency can be converted back to its corresponding 
    /// startCurrency at a rate of 1 / rate.
    /// You can perform any number of conversions, including zero, using 
    /// rates1 on day 1, followed by any number of additional conversions, 
    /// including zero, using rates2 on day 2.
    ///
    /// Return the maximum amount of initialCurrency you can have after 
    /// performing any number of conversions on both days in order.
    /// Note: Conversion rates are valid, and there will be no contradictions 
    /// in the rates for either day. The rates for the days are independent 
    /// of each other.
    /// 
    /// Example 1:
    /// Input: initialCurrency = "EUR", pairs1 = [["EUR","USD"],
    /// ["USD","JPY"]], rates1 = [2.0,3.0], pairs2 = [["JPY","USD"],
    /// ["USD","CHF"],["CHF","EUR"]], rates2 = [4.0,5.0,6.0]
    ///
    /// Output: 720.00000
    ///
    /// Explanation:
    /// To get the maximum amount of EUR, starting with 1.0 EUR:
    /// On Day 1:
    /// Convert EUR to USD to get 2.0 USD.
    /// Convert USD to JPY to get 6.0 JPY.
    /// On Day 2:
    /// Convert JPY to USD to get 24.0 USD.
    /// Convert USD to CHF to get 120.0 CHF.
    /// Finally, convert CHF to EUR to get 720.0 EUR.
    ///
    /// Example 2:
    /// Input: initialCurrency = "NGN", pairs1 = [["NGN","EUR"]], 
    /// rates1 = [9.0], pairs2 = [["NGN","EUR"]], rates2 = [6.0]
    /// Output: 1.50000
    /// Explanation:
    /// Converting NGN to EUR on day 1 and EUR to NGN using the inverse rate 
    /// on day 2 gives the maximum amount.
    ///
    /// Example 3:
    /// Input: initialCurrency = "USD", pairs1 = [["USD","EUR"]], 
    /// rates1 = [1.0], pairs2 = [["EUR","JPY"]], rates2 = [10.0]
    /// Output: 1.00000
    /// Explanation:
    /// In this example, there is no need to make any conversions on either 
    /// day.
    /// 
    /// Constraints:
    /// 1. 1 <= initialCurrency.length <= 3
    /// 2. initialCurrency consists only of uppercase English letters.
    /// 3. 1 <= n == pairs1.length <= 10
    /// 4. 1 <= m == pairs2.length <= 10
    /// 5. pairs1[i] == [startCurrencyi, targetCurrencyi]
    /// 6. pairs2[i] == [startCurrencyi, targetCurrencyi]
    /// 7. 1 <= startCurrencyi.length, targetCurrencyi.length <= 3
    /// 8. startCurrencyi and targetCurrencyi consist only of uppercase 
    ///    English letters.
    /// 9. rates1.length == n
    /// 10. rates2.length == m
    /// 11. 1.0 <= rates1[i], rates2[i] <= 10.0
    /// 12. The input is generated such that there are no contradictions or 
    ///     cycles in the conversion graphs for either day.
    /// </summary>
    double maxAmount(string initialCurrency,
        vector<vector<string>>& pairs1, vector<double>& rates1,
        vector<vector<string>>& pairs2, vector<double>& rates2);

    /// <summary>
    /// Leet Code 3528. Unit Conversion I
    ///
    /// Medium
    ///
    /// There are n types of units indexed from 0 to n - 1. You are given a 2D 
    /// integer array conversions of length n - 1, where conversions[i] = 
    /// [sourceUniti, targetUniti, conversionFactori]. This indicates that a 
    /// single unit of type sourceUniti is equivalent to conversionFactori units 
    /// of type targetUniti.
    ///
    /// Return an array baseUnitConversion of length n, where 
    /// baseUnitConversion[i] is the number of units of type i equivalent to a 
    /// single unit of type 0. Since the answer may be large, return each 
    /// baseUnitConversion[i] modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: conversions = [[0,1,2],[1,2,3]]
    /// Output: [1,2,6]
    /// Explanation:
    /// Convert a single unit of type 0 into 2 units of type 1 using 
    /// conversions[0].
    /// Convert a single unit of type 0 into 6 units of type 2 using 
    /// conversions[0], then conversions[1].
    ///
    /// Example 2:
    /// Input: conversions = [[0,1,2],[0,2,3],[1,3,4],[1,4,5],[2,5,2],[4,6,3],
    /// [5,7,4]]
    /// Output: [1,2,3,8,10,6,30,24]
    /// Explanation:
    /// Convert a single unit of type 0 into 2 units of type 1 using 
    /// conversions[0].
    /// Convert a single unit of type 0 into 3 units of type 2 using 
    /// conversions[1].
    /// Convert a single unit of type 0 into 8 units of type 3 using 
    /// conversions[0], then conversions[2].
    /// Convert a single unit of type 0 into 10 units of type 4 using 
    /// conversions[0], then conversions[3].
    /// Convert a single unit of type 0 into 6 units of type 5 using 
    /// conversions[1], then conversions[4].
    /// Convert a single unit of type 0 into 30 units of type 6 using 
    /// conversions[0], conversions[3], then conversions[5].
    /// Convert a single unit of type 0 into 24 units of type 7 using 
    /// conversions[1], conversions[4], then conversions[6].
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. conversions.length == n - 1
    /// 3. 0 <= sourceUniti, targetUniti < n
    /// 4. 1 <= conversionFactori <= 109
    /// 5. It is guaranteed that unit 0 can be converted into any other 
    ///    unit through a unique combination of conversions without using 
    ///    any conversions in the opposite direction.
    /// </summary>
    vector<int> baseUnitConversions(vector<vector<int>>& conversions);

    /// <summary>
    /// Leet Code 3535. Unit Conversion II 
    ///
    /// Medium
    ///
    /// There are n types of units indexed from 0 to n - 1.
    ///
    /// You are given a 2D integer array conversions of length n - 1, where 
    /// conversions[i] = [sourceUniti, targetUniti, conversionFactori]. This 
    /// indicates that a single unit of type sourceUniti is equivalent to 
    /// conversionFactori units of type targetUniti.
    ///
    /// You are also given a 2D integer array queries of length q, where 
    /// queries[i] = [unitAi, unitBi].
    ///
    /// Return an array answer of length q where answer[i] is the number of 
    /// units of type unitBi equivalent to 1 unit of type unitAi, and can be 
    /// represented as p/q where p and q are coprime. Return each answer[i] 
    /// as pq-1 modulo 109 + 7, where q-1 represents the multiplicative 
    /// inverse of q modulo 109 + 7.
    /// 
    /// Example 1:
    /// Input: conversions = [[0,1,2],[0,2,6]], queries = [[1,2],[1,0]]
    /// 
    /// Output: [3,500000004]
    /// Explanation:
    ///
    /// In the first query, we can convert unit 1 into 3 units of type 2 using 
    /// the inverse of conversions[0], then conversions[1].
    /// In the second query, we can convert unit 1 into 1/2 units of type 0 using 
    /// the inverse of conversions[0]. We return 500000004 since it is the 
    /// multiplicative inverse of 2.
    ///
    /// Example 2:
    /// Input: conversions = [[0,1,2],[0,2,6],[0,3,8],[2,4,2],[2,5,4],[3,6,3]], 
    /// queries = [[1,2],[0,4],[6,5],[4,6],[6,1]]
    /// Output: [3,12,1,2,83333334]
    /// Explanation:
    /// In the first query, we can convert unit 1 into 3 units of type 2 using 
    /// the inverse of conversions[0], then conversions[1].
    /// In the second query, we can convert unit 0 into 12 units of type 4 using 
    /// conversions[1], then conversions[3].
    /// In the third query, we can convert unit 6 into 1 unit of type 5 using the 
    /// inverse of conversions[5], the inverse of conversions[2], 
    /// conversions[1], then conversions[4].
    /// In the fourth query, we can convert unit 4 into 2 units of type 6 using 
    /// the inverse of conversions[3], the inverse of conversions[1], 
    /// conversions[2], then conversions[5].
    /// In the fifth query, we can convert unit 6 into 1/12 units of type 1 
    /// using the inverse of conversions[5], the inverse of conversions[2], then 
    /// conversions[0]. We return 83333334 since it is the multiplicative inverse 
    /// of 12.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. conversions.length == n - 1
    /// 3. 0 <= sourceUniti, targetUniti < n
    /// 4. 1 <= conversionFactori <= 10^9
    /// 5. 1 <= q <= 10^5
    /// 6. queries.length == q
    /// 7. 0 <= unitAi, unitBi < n
    /// 8. It is guaranteed that unit 0 can be uniquely converted into any other 
    ///    unit through a combination of forward or backward conversions.
    /// </summary>
    vector<int> queryConversions(vector<vector<int>>& conversions, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 3629. Minimum Jumps to Reach End via Prime Teleportation
    ///
    /// Medium
    ///
    /// You are given an integer array nums of length n.
    /// You start at index 0, and your goal is to reach index n - 1.
    /// From any index i, you may perform one of the following operations:
    /// Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
    /// Prime Teleportation: If nums[i] is a prime number p, you may instantly 
    /// jump to any index j != i such that nums[j] % p == 0.
    /// Return the minimum number of jumps required to reach index n - 1.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,4,6]
    /// Output: 2
    /// Explanation:
    /// One optimal sequence of jumps is:
    /// Start at index i = 0. Take an adjacent step to index 1.
    /// At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to 
    /// index i = 3 as nums[3] = 6 is divisible by 2.
    /// Thus, the answer is 2.
    ///
    /// Example 2:
    /// Input: nums = [2,3,4,7,9]
    /// Output: 2
    /// Explanation:
    /// One optimal sequence of jumps is:
    /// Start at index i = 0. Take an adjacent step to index i = 1.
    /// At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to 
    /// index i = 4 since nums[4] = 9 is divisible by 3.
    /// Thus, the answer is 2.
    ///
    /// Example 3:
    /// Input: nums = [4,6,5,8]
    /// Output: 3
    /// Explanation:
    /// Since no teleportation is possible, we move through 0 → 1 → 2 → 3. Thus, 
    /// the answer is 3.
    /// 
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    int minJumps(vector<int>& nums);

    /// <summary>
    /// Leet Code 3666. Minimum Operations to Equalize Binary String
    ///
    /// 
    /// Hard
    ///
    /// You are given a binary string s, and an integer k.
    ///
    /// In one operation, you must choose exactly k different indices and flip 
    /// each '0' to '1' and each '1' to '0'.
    ///
    /// Return the minimum number of operations required to make all characters 
    /// in the string equal to '1'. If it is not possible, return -1.
    ///
    /// Example 1:
    /// Input: s = "110", k = 1
    /// Output: 1
    /// Explanation:
    /// There is one '0' in s.
    /// Since k = 1, we can flip it directly in one operation.
    ///
    /// Example 2:
    /// Input: s = "0101", k = 3
    /// Output: 2
    /// Explanation:
    /// One optimal set of operations choosing k = 3 indices in each operation is:
    /// Operation 1: Flip indices [0, 1, 3]. s changes from "0101" to "1000".
    /// Operation 2: Flip indices [1, 2, 3]. s changes from "1000" to "1111".
    /// Thus, the minimum number of operations is 2.
    ///
    /// Example 3:
    /// Input: s = "101", k = 2
    /// Output: -1
    /// Explanation:
    /// Since k = 2 and s has only one '0', it is impossible to flip exactly k 
    /// indices to make all '1'. Hence, the answer is -1.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. s[i] is either '0' or '1'.
    /// 3. 1 <= k <= s.length
    /// </summary>
    int minOperations(string s, int k);
#pragma endregion
};
#endif  // LeetCodeBFS_H
