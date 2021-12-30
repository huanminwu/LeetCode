#pragma once
#ifndef LeetcodeBackTracking_H
#define LeetcodeBackTracking_H
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
using namespace std;
/// <summary>
/// The class is to implement two pointers  
/// </summary>
class LeetcodeBackTracking
{
public:
    /// <summary>
    /// Leet code #282. Expression Add Operators
    /// </summary>
    void calculate(vector<string>& result, string path, string num,
        long long target, long long eval, long long product);

    /// <summary>
    /// Leet code #282. Expression Add Operators
    ///
    /// Given a string that contains only digits 0-9 and a target value, 
    /// return all possibilities to add binary operators 
    /// (not unary) +, -, or * between the digits so they evaluate to 
    /// the target value. 
    /// 
    /// Examples:  
    /// "123", 6 -> ["1+2+3", "1*2*3"] 
    /// "232", 8 -> ["2*3+2", "2+3*2"]
    /// "105", 5 -> ["1*0+5","10-5"]
    /// "00", 0 -> ["0+0", "0-0", "0*0"]
    /// "3456237490", 9191 -> []
    /// </summary>
    vector<string> addOperators(string num, int target);

    /// <summary>
    /// Leet code #301. Remove Invalid Parentheses 
    /// </summary>
    void removeInvalidParentheses(string s, vector<char> p, int first, int last, vector<string>& result);

    /// <summary>
    /// Leet code #301. Remove Invalid Parentheses 
    /// 
    /// Remove the minimum number of invalid parentheses in order to make 
    /// the input string valid. Return all possible results.
    /// Note: The input string may contain letters other than the parentheses ( and ). 
    /// Examples:
    /// "()())()" -> ["()()()", "(())()"]
    /// "(a)())()" -> ["(a)()()", "(a())()"]
    /// ")(" -> [""]
    /// </summary>
    vector<string> removeInvalidParentheses(string s);

    /// <summary>
    /// Leet code #254. Factor Combinations    
    /// </summary>
    void getFactors(int n, vector<int> factors, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #254. Factor Combinations    
    /// 
    /// Numbers can be regarded as product of its factors. For example, 
    /// 8 = 2 x 2 x 2; = 2 x 4.
    /// Write a function that takes an integer n and return all possible combinations of its factors. 
    /// Note: 
    /// 1.You may assume that n is always positive. 
    /// 2.Factors should be greater than 1 and less than n.
    /// </summary>
    vector<vector<int>> getFactors(int n);

    /// <summary>
    /// Leet code #320. Generalized Abbreviation  
    /// </summary>
    vector<string> generateAbbreviations(string word, unordered_map<string, vector<string>>& cache);

    /// <summary>
    /// Leet code #320. Generalized Abbreviation  
    /// 
    /// Write a function to generate the generalized abbreviations of a word.
    /// Example:
    /// Given word = "word", return the following list (order does not matter):
    /// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", 
    ///  "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
    /// </summary>
    vector<string> generateAbbreviations(string word);

    /// <summary>
    /// Leet code #320. Generalized Abbreviation  
    /// 
    /// Write a function to generate the generalized abbreviations of a word.
    /// Example:
    /// Given word = "word", return the following list (order does not matter):
    /// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", 
    ///  "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
    /// </summary>
    vector<string> generateAbbreviationsII(string word);

    /// <summary>
    /// Leet code #411. Minimum Unique Word Abbreviation  
    /// </summary>
    void getAbbrBits(int index, int digits, int target_digits, string& abbr_bits, vector<string>& result);

    /// <summary>
    /// Leet code #411. Minimum Unique Word Abbreviation  
    /// </summary>
    string getAbbrWord(string word, string abbr_bits, int& length);

    /// <summary>
    /// Leet code #411. Minimum Unique Word Abbreviation  
    /// 
    /// A string such as "word" contains the following abbreviations:
    /// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", 
    ///  "2r1", "3d", "w3", "4"]
    /// Given a target string and a set of strings in a dictionary, find an abbreviation of this 
    /// target string with the smallest possible length such that it does not conflict with 
    /// abbreviations of the strings in the dictionary. 
    ///
    /// Each number or letter in the abbreviation is considered length = 1. 
    /// For example, the abbreviation "a32bc" has length = 4.
    ///
    /// Note:
    /// In the case of multiple answers as shown in the second example below, you may return any one of them.
    /// Assume length of target string = m, and dictionary size = n. You may assume that m ¡Ü 21, n ¡Ü 1000, 
    /// and log2(n) + m ¡Ü 20.
    /// 
    /// Examples:
    ///
    /// "apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")
    ///
    /// "apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", 
    /// "2p2", "3le", "3l1").
    /// </summary>
    string minAbbreviation(string target, vector<string>& dictionary);

    /// <summary>
    /// Leet code #267. Palindrome Permutation II 
    /// </summary>
    void generatePalindromes(string s, string partial_result, unordered_set<int>& visited, vector<string>& result);

    /// <summary>
    /// Leet code #267. Palindrome Permutation II 
    /// 
    /// Given a string s, return all the palindromic permutations (without duplicates) of it. 
    /// Return an empty list if no palindromic permutation could be form. 
    /// For example: 
    /// 
    /// Given s = "aabb", return ["abba", "baab"]. 
    /// Given s = "abc", return []. 
    /// Hint:
    /// 1.If a palindromic permutation exists, we just need to generate the first half of the string.
    /// 2.To generate all distinct permutations of a (half of) string, use a similar approach from: 
    ///   Permutations II or Next Permutation.
    /// </summary>
    vector<string> generatePalindromes(string s);

    /// <summary>
    /// Leet code #294. Flip Game II  
    /// </summary>
    bool canWin(string s, unordered_map<string, bool>& cache);

    /// <summary>
    /// Leet code #294. Flip Game II  
    /// 
    /// You are playing the following Flip Game with your friend: Given a string that 
    /// contains only these two characters: + and -, you and your friend take turns to 
    /// flip two consecutive "++" into "--". The game ends when a person can no longer 
    /// make a move and therefore the other person will be the winner. 
    /// Write a function to determine if the starting player can guarantee a win. 
    /// For example, given s = "++++", return true. The starting player can guarantee 
    /// a win by flipping the middle "++" to become "+--+". 
    /// Follow up:
    /// Derive your algorithm's runtime complexity. 
    /// </summary>
    bool canWin(string s);

    /// <summary>
    /// Leet code #291. Word Pattern II    
    /// </summary>
    bool wordPatternMatch(string& pattern, string& str, int pattern_index, int str_index,
        map<char, string>& pat_map, map<string, char>& str_map);

    /// <summary>
    /// Leet code #291. Word Pattern II    
    /// 
    /// Given a pattern and a string str, find if str follows the same pattern. 
    /// Here follow means a full match, such that there is a bijection between a letter in pattern 
    /// and a non-empty substring in str. 
    /// Examples:
    /// 1.pattern = "abab", str = "redblueredblue" should return true.
    /// 2.pattern = "aaaa", str = "asdasdasdasd" should return true.
    /// 3.pattern = "aabb", str = "xyzabcxzyabc" should return false.
    /// 
    /// Notes:
    /// You may assume both pattern and str contains only lowercase letters. 
    /// </summary>
    bool wordPatternMatch(string pattern, string str);

    /// <summary>
    /// Leet code #488. Zuma Game
    /// </summary>
    void shrinkZuma(string& board);

    /// <summary>
    /// Leet code #488. Zuma Game
    /// </summary>
    int findMinStep(string board, unordered_map<char, int>& hand_map, unordered_map<string, int>& cache);

    /// <summary>
    /// Leet code #488. Zuma Game
    ///
    /// Think about Zuma Game. You have a row of balls on the table, colored red(R), 
    /// yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.
    /// Each time, you may choose a ball in your hand, and insert it into the row (including 
    /// the leftmost place and rightmost place). Then, if there is a group of 3 or more balls 
    /// in the same color touching, remove these balls. Keep doing this until no more 
    /// balls can be removed.
    ///
    /// Find the minimal balls you have to insert to remove all the balls on the table. If 
    /// you cannot remove all the balls, output -1. 
    /// Examples:
    ///  
    /// Input: "WRRBBW", "RB"
    /// Output: -1
    /// Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
    ///
    /// Input: "WWRRBBWW", "WRBRW"
    /// Output: 2
    /// Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty
    /// 
    /// Input:"G", "GGGGG"
    /// Output: 2
    /// Explanation: G -> G[G] -> GG[G] -> empty 
    ///
    /// Input: "RBYYBBRRB", "YRBGB"
    /// Output: 3
    /// Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 
    ///
    /// Note:
    /// 1.You may assume that the initial row of balls on the table won¡¯t have any 3 or more 
    ///   consecutive balls with the same color.
    /// 2.The number of balls on the table won't exceed 20, and the string represents these 
    ///   balls is called "board" in the input.
    /// 3.The number of balls in your hand won't exceed 5, and the string represents these balls 
    ///   is called "hand" in the input.
    /// 4.Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.
    /// </summary>
    int findMinStep(string board, string hand);

    /// <summary>
    /// Leet code #465. Optimal Account Balancing
    /// </summary>
    int minTransfers(vector<int>& debt, size_t index);

    /// <summary>
    /// Leet code #465. Optimal Account Balancing
    /// A group of friends went on holiday and sometimes lent each other money. 
    /// For example, Alice paid for Bill's lunch for $10. Then later Chris gave 
    /// Alice $5 for a taxi ride. We can model each transaction as a tuple 
    /// (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, 
    /// and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), 
    /// the transactions can be represented as [[0, 1, 10], [2, 0, 5]].
    ///
    /// Given a list of transactions between a group of people, return the minimum 
    /// number of transactions required to settle the debt.
    ///
    /// Note: 
    /// 1.A transaction will be given as a tuple (x, y, z). Note that x ¡Ù y and z > 0.
    /// 2.Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we 
    ///   could also have the persons 0, 2, 6.
    /// Example 1: 
    /// Input:
    /// [[0,1,10], [2,0,5]]
    ///
    /// Output:
    /// 2
    ///
    /// Explanation:
    /// Person #0 gave person #1 $10.
    /// Person #2 gave person #0 $5.
    ///
    /// Two transactions are needed. One way to settle the debt is person #1 
    /// pays person #0 and #2 $5 each.
    /// Example 2: 
    /// Input:
    /// [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
    /// Output:
    /// 1
    ///
    /// Explanation:
    /// Person #0 gave person #1 $10.
    /// Person #1 gave person #0 $1.
    /// Person #1 gave person #2 $5.
    /// Person #2 gave person #0 $5.
    ///
    /// Therefore, person #1 only need to give person #0 $4, and all debt is settled.
    /// </summary>
    int minTransfers(vector<vector<int>>& transactions);

    /// <summary>
    /// Leet code #472. Concatenated Words
    /// </summary>
    bool findAllConcatenatedWordsInADict(string word, int start, unordered_set<string>& dictionary);

    /// <summary>
    /// Leet code #472. Concatenated Words
    ///
    /// Given a list of words (without duplicates), please write a program that 
    /// returns all concatenated words in the given list of words. 
    ///
    /// A concatenated word is defined as a string that is comprised entirely of at 
    /// least two shorter words in the given array.
    /// Example:
    /// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
    /// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
    /// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
    /// "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
    /// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
    ///
    /// Note:
    /// 1.The number of elements of the given array will not exceed 10,000  
    /// 2.The length sum of elements in the given array will not exceed 600,000. 
    /// 3.All the input string will only include lower case letters.
    /// 4.The returned elements order does not matter. 
    /// </summary>
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words);

    /// <summary>
    /// Leet code #351. Android Unlock Patterns
    /// </summary>
    void nextPattern(vector<int>& keys, vector<int>& visited, int m, int n, int& count);

    /// <summary>
    /// Leet code #351. Android Unlock Patterns
    /// </summary>
    int nextPattern(int key, int m, int n);

    /// <summary>
    /// Leet code #351. Android Unlock Patterns
    ///
    /// Given an Android 3x3 key lock screen and two integers m and n, where 
    /// 1 ¡Ü m ¡Ü n ¡Ü 9, count the total number of unlock patterns of the Android 
    /// lock screen, which consist of minimum of m keys and maximum n keys.
    /// 
    /// Rules for a valid pattern:
    /// 1.Each pattern must connect at least m keys and at most n keys.
    /// 2.All the keys must be distinct.
    /// 3.If the line connecting two consecutive keys in the pattern passes 
    ///   through any other keys, the other keys must have previously selected 
    ///   in the pattern. No jumps through non selected key is allowed.
    /// 4.The order of keys used matters.
    ///
    /// Explanation:
    /// | 1 | 2 | 3 |
    /// | 4 | 5 | 6 |
    /// | 7 | 8 | 9 |
    ///
    /// Invalid move: 4 - 1 - 3 - 6 
    /// Line 1 - 3 passes through key 2 which had not been selected in the pattern.
    ///
    /// Invalid move: 4 - 1 - 9 - 2 
    /// Line 1 - 9 passes through key 5 which had not been selected in the pattern.
    ///
    /// Valid move: 2 - 4 - 1 - 3 - 6
    /// Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern
    ///
    /// Valid move: 6 - 5 - 4 - 1 - 9 - 2
    /// Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
    /// Example:
    /// Given m = 1, n = 1, return 9. 
    /// </summary>
    int numberOfPatterns(int m, int n);

    /// <summary>
    /// Leet code #9901. Get Maximum Expression 
    /// 
    /// Assume you are given a list of integer and you can add '+', '*' or '(' , ')'.  
    /// Please try to get the maximum result.
    /// </summary>
    pair<int, int> getMaxExprResult(vector<int>& nums, int start, int end,
        unordered_map<string, pair<int, int>>& cache);

    /// <summary>
    /// Leet code #9901. Get Maximum Expression 
    /// 
    /// Assume you are given a list of integer and you can add '+', '*' or '(' , ')'.  
    /// Please try to get the maximum result.
    /// </summary>
    int getMaxExprResult(vector<int> nums);

    /// <summary>
    /// Leet code #546. Remove Boxes 
    /// </summary>
    string toString(vector<int>& boxes);

    /// <summary>
    /// Leet code #546. Remove Boxes 
    /// </summary>
    int calculatePoints(vector<int>& boxes, int start, int end, int k, vector<vector<vector<int>>> scores);

    /// <summary>
    /// Leet code #546. Remove Boxes 
    /// 
    /// Given several boxes with different colors represented by different 
    /// positive numbers. 
    /// You may experience several rounds to remove boxes until there is no 
    /// box left. Each time you can choose some continuous boxes with the same 
    /// color (composed of k boxes, k >= 1), remove them and get k*k points.
    /// Find the maximum points you can get.
    ///
    /// Example 1:
    /// Input:
    /// [1, 3, 2, 2, 2, 3, 4, 3, 1]
    /// Output:
    /// 23
    /// Explanation:
    /// [1, 3, 2, 2, 2, 3, 4, 3, 1] 
    /// ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
    /// ----> [1, 3, 3, 3, 1] (1*1=1 points) 
    /// ----> [1, 1] (3*3=9 points) 
    /// ----> [] (2*2=4 points)
    /// Note: The number of boxes n would not exceed 100.
    /// </summary>
    int removeBoxes(vector<int>& boxes);

    /// <summary>
    /// Leet code #638. Shopping Offers
    /// </summary>
    int tryOffer(vector<vector<int>>& special, vector<int>& needs, int index);

    /// <summary>
    /// Leet code #638. Shopping Offers
    /// </summary>
    void shoppingOffers(vector<int>& price, vector<vector<int>>& special,
        vector<int>& needs, int index, int& total_price, int& min_price);

    /// <summary>
    /// Leet code #638. Shopping Offers
    /// 
    /// In LeetCode Store, there are some kinds of items to sell. Each item has a 
    /// price. 
    /// However, there are some special offers, and a special offer consists of one
    /// or more different kinds of items with a sale price. 
    /// You are given the each item's price, a set of special offers, and the 
    /// number we need to buy for each item. The job is to output the lowest price 
    /// you have to pay for exactly certain items as given, where you could make 
    /// optimal use of the special offers. 
    /// Each special offer is represented in the form of an array, the last number 
    /// represents the price you need to pay for this special offer, other numbers 
    /// represents how many specific items you could get if you buy this offer. 
    /// You could use any of special offers as many times as you want.
    ///
    /// Example 1:
    /// Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
    /// Output: 14
    /// Explanation: 
    /// There are two kinds of items, A and B. Their prices are $2 and $5 
    /// respectively. 
    /// In special offer 1, you can pay $5 for 3A and 0B
    /// In special offer 2, you can pay $10 for 1A and 2B. 
    /// You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer 
    /// #2), and $4 for 2A.
    ///
    /// Example 2:
    /// Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
    /// Output: 11
    /// Explanation: 
    /// The price of A is $2, and $3 for B, $4 for C. 
    /// You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
    /// You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special 
    /// offer #1), and $3 for 1B, $4 for 1C. 
    /// You cannot add more items, though only $9 for 2A ,2B and 1C.
    /// 
    /// Note:
    /// 1. There are at most 6 kinds of items, 100 special offers.
    /// 2. For each item, you need to buy at most 6 of them.
    /// 3. You are not allowed to buy more items than you want, even if that would 
    /// lower the overall price.
    /// </summary>
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs);

    /// <summary>
    /// Leet code #681. Next Closest Time
    /// </summary>
    bool isValidTime(string& time);

    /// <summary>
    /// Leet code #681. Next Closest Time
    /// </summary>
    bool NextTime(string& time, int index, set<char>& nums);

    /// <summary>
    /// Leet code #681. Next Closest Time
    /// 
    /// Given a time represented in the format "HH:MM", form the next closest 
    /// time by reusing the current digits. There is no limit on how many 
    /// times a digit can be reused.
    ///
    /// You may assume the given input string is always valid. For example, 
    /// "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
    ///
    /// Example 1:
    ///
    /// Input: "19:34"
    /// Output: "19:39"
    /// Explanation: The next closest time choosing from digits 1, 9, 3, 4, 
    /// is 19:39, which occurs 5 minutes later.  It is not 19:33, because 
    /// this occurs 23 hours and 59 minutes later.
    ///
    /// Example 2:
    ///
    /// Input: "23:59"
    /// Output: "22:22"
    /// Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 
    /// 22:22. It may be assumed that the returned time is next day's time 
    /// since it is smaller than the input time numerically.
    /// </summary>
    string nextClosestTime(string time);

    /// <summary>
    /// Leet code #698. Partition to K Equal Sum Subsets
    /// </summary>
    bool buildPartitionKSubsets(vector<int>& nums, int index, vector<vector<int>>& path,
        int partition_id, int partition_count, int sum, vector<int>& visited,
        unordered_map<string, int>& search_map);

    /// <summary>
    /// Leet code #698. Partition to K Equal Sum Subsets
    /// Given an array of integers nums and a positive integer k, find whether 
    /// it's possible to divide this array into k non-empty subsets whose sums 
    /// are all equal.
    ///
    /// Example 1:
    /// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
    /// Output: True
    /// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), 
    /// (2,3), (2,3) with equal sums.
    /// Note:
    ///
    /// 1 <= k <= len(nums) <= 16.
    /// 0 < nums[i] < 10000.
    /// </summary>
    bool canPartitionKSubsets(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #691. Stickers to Spell Word
    ///
    /// search target
    /// </summary>
    int searchTarget(vector<vector<int>>& sticker_chars, vector<bool>& sticker_visited, string& target,
        unordered_map<string, int>& cache);

    /// <summary>
    /// Leet code #691. Stickers to Spell Word
    ///
    /// check dominated stickers
    /// </summary>
    void checkDominatedStickers(vector<vector<int>>& sticker_chars, vector<bool>& sticker_visited);

    /// <summary>
    /// Leet code #691. Stickers to Spell Word
    ///
    /// Convert string to characters count
    /// </summary>
    void convertStringToCharCount(string& word, vector<int>& char_count, vector<int>& target_count);

    /// <summary>
    /// Leet code #691. Stickers to Spell Word
    ///
    /// reduce the target by sticker
    /// </summary>
    void reduceTarget(vector<int>& sticker_count, string& target);

    /// <summary>
    /// Leet code #691. Stickers to Spell Word
    ///
    /// We are given N different types of stickers. Each sticker has a 
    /// lowercase English word on it.
    ///
    /// You would like to spell out the given target string by cutting 
    /// individual letters from your collection of stickers and rearranging 
    /// them.
    ///
    /// You can use each sticker more than once if you want, and you have 
    /// infinite quantities of each sticker.
    ///  
    /// What is the minimum number of stickers that you need to spell out the 
    /// target? If the task is impossible, return -1.
    /// 
    /// Example 1:
    ///
    /// Input:
    ///
    /// ["with", "example", "science"], "thehat"
    /// Output:
    ///
    /// 3
    /// Explanation:
    ///
    /// We can use 2 "with" stickers, and 1 "example" sticker.
    /// After cutting and rearrange the letters of those stickers, we can form 
    /// the target "thehat".
    /// Also, this is the minimum number of stickers necessary to form the 
    /// target string.
    ///
    /// Example 2:
    ///
    /// Input:
    ///
    /// ["notice", "possible"], "basicbasic"
    /// Output:
    ///
    /// -1
    /// Explanation:
    ///
    /// We can't form the target "basicbasic" from cutting letters from the 
    /// given stickers.
    /// Note:
    ///
    /// stickers has length in the range [1, 50].
    /// stickers consists of lowercase English words (without apostrophes).
    /// target has length in the range [1, 15], and consists of lowercase 
    /// English letters.
    /// In all test cases, all words were chosen randomly from the 1000 most 
    /// common US English words, and the target was chosen as a concatenation 
    /// of two random words.
    /// The time limit may be more challenging than usual. It is expected 
    /// that a 50 sticker test case can be solved within 35ms on average.
    /// </summary>
    int minStickers(vector<string>& stickers, string target);

    /// <summary>
    /// Leet code #753. Cracking the Safe
    /// </summary>
    void crackSafe(string& result, unordered_set<string>& password_set, int n, int k);

    /// <summary>
    /// Leet code #753. Cracking the Safe
    ///
    /// There is a box protected by a password. The password is n digits, 
    /// where each letter can be one of the first k digits 0, 1, ..., k-1.
    ///
    /// You can keep inputting the password, the password will automatically 
    /// be matched against the last n digits entered.
    ///
    /// For example, assuming the password is "345", I can open it when I type 
    /// "012345", but I enter a total of 6 digits.
    ///
    /// Please return any string of minimum length that is guaranteed to open 
    /// the box after the entire string is inputted.
    ///
    /// Example 1:
    /// Input: n = 1, k = 2
    /// Output: "01"
    /// Note: "10" will be accepted too.
    /// Example 2:
    /// Input: n = 2, k = 2
    /// Output: "00110"
    /// Note: "01100", "10011", "11001" will be accepted too.
    /// Note:
    /// 1. n will be in the range [1, 4].
    /// 2. k will be in the range [1, 10].
    /// 3. k^n will be at most 4096.
    /// </summary>
    string crackSafe(int n, int k);

    /// <summary>
    /// Leet code #756. Pyramid Transition Matrix
    /// </summary>
    void nextPyramidTop(string& bottom, string& top, unordered_map<char, unordered_map<char, set<char>>>& allowed_map);

    /// <summary>
    /// Leet code #756. Pyramid Transition Matrix
    /// </summary>
    bool buildPyramidTransition(string& bottom, unordered_map<char, unordered_map<char, set<char>>>& allowed_map);

    /// <summary>
    /// Leet code #756. Pyramid Transition Matrix
    ///
    /// We are stacking blocks to form a pyramid. Each block has a color which 
    /// is a one letter string, like 'Z'.
    ///
    /// For every block of color 'C' we place not in the bottom row, we are 
    /// placing it on top of a left block of color 'A' and right block of 
    /// color 'B'. We are allowed to place the block there only if '(A, B, C)' 
    /// is an allowed triple.
    ///
    /// We start with a bottom row of bottom, represented as a single string. 
    /// We also start with a list of allowed triples allowed. Each allowed 
    /// triple is represented as a string of length 3.
    ///
    /// Return true if we can build the pyramid all the way to the top, 
    /// otherwise false.
    ///
    /// Example 1:
    /// Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
    /// Output: true
    /// Explanation:
    /// We can stack the pyramid like this:
    ///      A
    ///     / \
    ///    D   E
    ///   / \ / \
    ///  X   Y   Z
    ///
    /// This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and 
    /// ('D', 'E', 'A') are allowed triples.
    /// Example 1:
    /// Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
    /// Output: false
    /// Explanation:
    /// We can't stack the pyramid to the top.
    /// Note that there could be allowed triples (A, B, C) and (A, B, D) 
    /// with C != D.
    /// Note:
    /// 1. bottom will be a string with length in range [2, 100]. 
    /// 2. allowed will have length in range [0, 350].
    /// 3. Letters in all strings will be chosen from the set 
    ///    {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
    /// </summary>
    bool pyramidTransition(string bottom, vector<string>& allowed);
};
#endif  // LeetCodeTwoPointer
