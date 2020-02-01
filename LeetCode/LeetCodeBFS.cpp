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
#include "LeetCodeBFS.h"
#pragma region BreadthFirstSearch
/// <summary>
/// Leet code #200. Number of Islands
/// Given a 2d grid map of '1's (land) and '0's (water), count the number of 
/// islands. 
/// An island is surrounded by water and is formed by connecting adjacent lands 
/// horizontally or vertically. You may assume all four edges of the grid are 
/// all surrounded by water.
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
int LeetCodeBFS::numIslands(vector<vector<char>>& grid)
{
    size_t result = 0;
    // search from top to down, then from left to right
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            // if this is land, floodfill it
            if (grid[i][j] == '1')
            {
                result++;
                grid[i][j] = '0';
                queue<pair<int, int>> search;
                search.push({ i, j });
                vector<vector<int>> directions = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
                while (!search.empty())
                {
                    pair<int, int> pos = search.front();
                    search.pop();
                    for (size_t k = 0; k < 4; k++)
                    {
                        pair<int, int> next = pos;
                        next.first += directions[k][0];
                        next.second += directions[k][1];
                        if (next.first < 0 || next.first >= (int)grid.size() ||
                            next.second < 0 || next.second >= (int)grid[0].size())
                        {
                            continue;
                        }
                        if (grid[next.first][next.second] != '1')
                        {
                            continue;
                        }
                        grid[next.first][next.second] = '0';
                        search.push(next);
                    }
                }
            }
        }
    }
    return result;
}

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
vector<pair<int, int>> LeetCodeBFS::pacificAtlantic(vector<vector<int>>& matrix)
{
    vector<pair<int, int>> result;
    if ((matrix.size() == 0) || (matrix[0].size() == 0))  return result;
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<vector<string>> mark_map(rows, vector<string>(columns, "00"));
    queue<pair<int, int>> queue;
    vector<pair<int, int>> directions = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };

    queue.push(make_pair(0, 0));
    mark_map[0][0][1] = 'p';
    queue.push(make_pair(rows - 1, columns - 1));
    mark_map[rows - 1][columns - 1][0] = 'a';

    while (!queue.empty())
    {
        pair<int, int> pair = queue.front();
        queue.pop();
        for (size_t i = 0; i < directions.size(); i++)
        {
            int row = pair.first + directions[i].first;
            int column = pair.second + directions[i].second;
            // out of boundary throw away
            if (row >= rows || row < 0 || column < 0 || column >= columns) continue;
            string prev = mark_map[row][column];
            if (matrix[row][column] >= matrix[pair.first][pair.second])
            {
                mark_map[row][column][1] = (mark_map[row][column][1] == 'p') ? mark_map[row][column][1] : mark_map[pair.first][pair.second][1];
                mark_map[row][column][0] = (mark_map[row][column][0] == 'a') ? mark_map[row][column][0] : mark_map[pair.first][pair.second][0];
            }
            if ((row == 0) || (column == 0)) mark_map[row][column][1] = 'p';
            if ((row == rows - 1) || (column == columns - 1)) mark_map[row][column][0] = 'a';
            if (prev != mark_map[row][column])
            {
                queue.push(make_pair(row, column));
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (mark_map[i][j] == "ap") result.push_back(make_pair(i, j));
        }
    }
    return result;
}

/// <summary>
/// Leet code #127. Word Ladder   
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
/// return its length 5.
/// Note:
/// Return 0 if there is no such transformation sequence.
/// All words have the same length.
/// All words contain only lowercase alphabetic characters.
/// </summary>
int LeetCodeBFS::wordLadderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
    wordList.insert(endWord);
    int step = 1;
    queue<string> word_search;
    word_search.push(beginWord);
    while (!word_search.empty())
    {
        size_t size = word_search.size();
        for (size_t i = 0; i < size; i++)
        {
            string word = word_search.front();
            word_search.pop();
            if (word == endWord) return step;
            for (size_t j = 0; j < word.size(); j++)
            {
                char letter = word[j];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[j] = ch;
                    if (wordList.find(word) != wordList.end())
                    {
                        word_search.push(word);
                        wordList.erase(word);
                    }
                }
                word[j] = letter;
            }
        }
        step++;
    }
    return 0;
}

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
void LeetCodeBFS::solveSurrounding(vector<vector<char>>& board)
{
    queue<pair<int, int>> search_queue;
    if ((board.size() == 0) || board[0].size() == 0) return;
    for (size_t i = 0; i < board[0].size(); i++)
    {
        if (board[0][i] == 'O')
        {
            board[0][i] = '+';
            search_queue.push(make_pair(0, i));
        }
        if (board[board.size() - 1][i] == 'O')
        {
            board[board.size() - 1][i] = '+';
            search_queue.push(make_pair(board.size() - 1, i));
        }
    }
    for (size_t i = 0; i < board.size(); i++)
    {
        if (board[i][0] == 'O')
        {
            board[i][0] = '+';
            search_queue.push(make_pair(i, 0));
        }
        if (board[i][board[0].size() - 1] == 'O')
        {
            board[i][board[0].size() - 1] = '+';
            search_queue.push(make_pair(i, board[0].size() - 1));
        }
    }
    while (!search_queue.empty())
    {
        pair<size_t, size_t> pair = search_queue.front();
        search_queue.pop();
        if (pair.first > 0 && board[pair.first - 1][pair.second] == 'O')
        {
            board[pair.first - 1][pair.second] = '+';
            search_queue.push(make_pair(pair.first - 1, pair.second));

        }
        if (pair.first < board.size() - 1 && board[pair.first + 1][pair.second] == 'O')
        {
            board[pair.first + 1][pair.second] = '+';
            search_queue.push(make_pair(pair.first + 1, pair.second));
        }
        if (pair.second > 0 && board[pair.first][pair.second - 1] == 'O')
        {
            board[pair.first][pair.second - 1] = '+';
            search_queue.push(make_pair(pair.first, pair.second - 1));
        }
        if (pair.second < board[0].size() - 1 && board[pair.first][pair.second + 1] == 'O')
        {
            board[pair.first][pair.second + 1] = '+';
            search_queue.push(make_pair(pair.first, pair.second + 1));
        }
    }
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '+') board[i][j] = 'O';
        }
    }
}

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
int LeetCodeBFS::minArea(vector<vector<char>>& image, int x, int y)
{
    int top = x, bottom = x, left = y, right = y;
    queue<pair<int, int>> process_queue;
    process_queue.push(make_pair(x, y));
    image[x][y] = '0';
    while (!process_queue.empty())
    {
        pair<int, int> point = process_queue.front();
        process_queue.pop();
        if (point.first < top) top = point.first;
        else if (point.first > bottom) bottom = point.first;
        if (point.second < left) left = point.second;
        else if (point.second > right) right = point.second;

        if ((point.first > 0) && (image[point.first - 1][point.second] == '1'))
        {
            process_queue.push(make_pair(point.first - 1, point.second));
            image[point.first - 1][point.second] = '0';
        }
        if ((point.first < (int)image.size() - 1) && (image[point.first + 1][point.second] == '1'))
        {
            process_queue.push(make_pair(point.first + 1, point.second));
            image[point.first + 1][point.second] = '0';
        }
        if ((point.second > 0) && (image[point.first][point.second - 1] == '1'))
        {
            process_queue.push(make_pair(point.first, point.second - 1));
            image[point.first][point.second - 1] = '0';
        }
        if ((point.second < (int)image[0].size() - 1) && (image[point.first][point.second + 1] == '1'))
        {
            process_queue.push(make_pair(point.first, point.second + 1));
            image[point.first][point.second + 1] = '0';
        }
    }
    return (bottom - top + 1) * (right - left + 1);
}

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
vector<vector<int>> LeetCodeBFS::updateMatrix(vector<vector<int>>& matrix)
{
    vector<vector<int>> result;
    if (matrix.empty() || matrix[0].empty()) return result;
    result = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
    queue<pair<int, int>> process_queue;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                result[i][j] = 0;
                process_queue.push(make_pair(i, j));
            }
            else
            {
                result[i][j] = -1;
            }
        }
    }
    int step = 0;
    while (!process_queue.empty())
    {
        step++;
        size_t size = process_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t k = 0; k < 4; k++)
            {
                pair<int, int> pos = process_queue.front();
                if (k == 0) pos.first--;
                else if (k == 1) pos.first++;
                else if (k == 2) pos.second--;
                else pos.second++;

                // out of boundary
                if (pos.first < 0 || pos.second < 0 || pos.first == result.size() || pos.second == result[0].size())
                {
                    continue;
                }
                // if visited
                if (result[pos.first][pos.second] >= 0)
                {
                    continue;
                }
                result[pos.first][pos.second] = step;
                process_queue.push(pos);
            }
            process_queue.pop();
        }
    }
    return result;
}

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
int LeetCodeBFS::getImportance(vector<Employee*> employees, int id)
{
    int result = 0;
    queue<int> employee_queue;
    unordered_map<int, Employee*> employee_map;
    for (size_t i = 0; i < employees.size(); i++)
    {
        employee_map[employees[i]->id] = employees[i];
    }
    employee_queue.push(id);
    while (!employee_queue.empty())
    {
        int employee_id = employee_queue.front();
        employee_queue.pop();
        Employee* employee = employee_map[employee_id];
        if (employee == nullptr) continue;
        result += employee->importance;
        for (int subordinate : employee->subordinates)
        {
            employee_queue.push(subordinate);
        }
    }
    return result;
}

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
vector<vector<int>> LeetCodeBFS::floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor)
{
    queue<pair<int, int>> search_queue;
    vector<vector<int>> result = image;
    vector<vector<int>> visited(image.size(), vector<int>(image[0].size()));
    vector<vector<int>> directions = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
    int oldColor = image[sr][sc];
    visited[sr][sc] = 1;
    search_queue.push(make_pair(sr, sc));
    while (!search_queue.empty())
    {
        pair<int, int> pos = search_queue.front();
        search_queue.pop();
        result[pos.first][pos.second] = newColor;
        for (size_t i = 0; i < directions.size(); i++)
        {
            pair<int, int> new_pos = 
                make_pair(pos.first + directions[i][0], pos.second + directions[i][1]);
            // if new position out of boundary skip it
            if ((new_pos.first < 0) || (new_pos.second < 0) || 
                (new_pos.first >= (int)image.size()) ||
                (new_pos.second >= (int)image[0].size()))
            {
                continue;
            }
            // if color not match skip 
            if (result[new_pos.first][new_pos.second] != oldColor)
            {
                continue;
            }
            // check visited flag, if already set skip
            if (visited[new_pos.first][new_pos.second] == 1)
            {
                continue;
            }
            visited[new_pos.first][new_pos.second] = 1;
            search_queue.push(new_pos);
        }
    }
    return result;
}

/// <summary>
/// Leet code #743. Network Delay Time
///
/// There are N network nodes, labeled 1 to N.
/// Given times, a list of travel times as directed edges 
/// times[i] = (u, v, w), where u is the source node, v is the target 
/// node, and w is the time it takes for a signal to travel from source 
/// to target.
///
/// Now, we send a signal from a certain node K. How long will it take 
/// for all nodes to receive the signal? If it is impossible, return -1.
///
/// Note:
/// 1.N will be in the range [1, 100].
/// 2.K will be in the range [1, N].
/// 3.The length of times will be in the range [1, 6000].
/// 4.All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 
///   1 <= w <= 100.
/// </summary>
int LeetCodeBFS::networkDelayTime(vector<vector<int>>& times, int N, int K)
{
    unordered_map<int, unordered_map<int, int>> travel_time;
    priority_queue<pair<int, int>> travel;
    unordered_map<int, int> visited_node;

    int result = 0;
    for (size_t i = 0; i < times.size(); i++)
    {
        travel_time[times[i][0]][times[i][1]] = times[i][2];
    }
    travel.push(make_pair(0, K));
    while (!travel.empty())
    {
        pair<int, int> destination = travel.top();
        travel.pop();
        int time = -destination.first;
        int next = destination.second;

        if (visited_node.count(next) > 0) continue;
        visited_node[next] = time;
        result = max(result, time);
        for (auto itr : travel_time[next])
        {
            travel.push(make_pair(-(itr.second + time), itr.first));
        }
    }
    if (visited_node.size() == N) return result;
    else return -1;
}

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
int LeetCodeBFS::openLock(vector<string>& deadends, string target)
{
    queue<string> bfs;
    unordered_set<string> visited;
    unordered_set<string> deadset;

    for (string str : deadends) deadset.insert(str);

    int result = 0;
    string lock = "0000";
    if (deadset.count(lock) == 0)
    {
        visited.insert(lock);
        bfs.push(lock);
    }
    while (!bfs.empty())
    {
        size_t size = bfs.size();
        for (size_t i = 0; i < size; i++)
        {
            string lock = bfs.front();
            bfs.pop();
            if (deadset.count(lock) > 0) continue;
            if (lock == target) return result;
            for (size_t j = 0; j < 4; j++)
            {
                for (int k = -1; k <= 1; k += 2)
                {
                    string next = lock;
                    next[j] = '0' + ((next[j] - '0') + k + 10) % 10;
                    if ((deadset.count(lock) == 0) && (visited.count(next) == 0))
                    {
                        visited.insert(next);
                        bfs.push(next);
                    }
                }
            }
        }
        result++;
    }
    return -1;
}

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
int LeetCodeBFS::slidingPuzzle(vector<vector<int>>& board)
{
    set<string> visited;
    queue<string> search_queue;
    string board_str;
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            board_str.push_back('0' + board[i][j]);
        }
    }
    search_queue.push(board_str);
    visited.insert(board_str);
    int result = 0;
    while (!search_queue.empty())
    {
        size_t size = search_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            string curr_board = search_queue.front();
            search_queue.pop();
            if (curr_board == "123450")
            {
                return result;
            }
            int pos = curr_board.find('0');
            vector<int> direction = { -1, 1, -3, 3 };
            for (size_t i = 0; i < direction.size(); i++)
            {
                int next = pos + direction[i];
                if ((next < 0) || (next >= (int)curr_board.size()))
                {
                    continue;
                }
                // two edge cases
                if (pos == 3 && direction[i] == -1) continue;
                if (pos == 2 && direction[i] == 1) continue;
                string next_board = curr_board;
                swap(next_board[pos], next_board[next]);
                if (visited.count(next_board) == 0)
                {
                    search_queue.push(next_board);
                    visited.insert(next_board);
                }
            }
        }
        result++;
    }
    return -1;
}

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
int LeetCodeBFS::racecar(int target)
{
    int N = 1;
    while (N <= target) N <<= 1;

    queue<pair<int, int>> search;
    set<pair<int, int>> visited;
    search.push(make_pair(0, 1));
    visited.insert(make_pair(0, 1));
    int count = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> pos_info = search.front();
            search.pop();
            int pos = pos_info.first;
            int step = pos_info.second;
            if (pos == target) return count;

            int next_pos = pos + step;
            int next_step = step * 2;
            // check goes too far
            if (next_pos >= 0 && next_pos < N)
            {
                search.push(make_pair(next_pos, next_step));
            }

            pos_info.second = pos_info.second < 0 ? 1 : -1;
            if (visited.count(pos_info) == 0)
            {
                search.push(pos_info);
                visited.insert(pos_info);
            }
        }
        count++;
    }
    return -1;
}

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
int LeetCodeBFS::kSimilarity(string A, string B)
{
    int result = 0;
    queue<string> search;
    if (A == B) return result;
    search.push(A);
    while (!search.empty())
    {
        result++;
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            string A = search.front();
            search.pop();
            size_t index = 0;
            while (A[index] == B[index]) index++;
            for (size_t j = index + 1; j < A.size(); j++)
            {
                if ((A[j] != B[j]) && (A[j] == B[index]))
                {
                    string temp = A;
                    swap(temp[index], temp[j]);
                    if (temp == B) return result;
                    else search.push(temp);
                }
            }
        }
    }
    return result;
}

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
int LeetCodeBFS::shortestPathAllKeys(vector<string>& grid)
{
    int key_full = 0;
    vector<vector<unordered_set<int>>>dp(grid.size(), vector<unordered_set<int>>(grid[0].size()));
    int start_x = 0, start_y = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] >= 'a' && grid[i][j] <= 'f') key_full |= 1 << (grid[i][j] - 'a');
            if (grid[i][j] == '@')
            {
                start_x = i;
                start_y = j;
            }
        }
    }
    queue<vector<int>> search;
    search.push({ start_x, start_y,0 });
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int result = 0;
    while (!search.empty())
    {
        result++;
        size_t size = search.size();
        for (size_t index = 0; index < size; index++)
        {
            vector<int> curr = search.front();
            search.pop();
            for (size_t i = 0; i < directions.size(); i++)
            {
                vector<int> next = curr;
                next[0] += directions[i][0];
                next[1] += directions[i][1];
                int x = next[0];
                int y = next[1];
                int key = next[2];
                // out of bound skip
                if (x < 0 || x >= (int)grid.size() || y < 0 || y >= (int)grid[0].size())
                {
                    continue;
                }
                // if this is wall
                if (grid[x][y] == '#')
                {
                    continue;
                }
                // if this is key
                if (grid[x][y] >= 'a' && grid[x][y] <= 'f')
                {
                    key |= 1 << (grid[x][y] - 'a');
                    // collect all the keys?
                    if ((key ^ key_full) == 0) return result;
                }
                else if (grid[x][y] >= 'A' && grid[x][y] <= 'F')
                {
                    int lock = 1 << (grid[x][y] - 'A');
                    // locked
                    if ((key & lock) == 0) continue;
                }
                bool cover = false;
                for (auto k : dp[x][y])
                {
                    if ((k & key ^ key) == 0)
                    {
                        cover = true;
                        break;
                    }
                }
                if (cover == false)
                {
                    dp[x][y].insert(key);
                    search.push({ x, y, key });
                }
            }
        }
    }
    return -1;
}

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
int LeetCodeBFS::minMutation(string start, string end, vector<string>& bank)
{
    vector<int> visited(bank.size());
    int result = 0;
    queue<string> search;
    search.push(start);
    while (!search.empty())
    {
        size_t size = search.size();
        result++;
        for (size_t i = 0; i < size; i++)
        {
            string str = search.front();
            search.pop();
            for (size_t j = 0; j < bank.size(); j++)
            {
                if (visited[j] == 1) continue;
                int count = 0;
                for (size_t k = 0; k < bank[j].size(); k++)
                {
                    if (str[k] != bank[j][k]) count++;
                    if (count > 1) break;
                }
                if (count == 1)
                {
                    search.push(bank[j]);
                    visited[j] = 1;
                    if (bank[j] == end) return result;
                }
            }
        }
    }
    return -1;
}

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
int LeetCodeBFS::reachableNodes(vector<vector<int>>& edges, int M, int N)
{
    int result = 0;
    unordered_map<int, unordered_map<int, int>> edge_nodes;
    vector<int> visited(N);
    for (size_t i = 0; i < edges.size(); i++)
    {
        edge_nodes[edges[i][0]][edges[i][1]] = edges[i][2];
        edge_nodes[edges[i][1]][edges[i][0]] = edges[i][2];
    }

    priority_queue<pair<int, int>>search;
    search.push(make_pair(M, 0));
    while (!search.empty())
    {
        pair<int, int> pos = search.top();
        search.pop();
        int node = pos.second;
        int step = pos.first;
        if (visited[node] == 1) continue;
        result++;
        visited[node] = 1;
        for (auto itr : edge_nodes[node])
        {
            int target_node = itr.first;
            int nodes_in_middle = itr.second;
            if (nodes_in_middle + 1 <= step)
            {
                result += nodes_in_middle;
                if (visited[target_node] == 0)
                {
                    search.push(make_pair(step - nodes_in_middle - 1, target_node));
                    edge_nodes[node][target_node] = 0;
                    edge_nodes[target_node][node] = 0;
                }
            }
            else
            {
                result += step;
                edge_nodes[node][target_node] -= step;
                edge_nodes[target_node][node] -= step;
            }
        }
    }
    return result;
}

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
int LeetCodeBFS::snakesAndLadders(vector<vector<int>>& board)
{
    int N = board.size();
    int row = N - 1;
    int col = 0;
    int step = 1;
    vector<int> matrix(N * N);
    for (int i = 0; i < N * N; i++)
    {
        matrix[i] = board[row][col];
        col += step;
        if (col < 0 || col >= N)
        {
            step = 0 - step;
            row--;
            col += step;
        }
    }
    queue<int> search;
    search.push(0);
    int result = 0;
    while (!search.empty())
    {
        int size = search.size();
        for (int i = 0; i < size; i++)
        {
            int pos = search.front();
            search.pop();
            if (pos == N * N - 1) return result;
            for (int i = pos + 1; (i < pos + 7) && (i < N * N); i++)
            {
                if (matrix[i] == -1)
                {
                    search.push(i);
                    matrix[i] = 0;
                }
                else if (matrix[i] > 0)
                {
                    search.push(matrix[i] - 1);
                    matrix[i] = 0;
                }
            }
        }
        result++;
    }
    return -1;
}

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
int LeetCodeBFS::minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial)
{
    vector<int> flag(graph.size(), -1);
    vector<int> count(graph.size());
    for (size_t i = 0; i < initial.size(); i++)
    {
        queue<int> search;
        search.push(initial[i]);

        if (flag[initial[i]] != -1)
        {
            count[flag[initial[i]]] = 0;
            continue;
        }
        while (!search.empty())
        {
            int node = search.front();
            search.pop();

            for (size_t j = 0; j < graph[node].size(); j++)
            {
                if (graph[node][j] == 1 && flag[j] == -1)
                {
                    flag[j] = initial[i];
                    count[initial[i]] += 1;
                    search.push(j);
                }
            }
        }
    }
    int result = initial[0];
    int reduce = 0;

    for (size_t i = 0; i < initial.size(); i++)
    {
        if ((count[initial[i]] > reduce) || 
            ((count[initial[i]] == reduce) && (initial[i] < result)))
        {
            reduce = count[initial[i]];
            result = initial[i];
        }
    }
    return result;
}

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
///
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
int LeetCodeBFS::minMalwareSpreadII(vector<vector<int>>& graph, vector<int>& initial)
{
    unordered_set<int> virus;
    for (auto v : initial) virus.insert(v);

    vector<int> flag(graph.size(), -1);
    vector<int> count(graph.size());
    for (size_t i = 0; i < initial.size(); i++)
    {
        queue<int> search;
        search.push(initial[i]);

        if (flag[initial[i]] == -1)
        {
            flag[initial[i]] = initial[i];
            count[initial[i]] += 1;
        }
        else if (flag[initial[i]] != -2)
        {
            count[flag[initial[i]]]--;
            flag[initial[i]] = -2;
        }
        else
        {
            continue;
        }
        while (!search.empty())
        {
            int node = search.front();
            search.pop();

            for (size_t j = 0; j < graph[node].size(); j++)
            {
                if (graph[node][j] == 1)
                {
                    if ((flag[j] == -2) || (flag[j] == initial[i]) || (virus.count(j) > 0)) continue;
                    if (flag[j] == -1)
                    {
                        flag[j] = initial[i];
                        count[initial[i]] += 1;
                    }
                    else
                    {
                        count[flag[j]]--;
                        flag[j] = -2;
                    }
                    search.push(j);
                }
            }
        }
    }
    int result = initial[0];
    int reduce = 0;

    for (size_t i = 0; i < initial.size(); i++)
    {
        if ((count[initial[i]] > reduce) || ((count[initial[i]] == reduce) && (initial[i] < result)))
        {
            reduce = count[initial[i]];
            result = initial[i];
        }
    }
    return result;
}

/// <summary>
/// Leet code #934. Shortest Bridge
/// </summary>
int LeetCodeBFS::shortestBridgePath(vector<vector<int>>& A)
{
    queue<pair<int, int>> search;
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] == 2)
            {
                search.push(make_pair(i, j));
            }
        }
    }
    int result = 0;
    vector<vector<int>> direction = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> pos = search.front();
            search.pop();
            for (size_t i = 0; i < direction.size(); i++)
            {
                pair<int, int> next = make_pair(pos.first + direction[i][0], pos.second + direction[i][1]);
                if (next.first < 0 || next.first >= (int)A.size() || 
                    next.second < 0 || next.second >= (int)A[0].size())
                {
                    continue;
                }
                if (A[next.first][next.second] == 1)
                {
                    return result;
                }
                else if (A[next.first][next.second] == 0)
                {
                    A[next.first][next.second] = 2;
                    search.push(next);
                }
            }
        }
        result++;
    }
    return result;
}

/// <summary>
/// Leet code #934. Shortest Bridge
/// </summary>
void LeetCodeBFS::shortestBridgeFill(vector<vector<int>>& A, int row, int col)
{
    queue<pair<int, int>> search;
    search.push({ row, col });
    A[row][col] = 2;

    vector<vector<int>> direction = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!search.empty())
    {
        pair<int, int> pos = search.front();
        search.pop();
      
        for (size_t i = 0; i < direction.size(); i++)
        {
            pair<int, int> next = make_pair(pos.first + direction[i][0], pos.second + direction[i][1]);
            if (next.first < 0 || next.first >= (int)A.size() || 
                next.second < 0 || next.second >= (int)A[row].size())
            {
                continue;
            }
            if (A[next.first][next.second] == 1)
            {
                A[next.first][next.second] = 2;
                search.push(next);
            }
        }
    }
}

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
int LeetCodeBFS::shortestBridge(vector<vector<int>>& A)
{
    queue<vector<int>> first_land;
    bool hit = false;
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] == 1)
            {
                shortestBridgeFill(A, i, j);
                hit = true;
                break;
            }
        }
        if (hit) break;
    }

    return shortestBridgePath(A);
}

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
vector<int> LeetCodeBFS::numsSameConsecDiff(int N, int K)
{
    queue<int> search;
    for (size_t i = 0; i < (size_t) N; i++)
    {
        if (i == 0)
        {
            for (size_t j = 1; j < 10; j++)
            {
                search.push(j);
            }
        }
        else
        {
            size_t size = search.size();
            for (size_t j = 0; j < size; j++)
            {
                int val = search.front();
                search.pop();

                int digit = val % 10;
                if (digit + K < 10) search.push(val * 10 + digit + K);
                // if K == 0 duplicate
                if ((K != 0) && (digit - K >= 0)) search.push(val * 10 + digit - K);
            }
        }
    }
    vector<int> result;
    while (!search.empty())
    {
        result.push_back(search.front());
        search.pop();
    }
    if (N == 1) result.push_back(0);
    return result;
}

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
///
/// Note:
///
/// 1. 1 <= grid.length <= 10
/// 2. 1 <= grid[0].length <= 10
/// 3. grid[i][j] is only 0, 1, or 2.
/// </summary>
int LeetCodeBFS::orangesRotting(vector<vector<int>>& grid)
{
    queue<pair<int, int>> search;
    int count = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                search.push(make_pair(i, j));
            }
            else if (grid[i][j] == 1)
            {
                count++;
            }
        }
    }

    int result = 0;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> pos = search.front();
            search.pop();

            for (size_t d = 0; d < directions.size(); d++)
            {
                pair<int, int> next_pos = pos;
                next_pos.first += directions[d][0];
                next_pos.second += directions[d][1];

                if (next_pos.first < 0 || next_pos.first >= (int)grid.size() ||
                    next_pos.second < 0 || next_pos.second >= (int)grid[0].size())
                {
                    continue;
                }

                if (grid[next_pos.first][next_pos.second] == 1)
                {
                    count--;
                    search.push(make_pair(next_pos.first, next_pos.second));
                    grid[next_pos.first][next_pos.second] = 2;
                }
            }
        }
        if (!search.empty()) result++;
    }
    if (count != 0) result = -1;
    return result;
}

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
/// 
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
int LeetCodeBFS::numEnclaves(vector<vector<int>>& A)
{
    int result = 0;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] == 0) continue;
            A[i][j] = 0;
            queue<pair<int, int>> search;
            search.push(make_pair(i, j));
            bool bound = false;
            int count = 0;
            while (!search.empty())
            {
                pair<int, int> pos = search.front();
                search.pop();
                count++;

                for (size_t d = 0; d < directions.size(); d++)
                {
                    pair<int, int> next = pos;
                    next.first += directions[d][0];
                    next.second += directions[d][1];

                    if (next.first < 0 || next.first >= (int)A.size() ||
                        next.second < 0 || next.second >= (int)A[i].size())
                    {
                        bound = true;
                        continue;
                    }
                    // skip empty cell
                    if (A[next.first][next.second] == 0) continue;
                    search.push(next);
                    A[next.first][next.second] = 0;
                }
            }
            if (bound == false) result += count;
        }
    }
    return result;
}

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
vector<vector<int>> LeetCodeBFS::allCellsDistOrder(int R, int C, int r0, int c0)
{
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    vector<vector<int>> matrix(R, vector<int>(C));
    vector<vector<int>> result;

    queue<vector<int>> search;
    vector<int> cell(2);
    cell[0] = r0;
    cell[1] = c0 ;
    search.push(cell);
    matrix[r0][c0] = 1;
    while (!search.empty())
    {
        vector<int> cell = search.front();
        search.pop();
        result.push_back(cell);
        for (size_t d = 0; d < directions.size(); d++)
        {
            vector<int> next = cell;
            next[0] += directions[d][0];
            next[1] += directions[d][1];
            if (next[0] < 0 || next[0] >= R || next[1] < 0 || next[1] >= C)
            {
                continue;
            }
            if (matrix[next[0]][next[1]] == 1) continue;
            matrix[next[0]][next[1]] = 1;
            search.push(next);
        }
    }
    return result;
}

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
vector<vector<int>> LeetCodeBFS::colorBorder(vector<vector<int>>& grid, int r0, int c0, int color)
{
    vector<vector<int>> result = grid;
    vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size()));
    int origin = grid[r0][c0];
    queue<pair<int, int>> search;
    search.push(make_pair(r0, c0));
    visit[r0][c0] = 1;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!search.empty())
    {
        pair<int, int> pos = search.front();
        search.pop();

        for (size_t d = 0; d < directions.size(); d++)
        {
            pair<int, int> next = pos;
            next.first += directions[d][0];
            next.second += directions[d][1];

            if (next.first < 0 || next.first >= (int)grid.size() ||
                next.second < 0 || next.second >= (int)grid[0].size())
            {
                result[pos.first][pos.second] = color;
            }
            else if (visit[next.first][next.second] == 1)
            {
                continue;
            }
            else if (grid[next.first][next.second] != origin)
            {
                result[pos.first][pos.second] = color;
            }
            else
            {
                search.push(next);
                visit[next.first][next.second] = 1;
            }
        }
    }
    return result;
}

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
vector<int> LeetCodeBFS::gardenNoAdj(int N, vector<vector<int>>& paths)
{
    vector<vector<int>> neighbor(N, vector<int>());
    vector<vector<int>> bit_map(N, vector<int>(4));
    vector<int> visited(N);
    vector<int> result(N);
    for (size_t i = 0; i < paths.size(); i++)
    {
        neighbor[paths[i][0] - 1].push_back(paths[i][1] - 1);
        neighbor[paths[i][1] - 1].push_back(paths[i][0] - 1);
    }

    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] != 0) continue;
        queue<int> search;       
        search.push(i);
        visited[i] = 1;
        while (!search.empty())
        {
            int index = search.front();
            search.pop();
            for (int j = 0; j < 4; j++)
            {
                if (bit_map[index][j] == 0)
                {
                    result[index] = j + 1;
                    break;
                }
            }
            int color = result[index] - 1;
            for (size_t j = 0; j < neighbor[index].size(); j++)
            {
                int ne = neighbor[index][j];
                bit_map[ne][color] = 1;
                if (visited[ne] == 0)
                {
                    visited[ne] = 1;
                    search.push(ne);
                }
            }
        }
    }
    return result;
}

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
int LeetCodeBFS::shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    vector<int> pos = { 0, 0 };
    queue<vector<int>> search;
    if (grid[0][0] == 1) return -1;
    search.push(pos);
    vector<vector<int>> directions = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };
    int result = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        result++;
        for (size_t i = 0; i < size; i++)
        {
            vector<int> pos = search.front();
            search.pop();
            if (pos[0] == grid.size() - 1 && pos[1] == grid[0].size() - 1) return result;
            for (size_t d = 0; d < directions.size(); d++)
            {
                vector<int> next = pos;
                next[0] += directions[d][0];
                next[1] += directions[d][1];

                if (next[0] < 0 || next[0] >= (int)grid.size() ||
                    next[1] < 0 || next[1] >= (int)grid[0].size())
                {
                    continue;
                }
                if (grid[next[0]][next[1]] == 1)
                {
                    continue;
                }
                grid[next[0]][next[1]] = 1;
                
                search.push(next);
            }
        }
    }
    return -1;
}

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
int LeetCodeBFS::maxLandDistance(vector<vector<int>>& grid)
{
    int distance = 0;
    int result = -1;
    queue<pair<int, int>> search;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1) search.push(make_pair(i, j));
        }
    }

    while (!search.empty())
    {
        size_t size = search.size();
        distance++;
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> pos = search.front();
            search.pop();
            vector<pair<int, int>> directions = 
                { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
            for (size_t d = 0; d < directions.size(); d++)
            {
                pair<int, int> next = pos;
                next.first += directions[d].first;
                next.second += directions[d].second;
                if (next.first < 0 || next.first >= (int)grid.size() ||
                    next.second < 0 || next.second >= (int)grid[0].size())
                {
                    continue;
                }
                if (grid[next.first][next.second] == 0)
                {
                    grid[next.first][next.second] = distance;
                    result = distance;
                    search.push(next);
                }
            }
        }
    }
    return result;
}

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
int LeetCodeBFS::minKnightMoves(int x, int y)
{
    unordered_map<int, unordered_map<int, int>> visited;
    queue<pair<int, int>> search;
    int result = 0;
    vector<vector<int>> directions =
    {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };
    pair<int, int> pos = { 0,0 };
    visited[0][0] = 1;
    search.push(make_pair(0, 0));
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> pos = search.front();
            search.pop();
            if (pos.first == x && pos.second == y) return result;          
            for (size_t d = 0; d < directions.size(); d++)
            {
                pair<int, int> next = pos;
                next.first += directions[d][0];
                next.second += directions[d][1];
                if ((std::abs(x - pos.first) > 1) && (directions[d][0] * (x - pos.first) < 0))
                {
                    continue;
                }
                if ((std::abs(y - pos.second) > 1) && (directions[d][1] * (y - pos.second) < 0))
                {
                    continue;
                }
                if (visited[next.first][next.second] == 1) continue;
                visited[next.first][next.second] = 1;
                search.push(next);
            }
        }
        result++;
    }
    return result;
}


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
/// Constraints:
/// 
/// 1. 0 <= low <= high <= 2 * 10^9
/// </summary>
vector<int> LeetCodeBFS::countSteppingNumbers(int low, int high)
{
    vector<int> result;
    queue<int> search;
    if (low == 0) result.push_back(0);
    for (size_t i = 1; i < 10; i++) search.push(i);
    while (!search.empty())
    {
        int num = search.front();
        search.pop();
        if (num >= low && num <= high)
        {
            result.push_back(num);
        }
        int digit = num % 10;
        long long next = 0;
        if (digit > 0)
        {
            next = (long long)num * 10 + digit - 1;
            if (next <= (long long)high) search.push((int)next);
        }
        if (digit < 9)
        {
            next = (long long)num * 10 + digit + 1;
            if (next <= (long long)high) search.push((int)next);
        }
    }
    return result;
}

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
int LeetCodeBFS::minFlips(vector<vector<int>>& mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> bits(m * n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bits[ i * n + j] = mat[i][j];
        }
    }
    vector<int> directions = { -1, 1, -n, n };
    set<vector<int>>visited;
    queue<vector<int>> search;
    search.push(bits);
    visited.insert(bits);
    int result = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t k = 0; k < size; k++)
        {
            vector<int> bits = search.front();
            search.pop();

            if (std::count(bits.begin(), bits.end(), 1) == 0)
            {
                return result;
            }
            for (size_t i = 0; i < bits.size(); i++)
            {
                vector<int> next = bits;
                next[i] = 1 - next[i];
                for (size_t d = 0; d < directions.size(); d++)
                {
                    int pos = (int)i + directions[d];
                    // out of boundary
                    if (pos < 0 || pos >= (int)bits.size())
                    {
                        continue;
                    }
                    // out of boundary
                    if ((d == 0 && pos % n == n - 1) ||
                        (d == 1 && pos % n == 0))
                    {
                        continue;
                    }
                    next[pos] = 1 - next[pos];
                }
                if (visited.count(next) == 0)
                {
                    search.push(next);
                    visited.insert(next);
                }
            }
        }
        result++;
    }
    return -1;
}

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
int LeetCodeBFS::findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
{
    pair<int, int> result = { -1, INT_MAX };
    vector<vector<pair<int, int>>> distance(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        distance[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
        distance[edges[i][1]].push_back({ edges[i][0], edges[i][2] });
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> visited(n, -1);
        queue<int> search;
        search.push(i);
        visited[i] = distanceThreshold;
        int count = 0;
        while (!search.empty())
        {
            if (count > result.second) break;
            int city = search.front();
            int threshold = visited[city];
            search.pop();
            for (auto d : distance[city])
            {
                if (threshold < d.second) continue;
                if (visited[d.first] == -1)
                {
                    count++;
                }
                if (threshold - d.second > visited[d.first])
                {
                    visited[d.first] = threshold - d.second;
                    search.push(d.first);
                }
            }
        }
        if (count <= result.second)
        {
            result.first = i;
            result.second = count;
        }
    }
    return result.first;
}
#pragma endregion
