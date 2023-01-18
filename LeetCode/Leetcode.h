#pragma once
#ifndef Leetcode_H
#define LeetCode_H
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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct DoublyLinkedNode {
    int val;
    DoublyLinkedNode* prev;
    DoublyLinkedNode* next;
    DoublyLinkedNode* child;
    DoublyLinkedNode() { prev = nullptr; next = nullptr; child = nullptr; val = 0; }
    DoublyLinkedNode(int _val)
    {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

struct TreeNode {
    int val;
    int count;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode* random;
    TreeNode(int x) : val(x), count(0), left(nullptr), right(nullptr), parent(nullptr), random(nullptr) {}
};

struct QuadNode {
public:
    bool val;
    bool isLeaf;
    QuadNode* topLeft;
    QuadNode* topRight;
    QuadNode* bottomLeft;
    QuadNode* bottomRight;

    QuadNode() { val = 0; isLeaf = false; topLeft = nullptr; topRight = nullptr; bottomLeft = nullptr; bottomRight = nullptr; }
    

    QuadNode(bool _val, bool _isLeaf, QuadNode* _topLeft, QuadNode* _topRight, QuadNode* _bottomLeft, QuadNode* _bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

struct Node {
    int val;
    vector<Node*> children;

    Node() { val = 0; }

    Node(int _val, vector<Node*> _children) 
    {
        val = _val;
        children = _children;
    }
};

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

#pragma region Design

class NestedInteger
{
private:
    vector<NestedInteger> m_NestedIntegers;
    int m_Integer;
    bool m_IsInteger;
    int m_Size;
public:
    // Constructure on single integter.
    NestedInteger()
    {
        m_NestedIntegers = vector<NestedInteger>();
        m_Size = 0;
        m_Integer = 0;
        m_IsInteger = false;
    }

    // Constructure on single integter.
    NestedInteger(int value)
    {
        m_NestedIntegers = vector<NestedInteger>();
        m_Integer = value;
        m_IsInteger = true;
        m_Size = 1;
    }

    // Constructure on nested integers.
    NestedInteger(vector<NestedInteger> nested_integers)
    {
        m_NestedIntegers = nested_integers;
        m_Integer = 0;
        m_IsInteger = false;
        m_Size = nested_integers.size();
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return m_IsInteger;
    };

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return m_Integer;
    };

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value)
    {
        m_Integer = value;
        m_IsInteger = true;
        m_NestedIntegers.clear();
        m_Size = 1;
    };

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni)
    {
        if (m_Size == 1 && isInteger())
        {
            m_NestedIntegers.push_back(m_Integer);
        }
        m_NestedIntegers.push_back((NestedInteger)ni);
        m_IsInteger = false;
        m_Size++;
    };

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const
    {
        return m_NestedIntegers;
    };
};


struct TrieNode
{
    bool is_end;
    vector<TrieNode *> children;

    TrieNode() 
    {
        is_end = false;
        children = vector<TrieNode *>(26, nullptr);
    };

    ~TrieNode()
    {
        for (size_t i = 0; i < children.size(); i++)
        {
            if (children[i] != nullptr) delete children[i];
        }
    }

    void insert(string word, int i)
    {
        if (i == word.size())
        {
            is_end = true;
        }
        else
        {
            int k = word[i] - 'a';
            if (children[k] == nullptr)
            {
                children[k] = new TrieNode();
            }
            children[k]->insert(word, i + 1);
        }
    }

    TrieNode * next(char ch)
    {
        int k = ch - 'a';
        return children[k];
    }

    void get_words(string &word, vector<string>& result)
    {
        if (is_end) result.push_back(word);

        for (size_t i = 0; i < children.size(); i++)
        {
            if (children[i] != nullptr)
            {
                word.push_back((char)('a' + i));
                children[i]->get_words(word, result);
                word.pop_back();
            }
        }
    }
};
#pragma endregion 

/// <summary>
/// The class is to implement some string algorithm 
/// </summary>
class LeetCode
{
public:

#pragma region DynamicProgramming
    /// <summary>
    /// Leet code #484. Find Permutation   
    /// 
    /// By now, you are given a secret signature consisting of character 'D' and 'I'. 
    /// 'D' represents a decreasing relationship between two numbers, 'I' represents 
    /// an increasing relationship between two numbers. And our secret signature was 
    /// constructed by a special integer array, which contains uniquely all the 
    /// different number from 1 to n (n is the length of the secret signature plus 1). 
    /// For example, the secret signature "DI" can be constructed by array [2,1,3] or 
    /// [3,1,2], but won't be constructed by array [3,2,4] or [2,1,3,4], which are both 
    /// illegal constructing special string that can't represent the "DI" 
    /// secret signature. 
    /// On the other hand, now your job is to find the lexicographically smallest 
    /// permutation of [1, 2, ... n] could refer to the given secret signature in the input. 
    ///
    /// Example 1:
    /// Input: "I"
    /// Output: [1,2]
    /// Explanation: [1,2] is the only legal initial spectial string can construct secret 
    /// signature "I", where the number 1 and 2 construct an increasing relationship.
    ///
    /// Example 2:
    ///
    /// Input: "DI"
    /// Output: [2,1,3]
    /// Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature "DI", 
    /// but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]
    /// Note: 
    /// The input string will only contain the character 'D' and 'I'.
    /// The length of input string is a positive integer and will not exceed 10,000
    /// </summary>
    vector<int> findPermutation(string s);

    /// <summary>
    /// Leet code #375. Guess Number Higher or Lower II 
    /// 
    /// We are playing the Guess Game. The game is as follows:
    /// I pick a number from 1 to n. You have to guess which number I picked. 
    /// Every time you guess wrong, I'll tell you whether the number I 
    /// picked is higher or lower. 
    /// However, when you guess a particular number x, and you guess wrong, 
    /// you pay $x. 
    /// You win the game when you guess the number I picked.
    /// Example: 
    /// n = 10, I pick 8.
    /// First round:  You guess 5, I tell you that it's higher. You pay $5.
    /// Second round: You guess 7, I tell you that it's higher. You pay $7.
    /// Third round:  You guess 9, I tell you that it's lower. You pay $9.
    /// Game over. 8 is the number I picked.
    /// You end up paying $5 + $7 + $9 = $21.
    /// Given a particular n ≥ 1, find out how much money you need to have to 
    /// guarantee a win.
    /// Hint:
    /// 1.The best strategy to play the game is to minimize the maximum loss you 
    ///   could possibly face. 
    ///   Another strategy is to minimize the expected loss. Here, we are 
    ///   interested in the first scenario.
    /// 2. Take a small example (n = 3). What do you end up paying in the 
    ///    worst case?
    /// 3. Check out this article if you're still stuck.
    /// 4.The purely recursive implementation of minimax would be worthless for 
    ///   even a small n. 
    ///   You MUST use dynamic programming. 
    /// 5.As a follow-up, how would you modify your code to solve the problem 
    ///   of minimizing the expected loss, 
    ///   instead of the worst-case loss? 
    /// </summary>
    int getMoneyAmount(int n);

    /// <summary>
    /// Leet code #552. Student Attendance Record II
    /// 
    /// Given a positive integer n, return the number of all possible 
    /// attendance records with length n, which will be regarded as 
    /// rewardable. The answer may be very large, return it after 
    /// mod 10^9 + 7.
    /// A student attendance record is a string that only contains the 
    /// following three characters:
    ///
    /// 'A' : Absent. 
    /// 'L' : Late.
    /// 'P' : Present. 
    /// A record is regarded as rewardable if it doesn't contain more 
    /// than one 'A' (absent) or more than two continuous 'L' (late).
    /// Example 1:
    /// Input: n = 2
    /// Output: 8 
    /// Explanation:
    /// There are 8 records with length 2 will be regarded as rewardable:
    /// "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
    /// Only "AA" won't be regarded as rewardable owing to more than one 
    /// absent times. 
    /// Note: The value of n won't exceed 100,000. 
    /// </summary>
    int checkRecord(int n);

    /// <summary>
    /// Leet code #583. Delete Operation for Two Strings
    /// 
    /// Given two words word1 and word2, find the minimum number of steps required 
    /// to make word1 and word2 the same, where in each step you can delete one 
    /// character in either string. 
    /// Example 1:
    /// Input: "sea", "eat"
    /// Output: 2
    /// Explanation: You need one step to make "sea" to "ea" and another step to 
    /// make "eat" to "ea".
    /// Note:
    /// 1. The length of given words won't exceed 500.
    /// 2. Characters in given words can only be lower-case letters.
    /// </summary>
    int minDeleteDistance(string word1, string word2);

    /// <summary>
    /// Leet code #600. Non-negative Integers without Consecutive Ones
    /// 
    /// Given a positive integer n, find the number of non-negative integers 
    /// less than or equal to n, whose binary representations do NOT contain 
    /// consecutive ones.
    /// Example 1:
    /// Input: 5
    /// Output: 5
    /// Explanation: 
    /// Here are the non-negative integers <= 5 with their corresponding 
    /// binary representations:
    /// 0 : 0
    /// 1 : 1
    /// 2 : 10
    /// 3 : 11
    /// 4 : 100
    /// 5 : 101
    /// Among them, only integer 3 disobeys the rule (two consecutive ones) 
    /// and the other 5 satisfy the rule. 
    /// Note: 1 <= n <= 10^9 
    /// </summary>
    int findIntegers(int num);

    /// <summary>
    /// Leet code #634. Find the Derangement of An Array
    /// 
    /// In combinatorial mathematics, a derangement is a permutation of the 
    /// elements of a set, such that no element appears in its original 
    /// position.
    /// 
    /// There's originally an array consisting of n integers from 1 to n in 
    /// ascending order, you need to find the number of derangement it can 
    /// generate.
    /// 
    /// Also, since the answer may be very large, you should return the output 
    /// mod 10^9 + 7.
    ///
    /// Example 1:
    /// Input: 3
    /// Output: 2
    /// Explanation: The original array is [1,2,3]. The two derangements are 
    /// [2,3,1] and [3,1,2].
    /// Note:
    /// n is in the range of [1, 10^6].
    /// </summary>
    int findDerangement(int n);

    /// <summary>
    /// Leet code #639. Decode Ways II
    /// 
    /// A message containing letters from A-Z is being encoded to numbers using 
    /// the following mapping way: 
    /// 'A' -> 1
    /// 'B' -> 2
    /// ...
    /// 'Z' -> 26
    /// Beyond that, now the encoded string can also contain the character '*', 
    /// which can be treated as one of the numbers from 1 to 9. 
    /// Given the encoded message containing digits and the character '*', return 
    /// the total number of ways to decode it. 
    /// Also, since the answer may be very large, you should return the output 
    /// mod 10^9 + 7. 
    ///
    /// Example 1:
    /// Input: "*"
    /// Output: 9
    /// Explanation: The encoded message can be decoded to the string: "A", "B", 
    /// "C", "D", "E", "F", "G", "H", "I".
    ///
    /// Example 2:
    /// Input: "1*"
    /// Output: 9 + 9 = 18
    ///
    /// Note:
    /// The length of the input string will fit in range [1, 10^5].
    /// The input string will only contain the character '*' and digits '0' - '9'.
    /// </summary>
    int numDecodingsII(string s);

    /// <summary>
    /// Leet code #647. Palindromic Substrings
    /// 
    /// Given a string, your task is to count how many palindromic substrings 
    /// in this string. 
    /// The substrings with different start indexes or end indexes are counted 
    /// as different substrings even they consist of same characters. 
    /// Example 1:
    /// Input: "abc"
    /// Output: 3
    /// Explanation: Three palindromic strings: "a", "b", "c".
    /// 
    /// Example 2:
    /// Input: "aaa"
    /// Output: 6
    /// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
    ///    
    /// Note:
    /// The input string length won't exceed 1000.
    /// </summary>
    int countSubstrings(string s);

    /// <summary>
    /// Leet code #650. 2 Keys Keyboard
    /// 
    /// Initially on a notepad only one character 'A' is present. You can 
    /// perform two operations on this notepad for each step:
    ///
    /// Copy All: You can copy all the characters present on the notepad 
    /// (partial copy is not allowed).
    /// Paste: You can paste the characters which are copied last time.
    /// Given a number n. You have to get exactly n 'A' on the notepad by 
    /// performing the minimum number of steps permitted. Output the minimum 
    /// number of steps to get n 'A'.
    /// 
    /// Example 1:
    /// Input: 3
    /// Output: 3
    /// Explanation:
    /// Intitally, we have one character 'A'.
    /// In step 1, we use Copy All operation.
    /// In step 2, we use Paste operation to get 'AA'.
    /// In step 3, we use Paste operation to get 'AAA'.
    /// Note:
    /// 1. The n will be in the range [1, 1000].
    /// </summary>
    int minSteps(int n);

    /// <summary>
    /// Leet code #651. 4 Keys Keyboard
    /// </summary>
    void insert_step(pair<int, int>&step, set<pair<int, int>> &step_set);

    /// <summary>
    /// Leet code #651. 4 Keys Keyboard
    /// 
    /// Key 1: (A): Prints one 'A' on screen.
    /// Key 2: (Ctrl-A): Select the whole screen.
    /// Key 3: (Ctrl-C): Copy selection to buffer.
    /// Key 4: (Ctrl-V): Print buffer on screen appending it after what has 
    ///        already been printed.
    /// Now, you can only press the keyboard for N times (with the above four 
    /// keys), find out the maximum numbers of 'A' you can print on screen.
    /// Example 1:
    /// Input: N = 3
    /// Output: 3
    /// Explanation: 
    /// We can at most get 3 A's on screen by pressing following key sequence:
    /// A, A, A
    /// Example 2:
    /// Input: N = 7
    /// Output: 9
    /// Explanation: 
    /// We can at most get 9 A's on screen by pressing following key sequence:
    /// A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
    /// Note:
    /// 1. 1 <= N <= 50
    /// 2. Answers will be in the range of 32-bit signed integer.
    /// </summary>
    int maxA(int N);

    /// <summary>
    /// Leet code # 660. Remove 9
    /// Start from integer 1, remove any integer that contains 9 such as 9, 
    /// 19, 29...
    ///
    /// So now, you will have a new integer sequence: 1, 2, 3, 4, 5, 6, 7, 
    /// 8, 10, 11, ...
    ///
    /// Given a positive integer n, you need to return the n-th integer after 
    /// removing. Note that 1 will be the first integer.
    ///
    /// Example 1:
    /// Input: 9
    /// Output: 10
    /// Hint: n will not exceed 9 x 10^8.
    /// </summary>
    int newInteger(int n);

    /// <summary>
    /// Leet code #664. Strange Printer
    /// 
    /// There is a strange printer with the following two special requirements:
    /// The printer can only print a sequence of the same character each time.
    ///
    /// At each turn, the printer can print new characters starting from and 
    /// ending at any places, and will cover the original existing characters.
    /// Given a string consists of lower English letters only, your job is to 
    /// count the minimum number of turns the printer needed in order to print 
    /// it.
    ///
    /// Example 1:
    ///
    /// Input: "aaabbb"
    /// Output: 2
    /// Explanation: Print "aaa" first and then print "bbb".
    ///
    /// Example 2:
    /// Input: "aba"
    /// Output: 2
    /// Explanation: Print "aaa" first and then print "b" from the second 
    /// place of the string, which will cover the existing character 'a'.
    ///
    /// Hint: Length of the given string will not exceed 100.
    /// </summary>
    int strangePrinter(string s);

    /// <summary>
    /// Leet code #688. Knight Probability in Chessboard
    ///
    /// On an NxN chessboard, a knight starts at the r-th row and c-th column 
    /// and attempts to make exactly K moves. The rows and columns are 0 
    /// indexed, so the top-left square is (0, 0), and the bottom-right square 
    /// is (N-1, N-1).
    /// A chess knight has 8 possible moves it can make, as illustrated below. 
    /// Each move is two squares in a cardinal direction, then one square in 
    /// an orthogonal direction.
    /// 
    /// Each time the knight is to move, it chooses one of eight possible moves 
    /// uniformly at random (even if the piece would go off the chessboard) and 
    /// moves there.
    /// 
    /// The knight continues moving until it has made exactly K moves or has 
    /// moved off the chessboard. Return the probability that the knight 
    /// remains on the board after it has stopped moving.
    ///
    /// Example:
    /// Input: 3, 2, 0, 0
    /// Output: 0.0625
    /// Explanation: There are two moves (to (1,2), (2,1)) that will keep the 
    /// knight on the board.
    /// From each of those positions, there are also two moves that will keep 
    /// the knight on the board.
    /// The total probability the knight stays on the board is 0.0625.
    /// Note:
    /// 1. N will be between 1 and 25.
    /// 2. K will be between 0 and 100.
    /// 3. The knight always initially starts on the board.
    /// </summary>
    double knightProbability(int N, int K, int r, int c);

    /// <summary>
    /// Leet code #712. Minimum ASCII Delete Sum for Two Strings
    /// Given two strings s1, s2, find the lowest ASCII sum of deleted 
    /// characters to make two strings equal.
    ///
    /// Example 1:
    /// Input: s1 = "sea", s2 = "eat"
    /// Output: 231
    /// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" 
    /// (115) to the sum.
    /// Deleting "t" from "eat" adds 116 to the sum.
    /// At the end, both strings are equal, and 115 + 116 = 231 is the minimum 
    /// sum possible to achieve this.
    ///
    /// Example 2:
    /// Input: s1 = "delete", s2 = "leet"
    /// Output: 403
    /// Explanation: Deleting "dee" from "delete" to turn the string into 
    /// "let", adds 100{d}+101{e}+101{e} to the sum.  Deleting "e" from "leet" 
    /// adds 101{e} to the sum.
    /// At the end, both strings are equal to "let", and the answer is 
    /// 100+101+101+101 = 403.
    /// If instead we turned both strings into "lee" or "eet", we would get 
    /// answers of 433 or 417, which are higher.
    /// Note:
    ///
    /// 0 < s1.length, s2.length <= 1000.
    /// All elements of each string will have an ASCII value in {97, 122}.
    /// </summary>
    int minimumDeleteSum(string s1, string s2);

    /// <summary>
    /// Leet code #718. Maximum Length of Repeated Subarray
    ///
    /// Given two integer arrays A and B, return the maximum length of an 
    /// subarray that appears in both arrays.
    ///
    /// Example 1:
    /// Input:
    /// A: [1,2,3,2,1]
    /// B: [3,2,1,4,7]
    /// Output: 3
    /// Explanation: 
    /// The repeated subarray with maximum length is [3, 2, 1].
    /// Note:
    /// 1. 1 <= len(A), len(B) <= 1000
    /// 2. 0 <= A[i], B[i] < 100
    /// </summary>
    int findLength(vector<int>& A, vector<int>& B);

    /// <summary>
    /// Leet code #689. Maximum Sum of 3 Non-Overlapping Subarrays
    ///
    /// In a given array nums of positive integers, find three non-overlapping 
    /// subarrays with maximum sum.
    ///
    /// Each subarray will be of size k, and we want to maximize the sum of all
    /// 3*k entries.
    /// Return the result as a list of indices representing the starting 
    /// position of each interval (0-indexed). If there are multiple answers, 
    /// return the lexicographically smallest one.
    /// 
    /// Example:
    /// Input: [1,2,1,2,6,7,5,1], 2
    /// Output: [0, 3, 5]
    /// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the 
    /// starting indices [0, 3, 5].
    /// We could have also taken [2, 1], but an answer of [1, 3, 5] would be 
    /// lexicographically larger.
    /// Note:
    /// 1.nums.length will be between 1 and 20000.
    /// 2.nums[i] will be between 1 and 65535.
    /// 3.k will be between 1 and floor(nums.length / 3).
    /// </summary>
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #714. Best Time to Buy and Sell Stock with Transaction Fee
    /// Your are given an array of integers prices, for which the i-th element 
    /// is the price of a given stock on day i; and a non-negative integer fee 
    /// representing a transaction fee.
    ///
    /// You may complete as many transactions as you like, but you need to pay 
    /// the transaction fee for each transaction. You may not buy more than 1 
    /// share of a stock at a time (ie. you must sell the stock share before 
    /// you buy again.)
    ///
    /// Return the maximum profit you can make.
    ///
    /// Example 1:
    /// Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
    /// Output: 8  
    /// Explanation: The maximum profit can be achieved by:
    /// Buying at prices[0] = 1
    /// Selling at prices[3] = 8
    /// Buying at prices[4] = 4
    /// Selling at prices[5] = 9
    /// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
    /// Note:
    ///
    /// 1. 0 < prices.length <= 50000.
    /// 2. 0 < prices[i] < 50000.
    /// 3. 0 <= fee < 50000.	
    /// </summary>
    int maxProfitWithFee(vector<int>& prices, int fee);

    /// <summary>
    /// Leet code #727. Minimum Window Subsequence
    ///
    /// Given strings S and T, find the minimum (contiguous) substring W of S,
    /// so that T is a subsequence of W.
    ///
    /// If there is no such window in S that covers all characters in T, return 
    /// the empty string "". If there are multiple such minimum-length windows, 
    /// return the one with the left-most starting index.
    ///
    /// Example 1:
    /// Input: 
    /// S = "abcdebdde", T = "bde"
    /// Output: "bcde"
    /// Explanation: 
    /// "bcde" is the answer because it occurs before "bdde" which has the same 
    /// length.
    /// "deb" is not a smaller window because the elements of T in the window 
    /// must occur in order.
    /// Note:
    ///
    /// All the strings in the input will only contain lowercase letters.
    /// The length of S will be in the range [1, 20000].
    /// The length of T will be in the range [1, 100].
    /// </summary>
    string minWindowIII(string S, string T);

    /// <summary>
    /// Leet code #730. Count Different Palindromic Subsequences
    ///
    /// Given a string S, find the number of different non-empty palindromic 
    /// subsequences in S, and return that number modulo 10^9 + 7.
    ///
    /// A subsequence of a string S is obtained by deleting 0 or more 
    /// characters from S.
    ///
    /// A sequence is palindromic if it is equal to the sequence reversed.
    ///
    /// Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there 
    /// is some i for which A_i != B_i.
    ///
    /// Example 1:
    /// Input: 
    /// S = 'bccb'
    /// Output: 6
    /// Explanation: 
    /// The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 
    /// 'cc', 'bcb', 'bccb'.
    /// Note that 'bcb' is counted only once, even though it occurs twice.
    /// Example 2:
    /// Input: 
    /// S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
    /// Output: 104860361
    /// Explanation: 
    /// There are 3104860382 different non-empty palindromic subsequences, 
    /// which is 104860361 modulo 10^9 + 7.
    /// Note:
    ///
    /// 1. The length of S will be in the range [1, 1000].
    /// 2. Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.
    /// </summary>
    int countPalindromicSubsequences(string S);

    /// <summary>
    /// Leet code #740. Delete and Earn
    ///
    /// Given an array nums of integers, you can perform operations on the 
    /// array. 
    /// In each operation, you pick any nums[i] and delete it to earn nums[i] 
    /// points. After, you must delete every element equal to nums[i] - 1 or 
    /// nums[i] + 1. 
    /// You start with 0 points. Return the maximum number of points you can 
    /// earn by applying such operations. 
    ///
    /// Example 1:
    /// Input: nums = [3, 4, 2]
    /// Output: 6
    /// Explanation: 
    /// Delete 4 to earn 4 points, consequently 3 is also deleted.
    /// Then, delete 2 to earn 2 points. 6 total points are earned.
    ///
    /// Example 2:
    /// Input: nums = [2, 2, 3, 3, 3, 4]
    /// Output: 9
    /// Explanation: 
    /// Delete 3 to earn 3 points, deleting both 2's and the 4.
    /// Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
    /// 9 total points are earned.
    ///
    /// Note: 
    /// The length of nums is at most 20000.
    /// Each element nums[i] is an integer in the range [1, 10000].
    /// </summary> 
    int deleteAndEarn(vector<int>& nums);

    /// <summary>
    /// Leet code #741. Cherry Pickup
    ///
    /// In a N x N grid representing a field of cherries, each cell is one of 
    /// three possible integers.
    ///
    /// 0 means the cell is empty, so you can pass through;
    /// 1 means the cell contains a cherry, that you can pick up and pass 
    /// through;
    /// -1 means the cell contains a thorn that blocks your way.
    /// Your task is to collect maximum number of cherries possible by 
    /// following the rules below:
    ///
    /// Starting at the position (0, 0) and reaching (N-1, N-1) by moving 
    /// right or down through valid path cells (cells with value 0 or 1);
    /// After reaching (N-1, N-1), returning to (0, 0) by moving left or up 
    /// through valid path cells;
    /// When passing through a path cell containing a cherry, you pick it up 
    /// and the cell becomes an empty cell (0);
    /// If there is no valid path between (0, 0) and (N-1, N-1), then no 
    /// cherries can be collected.
    /// Example 1:
    /// Input: grid =
    /// [[0, 1, -1],
    ///  [1, 0, -1],
    /// [1, 1,  1]]
    /// Output: 5
    /// Explanation: 
    /// The player started at (0, 0) and went down, down, right right to reach 
    /// (2, 2).
    /// 4 cherries were picked up during this single trip, and the matrix 
    /// becomes [[0,1,-1],[0,0,-1],[0,0,0]].
    /// Then, the player went left, up, up, left to return home, picking up one
    /// more cherry.
    /// The total number of cherries picked up is 5, and this is the maximum 
    /// possible.
    ///
    /// Note:
    /// grid is an N by N 2D array, with 1 <= N <= 50.
    /// Each grid[i][j] is an integer in the set {-1, 0, 1}.
    /// It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.
    /// </summary> 
    int cherryPickup(vector<vector<int>>& grid);
    int cherryPickupII(vector<vector<int>>& grid);

    /// <summary>
    /// Leetcode #746. Min Cost Climbing Stairs
    ///
    /// On a staircase, the i-th step has some non-negative cost cost[i] 
    /// assigned (0 indexed).
    ///
    /// Once you pay the cost, you can either climb one or two steps. You need 
    /// to find minimum cost to reach the top of the floor, and you can either 
    /// start from the step with index 0, or the step with index 1.
    ///
    /// Example 1:
    /// Input: cost = [10, 15, 20]
    /// Output: 15
    /// Explanation: Cheapest is start on cost[1], pay that cost and go to 
    /// the top.
    /// Example 2:
    /// Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    /// Output: 6
    /// Explanation: Cheapest is start on cost[0], and only step on 1s, 
    /// skipping cost[3].
    /// Note:
    /// 1. cost will have a length in the range [2, 1000].
    /// 2. Every cost[i] will be an integer in the range [0, 999].
    /// </summary>
    int minCostClimbingStairs(vector<int>& cost);

    /// <summary>
    /// Leetcode #764. Largest Plus Sign
    ///
    /// In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except 
    /// those cells in the given list mines which are 0. What is the largest 
    /// axis-aligned plus sign of 1s contained in the grid? Return the order of 
    /// the plus sign. If there is none, return 0.
    ///
    /// An "axis-aligned plus sign of 1s of order k" has some center 
    /// grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, 
    /// and right, and made of 1s. This is demonstrated in the diagrams below. 
    /// Note that there could be 0s or 1s beyond the arms of the plus sign, 
    /// only the relevant area of the plus sign is checked for 1s.
    ///
    /// Examples of Axis-Aligned Plus Signs of Order k:
    /// Order 1:
    /// 000
    /// 010
    /// 000
    ///
    /// Order 2:
    /// 00000
    /// 00100
    /// 01110
    /// 00100
    /// 00000
    ///
    /// Order 3:
    /// 0000000
    /// 0001000
    /// 0001000
    /// 0111110
    /// 0001000
    /// 0001000
    /// 0000000
    ///
    /// Example 1:
    /// Input: N = 5, mines = [[4, 2]]
    /// Output: 2
    /// Explanation:
    /// 11111
    /// 11111
    /// 11111
    /// 11111
    /// 11011
    /// In the above grid, the largest plus sign can only be order 2.  One of 
    /// them is marked in bold.
    ///
    /// Example 2:
    /// Input: N = 2, mines = []
    /// Output: 1
    /// Explanation:
    /// There is no plus sign of order 2, but there is of order 1.
    ///
    /// Example 3:
    /// Input: N = 1, mines = [[0, 0]]
    /// Output: 0
    /// Explanation:
    /// There is no plus sign, so return 0.
    /// Note:
    /// 1. N will be an integer in the range [1, 500].
    /// 2. mines will have length at most 5000.
    /// 3. mines[i] will be length 2 and consist of integers in the range 
    /// [0, N-1].
    /// (Additionally, programs submitted in C, C++, or C# will be judged 
    /// with a slightly smaller time limit.)
    /// </summary>
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines);

    /// <summary>
    /// Leetcode #788. Rotated Digits
    /// </summary>
    int rotatedDigits(int N, bool is_diff);

    /// <summary>
    /// Leetcode #788. Rotated Digits
    /// </summary>
    int checkIfRotateDigits(int N);

    /// <summary>
    /// Leetcode #788. Rotated Digits
    ///
    /// X is a good number if after rotating each digit individually by 180 
    /// degrees, we get a valid number that is different from X. A number is 
    /// valid if each digit remains a digit after rotation. 0, 1, and 8 rotate 
    /// to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each 
    /// other, and the rest of the numbers do not rotate to any other number.
    ///
    /// Now given a positive number N, how many numbers X from 1 to N are good?
    ///
    /// Example:
    /// Input: 10
    /// Output: 4
    /// Explanation: 
    /// There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
    /// Note that 1 and 10 are not good numbers, since they remain unchanged 
    /// after rotating.
    /// Note:
    ///
    /// 1. N  will be in range [1, 10000].
    /// </summary>
    int rotatedDigits(int N);

    /// <summary>
    /// Leet code #790. Domino and Tromino Tiling
    /// 
    /// We have two types of tiles: a 2x1 domino shape, and an "L" tromino 
    /// shape. These shapes may be rotated.
    ///
    /// XX  <- domino
    ///
    /// XX  <- "L" tromino
    /// X
    /// Given N, how many ways are there to tile a 2 x N board? Return your 
    /// answer modulo 10^9 + 7.
    ///
    /// (In a tiling, every square must be covered by a tile. Two tilings 
    /// are different if and only if there are two 4-directionally adjacent 
    /// cells on the board such that exactly one of the tilings has both 
    /// squares occupied by a tile.)
    ///
    /// Example:
    /// Input: 3
    /// Output: 5
    /// Explanation: 
    /// The five different ways are listed below, different letters indicates 
    /// different tiles:
    /// XYZ XXZ XYY XXY XYY
    /// XYZ YYZ XZZ XYY XXY
    /// Note:
    ///
    /// 1. N  will be in range [1, 1000].
    /// </summary>
    int numTilings(int N);

    /// <summary>
    /// Leet code #795. Number of Subarrays with Bounded Maximum
    ///
    /// We are given an array A of positive integers, and two positive 
    /// integers L and R (L <= R).
    ///
    /// Return the number of (contiguous, non-empty) subarrays such that the 
    /// value of the maximum array element in that subarray is at least L and 
    /// at most R.
    ///
    /// Example :
    /// Input: 
    /// A = [2, 1, 4, 3]
    /// L = 2
    /// R = 3
    /// Output: 3
    /// Explanation: There are three subarrays that meet the requirements: 
    /// [2], [2, 1], [3].
    /// Note:
    /// 1. L, R  and A[i] will be an integer in the range [0, 10^9].
    /// 2. The length of A will be in the range of [1, 50000].
    /// </summary>
    int numSubarrayBoundedMax(vector<int>& A, int L, int R);

    /// <summary>
    /// Leet code #793. Preimage Size of Factorial Zeroes Function
    ///
    /// Let f(x) be the number of zeroes at the end of x!. (Recall that x! = 
    /// 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)
    /// For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while 
    /// f(11) = 2 because 11! = 39916800 has 2 zeroes at the end. Given K, 
    /// find how many non-negative integers x have the property that f(x) = K.
    /// Example 1:
    /// Input: K = 0
    /// Output: 5
    /// Explanation: 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.
    ///
    /// Example 2:
    /// Input: K = 5
    /// Output: 0
    /// Explanation: There is no x such that x! ends in K = 5 zeroes.
    /// Note:
    /// 1. K will be an integer in the range [0, 10^9].
    /// </summary>
    int preimageSizeFZF(int K);

    /// <summary>
    /// Leet code #799. Champagne Tower
    /// 
    /// We stack glasses in a pyramid, where the first row has 1 glass, the 
    /// second row has 2 glasses, and so on until the 100th row.  Each glass 
    /// holds one cup (250ml) of champagne.
    ///
    /// Then, some champagne is poured in the first glass at the top.  When 
    /// the top most glass is full, any excess liquid poured will fall equally 
    /// to the glass immediately to the left and right of it.  When those 
    /// glasses become full, any excess champagne will fall equally to the left
    /// and right of those glasses, and so on.  (A glass at the bottom row has 
    /// it's excess champagne fall on the floor.)
    ///
    /// For example, after one cup of champagne is poured, the top most glass 
    /// is full.  After two cups of champagne are poured, the two glasses on 
    /// the second row are half full.  After three cups of champagne are 
    /// poured, those two cups become full - there are 3 full glasses total 
    /// now.  After four cups of champagne are poured, the third row has the 
    /// middle glass half full, and the two outside glasses are a quarter 
    /// full, as pictured below.
    ///
    /// Then, some champagne is poured in the first glass at the top.  When 
    /// the top most glass is full, any excess liquid poured will fall equally 
    /// to the glass immediately to the left and right of it.  When those 
    /// glasses become full, any excess champagne will fall equally to the left 
    /// and right of those glasses, and so on.  (A glass at the bottom row has 
    /// it's excess champagne fall on the floor.)
    ///
    /// For example, after one cup of champagne is poured, the top most glass 
    /// is full.  After two cups of champagne are poured, the two glasses on 
    /// the second row are half full.  After three cups of champagne are 
    /// poured, those two cups become full - there are 3 full glasses total 
    /// now.  After four cups of champagne are poured, the third row has the 
    /// middle glass half full, and the two outside glasses are a quarter 
    /// full, as pictured below.
    ///
    /// Example 1:
    /// Input: poured = 1, query_glass = 1, query_row = 1
    /// Output: 0.0
    /// Explanation: We poured 1 cup of champange to the top glass of the tower 
    /// (which is indexed as (0, 0)). There will be no excess liquid so all the 
    /// glasses under the top glass will remain empty.
    ///
    /// Example 2:
    /// Input: poured = 2, query_glass = 1, query_row = 1
    /// Output: 0.5
    /// Explanation: We poured 2 cups of champange to the top glass of the 
    /// tower (which is indexed as (0, 0)). There is one cup of excess liquid. 
    /// The glass indexed as (1, 0) and the glass indexed as (1, 1) will share 
    /// the excess liquid equally, and each will get half cup of champange.
    ///
    /// Now after pouring some non-negative integer cups of champagne, return 
    /// how full the j-th glass in the i-th row is (both i and j are 0 indexed.)
    ///
    /// Note:
    /// 1. poured will be in the range of [0, 10 ^ 9].
    /// 2. query_glass and query_row will be in the range of [0, 99].
    /// </summary>
    double champagneTower(int poured, int query_row, int query_glass);

    /// <summary>
    /// Leet code #801. Minimum Swaps To Make Sequences Increasing
    /// 
    /// We have two integer sequences A and B of the same non-zero length.
    /// We are allowed to swap elements A[i] and B[i].  Note that both elements
    /// are in the same index position in their respective sequences.
    ///
    /// At the end of some number of swaps, A and B are both strictly 
    /// increasing.  (A sequence is strictly increasing if and only if 
    /// A[0] < A[1] < A[2] < ... < A[A.length - 1].)
    ///
    /// Given A and B, return the minimum number of swaps to make both 
    /// sequences strictly increasing.  It is guaranteed that the given 
    /// input always makes it possible.
    ///
    /// Example:
    /// Input: A = [1,3,5,4], B = [1,2,3,7]
    /// Output: 1
    /// Explanation: 
    /// Swap A[3] and B[3].  Then the sequences are:
    /// A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
    /// which are both strictly increasing.
    /// Note:
    ///
    /// 1. A, B are arrays with the same length, and that length will be in the 
    ///    range [1, 1000].
    /// 2. A[i], B[i] are integer values in the range [0, 2000].
    /// </summary>
    int minSwap(vector<int>& A, vector<int>& B);

    /// <summary>
    /// Leet code #808. Soup Servings
    /// </summary>
    double soupServings(int A, int B, unordered_map<int, unordered_map<int, double>> &possibility);

    /// <summary>
    /// Leet code #808. Soup Servings
    /// 
    /// There are two types of soup: type A and type B. Initially we have N ml
    /// of each type of soup. There are four kinds of operations:
    ///
    /// Serve 100 ml of soup A and 0 ml of soup B
    /// Serve 75 ml of soup A and 25 ml of soup B
    /// Serve 50 ml of soup A and 50 ml of soup B
    /// Serve 25 ml of soup A and 75 ml of soup B
    /// When we serve some soup, we give it to someone and we no longer have 
    /// it.  Each turn, we will choose from the four operations with equal 
    /// probability 0.25. If the remaining volume of soup is not enough to 
    /// complete the operation, we will serve as much as we can.  We stop 
    /// once we no longer have some quantity of both types of soup.
    ///
    /// Note that we do not have the operation where all 100 ml's of soup B are 
    /// used first.  
    ///
    /// Return the probability that soup A will be empty first, plus half the 
    /// probability that A and B become empty at the same time.
    ///  
    /// Example:
    /// Input: N = 50
    /// Output: 0.625
    /// Explanation: 
    /// If we choose the first two operations, A will become empty first. For 
    /// the third operation, A and B will become empty at the same time. For 
    /// the fourth operation, B will become empty first. So the total 
    /// probability of A becoming empty first plus half the probability that A 
    /// and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 
    /// 0.625.
    /// Notes:
    /// 1. 0 <= N <= 10^9. 
    /// 2. Answers within 10^-6 of the true value will be accepted as correct.
    /// </summary>
    double soupServings(int N);

    /// <summary>
    /// Leet code #813. Largest Sum of Averages
    /// 
    /// We partition a row of numbers A into at most K adjacent (non-empty) 
    /// groups, then our score is the sum of the average of each group. 
    /// What is the largest score we can achieve?
    ///
    /// Note that our partition must use every number in A, and that scores 
    /// are not necessarily integers.
    ///
    /// Example:
    /// Input: 
    /// A = [9,1,2,3,9]
    /// K = 3
    /// Output: 20
    /// Explanation: 
    /// The best choice is to partition A into [9], [1, 2, 3], [9]. The 
    /// answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
    /// We could have also partitioned A into [9, 1], [2], [3, 9], for example.
    /// That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
    ///
    /// Note:
    /// 1. 1 <= A.length <= 100.
    /// 2. 1 <= A[i] <= 10000.
    /// 3. 1 <= K <= A.length.
    /// 4. Answers within 10^-6 of the correct answer will be accepted as 
    ///    correct.
    /// </summary>
    double largestSumOfAverages(vector<int>& A, int K);

    /// <summary>
    /// Leet code #823. Binary Trees With Factors
    /// 
    /// Given an array of unique integers, each integer is strictly greater 
    /// than 1.
    ///
    /// We make a binary tree using these integers and each number may be used 
    /// for any number of times.
    ///
    /// Each non-leaf node's value should be equal to the product of the 
    /// values of it's children.
    ///
    /// How many binary trees can we make?  Return the answer modulo 
    /// 10 ** 9 + 7.
    /// 
    /// Example 1:
    ///
    /// Input: A = [2, 4]
    /// Output: 3
    /// Explanation: We can make these trees: [2], [4], [4, 2, 2]
    ///  
    /// Example 2:
    ///
    /// Input: A = [2, 4, 5, 10]
    /// Output: 7
    /// Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], 
    /// [10, 2, 5], [10, 5, 2].
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 1000.
    /// 2. 2 <= A[i] <= 10 ^ 9.
    /// </summary>
    int numFactoredBinaryTrees(vector<int>& A);

    /// <summary>
    /// Leet code #828. Unique Letter String
    /// 
    /// A character is unique in string S if it occurs exactly once in it.
    ///
    /// For example, in string S = "LETTER", the only unique characters are 
    /// "L" and "R".
    ///
    /// Let's define UNIQ(S) as the number of unique characters in string S.
    ///
    /// For example, UNIQ("LETTER") =  2.
    ///
    /// Given a string S with only uppercases, calculate the sum of 
    /// UNIQ(substring) over all non-empty substrings of S.
    ///
    /// If there are two or more equal substrings at different positions in S, 
    /// we consider them different.
    ///
    /// Since the answer can be very large, retrun the answer modulo 
    /// 10 ^ 9 + 7.
    ///
    /// Example 1:
    /// Input: "ABC"
    /// Output: 10
    /// Explanation: All possible substrings are: "A","B","C","AB","BC" and 
    /// "ABC".
    /// Evey substring is composed with only unique letters.
    /// Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
    ///
    /// Example 2:
    /// Input: "ABA"
    /// Output: 8
    /// Explanation: The same as example 1, except uni("ABA") = 1.
    ///
    /// Note: 0 <= S.length <= 10000.
    /// </summary>
    int uniqueLetterString(string S);

    /// <summary>
    /// Leet code #834. Sum of Distances in Tree
    /// </summary>
    void calcuateChildrenDistance(int root, int parent, vector<vector<int>> &tree, unordered_map<int, pair<int, int>> &tree_stat);

    /// <summary>
    /// Leet code #834. Sum of Distances in Tree
    /// </summary>
    void calcuateAllDistance(int root, int parent, vector<vector<int>> &tree, unordered_map<int, pair<int, int>> &tree_stat);

    /// <summary>
    /// Leet code #834. Sum of Distances in Tree
    /// 
    /// An undirected, connected tree with N nodes labelled 0...N-1 and N-1 
    /// edges are given.
    ///
    /// The ith edge connects nodes edges[i][0] and edges[i][1] together.
    ///
    /// Return a list ans, where ans[i] is the sum of the distances between 
    /// node i and all other nodes.
    ///
    /// Example 1:
    ///
    /// Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
    /// Output: [8,12,6,10,10,10]
    /// Explanation: 
    /// Here is a diagram of the given tree:
    ///   0
    ///  / \
    /// 1   2
    ///    /|\
    ///   3 4 5
    /// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + 
    /// dist(0,5)
    /// equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
    /// Note: 1 <= N <= 10000
    /// </summary>
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges);

    /// <summary>
    /// Leet code #837. New 21 Game
    /// 
    /// Alice plays the following game, loosely based on the card game "21".
    ///
    /// Alice starts with 0 points, and draws numbers while she has less than 
    /// K points.  During each draw, she gains an integer number of points 
    /// randomly from the range [1, W], where W is an integer.  Each draw is 
    /// independent and the outcomes have equal probabilities.
    ///
    /// Alice stops drawing numbers when she gets K or more points.  What is 
    /// the probability that she has N or less points?
    ///
    /// Example 1:
    ///
    /// Input: N = 10, K = 1, W = 10
    /// Output: 1.00000
    /// Explanation:  Alice gets a single card, then stops.
    ///
    /// Example 2:
    ///
    /// Input: N = 6, K = 1, W = 10
    /// Output: 0.60000
    /// Explanation:  Alice gets a single card, then stops.
    /// In 6 out of W = 10 possibilities, she is at or below N = 6 points.
    /// Example 3:
    ///
    /// Input: N = 21, K = 17, W = 10
    /// Output: 0.73278
    /// Note:
    ///
    /// 1. 0 <= K <= N <= 10000
    /// 2. 1 <= W <= 10000
    /// 3. Answers will be accepted as correct if they are within 10^-5 of 
    ///    the correct answer.
    /// 4. The judging time limit has been reduced for this question.
    /// </summary>
    double new21Game(int N, int K, int W);

    /// <summary>
    /// Leet code #873. Length of Longest Fibonacci Subsequence
    /// 
    /// A sequence X_1, X_2, ..., X_n is fibonacci-like if:
    ///
    /// n >= 3
    /// X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
    /// Given a strictly increasing array A of positive integers forming a 
    /// sequence, find the length of the longest fibonacci-like subsequence 
    /// of A.  If one does not exist, return 0.
    ///
    /// (Recall that a subsequence is derived from another sequence A by 
    /// deleting any number of elements (including none) from A, without 
    /// changing the order of the remaining elements.  For example, 
    /// [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)
    /// 
    /// Example 1:
    /// Input: [1,2,3,4,5,6,7,8]
    /// Output: 5
    /// Explanation:
    /// The longest subsequence that is fibonacci-like: [1,2,3,5,8].
    ///
    /// Example 2:
    /// Input: [1,3,7,11,12,14,18]
    /// Output: 3
    /// Explanation:
    /// The longest subsequence that is fibonacci-like:
    /// [1,11,12], [3,11,14] or [7,11,18].
    ///
    /// Note:
    /// 
    /// 1. 3 <= A.length <= 1000
    /// 2. 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9	/// </summary>
    /// </summary>
    int lenLongestFibSubseq(vector<int>& A);

    /// <summary>
    /// Leet code #877. Stone Game
    /// 
    /// Alex and Lee play a game with piles of stones.  There are an even 
    /// number of piles arranged in a row, and each pile has a positive 
    /// integer number of stones piles[i].
    ///
    /// The objective of the game is to end with the most stones.  The 
    /// total number of stones is odd, so there are no ties.
    ///
    /// Alex and Lee take turns, with Alex starting first.  Each turn, 
    /// a player takes the entire pile of stones from either the beginning 
    /// or the end of the row.  This continues until there are no more piles 
    /// left, at which point the person with the most stones wins.
    ///
    /// Assuming Alex and Lee play optimally, return True if and only if Alex 
    /// wins the game.
    ///
    /// Example 1:
    /// Input: [5,3,4,5]
    /// Output: true
    /// Explanation: 
    /// Alex starts first, and can only take the first 5 or the last 5.
    /// Say he takes the first 5, so that the row becomes [3, 4, 5].
    /// If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win 
    /// with 10 points.
    /// If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 
    /// to win with 9 points.
    /// This demonstrated that taking the first 5 was a winning move for 
    /// Alex, so we return true.
    /// 
    /// Note:
    /// 1. 2 <= piles.length <= 500
    /// 2. piles.length is even.
    /// 3. 1 <= piles[i] <= 500
    /// 4. sum(piles) is odd.
    /// </summary>
    bool stoneGame(vector<int>& piles);

    /// <summary>
    /// Leet code #887. Super Egg Drop
    /// 
    /// You are given K eggs, and you have access to a building with N floors from 
    /// 1 to N. 
    ///
    /// Each egg is identical in function, and if an egg breaks, you cannot drop 
    /// it again.
    ///
    /// You know that there exists a floor F with 0 <= F <= N such that any egg 
    /// dropped at a floor higher than F will break, and any egg dropped at or 
    /// below floor F will not break.
    ///
    /// Each move, you may take an egg (if you have an unbroken one) and drop it 
    /// from any floor X (with 1 <= X <= N). 
    ///
    /// Your goal is to know with certainty what the value of F is.
    ///
    /// What is the minimum number of moves that you need to know with certainty 
    /// what F is, regardless of the initial value of F?
    ///
    /// Example 1:
    ///
    /// Input: K = 1, N = 2
    /// Output: 2
    /// Explanation: 
    /// Drop the egg from floor 1.  If it breaks, we know with certainty that 
    /// F = 0.
    /// Otherwise, drop the egg from floor 2.  If it breaks, we know with 
    /// certainty that F = 1.
    /// If it didn't break, then we know with certainty F = 2.
    /// Hence, we needed 2 moves in the worst case to know what F is with 
    /// certainty.
    ///
    /// Example 2:
    /// Input: K = 2, N = 6
    /// Output: 3
    ///
    /// Example 3
    /// Input: K = 3, N = 14
    /// Output: 4
    /// Note:
    /// 1 <= K <= 100
    /// 1 <= N <= 10000
    /// </summary>
    int superEggDrop(int K, int N);

    /// <summary>
    /// Leet code #880. Decoded String at Index
    /// 
    /// An encoded string S is given.  To find and write the decoded string to a 
    /// tape, the encoded string is read one character at a time and the following 
    /// steps are taken:
    ///
    /// If the character read is a letter, that letter is written onto the tape.
    /// If the character read is a digit (say d), the entire current tape is 
    /// repeatedly written d-1 more times in total.
    /// Now for some encoded string S, and an index K, find and return the K-th 
    /// letter (1 indexed) in the decoded string.
    ///
    /// Example 1:
    /// Input: S = "leet2code3", K = 10
    /// Output: "o"
    /// Explanation: 
    /// The decoded string is "leetleetcodeleetleetcodeleetleetcode".
    /// The 10th letter in the string is "o".
    ///
    /// Example 2:
    /// Input: S = "ha22", K = 5
    /// Output: "h"
    /// Explanation: 
    /// The decoded string is "hahahaha".  The 5th letter is "h".
    ///
    /// Example 3:
    /// Input: S = "a2345678999999999999999", K = 1
    /// Output: "a"
    /// Explanation: 
    /// The decoded string is "a" repeated 8301530446056247680 times.  The 1st 
    /// letter is "a".
    /// 
    /// Note:
    /// 1. 2 <= S.length <= 100
    /// 2. S will only contain lowercase letters and digits 2 through 9.
    /// 3. S starts with a letter.
    /// 4. 1 <= K <= 10^9
    /// 5. The decoded string is guaranteed to have less than 2^63 letters.
    /// </summary>
    string decodeAtIndex(string S, int K);

    /// <summary>
    /// Leet code #898. Bitwise ORs of Subarrays 
    /// 
    /// We have an array A of non-negative integers.
    ///
    /// For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] 
    /// (with i <= j), we take the bitwise OR of all the elements in B, 
    /// obtaining a result A[i] | A[i+1] | ... | A[j].
    ///
    /// Return the number of possible results.  (Results that occur more 
    /// than once are only counted once in the final answer.)
    ///
    /// Example 1:
    ///
    /// Input: [0]
    /// Output: 1
    /// Explanation: 
    /// There is only one possible result: 0.
    /// Example 2:
    ///
    /// Input: [1,1,2]
    /// Output: 3
    /// Explanation: 
    /// The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
    /// These yield the results 1, 1, 2, 1, 3, 3.
    /// There are 3 unique values, so the answer is 3.
    /// Example 3:
    ///
    /// Input: [1,2,4]
    /// Output: 6
    /// Explanation: 
    /// The possible results are 1, 2, 3, 4, 6, and 7.
    ///  
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 50000
    /// 2. 0 <= A[i] <= 10^9
    /// </summary>
    int subarrayBitwiseORs(vector<int>& A);

    /// <summary>
    /// Leet code #903. Valid Permutations for DI Sequence
    /// 
    /// We are given S, a length n string of characters from the set {'D', 'I'}. 
    /// (These letters stand for "decreasing" and "increasing".)
    ///
    /// A valid permutation is a permutation P[0], P[1], ..., P[n] of integers 
    /// {0, 1, ..., n}, such that for all i:
    ///
    /// If S[i] == 'D', then P[i] > P[i+1], and;
    /// If S[i] == 'I', then P[i] < P[i+1].
    /// How many valid permutations are there?  Since the answer may be large, 
    /// return your answer modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: "DID"
    /// Output: 5
    /// Explanation: 
    /// The 5 valid permutations of (0, 1, 2, 3) are:
    /// (1, 0, 3, 2)
    /// (2, 0, 3, 1)
    /// (2, 1, 3, 0)
    /// (3, 0, 2, 1)
    /// (3, 1, 2, 0)
    /// 
    /// Note:
    /// 1. 1 <= S.length <= 200
    /// 2. S consists only of characters from the set {'D', 'I'}.
    /// </summary>
    int numPermsDISequence(string S);

    /// <summary>
    /// Leet code #931. Minimum Falling Path Sum
    /// 
    /// Given a square array of integers A, we want the minimum sum of a falling 
    /// path through A.
    ///
    /// A falling path starts at any element in the first row, and chooses one 
    /// element from each row.  The next row's choice must be in a column that is 
    /// different from the previous row's column by at most one.
    /// 
    /// Example 1:
    ///
    /// Input: [[1,2,3],[4,5,6],[7,8,9]]
    /// Output: 12
    /// Explanation: 
    /// The possible falling paths are:
    /// [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
    /// [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
    /// [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
    /// The falling path with the smallest sum is [1,4,7], so the answer is 12.
    ///
    /// Note:
    /// 1. 1 <= A.length == A[0].length <= 100
    /// 2. -100 <= A[i][j] <= 100
    /// </summary>
    int minFallingPathSum(vector<vector<int>>& A);

    /// <summary>
    /// Leet code #935. Knight Dialer
    /// 
    /// A chess knight can move as indicated in the chess diagram below:
    ///
    /// This time, we place our chess knight on any numbered key of a phone pad 
    /// (indicated above), and the knight makes N-1 hops.  Each hop must be from 
    /// one key to another numbered key.
    ///
    /// Each time it lands on a key (including the initial placement of the 
    /// knight), it presses the number of that key, pressing N digits total.
    ///
    /// How many distinct numbers can you dial in this manner?
    ///
    /// Since the answer may be large, output the answer modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: 1
    /// Output: 10
    ///
    /// Example 2:
    /// Input: 2
    /// Output: 20
    ///
    /// Example 3:
    /// Input: 3
    /// Output: 46
    /// Note:
    /// 
    /// 1 <= N <= 5000
    /// </summary>
    int knightDialer(int N);

    /// <summary>
    /// Leet code #940. Distinct Subsequences II
    /// 
    /// Given a string S, count the number of distinct, non-empty subsequences of 
    /// S.
    ///
    /// Since the result may be large, return the answer modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: "abc"
    /// Output: 7
    /// Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", 
    /// "bc", and "abc".
    ///
    /// Example 2:
    /// Input: "aba"
    /// Output: 6
    /// Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" 
    /// and "aba".
    ///
    /// Example 3:
    /// 
    /// Input: "aaa"
    /// Output: 3
    /// Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
    ///  
    /// Note:
    ///
    /// 1. S contains only lowercase letters.
    /// 2. 1 <= S.length <= 2000
    /// </summary>
    int distinctSubseqII(string S);

    /// <summary>
    /// Leet code #956. Tallest Billboard
    /// 
    /// You are installing a billboard and want it to have the largest height.
    /// The billboard will have two steel supports, one on each side.  
    /// Each steel support must be an equal height.
    /// You have a collection of rods which can be welded together.  
    /// For example, if you have rods of lengths 1, 2, and 3, you can weld 
    /// them together to make a support of length 6.
    ///
    /// Return the largest possible height of your billboard installation.  
    /// If you cannot support the billboard, return 0.
    ///
    /// 
    /// Example 1:
    /// Input: [1,2,3,6]
    /// Output: 6
    /// Explanation: We have two disjoint subsets {1,2,3} and {6}, which have 
    /// the same sum = 6.
    ///
    /// Example 2:
    /// Input: [1,2,3,4,5,6]
    /// Output: 10
    /// Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which 
    /// have the same sum = 10.
    ///
    /// Example 3:
    /// Input: [1,2]
    /// Output: 0
    /// Explanation: The billboard cannot be supported, so we return 0.
    ///
    /// Note:
    /// 1. 0 <= rods.length <= 20
    /// 2. 1 <= rods[i] <= 1000
    /// 3. The sum of rods is at most 5000.
    /// </summary>
    int tallestBillboard(vector<int>& rods);

    /// <summary>
    /// Leet code #960. Delete Columns to Make Sorted III
    /// 
    /// We are given an array A of N lowercase letter strings, all of the same 
    /// length.
    ///
    /// Now, we may choose any set of deletion indices, and for each string, we 
    /// delete all the characters in those indices.
    ///
    /// For example, if we have an array A = ["babca","bbazb"] and deletion 
    /// indices {0, 1, 4}, then the final array after deletions is ["bc","az"].
    ///
    /// Suppose we chose a set of deletion indices D such that after deletions, 
    /// the final array has every element (row) in lexicographic order.
    ///
    /// For clarity, A[0] is in lexicographic order 
    /// (ie. A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]), A[1] is in 
    /// lexicographic order (ie. A[1][0] <= A[1][1] <= ... <= 
    /// A[1][A[1].length - 1]), and so on.
    ///
    /// Return the minimum possible value of D.length.
    ///
    /// Example 1:
    /// Input: ["babca","bbazb"]
    /// Output: 3
    /// Explanation: After deleting columns 0, 1, and 4, the final array is 
    /// A = ["bc", "az"].
    /// Both these rows are individually in lexicographic order 
    /// (ie. A[0][0] <= A[0][1] and A[1][0] <= A[1][1]).
    /// Note that A[0] > A[1] - the array A isn't necessarily in lexicographic 
    /// order.
    ///
    /// Example 2:
    /// Input: ["edcba"]
    /// Output: 4
    /// Explanation: If we delete less than 4 columns, the only row won't be 
    /// lexicographically sorted.
    ///
    /// Example 3:
    /// Input: ["ghi","def","abc"]
    /// Output: 0
    /// Explanation: All rows are already lexicographically sorted.
    /// 
    ///
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 100
    /// 2. 1 <= A[i].length <= 100
    /// </summary>
    int minDeletionSizeIII(vector<string>& A);

    /// <summary>
    /// Leet code #975. Odd Even Jump
    /// 
    /// You are given an integer array A.  From some starting index, you can make 
    /// a series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are 
    /// called odd numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the 
    /// series are called even numbered jumps.
    ///
    /// You may from index i jump forward to index j (with i < j) in the following 
    /// way:
    ///
    /// During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index 
    /// j such that A[i] <= A[j] and A[j] is the smallest possible value.  If there 
    /// are multiple such indexes j, you can only jump to the smallest such 
    /// index j.
    /// During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index 
    /// j such that A[i] >= A[j] and A[j] is the largest possible value.  If there 
    /// are multiple such indexes j, you can only jump to the smallest such 
    /// index j. 
    /// (It may be the case that for some index i, there are no legal jumps.)
    /// A starting index is good if, starting from that index, you can reach the 
    /// end of the array (index A.length - 1) by jumping some number of times 
    /// (possibly 0 or more than once.)
    ///
    /// Return the number of good starting indexes.
    ///
    /// Example 1:
    ///
    /// Input: [10,13,12,14,15]
    /// Output: 2
    /// Explanation: 
    /// From starting index i = 0, we can jump to i = 2 (since A[2] is the 
    /// smallest among A[1], A[2], A[3], A[4] that is greater or equal to A[0]), 
    /// then we can't jump any more.
    /// From starting index i = 1 and i = 2, we can jump to i = 3, then we can't 
    /// jump any more.
    /// From starting index i = 3, we can jump to i = 4, so we've reached the end.
    /// From starting index i = 4, we've reached the end already.
    /// In total, there are 2 different starting indexes (i = 3, i = 4) where we 
    /// can reach the end with some number of jumps.
    ///
    /// Example 2:
    /// 
    /// Input: [2,3,1,1,4]
    /// Output: 3
    /// Explanation: 
    /// From starting index i = 0, we make jumps to i = 1, i = 2, i = 3:
    ///
    /// During our 1st jump (odd numbered), we first jump to i = 1 because A[1] 
    /// is the smallest value in (A[1], A[2], A[3], A[4]) that is greater than 
    /// or equal to A[0].
    ///
    /// During our 2nd jump (even numbered), we jump from i = 1 to i = 2 because 
    /// A[2] is the largest value in (A[2], A[3], A[4]) that is less than or equal 
    /// to A[1].  A[3] is also the largest value, but 2 is a smaller index, so we 
    /// can only jump to i = 2 and not i = 3.
    ///
    /// During our 3rd jump (odd numbered), we jump from i = 2 to i = 3 because 
    /// A[3] is the smallest value in (A[3], A[4]) that is greater than or equal to
    /// A[2].
    ///
    /// We can't jump from i = 3 to i = 4, so the starting index i = 0 is not good.
    ///
    /// In a similar manner, we can deduce that:
    /// From starting index i = 1, we jump to i = 4, so we reach the end.
    /// From starting index i = 2, we jump to i = 3, and then we can't jump 
    /// anymore.
    /// From starting index i = 3, we jump to i = 4, so we reach the end.
    /// From starting index i = 4, we are already at the end.
    /// In total, there are 3 different starting indexes (i = 1, i = 3, i = 4) 
    /// where we can reach the end with some number of jumps.
    ///
    /// Example 3:
    /// 
    /// Input: [5,1,3,4,2]
    /// Output: 3
    /// Explanation: 
    /// We can reach the end from starting indexes 1, 2, and 4.
    ///
    /// Note:
    ///
    /// 1. 1 <= A.length <= 20000
    /// 2. 0 <= A[i] < 100000
    /// </summary>
    int oddEvenJumps(vector<int>& A);
    
    /// <summary>
    /// Leet code #978. Longest Turbulent Subarray
    /// 
    /// A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if 
    /// and only if:
    /// For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when 
    /// k is even;
    /// OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] 
    /// when k is odd.
    /// That is, the subarray is turbulent if the comparison sign flips 
    /// between each adjacent pair of elements in the subarray.
    /// Return the length of a maximum size turbulent subarray of A.
    ///
    /// Example 1:
    /// Input: [9,4,2,10,7,8,8,1,9]
    /// Output: 5
    /// Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
    /// Example 2:
    /// Input: [4,8,12,16]
    /// Output: 2
    ///
    /// Example 3:
    /// Input: [100]
    /// Output: 1
    ///
    /// Note:
    /// 1. 1 <= A.length <= 40000
    /// 2. 0 <= A[i] <= 10^9
    /// </summary>
    int maxTurbulenceSize(vector<int>& A);

    /// <summary>
    /// Leet code #982. Triples with Bitwise AND Equal To Zero
    /// 
    /// Given an array of integers A, find the number of triples of indices 
    /// (i, j, k) such that:
    /// 0 <= i < A.length
    /// 0 <= j < A.length
    /// 0 <= k < A.length
    /// A[i] & A[j] & A[k] == 0, where & represents 
    /// the bitwise-AND operator.
    /// 
    /// Example 1:
    /// Input: [2,1,3]
    /// Output: 12
    /// Explanation: We could choose the following i, j, k triples:
    /// (i=0, j=0, k=1) : 2 & 2 & 1
    /// (i=0, j=1, k=0) : 2 & 1 & 2
    /// (i=0, j=1, k=1) : 2 & 1 & 1
    /// (i=0, j=1, k=2) : 2 & 1 & 3
    /// (i=0, j=2, k=1) : 2 & 3 & 1
    /// (i=1, j=0, k=0) : 1 & 2 & 2
    /// (i=1, j=0, k=1) : 1 & 2 & 1
    /// (i=1, j=0, k=2) : 1 & 2 & 3
    /// (i=1, j=1, k=0) : 1 & 1 & 2
    /// (i=1, j=2, k=0) : 1 & 3 & 2
    /// (i=2, j=0, k=1) : 3 & 2 & 1
    /// (i=2, j=1, k=0) : 3 & 1 & 2
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 1000
    /// 2. 0 <= A[i] < 2^16
    /// </summary>
    int countTriplets(vector<int>& A);

    /// <summary>
    /// Leet code #983. Minimum Cost For Tickets
    /// </summary>
    int mincostTickets(int index, vector<int>& days, vector<int>& dp, vector<int>& costs);

    /// <summary>
    /// Leet code #983. Minimum Cost For Tickets
    /// 
    /// In a country popular for train travel, you have planned some train 
    /// travelling one year in advance.  The days of the year that you will 
    /// travel is given as an array days.  Each day is an integer from 1 to 365.
    /// Train tickets are sold in 3 different ways:
    /// 1. a 1-day pass is sold for costs[0] dollars;
    /// 2. a 7-day pass is sold for costs[1] dollars;
    /// 3. a 30-day pass is sold for costs[2] dollars.
    /// The passes allow that many days of consecutive travel.  For example, if 
    /// we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 
    /// 5, 6, 7, and 8.
    /// Return the minimum number of dollars you need to travel every day in the 
    /// given list of days.
    /// 
    /// Example 1:
    /// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
    /// Output: 11
    /// Explanation: 
    /// For example, here is one way to buy passes that lets you travel your 
    /// travel plan:
    /// 1. On day 1, you bought a 1-day pass for costs[0] = $2, which covered 
    ///    day 1.
    /// 2. On day 3, you bought a 7-day pass for costs[1] = $7, which covered 
    ///    days 3, 4, ..., 9.
    /// 3. On day 20, you bought a 1-day pass for costs[0] = $2, which covered 
    ///    day 20.
    /// 4. In total you spent $11 and covered all the days of your travel.
    ///
    /// Example 2:
    /// Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
    /// Output: 17
    /// Explanation: 
    /// For example, here is one way to buy passes that lets you travel your 
    /// travel plan:
    /// 1. On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 
    ///    1, 2, ..., 30.
    /// 2. On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 
    ///    31.
    /// 3. In total you spent $17 and covered all the days of your travel.
    ///  
    /// Note:
    /// 1. 1 <= days.length <= 365
    /// 2. 1 <= days[i] <= 365
    /// 3. days is in strictly increasing order.
    /// 4. costs.length == 3
    /// 5. 1 <= costs[i] <= 1000
    /// </summary>
    int mincostTickets(vector<int>& days, vector<int>& costs);
 

    /// Leet code #1025. Divisor Game
    /// 
    /// Alice and Bob take turns playing a game, with Alice starting first.
    ///
    /// Initially, there is a number N on the chalkboard.  On each player's 
    /// turn, that player makes a move consisting of:
    ///
    /// Choosing any x with 0 < x < N and N % x == 0.
    /// Replacing the number N on the chalkboard with N - x.
    /// Also, if a player cannot make a move, they lose the game.
    /// 
    /// Return True if and only if Alice wins the game, assuming both players 
    /// play optimally.
    ///
    /// Example 1:
    /// Input: 2
    /// Output: true
    /// Explanation: Alice chooses 1, and Bob has no more moves.
    ///
    /// Example 2:
    /// Input: 3
    /// Output: false
    /// Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
    /// 
    /// Note:
    /// 1. 1 <= N <= 1000
    /// </summary>
    bool divisorGame(int N);

    /// <summary>
    /// Leet code #1027. Longest Arithmetic Sequence
    /// 
    /// Given an array A of integers, return the length of the longest arithmetic 
    /// subsequence in A.
    ///
    /// Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 
    /// 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is 
    /// arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < 
    /// B.length - 1).
    ///
    /// Example 1:
    ///
    /// Input: [3,6,9,12]
    /// Output: 4
    /// Explanation: 
    /// The whole array is an arithmetic sequence with steps of length = 3.
    ///
    /// Example 2:
    ///
    /// Input: [9,4,7,2,10]
    /// Output: 3
    /// Explanation: 
    /// The longest arithmetic subsequence is [4,7,10].
    ///
    /// Example 3:
    ///
    /// Input: [20,1,15,3,10,5,8]
    /// Output: 4
    /// Explanation: 
    /// The longest arithmetic subsequence is [20,15,10,5].
    /// 
    /// Note:
    /// 
    /// 1. 2 <= A.length <= 2000
    /// 2. 0 <= A[i] <= 10000
    /// </summary>
    int longestArithSeqLength(vector<int>& A);

    /// <summary>
    /// Leet code #1031. Maximum Sum of Two Non-Overlapping Subarrays
    /// 
    /// Given an array A of non-negative integers, return the maximum sum of 
    /// elements in two non-overlapping (contiguous) subarrays, which have 
    /// lengths L and M.  (For clarification, the L-length subarray could occur 
    /// before or after the M-length subarray.)
    ///
    /// Formally, return the largest V for which V = (A[i] + A[i+1] + ... + 
    /// A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
    ///
    /// 0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
    /// 0 <= j < j + M - 1 < i < i + L - 1 < A.length.
    /// 
    ///
    /// Example 1:
    ///
    /// Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
    /// Output: 20
    /// Explanation: One choice of subarrays is [9] with length 1, and [6,5] with 
    /// length 2.
    ///
    /// Example 2:
    ///
    /// Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
    /// Output: 29
    /// Explanation: One choice of subarrays is [3,8,1] with length 3, and 
    /// [8,9] with length 2.
    ///
    /// Example 3:
    ///
    /// Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
    /// Output: 31
    /// Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] 
    /// with length 3.
    ///
    /// Note:
    ///
    /// 1. L >= 1
    /// 2. M >= 1
    /// 3. L + M <= A.length <= 1000
    /// 4. 0 <= A[i] <= 1000
    /// </summary>
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M);

    /// <summary>
    /// Leet code #1039. Minimum Score Triangulation of Polygon
    /// </summary>
    int minScoreTriangulation(vector<int>& A, int start, int end, unordered_map<string, int>& cache);

    /// <summary>
    /// Leet code #1039. Minimum Score Triangulation of Polygon
    /// 
    /// Given N, consider a convex N-sided polygon with vertices labelled 
    /// A[0], A[i], ..., A[N-1] in clockwise order.
    ///
    /// Suppose you triangulate the polygon into N-2 triangles.  For each 
    /// triangle, the value of that triangle is the product of the labels 
    /// of the vertices, and the total score of the triangulation is the 
    /// sum of these values over all N-2 triangles in the triangulation.
    ///
    /// Return the smallest possible total score that you can achieve with some 
    /// triangulation of the polygon.
    /// 
    /// Example 1:
    ///
    /// Input: [1,2,3]
    /// Output: 6
    /// Explanation: The polygon is already triangulated, and the score of the 
    /// only triangle is 6.
    ///
    /// Example 2:
    ///
    /// Input: [3,7,4,5]
    /// Output: 144
    /// Explanation: There are two triangulations, with possible scores: 3*7*5 + 
    /// 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.
    ///
    /// Example 3:
    ///
    /// Input: [1,3,1,4,1,5]
    /// Output: 13
    /// Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 
    /// 1*1*5 + 1*1*1 = 13.
    /// 
    ///
    /// Note:
    ///
    /// 1. 3 <= A.length <= 50
    /// 2. 1 <= A[i] <= 100
    /// </summary>
    int minScoreTriangulation(vector<int>& A);

    /// <summary>
    /// Leet code #1039. Minimum Score Triangulation of Polygon
    /// </summary>
    int minScoreTriangulationII(vector<int>& A);

    /// <summary>
    /// Leet code #1043. Partition Array for Maximum Sum
    /// 
    /// Given an integer array A, you partition the array into (contiguous) 
    /// subarrays of length at most K.  After partitioning, each subarray has 
    /// their values changed to become the maximum value of that subarray.
    ///
    /// Return the largest sum of the given array after partitioning.
    /// 
    /// Example 1:
    ///
    /// Input: A = [1,15,7,9,2,5,10], K = 3
    /// Output: 84
    /// Explanation: A becomes [15,15,15,9,10,10,10]
    ///  
    ///
    /// Note:
    ///
    /// 1. 1 <= K <= A.length <= 500
    /// 2. 0 <= A[i] <= 10^6
    /// </summary>
    int maxSumAfterPartitioning(vector<int>& A, int K);
    
    /// <summary>
    /// Leet code #1048. Longest String Chain
    /// 
    /// Given a list of words, each word consists of English lowercase letters.
    ///
    /// Let's say word1 is a predecessor of word2 if and only if we can add 
    /// exactly one letter anywhere in word1 to make it equal to word2.  For 
    /// example, "abc" is a predecessor of "abac".
    ///
    /// A word chain is a sequence of words [word_1, word_2, ..., word_k] 
    /// with k >= 1, where word_1 is a predecessor of word_2, word_2 is a 
    /// predecessor of word_3, and so on.
    ///
    /// Return the longest possible length of a word chain with words chosen 
    /// from the given list of words.
    ///
    /// Example 1:
    ///
    /// Input: ["a","b","ba","bca","bda","bdca"]
    /// Output: 4
    /// Explanation: one of the longest word chain is "a","ba","bda","bdca".
    /// 
    /// Note:
    /// 1. 1 <= words.length <= 1000
    /// 2. 1 <= words[i].length <= 16
    /// 3. words[i] only consists of English lowercase letters.
    /// </summary>
    int longestStrChain(vector<string>& words);


    /// <summary>
    /// Leet code #1062. Longest Repeating Substring
    /// 
    /// Given a string S, find out the length of the longest repeating 
    /// substring(s). Return 0 if no repeating substring exists.
    ///
    /// Example 1:
    /// Input: "abcd"
    /// Output: 0
    /// Explanation: There is no repeating substring.
    ///
    /// Example 2:
    /// Input: "abbaba"
    /// Output: 2
    /// Explanation: The longest repeating substrings are "ab" and "ba", each of 
    /// which occurs twice.
    ///
    /// Example 3:
    /// Input: "aabcaabdaab"
    /// Output: 3
    /// Explanation: The longest repeating substring is "aab", which occurs 3 
    /// times.
    ///
    /// Example 4:
    ///
    /// Input: "aaaaa"
    /// Output: 4
    /// Explanation: The longest repeating substring is "aaaa", which occurs twice.
    ///
    /// Note:
    /// 
    /// 1. The string S consists of only lowercase English letters from 'a' - 'z'.
    /// 2. 1 <= S.length <= 1500
    /// </summary>
    int longestRepeatingSubstring(string S);

    /// <summary>
    /// Leet code #1092. Shortest Common Supersequence
    /// 
    /// Given two strings str1 and str2, return the shortest string that has 
    /// both str1 and str2 as subsequences.  If multiple answers exist, you 
    /// may return any of them.
    ///
    /// (A string S is a subsequence of string T if deleting some number of 
    /// characters from T (possibly 0, and the characters are chosen anywhere 
    /// from T) results in the string S.)
    ///
    /// Example 1:
    /// Input: str1 = "abac", str2 = "cab"
    /// Output: "cabac"
    /// Explanation: 
    /// str1 = "abac" is a substring of "cabac" because we can delete the 
    /// first "c".
    /// str2 = "cab" is a substring of "cabac" because we can delete the last 
    /// "ac".
    /// The answer provided is the shortest such string that satisfies these 
    /// properties.
    /// 
    /// Note:
    /// 1. 1 <= str1.length, str2.length <= 1000
    /// 2. str1 and str2 consist of lowercase English letters.
    /// </summary>
    string shortestCommonSupersequence(string str1, string str2);


#pragma endregion

#pragma region BackTracking


    /// <summary>
    /// Leet code #301. Remove Invalid Parentheses 
    /// </summary>
    void removeInvalidParentheses(string s, vector<char> p, int first, int last, vector<string> &result);

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
    void getFactors(int n, vector<int> factors, vector<vector<int>> &result);

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
    vector<string> generateAbbreviations(string word, unordered_map<string, vector<string>> &cache);

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
    void getAbbrBits(int index, int digits, int target_digits, string &abbr_bits, vector<string> &result);

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
    /// Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, 
    /// and log2(n) + m ≤ 20.
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
    void generatePalindromes(string s, string partial_result, unordered_set<int>&visited, vector<string>& result);

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
    int findMinStep(string board, unordered_map<char, int>&hand_map, unordered_map<string, int>& cache);

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
    /// 1.You may assume that the initial row of balls on the table won’t have any 3 or more 
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
    /// 1.A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
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
    void nextPattern(vector<int> &keys, vector<int>& visited, int m, int n, int &count);

    /// <summary>
    /// Leet code #351. Android Unlock Patterns
    /// </summary>
    int nextPattern(int key, int m, int n);

    /// <summary>
    /// Leet code #351. Android Unlock Patterns
    ///
    /// Given an Android 3x3 key lock screen and two integers m and n, where 
    /// 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android 
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
        unordered_map<string, pair<int, int>> &cache);

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
        vector<int>& needs, int index, int &total_price, int& min_price);

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
    bool NextTime(string& time, int index, set<char> &nums);

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
    bool buildPartitionKSubsets(vector<int>& nums, int index, vector<vector<int>> &path, 
        int partition_id, int partition_count, int sum, vector<int>& visited, 
        unordered_map<string, int> &search_map);

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
    int searchTarget(vector<vector<int>>&sticker_chars, vector<bool>& sticker_visited, string& target, 
        unordered_map<string, int> &cache);

    /// <summary>
    /// Leet code #691. Stickers to Spell Word
    ///
    /// check dominated stickers
    /// </summary>
    void checkDominatedStickers(vector<vector<int>>&sticker_chars, vector<bool>& sticker_visited);
    
    /// <summary>
    /// Leet code #691. Stickers to Spell Word
    ///
    /// Convert string to characters count
    /// </summary>
    void convertStringToCharCount(string& word, vector<int>&char_count, vector<int>&target_count);

    /// <summary>
    /// Leet code #691. Stickers to Spell Word
    ///
    /// reduce the target by sticker
    /// </summary>
    void reduceTarget(vector<int>&sticker_count, string &target);

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
    void nextPyramidTop(string& bottom, string &top, unordered_map<char, unordered_map<char, set<char>>> &allowed_map);

    /// <summary>
    /// Leet code #756. Pyramid Transition Matrix
    /// </summary>
    bool buildPyramidTransition(string& bottom, unordered_map<char, unordered_map<char, set<char>>> &allowed_map);

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

#pragma endregion
};

class Logger
{
public:
    static void WriteMessage(const char* message)
    {
        printf("%s\n", message);
    }

    static void WriteMessage(const string message)
    {
        printf("%s\n", message.c_str());
    }

    static void WriteMessage(vector<int> &data)
    {
        std::string message;
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append(std::to_string(data[i]) + " ");
        }
        WriteMessage(message.c_str());
    }

    static void WriteMessage(vector<long long>& data)
    {
        std::string message;
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append(std::to_string(data[i]) + " ");
        }
        WriteMessage(message.c_str());
    }

    static void WriteMessage(vector<double> &data)
    {
        std::string message;
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append(std::to_string(data[i]) + " ");
        }
        WriteMessage(message.c_str());
    }

    static void WriteMessage(vector<char> &data)
    {
        std::string message;
        for (size_t i = 0; i < data.size(); i++)
        {
            message.push_back(data[i]);
            message.push_back(' ');
        }
        WriteMessage(message.c_str());
    }

    static void WriteMessage(vector<bool> &data)
    {
        std::string message;
        message.append("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append (data[i] ? "true" : "false");
            message.push_back(' ');
        }
        message.append("]");
        WriteMessage(message.c_str());
    }

    static void WriteMessage(vector<vector<int>> &data)
    {
        WriteMessage("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            std::string message;
            message.append("[");
            for (size_t j = 0; j < data[i].size(); j++)
            {
                if (j > 0) message.append(",");
                message.append(to_string(data[i][j]));
            }
            message.append("]");
            WriteMessage(message.c_str());
        }
        WriteMessage("]");
    }

    static void WriteMessage(vector<vector<long long>>& data)
    {
        WriteMessage("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            std::string message;
            message.append("[");
            for (size_t j = 0; j < data[i].size(); j++)
            {
                if (j > 0) message.append(",");
                message.append(to_string(data[i][j]));
            }
            message.append("]");
            WriteMessage(message.c_str());
        }
        WriteMessage("]");
    }

    static void WriteMessage(vector<vector<double>> &data)
    {
        WriteMessage("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            std::string message;
            message.append("[");
            for (size_t j = 0; j < data[i].size(); j++)
            {
                if (j > 0) message.append(",");
                message.append(to_string(data[i][j]));
            }
            message.append("]");
            WriteMessage(message.c_str());
        }
        WriteMessage("]");
    }

    static void WriteMessage(vector<pair<int, int>> &data)
    {
        std::string message;
        message.append("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append("[");
            message.append(to_string(data[i].first) + "," + to_string(data[i].second));
            message.append("]");
        }
        message.append("]");
        WriteMessage(message);
    }

    static void WriteMessage(vector<pair<string, string>> &data)
    {
        std::string message;
        message.append("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append("[");
            message.append(data[i].first + "," + data[i].second);
            message.append("]");
        }
        message.append("]");
        WriteMessage(message);
    }

    static void WriteMessage(vector<Interval> &data)
    {
        std::string message;
        message.append("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append("[");
            message.append(to_string(data[i].start) + "," + to_string(data[i].end));
            message.append("]");
        }
        message.append("]");
        WriteMessage(message);
    }

    static void WriteMessage(vector<vector<Interval>> &data)
    {
        std::string message;
        message.append("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append("[");
            for (size_t j = 0; j < data[i].size(); j++)
            {
                message.append("[");
                message.append(to_string(data[i][j].start) + "," + to_string(data[i][j].end));
                message.append("]");
            }
            message.append("]");
        }
        message.append("]");
        WriteMessage(message);
    }

    static void WriteMessage(vector<Point> &data)
    {
        std::string message;
        message.append("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            message.append("[");
            message.append(to_string(data[i].x) + "," + to_string(data[i].y));
            message.append("]");
        }
        message.append("]");
        WriteMessage(message);
    }

    static void WriteMessage(vector<string> &data)
    {
        std::string message;
        message.append("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            if (i > 0) message.append(",");
            message.append(data[i]);
        }
        message.append("]");
        WriteMessage(message.c_str());
    }

    static void WriteMessage(vector<vector<string>> &data)
    {
        WriteMessage("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            std::string message;
            message.append("[");
            for (size_t j = 0; j < data[i].size(); j++)
            {
                if (j > 0) message.append(",");
                message.append(data[i][j]);
            }
            message.append("]");
            WriteMessage(message.c_str());
        }
        WriteMessage("]");
    }

    static void WriteMessage(vector<vector<char>> &data)
    {
        WriteMessage("[");
        for (size_t i = 0; i < data.size(); i++)
        {
            std::string message;
            message.append("[");
            for (size_t j = 0; j < data[i].size(); j++)
            {
                if (j > 0) message.push_back(',');
                message.push_back(data[i][j]);
            }
            message.append("]");
            WriteMessage(message.c_str());
        }
        WriteMessage("]");
    }

    static void WriteMessage(unordered_set<string> &data)
    {
        std::string message;
        message.append("[");
        for (string word : data)
        {
            if (message.size() > 1) message.append(",");
            message.append(word);
        }
        message.append("]");
        WriteMessage(message.c_str());
    }

    static void WriteMessage(ListNode * data)
    {
        ListNode* current = data;
        std::string message;
        while (data != nullptr)
        {
            message.append(to_string(data->val) + " ");
            data = data->next;
        }
        WriteMessage(message.c_str());
    }

    static void WriteMessage(RandomListNode * data)
    {
        RandomListNode* current = data;
        std::string message;
        while (data != nullptr)
        {
            message.append(to_string(data->label));
            message.append("(");
            if (data->random != nullptr)
            {
                message.append(to_string(data->random->label));
            }
            message.append(")");
            message.append(" ");
            data = data->next;
        }
        WriteMessage(message.c_str());
    }

    static void WriteMessage(UndirectedGraphNode* root)
    {
        std::string message;
        unordered_set<UndirectedGraphNode*> node_set;
        queue<UndirectedGraphNode*> search_queue;
        search_queue.push(root);

        while (!search_queue.empty())
        {
            if (!message.empty()) message.append("#");
            UndirectedGraphNode* node = search_queue.front();
            search_queue.pop();
            if (node == nullptr) continue;
            if (node_set.find(node) != node_set.end()) continue;

            node_set.insert(node);
            message.append(to_string(node->label));
            for (auto neighbor : node->neighbors)
            {
                message.append("," + to_string(neighbor->label));
                search_queue.push(neighbor);
            }
        }
        WriteMessage(message.c_str());
    }
};

class Assert
{
public:
    static void IsTrue(bool condition)
    {
        if (!condition)
        {
            throw new exception();
        }
        else
        {
            Logger::WriteMessage("Test Pass");
        }
    }
};

/// <summary>
/// The class is used to generate a series of random integer so we can used it in algorithm
/// </summary>
class RandomNumber
{
public:
    /// <summary>
    /// Initializes the random seed, do it once at very beginning
    /// </summary>
    static void Initialize()
    {
        srand((unsigned int)time(NULL));
    }

    /// <summary>
    /// Gets the random number. which is from 0 to max_value -1
    /// </summary>
    /// <param name="max_value">The maximum value.</param>
    /// <returns></returns>
    static int GetRandomNumber(int max_value)
    {
        return rand() % max_value;
    }
};
#endif
