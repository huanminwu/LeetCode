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
#include "LeetcodeHashtable.h"
#pragma region HashTable


/// <summary>
/// Leet code #128. Longest Consecutive Sequence 
/// Given an unsorted array of integers, find the length of the longest 
/// consecutive elements sequence.
/// For example,
///   Given [100, 4, 200, 1, 3, 2],
///   The longest consecutive elements sequence is [1, 2, 3, 4]. 
///   Return its length: 4. 
/// Your algorithm should run in O(n) complexity. 
/// </summary>
int LeetCodeHashtable::longestConsecutive(vector<int>& nums)
{
    unordered_set<int> set;
    int max_length = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        set.insert(nums[i]);
    }

    while (!set.empty())
    {
        int length = 1;
        int number = *set.begin();
        set.erase(number);
        int index = -1;
        while (set.find(number + index) != set.end())
        {
            set.erase(number + index);
            length++;
            index--;
        }
        index = 1;
        while (set.find(number + index) != set.end())
        {
            set.erase(number + index);
            length++;
            index++;
        }
        max_length = max(max_length, length);
    }
    return max_length;
}

/// <summary>
/// Leet code #166. Fraction to Recurring Decimal
/// Given two integers representing the numerator and denominator of a 
/// fraction, return the fraction in string format.
/// If the fractional part is repeating, enclose the repeating part in 
/// parentheses.
/// For example,
/// Given numerator = 1, denominator = 2, return "0.5".	
/// Given numerator = 2, denominator = 1, return "2".
/// Given numerator = 2, denominator = 3, return "0.(6)"
/// Hint:
/// 1.No scary math, just apply elementary math knowledge. Still remember 
///   how to perform a long division?
/// 2.Try a long division on 4/9, the repeating part is obvious. Now try 
///   4/333. Do you see a pattern?
/// 3.Be wary of edge cases! List out as many test cases as you can think 
///   of and test your code thoroughly.
/// </summary>
string LeetCodeHashtable::fractionToDecimal(int numerator, int denominator)
{
    string result;
    vector<long long> decimals;
    unordered_map<long long, int> map;
    if (denominator == 0) return "overflow";
    if (numerator == 0) return "0";
    bool numerator_greater_zero = numerator > 0;
    bool denominator_grater_zero = denominator > 0;
    int sign = (numerator_greater_zero ^ denominator_grater_zero) ? -1 : 1;
    if (sign < 0) result = "-";
    long long long_numerator = abs((long long)numerator);
    long long long_denominator = abs((long long)denominator);

    long long dividend = long_numerator / long_denominator;
    long long reminder = long_numerator % long_denominator;
    result.append(to_string(dividend));
    if (reminder != 0) result.append(".");
    int pos = 0;
    int repeat_pos = -1;
    while (reminder != 0)
    {
        if (map.find(reminder) != map.end())
        {
            repeat_pos = map[reminder];
            break;
        }
        else
        {
            map[reminder] = pos;
        }
        reminder = reminder * 10;
        dividend = reminder / long_denominator;
        decimals.push_back(dividend);
        reminder = reminder %  long_denominator;
        pos++;
    }
    for (size_t i = 0; i < decimals.size(); i++)
    {
        if (i == repeat_pos)
        {
            result.append("(");
        }
        result.append(to_string(decimals[i]));
    }
    if (repeat_pos != -1) result.append(")");

    return result;
}

/// <summary>
/// Leet code #202. Happy Number   
/// Write an algorithm to determine if a number is "happy".
/// A happy number is a number defined by the following process: 
/// Starting with any positive integer,
/// replace the number by the sum of the squares of its digits, and 
/// repeat the process until the number
/// equals 1 (where it will stay), or it loops endlessly in a cycle 
/// which does not include 1. 
/// Those numbers for which this process ends in 1 are happy numbers.
/// Example: 19 is a happy number
/// 1^2 + 9^2 = 82
/// 8^2 + 2^2 = 68
/// 6^2 + 8^2 = 100
/// 1^2 + 0^2 + 0^2 = 1
/// </summary>
bool LeetCodeHashtable::isHappy(int n)
{
    unordered_set<int> data_set;
    while (true)
    {
        data_set.insert(n);
        int sum = 0;
        while (n != 0)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        n = sum;
        if ((n == 1) || (data_set.find(n) != data_set.end()))
        {
            break;
        }
    }
    if (n == 1) return true;
    else return false;
}

/// <summary>
/// Leet code #217. Contains Duplicate
/// Given an array of integers, find if the array contains any duplicates. Your function should return true 
/// if any value appears at least twice in the array, and it should return false if every element is distinct.	
/// </summary>
bool LeetCodeHashtable::containsDuplicate(vector<int>& nums)
{
    unordered_set<int> data_set;
    for (int x : nums)
    {
        if (data_set.find(x) == data_set.end())
        {
            data_set.insert(x);
        }
        else
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #299. Bulls and Cows      
/// You are playing the following Bulls and Cows game with your friend: You write down a number and ask your 
/// friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates 
/// how many digits in said guess match your secret number exactly in both digit and position (called "bulls") 
/// and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend 
/// will use successive guesses and hints to eventually derive the secret number.	
/// For example: 
/// Secret number:  "1807"
/// Friend's guess: "7810"
/// Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.) 
/// Write a function to return a hint according to the secret number and friend's guess, use A to indicate 
/// the bulls and B to indicate the cows. In the above example, your function should return "1A3B". 
/// Please note that both secret number and friend's guess may contain duplicate digits, for example: 
/// Secret number:  "1123"
/// Friend's guess: "0111"
/// In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B". 
/// You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
/// </summary>
string LeetCodeHashtable::getHint(string secret, string guess)
{
    string result;
    unordered_map<char, int> secret_map;
    int bull = 0;
    int cow = 0;
    for (size_t i = 0; i < secret.size(); i++)
    {
        if (secret[i] == guess[i])
        {
            bull++;
        }
        else
        {
            secret_map[secret[i]]++;
        }
    }
    for (size_t i = 0; i < guess.size(); i++)
    {
        if (secret[i] != guess[i])
        {
            if (secret_map.find(guess[i]) != secret_map.end())
            {
                secret_map[guess[i]]--;
                cow++;
                if (secret_map[guess[i]] == 0) secret_map.erase(guess[i]);
            }
        }
    }
    result.append(to_string(bull) + "A" + to_string(cow) + "B");
    return result;
}

/// <summary>
/// Leet code #349. Intersection of Two Arrays      
/// Example:
/// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2]. 
/// Note:
/// Each element in the result must be unique.
/// The result can be in any order.	
/// </summary>
vector<int> LeetCodeHashtable::intersectionArray(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> data_set;
    unordered_set<int> intersection;
    vector<int> result;
    for (size_t i = 0; i < nums1.size(); i++)
    {
        data_set.insert(nums1[i]);
    }
    for (size_t i = 0; i < nums2.size(); i++)
    {
        if (data_set.find(nums2[i]) != data_set.end())
        {
            intersection.insert(nums2[i]);
        }
    }
    for (int i : intersection)
    {
        result.push_back(i);
    }
    return result;
}

/// <summary>
/// Leet code #350. Intersection of Two Arrays II 
/// Given two arrays, write a function to compute their intersection. 	
/// Example:
/// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2]. 
/// Note:
/// Each element in the result should appear as many times as it shows in both arrays.
/// The result can be in any order.
///	Follow up:
/// What if the given array is already sorted? How would you optimize your algorithm?
/// What if nums1's size is small compared to nums2's size? Which algorithm is better?
/// What if elements of nums2 are stored on disk, and the memory is limited such that 
/// you cannot load all elements into the memory at once?
/// </summary>
vector<int> LeetCodeHashtable::intersectionArrayII(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> result;
    size_t index1 = 0, index2 = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while ((index1 < nums1.size()) && (index2 < nums2.size()))
    {
        if (nums1[index1] < nums2[index2])
        {
            index1++;
        }
        else if (nums1[index1] > nums2[index2])
        {
            index2++;
        }
        else
        {
            result.push_back(nums1[index1]);
            index1++; index2++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #219. Contains Duplicate II
/// Given an array of integers and an integer k, find out whether there are 
/// two distinct indices i and j in the array such that nums[i] = nums[j] 
/// and the difference between i and j is at most k.	
/// </summary>
bool LeetCodeHashtable::containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_map<int, int> pos_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (pos_map.find(nums[i]) != pos_map.end())
        {
            if ((int)(i - pos_map[nums[i]]) <= k) return true;
        }
        pos_map[nums[i]] = i;
    }
    return false;
}

/// <summary>
/// Leet code #205. Isomorphic Strings
///
/// Given two strings s and t, determine if they are isomorphic. 
/// Two strings are isomorphic if the characters in s can be replaced to 
/// get t.
/// All occurrences of a character must be replaced with another character 
/// while preserving the order of characters. No two characters may map to 
/// the same character but a character may map to itself.
/// For example,
/// Given "egg", "add", return true.
///
/// Given "foo", "bar", return false.
/// Given "paper", "title", return true.
/// Note:
/// You may assume both s and t have the same length.
/// </summary>
bool LeetCodeHashtable::isIsomorphic(string s, string t)
{
    unordered_map<char, char> src_map, dst_map;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (src_map.count(s[i]) == 0 && dst_map.count(t[i]) == 0)
        {
            src_map[s[i]] = t[i];
            dst_map[t[i]] = s[i];
        }
        else if (src_map[s[i]] != t[i] || dst_map[t[i]] != s[i])
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #242. Valid Anagram 
///
/// Given two strings s and t, write a function to determine if t is an 
/// anagram of s.
/// For example,  
/// s = "anagram", t = "nagaram", return true.
/// s = "rat", t = "car", return false.
/// Note:
///   You may assume the string contains only lowercase alphabets.
/// Follow up:
///   What if the inputs contain unicode characters? How would you adapt 
///   your solution to such case? 
/// </summary>
bool LeetCodeHashtable::isAnagram(string s, string t)
{
    if (s.size() != t.size()) return false;
    unordered_map<char, int> map;
    for (size_t i = 0; i < s.size(); i++)
    {
        map[s[i]]++;
    }
    for (size_t i = 0; i < t.size(); i++)
    {
        map[t[i]]--;
        if (map[t[i]] == 0) map.erase(t[i]);
    }
    if (map.size() == 0) return true;
    else return false;
}

/// <summary>
/// Leet code #347. Top K Frequent Elements
/// Given a non-empty array of integers, return the k most frequent elements.
/// For example,
/// Given [1,1,1,2,2,3] and k = 2, return [1,2]. 
/// Note: 
/// You may assume k is always valid, 1 <= k <= number of unique elements.
/// Your algorithm's time complexity must be better than O(n log n), 
/// where n is the array's size.
/// </summary>
vector<int> LeetCodeHashtable::topKFrequent(vector<int>& nums, int k)
{
    vector<int> result;
    unordered_map<int, int> num_count;
    for (int num : nums)  num_count[num]++;
    set<pair<int, int>> pq;
    for (auto itr : num_count)
    {
        pair<int, int> pair = make_pair(itr.second, itr.first);
        pq.insert(pair);
        if (pq.size() > (size_t)k) pq.erase(pq.begin());
    }
    while (!pq.empty())
    {
        result.push_back(pq.begin()->second);
        pq.erase(pq.begin());
    }
    return result;
}

/// <summary>
/// Leet code #451. Sort Characters By Frequency 
/// Given a string, sort it in decreasing order based on the frequency of characters.
/// Example 1: 
/// Input:
/// "tree"
///
/// Output:
/// "eert"
///
/// Explanation:
/// 'e' appears twice while 'r' and 't' both appear once.
/// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
///
/// Example 2: 
/// Input:
/// "cccaaa"
///
/// Output:
/// "cccaaa"
///
/// Explanation:
/// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
/// Note that "cacaca" is incorrect, as the same characters must be together.
///
/// Example 3: 
/// Input:
/// "Aabb" 
/// Output:
/// "bbAa"
///
/// Explanation:
/// "bbaA" is also a valid answer, but "Aabb" is incorrect.
/// Note that 'A' and 'a' are treated as two different characters.
/// </summary>
string LeetCodeHashtable::frequencySort(string s)
{
    string result;
    unordered_map<char, size_t> char_map;
    map<size_t, vector<char>> count_map;
    for (size_t i = 0; i < s.size(); i++)
    {
        char_map[s[i]]++;
    }
    for (unordered_map<char, size_t>::iterator itr = char_map.begin(); itr != char_map.end(); itr++)
    {
        count_map[itr->second].push_back(itr->first);
    }
    for (map<size_t, vector<char>>::reverse_iterator itr = count_map.rbegin(); itr != count_map.rend(); itr++)
    {
        for (char ch : itr->second)
        {
            result.append(string(itr->first, ch));
        }
    }
    return result;
}

/// <summary>
/// Leet code #500. Keyboard Row         
/// 
/// Given a List of words, return the words that can be typed using letters of alphabet 
/// on only one row's of American keyboard like the image below. 
/// The keyboard layout is as below:
/// QWERTYUIOP
/// ASDFGHJKL
/// ZXCVBNM
/// Example 1:
/// Input: ["Hello", "Alaska", "Dad", "Peace"]
/// Output: ["Alaska", "Dad"]
/// Note:
/// 1.You may use one character in the keyboard more than once.
/// 2.You may assume the input string will only contain letters of alphabet.
/// </summary>
vector<string> LeetCodeHashtable::findWordsInOneRow(vector<string>& words)
{
    vector<string> result;
    vector<string> keyboard = { "QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM" };
    unordered_map<char, int> key_map;
    for (size_t i = 0; i < keyboard.size(); i++)
    {
        for (size_t j = 0; j < keyboard[i].size(); j++)
        {
            key_map[keyboard[i][j]] = i + 1;
        }
    }
    for (size_t i = 0; i < words.size(); i++)
    {
        unordered_set<int> key_rows;
        for (size_t j = 0; j < words[i].size(); j++)
        {
            key_rows.insert(key_map[toupper(words[i][j])]);
            if (key_rows.size() > 1) break;
        }
        if (key_rows.size() == 1)
        {
            result.push_back(words[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #506. Relative Ranks         
/// 
/// Given scores of N athletes, find their relative ranks and the people with the top three highest 
/// scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
///
/// Example 1:
///
/// Input: [5, 4, 3, 2, 1]
/// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
/// Explanation: The first three athletes got the top three highest scores, so 
/// they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
/// For the left two athletes, you just need to output their relative ranks according to their scores.
///
/// Note:
/// 1.N is a positive integer and won't exceed 10,000.
/// 2.All the scores of athletes are guaranteed to be unique.    
/// </summary>
vector<string> LeetCodeHashtable::findRelativeRanks(vector<int>& nums)
{
    map<int, int> score_map;
    vector<string> result(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        score_map[nums[i]] = i;
    }
    int rank = 0;
    int count = 0;
    int last_value;
    for (map<int, int>::reverse_iterator itr = score_map.rbegin(); itr != score_map.rend(); ++itr)
    {
        count++;
        if ((rank == 0) || (last_value != itr->first))
        {
            rank = count;
        }
        if (rank == 1)
        {
            result[itr->second] = "Gold Medal";
        }
        else if (rank == 2)
        {
            result[itr->second] = "Silver Medal";
        }
        else if (rank == 3)
        {
            result[itr->second] = "Bronze Medal";
        }
        else
        {
            result[itr->second] = to_string(rank);
        }
        last_value = itr->first;
    }
    return result;
}

/// <summary>
/// Leet code #532. K-diff Pairs in an Array    
/// 
/// Given an array of integers and an integer k, you need to find the number 
/// of unique k-diff pairs in the array. Here a k-diff pair is defined as an 
/// integer pair (i, j), where i and j are both numbers in the array and their 
/// absolute difference is k.
///
/// Example 1:
/// Input: [3, 1, 4, 1, 5], k = 2
/// Output: 2
/// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
/// Although we have two 1s in the input, we should only return the number of 
/// unique pairs.
/// Example 2:
/// Input:[1, 2, 3, 4, 5], k = 1
/// Output: 4
/// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), 
/// (3, 4) and (4, 5).
/// Example 3:
/// Input: [1, 3, 1, 5, 4], k = 0
/// Output: 1
/// Explanation: There is one 0-diff pair in the array, (1, 1).
/// Note:
/// The pairs (i, j) and (j, i) count as the same pair.
/// The length of the array won't exceed 10,000.
/// All the integers in the given input belong to the range: [-1e7, 1e7].
/// </summary>
int LeetCodeHashtable::findPairs(vector<int>& nums, int k)
{
    if (k < 0) return 0;
    int count = 0;
    unordered_map<int, int> num_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_map[nums[i]]++;
    }

    for (auto itr : num_map)
    {
        if (k == 0)
        {
            if (itr.second > 1) count++;
        }
        else
        {
            if (num_map.count(itr.first + k) > 0) count++;
        }
    }
    return count;
}

/// <summary>
/// Leet code #594. Longest Harmonious Subsequence
/// We define a harmonious array is an array where the difference between 
/// its maximum value and its minimum value is exactly 1.
/// Now, given an integer array, you need to find the length of its 
/// longest harmonious subsequence among all its possible subsequences.
///
/// Example 1:
/// Input: [1,3,2,2,5,2,3,7]
/// Output: 5
/// Explanation: The longest harmonious subsequence is [3,2,2,2,3].
/// Note: The length of the input array will not exceed 20,000.
/// </summary>
int LeetCodeHashtable::findLHS(vector<int>& nums)
{
    unordered_map<int, int> num_count;
    for (int num : nums) num_count[num]++;
    int max_length = 0;
    for (auto itr : num_count)
    {
        if (num_count.count(itr.first + 1) > 0)
        {
            max_length = max(max_length, num_count[itr.first] + num_count[itr.first + 1]);
        }
    }
    return max_length;
}

/// <summary>
/// Leet code #599. Minimum Index Sum of Two Lists   
/// 
/// Suppose Andy and Doris want to choose a restaurant for dinner, and 
/// they both have a list of favorite restaurants represented by strings. 
/// You need to help them find out their common interest with the least 
/// list index sum. If there is a choice tie between answers, output all 
/// of them with no order requirement. You could assume there always 
/// exists an answer. 
/// Example 1:
/// Input:
/// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
/// ["Piatti", "The Grill at Torrey Pines", "Hungry Steakhouse", "Shogun"]
/// Output: ["Shogun"]
/// Explanation: The only restaurant they both like is "Shogun".
///
/// Example 2:
/// Input:
/// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
/// ["KFC", "Shogun", "Burger King"]
/// Output: ["Shogun"]
/// Explanation: The restaurant they both like and have the least index 
/// sum is "Shogun" with index sum 1 (0+1).
///
/// Note:
/// The length of both lists will be in the range of [1, 1000].
/// The length of strings in both lists will be in the range of [1, 30].
/// The index is starting from 0 to the list length minus 1.
/// No duplicates in both lists.
/// </summary>
vector<string> LeetCodeHashtable::findRestaurant(vector<string>& list1, vector<string>& list2)
{
    map<string, pair<int, int>> index_map;
    map<int, vector<string>>  index_sum;
    for (size_t i = 0; i < list1.size(); i++)
    {
        index_map[list1[i]] = make_pair(i, -1);
    }

    for (size_t i = 0; i < list2.size(); i++)
    {
        if (index_map.count(list2[i]) != 0)
        {
            string str = list2[i];
            index_map[str].second = i;
            index_sum[index_map[str].first + index_map[str].second].push_back(str);
        }
    }
    return index_sum.begin()->second;
}

/// <summary>
/// Leet code #721. Accounts Merge
/// </summary>
bool LeetCodeHashtable::checkCommonEmail(set<string>& emails, vector<string>& account)
{
    for (size_t i = 1; i < account.size(); i++)
    {
        if (emails.count(account[i]) > 0)
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #721. Accounts Merge
/// </summary>
void LeetCodeHashtable::addNewAccount(unordered_map<string, set<int>> &account_map, vector<set<string>> &account_emails,
    vector<string>& account)
{
    set<string> emails;
    for (size_t i = 1; i < account.size(); i++)
    {
        emails.insert(account[i]);
    }
    account_emails.push_back(emails);
    account_map[account[0]].insert(account_emails.size() - 1);
}

/// <summary>
/// Leet code #721. Accounts Merge
/// </summary>
void LeetCodeHashtable::mergeAccount(unordered_map<string, set<int>> &account_map, vector<set<string>> &account_emails, vector<int>& merge_list,
    vector<string>& account)
{
    if (merge_list.empty()) return;
    string name = account[0];
    int index = merge_list[0];
    for (size_t next = 1; next < merge_list.size(); next++)
    {
        account_map[name].erase(merge_list[next]);
        for (auto email : account_emails[merge_list[next]])
        {
            account_emails[index].insert(email);
        }
    }
    for (size_t i = 1; i < account.size(); i++)
    {
        account_emails[index].insert(account[i]);
    }
}

/// <summary>
/// Leet code #721. Accounts Merge
///
/// Given a list accounts, each element accounts[i] is a list of strings,
/// where the first element accounts[i][0] is a name, and the rest of the 
/// elements are emails representing emails of the account.
///
/// Now, we would like to merge these accounts. Two accounts definitely 
/// belong to the same person if there is some email that is common to 
/// both accounts. Note that even if two accounts have the same name, they 
/// may belong to different people as people could have the same name. A 
/// person can have any number of accounts initially, but all of their 
/// accounts definitely have the same name.
///
/// After merging the accounts, return the accounts in the following 
/// format: the first element of each account is the name, and the rest of 
/// the elements are emails in sorted order. The accounts themselves can be
/// returned in any order.
///
/// Example 1:
/// Input: 
/// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", 
/// "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", 
/// "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
/// Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 
/// 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", 
/// "mary@mail.com"]]
/// Explanation: 
/// The first and third John's are the same person as they have the common 
/// email "johnsmith@mail.com".
/// The second John and Mary are different people as none of their email 
/// addresses are used by other accounts.
/// We could return these lists in any order, for example the answer 
/// [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
/// ['John', 'john00@mail.com', 'john_newyork@mail.com', 
/// 'johnsmith@mail.com']] would still be accepted.
/// Note:
///
/// The length of accounts will be in the range [1, 1000].
/// The length of accounts[i] will be in the range [1, 10].
/// The length of accounts[i][j] will be in the range [1, 30].
/// </summary>
vector<vector<string>> LeetCodeHashtable::accountsMerge(vector<vector<string>>& accounts)
{
    vector<vector<string>> result;
    unordered_map<string, set<int>> account_map;
    vector<set<string>> account_emails;
    for (size_t i = 0; i < accounts.size(); i++)
    {
        string name = accounts[i][0];
        if (account_map.count(name) == 0)
        {
            addNewAccount(account_map, account_emails, accounts[i]);
        }
        else
        {
            vector<int> merge_list;
            for (int index : account_map[name])
            {
                if (checkCommonEmail(account_emails[index], accounts[i]))
                {
                    merge_list.push_back(index);
                }
            }
            if (merge_list.empty())
            {
                addNewAccount(account_map, account_emails, accounts[i]);
            }
            else
            {
                mergeAccount(account_map, account_emails, merge_list, accounts[i]);
            }
        }
    }

    // fetch all the result
    for (auto itr : account_map)
    {
        for (auto email_id : itr.second)
        {
            vector<string> account;
            account.push_back(itr.first);
            for (auto email : account_emails[email_id])
            {
                account.push_back(email);
            }
            result.push_back(account);
        }

    }
    return result;
}

/// <summary>
/// Leet code #734. Sentence Similarity
///
/// Given two sentences words1, words2 (each represented as an array of 
/// strings), and a list of similar word pairs pairs, determine if two 
/// sentences are similar.
/// 
/// For example, "great acting skills" and "fine drama talent" are similar, 
/// if the similar word pairs are pairs = [["great", "fine"], 
/// ["acting","drama"], ["skills","talent"]].
/// Note that the similarity relation is not transitive. For example, if 
/// "great" and "fine" are similar, and "fine" and "good" are similar, 
/// "great" and "good" are not necessarily similar.
/// However, similarity is symmetric. For example, "great" and "fine" 
/// being similar is the same as "fine" and "great" being similar.
///
/// Also, a word is always similar with itself. For example, the sentences 
/// words1 = ["great"], words2 = ["great"], pairs = [] are similar, even 
/// though there are no specified similar word pairs.
///
/// Finally, sentences can only be similar if they have the same number 
/// of words. So a sentence like words1 = ["great"] can never be similar 
/// to words2 = ["doubleplus","good"].
///
/// Note:
///
/// The length of words1 and words2 will not exceed 1000.
/// The length of pairs will not exceed 2000.
/// The length of each pairs[i] will be 2.
/// The length of each words[i] and pairs[i][j] will be in the range 
/// [1, 20].
/// </summary>
bool LeetCodeHashtable::areSentencesSimilar(vector<string>& words1, vector<string>& words2,
    vector<pair<string, string>> pairs)
{
    if (words1.size() != words2.size()) return false;
    unordered_map<string, unordered_set<string>> similar_words;
    for (auto itr : pairs)
    {
        similar_words[itr.first].insert(itr.second);
        similar_words[itr.second].insert(itr.first);
    }

    for (size_t i = 0; i < words1.size(); i++)
    {
        if ((words1[i] != words2[i]) && (similar_words[words1[i]].count(words2[i]) == 0))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #748. Shortest Completing Word
///
/// Find the minimum length word from a given dictionary words, which has 
/// all the letters from the string licensePlate. Such a word is said to 
/// complete the given string licensePlate
///
/// Here, for letters we ignore case. For example, "P" on the licensePlate 
/// still matches "p" on the word.
///
/// It is guaranteed an answer exists. If there are multiple answers, 
/// return the one that occurs first in the array.
///
/// The license plate might have the same letter occurring multiple times. 
/// For example, given a licensePlate of "PP", the word "pair" does not 
/// complete the licensePlate, but the word "supper" does.
///
/// Example 1:
/// Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", 
/// "stepple"]
/// Output: "steps"
/// Explanation: The smallest length word that contains the letters "S", 
/// "P", "S", and "T".
/// Note that the answer is not "step", because the letter "s" must occur 
/// in the word twice.
/// Also note that we ignored case for the purposes of comparing whether 
/// a letter exists in the word.
/// Example 2:
/// Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", 
/// "show"]
/// Output: "pest"
/// Explanation: There are 3 smallest length words that contains the 
/// letters "s".
/// We return the one that occurred first.
/// Note:
/// 1.licensePlate will be a string with length in range [1, 7].
/// 2. licensePlate will contain digits, spaces, or letters (uppercase or 
///    lowercase).
/// 3. words will have a length in the range [10, 1000].
/// 4. Every words[i] will consist of lowercase letters, and have length 
///    in range [1, 15].
/// </summary>
string LeetCodeHashtable::shortestCompletingWord(string licensePlate, vector<string>& words)
{
    string result;
    unordered_map<char, int> license_map;
    for (char ch : licensePlate)
    {
        ch = tolower(ch);
        if (ch >= 'a' && ch <= 'z') license_map[ch]++;
    }
    for (string word : words)
    {
        unordered_map<char, int> word_map;
        for (char ch : word)
        {
            word_map[ch]++;
        }
        bool satisfy = true;
        for (auto itr : license_map)
        {
            if (word_map[itr.first] < itr.second)
            {
                satisfy = false;
                break;
            }
        }
        if ((satisfy) && (result.empty() || result.size() > word.size()))
        {
            result = word;
        }
    }
    return result;
}

/// <summary>
/// Leet code #760. Find Anagram Mappings    
///
/// Given two lists A and B, and B is an anagram of A. B is an anagram of A 
/// means B is made by randomizing the order of the elements in A.
///
/// We want to find an index mapping P, from A to B. A mapping P[i] = j means 
/// the ith element in A appears in B at index j.
///
/// These lists A and B may contain duplicates. If there are multiple answers, 
/// output any of them.
///
/// For example, given
///
/// A = [12, 28, 46, 32, 50]
/// B = [50, 12, 32, 46, 28]
/// We should return
/// [1, 4, 3, 2, 0]
/// as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 
/// because the 1st element of A appears at B[4], and so on.
/// Note:
///
/// 1. A, B have equal lengths in range [1, 100].
/// 2. A[i], B[i] are integers in range [0, 10^5].
/// </summary>
vector<int> LeetCodeHashtable::anagramMappings(vector<int>& A, vector<int>& B)
{
    vector<int> result;
    unordered_map<int, queue<int>> anagram_mappings;
    for (size_t i = 0; i < B.size(); i++)
    {
        anagram_mappings[B[i]].push(i);
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        result.push_back(anagram_mappings[A[i]].front());
        anagram_mappings[A[i]].pop();
    }
    return result;
}

/// <summary>
/// Leet code #792. Number of Matching Subsequences
///
/// Given string S and a dictionary of words words, find the number of 
/// words[i] that is a subsequence of S.
///
/// Example :
/// Input: 
/// S = "abcde"
/// words = ["a", "bb", "acd", "ace"]
/// Output: 3
/// Explanation: There are three words in words that are a subsequence 
/// of S: "a", "acd", "ace".
/// Note:
///
/// 1. All words in words and S will only consists of lowercase letters.
/// 2. The length of S will be in the range of [1, 50000].
/// 3. The length of words will be in the range of [1, 5000].
/// 4. The length of words[i] will be in the range of [1, 50].
/// </summary>
int LeetCodeHashtable::numMatchingSubseq(string S, vector<string>& words)
{
    vector<queue<pair<int, int>>> word_pos(26);
    for (size_t i = 0; i < words.size(); i++)
    {
        int index = words[i][0] - 'a';
        word_pos[index].push(make_pair(i, 0));
    }
    int result = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        int index = S[i] - 'a';
        // use static size avoid new character in same slot.
        size_t size = word_pos[index].size();
        for (size_t j = 0; j < size; j++)
        {
            pair<int, int> pos = word_pos[index].front();
            word_pos[index].pop();
            pos.second++; 
            if (pos.second >= (int)words[pos.first].size())
            {
                result++;
            }
            else
            {
                int next = words[pos.first][pos.second] - 'a';
                word_pos[next].push(pos);
            }
        }
    }

    return result;
}

/// <summary>
/// Leet code #811. Subdomain Visit Count
/// 
/// A website domain like "discuss.leetcode.com" consists of various 
/// subdomains. At the top level, we have "com", at the next level, 
/// we have "leetcode.com", and at the lowest level, 
/// "discuss.leetcode.com". When we visit a domain like 
/// "discuss.leetcode.com", we will also visit the parent domains 
/// "leetcode.com" and "com" implicitly.
/// 
/// Now, call a "count-paired domain" to be a count (representing 
/// the number of visits this domain received), followed by a space, 
/// followed by the address. An example of a count-paired domain might 
/// be "9001 discuss.leetcode.com".
///
/// We are given a list cpdomains of count-paired domains. We would like 
/// a list of count-paired domains, (in the same format as the input, and 
/// in any order), that explicitly counts the number of visits to each 
/// subdomain.
///
/// Example 1:
/// Input: 
/// ["9001 discuss.leetcode.com"]
/// Output: 
/// ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
/// Explanation: 
/// We only have one website domain: "discuss.leetcode.com". As discussed 
/// above, the subdomain "leetcode.com" and "com" will also be visited. So 
/// they will all be visited 9001 times.
///
/// Example 2:
/// Input: 
/// ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", 
/// "5 wiki.org"]
/// Output: 
/// ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org",
///  "5 org","1 intel.mail.com","951 com"]
/// Explanation: 
/// We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, 
/// "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we 
/// will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 
/// times, and "org" 5 times.
/// 
/// Notes:
///
/// 1. The length of cpdomains will not exceed 100. 
/// 2. The length of each domain name will not exceed 100.
/// 3. Each address will have either 1 or 2 "." characters.
/// 4. The input count in any count-paired domain will not exceed 10000.
/// </summary>
vector<string> LeetCodeHashtable::subdomainVisits(vector<string>& cpdomains)
{
    map<string, int> domain_map;
    for (string str : cpdomains)
    {
        int count = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            string domain;
            if (isspace(str[i]))
            {
                count = atoi(str.substr(0, i).c_str());
                domain = str.substr(i + 1);
                domain_map[domain] += count;
            }
            if ((str[i] == '.') && (i < str.size() - 1))
            {
                domain = str.substr(i + 1);
                domain_map[str.substr(i + 1)] += count;
            }
        }
    }

    vector<string> result;
    for (auto itr : domain_map)
    {
        string str = to_string(itr.second) + " " + itr.first;
        result.push_back(str);
    }

    return result;
}

/// <summary>
/// Leet code #884. Uncommon Words from Two Sentences
/// 
/// We are given two sentences A and B.  (A sentence is a string of space 
/// separated words.  Each word consists only of lowercase letters.)
///
/// A word is uncommon if it appears exactly once in one of the sentences, 
/// and does not appear in the other sentence.
///
/// Return a list of all uncommon words. 
///
/// You may return the list in any order.
///
/// Example 1:
///
/// Input: A = "this apple is sweet", B = "this apple is sour"
/// Output: ["sweet","sour"]
/// Example 2:
///
/// Input: A = "apple apple", B = "banana"
/// Output: ["banana"]
/// 
/// Note:
/// 1. 0 <= A.length <= 200
/// 2. 0 <= B.length <= 200
/// 3. A and B both contain only spaces and lowercase letters.
/// </summary>
vector<string> LeetCodeHashtable::uncommonFromSentences(string A, string B)
{
    vector<string> result;
    unordered_map<string, int> word_map;
    string token;
    for (size_t i = 0; i <= A.size(); i++)
    {
        if (i == A.size() || isspace(A[i]))
        {
            if (!token.empty()) word_map[token]++;
            token.clear();
        }
        else
        {
            token.push_back(A[i]);
        }
    }

    for (size_t i = 0; i <= B.size(); i++)
    {
        if (i == B.size() || isspace(B[i]))
        {
            if (!token.empty()) word_map[token]++;
            token.clear();
        }
        else
        {
            token.push_back(B[i]);
        }
    }

    for (auto itr : word_map)
    {
        if (itr.second == 1) result.push_back(itr.first);
    }

    return result;
}

/// <summary>
/// Leet code #890. Find and Replace Pattern
/// 
/// You have a list of words and a pattern, and you want to know which words 
/// in words matches the pattern.
///
/// A word matches the pattern if there exists a permutation of letters p so 
/// that after replacing every letter x in the pattern with p(x), we get the 
/// desired word.
///
/// (Recall that a permutation of letters is a bijection from letters to 
/// letters: every letter maps to another letter, and no two letters map to 
/// the same letter.)
///
/// Return a list of the words in words that match the given pattern. 
///
/// You may return the answer in any order.
/// 
/// Example 1:
///
/// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
/// Output: ["mee","aqq"]
/// Explanation: "mee" matches the pattern because there is a permutation 
/// {a -> m, b -> e, ...}. 
/// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a 
/// permutation, since a and b map to the same letter.
/// 
/// Note:
/// 1 <= words.length <= 50
/// 1 <= pattern.length = words[i].length <= 20
/// </summary>
vector<string> LeetCodeHashtable::findAndReplacePattern(vector<string>& words, string pattern)
{
    vector<string> result;

    for (size_t i = 0; i < words.size(); i++)
    {
        unordered_map<char, char> char_map;
        unordered_set<char> char_set;
        if (words[i].size() != pattern.size()) continue;
        bool b_match = true;
        for (size_t j = 0; j < pattern.size(); j++)
        {
            if (char_map.count(pattern[j]) == 0)
            {
                if (char_set.count(words[i][j]) == 0)
                {
                    char_map[pattern[j]] = words[i][j];
                    char_set.insert(words[i][j]);
                }
                else // the target character alreay used.
                {
                    b_match = false;
                    break;
                }
            }
            else if (char_map[pattern[j]] != words[i][j])
            {
                b_match = false;
                break;
            }
        }
        if (b_match == true) result.push_back(words[i]);
    }
    return result;
}

/// <summary>
/// Leet code #916. Word Subsets
/// 
/// We are given two arrays A and B of words.  Each word is a string of 
/// lowercase letters.
///
/// Now, say that word b is a subset of word a if every letter in b occurs in 
/// a, including multiplicity.  For example, "wrr" is a subset of "warrior", 
/// but is not a subset of "world".
///
/// Now say a word a from A is universal if for every b in B, b is a subset of 
/// a. 
///
/// Return a list of all universal words in A.  You can return the words in 
/// any order.
///
/// Example 1:
///
/// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
/// Output: ["facebook","google","leetcode"]
///
/// Example 2:
///
/// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
/// Output: ["apple","google","leetcode"]
///
/// Example 3:
///
/// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
/// Output: ["facebook","google"]
///
/// Example 4:
///
/// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
/// Output: ["google","leetcode"]
///
/// Example 5:
///
/// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
/// Output: ["facebook","leetcode"]
/// 
///
/// Note:
///
/// 1. 1 <= A.length, B.length <= 10000
/// 2. 1 <= A[i].length, B[i].length <= 10
/// 3. A[i] and B[i] consist only of lowercase letters.
/// 4. All words in A[i] are unique: there isn't i != j with A[i] == A[j].
/// </summary>
vector<string> LeetCodeHashtable::wordSubsets(vector<string>& A, vector<string>& B)
{
    vector<string> result;
    vector<int> b_count(26);	
    for (size_t i = 0; i < B.size(); i++)
    {
        vector<int> temp(26);
        for (char ch : B[i])
        {
            temp[ch - 'a']++;
        }

        for (size_t j = 0; j < 26; j++)
        {
            b_count[j] = max(b_count[j], temp[j]);
        }
    }

    for (size_t i = 0;  i < A.size(); i++)
    {
        vector<int> a_count(26);
        for (char ch : A[i])
        {
            a_count[ch - 'a']++;
        }

        bool bMatch = true;
        for (size_t j = 0; j < 26; j++)
        {
            if (a_count[j] < b_count[j])
            {
                bMatch = false;
                break;
            }
        }
        if (bMatch) result.push_back(A[i]);
    }
    return result;
}

/// <summary>
/// Leet code #957. Prison Cells After N Days
/// 
/// There are 8 prison cells in a row, and each cell is either occupied or 
/// vacant.
///
/// Each day, whether the cell is occupied or vacant changes according to 
/// the following rules:
///
/// If a cell has two adjacent neighbors that are both occupied or both vacant, 
/// then the cell becomes occupied. Otherwise, it becomes vacant.
/// (Note that because the prison is a row, the first and the last cells in 
/// the row can't have two adjacent neighbors.)
///
/// We describe the current state of the prison in the following way: 
/// cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.
///
/// Given the initial state of the prison, return the state of the prison after 
/// N days (and N such changes described above.)
///
/// Example 1:
///
/// Input: cells = [0,1,0,1,1,0,0,1], N = 7
/// Output: [0,0,1,1,0,0,0,0]
/// Explanation: 
/// The following table summarizes the state of the prison on each day:
/// Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
/// Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
/// Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
/// Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
/// Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
/// Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
/// Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
/// Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
/// 
/// Example 2:
///
/// Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
/// Output: [0,0,1,1,1,1,1,0]
/// 
/// Note:
///
/// 1. cells.length == 8
/// 2. cells[i] is in {0, 1}
/// 3. 1 <= N <= 10^9
/// </summary>
vector<int> LeetCodeHashtable::prisonAfterNDays(vector<int>& cells, int N)
{
    map<vector<int>, int> cell_map;
    unordered_map<int, vector<int>> cell_index;
    vector<int> next = cells;
    for (size_t i = 0; i < (size_t)N; i++)
    {
        cell_map[next] = i;
        cell_index[i] = next;
        vector<int>  curr = next;
        for (size_t j = 0; j < curr.size(); j++)
        {
            if (j == 0 || j == curr.size() - 1) next[j] = 0;
            else if (curr[j - 1] == curr[j + 1]) next[j] = 1;
            else next[j] = 0;
        }
        int index = i + 1;
        if (cell_map.count(next) > 0)
        {
            int base_index = cell_map[next];
            int offset_index = (N - index) % (index - base_index);
            next = cell_index[offset_index + base_index];
            break;
        }
    }
    return next;
}

/// <summary>
/// Leet code #1010. Pairs of Songs With Total Durations Divisible by 60
/// 
/// In a list of songs, the i-th song has a duration of time[i] seconds. 
/// 
/// Return the number of pairs of songs for which their total duration in 
/// seconds is divisible by 60.  Formally, we want the number of indices 
/// i < j with (time[i] + time[j]) % 60 == 0.
///
///
/// Example 1: 
/// Input: [30,20,150,100,40]
/// Output: 3
/// Explanation: Three pairs have a total duration divisible by 60:
/// (time[0] = 30, time[2] = 150): total duration 180
/// (time[1] = 20, time[3] = 100): total duration 120
/// (time[1] = 20, time[4] = 40): total duration 60
///
/// Example 2:
/// Input: [60,60,60]
/// Output: 3
/// Explanation: All three pairs have a total duration of 120, which is 
/// divisible by 60.
/// 
///
/// Note:
///
/// 1. 1 <= time.length <= 60000
/// 2. 1 <= time[i] <= 500
/// </summary>
int LeetCodeHashtable::numPairsDivisibleBy60(vector<int>& time)
{
    vector<int> num_map(61);
    int result = 0;
    for (size_t i = 0; i < time.size(); i++)
    {
        int num = time[i] % 60;
        result += num_map[60 - num];
        if (num == 0) num_map[60]++;
        else num_map[num] ++;
    }
    return result;
}

/// <summary>
/// Leet code #1041. Robot Bounded In Circle
/// 
/// On an infinite plane, a robot initially stands at (0, 0) and faces north.  
/// The robot can receive one of three instructions:
///
/// "G": go straight 1 unit;
/// "L": turn 90 degrees to the left;
/// "R": turn 90 degress to the right.
/// The robot performs the instructions given in order, and repeats them 
/// forever.
///
/// Return true if and only if there exists a circle in the plane such that 
/// the robot never leaves the circle.
/// 
/// Example 1:
///
/// Input: "GGLLGG"
/// Output: true
/// Explanation: 
/// The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to
/// (0,0).
/// When repeating these instructions, the robot remains in the circle of 
/// radius 2 centered at the origin.
///
/// Example 2:
///
/// Input: "GG"
/// Output: false
/// Explanation: 
/// The robot moves north indefinitely.
///
/// Example 3:
///
/// Input: "GL"
/// Output: true
/// Explanation: 
/// The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> 
/// ...
/// 
/// Note:
/// 1. 1 <= instructions.length <= 100
/// 2. instructions[i] is in {'G', 'L', 'R'}
/// </summary>
bool LeetCodeHashtable::isRobotBounded(string instructions)
{
    vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    vector<int> pos = { 0, 0, 0 };
    for (int i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < instructions.size(); j++)
        {
            if (instructions[j] == 'G')
            {
                pos[0] += directions[pos[2]][0];
                pos[1] += directions[pos[2]][1];
            }
            else if (instructions[j] == 'L')
            {
                pos[2] = (pos[2] + 4 - 1)%4;
            }
            else if (instructions[j] == 'R')
            {
                pos[2] = (pos[2] + 1) % 4;
            }
        }
    }
    if (pos[0] == 0 && pos[1] == 0 && pos[2] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #1128. Number of Equivalent Domino Pairs
/// 
/// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to 
/// dominoes[j] = [c, d] if and only if either (a==c and b==d), or 
/// (a==d and b==c) - that is, one domino can be rotated to be equal 
/// to another domino.
///
/// Return the number of pairs (i, j) for which 
/// 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to 
/// dominoes[j].
///
/// Example 1:
/// 
/// Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
/// Output: 1
///
/// Constraints:
/// 1. 1 <= dominoes.length <= 40000
/// 2. 1 <= dominoes[i][j] <= 9
/// </summary>
int LeetCodeHashtable::numEquivDominoPairs(vector<vector<int>>& dominoes)
{
    vector<vector<int>> matrix(9, vector<int>(9));

    for (size_t i = 0; i < dominoes.size(); i++)
    {
        if (dominoes[i][0] < dominoes[i][1])
        {
            matrix[dominoes[i][0] - 1][dominoes[i][1] - 1]++;
        }
        else
        {
            matrix[dominoes[i][1] - 1][dominoes[i][0] - 1]++;
        }
    }
    int result = 0;
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = i; j < 9; j++)
        {
            int n = matrix[i][j];
            result += n * (n - 1) / 2;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1152. Analyze User Website Visit Pattern
/// 
/// You are given three arrays username, timestamp and website of the same 
/// length N where the ith tuple means that the user with name username[i] 
/// visited the website website[i] at time timestamp[i].
/// A 3-sequence is a list of not necessarily different websites of length 
/// 3 sorted in ascending order by the time of their visits.
/// Find the 3-sequence visited at least once by the largest number of 
/// users. If there is more than one solution, return the lexicographically 
/// minimum solution.
/// A 3-sequence X is lexicographically smaller than a 3-sequence Y if 
/// X[0] < Y[0] or X[0] == Y[0] and (X[1] < Y[1] or X[1] == Y[1] and 
/// X[2] < Y[2]). 
/// It is guaranteed that there is at least one user who visited at least 
/// 3 websites. No user visits two websites at the same time.
/// 
/// Example 1:
/// Input: username = ["joe","joe","joe","james","james","james",
/// "james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], 
/// website = ["home","about","career","home","cart","maps","home","home",
/// "about","career"]
/// Output: ["home","about","career"]
/// Explanation: 
/// The tuples in this example are:
/// ["joe", 1, "home"]
/// ["joe", 2, "about"]
/// ["joe", 3, "career"]
/// ["james", 4, "home"]
/// ["james", 5, "cart"]
/// ["james", 6, "maps"]
/// ["james", 7, "home"]
/// ["mary", 8, "home"]
/// ["mary", 9, "about"]
/// ["mary", 10, "career"]
/// The 3-sequence ("home", "about", "career") was visited at least once 
/// by 2 users.
/// The 3-sequence ("home", "cart", "maps") was visited at least once by 
/// 1 user.
/// The 3-sequence ("home", "cart", "home") was visited at least once by 
/// 1 user.
/// The 3-sequence ("home", "maps", "home") was visited at least once by 
/// 1 user.
/// The 3-sequence ("cart", "maps", "home") was visited at least once by 
/// 1 user.
/// 
/// Note:
/// 1. 3 <= N = username.length = timestamp.length = website.length <= 50
/// 2. 1 <= username[i].length <= 10
/// 3. 0 <= timestamp[i] <= 10^9
/// 4. 1 <= website[i].length <= 10
/// 5. Both username[i] and website[i] contain only lowercase characters.
/// </summary>
vector<string> LeetCodeHashtable::mostVisitedPattern(vector<string>& username,
    vector<int>& timestamp, vector<string>& website)
{
    unordered_map<string, vector<pair<int, string>>> user_visit;
    map<vector<string>, int> web_count;
    pair<int, vector<string>> result = { 0, {"", "", "" } };

    for (size_t i = 0; i < username.size(); i++)
    {
        user_visit[username[i]].push_back(make_pair(timestamp[i], website[i]));
    }
    for (auto itr : user_visit)
    {
        string user = itr.first;
        sort(user_visit[user].begin(), user_visit[user].end());
        set <vector<string>> hit;
        for (int j = 2; j < (int)user_visit[user].size(); j++)
        {
            for (int k = 0; k < j - 1; k++)
            {
                for (int l = k + 1; l < j; l++)
                {
                    vector<string> web;
                    web.push_back(user_visit[user][k].second);
                    web.push_back(user_visit[user][l].second);
                    web.push_back(user_visit[user][j].second);
                    hit.insert(web);
                }
            }
        }
        for (auto web : hit)
        {
            web_count[web]++;
        }
    }

    for (auto itr : web_count)
    {
        if (itr.second > result.first)
        {
            result.first = itr.second;
            result.second = itr.first;
        }
        else if (itr.second == result.first && itr.first < result.second)
        {
            result.second = itr.first;
        }
    }
    return result.second;
}

/// <summary>
/// Leet code 1 Two Sum
/// Given an array of integers, return indices of the two numbers such that 
/// they add up to a specific target.
/// You may assume that each input would have exactly one solution.
/// Example:
/// Given nums = [2, 7, 11, 15], target = 9,
/// Because nums[0] + nums[1] = 2 + 7 = 9,
/// return[0, 1]
/// </summary>
vector<int> LeetCodeHashtable::twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    unordered_map<int, int> num_map;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (num_map.count(target - nums[i]) > 0)
        {
            result = { num_map[target - nums[i]], i };
            return result;
        }
        num_map[nums[i]] = i;
    }
    return result;
}

/// <summary>
/// LeetCode #15. 3Sum
/// Given an array S of n integers, are there elements a, b, c in S such 
/// that a + b + c = 0? Find all unique triplets in the array which gives 
/// the sum of zero.
/// Note: The solution set must not contain duplicate triplets.
/// For example, given array S = [-1, 0, 1, 1, 2, -1, -1, -4],
/// A solution set is:
/// [
///   [-1, 0, 1],
///   [-1, -1, 2]
/// ]
/// </summary>
vector<vector<int>> LeetCodeHashtable::threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    unordered_map<int, int> num_map;
    // sort first, so we can dedup easily
    sort(nums.begin(), nums.end());
    // we only need to remember last one.
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_map[nums[i]] = i;
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        // skip all duplicated one on the same position
        if ((i > 0) && (nums[i] == nums[i - 1])) continue;
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            // skip all duplicated one on the same position
            if ((j > i + 1) && (nums[j] == nums[j - 1])) continue;
            int target = 0 - nums[i] - nums[j];
            if (num_map.count(target) > 0 && num_map[target] > (int)j)
            {
                result.push_back({ nums[i], nums[j], nums[num_map[target]] });
            }
        }
    }
    return result;
}

/// <summary>
/// LeetCode #15. 3Sum
/// </summary>
vector<vector<int>> LeetCodeHashtable::threeSumII(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size(); i++)
    {
        // skip all duplicated one on the same position
        if ((i > 0) && (nums[i] == nums[i - 1])) continue;
        int first = i + 1;
        int last = nums.size() - 1;
        while (first < last)
        {
            if ((first > i + 1) && (nums[first] == nums[first - 1]))
            {
                first++;
            }
            else if ((last < (int)nums.size() - 1) && (nums[last] == nums[last + 1]))
            {
                last--;
            }
            else if (nums[i] + nums[first] + nums[last] < 0)
            {
                first++;
            }
            else if (nums[i] + nums[first] + nums[last] > 0)
            {
                last--;
            }
            else
            {
                result.push_back({ nums[i], nums[first], nums[last] });
                first++;
                last--;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #454. 4Sum II  
/// Given four lists A, B, C, D of integer values, compute how many 
/// tuples (i, j, k, l) 
/// there are such that A[i] + B[j] + C[k] + D[l] is zero.
///
/// To make problem a bit easier, all A, B, C, D have same length of 
/// N where 0 <= N <= 500. 
/// All integers are in the range of -2^28 to 2^28 - 1 and the result 
/// is guaranteed to be at most 2^31 - 1.	
/// Example: 
/// Input:
/// A = [ 1, 2]
/// B = [-2,-1]
/// C = [-1, 2]
/// D = [ 0, 2]
///
/// Output:
/// 2
///
/// Explanation:
/// The two tuples are:
/// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
/// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
/// </summary>
int LeetCodeHashtable::fourSumCount(vector<int>& A, vector<int>& B,
    vector<int>& C, vector<int>& D)
{
    int result = 0;
    unordered_map<int, int> sum;

    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < B.size(); j++)
        {
            sum[A[i] + B[j]]++;
        }
    }
    for (size_t i = 0; i < C.size(); i++)
    {
        for (size_t j = 0; j < C.size(); j++)
        {
            int target = 0 - C[i] - D[j];
            if (sum.count(target) > 0) result += sum[target];
        }
    }
    return result;
}

/// <summary>
/// Leet code #18. 4Sum 
/// Given an array S of n integers, are there elements a, b, c, and d in S 
/// such that a + b + c + d = target? 
/// Find all unique quadruplets in the array which gives the sum of target.
/// Note: The solution set must not contain duplicate quadruplets. 
/// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
///
/// A solution set is:
/// [
///  [-1,  0, 0, 1],
///  [-2, -1, 1, 2],
///  [-2,  0, 0, 2]
/// ]
/// </summary>
vector<vector<int>> LeetCodeHashtable::fourSum(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    unordered_map<int, vector<pair<int, int>>> two_sum;

    for (int i = nums.size() - 1; i > 2; i--)
    {
        if (4 * nums[i] < target) break;
        // dedup
        if (i < (int)nums.size() - 1 && nums[i] == nums[i + 1]) continue;
        for (int j = i - 1; j > 1; j--)
        {
            // dedup
            if (j < (i - 1) && nums[j] == nums[j + 1]) continue;
            two_sum[nums[i] + nums[j]].push_back({ j, i });
        }
    }

    for (int i = 0; i < (int)nums.size() - 3; i++)
    {
        if (4 * nums[i] > target) break;
        // dedup
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < (int)nums.size() - 2; j++)
        {
            // dedup
            if (j > (i + 1) && nums[j] == nums[j - 1]) continue;
            int value = target - (nums[i] + nums[j]);
            if (two_sum.count(value) == 0) continue;

            for (int k = two_sum[value].size() - 1; k >= 0; k--)
            {
                if (two_sum[value][k].first <= (int)j) continue;
                result.push_back({ nums[i], nums[j], 
                                   nums[two_sum[value][k].first], 
                                   nums[two_sum[value][k].second] });
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #18. 4Sum 
/// </summary>
vector<vector<int>> LeetCodeHashtable::fourSumII(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < (int)nums.size() - 3; i++)
    {
        if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
        // dedup
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < (int)nums.size() - 2; j++)
        {
            if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
            // dedup
            if (j > (i + 1) && nums[j] == nums[j - 1]) continue;
            int value = target - (nums[i] + nums[j]);
            int first = j + 1;
            int last = nums.size() - 1;
            while (first < last)
            {
                if ((nums[first] + nums[first + 1] > value) || (nums[last - 1] + nums[last] < value))
                {
                    break;
                }
                if ((first > j + 1) && (nums[first] == nums[first - 1]))
                {
                    first++;
                }
                else if ((last < (int)nums.size() - 1) && (nums[last] == nums[last + 1]))
                {
                    last--;
                }
                else if (nums[first] + nums[last] < value)
                {
                    first++;
                }
                else if (nums[first] + nums[last] > value)
                {
                    last--;
                }
                else
                {
                    result.push_back({ nums[i], nums[j], nums[first], nums[last] });
                    first++;
                    last--;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1207. Unique Number of Occurrences
///
/// Given an array of integers arr, write a function that returns 
/// true if and only if the number of occurrences of each value in the 
/// array is unique.
///
/// Example 1:
///
/// Input: arr = [1,2,2,1,1,3]
/// Output: true
/// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No 
/// two values have the same number of occurrences.
///
/// Example 2:
///
/// Input: arr = [1,2]
/// Output: false
///
/// Example 3:
///
/// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
/// Output: true
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 1000
/// 2. -1000 <= arr[i] <= 1000
/// </summary>
bool LeetCodeHashtable::uniqueOccurrences(vector<int>& arr)
{
    unordered_map<int, int> num_occur;
    unordered_set<int> occur_set;
    for (size_t i = 0; i < arr.size(); i++)
    {
        num_occur[arr[i]]++;
    }
    for (auto itr : num_occur)
    {
        if (occur_set.count(itr.second) > 0)
        {
            return false;
        }
        else
        {
            occur_set.insert(itr.second);
        }
    }
    return true;
}

/// <summary>
/// Leet code #1218. Longest Arithmetic Subsequence of Given Difference
/// 
/// Given an integer array arr and an integer difference, return the length 
/// of the longest subsequence in arr which is an arithmetic sequence such 
/// that the difference between adjacent elements in the subsequence equals 
/// difference.
///
/// 
/// Example 1:
/// Input: arr = [1,2,3,4], difference = 1
/// Output: 4
/// Explanation: The longest arithmetic subsequence is [1,2,3,4].
///
/// Example 2:
///
/// Input: arr = [1,3,5,7], difference = 1
/// Output: 1
/// Explanation: The longest arithmetic subsequence is any single element.
///
/// Example 3:
///
/// Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
/// Output: 4
/// Explanation: The longest arithmetic subsequence is [7,5,3,1].
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. -10^4 <= arr[i], difference <= 10^4
/// </summary>
int LeetCodeHashtable::longestSubsequence(vector<int>& arr, int difference)
{
    unordered_map<int, int> seq_length;
    int result = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        int prev = arr[i] - difference;
        if (seq_length.count(prev) > 0)
        {
            seq_length[arr[i]] = max(seq_length[arr[i]], seq_length[prev] + 1);
        }
        else
        {
            seq_length[arr[i]] = max(seq_length[arr[i]], 1);
        }
        result = max(result, seq_length[arr[i]]);
    }
    return result;
}

/// <summary>
 /// Leet code #1224. Maximum Equal Frequency
 /// 
 /// Given an array nums of positive integers, return the longest possible 
 /// length of an array prefix of nums, such that it is possible to remove 
 /// exactly one element from this prefix so that every number that has 
 /// appeared in it will have the same number of occurrences.
 ///
 /// If after removing one element there are no remaining elements, it's 
 /// still considered that every appeared number has the same number of 
 /// ocurrences (0).
 ///
 /// 
 ///
 /// Example 1:
 ///
 /// Input: nums = [2,2,1,1,5,3,3,5]
 /// Output: 7
 /// Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we 
 /// remove nums[4]=5, we will get [2,2,1,1,3,3], so that each number 
 /// will appear exactly twice.
 ///
 /// Example 2:
 ///
 /// Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
 /// Output: 13
 ///
 /// Example 3:
 ///
 /// Input: nums = [1,1,1,2,2,2]
 /// Output: 5
 /// Example 4:
 ///
 /// Input: nums = [10,2,8,9,3,8,1,5,2,3,7,6]
 /// Output: 8
 /// 
 /// Constraints:
 /// 
 /// 1. 2 <= nums.length <= 10^5
 /// 2. 1 <= nums[i] <= 10^5
 /// </summary>
int LeetCodeHashtable::maxEqualFreq(vector<int>& nums)
{
    int result = 0;
    unordered_map<int, int> num_count;
    map<int, int> count_map;

    for (size_t i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        if (num_count.count(n) > 0)
        {
            int count = num_count[n];
            count_map[count]--;
            if (count_map[count] == 0)
            {
                count_map.erase(count);
            }
        }
        num_count[n]++;
        count_map[num_count[n]]++;

        // more than 2 counts
        if (count_map.size() > 2) continue;
        // only one distinct number         
        else if (num_count.size() == 1)
        {
            result = i + 1;
        }
        // every number only occur once
        else if (count_map.size() == 1 && count_map.begin()->first == 1)
        {
            result = i + 1;
        }
        else if (count_map.size() == 2)
        {
            auto first = count_map.begin();
            auto second = first;
            second++;

            // all same plus 1 abitary number
            if (first->first == 1 && first->second == 1)
            {
                result = i + 1;
            }
            // one group has an extra number
            else if (first->first + 1 == second->first && second->second == 1)
            {
                result = i + 1;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1257. Smallest Common Region
/// 
/// You are given some lists of regions where the first region of each 
/// list includes all other regions in that list.
///
/// Naturally, if a region X contains another region Y then X is bigger 
/// than Y.
///
/// Given two regions region1, region2, find out the smallest region that 
/// contains both of them.
///
/// If you are given regions r1, r2 and r3 such that r1 includes r3, it 
/// is guaranteed there is no r2 such that r2 includes r3.
///
/// It's guaranteed the smallest region exists.
///
/// Example 1:
///
/// Input:
/// regions = [["Earth","North America","South America"],
/// ["North America","United States","Canada"],
/// ["United States","New York","Boston"],
/// ["Canada","Ontario","Quebec"],
/// ["South America","Brazil"]],
/// region1 = "Quebec",
/// region2 = "New York"
/// Output: "North America"
///
/// Constraints:
///
/// 1. 2 <= regions.length <= 10^4
/// 2. region1 != region2
/// 3. All strings consist of English letters and spaces with at 
///    most 20 letters.
/// </summary>
string LeetCodeHashtable::findSmallestRegion(vector<vector<string>>& regions, string region1, string region2)
{
    unordered_map<string, string> up_links;
    for (size_t i = 0; i < regions.size(); i++)
    {
        for (size_t j = 1; j < regions[i].size(); j++)
        {
            up_links[regions[i][j]] = regions[i][0];
        }
    }

    unordered_set<string> parents;
    string str = region1;
    parents.insert(str);
    while (up_links.count(str) > 0)
    {
        str = up_links[str];
        parents.insert(str);
    }
    str = region2;
    while (parents.count(str) == 0)
    {
        str = up_links[str];
    }

    string result = str;
    return result;
}

/// <summary>
/// Leet code #1386. Cinema Seat Allocation
/// 
/// Medium
///
/// A cinema has n rows of seats, numbered from 1 to n and there are ten 
/// seats in each row, labelled from 1 to 10 as shown in the figure above.
///
/// Given the array reservedSeats containing the numbers of seats already 
/// reserved, for example, reservedSeats[i]=[3,8] means the seat located 
/// in row 3 and labelled with 8 is already reserved. 
///
/// Return the maximum number of four-person families you can allocate on 
/// the cinema seats. A four-person family occupies fours seats in one 
/// row, that are next to each other. Seats across an aisle (such 
/// as [3,3] and [3,4]) are not considered to be next to each other, 
/// however, It is permissible for the four-person family to be separated 
/// by an aisle, but in that case, exactly two people have to sit on each 
/// side of the aisle.
///
/// Example 1:
/// Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
/// Output: 4
/// Explanation: The figure above shows the optimal allocation for four 
/// families, where seats mark with blue are already reserved and 
/// contiguous seats mark with orange are for one family. 
/// 
/// Example 2:
/// Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
/// Output: 2
///
/// Example 3:
/// Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
/// Output: 4
///
/// Constraints:
/// 1. 1 <= n <= 10^9
/// 2. 1 <= reservedSeats.length <= min(10*n, 10^4)
/// 3. reservedSeats[i].length == 2
/// 4. 1 <= reservedSeats[i][0] <= n
/// 5. 1 <= reservedSeats[i][1] <= 10
/// 5. All reservedSeats[i] are distinct.
/// </summary>
int LeetCodeHashtable::maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
{
    unordered_map<int, int> bit_map;
    for (size_t i = 0; i < reservedSeats.size(); i++)
    {
        bit_map[reservedSeats[i][0] - 1] |= (1 << (reservedSeats[i][1] - 1));
    }
    int result = 0;
    for (auto itr : bit_map)
    {
        if ((itr.second & 0B0111111110) == 0)
        {
            result += 2;
        }
        else if ((itr.second & 0B0111100000) == 0)
        {
            result += 1;
        }
        else if ((itr.second & 0B0000011110) == 0)
        {
            result += 1;
        }
        else if ((itr.second & 0B0001111000) == 0)
        {
            result += 1;
        }
    }
    result += 2 * (n - bit_map.size());
    return result;
}


/// <summary>
/// Leet code #1394. Find Lucky Integer in an Array
/// 
/// Easy
///
/// Given an array of integers arr, a lucky integer is an integer which 
/// has a frequency in the array equal to its value.
///
/// Return a lucky integer in the array. If there are multiple lucky 
/// integers return the largest of them. If there is no lucky integer 
/// return -1.
/// 
/// Example 1:
/// Input: arr = [2,2,3,4]
/// Output: 2
/// Explanation: The only lucky number in the array is 2 because 
/// frequency[2] == 2.
///
/// Example 2:
/// Input: arr = [1,2,2,3,3,3]
/// Output: 3
/// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of 
/// them.
///
/// Example 3:
/// Input: arr = [2,2,2,3,3]
/// Output: -1
/// Explanation: There are no lucky numbers in the array.
///
/// Example 4:
/// Input: arr = [5]
/// Output: -1
/// Example 5:
///
/// Input: arr = [7,7,7,7,7,7,7]
/// Output: 7
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 500
/// 2. 1 <= arr[i] <= 500
/// </summary>
int LeetCodeHashtable::findLucky(vector<int>& arr)
{
    unordered_map<int, int> num_map;
    for (size_t i = 0; i < arr.size(); i++)
    {
        num_map[arr[i]]++;
    }

    int result = -1;
    for (auto itr : num_map)
    {
        if (itr.first == itr.second && itr.first > result)
        {
            result = itr.first;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1418. Display Table of Food Orders in a Restaurant
/// 
/// Medium
///
/// Given the array orders, which represents the orders that customers 
/// have done in a restaurant. More specifically orders[i]=
/// [customerNamei,tableNumberi,foodItemi] where customerNamei is the 
/// name of the customer, tableNumberi is the table customer sit at, and 
/// foodItemi is the item customer orders.
///
/// Return the restaurant's "display table". The "display table" is a 
/// table whose row entries denote how many of each food item each table 
/// ordered. The first column is the table number and the remaining 
/// columns correspond to each food item in alphabetical order. The first 
/// row should be a header whose first column is "Table", followed by the 
/// names of the food items. Note that the customer names are not part of 
/// the table. Additionally, the rows should be sorted in numerically 
/// increasing order.
/// 
/// Example 1:
/// Input: orders = [["David","3","Ceviche"],["Corina","10",
/// "Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],
/// ["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
/// Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],
/// ["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
/// Explanation:
/// The displaying table looks like:
/// Table,Beef Burrito,Ceviche,Fried Chicken,Water
/// 3    ,0           ,2      ,1            ,0
/// 5    ,0           ,1      ,0            ,1
/// 10   ,1           ,0      ,0            ,0
/// For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous 
/// orders "Ceviche".
/// For the table 5: Carla orders "Water" and "Ceviche".
/// For the table 10: Corina orders "Beef Burrito". 
///
/// Example 2:
/// Input: orders = [["James","12","Fried Chicken"],["Ratesh","12",
/// "Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1",
/// "Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
/// Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],
/// ["12","0","3"]] 
/// Explanation: 
/// For the table 1: Adam and Brianna order "Canadian Waffles".
/// For the table 12: James, Ratesh and Amadeus order "Fried Chicken".
///
/// Example 3:
/// Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2",
/// "Beef Burrito"],["Melissa","2","Soda"]]
/// Output: [["Table","Bean Burrito","Beef Burrito","Soda"],
/// ["2","1","1","1"]]
///  
/// Constraints:
/// 1. 1 <= orders.length <= 5 * 10^4
/// 2. orders[i].length == 3
/// 3. 1 <= customerNamei.length, foodItemi.length <= 20
/// 4. customerName[i] and foodItem[i] consist of lowercase and uppercase 
///    English letters and the space character.
/// 5. tableNumber[i] is a valid integer between 1 and 500.
/// </summary>
vector<vector<string>> LeetCodeHashtable::displayTable(vector<vector<string>>& orders)
{
    set<int> tbl_set;
    map<string, vector<int>> tbl_orders;

    for (size_t i = 0; i < orders.size(); i++)
    {
        string item = orders[i][2];
        int table_id = atoi(orders[i][1].c_str());
        if (tbl_orders.count(item) == 0)
        {
            tbl_orders[item] = vector<int>(501);
        }
        tbl_orders[orders[i][2]][table_id]++;
        tbl_set.insert(table_id);
    }
    vector<int> tables = vector<int>(tbl_set.begin(), tbl_set.end());

    vector<vector<string>> result;

    for (int i = -1; i < (int)tables.size(); i++)
    {
        vector<string> line;
        int table_id;
        if (i == -1)
        {
            line.push_back("Table");
        }
        else
        {
            table_id = tables[i];
            line.push_back(to_string(table_id));
        }
        for (auto itr : tbl_orders)
        {
            if (i == -1) line.push_back(itr.first);
            else
            {
                line.push_back(to_string(itr.second[table_id]));
            }
        }
        result.push_back(line);
    }
    return result;
}

/// <summary>
/// Leet code #1426. Counting Elements
/// 
/// Easy
///
/// Given an integer array arr, count how many elements x there are, such 
/// that x + 1 is also in arr.
///
/// If there're duplicates in arr, count them seperately.
/// 
/// Example 1:
/// Input: arr = [1,2,3]
/// Output: 2
/// Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
///
/// Example 2:
/// Input: arr = [1,1,3,3,5,5,7,7]
/// Output: 0
/// Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
///
/// Example 3:
/// Input: arr = [1,3,2,3,5,0]
/// Output: 3
/// Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
///
/// Example 4:
/// Input: arr = [1,1,2,2]
/// Output: 2
/// Explanation: Two 1s are counted cause 2 is in arr.
///
/// Example 5:
/// Input: arr = [1,1,2]
/// Output: 2
/// Explanation: Both 1s are counted because 2 is in the array.
///
/// Constraints:
/// 1. 1 <= arr.length <= 1000
/// 2. 0 <= arr[i] <= 1000
/// </summary>
int LeetCodeHashtable::countElements(vector<int>& arr)
{
    set<int> data_set;
    for (size_t i = 0; i < arr.size(); i++) data_set.insert(arr[i]);
    int result = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (data_set.count(arr[i] + 1) > 0) result++;
    }
    return result;
}

/// <summary>
/// Leet code #1452. People Whose List of Favorite Companies Is Not a 
///                  Subset of Another List
/// 
/// Medium
///
/// Given the array favoriteCompanies where favoriteCompanies[i] is the 
/// list of favorites companies for the ith person (indexed from 0).
/// Return the indices of people whose list of favorite companies is not 
/// a subset of any other list of favorites companies. You must return 
/// the indices in increasing order.
///
/// Example 1:
/// Input: favoriteCompanies = [["leetcode","google","facebook"],
/// ["google","microsoft"],["google","facebook"],["google"],["amazon"]]
/// Output: [0,1,4] 
/// Explanation: 
/// Person with index=2 has favoriteCompanies[2]=["google","facebook"] 
/// which is a subset of favoriteCompanies[0]=["leetcode","google",
/// "facebook"] corresponding to the person with index 0. 
/// Person with index=3 has favoriteCompanies[3]=["google"] which is a 
/// subset of favoriteCompanies[0]=["leetcode","google","facebook"] and 
/// favoriteCompanies[1]=["google","microsoft"]. 
/// Other lists of favorite companies are not a subset of another list, 
/// therefore, the answer is [0,1,4].
///
/// Example 2:
/// Input: favoriteCompanies = [["leetcode","google","facebook"],
/// ["leetcode","amazon"],["facebook","google"]]
/// Output: [0,1] 
/// Explanation: In this case favoriteCompanies[2]=["facebook","google"] 
/// is a subset of favoriteCompanies[0]=["leetcode","google","facebook"], 
/// therefore, the answer is [0,1].
///
/// Example 3:
/// Input: favoriteCompanies = [["leetcode"],["google"],["facebook"],
/// ["amazon"]]
/// Output: [0,1,2,3]
/// 
/// Constraints:
/// 1. 1 <= favoriteCompanies.length <= 100
/// 2. 1 <= favoriteCompanies[i].length <= 500
/// 3. 1 <= favoriteCompanies[i][j].length <= 20
/// 4. All strings in favoriteCompanies[i] are distinct.
/// 5. All lists of favorite companies are distinct, that is, If we sort 
///    alphabetically each list then 
///    favoriteCompanies[i] != favoriteCompanies[j].
/// 6. All strings consist of lowercase English letters only.
/// </summary>
vector<int> LeetCodeHashtable::peopleIndexes(vector<vector<string>>& favoriteCompanies)
{
    unordered_map<string, bitset<100>> company_masks;
    vector<int> result;
    for (size_t i = 0; i < favoriteCompanies.size(); i++)
    {
        for (size_t j = 0; j < favoriteCompanies[i].size(); j++)
        {
            string company = favoriteCompanies[i][j];
            company_masks[company].set(i);
        }
    }

    for (size_t i = 0; i < favoriteCompanies.size(); i++)
    {
        bitset<100> bit_mask;
        bit_mask.set();
        for (size_t j = 0; j < favoriteCompanies[i].size(); j++)
        {
            string company = favoriteCompanies[i][j];
            bitset<100> company_mask = company_masks[company];
            // discard self bit
            company_mask.reset(i);
            bit_mask &= company_mask;
            if (bit_mask.none()) break;
        }
        if (bit_mask.none()) result.push_back(i);
    }
    return result;
}

/// <summary>
/// Leet code #1481. Least Number of Unique Integers after K Removals
///
/// Medium
///
/// Given an array of integers arr and an integer k. Find the least 
/// number of unique integers after removing exactly k elements.
/// 
/// Example 1:
/// Input: arr = [5,5,4], k = 1
/// Output: 1
/// Explanation: Remove the single 4, only 5 is left.
///
/// Example 2:
/// Input: arr = [4,3,1,1,3,3,2], k = 3
/// Output: 2
/// Explanation: Remove 4, 2 and either one of the two 1s or 
/// three 3s. 1 and 3 will be left.
///
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 1 <= arr[i] <= 10^9
/// 3. 0 <= k <= arr.length
/// </summary> 
int LeetCodeHashtable::findLeastNumOfUniqueInts(vector<int>& arr, int k)
{
    unordered_map<int, int> num_map;
    for (size_t i = 0; i < arr.size(); i++)
    {
        num_map[arr[i]]++;
    }
    priority_queue<int> pq;
    for (auto itr : num_map)
    {
        pq.push(0 - itr.second);
    }
    while (!pq.empty() && k > 0)
    {
        int smallest = 0 - pq.top();
        k -= smallest;
        if (k >= 0) pq.pop();
    }
    return pq.size();
}

/// <summary>
/// Leet code #1487. Making File Names Unique
/// 
/// Medium
///
/// Given an array of strings names of size n. You will create n folders 
/// in your file system such that, at the ith minute, you will create a 
/// folder with the name names[i].
///
/// Since two files cannot have the same name, if you enter a folder name 
/// which is previously used, the system will have a suffix addition to 
/// its name in the form of (k), where, k is the smallest positive integer 
/// such that the obtained name remains unique.
///
/// Return an array of strings of length n where ans[i] is the actual name 
/// the system will assign to the ith folder when you create it.
/// 
/// Example 1:
/// Input: names = ["pes","fifa","gta","pes(2019)"]
/// Output: ["pes","fifa","gta","pes(2019)"]
/// Explanation: Let's see how the file system creates folder names:
/// "pes" --> not assigned before, remains "pes"
/// "fifa" --> not assigned before, remains "fifa"
/// "gta" --> not assigned before, remains "gta"
/// "pes(2019)" --> not assigned before, remains "pes(2019)"
///
/// Example 2:
/// Input: names = ["gta","gta(1)","gta","avalon"]
/// Output: ["gta","gta(1)","gta(2)","avalon"]
/// Explanation: Let's see how the file system creates folder names:
/// "gta" --> not assigned before, remains "gta"
/// "gta(1)" --> not assigned before, remains "gta(1)"
/// "gta" --> the name is reserved, system adds (k), since "gta(1)" is 
/// also reserved, systems put k = 2. it becomes "gta(2)"
/// "avalon" --> not assigned before, remains "avalon"
///
/// Example 3:
/// Input: names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)",
/// "onepiece"]
/// Output: ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)",
/// "onepiece(4)"]
/// Explanation: When the last folder is created, the smallest positive 
/// valid k is 4, and it becomes "onepiece(4)".
///
/// Example 4:
///
/// Input: names = ["wano","wano","wano","wano"]
/// Output: ["wano","wano(1)","wano(2)","wano(3)"]
/// Explanation: Just increase the value of k each time you create folder 
/// "wano".
///
/// Example 5:
/// Input: names = ["kaido","kaido(1)","kaido","kaido(1)"]
/// Output: ["kaido","kaido(1)","kaido(2)","kaido(1)(1)"]
/// Explanation: Please note that system adds the suffix (k) to current 
/// name even it contained the same suffix before.
/// 
/// Constraints:
/// 1. 1 <= names.length <= 5 * 10^4
/// 2. 1 <= names[i].length <= 20
/// 3. names[i] consists of lower case English letters, digits and/or 
///    round brackets.
/// </summary>
vector<string> LeetCodeHashtable::getFolderNames(vector<string>& names)
{
    unordered_map<string, int> cache;
    vector<string> result;
    for (size_t i = 0; i < names.size(); i++)
    {
        string str = names[i];
        int index = 0;
        if (cache.count(str) > 0)
        {
            index = cache[str];
        }
        while (cache.count(str) > 0)
        {
            index++;
            str = names[i] + "(" + to_string(index) + ")";
        }
        result.push_back(str);
        cache[names[i]] = index;
        cache[str] = 0;
    }
    return result;
}

/// <summary>
/// Leet code #1496. Path Crossing
/// 
/// Easy
///
/// Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each 
/// representing moving one unit north, south, east, or west, 
/// respectively. You start at the origin (0, 0) on a 2D plane and 
/// walk on the path specified by path.
///
/// Return True if the path crosses itself at any point, that is, 
/// if at any time you are on a location you've previously visited. 
/// Return False otherwise.
///
/// Example 1:
/// Input: path = "NES"
/// Output: false 
/// Explanation: Notice that the path doesn't cross any point more 
/// than once.
///
/// Example 2:
/// Input: path = "NESWW"
/// Output: true
/// Explanation: Notice that the path visits the origin twice.
/// Constraints:
/// 1. 1 <= path.length <= 10^4
/// 2. path will only consist of characters in {'N', 'S', 'E', 'W}
/// </summary>
bool LeetCodeHashtable::isPathCrossing(string path)
{
    vector<int> pos = { 0, 0 };
    set<vector<int>> visited;
    visited.insert(pos);
    unordered_map<char, vector<int>> directions = 
    {
        {'N', {0, -1}},
        {'S', {0, 1}},
        {'W', {-1, 0}},
        {'E', {1, 0}},
    };
    for (size_t i = 0; i < path.size(); i++)
    {
        pos[0] += directions[path[i]][0];
        pos[1] += directions[path[i]][1];
        if (visited.count(pos) > 0)
        {
            return true;
        }
        visited.insert(pos);
    }
    return false;
}

/// <summary>
/// Leet code #1512. Number of Good Pairs
///
/// Easy
///	
/// Given an array of integers nums.
///
/// A pair (i,j) is called good if nums[i] == nums[j] and i < j.
///
/// Return the number of good pairs.
///
/// Example 1:
/// Input: nums = [1,2,3,1,1,3]
/// Output: 4
/// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5)
/// 0-indexed.
///
/// Example 2:
/// Input: nums = [1,1,1,1]
/// Output: 6
/// Explanation: Each pair in the array are good.
///
/// Example 3:
/// Input: nums = [1,2,3]
/// Output: 0
///
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 1 <= nums[i] <= 100
/// </summary>
int LeetCodeHashtable::numIdenticalPairs(vector<int>& nums)
{
    unordered_map<int, int> count_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        count_map[nums[i]]++;
    }
    int result = 0;
    for (auto itr : count_map)
    {
        result += itr.second * (itr.second - 1) / 2;
    }

    return result;
}

/// <summary>
/// Leet code #1577. Number of Ways Where Square of Number Is Equal to 
///                  Product of Two Numbers 
/// 
/// Medium
///
/// Given two arrays of integers nums1 and nums2, return the number of 
/// triplets formed (type 1 and type 2) under the following rules:
///
/// Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 
/// 0 <= i < nums1.length and 0 <= j < k < nums2.length.
/// Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 
/// 0 <= i < nums2.length and 0 <= j < k < nums1.length.
/// 
/// Example 1:
/// Input: nums1 = [7,4], nums2 = [5,2,8,9]
/// Output: 1
/// Explanation: Type 1: (1,1,2), nums1[1]^2 = nums2[1] * nums2[2]. 
/// (4^2 = 2 * 8). 
///
/// Example 2:
/// Input: nums1 = [1,1], nums2 = [1,1,1]
/// Output: 9
/// Explanation: All Triplets are valid, because 1^2 = 1 * 1.
/// Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  
/// nums1[i]^2 = nums2[j] * nums2[k].
/// Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]^2 = nums1[j] * nums1[k].
///
/// Example 3:
/// Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
/// Output: 2
/// Explanation: There are 2 valid triplets.
/// Type 1: (3,0,2).  nums1[3]^2 = nums2[0] * nums2[2].
/// Type 2: (3,0,1).  nums2[3]^2 = nums1[0] * nums1[1].
///
/// Example 4:
/// Input: nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
/// Output: 0
/// Explanation: There are no valid triplets.
///
/// Constraints:
/// 1. 1 <= nums1.length, nums2.length <= 1000
/// 2. 1 <= nums1[i], nums2[i] <= 10^5
/// </summary>
int LeetCodeHashtable::numTriplets(vector<int>& nums1, vector<int>& nums2)
{
    int result = 0;
    unordered_map<long long , int> squares;

    for (size_t i = 0; i < nums2.size(); i++)
    {
        squares[(long long)nums2[i] * (long long)nums2[i]]++;
    }
    for (size_t i = 0; i < nums1.size(); i++)
    {
        for (size_t j = i + 1; j < nums1.size(); j++)
        {
            long long product = (long long)nums1[i] * (long long)nums1[j];
            if (squares.count(product) > 0)
            {
                result += squares[product];
            }
        }
    }
    squares.clear();
    for (size_t i = 0; i < nums1.size(); i++)
    {
        squares[(long long)nums1[i] * (long long)nums1[i]]++;
    }
    for (size_t i = 0; i < nums2.size(); i++)
    {
        for (size_t j = i + 1; j < nums2.size(); j++)
        {
            long long product = (long long)nums2[i] * (long long)nums2[j];
            if (squares.count(product) > 0)
            {
                result += squares[product];
            }
        }
    }

    return result;
}

/// <summary>
/// Leet code #1604. Alert Using Same Key-Card Three or More Times in a 
///                  One Hour Period
/// 
/// Medium
///
/// Leetcode company workers use key-cards to unlock office doors. Each 
/// time a worker uses their key-card, the security system saves the 
/// worker's name and the time when it was used. The system emits an 
/// alert if any worker uses the key-card three or more times in a 
/// one-hour period.
///
/// You are given a list of strings keyName and keyTime where 
/// [keyName[i], keyTime[i]] corresponds to a person's name and the 
/// time when their key-card was used in a single day.
///
/// Access times are given in the 24-hour time format "HH:MM", such as 
/// "23:51" and "09:49".
///
/// Return a list of unique worker names who received an alert for frequent 
/// keycard use. Sort the names in ascending order alphabetically.
///
/// Notice that "10:00" - "11:00" is considered to be within a one-hour 
/// period, while "23:51" - "00:10" is not considered to be within a 
/// one-hour period.
/// 
/// Example 1:
/// Input: keyName = ["daniel","daniel","daniel","luis","luis","luis",
/// "luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00",
/// "15:00"]
/// Output: ["daniel"]
/// Explanation: "daniel" used the keycard 3 times in a one-hour period 
/// ("10:00","10:40", "11:00").
///
/// Example 2:
/// Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], 
/// keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
/// Output: ["bob"]
/// Explanation: "bob" used the keycard 3 times in a one-hour period 
/// ("21:00","21:20", "21:30").
///
/// Example 3:
/// Input: keyName = ["john","john","john"], 
/// keyTime = ["23:58","23:59","00:01"]
/// Output: []
///
/// Example 4:
/// Input: keyName = ["leslie","leslie","leslie","clare","clare","clare",
/// "clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30",
/// "19:49"]
/// Output: ["clare","leslie"]
/// 
/// Constraints:
/// 1. 1 <= keyName.length, keyTime.length <= 10^5
/// 2. keyName.length == keyTime.length
/// 3. keyTime are in the format "HH:MM".
/// 4. [keyName[i], keyTime[i]] is unique.
/// 5. 1 <= keyName[i].length <= 10
/// 6. keyName[i] contains only lowercase English letters.
/// </summary>
vector<string> LeetCodeHashtable::alertNames(vector<string>& keyName, vector<string>& keyTime)
{
    unordered_map<string, vector<string>> entries;
    vector<string> result;
    for (size_t i = 0; i < keyName.size(); i++)
    {
        entries[keyName[i]].push_back(keyTime[i]);
    }
    for (auto itr : entries)
    {
        sort(itr.second.begin(), itr.second.end());
        for (size_t i = 2; i < itr.second.size(); i++)
        {
            string prev_time = itr.second[i - 2];
            string curr_time = itr.second[i];
            int prev_hour = atoi(prev_time.substr(0, 2).c_str());
            int prev_min = atoi(prev_time.substr(3, 2).c_str());
            int curr_hour = atoi(curr_time.substr(0, 2).c_str());
            int curr_min = atoi(curr_time.substr(3, 2).c_str());
            if ((prev_hour == curr_hour) ||
                ((prev_hour + 1 == curr_hour) && (curr_min <= prev_min)))
            {
                result.push_back(itr.first);
                break;
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #1679. Max Number of K-Sum Pairs
/// 
/// Medium
/// 
/// You are given an integer array nums and an integer k.
/// In one operation, you can pick two numbers from the array whose sum 
/// equals k and remove them from the array.
///
/// Return the maximum number of operations you can perform on the array.
///
/// Example 1:
/// Input: nums = [1,2,3,4], k = 5
/// Output: 2
/// Explanation: Starting with nums = [1,2,3,4]:
/// - Remove numbers 1 and 4, then nums = [2,3]
/// - Remove numbers 2 and 3, then nums = []
/// There are no more pairs that sum up to 5, hence a total of 2 
/// operations.
///
/// Example 2:
/// Input: nums = [3,1,3,4,3], k = 6
/// Output: 1
/// Explanation: Starting with nums = [3,1,3,4,3]:
/// - Remove the first two 3's, then nums = [1,4,3]
/// There are no more pairs that sum up to 6, hence a total of 1 operation.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^9
/// 3. 1 <= k <= 10^9
/// </summary>
int LeetCodeHashtable::maxOperations(vector<int>& nums, int k)
{
    unordered_map<int, int> hashtable;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (hashtable.count(k - nums[i]) > 0)
        {
            hashtable[k - nums[i]]--;
            if (hashtable[k - nums[i]] == 0)
            {
                hashtable.erase(k - nums[i]);
            }
            result++;
        }
        else
        {
            hashtable[nums[i]]++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1711. Count Good Meals
/// 
/// Medium
/// 
/// A good meal is a meal that contains exactly two different food items 
/// with a sum of deliciousness equal to a power of two.
///
/// You can pick any two different foods to make a good meal.
///
/// Given an array of integers deliciousness where deliciousness[i] is 
/// the deliciousness of the ith item of food, return the number of 
/// different good meals you can make from this list modulo 10^9 + 7.
///
/// Note that items with different indices are considered different 
/// even if they have the same deliciousness value.
///
/// Example 1:
/// Input: deliciousness = [1,3,5,7,9]
/// Output: 4
/// Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
/// Their respective sums are 4, 8, 8, and 16, all of which are powers 
/// of 2.
///
/// Example 2:
/// Input: deliciousness = [1,1,1,3,3,3,7]
/// Output: 15
/// Explanation: The good meals are (1,1) with 3 ways, (1,3) with 9 ways, 
/// and (1,7) with 3 ways.
///
/// Constraints:
/// 1. 1 <= deliciousness.length <= 10^5
/// 2. 0 <= deliciousness[i] <= 2^20
/// </summary>
int LeetCodeHashtable::countPairs(vector<int>& deliciousness)
{
    int M = 1000000007;
    unordered_map<int, int> count_map;
    int result = 0;
    for (size_t i = 0; i < deliciousness.size(); i++)
    {
        int pow = 1;
        for (size_t j = 0; j < 22; j++)
        {
            if (count_map.count(pow - deliciousness[i]) > 0)
            {
                result = (result + count_map[pow - deliciousness[i]]) % M;
            }
            pow = pow * 2;
        }
        count_map[deliciousness[i]]++;
    }
    return result;
}

/// <summary>
/// Leet code 1714. Sum Of Special Evenly-Spaced Elements In Array
/// 
/// Hard
/// 
/// You are given a 0-indexed integer array nums consisting of n 
/// non-negative integers.
///
/// You are also given an array queries, where queries[i] = [xi, yi]. The 
/// answer to the ith query is the sum of all nums[j] where xi <= j < n 
/// and (j - xi) is divisible by yi.
///
/// Return an array answer where answer.length == queries.length and 
/// answer[i] is the answer to the ith query modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: nums = [0,1,2,3,4,5,6,7], queries = [[0,3],[5,1],[4,2]]
/// Output: [9,18,10]
/// Explanation: The answers of the queries are as follows:
/// 1) The j indices that satisfy this query are 0, 3, and 6. 
/// nums[0] + nums[3] + nums[6] = 9
/// 2) The j indices that satisfy this query are 5, 6, and 7. 
/// nums[5] + nums[6] + nums[7] = 18
/// 3) The j indices that satisfy this query are 4 and 6. 
/// nums[4] + nums[6] = 10
///
/// Example 2:
/// Input: nums = [100,200,101,201,102,202,103,203], queries = [[0,7]]
/// Output: [303]
/// Constraints:
/// 1. n == nums.length
/// 2. 1 <= n <= 5 * 10^4
/// 3. 0 <= nums[i] <= 10^9
/// 4. 1 <= queries.length <= 1.5 * 10^5
/// 5. 0 <= xi < n
/// 6. 1 <= yi <= 5 * 10^4
/// </summary>
vector<int> LeetCodeHashtable::solve(vector<int>& nums, vector<vector<int>>& queries)
{
    int M = 1000000007;
    int n = nums.size();
    unordered_map<long long, vector<int>> pre_sum;
    vector<int> result(queries.size());

    for (size_t i = 0; i < queries.size(); i++)
    {
        int start = queries[i][0];
        int step = queries[i][1];
        if (step >= sqrt(n))
        {
            int sum = 0;
            for (int j = start; j < n; j += step)
            {
                sum = (sum + nums[j]) % M;
            }
            result[i] = sum;
        }
        else
        {
            int origin = start % step;
            long long hash_code = (long long)step * (long long)n + (long long)origin;
            if (pre_sum.count(hash_code) == 0)
            {
                vector<int>temp;;
                int sum = 0;
                for (int j = origin; j < n; j += step)
                {
                    sum = (sum + nums[j]) % M;
                    temp.push_back(sum);
                }
                pre_sum[hash_code] = temp;
            }
            int prev_index = start / step - 1;
            int sum = 0;
            if (prev_index == -1)
            {
                sum = pre_sum[hash_code].back();
            }
            else
            {
                sum = (pre_sum[hash_code].back() - pre_sum[hash_code][prev_index] + M) % M;
            }
            result[i] = sum;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1748. Sum of Unique Elements
/// 
/// Easy
/// 
/// You are given an integer array nums. The unique elements of an array 
/// are the elements that appear exactly once in the array.
///
/// Return the sum of all the unique elements of nums.
/// 
/// Example 1:
/// Input: nums = [1,2,3,2]
/// Output: 4
/// Explanation: The unique elements are [1,3], and the sum is 4.
///
/// Example 2:
/// Input: nums = [1,1,1,1,1]
/// Output: 0
/// Explanation: There are no unique elements, and the sum is 0.
///
/// Example 3:
/// Input: nums = [1,2,3,4,5]
/// Output: 15
/// Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 1 <= nums[i] <= 100
/// </summary>
int LeetCodeHashtable::sumOfUnique(vector<int>& nums)
{
    vector<int> arr(101);
    for (size_t i = 0; i < nums.size(); i++)
    {
        arr[nums[i]]++;
    }
    int result = 0;
    for (int i = 0; i < 101; i++)
    {
        if (arr[i] == 1) result += i;
    }
    return result;
}

/// <summary>
/// Leet code 1755. Closest Subsequence Sum
/// 
/// Hard
/// 
/// You are given an integer array nums and an integer goal.
/// You want to choose a subsequence of nums such that the sum of its 
/// elements is the closest possible to goal. That is, if the sum of the 
/// subsequence's elements is sum, then you want to minimize the absolute 
/// difference abs(sum - goal).
///
/// Return the minimum possible value of abs(sum - goal).
/// Note that a subsequence of an array is an array formed by removing 
/// some elements (possibly all or none) of the original array.
///
/// Example 1:
/// Input: nums = [5,-7,3,5], goal = 6
/// Output: 0
/// Explanation: Choose the whole array as a subsequence, with a sum of 6.
/// This is equal to the goal, so the absolute difference is 0.
///
/// Example 2:
/// Input: nums = [7,-9,15,-2], goal = -5
/// Output: 1
/// Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
/// The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the 
/// minimum.
///
/// Example 3:
/// Input: nums = [1,2,3], goal = -7
/// Output: 7
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 40
/// 2. -10^7 <= nums[i] <= 10^7
/// 3. -10^9 <= goal <= 10^9
/// </summary>
int LeetCodeHashtable::minAbsDifference(vector<int>& nums, int goal)
{
    set<int> h1, h2;
    for (size_t i = 0; i < nums.size() / 2; i++)
    {
        vector<int> temp = vector<int>(h1.begin(), h1.end());
        for (auto sum : temp)
        {
            h1.insert(sum + nums[i]);
        }
        h1.insert(nums[i]);
    }
    for (size_t i = nums.size() / 2; i < nums.size(); i++)
    {
        vector<int> temp = vector<int>(h2.begin(), h2.end());
        for (auto sum : temp)
        {
            h2.insert(sum + nums[i]);
        }
        h2.insert(nums[i]);
    }
    int result = std::abs(goal);
    auto itr = h1.lower_bound(goal);
    if (itr != h1.end())
    {
        result = min(result, *itr - goal);
    }
    if (itr != h1.begin())
    {
        result = min(result, goal - *prev(itr));
    }
    vector<int> remaining;
    remaining.push_back(goal);
    for (int sum : h1) remaining.push_back(goal - sum);
    for (int target : remaining)
    {
        itr = h2.lower_bound(target);
        if (itr != h2.end())
        {
            result = min(result, *itr - target);
        }
        if (itr != h2.begin())
        {
            result = min(result, target - *prev(itr));
        }
    }
    return result;
}

/// <summary>
/// Leet code 1733. Minimum Number of People to Teach
/// 
/// Medium
/// 
/// On a social network consisting of m users and some friendships between 
/// users, two users can communicate with each other if they know a common 
/// language.
///
/// You are given an integer n, an array languages, and an array 
/// friendships where:
/// There are n languages numbered 1 through n,
/// languages[i] is the set of languages the ith user knows, and
/// friendships[i] = [ui, vi] denotes a friendship between the users 
/// ui and vi.
/// You can choose one language and teach it to some users so that all 
/// friends can communicate with each other. Return the minimum number of 
/// users you need to teach.
/// 
/// Note that friendships are not transitive, meaning if x is a friend of y 
/// and y is a friend of z, this doesn't guarantee that x is a friend of z.
///
/// Example 1:
/// Input: n = 2, languages = [[1],[2],[1,2]], 
/// friendships = [[1,2],[1,3],[2,3]]
/// Output: 1
/// Explanation: You can either teach user 1 the second language or user 2 
/// the first language.
///
/// Example 2:
/// Input: n = 3, languages = [[2],[1,3],[1,2],[3]], 
/// friendships = [[1,4],[1,2],[3,4],[2,3]]
/// Output: 2
/// Explanation: Teach the third language to users 1 and 3, yielding two 
/// users to teach.
///
/// Constraints:
/// 1. 2 <= n <= 500
/// 2. languages.length == m
/// 3. 1 <= m <= 500
/// 4. 1 <= languages[i].length <= n
/// 5. 1 <= languages[i][j] <= n
/// 6. 1 <= ui < vi <= languages.length
/// 7. 1 <= friendships.length <= 500
/// 8. All tuples (ui, vi) are unique
/// 9. languages[i] contains only unique values
/// </summary>
int LeetCodeHashtable::minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
{
    unordered_map<int, unordered_set<int>> user_languages;
    vector<int> popular_languages(n);
    unordered_set<int> users_nottalk;
    for (size_t i = 0; i < languages.size(); i++)
    {
        for (size_t j = 0; j < languages[i].size(); j++)
        {
            user_languages[i].insert(languages[i][j]);
        }
    }
    for (size_t i = 0; i < friendships.size(); i++)
    {
        bool communicate = false;
        for (auto language : user_languages[friendships[i][0] -1])
        {
            if (user_languages[friendships[i][1]-1].count(language) > 0)
            {
                communicate = true;
                break;
            }
        }
        if (communicate == false)
        {
            users_nottalk.insert(friendships[i][0]-1);
            users_nottalk.insert(friendships[i][1]-1);
        }
    }
    int popular = 0;
    for (auto user: users_nottalk)
    {
        for (auto language : user_languages[user])
        {
            popular_languages[language - 1]++;
            popular = max(popular, popular_languages[language - 1]);
        }
    }
    int result = users_nottalk.size() - popular;
    return result;
}

/// <summary>
/// Leet code 1773. Count Items Matching a Rule
/// 
/// Easy
/// 
/// You are given an array items, where each items[i] = [typei, colori, 
/// namei] describes the type, color, and name of the ith item. You 
/// are also given a rule represented by two strings, ruleKey and 
/// ruleValue.
///
/// The ith item is said to match the rule if one of the following is true:
///
/// ruleKey == "type" and ruleValue == typei.
/// ruleKey == "color" and ruleValue == colori.
/// ruleKey == "name" and ruleValue == namei.
/// Return the number of items that match the given rule.
/// 
/// Example 1:
/// Input: items = [["phone","blue","pixel"],
/// ["computer","silver","lenovo"], ["phone","gold","iphone"]], 
/// ruleKey = "color", ruleValue = "silver"
/// Output: 1
/// Explanation: There is only one item matching the given rule, which is 
/// ["computer","silver","lenovo"].
///
/// Example 2:
/// Input: items = [["phone","blue","pixel"],["computer","silver","phone"],
/// ["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
/// Output: 2
/// Explanation: There are only two items matching the given rule, which 
/// are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that 
/// the item ["computer","silver","phone"] does not match.
///
/// Constraints:
/// 1. 1 <= items.length <= 10^4
/// 2. 1 <= typei.length, colori.length, namei.length, 
///    ruleValue.length <= 10
/// 3. ruleKey is equal to either "type", "color", or "name".
/// 4. All strings consist only of lowercase letters.
/// </summary>
int LeetCodeHashtable::countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)
{
    unordered_map<string, int> key_map = { {"type", 0}, {"color", 1}, {"name", 2} };
    int ruleIndex = key_map[ruleKey];
    int result = 0;
    for (size_t i = 0; i < items.size(); i++)
    {
        if (items[i][ruleIndex] == ruleValue) result++;
    }
    return result;
}

/// <summary>
/// Leet code 1814. Count Nice Pairs in an Array
/// 
/// Medium
/// 
/// You are given an array nums that consists of non-negative integers. 
/// Let us define rev(x) as the reverse of the non-negative integer x. 
/// For example, rev(123) = 321, and rev(120) = 21. A pair of 
/// indices (i, j) is nice if it satisfies all of the following conditions:
///
/// 0 <= i < j < nums.length
/// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
/// Return the number of nice pairs of indices. Since that number can be 
/// too large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: nums = [42,11,1,97]
/// Output: 2
/// Explanation: The two pairs are:
/// - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
/// - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
///
/// Example 2:
/// Input: nums = [13,10,35,24,76]
/// Output: 4
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^9
/// </summary>
int LeetCodeHashtable::countNicePairs(vector<int>& nums)
{
    long long M = 1000000007;
    unordered_map<long long, long long> num_count;
    long long result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        string str = to_string(nums[i]);
        reverse(str.begin(), str.end());
        long long rev = atol(str.c_str());
        long long value = (long long)(nums[i]) - rev;
        result = (result + num_count[value]) % M;
        num_count[value]++;
    }
    return (int)result;
}


/// <summary>
/// Leet code 1817. Finding the Users Active Minutes
/// 
/// Medium
/// 
/// You are given the logs for users' actions on LeetCode, and an integer 
/// k. The logs are represented by a 2D integer array logs where each 
/// logs[i] = [IDi, timei] indicates that the user with IDi performed an 
/// action at the minute timei.
///
/// Multiple users can perform actions simultaneously, and a single user 
/// can perform multiple actions in the same minute.
///
/// The user active minutes (UAM) for a given user is defined as the 
/// number of unique minutes in which the user performed an action on 
/// LeetCode. A minute can only be counted once, even if multiple actions 
/// occur during it.
///
/// You are to calculate a 1-indexed array answer of size k such that, for 
/// each j (1 <= j <= k), answer[j] is the number of users whose UAM 
/// equals j.
///
/// Return the array answer as described above.
///
/// Example 1:
/// Input: logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
/// Output: [0,2,0,0,0]
/// Explanation:
/// The user with ID=0 performed actions at minutes 5, 2, and 5 again. 
/// Hence, they have a UAM of 2 (minute 5 is only counted once).
/// The user with ID=1 performed actions at minutes 2 and 3. Hence, they 
/// have a UAM of 2.
/// Since both users have a UAM of 2, answer[2] is 2, and the remaining 
/// answer[j] values are 0.
///
/// Example 2:
/// Input: logs = [[1,1],[2,2],[2,3]], k = 4
/// Output: [1,1,0,0]
/// Explanation:
/// The user with ID=1 performed a single action at minute 1. Hence, they 
/// have a UAM of 1.
/// The user with ID=2 performed actions at minutes 2 and 3. Hence, they 
/// have a UAM of 2.
/// There is one user with a UAM of 1 and one with a UAM of 2.
/// Hence, answer[1] = 1, answer[2] = 1, and the remaining values are 0.
/// 
/// Constraints:
/// 1. 1 <= logs.length <= 10^4
/// 2. 0 <= IDi <= 10^9
/// 3. 1 <= timei <= 10^5
/// 4. k is in the range [The maximum UAM for a user, 10^5].
/// </summary>
vector<int> LeetCodeHashtable::findingUsersActiveMinutes(vector<vector<int>>& logs, int k)
{
    unordered_map<int, unordered_set<int>> access_map;
    vector<int> result(k);
    for (size_t i = 0; i < logs.size(); i++)
    {
        access_map[logs[i][0]].insert(logs[i][1]);
    }
    for (auto itr : access_map)
    {
        if ((int)itr.second.size() <= k) result[itr.second.size() - 1]++;
    }
    return result;
}

/// <summary>
/// Leet code 1941. Check if All Characters Have Equal Number of 
///                 Occurrences
///                                  
/// Easy
/// 
/// 
/// Given a string s, return true if s is a good string, or false otherwise.
///
/// A string s is good if all the characters that appear in s have the same
/// number of occurrences (i.e., the same frequency).
/// 
/// Example 1:
/// Input: s = "abacbc"
/// Output: true
/// Explanation: The characters that appear in s are 'a', 'b', and 'c'. 
/// All characters occur 2 times in s.
///
/// Example 2:
/// Input: s = "aaabb"
/// Output: false
/// Explanation: The characters that appear in s are 'a' and 'b'.
/// 'a' occurs 3 times while 'b' occurs 2 times, which is not the same 
/// number of times.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s consists of lowercase English letters.
/// </summary>
bool LeetCodeHashtable::areOccurrencesEqual(string s)
{
    vector<int> chars(26);
    for (size_t i = 0; i < s.size(); i++)
    {
        chars[s[i] - 'a']++;
    }
    int result = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if (chars[i] == 0) continue;
        if (result == 0) result = chars[i];
        else
        {
            if (result != chars[i]) return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code 2053. Kth Distinct String in an Array
///                                                
/// Easy
/// 
/// A distinct string is a string that is present only once in an array.
///
/// Given an array of strings arr, and an integer k, return the kth 
/// distinct string present in arr. If there are fewer than k distinct 
/// strings, return an empty string "".
///
/// Note that the strings are considered in the order in which they 
/// appear in the array.
/// 
/// Example 1:
/// Input: arr = ["d","b","c","b","c","a"], k = 2
/// Output: "a"
/// Explanation:
/// The only distinct strings in arr are "d" and "a".
/// "d" appears 1st, so it is the 1st distinct string.
/// "a" appears 2nd, so it is the 2nd distinct string.
/// Since k == 2, "a" is returned. 
///
/// Example 2:
/// Input: arr = ["aaa","aa","a"], k = 1
/// Output: "aaa"
/// Explanation:
/// All strings in arr are distinct, so the 1st string "aaa" is returned.
///
/// Example 3:
/// Input: arr = ["a","b","a"], k = 3
/// Output: ""
/// Explanation:
/// The only distinct string is "b". Since there are fewer than 3 distinct 
/// strings, we return an empty string "".
/// 
/// Constraints:  
/// 1. 1 <= k <= arr.length <= 1000
/// 2. 1 <= arr[i].length <= 5
/// 3. arr[i] consists of lowercase English letters.
/// </summary>
string LeetCodeHashtable::kthDistinct(vector<string>& arr, int k)
{
    unordered_map<string, int> str_count;
    for (size_t i = 0; i < arr.size(); i++)
    {
        str_count[arr[i]]++;
    }
    int count = 0;
    string result;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (str_count[arr[i]] == 1) count++;
        if (count == k)
        {
            result = arr[i];
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1995. Count Special Quadruplets
///                                                
/// Easy
/// 
/// Given a 0-indexed integer array nums, return the number of distinct 
/// quadruplets (a, b, c, d) such that:
///
/// nums[a] + nums[b] + nums[c] == nums[d], and
/// a < b < c < d
/// 
/// Example 1:
/// Input: nums = [1,2,3,6]
/// Output: 1
/// Explanation: The only quadruplet that satisfies the requirement is 
/// (0, 1, 2, 3) because 1 + 2 + 3 == 6.
///
/// Example 2:
/// Input: nums = [3,3,6,4,5]
/// Output: 0
/// Explanation: There are no such quadruplets in [3,3,6,4,5].
///
/// Example 3:
/// Input: nums = [1,1,1,3,5]
/// Output: 4
/// Explanation: The 4 quadruplets that satisfy the requirement are:
/// - (0, 1, 2, 3): 1 + 1 + 1 == 3
/// - (0, 1, 3, 4): 1 + 1 + 3 == 5
/// - (0, 2, 3, 4): 1 + 1 + 3 == 5
/// - (1, 2, 3, 4): 1 + 1 + 3 == 5
///
/// Constraints:
/// 1. 4 <= nums.length <= 50
/// 2. 1 <= nums[i] <= 100
/// </summary>
int LeetCodeHashtable::countQuadruplets(vector<int>& nums)
{
    unordered_map<int, vector<pair<int, int>>> pairs;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            pairs[nums[i] + nums[j]].push_back(make_pair(i, j));
        }
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            int sum = nums[j] - nums[i];
            if (pairs.count(sum) == 0) continue;
            for (size_t k = 0; k < pairs[sum].size(); k++)
            {
                if (pairs[sum][k].second >= (int)i) continue;
                result++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code 2032. Two Out of Three
///                                                
/// Easy
/// 
/// Given three integer arrays nums1, nums2, and nums3, return a distinct 
/// array containing all the values that are present in at least two out 
/// of the three arrays. You may return the values in any order.
///
/// Example 1:
/// Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
/// Output: [3,2]
/// Explanation: The values that are present in at least two arrays are:
/// - 3, in all three arrays.
/// - 2, in nums1 and nums2.
///
/// Example 2:
/// Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
/// Output: [2,3,1]
/// Explanation: The values that are present in at least two arrays are:
/// - 2, in nums2 and nums3.
/// - 3, in nums1 and nums2.
/// - 1, in nums1 and nums3.
///
/// Example 3:
/// Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
/// Output: []
/// Explanation: No value is present in at least two arrays.
///
/// Constraints:
/// 1. 1 <= nums1.length, nums2.length, nums3.length <= 100
/// 2. 1 <= nums1[i], nums2[j], nums3[k] <= 100
/// </summary>
vector<int> LeetCodeHashtable::twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
{
    vector<set<int>> set_map(101);
    vector<int> result;
    for (size_t i = 0; i < nums1.size(); i++)
    {
        set_map[nums1[i]].insert(1);
    }
    for (size_t i = 0; i < nums2.size(); i++)
    {
        set_map[nums2[i]].insert(2);
    }
    for (size_t i = 0; i < nums3.size(); i++)
    {
        set_map[nums3[i]].insert(3);
    }
    for (size_t i = 0; i < set_map.size(); i++)
    {
        if (set_map[i].size() >= 2) result.push_back(i);
    }
    return result;
}

/// <summary>
/// Leet code 1915. Number of Wonderful Substrings
///                                                
/// Medium
/// 
/// A wonderful string is a string where at most one letter appears an odd 
/// number of times.
///
/// For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
/// Given a string word that consists of the first ten lowercase English 
/// letters ('a' through 'j'), return the number of wonderful non-empty 
/// substrings in word. If the same substring appears multiple times in 
/// word, then count each occurrence separately.
///
/// A substring is a contiguous sequence of characters in a string.
/// 
/// Example 1:
/// Input: word = "aba"
/// Output: 4
/// Explanation: The four wonderful substrings are underlined below:
/// - "aba" -> "a"
/// - "aba" -> "b"
/// - "aba" -> "a"
/// - "aba" -> "aba"
///
/// Example 2:
/// Input: word = "aabb"
/// Output: 9
/// Explanation: The nine wonderful substrings are underlined below:
/// - "aabb" -> "a"
/// - "aabb" -> "aa"
/// - "aabb" -> "aab"
/// - "aabb" -> "aabb"
/// - "aabb" -> "a"
/// - "aabb" -> "abb"
/// - "aabb" -> "b"
/// - "aabb" -> "bb"
/// - "aabb" -> "b"
///
/// Example 3:
/// Input: word = "he"
/// Output: 2
/// Explanation: The two wonderful substrings are underlined below:
/// - "he" -> "h"
/// - "he" -> "e"
/// 
/// Constraints:
/// 1. 1 <= word.length <= 10^5
/// 2. word consists of lowercase English letters from 'a' to 'j'.
/// </summary>
long long LeetCodeHashtable::wonderfulSubstrings(string word)
{
    vector<int> str_count(2048);
    str_count[0] = 1;
    int bit_mask = 0;
    long long result = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        bit_mask ^= (1 << (word[i] - 'a'));
        result += str_count[bit_mask];
        
        for (int j = 0; j < 10; j++)
        {
            int target_mask = bit_mask ^ (1 << j);
            result += str_count[target_mask];
        }
        str_count[bit_mask] ++;
    }
    return result;
}

/// <summary>
/// Leet Code 2150. Find All Lonely Numbers in the Array
///                                                                 
/// Medium
///
/// You are given an integer array nums. A number x is lonely when it 
/// appears only once, and no adjacent numbers (i.e. x + 1 and x - 1) 
/// appear in the array.
///
/// Return all lonely numbers in nums. You may return the answer in 
/// any order.
///
/// Example 1:
/// Input: nums = [10,6,5,8]
/// Output: [10,8]
/// Explanation: 
/// - 10 is a lonely number since it appears exactly once and 9 and 11 
///  does not appear in nums.
/// - 8 is a lonely number since it appears exactly once and 7 and 9 
///   does not appear in nums.
/// - 5 is not a lonely number since 6 appears in nums and vice versa.
/// Hence, the lonely numbers in nums are [10, 8].
/// Note that [8, 10] may also be returned.
///
/// Example 2:
/// Input: nums = [1,3,5,3]
/// Output: [1,5]
/// Explanation: 
/// - 1 is a lonely number since it appears exactly once and 0 and 2 does 
///   not appear in nums.
/// - 5 is a lonely number since it appears exactly once and 4 and 6 
///   does not appear in nums.
/// - 3 is not a lonely number since it appears twice.
/// Hence, the lonely numbers in nums are [1, 5].
/// Note that [5, 1] may also be returned.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^6
/// </summary>
vector<int> LeetCodeHashtable::findLonely(vector<int>& nums)
{
    unordered_map<int, int> num_map;
    for (auto x : nums) num_map[x]++;
    
    vector<int> result;
    for (auto x : nums)
    { 
        if (num_map[x] == 1 && num_map.count(x - 1) == 0 && num_map.count(x + 1) == 0)
        {
            result.push_back(x);
        }
    }
    return result;
}
/// <summary>
/// Leet Code 2206. Divide Array Into Equal Pairs
///                                                                                   
/// Easy
///
/// You are given an integer array nums consisting of 2 * n integers.
/// You need to divide nums into n pairs such that:
///
/// Each element belongs to exactly one pair.
/// The elements present in a pair are equal.
/// Return true if nums can be divided into n pairs, otherwise return 
/// false.
/// 
/// Example 1:
/// Input: nums = [3,2,3,2,2,2]
/// Output: true
/// Explanation: 
/// There are 6 elements in nums, so they should be divided into 
/// 6 / 2 = 3 pairs.
/// If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will 
/// satisfy all the conditions.
///
/// Example 2:
/// Input: nums = [1,2,3,4]
/// Output: false
/// Explanation: 
/// There is no way to divide nums into 4 / 2 = 2 pairs such that the 
/// pairs satisfy every condition.
/// 
/// Constraints:
/// 1. nums.length == 2 * n
/// 2. 1 <= n <= 500
/// 3. 1 <= nums[i] <= 500
/// </summary>
bool LeetCodeHashtable::divideArray(vector<int>& nums)
{
    vector<int> count(501);
    for (size_t i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }
    for (int i = 1; i < 501; i++)
    {
        if (count[i] % 2 == 1) return false;
    }
    return true;
}

/// <summary>
/// Leet Code 2215. Find the Difference of Two Arrays
///                                                                                   
/// Easy
///
/// Given two 0-indexed integer arrays nums1 and nums2, return a list 
/// answer of size 2 where:
///
/// answer[0] is a list of all distinct integers in nums1 which are not 
/// present in nums2.
/// answer[1] is a list of all distinct integers in nums2 which are not 
/// present in nums1.
/// Note that the integers in the lists may be returned in any order.
/// 
/// Example 1:
/// Input: nums1 = [1,2,3], nums2 = [2,4,6]
/// Output: [[1,3],[4,6]]
/// Explanation:
/// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas 
/// nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, 
/// answer[0] = [1,3].
/// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas 
/// nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, 
/// answer[1] = [4,6].
///
/// Example 2:
/// Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
/// Output: [[3],[]]
/// Explanation:
/// For nums1, nums1[2] and nums1[3] are not present in nums2. Since 
/// nums1[2] == nums1[3], their value is only included once and 
/// answer[0] = [3].
/// Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
/// 
/// Constraints:
/// 1. 1 <= nums1.length, nums2.length <= 1000
/// 2. -1000 <= nums1[i], nums2[i] <= 1000
/// </summary>
vector<vector<int>> LeetCodeHashtable::findDifference(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    unordered_set<int> result1, result2;
    for (size_t i = 0; i < nums1.size(); i++)
    {
        if (set2.count(nums1[i]) == 0)
        {
            result1.insert(nums1[i]);
        }
    }
    for (size_t i = 0; i < nums2.size(); i++)
    {
        if (set1.count(nums2[i]) == 0)
        {
            result2.insert(nums2[i]);
        }
    }
    vector<vector<int>> result;
    result.push_back(vector<int>(result1.begin(), result1.end()));
    result.push_back(vector<int>(result2.begin(), result2.end()));
    return result;
}

/// <summary>
/// Leet Code 2244. Minimum Rounds to Complete All Tasks
///                                                                                   
/// Medium
/// 
/// You are given a 0-indexed integer array tasks, where tasks[i] 
/// represents the difficulty level of a task. In each round, you 
/// can complete either 2 or 3 tasks of the same difficulty level.
///
/// Return the minimum rounds required to complete all the tasks, 
/// or -1 if it is not possible to complete all the tasks.
///
/// Example 1:
/// Input: tasks = [2,2,3,3,2,4,4,4,4,4]
/// Output: 4
/// Explanation: To complete all the tasks, a possible plan is:
/// - In the first round, you complete 3 tasks of difficulty level 2. 
/// - In the second round, you complete 2 tasks of difficulty level 3. 
/// - In the third round, you complete 3 tasks of difficulty level 4. 
/// - In the fourth round, you complete 2 tasks of difficulty level 4.  
/// It can be shown that all the tasks cannot be completed in fewer 
/// than 4 rounds, so the answer is 4.
///
/// Example 2:
/// Input: tasks = [2,3,3]
/// Output: -1
/// Explanation: There is only 1 task of difficulty level 2, but in 
/// each round, you can only complete either 2 or 3 tasks of the 
/// same difficulty level. Hence, you cannot complete all the tasks, 
/// and the answer is -1.
/// 
/// Constraints:
/// 1. 1 <= tasks.length <= 10^5
/// 2. 1 <= tasks[i] <= 10^9
/// </summary>
int LeetCodeHashtable::minimumRounds(vector<int>& tasks)
{
    unordered_map<int, int> task_count;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        task_count[tasks[i]]++;
    }
    int result = 0;
    for (auto itr : task_count)
    {
        if (itr.second == 1) return -1;
        if (itr.second % 3 == 0)
        {
            result += itr.second / 3;
        }
        else if (itr.second % 3 == 2)
        {
            result += itr.second / 3 + 1;
        }
        else if (itr.second % 3 == 1)
        {
            result += itr.second / 3 - 1;
            result += 2;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2248. Intersection of Multiple Arrays
///                                                                                      
/// Easy
/// 
/// Given a 2D integer array nums where nums[i] is a non-empty array of 
/// distinct positive integers, return the list of integers that are 
/// present	in each array of nums sorted in ascending order.
/// 
/// Example 1:
/// Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
/// Output: [3,4]
/// Explanation: 
/// The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = 
/// [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
///
/// Example 2:
/// Input: nums = [[1,2,3],[4,5,6]]
/// Output: []
/// Explanation: 
/// There does not exist any integer present both in nums[0] and nums[1], 
/// so we return an empty list [].
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. 1 <= sum(nums[i].length) <= 1000
/// 3. 1 <= nums[i][j] <= 1000
/// 4. All the values of nums[i] are unique.
/// </summary>
vector<int> LeetCodeHashtable::intersection(vector<vector<int>>& nums)
{
    vector<int> num_map(1001);
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums[i].size(); j++)
        num_map[nums[i][j]]++;
    }
    vector<int> result;
    for (size_t i = 1; i < num_map.size(); i++)
    {
        if (num_map[i] == nums.size())
        {
            result.push_back(i);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2295. Replace Elements in an Array
///                                                           
/// Medium
/// 
/// You are given a 0-indexed array nums that consists of n distinct 
/// positive integers. Apply m operations to this array, where in 
/// the ith operation you replace the number operations[i][0] with 
/// operations[i][1].
///
/// It is guaranteed that in the ith operation:
/// 
/// operations[i][0] exists in nums.
/// operations[i][1] does not exist in nums.
/// Return the array obtained after applying all the operations.
///  
/// Example 1:
/// Input: nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
/// Output: [3,2,7,1]
/// Explanation: We perform the following operations on nums:
/// - Replace the number 1 with 3. nums becomes [3,2,4,6].
/// - Replace the number 4 with 7. nums becomes [3,2,7,6].
/// - Replace the number 6 with 1. nums becomes [3,2,7,1].
/// We return the final array [3,2,7,1].
///
/// Example 2:
/// Input: nums = [1,2], operations = [[1,3],[2,1],[3,2]]
/// Output: [2,1]
/// Explanation: We perform the following operations to nums:
 /// - Replace the number 1 with 3. nums becomes [3,2].
/// - Replace the number 2 with 1. nums becomes [3,1].
/// - Replace the number 3 with 2. nums becomes [2,1].
/// We return the array [2,1].
///
/// Constraints:
/// 1. n == nums.length
/// 2. m == operations.length
/// 3. 1 <= n, m <= 10^5
/// 4. All the values of nums are distinct.
/// 5. operations[i].length == 2
/// 6. 1 <= nums[i], operations[i][0], operations[i][1] <= 10^6
/// 7. operations[i][0] will exist in nums when applying the ith operation.
/// 8. operations[i][1] will not exist in nums when applying the ith 
///    operation.
/// </summary>
vector<int> LeetCodeHashtable::arrayChange(vector<int>& nums, vector<vector<int>>& operations)
{
    unordered_map<int, int> num_map;
    for (int i = operations.size() - 1; i >= 0; i--)
    {
        if (num_map.count(operations[i][1]) == 0)
        {
            num_map[operations[i][0]] = operations[i][1];
        }
        else
        {
            num_map[operations[i][0]] = num_map[operations[i][1]];
        }
    }
    vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (num_map.count(nums[i]) > 0)
        {
            result[i] = num_map[nums[i]];
        }
        else
        {
            result[i] = nums[i];
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2342. Max Sum of a Pair With Equal Sum of Digits
///                                                           
/// Medium
///
/// You are given a 0-indexed array nums consisting of positive integers. 
/// You can choose two indices i and j, such that i != j, and the sum of 
/// digits of the number nums[i] is equal to that of nums[j].
///
/// Return the maximum value of nums[i] + nums[j] that you can obtain 
/// over all possible indices i and j that satisfy the conditions.
///
/// Example 1:
/// Input: nums = [18,43,36,13,7]
/// Output: 54
/// Explanation: The pairs (i, j) that satisfy the conditions are:
/// - (0, 2), both numbers have a sum of digits equal to 9, and their 
///   sum is 18 + 36 = 54.
/// - (1, 4), both numbers have a sum of digits equal to 7, and their 
///   sum is 43 + 7 = 50.
/// So the maximum sum that we can obtain is 54.
///
/// Example 2:
/// Input: nums = [10,12,19,14]
/// Output: -1
/// Explanation: There are no two numbers that satisfy the conditions, 
/// so we return -1.
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^9
/// </summary>
int LeetCodeHashtable::maximumSum(vector<int>& nums)
{
    unordered_map<int, priority_queue<int>> num_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        int num = nums[i];
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num_map[sum].push(nums[i]);
    }
    int result = -1;
    for (auto itr : num_map)
    {
        if (itr.second.size() >= 2)
        {
            int sum = itr.second.top();
            itr.second.pop();
            sum += itr.second.top();
            itr.second.pop();
            result = max(result, sum);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2347. Best Poker Hand
///                                                           
/// Easy
///
/// You are given an integer array ranks and a character array suits. 
/// You have 5 cards where the ith card has a rank of ranks[i] and a 
/// suit of suits[i].
///
/// The following are the types of poker hands you can make from best 
/// to worst:
///
/// "Flush": Five cards of the same suit.
/// "Three of a Kind": Three cards of the same rank.
/// "Pair": Two cards of the same rank.
/// "High Card": Any single card.
/// Return a string representing the best type of poker hand you can 
/// make with the given cards.
///
/// Note that the return values are case-sensitive.
/// 
/// Example 1:
/// Input: ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
/// Output: "Flush"
/// Explanation: The hand with all the cards consists of 5 cards with 
/// the same suit, so we have a "Flush".
///
/// Example 2:
/// Input: ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
/// Output: "Three of a Kind"
/// Explanation: The hand with the first, second, and fourth card consists 
/// of 3 cards with the same rank, so we have a "Three of a Kind".
/// Note that we could also make a "Pair" hand but "Three of a Kind" is a 
/// better hand.
/// Also note that other cards could be used to make the "Three of a Kind" 
/// hand.
///
/// Example 3:
/// Input: ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
/// Output: "Pair"
/// Explanation: The hand with the first and second card consists of 2 cards 
/// with the same rank, so we have a "Pair".
/// Note that we cannot make a "Flush" or a "Three of a Kind".
///
/// Constraints:
/// 1. ranks.length == suits.length == 5
/// 2. 1 <= ranks[i] <= 13
/// 3. 'a' <= suits[i] <= 'd'
/// 4. No two cards have the same rank and suit.
/// </summary>
string LeetCodeHashtable::bestHand(vector<int>& ranks, vector<char>& suits)
{
    unordered_map<int, int> rank_count;
    unordered_map<char, int> suit_count;

    for (size_t i = 0; i < ranks.size(); i++)
    {
        rank_count[ranks[i]]++;
        suit_count[suits[i]]++;
    }
    string result;
    if (suit_count.size() == 1)
    {
        result = "Flush";
    }
    else
    {
        for (auto& itr : rank_count)
        {
            if (itr.second >= 3)
            {
                result = "Three of a Kind";
            }
            else if (itr.second == 2 && result.empty())
            {
                result = "Pair";
            }
        }
    }
    if (result.empty()) result = "High Card";
    return result;
}

/// <summary>
/// Leet Code 2441. Largest Positive Integer That Exists With Its Negative           
///                                                  
/// Easy
///
/// Given an integer array nums that does not contain any zeros, find the 
/// largest positive integer k such that -k also exists in the array.
///
/// Return the positive integer k. If there is no such integer, return -1.
///
/// Example 1:
/// Input: nums = [-1,2,-3,3]
/// Output: 3
/// Explanation: 3 is the only valid k we can find in the array.
///
/// Example 2:
/// Input: nums = [-1,10,6,7,-7,1]
/// Output: 7
/// Explanation: Both 1 and 7 have their corresponding negative values 
/// in the array. 7 has a larger value.
///
/// Example 3:
/// Input: nums = [-10,8,6,7,-2,-3]
/// Output: -1
/// Explanation: There is no a single valid k, we return -1.
///
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. -1000 <= nums[i] <= 1000
/// 3. nums[i] != 0
/// </summary>
int LeetCodeHashtable::findMaxK(vector<int>& nums)
{
    unordered_set<int> data_set = unordered_set<int>(nums.begin(), nums.end());
    int result = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > result && nums[i] > 0 && data_set.count(-nums[i]) > 0)
        {
            result = nums[i];
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2442. Count Number of Distinct Integers After Reverse 
///                 Operations           
///                                                  
/// Medium
///
/// You are given an array nums consisting of positive integers.
///
/// You have to take each integer in the array, reverse its digits, 
/// and add it to the end of the array. You should apply this operation 
/// to the original integers in nums.
///
/// Return the number of distinct integers in the final array.
/// 
/// Example 1:
/// Input: nums = [1,13,10,12,31]
/// Output: 6
/// Explanation: After including the reverse of each number, the 
/// resulting array is [1,13,10,12,31,1,31,1,21,13].
/// The reversed integers that were added to the end of the array are 
/// underlined. Note that for the integer 10, after reversing it, it 
/// becomes 01 which is just 1.
/// The number of distinct integers in this array is 6 (The 
/// numbers 1, 10, 12, 13, 21, and 31).
///
/// Example 2:
/// Input: nums = [2,2,2]
/// Output: 1
/// Explanation: After including the reverse of each number, the 
/// resulting array is [2,2,2,2,2,2].
/// The number of distinct integers in this array is 1 (The number 2).
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^6
/// </summary>
int LeetCodeHashtable::countDistinctIntegers(vector<int>& nums)
{
    set<int> data_set;
    for (size_t i = 0; i < nums.size(); i++)
    {
        data_set.insert(nums[i]);
        string str = to_string(nums[i]);
        reverse(str.begin(), str.end());
        data_set.insert(atoi(str.c_str()));
    }
    return data_set.size();
}

/// <summary>
/// Leet Code 2456. Most Popular Video Creator 
///                                                  
/// Medium
///
/// You are given two string arrays creators and ids, and an integer 
/// array views, all of length n. The ith video on a platform was created 
/// by creator[i], has an id of ids[i], and has views[i] views.
///
/// The popularity of a creator is the sum of the number of views on all 
/// of the creator's videos. Find the creator with the highest popularity 
/// and the id of their most viewed video.
///
/// If multiple creators have the highest popularity, find all of them.
/// If multiple videos have the highest view count for a creator, find 
/// the lexicographically smallest id.
/// Return a 2D array of strings answer where answer[i] = [creatori, idi] 
/// means that creatori has the highest popularity and idi is the id of 
/// their most popular video. The answer can be returned in any order.
/// Example 1:
/// Input: creators = ["alice","bob","alice","chris"], ids = 
/// ["one","two","three","four"], views = [5,10,5,4]
/// Output: [["alice","one"],["bob","two"]]
/// Explanation:
/// The popularity of alice is 5 + 5 = 10.
/// The popularity of bob is 10.
/// The popularity of chris is 4.
/// alice and bob are the most popular creators.
/// For bob, the video with the highest view count is "two".
/// For alice, the videos with the highest view count are "one" and 
/// "three". Since "one" is lexicographically smaller than "three", 
/// it is included in the answer.
///
/// Example 2:
///
/// Input: creators = ["alice","alice","alice"], ids = ["a","b","c"], 
///        views = [1,2,2]
/// Output: [["alice","b"]]
/// Explanation:
/// The videos with id "b" and "c" have the highest view count.
/// Since "b" is lexicographically smaller than "c", it is included in 
/// the answer.
/// 
/// Constraints:
/// 1. n == creators.length == ids.length == views.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= creators[i].length, ids[i].length <= 5
/// 4. creators[i] and ids[i] consist only of lowercase English letters.
/// 5. 0 <= views[i] <= 10^5
/// </summary>
vector<vector<string>> LeetCodeHashtable::mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views)
{
    unordered_map<string, long long> score;
    unordered_map<string, pair<string, int>> popular;
    int n = creators.size();
    long long max_score = 0;
    for (int i = 0; i < n; i++)
    {
        string creator = creators[i];
        score[creator] += views[i];
        max_score = max(max_score, score[creator]);
        if (popular.count(creator) == 0 || 
            views[i] > popular[creator].second ||
            (views[i] == popular[creator].second && ids[i] < popular[creator].first))
        {
            popular[creator].first = ids[i];
            popular[creator].second = views[i];
        }
    }
    vector<vector<string>> result;
    for (auto itr : score)
    {
        if (itr.second == max_score)
        {
            string creator = itr.first;
            result.push_back({ creator, popular[creator].first });
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2657. Find the Prefix Common Array of Two Arrays
/// 
/// Medium
///	
/// You are given two 0-indexed integer permutations A and B of length n.
///
/// A prefix common array of A and B is an array C such that C[i] is equal 
/// to the count of numbers that are present at or before the index i in 
/// both A and B.
///
/// Return the prefix common array of A and B.
///
/// A sequence of n integers is called a permutation if it contains all 
/// integers from 1 to n exactly once.
/// 
/// Example 1:
/// Input: A = [1,3,2,4], B = [3,1,2,4]
/// Output: [0,2,3,4]
/// Explanation: At i = 0: no number is common, so C[0] = 0.
/// At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
/// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
/// At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
///
/// Example 2:
/// Input: A = [2,3,1], B = [3,1,2]
/// Output: [0,1,3]
/// Explanation: At i = 0: no number is common, so C[0] = 0.
/// At i = 1: only 3 is common in A and B, so C[1] = 1.
/// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
///
/// Constraints:
/// 1. 1 <= A.length == B.length == n <= 50
/// 2. 1 <= A[i], B[i] <= n
/// 3. It is guaranteed that A and B are both a permutation of n integers.
/// </summary>
vector<int> LeetCodeHashtable::findThePrefixCommonArray(vector<int>& A, vector<int>& B)
{
    unordered_map<int, int> num_count;
    vector<int> result(A.size());
    int sum = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        num_count[A[i]]++;
        if (num_count[A[i]] > 1) sum++;
        num_count[B[i]]++;
        if (num_count[B[i]] > 1) sum++;
        result[i] = sum;
    }
    return result;
}

/// <summary>
/// Leet Code 2670. Find the Distinct Difference Array
/// 
/// Easy
///	
/// You are given a 0-indexed array nums of length n.
///
/// The distinct difference array of nums is an array diff of length n 
/// such that diff[i] is equal to the number of distinct elements in 
/// the suffix nums[i + 1, ..., n - 1] subtracted from the number of 
/// distinct elements in the prefix nums[0, ..., i].
///
/// Return the distinct difference array of nums.
///
/// Note that nums[i, ..., j] denotes the subarray of nums starting 
/// at index i and ending at index j inclusive. Particularly, if i > j 
/// then nums[i, ..., j] denotes an empty subarray.
///
/// Example 1:
/// Input: nums = [1,2,3,4,5]
/// Output: [-3,-1,1,3,5]
/// Explanation: For index i = 0, there is 1 element in the prefix 
/// and 4 distinct elements in the suffix. Thus, diff[0] = 1 - 4 = -3.
/// For index i = 1, there are 2 distinct elements in the prefix and 3 
/// distinct elements in the suffix. Thus, diff[1] = 2 - 3 = -1.
/// For index i = 2, there are 3 distinct elements in the prefix and 2 
/// distinct elements in the suffix. Thus, diff[2] = 3 - 2 = 1.
/// For index i = 3, there are 4 distinct elements in the prefix and 1 
/// distinct element in the suffix. Thus, diff[3] = 4 - 1 = 3.
/// For index i = 4, there are 5 distinct elements in the prefix and 
/// no elements in the suffix. Thus, diff[4] = 5 - 0 = 5.
///
/// Example 2:
/// Input: nums = [3,2,3,4,2]
/// Output: [-2,-1,0,2,3]
/// Explanation: For index i = 0, there is 1 element in the prefix 
/// and 3 distinct elements in the suffix. Thus, diff[0] = 1 - 3 = -2.
/// For index i = 1, there are 2 distinct elements in the prefix and 3 
/// distinct elements in the suffix. Thus, diff[1] = 2 - 3 = -1.
/// For index i = 2, there are 2 distinct elements in the prefix and 2 
/// distinct elements in the suffix. Thus, diff[2] = 2 - 2 = 0.
/// For index i = 3, there are 3 distinct elements in the prefix and 1 
/// distinct element in the suffix. Thus, diff[3] = 3 - 1 = 2.
/// For index i = 4, there are 3 distinct elements in the prefix and 
/// no elements in the suffix. Thus, diff[4] = 3 - 0 = 3.
/// 
/// Constraints:
/// 1. 1 <= n == nums.length <= 50 
/// 2. 1 <= nums[i] <= 50
/// </summary>
vector<int> LeetCodeHashtable::distinctDifferenceArray(vector<int>& nums)
{
    vector<int> result(nums.size());
    unordered_map<int, int> prefix, suffix;
    for (size_t i = 0; i < nums.size(); i++)
    {
        suffix[nums[i]]++;
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        prefix[nums[i]]++;
        suffix[nums[i]]--;
        if (suffix[nums[i]] == 0) suffix.erase(nums[i]);
        result[i] = prefix.size() - suffix.size();
    }
    return result;
}

/// <summary>
/// Leet Code 2766. Relocate Marbles
/// 
/// Medium
///
/// You are given a 0-indexed integer array nums representing the initial 
/// positions of some marbles. You are also given two 0-indexed integer 
/// arrays moveFrom and moveTo of equal length.
///
/// Throughout moveFrom.length steps, you will change the positions of 
/// the marbles. On the ith step, you will move all marbles at position 
/// moveFrom[i] to position moveTo[i].
///
/// After completing all the steps, return the sorted list of occupied 
/// positions.
///
/// Notes:
///
/// We call a position occupied if there is at least one marble in that 
/// position.
/// There may be multiple marbles in a single position.
///
/// Example 1:
/// Input: nums = [1,6,7,8], moveFrom = [1,7,2], moveTo = [2,9,5]
/// Output: [5,6,8,9]
/// Explanation: Initially, the marbles are at positions 1,6,7,8.
/// At the i = 0th step, we move the marbles at position 1 to position 2. 
/// Then, positions 2,6,7,8 are occupied.
/// At the i = 1st step, we move the marbles at position 7 to position 9. 
/// Then, positions 2,6,8,9 are occupied.
/// At the i = 2nd step, we move the marbles at position 2 to position 5. 
/// Then, positions 5,6,8,9 are occupied.
/// At the end, the final positions containing at least one marbles 
/// are [5,6,8,9].
///
/// Example 2:
///
/// Input: nums = [1,1,3,3], moveFrom = [1,3], moveTo = [2,2]
/// Output: [2]
/// Explanation: Initially, the marbles are at positions [1,1,3,3].
/// At the i = 0th step, we move all the marbles at position 1 to 
/// position 2. Then, the marbles are at positions [2,2,3,3].
/// At the i = 1st step, we move all the marbles at position 3 to 
/// position 2. Then, the marbles are at positions [2,2,2,2].
/// Since 2 is the only occupied position, we return [2].
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= moveFrom.length <= 10^5
/// 3. moveFrom.length == moveTo.length
/// 4. 1 <= nums[i], moveFrom[i], moveTo[i] <= 10^9
/// 5. The test cases are generated such that there is at least a marble 
///    in moveFrom[i] at the moment we want to apply the ith move.
/// </summary>
vector<int> LeetCodeHashtable::relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo)
{
    set<int> num_set = set<int>(nums.begin(), nums.end());
    for (size_t i = 0; i < moveFrom.size(); i++)
    {
        if (num_set.count(moveFrom[i]) > 0)
        {
            num_set.erase(moveFrom[i]);
            num_set.insert(moveTo[i]);
        }
    }
    vector<int> result;
    for (auto x : num_set) result.push_back(x);
    
    return result;
}

/// <summary>
/// Leet 2815. Max Pair Sum in an Array
/// 
/// Easy
///
/// You are given a 0-indexed integer array nums. You have to find the 
/// maximum sum of a pair of numbers from nums such that the maximum 
/// digit in both numbers are equal.
///
/// Return the maximum sum or -1 if no such pair exists.
/// 
/// Example 1:
/// Input: nums = [51,71,17,24,42]
/// Output: 88
/// Explanation: 
/// For i = 1 and j = 2, nums[i] and nums[j] have equal maximum digits 
/// with a pair sum of 71 + 17 = 88. 
/// For i = 3 and j = 4, nums[i] and nums[j] have equal maximum digits 
/// with a pair sum of 24 + 42 = 66.
/// It can be shown that there are no other pairs with equal maximum 
/// digits, so the answer is 88.
///
/// Example 2:
/// Input: nums = [1,2,3,4]
/// Output: -1
/// Explanation: No pair exists in nums with equal maximum digits.
/// 
/// Constraints:
/// 1. 2 <= nums.length <= 100
/// 2. 1 <= nums[i] <= 10^4
/// </summary>
int LeetCodeHashtable::maxSum(vector<int>& nums)
{
    unordered_map<int, int> sum;
    int result = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        int digit_max = 0;
        while (n > 0)
        {
            digit_max = max(digit_max, n % 10);
            n /= 10;
        }
        if (sum.count(digit_max) > 0)
        {
            result = max(result, sum[digit_max] + nums[i]);
        }
        if (nums[i] > sum[digit_max]) sum[digit_max] = nums[i];
    }
    return result;
}

/// <summary>
/// Leet Code 2829. Determine the Minimum Sum of a k-avoiding Array
/// 
/// Medium
///
/// You are given two integers, n and k.
///
/// An array of distinct positive integers is called a k-avoiding array 
/// if there does not exist any pair of distinct elements that sum to k.
///
/// Return the minimum possible sum of a k-avoiding array of length n.
///
/// Example 1:
/// Input: n = 5, k = 4
/// Output: 18
/// Explanation: Consider the k-avoiding array [1,2,4,5,6], which has a 
/// sum of 18.
/// It can be proven that there is no k-avoiding array with a sum less 
/// than 18.
///
/// Example 2:
/// Input: n = 2, k = 6
/// Output: 3
/// Explanation: We can construct the array [1,2], which has a sum of 3.
/// It can be proven that there is no k-avoiding array with a sum less 
/// than 3.
///
/// Constraints:
/// 1. 1 <= n, k <= 50
/// </summary>
int LeetCodeHashtable::minimumSum(int n, int k)
{
    unordered_set<int> avoid;
    int result = 0;
    int count = 0;
    int num = 0;
    while (count < n)
    {
        num++;
        if (avoid.count(num) == 0)
        {
            count++;
            result += num;
            if (num < k) avoid.insert(k - num);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2834. Find the Minimum Possible Sum of a Beautiful Array
/// 
/// Medium
///
/// You are given positive integers n and target.
///
/// An array nums is beautiful if it meets the following conditions:
///
/// nums.length == n.
/// nums consists of pairwise distinct positive integers.
/// There doesn't exist two distinct indices, i and j, in the range 
/// [0, n - 1], such that nums[i] + nums[j] == target.
/// Return the minimum possible sum that a beautiful array could 
/// have.
///
/// Example 1:
/// Input: n = 2, target = 3
/// Output: 4
/// Explanation: We can see that nums = [1,3] is beautiful.
/// - The array nums has length n = 2.
/// - The array nums consists of pairwise distinct positive integers.
/// - There doesn't exist two distinct indices, i and j, with 
///   nums[i] + nums[j] == 3.
/// It can be proven that 4 is the minimum possible sum that a beautiful 
/// array could have.
///
/// Example 2:
/// Input: n = 3, target = 3
/// Output: 8
/// Explanation: We can see that nums = [1,3,4] is beautiful.
/// - The array nums has length n = 3.
/// - The array nums consists of pairwise distinct positive integers.
/// - There doesn't exist two distinct indices, i and j, with 
///   nums[i] + nums[j] == 3.
/// It can be proven that 8 is the minimum possible sum that a beautiful 
/// array could have.
///
/// Example 3:
/// Input: n = 1, target = 1
/// Output: 1
/// Explanation: We can see, that nums = [1] is beautiful.
/// 
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 1 <= target <= 10^5
/// </summary>
long long LeetCodeHashtable::minimumPossibleSum(int n, int target)
{
    unordered_set<int> forbidden;
    int count = 0;
    int num = 1;
    long long result = 0;
    while (count < n)
    {
        if (forbidden.count(num) == 0)
        {
            result += (long long)num;
            if (target - num > 0) forbidden.insert(target - num);
            count++;
        }
        num++;
    }
    return result;
}

/// <summary>
/// Leet Code 2857. Count Pairs of Points With Distance k
/// 
/// Medium
///
/// You are given a 2D integer array coordinates and an integer k, where 
/// coordinates[i] = [xi, yi] are the coordinates of the ith point in a 
/// 2D plane.
///
/// We define the distance between two points (x1, y1) and (x2, y2) as 
/// (x1 XOR x2) + (y1 XOR y2) where XOR is the bitwise XOR operation.
///
/// Return the number of pairs (i, j) such that i < j and the distance 
/// between points i and j is equal to k.
///
/// Example 1:
/// Input: coordinates = [[1,2],[4,2],[1,3],[5,2]], k = 5
/// Output: 2
/// Explanation: We can choose the following pairs:
/// - (0,1): Because we have (1 XOR 4) + (2 XOR 2) = 5.
/// - (2,3): Because we have (1 XOR 5) + (3 XOR 2) = 5.
///
/// Example 2:
/// Input: coordinates = [[1,3],[1,3],[1,3],[1,3],[1,3]], k = 0
/// Output: 10
/// Explanation: Any two chosen pairs will have a distance of 0. There 
/// are 10 ways to choose two pairs.
/// Constraints:
/// 1. 2 <= coordinates.length <= 50000
/// 2. 0 <= xi, yi <= 10^6
/// 3. 0 <= k <= 100
/// 4. You are given a 0-indexed sorted array of integers nums.
/// </summary>
int LeetCodeHashtable::countPairs(vector<vector<int>>& coordinates, int k)
{
    unordered_map<int, unordered_map<int, int>> coord_count;
    int result = 0;
    for (size_t i = 0; i < coordinates.size(); i++)
    {
        int x1 = coordinates[i][0];
        int y1 = coordinates[i][1];
        for (int i = 0; i <= k; i++)
        {
            int x2 = i ^ x1;
            int y2 = (k - i) ^ y1;
            if (coord_count.count(x2) > 0)
            {
                if (coord_count[x2].count(y2) > 0)
                {
                    result += coord_count[x2][y2];
                }
            }
        }
        coord_count[x1][y1]++;
    }
    return result;
}

/// <summary>
/// Leet Code 2870. Minimum Number of Operations to Make Array Empty
/// 
/// Medium
/// 
/// You are given a 0-indexed array nums consisting of positive integers.
///
/// There are two types of operations that you can apply on the array any 
/// number of times:
///
/// Choose two elements with equal values and delete them from the array.
/// Choose three elements with equal values and delete them from the array.
/// Return the minimum number of operations required to make the array 
/// empty, or -1 if it is not possible.
/// 
/// Example 1:
/// Input: nums = [2,3,3,2,2,4,2,3,4]
/// Output: 4
/// Explanation: We can apply the following operations to make the array 
/// empty:
/// - Apply the first operation on the elements at indices 0 and 3. The 
///   resulting array is nums = [3,3,2,4,2,3,4].
/// - Apply the first operation on the elements at indices 2 and 4. The 
///   resulting array is nums = [3,3,4,3,4].
/// - Apply the second operation on the elements at indices 0, 1, and 3. 
///   The resulting array is nums = [4,4].
/// - Apply the first operation on the elements at indices 0 and 1. The 
///   resulting array is nums = [].
/// It can be shown that we cannot make the array empty in less than 4 
/// operations.
///
/// Example 2:
/// Input: nums = [2,1,2,2,3,3]
/// Output: -1
/// Explanation: It is impossible to empty the array.
///
/// Constraints:
/// 1. 2 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^6
/// </summary>
int LeetCodeHashtable::minOperations(vector<int>& nums)
{
    int result = 0;
    unordered_map<int, int> num_count;
    for (size_t i = 0; i < nums.size(); i++)
    {
        num_count[nums[i]]++;
    }
    for (auto itr : num_count)
    {
        if (itr.second == 1) return -1;
        else if (itr.second % 3 == 0)
        {
            result += itr.second / 3;
        }
        else if (itr.second % 3 == 2)
        {
            result += (itr.second - 2) / 3 + 1;
        }
        else if (itr.second % 3 == 1)
        {
            result += (itr.second - 4) / 3 + 2;
        }
    }
    return result;
}

#pragma endregion
