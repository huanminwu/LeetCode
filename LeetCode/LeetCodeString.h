#pragma once
#ifndef LeetCodeString_H
#define LeetCodeString_H
#include <stdint.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> 
#include <functional> 
#include <bitset> 
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <vector> 
#include <stack> 
#include "leetcode.h"

using namespace std;

/// <summary>
/// The class is to implement array related algorithm  
/// </summary>
class LeetCodeString
{
public:
#pragma region String
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
    int maxPower(string s);

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
    int strStr(string haystack, string needle);

    /// <summary>
    /// Leet code #30. Substring with Concatenation of All Words 
    ///
    /// You are given a string, s, and a list of words, words, 
    /// that are all of the same length. Find all starting indices of 
    /// substring(s) in s that is a concatenation of each word in 
    /// words exactly once and without any intervening characters. 
    /// For example, given:
    /// s: "barfoothefoobarman"
    /// words: ["foo", "bar"] 
    /// You should return the indices: [0,9].
    /// </summary> 
    vector<int> findSubstring(string s, vector<string>& words);

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
    bool isValidNumber(string s);

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
    bool isIsomorphic(string s, string t);

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
    bool isPalindrome(string s);

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
    bool wordBreak(string s, vector<string>& wordDict);

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
    vector<string> findRepeatedDnaSequences(string s);

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
    string shortestPalindrome(string s);

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
    bool wordPattern(string pattern, string str);

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
    vector<vector<int>> palindromePairs(vector<string>& words);

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
    vector<string> generatePossibleNextMoves(string s);

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
    bool validUtf8(vector<int>& data);

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
    int longestPalindromeII(string s);

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
    string licenseKeyFormatting(string S, int K);

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
    vector<string> removeSubfolders(vector<string> & folder); 

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
    ///Input: s = "QWER"
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
    int balancedString(string s);

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
    int minimumSwap(string s1, string s2);

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
    string addStrings(string num1, string num2);

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
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord);

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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize);

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
    /// Example 4:
    /// Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
    /// Output: "abcdefghijklmnopqrstuvwxyz"
    ///  
    /// Constraints:
    /// 1. 1 <= s.length <= 1000
    /// 2. s[i] only contains digits letters ('0'-'9') and '#' letter.
    /// 3. s will be valid string such that mapping is always possible.
    /// </summary>
    string freqAlphabets(string s);

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
    int distinctEchoSubstrings(string text);

    /// <summary>
    /// Leet code #459. Repeated Substring Pattern  
    /// Given a non-empty string check if it can be constructed by taking a substring of it 
    /// and appending multiple copies of the substring together. You may assume the given string 
    /// consists of lowercase English letters only and its length will not exceed 10000. 
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
    /// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
    ///
    /// </summary>
    bool repeatedSubstringPattern(string s);

    /// <summary>
    /// Leet code #686. Repeated String Match
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
    int repeatedStringMatch(string A, string B);

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
    bool rotateString(string A, string B);

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
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases);

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
    int maxNumberOfBalloons(string text);

    /// <summary>
    /// Leet code #1170. Compare Strings by Frequency of the Smallest Character
    /// </summary>
    int numSmallerByFrequency(string word);

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
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words);

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
    int calculateTime(string keyboard, string word);

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
    vector<vector<int>> largeGroupPositions(string S);

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
    int lengthOfLastWord(string s);

    /// <summary>
    /// Leet code #165. Compare Version Numbers
    ///
    /// Compare two version numbers version1 and version2.
    /// If version1 > version2 return 1, if version1 < version2 return -1, 
    /// otherwise return 0. 
    /// You may assume that the version strings are non-empty and contain 
    /// only digits and the . character.
    /// The . character does not represent a decimal point and is used to 
    /// separate number sequences.
    /// For instance, 2.5 is not "two and a half" or "half way to version 
    /// three", it is the fifth second-level revision of the second 
    /// first-level revision.
    /// Here is an example of version numbers ordering:
    /// 0.1 < 1.1 < 1.2 < 13.37 
    /// </summary>
    int compareVersion(string version1, string version2);

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
    string simplifyPath(string path);

    /// <summary>
    /// Leet code #151. Reverse Words in a String
    /// Given an input string, reverse the string word by word. 
    /// For example,
    ///   Given s = "the sky is blue",
    ///   return "blue is sky the". 
    /// Update (2015-02-12):
    /// For C programmers: Try to solve it in-place in O(1) space. 
    /// </summary>
    string reverseWords(string s);

    /// <summary>
    /// Leet code #186. Reverse Words in a String II  
    /// 
    /// Given an input string, reverse the string word by word. A word 
    /// is defined as a sequence of non-space characters. 
    /// The input string does not contain leading or trailing spaces and 
    /// the words are always separated by a single space.  
    /// For example,
    /// Given s = "the sky is blue",
    /// return "blue is sky the".
    /// Could you do it in-place without allocating extra space? 
    /// </summary>
    void reverseWordsII(string &s);

    /// <summary>
    /// Leet code #344. Reverse String 
    ///
    /// Write a function that takes a string as input and returns the string 
    /// reversed.
    /// Example:
    ///  Given s = "hello", return "olleh".	
    /// </summary>
    string reverseString(string s);

    /// <summary>
    /// Leet code #14. Longest Common Prefix 
    ///
    /// Write a function to find the longest common prefix string amongst 
    /// an array of strings. 
    /// </summary>
    string longestCommonPrefix(vector<string>& strs);

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
    vector<string> fullJustify(vector<string>& words, int maxWidth);

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
    string minWindow(string s, string t);

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
    int lengthOfLongestSubstring(string s);

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
    bool isAnagram(string s, string t);

    /// <summary>
    /// Leet code #383. Ransom Note
    ///
    /// Given an arbitrary ransom note string and another string containing 
    /// letters from all the magazines, write a function that will return 
    /// true if the ransom note can be constructed from the magazines; 
    /// otherwise, it will return false. 
    ///
    /// Each letter in the magazine string can only be used once in your 
    /// ransom note. 
    /// Note:
    /// You may assume that both strings contain only lowercase letters. 
    /// canConstruct("a", "b") -> false
    /// canConstruct("aa", "ab") -> false
    /// canConstruct("aa", "aab") -> true
    /// </summary>
    bool canConstruct(string ransomNote, string magazine);

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
    int firstUniqChar(string s);

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
    string originalDigits(string s);

    /// <summary>
    /// Leet code #434. Number of Segments in a String
    ///
    /// Count the number of segments in a string, where a segment is defined 
    /// to be a contiguous sequence of non-space characters.
    /// Please note that the string does not contain any non-printable 
    /// characters.
    /// Example:
    /// Input: "Hello, my name is John"
    /// Output: 5
    /// </summary>
    int countSegments(string s);

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
    vector<int> findAnagrams(string s, string p);

    /// <summary>
    /// Check if this is a valid IPv4 address
    /// </summary>
    bool checkIPv4Address(vector<string> addressList);

    /// <summary>
    /// Check if this is a valid IPv6 address
    /// </summary>
    bool checkIPv6Address(vector<string> addressList);

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
    string validIPAddress(string IP);

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
    bool detectCapitalUse(string word);

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
    vector<vector<string>> groupAnagrams(vector<string>& strs);

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
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles);

    /// <summary>
    /// Leet code #224. Basic Calculator    
    /// Implement a basic calculator to evaluate a simple expression string.
    /// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
    /// You may assume that the given expression is always valid. 
    /// Some examples:
    /// "1 + 1" = 2
    /// " 2-1 + 2 " = 3
    /// "(1+(4+5+2)-3)+(6+8)" = 23	
    /// </summary>
    int calculate(string s);

    /// <summary>
    /// Leet code #227. Basic Calculator II 
    /// </summary>   
    inline int calculateII(int a, int b, char op);

    /// <summary>
    /// Leet code #227. Basic Calculator II 
    /// Implement a basic calculator to evaluate a simple expression string. 
    /// The expression string contains only non-negative integers, +, -, *, / 
    /// operators and empty spaces . The integer division should truncate 
    /// toward zero.
    /// You may assume that the given expression is always valid.
    /// Some examples:
    /// "3+2*2" = 7
    /// " 3/2 " = 1
    /// " 3+5 / 2 " = 5
    /// Note: Do not use the eval built-in library function. 
    /// </summary>   
    int calculateII(string s);

    /// <summary>
    /// Leet code #772. Basic Calculator III   
    /// </summary>
    string parseExpressionToken(string s, int& index);

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
    int calculateIII(string s);

    /// <summary>
    /// Leet code #772. Basic Calculator III   
    /// </summary>
    int parseTerm(vector<string>& tokens, int& index);

    /// <summary>
    /// Leet code #772. Basic Calculator III   
    /// </summary>
    int parseFactor(vector<string>& tokens, int& index);

    /// <summary>
    /// Leet code #772. Basic Calculator III   
    /// </summary>
    int parseExpression(vector<string>& tokens, int& index);

    /// <summary>
    /// Leet code #770. Basic Calculator IV   
    /// </summary>
    vector<string> polyToString(map<vector<string>, int> &ploy_map);

    /// <summary>
    /// Leet code #770. Basic Calculator IV   
    /// </summary>
    void calculatePolyExpression(
        stack<map<vector<string>, int>>& operands,
        stack<string>& operators);

    /// <summary>
    /// Leet code #770. Basic Calculator IV   
    /// </summary>
    map<vector<string>, int> parsePolyExpression(string& s, int& index,
        unordered_map<string, int>& eval_map);

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
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars,
        vector<int>& evalints);

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
    int lengthLongestPath(string input);

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
    int characterReplacement(string s, int k);

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
    int longestSubstring(string s, int k);

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
    int countCharacters(vector<string>& words, string chars);

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
    string removeVowels(string S);

    /// <summary>
    /// Leet code #1106. Parsing A Boolean Expression
    /// </summary>
    bool parseBoolExprAnd(string expression, int &pos);

    /// <summary>
    /// Leet code #1106. Parsing A Boolean Expression
    /// </summary>
    bool parseBoolExprOr(string expression, int &pos);

    /// <summary>
    /// Leet code #1106. Parsing A Boolean Expression
    /// </summary>
    bool parseBoolExprNot(string expression, int &pos);

    /// <summary>
    /// Leet code #1106. Parsing A Boolean Expression
    /// </summary>
    bool parseBoolExpr(string expression, int &pos);

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
    bool parseBoolExpr(string expression);

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
    string defangIPaddr(string address);

    /// <summary>
    /// Leet code #1096. Brace Expansion II
    /// </summary>
    void braceExpansionIIProduct(string &expression, size_t& pos, unordered_set<string> &result);

    /// <summary>
    /// Leet code #1096. Brace Expansion II
    /// </summary>
    void braceExpansionIIUnion(string &expression, size_t& pos, unordered_set<string> &result);

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
    /// R({e_1,e_2,...}) = R(e_1) ¡È R(e_2) ¡È ...
    /// For expressions e_1 and e_2, we have R(e_1 + e_2) = {a + b for (a, b) 
    /// in R(e_1) ¡Á R(e_2)}, where + denotes concatenation, and ¡Á denotes the 
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
    vector<string> braceExpansionII(string expression);

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
    vector<int> maxDepthAfterSplit(string seq);

    /// <summary>
    /// Leet code #1071. Greatest Common Divisor of Strings
    /// </summary>
    string getRepeatedOfStrings(string str);

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
    string gcdOfStrings(string str1, string str2);

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
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries);

    /// <summary>
    /// Leet code #972. Equal Rational Numbers
    /// </summary>
    string parseRationalInteger(string S, size_t &index);

    /// <summary>
    /// Leet code #972. Equal Rational Numbers
    /// </summary>
    string parseRationalDecimal(string S, size_t &index);

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
    bool isRationalEqual(string S, string T);

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
    vector<vector<int>> indexPairs(string text, vector<string>& words);

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
    vector<string> findOcurrences(string text, string first, string second);

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
    int shortestWay(string source, string target);

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
    string longestDupSubstring(string S);

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
    vector<string> printVertically(string s);

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
    string breakPalindrome(string palindrome); 

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
    int removePalindromeSub(string s);

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
    int minSteps(string s, string t);

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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries);

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
    int numberOfSubstrings(string s);

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
    string sortString(string s);

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
    int findTheLongestSubstring(string s);

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
    string generateTheString(int n);

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
    string longestPrefix(string s);

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
    bool canConstruct(string s, int k);

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
    int numSteps(string s);

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
    vector<string> stringMatching(vector<string>& words);

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
    string entityParser(string text);

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
    string reformat(string s);

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
    int maxScore(string s);

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
    bool checkIfCanBreak(string s1, string s2);

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
    string stringShift(string s, vector<vector<int>>& shift);

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
    string arrangeWords(string text);

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
    int isPrefixOfWord(string sentence, string searchWord);

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
    int maxVowels(string s, int k);

    /// <summary>
    /// Leet code #471. Encode String with Shortest Length
    /// </summary>
    void findRepeatPattern(string s, size_t start, size_t length, vector<vector<string>>& result);

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
    string encode(string s);

    /// <summary>
    /// Leet code # 466. Count The Repetitions 
    ///
    /// Define S = [s,n] as the string S which consists of n 
    /// connected strings s. For example, ["abc", 3] ="abcabcabc". 
    /// On the other hand, we define that string s1 can be obtained from string s2 
    /// if we can remove some characters from s2 such that it becomes s1. For 
    /// example, "abc" can be obtained from ¡°abdbec¡± based on our definition, but 
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
    int getMaxRepetitions(string s1, int n1, string s2, int n2);

    /// <summary>
    /// Leet code #418. Sentence Screen Fitting
    /// 
    /// Given a rows x cols screen and a sentence represented by a list of 
    /// non-empty words, find how many times the given sentence can be fitted 
    /// on the screen. 
    /// 
    /// Note:
    /// 1.A word cannot be split into two lines. 
    /// 2.The order of words in the sentence must remain unchanged.
    /// 3.Two consecutive words in a line must be separated by a single space.
    /// 4.Total words in the sentence won't exceed 100.
    /// 5.Length of each word is greater than 0 and won't exceed 10.
    /// 6.1 <= rows, cols <= 20,000.
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
    int wordsTyping(vector<string>& sentence, int rows, int cols);

    /// <summary>
    /// Leet code #816. Ambiguous Coordinates
    /// </summary>
    vector<string> getAllDecimals(string S);

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
    vector<string> ambiguousCoordinates(string S);

    /// <summary>
    /// Leet code #936. Stamping The Sequence
    /// </summary>
    vector<int> searchStamp(string& stamp, string& target, int& reduce);

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
    vector<int> movesToStamp(string stamp, string target);

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
    bool checkValidString(string s);

    /// <summary>
    /// Leet code #420. Strong Password Checker     
    /// A password is considered strong if below conditions are all met:
    /// 1. It has at least 6 characters and at most 20 characters. 
    /// 2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit. 
    /// 3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met). 
    /// Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.
    /// Insertion, deletion or replace of any one character are all considered as one change.
    /// </summary>
    int strongPasswordChecker(string s);

    /// <summary>
    /// Is Additive Number recursive call
    /// </summary>
    bool isAdditiveNumber(string num1, string num2, string num);

    /// <summary>
    /// Leet code #306. Additive Number
    ///
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
    bool isAdditiveNumber(string num);

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
    bool canPermutePalindrome(string s);

    /// <summary>
    /// Leet code #246. Strobogrammatic Number  
    /// 
    /// A strobogrammatic number is a number that looks the same when 
    /// rotated 180 degrees (looked at upside down).
    /// Write a function to determine if a number is strobogrammatic. The 
    /// number is represented as a string.
    /// For example, the numbers "69", "88", and "818" are all strobogrammatic.
    /// </summary>
    bool isStrobogrammatic(string num);

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
    vector<vector<string>> groupStrings(vector<string>& strings);

    /// <summary>
    /// Leet code #408. Valid Word Abbreviation    
    /// 
    /// Given a non-empty string s and an abbreviation abbr, return 
    /// whether the string matches with the given abbreviation. 
    /// A string such as "word" contains only the following valid abbreviations:
    /// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", 
    /// "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
    /// Notice that only the above abbreviations are valid abbreviations of 
    /// the string "word". 
    /// Any other string is not a valid abbreviation of "word".
    /// Note:
    /// Assume s contains only lowercase letters and abbr contains only 
    /// lowercase letters and digits. 
    /// Example 1:
    /// Given s = "internationalization", abbr = "i12iz4n":
    /// Return true.
    /// Example 2:
    /// Given s = "apple", abbr = "a2e":
    /// Return false.
    /// </summary>
    bool validWordAbbreviation(string word, string abbr);

    /// <summary>
    /// Leet code #481. Magical String
    /// 
    /// A magical string S consists of only '1' and '2' and obeys the following rules:  
    /// The string S is magical because concatenating the number of contiguous occurrences of 
    /// characters '1' and '2' generates the string S itself.  
    /// The first few elements of string S is the following: S = "1221121221221121122¡­¡­" 
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
    int magicalString(int n);

    /// <summary>
    /// Leet code #157. Read N Characters Given Read4  
    /// </summary>
    int read4(char* buff, string& s, int& index);

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
    int readNChars(char* buf, int n, string& s);

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
    int readNCharsII(char* buf, int n, string& s, int& index, string& m_buffer);

    /// <summary>
    /// Leet code #159. Longest Substring with At Most Two Distinct Characters
    /// 
    /// Given a string, find the length of the longest substring T that contains at most 
    /// 2 distinct characters. 
    /// For example, Given s = "eceba", 
    /// T is "ece" which its length is 3.
    /// </summary>
    int lengthOfLongestSubstringTwoDistinct(string s);

    /// <summary>
    /// Leet code #340. Longest Substring with At Most K Distinct Characters
    /// 
    /// Given a string, find the length of the longest substring T that 
    /// contains at most k distinct characters. 
    /// For example, Given s = "eceba" and k = 2,  
    /// T is "ece" which its length is 3. 
    /// </summary>
    int lengthOfLongestSubstringKDistinct(string s, int k);

    /// <summary>
    /// Leet code #467. Unique Substrings in Wraparound String
    /// 
    /// Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz",
    /// so s will look like this: 
    /// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
    /// Now we have another string p. Your job is to find out how many unique 
    /// non-empty substrings of p are present in s. In particular, your input is the string 
    /// p and you need to output the number of different non-empty substrings of p in the string s.
    /// Note: p consists of only lowercase English letters and the size of p might be over 10000.
    ///
    /// Example 1:
    /// Input: "a"
    /// Output: 1
    /// Explanation: Only the substring "a" of string "a" is in the string.
    ///
    /// Example 2:
    /// Input: "cac"
    /// Output: 2
    /// Explanation: There are two substrings "a", "c" of string "cac" in the string s.
    ///
    /// Example 3:
    /// Input: "zab"
    /// Output: 6
    /// Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
    /// </summary>
    int findSubstringInWraproundString(string p);

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
    string findLongestWord(string s, vector<string>& d);

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
    string reverseStr(string s, int k);

    /// <summary>
    /// Leet code #527. Word Abbreviation
    /// </summary>
    string makeAbbreviation(string& word, int k);

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
    vector<string> wordsAbbreviation(vector<string>& dict);

    /// <summary>
    /// Leet code #392. Is Subsequence 
    /// Given a string s and a string t, check if s is subsequence of t. 
    /// You may assume that there is only lower case English letters in both s and t. 
    /// t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100). 
    ///
    /// A subsequence of a string is a new string which is formed from the original string by 
    /// deleting some (can be none) of the characters without disturbing the relative positions 
    /// of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not). 
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
    /// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to 
    /// check one by one to see if T has its subsequence. In this scenario, how would you 
    /// change your code?
    /// </summary>
    bool isSubsequence(string s, string t);

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
    int findLUSlength(string a, string b);

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
    int findLUSlength(vector<string>& strs);

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
    string reverseWordsIII(string s);

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
    bool checkRecord(string s);

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
    bool checkInclusion(string s1, string s2);

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
    vector<vector<string>> findDuplicate(vector<string>& paths);

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
    string addBoldTag(string s, vector<string>& dict);

    /// <summary>
    /// Leet code #591. Tag Validator
    /// </summary>
    string getTag(string code, size_t& pos);

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
    bool isValid(string code);

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
    string solveEquation(string equation);

    /// <summary>
    /// Leet code #648. Replace Words
    /// </summary>
    string replaceWord(unordered_map<int, unordered_set<string>>& dict_map, const string& word);

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
    string replaceWords(vector<string>& dict, string sentence);

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
    string longestWord(vector<string>& words);

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
    vector<string> removeComments(vector<string>& source);

    /// <summary>
    /// Leet code #726. Number of Atoms
    /// </summary>
    string parseAtom(string& formula, int& index);

    /// <summary>
    /// Leet code #726. Number of Atoms
    /// </summary>
    int parseAtomCount(string& formula, int& index);

    /// <summary>
    /// Leet code #726. Number of Atoms
    /// </summary>
    void multiplyFormula(map<string, int>& formula, int& count);

    /// <summary>
    /// Leet code #726. Number of Atoms
    /// </summary>
    void mergeFormula(map<string, int>& atom_count, vector<map<string, int>>& formula_array);

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
    string countOfAtoms(string formula);

    /// <summary>
/// Leet code #736. Parse Lisp Expression
/// </summary>
    string parseLispToken(string& expression, int& index);

    /// <summary>
    /// Leet code #736. Parse Lisp Expression
    /// </summary>
    int calculateLispCommand(string& command, vector<string>& parameters, unordered_map<string, int>& variables);

    /// <summary>
    /// Leet code #736. Parse Lisp Expression
    /// </summary>
    int processLispCommand(string& expression, int& index, unordered_map<string, int> variables);

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
    int evaluate(string expression);

    /// <summary>
    /// Leet code #736. Parse Lisp Expression
    /// </summary>
    int processLispExpression(vector<string>& tokens, int& index, unordered_map<string, int> variables);

    /// <summary>
    /// Leet code #736. Parse Lisp Expression
    /// </summary>
    int processLispCommand(vector<string>& tokens, int& index, unordered_map<string, int> variables);

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
    int evaluate_V2(string expression);

    /// <summary>
    /// Leet code #751. Convert IPV4 to Ineteger
    /// </summary>
    unsigned int convertIpV4ToInt(string ipV4);

    /// <summary>
    /// Leet code #751. Integer to IPv4
    /// </summary>
    string convertIntToIpV4(unsigned int ipV4);

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
    vector<string> ipToCIDR(string ip, int range);

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
    string makeLargestSpecial(string S);

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
    string boldWords(vector<string>& words, string S);

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
    int numJewelsInStones(string J, string S);

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
    vector<int> partitionLabels(string S);

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
    string reorganizeString(string S);

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
    bool canTransform(string start, string end);

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
    string customSortString(string S, string T);

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
    int uniqueMorseRepresentations(vector<string>& words);

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
    vector<int> numberOfLines(vector<int>& widths, string S);

    /// <summary>
    /// Leet code #809. Expressive Words
    /// </summary>
    void expressiveWords(string str, vector<pair<char, int>>& str_code);

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
    int expressiveWords(string S, vector<string>& words);

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
    string mostCommonWord(string paragraph, vector<string>& banned);

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
    int minimumLengthEncoding(vector<string>& words);

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
    string toGoatLatin(string S);

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
    /// We define a name to be a string of length ¡Ý 2 consisting of only 
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
    string maskPII(string S);

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
    string findReplaceString(string S, vector<int>& indexes,
        vector<string>& sources, vector<string>& targets);

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
    vector<int> splitIntoFibonacci(string S);

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
    bool backspaceCompare(string S, string T);

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
    string shiftingLetters(string S, vector<int>& shifts);

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
    bool buddyStrings(string A, string B);

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
    int numSpecialEquivGroups(vector<string>& A);

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
    int countkDist(string str, int k);

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
    string orderlyQueue(string S, int K);

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
    bool isLongPressedName(string name, string typed);

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
    int numUniqueEmails(vector<string>& emails);

    /// <summary>
    /// Leet code #9904. CSV Parser
    /// </summary>
    string parsePhrase(string& line, int& pos);

    /// <summary>
    /// Leet code #9904. CSV Parser
    /// </summary>
    vector<string> parseLine(string& line);

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
    vector<vector<string>>  parseCSV(vector<string>& lines);

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
    vector<string> reorderLogFiles(vector<string>& logs);

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
    vector<string> commonChars(vector<string>& A);

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
    string removeOuterParentheses(string S);

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
    vector<bool> camelMatch(vector<string>& queries, string pattern);

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
    string lastSubstring(string s);

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
    string reformatDate(string date);

    /// <summary>
    /// Leet code #1531. String Compression II
    /// </summary>
    int getLengthOfOptimalCompression(string& s, int left, int k, vector<vector<int>>& dp);

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
    int getLengthOfOptimalCompression(string s, int k);

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
    string restoreString(string s, vector<int>& indices);

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
    int numSplits(string s);

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
    bool canConvertString(string s, string t, int k);

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
    int minInsertions(string s);

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
    int longestAwesome(string s);

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
    string makeGood(string s);

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
    bool differByOne(vector<string>& dict);

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
    string thousandSeparator(int n);

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
    int numWays(string s);

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
    string modifyString(string s);

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
    int minCost(string s, vector<int>& cost);

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
    string reorderSpaces(string text);

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
    int minOperations(vector<string>& logs);

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
    int maxDepth(string s);

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
    bool checkPalindromeFormation(string a, string b);

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
    int maxFont(string text, int w, int h, vector<int>& fonts);

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
    int maxLengthBetweenEqualCharacters(string s);

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
    string findLexSmallestString(string s, int a, int b);

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
    int countSubstrings(string s, string t);

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
    int minDeletions(string s);

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
    bool closeStrings(string word1, string word2);

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
    int maxRepeating(string sequence, string word);

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
    /// </summary>
    string interpret(string command);

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
    int countConsistentStrings(string allowed, vector<string>& words);
#pragma endregion
};

#endif  // LeetCodeString_H
