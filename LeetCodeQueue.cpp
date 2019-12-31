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
#pragma region Queue
/// <summary>
/// Leet code #239. Sliding Window Maximum  
/// Given an array nums, there is a sliding window of size k which is moving 
/// from the very left of the array to the very right. 
/// You can only see the k numbers in the window. Each time the sliding window 
/// moves right by one position.
/// For example,
/// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
/// Window position                Max
/// ---------------               -----
/// [1  3  -1] -3  5  3  6  7       3
///  1 [3  -1  -3] 5  3  6  7       3
///  1  3 [-1  -3  5] 3  6  7       5
///  1  3  -1 [-3  5  3] 6  7       5
///  1  3  -1  -3 [5  3  6] 7       6
///  1  3  -1  -3  5 [3  6  7]      7
/// Therefore, return the max sliding window as [3,3,5,5,6,7].
/// Note: 
/// You may assume k is always valid, ie: 1 ¡Ü k ¡Ü input array's size for 
/// non-empty array.
/// Follow up:
/// Could you solve it in linear time?
/// Hint:
/// 1.How about using a data structure such as deque (double-ended queue)?
/// 2.The queue size need not be the same as the window¡¯s size.
/// 3.Remove redundant elements and the queue should store only elements 
///   that need to be considered.
/// </summary> 
vector<int> LeetCode::maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> result;
    deque<int> max_window;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (max_window.empty())
        {
            max_window.push_back(nums[i]);
        }
        else
        {
            if (max_window.size() == k) max_window.pop_front();
            size_t count = 0;
            while (!max_window.empty() && max_window.back() < nums[i])
            {
                max_window.pop_back();
                count++;
            }
            for (size_t j = 0; j < count; j++)
            {
                max_window.push_back(nums[i]);
            }
            max_window.push_back(nums[i]);
        }
        if (max_window.size() == k)
        {
            result.push_back(max_window.front());
        }
    }
    return result;
}
#pragma endregion