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
#include "LeetCodeString.h"
#pragma region String
/// <summary>
/// Leet code #3. Longest Substring Without Repeating Characters
/// Given a string, find the length of the longest substring without 
/// repeating characters.
/// Examples:
/// Given "abcabcbb", the answer is "abc", which the length is 3.
/// Given "bbbbb", the answer is "b", with the length of 1.
/// Given "pwwkew", the answer is "wke", with the length of 3. 
/// Note that the answer must be a substring, "pwke" is a subsequence 
/// and not a substring.
/// </summary>
int LeetCodeString::lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> char_count;
    int begin = -1;
    int result = 0;
    for (int end = 0; end < (int)s.size(); end++)
    {
        char_count[s[end]]++;
        while (char_count[s[end]] > 1)
        {
            begin++;
            char_count[s[begin]]--;
        }
        result = max(result, end - begin);
    }
    return result;
}

/// <summary>
/// Leet code #30. Substring with Concatenation of All Words 
/// You are given a string, s, and a list of words, words, that are all of 
/// the same length. Find all starting indices of 
/// substring(s) in s that is a concatenation of each word in words exactly 
///  once and without any intervening characters. 
/// For example, given:
/// s: "barfoothefoobarman"
/// words: ["foo", "bar"] 
/// You should return the indices: [0,9].
/// </summary> 
vector<int> LeetCodeString::findSubstring(string s, vector<string>& words)
{
    vector<int> result;
    unsigned int checksum_words = 0;
    unsigned int checksum = 0;
    unordered_map<string, int> word_map;
    size_t word_len = 0;
    size_t total_len = 0;

    if (words.size() == 0)
    {
        return result;
    }

    for (size_t i = 0; i < words.size(); i++)
    {
        word_len = words[i].size();
        word_map[words[i]]++;
        for (size_t j = 0; j < word_len; j++)
        {
            checksum_words += (unsigned int)words[i][j];
        }
        total_len += word_len;
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        checksum += (unsigned int)s[i];
        if (i >= total_len) checksum -= (unsigned int)s[i - total_len];
        // check sum not match, no way to match
        if ((i < total_len - 1) || (checksum != checksum_words)) continue;
        size_t index = i - total_len + 1;
        unordered_map<string, int> word_seen;
        while (index <= i)
        {
            string word = s.substr(index, word_len);
            if (word_map.find(word) == word_map.end())
            {
                break;
            }
            word_seen[word]++;
            if (word_seen[word] > word_map[word]) break;
            index += word_len;
        }
        if (index > i)
        {
            result.push_back(i - total_len + 1);
        }
    }
    return result;
}

/// <summary>
/// Leet code #139. Word Break
/// 
/// Medium
///
/// Given a non-empty string s and a dictionary wordDict containing a 
/// list of non-empty words, determine if s can be segmented into a 
/// space-separated sequence of one or more dictionary words.
///
/// Note:
///
/// The same word in the dictionary may be reused multiple times in 
/// the segmentation.
/// You may assume the dictionary does not contain duplicate words.
///
/// Example 1:
/// Input: s = "leetcode", wordDict = ["leet", "code"]
/// Output: true
/// Explanation: Return true because "leetcode" can be segmented 
/// as "leet code".
///
/// Example 2:
/// Input: s = "applepenapple", wordDict = ["apple", "pen"]
/// Output: true
/// Explanation: Return true because "applepenapple" can be segmented 
/// as "apple pen apple".Note that you are allowed to reuse a dictionary
/// word.
///
/// Example 3:
/// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
/// Output: false
/// </summary>
bool LeetCodeString::wordBreak(string s, vector<string>& wordDict)
{
    if (s.empty()) return false;
    size_t max_len = 0;
    unordered_set<string> dict;
    for (size_t i = 0; i < wordDict.size(); i++)
    {
        max_len = max(max_len, wordDict[i].size());
        dict.insert(wordDict[i]);
    }

    vector<bool> dp(s.size(), false);
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 1; j <= max_len; j++)
        {
            if (i < j - 1) break;
            int pos = i - (j - 1);
            string str = s.substr(pos, j);
            if (dict.count(str) > 0)
            {
                if (pos == 0 || dp[pos - 1] == 1)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.size() - 1];
}

/// <summary>
/// Leet code #151. Reverse Words in a String
/// Given an input string, reverse the string word by word. 
/// For example,
///   Given s = "the sky is blue",
///   return "blue is sky the". 
/// Update (2015-02-12):
/// For C programmers: Try to solve it in-place in O(1) space. 
/// </summary>
string LeetCodeString::reverseWords(string s)
{
    // The first iteration reverse every single character
    std::reverse(s.begin(), s.end());

    // start from begining of the sentence
    size_t begin = 0; 
    size_t end = 0;
    int pos = -1;
    while (begin < s.size())
    {
        // either end hit end or hit a space, we got a word
        if ((!isspace(s[begin])) && ((end == s.size()) || (isspace(s[end]))))
        {
            std::reverse(s.begin() + begin, s.begin() + end);
            pos++;
            for (size_t i = begin; i < end; i++, pos++)
            {
                s[pos] = s[i];
            }
            if (pos < (int)s.size()) s[pos] = ' ';
            begin = end;
            end = begin + 1;
        }
        else if ((isspace(s[begin])) && (begin < s.size()))
        {
            begin++;
            end = begin + 1;
        }
        else if ((!isspace(s[end])) && (end < s.size()))
        {
            end++;
        }
    }
    if (pos != -1) s.resize(pos);
    else s.clear();
    return s;
}

/// <summary>
/// Leet code #186. Reverse Words in a String II  
/// 
/// Given an input string, reverse the string word by word. A word is defined 
/// as a sequence of non-space characters. 
/// The input string does not contain leading or trailing spaces and the words 
/// are always separated by a single space.  
/// For example,
/// Given s = "the sky is blue",
/// return "blue is sky the".
/// Could you do it in-place without allocating extra space? 
/// </summary>
void LeetCodeString::reverseWordsII(string &s)
{
    std::reverse(s.begin(), s.end());
    // start from begining of the sentence
    size_t begin = 0;
    size_t end = 0;
    while (begin < s.size())
    {
        // either end hit end or hit a space, we got a word
        if ((!isspace(s[begin])) && ((end == s.size()) || (isspace(s[end]))))
        {
            std::reverse(s.begin() + begin, s.begin() + end);
            begin = end;
            end = begin + 1;
        }
        else if ((isspace(s[begin])) && (begin < s.size()))
        {
            begin++;
            end = begin + 1;
        }
        else if ((!isspace(s[end])) && (end < s.size()))
        {
            end++;
        }
    }
}

/// <summary>
/// Leet code #14. Longest Common Prefix 
///
/// Write a function to find the longest common prefix string amongst 
/// an array of strings. 
/// </summary>
string LeetCodeString::longestCommonPrefix(vector<string>& strs)
{
    string commonPrefix;
    for (size_t i = 0; i < strs.size(); i++)
    {
        string word = strs[i];
        if (i == 0)
        {
            commonPrefix = word;
        }
        else
        {
            size_t i;
            for (i = 0; i < commonPrefix.size(); i++)
            {
                if ((i == word.size()) || (commonPrefix[i] != word[i]))
                {
                    break;
                }
            }
            commonPrefix = commonPrefix.substr(0, i);
        }
    }
    return commonPrefix;
}

/// <summary>
/// Leet code #28. Implement strStr()
///
/// Easy
///
/// Implement strStr().
///
/// Return the index of the first occurrence of needle in haystack, or -1 
/// if needle is not part of haystack.
///
/// Example 1:
///
/// Input: haystack = "hello", needle = "ll"
/// Output: 2
///
/// Example 2:
///
/// Input: haystack = "aaaaa", needle = "bba"
/// Output: -1
/// Clarification:
///
/// What should we return when needle is an empty string? This is a great 
/// question to ask during an interview.
///
/// For the purpose of this problem, we will return 0 when needle is an empty 
/// string. This is consistent to C's strstr() and Java's indexOf().
/// </summary>
int LeetCodeString::strStr(string haystack, string needle)
{
    if (haystack.size() < needle.size()) return -1;
    // Step 1: build kmp table
    vector<int> kmp_table(needle.size());
    int i = 1;
    int j = 0;
    while (i < (int)needle.size())
    {
        if (needle[i] == needle[j])
        {
            j++;
            kmp_table[i] = j;
            i++;
        }
        else if (j == 0)
        {
            kmp_table[i] = 0;
            i++;
        }
        else
        {
            j = kmp_table[j - 1];
        }
    }

    // Step 2: search substring
    i = 0;
    j = 0;
    while (i < (int)haystack.size())
    {
        if (j == needle.size())
        {
            break;
        }
        else if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = kmp_table[j - 1];
        }
    }
    if (j == needle.size())
    {
        return i - needle.size();
    }
    else
    {
        return -1;
    }
}

/// <summary>
/// Leet code #344. Reverse String 
///
/// Write a function that takes a string as input and returns the string 
/// reversed.
/// Example:
///  Given s = "hello", return "olleh".	
/// </summary>
string LeetCodeString::reverseString(string s)
{
    int first = 0, last = s.size() - 1;
    while (first < last)
    {
        swap(s[first], s[last]);
        first++;
        last--;
    }
    return s;
}

/// <summary>
/// Leet code #68. Text Justification 
///
/// Given an array of words and a length L, format the text such that 
/// each line has exactly L characters and is fully (left and right) 
/// justified. 
/// You should pack your words in a greedy approach; that is, pack as 
/// many words as you can in each line. 
/// Pad extra spaces ' ' when necessary so that each line has exactly L 
/// characters. 
/// Extra spaces between words should be distributed as evenly as 
/// possible. 
/// If the number of spaces on a line do not divide evenly between words, 
/// the empty slots on the left will be assigned more spaces than the 
/// slots on the right. 
/// For the last line of text, it should be left justified and no extra 
/// space is inserted between words. 
/// For example,
/// words: ["This", "is", "an", "example", "of", "text", "justification."]
/// L: 16. 
/// Return the formatted lines as:
/// [
///   "This    is    an",
///   "example  of text",
///   "justification.  "
/// ]
/// </summary>
vector<string> LeetCodeString::fullJustify(vector<string>& words, int maxWidth)
{
    // total word length, not counting space
    int total_word_length = 0;
    // number of word
    int word_count = 0;
    // a string buffer for a line
    string word_line;
    vector<string> result;
    // remember the current line starting from which word
    size_t first = 0;
    while (first + word_count < words.size())
    {
        // still able to add more words
        if ((word_count == 0) || (total_word_length + word_count + (int)words[first + word_count].size() <= maxWidth))
        {
            total_word_length += words[first + word_count].size();
            word_count++;
            continue;
        }

        int total_spaces = maxWidth < total_word_length ? 0 : maxWidth - total_word_length;

        size_t distribute_spaces = (word_count == 1) ? total_spaces : total_spaces / (word_count - 1);
        int remaining_spaces = (word_count == 1) ? 0 : (total_spaces - distribute_spaces * (word_count - 1));

        word_line.clear();
        for (size_t index = first; index < first + word_count; index++)
        {
            word_line.append(words[index]);
            if ((index < first + word_count - 1) || (word_count == 1))
            {
                word_line.append(distribute_spaces, ' ');
                if (remaining_spaces > 0)
                {
                    word_line.push_back(' ');
                    remaining_spaces--;
                }
            }
        }
        result.push_back(word_line);

        // start next line
        first += word_count;
        total_word_length = 0;
        word_count = 0;
    }

    word_line.clear();

    for (size_t index = first; index < first + word_count; index++)
    {
        if (index > first) word_line.push_back(' ');
        word_line.append(words[index]);

    }
    word_line.append(maxWidth - word_line.size(), ' ');
    result.push_back(word_line);

    return result;
}

/// <summary>
/// Leet code #76. Minimum Window Substring 
///
/// Given a string S and a string T, find the minimum window in S which 
/// will contain all the characters in T in complexity O(n).
/// For example, 
/// S = "ADOBECODEBANC"
/// T = "ABC"
/// Minimum window is "BANC".  
/// Note:
/// If there is no such window in S that covers all characters in T, 
/// return the empty string "". 
/// If there are multiple such windows, you are guaranteed that there 
/// will always be only one unique minimum window in S. 
/// </summary> 
string LeetCodeString::minWindow(string s, string t)
{
    unordered_map<char, int> source, target;
    for (size_t i = 0; i < t.size(); i++)
    {
        target[t[i]]++;
    }
    int left = -1;

    string result;
    int count = 0;
    for (int right = 0; right < (int)s.size(); right++)
    {
        if (target.count(s[right]) == 0)
        {
            continue;
        }
        // not interested
        source[s[right]]++;
        if (source[s[right]] == target[s[right]])
        {
            count++;
        }
        while (count == target.size())
        {
            if (result.empty() || right - left < (int)result.size())
            {
                result = s.substr(left + 1, right - left);
            }
            left++;
            // not interested
            if (target.count(s[left]) == 0)
            {
                continue;
            }
            source[s[left]]--;
            if (source[s[left]] == target[s[left]] - 1)
            {
                count--;
            }
        }
    }
    return result;
}


/// <summary>
/// Leet code #58. Length of Last Word
///
/// Given a string s consists of upper/lower-case alphabets and empty 
/// space characters ' ', 
/// return the length of last word in the string.
/// If the last word does not exist, return 0.
/// Note: A word is defined as a character sequence consists of non-space 
/// characters only. 
/// For example,
/// Given s = "Hello World",
/// return 5.
/// </summary>
int LeetCodeString::lengthOfLastWord(string s)
{
    int last = s.size();
    while ((last > 0) && isspace(s[last - 1])) last--;
    if (last == 0) return 0;
    int first = last - 1;
    while ((first > 0) && !isspace(s[first - 1])) first--;
    return last - first;
}

/// <summary>
/// Leet code #49. Group Anagrams   
/// Given an array of strings, group anagrams together.
/// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],  
/// Return: 
/// [
///   ["ate", "eat","tea"],
///   ["nat","tan"],
///   ["bat"]
/// ]
/// </summary>
vector<vector<string>> LeetCodeString::groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> result;
    unordered_map<string, int> anagram_map;
    for (size_t i = 0; i < strs.size(); i++)
    {
        string str = strs[i];
        sort(str.begin(), str.end());
        if (anagram_map.count(str) > 0)
        {
            result[anagram_map[str]].push_back(strs[i]);
        }
        else
        {
            anagram_map[str] = result.size();
            result.push_back({ strs[i] });
        }
    }

    return result;
}

/// <summary>
/// Leet code #383. Ransom Note
///
/// Given an arbitrary ransom note string and another string containing 
/// letters from all the magazines, write a function that will return true 
/// if the ransom note can be constructed from the magazines ; otherwise, 
/// it will return false. 
///
/// Each letter in the magazine string can only be used once in your ransom note. 
/// Note:
/// You may assume that both strings contain only lowercase letters. 
/// canConstruct("a", "b") -> false
/// canConstruct("aa", "ab") -> false
/// canConstruct("aa", "aab") -> true
/// </summary>
bool LeetCodeString::canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> char_map;
    for (size_t i = 0; i < magazine.size(); i++)
    {
        char_map[magazine[i]]++;
    }
    for (size_t i = 0; i < ransomNote.size(); i++)
    {
        char_map[ransomNote[i]]--;
        if (char_map[ransomNote[i]] < 0) return false;
    }
    return true;
}

/// <summary>
/// Leet code #387. First Unique Character in a String  
///
/// Given a string, find the first non-repeating character in it and 
/// return it's index. If it doesn't exist, return -1. 
/// Examples: 
/// s = "leetcode"
/// return 0.
/// s = "loveleetcode",
/// return 2.
/// Note: You may assume the string contain only lowercase letters. 
/// </summary>
int LeetCodeString::firstUniqChar(string s)
{
    vector<int> char_set(26, 0);
    for (char x : s)
    {
        char_set[x - 'a']++;
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        if (char_set[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

/// <summary>
/// Leet code #165. Compare Version Numbers  
/// Compare two version numbers version1 and version2.
/// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0. 
/// You may assume that the version strings are non-empty and contain only digits and the . character.
/// The . character does not represent a decimal point and is used to separate number sequences.
/// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
/// Here is an example of version numbers ordering:
/// 0.1 < 1.1 < 1.2 < 13.37 
/// </summary>
int LeetCodeString::compareVersion(string version1, string version2)
{
    vector<int> version_list1;
    vector<int> version_list2;
    string number = "";
    for (size_t i = 0; i <= version1.size(); i++)
    {
        if ((version1[i] == '.') || (i == version1.size()))
        {
            if (number.empty()) version_list1.push_back(0);
            else version_list1.push_back(atoi(number.c_str()));
            number.clear();
        }
        else
        {
            number.push_back(version1[i]);
        }
    }

    for (size_t i = 0; i <= version2.size(); i++)
    {
        if ((version2[i] == '.') || (i == version2.size()))
        {
            if (number.empty()) version_list2.push_back(0);
            else version_list2.push_back(atoi(number.c_str()));
            number.clear();
        }
        else
        {
            number.push_back(version2[i]);
        }
    }
    size_t index = 0;
    while ((index < version_list1.size()) || (index < version_list2.size()))
    {
        if (index == version_list1.size()) version_list1.push_back(0);
        if (index == version_list2.size()) version_list2.push_back(0);
        if (version_list1[index] < version_list2[index])
        {
            return -1;
        }
        else if (version_list1[index] > version_list2[index])
        {
            return 1;
        }
        else
        {
            index++;
        }
    }
    return 0;
}

/// <summary>
/// Leet code #409. Longest Palindrome 
///
/// Given a string which consists of lowercase or uppercase letters, find 
/// the length of the longest palindromes that can be built with those 
/// letters. 
/// This is case sensitive, for example "Aa" is not considered a 
/// palindrome here.
/// Note:
/// Assume the length of given string will not exceed 1,010. 
/// Example: 
/// Input:
/// "abccccdd"
/// Output:
/// 7
///
/// Explanation:
/// One longest palindrome that can be built is "dccaccd", whose length is 7.
/// </summary>
int LeetCodeString::longestPalindromeII(string s)
{
    int sum = 0;
    unordered_map<char, int> char_map;
    for (size_t i = 0; i < s.size(); i++)
    {
        char_map[s[i]]++;
    }
    unordered_map<char, int>::iterator itr;
    for (itr = char_map.begin(); itr != char_map.end(); ++itr)
    {
        if (itr->second >= 2)
        {
            sum += (itr->second / 2) * 2;
        }
    }
    for (itr = char_map.begin(); itr != char_map.end(); ++itr)
    {
        if (itr->second % 2 == 1)
        {
            sum += 1;
            break;
        }
    }
    return sum;
}

/// <summary>
/// Leet code #71. Simplify Path
///
/// Medium
///
/// Given an absolute path for a file (Unix-style), simplify it. Or in other 
/// words, convert it to the canonical path.
///
/// In a UNIX-style file system, a period . refers to the current directory. 
/// Furthermore, a double period .. moves the directory up a level. For more 
/// information, see: Absolute path vs relative path in Linux/Unix
///
/// Note that the returned canonical path must always begin with a slash /, 
/// and there must be only a single slash / between two directory names. The 
/// last directory name (if it exists) must not end with a trailing /. Also, 
/// the canonical path must be the shortest string representing the absolute 
/// path.
///
/// Example 1:
/// Input: "/home/"
/// Output: "/home"
/// Explanation: Note that there is no trailing slash after the last directory 
/// name.
///
/// Example 2:
/// Input: "/../"
/// Output: "/"
/// Explanation: Going one level up from the root directory is a no-op, as the 
/// root level is the highest level you can go.
///
/// Example 3:
/// Input: "/home//foo/"
/// Output: "/home/foo"
/// Explanation: In the canonical path, multiple consecutive slashes are 
/// replaced by a single one.
///
/// Example 4:
/// Input: "/a/./b/../../c/"
/// Output: "/c"
///
/// Example 5:
/// Input: "/a/../../b/../c//.//"
/// Output: "/c"
///
/// Example 6:
///
/// Input: "/a//b////c/d//././/.."
/// Output: "/a/b/c"
/// </summary>
string LeetCodeString::simplifyPath(string path)
{
    string result;
    vector<string> path_list;
    string folder_name;
    for (size_t i = 0; i <= path.size(); i++)
    {
        if ((i == path.size()) || (path[i] == '/'))
        {
            if ((folder_name.empty()) || (folder_name == "."))
            {
            }
            else if (folder_name == "..")
            {
                if (!path_list.empty()) path_list.pop_back();
            }
            else
            {
                path_list.push_back(folder_name);
            }
            folder_name.clear();
        }
        else
        {
            folder_name.push_back(path[i]);
        }
    }
    for (size_t i = 0; i < path_list.size(); i++)
    {
        result.push_back('/');
        result.append(path_list[i]);
    }
    if ((result.empty()) && (!path.empty()) && (path[0] == '/'))
    {
        result = "/";
    }
    return result;
}

/// <summary>
/// Leet code #187. Repeated DNA Sequences 
///
/// All DNA is composed of a series of nucleotides abbreviated 
/// as A, C, G, and T, for example: "ACGAATTCCG". 
/// When studying DNA, it is sometimes useful to identify repeated 
/// sequences within the DNA.
/// Write a function to find all the 10-letter-long sequences 
/// (substrings) that occur more than once in a DNA molecule.
///
/// For example,
/// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
/// Return:
/// ["AAAAACCCCC", "CCCCCAAAAA"].
/// </summary>
vector<string> LeetCodeString::findRepeatedDnaSequences(string s)
{
    vector<string> result;
    if (s.size() < 10) return result;
    unordered_map<char, int> char_map = { { 'A', 0 },{ 'C', 1 },{ 'G', 2 },{ 'T', 3 } };
    unordered_map<int, int> pos_map;
    unordered_set<int> visited;
    uint32_t string_code = 0;
    for (size_t i = 0; i < 10; i++)
    {
        string_code = ((string_code << 2) & 0xfffff) + char_map[s[i]];
    }
    pos_map[string_code] = 0;
    for (size_t i = 10; i < s.size(); i++)
    {
        string_code = ((string_code << 2) & 0xfffff) + char_map[s[i]];

        if (pos_map.find(string_code) != pos_map.end())
        {
            if (visited.find(string_code) == visited.end())
            {
                result.push_back(s.substr(pos_map[string_code], 10));
                visited.insert(string_code);
            }
        }
        else
        {
            pos_map[string_code] = i - 9;
        }
    }
    return result;
}

/// <summary>
/// Leet code #459. Repeated Substring Pattern  
/// Given a non-empty string check if it can be constructed by taking a 
/// substring of it and appending multiple copies of the substring together. 
/// You may assume the given string consists of lowercase English letters 
/// only and its length will not exceed 10000. 
///
/// Example 1:
/// Input: "abab"
/// Output: True
///
/// Explanation: It's the substring "ab" twice.
/// Example 2:
/// Input: "aba"
/// Output: False
/// 
/// Example 3:
/// Input: "abcabcabcabc" 
/// Output: True
/// Explanation: It's the substring "abc" four times. (And the substring 
/// "abcabc" twice.)
/// </summary>
bool LeetCodeString::repeatedSubstringPattern(string s)
{
    vector<int> kmp(s.size());
    int i = 1;
    int j = 0;
    while (i < (int)s.size())
    {
        if (s[i] == s[j])
        {
            j++;
            kmp[i] = j;
            i++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = kmp[j - 1];
        }
    }
    int last = kmp.back();
    int size = s.size();
    if ((last != 0) && (size % (size - last) == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #423. Reconstruct Original Digits from English   
///
/// Given a non-empty string containing an out-of-order English representation
/// of digits 0-9, output the digits in ascending order.
/// Note:
/// 1.Input contains only lowercase English letters.
/// 2.Input is guaranteed to be valid and can be transformed to its original 
///   digits.That means invalid inputs such as "abc" or "zerone" are not 
///   permitted.
/// 3.Input length is less than 50,000.
/// Example 1:  
/// Input: "owoztneoer" 
/// Output: "012"
/// Input: "fviefuro"
/// Example 2:
/// Output: "45"
/// </summary>
string LeetCodeString::originalDigits(string s)
{
    string result;
    vector<string> digit_map =
    {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    vector<int> digits(10);
    vector<int> alphabet_count(26);
    for (size_t i = 0; i < s.size(); i++)
    {
        alphabet_count[s[i] - 'a'] ++;
    }
    digits[0] = alphabet_count['z' - 'a'];
    digits[2] = alphabet_count['w' - 'a'];
    digits[4] = alphabet_count['u' - 'a'];
    digits[6] = alphabet_count['x' - 'a'];
    digits[8] = alphabet_count['g' - 'a'];
    digits[7] = alphabet_count['s' - 'a'] - digits[6];
    digits[3] = alphabet_count['h' - 'a'] - digits[8];
    digits[5] = alphabet_count['f' - 'a'] - digits[4];
    digits[1] = alphabet_count['o' - 'a'] - digits[0] - digits[2] - digits[4];
    digits[9] = alphabet_count['i' - 'a'] - digits[5] - digits[6] - digits[8];
    for (size_t i = 0; i < 10; i++)
    {
        result.append(string(digits[i], (char)('0' + i)));
    }
    return result;
}

/// <summary>
/// Leet code #434. Number of Segments in a String   
/// Count the number of segments in a string, where a segment is defined to be a contiguous 
/// sequence of non-space characters.
/// Please note that the string does not contain any non-printable characters.
/// Example:
/// Input: "Hello, my name is John"
/// Output: 5
/// </summary>
int LeetCodeString::countSegments(string s)
{
    int segments = 0;
    size_t index = 0;
    while (index < s.size())
    {
        int alpha = 0;
        while ((index < s.size()) && (!isspace(s[index])))
        {
            index++;
            alpha++;
        }
        if (alpha > 0) segments++;
        while ((index < s.size()) && (isspace(s[index])))
        {
            index++;
        }
    }
    return segments;
}


/// <summary>
/// Leet code #438. Find All Anagrams in a String
///
/// Given a string s and a non-empty string p, find all the start 
/// indices of p's anagrams in s. 
/// Strings consists of lowercase English letters only and the length 
/// of both strings s and p will not be larger than 20,100.
/// The order of output does not matter.
///
/// Example 1: 
/// Input:
/// s: "cbaebabacd" p: "abc"
/// Output:
/// [0, 6]
/// Explanation:
/// The substring with start index = 0 is "cba", which is an anagram of "abc".
/// The substring with start index = 6 is "bac", which is an anagram of "abc".
///
/// Example 2: 
/// Input:
/// s: "abab" p: "ab"
/// Output:
/// [0, 1, 2]
/// Explanation:
/// The substring with start index = 0 is "ab", which is an anagram of "ab".
/// The substring with start index = 1 is "ba", which is an anagram of "ab".
/// The substring with start index = 2 is "ab", which is an anagram of "ab".
/// </summary>
vector<int> LeetCodeString::findAnagrams(string s, string p)
{
    vector<int> result;
    int char_count = 0;
    vector<int> char_map(26);
    for (char ch : p) char_map[ch - 'a']++;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (i >= p.size())
        {
            char_map[s[i - p.size()] - 'a']++;
            if (char_map[s[i - p.size()] - 'a'] > 0) char_count--;
        }
        char_map[s[i] - 'a']--;
        if (char_map[s[i] - 'a'] >= 0) char_count++;
        if (char_count == p.size())
        {
            result.push_back(i - char_count + 1);
        }
    }
    return result;
}

/// <summary>
/// Leet code #290. Word Pattern      
///
/// Given a pattern and a string str, find if str follows the same pattern.
/// Here follow means a full match, such that there is a bijection between 
/// a letter in pattern and a non-empty word in str.
/// Examples:
/// 1.pattern = "abba", str = "dog cat cat dog" should return true.
/// 2.pattern = "abba", str = "dog cat cat fish" should return false.
/// 3.pattern = "aaaa", str = "dog cat cat dog" should return false.
/// 4.pattern = "abba", str = "dog dog dog dog" should return false.
/// Notes:
/// You may assume pattern contains only lowercase letters, and str 
/// contains lowercase letters separated by a single space. 
/// </summary>
bool LeetCodeString::wordPattern(string pattern, string str)
{
    vector<string> word_list;
    size_t index = 0;
    while (index < str.size())
    {
        string word;
        while ((index < str.size()) && (isalpha(str[index])))
        {
            word.push_back(str[index]);
            index++;
        }
        word_list.push_back(word);
        while ((index < str.size()) && (isspace(str[index])))
        {
            index++;
        }
    }
    unordered_map<char, string> word_map;
    unordered_set<string> word_set;
    if (pattern.size() != word_list.size()) return false;
    for (size_t i = 0; i < pattern.size(); i++)
    {
        if (word_map.find(pattern[i]) == word_map.end())
        {
            if (word_set.find(word_list[i]) == word_set.end())
            {
                word_map[pattern[i]] = word_list[i];
                word_set.insert(word_list[i]);
            }
            else
            {
                return false;
            }
        }
        else if (word_map[pattern[i]] != word_list[i])
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #65. Valid Number
///
/// Validate if a given string is numeric.
/// Some examples:
/// "0" => true
/// " 0.1 " => true
/// "abc" => false
/// "1 a" => false
/// "2e10" => true
/// Note: It is intended for the problem statement to be ambiguous. 
/// You should gather all requirements up front before implementing one. 
/// </summary>
bool LeetCodeString::isValidNumber(string s)
{
    enum class NumberState { start, sign, integer, decimal_start, decimal, exp_start, exp_sign, exp_int, end };
    NumberState state = NumberState::start;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (state == NumberState::start)
        {
            if (isspace(s[i])) state = NumberState::start;
            else if ((s[i] == '+') || (s[i] == '-')) state = NumberState::sign;
            else if (isdigit(s[i])) state = NumberState::integer;
            else if (s[i] == '.') state = NumberState::decimal_start;
            else return false;
        }
        else if (state == NumberState::sign)
        {
            if (isdigit(s[i])) state = NumberState::integer;
            else if (s[i] == '.') state = NumberState::decimal_start;
            else return false;
        }
        else if (state == NumberState::integer)
        {
            if (isdigit(s[i])) state = NumberState::integer;
            else if (s[i] == '.') state = NumberState::decimal;
            else if (s[i] == 'e') state = NumberState::exp_start;
            else if (isspace(s[i])) state = NumberState::end;
            else return false;
        }
        else if (state == NumberState::decimal_start)
        {
            if (isdigit(s[i])) state = NumberState::decimal;
            else return false;
        }
        else if (state == NumberState::decimal)
        {
            if (isdigit(s[i])) state = NumberState::decimal;
            else if (s[i] == 'e') state = NumberState::exp_start;
            else if (isspace(s[i])) state = NumberState::end;
            else return false;
        }
        else if (state == NumberState::exp_start)
        {
            if ((s[i] == '+') || (s[i] == '-')) state = NumberState::exp_sign;
            else if (isdigit(s[i])) state = NumberState::exp_int;
            else return false;
        }
        else if (state == NumberState::exp_sign)
        {
            if (isdigit(s[i])) state = NumberState::exp_int;
            else return false;
        }
        else if (state == NumberState::exp_int)
        {
            if (isdigit(s[i])) state = NumberState::exp_int;
            else if (isspace(s[i])) state = NumberState::end;
            else return false;
        }
        else if (state == NumberState::end)
        {
            if (isspace(s[i])) state = NumberState::end;
            else return false;
        }
    }
    if ((state == NumberState::start) || (state == NumberState::decimal_start) || (state == NumberState::sign) ||
        (state == NumberState::exp_start) || (state == NumberState::exp_sign))
    {
        return false;
    }
    else
    {
        return true;
    }
}

/// <summary>
/// Leet code #420. Strong Password Checker     
/// A password is considered strong if below conditions are all met:
/// 1. It has at least 6 characters and at most 20 characters. 
/// 2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit. 
/// 3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met). 
/// Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.
/// Insertion, deletion or replace of any one character are all considered as one change.
/// </summary>
/// <solution>
/// The key point in this problem is that we may have repeat characters and excessive characters, 
/// which makes the password longer than 20 characters, but they can cancel each other,
/// so I record all the repeated characters which are at least 3 characters, and if we have excessive characters
/// The first step is to cancel the repeated characters, after this step, either we will have excessive characters or
/// we have repeated characters, but not both, the amount is count in to_delete variable. 
/// Now we handle the string which is equal or less than 20 characters, the repeated characters can be considered as to_change
/// and they can cancel the missing digit, upper case, lower case or the password which are less than 6 characters.
/// </solution>
int LeetCodeString::strongPasswordChecker(string s)
{
    int less = 0;
    int more = 0;
    int lower = 0;
    int upper = 0;
    int digit = 0;
    int repeat = 0;
    vector<vector<int>> repeat_group(3);
    vector<int> repeat_list;
    int to_delete = 0;
    int to_change = 0;

    if (s.size() < 6) less = 6 - s.size();
    if (s.size() > 20) more = s.size() - 20;
    char ch = '\0';
    int repeat_sum = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) digit = 1;
        if (isupper(s[i])) upper = 1;
        if (islower(s[i])) lower = 1;

        if (s[i] != ch)
        {
            ch = s[i];
            if (repeat_sum >= 3)
            {
                repeat_group[repeat_sum % 3].push_back(repeat_sum);
            }
            repeat_sum = 0;
        }
        repeat_sum++;
    }
    if (repeat_sum >= 3)
    {
        repeat_group[repeat_sum % 3].push_back(repeat_sum);
    }

    // make repeat count 3k to 3(k-1)+2; 
    for (size_t i = 0; i < repeat_group[0].size(); i++)
    {
        if (more == 0) break;
        else
        {
            repeat_group[0][i]--;
            more--;
            to_delete++;
        }
    }
    // make repeat count 3k+1 to 3(k-1)+2; 
    for (size_t i = 0; i < repeat_group[1].size(); i++)
    {
        if (more < 2)  break;
        else
        {
            repeat_group[1][i] -= 2;
            more -= 2;
            to_delete += 2;
        }
    }

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < repeat_group[i].size(); j++)
        {
            repeat_list.push_back(repeat_group[i][j]);
        }
    }

    // cancel excessive characters and repeated characters
    while ((more > 0) && (!repeat_list.empty()))
    {
        int repeat_count = repeat_list.back();
        repeat_list.pop_back();
        int delete_count = min(repeat_count - 2, more);
        repeat_count -= delete_count;
        more -= delete_count;
        if (repeat_count > 2) repeat_list.push_back(repeat_count);
        to_delete += delete_count;
    }
    // in case we have more excessive characters
    to_delete += more;

    // for remaining repeated characters, we consider them to be changed
    while (!repeat_list.empty())
    {
        to_change += repeat_list.back() / 3;
        repeat_list.pop_back();
    }
    to_change = max(to_change, (1 - lower) + (1 - upper) + (1 - digit));
    to_change = max(to_change, less);
    return to_change + to_delete;
}

/// <summary>
/// Leet code #393. UTF-8 Validation
///
/// A character in UTF8 can be from 1 to 4 bytes long, subjected to the 
/// following rules:
/// 1.For 1-byte character, the first bit is a 0, followed by its unicode 
///   code.
/// 2.For n-bytes character, the first n-bits are all one's, the n+1 bit 
///   is 0, followed by n-1 bytes with most significant 2 bits being 10.
/// This is how the UTF-8 encoding would work:
///   Char. number range  |        UTF-8 octet sequence
///      (hexadecimal)    |              (binary)
///   --------------------+---------------------------------------------
///   0000 0000-0000 007F | 0xxxxxxx
///   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
///   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
///   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
/// Given an array of integers representing the data, return whether it is 
/// a valid utf-8 encoding. 
/// Note:
/// The input is an array of integers. Only the least significant 8 bits 
/// of each integer is used to store the data. This means each integer 
/// represents only 1 byte of data. 
/// Example 1: 
/// data = [197, 130, 1], which represents the octet 
/// sequence: 11000101 10000010 00000001.
/// Return true.
/// It is a valid utf-8 encoding for a 2-bytes character followed by 
//// a 1-byte character.
/// Example 2: 
/// data = [235, 140, 4], which represented the octet 
/// sequence: 11101011 10001100 00000100.
/// Return false.
/// The first 3 bits are all one's and the 4th bit is 0 means it is 
/// a 3-bytes character.
/// The next byte is a continuation byte which starts with 10 and 
/// that's correct.
/// But the second continuation byte does not start with 10, so it is 
/// invalid.
/// </summary>
bool LeetCodeString::validUtf8(vector<int>& data)
{
    uint32_t high_bit = 1 << 7;
    int pending_byte = 0;
    for (size_t i = 0; i < data.size(); i++)
    {
        uint32_t n = data[i];
        int count = 0;
        while ((n & high_bit) != 0)
        {
            n <<= 1;
            count++;
        }
        if (count == 0)
        {
            if (pending_byte != 0) return false;
        }
        else if (count == 1)
        {
            if (pending_byte == 0) return false;
            else pending_byte--;
        }
        else
        {
            if (pending_byte != 0) return false;
            else pending_byte = count - 1;
        }
    }
    if (pending_byte == 0) return true;
    else return false;
}

/// <summary>
/// Check if this is a valid IPv4 address
/// </summary>
bool LeetCodeString::checkIPv4Address(vector<string> addressList)
{
    if (addressList.size() != 4)
    {
        return false;
    }
    for (size_t i = 0; i < addressList.size(); i++)
    {
        string address = addressList[i];
        if ((address.size() == 0) || (address.size() > 3)) return false;
        if ((address[0] == '0') && (address.size() > 1)) return false;
        for (char ch : address)
        {
            if (!isdigit(ch)) return false;
        }
        if (atoi(address.c_str()) > 255)
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Check if this is a valid IPv6 address
/// </summary>
bool LeetCodeString::checkIPv6Address(vector<string> addressList)
{
    if (addressList.size() != 8)
    {
        return false;
    }
    for (size_t i = 0; i < addressList.size(); i++)
    {
        string address = addressList[i];
        if ((address.size() == 0) || (address.size() > 4)) return false;
        for (char ch : address)
        {
            if (!isxdigit(ch)) return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #468. Validate IP Address        
///
/// In this problem, your job to write a function to check whether a input 
/// string is a valid IPv4 address or IPv6 address or neither. IPv4 
/// addresses are canonically represented in dot-decimal notation, which 
/// consists of four decimal numbers, each ranging from 0 to 255, separated 
/// by dots ("."), e.g.,172.16.254.1; 
/// Besides, you need to keep in mind that leading zeros in the IPv4 is 
/// illegal. For example, the address 172.16.254.01 is illegal. 
/// IPv6 addresses are represented as eight groups of four hexadecimal 
/// digits, each group representing 16 bits. 
/// The groups are separated by colons (":"). For example, the 
/// address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a legal one. 
/// Also, we could omit some leading zeros among four hexadecimal digits 
/// and some low-case characters in the address to upper-case ones, 
/// so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit 
/// leading zeros and using upper cases). 
/// However, we don't replace a consecutive group of zero value with a 
/// single empty group using two consecutive colons (::) to pursue 
/// simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid 
/// IPv6 address. 
/// Besides, you need to keep in mind that extra leading zeros in the 
//// IPv6 is also illegal. For example, the address 
/// 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is also illegal. 
/// Note: You could assume there is no extra space in the test cases and 
/// there may some special characters in the input string. 
/// Example 1:
/// Input: "172.16.254.1"
/// Output: "IPv4"
/// Explanation: This is a valid IPv4 address, return "IPv4".
/// Example 2:
/// Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
/// Output: "IPv6"
/// Explanation: This is a valid IPv6 address, return "IPv6".
/// Example 3:
/// Input: "256.256.256.256"
/// Output: "Neither"
/// Explanation: This is neither a IPv4 address nor a IPv6 address.
/// </summary>
string LeetCodeString::validIPAddress(string IP)
{
    vector<string> addressList;
    string word, type;
    for (size_t i = 0; i <= IP.size(); i++)
    {
        if (i == IP.size())
        {
            addressList.push_back(word);
            word.clear();
        }
        else if (IP[i] == '.')
        {
            if (type == "")
            {
                type = "IPv4";
            }
            else if (type != "IPv4")
            {
                type = "Neither";
                break;
            }
            addressList.push_back(word);
            word.clear();
        }
        else if (IP[i] == ':')
        {
            if (type == "")
            {
                type = "IPv6";
            }
            else if (type != "IPv6")
            {
                type = "Neither";
                break;
            }
            addressList.push_back(word);
            word.clear();
        }
        else
        {
            word.push_back(IP[i]);
        }
    }
    if ((type == "IPv4") && (checkIPv4Address(addressList)))
    {
        return type;
    }
    else if ((type == "IPv6") && (checkIPv6Address(addressList)))
    {
        return type;
    }
    else
    {
        return "Neither";
    }
}

/// <summary>
/// Is Additive Number recursive call
/// </summary>
bool LeetCodeString::isAdditiveNumber(string num1, string num2, string num)
{
    if ((num1[0] == '0' && num1.size() > 1) || (num2[0] == '0' && num2.size() > 1))
    {
        return false;
    }

    string num3 = addStrings(num1, num2);
    if ((num.size() >= num3.size()) && (num.substr(0, num3.size()) == num3))
    {
        num1 = num2;
        num2 = num3;
        num = num.substr(num3.size());
        if (num.empty()) return true;
        return isAdditiveNumber(num1, num2, num);
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #306. Additive Number
/// Additive number is a string whose digits can form additive sequence.
/// A valid additive sequence should contain at least three numbers. Except for the first two numbers, 
/// each subsequent number in the sequence must be the sum of the preceding two.
/// 
/// For example:
/// "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
/// 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
/// "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199. 1 + 99 = 100, 99 + 100 = 199
///
///	Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid. 
/// Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
/// Follow up:
/// How would you handle overflow for very large input integers? 
/// </summary>
bool LeetCodeString::isAdditiveNumber(string num)
{
    for (int i = 0; i < (int)num.size() - 1; i++)
    {
        for (int j = i + 1; j < (int)num.size() - 1; j++)
        {
            string num1 = num.substr(0, i + 1);
            string num2 = num.substr(i + 1, j - i);
            string num3 = num.substr(j + 1);
            if (isAdditiveNumber(num1, num2, num3))
            {
                return true;
            }
        }
    }
    return false;
}

/// <summary>
/// Leet code #214. Shortest Palindrome
/// 
/// Given a string S, you are allowed to convert it to a palindrome by 
/// adding characters in front of it. Find and return the shortest palindrome 
/// you can find by performing this transformation. 
///
/// For example: 
/// Given "aacecaaa", return "aaacecaaa".
/// Given "abcd", return "dcbabcd".
/// Given an array of n positive integers and a positive integer s, 
/// </summary>
string LeetCodeString::shortestPalindrome(string s)
{
    string result;
    int n = s.size();
    vector<int> kmp(n);
    int i = 1; 
    int j = 0;
    while (i < n)
    {
        if (s[i] == s[j])
        {
            j++;
            kmp[i] = j;
            i++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = kmp[j - 1];
        }
    }

    int s_i = 0, r_i = 0;
    while (s_i + r_i <  n)
    {
        if (s[s_i] == s[n-1-r_i])
        {
            s_i++;
            r_i++;
        }
        else
        {
            if (s_i > 0)
            {
                s_i = kmp[s_i-1];
            }
            else r_i++;
        }
    }
    r_i -= s_i;
    for (int i = 0; i < r_i; i++)
    {
        result.push_back(s[n-1-i]);
    }
    result.append(s);
    return result;
}

/// <summary>
/// Leet code #125. Valid Palindrome
///
/// Given a string, determine if it is a palindrome, considering only 
/// alphanumeric characters and ignoring cases.
/// For example,
/// "A man, a plan, a canal: Panama" is a palindrome.
/// "race a car" is not a palindrome.
/// Notes:
/// Have you consider that the string might be empty? This is a good 
/// question to ask during an interview.
/// For the purpose of this problem, we define empty string as valid 
/// palindrome.
/// </summary>
bool LeetCodeString::isPalindrome(string s)
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
/// Leet code #336. Palindrome Pairs
/// 
/// Given a list of unique words, find all pairs of distinct 
/// indices (i, j) in the given list, 
/// so that the concatenation of the two words, i.e. words[i] + words[j] 
/// is a palindrome. 
/// Example 1:
/// Given words = ["bat", "tab", "cat"]
/// Return [[0, 1], [1, 0]]
///
/// Example 2:
/// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
/// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
/// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
/// </summary>
vector<vector<int>> LeetCodeString::palindromePairs(vector<string>& words)
{
    vector<vector<int>> result;
    unordered_map<string, int> reverse_map;
    for (size_t i = 0; i < words.size(); i++)
    {
        string str = words[i];
        std::reverse(str.begin(), str.end());
        reverse_map[str] = i;
    }

    for (int i = 0; i < (int)words.size(); i++)
    {
        string str = words[i];
        for (size_t k = 0; k < words[i].size(); k++)
        {
            string left = words[i].substr(0, k + 1);
            string right = words[i].substr(k + 1);
            if (left == string(left.rbegin(), left.rend()) && 
                (reverse_map.count(right) > 0))
            {
                int j = reverse_map[right];
                if (i != j)
                {
                    result.push_back({ j, i });
                    if (right.empty()) result.push_back({ i, j });
                }
            }
            if (right == string(right.rbegin(), right.rend()) && 
                (reverse_map.count(left) > 0))
            {
                int j = reverse_map[left];
                if (i != j) result.push_back({ i, j });
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #388. Longest Absolute File Path    
/// 
/// Suppose we abstract our file system by a string in the following manner:
/// The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
/// dir
///     subdir1
///     subdir2
///         file.ext
/// The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
/// The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
/// dir
///     subdir1
///         file1.ext
///         subsubdir1
///     subdir2
///         subsubdir2
///             file2.ext
/// The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file 
/// file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level 
/// sub-directory subsubdir2 containing a file file2.ext.
/// We are interested in finding the longest (number of characters) absolute path to a file within 
/// our file system. For example, in the second example above, the longest absolute path is 
/// "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
/// Given a string representing the file system in the above format, return the length of 
/// the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
/// Note:
/// The name of a file contains at least a . and an extension.
/// The name of a directory or sub-directory will not contain a ..
///  ime complexity required: O(n) where n is the size of the input string.
/// Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
/// </summary>
int LeetCodeString::lengthLongestPath(string input)
{
    int max_length = 0;
    vector<string> path_list;
    vector<int> path_length;
    size_t index = 0;
    string word;
    for (size_t i = 0; i <= input.size(); i++)
    {
        if (i == input.size() || input[i] == '\n')
        {
            if (!word.empty())
            {
                path_list.resize(index + 1);
                path_list[index] = word;
                path_length.resize(index + 1);
                if (index == 0) path_length[index] = word.size();
                else path_length[index] = path_length[index - 1] + word.size() + 1;
                if (strchr(word.c_str(), '.') != nullptr)
                {
                    max_length = max(max_length, path_length[index]);
                }
                word.clear();
            }
            index = 0;
        }
        else if (input[i] == '\t')
        {
            index++;
        }
        else
        {
            word.push_back(input[i]);
        }
    }
    return max_length;
}

/// <summary>
/// Leet code #424. Longest Repeating Character Replacement    
/// 
/// Given a string that consists of only uppercase English letters, 
/// you can replace any letter in the string with another letter at 
/// most k times. Find the length of a longest substring containing 
/// all repeating letters you can get after performing the above 
/// operations.
/// Note:
/// Both the string's length and k will not exceed 10^4. 
///
/// Example 1: 
/// Input:
/// s = "ABAB", k = 2
/// Output:
/// 4
/// Explanation:
/// Replace the two 'A's with two 'B's or vice versa.
/// 
/// Example 2: 
/// Input:
/// s = "AABABBA", k = 1
/// Output:
/// 4
/// Explanation:
/// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
/// The substring "BBBB" has the longest repeating letters, which is 4.
/// </summary>
int LeetCodeString::characterReplacement(string s, int k)
{
    vector<int> char_count(26);
    int result = 0;
    int max_count = 0;
    int first = 0, last = 0;
    while (last < (int)s.size())
    {
        char_count[s[last]-'A']++;
        // we only need to track the max count of characters
        max_count = max(max_count, char_count[s[last] - 'A']);
        last++;
        // if valid we track the length
        if (max_count + k >= last - first)
        {
            result = max(result, last - first);
        }
        else
        {
            // when invalid, we shrink window by one
            char_count[s[first] - 'A']--;
            first++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #395. Longest Substring with At Least K Repeating Characters     
/// 
/// Find the length of the longest substring T of a given string 
/// (consists of lowercase letters only) such that every character in T 
/// appears no less than k times. 
///
/// Example 1: 
/// Input:
/// s = "aaabb", k = 3
/// Output:
/// 3
/// The longest substring is "aaa", as 'a' is repeated 3 times.
///
/// Example 2: 
/// Input:
/// s = "ababbc", k = 2
/// Output:
/// 5
/// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
/// </summary>
int LeetCodeString::longestSubstring(string s, int k)
{
    int result = 0;
    for (int i = 1; i <= 26; i++)
    {
        vector<int> char_map(26);
        int char_count = 0;
        int not_meet = 0;
        int begin = -1;
        for (int end = 0; end < (int)s.size(); end++)
        {
            char_map[s[end] - 'a']++;
            if (char_map[s[end] - 'a'] == 1)
            {
                char_count++;
                not_meet++;
            }
            if (char_map[s[end] - 'a'] == k)
            {
                not_meet--;
            }
            while (char_count > i)
            {
                begin++;
                char_map[s[begin] - 'a']--;
                if (char_map[s[begin] - 'a'] == k -1)
                {
                    not_meet++;
                }
                if (char_map[s[begin]- 'a'] == 0)
                {
                    char_count--;
                    not_meet--;
                }
            }
            if (not_meet == 0)
            {
                result = max(result, end - begin);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #266. Palindrome Permutation  
/// 
/// Given a string, determine if a permutation of the string could form a palindrome.
/// For example,
/// "code" -> False, "aab" -> True, "carerac" -> True.
/// Hint:
/// 1.Consider the palindromes of odd vs even length. What difference do you notice?
/// 2.Count the frequency of each character.
/// 3.If each character occurs even number of times, then it must be a palindrome. 
/// How about character which occurs odd number of times?
/// </summary>
bool LeetCodeString::canPermutePalindrome(string s)
{
    unordered_map<char, int> char_count;
    for (char ch : s)
    {
        char_count[ch]++;
    }
    int odd_count = 0;
    for (auto &x : char_count)
    {
        odd_count += (x.second % 2 == 1) ? 1 : 0;
        if (odd_count > 1) return false;
    }
    return true;
}

/// <summary>
/// Leet code #293. Flip Game  
/// 
/// You are playing the following Flip Game with your friend: Given a 
/// string that contains only these two characters: + and -, you and your 
/// friend take turns to flip two consecutive "++" into "--". The game 
/// ends when a person can no longer make a move and therefore the other 
/// person will be the winner. 
/// Write a function to compute all possible states of the string after 
/// one valid move. 
/// For example, given s = "++++", after one move, it may become one of 
/// the following states: 
/// [
///    "--++",
///    "+--+",
///    "++--"
/// ]
/// If there is no valid move, return an empty list [].
/// </summary>
vector<string> LeetCodeString::generatePossibleNextMoves(string s)
{
    vector<string> result;
    for (int i = 0; i < (int)s.size() - 1; i++)
    {
        if ((s[i] == '+') && (s[i + 1] == '+'))
        {
            result.push_back(s.substr(0, i) + "--" + s.substr(i + 2));
        }
    }
    return result;
}

/// <summary>
/// Leet code #246. Strobogrammatic Number  
/// 
/// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
/// Write a function to determine if a number is strobogrammatic. The number is represented as a string.
/// For example, the numbers "69", "88", and "818" are all strobogrammatic.
/// </summary>
bool LeetCodeString::isStrobogrammatic(string num)
{
    unordered_map<char, char> char_map = { { '6', '9' },{ '9', '6' },{ '1', '1' },{ '0', '0' },{ '8', '8' } };
    int first = 0;
    int last = num.size() - 1;
    while (first <= last)
    {
        if (char_map[num[first]] == num[last])
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
/// Leet code #249. Group Shifted Strings    
/// 
/// Given a string, we can "shift" each of its letter to its successive letter, 
/// for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
/// "abc" -> "bcd" -> ... -> "xyz"
/// Given a list of strings which contains only lowercase alphabets, 
/// group all strings that belong to the same shifting sequence.
/// For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
/// A solution is: 
/// [
///   ["abc","bcd","xyz"],
///   ["az","ba"],
///   ["acef"],
///   ["a","z"]
/// ]
/// </summary>
vector<vector<string>> LeetCodeString::groupStrings(vector<string>& strings)
{
    vector<vector<string>> result;
    for (string str : strings)
    {
        size_t i = 0;
        for (i = 0; i < result.size(); i++)
        {
            string target = result[i][0];
            if (str.size() != target.size()) continue;
            int distance = 0;
            bool match = true;
            for (size_t j = 0; j < str.size(); j++)
            {
                if (j == 0) distance = (str[j] - target[j] + 26) % 26;
                else if (distance != (str[j] - target[j] + 26) % 26)
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                result[i].push_back(str);
                break;
            }
        }
        if (i == result.size())
        {
            result.push_back(vector<string>());
            result[i].push_back(str);
        }
    }
    return result;
}

/// <summary>
/// Leet code #408. Valid Word Abbreviation    
/// 
/// Given a non-empty string s and an abbreviation abbr, return 
/// whether the string matches with the given abbreviation. 
/// A string such as "word" contains only the following valid abbreviations:
/// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
/// Notice that only the above abbreviations are valid abbreviations of the string "word". 
/// Any other string is not a valid abbreviation of "word".
/// Note:
/// Assume s contains only lowercase letters and abbr contains only lowercase letters and digits. 
/// Example 1:
/// Given s = "internationalization", abbr = "i12iz4n":
/// Return true.
/// Example 2:
/// Given s = "apple", abbr = "a2e":
/// Return false.
/// </summary>
bool LeetCodeString::validWordAbbreviation(string word, string abbr)
{
    size_t word_index = 0;
    size_t abbr_index = 0;
    string number = "";
    while (word_index < word.size() && abbr_index <abbr.size())
    {
        if (isdigit(abbr[abbr_index]))
        {
            number.push_back(abbr[abbr_index]);
            abbr_index++;
        }
        else if (number.empty())
        {
            if (word[word_index] == abbr[abbr_index])
            {
                word_index++;
                abbr_index++;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (number[0] == '0') return false;
            word_index += stoi(number);
            number = "";
        }
    }
    if (!number.empty())
    {
        if (number[0] == '0') return false;
        word_index += stoi(number);
        number = "";
    }
    if (word_index == word.size() && abbr_index == abbr.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #482. License Key Formatting  
/// 
/// Now you are given a string S, which represents a software license key 
/// which we would like to format. The string S is composed of 
/// alphanumerical characters and dashes. 
/// The dashes split the alphanumerical characters within the string into 
/// groups. (i.e. if there are M dashes, the string is split into M+1 
/// groups). 
/// The dashes in the given string are possibly misplaced.
///
/// We want each group of characters to be of length K (except for 
/// possibly the first group, which could be shorter, but still must 
/// contain at least one character). To satisfy this requirement, we will 
/// reinsert dashes. Additionally, all the lower case letters in the 
/// string must be converted to upper case.
/// So, you are given a non-empty string S, representing a license key to 
/// format, and an integer K. 
/// And you need to return the license key formatted according to the 
/// description above.
/// Example 1:
/// Input: S = "2-4A0r7-4k", K = 4
/// Output: "24A0-R74K"
/// Explanation: The string S has been split into two parts, each part 
/// has 4 characters.
/// Example 2:
/// Input: S = "2-4A0r7-4k", K = 3
/// Output: "24-A0R-74K"
/// Explanation: The string S has been split into three parts, each part 
/// has 3 characters except the first part as it could be shorter as said 
/// above.
/// Note:
/// 1.The length of string S will not exceed 12,000, and K is a positive 
///   integer.
/// 2.String S consists only of alphanumerical characters (a-z and/or A-Z 
///   and/or 0-9) and dashes(-).
/// 3.String S is non-empty.
/// </summary>
string LeetCodeString::licenseKeyFormatting(string S, int K)
{
    string str;
    int index = S.size() - 1;
    int count = 0;
    while (index >= 0)
    {
        if (S[index] != '-')
        {
            str.push_back(toupper(S[index]));
            count++;
            if (count == K)
            {
                str.push_back('-');
                count = 0;
            }
        }
        index--;
    }
    if ((!str.empty()) && (str.back() == '-'))
    {
        str.pop_back();
    }
    std::reverse(str.begin(), str.end());
    return str;
}

/// <summary>
/// Leet code #481. Magical String
/// 
/// A magical string S consists of only '1' and '2' and obeys the following rules:  
/// The string S is magical because concatenating the number of contiguous occurrences of 
/// characters '1' and '2' generates the string S itself.  
/// The first few elements of string S is the following: S = "1221121221221121122……" 
/// If we group the consecutive '1's and '2's in S, it will be:  
///
/// 1 22 11 2 1 22 1 22 11 2 11 22 ...... 
///
/// and the occurrences of '1's or '2's in each group are: 
/// 1 2 2 1 1 2 1 2 2 1 2 2 ...... 
/// You can see that the occurrence sequence above is the S itself. 
///
/// Given an integer N as input, return the number of '1's in the first N number in the magical string S. 
///
/// Note: N will not exceed 100,000. 
/// Example 1:
///
/// Input: 6
/// Output: 3
/// Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
/// </summary>
int LeetCodeString::magicalString(int n)
{
    string str;
    int index = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            str.push_back('1');
        }
        else if (i == 1)
        {
            str.push_back('2');
            index = 1;
            count = 1;
        }
        else
        {
            if (count == 0)
            {
                index++;
                count = str[index] - '0';
                if (str.back() == '1') str.push_back('2');
                else str.push_back('1');
                count--;
            }
            else
            {
                str.push_back(str.back());
                count--;
            }
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1') count++;
    }
    return count;
}

/// <summary>
/// Leet code #157. Read N Characters Given Read4  
/// </summary>
int LeetCodeString::read4(char *buff, string& s, int& index)
{
    int i;
    for (i = index; (i < index + 4) && (i < (int)s.size()); i++)
    {
        buff[i - index] = s[i];
    }
    buff[i - index] = 0;
    return i - index;
}

/// <summary>
/// Leet code #157. Read N Characters Given Read4  
/// 
/// The API: int read4(char *buf) reads 4 characters at a time from a file. 
/// The return value is the actual number of characters read. For example, 
/// it returns 3 if there is only 3 characters left in the file. 
/// By using the read4 API, implement the function int read(char *buf, int n) 
/// that reads n characters from the file. 
///
/// Note:
/// The read function will only be called once for each test case. 
/// </summary>
int LeetCodeString::readNChars(char *buf, int n, string &s)
{
    int index = 0;
    while (index < n)
    {
        char buff[5];
        int n_char = read4(buff, s, index);
        if (n_char > n - index) n_char = n - index;
        for (int i = 0; i < n_char; i++)
        {
            buf[index + i] = buff[i];
        }
        index += n_char;
        buf[index] = 0;
        if (n_char < 4) break;
    }
    buf[index] = 0;
    return index;
}

/// <summary>
/// Leet code #158. Read N Characters Given Read4 II - Call multiple times  
/// 
/// The API: int read4(char *buf) reads 4 characters at a time from a file. 
/// The return value is the actual number of characters read. 
/// For example, it returns 3 if there is only 3 characters left in the file. 
/// The return value is the actual number of characters read. For example, 
/// it returns 3 if there is only 3 characters left in the file. 
/// By using the read4 API, implement the function int read(char *buf, int n) 
/// that reads n characters from the file. 
/// Note:
/// The read function may be called multiple times. 
/// </summary>
int LeetCodeString::readNCharsII(char *buf, int n, string& s, int& index, string&m_buffer)
{
    int i = 0;
    while (i < (int)m_buffer.size() && i < n)
    {
        buf[i] = m_buffer[i];
        i++;
    }
    m_buffer = m_buffer.substr(i);
    buf[i] = 0;

    while (i < n)
    {
        char buff[5];
        int size = read4(buff, s, index);
        int j = 0;
        for (j = 0; (j < size) && (i + j < n); j++)
        {
            buf[i + j] = buff[j];
        }
        i += j;
        buf[i] = 0;
        while (j < size)
        {
            m_buffer.push_back(buff[j]);
            j++;
        }
        index += size;
        if (size < 4) break;
    }
    return i;
}

/// <summary>
/// Leet code #159. Longest Substring with At Most Two Distinct Characters       
/// 
/// Given a string, find the length of the longest substring T that contains 
/// at most 2 distinct characters. 
/// For example, Given s = “eceba”, 
/// T is "ece" which its length is 3.
/// </summary>
int LeetCodeString::lengthOfLongestSubstringTwoDistinct(string s)
{
    unordered_map<char, int> char_count;
    int begin = -1;
    int result = 0;
    for (int end = 0; end < (int)s.size(); end++)
    {
        char_count[s[end]]++;
        while (char_count.size() > 2)
        {
            begin++;
            char_count[s[begin]]--;
            if (char_count[s[begin]] == 0)
            {
                char_count.erase(s[begin]);
            }
        }
        result = max(result, end - begin);
    }
    return result;
}

/// <summary>
/// Leet code #340. Longest Substring with At Most K Distinct Characters
/// 
/// Given a string, find the length of the longest substring T that contains 
/// at most k distinct characters. 
/// For example, Given s = "eceba" and k = 2,  
/// T is "ece" which its length is 3. 
/// </summary>
int LeetCodeString::lengthOfLongestSubstringKDistinct(string s, int k)
{
    unordered_map<char, int> char_count;
    int begin = -1;
    int result = 0;
    for (int end = 0; end < (int)s.size(); end++)
    {
        char_count[s[end]]++;
        while ((int)char_count.size() > k)
        {
            begin++;
            char_count[s[begin]]--;
            if (char_count[s[begin]] == 0)
            {
                char_count.erase(s[begin]);
            }
        }
        result = max(result, end - begin);
    }
    return result;
}

/// <summary>
/// Leet code #467. Unique Substrings in Wraparound String        
/// 
/// Consider the string s to be the infinite wraparound string of 
/// "abcdefghijklmnopqrstuvwxyz",
/// so s will look like this: 
/// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
/// Now we have another string p. Your job is to find out how many unique 
/// non-empty substrings of p are present in s. In particular, your input is 
/// the string p and you need to output the number of different non-empty 
/// substrings of p in the string s.
/// Note: p consists of only lowercase English letters and the size of p might 
/// be over 10000.
///
/// Example 1:
/// Input: "a"
/// Output: 1
/// Explanation: Only the substring "a" of string "a" is in the string.
///
/// Example 2:
/// Input: "cac"
/// Output: 2
/// Explanation: There are two substrings "a", "c" of string "cac" in the 
/// string s.
///
/// Example 3:
/// Input: "zab"
/// Output: 6
/// Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" 
/// of string "zab" in the string s.
/// </summary>
int LeetCodeString::findSubstringInWraproundString(string p)
{
    unordered_map<char, int> str_map;
    int first = 0, last = first + 1;
    while (first < (int)p.size())
    {
        char ch = p[last - 1];
        str_map[ch] = max(str_map[ch], last - first);
        if ((last < (int)p.size()) && ((p[last - 1] - 'a' + 1) % 26 == (p[last] - 'a')))
        {
            last++;
        }
        else
        {
            first = last;
            last = first + 1;
        }
    }
    int count = 0;
    for (auto &itr : str_map)
    {
        count += itr.second;
    }
    return count;
}

/// <summary>
/// Leet code #520. Detect Capital   
/// 
/// Given a word, you need to judge whether the usage of capitals in it is right or not. 
/// We define the usage of capitals in a word to be right when one of the following cases holds: 
/// 1.All letters in this word are capitals, like "USA".
/// 2.All letters in this word are not capitals, like "leetcode".
/// 3.Only the first letter in this word is capital if it has more than one letter, like "Google".
/// Otherwise, we define that this word doesn't use capitals in a right way. 
///
/// Example 1:
///
/// Input: "USA"
/// Output: True
/// 
/// Example 2:
/// Input: "FlaG"
/// Output: False
/// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters. 
/// </summary>
bool LeetCodeString::detectCapitalUse(string word)
{
    int upper_count = 0;
    int lower_count = 0;

    for (size_t i = 0; i < word.size(); i++)
    {
        if (islower(word[i]))
        {
            lower_count++;
            if (upper_count > 1) return false;
        }
        else if (isupper(word[i]))
        {
            upper_count++;
            if (lower_count > 0) return false;

        }
    }
    return true;
}

/// <summary>
/// Leet code #524. Longest Word in Dictionary through Deleting
/// 
/// Given a string and a string dictionary, find the longest string in 
/// the dictionary that can be formed by deleting some characters of the 
/// given string. If there are more than one possible results, return 
/// the longest word with the smallest lexicographical order. If there 
/// is no possible result, return the empty string.
///
/// Example 1:
/// Input:
/// s = "abpcplea", d = ["ale","apple","monkey","plea"]
///
/// Output: 
/// "apple"
/// Example 2:
/// Input:
/// s = "abpcplea", d = ["a","b","c"]
///
/// Output: 
/// "a"
/// Note:
/// All the strings in the input will only contain lower-case letters.
/// The size of the dictionary won't exceed 1,000.
/// The length of all the strings in the input won't exceed 1,000.
/// </summary>
string LeetCodeString::findLongestWord(string s, vector<string>& d)
{
    map<int, set<string>> dict_map;
    for (string str : d) dict_map[str.size()].insert(str);
    for (map<int, set<string>>::reverse_iterator itr = dict_map.rbegin(); itr != dict_map.rend(); itr++)
    {
        for (string str : itr->second)
        {
            if (isSubsequence(str, s)) return str;
        }
    }
    return "";
}

/// <summary>
/// Leet code #541. Reverse String II
/// 
/// Given a string and an integer k, you need to reverse the first 
/// k characters for every 2k characters counting from the start of 
/// the string. If there are less than k characters left, reverse 
/// all of them. If there are less than 2k but greater than or equal 
/// to k characters, then reverse the first k characters and left 
/// the other as original.
///
/// Example:
/// Input: s = "abcdefg", k = 2
/// Output: "bacdfeg"
/// Restrictions:
/// The string consists of lower English letters only. 
/// Length of the given string and k will in the range [1, 10000]
/// </summary>
string LeetCodeString::reverseStr(string s, int k)
{
    size_t start = 0;
    while (start < s.size())
    {
        size_t end = min(start + k, s.size());
        std::reverse(s.begin() + start, s.begin() + end);
        start += 2 * k;
    }
    return s;
}

/// <summary>
/// Leet code #527. Word Abbreviation
/// </summary>
string LeetCodeString::makeAbbreviation(string& word, int k)
{
    if (word.size() - k - 1 > 1)
    {
        return word.substr(0, k) + to_string(word.size() - k - 1) + word.substr(word.size() - 1);
    }
    else
    {
        return word;
    }
}

/// <summary>
/// Leet code #527. Word Abbreviation
/// 
/// Given an array of n distinct non-empty strings, you need to 
/// generate minimal possible abbreviations for every word 
/// following rules below.
/// Begin with the first character and then the number of 
/// characters abbreviated, which followed by the last character.
/// If there are any conflict, that is more than one words share 
/// the same abbreviation, a longer prefix is used instead of 
/// only the first character until making the map from word to 
/// abbreviation become unique. In other words, a final 
/// abbreviation cannot map to more than one original words.
/// If the abbreviation doesn't make the word shorter, then 
/// keep it as original.
/// Example:
/// Input: ["like", "god", "internal", "me", "internet", 
///         "interval", "intension", "face", "intrusion"]
/// Output: ["l2e","god","internal","me","i6t","interval",
///          "inte4n","f2e","intr4n"]
/// Note:
/// Both n and the length of each word will not exceed 400.
/// The length of each word is greater than 1.
/// The words consist of lowercase English letters only.
/// The return answers should be in the same order as the 
/// original array.
/// </summary>
vector<string> LeetCodeString::wordsAbbreviation(vector<string>& dict)
{
    vector<string> result;
    vector<int> prefix;
    unordered_map<string, vector<int>> dup_set;
    for (string s : dict)
    {
        string abbr = makeAbbreviation(s, 1);
        dup_set[abbr].push_back(result.size());
        result.push_back(abbr);
        prefix.push_back(1);
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        while (dup_set[result[i]].size() > 1)
        {
            string abbr = result[i];
            for (int k : dup_set[abbr])
            {
                prefix[k]++;
                result[k] = makeAbbreviation(dict[k], prefix[k]);
                dup_set[result[k]].push_back(k);
            }
            dup_set.erase(abbr);
        }
    }

    return result;
}

/// <summary>
/// Leet code #392. Is Subsequence 
/// Given a string s and a string t, check if s is subsequence of t. 
/// You may assume that there is only lower case English letters in both s 
/// and t. 
/// t is potentially a very long (length ~= 500,000) string, and s is a short 
/// string (<=100). 
///
/// A subsequence of a string is a new string which is formed from the original 
/// string by deleting some (can be none) of the characters without disturbing 
/// the relative positions of the remaining characters. (ie, "ace" is a 
/// subsequence of "abcde" while "aec" is not). 
///
/// Example 1:
/// s = "abc", t = "ahbgdc" 
/// Return true.
///
/// Example 2:
/// s = "axc", t = "ahbgdc" 
/// Return false. 
/// 
/// Follow up:
/// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and 
/// you want to check one by one to see if T has its subsequence. In this 
/// scenario, how would you change your code?
/// </summary>
bool LeetCodeString::isSubsequence(string s, string t)
{
    size_t i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++; j++;
        }
        else
        {
            j++;
        }
    }
    if (i == s.size()) return true;
    else return false;
}

/// <summary>
/// Leet code #521. Longest Uncommon Subsequence I
/// 
/// Given a group of two strings, you need to find the longest uncommon 
/// subsequence of this group of two strings. The longest uncommon 
/// subsequence is defined as the longest subsequence of one of these 
/// strings and this subsequence should not be any subsequence of the other
/// strings. 
/// A subsequence is a sequence that can be derived from one sequence by 
/// deleting some characters without changing the order of the remaining 
/// elements. Trivially, any string is a subsequence of itself and an empty 
/// string is a subsequence of any string. 
/// The input will be two strings, and the output needs to be the length of 
/// the longest uncommon subsequence. If the longest uncommon subsequence 
/// doesn't exist, return -1. 
/// Example 1:
/// Input: "aba", "cdc"
/// Output: 3
/// Explanation: The longest uncommon subsequence is "aba" (or "cdc"), 
/// because "aba" is a subsequence of "aba", 
/// but not a subsequence of any other strings in the group of two strings. 
///
/// Note: 
/// Both strings' lengths will not exceed 100.
/// Only letters from a ~ z will appear in input strings. 
/// </summary>
int LeetCodeString::findLUSlength(string a, string b)
{
    if (a.size() == b.size())
    {
        if (isSubsequence(a, b)) return -1;
        else return a.size();
    }
    else
    {
        return max(a.size(), b.size());
    }
}

/// <summary>
/// Leet code #522. Longest Uncommon Subsequence II 
/// 
/// Given a list of strings, you need to find the longest uncommon 
/// subsequence among them. The longest uncommon subsequence is 
/// defined as the longest subsequence of one of these strings and 
/// this subsequence should not be any subsequence of the other 
/// strings. 
/// A subsequence is a sequence that can be derived from one 
/// sequence by deleting some characters without changing the order 
/// of the remaining elements. Trivially, any string is a subsequence 
/// of itself and an empty string is a subsequence of any string. 
/// The input will be a list of strings, and the output needs to be 
/// the length of the longest uncommon subsequence. If the longest 
/// uncommon subsequence doesn't exist, return -1. 
/// Example 1:
/// Input: "aba", "cdc", "eae"
/// Output: 3
/// Note: 
/// All the given strings' lengths will not exceed 10.
/// The length of the given list will be in the range of [2, 50].
/// </summary>
int LeetCodeString::findLUSlength(vector<string>& strs)
{
    map<int, map<string, int>> str_map;
    for (string str : strs)
    {
        str_map[0 - str.size()][str]++;
    }
    unordered_set<string> str_set;
    map<int, map<string, int>>::iterator itr;
    for (itr = str_map.begin(); itr != str_map.end(); itr++)
    {
        for (auto &str_cnt : itr->second)
        {
            // unique string in same length
            if (str_cnt.second == 1)
            {
                // compare it with all the longer ones, see if it is subsequence
                bool match = false;
                for (string longer_str : str_set)
                {
                    if (isSubsequence(str_cnt.first, longer_str))
                    {
                        match = true;
                        break;
                    }
                }
                if (match == false) return str_cnt.first.size();
            }
            str_set.insert(str_cnt.first);
        }
    }
    // Can not find a unique string
    return -1;
}

/// <summary>
/// Leet code #557. Reverse Words in a String III 
/// 
/// Given a string, you need to reverse the order of characters in each 
/// word within a sentence while still preserving whitespace and initial 
/// word order.
/// Example 1:
/// Input: "Let's take LeetCode contest"
/// Output: "s'teL ekat edoCteeL tsetnoc"
/// Note: In the string, each word is separated by single space and there 
/// will not be any extra space in the string. 
/// </summary>
string LeetCodeString::reverseWordsIII(string s)
{
    int first = 0;
    int last = 0;
    while (last <= (int)s.size())
    {
        if (last < (int)s.size() && !isspace(s[last]))
        {
            last++;
        }
        else if (first < last)
        {
            std::reverse(s.begin() + first, s.begin() + last);
            first = last + 1;
            last = first;
        }
        else
        {
            last++;
        }
    }
    return s;
}

/// <summary>
/// Leet code #551. Student Attendance Record I
/// 
/// You are given a string representing an attendance record for a student. 
/// The record only contains the following three characters: 
/// 'A' : Absent. 
/// 'L' : Late.
/// 'P' : Present. 
///
/// A student could be rewarded if his attendance record doesn't contain 
/// more than one 'A' (absent) or more than two continuous 'L' (late). 
/// You need to return whether the student could be rewarded according to 
/// his attendance record.
/// Example 1:
/// Input: "PPALLP"
/// Output: True
///
/// Example 2:
/// Input: "PPALLL"
/// Output: False
/// </summary>
bool LeetCodeString::checkRecord(string s)
{
    int absent = 0;
    int late = 0;
    for (char ch : s)
    {
        if (ch != 'L') late = 0;
        if (ch == 'L') late++;
        if (ch == 'A') absent++;
        if ((absent > 1) || (late > 2))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #567. Permutation in String
/// 
/// Given two strings s1 and s2, write a function to return true if s2 contains
/// the permutation of s1. In other words, one of the first string's 
/// permutations is the substring of the second string. 
/// Example 1:
/// Input:s1 = "ab" s2 = "eidbaooo"
/// Output:True
/// Explanation: s2 contains one permutation of s1 ("ba").
///
/// Example 2:
/// Input:s1= "ab" s2 = "eidboaoo"
/// Output: False
///
/// Note:
/// 1. The input strings only contain lower case letters.
/// 2. The length of both given strings is in range [1, 10,000].
/// </summary>
bool LeetCodeString::checkInclusion(string s1, string s2)
{
    vector<int> char_map(26);
    for (size_t i = 0; i < s1.size(); i++)
    {
        char_map[s1[i] - 'a']++;
    }
    int first = 0, last = 0;
    while (last < (int)s2.size())
    {
        if (last - first == s1.size()) break;
        char_map[s2[last] - 'a']--;
        while (char_map[s2[last] - 'a'] < 0)
        {
            char_map[s2[first] - 'a']++;
            first++;
        }
        last++;
    }
    return (last - first == s1.size());
}

/// <summary>
/// Leet code #609. Find Duplicate File in System 
/// 
/// Given a list of directory info including directory path, and all the 
/// files with contents in this directory, you need to find out all the 
/// groups of duplicate files in the file system in terms of their paths.
/// A group of duplicate files consists of at least two files that have 
/// exactly the same content.
/// A single directory info string in the input list has the following 
/// format: 
/// "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... 
/// fn.txt(fn_content)"
/// It means there are n files (f1.txt, f2.txt ... fn.txt with content 
/// f1_content, f2_content ... fn_content, respectively) in directory 
/// root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means 
/// the directory is just the root directory.
/// The output is a list of group of duplicate file paths. For each group, 
/// it contains all the file paths of the files that have the same 
/// content. 
/// A file path is a string that has the following format: 
/// "directory_path/file_name.txt"
/// Example 1:
/// Input:
/// ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", 
///  "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
/// Output:  
/// [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],
///  ["root/a/1.txt","root/c/3.txt"]]
/// Note:
/// 1. No order is required for the final output.
/// 2. You may assume the directory name, file name and file content only 
/// has letters and digits, and the length of file content is in the range 
/// of [1,50].
/// 3.The number of files given is in the range of [1,20000].
/// 4. You may assume no files or directories share the same name in a 
/// same directory.
/// 5. You may assume each given directory info represents a unique 
/// directory. Directory path and file infos are separated by a single 
/// blank space.
///
/// Follow up beyond contest: 
/// 1. Imagine you are given a real file system, how will you search files?
/// DFS or BFS ?
/// 2. If the file content is very large (GB level), how will you modify 
/// your solution?
/// 3. If you can only read the file by 1kb each time, how will you modify 
/// your solution?
/// 4. What is the time complexity of your modified solution? What is the 
/// most time consuming part and memory consuming part of it? How to 
/// optimize?
/// 5. How to make sure the duplicated files you find are not false 
/// positive?
/// </summary>
vector<vector<string>> LeetCodeString::findDuplicate(vector<string>& paths)
{
    unordered_map<string, vector<string>> file_map;
    vector<vector<string>> result;
    for (string str : paths)
    {
        size_t first = 0;
        size_t last = 0;
        while ((last < str.size()) && (!isspace(str[last]))) last++;
        string path = str.substr(first, last - first);
        string file_name;
        string file_content;
        first = last;
        while (last < str.size())
        {
            if (str[last] == '(')
            {
                file_name = str.substr(first, last - first);
                first = last + 1;
            }
            else if (str[last] == ')')
            {
                file_content = str.substr(first, last - first);
                first = last + 1;
                file_map[file_content].push_back(path + "/" + file_name);
            }
            else if (isspace(str[last]))
            {
                first = last + 1;
            }

            last++;
        }
    }
    for (auto &itr : file_map)
    {
        if (itr.second.size() > 1) result.push_back(itr.second);
    }
    return result;
}

/// <summary>
/// Leet code 616. Add Bold Tag in String
/// 
/// Given a string s and a list of strings dict, you need to add a closed 
/// pair of bold tag <b> and </b> to wrap the substrings in s that exist 
/// in dict. If two such substrings overlap, you need to wrap them 
/// together by only one pair of closed bold tag. Also, if two substrings 
/// wrapped by bold tags are consecutive, you need to combine them. 
/// Example 1:
/// Input: 
/// s = "abcxyz123"
/// dict = ["abc","123"]
/// Output:
/// "<b>abc</b>xyz<b>123</b>"
///
/// Example 2:
/// Input: 
/// s = "aaabbcc"
/// dict = ["aaa","aab","bc"]
/// Output:
/// "<b>aaabbc</b>c"
/// Note:
/// The given dict won't contain duplicates, and its length won't exceed 
/// 100.
/// All the strings in input have length in range [1, 1000]. 
/// </summary>
string LeetCodeString::addBoldTag(string s, vector<string>& dict)
{
    vector<pair<size_t, size_t>> bold_range;
    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, std::greater<pair<size_t, size_t>>> word_range;
    string result;

    // search word and insert ranges
    for (size_t i = 0; i < dict.size(); i++)
    {
        string word = dict[i];
        size_t pos = 0;
        while (true)
        {
            pos = s.find(word, pos);
            if (pos == string::npos) break;
            word_range.push(make_pair(pos, pos + word.size()));
            pos += 1;
        }
    }

    // merge ranges
    while (!word_range.empty())
    {
        pair<size_t, size_t> range = word_range.top();
        word_range.pop();
        if (bold_range.empty() || range.first > bold_range.back().second)
        {
            bold_range.push_back(range);
        }
        else
        {
            size_t index = bold_range.size() - 1;
            bold_range[index].first = min(range.first, bold_range[index].first);
            bold_range[index].second = max(range.second, bold_range[index].second);
        }
    }

    // output string
    size_t pos = 0;
    for (size_t i = 0; i <= s.size(); i++)
    {
        if (pos < bold_range.size() && i == bold_range[pos].first)
        {
            result.append("<b>");
        }
        else if (pos < bold_range.size() && i == bold_range[pos].second)
        {
            result.append("</b>");
            pos++;
        }
        if (i < s.size()) result.push_back(s[i]);
    }
    return result;
}

/// <summary>
/// Leet code #591. Tag Validator
/// </summary>
string LeetCodeString::getTag(string code, size_t &pos)
{
    string tag;
    while (pos < code.size() && (code[pos] != '>'))
    {
        char ch = code[pos];
        if (isupper(ch))
        {
            tag.push_back(ch);
        }
        else
        {
            return "";
        }
        if (tag.size() > 9) return "";
        pos++;
    }
    if (pos < code.size() && (code[pos] == '>'))
    {
        return tag;
    }
    else
    {
        return "";
    }
}

/// <summary>
/// Leet code #591. Tag Validator
/// 
/// Given a string representing a code snippet, you need to implement a tag 
/// validator to parse the code and return whether it is valid. A code 
/// snippet is valid if all the following rules hold:
/// 1.The code must be wrapped in a valid closed tag. Otherwise, the code 
///   is invalid.
/// 2.A closed tag (not necessarily valid) has exactly the following 
///   format : <TAG_NAME>TAG_CONTENT</TAG_NAME>. Among them, <TAG_NAME> is 
///   the start tag, and </TAG_NAME> is the end tag. The TAG_NAME in start 
///   and end tags should be the same. A closed tag is valid if and only 
///   if the TAG_NAME and TAG_CONTENT are valid.
/// 3.A valid TAG_NAME only contain upper-case letters, and has length in 
///   range [1,9]. Otherwise, the TAG_NAME is invalid.
/// 4.A valid TAG_CONTENT may contain other valid closed tags, cdata and 
///   any characters (see note1) EXCEPT unmatched <, unmatched start and 
///   end tag, and unmatched or closed tags with invalid TAG_NAME. 
///   Otherwise, the TAG_CONTENT is invalid.
/// 5.A start tag is unmatched if no end tag exists with the same TAG_NAME, 
///   and vice versa. However, you also need to consider the issue of 
///   unbalanced when tags are nested.
/// 6.A < is unmatched if you cannot find a subsequent >. And when you find 
///   a < or </, all the subsequent characters until the next > should be 
///   parsed as TAG_NAME (not necessarily valid).
/// 7.The cdata has the following format : <![CDATA[CDATA_CONTENT]]>. The 
///   range of CDATA_CONTENT is defined as the characters between 
///   <![CDATA[ and the first subsequent ]]>. 
/// 8.CDATA_CONTENT may contain any characters. The function of cdata is 
///   to forbid the validator to parse CDATA_CONTENT, so even it has some 
///   characters that can be parsed as tag (no matter valid or invalid), 
///   you should treat it as regular characters. 
///
/// Valid Code Examples:
/// Input: "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
/// Output: True
/// Explanation: 
/// The code is wrapped in a closed tag : <DIV> and </DIV>. 
/// The TAG_NAME is valid, the TAG_CONTENT consists of some characters and
/// cdata. 
/// Although CDATA_CONTENT has unmatched start tag with invalid TAG_NAME, 
/// it should be considered as plain text, not parsed as tag.
/// So TAG_CONTENT is valid, and then the code is valid. Thus return true.
/// Input: "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"
/// Output: True
/// Explanation:
/// We first separate the code into : start_tag|tag_content|end_tag.
/// start_tag -> "<DIV>"
/// end_tag -> "</DIV>"
/// tag_content could also be separated into : text1|cdata|text2.
/// text1 -> ">>  ![cdata[]] "
/// cdata -> "<![CDATA[<div>]>]]>", where the CDATA_CONTENT is "<div>]>"
/// text2 -> "]]>>]"
/// The reason why start_tag is NOT "<DIV>>>" is because of the rule 6.
/// The reason why cdata is NOT "<![CDATA[<div>]>]]>]]>" is because of the 
/// rule 7.
///
/// Invalid Code Examples:
/// Input: "<A>  <B> </A>   </B>"
/// Output: False
/// Explanation: Unbalanced. If "<A>" is closed, then "<B>" must be 
/// unmatched, and vice versa.
/// Input: "<DIV>  div tag is not closed  <DIV>"
/// Output: False
/// Input: "<DIV>  unmatched <  </DIV>"
/// Output: False
/// Input: "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>"
/// Output: False
/// Input: "<DIV> unmatched tags with invalid tag name  </1234567890> and 
///        <CDATA[[]]>  </DIV>"
/// Output: False
/// Input: "<DIV>  unmatched start tag <B>  and unmatched end tag </C>  
///        </DIV>"
/// Output: False
/// Note:
/// 1.For simplicity, you could assume the input code (including the any 
///   characters mentioned above) only contain letters, digits, '<','>',
///   '/','!','[',']' and ' '.
/// </summary>
bool LeetCodeString::isValid(string code)
{
    enum class HtmlState { Start, TagContent, DataContent, End };

    HtmlState state = HtmlState::Start;
    stack<string> tag_stack;
    for (size_t i = 0; i < code.size(); i++)
    {
        if (isspace(code[i])) continue;

        if (code[i] == '<')
        {
            if (state == HtmlState::DataContent) continue;
            if (state == HtmlState::End) return false;
            if (code.substr(i, 9) == "<![CDATA[")
            {
                if (state != HtmlState::TagContent) return false;
                i += (9 - 1);
                state = HtmlState::DataContent;
            }
            else if (code.substr(i, 2) == "</")
            {
                // in CData content we do not care
                if (state == HtmlState::TagContent)
                {
                    i += 2;
                    string tag = getTag(code, i);

                    // unmatch tag?
                    if (tag != tag_stack.top()) return false;

                    tag_stack.pop();
                    // out of tag?
                    if (tag_stack.empty()) state = HtmlState::End;

                }
                // unmatched end tag
                else
                {
                    return false;
                }
            }
            else
            {
                i++;
                string tag = getTag(code, i);
                if (tag.empty()) return false;
                else tag_stack.push(tag);
                state = HtmlState::TagContent;
            }
        }
        else if ((state == HtmlState::DataContent) && (code.substr(i, 3) == "]]>"))
        {
            i += (3 - 1);
            state = HtmlState::TagContent;
        }
        else if (state == HtmlState::Start || state == HtmlState::End)
        {
            return false;
        }
    }
    if (state == HtmlState::End) return true;
    else return false;
}

/// <summary>
/// Leet code #640. Solve the Equation
/// 
/// Solve a given equation and return the value of x in the form of string 
/// "x=#value". The equation contains only '+', '-' operation, the variable 
/// x and its coefficient. 
/// If there is no solution for the equation, return "No solution". 
/// If there are infinite solutions for the equation, return "Infinite 
/// solutions". 
/// If there is exactly one solution for the equation, we ensure that the 
/// value of x is an integer. 
///
/// Example 1:
/// Input: "x+5-3+x=6+x-2"
/// Output: "x=2"
/// 
/// Example 2:
/// Input: "x=x"
/// Output: "Infinite solutions"
///
/// Example 3:
/// Input: "2x=x"
/// Output: "x=0"
///
/// Example 4:
/// Input: "2x+3x-6x=x+2"
/// Output: "x=-1"
///
/// Example 5:
/// Input: "x=x+2"
/// Output: "No solution"
/// </summary>
string LeetCodeString::solveEquation(string equation)
{
    int coefficient = 0;
    int constant = 0;
    string sign = "+";
    string equal = "";
    string token = "";
    string result;

    for (size_t i = 0; i <= equation.size(); i++)
    {
        if (i == equation.size())
        {
            if (!token.empty()) constant += (equal == "=" ? 1 : -1) * (sign == "+" ? 1 : -1) * atoi(token.c_str());
            token.clear();
        }
        else if ((equation[i] == '+') || (equation[i] == '-'))
        {
            if (!token.empty()) constant += (equal == "=" ? 1 : -1) * (sign == "+" ? 1 : -1) * atoi(token.c_str());
            token.clear();
            sign.clear();
            sign.push_back(equation[i]);
        }
        else if (equation[i] == '=')
        {
            if (!token.empty()) constant += (equal == "=" ? 1 : -1) * (sign == "+" ? 1 : -1) * atoi(token.c_str());
            token.clear();
            equal = "=";
            sign = "+";
        }
        else if (equation[i] == 'x')
        {
            if (token.empty())
            {
                coefficient += (equal == "=" ? -1 : 1) * (sign == "+" ? 1 : -1) * 1;
            }
            else
            {
                coefficient += (equal == "=" ? -1 : 1) * (sign == "+" ? 1 : -1) * atoi(token.c_str());
            }
            token.clear();
        }
        else if (isdigit(equation[i]))
        {
            token.push_back(equation[i]);
        }
    }

    if (coefficient == 0)
    {
        if (constant != 0) result = "No solution";
        else result = "Infinite solutions";

    }
    else
    {
        result = "x=" + to_string(constant / coefficient);
    }
    return result;
}

/// <summary>
/// Leet code #648. Replace Words
/// </summary>
string LeetCodeString::replaceWord(unordered_map<int, unordered_set<string>>&dict_map, const string&word)
{
    string result = word;
    for (size_t i = 0; i < word.size(); i++)
    {
        string sub_word = word.substr(0, i + 1);
        if (dict_map[sub_word.size()].count(sub_word) > 0)
        {
            result = sub_word;
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #648. Replace Words
/// 
/// In English, we have a concept called root, which can be followed by 
/// some other words to form another longer word - let's call this word 
/// successor. For example, the root an, followed by other, which can 
/// form another word another. 
/// Now, given a dictionary consisting of many roots and a sentence. You 
/// need to replace all the successor in the sentence with the root forming 
/// it. If a successor has many roots can form it, replace it with the root 
/// with the shortest length. 
/// You need to output the sentence after the replacement. 
/// Example 1:
/// Input: dict = ["cat", "bat", "rat"]
/// sentence = "the cattle was rattled by the battery"
/// Output: "the cat was rat by the bat"
///
/// Note:
/// 1. The input will only have lower-case letters.
/// 2. 1 <= dict words number <= 1000 
/// 3. 1 <= sentence words number <= 1000 
/// 4. 1 <= root length <= 100 
/// 5. 1 <= sentence words length <= 1000 
/// </summary>
string LeetCodeString::replaceWords(vector<string>& dict, string sentence)
{
    string result;
    unordered_map<int, unordered_set<string>> dict_map;
    for (size_t i = 0; i < dict.size(); i++)
    {
        dict_map[dict[i].size()].insert(dict[i]);
    }
    int first = 0, last = 0;
    while (last <= (int)sentence.size())
    {
        if (last == sentence.size() || isspace(sentence[last]))
        {
            if (first < last)
            {
                if (!result.empty()) result.push_back(' ');
                string word = replaceWord(dict_map, sentence.substr(first, last - first));
                result.append(word);
            }
            first = last + 1;
        }
        last++;
    }
    return result;
}

/// <summary>
/// Leet code #686. Repeated String Match
///
/// Given two strings A and B, find the minimum number of times A has to 
/// be repeated such that B is a substring of it. If no such solution, 
/// return -1.
///
/// For example, with A = "abcd" and B = "cdabcdab".
/// Return 3, because by repeating A three times ("abcdabcdabcd"), 
/// B is a substring of it; and B is not a substring of A repeated 
/// two times ("abcdabcd").
///
/// Note:
/// The length of A and B will be between 1 and 10000.
/// </summary>
int LeetCodeString::repeatedStringMatch(string A, string B)
{
    vector<int> kmp(B.size());
    int i = 1;
    int j = 0;
    while (i < (int)B.size())
    {
        if (B[i] == B[j])
        {
            j++;
            kmp[i] = j;
            i++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = kmp[j - 1];
        }
    }
    int result = 0;
    i = 0;
    j = 0;
    while (j < (int)B.size())
    {
        if (i == A.size())
        {
            result++;
            i = 0;
        }
        else if (A[i] == B[j])
        {
            i++;
            j++;
        }
        else
        {
            if ((result - 1) * (int)A.size() + i > j)
            {
                return -1;
            }
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = kmp[j - 1];
            }
        }
    }
    return result + 1;
}

/// <summary>
/// Leet code #720. Longest Word in Dictionary
///
/// Given a list of strings words representing an English Dictionary, find 
/// the longest word in words that can be built one character at a time by 
/// other words in words. If there is more than one possible answer, 
/// return the longest word with the smallest lexicographical order.
/// 
/// If there is no answer, return the empty string.
/// Example 1:
/// Input: 
/// words = ["w","wo","wor","worl", "world"]
/// Output: "world"
/// Explanation: 
/// The word "world" can be built one character at a time by "w", "wo", 
/// "wor", and "worl".
///
/// Example 2:
/// Input: 
/// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
/// Output: "apple"
/// Explanation: 
/// Both "apply" and "apple" can be built from other words in the 
/// dictionary. However, "apple" is lexicographically smaller than 
/// "apply".
/// 
/// Note:
///
/// All the strings in the input will only contain lowercase letters.
/// The length of words will be in the range [1, 1000].
/// The length of words[i] will be in the range [1, 30].
/// </summary>
string LeetCodeString::longestWord(vector<string>& words)
{
    set<pair<int, string>> pq;
    unordered_set<string> word_map;
    word_map.insert("");
    for (size_t i = 0; i < words.size(); i++)
    {
        pq.insert(make_pair((int)words[i].size(), words[i]));
    }
    string result;
    while (!pq.empty())
    {
        pair<int, string> pair = *pq.begin();
        pq.erase(pq.begin());
        if (pair.first > (int)result.size() + 1) break;
        if (word_map.count(pair.second.substr(0, pair.first - 1)) == 0)
        {
            continue;
        }
        word_map.insert(pair.second);
        // longer word found
        if (pair.first > (int)result.size())
        {
            result = pair.second;
        }
    }
    return result;
}

/// <summary>
/// Leet code #722. Remove Comments
///
/// Given a C++ program, remove comments from it. The program source is an 
/// array where source[i] is the i-th line of the source code. This 
/// represents the result of splitting the original source code string by 
/// the newline character \n.
///
/// In C++, there are two types of comments, line comments, and block 
/// comments.
///
/// The string // denotes a line comment, which represents that it and 
/// rest of the characters to the right of it in the same line should be 
/// ignored.
/// The string /* denotes a block comment, which represents that all 
/// characters until the next (non-overlapping) occurrence of */ should 
/// be ignored. (Here, occurrences happen in reading order: line by line 
/// from left to right.) To be clear, the string /*/ does not yet end the 
/// block comment, as the ending would be overlapping the beginning.
///
/// The first effective comment takes precedence over others: if the 
/// string // occurs in a block comment, it is ignored. Similarly, if the 
/// string /* occurs in a line or block comment, it is also ignored.
/// If a certain line of code is empty after removing comments, you must 
/// not output that line: each string in the answer list will be non-empty.
///
/// There will be no control characters, single quote, or double quote 
/// characters. For example, source = "string s = "/* Not a comment. */";" 
/// will not be a test case. (Also, nothing else such as defines or macros 
/// will interfere with the comments.)
///
/// It is guaranteed that every open block comment will eventually be 
/// closed, so /* outside of a line or block comment always starts a new 
/// comment.
/// 
/// Finally, implicit newline characters can be deleted by block comments. 
/// Please see the examples below for details.
///
/// After removing the comments from the source code, return the source 
/// code in the same format.
///
/// Example 1:
/// Input: 
/// source = ["/*Test program */", "int main()", "{ ", 
/// "  // variable declaration ", "int a, b, c;", "/* This is a test", 
/// "   multiline  ", "   comment for ", 
/// "   testing */", "a = b + c;", "}"]
///
/// The line by line code is visualized as below:
/// /*Test program */
/// int main()
/// { 
///     // variable declaration 
///     int a, b, c;
///     /* This is a test
///        multiline  
///        comment for 
///        testing */
///        a = b + c;
/// }
///
/// Output: ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]
/// 
/// The line by line code is visualized as below:
/// int main()
/// { 
///  
///     int a, b, c;
///     a = b + c;
/// }
///
/// Explanation: 
/// The string 
/// /*
/// denotes a block comment, including line 1 and lines 6-9. The string 
/// //
/// denotes line 4 as comments.
/// Example 2:
/// Input: 
/// source = ["a/*comment", "line", "more_comment*/b"]
/// Output: ["ab"]
/// Explanation: The original source string is 
/// "a/*comment\nline\nmore_comment*/b", where we have bolded the newline
/// characters.  After deletion, the implicit newline characters are 
/// deleted, leaving the string "ab", which when delimited by newline 
/// characters becomes ["ab"].
/// Note:
///
/// The length of source is in the range [1, 100].
/// The length of source[i] is in the range [0, 80].
/// Every open block comment is eventually closed.
/// There are no single-quote, double-quote, or control characters in the 
/// source code.
/// </summary>
vector<string> LeetCodeString::removeComments(vector<string>& source)
{
    vector<string> result;
    string line;
    enum class CodeState
    {
        NONE, SINGLE_LINE_COMMENT, MULTI_LINE_COMMENT
    };
    CodeState state = CodeState::NONE;
    for (size_t i = 0; i < source.size(); i++)
    {
        char prev_ch = 0;
        for (size_t j = 0; j < source[i].size(); j++)
        {
            if (state == CodeState::NONE)
            {
                // check multi line comments start
                if ((source[i][j] == '*') && (prev_ch == '/'))
                {
                    line.pop_back();
                    state = CodeState::MULTI_LINE_COMMENT;
                    prev_ch = 0;
                }
                // single line comment
                else if ((source[i][j] == '/') && (prev_ch == '/'))
                {
                    line.pop_back();
                    state = CodeState::SINGLE_LINE_COMMENT;
                    prev_ch = 0;
                }
                else
                {
                    line.push_back(source[i][j]);
                    prev_ch = source[i][j];
                }
            }
            else if (state == CodeState::MULTI_LINE_COMMENT)
            {
                // check multi line comments end
                if ((source[i][j] == '/') && (prev_ch == '*'))
                {
                    state = CodeState::NONE;
                    prev_ch = 0;
                }
                else prev_ch = source[i][j];
            }
        }
        // cancel single line comment state
        if (state == CodeState::SINGLE_LINE_COMMENT)
        {
            state = CodeState::NONE;
        }
        if ((state != CodeState::MULTI_LINE_COMMENT) && (!line.empty()))
        {
            result.push_back(line);
            line.clear();
        }
    }
    return result;
}

/// <summary>
/// Leet code #726. Number of Atoms
/// </summary>
string LeetCodeString::parseAtom(string &formula, int& index)
{
    string token;
    while (index < (int)formula.size())
    {
        if (isupper(formula[index]))
        {
            if (token.empty()) token.push_back(formula[index]);
            else break;
        }
        else if (islower(formula[index]))
        {
            token.push_back(formula[index]);
        }
        else
        {
            break;
        }
        index++;
    }
    return token;
}

/// <summary>
/// Leet code #726. Number of Atoms
/// </summary>
int LeetCodeString::parseAtomCount(string &formula, int& index)
{
    string token;
    while (isdigit(formula[index]))
    {
        token.push_back(formula[index]);
        index++;
    }
    int count = atoi(token.c_str());
    return count;
}


/// <summary>
/// Leet code #726. Number of Atoms
/// </summary>
void LeetCodeString::multiplyFormula(map<string, int> &atom_count, int& count)
{
    for (auto &itr : atom_count)
    {
        atom_count[itr.first] = itr.second * count;
    }
}

/// <summary>
/// Leet code #726. Number of Atoms
/// </summary>
void LeetCodeString::mergeFormula(map<string, int> &atom_count, vector<map<string, int>>& formula_array)
{
    int index = formula_array.size() - 1;
    for (auto itr : atom_count)
    {
        formula_array[index][itr.first] += atom_count[itr.first];
    }
    atom_count.clear();
}

/// <summary>
/// Leet code #726. Number of Atoms
/// Given a chemical formula (given as a string), return the count of each 
/// atom.
/// An atomic element always starts with an uppercase character, then zero 
/// or more lowercase letters, representing the name.
/// 
/// 1 or more digits representing the count of that element may follow if 
/// the count is greater than 1. If the count is 1, no digits will follow. 
/// For example, H2O and H2O2 are possible, but H1O2 is impossible.
///
/// Two formulas concatenated together produce another formula. For 
/// example, H2O2He3Mg4 is also a formula.
///
/// A formula placed in parentheses, and a count (optionally added) is also 
/// a formula. For example, (H2O2) and (H2O2)3 are formulas.
///
/// Given a formula, output the count of all elements as a string in the 
/// following form: the first name (in sorted order), followed by its 
/// count (if that count is more than 1), followed by the second name 
/// (in sorted order), followed by its count 
/// (if that count is more than 1), and so on.
///
/// Example 1:
/// Input: 
/// formula = "H2O"
/// Output: "H2O"
/// Explanation: 
/// The count of elements are {'H': 2, 'O': 1}.
/// Example 2:
/// Input: 
/// formula = "Mg(OH)2"
/// Output: "H2MgO2"
/// Explanation: 
/// The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
/// Example 3:
/// Input: 
/// formula = "K4(ON(SO3)2)2"
/// Output: "K4N2O14S4"
/// Explanation: 
/// The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
/// Note:
///
/// 1. All atom names consist of lowercase letters, except for the first 
/// character which is uppercase.
/// 2. The length of formula will be in the range [1, 1000].
/// formula will only consist of letters, digits, and round parentheses, 
/// and is a valid formula as defined in the problem.
/// </summary>
string LeetCodeString::countOfAtoms(string formula)
{
    string result;
    int index = 0;
    map<string, int> atom_count;
    vector<map<string, int>> formula_array;
    formula_array.push_back(atom_count);

    while (index <= (int)formula.size())
    {
        if (index == formula.size())
        {
            mergeFormula(atom_count, formula_array);
            index++;
        }
        else if (isupper(formula[index]))
        {
            mergeFormula(atom_count, formula_array);
            string atom = parseAtom(formula, index);
            atom_count[atom] = 1;
        }
        else if (isdigit(formula[index]))
        {
            int count = parseAtomCount(formula, index);
            multiplyFormula(atom_count, count);
            mergeFormula(atom_count, formula_array);
        }
        else if (formula[index] == '(')
        {
            mergeFormula(atom_count, formula_array);
            // push an empty 
            formula_array.push_back(atom_count);
            index++;
        }
        else if (formula[index] == ')')
        {
            mergeFormula(atom_count, formula_array);
            atom_count = formula_array.back();
            formula_array.pop_back();
            index++;
        }
        else
        {
            index++;
        }
    }
    for (auto &itr : formula_array.back())
    {
        result += itr.first;
        if (itr.second > 1) result += to_string(itr.second);
    }
    return result;
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
string LeetCodeString::parseLispToken(string& expression, int& index)
{
    string result;
    while (index < (int)expression.size())
    {
        if (isspace(expression[index]))
        {
            index++;
            if (!result.empty()) break;
        }
        else if ((expression[index] == '(') || (expression[index] == ')'))
        {
            if (!result.empty()) break;
            else
            {
                result.push_back(expression[index]);
                index++;
                break;
            }
        }
        else
        {
            result.push_back(expression[index]);
            index++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
int LeetCodeString::calculateLispCommand(string& command, vector<string>& parameters, unordered_map<string, int>&variables)
{
    int result = 0;
    for (size_t i = 0; i < parameters.size(); i++)
    {
        if (islower(parameters[i][0]))
        {
            parameters[i] = to_string(variables[parameters[i]]);
        }
    }
    if (command == "add")
    {
        result = atoi(parameters[0].c_str()) + atoi(parameters[1].c_str());
    }
    else if (command == "mult")
    {
        result = atoi(parameters[0].c_str()) * atoi(parameters[1].c_str());
    }
    else if (command == "let")
    {
        result = atoi(parameters[0].c_str());
    }
    return result;
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
int LeetCodeString::processLispCommand(string& expression, int& index, unordered_map<string, int> variables)
{
    string command;
    vector<string> parameters;

    while (index < (int)expression.size())
    {
        string token = parseLispToken(expression, index);
        if (token == ")")
        {
            if (!command.empty()) break;
        }
        else if (token == "(")
        {
            if (!command.empty())
            {
                int parameter = processLispCommand(expression, index, variables);
                parameters.push_back(to_string(parameter));
            }
        }
        else if (command.empty())
        {
            command = token;
        }
        else
        {
            parameters.push_back(token);
        }
        if ((command == "let") && (parameters.size() == 2))
        {
            if (islower(parameters[1][0]))
            {
                variables[parameters[0]] = variables[parameters[1]];
            }
            else
            {
                variables[parameters[0]] = atoi(parameters[1].c_str());
            }
            parameters.clear();
        }
    }
    return calculateLispCommand(command, parameters, variables);
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
///
/// You are given a string expression representing a Lisp-like expression to 
/// return the integer value of.
///
/// The syntax for these expressions is given as follows.
///
/// An expression is either an integer, a let-expression, an add-expression, 
/// a mult-expression, or an assigned variable. Expressions always evaluate to 
/// a single integer.
/// (An integer could be positive or negative.)
/// A let-expression takes the form (let v1 e1 v2 e2 ... vn en expr), where 
/// let is always the string "let", then there are 1 or more pairs of 
/// alternating variables and expressions, meaning that the first variable v1 
/// is assigned the value of the expression e1, the second variable v2 is 
/// assigned the value of the expression e2, and so on sequentially; and then 
/// the value of this let-expression is the value of the expression expr.
///
/// An add-expression takes the form (add e1 e2) where add is always the string
/// "add", there are always two expressions e1, e2, and this expression 
/// evaluates to the addition of the evaluation of e1 and the evaluation of e2.
///
/// A mult-expression takes the form (mult e1 e2) where mult is always the 
/// string "mult", there are always two expressions e1, e2, and this expression
/// evaluates to the multiplication of the evaluation of e1 and the evaluation 
/// of e2.
///
/// For the purposes of this question, we will use a smaller subset of variable 
/// names. A variable starts with a lowercase letter, then zero or more 
/// lowercase letters or digits. Additionally for your convenience, the names 
/// "add", "let", or "mult" are protected and will never be used as variable 
/// names.
/// Finally, there is the concept of scope. When an expression of a variable 
/// name is evaluated, within the context of that evaluation, the innermost 
/// scope (in terms of parentheses) is checked first for the value of that 
/// variable, and then outer scopes are checked sequentially. It is guaranteed 
/// that every expression is legal. Please see the examples for more details on
/// scope.
/// Evaluation Examples:
/// Input: (add 1 2)
/// Output: 3
/// 
/// Input: (mult 3 (add 2 3))
/// Output: 15
///
/// Input: (let x 2 (mult x 5))
/// Output: 10
///
/// Input: (let x 2 (mult x (let x 3 y 4 (add x y))))
/// Output: 14
/// Explanation: In the expression (add x y), when checking for the value of 
/// the variable x,
/// we check from the innermost scope to the outermost in the context of the 
/// variable we are trying to evaluate.
/// Since x = 3 is found first, the value of x is 3.
///
/// Input: (let x 3 x 2 x)
/// Output: 2
/// Explanation: Assignment in let statements is processed sequentially.
///
/// Input: (let x 1 y 2 x (add x y) (add x y))
/// Output: 5
/// Explanation: The first (add x y) evaluates as 3, and is assigned to x.
/// The second (add x y) evaluates as 3+2 = 5.
///
/// Input: (let x 2 (add (let x 3 (let x 4 x)) x))
/// Output: 6
/// Explanation: Even though (let x 4 x) has a deeper scope, it is outside 
/// the context
/// of the final x in the add-expression.  That final x will equal 2.
///
/// Input: (let a1 3 b2 (add a1 1) b2) 
/// Output 4
/// Explanation: Variable names can contain digits after the first character.
/// 
/// Note:
///
/// 1. The given string expression is well formatted: There are no leading or 
/// trailing spaces, there is only a single space separating different 
/// components of the string, and no space between adjacent parentheses. 
/// 2. The expression is guaranteed to be legal and evaluate to an integer.
/// 3. The length of expression is at most 2000. (It is also non-empty, as that 
/// would not be a legal expression.)
/// 4. The answer and all intermediate calculations of that answer are guaranteed 
/// to fit in a 32-bit integer.
/// </summary>
int LeetCodeString::evaluate(string expression)
{
    int index = 0;
    unordered_map<string, int> variables;
    return processLispCommand(expression, index, variables);
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
int LeetCodeString::processLispExpression(vector<string>& tokens, int& index, unordered_map<string, int> variables)
{
    int result;
    if (islower(tokens[index][0]))
    {
        result = variables[tokens[index]];
    }
    else if (tokens[index] == "(")
    {
        result = processLispCommand(tokens, index, variables);
    }
    else
    {
        result = atoi(tokens[index].c_str());
    }
    index++;
    return result;
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
int LeetCodeString::processLispCommand(vector<string>& tokens, int& index, unordered_map<string, int> variables)
{
    if (tokens[index] == "(") index++;
    string command = tokens[index];
    index++;
    int result = 0;
    while (tokens[index] != ")")
    {
        if (command == "add")
        {
            result = processLispExpression(tokens, index, variables) +
                processLispExpression(tokens, index, variables);
        }
        else if (command == "mult")
        {
            result = processLispExpression(tokens, index, variables) *
                processLispExpression(tokens, index, variables);
        }
        else if (command == "let")
        {
            int count = 0;
            string variable;
            int value = 0;
            while (tokens[index] != ")")
            {
                if (islower(tokens[index][0]) && (count == 0))
                {
                    variable = tokens[index];
                    value = variables[variable];
                    index++;
                }
                else
                {
                    value = processLispExpression(tokens, index, variables);
                }
                count++;
                if (count == 2)
                {
                    variables[variable] = value;
                    count = 0;
                }
            }
            result = value;
        }
    }
    return result;
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
int LeetCodeString::evaluate_V2(string expression)
{
    int index = 0;
    vector<string> tokens;
    while (index < (int)expression.size())
    {
        string token = parseLispToken(expression, index);
        tokens.push_back(token);
    }
    unordered_map<string, int> variables;
    index = 0;
    return processLispCommand(tokens, index, variables);
}

/// <summary>
/// Leet code #751. IP to CIDR
/// </summary>
unsigned int LeetCodeString::convertIpV4ToInt(string ipV4)
{
    unsigned int ipaddress = 0;
    string token;
    for (size_t i = 0; i <= ipV4.size(); i++)
    {
        if ((i == ipV4.size() || ipV4[i] == '.') && (!token.empty()))
        {
            ipaddress = ipaddress * 256 + atoi(token.c_str());
            token.clear();
        }
        else if (isdigit(ipV4[i]))
        {
            token.push_back(ipV4[i]);
        }
    }
    return ipaddress;
}

/// <summary>
/// Leet code #751. Integer to IPv4
/// </summary>
string LeetCodeString::convertIntToIpV4(unsigned int ipV4)
{
    string ipaddress;
    for (size_t i = 0; i < 4; i++)
    {
        if (ipaddress.empty())
        {
            ipaddress = to_string(ipV4 % 256);
        }
        else
        {
            ipaddress = to_string(ipV4 % 256) + "." + ipaddress;
        }
        ipV4 /= 256;
    }
    return ipaddress;
}

/// <summary>
/// Leet code #751. IP to CIDR
///
/// Given a start IP address ip and a number of ips we need to cover n, 
/// return a representation of the range as a list (of smallest possible 
/// length) of CIDR blocks.
/// 
/// A CIDR block is a string consisting of an IP, followed by a slash, 
/// and then the prefix length. For example: "123.45.67.89/20". That 
/// prefix length "20" represents the number of common prefix bits in the 
/// specified range.
///
/// Example 1:
/// Input: ip = "255.0.0.7", n = 10
/// Output: ["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]
/// Explanation:
/// The initial ip address, when converted to binary, looks like this 
/// (spaces added for clarity):
/// 255.0.0.7 -> 11111111 00000000 00000000 00000111
/// The address "255.0.0.7/32" specifies all addresses with a common 
/// prefix of 32 bits to the given address,
/// ie. just this one address.
///
/// The address "255.0.0.8/29" specifies all addresses with a common 
/// prefix of 29 bits to the given address:
/// 255.0.0.8 -> 11111111 00000000 00000000 00001000
/// Addresses with common prefix of 29 bits are:
/// 11111111 00000000 00000000 00001000
/// 11111111 00000000 00000000 00001001
/// 11111111 00000000 00000000 00001010
/// 11111111 00000000 00000000 00001011
/// 11111111 00000000 00000000 00001100
/// 11111111 00000000 00000000 00001101
/// 11111111 00000000 00000000 00001110
/// 11111111 00000000 00000000 00001111
///
/// The address "255.0.0.16/32" specifies all addresses with a common 
/// prefix of 32 bits to the given address,
/// ie. just 11111111 00000000 00000000 00010000.
///
/// In total, the answer specifies the range of 10 ips starting with the 
/// address 255.0.0.7 .
///
/// There were other representations, such as:
/// ["255.0.0.7/32","255.0.0.8/30", "255.0.0.12/30", "255.0.0.16/32"],
/// but our answer was the shortest possible.
///
/// Also note that a representation beginning with say, "255.0.0.7/30" 
/// would be incorrect,
/// because it includes addresses like 255.0.0.4 = 11111111 00000000 
/// 00000000 00000100 
/// that are outside the specified range.
/// Note:
/// 1. ip will be a valid IPv4 address.
/// 2. Every implied address ip + x (for x < n) will be a valid IPv4 
///    address.
/// 3. n will be an integer in the range [1, 1000].
/// </summary>
vector<string> LeetCodeString::ipToCIDR(string ip, int range)
{
    vector<string> result;
    unsigned int ipV4Int = convertIpV4ToInt(ip);
    while (range > 0)
    {
        // get the lowest significant bit from IP address
        unsigned int low_bit = ipV4Int & (-(int)ipV4Int);
        // calculate prefix
        unsigned int prefix = 32 - (unsigned int)log2(low_bit);
        // if lowerest bit cover too many IP address, reduce it
        while (low_bit > (unsigned int)range)
        {
            low_bit >>= 1;
            prefix++;
        }
        string ipaddress = convertIntToIpV4(ipV4Int);
        result.push_back(ipaddress + "/" + to_string(prefix));
        ipV4Int += low_bit;
        range -= low_bit;
    }
    return result;
}

/// <summary>
/// Leet code #761. Special Binary String    
///
/// Special binary strings are binary strings with the following two 
/// properties:
///
/// The number of 0's is equal to the number of 1's.
/// Every prefix of the binary string has at least as many 1's as 0's.
/// Given a special string S, a move consists of choosing two consecutive, 
/// non-empty, special substrings of S, and swapping them. (Two strings 
/// are consecutive if the last character of the first string is exactly one 
/// index before the first character of the second string.)
///
/// At the end of any number of moves, what is the lexicographically largest 
/// resulting string possible?
///
/// Example 1:
/// Input: S = "11011000"
/// Output: "11100100"
/// Explanation:
/// The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
/// This is the lexicographically largest string possible after some number 
/// of swaps.
/// Note:
///
/// 1. S has length at most 50.
/// 2. S is guaranteed to be a special binary string as defined above.	
/// </summary>
string LeetCodeString::makeLargestSpecial(string S)
{
    string result = "";
    vector<string> special_strings;
    int first = 0;
    int count = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == '1') count++;
        else
        {
            count--;
            if (count == 0)
            {
                special_strings.push_back(S.substr(first, i - first + 1));
                first = i + 1;
            }
        }
    }
    for (size_t i = 0; i < special_strings.size(); i++)
    {
        if (special_strings[i].size() > 2)
        {
            string inner_string = special_strings[i].substr(1, special_strings[i].size() - 2);
            special_strings[i] = "1" + makeLargestSpecial(inner_string) + "0";
        }
    }
    sort(special_strings.begin(), special_strings.end(), greater<string>());
    for (size_t i = 0; i < special_strings.size(); i++)
    {
        result.append(special_strings[i]);
    }

    return result;
}

/// <summary>
/// Leet code #758. Bold Words in String    
///
/// Given a set of keywords words and a string S, make all appearances of 
/// all keywords in S bold. Any letters between <b> and </b> tags become 
/// bold. 
///
/// The returned string should use the least number of tags possible, and 
/// of course the tags should form a valid combination. 
///
/// For example, given that words = ["ab", "bc"] and S = "aabcd", we should 
/// return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would 
/// use more tags, so it is incorrect. 
///
/// Note:
/// 1.words has length in range [0, 50].
/// 2.words[i] has length in range [1, 10].
/// 3.S has length in range [0, 500].
/// 4.All characters in words[i] and S are lowercase letters.
/// </summary>
string LeetCodeString::boldWords(vector<string>& words, string S)
{
    vector<int> bold(S.size());
    string result;
    if (S.empty()) return result;
    unordered_set<string> word_set;
    for (string str : words) word_set.insert(str);
    int len = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        for (len = 1; (len <= 10) && (i + len) <= S.size(); len++)
        {
            if (word_set.count(S.substr(i, len)) > 0)
            {
                for (size_t j = i; j < i + len; j++) bold[j] = 1;
            }
        }
    }

    for (size_t i = 0; i <= bold.size(); i++)
    {
        if (i == bold.size())
        {
            if (bold[i - 1] == 1) result += "</b>";
        }
        else if ((i > 0) && (bold[i] == 0) && (bold[i - 1] == 1))
        {
            result += "</b>";
            result.push_back(S[i]);
        }
        else if ((bold[i] == 1) && ((i == 0) || (bold[i - 1] == 0)))
        {
            result += "<b>";
            result.push_back(S[i]);
        }
        else
        {
            result.push_back(S[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #772. Basic Calculator III
/// </summary>
string LeetCodeString::parseExpressionToken(string s, int& index)
{
    string result;
    while (index < (int)s.size())
    {
        if (isalnum(s[index]))
        {
            result.push_back(s[index]);
            index++;
        }
        else if (isspace(s[index]))
        {
            index++;
        }
        else
        {
            if (!result.empty()) break;
            else
            {
                result = s[index];
                index++;
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #772. Basic Calculator III   
/// </summary>
int LeetCodeString::parseFactor(vector<string>& tokens, int& index)
{
    int result = 0;
    if (isdigit(tokens[index][0]))
    {
        result = atoi(tokens[index].c_str());
    }
    else if (tokens[index] == "(")
    {
        index++;
        result = parseExpression(tokens, index);
        // when return with ")" left there
    }
    index++;
    return result;
}

/// <summary>
/// Leet code #772. Basic Calculator III   
/// </summary>
int LeetCodeString::parseTerm(vector<string>& tokens, int& index)
{
    int result = parseFactor(tokens, index);
    while (index < (int)tokens.size())
    {
        if (tokens[index] == "*")
        {
            index++;
            result *= parseFactor(tokens, index);
        }
        else if (tokens[index] == "/")
        {
            index++;
            result /= parseFactor(tokens, index);
        }
        else
        {
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #772. Basic Calculator III   
/// </summary>
int LeetCodeString::parseExpression(vector<string>& tokens, int& index)
{
    int result = parseTerm(tokens, index);
    while (index < (int)tokens.size())
    {
        if (tokens[index] == "+")
        {
            index++;
            result += parseTerm(tokens, index);
        }
        else if (tokens[index] == "-")
        {
            index++;
            result -= parseTerm(tokens, index);
        }
        else
        {
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #772. Basic Calculator III   
///
/// Implement a basic calculator to evaluate a simple expression string.
/// The expression string may contain open ( and closing parentheses ), 
/// the plus + or minus sign -, non-negative integers and empty spaces.
/// 
/// The expression string contains only non-negative integers, +, -, *, / 
/// operators , open ( and closing parentheses ) and empty spaces . 
/// The integer division should truncate toward zero.
///
/// You may assume that the given expression is always valid. All 
/// intermediate results will be in the range of [-2147483648, 2147483647].
///
/// Some examples:
///
/// "1 + 1" = 2
/// " 6-4 / 2 " = 4
/// "2*(5+5*2)/3+(6/2+8)" = 21
/// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
/// </summary>
int LeetCodeString::calculateIII(string s)
{
    vector<string> tokens;
    int index = 0;
    while (index < (int)s.size())
    {
        tokens.push_back(parseExpressionToken(s, index));
    }
    index = 0;
    int result = parseExpression(tokens, index);
    return result;
}


/// <summary>
/// Leet code #770. Basic Calculator IV   
/// </summary>
vector<string> LeetCodeString::polyToString(map<vector<string>, int> &ploy_map)
{
    vector<pair<vector<string>, int>> poly_vector;
    typedef struct _greater_poly
    {
        bool operator() (pair<vector<string>, int>&a, pair<vector<string>, int> &b)
        {
            if (a.first.size() != b.first.size())
            {
                return (a.first.size() > b.first.size());
            }
            else
            {
                return (a.first < b.first);
            }
        }
    } greater_poly;

    for (auto itr : ploy_map)
    {
        poly_vector.push_back(make_pair(itr.first, itr.second));
    }

    vector<string> result;
    sort(poly_vector.begin(), poly_vector.end(), greater_poly());
    for (size_t i = 0; i < poly_vector.size(); i++)
    {
        if (poly_vector[i].second == 0) continue;
        string term;
        term += to_string(poly_vector[i].second);
        for (size_t j = 0; j < poly_vector[i].first.size(); j++)
        {
            term += "*" + poly_vector[i].first[j];
        }
        result.push_back(term);
    }
    return result;
}

/// <summary>
/// Leet code #770. Basic Calculator IV   
/// </summary>
void LeetCodeString::calculatePolyExpression(
    stack<map<vector<string>, int>>& operands,
    stack<string>& operators)
{
    string op = operators.top();
    operators.pop();
    map<vector<string>, int> poly2 = operands.top();
    operands.pop();
    map<vector<string>, int> poly1 = operands.top();
    operands.pop();

    map<vector<string>, int> result;

    if (op == "+")
    {
        result = poly1;
        for (auto itr : poly2)
        {
            result[itr.first] += itr.second;
        }
    }
    else if (op == "-")
    {
        result = poly1;
        for (auto itr : poly2)
        {
            result[itr.first] -= itr.second;
        }
    }
    else if (op == "*")
    {
        for (auto itr1 : poly1)
        {
            for (auto itr2 : poly2)
            {
                vector<string> term = itr1.first;
                term.insert(term.end(), itr2.first.begin(), itr2.first.end());
                sort(term.begin(), term.end());
                result[term] += itr1.second * itr2.second;
            }
        }
    }
    operands.push(result);
}

/// <summary>
/// Leet code #770. Basic Calculator IV   
/// </summary>
map<vector<string>, int> LeetCodeString::parsePolyExpression(string& s, int& index,
    unordered_map<string, int>& eval_map)
{
    stack<map<vector<string>, int>> operands;
    stack<string> operators;
    string token;
    while (true)
    {
        token = parseExpressionToken(s, index);
        if ((token == ")") || (token.empty()))
        {
            break;
        }
        else if (token == "(")
        {
            map<vector<string>, int> operand = parsePolyExpression(s, index, eval_map);
            operands.push(operand);
        }
        else if (isalnum(token[0]))
        {
            map<vector<string>, int> operand;
            vector<string> var;
            if (eval_map.count(token) > 0)
            {
                operand[var] = eval_map[token];
            }
            else if (isdigit(token[0]))
            {
                operand[var] = atoi(token.c_str());
            }
            else
            {
                var.push_back(token);
                operand[var] = 1;
            }
            operands.push(operand);
        }
        else
        {
            if ((token == "+") || (token == "-"))
            {
                while (!operators.empty())
                {
                    calculatePolyExpression(operands, operators);
                }
            }
            else if ((token == "*") || (token == "/"))
            {
                while ((!operators.empty()) && (operators.top() == "*" || operators.top() == "/"))
                {
                    calculatePolyExpression(operands, operators);
                }
            }
            operators.push(token);
        }
    }
    while (!operators.empty())
    {
        calculatePolyExpression(operands, operators);
    }
    return operands.top();
}

/// <summary>
/// Leet code #770. Basic Calculator IV    
///
/// Given an expression such as expression = "e + 8 - a + 5" and an 
/// evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] 
/// and evalints = [1]), return a list of tokens representing the 
/// simplified expression, such as ["-1*a","14"]
///
/// An expression alternates chunks and symbols, with a space separating 
/// each chunk and symbol.
/// A chunk is either an expression in parentheses, a variable, or a 
/// non-negative integer.
/// A variable is a string of lowercase letters (not including digits.) 
/// Note that variables can be multiple letters, and note that variables 
/// never have a leading coefficient or unary operator like "2x" or "-x".
/// 
/// Expressions are evaluated in the usual order: brackets first, then 
/// multiplication, then addition and subtraction. For example, 
/// expression = "1 + 2 * 3" has an answer of ["7"].
///
/// The format of the output is as follows:
///
/// For each term of free variables with non-zero coefficient, we write 
/// the free variables within a term in sorted order lexicographically. 
/// For example, we would never write a term like "b*a*c", only "a*b*c".
/// Terms have degree equal to the number of free variables being 
/// multiplied, counting multiplicity. (For example, "a*a*b*c" has degree 
/// 4.) We write the largest degree terms of our answer first, breaking 
/// ties by lexicographic order ignoring the leading coefficient of the 
/// term.
/// The leading coefficient of the term is placed directly to the left 
/// with an asterisk separating it from the variables (if they exist.)  
/// A leading coefficient of 1 is still printed.
/// An example of a well formatted answer is ["-2*a*a*a", "3*a*a*b", 
/// "3*b*b", "4*a", "5*c", "-6"] 
/// Terms (including constant terms) with coefficient 0 are not included.  
/// For example, an expression of "0" has an output of [].
///
/// Examples:
///
/// Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
/// Output: ["-1*a","14"]
///
/// Input: expression = "e - 8 + temperature - pressure",
/// evalvars = ["e", "temperature"], evalints = [1, 12]
/// Output: ["-1*pressure","5"]
///
/// Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
/// Output: ["1*e*e","-64"]
///
/// Input: expression = "7 - 7", evalvars = [], evalints = []
/// Output: []
///
/// Input: expression = "a * b * c + b * a * c * 4", evalvars = [], 
/// evalints = []
/// Output: ["5*a*b*c"]
///
/// Input: expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + 
///                       (b - c) * (c - a))",
/// evalvars = [], evalints = []
/// Output: 
/// ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c",
///  "-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c","2*b*b*c*c","-1*b*c*c*c",
///  "2*a*a*b", "-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c",
///  "1*b*c*c","-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
/// Note:
/// 1. expression will have length in range [1, 250].
/// 2. evalvars, evalints will have equal lengths in range [0, 100].
/// </summary>
vector<string> LeetCodeString::basicCalculatorIV(string expression, vector<string>& evalvars,
    vector<int>& evalints)
{
    map<vector<string>, int> poly;
    vector<string> result;
    unordered_map<string, int> eval_map;
    for (size_t i = 0; i < evalvars.size(); i++)
    {
        eval_map[evalvars[i]] = evalints[i];
    }
    int index = 0;
    poly = parsePolyExpression(expression, index, eval_map);
    result = polyToString(poly);
    return result;
}

/// <summary>
/// Leet code #771. Jewels and Stones    
///
/// You're given strings J representing the types of stones that are 
/// jewels, and S representing the stones you have.  Each character 
/// in S is a type of stone you have.  You want to know how many of 
/// the stones you have are also jewels.
///
/// The letters in J are guaranteed distinct, and all characters in J 
/// and S are letters. Letters are case sensitive, so "a" is considered 
/// a different type of stone from "A".
///
/// Example 1:
///
/// Input: J = "aA", S = "aAAbbbb"
/// Output: 3
/// Example 2:
///
/// Input: J = "z", S = "ZZ"
/// Output: 0
/// Note:
///
/// 1. S and J will consist of letters and have length at most 50.
/// 2. The characters in J are distinct.
/// </summary>
int LeetCodeString::numJewelsInStones(string J, string S)
{
    int result = 0;
    unordered_set<char> jewels;
    for (char ch : J) jewels.insert(ch);

    for (char ch : S)
    {
        if (jewels.count(ch) > 0)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #763. Partition Labels    
///
/// A string S of lowercase letters is given. We want to partition this 
/// string into as many parts as possible so that each letter appears in 
/// at most one part, and return a list of integers representing the size 
/// of these parts.
/// 
/// Example 1:
/// Input: S = "ababcbacadefegdehijhklij"
/// Output: [9,7,8]
/// Explanation:
/// The partition is "ababcbaca", "defegde", "hijhklij".
/// This is a partition so that each letter appears in at most one part.
/// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because 
/// it splits S into less parts.
/// Note:
///
/// 1. S will have length in range [1, 500].
/// 2. S will consist of lowercase letters ('a' to 'z') only.
/// </summary>
vector<int> LeetCodeString::partitionLabels(string S)
{
    vector<int> result;
    unordered_map<char, int> char_pos;
    vector<int> positions;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (char_pos.count(S[i]) == 0)
        {
            char_pos[S[i]] = i;
            positions.push_back(i);
        }
        else
        {
            while ((!positions.empty()) && (positions.back() > char_pos[S[i]]))
            {
                char_pos[S[positions.back()]] = char_pos[S[i]];
                positions.pop_back();
            }
        }
    }

    for (size_t i = 1; i < positions.size(); i++)
    {
        result.push_back(positions[i] - positions[i - 1]);
    }
    if (!positions.empty()) result.push_back(S.size() - positions.back());
    return result;
}

/// <summary>
/// Leetcode #767. Reorganize String
///
/// Given a string S, check if the letters can be rearranged so that two 
/// characters that are adjacent to each other are not the same.
///
/// If possible, output any possible result.  If not possible, return the 
/// empty string.
///
/// Example 1:
/// Input: S = "aab"
/// Output: "aba"
///
/// Example 2:
/// Input: S = "aaab"
/// Output: ""
///
/// Note:
/// S will consist of lowercase letters and have length in range [1, 500].
/// </summary>
string LeetCodeString::reorganizeString(string S)
{
    string result;
    vector<vector<int>> char_map(26, vector<int>(2));
    for (size_t i = 0; i < S.size(); i++)
    {
        char_map[S[i] - 'a'][0]++;
    }

    for (size_t i = 0; i < S.size(); i++)
    {
        int index = 0;
        int count = 0;
        for (size_t j = 0; j < 26; j++)
        {
            if ((char_map[j][1] <= (int)result.size()) && (char_map[j][0] > count))
            {
                index = j;
                count = char_map[j][0];
            }
        }
        if (count == 0)
        {
            result = "";
            break;
        }
        else
        {
            char_map[index][0]--;
            char_map[index][1] = result.size() + 2;
            result.push_back('a' + index);
        }
    }
    return result;
}

/// <summary>
/// Leetcode #777. Swap Adjacent in LR String
///
/// In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", 
/// a move consists of either replacing one occurrence of "XL" with "LX", 
/// or replacing one occurrence of "RX" with "XR". Given the starting 
/// string start and the ending string end, return True if and only if 
/// there exists a sequence of moves to transform one string to the other.
/// 
/// Example:
/// Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
/// Output: True
/// Explanation:
/// We can transform start to end following these steps:
/// RXXLRXRXL ->
/// XRXLRXRXL ->
/// XRLXRXRXL ->
/// XRLXXRRXL ->
/// XRLXXRRLX
/// Note:
/// 1. 1 <= len(start) = len(end) <= 10000.
/// 2. Both start and end will only consist of characters in 
/// {'L', 'R', 'X'}.
/// </summary>
bool LeetCodeString::canTransform(string start, string end)
{
    vector<pair<char, int>> start_map;
    vector<pair<char, int>> end_map;
    if (start.size() != end.size()) return false;
    for (size_t i = 0; i < start.size(); i++)
    {
        if ((start[i] == 'L') || (start[i] == 'R'))
        {
            start_map.push_back(make_pair(start[i], i));
        }
    }
    for (size_t i = 0; i < end.size(); i++)
    {
        if ((end[i] == 'L') || (end[i] == 'R'))
        {
            end_map.push_back(make_pair(end[i], i));
        }
    }
    if (start_map.size() != end_map.size()) return false;
    for (size_t i = 0; i < start_map.size(); i++)
    {
        if (start_map[i].first != end_map[i].first)
        {
            return false;
        }
        else if ((start_map[i].first == 'L') && (start_map[i].second < end_map[i].second))
        {
            return false;
        }
        else if ((start_map[i].first == 'R') && (start_map[i].second > end_map[i].second))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #791. Custom Sort String
/// 
/// S and T are strings composed of lowercase letters. In S, no letter 
/// occurs more than once.
///
/// S was sorted in some custom order previously. We want to permute the 
/// characters of T so that they match the order that S was sorted. More 
/// specifically, if x occurs before y in S, then x should occur before 
/// y in the returned string.
///
/// Return any permutation of T (as a string) that satisfies this property.
///
/// Example :
/// Input: 
/// S = "cba"
/// T = "abcd"
/// Output: "cbad"
/// Explanation: 
/// "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c",
/// "b", and "a". 
/// Since "d" does not appear in S, it can be at any position in T. "dcba",
/// "cdba", "cbda" are also valid outputs.
///
/// Note:
/// 1. S has length at most 26, and no character is repeated in S.
/// 2. T has length at most 200.
/// 3. S and T consist of lowercase letters only.
/// </summary>
string LeetCodeString::customSortString(string S, string T)
{
    string result;
    unordered_map<char, int> order_map;
    map<int, string> char_map;

    for (size_t i = 0; i < S.size(); i++)
    {
        order_map[S[i]] = i;
    }

    for (char ch : T)
    {
        if (order_map.count(ch) == 0)
        {
            char_map[26].push_back(ch);
        }
        else
        {
            char_map[order_map[ch]].push_back(ch);
        }
    }

    for (auto itr : char_map)
    {
        result.append(itr.second);
    }
    return result;
}

/// <summary>
/// Leet code #796. Rotate String
/// 
/// We are given two strings, A and B. 
/// A shift on A consists of taking string A and moving the leftmost 
/// character to the rightmost position. For example, if A = 'abcde', 
/// then it will be 'bcdea' after one shift on A. Return True if and 
/// only if A can become B after some number of shifts on A.
///
/// Example 1:
/// Input: A = 'abcde', B = 'cdeab' 
/// Output: true
///
/// Example 2:
/// Input: A = 'abcde', B = 'abced' 
/// Output: false
/// Note:
/// 1. A and B will have length at most 100.
/// </summary>
bool LeetCodeString::rotateString(string A, string B)
{
    if (A.size() != B.size()) return false;
    string str = A;
    str.append(A);
    if (str.find(B) == string::npos) return false;
    return true;
}

/// <summary>
/// Leet code #804. Unique Morse Code Words
/// 
/// International Morse Code defines a standard encoding where each 
/// letter is mapped to a series of dots and dashes, as follows: "a" 
/// maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
/// 
/// For convenience, the full table for the 26 letters of the English 
/// alphabet is given below:
///
/// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
///  ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
///  ".--","-..-","-.--","--.."]
/// Now, given a list of words, each word can be written as a concatenation
/// of the Morse code of each letter. For example, "cab" can be written as 
/// "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). 
/// We'll call such a concatenation, the transformation of a word.
///
/// Return the number of different transformations among all words we have.
///
/// Example:
/// Input: words = ["gin", "zen", "gig", "msg"]
/// Output: 2
/// Explanation: 
/// The transformation of each word is:
/// "gin" -> "--...-."
/// "zen" -> "--...-."
/// "gig" -> "--...--."
/// "msg" -> "--...--."
///
/// There are 2 different transformations, "--...-." and "--...--.".
///
/// Note:
///
/// 1. The length of words will be at most 100.
/// 2. Each words[i] will have length in range [1, 12].
/// 3. words[i] will only consist of lowercase letters.
/// </summary>
int LeetCodeString::uniqueMorseRepresentations(vector<string>& words)
{
    unordered_set<string> result;
    vector<string> code_map =
    {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
        ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
        ".--","-..-","-.--","--.."
    };

    for (size_t i = 0; i < words.size(); i++)
    {
        string str;
        for (size_t j = 0; j < words[i].size(); j++)
        {
            str += code_map[words[i][j] - 'a'];
        }
        result.insert(str);
    }
    return result.size();
}

/// <summary>
/// Leet code #806. Number of Lines To Write String
/// 
/// We are to write the letters of a given string S, from left to right 
/// into lines. Each line has maximum width 100 units, and if writing a 
/// letter would cause the width of the line to exceed 100 units, it is 
/// written on the next line. We are given an array widths, an array where 
/// widths[0] is the width of 'a', widths[1] is the width of 'b', ..., and 
/// widths[25] is the width of 'z'.
///
/// Now answer two questions: how many lines have at least one character 
/// from S, and what is the width used by the last such line? Return your 
/// answer as an integer list of length 2.
///
/// Example :
/// Input: 
/// widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
///           10,10,10,10,10,10,10]
/// S = "abcdefghijklmnopqrstuvwxyz"
/// Output: [3, 60]
/// Explanation: 
/// All letters have the same length of 10. To write all 26 letters,
/// we need two full lines and one line with 60 units.
/// Example :
/// Input: 
/// widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
/// S = "bbbcccdddaaa"
/// Output: [2, 4]
/// Explanation: 
/// All letters except 'a' have the same length of 10, and 
/// "bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
/// For the last 'a', it is written on the second line because
/// there is only 2 units left in the first line.
/// So the answer is 2 lines, plus 4 units in the second line.
///
/// Note:
///
/// 1. The length of S will be in the range [1, 1000].
/// 2. S will only contain lowercase letters.
/// 3. widths is an array of length 26.
/// 4. widths[i] will be in the range of [2, 10].
/// </summary>
vector<int> LeetCodeString::numberOfLines(vector<int>& widths, string S)
{
    vector<int> result(2);
    result[0] = 1;
    result[1] = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (result[1] + widths[S[i] - 'a'] > 100)
        {
            result[0]++;
            result[1] = widths[S[i] - 'a'];
        }
        else
        {
            result[1] += widths[S[i] - 'a'];
        }
    }
    return result;
}

/// <summary>
/// Leet code #809. Expressive Words
/// </summary>
void LeetCodeString::expressiveWords(string str, vector<pair<char, int>>& str_code)
{
    pair<char, int> char_count;
    for (size_t i = 0; i <= str.size(); i++)
    {
        if (i == str.size())
        {
            str_code.push_back(char_count);
        }
        else if (i == 0)
        {
            char_count.first = str[i];
            char_count.second = 1;
        }
        else if (str[i] == str[i - 1])
        {
            char_count.second++;
        }
        else
        {
            str_code.push_back(char_count);
            char_count.first = str[i];
            char_count.second = 1;
        }
    }
}

/// <summary>
/// Leet code #809. Expressive Words
/// 
/// Sometimes people repeat letters to represent extra feeling, such as 
/// "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of 
/// adjacent letters that are all the same character, and adjacent 
/// characters to the group are different.  A group is extended if that 
/// group is length 3 or more, so "e" and "o" would be extended in the 
/// first example, and "i" would be extended in the second example.  As 
/// another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", 
/// and "aaaa"; and "ccc" and "aaaa" are the extended groups of that 
/// string.
///
/// For some given string S, a query word is stretchy if it can be made to 
/// be equal to S by extending some groups.  Formally, we are allowed to 
/// repeatedly choose a group (as defined above) of characters c, and add 
/// some number of the same character c to it so that the length of the 
/// group is 3 or more.  Note that we cannot extend a group of size one 
/// like "h" to a group of size two like "hh" - all extensions must leave 
/// the group extended - ie., at least 3 characters long.
///
/// Given a list of query words, return the number of words that are 
/// stretchy. 
///
/// Example:
/// Input: 
/// S = "heeellooo"
/// words = ["hello", "hi", "helo"]
/// Output: 1
/// Explanation: 
/// We can extend "e" and "o" in the word "hello" to get "heeellooo".
/// We can't extend "helo" to get "heeellooo" because the group "ll" is 
/// not extended.
/// Notes:
/// 
/// 1. 0 <= len(S) <= 100.
/// 2. 0 <= len(words) <= 100.
/// 3. 0 <= len(words[i]) <= 100.
/// 4. S and all words in words consist only of lowercase letters
/// </summary>
int LeetCodeString::expressiveWords(string S, vector<string>& words)
{
    int result = 0;
    vector<pair<char, int>> source_code;
    expressiveWords(S, source_code);
    for (string word : words)
    {
        vector<pair<char, int>> target_code;
        expressiveWords(word, target_code);
        if (source_code.size() != target_code.size()) continue;
        bool match = false;
        for (size_t i = 0; i < source_code.size(); i++)
        {
            if (source_code[i].first != target_code[i].first)
            {
                match = false;
                break;
            }
            else if (source_code[i].second > target_code[i].second && source_code[i].second >= 3)
            {
                match = true;
            }
            else if (source_code[i].second != target_code[i].second)
            {
                match = false;
                break;
            }
        }
        if (match) result++;
    }
    return result;
}

/// <summary>
/// Leet code #819. Most Common Word
/// 
/// Given a paragraph and a list of banned words, return the most frequent 
/// word that is not in the list of banned words.  It is guaranteed there 
/// is at least one word that isn't banned, and that the answer is unique.
///
/// Words in the list of banned words are given in lowercase, and free of 
/// punctuation.  Words in the paragraph are not case sensitive.  
/// The answer is in lowercase.
///
/// Example:
/// Input: 
/// paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
/// banned = ["hit"]
/// Output: "ball"
/// Explanation: 
/// "hit" occurs 3 times, but it is a banned word.
/// "ball" occurs twice (and no other word does), so it is the most 
/// frequent non-banned word in the paragraph. 
/// Note that words in the paragraph are not case sensitive,
/// that punctuation is ignored (even if adjacent to words, such as 
/// "ball,"), 
/// and that "hit" isn't the answer even though it occurs more because it 
/// is banned.
///
///
/// Note:
///
/// 1. 1 <= paragraph.length <= 1000.
/// 2. 1 <= banned.length <= 100.
/// 3. 1 <= banned[i].length <= 10.
/// 4. The answer is unique, and written in lowercase (even if its 
///    occurrences in paragraph may have uppercase symbols, and even if it 
///    is a proper noun.)
/// 5. paragraph only consists of letters, spaces, or the punctuation 
///    symbols !?',;.
/// 6. Different words in paragraph are always separated by a space.
/// 7. There are no hyphens or hyphenated words.
/// 8. Words only consist of letters, never apostrophes or other 
///    punctuation symbols.
/// </summary>
string LeetCodeString::mostCommonWord(string paragraph, vector<string>& banned)
{
    unordered_map<string, int> word_map;
    unordered_set<string> banned_words;
    for (string word : banned) banned_words.insert(word);

    string word;
    for (size_t i = 0; i <= paragraph.size(); i++)
    {
        if ((i == paragraph.size()) || (!isalpha(paragraph[i])))
        {
            if (!word.empty())
            {
                if (banned_words.count(word) == 0) word_map[word]++;
                word.clear();
            }
        }
        else if (isalpha(paragraph[i]))
        {
            word.push_back(tolower(paragraph[i]));
        }
    }
    int max_count = 0;
    string result;
    for (auto itr : word_map)
    {
        if (itr.second > max_count)
        {
            max_count = itr.second;
            result = itr.first;
        }
    }
    return result;
}

/// <summary>
/// Leet code #820. Short Encoding of Words
/// 
/// Given a list of words, we may encode it by writing a reference string 
/// S and a list of indexes A.
///
/// For example, if the list of words is ["time", "me", "bell"], we can 
/// write it as S = "time#bell#" and indexes = [0, 2, 5].
///
/// Then for each index, we will recover the word by reading from the 
/// reference string from that index until we reach a "#" character.
///
/// What is the length of the shortest reference string S possible that 
/// encodes the given words?
///
/// Example:
///
/// Input: words = ["time", "me", "bell"]
/// Output: 10
/// Explanation: S = "time#bell#" and indexes = [0, 2, 5].
/// Note:
///
/// 1. 1 <= words.length <= 2000.
/// 2. 1 <= words[i].length <= 7.
/// 3. Each word has only lowercase letters.
/// </summary>
int LeetCodeString::minimumLengthEncoding(vector<string>& words)
{
    int result = 0;
    for (size_t i = 0; i < words.size(); i++)
    {
        std::reverse(words[i].begin(), words[i].end());
    }
    std::sort(words.begin(), words.end());
    for (size_t i = 1; i <= words.size(); i++)
    {
        if (i == words.size())
        {
            result += words[i - 1].size() + 1;
        }
        else
        {
            if (words[i - 1].size() > words[i].size())
            {
                result += words[i - 1].size() + 1;
            }
            else
            {
                if (words[i].substr(0, words[i - 1].size()) != words[i - 1])
                {
                    result += words[i - 1].size() + 1;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #824. Goat Latin
/// 
/// A sentence S is given, composed of words separated by spaces. Each 
/// word consists of lowercase and uppercase letters only.
/// We would like to convert the sentence to "Goat Latin" (a made-up 
/// language similar to Pig Latin.)
///
/// The rules of Goat Latin are as follows:
///
/// If a word begins with a vowel (a, e, i, o, or u), append "ma" to the 
/// end of the word.
/// For example, the word 'apple' becomes 'applema'.
///
/// If a word begins with a consonant (i.e. not a vowel), remove the first 
/// letter and append it to the end, then add "ma".
/// For example, the word "goat" becomes "oatgma".
///
/// Add one letter 'a' to the end of each word per its word index in the 
/// sentence, starting with 1.
/// For example, the first word gets "a" added to the end, the second word
/// gets "aa" added to the end and so on.
/// Return the final sentence representing the conversion from S to Goat 
/// Latin. 
/// Example 1:
///
/// Input: "I speak Goat Latin"
/// Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
/// Example 2:
///
/// Input: "The quick brown fox jumped over the lazy dog"
/// Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa 
/// overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
///
/// Notes: 
/// S contains only uppercase, lowercase and spaces. Exactly one space 
/// between each word.
/// 1 <= S.length <= 150.
/// </summary>
string LeetCodeString::toGoatLatin(string S)
{
    unordered_set<char> vowel = { 'a', 'e', 'i', 'o', 'u' };

    string word;
    string result;
    int index = 0;
    for (size_t i = 0; i <= S.size(); i++)
    {
        if (i < S.size() && isalpha(S[i]))
        {
            word.push_back(S[i]);
        }
        else
        {
            if (!word.empty())
            {
                // not vowel
                if (vowel.count(tolower(word[0])) == 0)
                {
                    word = word.substr(1) + word.substr(0, 1);
                }
                word.append("ma");
                index++;
                word.append(index, 'a');
                result.append(word);
                word.clear();
            }
            if (i < S.size()) result.push_back(S[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #831. Masking Personal Information
/// 
/// We are given a personal information string S, which may represent 
/// either an email address or a phone number.
///
/// We would like to mask this personal information according to the 
/// following rules:
///
///
/// 1. Email address:
///
/// We define a name to be a string of length ≥ 2 consisting of only 
/// lowercase letters a-z or uppercase letters A-Z.
///
/// An email address starts with a name, followed by the symbol '@', 
/// followed by a name, followed by the dot '.' and followed by a name. 
///
/// All email addresses are guaranteed to be valid and in the format 
/// of "name1@name2.name3".
///
/// To mask an email, all names must be converted to lowercase and all 
/// letters between the first and last letter of the first name must be 
/// replaced by 5 asterisks '*'.
///
///
/// 2. Phone number:
///
/// A phone number is a string consisting of only the digits 0-9 or the 
/// characters from the set {'+', '-', '(', ')', ' '}. You may assume a 
/// phone number contains 10 to 13 digits.
/// 
/// The last 10 digits make up the local number, while the digits before 
/// those make up the country code. Note that the country code is optional. 
/// We want to expose only the last 4 digits and mask all other digits.
/// 
/// The local number should be formatted and masked as "***-***-1111", 
/// where 1 represents the exposed digits.
/// 
/// To mask a phone number with country code like "+111 111 111 1111", we 
/// write it in the form "+***-***-***-1111".  The '+' sign and the first 
/// '-' sign before the local number should only exist if there is a 
/// country code.  For example, a 12 digit phone number mask should start 
/// with "+**-".
///
/// Note that extraneous characters like "(", ")", " ", as well as extra 
/// dashes or plus signs not part of the above formatting scheme should 
/// be removed.
///
/// Return the correct "mask" of the information provided.
/// 
/// Example 1:
/// Input: "LeetCode@LeetCode.com"
/// Output: "l*****e@leetcode.com"
/// Explanation: All names are converted to lowercase, and the letters between the
///         first and last letter of the first name is replaced by 5 asterisks.
///         Therefore, "leetcode" -> "l*****e".
///
/// Example 2:
///
/// Input: "AB@qq.com"
/// Output: "a*****b@qq.com"
/// Explanation: There must be 5 asterisks between the first and last letter 
///         of the first name "ab". Therefore, "ab" -> "a*****b".
///
/// Example 3:
/// Input: "1(234)567-890"
/// Output: "***-***-7890"
/// Explanation: 10 digits in the phone number, which means all digits make up the local number.
///
/// Example 4:
///
/// Input: "86-(10)12345678"
/// Output: "+**-***-***-5678"
/// Explanation: 12 digits, 2 digits for country code and 10 digits for local number. 
///
/// Notes:
///
/// 1. S.length <= 40.
/// 2. Emails have length at least 8.
/// 3. Phone numbers have length at least 10.
/// </summary>
string LeetCodeString::maskPII(string S)
{
    string result;
    string name;
    if (S.find('@') != string::npos)
    {
        for (size_t i = 0; i <= S.size(); i++)
        {
            if (i == S.size())
            {
                result.append(name);
            }
            else if (S[i] == '@')
            {
                result.push_back(name[0]);
                result.append("*****");
                result.push_back(name[name.size() - 1]);
                result.push_back('@');
                name.clear();
            }
            else
            {
                if (isalpha(S[i]) || S[i] == '.')
                {
                    name.push_back(tolower(S[i]));
                }
            }
        }
    }
    else
    {
        string buff;
        for (size_t i = 0; i < S.size(); i++)
        {
            if (isdigit(S[i])) buff.push_back(S[i]);
        }
        if (buff.size() > 10)
        {
            result += "+";
            result.append(string(buff.size() - 10, '*'));
            result.push_back('-');
        }
        result.append("***-***-");
        result.append(buff.substr(buff.size() - 4, 4));
    }
    return result;
}

/// <summary>
/// Leet code #833. Find And Replace in String
/// 
/// To some string S, we will perform some replacement operations that 
/// replace groups of letters with new ones (not necessarily the same 
/// size).
///
/// Each replacement operation has 3 parameters: a starting index i, a 
/// source word x and a target word y.  The rule is that if x starts at 
/// position i in the original string S, then we will replace that 
/// occurrence of x with y.  If not, we do nothing.
/// 
/// For example, if we have S = "abcd" and we have some replacement 
/// operation i = 2, x = "cd", y = "ffff", then because "cd" starts at 
/// position 2 in the original string S, we will replace it with "ffff".
///
/// Using another example on S = "abcd", if we have both the replacement 
/// operation i = 0, x = "ab", y = "eee", as well as another replacement 
/// operation i = 2, x = "ec", y = "ffff", this second operation does 
/// nothing because in the original string S[2] = 'c', which doesn't 
/// match x[0] = 'e'.
///
/// All these operations occur simultaneously.  It's guaranteed that there 
/// won't be any overlap in replacement: for example, S = "abc", indexes = 
/// [0, 1], sources = ["ab","bc"] is not a valid test case.
/// 
/// Example 1:
///
/// Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], 
/// targets = ["eee","ffff"]
/// Output: "eeebffff"
/// Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
/// "cd" starts at index 2 in S, so it's replaced by "ffff".
///
/// Example 2:
///
/// Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], 
/// targets = ["eee","ffff"]
/// Output: "eeecd"
/// Explanation: "ab" starts at index 0 in S, so it's replaced by "eee". 
/// "ec" doesn't starts at index 2 in the original S, so we do nothing.
/// Notes:
/// 
/// 1. 0 <= indexes.length = sources.length = targets.length <= 100
/// 2. 0 < indexes[i] < S.length <= 1000
/// 3. All characters in given inputs are lowercase letters.
/// </summary>
string LeetCodeString::findReplaceString(string S, vector<int>& indexes,
    vector<string>& sources, vector<string>& targets)
{
    string result;
    size_t index = 0;
    map<int, pair<string, string>> str_map;
    for (size_t i = 0; i < indexes.size(); i++)
    {
        str_map[indexes[i]] = make_pair(sources[i], targets[i]);
    }
    for (int i = 0; i < (int)S.size(); i++)
    {
        if (!str_map.empty() && (i == str_map.begin()->first))
        {
            string source = str_map.begin()->second.first;
            string target = str_map.begin()->second.second;

            if (S.substr(i, source.size()) == source)
            {
                result.append(target);
                i += source.size() - 1;
            }
            else
            {
                result.push_back(S[i]);
            }
            str_map.erase(str_map.begin());
        }
        else
        {
            result.push_back(S[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #842. Split Array into Fibonacci Sequence
/// 
/// Given a string S of digits, such as S = "123456579", we can split it 
/// into a Fibonacci-like sequence [123, 456, 579].
///
/// Formally, a Fibonacci-like sequence is a list F of non-negative 
/// integers such that:
///
/// 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed 
/// integer type);
/// F.length >= 3;
/// and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
/// Also, note that when splitting the string into pieces, each piece must 
/// not have extra leading zeroes, except if the piece is the number 0 
/// itself.
///
/// Return any Fibonacci-like sequence split from S, or return [] if it 
/// cannot be done.
///
/// Example 1:
/// Input: "123456579"
/// Output: [123,456,579]
///
/// Example 2:
/// Input: "11235813"
/// Output: [1,1,2,3,5,8,13]
///
/// Example 3:
/// Input: "112358130"
/// Output: []
/// Explanation: The task is impossible.
///
/// Example 4:
/// Input: "0123"
/// Output: []
/// Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not 
/// valid.
///
/// Example 5:
/// Input: "1101111"
/// Output: [110, 1, 111]
/// Explanation: The output [11, 0, 11, 11] would also be accepted.
///
/// Note:
/// 1. 1 <= S.length <= 200
/// 2. S contains only digits.
/// </summary>
vector<int> LeetCodeString::splitIntoFibonacci(string S)
{
    vector<int> result;
    for (size_t i = 1; i < S.size() - 1; i++)
    {
        if (i > 1 && S[0] == '0') break;
        for (size_t j = i + 1; j < S.size(); j++)
        {
            if (j - i > 1 && S[i] == '0') break;
            result.clear();
            long v = atol(S.substr(0, i).c_str());
            if (v > INT_MAX) continue;
            result.push_back((int)v);
            v = atol(S.substr(i, j - i).c_str());
            if (v > INT_MAX) continue;
            result.push_back((int)v);
            string temp = S.substr(j);
            bool isFibonacci = true;
            while (isFibonacci)
            {
                long sum = result[result.size() - 2] + result[result.size() - 1];
                if (sum > INT_MAX) break;
                string sum_str = to_string(sum);
                if ((sum_str.size() > temp.size()) || (sum_str != temp.substr(0, sum_str.size())))
                {
                    isFibonacci = false;
                    break;
                }
                result.push_back((int)sum);
                temp = temp.substr(sum_str.size());
                if (temp.empty()) return result;
            }
        }
    }
    result.clear();
    return result;
}

/// <summary>
/// Leet code #844. Backspace String Compare
/// 
/// Given two strings S and T, return if they are equal when both are 
/// typed  into empty text editors. # means a backspace character.
///  
/// Example 1:
/// Input: S = "ab#c", T = "ad#c"
/// Output: true
/// Explanation: Both S and T become "ac".
///
/// Example 2:
///
/// Input: S = "ab##", T = "c#d#"
/// Output: true
/// Explanation: Both S and T become "".
///
/// Example 3:
///
/// Input: S = "a##c", T = "#a#c"
/// Output: true
/// Explanation: Both S and T become "c".
/// Example 4:
///
/// Input: S = "a#c", T = "b"
/// Output: false
/// Explanation: S becomes "c" while T becomes "b".
/// 
/// Note:
/// 1. 1 <= S.length <= 200
/// 2. 1 <= T.length <= 200
/// 3. S and T only contain lowercase letters and '#' characters.
/// </summary>
bool LeetCodeString::backspaceCompare(string S, string T)
{
    string src;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == '#')
        {
            if (!src.empty()) src.pop_back();
        }
        else
        {
            src.push_back(S[i]);
        }
    }

    string dst;
    for (size_t i = 0; i < T.size(); i++)
    {
        if (T[i] == '#')
        {
            if (!dst.empty()) dst.pop_back();
        }
        else
        {
            dst.push_back(T[i]);
        }
    }
    return (src == dst);
}

/// <summary>
/// Leet code #848. Shifting Letters
/// 
/// We have a string S of lowercase letters, and an integer array shifts.
/// Call the shift of a letter, the next letter in the alphabet, (wrapping 
/// around so that 'z' becomes 'a'). 
///
/// For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
/// Now for each shifts[i] = x, we want to shift the first i+1 letters of S, 
/// x times.
///
/// Return the final string after all such shifts to S are applied.
///
/// Example 1:
///
/// Input: S = "abc", shifts = [3,5,9]
/// Output: "rpl"
/// Explanation: 
/// We start with "abc".
/// After shifting the first 1 letters of S by 3, we have "dbc".
/// After shifting the first 2 letters of S by 5, we have "igc".
/// After shifting the first 3 letters of S by 9, we have "rpl", the answer.
/// Note:
///
/// 1 <= S.length = shifts.length <= 20000
/// 0 <= shifts[i] <= 10 ^ 9
/// Seen this question in a real interview before?  
/// </summary>
string LeetCodeString::shiftingLetters(string S, vector<int>& shifts)
{
    string result = S;
    vector<int> sh = shifts;
    for (int i = shifts.size() - 2; i >= 0; i--)
    {
        sh[i] = (int) (((long)sh[i] + (long)sh[i + 1]) % 26);
    }
    for (size_t i = 0; i < S.size(); i++)
    {
        result[i] = 'a' + ((long)(result[i] - 'a') + sh[i]) % 26;
    }

    return result;
}


/// <summary>
/// Leet code #859. Buddy Strings
/// 
/// Given two strings A and B of lowercase letters, return true if and only 
/// if we can swap two letters in A so that the result equals B.
///
/// Example 1:
/// Input: A = "ab", B = "ba"
/// Output: true
///
/// Example 2:
/// Input: A = "ab", B = "ab"
/// Output: false
///
/// Example 3:
/// Input: A = "aa", B = "aa"
/// Output: true
///
/// Example 4:
/// Input: A = "aaaaaaabc", B = "aaaaaaacb"
/// Output: true
///
/// Example 5:
/// Input: A = "", B = "aa"
/// Output: false
/// 
/// Note:
/// 1. 0 <= A.length <= 20000
/// 2. 0 <= B.length <= 20000
/// 3. A and B consist only of lowercase letters.
/// </summary>
bool LeetCodeString::buddyStrings(string A, string B)
{
    vector<int> diff;
    vector<int> char_set(26);
    bool duplicate = false;
    if (A.size() != B.size()) return false;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] != B[i]) diff.push_back(i);
        char_set[A[i] - 'a']++;
        if (char_set[A[i] - 'a'] > 1) duplicate = true;
    }
    if (diff.empty()) return duplicate;
    else if (diff.size() == 2)
    {
        if (A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #893. Groups of Special-Equivalent Strings
/// 
/// You are given an array A of strings.
///
/// Two strings S and T are special-equivalent if after any number of moves, 
/// S == T.
///
/// A move consists of choosing two indices i and j with i % 2 == j % 2, and 
/// swapping S[i] with S[j].
///
/// Now, a group of special-equivalent strings from A is a non-empty subset S 
/// of A such that any string not in S is not special-equivalent with any 
/// string in S.
///
/// Return the number of groups of special-equivalent strings from A.
///
/// 
/// Example 1:
/// Input: ["a","b","c","a","c","c"]
/// Output: 3
/// Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
///
/// Example 2:
/// Input: ["aa","bb","ab","ba"]
/// Output: 4
/// Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]
///
/// Example 3:
/// Input: ["abc","acb","bac","bca","cab","cba"]
/// Output: 3
/// Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
///
/// Example 4:
/// Input: ["abcd","cdab","adcb","cbad"]
/// Output: 1
/// Explanation: 1 group ["abcd","cdab","adcb","cbad"]
///
/// Note:
/// 1. 1 <= A.length <= 1000
/// 2. 1 <= A[i].length <= 20
/// 3. All A[i] have the same length.
/// 4. All A[i] consist of only lowercase letters.
/// </summary>
int LeetCodeString::numSpecialEquivGroups(vector<string>& A)
{
    set<string> str_set;
    for (size_t i = 0; i < A.size(); i++)
    {
        string even, odd;
        for (size_t j = 0; j < A[i].size(); j++)
        {
            if (j % 2 == 0) even.push_back(A[i][j]);
            else odd.push_back(A[i][j]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        str_set.insert(even + odd);
    }
    return str_set.size();
}


/// <summary>
/// Leet code #9900. Count number of substrings with exactly k distinct 
/// characters
/// 
/// Given a string of lowercase alphabets, count all possible substrings 
/// (not necessarily distinct) that has exactly k distinct characters.
///
/// Examples:
///
/// Input: abc, k = 2
/// Output: 2
/// Possible substrings are {"ab", "bc"}
///
/// Input: aba, k = 2
/// Output: 3
/// Possible substrings are {"ab", "ba", "aba"}
///
/// Input: aa, k = 1
/// Output: 3
/// Possible substrings are {"a", "a", "aa"}
/// </summary>
int LeetCodeString::countkDist(string str, int k)
{
    unordered_map<char, size_t> num_map;
    size_t head = 0, tail = 0, next = 0;
    int result = 0;
    while (head < str.size())
    {
        if (num_map.size() < (size_t)k)
        {
            if (tail == str.size()) break;
            num_map[str[tail]]++;
            tail++;
        }
        if (num_map.size() == k)
        {
            next = max(next, tail);
            while (next < str.size() && num_map.count(str[next]) > 0) next++;
            result += next - tail + 1;

            num_map[str[head]]--;
            if (num_map[str[head]] == 0) num_map.erase(str[head]);
            head++;
            tail = max(head, tail);
        }
    }
    return result;
}

/// <summary>
/// Leet code #899. Orderly Queue 
/// 
/// A string S of lowercase letters is given.  Then, we may make any 
/// number of moves.
///
/// In each move, we choose one of the first K letters (starting from 
/// the left), remove it, and place it at the end of the string.
/// Return the lexicographically smallest string we could have after 
/// any number of moves.
///
/// Example 1:
/// Input: S = "cba", K = 1
/// Output: "acb"
/// Explanation: 
/// In the first move, we move the 1st character ("c") to the end, obtaining 
/// the string "bac".
/// In the second move, we move the 1st character ("b") to the end, obtaining 
/// the final result "acb".
///
/// Example 2:
/// Input: S = "baaca", K = 3
/// Output: "aaabc"
/// Explanation: 
/// In the first move, we move the 1st character ("b") to the end, obtaining 
/// the string "aacab".
/// In the second move, we move the 3rd character ("c") to the end, obtaining 
/// the final result "aaabc".
/// 
/// Note:
/// 1. 1 <= K <= S.length <= 1000
/// 2. S consists of lowercase letters only.
/// </summary>
string LeetCodeString::orderlyQueue(string S, int K)
{
    string result ;
    if (K == 1)
    {
        result = S;
        for (size_t i = 0; i < S.size(); i++)
        {
            string temp = S.substr(i);
            temp.append(S.substr(0, i));
            if (temp < result) result = temp;
        }
    }
    else
    {
        result = S;
        sort(result.begin(), result.end());
    }
    return result;
}

/// <summary>
/// Leet code #925. Long Pressed Name 
/// 
/// Your friend is typing his name into a keyboard.  Sometimes, when typing 
/// a character c, the key might get long pressed, and the character will be 
/// typed 1 or more times.
///
/// You examine the typed characters of the keyboard.  Return True if it is 
/// possible that it was your friends name, with some characters (possibly 
/// none) being long pressed.
/// 
/// Example 1:
/// Input: name = "alex", typed = "aaleex"
/// Output: true
/// Explanation: 'a' and 'e' in 'alex' were long pressed.
///
/// Example 2:
/// Input: name = "saeed", typed = "ssaaedd"
/// Output: false
/// Explanation: 'e' must have been pressed twice, but it wasn't in 
/// the typed output.
///
/// Example 3:
/// Input: name = "leelee", typed = "lleeelee"
/// Output: true
///
/// Example 4:
/// Input: name = "laiden", typed = "laiden"
/// Output: true
/// Explanation: It's not necessary to long press any character.
/// 
/// Note:
///
/// 1. name.length <= 1000
/// 2. typed.length <= 1000
/// 3. The characters of name and typed are lowercase letters.
/// </summary>
bool LeetCodeString::isLongPressedName(string name, string typed)
{
    vector<pair<char, int>> name_chars;
    vector<pair<char, int>> typed_chars;

    for (size_t i = 0; i < name.size(); i++)
    {
        if (i == 0) name_chars.push_back({ name[i], 1 });
        else if (name[i] == name_chars.back().first)
        {
            name_chars.back().second++;
        }
        else
        {
            name_chars.push_back({ name[i], 1 });
        }
    }
    for (size_t i = 0; i < typed.size(); i++)
    {
        if (i == 0) typed_chars.push_back({ typed[i], 1 });
        else if (typed[i] == typed_chars.back().first)
        {
            typed_chars.back().second++;
        }
        else
        {
            typed_chars.push_back({ typed[i], 1 });
        }
    }

    if (name_chars.size() != typed_chars.size()) return false;
    for (size_t i = 0; i < name_chars.size(); i++)
    {
        if ((name_chars[i].first != typed_chars[i].first) || (name_chars[i].second > typed_chars[i].second))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #929. Unique Email Addresses
/// 
/// Every email consists of a local name and a domain name, separated by the @ 
/// sign.
/// 
/// For example, in alice@leetcode.com, alice is the local name, and 
/// leetcode.com is the domain name.
///
/// Besides lowercase letters, these emails may contain '.'s or '+'s.
///
/// If you add periods ('.') between some characters in the local name part of 
/// an email address, mail sent there will be forwarded to the same address 
/// without dots in the local name.  For example, "alice.z@leetcode.com" and 
/// "alicez@leetcode.com" forward to the same email address.  (Note that this 
/// rule does not apply for domain names.)
///
/// If you add a plus ('+') in the local name, everything after the first plus 
/// sign will be ignored. This allows certain emails to be filtered, for 
/// example m.y+name@email.com will be forwarded to my@email.com.  (Again, 
/// this rule does not apply for domain names.)
///
/// It is possible to use both of these rules at the same time.
///
/// Given a list of emails, we send one email to each address in the list.  
/// How many different addresses actually receive mails? 
///
/// 
/// Example 1:
/// Input: ["test.email+alex@leetcode.com",
/// "test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
/// Output: 2
/// Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" 
/// actually receive mails
/// Note:
/// 1. 1 <= emails[i].length <= 100
/// 2. 1 <= emails.length <= 100
/// 3. Each emails[i] contains exactly one '@' character.
/// </summary>
int LeetCodeString::numUniqueEmails(vector<string>& emails)
{
    unordered_set<string> emails_set;
    for (size_t i = 0; i < emails.size(); i++)
    {
        string local_name = emails[i].substr(0, emails[i].find("@"));
        string domain_name = emails[i].substr(emails[i].find("@"));
        string email;
        for (size_t j = 0; j < local_name.size(); j++)
        {
            if (local_name[j] == '+') break;
            else if (local_name[j] == '.') continue;
            email.push_back(local_name[j]);
        }
        email.append(domain_name);
        emails_set.insert(email);
    }
    return emails_set.size();
}

/// <summary>
/// Leet code #9904. CSV Parser
/// </summary>
string LeetCodeString::parsePhrase(string& line, int &pos)
{
    string result;
    bool in_quote = false;

    while (pos < (int)line.size())
    {
        // ignore leading space
        if (isspace(line[pos]))
        {
            // but do not ignore the space bwteen words or in quote
            if (!result.empty() || in_quote) result.push_back(line[pos]);
        }
        else if (line[pos] == '"')
        {
            // double quote, it is a quote in phrase
            if ((pos < (int)line.size() - 1) && (line[pos + 1] == '"'))
            {
                result.push_back('"');
                pos++;
            }
            else
            {
                // quote to enclose the phrase
                in_quote = !in_quote;
            }
        }
        else if (line[pos] == ',')
        {
            if (in_quote) result.push_back(',');
            else break;
        }
        else
        {
            result.push_back(line[pos]);
        }
        pos++;
    }

    // trim right
    int index = result.size() - 1;
    while (index >= 0 && isspace(result[index])) index--;
    result = result.substr(0, index + 1);
    return result;
}

/// <summary>
/// Leet code #9904. CSV Parser
/// </summary>
vector<string> LeetCodeString::parseLine(string& line)
{
    int pos = 0;
    vector<string> result;
    while (pos < (int)line.size())
    {
        if (line[pos] == ',')
        {
            pos++;
        }
        result.push_back(parsePhrase(line, pos));
    }
    return result;
}

/// <summary>
/// Leet code #9904. CSV Parser
/// 
/// The CSV file contains lines of phrase delimited by , when there is 
/// a , in the phrase, we use double quote to qoute it, for example
/// "San Francisco, CA", if there is a double quote in the phrase, 
/// we use another double quote in front of it to escape it. 
/// 
/// For example, assuming we have following lines
/// John,Smith,john.smith@gmail.com,Los Angeles,1
/// Jane, Roberts, janer@msn.com, "San Francisco, CA", 0
///	"Alexandra ""Alex""", Menendez, alex.menendez@gmail.com, Miami, 1
///	"""Alexandra Alex"""
///
/// After we parse it, it become the followng vector of strings.
///	John | Smith | john.smith@gmail.com | Los Angeles | 1
///	Jane | Roberts | janer@msn.com | San Francisco, CA | 0
///	Alexandra "Alex" | Menendez | alex.menendez@gmail.com | Miami | 1
///	"Alexandra Alex"
/// </summary>
vector<vector<string>> LeetCodeString::parseCSV(vector<string>& lines)
{
    vector<vector<string>> result;
    for (size_t i = 0; i < lines.size(); i++)
    {
        result.push_back(parseLine(lines[i]));
    }
    return result;
}

/// <summary>
/// Leet code #937. Reorder Log Files
/// 
/// You have an array of logs.  Each log is a space delimited string of words.
///
/// For each log, the first word in each log is an alphanumeric identifier.  
/// Then, either:
///
/// Each word after the identifier will consist only of lowercase letters, or;
/// Each word after the identifier will consist only of digits.
/// We will call these two varieties of logs letter-logs and digit-logs.  
/// It is guaranteed that each log has at least one word after its identifier.
///
/// Reorder the logs so that all of the letter-logs come before any digit-log.  
/// The letter-logs are ordered lexicographically ignoring identifier, with 
/// the identifier used in case of ties.  The digit-logs should be put in 
/// their original order.
///
/// Return the final order of the logs.
/// 
///  1. Example 1:
///
/// Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
/// Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 
/// 4 7"]
/// 
///
/// Note:
///
/// 1. 0 <= logs.length <= 100
/// 2. 3 <= logs[i].length <= 100
/// 3. logs[i] is guaranteed to have an identifier, and a word after the 
/// identifier.
/// </summary>
vector<string> LeetCodeString::reorderLogFiles(vector<string>& logs)
{
    vector<string> result;
    vector<pair<string, string>> letter_logs, digit_logs;

    for (size_t i = 0; i < logs.size(); i++)
    {
        size_t pos = logs[i].find(" ");
        string id = logs[i].substr(0, pos);
        string log = logs[i].substr(pos + 1);
        if (isdigit(log[0])) digit_logs.push_back(make_pair(log, id));
        else letter_logs.push_back(make_pair(log, id));
    }

    sort(letter_logs.begin(), letter_logs.end());

    for (auto itr : letter_logs)
    {
        result.push_back(itr.second + " " + itr.first);
    }
    for (auto itr : digit_logs)
    {
        result.push_back(itr.second + " " + itr.first);
    }

    return result;
}

/// <summary>
/// Leet code #966. Vowel Spellchecker
/// 
/// Given a wordlist, we want to implement a spellchecker that converts 
/// a query word into a correct word.
///
/// For a given query word, the spell checker handles two categories of 
/// spelling mistakes:
///
/// Capitalization: If the query matches a word in the wordlist 
/// (case-insensitive), then the query word is returned with the same case 
/// as the case in the wordlist.
/// Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
/// Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
/// Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
/// Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of 
/// the query word with any vowel individually, it matches a word in the 
/// wordlist (case-insensitive), then the query word is returned with the 
/// same case as the match in the wordlist.
/// Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
/// Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
/// Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
/// In addition, the spell checker operates under the following precedence 
/// rules:
///
/// When the query exactly matches a word in the wordlist (case-sensitive), 
/// you should return the same word back.
/// When the query matches a word up to capitlization, you should return 
/// the first such match in the wordlist.
/// When the query matches a word up to vowel errors, you should return the 
/// first such match in the wordlist.
/// If the query has no matches in the wordlist, you should return the empty 
/// string.
/// Given some queries, return a list of words answer, where answer[i] is the 
/// correct word for query = queries[i].
///
/// Example 1:
/// Input: wordlist = ["KiTe","kite","hare","Hare"], 
/// queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear",
/// "keti","keet","keto"]
/// Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
/// 
/// Note:
/// 
/// 1. 1 <= wordlist.length <= 5000
/// 2. 1 <= queries.length <= 5000
/// 3. 1 <= wordlist[i].length <= 7
/// 4. 1 <= queries[i].length <= 7
/// 5. All strings in wordlist and queries consist only of english letters.
/// </summary>
vector<string> LeetCodeString::spellchecker(vector<string>& wordlist, vector<string>& queries)
{
    unordered_set<string> exact_words;
    unordered_map<string, int> upper_words;
    unordered_map<string, int> vowel_words;

    vector<string> result;

    for (size_t i = 0; i < wordlist.size(); i++)
    {
        exact_words.insert(wordlist[i]);
        // create upper case word list
        string word = wordlist[i];
        for (size_t j = 0; j < word.size(); j++)
        {
            word[j] = toupper(word[j]);
        }
        if (upper_words.count(word) == 0) upper_words[word] = i;

        // create vowel_word list
        for (size_t j = 0; j < word.size(); j++)
        {
            if (word[j] == 'A' || word[j] == 'E' || word[j] == 'I' || word[j] == 'O' || word[j] == 'U')
            {
                word[j] = 'A';
            }
        }
        if (vowel_words.count(word) == 0) vowel_words[word] = i;
    }

    for (size_t i = 0; i < queries.size(); i++)
    {
        if (exact_words.count(queries[i]) > 0)
        {
            result.push_back(queries[i]);
            continue;
        }

        // create upper case word list
        string word = queries[i];
        for (size_t j = 0; j < word.size(); j++)
        {
            word[j] = toupper(word[j]);
        }
        if (upper_words.count(word) > 0)
        {
            result.push_back(wordlist[upper_words[word]]);
            continue;
        }

        // create vowel_word list
        for (size_t j = 0; j < word.size(); j++)
        {
            if (word[j] == 'A' || word[j] == 'E' || word[j] == 'I' || word[j] == 'O' || word[j] == 'U')
            {
                word[j] = 'A';
            }
        }
        if (vowel_words.count(word) > 0)
        {
            result.push_back(wordlist[vowel_words[word]]);
            continue;
        }
        result.push_back("");
    }
    return result;
}

/// <summary>
/// Leet code #972. Equal Rational Numbers
/// </summary>
string LeetCodeString::parseRationalInteger(string S, size_t &index)
{
    string result;
    while (index < S.size())
    {
        if (S[index] == '.') break;
        result.push_back(S[index]);
        index++;
    }
    if (result.empty()) result.push_back('0');
    return result;
}

/// <summary>
/// Leet code #972. Equal Rational Numbers
/// </summary>
string LeetCodeString::parseRationalDecimal(string S, size_t &index)
{
    string non_repeating_part;
    string repeating_part;
  
    bool is_repeat = false;
    while (index < S.size())
    {
        if (S[index] == '.')
        {

        }
        else if (S[index] == '(')
        {
            is_repeat = true;
        }
        else if (S[index] == ')')
        {
            is_repeat = false;
        }
        else if (is_repeat)
        {
            repeating_part.push_back(S[index]);
        }
        else
        {
            non_repeating_part.push_back(S[index]);
        }
        index++;
    }

    // shift non-repeating part to repeating part 
    while (!non_repeating_part.empty() && !repeating_part.empty() && 
            (non_repeating_part.back() == repeating_part.back()))
    {
        repeating_part.insert(repeating_part.begin(), non_repeating_part.back());
        non_repeating_part.pop_back();
        repeating_part.pop_back();
    }

    // shrink repeating part
    for (int i = 1; i < (int)repeating_part.size(); i++)
    {
        string next_str = repeating_part.substr(i) + repeating_part.substr(0, i);
        if (repeating_part == next_str)
        {
            repeating_part = repeating_part.substr(0, i);
            break;
        }
    }
    if (repeating_part == "0") repeating_part = "";
    
    // (9) theory
    if (repeating_part == "9" && !non_repeating_part.empty())
    {
        non_repeating_part[non_repeating_part.size() - 1]++;
        repeating_part = "";
    }

    if (repeating_part.empty())
    {
        while (!non_repeating_part.empty() && non_repeating_part.back() == '0')
        {
            non_repeating_part.pop_back();
        }
    }
    
    string result = non_repeating_part;
    if (!repeating_part.empty()) result += "(" + repeating_part + ")";
    return result;
}

/// <summary>
/// Leet code #972. Equal Rational Numbers
/// 
/// Given two strings S and T, each of which represents a non-negative 
/// rational number, return True if and only if they represent the same 
/// number. The strings may use parentheses to denote the repeating part 
/// of the rational number.
///
/// In general a rational number can be represented using up to three parts: 
/// an integer part, a non-repeating part, and a repeating part. The number 
/// will be represented in one of the following three ways:
///
/// <IntegerPart> (e.g. 0, 12, 123)
/// <IntegerPart><.><NonRepeatingPart>  (e.g. 0.5, 1., 2.12, 2.0001)
/// <IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)> (e.g. 0.1(6), 
/// 0.9(9), 0.00(1212))
/// The repeating portion of a decimal expansion is conventionally denoted 
/// within a pair of round brackets.  For example:
///
/// 1 / 6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66)
///
/// Both 0.1(6) or 0.1666(6) or 0.166(66) are correct representations of 1 / 6.
///
/// Example 1:
/// Input: S = "0.(52)", T = "0.5(25)"
/// Output: true
/// Explanation:
/// Because "0.(52)" represents 0.52525252..., and "0.5(25)" represents 
/// 0.52525252525..... , the strings represent the same number.
///
/// Example 2:
/// Input: S = "0.1666(6)", T = "0.166(66)"
/// Output: true
///
/// Example 3:
///
/// Input: S = "0.9(9)", T = "1."
/// Output: true
/// Explanation: 
/// "0.9(9)" represents 0.999999999... repeated forever, which equals 1.  
/// [See this link for an explanation.]
/// "1." represents the number 1, which is formed correctly: 
/// (IntegerPart) = "1" and (NonRepeatingPart) = "".
///
/// Note:
/// 
/// 1. Each part consists only of digits.
/// 2. The <IntegerPart> will not begin with 2 or more zeros.  (
///    There is no other restriction on the digits of each part.)
/// 3. 1 <= <IntegerPart>.length <= 4
/// 4. 0 <= <NonRepeatingPart>.length <= 4
/// 5. 1 <= <RepeatingPart>.length <= 4
/// </summary>
bool LeetCodeString::isRationalEqual(string S, string T)
{
    size_t index = 0;
    string integer1 = parseRationalInteger(S, index);
    string decimal1 = parseRationalDecimal(S, index);
    if (decimal1 == "(9)")
    {
        integer1 = to_string(stoi(integer1) + 1);
        decimal1 = "";
    }
    index = 0;
    string integer2 = parseRationalInteger(T, index);
    string decimal2 = parseRationalDecimal(T, index);
    if (decimal2 == "(9)")
    {
        integer2 = to_string(stoi(integer2) + 1);
        decimal2 = "";
    }

    if (integer1 == integer2 && decimal1 == decimal2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #1002. Find Common Characters
/// 
/// Given an array A of strings made only from lowercase letters, return a 
/// list of all characters that show up in all strings within the list 
/// (including duplicates).  For example, if a character occurs 3 times in 
/// all strings but not 4 times, you need to include that character three
/// times in the final answer.
///
/// You may return the answer in any order.
///
/// 
/// Example 1:
///
/// Input: ["bella","label","roller"]
/// Output: ["e","l","l"]
///
/// Example 2:
///
/// Input: ["cool","lock","cook"]
/// Output: ["c","o"]
/// 
///
/// Note:
/// 
/// 1. 1 <= A.length <= 100
/// 2. 1 <= A[i].length <= 100
/// 3. A[i][j] is a lowercase letter
/// </summary>
vector<string> LeetCodeString::commonChars(vector<string>& A)
{
    vector<int> result_count(26, INT_MAX);

    for (size_t i = 0; i < A.size(); i++)
    {
        vector<int> char_count(26);
        for (size_t j = 0; j < A[i].size(); j++)
        {
            char_count[A[i][j] - 'a']++;
        }
        for (size_t i = 0; i < result_count.size(); i++)
        {
            result_count[i] = min(result_count[i], char_count[i]);
        }
    }
    vector<string> result;
    for (size_t i = 0; i < result_count.size(); i++)
    {
        for (int j = 0; j < result_count[i]; j++)
        {
            string str;
            str.push_back((char)('a' + i));
            result.push_back(str);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1021. Remove Outermost Parentheses
/// 
/// A valid parentheses string is either empty (""), "(" + A + ")", or A + B,
/// where A and B are valid parentheses strings, and + represents string 
/// concatenation.  For example, "", "()", "(())()", and "(()(()))" are all 
/// valid parentheses strings.
///
/// A valid parentheses string S is primitive if it is nonempty, and there 
/// does not exist a way to split it into S = A+B, with A and B nonempty valid
/// parentheses strings.
///
/// Given a valid parentheses string S, consider its primitive decomposition: 
/// S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses 
/// strings.
///
/// Return S after removing the outermost parentheses of every primitive string 
/// in the primitive decomposition of S.
///
/// Example 1:
///
/// Input: "(()())(())"
/// Output: "()()()"
/// Explanation: 
/// The input string is "(()())(())", with primitive decomposition 
/// "(()())" + "(())".
/// After removing outer parentheses of each part, this is 
/// "()()" + "()" = "()()()".
///
/// Example 2:
/// 
/// Input: "(()())(())(()(()))"
/// Output: "()()()()(())"
/// Explanation: 
/// The input string is "(()())(())(()(()))", with primitive decomposition 
/// "(()())" + "(())" + "(()(()))".
/// After removing outer parentheses of each part, this is "()()" + "()" + 
/// "()(())" = "()()()()(())".
///
/// Example 3:
///
/// Input: "()()"
/// Output: ""
/// Explanation: 
/// The input string is "()()", with primitive decomposition "()" + "()".
/// After removing outer parentheses of each part, this is "" + "" = "".
/// 
/// Note:
/// 1. S.length <= 10000
/// 2. S[i] is "(" or ")"
/// 3. S is a valid parentheses string
/// </summary>
string LeetCodeString::removeOuterParentheses(string S)
{
    string result;
    string search;
    int count = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        search.push_back(S[i]);
        count += ((S[i] == '(') ? 1 : -1);
        if (count == 0)
        {
            result.append(search.substr(1, search.size() - 2));
            search.clear();
        }
    }
    return result;
}

/// <summary>
/// Leet code #1023. Camelcase Matching
/// 
/// A query word matches a given pattern if we can insert lowercase letters 
/// to the pattern word so that it equals the query. (We may insert each 
/// character at any position, and may insert 0 characters.)
///
/// Given a list of queries, and a pattern, return an answer list of booleans, 
/// where answer[i] is true if and only if queries[i] matches the pattern.
///
/// Example 1:
///
/// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer",
/// "ForceFeedBack"], pattern = "FB"
/// Output: [true,false,true,true,false]
/// Explanation: 
/// "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
/// "FootBall" can be generated like this "F" + "oot" + "B" + "all".
/// "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
///
/// Example 2:
///
/// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer",
/// "ForceFeedBack"], pattern = "FoBa"
/// Output: [true,false,true,false,false]
/// Explanation: 
/// "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
/// "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
///
/// Example 3:
///
/// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer",
/// "ForceFeedBack"], pattern = "FoBaT"
/// Output: [false,true,false,false,false]
/// Explanation: 
/// "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + 
/// "est".
///
/// Note:
///
/// 1. 1 <= queries.length <= 100
/// 2. 1 <= queries[i].length <= 100
/// 3. 1 <= pattern.length <= 100
/// 4. All strings consists only of lower and upper case English letters.
/// </summary>
vector<bool> LeetCodeString::camelMatch(vector<string>& queries, string pattern)
{
    vector<bool> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        size_t pos = 0;
        bool match = true;
        for (size_t j = 0; j < queries[i].size(); j++)
        {
            if (isupper(queries[i][j]))
            {
                if (pos < pattern.size() && queries[i][j] == pattern[pos]) pos++;
                else
                {
                    match = false;
                    break;
                }
            }
            else
            {
                if (pos < pattern.size() && queries[i][j] == pattern[pos]) pos++;
            }
        }
        if (pos < pattern.size()) match = false;
        result[i] = match;
    }
    return result;
}

/// <summary>
/// Leet code #1044. Longest Duplicate Substring
/// 
/// Given a string S, consider all duplicated substrings: (contiguous) 
/// substrings of S that occur 2 or more times.  (The occurrences may overlap.)
///
/// Return any duplicated substring that has the longest possible length.  
/// (If S does not have a duplicated substring, the answer is "".)
/// 
/// Example 1:
///
/// Input: "banana"
/// Output: "ana"
///
/// Example 2:
/// 
/// Input: "abcd"
/// Output: ""
/// 
/// Note:
///
/// 1. 2 <= S.length <= 10^5
/// 2. S consists of lowercase English letters.
/// </summary>
string LeetCodeString::longestDupSubstring(string S)
{
    unsigned long long M = 1000000007;
    int first = 1; 
    int last = S.size();
    string result;
    while (first < last)
    {
        int middle = first + (last - first) / 2;
        unsigned long long pow = 1;
        for (int i = 0; i < middle; i++)
        {
            pow = pow * 26 % M;
        }
        bool match = false;
        unordered_map<int, vector<int>> hash;     
        unsigned long long sum = 0;
        for (int i = 0; i < (int)S.size(); i++)
        {
            if (i < middle - 1)
            {
                sum = (sum * 26 %M + S[i] - 'a') % M;
            }
            else
            {
                if (i == middle - 1)
                {
                    sum = (sum * 26 % M + S[i] - 'a') % M;
                }
                else
                {
                    sum = (sum * 26 % M + S[i] - 'a' - (((unsigned long long)S[i - middle] - 'a') * pow % M) + M) % M;
                }
                int key = (int)sum;
                if (hash.count(key) > 0)
                {
                    match = false;
                    string target = S.substr(i - middle + 1, middle);
                    for (size_t j = 0; j < hash[key].size(); j++)
                    {
                        string source = S.substr(hash[key][j], middle);
                        if (source == target)
                        {
                            match = true;
                            break;
                        }
                    }
                    if (match == true) 
                    {
                       result = target;
                       break;
                    }
                }
                hash[key].push_back(i - middle + 1);
            }
        }
        if (match) first = middle + 1;
        else last = middle;
    }
    return result;
}

/// <summary>
/// Leet code #1071. Greatest Common Divisor of Strings
/// </summary>
string LeetCodeString::getRepeatedOfStrings(string str)
{
    size_t size = str.size();
    vector<int> lps(size);
    int len = 0;
    size_t i = 1;
    while (i < str.size())
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len > 0)
        {
            len = lps[len - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }
    if ((len > 0) && (size % (size-len) == 0))
    {
        return str.substr(0, size-len);
    }
    else
    {
        return str;
    }
}

/// <summary>
/// Leet code #1071. Greatest Common Divisor of Strings
/// 
/// For strings S and T, we say "T divides S" if and only if S = T + ... + T  
/// (T concatenated with itself 1 or more times)
///
/// Return the largest string X such that X divides str1 and X divides str2.
///
/// Example 1:
///
/// Input: str1 = "ABCABC", str2 = "ABC"
/// Output: "ABC"
///
/// Example 2:
///
/// Input: str1 = "ABABAB", str2 = "ABAB"
/// Output: "AB"
///
/// Example 3:
///
/// Input: str1 = "LEET", str2 = "CODE"
/// Output: ""
/// 
/// Note:
///
/// 1. 1 <= str1.length <= 1000
/// 2. 1 <= str2.length <= 1000
/// 3. str1[i] and str2[i] are English uppercase letters.
/// </summary>
string LeetCodeString::gcdOfStrings(string str1, string str2)
{
    string re1 = getRepeatedOfStrings(str1);
    string re2 = getRepeatedOfStrings(str2);
    if (re1 != re2 || re1 == "") return "";

    size_t a = str1.size() / re1.size();
    size_t b = str2.size() / re2.size();
    while (a * b != 0)
    {
        if (a < b) swap(a, b);
        a = a % b;
    }

    string result;
    for (size_t i = 0; i < b; i++)
    {
        result.append(re1);
    }
    return result;
}

/// <summary>
/// Leet code #1055. Shortest Way to Form String
/// 
/// From any string, we can form a subsequence of that string by deleting 
/// some number of characters (possibly no deletions).
///
/// Given two strings source and target, return the minimum number of 
/// subsequences of source such that their concatenation equals target. 
/// If the task is impossible, return -1.
///
/// 
/// Example 1:
/// Input: source = "abc", target = "abcbc"
/// Output: 2
/// Explanation: The target "abcbc" can be formed by "abc" and "bc", which 
/// are subsequences of source "abc".
///
/// Example 2:
/// Input: source = "abc", target = "acdbc"
/// Output: -1
/// Explanation: The target string cannot be constructed from the 
/// subsequences of source string due to the character "d" in target string.
///
/// Example 3:
/// Input: source = "xyz", target = "xzyxz"
/// Output: 3
/// Explanation: The target string can be constructed as follows 
/// "xz" + "y" + "xz".
/// 
/// Note:
/// 1. Both the source and target strings consist of only lowercase English 
/// letters from "a"-"z".
/// 2. The lengths of source and target string are between 1 and 1000.
/// </summary>
int LeetCodeString::shortestWay(string source, string target)
{
    int result = 0;
    vector<vector<int>> char_index(26, vector<int>());
    for (size_t i = 0; i < source.size(); i++)
    {
        char_index[source[i] - 'a'].push_back(i);
    }
    int index = -1;
    for (size_t i = 0; i < target.size(); i++)
    {
        // no such character, return -1;
        if (char_index[target[i] - 'a'].empty()) return -1;
        auto itr = upper_bound(char_index[target[i] - 'a'].begin(), char_index[target[i] - 'a'].end(), index);
        if (itr == char_index[target[i] - 'a'].end())
        {
            result++;
            index = -1;
            itr = upper_bound(char_index[target[i] - 'a'].begin(), char_index[target[i] - 'a'].end(), index);
            index = *itr;
        }
        else
        {
            if (result == 0) result++;
            index = *itr;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1065. Index Pairs of a String
/// 
/// Given a text string and words (a list of strings), return all index 
/// pairs [i, j] so that the substring text[i]...text[j] is in the list 
/// of words.
///
/// Example 1:
///
/// Input: text = "thestoryofleetcodeandme", 
/// words = ["story","fleet","leetcode"]
/// Output: [[3,7],[9,13],[10,17]]
///
/// Example 2:
///
/// Input: text = "ababa", words = ["aba","ab"]
/// Output: [[0,1],[0,2],[2,3],[2,4]]
/// Explanation: 
/// Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].
///  
/// Note:
///
/// 1. All strings contains only lowercase English letters.
/// 2. It's guaranteed that all strings in words are different.
/// 3. 1 <= text.length <= 100
/// 4. 1 <= words.length <= 20
/// 5. 1 <= words[i].length <= 50
/// 6. Return the pairs [i,j] in sorted order (i.e. sort them by their first 
/// coordinate in case of ties sort them by their second coordinate).
/// </summary>
vector<vector<int>> LeetCodeString::indexPairs(string text, vector<string>& words)
{
    vector<vector<int>> result;
    unordered_map<string, int> trie;
    for (size_t i = 0; i < words.size(); i++)
    {
        for (size_t j = 0; j < words[i].size(); j++)
        {
            if (j == words[i].size() - 1)
            {
                trie[words[i].substr(0, j + 1)] = 1;
            }
            else
            {
                if (trie.count(words[i].substr(0, j + 1)) == 0)
                {
                    trie[words[i].substr(0, j + 1)] = 0;
                }
            }
        }
    }

    for (size_t i = 0; i < text.size(); i++)
    {
        for (size_t j = i; j < text.size(); j++)
        {
            string str = text.substr(i, j - i + 1);
            if (trie.count(str) == 0) break;
            if (trie[str] == 1)
            {
                vector<int> range(2);
                range[0] = i;
                range[1] = j;
                result.push_back(range);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1078. Occurrences After Bigram
/// 
/// Given words first and second, consider occurrences in some text of the 
/// form "first second third", where second comes immediately after first, 
/// and third comes immediately after second.
///
/// For each such occurrence, add "third" to the answer, and return the answer.
/// 
/// Example 1:
///
/// Input: text = "alice is a good girl she is a good student", first = "a", 
/// second = "good"
/// Output: ["girl","student"]
///
/// Example 2:
///
/// Input: text = "we will we will rock you", first = "we", second = "will"
/// Output: ["we","rock"]
///  
/// Note:
/// 1. 1 <= text.length <= 1000
/// 2. text consists of space separated words, where each word consists of 
///    lowercase English letters.
/// 3. 1 <= first.length, second.length <= 10
/// 4. first and second consist of lowercase English letters.
/// </summary>
vector<string> LeetCodeString::findOcurrences(string text, string first, string second)
{
    string str;
    vector<string> result;
    int step = 0;
    for (size_t i = 0; i <= text.size(); i++)
    {
        if (i == text.size() || isspace(text[i]))
        {
            if (!str.empty())
            {
                if (step == 2)
                {
                    result.push_back(str);
                }
                if (str == second && step == 1)
                {
                    step = 2;
                }
                else if (str == first)
                {
                    step = 1;
                }
                else
                {
                   step = 0;
                }
                str.clear();
            }
        }
        else
        {
            str.push_back(text[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1096. Brace Expansion II
/// </summary>
void LeetCodeString::braceExpansionIIProduct(string &expression, size_t& pos, unordered_set<string> &result)
{
    pos++;
    braceExpansionIIUnion(expression, pos, result);
    pos++;
}

/// <summary>
/// Leet code #1096. Brace Expansion II
/// </summary>
void LeetCodeString::braceExpansionIIUnion(string &expression, size_t& pos, unordered_set<string> &result)
{
    while (pos <= expression.size())
    {
        unordered_set<string> left;
        if (pos == expression.size())
        {
            break;
        }
        else if (expression[pos] == '}')
        {
            break;
        }
        else if (expression[pos] == '{')
        {
            unordered_set<string> right;
            braceExpansionIIProduct(expression, pos, right);
            if (result.empty()) result.insert("");
            for (auto left_str : result)
            {
                for (auto right_str : right)
                {
                    left.insert(left_str + right_str);
                }
            }
            result.clear();
            result.insert(left.begin(), left.end());
        }
        else if (isalpha(expression[pos]))
        {
            if (result.empty()) result.insert("");
            for (auto left_str : result)
            {
                left_str.push_back(expression[pos]);
                left.insert(left_str);
            }
            pos++;
            result.clear();
            result.insert(left.begin(), left.end());
        }
        else if (expression[pos] == ',')
        {
            unordered_set<string> right;
            pos++;
            braceExpansionIIUnion(expression, pos, right);
            for (auto right_str : right)
            {
                result.insert(right_str);
            }
        }
    }
}

/// <summary>
/// Leet code #1096. Brace Expansion II
/// 
/// Under a grammar given below, strings can represent a set of lowercase 
/// words.  Let's use R(expr) to denote the set of words the expression 
/// represents.
///
/// Grammar can best be understood through simple examples:
///
/// Single letters represent a singleton set containing that word.
/// R("a") = {"a"}
/// R("w") = {"w"}
/// When we take a comma delimited list of 2 or more expressions, we take 
/// the union of possibilities.
/// R("{a,b,c}") = {"a","b","c"}
/// R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains 
/// each word at most once)
/// When we concatenate two expressions, we take the set of possible 
/// concatenations between two words where the first word comes from the 
/// first expression and the second word comes from the second expression.
/// R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
/// R("{a{b,c}}{{d,e}f{g,h}}") = R("{ab,ac}{dfg,dfh,efg,efh}") = 
/// {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", 
///  "acefh"}
/// Formally, the 3 rules for our grammar:
///
/// For every lowercase letter x, we have R(x) = {x}
/// For expressions e_1, e_2, ... , e_k with k >= 2, we have 
/// R({e_1,e_2,...}) = R(e_1) ∪ R(e_2) ∪ ...
/// For expressions e_1 and e_2, we have R(e_1 + e_2) = {a + b for (a, b) 
/// in R(e_1) × R(e_2)}, where + denotes concatenation, and × denotes the 
/// cartesian product.
/// Given an expression representing a set of words under the given 
/// grammar, return the sorted list of words that the expression 
/// represents.
///
/// Example 1:
///
/// Input: "{a,b}{c{d,e}}"
/// Output: ["acd","ace","bcd","bce"]
///
/// Example 2:
///
/// Input: "{{a,z},a{b,c},{ab,z}}"
/// Output: ["a","ab","ac","z"]
/// Explanation: Each distinct word is written only once in the final 
/// answer.
/// 
/// Constraints:
/// 1. 1 <= expression.length <= 50
/// 2. expression[i] consists of '{', '}', ','or lowercase English letters.
/// 3. The given expression represents a set of words based on the grammar 
///    given in the description.
/// </summary>
vector<string> LeetCodeString::braceExpansionII(string expression)
{
    vector<string> result;
    unordered_set<string> left;
    size_t pos = 0;
    braceExpansionIIUnion(expression, pos, left);
    for (auto str : left) result.push_back(str);

    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #1106. Parsing A Boolean Expression
/// </summary>
bool LeetCodeString::parseBoolExpr(string expression, int &pos)
{
    if (expression[pos] == 't')
    {
        pos++;
        return true;
    }
    else if (expression[pos] == 'f')
    {
        pos++;
        return false;
    }
    else if (expression[pos] == '&')
    {
        return parseBoolExprAnd(expression, pos);
    }
    else if (expression[pos] == '|')
    {
        return parseBoolExprOr(expression, pos);
    }
    else // (expression[pos] == '!')
    {
        return parseBoolExprNot(expression, pos);
    }
}

/// <summary>
/// Leet code #1106. Parsing A Boolean Expression
/// </summary>
bool LeetCodeString::parseBoolExprNot(string expression, int &pos)
{
    pos++; // skip !
    pos++; // skip (
    bool result = !parseBoolExpr(expression, pos);
    pos++; // skip )
    return result;
}

/// <summary>
/// Leet code #1106. Parsing A Boolean Expression
/// </summary>
bool LeetCodeString::parseBoolExprOr(string expression, int &pos)
{
    pos++; // skip |
    pos++; // skip (
    bool result = parseBoolExpr(expression, pos);
    while (expression[pos] != ')')
    {
        if (expression[pos] == ',')
        {
            pos++;
            bool next = parseBoolExpr(expression, pos);
            result = result || next;
        }
    }
    pos++; // skip )
    return result;
}

/// <summary>
/// Leet code #1106. Parsing A Boolean Expression
/// </summary>
bool LeetCodeString::parseBoolExprAnd(string expression, int &pos)
{
    pos++; // skip |
    pos++; // skip (
    bool result = parseBoolExpr(expression, pos);
    while (expression[pos] != ')')
    {
        if (expression[pos] == ',')
        {
            pos++;
            bool next = parseBoolExpr(expression, pos);
            result = result && next;
        }
    }
    pos++; // skip )
    return result;
}

/// <summary>
/// Leet code #1106. Parsing A Boolean Expression
/// 
/// Return the result of evaluating a given boolean expression, represented 
/// as a string.
///
/// An expression can either be:
///
/// "t", evaluating to True;
/// "f", evaluating to False;
/// "!(expr)", evaluating to the logical NOT of the inner expression expr;
/// "&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner 
/// expressions expr1, expr2, ...;
/// "|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner 
/// expressions expr1, expr2, ...
///
/// Example 1:
/// Input: expression = "!(f)"
/// Output: true
///
/// Example 2:
/// Input: expression = "|(f,t)"
/// Output: true
///
/// Example 3:
/// Input: expression = "&(t,f)"
/// Output: false
///
/// Example 4:
/// Input: expression = "|(&(t,f,t),!(t))"
/// Output: false
/// 
/// Constraints:
///
/// 1. 1 <= expression.length <= 20000
/// 2. expression[i] consists of characters in {'(', ')', '&', '|', '!', 
///    't', 'f', ','}.
/// 3. expression is a valid expression representing a boolean, as given in 
///    the description.
/// </summary>
bool LeetCodeString::parseBoolExpr(string expression)
{
    int pos = 0;
    return parseBoolExpr(expression, pos);
}

/// <summary>
/// Leet code #1108. Defanging an IP Address
/// 
/// Given a valid (IPv4) IP address, return a defanged version of that IP 
/// address.
///
/// A defanged IP address replaces every period "." with "[.]".
/// 
/// Example 1:
/// 
/// Input: address = "1.1.1.1"
/// Output: "1[.]1[.]1[.]1"
///
/// Example 2:
///
/// Input: address = "255.100.50.0"
/// Output: "255[.]100[.]50[.]0"
///
/// Constraints:
/// The given address is a valid IPv4 address.
/// </summary>
string LeetCodeString::defangIPaddr(string address)
{
    string result;
    for (size_t i = 0; i < address.size(); i++)
    {
        if (address[i] == '.')
        {
            result.append("[.]");
        }
        else
        {
            result.push_back(address[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1111. Maximum Nesting Depth of Two Valid Parentheses Strings
/// 
/// A string is a valid parentheses string (denoted VPS) if and only if it 
/// consists of "(" and ")" characters only, and:
///
/// It is the empty string, or
/// It can be written as AB (A concatenated with B), where A and B are VPS's, 
/// or
/// It can be written as (A), where A is a VPS.
/// We can similarly define the nesting depth depth(S) of any VPS S as follows:
///
/// depth("") = 0
/// depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
/// depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
/// For example,  "", "()()", and "()(()())" are VPS's (with nesting depths 0,
/// 1, and 2), and ")(" and "(()" are not VPS's.
///
/// 
/// Given a VPS seq, split it into two disjoint subsequences A and B, such that
/// A and B are VPS's (and A.length + B.length = seq.length).
///
/// Now choose any such A and B such that max(depth(A), depth(B)) is the minimum 
/// possible value.
///
/// Return an answer array (of length seq.length) that encodes such a choice of
/// A and B:  answer[i] = 0 if seq[i] is part of A, else answer[i] = 1.  Note 
/// that even though multiple answers may exist, you may return any of them.
///
/// Example 1:
//
/// Input: seq = "(()())"
/// Output: [0,1,1,1,1,0]
///
/// Example 2:
///
/// Input: seq = "()(())()"
/// Output: [0,0,0,1,1,0,1,1]
///  
///
/// Constraints:
/// 
/// 1. 1 <= seq.size <= 10000
/// </summary>
vector<int> LeetCodeString::maxDepthAfterSplit(string seq)
{
    vector<int> result(seq.size());
    int flag = 1;
    for (size_t i = 0; i < seq.size(); i++)
    {
        if (seq[i] == '(')
        {
            result[i] = 1 - flag;
        }
        else
        {
            result[i] = flag;
        }
        flag = 1 - flag;
    }
    return result;
}

/// <summary>
/// Leet code #1119. Remove Vowels from a String
/// 
/// Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it,
/// and return the new string.
///
/// Example 1:
///
/// Input: "leetcodeisacommunityforcoders"
/// Output: "ltcdscmmntyfrcdrs"
///
/// Example 2:
///
/// Input: "aeiou"
/// Output: ""
///
/// Note:
///
/// 1. S consists of lowercase English letters only.
/// 2. 1 <= S.length <= 1000
/// </summary>
string LeetCodeString::removeVowels(string S)
{
    string result;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
        {
            continue;
        }
        result.push_back(S[i]);
    }
    return result;
}

/// <summary>
/// Leet code #224. Basic Calculator    
/// Implement a basic calculator to evaluate a simple expression string.
/// The expression string may contain open ( and closing parentheses ), 
/// the plus + or minus sign -, non-negative integers and empty spaces .
/// You may assume that the given expression is always valid. 
/// Some examples:
/// "1 + 1" = 2
/// " 2-1 + 2 " = 3
/// "(1+(4+5+2)-3)+(6+8)" = 23	
/// </summary>
int LeetCodeString::calculate(string s)
{
    stack <int> nums, signs;
    int result = 0;
    int num = 0;
    int sign = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            num = num * 10 + (s[i] - '0');
        }
        else 
        {
            result += sign * num;
            num = 0;
            if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else if (c == '(')
            {
                nums.push(result);
                signs.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                num = result;
                result = nums.top();
                nums.pop();
                sign = signs.top();
                signs.pop();
            }
        }
    }
    result += sign * num;
    return result;
}

/// <summary>
/// Leet code #227. Basic Calculator II 
/// </summary>   
inline int LeetCodeString::calculateII(int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a * b;
    }
    else // (op == '/')
    {
        return a / b;
    }
}

/// <summary>
/// Leet code #227. Basic Calculator II 
/// Implement a basic calculator to evaluate a simple expression string. 
/// The expression string contains only non-negative integers, +, -, *, / 
/// operators and empty spaces . The integer division should truncate toward 
/// zero.
/// You may assume that the given expression is always valid.
/// Some examples:
/// "3+2*2" = 7
/// " 3/2 " = 1
/// " 3+5 / 2 " = 5
/// Note: Do not use the eval built-in library function. 
/// </summary>   
int LeetCodeString::calculateII(string s)
{
    int num = 0;
    int product = 1;
    stack<int> nums;
    stack<char> ops;
    for (size_t i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isspace(c)) continue;
        if (isdigit(s[i]))
        {
            num = num * 10 + (c - '0');
        }
        else 
        {
            while (!ops.empty())
            {
                if ((ops.top() == '*') || (ops.top() == '/') || (c == '+') || (c == '-'))
                {
                    num = calculateII(nums.top(), num, ops.top());
                    nums.pop();
                    ops.pop();
                }
                else
                {
                    break;
                }
            }
            nums.push(num);
            num = 0;
            ops.push(c);
        }
    }
    while (!ops.empty())
    {
        num = calculateII(nums.top(), num, ops.top());
        nums.pop();
        ops.pop();
    }
    return num;
}

/// <summary>
/// Leet code #1160. Find Words That Can Be Formed by Characters
/// 
/// You are given an array of strings words and a string chars.
/// A string is good if it can be formed by characters from chars 
/// (each character can only be used once).
/// Return the sum of lengths of all good strings in words.
/// 
/// Example 1:
/// Input: words = ["cat","bt","hat","tree"], chars = "atach"
/// Output: 6
/// Explanation: 
/// The strings that can be formed are "cat" and "hat" so the answer 
/// is 3 + 3 = 6.
///
/// Example 2:
/// Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
/// Output: 10
/// Explanation: 
/// The strings that can be formed are "hello" and "world" so the answer 
/// is 5 + 5 = 10.
/// 
/// Note:
/// 1. 1 <= words.length <= 1000
/// 2. 1 <= words[i].length, chars.length <= 100
/// 3. All strings contain lowercase English letters only.
/// </summary>
int LeetCodeString::countCharacters(vector<string>& words, string chars)
{
    vector<int> char_count(26);
    for (size_t i = 0; i < chars.size(); i++)
    {
        char_count[chars[i] - 'a']++;
    }
    int result = 0;
    for (size_t i = 0; i < words.size(); i++)
    {
        vector<int> count = char_count;
        bool match = true;
        for (size_t j = 0; j < words[i].size(); j++)
        {
            int index = words[i][j] - 'a';
            if (count[index] == 0)
            {
                match = false;
                break;
            }
            count[index]--;
        }
        if (match) result += words[i].size();
    }
    return result;
}

/// <summary>
/// Leet code #1163. Last Substring in Lexicographical Order
/// 
/// Given a string s, return the last substring of s in lexicographical order.
///
/// Example 1:
/// Input: "abab"
/// Output: "bab"
/// Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", 
/// "bab"]. The lexicographically maximum substring is "bab".
///
/// Example 2:
/// Input: "leetcode"
/// Output: "tcode"
/// 
/// Note:
/// 1. 1 <= s.length <= 4 * 10^5
/// 2. s contains only lowercase English letters.
/// </summary>
string LeetCodeString::lastSubstring(string s)
{
    std::queue<pair<int, char>> search;
    vector<int> visited(s.size());

    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == 0) search.push(make_pair(i, s[i]));
        else if (s[i] == s[i - 1])
        {
            continue;
        }
        else
        {
            while (!search.empty())
            {
                pair<int, char> node = search.front();
                if (node.second < s[i])
                {
                    search.pop();
                }
                else
                {
                    if (node.second == s[i]) search.push(make_pair(i, s[i]));
                    break;
                }
            }
            if (search.empty()) search.push(make_pair(i, s[i]));
        }
    }

    int length = 0;
    while (search.size() > 1)
    {
        length++;
        size_t size = search.size();
        char ch = 'a';
        for (size_t i = 0; i < size; i++)
        {
            pair<int, char> node = search.front();
            search.pop();
            node.first++;
            if (node.first >= (int)s.size()) continue;
            // the previous substring overlap this one, we discard it
            if (visited[node.first - length] == 1) continue;
            visited[node.first] = 1;

            ch = max(ch, s[node.first]);
            if (s[node.first] == ch)
            {
                search.push(make_pair(node.first, ch));
            }
        }
        while (!search.empty())
        {
            pair<int, char> node = search.front();
            if (node.second < ch)
            {
                search.pop();
                continue;
            }
            break;
        }
    }
    pair<int, char> node = search.front();
    return s.substr(node.first - length);
}

/// <summary>
/// Leet code #1170. Compare Strings by Frequency of the Smallest Character
/// </summary>
int LeetCodeString::numSmallerByFrequency(string word)
{
    char ch;
    int result = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        if (i == 0)
        {
            ch = word[i];
            result = 1;
        }
        else if (word[i] < ch)
        {
            ch = word[i];
            result = 1;
        }
        else if (word[i] == ch)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1170. Compare Strings by Frequency of the Smallest Character
///
/// Let's define a function f(s) over a non-empty string s, which calculates 
/// the frequency of the smallest character in s. For example, if s = "dcce" 
/// then f(s) = 2 because the smallest character is "c" and its frequency 
/// is 2.
///
/// Now, given string arrays queries and words, return an integer array 
/// answer, where each answer[i] is the number of words such that 
/// f(queries[i]) < f(W), where W is a word in words.
///
/// Example 1:
/// Input: queries = ["cbd"], words = ["zaaaz"]
/// Output: [1]
/// Explanation: On the first query we have f("cbd") = 1, 
/// f("zaaaz") = 3 so f("cbd") < f("zaaaz").
///
/// Example 2:
/// Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
/// Output: [1,2]
/// Explanation: On the first query only f("bbb") < f("aaaa"). On the second 
/// query both f("aaa") and f("aaaa") are both > f("cc").
/// 
/// Constraints:
/// 1. 1 <= queries.length <= 2000
/// 2. 1 <= words.length <= 2000
/// 3. 1 <= queries[i].length, words[i].length <= 10
/// 4. queries[i][j], words[i][j] are English lowercase letters.
/// </summary>
vector<int> LeetCodeString::numSmallerByFrequency(vector<string>& queries, vector<string>& words)
{
    vector<int> word_frequency(words.size());
    vector<int> result(queries.size());
    for (size_t i = 0; i < words.size(); i++)
    {
        word_frequency[i] = numSmallerByFrequency(words[i]);
    }
    std::sort(word_frequency.begin(), word_frequency.end());

    for (size_t i = 0; i < queries.size(); i++)
    {
        int frequency = numSmallerByFrequency(queries[i]);

        result[i] = word_frequency.end() - 
                    std::upper_bound(word_frequency.begin(), word_frequency.end(), frequency);
    }
    return result;
}

/// <summary>
/// Leet code #1165. Single-Row Keyboard
///
/// There is a special keyboard with all keys in a single row.
/// Given a string keyboard of length 26 indicating the layout of the 
/// keyboard (indexed from 0 to 25), initially your finger is at index 0. 
/// To type a character, you have to move your finger to the index of the 
/// desired character. The time taken to move your finger from index i to 
/// index j is |i - j|.
///
/// You want to type a string word. Write a function to calculate how 
/// much time it takes to type it with one finger.
/// 
/// Example 1:
///
/// Input: keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
/// Output: 4
/// Explanation: The index moves from 0 to 2 to write 'c' then to 1 to 
/// write 'b' then to 0 again to write 'a'.
/// Total time = 2 + 1 + 1 = 4. 
///
/// Example 2:
/// 
/// Input: keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
/// Output: 73
///  
/// Constraints:
/// 1. keyboard.length == 26
/// 2. keyboard contains each English lowercase letter exactly once in 
///    some order.
/// 3. 1 <= word.length <= 10^4
/// 4. word[i] is an English lowercase letter.
/// </summary>
int LeetCodeString::calculateTime(string keyboard, string word)
{
    vector<int> key_pos(26);
    for (size_t i = 0; i < keyboard.size(); i++)
    {
        key_pos[keyboard[i] - 'a'] = i;
    }
    int result = 0;
    int pos = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        result += std::abs(key_pos[word[i] - 'a'] - pos);
        pos = key_pos[word[i] - 'a'];
    }
    return result;
}

/// <summary>
/// Leet code #1178. Number of Valid Words for Each Puzzle
/// 
/// With respect to a given puzzle string, a word is valid if both the 
/// following conditions are satisfied: 
/// word contains the first letter of puzzle.
/// For each letter in word, that letter is in puzzle.
/// For example, if the puzzle is "abcdefg", then valid words are "faced", 
/// "cabbage", and "baggage"; while invalid words are "beefed" (doesn't 
/// include "a") and "based" (includes "s" which isn't in the puzzle).
/// Return an array answer, where answer[i] is the number of words in the 
/// given word list words that are valid with respect to the puzzle puzzles[i]. 
/// 
/// Example :
/// Input: 
/// words = ["aaaa","asas","able","ability","actt","actor","access"], 
/// puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
/// Output: [1,1,3,2,4,0]
/// Explanation:
/// 1 valid word for "aboveyz" : "aaaa" 
/// 1 valid word for "abrodyz" : "aaaa"
/// 3 valid words for "abslute" : "aaaa", "asas", "able"
/// 2 valid words for "absoryz" : "aaaa", "asas"
/// 4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
/// There're no valid words for "gaswxyz" cause none of the words in the 
/// list contains letter 'g'.
/// 
/// Constraints:
/// 1. 1 <= words.length <= 10^5
/// 2. 4 <= words[i].length <= 50
/// 3. 1 <= puzzles.length <= 10^4
/// 4. puzzles[i].length == 7
/// 5. words[i][j], puzzles[i][j] are English lowercase letters.
/// 6. Each puzzles[i] doesn't contain repeated characters.
/// </summary>
vector<int> LeetCodeString::findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
{
    unordered_map<int, int> word_count;
    for (size_t i = 0; i < words.size(); i++)
    {
        int bit = 0;
        for (char ch : words[i])
        {
            bit |= 1 << (ch - 'a');
        }
        int count = 0;
        for (size_t j = 0; j < 26; j++)
        {
            if (bit & (1 << j))
            {
                count++;
            }
        }
        if (count > 7) continue;
        word_count[bit]++;
    }
    vector<int> result;
    for (size_t i = 0; i < puzzles.size(); i++)
    {
        int sum = 0;
        int bit = 1 << (puzzles[i][0] - 'a');
        for (size_t j = 0; j < 64; j++)
        {
            int b = bit;
            int k = 0;
            int n = j;
            while (n > 0)
            {
                if (n % 2 == 1) b |= 1 << (puzzles[i][k+1] - 'a');
                n /= 2;
                k++;
            }
            sum += word_count[b];
        }
        result.push_back(sum);
    }
    return result;
}

/// <summary>
/// Leet code #1181. Before and After Puzzle
/// 
/// Given a list of phrases, generate a list of Before and After puzzles.
/// A phrase is a string that consists of lowercase English letters and 
/// spaces only. No space appears in the start or the end of a phrase. 
/// There are no consecutive spaces in a phrase.
/// Before and After puzzles are phrases that are formed by merging two 
/// phrases where the last word of the first phrase is the same as the 
/// first word of the second phrase.
/// Return the Before and After puzzles that can be formed by every two 
/// phrases phrases[i] and phrases[j] where i != j. Note that the order 
/// of matching two phrases matters, we want to consider both orders.
/// You should return a list of distinct strings sorted lexicographically.
/// 
/// Example 1:
/// Input: phrases = ["writing code","code rocks"]
/// Output: ["writing code rocks"]
///
/// Example 2:
/// Input: phrases = ["mission statement",
///                   "a quick bite to eat",
///                   "a chip off the old block",
///                   "chocolate bar",
///                   "mission impossible",
///                   "a man on a mission",
///                   "block party",
///                   "eat my words",
///                   "bar of soap"]
/// Output: ["a chip off the old block party",
///          "a man on a mission impossible",
///          "a man on a mission statement",
///          "a quick bite to eat my words",
///          "chocolate bar of soap"]
///
/// Example 3:
/// Input: phrases = ["a","b","a"]
/// Output: ["a"]
/// 
/// Constraints:
/// 1. 1 <= phrases.length <= 100
/// 2. 1 <= phrases[i].length <= 100
/// </summary>
vector<string> LeetCodeString::beforeAndAfterPuzzles(vector<string>& phrases)
{
    unordered_map<string, unordered_map<string, int>> phrase_map;
    for (size_t i = 0; i < phrases.size(); i++)
    {
        size_t pos = phrases[i].find(' ');
        if (pos == string::npos)
        {
            pos = phrases[i].size();
        }
        string first = phrases[i].substr(0, pos);
        phrase_map[first][phrases[i]]++;
    }
    vector<string> result;
    set<string> out_set;
    for (auto first : phrase_map)
    {
        for (auto itr : first.second)
        {
            string sentence = itr.first;
            size_t pos = sentence.find_last_of(' ');
            if (pos == string::npos)
            {
                pos = -1;
            }
            string last = sentence.substr(pos + 1);

            if (phrase_map.count(last) == 0) 
            {
                continue;
            }
            for (auto after : phrase_map[last])
            {
                // only one instance of the sentence
                if ((sentence == after.first) && (after.second == 1))
                {
                    continue;
                }
                out_set.insert(sentence + after.first.substr(last.size()));
            }
        }
    }
    result = vector<string>(out_set.begin(), out_set.end());
    return result;
}

/// <summary>
/// Leet code #1189. Maximum Number of Balloons
/// 
/// Given a string text, you want to use the characters of text to form as 
/// many instances of the word "balloon" as possible.
/// You can use each character in text at most once. Return the maximum number 
/// of instances that can be formed.
/// 
/// Example 1:
///
/// Input: text = "nlaebolko"
/// Output: 1
/// Example 2:
///
/// Input: text = "loonbalxballpoon"
/// Output: 2
/// Example 3:
/// Input: text = "leetcode"
/// Output: 0
/// 
/// Constraints:
/// 1. 1 <= text.length <= 10^4
/// 2. text consists of lower case English letters only.
/// </summary>
int LeetCodeString::maxNumberOfBalloons(string text)
{
    vector<int> char_count(26);
    for (size_t i = 0; i < text.size(); i++)
    {
        char_count[text[i] - 'a']++;
    }
    int result = char_count['b' - 'a'];
    result = min(result, char_count['a' - 'a']);
    result = min(result, char_count['l' - 'a'] / 2);
    result = min(result, char_count['o' - 'a'] / 2);
    result = min(result, char_count['n' - 'a']);    
    return result;
}

/// <summary>
/// Leet code #1233. Remove Sub-Folders from the Filesystem
/// 
/// Given a list of folders, remove all sub-folders in those folders and 
/// return in any order the folders after removing.
///
/// If a folder[i] is located within another folder[j], it is called a 
/// sub-folder of it.
/// 
/// The format of a path is one or more concatenated strings of the 
/// form: / followed by one or more lowercase English letters. For 
/// example, /leetcode and /leetcode/problems are valid paths while an 
/// empty string and / are not.
/// 
/// Example 1:
///
/// Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
/// Output: ["/a","/c/d","/c/f"]
/// Explanation: Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is 
/// inside of folder "/c/d" in our filesystem.
///
/// Example 2:
///
/// Input: folder = ["/a","/a/b/c","/a/b/d"]
/// Output: ["/a"]
/// Explanation: Folders "/a/b/c" and "/a/b/d/" will be removed because 
/// they are subfolders of "/a".
///
/// Example 3:
///
/// Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
/// Output: ["/a/b/c","/a/b/ca","/a/b/d"]
///
/// Constraints:
/// 1. 1 <= folder.length <= 4 * 10^4
/// 2. 2 <= folder[i].length <= 100
/// 3. folder[i] contains only lowercase letters and '/'
/// 4. folder[i] always starts with character '/'
/// 5. Each folder name is unique.
/// </summary>
vector<string> LeetCodeString::removeSubfolders(vector<string>& folder)
{
    priority_queue<pair<int, string>> pq;
    for (size_t i = 0; i < folder.size(); i++)
    {
        pq.push(make_pair(0-(int)folder[i].size(), folder[i]));
    }
    set<string> result;
    while (!pq.empty())
    {
        pair<int, string> p = pq.top();
        pq.pop();

        int index = 0;
        bool is_subfolder = false;
        while (true)
        {
            index = p.second.find('/', index + 1);
            if (index == string::npos) break;
            string sub_folder = p.second.substr(0, index);
            if (result.count(sub_folder) > 0)
            {
                is_subfolder = true;
                break;
            }
        }
        if (is_subfolder == false) result.insert(p.second);
    }
    return vector<string>(result.begin(), result.end());
}

/// <summary>
/// Leet code #1234. Replace the Substring for Balanced String
/// 
/// You are given a string containing only 4 kinds of characters 
/// 'Q', 'W', 'E' and 'R'.
/// A string is said to be balanced if each of its characters appears 
/// n/4 times where n is the length of the string.
/// 
/// Return the minimum length of the substring that can be replaced 
/// with any other string of the same length to make the original 
/// string s balanced.
///
/// Return 0 if the string is already balanced.
/// Example 1:
/// Input: s = "QWER"
/// Output: 0
/// Explanation: s is already balanced.
///
/// Example 2:
///
/// Input: s = "QQWE"
/// Output: 1
/// Explanation: We need to replace a 'Q' to 'R', so that "RQWE" 
/// (or "QRWE") is balanced.
///
/// Example 3:
/// 
/// Input: s = "QQQW"
/// Output: 2
/// Explanation: We can replace the first "QQ" to "ER". 
///
/// Example 4:
/// Input: s = "QQQQ"
/// Output: 3
/// Explanation: We can replace the last 3 'Q' to make s = "QWER".
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s.length is a multiple of 4
/// 3. s contains only 'Q', 'W', 'E' and 'R'.
/// </summary>
int LeetCodeString::balancedString(string s)
{
    int result = s.size();
    vector<int> ch_count(26);
    unordered_map<char, int> ch_map;
    for (size_t i = 0; i < s.size(); i++)
    {
        ch_count[s[i] - 'A']++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        // we only care surplus
        if (ch_count[i] > ((int)s.size() / 4))
        {
            ch_map['A' + i] = ch_count[i] - s.size() / 4;
            count += ch_map['A' + i];
        }
        else
        {
            ch_count[i] = 0;
        }
    }
    if (ch_map.empty()) return 0;
    int first = -1;
    for (int last = 0; last < (int)s.size(); last++)
    {
        if (ch_map.count(s[last]) > 0)
        {
            ch_map[s[last]]--;
            if (ch_map[s[last]] >= 0)
            {
                count--;
            }
        }
        if (count == 0)
        {
            while (first < last)
            {
                result = min(result, last - first);
                first++;
                if (ch_map.count(s[first]) > 0)
                {
                    ch_map[s[first]]++;
                    if (ch_map[s[first]] > 0)
                    {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1247. Minimum Swaps to Make Strings Equal
///  
/// You are given two strings s1 and s2 of equal length consisting of 
/// letters "x" and "y" only. Your task is to make these two strings equal 
/// to each other. You can swap any two characters that belong to different 
/// strings, which means: swap s1[i] and s2[j].
///
/// Return the minimum number of swaps required to make s1 and s2 equal, 
/// or return -1 if it is impossible to do so.
///
/// Example 1:
/// 
/// Input: s1 = "xx", s2 = "yy"
/// Output: 1
/// Explanation: 
/// Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
///
/// Example 2: 
///
/// Input: s1 = "xy", s2 = "yx"
/// Output: 2
/// Explanation: 
/// Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
/// Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
/// Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause 
/// we can only swap chars in different strings.
///
/// Example 3:
/// 
/// Input: s1 = "xx", s2 = "xy"
/// Output: -1
///
/// Example 4:
///
/// Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
/// Output: 4
/// 
/// Constraints:
/// 1. 1 <= s1.length, s2.length <= 1000
/// 2. s1, s2 only contain 'x' or 'y'.
/// </summary>
int LeetCodeString::minimumSwap(string s1, string s2)
{
    int count_x = 0;
    int count_y = 0;
    int result = 0;
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s2[i]) continue;
        if (s1[i] == 'x') count_x++;
        else count_y++;
    }
    result += count_x / 2;
    result += count_y / 2;
    count_x %= 2;
    count_y %= 2;
    if (count_x + count_y == 1) result = -1;
    else if (count_x + count_y == 2) result += 2;
    return result;
}

/// <summary>
/// Leet code #415. Add Strings
///  
/// Given two non-negative integers num1 and num2 represented as string, 
/// return the sum of num1 and num2.
///
/// Note:
///
/// The length of both num1 and num2 is < 5100.
/// Both num1 and num2 contains only digits 0-9.
/// Both num1 and num2 does not contain any leading zero.
/// You must not use any built-in BigInteger library or convert the 
/// inputs to integer directly.
/// </summary>
string LeetCodeString::addStrings(string num1, string num2)
{
    string result;
    string tempStore;
    size_t size = max(num1.size(), num2.size());
    int carry = 0;
    for (size_t i = 0; i < size; i++)
    {
        int d1 = 0;
        if (i < num1.size())
        {
            d1 = num1[num1.size() - 1 - i] - '0';
        }
        int d2 = 0;
        if (i < num2.size())
        {
            d2 = num2[num2.size() - 1 - i] - '0';
        }
        int sum = d1 + d2 + carry;
        tempStore.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry == 1) tempStore.push_back(carry + '0');
    for (size_t i = 0; i < tempStore.size(); i++)
    {
        result.push_back(tempStore[tempStore.size() - 1 - i]);
    }
    return result;
}

/// <summary>
/// Leet code #1268. Search Suggestions System
/// 
/// Given an array of strings products and a string searchWord. We want to 
/// design a system that suggests at most three product names from 
/// products after each character of searchWord is typed. Suggested 
/// products should have common prefix with the searchWord. If there are 
/// more than three products with a common prefix return the three 
/// lexicographically minimums products.
///
/// Return list of lists of the suggested products after each character of 
/// searchWord is typed. 
///
/// Example 1:
/// 
/// Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], 
/// searchWord = "mouse"
/// Output: [
/// ["mobile","moneypot","monitor"],
/// ["mobile","moneypot","monitor"],
/// ["mouse","mousepad"],
/// ["mouse","mousepad"],
/// ["mouse","mousepad"]
/// ]
/// Explanation: products sorted lexicographically = ["mobile","moneypot",
/// "monitor","mouse","mousepad"]
/// After typing m and mo all products match and we show user 
/// ["mobile","moneypot","monitor"]
/// After typing mou, mous and mouse the system suggests 
/// ["mouse","mousepad"]
///
/// Example 2:
///
/// Input: products = ["havana"], searchWord = "havana"
/// Output: [["havana"],["havana"],["havana"],["havana"],["havana"],
/// ["havana"]]
///
/// Example 3:
///
/// Input: products = ["bags","baggage","banner","box","cloths"], 
/// searchWord = "bags"
/// Output: [["baggage","bags","banner"],["baggage","bags","banner"],
/// ["baggage","bags"],["bags"]]
///
/// Example 4:
///
/// Input: products = ["havana"], searchWord = "tatiana"
/// Output: [[],[],[],[],[],[],[]]
/// 
/// Constraints:
/// 1. 1 <= products.length <= 1000
/// 2. 1 <= SUM products[i].length <= 2 * 10^4
/// 3. All characters of products[i] are lower-case English letters.
/// 4. 1 <= searchWord.length <= 1000
/// 5. All characters of searchWord are lower-case English letters.
/// </summary>
vector<vector<string>> LeetCodeString::suggestedProducts(vector<string>& products, string searchWord)
{
    unordered_map<string, multiset<string>> product_map;

    for (size_t i = 0; i < products.size(); i++)
    {
        for (size_t j = 0; j < products[i].size(); j++)
        {
            string prefix = products[i].substr(0, j + 1);
            product_map[prefix].insert(products[i]);
        }
    }
    vector<vector<string>> result(searchWord.size());
    for (size_t i = 0; i < searchWord.size(); i++)
    {
        auto itr = product_map[searchWord.substr(0, i + 1)].begin();
        for (size_t j = 0; j < 3; j++)
        {
            if (itr == product_map[searchWord.substr(0, i + 1)].end()) break;
            result[i].push_back(*itr);
            itr++;
        }
    }
    return result;
}

/// <summary>
/// Leetcode #1297. Maximum Number of Occurrences of a Substring
/// 
/// Given a string s, return the maximum number of ocurrences of any 
/// substring under the following rules:
///
/// The number of unique characters in the substring must be less than 
/// or equal to maxLetters.
/// The substring size must be between minSize and maxSize inclusive.
///
/// Example 1:
///
/// Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
/// Output: 2
/// Explanation: Substring "aab" has 2 ocurrences in the original string.
/// It satisfies the conditions, 2 unique letters and size 3 (between 
/// minSize and maxSize).
///
/// Example 2:
/// 
/// Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
/// Output: 2
/// Explanation: Substring "aaa" occur 2 times in the string. It can 
/// overlap.
///
/// Example 3:
///
/// Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
/// Output: 3
///
/// Example 4:
///
/// Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
/// Output: 0
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. 1 <= maxLetters <= 26
/// 3. 1 <= minSize <= maxSize <= min(26, s.length)
/// 4. s only contains lowercase English letters.
/// </summary>
int LeetCodeString::maxFreq(string s, int maxLetters, int minSize, int maxSize)
{
    unordered_map<string, int> words;
    unordered_map<char, int> letters;
    int first = 0;
    int second = 0;
    while (second < (int)s.size())
    {
        letters[s[second]]++;
        while ((int)letters.size() > maxLetters || (second - first) >= maxSize)
        {
            letters[s[first]]--;
            if (letters[s[first]] == 0)
            {
                letters.erase(s[first]);
            }
            first++;
        }
        // only need to check minSize substring
        if (first <= second - minSize + 1)
        {
            string str = s.substr(second - minSize + 1, minSize);
            words[str]++;
        }
        second++;
    }
    int result = 0;
    for (auto itr : words)
    {
        result = max(result, itr.second);
    }
    return result;
}

/// <summary>
/// Leet code #1309. Decrypt String from Alphabet to Integer Mapping
/// 
/// Easy
///
/// Given a string s formed by digits ('0' - '9') and '#' . We want to 
/// map s to English lowercase characters as follows:
/// Characters ('a' to 'i') are represented by ('1' to '9') respectively.
/// Characters ('j' to 'z') are represented by ('10#' to '26#') 
/// respectively. 
/// Return the string formed after mapping.
/// It's guaranteed that a unique mapping will always exist.
///
/// Example 1:
/// Input: s = "10#11#12"
/// Output: "jkab"
/// Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
///
/// Example 2:
/// Input: s = "1326#"
/// Output: "acz"
///
/// Example 3:
/// Input: s = "25#"
/// Output: "y"
///
/// Example 4:
/// Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
/// Output: "abcdefghijklmnopqrstuvwxyz"
///  
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s[i] only contains digits letters ('0'-'9') and '#' letter.
/// 3. s will be valid string such that mapping is always possible.
/// </summary>
string LeetCodeString::freqAlphabets(string s)
{
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            string digit;
            digit.push_back(result[result.size() - 2]);
            digit.push_back(result[result.size() - 1]);
            result.pop_back();
            result.pop_back();
            result.push_back('j' + atoi(digit.c_str()) - 10);
        }
        else
        {
            result.push_back(s[i]);
        }
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] >= '1' && result[i] <= '9')
        {
            result[i] = 'a' + result[i] - '1';
        }
    }
    return result;
}

/// <summary>
/// Leet code #1316. Distinct Echo Substrings
///
/// Hard
///
/// Return the number of distinct non-empty substrings of text that can be 
/// written as the concatenation of some string with itself.
/// 
/// Example 1:
/// Input: text = "abcabcabc"
/// Output: 3
/// Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
/// Example 2:
/// Input: text = "leetcodeleetcode"
/// Output: 2
/// Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
/// 
/// Constraints:
/// 1. 1 <= text.length <= 2000
/// 2. text has only lowercase English letters.
/// </summary>
int LeetCodeString::distinctEchoSubstrings(string text)
{
    int n = text.size();
    unordered_set<string> result_set;
    for (int s = 0; s < (int)text.size(); s++)
    {
        vector<int> kmp(n);
        int i = 1;
        int j = 0;
        while (s + i < n)
        {
            if (text[s + i] == text[s + j])
            {
                j++;
                kmp[i] = j;
                i++;
                // must be even length
                if (i % 2 == 1) continue;
                // if duplicate as half half, the remaining prefix length 
                // must be divisible to total length
                if ((i / 2) % (i - j) == 0)
                {
                    result_set.insert(text.substr(s, i));
                }
            }
            else if (j == 0)
            {
                i++;
            }
            else
            {
                j = kmp[j - 1];
            }
        }
    }
    return result_set.size();
}

/// <summary>
/// Leet code #830. Positions of Large Groups
/// 
/// In a string S of lowercase letters, these letters form consecutive 
/// groups of the same character.
///
/// For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", 
/// "xxxx", "z" and "yy".
///
/// Call a group large if it has 3 or more characters.  We would like the 
/// starting and ending positions of every large group.
/// 
/// The final answer should be in lexicographic order.
///
/// Example 1:
///
/// Input: "abbxxxxzzy"
/// Output: [[3,6]]
/// Explanation: "xxxx" is the single large group with starting  3 and 
/// ending positions 6.
///
/// Example 2:
///
/// Input: "abc"
/// Output: []
/// Explanation: We have "a","b" and "c" but no large group.
///
/// Example 3:
///
/// Input: "abcdddeeeeaabbbcd"
/// Output: [[3,5],[6,9],[12,14]]
///
/// Note:  1. 1 <= S.length <= 1000
/// </summary>
vector<vector<int>> LeetCodeString::largeGroupPositions(string S)
{
    vector<vector<int>> result;
    int first = 0, last = 0;
    while (last <= (int)S.size())
    {
        if ((last == S.size()) || (S[first] != S[last]))
        {
            if (last - first >= 3)
            {
                result.push_back(vector<int>{ first, last - 1});
            }
            first = last;

        }
        last++;
    }
    return result;
}

/// <summary>
/// Leet code #1324. Print Words Vertically
///
/// Medium
///
/// Given a string s. Return all the words vertically in the same 
/// order in which they appear in s.
/// Words are returned as a list of strings, complete with spaces when 
/// is necessary. (Trailing spaces are not allowed).
/// Each word would be put on only one column and that in one column 
/// there will be only one word.
/// 
/// Example 1:
/// Input: s = "HOW ARE YOU"
/// Output: ["HAY","ORO","WEU"]
/// Explanation: Each word is printed vertically. 
///  "HAY"
///  "ORO"
///  "WEU"
///
/// Example 2:
/// Input: s = "TO BE OR NOT TO BE"
/// Output: ["TBONTB","OEROOE","   T"]
/// Explanation: Trailing spaces is not allowed. 
/// "TBONTB"
/// "OEROOE"
/// "   T"
///
/// Example 3:
/// Input: s = "CONTEST IS COMING"
/// Output: ["CIC","OSO","N M","T I","E N","S G","T"]
///
/// Constraints:
/// 1. 1 <= s.length <= 200
/// 2. s contains only upper case English letters.
/// 3. It's guaranteed that there is only one space between 2 words.
/// </summary>
vector<string> LeetCodeString::printVertically(string s)
{
    vector<string> result;
    vector<int> dp;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == 0) dp.push_back(i);
        else if (isspace(s[i - 1]) && !isspace(s[i]))
        {
            dp.push_back(i);
        }
    }
    size_t index = 0;
    while (!dp.empty())
    {
        for (size_t i = 0; i < dp.size(); i++)
        {
            if (result.size() <= index)
            {
                result.push_back("");
            }
            if (dp[i] == s.size() || isspace(s[dp[i]]))
            {
                result[index].push_back(' ');
            }
            else
            {
                result[index].push_back(s[dp[i]]);
                dp[i]++;
            }
        }
        while ((!dp.empty()) && (dp.back() == s.size() || isspace(s[dp.back()])))
        {
            dp.pop_back();
        }
        index++;
    }
    return result;
}

/// <summary>
/// Leet code #1328. Break a Palindrome
/// 
/// Medium
///
/// Given a palindromic string palindrome, replace exactly one character 
/// by any lowercase English letter so that the string becomes the 
/// lexicographically smallest possible string that isn't a palindrome.
///
/// After doing so, return the final string.  If there is no way to do 
/// so, return the empty string.
///
/// Example 1:
/// Input: palindrome = "abccba"
/// Output: "aaccba"
///
/// Example 2:
/// Input: palindrome = "a"
/// Output: ""
/// 
/// Constraints:
/// 1. 1 <= palindrome.length <= 1000
/// 2. palindrome consists of only lowercase English letters.
/// </summary>
string LeetCodeString::breakPalindrome(string palindrome)
{
    string result = "";
    if (palindrome.size() == 1) return result;
    result = palindrome;
    for (size_t i = 0; i < result.size() / 2; i++)
    {
        // change any non leading 'a' to 'a';
        if (result[i] != 'a')
        {
            result[i] = 'a';
            return result;
        }
    }
    result.pop_back();
    result.push_back('b');
    return result;
}

/// <summary>
/// Leet code #1332. Remove Palindromic Subsequences
/// 
/// Easy
///
/// Given a string s consisting only of letters 'a' and 'b'. In a single 
/// step you can remove one palindromic subsequence from s.
///
/// Return the minimum number of steps to make the given string empty.
///
/// A string is a subsequence of a given string, if it is generated by 
/// deleting some characters of a given string without changing its order.
///
/// A string is called palindrome if is one that reads the same backward 
/// as well as forward.
///
/// Example 1:
/// Input: s = "ababa"
/// Output: 1
/// Explanation: String is already palindrome
///
/// Example 2:
/// Input: s = "abb"
/// Output: 2
/// Explanation: "abb" -> "bb" -> "". 
/// Remove palindromic subsequence "a" then "bb".
/// 
/// Example 3:
/// Input: s = "baabb"
/// Output: 2
/// Explanation: "baabb" -> "b" -> "". 
/// Remove palindromic subsequence "baab" then "b".
///
/// Example 4:
/// Input: s = ""
/// Output: 0
///
/// Constraints:
/// 1. 0 <= s.length <= 1000
/// 2. s only consists of letters 'a' and 'b'
/// </summary>
int LeetCodeString::removePalindromeSub(string s)
{
    if (s.empty()) return 0;
    int first = 0;
    int last = s.size() - 1;
    bool isPalindrome = true;
    while (first < last)
    {
        if (s[first] != s[last])
        {
            isPalindrome = false;
            break;
        }
        first++;
        last--;
    }
    if (isPalindrome) return 1;
    else return 2;
}

/// <summary>
/// Leet code #1347. Minimum Number of Steps to Make Two Strings Anagram
///
/// Medium
///
/// Given two equal-size strings s and t. In one step you can choose any 
/// character of t and replace it with another character.
///
/// Return the minimum number of steps to make t an anagram of s.
///
/// An Anagram of a string is a string that contains the same characters 
/// with a different (or the same) ordering.
/// 
/// Example 1: 
/// Input: s = "bab", t = "aba"
/// Output: 1
/// Explanation: Replace the first 'a' in t with b, t = "bba" which is 
/// anagram of s.
/// 
/// Example 2:
/// Input: s = "leetcode", t = "practice"
/// Output: 5
/// Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper 
/// characters to make t anagram of s.
///
/// Example 3:
/// Input: s = "anagram", t = "mangaar"
/// Output: 0
/// Explanation: "anagram" and "mangaar" are anagrams. 
///
/// Example 4:
/// Input: s = "xxyyzz", t = "xxyyzz"
/// Output: 0
///
/// Example 5:
/// Input: s = "friend", t = "family"
/// Output: 4
///
/// Constraints:
/// 1. 1 <= s.length <= 50000
/// 2. s.length == t.length
/// 3. s and t contain lower-case English letters only.
/// </summary>
int LeetCodeString::minSteps(string s, string t)
{
    vector<int> arr_s(26), arr_t(26);

    for (size_t i = 0; i < s.size(); i++)
    {
        arr_s[s[i] - 'a']++;
        arr_t[t[i] - 'a']++;
    }
    int result = 0;
    for (size_t i = 0; i < 26; i++)
    {
        result += abs(arr_s[i] - arr_t[i]);
    }
    return result / 2;
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
vector<bool> LeetCodeString::canMakePaliQueries(string s, vector<vector<int>>& queries)
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
/// Leet code #1358. Number of Substrings Containing All Three Characters
///
/// Medium
///
/// Given a string s consisting only of characters a, b and c.
/// Return the number of substrings containing at least one occurrence of 
/// all these characters a, b and c.
/// 
/// Example 1:
/// Input: s = "abcabc"
/// Output: 10
/// Explanation: The substrings containing at least one occurrence of the 
/// characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", 
/// "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
///
/// Example 2:
/// Input: s = "aaacb"
/// Output: 3
/// Explanation: The substrings containing at least one occurrence of 
/// the characters a, b and c are "aaacb", "aacb" and "acb". 
///
/// Example 3:
/// Input: s = "abc"
/// Output: 1
///
/// Constraints:
/// 1. 3 <= s.length <= 5 x 10^4
/// 2. s only consists of a, b or c characters.
/// </summary>
int LeetCodeString::numberOfSubstrings(string s)
{
    int result = 0;
    vector<int> char_count(3);
    int first = 0;
    int last = -1;
    while (first < (int)s.size() && last < (int)s.size())
    {
        if ((last == -1) || (char_count[0] == 0) || (char_count[1] == 0) || (char_count[2] == 0))
        {
            last++;
            if (last < (int)s.size()) char_count[s[last] - 'a']++;
        }
        else
        {
            result += s.size() - last;
            char_count[s[first] - 'a']--;
            first++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1370. Increasing Decreasing String
///
/// Easy
///
/// 1. Pick the smallest character from s and append it to the result.
/// 2. Pick the smallest character from s which is greater than the last 
///    appended character to the result and append it.
/// 3. Repeat step 2 until you cannot pick more characters.
/// 4. Pick the largest character from s and append it to the result.
/// 5. Pick the largest character from s which is smaller than the last 
///    appended character to the result and append it.  
/// 6. Repeat step 5 until you cannot pick more characters.
/// 7. Repeat the steps from 1 to 6 until you pick all characters from s.
/// In each step, If the smallest or the largest character appears 
/// more than once you can choose any occurrence and append it to 
/// the result.
///
/// Return the result string after sorting s with this algorithm.
///
/// Example 1:
/// Input: s = "aaaabbbbcccc"
/// Output: "abccbaabccba"
/// Explanation: After steps 1, 2 and 3 of the first iteration, 
/// result = "abc"
/// After steps 4, 5 and 6 of the first iteration, result = "abccba"
/// First iteration is done. Now s = "aabbcc" and we go back to step 1
/// After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
/// After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
///
/// Example 2:
/// Input: s = "rat"
/// Output: "art"
/// Explanation: The word "rat" becomes "art" after re-ordering it with 
/// the mentioned algorithm.
///
/// Example 3:
/// Input: s = "leetcode"
/// Output: "cdelotee"
///
/// Example 4:
/// Input: s = "ggggggg"
/// Output: "ggggggg"
///
/// Example 5: 
/// Input: s = "spo"
/// Output: "ops"
///
/// Constraints:
/// 1. 1 <= s.length <= 500
/// 2. s contains only lower-case English letters.
/// </summary>
string LeetCodeString::sortString(string s)
{
    string result;
    vector<int> char_count(26);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char_count[s[i] - 'a']++;
    }
    while (n > 0)
    {
        for (int i = 0; i < 26; i++)
        {
            if (char_count[i] > 0)
            {
                result.push_back('a' + i);
                char_count[i]--;
                n--;
            }
        }
        for (int i = 25; i >= 0; i--)
        {
            if (char_count[i] > 0)
            {
                result.push_back('a' + i);
                char_count[i]--;
                n--;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1371. Find the Longest Substring Containing Vowels 
///                  in Even Counts
///
/// Medium
///
/// Given the string s, return the size of the longest substring 
/// containing each vowel an even number of times. That is, 'a', 
/// 'e', 'i', 'o', and 'u' must appear an even number of times.
///
/// Example 1:
/// Input: s = "eleetminicoworoep"
/// Output: 13
/// Explanation: The longest substring is "leetminicowor" which 
/// contains two each of the vowels: e, i and o and zero of the 
/// vowels: a and u.  
/// Example 2:
/// Input: s = "leetcodeisgreat"
/// Output: 5
/// Explanation: The longest substring is "leetc" which contains two e's.
///
/// Example 3:
/// Input: s = "bcbcbc"
/// Output: 6
/// Explanation: In this case, the given string "bcbcbc" is the longest 
/// because all vowels: a, e, i, o and u appear zero times.
///
/// Constraints:
/// 1. 1 <= s.length <= 5 x 10^5
/// 2. s contains only lowercase English letters.
/// </summary>
int LeetCodeString::findTheLongestSubstring(string s)
{
    unordered_map<int, int> bit_map;
    bit_map[0] = -1;
    int result = 0;
    int n = s.size();
    int bit = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a') bit ^= 1;
        else if (s[i] == 'e') bit ^= 2;
        else if (s[i] == 'i') bit ^= 4;
        else if (s[i] == 'o') bit ^= 8;
        else if (s[i] == 'u') bit ^= 16;

        if (bit_map.count(bit) == 0) bit_map[bit] = i;
        else result = max(result, i - bit_map[bit]);
    }
    return result;
}

/// <summary>
/// Leet code #1374. Generate a String With Characters That Have Odd 
///           Counts 
/// Easy
///
/// Given an integer n, return a string with n characters such that 
/// each character in such string occurs an odd number of times.
///
/// The returned string must contain only lowercase English letters. 
/// If there are multiples valid strings, return any of them.  
///
/// Example 1:
/// Input: n = 4
/// Output: "pppz"
/// Explanation: "pppz" is a valid string since the character 'p' 
/// occurs three times and the character 'z' occurs once. Note that 
/// there are many other valid strings such as "ohhh" and "love".
/// 
/// Example 2:
/// Input: n = 2
/// Output: "xy"
/// Explanation: "xy" is a valid string since the characters 'x' and 'y' 
/// occur once. Note that there are many other valid strings such as 
/// "ag" and "ur".
///
/// Example 3:
/// Input: n = 7
/// Output: "holasss"
///
/// Constraints:
/// 1. 1 <= n <= 500
/// </summary>
string LeetCodeString::generateTheString(int n)
{
    string result;
    if (n % 2 == 0)
    {
        result.insert(result.end(), n - 1, 'a');
        result.push_back('b');
    }
    else if (n % 2 == 1)
    {
        result.insert(result.end(), n, 'a');
    }
    return result;
}

/// <summary>
/// Leet code #1392. Longest Happy Prefix
/// 
/// Hard
///
/// A string is called a happy prefix if is a non-empty prefix which is 
/// also a suffix (excluding itself).
///
/// Given a string s. Return the longest happy prefix of s .
///
/// Return an empty string if no such prefix exists.
/// 
/// Example 1:
///
/// Input: s = "level"
/// Output: "l"
/// Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), 
/// and suffix ("l", "el", "vel", "evel"). The largest prefix which is also 
/// suffix is given by "l".
///
/// Example 2:
/// Input: s = "ababab"
/// Output: "abab"
/// Explanation: "abab" is the largest prefix which is also suffix. They can 
/// overlap in the original string.
///
/// Example 3:
/// Input: s = "leetcodeleet"
/// Output: "leet"
///
/// Example 4:
/// Input: s = "a"
/// Output: ""
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s contains only lowercase English letters.
/// </summary>
string LeetCodeString::longestPrefix(string s)
{
    vector<int> kmp_table(s.size());
    int i = 1;
    int j = 0;
    while (i < (int)s.size())
    {
        if (s[i] == s[j])
        {
            j++;
            kmp_table[i] = j;
            i++;
        }
        else if (j == 0)
        {
            kmp_table[i] = 0;
            i++;
        }
        else
        {
            j = kmp_table[j - 1];
        }
    }
    return s.substr(0, kmp_table[s.size() - 1]);
}

/// <summary>
/// Leet code #1400. Construct K Palindrome Strings
/// 
/// Medium
///
/// Given a string s and an integer k. You should construct k non-empty 
/// palindrome strings using all the characters in s.
///
/// Return True if you can use all the characters in s to construct k 
/// palindrome strings or False otherwise.
/// 
/// Example 1:
/// Input: s = "annabelle", k = 2
/// Output: true
/// Explanation: You can construct two palindromes using all characters 
/// in s.
/// Some possible constructions "anna" + "elble", "anbna" + "elle", 
/// "anellena" + "b"
///
/// Example 2:
/// Input: s = "leetcode", k = 3
/// Output: false
/// Explanation: It is impossible to construct 3 palindromes using all 
/// the characters of s.
///
/// Example 3:
/// Input: s = "true", k = 4
/// Output: true
/// Explanation: The only possible solution is to put each character 
/// in a separate string.
///
/// Example 4:
/// Input: s = "yzyzyzyzyzyzyzy", k = 2
/// Output: true
/// Explanation: Simply you can put all z's in one string and all y's 
/// in the other string. Both strings will be palindrome.
///
/// Example 5:
/// Input: s = "cr", k = 7
/// Output: false
/// Explanation: We don't have enough characters in s to construct 7 
/// palindromes.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. All characters in s are lower-case English letters.
/// 3. 1 <= k <= 10^5
/// </summary>
bool LeetCodeString::canConstruct(string s, int k)
{
    vector<int> char_count(26);

    for (size_t i = 0; i < s.size(); i++)
    {
        char_count[s[i] - 'a']++;
    }

    int min_count = 0;
    int max_count = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if (char_count[i] % 2 == 1)
        {
            min_count++;
            max_count += char_count[i];
        }
        else
        {
            max_count += char_count[i];
        }
    }
    if (min_count <= k && max_count >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #1404. Number of Steps to Reduce a Number in Binary 
/// Representation to One
/// 
/// Medium
///
/// Given a number s in their binary representation. Return the number 
/// of steps to reduce it to 1 under the following rules:
///
/// If the current number is even, you have to divide it by 2.
///
/// If the current number is odd, you have to add 1 to it.
///
/// It's guaranteed that you can always reach to one for all testcases.
///
/// Example 1:
/// Input: s = "1101"
/// Output: 6
/// Explanation: "1101" corressponds to number 13 in their decimal 
/// representation.
/// Step 1) 13 is odd, add 1 and obtain 14. 
/// Step 2) 14 is even, divide by 2 and obtain 7.
/// Step 3) 7 is odd, add 1 and obtain 8.
/// Step 4) 8 is even, divide by 2 and obtain 4.  
/// Step 5) 4 is even, divide by 2 and obtain 2. 
/// Step 6) 2 is even, divide by 2 and obtain 1.  
///
/// Example 2:
/// Input: s = "10"
/// Output: 1
/// Explanation: "10" corressponds to number 2 in their decimal 
/// representation.
/// Step 1) 2 is even, divide by 2 and obtain 1.  
/// Example 3:
///
/// Input: s = "1"
/// Output: 0
///
/// Constraints:
/// 1. 1 <= s.length <= 500
/// 2. s consists of characters '0' or '1'
/// 3. s[0] == '1'
/// </summary>
int LeetCodeString::numSteps(string s)
{
    deque<int> str;
    for (size_t i = 0; i < s.size(); i++)
    {
        str.push_front(s[i] - '0');
    }

    int result = 0;
    while (str.size() != 1)
    {
        result++;
        if (str.front() == 0) str.pop_front();
        else
        {
            int carry = 1;
            for (size_t i = 0; i < str.size(); i++)
            {
                str[i] += carry;
                if (str[i] > 1)
                {
                    str[i] = 0;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                    break;
                }
            }
            if (carry == 1) str.push_back(1);
        }
    }

    return result;
}

/// <summary>
/// Leet code #1408. String Matching in an Array 
/// 
/// Easy
///
/// Given an array of string words. Return all strings in words which 
/// is substring of another word in any order. 
///
/// String words[i] is substring of words[j], if can be obtained removing 
/// some characters to left and/or right side of words[j].
///
/// Example 1:
/// Input: words = ["mass","as","hero","superhero"]
/// Output: ["as","hero"]
/// Explanation: "as" is substring of "mass" and "hero" is substring 
/// of "superhero".
/// ["hero","as"] is also a valid answer.
///
/// Example 2:
/// Input: words = ["leetcode","et","code"]
/// Output: ["et","code"]
/// Explanation: "et", "code" are substring of "leetcode".
///
/// Example 3:
/// Input: words = ["blue","green","bu"]
/// Output: []
///
/// Constraints:
/// 1. 1 <= words.length <= 100
/// 2. 1 <= words[i].length <= 30
/// 3. words[i] contains only lowercase English letters.
/// 4. It's guaranteed that words[i] will be unique.
/// </summary>
vector<string> LeetCodeString::stringMatching(vector<string>& words)
{
    vector<string> result;
    for (size_t i = 0; i < words.size(); i++)
    {
        for (size_t j = 0; j < words.size(); j++)
        {
            if (i == j) continue;
            // look outer loop for result, avoid duplication
            if (words[j].find(words[i]) != string::npos)
            {
                result.push_back(words[i]);
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1410. HTML Entity Parser 
/// 
/// Medium
///
/// HTML entity parser is the parser that takes HTML code as input and 
/// replace all the entities of the special characters by the characters 
/// itself.
///
/// The special characters and their entities for HTML are:
///
/// Quotation Mark: the entity is &quot; and symbol character is ".
/// Single Quote Mark: the entity is &apos; and symbol character is '.
/// Ampersand: the entity is &amp; and symbol character is &.
/// Greater Than Sign: the entity is &gt; and symbol character is >.
/// Less Than Sign: the entity is &lt; and symbol character is <.
/// Slash: the entity is &frasl; and symbol character is /.
/// Given the input text string to the HTML parser, you have to implement 
/// the entity parser.
///
/// Return the text after replacing the entities by the special characters.
/// 
/// Example 1:
/// Input: text = "&amp; is an HTML entity but &ambassador; is not."
/// Output: "& is an HTML entity but &ambassador; is not."
/// Explanation: The parser will replace the &amp; entity by &
///
/// Example 2:
/// Input: text = "and I quote: &quot;...&quot;"
/// Output: "and I quote: \"...\""
///
/// Example 3:
/// Input: text = "Stay home! Practice on Leetcode :)"
/// Output: "Stay home! Practice on Leetcode :)"
///
/// Example 4:
/// Input: text = "x &gt; y &amp;&amp; x &lt; y is always false"
/// Output: "x > y && x < y is always false"
///
/// Example 5:
/// Input: text = "leetcode.com&frasl;problemset&frasl;all"
///  Output: "leetcode.com/problemset/all"
/// 
/// Constraints:
/// 1. 1 <= text.length <= 10^5
/// 2. The string may contain any possible characters out of all the 256 
///    ASCII characters.
/// </summary>
string LeetCodeString::entityParser(string text)
{
    string result;
    size_t index = 0;
    while (index < text.size())
    {
        if (text[index] == '&')
        {
            string token;
            while (index < text.size())
            {
                token.push_back(text[index]);
                index++;
                if (text[index-1] == ';') break;
            }
            if (token == "&quot;") result.append("\"");
            else if (token == "&apos;") result.append("\'");
            else if (token == "&amp;") result.append("&");
            else if (token == "&gt;") result.append(">");
            else if (token == "&lt;") result.append("<");
            else if (token == "&frasl;") result.append("/");
            else result.append(token);
        }
        else
        {
            result.push_back(text[index]);
            index++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1417. Reformat The String
/// 
/// Easy
///
/// Given alphanumeric string s. (Alphanumeric string is a string 
/// consisting of lowercase English letters and digits).
///
/// You have to find a permutation of the string where no letter is 
/// followed by another letter and no digit is followed by another 
/// digit. That is, no two adjacent characters have the same type.
///
/// Return the reformatted string or return an empty string if it is 
/// impossible to reformat the string.
/// 
/// Example 1:
/// Input: s = "a0b1c2"
/// Output: "0a1b2c"
/// Explanation: No two adjacent characters have the same type in 
/// "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
///
/// Example 2:
/// Input: s = "leetcode"
/// Output: ""
/// Explanation: "leetcode" has only characters so we cannot separate 
/// them by digits.
///
/// Example 3:
/// Input: s = "1229857369"
/// Output: ""
/// Explanation: "1229857369" has only digits so we cannot separate them 
/// by characters.
///
/// Example 4:
/// Input: s = "covid2019"
/// Output: "c2o0v1i9d"
///
/// Example 5:
/// Input: s = "ab123"
/// Output: "1a2b3"
///
/// Constraints:
/// 1. 1 <= s.length <= 500
/// 2. s consists of only lowercase English letters and/or digits.
/// </summary>
string LeetCodeString::reformat(string s)
{
    vector<char> nums, letters;
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) nums.push_back(s[i]);
        else letters.push_back(s[i]);
    }
    if (std::abs((int)nums.size() - (int)letters.size()) > 1)
    {
        return result;
    }
    else if (nums.size() > letters.size())
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            result.push_back(nums[i]);
            if (i < letters.size()) result.push_back(letters[i]);
        }
    }
    else
    {
        for (size_t i = 0; i < letters.size(); i++)
        {
            result.push_back(letters[i]);
            if (i < nums.size()) result.push_back(nums[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1422. Maximum Score After Splitting a String
/// 
/// Easy
///
/// Given a string s of zeros and ones, return the maximum score after 
/// splitting the string into two non-empty substrings (i.e. left 
/// substring and right substring).
///
/// The score after splitting a string is the number of zeros in the 
/// left substring plus the number of ones in the right substring.
///
/// Example 1:
/// Input: s = "011101"
/// Output: 5 
/// Explanation: 
/// All possible ways of splitting s into two non-empty substrings are:
/// left = "0" and right = "11101", score = 1 + 4 = 5 
/// left = "01" and right = "1101", score = 1 + 3 = 4 
/// left = "011" and right = "101", score = 1 + 2 = 3 
/// left = "0111" and right = "01", score = 1 + 1 = 2 
/// left = "01110" and right = "1", score = 2 + 1 = 3
///
/// Example 2:
/// Input: s = "00111"
/// Output: 5
/// Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
///
/// Example 3:
///
/// Input: s = "1111"
/// Output: 3
///
/// Constraints:
///
/// 1. 2 <= s.length <= 500
/// 2. The string s consists of characters '0' and '1' only.
/// </summary>
int LeetCodeString::maxScore(string s)
{
    int result = 0;
    int score = std::count(s.begin(), s.end(), '1');
    for (size_t i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '0') score++;
        else score--;
        result = max(result, score);
    }
    return result;
}


/// <summary>
/// Leet code #1433. Check If a String Can Break Another String
/// 
/// Medium
///
/// Given two strings: s1 and s2 with the same size, check if some 
/// permutation of string s1 can break some permutation of string s2 
/// or vice-versa (in other words s2 can break s1).
/// 
/// A string x can break string y (both of size n) if x[i] >= y[i] 
/// (in alphabetical order) for all i between 0 and n-1.
///
/// Example 1:
/// Input: s1 = "abc", s2 = "xya"
/// Output: true
/// Explanation: "ayx" is a permutation of s2="xya" which can break 
/// to string "abc" which is a permutation of s1="abc".
///
/// Example 2:
/// Input: s1 = "abe", s2 = "acd"
/// Output: false 
/// Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", 
/// "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", 
/// "adc", "cad", "cda", "dac" and "dca". However, there is not any 
/// permutation from s1 which can break some permutation from s2 and 
/// vice-versa.
///
/// Example 3:
/// Input: s1 = "leetcodee", s2 = "interview"
/// Output: true
/// Constraints:
/// 1. s1.length == n
/// 2. s2.length == n
/// 3. 1 <= n <= 10^5
/// 4. All strings consist of lowercase English letters.
/// </summary>
bool LeetCodeString::checkIfCanBreak(string s1, string s2)
{
    int result = 0;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s2[i]) continue;
        int comp = (s1[i] < s2[i]) ? -1 : 1;
        if (result * comp == -1) return false;
        result = comp;
    }
    return true;
}

/// <summary>
/// Leet code #1427. Perform String Shifts
/// 
/// Easy
///
/// You are given a string s containing lowercase English letters, 
/// and a matrix shift, where shift[i] = [direction, amount]:
///
/// direction can be 0 (for left shift) or 1 (for right shift). 
/// amount is the amount by which string s is to be shifted.
/// A left shift by 1 means remove the first character of s and append 
/// it to the end.
/// Similarly, a right shift by 1 means remove the last character of s 
/// and add it to the beginning.
/// Return the final string after all operations.
///
/// Example 1:
/// Input: s = "abc", shift = [[0,1],[1,2]]
/// Output: "cab"
/// Explanation: 
/// [0,1] means shift to left by 1. "abc" -> "bca"
/// [1,2] means shift to right by 2. "bca" -> "cab"
///
/// Example 2:
/// Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
/// Output: "efgabcd"
/// Explanation:  
/// [1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
/// [1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
/// [0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
/// [1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
///
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s only contains lower case English letters.
/// 3. 1 <= shift.length <= 100
/// 4. shift[i].length == 2
/// 5. 0 <= shift[i][0] <= 1
/// 6. 0 <= shift[i][1] <= 100
/// </summary>
string LeetCodeString::stringShift(string s, vector<vector<int>>& shift)
{
    int delta = 0;
    for (size_t i = 0; i < shift.size(); i++)
    {
        if (shift[i][0] == 0) delta += shift[i][1];
        else delta -= shift[i][1];
    }
    delta %= (int)s.size();
    string result = s;
    if (delta > 0)
    {
        result = s.substr(delta) + s.substr(0, delta);
    }
    else if (delta < 0)
    {
        result = s.substr(s.size() + delta) + s.substr(0, s.size() + delta);
    }
    return result;
}

/// <summary>
/// Leet code #1446. Consecutive Characters
///
/// Easy
///
/// Given a string s, the power of the string is the maximum length of 
/// a non-empty substring that contains only one unique character.
///
/// Return the power of the string.
///
/// Example 1:
/// Input: s = "leetcode"
/// Output: 2
/// Explanation: The substring "ee" is of length 2 with the character 'e' 
/// only.
///
/// Example 2:
/// Input: s = "abbcccddddeeeeedcba"
/// Output: 5
/// Explanation: The substring "eeeee" is of length 5 with the character 
/// 'e' only.
///
/// Example 3:
/// Input: s = "triplepillooooow"
/// Output: 5
///
/// Example 4:
/// Input: s = "hooraaaaaaaaaaay"
/// Output: 11
///
/// Example 5:
/// Input: s = "tourist"
/// Output: 1
///
/// Constraints:
/// 1. 1 <= s.length <= 500
/// 2. s contains only lowercase English letters.
/// </summary>
int LeetCodeString::maxPower(string s)
{
    int last_char = s[0];
    int count = 0;
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == last_char)
        {
            count++;
        }
        else
        {
            last_char = s[i];
            count = 1;
        }
        result = max(result, count);
    }
    return result;
}

/// <summary>
/// Leet code #1451. Rearrange Words in a Sentence
/// 
/// Medium
///
/// Given a sentence text (A sentence is a string of space-separated 
/// words) in the following format:
///
/// First letter is in upper case.
/// Each word in text are separated by a single space.
/// Your task is to rearrange the words in text such that all words are 
/// rearranged in an increasing order of their lengths. If two words 
/// have the same length, arrange them in their original order.
///
/// Return the new text following the format shown above.
/// Example 1:
/// Input: text = "Leetcode is cool"
/// Output: "Is cool leetcode"
/// Explanation: There are 3 words, "Leetcode" of length 8, "is" of 
/// length 2 and "cool" of length 4.
/// Output is ordered by length and the new first word starts with 
/// capital letter.
///
/// Example 2:
/// Input: text = "Keep calm and code on"
/// Output: "On and keep calm code"
/// Explanation: Output is ordered as follows:
/// "On" 2 letters.
/// "and" 3 letters.
/// "keep" 4 letters in case of tie order by position in original text.
/// "calm" 4 letters.
/// "code" 4 letters.
///
/// Example 3:
/// Input: text = "To be or not to be"
/// Output: "To be or to be not"
///
/// Constraints:
/// 1. text begins with a capital letter and then contains lowercase 
///    letters and single space between words.
/// 2. 1 <= text.length <= 10^5
/// </summary>
string LeetCodeString::arrangeWords(string text)
{
    vector<string> words;
    priority_queue<pair<int, int>> pq;

    string word;
    for (size_t i = 0; i <= text.size(); i++)
    {
        if (i == text.size() || isspace(text[i]))
        {
            if (!word.empty())
            {
                pq.push(make_pair(0 - (int)word.size(), 0-words.size()));
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word.push_back(tolower(text[i]));
        }
    }
    string result;
    while (!pq.empty())
    {
        pair<int, int> pos = pq.top();
        pq.pop();
        string word = words[-pos.second];
        if (result.empty())
        {
            word[0] = toupper(word[0]);
        }
        else
        {
            result.push_back(' ');
        }
        result.append(word);
    }
    return result;
}

/// <summary>
/// Leet code #1455. Check If a Word Occurs As a Prefix of Any Word in a 
///                  Sentence
/// 
/// Easy
///
/// Given a sentence that consists of some words separated by a single 
/// space, and a searchWord.
/// 
/// You have to check if searchWord is a prefix of any word in sentence.
///
/// Return the index of the word in sentence where searchWord is a prefix 
/// of this word (1-indexed).
///
/// If searchWord is a prefix of more than one word, return the index of 
/// the first word (minimum index). If there is no such word return -1.
///
/// A prefix of a string S is any leading contiguous substring of S.
///
/// Example 1:
/// Input: sentence = "i love eating burger", searchWord = "burg"
/// Output: 4
/// Explanation: "burg" is prefix of "burger" which is the 4th word in 
/// the sentence.
///
/// Example 2:
/// Input: sentence = "this problem is an easy problem", searchWord = "pro"
/// Output: 2
/// Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th 
/// word in the sentence, but we return 2 as it's the minimal index.
///
/// Example 3:
/// Input: sentence = "i am tired", searchWord = "you"
/// Output: -1
/// Explanation: "you" is not a prefix of any word in the sentence.
///
/// Example 4:
///
/// Input: sentence = "i use triple pillow", searchWord = "pill"
/// Output: 4
///
/// Example 5:
/// Input: sentence = "hello from the other side", searchWord = "they"
/// Output: -1
///
/// Constraints:
/// 1. 1 <= sentence.length <= 100
/// 2. 1 <= searchWord.length <= 10
/// 3. sentence consists of lowercase English letters and spaces.
/// 4. searchWord consists of lowercase English letters.
/// </summary>
int LeetCodeString::isPrefixOfWord(string sentence, string searchWord)
{
    int index = 0;
    int result = 1;
    for (size_t i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            index = 0;
            result++;
        }
        else
        {
            if (index == -1) continue;
            if (sentence[i] == searchWord[index])
            {
                index++;
                if (index == searchWord.size()) return result;
            }
            else
            {
                index = -1;
            }
        }
    }

    return -1;
}

/// <summary>
/// Leet code #1456. Maximum Number of Vowels in a Substring of Given 
///                  Length
///                   
/// Medium
/// 
/// Given a string s and an integer k.
/// Return the maximum number of vowel letters in any substring of s 
/// with length k.
///
/// Vowel letters in English are (a, e, i, o, u).
/// 
/// Example 1:
/// Input: s = "abciiidef", k = 3
/// Output: 3
/// Explanation: The substring "iii" contains 3 vowel letters.
///
/// Example 2:
/// Input: s = "aeiou", k = 2
/// Output: 2
/// Explanation: Any substring of length 2 contains 2 vowels.
///
/// Example 3:
/// Input: s = "leetcode", k = 3
/// Output: 2
/// Explanation: "lee", "eet" and "ode" contain 2 vowels.
///
/// Example 4:
/// Input: s = "rhythms", k = 4
/// Output: 0
/// Explanation: We can see that s doesn't have any vowel letters.
///
/// Example 5:
/// Input: s = "tryhard", k = 4
/// Output: 1
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of lowercase English letters.
/// 3. 1 <= k <= s.length
/// </summary>
int LeetCodeString::maxVowels(string s, int k)
{
    int result = 0;
    int vowels = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vowels++;
        }
        if (i >= k)
        {
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u')
            {
                vowels--;
            }
        }
        if (i >= k - 1) result = max(result, vowels);
    }
    return result;
}

/// <summary>
/// Leet code #471. Encode String with Shortest Length
/// </summary>
void LeetCodeString::findRepeatPattern(string s, size_t start, size_t end, vector<vector<string>>& result)
{
    int length = end - start + 1;
    string str = s.substr(start, length);

    int count = 1;
    size_t next = start + length;
    // use greedy to look for repeated pattern as far as possible
    while ((next + length <= s.size()) && (s.substr(next, length) == str))
    {
        count++;
        // on each repeated substring they should have same encoding
        result[next][next + length - 1] = result[start][end];
        next += length;
        if (count > 1)
        {
            // with each n repeated substring the summary is n[substring]
            if (result[start][next - 1].empty())
            {
                result[start][next - 1] = s.substr(start, next - start);
            }
            string new_str = to_string(count) + "[" + result[start][end] + "]";
            if (new_str.size() < result[start][next - 1].size())
            {
                result[start][next - 1] = new_str;
            }
        }
    }
    return;
}

/// <summary>
/// Leet code #471. Encode String with Shortest Length
///
/// Given a non-empty string, encode the string such that its encoded 
/// length is the shortest.
/// The encoding rule is: k[encoded_string], where the encoded_string 
/// inside the square brackets is being repeated exactly k times.
/// Note:
/// 1.k will be a positive integer and encoded string will not be empty or 
///   have extra space.
/// 2.You may assume that the input string contains only lowercase English 
///   letters. The string's length is at most 160.
/// 3.If an encoding process does not make the string shorter, then do not 
///   encode it. If there are several solutions, return any of them is fine.
///
/// Example 1: 
/// Input: "aaa"
/// Output: "aaa"
/// Explanation: There is no way to encode it such that it is shorter than 
/// the input string, so we do not encode it.
/// 
/// Example 2: 
/// Input: "aaaaa"
/// Output: "5[a]"
/// Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
///
/// Example 3: 
/// Input: "aaaaaaaaaa"
/// Output: "10[a]"
/// Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them 
/// have the same length = 5, which is the same as "10[a]".
///
/// Example 4: 
/// Input: "aabcaabcd"
/// Output: "2[aabc]d"
/// Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
/// 
/// Example 5: 
/// Input: "abbbabbbcabbbabbbc"
/// Output: "2[2[abbb]c]"
/// Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded 
/// to "2[abbb]c", so one answer can be "2[2[abbb]c]".
/// </summary>
string LeetCodeString::encode(string s)
{
    vector<vector<string>> result(s.size(), vector<string>(s.size()));
    // two dimension programming
    for (size_t step = 0; step < s.size(); step++)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (i + step >= s.size())
            {
                break;
            }

            // we may process this range before.
            if (result[i][i + step].empty())
            {
                result[i][i + step] = s.substr(i, step + 1);
            }

            // less than 5 characters, no need to encode
            if (step >= 4)
            {
                // search for better option by using sub range
                for (size_t k = 0; k < step; k++)
                {
                    // if the whole range can be replaced by the combination of two sub ranges with shorter
                    // encoded string, let's do it.
                    if (result[i][i + step].size() > result[i][i + k].size() + result[i + k + 1][i + step].size())
                    {
                        result[i][i + step] = result[i][i + k] + result[i + k + 1][i + step];
                    }
                }

            }
            findRepeatPattern(s, i, i + step, result);
        }
    }
    return result[0][s.size() - 1];
}

/// <summary>
/// Leet code # 466. Count The Repetitions 
///
/// Define S = [s,n] as the string S which consists of n 
/// connected strings s. For example, ["abc", 3] ="abcabcabc". 
/// On the other hand, we define that string s1 can be obtained from string s2 
/// if we can remove some characters from s2 such that it becomes s1. For 
/// example, "abc" can be obtained from “abdbec” based on our definition, but 
/// it can not be obtained from "acbbe".
/// You are given two non-empty strings s1 and s2 (each at most 100 characters 
/// long) and two integers 0 <= n1 <= 106 and 1 <= n2 <= 106. Now consider the 
/// strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum 
/// integer M such that [S2,M] can be obtained from S1.
///
/// Example: 
/// Input:
/// s1="acb", n1=4
/// s2="ab", n2=2
/// Return:
/// 2
/// </summary>
int LeetCodeString::getMaxRepetitions(string s1, int n1, string s2, int n2)
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
int LeetCodeString::wordsTyping(vector<string>& sentence, int rows, int cols)
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
/// Leet code #816. Ambiguous Coordinates
/// </summary>
vector<string> LeetCodeString::getAllDecimals(string S)
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
vector<string> LeetCodeString::ambiguousCoordinates(string S)
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
/// Leet code #936. Stamping The Sequence
/// </summary>
vector<int> LeetCodeString::searchStamp(string& stamp, string& target, int& reduce)
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
vector<int> LeetCodeString::movesToStamp(string stamp, string target)
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
bool LeetCodeString::checkValidString(string s)
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
/// Leet code #1507. Reformat Date
///
/// Easy
///	
/// Given a date string in the form Day Month Year, where:
/// Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
/// Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", 
/// "Aug", "Sep", "Oct", "Nov", "Dec"}.   
/// Year is in the range [1900, 2100].
/// Convert the date string to the format YYYY-MM-DD, where:
/// YYYY denotes the 4 digit year.
/// MM denotes the 2 digit month.
/// DD denotes the 2 digit day.
///
/// Example 1:
/// Input: date = "20th Oct 2052" 
/// Output: "2052-10-20"
///
/// Example 2:
/// Input: date = "6th Jun 1933"
/// Output: "1933-06-06"
///
/// Example 3:
/// Input: date = "26th May 1960"
/// Output: "1960-05-26"
/// 
/// Constraints:
/// 1. The given dates are guaranteed to be valid, so no error handling is 
///    necessary.
/// </summary>
string LeetCodeString::reformatDate(string date)
{
    unordered_map<string, string> month_map =
    {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
        {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
    size_t offset = 0;
    size_t pos = date.find(' ', offset);
    string day_str = date.substr(offset, pos-offset);
    offset = pos + 1;
    pos = date.find(' ', offset);
    string month_str = date.substr(offset, pos-offset);
    offset = pos + 1;
    string year = date.substr(offset);

    string day;
    for (size_t i = 0; i < day_str.size(); i++)
    {
        if (isdigit(day_str[i])) day.push_back(day_str[i]);
    }
    if (day.size() == 1) day = "0" + day;
    string month = month_map[month_str];
    string result;
    result.append(year);
    result.push_back('-');
    result.append(month);
    result.push_back('-');
    result.append(day);

    return result;
}

/// <summary>
/// Leet code #1531. String Compression II
/// </summary>
int LeetCodeString::getLengthOfOptimalCompression(string& s, int left, int k, vector<vector<int>> &dp)
{
    int n = s.size();
    // delete all remaining
    if (dp[left][k] != 1000) return dp[left][k];
    if (n - left <= k)
    {
        dp[left][k] = 0;
        return dp[left][k];
    }
    vector<int> char_cnt(26);
    int most = 0;
    for (int i = left; i < n; i++)
    {
        // calculate count length
        char_cnt[s[i] - 'a']++;
        // not the most frequent character, ignore
        if (char_cnt[s[i] - 'a'] <= most) continue;
        most = char_cnt[s[i] - 'a'];
        int len = (most <= 1) ? 0 : (most < 10) ? 1 : (most < 100) ? 2 : 3;
        int remaining = k - (i - left + 1 - most);
        // delete too many characters
        if (remaining < 0) continue;
        // optimization, handle long repeat characters
        if (i < n - 1 && s[i + 1] == s[i])
        {
            int next_len = (most + 1 < 10) ? 1 : (most + 1 < 100) ? 2 : 3;
            if (len == next_len) continue;
        }
        dp[left][k] = min(dp[left][k], 1+ len + getLengthOfOptimalCompression(s, i + 1, remaining, dp));
    }
    return dp[left][k];
}

/// <summary>
/// Leet code #1531. String Compression II
/// 
/// Hard
///
/// Run-length encoding is a string compression method that works by 
/// replacing consecutive identical characters (repeated 2 or more times) 
/// with the concatenation of the character and the number marking the 
/// count of the characters (length of the run). For example, to compress 
/// the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". 
/// Thus the compressed string becomes "a2bc3".
/// 
/// Notice that in this problem, we are not adding '1' after single 
/// characters.
///
/// Given a string s and an integer k. You need to delete at most k 
/// characters from s such that the run-length encoded version of s 
/// has minimum length.
///
/// Find the minimum length of the run-length encoded version of s 
/// after deleting at most k characters.
///
/// Example 1:
/// Input: s = "aaabcccd", k = 2
/// Output: 4
/// Explanation: Compressing s without deleting anything will give us 
/// "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' 
/// would at most decrease the length of the compressed string to 5, 
/// for instance delete 2 'a' then we will have s = "abcccd" which 
/// compressed is abc3d. Therefore, the optimal way is to delete 'b' 
/// and 'd', then the compressed version of s will be "a3c3" of length 4.
///
/// Example 2:
/// Input: s = "aabbaa", k = 2
/// Output: 2
/// Explanation: If we delete both 'b' characters, the resulting 
/// compressed string would be "a4" of length 2.
///
/// Example 3:
/// 
/// Input: s = "aaaaaaaaaaa", k = 0
/// Output: 3
/// Explanation: Since k is zero, we cannot delete anything. The 
/// compressed string is "a11" of length 3.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. 0 <= k <= s.length
/// 3. s contains only lowercase English letters.
/// </summary>
int LeetCodeString::getLengthOfOptimalCompression(string s, int k)
{
    vector<vector<int>> dp(101, vector<int>(101, 1000));
    return getLengthOfOptimalCompression(s, 0, k, dp);
}


/// <summary>
/// Leet code #1528. Shuffle String
/// 
/// Easy
///
/// Given a string s and an integer array indices of the same length.
/// The string s will be shuffled such that the character at the ith 
/// position moves to indices[i] in the shuffled string.
/// 
/// Return the shuffled string.
/// 
/// Example 1:
/// Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
/// Output: "leetcode"
/// Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
///
/// Example 2:
/// Input: s = "abc", indices = [0,1,2]
/// Output: "abc"
/// Explanation: After shuffling, each character remains in its position.
///
/// Example 3:
/// Input: s = "aiohn", indices = [3,1,4,2,0]
/// Output: "nihao"
///
/// Example 4:
/// Input: s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
/// Output: "arigatou"
///
/// Example 5:
/// Input: s = "art", indices = [1,0,2]
/// Output: "rat"
///
/// Constraints:
/// 1. s.length == indices.length == n
/// 2. 1 <= n <= 100
/// 3. s contains only lower-case English letters.
/// 4. 0 <= indices[i] < n
/// 5. All values of indices are unique (i.e. indices is a permutation 
///    of the integers from 0 to n - 1).
/// </summary>
string LeetCodeString::restoreString(string s, vector<int>& indices)
{
    string result = s;
    for (size_t i = 0; i < indices.size(); i++)
    {
        result[indices[i]] = s[i];
    }
    return result;
}

/// <summary>
/// Leet code #1525. Number of Good Ways to Split a String
/// 
/// Medium
///
/// You are given a string s, a split is called good if you can split 
/// s into 2 non-empty strings p and q where its concatenation is equal
/// to s and the number of distinct letters in p and q are the same.
///
/// Return the number of good splits you can make in s.
/// Example 1:
/// Input: s = "aacaba"
/// Output: 2
/// Explanation: There are 5 ways to split "aacaba" and 2 of them are good.
/// ("a", "acaba") Left string and right string contains 1 and 3 different 
/// letters respectively.
/// ("aa", "caba") Left string and right string contains 1 and 3 different 
/// letters respectively.
/// ("aac", "aba") Left string and right string contains 2 and 2 different 
/// letters respectively (good split).
/// ("aaca", "ba") Left string and right string contains 2 and 2 different 
/// letters respectively (good split).
/// ("aacab", "a") Left string and right string contains 3 and 1 different 
/// letters respectively.
///
/// Example 2:
/// Input: s = "abcd"
/// Output: 1
/// Explanation: Split the string as follows ("ab", "cd").
///
/// Example 3:
/// Input: s = "aaaaa"
/// Output: 4
/// Explanation: All possible splits are good.
///
/// Example 4:
/// 
/// Input: s = "acbadbaada"
/// Output: 2
///
/// Constraints:
/// 1. s contains only lowercase English letters.
/// 2. 1 <= s.length <= 10^5
/// </summary>
int LeetCodeString::numSplits(string s)
{
    vector<int> left(26), right(26);
    int left_count = 0, right_count = 0;
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        right[index]++;
        if (right[index] == 1) right_count++;
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        right[index]--;
        left[index]++;
        if (right[index] == 0) right_count--;
        if (left[index] == 1) left_count++;
        if (left_count == right_count) result++;
    }
    return result;
}

/// <summary>
/// Leet code #1540. Can Convert String in K Moves
/// 
/// Medium
///
/// Given two strings s and t, your goal is to convert s into t in k moves
/// or less.
///
/// During the ith (1 <= i <= k) move you can:
/// Choose any index j (1-indexed) from s, such that 1 <= j <= s.length 
/// and j has not been chosen in any previous move, and shift the character
/// at that index i times.
/// Do nothing.
/// Shifting a character means replacing it by the next letter in the 
/// alphabet (wrapping around so that 'z' becomes 'a'). Shifting a 
/// character by i means applying the shift operations i times.
///
/// Remember that any index j can be picked at most once.
///
/// Return true if it's possible to convert s into t in no more than k 
/// moves, otherwise return false.
///
/// Example 1:
/// Input: s = "input", t = "ouput", k = 9
/// Output: true
/// Explanation: In the 6th move, we shift 'i' 6 times to get 'o'. And in 
/// the 7th move we shift 'n' to get 'u'.
///
/// Example 2:
/// Input: s = "abc", t = "bcd", k = 10
/// Output: false
/// Explanation: We need to shift each character in s one time to convert 
/// it into t. We can shift 'a' to 'b' during the 1st move. However, there 
/// is no way to shift the other characters in the remaining moves to 
/// obtain t from s.
///
/// Example 3:
/// Input: s = "aab", t = "bbb", k = 27
/// Output: true
/// Explanation: In the 1st move, we shift the first 'a' 1 time to get 'b'. 
/// In the 27th move, we shift the second 'a' 27 times to get 'b'.
///
/// Constraints:
/// 1. 1 <= s.length, t.length <= 10^5
/// 2. 0 <= k <= 10^9
/// 3. s, t contain only lowercase English letters.
/// </summary>
bool LeetCodeString::canConvertString(string s, string t, int k)
{
    if (s.size() != t.size()) return false;
    vector<int> arr(26);

    for (size_t i = 0; i < s.size(); i++)
    {
        int index = (t[i] - s[i] + 26) % 26;
        arr[index]++;
    }

    for (size_t i = 1; i < 26; i++)
    {
        arr[i] -= k / 26;
        if ((arr[i] > 1) || (arr[i] > 0 && (int)i > (k % 26)))
        {
            return false;
        }
    }
    return true;
}


/// <summary>
/// Leet code #1541. Minimum Insertions to Balance a Parentheses String
/// 
/// Medium
///
/// Given a parentheses string s containing only the characters '(' 
/// and ')'. A parentheses string is balanced if:
/// 
/// Any left parenthesis '(' must have a corresponding two consecutive 
/// right parenthesis '))'.
/// Left parenthesis '(' must go before the corresponding two consecutive 
/// right parenthesis '))'.
/// For example, "())", "())(())))" and "(())())))" are balanced, ")()", 
/// "()))" and "(()))" are not balanced.
///
/// You can insert the characters '(' and ')' at any position of the 
/// string to balance it if needed.
///
/// Return the minimum number of insertions needed to make s balanced.
/// 
/// Example 1:
/// Input: s = "(()))"
/// Output: 1
/// Explanation: The second '(' has two matching '))', but the first 
/// '(' has only ')' matching. We need to to add one more ')' at the 
/// end of the string to be "(())))" which is balanced.
///
/// Example 2:
/// Input: s = "())"
/// Output: 0
/// Explanation: The string is already balanced.
///
/// Example 3:
/// Input: s = "))())("
/// Output: 3
/// Explanation: Add '(' to match the first '))', Add '))' to match the 
/// last '('.
///
/// Example 4:
/// Input: s = "(((((("
/// Output: 12
/// Explanation: Add 12 ')' to balance the string.
///
/// Example 5:
/// Input: s = ")))))))"
/// Output: 5
/// Explanation: Add 4 '(' at the beginning of the string and one ')' at 
/// the end. The string becomes "(((())))))))".
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of '(' and ')' only.
/// </summary>
int LeetCodeString::minInsertions(string s)
{
    int result = 0;
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (count % 2 == 1)
            {
                result++;
                count--;
            }
            count += 2;
        }
        else count--;
        if (count < 0)
        {
            result++;
            count += 2;
        }
    }
    result += count;
    return result;
}


/// <summary>
/// Leet code #1542. Find Longest Awesome Substring
/// 
/// Hard
///
/// Given a string s. An awesome substring is a non-empty substring of s 
/// such that we can make any number of swaps in order to make it 
/// palindrome.
///
/// Return the length of the maximum length awesome substring of s.
/// 
/// Example 1:
/// Input: s = "3242415"
/// Output: 5
/// Explanation: "24241" is the longest awesome substring, we can form 
/// the palindrome "24142" with some swaps.
///
/// Example 2:
/// Input: s = "12345678"
/// Output: 1
///
/// Example 3:
/// Input: s = "213123"
/// Output: 6
/// Explanation: "213123" is the longest awesome substring, we can form 
/// the palindrome "231132" with some swaps.
///
/// Example 4:
/// Input: s = "00"
/// Output: 2
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists only of digits.
/// </summary>
int LeetCodeString::longestAwesome(string s)
{
    vector<int> pos_map(1024);
    int bits = 0;
    int result = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        bits = bits ^ (1 << (s[i] - '0'));
        if (bits == 0) result = i + 1;
        else
        {
            for (int j = 0; j < 10; j++)
            {
                if ((bits ^ (1 << j)) == 0)
                {
                    result = i + 1;
                }
            }
        }
        // check all digits are even
        if (pos_map[bits] > 0)
        {
            result = max(result, i + 1 - pos_map[bits]);
        }
        else
        {
            pos_map[bits] = i + 1;
        }
        // allow one digit be odd
        for (int j = 0; j < 10; j++)
        {
            int next_bits = bits ^ (1 << j);
            if (pos_map[next_bits] > 0)
            {
                result = max(result, i + 1- pos_map[next_bits]);
            }
        }
    }
    return result;
}


/// <summary>
/// Leet code #1544. Make The String Great
/// 
/// Easy
///
/// Given a string s of lower and upper case English letters.
///
/// A good string is a string which doesn't have two adjacent characters 
/// s[i] and s[i + 1] where:
///
/// 0 <= i <= s.length - 2
/// s[i] is a lower-case letter and s[i + 1] is the same letter but in 
/// upper-case or vice-versa.
/// To make the string good, you can choose two adjacent characters that 
/// make the string bad and remove them. You can keep doing this until 
/// the string becomes good.
///
/// Return the string after making it good. The answer is guaranteed to 
/// be unique under the given constraints.
///
/// Notice that an empty string is also good.
///
/// Example 1:
/// Input: s = "leEeetcode"
/// Output: "leetcode"
/// Explanation: In the first step, either you choose i = 1 or i = 2, 
/// both will result "leEeetcode" to be reduced to "leetcode".
///
/// Example 2:
/// Input: s = "abBAcC"
/// Output: ""
/// Explanation: We have many possible scenarios, and all lead to the 
/// same answer. For example:
/// "abBAcC" --> "aAcC" --> "cC" --> ""
/// "abBAcC" --> "abBA" --> "aA" --> ""
///
/// Example 3:
/// Input: s = "s"
/// Output: "s"
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s contains only lower and upper case English letters.
/// </summary>
string LeetCodeString::makeGood(string s)
{
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (result.empty()) result.push_back(s[i]);
        else
        {
            char ch = result.back();
            if ((tolower(ch) == tolower(s[i])) && (ch != s[i]))
            {
                result.pop_back();
            }
            else
            {
                result.push_back(s[i]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1554. Strings Differ by One Character
/// 
/// Medium
///
/// Given a list of strings dict where all the strings are of the same 
/// length.
/// Return True if there are 2 strings that only differ by 1 character 
/// in the same index, otherwise return False.
///
/// Example 1:
/// Input: dict = ["abcd","acbd", "aacd"]
/// Output: true
/// Output: Strings "abcd" and "aacd" differ only by one character in 
/// the index 1.
///
/// Example 2:
/// Input: dict = ["ab","cd","yz"]
/// Output: false
///
/// Example 3:
/// Input: dict = ["abcd","cccc","abyd","abab"]
/// Output: true
/// 
/// Constraints:
/// 1. Number of characters in dict <= 10^5
/// 2. dict[i].length == dict[j].length
/// 3. dict[i] should be unique.
/// 4. dict[i] contains only lowercase English letters.
/// </summary>
bool LeetCodeString::differByOne(vector<string>& dict)
{
    int m = dict[0].size();
    for (int i = 0; i < m; i++)
    {
        unordered_set<string> str_map;
        for (string str : dict)
        {
            str[i] = '*';
            if (str_map.count(str) > 0)
            {
                return true;
            }
            str_map.insert(str);
        }
    }
    return false;
}

/// <summary>
/// Leet code #1556. Thousand Separator
/// 
/// Easy
///
/// Given an integer n, add a dot (".") as the thousands separator and 
/// return it in string format.
///
/// Example 1:
/// Input: n = 987
/// Output: "987"
///
/// Example 2: 
/// Input: n = 1234
/// Output: "1.234"
///
/// Example 3:
/// Input: n = 123456789
/// Output: "123.456.789"
///
/// Example 4:
/// Input: n = 0
/// Output: "0"
/// Constraints:
/// 1. 0 <= n < 2^31
/// </summary>
string LeetCodeString::thousandSeparator(int n)
{
    string result;
    string str = to_string(n);
    for (size_t i = 0; i < str.size(); i++)
    {
        if (((str.size() - i) % 3 == 0) && !result.empty())
        {
            result.push_back('.');
        }
        result.push_back(str[i]);
    }
    return result;
}

/// <summary>
/// Leet code #1573. Number of Ways to Split a String
/// 
/// Medium
///
/// Given a binary string s (a string consisting only of '0's and '1's), 
/// we can split s into 3 non-empty strings s1, s2, s3 (s1+ s2+ s3 = s).
/// Return the number of ways s can be split such that the number of 
/// characters '1' is the same in s1, s2, and s3.
///
/// Since the answer may be too large, return it modulo 10^9 + 7.
/// 
/// Example 1:
/// Input: s = "10101"
/// Output: 4
/// Explanation: There are four ways to split s in 3 parts where 
/// each part contain the same number of letters '1'.
/// "1|010|1"
/// "1|01|01"
/// "10|10|1"
/// "10|1|01"
///
/// Example 2:
/// Input: s = "1001"
/// Output: 0
///
/// Example 3:
/// Input: s = "0000"
/// Output: 3
/// Explanation: There are three ways to split s in 3 parts.
/// "0|0|00"
/// "0|00|0"
/// "00|0|0"
///
/// Example 4:
/// Input: s = "100100010100110"
/// Output: 12
/// Constraints:
/// 1. 3 <= s.length <= 10^5
/// 2. s[i] is '0' or '1'.
/// </summary>
int LeetCodeString::numWays(string s)
{
    long long M = 1000000007;
    int total_ones = 0;
    for (char ch : s)
    {
        total_ones += (ch == '1') ? 1 : 0;
    }
    long long result = 0;
    if (total_ones == 0) result = (long long)(s.size() - 1) * (long long)(s.size() - 2) / 2;
    else if (total_ones % 3 != 0) result = 0;
    else
    {
        int ones = 0;
        int pos = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                ones++;
                if (ones == total_ones / 3)
                {
                    pos = i;
                }
                if (ones == total_ones / 3 + 1)
                {
                    result = (long long)i - (long long)pos;
                }
                if (ones == total_ones / 3 * 2)
                {
                    pos = i;
                }
                if (ones == total_ones / 3 * 2 + 1)
                {
                    result = result * ((long long)i - (long long)pos);
                }
            }
        }
    }
    return (int)(result % M);
}

/// <summary>
/// Leet code #1576. Replace All ?'s to Avoid Consecutive Repeating 
///           Characters
/// 
/// Easy
///
/// Given a string s containing only lower case English letters and 
/// the '?' character, convert all the '?' characters into lower case 
/// letters such that the final string does not contain any consecutive 
/// repeating characters. You cannot modify the non '?' characters.
///
/// It is guaranteed that there are no consecutive repeating characters 
/// in the given string except for '?'.
///
/// Return the final string after all the conversions (possibly zero) 
/// have been made. If there is more than one solution, return any of 
/// them. It can be shown that an answer is always possible with the 
/// given constraints.
///
/// Example 1:
/// Input: s = "?zs"
/// Output: "azs"
/// Explanation: There are 25 solutions for this problem. From "azs" 
/// to "yzs", all are valid. Only "z" is an invalid modification as 
/// the string will consist of consecutive repeating characters in "zzs".
///
/// Example 2:
/// Input: s = "ubv?w"
/// Output: "ubvaw"
/// Explanation: There are 24 solutions for this problem. Only "v" and 
/// "w" are invalid modifications as the strings will consist of 
/// consecutive repeating characters in "ubvvw" and "ubvww".
///
/// Example 3:
/// Input: s = "j?qg??b"
/// Output: "jaqgacb"
///
/// Example 4:
/// Input: s = "??yw?ipkj?"
/// Output: "acywaipkja"
///
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s contains only lower case English letters and '?'.
/// </summary>
string LeetCodeString::modifyString(string s)
{
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != '?') result.push_back(s[i]);
        else
        {
            for (int j = 0; j < 26; j++)
            {
                char ch = 'a' + j;
                if (i > 0 && result[i - 1] == ch) continue;
                if (i < s.size() - 1 && s[i + 1] == ch) continue;
                result.push_back(ch);
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1578. Minimum Deletion Cost to Avoid Repeating Letters 
/// 
/// Medium
///
/// Given a string s and an array of integers cost where cost[i] is the 
/// cost of deleting the ith character in s.
///
/// Return the minimum cost of deletions such that there are no two 
/// identical letters next to each other.
///
/// Notice that you will delete the chosen characters at the same time, 
/// in other words, after deleting a character, the costs of deleting 
/// other characters will not change.
/// 
/// Example 1:
/// Input: s = "abaac", cost = [1,2,3,4,5]
/// Output: 3
/// Explanation: Delete the letter "a" with cost 3 to get "abac" (String 
/// without two identical letters next to each other).
///
/// Example 2:
/// Input: s = "abc", cost = [1,2,3]
/// Output: 0
/// Explanation: You don't need to delete any character because there are 
/// no identical letters next to each other.
///
/// Example 3:
/// Input: s = "aabaa", cost = [1,2,3,4,1]
/// Output: 2
/// Explanation: Delete the first and the last character, getting the 
/// string ("aba").
/// 
/// Constraints:
/// 1. s.length == cost.length
/// 2. 1 <= s.length, cost.length <= 10^5
/// 3. 1 <= cost[i] <= 10^4
/// 4. s contains only lowercase English letters.
/// </summary>
int LeetCodeString::minCost(string s, vector<int>& cost)
{
    int first = 0;
    int last = 0;
    int result = 0;
    for (size_t i = 1; i <= s.size(); i++)
    {
        last++;
        if (i == s.size() || s[i] != s[i-1])
        {
            if (last - first > 1)
            {
                int sum = 0;
                priority_queue<int> pq;
                for (int j = first; j < last; j++)
                {
                    pq.push(cost[j]);
                    sum += cost[j];
                }
                result += sum - pq.top();
            }
            first = last;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1592. Rearrange Spaces Between Words
/// 
/// Easy
///
/// You are given a string text of words that are placed among some number
/// of spaces. Each word consists of one or more lowercase English letters
/// and are separated by at least one space. It's guaranteed that text 
/// contains at least one word.
///
/// Rearrange the spaces so that there is an equal number of spaces 
/// between every pair of adjacent words and that number is maximized. 
/// If you cannot redistribute all the spaces equally, place the extra 
/// spaces at the end, meaning the returned string should be the same 
/// length as text.
///
/// Return the string after rearranging the spaces.
///
/// Example 1:
/// Input: text = "  this   is  a sentence "
/// Output: "this   is   a   sentence"
/// Explanation: There are a total of 9 spaces and 4 words. We can evenly 
/// divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
///
/// Example 2:
/// Input: text = " practice   makes   perfect"
/// Output: "practice   makes   perfect "
/// Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 
/// spaces plus 1 extra space. We place this extra space at the end of the 
/// string.
///
/// Example 3:
/// Input: text = "hello   world"
/// Output: "hello   world"
///
/// Example 4:
/// Input: text = "  walks  udp package   into  bar a"
/// Output: "walks  udp  package  into  bar  a "
///
/// Example 5:
/// Input: text = "a"
/// Output: "a"
///
/// Constraints:
/// 1. 1 <= text.length <= 100
/// 2. text consists of lowercase English letters and ' '.
/// 3. text contains at least one word.
/// </summary>
string LeetCodeString::reorderSpaces(string text)
{
    vector<string> words;
    int spaces = 0;
    string token;
    for (size_t i = 0; i <= text.size(); i++)
    {
        if (i == text.size())
        {
            if (!token.empty())
            {
                words.push_back(token);
                token.clear();
            }
        }
        if (isspace(text[i]))
        {
            spaces++;
            if (!token.empty())
            {
                words.push_back(token);
                token.clear();
            }
        }
        else
        {
            token.push_back(text[i]);
        }
    }
    string result;
    int divisor = 0;
    int remainder = 0;
    int count = words.size();
    if (count == 1)
    {
        divisor = 0;
        remainder = spaces;
    }
    else
    {
        divisor = spaces / (count - 1);
        remainder = spaces % (count - 1);
    }
    for (size_t i = 0; i < words.size(); i++)
    {
        result.append(words[i]);
        if (i == words.size() - 1)
            result.append(remainder, ' ');
        else
            result.append(divisor, ' ');
    }
    return result;
}

/// <summary>
/// Leet code #1598. Crawler Log Folder
/// 
/// Easy
///
/// The Leetcode file system keeps a log each time some user performs a 
/// change folder operation.
///
/// The operations are described below:
///
/// "../" : Move to the parent folder of the current folder. (If you are 
/// already in the main folder, remain in the same folder).
/// "./" : Remain in the same folder.
/// "x/" : Move to the child folder named x (This folder is guaranteed to 
/// always exist).
/// You are given a list of strings logs where logs[i] is the operation 
/// performed by the user at the ith step.
///
/// The file system starts in the main folder, then the operations in 
/// logs are performed.
///
/// Return the minimum number of operations needed to go back to the main 
/// folder after the change folder operations.
///
/// Example 1:
/// Input: logs = ["d1/","d2/","../","d21/","./"]
/// Output: 2
/// Explanation: Use this change folder operation "../" 2 times and go 
/// back to the main folder.
///
/// Example 2:
/// Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
/// Output: 3
///
/// Example 3:
/// Input: logs = ["d1/","../","../","../"]
/// Output: 0
///
/// Constraints:
/// 1. 1 <= logs.length <= 103
/// 2. 2 <= logs[i].length <= 10
/// 3. logs[i] contains lowercase English letters, digits, '.', and '/'.
/// 4. logs[i] follows the format described in the statement.
/// 5. Folder names consist of lowercase English letters and digits.
/// </summary>
int LeetCodeString::minOperations(vector<string>& logs)
{
    int result = 0;
    for (size_t i = 0; i < logs.size(); i++)
    {
        if (logs[i] == "./") continue;
        else if (logs[i] == "../")
        {
            if (result > 0) result--;
        }
        else
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1614. Maximum Nesting Depth of the Parentheses
/// 
/// Easy
///
/// A string is a valid parentheses string (denoted VPS) if it meets one 
/// of the following:
///
/// It is an empty string "", or a single character not equal 
/// to "(" or ")",
/// It can be written as AB (A concatenated with B), where A and B are 
/// VPS's, or
/// It can be written as (A), where A is a VPS.
/// We can similarly define the nesting depth depth(S) of any VPS S as 
/// follows:
///
/// depth("") = 0
/// depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
/// depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
/// For example, "", "()()", and "()(()())" are VPS's (with nesting 
/// depths 0, 1, and 2), and ")(" and "(()" are not VPS's.
///
/// Given a VPS represented as string s, return the nesting depth of s.
/// 
/// Example 1:
/// Input: s = "(1+(2*3)+((8)/4))+1"
/// Output: 3
/// Explanation: Digit 8 is inside of 3 nested parentheses in the string.
///
/// Example 2:
/// Input: s = "(1)+((2))+(((3)))"
/// Output: 3
///
/// Example 3:
/// Input: s = "1+(2*3)/(2-1)"
/// Output: 1
///
/// Example 4:
/// Input: s = "1"
/// Output: 0
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s consists of digits 0-9 and characters '+', '-', '*', '/', 
///    '(', and ')'.
/// 3. It is guaranteed that parentheses expression s is a VPS.
/// </summary>
int LeetCodeString::maxDepth(string s)
{
    int result = 0;
    int depth = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') depth++;
        if (s[i] == ')') depth--;
        result = max(result, depth);
    }
    return result;
}

/// <summary>
/// Leet code #1616. Split Two Strings to Make Palindrome
/// 
/// Medium
///
/// You are given two strings a and b of the same length. Choose an index 
/// and split both strings at the same index, splitting a into two 
/// strings: aprefix and asuffix where a = aprefix + asuffix, and 
/// splitting b into two strings: bprefix and bsuffix where 
/// b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix 
/// forms a palindrome.
///
/// When you split a string s into sprefix and ssuffix, either ssuffix or 
/// sprefix is allowed to be empty. For example, if s = "abc", then "" + 
/// "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.
///
/// Return true if it is possible to form a palindrome string, otherwise 
/// return false.
/// 
/// Notice that x + y denotes the concatenation of strings x and y.
///
/// Example 1:
/// Input: a = "x", b = "y"
/// Output: true
/// Explaination: If either a or b are palindromes the answer is true 
/// since you can split in the following way:
/// aprefix = "", asuffix = "x"
/// bprefix = "", bsuffix = "y"
/// Then, aprefix + bsuffix = "" + "y" = "y", which is a palindrome.
///
/// Example 2:
/// Input: a = "abdef", b = "fecab"
/// Output: true
///
/// Example 3:
/// Input: a = "ulacfd", b = "jizalu"
/// Output: true
/// Explaination: Split them at index 3:
/// aprefix = "ula", asuffix = "cfd"
/// bprefix = "jiz", bsuffix = "alu"
/// Then, aprefix + bsuffix = "ula" + "alu" = "ulaalu", which is a palindrome.
///
/// Example 4:
/// Input: a = "xbdef", b = "xecab"
/// Output: false
///
/// Constraints:
/// 1. 1 <= a.length, b.length <= 105
/// 2. a.length == b.length
/// 3. a and b consist of lowercase English letters
/// </summary>
bool LeetCodeString::checkPalindromeFormation(string a, string b)
{
    int index = 0;
    int last = a.size() - 1;
    while (index < (int)a.size())
    {
        if (a[index] != b[last - index])
        {
            break;
        }
        index++;
    }
    if (index * 2 >= last + 1) return true;
    string str_a = a.substr(index, a.size() - 2 * index);
    string str_b = b.substr(index, b.size() - 2 * index);
    if (isPalindrome(str_a) || isPalindrome(str_b))
    {
        return true;
    }

    index = 0;
    last = a.size() - 1;
    while (index < (int)a.size())
    {
        if (b[index] != a[last - index])
        {
            break;
        }
        index++;
    }
    if (index * 2 >= last + 1) return true;
    str_a = a.substr(index, a.size() - 2 * index);
    str_b = b.substr(index, b.size() - 2 * index);
    if (isPalindrome(str_a) || isPalindrome(str_b))
    {
        return true;
    }
    return false;
}

/// <summary>
/// Leet code #1618. Maximum Font to Fit a Sentence in a Screen
/// 
/// Medium
///
/// You are given a string text. We want to display text on a screen of 
/// width w and height h. You can choose any font size from array fonts, 
/// which contains the available font sizes in ascending order.
///
/// You can use the FontInfo interface to get the width and height of any 
/// character at any available font size. 
///
/// The FontInfo interface is defined as such:
///
/// interface FontInfo {
///   // Returns the width of character ch on the screen using font size 
///   //fontSize.
///   // O(1) per call
/// public int getWidth(int fontSize, char ch);
/// 
///   // Returns the height of any character on the screen using font size 
///   // fontSize.
///   // O(1) per call
///   public int getHeight(int fontSize);
/// }
/// The calculated width of text for some fontSize is the sum of every 
/// getWidth(fontSize, text[i]) call for each 0 <= i < text.length 
/// (0-indexed). The calculated height of text for some fontSize is 
/// getHeight(fontSize). Note that text is displayed on a single line.
///
/// It is guaranteed that FontInfo will return the same value if you call 
/// getHeight or getWidth with the same parameters.
///
/// It is also guaranteed that for any font size fontSize and any 
/// character ch:
///
/// getHeight(fontSize) <= getHeight(fontSize+1)
/// getWidth(fontSize, ch) <= getWidth(fontSize+1, ch)
/// Return the maximum font size you can use to display text on the 
/// screen. If text cannot fit on the display with any font size, 
/// return -1.
///
///
/// Example 1:
/// Input: text = "helloworld", w = 80, h = 20, 
///        fonts = [6,8,10,12,14,16,18,24,36]
/// Output: 6
///
/// Example 2:
/// Input: text = "leetcode", w = 1000, h = 50, fonts = [1,2,4]
/// Output: 4
///
/// Example 3:
/// Input: text = "easyquestion", w = 100, h = 100, 
/// fonts = [10,15,20,25]
/// Output: -1
/// Constraints:
/// 1. 1 <= text.length <= 50000
/// 2. text contains only lowercase English letters.
/// 3. 1 <= w <= 10^7
/// 4. 1 <= h <= 10^4
/// 5. 1 <= fonts.length <= 10^5
/// 6. 1 <= fonts[i] <= 10^5
/// 7. fonts is sorted in ascending order and does not contain duplicates.
/// </summary>
int LeetCodeString::maxFont(string text, int w, int h, vector<int>& fonts)
{
    int first = 0; 
    int last = fonts.size() - 1;
    int result = -1;
    while (first <= last)
    {
        int middle = (first + last) / 2;
        int width = 0;
        int height = 0;
        for (size_t i = 0; i < text.size(); i++)
        {
            width += fonts[middle];
            height = max(height, fonts[middle]);
            if (width > w || height > h) break;
        }
        if (width > w || height > h)
        {
            last = middle - 1;
        }
        else
        {
            result = middle;
            first = middle + 1;
        }
    }
    if (result == -1) return -1;
    else return fonts[result];
}

/// <summary>
/// Leet code #1624. Largest Substring Between Two Equal Characters
/// 
/// Easy
///
/// Given a string s, return the length of the longest substring between 
/// two equal characters, excluding the two characters. If there is no 
/// such substring return -1.
///
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: s = "aa"
/// Output: 0
/// Explanation: The optimal substring here is an empty substring 
/// between the two 'a's.
///
/// Example 2:
/// Input: s = "abca"
/// Output: 2
/// Explanation: The optimal substring here is "bc".
///
/// Example 3:
/// Input: s = "cbzxy"
/// Output: -1
/// Explanation: There are no characters that appear twice in s.
///
/// Example 4:
/// Input: s = "cabbac"
/// Output: 4
/// Explanation: The optimal substring here is "abba". Other non-optimal 
/// substrings include "bb" and "".
///
/// Constraints:
/// 1. 1 <= s.length <= 300
/// 2. s contains only lowercase English letters.
/// </summary>
int LeetCodeString::maxLengthBetweenEqualCharacters(string s)
{
    vector<int> pos(26, -1);
    int result = -1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (pos[s[i] - 'a'] == -1) pos[s[i] - 'a'] = i;
        else result = max(result, i - pos[s[i] - 'a'] - 1);
    }
    return result;
}

/// <summary>
/// Leet code #1625. Lexicographically Smallest String After Applying 
///                  Operations
/// 
/// Medium
///
/// You are given a string s of even length consisting of digits from 
/// 0 to 9, and two integers a and b.
///
/// You can apply either of the following two operations any number 
/// of times and in any order on s:
///
/// Add a to all odd indices of s (0-indexed). Digits post 9 are cycled 
/// back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
/// Rotate s to the right by b positions. For example, if s = "3456" 
/// and b = 1, s becomes "6345".
/// Return the lexicographically smallest string you can obtain by 
/// applying the above operations any number of times on s.
///
/// A string a is lexicographically smaller than a string b (of the same 
/// length) if in the first position where a and b differ, string a has a 
/// letter that appears earlier in the alphabet than the corresponding 
/// letter in b. For example, "0158" is lexicographically smaller than 
/// "0190" because the first position they differ is at the third letter, 
/// and '5' comes before '9'.
/// 
/// Example 1:
/// Input: s = "5525", a = 9, b = 2
/// Output: "2050"
/// Explanation: We can apply the following operations:
/// Start:  "5525"
/// Rotate: "2555"
/// Add:    "2454"
/// Add:    "2353"
/// Rotate: "5323"
/// Add:    "5222"
/// Add:    "5121"
/// Rotate: "2151"
/// Add:    "2050"
/// There is no way to obtain a string that is lexicographically smaller
/// then "2050".
///
/// Example 2:
/// Input: s = "74", a = 5, b = 1
/// Output: "24"
/// Explanation: We can apply the following operations:
/// Start:  "74"
/// Rotate: "47"
/// Add:    "42"
/// Rotate: "24"
/// There is no way to obtain a string that is lexicographically smaller
/// then "24".
///
/// Example 3:
/// Input: s = "0011", a = 4, b = 2
/// Output: "0011"
/// Explanation: There are no sequence of operations that will give us a 
/// lexicographically smaller string than "0011".
///
/// Example 4:
/// Input: s = "43987654", a = 7, b = 3
/// Output: "00553311"
/// 
/// Constraints:
/// 1. 2 <= s.length <= 100
/// 2. s.length is even.
/// 3. s consists of digits from 0 to 9 only.
/// 4. 1 <= a <= 9
/// 5. 1 <= b <= s.length - 1
/// </summary>
string LeetCodeString::findLexSmallestString(string s, int a, int b)
{
    string result = s;
    set<string> visited;
    std::queue<string> queue;
    visited.insert(s);
    queue.push(s);
    while (!queue.empty())
    {
        string str = queue.front();
        queue.pop();
        string str_a = str;
        for (size_t i = 1; i < str_a.size(); i += 2)
        {
            str_a[i] ='0' + (str_a[i] - '0' + a) % 10;
        }
        if (visited.count(str_a) == 0)
        {
            result = min(result, str_a);
            visited.insert(str_a);
            queue.push(str_a);
        }
        str_a = str.substr(s.size() - b) + str.substr(0, s.size() - b);
        if (visited.count(str_a) == 0)
        {
            result = min(result, str_a);
            visited.insert(str_a);
            queue.push(str_a);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1638. Count Substrings That Differ by One Character
/// 
/// Medium
///
/// Given two strings s and t, find the number of ways you can choose a 
/// non-empty substring of s and replace a single character by a different 
/// character such that the resulting substring is a substring of t. In 
/// other words, find the number of substrings in s that differ from some 
/// substring in t by exactly one character.
///
/// For example, the underlined substrings in "computer" and "computation" 
/// only differ by the 'e'/'a', so this is a valid way.
///
/// Return the number of substrings that satisfy the condition above.
///
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: s = "aba", t = "baba"
/// Output: 6
/// Explanation: The following are the pairs of substrings from s and t that 
/// differ by exactly 1 character:
/// ("aba", "baba")
/// ("aba", "baba")
/// ("aba", "baba")
/// ("aba", "baba")
/// ("aba", "baba")
/// ("aba", "baba")
/// The underlined portions are the substrings that are chosen from s and t.
///
/// Example 2:
/// Input: s = "ab", t = "bb"
/// Output: 3
/// Explanation: The following are the pairs of substrings from s and t that 
/// differ by 1 character:
/// ("ab", "bb")
/// ("ab", "bb")
/// ("ab", "bb")
/// The underlined portions are the substrings that are chosen from s and t.
///
/// Example 3:
/// Input: s = "a", t = "a"
/// Output: 0
///
/// Example 4:
/// Input: s = "abe", t = "bbc"
/// Output: 10
/// Constraints:
/// 1. 1 <= s.length, t.length <= 100
/// 2. s and t consist of lowercase English letters only.
/// </summary>
int LeetCodeString::countSubstrings(string s, string t)
{
    int result = 0;
    // for string starting from any position in s vs t
    for (int i = 0; i < (int)s.size(); i++)
    {
        int prev = -1;
        int prev_count = 0;
        for (int j = 0; i + j < (int)s.size() && j < (int)t.size(); j++)
        {
            // count strings same before but diff now
            if (s[i + j] != t[j])
            {
                prev_count = j - prev;;
                prev = j;
            }
            // if current is same also count prev_count
            result += prev_count;
        }
    }
    // for string starting from any position in t vs s[1]
    for (int i = 1; i < (int)t.size(); i++)
    {
        int prev = -1;
        int prev_count = 0;
        for (int j = 0; i + j < (int)t.size() && j < (int)s.size(); j++)
        {
            // count strings same before but diff now
            if (t[i + j] != s[j])
            {
                prev_count = j - prev;;
                prev = j;
            }
            // if current is same also count prev_count
            result += prev_count;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1647. Minimum Deletions to Make Character Frequencies Unique
/// 
/// Medium
///
/// A string s is called good if there are no two different characters in s 
/// that have the same frequency.
///
/// Given a string s, return the minimum number of characters you need to 
/// delete to make s good.
///
/// The frequency of a character in a string is the number of times it 
/// appears in the string. For example, in the string "aab", the frequency 
/// of 'a' is 2, while the frequency of 'b' is 1.
///
/// Example 1:
/// Input: s = "aab"
/// Output: 0
/// Explanation: s is already good.
///
/// Example 2:
/// Input: s = "aaabbbcc"
/// Output: 2
/// Explanation: You can delete two 'b's resulting in the good string 
/// "aaabcc".
/// Another way it to delete one 'b' and one 'c' resulting in the good 
/// string "aaabbc".
///
/// Example 3:
/// Input: s = "ceabaacb"
/// Output: 2
/// Explanation: You can delete both 'c's resulting in the good 
/// string "eabaab".
/// Note that we only care about characters that are still in the string 
/// at the end (i.e. frequency of 0 is ignored).
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s contains only lowercase English letters.
/// </summary>
int LeetCodeString::minDeletions(string s)
{
    vector<int> char_count(26);
    unordered_map<int, int> frequency;
    for (size_t i = 0; i < s.size(); i++)
    {
        char_count[s[i] - 'a']++;
    }
    for (size_t i = 0; i < 26; i++)
    {
        frequency[char_count[i]]++;
    }
    int result = 0;
    for (size_t i = 0; i < 26; i++)
    {
        int count = char_count[i];
        if (count == 0) continue;
        if (frequency[count] > 1)
        {
            frequency[count]--;
            while (count > 0)
            {
                count--;
                result++;
                if (frequency.count(count) == 0)
                {
                    frequency[count] = 1;
                    break;
                }
            }
        }
    }
    return result;
}


/// <summary>
/// Leet code #1657. Determine if Two Strings Are Close
/// 
/// Medium
///
/// Two strings are considered close if you can attain one from the other 
/// using the following operations:
///
/// Operation 1: Swap any two existing characters.
/// For example, abcde -> aecdb
/// Operation 2: Transform every occurrence of one existing character into 
/// another existing character, and do the same with the other character.
/// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn 
/// into a's)
/// You can use the operations on either string as many times as necessary.
///
/// Given two strings, word1 and word2, return true if word1 and word2 are 
/// close, and false otherwise.
///
/// Example 1:
/// Input: word1 = "abc", word2 = "bca"
/// Output: true
/// Explanation: You can attain word2 from word1 in 2 operations.
/// Apply Operation 1: "abc" -> "acb"
/// Apply Operation 1: "acb" -> "bca"
///
/// Example 2:
/// Input: word1 = "a", word2 = "aa"
/// Output: false
/// Explanation: It is impossible to attain word2 from word1, or vice 
/// versa, in any number of operations.
///
/// Example 3:
/// Input: word1 = "cabbba", word2 = "abbccc"
/// Output: true
/// Explanation: You can attain word2 from word1 in 3 operations.
/// Apply Operation 1: "cabbba" -> "caabbb"
/// Apply Operation 2: "caabbb" -> "baaccc"
/// Apply Operation 2: "baaccc" -> "abbccc"
///
/// Example 4:
/// Input: word1 = "cabbba", word2 = "aabbss"
/// Output: false
/// Explanation: It is impossible to attain word2 from word1, or vice versa, 
/// in any amount of operations.
///
/// Constraints:
/// 1. 1 <= word1.length, word2.length <= 10^5
/// 2. word1 and word2 contain only lowercase English letters.
/// </summary>
bool LeetCodeString::closeStrings(string word1, string word2)
{
    if (word1.size() != word2.size()) return false;

    vector<int> count1(26), count2(26);
    for (size_t i = 0; i < word1.size(); i++)
    {
        count1[word1[i] - 'a']++;
        count2[word2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] == 0 && count2[i] != 0) return false;
        if (count1[i] != 0 && count2[i] == 0) return false;
    }

    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i]) return false;
    }
    return true;
}


/// <summary>
/// Leet code #1668. Maximum Repeating Substring
/// 
/// Easy
/// 
/// For a string sequence, a string word is k-repeating if word concatenated k 
/// times is a substring of sequence. The word's maximum k-repeating value is 
/// the highest value k where word is k-repeating in sequence. If word is not 
/// a substring of sequence, word's maximum k-repeating value is 0.
///
/// Given strings sequence and word, return the maximum k-repeating value of 
/// word in sequence.
///
/// Example 1:
/// Input: sequence = "ababc", word = "ab"
///
/// Output: 2
/// Explanation: "abab" is a substring in "ababc".
///
/// Example 2:
/// Input: sequence = "ababc", word = "ba"
/// Output: 1
/// Explanation: "ba" is a substring in "ababc". "baba" is not a 
/// substring in "ababc".
///
/// Example 3:
/// Input: sequence = "ababc", word = "ac"
/// Output: 0
/// Explanation: "ac" is not a substring in "ababc". 
///
/// Constraints:
/// 1. 1 <= sequence.length <= 100
/// 2. 1 <= word.length <= 100
/// 3. sequence and word contains only lowercase English letters.
/// </summary>
int LeetCodeString::maxRepeating(string sequence, string word)
{
    int result = 0;
    int count = 0;
    size_t index = 0;
    while (index < sequence.size())
    {
        size_t pos = sequence.find(word, index);
        if (pos == string::npos) break;
        if (pos == index) count++;
        else count = 1;
        index = pos + word.size();
        result = max(result, count);
    }
    return result;
}

/// <summary>
/// Leet code #1678. Goal Parser Interpretation
/// 
/// Easy
/// 
/// You own a Goal Parser that can interpret a string command. The command 
/// consists of an alphabet of "G", "()" and/or "(al)" in some order. The 
/// Goal Parser will interpret "G" as the string "G", "()" as the string "o", 
/// and "(al)" as the string "al". The interpreted strings are then 
/// concatenated in the original order.
///
/// Given the string command, return the Goal Parser's interpretation of 
/// command.
/// 
/// Example 1:
/// Input: command = "G()(al)"
/// Output: "Goal"
/// Explanation: The Goal Parser interprets the command as follows:
/// G -> G
/// () -> o
/// (al) -> al
/// The final concatenated result is "Goal".
///
/// Example 2:
/// Input: command = "G()()()()(al)"
/// Output: "Gooooal"
/// Example 3:
/// 
/// Input: command = "(al)G(al)()()G"
/// Output: "alGalooG"
///  
/// Constraints:
/// 1. 1 <= command.length <= 100
/// 2. command consists of "G", "()", and/or "(al)" in some order.
string LeetCodeString::interpret(string command)
{
    string result;
    size_t index = 0;
    while (index < command.size())
    {
        if (command[index] == 'G')
        {
            result.push_back('G');
            index++;
        }
        else if (command[index] == '(' && command[index + 1] == ')')
        {
            result.push_back('o');
            index += 2;
        }
        else if (command[index] == '(' && command[index + 1] == 'a')
        {
            result.append("al");
            index += 4;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1684. Count the Number of Consistent Strings
/// 
/// Easy
/// 
/// You are given a string allowed consisting of distinct characters and 
/// an array of strings words. A string is consistent if all characters 
/// in the string appear in the string allowed.
///
/// Return the number of consistent strings in the array words.
/// 
/// Example 1:
/// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
/// Output: 2
/// Explanation: Strings "aaab" and "baa" are consistent since they only 
/// contain characters 'a' and 'b'.
///
/// Example 2:
/// Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
/// Output: 7
/// Explanation: All strings are consistent.
///
/// Example 3:
/// Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
/// Output: 4
/// Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
/// 
/// Constraints:
/// 1. 1 <= words.length <= 104
/// 2. 1 <= allowed.length <= 26
/// 3. 1 <= words[i].length <= 10
/// 4. The characters in allowed are distinct.
/// 5. words[i] and allowed contain only lowercase English letters.
/// </summary>
int LeetCodeString::countConsistentStrings(string allowed, vector<string>& words)
{
    vector<int> allow(26);
    for (size_t i = 0; i < allowed.size(); i++)
    {
        allow[allowed[i] - 'a'] = 1;
    }
    int result = 0;
    for (size_t i = 0; i < words.size(); i++)
    {
        int consistent = 1;
        for (size_t j = 0; j < words[i].size(); j++)
        {
            if (allow[words[i][j] - 'a'] == 0)
            {
                consistent = 0;
                break;
            }
        }
        result = result + consistent;
    }
    return result;
}

/// <summary>
/// Leet code #1694. Reformat Phone Number
/// 
/// Easy
/// 
/// You are given a phone number as a string number. number consists of 
/// digits, spaces ' ', and/or dashes '-'.
///
/// You would like to reformat the phone number in a certain manner. 
/// Firstly, remove all spaces and dashes. Then, group the digits from 
/// left to right into blocks of length 3 until there are 4 or fewer 
/// digits. The final digits are then grouped as follows:
///
/// 2 digits: A single block of length 2.
/// 3 digits: A single block of length 3.
/// 4 digits: Two blocks of length 2 each.
/// The blocks are then joined by dashes. Notice that the reformatting 
/// process should never produce any blocks of length 1 and produce at 
/// most two blocks of length 2.
///
/// Return the phone number after formatting.
///
/// Example 1:
/// Input: number = "1-23-45 6"
/// Output: "123-456"
/// Explanation: The digits are "123456".
/// Step 1: There are more than 4 digits, so group the next 3 digits. 
/// The 1st block is "123".
/// Step 2: There are 3 digits remaining, so put them in a single block 
/// of length 3. The 2nd block is "456".
/// Joining the blocks gives "123-456".
///
/// Example 2:
/// Input: number = "123 4-567"
/// Output: "123-45-67"
/// Explanation: The digits are "1234567".
/// Step 1: There are more than 4 digits, so group the next 3 digits. 
/// The 1st block is "123".
/// Step 2: There are 4 digits left, so split them into two blocks of 
/// length 2. The blocks are "45" and "67".
/// Joining the blocks gives "123-45-67".
///
/// Example 3:
/// Input: number = "123 4-5678"
/// Output: "123-456-78"
/// Explanation: The digits are "12345678".
/// Step 1: The 1st block is "123".
/// Step 2: The 2nd block is "456".
/// Step 3: There are 2 digits left, so put them in a single block of 
/// length 2. The 3rd block is "78".
/// Joining the blocks gives "123-456-78".
///
/// Example 4:
/// Input: number = "12"
/// Output: "12"
///
/// Example 5:
/// Input: number = "--17-5 229 35-39475 "
/// Output: "175-229-353-94-75"
/// 
/// Constraints:
/// 1. 2 <= number.length <= 100
/// 2. number consists of digits and the characters '-' and ' '.
/// </summary>
string LeetCodeString::reformatNumber(string number)
{
    string phone;
    for (size_t i = 0; i < number.size(); i++)
    {
        if (isdigit(number[i])) phone.push_back(number[i]);
    }
    string result;
    while (!phone.empty())
    {
        if (phone.size() > 4)
        {
            result.append(phone.substr(0, 3));
            result.push_back('-');
            phone = phone.substr(3);
        }
        else if (phone.size() == 4)
        {
            result.append(phone.substr(0, 2));
            result.push_back('-');
            result.append(phone.substr(2));
            phone.clear();
        }
        else
        {
            result.append(phone);
            phone.clear();
        }
    }
    return result;
}

/// <summary>
/// Leet code #1698. Number of Distinct Substrings in a String
/// 
/// Hard
/// 
/// Given a string s, return the number of distinct substrings of s.
///
/// A substring of a string is obtained by deleting any number of 
/// characters (possibly zero) from the front of the string and any 
/// number (possibly zero) from the back of the string.
/// 
/// Example 1:
/// Input: s = "aabbaba"
/// Output: 21
/// Explanation: The set of distinct strings is
/// ["a","b","aa","bb","ab","ba","aab","abb","bba","aba","aabb","abba",
/// "bbab","baba","aabba","abbab","bbaba","aabbab","abbaba","aabbaba"]
///
/// Example 2:
/// Input: s = "abcdefg"
/// Output: 28
/// 
/// Constraints:
/// 1. 1 <= s.length <= 500
/// 2. s consists of lowercase English letters.
/// </summary>
int LeetCodeString::countDistinct(string s)
{
    int n = s.size();
    vector<int> dp(n);
    for (int k = 1; k < n; k++)
    {
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            if (i + k >= n) break;
            if (s[i] == s[i + k]) len++;
            else len = 0;
            dp[i + k] = max(dp[i + k], len);
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += i + 1 - dp[i];
    }
    return result;
}

/// <summary>
/// Leet code #1702. Maximum Binary String After Change
/// 
/// Medium
/// 
/// You are given a binary string binary consisting of only 0's or 1's. 
/// You can apply each of the following operations any number of times:
///
/// Operation 1: If the number contains the substring "00", you can 
/// replace it with "10".
/// For example, "00010" -> "10010"
/// Operation 2: If the number contains the substring "10", you can 
/// replace it with "01".
/// For example, "00010" -> "00001"
/// Return the maximum binary string you can obtain after any number 
/// of operations. Binary string x is greater than binary string y if 
/// x's decimal representation is greater than y's decimal 
/// representation.
/// 
/// Example 1:
/// Input: binary = "000110"
/// Output: "111011"
/// Explanation: A valid transformation sequence can be:
/// "000110" -> "000101" 
/// "000101" -> "100101" 
/// "100101" -> "110101" 
/// "110101" -> "110011" 
/// "110011" -> "111011"
///
/// Example 2:
/// Input: binary = "01"
/// Output: "01"
/// Explanation: "01" cannot be transformed any further.
///
/// Constraints:
/// 1. 1 <= binary.length <= 10^5
/// 2. binary consist of '0' and '1'.
/// </summary>
string LeetCodeString::maximumBinaryString(string binary)
{
    int n = binary.size();
    string result = binary;
    int next = 0;
    for (int i = 0; i < n-1; i++)
    {
        // skip all '1'
        if (result[i] == '1') continue;
        // keep on filling "00"
        if (result[i] == '0' && result[i + 1] == '0')
        {
            result[i] = '1';
            continue;
        }
        if (next <= i) next = i + 1;
        while (next < n && result[next] == '1') next++;
        // no more zero for swap
        if (next >= n) break;
        
        swap(result[i + 1], result[next]);
        result[i] = '1';
    }
    return result;
}

/// <summary>
/// Leet code #1704. Determine if String Halves Are Alike
/// 
/// Easy
/// 
/// You are given a string s of even length. Split this string into two 
/// halves of equal lengths, and let a be the first half and b be the 
/// second half.
///
/// Two strings are alike if they have the same number of vowels 
/// ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s 
/// contains uppercase and lowercase letters.
///
/// Return true if a and b are alike. Otherwise, return false.
/// 
/// Example 1:
/// Input: s = "book"
/// Output: true
/// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. 
/// Therefore, they are alike.
///
/// Example 2:
/// Input: s = "textbook"
/// Output: false
/// Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. 
/// Therefore, they are not alike.
/// Notice that the vowel o is counted twice.
///
/// Example 3:
/// Input: s = "MerryChristmas"
/// Output: false
///
/// Example 4:
/// Input: s = "AbCdEfGh"
/// Output: true
///
/// Constraints:
/// 1. 2 <= s.length <= 1000
/// 2. s.length is even.
/// 3. s consists of uppercase and lowercase letters.
/// </summary>
bool LeetCodeString::halvesAreAlike(string s)
{
    unordered_set<char> vowels =
    {
        'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
    };
    int result = 0;
    for (size_t i = 0; i < s.size() / 2; i++)
    {
        if (vowels.count(s[i]) > 0) result++;
    }
    for (size_t i = s.size() / 2; i < s.size(); i++)
    {
        if (vowels.count(s[i]) > 0) result--;
    }
    return (result == 0);
}

/// <summary>
/// Leet code #1717. Maximum Score From Removing Substrings
/// 
/// Medium
/// 
/// You are given a string s and two integers x and y. You can perform 
/// two types of operations any number of times.
///
/// Remove substring "ab" and gain x points.
/// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
/// Remove substring "ba" and gain y points.
/// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
/// Return the maximum points you can gain after applying the above 
/// operations on s.
/// 
/// Example 1:
/// Input: s = "cdbcbbaaabab", x = 4, y = 5
/// Output: 19
/// Explanation:
/// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" 
/// and 5 points are added to the score.
/// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" 
/// and 4 points are added to the score.
/// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" 
/// and 5 points are added to the score.
/// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 
/// points are added to the score.
/// Total score = 5 + 4 + 5 + 5 = 19.
///
/// Example 2:
/// Input: s = "aabbaaxybbaabb", x = 5, y = 4
/// Output: 20
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. 1 <= x, y <= 10^4
/// 3. s consists of lowercase English letters.
/// </summary>
int LeetCodeString::maximumGain(string s, int x, int y)
{
    int result = 0;
    string str;
    for (size_t i = 0; i <= s.size(); i++)
    {
        if (i == s.size() || s[i] > 'b')
        {
            int first = 0;
            int last = (int)str.size() - 1;
            while (first < last)
            {
                if (str[first] == 'a' && str[last] == 'b')
                {
                    result += x;
                }
                else if (str[first] == 'b' && str[last] == 'a')
                {
                    result += y;
                }
                first++;
                last--;
            }
            str.clear();
        }
        else if (str.empty())
        {
            str.push_back(s[i]);
        }
        else if (x >= y && str.back() == 'a' && s[i] == 'b')
        {
            str.pop_back();
            result += x;
        }
        else if (x <= y && str.back() == 'b' && s[i] == 'a')
        {
            str.pop_back();
            result += y;
        }
        else
        {
            str.push_back(s[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code 1736. Latest Time by Replacing Hidden Digits
/// 
/// Easy
/// 
/// You are given a string time in the form of hh:mm, where some of 
/// the digits in the string are hidden (represented by ?).
///
/// The valid times are those inclusively between 00:00 and 23:59.
///
/// Return the latest valid time you can get from time by replacing 
/// the hidden digits.
///
/// Example 1:
///
/// Input: time = "2?:?0"
/// Output: "23:50"
/// Explanation: The latest hour beginning with the digit '2' is 23 
/// and the latest minute ending with the digit '0' is 50.
///
/// Example 2:
/// Input: time = "0?:3?"
/// Output: "09:39"
///
/// Example 3:
/// Input: time = "1?:22"
/// Output: "19:22"
///
/// Constraints:
/// 1. time is in the format hh:mm.
/// 2. It is guaranteed that you can produce a valid time from the given 
///    string.
/// </summary>
string LeetCodeString::maximumTime(string time)
{
    string result = time;
    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] != '?') continue;
        if (i == 0)
        {
            if (result[1] >= '4' && result[1] <= '9') result[i] = '1';
            else result[i] = '2';
        }
        else if (i == 1)
        {
            if (result[0] == '2') result[i] = '3';
            else result[i] = '9';
        }
        else if (i == 2) result[i] = ':';
        else if (i == 3) result[i] = '5';
        else result[i] = '9';
    }
    return result;
}

/// <summary>
/// Leet code 1737. Change Minimum Characters to Satisfy One of 
///                 Three Conditions
/// 
/// Medium
/// 
/// You are given two strings a and b that consist of lowercase letters. 
/// In one operation, you can change any character in a or b to any 
/// lowercase letter.
///
/// Your goal is to satisfy one of the following three conditions:
///
/// Every letter in a is strictly less than every letter in b in the 
/// alphabet.
/// Every letter in b is strictly less than every letter in a in the 
/// alphabet.
/// Both a and b consist of only one distinct letter.
/// Return the minimum number of operations needed to achieve your goal.
///
/// Example 1:
/// Input: a = "aba", b = "caa"
/// Output: 2
/// Explanation: Consider the best way to make each condition true:
/// 1) Change b to "ccc" in 2 operations, then every letter in a is less 
///    than every letter in b.
/// 2) Change a to "bbb" and b to "aaa" in 3 operations, then every 
///    letter in b is less than every letter in a.
/// 3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b 
///    consist of one distinct letter.
/// The best way was done in 2 operations (either condition 1 or 
/// condition 3).
///
/// Example 2:
/// Input: a = "dabadd", b = "cda"
/// Output: 3
/// Explanation: The best way is to make condition 1 true by changing b 
/// to "eee".
/// Constraints:
/// 1. 1 <= a.length, b.length <= 10^5
/// 2. a and b consist only of lowercase letters.You are given a 2D 
///    integer array, queries. For each queries[i], 
/// </summary>
int LeetCodeString::minCharacters(string a, string b)
{
    vector<int> char1(26), char2(26);

    for (char ch : a) char1[ch - 'a']++;
    for (char ch : b) char2[ch - 'a']++;

    int result = INT_MAX;
    int pre_sum1 = 0;
    int pre_sum2 = 0;
    // try to move either str1 or str2 left or right to 'a' - 'y'
    for (int i = 0; i < 25; i++)
    {
        pre_sum1 += char1[i];
        pre_sum2 += char2[i];
        int count1 = (int)a.size() - char1[i] + (int)b.size() - char2[i];
        int count2 = a.size() - pre_sum1 + pre_sum2;
        int count3 = b.size() - pre_sum2 + pre_sum1;
        result = min(result, min(min(count1, count2), count3));
    }
    result = min(result, (int)a.size() - char1[25] + (int)b.size() - char2[25]);
    return result;
}

/// <summary>
/// Leet code 1754. Largest Merge Of Two Strings
/// 
/// Medium
/// 
/// You are given two strings word1 and word2. You want to construct a 
/// string merge in the following way: while either word1 or word2 are 
/// non-empty, choose one of the following options:
///
/// If word1 is non-empty, append the first character in word1 to merge 
/// and delete it from word1.
/// For example, if word1 = "abc" and merge = "dv", then after choosing 
/// this operation, word1 = "bc" and merge = "dva".
/// If word2 is non-empty, append the first character in word2 to merge 
/// and delete it from word2.
/// For example, if word2 = "abc" and merge = "", then after choosing 
/// this operation, word2 = "bc" and merge = "a".
/// Return the lexicographically largest merge you can construct.
///
/// A string a is lexicographically larger than a string b (of the same 
/// length) if in the first position where a and b differ, a has a 
/// character strictly larger than the corresponding character in b. For 
/// example, "abcd" is lexicographically larger than "abcc" because the 
/// first position they differ is at the fourth character, and d is 
/// greater than c.
/// 
/// Example 1:
/// Input: word1 = "cabaa", word2 = "bcaaa"
/// Output: "cbcabaaaaa"
/// Explanation: One way to get the lexicographically largest merge is:
/// - Take from word1: merge = "c", word1 = "abaa", word2 = "bcaaa"
/// - Take from word2: merge = "cb", word1 = "abaa", word2 = "caaa"
/// - Take from word2: merge = "cbc", word1 = "abaa", word2 = "aaa"
/// - Take from word1: merge = "cbca", word1 = "baa", word2 = "aaa"
/// - Take from word1: merge = "cbcab", word1 = "aa", word2 = "aaa"
/// - Append the remaining 5 a's from word1 and word2 at the end of merge.
///
/// Example 2:
/// Input: word1 = "abcabc", word2 = "abdcaba"
/// Output: "abdcabcabcaba"
/// 
/// Constraints:
/// 1. 1 <= word1.length, word2.length <= 3000
/// 2. word1 and word2 consist only of lowercase English letters.
/// </summary>
string LeetCodeString::largestMerge(string word1, string word2)
{
    string result;
    size_t i = 0;
    size_t j = 0;
    while (i < word1.size() || j < word2.size())
    {
        if (i == word1.size())
        {
            result.push_back(word2[j]);
            j++;
        }
        else if (j == word2.size())
        {
            result.push_back(word1[i]);
            i++;
        }
        else if (word1[i] > word2[j])
        {
            result.push_back(word1[i]);
            i++;
        }
        else if (word1[i] < word2[j])
        {
            result.push_back(word2[j]);
            j++;
        }
        else
        {
            size_t ii = i;
            size_t jj = j;
            while (ii < word1.size() && jj < word2.size() && word1[ii] == word2[jj])
            {
                ii++; jj++;
            }
            if (ii == word1.size() || (jj < word2.size() && word1[ii] < word2[jj]))
            {
                result.push_back(word2[j]);
                j++;
            }
            else
            {
                result.push_back(word1[i]);
                i++;
            }
        }
    }
    return result;
}


/// <summary>
/// Leet code 1768. Merge Strings Alternately
/// 
/// Easy
/// 
/// You are given two strings word1 and word2. Merge the strings by 
/// adding letters in alternating order, starting with word1. If a 
/// string is longer than the other, append the additional letters 
/// onto the end of the merged string.
///
/// Return the merged string.
/// 
/// Example 1:
/// Input: word1 = "abc", word2 = "pqr"
/// Output: "apbqcr"
/// Explanation: The merged string will be merged as so:
/// word1:  a   b   c
/// word2:    p   q   r
/// merged: a p b q c r
///
/// Example 2:
/// Input: word1 = "ab", word2 = "pqrs"
/// Output: "apbqrs"
/// Explanation: Notice that as word2 is longer, "rs" is appended to 
/// the end.
/// word1:  a   b 
/// word2:    p   q   r   s
/// merged: a p b q   r   s
///
/// Example 3:
/// Input: word1 = "abcd", word2 = "pq"
/// Output: "apbqcd"
/// Explanation: Notice that as word1 is longer, "cd" is appended to the 
/// end.
/// word1:  a   b   c   d
/// word2:    p   q 
/// merged: a p b q c   d
///
/// Constraints:
/// 1. 1 <= word1.length, word2.length <= 100
/// 2. word1 and word2 consist of lowercase English letters.
/// </summary>
string LeetCodeString::mergeAlternately(string word1, string word2)
{
    size_t i = 0;
    size_t j = 0;
    string result;
    while (i < word1.size() || j < word2.size())
    {
        if (i < word1.size())
        {
            result.push_back(word1[i]);
            i++;
        }
        if (j < word2.size())
        {
            result.push_back(word2[j]);
            j++;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1763. Longest Nice Substring
/// 
/// Easy
/// 
/// A string s is nice if, for every letter of the alphabet that s 
/// contains, it appears both in uppercase and lowercase. For example, 
/// "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. 
/// However, "abA" is not because 'b' appears, but 'B' does not.
///
/// Given a string s, return the longest substring of s that is nice. 
/// If there are multiple, return the substring of the earliest 
/// occurrence. If there are none, return an empty string.
/// 
/// Example 1:
/// Input: s = "YazaAay"
/// Output: "aAa"
/// Explanation: "aAa" is a nice string because 'A/a' is the only letter 
/// of the alphabet in s, and both 'A' and 'a' appear.
/// "aAa" is the longest nice substring.
///
/// Example 2:
/// Input: s = "Bb"
/// Output: "Bb"
/// Explanation: "Bb" is a nice string because both 'B' and 'b' appear. 
/// The whole string is a substring.
///
/// Example 3:
/// Input: s = "c"
/// Output: ""
/// Explanation: There are no nice substrings.
///
/// Example 4:
/// Input: s = "dDzeE"
/// Output: "dD"
/// Explanation: Both "dD" and "eE" are the longest nice substrings.
/// As there are multiple longest nice substrings, return "dD" since it occurs 
/// earlier.
///
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s consists of uppercase and lowercase English letters.
/// </summary>
string LeetCodeString::longestNiceSubstring(string s)
{
    if (s.empty()) return s;
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);
    for (size_t i = 0; i < s.size(); i++)
    {
        if (islower(s[i])) lower[s[i] - 'a'] = i + 1;
        if (isupper(s[i])) upper[s[i] - 'A'] = i + 1;
    }
    string result = s;
    for (int i = 0; i < 26; i++)
    {
        if (lower[i] == 0 && upper[i] == 0)
        {
            continue;
        }
        else if (lower[i] != 0 && upper[i] != 0)
        {
            continue;
        }
        else
        {
            int pos = lower[i] + upper[i];
            
            string str1 = longestNiceSubstring(s.substr(0, pos-1));
            string str2 = longestNiceSubstring(s.substr(pos));
            result = str1;
            if (str1.size() < str2.size())
            {
                result = str2;
            }
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1750. Minimum Length of String After Deleting Similar Ends
/// 
/// Medium
/// 
/// Given a string s consisting only of characters 'a', 'b', and 'c'. You 
/// are asked to apply the following algorithm on the string any number of 
/// times:
///
/// Pick a non-empty prefix from the string s where all the characters in 
/// the prefix are equal.
/// Pick a non-empty suffix from the string s where all the characters in 
/// this suffix are equal.
/// The prefix and the suffix should not intersect at any index.
/// The characters from the prefix and suffix must be the same.
/// Delete both the prefix and the suffix.
/// Return the minimum length of s after performing the above operation 
/// any number of times (possibly zero times).
///
/// Example 1:
/// Input: s = "ca"
/// Output: 2
/// Explanation: You can't remove any characters, so the string stays 
/// as is.
///
/// Example 2:
/// Input: s = "cabaabac"
/// Output: 0
/// Explanation: An optimal sequence of operations is:
/// - Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
/// - Take prefix = "a" and suffix = "a" and remove them, s = "baab".
/// - Take prefix = "b" and suffix = "b" and remove them, s = "aa".
/// - Take prefix = "a" and suffix = "a" and remove them, s = "".
///
/// Example 3:
/// Input: s = "aabccabba"
/// Output: 3
/// Explanation: An optimal sequence of operations is:
/// - Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
/// - Take prefix = "b" and suffix = "bb" and remove them, s = "cca".
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s only consists of characters 'a', 'b', and 'c'.
/// </summary>
int LeetCodeString::minimumLength(string s)
{
    int first = 0;
    int last = s.size() - 1;
    while (first < last)
    {
        if (s[first] != s[last]) break;
        int next = first + 1;
        while (next <= last && s[next] == s[first]) next++;
        first = next;
        int prev = last - 1;
        while (prev >= first && s[prev] == s[last]) prev--;
        last = prev;
    }
    if (last < first) return 0;
    else return last - first + 1;
}

/// <summary>
/// Leet code 1781. Sum of Beauty of All Substrings
/// 
/// Medium
/// 
/// The beauty of a string is the difference in frequencies between 
/// the most frequent and least frequent characters.
///
/// For example, the beauty of "abaacc" is 3 - 1 = 2.
/// Given a string s, return the sum of beauty of all of its substrings.
/// 
/// Example 1:
/// Input: s = "aabcb"
/// Output: 5
/// Explanation: The substrings with non-zero beauty are ["aab","aabc",
/// "aabcb","abcb","bcb"], each with beauty equal to 1.
///
/// Example 2:
/// Input: s = "aabcbaa"
/// Output: 17
///
/// Constraints:
/// 1. 1 <= s.length <= 500
/// 2. s consists of only lowercase English letters.
/// </summary>
int LeetCodeString::beautySum(string s)
{
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        vector<int> chars(26);
        map<int, int> freq;
        for (size_t j = i; j < s.size(); j++)
        {
            int index = s[j] - 'a';
            int prev = chars[index];
            chars[index]++;
            if (prev > 0)
            {
                freq[prev]--;
                if (freq[prev] == 0) freq.erase(prev);
            }
            freq[prev + 1]++;
            if (freq.size() < 2) continue;
            result += freq.rbegin()->first - freq.begin()->first;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1784. Check if Binary String Has at Most One Segment of Ones
/// 
/// Easy
/// 
/// Given a binary string s without leading zeros, return true if s 
/// contains at most one contiguous segment of ones. Otherwise, return 
/// false.
///
/// Example 1:
/// Input: s = "1001"
/// Output: false
/// Explanation: The ones do not form a contiguous segment.
///
/// Example 2:
/// Input: s = "110"
/// Output: true
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s[i] is either '0' or '1'.
/// 3. s[0] is '1'.
/// </summary>
bool LeetCodeString::checkOnesSegment(string s)
{
    bool zero = false;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '0') zero = true;
        else if (zero == true) return false;
    }
    return true;
}

/// <summary>
/// Leet code 1790. Check if One String Swap Can Make Strings Equal
/// 
/// Easy
/// 
/// You are given two strings s1 and s2 of equal length. A string swap 
/// is an operation where you choose two indices in a string (not 
/// necessarily different) and swap the characters at these indices.
///
/// Return true if it is possible to make both strings equal by performing 
/// at most one string swap on exactly one of the strings. Otherwise, 
/// return false.
///
/// Example 1:
/// Input: s1 = "bank", s2 = "kanb"
/// Output: true
/// Explanation: For example, swap the first character with the last 
/// character of s2 to make "bank".
///
/// Example 2:
/// Input: s1 = "attack", s2 = "defend"
/// Output: false
/// Explanation: It is impossible to make them equal with one string swap.
/// 
/// Example 3:
/// Input: s1 = "kelb", s2 = "kelb"
/// Output: true
/// Explanation: The two strings are already equal, so no string swap 
/// operation is required.
///
/// Example 4:
/// Input: s1 = "abcd", s2 = "dcba"
/// Output: false
///
/// Constraints:
/// 1. 1 <= s1.length, s2.length <= 100
/// 2. s1.length == s2.length
/// 3. s1 and s2 consist of only lowercase English letters.
/// </summary>
bool LeetCodeString::areAlmostEqual(string s1, string s2)
{
    string str1, str2;
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s2[i]) continue;
        str1.push_back(s1[i]);
        str2.push_back(s2[i]);
    }
    if (str1.empty()) return true;
    if (str1.size() == 2)
    {
        swap(str1[0], str1[1]);
        if (str1 == str2) return true;
    }
    return false;
}

/// <summary>
/// Leet code 1796. Second Largest Digit in a String
/// 
/// Easy
/// 
/// Given an alphanumeric string s, return the second largest numerical 
/// digit that appears in s, or -1 if it does not exist.
///
/// An alphanumeric string is a string consisting of lowercase English 
/// letters and digits.
///
/// Example 1:
/// Input: s = "dfa12321afd"
/// Output: 2
/// Explanation: The digits that appear in s are [1, 2, 3]. The second 
/// largest digit is 2.
///
/// Example 2:
/// Input: s = "abc1111"
/// Output: -1
/// Explanation: The digits that appear in s are [1]. There is no 
/// second largest digit. 
/// 
/// Constraints:
/// 1. 1 <= s.length <= 500
/// 2. s consists of only lowercase English letters and/or digits.
/// </summary>
int LeetCodeString::secondHighest(string s)
{
    vector<int> digits(10);
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) digits[s[i] - '0'] = 1;
    }
    int count = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (digits[i] == 1) count++;
        if (count == 2) return i;
    }
    return -1;
}

/// <summary>
/// Leet code 1805. Number of Different Integers in a String
/// 
/// Easy
/// 
/// You are given a string word that consists of digits and lowercase 
/// English letters.
///
/// You will replace every non-digit character with a space. For example, 
/// "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left 
/// with some integers that are separated by at least one space: "123", 
/// "34", "8", and "34".
///
/// Return the number of different integers after performing the 
/// replacement operations on word.
///
/// Two integers are considered different if their decimal representations 
/// without any leading zeros are different.
///
/// Example 1:
/// Input: word = "a123bc34d8ef34"
/// Output: 3
/// Explanation: The three different integers are "123", "34", and "8". 
/// Notice that "34" is only counted once.
///
/// Example 2:
/// Input: word = "leet1234code234"
/// Output: 2
///
/// Example 3:
/// Input: word = "a1b01c001"
/// Output: 1
/// Explanation: The three integers "1", "01", and "001" all represent 
/// the same integer because
/// the leading zeros are ignored when comparing their decimal values.
///
/// Constraints:
/// 1. 1 <= word.length <= 1000
/// 2. word consists of digits and lowercase English letters.
/// </summary>
int LeetCodeString::numDifferentIntegers(string word)
{
    unordered_set<string> result;

    string str;
    for (size_t i = 0; i <= word.size(); i++)
    {
        if (i == word.size() || !isdigit(word[i]))
        {
            if (!str.empty())
            {
                result.insert(str);
                str.clear();
            }
        }
        else
        {
            if (str.empty() || str[0] != '0')
            {
                str.push_back(word[i]);
            }
            else
            {
                str[0] = word[i];
            }
        }
    }
    return result.size();
}


/// <summary>
/// Leet code 1807. Evaluate the Bracket Pairs of a String
/// 
/// Medium
/// 
/// You are given a string s that contains some bracket pairs, with each 
/// pair containing a non-empty key.
///
/// For example, in the string "(name)is(age)yearsold", there are two 
/// bracket pairs that contain the keys "name" and "age".
/// You know the values of a wide range of keys. This is represented by 
/// a 2D string array knowledge where each knowledge[i] = [keyi, valuei] 
/// indicates that key keyi has a value of valuei.
///
/// You are tasked to evaluate all of the bracket pairs. When you 
/// evaluate a bracket pair that contains some key keyi, you will:
///
/// Replace keyi and the bracket pair with the key's corresponding valuei.
/// If you do not know the value of the key, you will replace keyi and the 
/// bracket pair with a question mark "?" (without the quotation marks).
/// Each key will appear at most once in your knowledge. There will not be 
/// any nested brackets in s.
///
/// Return the resulting string after evaluating all of the bracket pairs.
/// 
/// Example 1:
/// Input: s = "(name)is(age)yearsold", knowledge = 
/// [["name","bob"],["age","two"]]
/// Output: "bobistwoyearsold"
/// Explanation:
/// The key "name" has a value of "bob", so replace "(name)" with "bob".
/// The key "age" has a value of "two", so replace "(age)" with "two".
///
/// Example 2:
/// Input: s = "hi(name)", knowledge = [["a","b"]]
/// Output: "hi?"
/// Explanation: As you do not know the value of the key "name", replace 
/// "(name)" with "?".
///
/// Example 3:
/// Input: s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
/// Output: "yesyesyesaaa"
/// Explanation: The same key can appear multiple times.
/// The key "a" has a value of "yes", so replace all occurrences of "(a)" 
/// with "yes".
/// Notice that the "a"s not in a bracket pair are not evaluated.
///
/// Example 4:
/// Input: s = "(a)(b)", knowledge = [["a","b"],["b","a"]]
/// Output: "ba"
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. 0 <= knowledge.length <= 10^5
/// 3. knowledge[i].length == 2
/// 4. 1 <= keyi.length, valuei.length <= 10
/// 5. s consists of lowercase English letters and round 
///    brackets '(' and ')'.
/// 6. Every open bracket '(' in s will have a corresponding close 
///    bracket ')'.
/// 7. The key in each bracket pair of s will be non-empty.
/// 8. There will not be any nested bracket pairs in s.
/// 9. keyi and valuei consist of lowercase English letters.
/// 10. Each keyi in knowledge is unique.
/// </summary>
string LeetCodeString::evaluate(string s, vector<vector<string>>& knowledge)
{
    unordered_map<string, string> word_map;

    for (size_t i = 0; i < knowledge.size(); i++)
    {
        word_map[knowledge[i][0]] = knowledge[i][1];
    }
    int brackets = 0;
    string str;
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (word_map.count(str) > 0)
            {
                result.append(word_map[str]);
            }
            else
            {
                result.append("?");
            }
            str.clear();
            brackets = 0;
        }
        else if (s[i] == '(')
        {
            brackets = 1;
        }
        else if (brackets == 1)
        {
            str.push_back(s[i]);
        }
        else
        {
            result.push_back(s[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code 1813. Sentence Similarity III
/// 
/// Medium
/// 
/// A sentence is a list of words that are separated by a single space 
/// with no leading or trailing spaces. For example, "Hello World", 
/// "HELLO", "hello world hello world" are all sentences. Words consist 
/// of only uppercase and lowercase English letters.
///
/// Two sentences sentence1 and sentence2 are similar if it is possible to 
/// insert an arbitrary sentence (possibly empty) inside one of these 
/// sentences such that the two sentences become equal. For example, 
/// sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can 
/// be made equal by inserting "my name is" between "Hello" and "Jane" in 
/// sentence2.
///
/// Given two sentences sentence1 and sentence2, return true if sentence1 
/// and sentence2 are similar. Otherwise, return false.
/// 
/// Example 1:
/// Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
/// Output: true
/// Explanation: sentence2 can be turned to sentence1 by inserting 
/// "name is" between "My" and "Haley".
///
/// Example 2:
/// Input: sentence1 = "of", sentence2 = "A lot of words"
/// Output: false
/// Explanation: No single sentence can be inserted inside one of the 
/// sentences to make it equal to the other.
///
/// Example 3:
/// Input: sentence1 = "Eating right now", sentence2 = "Eating"
/// Output: true
/// Explanation: sentence2 can be turned to sentence1 by inserting 
/// "right now" at the end of the sentence.
///
/// Example 4:
/// Input: sentence1 = "Luky", sentence2 = "Lucccky"
/// Output: false
///
/// Constraints:
/// 1. 1 <= sentence1.length, sentence2.length <= 100
/// 2. sentence1 and sentence2 consist of lowercase and uppercase 
///    English letters and spaces.
/// 3. The words in sentence1 and sentence2 are separated by a single 
///    space.
/// </summary>
bool LeetCodeString::areSentencesSimilar(string sentence1, string sentence2)
{
    vector<string> words1, words2;
    string str;
    for (size_t i = 0; i <= sentence1.size(); i++)
    {
        if (i == sentence1.size() || isspace(sentence1[i]))
        {
            if (!str.empty())
            {
                words1.push_back(str);
                str.clear();
            }
        }
        else str.push_back(sentence1[i]);

    }
    for (size_t i = 0; i <= sentence2.size(); i++)
    {
        if (i == sentence2.size() || isspace(sentence2[i]))
        {
            if (!str.empty())
            {
                words2.push_back(str);
                str.clear();
            }
        }
        else str.push_back(sentence2[i]);
    }
    if (words1.size() < words2.size()) swap(words1, words2);
    int first = 0;
    while (first < (int)words2.size() && words1[first] == words2[first])
    {
        first++;
    }
    int last = 0;
    while (last < (int)words2.size() && words1[words1.size() - 1 - last] == words2[words2.size() - 1 - last])
    {
        last++;
    }
    if (first + last >= (int)words2.size()) return true;
    else return false;
}

/// <summary>
/// Leet code 1816. Truncate Sentence
/// 
/// Easy
/// 
/// A sentence is a list of words that are separated by a single space 
/// with no leading or trailing spaces. Each of the words consists of 
/// only uppercase and lowercase English letters (no punctuation).
///
/// For example, "Hello World", "HELLO", and "hello world hello world" 
/// are all sentences.
/// You are given a sentence s and an integer k. You want to truncate 
/// s such that it contains only the first k words. Return s after 
/// truncating it.
/// 
/// Example 1:
/// Input: s = "Hello how are you Contestant", k = 4
/// Output: "Hello how are you"
/// Explanation:
/// The words in s are ["Hello", "how" "are", "you", "Contestant"].
/// The first 4 words are ["Hello", "how", "are", "you"].
/// Hence, you should return "Hello how are you".
///
/// Example 2:
/// Input: s = "What is the solution to this problem", k = 4
/// Output: "What is the solution"
/// Explanation:
/// The words in s are ["What", "is" "the", "solution", "to", "this", 
/// "problem"].
/// The first 4 words are ["What", "is", "the", "solution"].
/// Hence, you should return "What is the solution".
/// 
/// Example 3:
/// Input: s = "chopper is not a tanuki", k = 5
/// Output: "chopper is not a tanuki"
/// Constraints:
/// 1. 1 <= s.length <= 500
/// 2. k is in the range [1, the number of words in s].
/// 3. s consist of only lowercase and uppercase English letters and 
///    spaces.
/// 4. The words in s are separated by a single space.
/// 5. There are no leading or trailing spaces.
/// </summary>
string LeetCodeString::truncateSentence(string s, int k)
{
    int count = 0;
    string result;
    string str;
    for (size_t i = 0; i <= s.size(); i++)
    {
        if (i == s.size() || isspace(s[i]))
        {
            if (!result.empty()) result.push_back(' ');
            result.append(str);
            count++;
            if (count == k) break;
            str.clear();
        }
        else str.push_back(s[i]);
    }
    return result;
}

/// <summary>
/// Leet code 1832. Check if the Sentence Is Pangram
/// 
/// Easy
/// 
/// A pangram is a sentence where every letter of the English alphabet 
/// appears at least once.
///
/// Given a string sentence containing only lowercase English letters, 
/// return true if sentence is a pangram, or false otherwise.
///
/// Example 1:
/// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
/// Output: true
/// Explanation: sentence contains at least one of every letter of the 
/// English alphabet.
///
/// Example 2:
/// Input: sentence = "leetcode"
/// Output: false
///
/// Constraints:
/// 1. 1 <= sentence.length <= 1000
/// 2. sentence consists of lowercase English letters.
/// </summary>
bool LeetCodeString::checkIfPangram(string sentence)
{
    vector<int>chars(26);
    int result = 0;
    for (char c : sentence)
    {
        if (chars[c - 'a'] == 0)
        {
            chars[c - 'a'] = 1;
            result++;
        }
        if (result == 26) return true;
    }
    return false;
}


/// <summary>
/// Leet code 1794. Count Pairs of Equal Substrings With Minimum Difference
/// 
/// Medium
/// 
/// You are given two strings firstString and secondString that are 
/// 0-indexed and consist only of lowercase English letters. Count the 
/// number of index quadruples (i,j,a,b) that satisfy the following 
/// conditions:
///
/// 0 <= i <= j < firstString.length
/// 0 <= a <= b < secondString.length
/// The substring of firstString that starts at the ith character and ends 
/// at the jth character (inclusive) is equal to the substring of 
/// secondString that starts at the ath character and ends at the bth 
/// character (inclusive).
/// j - a is the minimum possible value among all quadruples that satisfy 
/// the previous conditions.
/// Return the number of such quadruples.
///
/// Example 1:
/// Input: firstString = "abcd", secondString = "bccda"
/// Output: 1
/// Explanation: The quadruple (0,0,4,4) is the only one that satisfies 
/// all the conditions and minimizes j - a.
///
/// Example 2:
/// Input: firstString = "ab", secondString = "cd"
/// Output: 0
/// Explanation: There are no quadruples satisfying all the conditions.
///
/// Constraints:
/// 1. 1 <= firstString.length, secondString.length <= 2 * 10^5
/// 2. Both strings consist only of lowercase English letters.
/// </summary>
int LeetCodeString::countQuadruples(string firstString, string secondString)
{
    vector<int> pos(26, -1);
    int last = INT_MAX;
    for (size_t i = 0; i < secondString.size(); i++)
    {
        pos[secondString[i] - 'a'] = i;
    }
    int result = 0;
    for (int i = 0; i < (int)firstString.size(); i++)
    {
        if (pos[firstString[i] - 'a'] == -1) continue;
        if (i - pos[firstString[i] - 'a'] < last)
        {
            last = i - pos[firstString[i] - 'a'];
            result = 1;
        }
        else if (i - pos[firstString[i] - 'a'] == last)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1839. Longest Substring Of All Vowels in Order
/// 
/// Medium
/// 
/// A string is considered beautiful if it satisfies the following 
/// conditions:
///
/// Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must 
/// appear at least once in it.
/// The letters must be sorted in alphabetical order (i.e. all 'a's before 
/// 'e's, all 'e's before 'i's, etc.).
/// For example, strings "aeiou" and "aaaaaaeiiiioou" are considered 
/// beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
///
/// Given a string word consisting of English vowels, return the length of 
/// the longest beautiful substring of word. If no such substring exists, 
/// return 0.
///
/// A substring is a contiguous sequence of characters in a string.
/// Example 1:
/// Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
/// Output: 13
/// Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" 
/// of length 13.
///
/// Example 2:
/// Input: word = "aeeeiiiioooauuuaeiou"
/// Output: 5
/// Explanation: The longest beautiful substring in word is "aeiou" of 
/// length 5.
///
/// Example 3:
/// Input: word = "a"
/// Output: 0
/// Explanation: There is no beautiful substring, so return 0.
///
/// Constraints:
/// 1. 1 <= word.length <= 5 * 105
/// 2. word consists of characters 'a', 'e', 'i', 'o', and 'u'.
/// </summary>
int LeetCodeString::longestBeautifulSubstring(string word)
{
    unordered_map<char, int> vowels = 
    { 
        { 'a', 0, }, {'e', 1}, {'i', 2}, {'o', 3 }, {'u', 4} 
    };
    int first = -1;
    int prev = -1;
    int result = 0;
    for (int i = 0; i < (int)word.size(); i++)
    {
        if (word[i] == 'a')
        {
            if (prev != 0) first = i;
        }
        else
        {
            if (prev > vowels[word[i]] || prev + 1 < vowels[word[i]])
            {
                first = -1;
            }
        }
        prev = vowels[word[i]];
        if (word[i] == 'u' && first != -1)
        {
            result = max(result, i - first + 1);
        }
    }
    return result;
}

/// <summary>
/// Leet code 1844. Replace All Digits with Characters
/// 
/// Easy
/// 
/// You are given a 0-indexed string s that has lowercase English letters
/// in its even indices and digits in its odd indices.
/// There is a function shift(c, x), where c is a character and x is a 
/// digit, that returns the xth character after c.
/// 
/// For example, shift('a', 5) = 'f' and shift('x', 0) = 'x'.
/// For every odd index i, you want to replace the digit s[i] with 
/// shift(s[i-1], s[i]).
///
/// Return s after replacing all digits. It is guaranteed that 
/// shift(s[i-1], s[i]) will never exceed 'z'.
/// 
/// Example 1:
/// Input: s = "a1c1e1"
/// Output: "abcdef"
/// Explanation: The digits are replaced as follows:
/// - s[1] -> shift('a',1) = 'b'
/// - s[3] -> shift('c',1) = 'd'
/// - s[5] -> shift('e',1) = 'f'
///
/// Example 2:
/// Input: s = "a1b2c3d4e"
/// Output: "abbdcfdhe"
/// Explanation: The digits are replaced as follows:
/// - s[1] -> shift('a',1) = 'b'
/// - s[3] -> shift('b',2) = 'd'
/// - s[5] -> shift('c',3) = 'f'
/// - s[7] -> shift('d',4) = 'h'
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s consists only of lowercase English letters and digits.
/// 3. shift(s[i-1], s[i]) <= 'z' for all odd indices i.
/// </summary>
string LeetCodeString::replaceDigits(string s)
{
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            result.push_back(result.back() + s[i] - '0');
        }
        else
        {
            result.push_back(s[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code 1896. Minimum Cost to Change the Final Value of Expression
/// </summary>
void LeetCodeString::minOperationsToFlip_FreeTree(LogicOperation* tree)
{
    if (tree == nullptr) return;
    minOperationsToFlip_FreeTree(tree->left);
    tree->left = nullptr;
    minOperationsToFlip_FreeTree(tree->right);
    tree->right = nullptr;
    delete tree;
}

/// <summary>
/// Leet code 1896. Minimum Cost to Change the Final Value of Expression
/// </summary>
LogicOperation* LeetCodeString::minOperationsToFlip_BuildTree(string& expression, int &index)
{
    LogicOperation* root = nullptr;
    while (index < (int)expression.size())
    {
        LogicOperation* node = nullptr;
        if (expression[index] == ')') break;
        else if (expression[index] == '(')
        {
            node = minOperationsToFlip_BuildTree(expression, ++index);
        }
        else if (expression[index] == '0' || expression[index] == '1')
        {
            node = new LogicOperation(expression[index] - '0', '#');
        }
        else if (expression[index] == '|' || expression[index] == '&')
        {
            node = new LogicOperation(-1, expression[index]);
        }
        if (root == nullptr)
        {
            root = node;
        }
        else if (root->left == nullptr || root->right != nullptr)
        {
            node->left = root;
            root = node;
        }
        else
        {
            root->right = node;
            if (root->operation == '|')
            {
                root->value = (root->left->value | root->right->value);
            }
            else
            {
                root->value = (root->left->value & root->right->value);
            }
        }
        index++;
    }
    return root;
}

/// <summary>
/// Leet code 1896. Minimum Cost to Change the Final Value of Expression
/// </summary>
int LeetCodeString::minOperationsToFlip_FlipTree(LogicOperation* root)
{
    if (root->operation == '#') return 1;
    int left = root->left->value;
    int right = root->right->value;
    int result = 0;
    if (root->operation == '&')
    {
        if ((left & right) == 0)
        {
            if ((left | right) == 1) return 1;
            else
            {
                result = 1 + min(minOperationsToFlip_FlipTree(root->left), 
                                 minOperationsToFlip_FlipTree(root->right));
            }
        }
        else
        {
            result =  min(minOperationsToFlip_FlipTree(root->left), 
                          minOperationsToFlip_FlipTree(root->right));
        }
    }
    else
    {
        if ((left | right) == 1)
        {
            if ((left & right) == 0) return 1;
            else
            {
                result = 1 + min(minOperationsToFlip_FlipTree(root->left),
                                 minOperationsToFlip_FlipTree(root->right));
            }
        }
        else
        {
            result = min(minOperationsToFlip_FlipTree(root->left),
                         minOperationsToFlip_FlipTree(root->right));
        }
    }
    return result;
}

/// <summary>
/// Leet code 1896. Minimum Cost to Change the Final Value of Expression
/// 
/// Hard
/// 
/// You are given a valid boolean expression as a string expression 
/// consisting of the characters '1','0','&' (bitwise AND operator),'|' 
/// (bitwise OR operator),'(', and ')'.
///
/// For example, "()1|1" and "(1)&()" are not valid while "1", 
/// "(((1))|(0))", and "1|(0&(1))" are valid expressions.
/// Return the minimum cost to change the final value of the expression.
/// 
/// For example, if expression = "1|1|(0&0)&1", its value is 
/// 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1. We want to apply operations 
/// so that the new expression evaluates to 0.
/// The cost of changing the final value of an expression is the number 
/// of operations performed on the expression. The types of operations 
/// are described as follows:
///
/// Turn a '1' into a '0'.
/// Turn a '0' into a '1'.
/// Turn a '&' into a '|'.
/// Turn a '|' into a '&'.
/// Note: '&' does not take precedence over '|' in the order of 
/// calculation. Evaluate parentheses first, then in left-to-right order.
///
/// Example 1:
/// Input: expression = "1&(0|1)"
/// Output: 1
/// Explanation: We can turn "1&(0|1)" into "1&(0&1)" by changing the '|' 
/// to a '&' using 1 operation.
/// The new expression evaluates to 0. 
///
/// Example 2:
/// Input: expression = "(0&0)&(0&0&0)"
/// Output: 3
/// Explanation: We can turn "(0&0)&(0&0&0)" into "(0|1)|(0&0&0)" using 
/// 3 operations.
/// The new expression evaluates to 1.
///
/// Example 3:
/// Input: expression = "(0|(1|0&1))"
/// Output: 1
/// Explanation: We can turn "(0|(1|0&1))" into "(0|(0|0&1))" using 
/// 1 operation.
/// The new expression evaluates to 0.
///
/// Constraints:
/// 1. 1 <= expression.length <= 10^5
/// 2. expression only contains '1','0','&','|','(', and ')'
/// 3. All parentheses are properly matched.
/// 4. There will be no empty parentheses (i.e: "()" is not a substring 
///    of expression).
/// </summary>
int LeetCodeString::minOperationsToFlip(string expression)
{
    int index = 0;
    LogicOperation* root = minOperationsToFlip_BuildTree(expression, index);
    int result = minOperationsToFlip_FlipTree(root);
    minOperationsToFlip_FreeTree(root);
    return result;
}

/// <summary>
/// Leet code 1859. Sorting the Sentence
/// 
/// Easy
/// 
/// A sentence is a list of words that are separated by a single space 
/// with no leading or trailing spaces. Each word consists of lowercase 
/// and uppercase English letters.
///
/// A sentence can be shuffled by appending the 1-indexed word position to 
/// each word then rearranging the words in the sentence.
///
/// For example, the sentence "This is a sentence" can be shuffled as 
/// "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
/// Given a shuffled sentence s containing no more than 9 words, 
/// reconstruct and return the original sentence.
/// 
/// Example 1:
/// Input: s = "is2 sentence4 This1 a3"
/// Output: "This is a sentence"
/// Explanation: Sort the words in s to their original positions "This1 
/// is2 a3 sentence4", then remove the numbers.
///
/// Example 2:
/// Input: s = "Myself2 Me1 I4 and3"
/// Output: "Me Myself and I"
/// Explanation: Sort the words in s to their original positions "Me1 
/// Myself2 and3 I4", then remove the numbers.
///
/// Constraints:
/// 1. 2 <= s.length <= 200
/// 2. s consists of lowercase and uppercase English letters, spaces, and 
///    digits from 1 to 9.
/// 3. The number of words in s is between 1 and 9.
/// 4. The words in s are separated by a single space.
/// 5. s contains no leading or trailing spaces.
/// </summary>
string LeetCodeString::sortSentence(string s)
{
    vector<string> arr(10);
    string str;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            arr[s[i] - '1'] = str;
            str.clear();
        }
        else if (!isspace(s[i])) str.push_back(s[i]);
    }
    string result;
    for (size_t i = 0; i < 10; i++)
    {
        if (!arr[i].empty())
        {
            if (!result.empty()) result.push_back(' ');
            result.append(arr[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code 1869. Longer Contiguous Segments of Ones than Zeros
/// 
/// Easy
/// 
/// Given a binary string s, return true if the longest contiguous segment 
/// of 1s is strictly longer than the longest contiguous segment of 0s in 
/// s. Return false otherwise.
///
/// For example, in s = "110100010" the longest contiguous segment of 1s 
/// has length 2, and the longest contiguous segment of 0s has length 3.
/// Note that if there are no 0s, then the longest contiguous segment of 
/// 0s is considered to have length 0. The same applies if there are no 1s.
/// 
/// Example 1:
/// Input: s = "1101"
/// Output: true
/// Explanation:
/// The longest contiguous segment of 1s has length 2: "1101"
/// The longest contiguous segment of 0s has length 1: "1101"
/// The segment of 1s is longer, so return true.
///
/// Example 2:
/// Input: s = "111000"
/// Output: false
/// Explanation:
/// The longest contiguous segment of 1s has length 3: "111000"
/// The longest contiguous segment of 0s has length 3: "111000"
/// The segment of 1s is not longer, so return false.
///
/// Example 3:
/// Input: s = "110100010"
/// Output: false
/// Explanation:
/// The longest contiguous segment of 1s has length 2: "110100010"
/// The longest contiguous segment of 0s has length 3: "110100010"
/// The segment of 1s is not longer, so return false.
///
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s[i] is either '0' or '1'.
/// </summary>
bool LeetCodeString::checkZeroOnes(string s)
{
    int sum_one = 0;
    int sum_zero = 0;
    int count_one = 0;
    int count_zero = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            count_one = 0;
            count_zero++;
            sum_zero = max(sum_zero, count_zero);
        }
        else
        {
            count_zero = 0;
            count_one++;
            sum_one = max(sum_one, count_one);
        }
    }

    return sum_one > sum_zero;
}


/// <summary>
/// Leet code 1876. Substrings of Size Three with Distinct Characters
/// 
/// Easy
/// 
/// A string is good if there are no repeated characters.
///
/// Given a string s return the number of good substrings of length 
/// three in s.
///
/// Note that if there are multiple occurrences of the same substring, 
/// every occurrence should be counted.
///
/// A substring is a contiguous sequence of characters in a string.
///
/// Example 1:
/// 
/// Input: s = "xyzzaz"
/// Output: 1
/// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", 
/// and "zaz". 
/// The only good substring of length 3 is "xyz".
///
/// Example 2:
/// Input: s = "aababcabc"
/// Output: 4
/// Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", 
/// "abc", "bca", "cab", and "abc".
/// The good substrings are "abc", "bca", "cab", and "abc".
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s consists of lowercase English letters.
/// </summary>
int LeetCodeString::countGoodSubstrings(string s)
{
    vector<int> char_count(26);
    int count = 0;
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        char_count[s[i] - 'a']++;
        if (char_count[s[i] - 'a'] == 1) count++;
        if (i >= 3)
        {
            char_count[s[i - 3] - 'a']--;
            if (char_count[s[i - 3] - 'a'] == 0) count--;
        }

        if (count == 3) result++;
    }
    return result;
}

/// <summary>
/// Leet code 1880. Check if Word Equals Summation of Two Words
/// 
/// Easy
/// 
/// The letter value of a letter is its position in the alphabet starting 
/// from 0 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, etc.).
///
/// The numerical value of some string of lowercase English letters s is 
/// the concatenation of the letter values of each letter in s, which is 
/// then converted into an integer.
///
/// For example, if s = "acb", we concatenate each letter's letter value, 
/// resulting in "021". After converting it, we get 21.
/// You are given three strings firstWord, secondWord, and targetWord, 
/// each consisting of lowercase English letters 'a' through 'j' inclusive.
///
/// Return true if the summation of the numerical values of firstWord and 
/// secondWord equals the numerical value of targetWord, or false otherwise.
///  
/// Example 1:
/// Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
/// Output: true
/// Explanation:
/// The numerical value of firstWord is "acb" -> "021" -> 21.
/// The numerical value of secondWord is "cba" -> "210" -> 210.
/// The numerical value of targetWord is "cdb" -> "231" -> 231.
/// We return true because 21 + 210 == 231.
///
/// Example 2:
/// Input: firstWord = "aaa", secondWord = "a", targetWord = "aab"
/// Output: false
/// Explanation: 
/// The numerical value of firstWord is "aaa" -> "000" -> 0.
/// The numerical value of secondWord is "a" -> "0" -> 0.
/// The numerical value of targetWord is "aab" -> "001" -> 1.
/// We return false because 0 + 0 != 1.
///
/// Example 3:
/// Input: firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
/// Output: true
/// Explanation: 
/// The numerical value of firstWord is "aaa" -> "000" -> 0.
/// The numerical value of secondWord is "a" -> "0" -> 0.
/// The numerical value of targetWord is "aaaa" -> "0000" -> 0.
/// We return true because 0 + 0 == 0.
/// 
/// Constraints:
/// 1. 1 <= firstWord.length, secondWord.length, targetWord.length <= 8
/// 2. firstWord, secondWord, and targetWord consist of lowercase English 
///    letters from 'a' to 'j' inclusive.
/// </summary>
bool LeetCodeString::isSumEqual(string firstWord, string secondWord, string targetWord)
{
    long long num1 = 0, num2 = 0, num3 = 0;
    for (size_t i = 0; i < firstWord.size(); i++)
    {
        num1 = num1 * 10 + firstWord[i] - 'a';
    }
    for (size_t i = 0; i < secondWord.size(); i++)
    {
        num2 = num2 * 10 + secondWord[i] - 'a';
    }
    for (size_t i = 0; i < targetWord.size(); i++)
    {
        num3 = num3 * 10 + targetWord[i] - 'a';
    }
    if (num1 + num2 == num3) return true;
    else return false;
}

/// <summary>
/// Leet code 1897. Redistribute Characters to Make All Strings Equal
/// 
/// Easy
/// 
/// You are given an array of strings words (0-indexed).
///
/// In one operation, pick two distinct indices i and j, where 
/// words[i] is a non-empty string, and move any character from words[i] 
/// to any position in words[j].
///
/// Return true if you can make every string in words equal using any 
/// number of operations, and false otherwise.
/// 
/// Example 1:
/// Input: words = ["abc","aabc","bc"]
/// Output: true
/// Explanation: Move the first 'a' in words[1] to the front of words[2],
/// to make words[1] = "abc" and words[2] = "abc".
/// All the strings are now equal to "abc", so return true.
///
/// Example 2:
/// Input: words = ["ab","a"]
/// Output: false
/// Explanation: It is impossible to make all the strings equal using the 
/// operation.
/// 
/// Constraints:
/// 1. 1 <= words.length <= 100
/// 2. 1 <= words[i].length <= 100
/// 3. words[i] consists of lowercase English letters.
/// </summary>
bool LeetCodeString::makeEqual(vector<string>& words)
{
    vector<int> chars(26);
    for (size_t i = 0; i < words.size(); i++)
    {
        for (size_t j = 0; j < words[i].size(); j++)
        {
            chars[words[i][j] - 'a']++;
        }
    }
    for (size_t i = 0; i < 26; i++)
    {
        if (chars[i] % words.size() != 0) return false;
    }
    return true;
}

/// <summary>
/// Leet code 1903. Largest Odd Number in String
/// 
/// Easy
/// 
/// You are given a string num, representing a large integer. Return the 
/// largest-valued odd integer (as a string) that is a non-empty substring 
/// of num, or an empty string "" if no odd integer exists.
///
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: num = "52"
/// Output: "5"
/// Explanation: The only non-empty substrings are "5", "2", and "52". "5" 
/// is the only odd number.
///
/// Example 2:
/// Input: num = "4206"
/// Output: ""
/// Explanation: There are no odd numbers in "4206".
///
/// Example 3:
/// Input: num = "35427"
/// Output: "35427"
/// Explanation: "35427" is already an odd number.
/// 
/// Constraints:
/// 1. 1 <= num.length <= 10^5
/// 2. num only consists of digits and does not contain any leading zeros.
/// </summary>
string LeetCodeString::largestOddNumber(string num)
{
    string result = num;
    while ((!result.empty()) && ((result.back() - '0') % 2) == 0)
    {
        result.pop_back();
    }
    return result;
}

/// <summary>
/// Leet code 1945. Sum of Digits of String After Convert
///                                  
/// Easy
/// 
/// 
/// You are given a string s consisting of lowercase English letters, and 
/// an integer k.
///
/// First, convert s into an integer by replacing each letter with its 
/// position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 
/// 'z' with 26). Then, transform the integer by replacing it with the sum 
/// of its digits. Repeat the transform operation k times in total.
/// 
/// For example, if s = "zbax" and k = 2, then the resulting integer would 
/// be 8 by the following operations:
///
/// Convert: "zbax" "(26)(2)(1)(24)" "262124" 262124
/// Transform #1: 262124 2 + 6 + 2 + 1 + 2 + 4 17
/// Transform #2: 17 1 + 7 8
/// Return the resulting integer after performing the operations described 
/// above.
/// 
/// Example 1:
/// Input: s = "iiii", k = 1
/// Output: 36
/// Explanation: The operations are as follows:
/// - Convert: "iiii" "(9)(9)(9)(9)" "9999" 9999
/// - Transform #1: 9999 9 + 9 + 9 + 9 36
/// Thus the resulting integer is 36.
///
/// Example 2:
/// Input: s = "leetcode", k = 2
/// Output: 6
/// Explanation: The operations are as follows:
/// - Convert: "leetcode" "(12)(5)(5)(20)(3)(15)(4)(5)" "12552031545" 12552031545
/// - Transform #1: 12552031545 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 33
/// - Transform #2: 33 3 + 3 6
/// Thus the resulting integer is 6.
///
/// Example 3:
/// Input: s = "zbax", k = 2
/// Output: 8
///
/// Constraints:
/// 1 <= s.length <= 100
/// 1 <= k <= 10
/// s consists of lowercase English letters.
/// </summary>
int LeetCodeString::getLucky(string s, int k)
{
    string str;
    for (size_t j = 0; j < s.size(); j++)
    {
        str.append(to_string(s[j] - 'a' + 1));
    }
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        result = 0;
        for (size_t j = 0; j < str.size(); j++)
        {
            result += str[j] - '0';
        }
        str = to_string(result);
    }
    return result;
}

/// <summary>
/// Leet code 1935. Maximum Number of Words You Can Type
///                                  
/// Easy
/// 
/// There is a malfunctioning keyboard where some letter keys do not work. 
/// All other keys on the keyboard work properly.
///
/// Given a string text of words separated by a single space (no leading 
/// or trailing spaces) and a string brokenLetters of all distinct letter 
/// keys that are broken, return the number of words in text you can fully 
/// type using this keyboard.
/// 
/// Example 1:
/// Input: text = "hello world", brokenLetters = "ad"
/// Output: 1
/// Explanation: We cannot type "world" because the 'd' key is broken.
///
/// Example 2:
/// Input: text = "leet code", brokenLetters = "lt"
/// Output: 1
/// Explanation: We cannot type "leet" because the 'l' and 't' keys are 
/// broken.
///
/// Example 3:
/// Input: text = "leet code", brokenLetters = "e"
/// Output: 0
/// Explanation: We cannot type either word because the 'e' key is broken.
/// 
/// Constraints:
/// 1. 1 <= text.length <= 10^4
/// 2. 0 <= brokenLetters.length <= 26
/// 3. text consists of words separated by a single space without any 
///    leading or trailing spaces.
/// 4. Each word only consists of lowercase English letters.
/// 5. brokenLetters consists of distinct lowercase English letters.
/// </summary>
int LeetCodeString::canBeTypedWords(string text, string brokenLetters)
{
    vector<int> chars(26);
    for (size_t i = 0; i < brokenLetters.size(); i++)
    {
        chars[brokenLetters[i] - 'a']++;
    }
    int result = 0;
    bool broken = false;
    for (size_t i = 0; i <= text.size(); i++)
    {
        if (i == text.size() || isspace(text[i]))
        {
            if (broken == false) result++;
            broken = false;
        }
        else
        {
            if (chars[text[i] - 'a'] > 0) broken = true;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1948. Delete Duplicate Folders in System
/// </summary>
void LeetCodeString::addDuplicateFolderPaths(FolderNode* root, vector<vector<string>>& paths)
{
    for (size_t i = 0; i < paths.size(); i++)
    {
        FolderNode* node = root;
        for (size_t j = 0; j < paths[i].size(); j++)
        {
            if (node->children[paths[i][j]] == nullptr)
            {
                node->children[paths[i][j]] = new FolderNode(paths[i][j]);
            }
            node = node->children[paths[i][j]];
        }
    }
}

/// <summary>
/// Leet code 1948. Delete Duplicate Folders in System
/// </summary>
string LeetCodeString::deleteDuplicateFolderPaths(FolderNode* root, unordered_map<string, FolderNode*>& node_map)
{
    string subfolders;
    for (auto itr : root->children)
    {
        subfolders += deleteDuplicateFolderPaths(itr.second, node_map);
    }
    if (!subfolders.empty())
    {
        if (node_map.count(subfolders) > 0)
        {
            root->is_deleted = 1;
            node_map[subfolders]->is_deleted = 1;
        }
        else
        {
            node_map[subfolders] = root;
        }
    }
    return "(" + root->foldername + subfolders + ")";
}

/// <summary>
/// Leet code 1948. Delete Duplicate Folders in System
/// </summary>
vector<vector<string>> LeetCodeString::outputFolderPaths(FolderNode* root)
{
    vector<vector<string>> paths;
    for (auto itr : root->children)
    {
        if (itr.second->is_deleted == 1) continue;
        vector<vector<string>> sub_paths = outputFolderPaths(itr.second);
        paths.insert(paths.end(), sub_paths.begin(), sub_paths.end());
    }
    if (root->foldername != "#")
    {
        for (size_t i = 0; i < paths.size(); i++)
        {
            paths[i].push_back(root->foldername);
        }
        paths.push_back({ root->foldername });
    }
    return paths;
}


/// <summary>
/// Leet code 1948. Delete Duplicate Folders in System
///                                  
/// Hard
/// 
/// Due to a bug, there are many duplicate folders in a file system. You 
/// are given a 2D array paths, where paths[i] is an array representing 
/// an absolute path to the ith folder in the file system.
///
/// For example, ["one", "two", "three"] represents the path 
/// "/one/two/three".
/// Two folders (not necessarily on the same level) are identical if they 
/// contain the same non-empty set of identical subfolders and underlying 
/// subfolder structure. The folders do not need to be at the root level 
/// to be identical. If two or more folders are identical, then mark the 
/// folders as well as all their subfolders.
///
/// For example, folders "/a" and "/b" in the file structure below are 
/// identical. They (as well as their subfolders) should all be marked:
/// /a
/// /a/x
/// /a/x/y
/// /a/z
/// /b
/// /b/x
/// /b/x/y
/// /b/z
/// However, if the file structure also included the path "/b/w", then 
/// the folders "/a" and "/b" would not be identical. Note that "/a/x" 
/// and "/b/x" would still be considered identical even with the added 
/// folder.
/// Once all the identical folders and their subfolders have been marked, 
/// the file system will delete all of them. The file system only runs 
/// the deletion once, so any folders that become identical after the 
/// initial deletion are not deleted.
///
/// Return the 2D array ans containing the paths of the remaining folders 
/// after deleting all the marked folders. The paths may be returned in 
/// any order.
/// 
/// Example 1:
/// Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
/// Output: [["d"],["d","a"]]
/// Explanation: The file structure is as shown.
/// Folders "/a" and "/c" (and their subfolders) are marked for deletion 
/// because they both contain an empty
/// folder named "b".
///
/// Example 2:
/// Input: paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],
/// ["a","b","x","y"],["w"],["w","y"]]
/// Output: [["c"],["c","b"],["a"],["a","b"]]
/// Explanation: The file structure is as shown. 
/// Folders "/a/b/x" and "/w" (and their subfolders) are marked for 
/// deletion because they both contain an empty folder named "y".
/// Note that folders "/a" and "/c" are identical after the deletion, but 
/// they are not deleted because they were not marked beforehand.
///
/// Example 3:
/// Input: paths = [["a","b"],["c","d"],["c"],["a"]]
/// Output: [["c"],["c","d"],["a"],["a","b"]]
/// Explanation: All folders are unique in the file system.
/// Note that the returned array can be in a different order as the order 
/// does not matter.
///
/// Example 4:
/// Input: paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],
/// ["b","x"],["b","x","y"],["b","z"]]
/// Output: []
/// Explanation: The file structure is as shown.
/// Folders "/a/x" and "/b/x" (and their subfolders) are marked for 
/// deletion because they both contain an
/// empty folder named "y".
/// Folders "/a" and "/b" (and their subfolders) are marked for deletion 
/// because they both contain an empty
/// folder "z" and the folder "x" described above.
///
/// Example 5:
/// Input: paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],
/// ["b","x"],["b","x","y"],["b","z"],["b","w"]]
/// Output: [["b"],["b","w"],["b","z"],["a"],["a","z"]]
/// Explanation: This has the same structure as the previous example, 
/// except with the added "/b/w".
/// Folders "/a/x" and "/b/x" are still marked, but "/a" and "/b" are no
/// longer marked because "/b" has the
/// empty folder named "w" and "/a" does not.
/// Note that "/a/z" and "/b/z" are not marked because the set of 
/// identical subfolders must be non-empty, but these folders are empty.
///
/// Constraints:
/// 1. 1 <= paths.length <= 2 * 10^4
/// 2. 1 <= paths[i].length <= 500
/// 3. 1 <= paths[i][j].length <= 10
/// 4. 1 <= sum(paths[i][j].length) <= 2 * 10^5
/// 5. path[i][j] consists of lowercase English letters.
/// 6. No two paths lead to the same folder.
/// 7. For any folder not at the root level, its parent folder will also 
///    be in the input.
/// </summary>
vector<vector<string>> LeetCodeString::deleteDuplicateFolder(vector<vector<string>>& paths)
{
    FolderNode* root = new FolderNode("#");
    unordered_map<string, FolderNode*> node_map;
    addDuplicateFolderPaths(root, paths);
    deleteDuplicateFolderPaths(root, node_map);
    vector<vector<string>> result = outputFolderPaths(root);
    for (size_t i = 0; i < result.size(); i++)
    {
        reverse(result[i].begin(), result[i].end());
    }
    return result;
}


/// <summary>
/// Leet code 1960. Maximum Product of the Length of Two Palindromic 
///                 Substrings
///                                  
/// Hard
/// 
/// You are given a 0-indexed string s and are tasked with finding two 
/// non-intersecting palindromic substrings of odd length such that the 
/// product of their lengths is maximized.
///
/// More formally, you want to choose four integers i, j, k, l such that 
/// 0 <= i <= j < k <= l < s.length and both the substrings s[i...j] and 
/// s[k...l] are palindromes and have odd lengths. s[i...j] denotes a 
/// substring from index i to index j inclusive.
///
/// Return the maximum possible product of the lengths of the two 
/// non-intersecting palindromic substrings.
///
/// A palindrome is a string that is the same forward and backward. A 
/// substring is a contiguous sequence of characters in a string.
///
/// Example 1:
/// Input: s = "ababbb"
/// Output: 9
/// Explanation: Substrings "aba" and "bbb" are palindromes with 
/// odd length. product = 3 * 3 = 9.
///
/// Example 2:
/// Input: s = "zaaaxbbby"
/// Output: 9
/// Explanation: Substrings "aaa" and "bbb" are palindromes with odd 
/// length. product = 3 * 3 = 9.
/// 
/// Constraints:
/// 1. 2 <= s.length <= 10^5
/// 2. s consists of lowercase English letters.
/// </summary>
long long LeetCodeString::maxProduct(string s)
{
    int n = s.size();
    vector<int> dp = vector<int>(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(dp[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        dp[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }

    vector<int> maxL = vector<int>(n, 1);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            maxL[i] = max(maxL[i], maxL[i - 1]);

        pq.push({ -i, dp[i] });

        while (-(pq.top().first) + pq.top().second - 1 < i)
        {
            pq.pop();
        }

        maxL[i] = max(maxL[i], ((i + pq.top().first) * 2) + 1);
    }

    vector<int> maxR = vector<int>(n, 1);
    pq = priority_queue<pair<int, int>>();

    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
            maxR[i] = max(maxR[i], maxR[i + 1]);

        pq.push({ i, dp[i] });

        while (pq.top().first - (pq.top().second - 1) > i)
        {
            pq.pop();
        }

        maxR[i] = max(maxR[i], ((pq.top().first - i) * 2) + 1);
    }

    long long result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        result = max(result, (long long)maxL[i] * (long long)maxR[i + 1]);
    }
    return result;
}

/// <summary>
/// Leet code 1957. Delete Characters to Make Fancy String
///                                                
/// Easy
/// 
/// A fancy string is a string where no three consecutive characters are 
/// equal.
///
/// Given a string s, delete the minimum possible number of characters 
/// from s to make it fancy.
///
/// Return the final string after the deletion. It can be shown that the 
/// answer will always be unique.
/// 
/// Example 1:
/// Input: s = "leeetcode"
/// Output: "leetcode"
/// Explanation:
/// Remove an 'e' from the first group of 'e's to create "leetcode".
/// No three consecutive characters are equal, so return "leetcode".
///
/// Example 2:
/// Input: s = "aaabaaaa"
/// Output: "aabaa"
/// Explanation:
/// Remove an 'a' from the first group of 'a's to create "aabaaaa".
/// Remove two 'a's from the second group of 'a's to create "aabaa".
/// No three consecutive characters are equal, so return "aabaa".
///
/// Example 3:
/// Input: s = "aab"
/// Output: "aab"
/// Explanation: No three consecutive characters are equal, so 
/// return "aab".
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists only of lowercase English letters.
/// </summary>
string LeetCodeString::makeFancyString(string s)
{
    string result;
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i > 0 && s[i] == s[i - 1])
        {
            if (count < 2)
            {
                count++;
                result.push_back(s[i]);
            }
        }
        else
        {
            count = 1;
            result.push_back(s[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code 1961. Check If String Is a Prefix of Array
///                                                
/// Easy
/// 
/// Given a string s and an array of strings words, determine whether s 
/// is a prefix string of words.
///
/// A string s is a prefix string of words if s can be made by 
/// concatenating the first k strings in words for some positive k no 
/// larger than words.length.
///
/// Return true if s is a prefix string of words, or false otherwise.
/// 
/// Example 1:
/// Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
/// Output: true
/// Explanation:
/// s can be made by concatenating "i", "love", and "leetcode" together.
///
/// Example 2:
/// Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
/// Output: false
/// Explanation:
/// It is impossible to make s using a prefix of arr.
/// 
/// Constraints:
/// 1. 1 <= words.length <= 100
/// 2. 1 <= words[i].length <= 20
/// 3. 1 <= s.length <= 1000
/// 4. words[i] and s consist of only lowercase English letters.
/// </summary>
bool LeetCodeString::isPrefixString(string s, vector<string>& words)
{
    string t;
    for (size_t i = 0; i < words.size(); i++)
    {
        t.append(words[i]);
        if (s == t)
        {
            return true;
        }
        else if (t.size() > s.size())
        {
            return false;
        }
    }
    return false;
}

/// <summary>
/// Leet code 1967. Number of Strings That Appear as Substrings in Word
///                                                
/// Easy
/// 
/// Given an array of strings patterns and a string word, return the number 
/// of strings in patterns that exist as a substring in word.
///
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: patterns = ["a","abc","bc","d"], word = "abc"
/// Output: 3
/// Explanation:
/// - "a" appears as a substring in "abc".
/// - "abc" appears as a substring in "abc".
/// - "bc" appears as a substring in "abc".
/// - "d" does not appear as a substring in "abc".
/// 3 of the strings in patterns appear as a substring in word.
///
/// Example 2:
/// Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
/// Output: 2
/// Explanation:
/// - "a" appears as a substring in "aaaaabbbbb".
/// - "b" appears as a substring in "aaaaabbbbb".
/// - "c" does not appear as a substring in "aaaaabbbbb".
/// 2 of the strings in patterns appear as a substring in word.
///
/// Example 3:
/// 
/// Input: patterns = ["a","a","a"], word = "ab"
/// Output: 3
/// Explanation: Each of the patterns appears as a substring in word "ab".
///
/// Constraints:
/// 1. 1 <= patterns.length <= 100
/// 2. 1 <= patterns[i].length <= 100
/// 3. 1 <= word.length <= 100
/// 4. patterns[i] and word consist of lowercase English letters.
/// </summary>
int LeetCodeString::numOfStrings(vector<string>& patterns, string word)
{
    int result = 0;
    for (size_t i = 0; i < patterns.size(); i++)
    {
        if (strstr(word.c_str(), patterns[i].c_str()) != nullptr)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1974. Minimum Time to Type Word Using Special Typewriter
///                                                
/// Easy
/// 
/// There is a special typewriter with lowercase English letters 'a' to 
/// 'z' arranged in a circle with a pointer. A character can only be 
/// typed if the pointer is pointing to that character. The pointer is 
/// initially pointing to the character 'a'.
///
/// Each second, you may perform one of the following operations:
/// Move the pointer one character counterclockwise or clockwise.
/// Type the character the pointer is currently on.
/// Given a string word, return the minimum number of seconds to type out 
/// the characters in word.
///
/// Example 1:
/// Input: word = "abc"
/// Output: 5
/// Explanation: 
/// The characters are printed as follows:
/// - Type the character 'a' in 1 second since the pointer is initially 
///   on 'a'.
/// - Move the pointer clockwise to 'b' in 1 second.
/// - Type the character 'b' in 1 second.
/// - Move the pointer clockwise to 'c' in 1 second.
/// - Type the character 'c' in 1 second.
///
/// Example 2:
/// Input: word = "bza"
/// Output: 7
/// Explanation:
/// The characters are printed as follows:
/// - Move the pointer clockwise to 'b' in 1 second.
/// - Type the character 'b' in 1 second.
/// - Move the pointer counterclockwise to 'z' in 2 seconds.
/// - Type the character 'z' in 1 second.
/// - Move the pointer clockwise to 'a' in 1 second.
/// - Type the character 'a' in 1 second.
///
/// Example 3:
/// Input: word = "zjpc"
/// Output: 34
/// Explanation:
/// The characters are printed as follows:
/// - Move the pointer counterclockwise to 'z' in 1 second.
/// - Type the character 'z' in 1 second.
/// - Move the pointer clockwise to 'j' in 10 seconds.
/// - Type the character 'j' in 1 second.
/// - Move the pointer clockwise to 'p' in 6 seconds.
/// - Type the character 'p' in 1 second.
/// - Move the pointer counterclockwise to 'c' in 13 seconds.
/// - Type the character 'c' in 1 second.
///
/// Constraints:
/// 1. 1 <= word.length <= 100
/// 2. word consists of lowercase English letters.
/// </summary>
int LeetCodeString::minTimeToType(string word)
{
    int result = 0;
    int prev = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        int curr = word[i] - 'a';
        if (curr >= prev)
        {
            result += min(curr - prev, prev + 26 - curr);
        }
        else
        {
            result += min(prev - curr, curr + 26 - prev);
        }
        prev = curr;
        result++;
    }
    return result;
}

/// <summary>
/// Leet code 1910. Remove All Occurrences of a Substring
///                                                
/// Medium
/// 
/// Given two strings s and part, perform the following operation on s 
/// until all occurrences of the substring part are removed:
///
/// Find the leftmost occurrence of the substring part and remove it 
/// from s.
/// Return s after removing all occurrences of part.
///
/// A substring is a contiguous sequence of characters in a string.
///
/// Example 1:
///
/// Input: s = "daabcbaabcbc", part = "abc"
/// Output: "dab"
/// Explanation: The following operations are done:
/// - s = "daabcbaabcbc", remove "abc" starting at index 2, so 
///   s = "dabaabcbc".
/// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
/// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
/// Now s has no occurrences of "abc".
///
/// Example 2:
/// Input: s = "axxxxyyyyb", part = "xy"
/// Output: "ab"
/// Explanation: The following operations are done:
/// - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
/// - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
/// - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
/// - s = "axyb", remove "xy" starting at index 1 so s = "ab".
/// Now s has no occurrences of "xy".
/// 
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. 1 <= part.length <= 1000
/// 3. s and part consists of lowercase English letters.
/// </summary>
string LeetCodeString::removeOccurrences(string s, string part)
{
    string result;
    int size_p = part.size();
    for (size_t i = 0; i < s.size(); i++)
    {
        result.push_back(s[i]);
        int size_r = result.size();
        if (size_r >= size_p)
        {
            if (result.substr(size_r - size_p, size_p) == part)
            {
                result.resize(size_r - size_p);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code 2011. Final Value of Variable After Performing Operations
///                                                
/// Easy
/// 
/// There is a programming language with only four operations and one 
/// variable X:
///
/// ++X and X++ increments the value of the variable X by 1.
/// --X and X-- decrements the value of the variable X by 1.
/// Initially, the value of X is 0.
///
/// Given an array of strings operations containing a list of operations, 
/// return the final value of X after performing all the operations.
/// 
/// Example 1:
/// Input: operations = ["--X","X++","X++"]
/// Output: 1
/// Explanation: The operations are performed as follows:
/// Initially, X = 0.
/// --X: X is decremented by 1, X =  0 - 1 = -1.
/// X++: X is incremented by 1, X = -1 + 1 =  0.
/// X++: X is incremented by 1, X =  0 + 1 =  1.
///
/// Example 2:
/// Input: operations = ["++X","++X","X++"]
/// Output: 3
/// Explanation: The operations are performed as follows:
/// Initially, X = 0.
/// ++X: X is incremented by 1, X = 0 + 1 = 1.
/// ++X: X is incremented by 1, X = 1 + 1 = 2.
/// X++: X is incremented by 1, X = 2 + 1 = 3.
///
/// Example 3:
/// Input: operations = ["X++","++X","--X","X--"]
/// Output: 0
/// Explanation: The operations are performed as follows:
/// Initially, X = 0.
/// X++: X is incremented by 1, X = 0 + 1 = 1.
/// ++X: X is incremented by 1, X = 1 + 1 = 2.
/// --X: X is decremented by 1, X = 2 - 1 = 1.
/// X--: X is decremented by 1, X = 1 - 1 = 0.
/// 
/// Constraints:
/// 1. 1 <= operations.length <= 100
/// 2. operations[i] will be either "++X", "X++", "--X", or "X--".
/// </summary>
int LeetCodeString::finalValueAfterOperations(vector<string>& operations)
{
    int result = 0;
    for (size_t i = 0; i < operations.size(); i++)
    {
        if (operations[i][1] == '-') result--;
        else result++;
    }
    return result;
}

/// <summary>
/// Leet code 2027. Minimum Moves to Convert String
///                                                
/// Easy
/// 
/// You are given a string s consisting of n characters which are either 
/// 'X' or 'O'.
///
/// A move is defined as selecting three consecutive characters of s and 
/// converting them to 'O'. Note that if a move is applied to the 
/// character 'O', it will stay the same.
///
/// Return the minimum number of moves required so that all the characters
/// of s are converted to 'O'.
///
/// Example 1:
///
/// Input: s = "XXX"
/// Output: 1
/// Explanation: XXX -> OOO
/// We select all the 3 characters and convert them in one move.
///
/// Example 2:
/// Input: s = "XXOX"
/// Output: 2
/// Explanation: XXOX -> OOOX -> OOOO
/// We select the first 3 characters in the first move, and convert them 
/// to 'O'.
/// Then we select the last 3 characters and convert them so that the 
/// final string contains all 'O's.
///
/// Example 3:
/// Input: s = "OOOO"
/// Output: 0
/// Explanation: There are no 'X's in s to convert.
///
/// Constraints:
/// 1. 3 <= s.length <= 1000
/// 2. s[i] is either 'X' or 'O'.
/// </summary>
int LeetCodeString::minimumMoves(string s)
{
    size_t i = 0;
    int result = 0;
    while (i <= s.size())
    {
        if (s[i] == 'X')
        {
            result++;
            i += 3;
        }
        else
        {
            i++;
        }
    }
    return result;
}

/// <summary>
/// Leet code 2042. Check if Numbers Are Ascending in a Sentence
///                                                
/// Easy
/// 
/// A sentence is a list of tokens separated by a single space with no 
/// leading or trailing spaces. Every token is either a positive number 
/// consisting of digits 0-9 with no leading zeros, or a word consisting 
/// of lowercase English letters.
///
/// For example, "a puppy has 2 eyes 4 legs" is a sentence with seven 
/// tokens: "2" and "4" are numbers and the other tokens such as "puppy" 
/// are words.
/// Given a string s representing a sentence, you need to check if all the 
/// numbers in s are strictly increasing from left to right (i.e., other 
/// than the last number, each number is strictly smaller than the number 
/// on its right in s).
///
/// Return true if so, or false otherwise.
/// Example 1:
/// Input: s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
/// Output: true
/// Explanation: The numbers in s are: 1, 3, 4, 6, 12.
/// They are strictly increasing from left to right: 1 < 3 < 4 < 6 < 12.
///
/// Example 2:
/// Input: s = "hello world 5 x 5"
/// Output: false
/// Explanation: The numbers in s are: 5, 5. They are not strictly 
/// increasing.
///
/// Example 3:
/// Input: s = "sunset is at 7 51 pm overnight lows will be in the 
/// low 50 and 60 s"
/// Output: false
/// Explanation: The numbers in s are: 7, 51, 50, 60. They are not 
/// strictly increasing.
///
/// Example 4:
/// Input: s = "4 5 11 26"
/// Output: true
/// Explanation: The numbers in s are: 4, 5, 11, 26.
/// They are strictly increasing from left to right: 4 < 5 < 11 < 26.
///
/// Constraints:
/// 1. 3 <= s.length <= 200
/// 2. s consists of lowercase English letters, spaces, and digits 
///    from 0 to 9, inclusive.
/// 3. The number of tokens in s is between 2 and 100, inclusive.
/// 4. The tokens in s are separated by a single space.
/// 5. There are at least two numbers in s.
/// 6. Each number in s is a positive number less than 100, with no 
///    leading zeros.
/// 7. s contains no leading or trailing spaces.
/// </summary>
bool LeetCodeString::areNumbersAscending(string s)
{
    int last_num = 0;
    int num = 0;
    for (size_t i = 0; i <= s.size(); i++)
    {
        if (i == s.size() || !isdigit(s[i]))
        {
            if (num != 0)
            {
                if (num <= last_num) return false;
                last_num = num;
                num = 0;
            }
        }
        else
        {
            num = num * 10 + s[i] - '0';
        }
    }
    return true;
}

/// <summary>
/// Leet code 2047. Number of Valid Words in a Sentence
///                                                
/// Easy
/// 
/// A sentence consists of lowercase letters ('a' to 'z'), digits 
/// ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), 
/// and spaces (' ') only. Each sentence can be broken down into one or 
/// more tokens separated by one or more spaces ' '.
///
/// A token is a valid word if all three of the following are true:
///
/// It only contains lowercase letters, hyphens, and/or punctuation 
/// (no digits).
/// There is at most one hyphen '-'. If present, it must be surrounded 
/// by lowercase characters ("a-b" is valid, but "-ab" and "ab-" are 
/// not valid).
/// There is at most one punctuation mark. If present, it must be at 
/// the end of the token ("ab,", "cd!", and "." are valid, but 
/// "a!b" and "c.," are not valid).
/// Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".
///
/// Given a string sentence, return the number of valid words in sentence.
///
/// Example 1:
/// Input: sentence = "cat and  dog"
/// Output: 3
/// Explanation: The valid words in the sentence are "cat", "and", and "dog".
///
/// Example 2:
/// Input: sentence = "!this  1-s b8d!"
/// Output: 0
/// Explanation: There are no valid words in the sentence.
/// "!this" is invalid because it starts with a punctuation mark.
/// "1-s" and "b8d" are invalid because they contain digits.
///
/// Example 3:
/// Input: sentence = "alice and  bob are playing stone-game10"
/// Output: 5
/// Explanation: The valid words in the sentence are "alice", "and", 
/// "bob", "are", and "playing".
/// "stone-game10" is invalid because it contains digits.
///
/// Example 4:
/// Input: sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."
/// Output: 6
/// Explanation: The valid words in the sentence are "he", "bought", "pencils,", 
/// "erasers,", "and", and "pencil-sharpener.".
/// 
/// Constraints:
/// 1. 1 <= sentence.length <= 1000
/// 2. sentence only contains lowercase English letters, digits, ' ', '-', 
///    '!', '.', and ','.
/// 3. There will be at least 1 token.
/// </summary>
int LeetCodeString::countValidWords(string sentence)
{
    int result = 0;
    int hyphen = 0;
    int punctuation = 0;
    int letter = 0;
    bool valid = true;

    for (size_t i = 0; i <= sentence.size(); i++)
    {
        if (i == sentence.size() || isspace(sentence[i]))
        {
            if (letter > 0 || punctuation > 0)
            {
                if (valid == true) result++;
            }
            // reset all flag
            punctuation = hyphen = letter = 0;
            valid = true;
        }
        else if (sentence[i] == '!' || sentence[i] == '.' || sentence[i] == ',')
        {
            punctuation++;
            if (punctuation > 1) valid = false;
            if (i != sentence.size() - 1 && !isspace(sentence[i + 1]))
            {
                valid = false;
            }
        }
        else if (sentence[i] == '-')
        {
            hyphen++;
            if (hyphen > 1) valid = false;
            if (letter == 0) valid = false;
            if (i == sentence.size() - 1 || !isalpha(sentence[i + 1]))
            {
                valid = false;
            }
        }
        else if (sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            letter++;
        }
        else if (isdigit(sentence[i]))
        {
            valid = false;
        }
    }
    return result;
}

/// <summary>
/// Leet code 2000. Reverse Prefix of Word
///                                                
/// Easy
/// 
/// Given a 0-indexed string word and a character ch, reverse the segment 
/// of word that starts at index 0 and ends at the index of the first 
/// occurrence of ch (inclusive). If the character ch does not exist in 
/// word, do nothing.
///
/// For example, if word = "abcdefd" and ch = "d", then you should reverse 
/// the segment that starts at 0 and ends at 3 (inclusive). The resulting 
/// string will be "dcbaefd".
///
/// Return the resulting string.
/// Example 1:
/// Input: word = "abcdefd", ch = "d"
/// Output: "dcbaefd"
/// Explanation: The first occurrence of "d" is at index 3. 
/// Reverse the part of word from 0 to 3 (inclusive), the resulting 
/// string is "dcbaefd".
///
/// Example 2:
/// Input: word = "xyxzxe", ch = "z"
/// Output: "zxyxxe"
/// Explanation: The first and only occurrence of "z" is at index 3.
/// Reverse the part of word from 0 to 3 (inclusive), the resulting string 
/// is "zxyxxe".
///
/// Example 3:
/// Input: word = "abcd", ch = "z"
/// Output: "abcd"
/// Explanation: "z" does not exist in word.
/// You should not do any reverse operation, the resulting string 
/// is "abcd".
///
/// Constraints:
/// 1. 1 <= word.length <= 250
/// 2. word consists of lowercase English letters.
/// 3. ch is a lowercase English letter.
/// </summary>
string LeetCodeString::reversePrefix(string word, char ch)
{
    int index = -1;
    string result = word;
    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] == ch)
        {
            index = i + 1;
            break;
        }
    }
    if (index != -1)
    {
        reverse(result.begin(), result.begin() + index);
    }
    return result;
}

/// <summary>
/// Leet code 2019. The Score of Students Solving Math Expression
///                                                                 
/// Hard
/// 
/// You are given a string s that contains digits 0-9, addition 
/// symbols '+', and multiplication symbols '*' only, representing a valid 
/// math expression of single digit numbers (e.g., 3+5*2). This expression 
/// was given to n elementary school students. The students were 
/// instructed to get the answer of the expression by following this order 
/// of operations:
///
/// Compute multiplication, reading from left to right; Then,
/// Compute addition, reading from left to right.
/// You are given an integer array answers of length n, which are the 
/// submitted answers of the students in no particular order. You are 
/// asked to grade the answers, by following these rules:
///
/// If an answer equals the correct answer of the expression, this student 
/// will be rewarded 5 points;
/// Otherwise, if the answer could be interpreted as if the student 
/// applied the operators in the wrong order but had correct arithmetic, 
/// this student will be rewarded 2 points;
/// Otherwise, this student will be rewarded 0 points.
/// Return the sum of the points of the students.
///
/// Example 1:
/// Input: s = "7+3*1*2", answers = [20,13,42]
/// Output: 7
/// Explanation: As illustrated above, the correct answer of the expression
/// is 13, therefore one student is rewarded 5 points: [20,13,42]
/// A student might have applied the operators in this wrong order: 
/// ((7+3)*1)*2 = 20. Therefore one student is rewarded 2 
/// points: [20,13,42]
/// The points for the students are: [2,5,0]. The sum of the points 
/// is 2+5+0=7.
///
/// Example 2:
/// Input: s = "3+5*2", answers = [13,0,10,13,13,16,16]
/// Output: 19
/// Explanation: The correct answer of the expression is 13, therefore 
/// three students are rewarded 5 points each: [13,0,10,13,13,16,16]
/// A student might have applied the operators in this wrong order: 
/// ((3+5)*2 = 16. Therefore two students are rewarded 2 points: 
/// [13,0,10,13,13,16,16]
/// The points for the students are: [5,0,0,5,5,2,2]. The sum of the 
/// points is 5+0+0+5+5+2+2=19.
///
/// Example 3:
/// Input: s = "6+0*1", answers = [12,9,6,4,8,6]
/// Output: 10
/// Explanation: The correct answer of the expression is 6.
/// If a student had incorrectly done (6+0)*1, the answer would also be 6.
/// By the rules of grading, the students will still be rewarded 5 points 
/// (as they got the correct answer), not 2 points.
/// The points for the students are: [0,0,5,0,0,5]. The sum of the points 
/// is 10.
///
/// Example 4:
/// Input: s = "1+2*3+4", answers = [13,21,11,15]
/// Output: 11
/// Explanation: The correct answer of the expression is 11.
/// Every other student was rewarded 2 points because they could have 
/// applied the operators as follows:
/// - ((1+2)*3)+4 = 13
/// - (1+2)*(3+4) = 21
/// - 1+(2*(3+4)) = 15
/// The points for the students are: [2,2,5,2]. The sum of the points 
/// is 11.
/// 
/// Constraints:
/// 1. 3 <= s.length <= 31
/// 2. s represents a valid expression that contains only digits 
///    0-9, '+', and '*' only.
/// 3. All the integer operands in the expression are in the inclusive 
///    range [0, 9].
/// 4. 1 <= The count of all operators ('+' and '*') in the math 
///    expression <= 15
/// 5. Test data are generated such that the correct answer of the 
///    expression is in the range of [0, 1000].
/// 6. n == answers.length
/// 7. 1 <= n <= 10^4
/// 8. 0 <= answers[i] <= 1000
/// </summary>
int LeetCodeString::scoreOfStudents(string s, vector<int>& answers)
{
    stack<int>nums;
    stack<char> ops;
    s.push_back('#');
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) nums.push(s[i] - '0');
        else if (s[i] == '#' || s[i] == '+')
        {
            while (!ops.empty())
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                if (ops.top() == '*')
                {
                    nums.push(num1 * num2);
                }
                else
                {
                    nums.push(num1 + num2);
                }
                ops.pop();
            }
            ops.push(s[i]);
        }
        else
        {
            ops.push(s[i]);
        }
    }
    int correct = nums.top();
    int n = s.size() / 2;
    vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(n));

    for (size_t k = 0; k < s.size(); k+=2)
    {
        for (size_t i = 0; i + k < s.size(); i += 2)
        {
            if (k == 0)
            {
                dp[i / 2][i / 2].insert(s[i] - '0');
                continue;
            }
            for (size_t j = i; j < i + k; j += 2)
            {
                for (int x : dp[i / 2][j / 2])
                {
                    for (int y : dp[(j + 2) / 2][(i + k) / 2])
                    {
                        int ans = 0;
                        if (s[j + 1] == '+')
                        {
                            ans = x + y;
                        }
                        else
                        {
                            ans = x * y;
                        }
                        if (ans <= 1000)
                        dp[i / 2][(i + k) / 2].insert(ans);
                    }
                }
            }
        }
    }
    int result = 0;
    for (size_t i = 0; i < answers.size(); i++)
    {
        if (answers[i] == correct)
        {
            result += 5;
        }
        else if (dp[0][s.size() / 2-1].count(answers[i]) > 0)
        {
            result += 2;
        }
    }

    return result;
}

/// <summary>
/// Leet Code 1946. Largest Number After Mutating Substring
///                                                                 
/// Medium
/// 
/// You are given a string num, which represents a large integer. You are 
/// also given a 0-indexed integer array change of length 10 that maps 
/// each digit 0-9 to another digit. More formally, digit d maps to digit 
/// change[d].
///
/// You may choose to mutate a single substring of num. To mutate a 
/// substring, replace each digit num[i] with the digit it maps to in 
/// change (i.e. replace num[i] with change[num[i]]).
///
/// Return a string representing the largest possible integer after 
/// mutating (or choosing not to) a single substring of num.
///
/// A substring is a contiguous sequence of characters within the string.
/// 
/// Example 1:
/// Input: num = "132", change = [9,8,5,0,3,6,4,2,6,8]
/// Output: "832" 
/// Explanation: Replace the substring "1":
/// - 1 maps to change[1] = 8.
/// Thus, "132" becomes "832".
/// "832" is the largest number that can be created, so return it.
///
/// Example 2:
/// Input: num = "021", change = [9,4,3,5,7,2,1,9,0,6]
/// Output: "934"
/// Explanation: Replace the substring "021":
/// - 0 maps to change[0] = 9.
/// - 2 maps to change[2] = 3.
/// - 1 maps to change[1] = 4.
/// Thus, "021" becomes "934".
/// "934" is the largest number that can be created, so return it.
///
/// Example 3:
/// Input: num = "5", change = [1,4,7,5,3,2,5,6,9,4]
/// Output: "5"
/// Explanation: "5" is already the largest number that can be created, 
/// so return it.
///
/// Constraints:
///  1. 1 <= num.length <= 10^5
/// 2. num consists of only digits 0-9.
/// 3. change.length == 10
/// 4. 0 <= change[d] <= 9
/// </summary>
string LeetCodeString::maximumNumber(string num, vector<int>& change)
{
    string result = num;
    bool b_change = false;
    for (size_t i = 0; i < result.size(); i++)
    {
        if ((b_change == false) && (change[result[i] - '0'] <= result[i] - '0'))
        {
            continue;
        }
        else if (change[result[i] - '0'] >= result[i] - '0')
        {
            b_change = true;
            result[i] = change[result[i] - '0'] + '0';
        }
        else
        {
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1772. Sort Features by Popularity
///                                                                 
/// Medium
/// 
/// You are given a string array features where features[i] is a single 
/// word that represents the name of a feature of the latest product you 
/// are working on. You have made a survey where users have reported which 
/// features they like. You are given a string array responses, where each 
/// responses[i] is a string containing space-separated words.
///
/// The popularity of a feature is the number of responses[i] that contain 
/// the feature. You want to sort the features in non-increasing order by 
/// their popularity. If two features have the same popularity, order them 
/// by their original index in features. Notice that one response could 
/// contain the same feature multiple times; this feature is only counted 
/// once in its popularity.
///
/// Return the features in sorted order.
/// 
/// Example 1:
/// Input: features = ["cooler","lock","touch"], responses = ["i like 
/// cooler cooler","lock touch cool","locker like touch"]
/// Output: ["touch","cooler","lock"]
/// Explanation: appearances("cooler") = 1, appearances("lock") = 1, 
/// appearances("touch") = 2. Since "cooler" and "lock" both had 1 
/// appearance, "cooler" comes first because "cooler" came first in the 
/// features array.
///
/// Example 2:
/// Input: features = ["a","aa","b","c"], responses = ["a","a 
/// aa","a a a a a","b a"]
/// Output: ["a","aa","b","c"]
/// 
/// Constraints:
/// 1. 1 <= features.length <= 10^4
/// 2. 1 <= features[i].length <= 10
/// 3. features contains no duplicates.
/// 4. features[i] consists of lowercase letters.
/// 5. 1 <= responses.length <= 10^2
/// 6. 1 <= responses[i].length <= 10^3
/// 7. responses[i] consists of lowercase letters and spaces.
/// 8. responses[i] contains no two consecutive spaces.
/// 9. responses[i] has no leading or trailing spaces.
/// </summary>
vector<string> LeetCodeString::sortFeatures(vector<string>& features, vector<string>& responses)
{
    unordered_map<string, pair<int, int>> feature_count;

    for (size_t i = 0; i < features.size(); i++)
    {
        feature_count[features[i]].first = i;
    }
    for (size_t i = 0; i < responses.size(); i++)
    {
        string token;
        unordered_set<string> words;
        for (size_t j = 0; j <= responses[i].size(); j++)
        {
            if (j == responses[i].size() || isspace(responses[i][j]))
            {
                if (feature_count.count(token) > 0)
                {
                    words.insert(token);
                }
                token.clear();
            }
            else
            {
                token.push_back(responses[i][j]);
            }
        }
        for (auto& w : words)
        {
            feature_count[w].second++;
        }
    }
    priority_queue<pair<int, int>> pq;
    for (auto& itr : feature_count)
    {
        pq.push(make_pair(itr.second.second, -itr.second.first));
    }
    vector<string> result;
    while (!pq.empty())
    {
        auto itr = pq.top();
        pq.pop();
        result.push_back(features[0-itr.second]);
    }
    return result;
}

/// <summary>
/// Leet Code 2085. Count Common Words With One Occurrence
///                                                                 
/// Easy
/// 
/// Given two string arrays words1 and words2, return the number of 
/// strings that appear exactly once in each of the two arrays.
/// 
/// Example 1:
/// Input: words1 = ["leetcode","is","amazing","as","is"], 
/// words2 = ["amazing","leetcode","is"]
/// Output: 2
/// Explanation:
/// - "leetcode" appears exactly once in each of the two arrays. We 
///   count this string.
/// - "amazing" appears exactly once in each of the two arrays. We count 
///   this string.
/// - "is" appears in each of the two arrays, but there are 2 occurrences 
///   of it in words1. We do not count this string.
/// - "as" appears once in words1, but does not appear in words2. We do 
///   not count this string.
/// Thus, there are 2 strings that appear exactly once in each of the 
/// two arrays.
///
/// Example 2:
/// Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
/// Output: 0
/// Explanation: There are no strings that appear in each of the 
/// two arrays.
///
/// Example 3:
/// Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
/// Output: 1
/// Explanation: The only string that appears exactly once in each of 
/// the two arrays is "ab".
/// 
/// Constraints:
/// 1. 1 <= words1.length, words2.length <= 1000
/// 2. 1 <= words1[i].length, words2[j].length <= 30
/// 3. words1[i] and words2[j] consists only of lowercase English letters.
/// </summary>
int LeetCodeString::countWords(vector<string>& words1, vector<string>& words2)
{
    int result = 0;
    unordered_map<string, int> word1_count;
    for (size_t i = 0; i < words1.size(); i++)
    {
        string token;
        unordered_set<string> words;
        for (size_t j = 0; j <= words1[i].size(); j++)
        {
            if (j == words1[i].size() || isspace(words1[i][j]))
            {
                word1_count[token]++;
                token.clear();
            }
            else
            {
                token.push_back(words1[i][j]);
            }
        }
    }
    unordered_map<string, int> word2_count;
    for (size_t i = 0; i < words2.size(); i++)
    {
        string token;
        unordered_set<string> words;
        for (size_t j = 0; j <= words2[i].size(); j++)
        {
            if (j == words2[i].size() || isspace(words2[i][j]))
            {
                word2_count[token]++;
                token.clear();
            }
            else
            {
                token.push_back(words2[i][j]);
            }
        }
    }
    for (auto& itr : word1_count)
    {
        if (itr.second == 1 && word2_count[itr.first] == 1)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2068. Check Whether Two Strings are Almost Equivalent
///                                                                 
/// Easy
/// 
/// Two strings word1 and word2 are considered almost equivalent if the 
/// differences between the frequencies of each letter from 'a' to 'z' 
/// between word1 and word2 is at most 3.
///
/// Given two strings word1 and word2, each of length n, return true if 
/// word1 and word2 are almost equivalent, or false otherwise.
///
/// The frequency of a letter x is the number of times it occurs in the 
/// string.
/// 
/// Example 1:
/// Input: word1 = "aaaa", word2 = "bccb"
/// Output: false
/// Explanation: There are 4 'a's in "aaaa" but 0 'a's in "bccb".
/// The difference is 4, which is more than the allowed 3.
///
/// Example 2:
/// Input: word1 = "abcdeef", word2 = "abaaacc"
/// Output: true
/// Explanation: The differences between the frequencies of each letter 
/// in word1 and word2 are at most 3:
/// - 'a' appears 1 time in word1 and 4 times in word2. The difference 
///   is 3.
/// - 'b' appears 1 time in word1 and 1 time in word2. The difference 
///   is 0.
/// - 'c' appears 1 time in word1 and 2 times in word2. The difference 
///   is 1.
/// - 'd' appears 1 time in word1 and 0 times in word2. The difference 
///   is 1.
/// - 'e' appears 2 times in word1 and 0 times in word2. The difference 
///   is 2.
/// - 'f' appears 1 time in word1 and 0 times in word2. The difference 
///   is 1.
///
/// Example 3:
/// Input: word1 = "cccddabba", word2 = "babababab"
/// Output: true
/// Explanation: The differences between the frequencies of each letter 
/// in word1 and word2 are at most 3:
/// - 'a' appears 2 times in word1 and 4 times in word2. The difference 
///   is 2.
/// - 'b' appears 2 times in word1 and 5 times in word2. The difference 
///   is 3.
/// - 'c' appears 3 times in word1 and 0 times in word2. The difference 
///   is 3.
/// - 'd' appears 2 times in word1 and 0 times in word2. The difference 
///   is 2.
///
/// Constraints:
/// 1. n == word1.length == word2.length
/// 2. 1 <= n <= 100
/// 3. word1 and word2 consist only of lowercase English letters.
/// </summary>
bool LeetCodeString::checkAlmostEquivalent(string word1, string word2)
{
    vector<int> char1_count(26), char2_count(26);
    for (size_t i = 0; i < word1.size(); i++)
    {
        char1_count[word1[i] - 'a']++;
    }
    for (size_t i = 0; i < word2.size(); i++)
    {
        char2_count[word2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (abs(char1_count[i] - char2_count[i]) > 3)
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet Code 1933. Check if String Is Decomposable Into Value-Equal 
///                 Substrings
/// </summary>
bool LeetCodeString::isDecomposable(string s, int start, bool twoUsed)
{
    if (start == s.size())
    {
        if (twoUsed) return true;
        else return false;
    }
    if (twoUsed)
    {
        if ((s.size() - start) % 3 != 0)
        {
            return false;
        }
        for (size_t i = start; i < s.size(); i += 3)
        {
            if (s[i] != s[i + 1] || s[i] != s[i + 2])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        if (start < (int)s.size() - 1 && s[start] == s[start + 1])
        {
            bool result = isDecomposable(s, start + 2, true);
            if (result) return true;
        }
        if (start < (int)s.size() - 2 && s[start] == s[start + 1] && s[start] == s[start + 2])
        {
            return isDecomposable(s, start + 3, false);
        }
        else
        {
            return false;
        }
    }
}

/// <summary>
/// Leet Code 1933. Check if String Is Decomposable Into Value-Equal 
///                 Substrings
///                                                                 
/// Easy
/// 
/// A value-equal string is a string where all characters are the same.
///
/// For example, "1111" and "33" are value-equal strings.
/// In contrast, "123" is not a value-equal string.
/// Given a digit string s, decompose the string into some number of 
/// consecutive value-equal substrings where exactly one substring has 
/// a length of 2 and the remaining substrings have a length of 3.
///
/// Return true if you can decompose s according to the above rules. 
/// Otherwise, return false.
///
/// A substring is a contiguous sequence of characters in a string.
///
/// Example 1:
/// Input: s = "000111000" 
/// Output: false
/// Explanation: s cannot be decomposed according to the rules because 
/// ["000", "111", "000"] does not have a substring of length 2.
///
/// Example 2:
/// Input: s = "00011111222"
/// Output: true
/// Explanation: s can be decomposed into ["000", "111", "11", "222"].
///
/// Example 3:
/// Input: s = "011100022233"
/// Output: false
/// Explanation: s cannot be decomposed according to the rules because 
/// of the first '0'.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s consists of only digits '0' through '9'.
/// </summary>
bool LeetCodeString::isDecomposable(string s)
{
    return isDecomposable(s, 0, false);
}


/// <summary>
/// Leet Code 1858. Longest Word With All Prefixes
///                                                                 
/// Medium
///
/// Given an array of strings words, find the longest string in words such 
/// that every prefix of it is also in words.
/// 
/// For example, let words = ["a", "app", "ap"]. The string "app" has 
/// prefixes "ap" and "a", all of which are in words.
/// Return the string described above. If there is more than one string 
/// with the same length, return the lexicographically smallest one, and 
/// if no string exists, return "".
/// 
/// Example 1:
/// Input: words = ["k","ki","kir","kira", "kiran"]
/// Output: "kiran"
/// Explanation: "kiran" has prefixes "kira", "kir", "ki", and "k", and 
/// all of them appear in words.
///
/// Example 2:
/// Input: words = ["a", "banana", "app", "appl", "ap", "apply", "apple"] 
/// Output: "apple"
/// Explanation: Both "apple" and "apply" have all their prefixes in words.
/// However, "apple" is lexicographically smaller, so we return that.
///
/// Example 3:
/// Input: words = ["abc", "bc", "ab", "qwe"]
/// Output: ""
/// 
/// Constraints:
/// 1. 1 <= words.length <= 10^5
/// 2. 1 <= words[i].length <= 10^5
/// 3. 1 <= sum(words[i].length) <= 10^5
/// </summary>
string LeetCodeString::longestWordII(vector<string>& words)
{
    map<int, vector<int>> word_map;
    unordered_set<string> hash_set;
    for (size_t i = 0; i < words.size(); i++)
    {
        word_map[words[i].size()].push_back(i);
    }
    hash_set.insert("");

    int length = 0;
    string result;
    while (true)
    {
        length++;
        bool found = false;
        for (auto i : word_map[length])
        {
            if (hash_set.count(words[i].substr(0, words[i].size() - 1)) > 0)
            {
                found = true;
                hash_set.insert(words[i]);
                if (length > (int)result.size() || words[i] < result)
                {
                    result = words[i];
                }
            }
        }
        if (found == false) break;
    }
    return result;
}

/// <summary>
/// Leet Code 2038. Remove Colored Pieces if Both Neighbors are the Same 
///                 Color
///                                                                 
/// Medium
///
/// There are n pieces arranged in a line, and each piece is colored 
/// either by 'A' or by 'B'. You are given a string colors of length n 
/// where colors[i] is the color of the ith piece.
///
/// Alice and Bob are playing a game where they take alternating turns 
/// removing pieces from the line. In this game, Alice moves first.
///
/// Alice is only allowed to remove a piece colored 'A' if both its 
/// neighbors are also colored 'A'. She is not allowed to remove pieces 
/// that are colored 'B'.
/// Bob is only allowed to remove a piece colored 'B' if both its 
/// neighbors are also colored 'B'. He is not allowed to remove pieces 
/// that are colored 'A'.
/// Alice and Bob cannot remove pieces from the edge of the line.
/// If a player cannot make a move on their turn, that player loses and 
/// the other player wins.
/// Assuming Alice and Bob play optimally, return true if Alice wins, or 
/// return false if Bob wins.
/// 
/// Example 1:
/// Input: colors = "AAABABB"
/// Output: true
/// Explanation:
/// AAABABB -> AABABB
/// Alice moves first.
/// She removes the second 'A' from the left since that is the only 'A' 
/// whose neighbors are both 'A'.
///
/// Now it's Bob's turn.
/// Bob cannot make a move on his turn since there are no 'B's whose 
/// neighbors are both 'B'.
/// Thus, Alice wins, so return true.
///
/// Example 2:
/// Input: colors = "AA"
/// Output: false
/// Explanation:
/// Alice has her turn first.
/// There are only two 'A's and both are on the edge of the line, so she 
/// cannot move on her turn.
/// Thus, Bob wins, so return false.
///
/// Example 3:
/// Input: colors = "ABBBBBBBAAA"
/// Output: false
/// Explanation:
/// ABBBBBBBAAA -> ABBBBBBBAA
/// Alice moves first.
/// Her only option is to remove the second to last 'A' from the right.
///
/// ABBBBBBBAA -> ABBBBBBAA
/// Next is Bob's turn.
/// He has many options for which 'B' piece to remove. He can pick any.
///
/// On Alice's second turn, she has no more pieces that she can remove.
/// Thus, Bob wins, so return false.
/// 
/// Constraints:
/// 1. 1 <= colors.length <= 10^5
/// 2. colors consists of only the letters 'A' and 'B'
/// </summary>
bool LeetCodeString::winnerOfGame(string colors)
{
    int countA = 0;
    int countB = 0;
    int prevA = 0;
    int prevB = 0;
    for (size_t i = 0; i < colors.size(); i++)
    {
        if (colors[i] == 'A')
        {
            prevA++;
            if (prevA > 2) countA++;
            prevB = 0;
        }
        else 
        {
            prevB++;
            if (prevB > 2) countB++;
            prevA = 0;
        }
    }
    if (countA > countB) return true;
    else return false;
}

/// <summary>
/// Leet Code 1963. Minimum Number of Swaps to Make the String Balanced
///                                                                 
/// Medium
///
/// You are given a 0-indexed string s of even length n. The string 
/// consists of exactly n / 2 opening brackets '[' and n / 2 closing 
/// brackets ']'.
///
/// A string is called balanced if and only if:
///
/// It is the empty string, or
/// It can be written as AB, where both A and B are balanced strings, or
/// It can be written as [C], where C is a balanced string.
/// You may swap the brackets at any two indices any number of times.
///
/// Return the minimum number of swaps to make s balanced.
///
/// Example 1:
/// Input: s = "][]["
/// Output: 1
/// Explanation: You can make the string balanced by swapping index 0 with
/// index 3. 
/// The resulting string is "[[]]".
/// 
/// Example 2:
/// Input: s = "]]][[["
/// Output: 2
/// Explanation: You can do the following to make the string balanced:
/// - Swap index 0 with index 4. s = "[]][][".
/// - Swap index 1 with index 5. s = "[[][]]".
/// The resulting string is "[[][]]".
///
/// Example 3:
/// Input: s = "[]"
/// Output: 0
/// Explanation: The string is already balanced.
/// 
/// Constraints:
/// 1. n == s.length
/// 2. 2 <= n <= 10^6
/// 3. n is even.
/// 4. s[i] is either '[' or ']'.
/// 5. The number of opening brackets '[' equals n / 2, and the number 
///    of closing brackets ']' equals n / 2.
/// </summary>
int LeetCodeString::minSwaps(string s)
{
    int result = 0;
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count < 0)
        {
            count = 0;
            result++;
        }
    }
    return (result + 1) / 2;
}

/// <summary>
/// Leet Code 2108. Find First Palindromic String in the Array
///                                                                 
/// Easy
///
/// Given an array of strings words, return the first palindromic string
/// in the array. If there is no such string, return an empty string "".
///
/// A string is palindromic if it reads the same forward and backward.
///
/// Example 1:
/// Input: words = ["abc","car","ada","racecar","cool"]
/// Output: "ada"
/// Explanation: The first string that is palindromic is "ada".
/// Note that "racecar" is also palindromic, but it is not the first.
///
/// Example 2:
/// Input: words = ["notapalindrome","racecar"]
/// Output: "racecar"
/// Explanation: The first and only string that is palindromic is 
/// "racecar".
///
/// Example 3:
/// Input: words = ["def","ghi"]
/// Output: ""
/// Explanation: There are no palindromic strings, so the empty string is 
/// returned.
///
/// Constraints:
/// 1. 1 <= words.length <= 100
/// 2. 1 <= words[i].length <= 100
/// 3. words[i] consists only of lowercase English letters.
/// </summary>
string LeetCodeString::firstPalindrome(vector<string>& words)
{
    for (size_t i = 0; i < words.size(); i++)
    {
        if (isPalindrome(words[i]))
        {
            return words[i];
        }
    }
    return "";
}

/// <summary>
/// Leet Code 2023. Number of Pairs of Strings With Concatenation Equal to 
///                 Target
///                                                                 
/// Medium
///
/// Given an array of digit strings nums and a digit string target, return 
/// the number of pairs of indices (i, j) (where i != j) such that the 
/// concatenation of nums[i] + nums[j] equals target.
///
/// Example 1:
/// Input: nums = ["777","7","77","77"], target = "7777"
/// Output: 4
/// Explanation: Valid pairs are:
/// - (0, 1): "777" + "7"
/// - (1, 0): "7" + "777"
/// - (2, 3): "77" + "77"
/// - (3, 2): "77" + "77"
///
/// Example 2:
/// Input: nums = ["123","4","12","34"], target = "1234"
/// Output: 2
/// Explanation: Valid pairs are:
/// - (0, 1): "123" + "4"
/// - (2, 3): "12" + "34"
///
/// Example 3:
/// Input: nums = ["1","1","1"], target = "11"
/// Output: 6
/// Explanation: Valid pairs are:
/// - (0, 1): "1" + "1"
/// - (1, 0): "1" + "1"
/// - (0, 2): "1" + "1"
/// - (2, 0): "1" + "1"
/// - (1, 2): "1" + "1"
/// - (2, 1): "1" + "1"
/// 
/// Constraints:
/// 1. 2 <= nums.length <= 100
/// 2. 1 <= nums[i].length <= 100
/// 3. 2 <= target.length <= 100
/// 4. nums[i] and target consist of digits.
/// 5. nums[i] and target do not have leading zeros.
/// </summary>
int LeetCodeString::numOfPairs(vector<string>& nums, string target)
{
    unordered_map<string, int> str_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        str_map[nums[i]]++;
    }
    int result = 0;
    for (auto itr : str_map)
    {
        if (target.substr(0, itr.first.size()) == itr.first)
        {
            string next = target.substr(itr.first.size());
            if (next.empty() || str_map.count(next) == 0) continue;
            if (itr.first == next)
            {
                result += itr.second * (itr.second - 1);
            }
            else
            {
                result += itr.second * str_map[next];
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 20. Valid Parentheses
///                                                                 
/// Easy
///
/// Given a string s containing just the characters '(', ')', '{', '}', 
/// '[' and ']', determine if the input string is valid.
///
/// An input string is valid if:
/// 
/// Open brackets must be closed by the same type of brackets.
/// Open brackets must be closed in the correct order.
///
/// Example 1:
/// Input: s = "()"
/// Output: true
///
/// Example 2:
/// Input: s = "()[]{}"
/// Output: true
///
/// Example 3:
/// Input: s = "(]"
/// Output: false
///
/// Constraints:
/// 1. 1 <= s.length <= 10^4 
/// 2. s consists of parentheses only '()[]{}'.
/// </summary>
bool LeetCodeString::isValidParentheses(string s)
{
    stack<char> stack;
    for (size_t i = 0; i < s.size(); i++)
    {
        if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
        {
            stack.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if ((!stack.empty()) && (stack.top() == '('))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if ((!stack.empty()) && (stack.top() == '['))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '}')
        {
            if ((!stack.empty()) && (stack.top() == '{'))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (stack.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet Code 32. Longest Valid Parentheses
///                                                                 
/// Hard
///
/// Given a string containing just the characters '(' and ')', find the 
/// length of the longest valid (well-formed) parentheses substring.
/// 
/// Example 1:
/// Input: s = "(()"
/// Output: 2
/// Explanation: The longest valid parentheses substring is "()".
///
/// Example 2:
/// Input: s = ")()())"
/// Output: 4
/// Explanation: The longest valid parentheses substring is "()()".
///
/// Example 3:
/// Input: s = ""
/// Output: 0
/// 
/// Constraints:
/// 1. 0 <= s.length <= 3 * 10^4
/// 2. s[i] is '(', or ')'
/// </summary>
int LeetCodeString::longestValidParentheses(string s)
{
    vector<int> dp(s.size());
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') count++;
        else count--;
        if (count < 0)
        {
            count = 0;
            dp[i] = -1;
        }
    }
    count = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ')') count++;
        else count--;
        if (count < 0)
        {
            count = 0;
            dp[i] = -1;
        }
    }
    int result = 0;
    count = 0;
    for (size_t i = 0; i < dp.size(); i++)
    {
        if (dp[i] == -1) count = 0;
        else
        {
            count++;
            result = max(result, count);
        }
    }
    return result;
}

/// <summary>
/// Leet code #921. Minimum Add to Make Parentheses Valid
/// 
/// Given a string S of '(' and ')' parentheses, we add the minimum number of 
/// parentheses ( '(' or ')', and in any positions ) so that the resulting 
/// parentheses string is valid.
///
/// Formally, a parentheses string is valid if and only if:
///
/// It is the empty string, or
/// It can be written as AB (A concatenated with B), where A and B are valid 
/// strings, or
/// It can be written as (A), where A is a valid string.
/// Given a parentheses string, return the minimum number of parentheses we 
/// must add to make the resulting string valid.
///
/// Example 1:
/// Input: "())"
/// Output: 1
///
/// Example 2:
/// Input: "((("
/// Output: 3
///
/// Example 3:
/// Input: "()"
/// Output: 0
/// Example 4:
///
/// Input: "()))(("
/// Output: 4
/// 
/// Note:
///
/// 1. S.length <= 1000
/// 2. S only consists of '(' and ')' characters.
/// </summary>
int LeetCodeString::minAddToMakeValid(string S)
{
    int result = 0;
    int count = 0;
    for (int i = 0; i < (int)S.size(); i++)
    {
        if (S[i] == '(') count++;
        else count--;
        if (count < 0)
        {
            result++;
            count = 0;
        }
    }
    count = 0;
    for (int i = S.size() - 1; i >= 0; i--)
    {
        if (S[i] == ')') count++;
        else count--;
        if (count < 0)
        {
            result++;
            count = 0;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1249. Minimum Remove to Make Valid Parentheses
///  
/// Given a string s of '(' , ')' and lowercase English characters. 
///
/// Your task is to remove the minimum number of parentheses ( '(' or ')', 
/// in any positions ) so that the resulting parentheses string is valid 
/// and return any valid string.
///
/// Formally, a parentheses string is valid if and only if:
///
/// It is the empty string, contains only lowercase characters, or
/// It can be written as AB (A concatenated with B), where A and B are valid 
/// strings, or It can be written as (A), where A is a valid string.
/// 
/// Example 1:
///
/// Input: s = "lee(t(c)o)de)"
/// Output: "lee(t(c)o)de"
/// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
///
/// Example 2:
///
/// Input: s = "a)b(c)d"
/// Output: "ab(c)d"
///
/// Example 3:
///
/// Input: s = "))(("
/// Output: ""
/// Explanation: An empty string is also valid.
///
/// Example 4:
///
/// Input: s = "(a(b(c)d)"
/// Output: "a(b(c)d)"
/// 
/// Constraints:
///
/// 1. 1 <= s.length <= 10^5
/// 2. s[i] is one of  '(' , ')' and lowercase English letters.
/// </summary>
string LeetCodeString::minRemoveToMakeValid(string s)
{
    int count = 0;
    string str = s;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') count++;
        else if (str[i] == ')')
        {
            if (count == 0) str[i] = '*';
            else count--;
        }
    }
    count = 0;
    for (int i = (int)str.size() - 1; i >= 0; i--)
    {
        if (str[i] == ')') count++;
        else if (str[i] == '(')
        {
            if (count == 0) str[i] = '*';
            else count--;
        }
    }
    string result;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '*') continue;
        result.push_back(str[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 2109. Adding Spaces to a String
///                                                                 
/// Medium
///
/// You are given a 0-indexed string s and a 0-indexed integer array 
/// spaces that describes the indices in the original string where 
/// spaces will be added. Each space should be inserted before the 
/// character at the given index.
///
/// For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], 
/// we place spaces before 'Y' and 'C', which are at indices 5 and 9 
/// respectively. Thus, we obtain "Enjoy Your Coffee".
/// Return the modified string after the spaces have been added.
/// 
/// Example 1:
/// Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
/// Output: "Leetcode Helps Me Learn"
/// Explanation: 
/// The indices 8, 13, and 15 correspond to the underlined characters 
/// in "LeetcodeHelpsMeLearn".
/// We then place spaces before those characters.
///
/// Example 2:
/// Input: s = "icodeinpython", spaces = [1,5,7,9]
/// Output: "i code in py thon"
/// Explanation:
/// The indices 1, 5, 7, and 9 correspond to the underlined characters 
/// in "icodeinpython".
/// We then place spaces before those characters.
///
/// Example 3:
/// Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
/// Output: " s p a c i n g"
/// Explanation:
/// We are also able to place spaces before the first character of the 
/// string.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 3 * 10^5
/// 2. s consists only of lowercase and uppercase English letters.
/// 3. 1 <= spaces.length <= 3 * 10^5
/// 4. 0 <= spaces[i] <= s.length - 1
/// 5. All the values of spaces are strictly increasing.
/// </summary>
string LeetCodeString::addSpaces(string s, vector<int>& spaces)
{
    string result;
    int index = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (index < (int)spaces.size() && i == spaces[index])
        {
            result.push_back(' ');
            index++;
        }
        result.push_back(s[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 2067. Number of Equal Count Substrings
///                                                                 
/// Medium
///
/// You are given a 0-indexed string s consisting of only lowercase 
/// English letters, and an integer count. A substring of s is said 
/// to be an equal count substring if, for each unique letter in the 
/// substring, it appears exactly count times in the substring.
///
/// Return the number of equal count substrings in s.
/// A substring is a contiguous non-empty sequence of characters 
/// within a string.
/// 
/// Example 1:
/// Input: s = "aaabcbbcc", count = 3
/// Output: 3
/// Explanation:
/// The substring that starts at index 0 and ends at index 2 is "aaa".
/// The letter 'a' in the substring appears exactly 3 times.
/// The substring that starts at index 3 and ends at index 8 is "bcbbcc".
/// The letters 'b' and 'c' in the substring appear exactly 3 times.
/// The substring that starts at index 0 and ends at index 8 
/// is "aaabcbbcc".
/// The letters 'a', 'b', and 'c' in the substring appear exactly 3 times.
///
/// Example 2:
/// Input: s = "abcd", count = 2
/// Output: 0
/// Explanation:
/// The number of times each letter appears in s is less than count.
/// Therefore, no substrings in s are equal count substrings, so return 0.
///
/// Example 3:
/// Input: s = "a", count = 5
/// Output: 0
/// Explanation:
/// The number of times each letter appears in s is less than count.
/// Therefore, no substrings in s are equal count substrings, so return 0
/// 
/// Constraints:
/// 1. 1 <= s.length <= 3 * 10^4
/// 2. 1 <= count <= 3 * 10^4
/// 3. s consists only of lowercase English letters.
/// </summary>
int LeetCodeString::equalCountSubstrings(string s, int count)
{
    int size = unordered_set<char>(s.begin(), s.end()).size();
    int result = 0;
    for (int i = 1; i <= size; i++)
    {
        int first = 0;
        vector<int> char_count(26);
        int unique = 0;
        for (int last = 0; last < (int)s.size(); last++)
        {
            char_count[s[last] - 'a']++;
            if (char_count[s[last] - 'a'] == count) unique++;
            if (unique == i) result++;
            if (last - first + 1 == i * count)
            {
                char_count[s[first] - 'a']--;
                if (char_count[s[first] - 'a'] == count - 1) unique--;
                first++;
            }
        }
    }
    return result;
}


/// <summary>
/// Leet Code 2083. Substrings That Begin and End With the Same Letter
///                                                                 
/// Medium
///
/// You are given a 0-indexed string s consisting of only lowercase 
/// English letters. Return the number of substrings in s that begin 
/// and end with the same character.
///
/// A substring is a contiguous non-empty sequence of characters within 
/// a string.
/// 
/// Example 1:
/// Input: s = "abcba"
/// Output: 7
/// Explanation:
/// The substrings of length 1 that start and end with the same letter 
/// are: "a", "b", "c", "b", and "a".
/// The substring of length 3 that starts and ends with the same letter 
/// is: "bcb".
/// The substring of length 5 that starts and ends with the same letter 
/// is: "abcba".
///
/// Example 2:
/// Input: s = "abacad"
/// Output: 9
/// Explanation:
/// The substrings of length 1 that start and end with the same letter 
/// are: "a", "b", "a", "c", "a", and "d".
/// The substrings of length 3 that start and end with the same letter 
/// are: "aba" and "aca".
/// The substring of length 5 that starts and ends with the same letter 
/// is: "abaca".
///
/// Example 3:
/// Input: s = "a"
/// Output: 1
/// Explanation:
/// The substring of length 1 that starts and ends with the same letter 
/// is: "a".
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists only of lowercase English letters.
/// </summary>
long long LeetCodeString::numberOfSubstringsII(string s)
{
    vector<int>char_count(26);
    long long result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        char_count[s[i] - 'a']++;
        result += (long long)char_count[s[i] - 'a'];
    }
    return result;
}

/// <summary>
/// Leet Code 2114. Maximum Number of Words Found in Sentences
///                                                                 
/// Easy
///
/// A sentence is a list of words that are separated by a single space 
/// with no leading or trailing spaces.
///
/// You are given an array of strings sentences, where each sentences[i] 
/// represents a single sentence.
///
/// Return the maximum number of words that appear in a single sentence.
/// 
/// Example 1:
/// Input: sentences = ["alice and bob love leetcode", "i think so too", 
/// "this is great thanks very much"]
/// Output: 6
/// Explanation: 
/// - The first sentence, "alice and bob love leetcode", 
///   has 5 words in total.
/// - The second sentence, "i think so too", has 4 words in total.
/// - The third sentence, "this is great thanks very much", 
///   has 6 words in total.
/// Thus, the maximum number of words in a single sentence comes from 
/// the third sentence, which has 6 words.
/// Example 2:
/// Input: sentences = ["please wait", "continue to fight", 
///        "continue to win"]
/// Output: 3
/// Explanation: It is possible that multiple sentences contain the 
/// same number of words. 
/// In this example, the second and third sentences (underlined) have 
/// the same number of words.
///
/// Constraints:
/// 1. 1 <= sentences.length <= 100
/// 2. 1 <= sentences[i].length <= 100
/// 3. sentences[i] consists only of lowercase English letters 
///    and ' ' only.
/// 4. sentences[i] does not have leading or trailing spaces.
/// 5. All the words in sentences[i] are separated by a single space.
/// </summary>
int LeetCodeString::mostWordsFound(vector<string>& sentences)
{
    int result = 0;
    for (size_t i = 0; i < sentences.size(); i++)
    {
        int count = 0;
        for (size_t j = 0; j < sentences[i].size(); j++)
        {
            if (isspace(sentences[i][j]))
            {
                count++;
            }
        }
        result = max(result, count + 1);
    }
    return result;
}

/// <summary>
/// Leet Code 2116. Check if a Parentheses String Can Be Valid
///                                                                 
/// Medium
///
/// A parentheses string is a non-empty string consisting only of '(' 
/// and ')'. It is valid if any of the following conditions is true:
///
/// It is ().
/// It can be written as AB (A concatenated with B), where A and B 
/// are valid parentheses strings.
/// It can be written as (A), where A is a valid parentheses string.
/// You are given a parentheses string s and a string locked, both of 
/// length n. locked is a binary string consisting only of '0's and '1's. 
/// For each index i of locked,
///
/// If locked[i] is '1', you cannot change s[i].
/// But if locked[i] is '0', you can change s[i] to either '(' or ')'.
/// Return true if you can make s a valid parentheses string. Otherwise, 
/// return false.
/// 
/// Example 1:
/// Input: s = "))()))", locked = "010100"
/// Output: true
/// Explanation: locked[1] == '1' and locked[3] == '1', so we cannot 
/// change s[1] or s[3].
/// We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged 
/// to make s valid.
///
/// Example 2:
/// Input: s = "()()", locked = "0000"
/// Output: true
/// Explanation: We do not need to make any changes because s is already 
/// valid.
///
/// Example 3:
/// Input: s = ")", locked = "0"
/// Output: false
/// Explanation: locked permits us to change s[0]. 
/// Changing s[0] to either '(' or ')' will not make s valid.
/// 
/// Constraints:
/// 1. n == s.length == locked.length
/// 2. 1 <= n <= 10^5
/// 3. s[i] is either '(' or ')'.
/// 4. locked[i] is either '0' or '1'.
/// </summary>
bool LeetCodeString::canBeValid(string s, string locked)
{
    deque<int> free;
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') count++;
        else
        {
            if (locked[i] == '0') free.push_back(i);
            count--;
        }
        if (count < 0)
        {
            if (free.empty()) return false;
            int k = free.back();
            free.pop_back();
            s[k] = '(';
            count += 2;
        }
    }
    free.clear();
    count = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ')') count++;
        else
        {
            if (locked[i] == '0') free.push_back(i);
            count--;
        }
        if (count < 0)
        {
            if (free.empty()) return false;
            int k = free.back();
            free.pop_back();
            s[k] = '(';
            count += 2;
        }
    }
    if (count == 0) return true;
    else return false;
}

/// <summary>
/// Leet Code 2124. Check if All A's Appears Before All B's
///                                                                 
/// Easy
///
/// Given a string s consisting of only the characters 'a' and 'b', return 
/// true if every 'a' appears before every 'b' in the string. Otherwise, 
/// return false.
///
/// Example 1:
/// Input: s = "aaabbb"
/// Output: true
/// Explanation:
/// The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 
/// 3, 4, and 5.
/// Hence, every 'a' appears before every 'b' and we return true.
///
/// Example 2:
/// Input: s = "abab"
/// Output: false 
/// Explanation:
/// There is an 'a' at index 2 and a 'b' at index 1.
/// Hence, not every 'a' appears before every 'b' and we return false.
///
/// Example 3:
/// Input: s = "bbb"
/// Output: true
/// Explanation:
/// There are no 'a's, hence, every 'a' appears before every 'b' and we 
/// return true.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s[i] is either 'a' or 'b'.
/// </summary>
bool LeetCodeString::checkString(string s)
{
    bool is_b = false;
    for (auto ch: s)
    {
        if (ch == 'b') is_b = true;
        else if (is_b == true) return false;
    }
    return true;
}

/// <summary>
/// Leet Code 2129. Capitalize the Title
///                                                                 
/// Easy
///
/// You are given a string title consisting of one or more words separated 
/// by a single space, where each word consists of English letters. 
/// Capitalize the string by changing the capitalization of each word such 
/// that:
///
/// If the length of the word is 1 or 2 letters, change all letters to 
/// lowercase.
/// Otherwise, change the first letter to uppercase and the remaining 
/// letters to lowercase.
/// Return the capitalized title.
///
/// Example 1:
/// Input: title = "capiTalIze tHe titLe"
/// Output: "Capitalize The Title"
/// Explanation:
/// Since all the words have a length of at least 3, the first letter of 
/// each word is uppercase, and the remaining letters are lowercase.
///
/// Example 2:
/// Input: title = "First leTTeR of EACH Word"
/// Output: "First Letter of Each Word"
/// Explanation:
/// The word "of" has length 2, so it is all lowercase.
/// The remaining words have a length of at least 3, so the first letter 
/// of each remaining word is uppercase, and the remaining letters are 
/// lowercase.
///
/// Example 3:
/// Input: title = "i lOve leetcode"
/// Output: "i Love Leetcode"
/// Explanation:
/// The word "i" has length 1, so it is lowercase.
/// The remaining words have a length of at least 3, so the first letter 
/// of each remaining word is uppercase, and the remaining letters are 
/// lowercase.
///   
/// Constraints:
/// 1. 1 <= title.length <= 100
/// 2. title consists of words separated by a single space without any 
///    leading or trailing spaces.
/// 3. Each word consists of uppercase and lowercase English letters and 
///    is non-empty.
/// </summary>
string LeetCodeString::capitalizeTitle(string title)
{
    string result;
    string word;
    for (size_t i = 0; i <= title.size(); i++)
    {
        if (i == title.size() || isspace(title[i]))
        {
            if (word.size() < 3)
            {
                for (size_t j = 0; j < word.size(); j++)
                {
                    word[j] = tolower(word[j]);
                }
            }
            else
            {
                word[0] = toupper(word[0]);
                for (size_t j = 1; j < word.size(); j++)
                {
                    word[j] = tolower(word[j]);
                }
            }
            if (!result.empty()) result.push_back(' ');
            result.append(word);
            word.clear();
        }
        else
        {
            word.push_back(title[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2138. Divide a String Into Groups of Size k
///                                                                 
/// Easy
///
/// A string s can be partitioned into groups of size k using the 
/// following procedure:
///
/// The first group consists of the first k characters of the string, 
/// the second group consists of the next k characters of the string, and 
/// so on. Each character can be a part of exactly one group.
/// For the last group, if the string does not have k characters 
/// remaining, a character fill is used to complete the group.
/// Note that the partition is done so that after removing the fill 
/// character from the last group (if it exists) and concatenating all 
/// the groups in order, the resultant string should be s.
/// Given the string s, the size of each group k and the character fill, 
/// return a string array denoting the composition of every group s has 
/// been divided into, using the above procedure.
///
/// Example 1:
/// Input: s = "abcdefghi", k = 3, fill = "x"
/// Output: ["abc","def","ghi"]
/// Explanation:
/// The first 3 characters "abc" form the first group.
/// The next 3 characters "def" form the second group.
/// The last 3 characters "ghi" form the third group.
/// Since all groups can be completely filled by characters from the 
/// string, we do not need to use fill.
/// Thus, the groups formed are "abc", "def", and "ghi".
/// Example 2:
/// Input: s = "abcdefghij", k = 3, fill = "x"
/// Output: ["abc","def","ghi","jxx"]
/// Explanation:
/// Similar to the previous example, we are forming the first three 
/// groups "abc", "def", and "ghi".
/// For the last group, we can only use the character 'j' from the string. 
/// To complete this group, we add 'x' twice.
/// Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".
///
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s consists of lowercase English letters only.
/// 3. 1 <= k <= 100
/// 4. fill is a lowercase English letter.
/// </summary>
vector<string> LeetCodeString::divideString(string s, int k, char fill)
{
    vector<string> result((s.size() + k - 1) / k);
    for (size_t i = 0; i < s.size(); i++)
    {
        result[i / k].push_back(s[i]);
    }
    while ((int)result.back().size() < k) result.back().push_back(fill);
    return result;
}

/// <summary>
/// Leet Code 2135. Count Words Obtained After Adding a Letter
///                                                                 
/// Medium
///
/// You are given two 0-indexed arrays of strings startWords and 
/// targetWords. Each string consists of lowercase English letters only.
///
/// For each string in targetWords, check if it is possible to choose a 
/// string from startWords and perform a conversion operation on it to be 
/// equal to that from targetWords.
///
/// The conversion operation is described in the following two steps:
///
/// Append any lowercase letter that is not present in the string to its
/// end.
/// For example, if the string is "abc", the letters 'd', 'e', or 'y' can 
/// be added to it, but not 'a'. If 'd' is added, the resulting string 
/// will be "abcd".
/// Rearrange the letters of the new string in any arbitrary order.
/// For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and 
/// so on. Note that it can also be rearranged to "abcd" itself.
/// Return the number of strings in targetWords that can be obtained by 
/// performing the operations on any string of startWords.
///
/// Note that you will only be verifying if the string in targetWords can 
/// be obtained from a string in startWords by performing the operations. 
/// The strings in startWords do not actually change during this process.
/// 
/// Example 1:
/// Input: startWords = ["ant","act","tack"], 
/// targetWords = ["tack","act","acti"]
/// Output: 2
/// Explanation:
/// - In order to form targetWords[0] = "tack", we use 
/// startWords[1] = "act", append 'k' to it, and rearrange "actk" 
/// to "tack".
/// - There is no string in startWords that can be used to obtain 
///   targetWords[1] = "act".
/// Note that "act" does exist in startWords, but we must append one 
/// letter to the string before rearranging it.
/// - In order to form targetWords[2] = "acti", we use startWords[1] = 
/// "act", append 'i' to it, and rearrange "acti" to "acti" itself.
///
/// Example 2:
/// Input: startWords = ["ab","a"], targetWords = ["abc","abcd"]
/// Output: 1
/// Explanation:
/// - In order to form targetWords[0] = "abc", we use startWords[0] = 
///   "ab", add 'c' to it, and rearrange it to "abc".
/// - There is no string in startWords that can be used to obtain 
///   targetWords[1] = "abcd".
///
/// Constraints:
/// 1. 1 <= startWords.length, targetWords.length <= 5 * 10^4
/// 2. 1 <= startWords[i].length, targetWords[j].length <= 26
/// 3. Each string of startWords and targetWords consists of lowercase 
///    English letters only. 
/// 4. No letter occurs more than once in any string of startWords or 
///    targetWords.
/// </summary>
int LeetCodeString::wordCount(vector<string>& startWords, vector<string>& targetWords)
{
    unordered_set<string> source;
    for (string word: startWords)
    {  
        sort(word.begin(), word.end());
        source.insert(word);
    }
    int result = 0;
    for (string word : targetWords)
    {
        sort(word.begin(), word.end());
        for (size_t i = 0; i < word.size(); i++)
        {
            string str = word.substr(0, i) + word.substr(i + 1);
            if (source.count(str) > 0)
            {
                result++;
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2131. Longest Palindrome by Concatenating Two Letter Words
///                                                                 
/// Medium
///
/// You are given an array of strings words. Each element of words 
/// consists of two lowercase English letters.
///
/// Create the longest possible palindrome by selecting some elements from 
/// words and concatenating them in any order. Each element can be 
/// selected at most once.
///
/// Return the length of the longest palindrome that you can create. If 
/// it is impossible to create any palindrome, return 0.
///
/// A palindrome is a string that reads the same forward and backward.
/// 
/// Example 1:
/// Input: words = ["lc","cl","gg"]
/// Output: 6
/// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", 
/// of length 6.
/// Note that "clgglc" is another longest palindrome that can be created.
///
/// Example 2:
/// Input: words = ["ab","ty","yt","lc","cl","ab"]
/// Output: 8
/// Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = 
/// "tylcclyt", of length 8.
/// Note that "lcyttycl" is another longest palindrome that can be created.
///
/// Example 3:
/// Input: words = ["cc","ll","xx"]
/// Output: 2
/// Explanation: One longest palindrome is "cc", of length 2.
/// Note that "ll" is another longest palindrome that can be created, 
/// and so is "xx".
/// 
/// Constraints:
/// 1. 1 <= words.length <= 10^5
/// 2. words[i].length == 2
/// 3. words[i] consists of lowercase English letters.
/// </summary>
int LeetCodeString::longestPalindrome(vector<string>& words)
{
    unordered_map<string, int> word_map;
    int result = 0;
    for (string&  word : words)
    {
        string reverse_word = word;
        std::reverse(reverse_word.begin(), reverse_word.end());
        if (word_map.count(reverse_word) > 0)
        {
            word_map[reverse_word]--;
            if (word_map[reverse_word] == 0)
            {
                word_map.erase(reverse_word);
            }
            result += word.size() * 2;
        }
        else
        {
            word_map[word]++;
        } 
    }

    int central = 0;
    for (auto& itr : word_map)
    {
        string reverse_word = itr.first;
        std::reverse(reverse_word.begin(), reverse_word.end());
        if (reverse_word == itr.first)
        {
            central = max(central, (int)itr.first.size());
        }
    }
    result += central;
    return result;
}

/// <summary>
/// Leet Code 2157. Groups of Strings
///                                                                 
/// Hard
///
/// You are given a 0-indexed array of strings words. Each string consists 
/// of lowercase English letters only. No letter occurs more than once in 
/// any string of words.
///
/// Two strings s1 and s2 are said to be connected if the set of letters 
/// of s2 can be obtained from the set of letters of s1 by any one of the 
/// following operations:
///
/// Adding exactly one letter to the set of the letters of s1.
/// Deleting exactly one letter from the set of the letters of s1.
/// Replacing exactly one letter from the set of the letters of s1 with 
/// any letter, including itself.
/// The array words can be divided into one or more non-intersecting 
/// groups. A string belongs to a group if any one of the following is 
/// true:
///
/// It is connected to at least one other string of the group.
/// It is the only string present in the group.
/// Note that the strings in words should be grouped in such a manner 
/// that a string belonging to a group cannot be connected to a string 
/// present in any other group. It can be proved that such an arrangement 
/// is always unique.
///
/// Return an array ans of size 2 where:
/// ans[0] is the total number of groups words can be divided into, and
/// ans[1] is the size of the largest group.
///
/// Example 1:
/// Input: words = ["a","b","ab","cde"]
/// Output: [2,3]
/// Explanation:
/// - words[0] can be used to obtain words[1] (by replacing 'a' with 'b'), 
///   and words[2] (by adding 'b'). So words[0] is connected to words[1] 
///   and words[2].
/// - words[1] can be used to obtain words[0] (by replacing 'b' with 'a'), 
///   and words[2] (by adding 'a'). So words[1] is connected to words[0] 
///   and words[2].
/// - words[2] can be used to obtain words[0] (by deleting 'b'), and 
///   words[1] (by deleting 'a'). So words[2] is connected to words[0] and 
///   words[1].
/// - words[3] is not connected to any string in words.
/// Thus, words can be divided into 2 groups ["a","b","ab"] and ["cde"]. 
/// The size of the largest group is 3.  
///
/// Example 2:
/// Input: words = ["a","ab","abc"]
/// Output: [1,3]
/// Explanation:
/// - words[0] is connected to words[1].
/// - words[1] is connected to words[0] and words[2].
/// - words[2] is connected to words[1].
/// Since all strings are connected to each other, they should be grouped 
/// together.
/// Thus, the size of the largest group is 3.
/// 
/// Constraints:
/// 1. 1 <= words.length <= 2 * 10^4
/// 2. 1 <= words[i].length <= 26
/// 3. words[i] consists of lowercase English letters only.
/// 4. No letter occurs more than once in words[i].
/// </summary>
vector<int> LeetCodeString::groupStringsII(vector<string>& words)
{
    vector<int> bit_masks(words.size());
    unordered_map<int, vector<int>> word_map; 
    for (size_t i = 0; i < words.size(); i++)
    {
        int bitmask = 0;
        for (size_t j = 0; j < words[i].size(); j++)
        {
            bitmask |= (1 << (words[i][j] - 'a'));
        }
        word_map[bitmask].push_back(i);
        bit_masks[i] = bitmask;
    }
    vector<int> result(2);
    int group_size = 0;
    for (size_t i = 0; i < bit_masks.size(); i++)
    {
        if (word_map.count(bit_masks[i]) != 0)
        {
            result[0]++;
            group_size = 0;
            queue<int> queue;
            queue.push(i);
            int bitmask = bit_masks[i];
            group_size += word_map[bitmask].size();
            word_map.erase(bitmask);

            while (!queue.empty())
            {
                int index = queue.front();
                queue.pop();
                int bitmask = bit_masks[index];
                // flip 1 bit
                for (int j = 0; j < 26; j++)
                {
                    int new_mask = bitmask ^ (1 << j);
                    if (word_map.count(new_mask) == 0) continue;
                    queue.push(word_map[new_mask][0]);
                    group_size += word_map[new_mask].size();
                    word_map.erase(new_mask);
                }
                // flip 2 bit
                for (int j = 0; j < 26; j++)
                {
                    for (int k = j + 1; k < 26; k++)
                    {
                        if (((bitmask >> j) & 1) != ((bitmask >> k) & 1))
                        {
                            int new_mask = bitmask ^ (1 << j) ^ (1 << k);
                            if (word_map.count(new_mask) == 0) continue;
                            queue.push(word_map[new_mask][0]);
                            group_size += word_map[new_mask].size();
                            word_map.erase(new_mask);
                        }
                    }
                }
            }
            result[1] = max(result[1], group_size);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2156. Find Substring With Given Hash Value
///                                                                 
/// Medium
///
/// The hash of a 0-indexed string s of length k, given integers p and m, 
/// is computed using the following function:
///
/// hash(s, p, m) = (val(s[0]) * p0 + val(s[1]) * p^1 + ... + val(s[k-1]) * 
/// p^k-1) mod m.
/// Where val(s[i]) represents the index of s[i] in the alphabet from 
/// val('a') = 1 to val('z') = 26. 
/// 
/// You are given a string s and the integers power, modulo, k, and 
/// hashValue. Return sub, the first substring of s of length k such that 
/// hash(sub, power, modulo) == hashValue.
///
/// The test cases will be generated such that an answer always exists.
/// A substring is a contiguous non-empty sequence of characters within a 
/// string.
///
/// Example 1:
/// Input: s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
/// Output: "ee"
/// Explanation: The hash of "ee" can be computed to be 
/// hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0. 
/// "ee" is the first substring of length 2 with hashValue 0. Hence, we 
/// return "ee".
///
/// Example 2:
/// Input: s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
/// Output: "fbx"
/// Explanation: The hash of "fbx" can be computed to be 
/// hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 312) mod 100 = 23132 
/// mod 100 = 32. 
/// The hash of "bxz" can be computed to be hash("bxz", 31, 100) = 
/// (2 * 1 + 24 * 31 + 26 * 312) mod 100 = 25732 mod 100 = 32. 
/// "fbx" is the first substring of length 3 with hashValue 32. Hence, we 
/// return "fbx".
/// Note that "bxz" also has a hash of 32 but it appears later than "fbx".
/// 
/// Constraints:
/// 1. 1 <= k <= s.length <= 2 * 10^4
/// 2. 1 <= power, modulo <= 10^9
/// 3. 0 <= hashValue < modulo
/// 4. s consists of lowercase English letters only.
/// 5. The test cases are generated such that an answer always exists.
/// </summary>
string LeetCodeString::subStrHash(string s, int power, int modulo, int k, int hashValue)
{
    long long value = 0;
    long long power_accu = 1;
    for (size_t i = s.size() - k; i < s.size(); i++)
    {
        if (i > s.size() - k)
        {
            power_accu = power_accu * (long long)power % (long long)modulo;
        }
        value = (value + ((long long)s[i] - (long long)'a' + (long long)1) * power_accu % (long long)modulo) % modulo;
    }
    string result;
    if (value == (long long)hashValue) result = s.substr(s.size() - k);
    for (int i = (int)s.size() - k - 1; i >= 0; i--)
    {
        value = ((value - ((long long)s[i + k] - (long long)'a' + (long long)1) * power_accu % (long long)modulo) + modulo) % modulo;
        value = (value * (long long)power) % (long long)modulo;
        value = (value + ((long long)s[i] - (long long)'a' + (long long)1)) % (long long)modulo;
        if (value == (long long)hashValue) result = s.substr(i, k);
    }
    return result;
}

/// <summary>
/// Leet Code 2168. Unique Substrings With Equal Digit Frequency
///                                                                                  
/// Medium
///
/// Given a digit string s, return the number of unique substrings of s 
/// where every digit appears the same number of times.
///
/// Example 1:
/// Input: s = "1212"
/// Output: 5
/// Explanation: The substrings that meet the requirements are "1", "2", 
/// "12", "21", "1212".
/// Note that although the substring "12" appears twice, it is only 
/// counted once.
///
/// Example 2:
/// Input: s = "12321"
/// Output: 9
/// Explanation: The substrings that meet the requirements are "1", "2", "3", 
/// "12", "23", "32", "21", "123", "321".
/// 
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s consists of digits.
/// </summary>
int LeetCodeString::equalDigitFrequency(string s)
{
    long long M = 1000000007;
    unordered_set<long long> hash_sum;
    for (size_t i = 0; i < s.size(); i++)
    {
        vector<int>digit(10);
        int max_count = 0;
        int unique = 0;
        long long rolling_hash = 0;
        for (size_t j = i; j < s.size(); j++)
        {
            rolling_hash = (rolling_hash * 11 + ((long long)s[j] - (long long)'0' + (long long)1)) % M;
            digit[s[j] - '0']++;
            if (digit[s[j] - '0'] == 1) unique++;
            max_count = max(max_count, digit[s[j] - '0']);
            if (max_count * unique == j - i + 1)
            {
                hash_sum.insert(rolling_hash);
            }
        }
    }
    return hash_sum.size();
}

/// <summary>
/// Leet Code 2185. Counting Words With a Given Prefix
///                                                                                   
/// Easy
///
/// You are given an array of strings words and a string pref.
///
/// Return the number of strings in words that contain pref as a prefix.
///
/// A prefix of a string s is any leading contiguous substring of s.
///  
/// Example 1:
/// Input: words = ["pay","attention","practice","attend"], pref = "at"
/// Output: 2
/// Explanation: The 2 strings that contain "at" as a prefix 
/// are: "attention" and "attend".
///
/// Example 2:
/// Input: words = ["leetcode","win","loops","success"], pref = "code"
/// Output: 0
/// Explanation: There are no strings that contain "code" as a prefix.
///
/// Constraints:
/// 1. 1 <= words.length <= 100
/// 2. 1 <= words[i].length, pref.length <= 100
/// 3. words[i] and pref consist of lowercase English letters.
/// </summary>
int LeetCodeString::prefixCount(vector<string>& words, string pref)
{
    size_t size = pref.size();
    int result = 0;
    for (size_t i = 0; i < words.size(); i++)
    {
        if (words[i].substr(0, size) == pref)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2194. Cells in a Range on an Excel Sheet
///                                                                                   
/// Easy
///
/// A cell (r, c) of an excel sheet is represented as a string 
/// "<col><row>" where:
///
/// <col> denotes the column number c of the cell. It is represented 
/// by alphabetical letters.
/// For example, the 1st column is denoted by 'A', the 2nd by 'B', 
/// the 3rd by 'C', and so on.
/// <row> is the row number r of the cell. The rth row is represented 
/// by the integer r.
/// You are given a string s in the format "<col1><row1>:<col2><row2>", 
/// where <col1> represents the column c1, <row1> represents the row r1, 
/// <col2> represents the column c2, and <row2> represents the row r2, 
/// such that r1 <= r2 and c1 <= c2.
///
/// Return the list of cells (x, y) such that r1 <= x <= r2 and 
/// c1 <= y <= c2. The cells should be represented as strings in the 
/// format mentioned above and be sorted in non-decreasing order first 
/// by columns and then by rows.
/// 
/// Example 1:
/// Input: s = "K1:L2"
/// Output: ["K1","K2","L1","L2"]
/// Explanation:
/// The above diagram shows the cells which should be present in the list.
/// The red arrows denote the order in which the cells should be presented.
///
/// Example 2:
/// Input: s = "A1:F1"
/// Output: ["A1","B1","C1","D1","E1","F1"]
/// Explanation:
/// The above diagram shows the cells which should be present in the list.
/// The red arrow denotes the order in which the cells should be presented.
/// 
/// Constraints:
/// 1. s.length == 5
/// 2. 'A' <= s[0] <= s[3] <= 'Z'
/// 3. '1' <= s[1] <= s[4] <= '9'
/// 4. s consists of uppercase English letters, digits and ':'.
/// </summary>
vector<string> LeetCodeString::cellsInRange(string s)
{
    int col1 = s[0] - 'A';
    int col2 = s[3] - 'A';
    int row1 = s[1] - '0';
    int row2 = s[4] - '0';
    vector<string> result;
    for (int i = col1; i <= col2; i++)
    {
        for (int j = row1; j <= row2; j++)
        {
            string str = "A0";
            str[0] += i;
            str[1] += j;
            result.push_back(str);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2193. Minimum Number of Moves to Make Palindrome
///                                                                                   
/// Hard
///
/// You are given a string s consisting only of lowercase English letters.
/// In one move, you can select any two adjacent characters of s and swap 
/// them.
/// Return the minimum number of moves needed to make s a palindrome.
/// Note that the input will be generated such that s can always be 
/// converted to a palindrome.
/// 
/// Example 1:
/// Input: s = "aabb"
/// Output: 2
/// Explanation:
/// We can obtain two palindromes from s, "abba" and "baab". 
/// - We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
/// - We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
/// Thus, the minimum number of moves needed to make s a palindrome is 2.
///
/// Example 2:
/// Input: s = "letelt"
/// Output: 2
///
/// Explanation:
/// One of the palindromes we can obtain from s in 2 moves is "lettel".
/// One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
/// Other palindromes such as "tleelt" can also be obtained in 2 moves.
/// It can be shown that it is not possible to obtain a palindrome in 
/// less than 2 moves.
///
/// Constraints:
/// 1. 1 <= s.length <= 2000
/// 2. s consists only of lowercase English letters.
/// 3. s can be converted to a palindrome using a finite number of moves.
/// </summary>
int LeetCodeString::minMovesToMakePalindrome(string s)
{
    int result = 0;
    while (!s.empty())
    {
        int pos = s.find(s.back());
        if (pos == s.size() - 1)
        {
            result += s.size() - 1 - (s.size() - 1) / 2;
        }
        else
        {
            result += pos;
            s.erase(s.begin() + pos);
        }
        s.pop_back();
    }
    return result;
}

/// <summary>
/// Leet Code 2186. Minimum Number of Steps to Make Two Strings Anagram II
///                                                                                   
/// Medium
///
/// You are given two strings s and t. In one step, you can append any 
/// character to either s or t.
///
/// Return the minimum number of steps to make s and t anagrams of each 
/// other.
///
/// An anagram of a string is a string that contains the same characters 
/// with a different (or the same) ordering.
/// 
/// Example 1:
/// Input: s = "leetcode", t = "coats"
/// Output: 7
/// Explanation: 
/// - In 2 steps, we can append the letters in "as" onto s = "leetcode", 
///   forming s = "leetcodeas".
/// - In 5 steps, we can append the letters in "leede" onto t = "coats", 
///   forming t = "coatsleede".
/// "leetcodeas" and "coatsleede" are now anagrams of each other.
/// We used a total of 2 + 5 = 7 steps.
/// It can be shown that there is no way to make them anagrams of each 
/// other with less than 7 steps.
///
/// Example 2:
/// Input: s = "night", t = "thing"
/// Output: 0
/// Explanation: The given strings are already anagrams of each other. 
/// Thus, we do not need any further steps.
/// 
/// Constraints:
/// 1. 1 <= s.length, t.length <= 2 * 10^5
/// 2. s and t consist of lowercase English letters.
/// </summary>
int LeetCodeString::minStepsII(string s, string t)
{
    vector<int> char_count1(26), char_count2(26);
    for (size_t i = 0; i < s.size(); i++)
    {
        char_count1[s[i] - 'a']++;
    }
    for (size_t i = 0; i < t.size(); i++)
    {
        char_count2[t[i] - 'a']++;
    }
    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        result += abs(char_count1[i] - char_count2[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 2191. Sort the Jumbled Numbers
///                                                                                   
/// Medium
///
/// You are given a 0-indexed integer array mapping which represents the 
/// mapping rule of a shuffled decimal system. mapping[i] = j means 
/// digit i should be mapped to digit j in this system.
///  
/// The mapped value of an integer is the new integer obtained by 
/// replacing each occurrence of digit i in the integer with mapping[i] 
/// for all 0 <= i <= 9.
/// 
/// You are also given another integer array nums. Return the array nums 
/// sorted in non-decreasing order based on the mapped values of its 
/// elements.
///
/// Notes:
/// Elements with the same mapped values should appear in the same 
/// relative order as in the input.
/// The elements of nums should only be sorted based on their mapped values 
/// and not be replaced by them.
///
/// Example 1:
/// Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
/// Output: [338,38,991]
/// Explanation:  
/// Map the number 991 as follows:
/// 1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
/// 2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
/// Therefore, the mapped value of 991 is 669.
/// 338 maps to 007, or 7 after removing the leading zeros.
/// 38 maps to 07, which is also 7 after removing leading zeros.
/// Since 338 and 38 share the same mapped value, they should remain in 
/// the same relative order, so 338 comes before 38.
/// Thus, the sorted array is [338,38,991].
///
/// Example 2:
/// Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
/// Output: [123,456,789]
/// Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. 
/// Thus, the sorted array is [123,456,789].
/// 
/// Constraints:
/// 1. mapping.length == 10
/// 2. 0 <= mapping[i] <= 9
/// 3. All the values of mapping[i] are unique.
/// 4. 1 <= nums.length <= 3 * 10^4
/// 5. 0 <= nums[i] < 10^9
/// </summary>
vector<int> LeetCodeString::sortJumbled(vector<int>& mapping, vector<int>& nums)
{
    set<pair<int, int>> jumbled;
    for (size_t i = 0; i < nums.size(); i++)
    {
        string str = to_string(nums[i]);
        for (size_t j = 0; j < str.size(); j++)
        {
            str[j] = mapping[str[j] - '0'] + '0';
        }
        jumbled.insert(make_pair(stoi(str), i));
    }
    vector<int> result;
    for (auto& itr : jumbled)
    {
        result.push_back(nums[itr.second]);
    }
    return result;
}

/// <summary>
/// Leet Code 2223. Sum of Scores of Built Strings
///                                                                                   
/// Hard
///
/// You are building a string s of length n one character at a time, 
/// prepending each new character to the front of the string. The 
/// strings are labeled from 1 to n, where the string with length i 
/// is labeled si.
///
/// For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.
/// The score of si is the length of the longest common prefix between si 
/// and sn (Note that s == sn).
///
/// Given the final string s, return the sum of the score of every si.
/// 
/// Example 1:
/// Input: s = "babab"
/// Output: 9
/// Explanation:
/// For s1 == "b", the longest common prefix is "b" which has a score of 1.
/// For s2 == "ab", there is no common prefix so the score is 0.
/// For s3 == "bab", the longest common prefix is "bab" which has a score 
/// of 3.
/// For s4 == "abab", there is no common prefix so the score is 0.
/// For s5 == "babab", the longest common prefix is "babab" which has a 
/// score of 5.
/// The sum of the scores is 1 + 0 + 3 + 0 + 5 = 9, so we return 9.
///
/// Example 2:
/// Input: s = "azbazbzaz"
/// Output: 14
/// Explanation: 
/// For s2 == "az", the longest common prefix is "az" which has a 
/// score of 2.
/// For s6 == "azbzaz", the longest common prefix is "azb" which has a 
/// score of 3.
/// For s9 == "azbazbzaz", the longest common prefix is "azbazbzaz" which 
/// has a score of 9.
/// For all other si, the score is 0. 
/// The sum of the scores is 2 + 3 + 9 = 14, so we return 14.
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of lowercase English letters.
/// </summary>
long long LeetCodeString::sumScores(string s)
{
    int n = (int)s.size();
    vector <long long> z(s.size());
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
        { 
            z[i] = min(((long long)r - (long long)i + 1) * 1LL, z[i - l]);
        }
        while ((long long)i + (long long)z[i] < (long long)n && s[(int)z[i]] == s[i + (int)z[i]])
            ++z[i];
        if ((long long)i + z[i] - (long long)1 > (long long)r)
        {
            l = i;
            r = (int)i + (int)z[i] - (int)1;
        }
    }
    long long result = 0;
    for (auto xt : z) result += xt;
    result += (long long)s.size();
    
    return result;
}

/// <summary>
/// Leet Code 2224. Minimum Number of Operations to Convert Time
///                                                                                   
/// Easy
///
/// You are given two strings current and correct representing two 
/// 24-hour times.
///
/// 24-hour times are formatted as "HH:MM", where HH is between 00 
/// and 23, and MM is between 00 and 59. The earliest 24-hour time is 
/// 00:00, and the latest is 23:59.
///
/// In one operation you can increase the time current by 1, 5, 15, 
/// or 60 minutes. You can perform this operation any number of 
/// times.
///  
/// Return the minimum number of operations needed to convert current 
/// to correct.
///
/// Example 1:
/// Input: current = "02:30", correct = "04:35"
/// Output: 3
/// Explanation:
/// We can convert current to correct in 3 operations as follows:
/// - Add 60 minutes to current. current becomes "03:30".
/// - Add 60 minutes to current. current becomes "04:30".
/// - Add 5 minutes to current. current becomes "04:35".
/// It can be proven that it is not possible to convert current to 
/// correct in fewer than 3 operations.
///
/// Example 2:
/// Input: current = "11:00", correct = "11:01"
/// Output: 1
/// Explanation: We only have to add one minute to current, so the 
/// minimum number of operations needed is 1.
///
/// Constraints:
/// 1. current and correct are in the format "HH:MM"
/// 2. current <= correct
/// </summary>
int LeetCodeString::convertTime(string current, string correct)
{
    int current_time = current[4] + current[3] * 10 + (current[1] + current[0] * 10) * 60;
    int correct_time = correct[4] + correct[3] * 10 + (correct[1] + correct[0] * 10) * 60;
    int diff = correct_time - current_time;
    int result = 0;
    result += diff / 60;
    diff %= 60;
    result += diff / 15;
    diff %= 15;
    result += diff / 5;
    diff %= 5;
    result += diff;

    return result;
}

/// <summary>
/// Leet Code 2243. Calculate Digit Sum of a String
///                                                                                   
/// Easy
/// 
/// You are given a string s consisting of digits and an integer k.
///
/// A round can be completed if the length of s is greater than k. In one 
/// round, do the following:
///
/// Divide s into consecutive groups of size k such that the first k 
/// characters are in the first group, the next k characters are in the 
/// second group, and so on. Note that the size of the last group can be 
/// smaller than k.
/// Replace each group of s with a string representing the sum of all its 
/// digits. For example, "346" is replaced with "13" because 
/// 3 + 4 + 6 = 13.
/// Merge consecutive groups together to form a new string. If the length 
/// of the string is greater than k, repeat from step 1.
/// Return s after all rounds have been completed.
/// 
/// Example 1:
/// Input: s = "11111222223", k = 3
/// Output: "135"
/// Explanation: 
/// For the first round, we divide s into groups of size 3: 
/// "111", "112", "222", and "23".
/// Then we calculate the digit sum of each group: 1 + 1 + 1 = 3, 
/// 1 + 1 + 2 = 4, 2 + 2 + 2 = 6, and 2 + 3 = 5. 
/// So, s becomes "3" + "4" + "6" + "5" = "3465" after the first round.
/// - For the second round, we divide s into "346" and "5".
/// Then we calculate the digit sum of each group: 3 + 4 + 6 = 13, 5 = 5. 
/// So, s becomes "13" + "5" = "135" after second round. 
/// Now, s.length <= k, so we return "135" as the answer.
///
/// Example 2:
/// Input: s = "00000000", k = 3
/// Output: "000"
/// Explanation: 
/// We divide s into "000", "000", and "00".
/// Then we calculate the digit sum of each group: 0 + 0 + 0 = 0, 
/// 0 + 0 + 0 = 0, and 0 + 0 = 0. 
/// s becomes "0" + "0" + "0" = "000", whose length is equal to k, 
/// so we return "000".
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. 2 <= k <= 100
/// 3. s consists of digits only.
/// </summary>
string LeetCodeString::digitSum(string s, int k)
{
    string result = s;
    while ((int)result.size() > k)
    {
        string str = result;
        result.clear();
        int sum = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (i % k == 0)
            {
                if (i != 0) result.append(to_string(sum));
                sum = 0;
            }
            sum += str[i] - '0';
        }
        result.append(to_string(sum));
    }
    return result;
}

/// <summary>
/// Leet Code 2255. Count Prefixes of a Given String
///                                                                                      
/// Easy
/// 
/// You are given a string array words and a string s, where words[i] and 
/// s comprise only of lowercase English letters.
///
/// Return the number of strings in words that are a prefix of s.
///
/// A prefix of a string is a substring that occurs at the beginning of 
/// the string. A substring is a contiguous sequence of characters 
/// within a string.
/// 
/// Example 1:
/// Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
/// Output: 3
/// Explanation:
/// The strings in words which are a prefix of s = "abc" are:
/// "a", "ab", and "abc".
/// Thus the number of strings in words which are a prefix of s is 3.
///
/// Example 2:
/// Input: words = ["a","a"], s = "aa"
/// Output: 2
/// Explanation:
/// Both of the strings are a prefix of s. 
/// Note that the same string can occur multiple times in words, and it 
/// should be counted each time.
/// 
/// Constraints:
/// 1. 1 <= words.length <= 1000
/// 2. 1 <= words[i].length, s.length <= 10
/// 3. words[i] and s consist of lowercase English letters only.
/// </summary>
int LeetCodeString::countPrefixes(vector<string>& words, string s)
{
    int result = 0;
    for (string str : words)
    {
        if (s.substr(0, str.size()) == str)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2259. Remove Digit From Number to Maximize Result
///                                                               
/// Easy
/// 
/// You are given a string number representing a positive integer and 
/// a character digit.
///
/// Return the resulting string after removing exactly one occurrence of 
/// digit from number such that the value of the resulting string in 
/// decimal form is maximized. The test cases are generated such that 
/// digit occurs at least once in number.
///  
/// Example 1:
/// Input: number = "123", digit = "3"
/// Output: "12"
/// Explanation: There is only one '3' in "123". After removing '3', 
/// the result is "12".
///
/// Example 2:
/// Input: number = "1231", digit = "1"
/// Output: "231"
/// Explanation: We can remove the first '1' to get "231" or remove 
/// the second '1' to get "123".
/// Since 231 > 123, we return "231".
///
/// Example 3:
/// Input: number = "551", digit = "5"
/// Output: "51"
/// Explanation: We can remove either the first or second '5' from "551".
/// Both result in the string "51".
/// 
/// Constraints:
/// 1. 2 <= number.length <= 100
/// 2. number consists of digits from '1' to '9'.
/// 3. digit is a digit from '1' to '9'.
/// 4. digit occurs at least once in number.
/// </summary>
string LeetCodeString::removeDigit(string number, char digit)
{
    int pos = -1;
    for (size_t i = 0; i < number.size(); i++)
    {
        if (number[i] != digit) continue;
        pos = i;
        if ((i < number.size() - 1) && (number[i + 1] > digit))
        {
            break;
        }
    }
    string result = number.substr(0, pos);
    result.append(number.substr(pos + 1));
    return result;
}


/// <summary>
/// Leet Code 2264. Largest 3-Same-Digit Number in String
///                                                                                      
/// Easy
/// 
/// You are given a string num representing a large integer. An integer 
/// is good if it meets the following conditions:
///
/// It is a substring of num with length 3.
/// It consists of only one unique digit.
/// Return the maximum good integer as a string or an empty string 
/// "" if no such integer exists.
///
/// Note:
///  
/// A substring is a contiguous sequence of characters within a string.
/// There may be leading zeroes in num or a good integer.
/// 
/// Example 1:
/// Input: num = "6777133339"
/// Output: "777"
/// Explanation: There are two distinct good integers: "777" and "333".
//// "777" is the largest, so we return "777".
///
/// Example 2:
/// Input: num = "2300019"
/// Output: "000"
/// Explanation: "000" is the only good integer.
///
/// Example 3:
/// Input: num = "42352338"
/// Output: ""
/// Explanation: No substring of length 3 consists of only one unique 
/// digit. Therefore, there are no good integers.
///
/// Constraints:
/// 1. 3 <= num.length <= 1000
/// 2. num only consists of digits.
/// </summary>
string LeetCodeString::largestGoodInteger(string num)
{
    string result;
    for (size_t i = 2; i < num.size(); i++)
    {
        if (num[i] == num[i - 1] && num[i] == num[i - 2])
        {
            if (result.empty()) result = num.substr(i - 2, 3);
            else result = max(result, num.substr(i - 2, 3));
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2268. Minimum Number of Keypresses
///                                                                                      
/// Medium
/// 
/// You have a keypad with 9 buttons, numbered from 1 to 9, each mapped to 
/// lowercase English letters. You can choose which characters each button 
/// is matched to as long as:
///
/// All 26 lowercase English letters are mapped to.
/// Each character is mapped to by exactly 1 button.
/// Each button maps to at most 3 characters.
/// To type the first character matched to a button, you press the button 
/// once. To type the second character, you press the button twice, and 
/// so on.
///
/// Given a string s, return the minimum number of keypresses needed to 
/// type s using your keypad.
///
/// Note that the characters mapped to by each button, and the order they 
/// are mapped in cannot be changed.
/// 
/// Example 1:
/// Input: s = "apple"
/// Output: 5
/// Explanation: One optimal way to setup your keypad is shown above.
/// Type 'a' by pressing button 1 once.
/// Type 'p' by pressing button 6 once.
/// Type 'p' by pressing button 6 once.
/// Type 'l' by pressing button 5 once.
/// Type 'e' by pressing button 3 once.
/// A total of 5 button presses are needed, so return 5.
///
/// Example 2:
/// Input: s = "abcdefghijkl"
/// Output: 15
/// Explanation: One optimal way to setup your keypad is shown above.
/// The letters 'a' to 'i' can each be typed by pressing a button once.
/// Type 'j' by pressing button 1 twice.
/// Type 'k' by pressing button 2 twice.
/// Type 'l' by pressing button 3 twice.
/// A total of 15 button presses are needed, so return 15.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of lowercase English letters.
/// </summary>
int LeetCodeString::minimumKeypresses(string s)
{
    vector<int> count(26);
    for (size_t i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a']++;
    }
    sort(count.begin(), count.end(), greater<int>());
    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        if (i / 9 == 0)
        {
            result += count[i];
        }
        else if (i / 9 == 1)
        {
            result += count[i] * 2;
        }
        else
        {
            result += count[i] * 3;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2269. Find the K-Beauty of a Number
///                                                                                      
/// Easy
/// 
/// The k-beauty of an integer num is defined as the number of substrings 
/// of num when it is read as a string that meet the following conditions:
///
/// It has a length of k.
/// It is a divisor of num.
/// Given integers num and k, return the k-beauty of num.
///
/// Note:
/// Leading zeros are allowed.
/// 0 is not a divisor of any value.
/// A substring is a contiguous sequence of characters in a string.
///  
/// Example 1:
/// Input: num = 240, k = 2
/// Output: 2
/// Explanation: The following are the substrings of num of length k:
/// - "24" from "240": 24 is a divisor of 240.
/// - "40" from "240": 40 is a divisor of 240.
/// Therefore, the k-beauty is 2.
///
/// Example 2:
/// Input: num = 430043, k = 2
/// Output: 2 
/// Explanation: The following are the substrings of num of length k:
/// - "43" from "430043": 43 is a divisor of 430043.
/// - "30" from "430043": 30 is not a divisor of 430043.
/// - "00" from "430043": 0 is not a divisor of 430043.
/// - "04" from "430043": 4 is not a divisor of 430043.
/// - "43" from "430043": 43 is a divisor of 430043.
/// Therefore, the k-beauty is 2.
/// 
/// Constraints:
/// 1. 1 <= num <= 10^9
/// 2. 1 <= k <= num.length (taking num as a string)
/// </summary>
int LeetCodeString::divisorSubstrings(int num, int k)
{
    string str_num = to_string(num);
    int result = 0;
    for (size_t i = 0; i < str_num.size() - (k - 1); i++)
    {
        int d = atoi(str_num.substr(i, k).c_str());
        if (d == 0) continue;
        if (num % d == 0) result++;
    }
    return result;
}

/// <summary>
/// Leet Code 2273. Find Resultant Array After Removing Anagrams
///                                                           
/// Easy
/// 
/// You are given a 0-indexed string array words, where words[i] consists 
/// of lowercase English letters.
///
/// In one operation, select any index i such that 0 < i < words.length 
/// and words[i - 1] and words[i] are anagrams, and delete words[i] from 
/// words. Keep performing this operation as long as you can select an 
/// index that satisfies the conditions.
///
/// Return words after performing all operations. It can be shown that 
/// selecting the indices for each operation in any arbitrary order will 
/// lead to the same result.
///
/// An Anagram is a word or phrase formed by rearranging the letters of 
/// a different word or phrase using all the original letters exactly 
/// once. For example, "dacb" is an anagram of "abdc".
///
/// Example 1:
/// Input: words = ["abba","baba","bbaa","cd","cd"]
/// Output: ["abba","cd"]
/// Explanation:
/// One of the ways we can obtain the resultant array is by using the 
/// following operations:
/// - Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we 
///   choose index 2 and delete words[2].
/// Now words = ["abba","baba","cd","cd"].
/// - Since words[1] = "baba" and words[0] = "abba" are anagrams, we 
///   choose index 1 and delete words[1].
/// Now words = ["abba","cd","cd"].
/// - Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose 
///   index 2 and delete words[2].
/// Now words = ["abba","cd"].
/// We can no longer perform any operations, so ["abba","cd"] is the 
/// final answer.
///
/// Example 2:
/// Input: words = ["a","b","c","d","e"]
/// Output: ["a","b","c","d","e"]
/// Explanation:
/// No two adjacent strings in words are anagrams of each other, so no 
/// operations are performed.
///
/// Constraints:
/// 1. 1 <= words.length <= 100
/// 2. 1 <= words[i].length <= 10
/// 3. words[i] consists of lowercase English letters.
/// </summary>
vector<string> LeetCodeString::removeAnagrams(vector<string>& words)
{
    vector<string> result;
    string pre_sorted;
    for (size_t i = 0; i < words.size(); i++)
    {
        string word = words[i];
        string sorted = word;
        sort(sorted.begin(), sorted.end());
        if (i == 0)
        {
            result.push_back(word);
        }
        else
        {
            if (pre_sorted != sorted)
            {
                result.push_back(word);
            }
        }
        pre_sorted = sorted;
    }
    return result;
}


/// <summary>
/// Leet Code 2272. Substring With Largest Variance
///                                                           
/// Hard
/// 
/// The variance of a string is defined as the largest difference between 
/// the number of occurrences of any 2 characters present in the string. 
/// Note the two characters may or may not be the same.
///
/// Given a string s consisting of lowercase English letters only, return 
/// the largest variance possible among all substrings of s.
///
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: s = "aababbb"
/// Output: 3
/// Explanation:
/// All possible variances along with their respective substrings are 
/// listed below:
/// - Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", 
///   "ba", "b", "bb", and "bbb".
/// - Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", 
///   "aababbb", and "bab".
/// - Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
/// - Variance 3 for substring "babbb".
/// Since the largest possible variance is 3, we return it.
///
/// Example 2:
/// Input: s = "abcde"
/// Output: 0
/// Explanation:
/// No letter occurs more than once in s, so the variance of every 
/// substring is 0.
///  
/// Constraints:
/// 1. 1 <= s.length <= 10^4
/// 2. s consists of lowercase English letters.
/// </summary>
int LeetCodeString::largestVariance(string s)
{
    int result = 0;
    for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
    {
        for (char ch2 = 'a'; ch2 <= 'z'; ch2++)
        {
            list<char> deque;
            if (ch1 == ch2) continue;
            int count1 = 0;
            int count2 = 0;
            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i] != ch1 && s[i] != ch2)
                {
                    continue;
                }
                deque.push_back(s[i]);
                if (s[i] == ch1)
                {
                    count1++;
                    if (deque.front() == ch1 && count1 > 1)
                    {
                        deque.pop_front();
                        count1--;
                    }
                    if (count1 > count2)
                    {
                        deque.clear();
                        deque.push_back(ch1);
                        count1 = 1;
                        count2 = 0;
                    }
                }
                else
                {
                    count2++;
                }
                if (count1 > 0 && count2 > 0)
                {
                    result = max(result, count2 - count1);
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2262. Total Appeal of A String
///                                                           
/// Hard
/// 
/// The appeal of a string is the number of distinct characters found in 
/// the string.
///
/// For example, the appeal of "abbca" is 3 because it has 3 distinct 
/// characters: 'a', 'b', and 'c'.
/// Given a string s, return the total appeal of all of its substrings.
///
/// A substring is a contiguous sequence of characters within a string.
///  
/// Example 1:
/// Input: s = "abbca"
/// Output: 28
/// Explanation: The following are the substrings of "abbca":
/// - Substrings of length 1: "a", "b", "b", "c", "a" have an appeal of 
///   1, 1, 1, 1, and 1 respectively. The sum is 5.
/// - Substrings of length 2: "ab", "bb", "bc", "ca" have an appeal of 
///   2, 1, 2, and 2 respectively. The sum is 7.
/// - Substrings of length 3: "abb", "bbc", "bca" have an appeal of 
///   2, 2, and 3 respectively. The sum is 7.
/// - Substrings of length 4: "abbc", "bbca" have an appeal of 3 and 3 
///   respectively. The sum is 6.
/// - Substrings of length 5: "abbca" has an appeal of 3. The sum is 3.
/// The total sum is 5 + 7 + 7 + 6 + 3 = 28.
///
/// Example 2:
/// Input: s = "code"
/// Output: 20
/// Explanation: The following are the substrings of "code":
/// - Substrings of length 1: "c", "o", "d", "e" have an appeal of 
///   1, 1, 1, and 1 respectively. The sum is 4.
/// - Substrings of length 2: "co", "od", "de" have an appeal of 
///   2, 2, and 2 respectively. The sum is 6.
/// - Substrings of length 3: "cod", "ode" have an appeal of 3 and 3 
///   respectively. The sum is 6.
/// - Substrings of length 4: "code" has an appeal of 4. The sum is 4.
/// The total sum is 4 + 6 + 6 + 4 = 20.
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of lowercase English letters.
/// </summary>
long long LeetCodeString::appealSum(string s)
{
    vector<int> dp(26);
    long long result = 0;;
    set<long long> pos;
    for (size_t i = 0; i < s.size(); i++)
    {
        pos.erase(dp[s[i] - 'a']);
        dp[s[i] - 'a'] = i + 1;
        pos.insert((long long)i + 1);
        long long last = 0;
        long long n = pos.size();
        for (auto x : pos)
        {
            result = result + ((long long)x - last) * n;
            n--;
            last = x;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2278. Percentage of Letter in String
///                                                           
/// Easy
/// 
/// Given a string s and a character letter, return the percentage of 
/// characters in s that equal letter rounded down to the nearest 
/// whole percent.
///
/// Example 1:
/// Input: s = "foobar", letter = "o"
/// Output: 33
/// Explanation:
/// The percentage of characters in s that equal the letter 'o' is 
/// 2 / 6 * 100% = 33% when rounded down, so we return 33.
///
/// Example 2:
/// Input: s = "jjjj", letter = "k"
/// Output: 0
/// Explanation:
/// The percentage of characters in s that equal the letter 'k' is 0%, 
/// so we return 0.
///
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. s consists of lowercase English letters.
/// 3. letter is a lowercase English letter.
/// </summary>
int LeetCodeString::percentageLetter(string s, char letter)
{
    int count = 0;
    for (auto ch : s)
    {
        if (ch == letter) count++;
    }
    return (count * 100) / s.size();
}

/// <summary>
/// Leet Code 2283. Check if Number Has Equal Digit Count and Digit Value
///                                                           
/// Easy
/// 
/// You are given a 0-indexed string num of length n consisting of digits.
///
/// Return true if for every index i in the range 0 <= i < n, the digit i 
/// occurs num[i] times in num, otherwise return false.
///
///
/// Example 1:
/// Input: num = "1210"
/// Output: true
/// Explanation:
/// num[0] = '1'. The digit 0 occurs once in num.
/// num[1] = '2'. The digit 1 occurs twice in num.
/// num[2] = '1'. The digit 2 occurs once in num.
/// num[3] = '0'. The digit 3 occurs zero times in num.
/// The condition holds true for every index in "1210", so return true.
///
/// Example 2:
/// Input: num = "030"
/// Output: false
/// Explanation:
/// num[0] = '0'. The digit 0 should occur zero times, but actually occurs 
/// twice in num.
/// num[1] = '3'. The digit 1 should occur three times, but actually 
/// occurs zero times in num.
/// num[2] = '0'. The digit 2 occurs zero times in num.
/// The indices 0 and 1 both violate the condition, so return false.
/// 
/// Constraints:
/// 1. n == num.length
/// 2. 1 <= n <= 10
/// 3. num consists of digits.
/// </summary>
bool LeetCodeString::digitCount(string num)
{
    vector<int> count(10);
    for (size_t i = 0; i < num.size(); i++)
    {
        count[num[i] - '0']++;
    }
    for (size_t i = 0; i < num.size(); i++)
    {
        if (count[i] != num[i] - '0')
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet Code 2287. Rearrange Characters to Make Target String
///                                                           
/// Easy
/// 
/// You are given two 0-indexed strings s and target. You can take some 
/// letters from s and rearrange them to form new strings.
///
/// Return the maximum number of copies of target that can be formed by 
/// taking letters from s and rearranging them.
/// 
/// Example 1:
/// Input: s = "ilovecodingonleetcode", target = "code"
/// Output: 2
/// Explanation:
/// For the first copy of "code", take the letters at indices 4, 5, 6, 
/// and 7.
/// For the second copy of "code", take the letters at indices 17, 18, 19, 
/// and 20.
/// The strings that are formed are "ecod" and "code" which can both be 
/// rearranged into "code".
/// We can make at most two copies of "code", so we return 2.
///
/// Example 2:
/// Input: s = "abcba", target = "abc"
/// Output: 1
/// Explanation:
/// We can make one copy of "abc" by taking the letters at indices 0, 1, 
/// and 2.
/// We can make at most one copy of "abc", so we return 1.
/// Note that while there is an extra 'a' and 'b' at indices 3 and 4, we 
/// cannot reuse the letter 'c' at index 2, so we cannot make a second 
/// copy of "abc".
///
/// Example 3:
/// Input: s = "abbaccaddaeea", target = "aaaaa"
/// Output: 1
/// Explanation:
/// We can make one copy of "aaaaa" by taking the letters at 
/// indices 0, 3, 6, 9, and 12.
/// We can make at most one copy of "aaaaa", so we return 1.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 100
/// 2. 1 <= target.length <= 10
/// 3. s and target consist of lowercase English letters.
/// </summary>
int LeetCodeString::rearrangeCharacters(string s, string target)
{
    vector<int> s_count(26);
    vector<int> t_count(26);
    for (char ch : s) s_count[ch - 'a']++;
    for (char ch : target) t_count[ch - 'a']++;
    int result = INT_MAX;
    for (size_t i = 0; i < t_count.size(); i++)
    {
        if (t_count[i] == 0) continue;
        result = min(result, s_count[i] / t_count[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 2288. Apply Discount to Prices
///                                                           
/// Medium
/// 
/// A sentence is a string of single-space separated words where each 
/// word can contain digits, lowercase letters, and the dollar sign '$'. 
/// A word represents a price if it is a non-negative real number 
/// preceded by a dollar sign.
///
/// For example, "$100", "$23", and "$6.75" represent prices while 
/// "100", "$", and "2$3" do not.
/// You are given a string sentence representing a sentence and an integer 
/// discount. For each word representing a price, apply a discount of 
/// discount% on the price and update the word in the sentence. All 
/// updated prices should be represented with exactly two decimal places.
///
/// Return a string representing the modified sentence.
/// 
/// Example 1:
/// Input: sentence = "there are $1 $2 and 5$ candies in the shop", 
/// discount = 50
/// Output: "there are $0.50 $1.00 and 5$ candies in the shop"
/// Explanation: 
/// The words which represent prices are "$1" and "$2". 
/// - A 50% discount on "$1" yields "$0.50", so "$1" is replaced by 
/// "$0.50".
/// - A 50% discount on "$2" yields "$1". Since we need to have 
/// exactly 2 decimal places after a price, we replace "$2" with "$1.00".
///
/// Example 2:
/// Input: sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
/// Output: "1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
/// Explanation: 
/// Applying a 100% discount on any price will result in 0.
/// The words representing prices are "$3", "$5", "$6", and "$9".
/// Each of them is replaced by "$0.00".
/// 
/// Constraints:
/// 1. 1 <= sentence.length <= 10^5
/// 2. sentence consists of lowercase English letters, digits, ' ', 
///    and '$'.
/// 3. sentence does not have leading or trailing spaces.
/// 4. All words in sentence are separated by a single space.
/// 5. All prices will be positive integers without leading zeros.
/// 6. All prices will have at most 10 digits.
/// 7. 0 <= discount <= 100
/// </summary>
string LeetCodeString::discountPrices(string sentence, int discount)
{
    string result;
    string word;
    for (size_t i = 0; i <= sentence.size(); i++)
    {
        if (i == sentence.size() || isspace(sentence[i]))
        {
            if (word[0] == '$')
            {
                string amount = word.substr(1);
                long long ld = 0;
                for (size_t i = 0; i < amount.size(); i++)
                {
                    if (!isdigit(amount[i]))
                    {
                        ld = -1;
                        break;
                    }
                    ld = ld * 10 + amount[i] - '0';
                }
                if (amount.empty()) ld = -1;
                if (ld != -1)
                {
                    ld = (long long)(ld * (100 - (long long)discount));
                    string decimal;
                    if (ld % 100 >= 10) decimal = to_string(ld % 100);
                    else
                    {
                        decimal = "0" + to_string(ld % 100);
                    }
                    word = "$" + to_string(ld / 100) + "." + decimal;
                }
            }
            if (!result.empty()) result.push_back(' ');
            result.append(word);
            word.clear();
        }
        else
        {
            word.push_back(sentence[i]);
        }
    }
    return result;
}


/// <summary>
/// Leet Code 2284. Sender With Largest Word Count
///                                                           
/// Medium
/// 
/// You have a chat log of n messages. You are given two string arrays 
/// messages and senders where messages[i] is a message sent by senders[i].
///
/// A message is list of words that are separated by a single space with 
/// no leading or trailing spaces. The word count of a sender is the total 
/// number of words sent by the sender. Note that a sender may send more 
/// than one message.
///
/// Return the sender with the largest word count. If there is more than 
/// one sender with the largest word count, return the one with the 
/// lexicographically largest name.
///
/// Note:
/// Uppercase letters come before lowercase letters in lexicographical 
/// order.
/// "Alice" and "alice" are distinct.
/// 
/// Example 1:
/// Input: messages = ["Hello userTwooo","Hi userThree","Wonderful day 
/// Alice","Nice day userThree"], senders = ["Alice","userTwo",
/// "userThree","Alice"]
/// Output: "Alice"
/// Explanation: Alice sends a total of 2 + 3 = 5 words.
/// userTwo sends a total of 2 words.
/// userThree sends a total of 3 words.
/// Since Alice has the largest word count, we return "Alice".
///
/// Example 2:
/// Input: messages = ["How is leetcode for everyone","Leetcode is useful 
/// for practice"], senders = ["Bob","Charlie"]
/// Output: "Charlie"
/// Explanation: Bob sends a total of 5 words.
/// Charlie sends a total of 5 words.
/// Since there is a tie for the largest word count, we return the sender 
/// with the lexicographically larger name, Charlie.
///
/// Constraints:
/// 1. n == messages.length == senders.length
/// 2. 1 <= n <= 10^4
/// 3. 1 <= messages[i].length <= 100
/// 4. 1 <= senders[i].length <= 10
/// 5. messages[i] consists of uppercase and lowercase English letters 
///    and ' '.
/// 6. All the words in messages[i] are separated by a single space.
/// 7. messages[i] does not have leading or trailing spaces.
/// 8. senders[i] consists of uppercase and lowercase English letters only.
/// </summary>
string LeetCodeString::largestWordCount(vector<string>& messages, vector<string>& senders)
{
    unordered_map<string, int> word_count;
    for (size_t i = 0; i < messages.size(); i++)
    {
        int count = 1;
        for (size_t j = 0; j < messages[i].size(); j++)
        {
            if (isspace(messages[i][j])) count++;
        }
        word_count[senders[i]] += count;
    }
    int words = 0;
    string result;
    for (auto itr : word_count)
    {
        if ((itr.second > words) || ((itr.second == words) && (itr.first > result)))
        {
            words = itr.second;
            result = itr.first;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2299. Strong Password Checker II
///                                                           
/// Easy
/// 
/// A password is said to be strong if it satisfies all the following 
/// criteria:
///
/// It has at least 8 characters.
/// It contains at least one lowercase letter.
/// It contains at least one uppercase letter.
/// It contains at least one digit.
/// It contains at least one special character. The special characters 
/// are the characters in the following string: "!@#$%^&*()-+".
/// It does not contain 2 of the same character in adjacent positions 
/// (i.e., "aab" violates this condition, but "aba" does not).
/// Given a string password, return true if it is a strong password. 
/// Otherwise, return false.
/// 
/// Example 1:
/// Input: password = "IloveLe3tcode!"
/// Output: true
/// Explanation: The password meets all the requirements. Therefore, 
/// we return true.
///
/// Example 2:
/// Input: password = "Me+You--IsMyDream"
/// Output: false
/// Explanation: The password does not contain a digit and also 
/// contains 2 of the same character in adjacent positions. Therefore, 
/// we return false.
///
/// Example 3:
/// Input: password = "1aB!"
/// Output: false
/// Explanation: The password does not meet the length requirement. 
/// Therefore, we return false.
/// 
/// Constraints:
/// 1. 1 <= password.length <= 100
/// 2. password consists of letters, digits, and special characters: "!@#$%^&*()-+".
/// </summary>
bool LeetCodeString::strongPasswordCheckerII(string password)
{
    bool upper = false, lower = false, digit = false, special = false;
    if (password.size() < 8) return false;
    for (int i = 0; i < (int)password.size(); i++)
    {
        if (isupper(password[i]))
        {
            upper = true;
        }
        else if (islower(password[i]))
        {
            lower = true;
        }
        else if (isdigit(password[i]))
        {
            digit = true;
        }
        else
        {
            special = true;
        }
        if (i > 0 && password[i] == password[i - 1])
        {
            return false;
        }
    }
    return upper && lower && digit && special;
}


/// <summary>
/// Leet Code 2301. Match Substring After Replacement
///                                                           
/// Hard
/// 
/// You are given two strings s and sub. You are also given a 2D character 
/// array mappings where mappings[i] = [oldi, newi] indicates that you may 
/// replace any number of oldi characters of sub with newi. Each character 
/// in sub cannot be replaced more than once.
///
/// Return true if it is possible to make sub a substring of s by 
/// replacing zero or more characters according to mappings. Otherwise, 
/// return false.
///
/// A substring is a contiguous non-empty sequence of characters within 
/// a string.
/// 
/// Example 1:
/// Input: s = "fool3e7bar", sub = "leet", 
/// mappings = [["e","3"],["t","7"],["t","8"]]
/// Output: true
/// Explanation: Replace the first 'e' in sub with '3' and 't' in 
/// sub with '7'.
/// Now sub = "l3e7" is a substring of s, so we return true.
///
/// Example 2:
/// Input: s = "fooleetbar", sub = "f00l", mappings = [["o","0"]]
/// Output: false
/// Explanation: The string "f00l" is not a substring of s and no 
/// replacements can be made.
/// Note that we cannot replace '0' with 'o'.
///
/// Example 3:
/// Input: s = "Fool33tbaR", sub = "leetd", mappings = [["e","3"],
/// ["t","7"],["t","8"],["d","b"],["p","b"]]
/// Output: true
/// Explanation: Replace the first and second 'e' in sub with '3' and 'd' 
/// in sub with 'b'.
/// Now sub = "l33tb" is a substring of s, so we return true.
/// 
/// Constraints:
/// 1. 1 <= sub.length <= s.length <= 5000
/// 2. 0 <= mappings.length <= 1000
/// 3. mappings[i].length == 2
/// 4. oldi != newi
/// 5. s and sub consist of uppercase and lowercase English letters and 
///    digits.
/// 6. oldi and newi are either uppercase or lowercase English letters 
///    or digits.
/// </summary>
bool LeetCodeString::matchReplacement(string s, string sub, vector<vector<char>>& mappings)
{
    unordered_map<char, unordered_set<char>> char_map;
    for (size_t i = 0; i < mappings.size(); i++)
    {
        char_map[mappings[i][0]].insert(mappings[i][1]);
    }

    for (size_t i = 0; i + sub.size() <= s.size(); i++)
    {
        bool match = true;
        for (size_t j = 0; j < sub.size(); j++)
        {
            if (s[i + j] != sub[j] && char_map[sub[j]].count(s[i + j]) == 0)
            {
                match = false;
                break;
            }
        }
        if (match == true) return true;
    }
    return false;
}

/// <summary>
/// Leet Code 2306. Naming a Company
///                                                           
/// Hard
/// 
/// You are given an array of strings ideas that represents a list of 
/// names to be used in the process of naming a company. The process 
/// of naming a company is as follows:
///
/// Choose 2 distinct names from ideas, call them ideaA and ideaB.
/// Swap the first letters of ideaA and ideaB with each other.
/// If both of the new names are not found in the original ideas, then 
/// the name ideaA ideaB (the concatenation of ideaA and ideaB, 
/// separated by a space) is a valid company name.
/// Otherwise, it is not a valid name.
/// Return the number of distinct valid names for the company.
/// 
/// Example 1:
///
/// Input: ideas = ["coffee","donuts","time","toffee"]
/// Output: 6
/// Explanation: The following selections are valid:
/// - ("coffee", "donuts"): The company name created is "doffee conuts".
/// - ("donuts", "coffee"): The company name created is "conuts doffee".
/// - ("donuts", "time"): The company name created is "tonuts dime".
/// - ("donuts", "toffee"): The company name created is "tonuts doffee".
/// - ("time", "donuts"): The company name created is "dime tonuts".
/// - ("toffee", "donuts"): The company name created is "doffee tonuts".
/// Therefore, there are a total of 6 distinct company names.
///
/// The following are some examples of invalid selections:
/// - ("coffee", "time"): The name "toffee" formed after swapping already 
///   exists in the original array.
/// - ("time", "toffee"): Both names are still the same after swapping and 
///   exist in the original array.
/// - ("coffee", "toffee"): Both names formed after swapping already exist 
///   in the original array.
///
/// Example 2:
/// Input: ideas = ["lack","back"]
/// Output: 0
/// Explanation: There are no valid selections. Therefore, 0 is returned.
/// 
/// Constraints:
/// 1. 2 <= ideas.length <= 5 * 10^4
/// 2. 1 <= ideas[i].length <= 10
/// 3. ideas[i] consists of lowercase English letters.
/// 4. All the strings in ideas are unique.
/// </summary>
long long LeetCodeString::distinctNames(vector<string>& ideas)
{
    vector<unordered_set<string>> idea_map(26);
    for (size_t i = 0; i < ideas.size(); i++)
    {
        idea_map[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
    }
    long long result = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            long long left = 0;
            long long right = 0;
            for (string str : idea_map[i])
            {
                if (!idea_map[j].count(str)) left++;
            }
            for (string str : idea_map[j])
            {
                if (!idea_map[i].count(str)) right++;
            }
            result += left * right * 2;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2309. Greatest English Letter in Upper and Lower Case
///                                                           
/// Easy
/// 
/// Given a string of English letters s, return the greatest English 
/// letter which occurs as both a lowercase and uppercase letter in s. 
/// The returned letter should be in uppercase. If no such letter 
/// exists, return an empty string.
///
/// An English letter b is greater than another letter a if b appears 
/// after a in the English alphabet.
///
/// Example 1:
/// Input: s = "lEeTcOdE"
/// Output: "E"
/// Explanation:
/// The letter 'E' is the only letter to appear in both lower and upper 
/// case.
///
/// Example 2:
/// Input: s = "arRAzFif"
/// Output: "R"
/// Explanation:
/// The letter 'R' is the greatest letter to appear in both lower and 
/// upper case.
/// Note that 'A' and 'F' also appear in both lower and upper case, 
/// but 'R' is greater than 'F' or 'A'.
///
/// Example 3:
/// Input: s = "AbCdEfGhIjK"
/// Output: ""
/// Explanation:
/// There is no letter that appears in both lower and upper case.
///
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s consists of lowercase and uppercase English letters.
/// </summary>
string LeetCodeString::greatestLetter(string s)
{
    vector<int> upper(26);
    vector<int> lower(26);
    for (char ch : s)
    {
        if (isupper(ch)) upper[ch - 'A'] = 1;
        else if (islower(ch)) lower[ch - 'a'] = 1;
    }
    string result;
    for (int i = 25; i >= 0; i--)
    {
        if (upper[i] == 1 && lower[i] == 1)
        {
            result.push_back('A' + i);
            break;
        }
    }
    return result;
}
/// <summary>
/// Leet Code 2311. Longest Binary Subsequence Less Than or Equal to K
///                                                           
/// Medium
///
/// You are given a binary string s and a positive integer k.
///
/// Return the length of the longest subsequence of s that makes up a 
/// binary number less than or equal to k.
///
/// Note:
/// The subsequence can contain leading zeroes.
/// The empty string is considered to be equal to 0.
/// A subsequence is a string that can be derived from another string 
/// by deleting some or no characters without changing the order of 
/// the remaining characters.
/// 
/// Example 1:
/// Input: s = "1001010", k = 5
/// Output: 5
/// Explanation: The longest subsequence of s that makes up a binary 
/// number less than or equal to 5 is "00010", as this number is equal 
/// to 2 in decimal.
///
/// Note that "00100" and "00101" are also possible, which are equal 
/// to 4 and 5 in decimal, respectively.
/// The length of this subsequence is 5, so 5 is returned.
///
/// Example 2:
/// Input: s = "00101001", k = 1
/// Output: 6
/// Explanation: "000001" is the longest subsequence of s that makes 
/// up a binary number less than or equal to 1, as this number is equal 
/// to 1 in decimal.
/// The length of this subsequence is 6, so 6 is returned.
///
///
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s[i] is either '0' or '1'.
/// 3. 1 <= k <= 10^9
/// </summary>
int LeetCodeString::longestSubsequence(string s, int k)
{
    int num = 0;
    deque<int> deque;
    int result = 0;
    int size = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        num = num * 2 + s[i] - '0';
        if (s[i] == '1') deque.push_back(i);
        size++;
        while (num > k)
        {
            num -= 1 << ((int)i - deque.front());
            deque.pop_front();
            size--;
        }
        result = max(result, size);
    }
    return result;
}


/// <summary>
/// Leet Code 2315. Count Asterisks
///                                                           
/// Easy
///
/// You are given a string s, where every two consecutive vertical 
/// bars '|' are grouped into a pair. In other words, the 1st and 
/// 2nd '|' make a pair, the 3rd and 4th '|' make a pair, and so forth.
///
/// Return the number of '*' in s, excluding the '*' between each pair 
/// of '|'.
///
/// Note that each '|' will belong to exactly one pair.
///
/// Example 1:
/// 
/// Input: s = "l|*e*et|c**o|*de|"
/// Output: 2
/// Explanation: The considered characters are underlined: 
/// "l|*e*et|c**o|*de|".
/// The characters between the first and second '|' are excluded from the 
/// answer.
/// Also, the characters between the third and fourth '|' are excluded from 
/// the answer.
/// There are 2 asterisks considered. Therefore, we return 2.
///
/// Example 2:
/// Input: s = "iamprogrammer"
/// Output: 0
/// Explanation: In this example, there are no asterisks in s. Therefore, 
/// we return 0.
///
/// Example 3:
/// Input: s = "yo|uar|e**|b|e***au|tifu|l"
/// Output: 5
/// Explanation: The considered characters are underlined: 
/// "yo|uar|e**|b|e***au|tifu|l". There are 5 asterisks considered. 
/// Therefore, we return 5.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s consists of lowercase English letters, vertical bars '|', and 
///    asterisks '*'.
/// 3. s contains an even number of vertical bars '|'.
/// </summary>
int LeetCodeString::countAsterisks(string s) 
{
    int flag = 0;
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '|') flag = 1 - flag;
        if (s[i] == '*' && flag == 0)
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2325. Decode the Message
///                                                           
/// Easy
///
/// You are given the strings key and message, which represent a cipher 
/// key and a secret message, respectively. The steps to decode message 
/// are as follows:
///
/// Use the first appearance of all 26 lowercase English letters in key 
/// as the order of the substitution table.
/// Align the substitution table with the regular English alphabet.
/// Each letter in message is then substituted using the table.
/// Spaces ' ' are transformed to themselves.
/// For example, given key = "happy boy" (actual key would have at least 
/// one instance of each letter in the alphabet), we have the partial 
/// substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 
/// 'b' -> 'e', 'o' -> 'f').
/// Return the decoded message.
/// 
/// Example 1:
/// Input: key = "the quick brown fox jumps over the lazy dog", 
/// message = "vkbs bs t suepuv"
/// Output: "this is a secret"
/// Explanation: The diagram above shows the substitution table.
/// It is obtained by taking the first appearance of each letter in "the 
/// quick brown fox jumps over the lazy dog".
///
/// Example 2:
/// Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp 
///  mnoeius ycgk vcnjrdb"
/// Output: "the five boxing wizards jump quickly"
/// Explanation: The diagram above shows the substitution table.
/// It is obtained by taking the first appearance of each letter in 
/// "eljuxhpwnyrdgtqkviszcfmabo".
/// 
/// Constraints:
/// 1. 26 <= key.length <= 2000
/// 2. key consists of lowercase English letters and ' '.
/// 3. key contains every letter in the English alphabet ('a' to 'z') at 
///    least once.
/// 4. 1 <= message.length <= 2000
/// 5. message consists of lowercase English letters and ' '.
/// </summary>
string LeetCodeString::decodeMessage(string key, string message)
{
    vector<int> decode(26, -1);
    int ord = 0;
    for (size_t i = 0; i < key.size(); i++)
    {
        if (isspace(key[i])) continue;
        if (decode[key[i] - 'a'] == -1)
        {
            decode[key[i] - 'a'] = ord;
            ord++;
            if (ord == 26) break;
        }
    }
    string result;
    for (size_t i = 0; i < message.size(); i++)
    {
        if (isspace(message[i])) result.push_back(' ');
        else
        {
            result.push_back('a' + decode[message[i] - 'a']);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2343. Query Kth Smallest Trimmed Number
///                                                           
/// Medium
///
/// You are given a 0-indexed array of strings nums, where each string is 
/// of equal length and consists of only digits.
///
/// You are also given a 0-indexed 2D integer array queries where 
/// queries[i] = [ki, trimi]. For each queries[i], you need to:
///
/// Trim each number in nums to its rightmost trimi digits.
/// Determine the index of the kith smallest trimmed number in nums. If 
/// two trimmed numbers are equal, the number with the lower index is 
/// considered to be smaller.
/// Reset each number in nums to its original length.
/// Return an array answer of the same length as queries, where answer[i] 
/// is the answer to the ith query.
///
/// Note:
/// To trim to the rightmost x digits means to keep removing the leftmost 
/// digit, until only x digits remain.
/// Strings in nums may contain leading zeros.
/// 
/// Example 1:
/// Input: nums = ["102","473","251","814"], 
///        queries = [[1,1],[2,3],[4,2],[1,2]]
/// Output: [2,2,1,0]
/// Explanation:
/// 1. After trimming to the last digit, nums = ["2","3","1","4"]. 
///    The smallest number is 1 at index 2.
/// 2. Trimmed to the last 3 digits, nums is unchanged. The 2nd smallest 
///    number is 251 at index 2.
/// 3. Trimmed to the last 2 digits, nums = ["02","73","51","14"]. The 4th 
///    smallest number is 73.
/// 4. Trimmed to the last 2 digits, the smallest number is 2 at index 0.
/// Note that the trimmed number "02" is evaluated as 2.
///
/// Example 2:
/// Input: nums = ["24","37","96","04"], queries = [[2,1],[2,2]]
/// Output: [3,0]
/// Explanation:
/// 1. Trimmed to the last digit, nums = ["4","7","6","4"]. 
///    The 2nd smallest number is 4 at index 3.
///    There are two occurrences of 4, but the one at index 0 is considered 
///    smaller than the one at index 3.
/// 2. Trimmed to the last 2 digits, nums is unchanged. The 2nd smallest 
///    number is 24.
///
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. 1 <= nums[i].length <= 100
/// 3. nums[i] consists of only digits.
/// 4. All nums[i].length are equal.
/// 5. 1 <= queries.length <= 100
/// 6. queries[i].length == 2
/// 7. 1 <= ki <= nums.length
/// 8. 1 <= trimi <= nums[i].length
/// Follow up: Could you use the Radix Sort Algorithm to solve this 
/// problem? What will be the complexity of that solution?
/// </summary>
vector<int> LeetCodeString::smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries)
{
    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        vector<pair<string, int>> arr(nums.size());
        for (size_t j = 0; j < nums.size(); j++)
        {
            arr[j].first = nums[j].substr(nums[j].size() - queries[i][1]);
            arr[j].second = j;
        }
        sort(arr.begin(), arr.end());
        result[i] = arr[queries[i][0] - 1].second;
    }
    return result;
}

/// <summary>
/// Leet Code 2337. Move Pieces to Obtain a String
///                                                           
/// Medium
///
/// You are given two strings start and target, both of length n. Each 
/// string consists only of the characters 'L', 'R', and '_' where:
///
/// The characters 'L' and 'R' represent pieces, where a piece 'L' can 
/// move to the left only if there is a blank space directly to its left, 
/// and a piece 'R' can move to the right only if there is a blank space 
/// directly to its right.
/// The character '_' represents a blank space that can be occupied by 
/// any of the 'L' or 'R' pieces.
/// Return true if it is possible to obtain the string target by moving 
/// the pieces of the string start any number of times. Otherwise, return 
/// false.
///
/// Example 1:
/// Input: start = "_L__R__R_", target = "L______RR"
/// Output: true
/// Explanation: We can obtain the string target from start by doing the 
/// following moves:
/// - Move the first piece one step to the left, start becomes equal 
///   to "L___R__R_".
/// - Move the last piece one step to the right, start becomes equal 
///   to "L___R___R".
/// - Move the second piece three steps to the right, start becomes equal 
///   to "L______RR".
/// Since it is possible to get the string target from start, we return 
/// true.
///
/// Example 2:
/// Input: start = "R_L_", target = "__LR"
/// Output: false
/// Explanation: The 'R' piece in the string start can move one step to 
/// the right to obtain "_RL_".
/// After that, no pieces can move anymore, so it is impossible to obtain 
/// the string target from start.
///
/// Example 3:
/// Input: start = "_R", target = "R_"
/// Output: false
/// Explanation: The piece in the string start can move only to the right, 
/// so it is impossible to obtain the string target from start.
/// 
/// Constraints:
/// 1. n == start.length == target.length
/// 2. 1 <= n <= 10^5
/// 3. start and target consist of the characters 'L', 'R', and '_'.
/// </summary>
bool LeetCodeString::canChange(string start, string target)
{
    vector<pair<char, int>> start_pos, target_pos;
    for (size_t i = 0; i < start.size(); i++)
    {
        if (start[i] != '_')
        {
            start_pos.push_back(make_pair(start[i], i));
        }
        if (target[i] != '_')
        {
            target_pos.push_back(make_pair(target[i], i));
        }
    }
    if (start_pos.size() != target_pos.size())
    {
        return false;
    }
    for (size_t i = 0; i < start_pos.size(); i++)
    {
        if (start_pos[i].first != target_pos[i].first)
        {
            return false;
        }
        if (start_pos[i].first == 'L' && start_pos[i].second < target_pos[i].second)
        {
            return false;
        }
        if (start_pos[i].first == 'R' && start_pos[i].second > target_pos[i].second)
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet Code 2351. First Letter to Appear Twice
///                                                           
/// Easy
///
/// Given a string s consisting of lowercase English letters, return the 
/// first letter to appear twice.
///
/// Note:
/// A letter a appears twice before another letter b if the second 
/// occurrence of a is before the second occurrence of b.
/// s will contain at least one letter that appears twice.
/// 
/// Example 1:
/// Input: s = "abccbaacz"
/// Output: "c"
/// Explanation:
/// The letter 'a' appears on the indexes 0, 5 and 6.
/// The letter 'b' appears on the indexes 1 and 4.
/// The letter 'c' appears on the indexes 2, 3 and 7.
/// The letter 'z' appears on the index 8.
/// The letter 'c' is the first letter to appear twice, because out of 
/// all the letters the index of its second occurrence is the smallest.
///
/// Example 2:
/// Input: s = "abcdd"
/// Output: "d"
/// Explanation:
/// The only letter that appears twice is 'd' so we return 'd'.
/// 
/// Constraints:
/// 1. 2 <= s.length <= 100
/// 2. s consists of lowercase English letters.
/// 3. s has at least one repeated letter.
/// </summary>
char LeetCodeString::repeatedCharacter(string s)
{
    vector<int> char_count(26);
    for (size_t i = 0; i < s.size(); i++)
    {
        char_count[s[i] - 'a']++;
        if (char_count[s[i] - 'a'] == 2)
        {
            return s[i];
        }
    }
    return '#';
}

/// <summary>
/// Leet Code 2390. Removing Stars From a String
///                                                  
/// Medium
///
/// You are given a string s, which contains stars *.
///
/// In one operation, you can:
///
/// Choose a star in s.
/// Remove the closest non-star character to its left, as well as remove 
/// the star itself.
/// Return the string after all stars have been removed.
///
/// Note:
/// The input will be generated such that the operation is always possible.
/// It can be shown that the resulting string will always be unique.
///
/// Example 1:
/// Input: s = "leet**cod*e"
/// Output: "lecoe"
/// Explanation: Performing the removals from left to right:
/// - The closest character to the 1st star is 't' in "leet**cod*e". s 
///   becomes "lee*cod*e".
/// - The closest character to the 2nd star is 'e' in "lee*cod*e". s 
///   becomes "lecod*e".
/// - The closest character to the 3rd star is 'd' in "lecod*e". s 
///   becomes "lecoe".
/// There are no more stars, so we return "lecoe".
///
/// Example 2:
/// Input: s = "erase*****"
/// Output: ""
/// Explanation: The entire string is removed, so we return an empty 
/// string.
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of lowercase English letters and stars *.
/// 3. The operation above can be performed on s.
/// </summary>
string LeetCodeString::removeStars(string s)
{
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != '*')
        {
            result.push_back(s[i]);
        }
        else
        {
            if (!result.empty()) result.pop_back();
        }
    }
    return result;
}
/// <summary>
/// Leet Code 2399. Check Distances Between Same Letters
///                                                  
/// Easy
///
/// You are given a 0-indexed string s consisting of only lowercase 
/// English letters, where each letter in s appears exactly twice. 
/// You are also given a 0-indexed integer array distance of length 26.
///
/// Each letter in the alphabet is numbered from 0 to 25 (i.e. 
/// 'a' -> 0, 'b' -> 1, 'c' -> 2, ... , 'z' -> 25).
///
/// In a well-spaced string, the number of letters between the two 
/// occurrences of the ith letter is distance[i]. If the ith letter 
/// does not appear in s, then distance[i] can be ignored.
///
/// Return true if s is a well-spaced string, otherwise return false.
///
/// Example 1:
/// Input: s = "abaccb", 
/// distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
/// Output: true
/// Explanation:
/// - 'a' appears at indices 0 and 2 so it satisfies distance[0] = 1.
/// - 'b' appears at indices 1 and 5 so it satisfies distance[1] = 3.
/// - 'c' appears at indices 3 and 4 so it satisfies distance[2] = 0.
/// Note that distance[3] = 5, but since 'd' does not appear in s, it 
/// can be ignored.
/// Return true because s is a well-spaced string.
///
/// Example 2:
/// Input: s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/// 0,0,0,0,0,0,0,0,0,0]
/// Output: false
/// Explanation:
/// - 'a' appears at indices 0 and 1 so there are zero letters 
///   between them.
/// Because distance[0] = 1, s is not a well-spaced string.
///
/// Constraints:
/// 1. 2 <= s.length <= 52
/// 2. s consists only of lowercase English letters.
/// 3. Each letter appears in s exactly twice.
/// 4. distance.length == 26
/// 5. 0 <= distance[i] <= 50
/// </summary>
bool LeetCodeString::checkDistances(string s, vector<int>& distance)
{
    vector<int> diff(26, -1);
    vector<int> pos(26, -1);
    for (size_t i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        if (pos[index] == -1)
        {
            pos[index] = i;
        }
        else
        {
            diff[index] = i - pos[index] - 1;
        }
    }
    for (size_t i = 0; i < distance.size(); i++)
    {
        if (diff[i] == -1) continue;
        if (diff[i] != distance[i]) return false;
    }
    return true;
}

/// <summary>
/// Leet Code 2380. Time Needed to Rearrange a Binary String
///                                                  
/// Medium
///
/// You are given a binary string s. In one second, all occurrences 
/// of "01" are simultaneously replaced with "10". This process repeats 
/// until no occurrences of "01" exist.
///  
/// Return the number of seconds needed to complete this process.
///
/// 
/// Example 1:
/// Input: s = "0110101"
/// Output: 4
/// Explanation: 
/// After one second, s becomes "1011010".
/// After another second, s becomes "1101100".
/// After the third second, s becomes "1110100".
/// After the fourth second, s becomes "1111000".
/// No occurrence of "01" exists any longer, and the process needed 4 
/// seconds to complete,
/// so we return 4.
///
/// Example 2:
/// Input: s = "11100"
/// Output: 0
/// Explanation:
/// No occurrence of "01" exists in s, and the processes needed 0 
/// seconds to complete,
/// so we return 0.
///
/// Constraints:
/// 1. 1 <= s.length <= 1000
/// 2. s[i] is either '0' or '1'.
///
/// Follow up:
/// Can you solve this problem in O(n) time complexity?
/// </summary>
int LeetCodeString::secondsToRemoveOccurrences(string s)
{
    int result = 0;
    int zero = 0;
    int excess = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            zero++;
            if (excess > 0) excess--;
        }
        else
        {
            if (zero != 0)
            {
                excess++;
                result = max(result, zero + excess - 1);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 416. Sum of Prefix Scores of Strings 
///                                                  
/// Hard
///
/// You are given an array words of size n consisting of non-empty strings.
///
/// We define the score of a string word as the number of strings words[i] 
/// such that word is a prefix of words[i].
///
/// For example, if words = ["a", "ab", "abc", "cab"], then the score 
/// of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
/// Return an array answer of size n where answer[i] is the sum of scores 
/// of every non-empty prefix of words[i].
///
/// Note that a string is considered as a prefix of itself.
/// Example 1:
/// Input: words = ["abc","ab","bc","b"]
/// Output: [5,4,3,2]
/// Explanation: The answer for each string is the following:
/// - "abc" has 3 prefixes: "a", "ab", and "abc".
/// - There are 2 strings with the prefix "a", 2 strings with the 
///   prefix "ab", and 1 string with the prefix "abc".
/// The total is answer[0] = 2 + 2 + 1 = 5.
/// - "ab" has 2 prefixes: "a" and "ab".
/// - There are 2 strings with the prefix "a", and 2 strings with the 
///   prefix "ab".
/// The total is answer[1] = 2 + 2 = 4.
/// - "bc" has 2 prefixes: "b" and "bc".
/// - There are 2 strings with the prefix "b", and 1 string with the 
///   prefix "bc".
/// The total is answer[2] = 2 + 1 = 3.
/// - "b" has 1 prefix: "b".
/// - There are 2 strings with the prefix "b".
/// The total is answer[3] = 2.
///
/// Example 2:
/// Input: words = ["abcd"]
/// Output: [4]
/// Explanation:
/// "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
/// Each prefix has a score of one, so the total is 
/// answer[0] = 1 + 1 + 1 + 1 = 4.
///
/// Constraints:
/// 1. 1 <= words.length <= 1000
/// 2. 1 <= words[i].length <= 1000
/// 3. words[i] consists of lowercase English letters.
/// </summary>
vector<int> LeetCodeString::sumPrefixScores(vector<string>& words)
{
    struct Trie
    {
        Trie* children[26] = {};
        int cnt = 0;
        Trie()
        {
            cnt = 0;
        }
        void insert(string& w)
        {
            Trie* curr = this;
            for (char c : w)
            {
                if (curr->children[c - 'a'] == nullptr)
                {
                    curr->children[c - 'a'] = new Trie();
                }
                curr = curr->children[c - 'a'];
                curr->cnt++;
            }
        }
        int count(string& w)
        {
            Trie* curr = this;
            int result = 0;
            for (char c : w)
            {
                curr = curr->children[c - 'a'];
                result += curr->cnt;
            }
            return result;
        }
    };
    Trie* trie = new Trie();
    for (size_t i = 0; i < words.size(); i++)
    {
        trie->insert(words[i]);
    }
    vector<int> result(words.size());
    for (size_t i = 0; i < words.size(); i++)
    {
        result[i] = trie->count(words[i]);
    }
    delete trie;
    return result;
}

/// <summary>
/// Leet Code 2405. Optimal Partition of String
///                                                  
/// Medium
///
/// Given a string s, partition the string into one or more substrings 
/// such that the characters in each substring are unique. That is, no 
/// letter appears in a single substring more than once.
///
/// Return the minimum number of substrings in such a partition.
///
/// Note that each character should belong to exactly one substring 
/// in a partition.
///
/// Example 1:
/// Input: s = "abacaba"
/// Output: 4
/// Explanation:
/// Two possible partitions are ("a","ba","cab","a") and 
/// ("ab","a","ca","ba").
/// It can be shown that 4 is the minimum number of substrings 
/// needed.
///
/// Example 2:
/// Input: s = "ssssss"
/// Output: 6
/// Explanation:
/// The only valid partition is ("s","s","s","s","s","s").
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of only English lowercase letters.
/// </summary>
int LeetCodeString::partitionString(string s)
{
    unordered_set<char> chars;
    int result = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (chars.count(s[i]) > 0)
        {
            chars.clear();
            result++;
        }
        chars.insert(s[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 2414. Length of the Longest Alphabetical Continuous Substring
///                                                  
/// Medium
///
/// An alphabetical continuous string is a string consisting of 
/// consecutive letters in the alphabet. In other words, it is any 
/// substring of the string "abcdefghijklmnopqrstuvwxyz".
///
/// For example, "abc" is an alphabetical continuous string, while "acb" 
/// and "za" are not.
/// Given a string s consisting of lowercase letters only, return the
/// length of the longest alphabetical continuous substring.
///
/// Example 1:
/// Input: s = "abacaba"
/// Output: 2
/// Explanation: There are 4 distinct continuous substrings: "a", "b", 
/// "c" and "ab".
/// "ab" is the longest continuous substring. 
///
/// Example 2:
/// Input: s = "abcde"
/// Output: 5
/// Explanation: "abcde" is the longest continuous substring.
///
/// Constraints:
/// 1 <= s.length <= 10^5
/// 2. s consists of only English lowercase letters.
/// </summary>
int LeetCodeString::longestContinuousSubstring(string s)
{
    int result = 0;
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == 0) count = 1;
        else if (s[i] - s[i - 1] == 1)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        result = max(result, count);
    }
    return result;
}

/// <summary>
/// Leet Code 2423. Remove Letter To Equalize Frequency
///                                                  
/// Easy
///
/// You are given a 0-indexed string word, consisting of lowercase English 
/// letters. You need to select one index and remove the letter at that 
/// index from word so that the frequency of every letter present in word 
/// is equal.
///
/// Return true if it is possible to remove one letter so that the 
/// frequency of all letters in word are equal, and false otherwise.
///
/// Note:
/// The frequency of a letter x is the number of times it occurs in the 
/// string.
/// You must remove exactly one letter and cannot chose to do nothing.
///
/// Example 1:
/// Input: word = "abcc"
/// Output: true
/// Explanation: Select index 3 and delete it: word becomes "abc" and 
/// each character has a frequency of 1.
///
/// Example 2:
///
/// Input: word = "aazz"
/// Output: false
/// Explanation: We must delete a character, so either the frequency of 
/// "a" is 1 and the frequency of "z" is 2, or vice versa. It is 
/// impossible to make all present letters have equal frequency.
/// 
/// Constraints:
/// 1. 2 <= word.length <= 100
/// 2. word consists of lowercase English letters only.
/// </summary>
bool LeetCodeString::equalFrequency(string word)
{
    vector<int> chars(26);
    for (size_t i = 0; i < word.size(); i++)
    {
        chars[word[i] - 'a']++;
    }
    map<int, int> count;
    for (size_t i = 0; i < 26; i++)
    {
        if (chars[i] == 0) continue;
        else count[chars[i]]++;
    }
    if (count.size() > 2) return false;
    if (count.begin()->first == 1)
    {
        if (count.size() == 1 || count.begin()->second == 1)
        {
            return true;
        }
    }
    if (count.size() == 1 && count.begin()->second == 1)
    {
        return true;
    }
    if (count.begin()->first + 1 == count.rbegin()->first && count.rbegin()->second == 1)
    {
        return true;
    }
    return false;
}

/// <summary>
/// Leet Code 2451. Odd String Difference 
///                                                  
/// Easy
///
/// You are given an array of equal-length strings words. Assume that 
/// the length of each string is n.
/// Each string words[i] can be converted into a difference integer array 
/// difference[i] of length n - 1 where difference[i][j] = words[i][j+1] 
/// - words[i][j] where 0 <= j <= n - 2. Note that the difference 
/// between two letters is the difference between their positions in 
/// the alphabet i.e. the position of 'a' is 0, 'b' is 1, and 'z' is 25.
///
/// For example, for the string "acb", the difference integer array is 
/// [2 - 0, 1 - 2] = [2, -1].
/// All the strings in words have the same difference integer array, 
/// except one. You should find that string.
///
/// Return the string in words that has different difference integer array.
/// 
/// Example 1:
/// Input: words = ["adc","wzy","abc"]
/// Output: "abc"
/// Explanation: 
/// - The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
/// - The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
/// - The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1]. 
/// The odd array out is [1, 1], so we return the corresponding string, "abc".
///
/// Example 2:
/// Input: words = ["aaa","bob","ccc","ddd"]
/// Output: "bob"
/// Explanation: All the integer arrays are [0, 0] except for "bob", 
/// which corresponds to [13, -13].
///
/// Constraints:
/// 1. 3 <= words.length <= 100
/// 2. n == words[i].length
/// 3. 2 <= n <= 20
/// 4. words[i] consists of lowercase English letters.
/// </summary>
string LeetCodeString::oddString(vector<string>& words)
{
    unordered_map<string, int> str_map;
    for (size_t i = 0; i < words.size(); i++)
    {
        int diff = words[i][0] - 'a';
        string word = words[i];
        for (size_t j = 0; j < word.size(); j++)
        {
            word[j] -= diff;
        }
        str_map[word]++;
    }
    for (size_t i = 0; i < words.size(); i++)
    {
        int diff = words[i][0] - 'a';
        string word = words[i];
        for (size_t j = 0; j < word.size(); j++)
        {
            word[j] -= diff;
        }
        if (str_map[word] == 1) return words[i];
    }
    return "";
}

/// <summary>
/// Leet Code 2452. Words Within Two Edits of Dictionary 
///                                                  
/// Medium
///
/// You are given two string arrays, queries and dictionary. All words 
/// in each array comprise of lowercase English letters and have the 
/// same length.
///
/// In one edit you can take a word from queries, and change any letter 
/// in it to any other letter. Find all words from queries that, after 
/// a maximum of two edits, equal some word from dictionary.
///
/// Return a list of all words from queries, that match with some word 
/// from dictionary after a maximum of two edits. Return the words in 
/// the same order they appear in queries.
///
/// Example 1:
/// Input: queries = ["word","note","ants","wood"], dictionary = 
/// ["wood","joke","moat"]
/// Output: ["word","note","wood"]
/// Explanation:
/// - Changing the 'r' in "word" to 'o' allows it to equal the dictionary 
///   word "wood".
/// - Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it 
///   to "joke".
/// - It would take more than 2 edits for "ants" to equal a dictionary 
///   word.
/// - "wood" can remain unchanged (0 edits) and match the corresponding 
///   dictionary word.
/// Thus, we return ["word","note","wood"].
///
/// Example 2:
/// Input: queries = ["yes"], dictionary = ["not"]
/// Output: []
/// Explanation:
/// Applying any two edits to "yes" cannot make it equal to "not". Thus, 
/// we return an empty array.
///
/// Constraints:
/// 1. 1 <= queries.length, dictionary.length <= 100
/// 2. n == queries[i].length == dictionary[j].length
/// 3. 1 <= n <= 100
/// 4. All queries[i] and dictionary[j] are composed of lowercase English 
///    letters.
/// </summary>
vector<string> LeetCodeString::twoEditWords(vector<string>& queries, vector<string>& dictionary)
{
    vector<string> result;
    int n = queries[0].size();
    for (size_t i = 0; i < queries.size(); i++)
    {
        for (size_t j = 0; j < dictionary.size(); j++)
        {
            int mismatch = 0;
            for (int k = 0; k < n; k++)
            {
                if (queries[i][k] != dictionary[j][k])
                {
                    mismatch++;
                }
                if (mismatch > 2) break;
            }
            if (mismatch <= 2)
            {
                result.push_back(queries[i]);
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2490. Circular Sentence
/// 
/// Easy
///	
/// A sentence is a list of words that are separated by a single space 
/// with no leading or trailing spaces.
///
/// For example, "Hello World", "HELLO", "hello world hello world" are 
/// all sentences.
/// Words consist of only uppercase and lowercase English letters. 
/// Uppercase and lowercase English letters are considered different.
///
/// A sentence is circular if:
/// The last character of a word is equal to the first character of the 
/// next word.
/// The last character of the last word is equal to the first character 
/// of the first word.
/// For example, "leetcode exercises sound delightful", "eetcode", 
/// "leetcode eats soul" are all circular sentences. However, 
/// "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" 
/// are not circular sentences.
///
/// Given a string sentence, return true if it is circular. Otherwise, 
/// return false.
/// Example 1:
///
/// Input: sentence = "leetcode exercises sound delightful"
/// Output: true
/// Explanation: The words in sentence are ["leetcode", "exercises", 
/// "sound", "delightful"].
/// - leetcode's last character is equal to exercises's first character.
/// - exercises's last character is equal to sound's first character.
/// - sound's last character is equal to delightful's first character.
/// - delightful's last character is equal to leetcode's first character.
/// The sentence is circular.
///
/// Example 2:
/// Input: sentence = "eetcode"
/// Output: true
/// Explanation: The words in sentence are ["eetcode"].
/// - eetcode's last character is equal to eetcode's first character.
/// The sentence is circular.
///
/// Example 3:
/// Input: sentence = "Leetcode is cool"
/// Output: false
/// Explanation: The words in sentence are ["Leetcode", "is", "cool"].
/// - Leetcode's last character is not equal to is's first character.
/// The sentence is not circular.
///
/// Constraints:
///
/// 1. 1 <= sentence.length <= 500
/// 2. sentence consist of only lowercase and uppercase English letters 
///    and spaces.
/// 3. The words in sentence are separated by a single space.
/// 4. There are no leading or trailing spaces.
/// </summary>
bool LeetCodeString::isCircularSentence(string sentence)
{
    if (sentence[0] != sentence[sentence.size() - 1]) return false;
    for (size_t i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            if (sentence[i - 1] != sentence[i + 1]) return false;
        }
    }
    return true;
}

/// <summary>
/// Leet Code 2486. Append Characters to String to Make Subsequence
/// 
/// Medium
///	
/// You are given two strings s and t consisting of only lowercase English 
/// letters.
///
/// Return the minimum number of characters that need to be appended to 
/// the end of s so that t becomes a subsequence of s.
///
/// A subsequence is a string that can be derived from another string by 
/// deleting some or no characters without changing the order of the 
/// remaining characters.
///
/// Example 1:
/// Input: s = "coaching", t = "coding"
/// Output: 4
/// Explanation: Append the characters "ding" to the end of s so that 
/// s = "coachingding".
/// Now, t is a subsequence of s ("coachingding").
/// It can be shown that appending any 3 characters to the end of s will 
/// never make t a subsequence.
///
/// Example 2:
/// Input: s = "abcde", t = "a"
/// Output: 0
/// Explanation: t is already a subsequence of s ("abcde").
///
/// Example 3:
/// Input: s = "z", t = "abcde"
/// Output: 5
/// Explanation: Append the characters "abcde" to the end of s so that 
/// s = "zabcde".
/// Now, t is a subsequence of s ("zabcde").
/// It can be shown that appending any 4 characters to the end of s will 
/// never make t a subsequence.
///
/// Constraints:
/// 1. 1 <= s.length, t.length <= 10^5
/// 2. s and t consist only of lowercase English letters.
/// </summary>
int LeetCodeString::appendCharacters(string s, string t)
{
    size_t k = 0;
    for (size_t i = 0; i < s.size() && k < t.size(); i++)
    {
        if (s[i] == t[k])
        {
            k++;
        }
    }
    return t.size() - k;
}

/// <summary>
/// Leet Code 2496. Maximum Value of a String in an Array
/// 
/// Easy
///	
/// The value of an alphanumeric string can be defined as:
///
/// The numeric representation of the string in base 10, if it comprises 
/// of digits only.
/// The length of the string, otherwise.
/// Given an array strs of alphanumeric strings, return the maximum 
/// value of any string in strs.
///
/// Example 1:
/// Input: strs = ["alic3","bob","3","4","00000"]
/// Output: 5
/// Explanation: 
/// - "alic3" consists of both letters and digits, so its value is its 
///   length, i.e. 5.
/// - "bob" consists only of letters, so its value is also its length, 
///   i.e. 3.
/// - "3" consists only of digits, so its value is its numeric equivalent, 
///   i.e. 3.
/// - "4" also consists only of digits, so its value is 4.
/// - "00000" consists only of digits, so its value is 0.
/// Hence, the maximum value is 5, of "alic3".
/// 
/// Example 2:
/// Input: strs = ["1","01","001","0001"]
/// Output: 1
/// Explanation: 
/// Each string in the array has value 1. Hence, we return 1.
///  
/// Constraints:
/// 1. 1 <= strs.length <= 100
/// 2. 1 <= strs[i].length <= 9
/// 3. strs[i] consists of only lowercase English letters and digits.
/// </summary>
int LeetCodeString::maximumValue(vector<string>& strs)
{
    int result = 0;
    for (size_t i = 0; i < strs.size(); i++)
    {
        bool is_digit = true;
        int val = 0;
        for (size_t j = 0; j < strs[i].size(); j++)
        {
            if (!isdigit(strs[i][j]))
            {
                result = max(result, (int)strs[i].size());
                val = 0;
                break;
            }
            val = val * 10 + strs[i][j] - '0';
        }
        result = max(result, val);
    }
    return result;
}

/// <summary>
/// Leet Code 2506. Count Pairs Of Similar Strings
/// 
/// Easy
///	
/// You are given a 0-indexed string array words.
///
/// Two strings are similar if they consist of the same characters.
///
/// For example, "abca" and "cba" are similar since both consist of 
/// characters 'a', 'b', and 'c'.
/// However, "abacba" and "bcfd" are not similar since they do not 
/// consist of the same characters.
/// Return the number of pairs (i, j) such that 
/// 0 <= i < j <= word.length - 1 and the two strings words[i] and 
/// words[j] are similar.
/// 
/// Example 1:
/// Input: words = ["aba","aabb","abcd","bac","aabc"]
/// Output: 2
/// Explanation: There are 2 pairs that satisfy the conditions:
/// - i = 0 and j = 1 : both words[0] and words[1] only consist of 
///   characters 'a' and 'b'. 
/// - i = 3 and j = 4 : both words[3] and words[4] only consist of 
///   characters 'a', 'b', and 'c'. 
///
/// Example 2:
/// Input: words = ["aabb","ab","ba"]
/// Output: 3
/// Explanation: There are 3 pairs that satisfy the conditions:
/// - i = 0 and j = 1 : both words[0] and words[1] only consist of 
///   characters 'a' and 'b'. 
/// - i = 0 and j = 2 : both words[0] and words[2] only consist of 
///   characters 'a' and 'b'.
/// - i = 1 and j = 2 : both words[1] and words[2] only consist of 
///   characters 'a' and 'b'.
///
/// Example 3:
/// Input: words = ["nba","cba","dba"]
/// Output: 0
/// Explanation: Since there does not exist any pair that satisfies 
/// the conditions, we return 0.
///
/// Constraints:
/// 1. 1 <= words.length <= 100
/// 2. 1 <= words[i].length <= 100
/// 3. words[i] consist of only lowercase English letters.
/// </summary>
int LeetCodeString::similarPairs(vector<string>& words)
{
    unordered_map<string, int> str_groups;
    for (size_t i = 0; i < words.size(); i++)
    {
        vector<int> chars(26);
        for (size_t j = 0; j < words[i].size(); j++)
        {
            chars[words[i][j] - 'a']++;
        }
        string str;
        for (int j = 0; j < 26; j++)
        {
            if (chars[j] != 0)
            {
                str.push_back('a' + j);
            }
        }
        str_groups[str]++;
    }
    int result = 0;
    for (auto itr : str_groups)
    {
        result += itr.second * (itr.second - 1) / 2;
    }
    return result;
}

/// <summary>
/// Leet Code 2512. Reward Top K Students
/// 
/// Medium
///	
/// You are given two string arrays positive_feedback and 
/// negative_feedback, containing the words denoting positive and negative 
/// feedback, respectively. Note that no word is both positive and 
/// negative.
///
/// Initially every student has 0 points. Each positive word in a feedback 
/// report increases the points of a student by 3, whereas each negative 
/// word decreases the points by 1.
///
/// You are given n feedback reports, represented by a 0-indexed string 
/// array report and a 0-indexed integer array student_id, where 
/// student_id[i] represents the ID of the student who has received the 
/// feedback report report[i]. The ID of each student is unique.
///
/// Given an integer k, return the top k students after ranking them in 
/// non-increasing order by their points. In case more than one student 
/// has the same points, the one with the lower ID ranks higher.
///
/// Example 1:
/// Input: positive_feedback = ["smart","brilliant","studious"], 
/// negative_feedback = ["not"], report = ["this student is studious",
/// "the student is smart"], student_id = [1,2], k = 2
/// Output: [1,2]
/// Explanation: 
/// Both the students have 1 positive feedback and 3 points but since 
/// student 1 has a lower ID he ranks higher.
///
/// Example 2:
/// Input: positive_feedback = ["smart","brilliant","studious"], 
/// negative_feedback = ["not"], report = ["this student is not studious",
/// "the student is smart"], student_id = [1,2], k = 2
/// Output: [2,1]
/// Explanation: 
/// - The student with ID 1 has 1 positive feedback and 1 negative 
///   feedback, so he has 3-1=2 points. 
/// - The student with ID 2 has 1 positive feedback, so he has 3 points. 
/// Since student 2 has more points, [2,1] is returned.
///
/// Constraints:
/// 1. 1 <= positive_feedback.length, negative_feedback.length <= 10^4
/// 2. 1 <= positive_feedback[i].length, negative_feedback[j].length <= 100
/// 3. Both positive_feedback[i] and negative_feedback[j] consists of 
///    lowercase English letters.
/// 4. No word is present in both positive_feedback and negative_feedback.
/// 5. n == report.length == student_id.length
/// 6. 1 <= n <= 10^4
/// 7. report[i] consists of lowercase English letters and spaces ' '.
/// 8. There is a single space between consecutive words of report[i].
/// 9. 1 <= report[i].length <= 100
/// 10. 1 <= student_id[i] <= 109
/// 11. All the values of student_id[i] are unique.
/// 12. 1 <= k <= n
/// </summary>
vector<int> LeetCodeString::topStudents(
    vector<string>& positive_feedback,
    vector<string>& negative_feedback,
    vector<string>& report,
    vector<int>& student_id, int k)
{
    unordered_set<string> positives, negatives;
    for (size_t i = 0; i < positive_feedback.size(); i++)
    {
        positives.insert(positive_feedback[i]);
    }
    for (size_t i = 0; i < negative_feedback.size(); i++)
    {
        negatives.insert(negative_feedback[i]);
    }
    unordered_map<int, int> scores;
    for (size_t i = 0; i < report.size(); i++)
    {
        string word;
        scores[student_id[i]] = 0;
        for (size_t j = 0; j <= report[i].size(); j++)
        {
            if (j == report[i].size() || report[i][j] == ' ')
            {
                if (positives.count(word) > 0) scores[student_id[i]] += 3;
                if (negatives.count(word) > 0) scores[student_id[i]] -= 1;
                word.clear();
            }
            else
            {
                word.push_back(report[i][j]);
            }
        }
    }
    priority_queue<pair<int, int>> pq;
    for (auto itr : scores)
    {
        pq.push(make_pair(itr.second, -itr.first));
    }
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        if (pq.empty()) break;
        pair<int, int> p = pq.top();
        pq.pop();
        result.push_back(0 - p.second);
    }
    return result;
}

/// <summary>
/// Leet Code 2516. Take K of Each Character From Left and Right
/// 
/// Medium
///	
/// You are given a string s consisting of the characters 'a', 'b', 
/// and 'c' and a non-negative integer k. Each minute, you may take 
/// either the leftmost character of s, or the rightmost character of s.
///
/// Return the minimum number of minutes needed for you to take at least 
/// k of each character, or return -1 if it is not possible to take k of 
/// each character.
///
/// Example 1:
/// Input: s = "aabaaaacaabc", k = 2
/// Output: 8
/// Explanation: 
/// Take three characters from the left of s. You now have two 'a' 
/// characters, and one 'b' character.
/// Take five characters from the right of s. You now have four 'a' 
/// characters, two 'b' characters, and two 'c' characters.
/// A total of 3 + 5 = 8 minutes is needed.
/// It can be proven that 8 is the minimum number of minutes needed.
///
/// Example 2:
/// Input: s = "a", k = 1
/// Output: -1
/// Explanation: It is not possible to take one 'b' or 'c' so return -1.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of only the letters 'a', 'b', and 'c'.
/// 3. 0 <= k <= s.length
/// </summary>
int LeetCodeString::takeCharacters(string s, int k)
{
    int result = INT_MAX;
    if (k == 0) return 0;
    int n = s.size();
    s = s.append(s);
    vector<int> a, b, c;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a') a.push_back(i);
        else if (s[i] == 'b') b.push_back(i);
        else if (s[i] == 'c') c.push_back(i);

        if ((int)a.size() >= k && (int)b.size() >= k && (int)c.size() >= k)
        {
            int first = 0;
            if ((int)i >= n - 1)
            {
                first = a[a.size() - k];
                first = min(first, b[b.size() - k]);
                first = min(first, c[c.size() - k]);
            }
            if (first < n && (int)(i)-first < n)
            {
                result = min(result, (int)(i)-first + 1);
            }
        }
    }
    if (result == INT_MAX) return -1;
    else return result;
}

/// <summary>
/// Leet Code 2522. Partition String Into Substrings With Values at Most K
/// 
/// Medium
///	
/// You are given a string s consisting of digits from 1 to 9 and an 
/// integer k.
///
/// A partition of a string s is called good if:
///
/// Each digit of s is part of exactly one substring.
/// The value of each substring is less than or equal to k.
/// Return the minimum number of substrings in a good partition of s. 
/// If no good partition of s exists, return -1.
///
/// Note that:
/// The value of a string is its result when interpreted as an integer. 
/// For example, the value of "123" is 123 and the value of "1" is 1.
/// A substring is a contiguous sequence of characters within a string.
/// 
/// Example 1:
/// Input: s = "165462", k = 60
/// Output: 4
/// Explanation: We can partition the string into substrings "16", "54", 
/// "6", and "2". Each substring has a value less than or equal to k = 60.
/// It can be shown that we cannot partition the string into less than 4 
/// substrings.
///
/// Example 2:
/// Input: s = "238182", k = 5
/// Output: -1
/// Explanation: There is no good partition for this string.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s[i] is a digit from '1' to '9'.
/// 3. 1 <= k <= 10^9
/// </summary>
int LeetCodeString::minimumPartition(string s, int k)
{
    string str;
    int result = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' > k) return -1;
        str.push_back(s[i]);
        long long val = atol(str.c_str());
        if (val > (long long)k)
        {
            result++;
            str.clear();
            str.push_back(s[i]);
        }
    }
    result++;
    return result;
}

/// <summary>
/// Leet Code 2531. Make Number of Distinct Characters Equal
/// 
/// Medium
///	
/// You are given two 0-indexed strings word1 and word2.
///
/// A move consists of choosing two indices i and j such that 
/// 0 <= i < word1.length and 0 <= j < word2.length and swapping 
/// word1[i] with word2[j].
///
/// Return true if it is possible to get the number of distinct 
/// characters in word1 and word2 to be equal with exactly one move. 
/// Return false otherwise.
/// 
/// Example 1:
/// Input: word1 = "ac", word2 = "b"
/// Output: false
/// Explanation: Any pair of swaps would yield two distinct characters 
/// in the first string, and one in the second string.
///
/// Example 2:
/// Input: word1 = "abcc", word2 = "aab"
/// Output: true
/// Explanation: We swap index 2 of the first string with index 0 of the 
/// second string. The resulting strings are word1 = "abac" and 
/// word2 = "cab", which both have 3 distinct characters.
///
/// Example 3:
/// Input: word1 = "abcde", word2 = "fghij"
/// Output: true
/// Explanation: Both resulting strings will have 5 distinct characters, 
/// regardless of which indices we swap.
///
/// Constraints:
/// 1. 1 <= word1.length, word2.length <= 10^5
/// 2. word1 and word2 consist of only lowercase English letters.
/// </summary>
bool LeetCodeString::isItPossible(string word1, string word2)
{
    vector<int> str1_count(26), str2_count(26);
    int count1 = 0, count2 = 0;
    for (size_t i = 0; i < word1.size(); i++)
    {
        str1_count[word1[i] - 'a']++;
        if (str1_count[word1[i] - 'a'] == 1) count1++;
    }
    for (size_t i = 0; i < word2.size(); i++)
    {
        str2_count[word2[i] - 'a']++;
        if (str2_count[word2[i] - 'a'] == 1) count2++;
    }
    for (int a = 0; a < 26; a++)
    {
        if (str1_count[a] == 0) continue;
        for (int b = 0; b < 26; b++)
        {
            if (str2_count[b] == 0) continue;
            str1_count[a]--;
            if (str1_count[a] == 0) count1--;
            str1_count[b]++;
            if (str1_count[b] == 1) count1++;
            str2_count[a]++;
            if (str2_count[a] == 1) count2++;
            str2_count[b]--;
            if (str2_count[b] == 0) count2--;
            if (count1 == count2) return true;

            str1_count[a]++;
            if (str1_count[a] == 1) count1++;
            str1_count[b]--;
            if (str1_count[b] == 0) count1--;
            str2_count[a]--;
            if (str2_count[a] == 0) count2--;
            str2_count[b]++;
            if (str2_count[b] == 1) count2++;
        }
    }
    return false;
}

/// <summary>
/// Leet Code 2565. Subsequence With the Minimum Score
/// 
/// Hard
///	
/// You are given two strings s and t.
/// You are allowed to remove any number of characters from the string t.
/// The score of the string is 0 if no characters are removed from the 
/// string t, otherwise:
///
/// Let left be the minimum index among all removed characters.
/// Let right be the maximum index among all removed characters.
/// Then the score of the string is right - left + 1.
///
/// Return the minimum possible score to make t a subsequence of s.
///
/// A subsequence of a string is a new string that is formed from the 
/// original string by deleting some (can be none) of the characters 
/// without disturbing the relative positions of the remaining 
/// characters. (i.e., "ace" is a subsequence of "abcde" while 
/// "aec" is not).
/// 
/// Example 1:
/// Input: s = "abacaba", t = "bzaa"
/// Output: 1
/// Explanation: In this example, we remove the character "z" at 
/// index 1 (0-indexed).
/// The string t becomes "baa" which is a subsequence of the string 
/// "abacaba" and the score is 1 - 1 + 1 = 1.
/// It can be proven that 1 is the minimum score that we can achieve.
///
/// Example 2:
/// Input: s = "cde", t = "xyz"
/// Output: 3
/// Explanation: In this example, we remove characters "x", "y" and 
/// "z" at indices 0, 1, and 2 (0-indexed).
/// The string t becomes "" which is a subsequence of the string 
/// "cde" and the score is 2 - 0 + 1 = 3.
/// It can be proven that 3 is the minimum score that we can achieve.
/// 
/// Constraints:
/// 1. 1 <= s.length, t.length <= 10^5
/// 2. s and t consist of only lowercase English letters.
/// </summary>
int LeetCodeString::minimumScore(string s, string t)
{
    vector<pair<int, int>> dp(t.size(), { -1, -1 });
    int p = 0;
    for (size_t i = 0; i < s.size() && p < (int)t.size(); i++)
    {
        if (s[i] == t[p])
        {
            dp[p].first = i;
            p++;
        }
    }
    p = t.size() - 1;
    for (int i = s.size() - 1; i >= 0 && p >= 0; i--)
    {
        if (s[i] == t[p])
        {
            dp[p].second = i;
            p--;
        }
    }
    int result = t.size();
    p = 0;
    for (int i = 0; i < (int)t.size(); i++)
    {
        if (dp[i].first == -1)
        {
            result = min((int)t.size() - i, result);
            p = 0;
            while (p < (int)t.size() && dp[p].second == -1) p++;
            result = min(result, p);
            break;
        }
        if (p <= i) p = i + 1;
        while (p < (int)t.size() && dp[p].second <= dp[i].first)
        {
            p++;
        }
        result = min(result, p - i - 1);
    }
    return result;
}

/// <summary>
/// Leet Code 2586. Count the Number of Vowel Strings in Range
/// 
/// Easy
///	
/// You are given a 0-indexed array of string words and two integers left 
/// and right.
///
/// A string is called a vowel string if it starts with a vowel character 
/// and ends with a vowel character where vowel characters are 
/// 'a', 'e', 'i', 'o', and 'u'.
///
/// Return the number of vowel strings words[i] where i belongs to the 
/// inclusive range [left, right].
///
/// Example 1:
///
/// Input: words = ["are","amy","u"], left = 0, right = 2
/// Output: 2
/// Explanation: 
/// - "are" is a vowel string because it starts with 'a' and ends with 'e'.
/// - "amy" is not a vowel string because it does not end with a vowel.
/// - "u" is a vowel string because it starts with 'u' and ends with 'u'.
/// The number of vowel strings in the mentioned range is 2.
///
/// Example 2:
/// Input: words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
/// Output: 3
/// Explanation: 
/// - "aeo" is a vowel string because it starts with 'a' and ends with 'o'.
/// - "mu" is not a vowel string because it does not start with a vowel.
/// - "ooo" is a vowel string because it starts with 'o' and ends with 'o'.
/// - "artro" is a vowel string because it starts with 'a' and ends 
///   with 'o'.
/// The number of vowel strings in the mentioned range is 3.
///
///
/// Constraints:
/// 1. 1 <= words.length <= 1000
/// 2. 1 <= words[i].length <= 10
/// 3. words[i] consists of only lowercase English letters.
/// 4. 0 <= left <= right < words.length
/// </summary>
int LeetCodeString::vowelStrings(vector<string>& words, int left, int right)
{
    unordered_set<char> vowels = {'a','e','i','o','u'};
    int result = 0;
    for (int i = left; i <= right; i++)
    {
        if (vowels.count(words[i][0]) > 0 &&
            vowels.count(words[i].back()) > 0)
        {
            result++;
        }
    }
    return result;
}
#pragma endregion
