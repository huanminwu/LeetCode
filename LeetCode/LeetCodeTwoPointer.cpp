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
#include "LeetcodeTwoPointer.h"
#pragma region TwoPointer

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
int LeetCodeTwoPointer::numRescueBoats(vector<int>& people, int limit)
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
/// Leet Code 1852. Distinct Numbers in Each Subarray
///                                                                 
/// Medium
///
/// Given an integer array nums and an integer k, you are asked to 
/// construct the array ans of size n-k+1 where ans[i] is the number 
/// of distinct numbers in the subarray nums[i:i+k-1] = [nums[i], 
/// nums[i+1], ..., nums[i+k-1]].
///
/// Return the array ans.
/// 
/// Example 1:
/// Input: nums = [1,2,3,2,2,1,3], k = 3
/// Output: [3,2,2,2,3]
/// Explanation: The number of distinct elements in each subarray goes 
/// as follows:
/// - nums[0:2] = [1,2,3] so ans[0] = 3
/// - nums[1:3] = [2,3,2] so ans[1] = 2
/// - nums[2:4] = [3,2,2] so ans[2] = 2
/// - nums[3:5] = [2,2,1] so ans[3] = 2
/// - nums[4:6] = [2,1,3] so ans[4] = 3
///
/// Example 2:
/// Input: nums = [1,1,1,1,2,3,4], k = 4
/// Output: [1,2,3,4]
/// Explanation: The number of distinct elements in each subarray goes 
/// as follows:
/// - nums[0:3] = [1,1,1,1] so ans[0] = 1
/// - nums[1:4] = [1,1,1,2] so ans[1] = 2
/// - nums[2:5] = [1,1,2,3] so ans[2] = 3
/// - nums[3:6] = [1,2,3,4] so ans[3] = 4
///
/// Constraints:
/// 1. 1 <= k <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^5
/// </summary>
vector<int> LeetCodeTwoPointer::distinctNumbers(vector<int>& nums, int k)
{
    unordered_map<int, int> num_map;
    int first = 0;
    int last = 0;
    vector<int> result;
    while (last < k - 1)
    {
        num_map[nums[last]]++;
        last++;
    }

    while (last < (int)nums.size())
    {
        num_map[nums[last]]++;
        result.push_back(num_map.size());
        num_map[nums[first]]--;
        if (num_map[nums[first]] == 0)
        {
            num_map.erase(nums[first]);
        }
        first++;
        last++;
    }
    return result;
}

/// <summary>
/// Leet Code 2062. Count Vowel Substrings of a String
///                                                                 
/// Easy
///
/// A substring is a contiguous (non-empty) sequence of characters within 
/// a string.
///
/// A vowel substring is a substring that only consists of vowels 
/// ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
/// Given a string word, return the number of vowel substrings in word.
///
/// Example 1:
/// Input: word = "aeiouu"
/// Output: 2
/// Explanation: The vowel substrings of word are as follows (underlined):
/// - "aeiouu"
/// - "aeiouu"
///
/// Example 2:
/// Input: word = "unicornarihan"
/// Output: 0
/// Explanation: Not all 5 vowels are present, so there are no vowel 
/// substrings.
///
/// Example 3:
/// Input: word = "cuaieuouac"
/// Output: 7
/// Explanation: The vowel substrings of word are as follows (underlined):
/// - "cuaieuouac"
/// - "cuaieuouac"
/// - "cuaieuouac"
/// - "cuaieuouac"
/// - "cuaieuouac"
/// - "cuaieuouac"
/// - "cuaieuouac"
///
/// Example 4:
/// Input: word = "bbaeixoubb"
/// Output: 0
/// Explanation: The only substrings that contain all five vowels also 
/// contain 
/// consonants, so there are no vowel substrings.
/// 
/// Constraints:
/// 1. 1 <= word.length <= 100
/// 2. word consists of lowercase English letters only.
/// </summary>
int LeetCodeTwoPointer::countVowelSubstrings(string word)
{
    int first = -1;
    int last = 0;
    int count = 0;
    int head = 0;
    int result = 0;
    unordered_map<char, int> vowel_map = 
    { 
        {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0} 
    };
    while (last < (int)word.size())
    {
        if (vowel_map.count(word[last]) > 0)
        {
            if (first == -1)
            {
                vowel_map['a'] = vowel_map['e'] = vowel_map['i'] = vowel_map['o'] = vowel_map['u'] = 0;
                first = last;
                head = first;
                count = 0;
            }
            vowel_map[word[last]]++;
            if (vowel_map[word[last]] == 1) count++;
            if (count == 5)
            {
                while(vowel_map[word[head]] > 1)
                {
                    vowel_map[word[head]]--;
                    head++;
                }
                result += head - first + 1;
            }
        }
        else
        {
            first = -1;
        }
        last++;
    }
    return result;
}

/// <summary>
/// Leet Code 2106. Maximum Fruits Harvested After at Most K Steps
///                                                                 
/// Hard
///
/// Fruits are available at some positions on an infinite x-axis. You are 
/// given a 2D integer array fruits where fruits[i] = [positioni, amounti] 
/// depicts amounti fruits at the position positioni. fruits is already 
/// sorted by positioni in ascending order, and each positioni is unique.
///
/// You are also given an integer startPos and an integer k. Initially, 
/// you are at the position startPos. From any position, you can either 
/// walk to the left or right. It takes one step to move one unit on the 
/// x-axis, and you can walk at most k steps in total. For every position 
/// you reach, you harvest all the fruits at that position, and the 
/// fruits will disappear from that position.
///
/// Return the maximum total number of fruits you can harvest.
/// 
/// Example 1:
/// Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
/// Output: 9
/// Explanation: 
/// The optimal way is to:
/// - Move right to position 6 and harvest 3 fruits
/// - Move right to position 8 and harvest 6 fruits
/// You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
///
/// Example 2:
/// Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], 
/// startPos = 5, k = 4
/// Output: 14
/// Explanation: 
/// You can move at most k = 4 steps, so you cannot reach position 0 
/// nor 10.
/// The optimal way is to:
/// - Harvest the 7 fruits at the starting position 5
/// - Move left to position 4 and harvest 1 fruit
/// - Move right to position 6 and harvest 2 fruits
/// - Move right to position 7 and harvest 4 fruits
/// You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 
/// fruits in total.
///
/// Example 3:
/// Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
/// Output: 0
/// Explanation:
/// You can move at most k = 2 steps and cannot reach any position with 
/// fruits.
/// 
/// Constraints:
/// 1. 1 <= fruits.length <= 10^5
/// 2. fruits[i].length == 2
/// 3. 0 <= startPos, positioni <= 2 * 10^5
/// 4. positioni-1 < positioni for any i > 0 (0-indexed)
/// 5. 1 <= amounti <= 10^4
/// 6. 0 <= k <= 2 * 10^5
/// </summary>
int LeetCodeTwoPointer::maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k)
{
    map<int, int> road;
    for (size_t i = 0; i < fruits.size(); i++)
    {
        road[fruits[i][0]] = fruits[i][1];
    }
    int result = 0;
    auto left = road.lower_bound(startPos - k);
    auto right = road.lower_bound(startPos);
    int sum = 0;
    for (auto itr = left; itr != right; itr++)
    {
        sum += itr->second;
    }
    result = max(result, sum);
    while (right != road.end())
    {
        if (left->first < startPos)
        {
            if ((((startPos - left->first) + 2 * (right->first - startPos)) <= k) ||
                (((startPos - left->first) * 2 + (right->first - startPos)) <= k))
            {
                sum += right->second;
                result = max(result, sum);
                right++;
            }
            else
            {
                sum -= left->second;
                left++;
            }
        }
        else
        {
            if ((right->first - startPos) <= k)
            {
                sum += right->second;
                result = max(result, sum);
                right++;
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
/// Leet Code 2107. Number of Unique Flavors After Sharing K Candies
///                                                                 
/// Medium
///
/// You are given a 0-indexed integer array candies, where candies[i] 
/// represents the flavor of the ith candy. Your mom wants you to share 
/// these candies with your little sister by giving her k consecutive 
/// candies, but you want to keep as many flavors of candies as possible.
///
/// Return the maximum number of unique flavors of candy you can keep 
/// after sharing with your sister.
/// 
/// Example 1:
/// Input: candies = [1,2,2,3,4,3], k = 3
/// Output: 3
/// Explanation:
/// Give the candies in the range [1, 3] (inclusive) with flavors [2,2,3].
/// You can eat the candies with flavors [1,4,3].
/// There are 3 unique flavors, so return 3.
///
/// Example 2:
/// Input: candies = [2,2,2,2,3,3], k = 2
/// Output: 2
/// Explanation:
/// Give the candies in the range [3, 4] (inclusive) with flavors [2,3].
/// You can eat the candies with flavors [2,2,2,3].
/// There are 2 unique flavors, so return 2.
/// Note that you can also share the candies with flavors [2,2] and eat 
/// the candies with flavors [2,2,3,3].
///
/// Example 3:
/// Input: candies = [2,4,5], k = 0
/// Output: 3
/// Explanation:
/// You do not have to give any candies.
/// You can eat the candies with flavors [2,4,5].
/// There are 3 unique flavors, so return 3.
///
/// Example 4:
/// Input: candies = [2,4,5], k = 3
/// Output: 0
/// Explanation:
/// You have to give all the candies.
/// You do not have any candies left over, so return 0.
/// 
/// Constraints:
/// 1. 1 <= candies.length <= 10^5
/// 2. 1 <= candies[i] <= 10^5
/// 3. 0 <= k <= candies.length
/// </summary>
int LeetCodeTwoPointer::shareCandies(vector<int>& candies, int k)
{
    unordered_map<int, int> flavors;
    for (size_t i = 0; i < candies.size(); i++)
    {
        flavors[candies[i]]++;
    }
    int count = flavors.size();
    if (k == 0) return count;
    int first = 0;
    int last = 0;
    int result = 0;
    while (last < (int)candies.size())
    {
        flavors[candies[last]]--;
        if (flavors[candies[last]] == 0)
        {
            count--;
        }
        last++;
        if (last - first == k)
        {
            result = max(result, count);
            flavors[candies[first]]++;
            if (flavors[candies[first]] == 1)
            {
                count++;
            }
            first++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2105. Watering Plants II
///                                                                 
/// Medium
///
/// Alice and Bob want to water n plants in their garden. The plants are 
/// arranged in a row and are labeled from 0 to n - 1 from left to right 
/// where the ith plant is located at x = i.
///
/// Each plant needs a specific amount of water. Alice and Bob have a 
/// watering can each, initially full. They water the plants in the 
/// following way:
///
/// Alice waters the plants in order from left to right, starting from 
/// the 0th plant. Bob waters the plants in order from right to left, 
/// starting from the (n - 1)th plant. They begin watering the plants 
/// simultaneously.
/// It takes the same amount of time to water each plant regardless of 
/// how much water it needs.
/// Alice/Bob must water the plant if they have enough in their can to 
/// fully water it. Otherwise, they first refill their can 
/// (instantaneously) then water the plant.
/// In case both Alice and Bob reach the same plant, the one with more 
/// water currently in his/her watering can should water this plant. If 
/// they have the same amount of water, then Alice should water this plant.
/// Given a 0-indexed integer array plants of n integers, where plants[i] 
/// is the amount of water the ith plant needs, and two integers capacityA 
/// and capacityB representing the capacities of Alice's and Bob's 
/// watering cans respectively, return the number of times they have to 
/// refill to water all the plants.
/// 
/// Example 1:
/// Input: plants = [2,2,3,3], capacityA = 5, capacityB = 5
/// Output: 1
/// Explanation:
/// - Initially, Alice and Bob have 5 units of water each in their 
///   watering cans.
/// - Alice waters plant 0, Bob waters plant 3.
/// - Alice and Bob now have 3 units and 2 units of water respectively.
/// - Alice has enough water for plant 1, so she waters it. Bob does not 
///   have enough water for plant 2, so he refills his can then waters it.
/// So, the total number of times they have to refill to water all the 
/// plants is 0 + 0 + 1 + 0 = 1.
///
/// Example 2:
/// Input: plants = [2,2,3,3], capacityA = 3, capacityB = 4
/// Output: 2
/// Explanation:
/// - Initially, Alice and Bob have 3 units and 4 units of water in their 
///   watering cans respectively.
/// - Alice waters plant 0, Bob waters plant 3.
/// - Alice and Bob now have 1 unit of water each, and need to water 
///   plants 1 and 2 respectively.
/// - Since neither of them have enough water for their current plants, 
///   they refill their cans and then water the plants.
/// So, the total number of times they have to refill to water all the 
/// plants is 0 + 1 + 1 + 0 = 2.
///
/// Example 3:
/// Input: plants = [5], capacityA = 10, capacityB = 8
/// Output: 0
/// Explanation:
/// - There is only one plant.
/// - Alice's watering can has 10 units of water, whereas Bob's can has 8 
/// units. Since Alice has more water in her can, she waters this plant.
/// So, the total number of times they have to refill is 0.
///
/// Constraints:
/// 1. n == plants.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= plants[i] <= 10^6
/// 4. max(plants[i]) <= capacityA, capacityB <= 10^9
/// </summary>
int LeetCodeTwoPointer::minimumRefill(vector<int>& plants, int capacityA, int capacityB)
{
    int barrelA = capacityA;
    int barrelB = capacityB;
    int first = 0; 
    int last = plants.size() - 1;
    int result = 0;
    while (first <= last)
    {
        if (first == last)
        {
            if (barrelA < plants[first] && barrelB < plants[first])
            {
                result++;
            }
            break;
        }
        if (barrelA < plants[first])
        {
            barrelA = capacityA;
            result++;
        }
        if (barrelB < plants[last])
        {
            barrelB = capacityB;
            result++;
        }
        barrelA -= plants[first];
        barrelB -= plants[last];
        first++;
        last--;
    }
    return result;
}


/// <summary>
/// Leet Code 2302. Count Subarrays With Score Less Than K
///                                                           
/// Hard
/// 
/// The score of an array is defined as the product of its sum and its 
/// length.
///
/// For example, the score of [1, 2, 3, 4, 5] is 
/// (1 + 2 + 3 + 4 + 5) * 5 = 75.
/// Given a positive integer array nums and an integer k, return the 
/// number of non-empty subarrays of nums whose score is strictly less 
/// than k.
///
/// A subarray is a contiguous sequence of elements within an array.
///  
/// Example 1:
/// Input: nums = [2,1,4,3,5], k = 10
/// Output: 6
/// Explanation:
/// The 6 subarrays having scores less than 10 are:
/// - [2] with score 2 * 1 = 2.
/// - [1] with score 1 * 1 = 1.
/// - [4] with score 4 * 1 = 4.
/// - [3] with score 3 * 1 = 3. 
/// - [5] with score 5 * 1 = 5.
/// - [2,1] with score (2 + 1) * 2 = 6.
/// Note that subarrays such as [1,4] and [4,3,5] are not considered 
/// because their scores are 10 and 36 respectively, while we need scores 
/// strictly less than 10.
///
/// Example 2:
/// Input: nums = [1,1,1], k = 5
/// Output: 5
/// Explanation:
/// Every subarray except [1,1,1] has a score less than 5.
/// [1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
/// Thus, there are 5 subarrays having scores less than 5.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^5
/// 3. 1 <= k <= 10^15
/// </summary>
long long LeetCodeTwoPointer::countSubarrays(vector<int>& nums, long long k)
{
    long long sum = 0;
    long long result = 0;
    deque<int> deque;
    for (size_t i = 0; i <= nums.size(); i++)
    {
        while (sum * (long long)deque.size() >= k)
        {
            sum -= (long long)deque.front();
            deque.pop_front();
        }
        result += (long long)deque.size();
        if (i < nums.size())
        {
            deque.push_back(nums[i]);
            sum += (long long)nums[i];
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2327. Number of People Aware of a Secret
///                                                           
/// Medium
///
/// On day 1, one person discovers a secret.
///
/// You are given an integer delay, which means that each person will 
/// share the secret with a new person every day, starting from delay 
/// days after discovering the secret. You are also given an integer 
/// forget, which means that each person will forget the secret forget 
/// days after discovering it. A person cannot share the secret on the 
/// same day they forgot it, or on any day afterwards.
///
/// Given an integer n, return the number of people who know the secret 
/// at the end of day n. Since the answer may be very large, return it 
/// modulo 10^9 + 7.
///
/// Example 1:
/// Input: n = 6, delay = 2, forget = 4
/// Output: 5
/// Explanation:
/// Day 1: Suppose the first person is named A. (1 person)
/// Day 2: A is the only person who knows the secret. (1 person)
/// Day 3: A shares the secret with a new person, B. (2 people)
/// Day 4: A shares the secret with a new person, C. (3 people)
/// Day 5: A forgets the secret, and B shares the secret with a new 
///        person, D. (3 people)
/// Day 6: B shares the secret with E, and C shares the secret with 
///        F. (5 people)
///
/// Example 2:
/// Input: n = 4, delay = 1, forget = 3
/// Output: 6
/// Explanation:
/// Day 1: The first person is named A. (1 person)
/// Day 2: A shares the secret with B. (2 people)
/// Day 3: A and B share the secret with 2 new people, C and D. (4 people)
/// Day 4: A forgets the secret. B, C, and D share the secret with 3 new 
///        people. (6 people)
///
/// Constraints:
/// 1. 2 <= n <= 1000
/// 2. 1 <= delay < forget <= n
/// </summary>
int LeetCodeTwoPointer::peopleAwareOfSecret(int n, int delay, int forget)
{
    int M = 1000000007;
    int share = 0, result = 0;
    vector<int> dp(n);
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            share = 0;
            dp[0] = 1;
        }
        else
        {
            if (right + delay == i)
            {
                share = (share + dp[right]) % M;
                right++;
            }
            if (left + forget == i)
            {
                share = (share - dp[left] + M) % M;
                result = (result - dp[left] + M) % M;
                left++;
            }
            dp[i] = share;
        }
        result = (result + dp[i]) % M;
    }
    return result;
}

/// <summary>
/// Leet Code 2330. Valid Palindrome IV
///                                                           
/// Medium
///
/// You are given a 0-indexed string s consisting of only lowercase 
/// English letters. In one operation, you can change any character 
/// of s to any other character.
///
/// Return true if you can make s a palindrome after performing 
/// exactly one or two operations, or return false otherwise.
///
/// Example 1:
/// Input: s = "abcdba"
/// Output: true
/// Explanation: One way to make s a palindrome using 1 operation is:
/// - Change s[2] to 'd'. Now, s = "abddba".
/// One operation could be performed to make s a palindrome so return true.
/// 
/// Example 2:
/// Input: s = "aa"
/// Output: true
/// Explanation: One way to make s a palindrome using 2 operations is:
/// - Change s[0] to 'b'. Now, s = "ba".
/// - Change s[1] to 'b'. Now, s = "bb".
/// Two operations could be performed to make s a palindrome so return 
/// true.
///
/// Example 3:
///
/// Input: s = "abcdef"
/// Output: false
/// Explanation: It is not possible to make s a palindrome using one 
/// or two operations so return false.
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists only of lowercase English letters.
/// </summary>
bool LeetCodeTwoPointer::makePalindrome(string s)
{
    int left = 0, right = s.size() - 1;
    int count = 0;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            count++;
            if (count > 2) return false;
        }
        left++;
        right--;
    }
    return true;
}

/// <summary>
/// Leet Code 2379. Minimum Recolors to Get K Consecutive Black Blocks
///                                                           
/// Easy
///
/// You are given a 0-indexed string blocks of length n, where blocks[i] 
/// is either 'W' or 'B', representing the color of the ith block. The 
/// characters 'W' and 'B' denote the colors white and black, respectively.
/// You are also given an integer k, which is the desired number of 
/// consecutive black blocks.
/// In one operation, you can recolor a white block such that it becomes a 
/// black block.
///
/// Return the minimum number of operations needed such that there is at 
/// least one occurrence of k consecutive black blocks.
///
/// Example 1:
/// Input: blocks = "WBBWWBBWBW", k = 7
/// Output: 3
/// Explanation:
/// One way to achieve 7 consecutive black blocks is to recolor the 0th, 
/// 3rd, and 4th blocks
/// so that blocks = "BBBBBBBWBW". 
/// It can be shown that there is no way to achieve 7 consecutive black 
/// blocks in less than 3 operations.
/// Therefore, we return 3.
///
/// Example 2:
/// Input: blocks = "WBWBBBW", k = 2
/// Output: 0
/// Explanation:
/// No changes need to be made, since 2 consecutive black blocks 
/// already exist.
/// Therefore, we return 0.
/// 
/// Constraints:
/// 1. n == blocks.length
/// 2. 1 <= n <= 100
/// 3. blocks[i] is either 'W' or 'B'.
/// 4. 1 <= k <= n
/// </summary>
int LeetCodeTwoPointer::minimumRecolors(string blocks, int k)
{
    int count = 0;
    size_t prev = -1;
    int result = k;
    for (size_t i = 0; i < blocks.size(); i++)
    {
        if (blocks[i] == 'B') count++;
        if (i - prev > k)
        {
            prev++;
            if (blocks[prev] == 'B') count--;
        }
        if (i - prev == k)
        {
            result = min(result, k - count);
        }
    }
    return result;
}
#pragma endregion
