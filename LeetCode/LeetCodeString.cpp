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
    int begin = 0;
    int result = 0;
    for (int end = 0; end < (int)s.size(); end++)
    {
        char_count[s[end]]++;
        while (char_count[s[end]] > 1)
        {
            char_count[s[begin]]--;
            begin++;
        }
        result = max(result, end - begin + 1);
    }
    return result;
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
    vector<int> char_map(128);
    for (size_t i = 0; i < t.size(); i++)
    {
        char_map[t[i]]++;
    }
    int count = t.size();
    int begin = 0;

    string result;
    for (int end = 0; end < (int)s.size(); end++)
    {
        if (char_map[s[end]] > 0)
        {
            count--;
        }
        char_map[s[end]]--;
        // Do we have all the characters matched
        if (count > 0) continue;

        // reduce slide window, until break the condition
        while (count == 0)
        {
            if (result.empty() || (end - begin + 1) < (int)result.size())
            {
                result = s.substr(begin, end - begin + 1);
            }
            char_map[s[begin]]++;
            if (char_map[s[begin]] > 0)
            {
                count++;
            }
            begin++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #87. Scramble String 
/// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively. 
/// Below is one possible representation of s1 = "great": 
///      great
///     /    \
///    gr    eat
///   / \    /  \
///  g   r  e   at
///            / \
///           a   t
///
/// To scramble the string, we may choose any non-leaf node and swap its two children. 
/// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat". 
///      rgeat
///     /    \
///    rg    eat
///   / \    /  \
///  r   g  e   at
///            / \
///           a   t
/// We say that "rgeat" is a scrambled string of "great". 
/// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae". 
///      rgtae
///     /    \
///    rg    tae
///   / \    /  \
///  r   g  ta  e
///        / \
///       t   a
/// We say that "rgtae" is a scrambled string of "great". 
/// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
/// </summary>
bool LeetCode::isScramble(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    if (s1 == s2) return true;
    size_t len = s1.size();

    vector<int> alpha_table(26, 0);

    for (size_t i = 0; i < len; i++)
    {
        alpha_table[s1[i] - 'a']++;
    }
    for (size_t i = 0; i < len; i++)
    {
        alpha_table[s2[i] - 'a']--;
    }
    for (size_t i = 0; i < 26; i++)
    {
        if (alpha_table[i] != 0) return false;
    }

    for (size_t i = 1; i < len; i++)
    {
        string sub1 = s1.substr(0, i);
        string sub2 = s1.substr(i, len - i);

        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i, len - i), s2.substr(i, len - i)))
        {
            return true;
        }

        if (isScramble(s1.substr(0, i), s2.substr(len - i, i)) &&
            isScramble(s1.substr(i, len - i), s2.substr(0, len - i)))
        {
            return true;
        }
    }
    return false;
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
bool LeetCodeString::isAnagram(string s, string t)
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
/// Given a string which consists of lowercase or uppercase letters, find the length of the longest 
/// palindromes that can be built with those letters. 
/// This is case sensitive, for example "Aa" is not considered a palindrome here.
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
int LeetCode::longestPalindromeII(string s)
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
/// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
/// When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
/// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
///
/// For example,
/// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
/// Return:
/// ["AAAAACCCCC", "CCCCCAAAAA"].
/// </summary>
vector<string> LeetCode::findRepeatedDnaSequences(string s)
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
/// Leet code #205. Isomorphic Strings     
/// Given two strings s and t, determine if they are isomorphic. 
/// Two strings are isomorphic if the characters in s can be replaced to get t.
/// All occurrences of a character must be replaced with another character while 
/// preserving the order of characters. No two characters may map to the same 
/// character but a character may map to itself.
/// For example,
/// Given "egg", "add", return true.
///
/// Given "foo", "bar", return false.
/// Given "paper", "title", return true.
/// Note:
/// You may assume both s and t have the same length.
/// </summary>
bool LeetCode::isIsomorphic(string s, string t)
{
    unordered_map<char, char> char_map;
    unordered_set<char> used_chars;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (char_map.find(s[i]) == char_map.end())
        {
            if (used_chars.find(t[i]) == used_chars.end())
            {
                char_map[s[i]] = t[i];
                used_chars.insert(t[i]);
            }
            else
            {
                return false;
            }
        }
        else if (char_map[s[i]] != t[i])
        {
            return false;
        }
    }
    return true;
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
/// Given a pattern and a string str, find if str follows the same pattern.
/// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
/// Examples:
/// 1.pattern = "abba", str = "dog cat cat dog" should return true.
/// 2.pattern = "abba", str = "dog cat cat fish" should return false.
/// 3.pattern = "aaaa", str = "dog cat cat dog" should return false.
/// 4.pattern = "abba", str = "dog dog dog dog" should return false.
/// Notes:
/// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
/// </summary>
bool LeetCode::wordPattern(string pattern, string str)
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
bool LeetCode::isValidNumber(string s)
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
int LeetCode::strongPasswordChecker(string s)
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
/// Leet code #289. Game of Life 
/// According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
/// is a cellular automaton devised by the British mathematician John Horton Conway in 1970." 
/// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
/// Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the 
/// following four rules (taken from the above Wikipedia article): 	
/// 1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.
/// 2.Any live cell with two or three live neighbors lives on to the next generation.
/// 3.Any live cell with more than three live neighbors dies, as if by over-population..
/// 4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
/// Write a function to compute the next state (after one update) of the board given its current state.
/// Follow up: 
/// 1.Could you solve it in-place? Remember that the board needs to be updated at the same time: You 
/// cannot update some cells first and then use their updated values to update other cells.
/// 2.In this question, we represent the board using a 2D array. In principle, the board is infinite, 
/// which would cause problems when the active area encroaches the border of the array. How would you address 
/// these problems?
/// </summary>
void LeetCode::gameOfLife(vector<vector<int>>& board)
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
/// Leet code #393. UTF-8 Validation
/// A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
/// 1.For 1-byte character, the first bit is a 0, followed by its unicode code.
/// 2.For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed 
///   by n-1 bytes with most significant 2 bits being 10.
/// This is how the UTF-8 encoding would work:
///   Char. number range  |        UTF-8 octet sequence
///      (hexadecimal)    |              (binary)
///   --------------------+---------------------------------------------
///   0000 0000-0000 007F | 0xxxxxxx
///   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
///   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
///   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
/// Given an array of integers representing the data, return whether it is a valid utf-8 encoding. 
/// Note:
/// The input is an array of integers. Only the least significant 8 bits of each integer is used 
/// to store the data. This means each integer represents only 1 byte of data. 
/// Example 1: 
/// data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
/// Return true.
/// It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
/// Example 2: 
/// data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.
/// Return false.
/// The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
/// The next byte is a continuation byte which starts with 10 and that's correct.
/// But the second continuation byte does not start with 10, so it is invalid.
/// </summary>
bool LeetCode::validUtf8(vector<int>& data)
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
bool LeetCode::isAdditiveNumber(string num1, string num2, string num)
{
    if ((num1[0] == '0' && num1.size() > 1) || (num2[0] == '0' && num2.size() > 1))
    {
        return false;
    }

    LeetCodeString leetCode;
    string num3 = leetCode.addStrings(num1, num2);
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
bool LeetCode::isAdditiveNumber(string num)
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
string LeetCode::shortestPalindrome(string s)
{
    string result;
    vector<int> kmp_table(s.size());
    int count = 0;
    size_t pos = 2;
    while (pos < s.size())
    {
        if (s[pos - 1] == s[count])
        {
            count++;
            kmp_table[pos] = count;
            pos++;
        }
        else
        {
            if (count > 0) count = kmp_table[count];
            else pos++;
        }
    }
    int first = 0, last = s.size() - 1;
    while (first < last)
    {
        if (s[first] == s[last])
        {
            first++;
            last--;
        }
        else
        {
            if (first > 0)
            {
                first = kmp_table[first];
            }
            else last--;
        }
    }
    for (int i = s.size() - 1; i > first + last; i--)
    {
        result.push_back(s[i]);
    }
    result.append(s);
    return result;
}

/// <summary>
/// Leet code #336. Palindrome Pairs    
/// 
/// Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
/// so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome. 
/// Example 1:
/// Given words = ["bat", "tab", "cat"]
/// Return [[0, 1], [1, 0]]
///
/// Example 2:
/// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
/// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
/// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
/// </summary>
vector<vector<int>> LeetCode::palindromePairs(vector<string>& words)
{
    vector<vector<int>> result;
    unordered_map<string, int> reverse_map;
    TrieNode trie_root;
    for (size_t i = 0; i < words.size(); i++)
    {
        string str = words[i];
        int first = 0;
        int last = str.size() - 1;
        while (first < last)
        {
            swap(str[first], str[last]);
            first++; last--;
        }
        reverse_map[str] = i;
        trie_root.insert(str, 0);
    }

    for (size_t i = 0; i < words.size(); i++)
    {
        string str = words[i];
        vector<string> match_words;
        trie_root.getMatchWords(str, 0, match_words);
        for (string word : match_words)
        {
            int j = reverse_map[word];
            if (i == j) continue;
            string combination = words[i] + words[j];
            if (isPalindrome(combination))
            {
                vector<int> pair;
                pair.push_back(i);
                pair.push_back(j);
                result.push_back(pair);
                if (str == "")
                {
                    pair.clear();
                    pair.push_back(j);
                    pair.push_back(i);
                    result.push_back(pair);
                }
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
/// Both the string's length and k will not exceed 104. 
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
/// (consists of lowercase letters only) such that every character in T appears no less than k times. 
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
    if (s.size() == 0 || k > (int)s.size())   return 0;
    if (k == 0)  return s.size();
    vector<int> char_count(26);
    for (char ch : s)
    {
        char_count[ch - 'a']++;
    }
    size_t index = 0;
    while ((index < s.size()) && (char_count[s[index] - 'a'] >= k))
    {
        index++;
    }
    if (index == s.size()) return s.size();
    int left = longestSubstring(s.substr(0, index), k);
    int right = longestSubstring(s.substr(index + 1), k);
    return max(left, right);
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
bool LeetCode::canPermutePalindrome(string s)
{
    unordered_map<char, int> char_count;
    for (char ch : s)
    {
        char_count[ch]++;
    }
    int odd_count = 0;
    for (auto x : char_count)
    {
        odd_count += (x.second % 2 == 1) ? 1 : 0;
        if (odd_count > 1) return false;
    }
    return true;
}

/// <summary>
/// Leet code #293. Flip Game  
/// 
/// You are playing the following Flip Game with your friend: Given a string that 
/// contains only these two characters: + and -, you and your friend take turns to 
/// flip two consecutive "++" into "--". The game ends when a person can no longer 
/// make a move and therefore the other person will be the winner. 
/// Write a function to compute all possible states of the string after one valid move. 
/// For example, given s = "++++", after one move, it may become one of the following states: 
/// [
///    "--++",
///    "+--+",
///    "++--"
/// ]
/// If there is no valid move, return an empty list [].
/// </summary>
vector<string> LeetCode::generatePossibleNextMoves(string s)
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
bool LeetCode::isStrobogrammatic(string num)
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
vector<vector<string>> LeetCode::groupStrings(vector<string>& strings)
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
bool LeetCode::validWordAbbreviation(string word, string abbr)
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
/// Now you are given a string S, which represents a software license key which we would 
/// like to format. The string S is composed of alphanumerical characters and dashes. 
/// The dashes split the alphanumerical characters within the string into groups. 
/// (i.e. if there are M dashes, the string is split into M+1 groups). 
/// The dashes in the given string are possibly misplaced.
///
/// We want each group of characters to be of length K (except for possibly the first group, 
/// which could be shorter, but still must contain at least one character). To satisfy this 
/// requirement, we will reinsert dashes. Additionally, all the lower case letters in the 
/// string must be converted to upper case.
/// So, you are given a non-empty string S, representing a license key to format, and an integer K. 
/// And you need to return the license key formatted according to the description above.
/// Example 1:
/// Input: S = "2-4A0r7-4k", K = 4
/// Output: "24A0-R74K"
/// Explanation: The string S has been split into two parts, each part has 4 characters.
/// Example 2:
/// Input: S = "2-4A0r7-4k", K = 3
/// Output: "24-A0R-74K"
/// Explanation: The string S has been split into three parts, each part has 3 characters except the first part as it could be shorter as said above.
/// Note:
/// 1.The length of string S will not exceed 12,000, and K is a positive integer.
/// 2.String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
/// 3.String S is non-empty.
/// </summary>
string LeetCode::licenseKeyFormatting(string S, int K)
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
int LeetCode::magicalString(int n)
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
int LeetCode::read4(char *buff, string& s, int& index)
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
int LeetCode::readNChars(char *buf, int n, string &s)
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
int LeetCode::readNCharsII(char *buf, int n, string& s, int& index, string&m_buffer)
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
/// Given a string, find the length of the longest substring T that contains at most 
/// 2 distinct characters. 
/// For example, Given s = “eceba”, 
/// T is "ece" which its length is 3.
/// </summary>
int LeetCode::lengthOfLongestSubstringTwoDistinct(string s)
{
    unordered_map<char, int> char_map;
    size_t max_length = 0;
    size_t first = 0, last = 0;
    while (last < s.size())
    {
        if (char_map.size() == 3)
        {
            char_map[s[first]]--;
            if (char_map[s[first]] == 0)
            {
                char_map.erase(s[first]);
            }
            first++;
        }
        else
        {
            char_map[s[last]]++;
            last++;
            if (char_map.size() < 3)
            {
                max_length = max(max_length, last - first);
            }
        }
    }
    return max_length;
}

/// <summary>
/// Leet code #340. Longest Substring with At Most K Distinct Characters       
/// 
/// Given a string, find the length of the longest substring T that contains at most k distinct characters. 
/// For example, Given s = “eceba” and k = 2,  
/// T is "ece" which its length is 3. 
/// </summary>
int LeetCode::lengthOfLongestSubstringKDistinct(string s, int k)
{
    unordered_map<char, int> char_map;
    int max_length = 0;
    int first = 0, last = 0;
    while (last < (int)s.size())
    {
        if (char_map.size() == k + 1)
        {
            char_map[s[first]]--;
            if (char_map[s[first]] == 0)
            {
                char_map.erase(s[first]);
            }
            first++;
        }
        else
        {
            char_map[s[last]]++;
            last++;
            if ((int)char_map.size() < k + 1)
            {
                max_length = max(max_length, last - first);
            }
        }
    }
    return max_length;
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
int LeetCode::findSubstringInWraproundString(string p)
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
    for (auto itr : str_map)
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
string LeetCode::findLongestWord(string s, vector<string>& d)
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
string LeetCode::reverseStr(string s, int k)
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
string LeetCode::makeAbbreviation(string& word, int k)
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
vector<string> LeetCode::wordsAbbreviation(vector<string>& dict)
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
bool LeetCode::isSubsequence(string s, string t)
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
int LeetCode::findLUSlength(string a, string b)
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
int LeetCode::findLUSlength(vector<string>& strs)
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
        for (auto str_cnt : itr->second)
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
string LeetCode::reverseWordsIII(string s)
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
bool LeetCode::checkRecord(string s)
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
bool LeetCode::checkInclusion(string s1, string s2)
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
vector<vector<string>> LeetCode::findDuplicate(vector<string>& paths)
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
    for (auto itr : file_map)
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
string LeetCode::addBoldTag(string s, vector<string>& dict)
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
string LeetCode::getTag(string code, size_t &pos)
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
bool LeetCode::isValid(string code)
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
string LeetCode::solveEquation(string equation)
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
string LeetCode::replaceWord(unordered_map<int, unordered_set<string>>&dict_map, const string&word)
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
string LeetCode::replaceWords(vector<string>& dict, string sentence)
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
string LeetCode::longestWord(vector<string>& words)
{
    unordered_map<int, set<string>> word_map;
    for (string word : words)
    {
        word_map[word.size() - 1].insert(word);
    }
    int length = 1;
    while (true)
    {
        set<string> candidates;
        for (string word : word_map[length])
        {
            // the string with (0, length -1) exist?
            if (word_map[length - 1].count(word.substr(0, length)) > 0)
            {
                candidates.insert(word);
            }
        }
        word_map[length] = candidates;

        // when candidates is empty, no more expansion
        if (candidates.empty()) break;
        length++;
    }
    // if no result in length - 1, which means no word with length as 1, 
    // return empty string
    if (word_map[length - 1].empty()) return "";
    else return  *word_map[length - 1].begin();
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
vector<string> LeetCode::removeComments(vector<string>& source)
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
string LeetCode::parseAtom(string &formula, int& index)
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
int LeetCode::parseAtomCount(string &formula, int& index)
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
void LeetCode::multiplyFormula(map<string, int> &atom_count, int& count)
{
    for (auto itr : atom_count)
    {
        atom_count[itr.first] = itr.second * count;
    }
}

/// <summary>
/// Leet code #726. Number of Atoms
/// </summary>
void LeetCode::mergeFormula(map<string, int> &atom_count, vector<map<string, int>>& formula_array)
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
string LeetCode::countOfAtoms(string formula)
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
    for (auto itr : formula_array.back())
    {
        result += itr.first;
        if (itr.second > 1) result += to_string(itr.second);
    }
    return result;
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
string LeetCode::parseLispToken(string& expression, int& index)
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
int LeetCode::calculateLispCommand(string& command, vector<string>& parameters, unordered_map<string, int>&variables)
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
int LeetCode::processLispCommand(string& expression, int& index, unordered_map<string, int> variables)
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
int LeetCode::evaluate(string expression)
{
    int index = 0;
    unordered_map<string, int> variables;
    return processLispCommand(expression, index, variables);
}

/// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
int LeetCode::processLispExpression(vector<string>& tokens, int& index, unordered_map<string, int> variables)
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
int LeetCode::processLispCommand(vector<string>& tokens, int& index, unordered_map<string, int> variables)
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
int LeetCode::evaluate_V2(string expression)
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
unsigned int LeetCode::convertIpV4ToInt(string ipV4)
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
string LeetCode::convertIntToIpV4(unsigned int ipV4)
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
vector<string> LeetCode::ipToCIDR(string ip, int range)
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
string LeetCode::makeLargestSpecial(string S)
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
string LeetCode::boldWords(vector<string>& words, string S)
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
int LeetCodeString::parseTerm(vector<string>& tokens, int& index)
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
int LeetCodeString::parseFactor(vector<string>& tokens, int& index)
{
    int result = parseTerm(tokens, index);
    while (index < (int)tokens.size())
    {
        if (tokens[index] == "*")
        {
            index++;
            result *= parseTerm(tokens, index);
        }
        else if (tokens[index] == "/")
        {
            index++;
            result /= parseTerm(tokens, index);
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
    int result = parseFactor(tokens, index);
    while (index < (int)tokens.size())
    {
        if (tokens[index] == "+")
        {
            index++;
            result += parseFactor(tokens, index);
        }
        else if (tokens[index] == "-")
        {
            index++;
            result -= parseFactor(tokens, index);
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
    typedef struct
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
int LeetCode::numJewelsInStones(string J, string S)
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
vector<int> LeetCode::partitionLabels(string S)
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
string LeetCode::reorganizeString(string S)
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
bool LeetCode::canTransform(string start, string end)
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
string LeetCode::customSortString(string S, string T)
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
int LeetCode::uniqueMorseRepresentations(vector<string>& words)
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
vector<int> LeetCode::numberOfLines(vector<int>& widths, string S)
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
void LeetCode::expressiveWords(string str, vector<pair<char, int>>& str_code)
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
int LeetCode::expressiveWords(string S, vector<string>& words)
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
string LeetCode::mostCommonWord(string paragraph, vector<string>& banned)
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
int LeetCode::minimumLengthEncoding(vector<string>& words)
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
string LeetCode::toGoatLatin(string S)
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
string LeetCode::maskPII(string S)
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
string LeetCode::findReplaceString(string S, vector<int>& indexes,
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
/// Leet code #843. Guess the Word
/// </summary>
int LeetCode::match(string strA, string strB)
{
    int result = 0;
    for (size_t i = 0; i < strA.size(); i++)
    {
        if (strA[i] == strB[i])
        {
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #843. Guess the Word
/// 
/// This problem is an interactive problem new to the LeetCode platform.
///  
/// We are given a word list of unique words, each word is 6 letters long, 
/// and one word in this list is chosen as secret.
/// 
/// You may call master.guess(word) to guess a word.  The guessed word 
/// should have type string and must be from the original list with 6 
/// lowercase letters.
///
/// This function returns an integer type, representing the number of 
/// exact matches (value and position) of your guess to the secret word.  
/// Also, if your guess is not in the given wordlist, it will return -1 
/// instead.
///
/// For each test case, you have 10 guesses to guess the word. At the end 
/// of any number of calls, if you have made 10 or less calls to 
/// master.guess and at least one of these guesses was the secret, you
/// pass the testcase.
///
/// Besides the example test case below, there will be 5 additional test 
/// cases, each with 100 words in the word list.  The letters of each word 
/// in those testcases were chosen independently at random from 'a' to 'z', 
/// such that every word in the given word lists is unique.
///
/// Example 1:
/// Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz",
/// "abcczz"]
/// 
/// Explanation:
/// master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
/// master.guess("acckzz") returns 6, because "acckzz" is secret and has 
/// all 6 matches.
/// master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
/// master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
/// master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
///
/// We made 5 calls to master.guess and one of them was the secret, so we 
/// pass the test case.
/// Note:  Any solutions that attempt to circumvent the judge will 
/// result in disqualification.
/// </summary>
string LeetCode::findSecretWord(vector<string>& wordlist, Master& master)
{
    vector<int> zero_match(wordlist.size());
    for (size_t i = 0; i < wordlist.size(); i++)
    {
        for (size_t j = 0; j < wordlist.size(); j++)
        {
            if (match(wordlist[i], wordlist[j]) == 0)
            {
                zero_match[i]++;
            }
        }
    }
    int min_match = 0;
    for (size_t i = 0; i < wordlist.size(); i++)
    {
        if (zero_match[i] < zero_match[min_match]) min_match = i;
    }
    int result = master.guess(wordlist[min_match]);
    if (result == 6) return wordlist[min_match];
    vector<string> new_word_list;
    for (size_t i = 0; i < wordlist.size(); i++)
    {
        if (match(wordlist[i], wordlist[min_match]) == result)
        {
            new_word_list.push_back(wordlist[i]);
        }
    }
    return findSecretWord(new_word_list, master);
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
vector<int> LeetCode::splitIntoFibonacci(string S)
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
bool LeetCode::backspaceCompare(string S, string T)
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
string LeetCode::shiftingLetters(string S, vector<int>& shifts)
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
bool LeetCode::buddyStrings(string A, string B)
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
int LeetCode::numSpecialEquivGroups(vector<string>& A)
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
int LeetCode::countkDist(string str, int k)
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
string LeetCode::orderlyQueue(string S, int K)
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
bool LeetCode::isLongPressedName(string name, string typed)
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
int LeetCode::numUniqueEmails(vector<string>& emails)
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
string LeetCode::parsePhrase(string& line, int &pos)
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
vector<string> LeetCode::parseLine(string& line)
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
vector<vector<string>> LeetCode::parseCSV(vector<string>& lines)
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
vector<string> LeetCode::reorderLogFiles(vector<string>& logs)
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
vector<string> LeetCode::commonChars(vector<string>& A)
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
string LeetCode::removeOuterParentheses(string S)
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
vector<bool> LeetCode::camelMatch(vector<string>& queries, string pattern)
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
string LeetCode::lastSubstring(string s)
{
    queue<pair<int, char>> search;
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
#pragma endregion
