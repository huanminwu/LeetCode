#pragma once
/// <summary>
/// The class is to implement some string algorithm 
/// </summary>
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
#include "LeetCodeBackTracking.h"
#pragma region BackTracking
/// <summary>
/// Leet code #282. Expression Add Operators
/// </summary>
void LeetCodeBackTracking::calculate(vector<string>& result, string path, string num, long long target, long long eval, long long product)
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
            calculate(result, path + "*" + cur_string, num.substr(i + 1), target, eval - product + product * cur_value, product * cur_value);
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
vector<string> LeetCodeBackTracking::addOperators(string num, int target)
{
    vector<string> result;
    unordered_map<string, unordered_map<string, int>> cache;
    if (num.empty()) return result;

    calculate(result, "", num, target, 0, 1);
    return result;
}

/// <summary>
/// Leet code #756. Pyramid Transition Matrix
/// </summary>
void LeetCodeBackTracking::nextPyramidTop(string& bottom, string& top, unordered_map<char, unordered_map<char, set<char>>>& allowed_map)

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
bool LeetCodeBackTracking::buildPyramidTransition(string& bottom, unordered_map<char, unordered_map<char, set<char>>>& allowed_map)
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
bool LeetCodeBackTracking::pyramidTransition(string bottom, vector<string>& allowed)
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

#pragma endregion
