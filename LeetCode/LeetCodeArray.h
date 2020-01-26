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
/// Leet code #284. Peeking Iterator             
/// Given an Iterator class interface with methods: next() and hasNext(), design and implement 
/// a PeekingIterator that support the peek() operation -- it essentially peek() at the element that 
/// will be returned by the next call to next().
///
/// Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
/// Call next() gets you 1, the first element in the list.
/// Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
///
/// You call next() the final time and it returns 3, the last element. 
/// Calling hasNext() after that should return false. 
/// Hint:
/// 1.Think of "looking ahead". You want to cache the next element.
/// 2.Is one variable sufficient? Why or why not?
/// 3.Test your design with call order of peek() before next() vs next() before peek().
/// 4.For a clean implementation, check out Google's guava library source code.
/// Follow up: How would you extend your design to be generic and work with all types, not just integer?	
/// </summary>
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
// 2016-12-10, HM: I modify this interface so I can run it in my code 
class Iterator {
private:
    vector<int> m_nums;
    int m_index;
public:
    Iterator(const vector<int>& nums)
    {
        m_nums = nums;
        m_index = 0;
    };
    Iterator(const Iterator& iter)
    {
        m_nums = iter.m_nums;
    }
    virtual ~Iterator()
    {
    };
    // Returns the next element in the iteration.
    int next()
    {
        return m_nums[m_index];
        m_index++;
    };
    // Returns true if the iteration has more elements.
    bool hasNext() const
    {
        return (m_index < (int)m_nums.size());
    };
};


class PeekingIterator : public Iterator
{
private:
    queue<int> m_queue;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        if ((m_queue.empty()) && (Iterator::hasNext()))
        {
            m_queue.push(Iterator::next());
        }
        return m_queue.front();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        int value;
        if (!m_queue.empty())
        {
            value = m_queue.front();
            m_queue.pop();
        }
        else
        {
            value = Iterator::next();
        }
        return value;
    }

    bool hasNext() const {
        if (!m_queue.empty())
        {
            return true;
        }
        else
        {
            return Iterator::hasNext();
        }
    }
};

/// <summary>
/// Leet code #348. Design Tic-Tac-Toe 
/// 
/// Design a Tic-tac-toe game that is played between two players on a n x n grid. 
/// You may assume the following rules:  
/// 1.A move is guaranteed to be valid and is placed on an empty block.
/// 2.Once a winning condition is reached, no more moves is allowed. 
/// 3.A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
///
/// Example:
/// Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
/// TicTacToe toe = new TicTacToe(3); 
/// toe.move(0, 0, 1); -> Returns 0 (no one wins)
/// |X| | |
/// | | | |    // Player 1 makes a move at (0, 0).
/// | | | |
/// 
/// toe.move(0, 2, 2); -> Returns 0 (no one wins)
/// |X| |O|
/// | | | |    // Player 2 makes a move at (0, 2).
/// | | | |
/// 
/// toe.move(2, 2, 1); -> Returns 0 (no one wins)
/// |X| |O|
/// | | | |    // Player 1 makes a move at (2, 2).
/// | | |X|
///
/// toe.move(1, 1, 2); -> Returns 0 (no one wins)
/// |X| |O|
/// | |O| |    // Player 2 makes a move at (1, 1).
/// | | |X|
///
/// toe.move(2, 0, 1); -> Returns 0 (no one wins)
/// |X| |O|
/// | |O| |    // Player 1 makes a move at (2, 0).
/// |X| |X|
///
/// toe.move(1, 0, 2); -> Returns 0 (no one wins)
/// |X| |O|
/// |O|O| |    // Player 2 makes a move at (1, 0).
/// |X| |X|
///
/// toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
/// |X| |O|
/// |O|O| |    // Player 1 makes a move at (2, 1).
/// |X|X|X|
/// Follow up:
/// Could you do better than O(n2) per move() operation? 
/// Hint:
/// 1.Could you trade extra space such that move() operation can be done in O(1)?
/// 2.You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.
/// </summary>
class TicTacToe
{
    vector<vector<int>> row_map;
    vector<vector<int>> col_map;
    vector<int> diag_map;
    vector<int> anti_map;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    {
        row_map = vector<vector<int>>(n, vector<int>(2));
        col_map = vector<vector<int>>(n, vector<int>(2));
        diag_map = vector<int>(2);
        anti_map = vector<int>(2);
    }

    /** Player {player} makes a move at ({row}, {col}).
    @param row The row of the board.
    @param col The column of the board.
    @param player The player, can be either 1 or 2.
    @return The current winning condition, can be either:
    0: No one wins.
    1: Player 1 wins.
    2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        row_map[row][player - 1]++;
        col_map[col][player - 1]++;
        if (row == col)
        {
            diag_map[player - 1]++;
        }
        if (row + col == row_map.size() - 1)
        {
            anti_map[player - 1]++;
        }
        if ((row_map[row][player - 1] == row_map.size()) ||
            (col_map[col][player - 1] == row_map.size()) ||
            (diag_map[player - 1] == row_map.size()) ||
            (anti_map[player - 1] == row_map.size()))
        {
            return player;
        }
        else
        {
            return 0;
        }
    }
};

/// <summary>
/// Leet code #353. Design Snake Game  
/// 
/// Design a Snake game that is played on a device with screen size = width x height. 
/// Play the game online if you are not familiar with the game.
/// The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
/// You are given a list of food's positions in row-column order. When a snake eats the food, 
/// its length and the game's score both increase by 1.
/// Each food appears one by one on the screen. For example, the second food will not appear 
/// until the first food was eaten by the snake. 
/// When a food does appear on the screen, it is guaranteed that it will not appear on a 
/// block occupied by the snake.
/// Example:
/// Given width = 3, height = 2, and food = [[1,2],[0,1]].
/// Snake snake = new Snake(width, height, food);
/// Initially the snake appears at position (0,0) and the food at (1,2).
/// |S| | |
/// | | |F|
/// 
/// snake.move("R"); -> Returns 0
/// | |S| |
/// | | |F|
///
/// snake.move("D"); -> Returns 0
///
/// | | | |
/// | |S|F|
///   
/// snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )
///
/// | |F| |
/// | |S|S|
///
/// snake.move("U"); -> Returns 1
///
/// | |F|S|
/// | | |S|
///
/// snake.move("L"); -> Returns 2 (Snake eats the second food)
///
/// | |S|S|
/// | | |S|
///
/// snake.move("U"); -> Returns -1 (Game over because snake collides with border)
/// </summary>
class SnakeGame
{
private:
    list<pair<int, int>> m_snake;
    int m_width;
    int m_height;
    vector<pair<int, int>> m_food;
    int m_foodindex;
    unordered_map<int, unordered_set<int>> m_snakemap;
public:
    /** Initialize your data structure here.
    @param width - screen width
    @param height - screen height
    @param food - A list of food positions
    E.g food = [[1, 1], [1, 0]] means the first food is positioned at[1, 1], the second is at[1, 0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food)
    {
        m_width = width;
        m_height = height;
        m_food = food;
        m_snake.push_front(make_pair(0, 0));
        m_snakemap[0].insert(0);
        m_foodindex = 0;
    }

    /** Moves the snake.
    @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
    @return The game's score after the move. Return -1 if game over.
    Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction)
    {
        pair<int, int> head = m_snake.front();
        if (direction == "U")
        {
            head.first--;
            if (head.first < 0)
            {
                return -1;
            }
        }
        else if (direction == "D")
        {
            head.first++;
            if (head.first == m_height)
            {
                return -1;
            }
        }
        else if (direction == "L")
        {
            head.second--;
            if (head.second < 0)
            {
                return -1;
            }
        }
        else if (direction == "R")
        {
            head.second++;
            if (head.second == m_width)
            {
                return -1;
            }
        }

        m_snake.push_front(head);
        if ((m_foodindex < (int)m_food.size()) && (head == m_food[m_foodindex]) &&
            (m_snakemap[head.first].count(head.second) == 0))
        {
            m_foodindex++;
        }
        else
        {
            pair<int, int> tail = m_snake.back();
            m_snakemap[tail.first].erase(tail.second);
            m_snake.pop_back();
        }
        if (m_snakemap[head.first].count(head.second) > 0)
        {
            return -1;
        }
        m_snakemap[head.first].insert(head.second);
        return m_foodindex;
    }
};

/// <summary>
/// Leet code #379. Design Phone Directory 
/// 
/// Design a Phone Directory which supports the following operations:
/// 1.get: Provide a number which is not assigned to anyone.
///	2.check: Check if a number is available or not.
/// 3.release: Recycle or release a number.
/// Example: 
/// // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
/// PhoneDirectory directory = new PhoneDirectory(3);
/// // It can return any available phone number. Here we assume it returns 0.
/// directory.get();
/// 
/// // Assume it returns 1.
/// directory.get();
///
/// // The number 2 is available, so return true.
/// directory.check(2);
///
/// // It returns 2, the only number that is left.
/// directory.get();
///
/// // The number 2 is no longer available, so return false.
/// directory.check(2);
///
/// // Release number 2 back to the pool.
/// directory.release(2);
///
/// // Number 2 is available again, return true.
/// directory.check(2);
/// </summary>
class PhoneDirectory
{
    vector<int> m_FreeList;
    vector<bool> m_Allocation;
    int m_Index;
    int m_Size;
public:
    // Initialize your data structure here
    // @param maxNumbers - The maximum numbers that can be stored in the phone directory.
    PhoneDirectory(int maxNumbers)
    {
        m_Index = 0;
        m_Size = maxNumbers;
        m_FreeList = vector<int>(m_Size);
        m_Allocation = vector<bool>(m_Size, false);
        for (int i = 0; i < maxNumbers; i++)
        {
            m_FreeList[i] = i;
        }
    }

    // Provide a number which is not assigned to anyone.
    // @return - Return an available number. Return -1 if none is available.
    int get()
    {
        if (m_Index == m_Size)
        {
            return -1;
        }
        else
        {
            int value = m_FreeList[m_Index];
            m_Index++;
            m_Allocation[value] = true;
            return value;
        }
    }

    // Check if a number is available or not.
    bool check(int number)
    {
        if ((number < 0) || (number >= m_Size))
        {
            return false;
        }
        return (!m_Allocation[number]);
    }

    // Recycle or release a number.
    void release(int number)
    {
        if ((number < 0) || (number >= m_Size) || (m_Allocation[number] == false))
        {
            return;
        }
        m_Index--;
        m_FreeList[m_Index] = number;
        m_Allocation[number] = false;
    }
};

/// <summary>
/// Leet code #281. Zigzag Iterator  
/// 
/// Given two 1d vectors, implement an iterator to return their elements 
/// alternately.
/// For example, given two 1d vectors: 
/// v1 = [1, 2]
/// v2 = [3, 4, 5, 6]
/// By calling next repeatedly until hasNext returns false, the order of 
/// elements returned by next should be: [1, 3, 2, 4, 5, 6].
/// Follow up: What if you are given k 1d vectors? How well can your code be 
/// extended to such cases?
/// Clarification for the follow up question - Update (2015-09-18):
/// The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. 
/// If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". 
/// For example, given the following input: 
/// [1,2,3]
/// [4,5,6,7]
/// [8,9]
/// It should return [1,4,8,2,5,9,3,6,7]. 	
/// </summary>
class ZigzagIterator
{
private:
    size_t m_Row;
    size_t m_Col;
    int m_Size;
    int m_Index;
    vector<vector<int>> m_Vector;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        m_Vector.push_back(v1);
        m_Vector.push_back(v2);
        m_Index = 0;
        m_Size = v1.size() + v2.size();
        m_Row = 0;
        m_Col = 0;
    }
    int next()
    {
        int result;
        while (m_Row >= m_Vector.size() || m_Col >= m_Vector[m_Row].size())
        {
            if (m_Row < m_Vector.size())
            {
                m_Row++;
            }
            else
            {
                m_Row = 0;
                m_Col++;
            }
        }
        result = m_Vector[m_Row][m_Col];
        m_Row++;
        m_Index++;
        return result;
    }

    bool hasNext()
    {
        if (m_Index < m_Size) return true;
        else return false;
    }
};

/// <summary>
/// Leet code #251. Flatten 2D Vector  
/// 
/// Implement an iterator to flatten a 2d vector.
/// For example,
/// Given 2d vector = 
/// [
///  [1,2],
///  [3],
///  [4,5,6]
/// ]
/// By calling next repeatedly until hasNext returns false, the order of 
/// elements returned by next should be: [1,2,3,4,5,6]. 
/// Hint:
/// 1.How many variables do you need to keep track?
/// 2.Two variables is all you need. Try with x and y.
/// 3.Beware of empty rows. It could be the first few rows.
/// 4.To write correct code, think about the invariant to maintain. What is it?
/// 5.The invariant is x and y must always point to a valid point in the 2d 
///   vector. Should you maintain your invariant ahead of time or right when 
///   you need it?
/// 6.Not sure? Think about how you would implement hasNext(). Which is more 
///   complex?
/// 7.Common logic in two different places should be refactored into a common 
///   method.
///
/// Follow up:
/// As an added challenge, try to code it using only iterators in C++ or 
/// iterators in Java. 
/// </summary>
class Vector2D
{
private:
    size_t m_Row;
    size_t m_Col;
    vector<vector<int>> m_Vector;
public:
    Vector2D(vector<vector<int>>& vec2d)
    {
        m_Vector = vec2d;
        m_Row = 0;
        m_Col = 0;
    }

    int next()
    {
        int result = m_Vector[m_Row][m_Col];
        m_Col++;
        return result;
    }

    bool hasNext()
    {
        while ((m_Row < m_Vector.size()) && (m_Col >= m_Vector[m_Row].size()))
        {
            m_Row++;
            m_Col = 0;
        }
        if (m_Row == m_Vector.size()) return false;
        else return true;
    }
};

/// <summary>
/// Leet code #631. Design Excel Sum Formula
/// 
/// Your task is to design the basic function of Excel and implement the 
/// function of sum formula. Specifically, you need to implement the 
/// following functions:
/// Excel(int H, char W): This is the constructor. The inputs represents 
/// the height and width of the Excel form. H is a positive integer, range 
/// from 1 to 26. It represents the height. W is a character range from 
/// 'A' to 'Z'. It represents that the width is the number of characters 
/// from 'A' to W. The Excel form content is represented by a height * 
/// width 2D integer array C, it should be initialized to zero. You should 
/// assume that the first row of C starts from 1, and the first column of 
/// C starts from 'A'.
/// 
/// void Set(int row, char column, int val): Change the value at 
/// C(row, column) to be val.
///
/// int Get(int row, char column): Return the value at C(row, column).
///
/// int Sum(int row, char column, List of Strings : numbers): This function 
/// calculate and set the value at C(row, column), where the value should 
/// be the sum of cells represented by numbers. This function return the 
/// sum result at C(row, column). This sum formula should exist until this 
/// cell is overlapped by another value or another sum formula.
/// numbers is a list of strings that each string represent a cell or a 
/// range of cells. If the string represent a single cell, then it has the 
/// following format : ColRow. For example, "F7" represents the cell at 
/// (7, F). 
/// If the string represent a range of cells, then it has the following 
/// format : ColRow1:ColRow2. The range will always be a rectangle, and 
/// ColRow1 represent the position of the top-left cell, and ColRow2 
/// represents the position of the bottom-right cell. 
///
/// Example 1:
/// Excel(3,"C"); 
/// construct a 3*3 2D array with all zero.
///   A B C
/// 1 0 0 0
/// 2 0 0 0
/// 3 0 0 0
///
/// Set(1, "A", 2);
/// set C(1,"A") to be 2.
///   A B C
/// 1 2 0 0
/// 2 0 0 0
/// 3 0 0 0
///
/// Sum(3, "C", ["A1", "A1:B2"]);
/// set C(3,"C") to be the sum of value at C(1,"A") and the values sum of 
/// the rectangle range whose top-left cell is C(1,"A") and bottom-right 
/// cell is C(2,"B"). Return 4. 
///   A B C
/// 1 2 0 0
/// 2 0 0 0
/// 3 0 0 4
///
/// Set(2, "B", 2);
/// set C(2,"B") to be 2. Note C(3, "C") should also be changed.
///   A B C
/// 1 2 0 0
/// 2 0 2 0
/// 3 0 0 6
///
/// Note:
/// You could assume that there won't be any circular sum reference. For 
/// example, A1 = sum(B1) and B1 = sum(A1).
/// The test cases are using double-quotes to represent a character.
/// Please remember to RESET your class variables declared in class Excel, 
/// as static/class variables are persisted across multiple test cases. 
/// Please see here for more details.
/// </summary>
class Excel
{
private:
    unordered_map<int, unordered_map<int, vector<pair<int, int>>>> sum_formula;
    vector<vector<int>> cells;

    int calculate(int row, int col)
    {
        if (sum_formula[row].count(col) == 0)
        {
            return cells[row][col];
        }

        int sum = 0;
        vector<pair<int, int>>& range_list = sum_formula[row][col];
        for (size_t i = 0; i < range_list.size(); i += 2)
        {
            int start_row = range_list[i].first;
            int start_col = range_list[i].second;
            int end_row = range_list[i + 1].first;
            int end_col = range_list[i + 1].second;
            for (int r = start_row; r < end_row; r++)
            {
                for (int c = start_col; c < end_col; c++)
                {
                    sum += calculate(r, c);
                }
            }
        }
        return sum;
    }

    vector<pair<int, int>> parse_range(vector<string> str_list)
    {
        vector<pair<int, int>> result;
        for (size_t i = 0; i < str_list.size(); i++)
        {
            string token;
            string str = str_list[i];
            int row = 0, col = 0;
            for (size_t j = 0; j <= str.size(); j++)
            {
                if (j == str.size())
                {
                    row = stoi(token) - 1;
                    token.clear();

                    // for a single cell
                    if (result.size() % 2 == 0)
                    {
                        result.push_back(make_pair(row, col));
                    }
                    // for end range we make it out of boundary
                    result.push_back(make_pair(row + 1, col + 1));
                }
                else if (str[j] == ':')
                {
                    row = stoi(token) - 1;
                    token.clear();
                    result.push_back(make_pair(row, col));
                }
                else if (isalpha(str[j]))
                {
                    col = str[j] - 'A';
                }
                else if (isdigit(str[j]))
                {
                    token += str[j];
                }
            }
            // if this is a single cell, duplicate it as range
            if (result.size() % 2 == 1)
            {
                result.push_back(make_pair(row, col));
            }
        }
        return result;
    }

public:
    Excel(int H, char W)
    {
        int rows = H;
        int cols = W - 'A' + 1;
        cells = vector<vector<int>>(rows, vector<int>(cols));
    }

    void set(int r, char c, int v)
    {
        int row = r - 1;
        int col = c - 'A';
        // clean up formula
        if (sum_formula[row].count(col) > 0)
        {
            sum_formula[row].erase(col);
        }

        cells[row][col] = v;
    }

    int get(int r, char c)
    {
        int row = r - 1;
        int col = c - 'A';
        return calculate(row, col);
    }

    int sum(int r, char c, vector<string> strs)
    {
        int row = r - 1;
        int col = c - 'A';
        sum_formula[row][col] = parse_range(strs);
        cells[row][col] = 0;
        return calculate(row, col);
    }
};

/// <summary>
/// The class is to implement array related algorithm  
/// </summary>
class LeetCodeArray
{
public:
#pragma region Array

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
#pragma endregion
};
#endif  // LeetCodeArray_H
