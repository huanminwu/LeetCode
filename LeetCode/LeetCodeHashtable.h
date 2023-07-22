#pragma once
#ifndef LeetcodeHashtable_H
#define LeetCodeHashtable_H
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
/// The class is to implement dynamic programming  
/// </summary>
class LeetCodeHashtable
{
public:
    /// <summary>
    /// Leet code #1 Two Sum
    /// Given an array of integers, return indices of the two numbers such that they add up to 
    /// a specific target.
    /// You may assume that each input would have exactly one solution.
    /// Example:
    /// Given nums = [2, 7, 11, 15], target = 9,
    /// Because nums[0] + nums[1] = 2 + 7 = 9,
    /// return[0, 1]
    /// </summary>
    vector<int> twoSum(vector<int>& nums, int target);

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
    vector<vector<int>> threeSum(vector<int>& nums);

    /// <summary>
    /// LeetCode #15. 3Sum
    /// </summary>
    vector<vector<int>> threeSumII(vector<int>& nums);

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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);

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
    vector<vector<int>> fourSum(vector<int>& nums, int target);
 
    /// <summary>
    /// Leet code #18. 4Sum 
    /// </summary>
    vector<vector<int>> fourSumII(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #128. Longest Consecutive Sequence 
    /// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
    /// For example,
    ///   Given [100, 4, 200, 1, 3, 2],
    ///   The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. 
    /// Your algorithm should run in O(n) complexity. 
    /// </summary>
    int longestConsecutive(vector<int>& nums);

    /// <summary>
    /// Leet code #166. Fraction to Recurring Decimal
    /// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
    /// If the fractional part is repeating, enclose the repeating part in parentheses.
    /// For example,
    /// Given numerator = 1, denominator = 2, return "0.5".	
    /// Given numerator = 2, denominator = 1, return "2".
    /// Given numerator = 2, denominator = 3, return "0.(6)"
    /// Hint:
    /// 1.No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
    /// 2.Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
    /// 3.Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
    /// </summary>
    string fractionToDecimal(int numerator, int denominator);

    /// <summary>
    /// Leet code #202. Happy Number   
    /// Write an algorithm to determine if a number is "happy".
    /// A happy number is a number defined by the following process: Starting 
    /// with any positive integer,
    /// replace the number by the sum of the squares of its digits, and repeat 
    /// the process until the number
    /// equals 1 (where it will stay), or it loops endlessly in a cycle which 
    /// does not include 1. 
    /// Those numbers for which this process ends in 1 are happy numbers.
    /// Example: 19 is a happy number
    /// 1^2 + 9^2 = 82
    /// 8^2 + 2^2 = 68
    /// 6^2 + 8^2 = 100
    /// 1^2 + 0^2 + 0^2 = 1
    /// </summary>
    bool isHappy(int n);

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
    /// Leet code #217. Contains Duplicate
    /// Given an array of integers, find if the array contains any duplicates. Your function should return true 
    /// if any value appears at least twice in the array, and it should return false if every element is distinct.	
    /// </summary>
    bool containsDuplicate(vector<int>& nums);

    /// <summary>
    /// Leet code #299. Bulls and Cows
    ///
    /// You are playing the following Bulls and Cows game with your friend: 
    /// You write down a number and ask your friend to guess what the number 
    ///is. Each time your friend makes a guess, you provide a hint that indicates 
    /// how many digits in said guess match your secret number exactly in both 
    /// digit and position (called "bulls") 
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
    string getHint(string secret, string guess);

    /// <summary>
    /// Leet code #349. Intersection of Two Arrays      
    /// Example:
    /// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2]. 
    /// Note:
    /// Each element in the result must be unique.
    /// The result can be in any order.	
    /// </summary>
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2);

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
    vector<int> intersectionArrayII(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet code #219. Contains Duplicate II
    /// Given an array of integers and an integer k, find out whether there are two distinct 
    /// indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.	
    /// </summary>
    bool containsNearbyDuplicate(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #347. Top K Frequent Elements
    /// Given a non-empty array of integers, return the k most frequent elements.
    /// For example,
    /// Given [1,1,1,2,2,3] and k = 2, return [1,2]. 
    /// Note: 
    /// You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
    /// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    /// </summary>
    vector<int> topKFrequent(vector<int>& nums, int k);

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
    string frequencySort(string s);

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
    vector<string> findWordsInOneRow(vector<string>& words);

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
    /// For the left two athletes, you just need to output their relative ranks 
    /// according to their scores.
    ///
    /// Note:
    /// 1.N is a positive integer and won't exceed 10,000.
    /// 2.All the scores of athletes are guaranteed to be unique.
    /// </summary>
    vector<string> findRelativeRanks(vector<int>& nums);

    /// <summary>
    /// Leet code #532. K-diff Pairs in an Array
    /// 
    /// Given an array of integers and an integer k, you need to find the number of unique 
    /// k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), 
    /// where i and j are both numbers in the array and their absolute difference is k.
    ///
    /// Example 1:
    /// Input: [3, 1, 4, 1, 5], k = 2
    /// Output: 2
    /// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
    /// Although we have two 1s in the input, we should only return the number of unique pairs.
    /// Example 2:
    /// Input:[1, 2, 3, 4, 5], k = 1
    /// Output: 4
    /// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
    /// Example 3:
    /// Input: [1, 3, 1, 5, 4], k = 0
    /// Output: 1
    /// Explanation: There is one 0-diff pair in the array, (1, 1).
    /// Note:
    /// The pairs (i, j) and (j, i) count as the same pair.
    /// The length of the array won't exceed 10,000.
    /// All the integers in the given input belong to the range: [-1e7, 1e7].
    /// </summary>
    int findPairs(vector<int>& nums, int k);

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
    int findLHS(vector<int>& nums);

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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2);

    /// <summary>
    /// Leet code #721. Accounts Merge
    /// </summary>
    bool checkCommonEmail(set<string>& emails, vector<string>& account);

    /// <summary>
    /// Leet code #721. Accounts Merge
    /// </summary>
    void addNewAccount(unordered_map<string, set<int>>& account_map, vector<set<string>>& account_emails,
        vector<string>& account);

    /// <summary>
    /// Leet code #721. Accounts Merge
    /// </summary>
    void mergeAccount(unordered_map<string, set<int>>& account_map, vector<set<string>>& account_emails, vector<int>& merge_list,
        vector<string>& account);

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
    /// 1.The length of accounts will be in the range [1, 1000].
    /// 2.The length of accounts[i] will be in the range [1, 10].
    /// 3.The length of accounts[i][j] will be in the range [1, 30].
    /// </summary>
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts);

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
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2,
        vector<pair<string, string>> pairs);

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
    string shortestCompletingWord(string licensePlate, vector<string>& words);

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
    vector<int> anagramMappings(vector<int>& A, vector<int>& B);

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
    int numMatchingSubseq(string S, vector<string>& words);

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
    vector<string> subdomainVisits(vector<string>& cpdomains);

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
    vector<string> uncommonFromSentences(string A, string B);

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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern);

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
    vector<string> wordSubsets(vector<string>& A, vector<string>& B);

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
    vector<int> prisonAfterNDays(vector<int>& cells, int N);

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
    int numPairsDivisibleBy60(vector<int>& time);

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
    bool isRobotBounded(string instructions);

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
    int numEquivDominoPairs(vector<vector<int>>& dominoes);

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
    vector<string> mostVisitedPattern(vector<string>& username,
        vector<int>& timestamp, vector<string>& website);

    /// <summary>
    /// Leet code #1207. Unique Number of Occurrences
    ///
    /// Given an array of integers arr, write a function that returns 
    /// true if and only if the number of occurrences of each value in the 
    /// array is unique.
    ///
    /// 
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
    bool uniqueOccurrences(vector<int>& arr);

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
    int longestSubsequence(vector<int>& arr, int difference);

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
    int maxEqualFreq(vector<int>& nums);

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
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2);

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
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats);

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
    int findLucky(vector<int>& arr);

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
    vector<vector<string>> displayTable(vector<vector<string>>& orders);

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
    int countElements(vector<int>& arr);

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
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies);

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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k);

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
    vector<string> getFolderNames(vector<string>& names);

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
    bool isPathCrossing(string path);

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
    int numIdenticalPairs(vector<int>& nums);

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
    int numTriplets(vector<int>& nums1, vector<int>& nums2);

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
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime);

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
    int maxOperations(vector<int>& nums, int k);

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
    int countPairs(vector<int>& deliciousness);

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
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries);

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
    int sumOfUnique(vector<int>& nums);

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
    int minAbsDifference(vector<int>& nums, int goal);

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
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships);

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
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue);

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
    int countNicePairs(vector<int>& nums);

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
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k);

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
    bool areOccurrencesEqual(string s);

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
    string kthDistinct(vector<string>& arr, int k); 

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
    int countQuadruplets(vector<int>& nums); 


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
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3); 

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
    long long wonderfulSubstrings(string word);

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
    vector<int> findLonely(vector<int>& nums);

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
    bool divideArray(vector<int>& nums);

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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);

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
    int minimumRounds(vector<int>& tasks);

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
    vector<int> intersection(vector<vector<int>>& nums);

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
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations);

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
    int maximumSum(vector<int>& nums);

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
    string bestHand(vector<int>& ranks, vector<char>& suits);

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
    int findMaxK(vector<int>& nums);

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
    int countDistinctIntegers(vector<int>& nums);

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
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views);

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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B);

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
    vector<int> distinctDifferenceArray(vector<int>& nums);

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
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo);
};
#endif  // LeetCodeHashtable
