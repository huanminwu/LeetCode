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

#pragma region TwoPointers

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
int LeetCode::maxArea(vector<int>& height)
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
int LeetCode::threeSumClosest(vector<int>& nums, int target)
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
int LeetCode::trapWater(vector<int>& height)
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
/// Given an array and a value, remove all instances of that value in place and return the new length. 
/// Do not allocate extra space for another array, you must do this in place with constant memory.
/// The order of elements can be changed. It doesn't matter what you leave beyond the new length.
/// Example:
/// Given input array nums = [3,2,2,3], val = 3 
/// Your function should return length = 2, with the first two elements of nums being 2.	
/// </summary> 
int LeetCode::removeArrayElement(vector<int>& nums, int val)
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
/// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
/// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].  
/// Note:
/// 1.You must do this in-place without making a copy of the array.
/// 2.Minimize the total number of operations
/// </summary>
void LeetCode::moveZeroes(vector<int>& nums)
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
/// Leet code #125. Valid Palindrome  
/// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
/// For example,
/// "A man, a plan, a canal: Panama" is a palindrome.
/// "race a car" is not a palindrome.
/// Notes:
/// Have you consider that the string might be empty? This is a good question to ask during an interview.
/// For the purpose of this problem, we define empty string as valid palindrome. 
/// </summary>
bool LeetCode::isPalindrome(string s)
{
	int first = 0;
	int last = s.size() - 1;
	while (first < last)
	{
		if (!isalnum(s[first]))
		{
			first++;
		}
		else if (!isalnum(s[last]))
		{
			last--;
		}
		else if (tolower(s[first]) == tolower(s[last]))
		{
			first++;
			last--;
		}
		else
		{
			return false;
		}
	}
	return true;
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
string LeetCode::reverseVowels(string s)
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

/// <summary>
/// Leet code #167. Two Sum II - Input array is sorted            
/// Given an array of integers that is already sorted in ascending order, 
/// find two numbers such that they add up to a specific target number.
/// The function twoSum should return indices of the two numbers such that they add up to the target, 
/// where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
///
/// You may assume that each input would have exactly one solution. 
/// Input: numbers={2, 7, 11, 15}, target=9
///
/// Output: index1=1, index2=2 
/// </summary>
vector<int> LeetCode::twoSumII(vector<int>& numbers, int target)
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
/// Leet code #228. Summary Ranges
/// Given a sorted integer array without duplicates, return the summary of its ranges.
/// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
/// </summary>
vector<string> LeetCode::summaryRanges(vector<int>& nums)
{
	vector<string> result;
	size_t first = 0, last = 0, next = 1;
	while (last < nums.size())
	{
		if (next == nums.size() || nums[last] + 1 < nums[next])
		{
			if (first == last)
			{
				result.push_back(to_string(nums[first]));
			}
			else
			{
				result.push_back(to_string(nums[first]) + "->" + to_string(nums[last]));
			}
			first = next;
			last = next;
		}
		else
		{
			last++;
		}
		next++;
	}
	return result;
}

/// <summary>
/// Leet code #209. Minimum Size Subarray Sum    
/// 
/// Given an array of n positive integers and a positive integer s, 
/// find the minimal length of a subarray of which the sum ≥ s. If there 
/// isn't one, return 0 instead. 
/// For example, given the array [2,3,1,2,4,3] and s = 7,
/// the subarray [4,3] has the minimal length under the problem constraint. 
/// </summary>
int LeetCode::minSubArrayLen(int s, vector<int>& nums)
{
	int result = -1;
	vector<int> sums(nums.size() + 1);
	int total = 0;
	for (size_t i = 0; i <= nums.size(); i++)
	{
		sums[i] = total;
		if (i < nums.size()) total += nums[i];
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
			if (sums[last] - sums[first] >= s)
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
int LeetCode::threeSumSmaller(vector<int>& nums, int target)
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
/// Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.  
/// Example 1: 
/// Input: [1,0,1,1,0]
///
/// Output: 4 
/// Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
/// After flipping, the maximum number of consecutive 1s is 4.
///	Note:
/// The input array will only contain 0 and 1.
/// The length of input array is a positive integer and will not exceed 10,000
/// Follow up:
/// What if the input numbers come in one by one as an infinite stream? In other words, 
/// you can't store all numbers coming from the stream as it's too large to hold in memory. 
/// Could you solve it efficiently? 
/// </summary>
int LeetCode::findMaxConsecutiveOnesII(vector<int>& nums)
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
string LeetCode::findContestMatch(int n)
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
bool LeetCode::validPalindrome(string s)
{
	stack<pair<string, int>> process_stack;
	process_stack.push(make_pair(s, 0));
	while (!process_stack.empty())
	{
		pair<string, int> entity = process_stack.top();
		process_stack.pop();
		string str = entity.first;
		int left = 0, right = str.size() - 1;
		// if both end are equal we are safe to stripe both end
		while ((left <  right) && (str[left] == str[right]))
		{
			left++;
			right--;
		}
		if (left < right)
		{
			// we stripe either head, if no mismatch found
			if (entity.second == 0)
			{
				process_stack.push(make_pair(str.substr(left + 1, right - left), entity.second + 1));
				process_stack.push(make_pair(str.substr(left, right - left), entity.second + 1));
			}
		}
		else if (entity.second <= 1)
		{
			return true;
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
int LeetCode::numSubarrayProductLessThanK(vector<int>& nums, int k)
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
int LeetCode::compress(vector<char>& chars)
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
vector<int> LeetCode::pourWater(vector<int>& heights, int V, int K)
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
int LeetCode::totalFruit(vector<int>& tree)
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
string LeetCode::reverseOnlyLetters(string S)
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
int LeetCode::partitionDisjoint(vector<int>& A)
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
int LeetCode::numKLenSubstrNoRepeats(string S, int K)
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
bool LeetCode::isMajorityElement(vector<int>& nums, int target)
{
    int first =  lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int last = first;

    while ((last < (int)nums.size()) && (nums[first] == nums[last])) last++;
    if ((last - first) > (int)nums.size() / 2) return true;
    else return false;
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
int LeetCode::maxRepOpt1(string text)
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
int LeetCode::countLetters(string S)
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



#pragma endregion
