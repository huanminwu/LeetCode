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
#include <queue> 
#include <vector>
#include <iostream>
#include <fstream>
#include "Leetcode.h"
#include "LeetcodeSort.h"
#pragma region Sort
/// <summary>
/// Leet code #164. Maximum Gap 
/// Given an unsorted array, find the maximum difference between the successive 
/// elements in its sorted form.
/// Try to solve it in linear time/space.
/// Return 0 if the array contains less than 2 elements.
/// You may assume all elements in the array are non-negative integers and fit 
/// in the 32-bit signed integer range.
/// </summary>
int LeetCode::maximumGap(vector<int>& nums)
{
    if (nums.size() < 2) return 0;

    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] < minimum) minimum = nums[i];
        if (nums[i] > maximum) maximum = nums[i];
    }
    // The plus one is to make sure we do not have a slot_gap as 0.
    int slot_gap = (maximum - minimum) / nums.size() + 1;
    // In case the slot gap is not divisible by the range.
    vector<pair<int, int>> slot((maximum - minimum) / slot_gap + 1, make_pair(-1, -1));
    for (size_t i = 0; i < nums.size(); i++)
    {
        int index = (nums[i] - minimum) / slot_gap;
        pair<int, int> pair = slot[index];
        if (pair.first == -1)
        {
            pair.first = nums[i];
            pair.second = nums[i];
        }
        else
        {
            if (nums[i] < pair.first)
            {
                pair.first = nums[i];
            }
            else if (nums[i] > pair.second)
            {
                pair.second = nums[i];
            }
        }
        slot[index] = pair;
    }
    int max_gap = INT_MIN;
    int previous = -1;
    pair<int, int> pair;
    if (slot.size() == 1)
    {
        pair = slot[0];
        max_gap = pair.second - pair.first;
    }
    else
    {
        for (size_t i = 0; i < slot.size(); i++)
        {
            pair = slot[i];
            if (pair.first == -1) continue;
            if ((previous != -1) && (pair.first - previous) > max_gap)
            {
                max_gap = pair.first - previous;
            }
            previous = pair.second;
        }
    }
    return max_gap;
}

/// <summary>
/// Leet code #75. Sort Colors   
/// Given an array with n objects colored red, white or blue, sort them so 
/// that objects of the same color are adjacent, with the colors in the order 
/// red, white and blue. 
/// Here, we will use the integers 0, 1, and 2 to represent the color red, 
/// white, and blue respectively.  
/// Note:
/// You are not suppose to use the library's sort function for this problem.  
/// Follow up:
/// A rather straight forward solution is a two-pass algorithm using counting 
/// sort.
/// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite 
/// array with total number of 0's, then 1's and followed by 2's.
/// Could you come up with an one-pass algorithm using only constant space?
/// </summary>
void LeetCode::sortColors(vector<int>& nums)
{
    int low, high, mid;
    low = 0;
    high = nums.size() - 1;
    mid = low;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
}

/// <summary>
/// Leet code #274. H-Index 
/// Given an array of citations (each citation is a non-negative integer) of 
/// a researcher, write a function to compute the researcher's h-index.  
/// According to the definition of h-index on Wikipedia: "A scientist has index h 
/// if h of his/her N papers have at 
/// least h citations each, and the other N − h papers have no more than h citations each." 
/// For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers 
/// in total and each of 
/// them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers 
/// with at least 3 
/// citations each and the remaining two with no more than 3 citations each, his h-index is 3. 
/// Note: If there are several possible values for h, the maximum one is taken as the h-index. 
/// Hint:
/// 1.An easy approach is to sort the array first.
/// 2.What are the possible values of h-index?
/// 3.A faster approach is to use extra space.
/// </summary>
int LeetCode::hIndex(vector<int>& citations)
{
    vector<int> count_map(citations.size() + 1);
    for (size_t i = 0; i < citations.size(); i++)
    {
        if (citations[i] >= (int)citations.size())
        {
            count_map[citations.size()]++;
        }
        else
        {
            count_map[citations[i]]++;
        }
    }
    int index;
    for (index = citations.size(); index >= 0; index--)
    {
        if (index < (int)citations.size()) count_map[index] += count_map[index + 1];
        if (count_map[index] >= index) break;
    }
    return index;
}

/// <summary>
/// Leet code #324. Wiggle Sort II  
/// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3].... 
/// Example:
/// (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
/// (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2]. 
/// Note:
/// You may assume all input has valid answer. 
/// Follow Up:
/// Can you do it in O(n) time and/or in-place with O(1) extra space? 
/// </summary>
void LeetCode::wiggleSortII(vector<int>& nums)
{
    int n = nums.size();

    // Find a median.
    vector<int>::iterator middle_ptr = nums.begin() + n / 2;
    nth_element(nums.begin(), middle_ptr, nums.end());
    int value = *middle_ptr;

    // Index-rewiring.
#define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (A(mid) > value)
        {
            swap(A(low), A(mid));
            low++; mid++;
        }
        else if (A(mid) < value)
        {
            swap(A(mid), A(high--));
        }
        else
        {
            mid++;
        }
    }
}

/// <summary>
/// Leet code #179. Largest Number        
/// Given a list of non negative integers, arrange them such that they form the largest number.  
/// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
/// Note: The result may be very large, so you need to return a string instead of an integer.
/// </summary>
string LeetCode::largestNumber(vector<int>& nums)
{
    string result;
    vector<string> num_strs;
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_strs.push_back(to_string(nums[i]));
    }
    struct digit_compare_loop
    {
        bool operator() (string str1, string str2)
        {
            size_t index = 0;
            while (index < str1.size() + str2.size())
            {
                char ch1 = index < str1.size() ? str1[index] : str2[index - str1.size()];
                char ch2 = index < str2.size() ? str2[index] : str1[index - str2.size()];

                if (ch1 > ch2)
                {
                    return true;
                }
                else if (ch1 < ch2)
                {
                    return false;
                }
                index++;
            }
            return false;
        }
    };

    sort(num_strs.begin(), num_strs.end(), digit_compare_loop());
    int index = 0;
    for (size_t i = 0; i < num_strs.size(); i++)
    {
        if ((i < num_strs.size() - 1) && (num_strs[i] == "0") && (result.empty()))
        {
            continue;
        }
        result.append(num_strs[i]);
    }
    return result;
}

/// <summary>
/// Leet code #456. 132 Pattern
/// Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence 
/// ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes 
/// a list of n numbers as input and checks whether there is a 132 pattern in the list.
/// Note: n will be less than 15,000.    
/// Example 1:
/// Input: [1, 2, 3, 4]
/// Output: False
/// Explanation: There is no 132 pattern in the sequence.
///
/// Example 2:
/// Input: [3, 1, 4, 2]
/// Output: True
/// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
/// Example 3:
/// Input: [-1, 3, 2, 0]
/// Output: True
/// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
/// </summary>
bool LeetCode::find132pattern(vector<int>& nums)
{
    map<int, int> intervals;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (intervals.empty())
        {
            intervals[nums[i]] = nums[i];
            continue;
        }
        map<int, int>::iterator next = intervals.lower_bound(nums[i]);
        if (next == intervals.begin())
        {
            if (nums[i] != next->first)
            {
                intervals[nums[i]] = nums[i];
                continue;
            }
        }
        else
        {
            next--;
            if (nums[i] < next->second)
            {
                return true;
            }
            else if (nums[i] > next->second)
            {
                next++;
                int first = intervals.begin()->first;
                intervals.erase(intervals.begin(), next);
                intervals[first] = nums[i];
                continue;
            }
        }
    }
    return false;
}

/// <summary>
/// Leet code #406. Queue Reconstruction by Height 
/// Suppose you have a random list of people standing in a queue. Each person
/// is described by a pair of integers (h, k), where h is the height of the 
/// person and k is the number of people in front of this person who have a 
/// height greater than or equal to h. Write an algorithm to reconstruct the queue. 
///
/// Note:
/// The number of people is less than 1,100. 
///
/// Example 
/// Input:
/// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
///
/// Output:
/// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
/// </summary>
vector<pair<int, int>> LeetCode::reconstructQueue(vector<pair<int, int>>& people)
{
    vector<pair<int, int>> result;
    struct heightCompare
    {
        bool operator() (pair<int, int>& a, pair<int, int>& b)
        {
            if ((a.first > b.first) || ((a.first == b.first) && (a.second < b.second)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };

    sort(people.begin(), people.end(), heightCompare());
    for (size_t i = 0; i < people.size(); i++)
    {
        vector<pair<int, int>>::iterator itr = result.begin();
        result.insert(itr + people[i].second, people[i]);
    }
    return result;
}

/// <summary>
/// Leet code #373. Find K Pairs with Smallest Sums 
///
/// You are given two integer arrays nums1 and nums2 sorted in ascending 
/// order and an integer k.
/// Define a pair (u,v) which consists of one element from the first array 
/// and one element from the second array. 
/// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums. 
///
/// Example 1:
/// Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
/// Return: [1,2],[1,4],[1,6]
/// The first 3 pairs are returned from the sequence:
/// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
/// 
/// Example 2:
/// Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
/// Return: [1,1],[1,1]
/// The first 2 pairs are returned from the sequence: 
/// [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
/// 
/// Example 3:
/// Given nums1 = [1,2], nums2 = [3],  k = 3 
/// Return: [1,3],[2,3]
/// All possible pairs are returned from the sequence:
/// [1,3],[2,3]
/// </summary>
vector<vector<int>> LeetCodeSort::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty()) return result;
    priority_queue<vector<int>> priority_queue;
    for (int i = 0; i < (int)nums1.size(); i++)
    {
        priority_queue.push({ -(nums1[i] + nums2[0]), i, 0 });
    }
    for (int i = 0; i < k; i++)
    {
        if (priority_queue.empty()) break;
        vector<int> sum = priority_queue.top();
        priority_queue.pop();

        result.push_back({ nums1[sum[1]], nums2[sum[2]] });
        sum[2]++;
        if (sum[2] < (int)nums2.size())
        {
            priority_queue.push({ -(nums1[sum[1]] + nums2[sum[2]]), sum[1], sum[2] });
        }
    }
    return result;
}

/// <summary>
/// Leet code #220. Contains Duplicate III
/// Given an array of integers, find out whether there are two distinct 
/// indices i and j in the array such that the difference between 
/// nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
/// </summary>
bool LeetCode::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    set<int> nums_set;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i >(size_t)k)
        {
            nums_set.erase(nums[i - k - 1]);
        }
        set<int>::iterator itr = nums_set.lower_bound(nums[i]);
        if (itr != nums_set.end())
        {
            if (abs((long long)nums[i] - (long long)*itr) <= t)
            {
                return true;
            }
        }
        if (itr != nums_set.begin())
        {
            itr--;
            if (abs((long long)nums[i] - (long long)*itr) <= t)
            {
                return true;
            }
        }
        nums_set.insert(nums[i]);
    }
    return false;
}

/// <summary>
/// Leet code #315. Count of Smaller Numbers After Self  
/// 
/// You are given an integer array nums and you have to return a new counts array. 
/// The counts array has the property where counts[i] is the number of smaller 
/// elements to the right of nums[i]. 
///
/// Example:
///
/// Given nums = [5, 2, 6, 1]
/// To the right of 5 there are 2 smaller elements (2 and 1).
/// To the right of 2 there is only 1 smaller element (1).
/// To the right of 6 there is 1 smaller element (1).
/// To the right of 1 there is 0 smaller element.
/// Return the array [2, 1, 1, 0]. 
/// </summary>
vector<int> LeetCode::countSmallerII(vector<int>& nums)
{
    vector<int> num_map;
    vector<int> result(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        vector<int> ::iterator itr = lower_bound(num_map.begin(), num_map.end(), nums[i]);
        int index = itr - num_map.begin();
        result[i] = index;
        num_map.insert(itr, nums[i]);
    }
    return result;
}

/// <summary>
/// Leet code #315. Count of Smaller Numbers After Self
/// Note: end is out of the boundary of the last element, e.g. vector.size(), 
/// not the index of last element.
/// </summary>
void LeetCodeSort::mergeSortCountSmaller(vector<pair<int, int>>& nums, int begin, int end, vector<int>&result)
{
    if (begin + 1 >= end) return;
    int mid = begin + (end - begin) / 2;
    mergeSortCountSmaller(nums, begin, mid, result);
    mergeSortCountSmaller(nums, mid, end, result);
    int left = begin, right = mid;
    int count = 0;
    // we may have right pointer stay at end position for a 
    // while for the left elements to catch up
    while (left < mid  && right <= end)
    {
        while ((right < end) && (nums[left].first > nums[right].first)) right++;
        count = right - mid;
        result[nums[left].second] += count;
        left++;
    }
    sort(nums.begin() + begin, nums.begin() + end);
}

/// <summary>
/// Leet code #315. Count of Smaller Numbers After Self  
/// 
/// You are given an integer array nums and you have to return a new counts array. 
/// The counts array has the property where counts[i] is the number of smaller 
/// elements to the right of nums[i]. 
/// Example:
///
/// Input: [5,2,6,1]
/// Output: [2, 1, 1, 0]
/// Explanation :
/// To the right of 5 there are 2 smaller elements (2 and 1).
/// To the right of 2 there is only 1 smaller element (1).
/// To the right of 6 there is 1 smaller element (1).
/// To the right of 1 there is 0 smaller element.
/// Return the array [2, 1, 1, 0]. 
/// </summary>
vector<int> LeetCodeSort::countSmaller(vector<int>& nums)
{
    vector<pair<int, int>> num_pairs;
    vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_pairs.push_back(make_pair(nums[i], i));
    }
    mergeSortCountSmaller(num_pairs, 0, nums.size(), result);
    return result;
}

/// <summary>
/// Leet code #315. Count of Smaller Numbers After Self  
/// </summary>
void LeetCode::addBIT(int index, vector<int>& accu_slot)
{
    while (index < (int)accu_slot.size())
    {
        accu_slot[index] += 1;
        index += (index & -index);
    }
}

/// <summary>
/// Leet code #315. Count of Smaller Numbers After Self  
/// </summary>
int LeetCode::sumBIT(int index, vector<int>& accu_slot)
{
    int sum = 0;
    while (index != 0)
    {
        sum += accu_slot[index];
        index -= index & -index;
    }
    return sum;
}

/// <summary>
/// Leet code #315. Count of Smaller Numbers After Self  
/// 
/// You are given an integer array nums and you have to return a new counts array. 
/// The counts array has the property where counts[i] is the number of smaller 
/// elements to the right of nums[i]. 
/// Example:
/// Given nums = [5, 2, 6, 1]
/// To the right of 5 there are 2 smaller elements (2 and 1).
/// To the right of 2 there is only 1 smaller element (1).
/// To the right of 6 there is 1 smaller element (1).
/// To the right of 1 there is 0 smaller element.
/// Return the array [2, 1, 1, 0]. 
/// </summary>
vector<int> LeetCode::countSmallerIV(vector<int>& nums)
{
    vector<int> result(nums.size());
    int max_num = INT_MIN;
    int min_num = INT_MAX;
    for (size_t i = 0; i < nums.size(); i++)
    {
        max_num = max(max_num, nums[i]);
        min_num = min(min_num, nums[i]);
    }
    // the min_num should be located at 1 and 
    // the max_num should be located at max_num-min_num + 1 
    vector<int> accu_slot(max_num - min_num + 2);

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        addBIT(nums[i] - min_num + 1, accu_slot);
        result[i] = sumBIT(nums[i] - min_num, accu_slot);
    }
    return result;
}


/// <summary>
/// Leet code #493. Reverse Pairs
/// </summary>
int LeetCodeSort::mergeSortReversePairs(vector<int>& nums, int begin, int end)
{
    if (begin + 1 >= end) return 0;
    int mid = begin + (end - begin) / 2;
    int count = mergeSortReversePairs(nums, begin, mid) + mergeSortReversePairs(nums, mid, end);
    int first = begin, next = mid;
    while (first < mid  && next <= end)
    {
        while ((next < end) && (nums[first] / 2.0 > nums[next])) next++;
        count += next - mid;
        first++;
    }
    sort(nums.begin() + begin, nums.begin() + end);
    return count;
}

/// <summary>
/// Leet code #493. Reverse Pairs
/// 
/// Given an array nums, we call (i, j) an important reverse pair if 
/// i < j and nums[i] > 2*nums[j]. 
/// You need to return the number of important reverse pairs in the given array. 
/// 
/// Example1: 
/// Input: [1,3,2,3,1]
/// Output: 2
///
/// Example2: 
/// Input: [2,4,3,5,1]
/// Output: 3
///
/// Note:
/// 1.The length of the given array will not exceed 50,000.
/// 2.All the numbers in the input array are in the range of 32-bit integer.
/// </summary>
int LeetCodeSort::reversePairs(vector<int>& nums)
{
    return mergeSortReversePairs(nums, 0, nums.size());
}

/// <summary>
/// Leet code #327. Count of Range Sum   
/// </summary>
int LeetCodeSort::mergeCountRangeSum(vector<long long>& sums, int begin, int end, int lower, int upper)
{
    if (begin + 1 >= end) return 0;
    int middle = begin + (end - begin) / 2;
    int count = 0;
    count = mergeCountRangeSum(sums, begin, middle, lower, upper) +
        mergeCountRangeSum(sums, middle, end, lower, upper);
    int m = middle, n = middle;
    for (int i = begin; i < middle; i++)
    {
        while ((m < end) && (sums[m] - sums[i] < lower)) m++;
        while ((n < end) && (sums[n] - sums[i] <= upper)) n++;
        count += n - m;
    }
    inplace_merge(sums.begin() + begin, sums.begin() + middle, sums.begin() + end);
    return count;
}

/// <summary>
/// Leet code #327. Count of Range Sum   
/// 
/// Given an integer array nums, return the number of range sums that lie in 
/// [lower, upper] inclusive.
/// Range sum S(i, j) is defined as the sum of the elements in nums between 
/// indices i and j (i ≤ j), inclusive.
/// 
/// Note:
/// A naive algorithm of O(n2) is trivial. You MUST do better than that. 
/// Example:
/// Given nums = [-2, 5, -1], lower = -2, upper = 2,
/// Return 3.
/// The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums 
/// are: -2, -1, 2. 
/// </summary>
int LeetCodeSort::countRangeSum(vector<int>& nums, int lower, int upper)
{
    vector<long long> sums;
    long long sum = 0;
    sums.push_back(0);
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        sums.push_back(sum);
    }
    return mergeCountRangeSum(sums, 0, sums.size(), lower, upper);
}

/// <summary>
/// Leet code #280. Wiggle Sort      
/// 
/// Given an unsorted array nums, reorder it in-place such that 
/// nums[0] <= nums[1] >= nums[2] <= nums[3].... 
/// For example, given nums = [3, 5, 2, 1, 6, 4], 
/// one possible answer is [1, 6, 2, 5, 3, 4].
/// </summary>
void LeetCode::wiggleSort(vector<int>& nums)
{
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (i % 2 == 1)
        {
            if (nums[i] < nums[i - 1]) swap(nums[i], nums[i - 1]);
        }
        else
        {
            if (nums[i] > nums[i - 1]) swap(nums[i], nums[i - 1]);
        }
    }
}

/// <summary>
/// Leet code #334. Increasing Triplet Subsequence  
/// 
/// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array. 
/// Formally the function should:
/// Return true if there exists i, j, k  
/// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 
/// Your algorithm should run in O(n) time complexity and O(1) space complexity. 
/// Examples:
/// Given [1, 2, 3, 4, 5],
///  return true.
/// Given [5, 4, 3, 2, 1],
/// return false. 
/// </summary>
bool LeetCode::increasingTriplet(vector<int>& nums)
{
    vector<int> result;
    for (size_t i = 0; i < nums.size(); i++)
    {
        vector<int>::iterator itr = lower_bound(result.begin(), result.end(), nums[i]);
        if (itr == result.end()) result.push_back(nums[i]);
        else *itr = nums[i];
        if (result.size() == 3) return true;
    }
    return false;
}

/// <summary>
/// Leet code #496. Next Greater Element I
///
/// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements 
/// are subset of nums2. Find all the next greater numbers for nums1's elements in the 
/// corresponding places of nums2. 
/// 
/// The Next Greater Number of a number x in nums1 is the first greater number to its right 
/// in nums2. If it does not exist, output -1 for this number. 
/// 
/// Example 1:
/// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
/// Output: [-1,3,-1]
/// Explanation:
/// For number 4 in the first array, you cannot find the next greater number for it in 
/// the second array, so output -1.
/// For number 1 in the first array, the next greater number for it in the second array is 3.
/// For number 2 in the first array, there is no next greater number for it in the second array, 
/// so output -1.
///
/// Example 2:
///
/// Input: nums1 = [2,4], nums2 = [1,2,3,4].
/// Output: [3,-1]
/// Explanation:
/// For number 2 in the first array, the next greater number for it in the second array is 3.
/// For number 4 in the first array, there is no next greater number for it in the second array, 
/// so output -1.
///  
/// Note:
///
/// 1.All elements in nums1 and nums2 are unique.
/// 2.The length of both nums1 and nums2 would not exceed 1000.
/// </summary>
vector<int> LeetCode::nextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
    vector<int> result;
    map<int, int> num_map;
    set<int> num_set;
    for (size_t i = 0; i < nums.size(); i++)
    {
        while (!num_set.empty())
        {
            set<int>::iterator itr = num_set.begin();
            if (*itr < nums[i])
            {
                num_map[*itr] = nums[i];
                num_set.erase(itr);
            }
            else
            {
                break;
            }
        }
        num_set.insert(nums[i]);
    }
    for (size_t i = 0; i < findNums.size(); i++)
    {
        if (num_map.count(findNums[i]) > 0)
        {
            result.push_back(num_map[findNums[i]]);
        }
        else
        {
            result.push_back(-1);
        }
    }
    return result;
}

/// <summary>
/// Leet code #503. Next Greater Element II
///
/// Given a circular array (the next element of the last element is the 
/// first element of the array), print the Next Greater Number for 
/// every element. The Next Greater Number of a number x is the first 
/// greater number to its traversing-order next in the array, which means 
/// you could search circularly to find its next greater number. If it 
/// doesn't exist, output -1 for this number. 
///
/// Example 1:
///
/// Input: [1,2,1]
/// Output: [2,-1,2]
/// Explanation: The first 1's next greater number is 2; 
/// The number 2 can't find next greater number; 
/// The second 1's next greater number needs to search circularly, which is also 2.
/// </summary>
vector<int> LeetCode::nextGreaterElements(vector<int>& nums)
{
    vector<int> result(nums.size(), -1);
    map<int, vector<int>> num_map;
    for (size_t k = 0; k < 2; k++)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            while (!num_map.empty())
            {
                map<int, vector<int>>::iterator itr = num_map.begin();
                if (itr->first < nums[i])
                {
                    while (!itr->second.empty())
                    {
                        int index = itr->second.back();
                        itr->second.pop_back();
                        result[index] = nums[i];
                    }
                    num_map.erase(itr);
                }
                else
                {
                    break;
                }
            }
            if (k == 0)
            {
                num_map[nums[i]].push_back(i);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code # 440. K-th Smallest in Lexicographical Order  
///
/// Given integers n and k, find the lexicographically k-th smallest 
/// integer in the range from 1 to n. 
/// Note: 1 ≤ k ≤ n ≤ 109.
/// 
/// Example: 
/// Input:
/// n: 13   k: 2
///
/// Output:
/// 10
/// 
/// Explanation:
/// The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], 
/// so the second smallest number is 10.
/// </summary>
int LeetCode::findKthNumber(int n, int k)
{
    k--;
    int current = 1;
    while (k > 0)
    {
        unsigned long first = (unsigned long)current;
        unsigned long last = (unsigned long)current + 1;
        int count = 0;
        while (first <= (unsigned long)n)
        {
            count += min((unsigned long)n + 1, last) - first;
            first *= 10;
            last *= 10;
        }
        if (count <= k)
        {
            k -= count;
            current++;
        }
        else
        {
            k--;
            current *= 10;
        }
    }
    return current;
}

/// <summary>
/// Leet code #480. Sliding Window Median
///
/// Median is the middle value in an ordered integer list. If the size of 
/// the list is even, there is no middle value. So the median is the mean 
/// of the two middle value.
/// Examples: 
/// [2,3,4] , the median is 3
/// [2,3], the median is (2 + 3) / 2 = 2.5 
/// Given an array nums, there is a sliding window of size k which is 
/// moving from the very left of the array to the very right. You can 
/// only see the k numbers in the window. Each time the sliding window 
/// moves right by one position. Your job is to output the median array 
/// for each window in the original array.
///
/// For example,
/// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
/// Window position                Median
/// ---------------               -----
/// [1  3  -1] -3  5  3  6  7       1
/// 1 [3  -1  -3] 5  3  6  7       -1
/// 1  3 [-1  -3  5] 3  6  7       -1
/// 1  3  -1 [-3  5  3] 6  7       3
/// 1  3  -1  -3 [5  3  6] 7       5
/// 1  3  -1  -3  5 [3  6  7]      6
///
/// Therefore, return the median sliding window as [1,-1,-1,3,5,6].
/// Note: 
/// You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty 
/// array.
/// </summary>
vector<double> LeetCode::medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> result;
    multiset<int> low_half;
    multiset<int> high_half;
    for (size_t i = 0; i < nums.size(); i++)
    {
        // remove the first one
        if (i >= (size_t)k)
        {
            int value = nums[i - k];
            // remove a low half value
            if ((high_half.empty()) || (value < *high_half.begin()))
            {
                low_half.erase(low_half.find(value));
            }
            // remove a high half value
            else
            {
                high_half.erase(high_half.find(value));
            }
        }

        // push the new one
        int value = nums[i];
        if ((high_half.empty()) || (value < *high_half.begin()))
        {
            low_half.insert(value);
        }
        else
        {
            high_half.insert(value);
        }

        if (low_half.size() < high_half.size())
        {
            low_half.insert(*high_half.begin());
            high_half.erase(high_half.begin());
        }
        else if (high_half.size() + 1 < low_half.size())
        {
            high_half.insert(*low_half.rbegin());
            low_half.erase(low_half.find(*low_half.rbegin()));
        }

        if (low_half.size() + high_half.size() == k)
        {
            if (low_half.size() == high_half.size())
            {
                result.push_back(((double)(*low_half.rbegin()) + (double)(*high_half.begin())) / 2);
            }
            else
            {
                result.push_back(*low_half.rbegin());
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #556. Next Greater Element III  
/// 
/// Given a positive 32-bit integer n, you need to find the smallest 32-bit 
/// integer which has exactly the same digits existing in the integer n and 
/// is greater in value than n. If no such positive 32-bit integer exists, 
/// you need to return -1.
/// Example 1:
/// Input: 12
/// Output: 21
///
/// Example 2:
/// Input: 21
/// Output: -1
/// </summary>
int LeetCode::nextGreaterElement(int n)
{
    vector<int> nums;
    while (n > 0)
    {
        nums.push_back(n % 10);
        n /= 10;
    }
    int index = 1;
    unsigned long long result = 0;
    // index is the position where digits may be in asc order, from 
    // lowest significant to most significant
    while (index < (int)nums.size())
    {
        if (nums[index] < nums[index - 1]) break;
        index++;
    }
    // No asc order digits, no answer
    if (index == nums.size()) return -1;

    int i = 0;
    // fine the first digit larger than nums[index]
    while (i < index && nums[i] <= nums[index]) i++;

    // swap with nums[index]
    swap(nums[i], nums[index]);

    // reverse first part
    std::reverse(nums.begin(), nums.begin() + index);
    // copy the digits before the position, they do not
    // matters
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        result = result * 10 + nums[i];
    }

    if (result > (unsigned long long) INT_MAX) return -1;
    return (int)result;
}

/// <summary>
/// Leet code #321. Create Maximum Number 
/// </summary>
string LeetCode::createMaxNumber(vector<int>& nums, int k)
{
    string result;
    size_t i = 0;
    while (i < nums.size())
    {
        if (result.empty() || nums[i] + '0' <= result.back() || k == nums.size())
        {
            result.push_back(nums[i] + '0');
            i++;
        }
        else
        {
            k++;
            result.pop_back();
        }
    }
    while (k < (int)nums.size())
    {
        k++;
        result.pop_back();
    }
    return result;
}

/// <summary>
/// Leet code #321. Create Maximum Number 
/// </summary>
void LeetCode::createMaxNumber(string num1, string num2, string& result)
{
    while ((!num1.empty()) || (!num2.empty()))
    {
        if (num1.empty() || num2.empty())
        {
            result.append(num1);
            num1.clear();
            result.append(num2);
            num2.clear();
        }
        else
        {
            if (num1 > num2)
            {
                result.push_back(num1[0]);
                num1 = num1.substr(1);
            }
            else
            {
                result.push_back(num2[0]);
                num2 = num2.substr(1);
            }
        }
    }
}

/// <summary>
/// Leet code #321. Create Maximum Number 
/// 
/// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of 
/// length k <= m + n from digits of the two. The relative order of the digits from the same array must be 
/// preserved. Return an array of the k digits. You should try to optimize your time and space complexity. 
/// Example 1: 
/// nums1 = [3, 4, 6, 5]
/// nums2 = [9, 1, 2, 5, 8, 3] 
/// k = 5
/// return [9, 8, 6, 5, 3]
/// 
/// Example 2:
/// nums1 = [6, 7]
/// nums2 = [6, 0, 4]
/// k = 5
/// return [6, 7, 6, 0, 4] 
/// 
/// Example 3:
/// nums1 = [3, 9]
/// nums2 = [8, 9]
/// k = 3
/// return [9, 8, 9]
/// </summary>
vector<int> LeetCode::maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
    vector<int> result;
    string max_num;
    for (int i = 0; i <= k; i++)
    {
        if ((i > (int)nums1.size()) || (k - i > (int)nums2.size()))
        {
            continue;
        }
        string num1 = createMaxNumber(nums1, i);
        string num2 = createMaxNumber(nums2, k - i);
        string merge_num;
        createMaxNumber(num1, num2, merge_num);
        if (max_num.empty()) max_num = merge_num;
        else max_num = max(max_num, merge_num);
    }
    for (int i = 0; i < (int)max_num.size(); i++)
    {
        result.push_back(max_num[i] - '0');
    }
    return result;
}

/// <summary>
/// Leet code #555. Split Assembled Strings 
/// 
/// Given a list of strings, you could assemble these strings together into 
/// a loop. Among all the possible loops, you need to find the 
/// lexicographically biggest string after cutting and making one 
/// breakpoint of the loop, which will make a looped string into a regular one.
///
/// So, to find the lexicographically biggest string, you need to experience 
/// two phases: 
/// 1.Assemble all the strings into a loop, where you can reverse some strings 
///   or not and connect them in the same order as given.
/// 2.Cut and make one breakpoint in any place of the loop, which will make a 
///   looped string into a regular string starting from the character at the 
///   cutting point. 
/// And your job is to find the lexicographically biggest one among all the 
/// regular strings.
/// 
/// Example:
/// Input: "abc", "xyz"
/// Output: "zyxcba"
/// Explanation: You can get the looped string "-abcxyz-", "-abczyx-", 
/// "-cbaxyz-", "-cbazyx-", 
/// where '-' represents the looped status. 
/// The answer string came from the fourth looped one, 
/// where you could cut from the middle and get "zyxcba".
/// Note:
/// 1.The input strings will only contain lowercase letters.
/// 2.The total length of all the strings will not over 1000.
/// </summary>
string LeetCode::splitLoopedString(vector<string>& strs)
{
    string max_str;
    vector<string> max_strs;
    vector<string> reverse_strs;
    for (string str : strs)
    {
        string reverse_str = str;
        std::reverse(reverse_str.begin(), reverse_str.end());
        max_strs.push_back(max(str, reverse_str));
        reverse_strs.push_back(reverse_str);
    }
    for (size_t i = 0; i < strs.size(); i++)
    {
        string str, reverse_str;
        string first_part, second_part;
        string combined_str;
        for (size_t j = 0; j < strs.size(); j++)
        {
            if (i == j)
            {
                str = strs[j];
                reverse_str = reverse_strs[j];
            }
            else if (j < i)
            {
                second_part.append(max_strs[j]);
            }
            else
            {
                first_part.append(max_strs[j]);
            }
        }
        for (size_t j = 0; j < str.size(); j++)
        {
            combined_str = str.substr(j) + first_part + second_part + str.substr(0, j);
            max_str = max(max_str, combined_str);
            combined_str = reverse_str.substr(j) + first_part + second_part + reverse_str.substr(0, j);
            max_str = max(max_str, combined_str);
        }
    }
    return max_str;
}

/// <summary>
/// Leet code #561. Array        
/// 
/// Given an array of 2n integers, your task is to group these integers 
/// into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which 
/// makes sum of min(ai, bi) for all i from 1 to n as large as possible.
///
/// Example 1:
/// Input: [1,4,3,2]
///
/// Output: 4
/// Explanation: n is 2, and the maximum sum of pairs is 4.
/// Note:
/// n is a positive integer, which is in the range of [1, 10000].
/// All the integers in the array will be in the range of [-10000, 10000].
/// </summary>
int LeetCode::arrayPairSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (size_t i = 0; i < nums.size() / 2; i++)
    {
        sum += nums[i * 2];
    }
    return sum;
}

/// <summary>
/// Leet code #581. Shortest Unsorted Continuous Subarray
/// Given an integer array, you need to find one continuous subarray that 
/// if you only sort this subarray in ascending order, then the whole 
/// array will be sorted in ascending order, too. 
/// 
/// You need to find the shortest such subarray and output its length.
/// Example 1:
/// 
/// Input: [2, 6, 4, 8, 10, 9, 15]
/// Output: 5
/// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to 
/// make the whole array sorted in ascending order.
/// Note:
/// 1.Then length of the input array is in range [1, 10,000].
/// 2.The input array may contain duplicates, so ascending order here means 
/// <=. 
/// </summary>
int LeetCode::findUnsortedSubarray(vector<int>& nums)
{
    int first = 0, last = nums.size() - 1;
    vector<int> sorted_array(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        sorted_array[i] = nums[i];
    }
    sort(nums.begin(), nums.end());
    while (first <= last)
    {
        if (sorted_array[first] == nums[first]) first++;
        else if (sorted_array[last] == nums[last]) last--;
        else break;
    }
    return last - first + 1;
}

/// <summary>
/// Leet code #632. Smallest Range 
/// 
/// You have k lists of sorted integers in ascending order. Find the 
/// smallest range that includes at least one number from each of the 
/// k lists. 
/// We define the range [a,b] is smaller than range [c,d] if b-a < 
/// d-c or a < c if b-a == d-c.
/// Example 1:
/// Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
/// Output: [20,24]
/// Explanation: 
/// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
/// List 2: [0, 9, 12, 20], 20 is in range [20,24].
/// List 3: [5, 18, 22, 30], 22 is in range [20,24].
///
/// Note:
/// The given list may contain duplicates, so ascending order means 
/// >= here.
/// 1 <= k <= 3500
/// -10^5 <= value of elements <= 10^5.
/// For Java users, please note that the input type has been changed to 
/// List<List<Integer>>. And after you reset the code template, you'll see 
/// this point.
/// </summary>
vector<int> LeetCodeSort::smallestRange(vector<vector<int>>& nums)
{
    vector<int> range = { 0, INT_MAX };
    map<pair<int, int>, int> sort_map;

    for (size_t i = 0; i < nums.size(); i++)
    {
        sort_map[make_pair(nums[i][0], i)] = 0;
    }
    while (true)
    {
        pair<int, int> start = sort_map.begin()->first;
        pair<int, int> end = sort_map.rbegin()->first;
        if (end.first - start.first < range[1] - range[0])
        {
            range[0] = start.first;
            range[1] = end.first;
        }
        int index = sort_map.begin()->second + 1;

        // exhaust one list, game over
        if (index == nums[start.second].size()) break;

        // delete the head and move the position in that list to next
        sort_map.erase(start);
        sort_map[make_pair(nums[start.second][index], start.second)] = index;
    }

    return range;
}

/// <summary>
/// Leet code #665. Non-decreasing Array
/// 
/// Given an array with n integers, your task is to check if it could 
/// become non-decreasing by modifying at most 1 element. 
/// We define an array is non-decreasing if array[i] <= array[i + 1] holds 
/// for every i (1 <= i < n). 
/// Example 1:
/// Input: [4,2,3]
/// Output: True
/// Explanation: You could modify the first 
/// 4
/// to 
/// 1
/// to get a non-decreasing array.
///
/// Example 2:
/// Input: [4,2,1]
/// Output: False
/// Explanation: You can't get a non-decreasing array by modify at most one 
/// element.
/// 
/// Note: The n belongs to [1, 10,000]. 
/// </summary>
bool LeetCode::checkPossibility(vector<int>& nums)
{
    int decrease = 0;
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] >= nums[i - 1]) continue;
        if (((i == 1) || (nums[i] >= nums[i - 2])) ||
            ((i == nums.size() - 1) || (nums[i + 1] >= nums[i - 1])))
        {
            if (decrease == 0) decrease++;
            else return false;
        }
        else
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #692. Top K Frequent Words
///
/// Given a non-empty list of words, return the k most frequent elements.
/// Your answer should be sorted by frequency from highest to lowest. If 
/// two words have the same frequency, then the word with the lower 
/// alphabetical order comes first.
///
/// Example 1:
/// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
/// Output: ["i", "love"]
/// Explanation: "i" and "love" are the two most frequent words.
/// Note that "i" comes before "love" due to a lower alphabetical order.
/// Example 2:
/// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", 
/// "is", "is"], k = 4
/// Output: ["the", "is", "sunny", "day"]
/// Explanation: "the", "is", "sunny" and "day" are the four most frequent 
/// words, with the number of occurrence being 4, 3, 2 and 1 respectively.
/// Note:
/// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
/// Input words contain only lowercase letters.
/// Follow up:
/// 1. Try to solve it in O(n log k) time and O(n) extra space.
/// 2. Can you solve it in O(n) time with only O(k) extra space?
/// </summary>
vector<string> LeetCode::topKFrequent(vector<string>& words, int k)
{
    unordered_map<string, int> word_count;
    for (string word : words)
    {
        word_count[word]--;
    }
    set<pair<int, string>> word_map;
    for (auto itr : word_count)
    {
        word_map.insert(make_pair(itr.second, itr.first));
    }
    vector<string> result;
    for (auto itr : word_map)
    {
        result.push_back(itr.second);
        if (result.size() == k) break;
    }
    return result;
}

/// <summary>
/// Leet code #683. K Empty Slots
///
/// There is a garden with N slots. In each slot, there is a flower. The 
/// N flowers will bloom one by one in N days. In each day, there will be 
/// exactly one flower blooming and it will be in the status of blooming 
/// since then.
///
/// Given an array flowers consists of number from 1 to N. Each number in 
/// the array represents the place where the flower will open in that day.
///
/// For example, flowers[i] = x means that the unique flower that blooms 
/// at day i will be at position x, where i and x will be in the range 
/// from 1 to N.
///
/// Also given an integer k, you need to output in which day there exists 
/// two flowers in the status of blooming, and also the number of flowers 
/// between them is k and these flowers are not blooming.
/// 
/// If there isn't such day, output -1.
///
/// Example 1:
/// Input: 
/// flowers: [1,3,2]
/// k: 1
/// Output: 2
/// Explanation: In the second day, the first and the third flower have 
/// become blooming.
///
/// Example 2:
/// Input: 
/// flowers: [1,2,3]
/// k: 1
/// Output: -1
///
/// Note:
/// The given array will be in the range [1, 20000].
/// </summary>
int LeetCodeSort::kEmptySlots(vector<int>& flowers, int k)
{
    int result = -1;
    set<int> sorted_flowers;
    for (size_t i = 0; i < flowers.size(); i++)
    {
        // insert the flower first then search for position
        sorted_flowers.insert(flowers[i]);
        set<int>::iterator itr = sorted_flowers.find(flowers[i]);
        if (itr != sorted_flowers.begin())
        {
            set<int>::iterator prev = itr;
            prev--;
            if ((*itr - *prev) == k + 1)
            {
                result = i + 1;
                break;
            }
        }
        set<int>::iterator next = itr;
        next++;
        if (next != sorted_flowers.end())
        {
            if ((*next - *itr) == k + 1)
            {
                result = i + 1;
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #738. Monotone Increasing Digits
///
/// Given a non-negative integer N, find the largest number that is less than 
/// or equal to N with monotone increasing digits.
///
/// (Recall that an integer has monotone increasing digits if and only if each 
/// pair of adjacent digits x and y satisfy x <= y.)
/// 
/// Example 1:
/// Input: N = 10
/// Output: 9
/// Example 2:
/// Input: N = 1234
/// Output: 1234
/// Example 3:
/// Input: N = 332
/// Output: 299
/// Note: N is an integer in the range [0, 10^9].
/// </summary>
int LeetCode::monotoneIncreasingDigits(int N)
{
    string str_num = to_string(N);
    string buffer;
    for (size_t i = 0; i < str_num.size(); i++)
    {
        char ch = str_num[i];
        if (buffer.empty() || (ch >= buffer.back()))
        {
            buffer.push_back(str_num[i]);
        }
        else
        {
            while ((!buffer.empty()) && (ch < buffer.back()))
            {
                ch = buffer.back() - 1;
                buffer.pop_back();
            }
            buffer.push_back(ch);
            break;
        }
    }
    while (buffer.size() < str_num.size()) buffer.push_back('9');
    return atoi(buffer.c_str());
}

/// <summary>
/// Leet code #744. Find Smallest Letter Greater Than Target
///
/// Given a list of sorted characters letters containing only lowercase 
/// letters, and given a target letter target, find the smallest element 
/// in the list that is larger than the given target.
///
/// Letters also wrap around. For example, if the target is target = 'z' 
/// and letters = ['a', 'b'], the answer is 'a'.
///
/// Examples:
/// Input:
/// letters = ["c", "f", "j"]
/// target = "a"
/// Output: "c"
///
/// Input:
/// letters = ["c", "f", "j"]
/// target = "c"
/// Output: "f"
///  
/// Input:
/// letters = ["c", "f", "j"]
/// target = "d"
/// Output: "f"
///
/// Input:
/// letters = ["c", "f", "j"]
/// target = "g"
/// Output: "j"
///
/// Input:
/// letters = ["c", "f", "j"]
/// target = "j"
/// Output: "c"
///
/// Input:
/// letters = ["c", "f", "j"]
/// target = "k"
/// Output: "c"
/// Note:
/// 1. letters has a length in range [2, 10000].
/// 2. letters consists of lowercase letters, and contains at least 2 
/// unique letters.
/// target is a lowercase letter.
/// </summary> 
char LeetCode::nextGreatestLetter(vector<char>& letters, char target)
{
    int low = 0, high = letters.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (letters[mid] <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (low == letters.size())
    {
        low = 0;
    }
    return letters[low];
}

/// <summary>
/// Leet code #769. Max Chunks To Make Sorted   
///
/// Given an array arr that is a permutation of 
/// [0, 1, ..., arr.length - 1], we split the array into some number of 
/// "chunks" (partitions), and individually sort each chunk.  After 
/// concatenating them, the result equals the sorted array.
///
/// What is the most number of chunks we could have made?
///
/// Example 1:
///
/// Input: arr = [4,3,2,1,0]
/// Output: 1
/// Explanation:
/// Splitting into two or more chunks will not return the required result.
/// For example, splitting into [4, 3], [2, 1, 0] will result in 
/// [3, 4, 0, 1, 2], which isn't sorted.
///
/// Example 2:
///
/// Input: arr = [1,0,2,3,4]
/// Output: 4
/// Explanation:
/// We can split into two chunks, such as [1, 0], [2, 3, 4].
/// However, splitting into [1, 0], [2], [3], [4] is the highest number of
/// chunks possible.
/// Note:
/// arr will have length in range [1, 10].
/// arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
/// </summary>
int LeetCode::maxChunksToSorted(vector<int>& arr)
{
    deque<int> chunks;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (chunks.empty()) chunks.push_back(arr[i]);
        else
        {
            if (chunks.back() > arr[i])
            {
                int top = chunks.back();
                while ((!chunks.empty()) && (chunks.back() > arr[i])) chunks.pop_back();
                chunks.push_back(top);
            }
            else
            {
                chunks.push_back(arr[i]);
            }
        }
    }
    return chunks.size();
}

/// <summary>
/// Leetcode #768. Max Chunks To Make Sorted II
///
/// This question is the same as "Max Chunks to Make Sorted" except the 
/// integers of the given array are not necessarily distinct, the input 
/// array could be up to length 2000, and the elements could be up to 
/// 10**8.
///
/// Given an array arr of integers (not necessarily distinct), we split 
/// the array into some number of "chunks" (partitions), and individually 
/// sort each chunk.  After concatenating them, the result equals the 
/// sorted array.
///
/// What is the most number of chunks we could have made?
///
/// Example 1:
///
/// Input: arr = [5,4,3,2,1]
/// Output: 1
/// Explanation:
/// Splitting into two or more chunks will not return the required result.
/// For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 
/// 2, 3], which isn't sorted.
///
/// Example 2:
/// Input: arr = [2,1,3,4,4]
/// Output: 4
/// Explanation:
/// We can split into two chunks, such as [2, 1], [3, 4, 4].
/// However, splitting into [2, 1], [3], [4], [4] is the highest number of 
/// chunks possible.
///
/// Note:
/// arr will have length in range [1, 2000].
/// arr[i] will be an integer in range [0, 10**8].
/// </summary>
int LeetCode::maxChunksToSortedII(vector<int>& arr)
{
    deque<int> chunks;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (chunks.empty()) chunks.push_back(arr[i]);
        else
        {
            if (chunks.back() > arr[i])
            {
                int top = chunks.back();
                while ((!chunks.empty()) && (chunks.back() > arr[i])) chunks.pop_back();
                chunks.push_back(top);
            }
            else
            {
                chunks.push_back(arr[i]);
            }
        }
    }
    return chunks.size();
}

/// <summary>
/// Leetcode #774. Minimize Max Distance to Gas Station
///
/// On a horizontal number line, we have gas stations at positions 
/// stations[0], stations[1], ..., stations[N-1], where 
/// N = stations.length.
/// 
/// Now, we add K more gas stations so that D, the maximum distance 
/// between adjacent gas stations, is minimized.
/// 
/// Return the smallest possible value of D.
/// Example:
/// Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
/// Output: 0.500000
/// Note:
///
/// 1.stations.length will be an integer in range [10, 2000].
/// 2. stations[i] will be an integer in range [0, 10^8].
/// 3. K will be an integer in range [1, 10^6].
/// 4. Answers within 10^-6 of the true value will be accepted as correct.
/// </summary>
double LeetCodeSort::minmaxGasDist(vector<int>& stations, int K)
{
    if (stations.empty()) return (double)0.0;
    double total_distance = (double)stations.back() - (double)stations[0];
    priority_queue<pair<double, int>> station_plans;
    int remaining_stations = K;
    for (size_t i = 1; i < stations.size(); i++)
    {
        int extra_stations = (int)(((double)stations[i] - (double)stations[i - 1]) * K / total_distance);
        double planned_distance = ((double)stations[i] - (double)stations[i - 1]) / ((double)extra_stations + 1);
        station_plans.push(make_pair(planned_distance, (extra_stations + 1)));
        remaining_stations -= extra_stations;
    }
    while (remaining_stations != 0)
    {
        pair<double, int> plan = station_plans.top();
        station_plans.pop();
        plan.first = plan.first * plan.second / ((long long)plan.second + 1);
        plan.second++;
        station_plans.push(plan);
        remaining_stations--;
    }

    double result = station_plans.top().first;
    return result;
}

/// <summary>
/// Leetcode #775. Global and Local Inversions
///
/// We have some permutation A of [0, 1, ..., N - 1], where N is the length
/// of A.
///
/// The number of (global) inversions is the number of i < j with 
/// 0 <= i < j < N and A[i] > A[j].
///
/// The number of local inversions is the number of i with 0 <= i < N and 
/// A[i] > A[i+1].
///
/// Return true if and only if the number of global inversions is equal to 
/// the number of local inversions.
///
/// Example 1:
/// Input: A = [1,0,2]
/// Output: true
/// Explanation: There is 1 global inversion, and 1 local inversion.
///
/// Example 2:
/// Input: A = [1,2,0]
/// Output: false
/// Explanation: There are 2 global inversions, and 1 local inversion.
/// Note:
/// 
/// A will be a permutation of [0, 1, ..., A.length - 1].
/// A will have length in range [1, 5000].
/// The time limit for this problem has been reduced.
/// </summary>
bool LeetCode::isIdealPermutation(vector<int>& A)
{
    vector<pair<int, int>> nums;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (i == 0) nums.push_back(make_pair(A[i], i));
        else if ((A[i] > nums.back().first))
        {
            nums.push_back(make_pair(A[i], i));
        }
        else if ((nums.back().second == i - 1) && (nums.size() == 1 || A[i] > nums[nums.size() - 2].first))
        {
            continue;
        }
        else
        {
            return false;
        }

    }
    return true;
}

/// <summary>
/// Leetcode #775. Global and Local Inversions
///
/// We have some permutation A of [0, 1, ..., N - 1], where N is the length
/// of A.
///
/// The number of (global) inversions is the number of i < j with 
/// 0 <= i < j < N and A[i] > A[j].
///
/// The number of local inversions is the number of i with 0 <= i < N and 
/// A[i] > A[i+1].
///
/// Return true if and only if the number of global inversions is equal to 
/// the number of local inversions.
///
/// Example 1:
/// Input: A = [1,0,2]
/// Output: true
/// Explanation: There is 1 global inversion, and 1 local inversion.
///
/// Example 2:
/// Input: A = [1,2,0]
/// Output: false
/// Explanation: There are 2 global inversions, and 1 local inversion.
/// Note:
/// 
/// A will be a permutation of [0, 1, ..., A.length - 1].
/// A will have length in range [1, 5000].
/// The time limit for this problem has been reduced.
/// </summary>
bool LeetCode::isIdealPermutationII(vector<int>& A)
{
    map<int, int> num_map;
    for (size_t i = 0; i < A.size(); i++)
    {
        num_map[A[i]] = i;
        auto itr = num_map.find(A[i]);
        auto next = itr;
        next++;
        if (next == num_map.end()) continue;
        if (next->second != itr->second - 1)
        {
            return false;
        }
        next++;
        if (next != num_map.end()) return false;
    }
    return true;
}

/// <summary>
/// Leet code #798. Smallest Rotation with Highest Score
///
/// Given an array A, we may rotate it by a non-negative integer K so that 
/// the array becomes A[K], A[K+1], A{K+2], ... A[A.length - 1], A[0], 
/// A[1], ..., A[K-1].  Afterward, any entries that are less than or equal 
/// to their index are worth 1 point. 
/// For example, if we have [2, 4, 1, 3, 0], and we rotate by K = 2, it 
/// becomes [1, 3, 0, 2, 4].  This is worth 3 points because 1 > 0 
/// [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 
/// 4 <= 4 [one point].
/// Over all possible rotations, return the rotation index K that 
/// corresponds to the highest score we could receive.  If there are 
/// multiple answers, return the smallest such index K.
/// Example 1:
/// Input: [2, 3, 1, 4, 0]
/// Output: 3
/// Explanation:  
/// Scores for each K are listed below: 
/// K = 0,  A = [2,3,1,4,0],    score 2
/// K = 1,  A = [3,1,4,0,2],    score 3
/// K = 2,  A = [1,4,0,2,3],    score 3
/// K = 3,  A = [4,0,2,3,1],    score 4
/// K = 4,  A = [0,2,3,1,4],    score 3
/// So we should choose K = 3, which has the highest score.
///
/// Example 2:
/// Input: [1, 3, 0, 2, 4]
/// Output: 0
/// Explanation:  A will always have 3 points no matter how it shifts.
/// So we will choose the smallest K, which is 0.
/// Note:
/// 1. A will have length at most 20000.
/// 2. A[i] will be in the range [0, A.length].
/// </summary> 
int LeetCode::bestRotation(vector<int>& A)
{
    int result = 0;
    int max_score = 0;
    int score = A.size();
    int base = 0;
    map<int, int> score_map;

    // caluclate every delta value
    for (size_t i = 0; i < A.size(); i++)
    {
        score_map[i - A[i]]++;
    }
    for (int i = 0; i < (int)A.size(); i++)
    {
        // delete all the negative elements with 0 points;
        while ((!score_map.empty()) && (score_map.begin()->first - i < 0))
        {
            score -= score_map.begin()->second;
            score_map.erase(score_map.begin());
        }

        if (score > max_score)
        {
            max_score = score;
            result = i;
        }
        // recalculate existing ith element
        int delta = i - A[i];
        // take out current score if it is still non-negative.
        if (delta - i >= 0)
        {
            score_map[delta]--;
            score--;
        }
        // This may be always true
        if (A.size() - A[i] + i >= 0)
        {
            score_map[A.size() - A[i] + i]++;
            score++;
        }
    }

    return result;
}

/// <summary>
/// Leet code #846. Hand of Straights
/// 
/// Alice has a hand of cards, given as an array of integers.
///
/// Now she wants to rearrange the cards into groups so that each group 
/// is size W, and consists of W consecutive cards.
///
/// Return true if and only if she can.
///
/// Example 1:
/// Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
/// Output: true
/// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
///
/// Example 2:
/// Input: hand = [1,2,3,4,5], W = 4
/// Output: false
/// Explanation: Alice's hand can't be rearranged into groups of 4.
/// 
/// Note:
/// 1. 1 <= hand.length <= 10000
/// 2. 0 <= hand[i] <= 10^9
/// 3. 1 <= W <= hand.length
/// </summary>
bool LeetCodeSort::isNStraightHand(vector<int>& hand, int W)
{
    map<int, int> hand_map;
    for (size_t i = 0; i < hand.size(); i++)
    {
        hand_map[hand[i]]++;
    }

    while (!hand_map.empty())
    {
        int start = hand_map.begin()->first;
        int count = hand_map.begin()->second;

        for (int i = 0; i < W; i++)
        {
            hand_map[start + i] -= count;
            if (hand_map[start + i] == 0)
            {
                hand_map.erase(start + i);
            }
            else if (hand_map[start + i] < 0)
            {
                return false;
            }
        }
    }
    return true;
}

/// <summary>
/// Leet code #853. Car Fleet
/// 
/// N cars are going to the same destination along a one lane road.  The 
/// destination is target miles away.
///
/// Each car i has a constant speed speed[i] (in miles per hour), and initial 
/// position position[i] miles towards the target along the road.
///
/// A car can never pass another car ahead of it, but it can catch up to it, 
/// and drive bumper to bumper at the same speed.
///
/// The distance between these two cars is ignored - they are assumed to have 
/// the same position.
///
/// A car fleet is some non-empty set of cars driving at the same position 
/// and same speed.  Note that a single car is also a car fleet.
///
/// If a car catches up to a car fleet right at the destination point, it 
/// will still be considered as one car fleet.
/// 
/// How many car fleets will arrive at the destination?
/// 
/// Example 1:
///
/// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
/// Output: 3
/// Explanation:
/// The cars starting at 10 and 8 become a fleet, meeting each other at 12.
/// The car starting at 0 doesn't catch up to any other car, so it is a fleet 
/// by itself.
/// The cars starting at 5 and 3 become a fleet, meeting each other at 6.
/// Note that no other cars meet these fleets before the destination, so the 
/// answer is 3.
///
/// Note:
///
/// 1. 0 <= N <= 10 ^ 4
/// 2. 0 < target <= 10 ^ 6
/// 3. 0 < speed[i] <= 10 ^ 6
/// 4. 0 <= position[i] < target
/// 5. All initial positions are different.
/// </summary>
int LeetCode::carFleet(int target, vector<int>& position, vector<int>& speed)
{
    if (position.empty()) return 0;
    int result = 1;
    priority_queue<pair<int, int>> car_line;
    deque<pair<int, int>> car_fleet;
    for (size_t i = 0; i < position.size(); i++)
    {
        car_line.push(make_pair(position[i], speed[i]));
    }

    while (!car_line.empty())
    {
        pair<int, int> car = car_line.top();
        car_line.pop();
        if (car_fleet.empty())
        {
            car_fleet.push_back(car);
        }
        else
        {
            pair<int, int> prev = car_fleet.back();
            // slow than the previous one never merge
            if ((car.second < prev.second) || ((car.second == prev.second) && (car.first < prev.first)))
            {
                result++;
                car_fleet.pop_front();
                car_fleet.push_back(car);
            }
            else if (car.second == prev.second)
            {
                continue;
            }
            else
            {
                // the time for the previous car to reach the target
                double time1 = ((double)target - (double)prev.first) / prev.second;
                double time2 = ((double)prev.first - (double)car.first) / ((double)car.second - (double)prev.second);
                if (time1 < time2)
                {
                    result++;
                    car_fleet.pop_front();
                    car_fleet.push_back(car);
                }
                else continue;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #857. Minimum Cost to Hire K Workers
/// 
/// There are N workers.  The i-th worker has a quality[i] and a minimum 
/// wage expectation wage[i].
///
/// Now we want to hire exactly K workers to form a paid group.  When hiring 
/// a group of K workers, we must pay them according to the following rules:
///
/// Every worker in the paid group should be paid in the ratio of their 
/// quality compared to other workers in the paid group.
/// Every worker in the paid group must be paid at least their minimum wage 
/// expectation.
/// Return the least amount of money needed to form a paid group satisfying 
/// the above conditions.
///
/// 
/// Example 1:
/// Input: quality = [10,20,5], wage = [70,50,30], K = 2
/// Output: 105.00000
/// Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
///
/// Example 2:
/// Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
/// Output: 30.66667
/// Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers 
/// seperately. 
/// 
///
/// Note:
///
/// 1. 1 <= K <= N <= 10000, where N = quality.length = wage.length
/// 2. 1 <= quality[i] <= 10000
/// 3. 1 <= wage[i] <= 10000
/// 4. Answers within 10^-5 of the correct answer will be considered correct.
/// </summary>
double LeetCodeSort::mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K)
{
    vector<pair<double, int>> ratio_list;
    priority_queue<int> quality_heap;
    for (size_t i = 0; i < quality.size(); i++)
    {
        ratio_list.push_back(make_pair((double)wage[i] / 
            (double)quality[i], quality[i]));
    }
    sort(ratio_list.begin(), ratio_list.end());
    unsigned long long sum_quality = 0;
    // if we select K worker, the highest ratio worker is paid as minimum wage, 
    // for any lower wage, they are upgrade with highest ratio
    for (size_t i = 0; i < (size_t)K; i++)
    {
        quality_heap.push(ratio_list[i].second);
        sum_quality += ratio_list[i].second;
    }
    double ratio = ratio_list[K - 1].first;
    double result = ratio * sum_quality;

    // we keep on raise the ratio, but because we may have the lower quality 
    // and wage, we may end up with lower minimum total wage
    for (size_t i = K; i < quality.size(); i++)
    {
        sum_quality -= quality_heap.top();
        quality_heap.pop();
        quality_heap.push(ratio_list[i].second);
        sum_quality += ratio_list[i].second;
        ratio = ratio_list[i].first;
        result = min(result, ratio * sum_quality);
    }
    return result;
}

/// <summary>
/// Leet code #870. Advantage Shuffle
/// 
/// Given two arrays A and B of equal size, the advantage of A with respect 
/// to B is the number of indices i for which A[i] > B[i].
///
/// Return any permutation of A that maximizes its advantage with respect 
/// to B.
/// 
/// Example 1:
/// Input: A = [2,7,11,15], B = [1,10,4,11]
/// Output: [2,11,7,15]
///
/// Example 2:
/// Input: A = [12,24,8,32], B = [13,25,32,11]
/// Output: [24,32,8,12]
/// 
/// Note:
/// 1. 1 <= A.length = B.length <= 10000
/// 2. 0 <= A[i] <= 10^9
/// 3. 0 <= B[i] <= 10^9
/// </summary>
vector<int> LeetCode::advantageCount(vector<int>& A, vector<int>& B)
{
    vector<int> result(A.size());
    vector<int> X = A;
    priority_queue<pair<int, int>> sort_b;
    for (size_t i = 0; i < B.size(); i++)
    {
        sort_b.push(make_pair(B[i], i));
    }
    sort(X.begin(), X.end());
    int first = 0;
    int last = X.size() - 1;
    while (!sort_b.empty())
    {
        pair<int, int> b_num = sort_b.top();
        sort_b.pop();
        if (b_num.first < X[last])
        {
            result[b_num.second] = X[last];
            last--;
        }
        else
        {
            result[b_num.second] = X[first];
            first++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #881. Boats to Save People
/// 
/// The i-th person has weight people[i], and each boat can carry a maximum 
/// weight of limit.
///
/// Each boat carries at most 2 people at the same time, provided the sum of 
/// the weight of those people is at most limit.
///
/// Return the minimum number of boats to carry every given person.  (It is 
/// guaranteed each person can be carried by a boat.)
///
/// Example 1:
///
/// Input: people = [1,2], limit = 3
/// Output: 1
/// Explanation: 1 boat (1, 2)
///
/// Example 2:
///
/// Input: people = [3,2,2,1], limit = 3
/// Output: 3
/// Explanation: 3 boats (1, 2), (2) and (3)
///
/// Example 3:
/// 
/// Input: people = [3,5,3,4], limit = 5
/// Output: 4
/// Explanation: 4 boats (3), (3), (4), (5)
/// Note:
/// 
/// 1. 1 <= people.length <= 50000
/// 2. 1 <= people[i] <= limit <= 30000
/// </summary>
int LeetCode::numRescueBoats(vector<int>& people, int limit)
{
    int result = 0;
    sort(people.begin(), people.end());
    int first = 0; 
    int last = people.size() - 1;
    while (first <= last)
    {
        if (people[first] + people[last] <= limit)
        {
            first++;
        }
        last--;
        result++;
    }
    return result;
}

/// <summary>
/// Leet code #941. Valid Mountain Array
/// 
/// Given an array A of integers, return true if and only if it is a valid 
/// mountain array.
///
/// Recall that A is a mountain array if and only if:
///
/// A.length >= 3
/// There exists some i with 0 < i < A.length - 1 such that:
/// A[0] < A[1] < ... A[i-1] < A[i]
/// A[i] > A[i+1] > ... > A[B.length - 1]
/// 
///
/// Example 1:
/// Input: [2,1]
/// Output: false
///
/// Example 2:
/// Input: [3,5,5]
/// Output: false
///
/// Example 3:
/// Input: [0,3,2,1]
/// Output: true
///
/// Note:
/// 1. 0 <= A.length <= 10000
/// 2. 0 <= A[i] <= 10000 
/// </summary>
bool LeetCode::validMountainArray(vector<int>& A)
{
    int prev = 0;
    for (size_t i = 1; i < A.size(); i++)
    {
        if (A[i] == A[i - 1]) return false;
        else if (A[i] > A[i - 1])
        {
            if (prev == -1) return false;
            prev = 1;
        }
        else
        {
            if (prev == 0) return false;
            prev = -1;
        }
    }
    if (prev == -1) return true;
    else return false;
}

/// <summary>
/// Leet code #942. DI String Match
/// 
/// Given a string S that only contains "I" (increase) or "D" (decrease), 
/// let N = S.length.
///
/// Return any permutation A of [0, 1, ..., N] such that for all 
/// i = 0, ..., N-1:
///
/// If S[i] == "I", then A[i] < A[i+1]
/// If S[i] == "D", then A[i] > A[i+1]
/// 
/// Example 1:
/// Input: "IDID"
/// Output: [0,4,1,3,2]
///
/// Example 2:
/// Input: "III"
/// Output: [0,1,2,3]
///
/// Example 3:
/// Input: "DDI"
/// Output: [3,2,0,1]
/// 
///
/// Note:
/// 
/// 1. 1 <= S.length <= 10000
/// 2. S only contains characters "I" or "D".
/// </summary>
vector<int> LeetCode::diStringMatch(string S)
{
    vector<int> result(S.size() + 1);
    int first = 0;
    int last = S.size();

    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == 'I')
        {
            result[i] = first;
            first++;
        }
        else
        {
            result[i] = last;
            last--;
        }
    }
    result[S.size()] = first;
    return result;
}

/// <summary>
/// Leet code #953. Verifying an Alien Dictionary
/// 
/// In an alien language, surprisingly they also use english lowercase 
/// letters, but possibly in a different order. The order of the alphabet 
/// is some permutation of lowercase letters.
///
/// Given a sequence of words written in the alien language, and the order 
/// of the alphabet, return true if and only if the given words are sorted 
/// lexicographicaly in this alien language.
///
/// Example 1:
/// Input: words = ["hello","leetcode"], 
/// order = "hlabcdefgijkmnopqrstuvwxyz"
/// Output: true
/// Explanation: As 'h' comes before 'l' in this language, then the 
/// sequence is sorted.
///
/// Example 2:
/// Input: words = ["word","world","row"], 
/// order = "worldabcefghijkmnpqstuvxyz"
/// Output: false
/// Explanation: As 'd' comes after 'l' in this language, then 
/// words[0] > words[1], hence the sequence is unsorted.
///
/// Example 3:
/// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
/// Output: false
/// Explanation: The first three characters "app" match, and the second 
/// string is shorter (in size.) According to lexicographical rules 
/// "apple" > "app", because 'l' > '\0', where '\0' is defined as the 
/// blank character which is less than any other character (More info).
/// 
/// Note:
/// 1. 1 <= words.length <= 100
/// 2. 1 <= words[i].length <= 20
/// 3. order.length == 26
/// 4. All characters in words[i] and order are english lowercase letters.
/// </summary>
bool LeetCode::isAlienSorted(vector<string>& words, string order)
{
    vector<int> alpha_map(26);
    for (size_t i = 0; i < order.size(); i++)
    {
        alpha_map[order[i] - 'a'] = i;
    }
    for (size_t i = 1; i < words.size(); i++)
    {
        for (size_t j = 0; j < words[i-1].size(); j++)
        {
            // the next string shorter
            if (j == words[i].size()) return false;
            if (alpha_map[words[i - 1][j] - 'a'] > alpha_map[words[i][j] - 'a']) return false;
            if (alpha_map[words[i - 1][j] - 'a'] < alpha_map[words[i][j] - 'a']) break;
        }
    }
    return true;
}

/// <summary>
/// Leet code #954. Array of Doubled Pairs
/// 
/// Given an array of integers A with even length, return true if and only 
/// if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] 
/// for every 0 <= i < len(A) / 2.
///  
/// Example 1:
/// Input: [3,1,3,6]
/// Output: false
///
/// Example 2:
/// Input: [2,1,2,6]
/// Output: false
///
/// Example 3:
/// Input: [4,-2,2,-4]
/// Output: true
/// Explanation: We can take two groups, [-2,-4] and [2,4] to form 
/// [-2,-4,2,4] or [2,4,-2,-4].
///
/// Example 4:
/// Input: [1,2,4,16,8,4]
/// Output: false
///
/// Note:
/// 1. 0 <= A.length <= 30000
/// 2. A.length is even
/// 3. -100000 <= A[i] <= 100000
/// </summary>
bool LeetCode::canReorderDoubled(vector<int>& A)
{
    map<int, int> number_map;
    for (auto a : A) number_map[a]++;

    while (!number_map.empty())
    {
        int current = number_map.begin()->first;
        int count = number_map.begin()->second;
        number_map.erase(current);
        if (current == 0 && (count % 2) == 0) continue;
        int next;
        if (current < 0) next = current / 2;
        else next = current * 2;
        if (number_map.count(next)  == 0 || number_map[next] < count) return false;
        number_map[next] -= count;
        if (number_map[next] == 0)
        number_map.erase(next);
    }
    return true;
}

/// <summary>
/// Leet code #955. Delete Columns to Make Sorted II
/// 
/// We are given an array A of N lowercase letter strings, all of the same 
/// length.
///
/// Now, we may choose any set of deletion indices, and for each string, 
/// we delete all the characters in those indices.
///
/// For example, if we have an array A = ["abcdef","uvwxyz"] and deletion 
/// indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].
///
/// Suppose we chose a set of deletion indices D such that after deletions, 
/// the final array has its elements in lexicographic order 
/// (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).
///
/// Return the minimum possible value of D.length.
///
/// Example 1:
/// Input: ["ca","bb","ac"]
/// Output: 1
/// Explanation: 
/// After deleting the first column, A = ["a", "b", "c"].
/// Now A is in lexicographic order (ie. A[0] <= A[1] <= A[2]).
/// We require at least 1 deletion since initially A was not in 
/// lexicographic order, so the answer is 1.
///
/// Example 2:
/// Input: ["xc","yb","za"]
/// Output: 0
/// Explanation: 
/// A is already in lexicographic order, so we don't need to delete 
/// anything.
/// Note that the rows of A are not necessarily in lexicographic order:
/// ie. it is NOT necessarily true that (A[0][0] <= A[0][1] <= ...)
///
/// Example 3:
/// Input: ["zyx","wvu","tsr"]
/// Output: 3
/// Explanation: 
/// We have to delete every column.
///  
/// Note:
/// 1. 1 <= A.length <= 100
/// 2. 1 <= A[i].length <= 100
/// </summary>
int LeetCode::minDeletionSizeII(vector<string>& A)
{
    int result = 0;
    vector<int> flag(A.size(), -1), remove(A[0].size());

    for (size_t i = 0; i < A[0].size(); i++)
    {
        for (size_t j = 1; j < A.size(); j++)
        {
            // already say remove this column
            if (remove[i] != 0) break;

            // already marked as lexicon order
            if (flag[j] != -1 && remove[flag[j]] == 0)
            {
                continue;
            }

            // violation
            if (A[j - 1][i] > A[j][i])
            {
                result++;
                remove[i] = 1;
            }
            else if (A[j - 1][i] < A[j][i])
            {
                if (flag[j] == -1 || remove[flag[j]] != 0)
                {
                    flag[j] = i;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #962. Maximum Width Ramp
/// 
/// Given an array A of integers, a ramp is a tuple (i, j) for which i < j 
/// and A[i] <= A[j].  The width of such a ramp is j - i.
///
/// Find the maximum width of a ramp in A.  If one doesn't exist, return 0.
/// 
/// Example 1:
///
/// Input: [6,0,8,2,1,5]
/// Output: 4
/// Explanation: 
/// The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and 
/// A[5] = 5.
///
/// Example 2:
///
/// Input: [9,8,1,0,1,9,4,0,4,1]
/// Output: 7
/// Explanation: 
/// The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and 
/// A[9] = 1.
///
/// Note:
///
/// 1. 2 <= A.length <= 50000
/// 2. 0 <= A[i] <= 50000
/// </summary>
int LeetCode::maxWidthRamp(vector<int>& A)
{
    vector<int> list;
    map<int, int> val_map;
    int result = 0;
    for (int i = 0; i < (int)A.size(); i++)
    {
        auto itr = val_map.lower_bound(-A[i]);
        if (itr != val_map.end())
        {
            result = max(result, i - itr->second);
        }
        if (list.empty() || list.back() > A[i])
        {
            list.push_back(A[i]);
            val_map[-A[i]] = i;
        }
    }
    return result;
}

/// <summary>
/// Leet code #977. Squares of a Sorted Array
/// 
/// Given an array of integers A sorted in non-decreasing order, return 
/// an array of the squares of each number, also in sorted 
/// non-decreasing order.
/// 
/// Example 1:
/// Input: [-4,-1,0,3,10]
/// Output: [0,1,9,16,100]
///
/// Example 2:
/// Input: [-7,-3,2,3,11]
/// Output: [4,9,9,49,121]
///
/// Note:
/// 1. 1 <= A.length <= 10000
/// 2. -10000 <= A[i] <= 10000
/// 3. A is sorted in non-decreasing order.
/// </summary>
vector<int> LeetCode::sortedSquares(vector<int>& A)
{
    vector<int> result;
    for (size_t i = 0; i < A.size(); i++)
    {
        result.push_back(A[i]*A[i]);
    }
    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #912. Sort an Array
/// 
/// Given an array of integers nums, sort the array in ascending order.
/// 
/// Example 1:
/// 
/// Input: [5,2,3,1]
/// Output: [1,2,3,5]
///
/// Example 2:
///
/// Input: [5,1,1,2,0,0]
/// Output: [0,0,1,1,2,5]
/// 
/// Note:
/// 
/// 1. 1 <= A.length <= 10000
/// 2. -50000 <= A[i] <= 50000
/// </summary>
vector<int> LeetCode::sortArray(vector<int>& nums)
{
    vector<int> result = nums;
    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #1029. Two City Scheduling
/// 
/// There are 2N people a company is planning to interview. The cost of flying 
/// the i-th person to city A is costs[i][0], and the cost of flying the i-th 
/// person to city B is costs[i][1].
/// 
/// Return the minimum cost to fly every person to a city such that exactly N 
/// people arrive in each city.
/// 
/// Example 1:
///
/// Input: [[10,20],[30,200],[400,50],[30,20]]
/// Output: 110
/// Explanation: 
/// The first person goes to city A for a cost of 10.
/// The second person goes to city A for a cost of 30.
/// The third person goes to city B for a cost of 50.
/// The fourth person goes to city B for a cost of 20.
///
/// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people 
/// interviewing in each city.
///  
/// Note:
/// 1. 1 <= costs.length <= 100
/// 2. It is guaranteed that costs.length is even.
/// 3. 1 <= costs[i][0], costs[i][1] <= 1000
/// </summary>
int LeetCode::twoCitySchedCost(vector<vector<int>>& costs)
{
    int result = 0;
    priority_queue<int> cost_diff;
    for (size_t i = 0; i < costs.size(); i++)
    {
        result += costs[i][0];
        cost_diff.push(costs[i][0] - costs[i][1]);
    }
    for (size_t i = 0; i < costs.size() / 2; i++)
    {
        result -= cost_diff.top();
        cost_diff.pop();
    }
    return result;
}

/// <summary>
/// Leet code #1046. Last Stone Weight
/// 
/// We have a collection of rocks, each rock has a positive integer weight.
/// Each turn, we choose the two heaviest rocks and smash them together.  
/// Suppose the stones have weights x and y with x <= y.  The result of this 
/// smash is:
/// If x == y, both stones are totally destroyed;
/// If x != y, the stone of weight x is totally destroyed, and the stone of 
/// weight y has new weight y-x.
/// At the end, there is at most 1 stone left.  Return the weight of this 
/// stone (or 0 if there are no stones left.)
/// 
/// Example 1:
/// Input: [2,7,4,1,8,1]
/// Output: 1
/// Explanation: 
/// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
/// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
/// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
/// we combine 1 and 1 to get 0 so the array converts to [1] then that's the 
/// value of last stone.
/// 
/// Note:
/// 1. 1 <= stones.length <= 30
/// 2. 1 <= stones[i] <= 1000
/// </summary>
int LeetCode::lastStoneWeight(vector<int>& stones)
{
    priority_queue<int> pq;
    for (size_t i = 0; i < stones.size(); i++)
    {
        pq.push(stones[i]);
    }
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if (y < x) pq.push(x - y);
    }
    if (pq.empty()) return 0;
    else return pq.top();
}

/// <summary>
/// Leet code #1051. Height Checker
/// 
/// Students are asked to stand in non-decreasing order of heights for an 
/// annual photo.
///
/// Return the minimum number of students not standing in the right 
/// positions.  (This is the number of students that must move in order 
/// for all students to be standing in non-decreasing order of height.)
///
/// Example 1:
///
/// Input: [1,1,4,2,1,3]
/// Output: 3
/// Explanation: 
/// Students with heights 4, 3 and the last 1 are not standing in the right 
/// positions.
/// 
/// Note:
/// 
/// 1. 1 <= heights.length <= 100
/// 2. 1 <= heights[i] <= 100
/// </summary>
int LeetCode::heightChecker(vector<int>& heights)
{
    vector<int> sorted = heights;
    std::sort(sorted.begin(), sorted.end());
    int result = 0;
    for (size_t i = 0; i < heights.size(); i++)
    {
        if (sorted[i] != heights[i]) result++;
    }
    return result;
}


/// <summary>
/// Leet code #1053. Previous Permutation With One Swap
/// 
/// Given an array A of positive integers (not necessarily distinct), return 
/// the lexicographically largest permutation that is smaller than A, that 
/// can be made with one swap (A swap exchanges the positions of two numbers 
/// A[i] and A[j]).  If it cannot be done, then return the same array.
///
/// Example 1:
///
/// Input: [3,2,1]
/// Output: [3,1,2]
/// Explanation: Swapping 2 and 1.
///
/// Example 2:
///
/// Input: [1,1,5]
/// Output: [1,1,5]
/// Explanation: This is already the smallest permutation.
///
/// Example 3:
///
/// Input: [1,9,4,6,7]
/// Output: [1,7,4,6,9]
/// Explanation: Swapping 9 and 7.
///
/// Example 4:
///
/// Input: [3,1,1,3]
/// Output: [1,3,1,3]
/// Explanation: Swapping 1 and 3.
/// 
///
/// Note:
///
/// 1. 1 <= A.length <= 10000
/// 2. 1 <= A[i] <= 10000
/// </summary>
vector<int> LeetCode::prevPermOpt1(vector<int>& A)
{
    vector<int> result = A;
    int first = -1;
    int second = -1;
    for (size_t i = 1; i < result.size(); i++)
    {
        if (result[i] < result[i - 1])
        {
            first = i - 1;
            second = i;
        }
        else
        {
            if (first >= 0)
            {
                if (result[i] < result[first] && result[i] > result[second]) second = i;
            }
        }
    }
    if (first >= 0)
    {
        std::swap(result[first], result[second]);
    }
    return result;
}

/// <summary>
/// Leet code #1090. Largest Values From Labels
/// 
/// We have a set of items: the i-th item has value values[i] and label 
/// labels[i].
///
/// Then, we choose a subset S of these items, such that:
/// |S| <= num_wanted
/// For every label L, the number of items in S with label L is <= 
/// use_limit.
/// Return the largest possible sum of the subset S.
///
/// Example 1:
/// Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, 
/// use_limit = 1
/// Output: 9
/// Explanation: The subset chosen is the first, third, and fifth item.
///
/// Example 2: 
/// Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, 
/// use_limit = 2
/// Output: 12
/// Explanation: The subset chosen is the first, second, and third item.
///
/// Example 3:
/// Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, 
/// use_limit = 1
/// Output: 16
/// Explanation: The subset chosen is the first and fourth item.
///
/// Example 4:
/// Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, 
/// use_limit = 2
/// Output: 24
/// Explanation: The subset chosen is the first, second, and fourth item.
/// 
///
/// Note:
///
/// 1. 1 <= values.length == labels.length <= 20000
/// 2. 0 <= values[i], labels[i] <= 20000
/// 3. 1 <= num_wanted, use_limit <= values.length
/// </summary>
int LeetCode::largestValsFromLabels(vector<int>& values, vector<int>& labels,
    int num_wanted, int use_limit)
{
    vector<pair<int, int>> val_lab;
    for (size_t i = 0; i < values.size(); i++)
    {
        val_lab.push_back(make_pair(values[i], labels[i]));
    }
    sort(val_lab.begin(), val_lab.end(), std::greater<pair<int, int>>());
    unordered_map<int, int> use_map;
    int result = 0;
    for (size_t i = 0; i < (int)val_lab.size(); i++)
    {
        if (use_map[val_lab[i].second] == use_limit)
        {
            continue;
        }
        if (num_wanted == 0) break;
        result += val_lab[i].first;
        num_wanted--;
        use_map[val_lab[i].second]++;
    }
    return result;
}

/// <summary>
/// Leet code #1086. High Five
/// 
/// Given a list of scores of different students, return the average 
/// score of each student's top five scores in the order of each 
/// student's id.
/// Each entry items[i] has items[i][0] the student's id, and items[i][1] 
/// the student's score.  The average score is calculated using integer 
/// division.
///
/// Example 1:
/// Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],
///        [1,100],[2,100],[2,76]]
/// Output: [[1,87],[2,88]]
/// Explanation: 
/// The average of the student with id = 1 is 87.
/// The average of the student with id = 2 is 88.6. But with integer 
/// division their average converts to 88.
///
/// Note:
/// 1. 1 <= items.length <= 1000
/// 2. items[i].length == 2
/// 3. The IDs of the students is between 1 to 1000
/// 4. The score of the students is between 1 to 100
/// 5. For each student, there are at least 5 scores
/// </summary>
vector<vector<int>> LeetCode::highFive(vector<vector<int>>& items)
{
    map<int, multiset<int>> scores;
    vector<vector<int>> result;

    for (size_t i = 0; i < items.size(); i++)
    {
        int id = items[i][0];
        scores[id].insert(items[i][1]);
        if (scores[id].size() > 5) scores[id].erase(scores[id].begin());
    }

    for (auto itr : scores)
    {
        int score = 0;
        for (auto x : itr.second)
        {
            score += x;
        }
        score /= 5;
        result.push_back({ itr.first, score });
    }
    return result;
}

/// <summary>
/// Leet code #1099. Two Sum Less Than K
/// 
/// Given an array A of integers and integer K, return the maximum S such 
/// that there exists i < j with A[i] + A[j] = S and S < K. If no i, j 
/// exist satisfying this equation, return -1.
/// 
/// Example 1:
/// Input: A = [34,23,1,24,75,33,54,8], K = 60
/// Output: 58
/// Explanation: 
/// We can use 34 and 24 to sum 58 which is less than 60.
///
/// Example 2:
/// Input: A = [10,20,30], K = 15
/// Output: -1
/// Explanation: 
/// In this case it's not possible to get a pair sum less that 15.
/// </summary>
int LeetCode::twoSumLessThanK(vector<int>& A, int K)
{
    set<int> heap;
    int result = -1;
    for (auto x : A)
    {
        if (heap.empty()) heap.insert(x);
        else
        {
            auto itr = heap.lower_bound(K - x);
            if (itr != heap.begin())
            {
                itr--;
                result = max(result, *itr + x);
            }
            heap.insert(x);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1122. Relative Sort Array
/// 
/// Given two arrays arr1 and arr2, the elements of arr2 are distinct, 
/// and all elements in arr2 are also in arr1.
///
/// Sort the elements of arr1 such that the relative ordering of items 
/// in arr1 are the same as in arr2.  Elements that don't appear in arr2 
/// should be placed at the end of arr1 in ascending order.
///
/// 
/// Example 1:
/// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
/// Output: [2,2,2,1,4,3,3,9,6,7,19]
/// 
/// 
/// Constraints:
///
/// 1. arr1.length, arr2.length <= 1000
/// 2. 0 <= arr1[i], arr2[i] <= 1000
/// 3. Each arr2[i] is distinct.
/// 4. Each arr2[i] is in arr1.
/// </summary>
vector<int> LeetCode::relativeSortArray(vector<int>& arr1, vector<int>& arr2)
{
    vector<pair<int, int>> arr;
    unordered_map<int, int> num_ord;
    for (size_t i = 0; i < arr2.size(); i++)
    {
        num_ord[arr2[i]] = i;
    }
    for (size_t i = 0; i < arr1.size(); i++)
    {
        if (num_ord.count(arr1[i]) > 0)
        {
            arr.push_back(make_pair(num_ord[arr1[i]], arr1[i]));
        }
        else
        {
            arr.push_back(make_pair(arr2.size(), arr1[i]));
        }
    }
    sort(arr.begin(), arr.end());
    vector<int> result;
    for (size_t i = 0; i < arr.size(); i++)
    {
        result.push_back(arr[i].second);
    }
    return result;
}

/// <summary>
/// Leet code #1133. Largest Unique Number
/// 
/// Given an array of integers A, return the largest integer that only occurs 
/// once.
///
/// If no integer occurs once, return -1.
///
/// Example 1:
/// Input: [5,7,3,9,4,9,8,3,1]
/// Output: 8
/// Explanation: 
/// The maximum integer in the array is 9 but it is repeated. The number 8 
/// occurs only once, so it's the answer.
///
/// Example 2:
/// Input: [9,9,8,8]
/// Output: -1
/// Explanation: 
/// There is no number that occurs only once.
/// Note:
/// 1. 1 <= A.length <= 2000
/// 2. 0 <= A[i] <= 1000
/// </summary>
int LeetCode::largestUniqueNumber(vector<int>& A)
{
    map<int, int> num_map;
    for (size_t i = 0; i < A.size(); i++)
    {
        num_map[A[i]]++;
    }
    int result = -1;
    for (auto itr = num_map.rbegin(); itr != num_map.rend(); itr++)
    {
        if (itr->second == 1)
        {
            result = itr->first;
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #376. Wiggle Subsequence
/// A sequence of numbers is called a wiggle sequence if the differences between successive numbers 
/// strictly alternate between positive and negative. The first difference (if one
/// exists) may be either positive or negative. A sequence with fewer than two elements is trivially 
/// a wiggle sequence. 
/// 
/// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are 
/// alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are 
/// not wiggle sequences, the first because its first two differences are 
/// positive and the second because its last difference is zero.
///
/// Given a sequence of integers, return the length of the longest subsequence that is a 
/// wiggle sequence. A subsequence is obtained by deleting some number of elements 
/// (eventually, also zero) from the original sequence, leaving the remaining elements 
/// in their original order.
/// 
/// Examples:
/// Input: [1,7,4,9,2,5]
/// Output: 6
/// The entire sequence is a wiggle sequence.
///
/// Input: [1,17,5,10,13,15,10,5,16,8]
/// Output: 7
/// There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
///
/// Input: [1,2,3,4,5,6,7,8,9]
/// Output: 2
/// Follow up:
/// Can you do it in O(n) time? 
/// </summary>
int LeetCode::wiggleMaxLength(vector<int>& nums)
{
    int count = 0;
    int sign = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            continue;
        }
        else if (nums[i] == nums[i - 1])
        {
            count++;
            continue;
        }
        else
        {
            int new_sign = (nums[i] - nums[i - 1]) / abs(nums[i] - nums[i - 1]);
            if (new_sign == sign)
            {
                count++;
            }
            sign = new_sign;
        }
    }
    return nums.size() - count;
}

/// <summary>
/// Leet code #1169. Invalid Transactions
///
/// A transaction is possibly invalid if:
///
/// the amount exceeds $1000, or;
/// if it occurs within (and including) 60 minutes of another transaction 
/// with the same name in a different city.
/// Each transaction string transactions[i] consists of comma separated 
/// values representing the name, time (in minutes), amount, and city of 
/// the transaction.
///
/// Given a list of transactions, return a list of transactions that are 
/// possibly invalid.  You may return the answer in any order.
///
/// Example 1:
/// Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
/// Output: ["alice,20,800,mtv","alice,50,100,beijing"]
/// Explanation: The first transaction is invalid because the second 
/// transaction occurs within a difference of 60 minutes, have the same 
/// name and is in a different city. Similarly the second one is 
/// invalid too.
///
/// Example 2:
///
/// Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
/// Output: ["alice,50,1200,mtv"]
///
/// Example 3:
///
/// Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
/// Output: ["bob,50,1200,mtv"]
///  
/// Constraints:
/// 
/// 1. transactions.length <= 1000
/// 2. Each transactions[i] takes the form "{name},{time},{amount},{city}"
/// 3. Each {name} and {city} consist of lowercase English letters, and have 
///    lengths between 1 and 10.
/// 3. Each {time} consist of digits, and represent an integer between 
///    0 and 1000.
/// 4. Each {amount} consist of digits, and represent an integer between 
///    0 and 2000.
/// </summary>
vector<string> LeetCode::invalidTransactions(vector<string>& transactions)
{
    vector<pair<string, pair<int, pair<string, pair<int, int>>>>> tran_list;
    for (size_t i = 0; i < transactions.size(); i++)
    {
        string tran = transactions[i];
        size_t pos = tran.find(",");
        string name = tran.substr(0, pos);
        tran = tran.substr(pos + 1);
        pos = tran.find(",");
        int time = atoi(tran.substr(0, pos).c_str());
        tran = tran.substr(pos + 1);
        pos = tran.find(",");
        int amount = atoi(tran.substr(0, pos).c_str());
        tran = tran.substr(pos + 1);
        string city = tran;
        tran_list.push_back(make_pair(name, make_pair(time, make_pair(city, make_pair(amount, i)))));
    }
    std::sort(tran_list.begin(), tran_list.end());
    vector<int> invalid(tran_list.size());
    for (size_t i = 0; i < tran_list.size(); i++)
    {
        // amount > 1000
        if (tran_list[i].second.second.second.first > 1000)
        {
            invalid[i] = 1;
        }
        
        if (i > 0)
        {
            string this_person = tran_list[i].first;
            string this_city = tran_list[i].second.second.first;
            int this_time = tran_list[i].second.first;
            int last_index = i - 1;
            while (last_index >= 0)
            {
                string last_person = tran_list[last_index].first;
                int last_time = tran_list[last_index].second.first;
                string last_city = tran_list[last_index].second.second.first;
                if (this_person != last_person) break;
                if (this_time - last_time > 60) break;
                if (this_city != last_city)
                {
                    invalid[last_index] = 1;
                    invalid[i] = 1;
                }
                last_index--;
            }

        }
    }
    vector<string> result;
    vector<int> result_trans;
    for (size_t i = 0; i < tran_list.size(); i++)
    {
        if (invalid[i] == 1)
        {
            result_trans.push_back(tran_list[i].second.second.second.second);
        }
    }
    sort(result_trans.begin(), result_trans.end());
    for (size_t i = 0; i < result_trans.size(); i++)
    {
        result.push_back(transactions[result_trans[i]]);
    }
    return result;
}

/// <summary>
/// Leet code #1167. Minimum Cost to Connect Sticks
/// 
/// You have some sticks with positive integer lengths.
/// You can connect any two sticks of lengths X and Y into one stick by 
/// paying a cost of X + Y.  You perform this action until there is one 
/// stick remaining.
/// Return the minimum cost of connecting all the given sticks into one 
/// stick in this way.
/// 
/// Example 1:
/// Input: sticks = [2,4,3]
/// Output: 14
///
/// Example 2:
/// Input: sticks = [1,8,3,5]
/// Output: 30
///  
/// Constraints:
/// 1 <= sticks.length <= 10^4
/// 1 <= sticks[i] <= 10^4
/// </summary>
int LeetCode::connectSticks(vector<int>& sticks)
{
    int result = 0;
    priority_queue<int> heap;
    for (size_t i = 0; i < sticks.size(); i++)
    {
        heap.push(-sticks[i]);
    }
    while (heap.size() > 1)
    {
        int a = -heap.top();
        heap.pop();
        int b = -heap.top();
        heap.pop();
        result += a + b;
        heap.push(-a - b);
    }
    return result;
}

/// <summary>
/// Leet code #1182. Shortest Distance to Target Color
/// 
/// You are given an array colors, in which there are three colors: 1, 2 and 3.
/// You are also given some queries. Each query consists of two integers i 
/// and c, return the shortest distance between the given index i and the 
/// target color c. If there is no solution return -1.
/// 
/// Example 1:
/// Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
/// Output: [3,0,3]
/// Explanation: 
/// The nearest 3 from index 1 is at index 4 (3 steps away).
/// The nearest 2 from index 2 is at index 2 itself (0 steps away).
/// The nearest 1 from index 6 is at index 3 (3 steps away).
///
/// Example 2:
/// Input: colors = [1,2], queries = [[0,3]]
/// Output: [-1]
/// Explanation: There is no 3 in the array.
///  
/// Constraints:
/// 1. 1 <= colors.length <= 5*10^4
/// 2. 1 <= colors[i] <= 3
/// 3. 1 <= queries.length <= 5*10^4
/// 4. queries[i].length == 2
/// 5. 0 <= queries[i][0] < colors.length
/// 6. 1 <= queries[i][1] <= 3
/// </summary>
vector<int> LeetCode::shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries)
{
    vector<vector<int>> dp(3);
    for (size_t i = 0; i < colors.size(); i++)
    {
        dp[colors[i] - 1].push_back(i);
    }
    vector<int> result;
    for (size_t i = 0; i < queries.size(); i++)
    {
        int distance = INT_MAX;
        int color = queries[i][1] - 1;
        int pos = queries[i][0];
        int index = lower_bound(dp[color].begin(), dp[color].end(), pos) - dp[color].begin();
        if (index < (int)dp[color].size())
        {
            distance = min(distance, dp[color][index] - pos);
        }
        if (index > 0)
        {
            distance = min(distance, pos- dp[color][index - 1]);
        }
        if (distance == INT_MAX)
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(distance);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1199. Minimum Time to Build Blocks
/// 
/// You are given a list of blocks, where blocks[i] = t means that the i-th 
/// block needs t units of time to be built. A block can only be built by 
/// exactly one worker.
///
/// A worker can either split into two workers (number of workers increases 
/// by one) or build a block then go home. Both decisions cost some time.
///
/// The time cost of spliting one worker into two workers is given as an 
/// integer split. Note that if two workers split at the same time, they 
/// split in parallel so the cost would be split.
///
/// Output the minimum time needed to build all blocks.
///
/// Initially, there is only one worker.
/// 
/// Example 1:
/// Input: blocks = [1], split = 1
/// Output: 1
/// Explanation: We use 1 worker to build 1 block in 1 time unit.
///
/// Example 2:
/// Input: blocks = [1,2], split = 5
/// Output: 7
/// Explanation: We split the worker into 2 workers in 5 time units then 
/// assign each of them to a block so the cost is 5 + max(1, 2) = 7.
///
/// Example 3:
/// Input: blocks = [1,2,3], split = 1
/// Output: 4
/// Explanation: Split 1 worker into 2, then assign the first worker to 
/// the last block and split the second worker into 2.
/// Then, use the two unassigned workers to build the first two blocks.
/// The cost is 1 + max(3, 1 + max(1, 2)) = 4.
/// 
///
/// Constraints:
///
/// 1. 1 <= blocks.length <= 1000
/// 2. 1 <= blocks[i] <= 10^5
/// 3. 1 <= split <= 100
/// </summary>
int LeetCode::minBuildTime(vector<int>& blocks, int split)
{
    priority_queue<int> task_queue;
    for (size_t i = 0; i < blocks.size(); i++)
    {
        task_queue.push(-blocks[i]);
    }
    while (task_queue.size() > 1)
    {
        int task1 = -task_queue.top();
        task_queue.pop();
        int task2 = -task_queue.top();
        task_queue.pop();

        task_queue.push(-(max(task1, task2) + split));
    }
    return -task_queue.top();
}

/// <summary>
/// Leet code #300. Longest Increasing Subsequence
///  
/// Given an unsorted array of integers, find the length of longest 
/// increasing subsequence.
///
/// Example:
///
/// Input: [10,9,2,5,3,7,101,18]
/// Output: 4 
/// Explanation: The longest increasing subsequence is [2,3,7,101], 
/// therefore the length is 4. 
/// Note:
///
/// There may be more than one LIS combination, it is only necessary for 
/// you to return the length.
/// Your algorithm should run in O(n2) complexity.
/// Follow up: Could you improve it to O(n log n) time complexity?
/// </summary>
int LeetCodeSort::lengthOfLIS(vector<int>& nums)
{
    vector<int> result;
    for (int num : nums)
    {
        vector<int>::iterator iterator = 
            lower_bound(result.begin(), result.end(), num);
        if (iterator == result.end())
        {
            result.push_back(num);
        }
        else
        {
            *iterator = num;
        }
    }
    return result.size();
}

/// <summary>
/// Leet code #1213. Intersection of Three Sorted Arrays      
///
/// Given three integer arrays arr1, arr2 and arr3 sorted in strictly 
/// increasing order, return a sorted array of only the integers that 
/// appeared in all three arrays.
/// 
/// Example 1:
/// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
/// Output: [1,5]
/// Explanation: Only 1 and 5 appeared in the three arrays.
/// 
/// Constraints:
/// 1. 1 <= arr1.length, arr2.length, arr3.length <= 1000
/// 2. 1 <= arr1[i], arr2[i], arr3[i] <= 2000
/// </summary>
vector<int> LeetCodeSort::arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3)
{
    vector<int> result; 
    vector<int> index(3);
    vector<vector<int> *> p_arr(3);
    p_arr[0] = &arr1;
    p_arr[1] = &arr2;
    p_arr[2] = &arr3;
    int max_num = 0;
    priority_queue<pair<int, int>> pq;
    bool finish = false;
    while (!finish)
    {
        if (pq.empty())
        {
            for (size_t i = 0; i < 3; i++)
            {
                if (index[i] >= (int)p_arr[i]->size())
                {
                    finish = true;
                    break;
                }
                pq.push(make_pair(-p_arr[i]->operator[](index[i]), i));
                max_num = max(max_num, p_arr[i]->operator[](index[i]));
            }
        }
        if (finish) break;
        int min_num = -pq.top().first;
        if (min_num < max_num)
        {
            int i = pq.top().second;
            pq.pop();
            index[i] = lower_bound(p_arr[i]->begin(), p_arr[i]->end(), max_num) - p_arr[i]->begin();
            if (index[i] >= (int)p_arr[i]->size())
            {
                finish = true;
                break;
            }
            pq.push(make_pair(-p_arr[i]->operator[](index[i]), i));
            max_num = max(max_num, p_arr[i]->operator[](index[i]));
        }
        else
        {
            result.push_back(min_num);
            for (size_t i = 0; i < 3; i++)
            {
                index[i]++;
                pq.pop();
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #673. Number of Longest Increasing Subsequence
///
/// Given an unsorted array of integers, find the number of longest 
/// increasing subsequence.
/// 
/// Example 1:
/// Input: [1,3,5,4,7]
/// Output: 2
/// Explanation: The two longest increasing subsequence are [1, 3, 4, 7] 
/// and [1, 3, 5, 7].
///
/// Example 2:
/// Input: [2,2,2,2,2]
/// Output: 5
/// Explanation: The length of longest continuous increasing subsequence 
/// is 1, and there are 5 subsequences' length is 1, so output 5.
///
/// Note: Length of the given array will be not exceed 2000 and the answer 
/// is guaranteed to be fit in 32-bit signed int.
/// </summary>
int LeetCodeSort::findNumberOfLIS(vector<int>& nums)
{
    vector<int> seq;
    vector<map<int, int>> dp;
    // first we build the value from nums into a sequence,  
    for (size_t i = 0; i < nums.size(); i++)
    {
        int j = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
        if (j < (int)seq.size())
        {
            seq[j] = nums[i];
        }
        else
        {
            seq.push_back(nums[i]);
            dp.push_back(map<int, int>());
        }
        // calculate dp value based on current count on seq length - 1;
        if (j == 0) dp[j][nums[i]] += 1;
        else
        {
            for (auto itr : dp[j - 1])
            {
                if (itr.first < nums[i]) dp[j][nums[i]] += itr.second;
            }
        }
    }
    int result = 0;
    if (!dp.empty())
    {
        for (auto itr : dp[dp.size() - 1])
        {
            result += itr.second;
        }
    }
    return result;
}

/// <summary>
/// Leet code #354. Russian Doll Envelopes
///  
/// You have a number of envelopes with widths and heights given as a 
/// pair of integers (w, h). One envelope can fit into another if and 
/// only if both the width and height of one envelope is greater than 
/// the width and height of the other envelope.
///
/// What is the maximum number of envelopes can you Russian doll?
/// (put one inside other)
///
/// Note:
/// Rotation is not allowed.
///
/// Example:
///
/// Input: [[5,4],[6,4],[6,7],[2,3]]
/// Output: 3 
/// Explanation: The maximum number of envelopes you can Russian doll 
/// is 3 ([2,3] => [5,4] => [6,7]).
/// </summary>
int LeetCodeSort::maxEnvelopes(vector<pair<int, int>>& envelopes)
{
    vector<int> collector;
    struct envelope_order
    {
        bool operator() (pair<int, int> a, pair<int, int> b)
        {
            return ((a.first < b.first) || ((a.first == b.first) && (a.second > b.second)));
        }
    };
    std::sort(envelopes.begin(), envelopes.end(), envelope_order());
    for (pair<int, int>envelope : envelopes)
    {
        vector<int>::iterator iterator = 
            lower_bound(collector.begin(), collector.end(), envelope.second);
        if (iterator == collector.end())
        {
            collector.push_back(envelope.second);
        }
        else if (*iterator > envelope.second)
        {
            *iterator = envelope.second;
        }
    }
    return (int)collector.size();
}

/// <summary>
/// Leet code #88. Merge Sorted Array 
/// 
/// Given two sorted integer arrays nums1 and nums2, merge nums2 into 
/// nums1 as one sorted array.
///
/// Note:
///
/// The number of elements initialized in nums1 and nums2 are m and n 
/// respectively.
/// You may assume that nums1 has enough space (size that is greater 
/// or equal to m + n) to hold additional elements from nums2.
///
/// Example:
/// Input:
/// nums1 = [1,2,3,0,0,0], m = 3
/// nums2 = [2,5,6],       n = 3
///
/// Output: [1,2,2,3,5,6]
/// </summary>
void LeetCodeSort::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int index = m + n - 1;
    int pos1 = m - 1, pos2 = n - 1;
    while (index >= 0)
    {
        // no more elements in nums1, just copy remaining in nums2
        if (pos1 < 0)
        {
            nums1[index] = nums2[pos2];
            pos2--;
        }
        // no more elements in nums2, assume all sorted.
        else if (pos2 < 0)
        {
            break;
        }
        else if (nums1[pos1] > nums2[pos2])
        {
            nums1[index] = nums1[pos1];
            pos1--;
        }
        else
        {
            nums1[index] = nums2[pos2];
            pos2--;
        }
        index--;
    }
}

/// <summary>
/// Leet code #973. K Closest Points to Origin
/// 
/// We have a list of points on the plane.  Find the K closest points to the 
/// origin (0, 0).
///
/// (Here, the distance between two points on a plane is the Euclidean 
/// distance.)
///
/// You may return the answer in any order.  The answer is guaranteed to be 
/// unique (except for the order that it is in.)
///
/// Example 1:
///
/// Input: points = [[1,3],[-2,2]], K = 1
/// Output: [[-2,2]]
/// Explanation: 
/// The distance between (1, 3) and the origin is sqrt(10).
/// The distance between (-2, 2) and the origin is sqrt(8).
/// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
/// We only want the closest K = 1 points from the origin, so the answer is 
/// just [[-2,2]].
///
/// Example 2:
/// 
/// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
/// Output: [[3,3],[-2,4]]
/// (The answer [[-2,4],[3,3]] would also be accepted.)
/// 
/// Note:
/// 
/// 1. 1 <= K <= points.length <= 10000
/// 2. -10000 < points[i][0] < 10000
/// 3. -10000 < points[i][1] < 10000
/// </summary>
vector<vector<int>> LeetCodeSort::kClosest(vector<vector<int>>& points, int K)
{
    map<double, vector<int>> selection;
    for (size_t i = 0; i < points.size(); i++)
    {
        double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
        selection[-distance] = points[i];
        if (selection.size() > (size_t) K) selection.erase(selection.begin());
    }
    vector<vector<int>> result;
    for (auto itr : selection)
    {
        result.push_back(itr.second);
    }
    return result;
}

/// <summary>
/// Leet code #414. Third Maximum Number 
///
/// Given a non-empty array of integers, return the third maximum number 
/// in this array. If it does not exist, 
/// return the maximum number. The time complexity must be in O(n).
/// Example 1:
/// Input: [3, 2, 1]
/// Output: 1
/// Explanation: The third maximum is 1.
/// 
/// Example 2:
/// Input: [1, 2]
/// Output: 2
/// Explanation: The third maximum does not exist, so the maximum (2) is 
/// returned instead.
///
/// Example 3:
/// Input: [2, 2, 3, 1]
/// Output: 1
/// Explanation: Note that the third maximum here means the third 
/// maximum distinct number.
/// Both numbers with value 2 are both considered as second maximum.
/// </summary>
int LeetCodeSort::thirdMax(vector<int>& nums)
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
///
/// Find the kth largest element in an unsorted array. Note that it 
/// is the kth largest element 
/// in the sorted order, not the kth distinct element.  
/// For example,
/// Given [3,2,1,5,6,4] and k = 2, return 5. 
/// </summary>
int LeetCodeSort::findKthLargest(vector<int>& nums, int k)
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
/// Leet code #1331. Rank Transform of an Array 
/// 
/// Easy
///
/// Given an array of integers arr, replace each element with its rank.
///
/// The rank represents how large the element is. The rank has the 
/// following rules:
///
/// Rank is an integer starting from 1.
/// The larger the element, the larger the rank. If two elements are 
/// equal, their rank must be the same.
/// Rank should be as small as possible.
///
/// Example 1:
/// Input: arr = [40,10,20,30]
/// Output: [4,1,2,3]
/// Explanation: 40 is the largest element. 10 is the smallest. 20 is 
/// the second smallest. 30 is the third smallest.
///
/// Example 2:
/// Input: arr = [100,100,100]
/// Output: [1,1,1]
/// Explanation: Same elements share the same rank.
///
/// Example 3:
/// Input: arr = [37,12,28,9,100,56,80,5,12]
/// Output: [5,3,4,2,8,6,7,1,3]
///
/// 
/// Constraints:
/// 1. 0 <= arr.length <= 10^5
/// 2. -10^9 <= arr[i] <= 10^9
/// </summary>
vector<int> LeetCodeSort::arrayRankTransform(vector<int>& arr)
{
    vector<int> result(arr.size());

    map<int, vector<int>> sorted_arr;
    for (size_t i = 0; i < arr.size(); i++)
    {
        sorted_arr[arr[i]].push_back(i);
    }
    int order = 1;
    for (auto itr : sorted_arr)
    {
        for (auto k : itr.second)
        {
            result[k] = order;
        }
        order++;
    }
    return result;
}

#pragma endregion
