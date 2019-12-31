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
#include "LeetCodeArray.h"
#pragma region Array

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
int LeetCodeArray::maxSubArray(vector<int>& nums)
{
    int min_sum = 0;
    int max_sum = INT_MIN;
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        // calculate max_sum first because min_sum is for previous ones.
        max_sum = max(max_sum, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    return max_sum;
}

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
int LeetCodeArray::canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    vector<int> sum(gas.size());
    int start_index = -1;
    int min_sum = INT_MAX;
    for (size_t i = 0; i < gas.size(); i++)
    {
        if (i == 0)
        {
            sum[i] = gas[i] - cost[i];
        }
        else
        {
            sum[i] = sum[i - 1] + gas[i] - cost[i];
        }
        if (sum[i] < min_sum)
        {
            min_sum = sum[i];
            start_index = (i + 1 == gas.size()) ? 0 : i + 1;
        }
    }
    if (sum[gas.size() - 1] >= 0)
    {
        return start_index;
    }
    else
    {
        return -1;
    }
}

/// <summary>
/// Leet code #204. Count Primes
/// 
/// Count the number of prime numbers less than a non - negative number, n.
/// </summary>
int LeetCode::countPrimes(int n)
{
    int result = 0;
    vector<int> matrix(n, 0);
    for (int i = 0; i < n; i++)
    {
        if ((i == 0) || (i == 1)) continue;
        if (matrix[i] == 1) continue;
        int factor = 2;
        while (i * factor < n)
        {
            matrix[i * factor] = 1;
            factor++;
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (matrix[i] == 0)
        {
            result++;
        }
    }
    return result;
}

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
int LeetCodeArray::majorityElement(vector<int>& nums)
{
    int count = 0;
    int major_number = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            major_number = nums[i];
            count++;
        }
        else
        {
            if (major_number == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
    }
    return major_number;
}

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
vector<int> LeetCodeArray::majorityElementII(vector<int>& nums)
{
    vector<int> result;
    if (nums.size() < 3) return nums;
    int count1 = 1, count2 = 1;
    int number1 = nums[0], number2 = nums[1];
    for (size_t i = 2; i < nums.size(); i++)
    {
        if (number1 == nums[i])
        {
            count1++;
        }
        else if (number2 == nums[i])
        {
            count2++;
        }
        else if (count1 == 0)
        {
            number1 = nums[i];
            count1++;
        }
        else if (count2 == 0)
        {
            number2 = nums[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = count(nums.begin(), nums.end(), number1);
    count2 = count(nums.begin(), nums.end(), number2);
    if (count1 > (int)nums.size() / 3)
    {
        result.push_back(number1);
    }
    if (count2 > (int)nums.size() / 3)
    {
        if (number2 != number1) result.push_back(number2);
    }
    return result;
}

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
///
/// Note:
///
/// 1. You must not modify the array (assume the array is read only).
/// 2. You must use only constant, O(1) extra space.
/// 3. Your runtime complexity should be less than O(n2).
/// 4. There is only one duplicate number in the array, but it could be 
///    repeated more than once.
/// </summary>
int LeetCodeArray::findDuplicate(vector<int>& nums)
{
    // protect empty array
    if (nums.size() == 0) return -1;

    // tortoise
    int slow = 0;
    int fast = 0;

    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) break;
    }
    fast = 0;

    while (true)
    {
        slow = nums[slow];
        fast = nums[fast];
        if (slow == fast) break;
    }
    return slow;
}

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
int LeetCodeArray::firstMissingPositive(vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return 1;
    }
    size_t index = 0;
    while (index < nums.size())
    {
        // non-positive or out of range, skip it.
        if ((nums[index] <= 0) || (nums[index] >= (int)nums.size()))
        {
            index++;
        }
        // already in order, skip it
        else if (nums[index] == index + 1)
        {
            index++;
        }
        // already same data so no need to swap
        else if (nums[index] == nums[nums[index] - 1])
        {
            index++;
        }
        else
        {
            swap(nums[index], nums[nums[index] - 1]);
        }
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return nums.size() + 1;
}

/// <summary>
/// Leet code #26. Remove Duplicates from Sorted Array
/// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
/// Do not allocate extra space for another array, you must do this in place with constant memory. 
/// For example,
/// Given input array nums = [1,1,2], 
/// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
/// It doesn't matter what you leave beyond the new length. 
/// </summary>
int LeetCode::removeDuplicateSortedArray(vector<int>& nums)
{
    vector<int>::iterator new_end = std::unique(nums.begin(), nums.end());
    nums.erase(new_end, nums.end());
    return nums.size();
}

/// <summary>
/// LeetCode #80. Remove Duplicates from Sorted Array II  
/// Follow up for "Remove Duplicates": 
/// What if duplicates are allowed at most twice? 
/// For example, 
/// Given sorted array nums = [1,1,1,2,2,3], 
/// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
/// It doesn't matter what you leave beyond the new length.  
/// </summary>
int LeetCode::removeDuplicatesII(vector<int>& nums)
{
    size_t first = 0, last = 0;
    int count = 0;
    while (last < nums.size())
    {
        if ((last > 0) && (nums[last] == nums[last - 1]))
        {
            count++;
            if (count >= 2)
            {
                last++;
                continue;
            }
        }
        else
        {
            count = 0;
        }
        if (first < last)
        {
            nums[first] = nums[last];
        }
        first++;
        last++;
    }
    nums.erase(nums.begin() + first, nums.end());
    return first;
}

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
vector<int> LeetCodeArray::spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result;
    if (matrix.empty() || matrix[0].empty()) return result;
    int begin_row = 0;
    int end_row = matrix.size() - 1;
    int begin_col = 0;
    int end_col = matrix[0].size() - 1;
    int direction = 0;
    while ((begin_row <= end_row) && (begin_col <= end_col))
    {
        switch (direction)
        {
        case 0:
            for (int i = begin_col; i <= end_col; i++)
            {
                result.push_back(matrix[begin_row][i]);
            }
            begin_row++;
            break;
        case 1:
            for (int i = begin_row; i <= end_row; i++)
            {
                result.push_back(matrix[i][end_col]);
            }
            end_col--;
            break;
        case 2:
            for (int i = end_col; i >= begin_col; i--)
            {
                result.push_back(matrix[end_row][i]);
            }
            end_row--;
            break;
        case 3:
            for (int i = end_row; i >= begin_row; i--)
            {
                result.push_back(matrix[i][begin_col]);
            }
            begin_col++;
            break;
        }
        direction = (direction + 1) % 4;
    }
    return result;
}

/// <summary>
/// Leet code #59. Spiral Matrix II
/// 
/// Medium
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
vector<vector<int>> LeetCodeArray::generateMatrix(int n)
{
    vector<vector<int>> result(n, vector<int>(n, 0));
    if (n <= 0) return result;
    int begin_row = 0;
    int end_row = n - 1;
    int begin_col = 0;
    int end_col = n - 1;
    int direction = 0;
    int index = 0;
    while ((begin_row <= end_row) && (begin_col <= end_col))
    {
        switch (direction)
        {
        case 0:
            for (int i = begin_col; i <= end_col; i++)
            {
                index++;
                result[begin_row][i] = index;
            }
            begin_row++;
            break;
        case 1:
            for (int i = begin_row; i <= end_row; i++)
            {
                index++;
                result[i][end_col] = index;
            }
            end_col--;
            break;
        case 2:
            for (int i = end_col; i >= begin_col; i--)
            {
                index++;
                result[end_row][i] = index;
            }
            end_row--;
            break;
        case 3:
            for (int i = end_row; i >= begin_row; i--)
            {
                index++;
                result[i][begin_col] = index;
            }
            begin_col++;
            break;
        }
        direction = (direction + 1) % 4;
    }
    return result;
}

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
void LeetCodeArray::rotate(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) return;
    int begin_row = 0;
    int end_row = matrix.size() - 1;
    int begin_col = 0;
    int end_col = matrix[0].size() - 1;
    while ((begin_row <= end_row) && (begin_col <= end_col))
    {
        for (int i = 0; i < (end_col - begin_col); i++)
        {
            swap(matrix[begin_row][begin_col + i], matrix[begin_row + i][end_col]);
            swap(matrix[begin_row][begin_col + i], matrix[end_row][end_col - i]);
            swap(matrix[begin_row][begin_col + i], matrix[end_row - i][begin_col]);
        }
        begin_row++;
        end_row--;
        begin_col++;
        end_col--;
    }
}

/// <summary>
/// LeetCode #73. Set Matrix Zeroes  
/// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 
/// Did you use extra space?
/// A straight forward solution using O(mn) space is probably a bad idea.
/// A simple improvement uses O(m + n) space, but still not the best solution.
/// Could you devise a constant space solution? 
/// </summary>
void LeetCode::setZeroes(vector<vector<int>>& matrix)
{
    int row0 = -1, col0 = -1;
    if ((matrix.size() == 0) || (matrix[0].size() == 0)) return;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                if ((row0 == -1) && (col0 == -1))
                {
                    row0 = i; col0 = j;
                }
                else
                {
                    matrix[row0][j] = 0; matrix[i][col0] = 0;
                }
            }
        }
    }
    if ((row0 == -1) && (col0 == -1)) return;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        if (i == row0) continue;
        if (matrix[i][col0] == 0)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < matrix[0].size(); i++)
    {
        if (i == col0) continue;
        if (matrix[row0][i] == 0)
        {
            for (size_t j = 0; j < matrix.size(); j++)
            {
                matrix[j][i] = 0;
            }
        }
    }

    for (size_t i = 0; i < matrix.size(); i++)
    {
        matrix[i][col0] = 0;
    }
    for (size_t i = 0; i < matrix[0].size(); i++)
    {
        matrix[row0][i] = 0;
    }
}

/// <summary>
/// Leet code #189. Rotate Array       
/// Rotate an array of n elements to the right by k steps.
/// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
/// Note:
/// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
/// Hint:
/// Could you do it in-place with O(1) extra space? 
/// Related problem: Reverse Words in a String II
/// </summary>
void LeetCode::rotateArray(vector<int>& nums, int k)
{
    if ((nums.size() == 0) || (k == 0)) return;
    size_t a = nums.size(), b = k;
    if (a < b) swap(a, b);
    while (b != 0)
    {
        a = a % b;
        swap(a, b);
    }
    for (size_t i = 0; i < a; i++)
    {
        size_t index = i, next = (index + k) % nums.size();
        while (next != index)
        {
            swap(nums[index], nums[next]);
            next = (next + k) % nums.size();
        }
    }
}

/// <summary>
/// Leet code #414. Third Maximum Number       
/// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, 
/// return the maximum number. The time complexity must be in O(n).
/// Example 1:
/// Input: [3, 2, 1]
/// Output: 1
/// Explanation: The third maximum is 1.
/// 
/// Example 2:
/// Input: [1, 2]
/// Output: 2
/// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
///
/// Example 3:
/// Input: [2, 2, 3, 1]
/// Output: 1
/// Explanation: Note that the third maximum here means the third maximum distinct number.
/// Both numbers with value 2 are both considered as second maximum.
/// </summary>
int LeetCode::thirdMax(vector<int>& nums)
{
    vector<int> max_list;
    for (size_t i = 0; i < nums.size(); i++)
    {
        size_t index = 0;
        while (index < max_list.size())
        {
            if (nums[i] == max_list[index])
            {
                break;
            }
            else if (nums[i] > max_list[index])
            {
                swap(nums[i], max_list[index]);
            }
            index++;
        }
        if ((index == max_list.size()) && (index < 3))
        {
            max_list.push_back(nums[i]);
        }
    }
    if (max_list.size() == 3)
    {
        return max_list[2];
    }
    else if (max_list.size() == 0)
    {
        return 0;
    }
    else
    {
        return max_list[0];
    }
}

/// <summary>
/// Leet code #215. Kth Largest Element in an Array        
/// Find the kth largest element in an unsorted array. Note that it is the kth largest element 
/// in the sorted order, not the kth distinct element.  
/// For example,
/// Given [3,2,1,5,6,4] and k = 2, return 5. 
/// </summary>
int LeetCode::findKthLargest(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());
    if (nums.size() == 0) return 0;
    if (k <= (int)nums.size())
    {
        return nums[nums.size() - k];
    }
    else
    {
        return 0;
    }
}

/// <summary>
/// Leet code #419. Battleships in a Board  
/// Given an 2D board, count how many different battleships are in it. 
/// The battleships are represented with 'X's, empty slots are represented 
/// with '.'s. You may assume the following rules: 
/// You receive a valid board, made of only battleships or empty slots.
/// Battleships can only be placed horizontally or vertically. In other words, 
/// they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 
/// 1 column), where N can 
/// be of any size.
/// At least one horizontal or vertical cell separates between 
/// two battleships - there are no adjacent battleships.
/// Example:
/// X..X
/// ...X
/// ...X
/// In the above board there are 2 battleships. 
/// Invalid Example:
/// ...X
/// XXXX
/// ...X
/// This is an invalid board that you will not receive - as battleships will 
/// always have a cell separating between them. 
/// Follow up:
/// Could you do it in one-pass, using only O(1) extra memory and without 
/// modifying the value of the board?    
/// </summary>
int LeetCode::countBattleships(vector<vector<char>>& board)
{
    int count = 0;
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            if ((board[i][j] == 'X') && ((i == 0) || (board[i - 1][j] == '.')) &&
                ((j == 0) || (board[i][j - 1] == '.')))
            {
                count++;
            }
        }
    }
    return count;
}

/// <summary>
/// Leet code #398. Random Pick Index     
/// Given an array of integers with possible duplicates, randomly output the 
/// index of a given target number. 
/// You can assume that the given target number must exist in the array.  
/// 
/// Note:
/// The array size can be very large. Solution that uses too much extra 
/// space will not pass the judge. 
///
/// Example: 
/// int[] nums = new int[] {1,2,3,3,3};
/// Solution solution = new Solution(nums);
/// pick(3) should return either index 2, 3, or 4 randomly. Each index should have 
/// equal probability of returning.
/// solution.pick(3);
/// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
/// solution.pick(1);
/// </summary>
int LeetCode::pickRandom(vector<int>&nums, int target)
{
    int count = 0;
    int value = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != target) continue;
        count++;
        if (rand() % count == 0)
        {
            value = i;
        }
    }
    return value;
}

/// <summary>
/// Leet code #384. Shuffle an Array      
/// Shuffle a set of numbers without duplicates. 
/// Example: 
/// Init an array with set 1, 2, and 3.
/// int[] nums = {1,2,3};
/// Solution solution = new Solution(nums);
///
/// Shuffle the array [1,2,3] and return its result. Any permutation of 
/// [1,2,3] must equally likely to be returned solution.shuffle();
///
/// Resets the array back to its original configuration [1,2,3].
/// solution.reset(); 
/// Returns the random shuffling of array [1,2,3].
/// solution.shuffle();
/// </summary>
vector<int> LeetCode::shuffle(vector<int> nums)
{
    for (size_t i = 0; i < nums.size(); i++) {
        int pos = rand() % (nums.size());
        swap(nums[pos], nums[i]);
    }
    return nums;
}

/// <summary>
/// Leet code #448. Find All Numbers Disappeared in an Array
/// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
/// Find all the elements of [1, n] inclusive that do not appear in this array.
/// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
/// Example:
///
/// Input:
/// [4,3,2,7,8,2,3,1]
/// Output:
/// [5,6]
/// </summary>
vector<int> LeetCode::findDisappearedNumbers(vector<int>& nums)
{
    vector<int> result;
    size_t index = 0;
    while (index < nums.size())
    {
        if (nums[index] == index + 1)
        {
            index++;
        }
        else if (nums[index] == nums[nums[index] - 1])
        {
            index++;
        }
        else
        {
            swap(nums[index], nums[nums[index] - 1]);
        }
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            result.push_back(i + 1);
        }
    }
    return result;
}

/// <summary>
/// Leet code #442. Find All Duplicates in an Array
/// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
/// Find all the elements that appear twice in this array.
/// Could you do it without extra space and in O(n) runtime?
/// Example:
/// Input:
/// Input:
/// [4,3,2,7,8,2,3,1]
/// Output:
/// [2,3]
/// </summary>
vector<int> LeetCode::findDuplicates(vector<int>& nums)
{
    vector<int> result;
    size_t index = 0;
    while (index < nums.size())
    {
        if (nums[index] == index + 1)
        {
            index++;
        }
        else if (nums[index] == nums[nums[index] - 1])
        {
            index++;
        }
        else
        {
            swap(nums[index], nums[nums[index] - 1]);
        }
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            result.push_back(nums[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #475. Heaters 
/// Winter is coming! Your first job during the contest is to design a standard heater with 
/// fixed warm radius to warm all the houses.
/// Now, you are given positions of houses and heaters on a horizontal line, find out minimum 
/// radius of heaters so that all houses could be covered by those heaters.
///
/// So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
/// Note:
/// Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
/// Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
/// As long as a house is in the heaters' warm radius range, it can be warmed.
/// All the heaters follow your radius standard and the warm radius will the same.
/// Example 1:
/// Input: [1,2,3],[2]
/// Output: 1
/// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
/// Example 2:
/// Input: [1,2,3,4],[1,4]
/// Output: 1
/// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
/// </summary>
int LeetCode::findRadius(vector<int>& houses, vector<int>& heaters)
{
    int result = 0;
    sort(heaters.begin(), heaters.end());
    for (int house : houses)
    {
        vector<int>::iterator next = lower_bound(heaters.begin(), heaters.end(), house);
        vector<int>::iterator prev;
        if (next == heaters.begin())
        {
            prev = next;
        }
        else
        {
            prev = next - 1;
        }
        if (next == heaters.end())
        {
            next = next - 1;
        }

        result = max(result, min(abs(house - *next), abs(house - *prev)));
    }
    return result;
}


/// <summary>
/// Leet code #364. Nested List Weight Sum II   
/// </summary>
int LeetCode::countDepth(vector<NestedInteger>& nestedList)
{
    int depth = 1;
    for (NestedInteger ni : nestedList)
    {
        if (ni.isInteger()) continue;
        vector<NestedInteger> nextList = ni.getList();
        depth = max(depth, 1 + countDepth(nextList));
    }
    return depth;
}

/// <summary>
/// Leet code #364. Nested List Weight Sum II   
/// </summary>
int LeetCode::depthSumInverse(vector<NestedInteger>& nestedList, int depth)
{
    int sum = 0;
    for (NestedInteger ni : nestedList)
    {
        if (ni.isInteger())
        {
            sum += ni.getInteger() * depth;
        }
        else
        {
            vector<NestedInteger> nextList = ni.getList();
            sum += depthSumInverse(nextList, depth - 1);
        }
    }
    return sum;
}

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
int LeetCode::depthSumInverse(vector<NestedInteger>& nestedList)
{
    int depth = countDepth(nestedList);
    return depthSumInverse(nestedList, depth);
}

/// <summary>
/// Leet code #243. Shortest Word Distance  
/// 
/// Given a list of words and two words word1 and word2, return the shortest 
/// distance between these two words in the list. 
/// For example,
/// Assume that words = ["practice", "makes", "perfect", "coding", "makes"]. 
/// Given word1 = “coding”, word2 = “practice”, return 3. 
/// Given word1 = "makes", word2 = "coding", return 1.
/// </summary>
int LeetCode::shortestDistance(vector<string>& words, string word1, string word2)
{
    unordered_map<string, vector<int>> string_position;
    for (size_t i = 0; i < words.size(); i++)
    {
        string_position[words[i]].push_back(i);
    }
    int distance = INT_MAX;
    for (size_t i = 0; i < string_position[word1].size(); i++)
    {
        for (size_t j = 0; j < string_position[word2].size(); j++)
        {
            distance = min(distance, abs(string_position[word1][i] - string_position[word2][j]));
        }
    }
    return distance;
}

/// <summary>
/// Leet code #245. Shortest Word Distance III  
/// 
/// This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
/// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
/// word1 and word2 may be the same and they represent two individual words in the list.
/// For example,
/// Assume that words = ["practice", "makes", "perfect", "coding", "makes"]. 
/// Given word1 = “makes”, word2 = “coding”, return 1.
/// Given word1 = "makes", word2 = "makes", return 3. 
/// Note:
/// You may assume word1 and word2 are both in the list. 
/// </summary>
int LeetCode::shortestWordDistance(vector<string>& words, string word1, string word2)
{
    unordered_map<string, vector<int>> string_position;
    for (size_t i = 0; i < words.size(); i++)
    {
        string_position[words[i]].push_back(i);
    }
    int distance = INT_MAX;
    for (size_t i = 0; i < string_position[word1].size(); i++)
    {
        for (size_t j = 0; j < string_position[word2].size(); j++)
        {
            if (string_position[word1][i] == string_position[word2][j]) continue;
            distance = min(distance, abs(string_position[word1][i] - string_position[word2][j]));
        }
    }
    return distance;
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
bool LeetCode::validWordSquare(vector<string>& words)
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
/// Leet code #370. Range Addition      
/// 
/// Assume you have an array of length n initialized with all 0's and are given k update operations.
/// Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each 
/// element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
/// 
/// Return the modified array after all k operations were executed.
/// Example: 
/// Given:
/// length = 5,
/// updates = [
///    [1,  3,  2],
///    [2,  4,  3],
///    [0,  2, -2]
/// ]
///
/// Output:
/// [-2, 0, 3, 5, 3]
/// Explanation: 
/// Initial state:
/// [ 0, 0, 0, 0, 0 ]
/// After applying operation [1, 3, 2]:
/// [ 0, 2, 2, 2, 0 ]
/// After applying operation [2, 4, 3]:
/// [ 0, 2, 5, 5, 3 ]
/// After applying operation [0, 2, -2]:
/// [-2, 0, 3, 5, 3 ]
/// Hint:
/// 1.Thinking of using advanced data structures? You are thinking it too complicated.
/// 2.For each update operation, do you really need to update all elements between i and j?
/// 3.Update only the first and end element is sufficient.
/// 4.The optimal time complexity is O(k + n) and uses O(1) extra space.
/// </summary>
vector<int> LeetCode::getModifiedArray(int length, vector<vector<int>>& updates)
{
    vector<int> result(length);
    for (size_t i = 0; i < updates.size(); i++)
    {
        result[updates[i][0]] += updates[i][2];
        if (updates[i][1] + 1 < length)
        {
            result[updates[i][1] + 1] -= updates[i][2];
        }
    }
    for (int i = 1; i < length; i++)
    {
        result[i] += result[i - 1];
    }
    return result;
}

/// <summary>
/// Leet code #311. Sparse Matrix Multiplication       
/// 
/// Given two sparse matrices A and B, return the result of AB.
/// You may assume that A's column number is equal to B's row number.
/// Example:
/// A = 
/// [
///  [ 1, 0, 0],
///  [-1, 0, 3]
/// ]
/// B = 
/// [
///  [ 7, 0, 0 ],
///  [ 0, 0, 0 ],
///  [ 0, 0, 1 ]
/// ]
///
///      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
/// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
///                   | 0 0 1 |
/// </summary>
vector<vector<int>> LeetCode::multiply(vector<vector<int>>& A, vector<vector<int>>& B)
{
    if (A.size() == 0 || A[0].size() == 0 || B.size() == 0 || B[0].size() == 0)
    {
        return vector<vector<int>>();
    }
    vector<map<int, int>> matrixA(A.size()), matrixB(B[0].size());
    vector<vector<int>> C(A.size(), vector<int>(B.size()));
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] != 0) matrixA[i][j] = A[i][j];
        }
    }
    for (size_t i = 0; i < B.size(); i++)
    {
        for (size_t j = 0; j < B[i].size(); j++)
        {
            if (B[i][j] != 0) matrixB[i][j] = B[i][j];
        }
    }
    for (size_t i = 0; i < matrixA.size(); i++)
    {
        int rowA = i;
        for (auto itrA : matrixA[i])
        {
            int colA = itrA.first;
            int valA = itrA.second;
            int rowB = colA;
            for (auto itrB : matrixB[rowB])
            {
                int colB = itrB.first;
                int valB = itrB.second;
                C[rowA][colB] += valA * valB;
            }
        }
    }
    return C;
}


/// <summary>
/// Leet code #418. Sentence Screen Fitting     
/// 
/// Given a rows x cols screen and a sentence represented by a list of non-empty words, 
/// find how many times the given sentence can be fitted on the screen. 
/// 
/// Note:
/// 1.A word cannot be split into two lines. 
/// 2.The order of words in the sentence must remain unchanged.
/// 3.Two consecutive words in a line must be separated by a single space.
/// 4.Total words in the sentence won't exceed 100.
/// 5.Length of each word is greater than 0 and won't exceed 10.
/// 6.1 ≤ rows, cols ≤ 20,000.
/// 
/// Example 1: 
/// Input:
/// rows = 2, cols = 8, sentence = ["hello", "world"]
/// Output: 
/// 1
///
/// Explanation:
/// hello---
/// world---
///
/// The character '-' signifies an empty space on the screen.
///
/// Example 2: 
/// Input:
/// rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
/// 
/// Output: 
/// 2
///
/// Explanation:
/// a-bcd- 
/// e-a---
/// bcd-e-
///
/// The character '-' signifies an empty space on the screen.
///
/// Example 3: 
/// Input:
/// rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
///
/// Output: 
/// 1
///
/// Explanation:
/// I-had
/// apple
/// pie-I
/// had--
///
/// The character '-' signifies an empty space on the screen.
/// </summary>
int LeetCode::wordsTyping(vector<string>& sentence, int rows, int cols)
{
    int count = 0;
    int index = 0;
    int length = 0;
    if (sentence.size() == 0) return 0;
    for (size_t i = 0; i < sentence.size(); i++)
    {
        length += sentence[i].size() + 1;
    }
    for (int i = 0; i < rows; i++)
    {
        int char_count = cols;
        if (char_count >= length)
        {
            count += char_count / length;
            char_count %= length;
        }
        while (char_count >= (int)sentence[index].size())
        {
            char_count -= sentence[index].size();
            char_count--;
            index++;
            if (index == sentence.size())
            {
                count++;
                index = 0;
            }
        }
    }
    return count;
}

/// <summary>
/// Leet code #498. Diagonal Traverse          
/// 
/// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix 
/// in diagonal order as shown in the below image. 
///
/// Example:
///
/// Input:
/// [
///   [ 1, 2, 3 ],
///   [ 4, 5, 6 ],
///   [ 7, 8, 9 ]
/// ]
/// Output:  [1,2,4,7,5,3,6,8,9]
/// Explanation:
/// Note:
/// 1.The total number of elements of the given matrix will not exceed 10,000.
/// </summary>
vector<int> LeetCode::findDiagonalOrder(vector<vector<int>>& matrix)
{
    int direction = 1;
    pair<int, int> pos = { 0,0 };
    vector<int> result;
    if ((matrix.size() == 0) || (matrix[0].size() == 0)) return result;
    while (result.size() < matrix.size() * matrix[0].size())
    {
        result.push_back(matrix[pos.first][pos.second]);
        if (direction == 1)
        {
            if ((pos.first > 0) && (pos.second < (int)matrix[0].size() - 1))
            {
                pos.first--;
                pos.second++;
            }
            else
            {
                if (pos.second < (int)matrix[0].size() - 1)
                {
                    pos.second++;
                }
                else if (pos.first < (int)matrix.size() - 1)
                {
                    pos.first++;
                }
                direction = 0 - direction;
            }
        }
        else
        {
            if ((pos.first < (int)matrix.size() - 1) && (pos.second > 0))
            {
                pos.first++;
                pos.second--;
            }
            else
            {
                if (pos.first < (int)matrix.size() - 1)
                {
                    pos.first++;
                }
                else if (pos.second < (int)matrix[0].size() - 1)
                {
                    pos.second++;
                }
                direction = 0 - direction;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code # 531. Lonely Pixel I
///
/// Given a picture consisting of black and white pixels,
///	find the number of black lonely pixels.
///
/// The picture is represented by a 2D char array consisting
/// of 'B' and 'W', which means black and white pixels respectively.
///
/// A black lonely pixel is character 'B' that located at a specific 
/// position where the same row and same column don't have any 
/// other black pixels.
///
/// Example:
/// Input: 
/// [
///   ['W', 'W', 'B'],
///   ['W', 'B', 'W'],
///   ['B', 'W', 'W']
/// ]
///
/// Output: 3
/// Explanation: All the three 'B's are black lonely pixels.
/// Note:
/// The range of width and height of the input 2D array is [1,500].
/// </summary>
int LeetCode::findLonelyPixel(vector<vector<char>>& picture)
{
    if (picture.empty() || picture[0].empty()) return 0;
    vector<vector<int>> row_map(picture.size());
    vector<vector<int>> col_map(picture[0].size());
    for (size_t i = 0; i < picture.size(); i++)
    {
        for (size_t j = 0; j < picture[i].size(); j++)
        {
            if (picture[i][j] == 'B')
            {
                row_map[i].push_back(j);
                col_map[j].push_back(i);
            }
        }
    }
    int result = 0;
    for (size_t i = 0; i < row_map.size(); i++)
    {
        if (row_map[i].size() == 1)
        {
            int j = row_map[i][0];
            if ((col_map[j].size() == 1) && (col_map[j][0] == i))
            {
                result++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code # 533. Lonely Pixel II
///
/// Given a picture consisting of black and white pixels, and a positive 
/// integer N, find the number of black pixels located at some specific 
/// row R and column C that align with all the following rules:
///
/// Row R and column C both contain exactly N black pixels.
/// For all rows that have a black pixel at column C, they should be 
/// exactly the same as row R
///
/// The picture is represented by a 2D char array consisting of 'B' and 'W', 
/// which means black and white pixels respectively.
///
/// Example:
/// Input:                                            
/// [
///   ['W', 'B', 'W', 'B', 'B', 'W'],    
///   ['W', 'B', 'W', 'B', 'B', 'W'],    
///   ['W', 'B', 'W', 'B', 'B', 'W'],    
///   ['W', 'W', 'B', 'W', 'B', 'W']
/// ] 
///
/// N = 3
/// Output: 6
/// Explanation: All the bold 'B' are the black pixels we need 
/// (all 'B's at column 1 and 3).
///        0    1    2    3    4    5         column index                                            
/// 0    [['W', 'B', 'W', 'B', 'B', 'W'],    
/// 1     ['W', 'B', 'W', 'B', 'B', 'W'],    
/// 2     ['W', 'B', 'W', 'B', 'B', 'W'],    
/// 3     ['W', 'W', 'B', 'W', 'B', 'W']]    
/// row index
///
/// Take 'B' at row R = 0 and column C = 1 as an example:
/// Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
/// Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and 
/// row 2. They are exactly the same as row R = 0.
///
/// Note:
/// The range of width and height of the input 2D array is [1,200].	
/// </summary>
int LeetCode::findLonelyPixel(vector<vector<char>>& picture, int N)
{
    if (picture.empty() || picture[0].empty()) return 0;
    vector<vector<int>> row_map(picture.size());
    vector<vector<int>> col_map(picture[0].size());
    for (size_t i = 0; i < picture.size(); i++)
    {
        for (size_t j = 0; j < picture[i].size(); j++)
        {
            if (picture[i][j] == 'B')
            {
                row_map[i].push_back(j);
                col_map[j].push_back(i);
            }
        }
    }

    int result = 0;
    for (size_t i = 0; i < col_map.size(); i++)
    {
        if (col_map[i].size() != N) continue;
        vector<int> first_row;
        for (size_t j = 0; j < col_map[i].size(); j++)
        {
            if (first_row.empty())
            {
                if (row_map[col_map[i][j]].size() != N)
                {
                    result -= N;
                    break;
                }
                first_row = row_map[col_map[i][j]];
            }
            else if (row_map[col_map[i][j]] != first_row)
            {
                result -= N;
                break;
            }
        }
        result += N;
    }
    return result;
}

/// <summary>
/// Leet code #539. Minimum Time Difference
///
/// Given a list of 24-hour clock time points in "Hour:Minutes" format, 
/// find the minimum minutes difference between any two time points in 
/// the list.
/// 
/// Example 1:
/// Input: ["23:59","00:00"]
/// Output: 1
/// Note:
/// The number of time points in the given list is at least 2 and won't exceed 20000.
/// The input time is legal and ranges from 00:00 to 23:59.
/// </summary>
int LeetCode::findMinDifference(vector<string>& timePoints)
{
    priority_queue<int> time_line;
    for (size_t i = 0; i < timePoints.size(); i++)
    {
        string time_stamp = timePoints[i];
        size_t index = 0;
        string str;
        while (time_stamp[index] != ':')
        {
            str.push_back(time_stamp[index]);
            index++;
        }
        index++;
        int minutes = atoi(str.c_str()) * 60;
        str.clear();
        while (index != time_stamp.size())
        {
            str.push_back(time_stamp[index]);
            index++;
        }
        minutes += atoi(str.c_str());
        time_line.push(minutes);
    }
    int first = time_line.top();
    int prev = first;
    time_line.pop();
    int diff = INT_MAX;
    while (!time_line.empty())
    {
        int curr = time_line.top();
        time_line.pop();
        diff = min(diff, prev - curr);
        prev = curr;
    }
    diff = min(diff, prev + 24 * 60 - first);
    return diff;
}

/// <summary>
/// Leet code # 466. Count The Repetitions 
///
/// Define S = [s,n] as the string S which consists of n 
/// connected strings s. For example, ["abc", 3] ="abcabcabc". 
/// On the other hand, we define that string s1 can be obtained from string s2 
/// if we can remove some characters from s2 such that it becomes s1. For example, 
/// “abc” can be obtained from “abdbec” based on our definition, but it 
/// can not be obtained from “acbbe”.
/// You are given two non-empty strings s1 and s2 (each at most 100 characters long) 
/// and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, 
/// where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that 
/// [S2,M] can be obtained from S1.
///
/// Example: 
/// Input:
/// s1="acb", n1=4
/// s2="ab", n2=2
/// Return:
/// 2
/// </summary>
int LeetCode::getMaxRepetitions(string s1, int n1, string s2, int n2)
{
    int count1 = 0, count2 = 0;
    unordered_map<int, pair<int, int>> pos_map;
    int i = 0, j = 0;
    while (count1 < n1)
    {
        i = 0;
        for (i = 0; i < (int)s1.size(); i++)
        {
            if (s1[i] == s2[j])
            {
                j++;
                if (j == s2.size())
                {
                    count2++;
                    j = 0;
                    if (pos_map.count(i) > 0)
                    {
                        int distance1 = count1 * s1.size() + i - pos_map[i].first;
                        int distance2 = count2 * s2.size() - pos_map[i].second;
                        int repeat_len = n1 * s1.size() - 1 - (count1 * s1.size() + i);
                        int hop = repeat_len / distance1;
                        count1 += hop * distance1 / s1.size();
                        count2 += hop * distance2 / s2.size();
                    }
                    else
                    {
                        pos_map[i] = make_pair(count1 * s1.size() + i, count2 * s2.size());
                    }
                }
            }
        }
        count1++;
    }
    return count2 / n2;
}

/// <summary>
/// Leet code # 363. Max Sum of Rectangle No Larger Than K  
///
/// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a 
/// rectangle in the matrix such that its sum is no larger than k.
/// 
/// Example:
/// Given matrix = 
/// [
///  [1,  0, 1],
///  [0, -2, 3]
/// ]
/// k = 2
/// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
/// Note:
/// 1.The rectangle inside the matrix must have an area > 0.
/// 2.What if the number of rows is much larger than the number of columns?
/// </summary>
int LeetCode::maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
    int max_value = INT_MIN;
    if (matrix.empty() || matrix[0].empty()) return 0;
    vector<vector<int>>sum(matrix.size(), vector<int>(matrix[0].size()));
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if (j == 0)
            {
                sum[i][j] = matrix[i][j];
            }
            else
            {
                sum[i][j] = matrix[i][j] + sum[i][j - 1];
            }
        }
        if (i > 0)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                sum[i][j] = sum[i][j] + sum[i - 1][j];
            }
        }
    }
    for (size_t row1 = 0; row1 < sum.size(); row1++)
    {
        for (size_t col1 = 0; col1 < sum[0].size(); col1++)
        {
            for (size_t row2 = row1; row2 < sum.size(); row2++)
            {
                for (size_t col2 = col1; col2 < sum[0].size(); col2++)
                {
                    int sum_value = sum[row2][col2];
                    if (row1 > 0) sum_value -= sum[row1 - 1][col2];
                    if (col1 > 0) sum_value -= sum[row2][col1 - 1];
                    if ((row1 > 0) && (col1 > 0))
                    {
                        sum_value += sum[row1 - 1][col1 - 1];
                    }
                    if (sum_value <= k)
                    {
                        max_value = max(max_value, sum_value);
                    }
                }
            }
        }
    }
    return max_value;
}

/// <summary>
/// Leet code # 363. Max Sum of Rectangle No Larger Than K  
///
/// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a 
/// rectangle in the matrix such that its sum is no larger than k.
/// 
/// Example:
/// Given matrix = 
/// [
///  [1,  0, 1],
///  [0, -2, 3]
/// ]
/// k = 2
/// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
/// Note:
/// 1.The rectangle inside the matrix must have an area > 0.
/// 2.What if the number of rows is much larger than the number of columns?
/// </summary>
int LeetCode::maxSumSubmatrixII(vector<vector<int>>& matrix, int k)
{
    int max_value = INT_MIN;
    if (matrix.empty() || matrix[0].empty()) return 0;
    vector<vector<int>>sum(matrix.size(), vector<int>(matrix[0].size()));
    for (size_t col1 = 0; col1 < matrix[0].size(); col1++)
    {
        vector<int> sum(matrix.size());
        for (size_t col2 = col1; col2 < matrix[0].size(); col2++)
        {
            set<int> accumulate_set;
            accumulate_set.insert(0);
            int accumulate = 0;
            for (size_t row = 0; row < matrix.size(); row++)
            {
                sum[row] += matrix[row][col2];
                accumulate += sum[row];
                set<int>::iterator itr = accumulate_set.lower_bound(accumulate - k);
                if (itr != accumulate_set.end())
                {
                    max_value = max(max_value, accumulate - *itr);
                    if (max_value == k) return max_value;
                }
                accumulate_set.insert(accumulate);
            }
        }
    }
    return max_value;
}

/// <summary>
/// Leet code #548. Split Array with Equal Sum       
/// 
/// Given an array with n integers, you need to find if there are 
/// triplets (i, j, k) which satisfies following conditions:
/// 0 < i, i + 1 < j, j + 1 < k < n - 1
/// Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) 
/// and (k + 1, n - 1) should be equal.
/// where we define that subarray (L, R) represents a slice of the 
/// original array starting from the element indexed L to the element 
/// indexed R.
/// Example:
/// Input: [1,2,1,2,1,2,1]
/// Output: True
/// Explanation:
/// i = 1, j = 3, k = 5. 
/// sum(0, i - 1) = sum(0, 0) = 1
/// sum(i + 1, j - 1) = sum(2, 2) = 1
/// sum(j + 1, k - 1) = sum(4, 4) = 1
/// sum(k + 1, n - 1) = sum(6, 6) = 1
/// Note:
/// 1 <= n <= 2000.
/// Elements in the given array will be in range [-1,000,000, 1,000,000].
/// </summary>
bool LeetCode::splitArray(vector<int>& nums)
{
    vector<int> sum(nums.size());
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (i == 0) sum[i] = nums[i];
        else (sum[i] = sum[i - 1] + nums[i]);
    }

    for (int j = 3; j < (int)nums.size() - 3; j++)
    {
        unordered_set<int> sum_set;
        for (int i = 1; i < j - 1; i++)
        {
            if (sum[i - 1] == sum[j - 1] - sum[i])
            {
                sum_set.insert(sum[i - 1]);
            }
        }
        for (int k = j + 2; k < (int)nums.size() - 1; k++)
        {
            if (sum[k - 1] - sum[j] == sum[sum.size() - 1] - sum[k])
            {
                if (sum_set.count(sum[k - 1] - sum[j]) > 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/// <summary>
/// Leet code #566. Reshape the Matrix       
/// 
/// In MATLAB, there is a very useful function called 'reshape', which 
/// can reshape a matrix into a new one with different size but keep its 
/// original data. 
/// You're given a matrix represented by a two-dimensional array, and two 
/// positive integers r and c representing the row number and column number 
/// of the wanted reshaped matrix, respectively.
/// The reshaped matrix need to be filled with all the elements of the 
/// original matrix in the same row-traversing order as they were. 
/// If the 'reshape' operation with given parameters is possible and legal, 
/// output the new reshaped matrix; Otherwise, output the original matrix. 
/// Example 1:
/// Input: 
/// nums = 
/// [[1,2],
/// [3,4]]
/// r = 1, c = 4
/// Output: 
/// [[1,2,3,4]]
/// Explanation:
/// The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 
/// 1 * 4 matrix, fill it row by row by using the previous list.
///
/// Example 2:
/// Input: 
/// nums = 
/// [[1,2],
/// [3,4]]
/// r = 2, c = 4
/// Output: 
/// [[1,2],
/// [3,4]]
/// Explanation:
/// There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output 
/// the original matrix.
/// </summary>
vector<vector<int>> LeetCode::matrixReshape(vector<vector<int>>& nums, int r, int c)
{
    if (nums.empty() || nums[0].empty())
    {
        return nums;
    }
    if (nums.size() * nums[0].size() != r * c)
    {
        return nums;
    }
    vector<vector<int>> result(r, vector<int>(c));
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums[0].size(); j++)
        {
            int index = i * nums[0].size() + j;
            int row = index / c;
            int col = index % c;
            result[row][col] = nums[i][j];
        }
    }
    return result;
}

/// <summary>
/// Leet code #575. Distribute Candies       
/// 
/// Given an integer array with even length, where different numbers in 
/// this array represent different kinds of candies. Each number means one
/// candy of the corresponding kind. You need to distribute these candies 
/// equally in number to brother and sister. Return the maximum number of 
/// kinds of candies the sister could gain. 
/// 
/// Example 1:
/// Input: candies = [1,1,2,2,3,3]
/// Output: 3
/// Explanation:
/// There are three different kinds of candies (1, 2 and 3), and two 
/// candies for each kind.
/// Optimal distribution: The sister has candies [1,2,3] and the brother 
/// has candies [1,2,3], too. 
/// The sister has three different kinds of candies. 
/// Example 2:
/// Input: candies = [1,1,2,3]
/// Output: 2
/// Explanation: For example, the sister has candies [2,3] and the brother 
/// has candies [1,1]. 
/// The sister has two different kinds of candies, the brother has only one
/// kind of candies. 
/// Note: 
/// The length of the given array is in range [2, 10,000], and will be even.
/// The number in given array is in range [-100,000, 100,000].
/// </summary>
int LeetCode::distributeCandies(vector<int>& candies)
{
    unordered_map<int, int> candy_map;
    for (int candy : candies) candy_map[candy]++;
    return min(candy_map.size(), candies.size() / 2);
}

/// <summary>
/// Leet code #565. Array Nesting   
/// 
/// A zero-indexed array A consisting of N different integers is given. 
/// The array contains all integers in the range [0, N - 1]. 
/// Sets S[K] for 0 <= K < N are defined as follows:
/// S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.
/// Sets S[K] are finite for each K and should NOT contain duplicates.
/// Write a function that given an array A consisting of N integers, 
/// return the size of the largest set S[K] for this array.
/// Example 1:
/// Input: A = [5,4,0,3,1,6,2]
/// Output: 4
/// Explanation: 
/// A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
///
/// One of the longest S[K]:
/// S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
/// 
/// Note:
/// N is an integer within the range [1, 20,000].
/// The elements of A are all distinct.
/// Each element of array A is an integer within the range [0, N-1].
/// </summary>
int LeetCode::arrayNesting(vector<int>& nums)
{
    vector<int> lens(nums.size());
    int max_length = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (lens[i] != 0) continue;

        unordered_set<int> nums_set;
        vector<int> nums_list;
        int index = i;
        while ((nums_set.count(index) == 0) && (lens[index] == 0))
        {
            nums_set.insert(index);
            nums_list.push_back(index);
            index = nums[index];
        }
        int base = lens[index];
        for (int num : nums_list)
        {
            lens[num] = nums_list.size() + base;
        }
        max_length = max(max_length, lens[nums_list[0]]);
    }
    return max_length;
}

/// <summary>
/// Leet code #565-II. Array Nesting   
/// 
/// A zero-indexed array A consisting of N integers is given. 
/// The array contains integers in the range [0, N - 1]. 
/// Sets S[K] for 0 <= K < N are defined as follows:
/// S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.
/// Sets S[K] are finite for each K and should NOT contain duplicates.
/// Write a function that given an array A consisting of N integers, 
/// return the size of the largest set S[K] for this array.
/// Example 1:
/// Input: A = [5,4,0,3,1,6,2]
/// Output: 4
/// Explanation: 
/// A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
///
/// One of the longest S[K]:
/// S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
/// 
/// Note:
/// N is an integer within the range [1, 20,000].
/// The elements of A are all distinct.
/// Each element of array A is an integer within the range [0, N-1].
/// </summary>
int LeetCode::arrayNestingII(vector<int>& nums)
{
    vector<int> lens(nums.size());
    int max_length = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (lens[i] != 0) continue;

        unordered_map<int, int> nums_map;
        vector<int> nums_list;
        int index = i;
        while ((nums_map.count(index) == 0) && (lens[index] == 0))
        {
            nums_map[index] = nums_list.size();
            nums_list.push_back(index);
            index = nums[index];
        }
        int length = lens[index];
        // if self loop back, we can also check if base_length is 0 or not.
        if (nums_map.count(index) > 0)
        {
            // count the loop circle size
            length = nums_list.size() - nums_map[index];
            // we can also check if nums_list.back
            while (nums_list.size() > (size_t)nums_map[index])
            {
                int id = nums_list.back();
                lens[id] = length;
                nums_list.pop_back();
            }
        }

        // for unlooped part the length should keep on increasing
        while (!nums_list.empty())
        {
            int id = nums_list.back();
            length++;
            lens[id] = length;
            nums_list.pop_back();
        }
        max_length = max(max_length, length);
    }
    return max_length;
}

/// <summary>
/// Leet code #605. Can Place Flowers    
/// 
/// Suppose you have a long flowerbed in which some of the plots are 
/// planted and some are not. However, flowers cannot be planted in 
/// adjacent plots - they would compete for water and both would die.
/// Given a flowerbed (represented as an array containing 0 and 1, 
/// where 0 means empty and 1 means not empty), and a number n, return
/// if n new flowers can be planted in it without violating the 
/// no-adjacent-flowers rule.
/// Example 1:
/// Input: flowerbed = [1,0,0,0,1], n = 1
/// Output: True
///
/// Example 2:
/// Input: flowerbed = [1,0,0,0,1], n = 2
/// Output: False
/// 
/// Note:
/// 1. The input array won't violate no-adjacent-flowers rule.
/// 2. The input array size is in the range of [1, 20000].
/// 3. n is a non-negative integer which won't exceed the input array size.
/// </summary>
bool LeetCode::canPlaceFlowers(vector<int>& flowerbed, int n)
{
    int zero_count = 0;
    for (size_t i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 0) zero_count++;
        else
        {
            if (zero_count == i)
            {
                n -= zero_count / 2;
            }
            else
            {
                n -= (zero_count - 1) / 2;
            }
            zero_count = 0;
        }
    }
    if (zero_count == flowerbed.size())
    {
        n -= (zero_count + 1) / 2;
    }
    else
    {
        n -= zero_count / 2;
    }
    if (n <= 0) return true;
    else return false;
}

/// <summary>
/// Leet code #624. Maximum Distance in Arrays
/// 
/// Given m arrays, and each array is sorted in ascending order. Now you 
/// can pick up two integers from two different arrays (each array picks 
/// one) and calculate the distance. We define the distance between two 
/// integers a and b to be their absolute difference |a-b|. Your task 
/// is to find the maximum distance. 
/// Example 1:
/// Input: 
/// [
///   [1,2,3],
///   [4,5],
///   [1,2,3]
/// ]
/// Output: 4
/// Explanation: 
/// One way to reach the maximum distance 4 is to pick 1 in the first or 
/// third array and pick 5 in the second array.
/// Note:
/// 1.Each given array will have at least 1 number. There will be at least 
///   two non-empty arrays.
/// 2.The total number of the integers in all the m arrays will be in the 
///   range of [2, 10000].
/// 3.The integers in the m arrays will be in the range of [-10000, 10000].
/// </summary>
int LeetCode::maxDistance(vector<vector<int>>& arrays)
{
    priority_queue<pair<int, int>> min_queue, max_queue;
    int max_distance;
    for (size_t i = 0; i < arrays.size(); i++)
    {
        if (arrays[i].empty()) continue;
        min_queue.push(make_pair(arrays[i][0], i));
        max_queue.push(make_pair(-arrays[i][arrays[i].size() - 1], i));
        if (min_queue.size() > 2) min_queue.pop();
        if (max_queue.size() > 2) max_queue.pop();
    }
    vector<pair<int, int>> min_pairs, max_pairs;
    for (size_t i = 0; i < 2; i++)
    {
        min_pairs.push_back(min_queue.top());
        min_queue.pop();
        max_pairs.push_back(max_queue.top());
        max_queue.pop();
    }

    if (min_pairs[1].second != max_pairs[1].second)
    {
        max_distance = abs((int)(min_pairs[1].first + max_pairs[1].first));
    }
    else
    {
        max_distance = max(abs((int)(min_pairs[1].first + max_pairs[0].first)), abs((int)(min_pairs[0].first + max_pairs[1].first)));
    }
    return max_distance;
}

/// <summary>
/// Leet code #643. Maximum Average Subarray I
/// 
/// Given an array consisting of n integers, find the contiguous subarray 
/// of given length k that has the maximum average value. And you need to 
/// output the maximum average value. 
///
/// Example 1:
/// Input: [1,12,-5,-6,50,3], k = 4
/// Output: 12.75
/// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
/// Note:
/// 1 <= k <= n <= 30,000.
/// Elements of the given array will be in the range [-10,000, 10,000].
/// </summary>
double LeetCode::findMaxAverage(vector<int>& nums, int k)
{
    double sum = 0, max_sum = (double)INT_MIN;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (i >= k)
        {
            sum = sum - nums[i - k];
        }
        sum += nums[i];
        if (i >= k - 1)
        {
            max_sum = max(sum, max_sum);
        }
    }
    return (double)max_sum / k;
}

/// <summary>
/// Leet code #644. Maximum Average Subarray II
/// </summary>
double LeetCode::density(vector<double>& sum, int l, int r)
{
    if (l == 0)
    {
        return sum[r] / ((double)r + 1);
    }
    else
    {
        return (sum[r] - sum[l - 1]) / ((double)r - (double)l + 1);
    }
}

/// <summary>
/// Leet code #644. Maximum Average Subarray II
/// 
/// Given an array consisting of n integers, find the contiguous subarray 
/// whose length is greater than or equal to k that has the maximum average 
/// value. And you need to output the maximum average value. 
///
/// Example 1:
/// Input: [1,12,-5,-6,50,3], k = 4
/// Output: 12.75
/// Explanation:
/// when length is 5, maximum average value is 10.8,
/// when length is 6, maximum average value is 9.16667.
/// Thus return 12.75.
///
/// Note:
/// 1 <= k <= n <= 10,000.
/// Elements of the given array will be in range [-10,000, 10,000].
/// The answer with the calculation error less than 10^-5 will be accepted.
/// </summary>
double LeetCode::findMaxAverageII(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<double> sum(n, 0);
    for (int i = 0; i < n; i++)
    {
        // sum[i] is accumulated sum
        sum[i] += nums[i];
        if (i > 0) sum[i] += sum[i - 1];
    }

    deque<int> q;
    double result = sum[n - 1] / n;
    for (int j = k - 1; j < n; ++j)
    {
        while (q.size() >= 2 && density(sum, q[q.size() - 2], q.back() - 1) >= density(sum, q.back(), j - k))
        {
            q.pop_back();
        }
        q.push_back(j - k + 1);
        while (q.size() >= 2 && density(sum, q[0], j) <= density(sum, q[1], j))
        {
            q.pop_front();
        }
        result = max(result, density(sum, q.front(), j));
    }
    return result;
}

/// <summary>
/// Leet code #645. Set Mismatch
/// 
/// The set S originally contains numbers from 1 to n. But unfortunately, 
/// due to the data error, one of the numbers in the set got duplicated 
/// to another number in the set, which results in repetition of one number
/// and loss of another number. 
/// Given an array nums representing the data status of this set after the 
/// error. Your task is to firstly find the number occurs twice and then 
/// find the number that is missing. Return them in the form of an array. 
///
/// Example 1:
/// Input: nums = [1,2,2,4]
/// Output: [2,3]
/// Note:
/// The given array size will in the range [2, 10000].
/// The given array's numbers won't have any order.
/// </summary>
vector<int> LeetCode::findErrorNums(vector<int>& nums)
{
    vector<int> result(2);
    unordered_map<int, int> num_map;
    for (size_t i = 0; i < nums.size(); i++) num_map[nums[i]]++;
    for (size_t i = 1; i <= nums.size(); i++)
    {
        if (num_map.count(i) == 0) result[1] = i;
        else if (num_map[i] > 1)  result[0] = i;
    }
    return result;
}

/// <summary>
/// Leet code #649. Dota2 Senate
/// 
/// In the world of Dota2, there are two parties: the Radiant and the Dire. 
/// The Dota2 senate consists of senators coming from two parties. Now the 
/// senate wants to make a decision about a change in the Dota2 game. The 
/// voting for this change is a round-based procedure. In each round, each 
/// senator can exercise one of the two rights: 
/// 1. Ban one senator's right: 
///    A senator can make another senator lose all his rights in this and 
///    all the following rounds.
/// 2. Announce the victory: 
///    If this senator found the senators who still have rights to vote are 
///    all from the same party, he can announce the victory and make the 
///    decision about the change in the game.
///
/// Given a string representing each senator's party belonging. The 
/// character 'R' and 'D' represent the Radiant party and the Dire party 
/// respectively. Then if there are n senators, the size of the given 
/// string will be n. 
/// The round-based procedure starts from the first senator to the last 
/// senator in the given order. This procedure will last until the end of 
/// voting. All the senators who have lost their rights will be skipped 
/// during the procedure. 
/// Suppose every senator is smart enough and will play the best strategy 
/// for his own party, you need to predict which party will finally 
/// announce the victory and make the change in the Dota2 game. The output 
/// should be Radiant or Dire. 
/// Example 1:
/// Input: "RD"
/// Output: "Radiant"
/// Explanation: The first senator comes from Radiant and he can just ban 
/// the next senator's right in the round 1. 
/// And the second senator can't exercise any rights any more since his 
/// right has been banned. 
/// And in the round 2, the first senator can just announce the victory 
/// since he is the only guy in the senate who can vote.
///
/// Example 2:
/// Input: "RDD"
/// Output: "Dire"
/// Explanation: 
/// The first senator comes from Radiant and he can just ban the next 
/// senator's right in the round 1. 
/// And the second senator can't exercise any rights anymore since his 
/// right has been banned. 
/// And the third senator comes from Dire and he can ban the first 
/// senator's right in the round 1. 
/// And in the round 2, the third senator can just announce the victory 
/// since he is the only guy in the senate who can vote.
///
/// Note:
/// The length of the given string will in the range [1, 10,000].
/// </summary>
string LeetCode::predictPartyVictory(string senate)
{
    vector<int> count_map(2);
    while (true)
    {
        string temp;
        for (auto ch : senate)
        {
            int index = (ch == 'R' ? 0 : 1);
            if (count_map[index] > 0)
            {
                count_map[index]--;
            }
            else
            {
                temp.push_back(ch);
                count_map[1 - index]++;
            }
        }
        if (temp.size() == senate.size()) break;
        senate = temp;
    }
    if (senate[0] == 'D') return "Dire";
    else return "Radiant";
}

/// <summary>
/// Leet code #661. Image Smoother 
/// 
/// Given a 2D integer matrix M representing the gray scale of an image, 
/// you need to design a smoother to make the gray scale of each cell 
/// becomes the average gray scale (rounding down) of all the 8 
/// surrounding cells and itself. If a cell has less than 8 surrounding 
/// cells, then use as many as you can.
/// Example 1:
/// Input:
/// [
///   [1,1,1],
///   [1,0,1],
///   [1,1,1]
/// ]
/// Output:
/// [
///   [0, 0, 0],
///   [0, 0, 0],
///   [0, 0, 0]
/// ]
/// Explanation:
/// For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
/// For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = 
/// floor(0.83333333) = 0
/// For the point (1,1): floor(8/9) = floor(0.88888889) = 0
///
/// Note:
/// The value in the given matrix is in the range of [0, 255].
/// The length and width of the given matrix are in the range of [1, 150].
/// </summary>
vector<vector<int>> LeetCode::imageSmoother(vector<vector<int>>& M)
{
    vector<vector<int>> result;
    vector<pair<int, int>> step_map =
    { { -1, -1 },{ 0, -1 },{ 1, -1 },{ -1, 0 },{ 0, 0 },{ 1, 0 },{ -1, 1, },{ 0, 1 },{ 1, 1 } };
    for (size_t i = 0; i < M.size(); i++)
    {
        result.push_back(vector<int>(M[i].size()));
        for (size_t j = 0; j < M[i].size(); j++)
        {
            int count = 0, sum = 0;
            for (size_t k = 0; k < step_map.size(); k++)
            {
                int y = i + step_map[k].second;
                int x = j + step_map[k].first;
                if (x < 0 || y < 0 || y >= (int)M.size() || x >= (int)M[i].size()) continue;
                sum += M[y][x];
                count++;
            }
            result[i][j] = sum / count;
        }
    }
    return result;
}

/// <summary>
/// Leet code #667. Beautiful Arrangement II 
/// 
/// Given two integers n and k, you need to construct a list which 
/// contains n different positive integers ranging from 1 to n and 
/// obeys the following requirement: 
/// Suppose this list is [a1, a2, a3, ... , an], then the list 
/// [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly 
/// k distinct integers.
///
/// If there are multiple answers, print any of them.
///
/// Example 1:
/// Input: n = 3, k = 1
/// Output: [1, 2, 3]
/// Explanation: The [1, 2, 3] has three different positive integers 
/// ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
/// 
/// Example 2:
/// Input: n = 3, k = 2
/// Output: [1, 3, 2]
/// Explanation: The [1, 3, 2] has three different positive integers 
/// ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 
/// and 2.
/// Note:
/// 1. The n and k are in the range 1 <= k < n <= 104.
/// </summary>
vector<int> LeetCode::constructArray(int n, int k)
{
    vector<int> result;
    int first = 1, last = n;

    for (int i = 0; i < n - 1 - k; i++)
    {
        result.push_back(first);
        first++;
    }
    while (first <= last)
    {
        result.push_back(first);
        first++;
        if (first <= last) result.push_back(last);
        last--;
    }
    return result;
}

/// <summary>
/// Leet code #670. Maximum Swap 
/// 
/// Given a non-negative integer, you could swap two digits at most once 
/// to get the maximum valued number. Return the maximum valued number 
/// you could get.
///
/// Example 1:
/// Input: 2736
/// Output: 7236
/// Explanation: Swap the number 2 and the number 7.
/// Example 2:
/// Input: 9973
/// Output: 9973
/// Explanation: No swap.
/// Note:
/// The given number is in the range [0, 10^8]
/// </summary>
int LeetCode::maximumSwap(int num)
{
    string str = to_string(num);
    int result = num;
    int first = -1, last = -1;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if ((i > 0 && str[i] > str[i - 1]) && (last == -1 || str[i] > str[last]))  last = i;
    }
    first = last;
    for (int i = 0; i < last; i++)
    {
        if (str[i] < str[last])
        {
            first = i;
            break;
        }
    }

    if (first != last)
    {
        for (int i = last; i < (int)str.size(); i++)
        {
            if (str[i] == str[last]) last = i;
            string temp = str;
            swap(temp[first], temp[last]);
            result = max(atoi(temp.c_str()), num);
        }
    }
    return result;
}

/// <summary>
/// Leet code #674. Longest Continuous Increasing Subsequence 
/// 
/// Given an unsorted array of integers, find the length of longest 
/// continuous increasing subsequence.
///
/// Example 1:
/// Input: [1,3,5,4,7]
/// Output: 3
/// Explanation: The longest continuous increasing subsequence is [1,3,5], 
/// its length is 3. 
/// Even though [1,3,5,7] is also an increasing subsequence, it's not a 
/// continuous one where 5 and 7 are separated by 4. 
///
/// Example 2:
/// Input: [2,2,2,2,2]
/// Output: 1
/// Explanation: The longest continuous increasing subsequence is [2], 
/// its length is 1.
///	
/// Note: Length of the array will not exceed 10,000.
/// </summary>
int LeetCode::findLengthOfLCIS(vector<int>& nums)
{
    int count = 0, result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if ((i == 0) || (nums[i] > nums[i - 1]))
        {
            count++;
        }
        else
        {
            result = max(result, count);
            count = 1;
        }
    }
    result = max(result, count);
    return result;
}

/// <summary>
/// Leet code #678. Valid Parenthesis String
/// 
/// Given a string containing only three types of characters: '(', ')' 
/// and '*', write a function to check whether this string is valid. 
/// We define the validity of a string by these rules:
/// Any left parenthesis '(' must have a corresponding right 
/// parenthesis ')'.
/// Any right parenthesis ')' must have a corresponding left 
/// parenthesis '('.
/// Left parenthesis '(' must go before the corresponding right 
/// parenthesis ')'.
/// '*' could be treated as a single right parenthesis ')' or a single 
/// left parenthesis '(' or an empty string.
/// An empty string is also valid.
/// Example 1:
/// Input: "()"
/// Output: True
/// Example 2:
/// Input: "(*)"
/// Output: True
/// Example 3:
/// Input: "(*))"
/// Output: True
/// Note:
/// The string size will be in the range [1, 100].
/// </summary>
bool LeetCode::checkValidString(string s)
{
    // scan left to right
    int parenthesis_count = 0;
    int star_count = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '*')
        {
            star_count++;
        }
        else if (s[i] == '(')
        {
            parenthesis_count++;
        }
        else
        {
            parenthesis_count--;
            if (parenthesis_count < 0 && star_count > 0)
            {
                parenthesis_count++;
                star_count--;
            }
        }
        if (parenthesis_count < 0) return false;
    }

    // scan right to left
    parenthesis_count = 0;
    star_count = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            star_count++;
        }
        else if (s[i] == ')')
        {
            parenthesis_count++;
        }
        else
        {
            parenthesis_count--;
            if (parenthesis_count < 0 && star_count > 0)
            {
                parenthesis_count++;
                star_count--;
            }
        }
        if (parenthesis_count < 0) return false;
    }
    return true;
}

/// <summary>
/// Leet code #682. Baseball Game
/// 
/// Given a list of strings, each string can be one of the 4 following 
/// types:
///
/// Integer (one round's score): Directly represents the number of points 
/// you get in this round.
/// "+" (one round's score): Represents that the points you get in this 
///  round are the sum of the last two valid round's points.
/// "D" (one round's score): Represents that the points you get in this 
/// round are the doubled data of the last valid round's points.
/// "C" (an operation, which isn't a round's score): Represents the last 
/// valid round's points you get were invalid and should be removed.
/// Each round's operation is permanent and could have an impact on the 
/// round before and the round after.
///
/// You need to return the sum of the points you could get in all the 
/// rounds.
///
/// Example 1:
/// Input: ["5","2","C","D","+"]
/// Output: 30
/// Explanation: 
/// Round 1: You could get 5 points. The sum is: 5.
/// Round 2: You could get 2 points. The sum is: 7.
/// Operation 1: The round 2's data was invalid. The sum is: 5.  
/// Round 3: You could get 10 points (the round 2's data has been 
/// removed). The sum is: 15.
/// Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
/// Example 2:
/// Input: ["5","-2","4","C","D","9","+","+"]
/// Output: 27
/// Explanation: 
/// Round 1: You could get 5 points. The sum is: 5.
/// Round 2: You could get -2 points. The sum is: 3.
/// Round 3: You could get 4 points. The sum is: 7.
/// Operation 1: The round 3's data is invalid. The sum is: 3.  
/// Round 4: You could get -4 points (the round 3's data has been removed). 
/// The sum is: -1.
/// Round 5: You could get 9 points. The sum is: 8.
/// Round 6: You could get -4 + 9 = 5 points. The sum is 13.
/// Round 7: You could get 9 + 5 = 14 points. The sum is 27.
/// Note:
/// 1.The size of the input list will be between 1 and 1000.
/// 2.Every integer represented in the list will be between -30000 
///   and 30000.
/// </summary>
int LeetCode::calPoints(vector<string>& ops)
{
    vector<int> nums;
    int sum = 0;
    for (size_t i = 0; i < ops.size(); i++)
    {
        if (ops[i] == "C")
        {
            if (!nums.empty())
            {
                sum -= nums.back();
                nums.pop_back();
            }
        }
        else if (ops[i] == "D")
        {
            if (!nums.empty())
            {
                nums.push_back(nums.back() * 2);
                sum += nums.back();
            }
        }
        else if (ops[i] == "+")
        {
            if (!nums.empty())
            {
                int sub_total = 0;
                for (int j = (int)nums.size() - 1; j >= 0 && j >= (int)nums.size() - 2; j--)
                {
                    sub_total += nums[j];
                }
                nums.push_back(sub_total);
                sum += nums.back();
            }
        }
        else
        {
            nums.push_back(atoi(ops[i].c_str()));
            sum += nums.back();
        }
    }
    return sum;
}

/// <summary>
/// Leet code #659. Split Array into Consecutive Subsequences 
/// 
/// You are given an integer array sorted in ascending order (may contain 
/// duplicates), you need to split them into several subsequences, where 
/// each subsequences consist of at least 3 consecutive integers. 
/// Return whether you can make such a split.
///
/// Example 1:
/// Input: [1,2,3,3,4,5]
/// Output: True
/// Explanation:
/// You can split them into two consecutive subsequences : 
/// 1, 2, 3
/// 3, 4, 5
///
/// Example 2:
/// Input: [1,2,3,3,4,4,5,5]
/// Output: True
/// Explanation:
/// You can split them into two consecutive subsequences : 
/// 1, 2, 3, 4, 5
/// 3, 4, 5
/// 
/// Example 3:
/// Input: [1,2,3,4,4,5]
/// Output: False
///
/// Note:
/// 1. The length of the input is in range of [1, 10000]
/// </summary>
bool LeetCode::isPossible(vector<int>& nums)
{
    unordered_map<int, priority_queue<int, std::vector<int>, std::greater<int>>> heap_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (heap_map.count(nums[i] - 1) == 0)
        {
            heap_map[nums[i]].push(1);
        }
        else
        {
            int length = heap_map[nums[i] - 1].top();
            heap_map[nums[i] - 1].pop();
            if (heap_map[nums[i] - 1].empty())
            {
                heap_map.erase(nums[i] - 1);
            }
            heap_map[nums[i]].push(length + 1);
        }
    }

    for (auto itr : heap_map)
    {
        if (itr.second.top() < 3) return false;
    }
    return true;
}

/// <summary>
/// Leet code #696. Count Binary Substrings
///
/// Give a string s, count the number of non-empty (contiguous) substrings 
/// that have the same number of 0's and 1's, and all the 0's and all the 
/// 1's in these substrings are grouped consecutively.
///
/// Substrings that occur multiple times are counted the number of times 
/// they occur.
///
/// Example 1:
/// Input: "00110011"
/// Output: 6
/// Explanation: There are 6 substrings that have equal number of 
/// consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
///
/// Notice that some of these substrings repeat and are counted the number 
/// of times they occur.
/// 
/// Also, "00110011" is not a valid substring because all the 0's 
/// (and 1's) are not grouped together.
/// Example 2:
/// Input: "10101"
/// Output: 4
/// Explanation: There are 4 substrings: "10", "01", "10", "01" that have 
/// equal number of consecutive 1's and 0's.
/// Note:
///
/// s.length will be between 1 and 50,000.
/// s will only consist of "0" or "1" characters.
/// </summary>
int LeetCode::countBinarySubstrings(string s)
{
    vector<int> count_array;
    int result = 0;
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if ((i > 0) && (s[i] != s[i - 1]))
        {
            count_array.push_back(count);
            count = 1;
        }
        else
        {
            count++;
        }

        if ((!count_array.empty()) && (count_array.back() >= count))
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #697. Degree of an Array
///
/// Given a non-empty array of non-negative integers nums, the degree of 
/// this array is defined as the maximum frequency of any one of its 
/// elements.
/// 
/// Your task is to find the smallest possible length of a (contiguous) 
/// subarray of nums, that has the same degree as nums.
///
/// Example 1:
/// Input: [1, 2, 2, 3, 1]
/// Output: 2
/// Explanation: 
/// The input array has a degree of 2 because both elements 1 and 2 appear 
/// twice.
/// Of the subarrays that have the same degree:
/// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
/// The shortest length is 2. So return 2.
///
/// Example 2:
/// Input: [1,2,2,3,1,4,2]
/// Output: 6
/// Note:
/// 
/// nums.length will be between 1 and 50,000.
/// nums[i] will be an integer between 0 and 49,999.
/// </summary>
int LeetCode::findShortestSubArray(vector<int>& nums)
{
    int min_len = 0;
    int max_degree = 0;
    unordered_map<int, pair<int, int>> num_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (num_map.count(nums[i]) == 0)
        {
            num_map[nums[i]] = make_pair(i, 1);
        }
        else
        {
            num_map[nums[i]].second++;
        }

        if (num_map[nums[i]].second > max_degree)
        {
            max_degree = num_map[nums[i]].second;
            min_len = i - num_map[nums[i]].first + 1;
        }
        else if (num_map[nums[i]].second == max_degree)
        {
            min_len = min(min_len, (int)i - num_map[nums[i]].first + 1);
        }
    }
    return min_len;
}

/// <summary>
/// Leet code #717. 1-bit and 2-bit Characters
///
/// We have two special characters. The first character can be 
/// represented by one bit 0. The second character can be represented 
/// by two bits (10 or 11).
///
/// Now given a string represented by several bits. Return whether the 
/// last character must be a one-bit character or not. The given string 
/// will always end with a zero.
///
/// Example 1:
/// Input: 
/// bits = [1, 0, 0]
/// Output: True
/// Explanation: 
/// The only way to decode it is two-bit character and one-bit character. 
/// So the last character is one-bit character.
///
/// Example 2:
/// Input: 
/// bits = [1, 1, 1, 0]
/// Output: False
/// Explanation:  
/// The only way to decode it is two-bit character and two-bit character. 
/// So the last character is NOT one-bit character.
/// Note:
///
/// 1 <= len(bits) <= 1000.
/// bits[i] is always 0 or 1.
/// </summary>
bool LeetCode::isOneBitCharacter(vector<int>& bits)
{
    for (size_t i = 0; i < bits.size(); i++)
    {
        // two bits
        if (bits[i] == 1)
        {
            i++;
        }
        else if (i == bits.size() - 1)
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #723. Candy Crush
/// Count candy
/// </summary>
void LeetCode::countCandy(vector<vector<int>>& board, vector<vector<pair<int, int>>>& match)
{
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            int first = 0, second = 0;
            if (board[i][j] != 0)
            {
                if ((i == 0) || (board[i][j] != board[i - 1][j]))
                {
                    first = 1;
                }
                else
                {
                    first = match[i - 1][j].first + 1;
                }
                if ((j == 0) || (board[i][j] != board[i][j - 1]))
                {
                    second = 1;
                }
                else
                {
                    second = match[i][j - 1].second + 1;
                }
            }
            match[i][j] = make_pair(first, second);
        }
    }
}

/// <summary>
/// Leet code #723. Candy Crush
/// Remove candy
/// </summary>
bool LeetCode::removeCandy(vector<vector<int>>& board, vector<vector<pair<int, int>>>& match)
{
    bool result = false;
    for (int i = match.size() - 1; i >= 0; i--)
    {
        for (int j = match[i].size() - 1; j >= 0; j--)
        {
            if (match[i][j].first >= 3)
            {
                int size = match[i][j].first;
                for (int k = 0; k < size; k++)
                {
                    board[i - k][j] = 0;
                    match[i - k][j].first = 0;
                    result = true;
                }
            }
            if (match[i][j].second >= 3)
            {
                int size = match[i][j].second;
                for (int k = 0; k < size; k++)
                {
                    board[i][j - k] = 0;
                    match[i][j - k].second = 0;
                    result = true;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #723. Candy Crush
/// Drop candy
/// </summary>
void LeetCode::dropCandy(vector<vector<int>>& board)
{
    vector<int> bottom(board[0].size(), board.size() - 1);
    for (int i = board.size() - 1; i >= 0; i--)
    {
        for (int j = board[i].size() - 1; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                if (i < bottom[j]) swap(board[i][j], board[bottom[j]][j]);
                bottom[j]--;
            }
        }
    }
}

/// <summary>
/// Leet code #723. Candy Crush
///
/// This question is about implementing a basic elimination algorithm for 
/// Candy Crush. 
/// 
/// Given a 2D integer array board representing the grid of candy, 
/// different positive integers board[i][j] represent different types of 
/// candies. A value of board[i][j] = 0 represents that the cell at 
/// position (i, j) is empty. The given board represents the state of the 
/// game following the player's move. Now, you need to restore the board 
/// to a stable state by crushing candies according to the following rules:
///
/// 1. If three or more candies of the same type are adjacent vertically or 
/// horizontally, "crush" them all at the same time - these positions 
/// become empty.
/// 2. After crushing all candies simultaneously, if an empty space on the 
/// board has candies on top of itself, then these candies will drop until 
/// they hit a candy or bottom at the same time. (No new candies will drop 
/// outside the top boundary.)
/// 3. After the above steps, there may exist more candies that can be 
/// crushed. If so, you need to repeat the above steps.
/// 4. If there does not exist more candies that can be crushed (ie. the board 
/// is stable), then return the current board.
/// 
/// You need to perform the above rules until the board becomes stable, 
/// then return the current board.
///
/// Example 1:
/// Input:
/// board = 
/// [[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],
/// [410,411,412,5,414], [5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714], 
/// [810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
/// Output:
/// [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],
/// [310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],
/// [710,311,412,613,714],[810,411,512,713,1014]]
/// Explanation: 
///
/// Note:
/// 1. The length of board will be in the range [3, 50].
/// 2. The length of board[i] will be in the range [3, 50].
/// Each board[i][j] will initially start as an integer in the range 
/// [1, 2000].
/// </summary>
vector<vector<int>> LeetCode::candyCrush(vector<vector<int>>& board)
{
    vector<vector<pair<int, int>>> match(board.size(), vector<pair<int, int>>(board[0].size()));
    countCandy(board, match);
    while (removeCandy(board, match))
    {
        dropCandy(board);
        countCandy(board, match);
    }
    return board;
}

/// <summary>
/// Leet code #724. Find Pivot Index
///
/// Given an array of integers nums, write a method that returns the 
/// "pivot" index of this array.
///
/// We define the pivot index as the index where the sum of the numbers 
/// to the left of the index is equal to the sum of the numbers to the 
/// right of the index.
///
/// If no such index exists, we should return -1. If there are multiple 
/// pivot indexes, you should return the left-most pivot index.
///
/// Example 1:
/// Input: 
/// nums = [1, 7, 3, 6, 5, 6]
/// Output: 3
/// Explanation: 
/// The sum of the numbers to the left of index 3 (nums[3] = 6) is equal 
/// to the sum of numbers to the right of index 3.
/// Also, 3 is the first index where this occurs.
///
/// Example 2:
/// Input: 
/// nums = [1, 2, 3]
/// Output: -1
/// Explanation: 
/// There is no index that satisfies the conditions in the problem 
/// statement.
/// Note:
///
/// 1. The length of nums will be in the range [0, 10000].
/// 2. Each element nums[i] will be an integer in the range [-1000, 1000].
/// </summary>
int LeetCode::pivotIndex(vector<int>& nums)
{
    if (nums.empty()) return -1;
    vector<int> sum(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i == 0) sum[i] = nums[i];
        else sum[i] = sum[i - 1] + nums[i];
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        int left = 0;
        if (i != 0) left = sum[i - 1];
        if (left == sum[nums.size() - 1] - left - nums[i])
        {
            return (int)i;
        }
    }
    return -1;
}

/// <summary>
/// Leet code #750. Number Of Corner Rectangles
///
/// Given a grid where each entry is only 0 or 1, find the number of corner
/// rectangles.
/// A corner rectangle is 4 distinct 1s on the grid that form an 
/// axis-aligned rectangle. Note that only the corners need to have the 
/// value 1. Also, all four 1s used must be distinct.
///
/// Example 1:
/// Input: grid = 
/// [[1, 0, 0, 1, 0],
///  [0, 0, 1, 0, 1],
///  [0, 0, 0, 1, 0],
///  [1, 0, 1, 0, 1]]
/// Output: 1
/// Explanation: There is only one corner rectangle, with corners 
/// grid[1][2], grid[1][4], grid[3][2], grid[3][4].
/// Example 2:
/// Input: grid = 
/// [[1, 1, 1],
///  [1, 1, 1],
/// [1, 1, 1]]
/// Output: 9
/// Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 
/// rectangles, and one 3x3 rectangle.
/// Example 3:
/// Input: grid = 
/// [[1, 1, 1, 1]]
/// Output: 0
/// Explanation: Rectangles must have four distinct corners.
/// Note:
/// 1. The number of rows and columns of grid will each be in the range 
///    [1, 200].
/// 2. Each grid[i][j] will be either 0 or 1.
/// 3. The number of 1s in the grid will be at most 6000.
/// </summary>
int LeetCode::countCornerRectangles(vector<vector<int>>& grid)
{
    int result = 0;
    for (size_t i = 0; i < grid[0].size(); i++)
    {
        for (size_t j = i + 1; j < grid[0].size(); j++)
        {
            int count = 0;
            for (size_t k = 0; k < grid.size(); k++)
            {
                if (grid[k][i] == 1 && grid[k][j] == 1)
                {
                    count++;
                }
            }
            result += count * (count - 1) / 2;
        }
    }
    return result;
}

/// <summary>
/// Leet code #747. Largest Number Greater Than Twice of Others
///
/// In a given integer array nums, there is always exactly one largest 
/// element.
///
/// Find whether the largest element in the array is at least twice as 
/// much as every other number in the array.
///
/// If it is, return the index of the largest element, otherwise return -1.
///
/// Example 1:
/// Input: nums = [3, 6, 1, 0]
/// Output: 1
/// Explanation: 6 is the largest integer, and for every other number in 
/// the array x,
/// 6 is more than twice as big as x.  The index of value 6 is 1, so we 
/// return 1.
/// Example 2:
/// Input: nums = [1, 2, 3, 4]
/// Output: -1
/// Explanation: 4 isn't at least as big as twice the value of 3, so we 
/// return -1.
/// Note:
/// nums will have a length in the range [1, 50].
/// Every nums[i] will be an integer in the range [0, 99].
/// </summary>
int LeetCode::dominantIndex(vector<int>& nums)
{
    multiset<int> double_num;
    int max_index = -1;
    int max_num = INT_MIN;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (max_num < nums[i])
        {
            max_index = i;
            max_num = nums[i];
        }
        double_num.insert(nums[i] * 2);
        if (double_num.size() > 2) double_num.erase(double_num.begin());
    }
    if (max_num >= *double_num.begin()) return max_index;
    else return -1;
}

/// <summary>
/// Leet code #766. Toeplitz Matrix    
///
/// A matrix is Toeplitz if every diagonal from top-left to bottom-right 
/// has the same element.
///
/// Now given an M x N matrix, return True if and only if the matrix is 
/// Toeplitz.
///
///
/// Example 1:
///
/// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
/// Output: True
/// Explanation:
/// 1234
/// 5123
/// 9512
///
/// In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", 
/// "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are 
/// the same, so the answer is True.
///
/// Example 2:
///
/// Input: matrix = [[1,2],[2,2]]
/// Output: False
/// Explanation:
/// The diagonal "[1, 2]" has different elements.
/// Note:
/// 1. matrix will be a 2D array of integers.
/// 2. matrix will have a number of rows and columns in range [1, 20].
/// 3. matrix[i][j] will be integers in range [0, 99].
/// </summary>
bool LeetCode::isToeplitzMatrix(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) return false;
    for (size_t i = 1; i < matrix.size(); i++)
    {
        for (size_t j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] != matrix[i - 1][j - 1])
            {
                return false;
            }
        }
    }
    return true;
}

/// <summary>
/// Leetcode #779. K-th Symbol in Grammar
///
/// On the first row, we write a 0. Now in every subsequent row, we look 
/// at the previous row and replace each occurrence of 0 with 01, and each 
/// occurrence of 1 with 10.
///
/// Given row N and index K, return the K-th indexed symbol in row N. 
/// (The values of K are 1-indexed.) (1 indexed).
///
/// Examples:
/// Input: N = 1, K = 1
/// Output: 0
/// 
/// Input: N = 2, K = 1
/// Output: 0
///
/// Input: N = 2, K = 2
/// Output: 1
///
/// Input: N = 4, K = 5 
/// Output: 1
/// 
/// Explanation:
/// row 1: 0
/// row 2: 01
/// row 3: 0110
/// row 4: 01101001
/// row 5: 0110100110010110
/// Note:
/// 1. N will be an integer in the range [1, 30].
/// 2. K will be an integer in the range [1, 2^(N-1)].
/// </summary>
int LeetCode::kthGrammar(int N, int K)
{
    int length = (int)pow(2, N - 1);
    int index = K - 1;
    int result = 0;
    while (N > 1)
    {
        int half = length / 2;
        if (index >= length / 2)
        {
            index = index - length / 2;
            result ^= 1;
        }
        length /= 2;
        N--;
    }
    return result;
}

/// <summary>
/// Leet code #807. Max Increase to Keep City Skyline
/// 
/// In a 2 dimensional array grid, each value grid[i][j] represents the 
/// height of a building located there. We are allowed to increase the 
/// height of any number of buildings, by any amount (the amounts can be 
/// different for different buildings). Height 0 is considered to be a 
/// building as well. 
///
/// At the end, the "skyline" when viewed from all four directions of the 
/// grid, i.e. top, bottom, left, and right, must be the same as the 
/// skyline of the original grid. A city's skyline is the outer contour 
/// of the rectangles formed by all the buildings when viewed from a 
/// distance. See the following example.
///
/// What is the maximum total sum that the height of the buildings can be 
/// increased?
/// 
/// Example:
/// Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
/// Output: 35
/// Explanation: 
/// The grid is:
/// [ 
///   [3, 0, 8, 4], 
///   [2, 4, 5, 7],
///   [9, 2, 6, 3],
///   [0, 3, 1, 0] 
/// ]
///
/// The skyline viewed from top or bottom is: [9, 4, 8, 7]
/// The skyline viewed from left or right is: [8, 7, 9, 3]
///
/// The grid after increasing the height of buildings without affecting 
/// skylines is:
/// gridNew = 
/// [ 
///   [8, 4, 8, 7],
///   [7, 4, 7, 7],
///   [9, 4, 8, 7],
///   [3, 3, 3, 3] 
/// ]
///
/// Notes:
///
/// 1. 1 < grid.length = grid[0].length <= 50.
/// 2. All heights grid[i][j] are in the range [0, 100].
/// 3. All buildings in grid[i][j] occupy the entire grid cell: that is, they 
///   are a 1 x 1 x grid[i][j] rectangular prism.
/// </summary>
int LeetCode::maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
{
    int result = 0;
    vector<int> row(grid.size()), col(grid[0].size());

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            row[i] = max(row[i], grid[i][j]);
            col[j] = max(col[j], grid[i][j]);
        }
    }

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            result += min(row[i], col[j]) - grid[i][j];
        }
    }

    return result;
}

/// <summary>
/// Leet code #821. Shortest Distance to a Character
/// 
/// Given a string S and a character C, return an array of integers   
/// representing the shortest distance from the character C in the string.
///
/// Example 1: 
/// 1. Input: S = "loveleetcode", C = 'e'
/// 2. Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0] 
/// 3. All letters in S and C are lowercase.
/// </summary>
vector<int> LeetCode::shortestToChar(string S, char C)
{
    int last_pos = -1;
    vector<int> result(S.size());
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == C)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if ((result[j] != -1) && (result[j] <= (int)(i - j)))
                {
                    break;
                }
                result[j] = i - j;
            }
            last_pos = i;
        }
        else
        {
            if (last_pos == -1) result[i] = -1;
            else result[i] = i - last_pos;
        }
    }
    return result;
}

/// <summary>
/// Leet code #816. Ambiguous Coordinates
/// </summary>
vector<string> LeetCode::getAllDecimals(string S)
{
    vector<string> result;

    for (size_t i = 0; i < S.size(); i++)
    {
        // integter no leading zero and multiple digits
        if (i == 0)
        {
            if ((S[0] == '0') && (S.size() > 1)) continue;
        }
        // decimal no ending zero
        else if (i == 1)
        {
            if (S[S.size() - 1] == '0') continue;
        }
        // multiple digits integers decimal no leading zero, no ending zero
        else
        {
            if ((S[0] == '0') || (S[S.size() - 1] == '0')) continue;
        }
        if (i == 0) result.push_back(S);
        else
        {
            string str = S.substr(0, i);
            str.push_back('.');
            str.append(S.substr(i));
            result.push_back(str);
        }
    }
    return result;
}

/// <summary>
/// Leet code #816. Ambiguous Coordinates
/// 
/// We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  
/// Then, we removed all commas, decimal points, and spaces, and ended up 
/// with the string S.  Return a list of strings representing all 
/// possibilities for what our original coordinates could have been.
///
/// Our original representation never had extraneous zeroes, so we never 
/// started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", 
/// or any other number that can be represented with less digits.  Also, a 
/// decimal point within a number never occurs without at least one digit 
/// occuring before it, so we never started with numbers like ".1".
/// The final answer list can be returned in any order.  Also note that all 
/// coordinates in the final answer have exactly one space between them 
/// (occurring after the comma.)
/// 
/// Example 1:
/// Input: "(123)"
/// Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
/// Example 2:
/// Input: "(00011)"
/// Output:  ["(0.001, 1)", "(0, 0.011)"]
/// Explanation: 
/// 0.0, 00, 0001 or 00.01 are not allowed.
/// Example 3:
/// Input: "(0123)"
/// Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", 
/// "(0.1, 2.3)", "(0.12, 3)"]
/// Example 4:
/// Input: "(100)"
/// Output: [(10, 0)]
/// Explanation: 
/// 1.0 is not allowed.
/// 
/// Note:
///
/// 4 <= S.length <= 12.
/// S[0] = "(", S[S.length - 1] = ")", and the other elements in S are 
/// digits.
/// </summary>
vector<string> LeetCode::ambiguousCoordinates(string S)
{
    vector<string> result;

    S = S.substr(1, S.size() - 2);
    for (size_t i = 1; i < S.size(); i++)
    {
        string first_str = S.substr(0, i);
        string second_str = S.substr(i);
        vector<string> first_part = getAllDecimals(first_str);
        vector<string> second_part = getAllDecimals(second_str);

        for (string first_str : first_part)
        {
            for (string second_str : second_part)
            {
                string str = "(" + first_str + ", " + second_str + ")";
                result.push_back(str);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #822. Card Flipping Game
/// 
/// On a table are N cards, with a positive integer printed on the front 
/// and back of each card (possibly different).
///
/// We flip any number of cards, and after we choose one card. 
///
/// If the number X on the back of the chosen card is not on the front of 
/// any card, then this number X is good.
///
/// What is the smallest number that is good?  If no number is good, 
/// output 0.
///
/// Here, fronts[i] and backs[i] represent the number on the front and 
/// back of card i. 
///
/// A flip swaps the front and back numbers, so the value on the front is 
/// now on the back and vice versa.
///
/// Example:
///
/// Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
/// Output: 2
/// Explanation: If we flip the second card, the fronts are [1,3,4,4,7] 
/// and the backs are [1,2,4,1,3].
/// We choose the second card, which has number 2 on the back, and it 
/// isn't on the front of any card, so 2 is good.
///
/// Note:
/// 1.1 <= fronts.length == backs.length <= 1000.
/// 2.1 <= fronts[i] <= 2000.
/// 3.1 <= backs[i] <= 2000.
/// </summary>
int LeetCode::flipgame(vector<int>& fronts, vector<int>& backs)
{
    int result = 0;
    unordered_set<int> bad_numbers;
    for (size_t i = 0; i < fronts.size(); i++)
    {
        if (fronts[i] == backs[i])
        {
            bad_numbers.insert(fronts[i]);
        }
    }

    for (size_t i = 0; i < fronts.size(); i++)
    {
        if (bad_numbers.count(fronts[i]) == 0)
        {
            if (result == 0) result = fronts[i];
            else
            {
                result = min(result, fronts[i]);
            }
        }
        if (bad_numbers.count(backs[i]) == 0)
        {
            if (result == 0) result = backs[i];
            else
            {
                result = min(result, backs[i]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #825. Friends Of Appropriate Ages
/// 
/// Some people will make friend requests. The list of their ages is given 
/// and ages[i] is the age of the ith person. 
///
/// Person A will NOT friend request person B (B != A) if any of the 
/// following conditions are true:
///
/// age[B] <= 0.5 * age[A] + 7
/// age[B] > age[A]
/// age[B] > 100 && age[A] < 100
/// Otherwise, A will friend request B.
///
/// Note that if A requests B, B does not necessarily request A.  Also, 
/// people will not friend request themselves.
///
/// How many total friend requests are made?
///
/// Example 1:
///
/// Input: [16,16]
/// Output: 2
/// Explanation: 2 people friend request each other.
/// Example 2:
///
/// Input: [16,17,18]
/// Output: 2
/// Explanation: Friend requests are made 17 -> 16, 18 -> 17.
///
/// Example 3:
/// Input: [20,30,100,110,120]
/// Output: 
/// Explanation: Friend requests are made 110 -> 100, 120 -> 110, 
/// 120 -> 100.
///
///
/// Notes:
///
/// 1. 1 <= ages.length <= 20000.
/// 2. 1 <= ages[i] <= 120.
/// </summary>
int LeetCode::numFriendRequests(vector<int>& ages)
{
    int result = 0;
    sort(ages.begin(), ages.end());

    for (size_t i = 0; i < ages.size(); i++)
    {
        int young = (int)(ages[i] * 0.5 + 7);
        if (young < ages[i])
        {
            vector<int>::iterator first = upper_bound(ages.begin(), ages.end(), young);
            vector<int>::iterator second = upper_bound(ages.begin(), ages.end(), ages[i]);
            result += second - first - 1;
        }
    }
    return result;
}

/// <summary>
/// Leet code #826. Most Profit Assigning Work
/// 
/// We have jobs: difficulty[i] is the difficulty of the ith job, and 
/// profit[i] is the profit of the ith job. 
///
/// Now we have some workers. worker[i] is the ability of the ith worker, 
/// which means that this worker can only complete a job with difficulty 
/// at most worker[i]. 
/// 
/// Every worker can be assigned at most one job, but one job can be 
/// completed multiple times.
///
/// For example, if 3 people attempt the same job that pays $1, then the 
/// total profit will be $3.  If a worker cannot complete any job, his 
/// profit is $0.
///
/// What is the most profit we can make?
///
/// Example 1:
///
/// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], 
/// worker = [4,5,6,7]
/// Output: 100 
/// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and 
/// they get profit of [20,20,30,30] seperately.
/// Notes:
///
/// 1. 1 <= difficulty.length = profit.length <= 10000
/// 2. 1 <= worker.length <= 10000
/// 3. difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
/// </summary>
int LeetCode::maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
    vector<int>& worker)
{
    map<int, int> tasks;
    for (size_t i = 0; i < difficulty.size(); i++)
    {
        tasks[difficulty[i]] = max(tasks[difficulty[i]], profit[i]);
    }
    sort(worker.begin(), worker.end());
    int result = 0;
    auto itr = tasks.begin();
    int max_profit = 0;
    for (size_t i = 0; i < worker.size(); i++)
    {
        while ((itr != tasks.end()) && (itr->first <= worker[i]))
        {
            max_profit = std::max(max_profit, itr->second);
            ++itr;
        }
        result += max_profit;
    }
    return result;
}

/// <summary>
/// Leet code #832. Flipping an Image
/// 
/// Given a binary matrix A, we want to flip the image horizontally, then 
/// invert it, and return the resulting image.
///
/// To flip an image horizontally means that each row of the image is 
/// reversed.  For example, flipping [1, 1, 0] horizontally results in 
/// [0, 1, 1].
///
/// To invert an image means that each 0 is replaced by 1, and each 1 is 
/// replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
///
/// Example 1:
///
/// Input: [[1,1,0],[1,0,1],[0,0,0]]
/// Output: [[1,0,0],[0,1,0],[1,1,1]]
/// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
/// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
///
/// Example 2:
///
/// Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
/// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
/// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],
/// [0,1,0,1]].
/// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
/// Notes:
/// 1. 1 <= A.length = A[0].length <= 20
/// 2. 0 <= A[i][j] <= 1
/// </summary>
vector<vector<int>> LeetCode::flipAndInvertImage(vector<vector<int>>& A)
{
    vector<vector<int>> result = A;
    for (size_t i = 0; i < result.size(); i++)
    {
        int first = 0;
        int last = result[i].size() - 1;
        while (first < last)
        {
            result[i][first] = 1 - result[i][first];
            result[i][last] = 1 - result[i][last];
            swap(result[i][first], result[i][last]);
            first++;
            last--;
        }
        if (first == last)
        {
            result[i][first] = 1 - result[i][first];
        }
    }
    return result;
}

/// <summary>
/// Leet code #835. Image Overlap
/// 
/// Two images A and B are given, represented as binary, square matrices 
/// of the same size.  (A binary matrix has only 0s and 1s as values.)
///
/// We translate one image however we choose (sliding it left, right, up, 
/// or down any number of units), and place it on top of the other image.  
/// After, the overlap of this translation is the number of positions that 
/// have a 1 in both images.
///
/// (Note also that a translation does not include any kind of rotation.)
///
/// What is the largest possible overlap?
///
/// Example 1:
///
/// Input: A = [[1,1,0],
///             [0,1,0],
///             [0,1,0]]
///        B = [[0,0,0],
///             [0,1,1],
///             [0,0,1]]
/// Output: 3
/// Explanation: We slide A to right by 1 unit and down by 1 unit.
/// Notes: 
///
/// 1. 1 <= A.length = A[0].length = B.length = B[0].length <= 30
/// 2. 0 <= A[i][j], B[i][j] <= 1
/// </summary>
int LeetCode::largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int size = A.size();
    int result = 0;
    for (int delta_r = -(size - 1); delta_r <= size - 1; delta_r++)
    {
        for (int delta_c = -(size - 1); delta_c <= (size - 1); delta_c++)
        {
            int score = 0;
            for (int i = 0; i < size; i++)
            {
                if (i + delta_r < 0 || i + delta_r >= size) continue;
                for (int j = 0; j < size; j++)
                {
                    if (j + delta_c < 0 || j + delta_c >= size) continue;
                    if (A[i][j] & B[i + delta_r][j + delta_c]) score++;
                }
            }
            result = max(result, score);
        }
    }
    return result;
}

/// <summary>
/// Leet code #838. Push Dominoes
/// 
/// There are N dominoes in a line, and we place each domino vertically 
/// upright.
/// In the beginning, we simultaneously push some of the dominoes either 
/// to the left or to the right.
///
/// After each second, each domino that is falling to the left pushes the 
/// adjacent domino on the left.
///
/// Similarly, the dominoes falling to the right push their adjacent 
/// dominoes standing on the right.
///
/// When a vertical domino has dominoes falling on it from both sides, it 
/// stays still due to the balance of the forces.
///
/// For the purposes of this question, we will consider that a falling 
/// domino expends no additional force to a falling or already fallen 
/// domino.
///
/// Given a string "S" representing the initial state. S[i] = 'L', if the 
/// i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino 
/// has been pushed to the right; S[i] = '.', if the i-th domino has not 
/// been pushed.
///
/// Return a string representing the final state. 
/// 
/// Example 1:
///
/// Input: ".L.R...LR..L.."
/// Output: "LL.RR.LLRRLL.."
/// Example 2:
/// 
/// Input: "RR.L"
/// Output: "RR.L"
/// Explanation: The first domino expends no additional force on the second
/// domino.
/// Note:
/// 
/// 1. 0 <= N <= 10^5
/// 2. String dominoes contains only 'L', 'R' and '.'
/// </summary>
string LeetCode::pushDominoes(string dominoes)
{
    queue<int> process_queue;
    for (size_t i = 0; i < dominoes.size(); i++)
    {
        if (dominoes[i] != '.') process_queue.push(i);
    }
    string next = dominoes;
    while (!process_queue.empty())
    {
        size_t size = process_queue.size();
        string current = next;
        for (size_t i = 0; i < size; i++)
        {
            size_t k = process_queue.front();
            process_queue.pop();
            if (current[k] == 'L')
            {
                if ((k == 0) || ((k > 0) && (current[k - 1] != '.')) || ((k > 1) && (current[k - 2] == 'R')))
                {
                    continue;
                }
                else
                {
                    next[k - 1] = 'L';
                    process_queue.push(k - 1);
                }
            }
            else if (current[k] == 'R')
            {
                if ((k == current.size() - 1) ||
                    ((k < current.size() - 1) && (current[k + 1] != '.')) ||
                    ((k < current.size() - 2) && (current[k + 2] == 'L')))
                {
                    continue;
                }
                else
                {
                    next[k + 1] = 'R';
                    process_queue.push(k + 1);
                }
            }
        }
    }
    return next;
}

/// <summary>
/// Leet code #840. Magic Squares In Grid
/// 
/// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers 
/// from 1 to 9 such that each row, column, and both diagonals all have 
/// the same sum.
///
/// Given an grid of integers, how many 3 x 3 "magic square" subgrids are 
/// there?  (Each subgrid is contiguous).
///
/// Example 1:
///
/// Input: [
///         [4,3,8,4],
///         [9,5,1,9],
///         [2,7,6,2]
///        ]
/// Output: 1
/// Explanation: 
/// The following subgrid is a 3 x 3 magic square:
/// 438
/// 951
/// 276
///
/// while this one is not:
/// 384
/// 519
/// 762
///
/// In total, there is only one magic square inside the given grid.
/// Note:
///
/// 1. 1 <= grid.length <= 10
/// 2. 1 <= grid[0].length <= 10
/// 3. 0 <= grid[i][j] <= 15
/// </summary>
int LeetCode::numMagicSquaresInside(vector<vector<int>>& grid)
{
    int result = 0;

    for (int i = 0; i < (int)grid.size() - 2; i++)
    {
        for (int j = 0; j < (int)grid[i].size() - 2; j++)
        {
            vector<int> sum(8);
            unordered_set<int> digit_map;
            for (size_t r = 0; r < 3; r++)
            {
                for (size_t c = 0; c < 3; c++)
                {
                    sum[r] += grid[i + r][j + c];
                    if (grid[i + r][j + c] >= 1 && grid[i + r][j + c] <= 9)
                    {
                        digit_map.insert(grid[i + r][j + c]);
                    }
                    sum[3+c] += grid[i + r][j + c];
                    if (r == c) sum[6] += grid[i + r][j + c];
                    if (r + c == 2) sum[7] += grid[i + r][j + c];
                }
            }
            
            for (size_t k = 0; k < sum.size(); k++)
            {
                if (sum[k] != 15) digit_map.clear();
            }
            if (digit_map.size() != 9) continue;
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #845. Longest Mountain in Array
/// 
/// Let's call any (contiguous) subarray B (of A) a mountain if the 
/// following properties hold:
///
/// B.length >= 3
/// There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... 
/// B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
/// (Note that B could be any subarray of A, including the entire array A.)
///
/// Given an array A of integers, return the length of the longest 
/// mountain.
///  
/// Return 0 if there is no mountain.
/// 
/// Example 1:
/// Input: [2,1,4,7,3,2,5]
/// Output: 5
/// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
/// 
/// Example 2:
/// Input: [2,2,2]
/// Output: 0
/// Explanation: There is no mountain.
///
/// Note:
/// 1. 0 <= A.length <= 10000
/// 2. 0 <= A[i] <= 10000
/// </summary>
int LeetCode::longestMountain(vector<int>& A)
{
    int result = 0;
    deque<int> mountain;
    for (size_t i = 0; i < A.size(); i++)
    {
        if ((i == 0) || (A[i] == A[i - 1]))
        {
            mountain.clear();
        }
        else if (A[i] > A[i - 1])
        {
            if (mountain.size() == 2) mountain.pop_back();
            else if (mountain.size() == 3)
            {
                mountain.pop_front();
                mountain.pop_front();
            }
        }
        else if (A[i] < A[i - 1])
        {
            if ((mountain.size() == 1) || (mountain.size() == 3)) mountain.pop_back();
        }
        mountain.push_back(i);
        if (mountain.size() == 3)
        {
            result = max(result, mountain[2] - mountain[0] + 1);
        }
    }
    return result;
}

/// <summary>
/// Leet code #849. Maximize Distance to Closest Person
/// 
/// In a row of seats, 1 represents a person sitting in that seat, and 0 
/// represents that the seat is empty. 
/// 
/// There is at least one empty seat, and at least one person sitting.
///
/// Alex wants to sit in the seat such that the distance between him and the 
/// closest person to him is maximized. 
///
/// Return that maximum distance to closest person.
///
/// Example 1:
///
/// Input: [1,0,0,0,1,0,1]
/// Output: 2
/// Explanation: 
/// If Alex sits in the second open seat (seats[2]), then the closest person 
/// has distance 2.
/// If Alex sits in any other open seat, the closest person has distance 1.
/// Thus, the maximum distance to the closest person is 2.
/// Example 2:
///
/// Input: [1,0,0,0]
/// Output: 3
/// Explanation: 
/// If Alex sits in the last seat, the closest person is 3 seats away.
/// This is the maximum distance possible, so the answer is 3.
/// Note:
///
/// 1. 1 <= seats.length <= 20000
/// 2. seats contains only 0s or 1s, at least one 0, and at least one 1.
/// </summary>
int LeetCode::maxDistToClosest(vector<int>& seats)
{
    int result = 0;
    int last = 0;
    for (int i = 0; i < (int)seats.size(); i++)
    {
        if (seats[i] == 1)
        {
            if (seats[last] == 0)
            {
                result = max(i - last, result);
            }
            else
            {
                result = max((i - last) / 2, result);
            }
            last = i;
        }
        else if (i == seats.size() - 1)
        {
            result = max(i - last, result);
        }
    }
    return result;
}

/// <summary>
/// Leet code #860. Lemonade Change
/// 
/// At a lemonade stand, each lemonade costs $5. 
///
/// Customers are standing in a queue to buy from you, and order one at a time 
/// (in the order specified by bills).
///
/// Each customer will only buy one lemonade and pay with either a $5, $10, or 
/// $20 bill.  You must provide the correct change to each customer, so that 
/// the net transaction is that the customer pays $5.
///
/// Note that you don't have any change in hand at first.
///
/// Return true if and only if you can provide every customer with correct 
/// change.
/// 
/// Example 1:
/// Input: [5,5,5,10,20]
/// Output: true
/// Explanation: 
/// From the first 3 customers, we collect three $5 bills in order.
/// From the fourth customer, we collect a $10 bill and give back a $5.
/// From the fifth customer, we give a $10 bill and a $5 bill.
/// Since all customers got correct change, we output true.
///
/// Example 2:
/// Input: [5,5,10]
/// Output: true
///
/// Example 3: 
/// Input: [10,10]
/// Output: false
///
/// Example 4:
/// Input: [5,5,10,10,20]
/// Output: false
/// Explanation: 
/// From the first two customers in order, we collect two $5 bills.
/// For the next two customers in order, we collect a $10 bill and give back a 
/// $5 bill.
/// For the last customer, we can't give change of $15 back because we only 
/// have two $10 bills.
/// Since not every customer received correct change, the answer is false.
/// 
/// Note:
///
/// 1. 0 <= bills.length <= 10000
/// 2. bills[i] will be either 5, 10, or 20.
/// </summary>
bool LeetCode::lemonadeChange(vector<int>& bills)
{
    vector<int> changes(2);
    for (size_t i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5) changes[0]++;
        else if (bills[i] == 10)
        {
            if (changes[0] < 1) return false;
            changes[0]--;
            changes[1]++;			
        }
        else  // 20
        {
            if (changes[1] > 0)
            {
                changes[1]--;
                if (changes[0] < 1) return false;
                changes[0]--;
            }
            else
            {
                if (changes[0] < 3) return false;
                changes[0]-=3;
            }
        }
    }
    return true;
}


/// <summary>
/// Leet code #861. Score After Flipping Matrix
/// 
/// We have a two dimensional matrix A where each value is 0 or 1.
///
/// A move consists of choosing any row or column, and toggling each value 
/// in that row or column: changing all 0s to 1s, and all 1s to 0s.
///
/// After making any number of moves, every row of this matrix is interpreted 
/// as a binary number, and the score of the matrix is the sum of these 
/// numbers.
///
/// Return the highest possible score.
///
/// 
///
/// Example 1:
///
/// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
/// Output: 39
/// Explanation:
/// Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
/// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
/// 
/// 
/// Note:
///
/// 1. 1 <= A.length <= 20
/// 2. 1 <= A[0].length <= 20
/// 3. A[i][j] is 0 or 1.
/// </summary>
int LeetCode::matrixScore(vector<vector<int>>& A)
{
    vector<vector<int>> M = A;
    for (size_t row = 0; row < M.size(); row++)
    {
        if (M[row][0] == 0)
        {
            for (size_t col = 0; col < M[row].size(); col++)
            {
                M[row][col] = 1 - M[row][col];
            }
        }
    }

    for (size_t col = 0; col < M[0].size(); col++)
    {
        int count = 0;
        for (size_t row = 0; row < M.size(); row++)
        {
            if (M[row][col] == 1) count++;
        }
        if (count < ((int)M.size() - count))
        {
            for (size_t row = 0; row < M.size(); row++)
            {
                M[row][col] = 1 - M[row][col];
            }
        }
    }

    int result = 0;
    for (size_t row = 0; row < M.size(); row++)
    {
        int sum = 0;
        for (size_t col = 0; col < M[row].size(); col++)
        {
            sum = (sum << 1) + M[row][col];
        }
        result += sum;
    }
    return result;
}

/// <summary>
/// Leet code #862. Shortest Subarray with Sum at Least K
/// 
/// Return the length of the shortest, non-empty, contiguous subarray of A 
/// with sum at least K.
///
/// If there is no non-empty subarray with sum at least K, return -1.
///
/// Example 1:
/// Input: A = [1], K = 1
/// Output: 1
///
/// Example 2:
/// Input: A = [1,2], K = 4
/// Output: -1
///
/// Example 3:
/// Input: A = [2,-1,2], K = 3
/// Output: 3
///
/// Note:
/// 1. 1 <= A.length <= 50000
/// 2. -10 ^ 5 <= A[i] <= 10 ^ 5
/// 3. 1 <= K <= 10 ^ 9
/// </summary>
int LeetCode::shortestSubarray(vector<int>& A, int K)
{
    int result = 0;
    vector<int> sums(A.size() + 1);
    int total = 0;
    for (size_t i = 0; i <= A.size(); i++)
    {
        sums[i] = total;
        if (i < A.size()) total += A[i];
    }
    deque<int> window;
    size_t index = 0;
    for (size_t i = 0; i < sums.size(); i++)
    {
        if (window.size() > 1)
        {
            int last = window.back();
            window.pop_back();
            while (!window.empty() && sums[window.back()] >= sums[last])
            {
                window.pop_back();
            }
            window.push_back(last);
        }

        window.push_back(i);
        while (window.size() > 1)
        {
            int first = window.front();
            int last = window.back();
            if (sums[last] - sums[first] >= K)
            {
                result = (result == -1) ? (last - first) : min(result, last - first);
                window.pop_front();
            }
            else
            {
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #867. Transpose Matrix
/// 
/// Given a matrix A, return the transpose of A.
///
/// The transpose of a matrix is the matrix flipped over it's main 
/// diagonal, switching the row and column indices of the matrix.
///
/// Example 1:
///
/// Input: [[1,2,3],[4,5,6],[7,8,9]]
/// Output: [[1,4,7],[2,5,8],[3,6,9]]
///
/// Example 2:
///
/// Input: [[1,2,3],[4,5,6]]
/// Output: [[1,4],[2,5],[3,6]]
///
/// Note:
///
/// 1. 1 <= A.length <= 1000
/// 2. 1 <= A[0].length <= 1000
/// </summary>
vector<vector<int>> LeetCode::transpose(vector<vector<int>>& A)
{
    vector<vector<int>> result(A[0].size(), vector<int>(A.size()));
    for (size_t i = 0; i < A[0].size(); i++)
    {
        for (size_t j = 0; j < A.size(); j++)
        {
            result[i][j] = A[j][i];
        }
    }
    return result;
}

/// <summary>
/// Leet code #874. Walking Robot Simulation
/// 
/// A robot on an infinite grid starts at point (0, 0) and faces north.  
/// The robot can receive one of three possible types of commands:
///
/// -2: turn left 90 degrees
/// -1: turn right 90 degrees
/// 1 <= x <= 9: move forward x units
/// Some of the grid squares are obstacles. 
///
/// The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
///
/// If the robot would try to move onto them, the robot stays on the 
/// previous grid square instead (but still continues following the rest 
/// of the route.)
///
/// Return the square of the maximum Euclidean distance that the robot 
/// will be from the origin.
///  
/// Example 1:
///
/// Input: commands = [4,-1,3], obstacles = []
/// Output: 25
/// Explanation: robot will go to (3, 4)
/// 
/// Example 2:
///
/// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
/// Output: 65
/// Explanation: robot will be stuck at (1, 4) before turning left and 
/// going to (1, 8)
///
/// Note:
/// 1. 0 <= commands.length <= 10000
/// 2. 0 <= obstacles.length <= 10000
/// 3. -30000 <= obstacle[i][0] <= 30000
/// 4. -30000 <= obstacle[i][1] <= 30000
/// 5. The answer is guaranteed to be less than 2 ^ 31.
/// </summary>
int LeetCode::robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
{
    int result = 0;
    vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int direction = 0;
    unordered_set<string> obstacles_map;
    for (size_t i = 0; i < obstacles.size(); i++)
    {
        obstacles_map.insert(to_string(obstacles[i][0]) + "_" + to_string(obstacles[i][1]));
    }
    vector<int> pos = { 0,0 };
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == -1)
        {
            direction = (direction + 1) % 4;
        }
        else if (commands[i] == -2)
        {
            direction = (direction + 3) % 4;
        }
        else
        {
            int step = commands[i];
            while (step > 0)
            {
                step--;
                vector<int> next_pos = pos;
                next_pos[0] += directions[direction][0];
                next_pos[1] += directions[direction][1];
                if (obstacles_map.count(to_string(next_pos[0]) + "_" + to_string(next_pos[1])) > 0)
                {
                    break;
                }
                pos = next_pos;
                result = max(pos[0] * pos[0] + pos[1] * pos[1], result);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #883. Projection Area of 3D Shapes
/// 
/// On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned 
/// with the x, y, and z axes.
///
/// Each value v = grid[i][j] represents a tower of v cubes placed on top 
/// of grid cell (i, j).
///
/// Now we view the projection of these cubes onto the xy, yz, and zx planes.
///
/// A projection is like a shadow, that maps our 3 dimensional figure to a 2 
/// dimensional plane. 
///
/// Here, we are viewing the "shadow" when looking at the cubes from the top, 
/// the front, and the side.
///
/// Return the total area of all three projections.
///
/// Example 1:
/// Input: [[2]]
/// Output: 5
///
/// Example 2:
/// Input: [[1,2],[3,4]]
/// Output: 17
/// Explanation: 
/// Here are the three projections ("shadows") of the shape made with each 
/// axis-aligned plane.
///
/// Example 3:
/// Input: [[1,0],[0,2]]
/// Output: 8
///
/// Example 4:
/// Input: [[1,1,1],[1,0,1],[1,1,1]]
/// Output: 14
///
/// Example 5:
/// Input: [[2,2,2],[2,1,2],[2,2,2]]
/// Output: 21
///  
/// Note:
/// 1. 1 <= grid.length = grid[0].length <= 50
/// 2. 0 <= grid[i][j] <= 50
/// </summary>
int LeetCode::projectionArea(vector<vector<int>>& grid)
{
    vector<int> rows(grid.size());
    vector<int> cols(grid[0].size());
    int result = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] != 0)
            {
                result++;
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
    }
    for (size_t i = 0; i < rows.size(); i++)
    {
        result += rows[i];
    }
    for (size_t i = 0; i < cols.size(); i++)
    {
        result += cols[i];
    }
    return result;
}

/// <summary>
/// Leet code #457. Circular Array Loop
/// 
/// You are given an array of positive and negative integers. If a number n 
/// at an index is positive, then move forward n steps. Conversely, if 
/// it's negative (-n), move backward n steps. Assume the first element of 
/// the array is forward next to the last element, and the last element is 
/// backward next to the first element. Determine if there is a loop in this 
/// array. A loop starts and ends at a particular index with more than 1 
/// element along the loop. The loop must be "forward" or "backward'.
///
/// Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 
/// 0 -> 2 -> 3 -> 0.
///
/// Example 2: Given the array [-1, 2], there is no loop.
///
/// Note: The given array is guaranteed to contain no element "0".
/// Can you do it in O(n) time complexity and O(1) space complexity?
/// </summary>
bool LeetCode::circularArrayLoop(vector<int>& nums)
{
    int slow = 0;
    int fast = 0;
    int start = 0;
    int size = nums.size();
    for (size_t i = 0; i < nums.size(); i++)
    {
        if ((nums[start] > 0) != (nums[slow] > 0)) return false;
        int prev = slow;
        slow = (slow + nums[slow] + size) % size;
        if (slow == prev)
        {
            start = (slow + 1) % size;
            slow = start;
            fast = start;
        }
        else
        {
            fast = (fast + nums[fast] + size) % size;
            if ((nums[start] > 0) != (nums[slow] > 0)) return false;
            int prev = fast;
            fast = (fast + nums[fast] + size) % size;
            if ((nums[start] > 0) != (nums[slow] > 0)) return false;
            if (fast == prev) continue;
            if (slow == fast) return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #885. Spiral Matrix III
/// 
/// On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) 
/// facing east.
///
/// Here, the north-west corner of the grid is at the first row and column, 
/// and the south-east corner of the grid is at the last row and column.
///
/// Now, we walk in a clockwise spiral shape to visit every position in this 
/// grid. 
///
/// Whenever we would move outside the boundary of the grid, we continue our 
/// walk outside the grid (but may return to the grid boundary later.) 
///
/// Eventually, we reach all R * C spaces of the grid.
///
/// Return a list of coordinates representing the positions of the grid in 
/// the order they were visited.
///
/// Example 1:
///
/// Input: R = 1, C = 4, r0 = 0, c0 = 0
/// Output: [[0,0],[0,1],[0,2],[0,3]]
///
/// Example 2:
///
/// Input: R = 5, C = 6, r0 = 1, c0 = 4
/// Output: 
/// [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],
///  [3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],
///  [0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
///
/// Note:
/// 1. 1 <= R <= 100
/// 2. 1 <= C <= 100
/// 3. 0 <= r0 < R
/// 4. 0 <= c0 < C
/// </summary>
vector<vector<int>> LeetCode::spiralMatrixIII(int R, int C, int r0, int c0)
{
    vector<vector<int>> result;
    vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    size_t step = 1;
    int direction = 0;
    int row = r0;
    int col = c0;
    while (result.size() < (size_t)(R * C))
    {
        for (size_t i = 0; i < step; i++)
        {
            if ((row >= 0) && (col >= 0) && (row < R) && (col < C))
            {
                result.push_back({ row, col });
            }
            row += directions[direction][0];
            col += directions[direction][1];
        }		
        direction = (direction + 1) % 4;
        if (direction == 0 || direction == 2) step++;
    }
    return result;
}

/// <summary>
/// Leet code #888. Fair Candy Swap
/// 
/// Alice and Bob have candy bars of different sizes: A[i] is the size of the 
/// i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of 
/// candy that Bob has.
///
/// Since they are friends, they would like to exchange one candy bar each so 
/// that after the exchange, they both have the same total amount of candy.  
/// (The total amount of candy a person has is the sum of the sizes of candy 
/// bars they have.)
///
/// Return an integer array ans where ans[0] is the size of the candy bar that 
/// Alice must exchange, and ans[1] is the size of the candy bar that Bob must 
/// exchange.
///
/// If there are multiple answers, you may return any one of them.  It is 
/// guaranteed an answer exists.
///
/// Example 1:
/// Input: A = [1,1], B = [2,2]
/// Output: [1,2]
///
/// Example 2:
/// Input: A = [1,2], B = [2,3]
/// Output: [1,2]
///
/// Example 3:
/// Input: A = [2], B = [1,3]
/// Output: [2,3]
///
/// Example 4:
/// Input: A = [1,2,5], B = [2,4]
/// Output: [5,4]
/// 
/// Note:
/// 1. 1 <= A.length <= 10000
/// 2. 1 <= B.length <= 10000
/// 3. 1 <= A[i] <= 100000
/// 4. 1 <= B[i] <= 100000
/// 5. It is guaranteed that Alice and Bob have different total amounts of 
///    candy.
/// 6. It is guaranteed there exists an answer.
/// </summary>
vector<int> LeetCode::fairCandySwap(vector<int>& A, vector<int>& B)
{
    vector<int> result;
    unordered_set<int> A_set;
    int sum_a = 0;
    int sum_b = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        sum_a += A[i];
        A_set.insert(A[i]);
    }

    for (size_t i = 0; i < B.size(); i++)
    {
        sum_b += B[i];
    }

    for (size_t i = 0; i < B.size(); i++)
    {
        int target_a = B[i] - (sum_b - sum_a) / 2;
        if (A_set.count(target_a) > 0)
        {
            result.push_back(target_a);
            result.push_back(B[i]);
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #892. Surface Area of 3D Shapes
/// 
/// On a N * N grid, we place some 1 * 1 * 1 cubes.
///
/// Each value v = grid[i][j] represents a tower of v cubes placed on top of 
/// grid cell (i, j).
///
/// Return the total surface area of the resulting shapes. 
///
/// Example 1:
/// Input: [[2]]
/// Output: 10
///
/// Example 2: 
/// Input: [[1,2],[3,4]]
/// Output: 34
///
/// Example 3:
/// Input: [[1,0],[0,2]]
/// Output: 16
///
/// Example 4:
/// Input: [[1,1,1],[1,0,1],[1,1,1]]
/// Output: 32
///
/// Example 5: 
/// Input: [[2,2,2],[2,1,2],[2,2,2]]
/// Output: 46
/// 
/// Note:
/// 
/// 1. 1 <= N <= 50
/// 2. 0 <= grid[i][j] <= 50
/// </summary>
int LeetCode::surfaceArea(vector<vector<int>>& grid)
{
    int result = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 0) continue;
            // top and bottom
            result += 2;
            // front 
            if (i == 0) result += grid[i][j];
            else if (grid[i][j] > grid[i - 1][j]) result += grid[i][j] - grid[i - 1][j];

            // back
            if (i == grid.size() - 1) result += grid[i][j];
            else if (grid[i][j] > grid[i + 1][j]) result += grid[i][j] - grid[i + 1][j];

            // left
            if (j == 0) result += grid[i][j];
            else if (grid[i][j] > grid[i][j - 1]) result += grid[i][j] - grid[i][j - 1];

            // right
            if (j == grid[0].size() - 1) result += grid[i][j];
            else if (grid[i][j] > grid[i][j + 1]) result += grid[i][j] - grid[i][j + 1];
        }
    }
    return result;
}

/// <summary>
/// Leet code #896. Monotonic Array 
/// 
/// An array is monotonic if it is either monotone increasing or monotone 
/// decreasing.
///
/// An array A is monotone increasing if for all i <= j, A[i] <= A[j].  
/// An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
///
/// Return true if and only if the given array A is monotonic.
///
/// Example 1:
/// Input: [1,2,2,3]
/// Output: true
///
/// Example 2:
/// Input: [6,5,4,4]
/// Output: true
///
/// Example 3:
/// Input: [1,3,2]
/// Output: false
///
/// Example 4:
/// Input: [1,2,4,5]
/// Output: true
///
/// Example 5:
/// Input: [1,1,1]
/// Output: true
/// Note:
/// 1. 1 <= A.length <= 50000
/// 2. -100000 <= A[i] <= 100000
/// </summary>
bool LeetCode::isMonotonic(vector<int>& A)
{
    int trend = 0;
    for (size_t i = 1; i < A.size(); i++)
    {
        if (A[i - 1] < A[i])
        {
            if (trend == -1) return false;
            trend = 1;
        }
        else if (A[i - 1] > A[i])
        {
            if (trend == 1) return false;
            trend = -1;
        }
    }
    return true;
}

/// <summary>
/// Leet code #905. Sort Array By Parity
/// 
/// Given an array A of non-negative integers, return an array 
/// consisting of all the even elements of A, followed by all 
/// the odd elements of A.
///
/// You may return any answer array that satisfies this condition.
///
/// Example 1:
/// Input: [3,1,2,4]
/// Output: [2,4,3,1]
/// The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
/// 
/// Note:
/// 1. 1 <= A.length <= 5000
/// 2. 0 <= A[i] <= 5000
/// </summary>
vector<int> LeetCode::sortArrayByParity(vector<int>& A)
{
    vector<int> result(A.size());
    int first = 0;
    int last = A.size() - 1;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 == 0)
        {
            result[first] = A[i];
            first++;
        }
        else
        {
            result[last] = A[i];
            last--;
        }
    }
    return result;
}


/// <summary>
/// Leet code #922. Sort Array By Parity II
/// 
/// Given an array A of non-negative integers, half of the integers in A are 
/// odd, and half of the integers are even.
///
/// Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] 
/// is even, i is even.
///
/// You may return any answer array that satisfies this condition.
///
/// 
/// Example 1:
///
/// Input: [4,2,5,7]
/// Output: [4,5,2,7]
/// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
/// 
///
/// Note:
///
/// 1. 2 <= A.length <= 20000
/// 2. A.length % 2 == 0
/// 3. 0 <= A[i] <= 1000
/// </summary>
vector<int> LeetCode::sortArrayByParityII(vector<int>& A)
{
    size_t even = 0;
    size_t odd = 1;
    vector<int> result = A;
    while (even < A.size())
    {
        if (result[even] % 2 == 0) even +=2;
        else
        {
            while ((odd < A.size()) && (result[odd] % 2 == 1)) odd += 2;
            swap(result[even], result[odd]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #918. Maximum Sum Circular Subarray
/// 
/// Given a circular array C of integers represented by A, find the maximum 
/// possible sum of a non-empty subarray of C.
///
/// Here, a circular array means the end of the array connects to the 
/// beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, 
/// and C[i+A.length] = C[i] when i >= 0.)
///
/// Also, a subarray may only include each element of the fixed buffer A at 
/// most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does 
/// not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
///
///
/// Example 1:
/// Input: [1,-2,3,-2]
/// Output: 3
/// Explanation: Subarray [3] has maximum sum 3
///
/// Example 2:
/// Input: [5,-3,5]
/// Output: 10
/// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
///
/// Example 3: 
/// Input: [3,-1,2,-1]
/// Output: 4
/// Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
///
/// Example 4:
/// Input: [3,-2,2,-3]
/// Output: 3
/// Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
//
/// Example 5:
/// Input: [-2,-3,-1]
/// Output: -1
/// Explanation: Subarray [-1] has maximum sum -1
///  
///
/// Note:
///
/// 1. -30000 <= A[i] <= 30000
/// 2. 1 <= A.length <= 30000
/// 
/// </summary>
int LeetCode::maxSubarraySumCircular(vector<int>& A)
{
    vector<int> dp(A.size());
    vector<int> right(A.size());
    int sum = 0;
    // calculate sum from index i to end;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        right[i] = sum + A[i];
        sum += A[i];
    }
    sum = 0;
    int max_left = 0;
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (i == 0)
        {
            dp[i] = A[i];
            sum += A[i];
            max_left = A[i];
            result = A[i];
        }
        else
        {
            // calculate max sum on subarry end with i;
            dp[i] = max(A[i], dp[i - 1] + A[i]);
            result = max(result, dp[i]);
            // calculate max circular sum starting from i;
            result = max(result, max_left + right[i]);
            // calculate sum from index 0
            sum += A[i];
            max_left = max(max_left, sum);
        }
    }
    return result;
}

/// <summary>
/// Leet code #926. Flip String to Monotone Increasing 
/// 
/// A string of '0's and '1's is monotone increasing if it consists of some 
/// number of '0's (possibly 0), followed by some number of '1's (also 
/// possibly 0.)
///
/// We are given a string S of '0's and '1's, and we may flip any '0' to a '1' 
/// or a '1' to a '0'.
///
/// Return the minimum number of flips to make S monotone increasing.
///
/// 
/// Example 1:
/// Input: "00110"
/// Output: 1
/// Explanation: We flip the last digit to get 00111.
///
/// Example 2:
/// Input: "010110"
/// Output: 2
/// Explanation: We flip to get 011111, or alternatively 000111.
///
/// Example 3:
/// Input: "00011000"
/// Output: 2
/// Explanation: We flip to get 00000000.
/// 
/// Note:
///
/// 1. 1 <= S.length <= 20000
/// 2. S only consists of '0' and '1' characters.
/// </summary>
int LeetCode::minFlipsMonoIncr(string S)
{
    vector<pair<char, int>> chars;
    int zero = 0;
    int one = 0;
    int result = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (i == 0)
        {
            chars.push_back({ S[i], 1 });
        }
        else if (S[i] == chars.back().first)
        {
            chars.back().second++;
        }
        else
        {
            chars.push_back({ S[i], 1 });
        }
        if (S[i] == '0') zero++;
        else one++;
    }

    int first = 0;
    int last = chars.size() - 1;
    while (first < last)
    {
        if (chars[first].first == '0')
        {
            zero -= chars[first].second;
            first++;
        }
        else if (chars[last].first == '1')
        {
            one -= chars[last].second;
            last--;
        }
        else
        {
            if (zero < one)
            {
                result += chars[last].second;
                zero -= chars[last].second;
                last--;
            }
            else
            {
                result += chars[first].second;
                one -= chars[first].second;
                first++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #927. Three Equal Parts
/// 
/// Given an array A of 0s and 1s, divide the array into 3 non-empty parts 
/// such that all of these parts represent the same binary value.
///
/// If it is possible, return any [i, j] with i+1 < j, such that:
///
/// A[0], A[1], ..., A[i] is the first part;
/// A[i+1], A[i+2], ..., A[j-1] is the second part, and
/// A[j], A[j+1], ..., A[A.length - 1] is the third part.
/// All three parts have equal binary value.
/// If it is not possible, return [-1, -1].
///
/// Note that the entire part is used when considering what binary value it 
/// represents.  For example, [1,1,0] represents 6 in decimal, not 3.  Also, 
/// leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.
///
/// Example 1:
/// Input: [1,0,1,0,1]
/// Output: [0,3]
///
/// Example 2:
/// Input: [1,1,0,1,1]
/// Output: [-1,-1]
///
/// Note:
/// 
/// 1. 3 <= A.length <= 30000
/// 2. A[i] == 0 or A[i] == 1
/// </summary>
vector<int> LeetCode::threeEqualParts(vector<int>& A)
{
    vector<int> ones;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == 1) ones.push_back(i);
    }

    if (ones.size() % 3 != 0)
    {
        return { -1, -1 };
    }
    else if (ones.empty())
    {
        return { 0, 2 };
    }
    else
    {
        // calculate end position
        int first = ones[ones.size() / 3 - 1];
        int second = ones[ones.size() / 3 * 2 - 1];
        int third = ones[ones.size() - 1];
        int tail = A.size() - 1 - third;
        int j = second + tail + 1;
        if (j > third)
        {
            return { -1, -1 };
        }
        else
        {
            int i = first + j - second - 1;
            if (i >= second)
            {
                return { -1, -1 };
            }
            else
            {
                vector<vector<int>> dp;
                int k = 0;
                for (k = 0; k <= i; k++)
                {
                    if (A[k] != 0) break;
                }
                vector<int> one (A.begin() + k, A.begin() + i + 1);

                for (k = i+1; k < j; k++)
                {
                    if (A[k] != 0) break;
                }
                vector<int> two(A.begin() + k, A.begin() + j);
                
                for (k = j; k < (int)A.size(); k++)
                {
                    if (A[k] != 0) break;
                }
                vector<int> three(A.begin() + k, A.end());

                if (one == two && two == three)
                {
                    return{ i, j };
                }
                else
                {
                    return{ -1, -1 };
                }
            }
        }
    }
}

/// <summary>
/// Leet code #936. Stamping The Sequence
/// </summary>
vector<int> LeetCode::searchStamp(string &stamp, string& target, int &reduce)
{
    vector<int> result;
    size_t pos = 0;
    while (pos + stamp.size() <= target.size())
    {
        bool bMatch = true;
        int temp = reduce;
        for (size_t i = pos; i < pos + stamp.size(); i++)
        {
            if (target[i] != '?') reduce++;
            if (target[i] != stamp[i - pos] && target[i] != '?')
            {
                bMatch = false;
                break;
            }
        }
        if (temp != reduce && bMatch)
        {
            for (size_t i = pos; i < pos + stamp.size(); i++) target[i] = '?';
            result.push_back(pos);
            pos += stamp.size();
        }
        else
        {
            reduce = temp;
            pos++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #936. Stamping The Sequence
/// 
/// You want to form a target string of lowercase letters.
///
/// At the beginning, your sequence is target.length '?' marks.  You also 
/// have a stamp of lowercase letters.
///
/// On each turn, you may place the stamp over the sequence, and replace 
/// every letter in the sequence with the corresponding letter from the stamp.
/// You can make up to 10 * target.length turns.
///
/// For example, if the initial sequence is "?????", and your stamp is "abc",  
/// then you may make "abc??", "?abc?", "??abc" in the first turn.  (Note that 
/// the stamp must be fully contained in the boundaries of the sequence in 
/// order to stamp.)
///
/// If the sequence is possible to stamp, then return an array of the index of 
/// the left-most letter being stamped at each turn.  If the sequence is not 
/// possible to stamp, return an empty array.
///
/// For example, if the sequence is "ababc", and the stamp is "abc", then we 
/// could return the answer [0, 2], corresponding to the moves "?????" -> 
/// "abc??" -> "ababc".
///
/// Also, if the sequence is possible to stamp, it is guaranteed it is possible
/// to stamp within 10 * target.length moves.  Any answers specifying more than
/// this number of moves will not be accepted.
///
/// Example 1:
/// Input: stamp = "abc", target = "ababc"
/// Output: [0,2]
/// ([1,0,2] would also be accepted as an answer, as well as some other 
///  answers.)
///
/// Example 2:
/// 
/// Input: stamp = "abca", target = "aabcaca"
/// Output: [3,0,1]
/// 
///
/// Note:
/// 1. 1 <= stamp.length <= target.length <= 1000
/// 2. stamp and target only contain lowercase letters.
/// </summary>
vector<int> LeetCode::movesToStamp(string stamp, string target)
{
    vector<int> result;
    int reduce = 0;
    while (reduce < (int)target.size())
    {
        vector<int> temp = searchStamp(stamp, target, reduce);
        if (temp.empty()) return temp;
        for (int i = (int)temp.size() - 1; i >= 0; i--)
        {
            result.push_back(temp[i]);
        }
    }

    std::reverse(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #939. Minimum Area Rectangle
/// 
/// Given a set of points in the xy-plane, determine the minimum area of a 
/// rectangle formed from these points, with sides parallel to the x and y 
/// axes.
///
/// If there isn't any rectangle, return 0.
/// 
/// Example 1:
///
/// Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
/// Output: 4
///
/// Example 2:
/// 
/// Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
/// Output: 2
///  
/// Note:
///
/// 1. 1 <= points.length <= 500
/// 2. 0 <= points[i][0] <= 40000
/// 3. 0 <= points[i][1] <= 40000
/// 4. All points are distinct.
/// </summary>
int LeetCode::minAreaRect(vector<vector<int>>& points)
{
    unordered_map<int, set<int>> coord_map;
    int result = INT_MAX;

    for (size_t i = 0; i < points.size(); i++)
    {
        coord_map[points[i][0]].insert(points[i][1]);
    }

    for (auto i = coord_map.begin(); i != coord_map.end(); i++)
    {
        auto j = i;
        j++;
        for (; j != coord_map.end(); j++)
        {
            int x_dist = abs(j->first - i->first);
            size_t size = min(i->second.size(), j->second.size());
            vector<int> y(size);
            auto itr = set_intersection(i->second.begin(), i->second.end(), j->second.begin(), j->second.end(), y.begin());
            y.resize(itr - y.begin());
            for (size_t k = 1; k < y.size(); k++)
            {
                int area = (y[k] - y[k - 1]) * x_dist;
                result = min(result, area);
            }
        }
    }

    return (result == INT_MAX) ? 0 : result;
}

/// <summary>
/// Leet code #944. Delete Columns to Make Sorted
/// 
/// We are given an array A of N lowercase letter strings, all of the same 
/// length.
///
/// Now, we may choose any set of deletion indices, and for each string, we 
/// delete all the characters in those indices.
///
/// For example, if we have a string "abcdef" and deletion indices {0, 2, 3}, 
/// then the final string after deletion is "bef".
///
/// Suppose we chose a set of deletion indices D such that after deletions, 
/// each remaining column in A is in non-decreasing sorted order.
///
/// Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]]
///
/// Return the minimum possible value of D.length.
///
/// 
/// Example 1:
/// Input: ["cba","daf","ghi"]
/// Output: 1
///
/// Example 2:
/// Input: ["a","b"]
/// Output: 0
///
/// Example 3:
/// Input: ["zyx","wvu","tsr"]
/// Output: 3
/// Note:
/// 1. 1 <= A.length <= 100
/// 2. 1 <= A[i].length <= 1000
/// </summary>
int LeetCode::minDeletionSize(vector<string>& A)
{
    int result = 0;
    for (size_t i = 0; i < A[0].size(); i++)
    {
        for (size_t j = 1; j < A.size(); j++)
        {
            if (A[j][i] < A[j -1][i])
            {
                result++;
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #945. Minimum Increment to Make Array Unique
/// 
/// Given an array of integers A, a move consists of choosing any A[i], 
/// and incrementing it by 1.
///
/// Return the least number of moves to make every value in A unique.
///
/// Example 1:
/// Input: [1,2,2]
/// Output: 1
/// Explanation:  After 1 move, the array could be [1, 2, 3].
///
/// Example 2:
/// Input: [3,2,1,2,1,7]
/// Output: 6
/// Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
/// It can be shown with 5 or less moves that it is impossible for the 
/// array to have all unique values.
/// 
/// Note:
/// 1. 0 <= A.length <= 40000
/// 2. 0 <= A[i] < 40000
/// </summary>
int LeetCode::minIncrementForUnique(vector<int>& A)
{
    map<int, int> num_count;	
    for (auto x : A) num_count[x]++;
    int result = 0;
    auto itr = num_count.begin();
    int empty = itr->first;
    while (itr != num_count.end())
    {
        if (itr->second < 2)
        {
            itr++;
            continue;
        }
        if (itr->second > 1)
        {
            if (empty <= itr->first) empty = itr->first + 1;
            while (num_count.count(empty) != 0)
            {
                empty++;
            }
            result += empty - itr->first;
            empty++;
            itr->second --;
        }
    }
    return result;
}

/// <summary>
/// Leet code #950. Reveal Cards In Increasing Order
/// 
/// In a deck of cards, every card has a unique integer.  You can order 
/// the deck in any order you want.
///
/// Initially, all the cards start face down (unrevealed) in one deck.
///
/// Now, you do the following steps repeatedly, until all cards are 
/// revealed:
///
/// Take the top card of the deck, reveal it, and take it out of the deck.
/// If there are still cards in the deck, put the next top card of the  
/// deck at the bottom of the deck.
/// If there are still unrevealed cards, go back to step 1.  Otherwise, 
/// stop.
/// Return an ordering of the deck that would reveal the cards in 
/// increasing order.
/// 
/// The first entry in the answer is considered to be the top of the deck.
///
///
///
/// Example 1:
///
/// Input: [17,13,11,2,3,5,7]
/// Output: [2,13,3,11,5,17,7]
/// Explanation: 
/// We get the deck in the order [17,13,11,2,3,5,7] (this order doesn't 
/// matter), and reorder it.
/// After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is 
/// the top of the deck.
/// We reveal 2, and move 13 to the bottom.  The deck is now 
/// [3,11,5,17,7,13].
/// We reveal 3, and move 11 to the bottom.  The deck is now 
/// [5,17,7,13,11].
/// We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
/// We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
/// We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
/// We reveal 13, and move 17 to the bottom.  The deck is now [17].
/// We reveal 17.
/// Since all the cards revealed are in increasing order, the answer is 
/// correct.
///
///
/// Note:
/// 1. 1 <= A.length <= 1000
/// 2. 1 <= A[i] <= 10^6
/// 3. A[i] != A[j] for all i != j
/// </summary>
vector<int> LeetCode::deckRevealedIncreasing(vector<int>& deck)
{
    vector<int> index;
    sort(deck.begin(), deck.end());
    queue<int> search;
    for (size_t i = 0; i < deck.size(); i++) search.push(i);

    while (!search.empty())
    {
        index.push_back(search.front());
        search.pop();
        if (!search.empty())
        {
            search.push(search.front());
            search.pop();
        }
    }
    vector<int> result(deck.size());
    for (size_t i = 0; i < result.size(); i++)
    {
        result[index[i]] = deck[i];
    }
    return result;
}

/// <summary>
/// Leet code #961. N-Repeated Element in Size 2N Array
/// 
/// In a array A of size 2N, there are N+1 unique elements, and exactly one 
/// of these elements is repeated N times.
///
/// Return the element repeated N times.
///
/// Example 1:
/// Input: [1,2,3,3]
/// Output: 3
///
/// Example 2:
/// Input: [2,1,2,5,3,2]
/// Output: 2
///
/// Example 3:
/// Input: [5,1,5,2,5,3,5,4]
/// Output: 5 
///
/// Note:
/// 1. 4 <= A.length <= 10000
/// 2. 0 <= A[i] < 10000
/// 3. A.length is even
/// </summary>
int LeetCode::repeatedNTimes(vector<int>& A)
{
    deque<int> line;
    for (size_t i = 0; i < A.size(); i ++)
    {
        if (line.size() < 2)
        {
            line.push_back(A[i]);
        }
        else
        {
            if (line[0] == A[i] || line[1] == A[i])
            {
                return A[i];
            }
            line.pop_front();
            line.push_back(A[i]);
        }
    }
    return line[1];
}

/// <summary>
/// Leet code #985. Sum of Even Numbers After Queries
/// 
/// We have an array A of integers, and an array queries of queries.
/// For the i-th query val = queries[i][0], index = queries[i][1], we 
/// add val to A[index].  Then, the answer to the i-th query is the 
/// sum of the even values of A.
///
/// (Here, the given index = queries[i][1] is a 0-based index, and 
/// each query permanently modifies the array A.)
///
/// Return the answer to all queries.  Your answer array should have 
/// answer[i] as the answer to the i-th query.
///
/// Example 1:
/// 
/// Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
/// Output: [8,6,2,4]
/// Explanation: 
/// At the beginning, the array is [1,2,3,4].
/// 1. After adding 1 to A[0], the array is [2,2,3,4], and the sum of 
///    even values is 2 + 2 + 4 = 8.
/// 2. After adding -3 to A[1], the array is [2,-1,3,4], and the sum 
///    of even values is 2 + 4 = 6.
/// 3. After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of 
///    even values is -2 + 4 = 2.
/// 4. After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of 
///    even values is -2 + 6 = 4.
/// 
/// Note:
/// 1. 1 <= A.length <= 10000
/// 2. -10000 <= A[i] <= 10000
/// 3. 1 <= queries.length <= 10000
/// 4. -10000 <= queries[i][0] <= 10000
/// 5. 0 <= queries[i][1] < A.length
/// </summary>
vector<int> LeetCode::sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries)
{
    int sum = 0;
    vector<int> result;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 == 0) sum += A[i];
    }

    for (size_t i = 0; i < queries.size(); i++)
    {
        int index = queries[i][1];
        if (A[index] % 2 == 0) sum -= A[index];
        A[index] += queries[i][0];
        if (A[index] % 2 == 0) sum += A[index];
        result.push_back(sum);
    }
    return result;
}

/// <summary>
/// Leet code #989. Add to Array-Form of Integer
/// 
/// For a non-negative integer X, the array-form of X is an array of its 
/// digits in left to right order.  For example, if X = 1231, then the 
/// array form is [1,2,3,1].
///
/// Given the array-form A of a non-negative integer X, return the 
/// array-form of the integer X+K.
///
/// Example 1:
/// Input: A = [1,2,0,0], K = 34
/// Output: [1,2,3,4]
/// Explanation: 1200 + 34 = 1234
///
/// Example 2:
/// Input: A = [2,7,4], K = 181
/// Output: [4,5,5]
/// Explanation: 274 + 181 = 455
///
/// Example 3:
/// Input: A = [2,1,5], K = 806
/// Output: [1,0,2,1]
/// Explanation: 215 + 806 = 1021
///
/// Example 4:
/// Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
/// Output: [1,0,0,0,0,0,0,0,0,0,0]
/// Explanation: 9999999999 + 1 = 10000000000
/// 
/// Note：
/// 1. 1 <= A.length <= 10000
/// 2. 0 <= A[i] <= 9
/// 3. 0 <= K <= 10000
/// 4. If A.length > 1, then A[0] != 0
/// </summary>
vector<int> LeetCode::addToArrayForm(vector<int>& A, int K)
{
    vector<int> result;
    std::reverse(A.begin(), A.end());

    int sum = K;
    for (size_t i = 0; i < A.size(); i++)
    {
        sum += A[i];
        result.push_back(sum % 10);
        sum /= 10;
    }

    while (sum > 0)
    {
        result.push_back(sum % 10);
        sum /= 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #992. Subarrays with K Different Integers
/// 
/// Given an array A of positive integers, call a (contiguous, not 
/// necessarily distinct) subarray of A good if the number of different 
/// integers in that subarray is exactly K.
/// 
/// (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
///
/// Return the number of good subarrays of A.
///
/// 
/// Example 1:
///
/// Input: A = [1,2,1,2,3], K = 2
/// Output: 7
/// Explanation: Subarrays formed with exactly 2 different integers: 
/// [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
///
/// Example 2:
///
/// Input: A = [1,2,1,3,4], K = 3
/// Output: 3
/// Explanation: Subarrays formed with exactly 3 different integers: 
/// [1,2,1,3], [2,1,3], [1,3,4].
///
///
/// Note:
/// 1. 1 <= A.length <= 20000
/// 2. 1 <= A[i] <= A.length
/// 3. 1 <= K <= A.length
/// </summary>
int LeetCode::subarraysWithKDistinct(vector<int>& A, int K)
{
    unordered_map<size_t, size_t> num_map;
    size_t head = 0, tail = 0, next = 0;
    int result = 0;
    while (head < A.size())
    {
        if (num_map.size() < (size_t)K)
        {
            if (tail == A.size()) break;
            num_map[A[tail]]++;
            tail++;
        }
        if (num_map.size() == K)
        {
            next = max(next, tail);
            while (next < A.size() && num_map.count(A[next]) > 0) next++;
            result += next - tail + 1;

            num_map[A[head]]--;
            if (num_map[A[head]] == 0) num_map.erase(A[head]);
            head++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #995. Minimum Number of K Consecutive Bit Flips
/// 
/// In an array A containing only 0s and 1s, a K-bit flip consists of choosing 
/// a (contiguous) subarray of length K and simultaneously changing every 0 in 
/// the subarray to 1, and every 1 in the subarray to 0.
///
/// Return the minimum number of K-bit flips required so that there is no 0 in 
/// the array.  If it is not possible, return -1.
///
/// Example 1:
///
/// Input: A = [0,1,0], K = 1
/// Output: 2
/// Explanation: Flip A[0], then flip A[2].
///
/// Example 2:
///
/// Input: A = [1,1,0], K = 2
/// Output: -1
/// Explanation: No matter how we flip subarrays of size 2, we can't make the 
/// array become [1,1,1].
///
/// Example 3:
///
/// Input: A = [0,0,0,1,0,1,1,0], K = 3
/// Output: 3
/// Explanation:
/// Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
/// Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
/// Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]
///
///
/// Note:
///
/// 1. 1 <= A.length <= 30000
/// 2. 1 <= K <= A.length
/// </summary>
int LeetCode::minKBitFlips(vector<int>& A, int K)
{
    vector<int> flip_count(A.size());
    int flip = 0;
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        flip ^= (flip_count[i] % 2);
        if ((A[i] ^ flip) == 0)
        {
            flip ^= 1;
            result++;
            if (i + K < A.size()) flip_count[i + K]++;
            if (i + K - 1 >= A.size())
            {
                result = -1;
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1001. Grid Illumination
/// 
/// On a N x N grid of cells, each cell (x, y) with 0 <= x < N and 
/// 0 <= y < N has a lamp.
/// Initially, some number of lamps are on.  lamps[i] tells us the 
/// location of the i-th lamp that is on.  Each lamp that is on 
/// illuminates every square on its x-axis, y-axis, and both diagonals 
/// (similar to a Queen in chess).
/// For the i-th query queries[i] = (x, y), the answer to the query is 1 
/// if the cell (x, y) is illuminated, else 0.
/// After each query (x, y) [in the order given by queries], we turn off 
/// any lamps that are at cell (x, y) or are adjacent 8-directionally 
/// (ie., share a corner or edge with cell (x, y).)
/// Return an array of answers.  Each value answer[i] should be equal 
/// to the answer of the i-th query queries[i].
///
/// Example 1:
/// Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
/// Output: [1,0]
/// Explanation: 
/// Before performing the first query we have both lamps [0,0] and [4,4] 
/// on.
/// The grid representing which cells are lit looks like this, where [0,0] 
/// is the top left corner, and [4,4] is the bottom right corner:
/// 1 1 1 1 1
/// 1 1 0 0 1
/// 1 0 1 0 1
/// 1 0 0 1 1
/// 1 1 1 1 1
/// Then the query at [1, 1] returns 1 because the cell is lit.  After 
/// this query, the lamp at [0, 0] turns off, and the grid now looks 
/// like this:
/// 1 0 0 0 1
/// 0 1 0 0 1
/// 0 0 1 0 1
/// 0 0 0 1 1
/// 1 1 1 1 1
/// Before performing the second query we have only the lamp [4,4] on.  
/// Now the query at [1,0] returns 0, because the cell is no longer lit.
/// 
/// Note:
/// 1. 1 <= N <= 10^9
/// 2. 0 <= lamps.length <= 20000
/// 3. 0 <= queries.length <= 20000
/// 4. lamps[i].length == queries[i].length == 2
/// </summary>
vector<int> LeetCode::gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries)
{
    unordered_map<int, int> row_map, col_map, diag_map, a_diag_map;
    unordered_map<int, unordered_set<int>> lamp_map;
    vector<int> result;
    for (size_t i = 0; i < lamps.size(); i++)
    {
        row_map[lamps[i][0]]++;
        col_map[lamps[i][1]]++;
        diag_map[lamps[i][0] + lamps[i][1]]++;
        a_diag_map[lamps[i][0] - lamps[i][1]]++;
        lamp_map[lamps[i][0]].insert(lamps[i][1]);
    }

    for (size_t i = 0; i < queries.size(); i++)
    {
        if (row_map[queries[i][0]] > 0 || col_map[queries[i][1]] > 0 ||
            diag_map[queries[i][0] + queries[i][1]] > 0 || 
            a_diag_map[queries[i][0] - queries[i][1]] > 0)
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }

        for (int row = queries[i][0] - 1; row < queries[i][0] + 2; row++)
        {
            if (row < 0 || row >= N) continue;
            for (int col = queries[i][1] - 1; col < queries[i][1] + 2; col++)
            {
                if (col < 0 || col >= N) continue;
                if (lamp_map[row].count(col) == 0) continue;
                lamp_map[row].erase(col);
                row_map[row]--;
                col_map[col]--;
                diag_map[row + col]--;
                a_diag_map[row - col]--;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #999. Available Captures for Rook
/// 
/// On an 8 x 8 chessboard, there is one white rook.  There also may be 
/// empty squares, white bishops, and black pawns.  These are given as 
/// characters 'R', '.', 'B', and 'p' respectively. Uppercase characters 
/// represent white pieces, and lowercase characters represent black 
/// pieces.
///
/// The rook moves as in the rules of Chess: it chooses one of four 
/// cardinal directions (north, east, west, and south), then moves in that 
/// direction until it chooses to stop, reaches the edge of the board, or 
/// captures an opposite colored pawn by moving to the same square it 
/// occupies.  Also, rooks cannot move into the same square as other 
/// friendly bishops.
/// 
/// Return the number of pawns the rook can capture in one move.
/// 
/// Example 1:
///
/// Input: [
/// [".",".",".",".",".",".",".","."],
/// [".",".",".","p",".",".",".","."],
/// [".",".",".","R",".",".",".","p"],
/// [".",".",".",".",".",".",".","."],
/// [".",".",".",".",".",".",".","."],
/// [".",".",".","p",".",".",".","."],
/// [".",".",".",".",".",".",".","."],
/// [".",".",".",".",".",".",".","."]]
/// Output: 3
/// Explanation: 
/// In this example the rook is able to capture all the pawns.
///
/// Example 2:
/// 
/// Input: [
/// [".",".",".",".",".",".",".","."],
/// [".","p","p","p","p","p",".","."],
/// [".","p","p","B","p","p",".","."],
/// [".","p","B","R","B","p",".","."],
/// [".","p","p","B","p","p",".","."],
/// [".","p","p","p","p","p",".","."],
/// [".",".",".",".",".",".",".","."],
/// [".",".",".",".",".",".",".","."]]
/// Output: 0
/// Explanation: 
/// Bishops are blocking the rook to capture any pawn.
///
/// Example 3:
/// Input:[
/// [".",".",".",".",".",".",".","."],
/// [".",".",".","p",".",".",".","."],
/// [".",".",".","p",".",".",".","."],
/// ["p","p",".","R",".","p","B","."],
/// [".",".",".",".",".",".",".","."],
/// [".",".",".","B",".",".",".","."],
/// [".",".",".","p",".",".",".","."],
/// [".",".",".",".",".",".",".","."]]
/// Output: 3
/// Explanation: 
/// The rook can capture the pawns at positions b5, d6 and f5.
///
/// Note:
///  
/// board.length == board[i].length == 8
/// board[i][j] is either 'R', '.', 'B', or 'p'
/// There is exactly one cell with board[i][j] == 'R'
/// </summary>
int LeetCode::numRookCaptures(vector<vector<char>>& board)
{
    int result = 0;
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
                for (size_t d = 0; d < directions.size(); d++)
                {
                    int r = i;
                    int c = j;
                    while (r >= 0 && r < (int)board.size() && c >= 0 && c < (int)board[i].size())
                    {
                        if (board[r][c] == '.' || board[r][c] == 'R')
                        {
                            r += directions[d][0];
                            c += directions[d][1];
                        }
                        else 
                        {
                            if (board[r][c] == 'p') result++;
                            break;
                        }
                    }
                }
                return result;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #997. Find the Town Judge
/// 
/// In a town, there are N people labelled from 1 to N.  There is a rumor 
/// that one of these people is secretly the town judge.
///
/// If the town judge exists, then:
///
/// The town judge trusts nobody.
/// Everybody (except for the town judge) trusts the town judge.
/// There is exactly one person that satisfies properties 1 and 2.
/// You are given trust, an array of pairs trust[i] = [a, b] representing 
/// that the person labelled a trusts the person labelled b.
///
/// If the town judge exists and can be identified, return the label of the 
/// town judge.  Otherwise, return -1.
/// 
/// Example 1:
///
/// Input: N = 2, trust = [[1,2]]
/// Output: 2
///
/// Example 2:
/// 
/// Input: N = 3, trust = [[1,3],[2,3]]
/// Output: 3
///
/// Example 3:
/// 
/// Input: N = 3, trust = [[1,3],[2,3],[3,1]]
/// Output: -1
///
/// Example 4:
/// 
/// Input: N = 3, trust = [[1,2],[2,3]]
/// Output: -1
///
/// Example 5:
///
/// Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
/// Output: 3
///
/// Note:
/// 
/// 1. 1 <= N <= 1000
/// 2. trust.length <= 10000
/// 3. trust[i] are all different
/// 4. trust[i][0] != trust[i][1]
/// 5. 1 <= trust[i][0], trust[i][1] <= N
/// </summary>
int LeetCode::findJudge(int N, vector<vector<int>>& trust)
{
    vector<int> result(N);
    for (size_t i = 0; i < trust.size(); i++)
    {
        if (trust[i][0] != trust[i][1])
        {
            result[trust[i][0] - 1]--;
            result[trust[i][1] - 1]++;
        }
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] == N - 1) return i + 1;
    }
    return -1;
}

/// <summary>
/// Leet code #1004. Max Consecutive Ones III
/// 
/// Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
///
/// Return the length of the longest (contiguous) subarray that contains 
/// only 1s. 
///
/// Example 1:
/// Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
/// Output: 6
/// Explanation: 
/// [1,1,1,0,0,1,1,1,1,1,1]
/// Bolded numbers were flipped from 0 to 1.  The longest subarray is 
/// underlined.
///
/// Example 2:
/// Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
/// Output: 10
/// Explanation: 
/// [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
/// Bolded numbers were flipped from 0 to 1.  The longest subarray is 
/// underlined.
/// 
/// Note:
///
/// 1. 1 <= A.length <= 20000
/// 2. 0 <= K <= A.length
/// 3. A[i] is 0 or 1 
/// </summary>
int LeetCode::longestOnes(vector<int>& A, int K)
{
    int result = 0;
    int first = -1;
    deque<int> zeros;
    for (int i = 0; i < (int)A.size(); i++)
    {
        if (A[i] == 1 || (int)zeros.size() < K)
        {
            result = max(result, i - first);
        }
        if (A[i] == 0)
        {
            zeros.push_back(i);
            if ((int)zeros.size() > K)
            {
                first = zeros.front();
                zeros.pop_front();
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1005. Maximize Sum Of Array After K Negations
/// 
/// Given an array A of integers, we must modify the array in the 
/// following way: we choose an i and replace A[i] with -A[i], and we 
/// repeat this process K times in total.  (We may choose the same index 
/// i multiple times.)
/// 
/// Return the largest possible sum of the array after modifying it in 
/// this way.
///
/// Example 1:
///
/// Input: A = [4,2,3], K = 1
/// Output: 5
/// Explanation: Choose indices (1,) and A becomes [4,-2,3].
///
/// Example 2:
///
/// Input: A = [3,-1,0,2], K = 3
/// Output: 6
/// Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
///
/// Example 3:
///
/// Input: A = [2,-3,-1,5,-4], K = 2
/// Output: 13
/// Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
///
///
/// Note:
/// 1. 1 <= A.length <= 10000
/// 2. 1 <= K <= 10000
/// 3. -100 <= A[i] <= 100
/// </summary>
int LeetCode::largestSumAfterKNegations(vector<int>& A, int K)
{
    multiset<int> negative;
    int sum = 0;
    int smallest_positive = INT_MAX;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] < 0) negative.insert(A[i]);
        else
        {
            smallest_positive = min(smallest_positive, A[i]);
        }
        sum += A[i];
    }
    while (K > 0)
    {
        if (negative.empty()) break;
        int x = 0 - *negative.begin();
        smallest_positive = min(x, smallest_positive);
        negative.erase(negative.begin());
        sum += 2 * x;
        K--;
    }
    if (K % 2 == 1)
    {
        sum -= 2 * smallest_positive;
    }
    return sum;
}

/// <summary>
/// Leet code #1007. Minimum Domino Rotations For Equal Row
/// 
/// In a row of dominoes, A[i] and B[i] represent the top and bottom 
/// halves of the i-th domino.  (A domino is a tile with two numbers 
/// from 1 to 6 - one on each half of the tile.)
///
/// We may rotate the i-th domino, so that A[i] and B[i] swap values.
/// 
/// Return the minimum number of rotations so that all the values in A 
/// are the same, or all the values in B are the same.
///
/// If it cannot be done, return -1.
/// 
/// Example 1:
/// Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
/// Output: 2
/// Explanation: 
/// The first figure represents the dominoes as given by A and B: before 
/// we do any rotations.
/// If we rotate the second and fourth dominoes, we can make every 
/// value in the top row equal to 2, as indicated by the second figure.
///
/// Example 2:
///
/// Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
/// Output: -1
/// Explanation: 
/// In this case, it is not possible to rotate the dominoes to make one 
/// row of values equal.
/// 
///
/// Note:
///
/// 1. 1 <= A[i], B[i] <= 6
/// 2. 2 <= A.length == B.length <= 20000
/// 
/// </summary>
int LeetCode::minDominoRotations(vector<int>& A, vector<int>& B)
{
    vector<int> domino(7);

    for (size_t i = 0; i < A.size(); i++)
    {
        domino[A[i]]++;
        if (A[i] != B[i]) domino[B[i]]++;
    }
    int value = -1;
    for (int i = 1; i < 7; i++)
    {
        if (domino[i] == A.size())
        {
            value = i;
            break;
        }
    }
    if (value == -1) return -1;
    int a = 0;
    int b = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == value) a++;
        if (B[i] == value) b++;
    }
    int result = min(a, (int)A.size() - a);
    result = min(result, b);
    result = min(result, (int)B.size() - b);
    return result;
}

/// <summary>
/// Leet code #1013. Partition Array Into Three Parts With Equal Sum
/// 
/// Given an array A of integers, return true if and only if we can 
/// partition the array into three non-empty parts with equal sums.
///
/// Formally, we can partition the array if we can find indexes i+1 < j with 
/// (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + 
/// A[j-1] + ... + A[A.length - 1])
///
///
/// Example 1:
///
/// Input: [0,2,1,-6,6,-7,9,1,2,0,1]
/// Output: true
/// Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
/// Example 2:
///
/// Input: [0,2,1,-6,6,7,9,-1,2,0,1]
/// Output: false
/// Example 3:
///
/// Input: [3,3,6,5,-2,2,5,1,-9,4]
/// Output: true
/// Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
/// 
/// Note:
///
/// 1. 3 <= A.length <= 50000
/// 2. -10000 <= A[i] <= 10000
/// </summary>
bool LeetCode::canThreePartsEqualSum(vector<int>& A)
{
    int sum = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        sum += A[i];
    }
    if (sum % 3 != 0) return false;

    int first = sum / 3;
    sum = 0;
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if ((sum == first) && (result == 0))
        {
            result++;
        }
        else if ((sum == first * 2) && (result == 1))
        {
            result++;
        }
        else if ((sum == first * 3) && (result == 2))
        {
            result++;
        }
    }
    if (result == 3) return true;
    else return false;
}

/// <summary>
/// Leet code #1014. Best Sightseeing Pair
/// 
/// Given an array A of positive integers, A[i] represents the value of the 
/// i-th sightseeing spot, and two sightseeing spots i and j have distance 
/// j - i between them.
///
/// The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) 
/// : the sum of the values of the sightseeing spots, minus the distance 
/// between them.
///
/// Return the maximum score of a pair of sightseeing spots.
///
/// 
///
/// Example 1:
///
/// Input: [8,1,5,2,6]
/// Output: 11
/// Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
///
/// 
/// Note:
/// 
/// 1. 2 <= A.length <= 50000
/// 2. 1 <= A[i] <= 1000
/// </summary>
int LeetCode::maxScoreSightseeingPair(vector<int>& A)
{
    int result = 0;
    vector<pair<int, int>> spots;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (spots.empty())
        {
            spots.push_back(make_pair(A[i], i));
        }
        else if (spots.size() == 1)
        {
            spots.push_back(make_pair(A[i], i));
            int sight_score = spots[0].first + spots[1].first + spots[0].second - spots[1].second;
            result = max(result, sight_score);
            if (spots[1].second - spots[0].second < spots[0].first - spots[1].first)
            {
                spots.pop_back();
            }
            else
            {
                spots[0] = spots[1];
                spots.pop_back();
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1036. Escape a Large Maze
/// 
/// In a 1 million by 1 million grid, the coordinates of each grid square are 
/// (x, y) with 0 <= x, y < 10^6.
///
/// We start at the source square and want to reach the target square.  
/// Each move, we can walk to a 4-directionally adjacent square in the grid 
/// that isn't in the given list of blocked squares.
///
/// Return true if and only if it is possible to reach the target square 
/// through a sequence of moves.
///
/// Example 1:
///
/// Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
/// Output: false
/// Explanation: 
/// The target square is inaccessible starting from the source square, because
/// we can't walk outside the grid.
///
/// Example 2:
///
/// Input: blocked = [], source = [0,0], target = [999999,999999]
/// Output: true
/// Explanation: 
/// Because there are no blocked cells, it's possible to reach the target square.
/// 
/// Note:
/// 1. 0 <= blocked.length <= 200
/// 2. blocked[i].length == 2
/// 3. 0 <= blocked[i][j] < 10^6
/// 4. source.length == target.length == 2
/// 5. 0 <= source[i][j], target[i][j] < 10^6
/// 6. source != target
/// </summary>
bool LeetCode::isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)
{
    unordered_map<int, int> row_map, col_map;
    vector<int> row, col;
    for (size_t i = 0; i < blocked.size(); i++)
    {
        row.push_back(blocked[i][0]);
        col.push_back(blocked[i][1]);
    }
    row.push_back(source[0]);
    col.push_back(source[1]);
    row.push_back(target[0]);
    col.push_back(target[1]);
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    int row_id = 0;
    int col_id = 0;
    for (size_t i = 0; i < row.size(); i++)
    {
        if (i == 0)
        {
            if (row[0] > 0) row_id++;
            if (col[0] > 0) col_id++;
        }
        else 
        {
            if (row[i] == row[i - 1] + 1)
            {
                row_id++;
            }
            else if (row[i] > row[i - 1] + 1)
            {
                row_id += 2;
            }
            if (col[i] == col[i - 1] + 1)
            {
                col_id++;
            }
            else if (col[i] > col[i - 1] + 1)
            {
                col_id += 2;
            }
        }
        row_map[row[i]] = row_id;
        col_map[col[i]] = col_id;
    }
    if (row[row.size()-1] < 999999) row_id++;
    if (col[col.size() - 1] < 999999) col_id++;
    vector<vector<int>> grid(row_id + 1, vector<int>(col_id + 1));
    for (size_t i = 0; i < blocked.size(); i++)
    {
        grid[row_map[blocked[i][0]]][col_map[blocked[i][1]]] = 1;
    }
    int x = row_map[source[0]];
    int y = col_map[source[1]];
    grid[row_map[target[0]]][col_map[target[1]]] = 2;
 
    vector<vector<int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    queue<vector<int>> search;
    search.push({ x, y });
    grid[x][y] = 1;
    while (!search.empty())
    {
        vector<int> pos = search.front();
        if (grid[pos[0]][pos[1]] == 2) return true;
        search.pop();
        for (int d = 0; d < 4; d++)
        {
            vector<int> next_pos = pos;
            next_pos[0] += directions[d][0];
            next_pos[1] += directions[d][1];
            if (next_pos[0] < 0 || next_pos[0] > row_id || next_pos[1] < 0 || next_pos[1] > col_id)
            {
                continue;
            }
            if (grid[next_pos[0]][next_pos[1]] == 1)
            {
                continue;
            }
            if (grid[next_pos[0]][next_pos[1]] == 0) grid[next_pos[0]][next_pos[1]] = 1;
            search.push(next_pos);
        }
    }
    return false;
}

/// <summary>
/// Leet code #1052. Grumpy Bookstore Owner
/// 
/// Today, the bookstore owner has a store open for customers.length minutes.  
/// Every minute, some number of customers (customers[i]) enter the store, 
/// and all those customers leave after the end of that minute.
///
/// On some minutes, the bookstore owner is grumpy.  If the bookstore owner 
/// is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  
/// When the bookstore owner is grumpy, the customers of that minute are not 
/// satisfied, otherwise they are satisfied.
///
/// The bookstore owner knows a secret technique to keep themselves not grumpy 
/// for X minutes straight, but can only use it once.
///
/// Return the maximum number of customers that can be satisfied throughout 
/// the day.
/// 
/// Example 1:
///
/// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
/// Output: 16
/// Explanation: The bookstore owner keeps themselves not grumpy for the last 
/// 3 minutes. 
/// The maximum number of customers that can be 
/// satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
/// 
/// Note:
///
/// 1. 1 <= X <= customers.length == grumpy.length <= 20000
/// 2. 0 <= customers[i] <= 1000
/// 3. 0 <= grumpy[i] <= 1
/// </summary>
int LeetCode::maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
{
    int result = 0, grumpy_sum = 0, grumpy_max = 0;

    for (size_t i = 0; i < customers.size(); i++)
    {
        if (grumpy[i] == 0) result += customers[i];
        else
        {
            grumpy_sum += customers[i];
        }
        if (i >= (size_t)X)
        {
            if (grumpy[i - X] == 1)
            {
                grumpy_sum -= customers[i - X];
            }
        }
        grumpy_max = max(grumpy_max, grumpy_sum);
    }
    result += grumpy_max;
    return result;
}

/// <summary>
/// Leet code #1074. Number of Submatrices That Sum to Target
/// 
/// Given a matrix, and a target, return the number of non-empty submatrices 
/// that sum to target.
///
/// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with 
/// x1 <= x <= x2 and y1 <= y <= y2.
///
/// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different 
/// if they have some coordinate that is different: for example, if x1 != x1'.
///
/// Example 1:
///
/// Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
/// Output: 4
/// Explanation: The four 1x1 submatrices that only contain 0.
///
/// Example 2:
///
/// Input: matrix = [[1,-1],[-1,1]], target = 0
/// Output: 5
/// Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus 
/// the 2x2 submatrix.
/// 
///
/// Note:
///
/// 1. 1 <= matrix.length <= 300
/// 2. 1 <= matrix[0].length <= 300
/// 3. -1000 <= matrix[i] <= 1000
/// 4. -10^8 <= target <= 10^8
/// </summary>
int LeetCode::numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
{
    int result = 0;
    vector<vector<int>> sum(matrix.size(), vector<int>(matrix[0].size()));

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (j == 0) sum[i][j] = matrix[i][j];
            else sum[i][j] = sum[i][j - 1] + matrix[i][j];
        }
    }

    for (size_t c1 = 0; c1 < matrix[0].size(); c1++)
    {
        for (size_t c2 = c1; c2 < matrix[0].size(); c2++)
        {
            unordered_map<int, int> num_map;
            int sum_num = 0;
            num_map[sum_num]++;
            for (size_t r = 0; r < matrix.size(); r++)
            {
                int num = 0;
                if (c1 == 0) num = sum[r][c2];
                else num = sum[r][c2] - sum[r][c1 - 1];
                sum_num += num;
                if (num_map.count(sum_num - target) > 0)
                {
                    result += num_map[sum_num - target];
                }
                num_map[sum_num]++;
            }
        }
    }
    return result;
}


/// <summary>
/// Leet code #1063. Number of Valid Subarrays
/// 
/// Given an array A of integers, return the number of non-empty continuous 
/// subarrays that satisfy the following condition:
///
/// The leftmost element of the subarray is not larger than other elements 
/// in the subarray.
///
/// Example 1:
///
/// Input: [1,4,2,5,3]
/// Output: 11
/// Explanation: There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],
/// [2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].
///
/// Example 2:
///
/// Input: [3,2,1]
/// Output: 3
/// Explanation: The 3 valid subarrays are: [3],[2],[1].
///
/// Example 3:
///
/// Input: [2,2,2]
/// Output: 6
/// Explanation: There are 6 valid subarrays: [2],[2],[2],[2,2],[2,2],[2,2,2].
/// 
///
/// Note:
///
/// 1. 1 <= A.length <= 50000
/// 2. 0 <= A[i] <= 100000
/// </summary>
int LeetCode::validSubarrays(vector<int>& nums)
{
    int result = 0;
    stack<int> dp;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (dp.empty())
        {
            dp.push(nums[i]);
        }
        else
        {
            while (!dp.empty())
            {
                if (dp.top() > nums[i])
                {
                    dp.pop();
                }
                else
                {
                    break;
                }
            }
            dp.push(nums[i]);
        }
        result += dp.size();
    }
    return result;
}

/// <summary>
/// Leet code #1089. Duplicate Zeros
/// 
/// Given a fixed length array arr of integers, duplicate each occurrence 
/// of zero, shifting the remaining elements to the right.
///
/// Note that elements beyond the length of the original array are not 
/// written.
///
/// Do the above modifications to the input array in place, do not return 
/// anything from your function.
///  
/// Example 1:
/// Input: [1,0,2,3,0,4,5,0]
/// Output: null
/// Explanation: After calling your function, the input array is modified 
/// to: [1,0,0,2,3,0,0,4]
///
/// Example 2:
///
/// Input: [1,2,3]
/// Output: null
/// Explanation: After calling your function, the input array is modified 
/// to: [1,2,3]
///
/// Note:
/// 1. 1 <= arr.length <= 10000
/// 2. 0 <= arr[i] <= 9
/// </summary>
void LeetCode::duplicateZeros(vector<int>& arr)
{
    int count = 0;
    int index = 0;
    while (index + count < (int)arr.size())
    {
        if (arr[index] == 0) count++;
        index++;
    }
    index--;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        arr[i] = arr[index];
        if (arr[index] == 0)
        {
            if (index + count < (int)arr.size())
            {
                i--;
                arr[i] = 0;
            }
            count--;
        }
        index--;
    }
}

/// <summary>
/// Leet code #1124. Longest Well-Performing Interval
/// 
/// We are given hours, a list of the number of hours worked per day for a 
/// given employee.
/// A day is considered to be a tiring day if and only if the number of hours 
/// worked is (strictly) greater than 8.
/// A well-performing interval is an interval of days for which the number of 
/// tiring days is strictly larger than the number of non-tiring days.
/// Return the length of the longest well-performing interval.
/// 
/// Example 1:
/// Input: hours = [9,9,6,0,6,6,9]
/// Output: 3
/// Explanation: The longest well-performing interval is [9,9,6].
/// 
/// Constraints:
/// 1. 1 <= hours.length <= 10000
/// 2. 0 <= hours[i] <= 16
/// </summary>
int LeetCode::longestWPI(vector<int>& hours)
{
    int n = hours.size();
    vector<int> dp(n, -1);
    int sum = 0;
    int result = 0;
    for (int i = 0; i < (int)hours.size(); i++)
    {
        if (hours[i] <= 8)
        {
            sum--;
        }
        else
        {
            sum++;
        }

        if (sum > 0) result = i + 1;
        else if (sum == -n) continue;
        else
        {
            // for zero we do not need to store the position
            if (sum < 0) if (dp[sum + n] == -1) dp[sum + n] = i;
            if (dp[sum + n - 1] != -1)
            {
                result = max(result, i - dp[sum + n - 1]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1121. Divide Array Into Increasing Sequences
/// 
/// Given a non-decreasing array of positive integers nums and an integer K, 
/// find out if this array can be divided into one or more disjoint 
/// increasing subsequences of length at least K.
/// 
/// Example 1:
/// Input: nums = [1,2,2,3,3,4,4], K = 3
/// Output: true
/// Explanation: 
/// The array can be divided into the two subsequences [1,2,3,4] and [2,3,4] 
/// with lengths at least 3 each.
///
/// Example 2:
/// Input: nums = [5,6,6,7,8], K = 3
/// Output: false
/// Explanation: 
/// There is no way to divide the array using the conditions required.
/// 
/// Note:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= K <= nums.length
/// 3. 1 <= nums[i] <= 10^5
/// </summary>
bool LeetCode::canDivideIntoSubsequences(vector<int>& nums, int K)
{
    int max_dup = 0;
    int first = 0;
    for (int i = 0; i <= (int)nums.size(); i++)
    {
        if (i == nums.size())
        {
            max_dup = max(max_dup, i - first);
        }
        else if (i > 0 && nums[i] != nums[i - 1])
        {
            max_dup = max(max_dup, i - first);
            first = i;
        }
    }
    if ((int)nums.size() / max_dup >= K)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #1138. Alphabet Board Path
/// 
/// On an alphabet board, we start at position (0, 0), corresponding to 
/// character board[0][0].
///
/// Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], 
/// as shown in the diagram below.
///
/// We may make the following moves:
///
/// 'U' moves our position up one row, if the position exists on the 
/// board;
/// 'D' moves our position down one row, if the position exists on the 
/// board;
/// 'L' moves our position left one column, if the position exists on the 
/// board;
/// 'R' moves our position right one column, if the position exists on the 
/// board;
/// '!' adds the character board[r][c] at our current position (r, c) to the 
/// answer.
/// (Here, the only positions that exist on the board are positions with 
///  letters on them.)
///
/// Return a sequence of moves that makes our answer equal to target in the 
/// minimum number of moves.  You may return any path that does so.
///
/// Example 1:
/// Input: target = "leet"
/// Output: "DDR!UURRR!!DDD!"
///
/// Example 2:
/// Input: target = "code"
/// Output: "RR!DDRR!UUL!R!"
///  
/// Constraints:
/// 1. 1 <= target.length <= 100
/// 2. target consists only of English lowercase letters.
/// </summary>
string LeetCode::alphabetBoardPath(string target)
{
    string result;
    char curr = 'a';
    for (size_t i = 0; i < target.size(); i++)
    {
        char next = target[i];
        int row_curr = (curr - 'a') / 5;
        int col_curr = (curr - 'a') % 5;

        int row_next = (next - 'a') / 5;
        int col_next = (next - 'a') % 5;

        if (next == 'z')
        {
            if (col_curr > col_next) result.append(string(col_curr - col_next, 'L'));
            if (row_next > row_curr) result.append(string(row_next - row_curr, 'D'));
        }
        else if (curr == 'z')
        {
            if (row_curr > row_next) result.append(string(row_curr - row_next, 'U'));
            if (col_next - col_curr) result.append(string(col_next - col_curr, 'R'));
        }
        else
        {
            if (row_next > row_curr)
            {
                result.append(string(row_next - row_curr, 'D'));
            }
            else if (row_next < row_curr)
            {
                result.append(string(row_curr - row_next, 'U'));
            }
            if (col_next > col_curr)
            {
                result.append(string(col_next - col_curr, 'R'));
            }
            else if (col_next < col_curr)
            {
                result.append(string(col_curr - col_next, 'L'));
            }
        }
        result.push_back('!');
        curr = next;
    }
    return result;
}

/// <summary>
/// Leet code #1151. Minimum Swaps to Group All 1's Together
/// 
/// Given a binary array data, return the minimum number of swaps required 
/// to group all 1’s present in the array together in any place in the array.
/// 
/// Example 1:
/// Input: [1,0,1,0,1]
/// Output: 1
/// Explanation: 
/// There are 3 ways to group all 1's together:
/// [1,1,1,0,0] using 1 swap.
/// [0,1,1,1,0] using 2 swaps.
/// [0,0,1,1,1] using 1 swap.
/// The minimum is 1.
///
/// Example 2:
/// Input: [0,0,0,1,0]
/// Output: 0
/// Explanation: 
/// Since there is only one 1 in the array, no swaps needed.
///
/// Example 3:
/// Input: [1,0,1,0,1,0,0,1,1,0,1]
/// Output: 3
/// Explanation: 
/// One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
/// 
/// Note:
/// 1. 1 <= data.length <= 10^5
/// 2. 0 <= data[i] <= 1
/// </summary>
int LeetCode::minSwaps(vector<int>& data)
{
    vector<int> sum(data.size());
    for (size_t i = 0; i < data.size(); i++)
    {
        if (i == 0) sum[0] = data[0];
        else (sum[i] = sum[i - 1] + data[i]);
    }
    int length = sum[sum.size() - 1];
    int result = 0;
    for (size_t i = length - 1; i < sum.size(); i++)
    {
        int count = 0;
        if (i == length - 1) count = sum[i];
        else count = sum[i] - sum[i - length];
        result = max(result, count);
    }
    return length - result;
}

/// <summary>
/// Leet code #1176. Diet Plan Performance
/// 
/// A dieter consumes calories[i] calories on the i-th day.  For every 
/// consecutive sequence of k days, they look at T, the total calories 
/// consumed during that sequence of k days:
/// If T < lower, they performed poorly on their diet and lose 1 point; 
/// If T > upper, they performed well on their diet and gain 1 point;
/// Otherwise, they performed normally and there is no change in points.
/// Return the total number of points the dieter has after all 
/// calories.length days.
///
/// Note that: The total points could be negative.
/// 
/// Example 1:
/// Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
/// Output: 0
/// Explaination: calories[0], calories[1] < lower and 
/// calories[3], calories[4] > upper, total points = 0.
///
/// Example 2:
/// Input: calories = [3,2], k = 2, lower = 0, upper = 1
/// Output: 1
/// Explaination: calories[0] + calories[1] > upper, total points = 1.
///
/// Example 3:
/// Input: calories = [6,5,0,0], k = 2, lower = 1, upper = 5
/// Output: 0
/// Explaination: calories[0] + calories[1] > upper, 
/// calories[2] + calories[3] < lower, total points = 0.
/// 
/// Constraints:
/// 1. 1 <= k <= calories.length <= 10^5
/// 2. 0 <= calories[i] <= 20000
/// 3. 0 <= lower <= upper
/// </summary>
int LeetCode::dietPlanPerformance(vector<int>& calories, int k, int lower, int upper)
{
    vector<int> sum(calories.size());
    for (size_t i = 0; i < calories.size(); i++)
    {
        sum[i] = calories[i];
        if (i > 0) sum[i] += sum[i - 1];
    }
    int result = 0;
    for (int i = k - 1; i < (int)sum.size(); i++)
    {
        int s = sum[i];
        if (i > k - 1)
        {
            s -= sum[i - k];
        }
        if (s > upper) result++;
        else if (s < lower) result--;
    }
    return result;
}

/// <summary>
/// Leet code #1177. Can Make Palindrome from Substring
/// 
/// Given a string s, we make queries on substrings of s.
/// For each query queries[i] = [left, right, k], we may rearrange the 
/// substring s[left], ..., s[right], and then choose up to k of them to 
/// replace with any lowercase English letter. 
/// If the substring is possible to be a palindrome string after the 
/// operations above, the result of the query is true. Otherwise, the result 
/// is false.
/// Return an array answer[], where answer[i] is the result of the i-th query 
/// queries[i].
/// Note that: Each letter is counted individually for replacement so if for 
/// example s[left..right] = "aaa", and k = 2, we can only replace two of the 
/// letters.  (Also, note that the initial string s is never modified by 
/// any query.)
/// 
/// Example :
/// Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
/// Output: [true,false,false,true,true]
/// Explanation:
/// queries[0] : substring = "d", is palidrome.
/// queries[1] : substring = "bc", is not palidrome.
/// queries[2] : substring = "abcd", is not palidrome after replacing only 1 
///              character.
/// queries[3] : substring = "abcd", could be changed to "abba" which is 
///              palidrome. Also this can be changed to "baab" first rearrange 
///              it "bacd" then replace "cd" with "ab".
/// queries[4] : substring = "abcda", could be changed to "abcba" which is palidrome.
/// 
/// Constraints:
/// 1. 1 <= s.length, queries.length <= 10^5
/// 2. 0 <= queries[i][0] <= queries[i][1] < s.length
/// 3. 0 <= queries[i][2] <= s.length
/// 4. s only contains lowercase English letters.
/// </summary>
vector<bool> LeetCode::canMakePaliQueries(string s, vector<vector<int>>& queries)
{
    vector<int> dp(s.size());

    for (size_t i = 0; i < s.size(); i++)
    {
        dp[i] = 1 << (s[i] - 'a');
        if (i > 0) dp[i] = dp[i] ^ dp[i - 1];
    }
    vector<bool> result;

    for (size_t i = 0; i < queries.size(); i++)
    {
        int bit_mask = dp[queries[i][1]];
        if (queries[i][0] > 0)
        {
            bit_mask ^= dp[queries[i][0] - 1];
        }
        int count = 0;
        for (size_t j = 0; j < 32; j++)
        {
            int bit = 1 << j;
            if ((bit_mask & bit) != 0) count++;
        }
        if ((count / 2) <= queries[i][2]) result.push_back(true);
        else result.push_back(false);
    }
    return result;
}

/// <summary>
/// Leet code #1183. Maximum Number of Ones
/// 
/// Consider a matrix M with dimensions width * height, such that every cell
/// has value 0 or 1, and any square sub-matrix of M of size 
/// sideLength * sideLength has at most maxOnes ones.
/// Return the maximum possible number of ones that the matrix M can have.
/// 
/// Example 1:
/// Input: width = 3, height = 3, sideLength = 2, maxOnes = 1
/// Output: 4
/// Explanation:
/// In a 3*3 matrix, no 2*2 sub-matrix can have more than 1 one.
/// The best solution that has 4 ones is:
/// [1,0,1]
/// [0,0,0]
/// [1,0,1]
///
/// Example 2:
/// Input: width = 3, height = 3, sideLength = 2, maxOnes = 2
/// Output: 6
/// Explanation:
/// [1,0,1]
/// [1,0,1]
/// [1,0,1]
/// 
/// Constraints:
/// 1. 1 <= width, height <= 100
/// 2. 1 <= sideLength <= width, height
/// 3. 0 <= maxOnes <= sideLength * sideLength
/// </summary>
int LeetCode::maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes)
{
    priority_queue<int> heap;
    for (int i = 0; i < sideLength; i++)
    {
        for (int j = 0; j < sideLength; j++)
        {
            int count = ((width + sideLength - 1 - j) / sideLength) *
                ((height + sideLength - 1 - i) / sideLength);
            heap.push(count);
        }
    }

    int result = 0;
    for (int i = 0; i < maxOnes; i++)
    {
        result += heap.top();
        heap.pop();
    }
    return result;
 }

/// <summary>
/// Leet code #1184. Distance Between Bus Stops
/// 
/// A bus has n stops numbered from 0 to n - 1 that form a circle. We know 
/// the distance between all pairs of neighboring stops where distance[i] 
/// is the distance between the stops number i and (i + 1) % n.
/// The bus goes along both directions i.e. clockwise and counterclockwise.
/// Return the shortest distance between the given start and destination 
/// stops.
/// 
/// Example 1:
///
/// Input: distance = [1,2,3,4], start = 0, destination = 1
/// Output: 1
/// Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
/// 
/// Example 2:
///
/// Input: distance = [1,2,3,4], start = 0, destination = 2
/// Output: 3
/// Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
///  
/// Example 3:
///
/// Input: distance = [1,2,3,4], start = 0, destination = 3
/// Output: 4
/// Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
/// 
/// Constraints:
/// 1. 1 <= n <= 10^4
/// 2. distance.length == n
/// 3. 0 <= start, destination < n
/// 4. 0 <= distance[i] <= 10^4
/// </summary>
int LeetCode::distanceBetweenBusStops(vector<int>& distance, int start, int destination)
{
    int distance1 = 0;
    for (int i = start; ; i++)
    {
        if (i == distance.size()) i = 0;
        if (i == destination) break;
        distance1 += distance[i];
    }

    int distance2 = 0;
    for (int i = destination; ; i++)
    {
        if (i == distance.size()) i = 0;
        if (i == start) break;
        distance2 += distance[i];
    }
    return min(distance1, distance2);
}

/// <summary>
/// Leet code #1186. Maximum Subarray Sum with One Deletion
/// 
/// Given an array of integers, return the maximum sum for a non-empty 
/// subarray (contiguous elements) with at most one element deletion. 
/// In other words, you want to choose a subarray and optionally delete 
/// one element from it so that there is still at least one element left 
/// and the sum of the remaining elements is maximum possible.
/// Note that the subarray needs to be non-empty after deleting one element.
/// 
/// Example 1:
/// Input: arr = [1,-2,0,3]
/// Output: 4
/// Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the 
/// subarray [1, 0, 3] becomes the maximum value.
///
/// Example 2:
/// Input: arr = [1,-2,-2,3]
/// Output: 3
/// Explanation: We just choose [3] and it's the maximum sum.
///
/// Example 3:
/// Input: arr = [-1,-1,-1,-1]
/// Output: -1
/// Explanation: The final subarray needs to be non-empty. You can't 
/// choose [-1] and delete -1 from it, then get an empty subarray to make 
/// the sum equals to 0.
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. -10^4 <= arr[i] <= 10^4
/// </summary>
int LeetCode::maximumSum(vector<int>& arr)
{
    int last_sum_del = 0;
    int last_sum = 0;
    int last_item_del = 0;
    int next_item_del = 0;
    int sum = 0;
    int result = INT_MIN;
    for (size_t i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        result = max(result, sum - last_sum - next_item_del);
        result = max(result, sum - last_sum_del);
        // we have a single item dip, the dip since last sum can be 
        // counted in last_sum.
        if (arr[i] < last_item_del)
        {
            last_sum_del += -last_item_del + arr[i];
            last_item_del = arr[i];
        }

        if (arr[i] < next_item_del) next_item_del = arr[i];
        // If we have a lower sum, even account for new dip, 
        // we use the new last_sum
        if (sum <= last_sum)
        {
            last_sum = sum;
            next_item_del = 0;
        }
        if (sum <= last_sum_del)
        {
            last_sum_del = sum;
            last_item_del = 0;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1191. K-Concatenation Maximum Sum
/// 
/// Given an integer array arr and an integer k, modify the array by repeating 
/// it k times.
/// For example, if arr = [1, 2] and k = 3 then the modified array will 
/// be [1, 2, 1, 2, 1, 2].
/// Return the maximum sub-array sum in the modified array. Note that the 
/// length of the sub-array can be 0 and its sum in that case is 0.
///
/// As the answer can be very large, return the answer modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: arr = [1,2], k = 3
/// Output: 9
///
/// Example 2:
/// Input: arr = [1,-2,1], k = 5
/// Output: 2
/// Example 3:
/// Input: arr = [-1,-2], k = 7
/// Output: 0
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 1 <= k <= 10^5
/// 3. -10^4 <= arr[i] <= 10^4
/// </summary>
int LeetCode::kConcatenationMaxSum(vector<int>& arr, int k)
{
    int M = 1000000007;
    long long sum = 0;
    long long min_sum = 0;
    long long max_sum = 0;
    long long max_sub = 0;

    for (size_t i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        max_sub = max(max_sub, sum - min_sum);
        min_sum = min(min_sum, sum);
        max_sum = max(max_sum, sum);
    }

    long long result = 0;
    if (sum > 0 && k > 1)
    {
        result = sum * k - min_sum;
        if (sum < max_sum)
        {
            result -= sum - max_sum;
        }
    }
    else
    {
        result = max_sum;
        if (k > 1) result += sum - min_sum;
        result = max(result, max_sub);
    }
    result = result % M;
    return (int)result;
}

/// <summary>
/// Leet code #1196. How Many Apples Can You Put into the Basket
/// 
/// You have some apples, where arr[i] is the weight of the i-th apple.  
/// You also have a basket that can carry up to 5000 units of weight.
///
/// Return the maximum number of apples you can put in the basket.
/// 
/// Example 1:
///
/// Input: arr = [100,200,150,1000]
/// Output: 4
/// Explanation: All 4 apples can be carried by the basket since their 
/// sum of weights is 1450.
///
/// Example 2:
///
/// Input: arr = [900,950,800,1000,700,800]
/// Output: 5
/// Explanation: The sum of weights of the 6 apples exceeds 5000 so we 
/// choose any 5 of them.
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 10^3
/// 2. 1 <= arr[i] <= 10^3
/// </summary>
int LeetCode::maxNumberOfApples(vector<int>& arr)
{
    priority_queue<int> basket;
    int sum = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        basket.push(arr[i]);
        sum += arr[i];
        if (sum > 5000)
        {
            sum -= basket.top();
            basket.pop();
        }
    }
    return basket.size();
}

/// <summary>
/// Leet code #1200. Minimum Absolute Difference
/// 
/// Given an array of distinct integers arr, find all pairs of elements 
/// with the minimum absolute difference of any two elements. 
///
/// Return a list of pairs in ascending order(with respect to pairs), 
/// each pair [a, b] follows
///
/// a, b are from arr
/// a < b
/// b - a equals to the minimum absolute difference of any two elements in arr
/// 
///
/// Example 1:
///
/// Input: arr = [4,2,1,3]
/// Output: [[1,2],[2,3],[3,4]]
/// Explanation: The minimum absolute difference is 1. List all pairs with 
/// difference equal to 1 in ascending order.
///
/// Example 2:
///
/// Input: arr = [1,3,6,10,15]
/// Output: [[1,3]]
///
/// Example 3:
///
/// Input: arr = [3,8,-10,23,19,-4,-14,27]
/// Output: [[-14,-10],[19,23],[23,27]]
/// 
/// Constraints:
/// 1. 2 <= arr.length <= 10^5
/// 2. -10^6 <= arr[i] <= 10^6
/// </summary>
vector<vector<int>> LeetCode::minimumAbsDifference(vector<int>& arr)
{
    int diff = INT_MAX;
    vector<int> nums = arr;
    sort(nums.begin(), nums.end());
    deque<vector<int>> min_deque;
    for (size_t i = 0; i < nums.size() -1; i++)
    {
        if (nums[i + 1] - nums[i] < diff)
        {
            min_deque.clear();
            diff = nums[i + 1] - nums[i];
        }
        if (nums[i + 1] - nums[i] == diff)
        {
            min_deque.push_back({ nums[i], nums[i + 1] });
        }
    }
    vector<vector<int>> result = vector<vector<int>>(min_deque.begin(), min_deque.end());
    return result;
}

/// <summary>
/// Leet code #1198. Find Smallest Common Element in All Rows
/// 
/// Given a matrix mat where every row is sorted in increasing order, return 
/// the smallest common element in all rows.
///
/// If there is no common element, return -1.
///
/// 
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
int LeetCodeArray::smallestCommonElement(vector<vector<int>>& mat)
{
    priority_queue<pair<int, int>> common;
    int largest = 0;
    for (size_t i = 0; i < mat.size(); i++)
    {
        common.push(make_pair(-mat[i][0], i));
        largest = max(largest, mat[i][0]);
    }
    int result = -1;
    while (!common.empty())
    {
        pair<int, int> pos = common.top();
        common.pop();
        result = -pos.first;
        if (result == largest)
        {
            return result;
        }
        else
        {
            int index = lower_bound(mat[pos.second].begin(), mat[pos.second].end(), largest) 
                        - mat[pos.second].begin();
            if (index == mat[pos.second].size())
            {
                return -1;
            }
            else
            {
                largest = max(largest, mat[pos.second][index]);
                common.push(make_pair(0-mat[pos.second][index], pos.second));
            }
        }
    }
    return result;
}

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
/// Input: s = "bacd", t = "cade", maxCost = 0
/// Output: 1
/// Explanation: You can't make any change, so the maximum length is 1.
/// 
/// Constraints:
/// 1. 1 <= s.length, t.length <= 10^5
/// 2. 0 <= maxCost <= 10^6
/// 3. s and t only contain lower case English letters.
/// </summary>
int LeetCodeArray::equalSubstring(string s, string t, int maxCost)
{
    int sum = 0;
    int result = 0;
    deque<int> sub_deq;
    for (size_t i = 0; i < s.size(); i++)
    {
        int cost = abs(s[i] - t[i]);
        sub_deq.push_back(cost);
        sum += cost;
        while ((!sub_deq.empty()) && (sum > maxCost))
        {
            sum -= sub_deq.front();
            sub_deq.pop_front();
        }
        if (sum <= maxCost)
        {
            result = max(result, (int)sub_deq.size());
        }
    }
    return result;
}

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
int LeetCodeArray::balancedStringSplit(string s)
{
    int result = 0;
    int match = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L') match++;
        else match--;
        if (match == 0) result++;
    }
    return result;
}

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
vector<vector<int>> LeetCodeArray::queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
{
    vector<vector<int>> result;
    vector<vector<int>> board(8, vector<int>(8));
    for (size_t i = 0; i < queens.size(); i++)
    {
        board[queens[i][0]][queens[i][1]] = 1;
    }

    for (size_t i = 0; i < 8; i++)
    {
        int r = king[0];
        int c = king[1];
        if (i == 0)
        {
            while (r >= 0 && c >= 0 && board[r][c] == 0)
            {
                r--;
                c--;
            }
        }
        else if (i == 1)
        {
            while (r >= 0 && c >= 0 && board[r][c] == 0)
            {
                r--;
            }
        }
        else if (i == 2)
        {
            while (r >= 0 && c >= 0 && board[r][c] == 0)
            {
                c--;
            }
        }
        else if (i == 3)
        {
            while (r >= 0 && c < 8 && board[r][c] == 0)
            {
                r--;
                c++;
            }
        }
        else if (i == 4)
        {
            while (r < 8 && c >= 0 && board[r][c] == 0)
            {
                r++;
                c--;
            }
        }
        else if (i == 5)
        {
            while (r < 8 && c < 8 && board[r][c] == 0)
            {
                r++;
            }
        }
        else if (i == 6)
        {
            while (r < 8 && c < 8 && board[r][c] == 0)
            {
                c++;
            }
        }
        else
        {
            while (r < 8 && c < 8 && board[r][c] == 0)
            {
                r++;
                c++;
            }
        }
        if (r >= 0 && c >= 0 && r < 8 && c < 8)
        {
            result.push_back({ r, c });
        }
    }
    return result;
}

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
int LeetCodeArray::missingNumber(vector<int>& arr)
{
    int prev = 0;
    int prev_diff = 0;
    int result = 0;
    for (size_t i = 1; i < arr.size(); i++)
    {
        int diff = arr[i] - arr[i - 1];
        if ((i == 1) || (prev_diff == diff))
        {
            prev = arr[i - 1];
            prev_diff = arr[i] - arr[i - 1];
        }
        else
        {
            if (abs(prev_diff) < abs(diff))
            {
                result = arr[i - 1] + prev_diff;
            }
            else
            {
                result = prev + diff;
            }
            break;
        }
    }
    return result;
}

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
int LeetCodeArray::maxProduct(vector<int>& nums)
{
    int result = INT_MIN;
    int min_product = 1;
    int max_product = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int curr_min = min(min(nums[i] * min_product, nums[i] * max_product), nums[i]);
        int curr_max = max(max(nums[i] * min_product, nums[i] * max_product), nums[i]);
        min_product = curr_min;
        max_product = curr_max;
        result = max(result, max_product);
    }
    return result;
}

/// <summary>
/// Leet code #325. Maximum Size Subarray Sum Equals k
/// 
/// Given an array nums and a target value k, find the maximum length of a 
/// subarray that sums to k. 
/// If there isn't one, return 0 instead. 
/// Note:
/// The sum of the entire nums array is guaranteed to fit within the 32-bit 
/// signed integer range. 
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
int LeetCodeArray::maxSubArrayLen(vector<int>& nums, int k)
{
    unordered_map<int, int> sum_map;
    int sum = 0;
    int max_length = 0;

    sum_map[0] = -1;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        sum += nums[i];
        if (sum_map.find(sum - k) != sum_map.end())
        {
            max_length = max(max_length, i - sum_map[sum - k]);
        }
        if (sum_map.find(sum) == sum_map.end())
        {
            sum_map[sum] = i;
        }
    }
    return max_length;
}

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
bool LeetCodeArray::checkSubarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int> num_map;
    int sum = 0;
    num_map[sum] = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (k == 0)
        {
            if ((num_map.count(-sum) > 0) && (num_map[-sum] + 1 < (int)i))
            {
                return true;
            }
            if (num_map.count(sum) == 0) num_map[sum] = i;
        }
        else
        {
            if ((num_map.count(sum % k) > 0) && (num_map[sum % k] + 1 < (int)i))
            {
                return true;
            }
            if (num_map.count(sum % k) == 0) num_map[sum % k] = i;
        }
    }
    return false;
}

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
int LeetCodeArray::findMaxLength(vector<int>& nums)
{
    unordered_map<int, int> pos_map;

    // set the initial equal point before the array
    pos_map[0] = -1;
    vector<int> num_count(nums.size());
    int max_length = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            num_count[i] = -1;
        }
        else
        {
            num_count[i] = 1;
        }
        if (i > 0) num_count[i] += num_count[i - 1];
        if (pos_map.count(num_count[i]) == 0)
        {
            pos_map[num_count[i]] = i;
        }
        else
        {
            max_length = max(max_length, (int)(i - pos_map[num_count[i]]));
        }
    }
    return max_length;
}

/// <summary>
/// Leet code #560. Subarray Sum Equals K
///
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
int LeetCodeArray::subarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int> sum_map;
    int sum = 0;
    int count = 0;
    sum_map[0] = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum_map.count(sum - k) > 0)
        {
            count += sum_map[sum - k];
        }
        sum_map[sum]++;
    }
    return count;
}

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
/// [1,0,1,x,x]
/// [1,0,1,0,x]
/// [x,0,1,0,1]
/// [x,x,1,0,1]
/// 
/// Note:
/// 
/// 1. A.length <= 30000
/// 2. 0 <= S <= A.length
/// 3. A[i] is either 0 or 1.
/// </summary>
int LeetCodeArray::numSubarraysWithSum(vector<int>& A, int S)
{
    int result = 0;

    vector<int> dp;
    dp.push_back(0);

    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == 1) dp.push_back(0);
        else dp[dp.size() - 1]++;
        if (dp.size() < (size_t)(S + 1)) continue;
        if (S == 0)
        {
            result += dp[dp.size() - 1];
        }
        else
        {
            result += dp[dp.size() - 1 - S] + 1;
        }
    }
    return result;
}

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
int LeetCodeArray::subarraysDivByK(vector<int>& A, int K)
{
    vector<int> remainder(K);
    remainder[0]++;
    int sum = 0;
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        sum += A[i];
        int mod = (sum % K + K) % K;
        result += remainder[mod];
        remainder[mod]++;
    }
    return result;
}

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
vector<int> LeetCodeArray::transformArray(vector<int>& arr)
{
    vector<int> result = arr;
    bool is_final = false;
    while (!is_final)
    {
        is_final = true;
        int left = result[0];
        for (size_t i = 1; i < result.size() - 1; i++)
        {
            int right = result[i + 1];
            int new_val = result[i];
            if (result[i] < left && result[i] < right)
            {
                is_final = false;
                new_val++;
            }
            else if (result[i] > left&& result[i] > right)
            {
                is_final = false;
                new_val--;
            }
            left = result[i];
            result[i] = new_val;
        }
    }
    return result;
}

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
int LeetCodeArray::numberOfSubarrays(vector<int>& nums, int k)
{
    deque<int> window;
    int count = 1;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 1)
        {
            window.push_back(count);
            count = 1;
        }
        else
        {
            count++;
        }
        if (window.size() == k)
        {
            result += window.front();
        }
        else if (window.size() == k + 1)
        {
            window.pop_front();
            result += window.front();
        }
    }
    return result;
}

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
int LeetCodeArray::oddCells(int n, int m, vector<vector<int>>& indices)
{
    vector<int> row(n), col(m);
    for (size_t i = 0; i < indices.size(); i++)
    {
        row[indices[i][0]]++;
        col[indices[i][1]]++;
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((row[i] + col[j]) % 2 == 1) result++;
        }
    }
    return result;
}

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
vector<vector<int>> LeetCodeArray::reconstructMatrix(int upper, int lower, vector<int>& colsum)
{
    vector<vector<int>> result(2);

    for (size_t i = 0; i < colsum.size(); i++)
    {
        if (colsum[i] == 0)
        {
            result[0].push_back(0);
            result[1].push_back(0);
        }
        else if (colsum[i] == 2)
        {
            result[0].push_back(1);
            result[1].push_back(1);
            upper--;
            lower--;
        }
        else 
        {
            if (upper >= lower)
            {
                result[0].push_back(1);
                result[1].push_back(0);
                upper--;
            }
            else
            {
                result[0].push_back(0);
                result[1].push_back(1);
                lower--;
            }
        }
        if (upper < 0 || lower < 0)
        {
            result.clear();
            break;
        }
    }
    if (upper != 0 || lower != 0)
    {
        result.clear();
    }
    return result;
}

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
vector<vector<int>> LeetCodeArray::shiftGrid(vector<vector<int>>& grid, int k)
{
    vector<vector<int>> result = grid;

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            int col = j + k;
            int row = i;
            row = row + (col / grid[i].size());
            row = row % grid.size();
            col = col % grid[i].size();
            result[row][col] = grid[i][j];
        }
    }
    return result;
}

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
int LeetCodeArray::countServers(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> row(m), col(n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                row[i] ++;
                col[j] ++;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                if (row[i] > 1 || col[j] > 1)
                {
                    result++;
                }
            }
        }
    }
    return result;
}

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
string LeetCodeArray::tictactoe(vector<vector<int>>& moves)
{
    vector<int> row(3), col(3), diag_s(6), diag_r(6);

    for (size_t i = 0; i < moves.size(); i++)
    {
        if (i % 2 == 0)
        {
            row[moves[i][0]]++;
            col[moves[i][1]]++;
            diag_s[moves[i][0] + moves[i][1]]++;
            diag_r[moves[i][0] + 3 - moves[i][1]]++;
            if (row[moves[i][0]] == 3 || 
                col[moves[i][1]] == 3 ||
                diag_s[moves[i][0] + moves[i][1]] == 3 ||
                diag_r[moves[i][0] + 3 - moves[i][1]] == 3)
            {
                return "A";
            }
        }
        else
        {
            row[moves[i][0]]--;
            col[moves[i][1]]--;
            diag_s[moves[i][0] + moves[i][1]]--;
            diag_r[moves[i][0] + 3 - moves[i][1]]--;
            if (row[moves[i][0]] == -3 || 
                col[moves[i][1]] == -3 ||
                diag_s[moves[i][0] + moves[i][1]] == -3 ||
                diag_r[moves[i][0] + 3 - moves[i][1]] == -3)
            {
                return "B";
            }
        }
    }
    if (moves.size() == 9) return "Draw";
    else return "Pending";
}

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
vector<vector<int>> LeetCodeArray::groupThePeople(vector<int>& groupSizes)
{
    vector<vector<int>> result;
    vector<pair<int, int>> people;
    for (size_t i = 0; i < groupSizes.size(); i++)
    {
        people.push_back({ groupSizes[i], i });
    }
    sort(people.begin(), people.end());
    vector<int> bag;
    for (size_t i = 0; i < people.size(); i++)
    {
        bag.push_back(people[i].second);
        if (bag.size() == people[i].first )
        {
            result.push_back(bag);
            bag.clear();
        }
    }
    return result;
}

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
int LeetCodeArray::findSpecialInteger(vector<int>& arr)
{
    int result = 0;
    auto itr = arr.begin();
    while (itr != arr.end())
    {
        auto next = upper_bound(itr, arr.end(), *itr);
        int distance = next - itr;
        if (distance > (int)arr.size() / 4)
        {
            result = *itr;
            break;
        }
        itr = next;
    }
    return result;
}

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
///
/// Constraints:
/// 1. 1 <= m, n <= 300
/// 2. m == mat.length
/// 3. n == mat[i].length
/// 4. 0 <= mat[i][j] <= 10000
/// 5. 0 <= threshold <= 10^5
/// </summary>
int LeetCodeArray::maxSideLength(vector<vector<int>>& mat, int threshold)
{
    int result = 0;
    vector<vector<int>> sum(mat.size(), vector<int>(mat[0].size()));
    vector<int> row(mat.size());
    vector<int> col(mat[0].size());

    for (int i = 0; i < (int)mat.size(); i++)
    {
        for (int j = 0; j < (int)mat[0].size(); j++)
        {
            sum[i][j] = mat[i][j];
            sum[i][j] += row[i];
            sum[i][j] += col[j];
            if (i > 0 && j > 0) sum[i][j] += sum[i - 1][j - 1];            
            row[i] += mat[i][j];
            col[j] += mat[i][j];

            for (int k = result; k < min(i, j) + 1; k++)
            {
                int s = sum[i][j];
                if (i >= (k + 1)) s -= sum[i - (k + 1)][j];
                if (j >= (k + 1)) s -= sum[i][j - (k + 1)];
                if (i >= (k + 1) && j >= (k + 1)) s += sum[i - (k + 1)][j - (k + 1)];
                if (s <= threshold)
                {
                    result = k + 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return result;
}

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
bool LeetCodeArray::isPossibleDivide(vector<int>& nums, int k)
{
    map<int, int> sorted_num;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sorted_num[nums[i]]++;
    }
    while (!sorted_num.empty())
    {
        int first = sorted_num.begin()->first;
        int second = sorted_num.begin()->second;
        for (int i = 0; i < k; i++)
        {
            if (sorted_num[first + i] < second) return false;
            sorted_num[first + i] -= second;
            if (sorted_num[first + i] == 0)
            {
                sorted_num.erase(first + i);
            }
        }
    }
    return true;
}

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
vector<int> LeetCodeArray::replaceElements(vector<int>& arr)
{
    int right = -1;
    vector<int> result(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        result[i] = right;
        right = max(arr[i], right);
    }
    return result;
}

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
bool LeetCodeArray::canReach(vector<int>& arr, int start)
{
    queue<int> search;
    search.push(start);
    vector<int> visited(arr.size());
    visited[start] = 1;

    while (!search.empty())
    {
        int index = search.front();
        search.pop();
        if (arr[index] == 0) return true;
        int next = index + arr[index];
        if (next < (int)arr.size() && visited[next] == 0)
        {
            search.push(next);
            visited[next] = 1;
        }
        next = index - arr[index];
        if (next >= 0 && visited[next] == 0)
        {
            search.push(next);
            visited[next] = 1;
        }
    }
    return false;
}

#pragma endregion