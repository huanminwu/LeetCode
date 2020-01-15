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

#pragma endregion
};

/// <summary>
/// Leet code #288. Unique Word Abbreviation    
/// 
/// An abbreviation of a word follows the form <first letter><number><last letter>. 
/// Below are some examples of word abbreviations: 
/// a) it                      --> it    (no abbreviation)
///      1
/// b) d|o|g                   --> d1g
///              1    1  1
///      1---5----0----5--8
/// c) i|nternationalizatio|n  --> i18n
///              1
///      1---5----0
/// d) l|ocalizatio|n          --> l10n
///
/// Assume you have a dictionary and given a word, find whether its 
/// abbreviation is unique in the dictionary. A word's abbreviation is unique 
/// if no other word from the dictionary has the same abbreviation.
/// Example: 
/// Given dictionary = [ "deer", "door", "cake", "card" ]
/// isUnique("dear") -> false
/// isUnique("cart") -> true
/// isUnique("cane") -> false
/// isUnique("make") -> true
/// </summary>
class ValidWordAbbr
{
private:
    unordered_map<string, unordered_set<string>> m_AbbrMap;
public:
    ValidWordAbbr(vector<string> &dictionary)
    {
        for (string word : dictionary)
        {
            string abbr;
            if (word.size() > 0) abbr.push_back(word[0]);
            if (word.size() > 1) abbr.push_back(word[word.size() - 1]);
            if (word.size() > 2) abbr.insert(1, to_string(word.size() - 2));
            m_AbbrMap[abbr].insert(word);
        }
    }
    bool isUnique(string word)
    {
        string abbr;
        if (word.size() > 0) abbr.push_back(word[0]);
        if (word.size() > 1) abbr.push_back(word[word.size() - 1]);
        if (word.size() > 2) abbr.insert(1, to_string(word.size() - 2));

        if ((m_AbbrMap.find(abbr) == m_AbbrMap.end()) ||
            ((m_AbbrMap[abbr].size()) == 1 && (m_AbbrMap[abbr].count(word) == 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif  // LeetCodeString_H
