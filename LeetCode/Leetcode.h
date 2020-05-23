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
    TreeNode(int x) : val(x), count(0), left(nullptr), right(nullptr), parent(nullptr) {}
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



/// <summary>
/// Assume you have a sales organization 
/// Employee,Manager,ItemsSold
/// Alice,,5
/// Bob,Alice,3
/// Carol,Bob,2
/// David,Bob,3
/// Eve,Alice,2
/// Ferris,Eve,1
///
/// Please print it as the following format
/// Alice 16
/// |-Bob 8
/// | |-Carol 2
/// | |-David 3
/// |-Eve 3
/// | |-Ferris 1
/// </summary>
class SalesOrg
{
private:
    map<string, set<string>> m_Team;
    map<string, int> m_SalesAmount;
    map<string, string> m_Manager;
    
    string print(string& employee, int level)
    {
        string result;
        for (size_t i = 0; i < (size_t)level; i++)
        {
            if (i > 0) result += " ";
            result += "|";
        }
        if (level > 0) result += "-";
        result += employee;
        result += " ";
        result += to_string(m_SalesAmount[employee]);
        return result;
    }

    void print(string &employee, int level, vector<string> & result)
    {
        result.push_back(print(employee, level));
        if (m_Team[employee].empty()) return;
        for (string team_member : m_Team[employee])
        {
            print(team_member, level + 1, result);
        }
    }
public:
    SalesOrg()
    {
    }

    void addSalesRecord(string employee, string manager, int amount)
    {
        m_Manager[employee] = manager;
        while (true)
        {
            m_SalesAmount[employee] += amount;
            manager = m_Manager[employee];
            m_Team[manager].insert(employee);
            employee = manager;
            if (employee == "") break;
        }
    }

    vector<string> print()
    {
        vector<string> result;
        for (string team_member : m_Team[""])
        {
            print(team_member, 0, result);
        }
        return result;
    }
};


class Master
{
private:
    string secret;

public:
    Master(string str)
    {
        secret = str;
    }
    int guess(string str)
    {
        int result = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] == secret[i])
            {
                result++;
            }
        }
        return result;
    }
};




#pragma endregion 
/// <summary>
/// The class is to implement some string algorithm 
/// </summary>
class LeetCode
{
public:
#pragma region Math

    /// <summary>
    /// Leet code #12. Integer to Roman
    ///  
    /// Roman numerals are represented by seven different 
    /// symbols: I, V, X, L, C, D and M.
    ///
    /// Symbol       Value
    /// I             1
    /// V             5
    /// X             10
    /// L             50
    /// C             100
    /// D             500
    /// M             1000
    /// For example, two is written as II in Roman numeral, just two one's 
    /// added together. Twelve is written as, XII, which is simply X + II. 
    /// The number twenty seven is written as XXVII, which is XX + V + II.
    ///
    /// Roman numerals are usually written largest to smallest from left to 
    /// right. However, the numeral for four is not IIII. Instead, the number 
    /// four is written as IV. Because the one is before the five we subtract 
    /// it making four. The same principle applies to the number nine, which 
    /// is written as IX. There are six instances where subtraction is used:
    ///
    /// I can be placed before V (5) and X (10) to make 4 and 9. 
    /// X can be placed before L (50) and C (100) to make 40 and 90. 
    /// C can be placed before D (500) and M (1000) to make 400 and 900.
    /// Given an integer, convert it to a roman numeral. Input is guaranteed 
    /// to be within the range from 1 to 3999.
    ///
    /// Example 1:
    /// 
    /// Input: 3
    /// Output: "III"
    ///
    /// Example 2:
    ///
    /// Input: 4
    /// Output: "IV"
    ///
    /// Example 3:
    ///
    /// Input: 9
    /// Output: "IX"
    ///
    /// Example 4:
    ///
    /// Input: 58
    /// Output: "LVIII"
    /// Explanation: L = 50, V = 5, III = 3.
    ///
    /// Example 5:
    ///
    /// Input: 1994
    /// Output: "MCMXCIV"
    /// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
    /// </summary>
    string intToRoman(int num);

    /// <summary>
    /// Leet code 13. Roman to Integer
    /// Given a roman numeral, convert it to an integer.
    /// Input is guaranteed to be within the range from 1 to 3999.
    /// </summary>
    int romanToInt(string s);     

    /// <summary>
    /// Leet code #231. Power of Two    
    /// Given an integer, write a function to determine if it is a power of two. 
    /// </summary>
    bool isPowerOfTwo(int n);

    /// <summary>
    /// Leet code #171. Excel Sheet Column Number 
    /// Related to question Excel Sheet Column Title
    /// Given a column title as appear in an Excel sheet, return its corresponding column number.
    /// For example:
    /// A -> 1
    /// B -> 2
    /// C -> 3
    /// ...
    /// Z -> 26
    /// AA -> 27
    /// AB -> 28 
    /// </summary>
    int titleToNumber(string s);

    /// <summary>
    /// Leet code #168. Excel Sheet Column Title 
    /// Related to question Excel Sheet Column Title
    /// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
    /// For example:
    /// 1 -> A
    /// 2 -> B
    /// 3 -> C
    /// ...
    /// 26 -> Z
    /// 27 -> AA
    /// 28 -> AB 
    ///</summary>
    string convertToTitle(int n);

    /// <summary>
    /// Leet code #263. Ugly Number
    /// Write a program to check whether a given number is an ugly number. 
    /// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly 
    /// while 14 is not ugly since it includes another prime factor 7. 
    /// Note that 1 is typically treated as an ugly number. 
    /// </summary>
    bool isUgly(int num);


    /// <summary>
    /// Leet code #60. Permutation Sequence
    /// The set [1,2,3,?n] contains a total of n! unique permutations.
    /// By listing and labeling all of the permutations in order,
    /// We get the following sequence (ie, for n = 3): 
    /// 1."123"
    /// 2."132"
    /// 3."213"
    /// 4."231"
    /// 5."312"
    /// 6."321"
    /// Given n and k, return the kth permutation sequence.
    /// Note: Given n will be between 1 and 9 inclusive.
    /// </summary>
    string getPermutation(int n, int k);


    /// <summary>
    /// Leet code #31. Next Permutation
    /// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 
    /// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). 
    /// The replacement must be in-place, do not allocate extra memory. 
    /// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
    /// 1,2,3 -> 1,3,2
    /// 3,2,1 -> 1,2,3
    /// 1,1,5 -> 1,5,1 
    /// </summary>
    void nextPermutation(vector<int>& nums);

    /// <summary>
    /// Leet code #233. Number of Digit One 
    /// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
    /// For example: 
    /// Given n = 13,
    /// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13. 
    /// Hint: 
    /// 1.Beware of overflow.
    /// </summary>
    int countDigitOne(int n);

    /// <summary>
    /// Leet code #357. Count Numbers with Unique Digits 
    /// Given a non-negative integer n, count all numbers with unique digits, x, where 0 <= x < 10^n.
    /// Example: 
    /// Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99]) 
    /// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13. 
    /// Hint:
    /// 1.A direct way is to use the backtracking approach.
    /// 2.Backtracking should contains three states which are (the current number, number of steps to get that number and a bitmask which represent 
    /// which number is marked as visited so far in the current number). Start with state (0,0,0) and count all valid number till we reach number of steps equals to 10n.
    /// 3.This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
    /// 4.Let f(k) = count of numbers with unique digits with length equals k.
    /// 5.f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
    /// </summary>
    int countNumbersWithUniqueDigits(int n);

    /// <summary>
    /// Leet code #400. Nth Digit 
    /// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 
    /// Note: 
    /// n is positive and will fit within the range of a 32-bit signed integer (n < 2^31). 
    /// Example 1: 
    /// Input:
    /// 3
    /// Output:
    /// 3
    /// Example 2:
    /// Input:
    /// 11
    ///	Output:
    /// 0
    /// Explanation:
    /// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
    /// </summary>
    int findNthDigit(int n);

    /// <summary>
    /// Leet code #386. Lexicographical Numbers
    ///
    /// Given an integer n, return 1 - n in lexicographical order. 
    /// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9]. 
    /// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. 
    /// </summary>
    vector<int> lexicalOrder(int n);

    /// <summary>
    /// Leet code #238. Product of Array Except Self    
    /// Given an array of n integers where n > 1, nums, return an array output such 
    /// that output[i] is equal to the product of all the elements of nums except nums[i]. 
    ///
    /// Solve it without division and in O(n). 
    /// For example, given [1,2,3,4], return [24,12,8,6]. 
    /// 
    /// Follow up:
    /// Could you solve it with constant space complexity? 
    /// (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
    /// </summary>
    vector<int> productExceptSelf(vector<int>& nums);

    /// <summary>
    /// Leet code #891. Sum of Subsequence Widths
    /// 
    /// Given an array of integers A, consider all non-empty subsequences of A.
    ///
    /// For any sequence S, let the width of S be the difference between the 
    /// maximum and minimum element of S.
    ///
    /// Return the sum of the widths of all subsequences of A. 
    ///
    /// As the answer may be very large, return the answer modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: [2,1,3]
    /// Output: 6
    /// Explanation:
    /// Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
    /// The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
    /// The sum of these widths is 6.
    ///
    /// Note:
    ///
    /// 1 <= A.length <= 20000
    /// 1 <= A[i] <= 20000
    /// </summary>
    int sumSubseqWidths(vector<int>& A);

    /// <summary>
    /// Leet code #908. Smallest Range I
    /// 
    /// Given an array A of integers, for each integer A[i] we may choose any x 
    /// with -K <= x <= K, and add x to A[i].
    ///
    /// After this process, we have some array B.
    ///
    /// Return the smallest possible difference between the maximum value of B 
    /// and the minimum value of B.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: A = [1], K = 0
    /// Output: 0
    /// Explanation: B = [1]
    /// Example 2:
    ///
    /// Input: A = [0,10], K = 2
    /// Output: 6
    /// Explanation: B = [2,8]
    /// Example 3:
    ///
    /// Input: A = [1,3,6], K = 3
    /// Output: 0
    /// Explanation: B = [3,3,3] or B = [4,4,4]
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 10000
    /// 3. 0 <= K <= 10000
    /// </summary>
    int smallestRangeI(vector<int>& A, int K);


    /// <summary>
    /// Leet code #1067. Digit Count in Range
    /// </summary>
    int digitsCount(int d, int count);

    /// <summary>
    /// Leet code #1067. Digit Count in Range
    /// 
    /// Given an integer d between 0 and 9, and two positive integers low and 
    /// high as lower and upper bounds, respectively. Return the number of 
    /// times that d occurs as a digit in all integers between low and high, 
    /// including the bounds low and high.
    /// 
    /// Example 1:
    /// Input: d = 1, low = 1, high = 13
    /// Output: 6
    /// Explanation: 
    /// The digit d=1 occurs 6 times in 1,10,11,12,13. Note that the digit d=1 
    /// occurs twice in the number 11.
    ///
    /// Example 2:
    ///
    /// Input: d = 3, low = 100, high = 250
    /// Output: 35
    /// Explanation: 
    /// The digit d=3 occurs 35 times in 103,113,123,130,131,...,238,239,243.
    ///
    ///
    /// Note:
    ///
    /// 0 <= d <= 9
    /// 1 <= low <= high <= 2×10^8
    /// </summary>
    int digitsCount(int d, int low, int high);
#pragma endregion

#pragma region Array
    /// <summary>
    /// Leet code #398. Random Pick Index     
    /// Given an array of integers with possible duplicates, randomly output the index of a given target number. 
    /// You can assume that the given target number must exist in the array.  
    /// 
    /// Note:
    /// The array size can be very large. Solution that uses too much extra space will not pass the judge. 
    ///
    /// Example: 
    /// int[] nums = new int[] {1,2,3,3,3};
    /// Solution solution = new Solution(nums);
    /// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
    /// solution.pick(3);
    /// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
    /// solution.pick(1);
    /// </summary>
    int pickRandom(vector<int>&nums, int target); 

    /// <summary>
    /// Leet code #384. Shuffle an Array
    /// Shuffle a set of numbers without duplicates. 
    /// Example: 
    /// Init an array with set 1, 2, and 3.
    /// int[] nums = {1,2,3};
    /// Solution solution = new Solution(nums);
    ///
    /// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned
    /// solution.shuffle();
    ///
    /// Resets the array back to its original configuration [1,2,3].
    /// solution.reset(); 
    /// Returns the random shuffling of array [1,2,3].
    /// solution.shuffle();
    /// </summary>
    vector<int> shuffle(vector<int> nums);

    /// <summary>
    /// Leet code #475. Heaters 
    /// Winter is coming! Your first job during the contest is to design a standard heater with 
    /// fixed warm radius to warm all the houses.
    /// Now, you are given positions of houses and heaters on a horizontal line, find out minimum 
    /// radius of heaters so that all houses could be covered by those heaters.
    ///
    /// So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
    /// Note:
    /// Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
    /// Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
    /// As long as a house is in the heaters' warm radius range, it can be warmed.
    /// All the heaters follow your radius standard and the warm radius will the same.
    /// Example 1:
    /// Input: [1,2,3],[2]
    /// Output: 1
    /// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
    /// Example 2:
    /// Input: [1,2,3,4],[1,4]
    /// Output: 1
    /// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
    /// </summary>
    int findRadius(vector<int>& houses, vector<int>& heaters); 

    /// <summary>
    /// Leet code #422. Valid Word Square    
    /// 
    /// Given a sequence of words, check whether it forms a valid word square. 
    /// A sequence of words forms a valid word square if the kth row and column 
    /// read the exact same string, where 0 ≤ k < max(numRows, numColumns).
    /// Note:
    /// 1.The number of words given is at least 1 and does not exceed 500.
    /// 2.Word length will be at least 1 and does not exceed 500.
    /// 3.Each word contains only lowercase English alphabet a-z.
    /// Example 1: 
    /// Input:
    /// [
    ///  "abcd",
    ///  "bnrt",
    ///  "crmy",
    ///  "dtye"
    /// ]
    /// Output:
    /// true
    /// Explanation:
    /// The first row and first column both read "abcd".
    /// The second row and second column both read "bnrt".
    /// The third row and third column both read "crmy".
    /// The fourth row and fourth column both read "dtye".
    /// Therefore, it is a valid word square.
    ///
    /// Example 2: 
    /// Input:
    /// [
    ///  "abcd",
    ///  "bnrt",
    ///  "crm",
    ///  "dt"
    /// ]
    /// Output:
    /// true
    ///
    /// Explanation:
    /// The first row and first column both read "abcd".
    /// The second row and second column both read "bnrt".
    /// The third row and third column both read "crm".
    /// The fourth row and fourth column both read "dt".
    /// Therefore, it is a valid word square.
    /// Example 3: 
    /// Input:
    /// [
    ///  "ball",
    ///  "area",
    ///  "read",
    ///  "lady"
    /// ]
    ///
    /// Output:
    /// false
    /// Explanation:
    /// The third row reads "read" while the third column reads "lead".
    /// Therefore, it is NOT a valid word square.
    /// </summary>
    bool validWordSquare(vector<string>& words);

    /// <summary>
    /// Leet code #370. Range Addition      
    /// 
    /// Assume you have an array of length n initialized with all 0's and are given k update operations.
    /// Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each 
    /// element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
    /// 
    /// Return the modified array after all k operations were executed.
    /// Example: 
    /// Given:
    /// length = 5,
    /// updates = [
    ///    [1,  3,  2],
    ///    [2,  4,  3],
    ///    [0,  2, -2]
    /// ]
    ///
    /// Output:
    /// [-2, 0, 3, 5, 3]
    /// Explanation: 
    /// Initial state:
    /// [ 0, 0, 0, 0, 0 ]
    /// After applying operation [1, 3, 2]:
    /// [ 0, 2, 2, 2, 0 ]
    /// After applying operation [2, 4, 3]:
    /// [ 0, 2, 5, 5, 3 ]
    /// After applying operation [0, 2, -2]:
    /// [-2, 0, 3, 5, 3 ]
    /// Hint:
    /// 1.Thinking of using advanced data structures? You are thinking it too complicated.
    /// 2.For each update operation, do you really need to update all elements between i and j?
    /// 3.Update only the first and end element is sufficient.
    /// 4.The optimal time complexity is O(k + n) and uses O(1) extra space.
    /// </summary>
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates);

    /// <summary>
    /// Leet code #311. Sparse Matrix Multiplication       
    /// 
    /// Given two sparse matrices A and B, return the result of AB.
    /// You may assume that A's column number is equal to B's row number.
    /// Example:
    /// A = 
    /// [
    ///  [ 1, 0, 0],
    ///  [-1, 0, 3]
    /// ]
    /// B = 
    /// [
    ///  [ 7, 0, 0 ],
    ///  [ 0, 0, 0 ],
    ///  [ 0, 0, 1 ]
    /// ]
    ///
    ///      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
    /// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
    ///                   | 0 0 1 |
    /// </summary>
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B);

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
    int wordsTyping(vector<string>& sentence, int rows, int cols);

    /// <summary>
    /// Leet code #498. Diagonal Traverse  
    /// 
    /// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix 
    /// in diagonal order as shown in the below image. 
    ///
    /// Example:
    ///
    /// Input:
    /// [
    ///   [ 1, 2, 3 ],
    ///   [ 4, 5, 6 ],
    ///   [ 7, 8, 9 ]
    /// ]
    /// Output:  [1,2,4,7,5,3,6,8,9]
    /// Explanation:
    /// Note:
    /// 1.The total number of elements of the given matrix will not exceed 10,000.
    /// </summary>
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code # 531. Lonely Pixel I
    ///
    /// Given a picture consisting of black and white pixels,
    ///	find the number of black lonely pixels.
    ///
    /// The picture is represented by a 2D char array consisting
    /// of 'B' and 'W', which means black and white pixels respectively.
    ///
    /// A black lonely pixel is character 'B' that located at a specific 
    /// position where the same row and same column don't have any 
    /// other black pixels.
    ///
    /// Example:
    /// Input: 
    /// [
    ///   ['W', 'W', 'B'],
    ///   ['W', 'B', 'W'],
    ///   ['B', 'W', 'W']
    /// ]
    ///
    /// Output: 3
    /// Explanation: All the three 'B's are black lonely pixels.
    /// Note:
    /// The range of width and height of the input 2D array is [1,500].
    /// </summary>
    int findLonelyPixel(vector<vector<char>>& picture);

    /// <summary>
    /// Leet code # 533. Lonely Pixel II
    ///
    /// Given a picture consisting of black and white pixels, and a positive 
    /// integer N, find the number of black pixels located at some specific 
    /// row R and column C that align with all the following rules:
    ///
    /// Row R and column C both contain exactly N black pixels.
    /// For all rows that have a black pixel at column C, they should be 
    /// exactly the same as row R
    ///
    /// The picture is represented by a 2D char array consisting of 'B' and 'W', 
    /// which means black and white pixels respectively.
    ///
    /// Example:
    /// Input:                                            
    /// [
    ///   ['W', 'B', 'W', 'B', 'B', 'W'],    
    ///   ['W', 'B', 'W', 'B', 'B', 'W'],    
    ///   ['W', 'B', 'W', 'B', 'B', 'W'],    
    ///   ['W', 'W', 'B', 'W', 'B', 'W']
    /// ] 
    ///
    /// N = 3
    /// Output: 6
    /// Explanation: All the bold 'B' are the black pixels we need 
    /// (all 'B's at column 1 and 3).
    ///        0    1    2    3    4    5         column index                                            
    /// 0    [['W', 'B', 'W', 'B', 'B', 'W'],    
    /// 1     ['W', 'B', 'W', 'B', 'B', 'W'],    
    /// 2     ['W', 'B', 'W', 'B', 'B', 'W'],    
    /// 3     ['W', 'W', 'B', 'W', 'B', 'W']]    
    /// row index
    ///
    /// Take 'B' at row R = 0 and column C = 1 as an example:
    /// Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
    /// Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and 
    /// row 2. They are exactly the same as row R = 0.
    ///
    /// Note:
    /// The range of width and height of the input 2D array is [1,200].	
    /// </summary>
    int findLonelyPixel(vector<vector<char>>& picture, int N);

    /// <summary>
    /// Leet code #539. Minimum Time Difference
    ///
    /// Given a list of 24-hour clock time points in "Hour:Minutes" format, 
    /// find the minimum minutes difference between any two time points in 
    /// the list.
    /// 
    /// Example 1:
    /// Input: ["23:59","00:00"]
    /// Output: 1
    /// Note:
    /// The number of time points in the given list is at least 2 and won't exceed 20000.
    /// The input time is legal and ranges from 00:00 to 23:59.
    /// </summary>
    int findMinDifference(vector<string>& timePoints);

    /// <summary>
    /// Leet code # 466. Count The Repetitions 
    ///
    /// Define S = [s,n] as the string S which consists of n 
    /// connected strings s. For example, ["abc", 3] ="abcabcabc". 
    /// On the other hand, we define that string s1 can be obtained from string s2 
    /// if we can remove some characters from s2 such that it becomes s1. For example, 
    /// “abc” can be obtained from “abdbec” based on our definition, but it 
    /// can not be obtained from “acbbe”.
    /// You are given two non-empty strings s1 and s2 (each at most 100 characters long) 
    /// and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, 
    /// where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that 
    /// [S2,M] can be obtained from S1.
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
    /// Leet code # 363. Max Sum of Rectangle No Larger Than K  
    ///
    /// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a 
    /// rectangle in the matrix such that its sum is no larger than k.
    /// 
    /// Example:
    /// Given matrix = 
    /// [
    ///  [1,  0, 1],
    ///  [0, -2, 3]
    /// ]
    /// k = 2
    /// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
    /// Note:
    /// 1.The rectangle inside the matrix must have an area > 0.
    /// 2.What if the number of rows is much larger than the number of columns?
    /// </summary>
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k);

    /// <summary>
    /// Leet code # 363. Max Sum of Rectangle No Larger Than K  
    ///
    /// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a 
    /// rectangle in the matrix such that its sum is no larger than k.
    /// 
    /// Example:
    /// Given matrix = 
    /// [
    ///  [1,  0, 1],
    ///  [0, -2, 3]
    /// ]
    /// k = 2
    /// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
    /// Note:
    /// 1.The rectangle inside the matrix must have an area > 0.
    /// 2.What if the number of rows is much larger than the number of columns?
    /// </summary>
    int maxSumSubmatrixII(vector<vector<int>>& matrix, int k);

    /// <summary>
    /// Leet code #548. Split Array with Equal Sum       
    /// 
    /// Given an array with n integers, you need to find if there are 
    /// triplets (i, j, k) which satisfies following conditions:
    /// 0 < i, i + 1 < j, j + 1 < k < n - 1
    /// Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) 
    /// and (k + 1, n - 1) should be equal.
    /// where we define that subarray (L, R) represents a slice of the 
    /// original array starting from the element indexed L to the element 
    /// indexed R.
    /// Example:
    /// Input: [1,2,1,2,1,2,1]
    /// Output: True
    /// Explanation:
    /// i = 1, j = 3, k = 5. 
    /// sum(0, i - 1) = sum(0, 0) = 1
    /// sum(i + 1, j - 1) = sum(2, 2) = 1
    /// sum(j + 1, k - 1) = sum(4, 4) = 1
    /// sum(k + 1, n - 1) = sum(6, 6) = 1
    /// Note:
    /// 1 <= n <= 2000.
    /// Elements in the given array will be in range [-1,000,000, 1,000,000].
    /// </summary>
    bool splitArray(vector<int>& nums);

    /// <summary>
    /// Leet code #566. Reshape the Matrix       
    /// 
    /// In MATLAB, there is a very useful function called 'reshape', which 
    /// can reshape a matrix into a new one with different size but keep its 
    /// original data. 
    /// You're given a matrix represented by a two-dimensional array, and two 
    /// positive integers r and c representing the row number and column number 
    /// of the wanted reshaped matrix, respectively.
    /// The reshaped matrix need to be filled with all the elements of the 
    /// original matrix in the same row-traversing order as they were. 
    /// If the 'reshape' operation with given parameters is possible and legal, 
    /// output the new reshaped matrix; Otherwise, output the original matrix. 
    /// Example 1:
    /// Input: 
    /// nums = 
    /// [[1,2],
    /// [3,4]]
    /// r = 1, c = 4
    /// Output: 
    /// [[1,2,3,4]]
    /// Explanation:
    /// The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 
    /// 1 * 4 matrix, fill it row by row by using the previous list.
    ///
    /// Example 2:
    /// Input: 
    /// nums = 
    /// [[1,2],
    /// [3,4]]
    /// r = 2, c = 4
    /// Output: 
    /// [[1,2],
    /// [3,4]]
    /// Explanation:
    /// There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output 
    /// the original matrix.
    /// </summary>
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c);

    /// <summary>
    /// Leet code #575. Distribute Candies       
    /// 
    /// Given an integer array with even length, where different numbers in 
    /// this array represent different kinds of candies. Each number means one
    /// candy of the corresponding kind. You need to distribute these candies 
    /// equally in number to brother and sister. Return the maximum number of 
    /// kinds of candies the sister could gain. 
    /// 
    /// Example 1:
    /// Input: candies = [1,1,2,2,3,3]
    /// Output: 3
    /// Explanation:
    /// There are three different kinds of candies (1, 2 and 3), and two 
    /// candies for each kind.
    /// Optimal distribution: The sister has candies [1,2,3] and the brother 
    /// has candies [1,2,3], too. 
    /// The sister has three different kinds of candies. 
    /// Example 2:
    /// Input: candies = [1,1,2,3]
    /// Output: 2
    /// Explanation: For example, the sister has candies [2,3] and the brother 
    /// has candies [1,1]. 
    /// The sister has two different kinds of candies, the brother has only one
    /// kind of candies. 
    /// Note: 
    /// The length of the given array is in range [2, 10,000], and will be even.
    /// The number in given array is in range [-100,000, 100,000].
    /// </summary>
    int distributeCandies(vector<int>& candies);

    /// <summary>
    /// Leet code #565. Array Nesting   
    /// 
    /// A zero-indexed array A consisting of N different integers is given. 
    /// The array contains all integers in the range [0, N - 1]. 
    /// Sets S[K] for 0 <= K < N are defined as follows:
    /// S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.
    /// Sets S[K] are finite for each K and should NOT contain duplicates.
    /// Write a function that given an array A consisting of N integers, 
    /// return the size of the largest set S[K] for this array.
    /// Example 1:
    /// Input: A = [5,4,0,3,1,6,2]
    /// Output: 4
    /// Explanation: 
    /// A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
    ///
    /// One of the longest S[K]:
    /// S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
    /// 
    /// Note:
    /// N is an integer within the range [1, 20,000].
    /// The elements of A are all distinct.
    /// Each element of array A is an integer within the range [0, N-1].
    /// </summary>
    int arrayNesting(vector<int>& nums);

    /// <summary>
    /// Leet code #565-II. Array Nesting   
    /// 
    /// A zero-indexed array A consisting of N integers is given. 
    /// The array contains some integers in the range [0, N - 1]. 
    /// Sets S[K] for 0 <= K < N are defined as follows:
    /// S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.
    /// Sets S[K] are finite for each K and should NOT contain duplicates.
    /// Write a function that given an array A consisting of N integers, 
    /// return the size of the largest set S[K] for this array.
    /// Example 1:
    /// Input: A = [5,4,0,3,1,6,2]
    /// Output: 4
    /// Explanation: 
    /// A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
    ///
    /// One of the longest S[K]:
    /// S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
    /// 
    /// Note:
    /// N is an integer within the range [1, 20,000].
    /// The elements of A are all distinct.
    /// Each element of array A is an integer within the range [0, N-1].
    /// </summary>
    int arrayNestingII(vector<int>& nums);

    /// <summary>
    /// Leet code #605. Can Place Flowers    
    /// 
    /// Suppose you have a long flowerbed in which some of the plots are 
    /// planted and some are not. However, flowers cannot be planted in 
    /// adjacent plots - they would compete for water and both would die.
    /// Given a flowerbed (represented as an array containing 0 and 1, 
    /// where 0 means empty and 1 means not empty), and a number n, return
    /// if n new flowers can be planted in it without violating the 
    /// no-adjacent-flowers rule.
    /// Example 1:
    /// Input: flowerbed = [1,0,0,0,1], n = 1
    /// Output: True
    ///
    /// Example 2:
    /// Input: flowerbed = [1,0,0,0,1], n = 2
    /// Output: False
    /// 
    /// Note:
    /// 1. The input array won't violate no-adjacent-flowers rule.
    /// 2. The input array size is in the range of [1, 20000].
    /// 3. n is a non-negative integer which won't exceed the input array size.
    /// </summary>
    bool canPlaceFlowers(vector<int>& flowerbed, int n);

    /// <summary>
    /// Leet code #624. Maximum Distance in Arrays
    /// 
    /// Given m arrays, and each array is sorted in ascending order. Now you 
    /// can pick up two integers from two different arrays (each array picks 
    /// one) and calculate the distance. We define the distance between two 
    /// integers a and b to be their absolute difference |a-b|. Your task 
    /// is to find the maximum distance. 
    /// Example 1:
    /// Input: 
    /// [
    ///   [1,2,3],
    ///   [4,5],
    ///   [1,2,3]
    /// ]
    /// Output: 4
    /// Explanation: 
    /// One way to reach the maximum distance 4 is to pick 1 in the first or 
    /// third array and pick 5 in the second array.
    /// Note:
    /// 1.Each given array will have at least 1 number. There will be at least 
    ///   two non-empty arrays.
    /// 2.The total number of the integers in all the m arrays will be in the 
    ///   range of [2, 10000].
    /// 3.The integers in the m arrays will be in the range of [-10000, 10000].
    /// </summary>
    int maxDistance(vector<vector<int>>& arrays);

    /// <summary>
    /// Leet code #643. Maximum Average Subarray I
    /// 
    /// Given an array consisting of n integers, find the contiguous subarray 
    /// of given length k that has the maximum average value. And you need to 
    /// output the maximum average value. 
    ///
    /// Example 1:
    /// Input: [1,12,-5,-6,50,3], k = 4
    /// Output: 12.75
    /// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
    /// Note:
    /// 1 <= k <= n <= 30,000.
    /// Elements of the given array will be in the range [-10,000, 10,000].
    /// </summary>
    double findMaxAverage(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #644. Maximum Average Subarray II
    /// </summary>
    double density(vector<double>& sum, int l, int r);

    /// <summary>
    /// Leet code #644. Maximum Average Subarray II
    /// 
    /// Given an array consisting of n integers, find the contiguous subarray 
    /// whose length is greater than or equal to k that has the maximum average 
    /// value. And you need to output the maximum average value. 
    ///
    /// Example 1:
    /// Input: [1,12,-5,-6,50,3], k = 4
    /// Output: 12.75
    /// Explanation:
    /// when length is 5, maximum average value is 10.8,
    /// when length is 6, maximum average value is 9.16667.
    /// Thus return 12.75.
    ///
    /// Note:
    /// 1 <= k <= n <= 10,000.
    /// Elements of the given array will be in range [-10,000, 10,000].
    /// The answer with the calculation error less than 10^-5 will be accepted.
    /// </summary>
    double findMaxAverageII(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #645. Set Mismatch
    /// 
    /// The set S originally contains numbers from 1 to n. But unfortunately, 
    /// due to the data error, one of the numbers in the set got duplicated 
    /// to another number in the set, which results in repetition of one number
    /// and loss of another number. 
    /// Given an array nums representing the data status of this set after the 
    /// error. Your task is to firstly find the number occurs twice and then 
    /// find the number that is missing. Return them in the form of an array. 
    ///
    /// Example 1:
    /// Input: nums = [1,2,2,4]
    /// Output: [2,3]
    /// Note:
    /// The given array size will in the range [2, 10000].
    /// The given array's numbers won't have any order.
    /// </summary>
    vector<int> findErrorNums(vector<int>& nums);

    /// <summary>
    /// Leet code #649. Dota2 Senate
    /// 
    /// In the world of Dota2, there are two parties: the Radiant and the Dire. 
    /// The Dota2 senate consists of senators coming from two parties. Now the 
    /// senate wants to make a decision about a change in the Dota2 game. The 
    /// voting for this change is a round-based procedure. In each round, each 
    /// senator can exercise one of the two rights: 
    /// 1. Ban one senator's right: 
    ///    A senator can make another senator lose all his rights in this and 
    ///    all the following rounds.
    /// 2. Announce the victory: 
    ///    If this senator found the senators who still have rights to vote are 
    ///    all from the same party, he can announce the victory and make the 
    ///    decision about the change in the game.
    ///
    /// Given a string representing each senator's party belonging. The 
    /// character 'R' and 'D' represent the Radiant party and the Dire party 
    /// respectively. Then if there are n senators, the size of the given 
    /// string will be n. 
    /// The round-based procedure starts from the first senator to the last 
    /// senator in the given order. This procedure will last until the end of 
    /// voting. All the senators who have lost their rights will be skipped 
    /// during the procedure. 
    /// Suppose every senator is smart enough and will play the best strategy 
    /// for his own party, you need to predict which party will finally 
    /// announce the victory and make the change in the Dota2 game. The output 
    /// should be Radiant or Dire. 
    /// Example 1:
    /// Input: "RD"
    /// Output: "Radiant"
    /// Explanation: The first senator comes from Radiant and he can just ban 
    /// the next senator's right in the round 1. 
    /// And the second senator can't exercise any rights any more since his 
    /// right has been banned. 
    /// And in the round 2, the first senator can just announce the victory 
    /// since he is the only guy in the senate who can vote.
    ///
    /// Example 2:
    /// Input: "RDD"
    /// Output: "Dire"
    /// Explanation: 
    /// The first senator comes from Radiant and he can just ban the next 
    /// senator's right in the round 1. 
    /// And the second senator can't exercise any rights anymore since his 
    /// right has been banned. 
    /// And the third senator comes from Dire and he can ban the first 
    /// senator's right in the round 1. 
    /// And in the round 2, the third senator can just announce the victory 
    /// since he is the only guy in the senate who can vote.
    ///
    /// Note:
    /// The length of the given string will in the range [1, 10,000].
    /// </summary>
    string predictPartyVictory(string senate);

    /// <summary>
    /// Leet code #661. Image Smoother 
    /// 
    /// Given a 2D integer matrix M representing the gray scale of an image, 
    /// you need to design a smoother to make the gray scale of each cell 
    /// becomes the average gray scale (rounding down) of all the 8 
    /// surrounding cells and itself. If a cell has less than 8 surrounding 
    /// cells, then use as many as you can.
    /// Example 1:
    /// Input:
    /// [
    ///   [1,1,1],
    ///   [1,0,1],
    ///   [1,1,1]
    /// ]
    /// Output:
    /// [
    ///   [0, 0, 0],
    ///   [0, 0, 0],
    ///   [0, 0, 0]
    /// ]
    /// Explanation:
    /// For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
    /// For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = 
    /// floor(0.83333333) = 0
    /// For the point (1,1): floor(8/9) = floor(0.88888889) = 0
    ///
    /// Note:
    /// The value in the given matrix is in the range of [0, 255].
    /// The length and width of the given matrix are in the range of [1, 150].
    /// </summary>
    vector<vector<int>> imageSmoother(vector<vector<int>>& M);

    /// <summary>
    /// Leet code #667. Beautiful Arrangement II 
    /// 
    /// Given two integers n and k, you need to construct a list which 
    /// contains n different positive integers ranging from 1 to n and 
    /// obeys the following requirement: 
    /// Suppose this list is [a1, a2, a3, ... , an], then the list 
    /// [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly 
    /// k distinct integers.
    ///
    /// If there are multiple answers, print any of them.
    ///
    /// Example 1:
    /// Input: n = 3, k = 1
    /// Output: [1, 2, 3]
    /// Explanation: The [1, 2, 3] has three different positive integers 
    /// ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
    /// 
    /// Example 2:
    /// Input: n = 3, k = 2
    /// Output: [1, 3, 2]
    /// Explanation: The [1, 3, 2] has three different positive integers 
    /// ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 
    /// and 2.
    /// Note:
    /// 1. The n and k are in the range 1 <= k < n <= 104.
    /// </summary>
    vector<int> constructArray(int n, int k);

    /// <summary>
    /// Leet code #670. Maximum Swap 
    /// 
    /// Given a non-negative integer, you could swap two digits at most once 
    /// to get the maximum valued number. Return the maximum valued number 
    /// you could get.
    ///
    /// Example 1:
    /// Input: 2736
    /// Output: 7236
    /// Explanation: Swap the number 2 and the number 7.
    /// Example 2:
    /// Input: 9973
    /// Output: 9973
    /// Explanation: No swap.
    /// Note:
    /// The given number is in the range [0, 10^8]
    /// </summary>
    int maximumSwap(int num);

    /// <summary>
    /// Leet code #674. Longest Continuous Increasing Subsequence 
    /// 
    /// Given an unsorted array of integers, find the length of longest 
    /// continuous increasing subsequence.
    ///
    /// Example 1:
    /// Input: [1,3,5,4,7]
    /// Output: 3
    /// Explanation: The longest continuous increasing subsequence is [1,3,5], 
    /// its length is 3. 
    /// Even though [1,3,5,7] is also an increasing subsequence, it's not a 
    /// continuous one where 5 and 7 are separated by 4. 
    ///
    /// Example 2:
    /// Input: [2,2,2,2,2]
    /// Output: 1
    /// Explanation: The longest continuous increasing subsequence is [2], 
    /// its length is 1.
    ///	
    /// Note: Length of the array will not exceed 10,000.
    /// </summary>
    int findLengthOfLCIS(vector<int>& nums);

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
    /// Leet code #659. Split Array into Consecutive Subsequences 
    /// 
    /// You are given an integer array sorted in ascending order (may contain 
    /// duplicates), you need to split them into several subsequences, where 
    /// each subsequences consist of at least 3 consecutive integers. 
    /// Return whether you can make such a split.
    ///
    /// Example 1:
    /// Input: [1,2,3,3,4,5]
    /// Output: True
    /// Explanation:
    /// You can split them into two consecutive subsequences : 
    /// 1, 2, 3
    /// 3, 4, 5
    ///
    /// Example 2:
    /// Input: [1,2,3,3,4,4,5,5]
    /// Output: True
    /// Explanation:
    /// You can split them into two consecutive subsequences : 
    /// 1, 2, 3, 4, 5
    /// 3, 4, 5
    /// 
    /// Example 3:
    /// Input: [1,2,3,4,4,5]
    /// Output: False
    ///
    /// Note:
    /// 1. The length of the input is in range of [1, 10000]
    /// </summary>
    bool isPossible(vector<int>& nums); 

    /// <summary>
    /// Leet code #682. Baseball Game
    /// 
    /// Given a list of strings, each string can be one of the 4 following 
    /// types:
    ///
    /// Integer (one round's score): Directly represents the number of points 
    /// you get in this round.
    /// "+" (one round's score): Represents that the points you get in this 
    ///  round are the sum of the last two valid round's points.
    /// "D" (one round's score): Represents that the points you get in this 
    /// round are the doubled data of the last valid round's points.
    /// "C" (an operation, which isn't a round's score): Represents the last 
    /// valid round's points you get were invalid and should be removed.
    /// Each round's operation is permanent and could have an impact on the 
    /// round before and the round after.
    ///
    /// You need to return the sum of the points you could get in all the 
    /// rounds.
    ///
    /// Example 1:
    /// Input: ["5","2","C","D","+"]
    /// Output: 30
    /// Explanation: 
    /// Round 1: You could get 5 points. The sum is: 5.
    /// Round 2: You could get 2 points. The sum is: 7.
    /// Operation 1: The round 2's data was invalid. The sum is: 5.  
    /// Round 3: You could get 10 points (the round 2's data has been 
    /// removed). The sum is: 15.
    /// Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
    /// Example 2:
    /// Input: ["5","-2","4","C","D","9","+","+"]
    /// Output: 27
    /// Explanation: 
    /// Round 1: You could get 5 points. The sum is: 5.
    /// Round 2: You could get -2 points. The sum is: 3.
    /// Round 3: You could get 4 points. The sum is: 7.
    /// Operation 1: The round 3's data is invalid. The sum is: 3.  
    /// Round 4: You could get -4 points (the round 3's data has been removed). 
    /// The sum is: -1.
    /// Round 5: You could get 9 points. The sum is: 8.
    /// Round 6: You could get -4 + 9 = 5 points. The sum is 13.
    /// Round 7: You could get 9 + 5 = 14 points. The sum is 27.
    /// Note:
    /// 1.The size of the input list will be between 1 and 1000.
    /// 2.Every integer represented in the list will be between -30000 
    ///   and 30000.
    /// </summary>
    int calPoints(vector<string>& ops);

    /// <summary>
    /// Leet code #696. Count Binary Substrings
    ///
    /// Give a string s, count the number of non-empty (contiguous) substrings 
    /// that have the same number of 0's and 1's, and all the 0's and all the 
    /// 1's in these substrings are grouped consecutively.
    ///
    /// Substrings that occur multiple times are counted the number of times 
    /// they occur.
    ///
    /// Example 1:
    /// Input: "00110011"
    /// Output: 6
    /// Explanation: There are 6 substrings that have equal number of 
    /// consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
    ///
    /// Notice that some of these substrings repeat and are counted the number 
    /// of times they occur.
    /// 
    /// Also, "00110011" is not a valid substring because all the 0's 
    /// (and 1's) are not grouped together.
    /// Example 2:
    /// Input: "10101"
    /// Output: 4
    /// Explanation: There are 4 substrings: "10", "01", "10", "01" that have 
    /// equal number of consecutive 1's and 0's.
    /// Note:
    ///
    /// s.length will be between 1 and 50,000.
    /// s will only consist of "0" or "1" characters.
    /// </summary>
    int countBinarySubstrings(string s);

    /// <summary>
    /// Leet code #697. Degree of an Array
    ///
    /// Given a non-empty array of non-negative integers nums, the degree of 
    /// this array is defined as the maximum frequency of any one of its 
    /// elements.
    /// 
    /// Your task is to find the smallest possible length of a (contiguous) 
    /// subarray of nums, that has the same degree as nums.
    ///
    /// Example 1:
    /// Input: [1, 2, 2, 3, 1]
    /// Output: 2
    /// Explanation: 
    /// The input array has a degree of 2 because both elements 1 and 2 appear 
    /// twice.
    /// Of the subarrays that have the same degree:
    /// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
    /// The shortest length is 2. So return 2.
    ///
    /// Example 2:
    /// Input: [1,2,2,3,1,4,2]
    /// Output: 6
    /// Note:
    /// 
    /// nums.length will be between 1 and 50,000.
    /// nums[i] will be an integer between 0 and 49,999.
    /// </summary>
    int findShortestSubArray(vector<int>& nums);
    
    /// <summary>
    /// Leet code #717. 1-bit and 2-bit Characters
    ///
    /// We have two special characters. The first character can be 
    /// represented by one bit 0. The second character can be represented 
    /// by two bits (10 or 11).
    ///
    /// Now given a string represented by several bits. Return whether the 
    /// last character must be a one-bit character or not. The given string 
    /// will always end with a zero.
    ///
    /// Example 1:
    /// Input: 
    /// bits = [1, 0, 0]
    /// Output: True
    /// Explanation: 
    /// The only way to decode it is two-bit character and one-bit character. 
    /// So the last character is one-bit character.
    ///
    /// Example 2:
    /// Input: 
    /// bits = [1, 1, 1, 0]
    /// Output: False
    /// Explanation:  
    /// The only way to decode it is two-bit character and two-bit character. 
    /// So the last character is NOT one-bit character.
    /// Note:
    ///
    /// 1 <= len(bits) <= 1000.
    /// bits[i] is always 0 or 1.
    /// </summary>
    bool isOneBitCharacter(vector<int>& bits);

    /// <summary>
    /// Leet code #723. Candy Crush
    /// Count candy
    /// </summary>
    void countCandy(vector<vector<int>>& board, vector<vector<pair<int, int>>>& match);

    /// <summary>
    /// Leet code #723. Candy Crush
    /// Remove candy
    /// </summary>
    bool removeCandy(vector<vector<int>>& board, vector<vector<pair<int, int>>>& match);

    /// <summary>
    /// Leet code #723. Candy Crush
    /// Drop candy
    /// </summary>
    void dropCandy(vector<vector<int>>& board);

    /// <summary>
    /// Leet code #723. Candy Crush
    ///
    /// This question is about implementing a basic elimination algorithm for 
    /// Candy Crush. 
    /// 
    /// Given a 2D integer array board representing the grid of candy, 
    /// different positive integers board[i][j] represent different types of 
    /// candies. A value of board[i][j] = 0 represents that the cell at 
    /// position (i, j) is empty. The given board represents the state of the 
    /// game following the player's move. Now, you need to restore the board 
    /// to a stable state by crushing candies according to the following rules:
    ///
    /// 1. If three or more candies of the same type are adjacent vertically or 
    /// horizontally, "crush" them all at the same time - these positions 
    /// become empty.
    /// 2. After crushing all candies simultaneously, if an empty space on the 
    /// board has candies on top of itself, then these candies will drop until 
    /// they hit a candy or bottom at the same time. (No new candies will drop 
    /// outside the top boundary.)
    /// 3. After the above steps, there may exist more candies that can be 
    /// crushed. If so, you need to repeat the above steps.
    /// 4. If there does not exist more candies that can be crushed (ie. the board 
    /// is stable), then return the current board.
    /// 
    /// You need to perform the above rules until the board becomes stable, 
    /// then return the current board.
    ///
    /// Example 1:
    /// Input:
    /// board = 
    /// [[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],
    /// [410,411,412,5,414], [5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714], 
    /// [810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
    /// Output:
    /// [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],
    /// [310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],
    /// [710,311,412,613,714],[810,411,512,713,1014]]
    /// Explanation: 
    ///
    /// Note:
    /// 1. The length of board will be in the range [3, 50].
    /// 2. The length of board[i] will be in the range [3, 50].
    /// Each board[i][j] will initially start as an integer in the range 
    /// [1, 2000].
    /// </summary>
    vector<vector<int>> candyCrush(vector<vector<int>>& board);

    /// <summary>
    /// Leet code #724. Find Pivot Index
    ///
    /// Given an array of integers nums, write a method that returns the 
    /// "pivot" index of this array.
    ///
    /// We define the pivot index as the index where the sum of the numbers 
    /// to the left of the index is equal to the sum of the numbers to the 
    /// right of the index.
    ///
    /// If no such index exists, we should return -1. If there are multiple 
    /// pivot indexes, you should return the left-most pivot index.
    ///
    /// Example 1:
    /// Input: 
    /// nums = [1, 7, 3, 6, 5, 6]
    /// Output: 3
    /// Explanation: 
    /// The sum of the numbers to the left of index 3 (nums[3] = 6) is equal 
    /// to the sum of numbers to the right of index 3.
    /// Also, 3 is the first index where this occurs.
    ///
    /// Example 2:
    /// Input: 
    /// nums = [1, 2, 3]
    /// Output: -1
    /// Explanation: 
    /// There is no index that satisfies the conditions in the problem 
    /// statement.
    /// Note:
    ///
    /// 1. The length of nums will be in the range [0, 10000].
    /// 2. Each element nums[i] will be an integer in the range [-1000, 1000].
    /// </summary>
    int pivotIndex(vector<int>& nums);

    /// <summary>
    /// Leet code #750. Number Of Corner Rectangles
    ///
    /// Given a grid where each entry is only 0 or 1, find the number of corner
    /// rectangles.
    /// A corner rectangle is 4 distinct 1s on the grid that form an 
    /// axis-aligned rectangle. Note that only the corners need to have the 
    /// value 1. Also, all four 1s used must be distinct.
    ///
    /// Example 1:
    /// Input: grid = 
    /// [[1, 0, 0, 1, 0],
    ///  [0, 0, 1, 0, 1],
    ///  [0, 0, 0, 1, 0],
    ///  [1, 0, 1, 0, 1]]
    /// Output: 1
    /// Explanation: There is only one corner rectangle, with corners 
    /// grid[1][2], grid[1][4], grid[3][2], grid[3][4].
    /// Example 2:
    /// Input: grid = 
    /// [[1, 1, 1],
    ///  [1, 1, 1],
    /// [1, 1, 1]]
    /// Output: 9
    /// Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 
    /// rectangles, and one 3x3 rectangle.
    /// Example 3:
    /// Input: grid = 
    /// [[1, 1, 1, 1]]
    /// Output: 0
    /// Explanation: Rectangles must have four distinct corners.
    /// Note:
    /// 1. The number of rows and columns of grid will each be in the range 
    ///    [1, 200].
    /// 2. Each grid[i][j] will be either 0 or 1.
    /// 3. The number of 1s in the grid will be at most 6000.
    /// </summary>
    int countCornerRectangles(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #747. Largest Number Greater Than Twice of Others
    ///
    /// In a given integer array nums, there is always exactly one largest 
    /// element.
    ///
    /// Find whether the largest element in the array is at least twice as 
    /// much as every other number in the array.
    ///
    /// If it is, return the index of the largest element, otherwise return -1.
    ///
    /// Example 1:
    /// Input: nums = [3, 6, 1, 0]
    /// Output: 1
    /// Explanation: 6 is the largest integer, and for every other number in 
    /// the array x,
    /// 6 is more than twice as big as x.  The index of value 6 is 1, so we 
    /// return 1.
    /// Example 2:
    /// Input: nums = [1, 2, 3, 4]
    /// Output: -1
    /// Explanation: 4 isn't at least as big as twice the value of 3, so we 
    /// return -1.
    /// Note:
    /// nums will have a length in the range [1, 50].
    /// Every nums[i] will be an integer in the range [0, 99].
    /// </summary>
    int dominantIndex(vector<int>& nums);

    /// <summary>
    /// Leet code #766. Toeplitz Matrix    
    ///
    /// A matrix is Toeplitz if every diagonal from top-left to bottom-right 
    /// has the same element.
    ///
    /// Now given an M x N matrix, return True if and only if the matrix is 
    /// Toeplitz.
    ///
    ///
    /// Example 1:
    ///
    /// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
    /// Output: True
    /// Explanation:
    /// 1234
    /// 5123
    /// 9512
    ///
    /// In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", 
    /// "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are 
    /// the same, so the answer is True.
    ///
    /// Example 2:
    ///
    /// Input: matrix = [[1,2],[2,2]]
    /// Output: False
    /// Explanation:
    /// The diagonal "[1, 2]" has different elements.
    /// Note:
    ///
    /// matrix will be a 2D array of integers.
    /// matrix will have a number of rows and columns in range [1, 20].
    /// matrix[i][j] will be integers in range [0, 99].
    /// </summary>
    bool isToeplitzMatrix(vector<vector<int>>& matrix);

    /// <summary>
    /// Leetcode #779. K-th Symbol in Grammar
    ///
    /// On the first row, we write a 0. Now in every subsequent row, we look 
    /// at the previous row and replace each occurrence of 0 with 01, and each 
    /// occurrence of 1 with 10.
    ///
    /// Given row N and index K, return the K-th indexed symbol in row N. 
    /// (The values of K are 1-indexed.) (1 indexed).
    ///
    /// Examples:
    /// Input: N = 1, K = 1
    /// Output: 0
    /// 
    /// Input: N = 2, K = 1
    /// Output: 0
    ///
    /// Input: N = 2, K = 2
    /// Output: 1
    ///
    /// Input: N = 4, K = 5 
    /// Output: 1
    /// 
    /// Explanation:
    /// row 1: 0
    /// row 2: 01
    /// row 3: 0110
    /// row 4: 01101001
    /// Note:
    /// 1. N will be an integer in the range [1, 30].
    /// 2. K will be an integer in the range [1, 2^(N-1)].
    /// </summary>
    int kthGrammar(int N, int K);

    /// <summary>
    /// Leet code #807. Max Increase to Keep City Skyline
    /// 
    /// In a 2 dimensional array grid, each value grid[i][j] represents the 
    /// height of a building located there. We are allowed to increase the 
    /// height of any number of buildings, by any amount (the amounts can be 
    /// different for different buildings). Height 0 is considered to be a 
    /// building as well. 
    ///
    /// At the end, the "skyline" when viewed from all four directions of the 
    /// grid, i.e. top, bottom, left, and right, must be the same as the 
    /// skyline of the original grid. A city's skyline is the outer contour 
    /// of the rectangles formed by all the buildings when viewed from a 
    /// distance. See the following example.
    ///
    /// What is the maximum total sum that the height of the buildings can be 
    /// increased?
    /// 
    /// Example:
    /// Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
    /// Output: 35
    /// Explanation: 
    /// The grid is:
    /// [ 
    ///   [3, 0, 8, 4], 
    ///   [2, 4, 5, 7],
    ///   [9, 2, 6, 3],
    ///   [0, 3, 1, 0] 
    /// ]
    ///
    /// The skyline viewed from top or bottom is: [9, 4, 8, 7]
    /// The skyline viewed from left or right is: [8, 7, 9, 3]
    ///
    /// The grid after increasing the height of buildings without affecting 
    /// skylines is:
    /// gridNew = 
    /// [ 
    ///   [8, 4, 8, 7],
    ///   [7, 4, 7, 7],
    ///   [9, 4, 8, 7],
    ///   [3, 3, 3, 3] 
    /// ]
    ///
    /// Notes:
    ///
    /// 1. 1 < grid.length = grid[0].length <= 50.
    /// 2. All heights grid[i][j] are in the range [0, 100].
    /// 3. All buildings in grid[i][j] occupy the entire grid cell: that is, they 
    ///   are a 1 x 1 x grid[i][j] rectangular prism.
    /// </summary>
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #821. Shortest Distance to a Character
    /// 
    /// Given a string S and a character C, return an array of integers   
    /// representing the shortest distance from the character C in the string.
    ///
    /// Example 1: 
    /// 1. Input: S = "loveleetcode", C = 'e'
    /// 2. Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0] 
    /// 3. All letters in S and C are lowercase.
    /// </summary>
    vector<int> shortestToChar(string S, char C);

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
    /// Leet code #822. Card Flipping Game
    /// 
    /// On a table are N cards, with a positive integer printed on the front 
    /// and back of each card (possibly different).
    ///
    /// We flip any number of cards, and after we choose one card. 
    ///
    /// If the number X on the back of the chosen card is not on the front of 
    /// any card, then this number X is good.
    ///
    /// What is the smallest number that is good?  If no number is good, 
    /// output 0.
    ///
    /// Here, fronts[i] and backs[i] represent the number on the front and 
    /// back of card i. 
    ///
    /// A flip swaps the front and back numbers, so the value on the front is 
    /// now on the back and vice versa.
    ///
    /// Example:
    ///
    /// Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
    /// Output: 2
    /// Explanation: If we flip the second card, the fronts are [1,3,4,4,7] 
    /// and the backs are [1,2,4,1,3].
    /// We choose the second card, which has number 2 on the back, and it 
    /// isn't on the front of any card, so 2 is good.
    ///
    /// Note:
    /// 1.1 <= fronts.length == backs.length <= 1000.
    /// 2.1 <= fronts[i] <= 2000.
    /// 3.1 <= backs[i] <= 2000.
    /// </summary>
    int flipgame(vector<int>& fronts, vector<int>& backs);

    /// <summary>
    /// Leet code #825. Friends Of Appropriate Ages
    /// 
    /// Some people will make friend requests. The list of their ages is given 
    /// and ages[i] is the age of the ith person. 
    ///
    /// Person A will NOT friend request person B (B != A) if any of the 
    /// following conditions are true:
    ///
    /// age[B] <= 0.5 * age[A] + 7
    /// age[B] > age[A]
    /// age[B] > 100 && age[A] < 100
    /// Otherwise, A will friend request B.
    ///
    /// Note that if A requests B, B does not necessarily request A.  Also, 
    /// people will not friend request themselves.
    ///
    /// How many total friend requests are made?
    ///
    /// Example 1:
    ///
    /// Input: [16,16]
    /// Output: 2
    /// Explanation: 2 people friend request each other.
    /// Example 2:
    ///
    /// Input: [16,17,18]
    /// Output: 2
    /// Explanation: Friend requests are made 17 -> 16, 18 -> 17.
    ///
    /// Example 3:
    /// Input: [20,30,100,110,120]
    /// Output: 
    /// Explanation: Friend requests are made 110 -> 100, 120 -> 110, 
    /// 120 -> 100.
    ///
    ///
    /// Notes:
    ///
    /// 1. 1 <= ages.length <= 20000.
    /// 2. 1 <= ages[i] <= 120.
    /// </summary>
    int numFriendRequests(vector<int>& ages);

    /// <summary>
    /// Leet code #826. Most Profit Assigning Work
    /// 
    /// We have jobs: difficulty[i] is the difficulty of the ith job, and 
    /// profit[i] is the profit of the ith job. 
    ///
    /// Now we have some workers. worker[i] is the ability of the ith worker, 
    /// which means that this worker can only complete a job with difficulty 
    /// at most worker[i]. 
    /// 
    /// Every worker can be assigned at most one job, but one job can be 
    /// completed multiple times.
    ///
    /// For example, if 3 people attempt the same job that pays $1, then the 
    /// total profit will be $3.  If a worker cannot complete any job, his 
    /// profit is $0.
    ///
    /// What is the most profit we can make?
    ///
    /// Example 1:
    ///
    /// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], 
    /// worker = [4,5,6,7]
    /// Output: 100 
    /// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and 
    /// they get profit of [20,20,30,30] seperately.
    /// Notes:
    ///
    /// 1. 1 <= difficulty.length = profit.length <= 10000
    /// 2. 1 <= worker.length <= 10000
    /// 3. difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
    /// </summary>
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker);

    /// <summary>
    /// Leet code #832. Flipping an Image
    /// 
    /// Given a binary matrix A, we want to flip the image horizontally, then 
    /// invert it, and return the resulting image.
    ///
    /// To flip an image horizontally means that each row of the image is 
    /// reversed.  For example, flipping [1, 1, 0] horizontally results in 
    /// [0, 1, 1].
    ///
    /// To invert an image means that each 0 is replaced by 1, and each 1 is 
    /// replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
    ///
    /// Example 1:
    ///
    /// Input: [[1,1,0],[1,0,1],[0,0,0]]
    /// Output: [[1,0,0],[0,1,0],[1,1,1]]
    /// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
    /// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
    ///
    /// Example 2:
    ///
    /// Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
    /// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
    /// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],
    /// [0,1,0,1]].
    /// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
    /// Notes:
    /// 1. 1 <= A.length = A[0].length <= 20
    /// 2. 0 <= A[i][j] <= 1
    /// </summary>
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A);

    /// <summary>
    /// Leet code #835. Image Overlap
    /// 
    /// Two images A and B are given, represented as binary, square matrices 
    /// of the same size.  (A binary matrix has only 0s and 1s as values.)
    ///
    /// We translate one image however we choose (sliding it left, right, up, 
    /// or down any number of units), and place it on top of the other image.  
    /// After, the overlap of this translation is the number of positions that 
    /// have a 1 in both images.
    ///
    /// (Note also that a translation does not include any kind of rotation.)
    ///
    /// What is the largest possible overlap?
    ///
    /// Example 1:
    ///
    /// Input: A = [[1,1,0],
    ///             [0,1,0],
    ///             [0,1,0]]
    ///        B = [[0,0,0],
    ///             [0,1,1],
    ///             [0,0,1]]
    /// Output: 3
    /// Explanation: We slide A to right by 1 unit and down by 1 unit.
    /// Notes: 
    ///
    /// 1. 1 <= A.length = A[0].length = B.length = B[0].length <= 30
    /// 2. 0 <= A[i][j], B[i][j] <= 1
    /// </summary>
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B);

    /// <summary>
    /// Leet code #838. Push Dominoes
    /// 
    /// There are N dominoes in a line, and we place each domino vertically 
    /// upright.
    /// In the beginning, we simultaneously push some of the dominoes either 
    /// to the left or to the right.
    ///
    /// After each second, each domino that is falling to the left pushes the 
    /// adjacent domino on the left.
    ///
    /// Similarly, the dominoes falling to the right push their adjacent 
    /// dominoes standing on the right.
    ///
    /// When a vertical domino has dominoes falling on it from both sides, it 
    /// stays still due to the balance of the forces.
    ///
    /// For the purposes of this question, we will consider that a falling 
    /// domino expends no additional force to a falling or already fallen 
    /// domino.
    ///
    /// Given a string "S" representing the initial state. S[i] = 'L', if the 
    /// i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino 
    /// has been pushed to the right; S[i] = '.', if the i-th domino has not 
    /// been pushed.
    ///
    /// Return a string representing the final state. 
    /// 
    /// Example 1:
    ///
    /// Input: ".L.R...LR..L.."
    /// Output: "LL.RR.LLRRLL.."
    /// Example 2:
    /// 
    /// Input: "RR.L"
    /// Output: "RR.L"
    /// Explanation: The first domino expends no additional force on the second
    /// domino.
    /// Note:
    /// 
    /// 1. 0 <= N <= 10^5
    /// 2. String dominoes contains only 'L', 'R' and '.'
    /// </summary>
    string pushDominoes(string dominoes);

    /// <summary>
    /// Leet code #840. Magic Squares In Grid
    /// 
    /// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers 
    /// from 1 to 9 such that each row, column, and both diagonals all have 
    /// the same sum.
    ///
    /// Given an grid of integers, how many 3 x 3 "magic square" subgrids are 
    /// there?  (Each subgrid is contiguous).
    ///
    /// Example 1:
    ///
    /// Input: [
    ///         [4,3,8,4],
    ///         [9,5,1,9],
    ///         [2,7,6,2]
    ///        ]
    /// Output: 1
    /// Explanation: 
    /// The following subgrid is a 3 x 3 magic square:
    /// 438
    /// 951
    /// 276
    ///
    /// while this one is not:
    /// 384
    /// 519
    /// 762
    ///
    /// In total, there is only one magic square inside the given grid.
    /// Note:
    ///
    /// 1. 1 <= grid.length <= 10
    /// 2. 1 <= grid[0].length <= 10
    /// 3. 0 <= grid[i][j] <= 15
    /// </summary>
    int numMagicSquaresInside(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #845. Longest Mountain in Array
    /// 
    /// Let's call any (contiguous) subarray B (of A) a mountain if the 
    /// following properties hold:
    ///
    /// B.length >= 3
    /// There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... 
    /// B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
    /// (Note that B could be any subarray of A, including the entire array A.)
    ///
    /// Given an array A of integers, return the length of the longest 
    /// mountain.
    ///  
    /// Return 0 if there is no mountain.
    /// 
    /// Example 1:
    /// Input: [2,1,4,7,3,2,5]
    /// Output: 5
    /// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
    /// 
    /// Example 2:
    /// Input: [2,2,2]
    /// Output: 0
    /// Explanation: There is no mountain.
    ///
    /// Note:
    /// 1. 0 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 10000
    /// </summary>
    int longestMountain(vector<int>& A);

    /// <summary>
    /// Leet code #849. Maximize Distance to Closest Person
    /// 
    /// In a row of seats, 1 represents a person sitting in that seat, and 0 
    /// represents that the seat is empty. 
    /// 
    /// There is at least one empty seat, and at least one person sitting.
    ///
    /// Alex wants to sit in the seat such that the distance between him and the 
    /// closest person to him is maximized. 
    ///
    /// Return that maximum distance to closest person.
    ///
    /// Example 1:
    ///
    /// Input: [1,0,0,0,1,0,1]
    /// Output: 2
    /// Explanation: 
    /// If Alex sits in the second open seat (seats[2]), then the closest person 
    /// has distance 2.
    /// If Alex sits in any other open seat, the closest person has distance 1.
    /// Thus, the maximum distance to the closest person is 2.
    /// Example 2:
    ///
    /// Input: [1,0,0,0]
    /// Output: 3
    /// Explanation: 
    /// If Alex sits in the last seat, the closest person is 3 seats away.
    /// This is the maximum distance possible, so the answer is 3.
    /// Note:
    ///
    /// 1. 1 <= seats.length <= 20000
    /// 2. seats contains only 0s or 1s, at least one 0, and at least one 1.
    /// </summary>
    int maxDistToClosest(vector<int>& seats);

    /// <summary>
    /// Leet code #860. Lemonade Change
    /// 
    /// At a lemonade stand, each lemonade costs $5. 
    ///
    /// Customers are standing in a queue to buy from you, and order one at a time 
    /// (in the order specified by bills).
    ///
    /// Each customer will only buy one lemonade and pay with either a $5, $10, or 
    /// $20 bill.  You must provide the correct change to each customer, so that 
    /// the net transaction is that the customer pays $5.
    ///
    /// Note that you don't have any change in hand at first.
    ///
    /// Return true if and only if you can provide every customer with correct 
    /// change.
    /// 
    /// Example 1:
    /// 
    /// Input: [5,5,5,10,20]
    /// Output: true
    /// Explanation: 
    /// From the first 3 customers, we collect three $5 bills in order.
    /// From the fourth customer, we collect a $10 bill and give back a $5.
    /// From the fifth customer, we give a $10 bill and a $5 bill.
    /// Since all customers got correct change, we output true.
    ///
    /// Example 2: 
    /// Input: [5,5,10]
    /// Output: true
    /// Example 3:
    /// 
    /// Input: [10,10]
    /// Output: false
    /// Example 4:
    ///
    /// Input: [5,5,10,10,20]
    /// Output: false
    /// Explanation: 
    /// From the first two customers in order, we collect two $5 bills.
    /// For the next two customers in order, we collect a $10 bill and give back a 
    /// $5 bill.
    /// For the last customer, we can't give change of $15 back because we only 
    /// have two $10 bills.
    /// Since not every customer received correct change, the answer is false.
    /// 
    /// Note:
    ///
    /// 1. 0 <= bills.length <= 10000
    /// 2. bills[i] will be either 5, 10, or 20.
    /// </summary>
    bool lemonadeChange(vector<int>& bills);

    /// <summary>
    /// Leet code #861. Score After Flipping Matrix
    /// 
    /// We have a two dimensional matrix A where each value is 0 or 1.
    ///
    /// A move consists of choosing any row or column, and toggling each value 
    /// in that row or column: changing all 0s to 1s, and all 1s to 0s.
    ///
    /// After making any number of moves, every row of this matrix is interpreted 
    /// as a binary number, and the score of the matrix is the sum of these 
    /// numbers.
    ///
    /// Return the highest possible score.
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    /// Output: 39
    /// Explanation:
    /// Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
    /// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
    /// 
    /// 
    /// Note:
    ///
    /// 1. 1 <= A.length <= 20
    /// 2. 1 <= A[0].length <= 20
    /// 3. A[i][j] is 0 or 1.
    /// </summary>
    int matrixScore(vector<vector<int>>& A);

    /// <summary>
    /// Leet code #862. Shortest Subarray with Sum at Least K
    /// 
    /// Return the length of the shortest, non-empty, contiguous subarray of A 
    /// with sum at least K.
    ///
    /// If there is no non-empty subarray with sum at least K, return -1.
    ///
    /// Example 1:
    /// Input: A = [1], K = 1
    /// Output: 1
    ///
    /// Example 2:
    /// Input: A = [1,2], K = 4
    /// Output: -1
    ///
    /// Example 3:
    /// Input: A = [2,-1,2], K = 3
    /// Output: 3
    ///
    /// Note:
    /// 1. 1 <= A.length <= 50000
    /// 2. -10 ^ 5 <= A[i] <= 10 ^ 5
    /// 3. 1 <= K <= 10 ^ 9
    /// </summary>
    int shortestSubarray(vector<int>& A, int K);

    /// <summary>
    /// Leet code #867. Transpose Matrix
    /// 
    /// Given a matrix A, return the transpose of A.
    ///
    /// The transpose of a matrix is the matrix flipped over it's main 
    /// diagonal, switching the row and column indices of the matrix.
    ///
    /// Example 1:
    ///
    /// Input: [[1,2,3],[4,5,6],[7,8,9]]
    /// Output: [[1,4,7],[2,5,8],[3,6,9]]
    ///
    /// Example 2:
    ///
    /// Input: [[1,2,3],[4,5,6]]
    /// Output: [[1,4],[2,5],[3,6]]
    ///
    /// Note:
    ///
    /// 1. 1 <= A.length <= 1000
    /// 2. 1 <= A[0].length <= 1000
    /// </summary>
    vector<vector<int>> transpose(vector<vector<int>>& A);

    /// <summary>
    /// Leet code #874. Walking Robot Simulation
    /// 
    /// A robot on an infinite grid starts at point (0, 0) and faces north.  
    /// The robot can receive one of three possible types of commands:
    ///
    /// -2: turn left 90 degrees
    /// -1: turn right 90 degrees
    /// 1 <= x <= 9: move forward x units
    /// Some of the grid squares are obstacles. 
    ///
    /// The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
    ///
    /// If the robot would try to move onto them, the robot stays on the 
    /// previous grid square instead (but still continues following the rest 
    /// of the route.)
    ///
    /// Return the square of the maximum Euclidean distance that the robot 
    /// will be from the origin.
    ///  
    /// Example 1:
    ///
    /// Input: commands = [4,-1,3], obstacles = []
    /// Output: 25
    /// Explanation: robot will go to (3, 4)
    /// 
    /// Example 2:
    ///
    /// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
    /// Output: 65
    /// Explanation: robot will be stuck at (1, 4) before turning left and 
    /// going to (1, 8)
    ///
    /// Note:
    /// 1. 0 <= commands.length <= 10000
    /// 2. 0 <= obstacles.length <= 10000
    /// 3. -30000 <= obstacle[i][0] <= 30000
    /// 4. -30000 <= obstacle[i][1] <= 30000
    /// 5. The answer is guaranteed to be less than 2 ^ 31.
    /// </summary>
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles);

    /// <summary>
    /// Leet code #883. Projection Area of 3D Shapes
    /// 
    /// On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned 
    /// with the x, y, and z axes.
    ///
    /// Each value v = grid[i][j] represents a tower of v cubes placed on top 
    /// of grid cell (i, j).
    ///
    /// Now we view the projection of these cubes onto the xy, yz, and zx planes.
    ///
    /// A projection is like a shadow, that maps our 3 dimensional figure to a 2 
    /// dimensional plane. 
    ///
    /// Here, we are viewing the "shadow" when looking at the cubes from the top, 
    /// the front, and the side.
    ///
    /// Return the total area of all three projections.
    ///
    /// Example 1:
    /// Input: [[2]]
    /// Output: 5
    ///
    /// Example 2:
    /// Input: [[1,2],[3,4]]
    /// Output: 17
    /// Explanation: 
    /// Here are the three projections ("shadows") of the shape made with each 
    /// axis-aligned plane.
    ///
    /// Example 3:
    /// Input: [[1,0],[0,2]]
    /// Output: 8
    ///
    /// Example 4:
    /// Input: [[1,1,1],[1,0,1],[1,1,1]]
    /// Output: 14
    ///
    /// Example 5:
    /// Input: [[2,2,2],[2,1,2],[2,2,2]]
    /// Output: 21
    ///  
    /// Note:
    /// 1. 1 <= grid.length = grid[0].length <= 50
    /// 2. 0 <= grid[i][j] <= 50
    /// </summary>
    int projectionArea(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #457. Circular Array Loop
    /// 
    /// You are given an array of positive and negative integers. If a number n 
    /// at an index is positive, then move forward n steps. Conversely, if 
    /// it's negative (-n), move backward n steps. Assume the first element of 
    /// the array is forward next to the last element, and the last element is 
    /// backward next to the first element. Determine if there is a loop in this 
    /// array. A loop starts and ends at a particular index with more than 1 
    /// element along the loop. The loop must be "forward" or "backward'.
    ///
    /// Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 
    /// 0 -> 2 -> 3 -> 0.
    ///
    /// Example 2: Given the array [-1, 2], there is no loop.
    ///
    /// Note: The given array is guaranteed to contain no element "0".
    /// Can you do it in O(n) time complexity and O(1) space complexity?
    /// </summary>
    bool circularArrayLoop(vector<int>& nums);

    /// <summary>
    /// Leet code #885. Spiral Matrix III
    /// 
    /// On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) 
    /// facing east.
    ///
    /// Here, the north-west corner of the grid is at the first row and column, 
    /// and the south-east corner of the grid is at the last row and column.
    ///
    /// Now, we walk in a clockwise spiral shape to visit every position in this 
    /// grid. 
    ///
    /// Whenever we would move outside the boundary of the grid, we continue our 
    /// walk outside the grid (but may return to the grid boundary later.) 
    ///
    /// Eventually, we reach all R * C spaces of the grid.
    ///
    /// Return a list of coordinates representing the positions of the grid in 
    /// the order they were visited.
    ///
    /// Example 1:
    ///
    /// Input: R = 1, C = 4, r0 = 0, c0 = 0
    /// Output: [[0,0],[0,1],[0,2],[0,3]]
    ///
    /// Example 2:
    ///
    /// Input: R = 5, C = 6, r0 = 1, c0 = 4
    /// Output: 
    /// [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],
    ///  [3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],
    ///  [0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
    ///
    /// Note:
    /// 1. 1 <= R <= 100
    /// 2. 1 <= C <= 100
    /// 3. 0 <= r0 < R
    /// 4. 0 <= c0 < C
    /// </summary>
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0);
    
    /// <summary>
    /// Leet code #888. Fair Candy Swap
    /// 
    /// Alice and Bob have candy bars of different sizes: A[i] is the size of the 
    /// i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of 
    /// candy that Bob has.
    ///
    /// Since they are friends, they would like to exchange one candy bar each so 
    /// that after the exchange, they both have the same total amount of candy.  
    /// (The total amount of candy a person has is the sum of the sizes of candy 
    /// bars they have.)
    ///
    /// Return an integer array ans where ans[0] is the size of the candy bar that 
    /// Alice must exchange, and ans[1] is the size of the candy bar that Bob must 
    /// exchange.
    ///
    /// If there are multiple answers, you may return any one of them.  It is 
    /// guaranteed an answer exists.
    ///
    /// Example 1:
    /// Input: A = [1,1], B = [2,2]
    /// Output: [1,2]
    ///
    /// Example 2:
    /// Input: A = [1,2], B = [2,3]
    /// Output: [1,2]
    ///
    /// Example 3:
    /// Input: A = [2], B = [1,3]
    /// Output: [2,3]
    ///
    /// Example 4:
    /// Input: A = [1,2,5], B = [2,4]
    /// Output: [5,4]
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 10000
    /// 2. 1 <= B.length <= 10000
    /// 3. 1 <= A[i] <= 100000
    /// 4. 1 <= B[i] <= 100000
    /// 5. It is guaranteed that Alice and Bob have different total amounts of 
    ///    candy.
    /// 6. It is guaranteed there exists an answer.
    /// </summary>
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B);

    /// <summary>
    /// Leet code #892. Surface Area of 3D Shapes
    /// 
    /// On a N * N grid, we place some 1 * 1 * 1 cubes.
    ///
    /// Each value v = grid[i][j] represents a tower of v cubes placed on top of 
    /// grid cell (i, j).
    ///
    /// Return the total surface area of the resulting shapes. 
    ///
    /// Example 1:
    /// Input: [[2]]
    /// Output: 10
    ///
    /// Example 2: 
    /// Input: [[1,2],[3,4]]
    /// Output: 34
    ///
    /// Example 3:
    /// Input: [[1,0],[0,2]]
    /// Output: 16
    ///
    /// Example 4:
    /// Input: [[1,1,1],[1,0,1],[1,1,1]]
    /// Output: 32
    ///
    /// Example 5: 
    /// Input: [[2,2,2],[2,1,2],[2,2,2]]
    /// Output: 46
    /// 
    /// Note:
    /// 
    /// 1. 1 <= N <= 50
    /// 2. 0 <= grid[i][j] <= 50
    /// </summary>
    int surfaceArea(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #896. Monotonic Array 
    /// 
    /// An array is monotonic if it is either monotone increasing or monotone 
    /// decreasing.
    ///
    /// An array A is monotone increasing if for all i <= j, A[i] <= A[j].  
    /// An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
    ///
    /// Return true if and only if the given array A is monotonic.
    ///
    /// Example 1:
    /// Input: [1,2,2,3]
    /// Output: true
    ///
    /// Example 2:
    /// Input: [6,5,4,4]
    /// Output: true
    ///
    /// Example 3:
    /// Input: [1,3,2]
    /// Output: false
    ///
    /// Example 4:
    /// Input: [1,2,4,5]
    /// Output: true
    ///
    /// Example 5:
    /// Input: [1,1,1]
    /// Output: true
    /// Note:
    /// 1. 1 <= A.length <= 50000
    /// 2. -100000 <= A[i] <= 100000
    /// </summary>
    bool isMonotonic(vector<int>& A);

    /// <summary>
    /// Leet code #905. Sort Array By Parity
    /// 
    /// Given an array A of non-negative integers, return an array 
    /// consisting of all the even elements of A, followed by all 
    /// the odd elements of A.
    ///
    /// You may return any answer array that satisfies this condition.
    ///
    /// Example 1:
    /// Input: [3,1,2,4]
    /// Output: [2,4,3,1]
    /// The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 5000
    /// 2. 0 <= A[i] <= 5000
    /// </summary>
    vector<int> sortArrayByParity(vector<int>& A);

    /// <summary>
    /// Leet code #918. Maximum Sum Circular Subarray
    /// 
    /// Given a circular array C of integers represented by A, find the maximum 
    /// possible sum of a non-empty subarray of C.
    ///
    /// Here, a circular array means the end of the array connects to the 
    /// beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, 
    /// and C[i+A.length] = C[i] when i >= 0.)
    ///
    /// Also, a subarray may only include each element of the fixed buffer A at 
    /// most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does 
    /// not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
    ///
    ///
    /// Example 1:
    /// Input: [1,-2,3,-2]
    /// Output: 3
    /// Explanation: Subarray [3] has maximum sum 3
    ///
    /// Example 2:
    /// Input: [5,-3,5]
    /// Output: 10
    /// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
    ///
    /// Example 3:
    /// Input: [3,-1,2,-1]
    /// Output: 4
    /// Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
    ///
    /// Example 4:
    /// Input: [3,-2,2,-3]
    /// Output: 3
    /// Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
    ///
    /// Example 5:
    /// Input: [-2,-3,-1]
    /// Output: -1
    /// Explanation: Subarray [-1] has maximum sum -1
    ///  
    ///
    /// Note:
    ///
    /// 1. -30000 <= A[i] <= 30000
    /// 2. 1 <= A.length <= 30000
    /// 
    /// </summary>
    int maxSubarraySumCircular(vector<int>& A);

    /// <summary>
    /// Leet code #922. Sort Array By Parity II
    /// 
    /// Given an array A of non-negative integers, half of the integers in A are 
    /// odd, and half of the integers are even.
    ///
    /// Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] 
    /// is even, i is even.
    ///
    /// You may return any answer array that satisfies this condition.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: [4,2,5,7]
    /// Output: [4,5,2,7]
    /// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
    /// 
    ///
    /// Note:
    ///
    /// 1. 2 <= A.length <= 20000
    /// 2. A.length % 2 == 0
    /// 3. 0 <= A[i] <= 1000
    /// </summary>
    vector<int> sortArrayByParityII(vector<int>& A);

    /// <summary>
    /// Leet code #926. Flip String to Monotone Increasing 
    /// 
    /// A string of '0's and '1's is monotone increasing if it consists of some 
    /// number of '0's (possibly 0), followed by some number of '1's (also 
    /// possibly 0.)
    ///
    /// We are given a string S of '0's and '1's, and we may flip any '0' to a '1' 
    /// or a '1' to a '0'.
    ///
    /// Return the minimum number of flips to make S monotone increasing.
    ///
    /// 
    /// Example 1:
    /// Input: "00110"
    /// Output: 1
    /// Explanation: We flip the last digit to get 00111.
    ///
    /// Example 2:
    /// Input: "010110"
    /// Output: 2
    /// Explanation: We flip to get 011111, or alternatively 000111.
    ///
    /// Example 3:
    /// Input: "00011000"
    /// Output: 2
    /// Explanation: We flip to get 00000000.
    /// 
    /// Note:
    ///
    /// 1. 1 <= S.length <= 20000
    /// 2. S only consists of '0' and '1' characters.
    /// </summary>
    int minFlipsMonoIncr(string S);

    /// <summary>
    /// Leet code #927. Three Equal Parts
    /// 
    /// Given an array A of 0s and 1s, divide the array into 3 non-empty parts 
    /// such that all of these parts represent the same binary value.
    ///
    /// If it is possible, return any [i, j] with i+1 < j, such that:
    ///
    /// A[0], A[1], ..., A[i] is the first part;
    /// A[i+1], A[i+2], ..., A[j-1] is the second part, and
    /// A[j], A[j+1], ..., A[A.length - 1] is the third part.
    /// All three parts have equal binary value.
    /// If it is not possible, return [-1, -1].
    ///
    /// Note that the entire part is used when considering what binary value it 
    /// represents.  For example, [1,1,0] represents 6 in decimal, not 3.  Also, 
    /// leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.
    ///
    /// Example 1:
    /// Input: [1,0,1,0,1]
    /// Output: [0,3]
    ///
    /// Example 2:
    /// Input: [1,1,0,1,1]
    /// Output: [-1,-1]
    ///
    /// Note:
    /// 
    /// 1. 3 <= A.length <= 30000
    /// 2. A[i] == 0 or A[i] == 1
    /// </summary>
    vector<int> threeEqualParts(vector<int>& A);

    /// <summary>
    /// Leet code #936. Stamping The Sequence
    /// </summary>
    vector<int> searchStamp(string &stamp, string& target, int &reduce);

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
    /// Leet code #939. Minimum Area Rectangle
    /// 
    /// Given a set of points in the xy-plane, determine the minimum area of a 
    /// rectangle formed from these points, with sides parallel to the x and y 
    /// axes.
    ///
    /// If there isn't any rectangle, return 0.
    /// 
    /// Example 1:
    ///
    /// Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
    /// Output: 4
    ///
    /// Example 2:
    /// 
    /// Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
    /// Output: 2
    ///  
    /// Note:
    ///
    /// 1. 1 <= points.length <= 500
    /// 2. 0 <= points[i][0] <= 40000
    /// 3. 0 <= points[i][1] <= 40000
    /// 4. All points are distinct.
    /// </summary>
    int minAreaRect(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #944. Delete Columns to Make Sorted
    /// 
    /// We are given an array A of N lowercase letter strings, all of the same 
    /// length.
    ///
    /// Now, we may choose any set of deletion indices, and for each string, we 
    /// delete all the characters in those indices.
    ///
    /// For example, if we have a string "abcdef" and deletion indices {0, 2, 3}, 
    /// then the final string after deletion is "bef".
    ///
    /// Suppose we chose a set of deletion indices D such that after deletions, 
    /// each remaining column in A is in non-decreasing sorted order.
    ///
    /// Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]]
    ///
    /// Return the minimum possible value of D.length.
    ///
    /// 
    /// Example 1:
    /// Input: ["cba","daf","ghi"]
    /// Output: 1
    ///
    /// Example 2:
    /// Input: ["a","b"]
    /// Output: 0
    ///
    /// Example 3:
    /// Input: ["zyx","wvu","tsr"]
    /// Output: 3
    /// Note:
    /// 1. 1 <= A.length <= 100
    /// 2. 1 <= A[i].length <= 1000
    /// </summary>
    int minDeletionSize(vector<string>& A);

    /// <summary>
    /// Leet code #945. Minimum Increment to Make Array Unique
    /// 
    /// Given an array of integers A, a move consists of choosing any A[i], 
    /// and incrementing it by 1.
    ///
    /// Return the least number of moves to make every value in A unique.
    ///
    /// Example 1:
    /// Input: [1,2,2]
    /// Output: 1
    /// Explanation:  After 1 move, the array could be [1, 2, 3].
    ///
    /// Example 2:
    /// Input: [3,2,1,2,1,7]
    /// Output: 6
    /// Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
    /// It can be shown with 5 or less moves that it is impossible for the 
    /// array to have all unique values.
    /// 
    /// Note:
    /// 1. 0 <= A.length <= 40000
    /// 2. 0 <= A[i] < 40000
    /// </summary>
    int minIncrementForUnique(vector<int>& A);

    /// <summary>
    /// Leet code #950. Reveal Cards In Increasing Order
    /// 
    /// In a deck of cards, every card has a unique integer.  You can order 
    /// the deck in any order you want.
    ///
    /// Initially, all the cards start face down (unrevealed) in one deck.
    ///
    /// Now, you do the following steps repeatedly, until all cards are 
    /// revealed:
    ///
    /// Take the top card of the deck, reveal it, and take it out of the deck.
    /// If there are still cards in the deck, put the next top card of the  
    /// deck at the bottom of the deck.
    /// If there are still unrevealed cards, go back to step 1.  Otherwise, 
    /// stop.
    /// Return an ordering of the deck that would reveal the cards in 
    /// increasing order.
    /// 
    /// The first entry in the answer is considered to be the top of the deck.
    ///
    ///
    ///
    /// Example 1:
    ///
    /// Input: [17,13,11,2,3,5,7]
    /// Output: [2,13,3,11,5,17,7]
    /// Explanation: 
    /// We get the deck in the order [17,13,11,2,3,5,7] (this order doesn't 
    /// matter), and reorder it.
    /// After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is 
    /// the top of the deck.
    /// We reveal 2, and move 13 to the bottom.  The deck is now 
    /// [3,11,5,17,7,13].
    /// We reveal 3, and move 11 to the bottom.  The deck is now 
    /// [5,17,7,13,11].
    /// We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
    /// We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
    /// We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
    /// We reveal 13, and move 17 to the bottom.  The deck is now [17].
    /// We reveal 17.
    /// Since all the cards revealed are in increasing order, the answer is 
    /// correct.
    ///
    ///
    /// Note:
    /// 1. 1 <= A.length <= 1000
    /// 2. 1 <= A[i] <= 10^6
    /// 3. A[i] != A[j] for all i != j
    /// </summary>
    vector<int> deckRevealedIncreasing(vector<int>& deck);

    /// <summary>
    /// Leet code #961. N-Repeated Element in Size 2N Array
    /// 
    /// In a array A of size 2N, there are N+1 unique elements, and exactly one 
    /// of these elements is repeated N times.
    ///
    /// Return the element repeated N times.
    ///
    /// Example 1:
    /// Input: [1,2,3,3]
    /// Output: 3
    ///
    /// Example 2:
    /// Input: [2,1,2,5,3,2]
    /// Output: 2
    ///
    /// Example 3:
    /// Input: [5,1,5,2,5,3,5,4]
    /// Output: 5 
    ///
    /// Note:
    /// 1. 4 <= A.length <= 10000
    /// 2. 0 <= A[i] < 10000
    /// 3. A.length is even
    /// </summary>
    int repeatedNTimes(vector<int>& A);

    /// <summary>
    /// Leet code #985. Sum of Even Numbers After Queries
    /// 
    /// We have an array A of integers, and an array queries of queries.
    /// For the i-th query val = queries[i][0], index = queries[i][1], we 
    /// add val to A[index].  Then, the answer to the i-th query is the 
    /// sum of the even values of A.
    ///
    /// (Here, the given index = queries[i][1] is a 0-based index, and 
    /// each query permanently modifies the array A.)
    ///
    /// Return the answer to all queries.  Your answer array should have 
    /// answer[i] as the answer to the i-th query.
    ///
    /// Example 1:
    /// 
    /// Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
    /// Output: [8,6,2,4]
    /// Explanation: 
    /// At the beginning, the array is [1,2,3,4].
    /// 1. After adding 1 to A[0], the array is [2,2,3,4], and the sum of 
    ///    even values is 2 + 2 + 4 = 8.
    /// 2. After adding -3 to A[1], the array is [2,-1,3,4], and the sum 
    ///    of even values is 2 + 4 = 6.
    /// 3. After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of 
    ///    even values is -2 + 4 = 2.
    /// 4. After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of 
    ///    even values is -2 + 6 = 4.
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 10000
    /// 2. -10000 <= A[i] <= 10000
    /// 3. 1 <= queries.length <= 10000
    /// 4. -10000 <= queries[i][0] <= 10000
    /// 5. 0 <= queries[i][1] < A.length
    /// </summary>
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code #989. Add to Array-Form of Integer
    /// 
    /// For a non-negative integer X, the array-form of X is an array of its 
    /// digits in left to right order.  For example, if X = 1231, then the 
    /// array form is [1,2,3,1].
    ///
    /// Given the array-form A of a non-negative integer X, return the 
    /// array-form of the integer X+K.
    ///
    /// Example 1:
    /// Input: A = [1,2,0,0], K = 34
    /// Output: [1,2,3,4]
    /// Explanation: 1200 + 34 = 1234
    ///
    /// Example 2:
    /// Input: A = [2,7,4], K = 181
    /// Output: [4,5,5]
    /// Explanation: 274 + 181 = 455
    ///
    /// Example 3:
    /// Input: A = [2,1,5], K = 806
    /// Output: [1,0,2,1]
    /// Explanation: 215 + 806 = 1021
    ///
    /// Example 4:
    /// Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
    /// Output: [1,0,0,0,0,0,0,0,0,0,0]
    /// Explanation: 9999999999 + 1 = 10000000000
    /// 
    /// Note：
    /// 1. 1 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 9
    /// 3. 0 <= K <= 10000
    /// 4. If A.length > 1, then A[0] != 0
    /// </summary>
    vector<int> addToArrayForm(vector<int>& A, int K);

    /// <summary>
    /// Leet code #992. Subarrays with K Different Integers
    /// 
    /// Given an array A of positive integers, call a (contiguous, not 
    /// necessarily distinct) subarray of A good if the number of different 
    /// integers in that subarray is exactly K.
    /// 
    /// (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
    ///
    /// Return the number of good subarrays of A.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: A = [1,2,1,2,3], K = 2
    /// Output: 7
    /// Explanation: Subarrays formed with exactly 2 different integers: 
    /// [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
    ///
    /// Example 2:
    ///
    /// Input: A = [1,2,1,3,4], K = 3
    /// Output: 3
    /// Explanation: Subarrays formed with exactly 3 different integers: 
    /// [1,2,1,3], [2,1,3], [1,3,4].
    ///
    ///
    /// Note:
    /// 1. 1 <= A.length <= 20000
    /// 2. 1 <= A[i] <= A.length
    /// 3. 1 <= K <= A.length
    /// </summary>
    int subarraysWithKDistinct(vector<int>& A, int K);

    /// <summary>
    /// Leet code #995. Minimum Number of K Consecutive Bit Flips
    /// 
    /// In an array A containing only 0s and 1s, a K-bit flip consists of choosing 
    /// a (contiguous) subarray of length K and simultaneously changing every 0 in 
    /// the subarray to 1, and every 1 in the subarray to 0.
    ///
    /// Return the minimum number of K-bit flips required so that there is no 0 in 
    /// the array.  If it is not possible, return -1.
    ///
    /// Example 1:
    ///
    /// Input: A = [0,1,0], K = 1
    /// Output: 2
    /// Explanation: Flip A[0], then flip A[2].
    ///
    /// Example 2:
    ///
    /// Input: A = [1,1,0], K = 2
    /// Output: -1
    /// Explanation: No matter how we flip subarrays of size 2, we can't make the 
    /// array become [1,1,1].
    ///
    /// Example 3:
    ///
    /// Input: A = [0,0,0,1,0,1,1,0], K = 3
    /// Output: 3
    /// Explanation:
    /// Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
    /// Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
    /// Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]
    ///
    ///
    /// Note:
    ///
    /// 1. 1 <= A.length <= 30000
    /// 2. 1 <= K <= A.length
    /// </summary>
    int minKBitFlips(vector<int>& A, int K);

    /// <summary>
    /// Leet code #1001. Grid Illumination
    /// 
    /// On a N x N grid of cells, each cell (x, y) with 0 <= x < N and 
    /// 0 <= y < N has a lamp.
    /// Initially, some number of lamps are on.  lamps[i] tells us the 
    /// location of the i-th lamp that is on.  Each lamp that is on 
    /// illuminates every square on its x-axis, y-axis, and both diagonals 
    /// (similar to a Queen in chess).
    /// For the i-th query queries[i] = (x, y), the answer to the query is 1 
    /// if the cell (x, y) is illuminated, else 0.
    /// After each query (x, y) [in the order given by queries], we turn off 
    /// any lamps that are at cell (x, y) or are adjacent 8-directionally 
    /// (ie., share a corner or edge with cell (x, y).)
    /// Return an array of answers.  Each value answer[i] should be equal 
    /// to the answer of the i-th query queries[i].
    ///
    /// Example 1:
    /// Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
    /// Output: [1,0]
    /// Explanation: 
    /// Before performing the first query we have both lamps [0,0] and [4,4] 
    /// on.
    /// The grid representing which cells are lit looks like this, where [0,0] 
    /// is the top left corner, and [4,4] is the bottom right corner:
    /// 1 1 1 1 1
    /// 1 1 0 0 1
    /// 1 0 1 0 1
    /// 1 0 0 1 1
    /// 1 1 1 1 1
    /// Then the query at [1, 1] returns 1 because the cell is lit.  After 
    /// this query, the lamp at [0, 0] turns off, and the grid now looks 
    /// like this:
    /// 1 0 0 0 1
    /// 0 1 0 0 1
    /// 0 0 1 0 1
    /// 0 0 0 1 1
    /// 1 1 1 1 1
    /// Before performing the second query we have only the lamp [4,4] on.  
    /// Now the query at [1,0] returns 0, because the cell is no longer lit.
    /// 
    /// Note:
    /// 1. 1 <= N <= 10^9
    /// 2. 0 <= lamps.length <= 20000
    /// 3. 0 <= queries.length <= 20000
    /// 4. lamps[i].length == queries[i].length == 2
    /// </summary>
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code #999. Available Captures for Rook
    /// 
    /// On an 8 x 8 chessboard, there is one white rook.  There also may be 
    /// empty squares, white bishops, and black pawns.  These are given as 
    /// characters 'R', '.', 'B', and 'p' respectively. Uppercase characters 
    /// represent white pieces, and lowercase characters represent black 
    /// pieces.
    ///
    /// The rook moves as in the rules of Chess: it chooses one of four 
    /// cardinal directions (north, east, west, and south), then moves in that 
    /// direction until it chooses to stop, reaches the edge of the board, or 
    /// captures an opposite colored pawn by moving to the same square it 
    /// occupies.  Also, rooks cannot move into the same square as other 
    /// friendly bishops.
    /// 
    /// Return the number of pawns the rook can capture in one move.
    /// 
    /// Example 1:
    ///
    /// Input: [
    /// [".",".",".",".",".",".",".","."],
    /// [".",".",".","p",".",".",".","."],
    /// [".",".",".","R",".",".",".","p"],
    /// [".",".",".",".",".",".",".","."],
    /// [".",".",".",".",".",".",".","."],
    /// [".",".",".","p",".",".",".","."],
    /// [".",".",".",".",".",".",".","."],
    /// [".",".",".",".",".",".",".","."]]
    /// Output: 3
    /// Explanation: 
    /// In this example the rook is able to capture all the pawns.
    ///
    /// Example 2:
    /// 
    /// Input: [
    /// [".",".",".",".",".",".",".","."],
    /// [".","p","p","p","p","p",".","."],
    /// [".","p","p","B","p","p",".","."],
    /// [".","p","B","R","B","p",".","."],
    /// [".","p","p","B","p","p",".","."],
    /// [".","p","p","p","p","p",".","."],
    /// [".",".",".",".",".",".",".","."],
    /// [".",".",".",".",".",".",".","."]]
    /// Output: 0
    /// Explanation: 
    /// Bishops are blocking the rook to capture any pawn.
    ///
    /// Example 3:
    /// Input:[
    /// [".",".",".",".",".",".",".","."],
    /// [".",".",".","p",".",".",".","."],
    /// [".",".",".","p",".",".",".","."],
    /// ["p","p",".","R",".","p","B","."],
    /// [".",".",".",".",".",".",".","."],
    /// [".",".",".","B",".",".",".","."],
    /// [".",".",".","p",".",".",".","."],
    /// [".",".",".",".",".",".",".","."]]
    /// Output: 3
    /// Explanation: 
    /// The rook can capture the pawns at positions b5, d6 and f5.
    ///
    /// Note:
    ///  
    /// board.length == board[i].length == 8
    /// board[i][j] is either 'R', '.', 'B', or 'p'
    /// There is exactly one cell with board[i][j] == 'R'
    /// </summary>
    int numRookCaptures(vector<vector<char>>& board);

    /// <summary>
    /// Leet code #997. Find the Town Judge
    /// 
    /// In a town, there are N people labelled from 1 to N.  There is a rumor 
    /// that one of these people is secretly the town judge.
    ///
    /// If the town judge exists, then:
    ///
    /// The town judge trusts nobody.
    /// Everybody (except for the town judge) trusts the town judge.
    /// There is exactly one person that satisfies properties 1 and 2.
    /// You are given trust, an array of pairs trust[i] = [a, b] representing 
    /// that the person labelled a trusts the person labelled b.
    ///
    /// If the town judge exists and can be identified, return the label of the 
    /// town judge.  Otherwise, return -1.
    /// 
    /// Example 1:
    ///
    /// Input: N = 2, trust = [[1,2]]
    /// Output: 2
    ///
    /// Example 2:
    /// 
    /// Input: N = 3, trust = [[1,3],[2,3]]
    /// Output: 3
    ///
    /// Example 3:
    /// 
    /// Input: N = 3, trust = [[1,3],[2,3],[3,1]]
    /// Output: -1
    ///
    /// Example 4:
    /// 
    /// Input: N = 3, trust = [[1,2],[2,3]]
    /// Output: -1
    ///
    /// Example 5:
    ///
    /// Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
    /// Output: 3
    ///
    /// Note:
    /// 
    /// 1. 1 <= N <= 1000
    /// 2. trust.length <= 10000
    /// 3. trust[i] are all different
    /// 4. trust[i][0] != trust[i][1]
    /// 5. 1 <= trust[i][0], trust[i][1] <= N
    /// </summary>
    int findJudge(int N, vector<vector<int>>& trust);

    /// <summary>
    /// Leet code #1004. Max Consecutive Ones III
    /// 
    /// Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
    ///
    /// Return the length of the longest (contiguous) subarray that contains 
    /// only 1s. 
    ///
    /// Example 1:
    /// Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
    /// Output: 6
    /// Explanation: 
    /// [1,1,1,0,0,1,1,1,1,1,1]
    /// Bolded numbers were flipped from 0 to 1.  The longest subarray is 
    /// underlined.
    ///
    /// Example 2:
    /// Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
    /// Output: 10
    /// Explanation: 
    /// [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
    /// Bolded numbers were flipped from 0 to 1.  The longest subarray is 
    /// underlined.
    /// 
    /// Note:
    ///
    /// 1. 1 <= A.length <= 20000
    /// 2. 0 <= K <= A.length
    /// 3. A[i] is 0 or 1 
    /// </summary>
    int longestOnes(vector<int>& A, int K);

    /// <summary>
    /// Leet code #1005. Maximize Sum Of Array After K Negations
    /// 
    /// Given an array A of integers, we must modify the array in the 
    /// following way: we choose an i and replace A[i] with -A[i], and we 
    /// repeat this process K times in total.  (We may choose the same index 
    /// i multiple times.)
    /// 
    /// Return the largest possible sum of the array after modifying it in 
    /// this way.
    ///
    /// Example 1:
    ///
    /// Input: A = [4,2,3], K = 1
    /// Output: 5
    /// Explanation: Choose indices (1,) and A becomes [4,-2,3].
    ///
    /// Example 2:
    ///
    /// Input: A = [3,-1,0,2], K = 3
    /// Output: 6
    /// Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
    ///
    /// Example 3:
    ///
    /// Input: A = [2,-3,-1,5,-4], K = 2
    /// Output: 13
    /// Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
    ///
    ///
    /// Note:
    /// 1. 1 <= A.length <= 10000
    /// 2. 1 <= K <= 10000
    /// 3. -100 <= A[i] <= 100
    /// </summary>
    int largestSumAfterKNegations(vector<int>& A, int K);

    /// <summary>
    /// Leet code #1007. Minimum Domino Rotations For Equal Row
    /// 
    /// In a row of dominoes, A[i] and B[i] represent the top and bottom 
    /// halves of the i-th domino.  (A domino is a tile with two numbers 
    /// from 1 to 6 - one on each half of the tile.)
    ///
    /// We may rotate the i-th domino, so that A[i] and B[i] swap values.
    /// 
    /// Return the minimum number of rotations so that all the values in A 
    /// are the same, or all the values in B are the same.
    ///
    /// If it cannot be done, return -1.
    /// 
    /// Example 1:
    /// Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
    /// Output: 2
    /// Explanation: 
    /// The first figure represents the dominoes as given by A and B: before 
    /// we do any rotations.
    /// If we rotate the second and fourth dominoes, we can make every 
    /// value in the top row equal to 2, as indicated by the second figure.
    ///
    /// Example 2:
    ///
    /// Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
    /// Output: -1
    /// Explanation: 
    /// In this case, it is not possible to rotate the dominoes to make one 
    /// row of values equal.
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= A[i], B[i] <= 6
    /// 2. 2 <= A.length == B.length <= 20000
    /// 
    /// </summary>
    int minDominoRotations(vector<int>& A, vector<int>& B);

    /// <summary>
    /// Leet code #1013. Partition Array Into Three Parts With Equal Sum
    /// 
    /// Given an array A of integers, return true if and only if we can 
    /// partition the array into three non-empty parts with equal sums.
    ///
    /// Formally, we can partition the array if we can find indexes i+1 < j with 
    /// (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + 
    /// A[j-1] + ... + A[A.length - 1])
    ///
    ///
    /// Example 1:
    ///
    /// Input: [0,2,1,-6,6,-7,9,1,2,0,1]
    /// Output: true
    /// Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
    /// Example 2:
    ///
    /// Input: [0,2,1,-6,6,7,9,-1,2,0,1]
    /// Output: false
    /// Example 3:
    ///
    /// Input: [3,3,6,5,-2,2,5,1,-9,4]
    /// Output: true
    /// Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
    /// 
    /// Note:
    ///
    /// 1. 3 <= A.length <= 50000
    /// 2. -10000 <= A[i] <= 10000
    /// </summary>
    bool canThreePartsEqualSum(vector<int>& A);

    /// <summary>
    /// Leet code #1014. Best Sightseeing Pair
    /// 
    /// Given an array A of positive integers, A[i] represents the value of the 
    /// i-th sightseeing spot, and two sightseeing spots i and j have distance 
    /// j - i between them.
    ///
    /// The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) 
    /// : the sum of the values of the sightseeing spots, minus the distance 
    /// between them.
    ///
    /// Return the maximum score of a pair of sightseeing spots.
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: [8,1,5,2,6]
    /// Output: 11
    /// Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
    ///
    /// 
    /// Note:
    /// 
    /// 1. 2 <= A.length <= 50000
    /// 2. 1 <= A[i] <= 1000
    /// </summary>
    int maxScoreSightseeingPair(vector<int>& A);

    /// <summary>
    /// Leet code #1036. Escape a Large Maze
    /// 
    /// In a 1 million by 1 million grid, the coordinates of each grid square are 
    /// (x, y) with 0 <= x, y < 10^6.
    ///
    /// We start at the source square and want to reach the target square.  
    /// Each move, we can walk to a 4-directionally adjacent square in the grid 
    /// that isn't in the given list of blocked squares.
    ///
    /// Return true if and only if it is possible to reach the target square 
    /// through a sequence of moves.
    ///
    /// Example 1:
    ///
    /// Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
    /// Output: false
    /// Explanation: 
    /// The target square is inaccessible starting from the source square, because
    /// we can't walk outside the grid.
    ///
    /// Example 2:
    ///
    /// Input: blocked = [], source = [0,0], target = [999999,999999]
    /// Output: true
    /// Explanation: 
    /// Because there are no blocked cells, it's possible to reach the target square.
    /// 
    /// Note:
    /// 1. 0 <= blocked.length <= 200
    /// 2. blocked[i].length == 2
    /// 3. 0 <= blocked[i][j] < 10^6
    /// 4. source.length == target.length == 2
    /// 5. 0 <= source[i][j], target[i][j] < 10^6
    /// 6. source != target
    /// </summary>
    bool LeetCode::isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target);

    /// <summary>
    /// Leet code #1052. Grumpy Bookstore Owner
    /// 
    /// Today, the bookstore owner has a store open for customers.length minutes.  
    /// Every minute, some number of customers (customers[i]) enter the store, 
    /// and all those customers leave after the end of that minute.
    ///
    /// On some minutes, the bookstore owner is grumpy.  If the bookstore owner 
    /// is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  
    /// When the bookstore owner is grumpy, the customers of that minute are not 
    /// satisfied, otherwise they are satisfied.
    ///
    /// The bookstore owner knows a secret technique to keep themselves not grumpy 
    /// for X minutes straight, but can only use it once.
    ///
    /// Return the maximum number of customers that can be satisfied throughout 
    /// the day.
    /// 
    /// Example 1:
    ///
    /// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
    /// Output: 16
    /// Explanation: The bookstore owner keeps themselves not grumpy for the last 
    /// 3 minutes. 
    /// The maximum number of customers that can be 
    /// satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
    /// 
    /// Note:
    ///
    /// 1. 1 <= X <= customers.length == grumpy.length <= 20000
    /// 2. 0 <= customers[i] <= 1000
    /// 3. 0 <= grumpy[i] <= 1
    /// </summary>
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X);

    /// <summary>
    /// Leet code #1074. Number of Submatrices That Sum to Target
    /// 
    /// Given a matrix, and a target, return the number of non-empty submatrices 
    /// that sum to target.
    ///
    /// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with 
    /// x1 <= x <= x2 and y1 <= y <= y2.
    ///
    /// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different 
    /// if they have some coordinate that is different: for example, if x1 != x1'.
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
    /// Output: 4
    /// Explanation: The four 1x1 submatrices that only contain 0.
    ///
    /// Example 2:
    ///
    /// Input: matrix = [[1,-1],[-1,1]], target = 0
    /// Output: 5
    /// Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus 
    /// the 2x2 submatrix.
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= matrix.length <= 300
    /// 2. 1 <= matrix[0].length <= 300
    /// 3. -1000 <= matrix[i] <= 1000
    /// 4. -10^8 <= target <= 10^8
    /// </summary>
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target);

    /// <summary>
    /// Leet code #1063. Number of Valid Subarrays
    /// 
    /// Given an array A of integers, return the number of non-empty continuous 
    /// subarrays that satisfy the following condition:
    ///
    /// The leftmost element of the subarray is not larger than other elements 
    /// in the subarray.
    ///
    /// Example 1:
    ///
    /// Input: [1,4,2,5,3]
    /// Output: 11
    /// Explanation: There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],
    /// [2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].
    ///
    /// Example 2:
    ///
    /// Input: [3,2,1]
    /// Output: 3
    /// Explanation: The 3 valid subarrays are: [3],[2],[1].
    ///
    /// Example 3:
    ///
    /// Input: [2,2,2]
    /// Output: 6
    /// Explanation: There are 6 valid subarrays: [2],[2],[2],[2,2],[2,2],[2,2,2].
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= A.length <= 50000
    /// 2. 0 <= A[i] <= 100000
    /// </summary>
    int validSubarrays(vector<int>& nums);

    /// <summary>
    /// Leet code #1089. Duplicate Zeros
    /// 
    /// Given a fixed length array arr of integers, duplicate each occurrence 
    /// of zero, shifting the remaining elements to the right.
    ///
    /// Note that elements beyond the length of the original array are not 
    /// written.
    ///
    /// Do the above modifications to the input array in place, do not return 
    /// anything from your function.
    ///  
    /// Example 1:
    /// Input: [1,0,2,3,0,4,5,0]
    /// Output: null
    /// Explanation: After calling your function, the input array is modified 
    /// to: [1,0,0,2,3,0,0,4]
    ///
    /// Example 2:
    ///
    /// Input: [1,2,3]
    /// Output: null
    /// Explanation: After calling your function, the input array is modified 
    /// to: [1,2,3]
    ///
    /// Note:
    /// 1. 1 <= arr.length <= 10000
    /// 2. 0 <= arr[i] <= 9
    /// </summary>
    void duplicateZeros(vector<int>& arr);

#pragma endregion

#pragma region String
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
    bool isScramble(string s1, string s2);

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
    int readNChars(char *buf, int n, string& s);

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
    int readNCharsII(char *buf, int n, string& s, int& index, string& m_buffer);

    /// <summary>
    /// Leet code #159. Longest Substring with At Most Two Distinct Characters       
    /// 
    /// Given a string, find the length of the longest substring T that contains at most 
    /// 2 distinct characters. 
    /// For example, Given s = “eceba”, 
    /// T is "ece" which its length is 3.
    /// </summary>
    int lengthOfLongestSubstringTwoDistinct(string s);

    /// <summary>
    /// Leet code #340. Longest Substring with At Most K Distinct Characters       
    /// 
    /// Given a string, find the length of the longest substring T that contains at most k distinct characters. 
    /// For example, Given s = “eceba” and k = 2,  
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
    string getTag(string code, size_t &pos);

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
    string replaceWord(unordered_map<int, unordered_set<string>>&dict_map, const string&word);

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
    string parseAtom(string &formula, int& index);

    /// <summary>
    /// Leet code #726. Number of Atoms
    /// </summary>
    int parseAtomCount(string &formula, int& index);

    /// <summary>
    /// Leet code #726. Number of Atoms
    /// </summary>
    void multiplyFormula(map<string, int> &formula, int& count);

    /// <summary>
    /// Leet code #726. Number of Atoms
    /// </summary>
    void mergeFormula(map<string, int> &atom_count, vector<map<string, int>>& formula_array);

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
    int calculateLispCommand(string& command, vector<string>& parameters, unordered_map<string, int>&variables);

    /// <summary>
    /// Leet code #736. Parse Lisp Expression
    /// </summary>
    int processLispCommand (string& expression, int& index, unordered_map<string, int> variables);

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
    /// Leet code #843. Guess the Word
    /// </summary>
    int match(string strA, string strB);

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
    string findSecretWord(vector<string>& wordlist, Master& master);

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
    string parsePhrase(string& line, int &pos);

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
    vector<vector<string>>  parseCSV (vector<string>& lines);
    
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


#pragma endregion

#pragma region HashTable
    /// <summary>
    /// Leet code #30. Substring with Concatenation of All Words 
    /// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of 
    /// substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters. 
    /// For example, given:
    /// s: "barfoothefoobarman"
    /// words: ["foo", "bar"] 
    /// You should return the indices: [0,9].
    /// </summary> 
    vector<int> findSubstring(string s, vector<string>& words);

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
    /// A happy number is a number defined by the following process: Starting with any positive integer,
    /// replace the number by the sum of the squares of its digits, and repeat the process until the number
    /// equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
    /// Those numbers for which this process ends in 1 are happy numbers.
    /// Example: 19 is a happy number
    /// 12 + 92 = 82
    /// 82 + 22 = 68
    /// 62 + 82 = 100
    /// 12 + 02 + 02 = 1
    /// </summary>
    bool isHappy(int n);

    /// <summary>
    /// Leet code #217. Contains Duplicate
    /// Given an array of integers, find if the array contains any duplicates. Your function should return true 
    /// if any value appears at least twice in the array, and it should return false if every element is distinct.	
    /// </summary>
    bool containsDuplicate(vector<int>& nums);

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
    /// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
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
    /// For the left two athletes, you just need to output their relative ranks according to their scores.
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
    // The length of the array won't exceed 10,000.
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
    void addNewAccount(unordered_map<string, set<int>> &account_map, vector<set<string>> &account_emails,
        vector<string>& account);

    /// <summary>
    /// Leet code #721. Accounts Merge
    /// </summary>
    void mergeAccount(unordered_map<string, set<int>> &account_map, vector<set<string>> &account_emails, vector<int>& merge_list,
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

#pragma endregion


#pragma region DynamicProgramming
    /// <summary>
    /// Leet code #84. Largest Rectangle in Histogram  
    /// Given n non-negative integers representing the histogram's bar 
    /// height where the width of each bar is 1, 
    /// find the area of largest rectangle in the histogram. 
    /// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].  
    /// The largest rectangle is shown in the shaded area, which has area = 10 unit.
    /// For example,
    /// Given heights = [2,1,5,6,2,3],
    /// return 10.
    /// This is the first method by using stack, you keep on pushing when the next bar is 
    /// higher, and start to pop up and calculate the previous rectangle when the next bar 
    /// is smaller
    /// </summary> 
    int largestRectangleAreaByStack(vector<int>& heights);

    /// <summary>
    /// Leet code #84. Largest Rectangle in Histogram  
    /// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
    /// find the area of largest rectangle in the histogram. 
    /// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].  
    /// The largest rectangle is shown in the shaded area, which has area = 10 unit.
    /// For example,
    /// Given heights = [2,1,5,6,2,3],
    /// return 10.
    /// This is the second method by using divide and conquer, find the shortest bar 
    /// and then divide into 2 group.
    /// </summary> 
    int largestRectangleAreaByDivide(vector<int>& heights);

    /// <summary>
    /// Leet code #5. Longest Palindromic Substring 
    /// Given a string S, find the longest palindromic substring in S. 
    /// You may assume that the maximum length of S is 1000, 
    ///  and there exists one unique longest palindromic substring
    /// </summary>
    string longestPalindrome(string s);

    /// <summary>
    /// Leet code #121. Best Time to Buy and Sell Stock
    /// Say you have an array for which the ith element is the price of a given stock on day i.
    /// If you were only permitted to complete at most one transaction (ie, buy one and sell one 
    /// share of the stock), design an algorithm to find the maximum profit.
    ///
    /// Example 1:
    /// Input: [7, 1, 5, 3, 6, 4]
    /// Output: 5
    /// max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
    /// 
    /// Example 2:
    /// Input: [7, 6, 4, 3, 1]
    /// Output: 0
    /// In this case, no transaction is done, i.e. max profit = 0.
    /// </summary>
    int maxProfitOneTxn(vector<int>& prices);

    /// <summary>
    /// Leet code #122. Best Time to Buy and Sell Stock II 
    /// Say you have an array for which the ith element is the price of a given stock on day i.
    /// Design an algorithm to find the maximum profit. You may complete as many transactions as you 
    /// like (ie, buy one and sell one share of the stock multiple times). However, you may not 
    /// engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    /// </summary>
    int maxProfitManyTxns(vector<int>& prices);

    /// <summary>
    /// Leet code #188. Best Time to Buy and Sell Stock IV  
    /// Say you have an array for which the ith element is the price of a given stock on day i.
    /// Design an algorithm to find the maximum profit. You may complete at most k transactions.
    /// Note:
    /// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    /// </summary>
    int maxProfitKTxns(int k, vector<int>& prices);

    /// <summary>
    /// Leet code # 309. Best Time to Buy and Sell Stock with Cooldown 
    ///
    /// Say you have an array for which the ith element is the price of a given stock on day i.
    ///
    /// Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
    /// (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
    /// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    /// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
    /// 
    /// Example:
    /// prices = [1, 2, 3, 0, 2] 
    /// maxProfit = 3
    /// transactions = [buy, sell, cooldown, buy, sell]
    /// </summary>
    int maxProfit(vector<int>& prices);


    /// <summary>
    /// Leet code #97. Interleaving String
    /// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
    /// For example,
    /// Given:
    /// s1 = "aabcc",
    /// s2 = "dbbca", 
    /// When s3 = "aadbbcbcac", return true.
    /// When s3 = "aadbbbaccc", return false. 
    /// </summary>
    bool isInterleave(string s1, string s2, string s3);


    /// <summary>
    /// Leet code #198. House Robber
    ///
    /// You are a professional robber planning to rob houses along a street. 
    /// Each house has a certain amount of money stashed, the only constraint 
    /// stopping you from robbing each of them is that adjacent houses have 
    /// security system connected and it will automatically contact the police 
    /// if two adjacent houses were broken into on the same night.
    /// Given a list of non-negative integers representing the amount of money 
    /// of each house, determine the maximum amount of money you can rob 
    /// tonight without alerting the police.
    /// </summary>
    int rob(vector<int>& nums);

    /// <summary>
    /// Leet code #96. Unique Binary Search Trees    
    /// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?  
    /// For example,
    /// Given n = 3, there are a total of 5 unique BST's.
    ///   1         3     3      2      1
    ///    \       /     /      / \      \
    ///     3     2     1      1   3      2
    ///    /     /       \                 \
    ///   2     1         2                 3
    /// </summary>
    int numTrees(int n);

    /// <summary>
    /// Leet code #85. Maximal Rectangle  
    /// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
    /// For example, given the following matrix: 
    /// 1 0 1 0 0
    /// 1 0 1 1 1
    /// 1 1 1 1 1
    /// 1 0 0 1 0
    /// Return 6. 
    /// </summary>
    int LeetCode::maximalRectangle(vector<vector<char>>& matrix);

    /// <summary>
    /// Recursive break the word according to dictionary 
    /// </summary>
    bool wordBreak(string s, unordered_set<string>& wordDict, unordered_map<string, bool>&search_map);

    /// <summary>
    /// Leet code #139. Word Break 
    /// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence 
    /// of one or more dictionary words.
    /// For example, given
    /// s = "leetcode", 
    /// dict = ["leet", "code"]. 
    /// Return true because "leetcode" can be segmented as "leet code". 
    /// </summary>
    bool wordBreak(string s, unordered_set<string>& wordDict);

    /// <summary>
    /// Leet code #139. Word Break 
    /// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence 
    /// of one or more dictionary words.
    /// For example, given
    /// s = "leetcode", 
    /// dict = ["leet", "code"]. 
    /// Return true because "leetcode" can be segmented as "leet code". 
    /// </summary>
    bool wordBreakDP(string s, unordered_set<string>& wordDict);

    /// <summary>
    /// LeetCode #120. Triangle   
    /// Given a triangle, find the minimum path sum from top to bottom. 
    /// Each step you may move to adjacent numbers on the row below.
    /// For example, given the following triangle
    /// [
    ///     [2],
    ///    [3,4],
    ///   [6,5,7],
    ///  [4,1,8,3]
    /// ]
    /// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
    /// Note:
    /// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 
    /// </summary>
    int minimumTotal(vector<vector<int>>& triangle);

    /// <summary>
    /// Leet code #279. Perfect Squares 
    /// Given a positive integer n, find the least number of perfect square numbers 
    /// (for example, 1, 4, 9, 16, ...) which sum to n.
    /// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; 
    /// given n = 13, return 2 because 13 = 4 + 9. 
    /// </summary>
    int numSquares(int n);

    /// <summary>
    /// Leet code #276. Paint Fence     
    /// 
    /// There is a fence with n posts, each post can be painted with one of the k colors.
    /// You have to paint all the posts such that no more than two adjacent fence posts have the same color. 
    /// Return the total number of ways you can paint the fence.
    /// Note:
    /// n and k are non-negative integers. 
    /// </summary>
    int numWays(int n, int k);

    /// <summary>
    /// Leet code #221. Maximal Square  
    /// 
    /// Given a 2D binary matrix filled with 0's and 1's, find the largest square 
    /// containing only 1's and return its area. 
    /// For example, given the following matrix: 
    /// 1 0 1 0 0
    /// 1 0 1 1 1
    /// 1 1 1 1 1
    /// 1 0 0 1 0
    /// Return 4. 
    /// </summary>
    int maximalSquare(vector<vector<char>>& matrix);

    /// <summary>
    /// Leet code #256. Paint House 
    /// 
    /// There are a row of n houses, each house can be painted with one of the three colors: red, 
    /// blue or green. The cost of painting each house with a certain color is different. You have 
    /// to paint all the houses such that no two adjacent houses have the same color. 
    /// The cost of painting each house with a certain color is represented by a n x 3 
    /// cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; 
    /// costs[1][2] is the cost of painting house 1 with color green, and so on... 
    /// Find the minimum cost to paint all houses. 
    /// Note:
    /// All costs are positive integers.
    /// </summary>
    int minCost(vector<vector<int>>& costs);

    /// <summary>
    /// Leet code #265. Paint House II 
    /// </summary>
    void selectminCostII(vector<vector<pair<int, int>>>& min_costs, int index, pair<int, int>&color_cost);

    /// <summary>
    /// Leet code #265. Paint House II 
    /// 
    /// There are a row of n houses, each house can be painted with one of the k colors. 
    /// The cost of painting each house with a certain color is different. You have to 
    /// paint all the houses such that no two adjacent houses have the same color. 
    /// The cost of painting each house with a certain color is represented by a n x k 
    /// cost matrix. For example, costs[0][0] is the cost of painting house 0 
    /// with color 0; costs[1][2] is the cost of painting house 1 with color 2, and 
    /// so on... Find the minimum cost to paint all houses. 
    ///
    /// Note:
    /// All costs are positive integers.
    ///
    /// Follow up:
    /// Could you solve it in O(nk) runtime?
    /// </summary>
    int minCostII(vector<vector<int>>& costs);

    /// <summary>
    /// Leet code #161. One Edit Distance
    /// 
    /// Given two strings S and T, determine if they are both one edit distance apart. 
    /// </summary>
    bool isOneEditDistance(string s, string t, size_t i, size_t j, size_t count);

    /// <summary>
    /// Leet code #161. One Edit Distance 
    /// 
    /// Given two strings S and T, determine if they are both one edit distance apart. 
    /// </summary>
    bool isOneEditDistance(string s, string t);

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
    /// Leet code # 517. Super Washing Machines 
    ///
    /// You have n super washing machines on a line. Initially, 
    /// each washing machine has some dresses or is empty.
    /// 
    /// For each move, you could choose any m (1 ≤ m ≤ n) washing machines, 
    /// and pass one dress of each washing machine to one of its adjacent 
    /// washing machines at the same time .
    ///
    /// Given an integer array representing the number of dresses in each 
    /// washing machine from left to right on the line, you should find the 
    /// minimum number of moves to make all the washing machines have the 
    /// same number of dresses. If it is not possible to do it, return -1.
    /// 
    /// Example1
    /// Input: [1,0,5]
    /// Output: 3
    /// Explanation: 
    /// 1st move:    1     0 <-- 5    =>    1     1     4
    /// 2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
    /// 3rd move:    2     1 <-- 3    =>    2     2     2   
    ///
    /// Example2 
    /// Input: [0,3,0]
    /// Output: 2
    /// Explanation: 
    /// 1st move:    0 <-- 3     0    =>    1     2     0    
    /// 2nd move:    1     2 --> 0    =>    1     1     1     
    ///
    /// Example3
    /// Input: [0,2,0]
    /// Output: -1
    /// 
    /// Explanation: 
    /// It's impossible to make all the three washing machines have the 
    /// same number of dresses. 
    /// Note:
    /// The range of n is [1, 10000].
    /// The range of dresses number in a super washing machine is [0, 1e5].
    /// </summary>
    int findMinMoves(vector<int>& machines);
   
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
    /// Leet code #628. Maximum Product of Three Numbers
    /// 
    /// Given an integer array, find three numbers whose product is maximum 
    /// and output the maximum product.
    ///
    /// Example 1:
    /// Input: [1,2,3]
    /// Output: 6
    ///
    /// Example 2:
    /// Input: [1,2,3,4]
    /// Output: 24
    ///
    /// Note:
    /// 1.The length of the given array will be in range [3,104] and all 
    ///   elements are in the range [-1000, 1000].
    /// 2.Multiplication of any three numbers in the input won't exceed the 
    ///   range of 32-bit signed integer.
    /// </summary>
    int maximumProduct(vector<int>& nums);


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
    /// Leet code #	660. Remove 9
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
    /// Leet code #679. 24 Game
    /// </summary>
    void getPoint24Rotation(vector<int>& nums, vector<int> &path, vector<bool> &visited, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #679. 24 Game
    /// </summary>
    bool calculatePoint24(vector<int>& nums);

    /// <summary>
    /// Leet code #679. 24 Game
    ///
    /// You have 4 cards each containing a number from 1 to 9. You need to 
    /// judge whether they could operated through *, /, +, -, (, ) to get 
    /// the value of 24.
    ///
    /// Example 1:
    /// Input: [4, 1, 8, 7]
    /// Output: True
    /// Explanation: (8-4) * (7-1) = 24
    /// Example 2:
    /// Input: [1, 2, 1, 2]
    /// Output: False
    /// Note:
    /// The division operator / represents real division, not integer 
    /// division. For example, 4 / (1 - 2/3) = 12.
    /// Every operation done is between two numbers. In particular, we cannot 
    /// use - as a unary operator. For example, with [1, 1, 1, 1] as input, 
    /// the expression -1 - 1 - 1 - 1 is not allowed.
    /// </summary>
    bool judgePoint24(vector<int>& nums);

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
    /// Leet code #902. Numbers At Most N Given Digit Set 
    /// 
    /// We have a sorted set of digits D, a non-empty subset of 
    /// {'1','2','3','4','5','6','7','8','9'}.  (Note that '0' is not included.)
    /// Now, we write numbers using these digits, using each digit as many times 
    /// as we want.  For example, if D = {'1','3','5'}, we may write numbers such 
    /// as '13', '551', '1351315'.
    ///
    /// Return the number of positive integers that can be written (using the 
    /// digits of D) that are less than or equal to N.
    ///
    /// Example 1:
    /// Input: D = ["1","3","5","7"], N = 100
    /// Output: 20
    /// Explanation: 
    /// The 20 numbers that can be written are:
    /// 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
    /// Example 2:
    ///
    /// Input: D = ["1","4","9"], N = 1000000000
    /// Output: 29523
    /// Explanation: 
    /// We can write 3 one digit numbers, 9 two digit numbers, 27 three digit 
    /// numbers,
    /// 81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
    /// 2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit 
    /// numbers.
    /// In total, this is 29523 integers that can be written using the digits of D.
    ///
    /// Note:
    /// D is a subset of digits '1'-'9' in sorted order.
    /// 1 <= N <= 10^9
    /// </summary>
    int atMostNGivenDigitSet(vector<string>& D, int N);

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
    /// Leet code #964. Least Operators to Express Number
    /// </summary>
    int leastOpsExpressTarget(int exp, int x, int target, unordered_map<int, unordered_map<int, int>> &cache);

    /// <summary>
    /// Leet code #964. Least Operators to Express Number
    /// 
    /// Given a single positive integer x, we will write an expression of the 
    /// form x (op1) x (op2) x (op3) x ... where each operator op1, op2, etc. 
    /// is either addition, subtraction, multiplication, or division 
    /// (+, -, *, or /).  For example, with x = 3, we might write 
    /// 3 * 3 / 3 + 3 - 3 which is a value of 3.
    ///
    /// When writing such an expression, we adhere to the following conventions:
    ///
    /// The division operator (/) returns rational numbers.
    /// There are no parentheses placed anywhere.
    /// We use the usual order of operations: multiplication and division happens 
    /// before addition and subtraction.
    /// It's not allowed to use the unary negation operator (-).  For example, 
    /// "x - x" is a valid expression as it only uses subtraction, but "-x + x" 
    /// is not because it uses negation.
    /// We would like to write an expression with the least number of operators 
    /// such that the expression equals the given target.  Return the least number 
    /// of operators used.
    ///
    /// Example 1:
    /// Input: x = 3, target = 19
    /// Output: 5
    /// Explanation: 3 * 3 + 3 * 3 + 3 / 3.  The expression contains 5 operations.
    ///
    /// Example 2:
    /// Input: x = 5, target = 501
    /// Output: 8
    /// Explanation: 5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5.  The expression contains 
    /// 8 operations.
    ///
    /// Example 3:
    /// Input: x = 100, target = 100000000
    /// Output: 3
    /// Explanation: 100 * 100 * 100 * 100.  The expression contains 3 operations.
    ///  
    ///
    /// Note:
    /// 
    /// 1. 2 <= x <= 100
    /// 2. 1 <= target <= 2 * 10^8
    /// </summary>
    int leastOpsExpressTarget(int x, int target);

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
 
    /// <summary>
    /// Leet code #1000. Minimum Cost to Merge Stones
    /// </summary>
    int mergeStones(int i, int j, int m, int K, vector<vector<vector<int>>> &dp, vector<int> &sum);

    /// <summary>
    /// Leet code #1000. Minimum Cost to Merge Stones
    /// 
    /// There are N piles of stones arranged in a row.  The i-th pile has 
    /// stones[i] stones.
    ///
    /// A move consists of merging exactly K consecutive piles into one pile, 
    /// and the cost of this move is equal to the total number of stones in these 
    /// K piles.
    ///
    /// Find the minimum cost to merge all piles of stones into one pile.  If it 
    /// is impossible, return -1.
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: stones = [3,2,4,1], K = 2
    /// Output: 20
    /// Explanation: 
    /// We start with [3, 2, 4, 1].
    /// We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
    /// We merge [4, 1] for a cost of 5, and we are left with [5, 5].
    /// We merge [5, 5] for a cost of 10, and we are left with [10].
    /// The total cost was 20, and this is the minimum possible.
    ///
    /// Example 2:
    ///
    /// Input: stones = [3,2,4,1], K = 3
    /// Output: -1
    /// Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
    ///
    /// Example 3:
    ///
    /// Input: stones = [3,5,1,2,6], K = 3
    /// Output: 25
    /// Explanation: 
    /// We start with [3, 5, 1, 2, 6].
    /// We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
    /// We merge [3, 8, 6] for a cost of 17, and we are left with [17].
    /// The total cost was 25, and this is the minimum possible.
    ///  
    /// Note:
    /// 1. 1 <= stones.length <= 30
    /// 2. 2 <= K <= 30
    /// 3. 1 <= stones[i] <= 100
    /// </summary>
    int mergeStones(vector<int>& stones, int K);

    /// <summary>
    /// Leet code #1012. Numbers With Repeated Digits
    /// 
    /// Given a positive integer N, return the number of positive integers less 
    /// than or equal to N that have at least 1 repeated digit.
    ///
    /// Example 1:
    /// Input: 20
    /// Output: 1
    /// Explanation: The only positive number (<= 20) with at least 1 repeated 
    /// digit is 11.
    ///
    /// Example 2:
    /// Input: 100
    /// Output: 10
    /// Explanation: The positive numbers (<= 100) with atleast 1 repeated digit 
    /// are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
    ///
    /// Example 3:
    /// Input: 1000
    /// Output: 262
    /// 
    ///
    /// Note:
    ///
    /// 1 <= N <= 10^9
    /// </summary>
    int numDupDigitsAtMostN(int N);

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
    /// Leet code #1049. Last Stone Weight II
    /// 
    /// We have a collection of rocks, each rock has a positive integer weight.
    ///
    /// Each turn, we choose any two rocks and smash them together.  Suppose 
    /// the stones have weights x and y with x <= y.  The result of this smash is:
    ///
    /// If x == y, both stones are totally destroyed;
    /// If x != y, the stone of weight x is totally destroyed, and the stone of 
    /// weight y has new weight y-x.
    /// At the end, there is at most 1 stone left.  Return the smallest possible 
    /// weight of this stone (the weight is 0 if there are no stones left.)
    ///
    /// 
    /// Example 1:
    ///
    /// Input: [2,7,4,1,8,1]
    /// Output: 1
    /// Explanation: 
    /// We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
    /// we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
    /// we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
    /// we can combine 1 and 1 to get 0 so the array converts to [1] then that's the
    /// optimal value.
    /// 
    /// Note:
    /// 
    /// 1. 1 <= stones.length <= 30
    /// 2. 1 <= stones[i] <= 100
    /// </summary>
    int lastStoneWeightII(vector<int>& stones);

    /// <summary>
    /// Leet code #1049. Last Stone Weight II
    /// </summary>
    int lastStoneWeightIIA(vector<int>& stones);

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

    /// <summary>
    /// Leet code #1105. Filling Bookcase Shelves
    /// 
    /// We have a sequence of books: the i-th book has thickness books[i][0] 
    /// and height books[i][1].
    ///
    /// We want to place these books in order onto bookcase shelves that have 
    /// total width shelf_width.
    ///
    /// We choose some of the books to place on this shelf (such that the sum 
    /// of their thickness is <= shelf_width), then build another level of 
    /// shelf of the bookcase so that the total height of the bookcase has 
    /// increased by the maximum height of the books we just put down.  
    /// We repeat this process until there are no more books to place.
    ///
    /// Note again that at each step of the above process, the order of the 
    /// books we place is the same order as the given sequence of books.  
    /// For example, if we have an ordered list of 5 books, we might place 
    /// the first and second book onto the first shelf, the third book on the 
    /// second shelf, and the fourth and fifth book on the last shelf.
    ///
    /// Return the minimum possible height that the total bookshelf can be after 
    /// placing shelves in this manner.
    ///
    /// Example 1:
    ///
    ///
    /// Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
    /// Output: 6
    /// Explanation:
    /// The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
    /// Notice that book number 2 does not have to be on the first shelf.
    /// 
    ///
    /// Constraints:
    ///
    /// 1. 1 <= books.length <= 1000
    /// 2. 1 <= books[i][0] <= shelf_width <= 1000
    /// 3. 1 <= books[i][1] <= 1000
    /// </summary>
    int minHeightShelves(vector<vector<int>>& books, int shelf_width);

    /// <summary>
    /// Leet code #1125. Smallest Sufficient Team
    /// 
    /// In a project, you have a list of required skills req_skills, and a list 
    /// of people.  The i-th person people[i] contains a list of skills that 
    /// person has.
    /// Consider a sufficient team: a set of people such that for every required
    /// skill in req_skills, there is at least one person in the team who has 
    /// that skill.  We can represent these teams by the index of each person: 
    /// for example, team = [0, 1, 3] represents the people with skills people[0], 
    /// people[1], and people[3].
    /// Return any sufficient team of the smallest possible size, represented by 
    /// the index of each person.
    /// You may return the answer in any order.  It is guaranteed an answer exists.
    /// 
    /// Example 1:
    /// Input: req_skills = ["java","nodejs","reactjs"], 
    /// people = [["java"],["nodejs"],["nodejs","reactjs"]]
    /// Output: [0,2]
    ///
    /// Example 2:
    /// Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], 
    /// people = [["algorithms","math","java"],["algorithms","math","reactjs"],
    /// ["java","csharp","aws"],["reactjs","csharp"],
    /// ["csharp","math"],["aws","java"]]
    /// Output: [1,2]
    /// 
    /// Constraints:
    /// 1. 1 <= req_skills.length <= 16
    /// 2. 1 <= people.length <= 60
    /// 3. 1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
    /// 4. Elements of req_skills and people[i] are (respectively) distinct.
    /// 5. req_skills[i][j], people[i][j][k] are lowercase English letters.
    /// 6. It is guaranteed a sufficient team exists.
    /// </summary>
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people);

#pragma endregion

#pragma region BackTracking


    /// <summary>
    /// Palindrome Partitioning with cache
    /// </summary>
    vector<vector<string>> partitionPalindrome(string s, unordered_map<string, vector<vector<string>>> &partition);

    /// <summary>
    /// Leet code #131. Palindrome Partitioning       
    /// Given a string s, partition s such that every substring of the partition is a palindrome. 
    /// Return all possible palindrome partitioning of s. 
    /// For example, given s = "aab",
    /// Return 
    /// [
    ///  ["aa","b"],
    ///  ["a","a","b"]
    /// ]
    /// </summary>
    vector<vector<string>> partitionPalindrome(string s);

    /// <summary>
    /// Leet code #282. Expression Add Operators
    /// </summary>
    void calculate(vector<string> & result, string path, string num, 
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
    /// Leet code #473. Matchsticks to Square  
    /// </summary>
    bool nextside(vector<int>& nums, vector<int>& side, string &signature,
        int length, unordered_set<string>& dead_sig);

    /// <summary>
    /// Leet code #473. Matchsticks to Square  
    /// </summary>
    bool makeside(vector<int>& nums, vector<int>& side, int& sum, string &signature, 
        int start, int length, unordered_set<string>& dead_sig);

    /// <summary>
    /// Leet code #473. Matchsticks to Square  
    /// 
    /// Remember the story of Little Match Girl? By now, you know exactly what matchsticks the 
    /// little match girl has, please find out a way you can make one square by using up all 
    /// those matchsticks. You should not break any stick, but you can link them up, and 
    /// each matchstick must be used exactly one time.
    ///
    /// Your input will be several matchsticks the girl has, represented with their stick length. 
    /// Your output will either be true or false, to represent whether you could make one square 
    /// using all the matchsticks the little match girl has.
    /// Example 1:
    /// Input: [1,1,2,2,2]
    /// Output: true
    /// Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
    ///
    /// Example 2:
    /// Input: [3,3,3,3,4]
    /// Output: false
    /// Explanation: You cannot find a way to form a square with all the matchsticks.
    /// Note:
    /// 1.The length sum of the given matchsticks is in the range of 0 to 10^9. 
    /// 2.The length of the given matchstick array will not exceed 15.
    /// </summary>
    bool makesquare(vector<int>& nums);

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
    /// Leet code #140. Word Break II
    /// Recursive break the word according to dictionary, return word list 
    /// </summary>
    vector<string> wordBreakII(string s, unordered_set<string>& wordDict,
        unordered_map<string, vector<string>>&search_map);

    /// <summary>
    /// Leet code #140. Word Break II  
    /// Given a string s and a dictionary of words dict, add spaces in s to 
    /// construct a sentence where each word is a valid dictionary word. 
    /// Return all such possible sentences.
    /// For example, given
    /// s = "catsanddog",
    /// dict = ["cat", "cats", "and", "sand", "dog"]. 
    /// A solution is ["cats and dog", "cat sand dog"].
    /// </summary>
    vector<string> wordBreakII(string s, vector<string>& wordDictt);

    /// <summary>
    /// Leet code #247. Strobogrammatic Number II 
    /// </summary>
    void findStrobogrammatic(int i, int n, string& str, vector<string>& result, map<char, char>& num_map);

    /// <summary>
    /// Leet code #247. Strobogrammatic Number II 
    /// 
    /// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
    /// Find all strobogrammatic numbers that are of length = n. 
    /// For example,
    /// Given n = 2, return ["11","69","88","96"].
    /// Hint:
    /// 1.Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
    /// </summary>
    vector<string> findStrobogrammatic(int n);

    /// <summary>
    /// Leet code #248. Strobogrammatic Number III 
    /// </summary>
    void strobogrammaticInRange(int i, int n, string low, string high, string& str, int &count, map<char, char>& num_map);

    /// <summary>
    /// Leet code #248. Strobogrammatic Number III 
    /// 
    /// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
    /// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high. 
    /// For example,
    /// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers. 
    /// Note:
    /// Because the range might be a large number, the low and high numbers are represented as string.
    /// </summary>
    int strobogrammaticInRange(string low, string high);

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

    /// <summary>
    /// Leetcode #784. Letter Case Permutation
    ///
    /// Given a string S, we can transform every letter individually to be 
    /// lowercase or uppercase to create another string.  Return a list of 
    /// all possible strings we could create.
    ///
    /// Examples:
    /// Input: S = "a1b2"
    /// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
    ///
    /// Input: S = "3z4"
    /// Output: ["3z4", "3Z4"]
    ///
    /// Input: S = "12345"
    /// Output: ["12345"]
    /// Note:
    ///
    /// 1. S will be a string with length at most 12.
    /// 2. S will consist only of letters or digits.
    /// </summary>
    vector<string> letterCasePermutation(string S);
    
    /// <summary>
    /// Leet code #797. All Paths From Source to Target
    /// </summary>
    void allPathsSourceTarget(vector<vector<int>>& graph, vector<int> &path, unordered_set<int> &visited, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #797. All Paths From Source to Target
    /// 
    /// Given a directed, acyclic graph of N nodes.  Find all possible paths 
    /// from node 0 to node N-1, and return them in any order.
    ///
    /// The graph is given as follows:  the nodes are 0, 1, ..., 
    /// graph.length - 1.  graph[i] is a list of all nodes j for which the 
    /// edge (i, j) exists.
    ///
    /// Example:
    /// Input: [[1,2], [3], [3], []] 
    /// Output: [[0,1,3],[0,2,3]] 
    /// Explanation: The graph looks like this:
    /// 0--->1
    /// |    |
    /// v    v
    /// 2--->3
    /// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
    /// Note:
    ///
    /// 1. The number of nodes in the graph will be in the range [2, 15].
    /// 2. You can print different paths in any order, but you should keep the 
    ///    order of nodes inside one path.
    /// </summary>
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);

    /// <summary>
    /// Leet code #856. Score of Parentheses
    /// </summary>
    int scoreOfParentheses(string S, int &index);

    /// <summary>
    /// Leet code #856. Score of Parentheses
    /// 
    /// Given a balanced parentheses string S, compute the score of the 
    /// string based on the following rule:
    ///
    /// () has score 1
    /// AB has score A + B, where A and B are balanced parentheses strings.
    /// (A) has score 2 * A, where A is a balanced parentheses string.
    /// 
    /// Example 1:
    ///
    /// Input: "()"
    /// Output: 1
    ///
    /// Example 2:
    /// Input: "(())"
    /// Output: 2
    ///
    /// Example 3:
    /// Input: "()()"
    /// Output: 2
    ///
    /// Example 4:
    /// Input: "(()(()))"
    /// Output: 6
    ///
    /// Note:
    /// 1. S is a balanced parentheses string, containing only ( and ).
    /// 2. 2 <= S.length <= 50
    /// </summary>
    int scoreOfParentheses(string S);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    void robotClean(vector<vector<int>>& room, int row, int col);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    bool robotMove(vector<vector<int>>& room, int &row, int &col, int direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    int robotTurnRight(int direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    int robotTurnLeft(int direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    void robotMoveNext(vector<vector<int>>& room, unordered_map<int, unordered_set<int>>& visited, 
        int& row, int& col, int& direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// </summary>
    void robotMoveBack(vector<vector<int>>& room, unordered_map<int, unordered_set<int>>& visited, 
        int& row, int& col, int& direction);

    /// <summary>
    /// Leet code #489. Robot Room Cleaner
    /// 
    /// Given a robot cleaner in a room modeled as a grid.
    /// Each cell in the grid can be empty or blocked.
    ///
    /// The robot cleaner with 4 given APIs can move forward, turn left or turn 
    /// right. Each turn it made is 90 degrees.
    ///
    /// When it tries to move into a blocked cell, its bumper sensor detects 
    /// the obstacle and it stays on the current cell.
    ///
    /// Design an algorithm to clean the entire room using only the 4 given APIs 
    /// shown below.
    ///
    /// interface Robot {
    ///  // returns true if next cell is open and robot moves into the cell.
    ///  // returns false if next cell is obstacle and robot stays on the current 
    ///  // cell.
    ///  boolean move();
    ///
    ///  // Robot will stay on the same cell after calling turnLeft/turnRight.
    ///  // Each turn will be 90 degrees.
    ///  void turnLeft();
    ///  void turnRight();
    ///
    ///  // Clean the current cell.
    ///  void clean();
    /// }
    /// Example:
    ///
    /// Input:
    /// room = [
    ///  [1,1,1,1,1,0,1,1],
    ///  [1,1,1,1,1,0,1,1],
    ///  [1,0,1,1,1,1,1,1],
    ///  [0,0,0,1,0,0,0,0],
    ///  [1,1,1,1,1,1,1,1]
    /// ],
    /// row = 1,
    /// col = 3
    ///
    /// Explanation:
    /// All grids in the room are marked by either 0 or 1.
    /// 0 means the cell is blocked, while 1 means the cell is accessible.
    /// The robot initially starts at the position of row=1, col=3.
    /// From the top left corner, its position is one row below and three columns 
    /// right.
    /// Notes:
    ///
    /// The input is only given to initialize the room and the robot's position 
    /// internally. You must solve this problem "blindfolded". In other words, 
    /// you must control the robot using only the mentioned 4 APIs, without 
    /// knowing the room layout and the initial robot's position.
    /// The robot's initial position will always be in an accessible cell.
    /// The initial direction of the robot will be facing up.
    /// All accessible cells are connected, which means the all cells marked 
    /// as 1 will be accessible by the robot.
    /// Assume all four edges of the grid are all surrounded by wall.
    /// </summary>
    void cleanRoom(vector<vector<int>>& room, int row, int col);

    /// <summary>
    /// Leet code #980. Unique Paths III
    /// </summary>
    void uniquePathsIII(vector<vector<int>>& grid, stack<pair<int, int>> &path, 
        vector<vector<int>>& visited, int &remaining, int &result);

    /// <summary>
    /// Leet code #980. Unique Paths III
    /// 
    /// On a 2-dimensional grid, there are 4 types of squares:
    ///
    /// 1 represents the starting square.  There is exactly one starting square.
    /// 2 represents the ending square.  There is exactly one ending square.
    /// 0 represents empty squares we can walk over.
    /// -1 represents obstacles that we cannot walk over.
    /// Return the number of 4-directional walks from the starting square to the 
    /// ending square, that walk over every non-obstacle square exactly once.
    ///
    /// 
    /// Example 1:
    /// Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
    /// Output: 2
    /// Explanation: We have the following two paths: 
    /// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
    /// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
    ///
    /// Example 2:
    ///
    /// Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
    /// Output: 4
    /// Explanation: We have the following four paths: 
    /// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
    /// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
    /// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
    /// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
    ///
    /// Example 3:
    ///
    /// Input: [[0,1],[2,0]]
    /// Output: 0
    /// Explanation: 
    /// There is no path that walks over every empty square exactly once.
    /// Note that the starting and ending square can be anywhere in the grid.
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= grid.length * grid[0].length <= 20
    /// 2. Given a robot cleaner in a room modeled as a grid.
    /// </summary>
    int uniquePathsIII(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #996. Number of Squareful Arrays
    /// </summary>
    int numSquarefulPerms(vector<int>& A, vector<int> &path, vector<int> &visited, 
        int &result);

    /// <summary>
    /// Leet code #996. Number of Squareful Arrays
    /// 
    /// Given an array A of non-negative integers, the array is squareful if for 
    /// every pair of adjacent elements, their sum is a perfect square.
    ///
    /// Return the number of permutations of A that are squareful.  Two 
    /// permutations A1 and A2 differ if and only if there is some index i such 
    /// that A1[i] != A2[i].
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: [1,17,8]
    /// Output: 2
    /// Explanation: 
    /// [1,8,17] and [17,8,1] are the valid permutations.
    ///
    /// Example 2:
    ///
    /// Input: [2,2,2]
    /// Output: 1
    ///
    ///
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 12
    /// 2. 0 <= A[i] <= 1e9
    /// 3. On a 2-dimensional grid, there are 4 types of squares:
    /// </summary>
    int numSquarefulPerms(vector<int>& A);

    /// <summary>
    /// Leet code #1079. Letter Tile Possibilities
    /// </summary>
    int numTilePossibilities(string&word, string& tiles, vector<int> &visited);

    /// <summary>
    /// Leet code #1079. Letter Tile Possibilities
    /// 
    /// You have a set of tiles, where each tile has one letter tiles[i] printed 
    /// on it.  Return the number of possible non-empty sequences of letters you 
    /// can make.
    ///
    /// Example 1:
    /// Input: "AAB"
    /// Output: 8
    /// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", 
    /// "ABA", "BAA".
    ///
    /// Example 2:
    ///
    /// Input: "AAABBC"
    /// Output: 188
    /// Note:
    ///
    /// 1. 1 <= tiles.length <= 7
    /// 2. tiles consists of uppercase English letters.
    /// </summary>
    int numTilePossibilities(string tiles);

    /// <summary>
    /// Leet code #1087. Brace Expansion
    /// </summary>
    void expand(string path, string S, vector<string>& result);

    /// <summary>
    /// Leet code #1087. Brace Expansion
    /// 
    /// A string S represents a list of words.
    ///
    /// Each letter in the word has 1 or more options.  If there is one 
    /// option, the letter is represented as is.  If there is more than 
    /// one option, then curly braces delimit the options.  For example, 
    /// "{a,b,c}" represents options ["a", "b", "c"].
    ///
    /// For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", 
    /// "bde", "bdf", "cde", "cdf"].
    ///
    /// Return all words that can be formed in this manner, in lexicographical 
    /// order.
    /// 
    /// Example 1:
    /// Input: "{a,b}c{d,e}f"
    /// Output: ["acdf","acef","bcdf","bcef"]
    ///
    /// Example 2:
    /// Input: "abcd"
    /// Output: ["abcd"]
    ///
    /// Note:
    ///
    /// 1. 1 <= S.length <= 50
    /// 2. There are no nested curly brackets.
    /// </summary>
    vector<string> expand(string S);
       
    /// <summary>
    /// Leet code #1140. Stone Game II
    /// </summary>
    int stoneGameII(vector<int>& sum, int start, int M, vector<vector<int>> &memo);

    /// <summary>
    /// Leet code #1140. Stone Game II
    /// 
    /// Alex and Lee continue their games with piles of stones.  There are a 
    /// number of piles arranged in a row, and each pile has a positive 
    /// integer number of stones piles[i].  The objective of the game is to 
    /// end with the most stones. 
    ///
    /// Alex and Lee take turns, with Alex starting first.  Initially, M = 1.
    ///
    /// On each player's turn, that player can take all the stones in the 
    /// first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
    ///
    /// The game continues until all the stones have been taken.
    ///
    /// Assuming Alex and Lee play optimally, return the maximum number of 
    /// stones Alex can get.
    ///
    /// Example 1:
    /// Input: piles = [2,7,9,4,4]
    /// Output: 10
    /// Explanation:  If Alex takes one pile at the beginning, Lee takes two 
    /// piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles 
    /// in total. If Alex takes two piles at the beginning, then Lee can take 
    /// all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. 
    /// So we return 10 since it's larger. 
    /// 
    /// Constraints:
    /// 1. 1 <= piles.length <= 100
    /// 2. 1 <= piles[i] <= 10 ^ 4
    /// </summary>
    int stoneGameII(vector<int>& piles);

#pragma endregion
#pragma region Greedy
    /// <summary>
    /// LeetCode #56. Merge Intervals
    /// Given a collection of intervals, merge all overlapping intervals.
    /// For example,
    /// Given [1,3],[2,6],[8,10],[15,18],
    /// return [1,6],[8,10],[15,18]. 
    /// </summary>
    vector<Interval> mergeIntervals(vector<Interval>& intervals);

    /// <summary>
    /// Leet code #57. Insert Interval   
    /// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
    /// You may assume that the intervals were initially sorted according to their start times.
    ///
    /// Example 1:
    /// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9]. 
    ///
    /// Example 2:
    /// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16]. 
    /// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
    /// </summary>
    vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval);

    /// <summary>
    /// Leet code #330. Patching Array 
    ///
    /// Given a sorted positive integer array nums and an integer n, add/patch 
    /// elements to the array such that any number in range [1, n] inclusive 
    /// can be formed by the sum of some elements in the array. 
    /// Return the minimum number of patches required. 
    ///
    /// Example 1:
    /// nums = [1, 3], n = 6
    /// Return 1.
    /// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
    /// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
    /// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
    /// So we only need 1 patch.
    ///
    /// Example 2:
    /// nums = [1, 5, 10], n = 20
    /// Return 2.
    /// The two patches can be [2, 4].
    ///
    /// Example 3:
    /// nums = [1, 2, 2], n = 5
    /// Return 0.
    /// </summary>
    int minPatches(vector<int>& nums, int n);

    /// <summary>
    /// Leet code # 502. IPO  
    ///
    /// Suppose LeetCode will start its IPO soon. In order to sell a good price 
    /// of its shares to Venture Capital, LeetCode would like to work on some 
    /// projects to increase its capital before the IPO. Since it has limited 
    /// resources, it can only finish at most k distinct projects before the IPO. 
    /// Help LeetCode design the best way to maximize its total capital after 
    /// finishing at most k distinct projects. 
    ///
    /// You are given several projects. For each project i, it has a pure profit 
    /// Pi and a minimum capital of Ci is needed to start the corresponding project. 
    /// Initially, you have W capital. When you finish a project, you will obtain 
    /// its pure profit and the profit will be added to your total capital. 
    /// 
    /// To sum up, pick a list of at most k distinct projects from given projects 
    /// to maximize your final capital, and output your final maximized capital. 
    ///
    /// Example 1:
    ///
    /// Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
    ///
    /// Output: 4
    /// Explanation: Since your initial capital is 0, you can only start the project 
    /// indexed 0.
    /// After finishing it you will obtain profit 1 and your capital becomes 1.
    /// With capital 1, you can either start the project indexed 1 or the project indexed 2.
    /// Since you can choose at most 2 projects, you need to finish the project indexed 2 
    /// to get the maximum capital.
    /// Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
    /// Note:
    /// 1.You may assume all numbers in the input are non-negative integers.
    /// 2.The length of Profits array and Capital array will not exceed 50,000.
    /// 3.The answer is guaranteed to fit in a 32-bit signed integer.
    /// </summary>
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital);

    /// <summary>
    /// Leet code #253. Meeting Rooms II  
    /// 
    /// Given an array of meeting time intervals consisting of start 
    /// and end times [[s1,e1],[s2,e2],...] (si < ei), 
    /// find the minimum number of conference rooms required.
    /// For example,
    /// Given [[0, 30],[5, 10],[15, 20]],
    /// return 2. 
    /// </summary>
    int minMeetingRooms(vector<Interval>& intervals);

    /// <summary>
    /// Leet code #253. Meeting Rooms II  
    /// 
    /// Given an array of meeting time intervals consisting of start 
    /// and end times [[s1,e1],[s2,e2],...] (si < ei), 
    /// find the minimum number of conference rooms required.
    /// For example,
    /// Given [[0, 30],[5, 10],[15, 20]],
    /// return 2. 
    /// </summary>
    int minMeetingRoomsII(vector<Interval>& intervals);

    /// <summary>
    /// Leet code #435. Non-overlapping Intervals
    ///
    /// Given a collection of intervals, find the minimum number of intervals 
    /// you need to remove to make the rest of the intervals non-overlapping. 
    /// Note:
    /// You may assume the interval's end point is always bigger than its start point.
    /// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
    ///
    /// Example 1:
    /// Input: [ [1,2], [2,3], [3,4], [1,3] ]
    /// Output: 1
    /// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
    /// Example 2:
    /// Input: [ [1,2], [1,2], [1,2] ]
    /// Output: 2
    /// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
    /// Example 3:
    /// Input: [ [1,2], [2,3] ]
    /// Output: 0
    /// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
    /// </summary>
    int eraseOverlapIntervals(vector<Interval>& intervals);

    /// <summary>
    /// Leet code #436. Find Right Interval
    /// 
    /// Given a set of intervals, for each of the interval i, check if there exists an interval j 
    /// whose start point is bigger than or equal to the end point of the interval i, which can 
    /// be called that j is on the "right" of i. 
    ///
    /// For any interval i, you need to store the minimum interval j's index, which 
    /// means that the interval j has the minimum start point to build the "right" 
    /// relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. 
    /// Finally, you need output the stored value of each interval as an array. 
    ///
    /// Note:
    /// 1.You may assume the interval's end point is always bigger than its start point.
    /// 2.You may assume none of these intervals have the same start point.
    ///
    /// Example 1:
    /// Input: [ [1,2] ]
    /// Output: [-1]
    /// Explanation: There is only one interval in the collection, so it outputs -1.
    ///
    /// Example 2:
    /// Input: [ [3,4], [2,3], [1,2] ]
    /// Output: [-1, 0, 1]
    /// Explanation: There is no satisfied "right" interval for [3,4].
    /// For [2,3], the interval [3,4] has minimum-"right" start point;
    /// For [1,2], the interval [2,3] has minimum-"right" start point.
    ///
    /// Example 3:
    /// Input: [ [1,4], [2,3], [3,4] ]
    /// Output: [-1, 2, -1]
    /// Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
    /// For [2,3], the interval [3,4] has minimum-"right" start point.
    /// </summary>
    vector<int> findRightInterval(vector<Interval>& intervals);

    /// <summary>
    /// Leet code #452. Minimum Number of Arrows to Burst Balloons    
    /// 
    /// There are a number of spherical balloons spread in two-dimensional space. 
    /// For each balloon, provided input is the start and end coordinates of the 
    /// horizontal diameter. Since it's horizontal, y-coordinates don't matter 
    /// and hence the x-coordinates of start and end of the diameter suffice. 
    /// Start is always smaller than end. There will be at most 104 balloons.
    ///
    /// An arrow can be shot up exactly vertically from different points along 
    /// the x-axis. A balloon with xstart and xend bursts by an arrow shot at x 
    /// if xstart ≤ x ≤ xend. There is no limit to the number of arrows that 
    /// can be shot. An arrow once shot keeps travelling up infinitely. 
    /// The problem is to find the minimum number of arrows that must be 
    /// shot to burst all balloons. 
    /// Example: 
    /// Input:
    /// [[10,16], [2,8], [1,6], [7,12]]
    /// Output:
    /// 2
    /// Explanation:
    /// One way is to shoot one arrow for example at x = 6 (bursting the balloons 
    /// [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
    /// </summary>
    int findMinArrowShots(vector<pair<int, int>>& points);

    /// <summary>
    /// Leet code #218. The Skyline Problem    
    /// 
    /// A city's skyline is the outer contour of the silhouette formed 
    /// by all the buildings in that city when viewed from a distance. 
    /// Now suppose you are given the locations and height of all the buildings 
    /// as shown on a cityscape photo (Figure A), write a program to output 
    /// the skyline formed by these buildings collectively (Figure B).
    ///
    /// Buildings   Skyline Contour    
    /// The geometric information of each building is represented by a triplet of 
    /// integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left 
    /// and right edge of the ith building, respectively, and Hi is its height. 
    /// It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. 
    /// You may assume all buildings are perfect rectangles grounded on an absolutely 
    /// flat surface at height 0.
    ///
    /// For instance, the dimensions of all buildings in Figure A are recorded as: 
    /// [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
    /// The output is a list of "key points" (red dots in Figure B) in the format of 
    /// [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point 
    /// is the left endpoint of a horizontal line segment. Note that the last key point, 
    /// where the rightmost building ends, is merely used to mark the termination of the 
    /// skyline, and always has zero height. Also, the ground in between any two adjacent 
    /// buildings should be considered part of the skyline contour. 
    /// For instance, the skyline in Figure B should be represented as:
    /// [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
    /// Notes: 
    /// The number of buildings in any input list is guaranteed to be in the range [0, 10000].
    /// The input list is already sorted in ascending order by the left x position Li. 
    /// The output list must be sorted by the x position. 
    /// There must be no consecutive horizontal lines of equal height in the output skyline. 
    /// For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; 
    /// the three lines of height 5 should be merged into one in the final output 
    /// as such: [...[2 3], [4 5], [12 7], ...]
    /// </summary>
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings);

    /// <summary>
    /// Leet code #252. Meeting Rooms   
    /// 
    /// Given an array of meeting time intervals consisting of start and end times 
    /// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings. 
    /// distance between these two words in the list. 
    /// For example,
    /// Given [[0, 30],[5, 10],[15, 20]]. 
    /// return false. 
    /// </summary>
    bool canAttendMeetings(vector<Interval>& intervals);

    /// <summary>
    /// Leet code #334. Increasing Triplet Subsequence  
    /// 
    /// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array. 
    /// Formally the function should:
    /// Return true if there exists i, j, k  
    /// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 
    /// Your algorithm should run in O(n) time complexity and O(1) space complexity. 
    /// Examples:
    /// Given [1, 2, 3, 4, 5],
    ///  return true.
    /// Given [5, 4, 3, 2, 1],
    /// return false. 
    /// </summary>
    bool increasingTriplet(vector<int>& nums);

    /// <summary>
    /// Leet code 163. Missing Ranges 
    /// 
    /// Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], 
    /// return its missing ranges.
    /// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"]. 
    /// </summary>
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper);

    /// <summary>
    /// Leet code #495. Teemo Attacking   
    /// 
    /// In LLP world, there is a hero called Teemo and his attacking can make his enemy 
    /// Ashe be in poisoned condition. Now, given the Teemo's attacking ascending time 
    /// series towards Ashe and the poisoning time duration per Teemo's attacking, you 
    /// need to output the total time that Ashe is in poisoned condition. 
    ///
    /// You may assume that Teemo attacks at the very beginning of a specific time point, 
    /// and makes Ashe be in poisoned condition immediately.
    /// 
    /// Example 1: 
    /// Input: [1,4], 2
    /// Output: 4
    /// Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately. 
    /// This poisoned status will last 2 seconds until the end of time point 2. 
    /// And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds. 
    /// So you finally need to output 4.
    ///
    /// Example 2:
    /// Input: [1,2], 2
    /// Output: 3
    /// Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned. 
    /// This poisoned status will last 2 seconds until the end of time point 2. 
    /// However, at the beginning of time point 2, Teemo attacks Ashe again who is already in poisoned status. 
    /// Since the poisoned status won't add up together, though the second poisoning attack will still work at 
    /// time point 2, it will stop at the end of time point 3. 
    /// So you finally need to output 3.
    ///
    /// Note:
    /// 1.You may assume the length of given time series array won't exceed 10000.
    /// 2.You may assume the numbers in the Teemo's attacking time series and his 
    ///   poisoning time duration per attacking are non-negative integers, which 
    ///   won't exceed 10,000,000.
    /// </summary>
    int findPoisonedDuration(vector<int>& timeSeries, int duration);

    /// <summary>
    /// Leet code #554. Brick Wall  
    /// 
    /// There is a brick wall in front of you. The wall is rectangular and has 
    /// several rows of bricks. The bricks have the same height but different 
    /// width. You want to draw a vertical line from the top to the bottom and 
    /// cross the least bricks. 
    /// The brick wall is represented by a list of rows. Each row is a list of 
    /// integers representing the width of each brick in this row from left to 
    /// right. 
    /// If your line go through the edge of a brick, then the brick is not 
    /// considered as crossed. You need to find out how to draw the line to 
    /// cross the least bricks and return the number of crossed bricks. 
    /// You cannot draw a line just along one of the two vertical edges of the
    ///    wall, in which case the line will obviously cross no bricks. 
    /// Example:
    /// Input: 
    /// [[1,2,2,1],
    /// [3,1,2],
    /// [1,3,2],
    /// [2,4],
    /// [3,1,2],
    /// [1,3,1,1]]
    /// Output: 2
    /// Explanation: 
    /// Note:
    /// The width sum of bricks in different rows are the same and won't exceed 
    /// INT_MAX. 
    /// The number of bricks in each row is in range [1,10,000]. The height of 
    /// wall is in range [1,10,000]. Total number of bricks of the wall won't 
    /// exceed 20,000. 
    /// </summary>
    int leastBricks(vector<vector<int>>& wall);

    /// <summary>
    /// Leet code #598. Range Addition II   
    /// 
    /// Given an m * n matrix M initialized with all 0's and several update 
    /// operations.
    /// Operations are represented by a 2D array, and each operation is 
    /// represented by an array with two positive integers a and b, which 
    /// means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
    /// You need to count and return the number of maximum integers in the 
    /// matrix after performing all the operations.
    /// Example 1:
    /// Input: 
    /// m = 3, n = 3
    /// operations = [[2,2],[3,3]]
    /// Output: 4
    /// Explanation: 
    /// Initially, M = 
    /// [
    ///   [0, 0, 0],
    ///   [0, 0, 0],
    ///   [0, 0, 0]
    /// ]
    /// After performing [2,2], M = 
    /// [
    ///   [1, 1, 0],
    ///   [1, 1, 0],
    ///   [0, 0, 0]
    /// ]
    /// After performing [3,3], M = 
    /// [
    ///   [2, 2, 1],
    ///   [2, 2, 1],
    ///   [1, 1, 1]
    /// ]
    /// So the maximum integer in M is 2, and there are four of it in M. So 
    /// return 4.
    /// Note:
    /// The range of m and n is [1,40000].
    /// The range of a is [1,m], and the range of b is [1,n].
    /// The range of operations size won't exceed 10,000.
    /// </summary>
    int maxCount(int m, int n, vector<vector<int>>& ops);

    /// <summary>
    /// Leet code #621. Task Scheduler
    /// 
    /// Given a char array representing tasks CPU need to do. It contains 
    /// capital letters A to Z where different letters represent different 
    /// tasks. Tasks could be done without original order. Each task could 
    /// be done in one interval. For each interval, CPU could finish one 
    /// task or just be idle.    
    /// However, there is a non-negative cooling interval n that means 
    /// between two same tasks, there must be at least n intervals that 
    /// CPU are doing different tasks or just be idle. 
    /// You need to return the least number of intervals the CPU will take 
    /// to finish all the given tasks.
    ///
    /// Example 1:
    /// Input: tasks = ['A','A','A','B','B','B'], n = 2
    /// Output: 8
    /// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
    ///
    /// Note:
    /// 1.The number of tasks is in the range [1, 10000].
    /// 2.The integer n is in the range [0, 100].
    /// </summary>
    int leastInterval(vector<char>& tasks, int n);

    /// <summary>
    /// Leet code #630. Course Schedule III
    /// 
    /// There are n different online courses numbered from 1 to n. Each course 
    /// has some duration(course length) t and closed on dth day. A course 
    /// should be taken continuously for t days and must be finished before or 
    /// on the dth day. You will start at the 1st day. 
    ///
    /// Given n online courses represented by pairs (t,d), your task is to 
    /// find the maximal number of courses that can be taken. 
    /// Example:
    /// Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
    /// Output: 3
    /// Explanation: 
    /// There're totally 4 courses, but you can take 3 courses at most:
    /// First, take the 1st course, it costs 100 days so you will finish it on 
    /// the 100th day, and ready to take the next course on the 101st day.
    /// Second, take the 3rd course, it costs 1000 days so you will finish it 
    /// on the 1100th day, and ready to take the next course on the 1101st day. 
    /// Third, take the 2nd course, it costs 200 days so you will finish it on 
    /// the 1300th day. 
    /// The 4th course cannot be taken now, since you will finish it on the 
    /// 3300th day, which exceeds the closed date.
    /// Note:
    /// The integer 1 <= d, t, n <= 10,000. 
    /// You can't take two courses simultaneously.
    /// </summary>
    int scheduleCourse(vector<vector<int>>& courses);

    /// <summary>
    /// Leet code #646. Maximum Length of Pair Chain
    /// 
    /// You are given n pairs of numbers. In every pair, the first number is 
    /// always smaller than the second number.
    /// Now, we define a pair (c, d) can follow another pair (a, b) if and 
    /// only if b < c. Chain of pairs can be formed in this fashion.
    ///
    /// Given a set of pairs, find the length longest chain which can be 
    /// formed. You needn't use up all the given pairs. You can select pairs 
    /// in any order.
    ///
    /// Example 1:
    /// Input: [[1,2], [2,3], [3,4]]
    /// Output: 2
    /// Explanation: The longest chain is [1,2] -> [3,4]
    /// Note:
    /// The number of given pairs will be in the range [1, 1000].
    /// </summary>
    int findLongestChain(vector<vector<int>>& pairs);

    /// 
    /// On an infinite number line (x-axis), we drop given squares in the order 
    /// they are given.
    ///
    /// The i-th square dropped (positions[i] = (left, side_length)) is a 
    /// square with the left-most point being positions[i][0] and sidelength 
    /// positions[i][1].
    ///
    /// The square is dropped with the bottom edge parallel to the number line, 
    /// and from a higher height than all currently landed squares. We wait for 
    /// each square to stick before dropping the next.
    ///
    /// The squares are infinitely sticky on their bottom edge, and will remain 
    /// fixed to any positive length surface they touch (either the number line 
    /// or another square). Squares dropped adjacent to each other will not 
    /// stick together prematurely.
    ///
    /// Return a list ans of heights. Each height ans[i] represents the current 
    /// highest height of any square we have dropped, after dropping squares 
    /// represented by positions[0], positions[1], ..., positions[i].
    ///
    /// Example 1:
    /// Input: [[1, 2], [2, 3], [6, 1]]
    /// Output: [2, 5, 5]
    /// Explanation:
    ///
    /// After the first drop of 
    /// positions[0] = [1, 2]:
    /// _aa
    /// _aa
    /// -------
    /// The maximum height of any square is 2.
    ///
    /// After the second drop of 
    /// positions[1] = [2, 3]:
    /// __aaa
    /// __aaa
    /// __aaa
    /// _aa__
    /// _aa__
    /// --------------
    /// The maximum height of any square is 5.  
    /// The larger square stays on top of the smaller square despite where its 
    /// center of gravity is, because squares are infinitely sticky on their 
    /// bottom edge.
    ///
    /// After the third drop of 
    /// positions[1] = [6, 1]:
    /// __aaa
    /// __aaa
    /// __aaa
    /// _aa
    /// _aa___a
    /// --------------
    /// The maximum height of any square is still 5.
    ///
    /// Thus, we return an answer of 
    /// [2, 5, 5]
    ///
    /// Example 2:
    /// Input: [[100, 100], [200, 100]]
    /// Output: [100, 100]
    /// Explanation: Adjacent squares don't get stuck prematurely - only their 
    /// bottom edge can stick to surfaces.
    /// 
    /// Note:
    /// 1 <= positions.length <= 1000.
    /// 1 <= positions[i][0] <= 10^8.
    /// 1 <= positions[i][1] <= 10^6.
    /// </summary>

    /// <summary>
    /// Leet code #699. Falling Squares      
    /// </summary>
    map<int, int>::iterator findLocation(map<int, int>& pos_map, int pos);

    /// <summary>
    /// Leet code #699. Falling Squares      
    /// 
    /// On an infinite number line (x-axis), we drop given squares in the order 
    /// they are given.
    ///
    /// The i-th square dropped (positions[i] = (left, side_length)) is a 
    /// square with the left-most point being positions[i][0] and sidelength 
    /// positions[i][1].
    ///
    /// The square is dropped with the bottom edge parallel to the number line, 
    /// and from a higher height than all currently landed squares. We wait for 
    /// each square to stick before dropping the next.
    ///
    /// The squares are infinitely sticky on their bottom edge, and will remain 
    /// fixed to any positive length surface they touch (either the number line 
    /// or another square). Squares dropped adjacent to each other will not 
    /// stick together prematurely.
    ///
    /// Return a list ans of heights. Each height ans[i] represents the current 
    /// highest height of any square we have dropped, after dropping squares 
    /// represented by positions[0], positions[1], ..., positions[i].
    ///
    /// Example 1:
    /// Input: [[1, 2], [2, 3], [6, 1]]
    /// Output: [2, 5, 5]
    /// Explanation:
    ///
    /// After the first drop of 
    /// positions[0] = [1, 2]:
    /// _aa
    /// _aa
    /// -------
    /// The maximum height of any square is 2.
    ///
    /// After the second drop of 
    /// positions[1] = [2, 3]:
    /// __aaa
    /// __aaa
    /// __aaa
    /// _aa__
    /// _aa__
    /// --------------
    /// The maximum height of any square is 5.  
    /// The larger square stays on top of the smaller square despite where its 
    /// center of gravity is, because squares are infinitely sticky on their 
    /// bottom edge.
    ///
    /// After the third drop of 
    /// positions[1] = [6, 1]:
    /// __aaa
    /// __aaa
    /// __aaa
    /// _aa
    /// _aa___a
    /// --------------
    /// The maximum height of any square is still 5.
    ///
    /// Thus, we return an answer of 
    /// [2, 5, 5]
    ///
    /// Example 2:
    /// Input: [[100, 100], [200, 100]]
    /// Output: [100, 100]
    /// Explanation: Adjacent squares don't get stuck prematurely - only their 
    /// bottom edge can stick to surfaces.
    /// 
    /// Note:
    /// 1 <= positions.length <= 1000.
    /// 1 <= positions[i][0] <= 10^8.
    /// 1 <= positions[i][1] <= 10^6.
    /// </summary>
    vector<int> fallingSquares(vector<pair<int, int>>& positions);

    /// <summary>
    /// Leet code #757. Set Intersection Size At Least Two
    ///
    /// An integer interval [a, b] (for integers a < b) is a set of all 
    /// consecutive integers from a to b, including a and b.
    ///
    /// Find the minimum size of a set S such that for every integer interval 
    /// A in intervals, the intersection of S with A has size at least 2.
    ///
    /// Example 1:
    /// Input: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
    /// Output: 3
    /// Explanation:
    /// Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 
    /// elements from S in the interval.
    /// Also, there isn't a smaller size set that fulfills the above condition.
    /// Thus, we output the size of this set, which is 3.
    ///
    /// Example 2:
    /// Input: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
    /// Output: 5
    /// Explanation:
    /// An example of a minimum sized set is {1, 2, 3, 4, 5}.
    /// Note:
    /// 1. intervals will have length in range [1, 3000].
    /// 2. intervals[i] will have length 2, representing some integer interval.
    /// 3. intervals[i][j] will be an integer in [0, 10^8].
    /// </summary>
    int intersectionSizeTwo(vector<vector<int>>& intervals);

    /// <summary>
    /// Leet code #759. Employee Free Time    
    ///
    /// We are given a list schedule of employees, which represents the working 
    /// time for each employee.
    ///
    /// Each employee has a list of non-overlapping Intervals, and these 
    /// intervals are in sorted order.
    ///
    /// Return the list of finite intervals representing common, positive-length 
    /// free time for all employees, also in sorted order.
    /// 
    /// Example 1:
    /// Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
    /// Output: [[3,4]]
    /// Explanation:
    /// There are a total of three employees, and all common
    /// free time intervals would be [-inf, 1], [3, 4], [10, inf].
    /// We discard any intervals that contain inf as they aren't finite.
    /// Example 2:
    /// Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
    /// Output: [[5,6],[7,9]]
    /// (Even though we are representing Intervals in the form [x, y], the objects
    /// inside are Intervals, not lists or arrays. For example, 
    /// schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] 
    /// is not defined.)
    /// 
    /// Also, we wouldn't include intervals like [5, 5] in our answer, as they 
    /// have zero length.
    /// 
    /// Note:
    /// 1. schedule and schedule[i] are lists with lengths in range [1, 50].
    /// 2. 0 <= schedule[i].start < schedule[i].end <= 10^8.
    /// </summary>
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule);

    /// <summary>
    /// Leet code #850. Rectangle Area II
    /// 
    /// We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = 
    /// [x1, y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left 
    /// corner, and (x2, y2) are the coordinates of the top-right corner of the ith 
    /// rectangle.
    ///
    /// Find the total area covered by all rectangles in the plane.  Since the 
    /// answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
    /// Output: 6
    /// Explanation: As illustrated in the picture.
    ///
    /// Example 2:
    ///
    /// Input: [[0,0,1000000000,1000000000]]
    /// Output: 49
    /// Explanation: The answer is 10^18 modulo (10^9 + 7), 
    /// which is (10^9)^2 = (-7)^2 = 49.
    /// Note:
    ///
    /// 1 <= rectangles.length <= 200
    /// rectanges[i].length = 4
    /// 0 <= rectangles[i][j] <= 10^9
    /// The total area covered by all rectangles will never exceed 2^63 - 1 and 
    /// thus will fit in a 64-bit signed integer.
    /// </summary>
    int rectangleArea(vector<vector<int>>& rectangles);

    /// <summary>
    /// Leet code #948. Bag of Tokens
    /// 
    /// You have an initial power P, an initial score of 0 points, and a bag 
    /// of tokens.
    /// 
    /// Each token can be used at most once, has a value token[i], and has 
    /// potentially two ways to use it.
    ///
    /// If we have at least token[i] power, we may play the token face up, 
    /// losing token[i] power, and gaining 1 point.
    /// If we have at least 1 point, we may play the token face down, gaining 
    /// token[i] power, and losing 1 point.
    /// Return the largest number of points we can have after playing any 
    /// number of tokens.
    ///
    /// Example 1:
    ///
    /// Input: tokens = [100], P = 50
    /// Output: 0
    ///
    /// Example 2:
    ///
    /// Input: tokens = [100,200], P = 150
    /// Output: 1
    ///
    /// Example 3:
    ///
    /// Input: tokens = [100,200,300,400], P = 200
    /// Output: 2
    /// Note:
    ///
    /// 1. tokens.length <= 1000
    /// 2. 0 <= tokens[i] < 10000
    /// 3. 0 <= P < 10000
    /// </summary>
    int bagOfTokensScore(vector<int>& tokens, int P);

    /// <summary>
    /// Leet code #984. String Without AAA or BBB
    /// 
    /// Given two integers A and B, return any string S such that:
    /// S has length A + B and contains exactly A 'a' letters, and exactly 
    /// B 'b' letters;
    /// The substring 'aaa' does not occur in S;
    /// The substring 'bbb' does not occur in S.
    /// 
    /// Example 1:
    /// Input: A = 1, B = 2
    /// Output: "abb"
    /// Explanation: "abb", "bab" and "bba" are all correct answers.
    ///
    /// Example 2:
    /// Input: A = 4, B = 1
    /// Output: "aabaa"
    /// 
    /// Note:
    /// 1. 0 <= A <= 100
    /// 2. 0 <= B <= 100
    /// 3. It is guaranteed such an S exists for the given A and B.
    /// </summary>
    string strWithout3a3b(int A, int B);

    /// <summary>
    /// Leet code #986. Interval List Intersections
    /// 
    /// Given two lists of closed intervals, each list of intervals is 
    /// pairwise disjoint and in sorted order.
    ///
    /// Return the intersection of these two interval lists.
    ///
    /// (Formally, a closed interval [a, b] (with a <= b) denotes the 
    /// set of real numbers x with a <= x <= b.  The intersection of two 
    /// closed intervals is a set of real numbers that is either empty, or 
    /// can be represented as a closed interval.  For example, the 
    /// intersection of [1, 3] and [2, 4] is [2, 3].)
    ///
    /// Example 1:
    /// Input: A = [[0,2],[5,10],[13,23],[24,25]],
    /// B = [[1,5],[8,12],[15,24],[25,26]]
    /// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
    /// Reminder: The inputs and the desired output are lists of Interval 
    /// objects, and not arrays or lists.
    ///
    /// Note:
    /// 1. 0 <= A.length < 1000
    /// 2. 0 <= B.length < 1000
    /// 3. 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
    /// </summary>
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B);

    /// <summary>
    /// Leet code #1024. Video Stitching
    /// 
    /// You are given a series of video clips from a sporting event that lasted T 
    /// seconds.  These video clips can be overlapping with each other and have 
    /// varied lengths.
    ///
    /// Each video clip clips[i] is an interval: it starts at time clips[i][0] and 
    /// ends at time clips[i][1].  We can cut these clips into segments freely: 
    /// for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + 
    /// [3, 7].
    ///
    /// Return the minimum number of clips needed so that we can cut the clips into
    /// segments that cover the entire sporting event ([0, T]).  If the task is 
    /// impossible, return -1.
    ///
    /// Example 1:
    ///
    /// Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
    /// Output: 3
    /// Explanation: 
    /// We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
    /// Then, we can reconstruct the sporting event as follows:
    /// We cut [1,9] into segments [1,2] + [2,8] + [8,9].
    /// Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event
    /// [0, 10].
    ///
    /// Example 2:
    ///
    /// Input: clips = [[0,1],[1,2]], T = 5
    /// Output: -1
    /// Explanation: 
    /// We can't cover [0,5] with only [0,1] and [0,2].
    ///
    /// Example 3:
    ///
    /// Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],
    /// [1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
    /// Output: 3
    /// Explanation: 
    /// We can take clips [0,4], [4,7], and [6,9].
    ///
    /// Example 4:
    ///
    /// Input: clips = [[0,4],[2,8]], T = 5
    /// Output: 2
    /// Explanation: 
    /// Notice you can have extra video after the event ends.
    /// 
    /// 
    /// Note:
    /// 1. 1 <= clips.length <= 100
    /// 2. 0 <= clips[i][0], clips[i][1] <= 100
    /// 3. 0 <= T <= 100
    /// </summary>
    int videoStitching(vector<vector<int>>& clips, int T);

    /// <summary>
    /// Leet code #1054. Distant Barcodes
    /// 
    /// In a warehouse, there is a row of barcodes, where the i-th barcode is 
    /// barcodes[i].
    ///
    /// Rearrange the barcodes so that no two adjacent barcodes are equal.  You 
    /// may return any answer, and it is guaranteed an answer exists.
    ///
    /// Example 1:
    ///
    /// Input: [1,1,1,2,2,2]
    /// Output: [2,1,2,1,2,1]
    ///
    /// Example 2:
    ///
    /// Input: [1,1,1,1,2,2,3,3]
    /// Output: [1,3,1,3,2,1,2,1]
    /// Note:
    ///
    /// 1. 1 <= barcodes.length <= 10000
    /// 2. 1 <= barcodes[i] <= 10000
    /// </summary>
    vector<int> rearrangeBarcodes(vector<int>& barcodes);

    /// <summary>
    /// Leet code #1094. Car Pooling
    /// 
    /// You are driving a vehicle that has capacity empty seats initially 
    /// available for passengers.  The vehicle only drives east (ie. it 
    /// cannot turn around and drive west.)
    ///
    /// Given a list of trips, trip[i] = [num_passengers, start_location, 
    /// end_location] contains information about the i-th trip: the number 
    /// of passengers that must be picked up, and the locations to pick them 
    /// up and drop them off.  The locations are given as the number of 
    /// kilometers due east from your vehicle's initial location.
    ///
    /// Return true if and only if it is possible to pick up and drop off all 
    /// passengers for all the given trips. 
    /// 
    /// Example 1:
    /// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
    /// Output: false
    ///
    /// Example 2:
    /// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
    /// Output: true
    ///
    /// Example 3:
    /// Input: trips = [[2,1,5],[3,5,7]], capacity = 3
    /// Output: true
    ///
    /// Example 4:
    /// Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
    /// Output: true
    /// 
    /// Constraints:
    /// 1. trips.length <= 1000
    /// 2. trips[i].length == 3
    /// 3. 1 <= trips[i][0] <= 100
    /// 4. 0 <= trips[i][1] < trips[i][2] <= 1000
    /// 5. 1 <= capacity <= 100000
    /// </summary>
    bool carPooling(vector<vector<int>>& trips, int capacity);

    /// <summary>
    /// Leet code #1109. Corporate Flight Bookings
    /// 
    /// There are n flights, and they are labeled from 1 to n.
    /// We have a list of flight bookings.  The i-th booking 
    /// bookings[i] = [i, j, k] means that we booked k seats from flights 
    /// labeled i to j inclusive.
    ///
    /// Return an array answer of length n, representing the number of seats 
    /// booked on each flight in order of their label.
    ///
    /// Example 1:
    ///
    /// Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
    /// Output: [10,55,45,25,25]
    ///  
    /// Constraints:
    /// 1. 1 <= bookings.length <= 20000
    /// 2. 1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
    /// 3. 1 <= bookings[i][2] <= 10000
    /// </summary>
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n);

    /// <summary>
    /// Leet code #358. Rearrange String k Distance Apart   
    /// 
    /// Given a non-empty string s and an integer k, rearrange the string such 
    /// that the same characters are at least distance k from each other. 
    /// All input strings are given in lowercase letters. If it is not possible 
    /// to rearrange the string, return an empty string "". 
    ///
    /// Example 1:
    /// s = "aabbcc", k = 3
    /// Result: "abcabc"
    /// The same letters are at least distance 3 from each other.
    ///
    /// Example 2:
    /// s = "aaabc", k = 3 
    /// Answer: ""
    /// It is not possible to rearrange the string.
    ///
    /// Example 3:
    /// s = "aaadbbcc", k = 2
    /// Answer: "abacabcd"
    /// Another possible answer is: "abcabcda"
    /// The same letters are at least distance 2 from each other.
    /// </summary>
    string rearrangeString(string s, int k);

    /// <summary>
    /// Leet code #9906. Arrange operations      
    ///
    /// Assume we have N operations should be arrange in a certain time range. 
    /// Each operation will use some resources, each resource is exclusive, 
    /// which means one resource is used by a operation at any time it will
    /// not be used by another operation in that time frame. If two operations
    /// do not have any conflict resources, they can be done in parallel.
    ///
    /// Please work out the shortest time we can complete all the operations
    /// 
    /// Notes
    /// 1. The input is given as a list of array as O, in each O[i], the first 
    ///    element is the time how long the operation will complete, the remaining
    ///    k elements indidicate whether the operation will require a specific 
    ///    resource R[i-1], 0 means it does not require resource R[i-1], 
    ///    1 means it requires resource R[i-1].
    /// 2. Each resource will be used during the whole period of the operation.
    /// 3. To simplify the problem we assume we start as time 0 and time is an 
    ///    integer.
    /// </summary>
    /// <analysis>
    /// This is a schedule problem which is similar to leetcode 358. The only       
    /// difference is that we now have multiple resources, instead only one in 
    /// leetcode 358.
    /// We can do in the following steps.
    /// 1. We accumulate total utilization for each resource, each resource will
    ///    have a available time, which is 0 and the total requested time.
    /// 2. For any operation, the earliest time to start this operation is the 
    ///    maximum available time it utilized.
    /// 3. We scan on all the unvisited operation, pick the earliest time to start.
    ///    if both operations start at the same time, we will pick the one utilized
    ///    the busiest resource.
    /// 4. After we finally select an operation, we adjust the available time
    ///    and the request time for all the resources utilized in this operation.
    /// 5. Repeat #3 and #4 until all the operations have been completed.
    /// </analysis>
    int arrangeOperations(vector<vector<int>> operations);
#pragma endregion


#pragma region Sort
    /// <summary>
    /// Leet code #164. Maximum Gap 
    /// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
    /// Try to solve it in linear time/space.
    /// Return 0 if the array contains less than 2 elements.
    /// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    /// </summary>
    int maximumGap(vector<int>& nums);

    /// <summary>
    /// Leet code #75. Sort Colors   
    /// Given an array with n objects colored red, white or blue, sort them so that objects of 
    /// the same color are adjacent, with the colors in the order red, white and blue. 
    /// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.  
    /// Note:
    /// You are not suppose to use the library's sort function for this problem.  
    /// Follow up:
    /// A rather straight forward solution is a two-pass algorithm using counting sort.
    /// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, 
    /// then 1's and followed by 2's.
    /// Could you come up with an one-pass algorithm using only constant space?
    /// </summary>
    void sortColors(vector<int>& nums);

    /// <summary>
    /// Leet code #274. H-Index 
    /// Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.  
    /// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at 
    /// least h citations each, and the other N − h papers have no more than h citations each." 
    /// For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of 
    /// them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 
    /// citations each and the remaining two with no more than 3 citations each, his h-index is 3. 
    /// Note: If there are several possible values for h, the maximum one is taken as the h-index. 
    /// Hint:
    /// 1.An easy approach is to sort the array first.
    /// 2.What are the possible values of h-index?
    /// 3.A faster approach is to use extra space.
    /// </summary>
    int hIndex(vector<int>& citations);

    /// <summary>
    /// Leet code #324. Wiggle Sort II  
    /// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3].... 
    /// Example:
    /// (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
    /// (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2]. 
    /// Note:
    /// You may assume all input has valid answer. 
    /// Follow Up:
    /// Can you do it in O(n) time and/or in-place with O(1) extra space? 
    /// </summary>
    void wiggleSortII(vector<int>& nums);

    /// <summary>
    /// Leet code #179. Largest Number        
    /// Given a list of non negative integers, arrange them such that they form the largest number.  
    /// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
    /// Note: The result may be very large, so you need to return a string instead of an integer.
    /// </summary>
    string largestNumber(vector<int>& nums);

    /// <summary>
    /// Leet code #456. 132 Pattern
    /// Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence 
    /// ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes 
    /// a list of n numbers as input and checks whether there is a 132 pattern in the list.
    /// Note: n will be less than 15,000.    
    /// Example 1:
    /// Input: [1, 2, 3, 4]
    /// Output: False
    /// Explanation: There is no 132 pattern in the sequence.
    ///
    /// Example 2:
    /// Input: [3, 1, 4, 2]
    /// Output: True
    /// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
    /// Example 3:
    /// Input: [-1, 3, 2, 0]
    /// Output: True
    /// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
    /// </summary>
    bool find132pattern(vector<int>& nums);

    /// <summary>
    /// Leet code #406. Queue Reconstruction by Height 
    /// Suppose you have a random list of people standing in a queue. Each person is described 
    /// by a pair of integers (h, k), where h is the height of the person and k is the number 
    /// of people in front of this person who have a height greater than or equal to h. Write 
    /// an algorithm to reconstruct the queue. 
    ///
    /// Note:
    /// The number of people is less than 1,100. 
    ///
    /// Example 
    /// Input:
    /// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    ///
    /// Output:
    /// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
    /// </summary>
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people);

    /// <summary>
    /// Leet code #220. Contains Duplicate III
    /// Given an array of integers, find out whether there are two distinct 
    /// indices i and j in the array such that the difference between 
    /// nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
    /// </summary>
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// 
    /// You are given an integer array nums and you have to return a new counts array. 
    /// The counts array has the property where counts[i] is the number of smaller 
    /// elements to the right of nums[i]. 
    /// Example:
    /// Given nums = [5, 2, 6, 1]
    /// To the right of 5 there are 2 smaller elements (2 and 1).
    /// To the right of 2 there is only 1 smaller element (1).
    /// To the right of 6 there is 1 smaller element (1).
    /// To the right of 1 there is 0 smaller element.
    /// Return the array [2, 1, 1, 0]. 
    /// </summary>
    vector<int> countSmallerII(vector<int>& nums);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// </summary>
    void addBIT(int index, vector<int>& accu_slot);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// </summary>
    int sumBIT(int index, vector<int>& accu_slot);

    /// <summary>
    /// Leet code #315. Count of Smaller Numbers After Self  
    /// 
    /// You are given an integer array nums and you have to return a new counts array. 
    /// The counts array has the property where counts[i] is the number of smaller 
    /// elements to the right of nums[i]. 
    /// Example:
    /// Given nums = [5, 2, 6, 1]
    /// To the right of 5 there are 2 smaller elements (2 and 1).
    /// To the right of 2 there is only 1 smaller element (1).
    /// To the right of 6 there is 1 smaller element (1).
    /// To the right of 1 there is 0 smaller element.
    /// Return the array [2, 1, 1, 0]. 
    /// </summary>
    vector<int> countSmallerIV(vector<int>& nums);

    /// <summary>
    /// Leet code #280. Wiggle Sort      
    /// 
    /// Given an unsorted array nums, reorder it in-place such that 
    /// nums[0] <= nums[1] >= nums[2] <= nums[3].... 
    /// For example, given nums = [3, 5, 2, 1, 6, 4], 
    /// one possible answer is [1, 6, 2, 5, 3, 4].
    /// </summary>
    void wiggleSort(vector<int>& nums);

    /// <summary>
    /// Leet code #496. Next Greater Element I
    ///
    /// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements 
    /// are subset of nums2. Find all the next greater numbers for nums1's elements in the 
    /// corresponding places of nums2. 
    /// 
    /// The Next Greater Number of a number x in nums1 is the first greater number to its right 
    /// in nums2. If it does not exist, output -1 for this number. 
    /// 
    /// Example 1:
    /// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
    /// Output: [-1,3,-1]
    /// Explanation:
    /// For number 4 in the first array, you cannot find the next greater number for it in 
    /// the second array, so output -1.
    /// For number 1 in the first array, the next greater number for it in the second array is 3.
    /// For number 2 in the first array, there is no next greater number for it in the second array, 
    /// so output -1.
    ///
    /// Example 2:
    ///
    /// Input: nums1 = [2,4], nums2 = [1,2,3,4].
    /// Output: [3,-1]
    /// Explanation:
    /// For number 2 in the first array, the next greater number for it in the second array is 3.
    /// For number 4 in the first array, there is no next greater number for it in the second array, 
    /// so output -1.
    ///  
    /// Note:
    ///
    /// 1.All elements in nums1 and nums2 are unique.
    /// 2.The length of both nums1 and nums2 would not exceed 1000.
    /// </summary>
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums);

    /// <summary>
    /// Leet code #503. Next Greater Element II
    ///
    /// Given a circular array (the next element of the last element is the 
    /// first element of the array), print the Next Greater Number for 
    /// every element. The Next Greater Number of a number x is the first 
    /// greater number to its traversing-order next in the array, which means 
    /// you could search circularly to find its next greater number. If it 
    /// doesn't exist, output -1 for this number. 
    ///
    /// Example 1:
    ///
    /// Input: [1,2,1]
    /// Output: [2,-1,2]
    /// Explanation: The first 1's next greater number is 2; 
    /// The number 2 can't find next greater number; 
    /// The second 1's next greater number needs to search circularly, which is also 2.
    /// </summary>
    vector<int> nextGreaterElements(vector<int>& nums);

    /// <summary>
    /// Leet code # 440. K-th Smallest in Lexicographical Order  
    ///
    /// Given integers n and k, find the lexicographically k-th smallest 
    /// integer in the range from 1 to n. 
    /// Note: 1 ≤ k ≤ n ≤ 109.
    /// 
    /// Example: 
    /// Input:
    /// n: 13   k: 2
    ///
    /// Output:
    /// 10
    /// 
    /// Explanation:
    /// The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], 
    /// so the second smallest number is 10.
    /// </summary>
    int findKthNumber(int n, int k);

    /// <summary>
    /// Leet code #480. Sliding Window Median
    ///
    /// Median is the middle value in an ordered integer list. If the size of 
    /// the list is even, there is no middle value. So the median is the mean 
    /// of the two middle value.
    /// Examples: 
    /// [2,3,4] , the median is 3
    /// [2,3], the median is (2 + 3) / 2 = 2.5 
    /// Given an array nums, there is a sliding window of size k which is 
    /// moving from the very left of the array to the very right. You can 
    /// only see the k numbers in the window. Each time the sliding window 
    /// moves right by one position. Your job is to output the median array 
    /// for each window in the original array.
    ///
    /// For example,
    /// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
    /// Window position                Median
    /// ---------------               -----
    /// [1  3  -1] -3  5  3  6  7       1
    /// 1 [3  -1  -3] 5  3  6  7       -1
    /// 1  3 [-1  -3  5] 3  6  7       -1
    /// 1  3  -1 [-3  5  3] 6  7       3
    /// 1  3  -1  -3 [5  3  6] 7       5
    /// 1  3  -1  -3  5 [3  6  7]      6
    ///
    /// Therefore, return the median sliding window as [1,-1,-1,3,5,6].
    /// Note: 
    /// You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty 
    /// array.
    /// </summary>
    vector<double> medianSlidingWindow(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #556. Next Greater Element III  
    /// 
    /// Given a positive 32-bit integer n, you need to find the smallest 32-bit 
    /// integer which has exactly the same digits existing in the integer n and 
    /// is greater in value than n. If no such positive 32-bit integer exists, 
    /// you need to return -1.
    /// Example 1:
    /// Input: 12
    /// Output: 21
    ///
    /// Example 2:
    /// Input: 21
    /// Output: -1
    /// </summary>
    int nextGreaterElement(int n);

    /// <summary>
    /// Leet code #321. Create Maximum Number 
    /// </summary>
    string createMaxNumber(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #321. Create Maximum Number 
    /// </summary>
    void createMaxNumber(string num1, string num2, string& result);

    /// <summary>
    /// Leet code #321. Create Maximum Number 
    /// 
    /// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of 
    /// length k <= m + n from digits of the two. The relative order of the digits from the same array must be 
    /// preserved. Return an array of the k digits. You should try to optimize your time and space complexity. 
    /// Example 1: 
    /// nums1 = [3, 4, 6, 5]
    /// nums2 = [9, 1, 2, 5, 8, 3] 
    /// k = 5
    /// return [9, 8, 6, 5, 3]
    /// 
    /// Example 2:
    /// nums1 = [6, 7]
    /// nums2 = [6, 0, 4]
    /// k = 5
    /// return [6, 7, 6, 0, 4] 
    /// 
    /// Example 3:
    /// nums1 = [3, 9]
    /// nums2 = [8, 9]
    /// k = 3
    /// return [9, 8, 9]
    /// </summary>
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);

    /// <summary>
    /// Leet code #555. Split Assembled Strings 
    /// 
    /// Given a list of strings, you could assemble these strings together into 
    /// a loop. Among all the possible loops, you need to find the 
    /// lexicographically biggest string after cutting and making one 
    /// breakpoint of the loop, which will make a looped string into a regular one.
    ///
    /// So, to find the lexicographically biggest string, you need to experience 
    /// two phases: 
    /// 1.Assemble all the strings into a loop, where you can reverse some strings 
    ///   or not and connect them in the same order as given.
    /// 2.Cut and make one breakpoint in any place of the loop, which will make a 
    ///   looped string into a regular string starting from the character at the 
    ///   cutting point. 
    /// And your job is to find the lexicographically biggest one among all the 
    /// regular strings.
    /// 
    /// Example:
    /// Input: "abc", "xyz"
    /// Output: "zyxcba"
    /// Explanation: You can get the looped string "-abcxyz-", "-abczyx-", 
    /// "-cbaxyz-", "-cbazyx-", 
    /// where '-' represents the looped status. 
    /// The answer string came from the fourth looped one, 
    /// where you could cut from the middle and get "zyxcba".
    /// Note:
    /// 1.The input strings will only contain lowercase letters.
    /// 2.The total length of all the strings will not over 1000.
    /// </summary>
    string splitLoopedString(vector<string>& strs);

    /// <summary>
    /// Leet code #561. Array Partition I Add to List       
    /// 
    /// Given an array of 2n integers, your task is to group these integers 
    /// into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which 
    /// makes sum of min(ai, bi) for all i from 1 to n as large as possible.
    ///
    /// Example 1:
    /// Input: [1,4,3,2]
    ///
    /// Output: 4
    /// Explanation: n is 2, and the maximum sum of pairs is 4.
    /// Note:
    /// n is a positive integer, which is in the range of [1, 10000].
    /// All the integers in the array will be in the range of [-10000, 10000].
    /// </summary>
    int arrayPairSum(vector<int>& nums);

    /// <summary>
    /// Leet code #581. Shortest Unsorted Continuous Subarray
    /// Given an integer array, you need to find one continuous subarray that 
    /// if you only sort this subarray in ascending order, then the whole 
    /// array will be sorted in ascending order, too. 
    /// 
    /// You need to find the shortest such subarray and output its length.
    /// Example 1:
    /// 
    /// Input: [2, 6, 4, 8, 10, 9, 15]
    /// Output: 5
    /// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to 
    /// make the whole array sorted in ascending order.
    /// Note:
    /// 1.Then length of the input array is in range [1, 10,000].
    /// 2.The input array may contain duplicates, so ascending order here means 
    /// <=. 
    /// </summary>
    int findUnsortedSubarray(vector<int>& nums);

    /// <summary>
    /// Leet code #665. Non-decreasing Array
    /// 
    /// Given an array with n integers, your task is to check if it could 
    /// become non-decreasing by modifying at most 1 element. 
    /// We define an array is non-decreasing if array[i] <= array[i + 1] holds 
    /// for every i (1 <= i < n). 
    /// Example 1:
    /// Input: [4,2,3]
    /// Output: True
    /// Explanation: You could modify the first 
    /// 4
    /// to 
    /// 1
    /// to get a non-decreasing array.
    ///
    /// Example 2:
    /// Input: [4,2,1]
    /// Output: False
    /// Explanation: You can't get a non-decreasing array by modify at most one 
    /// element.
    /// 
    /// Note: The n belongs to [1, 10,000]. 
    /// </summary>
    bool checkPossibility(vector<int>& nums);

    /// <summary>
    /// Leet code #692. Top K Frequent Words
    ///
    /// Given a non-empty list of words, return the k most frequent elements.
    /// Your answer should be sorted by frequency from highest to lowest. If 
    /// two words have the same frequency, then the word with the lower 
    /// alphabetical order comes first.
    ///
    /// Example 1:
    /// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
    /// Output: ["i", "love"]
    /// Explanation: "i" and "love" are the two most frequent words.
    /// Note that "i" comes before "love" due to a lower alphabetical order.
    /// Example 2:
    /// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", 
    /// "is", "is"], k = 4
    /// Output: ["the", "is", "sunny", "day"]
    /// Explanation: "the", "is", "sunny" and "day" are the four most frequent 
    /// words, with the number of occurrence being 4, 3, 2 and 1 respectively.
    /// Note:
    /// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    /// Input words contain only lowercase letters.
    /// Follow up:
    /// 1. Try to solve it in O(n log k) time and O(n) extra space.
    /// 2. Can you solve it in O(n) time with only O(k) extra space?
    /// </summary>
    vector<string> topKFrequent(vector<string>& words, int k);

    /// <summary>
    /// Leet code #738. Monotone Increasing Digits
    ///
    /// Given a non-negative integer N, find the largest number that is less than 
    /// or equal to N with monotone increasing digits.
    ///
    /// (Recall that an integer has monotone increasing digits if and only if each 
    /// pair of adjacent digits x and y satisfy x <= y.)
    /// 
    /// Example 1:
    /// Input: N = 10
    /// Output: 9
    /// Example 2:
    /// Input: N = 1234
    /// Output: 1234
    /// Example 3:
    /// Input: N = 332
    /// Output: 299
    /// Note: N is an integer in the range [0, 10^9].
    /// </summary>
    int monotoneIncreasingDigits(int N);

    /// <summary>
    /// Leet code #744. Find Smallest Letter Greater Than Target
    ///
    /// Given a list of sorted characters letters containing only lowercase 
    /// letters, and given a target letter target, find the smallest element 
    /// in the list that is larger than the given target.
    ///
    /// Letters also wrap around. For example, if the target is target = 'z' 
    /// and letters = ['a', 'b'], the answer is 'a'.
    ///
    /// Examples:
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "a"
    /// Output: "c"
    ///
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "c"
    /// Output: "f"
    ///  
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "d"
    /// Output: "f"
    ///
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "g"
    /// Output: "j"
    ///
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "j"
    /// Output: "c"
    ///
    /// Input:
    /// letters = ["c", "f", "j"]
    /// target = "k"
    /// Output: "c"
    /// Note:
    /// 1. letters has a length in range [2, 10000].
    /// 2. letters consists of lowercase letters, and contains at least 2 
    /// unique letters.
    /// target is a lowercase letter.
    /// </summary> 
    char nextGreatestLetter(vector<char>& letters, char target);

    /// <summary>
    /// Leet code #769. Max Chunks To Make Sorted   
    ///
    /// Given an array arr that is a permutation of 
    /// [0, 1, ..., arr.length - 1], we split the array into some number of 
    /// "chunks" (partitions), and individually sort each chunk.  After 
    /// concatenating them, the result equals the sorted array.
    ///
    /// What is the most number of chunks we could have made?
    ///
    /// Example 1:
    ///
    /// Input: arr = [4,3,2,1,0]
    /// Output: 1
    /// Explanation:
    /// Splitting into two or more chunks will not return the required result.
    /// For example, splitting into [4, 3], [2, 1, 0] will result in 
    /// [3, 4, 0, 1, 2], which isn't sorted.
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,0,2,3,4]
    /// Output: 4
    /// Explanation:
    /// We can split into two chunks, such as [1, 0], [2, 3, 4].
    /// However, splitting into [1, 0], [2], [3], [4] is the highest number of
    /// chunks possible.
    /// Note:
    /// arr will have length in range [1, 10].
    /// arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
    /// </summary>
    int maxChunksToSorted(vector<int>& arr);

    /// <summary>
    /// Leetcode #768. Max Chunks To Make Sorted II
    ///
    /// This question is the same as "Max Chunks to Make Sorted" except the 
    /// integers of the given array are not necessarily distinct, the input 
    /// array could be up to length 2000, and the elements could be up to 
    /// 10**8.
    ///
    /// Given an array arr of integers (not necessarily distinct), we split 
    /// the array into some number of "chunks" (partitions), and individually 
    /// sort each chunk.  After concatenating them, the result equals the 
    /// sorted array.
    ///
    /// What is the most number of chunks we could have made?
    ///
    /// Example 1:
    ///
    /// Input: arr = [5,4,3,2,1]
    /// Output: 1
    /// Explanation:
    /// Splitting into two or more chunks will not return the required result.
    /// For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 
    /// 2, 3], which isn't sorted.
    ///
    /// Example 2:
    /// Input: arr = [2,1,3,4,4]
    /// Output: 4
    /// Explanation:
    /// We can split into two chunks, such as [2, 1], [3, 4, 4].
    /// However, splitting into [2, 1], [3], [4], [4] is the highest number of 
    /// chunks possible.
    ///
    /// Note:
    /// arr will have length in range [1, 2000].
    /// arr[i] will be an integer in range [0, 10**8].
    /// </summary>
    int maxChunksToSortedII(vector<int>& arr);

    /// <summary>
    /// Leetcode #775. Global and Local Inversions
    ///
    /// We have some permutation A of [0, 1, ..., N - 1], where N is the length
    /// of A.
    ///
    /// The number of (global) inversions is the number of i < j with 
    /// 0 <= i < j < N and A[i] > A[j].
    ///
    /// The number of local inversions is the number of i with 0 <= i < N and 
    /// A[i] > A[i+1].
    ///
    /// Return true if and only if the number of global inversions is equal to 
    /// the number of local inversions.
    ///
    /// Example 1:
    /// Input: A = [1,0,2]
    /// Output: true
    /// Explanation: There is 1 global inversion, and 1 local inversion.
    ///
    /// Example 2:
    /// Input: A = [1,2,0]
    /// Output: false
    /// Explanation: There are 2 global inversions, and 1 local inversion.
    /// Note:
    /// 
    /// A will be a permutation of [0, 1, ..., A.length - 1].
    /// A will have length in range [1, 5000].
    /// The time limit for this problem has been reduced.
    /// </summary>
    bool isIdealPermutation(vector<int>& A);

    /// <summary>
    /// Leetcode #775. Global and Local Inversions
    ///
    /// We have some permutation A of [0, 1, ..., N - 1], where N is the length
    /// of A.
    ///
    /// The number of (global) inversions is the number of i < j with 
    /// 0 <= i < j < N and A[i] > A[j].
    ///
    /// The number of local inversions is the number of i with 0 <= i < N and 
    /// A[i] > A[i+1].
    ///
    /// Return true if and only if the number of global inversions is equal to 
    /// the number of local inversions.
    ///
    /// Example 1:
    /// Input: A = [1,0,2]
    /// Output: true
    /// Explanation: There is 1 global inversion, and 1 local inversion.
    ///
    /// Example 2:
    /// Input: A = [1,2,0]
    /// Output: false
    /// Explanation: There are 2 global inversions, and 1 local inversion.
    /// Note:
    /// 
    /// A will be a permutation of [0, 1, ..., A.length - 1].
    /// A will have length in range [1, 5000].
    /// The time limit for this problem has been reduced.
    /// </summary>
    bool isIdealPermutationII(vector<int>& A);

    /// <summary>
    /// Leet code #798. Smallest Rotation with Highest Score
    ///
    /// Given an array A, we may rotate it by a non-negative integer K so that 
    /// the array becomes A[K], A[K+1], A{K+2], ... A[A.length - 1], A[0], 
    /// A[1], ..., A[K-1].  Afterward, any entries that are less than or equal 
    /// to their index are worth 1 point. 
    /// For example, if we have [2, 4, 1, 3, 0], and we rotate by K = 2, it 
    /// becomes [1, 3, 0, 2, 4].  This is worth 3 points because 1 > 0 
    /// [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 
    /// 4 <= 4 [one point].
    /// Over all possible rotations, return the rotation index K that 
    /// corresponds to the highest score we could receive.  If there are 
    /// multiple answers, return the smallest such index K.
    /// Example 1:
    /// Input: [2, 3, 1, 4, 0]
    /// Output: 3
    /// Explanation:  
    /// Scores for each K are listed below: 
    /// K = 0,  A = [2,3,1,4,0],    score 2
    /// K = 1,  A = [3,1,4,0,2],    score 3
    /// K = 2,  A = [1,4,0,2,3],    score 3
    /// K = 3,  A = [4,0,2,3,1],    score 4
    /// K = 4,  A = [0,2,3,1,4],    score 3
    /// So we should choose K = 3, which has the highest score.
    ///
    /// Example 2:
    /// Input: [1, 3, 0, 2, 4]
    /// Output: 0
    /// Explanation:  A will always have 3 points no matter how it shifts.
    /// So we will choose the smallest K, which is 0.
    /// Note:
    /// 1. A will have length at most 20000.
    /// 2. A[i] will be in the range [0, A.length].
    /// </summary> 
    int bestRotation(vector<int>& A);

    /// <summary>
    /// Leet code #853. Car Fleet
    /// 
    /// N cars are going to the same destination along a one lane road.  The 
    /// destination is target miles away.
    ///
    /// Each car i has a constant speed speed[i] (in miles per hour), and initial 
    /// position position[i] miles towards the target along the road.
    ///
    /// A car can never pass another car ahead of it, but it can catch up to it, 
    /// and drive bumper to bumper at the same speed.
    ///
    /// The distance between these two cars is ignored - they are assumed to have 
    /// the same position.
    ///
    /// A car fleet is some non-empty set of cars driving at the same position 
    /// and same speed.  Note that a single car is also a car fleet.
    ///
    /// If a car catches up to a car fleet right at the destination point, it 
    /// will still be considered as one car fleet.
    /// 
    /// How many car fleets will arrive at the destination?
    /// 
    /// Example 1:
    ///
    /// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
    /// Output: 3
    /// Explanation:
    /// The cars starting at 10 and 8 become a fleet, meeting each other at 12.
    /// The car starting at 0 doesn't catch up to any other car, so it is a fleet 
    /// by itself.
    /// The cars starting at 5 and 3 become a fleet, meeting each other at 6.
    /// Note that no other cars meet these fleets before the destination, so the 
    /// answer is 3.
    ///
    /// Note:
    ///
    /// 1. 0 <= N <= 10 ^ 4
    /// 2. 0 < target <= 10 ^ 6
    /// 3. 0 < speed[i] <= 10 ^ 6
    /// 4. 0 <= position[i] < target
    /// 5. All initial positions are different.
    /// </summary>
    int carFleet(int target, vector<int>& position, vector<int>& speed);

    /// <summary>
    /// Leet code #870. Advantage Shuffle
    /// 
    /// Given two arrays A and B of equal size, the advantage of A with respect 
    /// to B is the number of indices i for which A[i] > B[i].
    ///
    /// Return any permutation of A that maximizes its advantage with respect 
    /// to B.
    /// 
    /// Example 1:
    /// Input: A = [2,7,11,15], B = [1,10,4,11]
    /// Output: [2,11,7,15]
    ///
    /// Example 2:
    /// Input: A = [12,24,8,32], B = [13,25,32,11]
    /// Output: [24,32,8,12]
    /// 
    /// Note:
    /// 1. 1 <= A.length = B.length <= 10000
    /// 2. 0 <= A[i] <= 10^9
    /// 3. 0 <= B[i] <= 10^9
    /// </summary>
    vector<int> advantageCount(vector<int>& A, vector<int>& B);

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
    int numRescueBoats(vector<int>& people, int limit);

    /// <summary>
    /// Leet code #941. Valid Mountain Array
    /// 
    /// Given an array A of integers, return true if and only if it is a valid 
    /// mountain array.
    ///
    /// Recall that A is a mountain array if and only if:
    ///
    /// A.length >= 3
    /// There exists some i with 0 < i < A.length - 1 such that:
    /// A[0] < A[1] < ... A[i-1] < A[i]
    /// A[i] > A[i+1] > ... > A[B.length - 1]
    /// 
    ///
    /// Example 1:
    /// Input: [2,1]
    /// Output: false
    ///
    /// Example 2:
    /// Input: [3,5,5]
    /// Output: false
    ///
    /// Example 3:
    /// Input: [0,3,2,1]
    /// Output: true
    ///
    /// Note:
    /// 1. 0 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 10000 
    /// </summary>
    bool validMountainArray(vector<int>& A);

    /// <summary>
    /// Leet code #942. DI String Match
    /// 
    /// Given a string S that only contains "I" (increase) or "D" (decrease), 
    /// let N = S.length.
    ///
    /// Return any permutation A of [0, 1, ..., N] such that for all 
    /// i = 0, ..., N-1:
    ///
    /// If S[i] == "I", then A[i] < A[i+1]
    /// If S[i] == "D", then A[i] > A[i+1]
    /// 
    /// Example 1:
    /// Input: "IDID"
    /// Output: [0,4,1,3,2]
    ///
    /// Example 2:
    /// Input: "III"
    /// Output: [0,1,2,3]
    ///
    /// Example 3:
    /// Input: "DDI"
    /// Output: [3,2,0,1]
    /// 
    ///
    /// Note:
    /// 
    /// 1. 1 <= S.length <= 10000
    /// 2. S only contains characters "I" or "D".
    /// </summary>
    vector<int> diStringMatch(string S);

    /// <summary>
    /// Leet code #953. Verifying an Alien Dictionary
    /// 
    /// In an alien language, surprisingly they also use english lowercase 
    /// letters, but possibly in a different order. The order of the alphabet 
    /// is some permutation of lowercase letters.
    ///
    /// Given a sequence of words written in the alien language, and the order 
    /// of the alphabet, return true if and only if the given words are sorted 
    /// lexicographicaly in this alien language.
    ///
    /// Example 1:
    /// Input: words = ["hello","leetcode"], 
    /// order = "hlabcdefgijkmnopqrstuvwxyz"
    /// Output: true
    /// Explanation: As 'h' comes before 'l' in this language, then the 
    /// sequence is sorted.
    ///
    /// Example 2:
    /// Input: words = ["word","world","row"], 
    /// order = "worldabcefghijkmnpqstuvxyz"
    /// Output: false
    /// Explanation: As 'd' comes after 'l' in this language, then 
    /// words[0] > words[1], hence the sequence is unsorted.
    ///
    /// Example 3:
    /// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
    /// Output: false
    /// Explanation: The first three characters "app" match, and the second 
    /// string is shorter (in size.) According to lexicographical rules 
    /// "apple" > "app", because 'l' > '\0', where '\0' is defined as the 
    /// blank character which is less than any other character (More info).
    /// 
    /// Note:
    /// 1. 1 <= words.length <= 100
    /// 2. 1 <= words[i].length <= 20
    /// 3. order.length == 26
    /// 4. All characters in words[i] and order are english lowercase letters.
    /// </summary>
    bool isAlienSorted(vector<string>& words, string order);

    /// <summary>
    /// Leet code #954. Array of Doubled Pairs
    /// 
    /// Given an array of integers A with even length, return true if and only 
    /// if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] 
    /// for every 0 <= i < len(A) / 2.
    ///  
    /// Example 1:
    /// Input: [3,1,3,6]
    /// Output: false
    ///
    /// Example 2:
    /// Input: [2,1,2,6]
    /// Output: false
    ///
    /// Example 3:
    /// Input: [4,-2,2,-4]
    /// Output: true
    /// Explanation: We can take two groups, [-2,-4] and [2,4] to form 
    /// [-2,-4,2,4] or [2,4,-2,-4].
    ///
    /// Example 4:
    /// Input: [1,2,4,16,8,4]
    /// Output: false
    ///
    /// Note:
    /// 1. 0 <= A.length <= 30000
    /// 2. A.length is even
    /// 3. -100000 <= A[i] <= 100000
    /// </summary>
    bool canReorderDoubled(vector<int>& A);

    /// <summary>
    /// Leet code #955. Delete Columns to Make Sorted II
    /// 
    /// We are given an array A of N lowercase letter strings, all of the same 
    /// length.
    ///
    /// Now, we may choose any set of deletion indices, and for each string, 
    /// we delete all the characters in those indices.
    ///
    /// For example, if we have an array A = ["abcdef","uvwxyz"] and deletion 
    /// indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].
    ///
    /// Suppose we chose a set of deletion indices D such that after deletions, 
    /// the final array has its elements in lexicographic order 
    /// (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).
    ///
    /// Return the minimum possible value of D.length.
    ///
    /// Example 1:
    /// Input: ["ca","bb","ac"]
    /// Output: 1
    /// Explanation: 
    /// After deleting the first column, A = ["a", "b", "c"].
    /// Now A is in lexicographic order (ie. A[0] <= A[1] <= A[2]).
    /// We require at least 1 deletion since initially A was not in 
    /// lexicographic order, so the answer is 1.
    ///
    /// Example 2:
    /// Input: ["xc","yb","za"]
    /// Output: 0
    /// Explanation: 
    /// A is already in lexicographic order, so we don't need to delete 
    /// anything.
    /// Note that the rows of A are not necessarily in lexicographic order:
    /// ie. it is NOT necessarily true that (A[0][0] <= A[0][1] <= ...)
    ///
    /// Example 3:
    /// Input: ["zyx","wvu","tsr"]
    /// Output: 3
    /// Explanation: 
    /// We have to delete every column.
    ///  
    /// Note:
    /// 1. 1 <= A.length <= 100
    /// 2. 1 <= A[i].length <= 100
    /// </summary>
    int minDeletionSizeII(vector<string>& A);

    /// <summary>
    /// Leet code #962. Maximum Width Ramp
    /// 
    /// Given an array A of integers, a ramp is a tuple (i, j) for which i < j 
    /// and A[i] <= A[j].  The width of such a ramp is j - i.
    ///
    /// Find the maximum width of a ramp in A.  If one doesn't exist, return 0.
    /// 
    /// Example 1:
    ///
    /// Input: [6,0,8,2,1,5]
    /// Output: 4
    /// Explanation: 
    /// The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and 
    /// A[5] = 5.
    ///
    /// Example 2:
    ///
    /// Input: [9,8,1,0,1,9,4,0,4,1]
    /// Output: 7
    /// Explanation: 
    /// The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and 
    /// A[9] = 1.
    ///
    /// Note:
    ///
    /// 1. 2 <= A.length <= 50000
    /// 2. 0 <= A[i] <= 50000
    /// </summary>
    int maxWidthRamp(vector<int>& A);

    /// <summary>
    /// Leet code #977. Squares of a Sorted Array
    /// 
    /// Given an array of integers A sorted in non-decreasing order, return 
    /// an array of the squares of each number, also in sorted 
    /// non-decreasing order.
    /// 
    /// Example 1:
    /// Input: [-4,-1,0,3,10]
    /// Output: [0,1,9,16,100]
    ///
    /// Example 2:
    /// Input: [-7,-3,2,3,11]
    /// Output: [4,9,9,49,121]
    ///
    /// Note:
    /// 1. 1 <= A.length <= 10000
    /// 2. -10000 <= A[i] <= 10000
    /// 3. A is sorted in non-decreasing order.
    /// </summary>
    vector<int> sortedSquares(vector<int>& A);

    /// <summary>
    /// Leet code #912. Sort an Array
    /// 
    /// Given an array of integers nums, sort the array in ascending order.
    /// 
    /// Example 1:
    /// 
    /// Input: [5,2,3,1]
    /// Output: [1,2,3,5]
    ///
    /// Example 2:
    ///
    /// Input: [5,1,1,2,0,0]
    /// Output: [0,0,1,1,2,5]
    /// 
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 10000
    /// 2. -50000 <= A[i] <= 50000
    /// </summary>
    vector<int> sortArray(vector<int>& nums);

    /// <summary>
    /// Leet code #1029. Two City Scheduling
    /// 
    /// There are 2N people a company is planning to interview. The cost of flying 
    /// the i-th person to city A is costs[i][0], and the cost of flying the i-th 
    /// person to city B is costs[i][1].
    /// 
    /// Return the minimum cost to fly every person to a city such that exactly N 
    /// people arrive in each city.
    /// 
    /// Example 1:
    ///
    /// Input: [[10,20],[30,200],[400,50],[30,20]]
    /// Output: 110
    /// Explanation: 
    /// The first person goes to city A for a cost of 10.
    /// The second person goes to city A for a cost of 30.
    /// The third person goes to city B for a cost of 50.
    /// The fourth person goes to city B for a cost of 20.
    ///
    /// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people 
    /// interviewing in each city.
    ///  
    /// Note:
    /// 1. 1 <= costs.length <= 100
    /// 2. It is guaranteed that costs.length is even.
    /// 3. 1 <= costs[i][0], costs[i][1] <= 1000
    /// </summary>
    int twoCitySchedCost(vector<vector<int>>& costs);

    /// <summary>
    /// Leet code #1046. Last Stone Weight
    /// 
    /// We have a collection of rocks, each rock has a positive integer weight.
    /// Each turn, we choose the two heaviest rocks and smash them together.  
    /// Suppose the stones have weights x and y with x <= y.  The result of this 
    /// smash is:
    /// If x == y, both stones are totally destroyed;
    /// If x != y, the stone of weight x is totally destroyed, and the stone of 
    /// weight y has new weight y-x.
    /// At the end, there is at most 1 stone left.  Return the weight of this 
    /// stone (or 0 if there are no stones left.)
    /// 
    /// Example 1:
    /// Input: [2,7,4,1,8,1]
    /// Output: 1
    /// Explanation: 
    /// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
    /// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
    /// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
    /// we combine 1 and 1 to get 0 so the array converts to [1] then that's the 
    /// value of last stone.
    /// 
    /// Note:
    /// 1. 1 <= stones.length <= 30
    /// 2. 1 <= stones[i] <= 1000
    /// </summary>
    int lastStoneWeight(vector<int>& stones);

    /// <summary>
    /// Leet code #1051. Height Checker
    /// 
    /// Students are asked to stand in non-decreasing order of heights for an 
    /// annual photo.
    ///
    /// Return the minimum number of students not standing in the right 
    /// positions.  (This is the number of students that must move in order 
    /// for all students to be standing in non-decreasing order of height.)
    ///
    /// Example 1:
    ///
    /// Input: [1,1,4,2,1,3]
    /// Output: 3
    /// Explanation: 
    /// Students with heights 4, 3 and the last 1 are not standing in the right 
    /// positions.
    /// 
    /// Note:
    /// 
    /// 1. 1 <= heights.length <= 100
    /// 2. 1 <= heights[i] <= 100
    /// </summary>
    int heightChecker(vector<int>& heights);

    /// <summary>
    /// Leet code #1053. Previous Permutation With One Swap
    /// 
    /// Given an array A of positive integers (not necessarily distinct), return 
    /// the lexicographically largest permutation that is smaller than A, that 
    /// can be made with one swap (A swap exchanges the positions of two numbers 
    /// A[i] and A[j]).  If it cannot be done, then return the same array.
    ///
    /// Example 1:
    ///
    /// Input: [3,2,1]
    /// Output: [3,1,2]
    /// Explanation: Swapping 2 and 1.
    ///
    /// Example 2:
    ///
    /// Input: [1,1,5]
    /// Output: [1,1,5]
    /// Explanation: This is already the smallest permutation.
    ///
    /// Example 3:
    ///
    /// Input: [1,9,4,6,7]
    /// Output: [1,7,4,6,9]
    /// Explanation: Swapping 9 and 7.
    ///
    /// Example 4:
    ///
    /// Input: [3,1,1,3]
    /// Output: [1,3,1,3]
    /// Explanation: Swapping 1 and 3.
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= A.length <= 10000
    /// 2. 1 <= A[i] <= 10000
    /// </summary>
    vector<int> prevPermOpt1(vector<int>& A);

    /// <summary>
    /// Leet code #1090. Largest Values From Labels
    /// 
    /// We have a set of items: the i-th item has value values[i] and label 
    /// labels[i].
    ///
    /// Then, we choose a subset S of these items, such that:
    /// |S| <= num_wanted
    /// For every label L, the number of items in S with label L is <= 
    /// use_limit.
    /// Return the largest possible sum of the subset S.
    ///
    /// Example 1:
    /// Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, 
    /// use_limit = 1
    /// Output: 9
    /// Explanation: The subset chosen is the first, third, and fifth item.
    ///
    /// Example 2: 
    /// Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, 
    /// use_limit = 2
    /// Output: 12
    /// Explanation: The subset chosen is the first, second, and third item.
    ///
    /// Example 3:
    /// Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, 
    /// use_limit = 1
    /// Output: 16
    /// Explanation: The subset chosen is the first and fourth item.
    ///
    /// Example 4:
    /// Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, 
    /// use_limit = 2
    /// Output: 24
    /// Explanation: The subset chosen is the first, second, and fourth item.
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= values.length == labels.length <= 20000
    /// 2. 0 <= values[i], labels[i] <= 20000
    /// 3. 1 <= num_wanted, use_limit <= values.length
    /// </summary>
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, 
        int num_wanted, int use_limit);

    /// <summary>
    /// Leet code #1086. High Five
    /// 
    /// Given a list of scores of different students, return the average 
    /// score of each student's top five scores in the order of each 
    /// student's id.
    /// Each entry items[i] has items[i][0] the student's id, and items[i][1] 
    /// the student's score.  The average score is calculated using integer 
    /// division.
    ///
    /// Example 1:
    /// Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],
    ///        [1,100],[2,100],[2,76]]
    /// Output: [[1,87],[2,88]]
    /// Explanation: 
    /// The average of the student with id = 1 is 87.
    /// The average of the student with id = 2 is 88.6. But with integer 
    /// division their average converts to 88.
    ///
    /// Note:
    /// 1. 1 <= items.length <= 1000
    /// 2. items[i].length == 2
    /// 3. The IDs of the students is between 1 to 1000
    /// 4. The score of the students is between 1 to 100
    /// 5. For each student, there are at least 5 scores
    /// </summary>
    vector<vector<int>> highFive(vector<vector<int>>& items);

    /// <summary>
    /// Leet code #1099. Two Sum Less Than K
    /// 
    /// Given an array A of integers and integer K, return the maximum S such 
    /// that there exists i < j with A[i] + A[j] = S and S < K. If no i, j 
    /// exist satisfying this equation, return -1.
    /// 
    /// Example 1:
    /// Input: A = [34,23,1,24,75,33,54,8], K = 60
    /// Output: 58
    /// Explanation: 
    /// We can use 34 and 24 to sum 58 which is less than 60.
    ///
    /// Example 2:
    /// Input: A = [10,20,30], K = 15
    /// Output: -1
    /// Explanation: 
    /// In this case it's not possible to get a pair sum less that 15.
    /// </summary>
    int twoSumLessThanK(vector<int>& A, int K);

    /// <summary>
    /// Leet code #1122. Relative Sort Array
    /// 
    /// Given two arrays arr1 and arr2, the elements of arr2 are distinct, 
    /// and all elements in arr2 are also in arr1.
    ///
    /// Sort the elements of arr1 such that the relative ordering of items 
    /// in arr1 are the same as in arr2.  Elements that don't appear in arr2 
    /// should be placed at the end of arr1 in ascending order.
    ///
    /// 
    /// Example 1:
    /// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
    /// Output: [2,2,2,1,4,3,3,9,6,7,19]
    /// 
    /// 
    /// Constraints:
    ///
    /// 1. arr1.length, arr2.length <= 1000
    /// 2. 0 <= arr1[i], arr2[i] <= 1000
    /// 3. Each arr2[i] is distinct.
    /// 4. Each arr2[i] is in arr1.
    /// </summary>
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2);

    /// <summary>
    /// Leet code #1133. Largest Unique Number
    /// 
    /// Given an array of integers A, return the largest integer that only occurs 
    /// once.
    ///
    /// If no integer occurs once, return -1.
    ///
    /// Example 1:
    /// Input: [5,7,3,9,4,9,8,3,1]
    /// Output: 8
    /// Explanation: 
    /// The maximum integer in the array is 9 but it is repeated. The number 8 
    /// occurs only once, so it's the answer.
    ///
    /// Example 2:
    /// Input: [9,9,8,8]
    /// Output: -1
    /// Explanation: 
    /// There is no number that occurs only once.
    /// Note:
    /// 1. 1 <= A.length <= 2000
    /// 2. 0 <= A[i] <= 1000
    /// </summary>
    int largestUniqueNumber(vector<int>& A);

    /// <summary>
    /// Leet code #376. Wiggle Subsequence
    /// A sequence of numbers is called a wiggle sequence if the differences between successive numbers 
    /// strictly alternate between positive and negative. The first difference (if one
    /// exists) may be either positive or negative. A sequence with fewer than two elements is trivially 
    /// a wiggle sequence. 
    /// 
    /// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are 
    /// alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are 
    /// not wiggle sequences, the first because its first two differences are 
    /// positive and the second because its last difference is zero.
    ///
    /// Given a sequence of integers, return the length of the longest subsequence that is a 
    /// wiggle sequence. A subsequence is obtained by deleting some number of elements 
    /// (eventually, also zero) from the original sequence, leaving the remaining elements 
    /// in their original order.
    /// 
    /// Examples:
    /// Input: [1,7,4,9,2,5]
    /// Output: 6
    /// The entire sequence is a wiggle sequence.
    ///
    /// Input: [1,17,5,10,13,15,10,5,16,8]
    /// Output: 7
    /// There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
    ///
    /// Input: [1,2,3,4,5,6,7,8,9]
    /// Output: 2
    /// Follow up:
    /// Can you do it in O(n) time? 
    /// </summary>
    int wiggleMaxLength(vector<int>& nums);

    /// <summary>
    /// Leet code #1169. Invalid Transactions
    ///
    /// A transaction is possibly invalid if:
    ///
    /// the amount exceeds $1000, or;
    /// if it occurs within (and including) 60 minutes of another transaction 
    /// with the same name in a different city.
    /// Each transaction string transactions[i] consists of comma separated 
    /// values representing the name, time (in minutes), amount, and city of 
    /// the transaction.
    ///
    /// Given a list of transactions, return a list of transactions that are 
    /// possibly invalid.  You may return the answer in any order.
    ///
    /// 
    ///
    /// Example 1:
    /// Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
    /// Output: ["alice,20,800,mtv","alice,50,100,beijing"]
    /// Explanation: The first transaction is invalid because the second 
    /// transaction occurs within a difference of 60 minutes, have the same 
    /// name and is in a different city. Similarly the second one is 
    /// invalid too.
    ///
    /// Example 2:
    ///
    /// Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
    /// Output: ["alice,50,1200,mtv"]
    ///
    /// Example 3:
    ///
    /// Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
    /// Output: ["bob,50,1200,mtv"]
    ///  
    /// Constraints:
    /// 
    /// 1. transactions.length <= 1000
    /// 2. Each transactions[i] takes the form "{name},{time},{amount},{city}"
    /// 3. Each {name} and {city} consist of lowercase English letters, and have 
    ///    lengths between 1 and 10.
    /// 3. Each {time} consist of digits, and represent an integer between 
    ///    0 and 1000.
    /// 4. Each {amount} consist of digits, and represent an integer between 
    ///    0 and 2000.
    /// </summary>
    vector<string> invalidTransactions(vector<string>& transactions);

    /// <summary>
    /// Leet code #1167. Minimum Cost to Connect Sticks
    /// 
    /// You have some sticks with positive integer lengths.
    /// You can connect any two sticks of lengths X and Y into one stick by 
    /// paying a cost of X + Y.  You perform this action until there is one 
    /// stick remaining.
    /// Return the minimum cost of connecting all the given sticks into one 
    /// stick in this way.
    /// 
    /// Example 1:
    /// Input: sticks = [2,4,3]
    /// Output: 14
    ///
    /// Example 2:
    /// Input: sticks = [1,8,3,5]
    /// Output: 30
    ///  
    /// Constraints:
    /// 1 <= sticks.length <= 10^4
    /// 1 <= sticks[i] <= 10^4
    /// </summary>
    int connectSticks(vector<int>& sticks);

    /// <summary>
    /// Leet code #1182. Shortest Distance to Target Color
    /// 
    /// You are given an array colors, in which there are three colors: 1, 2 and 3.
    /// You are also given some queries. Each query consists of two integers i 
    /// and c, return the shortest distance between the given index i and the 
    /// target color c. If there is no solution return -1.
    /// 
    /// Example 1:
    /// Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
    /// Output: [3,0,3]
    /// Explanation: 
    /// The nearest 3 from index 1 is at index 4 (3 steps away).
    /// The nearest 2 from index 2 is at index 2 itself (0 steps away).
    /// The nearest 1 from index 6 is at index 3 (3 steps away).
    ///
    /// Example 2:
    /// Input: colors = [1,2], queries = [[0,3]]
    /// Output: [-1]
    /// Explanation: There is no 3 in the array.
    ///  
    /// Constraints:
    /// 1. 1 <= colors.length <= 5*10^4
    /// 2. 1 <= colors[i] <= 3
    /// 3. 1 <= queries.length <= 5*10^4
    /// 4. queries[i].length == 2
    /// 5. 0 <= queries[i][0] < colors.length
    /// 6. 1 <= queries[i][1] <= 3
    /// </summary>
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code #1199. Minimum Time to Build Blocks
    /// 
    /// You are given a list of blocks, where blocks[i] = t means that the i-th 
    /// block needs t units of time to be built. A block can only be built by 
    /// exactly one worker.
    ///
    /// A worker can either split into two workers (number of workers increases 
    /// by one) or build a block then go home. Both decisions cost some time.
    ///
    /// The time cost of spliting one worker into two workers is given as an 
    /// integer split. Note that if two workers split at the same time, they 
    /// split in parallel so the cost would be split.
    ///
    /// Output the minimum time needed to build all blocks.
    ///
    /// Initially, there is only one worker.
    /// 
    /// Example 1:
    /// Input: blocks = [1], split = 1
    /// Output: 1
    /// Explanation: We use 1 worker to build 1 block in 1 time unit.
    ///
    /// Example 2:
    /// Input: blocks = [1,2], split = 5
    /// Output: 7
    /// Explanation: We split the worker into 2 workers in 5 time units then 
    /// assign each of them to a block so the cost is 5 + max(1, 2) = 7.
    ///
    /// Example 3:
    /// Input: blocks = [1,2,3], split = 1
    /// Output: 4
    /// Explanation: Split 1 worker into 2, then assign the first worker to 
    /// the last block and split the second worker into 2.
    /// Then, use the two unassigned workers to build the first two blocks.
    /// The cost is 1 + max(3, 1 + max(1, 2)) = 4.
    /// 
    ///
    /// Constraints:
    ///
    /// 1. 1 <= blocks.length <= 1000
    /// 2. 1 <= blocks[i] <= 10^5
    /// 3. 1 <= split <= 100
    /// </summary>
    int minBuildTime(vector<int>& blocks, int split); 

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
