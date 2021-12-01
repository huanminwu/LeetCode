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
/// Leet code #11. Container With Most Water 
/// 
/// Given n non-negative integers a1, a2, ..., an, where each represents 
/// a point at coordinate (i, ai). n vertical lines are drawn such that 
/// the two endpoints of line i is at (i, ai) and (i, 0). 
/// Find two lines, which together with x-axis forms a container, such 
/// that the container contains the most water. 
/// Note: You may not slant the container. 
/// </summary>
int LeetCodeArray::maxArea(vector<int>& height)
{
    int maxArea = 0;
    int first = 0, last = height.size() - 1;
    while (first < last)
    {
        int area = min(height[first], height[last]) * (last - first);
        if (area > maxArea)
        {
            maxArea = area;
        }

        if (height[first] < height[last])
        {
            first++;
        }
        else
        {
            last--;
        }
    }
    return maxArea;
}

/// <summary>
/// Leet code #16. 3Sum Closest 
/// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
/// Return the sum of the three integers. You may assume that each input would have exactly one solution.
/// For example, given array S = {-1 2 1 -4}, and target = 1.
/// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
/// </summary>
int LeetCodeArray::threeSumClosest(vector<int>& nums, int target)
{
    int global_diff = INT_MAX;
    int global_sum = 0;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 2; i++)
    {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            int diff = sum - target;
            if (abs(diff) < global_diff)
            {
                global_diff = abs(diff);
                global_sum = sum;
            }
            if (sum == target)
            {
                return sum;
            }
            else if (sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return global_sum;
}

/// <summary>
/// Leet code #42. Trapping Rain Water    
/// Given n non-negative integers representing an elevation map where the 
/// width of each bar is 1, 
/// compute how much water it is able to trap after raining.
/// For example, 
/// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
/// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
/// In this case, 6 units of rain water (blue section) are being trapped. 
/// </summary>
int LeetCodeArray::trapWater(vector<int>& height)
{
    int sum = 0;
    int left_index = 0;
    int right_index = height.size() - 1;
    int left_value = height[left_index];
    int right_value = height[right_index];
    while (left_index < right_index)
    {

        if (left_value < right_value)
        {
            left_index++;
            // if left side become lower, take the water and fill it
            if (height[left_index] < left_value)
            {
                sum = sum + left_value - height[left_index];
            }
            else
            {
                left_value = height[left_index];
            }
        }
        else
        {
            right_index--;
            // if right side become lower, take the water and fill it
            if (height[right_index] < right_value)
            {
                sum = sum + right_value - height[right_index];
            }
            else
            {
                right_value = height[right_index];
            }
        }
    }
    return sum;
}

/// <summary>
/// Leet code #27. Remove Element
/// Given an array and a value, remove all instances of that value in place 
/// and return the new length. 
/// Do not allocate extra space for another array, you must do this in place 
/// with constant memory.
/// The order of elements can be changed. It doesn't matter what you leave 
/// beyond the new length.
/// Example:
/// Given input array nums = [3,2,2,3], val = 3 
/// Your function should return length = 2, with the first two elements of 
/// nums being 2.
/// </summary> 
int LeetCodeArray::removeArrayElement(vector<int>& nums, int val)
{
    if (nums.size() == 0)  return nums.size();
    int last = nums.size() - 1;
    int first = 0;
    while (first < last)
    {
        if (nums[first] == val)
        {
            swap(nums[first], nums[last]);
            last--;
        }
        else
        {
            first++;
        }
    }
    if (nums[first] != val) first++;
    nums.erase(nums.begin() + first, nums.end());
    return nums.size();
}

/// <summary>
/// Leet code #283. Move Zeroes
///
/// Given an array nums, write a function to move all 0's to the end of it 
/// while maintaining the relative order of the non-zero elements.
/// For example, given nums = [0, 1, 0, 3, 12], after calling your function, 
/// nums should be [1, 3, 12, 0, 0].  
/// Note:
/// 1.You must do this in-place without making a copy of the array.
/// 2.Minimize the total number of operations
/// </summary>
void LeetCodeArray::moveZeroes(vector<int>& nums)
{
    size_t first = 0;
    size_t last = 1;
    while (last < nums.size())
    {
        if (nums[last] == 0)
        {
            last++;
            continue;
        }
        if (nums[first] == 0)
        {
            swap(nums[first], nums[last]);
            last++;
        }
        if (nums[first] != 0) first++;
        if (first >= last) last = first + 1;
    }
}

/// <summary>
/// Leet code #345. Reverse Vowels of a String 
/// Write a function that takes a string as input and reverse only the vowels of a string.
/// Example 1:
/// Given s = "hello", return "holle". 
/// Example 2:
/// Given s = "leetcode", return "leotcede". 
/// Note:
/// The vowels does not include the letter "y". 
/// </summary>
string LeetCodeArray::reverseVowels(string s)
{
    int first = 0;
    int last = s.size() - 1;
    unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
    while (first < last)
    {
        if (vowels.find(tolower(s[first])) == vowels.end())
        {
            first++;
        }
        else if (vowels.find(tolower(s[last])) == vowels.end())
        {
            last--;
        }
        else
        {
            swap(s[first], s[last]);
            first++; last--;
        }
    }
    return s;
}

// <summary>
/// Leet code #167. Two Sum II - Input array is sorted
/// Given an array of integers that is already sorted in ascending order, 
/// find two numbers such that they add up to a specific target number.
/// The function twoSum should return indices of the two numbers such that 
/// they add up to the target, 
/// where index1 must be less than index2. Please note that your returned 
/// answers (both index1 and index2) are not zero-based.
///
/// You may assume that each input would have exactly one solution. 
/// Input: numbers={2, 7, 11, 15}, target=9
///
/// Output: index1=1, index2=2 
/// </summary>
vector<int> LeetCodeArray::twoSumII(vector<int>& numbers, int target)
{
    vector<int> result;
    int first = 0, last = numbers.size() - 1;
    while (first < last)
    {
        if (numbers[first] + numbers[last] == target)
        {
            result.push_back(first + 1);
            result.push_back(last + 1);
            break;
        }
        else if (numbers[first] + numbers[last] < target)
        {
            first++;
        }
        else
        {
            last--;
        }
    }
    return result;
}

/// <summary>
/// Leet code #209. Minimum Size Subarray Sum   
/// 
/// Medium
///
/// Given an array of n positive integers and a positive integer s, find 
/// the minimal length of a contiguous subarray of which the sum ≥ s. If 
/// there isn't one, return 0 instead.
///
/// Example: 
/// Input: s = 7, nums = [2,3,1,2,4,3]
/// Output: 2
/// Explanation: the subarray [4,3] has the minimal length under the 
/// problem constraint.
/// Follow up:
/// If you have figured out the O(n) solution, try coding another 
/// solution of which the time complexity is O(n log n). 
/// </summary>
int LeetCodeArray::minSubArrayLen(int s, vector<int>& nums)
{
    int result = 0;
    int first = 0;
    int last = -1;
    int sum = 0;
    while (last < (int)nums.size())
    {
        if (sum < s)
        {
            last++;
            if (last < (int)nums.size()) sum += nums[last];
        }
        while (sum >= s && first <= last)
        {
            result = (result == 0) ? last - first + 1 : min(result, last - first + 1);
            sum -= nums[first];
            first++;
        }
    }
    return result;
}


/// <summary>
/// Leet code #259. 3Sum Smaller  
/// 
/// Given an array of n integers nums and a target, find the number of index 
/// triplets i, j, k with 0 <= i < j < k < n that satisfy the condition 
/// nums[i] + nums[j] + nums[k] < target.
/// For example, given nums = [-2, 0, 1, 3], and target = 2.
/// Return 2. Because there are two triplets which sums are less than 2:
/// [-2, 0, 1]
/// [-2, 0, 3]
/// Follow up:
/// Could you solve it in O(n2) runtime? 
/// </summary>
int LeetCodeArray::threeSumSmaller(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < (int)nums.size() - 2; i++)
    {
        int k = nums.size() - 1;
        for (int j = i + 1; j < (int)nums.size() - 1; j++)
        {
            while ((k > j) && (nums[i] + nums[j] + nums[k] >= target))
            {
                k--;
            }
            if (k > j)
            {
                result += k - j;
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
/// Leet code #487. Max Consecutive Ones II       
/// 
/// Given a binary array, find the maximum number of consecutive 1s in this 
/// array if you can flip at most one 0.  
/// Example 1: 
/// Input: [1,0,1,1,0]
///
/// Output: 4 
/// Explanation: Flip the first zero will get the the maximum number of 
/// consecutive 1s.
/// After flipping, the maximum number of consecutive 1s is 4.
///	Note:
/// The input array will only contain 0 and 1.
/// The length of input array is a positive integer and will not exceed 10,000
/// Follow up:
/// What if the input numbers come in one by one as an infinite stream? In other words, 
/// you can't store all numbers coming from the stream as it's too large to hold in memory. 
/// Could you solve it efficiently? 
/// </summary>
int LeetCodeArray::findMaxConsecutiveOnesII(vector<int>& nums)
{
    size_t first = 0, last = 0, max_length = 0, count = 0;
    while (last <= nums.size())
    {
        if (count > 1)
        {
            if (nums[first] == 0)
            {
                count--;
            }
            first++;
        }
        else
        {
            max_length = max(max_length, last - first);
            if (last < nums.size())
            {
                if (nums[last] == 0) count++;
            }
            last++;
        }
    }
    return max_length;
}

/// <summary>
/// Leet code #544. Output Contest Matches       
/// 
/// During the NBA playoffs, we always arrange the rather strong team to 
/// play with the rather weak team, like make the rank 1 team play with 
/// the rank nth team, which is a good strategy to make the contest more 
/// interesting. Now, you're given n teams, you need to output their final 
/// contest matches in the form of a string.
///
/// The n teams are given in the form of positive integers from 1 to n, 
/// which represents their initial rank. (Rank 1 is the strongest team 
/// and Rank n is the weakest team.) We'll use parentheses('(', ')') and 
/// commas(',') to represent the contest team pairing - parentheses
/// ('(' , ')') for pairing and commas(',') for partition. During the 
/// pairing process in each round, you always need to follow the strategy 
/// of making the rather strong one pair with the rather weak one.
/// 
/// Example 1:
/// Input: 2
/// Output: (1,2)
/// Explanation: 
/// Initially, we have the team 1 and the team 2, placed like: 1,2.
/// Then we pair the team (1,2) together with '(', ')' and ',', which is 
/// the final answer.
/// Example 2:
/// Input: 4
/// Output: ((1,4),(2,3))
/// Explanation: 
/// In the first round, we pair the team 1 and 4, the team 2 and 3 
/// together, as we need to make the strong team and weak team together.
/// And we got (1,4),(2,3).
/// In the second round, the winners of (1,4) and (2,3) need to play again 
/// to generate the final winner, so you need to add the paratheses outside 
/// them.
/// And we got the final answer ((1,4),(2,3)).
/// Example 3:
/// Input: 8
/// Output: (((1,8),(4,5)),((2,7),(3,6)))
/// Explanation: 
/// First round: (1,8),(2,7),(3,6),(4,5)
/// Second round: ((1,8),(4,5)),((2,7),(3,6))
/// Third round: (((1,8),(4,5)),((2,7),(3,6)))
/// Since the third round will generate the final winner, you need to 
/// output the answer (((1,8),(4,5)),((2,7),(3,6))).
/// Note:
/// The n is in range [2, 212].
/// We ensure that the input n can be converted into the form 2^k, where k is a positive integer.
/// </summary>
string LeetCodeArray::findContestMatch(int n)
{
    vector<string> match(n);
    for (size_t i = 0; i < (size_t)n; i++)
    {
        match[i] = to_string(i + 1);
    }
    while (n > 1)
    {
        int index = n - 1;
        while (index >= n / 2)
        {
            match[n - 1 - index] = "(" + match[n - 1 - index] + "," + match[index] + ")";
            index--;
        }
        n = n / 2;
    }
    return match[0];
}


/// <summary>
/// Leet code #680. Valid Palindrome II
/// 
/// Given a non-empty string s, you may delete at most one character. 
/// Judge whether you can make it a palindrome.
/// Example 1:
/// Input: "aba"
/// Output: True
/// Example 2:
/// Input: "abca"
/// Output: True
/// Explanation: You could delete the character 'c'.
/// Note:
/// The string will only contain lowercase characters a-z. The maximum 
/// length of the string is 50000.
/// </summary>
bool LeetCodeArray::validPalindrome(string s)
{
    stack<vector<int>> stk;
    stk.push({ 0, (int)s.size() - 1, 1 });
    while (!stk.empty())
    {
        vector<int> pos = stk.top();
        stk.pop();
        while (s[pos[0]] == s[pos[1]] && pos[0] < pos[1])
        {
            pos[0]++;
            pos[1]--;
        }
        if (pos[0] >= pos[1])
        {
            return true;
        }
        if (pos[2] == 0) // we already delete one letter
        {
            continue;
        }
        else
        {
            pos[2]--;
            stk.push({ pos[0] + 1, pos[1], pos[2] });
            stk.push({ pos[0], pos[1] - 1, pos[2] });
        }
    }
    return false;
}

/// <summary>
/// Leet code #713. Subarray Product Less Than K
/// Your are given an array of positive integers nums.
/// 
/// Count and print the number of (contiguous) subarrays where the product 
/// of all the elements in the subarray is less than k.
///
/// Example 1:
/// Input: nums = [10, 5, 2, 6], k = 100
/// Output: 8
/// Explanation: The 8 subarrays that have product less than 100 are: 
/// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
/// Note that [10, 5, 2] is not included as the product of 100 is not 
/// strictly less than k.
/// Note:
/// 
/// 0 < nums.length <= 50000.
/// 0 < nums[i] < 1000.
/// 0 <= k < 10^6.
/// </summary>
int LeetCodeArray::numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    int product = 1;
    int first = 0, last = 0;
    unsigned long result = 0;
    unsigned long prev_dist = 0, distance = 0;
    while (last <= (int)nums.size())
    {
        if ((last < (int)nums.size()) && (product * nums[last] < k))
        {
            product *= nums[last];
            last++;
            distance = last - first;
        }
        else
        {
            if (distance > 0)
            {
                result = result + (distance) * (distance + 1) / 2 - prev_dist * (prev_dist + 1) / 2;
                prev_dist = distance;
                distance = 0;
            }
            if (first < last)
            {
                product /= nums[first];
            }
            first++;
            if (prev_dist > 0) prev_dist--;
            last = max(first, last);
        }
    }
    return (int)result;
}

/// <summary>
/// Leet code #443. String Compression
///
/// Given an array of characters, compress it in-place.
///
/// The length after compression must always be smaller than or equal to 
/// the original array.
/// Every element of the array should be a character (not int) of length 1.
/// After you are done modifying the input array in-place, return the new 
/// length of the array.
///
/// Follow up:
/// Could you solve it using only O(1) extra space?
///
/// Example 1:
/// Input:
/// ["a","a","b","b","c","c","c"]
/// Output:
/// Return 6, and the first 6 characters of the input array should be: 
/// ["a","2","b","2","c","3"]
///
/// Explanation:
/// "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced 
/// by "c3".
///
/// Example 2:
/// Input:
/// ["a"]
/// Output:
/// Return 1, and the first 1 characters of the input array should be: 
/// ["a"]
///
/// Explanation:
/// Nothing is replaced.
/// Example 3:
/// Input:
/// ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
///
/// Output:
/// Return 4, and the first 4 characters of the input array should be: 
/// ["a","b","1","2"].
///
/// Explanation:
/// Since the character "a" does not repeat, it is not compressed. 
/// "bbbbbbbbbbbb" is replaced by "b12".
/// Notice each digit has it's own entry in the array.
/// Note:
/// All characters have an ASCII value in [35, 126].
/// 1 <= len(chars) <= 1000.
/// </summary>
int LeetCodeArray::compress(vector<char>& chars)
{
    int pos = 0, count = 0;
    for (int i = 0; i <= (int)chars.size(); i++)
    {
        if ((i > 0) && (i < (int)chars.size()) && (chars[i] == chars[i - 1]))
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                string str = to_string(count);
                for (char ch : str)
                {
                    chars[pos] = ch;
                    pos++;
                }
            }
            if (i < (int)chars.size())
            {
                chars[pos] = chars[i];
                pos++;
                count = 1;
            }
        }
    }
    return pos;
}

/// <summary>
/// Leet code #755. Pour Water    
/// We are given an elevation map, heights[i] representing the height of the 
/// terrain at that index. The width at each index is 1. After V units of 
/// water fall at index K, how much water is at each index?
///
/// Water first drops at index K and rests on top of the highest terrain or 
/// water at that index. Then, it flows according to the following rules:
///
/// If the droplet would eventually fall by moving left, then move left.
/// Otherwise, if the droplet would eventually fall by moving right, then 
/// move right.
/// Otherwise, rise at it's current position.
/// Here, "eventually fall" means that the droplet will eventually be at a 
/// lower level if it moves in that direction. Also, "level" means the height 
/// of the terrain plus any water in that column.
/// We can assume there's infinitely high terrain on the two sides out of 
/// bounds of the array. Also, there could not be partial water being spread 
/// out evenly on more than 1 grid block - each unit of water has to be in 
/// exactly one block.
///
/// Example 1:
/// Input: heights = [2,1,1,2,1,2,2], V = 4, K = 3
/// Output: [2,2,2,3,2,2,2]
/// Explanation:
/// #       #
/// #       #
/// ##  # ###
/// #########
///  0123456    <- index
///
/// The first drop of water lands at index K = 3:
/// 
/// #       #
/// #   w   #
/// ##  # ###
/// #########
///  0123456    
/// 
/// When moving left or right, the water can only move to the same level or a 
/// lower level.
/// (By level, we mean the total height of the terrain plus any water in that 
/// column.)
/// Since moving left will eventually make it fall, it moves left.
/// (A droplet "made to fall" means go to a lower height than it was at 
/// previously.)
///
/// #       #
/// #       #
/// ## w# ###
/// #########
///  0123456    
///
/// Since moving left will not make it fall, it stays in place.  The next 
/// droplet falls:
///
/// #       #
/// #   w   #
/// ## w# ###
/// #########
///  0123456  
///
/// Since the new droplet moving left will eventually make it fall, it moves 
/// left.
/// Notice that the droplet still preferred to move left,
/// even though it could move right (and moving right makes it fall quicker.)
/// 
/// #       #
/// #  w    #
/// ## w# ###
/// #########
/// 0123456  
///
/// #       #
/// #       #
/// ##ww# ###
/// #########
///  0123456  
///
/// After those steps, the third droplet falls.
/// Since moving left would not eventually make it fall, it tries to move 
/// right.
/// Since moving right would eventually make it fall, it moves right.
///
/// #       #
/// #   w   #
/// ##ww# ###
/// #########
///  0123456  
/// 
/// #       #
/// #       #
/// ##ww#w###
/// #########
///  0123456  
/// 
/// Finally, the fourth droplet falls.
/// Since moving left would not eventually make it fall, it tries to move 
/// right.
/// Since moving right would not eventually make it fall, it stays in place:
/// 
/// #       #
/// #   w   #
/// ##ww#w###
/// #########
///  0123456  
///
/// The final answer is [2,2,2,3,2,2,2]:
///
///    #    
/// ####### 
/// ####### 
///  0123456 
/// Example 2:
/// Input: heights = [1,2,3,4], V = 2, K = 2
/// Output: [2,3,3,4]
/// Explanation:
/// The last droplet settles at index 1, since moving further left would not 
/// cause it to eventually fall to a lower height.
/// Example 3:
/// Input: heights = [3,1,3], V = 5, K = 1
/// Output: [4,4,4]
/// Note:
///
/// heights will have length in [1, 100] and contain integers in [0, 99].
/// 1. V will be in range [0, 2000].
/// 2. K will be in range [0, heights.length - 1].
/// </summary>
vector<int> LeetCodeArray::pourWater(vector<int>& heights, int V, int K)
{
    vector<int> result = heights;
    for (size_t i = 0; i < (size_t)V; i++)
    {
        int index = K - 1;
        int low_index = K;
        while ((index >= 0) && (result[index] <= result[low_index]))
        {
            if (result[index] < result[low_index])
            {
                low_index = index;
            }
            index--;
        }
        if (low_index != K)
        {
            result[low_index]++;
            continue;
        }
        index = K + 1;
        low_index = K;
        while ((index < (int)result.size()) && (result[index] <= result[low_index]))
        {
            if (result[index] < result[low_index])
            {
                low_index = index;
            }
            index++;
        }
        if (low_index != K)
        {
            result[low_index]++;
            continue;
        }
        result[K]++;
    }
    return result;
}

/// <summary>
/// Leet code #904. Fruit Into Baskets
/// 
/// In a row of trees, the i-th tree produces fruit with type tree[i].
///
/// You start at any tree of your choice, then repeatedly perform the 
/// following steps:
///
/// 1. Add one piece of fruit from this tree to your baskets.  If you cannot, 
/// stop.
/// 2. Move to the next tree to the right of the current tree.  If there is no 
/// tree to the right, stop.
/// Note that you do not have any choice after the initial choice of starting 
/// tree: you must perform step 1, then step 2, then back to step 1, then 
/// step 2, and so on until you stop.
///
/// You have two baskets, and each basket can carry any quantity of fruit, but 
/// you want each basket to only carry one type of fruit each.
///
/// What is the total amount of fruit you can collect with this procedure?
///
/// Example 1:
/// Input: [1,2,1]
/// Output: 3
/// Explanation: We can collect [1,2,1].
///
/// Example 2:
/// Input: [0,1,2,2]
/// Output: 3
/// Explanation: We can collect [1,2,2].
/// If we started at the first tree, we would only collect [0, 1].
///
/// Example 3:
/// Input: [1,2,3,2,2]
/// Output: 4
/// Explanation: We can collect [2,3,2,2].
/// If we started at the first tree, we would only collect [1, 2].
///
/// Example 4:
/// Input: [3,3,3,1,2,1,1,2,3,3,4]
/// Output: 5
/// Explanation: We can collect [1,2,1,1,2].
/// If we started at the first tree or the eighth tree, we would only collect 
/// 4 fruits.
/// 
/// Note:
///
/// 1. 1 <= tree.length <= 40000
/// 2. 0 <= tree[i] < tree.length
/// </summary>
int LeetCodeArray::totalFruit(vector<int>& tree)
{
    int first = 0;
    int result = 0;
    unordered_map<int, int> hash_table;
    for (size_t i = 0; i < tree.size(); i++)
    {
        int last = i;
        hash_table[tree[last]]++;
        if (hash_table.size() <= 2)
        {
            result = max(result, last - first + 1);
        }
        else
        {
            while (hash_table.size() > 2)
            {
                hash_table[tree[first]]--;
                if (hash_table[tree[first]] == 0)
                {
                    hash_table.erase(tree[first]);
                }
                first++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #917. Reverse Only Letters
/// 
/// Given a string S, return the "reversed" string where all characters that 
/// are not a letter stay in the same place, and all letters reverse their 
/// positions.
///
/// Example 1:
///
/// Input: "ab-cd"
/// Output: "dc-ba"
/// Example 2:
///
/// Input: "a-bC-dEf-ghIj"
/// Output: "j-Ih-gfE-dCba"
///
/// Example 3:
/// Input: "Test1ng-Leet=code-Q!"
/// Output: "Qedo1ct-eeLg=ntse-T!"
///  
/// Note:
/// 
/// 1. S.length <= 100
/// 2. 33 <= S[i].ASCIIcode <= 122 
/// 3. S doesn't contain \ or "
/// </summary>
string LeetCodeArray::reverseOnlyLetters(string S)
{
    string result = S;
    int first = 0;
    int last = S.size() - 1;
    while (first < last)
    {
        if (isalpha(result[first]) && isalpha(result[last]))
        {
            swap(result[first], result[last]);
            first++;
            last--;
        }
        else if (!isalpha(result[first]))
        {
            first++;
        }
        else if (!isalpha(result[last]))
        {
            last--;
        }
    }
    return result;
}

/// <summary>
/// Leet code #915. Partition Array into Disjoint Intervals
/// 
/// Given an array A, partition it into two (contiguous) subarrays left and 
/// right so that:
///
/// Every element in left is less than or equal to every element in right.
/// left and right are non-empty.
/// left has the smallest possible size.
/// Return the length of left after such a partitioning.  It is guaranteed 
/// that such a partitioning exists.
///
/// 
/// Example 1:
///
/// Input: [5,0,3,8,6]
/// Output: 3
/// Explanation: left = [5,0,3], right = [8,6]
///
/// Example 2:
///
/// Input: [1,1,1,0,6,12]
/// Output: 4
/// Explanation: left = [1,1,1,0], right = [6,12]
/// 
///
/// Note:
///
/// 2 <= A.length <= 30000
/// 0 <= A[i] <= 10^6
/// It is guaranteed there is at least one way to partition A as described.
/// </summary>
int LeetCodeArray::partitionDisjoint(vector<int>& A)
{
    size_t first = 0;
    size_t second = first + 1;
    int max_left = A[first];
    int min_right = A[second];
    int max_right = A[second];
    while (second < A.size())
    {
        if (min_right >= max_left)
        {
            second++;
            if (second < A.size())
            {
                min_right = min(min_right, A[second]);
                max_right = max(max_right, A[second]);
            }
        }
        else
        {
            first = second;
            max_left = max(max_left, max_right);
            second++;
            if (second < A.size())
            {
                min_right = A[second];
                max_right = A[second];
            }
        }
    }
    return first + 1;
}

/// <summary>
/// Leet code #1156. Swap For Longest Repeated Character Substring
/// 
/// Given a string text, we are allowed to swap two of the characters in the 
/// string. Find the length of the longest substring with repeated characters.
/// 
/// Example 1:
/// Input: text = "ababa"
/// Output: 3
/// Explanation: We can swap the first 'b' with the last 'a', or the last 'b' 
/// with the first 'a'. Then, the longest repeated character substring is 
/// "aaa", which its length is 3.
///
/// Example 2:
/// Input: text = "aaabaaa"
/// Output: 6
/// Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get 
/// longest repeated character substring "aaaaaa", which its length is 6.
///
/// Example 3:
/// Input: text = "aaabbaaa"
/// Output: 4
///
/// Example 4:
/// Input: text = "aaaaa"
/// Output: 5
/// Explanation: No need to swap, longest repeated character substring is 
/// "aaaaa", length is 5.
///
/// Example 5:
/// Input: text = "abcdef"
/// Output: 1
/// 
/// Constraints:
/// 1. 1 <= text.length <= 20000
/// 2. text consist of lowercase English characters only.
/// </summary>
int LeetCodeArray::maxRepOpt1(string text)
{
    vector<int> count(26);
    vector<int> window(26);
    for (size_t i = 0; i < text.size(); i++)
    {
        count[text[i] - 'a']++;
    }
    int first = 0;
    int last = 0;
    int result = 0;
    window[text[0] - 'a']++;
    while (last < (int)text.size())
    {
        bool match = false;
        int length = last - first + 1;
        for (int i = 0; i < 26; i++)
        {
            if (window[i] == length)
            {
                match = true;
                result = max(result, length);
                break;
            }
            else if ((window[i] == length - 1) && (count[i] > window[i]))
            {
                match = true;
                result = max(result, length);
                break;
            }
        }
        if (match)
        {
            last++;
            if (last < (int)text.size()) window[text[last] - 'a']++;
        }
        else
        {
            window[text[first] - 'a']--;
            first++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1100. Find K-Length Substrings With No Repeated Characters
/// 
/// Given a string S, return the number of substrings of length K with no 
/// repeated characters.
/// 
/// Example 1:
/// Input: S = "havefunonleetcode", K = 5
/// Output: 6
/// Explanation: 
/// There are 6 substrings they are : 'havef','avefu','vefun','efuno',
/// 'etcod','tcode'.
///
/// Example 2:
/// Input: S = "home", K = 5
/// Output: 0
/// Explanation: 
/// Notice K can be larger than the length of S. In this case is not 
/// possible to find any substring.
/// 
/// Note:
/// 1 <= S.length <= 10^4
/// 2. All characters of S are lowercase English letters.
/// 3. 1 <= K <= 10^4
/// </summary>
int LeetCodeArray::numKLenSubstrNoRepeats(string S, int K)
{
    vector<int> substring(26);
    int first = 0;
    int last = 0;
    int result = 0;
    while (last < (int)S.size())
    {
        if (substring[S[last] - 'a'] == 1)
        {
            substring[S[first] - 'a'] = 0;
            first++;
        }
        else
        {
            substring[S[last] - 'a'] = 1;
            last++;
            if (last - first == K)
            {
                result++;
                substring[S[first] - 'a'] = 0;
                first++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1150. Check If a Number Is Majority Element in a Sorted Array
/// 
/// Given an array nums sorted in non-decreasing order, and a number target, 
/// return True if and only if target is a majority element.
/// A majority element is an element that appears more than N/2 times in an 
/// array of length N.
/// 
/// Example 1:
/// Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
/// Output: true
/// Explanation: 
/// The value 5 appears 5 times and the length of the array is 9.
/// Thus, 5 is a majority element because 5 > 9/2 is true.
///
/// Example 2:
/// Input: nums = [10,100,101,101], target = 101
/// Output: false
/// Explanation: 
/// The value 101 appears 2 times and the length of the array is 4.
/// Thus, 101 is not a majority element because 2 > 4/2 is false.
/// 
/// Note:
/// 1. 1 <= nums.length <= 1000
/// 2. 1 <= nums[i] <= 10^9
/// 3. 1 <= target <= 10^9
/// </summary>
bool LeetCodeArray::isMajorityElement(vector<int>& nums, int target)
{
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int last = first;

    while ((last < (int)nums.size()) && (nums[first] == nums[last])) last++;
    if ((last - first) > (int)nums.size() / 2) return true;
    else return false;
}

/// <summary>
/// Leet code #1180. Count Substrings with Only One Distinct Letter
/// 
/// Given a string S, return the number of substrings that have only one 
/// distinct letter.
/// 
/// Example 1:
/// Input: S = "aaaba"
/// Output: 8
/// Explanation: The substrings with one distinct letter are 
/// "aaa", "aa", "a", "b".
/// "aaa" occurs 1 time.
/// "aa" occurs 2 times.
/// "a" occurs 4 times.
/// "b" occurs 1 time.
/// So the answer is 1 + 2 + 4 + 1 = 8.
///
/// Example 2:
/// Input: S = "aaaaaaaaaa"
/// Output: 55
/// 
/// Constraints:
/// 1. 1 <= S.length <= 1000
/// 2. S[i] consists of only lowercase English letters.
/// </summary>
int LeetCodeArray::countLetters(string S)
{
    int first = 0;
    int result = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[first] != S[i]) first = i;
        result += i - first + 1;
    }
    return result;
}

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
int LeetCodeArray::removeDuplicateSortedArray(vector<int>& nums)
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
int LeetCodeArray::removeDuplicatesII(vector<int>& nums)
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
///
/// Given a m x n matrix, if an element is 0, set its entire row and column 
/// to 0. Do it in place. 
/// Did you use extra space?
/// A straight forward solution using O(mn) space is probably a bad idea.
/// A simple improvement uses O(m + n) space, but still not the best 
/// solution.
/// Could you devise a constant space solution? 
/// </summary>
void LeetCodeArray::setZeroes(vector<vector<int>>& matrix)
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
void LeetCodeArray::rotateArray(vector<int>& nums, int k)
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
/// Leet code #419. Battleships in a Board  
///
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
int LeetCodeArray::countBattleships(vector<vector<char>>& board)
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
/// Leet code #448. Find All Numbers Disappeared in an Array
///
/// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
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
vector<int> LeetCodeArray::findDisappearedNumbers(vector<int>& nums)
{
    vector<int> result;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) nums[index] = - nums[index];
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0) result.push_back(i + 1);
    }
    return result;
}

/// <summary>
/// Leet code #442. Find All Duplicates in an Array
///
/// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some 
/// elements appear twice and others appear once.
/// Find all the elements that appear twice in this array.
/// Could you do it without extra space and in O(n) runtime?
/// Example:
/// Input:
/// [4,3,2,7,8,2,3,1]
/// Output:
/// [2,3]
/// </summary>
vector<int> LeetCodeArray::findDuplicates(vector<int>& nums)
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
int LeetCodeArray::findRadius(vector<int>& houses, vector<int>& heaters)
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
int LeetCodeArray::countDepth(vector<NestedInteger>& nestedList)
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
int LeetCodeArray::depthSumInverse(vector<NestedInteger>& nestedList, int depth)
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
int LeetCodeArray::depthSumInverse(vector<NestedInteger>& nestedList)
{
    int depth = countDepth(nestedList);
    return depthSumInverse(nestedList, depth);
}

/// <summary>
/// Leet code #289. Game of Life 
///
/// According to the Wikipedia's article: "The Game of Life, also known 
/// simply as Life, is a cellular automaton devised by the British 
/// mathematician John Horton Conway in 1970." 
/// Given a board with m by n cells, each cell has an initial state 
/// live (1) or dead (0). 
/// Each cell interacts with its eight neighbors (horizontal, vertical, 
/// diagonal) using the 
/// following four rules (taken from the above Wikipedia article): 	
/// 1.Any live cell with fewer than two live neighbors dies, as if caused 
///   by under-population.
/// 2.Any live cell with two or three live neighbors lives on to the next 
///   generation.
/// 3.Any live cell with more than three live neighbors dies, as if by 
///   over-population..
/// 4.Any dead cell with exactly three live neighbors becomes a live cell, 
///   as if by reproduction.
/// Write a function to compute the next state (after one update) of the 
/// board given its current state.
/// Follow up: 
/// 1.Could you solve it in-place? Remember that the board needs to be 
///   updated at the same time: You cannot update some cells first and 
///   then use their updated values to update other cells.
/// 2.In this question, we represent the board using a 2D array. In 
///   principle, the board is infinite, which would cause problems when 
///   the active area encroaches the border of the array. How would you 
///   address these problems?
/// </summary>
void LeetCodeArray::gameOfLife(vector<vector<int>>& board)
{
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[i].size(); j++)
        {
            int count = 0;
            int next = 0;
            if (i > 0)
            {
                count += (board[i - 1][j]) % 10;
                if (j > 0) count += board[i - 1][j - 1] % 10;
                if (j < (int)board[i].size() - 1) count += board[i - 1][j + 1] % 10;
            }
            if (i < (int)board.size() - 1)
            {
                count += (board[i + 1][j]) % 10;
                if (j > 0) count += board[i + 1][j - 1] % 10;
                if (j < (int)board[i].size() - 1) count += board[i + 1][j + 1] % 10;
            }
            if (j > 0) count += board[i][j - 1] % 10;
            if (j < (int)board[i].size() - 1) count += board[i][j + 1] % 10;
            // 1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
            if ((count < 2) && (board[i][j] % 10 == 1))
            {
                next = 0;
            }
            // 2. Any live cell with two or three live neighbors lives on to the next generation.
            else if (((count == 2) || (count == 3)) && (board[i][j] % 10 == 1))
            {
                next = 1;
            }
            // 3. Any live cell with more than three live neighbors dies, as if by over-population.
            else if ((count > 3) && (board[i][j] % 10 == 1))
            {
                next = 0;
            }
            // 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
            else if ((count == 3) && (board[i][j] % 10 == 0))
            {
                next = 1;
            }
            board[i][j] = next * 10 + board[i][j];
        }
    }

    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            board[i][j] /= 10;
        }
    }
}

/// <summary>
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
int LeetCodeArray::shortestDistance(vector<string>& words, string word1, string word2)
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
/// This is a follow up of Shortest Word Distance. The only difference is 
/// now word1 could be the same as word2.
/// Given a list of words and two words word1 and word2, return the 
/// shortest distance between these two words in the list.
/// word1 and word2 may be the same and they represent two individual 
/// words in the list.
/// For example,
/// Assume that words = ["practice", "makes", "perfect", "coding", "makes"]. 
/// Given word1 = “makes”, word2 = “coding”, return 1.
/// Given word1 = "makes", word2 = "makes", return 3. 
/// Note:
/// You may assume word1 and word2 are both in the list. 
/// </summary>
int LeetCodeArray::shortestWordDistance(vector<string>& words, string word1, string word2)
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
vector<int> LeetCodeArray::getModifiedArray(int length, vector<vector<int>>& updates)
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
vector<vector<int>> LeetCodeArray::multiply(vector<vector<int>>& A, vector<vector<int>>& B)
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
        for (auto& itrA : matrixA[i])
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
vector<int> LeetCodeArray::findDiagonalOrder(vector<vector<int>>& matrix)
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
int LeetCodeArray::findLonelyPixel(vector<vector<char>>& picture)
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
int LeetCodeArray::findLonelyPixel(vector<vector<char>>& picture, int N)
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
int LeetCodeArray::findMinDifference(vector<string>& timePoints)
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
int LeetCodeArray::maxSumSubmatrix(vector<vector<int>>& matrix, int k)
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
bool LeetCodeArray::splitArray(vector<int>& nums)
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
vector<vector<int>> LeetCodeArray::matrixReshape(vector<vector<int>>& nums, int r, int c)
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
int LeetCodeArray::distributeCandies(vector<int>& candies)
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
int LeetCodeArray::arrayNesting(vector<int>& nums)
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
bool LeetCodeArray::canPlaceFlowers(vector<int>& flowerbed, int n)
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
int LeetCodeArray::maxDistance(vector<vector<int>>& arrays)
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
double LeetCodeArray::findMaxAverage(vector<int>& nums, int k)
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
double LeetCodeArray::density(vector<double>& sum, int l, int r)
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
double LeetCodeArray::findMaxAverageII(vector<int>& nums, int k)
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
vector<int> LeetCodeArray::findErrorNums(vector<int>& nums)
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
string LeetCodeArray::predictPartyVictory(string senate)
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
vector<vector<int>> LeetCodeArray::imageSmoother(vector<vector<int>>& M)
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
vector<int> LeetCodeArray::constructArray(int n, int k)
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
/// Leet code #238. Product of Array Except Self    
/// Given an array of n integers where n > 1, nums, return an array output such 
/// that output[i] is equal to the product of all the elements of nums except 
/// nums[i]. 
///
/// Solve it without division and in O(n). 
/// For example, given [1,2,3,4], return [24,12,8,6]. 
/// 
/// Follow up:
/// Could you solve it with constant space complexity? 
/// (Note: The output array does not count as extra space for the purpose of 
/// space complexity analysis.)
/// </summary>
vector<int> LeetCodeArray::productExceptSelf(vector<int>& nums)
{
    vector<int> result(nums.size());
    int product = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        result[i] = product;
        product = product * nums[i];
    }
    product = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        result[i] = result[i] * product;
        product *= nums[i];
    }
    return result;
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
int LeetCodeArray::calPoints(vector<string>& ops)
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
bool LeetCodeArray::isPossible(vector<int>& nums)
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
int LeetCodeArray::countBinarySubstrings(string s)
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
int LeetCodeArray::findShortestSubArray(vector<int>& nums)
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
bool LeetCodeArray::isOneBitCharacter(vector<int>& bits)
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
void LeetCodeArray::countCandy(vector<vector<int>>& board, vector<vector<pair<int, int>>>& match)
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
bool LeetCodeArray::removeCandy(vector<vector<int>>& board, vector<vector<pair<int, int>>>& match)
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
void LeetCodeArray::dropCandy(vector<vector<int>>& board)
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
vector<vector<int>> LeetCodeArray::candyCrush(vector<vector<int>>& board)
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
int LeetCodeArray::pivotIndex(vector<int>& nums)
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
int LeetCodeArray::countCornerRectangles(vector<vector<int>>& grid)
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
int LeetCodeArray::dominantIndex(vector<int>& nums)
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
bool LeetCodeArray::isToeplitzMatrix(vector<vector<int>>& matrix)
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
int LeetCodeArray::kthGrammar(int N, int K)
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
int LeetCodeArray::maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
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
vector<int> LeetCodeArray::shortestToChar(string S, char C)
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
int LeetCodeArray::flipgame(vector<int>& fronts, vector<int>& backs)
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
vector<vector<int>> LeetCodeArray::flipAndInvertImage(vector<vector<int>>& A)
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
int LeetCodeArray::largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
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
string LeetCodeArray::pushDominoes(string dominoes)
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
int LeetCodeArray::numMagicSquaresInside(vector<vector<int>>& grid)
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
int LeetCodeArray::longestMountain(vector<int>& A)
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
int LeetCodeArray::maxDistToClosest(vector<int>& seats)
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
bool LeetCodeArray::lemonadeChange(vector<int>& bills)
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
int LeetCodeArray::shortestSubarray(vector<int>& A, int K)
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
vector<vector<int>> LeetCodeArray::transpose(vector<vector<int>>& A)
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
int LeetCodeArray::robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
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
int LeetCodeArray::projectionArea(vector<vector<int>>& grid)
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
bool LeetCodeArray::circularArrayLoop(vector<int>& nums)
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
vector<vector<int>> LeetCodeArray::spiralMatrixIII(int R, int C, int r0, int c0)
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
vector<int> LeetCodeArray::fairCandySwap(vector<int>& A, vector<int>& B)
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
int LeetCodeArray::surfaceArea(vector<vector<int>>& grid)
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
bool LeetCodeArray::isMonotonic(vector<int>& A)
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
vector<int> LeetCodeArray::sortArrayByParity(vector<int>& A)
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
vector<int> LeetCodeArray::sortArrayByParityII(vector<int>& A)
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
int LeetCodeArray::maxSubarraySumCircular(vector<int>& A)
{
    int sum = 0;
    int min_left = 0;
    int max_left = 0;
    int max_sum = INT_MIN;
    int min_sum = INT_MAX;
    for (size_t i = 0; i < A.size(); i++)
    {
        sum += A[i];
        max_sum = max(max_sum, sum - min_left);
        min_sum = min(min_sum, sum - max_left);
        min_left = min(min_left, sum);
        max_left = max(max_left, sum);
    }
    int result = max_sum;
    if (sum != min_sum) result = max(result, sum-min_sum);
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
int LeetCodeArray::minFlipsMonoIncr(string S)
{
    int zero = 0;
    int one = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == '0') zero++;
        else one++;
    }
    int first = 0;
    int last = S.size() - 1;
    int result = 0;
    while (first < last)
    {
        if (S[first] == '0')
        {
            zero--;
            first++;
        }
        else if (S[last] == '1')
        {
            one--;
            last--;
        }
        else
        {
            result++;
            if (zero < one)
            {
                zero--;
                last--;
            }
            else
            {
                one--;
                first++;
            }
        };
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
vector<int> LeetCodeArray::threeEqualParts(vector<int>& A)
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
int LeetCodeArray::minDeletionSize(vector<string>& A)
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
int LeetCodeArray::minIncrementForUnique(vector<int>& A)
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
vector<int> LeetCodeArray::deckRevealedIncreasing(vector<int>& deck)
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
int LeetCodeArray::repeatedNTimes(vector<int>& A)
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
vector<int> LeetCodeArray::sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries)
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
vector<int> LeetCodeArray::addToArrayForm(vector<int>& A, int K)
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
int LeetCodeArray::subarraysWithKDistinct(vector<int>& A, int K)
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
int LeetCodeArray::minKBitFlips(vector<int>& A, int K)
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
vector<int> LeetCodeArray::gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries)
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
int LeetCodeArray::numRookCaptures(vector<vector<char>>& board)
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
int LeetCodeArray::longestOnes(vector<int>& A, int K)
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
int LeetCodeArray::largestSumAfterKNegations(vector<int>& A, int K)
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
int LeetCodeArray::minDominoRotations(vector<int>& A, vector<int>& B)
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
bool LeetCodeArray::canThreePartsEqualSum(vector<int>& A)
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
        else if ((sum == first * 2) && (result == 1) && (i != A.size() - 1))
        {
            result++;
            break;
        }
    }
    if (result == 2) return true;
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
int LeetCodeArray::maxScoreSightseeingPair(vector<int>& A)
{
    int i = 0; 
    int j = 1;
    int result = A[i] + A[j] + i - j;
    for (int k = j + 1; k < (int)A.size(); k++)
    {
        int sum0 = A[i] + A[j] + i - j;
        int sum1 = A[j] + A[k] + j - k;
        int sum2 = A[i] + A[k] + i - k;
        result = max(result, sum1);
        result = max(result, sum2);
        if (A[i] + i -j < A[j])
        {
            i = j;
            j = k;
        }
        else if (A[j] + j - k < A[k])
        {
            j = k;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1036. Escape a Large Maze
/// 
/// In a 1 million by 1 million grid, the coordinates of each grid square
/// are (x, y) with 0 <= x, y < 10^6.
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
/// The target square is inaccessible starting from the source square, 
/// because we can't walk outside the grid.
///
/// Example 2:
///
/// Input: blocked = [], source = [0,0], target = [999999,999999]
/// Output: true
/// Explanation: 
/// Because there are no blocked cells, it's possible to reach the target 
/// square.
/// 
/// Note:
/// 1. 0 <= blocked.length <= 200
/// 2. blocked[i].length == 2
/// 3. 0 <= blocked[i][j] < 10^6
/// 4. source.length == target.length == 2
/// 5. 0 <= source[i][j], target[i][j] < 10^6
/// 6. source != target
/// </summary>
bool LeetCodeArray::isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)
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
int LeetCodeArray::maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
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
int LeetCodeArray::numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
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
void LeetCodeArray::duplicateZeros(vector<int>& arr)
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
int LeetCodeArray::longestWPI(vector<int>& hours)
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
bool LeetCodeArray::canDivideIntoSubsequences(vector<int>& nums, int K)
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
    // the minimum length of the increasing sequence is determined by 
    // maxium duplication
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
string LeetCodeArray::alphabetBoardPath(string target)
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
int LeetCodeArray::dietPlanPerformance(vector<int>& calories, int k, int lower, int upper)
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
int LeetCodeArray::maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes)
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
int LeetCodeArray::distanceBetweenBusStops(vector<int>& distance, int start, int destination)
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
int LeetCodeArray::maximumSum(vector<int>& arr)
{
    vector<int> dp1(arr.size()), dp2(arr.size());
    for (size_t i = 0; i < arr.size(); i++)
    {
        dp1[i] = arr[i];
        if (i > 0) dp1[i] = max(dp1[i-1] + arr[i], dp1[i]);
    }
    for (int i = arr.size() - 1; i >=0; i--)
    {
        dp2[i] = arr[i];
        if (i < (int)arr.size() - 1) dp2[i] = max(dp2[i + 1] + arr[i], dp2[i]);
    }
    int result = INT_MIN;
    for (size_t i = 0; i < arr.size(); i++)
    {
        result = max(result, dp1[i]);
        if (i > 0 && i < arr.size() - 1)
        {
            result = max(result, dp1[i - 1] + dp2[i + 1]);
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
int LeetCodeArray::kConcatenationMaxSum(vector<int>& arr, int k)
{
    int M = 1000000007;
    // use 64 bits so we do not worry about overflow
    long long sum = 0;
    long long min_sum = 0;
    long long result = 0;
    int n = arr.size();
    for (size_t i = 0; i < min(k, 2) * arr.size(); i++)
    {
        sum += arr[i % n];
        result = max(result, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    if (sum > 0 && k > 2)
    {
        result += (sum / 2) * ((long long)k - 2);
    }
    result = result % M;
    return (int)result;
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
vector<vector<int>> LeetCodeArray::minimumAbsDifference(vector<int>& arr)
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
/// Leet code #891. Sum of Subsequence Widths
/// 
/// Given an array of integers A, consider all non-empty subsequences of A.
///
/// For any sequence S, let the width of S be the difference between the 
/// maximum and minimum element of S.
///
/// Return the sum of the widths of all subsequences of A. 
///
/// As the answer may be very large, return the answer modulo 10^9 + 7.
///
/// Example 1:
///
/// Input: [2,1,3]
/// Output: 6
/// Explanation:
/// Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
/// The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
/// The sum of these widths is 6.
///
/// Note:
///
/// 1 <= A.length <= 20000
/// 1 <= A[i] <= 20000
/// </summary>
int LeetCodeArray::sumSubseqWidths(vector<int>& A)
{
    int M = 1000000007;
    vector<int> nums = A;
    int result = 0;
    vector<int> factor(A.size());
    for (size_t i = 0; i < A.size(); i++)
    {
        if (i == 0) factor[i] = 1;
        else  factor[i] = (factor[i - 1] << 1) % M;
    }
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++)
    {
        result = (result + ((long long)factor[i] - (long long)1) * nums[i]) % M;
        result = (result - ((long long)factor[A.size() - (long long)1 - (long long)i] - 1) * nums[i]) % M;
        result = (result + M) % M;
    }
    return result;
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
bool LeetCodeArray::isValidSudoku(vector<vector<char>>& board)
{
    size_t size = board.size();
    size_t square_size = (size_t)sqrt((double)size);
    vector<unordered_set<int>> row_map = vector<unordered_set<int>>(size);
    vector<unordered_set<int>> col_map = vector<unordered_set<int>>(size);
    vector<unordered_set<int>> square_map = vector<unordered_set<int>>(size);
    // first scan, set up the flag in the memory map, which will help us to immediately identify 
    // the bad candidate in the cell.
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            size_t pos = i * size + j;
            char value = board[i][j];
            if (board[i][j] != '.')
            {
                int s = (i / square_size) * square_size + (j / square_size);
                if (row_map[i].find(value) == row_map[i].end())
                {
                    row_map[i].insert(value);
                }
                else
                {
                    return false;
                }
                if (col_map[j].find(value) == col_map[j].end())
                {
                    col_map[j].insert(value);
                }
                else
                {
                    return false;
                }
                if (square_map[s].find(value) == square_map[s].end())
                {
                    square_map[s].insert(value);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}


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
vector<int> LeetCodeArray::xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
    vector<int> sum(arr.size());

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (i == 0) sum[i] = arr[i];
        else sum[i] = sum[i - 1] ^ arr[i];
    }

    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        if (queries[i][0] == 0) result[i] = sum[queries[i][1]];
        else result[i] = sum[queries[i][1]] ^ sum[queries[i][0]-1];
    }
    return result;
}

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
vector<int> LeetCodeArray::decompressRLElist(vector<int>& nums)
{
    vector<int> result;

    for (size_t i = 0; i < nums.size(); i += 2)
    {
        for (int j = 0; j < nums[i]; j++)
        {
            result.push_back(nums[i + 1]);
        }
    }
    return result;
}

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
vector<vector<int>> LeetCodeArray::matrixBlockSum(vector<vector<int>>& mat, int K)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<pair<int, int>>> sum(m, vector<pair<int, int>>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j].first = mat[i][j];
            if (j > 0) sum[i][j].first += sum[i][j - 1].first;
            sum[i][j].second = sum[i][j].first;
            if (i > 0) sum[i][j].second += sum[i - 1][j].second;
        }
    }

    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int y0 = max(0, i - K);
            int x0 = max(0, j - K);
            int y1 = min(i + K, m - 1);
            int x1 = min(j + K, n - 1);

            result[i][j] = sum[y1][x1].second;
            if (y0 > 0) result[i][j] -= sum[y0 - 1][x1].second;
            if (x0 > 0) result[i][j] -= sum[y1][x0-1].second;
            if (y0 > 0 && x0 > 0)result[i][j] += sum[y0-1][x0 - 1].second;
        }
    }
    return result;
}

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
int LeetCodeArray::numberOfArithmeticSlices(vector<int>& A)
{
    vector<int> sum_count(A.size());
    int count = 0;
    int diff;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (i == 0) continue;
        else if (i == 1)
        {
            diff = A[i] - A[i - 1];
        }
        else if (A[i] - A[i - 1] == diff)
        {
            count++;
        }
        else
        {
            count = 0;
            diff = A[i] - A[i - 1];
        }
        sum_count[i] = count;
    }
    int sum = 0;
    for (size_t i = 0; i < sum_count.size(); i++)
    {
        sum += sum_count[i];
    }
    return sum;
}


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
int LeetCodeArray::findMaxConsecutiveOnes(vector<int>& nums)
{
    int max_ones = 0;
    int count_ones = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0) count_ones = 0;
        else
        {
            count_ones++;
            max_ones = max(max_ones, count_ones);
        }
    }
    return max_ones;
}

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
/// (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.
///
/// A subsequence slice (P0, P1, ..., Pk) of array A is called 
/// arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] 
/// is arithmetic. In particular, this means that k ≥ 2.
/// 
/// The function should return the number of arithmetic subsequence 
/// slices in the array A. 
///
/// The input contains N integers. Every integer is in the range of -2^31 
/// and 2^31-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 
/// 2^31-1.
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
int LeetCodeArray::numberOfArithmeticSlicesII(vector<int>& A)
{
    int result = 0;
    vector<unordered_map<long long, int>> dp(A.size());
    for (int i = 0; i < (int)A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            long long diff = (long long)A[i] - (long long)A[j];
            if (dp[j].count(diff) > 0)
            {
                dp[i][diff] += dp[j][diff];
                result += dp[j][diff];
            }
            dp[i][diff]++;
        }
    }
    return result;
}

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
vector<int> LeetCodeArray::largestDivisibleSubset(vector<int>& nums)
{
    vector<int> result;
    vector<vector<int>> set_map(nums.size());
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if ((nums[i] % nums[j]) == 0)
            {
                if (set_map[i].size() < set_map[j].size())
                {
                    set_map[i] = set_map[j];
                }
            }
        }
        set_map[i].push_back(nums[i]);
        if (set_map[i].size() > result.size()) result = set_map[i];
    }
    return result;
}


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
int LeetCodeArray::maxValueAfterReverse(vector<int>& nums)
{
    int sum = 0;
    int min_max = INT_MAX;
    int max_min = INT_MIN;
    int gap_begin = 0;
    int gap_end = 0;

    for (size_t i = 1; i < nums.size(); i++)
    {
        sum += abs(nums[i - 1] - nums[i]);
        min_max = min(min_max, max(nums[i - 1], nums[i]));
        max_min = max(max_min, min(nums[i - 1], nums[i]));
        
        gap_begin = max(gap_begin, std::abs(nums[0] - nums[i]) - std::abs(nums[i - 1] - nums[i]));
        gap_end = max(gap_end, std::abs(nums[i-1] - nums[nums.size() - 1]) - std::abs(nums[i - 1] - nums[i]));
    }
    int result = sum + 2 * (max_min - min_max);
    result = max(result, sum + gap_begin);
    result = max(result, sum + gap_end);

    return result;
}

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
vector<vector<int>> LeetCodeArray::diagonalSort(vector<vector<int>>& mat)
{
    vector<vector<int>> result(mat.size(), vector<int>(mat[0].size()));
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < n; j++)
            {
                int r = i;
                int c = j;
                vector<int> temp;
                while (r < m && c < n)
                {
                    temp.push_back(mat[r][c]);
                    r++;
                    c++;
                }
                sort(temp.begin(), temp.end());
                r = i;
                c = j;
                int index = 0;
                while (r < m && c < n)
                {
                    result[r][c] = temp[index];
                    r++;
                    c++;
                    index++;
                }
            }
        }
        else
        {
            int r = i;
            int c = 0;
            vector<int> temp;
            while (r < m && c < n)
            {
                temp.push_back(mat[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(), temp.end());
            r = i;
            c = 0;
            int index = 0;
            while (r < m && c < n)
            {
                result[r][c] = temp[index];
                r++;
                c++;
                index++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1333. Filter Restaurants by Vegan-Friendly, Price and Distance
/// 
/// Medium
///
/// Given the array restaurants where  restaurants[i] = [idi, ratingi, 
/// veganFriendlyi, pricei, distancei]. You have to filter the restaurants 
/// using three filters.
///
/// The veganFriendly filter will be either true (meaning you should only 
/// include restaurants with veganFriendlyi set to true) or false (meaning 
/// you can include any restaurant). In addition, you have the filters 
/// maxPrice and maxDistance which are the maximum value for price and 
/// distance of restaurants you should consider respectively.
///
/// Return the array of restaurant IDs after filtering, ordered by rating 
/// from highest to lowest. For restaurants with the same rating, order 
/// them by id from highest to lowest. For simplicity veganFriendlyi and 
/// veganFriendly take value 1 when it is true, and 0 when it is false.
///
/// Example 1:
/// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
/// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, 
/// maxDistance = 10
/// Output: [3,1,5] 
/// Explanation: 
/// The restaurants are:
/// Restaurant 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
/// Restaurant 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
/// Restaurant 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
/// Restaurant 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
/// Restaurant 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
/// After filter restaurants with veganFriendly = 1, maxPrice = 50 and 
/// maxDistance = 10 we have restaurant 3, restaurant 1 and restaurant 5 
/// (ordered by rating from highest to lowest).
///	
/// Example 2:
/// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
/// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, 
/// maxDistance = 10
/// Output: [4,3,2,1,5]
/// Explanation: The restaurants are the same as in example 1, but in 
/// this case the filter veganFriendly = 0, therefore all restaurants are
/// considered.
///
/// Example 3:
/// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
/// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, 
/// maxDistance = 3
/// Output: [4,5]
///
/// Constraints:
/// 1. 1 <= restaurants.length <= 10^4
/// 2. restaurants[i].length == 5
/// 3. 1 <= id[i], ratingi, pricei, distancei <= 10^5
/// 4. 1 <= maxPrice, maxDistance <= 10^5
/// 5. veganFriendlyi and veganFriendly are 0 or 1.
/// 6. All id[i] are distinct.
/// </summary>
vector<int> LeetCodeArray::filterRestaurants(vector<vector<int>>& restaurants,
    int veganFriendly, int maxPrice, int maxDistance)
{
    priority_queue<pair<int, int>> pq;
    for (size_t i = 0; i < restaurants.size(); i++)
    {
        if (restaurants[i][3] > maxPrice) continue;
        if (restaurants[i][4] > maxDistance) continue;
        if (restaurants[i][2] == 0 && veganFriendly  == 1) continue;
        pq.push({ restaurants[i][1], restaurants[i][0] });
    }
    vector<int> result;
    while (!pq.empty())
    {
        pair<int, int> r = pq.top();
        pq.pop();
        result.push_back(r.second);
    }
    return result;
}

/// <summary>
/// Leet code #1337. The K Weakest Rows in a Matrix 
/// 
/// Easy
///
/// Given a m * n matrix mat of ones (representing soldiers) and zeros 
/// (representing civilians), return the indexes of the k weakest rows 
/// in the matrix ordered from the weakest to the strongest.
/// 
/// A row i is weaker than row j, if the number of soldiers in row i is 
/// less than the number of soldiers in row j, or they have the same 
/// number of soldiers but i is less than j. Soldiers are always stand 
/// in the frontier of a row, that is, always ones may appear first and 
/// then zeros.
/// 
/// Example 1:
///
/// Input: mat = 
/// [[1,1,0,0,0],
///  [1,1,1,1,0],
///  [1,0,0,0,0],
///  [1,1,0,0,0],
///  [1,1,1,1,1]], 
/// k = 3
/// Output: [2,0,3]
/// Explanation: 
/// The number of soldiers for each row is: 
/// row 0 -> 2 
/// row 1 -> 4 
/// row 2 -> 1 
/// row 3 -> 2 
/// row 4 -> 5 
/// Rows ordered from the weakest to the strongest are [2,0,3,1,4]
/// 
/// Example 2:
///
/// Input: mat = 
/// [[1,0,0,0],
///  [1,1,1,1],
///  [1,0,0,0],
///  [1,0,0,0]], 
/// k = 2
/// Output: [0,2]
/// Explanation: 
/// The number of soldiers for each row is: 
/// row 0 -> 1 
/// row 1 -> 4 
/// row 2 -> 1 
/// row 3 -> 1 
/// Rows ordered from the weakest to the strongest are [0,2,3,1]
/// 
/// Constraints:
/// 1. m == mat.length
/// 2. n == mat[i].length
/// 3. 2 <= n, m <= 100
/// 4. 1 <= k <= m
/// 5. matrix[i][j] is either 0 or 1.
/// </summary>
vector<int> LeetCodeArray::kWeakestRows(vector<vector<int>>& mat, int k)
{
    set<pair<int, int>> pq;
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0) break;
            count++;
        }
        pq.insert(make_pair(count, i));
    }
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        result.push_back(pq.begin()->second);
        pq.erase(pq.begin());
    }
    return result;
}

/// <summary>
/// Leet code #1338. Reduce Array Size to The Half 
/// 
/// Medium
///
/// Given an array arr.  You can choose a set of integers and remove all 
/// the occurrences of these integers in the array.
///
/// Return the minimum size of the set so that at least half of the 
/// integers of the array are removed.
///  
/// Example 1:
///
/// Input: arr = [3,3,3,3,5,5,5,2,2,7]
/// Output: 2
/// Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which 
/// has size 5 (i.e equal to half of the size of the old array).
/// Possible sets of size 2 are {3,5},{3,2},{5,2}.
/// Choosing set {2,7} is not possible as it will make the new 
/// array [3,3,3,3,5,5,5] which has size greater than half of the size of 
/// the old array.
///
/// Example 2:
///
/// Input: arr = [7,7,7,7,7,7]
/// Output: 1
/// Explanation: The only possible set you can choose is {7}. This will make 
/// the new array empty.
///
/// Example 3:
///
/// Input: arr = [1,9]
/// Output: 1
///
/// Example 4:
///
/// Input: arr = [1000,1000,3,7]
/// Output: 1
///
/// Example 5:
///
/// Input: arr = [1,2,3,4,5,6,7,8,9,10]
/// Output: 5
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. arr.length is even.
/// 3. 1 <= arr[i] <= 10^5
/// </summary>
int LeetCodeArray::minSetSize(vector<int>& arr)
{
    unordered_map<int, int> num_count;
    for (size_t i = 0; i < arr.size(); i++)
    {
        num_count[arr[i]]++;
    }

    priority_queue<int> pq;
    for (auto itr = num_count.begin(); itr != num_count.end(); ++itr)
    {
        pq.push(itr->second);
    }
    int result = 0;
    int sum = 0;
    while (!pq.empty())
    {
        int num = pq.top();
        pq.pop();
        sum += num;
        result++;
        if (sum >= ((int)arr.size() / 2))
        {
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1343. Number of Sub-arrays of Size K and Average Greater 
/// than or Equal to Threshold
///
/// Medium
///
/// Given an array of integers arr and two integers k and threshold.
///
/// Return the number of sub-arrays of size k and average greater than 
/// or equal to threshold.
///
/// Example 1:
/// Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
/// Output: 3
/// Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have 
/// averages 4, 5 and 6 respectively. All other sub-arrays of size 3 
/// have averages less than 4 (the threshold).
///
/// Example 2:
/// Input: arr = [1,1,1,1,1], k = 1, threshold = 0
/// Output: 5
///
/// Example 3:
/// Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
/// Output: 6
/// Explanation: The first 6 sub-arrays of size 3 have averages greater 
/// than 5. Note that averages are not integers.
///
/// Example 4:
/// Input: arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
/// Output: 1
///
/// Example 5:
/// Input: arr = [4,4,4,4], k = 4, threshold = 1
/// Output: 1
///
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 1 <= arr[i] <= 10^4
/// 3. 1 <= k <= arr.length
/// 4. 0 <= threshold <= 10^4
/// </summary>
int LeetCodeArray::numOfSubarrays(vector<int>& arr, int k, int threshold)
{
    deque<int> sum;
    sum.push_back(0);
    int result = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        sum.push_back(sum.back() + arr[i]);
        if (sum.size() == k + 1)
        {
            if ((sum.back() - sum.front()) >= k * threshold)
            {
                result++;
            }
            sum.pop_front();
        }
    }
    return result;
}

/// <summary>
/// Leet code #1346. Check If N and Its Double Exist
///
/// Easy
///
/// Given an array arr of integers, check if there exists two integers 
/// N and M such that N is the double of M ( i.e. N = 2 * M).
///
/// More formally check if there exists two indices i and j such that :
///  
/// i != j
/// 0 <= i, j < arr.length
/// arr[i] == 2 * arr[j]
/// 
/// Example 1:
/// Input: arr = [10,2,5,3]
/// Output: true
/// Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
///
/// Example 2:
/// Input: arr = [7,1,14,11]
/// Output: true
/// Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
///
/// Example 3:
/// Input: arr = [3,1,7,11]
/// Output: false
/// Explanation: In this case does not exist N and M, such that N = 2 * M.
///
/// Constraints:
/// 1. 2 <= arr.length <= 500
/// 2. -10^3 <= arr[i] <= 10^3
/// </summary>
bool LeetCodeArray::checkIfExist(vector<int>& arr)
{
    unordered_set<int> num_set;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (((num_set.count(arr[i] / 2) > 0) && (arr[i] % 2 == 0)) || (num_set.count(arr[i] * 2) > 0))
        {
            return true;
        }
        num_set.insert(arr[i]);
    }
    return false;
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
int LeetCodeArray::minSwaps(vector<int>& data)
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
/// Leet code #1351. Count Negative Numbers in a Sorted Matrix
///
/// Easy
///
/// Given a m * n matrix grid which is sorted in non-increasing order 
/// both row-wise and column-wise. 
///
/// Return the number of negative numbers in grid.
///
/// Example 1:
/// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
/// Output: 8
/// Explanation: There are 8 negatives number in the matrix.
///
/// Example 2:
/// Input: grid = [[3,2],[1,0]]
/// Output: 0
///
/// Example 3:
/// Input: grid = [[1,-1],[-1,-1]]
/// Output: 3
///
/// Example 4:
/// Input: grid = [[-1]]
/// Output: 1
/// 
///
/// Constraints:
///
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 100
/// 4. -100 <= grid[i][j] <= 100
/// </summary>
int LeetCodeArray::countNegatives(vector<vector<int>>& grid)
{
    int row = 0;
    int col = grid[0].size() - 1;
    int result = 0;
    while (row < (int)grid.size() && col >= 0)
    {
        if (grid[row][col] < 0)
        {
            result += grid.size() - row;
            col--;
        }
        else
        {
            row++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1380. Lucky Numbers in a Matrix
///
/// Easy
///
/// Given a m * n matrix of distinct numbers, return all lucky numbers 
/// in the matrix in any order.
/// A lucky number is an element of the matrix such that it is the 
/// minimum element in its row and maximum in its column.
///
/// Example 1:
/// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
/// Output: [15]
/// Explanation: 15 is the only lucky number since it is the minimum 
/// in its row and the maximum in its column
///
/// Example 2:
/// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
/// Output: [12]
/// Explanation: 12 is the only lucky number since it is the minimum in 
/// its row and the maximum in its column.
///
/// Example 3:
/// Input: matrix = [[7,8],[1,2]]
/// Output: [7]
///
/// Constraints:
/// 1. m == mat.length
/// 2. n == mat[i].length
/// 3. 1 <= n, m <= 50
/// 4. 1 <= matrix[i][j] <= 10^5.
/// 5. All elements in the matrix are distinct.
/// </summary>
vector<int> LeetCodeArray::luckyNumbers(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, INT_MAX), col(n, INT_MIN);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            row[i] = min(row[i], matrix[i][j]);
            col[j] = max(col[j], matrix[i][j]);
        }
    }
    vector<int> result;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == row[i] && matrix[i][j] == col[j])
            result.push_back(matrix[i][j]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1389. Create Target Array in the Given Order
/// 
/// Easy
///
/// Given two arrays of integers nums and index. Your task is to create 
/// target array under the following rules:
///
/// Initially target array is empty.
/// From left to right read nums[i] and index[i], insert at index index[i] 
/// the value nums[i] in target array.
/// Repeat the previous step until there are no elements to read in nums 
/// and index.
/// Return the target array.
///
/// It is guaranteed that the insertion operations will be valid.
///
/// Example 1:
/// Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
/// Output: [0,4,1,3,2]
/// Explanation:
/// nums       index     target
/// 0            0        [0]
/// 1            1        [0,1]
/// 2            2        [0,1,2] 
/// 3            2        [0,1,3,2]
/// 4            1        [0,4,1,3,2]
///
/// Example 2:
/// Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
/// Output: [0,1,2,3,4]
/// Explanation:
/// nums       index     target
/// 1            0        [1]
/// 2            1        [1,2]
/// 3            2        [1,2,3]
/// 4            3        [1,2,3,4]
/// 0            0        [0,1,2,3,4]
///
/// Example 3:
/// Input: nums = [1], index = [0]
/// Output: [1]
/// 
/// Constraints:
/// 1. 1 <= nums.length, index.length <= 100
/// 2. nums.length == index.length
/// 3. 0 <= nums[i] <= 100
/// 4. 0 <= index[i] <= i
/// </summary>
vector<int> LeetCodeArray::createTargetArray(vector<int>& nums, vector<int>& index)
{
    int n = nums.size();
    vector<int> result(nums.size(), -1);
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (j = index[i]; j < n; j++)
        {
            if (result[j] == -1) break;
        }
        for (int k = j; k > index[i]; k--) result[k] = result[k - 1];
        result[index[i]] = nums[i];
    }
    return result;
}

/// <summary>
/// Leet code #1395. Count Number of Teams
/// 
/// Medium
///
/// There are n soldiers standing in a line. Each soldier is assigned a 
/// unique rating value.
///
/// You have to form a team of 3 soldiers amongst them under the following
/// rules:
///
/// Choose 3 soldiers with index (i, j, k) with rating (rating[i], 
/// rating[j], rating[k]).
/// A team is valid if:  (rating[i] < rating[j] < rating[k]) or 
/// (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
/// Return the number of teams you can form given the conditions. 
/// (soldiers can be part of multiple teams).
/// 
/// Example 1:
/// Input: rating = [2,5,3,4,1]
/// Output: 3
/// Explanation: We can form three teams given the conditions. 
/// (2,3,4), (5,4,1), (5,3,1). 
///
/// Example 2:
/// Input: rating = [2,1,3]
/// Output: 0
/// Explanation: We can't form any team given the conditions.
///
/// Example 3:
/// Input: rating = [1,2,3,4]
/// Output: 4
///
/// Constraints:
/// 1. n == rating.length
/// 2. 1 <= n <= 200
/// 3. 1 <= rating[i] <= 10^5
/// </summary>
int LeetCodeArray::numTeams(vector<int>& rating)
{
    vector<int> low(rating.size());
    vector<int> high(rating.size());
    int result = 0;
    for (size_t i = 0; i < rating.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (rating[j] < rating[i])
            {
                low[i]++;
                result += low[j];
            }
            else  if (rating[j] > rating[i])
            {
                high[i]++;
                result += high[j];
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1409. Queries on a Permutation With Key 
/// 
/// Medium
///
/// Given the array queries of positive integers between 1 and m, 
/// you have to process all queries[i] (from i=0 to 
/// i=queries.length-1) according to the following rules:
///
/// In the beginning, you have the permutation P=[1,2,3,...,m].
/// For the current i, find the position of queries[i] in the 
/// permutation P (indexing from 0) and then move this at the 
/// beginning of the permutation P. Notice that the position of 
/// queries[i] in P is the result for queries[i].
/// Return an array containing the result for the given queries.
/// 
/// Example 1:
/// Input: queries = [3,1,2,1], m = 5
/// Output: [2,1,2,1] 
/// Explanation: The queries are processed as follow: 
/// For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, 
/// then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
/// For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, 
/// then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
/// For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, 
/// then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
/// For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, 
/// then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
/// Therefore, the array containing the result is [2,1,2,1].  
///
/// Example 2:
/// Input: queries = [4,1,2,2], m = 4
/// Output: [3,1,2,0]
///
/// Example 3:
/// Input: queries = [7,5,5,8,3], m = 8
/// Output: [6,5,0,7,5]
///
/// Constraints:
/// 1. 1 <= m <= 10^3
/// 2. 1 <= queries.length <= m
/// 3. 1 <= queries[i] <= m
/// </summary>
vector<int> LeetCodeArray::processQueries(vector<int>& queries, int m)
{
    vector<int> permutation(m);
    vector<int> position(m);
    vector<int> result;
    for (int i = 0; i < m; i++)
    {
        permutation[i] = i + 1;
        position[i] = i;
    }

    for (size_t i = 0; i < queries.size(); i++)
    {
        int pos = position[queries[i] - 1];

        for (int j = pos - 1; j >= 0; j--)
        {
            permutation[j + 1] = permutation[j];
            position[permutation[j] - 1]++;
        }
        permutation[0] = queries[i];
        position[queries[i] - 1] = 0;
        result.push_back(pos);
    }
    return result;
}

/// <summary>
/// Leet code #1413. Minimum Value to Get Positive Step by Step Sum 
/// 
/// Easy
///
/// Given an array of integers nums, you start with an initial positive 
/// value startValue.
///
/// In each iteration, you calculate the step by step sum of startValue 
/// plus elements in nums (from left to right).
///
/// Return the minimum positive value of startValue such that the step by 
/// step sum is never less than 1.
///
/// Example 1:
/// Input: nums = [-3,2,-3,4,2]
/// Output: 5
/// Explanation: If you choose startValue = 4, in the third iteration your 
/// step by step sum is less than 1.
///            step by step sum
///            startValue = 4 | startValue = 5 | nums
///              (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
///              (1 +2 ) = 3  | (2 +2 ) = 4    |   2
///              (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
///              (0 +4 ) = 4  | (1 +4 ) = 5    |   4
///              (4 +2 ) = 6  | (5 +2 ) = 7    |   2
/// Example 2:
/// Input: nums = [1,2]
/// Output: 1
/// Explanation: Minimum start value should be positive. 
///
/// Example 3:
/// Input: nums = [1,-2,-3]
/// Output: 5
///
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. -100 <= nums[i] <= 100
/// </summary>
int LeetCodeArray::minStartValue(vector<int>& nums)
{
    int sum = 0;
    int result = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        result = max(result, 1 - sum);
    }
    return result;
}

/// <summary>
/// Leet code #1423. Maximum Points You Can Obtain from Cards
/// 
/// Medium
///
/// There are several cards arranged in a row, and each card has an 
/// associated number of points The points are given in the integer 
/// array cardPoints.
///
/// In one step, you can take one card from the beginning or from the 
/// end of the row. You have to take exactly k cards.
///
/// Your score is the sum of the points of the cards you have taken.
///
/// Given the integer array cardPoints and the integer k, return 
/// the maximum score you can obtain.
///
/// Example 1:
/// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
/// Output: 12
/// Explanation: After the first step, your score will 
/// always be 1. However, choosing the rightmost card first 
/// will maximize your total score. The optimal strategy is 
/// to take the three cards on the right, giving a final 
/// score of 1 + 6 + 5 = 12.
///
/// Example 2:
/// Input: cardPoints = [2,2,2], k = 2
/// Output: 4
/// Explanation: Regardless of which two cards you take, your score will 
/// always be 4.
///
/// Example 3:
/// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
/// Output: 55
/// Explanation: You have to take all the cards. Your score is the sum of 
/// points of all cards.
///
/// Example 4:
/// Input: cardPoints = [1,1000,1], k = 1
/// Output: 1
/// Explanation: You cannot take the card in the middle. Your best score 
/// is 1. 
///
/// Example 5:
/// Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
/// Output: 202
///
/// Constraints:
/// 1. 1 <= cardPoints.length <= 10^5
/// 2. 1 <= cardPoints[i] <= 10^4
/// 3. 1 <= k <= cardPoints.length
/// </summary>
int LeetCodeArray::maxScore(vector<int>& cardPoints, int k)
{
    int sum = 0;
    int result = 0;
    for (int i = 0; i < 2 * k; i++)
    {
        int index = (cardPoints.size() - k + i) % cardPoints.size();
        sum += cardPoints[index];
        if (i >= k) sum -= cardPoints[cardPoints.size() - k + i - k];
        if (i >= k-1) result = max(result, sum);
    }
    return result;
}

/// <summary>
/// Leet code #1424. Diagonal Traverse II
/// 
/// Medium
///
/// Given a list of lists of integers, nums, return all elements of nums 
/// in diagonal order as shown in the below images.
/// 
/// Example 1:
/// Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
/// Output: [1,4,2,7,5,3,8,6,9]
///
/// Example 2:
/// Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
/// Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
///
/// Example 3:
/// Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
/// Output: [1,4,2,5,3,8,6,9,7,10,11]
///
/// Example 4:
/// Input: nums = [[1,2,3,4,5,6]]
/// Output: [1,2,3,4,5,6]
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i].length <= 10^5
/// 3. 1 <= nums[i][j] <= 10^9
/// 4. There at most 10^5 elements in nums.
/// </summary>
vector<int> LeetCodeArray::findDiagonalOrderII(vector<vector<int>>& nums)
{
    vector<vector<int>> arr;
    for (size_t r = 0; r < nums.size(); r++)
    {
        for (size_t c = 0; c < nums[r].size(); c++)
        {
            if (r + c >= arr.size()) arr.push_back(vector<int>());
            arr[r + c].push_back(nums[r][c]);
        }
    }
    vector<int> result;
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (int j = (int)arr[i].size() - 1; j >= 0; j--)
        {
            result.push_back(arr[i][j]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1431. Kids With the Greatest Number of Candies
/// 
/// Easy
///
/// Given the array candies and the integer extraCandies, where candies[i] 
/// represents the number of candies that the ith kid has.
///
/// For each kid check if there is a way to distribute extraCandies among 
/// the kids such that he or she can have the greatest number of candies 
/// among them. Notice that multiple kids can have the greatest number of 
/// candies.
///
/// Example 1:
/// Input: candies = [2,3,5,1,3], extraCandies = 3
/// Output: [true,true,true,false,true] 
/// Explanation: 
/// Kid 1 has 2 candies and if he or she receives all extra candies (3) 
/// will have 5 candies --- the greatest number of candies among the kids. 
/// Kid 2 has 3 candies and if he or she receives at least 2 extra candies 
/// will have the greatest number of candies among the kids. 
/// Kid 3 has 5 candies and this is already the greatest number of candies 
/// among the kids. 
/// Kid 4 has 1 candy and even if he or she receives all extra candies will
/// only have 4 candies. 
/// Kid 5 has 3 candies and if he or she receives at least 2 extra candies 
/// will have the greatest number of candies among the kids. 
///
/// Example 2:
/// Input: candies = [4,2,1,1,2], extraCandies = 1
/// Output: [true,false,false,false,false] 
/// Explanation: There is only 1 extra candy, therefore only kid 1 will 
/// have the greatest number of candies among the kids regardless of who 
/// takes the extra candy.
///
/// Example 3:
/// Input: candies = [12,1,12], extraCandies = 10
/// Output: [true,false,true]
/// Constraints:
/// 1. 2 <= candies.length <= 100
/// 2. 1 <= candies[i] <= 100
/// 3. 1 <= extraCandies <= 50
/// </summary>
vector<bool> LeetCodeArray::kidsWithCandies(vector<int>& candies, int extraCandies)
{
    int max_candy = 0;
    vector<bool> result(candies.size());
    for (auto candy : candies) max_candy = max(max_candy, candy);

    for (size_t i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= max_candy)  result[i] = true;
        else result[i] = false;
    }
    return result;
}

/// <summary>
/// Leet code #1437. Check If All 1's Are at Least Length K Places Away
/// 
/// Medium
///
/// Given an array nums of 0s and 1s and an integer k, return True if 
/// all 1's are at least k places away from each other, otherwise return 
/// False.
///
/// Example 1:
/// Input: nums = [1,0,0,0,1,0,0,1], k = 2
/// Output: true
/// Explanation: Each of the 1s are at least 2 places away from each 
/// other.
///
/// Example 2:
/// Input: nums = [1,0,0,1,0,1], k = 2
/// Output: false
/// Explanation: The second 1 and third 1 are only one apart from each 
/// other.
///
/// Example 3:
/// Input: nums = [1,1,1,1,1], k = 0
/// Output: true
///
/// Example 4:
/// Input: nums = [0,1,0,1], k = 1
/// Output: true
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 0 <= k <= nums.length
/// 3. nums[i] is 0 or 1
/// </summary>
bool LeetCodeArray::kLengthApart(vector<int>& nums, int k)
{
    int last = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            if (last != -1 && (int)i - last <= k) return false;
            last = i;
        }
    }
    return true;
}

/// <summary>
/// Leet code #1438. Longest Continuous Subarray With Absolute Diff 
///                  Less Than or Equal to Limit
/// 
/// Medium
///
/// Given an array of integers nums and an integer limit, return the 
/// size of the longest continuous subarray such that the absolute 
/// difference between any two elements is less than or equal to limit.
///
/// In case there is no subarray satisfying the given condition return 0.
///
/// Example 1:
/// Input: nums = [8,2,4,7], limit = 4
/// Output: 2 
/// Explanation: All subarrays are: 
/// [8] with maximum absolute diff |8-8| = 0 <= 4.
/// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
/// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
/// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
/// [2] with maximum absolute diff |2-2| = 0 <= 4.
/// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
/// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
/// [4] with maximum absolute diff |4-4| = 0 <= 4.
/// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
/// [7] with maximum absolute diff |7-7| = 0 <= 4. 
/// Therefore, the size of the longest subarray is 2.
///
/// Example 2:
/// Input: nums = [10,1,2,4,7,2], limit = 5
/// Output: 4 
/// Explanation: The subarray [2,4,7,2] is the longest since the maximum 
/// absolute diff is |2-7| = 5 <= 5.
///
/// Example 3:
/// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
/// Output: 3
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^9
/// 3. 0 <= limit <= 10^9
/// </summary>
int LeetCodeArray::longestSubarray(vector<int>& nums, int limit)
{
    deque<int> min_list;
    deque<int> max_list;
    int first = 0; 
    int last = 0;
    int result = 0;
    min_list.push_back(nums[0]);
    max_list.push_back(nums[0]);
    while (last < (int)nums.size())
    {

        if (max_list.front() - min_list.front() <= limit)
        {
            result = max(result, last - first + 1);
            last++;
            if (last < (int)nums.size())
            {
                while (!min_list.empty() && min_list.back() > nums[last]) min_list.pop_back();
                while (!max_list.empty() && max_list.back() < nums[last]) max_list.pop_back();
                min_list.push_back(nums[last]);
                max_list.push_back(nums[last]);
            }
        }
        else
        {
            if (!min_list.empty() && min_list.front() == nums[first]) min_list.pop_front();
            if (!max_list.empty() && max_list.front() == nums[first]) max_list.pop_front();
            first++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1441. Build an Array With Stack Operations
///
/// Easy
///
/// Given an array target and an integer n. In each iteration, you will read 
/// a number from  list = {1,2,3..., n}.
///
/// Build the target array using the following operations:
///
/// Push: Read a new element from the beginning list, and push it in the array.
/// Pop: delete the last element of the array.
/// If the target array is already built, stop reading more elements.
/// You are guaranteed that the target array is strictly increasing, only 
/// containing numbers between 1 to n inclusive.
///
/// Return the operations to build the target array.
///
/// You are guaranteed that the answer is unique.
/// 
/// Example 1:
///
/// Input: target = [1,3], n = 3
/// Output: ["Push","Push","Pop","Push"]
/// Explanation: 
/// Read number 1 and automatically push in the array -> [1]
/// Read number 2 and automatically push in the array then Pop it -> [1]
/// Read number 3 and automatically push in the array -> [1,3]
///
/// Example 2:
/// Input: target = [1,2,3], n = 3
/// Output: ["Push","Push","Push"]
///
/// Example 3:
/// Input: target = [1,2], n = 4
/// Output: ["Push","Push"]
/// Explanation: You only need to read the first 2 numbers and stop.
///
/// Example 4:
/// Input: target = [2,3,4], n = 4
/// Output: ["Push","Pop","Push","Push","Push"]
/// 
/// Constraints:
/// 1. 1 <= target.length <= 100
/// 2. 1 <= target[i] <= 100
/// 3. 1 <= n <= 100
/// 4. target is strictly increasing.
/// </summary>
vector<string> LeetCodeArray::buildArray(vector<int>& target, int n)
{
    vector<string> result;
    int index = 0;
    for (int i = 1; i <= n; i++)
    {
        if (index >= (int)target.size()) break;
        result.push_back("Push");
        if (target[index] > i)
        {
            result.push_back("Pop");
        }
        else
        {
            index++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1442. Count Triplets That Can Form Two Arrays of Equal XOR
///
/// Medium
///
/// Given an array of integers arr.
///
/// We want to select three indices i, j and k where 
/// (0 <= i < j <= k < arr.length).
///
/// Let's define a and b as follows:
///
/// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
/// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
/// Note that ^ denotes the bitwise-xor operation.
///
/// Return the number of triplets (i, j and k) Where a == b.
/// 
/// Example 1:
/// Input: arr = [2,3,1,6,7]
/// Output: 4
/// Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
///
/// Example 2:
/// Input: arr = [1,1,1,1,1]
/// Output: 10
///
/// Example 3:
/// Input: arr = [2,3]
/// Output: 0
///
/// Example 4:
/// Input: arr = [1,3,5,7,9]
/// Output: 3
///
/// Example 5:
/// Input: arr = [7,11,12,9,5,2,7,17,22]
/// Output: 8
///
/// Constraints:
/// 1. 1 <= arr.length <= 300
/// 2. 1 <= arr[i] <= 10^8
/// </summary>
int LeetCodeArray::countTriplets(vector<int>& arr)
{
    int result = 0;
    map<int, pair<int, int>> xor_map;
    int sum_xor = 0;
    xor_map[0] = { 0, 1 };
    for (size_t i = 0; i < arr.size(); i++)
    {
        sum_xor = sum_xor ^ arr[i];
        if (xor_map.count(sum_xor) > 0)
        {
            result += (i * xor_map[sum_xor].second - xor_map[sum_xor].first);
        }
        xor_map[sum_xor].first += i + 1;
        xor_map[sum_xor].second ++;
    }
    return result;
}

/// <summary>
/// Leet code #1450. Number of Students Doing Homework at a Given Time
/// 
/// Easy
///
/// Given two integer arrays startTime and endTime and given an integer 
/// queryTime.
/// 
/// The ith student started doing their homework at the time startTime[i] 
/// and finished it at time endTime[i].
///
/// Return the number of students doing their homework at time queryTime. 
/// More formally, return the number of students where queryTime lays in 
/// the interval [startTime[i], endTime[i]] inclusive.
/// 
/// Example 1:
/// Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
/// Output: 1
/// Explanation: We have 3 students where:
/// The first student started doing homework at time 1 and finished at 
/// time 3 and wasn't doing anything at time 4.
/// The second student started doing homework at time 2 and finished at 
/// time 2 and also wasn't doing anything at time 4.
/// The third student started doing homework at time 3 and finished at 
/// time 7 and was the only student doing homework at time 4.
///
/// Example 2:
/// Input: startTime = [4], endTime = [4], queryTime = 4
/// Output: 1
/// Explanation: The only student was doing their homework at the 
/// queryTime.
///
/// Example 3:
/// Input: startTime = [4], endTime = [4], queryTime = 5
/// Output: 0
///
/// Example 4:
/// Input: startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
/// Output: 0
///
/// Example 5:
/// Input: startTime = [9,8,7,6,5,4,3,2,1], 
/// endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
/// Output: 5
///
/// Constraints:
/// 1. startTime.length == endTime.length
/// 2. 1 <= startTime.length <= 100
/// 3. 1 <= startTime[i] <= endTime[i] <= 1000
/// 4. 1 <= queryTime <= 1000
/// </summary>
int LeetCodeArray::busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime)
{
    int result = 0;
    for (size_t i = 0; i < startTime.size(); i++)
    {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime)
        {
            result++;
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
int LeetCodeArray::validSubarrays(vector<int>& nums)
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
/// Leet code #1460. Make Two Arrays Equal by Reversing Sub-arrays
/// 
/// Easy
///
/// Given two integer arrays of equal length target and arr.
///
/// In one step, you can select any non-empty sub-array of arr and 
/// reverse it. You are allowed to make any number of steps.
///
/// Return True if you can make arr equal to target, or False otherwise.
/// 
/// Example 1:
///
/// Input: target = [1,2,3,4], arr = [2,4,1,3]
/// Output: true
/// Explanation: You can follow the next steps to convert arr to target:
/// 1- Reverse sub-array [2,4,1], arr becomes [1,4,2,3]
/// 2- Reverse sub-array [4,2], arr becomes [1,2,4,3]
/// 3- Reverse sub-array [4,3], arr becomes [1,2,3,4]
/// There are multiple ways to convert arr to target, this is not the 
/// only way to do so.
///
/// Example 2:
/// Input: target = [7], arr = [7]
/// Output: true
/// Explanation: arr is equal to target without any reverses.
///
/// Example 3:
/// Input: target = [1,12], arr = [12,1]
/// Output: true
///
/// Example 4:
/// Input: target = [3,7,9], arr = [3,7,11]
/// Output: false
/// Explanation: arr doesn't have value 9 and it can never be converted 
/// to target.
///
/// Example 5:
/// Input: target = [1,1,1,1,1], arr = [1,1,1,1,1]
/// Output: true
///
/// Constraints:
/// 1. target.length == arr.length
/// 2. 1 <= target.length <= 1000
/// 3. 1 <= target[i] <= 1000
/// 4. 1 <= arr[i] <= 1000
/// </summary>
bool LeetCodeArray::canBeEqual(vector<int>& target, vector<int>& arr)
{
    unordered_map<int, int> src_map;
    unordered_map<int, int> dest_map;
    for (size_t i = 0; i < arr.size(); i++)
    {
        src_map[arr[i]]++;
        dest_map[target[i]]++;
    }

    for (auto itr : src_map)
    {
        if (dest_map[itr.first] != itr.second) return false;
    }
    return true;
}

/// <summary>
/// Leet code #1470. Shuffle the Array
/// 
/// Easy
/// 
/// Given the array nums consisting of 2n elements in the form 
/// [x1,x2,...,xn,y1,y2,...,yn].
///
/// Return the array in the form [x1,y1,x2,y2,...,xn,yn].
/// 
/// Example 1:
/// Input: nums = [2,5,1,3,4,7], n = 3
/// Output: [2,3,5,4,1,7] 
/// Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the 
/// answer is [2,3,5,4,1,7].
///
/// Example 2:
/// Input: nums = [1,2,3,4,4,3,2,1], n = 4
/// Output: [1,4,2,3,3,2,4,1]
///
/// Example 3:
/// Input: nums = [1,1,2,2], n = 2
/// Output: [1,2,1,2]
///
/// Constraints:
/// 1. 1 <= n <= 500
/// 2. nums.length == 2n
/// 3. 1 <= nums[i] <= 10^3
/// </summary>	
vector<int> LeetCodeArray::shuffle(vector<int>& nums, int n)
{
    vector<int> result(nums.size());
    for (int i = 0; i < n; i++)
    {
        result[2*i] = nums[i];
        result[2*i + 1] = nums[i + n];
    }
    return result;
}

/// <summary>
/// Leet code #1471. The k Strongest Values in an Array
///                
/// Medium
/// 
/// Given an array of integers arr and an integer k.
/// A value arr[i] is said to be stronger than a value arr[j] 
/// if |arr[i] - m| > |arr[j] - m| where m is the median of the array.
/// If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger 
/// than arr[j] if arr[i] > arr[j].
///
/// Return a list of the strongest k values in the array. return the 
/// answer in any arbitrary order.
///
/// Median is the middle value in an ordered integer list. More formally, 
/// if the length of the list is n, the median is the element in 
/// position ((n - 1) / 2) in the sorted list (0-indexed).
///
/// For arr = [6, -3, 7, 2, 11], n = 5 and the median is obtained by 
/// sorting the array arr = [-3, 2, 6, 7, 11] and the median is arr[m] 
/// where m = ((5 - 1) / 2) = 2. The median is 6.
/// For arr = [-7, 22, 17, 3], n = 4 and the median is obtained by 
/// sorting the array arr = [-7, 3, 17, 22] and the median is arr[m] 
/// where m = ((4 - 1) / 2) = 1. The median is 3.
///
/// Example 1:
/// Input: arr = [1,2,3,4,5], k = 2
/// Output: [5,1]
/// Explanation: Median is 3, the elements of the array sorted by the 
/// strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1]. 
/// [1, 5] is also accepted answer.
/// Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 
/// because 5 > 1.
///
/// Example 2:
/// Input: arr = [1,1,3,5,5], k = 2
/// Output: [5,5]
/// Explanation: Median is 3, the elements of the array sorted by the 
/// strongest are [5,5,1,1,3]. The strongest 2 elements are [5, 5].
///
/// Example 3:
/// Input: arr = [6,7,11,7,6,8], k = 5
/// Output: [11,8,6,6,7]
/// Explanation: Median is 7, the elements of the array sorted by the 
/// strongest are [11,8,6,6,7,7].
/// Any permutation of [11,8,6,6,7] is accepted.
///
/// Example 4:
/// Input: arr = [6,-3,7,2,11], k = 3
/// Output: [-3,11,2]
///
/// Example 5:
/// Input: arr = [-7,22,17,3], k = 2
/// Output: [22,17]
///
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. -10^5 <= arr[i] <= 10^5
/// 3. 1 <= k <= arr.length
/// </summary>	
vector<int> LeetCodeArray::getStrongest(vector<int>& arr, int k)
{
    vector<int> result;
    sort(arr.begin(), arr.end());
    int median = arr[(arr.size() - 1) / 2];
    int first = 0;
    int last = arr.size() - 1;
    for (int i = 0; i < k; i++)
    {
        if (abs(arr[last] - median) > abs(arr[first] - median))
        {
            result.push_back(arr[last]);
            last--;
        }
        else if (abs(arr[last] - median) < abs(arr[first] - median))
        {
            result.push_back(arr[first]);
            first++;
        }
        else
        {
            result.push_back(arr[last]);
            last--;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1477. Find Two Non-overlapping Sub-arrays Each With 
///                  Target Sum
///
/// Medium
///
/// Given an array of integers arr and an integer target.
///
/// You have to find two non-overlapping sub-arrays of arr each with 
/// sum equal target. There can be multiple answers so you have to 
/// find an answer where the sum of the lengths of the two sub-arrays 
/// is minimum.
///
/// Return the minimum sum of the lengths of the two required 
/// sub-arrays, or return -1 if you cannot find such two sub-arrays.
///
/// Example 1:
/// Input: arr = [3,2,2,4,3], target = 3
/// Output: 2
/// Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The 
/// sum of their lengths is 2.
///
/// Example 2:
/// Input: arr = [7,3,4,7], target = 7
/// Output: 2
/// Explanation: Although we have three non-overlapping sub-arrays 
/// of sum = 7 ([7], [3,4] and [7]), but we will choose the first 
/// and third sub-arrays as the sum of their lengths is 2.
///
/// Example 3:
/// Input: arr = [4,3,2,6,2,3,4], target = 6
/// Output: -1
/// Explanation: We have only one sub-array of sum = 6.
///
/// Example 4:
/// Input: arr = [5,5,4,4,5], target = 3
/// Output: -1
/// Explanation: We cannot find a sub-array of sum = 3.
///
/// Example 5:
/// Input: arr = [3,1,1,1,5,1,2,1], target = 3
/// Output: 3
/// Explanation: Note that sub-arrays [1,2] and [2,1] cannot be an 
/// answer because they overlap.
///
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 1 <= arr[i] <= 1000
/// 3. 1 <= target <= 10^8
/// </summary> 
int LeetCodeArray::minSumOfLengths(vector<int>& arr, int target)
{
    unordered_map<int, int> sum_map;
    sum_map[0] = -1;
    int sum = 0;
    vector<int> dp(arr.size(), INT_MAX);
    int result = INT_MAX;
    for (int i = 0; i < (int)arr.size(); i++)
    {
        sum += arr[i];
        if (sum_map.count(sum - target) > 0)
        {
            int gap = i - sum_map[sum - target];
            int pos = i - gap;
            if (pos >= 0 && dp[pos] !=  INT_MAX)
            {
                result = min(result, gap + dp[pos]);
            }
            dp[i] = gap;
        }
        if (i > 0) dp[i] = min(dp[i], dp[i - 1]);
        sum_map[sum] = i;
    }
    return result == INT_MAX ? -1 : result;
}

/// <summary>
/// Leet code #1480. Running Sum of 1d Array
///
/// Easy
///
/// Given an array nums. We define a running sum of an array as 
/// runningSum[i] = sum(nums[0]…nums[i]).
///
/// Return the running sum of nums.
/// 
/// Example 1:
/// Input: nums = [1,2,3,4]
/// Output: [1,3,6,10]
/// Explanation: Running sum is obtained as follows: 
/// [1, 1+2, 1+2+3, 1+2+3+4].
///
/// Example 2:
/// Input: nums = [1,1,1,1,1]
/// Output: [1,2,3,4,5]
/// Explanation: Running sum is obtained as follows: [1, 1+1, 
/// 1+1+1, 1+1+1+1, 1+1+1+1+1].
///
/// Example 3:
/// Input: nums = [3,1,2,10,1]
/// Output: [3,4,6,16,17]
///
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. -10^6 <= nums[i] <= 10^6
/// </summary> 
vector<int> LeetCodeArray::runningSum(vector<int>& nums)
{
    vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i == 0) result[i] = nums[i];
        else result[i] = result[i - 1] + nums[i];
    }
    return result;
}

/// <summary>
/// Leet code #1488. Avoid Flood in The City
/// 
/// Medium
///
/// Your country has an infinite number of lakes. Initially, all the 
/// lakes are empty, but when it rains over the nth lake, the nth lake 
/// becomes full of water. If it rains over a lake which is full of 
/// water, there will be a flood. Your goal is to avoid the flood in 
/// any lake.
///
/// Given an integer array rains where:
/// rains[i] > 0 means there will be rains over the rains[i] lake.
/// rains[i] == 0 means there are no rains this day and you can choose 
/// one lake this day and dry it.
/// Return an array ans where:
/// ans.length == rains.length
/// ans[i] == -1 if rains[i] > 0.
/// ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
/// If there are multiple valid answers return any of them. If it is 
/// impossible to avoid flood return an empty array.
///
/// Notice that if you chose to dry a full lake, it becomes empty, but 
/// if you chose to dry an empty lake, nothing changes. (see example 4)
///
/// Example 1:
/// Input: rains = [1,2,3,4]
/// Output: [-1,-1,-1,-1]
/// Explanation: After the first day full lakes are [1]
/// After the second day full lakes are [1,2]
/// After the third day full lakes are [1,2,3]
/// After the fourth day full lakes are [1,2,3,4]
/// There's no day to dry any lake and there is no flood in any lake.
///
/// Example 2:
/// Input: rains = [1,2,0,0,2,1]
/// Output: [-1,-1,2,1,-1,-1]
/// Explanation: After the first day full lakes are [1]
/// After the second day full lakes are [1,2]
/// After the third day, we dry lake 2. Full lakes are [1]
/// After the fourth day, we dry lake 1. There is no full lakes.
/// After the fifth day, full lakes are [2].
/// After the sixth day, full lakes are [1,2].
/// It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is 
/// another acceptable scenario.
///
/// Example 3:
/// 1. Input: rains = [1,2,0,1,2]
/// 2. Output: []
/// Explanation: After the second day, full lakes are  [1,2]. We have 
/// to dry one lake in the third day.
/// After that, it will rain over lakes [1,2]. It's easy to prove that 
/// no matter which lake you choose to dry in the 3rd day, the other one 
/// will flood.
///
/// Example 4:
/// 1. Input: rains = [69,0,0,0,69]
/// 2. Output: [-1,69,1,1,-1]
/// 3. Explanation: Any solution on one of the forms [-1,69,x,y,-1], 
/// 4. [-1,x,69,y,-1] or [-1,x,y,69,-1] is acceptable 
///    where 1 <= x,y <= 10^9
///
/// Example 5:
/// Input: rains = [10,20,20]
/// Output: []
/// Explanation: It will rain over lake 20 two consecutive days. 
/// There is no chance to dry any lake.
///
/// Constraints:
/// 1. 1 <= rains.length <= 10^5
/// 2. 0 <= rains[i] <= 10^9
/// </summary>
vector<int> LeetCodeArray::avoidFlood(vector<int>& rains)
{
    unordered_map<int, int> lakes;
    set<int> drys;
    vector<int> result(rains.size(), 1);
    for (size_t i = 0; i < rains.size(); i++)
    {
        int lake = rains[i];
        if (lake == 0)
        {
            drys.insert(i);
        }
        else
        {
            result[i] = -1;
            if (lakes.count(lake) > 0)
            {
                auto itr = drys.upper_bound(lakes[lake]);
                if (itr == drys.end())
                {
                    result.clear();
                    break;
                }
                else
                {
                    result[*itr] = lake;
                    drys.erase(itr);
                }
            }
            lakes[lake] = i;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1491. Average Salary Excluding the Minimum and Maximum Salary
/// 
/// Easy
///
/// Given an array of unique integers salary where salary[i] is the salary 
/// of the employee i.
///
/// Return the average salary of employees excluding the minimum and maximum 
/// salary.
///  
/// Example 1:
/// Input: salary = [4000,3000,1000,2000]
/// Output: 2500.00000
/// Explanation: Minimum salary and maximum salary are 1000 and 4000 
/// respectively.
/// Average salary excluding minimum and maximum salary is 
/// (2000+3000)/2= 2500
///
/// Example 2:
/// Input: salary = [1000,2000,3000]
/// Output: 2000.00000
/// Explanation: Minimum salary and maximum salary are 1000 and 3000 
/// respectively.
/// Average salary excluding minimum and maximum salary is (2000)/1= 2000
///
/// Example 3:
/// Input: salary = [6000,5000,4000,3000,2000,1000]
/// Output: 3500.00000
/// Example 4:
/// Input: salary = [8000,9000,2000,3000,6000,1000]
/// Output: 4750.00000
/// Constraints:
/// 1. 3 <= salary.length <= 100
/// 2. 10^3 <= salary[i] <= 10^6
/// 3. salary[i] is unique.
/// 4. Answers within 10^-5 of the actual value will be accepted as correct.
/// </summary>
double LeetCodeArray::average(vector<int>& salary)
{
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    double sum = 0;
    for (size_t i = 0; i < salary.size(); i++)
    {
        sum += (double)salary[i];
        min_val = min(min_val, salary[i]);
        max_val = max(max_val, salary[i]);
    }

    if (salary.size() > 2)
    {
        return (sum - (double)min_val - (double)max_val) / (double)(salary.size() - 2);
    }
    else
    {
        return (double)0.0;
    }
}

/// <summary>
/// Leet code #1493. Longest Subarray of 1's After Deleting One Element
/// 
/// Medium
///
/// Given a binary array nums, you should delete one element from it.
///
/// Return the size of the longest non-empty subarray containing only 1's 
/// in the resulting array.
/// Return 0 if there is no such subarray.
/// Example 1:
/// Input: nums = [1,1,0,1]
/// Output: 3
/// Explanation: After deleting the number in position 2, [1,1,1] 
/// contains 3 numbers with value of 1's.
///
/// Example 2:
/// Input: nums = [0,1,1,1,0,1,1,0,1]
/// Output: 5
/// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] 
/// longest subarray with value of 1's is [1,1,1,1,1].
///
/// Example 3:
/// Input: nums = [1,1,1]
/// Output: 2
/// Explanation: You must delete one element.
/// Example 4:
/// Input: nums = [1,1,0,0,1,1,1,0,1]
/// Output: 4
///
/// Example 5:
/// Input: nums = [0,0,0]
/// Output: 0
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. nums[i] is either 0 or 1.
/// </summary>
int LeetCodeArray::longestSubarray(vector<int>& nums)
{
    deque<int> zeros;
    int result = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zeros.push_back(i);
            if (zeros.size() > 2) zeros.pop_front();
        }
        if (zeros.size() < 2) result = max(result, i);
        else result = max(result, i - zeros.front() - 1);
    }
    return result;
}

/// <summary>
/// Leet code #1497. Check If Array Pairs Are Divisible by k
/// 
/// Medium
///
/// Given an array of integers arr of even length n and an integer k.
/// We want to divide the array into exactly n / 2 pairs such that the 
/// sum of each pair is divisible by k.
/// Return True If you can find a way to do that or False otherwise.
/// 
/// Example 1:
/// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
/// Output: true
/// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
///
/// Example 2:
/// Input: arr = [1,2,3,4,5,6], k = 7
/// Output: true
/// Explanation: Pairs are (1,6),(2,5) and(3,4).
///
/// Example 3:
/// Input: arr = [1,2,3,4,5,6], k = 10
/// Output: false
/// Explanation: You can try all possible pairs to see that there is no 
/// way to divide arr into 3 pairs each with sum divisible by 10.
///
/// Example 4:
/// Input: arr = [-10,10], k = 2
/// Output: true
///
/// Example 5:
/// Input: arr = [-1,1,-2,2,-3,3,-4,4], k = 3
/// Output: true
///
/// Constraints:
/// 1. arr.length == n
/// 2. 1 <= n <= 10^5
/// 3. n is even.
/// 4. -10^9 <= arr[i] <= 10^9
/// 5. 1 <= k <= 10^5
/// </summary>
bool LeetCodeArray::canArrange(vector<int>& arr, int k)
{
    vector<int> result(k);
    for (size_t i = 0; i < arr.size(); i++)
    {
        int re = arr[i] % k;
        if (re < 0) result[abs(re)]--;
        else result[abs(re)]++;
    }
    if (result[0] % 2 != 0) return false;
    for (int i = 1; i <= k / 2; i++)
    {
        if (result[i] != result[k - i]) return false;
    }
    return true;
}

/// <summary>
/// Leet code #1498. Number of Subsequences That Satisfy the Given Sum 
///                  Condition
/// 
/// Medium
///
/// Given an array of integers nums and an integer target.
/// Return the number of non-empty subsequences of nums such that the 
/// sum of the minimum and maximum element on it is less or equal than 
/// target.
///
/// Since the answer may be too large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: nums = [3,5,6,7], target = 9
/// Output: 4
/// Explanation: There are 4 subsequences that satisfy the condition.
/// [3] -> Min value + max value <= target (3 + 3 <= 9)
/// [3,5] -> (3 + 5 <= 9)
/// [3,5,6] -> (3 + 6 <= 9)
/// [3,6] -> (3 + 6 <= 9)
///
/// Example 2:
/// Input: nums = [3,3,6,8], target = 10
/// Output: 6
/// Explanation: There are 6 subsequences that satisfy the condition. 
/// (nums can have repeated numbers).
/// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
///
/// Example 3:
/// Input: nums = [2,3,3,4,6,7], target = 12
/// Output: 61
/// Explanation: There are 63 non-empty subsequences, two of them don't 
/// satisfy the condition ([6,7], [7]).
/// Number of valid subsequences (63 - 2 = 61).
///
/// Example 4:
/// Input: nums = [5,2,4,1,7,6,8], target = 16
/// Output: 127
/// Explanation: All non-empty subset satisfy the condition (2^7 - 1) = 127
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^6
/// 3. 1 <= target <= 10^6
/// </summary>
int LeetCodeArray::numSubseq(vector<int>& nums, int target)
{
    int M = 1000000007;
    sort(nums.begin(), nums.end());
    vector<int> factors(nums.size());
    int result = 0;
    int first = 0;
    int last = nums.size() - 1;
    while (first <= last)
    {
        if (nums[first] + nums[last] > target) last--;
        else
        {
            int gap = last - first;
            if (factors[gap] == 0)
            {
                factors[0] = 1;
                for (int j = 1; j <= gap; j++)
                {
                    factors[j] = (factors[j - 1] * 2) % M;
                }
            }
            result = (result + factors[gap]) % M;
            first++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1502. Can Make Arithmetic Progression From Sequence
/// 
/// Easy
///
/// Given an array of numbers arr. A sequence of numbers is called an 
/// arithmetic progression if the difference between any two consecutive 
/// elements is the same.
///
/// Return true if the array can be rearranged to form an arithmetic 
/// progression, otherwise, return false.
/// 
/// Example 1:
/// Input: arr = [3,5,1]
/// Output: true
/// Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with 
/// differences 2 and -2 respectively, between each consecutive elements.
///
/// Example 2:
/// Input: arr = [1,2,4]
/// Output: false
/// Explanation: There is no way to reorder the elements to obtain an 
/// arithmetic progression.
///
/// Constraints:
/// 1. 2 <= arr.length <= 1000
/// 2. -10^6 <= arr[i] <= 10^6
/// </summary>
bool LeetCodeArray::canMakeArithmeticProgression(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < (int)arr.size() - 2; i++)
    {
        if (arr[i + 1] - arr[i] != arr[i + 2] - arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #1504. Count Submatrices With All Ones
/// 
/// Medium
///
/// Given a rows * columns matrix mat of ones and zeros, return how many 
/// submatrices have all ones.
/// 
/// Example 1:
/// Input: mat = [[1,0,1],
///               [1,1,0],
///               [1,1,0]]
/// Output: 13
/// Explanation:
/// There are 6 rectangles of side 1x1.
/// There are 2 rectangles of side 1x2.
/// There are 3 rectangles of side 2x1.
/// There is 1 rectangle of side 2x2. 
/// There is 1 rectangle of side 3x1.
/// Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
///
/// Example 2:
///
/// Input: mat = [[0,1,1,0],
///               [0,1,1,1],
///               [1,1,1,0]]
/// Output: 24
/// Explanation:
/// There are 8 rectangles of side 1x1.
/// There are 5 rectangles of side 1x2.
/// There are 2 rectangles of side 1x3. 
/// There are 4 rectangles of side 2x1.
/// There are 2 rectangles of side 2x2. 
/// There are 2 rectangles of side 3x1. 
/// There is 1 rectangle of side 3x2. 
/// Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
///
/// Example 3:
/// Input: mat = [[1,1,1,1,1,1]]
/// Output: 21
///
/// Example 4:
/// Input: mat = [[1,0,1],[0,1,0],[1,0,1]]
/// Output: 5
/// 
/// Constraints:
/// 1. 1 <= rows <= 150
/// 2. 1 <= columns <= 150
/// 3. 0 <= mat[i][j] <= 1
/// </summary>
int LeetCodeArray::numSubmat(vector<vector<int>>& mat)
{
    int rows = mat.size();
    int cols = mat[0].size();
    int result = 0;
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols)));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = j; k >= 0; k--)
            {
                if (mat[i][k] == 0) break;
                int g = j - k;
                dp[i][j][g]++;
                if (i > 0) dp[i][j][g] += dp[i - 1][j][g];
                result += dp[i][j][g];
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1508. Range Sum of Sorted Subarray Sums
///
/// Medium
///	
/// Given the array nums consisting of n positive integers. You computed 
/// the sum of all non-empty continous subarrays from the array and then 
/// sort them in non-decreasing order, creating a new array of 
/// n * (n + 1) / 2 numbers.
/// Return the sum of the numbers from index left to index right 
/// (indexed from 1), inclusive, in the new array. Since the answer 
/// can be a huge number return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
/// Output: 13 
/// Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. 
/// After sorting them in non-decreasing order we have the new array 
/// [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index 
/// le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
///
/// Example 2:
/// Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
/// Output: 6
/// Explanation: The given array is the same as example 1. We have 
/// the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the 
/// numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
///
/// Example 3:
/// Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
/// Output: 50
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^3
/// 2. nums.length == n
/// 3. 1 <= nums[i] <= 100
/// 4. 1 <= left <= right <= n * (n + 1) / 2
/// </summary>
int LeetCodeArray::rangeSum(vector<int>& nums, int n, int left, int right)
{
    int M = 1000000007;
    vector<int> dp(n);
    vector<int> sum;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) dp[i] = nums[i];
        else dp[i] = dp[i - 1] + nums[i];

        for (int j = -1; j < i; j++)
        {
            if (j == -1) sum.push_back(dp[i]);
            else sum.push_back(dp[i] - dp[j]);
        }
    }
    sort(sum.begin(), sum.end());
    int result = 0;
    for (int i = left - 1; i < right; i++)
    {
        result = result + sum[i];
    }
    return result;
}

/// <summary>
/// Leet code #1513. Number of Substrings With Only 1s
///
/// Medium
///	
/// Given a binary string s (a string consisting only of '0' and '1's).
///
/// Return the number of substrings with all characters 1's.
/// Since the answer may be too large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: s = "0110111"
/// Output: 9
/// Explanation: There are 9 substring in total with only 1's characters.
/// "1" -> 5 times.
/// "11" -> 3 times.
/// "111" -> 1 time.
///
/// Example 2:
/// Input: s = "101"
/// Output: 2
/// Explanation: Substring "1" is shown 2 times in s.
///
/// Example 3:
/// Input: s = "111111"
/// Output: 21
/// Explanation: Each substring contains only 1's characters.
///
/// Example 4:
/// Input: s = "000"
/// Output: 0
/// 
/// Constraints:
/// 1. s[i] == '0' or s[i] == '1'
/// 2. 1 <= s.length <= 10^5
/// </summary>
int LeetCodeArray::numSub(string s)
{
    int result = 0;
    int count = 0;
    int M = 1000000007;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '0') count = 0;
        else
        {
            count++;
            result = (result + count) % M;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1524. Number of Sub-arrays With Odd Sum
/// 
/// Medium
///
/// Given an array of integers arr. Return the number of sub-arrays with 
/// odd sum.
///
/// As the answer may grow large, the answer must be computed 
/// modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: arr = [1,3,5]
/// Output: 4
/// Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
/// All sub-arrays sum are [1,4,9,3,8,5].
/// Odd sums are [1,9,3,5] so the answer is 4.
///
/// Example 2:
/// Input: arr = [2,4,6]
/// Output: 0
/// Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
/// All sub-arrays sum are [2,6,12,4,10,6].
/// All sub-arrays have even sum and the answer is 0.
///
/// Example 3:
/// Input: arr = [1,2,3,4,5,6,7]
/// Output: 16
///
/// Example 4:
/// Input: arr = [100,100,99,99]
/// Output: 4
///
/// Example 5:
/// Input: arr = [7]
/// Output: 1
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 1 <= arr[i] <= 100
/// </summary>
int LeetCodeArray::numOfSubarrays(vector<int>& arr)
{
    vector<int> count(2);
    count[0] = 1;
    int M = 1000000007;
    int result = 0;
    int sum = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        result = (result + count[1 - (sum % 2)]) % M;
        count[sum % 2]++;
    }
    return result;
}

/// <summary>
/// Leet code #1526. Minimum Number of Increments on Subarrays to Form a 
///                  Target Array
/// 
/// Hard
///
/// Given an array of positive integers target and an array initial of 
/// same size with all zeros.
///
/// Return the minimum number of operations to form a target array from 
/// initial if you are allowed to do the following operation:
///
/// Choose any subarray from initial and increment each value by one.
/// The answer is guaranteed to fit within the range of a 32-bit signed 
/// integer.
///
///
/// Example 1:
///
/// Input: target = [1,2,3,2,1]
/// Output: 3
/// Explanation: We need at least 3 operations to form the target array 
/// from the initial array.
/// [0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
/// [1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
/// [1,2,2,2,1] increment 1 at index 2.
/// [1,2,3,2,1] target array is formed.
///
/// Example 2:
/// Input: target = [3,1,1,2]
/// Output: 4
/// Explanation: (initial)[0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> 
/// [2,1,1,2] -> [3,1,1,2] (target).
///
/// Example 3:
/// Input: target = [3,1,5,4,2]
/// Output: 7
/// Explanation: (initial)[0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] 
/// -> [3,1,1,1,1] -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] 
/// -> [3,1,5,4,2] (target).
///
/// Example 4:
/// Input: target = [1,1,1,1]
/// Output: 1
///
/// Constraints:
/// 1. 1 <= target.length <= 10^5
/// 2. 1 <= target[i] <= 10^5
/// </summary>
int LeetCodeArray::minNumberOperations(vector<int>& target)
{
    int result = 0;
    int prev = 0;
    for (size_t i = 0; i < target.size(); i++)
    {
        if (target[i] > prev)
        {
            result += target[i] - prev;
        }
        prev = target[i];
    }
    return result;
}

/// <summary>
/// Leet code #221. Maximal Square  
/// 
/// Given a 2D binary matrix filled with 0's and 1's, find the largest square 
/// containing only 1's and return its area. 
/// For example, given the following matrix: 
/// 1 0 1 0 0
/// 1 0 1 1 1
/// 1 1 1 1 1
/// 1 0 0 1 0
/// Return 4. 
/// </summary>
int LeetCodeArray::maximalSquare(vector<vector<char>>& matrix)
{
    int result = 0;
    if (matrix.size() == 0 || matrix[0].size() == 0) return result;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '0') dp[i][j] = 0;
            else
            {
                if ((i == 0) || (j == 0))
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                    dp[i][j]++;
                }
                result = max(result, dp[i][j] * dp[i][j]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1534. Count Good Triplets
/// 
/// Easy
///
/// Given an array of integers arr, and three integers a, b and c. You need 
/// to find the number of good triplets.
///
/// A triplet (arr[i], arr[j], arr[k]) is good if the following conditions 
/// are true:
///
/// 0 <= i < j < k < arr.length
/// |arr[i] - arr[j]| <= a
/// |arr[j] - arr[k]| <= b
/// |arr[i] - arr[k]| <= c
/// Where |x| denotes the absolute value of x.
///
/// Return the number of good triplets.
/// 
/// Example 1:
/// Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
/// Output: 4
/// Explanation: There are 4 good triplets: 
/// [(3,0,1), (3,0,1), (3,1,1), (0,1,1)]
///
/// Example 2:
/// Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
/// Output: 0
/// Explanation: No triplet satisfies all conditions.
///
/// Constraints:
/// 1. 3 <= arr.length <= 100
/// 2. 0 <= arr[i] <= 1000
/// 3. 0 <= a, b, c <= 1000
/// </summary>
int LeetCodeArray::countGoodTriplets(vector<int>& arr, int a, int b, int c)
{
    int result = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = i + 1; j < arr.size(); j++)
        {
            for (size_t k = j + 1; k < arr.size(); k++)
            {
                if ((abs(arr[i] - arr[j]) <= a) &&
                    (abs(arr[j] - arr[k]) <= b) &&
                    (abs(arr[i] - arr[k]) <= c))
                {
                    result++;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1537. Get the Maximum Score
/// 
/// Hard
///
/// You are given two sorted arrays of distinct integers nums1 and nums2.
///
/// A valid path is defined as follows:
///
/// Choose array nums1 or nums2 to traverse (from index-0).
/// Traverse the current array from left to right.
/// If you are reading any value that is present in nums1 and nums2 you are 
/// allowed to change your path to the other array. (Only one repeated value 
/// is considered in the valid path).
/// Score is defined as the sum of uniques values in a valid path.
///
/// Return the maximum score you can obtain of all possible valid paths.
///
/// Since the answer may be too large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
/// Output: 30
/// Explanation: Valid paths:
/// [2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  
/// (starting from nums1)
/// [4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
/// The maximum is obtained with the path in green [2,4,6,8,10].
///
/// Example 2:
/// Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
/// Output: 109
/// Explanation: Maximum sum is obtained with the path [1,3,5,100].
///
/// Example 3:
/// Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
/// Output: 40
/// Explanation: There are no common elements between nums1 and nums2.
/// Maximum sum is obtained with the path [6,7,8,9,10].
///
/// Example 4:
/// Input: nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
/// Output: 61
///  
/// Constraints:
/// 1. 1 <= nums1.length <= 10^5
/// 2. 1 <= nums2.length <= 10^5
/// 3. 1 <= nums1[i], nums2[i] <= 10^7
/// 4. nums1 and nums2 are strictly increasing.
/// </summary>
int LeetCodeArray::maxSum(vector<int>& nums1, vector<int>& nums2)
{
    int M = 1000000007;

    long long sum1 = 0, sum2 = 0;
    int index1 = nums1.size() - 1, index2 = nums2.size() - 1;
    while (index1 >= 0 || index2 >= 0)
    {
        if (index1 < 0 || (index2 >= 0 && nums1[index1] < nums2[index2]))
        {
            sum2 += nums2[index2];
            index2--;
        }
        else if (index2 < 0 || (index1 >= 0 && nums2[index2] < nums1[index1]))
        {
            sum1 += nums1[index1];
            index1--;
        }
        else
        {
            sum1 = max(sum1, sum2);
            sum2 = sum1;
            sum1 += nums1[index1];
            sum2 += nums2[index2];
            index1--;
            index2--;
        }
    }
    int result = (int)(max(sum1, sum2) % M);
    return result;
}

/// <summary>
/// Leet code #1539. Kth Missing Positive Number
/// 
/// Easy
///
/// Given an array arr of positive integers sorted in a strictly increasing
/// order, and an integer k.
///
/// Find the kth positive integer that is missing from this array.
///
/// Example 1:
/// Input: arr = [2,3,4,7,11], k = 5
/// Output: 9
/// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
/// The 5th missing positive integer is 9.
///
/// Example 2:
///
/// Input: arr = [1,2,3,4], k = 2
/// Output: 6
/// Explanation: The missing positive integers are [5,6,7,...]. 
/// The 2nd missing positive integer is 6.
/// Constraints:
/// 1. 1 <= arr.length <= 1000
/// 2. 1 <= arr[i] <= 1000
/// 3. 1 <= k <= 1000
/// 4. arr[i] < arr[j] for 1 <= i < j <= arr.lengthYou are given two sorted 
///    arrays of distinct integers nums1 and nums2.
/// </summary>
int LeetCodeArray::findKthPositive(vector<int>& arr, int k)
{
    int prev = 0;
    int result = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] - prev > 1)
        {
            if (k <= arr[i] - prev - 1)
            {
                result = prev + k;
                break;
            }
            k -= arr[i] - prev - 1;
        }
        prev = arr[i];
    }
    result = prev + k;
    return result;
}

/// <summary>
/// Leet code #1550. Three Consecutive Odds
/// 
/// Easy
///
/// Given an integer array arr, return true if there are three consecutive 
/// odd numbers in the array. Otherwise, return false.
///
/// Example 1:
/// Input: arr = [2,6,4,1]
/// Output: false
/// Explanation: There are no three consecutive odds.
///
/// Example 2:
/// Input: arr = [1,2,34,3,4,5,7,23,12]
/// Output: true
/// Explanation: [5,7,23] are three consecutive odds.
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 1000
/// 2. 1 <= arr[i] <= 1000
/// </summary>
bool LeetCodeArray::threeConsecutiveOdds(vector<int>& arr)
{
    int count = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            if (count == 3) return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #1538. Guess the Majority in a Hidden Array
/// 
/// Medium
///
/// We have an integer array nums, where all the integers in nums are 0 
/// or 1. You will not be given direct access to the array, instead, you 
/// will have an API ArrayReader which have the following functions:
/// 
/// int query(int a, int b, int c, int d): where 0 <= a < b < c < d < 
/// ArrayReader.length(). The function returns the distribution of the 
/// value of the 4 elements and returns:
/// 4 : if the values of the 4 elements are the same (0 or 1).
/// 2 : if three elements have a value equal to 0 and one element has 
/// value equal to 1 or vice versa.
/// 0 : if two element have a value equal to 0 and two elements have a 
/// value equal to 1.
/// int length(): Returns the size of the array.
/// You are allowed to call query() 2 * n times at most where n is equal 
/// to ArrayReader.length().
///
/// Return any index of the most frequent value in nums, in case of tie, 
/// return -1.
/// 
/// Follow up: What is the minimum number of calls needed to find the 
/// majority element?
///
/// Example 1:
/// Input: nums = [0,0,1,0,1,1,1,1]
/// Output: 5
/// Explanation: The following calls to the API
/// reader.length() // returns 8 because there are 8 elements in the hidden
///                 // array.
/// reader.query(0,1,2,3) // returns 2 this is a query that compares the 
///                       // elements nums[0], nums[1], nums[2], nums[3]
///                       // Three elements have a value equal to 0 and one 
///                       // element has value equal to 1 or viceversa.
/// reader.query(4,5,6,7) // returns 4 because nums[4], nums[5], nums[6], 
///                       // nums[7] have the same value.
///                       // we can infer that the most frequent value is 
///                       // found in the last 4 elements.
///                       // Index 2, 4, 6, 7 is also a correct answer.
///
/// Example 2:
/// Input: nums = [0,0,1,1,0]
/// Output: 0
///
/// Example 3:
/// Input: nums = [1,0,1,0,1,0,1,0]
/// Output: -1
/// Constraints:
/// 1. 5 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 1
/// </summary>
int LeetCodeArray::guessMajority(ArrayReader& reader)
{
    vector<int> dp(5);
    dp[0] = reader.query(0, 1, 2, 3);
    dp[1] = reader.query(0, 1, 2, 4);
    dp[2] = reader.query(0, 2, 3, 4);
    dp[3] = reader.query(1, 2, 3, 4);
    dp[4] = reader.query(0, 1, 3, 4);
    int length = reader.length();

    int vote = 1;
    int diff = -1;
    for (int i = 5; i < length; i++)
    {
        int value = reader.query(0, 1, 2, i);
        if (value == dp[0]) vote++;
        else
        {
            vote--;
            diff = i;
        }
    }
    if (dp[0] == dp[1])
    {
        vote++;
    }
    else
    {
        vote--;
        diff = 4;
    }
    if (dp[1] == dp[2])
    {
        vote++;
    }
    else
    {
        vote--;
        diff = 1;
    }
    if (dp[2] == dp[3])
    {
        if (diff != 1) vote++;
        else vote--;
    }
    else
    {
        if (diff != 1) vote--;
        else vote++;
    }
    if (dp[1] == dp[4])
    {
        vote++;
    }
    else
    {
        vote--;
        diff = 2;
    }
    if (vote == 0) return -1;
    else if (vote > 0) return 3;
    else return diff;
}

/// <summary>
/// Leet code #1533. Find the Index of the Large Integer
/// 
/// Medium
///
/// We have an integer array arr, where all the integers in arr are equal 
/// except for one integer which is larger than the rest of the integers. 
/// You will not be given direct access to the array, instead, you will 
/// have an API ArrayReader which have the following functions:
/// int compareSub(int l, int r, int x, int y): where 0 <= l, r, x, y < 
/// ArrayReader.length(), l <= r and x <= y. The function compares the 
/// sum of sub-array arr[l..r] with the sum of the sub-array arr[x..y] 
/// and returns:
/// 1 if arr[l]+arr[l+1]+...+arr[r] > arr[x]+arr[x+1]+...+arr[y].
/// 0 if arr[l]+arr[l+1]+...+arr[r] == arr[x]+arr[x+1]+...+arr[y].
/// -1 if arr[l]+arr[l+1]+...+arr[r] < arr[x]+arr[x+1]+...+arr[y].
/// int length(): Returns the size of the array.
/// You are allowed to call compareSub() 20 times at most. You can 
/// assume both functions work in O(1) time.
///
/// Return the index of the array arr which has the largest integer.
/// Follow-up:
/// What if there are two numbers in arr that are bigger than all other 
/// numbers?
/// What if there is one number that is bigger than other numbers and 
/// one number that is smaller than other numbers?
/// 
/// Example 1: 
/// Input: arr = [7,7,7,7,10,7,7,7]
/// Output: 4
/// Explanation: The following calls to the API
/// reader.compareSub(0, 0, 1, 1) // returns 0 this is a query comparing 
/// the sub-array (0, 0) with the sub array (1, 1), (i.e. compares arr[0] 
/// with arr[1]).
/// Thus we know that arr[0] and arr[1] doesn't contain the largest 
/// element.
/// reader.compareSub(2, 2, 3, 3) // returns 0.
/// reader.compareSub(4, 4, 5, 5) // returns 1.
/// Notice that we made only 3 calls, so the answer is valid.
///
/// Example 2:
/// Input: nums = [6,6,12]
/// Output: 2
/// 
/// Constraints:
/// 1. 2 <= arr.length <= 5 * 10^5
/// 2. 1 <= arr[i] <= 100
/// 3. All elements of arr are equal except for one element which is 
/// larger than all other elements.
/// </summary>
int LeetCodeArray::getIndex(ArrayReader& reader)
{
    int first = 0;
    int last = reader.length() - 1;
    while (first < last)
    {
        int length = (last - first + 1) / 2;
        int middle = first + length;
        int result = reader.compareSub(first, middle - 1, middle, middle + length - 1);
        if (result == -1)
        {
            first = middle;
            last = middle + length - 1;
        }
        else if (result == 1)
        {
            last = middle - 1;
        }
        else
        {
            break;
        }
    }
    return last;
}

/// <summary>
/// Leet code #1566. Detect Pattern of Length M Repeated K or More Times
/// 
/// Easy
///
/// Given an array of positive integers arr,  find a pattern of length m 
/// that is repeated k or more times.
///
/// A pattern is a subarray (consecutive sub-sequence) that consists of 
/// one or more values, repeated multiple times consecutively without 
/// overlapping. A pattern is defined by its length and the number of 
/// repetitions.
///
/// Return true if there exists a pattern of length m that is repeated 
/// k or more times, otherwise return false.
/// 
/// Example 1:
/// Input: arr = [1,2,4,4,4,4], m = 1, k = 3
/// Output: true
/// Explanation: The pattern (4) of length 1 is repeated 4 consecutive 
/// times. Notice that pattern can be repeated k or more times but not 
/// less.
///
/// Example 2:
/// Input: arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
/// Output: true
/// Explanation: The pattern (1,2) of length 2 is repeated 2 consecutive 
/// times. Another valid pattern (2,1) is also repeated 2 times.
///
/// Example 3:
/// Input: arr = [1,2,1,2,1,3], m = 2, k = 3
/// Output: false
/// Explanation: The pattern (1,2) is of length 2 but is repeated only 2 
/// times. There is no pattern of length 2 that is repeated 3 or more 
/// times.
///
/// Example 4:
/// Input: arr = [1,2,3,1,2], m = 2, k = 2
/// Output: false
/// Explanation: Notice that the pattern (1,2) exists twice but not 
/// consecutively, so it doesn't count.
///
/// Example 5:
/// Input: arr = [2,2,2,2], m = 2, k = 3
/// Output: false
/// Explanation: The only pattern of length 2 is (2,2) however it's 
/// repeated only twice. Notice that we do not count overlapping 
/// repetitions.
/// 
/// Constraints:
/// 1. 2 <= arr.length <= 100
/// 2. 1 <= arr[i] <= 100
/// 3. 1 <= m <= 100
/// 4. 2 <= k <= 100
/// </summary>
bool LeetCodeArray::containsPattern(vector<int>& arr, int m, int k)
{
    vector<int> dp(arr.size());
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (i < m) continue;
        if (i + m > (int)arr.size()) continue;
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (arr[i - (m - j)] != arr[i + j])
            {
                match = false;
                break;
            }
        }
        if (match == true)
        {
            dp[i] = dp[i - m] + 1;
            if (dp[i] == k-1) return true;
        }
    }
    return false;
}


/// <summary>
/// Leet code #1567. Maximum Length of Subarray With Positive Product
/// 
/// Medium
///
/// Given an array of integers nums, find the maximum length of a subarray 
/// where the product of all its elements is positive.
///
/// A subarray of an array is a consecutive sequence of zero or more 
/// values taken out of that array.
///
/// Return the maximum length of a subarray with positive product.
///
/// Example 1:
/// Input: nums = [1,-2,-3,4]
/// Output: 4
/// Explanation: The array nums already has a positive product of 24.
///
/// Example 2:
/// Input: nums = [0,1,-2,-3,-4]
/// Output: 3
/// Explanation: The longest subarray with positive product is [1,-2,-3] 
/// which has a product of 6.
/// Notice that we cannot include 0 in the subarray since that'll make 
/// the product 0 which is not positive.
///
/// Example 3:
/// Input: nums = [-1,-2,-3,0,1]
/// Output: 2
/// Explanation: The longest subarray with positive product is [-1,-2] 
/// or [-2,-3].
///
/// Example 4:
/// Input: nums = [-1,2]
/// Output: 1
///
/// Example 5:
/// Input: nums = [1,2,3,5,-6,4,0,10]
/// Output: 4
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. -10^9 <= nums[i] <= 10^9
/// </summary>
int LeetCodeArray::getMaxLen(vector<int>& nums)
{
    vector<int> map(2, INT_MAX);
    map[0] = -1;
    int count = 0;
    int result = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            map[1] = INT_MAX;
            map[0] = i;
            count = 0;
        }
        else if (nums[i] < 0)
        {
            count = 1 - count;
            if (map[count]  != INT_MAX)
            {
                result = max(result, i - map[count]);
            }
            else
            {
                map[count] = i;
            }
        }
        else
        {
            result = max(result, i - map[count]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1572. Matrix Diagonal Sum
/// 
/// Easy
///
/// Given a square matrix mat, return the sum of the matrix diagonals. 
/// Only include the sum of all the elements on the primary diagonal and 
/// all the elements on the secondary diagonal that are not part of the 
/// primary diagonal.
///
/// Example 1:
/// Input: mat = [[1,2,3],
///          [4,5,6],
///          [7,8,9]]
/// Output: 25
/// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
/// Notice that element mat[1][1] = 5 is counted only once.
///
/// Example 2:
/// Input: mat = [[1,1,1,1],
///          [1,1,1,1],
///          [1,1,1,1],
///          [1,1,1,1]]
/// Output: 8
///
/// Example 3:
/// Input: mat = [[5]]
/// Output: 5
///
/// Constraints:
/// 1. n == mat.length == mat[i].length
/// 2. 1 <= n <= 100
/// 3. 1 <= mat[i][j] <= 100
/// </summary>
int LeetCodeArray::diagonalSum(vector<vector<int>>& mat)
{
    int result = 0;

    int row = 0; 
    int col = 0;
    while (row < (int)mat.size())
    {
        result += mat[row][col];
        row++;
        col++;
    }
    row = 0;
    col = mat.size() - 1;
    while (row < (int)mat.size())
    {
        if (row != col) result += mat[row][col];
        row++;
        col--;
    }
    
    return result;
}

/// <summary>
/// Leet code #1574. Shortest Subarray to be Removed to Make Array Sorted 
/// 
/// Medium
///
/// Given an integer array arr, remove a subarray (can be empty) from arr 
/// such that the remaining elements in arr are non-decreasing.
///
/// A subarray is a contiguous subsequence of the array.
/// Return the length of the shortest subarray to remove.
///
/// Example 1:
/// Input: arr = [1,2,3,10,4,2,3,5]
/// Output: 3
/// Explanation: The shortest subarray we can remove is [10,4,2] of 
/// length 3. The remaining elements after that will be [1,2,3,3,5] which 
/// are sorted.
/// Another correct solution is to remove the subarray [3,10,4].
///
/// Example 2:
/// Input: arr = [5,4,3,2,1]
/// Output: 4
/// Explanation: Since the array is strictly decreasing, we can only keep 
/// a single element. Therefore we need to remove a subarray of length 4, 
/// either [5,4,3,2] or [4,3,2,1].
///
/// Example 3:
/// Input: arr = [1,2,3]
/// Output: 0
/// Explanation: The array is already non-decreasing. We do not need to 
/// remove any elements.
///
/// Example 4:
/// Input: arr = [1]
/// Output: 0
///
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 0 <= arr[i] <= 10^9
/// </summary>
int LeetCodeArray::findLengthOfShortestSubarray(vector<int>& arr)
{
    int left = 0;
    while (left < (int)arr.size() - 1 && arr[left] <= arr[left + 1]) left++;
    if (left == arr.size() - 1) return 0;
    int right = arr.size() - 1;
    while (right > 0 && arr[right - 1] <= arr[right]) right--;
    int result = left + 1;
    result = max(result, (int)arr.size() - right);
    int last = arr.size() - 1;
    while (left >= 0 && last >= right)
    {
        if (arr[last] >= arr[left])
        {
            result = max(result, left + 1 + (int)arr.size() - last);
            last--;
        }
        else
        {
            left--;
        }
    }
    return arr.size() - result;
}

/// <summary>
/// Leet code #1582. Special Positions in a Binary Matrix 
/// 
/// Easy
///
/// Given a rows x cols matrix mat, where mat[i][j] is either 0 or 1, 
/// return the number of special positions in mat.
///
/// A position (i,j) is called special if mat[i][j] == 1 and all other 
/// elements in row i and column j are 0 (rows and columns are 0-indexed).
///
/// Example 1:
/// Input: mat = [[1,0,0],
///          [0,0,1],
///          [1,0,0]]
/// Output: 1
/// Explanation: (1,2) is a special position because mat[1][2] == 1 and 
/// all other elements in row 1 and column 2 are 0.
///
/// Example 2:
/// Input: mat = [[1,0,0],
///          [0,1,0],
///          [0,0,1]]
/// Output: 3
/// Explanation: (0,0), (1,1) and (2,2) are special positions. 
///
/// Example 3:
/// Input: mat = [[0,0,0,1],
///          [1,0,0,0],
///          [0,1,1,0],
///          [0,0,0,0]]
/// Output: 2
///
/// Example 4:
/// Input: mat = [[0,0,0,0,0],
///          [1,0,0,0,0],
///          [0,1,0,0,0],
///          [0,0,1,0,0],
///          [0,0,0,1,1]]
/// Output: 3
/// Constraints:
/// 1. rows == mat.length
/// 2. cols == mat[i].length
/// 3. 1 <= rows, cols <= 100
/// 4. mat[i][j] is 0 or 1.
/// </summary>
int LeetCodeArray::numSpecial(vector<vector<int>>& mat)
{
    vector<int> row(mat.size()), col(mat[0].size());
    int result = 0;
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                if (row[i] == 1 && col[j] == 1)
                {
                    result++;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1583. Count Unhappy Friends
/// 
/// Medium
///
/// You are given a list of preferences for n friends, where n is always 
/// even.
///
/// For each person i, preferences[i] contains a list of friends sorted 
/// in the order of preference. In other words, a friend earlier in the 
/// list is more preferred than a friend later in the list. Friends in 
/// each list are denoted by integers from 0 to n-1.
///
/// All the friends are divided into pairs. The pairings are given in a 
/// list pairs, where pairs[i] = [xi, yi] denotes xi is paired with yi 
/// and yi is paired with xi.
///
/// However, this pairing may cause some of the friends to be unhappy. 
/// A friend x is unhappy if x is paired with y and there exists a 
/// friend u who is paired with v but:
///
/// x prefers u over y, and
/// u prefers x over v.
/// Return the number of unhappy friends.
/// 
/// Example 1:
/// Input: n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], 
/// [1, 2, 0]], pairs = [[0, 1], [2, 3]]
/// Output: 2
/// Explanation:
/// Friend 1 is unhappy because:
/// - 1 is paired with 0 but prefers 3 over 0, and
/// - 3 prefers 1 over 2.
/// Friend 3 is unhappy because:
/// - 3 is paired with 2 but prefers 1 over 2, and
/// - 1 prefers 3 over 0.
/// Friends 0 and 2 are happy.
///
/// Example 2:
/// Input: n = 2, preferences = [[1], [0]], pairs = [[1, 0]]
/// Output: 0
/// Explanation: Both friends 0 and 1 are happy.
///
/// Example 3:
/// Input: n = 4, preferences = [[1, 3, 2], [2, 3, 0], [1, 3, 0], 
/// [0, 2, 1]], pairs = [[1, 3], [0, 2]]
/// Output: 4
/// 
/// Constraints:
/// 1. 2 <= n <= 500
/// 2. n is even.
/// 3. preferences.length == n
/// 4. preferences[i].length == n - 1
/// 5. 0 <= preferences[i][j] <= n - 1
/// 6. preferences[i] does not contain i.
/// 7. All values in preferences[i] are unique.
/// 8. pairs.length == n/2
/// 9. pairs[i].length == 2
/// 10. xi != yi
/// 11. 0 <= xi, yi <= n - 1
/// 12. Each person is contained in exactly one pair.
/// </summary>
int LeetCodeArray::unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs)
{
    vector<vector<int>> rank(n, vector<int>(n));
    for (size_t i = 0; i < preferences.size(); i++)
    {
        for (size_t j = 0; j < preferences[i].size(); j++)
        {
            rank[i][preferences[i][j]] = j+1;
        }
    }
    vector<int> friend_pair(n);
    for (size_t i = 0; i < pairs.size(); i++)
    {
        friend_pair[pairs[i][0]] = pairs[i][1];
        friend_pair[pairs[i][1]] = pairs[i][0];
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (size_t j = 0; j < preferences[i].size(); j++)
        {
            int other = preferences[i][j];
            if (other == friend_pair[i]) break;
            if (rank[other][i] < rank[other][friend_pair[other]])
            {
                result++;
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1588. Sum of All Odd Length Subarrays 
/// 
/// Easy
///
/// Given an array of positive integers arr, calculate the sum of all 
/// possible odd-length subarrays.
///
/// A subarray is a contiguous subsequence of the array.
/// Return the sum of all odd-length subarrays of arr.
///
/// Example 1:
/// Input: arr = [1,4,2,5,3]
/// Output: 58
/// Explanation: The odd-length subarrays of arr and their sums are:
/// [1] = 1
/// [4] = 4
/// [2] = 2
/// [5] = 5
/// [3] = 3
/// [1,4,2] = 7
/// [4,2,5] = 11
/// [2,5,3] = 10
/// [1,4,2,5,3] = 15
/// If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 
/// 10 + 15 = 58
/// 
/// Example 2:
/// Input: arr = [1,2]
/// Output: 3
/// Explanation: There are only 2 subarrays of odd length, [1] 
/// and [2]. Their sum is 3.
///
/// Example 3:
/// Input: arr = [10,11,12]
/// Output: 66
/// Constraints:
/// 1. 1 <= arr.length <= 100
/// 2. 1 <= arr[i] <= 1000
/// </summary>
int LeetCodeArray::sumOddLengthSubarrays(vector<int>& arr)
{
    // counting for ending at current position.
    pair<int, int> odd = { 0, 0 }, even = { 0, 0 };
    int result = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        pair<int, int> next_odd, next_even;
        next_odd.first = even.first + 1;
        next_odd.second = even.second + (even.first + 1) * arr[i];
        next_even.first = odd.first;
        next_even.second = odd.second + odd.first * arr[i];
        odd = next_odd;
        even = next_even;

        result = result + odd.second;
    }
    return result;
}

/// <summary>
/// Leet code #1590. Make Sum Divisible by P
/// 
/// Medium
///
/// Given an array of positive integers nums, remove the smallest subarray 
/// (possibly empty) such that the sum of the remaining elements is 
/// divisible by p. It is not allowed to remove the whole array.
///
/// Return the length of the smallest subarray that you need to remove, 
/// or -1 if it's impossible.
///
/// A subarray is defined as a contiguous block of elements in the array.
/// 
/// Example 1:
/// Input: nums = [3,1,4,2], p = 6
/// Output: 1
/// Explanation: The sum of the elements in nums is 10, which is not 
/// divisible by 6. We can remove the subarray [4], and the sum of the 
/// remaining elements is 6, which is divisible by 6.
///
/// Example 2:
/// Input: nums = [6,3,5,2], p = 9
/// Output: 2
/// Explanation: We cannot remove a single element to get a sum divisible 
/// by 9. The best way is to remove the subarray [5,2], leaving us with 
/// [6,3] with sum 9.
///
/// Example 3:
/// Input: nums = [1,2,3], p = 3
/// Output: 0
/// Explanation: Here the sum is 6. which is already divisible by 3. Thus 
/// we do not need to remove anything.
///
/// Example 4:
/// Input: nums = [1,2,3], p = 7
/// Output: -1
/// Explanation: There is no way to remove a subarray in order to get a 
/// sum divisible by 7.
///
/// Example 5:
/// Input: nums = [1000000000,1000000000,1000000000], p = 3
/// Output: 0
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^9
/// 3. 1 <= p <= 10^9
/// </summary>
int LeetCodeArray::minSubarray(vector<int>& nums, int p)
{
    unordered_map<int, int> positions;
    int sum = 0;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum = (sum + nums[i]) % p;
    }
    if (sum == 0) return result;
    result = INT_MAX;
    int curr = 0;
    positions[0] = -1;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        curr = (curr + nums[i]) % p;
        int target = (curr + p - sum) % p;
        if (positions.count(target) > 0)
        {
            result = min(result, i - positions[target]);
        }
        positions[curr] = i;
    }
    return (result < (int) nums.size()) ? result : -1;
}

/// <summary>
/// Leet code #1599. Maximum Profit of Operating a Centennial Wheel
/// 
/// Medium
///
/// You are the operator of a Centennial Wheel that has four gondolas, 
/// and each gondola has room for up to four people. You have the ability 
/// to rotate the gondolas counterclockwise, which costs you runningCost 
/// dollars.
///
/// You are given an array customers of length n where customers[i] is 
/// the number of new customers arriving just before the ith rotation 
/// (0-indexed). This means you must rotate the wheel i times before 
/// customers[i] arrive. Each customer pays boardingCost dollars when 
/// they board on the gondola closest to the ground and will exit once 
/// that gondola reaches the ground again.
///
/// You can stop the wheel at any time, including before serving all 
/// customers. If you decide to stop serving customers, all subsequent 
/// rotations are free in order to get all the customers down safely. 
/// Note that if there are currently more than four customers waiting at 
/// the wheel, only four will board the gondola, and the rest will wait 
/// for the next rotation.
/// 
/// Return the minimum number of rotations you need to perform to maximize 
/// your profit. If there is no scenario where the profit is positive, 
/// return -1.
///
/// Example 1:
/// 
/// Input: customers = [8,3], boardingCost = 5, runningCost = 6
/// Output: 3
/// Explanation: The numbers written on the gondolas are the number of 
/// people currently there.
/// 1. 8 customers arrive, 4 board and 4 wait for the next gondola, the 
///    wheel rotates. Current profit is 4 * $5 - 1 * $6 = $14.
/// 2. 3 customers arrive, the 4 waiting board the wheel and the other 3 
///    wait, the wheel rotates. Current profit is 8 * $5 - 2 * $6 = $28.
/// 3. The final 3 customers board the gondola, the wheel rotates. Current 
///    profit is 11 * $5 - 3 * $6 = $37.
/// 4. The highest profit was $37 after rotating the wheel 3 times.
///
/// Example 2:
/// Input: customers = [10,9,6], boardingCost = 6, runningCost = 4
/// Output: 7
/// Explanation:
/// 1. 10 customers arrive, 4 board and 6 wait for the next gondola, the 
///    wheel rotates. Current profit is 4 * $6 - 1 * $4 = $20.
/// 2. 9 customers arrive, 4 board and 11 wait (2 originally waiting, 9 
///    newly waiting), the wheel rotates. Current profit is 
///    8 * $6 - 2 * $4 = $40.
/// 3. The final 6 customers arrive, 4 board and 13 wait, the wheel 
///    rotates. Current profit is 12 * $6 - 3 * $4 = $60.
/// 4. 4 board and 9 wait, the wheel rotates. Current profit is 
///    16 * $6 - 4 * $4 = $80.
/// 5. 4 board and 5 wait, the wheel rotates. Current profit is 
///    20 * $6 - 5 * $4 = $100.
/// 6. 4 board and 1 waits, the wheel rotates. Current profit is 
///    24 * $6 - 6 * $4 = $120.
/// 7. 1 boards, the wheel rotates. Current profit is 
///    25 * $6 - 7 * $4 = $122.
/// 8. The highest profit was $122 after rotating the wheel 7 times.
///
/// Example 3:
/// Input: customers = [3,4,0,5,1], boardingCost = 1, runningCost = 92
/// Output: -1
/// Explanation:
/// 1. 3 customers arrive, 3 board and 0 wait, the wheel rotates. Current 
///    profit is 3 * $1 - 1 * $92 = -$89.
/// 2. 4 customers arrive, 4 board and 0 wait, the wheel rotates. Current 
///    profit is 7 * $1 - 2 * $92 = -$177.
/// 3. 0 customers arrive, 0 board and 0 wait, the wheel rotates. Current 
///    profit is 7 * $1 - 3 * $92 = -$269.
/// 4. 5 customers arrive, 4 board and 1 waits, the wheel rotates. Current 
///    profit is 12 * $1 - 4 * $92 = -$356.
/// 5. 1 customer arrives, 2 board and 0 wait, the wheel rotates. Current 
///    profit is 13 * $1 - 5 * $92 = -$447.
/// 6. The profit was never positive, so return -1.
///
/// Example 4:
/// Input: customers = [10,10,6,4,7], boardingCost = 3, runningCost = 8
/// Output: 9
/// Explanation:
/// 1. 10 customers arrive, 4 board and 6 wait, the wheel rotates. Current 
///    profit is 4 * $3 - 1 * $8 = $4.
/// 2. 10 customers arrive, 4 board and 12 wait, the wheel rotates. Current 
///    profit is 8 * $3 - 2 * $8 = $8.
/// 3. 6 customers arrive, 4 board and 14 wait, the wheel rotates. Current 
///    profit is 12 * $3 - 3 * $8 = $12.
/// 4. 4 customers arrive, 4 board and 14 wait, the wheel rotates. Current 
///    profit is 16 * $3 - 4 * $8 = $16.
/// 5. 7 customers arrive, 4 board and 17 wait, the wheel rotates. Current 
///    profit is 20 * $3 - 5 * $8 = $20.
/// 6. 4 board and 13 wait, the wheel rotates. Current profit 
///    is 24 * $3 - 6 * $8 = $24.
/// 7. 4 board and 9 wait, the wheel rotates. Current profit is 
///    28 * $3 - 7 * $8 = $28.
/// 8. 4 board and 5 wait, the wheel rotates. Current profit is 
///    32 * $3 - 8 * $8 = $32.
/// 9. 4 board and 1 waits, the wheel rotates. Current profit is 
///    36 * $3 - 9 * $8 = $36.
/// 10. 1 board and 0 wait, the wheel rotates. Current profit is 
///    37 * $3 - 10 * $8 = $31.
/// 11. The highest profit was $36 after rotating the wheel 9 times.
///
/// Constraints:
/// 1. n == customers.length
/// 2. 1 <= n <= 10^5
/// 3. 0 <= customers[i] <= 50
/// 4. 1 <= boardingCost, runningCost <= 100
/// </summary>
int LeetCodeArray::minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost)
{
    int result = -1;
    int max_profit = 0;
    int waiting = 0;
    int profit = 0;
    int index = 0;
    while (waiting > 0 || index < (int)customers.size())
    {
        if (index < (int)customers.size())
        {
            waiting += customers[index];
        }
        index++;
        if (waiting > 4)
        {
            profit += boardingCost * 4;
            waiting -= 4;
        }
        else
        {
            profit += boardingCost * waiting;
            waiting = 0;
        }
        profit -= runningCost;
        if (profit > max_profit)
        {
            max_profit = profit;
            result = index;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1605. Find Valid Matrix Given Row and Column Sums
/// 
/// Medium
///
/// You are given two arrays rowSum and colSum of non-negative integers 
/// where rowSum[i] is the sum of the elements in the ith row and colSum[j] 
/// is the sum of the elements of the jth column of a 2D matrix. In other 
/// words, you do not know the elements of the matrix, but you do know the 
/// sums of each row and column.
///
/// Find any matrix of non-negative integers of size rowSum.length x 
/// colSum.length that satisfies the rowSum and colSum requirements.
///
/// Return a 2D array representing any matrix that fulfills the 
/// requirements. It's guaranteed that at least one matrix that fulfills 
/// the requirements exists.
///
/// Example 1:
/// Input: rowSum = [3,8], colSum = [4,7]
/// Output: [[3,0],
///          [1,7]]
/// Explanation:
/// 0th row: 3 + 0 = 0 == rowSum[0]
/// 1st row: 1 + 7 = 8 == rowSum[1]
/// 0th column: 3 + 1 = 4 == colSum[0]
/// 1st column: 0 + 7 = 7 == colSum[1]
/// The row and column sums match, and all matrix elements are 
/// non-negative.
/// Another possible matrix is: [[1,2],
///                              [3,5]]
/// Example 2:
/// Input: rowSum = [5,7,10], colSum = [8,6,8]
/// Output: [[0,5,0],
///          [6,1,0],
///         [2,0,8]]
///
/// Example 3:
/// Input: rowSum = [14,9], colSum = [6,9,8]
/// Output: [[0,9,5],
///          [6,0,3]]
///
/// Example 4:
/// Input: rowSum = [1,0], colSum = [1]
/// Output: [[1],
///          [0]]
///
/// Example 5:
/// Input: rowSum = [0], colSum = [0]
/// Output: [[0]]
///
/// Constraints:
/// 1. 1 <= rowSum.length, colSum.length <= 500
/// 2. 0 <= rowSum[i], colSum[i] <= 108
/// 3. sum(rows) == sum(columns)
/// </summary>
vector<vector<int>> LeetCodeArray::restoreMatrix(vector<int> rowSum, vector<int> colSum)
{
    vector<vector<int>> result(rowSum.size(), vector<int>(colSum.size()));
    int row = 0;
    int col = 0;
    while (row < (int)rowSum.size() && col < (int)colSum.size())
    {
        if (rowSum[row] < colSum[col])
        {
            result[row][col] = rowSum[row];
            colSum[col] -= result[row][col];
            row++;
        }
        else
        {
            result[row][col] = colSum[col];
            rowSum[row] -= result[row][col];
            col++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1629. Slowest Key
/// 
/// Easy
///
/// A newly designed keypad was tested, where a tester pressed a sequence 
/// of n keys, one at a time.
///
/// You are given a string keysPressed of length n, where keysPressed[i] 
/// was the ith key pressed in the testing sequence, and a sorted list 
/// releaseTimes, where releaseTimes[i] was the time the ith key was 
/// released. Both arrays are 0-indexed. The 0th key was pressed at the 
/// time 0, and every subsequent key was pressed at the exact time the 
/// previous key was released.
///
/// The tester wants to know the key of the keypress that had the longest 
/// duration. The ith keypress had a duration of releaseTimes[i] - 
/// releaseTimes[i - 1], and the 0th keypress had a duration of 
/// releaseTimes[0].
///
/// Note that the same key could have been pressed multiple times during 
/// the test, and these multiple presses of the same key may not have had 
/// the same duration.
///
/// Return the key of the keypress that had the longest duration. If there 
/// are multiple such keypresses, return the lexicographically largest key 
/// of the keypresses.
///
/// Example 1:
/// Input: releaseTimes = [9,29,49,50], keysPressed = "cbcd"
/// Output: "c"
/// Explanation: The keypresses were as follows:
/// Keypress for 'c' had a duration of 9 (pressed at time 0 and released 
/// at time 9).
/// Keypress for 'b' had a duration of 29 - 9 = 20 (pressed at time 9 
/// right after the release of the previous character and released at 
/// time 29).
/// Keypress for 'c' had a duration of 49 - 29 = 20 (pressed at time 29 
/// right after the release of the previous character and released at 
/// time 49).
/// Keypress for 'd' had a duration of 50 - 49 = 1 (pressed at time 49 
/// right after the release of the previous character and released at 
/// time 50).
/// The longest of these was the keypress for 'b' and the second keypress 
/// for 'c', both with duration 20.
/// 'c' is lexicographically larger than 'b', so the answer is 'c'.
///
/// Example 2:
/// Input: releaseTimes = [12,23,36,46,62], keysPressed = "spuda"
/// Output: "a"
/// Explanation: The keypresses were as follows:
/// Keypress for 's' had a duration of 12.
/// Keypress for 'p' had a duration of 23 - 12 = 11.
/// Keypress for 'u' had a duration of 36 - 23 = 13.
/// Keypress for 'd' had a duration of 46 - 36 = 10.
/// Keypress for 'a' had a duration of 62 - 46 = 16.
/// The longest of these was the keypress for 'a' with duration 16.
///
/// Constraints:
/// 1. releaseTimes.length == n
/// 2. keysPressed.length == n
/// 3. 2 <= n <= 1000
/// 4. 1 <= releaseTimes[i] <= 10^9 
/// 5. releaseTimes[i] < releaseTimes[i+1]
/// 6. keysPressed contains only lowercase English letters.
/// </summary>
char LeetCodeArray::slowestKey(vector<int>& releaseTimes, string keysPressed)
{
    int prev_rel = 0;
    char max_key = '#';
    int max_dur = 0;
    for (size_t i = 0; i < releaseTimes.size(); i++)
    {
        int duration = releaseTimes[i] - prev_rel;
        if ((duration > max_dur) || (duration == max_dur && keysPressed[i] > max_key))
        {
            max_key = keysPressed[i];
            max_dur = duration;
        }
        prev_rel = releaseTimes[i];
    }
    return max_key;
}

/// <summary>
/// Leet code #1630. Arithmetic Subarrays
/// 
/// Medium
///
/// A sequence of numbers is called arithmetic if it consists of at least 
/// two elements, and the difference between every two consecutive 
/// elements is the same. More formally, a sequence s is arithmetic if and 
/// only if s[i+1] - s[i] == s[1] - s[0] for all valid i.
/// 
/// For example, these are arithmetic sequences:
/// 1, 3, 5, 7, 9
/// 7, 7, 7, 7
/// 3, -1, -5, -9
/// The following sequence is not arithmetic:
/// 
/// 1, 1, 2, 5, 7
/// You are given an array of n integers, nums, and two arrays of m 
/// integers each, l and r, representing the m range queries, where the 
/// ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
///
/// Return a list of boolean elements answer, where answer[i] is true if 
/// the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be 
/// rearranged to form an arithmetic sequence, and false otherwise.
/// 
/// Example 1:
/// Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
/// Output: [true,false,true]
/// Explanation:
/// In the 0th query, the subarray is [4,6,5]. This can be rearranged 
/// as [6,5,4], which is an arithmetic sequence.
/// In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged 
/// as an arithmetic sequence.
/// In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged 
/// as [3,5,7,9], which is an arithmetic sequence.
///
/// Example 2:
/// Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], 
/// l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
/// Output: [false,true,false,false,true,true]
/// 
/// Constraints:
///
/// 1. n == nums.length
/// 2. m == l.length
/// 3. m == r.length
/// 4. 2 <= n <= 500
/// 5. 1 <= m <= 500
/// 6. 0 <= l[i] < r[i] < n
/// 7. -10^5 <= nums[i] <= 10^5
/// </summary>
vector<bool> LeetCodeArray::checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
{
    vector<bool> result(l.size());
    for (size_t i = 0; i < l.size(); i++)
    {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int j = l[i]; j <= r[i]; j++)
        {
            min_val = min(min_val, nums[j]);
            max_val = max(max_val, nums[j]);
        }
        int delta = (max_val - min_val) / (r[i] - l[i]);
        if (delta * (r[i] - l[i]) != (max_val - min_val))
        {
            result[i] = false;
            continue;
        }
        result[i] = true;
        if (delta == 0) continue;
        vector<int> visited(r[i] - l[i] + 1);
        for (int j = l[i]; j <= r[i]; j++)
        {
            int pos = (nums[j] - min_val) / delta;
            if (pos * delta != (nums[j] - min_val))
            {
                result[i] = false;
                break;
            }
            if (visited[pos] == 1)
            {
                result[i] = false;
                break;
            }
            visited[pos] = 1;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1636. Sort Array by Increasing Frequency
/// 
/// Easy
///
/// Given an array of integers nums, sort the array in increasing order 
/// based on the frequency of the values. If multiple values have the 
/// same frequency, sort them in decreasing order.
///
/// Return the sorted array.
///
/// Example 1:
/// Input: nums = [1,1,2,2,2,3]
/// Output: [3,1,1,2,2,2]
/// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, 
/// and '2' has a frequency of 3.
///
/// Example 2:
/// Input: nums = [2,3,1,3,2]
/// Output: [1,3,3,2,2]
/// Explanation: '2' and '3' both have a frequency of 2, so they are 
/// sorted in decreasing order.
///
/// Example 3:
/// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
/// Output: [5,-1,4,4,-6,-6,1,1,1]
///
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. -100 <= nums[i] <= 100
/// </summary>
vector<int> LeetCodeArray::frequencySort(vector<int>& nums)
{
    unordered_map<int, int> num_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_map[nums[i]]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto itr : num_map)
    {
        pq.push(make_pair(-itr.second, itr.first));
    }
    vector<int> result;
    while (!pq.empty())
    {
        pair<int, int> pair = pq.top();
        pq.pop();
        for (int i = 0; i < 0-pair.first; i++)
        {
            result.push_back(pair.second);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1640. Check Array Formation Through Concatenation
/// 
/// Easy
///
/// You are given an array of distinct integers arr and an array of 
/// integer arrays pieces, where the integers in pieces are distinct. 
/// Your goal is to form arr by concatenating the arrays in pieces in 
/// any order. However, you are not allowed to reorder the integers 
/// in each array pieces[i].
/// 
/// Return true if it is possible to form the array arr from pieces. 
/// Otherwise, return false.
///
/// Example 1:
/// Input: arr = [85], pieces = [[85]]
/// Output: true
///
/// Example 2:
/// Input: arr = [15,88], pieces = [[88],[15]]
/// Output: true
/// Explanation: Concatenate [15] then [88]
///
/// Example 3:
/// Input: arr = [49,18,16], pieces = [[16,18,49]]
/// Output: false
/// Explanation: Even though the numbers match, we cannot reorder pieces[0].
///
/// Example 4:
/// Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
/// Output: true
/// Explanation: Concatenate [91] then [4,64] then [78]
///
/// Example 5:
/// Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
/// Output: false
///
/// Constraints:
/// 1. 1 <= pieces.length <= arr.length <= 100
/// 2. sum(pieces[i].length) == arr.length
/// 3. 1 <= pieces[i].length <= arr.length
/// 4. 1 <= arr[i], pieces[i][j] <= 100
/// 5. The integers in arr are distinct. 
/// 6. The integers in pieces are distinct (i.e., If we flatten pieces in a 1D 
///    array, all the integers in this array are distinct).
/// </summary>
bool LeetCodeArray::canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
{
    unordered_map<int, int> num_map;
    for (size_t i = 0; i < pieces.size(); i++)
    {
        num_map[pieces[i][0]] = i;
    }
    int j = -1;
    int k = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (j == -1)
        {
            if (num_map.count(arr[i]) == 0)
            {
                return false;
            }
            j = num_map[arr[i]];
            num_map.erase(arr[i]);
            k = 0;
        }
        if (arr[i] != pieces[j][k]) return false;
        k++;
        if (k == pieces[j].size()) j = -1;
    }
    return true;
}

/// <summary>
/// Leet code #1637. Widest Vertical Area Between Two Points Containing 
///                  No Points
/// 
/// Medium
///
/// Given n points on a 2D plane where points[i] = [x[i], y[i]], Return 
/// the widest vertical area between two points such that no points are 
/// inside the area.
///
/// A vertical area is an area of fixed-width extending infinitely along 
/// the y-axis (i.e., infinite height). The widest vertical area is the 
/// one with the maximum width.
///
/// Note that points on the edge of a vertical area are not considered 
/// included in the area.
///
/// Example 1:
/// Input: points = [[8,7],[9,9],[7,4],[9,7]]
/// Output: 1
/// Explanation: Both the red and the blue area are optimal.
///
/// Example 2:
/// Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
/// Output: 3
/// Constraints:
/// 1. n == points.length
/// 2. 2 <= n <= 10^5
/// 3. points[i].length == 2
/// 4. 0 <= x[i], y[i] <= 10^9
/// </summary>
int LeetCodeArray::maxWidthOfVerticalArea(vector<vector<int>>& points)
{
    int result = 0;
    sort(points.begin(), points.end());
    for (size_t i = 1; i < points.size(); i++)
    {
        result = max(result, points[i][0] - points[i - 1][0]);
    }
    return result;
}

/// <summary>
/// Leet code #1646. Get Maximum in Generated Array
/// 
/// Easy
///
/// You are given an integer n. An array nums of length n + 1 is 
/// generated in the following way:
///
/// nums[0] = 0
/// nums[1] = 1
/// nums[2 * i] = nums[i] when 2 <= 2 * i <= n
/// nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
/// Return the maximum integer in the array nums​​​.
///
/// Example 1:
/// Input: n = 7
/// Output: 3
/// Explanation: According to the given rules:
/// nums[0] = 0
/// nums[1] = 1
/// nums[(1 * 2) = 2] = nums[1] = 1
/// nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
/// nums[(2 * 2) = 4] = nums[2] = 1
/// nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
/// nums[(3 * 2) = 6] = nums[3] = 2
/// nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
/// Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is 3.
///
/// Example 2:
/// Input: n = 2
/// Output: 1
/// Explanation: According to the given rules, the maximum between 
/// nums[0], nums[1], and nums[2] is 1.
///
/// Example 3:
/// Input: n = 3
/// Output: 2
/// Explanation: According to the given rules, the maximum between 
/// nums[0], nums[1], nums[2], and nums[3] is 2.
///
/// Constraints:
/// 1. 0 <= n <= 100
/// </summary>
int LeetCodeArray::getMaximumGenerated(int n)
{
    vector<int> nums(n + 1);
    int result = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0) nums[i] = 0;
        else if (i == 1) nums[i] = 1;
        else if (i % 2 == 0) nums[i] = nums[i / 2];
        else nums[i] = nums[i / 2] + nums[i / 2 + 1];
        result = max(result, nums[i]);
    }
    return result;
}


/// <summary>
/// Leet code #1652. Defuse the Bomb
/// 
/// Easy
///
/// You have a bomb to defuse, and your time is running out! Your informer 
/// will provide you with a circular array code of length of n and a key k.
///
/// To decrypt the code, you must replace every number. All the numbers are 
/// replaced simultaneously.
/// 
/// If k > 0, replace the ith number with the sum of the next k numbers.
/// If k < 0, replace the ith number with the sum of the previous k numbers.
/// If k == 0, replace the ith number with 0.
/// As code is circular, the next element of code[n-1] is code[0], and the 
/// previous element of code[0] is code[n-1].
///
/// Given the circular array code and an integer key k, return the 
/// decrypted code to defuse the bomb!
/// 
/// Example 1:
/// Input: code = [5,7,1,4], k = 3
/// Output: [12,10,16,13]
/// Explanation: Each number is replaced by the sum of the next 3 numbers. 
/// The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the 
/// numbers wrap around.
///
/// Example 2:
/// Input: code = [1,2,3,4], k = 0
/// Output: [0,0,0,0]
/// Explanation: When k is zero, the numbers are replaced by 0. 
///
/// Example 3:
/// 1. Input: code = [2,4,9,3], k = -2
/// 2. Output: [12,5,6,13]
/// Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that 
/// the numbers wrap around again. If k is negative, the sum is of the 
/// previous numbers.
/// Constraints:
/// 1. n == code.length
/// 2. 1 <= n <= 100
/// 3. 1 <= code[i] <= 100
/// 4. -(n - 1) <= k <= n - 1
/// </summary>
vector<int> LeetCodeArray::decrypt(vector<int>& code, int k)
{
    int n = code.size();
    vector<int> sum(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        if (i == 0) sum[i] = code[i];
        else sum[i] = sum[i - 1] + code[i % n];
    }
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        if (k == 0) result[i] = 0;
        if (k > 0) result[i] = sum[i + k] - sum[i];
        else result[i] = sum[i + n - 1] - sum[i + n + k - 1];
    }
    return result;
}

/// <summary>
/// Leet code #1656. Design an Ordered Stream
/// 
/// Easy
///
/// Given two string arrays word1 and word2, return true if the two arrays 
/// represent the same string, and false otherwise.
///
/// A string is represented by an array if the array elements concatenated 
/// in order forms the string.
///
/// Example 1:
/// Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
/// Output: true
/// Explanation:
/// word1 represents string "ab" + "c" -> "abc"
/// word2 represents string "a" + "bc" -> "abc"
/// The strings are the same, so return true.
///
/// Example 2:
/// Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
/// Output: false
///
/// Example 3:
/// Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
/// Output: true
///
/// Constraints:
/// 1. 1 <= word1.length, word2.length <= 10^3
/// 2. 1 <= word1[i].length, word2[i].length <= 10^3
/// 3. 1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
/// 4. word1[i] and word2[i] consist of lowercase letters.
/// </summary>
bool LeetCodeArray::arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
{
    size_t r_i = 0, c_i = 0;
    size_t r_j = 0, c_j = 0;

    while (r_i < word1.size() && r_j < word2.size())
    {
        if (word1[r_i][c_i] != word2[r_j][c_j])
        {
            return false;
        }
        c_i++;
        c_j++;
        if (c_i == word1[r_i].size())
        {
            r_i++;
            c_i = 0;
        }
        if (c_j == word2[r_j].size())
        {
            r_j++;
            c_j = 0;
        }
    }
    if (r_i < word1.size() || r_j < word2.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}

/// <summary>
/// Leet code #1658. Minimum Operations to Reduce X to Zero
/// 
/// Medium
///
/// You are given an integer array nums and an integer x. In one operation, 
/// you can either remove the leftmost or the rightmost element from the 
/// array nums and subtract its value from x. Note that this modifies the 
/// array for future operations.
///
/// Return the minimum number of operations to reduce x to exactly 0 if 
/// it's possible, otherwise, return -1.
///
/// Example 1:
/// Input: nums = [1,1,4,2,3], x = 5
/// Output: 2
/// Explanation: The optimal solution is to remove the last two elements to 
/// reduce x to zero.
///
/// Example 2:
/// Input: nums = [5,6,7,8,9], x = 4
/// Output: -1
///
/// Example 3:
/// Input: nums = [3,2,20,1,1,3], x = 10
/// Output: 5
/// Explanation: The optimal solution is to remove the last three elements 
/// and the first two elements (5 operations in total) to reduce x to zero.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^4
/// 3. 1 <= x <= 10^9
/// </summary>
int LeetCodeArray::minOperations(vector<int>& nums, int x)
{
    int result = INT_MAX;
    int sum = 0;
    int left = 0;
    for (left = 0; left < (int)nums.size(); left++)
    {
        sum += nums[left];
        if (sum == x) result = min(result, left + 1);
        if (sum >= x) break;
    }
    if (sum < x) return -1;

    int right = nums.size();
    while (left >= 0 || sum <= x)
    {
        if (left >= 0 && sum > x)
        {
            sum -= nums[left];
            left--;
        }
        else if (right > 0 && sum < x)
        {
            right--;
            sum += nums[right];
        }
        else
        {
            result = min(result, left + 1 + (int)nums.size() - right);
            if (left < 0) break;
            sum -= nums[left];
            left--;
        }
    }
    if (result == INT_MAX) result = -1;
    return result;
}

/// <summary>
/// Leet code #1664. Ways to Make a Fair Array
/// 
/// Medium
///
/// You are given an integer array nums. You can choose exactly one index 
/// (0-indexed) and remove the element. Notice that the index of the 
/// elements may change after the removal.
///
/// For example, if nums = [6,1,7,4,1]:
///
/// Choosing to remove index 1 results in nums = [6,7,4,1].
/// Choosing to remove index 2 results in nums = [6,1,4,1].
/// Choosing to remove index 4 results in nums = [6,1,7,4].
/// An array is fair if the sum of the odd-indexed values equals the sum 
/// of the even-indexed values.
///
/// Return the number of indices that you could choose such that after 
/// the removal, nums is fair.
///
/// Example 1:
/// Input: nums = [2,1,6,4]
/// Output: 1
/// Explanation:
/// Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
/// Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
/// Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
/// Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
/// There is 1 index that you can remove to make nums fair.
///
/// Example 2:
/// Input: nums = [1,1,1]
/// Output: 3
/// Explanation: You can remove any index and the remaining array is fair.
///
/// Example 3:
/// Input: nums = [1,2,3]
/// Output: 0
/// Explanation: You cannot make a fair array after removing any index.
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^4
/// </summary>
int LeetCodeArray::waysToMakeFair(vector<int>& nums)
{
    int even = 0;
    int odd = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0) even += nums[i];
        else odd += nums[i];
    }
    int result = 0;
    int e = 0;
    int o = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (odd - o + e == even - e + o - nums[i]) result++;
            e += nums[i];
        }
        else
        {
            if (odd - o + e - nums[i] == even - e + o) result++;
            o += nums[i];
        }
    }
    return result;
}

/// <summary>
/// Leet code #1672. Richest Customer Wealth
/// 
/// Easy
/// 
/// You are given an m x n integer grid accounts where accounts[i][j] 
/// is the amount of money the ith customer has in the jth bank. Return 
/// the wealth that the richest customer has.
///
/// A customer's wealth is the amount of money they have in all their 
/// bank accounts. The richest customer is the customer that has the 
/// maximum wealth.
/// 
/// Example 1:
///
/// Input: accounts = [[1,2,3],[3,2,1]]
/// Output: 6
/// Explanation:
/// 1st customer has wealth = 1 + 2 + 3 = 6
/// 2nd customer has wealth = 3 + 2 + 1 = 6
/// Both customers are considered the richest with a wealth of 6 each, 
/// so return 6.
///
/// Example 2:
/// Input: accounts = [[1,5],[7,3],[3,5]]
/// Output: 10
/// Explanation: 
/// 1st customer has wealth = 6
/// 2nd customer has wealth = 10 
/// 3rd customer has wealth = 8
/// The 2nd customer is the richest with a wealth of 10.
///
/// Example 3:
/// Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
/// Output: 17
/// Constraints:
/// 1. m == accounts.length
/// 2. n == accounts[i].length
/// 3. 1 <= m, n <= 50
/// 4. 1 <= accounts[i][j] <= 100
/// </summary>
int LeetCodeArray::maximumWealth(vector<vector<int>>& accounts)
{
    int result = 0;
    for (size_t i = 0; i < accounts.size(); i++)
    {
        int sum = 0;
        for (size_t j = 0; j < accounts[i].size(); j++)
        {
            sum += accounts[i][j];
        }
        result = max(result, sum);
    }
    return result;
}

/// <summary>
/// Leet code #1673. Find the Most Competitive Subsequence
/// 
/// Medium
/// 
/// Given an integer array nums and a positive integer k, return the most 
/// competitive subsequence of nums of size k.
///
/// An array's subsequence is a resulting sequence obtained by erasing some 
/// (possibly zero) elements from the array.
///
/// We define that a subsequence a is more competitive than a subsequence b 
/// (of the same length) if in the first position where a and b differ, 
/// subsequence a has a number less than the corresponding number in b. For 
/// example, [1,3,4] is more competitive than [1,3,5] because the first 
/// position they differ is at the final number, and 4 is less than 5.
///
/// Example 1:
/// Input: nums = [3,5,2,6], k = 2
/// Output: [2,6]
/// Explanation: Among the set of every possible subsequence: {[3,5], 
/// [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
///
/// Example 2:
/// Input: nums = [2,4,3,3,5,4,9,6], k = 4
/// Output: [2,3,3,4]
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^9
/// 3. 1 <= k <= nums.length
/// </summary>
vector<int> LeetCodeArray::mostCompetitive(vector<int>& nums, int k)
{
    vector<int> result;
    for (size_t i = 0; i < nums.size(); i++)
    {
        while (!result.empty() && nums[i] < result.back() &&
              (int)(nums.size() - i +result.size()) > k)
        {
            result.pop_back();
        }
        if ((int)result.size() < k)
        {
            result.push_back(nums[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1671. Minimum Number of Removals to Make Mountain Array
/// 
/// Hard
/// 
/// You may recall that an array arr is a mountain array if and only if:
///
/// arr.length >= 3
/// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such 
/// that:
/// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
/// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
/// Given an integer array nums, return the minimum number of elements to 
/// remove to make nums a mountain array.
/// 
/// Example 1: 
/// Input: nums = [1,3,1]
/// Output: 0
/// Explanation: The array itself is a mountain array so we do not need to 
/// remove any elements.
///
/// Example 2:
/// Input: nums = [2,1,1,5,6,2,3,1]
/// Output: 3
/// Explanation: One solution is to remove the elements at indices 0, 1, 
/// and 5, making the array nums = [1,5,6,3,1].
/// Example 3:
/// Input: nums = [4,3,2,1,1,2,3,1]
/// Output: 4
///
/// Example 4:
/// Input: nums = [1,2,3,4,4,3,2,1]
/// Output: 1
/// Constraints:
/// 1. 3 <= nums.length <= 1000
/// 2. 1 <= nums[i] <= 10^9
/// 3. It is guaranteed that you can make a mountain array out of nums.
/// </summary>
int LeetCodeArray::minimumMountainRemovals(vector<int>& nums)
{
    vector<int> left(nums.size());
    vector<int> right(nums.size());
    int prev_max = 0;
    vector<int> dp;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (index == dp.size()) dp.push_back(nums[i]);
        else dp[index] = nums[i];
        left[i] = index;
    }
    dp.clear();
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (index == dp.size()) dp.push_back(nums[i]);
        else dp[index] = nums[i];
        right[i] = index;
    }
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (left[i] > 0 && right[i] > 0)
        {
            result = max(result, left[i] + right[i] + 1);
        }
    }
    return nums.size() - result;
}

/// <summary>
/// Leet code #1691. Maximum Height by Stacking Cuboids
/// 
/// Hard
/// 
/// Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = 
/// [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and 
/// place them on each other.
///
/// You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= 
/// lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions 
/// by rotating it to put it on another cuboid.
///
/// Return the maximum height of the stacked cuboids.
/// 
/// Example 1:
/// Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
/// Output: 190
/// Explanation:
/// Cuboid 1 is placed on the bottom with the 53x37 side facing down with 
/// height 95.
/// Cuboid 0 is placed next with the 45x20 side facing down with height 50.
/// Cuboid 2 is placed next with the 23x12 side facing down with height 45.
/// The total height is 95 + 50 + 45 = 190.
///
/// Example 2:
/// Input: cuboids = [[38,25,45],[76,35,3]]
/// Output: 76
/// Explanation:
/// You can't place any of the cuboids on the other.
/// We choose cuboid 1 and rotate it so that the 35x3 side is facing down 
/// and its height is 76.
///
/// Example 3:
/// Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],
/// [17,7,11],[17,11,7]]
/// Output: 102
/// Explanation:
/// After rearranging the cuboids, you can see that all cuboids have the 
/// same dimension.
/// You can place the 11x7 side down on all cuboids so their heights are 17.
/// The maximum height of stacked cuboids is 6 * 17 = 102.
///
/// Constraints:
/// 1. n == cuboids.length
/// 2. 1 <= n <= 100
/// 3. 1 <= widthi, lengthi, heighti <= 100
/// </summary>
int LeetCodeArray::maxHeight(vector<vector<int>>& cuboids)
{
    for (size_t i = 0; i < cuboids.size(); i++)
    {
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    sort(cuboids.begin(), cuboids.end());
    vector<int> dp(cuboids.size());
    int result = 0;
    for (size_t i = 0; i < cuboids.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (cuboids[i][0] >= cuboids[j][0] &&
                cuboids[i][1] >= cuboids[j][1] &&
                cuboids[i][2] >= cuboids[j][2])
            {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += cuboids[i][2];
        result = max(result, dp[i]);
    }
    return result;
}

/// <summary>
/// Leet code #1685. Sum of Absolute Differences in a Sorted Array
/// 
/// Medium
/// 
/// You are given an integer array nums sorted in non-decreasing order.
///
/// Build and return an integer array result with the same length as nums 
/// such that result[i] is equal to the summation of absolute differences 
/// between nums[i] and all the other elements in the array.
///
/// In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 
/// 0 <= j < nums.length and j != i (0-indexed).
/// 
/// Example 1:
///
/// Input: nums = [2,3,5]
/// Output: [4,3,5]
/// Explanation: Assuming the arrays are 0-indexed, then
/// result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
/// result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
/// result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
///
/// Example 2:
/// Input: nums = [1,4,6,8,10]
/// Output: [24,15,13,15,21]
/// Constraints:
/// 1. 2 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= nums[i + 1] <= 10^4
/// </summary>
vector<int> LeetCodeArray::getSumAbsoluteDifferences(vector<int>& nums)
{
    vector<int> result(nums.size());
    int left_count = 0;
    int right_count = 0;
    int left_sum = 0;
    int right_sum = 0;
    for (size_t i = 1; i < nums.size(); i++)
    {
        left_count++;
        left_sum += left_count * (nums[i] - nums[i - 1]);
    }
    result[nums.size() - 1] = left_sum + right_sum;

    for (int i = (int)nums.size() - 2; i >= 0; i--)
    {
        left_sum -= left_count * (nums[i + 1] - nums[i]);
        left_count--;
        right_count++;
        right_sum += right_count * (nums[i + 1] - nums[i]);
        result[i] = left_sum + right_sum;
    }
    return result;
}

/// <summary>
/// Leet code #1695. Maximum Erasure Value
/// 
/// Medium
/// 
/// You are given an array of positive integers nums and want to erase a 
/// subarray containing unique elements. The score you get by erasing 
/// the subarray is equal to the sum of its elements.
///
/// Return the maximum score you can get by erasing exactly one subarray.
///
/// An array b is called to be a subarray of a if it forms a contiguous 
/// subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] 
/// for some (l,r).
/// 
/// Example 1:
/// Input: nums = [4,2,4,5,6]
/// Output: 17
/// Explanation: The optimal subarray here is [2,4,5,6].
///
/// Example 2:
/// Input: nums = [5,2,1,2,5,2,1,2,5]
/// Output: 8
/// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^4
/// </summary>
int LeetCodeArray::maximumUniqueSubarray(vector<int>& nums)
{
    vector<int> num_map(10001);
    int prev = -1;
    int sum = 0;
    int result = INT_MIN;
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_map[nums[i]]++;
        sum += nums[i];
        while (num_map[nums[i]] == 2)           
        {
            prev++;
            sum -= nums[prev];
            num_map[nums[prev]]--;
        }
        result = max(result, sum);
    }
    return result;
}

/// <summary>
/// Leet code #1696. Jump Game VI
/// 
/// Medium
/// 
/// You are given a 0-indexed integer array nums and an integer k.
///
/// You are initially standing at index 0. In one move, you can jump at 
/// most k steps forward without going outside the boundaries of the 
/// array. That is, you can jump from index i to any index in the 
/// range [i + 1, min(n - 1, i + k)] inclusive.
///
/// You want to reach the last index of the array (index n - 1). Your 
/// score is the sum of all nums[j] for each index j you visited in the 
/// array.
///
/// Return the maximum score you can get.
/// 
/// Example 1:
/// Input: nums = [1,-1,-2,4,-7,3], k = 2
/// Output: 7
/// Explanation: You can choose your jumps forming the subsequence 
/// [1,-1,4,3] (underlined above). The sum is 7.
///
/// Example 2:
/// Input: nums = [10,-5,-2,4,0,3], k = 3
/// Output: 17
/// Explanation: You can choose your jumps forming the subsequence 
/// [10,4,3] (underlined above). The sum is 17.
///
/// Example 3:
/// Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
/// Output: 0
///
/// Constraints:
/// 1. 1 <= nums.length, k <= 10^5
/// 2. -10^4 <= nums[i] <= 10^4
/// </summary>
int LeetCodeArray::maxResult(vector<int>& nums, int k)
{
    deque<pair<int, int>> dp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (dp.empty()) dp.push_back(make_pair(nums[i], i));
        else
        {
            if (i - dp.front().second > k) dp.pop_front();
            int sum = dp.front().first + nums[i];
            while (!dp.empty() && sum > dp.back().first)
            {
                dp.pop_back();
            }
            dp.push_back(make_pair(sum, i));
        }
    }
    return dp.back().first;
}

/// <summary>
/// Leet code #1700. Number of Students Unable to Eat Lunch
/// 
/// Easy
/// 
/// The school cafeteria offers circular and square sandwiches at lunch 
/// break, referred to by numbers 0 and 1 respectively. All students 
/// stand in a queue. Each student either prefers square or circular 
/// sandwiches.
///
/// The number of sandwiches in the cafeteria is equal to the number of 
/// students. The sandwiches are placed in a stack. At each step:
///
/// If the student at the front of the queue prefers the sandwich on the 
/// top of the stack, they will take it and leave the queue. 
/// Otherwise, they will leave it and go to the queue's end.
/// This continues until none of the queue students want to take the top 
/// sandwich and are thus unable to eat. 
///
/// You are given two integer arrays students and sandwiches where 
/// sandwiches[i] is the type of the ith sandwich in the stack (i = 0 is 
/// the top of the stack) and students[j] is the preference of the jth 
/// student in the initial queue (j = 0 is the front of the queue). 
/// Return the number of students that are unable to eat.
///
/// Example 1:
/// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
/// Output: 0 
/// Explanation:
/// - Front student leaves the top sandwich and returns to the end of the 
///   line making students = [1,0,0,1].
/// - Front student leaves the top sandwich and returns to the end of the 
///   line making students = [0,0,1,1].
/// - Front student takes the top sandwich and leaves the line making 
///   students = [0,1,1] and sandwiches = [1,0,1].
/// - Front student leaves the top sandwich and returns to the end of 
///   the line making students = [1,1,0].
/// - Front student takes the top sandwich and leaves the line making 
///   students = [1,0] and sandwiches = [0,1].
/// - Front student leaves the top sandwich and returns to the end of the 
///   line making students = [0,1].
/// - Front student takes the top sandwich and leaves the line making 
///   students = [1] and sandwiches = [1].
/// - Front student takes the top sandwich and leaves the line making 
///   students = [] and sandwiches = [].
/// Hence all students are able to eat.
///
/// Example 2:
/// Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
/// Output: 3
///
/// Constraints:
/// 1. 1 <= students.length, sandwiches.length <= 100
/// 2. students.length == sandwiches.length
/// 3. sandwiches[i] is 0 or 1.
/// 4. students[i] is 0 or 1.
/// </summary>
int LeetCodeArray::countStudents(vector<int>& students, vector<int>& sandwiches)
{
    int one = 0;
    int zero = 0;
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i] == 1) one++;
        else zero++;
    }
    int result = students.size();
    for (size_t i = 0; i < sandwiches.size(); i++)
    {
        if (sandwiches[i] == 1) one--;
        else zero--;
        if (one < 0 || zero < 0)
        {
            break;
        }
        result--;
    }
    return result;
}

/// <summary>
/// Leet code #1701. Average Waiting Time
/// 
/// Medium
/// 
/// There is a restaurant with a single chef. You are given an array 
/// customers, where customers[i] = [arrivali, timei]:
///
/// arrivali is the arrival time of the ith customer. The arrival times 
/// are sorted in non-decreasing order.
/// timei is the time needed to prepare the order of the ith customer.
/// When a customer arrives, he gives the chef his order, and the chef 
/// starts preparing it once he is idle. The customer waits till the chef 
/// finishes preparing his order. The chef does not prepare food for more 
/// than one customer at a time. The chef prepares food for customers in 
/// the order they were given in the input.
///
/// Return the average waiting time of all customers. Solutions within 
/// 10-5 from the actual answer are considered accepted.
///
/// Example 1:
/// Input: customers = [[1,2],[2,5],[4,3]]
/// Output: 5.00000
/// Explanation:
/// 1) The first customer arrives at time 1, the chef takes his order and 
///   starts preparing it immediately at time 1, and finishes at time 3, 
///   so the waiting time of the first customer is 3 - 1 = 2.
/// 2) The second customer arrives at time 2, the chef takes his order and 
///    starts preparing it at time 3, and finishes at time 8, so the 
///    waiting time of the second customer is 8 - 2 = 6.
/// 3) The third customer arrives at time 4, the chef takes his order and 
///    starts preparing it at time 8, and finishes at time 11, so the 
///    waiting time of the third customer is 11 - 4 = 7.
/// So the average waiting time = (2 + 6 + 7) / 3 = 5.
///
/// Example 2:
/// Input: customers = [[5,2],[5,4],[10,3],[20,1]]
/// Output: 3.25000
/// Explanation:
/// 1) The first customer arrives at time 5, the chef takes his order and 
///    starts preparing it immediately at time 5, and finishes at time 7, 
///    so the waiting time of the first customer is 7 - 5 = 2.
/// 2) The second customer arrives at time 5, the chef takes his order and 
///    starts preparing it at time 7, and finishes at time 11, so the 
///    waiting time of the second customer is 11 - 5 = 6.
/// 3) The third customer arrives at time 10, the chef takes his order and 
///    starts preparing it at time 11, and finishes at time 14, so the 
///    waiting time of the third customer is 14 - 10 = 4.
/// 4) The fourth customer arrives at time 20, the chef takes his order 
///    and starts preparing it immediately at time 20, and finishes at 
///    time 21, so the waiting time of the fourth customer is 21 - 20 = 1.
/// So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.
/// 
/// Constraints:
/// 1. 1 <= customers.length <= 105
/// 2. 1 <= arrivali, timei <= 104
/// 3. arrivali <= arrivali+1
/// </summary>
double LeetCodeArray::averageWaitingTime(vector<vector<int>>& customers)
{
    double accumulate = 0;
    int wait_time = 0;
    for (size_t i = 0; i < customers.size(); i++)
    {
        if (i > 0)
        {
            wait_time -= customers[i][0] - customers[i - 1][0];
            if (wait_time < 0) wait_time = 0;
        }
        wait_time += customers[i][1];
        accumulate += wait_time;
    }
    return accumulate / (double)customers.size();
}

/// <summary>
/// Leet code #1703. Minimum Adjacent Swaps for K Consecutive Ones
/// 
/// Hard
/// 
/// You are given an integer array, nums, and an integer k. nums comprises 
/// of only 0's and 1's. In one move, you can choose two adjacent indices 
/// and swap their values.
///
/// Return the minimum number of moves required so that nums has k 
/// consecutive 1's.
///
/// Example 1:
/// Input: nums = [1,0,0,1,0,1], k = 2
/// Output: 1
/// Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 
/// 2 consecutive 1's.
///
/// Example 2:
/// Input: nums = [1,0,0,0,0,0,1,1], k = 3
/// Output: 5
/// Explanation: In 5 moves, the leftmost 1 can be shifted right until 
/// nums = [0,0,0,0,0,1,1,1].
///
/// Example 3:
/// Input: nums = [1,1,0,1], k = 2
/// Output: 0
/// Explanation: nums already has 2 consecutive 1's.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. nums[i] is 0 or 1.
/// 3. 1 <= k <= sum(nums)
/// </summary>
int LeetCodeArray::minMoves(vector<int>& nums, int k)
{
    long long sum = 0;
    long long last_sum = 0;
    int result = INT_MAX;
    deque<long long> dp;
    for (size_t i = 0; i < nums.size(); i++)
    {
        // skip all 0
        if (nums[i] == 0) continue;
        // accumulate position sum
        last_sum += i;
        dp.push_back(last_sum);
        if ((int)dp.size() > k)
        {
            sum = dp.front();
            dp.pop_front();
        }
        if (dp.size() == k)
        {
            int median = k / 2;
            long long move = 0;
            if (median > 0)
            {
                long long curr = dp[median] - dp[median - 1];
                long long post_move = dp.back() - dp[median] - ((long long)k - 1 - (long long)median) * curr;
                long long prev_move = median * curr - (dp[median - 1] - sum);
                move = post_move + prev_move;
                int adjust = (1 + median) * median;
                if (k % 2 == 0)
                {
                    adjust -= median;
                }
                move -= adjust;
            }
            result = min(result, (int)move);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1706. Where Will the Ball Fall
/// 
/// Medium
/// 
/// You have a 2-D grid of size m x n representing a box, and you have n 
/// balls. The box is open on the top and bottom sides.
///
/// Each cell in the box has a diagonal board spanning two corners of the 
/// cell that can redirect a ball to the right or to the left.
///
/// A board that redirects the ball to the right spans the top-left corner 
/// to the bottom-right corner and is represented in the grid as 1.
/// A board that redirects the ball to the left spans the top-right corner 
/// to the bottom-left corner and is represented in the grid as -1.
/// We drop one ball at the top of each column of the box. Each ball can 
/// get stuck in the box or fall out of the bottom. A ball gets stuck if 
/// it hits a "V" shaped pattern between two boards or if a board redirects 
/// the ball into either wall of the box.
///
/// Return an array answer of size n where answer[i] is the column that the 
/// ball falls out of at the bottom after dropping the ball from the ith 
/// column at the top, or -1 if the ball gets stuck in the box.
///
/// Example 1:
/// Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],
/// [-1,-1,-1,-1,-1]]
/// Output: [1,-1,-1,-1,-1]
/// Explanation: This example is shown in the photo.
/// Ball b0 is dropped at column 0 and falls out of the box at column 1.
/// Ball b1 is dropped at column 1 and will get stuck in the box between 
/// column 2 and 3 and row 1.
/// Ball b2 is dropped at column 2 and will get stuck on the box between 
/// column 2 and 3 and row 0.
/// Ball b3 is dropped at column 3 and will get stuck on the box between 
/// column 2 and 3 and row 0.
/// Ball b4 is dropped at column 4 and will get stuck on the box between 
/// column 2 and 3 and row 1.
///
/// Example 2:
/// Input: grid = [[-1]]
/// Output: [-1]
/// Explanation: The ball gets stuck against the left wall.
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 100
/// 4. grid[i][j] is 1 or -1.
/// </summary>
vector<int> LeetCodeArray::findBall(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = i;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (result[j] == -1) continue;
            int pos = result[j];
            if (pos > 0 && grid[i][pos - 1] == 1 && grid[i][pos] == -1) result[j] = -1;
            else if (pos < n - 1 && grid[i][pos] == 1 && grid[i][pos + 1] == -1) result[j] = -1;
            else if (pos == 0 && grid[i][pos] == -1) result[j] = -1;
            else if (pos == n - 1 && grid[i][pos] == 1) result[j] = -1;
            else
            {
                result[j] += grid[i][pos];
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1712. Ways to Split Array Into Three Subarrays
/// 
/// Medium
/// 
/// A split of an integer array is good if:
/// The array is split into three non-empty contiguous subarrays - named 
/// left, mid, right respectively from left to right.
/// The sum of the elements in left is less than or equal to the sum of 
/// the elements in mid, and the sum of the elements in mid is less than 
/// or equal to the sum of the elements in right.
/// Given nums, an array of non-negative integers, return the number of 
/// good ways to split nums. As the number may be too large, return it 
/// modulo 10^9 + 7.
///
/// Example 1:
/// Input: nums = [1,1,1]
/// Output: 1
/// Explanation: The only good way to split nums is [1] [1] [1].
///
/// Example 2:
/// Input: nums = [1,2,2,2,5,0]
/// Output: 3
/// Explanation: There are three good ways of splitting nums:
/// [1] [2] [2,2,5,0]
/// [1] [2,2] [2,5,0]
/// [1,2] [2,2] [5,0]
///
/// Example 3:
/// Input: nums = [3,2,1]
/// Output: 0
/// Explanation: There is no good way to split nums.
/// Constraints:
/// 1. 3 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^4
/// </summary>
int LeetCodeArray::waysToSplit(vector<int>& nums)
{
    int M = 1000000007;
    int result = 0;
    int n = nums.size();
    vector<int> sums(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += nums[i];
        sums[i] = s;
    }
    int first = 0;
    int last = 0;
    for (int i = 0; i < n - 2; i++)
    {
        while ((first < n - 1) && (first <= i || sums[first] - sums[i] < sums[i]))
        {
            first++;
        }
        while ((last < n-1) && (last < first || sums[n - 1] - sums[last] >= sums[last] - sums[i]))
        {
            last++;
        }
        if (last > first) result = (result + last - first) % M;
    }
    return result;
}

/// <summary>
/// Leet code 1720. Decode XORed Array
/// 
/// Easy
/// 
/// There is a hidden integer array arr that consists of n non-negative 
/// integers.
///
/// It was encoded into another integer array encoded of length n - 1, 
/// such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if 
/// arr = [1,0,2,1], then encoded = [1,2,3].
///
/// You are given the encoded array. You are also given an integer first, 
/// that is the first element of arr, i.e. arr[0].
/// 
/// Return the original array arr. It can be proved that the answer exists 
/// and is unique.
///
/// Example 1:
/// Input: encoded = [1,2,3], first = 1
/// Output: [1,0,2,1]
/// Explanation: If arr = [1,0,2,1], then first = 1 and encoded = 
/// [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
///
/// Example 2:
/// Input: encoded = [6,2,7,3], first = 4
/// Output: [4,2,0,7,4]
///
/// Constraints:
/// 1. 2 <= n <= 10^4
/// 2. encoded.length == n - 1
/// 3. 0 <= encoded[i] <= 10^5
/// 4. 0 <= first <= 10^5
/// </summary>
vector<int> LeetCodeArray::decode(vector<int>& encoded, int first)
{
    vector<int> result(encoded.size() + 1);
    result[0] = first;

    for (size_t i = 0; i < encoded.size(); i++)
    {
        result[i + 1] = result[i] ^ encoded[i];
    }
    return result;
}

/// <summary>
/// Leet code 1713. Minimum Operations to Make a Subsequence
/// 
/// Hard
/// 
/// You are given an array target that consists of distinct integers and 
/// another integer array arr that can have duplicates.
///
/// In one operation, you can insert any integer at any position in arr. 
/// For example, if arr = [1,4,1,2], you can add 3 in the middle and make 
/// it [1,4,3,1,2]. Note that you can insert the integer at the very 
/// beginning or end of the array.
///
/// Return the minimum number of operations needed to make target a 
/// subsequence of arr.
/// 
/// A subsequence of an array is a new array generated from the original 
/// array by deleting some elements (possibly none) without changing the 
/// remaining elements' relative order. For example, [2,7,4] is a 
//// subsequence of [4,2,3,7,2,1,4] (the underlined elements), while 
/// [2,4,2] is not.
///
/// Example 1:
/// Input: target = [5,1,3], arr = [9,4,2,3,4]
/// Output: 2
/// Explanation: You can add 5 and 1 in such a way that makes 
/// arr = [5,9,4,1,2,3,4], then target will be a subsequence of arr.
///
/// Example 2:
/// Input: target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
/// Output: 3
/// 
/// Constraints:
/// 1. 1 <= target.length, arr.length <= 10^5
/// 2. 1 <= target[i], arr[i] <= 10^9
/// 3. target contains no duplicates.
/// </summary>
int LeetCodeArray::minOperations(vector<int>& target, vector<int>& arr)
{
    unordered_map<int, vector<int>> pos_map;
    for (size_t i = 0; i < arr.size(); i++)
    {
        pos_map[arr[i]].push_back(i);
    }
    set<int> seq;
    for (size_t i = 0; i < target.size(); i++)
    {
        map<int, int> new_map;
        for (size_t j = 0; j < pos_map[target[i]].size(); j++)
        {
            auto itr = seq.lower_bound(pos_map[target[i]][j]);
            int key = 0;
            if (itr == seq.end()) key = INT_MAX;
            else key = *itr;
            if (new_map.count(key) == 0) new_map[key] = pos_map[target[i]][j];
        }
        for (auto itr : new_map)
        {
            if (itr.first == INT_MAX) seq.insert(itr.second);
            else
            {
                seq.erase(itr.first);
                seq.insert(itr.second);
            }
        }
    }
    return target.size() - seq.size();
}

/// <summary>
/// Leet code 1725. Number Of Rectangles That Can Form The Largest Square
/// 
/// Easy
/// 
/// You are given an array rectangles where rectangles[i] = [li, wi] 
/// represents the ith rectangle of length li and width wi.
///
/// You can cut the ith rectangle to form a square with a side length 
/// of k if both k <= li and k <= wi. For example, if you have a 
/// rectangle [4,6], you can cut it to get a square with a side length 
/// of at most 4.
///
/// Let maxLen be the side length of the largest square you can obtain 
/// from any of the given rectangles.
///
/// Return the number of rectangles that can make a square with a side 
/// length of maxLen.
///
/// Example 1:
/// Input: rectangles = [[5,8],[3,9],[5,12],[16,5]]
/// Output: 3
/// Explanation: The largest squares you can get from each rectangle 
/// are of lengths [5,3,5,5].
/// The largest possible square is of length 5, and you can get it 
/// out of 3 rectangles.
///
/// Example 2:
/// Input: rectangles = [[2,3],[3,7],[4,3],[3,7]]
/// Output: 3
///
/// Constraints:
/// 1. 1 <= rectangles.length <= 1000
/// 2. rectangles[i].length == 2
/// 3. 1 <= li, wi <= 109
/// 4. li != wi
/// </summary>
int LeetCodeArray::countGoodRectangles(vector<vector<int>>& rectangles)
{
    int result = 0;
    int max_length = 0;
    for (size_t i = 0; i < rectangles.size(); i++)
    {
        int length = min(rectangles[i][0], rectangles[i][1]);
        if (length > max_length)
        {
            max_length = length;
            result = 1;
        }
        else if (length == max_length)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1726. Tuple with Same Product
/// 
/// Medium
/// 
/// Given an array nums of distinct positive integers, return the number 
/// of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d 
/// are elements of nums, and a != b != c != d.
/// Example 1:
/// Input: nums = [2,3,4,6]
/// Output: 8
/// Explanation: There are 8 valid tuples:
/// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
/// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
///
/// Example 2:
/// Input: nums = [1,2,4,5,10]
/// Output: 16
/// Explanation: There are 16 valids tuples:
/// (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
/// (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
/// (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
/// (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
///
/// Example 3:
/// Input: nums = [2,3,4,6,8,12]
/// Output: 40
///
/// Example 4:
/// Input: nums = [2,3,5,7]
/// Output: 0
///
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. 1 <= nums[i] <= 10^4
/// 3. All elements in nums are distinct.
/// </summary>
int LeetCodeArray::tupleSameProduct(vector<int>& nums)
{
    unordered_map<int, int> products;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            int product = nums[i] * nums[j];

            if (products.count(product) > 0)
            {
                result += products[product];
            }
            products[product]++;
        }
    }
    return result * 8;
}

/// <summary>
/// Leet code 1727. Largest Submatrix With Rearrangements
/// 
/// Medium
/// 
/// You are given a binary matrix matrix of size m x n, and you are 
/// allowed to rearrange the columns of the matrix in any order.
///
/// Return the area of the largest submatrix within matrix where every 
/// element of the submatrix is 1 after reordering the columns optimally.
///
/// Example 1:
/// Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
/// Output: 4
/// Explanation: You can rearrange the columns as shown above.
/// The largest submatrix of 1s, in bold, has an area of 4.
///
/// Example 2:
/// Input: matrix = [[1,0,1,0,1]]
/// Output: 3
/// Explanation: You can rearrange the columns as shown above.
/// The largest submatrix of 1s, in bold, has an area of 3.
///
/// Example 3:
/// Input: matrix = [[1,1,0],[1,0,1]]
/// Output: 2
/// Explanation: Notice that you must rearrange entire columns, and there 
/// is no way to make a submatrix of 1s larger than an area of 2.
///
/// Example 4:
/// Input: matrix = [[0,0],[0,0]]
/// Output: 0
/// Explanation: As there are no 1s, no submatrix of 1s can be formed 
/// and the area is 0.
/// 
/// Constraints:
/// 1. m == matrix.length
/// 2. n == matrix[i].length
/// 3. 1 <= m * n <= 10^5
/// 4. matrix[i][j] is 0 or 1.
/// </summary>
int LeetCodeArray::largestSubmatrix(vector<vector<int>>& matrix)
{
    vector<int> row(matrix[0].size());
    int result = 0;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 1) row[j]++;
            else row[j] = 0;
        }
        vector<int> sorted_row = row;
        sort(sorted_row.begin(), sorted_row.end(), greater<int>());
        for (size_t j = 0; j < sorted_row.size(); j++)
        {
            result = max(result, sorted_row[j] * ((int)j + 1));
        }
    }
    return result;
}

/// <summary>
/// Leet code 1708. Largest Subarray Length K
/// 
/// Easy
/// 
/// An array A is larger than some array B if for the first index i 
/// where A[i] != B[i], A[i] > B[i].
///
/// For example, consider 0-indexing:
///
/// [1,3,2,4] > [1,2,2,4], since at index 1, 3 > 2.
/// [1,4,4,4] < [2,1,1,1], since at index 0, 1 < 2.
/// A subarray is a contiguous subsequence of the array.
///
/// Given an integer array nums of distinct integers, return the largest 
/// subarray of nums of length k.
/// 
/// Example 1:
/// Input: nums = [1,4,5,2,3], k = 3
/// Output: [5,2,3]
/// Explanation: The subarrays of size 3 are: [1,4,5], [4,5,2], 
/// and [5,2,3].
/// Of these, [5,2,3] is the largest.
///
/// Example 2: 
/// Input: nums = [1,4,5,2,3], k = 4
/// Output: [4,5,2,3]
/// Explanation: The subarrays of size 4 are: [1,4,5,2], and [4,5,2,3].
/// Of these, [4,5,2,3] is the largest.
///
/// Example 3:
/// Input: nums = [1,4,5,2,3], k = 1
/// Output: [5]
/// Constraints:
/// 1. 1 <= k <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^9
/// 3. All the integers of nums are unique.
/// Follow up: What if the integers in nums are not distinct?
/// </summary>
vector<int> LeetCodeArray::largestSubarray(vector<int>& nums, int k)
{
    vector<int> result(k);
    int n = nums.size();
    int s = 0; 
    for (int t = 1; t < n - (k - 1); t++)
    {
        if (nums[s] < nums[t])
        {
            s = t;
        }
    }
    for (int i = 0; i < k; i++)
    {
        result[i] = nums[s + i];
    }
    return result;
}

/// <summary>
/// Leet code 1732. Find the Highest Altitude
/// 
/// Easy
/// 
/// There is a biker going on a road trip. The road trip consists of 
/// n + 1 points at different altitudes. The biker starts his trip on 
/// point 0 with altitude equal 0.
///
/// You are given an integer array gain of length n where gain[i] is 
/// the net gain in altitude between points i and i + 1 for all 
/// (0 <= i < n). Return the highest altitude of a point.
/// 
/// Example 1:
/// Input: gain = [-5,1,5,0,-7]
/// Output: 1
/// Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
///
/// Example 2:
/// Input: gain = [-4,-3,-2,-1,4,3,2]
/// Output: 0
/// Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. 
/// The highest is 0.
/// 
/// Constraints:
/// 1. n == gain.length
/// 2. 1 <= n <= 100
/// 3. -100 <= gain[i] <= 100
/// </summary>
int LeetCodeArray::largestAltitude(vector<int>& gain)
{
    int altitude = 0;
    int result = 0;
    for (size_t i = 0; i < gain.size(); i++)
    {
        altitude += gain[i];
        result = max(result, altitude);
    }
    return result;
}

/// <summary>
/// Leet code 1738. Find Kth Largest XOR Coordinate Value 
/// 
/// Medium
/// 
/// You are given a 2D matrix of size m x n, consisting of non-negative 
/// integers. You are also given an integer k.
///
/// The value of coordinate (a, b) of the matrix is the XOR of all 
/// matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
///
/// Find the kth largest value (1-indexed) of all the coordinates of 
/// matrix.
/// 
/// Example 1:
/// Input: matrix = [[5,2],[1,6]], k = 1
/// Output: 7
/// Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is 
/// the largest value.
///
/// Example 2:
/// Input: matrix = [[5,2],[1,6]], k = 2
/// Output: 5
/// Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd 
/// largest value.
///
/// Example 3:
/// Input: matrix = [[5,2],[1,6]], k = 3
/// Output: 4
/// Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is 
/// the 3rd largest value.
///
/// Example 4:
/// Input: matrix = [[5,2],[1,6]], k = 4
/// Output: 0
/// Explanation: The value of coordinate (1,1) is 5 XOR 2 XOR 1 XOR 6 = 0, 
/// which is the 4th largest value.
/// 
/// Constraints:
/// 1. m == matrix.length
/// 2. n == matrix[i].length
/// 3. 1 <= m, n <= 1000
/// 4. 0 <= matrix[i][j] <= 10^6
/// 5. 1 <= k <= m * n
/// </summary>
int LeetCodeArray::kthLargestValue(vector<vector<int>>& matrix, int k)
{
    vector<int> row(matrix[0].size());
    vector<int> sum(matrix[0].size());

    priority_queue<int> heap;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            row[j] = row[j] ^ matrix[i][j];
            if (j == 0)
            {
                sum[j] = row[j];
            }
            else
            {
                sum[j] = sum[j-1] ^ row[j];
            }
            heap.push(sum[j]);
        }
    }
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        result = heap.top();
        heap.pop();
    }
    return result;
}

/// <summary>
/// Leet code 1744. Can You Eat Your Favorite Candy on Your Favorite Day?
/// 
/// Medium
/// 
/// You are given a (0-indexed) array of positive integers candiesCount 
/// where candiesCount[i] represents the number of candies of the ith type 
/// you have. You are also given a 2D array queries where queries[i] = 
/// [favoriteTypei, favoriteDayi, dailyCapi].
///
/// You play a game with the following rules:
///
/// You start eating candies on day 0.
/// You cannot eat any candy of type i unless you have eaten all candies 
/// of type i - 1.
/// You must eat at least one candy per day until you have eaten all the 
/// candies.
/// Construct a boolean array answer such that answer.length == 
/// queries.length and answer[i] is true if you can eat a candy of type 
/// favoriteTypei on day favoriteDayi without eating more than dailyCapi 
/// candies on any day, and false otherwise. Note that you can eat 
/// different types of candy on the same day, provided that you follow 
/// rule 2.
///
/// Return the constructed array answer.
///
/// Example 1:
/// Input: candiesCount = [7,4,5,3,8], 
/// queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
/// Output: [true,false,true]
/// Explanation:
/// 1- If you eat 2 candies (type 0) on day 0 and 2 candies (type 0) on 
///    day 1, you will eat a candy of type 0 on day 2.
/// 2- You can eat at most 4 candies each day.
/// If you eat 4 candies every day, you will eat 4 candies (type 0) on 
/// day 0 and 4 candies (type 0 and type 1) on day 1.
/// On day 2, you can only eat 4 candies (type 1 and type 2), so you 
///  cannot eat a candy of type 4 on day 2.
/// 3- If you eat 1 candy each day, you will eat a candy of type 2 on 
/// day 13.
///
/// Example 2:
/// Input: candiesCount = [5,2,6,4,1], queries = [[3,1,2],[4,10,3],
/// [3,10,100],[4,100,30],[1,3,1]]
/// Output: [false,true,true,false,false]
/// 
/// Constraints:
/// 1. 1 <= candiesCount.length <= 10^5
/// 2. 1 <= candiesCount[i] <= 105
/// 3. 1 <= queries.length <= 105
/// 4. queries[i].length == 3
/// 5. 0 <= favoriteTypei < candiesCount.length
/// 6. 0 <= favoriteDayi <= 10^9
/// 7. 1 <= dailyCapi <= 10^9
/// </summary>
vector<bool> LeetCodeArray::canEat(vector<int>& candiesCount, vector<vector<int>>& queries)
{
    vector<long long> sum(candiesCount.size() + 1);
    for (size_t i = 0; i < candiesCount.size(); i++)
    {
        sum[i + 1] = sum[i] + candiesCount[i];
    }
    vector<bool> result;
    for (size_t i = 0; i < queries.size(); i++)
    {
        int type = queries[i][0];
        int day = queries[i][1];
        int cap = queries[i][2];
        if ((long long)day + 1 > sum[type + 1]) result.push_back(false);
        else if ((long long)cap * (long long)day + 1 <= sum[type]) result.push_back(false);
        else result.push_back(true);
    }
    return result;
}

/// <summary>
/// Leet code 1749. Maximum Absolute Sum of Any Subarray
/// 
/// Medium
/// 
/// You are given an integer array nums. The absolute sum of a subarray 
/// [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + 
/// numsr-1 + numsr).
///
/// Return the maximum absolute sum of any (possibly empty) subarray of 
/// nums.
///
/// Note that abs(x) is defined as follows:
///
/// If x is a negative integer, then abs(x) = -x.
/// If x is a non-negative integer, then abs(x) = x.
///
/// Example 1:
/// Input: nums = [1,-3,2,3,-4]
/// Output: 5
/// Explanation: The subarray [2,3] has absolute sum = abs(2+3) = 
/// abs(5) = 5.
///
/// Example 2:
/// Input: nums = [2,-5,1,-4,3,-2]
/// Output: 8
/// Explanation: The subarray [-5,1,-4] has absolute sum = 
/// abs(-5+1-4) = abs(-8) = 8.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. -10^4 <= nums[i] <= 10^4
/// </summary>
int LeetCodeArray::maxAbsoluteSum(vector<int>& nums)
{
    int result = INT_MIN;
    int min_val = 0;
    int max_val = 0;
    set<int> pre_sum;
    pre_sum.insert(0);
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        result = max(result, abs(sum - min_val));
        result = max(result, abs(sum - max_val));
        min_val = min(min_val, sum);
        max_val = max(max_val, sum);
    }
    return result;
}

/// <summary>
/// Leet code 1769. Minimum Number of Operations to Move All Balls to 
///                 Each Box
/// 
/// Medium
/// 
/// You have n boxes. You are given a binary string boxes of length n, 
/// where boxes[i] is '0' if the ith box is empty, and '1' if it contains 
/// one ball.
///
/// In one operation, you can move one ball from a box to an adjacent box. 
/// Box i is adjacent to box j if abs(i - j) == 1. Note that after doing 
/// so, there may be more than one ball in some boxes.
///
/// Return an array answer of size n, where answer[i] is the minimum number 
/// of operations needed to move all the balls to the ith box.
///
/// Each answer[i] is calculated considering the initial state of the boxes.
/// 
/// Example 1:
///
/// Input: boxes = "110"
/// Output: [1,1,3]
/// Explanation: The answer for each box is as follows:
/// 1) First box: you will have to move one ball from the second box to 
///    the first box in one operation.
/// 2) Second box: you will have to move one ball from the first box to 
///    the second box in one operation.
/// 3) Third box: you will have to move one ball from the first box to the 
///    third box in two operations, and move one ball from the second box 
///    to the third box in one operation.
///
/// Example 2:
/// Input: boxes = "001011"
/// Output: [11,8,5,4,3,4]
/// Constraints:
/// 1. n == boxes.length
/// 2. 1 <= n <= 2000
/// 3. boxes[i] is either '0' or '1'.
/// </summary>
vector<int> LeetCodeArray::minOperations(string boxes)
{
    int n = boxes.size();
    vector<int> sum(n);
    vector<int> dp(n);
    vector<int> result;
    for (int i = 1; i < n; i++)
    {
        if (boxes[i - 1] == '1') dp[i] = 1;
        dp[i] += dp[i - 1];
        sum[i] = sum[i - 1] + dp[i];
    }
    result = sum;
    sum = vector<int>(n);
    dp = vector<int>(n);
    for (int i = n-2; i >= 0; i--)
    {
        if (boxes[i + 1] == '1') dp[i] = 1;
        dp[i] += dp[i + 1];
        sum[i] = sum[i + 1] + dp[i];
        result[i] += sum[i];
    }
    return result;
}

/// <summary>
/// Leet code 1759. Count Number of Homogenous Substrings
/// 
/// Medium
/// 
/// Given a string s, return the number of homogenous substrings of s. 
/// Since the answer may be too large, return it modulo 10^9 + 7.
///
/// A string is homogenous if all the characters of the string are the 
/// same.
///
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: s = "abbcccaa"
/// Output: 13
/// Explanation: The homogenous substrings are listed as below:
/// "a"   appears 3 times.
/// "aa"  appears 1 time.
/// "b"   appears 2 times.
/// "bb"  appears 1 time.
/// "c"   appears 3 times.
/// "cc"  appears 2 times.
/// "ccc" appears 1 time.
/// 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
///
/// Example 2:
/// Input: s = "xy"
/// Output: 2
/// Explanation: The homogenous substrings are "x" and "y".
/// Example 3:
/// Input: s = "zzzzz"
/// Output: 15
///
/// Constraints:
/// 1. 1 <= s.length <= 105
/// 2. s consists of lowercase letters.
/// </summary>
int LeetCodeArray::countHomogenous(string s)
{
    int M = 1000000007;
    int result = 0, sum = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == 0) sum = 1;
        else if (s[i] == s[i - 1]) sum++;
        else sum = 1;
        result = (result + sum) % M;
    }
    return result;
}

/// <summary>
/// Leet code 1764. Form Array by Concatenating Subarrays of Another Array
/// 
/// Medium
/// 
/// You are given a 2D integer array groups of length n. You are also 
/// given an integer array nums.
///
/// You are asked if you can choose n disjoint subarrays from the array 
/// nums such that the ith subarray is equal to groups[i] (0-indexed), 
/// and if i > 0, the (i-1)th subarray appears before the ith subarray 
/// in nums (i.e. the subarrays must be in the same order as groups).
///
/// Return true if you can do this task, and false otherwise.
/// Note that the subarrays are disjoint if and only if there is no 
/// index k such that nums[k] belongs to more than one subarray. A 
/// subarray is a contiguous sequence of elements within an array.
///
/// Example 1:
/// Input: groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
/// Output: true
/// Explanation: You can choose the 0th subarray 
/// as [1,-1,0,1,-1,-1,3,-2,0] and the 1st one as [1,-1,0,1,-1,-1,3,-2,0].
/// These subarrays are disjoint as they share no common nums[k] element.
///
/// Example 2:
/// Input: groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
/// Output: false
/// Explanation: Note that choosing the subarrays [1,2,3,4,10,-2] 
/// and [1,2,3,4,10,-2] is incorrect because they are not in the same 
/// order as in groups.
/// [10,-2] must come before [1,2,3,4].
///
/// Example 3:
/// Input: groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
/// Output: false
/// Explanation: Note that choosing the subarrays [7,7,1,2,3,4,7,7] 
/// and [7,7,1,2,3,4,7,7] is invalid because they are not disjoint.
/// They share a common elements nums[4] (0-indexed).
///
/// Constraints:
/// 1. groups.length == n
/// 2. 1 <= n <= 10^3
/// 3. 1 <= groups[i].length, sum(groups[i].length) <= 10^3
/// 4. 1 <= nums.length <= 10^3
/// 5. -10^7 <= groups[i][j], nums[k] <= 10^7
/// </summary>
bool LeetCodeArray::canChoose(vector<vector<int>>& groups, vector<int>& nums)
{
    int group_id = 0;
    int item_id = 0;
    int index = 0;
    while (group_id < (int)groups.size() && index < (int)nums.size())
    {
        if (groups[group_id][item_id] == nums[index])
        {
            item_id++;
            index++;
            if (item_id == groups[group_id].size())
            {
                group_id++;
                item_id = 0;
            }
        }
        else
        {
            if (item_id != 0) index -= item_id - 1;
            else index++;
            item_id = 0;
        }
    }
    if (group_id == groups.size()) return true;
    else return false;
}

/// <summary>
/// Leet code 1779. Find Nearest Point That Has the Same X or Y Coordinate
/// 
/// Easy
/// 
/// You are given two integers, x and y, which represent your current 
/// location on a Cartesian grid: (x, y). You are also given an array 
/// points where each points[i] = [ai, bi] represents that a point exists 
/// at (ai, bi). A point is valid if it shares the same x-coordinate or 
/// the same y-coordinate as your location.
///
/// Return the index (0-indexed) of the valid point with the smallest 
/// Manhattan distance from your current location. If there are multiple, 
/// return the valid point with the smallest index. If there are no valid 
/// points, return -1.
///
/// The Manhattan distance between two points (x1, y1) and (x2, y2) is 
/// abs(x1 - x2) + abs(y1 - y2).
///
/// Example 1:
/// Input: x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
/// Output: 2
/// Explanation: Of all the points, only [3,1], [2,4] and [4,4] are valid. 
/// Of the valid points, [2,4] and [4,4] have the smallest Manhattan 
/// distance from your current location, with a distance of 1. [2,4] has 
/// the smallest index, so return 2.
///
/// Example 2:
/// Input: x = 3, y = 4, points = [[3,4]]
/// Output: 0
/// Explanation: The answer is allowed to be on the same location as your current location.
///
/// Example 3:
/// Input: x = 3, y = 4, points = [[2,3]]
/// Output: -1
/// Explanation: There are no valid points.
///
/// Constraints:
/// 1. 1 <= points.length <= 10^4
/// 2. points[i].length == 2
/// 3. 1 <= x, y, ai, bi <= 10^4
/// </summary>
int LeetCodeArray::nearestValidPoint(int x, int y, vector<vector<int>>& points)
{
    int min_distance = INT_MAX;
    int result = -1;
    for (size_t i = 0; i < points.size(); i++)
    {
        if (points[i][0] != x && points[i][1] != y) continue;
        int distance = abs(points[i][0] - x) + abs(points[i][1] - y);
        if (distance < min_distance)
        {
            min_distance = distance;
            result = i;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1793. Maximum Score of a Good Subarray
/// 
/// Hard
/// 
/// You are given an array of integers nums (0-indexed) and an integer k.
/// 
/// The score of a subarray (i, j) is defined as min(nums[i], 
/// nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray 
/// where i <= k <= j.
///
/// Return the maximum possible score of a good subarray.
///
/// Example 1:
/// Input: nums = [1,4,3,7,4,5], k = 3
/// Output: 15
/// Explanation: The optimal subarray is (1, 5) with a score of 
/// min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
///
/// Example 2:
/// Input: nums = [5,5,4,5,4,1,1,1], k = 0
/// Output: 20
/// Explanation: The optimal subarray is (0, 4) with a score of 
/// min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 2 * 10^4
/// 3. 0 <= k < nums.length
/// </summary>
int LeetCodeArray::maximumScore(vector<int>& nums, int k)
{
    int n = nums.size();
    priority_queue<pair<int, int>> pq;
    int result = nums[k];
    int min_num = nums[k];
    int count = 1;
    if (k > 0) pq.push(make_pair(nums[k - 1], k - 1));
    if (k < n-1) pq.push(make_pair(nums[k + 1], k + 1));
    while (!pq.empty())
    {
        pair<int, int> pos = pq.top();
        pq.pop();
        if (pos.second < k && pos.second > 0)
        {
            pq.push(make_pair(nums[pos.second - 1], pos.second - 1));
        }
        else if (pos.second > k && pos.second < n - 1)
        {
            pq.push(make_pair(nums[pos.second + 1], pos.second + 1));
        }
        min_num = min(min_num, pos.first);
        count++;
        result = max(min_num * count, result);
    }
    return result;
}

/// <summary>
/// Leet code 1800. Maximum Ascending Subarray Sum
/// 
/// Easy
/// 
/// Given an array of positive integers nums, return the maximum possible 
/// sum of an ascending subarray in nums.
///
/// A subarray is defined as a contiguous sequence of numbers in an array.
///
/// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for 
/// all i where l <= i < r, numsi < numsi+1. Note that a subarray of 
/// size 1 is ascending.
///
/// Example 1:
/// Input: nums = [10,20,30,5,10,50]
/// Output: 65
/// Explanation: [5,10,50] is the ascending subarray with the maximum 
/// sum of 65.
///
/// Example 2:
/// Input: nums = [10,20,30,40,50]
/// Output: 150
/// Explanation: [10,20,30,40,50] is the ascending subarray with the 
/// maximum sum of 150.
///
/// Example 3:
/// Input: nums = [12,17,15,13,10,11,12]
/// Output: 33
/// Explanation: [10,11,12] is the ascending subarray with the maximum 
/// sum of 33.
///
/// Example 4:
/// Input: nums = [100,10,1]
/// Output: 100
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 1 <= nums[i] <= 100
/// </summary>
int LeetCodeArray::maxAscendingSum(vector<int>& nums)
{
    int result = 0, sum = 0, last = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > last) sum += nums[i];
        else sum = nums[i];
        last = nums[i];
        result = max(result, sum);
    }
    return result;
}

/// <summary>
/// Leet code 1806. Minimum Number of Operations to Reinitialize a 
///                 Permutation
/// 
/// Medium
/// 
/// You are given an even integer n. You initially have a permutation 
/// perm of size n where perm[i] == i (0-indexed).
/// In one operation, you will create a new array arr, and for each i:
/// If i % 2 == 0, then arr[i] = perm[i / 2].
/// If i % 2 == 1, then arr[i] = perm[n / 2 + (i - 1) / 2].
/// You will then assign arr to perm.
///
/// Return the minimum non-zero number of operations you need to perform 
/// on perm to return the permutation to its initial value.
///
/// Example 1:
/// Input: n = 2
/// Output: 1
/// Explanation: perm = [0,1] initially.
/// After the 1st operation, perm = [0,1]
/// So it takes only 1 operation.
///
/// Example 2:
/// Input: n = 4
/// Output: 2
/// Explanation: perm = [0,1,2,3] initially.
/// After the 1st operation, perm = [0,2,1,3]
/// After the 2nd operation, perm = [0,1,2,3]
/// So it takes only 2 operations.
///
/// Example 3:
/// Input: n = 6
/// Output: 4
///
/// Constraints:
/// 1. 2 <= n <= 1000
/// 2. n is even.
/// </summary>
int LeetCodeArray::reinitializePermutation(int n)
{
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) nums[i] = i / 2;
        else nums[i] = n / 2 + (i - 1) / 2;
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == -1) continue;
        queue<int> queue;
        queue.push(nums[i]);
        nums[i] = -1;
        int count = 0;
        while (!queue.empty())
        {
            int index = queue.front();
            queue.pop();
            count++;
            if (index == i) break;
            queue.push(nums[index]);
            nums[index] = -1;
        }
        result = max(result, count);
    }
    return result;
}

/// <summary>
/// Leet code 1818. Minimum Absolute Sum Difference
/// 
/// Medium
/// 
/// You are given two positive integer arrays nums1 and nums2, both of 
/// length n.
///
/// The absolute sum difference of arrays nums1 and nums2 is defined as 
/// the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).
///
/// You can replace at most one element of nums1 with any other element 
/// in nums1 to minimize the absolute sum difference.
///
/// Return the minimum absolute sum difference after replacing at most 
/// one element in the array nums1. Since the answer may be large, return 
/// it modulo 10^9 + 7.
///
/// |x| is defined as:
///
/// x if x >= 0, or
/// -x if x < 0.
/// 
/// Example 1:
/// Input: nums1 = [1,7,5], nums2 = [2,3,5]
/// Output: 3
/// Explanation: There are two possible optimal solutions:
/// - Replace the second element with the first: [1,7,5] => [1,1,5], or
/// - Replace the second element with the third: [1,7,5] => [1,5,5].
/// Both will yield an absolute sum difference of 
/// |1-2| + (|1-3| or |5-3|) + |5-5| = 3.
///
/// Example 2:
/// Input: nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
/// Output: 0
/// Explanation: nums1 is equal to nums2 so no replacement is needed. 
/// This will result in an 
/// absolute sum difference of 0.
///
/// Example 3:
/// Input: nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
/// Output: 20
/// Explanation: Replace the first element with the second: 
/// [1,10,4,4,2,7] => [10,10,4,4,2,7].
/// This yields an absolute sum difference of 
/// |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20
///
/// Constraints:
/// 1. n == nums1.length
/// 2. n == nums2.length
/// 3. 1 <= n <= 10^5
/// 4. 1 <= nums1[i], nums2[i] <= 10^5
/// </summary>
int LeetCodeArray::minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2)
{
    set<int> set1(nums1.begin(), nums1.end());
    int delta = 0;
    int M = 1000000007;
    int result = 0;

    for (size_t i = 0; i < nums1.size(); i++)
    {
        int diff = abs(nums1[i] - nums2[i]);
        result = (result + diff) % M;

        auto itr = set1.lower_bound(nums2[i]);
        if (itr != set1.end())
        {
            delta = max(delta, diff - abs(*itr - nums2[i]));
        }
        if (itr != set1.begin())
        {
            delta = max(delta, diff - abs(*prev(itr) - nums2[i]));
        }
    }
    result = (result - delta + M) % M;
    return result;
}

/// <summary>
/// Leet code 1822. Sign of the Product of an Array
/// 
/// Easy
/// 
/// There is a function signFunc(x) that returns:
///
/// 1 if x is positive.
/// -1 if x is negative.
/// 0 if x is equal to 0.
/// You are given an integer array nums. Let product be the product of 
/// all values in the array nums.
///
/// Return signFunc(product).
/// 
/// Example 1:
/// Input: nums = [-1,-2,-3,-4,3,2,1]
/// Output: 1
/// Explanation: The product of all values in the array is 144, and 
/// signFunc(144) = 1
///
/// Example 2:
/// Input: nums = [1,5,0,2,-3]
/// Output: 0
/// Explanation: The product of all values in the array is 0, and 
/// signFunc(0) = 0
///
/// Example 3:
/// Input: nums = [-1,1,-1,1,-1]
/// Output: -1
/// Explanation: The product of all values in the array is -1, and 
/// signFunc(-1) = -1
///
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. -100 <= nums[i] <= 100
/// </summary>
int LeetCodeArray::arraySign(vector<int>& nums)
{
    int result = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0) result = result * 1;
        else if (nums[i] < 0) result = result * -1;
        else
        {
            result = 0;
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1823. Find the Winner of the Circular Game
/// 
/// Medium
/// 
/// There are n friends that are playing a game. The friends are sitting 
/// in a circle and are numbered from 1 to n in clockwise order. More 
/// formally, moving clockwise from the ith friend brings you to the 
/// (i+1)th friend for 1 <= i < n, and moving clockwise from the nth 
/// friend brings you to the 1st friend.
///
/// The rules of the game are as follows:
/// 
/// Start at the 1st friend.
/// Count the next k friends in the clockwise direction including the 
/// friend you started at. The counting wraps around the circle and may 
/// count some friends more than once.
/// The last friend you counted leaves the circle and loses the game.
/// If there is still more than one friend in the circle, go back to 
/// step 2 starting from the friend immediately clockwise of the friend 
/// who just lost and repeat.
/// Else, the last friend in the circle wins the game.
/// Given the number of friends, n, and an integer k, return the winner 
/// of the game.
/// 
/// Example 1:
/// Input: n = 5, k = 2
/// Output: 3
/// Explanation: Here are the steps of the game:
/// 1) Start at friend 1.
/// 2) Count 2 friends clockwise, which are friends 1 and 2.
/// 3) Friend 2 leaves the circle. Next start is friend 3.
/// 4) Count 2 friends clockwise, which are friends 3 and 4.
/// 5) Friend 4 leaves the circle. Next start is friend 5.
/// 6) Count 2 friends clockwise, which are friends 5 and 1.
/// 7) Friend 1 leaves the circle. Next start is friend 3.
/// 8) Count 2 friends clockwise, which are friends 3 and 5.
/// 9) Friend 5 leaves the circle. Only friend 3 is left, so they are the 
///    winner.
///
/// Example 2:
/// Input: n = 6, k = 5
/// Output: 1
/// Explanation: The friends leave in this order: 5, 4, 6, 2, 3. 
/// The winner is friend 1.
///
/// Constraints:
/// 1. 1 <= k <= n <= 500
/// </summary>
int LeetCodeArray::findTheWinner(int n, int k)
{
    list<int> people;
    for (int i = 0; i < n; i++)
    {
        people.push_back(i + 1);
    }  
    auto itr = people.begin();
    auto prev = itr;
    while (people.size() > 1)
    {
        for (int i = 0; i < k; i++)
        {
            prev = itr;
            itr++;
            if (itr == people.end()) itr = people.begin();
        }
        people.erase(prev);
    }
    return *itr;
}

/// <summary>
/// Leet code 1827. Minimum Operations to Make the Array Increasing
/// 
/// Easy
/// 
/// You are given an integer array nums (0-indexed). In one operation, 
/// you can choose an element of the array and increment it by 1.
///
/// For example, if nums = [1,2,3], you can choose to increment nums[1] 
/// to make nums = [1,3,3].
/// Return the minimum number of operations needed to make nums 
/// strictly increasing.
///
/// An array nums is strictly increasing if nums[i] < nums[i+1] for 
/// all 0 <= i < nums.length - 1. An array of length 1 is trivially 
/// strictly increasing.
/// Example 1:
///
/// Input: nums = [1,1,1]
/// Output: 3
/// Explanation: You can do the following operations:
/// 1) Increment nums[2], so nums becomes [1,1,2].
/// 2) Increment nums[1], so nums becomes [1,2,2].
/// 3) Increment nums[2], so nums becomes [1,2,3].
///
/// Example 2:
/// Input: nums = [1,5,2,4,1]
/// Output: 14
///
/// Example 3:
/// Input: nums = [8]
/// Output: 0
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 5000
/// 2. 1 <= nums[i] <= 10^4
/// </summary>
int LeetCodeArray::minOperations(vector<int>& nums)
{
    int last = 0;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (last >= nums[i]) result += last + 1 - nums[i];
        last = max(last + 1, nums[i]);
    }
    return result;
}

/// <summary>
/// Leet code 1762. Buildings With an Ocean View
/// 
/// Medium
/// 
/// There are n buildings in a line. You are given an integer array 
/// heights of size n that represents the heights of the buildings in the 
/// line.
///
/// The ocean is to the right of the buildings. A building has an ocean 
/// view if the building can see the ocean without obstructions. Formally, 
/// a building has an ocean view if all the buildings to its right have a 
/// smaller height.
///
/// Return a list of indices (0-indexed) of buildings that have an ocean 
/// view, sorted in increasing order.
/// 
/// Example 1:
/// Input: heights = [4,2,3,1]
/// Output: [0,2,3]
/// Explanation: Building 1 (0-indexed) does not have an ocean view 
/// because building 2 is taller.
///
/// Example 2:
/// Input: heights = [4,3,2,1]
/// Output: [0,1,2,3]
/// Explanation: All the buildings have an ocean view.
///
/// Example 3:
/// Input: heights = [1,3,2,4]
/// Output: [3]
/// Explanation: Only building 3 has an ocean view.
///
/// Example 4:
/// Input: heights = [2,2,2,2]
/// Output: [3]
/// Explanation: Buildings cannot see the ocean if there are 
/// buildings of the same height to its right.
/// 
/// Constraints:
/// 1. 1 <= heights.length <= 10^5
/// 2. 1 <= heights[i] <= 10^9
/// </summary>
vector<int> LeetCodeArray::findBuildings(vector<int>& heights)
{
    reverse(heights.begin(), heights.end());
    vector<int> result;
    for (size_t i = 0; i < heights.size(); i++)
    {
        if (i == 0)
        {
            result.push_back(0);
        }
        else
        {
            if (heights[i] > heights[result.back()])
            {
                result.push_back(i);
            }
        }
    }
    reverse(heights.begin(), heights.end());
    reverse(result.begin(), result.end());
    for (size_t i = 0; i < result.size(); i++)
    {
        result[i] = heights.size() - 1 - result[i];
    }
    return result;
}


/// <summary>
/// Leet code 1826. Faulty Sensor
/// 
/// Easy
/// 
/// An experiment is being conducted in a lab. To ensure accuracy, there 
/// are two sensors collecting data simultaneously. You are given 2 arrays 
/// sensor1 and sensor2, where sensor1[i] and sensor2[i] are the ith data 
/// points collected by the two sensors.
///
/// However, this type of sensor has a chance of being defective, which 
/// causes exactly one data point to be dropped. After the data is dropped, 
/// all the data points to the right of the dropped data are shifted one 
/// place to the left, and the last data point is replaced with some 
/// random value. It is guaranteed that this random value will not be equal 
/// to the dropped value.
///
/// For example, if the correct data is [1,2,3,4,5] and 3 is dropped, the 
/// sensor could return [1,2,4,5,7] (the last position can be any value, 
/// not just 7).
/// We know that there is a defect in at most one of the sensors. Return 
/// the sensor number (1 or 2) with the defect. If there is no defect in 
/// either sensor or if it is impossible to determine the defective sensor,
/// return -1.
///
/// Example 1:
/// Input: sensor1 = [2,3,4,5], sensor2 = [2,1,3,4]
/// Output: 1
/// Explanation: Sensor 2 has the correct values.
/// The second data point from sensor 2 is dropped, and the last value of 
/// sensor 1 is replaced by a 5.
///
/// Example 2:
/// Input: sensor1 = [2,2,2,2,2], sensor2 = [2,2,2,2,5]
/// Output: -1
/// Explanation: It is impossible to determine which sensor has a defect.
/// Dropping the last value for either sensor could produce the output 
/// for the other sensor.
///
/// Example 3:
/// Input: sensor1 = [2,3,2,2,3,2], sensor2 = [2,3,2,3,2,7]
/// Output: 2
/// Explanation: Sensor 1 has the correct values.
/// The fourth data point from sensor 1 is dropped, and the last value 
/// of sensor 1 is replaced by a 7.
/// 
/// Constraints:
/// 1. sensor1.length == sensor2.length
/// 2. 1 <= sensor1.length <= 100
/// 3. 1 <= sensor1[i], sensor2[i] <= 100
/// </summary>
int LeetCodeArray::badSensor(vector<int>& sensor1, vector<int>& sensor2)
{
    bool broken = false;
    for (size_t i = 0; i < sensor1.size(); i++)
    {
        if (!broken)
        {
            if (sensor1[i] == sensor2[i]) continue;
            else broken = true;
        }
        if (broken)
        {
            if (i == sensor1.size() - 1) return -1;
            if (sensor1[i] == sensor2[i + 1] && sensor1[i + 1] != sensor2[i])
            {
                return 1;
            }
            else if (sensor2[i] == sensor1[i + 1] && sensor2[i + 1] != sensor1[i])
            {
                return 2;
            }
        }
    }
    return -1;
}

/// <summary>
/// Leet code 1838. Frequency of the Most Frequent Element
/// 
/// Medium
/// 
/// The frequency of an element is the number of times it occurs in an 
/// array.
///  
/// You are given an integer array nums and an integer k. In one 
/// operation, you can choose an index of nums and increment the 
/// element at that index by 1.
///
/// Return the maximum possible frequency of an element after performing 
/// at most k operations.
/// 
/// Example 1:
/// Input: nums = [1,2,4], k = 5
/// Output: 3
/// Explanation: Increment the first element three times and the second 
/// element two times to make nums = [4,4,4].
/// 4 has a frequency of 3.
///
/// Example 2: 
/// Input: nums = [1,4,8,13], k = 5
/// Output: 2
/// Explanation: There are multiple optimal solutions:
/// - Increment the first element three times to make nums = [4,4,8,13]. 
///   4 has a frequency of 2.
/// - Increment the second element four times to make nums = [1,8,8,13]. 
///   8 has a frequency of 2.
/// - Increment the third element five times to make nums = [1,4,13,13]. 
///   13 has a frequency of 2.
///
/// Example 3:
/// Input: nums = [3,9,6], k = 2
/// Output: 1
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^5
/// 3. 1 <= k <= 10^5
/// </summary>
int LeetCodeArray::maxFrequency(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end(), greater<int>());
    int sum = 0;
    queue<int> queue;
    size_t index = 0;
    int result = 0;
    while (index <= nums.size())
    {
        if (queue.empty())
        {
            queue.push(nums[index]);
            index++;
        }
        
        if (sum > k)
        {
            int first = queue.front();
            queue.pop();
            sum = sum - (first - queue.front()) * queue.size();
        }
        else
        {
            result = max(result, (int)queue.size());
            if (index < (int)nums.size())
            {
                queue.push(nums[index]);
                sum = sum + queue.front() - nums[index];
            }
            index++;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1840. Maximum Building Height
/// 
/// Hard
/// 
/// You want to build n new buildings in a city. The new buildings will 
/// be built in a line and are labeled from 1 to n.
///
/// However, there are city restrictions on the heights of the new 
/// buildings:
///
/// The height of each building must be a non-negative integer.
/// The height of the first building must be 0.
/// The height difference between any two adjacent buildings cannot 
/// exceed 1.
/// Additionally, there are city restrictions on the maximum height of 
/// specific buildings. These restrictions are given as a 2D integer 
/// array restrictions where restrictions[i] = [idi, maxHeighti] indicates 
/// that building idi must have a height less than or equal to maxHeighti.
///
/// It is guaranteed that each building will appear at most once in 
/// restrictions, and building 1 will not be in restrictions.
///
/// Return the maximum possible height of the tallest building.
/// 
/// Example 1:
/// Input: n = 5, restrictions = [[2,1],[4,1]]
/// Output: 2
/// Explanation: The green area in the image indicates the maximum 
/// allowed height for each building.
/// We can build the buildings with heights [0,1,2,1,2], and the tallest 
/// building has a height of 2.
///
/// Example 2:
/// Input: n = 6, restrictions = []
/// Output: 5
/// Explanation: The green area in the image indicates the maximum 
/// allowed height for each building.
/// We can build the buildings with heights [0,1,2,3,4,5], and the tallest 
/// building has a height of 5.
///
/// Example 3:
/// Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
/// Output: 5
/// Explanation: The green area in the image indicates the maximum allowed 
/// height for each building.
/// We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the 
/// tallest building has a height of 5.
///
/// Constraints:
/// 1. 2 <= n <= 10^9
/// 2. 0 <= restrictions.length <= min(n - 1, 10^5)
/// 3. 2 <= idi <= n
/// 4. idi is unique.
/// 5. 0 <= maxHeighti <= 10^9
/// </summary>
int LeetCodeArray::maxBuilding(int n, vector<vector<int>>& restrictions)
{
    vector<vector<int>> heights = restrictions;
    sort(heights.begin(), heights.end());

    vector<int> prev = { 1, 0 };
    for (size_t i = 0; i < heights.size(); i++)
    {
        heights[i][1] = min(heights[i][1], prev[1] + heights[i][0] - prev[0]);
        prev = heights[i];
    }
    if (heights.size() > 1)
    {
        prev = heights[heights.size() - 1];
        for (int i = heights.size() - 2; i >= 0; i--)
        {
            heights[i][1] = min(heights[i][1], prev[1] + prev[0] - heights[i][0]);
            prev = heights[i];
        }
    }

    prev = { 1, 0 };
    int result = 0;
    for (size_t i = 0; i < heights.size(); i++)
    {
        int h = ((heights[i][0] - prev[0]) + abs(heights[i][1] - prev[1])) / 2 +
            (min(heights[i][1], prev[1]));
        prev = heights[i];
        result = max(result, h);
    }
    result = max(result, prev[1] + n - prev[0]);
    return result;
}

/// <summary>
/// Leet code 1848. Minimum Distance to the Target Element
/// 
/// Easy
/// 
/// Given an integer array nums (0-indexed) and two integers target and 
/// start, find an index i such that nums[i] == target and abs(i - start) 
/// is minimized. Note that abs(x) is the absolute value of x.
/// Return abs(i - start).
/// It is guaranteed that target exists in nums.
///
/// Example 1:
/// Input: nums = [1,2,3,4,5], target = 5, start = 3
/// Output: 1
/// Explanation: nums[4] = 5 is the only value equal to target, so the 
/// answer is abs(4 - 3) = 1.
///
/// Example 2:
/// Input: nums = [1], target = 1, start = 0
/// Output: 0
/// Explanation: nums[0] = 1 is the only value equal to target, so the 
/// answer is abs(0 - 0) = 1.
///
/// Example 3:
/// Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
/// Output: 0
/// Explanation: Every value of nums is 1, but nums[0] minimizes 
/// abs(i - start), which is abs(0 - 0) = 0.
///
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. 1 <= nums[i] <= 104
/// 3. 0 <= start < nums.length
/// 4. target is in nums.
/// </summary>
int LeetCodeArray::getMinDistance(vector<int>& nums, int target, int start)
{
    unordered_map<int, set<int>> num_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_map[nums[i]].insert(i);
    }
    int result = INT_MAX;
    auto itr = num_map[target].lower_bound(start);
    if (itr != num_map[target].end())
    {
        result = min(result, abs(start - *itr));
    }
    if (itr != num_map[target].begin())
    {
        itr = prev(itr);
        result = min(result, abs(start - *itr));
    }
    return result;
}


/// <summary>
/// Leet code 1855. Maximum Distance Between a Pair of Values
/// 
/// Medium
/// 
/// You are given two non-increasing 0-indexed integer arrays nums1
/// and nums2.
///
/// A pair of indices (i, j), where 0 <= i < nums1.length and 
/// 0 <= j < nums2.length, is valid if both i <= j and 
/// nums1[i] <= nums2[j]. The distance of the pair is j - i.
///
/// Return the maximum distance of any valid pair (i, j). If there are 
/// no valid pairs, return 0.
///
/// An array arr is non-increasing if arr[i-1] >= arr[i] for 
/// every 1 <= i < arr.length.
///
/// Example 1:
/// Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
/// Output: 2
/// Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), 
/// (3,3), (3,4), and (4,4).
/// The maximum distance is 2 with pair (2,4).
///
/// Example 2:
/// Input: nums1 = [2,2,2], nums2 = [10,10,1]
/// Output: 1
/// Explanation: The valid pairs are (0,0), (0,1), and (1,1).
/// The maximum distance is 1 with pair (0,1).
///
/// Example 3:
/// Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
/// Output: 2
/// Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
/// The maximum distance is 2 with pair (2,4).
///
/// Example 4:
/// Input: nums1 = [5,4], nums2 = [3,2]
/// Output: 0
/// Explanation: There are no valid pairs, so return 0.
/// 
/// Constraints:
/// 1. 1 <= nums1.length <= 10^5
/// 2. 1 <= nums2.length <= 10^5
/// 3. 1 <= nums1[i], nums2[j] <= 10^5
/// 4. Both nums1 and nums2 are non-increasing.
/// </summary>
int LeetCodeArray::maxDistance(vector<int>& nums1, vector<int>& nums2)
{
    int i = 0; 
    int j = 0;
    int result = 0;
    while (i < (int)nums1.size() && j < (int)nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            result = max(result, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1886. Determine Whether Matrix Can Be Obtained By Rotation
/// 
/// Easy
/// 
/// Given two n x n binary matrices mat and target, return true if it is 
/// possible to make mat equal to target by rotating mat in 90-degree 
/// increments, or false otherwise.
/// 
/// Example 1:
/// Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
/// Output: true
/// Explanation: We can rotate mat 90 degrees clockwise to make mat 
/// equal target.
///
/// Example 2:
/// Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
/// Output: false
/// Explanation: It is impossible to make mat equal to target by rotating 
/// mat.
///
/// Example 3:
/// Input: mat = [[0,0,0],[0,1,0],[1,1,1]], 
/// target = [[1,1,1],[0,1,0],[0,0,0]]
/// Output: true
/// Explanation: We can rotate mat 90 degrees clockwise two times to 
/// make mat equal target.
///
/// Constraints:
/// 1. n == mat.length == target.length
/// 2. n == mat[i].length == target[i].length
/// 2. 1 <= n <= 10
/// 3. mat[i][j] and target[i][j] are either 0 or 1.
/// </summary>
bool LeetCodeArray::findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
{
    bool b_match1 = true, b_match2 = true, b_match3 = true, b_match4 = true;
    int n = mat.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (mat[i][j] != target[j][n - i])  b_match1 = false;
            if (mat[i][j] != target[n - i][n - j])  b_match2 = false;
            if (mat[i][j] != target[n - j][i])  b_match3 = false;
            if (mat[i][j] != target[i][j])  b_match4 = false;
            if (b_match1 == false && b_match2 == false &&
                b_match3 == false && b_match4 == false)
            {
                return false;
            }
        }
    }
    return true;
}

/// <summary>
/// Leet code 1861. Rotating the Box
/// 
/// Medium
/// 
/// You are given an m x n matrix of characters box representing a 
/// side-view of a box. Each cell of the box is one of the following:
///  
/// A stone '#'
/// A stationary obstacle '*'
/// Empty '.'
/// The box is rotated 90 degrees clockwise, causing some of the stones 
/// to fall due to gravity. Each stone falls down until it lands on an 
/// obstacle, another stone, or the bottom of the box. Gravity does not 
/// affect the obstacles' positions, and the inertia from the box's 
/// rotation does not affect the stones' horizontal positions.
///
/// It is guaranteed that each stone in box rests on an obstacle, another 
/// stone, or the bottom of the box.
///
/// Example 1:
/// Input: box = [["#",".","#"]]
/// Output: [["."],
///         ["#"],
///         ["#"]]
///
/// Example 2:
/// Input: box = [["#",".","*","."],
///          ["#","#","*","."]]
/// Output: [["#","."],
///          ["#","#"],
///          ["*","*"],
///          [".","."]]
///
/// Example 3:
/// Input: box = [["#","#","*",".","*","."],
///           ["#","#","#","*",".","."],
///          ["#","#","#",".","#","."]]
/// Output: [[".","#","#"],
///          [".","#","#"],
///          ["#","#","*"],
///          ["#","*","."],
///          ["#",".","*"],
///         ["#",".","."]]
///
/// Constraints:
/// 1. m == box.length
/// 2. n == box[i].length
/// 3. 1 <= m, n <= 500
/// 4. box[i][j] is either '#', '*', or '.'.
/// </summary>
vector<vector<char>> LeetCodeArray::rotateTheBox(vector<vector<char>>& box)
{
    int m = box[0].size();
    int n = box.size();
    vector<int> prev(n, m - 1);
    vector<vector<char>> result(m, vector<char>(n));
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            result[j][n - 1- i] = '.';
            if (box[i][j] == '*')
            {
                result[j][n-1-i] = '*';
                prev[i] = j - 1;
            }
            else if (box[i][j] == '#')
            {
                result[prev[i]][n - 1 - i] = '#';
                prev[i]--;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code 1914. Cyclically Rotating a Grid
/// 
/// Medium
/// 
/// You are given an m x n integer matrix grid where m and n are both 
/// even integers, and an integer k.
///
/// The matrix is composed of several layers, which is shown in the 
/// below image, where each color is its own layer:
/// 
/// A cyclic rotation of the matrix is done by cyclically rotating each 
/// layer in the matrix. To cyclically rotate a layer once, each element 
/// in the layer will take the place of the adjacent element in the 
/// counter-clockwise direction. An example rotation is shown below:
///
/// Return the matrix after applying k cyclic rotations to it.
///
/// Example 1:
/// Input: grid = [[40,10],[30,20]], k = 1
/// Output: [[10,20],[40,30]]
/// Explanation: The figures above represent the grid at every state.
///
/// Example 2:
/// Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
/// Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
/// Explanation: The figures above represent the grid at every state.
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 2 <= m, n <= 50
/// 4. Both m and n are even integers.
/// 5. 1 <= grid[i][j] <= 5000
/// 6. 1 <= k <= 10^9
/// </summary>
vector<vector<int>> LeetCodeArray::rotateGrid(vector<vector<int>>& grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    int t = min(m, n) / 2;
    vector<list<int>> arr(t);
    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < t; i++)
    {
        int r = i;
        for (int c = i; c < n - i; c++)
        {
            arr[i].push_back(grid[r][c]);
        }
        int c = n - 1 - i;
        for (int r = i+1; r < m - 1 - i; r++)
        {
            arr[i].push_back(grid[r][c]);
        }
        r = m - 1 - i;
        for (int c = n - 1 - i; c >= i; c--)
        {
            arr[i].push_back(grid[r][c]);
        }
        c = i;
        for (int r = m - 2 - i; r > i; r--)
        {
            arr[i].push_back(grid[r][c]);
        }
    }
    for (int i = 0; i < t; i++)
    {
        int w = k % arr[i].size();
        for (int j = 0; j < w; j++)
        {
            arr[i].push_back(arr[i].front());
            arr[i].pop_front();
        }
    }
    for (int i = 0; i < t; i++)
    {
        int r = i;
        for (int c = i; c < n - i; c++)
        {
            result[r][c] = arr[i].front();
            arr[i].pop_front();
        }
        int c = n - 1 - i;
        for (int r = i + 1; r < m - 1 - i; r++)
        {
            result[r][c] = arr[i].front();
            arr[i].pop_front();
        }
        r = m - 1 - i;
        for (int c = n - 1 - i; c >= i; c--)
        {
            result[r][c] = arr[i].front();
            arr[i].pop_front();
        }
        c = i;
        for (int r = m - 2 - i; r > i; r--)
        {
            result[r][c] = arr[i].front();
            arr[i].pop_front();
        }
    }
    return result;
}

/// <summary>
/// Leet code 1920. Build Array from Permutation
/// 
/// Easy
/// 
/// Given a zero-based permutation nums (0-indexed), build an array ans 
/// of the same length where ans[i] = nums[nums[i]] for each 
/// 0 <= i < nums.length and return it.
///
/// A zero-based permutation nums is an array of distinct integers from 0 
/// to nums.length - 1 (inclusive).
/// 
/// Example 1:
/// Input: nums = [0,2,1,5,3,4]
/// Output: [0,1,2,4,5,3]
/// Explanation: The array ans is built as follows: 
/// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], 
/// nums[nums[4]], nums[nums[5]]]
/// = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
/// = [0,1,2,4,5,3]
///
/// Example 2:
/// Input: nums = [5,0,1,2,3,4]
/// Output: [4,5,0,1,2,3]
/// Explanation: The array ans is built as follows:
/// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], 
/// nums[nums[4]], nums[nums[5]]]
/// = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
/// = [4,5,0,1,2,3]
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. 0 <= nums[i] < nums.length
/// 3. The elements in nums are distinct.
/// 
/// Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?
/// </summary>
vector<int> LeetCodeArray::buildArray(vector<int>& nums)
{
    vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        result[i] = nums[nums[i]];
    }
    return result;
}

/// <summary>
/// Leet code 1864. Minimum Number of Swaps to Make the Binary String 
///                 Alternating
/// 
/// Medium
/// 
/// Given a binary string s, return the minimum number of character swaps 
/// to make it alternating, or -1 if it is impossible.
///
/// The string is called alternating if no two adjacent characters are 
/// equal. For example, the strings "010" and "1010" are alternating, 
/// while the string "0100" is not.
///
/// Any two characters may be swapped, even if they are not adjacent.
/// 
/// Example 1:
/// Input: s = "111000"
/// Output: 1
/// Explanation: Swap positions 1 and 4: "111000" -> "101010"
/// The string is now alternating.
///
/// Example 2:
/// Input: s = "010"
/// Output: 0
/// Explanation: The string is already alternating, no swaps are needed.
///
/// Example 3:
/// Input: s = "1110"
/// Output: -1
///
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s[i] is either '0' or '1'.
/// </summary>
int LeetCodeArray::minSwaps(string s)
{
    vector<vector<int>> count(2, vector<int>(2));
    for (size_t i = 0; i < s.size(); i++)
    {
        count[i % 2][s[i] - '0']++;
    }
    int result = INT_MAX;
    for (int i = 0; i < 2; i++)
    {
        if (count[0][i] == count[1][1 - i])
        {
            result = min(result, count[0][i]);
        }
    }
    if (result == INT_MAX) result = -1;
    return result;
}

/// <summary>
/// Leet code 1878. Get Biggest Three Rhombus Sums in a Grid
///                  
/// Medium
/// 
/// You are given an m x n integer matrix grid. 
/// A rhombus sum is the sum of the elements that form the border of a 
/// regular rhombus shape in grid???. The rhombus must have the shape 
/// of a square rotated 45 degrees with each of the corners centered 
/// in a grid cell. Below is an image of four valid rhombus shapes 
/// with the corresponding colored cells that should be included in each 
/// rhombus sum:
/// 
/// Note that the rhombus can have an area of 0, which is depicted by 
/// the purple rhombus in the bottom right corner.
///
/// Return the biggest three distinct rhombus sums in the grid in 
/// descending order. If there are less than three distinct values, return 
/// all of them.
/// 
/// Example 1:
/// Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],
///                [1,5,5,4,1],[4,3,2,2,5]]
/// Output: [228,216,211]
/// Explanation: The rhombus shapes for the three biggest distinct rhombus 
/// sums are depicted above.
/// - Blue: 20 + 3 + 200 + 5 = 228
/// - Red: 200 + 2 + 10 + 4 = 216
/// - Green: 5 + 200 + 4 + 2 = 211
///
/// Example 2:
/// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
/// Output: [20,9,8]
/// Explanation: The rhombus shapes for the three biggest distinct 
/// rhombus sums are depicted above.
/// - Blue: 4 + 2 + 6 + 8 = 20
/// - Red: 9 (area 0 rhombus in the bottom right corner)
/// - Green: 8 (area 0 rhombus in the bottom middle)
///
/// Example 3:
/// Input: grid = [[7,7,7]]
/// Output: [7]
/// Explanation: All three possible rhombus sums are the same, so 
/// return [7].
/// 
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 50
/// 4. 1 <= grid[i][j] <= 10^5
/// </summary>
vector<int> LeetCodeArray::getBiggestThree(vector<vector<int>>& grid)
{
    set<int> result;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> sum0(n, vector<vector<int>>(m, vector<int>(n)));
    vector<vector<vector<int>>> sum1(n, vector<vector<int>>(m, vector<int>(n)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum_f = grid[i][j];
            int sum_r = grid[i][j];
            for (int k = 0; i - k >= 0 && i + k < n; k++)
            {
                if (k > 0)
                {
                    int y0 = i - k;
                    int y1 = i + k;
                    int x0 = j - k;
                    int x1 = j + k;
                    if (x0 >= 0) sum_r += grid[y0][x0] + grid[y1][x0];
                    if (x1 < m) sum_f += grid[y0][x1] + grid[y1][x1];
                }
                sum0[i][j][k] = sum_r;
                sum1[i][j][k] = sum_f;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; i - k >= 0 && i + k < n && j + 2 * k < m; k++)
            {          
                int sum = sum1[i][j][k];
                if (k > 0) sum += sum0[i][j + 2 * k][k - 1];
                result.insert(sum);
                if (result.size() > 3) result.erase(result.begin());
            }
        }
    }
    return vector<int>(result.rbegin(), result.rend());
}

/// <summary>
/// Leet code 1895. Largest Magic Square
///                  
/// Medium
/// 
/// A k x k magic square is a k x k grid filled with integers such that 
/// every row sum, every column sum, and both diagonal sums are all equal. 
/// The integers in the magic square do not have to be distinct. Every 
/// 1 x 1 grid is trivially a magic square.
///
/// Given an m x n integer grid, return the size (i.e., the side length k) 
/// of the largest magic square that can be found within this grid.
///
/// Example 1:
/// Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
/// Output: 3
/// Explanation: The largest magic square has a size of 3.
/// Every row sum, column sum, and diagonal sum of this magic square is 
/// equal to 12.
/// - Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
/// - Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
/// - Diagonal sums: 5+4+3 = 6+4+2 = 12
///
/// Example 2:
/// Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
/// Output: 2
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 50
/// 4. 1 <= grid[i][j] <= 10^6
/// </summary>
int LeetCodeArray::largestMagicSquare(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> row(n+1, vector<int>(m+1));
    vector<vector<int>> col(n+1, vector<int>(m+1));
    vector<vector<int>> diag1(n+1, vector<int>(m+1));
    vector<vector<int>> diag2(n+1, vector<int>(m+2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            row[i][j] = grid[i-1][j-1] + row[i][j - 1];
            col[i][j] = grid[i-1][j-1] + col[i - 1][j];
            diag1[i][j] = grid[i-1][j-1] + diag1[i-1][j-1];
            diag2[i][j] = grid[i - 1][j - 1] + diag2[i - 1][j + 1];
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int k = min(i, j);
            while (k > result)
            {
                bool match = false;
                int sum = diag1[i][j] - diag1[i - k][j - k];
                match = (sum == (diag2[i][j - k + 1] - diag2[i - k][j + 1]));
                if (match == true)
                {
                    for (int l = 0; l < k; l++)
                    {
                        match = (sum == (row[i - l][j] - row[i - l][j - k]));
                        if (match == false) break;
                        match = (sum == (col[i][j-l] - col[i - k][j - l]));
                        if (match == false) break;
                    }
                }
                if (match == true)
                {
                    result = max(result, k);
                    break;
                }
                k--;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code 1888. Minimum Number of Flips to Make the Binary String 
///                 Alternating
///                  
/// Medium
/// 
/// You are given a binary string s. You are allowed to perform two types 
/// of operations on the string in any sequence:
///
/// Type-1: Remove the character at the start of the string s and append 
/// it to the end of the string.
/// Type-2: Pick any character in s and flip its value, i.e., if its value 
/// is '0' it becomes '1' and vice-versa.
/// Return the minimum number of type-2 operations you need to perform 
/// such that s becomes alternating.
///
/// The string is called alternating if no two adjacent characters are 
/// equal.
///
/// For example, the strings "010" and "1010" are alternating, while the 
/// string "0100" is not.
/// Example 1:
///
/// Input: s = "111000"
/// Output: 2
/// Explanation: Use the first operation two times to make s = "100011".
/// Then, use the second operation on the third and sixth elements to 
/// make s = "101010".
///
/// Example 2:
/// Input: s = "010"
/// Output: 0
/// Explanation: The string is already alternating.
///
/// Example 3:
/// Input: s = "1110"
/// Output: 1
/// Explanation: Use the second operation on the second element to 
/// make s = "1010".
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s[i] is either '0' or '1'.
/// </summary>
int LeetCodeArray::minFlips(string s)
{
    vector<vector<int>>count(2, vector<int>(2));
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        count[i % 2][s[i] - '0']++;
    }
    int result = count[0][0] + count[1][1];
    result = min(result, count[0][1] + count[1][0]);
    for (int i = 0; i < n; i++)
    {
        count[i % 2][s[i] - '0']--;
        count[(n + i) % 2][s[i] - '0']++;
        result = min(result, count[0][0] + count[1][1]);
        result = min(result, count[0][1] + count[1][0]);
    }
    return result;
}

/// <summary>
/// Leet code 1894. Find the Student that Will Replace the Chalk
///                                  
/// Medium
/// 
/// There are n students in a class numbered from 0 to n - 1. The teacher 
/// will give each student a problem starting with the student number 0, 
/// then the student number 1, and so on until the teacher reaches the 
/// student number n - 1. After that, the teacher will restart the process,
/// starting with the student number 0 again.
/// You are given a 0-indexed integer array chalk and an integer k. There 
/// are initially k pieces of chalk. When the student number i is given a 
/// problem to solve, they will use chalk[i] pieces of chalk to solve that 
/// problem. However, if the current number of chalk pieces is strictly 
/// less than chalk[i], then the student number i will be asked to replace 
/// the chalk.
///
/// Return the index of the student that will replace the chalk.
/// Example 1:
/// Input: chalk = [5,1,5], k = 22
/// Output: 0
/// Explanation: The students go in turns as follows:
/// - Student number 0 uses 5 chalk, so k = 17.
/// - Student number 1 uses 1 chalk, so k = 16.
/// - Student number 2 uses 5 chalk, so k = 11.
/// - Student number 0 uses 5 chalk, so k = 6.
/// - Student number 1 uses 1 chalk, so k = 5.
/// - Student number 2 uses 5 chalk, so k = 0.
/// Student number 0 does not have enough chalk, so they will have to 
/// replace it.
///
/// Example 2:
/// Input: chalk = [3,4,1,2], k = 25
/// Output: 1
/// Explanation: The students go in turns as follows:
/// - Student number 0 uses 3 chalk so k = 22.
/// - Student number 1 uses 4 chalk so k = 18.
/// - Student number 2 uses 1 chalk so k = 17.
/// - Student number 3 uses 2 chalk so k = 15.
/// - Student number 0 uses 3 chalk so k = 12.
/// - Student number 1 uses 4 chalk so k = 8.
/// - Student number 2 uses 1 chalk so k = 7.
/// - Student number 3 uses 2 chalk so k = 5.
/// - Student number 0 uses 3 chalk so k = 2.
/// Student number 1 does not have enough chalk, so they will have to 
/// replace it.
/// 
/// Constraints:
/// 1. chalk.length == n
/// 2. 1 <= n <= 10^5
/// 3. 1 <= chalk[i] <= 10^5
/// 4. 1 <= k <= 10^9
/// </summary>
int LeetCodeArray::chalkReplacer(vector<int>& chalk, int k)
{
    long long sum = 0;
    for (size_t i = 0; i < chalk.size(); i++)
    {
        sum += chalk[i];
    }
    k = k % sum;
    for (size_t i = 0; i < chalk.size(); i++)
    {
        if (k < chalk[i]) return i;
        k -= chalk[i];
    }
    return -1;
}

/// <summary>
/// Leet code 1929. Concatenation of Array
///                                                
/// Easy
/// 
/// Given an integer array nums of length n, you want to create an array 
/// ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] 
/// for 0 <= i < n (0-indexed).
///
/// Specifically, ans is the concatenation of two nums arrays.
///
/// Return the array ans.
/// 
/// Example 1:
/// Input: nums = [1,2,1]
/// Output: [1,2,1,1,2,1]
/// Explanation: The array ans is formed as follows:
/// - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
/// - ans = [1,2,1,1,2,1]
///
/// Example 2:
/// Input: nums = [1,3,2,1]
/// Output: [1,3,2,1,1,3,2,1]
/// Explanation: The array ans is formed as follows:
/// - ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],
///          nums[3]]
/// - ans = [1,3,2,1,1,3,2,1]
/// 
/// Constraints:
/// 1. n == nums.length
/// 2. 1 <= n <= 1000
/// 3. 1 <= nums[i] <= 1000
/// </summary>
vector<int> LeetCodeArray::getConcatenation(vector<int>& nums)
{
    vector<int> result(nums.size() * 2);
    for (size_t i = 0; i < result.size(); i++)
    {
        result[i] = nums[i % nums.size()];
    }
    return result;
}

/// <summary>
/// Leet code 2006. Count Number of Pairs With Absolute Difference K
///                                                
/// Easy
/// 
/// Given an integer array nums and an integer k, return the number of 
/// pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
///
/// The value of |x| is defined as:
///
/// x if x >= 0.
/// -x if x < 0.
///
/// Example 1:
/// Input: nums = [1,2,2,1], k = 1
/// Output: 4
/// Explanation: The pairs with an absolute difference of 1 are:
/// - [1,2,2,1]
/// - [1,2,2,1]
/// - [1,2,2,1]
/// - [1,2,2,1]
///
/// Example 2:
/// Input: nums = [1,3], k = 3
/// Output: 0
/// Explanation: There are no pairs with an absolute difference of 3.
///
/// Example 3:
/// Input: nums = [3,2,1,5,4], k = 2
/// Output: 3
/// Explanation: The pairs with an absolute difference of 2 are:
/// - [3,2,1,5,4]
/// - [3,2,1,5,4]
/// - [3,2,1,5,4]
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 200
/// 2. 1 <= nums[i] <= 100
/// 3. 1 <= k <= 99
/// </summary>
int LeetCodeArray::countKDifference(vector<int>& nums, int k)
{
    vector<int> arr(101);
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] - k >= 1)
        {
            result += arr[nums[i] - k];
        }
        if (nums[i] + k <= 100)
        {
            result += arr[nums[i] + k];
        }
        arr[nums[i]]++;
    }
    return result;
}

/// <summary>
/// Leet code 2016. Maximum Difference Between Increasing Elements
///                                                
/// Easy
/// 
/// Given a 0-indexed integer array nums of size n, find the maximum 
/// difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), 
/// such that 0 <= i < j < n and nums[i] < nums[j].
/// Return the maximum difference. If no such i and j exists, return -1.
/// 
/// Example 1:
/// Input: nums = [7,1,5,4]
/// Output: 4
/// Explanation:
/// The maximum difference occurs with i = 1 and j = 2, 
/// nums[j] - nums[i] = 5 - 1 = 4.
/// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] 
/// = 7 - 1 = 6, but i > j, so it is not valid.
///
/// Example 2:
/// Input: nums = [9,4,3,2]
/// Output: -1
/// Explanation:
/// There is no i and j such that i < j and nums[i] < nums[j].
///
/// Example 3:
/// Input: nums = [1,5,2,10]
/// Output: 9
/// Explanation:
/// The maximum difference occurs with i = 0 and j = 3, 
/// nums[j] - nums[i] = 10 - 1 = 9.
/// 
/// Constraints:
/// 1. n == nums.length
/// 2. 2 <= n <= 1000
/// 3. 1 <= nums[i] <= 10^9
/// </summary>
int LeetCodeArray::maximumDifference(vector<int>& nums)
{
    int min_val = INT_MAX;
    int result = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        result = max(result, nums[i] - min_val);
        min_val = min(min_val, nums[i]);
    }
    return result == 0 ? -1 : result;
}

/// <summary>
/// Leet code 2022. Convert 1D Array Into 2D Array
///                                                
/// Easy
/// 
/// You are given a 0-indexed 1-dimensional (1D) integer array original, 
/// and two integers, m and n. You are tasked with creating a 
/// 2-dimensional (2D) array with m rows and n columns using all the 
/// elements from original.
///
/// The elements from indices 0 to n - 1 (inclusive) of original should 
/// form the first row of the constructed 2D array, the elements from 
/// indices n to 2 * n - 1 (inclusive) should form the second row of 
/// the constructed 2D array, and so on.
///
/// Return an m x n 2D array constructed according to the above 
/// procedure, or an empty 2D array if it is impossible.
/// 
/// Example 1:
/// Input: original = [1,2,3,4], m = 2, n = 2
/// Output: [[1,2],[3,4]]
/// Explanation:
/// The constructed 2D array should contain 2 rows and 2 columns.
/// The first group of n=2 elements in original, [1,2], becomes the first 
/// row in the constructed 2D array.
/// The second group of n=2 elements in original, [3,4], becomes the 
/// second row in the constructed 2D array.
///
/// Example 2:
/// Input: original = [1,2,3], m = 1, n = 3
/// Output: [[1,2,3]]
/// Explanation:
/// The constructed 2D array should contain 1 row and 3 columns.
/// Put all three elements in original into the first row of the 
/// constructed 2D array.
///
/// Example 3:
/// Input: original = [1,2], m = 1, n = 1
/// Output: []
/// Explanation:
/// There are 2 elements in original.
/// It is impossible to fit 2 elements in a 1x1 2D array, so return an 
/// empty 2D array.
///
/// Example 4:
/// Input: original = [3], m = 1, n = 2
/// Output: []
/// Explanation:
/// There is 1 element in original.
/// It is impossible to make 1 element fill all the spots in a 1x2 2D 
/// array, so return an empty 2D array.
/// 
/// Constraints:
/// 1. 1 <= original.length <= 5 * 10^4
/// 2. 1 <= original[i] <= 10^5
/// 3. 1 <= m, n <= 4 * 10^4
/// </summary>
vector<vector<int>> LeetCodeArray::construct2DArray(vector<int>& original, int m, int n)
{
    vector<vector<int>> result;
    if (m * n != original.size())
    {
        return result;
    }
    for (int i = 0; i < m; i++)
    {
        result.push_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            result[i].push_back(original[i * n + j]);
        }
    }
    return result;
}

/// <summary>
/// Leet code 2057. Smallest Index With Equal Value
///                                                
/// Easy
/// 
/// Given a 0-indexed integer array nums, return the smallest index i of 
/// nums such that i mod 10 == nums[i], or -1 if such index does not exist.
/// 
/// x mod y denotes the remainder when x is divided by y.
/// Example 1:
/// Input: nums = [0,1,2]
/// Output: 0
/// Explanation: 
/// i=0: 0 mod 10 = 0 == nums[0].
/// i=1: 1 mod 10 = 1 == nums[1].
/// i=2: 2 mod 10 = 2 == nums[2].
/// All indices have i mod 10 == nums[i], so we return the smallest 
/// index 0.
/// Example 2:
///
/// Input: nums = [4,3,2,1]
/// Output: 2
/// Explanation: 
/// i=0: 0 mod 10 = 0 != nums[0].
/// i=1: 1 mod 10 = 1 != nums[1].
/// i=2: 2 mod 10 = 2 == nums[2].
/// i=3: 3 mod 10 = 3 != nums[3].
/// 2 is the only index which has i mod 10 == nums[i].
///
/// Example 3:
/// Input: nums = [1,2,3,4,5,6,7,8,9,0]
/// Output: -1
/// Explanation: No index satisfies i mod 10 == nums[i].
///
/// Example 4:
/// Input: nums = [2,1,3,5,2]
/// Output: 1
/// Explanation: 1 is the only index with i mod 10 == nums[i].
///
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 0 <= nums[i] <= 9
/// </summary>
int LeetCodeArray::smallestEqual(vector<int>& nums)
{
    int result = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (result == -1 && i % 10 == nums[i])
        {
            result = i;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1991. Find the Middle Index in Array
///                                                
/// Easy
/// 
/// Given a 0-indexed integer array nums, find the leftmost middleIndex 
/// (i.e., the smallest amongst all the possible ones).
///
/// A middleIndex is an index where nums[0] + nums[1] + ... + 
/// nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] 
/// + ... + nums[nums.length-1].
///
/// If middleIndex == 0, the left side sum is considered to be 0. 
/// Similarly, if middleIndex == nums.length - 1, the right side sum is 
/// considered to be 0.
///
/// Return the leftmost middleIndex that satisfies the condition, or -1 
/// if there is no such index.
/// 
/// Example 1:
/// Input: nums = [2,3,-1,8,4]
/// Output: 3
/// Explanation:
/// The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
/// The sum of the numbers after index 3 is: 4 = 4
///
/// Example 2:
/// Input: nums = [1,-1,4]
/// Output: 2
/// Explanation:
/// The sum of the numbers before index 2 is: 1 + -1 = 0
/// The sum of the numbers after index 2 is: 0
///
/// Example 3:
/// Input: nums = [2,5]
/// Output: -1
/// Explanation:
/// There is no valid middleIndex.
///
/// Example 4:
/// Input: nums = [1]
/// Output: 0
/// Explantion:
/// The sum of the numbers before index 0 is: 0
/// The sum of the numbers after index 0 is: 0
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. -1000 <= nums[i] <= 1000
/// </summary>
int LeetCodeArray::findMiddleIndex(vector<int>& nums)
{
    vector<int> dp(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i == 0) dp[i] = nums[0];
        else dp[i] = dp[i - 1] + nums[i];
    }
    int result = -1;
    for (size_t i = 0; i < dp.size(); i++)
    {
        int left = 0;
        int right = 0;
        if (i > 0) left = dp[i - 1];
        if (i < dp.size() - 1)
        {
            right = dp[dp.size() - 1] - dp[i];
        }
        if (left == right)
        {
            result = i;
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1930. Unique Length-3 Palindromic Subsequences
///                                                                 
/// Medium
/// 
/// Given a string s, return the number of unique palindromes of length 
/// three that are a subsequence of s.
///
/// Note that even if there are multiple ways to obtain the same 
/// subsequence, it is still only counted once.
///
/// A palindrome is a string that reads the same forwards and backwards.
///
/// A subsequence of a string is a new string generated from the original 
/// string with some characters (can be none) deleted without changing 
/// the relative order of the remaining characters.
///
/// For example, "ace" is a subsequence of "abcde".
/// Example 1:
/// Input: s = "aabca"
/// Output: 3
/// Explanation: The 3 palindromic subsequences of length 3 are:
/// - "aba" (subsequence of "aabca")
/// - "aaa" (subsequence of "aabca")
/// - "aca" (subsequence of "aabca")
///
/// Example 2:
/// Input: s = "adc"
/// Output: 0
/// Explanation: There are no palindromic subsequences of length 3 
/// in "adc".
///
/// Example 3:
/// Input: s = "bbcbaba"
/// Output: 4
/// Explanation: The 4 palindromic subsequences of length 3 are:
/// - "bbb" (subsequence of "bbcbaba")
/// - "bcb" (subsequence of "bbcbaba")
/// - "bab" (subsequence of "bbcbaba")
/// - "aba" (subsequence of "bbcbaba")
/// 
/// Constraints:
/// 1. 3 <= s.length <= 10^5
/// 2. s consists of only lowercase English letters.
/// </summary>
int LeetCodeArray::countPalindromicSubsequence(string s)
{
    vector<vector<int>> char_arr(26);
    vector<int> char_total(26);
    vector<int> char_count(26);

    for (size_t i = 0; i < s.size(); i++)
    {
        char_count[s[i] - 'a']++;
        if (char_arr[s[i] - 'a'].empty())
        {
            char_arr[s[i] - 'a'] = char_count;
            continue;
        }
        int count = 0;
        for (size_t j = 0; j < 26; j++)
        {
            if (char_count[j] > char_arr[s[i] - 'a'][j] && j != s[i] - 'a') count++;
            if (char_count[j] > char_arr[s[i] - 'a'][j] + 1 && j == s[i] - 'a') count++;
        }
        char_total[s[i] - 'a'] = max(char_total[s[i] - 'a'], count);
    }
    int result = 0;
    for (size_t i = 0; i < 26; i++)
    {
        result += char_total[i];
    }
    return result;
}


/// <summary>
/// Leet code 2009. Minimum Number of Operations to Make Array Continuous
///                                                                 
/// Hard
/// 
/// You are given an integer array nums. In one operation, you can replace 
/// any element in nums with any integer.
///
/// nums is considered continuous if both of the following conditions are 
/// fulfilled:
///
/// All elements in nums are unique.
/// The difference between the maximum element and the minimum element in 
/// nums equals nums.length - 1.
/// For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 
/// 5, 6] is not continuous.
///
/// Return the minimum number of operations to make nums continuous.
///
/// Example 1:
/// Input: nums = [4,2,5,3]
/// Output: 0
/// Explanation: nums is already continuous.
///
/// Example 2:
/// Input: nums = [1,2,3,5,6]
/// Output: 1
/// Explanation: One possible solution is to change the last element to 4.
/// The resulting array is [1,2,3,5,4], which is continuous.
///
/// Example 3:
/// Input: nums = [1,10,100,1000]
/// Output: 3
/// Explanation: One possible solution is to:
/// - Change the second element to 2.
/// - Change the third element to 3.
/// - Change the fourth element to 4.
///
/// The resulting array is [1,2,3,4], which is continuous.
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^9
/// </summary>
int LeetCodeArray::minOperationsII(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n);
    int result = n;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1];
        if (nums[i] == nums[i - 1]) dp[i]++;
    }
    for (int i = 0; i < n; i++)
    {
        auto itr = lower_bound(nums.begin() + i, nums.end(), nums[i] + n);
        int count = (itr - (nums.begin() + i));
        count -= dp[i + count - 1] - dp[i];
        result = min(result, n - count);
    }
    return result;
}

/// <summary>
/// Leet code 1936. Add Minimum Number of Rungs
///                                                                 
/// Medium
/// 
/// You are given a strictly increasing integer array rungs that represents
/// the height of rungs on a ladder. You are currently on the floor at 
/// height 0, and you want to reach the last rung.
///
/// You are also given an integer dist. You can only climb to the next 
/// highest rung if the distance between where you are currently at (the 
/// floor or on a rung) and the next rung is at most dist. You are able to 
/// insert rungs at any positive integer height if a rung is not already 
/// there.
///
/// Return the minimum number of rungs that must be added to the ladder in 
/// order for you to climb to the last rung.
/// 
/// Example 1:
/// Input: rungs = [1,3,5,10], dist = 2
/// Output: 2
/// Explanation:
/// You currently cannot reach the last rung.
/// Add rungs at heights 7 and 8 to climb this ladder. 
/// The ladder will now have rungs at [1,3,5,7,8,10].
///
/// Example 2:
/// Input: rungs = [3,6,8,10], dist = 3
/// Output: 0
/// Explanation:
/// This ladder can be climbed without adding additional rungs.
///
/// Example 3:
/// Input: rungs = [3,4,6,7], dist = 2
/// Output: 1
/// Explanation:
/// You currently cannot reach the first rung from the ground.
/// Add a rung at height 1 to climb this ladder.
/// The ladder will now have rungs at [1,3,4,6,7].
///
/// Example 4:
/// Input: rungs = [5], dist = 10
/// Output: 0
/// Explanation:
/// This ladder can be climbed without adding additional rungs.
/// 
/// Constraints:
/// 1. 1 <= rungs.length <= 10^5
/// 2. 1 <= rungs[i] <= 10^9
/// 3. 1 <= dist <= 10^9
/// 4. rungs is strictly increasing.
/// </summary>
int LeetCodeArray::addRungs(vector<int>& rungs, int dist)
{
    int result = 0;
    int prev = 0;
    for (size_t i = 0; i < rungs.size(); i++)
    {
        result += (rungs[i] - prev + dist - 1) / dist - 1;
        prev = rungs[i];
    }
    return result;
}

/// <summary>
/// Leet code 2025. Maximum Number of Ways to Partition an Array
///                                                                 
/// Hard
/// 
/// You are given a 0-indexed integer array nums of length n. The number 
/// of ways to partition nums is the number of pivot indices that satisfy 
/// both conditions:
///
/// 1 <= pivot < n
/// nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + 
/// nums[pivot + 1] + ... + nums[n - 1]
/// You are also given an integer k. You can choose to change the value 
/// of one element of nums to k, or to leave the array unchanged.
///
/// Return the maximum possible number of ways to partition nums to 
/// satisfy both conditions after changing at most one element.
/// 
/// Example 1:
/// Input: nums = [2,-1,2], k = 3
/// Output: 1
/// Explanation: One optimal approach is to change nums[0] to k. 
/// The array becomes [3,-1,2].
/// There is one way to partition the array:
/// - For pivot = 2, we have the partition [3,-1 | 2]: 3 + -1 == 2.
///
/// Example 2:
/// 
/// Input: nums = [0,0,0], k = 1
/// Output: 2
/// Explanation: The optimal approach is to leave the array unchanged.
/// There are two ways to partition the array:
/// - For pivot = 1, we have the partition [0 | 0,0]: 0 == 0 + 0.
/// - For pivot = 2, we have the partition [0,0 | 0]: 0 + 0 == 0.
///
/// Example 3:
/// Input: nums = [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14], k = -33
/// Output: 4
/// Explanation: One optimal approach is to change nums[2] to k. The 
/// array becomes [22,4,-33,-20,-15,15,-16,7,19,-10,0,-13,-14].
/// There are four ways to partition the array.
/// 
/// Constraints:
/// 1. n == nums.length
/// 2. 2 <= n <= 10^5
/// 3. -10^5 <= k, nums[i] <= 10^5
/// </summary>
int LeetCodeArray::waysToPartition(vector<int>& nums, int k)
{
    vector<long long> sum(nums.size());
    unordered_map<long long, int> left, right, left_count, right_count;
    left[nums[0]]++;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum[i] = nums[i];
        if (i > 0)
        {
            sum[i] += sum[i - 1];
            right[nums[i]]++;
        }
    }
    int result = 0;
    int update = 0;
    for (size_t p = 1; p < nums.size(); p++)
    {
        long long left_sum = sum[p - 1];
        long long right_sum = sum[nums.size() - 1] - sum[p - 1];
        long long delta = right_sum - left_sum;
        if (left_sum == right_sum)
        {
            result++;
        }
        else if (left.count(k - delta) > 0)
        {
            left_count[k - delta]++;
            update = max(update, left_count[k - delta]);
        }
        else if (right.count(k + delta) > 0)
        {
            right_count[k + delta]++;
            update = max(update, right_count[k + delta]);
        }

        left[nums[p]]++;
        left_count[nums[p]] = max(left_count[nums[p]], right_count[nums[p]]);
        right[nums[p]]--;
        if (right[nums[p]] == 0)
        {
            right.erase(nums[p]);
            right_count.erase(nums[p]);
        }
    }
    result = max(result, update);
    return result;
}

/// <summary>
/// Leet 1937. Maximum Number of Points with Cost
///                                                                 
/// Medium
/// 
/// You are given an m x n integer matrix points (0-indexed). Starting 
/// with 0 points, you want to maximize the number of points you can get 
/// from the matrix.
///
/// To gain points, you must pick one cell in each row. Picking the cell 
/// at coordinates (r, c) will add points[r][c] to your score.
///
/// However, you will lose points if you pick a cell too far from the cell 
/// that you picked in the previous row. For every two adjacent rows r and 
/// r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and 
/// (r + 1, c2) will subtract abs(c1 - c2) from your score.
/// 
/// Return the maximum number of points you can achieve.
/// abs(x) is defined as:
/// x for x >= 0.
/// -x for x < 0.
///
/// Example 1:
/// Input: points = [[1,2,3],[1,5,1],[3,1,1]]
/// Output: 9
/// Explanation:
/// The blue cells denote the optimal cells to pick, which have 
/// coordinates (0, 2), (1, 1), and (2, 0).
/// You add 3 + 5 + 3 = 11 to your score.
/// However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
/// Your final score is 11 - 2 = 9.
///
/// Example 2:
/// Input: points = [[1,5],[2,3],[4,2]]
/// Output: 11
/// Explanation:
/// The blue cells denote the optimal cells to pick, which have 
/// coordinates (0, 1), (1, 1), and (2, 0).
/// You add 5 + 3 + 4 = 12 to your score.
/// However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
/// Your final score is 12 - 1 = 11.
/// 
/// Constraints:
/// 1. m == points.length
/// 2. n == points[r].length
/// 3. 1 <= m, n <= 10^5
/// 4. 1 <= m * n <= 10^5
/// 5. 0 <= points[r][c] <= 10^5
/// </summary>
long long LeetCodeArray::maxPoints(vector<vector<int>>& points)
{
    int n = points[0].size();
    vector<long long> sum(n);
    for (size_t i = 0; i < points.size(); i++)
    {
        for (int j = 0; j <n; j++)
        {
            sum[j] += (long long)points[i][j];
        }

        vector<long long> left(n);
        for (int j = 0; j < n; j++)
        {
            if (j == 0) left[j] = sum[j];
            else left[j] = max(sum[j], left[j - 1] - 1);
        }
        vector<long long> right(n);
        for (int j = n-1; j >= 0; j--)
        {
            if (j == n - 1) right[j] = sum[j];
            else right[j] = max(sum[j], right[j + 1] - 1);
        }
        for (int j = 0; j < n; j++)
        {
            sum[j] = max(left[j], right[j]);
        }
    }

    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, sum[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 1788. Maximize the Beauty of the Garden
///                                                                 
/// Hard
/// 
/// There is a garden of n flowers, and each flower has an integer beauty 
/// value. The flowers are arranged in a line. You are given an integer 
/// array flowers of size n and each flowers[i] represents the beauty of 
/// the ith flower.
///
/// A garden is valid if it meets these conditions:
/// 
/// The garden has at least two flowers.
/// The first and the last flower of the garden have the same beauty value.
/// As the appointed gardener, you have the ability to remove any (possibly 
/// none) flowers from the garden. You want to remove flowers in a way that 
/// makes the remaining garden valid. The beauty of the garden is the sum 
/// of the beauty of all the remaining flowers.
/// Return the maximum possible beauty of some valid garden after you have 
/// removed any (possibly none) flowers.
///
/// Example 1:
/// Input: flowers = [1,2,3,1,2]
/// Output: 8
/// Explanation: You can produce the valid garden [2,3,1,2] to have a 
/// total beauty of 2 + 3 + 1 + 2 = 8.
///
/// Example 2:
/// Input: flowers = [100,1,1,-3,1]
/// Output: 3
/// Explanation: You can produce the valid garden [1,1,1] to have a total 
/// beauty of 1 + 1 + 1 = 3.
///
/// Example 3:
/// Input: flowers = [-1,-2,0,-1]
/// Output: -2
/// Explanation: You can produce the valid garden [-1,-1] to have a total 
/// beauty of -1 + -1 = -2.
/// Constraints:
/// 1. 2 <= flowers.length <= 10^5
/// 2. -10^4 <= flowers[i] <= 10^4
/// 3. It is possible to create a valid garden by removing some (possibly 
///    none) flowers.
/// </summary>
int LeetCodeArray::maximumBeauty(vector<int>& flowers)
{
    unordered_map<int, int> flower_map;
    vector<int> dp(flowers.size());
    int result = INT_MIN;
    for (size_t i = 0; i < flowers.size(); i++)
    {
        if (i == 0) dp[i] = 0;
        else dp[i] = dp[i - 1];
        if (flowers[i] > 0)
        {
            dp[i] += flowers[i];
        }
        if (flower_map.count(flowers[i]) > 0)
        {
            int prev = flower_map[flowers[i]];
            int beauty = dp[i] - dp[prev] + flowers[i];
            if (flowers[i] < 0)
            {
                beauty += flowers[i];
            }
            result = max(result, beauty);
        }
        else
        {
            flower_map[flowers[i]] = i;
        }
    }
    return result;
}
/// <summary>
/// Leet Code 2088. Count Fertile Pyramids in a Land
///                                                                 
/// Hard
/// 
/// A farmer has a rectangular grid of land with m rows and n columns that
/// can be divided into unit cells. Each cell is either fertile 
/// (represented by a 1) or barren (represented by a 0). All cells outside 
/// the grid are considered barren.
///
/// A pyramidal plot of land can be defined as a set of cells with the 
/// following criteria:
///
/// The number of cells in the set has to be greater than 1 and all cells 
/// must be fertile.
/// The apex of a pyramid is the topmost cell of the pyramid. The height 
/// of a pyramid is the number of rows it covers. Let (r, c) be the apex 
/// of the pyramid, and its height be h. Then, the plot comprises of 
/// cells (i, j) where r <= i <= r + h - 1 and c - (i - r) <= j <= c + 
/// (i - r).
/// An inverse pyramidal plot of land can be defined as a set of cells 
/// with similar criteria:
///
/// The number of cells in the set has to be greater than 1 and all 
/// cells must be fertile.
/// The apex of an inverse pyramid is the bottommost cell of the 
/// inverse pyramid. The height of an inverse pyramid is the number of 
/// rows it covers. Let (r, c) be the apex of the pyramid, and its height 
/// be h. Then, the plot comprises of cells (i, j) where 
/// r - h + 1 <= i <= r and c - (r - i) <= j <= c + (r - i).
/// Some examples of valid and invalid pyramidal (and inverse pyramidal) 
/// plots are shown below. Black cells indicate fertile cells.
///
/// Given a 0-indexed m x n binary matrix grid representing the farmland, 
/// return the total number of pyramidal and inverse pyramidal plots that 
/// can be found in grid.
///
/// Example 1:
/// Input: grid = [[0,1,1,0],[1,1,1,1]]
/// Output: 2
/// Explanation:
/// The 2 possible pyramidal plots are shown in blue and red respectively.
/// There are no inverse pyramidal plots in this grid. 
/// Hence total number of pyramidal and inverse pyramidal plots 
/// is 2 + 0 = 2.
///
/// Example 2:
/// Input: grid = [[1,1,1],[1,1,1]]
/// Output: 2
/// Explanation:
/// The pyramidal plot is shown in blue, and the inverse pyramidal plot 
/// is shown in red. 
/// Hence the total number of plots is 1 + 1 = 2.
///
/// Example 3:
/// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
/// Output: 0
/// Explanation:
/// There are no pyramidal or inverse pyramidal plots in the grid.
///
/// Example 4:
/// Input: grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
/// Output: 13
/// Explanation:
/// There are 7 pyramidal plots, 3 of which are shown in the 2nd 
/// and 3rd figures.
/// There are 6 inverse pyramidal plots, 2 of which are shown in the 
/// last figure.
/// The total number of plots is 7 + 6 = 13.
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 1000
/// 4. 1 <= m * n <= 10^5
/// 5. grid[i][j] is either 0 or 1.
/// </summary>
int LeetCodeArray::countPyramids(vector<vector<int>>& grid)
{
    int result = 0;
    vector<vector<int>> matrix = grid;
    for (int i = (int)matrix.size() - 2; i >= 0; i--)
    {
        for (int j = 1; j < (int)matrix[i].size() - 1; j++)
        {
            if (matrix[i][j] == 0) continue;
            int base = matrix[i + 1][j - 1];
            base = min(base, matrix[i + 1][j]);
            base = min(base, matrix[i + 1][j + 1]);
            matrix[i][j] += base;
            result += base;
        }
    }
    matrix = grid;
    for (int i = 1; i < (int)matrix.size(); i++)
    {
        for (int j = 1; j < (int)matrix[i].size() - 1; j++)
        {
            if (matrix[i][j] == 0) continue;
            int base = matrix[i - 1][j - 1];
            base = min(base, matrix[i - 1][j]);
            base = min(base, matrix[i - 1][j + 1]);
            matrix[i][j] += base;
            result += base;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2090. K Radius Subarray Averages
///                                                                 
/// Medium
/// 
/// You are given a 0-indexed array nums of n integers, and an integer k.
///
/// The k-radius average for a subarray of nums centered at some index i 
/// with the radius k is the average of all elements in nums between the 
/// indices i - k and i + k (inclusive). If there are less than k elements 
/// before or after the index i, then the k-radius average is -1.
///
/// Build and return an array avgs of length n where avgs[i] is the 
/// k-radius average for the subarray centered at index i.
///
/// The average of x elements is the sum of the x elements divided by x, 
/// using integer division. The integer division truncates toward zero, 
/// which means losing its fractional part.
///
/// For example, the average of four elements 2, 3, 1, and 5 is 
/// (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.
///
/// Example 1:
/// Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
/// Output: [-1,-1,-1,5,4,4,-1,-1,-1]
/// Explanation:
/// - avg[0], avg[1], and avg[2] are -1 because there are less than k 
///  elements before each index.
/// - The sum of the subarray centered at index 3 with radius 3 
/// is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
/// Using integer division, avg[3] = 37 / 7 = 5.
/// - For the subarray centered at index 4, avg[4] = 
///  (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
/// - For the subarray centered at index 5, avg[5] = 
///  (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
/// - avg[6], avg[7], and avg[8] are -1 because there are less than k 
///   elements after each index.
///
/// Example 2:
/// Input: nums = [100000], k = 0
/// Output: [100000]
/// Explanation:
/// - The sum of the subarray centered at index 0 with radius 0 
///   is: 100000.
/// avg[0] = 100000 / 1 = 100000.
///
/// Example 3:
/// Input: nums = [8], k = 100000
/// Output: [-1]
/// Explanation: 
/// - avg[0] is -1 because there are less than k elements before and 
///   after index 0.
/// 
/// Constraints:
/// 1. n == nums.length
/// 2. 1 <= n <= 10^5
/// 3. 0 <= nums[i], k <= 10^5
/// </summary>
vector<int> LeetCodeArray::getAverages(vector<int>& nums, int k)
{
    vector<int> result(nums.size(), -1);
    long long sum = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        sum += (long long)nums[i];
        if (i < 2 * k)
        {
            continue;
        }
        else if (i == 2 * k)
        {
            result[i - k] = (int)(sum / ((long long)2 * (long long)k + (long long)1));
        }
        else
        {
            sum -= nums[i - 2 * k - 1];
            result[i - k] = (int)(sum / ((long long)2 * (long long)k + (long long)1));
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1874. Minimize Product Sum of Two Arrays
///                                                                 
/// Medium
/// 
/// The product sum of two equal-length arrays a and b is equal to the 
/// sum of a[i] * b[i] for all 0 <= i < a.length (0-indexed).
///
/// For example, if a = [1,2,3,4] and b = [5,2,3,1], the product sum would 
/// be 1*5 + 2*2 + 3*3 + 4*1 = 22.
/// Given two arrays nums1 and nums2 of length n, return the minimum 
/// product sum if you are allowed to rearrange the order of the elements 
/// in nums1. 
/// 
/// Example 1:
/// Input: nums1 = [5,3,4,2], nums2 = [4,2,2,5]
/// Output: 40
/// Explanation: We can rearrange nums1 to become [3,5,4,2]. The product 
/// sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.
///
/// Example 2:
/// Input: nums1 = [2,1,4,5,7], nums2 = [3,2,4,8,6]
/// Output: 65
/// Explanation: We can rearrange nums1 to become [5,7,4,1,2]. The product 
/// sum of [5,7,4,1,2] and [3,2,4,8,6] is 5*3 + 7*2 + 4*4 + 1*8 + 2*6 = 65.
/// 
/// Constraints:
/// 1. n == nums1.length == nums2.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= nums1[i], nums2[i] <= 100
/// </summary>
int LeetCodeArray::minProductSum(vector<int>& nums1, vector<int>& nums2)
{
    int result = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for (size_t i = 0; i < nums1.size(); i++)
    {
        result += nums1[i] * nums2[nums2.size() - 1 - i];
    }
    return result;
}

/// <summary>
/// Leet Code 2079. Watering Plants 
///                                                                 
/// Medium
/// 
/// You want to water n plants in your garden with a watering can. The 
/// plants are arranged in a row and are labeled from 0 to n - 1 from 
/// left to right where the ith plant is located at x = i. There is a 
/// river at x = -1 that you can refill your watering can at.
///
/// Each plant needs a specific amount of water. You will water the 
/// plants in the following way:
/// 
/// Water the plants in order from left to right.
/// After watering the current plant, if you do not have enough water 
/// to completely water the next plant, return to the river to fully 
/// refill the watering can.
/// You cannot refill the watering can early.
/// You are initially at the river (i.e., x = -1). It takes one step 
/// to move one unit on the x-axis.
///  
/// Given a 0-indexed integer array plants of n integers, where plants[i] 
/// is the amount of water the ith plant needs, and an integer capacity 
/// representing the watering can capacity, return the number of steps 
/// needed to water all the plants.
/// 
/// Example 1:
/// 
/// Input: plants = [2,2,3,3], capacity = 5
/// Output: 14
/// Explanation: Start at the river with a full watering can:
/// - Walk to plant 0 (1 step) and water it. Watering can has 3 units of 
///   water.
/// - Walk to plant 1 (1 step) and water it. Watering can has 1 unit of 
///   water.
/// - Since you cannot completely water plant 2, walk back to the river 
///   to refill (2 steps).
/// - Walk to plant 2 (3 steps) and water it. Watering can has 2 units 
///   of water.
/// - Since you cannot completely water plant 3, walk back to the river 
///   to refill (3 steps).
/// - Walk to plant 3 (4 steps) and water it.
/// Steps needed = 1 + 1 + 2 + 3 + 3 + 4 = 14.
///
/// Example 2:
/// Input: plants = [1,1,1,4,2,3], capacity = 4
/// Output: 30
/// Explanation: Start at the river with a full watering can:
/// - Water plants 0, 1, and 2 (3 steps). Return to river (3 steps).
/// - Water plant 3 (4 steps). Return to river (4 steps).
/// - Water plant 4 (5 steps). Return to river (5 steps).
/// - Water plant 5 (6 steps).
/// Steps needed = 3 + 3 + 4 + 4 + 5 + 5 + 6 = 30.
///
/// Example 3:
/// Input: plants = [7,7,7,7,7,7,7], capacity = 8
/// Output: 49
/// Explanation: You have to refill before watering each plant.
/// Steps needed = 1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 + 5 + 5 + 6 + 6 + 7 = 49.
/// 
/// Constraints:
/// 1. n == plants.length
/// 2. 1 <= n <= 1000
/// 3. 1 <= plants[i] <= 10^6
/// 4. max(plants[i]) <= capacity <= 10^9
/// </summary>
int LeetCodeArray::wateringPlants(vector<int>& plants, int capacity)
{
    int result = 0;
    int original_capacity = capacity;
    for (size_t i = 0; i < plants.size(); i++)
    {
        if (plants[i] > capacity)
        {
            result += 2 * i;
            capacity = original_capacity;
        }
        result++;
        capacity -= plants[i];
    }
    return result;
}
#pragma endregion

