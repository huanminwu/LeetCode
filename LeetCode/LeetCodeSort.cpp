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
int LeetCodeSort::maximumGap(vector<int>& nums)
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
void LeetCodeSort::sortColors(vector<int>& nums)
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
int LeetCodeSort::hIndex(vector<int>& citations)
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
void LeetCodeSort::wiggleSortII(vector<int>& nums)
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
string LeetCodeSort::largestNumber(vector<int>& nums)
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
/// Explanation: There are three 132 patterns in the 
/// sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
/// </summary>
bool LeetCodeSort::find132pattern(vector<int>& nums)
{
    if (nums.empty()) return false;
    vector<pair<int, int>> pairs(nums.size());
    stack<int> back;
    // from back to front scan 
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int back_num = nums[i];
        while(!back.empty() && back.top() < nums[i])
        {
            back_num = back.top();
            back.pop();
        }
        back.push(nums[i]);
        pairs[i] = make_pair(nums[i], back_num);
    }
    // from front to back scan 
    int front = nums[0];
    for (size_t i = 1; i < pairs.size(); i++)
    {
        if (pairs[i].first <= front)
        {
            front = pairs[i].first;
        }
        else
        {
            if (pairs[i].second < pairs[i].first && pairs[i].second > front)
            {
                return true;
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
vector<pair<int, int>> LeetCodeSort::reconstructQueue(vector<pair<int, int>>& people)
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
bool LeetCodeSort::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
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
vector<int> LeetCodeSort::countSmallerII(vector<int>& nums)
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
void LeetCodeSort::addBIT(int index, vector<int>& accu_slot)
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
int LeetCodeSort::sumBIT(int index, vector<int>& accu_slot)
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
vector<int> LeetCodeSort::countSmallerIV(vector<int>& nums)
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
void LeetCodeSort::wiggleSort(vector<int>& nums)
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
/// Medium
/// 
/// Given an integer array nums, return true if there exists a triple of 
/// indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
/// If no such indices exists, return false.
/// 
/// Example 1:
/// Input: nums = [1,2,3,4,5]
/// Output: true
/// Explanation: Any triplet where i < j < k is valid.
///
/// Example 2:
/// Input: nums = [5,4,3,2,1]
/// Output: false
/// Explanation: No triplet exists.
///
/// Example 3:
/// Input: nums = [2,1,5,0,4,6]
/// Output: true
/// Explanation: The triplet (3, 4, 5) is valid 
/// because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. -2^31 <= nums[i] <= 2^31 - 1
///
/// Follow up: Could you implement a solution that runs in O(n) 
/// time complexity and O(1) space complexity?
/// </summary>
bool LeetCodeSort::increasingTriplet(vector<int>& nums)
{
    vector<int> result;
    for (size_t i = 0; i < nums.size(); i++)
    {
        auto itr = lower_bound(result.begin(), result.end(), nums[i]);
        if (itr == result.end()) result.push_back(nums[i]);
        else *itr = nums[i];
        if (result.size() == 3) return true;
    }
    return false;
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
int LeetCodeSort::findKthNumber(int n, int k)
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
vector<double> LeetCodeSort::medianSlidingWindow(vector<int>& nums, int k)
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
int LeetCodeSort::nextGreaterElement(int n)
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
string LeetCodeSort::createMaxNumber(vector<int>& nums, int k)
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
void LeetCodeSort::createMaxNumber(string num1, string num2, string& result)
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
vector<int> LeetCodeSort::maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
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
string LeetCodeSort::splitLoopedString(vector<string>& strs)
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
int LeetCodeSort::arrayPairSum(vector<int>& nums)
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
int LeetCodeSort::findUnsortedSubarray(vector<int>& nums)
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
bool LeetCodeSort::checkPossibility(vector<int>& nums)
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
vector<string> LeetCodeSort::topKFrequent(vector<string>& words, int k)
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
int LeetCodeSort::monotoneIncreasingDigits(int N)
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
char LeetCodeSort::nextGreatestLetter(vector<char>& letters, char target)
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
int LeetCodeSort::maxChunksToSorted(vector<int>& arr)
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
int LeetCodeSort::maxChunksToSortedII(vector<int>& arr)
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
bool LeetCodeSort::isIdealPermutation(vector<int>& A)
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
bool LeetCodeSort::isIdealPermutationII(vector<int>& A)
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
int LeetCodeSort::bestRotation(vector<int>& A)
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
int LeetCodeSort::carFleet(int target, vector<int>& position, vector<int>& speed)
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
vector<int> LeetCodeSort::advantageCount(vector<int>& A, vector<int>& B)
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
bool LeetCodeSort::validMountainArray(vector<int>& A)
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
vector<int> LeetCodeSort::diStringMatch(string S)
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
bool LeetCodeSort::isAlienSorted(vector<string>& words, string order)
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
bool LeetCodeSort::canReorderDoubled(vector<int>& A)
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
int LeetCodeSort::minDeletionSizeII(vector<string>& A)
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
int LeetCodeSort::maxWidthRamp(vector<int>& A)
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
vector<int> LeetCodeSort::sortedSquares(vector<int>& A)
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
vector<int> LeetCodeSort::sortArray(vector<int>& nums)
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
int LeetCodeSort::twoCitySchedCost(vector<vector<int>>& costs)
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
int LeetCodeSort::lastStoneWeight(vector<int>& stones)
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
int LeetCodeSort::heightChecker(vector<int>& heights)
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
vector<int> LeetCodeSort::prevPermOpt1(vector<int>& A)
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
int LeetCodeSort::largestValsFromLabels(vector<int>& values, vector<int>& labels,
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
vector<vector<int>> LeetCodeSort::highFive(vector<vector<int>>& items)
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
int LeetCodeSort::twoSumLessThanK(vector<int>& A, int K)
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
vector<int> LeetCodeSort::relativeSortArray(vector<int>& arr1, vector<int>& arr2)
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
int LeetCodeSort::largestUniqueNumber(vector<int>& A)
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
int LeetCodeSort::wiggleMaxLength(vector<int>& nums)
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
vector<string> LeetCodeSort::invalidTransactions(vector<string>& transactions)
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
int LeetCodeSort::connectSticks(vector<int>& sticks)
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
vector<int> LeetCodeSort::shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries)
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
int LeetCodeSort::minBuildTime(vector<int>& blocks, int split)
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
int LeetCodeSort::findLengthOfLCIS(vector<int>& nums)
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
vector<vector<int>> LeetCodeSort::kClosest(vector<vector<int>>& points, int k)
{
    priority_queue<pair<double, int>> pq;
    for (size_t i = 0; i < points.size(); i++)
    {
        double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
        pq.push(make_pair(distance, i));
        if (pq.size() > (size_t) k) pq.pop();
    }
    vector<vector<int>> result;
    while (!pq.empty())
    {
        result.push_back(points[pq.top().second]);
        pq.pop();
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
    set<int> max_list;
    for (size_t i = 0; i < nums.size(); i++)
    {
        max_list.insert(nums[i]);
        if (max_list.size() > 3) max_list.erase(max_list.begin());
    }
    if (max_list.size() == 3)
    {
        return *max_list.begin();
    }
    else
    {
        return *max_list.rbegin();
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
int LeetCodeSort::maxNumberOfApples(vector<int>& arr)
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
/// Leet code #1365. How Many Numbers Are Smaller Than the Current Number
///
/// Easy
///
/// Given the array nums, for each nums[i] find out how many numbers 
/// in the array are smaller than it. That is, for each nums[i] you have 
/// to count the number of valid j's such that j != i and nums[j] < 
/// nums[i].
///
/// Return the answer in an array.
/// 
/// Example 1:
/// Input: nums = [8,1,2,2,3]
/// Output: [4,0,1,1,3]
/// Explanation: 
/// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
/// For nums[1]=1 does not exist any smaller number than it.
/// For nums[2]=2 there exist one smaller number than it (1). 
/// For nums[3]=2 there exist one smaller number than it (1). 
/// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
///
/// Example 2:
/// Input: nums = [6,5,4,8]
/// Output: [2,1,0,3]
///
/// Example 3:
/// Input: nums = [7,7,7,7]
/// Output: [0,0,0,0]
/// 
/// Constraints:
/// 1. 2 <= nums.length <= 500
/// 2. 0 <= nums[i] <= 100
/// </summary>
vector<int> LeetCodeSort::smallerNumbersThanCurrent(vector<int>& nums)
{
    vector<pair<int, int>> arr(nums.size());
    for (int i = 0; i < (int)nums.size(); i++)
    {
        arr[i] = make_pair(nums[i], i);
    }
    sort(arr.begin(), arr.end());
    vector<int> result(nums.size());
    int smaller = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (i > 0 && arr[i].first > arr[i - 1].first)
        {
            smaller = i;
        }
        result[arr[i].second] = smaller;
    }
    return result;
}

/// <summary>
/// Leet code #1366. Rank Teams by Votes
///
/// Medium
///
/// In a special ranking system, each voter gives a rank from highest 
/// to lowest to all teams participated in the competition.
///
/// The ordering of teams is decided by who received the most position-one
/// votes. If two or more teams tie in the first position, we consider 
/// the second position to resolve the conflict, if they tie again, we 
/// continue this process until the ties are resolved. If two or more 
/// teams are still tied after considering all positions, we rank them 
/// alphabetically based on their team letter.
///
/// Given an array of strings votes which is the votes of all voters in 
/// the ranking systems. Sort all teams according to the ranking system 
/// described above.
///
/// Return a string of all teams sorted by the ranking system.
/// 
/// Example 1:
/// Input: votes = ["ABC","ACB","ABC","ACB","ACB"]
/// Output: "ACB"
/// Explanation: Team A was ranked first place by 5 voters. No other 
/// team was voted as first place so team A is the first team.
/// Team B was ranked second by 2 voters and was ranked third by 3 voters.
/// Team C was ranked second by 3 voters and was ranked third by 2 voters.
/// As most of the voters ranked C second, team C is the second team and 
/// team B is the third.
///
/// Example 2: 
/// Input: votes = ["WXYZ","XYZW"]
/// Output: "XWYZ"
/// Explanation: X is the winner due to tie-breaking rule. X has same votes
/// as W for the first position but X has one vote as second position while 
/// W doesn't have any votes as second position. 
///
/// Example 3:
/// Input: votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
/// Output: "ZMNAGUEDSJYLBOPHRQICWFXTVK"
/// Explanation: Only one voter so his votes are used for the ranking.
///
/// Example 4:
/// Input: votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]
/// Output: "ABC"
/// Explanation: 
/// Team A was ranked first by 2 voters, second by 2 voters and third 
/// by 2 voters.
/// Team B was ranked first by 2 voters, second by 2 voters and third 
/// by 2 voters.
/// Team C was ranked first by 2 voters, second by 2 voters and third 
/// by 2 voters.
/// There is a tie and we rank teams ascending by their IDs.
///
/// Example 5:
/// Input: votes = ["M","M","M","M"]
/// Output: "M"
/// Explanation: Only team M in the competition so it has the first rank.
///
/// Constraints:
/// 1. 1 <= votes.length <= 1000
/// 2. 1 <= votes[i].length <= 26
/// 3. votes[i].length == votes[j].length for 0 <= i, j < votes.length.
/// 4. votes[i][j] is an English upper-case letter.
/// 5. All characters of votes[i] are unique.
/// 6. All the characters that occur in votes[0] also occur in votes[j] 
///    where 1 <= j < votes.length.
/// </summary>
string LeetCodeSort::rankTeams(vector<string>& votes)
{
    vector<vector<int>>scores(26, vector<int>(27));
    for (size_t i = 0; i < 26; i++)
    {
        scores[i][26] = i;
    }
    for (size_t i = 0; i < votes.size(); i++)
    {
        for (size_t j = 0; j < votes[i].size(); j++)
        {
            int p = votes[i][j] - 'A';
            scores[p][j]--;
        }
    }
    sort(scores.begin(), scores.end());
    string result;
    for (size_t i = 0; i < scores.size(); i++)
    {
        for (size_t j = 0; j < scores[i].size() - 1; j++)
        {
            if (scores[i][j] != 0)
            {
                result.push_back(scores[i][26] + 'A');
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1387. Sort Integers by The Power Value
/// 
/// Medium
///
/// The power of an integer x is defined as the number of steps needed 
/// to transform x into 1 using the following steps:
///
/// if x is even then x = x / 2
/// if x is odd then x = 3 * x + 1
/// For example, the power of x = 3 is 7 because 3 needs 7 steps to 
/// become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
///
/// Given three integers lo, hi and k. The task is to sort all integers 
/// in the interval [lo, hi] by the power value in ascending order, if 
/// two or more integers have the same power value sort them by ascending 
/// order.
///
/// Return the k-th integer in the range [lo, hi] sorted by the power 
/// value.
///
/// Notice that for any integer x (lo <= x <= hi) it is guaranteed that x 
/// will transform into 1 using these steps and that the power of x is 
/// will fit in 32 bit signed integer.
///
/// Example 1:
/// Input: lo = 12, hi = 15, k = 2
/// Output: 13
/// Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 
/// 16 --> 8 --> 4 --> 2 --> 1)
/// The power of 13 is 9 
/// The power of 14 is 17
/// The power of 15 is 17
/// The interval sorted by the power value [12,13,14,15]. For k = 2 answer 
/// is the second element which is 13.
/// Notice that 12 and 13 have the same power value and we sorted them in 
/// ascending order. Same for 14 and 15.
///
/// Example 2:
/// Input: lo = 1, hi = 1, k = 1
/// Output: 1
///
/// Example 3:
/// Input: lo = 7, hi = 11, k = 4
/// Output: 7
/// Explanation: The power array corresponding to the 
/// interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
/// The interval sorted by power is [8, 10, 11, 7, 9].
/// The fourth number in the sorted array is 7.
///
/// Example 4:
///
/// Input: lo = 10, hi = 20, k = 5
/// Output: 13
///
/// Example 5:
/// Input: lo = 1, hi = 1000, k = 777
/// Output: 570
///
/// Constraints:
/// 1. 1 <= lo <= hi <= 1000
/// 2. 1 <= k <= hi - lo + 1
/// </summary>
int LeetCodeSort::getKth(int lo, int hi, int k)
{
    vector<pair<int, int>> arr;
    for (int i = lo; i <= hi; i++)
    {
        int power = 0;
        int x = i;
        while (x != 1)
        {
            if (x % 2 == 0) x = x / 2;
            else x = 3 * x + 1;
            power++;
        }
        arr.push_back({ power, i });
    }
    sort(arr.begin(), arr.end());
    return arr[k - 1].second;
}

/// <summary>
/// Leet code #1385. Find the Distance Value Between Two Arrays
/// 
/// Easy
///
/// Given two integer arrays arr1 and arr2, and the integer d, return 
/// the distance value between the two arrays.
///
/// The distance value is defined as the number of elements arr1[i] such 
/// that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
///
/// Example 1:
/// Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
/// Output: 2
/// Explanation: 
/// For arr1[0]=4 we have: 
/// |4-10|=6 > d=2 
/// |4-9|=5 > d=2 
/// |4-1|=3 > d=2 
/// |4-8|=4 > d=2 
/// For arr1[1]=5 we have: 
/// |5-10|=5 > d=2 
/// |5-9|=4 > d=2 
/// |5-1|=4 > d=2 
/// |5-8|=3 > d=2
/// For arr1[2]=8 we have:
/// |8-10|=2 <= d=2
/// |8-9|=1 <= d=2
/// |8-1|=7 > d=2
/// |8-8|=0 <= d=2
///
/// Example 2:
/// Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
/// Output: 2
///
/// Example 3:
/// Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
/// Output: 1
/// 
/// Constraints:
/// 1. 1 <= arr1.length, arr2.length <= 500
/// 2. -10^3 <= arr1[i], arr2[j] <= 10^3
/// 3. 0 <= d <= 100
/// </summary>
int LeetCodeSort::findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
{
    sort(arr2.begin(), arr2.end());
    int result = 0;
    for (size_t i = 0; i < arr1.size(); i++)
    {
        auto index = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
        if (index > 0)
        {
            if (abs(arr2[index - 1] - arr1[i]) <= d)
            {
                continue;
            }
        }
        if (index < (int)arr2.size())
        {
            if (abs(arr2[index] - arr1[i]) <= d)
            {
                continue;
            }
        }
        result++;
    }
    return result;
}

/// <summary>
/// Leet code #1402. Reducing Dishes
/// 
/// Hard
///
/// A chef has collected data on the satisfaction level of his n dishes. 
/// Chef can cook any dish in 1 unit of time.
///
/// Like-time coefficient of a dish is defined as the time taken to cook 
/// that dish including previous dishes multiplied by its satisfaction 
/// level  i.e.  time[i]*satisfaction[i]
///
/// Return the maximum sum of Like-time coefficient that the chef can 
/// obtain after dishes preparation.
///
/// Dishes can be prepared in any order and the chef can discard some 
/// dishes to get this maximum value.
/// 
/// Example 1:
/// Input: satisfaction = [-1,-8,0,5,-9]
/// Output: 14
/// Explanation: After Removing the second and last dish, the maximum 
/// total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). 
/// Each dish is prepared in one unit of time.
///
/// Example 2:
/// Input: satisfaction = [4,3,2]
/// Output: 20
/// Explanation: Dishes can be prepared in any order, 
/// (2*1 + 3*2 + 4*3 = 20)
///
/// Example 3:
/// Input: satisfaction = [-1,-4,-5]
/// Output: 0
/// Explanation: People don't like the dishes. No dish is prepared.
///
/// Example 4:
/// Input: satisfaction = [-2,5,-1,0,3,-3]
/// Output: 35
///
/// Constraints:
/// 1. n == satisfaction.length
/// 2. 1 <= n <= 500
/// 3. -10^3 <= satisfaction[i] <= 10^3
/// </summary>
int LeetCodeSort::maxSatisfaction(vector<int>& satisfaction)
{
    priority_queue<int> pq;
    
    for (size_t i = 0; i < satisfaction.size(); i++)
    {
        pq.push(satisfaction[i]);
    }
    int result = 0;
    int sum = 0;
    while (!pq.empty())
    {
        int s = pq.top();
        pq.pop();
        if (sum + s < 0) break;
        sum += s;
        result += sum;
    }
    return result;
}

/// <summary>
/// Leet code #1403. Minimum Subsequence in Non-Increasing Order
/// 
/// Easy
///
/// Given the array nums, obtain a subsequence of the array whose sum 
/// of elements is strictly greater than the sum of the non included 
/// elements in such subsequence. 
/// 
/// If there are multiple solutions, return the subsequence with minimum 
/// size and if there still exist multiple solutions, return the 
/// subsequence with the maximum total sum of all its elements. A 
/// subsequence of an array can be obtained by erasing some 
/// (possibly zero) elements from the array. 
///
/// Note that the solution with the given constraints is guaranteed to 
/// be unique. Also return the answer sorted in non-increasing order.
/// 
/// Example 1:
/// Input: nums = [4,3,10,9,8]
/// Output: [10,9] 
/// Explanation: The subsequences [10,9] and [10,8] are minimal such 
/// that the sum of their elements is strictly greater than the sum of 
/// elements not included, however, the subsequence [10,9] has the 
/// maximum total sum of its elements. 
///
/// Example 2:
/// Input: nums = [4,4,7,6,7]
/// Output: [7,7,6] 
/// Explanation: The subsequence [7,7] has the sum of its elements 
/// equal to 14 which is not strictly greater than the sum of 
/// elements not included (14 = 4 + 4 + 6). Therefore, the 
/// subsequence [7,6,7] is the minimal satisfying the conditions. 
/// Note the subsequence has to returned in non-decreasing order.  
///
/// Example 3:
/// Input: nums = [6]
/// Output: [6]
///
/// Constraints:
/// 1. 1 <= nums.length <= 500
/// 2. 1 <= nums[i] <= 100
/// </summary>
vector<int> LeetCodeSort::minSubsequence(vector<int>& nums)
{
    vector<int> result;
    priority_queue<int> pq;
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        sum += nums[i];
    }

    int sum_r = 0;
    while (!pq.empty())
    {
        int p = pq.top();
        pq.pop();

        sum_r += p;
        result.push_back(p);
        if (sum_r > sum - sum_r) break;
    }
    return result;
}

/// <summary>
/// Leet code #1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
/// 
/// Hard
///
/// You are given an m * n matrix, mat, and an integer k, which has its rows 
/// sorted in non-decreasing order.
///
/// You are allowed to choose exactly 1 element from each row to form an 
/// array. Return the Kth smallest array sum among all possible arrays.
///
/// Example 1:
/// Input: mat = [[1,3,11],[2,4,6]], k = 5
/// Output: 7
/// Explanation: Choosing one element from each row, the first k smallest 
/// sum are:
/// [1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  
///
/// Example 2:
/// Input: mat = [[1,3,11],[2,4,6]], k = 9
/// Output: 17
///
/// Example 3:
/// Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
/// Output: 9
/// Explanation: Choosing one element from each row, the first k smallest 
/// sum are:
/// [1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. 
/// Where the 7th sum is 9.  
///
/// Example 4:
/// Input: mat = [[1,1,10],[2,2,9]], k = 7
/// Output: 12
///
/// Constraints:
/// 1. m == mat.length
/// 2. n == mat.length[i]
/// 3. 1 <= m, n <= 40
/// 4. 1 <= k <= min(200, n ^ m)
/// 5. 1 <= mat[i][j] <= 5000
/// 6. mat[i] is a non decreasing array.
/// </summary>
int LeetCodeSort::kthSmallest(vector<vector<int>>& mat, int k)
{
    int result = 0;
    vector<int> sum = mat[0];
    for (size_t i = 1; i < mat.size(); i++)
    {
        vector<int> next;
        if ((int)sum.size() > k) sum.resize(k);
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            for (size_t s = 0; s < sum.size(); s++)
            {
                next.push_back(mat[i][j] + sum[s]);
            }
        }
        sort(next.begin(), next.end());
        sum = next;
    }
    if ((int)sum.size() < k)
    {
        return (sum[sum.size() - 1]);
    }
    else
    {
        return (sum[k - 1]);
    }
}

/// <summary>
/// Leet code #1499. Max Value of Equation
/// 
/// Hard
///
/// Given an array points containing the coordinates of points on a 2D 
/// plane, sorted by the x-values, where points[i] = [xi, yi] such that 
/// xi < xj for all 1 <= i < j <= points.length. You are also given an 
/// integer k.
///
/// Find the maximum value of the equation yi + yj + |xi - xj| 
/// where |xi - xj| <= k and 1 <= i < j <= points.length. It is guaranteed 
/// that there exists at least one pair of points that satisfy the 
/// constraint |xi - xj| <= k.
///
/// Example 1:
/// Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
/// Output: 4
/// Explanation: The first two points satisfy the condition |xi - xj| <= 1 
/// and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and 
/// fourth points also satisfy the condition and give a value of 10 + -10 + 
/// |5 - 6| = 1.
/// No other pairs satisfy the condition, so we return the max of 4 and 1.
///
/// Example 2: 
/// Input: points = [[0,0],[3,0],[9,2]], k = 3
/// Output: 3
/// Explanation: Only the first two points have an absolute difference of 3 
/// or less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
///
/// Constraints:
/// 1. 2 <= points.length <= 10^5
/// 2. points[i].length == 2
/// 3. -10^8 <= points[i][0], points[i][1] <= 10^8
/// 4. 0 <= k <= 2 * 10^8
/// 5. points[i][0] < points[j][0] for all 1 <= i < j <= points.length
/// 6. xi form a strictly increasing sequence.
/// </summary>
int LeetCodeSort::findMaxValueOfEquation(vector<vector<int>>& points, int k)
{
    set<pair<int, int>> heap;
    int first = 0;
    int result = INT_MIN;
    for (int last = 0; last < (int)points.size(); last++)
    {
        while (points[last][0] - points[first][0] > k)
        {
            heap.erase(make_pair(points[first][1] - points[first][0], points[first][0]));
            first++;
        }
        if (!heap.empty())
        {
            result = max(result, heap.rbegin()->first + points[last][0] + points[last][1]);
        }
        heap.insert(make_pair(points[last][1] - points[last][0], points[last][0]));
    }
    return result;
}

/// <summary>
/// Leet code #1505. Minimum Possible Integer After at Most K Adjacent 
///                  Swaps On Digits
/// Hard
///
/// Given a string num representing the digits of a very large integer 
/// and an integer k.
///
/// You are allowed to swap any two adjacent digits of the integer at 
/// most k times.
///
/// Return the minimum integer you can obtain also as a string.
///
/// Example 1:
/// Input: num = "4321", k = 4
/// Output: "1342"
/// Explanation: The steps to obtain the minimum integer from 4321 
/// with 4 adjacent swaps are shown.
///
/// Example 2:
/// Input: num = "100", k = 1
/// Output: "010"
/// Explanation: It's ok for the output to have leading zeros, but 
/// the input is guaranteed not to have any leading zeros.
///
/// Example 3:
/// Input: num = "36789", k = 1000
/// Output: "36789"
/// Explanation: We can keep the number without any swaps.
///
/// Example 4:
/// Input: num = "22", k = 22
/// Output: "22"
///
/// Example 5:
/// Input: num = "9438957234785635408", k = 23
/// Output: "0345989723478563548"
/// Constraints:
/// 1. 1 <= num.length <= 30000
/// 2. num contains digits only and doesn't have leading zeros.
/// 3. 1 <= k <= 10^9
/// </summary>
string LeetCodeSort::minInteger(string num, int k)
{
    vector<deque<int>> gt(10);
    for (size_t i = 0; i < num.size(); i++)
    {
        int n = num[i] - '0';
        int count = 0;
        for (int j = n + 1; j < 10; j++)
        {
            count += gt[j].size();
        }
        gt[n].push_back(count);
    }
    vector<int> delta(10);
    string result = "";
    for (size_t i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (gt[j].empty()) continue;
            if (gt[j].front() + delta[j] <= k)
            {
                k -= gt[j].front() + delta[j];
                gt[j].pop_front();
                result.push_back('0' + j);
                for (int k = 0; k < j; k++)
                {
                    delta[k]--;
                }
                break;
            }
        }
    }

    return result;
}

/// <summary>
/// Leet code #1509. Minimum Difference Between Largest and Smallest Value 
///                  in Three Moves
///
/// Medium
///	
/// Given an array nums, you are allowed to choose one element of nums and 
/// change it by any value in one move.
///
/// Return the minimum difference between the largest and smallest value 
/// of nums after perfoming at most 3 moves.
///
/// Example 1:
/// Input: nums = [5,3,2,4]
/// Output: 0
/// Explanation: Change the array [5,3,2,4] to [2,2,2,2].
/// The difference between the maximum and minimum is 2-2 = 0.
///
/// Example 2:
/// Input: nums = [1,5,0,10,14]
/// Output: 1
/// Explanation: Change the array [1,5,0,10,14] to [1,1,0,1,1]. 
/// The difference between the maximum and minimum is 1-0 = 1.
///
/// Example 3:
/// Input: nums = [6,6,0,1,1,4,6]
/// Output: 2
///
/// Example 4:
/// Input: nums = [1,5,6,14,15]
/// Output: 1
/// 1. Constraints:
/// 2. 1 <= nums.length <= 10^5
/// 3. -10^9 <= nums[i] <= 10^9
/// </summary>
int LeetCodeSort::minDifference(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    int k = 3;
    int first = 0;
    int last = nums.size() - 1;
    if (last - k <= first) return 0;
    while (k > 0)
    {
        if (nums[last - k] - nums[first] > nums[last] - nums[first + k])
        {
            first++;
        }
        else
        {
            last--;
        }
        k--;
    }
    return nums[last] - nums[first];
}

/// <summary>
/// Leet code #1535. Find the Winner of an Array Game
/// 
/// Medium
///
/// Given an integer array arr of distinct integers and an integer k.
///
/// A game will be played between the first two elements of the array 
/// (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] 
/// with arr[1], the larger integer wins and remains at position 0 and the 
/// smaller integer moves to the end of the array. The game ends when an 
/// integer wins k consecutive rounds.
///
/// Return the integer which will win the game.
///
/// It is guaranteed that there will be a winner of the game.
/// 
/// Example 1:
/// Input: arr = [2,1,3,5,4,6,7], k = 2
/// Output: 5
/// Explanation: Let's see the rounds of the game:
/// Round |       arr       | winner | win_count
///   1   | [2,1,3,5,4,6,7] | 2      | 1
///   2   | [2,3,5,4,6,7,1] | 3      | 1
///   3   | [3,5,4,6,7,1,2] | 5      | 1
///   4   | [5,4,6,7,1,2,3] | 5      | 2
/// So we can see that 4 rounds will be played and 5 is the winner because 
/// it wins 2 consecutive games.
///
/// Example 2:
/// Input: arr = [3,2,1], k = 10
/// Output: 3
/// Explanation: 3 will win the first 10 rounds consecutively.
///
/// Example 3:
/// Input: arr = [1,9,8,2,3,7,6,4,5], k = 7
/// Output: 9
///
/// Example 4:
/// Input: arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
/// Output: 99
///
/// Constraints:
/// 1. 2 <= arr.length <= 10^5
/// 2. 1 <= arr[i] <= 10^6
/// 3. arr contains distinct integers.
/// 4. 1 <= k <= 10^9
/// </summary>
int LeetCodeSort::getWinner(vector<int>& arr, int k)
{
    pair<int, int> prev;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            prev = make_pair(arr[i], 0);
        }
        else
        {
            if (prev.first > arr[i])
            {
                prev.second++;
            }
            else 
            {
                prev = make_pair(arr[i], 1);
            }
            if (prev.second >= k)
            {
                break;
            }
        }
    }
    return prev.first;
}

/// <summary>
/// Leet code #1536. Minimum Swaps to Arrange a Binary Grid
/// 
/// Medium
///
/// Given an n x n binary grid, in one step you can choose two adjacent rows 
/// of the grid and swap them.
///
/// A grid is said to be valid if all the cells above the main diagonal are 
/// zeros.
///
/// Return the minimum number of steps needed to make the grid valid, or -1 
/// if the grid cannot be valid.
///
/// The main diagonal of a grid is the diagonal that starts at cell (1, 1) 
/// and ends at cell (n, n).
///
/// Example 1:
/// Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
/// Output: 3
///
/// Example 2:
/// Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
/// Output: -1
/// Explanation: All rows are similar, swaps have no effect on the grid.
///
/// Example 3:
/// Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
/// Output: 0
/// 
/// Constraints:
/// 1. n == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= n <= 200
/// 4. grid[i][j] is 0 or 1
/// </summary>
int LeetCodeSort::minSwaps(vector<vector<int>>& grid)
{
    int n = grid.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = grid[i].size() - 1; j >= 0; j--)
        {
            if (grid[i][j] == 1) break;
            count++;
        }
        arr[i] = make_pair(i, count);
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int index = -1;
        for (int j = i; j < n; j++)
        {
            if (arr[j].second >= n - (i + 1))
            {
                index = j;
                break;
            }
        }
        if (index == -1) return -1;
        result += index - i;
        for (int j = index; j > i; j--)
        {
            swap(arr[j], arr[j - 1]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1585. Check If String Is Transformable With Substring Sort 
///                  Operations
/// 
/// Hard
///
/// Given two strings s and t, you want to transform string s into 
/// string t using the following operation any number of times:
///
/// Choose a non-empty substring in s and sort it in-place so the 
/// characters are in ascending order.
/// For example, applying the operation on the underlined substring 
/// in "14234" results in "12344".
///
/// Return true if it is possible to transform string s into string t. 
/// Otherwise, return false.
///
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: s = "84532", t = "34852"
/// Output: true
/// Explanation: You can transform s into t using the following sort 
/// operations:
/// "84532" (from index 2 to 3) -> "84352"
/// "84352" (from index 0 to 2) -> "34852"
//
/// Example 2:
/// Input: s = "34521", t = "23415"
/// Output: true
/// Explanation: You can transform s into t using the following sort 
/// operations:
/// "34521" -> "23451"
/// "23451" -> "23415"
///
/// Example 3:
///
/// Input: s = "12345", t = "12435"
/// Output: false
///
/// Example 4:
/// Input: s = "1", t = "2"
///
/// Output: false
/// 
/// Constraints:
/// 1. s.length == t.length
/// 2. 1 <= s.length <= 105
/// 3. s and t only contain digits from '0' to '9'.
/// </summary>
bool LeetCodeSort::isTransformable(string s, string t)
{
    vector<queue<int>> queue(10);
    for (size_t i = 0; i < s.size(); i++)
    {
        queue[s[i] - '0'].push(i);
    }
    string temp = s;
    int first = 0; 
    int last = 0;
    while (last < (int)t.size())
    {
        if (temp[first] == '#')
        {
            first++;
        }
        else if (temp[first] == t[last])
        {
            queue[temp[first] - '0'].pop();
            first++;
            last++;
        }
        else if (temp[first] < t[last])
        {
            return false;
        }
        else
        {
            int index = t[last] - '0';
            if (queue[index].empty()) return false;
            int pos = queue[index].front();
            queue[index].pop();
            temp[pos] = '#';
            last++;
        }
    }
    return true;
}

/// <summary>
/// Leet code #1608. Special Array With X Elements Greater Than or Equal X
/// 
/// Easy
///
/// You are given an array nums of non-negative integers. nums is 
/// considered special if there exists a number x such that there are 
/// exactly x numbers in nums that are greater than or equal to x.
///
/// Notice that x does not have to be an element in nums.
///
/// Return x if the array is special, otherwise, return -1. It can be 
/// proven that if nums is special, the value for x is unique.
/// 
/// Example 1:
/// Input: nums = [3,5]
/// Output: 2
/// Explanation: There are 2 values (3 and 5) that are greater than or 
/// equal to 2.
///
/// Example 2:
/// Input: nums = [0,0]
/// Output: -1
/// Explanation: No numbers fit the criteria for x.
/// If x = 0, there should be 0 numbers >= x, but there are 2.
/// If x = 1, there should be 1 number >= x, but there are 0.
/// If x = 2, there should be 2 numbers >= x, but there are 0.
/// x cannot be greater since there are only 2 numbers in nums.
///
/// Example 3:
/// Input: nums = [0,4,3,0,4]
/// Output: 3
/// Explanation: There are 3 values that are greater than or equal to 3.
///
/// Example 4:
/// Input: nums = [3,6,7,7,0]
/// Output: -1
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 0 <= nums[i] <= 1000
/// </summary>
int LeetCodeSort::specialArray(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int result = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int count = nums.size() - i;
        if (count <= nums[i])
        {
            if (i == 0 || count > nums[i - 1])
            {
                result = count;
            }
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1606. Find Servers That Handled Most Number of Requests 
/// 
/// Hard
///
/// You have k servers numbered from 0 to k-1 that are being used to 
/// handle multiple requests simultaneously. Each server has infinite 
/// computational capacity but cannot handle more than one request at 
/// a time. The requests are assigned to servers according to a specific 
/// algorithm:
///
/// The ith (0-indexed) request arrives.
/// If all servers are busy, the request is dropped (not handled at all).
/// If the (i % k)th server is available, assign the request to that 
/// server.
/// Otherwise, assign the request to the next available server (wrapping 
/// around the list of servers and starting from 0 if necessary). For 
/// example, if the ith server is busy, try to assign the request to the 
/// (i+1)th server, then the (i+2)th server, and so on.
/// You are given a strictly increasing array arrival of positive 
/// integers, where arrival[i] represents the arrival time of the ith 
/// request, and another array load, where load[i] represents the load 
/// of the ith request (the time it takes to complete). Your goal is to 
/// find the busiest server(s). A server is considered busiest if it 
/// handled the most number of requests successfully among all the servers.
///
/// Return a list containing the IDs (0-indexed) of the busiest server(s). 
/// You may return the IDs in any order.
///
/// Example 1:
/// Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
/// Output: [1] 
/// Explanation:
/// All of the servers start out available.
/// The first 3 requests are handled by the first 3 servers in order.
/// Request 3 comes in. Server 0 is busy, so it's assigned to the next 
/// available server, which is 1.
/// Request 4 comes in. It cannot be handled since all servers are busy, 
/// so it is dropped.
/// Servers 0 and 2 handled one request each, while server 1 handled two 
/// requests. Hence server 1 is the busiest server.
///
/// Example 2:
/// Input: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
/// Output: [0]
/// Explanation:
/// The first 3 requests are handled by first 3 servers.
/// Request 3 comes in. It is handled by server 0 since the server is 
/// available.
/// Server 0 handled two requests, while servers 1 and 2 handled one 
/// request each. Hence server 0 is the busiest server.
///
/// Example 3:
/// Input: k = 3, arrival = [1,2,3], load = [10,12,11]
/// Output: [0,1,2]
/// Explanation: Each server handles a single request, so they are all 
/// considered the busiest.
///
/// Example 4:
/// Input: k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
/// Output: [1]
///
/// Example 5:
/// Input: k = 1, arrival = [1], load = [1]
/// Output: [0]
/// 
/// Constraints:
/// 1. 1 <= k <= 105
/// 2. 1 <= arrival.length, load.length <= 10^5
/// 3. arrival.length == load.length
/// 4. 1 <= arrival[i], load[i] <= 10^9
/// 5. arrival is strictly increasing.
/// </summary>
vector<int> LeetCodeSort::busiestServers(int k, vector<int>& arrival, vector<int>& load)
{
    vector<int> dp(k);
    vector<queue<int>> queue(arrival.size());
    set<int> free_servers;

    for (int i = 0; i < k; i++)
    {
        free_servers.insert(i);
    }

    for (size_t i = 0; i < arrival.size(); i++)
    {
        while (!queue[i].empty())
        {
            free_servers.insert(queue[i].front());
            queue[i].pop();
        }
        if (free_servers.empty()) continue;
        auto itr = free_servers.lower_bound(i % k);
        if (itr == free_servers.end()) itr = free_servers.begin();
        dp[*itr]++;
        int next_time = arrival[i] + load[i];
        int index = lower_bound(arrival.begin(), arrival.end(), next_time) - arrival.begin();
        if (index < (int)arrival.size())
        {
            queue[index].push(*itr);
        }
        free_servers.erase(itr);
    }
    int busy_count = 1;
    vector<int> result;
    for (size_t i = 0; i < dp.size(); i++)
    {
        if (dp[i] < busy_count) continue;
        else if (dp[i] == busy_count) result.push_back(i);
        else
        {
            busy_count = dp[i];
            result.clear();
            result.push_back(i);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1564. Put Boxes Into the Warehouse I
/// 
/// Medium
///
/// You are given two arrays of positive integers, boxes and warehouse, 
/// representing the heights of some boxes of unit width and the heights 
/// of n rooms in a warehouse respectively. The warehouse's rooms are 
/// labelled from 0 to n - 1 from left to right where warehouse[i] 
/// (0-indexed) is the height of the ith room.
///
/// Boxes are put into the warehouse by the following rules:
/// Boxes cannot be stacked.
/// You can rearrange the insertion order of the boxes.
/// Boxes can only be pushed into the warehouse from left to right only.
/// If the height of some room in the warehouse is less than the height 
/// of a box, then that box and all other boxes behind it will be stopped 
/// before that room.
/// Return the maximum number of boxes you can put into the warehouse.
///
/// Example 1:
/// Input: boxes = [4,3,4,1], warehouse = [5,3,3,4,1]
/// Output: 3
/// Explanation: 
/// We can first put the box of height 1 in room 4. Then we can put the 
/// box of height 3 in either of the 3 rooms 1, 2, or 3. Lastly, we can 
/// put one box of height 4 in room 0.
/// There is no way we can fit all 4 boxes in the warehouse.
///
/// Example 2:
/// Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
/// Output: 3
/// Explanation: 
/// Notice that it's not possible to put the box of height 4 into the 
/// warehouse since it cannot pass the first room of height 3.
/// Also, for the last two rooms, 2 and 3, only boxes of height 1 can fit.
/// We can fit 3 boxes maximum as shown above. The yellow box can also be 
/// put in room 2 instead.
/// Swapping the orange and green boxes is also valid, or swapping one of 
/// them with the red box.
///
/// Example 3:
/// Input: boxes = [1,2,3], warehouse = [1,2,3,4]
/// Output: 1
/// Explanation: Since the first room in the warehouse is of height 1, we 
/// can only put boxes of height 1.
///
/// Example 4:
/// Input: boxes = [4,5,6], warehouse = [3,3,3,3,3]
/// Output: 0
/// 
/// Constraints:
/// 1. n == warehouse.length
/// 2. 1 <= boxes.length, warehouse.length <= 10^5
/// 3. 1 <= boxes[i], warehouse[i] <= 10^9
/// </summary>
int LeetCodeSort::maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse)
{
    vector<int> new_warehouse = warehouse;
    for (int i = 1; i < (int)new_warehouse.size(); i++)
    {
        new_warehouse[i] = min(new_warehouse[i], new_warehouse[i-1]);
    }
    sort(boxes.begin(), boxes.end());
    sort(new_warehouse.begin(), new_warehouse.end());
    size_t left = 0;
    size_t right = 0;
    while (left < boxes.size() && right < new_warehouse.size())
    {
        if (boxes[left] <= new_warehouse[right])
        {
            left++;
        }
        right++;
    }
    return left;
}

/// <summary>
/// Leet code #1580. Put Boxes Into the Warehouse II
/// 
/// Medium
///
/// You are given two arrays of positive integers, boxes and warehouse, 
/// representing the heights of some boxes of unit width and the heights 
/// of n rooms in a warehouse respectively. The warehouse's rooms are 
/// labeled from 0 to n - 1 from left to right where warehouse[i] 
/// (0-indexed) is the height of the ith room.
///
/// Boxes are put into the warehouse by the following rules:
/// Boxes cannot be stacked.
/// You can rearrange the insertion order of the boxes.
/// Boxes can be pushed into the warehouse from either side (left or right)
/// If the height of some room in the warehouse is less than the height of 
/// a box, then that box and all other boxes behind it will be stopped 
/// before that room.
/// Return the maximum number of boxes you can put into the warehouse.
///
/// Example 1:
/// Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
/// Output: 4
/// Explanation:
/// We can store the boxes in the following order:
/// 1- Put the yellow box in room 2 from either the left or right side.
/// 2- Put the orange box in room 3 from the right side.
/// 3- Put the green box in room 1 from the left side.
/// 4- Put the red box in room 0 from the left side.
/// Notice that there are other valid ways to put 4 boxes such as swapping 
/// the red and green boxes or the red and orange boxes.
///
/// Example 2:
/// Input: boxes = [3,5,5,2], warehouse = [2,1,3,4,5]
/// Output: 3
/// Explanation:
/// It's not possible to put the two boxes of height 5 in the warehouse 
/// since there's only 1 room of height >= 5.
/// Other valid solutions are to put the green box in room 2 or to put the 
/// orange box first in room 2 before putting the green and red boxes.
///
/// Example 3:
/// Input: boxes = [1,2,3], warehouse = [1,2,3,4]
/// Output: 3
///
/// Example 4:
/// Input: boxes = [4,5,6], warehouse = [3,3,3,3,3]
/// Output: 0
/// 
/// Constraints:
/// 1. n == warehouse.length
/// 2. 1 <= boxes.length, warehouse.length <= 10^5
/// 3. 1 <= boxes[i], warehouse[i] <= 10^9
/// </summary>
int LeetCodeSort::maxBoxesInWarehouseII(vector<int>& boxes, vector<int>& warehouse)
{
    vector<int> new_warehouse = warehouse;
    int min_index = 0;
    int min_height = INT_MAX;
    int size = new_warehouse.size();
    for (int i = 0; i < size; i++)
    {
        if (new_warehouse[i] < min_height)
        {
            min_height = new_warehouse[i];
            min_index = i;
        }
    }
    for (int i = 1; i < min_index; i++)
    {
        new_warehouse[i] = min(new_warehouse[i], new_warehouse[i - 1]);
    }
    for (int i = size - 2; i > min_index; i--)
    {
        new_warehouse[i] = min(new_warehouse[i], new_warehouse[i + 1]);
    }
    sort(boxes.begin(), boxes.end());
    sort(new_warehouse.begin(), new_warehouse.end());
    size_t left = 0;
    size_t right = 0;
    while (left < boxes.size() && right < new_warehouse.size())
    {
        if (boxes[left] <= new_warehouse[right])
        {
            left++;
        }
        right++;
    }
    return left;
}

/// <summary>
/// Leet code #1626. Best Team With No Conflicts
/// 
/// Medium
///
/// You are the manager of a basketball team. For the upcoming tournament, 
/// you want to choose the team with the highest overall score. The score 
/// of the team is the sum of scores of all the players in the team.
///
/// However, the basketball team is not allowed to have conflicts. A 
/// conflict exists if a younger player has a strictly higher score than 
/// an older player. A conflict does not occur between players of the same 
/// age.
///
/// Given two lists, scores and ages, where each scores[i] and ages[i] 
/// represents the score and age of the ith player, respectively, return 
/// the highest overall score of all possible basketball teams.
///
/// Example 1:
/// Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
/// Output: 34
/// Explanation: You can choose all the players.
///
/// Example 2:
/// Input: scores = [4,5,6,5], ages = [2,1,2,1]
/// Output: 16
/// Explanation: It is best to choose the last 3 players. Notice that 
/// you are allowed to choose multiple people of the same age.
///
/// Example 3:
/// Input: scores = [1,2,3,5], ages = [8,9,10,1]
/// Output: 6
/// Explanation: It is best to choose the first 3 players. 
///
/// Constraints:
/// 1. 1 <= scores.length, ages.length <= 1000
/// 2. scores.length == ages.length
/// 3. 1 <= scores[i] <= 10^6
/// 4. 1 <= ages[i] <= 1000
/// </summary>
int LeetCodeSort::bestTeamScore(vector<int>& scores, vector<int>& ages)
{
    int result = 0;
    map<int, int> sorted_scores;
    sorted_scores[0] = 0;

    vector<pair<int, int>> sorted_ages;
    for (size_t i = 0; i < scores.size(); i++)
    {
        sorted_ages.push_back(make_pair(ages[i], scores[i]));
    }
    sort(sorted_ages.begin(), sorted_ages.end());
    for (size_t i = 0; i < sorted_ages.size(); i++)
    {
        sorted_scores[sorted_ages[i].second] += sorted_ages[i].second;
        auto itr = sorted_scores.lower_bound(sorted_ages[i].second);
        if (itr->second == sorted_ages[i].second)
        {
            auto pre_itr = itr;
            pre_itr--;
            itr->second += pre_itr->second;
        }
        auto next_itr = itr;
        next_itr++;
        while (next_itr != sorted_scores.end() && next_itr->second <= itr->second)
        {
            auto temp = next_itr;
            next_itr++;
            sorted_scores.erase(temp);
        }
        result = max(result, itr->second);
    }
    return result;
}

/// <summary>
/// Leet code #1632. Rank Transform of a Matrix
/// 
/// Hard
///
/// Given an m x n matrix, return a new matrix answer where 
/// answer[row][col] is the rank of matrix[row][col].
///
/// The rank is an integer that represents how large an element 
/// is compared to other elements. It is calculated using the 
/// following rules:
///
/// The rank is an integer starting from 1.
/// If two elements p and q are in the same row or column, then:
/// If p < q then rank(p) < rank(q)
/// If p == q then rank(p) == rank(q)
/// If p > q then rank(p) > rank(q)
/// The rank should be as small as possible.
/// It is guaranteed that answer is unique under the given rules.
///
/// Example 1:
/// 
///
/// Input: matrix = [[1,2],[3,4]]
/// Output: [[1,2],[2,3]]
/// Explanation:
/// The rank of matrix[0][0] is 1 because it is the smallest 
/// integer in its row and column.
/// The rank of matrix[0][1] is 2 because matrix[0][1] > 
/// matrix[0][0] and matrix[0][0] is rank 1.
/// The rank of matrix[1][0] is 2 because matrix[1][0] > 
/// matrix[0][0] and matrix[0][0] is rank 1.
/// The rank of matrix[1][1] is 3 because matrix[1][1] > matrix[0][1], 
/// matrix[1][1] > matrix[1][0], and both matrix[0][1] and matrix[1][0] 
/// are rank 2.
///
/// Example 2:
/// Input: matrix = [[7,7],[7,7]]
/// Output: [[1,1],[1,1]]
///
/// Example 3:
/// Input: matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
/// Output: [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
///
/// Example 4:
/// Input: matrix = [[7,3,6],[1,4,5],[9,8,2]]
/// Output: [[5,1,4],[1,2,3],[6,3,1]]
/// 
/// Constraints:
/// 1. m == matrix.length
/// 2. n == matrix[i].length 
/// 3. 1 <= m, n <= 500
/// 4. -10^9 <= matrix[row][col] <= 10^9
/// </summary>
vector<vector<int>> LeetCodeSort::matrixRankTransform(vector<vector<int>>& matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    map<int, vector<pair<int, int>>> value_map;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            value_map[matrix[i][j]].push_back(make_pair(i, j));
        }
    }
    vector<int> row(n);
    vector<int> col(m);
    vector<vector<int>> result(n, vector<int>(m));
    for (auto it : value_map)
    {
        vector<int> parent(m + n);
        for (int i = 0; i < n + m; i++) parent[i] = i;
        vector<int> rank(m + n);
        for (int i = 0; i < n; i++) rank[i] = row[i];
        for (int i = n; i < n+m; i++) rank[i] = col[i-n];
        for (auto a : it.second)
        {
            int r = a.first, c = a.second;
            while (parent[r] != parent[parent[r]]) parent[r] = parent[parent[r]];
            int r1 = parent[r];
            while (parent[c+n] != parent[parent[c+n]]) parent[c+n] = parent[parent[c+n]];
            int r2 = parent[c + n];
            parent[r2] = r1;  // make col point to row
            rank[r1] = max(rank[r1], rank[r2]);
        }

        for (auto a : it.second) 
        {
            int r = a.first, c = a.second;
            while (parent[r] != parent[parent[r]]) parent[r] = parent[parent[r]];
            result[r][c] = rank[parent[r]] + 1;
            row[r] = result[r][c];
            col[c] = result[r][c];
        }
    }
    return result;
}

/// <summary>
/// Leet code #1649. Create Sorted Array through Instructions
/// 
/// Hard
///
/// Given an integer array instructions, you are asked to create a sorted 
/// array from the elements in instructions. You start with an empty 
/// container nums. For each element from left to right in instructions, 
/// insert it into nums. The cost of each insertion is the minimum of the 
/// following:
///
/// The number of elements currently in nums that are strictly less than 
/// instructions[i].
/// The number of elements currently in nums that are strictly greater 
/// than instructions[i].
/// For example, if inserting element 3 into nums = [1,2,3,5], the cost of 
/// insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is 
/// greater than 3) and nums will become [1,2,3,3,5].
///
/// Return the total cost to insert all elements from instructions into nums. 
/// Since the answer may be large, return it modulo 10^9 + 7
/// 
/// Example 1: 
/// Input: instructions = [1,5,6,2]
/// Output: 1
/// Explanation: Begin with nums = [].
/// Insert 1 with cost min(0, 0) = 0, now nums = [1].
/// Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
/// Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
/// Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
/// The total cost is 0 + 0 + 0 + 1 = 1.
///
/// Example 2:
/// Input: instructions = [1,2,3,6,5,4]
/// Output: 3
/// Explanation: Begin with nums = [].
/// Insert 1 with cost min(0, 0) = 0, now nums = [1].
/// Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
/// Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
/// Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
/// Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
/// Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
/// The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
///
/// Example 3:
/// Input: instructions = [1,3,3,3,2,4,2,1,2]
/// Output: 4
/// Explanation: Begin with nums = [].
/// Insert 1 with cost min(0, 0) = 0, now nums = [1].
/// Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
/// Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
/// Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
/// Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
/// Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
/// Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
/// Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
/// The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4
/// 
/// Constraints:
/// 1. 1 <= instructions.length <= 10^5
/// 2. 1 <= instructions[i] <= 10^5
/// </summary>
int LeetCodeSort::createSortedArray(vector<int>& instructions)
{
    int M = 1000000007;
    int max_value = 100000;
    int result = 0;
    vector<int> sum(max_value+1);
    for (size_t i = 0; i < instructions.size(); i++)
    {
        int num = instructions[i];
        while (num <= max_value)
        {
            sum[num] += 1;
            num += (num & -num);
        }       
        num = instructions[i] - 1;
        int less = 0;
        while (num != 0)
        {
            less += sum[num];
            num -= (num & -num);
        }
        num = instructions[i];
        int equal = 0;
        while (num != 0)
        {
            equal += sum[num];
            num -= (num & -num);
        }
        result = (result + min(less, (int)i + 1 - equal)) % M;
    }

    return result;
}

/// <summary>
/// Leet code #1649. Create Sorted Array through Instructions
/// 
/// Hard
///
/// Given an integer array instructions, you are asked to create a sorted 
/// array from the elements in instructions. You start with an empty 
/// container nums. For each element from left to right in instructions, 
/// insert it into nums. The cost of each insertion is the minimum of the 
/// following:
///
/// The number of elements currently in nums that are strictly less than 
/// instructions[i].
/// The number of elements currently in nums that are strictly greater 
/// than instructions[i].
/// For example, if inserting element 3 into nums = [1,2,3,5], the cost of 
/// insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is 
/// greater than 3) and nums will become [1,2,3,3,5].
///
/// Return the total cost to insert all elements from instructions into nums. 
/// Since the answer may be large, return it modulo 10^9 + 7
/// 
/// Example 1: 
/// Input: instructions = [1,5,6,2]
/// Output: 1
/// Explanation: Begin with nums = [].
/// Insert 1 with cost min(0, 0) = 0, now nums = [1].
/// Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
/// Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
/// Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
/// The total cost is 0 + 0 + 0 + 1 = 1.
///
/// Example 2:
/// Input: instructions = [1,2,3,6,5,4]
/// Output: 3
/// Explanation: Begin with nums = [].
/// Insert 1 with cost min(0, 0) = 0, now nums = [1].
/// Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
/// Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
/// Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
/// Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
/// Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
/// The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
///
/// Example 3:
/// Input: instructions = [1,3,3,3,2,4,2,1,2]
/// Output: 4
/// Explanation: Begin with nums = [].
/// Insert 1 with cost min(0, 0) = 0, now nums = [1].
/// Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
/// Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
/// Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
/// Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
/// Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
/// Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
/// Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
/// The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4
/// 
/// Constraints:
/// 1. 1 <= instructions.length <= 10^5
/// 2. 1 <= instructions[i] <= 10^5
/// </summary>
int LeetCodeSort::createSortedArrayI(vector<int>& instructions)
{
    int M = 1000000007;
    int max_value = 100000;
    int result = 0;
    vector<int> sum(4 * max_value + 1); 
    for (size_t i = 0; i < instructions.size(); i++)
    {
        int first = 0, last = max_value;
        int index = 1;
        int num = instructions[i];
        int less = 0, greater = 0;
        while (first < last)
        {
            int middle = (first + last) / 2;
            if (num <= middle)
            {
                last = middle;
                sum[index]++;
                greater += sum[index + 1];
                index = 2 * index + 1;
            }
            else
            {
                first = middle + 1;
                sum[index+1]++;
                less += sum[index];
                index = 2 * (index + 1)+1;
            }
        }
        result = (result + min(less, greater)) % M;
    }

    return result;
}

/// <summary>
/// Leet code #1675. Minimize Deviation in Array
/// 
/// Hard
/// 
/// You are given an array nums of n positive integers.
///
/// You can perform two types of operations on any element of the array any 
/// number of times:
///
/// If the element is even, divide it by 2.
/// For example, if the array is [1,2,3,4], then you can do this operation on 
/// the last element, and the array will be [1,2,3,2].
/// If the element is odd, multiply it by 2.
/// For example, if the array is [1,2,3,4], then you can do this operation on 
/// the first element, and the array will be [2,2,3,4].
/// The deviation of the array is the maximum difference between any two 
/// elements in the array.
///
/// Return the minimum deviation the array can have after performing some 
/// number of operations.
/// 
/// Example 1:
/// Input: nums = [1,2,3,4]
/// Output: 1
/// Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], 
/// then the deviation will be 3 - 2 = 1.
///
/// Example 2:
/// Input: nums = [4,1,5,20,3]
/// Output: 3
/// Explanation: You can transform the array after two operations to 
/// [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
///
/// Example 3:
/// Input: nums = [2,10,8]
/// Output: 3
/// 
/// Constraints:
/// 1. n == nums.length
/// 2. 2 <= n <= 10^5
/// 3. 1 <= nums[i] <= 10^9
/// </summary>
int LeetCodeSort::minimumDeviation(vector<int>& nums)
{
    int result = INT_MAX;
    set<int> num_set;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 1)  num_set.insert(nums[i] * 2);
        else num_set.insert(nums[i]);
    }
    while (true)
    {
        int first = *num_set.begin();
        int last = *num_set.rbegin();
        result = min(result, last - first);
        if (last % 2 == 0)
        {
            num_set.erase(last);
            last /= 2;
            num_set.insert(last);
        }
        else
        {
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1686. Stone Game VI
/// 
/// Medium
/// 
/// Alice and Bob take turns playing a game, with Alice starting first.
///
/// There are n stones in a pile. On each player's turn, they can remove a 
/// stone from the pile and receive points based on the stone's value. Alice 
/// and Bob may value the stones differently.
///
/// You are given two integer arrays of length n, aliceValues and bobValues. 
/// Each aliceValues[i] and bobValues[i] represents how Alice and Bob, 
/// respectively, value the ith stone.
///
/// The winner is the person with the most points after all the stones are 
/// chosen. If both players have the same amount of points, the game results 
/// in a draw. Both players will play optimally.
///
/// Determine the result of the game, and:
///
/// If Alice wins, return 1.
/// If Bob wins, return -1.
/// If the game results in a draw, return 0.
/// 
/// Example 1:
/// Input: aliceValues = [1,3], bobValues = [2,1]
/// Output: 1
/// Explanation:
/// If Alice takes stone 1 (0-indexed) first, Alice will receive 3 points.
/// Bob can only choose stone 0, and will only receive 2 points.
/// Alice wins.
///
/// Example 2:
/// Input: aliceValues = [1,2], bobValues = [3,1]
/// Output: 0
/// Explanation:
/// If Alice takes stone 0, and Bob takes stone 1, they will both have 1 point.
/// Draw.
///
/// Example 3:
/// Input: aliceValues = [2,4,3], bobValues = [1,6,7]
/// Output: -1
/// Explanation:
/// Regardless of how Alice plays, Bob will be able to have more points than 
/// Alice.
/// For example, if Alice takes stone 1, Bob can take stone 2, and Alice takes 
/// stone 0, Alice will have 6 points to Bob's 7.
/// Bob wins.
///
/// Constraints:
/// 1. n == aliceValues.length == bobValues.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= aliceValues[i], bobValues[i] <= 100
/// </summary>
int LeetCodeSort::stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues)
{
    vector<pair<int, int>> hp;
    for (size_t i = 0; i < aliceValues.size(); i++)
    {
        hp.push_back(make_pair(aliceValues[i] + bobValues[i], aliceValues[i]));
    }
    sort(hp.begin(), hp.end(), greater<pair<int, int>>());
    int alice = 0;
    int bob = 0;
    for (size_t i = 0; i < hp.size(); i++)
    {
        if (i % 2 == 0) alice += hp[i].second;
        else bob += hp[i].first - hp[i].second;
    }
    if (alice == bob) return 0;
    else if (alice > bob) return 1;
    else return -1;
}


/// <summary>
/// Leet code #1705. Maximum Number of Eaten Apples
/// 
/// Medium
/// 
/// There is a special kind of apple tree that grows apples every day 
/// for n days. On the ith day, the tree grows apples[i] apples that 
/// will rot after days[i] days, that is on day i + days[i] the apples 
/// will be rotten and cannot be eaten. On some days, the apple tree 
/// does not grow any apples, which are denoted by apples[i] == 0 
/// and days[i] == 0.
///
/// You decided to eat at most one apple a day (to keep the doctors away). 
/// Note that you can keep eating after the first n days.
///
/// Given two integer arrays days and apples of length n, return the 
/// maximum number of apples you can eat.
/// 
/// Example 1:
/// Input: apples = [1,2,3,5,2], days = [3,2,1,4,2]
/// Output: 7
/// Explanation: You can eat 7 apples:
/// - On the first day, you eat an apple that grew on the first day.
/// - On the second day, you eat an apple that grew on the second day.
/// - On the third day, you eat an apple that grew on the second day. 
///   After this day, the apples that grew on the third day rot.
/// - On the fourth to the seventh days, you eat apples that grew on the 
///   fourth day.
///
/// Example 2:
/// Input: apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
/// Output: 5
/// Explanation: You can eat 5 apples:
/// - On the first to the third day you eat apples that grew on the first 
///   day.
/// - Do nothing on the fouth and fifth days.
/// - On the sixth and seventh days you eat apples that grew on the sixth 
///   day.
/// 
/// Constraints:
/// 1. apples.length == n
/// 2. days.length == n
/// 3. 1 <= n <= 2 * 10^4
/// 4. 0 <= apples[i], days[i] <= 2 * 10^4
/// 5. days[i] = 0 if and only if apples[i] = 0.
/// </summary>
int LeetCodeSort::eatenApples(vector<int>& apples, vector<int>& days)
{
    priority_queue<pair<int, int>> pq;
    int day = 0;
    int result = 0;
    int n = apples.size();
    while (day < n || !pq.empty())
    {
        if (day < n && apples[day] != 0)
        {
            pq.push(make_pair(0 - (day + days[day]), apples[day]));
        }
        while (!pq.empty() && 0 - pq.top().first <= day)
        {
            pq.pop();
        }
        if (!pq.empty())
        {
            pair<int, int> pos = pq.top();
            pq.pop();
            pos.second--;
            result++;
            if (pos.second > 0) pq.push(pos);
        }
        day++;
    }
    return result;
}


/// <summary>
/// Leet code #1710. Maximum Units on a Truck
/// 
/// Easy
/// 
/// You are assigned to put some amount of boxes onto one truck. You are 
/// given a 2D array boxTypes, where boxTypes[i] = 
/// [numberOfBoxesi, numberOfUnitsPerBoxi]:
///
/// numberOfBoxesi is the number of boxes of type i.
/// numberOfUnitsPerBoxi is the number of units in each box of the type i.
/// You are also given an integer truckSize, which is the maximum number 
/// of boxes that can be put on the truck. You can choose any boxes to put 
/// on the truck as long as the number of boxes does not exceed truckSize.
///
/// Return the maximum total number of units that can be put on the truck.
///
/// Example 1:
/// Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
/// Output: 8
/// Explanation: There are:
/// - 1 box of the first type that contains 3 units.
/// - 2 boxes of the second type that contain 2 units each.
/// - 3 boxes of the third type that contain 1 unit each.
/// You can take all the boxes of the first and second types, and one 
/// box of the third type.
/// The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
///
/// Example 2:
/// Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
/// Output: 91
/// Constraints:
/// 1. 1 <= boxTypes.length <= 1000
/// 2. 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
/// 3. 1 <= truckSize <= 10^6
/// </summary>
int LeetCodeSort::maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
{
    priority_queue<pair<int, int>> pq;
    for (size_t i = 0; i < boxTypes.size(); i++)
    {
        pq.push(make_pair(boxTypes[i][1], boxTypes[i][0]));
    }
    int result = 0;
    while (!pq.empty())
    {

        result = result + pq.top().first * min(pq.top().second, truckSize);
        if (truckSize < pq.top().second)
        {
            break;
        }
        truckSize -= pq.top().second;
        pq.pop();
    }
    return result;
}

/// <summary>
/// Leet code 1752. Check if Array Is Sorted and Rotated
/// 
/// Easy
/// 
/// Given an array nums, return true if the array was originally 
/// sorted in non-decreasing order, then rotated some number of 
/// positions (including zero). Otherwise, return false.
///
/// There may be duplicates in the original array.
///
/// Note: An array A rotated by x positions results in an array B 
/// of the same length such that A[i] == B[(i+x) % A.length], 
/// where % is the modulo operation.
/// 
/// Example 1:
/// Input: nums = [3,4,5,1,2]
/// Output: true
/// Explanation: [1,2,3,4,5] is the original sorted array.
/// You can rotate the array by x = 3 positions to begin on the the 
/// element of value 3: [3,4,5,1,2].
///
/// Example 2:
/// Input: nums = [2,1,3,4]
/// Output: false
/// Explanation: There is no sorted array once rotated that can make nums.
///
/// Example 3:
/// Input: nums = [1,2,3]
/// Output: true
/// Explanation: [1,2,3] is the original sorted array.
/// You can rotate the array by x = 0 positions (i.e. no rotation) to 
/// make nums.
///
/// Example 4:
/// Input: nums = [1,1,1]
/// Output: true
/// Explanation: [1,1,1] is the original sorted array.
/// You can rotate any number of positions to make nums.
///
/// Example 5:
/// Input: nums = [2,1]
/// Output: true
/// Explanation: [1,2] is the original sorted array.
/// You can rotate the array by x = 5 positions to begin on the element 
/// of value 2: [2,1].
///
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 1 <= nums[i] <= 100
/// </summary>
bool LeetCodeSort::check(vector<int>& nums)
{
    int dip = 0;
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1]) dip++;
    }
    if (dip == 0) return true;
    if (dip > 1) return false;
    if (nums.front() < nums.back()) return false;
    return true;
 }

/// <summary>
/// Leet code 1775. Equal Sum Arrays With Minimum Number of Operations
/// 
/// Medium
/// 
/// You are given two arrays of integers nums1 and nums2, possibly of 
/// different lengths. The values in the arrays are between 1 and 6, 
/// inclusive.
///
/// In one operation, you can change any integer's value in any of the 
/// arrays to any value between 1 and 6, inclusive.
///
/// Return the minimum number of operations required to make the sum of 
/// values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if 
/// it is not possible to make the sum of the two arrays equal.
/// 
/// Example 1:
/// Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
/// Output: 3
/// Explanation: You can make the sums of nums1 and nums2 equal with 3 
/// operations. All indices are 0-indexed.
/// - Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
/// - Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
/// - Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
///
/// Example 2:
/// Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
/// Output: -1
/// Explanation: There is no way to decrease the sum of nums1 or to 
/// increase the sum of nums2 to make them equal.
///
/// Example 3:
/// Input: nums1 = [6,6], nums2 = [1]
/// Output: 3
/// Explanation: You can make the sums of nums1 and nums2 equal with 3 
/// operations. All indices are 0-indexed. 
/// - Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
/// - Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
/// - Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
///
/// Constraints:
/// 1. 1 <= nums1.length, nums2.length <= 105
/// 2. 1 <= nums1[i], nums2[i] <= 6
/// </summary>
int LeetCodeSort::minOperations(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> arr1(6), arr2(6);
    int sum1 = 0, sum2 = 0;
    for (size_t i = 0; i < nums1.size(); i++)
    {
        arr1[nums1[i] - 1]++;
        sum1 += nums1[i];
    }
    for (size_t i = 0; i < nums2.size(); i++)
    {
        arr2[nums2[i] - 1]++;
        sum2 += nums2[i];
    }
    if (sum1 > sum2)
    {
        swap(sum1, sum2);
        swap(arr1, arr2);
    }
    int delta = sum2 - sum1;
    int first = 0;
    int last = 5;
    int result = 0;
    while (delta > 0)
    {
        while (arr1[first] == 0 && first < 5) first++;
        while (arr2[last] == 0 && last >= 0) last--;
        if (first == 5 && last == 0) return -1;
        if (5 - first < last)
        {
            int count = min((delta + last - 1) / last, arr2[last]);
            arr2[last] -= count;;
            arr2[0]+=count;
            delta -= last * count;
            result+= count;
        }
        else
        {
            int count = min((delta + 5 - first - 1)/ (5- first), arr1[first]);
            arr1[first] -= count;;
            arr1[5] += count;
            delta -= (5 - first) * count;
            result += count;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1801. Number of Orders in the Backlog
/// 
/// Medium
/// 
/// You are given a 2D integer array orders, where each orders[i] = 
/// [pricei, amounti, orderTypei] denotes that amounti orders have been 
/// placed of type orderTypei at the price pricei. The orderTypei is:
///
/// 0 if it is a batch of buy orders, or
/// 1 if it is a batch of sell orders.
/// Note that orders[i] represents a batch of amounti independent orders 
/// with the same price and order type. All orders represented by 
/// orders[i] will be placed before all orders represented by orders[i+1] 
/// for all valid i.
///
/// There is a backlog that consists of orders that have not been executed. 
/// The backlog is initially empty. When an order is placed, the following 
/// happens:
///
/// If the order is a buy order, you look at the sell order with the 
/// smallest price in the backlog. If that sell order's price is smaller 
/// than or equal to the current buy order's price, they will match and be 
/// executed, and that sell order will be removed from the backlog. Else, 
/// the buy order is added to the backlog.
/// Vice versa, if the order is a sell order, you look at the buy order 
/// with the largest price in the backlog. If that buy order's price is 
/// larger than or equal to the current sell order's price, they will match 
/// and be executed, and that buy order will be removed from the backlog. 
/// Else, the sell order is added to the backlog.
/// Return the total amount of orders in the backlog after placing all the 
/// orders from the input. Since this number can be large, return it 
/// modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
/// Output: 6
/// Explanation: Here is what happens with the orders:
/// - 5 orders of type buy with price 10 are placed. There are no sell 
/// orders, so the 5 orders are added to the backlog.
/// - 2 orders of type sell with price 15 are placed. There are no buy 
/// orders with prices larger than or equal to 15, so the 2 orders are 
/// added to the backlog.
/// - 1 order of type sell with price 25 is placed. There are no buy orders 
/// with prices larger than or equal to 25 in the backlog, so this order is 
/// added to the backlog.
/// - 4 orders of type buy with price 30 are placed. The first 2 orders are 
/// matched with the 2 sell orders of the least price, which is 15 and 
/// these 2 sell orders are removed from the backlog. The 3rd order is 
/// matched with the sell order of the least price, which is 25 and this 
/// sell order is removed from the backlog. Then, there are no more sell 
/// orders in the backlog, so the 4th order is added to the backlog.
/// Finally, the backlog has 5 buy orders with price 10, and 1 buy order 
/// with price 30. So the total number of orders in the backlog is 6.
///
/// Example 2:
/// Input: orders = [[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]
/// Output: 999999984
/// Explanation: Here is what happens with the orders:
/// - 10^9 orders of type sell with price 7 are placed. There are no buy 
/// orders, so the 109 orders are added to the backlog.
/// - 3 orders of type buy with price 15 are placed. They are matched with 
/// the 3 sell orders with the least price which is 7, and those 3 sell 
/// orders are removed from the backlog.
/// - 999999995 orders of type buy with price 5 are placed. The least 
/// price of a sell order is 7, so the 999999995 orders are added to the 
/// backlog.
/// - 1 order of type sell with price 5 is placed. It is matched with the 
/// buy order of the highest price, which is 5, and that buy order is 
/// removed from the backlog.
/// Finally, the backlog has (1000000000-3) sell orders with price 7, 
/// and (999999995-1) buy orders with price 5. So the total number of 
/// orders = 1999999991, which is equal to 999999984 % (10^9 + 7).
/// 
/// Constraints:
/// 1. 1 <= orders.length <= 10^5
/// 2. orders[i].length == 3
/// 3. 1 <= pricei, amounti <= 10^9
/// 4. orderTypei is either 0 or 1.
/// </summary>
int LeetCodeSort::getNumberOfBacklogOrders(vector<vector<int>>& orders)
{
    int M = 1000000007;
    priority_queue<pair<int, int>> buy_orders;
    priority_queue<pair<int, int>> sell_orders;

    for (size_t i = 0; i < orders.size(); i++)
    {
        if (orders[i][2] == 0)
        {
            while (!sell_orders.empty())
            {
                pair<int, int> sell = sell_orders.top();
                if (orders[i][0] + sell.first >= 0)
                {
                    sell_orders.pop();
                    if (orders[i][1] >= sell.second)
                    {
                        orders[i][1] -= sell.second;
                    }
                    else
                    {
                        sell.second -= orders[i][1];
                        sell_orders.push(sell);
                        orders[i][1] = 0;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (orders[i][1] > 0)
            {
                buy_orders.push(make_pair(orders[i][0], orders[i][1]));
            }
        }
        else
        {
            while (!buy_orders.empty())
            {
                pair<int, int> buy = buy_orders.top();
                if (buy.first >= orders[i][0])
                {
                    buy_orders.pop();
                    if (orders[i][1] >= buy.second)
                    {
                        orders[i][1] -= buy.second;
                    }
                    else
                    {
                        buy.second -= orders[i][1];
                        buy_orders.push(buy);
                        orders[i][1] = 0;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (orders[i][1] > 0)
            {
                sell_orders.push(make_pair(-orders[i][0], orders[i][1]));
            }
        }
    }
    int result = 0;
    while (!buy_orders.empty())
    {
        result = (result + buy_orders.top().second) % M;
        buy_orders.pop();
    }
    while (!sell_orders.empty())
    {
        result = (result + sell_orders.top().second) % M;
        sell_orders.pop();
    }
    return result;
}

/// <summary>
/// Leet code 1833. Maximum Ice Cream Bars
/// 
/// Medium
/// 
/// It is a sweltering summer day, and a boy wants to buy some ice cream 
/// bars.
///
/// At the store, there are n ice cream bars. You are given an array costs 
/// of length n, where costs[i] is the price of the ith ice cream bar in 
/// coins. The boy initially has coins coins to spend, and he wants to buy 
/// as many ice cream bars as possible. 
///
/// Return the maximum number of ice cream bars the boy can buy with coins. 
/// 
/// Note: The boy can buy the ice cream bars in any order.
/// 
/// Example 1:
/// Input: costs = [1,3,2,4,1], coins = 7
/// Output: 4
/// Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a 
/// total price of 1 + 3 + 2 + 1 = 7.
///
/// Example 2:
/// Input: costs = [10,6,8,7,7,8], coins = 5
/// Output: 0
/// Explanation: The boy cannot afford any of the ice cream bars.
///
/// Example 3:
/// Input: costs = [1,6,3,1,2,5], coins = 20
/// Output: 6
/// Explanation: The boy can buy all the ice cream bars for a total price 
/// of 1 + 6 + 3 + 1 + 2 + 5 = 18.
/// 
/// Constraints:
/// 1. costs.length == n
/// 2. 1 <= n <= 10^5
/// 3. 1 <= costs[i] <= 10^5
/// 4. 1 <= coins <= 10^8
/// </summary>
int LeetCodeSort::maxIceCream(vector<int>& costs, int coins)
{
    priority_queue<int> pq;
    for (size_t i = 0; i < costs.size(); i++)
    {
        pq.push(0 - costs[i]);
    }
    int result = 0;
    while (!pq.empty() && coins > 0)
    {
        coins += pq.top();
        pq.pop();
        if (coins >= 0) result++;
    }
    return result;
}


/// <summary>
/// Leet code 1834. Single-Threaded CPU
/// 
/// Medium
/// 
/// You are given n tasks labeled from 0 to n - 1 represented by a 2D 
/// integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] 
/// means that the ith task will be available to process at enqueueTimei 
/// and will take processingTimei to finish processing.
///
/// You have a single-threaded CPU that can process at most one task at 
/// a time and will act in the following way:
///
/// If the CPU is idle and there are no available tasks to process, the 
/// CPU remains idle.
/// If the CPU is idle and there are available tasks, the CPU will choose 
/// the one with the shortest processing time. If multiple tasks have the 
/// same shortest processing time, it will choose the task with the 
/// smallest index.
/// Once a task is started, the CPU will process the entire task without 
/// stopping.
/// The CPU can finish a task then start a new one instantly.
/// Return the order in which the CPU will process the tasks.
/// 
/// Example 1:
/// Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
/// Output: [0,2,3,1]
/// Explanation: The events go as follows: 
/// - At time = 1, task 0 is available to process. Available tasks = {0}.
/// - Also at time = 1, the idle CPU starts processing task 0. 
///   Available tasks = {}.
/// - At time = 2, task 1 is available to process. Available tasks = {1}.
/// - At time = 3, task 2 is available to process. Available 
///   tasks = {1, 2}.
/// - Also at time = 3, the CPU finishes task 0 and starts processing 
///   task 2 as it is the shortest. Available tasks = {1}.
/// - At time = 4, task 3 is available to process. Available 
///   tasks = {1, 3}.
/// - At time = 5, the CPU finishes task 2 and starts processing task 3 
///   as it is the shortest. Available tasks = {1}.
/// - At time = 6, the CPU finishes task 3 and starts processing task 1. 
///   Available tasks = {}.
/// - At time = 10, the CPU finishes task 1 and becomes idle.
///  
/// Example 2:
/// 
/// Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
/// Output: [4,3,2,0,1]
/// Explanation: The events go as follows:
/// - At time = 7, all the tasks become available. Available 
///   tasks = {0,1,2,3,4}.
/// - Also at time = 7, the idle CPU starts processing task 4. 
///   Available tasks = {0,1,2,3}.
/// - At time = 9, the CPU finishes task 4 and starts processing task 3. 
///   Available tasks = {0,1,2}.
/// - At time = 13, the CPU finishes task 3 and starts processing task 2. 
///   Available tasks = {0,1}.
/// - At time = 18, the CPU finishes task 2 and starts processing task 0. 
///   Available tasks = {1}.
/// - At time = 28, the CPU finishes task 0 and starts processing task 1. 
///   Available tasks = {}.
/// - At time = 40, the CPU finishes task 1 and becomes idle.
/// 
/// Constraints:
/// 1. tasks.length == n
/// 2. 1 <= n <= 10^5
/// 3. 1 <= enqueueTimei, processingTimei <= 10^9
/// </summary>
vector<int> LeetCodeSort::getOrder(vector<vector<int>>& tasks)
{
    priority_queue<pair<int, int>> task_queue;
    priority_queue<vector<int>> process_queue;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        task_queue.push(make_pair(0-tasks[i][0], i));
    }

    int time = 0;
    vector<int> result;
    while (!task_queue.empty())
    {
        if (process_queue.empty() && time + task_queue.top().first < 0)
        {
            time = 0 - task_queue.top().first;
        }
        if (time + task_queue.top().first >= 0)
        {
            pair<int, int> schedule = task_queue.top();
            task_queue.pop();
            vector<int> task(3);
            task[0] = 0 - tasks[schedule.second][1];
            task[1] = 0 - schedule.second;
            task[2] = schedule.second;
            process_queue.push(task);
        }
        else
        {
            vector<int> task = process_queue.top();
            process_queue.pop();
            result.push_back(task[2]);
            time += tasks[task[2]][1];
        }
    }
    while (!process_queue.empty())
    {
        vector<int> task = process_queue.top();
        process_queue.pop();
        result.push_back(task[2]);
    }
    return result;
}


/// <summary>
/// Leet code 1846. Maximum Element After Decreasing and Rearranging
/// 
/// Medium
/// 
/// You are given an array of positive integers arr. Perform some 
/// operations (possibly none) on arr so that it satisfies these 
/// conditions:
///
/// The value of the first element in arr must be 1.
/// The absolute difference between any 2 adjacent elements must be less 
/// than or equal to 1. In other words, abs(arr[i] - arr[i - 1]) <= 1 
/// for each i where 1 <= i < arr.length (0-indexed). abs(x) is the 
/// absolute value of x.
/// There are 2 types of operations that you can perform any number of 
/// times:
///
/// Decrease the value of any element of arr to a smaller positive integer.
/// Rearrange the elements of arr to be in any order.
/// Return the maximum possible value of an element in arr after 
/// performing the operations to satisfy the conditions.
/// 
/// Example 1:
/// Input: arr = [2,2,1,2,1]
/// Output: 2
/// Explanation: 
/// We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
/// The largest element in arr is 2.
///
/// Example 2:
/// Input: arr = [100,1,1000]
/// Output: 3
/// Explanation: 
/// One possible way to satisfy the conditions is by doing the following:
/// 1. Rearrange arr so it becomes [1,100,1000].
/// 2. Decrease the value of the second element to 2.
/// 3. Decrease the value of the third element to 3.
/// Now arr = [1,2,3], which satisfies the conditions.
/// The largest element in arr is 3.
///
/// Example 3:
/// Input: arr = [1,2,3,4,5]
/// Output: 5
/// Explanation: The array already satisfies the conditions, and the largest 
/// element is 5.
///
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 1 <= arr[i] <= 10^9
/// </summary>
int LeetCodeSort::maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    int last = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] > last) last++;
    }
    return last;
}


/// <summary>
/// Leet code 1847. Closest Room
/// 
/// Hard
/// 
/// There is a hotel with n rooms. The rooms are represented by a 2D 
/// integer array rooms where rooms[i] = [roomIdi, sizei] denotes that 
/// there is a room with room number roomIdi and size equal to sizei. 
/// Each roomIdi is guaranteed to be unique.
///
/// You are also given k queries in a 2D array queries where 
/// queries[j] = [preferredj, minSizej]. The answer to the jth query 
/// is the room number id of a room such that:
///
/// The room has a size of at least minSizej, and
/// abs(id - preferredj) is minimized, where abs(x) is the absolute 
/// value of x.
/// If there is a tie in the absolute difference, then use the room 
/// with the smallest such id. If there is no such room, the answer 
/// is -1.
/// Return an array answer of length k where answer[j] contains the 
/// answer to the jth query.
///
/// Example 1:
/// Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
/// Output: [3,-1,3]
/// Explanation: The answers to the queries are as follows:
/// Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, 
/// and its size of 2 is at least 1. The answer is 3.
/// Query = [3,3]: There are no rooms with a size of at least 3, so 
/// the answer is -1.
/// Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, 
/// and its size of 2 is at least 2. The answer is 3.
///
/// Example 2:
/// Input: rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], 
/// queries = [[2,3],[2,4],[2,5]]
/// Output: [2,1,3]
/// Explanation: The answers to the queries are as follows:
/// Query = [2,3]: Room number 2 is the closest as abs(2 - 2) = 0, 
/// and its size of 3 is at least 3. The answer is 2.
/// Query = [2,4]: Room numbers 1 and 3 both have sizes of at least 4. 
/// The answer is 1 since it is smaller.
/// Query = [2,5]: Room number 3 is the only room with a size of at 
/// least 5. The answer is 3.
/// 
/// Constraints:
/// 1. n == rooms.length
/// 2. 1 <= n <= 10^5
/// 3. k == queries.length
/// 4. 1 <= k <= 10^4
/// 5. 1 <= roomIdi, preferredj <= 10^7
/// 6. 1 <= sizei, minSizej <= 10^7
/// </summary>
vector<int> LeetCodeSort::closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries)
{
    priority_queue<pair<int, int>> rooms_sorted, query_sorted;
    for (size_t i = 0; i < rooms.size(); i++)
    {
        rooms_sorted.push(make_pair(rooms[i][1], rooms[i][0]));
    }
    for (size_t i = 0; i < queries.size(); i++)
    {
        query_sorted.push(make_pair(queries[i][1], i));
    }
    vector<int> result(queries.size());
    set<int> room_ids;
    while (!query_sorted.empty())
    {
        pair<int, int> query = query_sorted.top();
        query_sorted.pop();

        while (!rooms_sorted.empty())
        {
            if (rooms_sorted.top().first < query.first) break;
            pair<int, int> room = rooms_sorted.top();
            rooms_sorted.pop();
            room_ids.insert(room.second);
        }
        result[query.second] = -1;
        if (!room_ids.empty())
        {
            int diff = INT_MAX;
            int preferred_room = queries[query.second][0];
            auto itr = room_ids.lower_bound(preferred_room);
            if (itr != room_ids.end())
            {
                diff = *itr - preferred_room;
                result[query.second] = *itr;
            }
            if (itr != room_ids.begin())
            {
                itr = std::prev(itr);
                if (preferred_room - *itr <= diff)
                {
                    result[query.second] = *itr;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code 1851. Minimum Interval to Include Each Query
/// 
/// Hard
/// 
/// You are given a 2D integer array intervals, where intervals[i] = 
/// [lefti, righti] describes the ith interval starting at lefti and 
/// ending at righti (inclusive). The size of an interval is defined 
/// as the number of integers it contains, or more formally 
/// righti - lefti + 1.
///
/// You are also given an integer array queries. The answer to the 
/// jth query is the size of the smallest interval i such that 
/// lefti <= queries[j] <= righti. If no such interval exists, the 
/// answer is -1.
///
/// Return an array containing the answers to the queries.
/// Example 1:
/// Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
/// Output: [3,3,1,4]
/// Explanation: The queries are processed as follows:
/// - Query = 2: The interval [2,4] is the smallest interval containing 2. 
///   The answer is 4 - 2 + 1 = 3.
/// - Query = 3: The interval [2,4] is the smallest interval containing 3. 
///   The answer is 4 - 2 + 1 = 3.
/// - Query = 4: The interval [4,4] is the smallest interval containing 4. 
///   The answer is 4 - 4 + 1 = 1.
/// - Query = 5: The interval [3,6] is the smallest interval containing 5. 
/// The answer is 6 - 3 + 1 = 4.
///
/// Example 2:
/// Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
/// Output: [2,-1,4,6]
/// Explanation: The queries are processed as follows:
/// - Query = 2: The interval [2,3] is the smallest interval containing 2. 
///   The answer is 3 - 2 + 1 = 2.
/// - Query = 19: None of the intervals contain 19. The answer is -1.
/// - Query = 5: The interval [2,5] is the smallest interval containing 5. 
///   The answer is 5 - 2 + 1 = 4.
/// - Query = 22: The interval [20,25] is the smallest interval 
///   containing 22. The answer is 25 - 20 + 1 = 6.
/// 
/// Constraints:
/// 1. 1 <= intervals.length <= 10^5
/// 2. 1 <= queries.length <= 10^5
/// 3. queries[i].length == 2
/// 4. 1 <= lefti <= righti <= 10^7
/// 5. 1 <= queries[j] <= 10^7
/// </summary>
vector<int> LeetCodeSort::minInterval(vector<vector<int>>& intervals, vector<int>& queries)
{
    sort(intervals.begin(), intervals.end());
    priority_queue<pair<int, int>> query_pq;
    priority_queue<pair<int, int>> candidates;
    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        query_pq.push(make_pair(-queries[i], i));
    }

    size_t index = 0;
    while (!query_pq.empty())
    {
        pair<int, int> query = query_pq.top();
        query_pq.pop();
        int pos = 0 - query.first;
        while (index < intervals.size())
        {
            if (intervals[index][0] > pos) break;
            if (intervals[index][1] >= pos)
            {
                candidates.push(make_pair(intervals[index][0] - intervals[index][1] - 1, index));
            }
            index++;
        }
        while (!candidates.empty())
        {
            if (intervals[candidates.top().second][1] >= pos)
            {
                break;
            }
            candidates.pop();
        }
        if (candidates.empty())
        {
            result[query.second] = -1;
        }
        else
        {
            result[query.second] = 0 - candidates.top().first;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1889. Minimum Space Wasted From Packaging
/// 
/// Hard
/// 
/// You have n packages that you are trying to place in boxes, one package 
/// in each box. There are m suppliers that each produce boxes of different 
/// sizes (with infinite supply). A package can be placed in a box if the 
/// size of the package is less than or equal to the size of the box.
///
/// The package sizes are given as an integer array packages, where 
/// packages[i] is the size of the ith package. The suppliers are given as 
/// a 2D integer array boxes, where boxes[j] is an array of box sizes that 
/// the jth supplier produces.
///
/// You want to choose a single supplier and use boxes from them such that 
/// the total wasted space is minimized. For each package in a box, we 
/// define the space wasted to be size of the box - size of the package. 
/// The total wasted space is the sum of the space wasted in all the boxes.
///
/// For example, if you have to fit packages with sizes [2,3,5] and the 
/// supplier offers boxes of sizes [4,8], you can fit the packages of 
/// size-2 and size-3 into two boxes of size-4 and the package with size-5 
/// into a box of size-8. This would result in a waste of (4-2) + (4-3) + 
/// (8-5) = 6.
/// Return the minimum total wasted space by choosing the box supplier 
/// optimally, or -1 if it is impossible to fit all the packages inside 
/// boxes. Since the answer may be large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: packages = [2,3,5], boxes = [[4,8],[2,8]]
/// Output: 6
/// Explanation: It is optimal to choose the first supplier, using two 
/// size-4 boxes and one size-8 box.
/// The total waste is (4-2) + (4-3) + (8-5) = 6.
///
/// Example 2:
/// Input: packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
/// Output: -1
/// Explanation: There is no box that the package of size 5 can fit in.
///
/// Example 3:
/// Input: packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
/// Output: 9
/// Explanation: It is optimal to choose the third supplier, using two 
/// size-5 boxes, two size-10 boxes, and two size-14 boxes.
/// The total waste is (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9.
/// 
/// Constraints:
/// 1. n == packages.length
/// 2. m == boxes.length
/// 3. 1 <= n <= 10^5
/// 4. 1 <= m <= 10^5
/// 5. 1 <= packages[i] <= 10^5
/// 6. 1 <= boxes[j].length <= 10^5
/// 7. 1 <= boxes[j][k] <= 10^5
/// 8. sum(boxes[j].length) <= 10^5
/// 9. The elements in boxes[j] are distinct.
/// </summary>
int LeetCodeSort::minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes)
{
    long long M = 1000000007;
    int n = packages.size();
    long long result = LONG_MAX;
    long long package_sum = 0;
    sort(packages.begin(), packages.end());
    for (int i = 0; i < n; i++)
    {
        package_sum += (long long)packages[i];
    }
    for (size_t i = 0; i < boxes.size(); i++)
    {
        sort(boxes[i].begin(), boxes[i].end());
        if (boxes[i][boxes[i].size() - 1] < packages[n - 1]) continue;
        int prev_index = -1;
        long long box_sum = 0;
        for (size_t j = 0; j < boxes[i].size(); j++)
        {
            int index = upper_bound(packages.begin(), packages.end(), boxes[i][j]) - packages.begin() - 1;
            if (index < 0 || index == prev_index) continue;
            box_sum = box_sum + (long long)boxes[i][j] * ((long long)index - (long long)prev_index);
            prev_index = index;
        }
        result = min(result, (box_sum - package_sum));
    }
    if (result == LONG_MAX) return -1;
    else return (int)(result % M);
}

/// <summary>
/// Leet code 1909. Remove One Element to Make the Array Strictly 
///                 Increasing
/// 
/// Easy
/// 
/// Given a 0-indexed integer array nums, return true if it can be made 
/// strictly increasing after removing exactly one element, or false 
/// otherwise. If the array is already strictly increasing, return true.
///
/// The array nums is strictly increasing if nums[i - 1] < nums[i] for 
/// each index (1 <= i < nums.length).
///
/// Example 1:
/// Input: nums = [1,2,10,5,7]
/// Output: true
/// Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
/// [1,2,5,7] is strictly increasing, so return true.
///
/// Example 2:
/// Input: nums = [2,3,1,2]
/// Output: false
/// Explanation:
/// [3,1,2] is the result of removing the element at index 0.
/// [2,1,2] is the result of removing the element at index 1.
/// [2,3,2] is the result of removing the element at index 2.
/// [2,3,1] is the result of removing the element at index 3.
/// No resulting array is strictly increasing, so return false.
///
/// Example 3:
/// Input: nums = [1,1,1]
/// Output: false
/// Explanation: The result of removing any element is [1,1].
/// [1,1] is not strictly increasing, so return false.
///
/// Example 4:
/// Input: nums = [1,2,3]
/// Output: true
/// Explanation: [1,2,3] is already strictly increasing, so 
/// return true.
/// 
/// Constraints:
/// 1. 2 <= nums.length <= 1000
/// 2. 1 <= nums[i] <= 1000
/// </summary>
bool LeetCodeSort::canBeIncreasing(vector<int>& nums)
{
    bool b_descrease = false;
    int prev = 0;
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] <= nums[prev])
        {
            if (b_descrease) return false;
            b_descrease = true;
            if (prev == 0 || nums[i] > nums[prev - 1]) prev = i;
        }
        else
        {
            prev = i;
        }
    }
    return true;
}

/// <summary>
/// Leet code 1913. Maximum Product Difference Between Two Pairs
/// 
/// Easy
/// 
/// The product difference between two pairs (a, b) and (c, d) is defined 
/// as (a * b) - (c * d).
///
/// For example, the product difference between (5, 6) and (2, 7) is 
/// (5 * 6) - (2 * 7) = 16.
/// Given an integer array nums, choose four distinct indices w, x, y, 
/// and z such that the product difference between pairs (nums[w], 
/// nums[x]) and (nums[y], nums[z]) is maximized.
///
/// Return the maximum such product difference.
///
/// Example 1:
/// Input: nums = [5,6,2,7,4]
/// Output: 34
/// Explanation: We can choose indices 1 and 3 for the first pair 
/// (6, 7) and indices 2 and 4 for the second pair (2, 4).
/// The product difference is (6 * 7) - (2 * 4) = 34.
///
/// Example 2:
/// Input: nums = [4,2,5,9,7,4,8]
/// Output: 64
/// Explanation: We can choose indices 3 and 6 for the first pair (9, 8) 
/// and indices 1 and 5 for the second pair (2, 4).
/// The product difference is (9 * 8) - (2 * 4) = 64.
///
/// Constraints:
/// 1. 4 <= nums.length <= 10^4
/// 2. 1 <= nums[i] <= 10^4
/// </summary>
int LeetCodeSort::maxProductDifference(vector<int>& nums)
{
    priority_queue<int> min_queue, max_queue;
    for (size_t i = 0; i < nums.size(); i++)
    {
        min_queue.push(nums[i]);
        if (min_queue.size() > 2)
        {
            int x = min_queue.top();
            min_queue.pop();
            max_queue.push(-x);
            if (max_queue.size() > 2) max_queue.pop();
        }
    }
    int x = min_queue.top();
    min_queue.pop();
    int w = min_queue.top();
    min_queue.pop();

    int y = 0 - max_queue.top();
    max_queue.pop();
    int z = 0 - max_queue.top();
    max_queue.pop();

    return (y * z - x * w);
}

/// <summary>
/// Leet code 1877. Minimize Maximum Pair Sum in Array
///                  
/// Medium
/// 
/// The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum 
/// is the largest pair sum in a list of pairs.
///
/// For example, if we have pairs (1,5), (2,3), and (4,4), the maximum 
/// pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
/// Given an array nums of even length n, pair up the elements of nums 
/// into n / 2 pairs such that:
///
/// Each element of nums is in exactly one pair, and
/// The maximum pair sum is minimized.
/// Return the minimized maximum pair sum after optimally pairing up the 
/// elements.
/// 
/// Example 1:
/// Input: nums = [3,5,2,3]
/// Output: 7
/// Explanation: The elements can be paired up into pairs (3,3) and (5,2).
/// The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
///
/// Example 2:
/// Input: nums = [3,5,4,2,4,6]
/// Output: 8
/// Explanation: The elements can be paired up into pairs (3,5), (4,4), 
/// and (6,2).
/// The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
/// 
/// Constraints:
///
/// 1. n == nums.length
/// 2. 2 <= n <= 10^5
/// 3. n is even.
/// 4. 1 <= nums[i] <= 10^5
/// </summary>
int LeetCodeSort::minPairSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int result = 0;
    for (size_t i = 0; i < nums.size() / 2; i++)
    {
        result = max(result, nums[i] + nums[nums.size() - 1 - i]);
    }
    return result;
}

/// <summary>
/// Leet code 1881. Maximum Value after Insertion
///                  
/// Medium
/// 
/// You are given a very large integer n, represented as a string, and an 
/// integer digit x. The digits in n and the digit x are in the 
/// inclusive range [1, 9], and n may represent a negative number.
///
/// You want to maximize n's numerical value by inserting x anywhere in 
/// the decimal representation of n. You cannot insert x to the left of 
/// the negative sign.
///
/// For example, if n = 73 and x = 6, it would be best to insert it 
/// between 7 and 3, making n = 763.
/// If n = -55 and x = 2, it would be best to insert it before the 
/// first 5, making n = -255.
/// Return a string representing the maximum value of n after the 
/// insertion.
/// 
/// Example 1:
/// Input: n = "99", x = 9
/// Output: "999"
/// Explanation: The result is the same regardless of where you insert 9.
///
/// Example 2:
/// Input: n = "-13", x = 2
/// Output: "-123"
/// Explanation: You can make n one of {-213, -123, -132}, and the 
/// largest of those three is -123.
///
/// Constraints:
/// 1. 1 <= n.length <= 105
/// 2. 1 <= x <= 9
/// 3. The digits in n are in the range [1, 9].
/// 4. n is a valid representation of an integer.
/// 5. In the case of a negative n, it will begin with '-'.
/// </summary>
string LeetCodeSort::maxValue(string n, int x)
{
    int sign = 1;
    if (n[0] == '-') sign = -1;
    string result;
    for (size_t i = 0; i <= n.size(); i++)
    {
        if (i == n.size())
        {
            result.push_back('0' + x);
            break;
        }
        if (n[i] == '-') result.push_back(n[i]);
        else
        {
            if (sign == 1 && n[i] >= '0' + x)
            {
                result.push_back(n[i]);
            }
            else if (sign == -1 && n[i] <= '0' + x)
            {
                result.push_back(n[i]);
            }
            else
            {
                result.push_back('0' + x);
                result.append(n.substr(i));
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code 1887. Reduction Operations to Make the Array Elements Equal 
///                                  
/// Medium
/// 
/// Given an integer array nums, your goal is to make all elements in nums 
/// equal. To complete one operation, follow these steps:
///
/// Find the largest value in nums. Let its index be i (0-indexed) and its 
/// value be largest. If there are multiple elements with the largest 
/// value, pick the smallest i.
/// Find the next largest value in nums strictly smaller than largest. Let 
/// its value be nextLargest.
/// Reduce nums[i] to nextLargest.
/// Return the number of operations to make all elements in nums equal.
///
/// Example 1:
/// Input: nums = [5,1,3]
/// Output: 3
/// Explanation: It takes 3 operations to make all elements in nums equal:
/// 1. largest = 5 at index 0. nextLargest = 3. Reduce nums[0] to 3. 
///    nums = [3,1,3].
/// 2. largest = 3 at index 0. nextLargest = 1. Reduce nums[0] to 1. 
///    nums = [1,1,3].
/// 3. largest = 3 at index 2. nextLargest = 1. Reduce nums[2] to 1. 
///    nums = [1,1,1].
///
/// Example 2:
/// Input: nums = [1,1,1]
/// Output: 0
/// Explanation: All elements in nums are already equal.
///
/// Example 3:
/// Input: nums = [1,1,2,2,3]
/// Output: 4
/// Explanation: It takes 4 operations to make all elements in nums equal:
/// 1. largest = 3 at index 4. nextLargest = 2. Reduce nums[4] to 2. 
///    nums = [1,1,2,2,2].
/// 2. largest = 2 at index 2. nextLargest = 1. Reduce nums[2] to 1. 
///    nums = [1,1,1,2,2].
/// 3. largest = 2 at index 3. nextLargest = 1. Reduce nums[3] to 1. 
///    nums = [1,1,1,1,2].
/// 4. largest = 2 at index 4. nextLargest = 1. Reduce nums[4] to 1. 
///    nums = [1,1,1,1,1].
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 5 * 10^4
/// 2. 1 <= nums[i] <= 5 * 10^4
/// </summary>
int LeetCodeSort::reductionOperations(vector<int>& nums)
{
    map<int, int> sorted_nums;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sorted_nums[nums[i]]++;
    }
    int result = 0;
    while (sorted_nums.size() > 1)
    {
        int count = sorted_nums.rbegin()->second;
        sorted_nums.erase(sorted_nums.rbegin()->first);
        sorted_nums[sorted_nums.rbegin()->first] += count;
        result += count;
    }
    return result;
}

/// <summary>
/// Leet code 1882. Process Tasks Using Servers
///                                  
/// Medium
/// 
/// You are given two 0-indexed integer arrays servers and tasks of lengths 
/// n and m respectively. servers[i] is the weight of the ith server, and 
/// tasks[j] is the time needed to process the jth task in seconds.
///
/// Tasks are assigned to the servers using a task queue. Initially, all 
/// servers are free, and the queue is empty.
///
/// At second j, the jth task is inserted into the queue (starting with 
/// the 0th task being inserted at second 0). As long as there are free 
/// servers and the queue is not empty, the task in the front of the queue 
/// will be assigned to a free server with the smallest weight, and in 
/// case of a tie, it is assigned to a free server with the smallest index.
///
/// If there are no free servers and the queue is not empty, we wait until 
/// a server becomes free and immediately assign the next task. If multiple
/// servers become free at the same time, then multiple tasks from the 
/// queue will be assigned in order of insertion following the weight and 
/// index priorities above.
///
/// A server that is assigned task j at second t will be free again at 
/// second t + tasks[j].
///
/// Build an array ans of length m, where ans[j] is the index of the 
/// server the jth task will be assigned to.
///
/// Return the array ans.
/// 
/// Example 1:
/// Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
/// Output: [2,2,0,2,1,2]
/// Explanation: Events in chronological order go as follows:
/// - At second 0, task 0 is added and processed using server 2 until 
///   second 1.
/// - At second 1, server 2 becomes free. Task 1 is added and 
///   processed using server 2 until second 3.
/// - At second 2, task 2 is added and processed using server 0 until 
///   second 5.
/// - At second 3, server 2 becomes free. Task 3 is added and processed 
///   using server 2 until second 5.
/// - At second 4, task 4 is added and processed using server 1 until 
///   second 5.
/// - At second 5, all servers become free. Task 5 is added and processed 
///   using server 2 until second 7.
///
/// Example 2:
/// Input: servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
/// Output: [1,4,1,4,1,3,2]
/// Explanation: Events in chronological order go as follows: 
/// - At second 0, task 0 is added and processed using server 1 until 
///   second 2.
/// - At second 1, task 1 is added and processed using server 4 until 
///   second 2.
/// - At second 2, servers 1 and 4 become free. Task 2 is added and 
///   processed using server 1 until second 4. 
/// - At second 3, task 3 is added and processed using server 4 until 
///   second 7.
/// - At second 4, server 1 becomes free. Task 4 is added and processed 
///   using server 1 until second 9. 
/// - At second 5, task 5 is added and processed using server 3 until 
///   second 7.
/// - At second 6, task 6 is added and processed using server 2 until 
///   second 7.
///
///  Constraints:
/// 1. servers.length == n
/// 2. tasks.length == m
/// 3. 1 <= n, m <= 2 * 10^5
/// 4. 1 <= servers[i], tasks[j] <= 2 * 10^5
/// </summary>
vector<int> LeetCodeSort::assignTasks(vector<int>& servers, vector<int>& tasks)
{
    set<pair<int, int>> free_servers;
    set<pair<int, int>> busy_servers;
    for (size_t i = 0; i < servers.size(); i++)
    {
        free_servers.insert(make_pair(servers[i], i));
    }

    vector<int> result;
    int time = 0;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if (time <= (int)i) time = i;
        int server_id = -1;
        if (free_servers.empty())
        {
            time = busy_servers.begin()->first;
        }
        while (!busy_servers.empty() && busy_servers.begin()->first <= time)
        {
            server_id = busy_servers.begin()->second;
            free_servers.insert(make_pair(servers[server_id], server_id));
            busy_servers.erase(busy_servers.begin());
        }
        server_id = free_servers.begin()->second;
        result.push_back(server_id);
        free_servers.erase(free_servers.begin());
        busy_servers.insert(make_pair(time + tasks[i], server_id));
    }
    return result;
}

/// <summary>
/// Leet code 1964. Find the Longest Valid Obstacle Course at Each Position
///                                                
/// Hard
/// 
/// You want to build some obstacle courses. You are given a 0-indexed 
/// integer array obstacles of length n, where obstacles[i] describes 
/// the height of the ith obstacle.
/// 
/// For every index i between 0 and n - 1 (inclusive), find the length 
/// of the longest obstacle course in obstacles such that:
/// 
/// You choose any number of obstacles between 0 and i inclusive.
/// You must include the ith obstacle in the course.
/// You must put the chosen obstacles in the same order as they appear in 
/// obstacles.
/// Every obstacle (except the first) is taller than or the same height as 
/// the obstacle immediately before it.
/// Return an array ans of length n, where ans[i] is the length of the 
/// longest obstacle course for index i as described above.
///
/// Example 1:
/// Input: obstacles = [1,2,3,2]
/// Output: [1,2,3,3]
/// Explanation: The longest valid obstacle course at each position is:
/// - i = 0: [1], [1] has length 1.
/// - i = 1: [1,2], [1,2] has length 2.
/// - i = 2: [1,2,3], [1,2,3] has length 3.
/// - i = 3: [1,2,3,2], [1,2,2] has length 3.
///
/// Example 2:
/// Input: obstacles = [2,2,1]
/// Output: [1,2,1]
/// Explanation: The longest valid obstacle course at each position is:
/// - i = 0: [2], [2] has length 1.
/// - i = 1: [2,2], [2,2] has length 2.
/// - i = 2: [2,2,1], [1] has length 1.
///
/// Example 3:
/// Input: obstacles = [3,1,5,6,4,2]
/// Output: [1,1,2,3,2,2]
/// Explanation: The longest valid obstacle course at each position is:
/// - i = 0: [3], [3] has length 1.
/// - i = 1: [3,1], [1] has length 1.
/// - i = 2: [3,1,5], [3,5] has length 2. [1,5] is also valid.
/// - i = 3: [3,1,5,6], [3,5,6] has length 3. [1,5,6] is also valid.
/// - i = 4: [3,1,5,6,4], [3,4] has length 2. [1,4] is also valid.
/// - i = 5: [3,1,5,6,4,2], [1,2] has length 2.
/// 
/// Constraints:
/// 1. n == obstacles.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= obstacles[i] <= 10^7
/// </summary>
vector<int> LeetCodeSort::longestObstacleCourseAtEachPosition(vector<int>& obstacles)
{
    vector<int> result(obstacles.size());
    vector<int> dp;
    for (size_t i = 0; i < obstacles.size(); i++)
    {
        auto itr = upper_bound(dp.begin(), dp.end(), obstacles[i]);
        if (itr == dp.end())
        {
            dp.push_back(obstacles[i]);
            result[i] = dp.size();
        }
        else
        {
            *itr = obstacles[i];
            result[i] = itr - dp.begin() + 1;
        }
    }
    return result;
}

/// <summary>
/// Leet code 2037. Minimum Number of Moves to Seat Everyone
///                                                
/// Easy
/// 
/// There are n seats and n students in a room. You are given an array 
/// seats of length n, where seats[i] is the position of the ith seat. 
/// You are also given the array students of length n, where students[j] 
/// is the position of the jth student.
///
/// You may perform the following move any number of times:
///
/// Increase or decrease the position of the ith student by 1 (i.e., 
/// moving the ith student from position x to x + 1 or x - 1)
/// Return the minimum number of moves required to move each student to 
/// a seat such that no two students are in the same seat.
///
/// Note that there may be multiple seats or students in the same 
/// position at the beginning.
/// 
/// Example 1:
/// Input: seats = [3,1,5], students = [2,7,4]
/// Output: 4
/// Explanation: The students are moved as follows:
/// - The first student is moved from from position 2 to position 1 
///   using 1 move.
/// - The second student is moved from from position 7 to position 5 
///   using 2 moves.
/// - The third student is moved from from position 4 to position 3 
///   using 1 move.
/// In total, 1 + 2 + 1 = 4 moves were used.
///
/// Example 2:
/// Input: seats = [4,1,5,9], students = [1,3,2,6]
/// Output: 7
/// Explanation: The students are moved as follows:
/// - The first student is not moved.
/// - The second student is moved from from position 3 to position 4 
///   using 1 move.
/// - The third student is moved from from position 2 to position 5 
///   using 3 moves.
/// - The fourth student is moved from from position 6 to position 9 
///   using 3 moves.
/// In total, 0 + 1 + 3 + 3 = 7 moves were used.
///
/// Example 3:
/// Input: seats = [2,2,6,6], students = [1,3,2,6]
/// Output: 4
/// Explanation: Note that there are two seats at position 2 and two 
/// seats at position 6.
/// The students are moved as follows:
/// - The first student is moved from from position 1 to position 2 
///   using 1 move.
/// - The second student is moved from from position 3 to position 6 
///   using 3 moves.
/// - The third student is not moved.
/// - The fourth student is not moved.
/// In total, 1 + 3 + 0 + 0 = 4 moves were used.
/// 
/// Constraints:
/// 1. n == seats.length == students.length
/// 2. 1 <= n <= 100
/// 3. 1 <= seats[i], students[j] <= 100
/// </summary>
int LeetCodeSort::minMovesToSeat(vector<int>& seats, vector<int>& students)
{
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int result = 0;
    for (size_t i = 0; i < seats.size(); i++)
    {
        result = result + abs(seats[i] - students[i]);
    }
    return result;
}

/// <summary>
/// Leet code 1984. Minimum Difference Between Highest and Lowest of K 
///                 Scores
///                                                
/// Easy
/// 
/// You are given a 0-indexed integer array nums, where nums[i] 
/// represents the score of the ith student. You are also given an 
/// integer k.
///
/// Pick the scores of any k students from the array so that the 
/// difference between the highest and the lowest of the k scores is 
/// minimized.
/// 
/// Return the minimum possible difference.
/// 
/// Example 1:
/// Input: nums = [90], k = 1
/// Output: 0
/// Explanation: There is one way to pick score(s) of one student:
/// - [90]. The difference between the highest and lowest score 
///   is 90 - 90 = 0.
/// The minimum possible difference is 0.
///
/// Example 2:
/// Input: nums = [9,4,1,7], k = 2
/// Output: 2
/// Explanation: There are six ways to pick score(s) of two students:
/// - [9,4,1,7]. The difference between the highest and lowest 
///   score is 9 - 4 = 5.
/// - [9,4,1,7]. The difference between the highest and lowest 
/// score is 9 - 1 = 8.
/// - [9,4,1,7]. The difference between the highest and lowest 
///   score is 9 - 7 = 2.
/// - [9,4,1,7]. The difference between the highest and lowest 
///   score is 4 - 1 = 3.
/// - [9,4,1,7]. The difference between the highest and lowest 
///   score is 7 - 4 = 3.
/// - [9,4,1,7]. The difference between the highest and lowest 
///   score is 7 - 1 = 6.
/// The minimum possible difference is 2.
///
/// Constraints:
/// 1. 1 <= k <= nums.length <= 1000
/// 2. 0 <= nums[i] <= 10^5
/// </summary>
int LeetCodeSort::minimumDifference(vector<int>& nums, int k)
{
    int result = INT_MAX;
    if (k == 1) return 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int) nums.size() - (k - 1); i++)
    {
        result = min(result, nums[i + k - 1] - nums[i]);
    }
    return result;
}

/// <summary>
/// Leet code 1921. Eliminate Maximum Number of Monsters
///                                                
/// Medium
/// 
/// You are playing a video game where you are defending your city from 
/// a group of n monsters. You are given a 0-indexed integer array dist 
/// of size n, where dist[i] is the initial distance in kilometers of 
/// the ith monster from the city.
///
/// The monsters walk toward the city at a constant speed. The speed of 
/// each monster is given to you in an integer array speed of size n, 
/// where speed[i] is the speed of the ith monster in kilometers per 
/// minute.
///
/// You have a weapon that, once fully charged, can eliminate a single 
/// monster. However, the weapon takes one minute to charge.The weapon 
/// is fully charged at the very start.
///
/// You lose when any monster reaches your city. If a monster reaches 
/// the city at the exact moment the weapon is fully charged, it counts 
/// as a loss, and the game ends before you can use your weapon.
///
/// Return the maximum number of monsters that you can eliminate before 
/// you lose, or n if you can eliminate all the monsters before they 
/// reach the city.
/// 
/// Example 1:
/// Input: dist = [1,3,4], speed = [1,1,1]
/// Output: 3
/// Explanation:
/// In the beginning, the distances of the monsters are [1,3,4]. You 
/// eliminate the first monster.
/// After a minute, the distances of the monsters are [X,2,3]. You 
/// eliminate the second monster.
/// After a minute, the distances of the monsters are [X,X,2]. You 
/// eliminate the thrid monster.
/// All 3 monsters can be eliminated.
///
/// Example 2:
/// Input: dist = [1,1,2,3], speed = [1,1,1,1]
/// Output: 1
/// Explanation:
/// In the beginning, the distances of the monsters are [1,1,2,3]. 
/// You eliminate the first monster.
/// After a minute, the distances of the monsters are [X,0,1,2], so you 
/// lose.
/// You can only eliminate 1 monster.
///
/// Example 3:
/// Input: dist = [3,2,4], speed = [5,3,2]
/// Output: 1
/// Explanation:
/// In the beginning, the distances of the monsters are [3,2,4]. 
/// You eliminate the first monster.
/// After a minute, the distances of the monsters are [X,0,2], so you lose.
/// You can only eliminate 1 monster.
/// 
/// Constraints:
/// 1. n == dist.length == speed.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= dist[i], speed[i] <= 10^5
/// </summary>
int LeetCodeSort::eliminateMaximum(vector<int>& dist, vector<int>& speed)
{
    priority_queue<pair<double, int>> pq;
    for (size_t i = 0; i < dist.size(); i++)
    {
        pq.push(make_pair(-((double)dist[i]) / speed[i], i));
    }
    int time = 0;
    while (!pq.empty())
    {
        if (speed[pq.top().second] * time >= dist[pq.top().second])
        {
            break;
        }
        pq.pop();
        time++;
    }
    return time;
}

/// <summary>
/// Leet 1985. Find the Kth Largest Integer in the Array
///                                                                 
/// Medium
/// 
/// You are given an array of strings nums and an integer k. Each string 
/// in nums represents an integer without leading zeros.
///
/// Return the string that represents the kth largest integer in nums.
///
/// Note: Duplicate numbers should be counted distinctly. For example, if 
/// nums is ["1","2","2"], "2" is the first largest integer, "2" is the 
/// second-largest integer, and "1" is the third-largest integer. 
/// 
/// Example 1:
/// Input: nums = ["3","6","7","10"], k = 4
/// Output: "3"
/// Explanation:
/// The numbers in nums sorted in non-decreasing order are 
/// ["3","6","7","10"].
/// The 4th largest integer in nums is "3".
/// Example 2:
///
/// Input: nums = ["2","21","12","1"], k = 3
/// Output: "2"
/// Explanation:
/// The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
/// The 3rd largest integer in nums is "2".
/// Example 3:
///
/// Input: nums = ["0","0"], k = 2
/// Output: "0"
/// Explanation:
/// The numbers in nums sorted in non-decreasing order are ["0","0"].
/// The 2nd largest integer in nums is "0".
/// 
/// Constraints:
/// 1. 1 <= k <= nums.length <= 10^4
/// 2. 1 <= nums[i].length <= 100 
/// 3. nums[i] consists of only digits.
/// 4. nums[i] will not have any leading zeros.
/// </summary>
string LeetCodeSort::kthLargestNumber(vector<string>& nums, int k)
{
    priority_queue<pair<int, string>> pq;
    for (size_t i = 0; i < nums.size(); i++)
    {
        pq.push(make_pair(nums[i].size(), nums[i]));
    }
    string result;
    for (int i = 0; i < k-1; i++)
    {
        pq.pop();
    }
    result = pq.top().second;
    return result;
}

/// <summary>
/// Leet Code 1942. The Number of the Smallest Unoccupied Chair
///                                                                 
/// Medium
/// 
/// There is a party where n friends numbered from 0 to n - 1 are 
/// attending. There is an infinite number of chairs in this party 
/// that are numbered from 0 to infinity. When a friend arrives at 
/// the party, they sit on the unoccupied chair with the smallest 
/// number.
///
/// For example, if chairs 0, 1, and 5 are occupied when a friend 
/// comes, they will sit on chair number 2.
/// When a friend leaves the party, their chair becomes unoccupied 
/// at the moment they leave. If another friend arrives at that 
/// same moment, they can sit in that chair.
///
/// You are given a 0-indexed 2D integer array times where 
/// times[i] = [arrivali, leavingi], indicating the arrival and 
/// leaving times of the ith friend respectively, and an integer 
/// targetFriend. All arrival times are distinct.
///
/// Return the chair number that the friend numbered targetFriend 
/// will sit on.
///
/// Example 1:
/// Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
/// Output: 1 
/// Explanation: 
/// - Friend 0 arrives at time 1 and sits on chair 0.
/// - Friend 1 arrives at time 2 and sits on chair 1.
/// - Friend 1 leaves at time 3 and chair 1 becomes empty.
/// - Friend 0 leaves at time 4 and chair 0 becomes empty.
/// - Friend 2 arrives at time 4 and sits on chair 0.
/// Since friend 1 sat on chair 1, we return 1.
///
/// Example 2:
/// Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
/// Output: 2
/// Explanation: 
/// - Friend 1 arrives at time 1 and sits on chair 0.
/// - Friend 2 arrives at time 2 and sits on chair 1.
/// - Friend 0 arrives at time 3 and sits on chair 2.
/// - Friend 1 leaves at time 5 and chair 0 becomes empty.
/// - Friend 2 leaves at time 6 and chair 1 becomes empty.
/// - Friend 0 leaves at time 10 and chair 2 becomes empty. 
/// Since friend 0 sat on chair 2, we return 2.
/// 
/// Constraints:
/// 1. n == times.length
/// 2. 2 <= n <= 104
/// 3. times[i].length == 2
/// 4. 1 <= arrivali < leavingi <= 10^5
/// 5. 0 <= targetFriend <= n - 1
/// 6. Each arrivali time is distinct.
/// </summary>
int LeetCodeSort::smallestChair(vector<vector<int>>& times, int targetFriend)
{
    int n = times.size();
    priority_queue<pair<int, int>> pq;
    vector<int> people(n);
    priority_queue<int> seats;
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(-times[i][0], -(i+1)));
        pq.push(make_pair(-times[i][1], (i + 1)));
        seats.push(-i);
    }
    int result = -1;
    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();

        if (curr.second < 0)
        {
            int person = -(curr.second + 1);
            int seat = seats.top();
            seats.pop();
            people[person] = seat;
            if (person == targetFriend)
            {
                result = 0 - seat;
                break;
            }
        }
        else
        {
            int person = curr.second - 1;
            int seat = people[person];
            seats.push(seat);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1962. Remove Stones to Minimize the Total
///                                                                 
/// Medium
/// 
/// You are given a 0-indexed integer array piles, where piles[i] 
/// represents the number of stones in the ith pile, and an integer 
/// k. You should apply the following operation exactly k times:
///
/// Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
/// Notice that you can apply the operation on the same pile more than 
/// once.
/// 
/// Return the minimum possible total number of stones remaining after 
/// applying the k operations.
///
/// floor(x) is the greatest integer that is smaller than or equal to x 
/// (i.e., rounds x down).
///
/// Example 1:
/// Input: piles = [5,4,9], k = 2
/// Output: 12
/// Explanation: Steps of a possible scenario are:
/// - Apply the operation on pile 2. The resulting piles are [5,4,5].
/// - Apply the operation on pile 0. The resulting piles are [3,4,5].
/// The total number of stones in [3,4,5] is 12.
///
/// Example 2:
/// Input: piles = [4,3,6,7], k = 3
/// Output: 12
/// Explanation: Steps of a possible scenario are:
/// - Apply the operation on pile 2. The resulting piles are [4,3,3,7].
/// - Apply the operation on pile 3. The resulting piles are [4,3,3,4].
/// - Apply the operation on pile 0. The resulting piles are [2,3,3,4].
/// The total number of stones in [2,3,3,4] is 12.
/// 
/// Constraints:
/// 1. 1 <= piles.length <= 10^5
/// 2. 1 <= piles[i] <= 10^4
/// 3. 1 <= k <= 10^5
/// </summary>
int LeetCodeSort::minStoneSum(vector<int>& piles, int k)
{
    priority_queue<int> pq;
    int result = 0;
    for (size_t i = 0; i < piles.size(); i++)
    {
        result += piles[i];
        pq.push(piles[i]);
    }

    for (int i = 0; i < k; i++)
    {
        int stone = pq.top();
        pq.pop();
        result -= stone / 2;
        pq.push(stone - stone / 2);
    }
    return result;
}

/// <summary>
/// Leet Code 1996. The Number of Weak Characters in the Game
///                                                                 
/// Medium
/// 
/// You are playing a game that contains multiple characters, and each of 
/// the characters has two main properties: attack and defense. You are 
/// given a 2D integer array properties where properties[i] = [attacki, 
/// defensei] represents the properties of the ith character in the game.
///
/// A character is said to be weak if any other character has both attack 
/// and defense levels strictly greater than this character's attack and 
/// defense levels. More formally, a character i is said to be weak if 
/// there exists another character j where attackj > attacki and 
/// defensej > defensei.
///  
/// Return the number of weak characters.
///
/// Example 1:
/// Input: properties = [[5,5],[6,3],[3,6]]
/// Output: 0
/// Explanation: No character has strictly greater attack and defense 
/// than the other.
///
/// Example 2:
/// Input: properties = [[2,2],[3,3]]
/// Output: 1
/// Explanation: The first character is weak because the second character 
/// has a strictly greater attack and defense.
///
/// Example 3:
/// Input: properties = [[1,5],[10,4],[4,3]]
/// Output: 1
/// Explanation: The third character is weak because the second character 
/// has a strictly greater attack and defense.
///
/// Constraints:
/// 1. 2 <= properties.length <= 10^5
/// 2. properties[i].length == 2
/// 3. 1 <= attacki, defensei <= 10^5
/// </summary>
int LeetCodeSort::numberOfWeakCharacters(vector<vector<int>>& properties)
{
    map<int, int> defense;
    sort(properties.begin(), properties.end());
    int prev_defense = 0;
    int max_defense = 0;
    for (int i = properties.size() - 1; i >= 0; i--)
    {
        if (i == properties.size() - 1 || properties[i][0] != properties[i + 1][0])
        {
            prev_defense = max_defense;
            defense[properties[i][0]] = prev_defense;
        }
        max_defense = max(max_defense, properties[i][1]);
    }
    int result = 0;
    for (size_t i = 0; i < properties.size(); i++)
    {
        if (defense[properties[i][0]] > properties[i][1])
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1966. Binary Searchable Numbers in an Unsorted Array 
///                                                                 
/// Medium
/// 
/// Consider a function that implements an algorithm similar to Binary 
/// Search. The function has two input parameters: sequence is a sequence 
/// of integers, and target is an integer value. The purpose of the 
/// function is to find if the target exists in the sequence.
///
/// The pseudocode of the function is as follows:
///
/// func(sequence, target)
/// while sequence is not empty
/// randomly choose an element from sequence as the pivot
/// if pivot = target, return true
/// else if pivot < target, remove pivot and all elements to its left 
/// from the sequence
/// else, remove pivot and all elements to its right from the sequence
/// end while
/// return false
/// When the sequence is sorted, the function works correctly for all 
/// values. When the sequence is not sorted, the function does not work 
/// for all values, but may still work for some values.
/// Given an integer array nums, representing the sequence, that contains 
/// unique numbers and may or may not be sorted, return the number of 
/// values that are guaranteed to be found using the function, for every 
/// possible pivot selection.
/// 
/// Example 1:
/// Input: nums = [7]
/// Output: 1
/// Explanation: 
/// Searching for value 7 is guaranteed to be found.
/// Since the sequence has only one element, 7 will be chosen as the 
/// pivot. Because the pivot equals the target, the function will return 
/// true.
///
/// Example 2:
/// Input: nums = [-1,5,2]
/// Output: 1
/// Explanation: 
/// Searching for value -1 is guaranteed to be found.
/// If -1 was chosen as the pivot, the function would return true.
/// If 5 was chosen as the pivot, 5 and 2 would be removed. In the next 
/// loop, the sequence would have only -1 and the function would return 
/// true.
/// If 2 was chosen as the pivot, 2 would be removed. In the next loop, 
/// the sequence would have -1 and 5. No matter which number was chosen 
/// as the next pivot, the function would find -1 and return true.
///
/// Searching for value 5 is NOT guaranteed to be found.
/// If 2 was chosen as the pivot, -1, 5 and 2 would be removed. The 
/// sequence would be empty and the function would return false.
///
/// Searching for value 2 is NOT guaranteed to be found.
/// If 5 was chosen as the pivot, 5 and 2 would be removed. In the next 
/// loop, the sequence would have only -1 and the function would 
/// return false.
///
/// Because only -1 is guaranteed to be found, you should return 1.
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. -10^5 <= nums[i] <= 10^5
/// 3. All the values of nums are unique.
/// Follow-up: If nums has duplicates, would you modify your algorithm? 
/// If so, how?
/// </summary>
int LeetCodeSort::binarySearchableNumbers(vector<int>& nums)
{
    vector<int> dp(nums.size());
    int result = 0;
    int val = INT_MIN;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (nums[i] >= val) dp[i]++;
        val = max(val, nums[i]);
    }
    val = INT_MAX;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] <= val) dp[i]++;
        val = min(val, nums[i]);
        if (dp[i] == 2) result++;
    }
    return result;
}

/// <summary>
/// Leet Code 1968. Array With Elements Not Equal to Average of Neighbors 
///                                                                 
/// Medium
/// 
/// You are given a 0-indexed array nums of distinct integers. You want to 
/// rearrange the elements in the array such that every element in the 
/// rearranged array is not equal to the average of its neighbors.
///
/// More formally, the rearranged array should have the property such that 
/// for every i in the range 1 <= i < nums.length - 1, (nums[i-1] + 
/// nums[i+1]) / 2 is not equal to nums[i].
///
/// Return any rearrangement of nums that meets the requirements.
/// 
/// Example 1:
/// Input: nums = [1,2,3,4,5]
/// Output: [1,2,4,5,3]
/// Explanation:
/// When i=1, nums[i] = 2, and the average of its neighbors is 
/// (1+4) / 2 = 2.5.
/// When i=2, nums[i] = 4, and the average of its neighbors is 
/// (2+5) / 2 = 3.5.
/// When i=3, nums[i] = 5, and the average of its neighbors is 
/// (4+3) / 2 = 3.5.
///
/// Example 2:
/// Input: nums = [6,2,0,9,7]
/// Output: [9,7,6,2,0]
/// Explanation:
/// When i=1, nums[i] = 7, and the average of its neighbors is 
/// (9+6) / 2 = 7.5.
/// When i=2, nums[i] = 6, and the average of its neighbors is 
/// (7+2) / 2 = 4.5.
/// When i=3, nums[i] = 2, and the average of its neighbors is 
/// (6+0) / 2 = 3.
/// 
/// Constraints:
/// 1. 3 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^5
/// </summary>
vector<int> LeetCodeSort::rearrangeArray(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int index = 0;
    vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); i += 2)
    {
        result[i] = nums[index];
        index++;
    }
    for (size_t i = 1; i < nums.size(); i += 2)
    {
        result[i] = nums[index];
        index++;
    }
    return result;
}

/// <summary>
/// Leet Code 2098. Subsequence of Size K With the Largest Even Sum
///                                                                 
/// Medium
///
/// You are given an integer array nums and an integer k. Find the 
/// largest even sum of any subsequence of nums that has a length of k.
///
/// Return this sum, or -1 if such a sum does not exist.
///
/// A subsequence is an array that can be derived from another array 
/// by deleting some or no elements without changing the order of the 
/// remaining elements.
/// 
/// Example 1:
/// Input: nums = [4,1,5,3,1], k = 3
/// Output: 12
/// Explanation:
/// The subsequence with the largest possible even sum is [4,5,3]. It 
/// has a sum of 4 + 5 + 3 = 12.
///
/// Example 2:
/// Input: nums = [4,6,2], k = 3
/// Output: 12
/// Explanation:
/// The subsequence with the largest possible even sum is [4,6,2]. It 
/// has a sum of 4 + 6 + 2 = 12.
///
/// Example 3:
/// Input: nums = [1,3,5], k = 1
/// Output: -1
/// Explanation:
/// No subsequence of nums with length 1 has an even sum.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^5
/// 3. 1 <= k <= nums.length
/// </summary>
long long LeetCodeSort::largestEvenSum(vector<int>& nums, int k)
{
    priority_queue<int> odd, even;
    for (auto n : nums)
    {
        if (n % 2 == 0) even.push(n);
        else odd.push(n);
    }
    long long result = 0;
    if (k % 2 == 1)
    {
        if (even.empty()) return -1;
        result += (long long)even.top();
        even.pop();
        k--;
    }
    while (k > 0)
    {
        if (odd.size() < 2 && even.size() < 2)
        {
            return -1;
        }
        else if (odd.size() < 2)
        {
            result += (long long)even.top();
            even.pop();
            result += (long long)even.top();
            even.pop();
        }
        else if (even.size() < 2)
        {
            result += (long long)odd.top();
            odd.pop();
            result += (long long)odd.top();
            odd.pop();
        }
        else
        {
            int even_top = even.top();
            even.pop();
            int odd_top = odd.top();
            odd.pop();
            if ((long long)even_top + (long long)even.top() > (long long)odd_top + (long long)odd.top())
            {
                result += (long long)even_top + (long long)even.top();
                even.pop();
                odd.push(odd_top);
            }
            else
            {
                result += (long long)odd_top + (long long)odd.top();
                odd.pop();
                even.push(even_top);
            }
        }
        k -= 2;
    }
    return result;
}

/// <summary>
/// Leet Code 2111. Minimum Operations to Make the Array K-Increasing
///                                                                 
/// Hard
///
/// You are given a 0-indexed array arr consisting of n positive 
/// integers, and a positive integer k.
///
/// The array arr is called K-increasing if arr[i-k] <= arr[i] holds 
/// for every index i, where k <= i <= n-1.
///
/// For example, arr = [4, 1, 5, 2, 6, 2] is K-increasing for k = 2 
/// because:
/// arr[0] <= arr[2] (4 <= 5)
/// arr[1] <= arr[3] (1 <= 2)
/// arr[2] <= arr[4] (5 <= 6)
/// arr[3] <= arr[5] (2 <= 2)
/// However, the same arr is not K-increasing for k = 1 (because 
/// arr[0] > arr[1]) or k = 3 (because arr[0] > arr[3]).
/// In one operation, you can choose an index i and change arr[i] into 
/// any positive integer.
///
/// Return the minimum number of operations required to make the array 
/// K-increasing for the given k.
///
/// Example 1:
///
/// Input: arr = [5,4,3,2,1], k = 1
/// Output: 4
/// Explanation:
/// For k = 1, the resultant array has to be non-decreasing.
/// Some of the K-increasing arrays that can be formed are [5,6,7,8,9], 
/// [1,1,1,1,1], [2,2,3,4,4]. All of them require 4 operations.
/// It is suboptimal to change the array to, for example, [6,7,8,9,10]
/// because it would take 5 operations.
/// It can be shown that we cannot make the array K-increasing in less 
/// than 4 operations.
///
/// Example 2:
/// Input: arr = [4,1,5,2,6,2], k = 2
/// Output: 0
/// Explanation:
/// This is the same example as the one in the problem description.
/// Here, for every index i where 2 <= i <= 5, arr[i-2] <= arr[i].
/// Since the given array is already K-increasing, we do not need to 
/// perform any operations.
///
/// Example 3:
/// Input: arr = [4,1,5,2,6,2], k = 3
/// Output: 2
/// Explanation:
/// Indices 3 and 5 are the only ones not satisfying arr[i-3] <= arr[i] 
/// for 3 <= i <= 5.
/// One of the ways we can make the array K-increasing is by changing 
/// arr[3] to 4 and arr[5] to 5.
/// The array will now be [4,1,5,4,6,5].
/// Note that there can be other ways to make the array K-increasing, but 
/// none of them require less than 2 operations.
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 1 <= arr[i], k <= arr.length
/// </summary>
int LeetCodeSort::kIncreasing(vector<int>& arr, int k)
{
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int count = 0; // calculate how many elements
        vector<int>dp;
        for (size_t j = i; j < arr.size(); j+=k)
        {
            count++;
            auto itr = upper_bound(dp.begin(), dp.end(), arr[j]);
            if (itr == dp.end()) dp.push_back(arr[j]);
            else *itr = arr[j];
        }
        result += count - dp.size();
    }
    return result;
}

/// <summary>
/// Leet Code 2070. Most Beautiful Item for Each Query
///                                                                 
/// Medium
///
/// You are given a 2D integer array items where items[i] = 
/// [pricei, beautyi] denotes the price and beauty of an item respectively.
///
/// You are also given a 0-indexed integer array queries. For each 
/// queries[j], you want to determine the maximum beauty of an item whose 
/// price is less than or equal to queries[j]. If no such item exists, 
/// then the answer to this query is 0.
///
/// Return an array answer of the same length as queries where answer[j] 
/// is the answer to the jth query.
/// 
/// Example 1:
/// Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
/// Output: [2,4,5,5,6,6]
/// Explanation:
/// - For queries[0]=1, [1,2] is the only item which has price <= 1. 
///   Hence, the answer for this query is 2.
/// - For queries[1]=2, the items which can be considered are [1,2] 
///   and [2,4]. 
/// The maximum beauty among them is 4.
/// - For queries[2]=3 and queries[3]=4, the items which can be considered 
///   are [1,2], [3,2], [2,4], and [3,5].
/// The maximum beauty among them is 5.
/// - For queries[4]=5 and queries[5]=6, all items can be considered.
/// Hence, the answer for them is the maximum beauty of all items, i.e., 6.
///
/// Example 2:
/// Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
/// Output: [4]
/// Explanation: 
/// The price of every item is equal to 1, so we choose the item with 
/// the maximum beauty 4. 
/// Note that multiple items can have the same price and/or beauty.  
/// Example 3:
/// Input: items = [[10,1000]], queries = [5]
/// Output: [0]
/// Explanation:
/// No item has a price less than or equal to 5, so no item can be chosen.
/// Hence, the answer to the query is 0.
/// 
/// Constraints:
/// 1. 1 <= items.length, queries.length <= 10^5
/// 2. items[i].length == 2
/// 3. 1 <= pricei, beautyi, queries[j] <= 10^9
/// </summary>
vector<int> LeetCodeSort::maximumBeauty(vector<vector<int>>&items, vector<int>&queries)
{
    map<int, int> item_prices;
    for (size_t i = 0; i < items.size(); i++)
    {
        item_prices[items[i][0]] = max(item_prices[items[i][0]], items[i][1]);
    }
    int prev_beauty = 0;
    for (auto itr : item_prices)
    {
        item_prices[itr.first] = max(prev_beauty, itr.second);
        prev_beauty = max(prev_beauty, itr.second);
    }
    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        auto itr = item_prices.upper_bound(queries[i]);
        if (itr == item_prices.begin())
        {
            result[i] = 0;
        }
        else
        {
            result[i] = prev(itr)->second;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2136. Earliest Possible Day of Full Bloom
///                                                                 
/// Hard
///
/// You have n flower seeds. Every seed must be planted first before it 
/// can begin to grow, then bloom. Planting a seed takes time and so does 
/// the growth of a seed. You are given two 0-indexed integer arrays 
/// plantTime and growTime, of length n each:
///
/// plantTime[i] is the number of full days it takes you to plant the ith 
/// seed. Every day, you can work on planting exactly one seed. You do not 
/// have to work on planting the same seed on consecutive days, but the 
/// planting of a seed is not complete until you have worked plantTime[i] 
/// days on planting it in total.
/// growTime[i] is the number of full days it takes the ith seed to grow 
/// after being completely planted. After the last day of its growth, the 
/// flower blooms and stays bloomed forever.
/// From the beginning of day 0, you can plant the seeds in any order.
///
/// Return the earliest possible day where all seeds are blooming.
///
/// Example 1:
/// Input: plantTime = [1,4,3], growTime = [2,3,1]
/// Output: 9
/// Explanation: The grayed out pots represent planting days, colored pots 
/// represent growing days, and the flower represents the day it blooms.
/// One optimal way is:
/// On day 0, plant the 0th seed. The seed grows for 2 full days and 
/// blooms on day 3.
/// On days 1, 2, 3, and 4, plant the 1st seed. The seed grows for 3 full 
/// days and blooms on day 8.
/// On days 5, 6, and 7, plant the 2nd seed. The seed grows for 1 full day 
/// and blooms on day 9.
/// Thus, on day 9, all the seeds are blooming.
///
/// Example 2:
/// Input: plantTime = [1,2,3,2], growTime = [2,1,2,1]
/// Output: 9
/// Explanation: The grayed out pots represent planting days, colored pots 
/// represent growing days, and the flower represents the day it blooms.
/// One optimal way is:
/// On day 1, plant the 0th seed. The seed grows for 2 full days and 
/// blooms on day 4.
/// On days 0 and 3, plant the 1st seed. The seed grows for 1 full day and 
/// blooms on day 5.
/// On days 2, 4, and 5, plant the 2nd seed. The seed grows for 2 full 
/// days and blooms on day 8.
/// On days 6 and 7, plant the 3rd seed. The seed grows for 1 full day 
/// and blooms on day 9.
/// Thus, on day 9, all the seeds are blooming.
///
/// Example 3:
/// Input: plantTime = [1], growTime = [1]
/// Output: 2
/// Explanation: On day 0, plant the 0th seed. The seed grows for 1 full 
/// day and blooms on day 2.
/// Thus, on day 2, all the seeds are blooming.
///
/// Constraints:
/// 1. n == plantTime.length == growTime.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= plantTime[i], growTime[i] <= 10^4
/// </summary>
int LeetCodeSort::earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
{
    int result = 0;
    int planStart = 0;
    priority_queue<pair<int, int>> pq;
    for (size_t i = 0; i < plantTime.size(); i++)
    {
        pq.push(make_pair(growTime[i], plantTime[i]));
    }
    while (!pq.empty())
    {
        pair<int, int> pair = pq.top();
        pq.pop();
        planStart += pair.second;
        result = max(result, planStart + pair.first);
    }
    return result;
}

/// <summary>
/// Leet Code 2126. Destroying Asteroids
///                                                                 
/// Medium
///
/// You are given an integer mass, which represents the original mass of 
/// a planet. You are further given an integer array asteroids, where 
/// asteroids[i] is the mass of the ith asteroid.
///
/// You can arrange for the planet to collide with the asteroids in any 
/// arbitrary order. If the mass of the planet is greater than or equal 
/// to the mass of the asteroid, the asteroid is destroyed and the planet 
/// gains the mass of the asteroid. Otherwise, the planet is destroyed.
/// 
/// Return true if all asteroids can be destroyed. Otherwise, return false.
///
/// 
/// Example 1:
/// Input: mass = 10, asteroids = [3,9,19,5,21]
/// Output: true
/// Explanation: One way to order the asteroids is [9,19,5,3,21]:
/// - The planet collides with the asteroid with a mass of 9. New planet 
///   mass: 10 + 9 = 19
/// - The planet collides with the asteroid with a mass of 19. New planet 
///   mass: 19 + 19 = 38
/// - The planet collides with the asteroid with a mass of 5. New planet 
///   mass: 38 + 5 = 43
/// - The planet collides with the asteroid with a mass of 3. New planet 
///   mass: 43 + 3 = 46
/// - The planet collides with the asteroid with a mass of 21. New planet 
///   mass: 46 + 21 = 67
/// All asteroids are destroyed.
///
/// Example 2:
/// Input: mass = 5, asteroids = [4,9,23,4]
/// Output: false
/// Explanation: 
/// The planet cannot ever gain enough mass to destroy the asteroid with a 
/// mass of 23.
/// After the planet destroys the other asteroids, it will have a mass 
/// of 5 + 4 + 9 + 4 = 22.
/// This is less than 23, so a collision would not destroy the last 
/// asteroid.
/// 
/// Constraints:
/// 1. 1 <= mass <= 10^5
/// 2. 1 <= asteroids.length <= 10^5
/// 3. 1 <= asteroids[i] <= 10^5
/// </summary>
bool LeetCodeSort::asteroidsDestroyed(int mass, vector<int>& asteroids)
{
    sort(asteroids.begin(), asteroids.end());
    long long sum = mass;
    for (size_t i = 0; i < asteroids.size(); i++)
    {
        if (sum < (long long)asteroids[i])
        {
            return false;
        }
        else
        {
            sum += asteroids[i];
        }
    }
    return true;
}

/// <summary>
/// Leet Code 2144. Minimum Cost of Buying Candies With Discount
///                                                                 
/// Easy
///
/// A shop is selling candies at a discount. For every two candies sold, 
/// the shop gives a third candy for free.
///
/// The customer can choose any candy to take away for free as long as 
/// the cost of the chosen candy is less than or equal to the minimum 
/// cost of the two candies bought.
///
/// For example, if there are 4 candies with costs 1, 2, 3, and 4, and 
/// the customer buys candies with costs 2 and 3, they can take the candy 
/// with cost 1 for free, but not the candy with cost 4.
/// Given a 0-indexed integer array cost, where cost[i] denotes the cost 
/// of the ith candy, return the minimum cost of buying all the candies.
///
/// Example 1:
/// Input: cost = [1,2,3]
/// Output: 5
/// Explanation: We buy the candies with costs 2 and 3, and take the candy 
/// with cost 1 for free.
/// The total cost of buying all candies is 2 + 3 = 5. This is the only 
/// way we can buy the candies.
/// Note that we cannot buy candies with costs 1 and 3, and then take the 
/// candy with cost 2 for free.
/// The cost of the free candy has to be less than or equal to the minimum 
/// cost of the purchased candies.
///
/// Example 2:
/// Input: cost = [6,5,7,9,2,2]
/// Output: 23
/// Explanation: The way in which we can get the minimum cost is described 
/// below:
/// - Buy candies with costs 9 and 7
/// - Take the candy with cost 6 for free
/// - We buy candies with costs 5 and 2
/// - Take the last remaining candy with cost 2 for free
/// Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
///
/// Example 3:
/// Input: cost = [5,5]
/// Output: 10
/// Explanation: Since there are only 2 candies, we buy both of them. 
/// There is not a third candy we can take for free.
/// Hence, the minimum cost to buy all candies is 5 + 5 = 10.
///
/// Constraints:
/// 1. 1 <= cost.length <= 100
/// 2. 1 <= cost[i] <= 100
/// </summary>
int LeetCodeSort::minimumCost(vector<int>& cost)
{
    sort(cost.begin(), cost.end());
    reverse(cost.begin(), cost.end());
    int result = 0;
    for (size_t i = 0; i < cost.size(); i++)
    {
        if ((i + 1) % 3 != 0) result += cost[i];
    }
    return result;
}

/// <summary>
/// Leet Code 2148. Count Elements With Strictly Smaller and Greater 
///                 Elements
///                                                                 
/// Easy
///
/// Given an integer array nums, return the number of elements that have 
/// both a strictly smaller and a strictly greater element appear in nums.
///
/// Example 1:
/// Input: nums = [11,7,2,15]
/// Output: 2
/// Explanation: The element 7 has the element 2 strictly smaller than it 
/// and the element 11 strictly greater than it.
/// Element 11 has element 7 strictly smaller than it and element 15 
/// strictly greater than it.
/// In total there are 2 elements having both a strictly smaller and a 
/// strictly greater element appear in nums.
///
/// Example 2:
/// Input: nums = [-3,3,3,90]
/// Output: 2
/// Explanation: The element 3 has the element -3 strictly smaller than 
/// it and the element 90 strictly greater than it.
/// Since there are two elements with the value 3, in total there are 2 
/// elements having both a strictly smaller and a strictly greater element 
/// appear in nums.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. -10^5 <= nums[i] <= 10^5
/// </summary>
int LeetCodeSort::countElements(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int result = 0;
    for (size_t i = 1; i + 1 < nums.size(); i++)
    {
        if (nums[i] != nums[0] && nums[i] != nums[nums.size() - 1])
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2164. Sort Even and Odd Indices Independently
///                                                                 
/// Easy
///
/// You are given a 0-indexed integer array nums. Rearrange the values 
/// of nums according to the following rules:
///
/// Sort the values at odd indices of nums in non-increasing order.
/// For example, if nums = [4,1,2,3] before this step, it 
/// becomes [4,3,2,1] after. The values at odd indices 1 and 3 are 
/// sorted in non-increasing order.
/// Sort the values at even indices of nums in non-decreasing order.
/// For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] 
/// after. The values at even indices 0 and 2 are sorted in non-decreasing 
/// order.
/// Return the array formed after rearranging the values of nums.
///
/// Example 1:
/// Input: nums = [4,1,2,3]
/// Output: [2,3,4,1]
/// Explanation: 
/// First, we sort the values present at odd indices (1 and 3) in 
/// non-increasing order.
/// So, nums changes from [4,1,2,3] to [4,3,2,1].
/// Next, we sort the values present at even indices (0 and 2) in 
/// non-decreasing order.
/// So, nums changes from [4,1,2,3] to [2,3,4,1].
/// Thus, the array formed after rearranging the values is [2,3,4,1].
///
/// Example 2:
/// Input: nums = [2,1]
/// Output: [2,1]
/// Explanation: 
/// Since there is exactly one odd index and one even index, no 
/// rearrangement of values takes place.
/// The resultant array formed is [2,1], which is the same as the initial 
/// array. 
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 1 <= nums[i] <= 100
/// </summary>
vector<int> LeetCodeSort::sortEvenOdd(vector<int>& nums)
{
    vector<int> even;
    vector<int> odd;
    for (size_t i = 0; i < nums.size(); i += 2)
    {
        even.push_back(nums[i]);
        if (i + 1 < nums.size())
        {
            odd.push_back(0 - nums[i+1]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    vector<int> result;
    for (size_t i = 0; i < nums.size(); i += 2)
    {
        result.push_back(even[i/2]);
        if (i + 1 < nums.size())
        {
           result.push_back(0 - odd[i/2]);
        }
    }
    return result;
}


/// <summary>
/// Leet Code 2165. Smallest Value of the Rearranged Number
///                                                                 
/// Medium
///
/// You are given an integer num. Rearrange the digits of num such that 
/// its value is minimized and it does not contain any leading zeros.
///
/// Return the rearranged number with minimal value.
/// Note that the sign of the number does not change after rearranging 
/// the digits.
///
/// Example 1:
/// Input: num = 310
/// Output: 103
/// Explanation: The possible arrangements for the digits of 310 
/// are 013, 031, 103, 130, 301, 310. 
/// The arrangement with the smallest value that does not contain any 
/// leading zeros is 103.
///
/// Example 2:
/// Input: num = -7605
/// Output: -7650
/// Explanation: Some possible arrangements for the digits of -7605 
/// are -7650, -6705, -5076, -0567.
/// The arrangement with the smallest value that does not contain 
/// any leading zeros is -7650.
///
/// Constraints:
/// 1. -10^15 <= num <= 10^15
/// </summary>
long long LeetCodeSort::smallestNumber(long long num)
{
    if (num == 0) return num;
    vector<int> digits;
    long long n = llabs(num);
    while (n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }

    sort(digits.begin(), digits.end());
    size_t i = 0;
    while (i < digits.size() && digits[i] == 0) i++;
    long long result = 0;
    if (num < 0)
    {
        for (int j = digits.size() - 1; j >= 0; j--)
        {
            result = result * 10 + (long long)digits[j];
        }
        result = 0 - result;
    }
    else
    {
        result = digits[i];
        for (size_t j = 0; j < i; j++)
        {
            result = result * 10;
        }
        for (size_t j = i + 1; j < digits.size(); j++)
        {
            result = result * 10 + (long long)digits[j];
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2171. Removing Minimum Number of Magic Beans
///                                                                                  
/// Medium
///
/// You are given an array of positive integers beans, where each integer 
/// represents the number of magic beans found in a particular magic bag.
///
/// Remove any number of beans (possibly none) from each bag such that 
/// the number of beans in each remaining non-empty bag (still containing 
/// at least one bean) is equal. Once a bean has been removed from a bag, 
/// you are not allowed to return it to any of the bags.
///
/// Return the minimum number of magic beans that you have to remove.
/// 
/// Example 1:
/// Input: beans = [4,1,6,5]
/// Output: 4
/// Explanation: 
/// - We remove 1 bean from the bag with only 1 bean.
/// This results in the remaining bags: [4,0,6,5]
/// - Then we remove 2 beans from the bag with 6 beans.
///   This results in the remaining bags: [4,0,4,5]
/// - Then we remove 1 bean from the bag with 5 beans.
///   This results in the remaining bags: [4,0,4,4]
/// We removed a total of 1 + 2 + 1 = 4 beans to make the remaining 
/// non-empty bags have an equal number of beans.
/// There are no other solutions that remove 4 beans or fewer.
///
/// Example 2:
/// Input: beans = [2,10,3,2]
/// Output: 7
/// Explanation:
/// - We remove 2 beans from one of the bags with 2 beans.
///  This results in the remaining bags: [0,10,3,2]
/// - Then we remove 2 beans from the other bag with 2 beans.
///  This results in the remaining bags: [0,10,3,0]
/// - Then we remove 3 beans from the bag with 3 beans. 
/// This results in the remaining bags: [0,10,0,0]
/// We removed a total of 2 + 2 + 3 = 7 beans to make the remaining 
/// non-empty bags have an equal number of beans.
/// There are no other solutions that removes 7 beans or fewer.
/// 
/// Constraints:
/// 1. 1 <= beans.length <= 10^5
/// 2. 1 <= beans[i] <= 10^5
/// </summary>
long long LeetCodeSort::minimumRemoval(vector<int>& beans)
{
    map<int, int> bean_count;
    long long low_sum = 0;
    for (size_t i = 0; i < beans.size(); i++)
    {
        low_sum += beans[i];
        bean_count[beans[i]]++;
    }
    bean_count.erase(0);
    long long high_sum = 0;
    long long prev_count = 0;
    long long prev_val = 0;
    long long result = LLONG_MAX;
    while (!bean_count.empty())
    {
        long long val = bean_count.rbegin()->first;
        long long count = bean_count.rbegin()->second;

        low_sum = low_sum - val * count;
        high_sum = prev_count * (prev_val - val) + high_sum;
        result = min(result, low_sum + high_sum);
        prev_count += count;
        prev_val = val;
        bean_count.erase((int)val);
    }
    return result;
}
#pragma endregion
