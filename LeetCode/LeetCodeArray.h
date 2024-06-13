#pragma once
#ifndef LeetCodeArray_H
#define LeetCodeArray_H
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
#include "LeetCodeDesign.h"
using namespace std;
/// <summary>
/// The street class
/// </summary>
class Street 
{
private: 
    vector<int> m_doors;
    int m_index = 0;
public:
    Street(vector<int> doors)
    {
        m_doors = doors;
    }
    void openDoor()
    {
        m_doors[m_index] = 1;
    }
    void closeDoor()
    {
        m_doors[m_index] = 0;
    }
    bool isDoorOpen()
    {
        return (m_doors[m_index] == 1);
    };
    void moveRight()
    {
        m_index++;
        if (m_index == m_doors.size()) m_index = 0;
    }
    void moveLeft()
    {
        m_index--;
        if (m_index < 0) m_index = m_doors.size() - 1;
    }
};
/// <summary>
/// The street class
/// </summary>
class ArrayReader
{
private:
    vector<int> m_array;
public:
    /// <summary>
    /// Constructor, which will lead to the smallest child.
    /// </summary>
    ArrayReader(vector<int>& arr)
    {
        m_array = arr;
    }

    /// <summary>
    /// Query four number.
    /// </summary>
    int query(int a, int b, int c, int d)
    {
        vector<int> slot(2);
        slot[m_array[a]]++;
        slot[m_array[b]]++;
        slot[m_array[c]]++;
        slot[m_array[d]]++;
        return abs(slot[0] - slot[1]);
    }

    /// <summary>
    /// compare the sum of subarray.
    /// </summary>
    int compareSub(int l, int r, int x, int y)
    {
        int sum1 = 0;
        for (int i = l; i <= r; i++) sum1 += m_array[i];

        int sum2 = 0;
        for (int i = x; i <= y; i++) sum2 += m_array[i];

        if (sum1 < sum2) return -1;
        else if (sum1 > sum2) return 1;
        else return 0;
    }

    /// <summary>
    /// Return the length of array.
    /// </summary>
    int length(void)
    {
        return m_array.size();
    }
};

/// <summary>
/// The class is to implement array related algorithm  
/// </summary>
class LeetCodeArray
{
public:
#pragma region TwoPointers
    /// <summary>
    /// Leet code #16. 3Sum Closest 
    /// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
    /// Return the sum of the three integers. You may assume that each input would have exactly one solution.
    /// For example, given array S = {-1 2 1 -4}, and target = 1.
    /// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    /// </summary>
    int threeSumClosest(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #27. Remove Element
    ///
    /// Given an array and a value, remove all instances of that value 
    /// in place and return the new length. 
    /// Do not allocate extra space for another array, you must do this 
    /// in place with constant memory.
    /// The order of elements can be changed. It doesn't matter what you 
    /// leave beyond the new length.
    /// Example:
    /// Given input array nums = [3,2,2,3], val = 3 
    /// Your function should return length = 2, with the first two elements 
    /// of nums being 2.	
    /// </summary> 
    int removeArrayElement(vector<int>& nums, int val);

    /// <summary>
    /// Leet code #283. Move Zeroes
    ///
    /// Given an array nums, write a function to move all 0's to the end 
    /// of it while maintaining the relative order of the non-zero elements.
    /// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].  
    /// Note:
    /// 1.You must do this in-place without making a copy of the array.
    /// 2.Minimize the total number of operations
    /// </summary>
    void moveZeroes(vector<int>& nums);

    /// <summary>
    /// Leet code #345. Reverse Vowels of a String 
    ///
    /// Write a function that takes a string as input and reverse only the vowels of a string.
    /// Example 1:
    /// Given s = "hello", return "holle". 
    /// Example 2:
    /// Given s = "leetcode", return "leotcede". 
    /// Note:
    /// The vowels does not include the letter "y". 
    /// </summary>
    string reverseVowels(string s);

    /// <summary>
    /// Leet code #167. Two Sum II - Input array is sorted
    ///
    /// Given an array of integers that is already sorted in ascending order, 
    /// find two numbers such that they add up to a specific target number.
    /// The function twoSum should return indices of the two numbers such that 
    /// they add up to the target, 
    /// where index1 must be less than index2. Please note that your returned 
    /// answers (both index1 and index2) are not zero-based.
    ///
    /// You may assume that each input would have exactly one solution. 
    /// Input: numbers={2, 7, 11, 15}, target=9
    ///
    /// Output: index1=1, index2=2 
    /// </summary>
    vector<int> twoSumII(vector<int>& numbers, int target);

    /// <summary>
    /// Leet code #209. Minimum Size Subarray Sum   
    /// 
    /// Medium
    ///
    /// Given an array of n positive integers and a positive integer s, find 
    /// the minimal length of a contiguous subarray of which the sum >= s. If 
    /// there isn't one, return 0 instead.
    ///
    /// Example: 
    /// Input: s = 7, nums = [2,3,1,2,4,3]
    /// Output: 2
    /// Explanation: the subarray [4,3] has the minimal length under the 
    /// problem constraint.
    /// Follow up:
    /// If you have figured out the O(n) solution, try coding another 
    /// solution of which the time complexity is O(n log n). 
    /// </summary>
    int minSubArrayLen(int s, vector<int>& nums);

    /// <summary>
    /// Leet code #259. 3Sum Smaller  
    /// 
    /// Given an array of n integers nums and a target, find the number of index 
    /// triplets i, j, k with 0 <= i < j < k < n that satisfy the condition 
    /// nums[i] + nums[j] + nums[k] < target.
    /// For example, given nums = [-2, 0, 1, 3], and target = 2.
    /// Return 2. Because there are two triplets which sums are less than 2:
    /// [-2, 0, 1]
    /// [-2, 0, 3]
    /// Follow up:
    /// Could you solve it in O(n2) runtime? 
    /// </summary>
    int threeSumSmaller(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #487. Max Consecutive Ones II������ 
    /// 
    /// Given a binary array, find the maximum number of consecutive 1s in this 
    /// array if you can flip at most one 0.  
    /// Example 1: 
    /// Input: [1,0,1,1,0]
    ///
    /// Output: 4 
    /// Explanation: Flip the first zero will get the the maximum number of 
    /// consecutive 1s.
    /// After flipping, the maximum number of consecutive 1s is 4.
    ///	Note:
    /// The input array will only contain 0 and 1.
    /// The length of input array is a positive integer and will not exceed 10,000
    /// Follow up:
    /// What if the input numbers come in one by one as an infinite stream? In other words, 
    /// you can't store all numbers coming from the stream as it's too large to hold in memory. 
    /// Could you solve it efficiently? 
    /// </summary>
    int findMaxConsecutiveOnesII(vector<int>& nums);

    /// <summary>
    /// Leet code #544. Output Contest Matches 
    /// 
    /// During the NBA playoffs, we always arrange the rather strong team to 
    /// play with the rather weak team, like make the rank 1 team play with 
    /// the rank nth team, which is a good strategy to make the contest more 
    /// interesting. Now, you're given n teams, you need to output their final 
    /// contest matches in the form of a string.
    ///
    /// The n teams are given in the form of positive integers from 1 to n, 
    /// which represents their initial rank. (Rank 1 is the strongest team 
    /// and Rank n is the weakest team.) We'll use parentheses('(', ')') and 
    /// commas(',') to represent the contest team pairing - parentheses
    /// ('(' , ')') for pairing and commas(',') for partition. During the 
    /// pairing process in each round, you always need to follow the strategy 
    /// of making the rather strong one pair with the rather weak one.
    /// 
    /// Example 1:
    /// Input: 2
    /// Output: (1,2)
    /// Explanation: 
    /// Initially, we have the team 1 and the team 2, placed like: 1,2.
    /// Then we pair the team (1,2) together with '(', ')' and ',', which is 
    /// the final answer.
    /// Example 2:
    /// Input: 4
    /// Output: ((1,4),(2,3))
    /// Explanation: 
    /// In the first round, we pair the team 1 and 4, the team 2 and 3 
    /// together, as we need to make the strong team and weak team together.
    /// And we got (1,4),(2,3).
    /// In the second round, the winners of (1,4) and (2,3) need to play again 
    /// to generate the final winner, so you need to add the paratheses outside 
    /// them.
    /// And we got the final answer ((1,4),(2,3)).
    /// Example 3:
    /// Input: 8
    /// Output: (((1,8),(4,5)),((2,7),(3,6)))
    /// Explanation: 
    /// First round: (1,8),(2,7),(3,6),(4,5)
    /// Second round: ((1,8),(4,5)),((2,7),(3,6))
    /// Third round: (((1,8),(4,5)),((2,7),(3,6)))
    /// Since the third round will generate the final winner, you need to 
    /// output the answer (((1,8),(4,5)),((2,7),(3,6))).
    /// Note:
    /// The n is in range [2, 212].
    /// We ensure that the input n can be converted into the form 2^k, where k is a positive integer.
    /// </summary>
    string findContestMatch(int n);

    /// <summary>
    /// Leet code #713. Subarray Product Less Than K
    /// Your are given an array of positive integers nums.
    /// 
    /// Count and print the number of (contiguous) subarrays where the product 
    /// of all the elements in the subarray is less than k.
    ///
    /// Example 1:
    /// Input: nums = [10, 5, 2, 6], k = 100
    /// Output: 8
    /// Explanation: The 8 subarrays that have product less than 100 are: 
    /// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
    /// Note that [10, 5, 2] is not included as the product of 100 is not 
    /// strictly less than k.
    /// Note:
    /// 
    /// 0 < nums.length <= 50000.
    /// 0 < nums[i] < 1000.
    /// 0 <= k < 10^6.
    /// </summary>
    int numSubarrayProductLessThanK(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #443. String Compression
    ///
    /// Given an array of characters, compress it in-place.
    ///
    /// The length after compression must always be smaller than or equal to 
    /// the original array.
    /// Every element of the array should be a character (not int) of length 1.
    /// After you are done modifying the input array in-place, return the new 
    /// length of the array.
    ///
    /// Follow up:
    /// Could you solve it using only O(1) extra space?
    ///
    /// Example 1:
    /// Input:
    /// ["a","a","b","b","c","c","c"]
    /// Output:
    /// Return 6, and the first 6 characters of the input array should be: 
    /// ["a","2","b","2","c","3"]
    ///
    /// Explanation:
    /// "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced 
    /// by "c3".
    ///
    /// Example 2:
    /// Input:
    /// ["a"]
    /// Output:
    /// Return 1, and the first 1 characters of the input array should be: 
    /// ["a"]
    ///
    /// Explanation:
    /// Nothing is replaced.
    /// Example 3:
    /// Input:
    /// ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    ///
    /// Output:
    /// Return 4, and the first 4 characters of the input array should be: 
    /// ["a","b","1","2"].
    ///
    /// Explanation:
    /// Since the character "a" does not repeat, it is not compressed. 
    /// "bbbbbbbbbbbb" is replaced by "b12".
    /// Notice each digit has it's own entry in the array.
    /// Note:
    /// All characters have an ASCII value in [35, 126].
    /// 1 <= len(chars) <= 1000.
    /// </summary>
    int compress(vector<char>& chars);

    /// <summary>
    /// Leet code #755. Pour Water    
    /// We are given an elevation map, heights[i] representing the height of the 
    /// terrain at that index. The width at each index is 1. After V units of 
    /// water fall at index K, how much water is at each index?
    ///
    /// Water first drops at index K and rests on top of the highest terrain or 
    /// water at that index. Then, it flows according to the following rules:
    ///
    /// If the droplet would eventually fall by moving left, then move left.
    /// Otherwise, if the droplet would eventually fall by moving right, then 
    /// move right.
    /// Otherwise, rise at it's current position.
    /// Here, "eventually fall" means that the droplet will eventually be at a 
    /// lower level if it moves in that direction. Also, "level" means the height 
    /// of the terrain plus any water in that column.
    /// We can assume there's infinitely high terrain on the two sides out of 
    /// bounds of the array. Also, there could not be partial water being spread 
    /// out evenly on more than 1 grid block - each unit of water has to be in 
    /// exactly one block.
    ///
    /// Example 1:
    /// Input: heights = [2,1,1,2,1,2,2], V = 4, K = 3
    /// Output: [2,2,2,3,2,2,2]
    /// Explanation:
    /// #       #
    /// #       #
    /// ##  # ###
    /// #########
    ///  0123456    <- index
    ///
    /// The first drop of water lands at index K = 3:
    /// 
    /// #       #
    /// #   w   #
    /// ##  # ###
    /// #########
    ///  0123456    
    /// 
    /// When moving left or right, the water can only move to the same level or a 
    /// lower level.
    /// (By level, we mean the total height of the terrain plus any water in that 
    /// column.)
    /// Since moving left will eventually make it fall, it moves left.
    /// (A droplet "made to fall" means go to a lower height than it was at 
    /// previously.)
    ///
    /// #       #
    /// #       #
    /// ## w# ###
    /// #########
    ///  0123456    
    ///
    /// Since moving left will not make it fall, it stays in place.  The next 
    /// droplet falls:
    ///
    /// #       #
    /// #   w   #
    /// ## w# ###
    /// #########
    ///  0123456  
    ///
    /// Since the new droplet moving left will eventually make it fall, it moves 
    /// left.
    /// Notice that the droplet still preferred to move left,
    /// even though it could move right (and moving right makes it fall quicker.)
    /// 
    /// #       #
    /// #  w    #
    /// ## w# ###
    /// #########
    /// 0123456  
    ///
    /// #       #
    /// #       #
    /// ##ww# ###
    /// #########
    ///  0123456  
    ///
    /// After those steps, the third droplet falls.
    /// Since moving left would not eventually make it fall, it tries to move 
    /// right.
    /// Since moving right would eventually make it fall, it moves right.
    ///
    /// #       #
    /// #   w   #
    /// ##ww# ###
    /// #########
    ///  0123456  
    /// 
    /// #       #
    /// #       #
    /// ##ww#w###
    /// #########
    ///  0123456  
    /// 
    /// Finally, the fourth droplet falls.
    /// Since moving left would not eventually make it fall, it tries to move 
    /// right.
    /// Since moving right would not eventually make it fall, it stays in place:
    /// 
    /// #       #
    /// #   w   #
    /// ##ww#w###
    /// #########
    ///  0123456  
    ///
    /// The final answer is [2,2,2,3,2,2,2]:
    ///
    ///    #    
    /// ####### 
    /// ####### 
    ///  0123456 
    /// Example 2:
    /// Input: heights = [1,2,3,4], V = 2, K = 2
    /// Output: [2,3,3,4]
    /// Explanation:
    /// The last droplet settles at index 1, since moving further left would not 
    /// cause it to eventually fall to a lower height.
    /// Example 3:
    /// Input: heights = [3,1,3], V = 5, K = 1
    /// Output: [4,4,4]
    /// Note:
    ///
    /// heights will have length in [1, 100] and contain integers in [0, 99].
    /// 1. V will be in range [0, 2000].
    /// 2. K will be in range [0, heights.length - 1].
    /// </summary>
    vector<int> pourWater(vector<int>& heights, int V, int K);

    /// <summary>
    /// Leet code #904. Fruit Into Baskets
    /// 
    /// In a row of trees, the i-th tree produces fruit with type tree[i].
    ///
    /// You start at any tree of your choice, then repeatedly perform the 
    /// following steps:
    ///
    /// 1. Add one piece of fruit from this tree to your baskets.  If you cannot, 
    /// stop.
    /// 2. Move to the next tree to the right of the current tree.  If there is no 
    /// tree to the right, stop.
    /// Note that you do not have any choice after the initial choice of starting 
    /// tree: you must perform step 1, then step 2, then back to step 1, then 
    /// step 2, and so on until you stop.
    ///
    /// You have two baskets, and each basket can carry any quantity of fruit, but 
    /// you want each basket to only carry one type of fruit each.
    ///
    /// What is the total amount of fruit you can collect with this procedure?
    ///
    /// Example 1:
    /// Input: [1,2,1]
    /// Output: 3
    /// Explanation: We can collect [1,2,1].
    ///
    /// Example 2:
    /// Input: [0,1,2,2]
    /// Output: 3
    /// Explanation: We can collect [1,2,2].
    /// If we started at the first tree, we would only collect [0, 1].
    ///
    /// Example 3:
    /// Input: [1,2,3,2,2]
    /// Output: 4
    /// Explanation: We can collect [2,3,2,2].
    /// If we started at the first tree, we would only collect [1, 2].
    ///
    /// Example 4:
    /// Input: [3,3,3,1,2,1,1,2,3,3,4]
    /// Output: 5
    /// Explanation: We can collect [1,2,1,1,2].
    /// If we started at the first tree or the eighth tree, we would only collect 
    /// 4 fruits.
    /// 
    /// Note:
    ///
    /// 1. 1 <= tree.length <= 40000
    /// 2. 0 <= tree[i] < tree.length
    /// </summary>
    int totalFruit(vector<int>& tree);

    /// <summary>
    /// Leet code #917. Reverse Only Letters
    /// 
    /// Given a string S, return the "reversed" string where all characters that 
    /// are not a letter stay in the same place, and all letters reverse their 
    /// positions.
    ///
    /// Example 1:
    ///
    /// Input: "ab-cd"
    /// Output: "dc-ba"g
    ///
    /// Input: "a-bC-dEf-ghIj"
    /// Output: "j-Ih-gfE-dCba"
    ///
    /// Example 3:
    /// Input: "Test1ng-Leet=code-Q!"
    /// Output: "Qedo1ct-eeLg=ntse-T!"
    ///  
    /// Note:
    /// 
    /// 1. S.length <= 100
    /// 2. 33 <= S[i].ASCIIcode <= 122 
    /// 3. S doesn't contain \ or "
    /// </summary>
    string reverseOnlyLetters(string S);

    /// <summary>
    /// Leet code #915. Partition Array into Disjoint Intervals
    /// 
    /// Given an array A, partition it into two (contiguous) subarrays left and 
    /// right so that:
    ///
    /// Every element in left is less than or equal to every element in right.
    /// left and right are non-empty.
    /// left has the smallest possible size.
    /// Return the length of left after such a partitioning.  It is guaranteed 
    /// that such a partitioning exists.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: [5,0,3,8,6]
    /// Output: 3
    /// Explanation: left = [5,0,3], right = [8,6]
    ///
    /// Example 2:
    ///
    /// Input: [1,1,1,0,6,12]
    /// Output: 4
    /// Explanation: left = [1,1,1,0], right = [6,12]
    /// 
    ///
    /// Note:
    ///
    /// 2 <= A.length <= 30000
    /// 0 <= A[i] <= 10^6
    /// It is guaranteed there is at least one way to partition A as described.
    /// </summary>
    int partitionDisjoint(vector<int>& A);

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
    /// Note:
    /// 1. 1 <= A.length <= 20000
    /// 2. 1 <= A[i] <= A.length
    /// 3. 1 <= K <= A.length
    /// </summary>
    int subarraysWithKDistinct(vector<int>& A, int K);


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
    /// Leet code #1150. Check If a Number Is Majority Element in a Sorted Array
    /// 
    /// Given an array nums sorted in non-decreasing order, and a number target, 
    /// return True if and only if target is a majority element.
    /// A majority element is an element that appears more than N/2 times in an 
    /// array of length N.
    /// 
    /// Example 1:
    /// Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
    /// Output: true
    /// Explanation: 
    /// The value 5 appears 5 times and the length of the array is 9.
    /// Thus, 5 is a majority element because 5 > 9/2 is true.
    ///
    /// Example 2:
    /// Input: nums = [10,100,101,101], target = 101
    /// Output: false
    /// Explanation: 
    /// The value 101 appears 2 times and the length of the array is 4.
    /// Thus, 101 is not a majority element because 2 > 4/2 is false.
    /// 
    /// Note:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= target <= 10^9
    /// </summary>
    bool isMajorityElement(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1180. Count Substrings with Only One Distinct Letter
    /// 
    /// Given a string S, return the number of substrings that have only one 
    /// distinct letter.
    /// 
    /// Example 1:
    /// Input: S = "aaaba"
    /// Output: 8
    /// Explanation: The substrings with one distinct letter are 
    /// "aaa", "aa", "a", "b".
    /// "aaa" occurs 1 time.
    /// "aa" occurs 2 times.
    /// "a" occurs 4 times.
    /// "b" occurs 1 time.
    /// So the answer is 1 + 2 + 4 + 1 = 8.
    ///
    /// Example 2:
    /// Input: S = "aaaaaaaaaa"
    /// Output: 55
    /// 
    /// Constraints:
    /// 1. 1 <= S.length <= 1000
    /// 2. S[i] consists of only lowercase English letters.
    /// </summary>
    int countLetters(string S);
#pragma endregion

#pragma region Sub Matrix Sum
    /// <summary>
    /// Leet code # 363. Max Sum of Rectangle No Larger Than K  
    ///
    /// Given a non-empty 2D matrix matrix and an integer k, find the max sum 
    /// of a rectangle in the matrix such that its sum is no larger than k.
    /// 
    /// Example:
    /// Given matrix = 
    /// [
    ///  [1,  0, 1],
    ///  [0, -2, 3]
    /// ]
    /// k = 2
    /// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 
    /// and 2 is the max number no larger than k (k = 2).
    /// Note:
    /// 1.The rectangle inside the matrix must have an area > 0.
    /// 2.What if the number of rows is much larger than the number of columns?
    /// </summary>
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k);

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

#pragma endregion

#pragma region Count Subarray
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
    /// Note:
    ///
    /// 1. 1 <= A.length <= 50000
    /// 2. 0 <= A[i] <= 100000
    /// </summary>
    int validSubarrays(vector<int>& nums);
#pragma endregion

#pragma region Prefix Sum
    /// <summary>
    /// Leet code #53. Maximum Subarray
    /// 
    /// Given an integer array nums, find the contiguous subarray (containing 
    /// at least one number) which has the largest sum and return its sum.
    ///
    /// Example:
    ///
    /// Input: [-2,1,-3,4,-1,2,1,-5,4],
    /// Output: 6
    /// Explanation: [4,-1,2,1] has the largest sum = 6.
    ///
    /// Follow up:
    /// If you have figured out the O(n) solution, try coding another solution 
    /// using the divide and conquer approach, which is more subtle.
    /// </summary>
    int maxSubArray(vector<int>& nums);

    /// <summary>
    /// Leet code #134. Gas Station
    /// 
    /// There are N gas stations along a circular route, where the amount of gas 
    /// at station i is gas[i].
    ///
    /// You have a car with an unlimited gas tank and it costs cost[i] of gas to 
    /// travel from station i to its next station (i+1). You begin the journey 
    /// with an empty tank at one of the gas stations.
    ///
    /// Return the starting gas station's index if you can travel around the 
    /// circuit once in the clockwise direction, otherwise return -1.
    ///
    /// Note:
    ///
    /// If there exists a solution, it is guaranteed to be unique.
    /// Both input arrays are non-empty and have the same length.
    /// Each element in the input arrays is a non-negative integer.
    ///
    /// Example 1:
    /// Input: 
    /// gas  = [1,2,3,4,5]
    /// cost = [3,4,5,1,2]
    /// Output: 3
    ///
    /// Explanation:
    /// 1. Start at station 3 (index 3) and fill up with 4 unit of gas. 
    ///    Your tank = 0 + 4 = 4
    /// 2. Travel to station 4. Your tank = 4 - 1 + 5 = 8
    /// 3. Travel to station 0. Your tank = 8 - 2 + 1 = 7
    /// 4. Travel to station 1. Your tank = 7 - 3 + 2 = 6
    /// 5. Travel to station 2. Your tank = 6 - 4 + 3 = 5
    /// 6. Travel to station 3. The cost is 5. Your gas is just enough to travel 
    ///    back to station 3.
    /// 7. Therefore, return 3 as the starting index.
    ///
    /// Example 2:
    /// Input: 
    /// gas  = [2,3,4]
    /// cost = [3,4,3]
    /// Output: -1
    /// 
    /// Explanation:
    /// 1. You can't start at station 0 or 1, as there is not enough gas to travel 
    ///    to the next station.
    /// 2. Let's start at station 2 and fill up with 4 unit of gas. Your 
    ///    tank = 0 + 4 = 4
    /// 3. Travel to station 0. Your tank = 4 - 3 + 2 = 3
    /// 4. Travel to station 1. Your tank = 3 - 3 + 3 = 3
    /// 5. You cannot travel back to station 2, as it requires 4 unit of gas but 
    ///    you only have 3.
    /// 6. Therefore, you can't travel around the circuit once no matter where 
    ///    you start.
    /// </summary>
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

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
    /// Leet code #152. Maximum Product Subarray
    /// 
    /// Given an integer array nums, find the contiguous subarray within an array 
    /// (containing at least one number) which has the largest product.
    ///
    /// Example 1:
    ///
    /// Input: [2,3,-2,4]
    /// Output: 6
    /// Explanation: [2,3] has the largest product 6.
    ///
    /// Example 2:
    ///
    /// Input: [-2,0,-1]
    /// Output: 0
    /// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
    /// </summary>
    int maxProduct(vector<int>& nums);

    /// <summary>
    /// Leet code #325. Maximum Size Subarray Sum Equals k
    /// 
    /// Given an array nums and a target value k, find the maximum length of a subarray that sums to k. 
    /// If there isn't one, return 0 instead. 
    /// Note:
    /// The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range. 
    ///
    /// Example 1:
    /// Given nums = [1, -1, 5, -2, 3], k = 3,
    /// return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest) 
    ///
    /// Example 2:
    /// Given nums = [-2, -1, 2, 1], k = 1,
    /// return 2. (because the subarray [-1, 2] sums to 1 and is the longest) 
    ///
    /// Follow Up:
    /// Can you do it in O(n) time? 
    /// </summary>
    int maxSubArrayLen(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #422. Valid Word Square    
    /// 
    /// Given a sequence of words, check whether it forms a valid word square. 
    /// A sequence of words forms a valid word square if the kth row and column 
    /// read the exact same string, where 0 �� k < max(numRows, numColumns).
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
    /// Leet code #523. Continuous Subarray Sum   
    /// 
    /// Given a list of non-negative numbers and a target integer k, write a 
    /// function to check if the array has a continuous subarray of size at 
    /// least 2 that sums up to the multiple of k, that is, sums up to n*k 
    /// where n is also an integer.
    ///
    /// Example 1:
    /// Input: [23, 2, 4, 6, 7],  k=6
    /// Output: True
    /// Explanation: Because [2, 4] is a continuous subarray of size 2 and 
    /// sums up to 6.
    /// Example 2:
    /// Input: [23, 2, 6, 4, 7],  k=42
    /// Output: True
    /// Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of 
    /// size 5 and sums up to 42.
    /// Note:
    /// The length of the array won't exceed 10,000.
    /// You may assume the sum of all the numbers is in the range of a 
    /// signed 32-bit integer.
    /// </summary>
    bool checkSubarraySum(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #525. Contiguous Array    
    /// 
    /// Given a binary array, find the maximum length of a contiguous subarray 
    /// with equal number of 0 and 1. 
    /// Example 1:
    /// Input: [0,1]
    /// Output: 2
    /// Explanation: [0, 1] is the longest contiguous subarray with equal 
    /// number of 0 and 1.
    ///
    /// Example 2:
    /// Input: [0,1,0]
    /// Output: 2
    /// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with 
    /// equal number of 0 and 1.
    /// Note: The length of the given binary array will not exceed 50,000. 
    /// </summary>
    int findMaxLength(vector<int>& nums);

    /// <summary>
    /// Leet code #548. Split Array with Equal Sum������ 
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
    /// Leet code #560. Subarray Sum Equals K
    /// Given an array of integers and an integer k, you need to find the 
    /// total number of continuous subarrays whose sum equals to k.
    /// Example 1:
    /// Input:nums = [1,1,1], k = 2 
    /// Output: 2
    ///
    /// Note:
    /// The length of the array is in range [1, 20,000].
    /// The range of numbers in the array is [-1000, 1000] and the range of 
    /// the integer k is [-1e7, 1e7].
    /// </summary>
    int subarraySum(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #930. Binary Subarrays With Sum
    /// 
    /// In an array A of 0s and 1s, how many non-empty subarrays have sum S?
    /// 
    /// Example 1:
    /// Input: A = [1,0,1,0,1], S = 2
    /// Output: 4
    /// Explanation: 
    /// The 4 subarrays are bolded below:
    /// [1,0,1,0,1]
    /// [1,0,1,0,1]
    /// [1,0,1,0,1]
    /// [1,0,1,0,1]
    /// 
    /// Note:
    /// 
    /// 1. A.length <= 30000
    /// 2. 0 <= S <= A.length
    /// 3. A[i] is either 0 or 1.
    /// </summary>
    int numSubarraysWithSum(vector<int>& A, int S);

    /// <summary>
    /// Leet code #974. Subarray Sums Divisible by K
    /// 
    /// Given an array A of integers, return the number of (contiguous, non-empty) 
    /// subarrays that have a sum divisible by K.
    ///
    /// Example 1:
    ///
    /// Input: A = [4,5,0,-2,-3,1], K = 5
    /// Output: 7
    /// Explanation: There are 7 subarrays with a sum divisible by K = 5:
    /// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], 
    /// [-2, -3]
    /// 
    /// Note:
    ///
    /// 1. 1 <= A.length <= 30000
    /// 2. -10000 <= A[i] <= 10000
    /// 3. 2 <= K <= 10000
    /// </summary>
    int subarraysDivByK(vector<int>& A, int K);

    /// <summary>
    /// Leet code #1124. Longest Well-Performing Interval
    /// 
    /// We are given hours, a list of the number of hours worked per day for a 
    /// given employee.
    /// A day is considered to be a tiring day if and only if the number of hours 
    /// worked is (strictly) greater than 8.
    /// A well-performing interval is an interval of days for which the number of 
    /// tiring days is strictly larger than the number of non-tiring days.
    /// Return the length of the longest well-performing interval.
    /// 
    /// Example 1:
    /// Input: hours = [9,9,6,0,6,6,9]
    /// Output: 3
    /// Explanation: The longest well-performing interval is [9,9,6].
    /// 
    /// Constraints:
    /// 1. 1 <= hours.length <= 10000
    /// 2. 0 <= hours[i] <= 16
    /// </summary>
    int longestWPI(vector<int>& hours);

    /// <summary>
    /// Leet code #1151. Minimum Swaps to Group All 1's Together
    /// 
    /// Given a binary array data, return the minimum number of swaps required 
    /// to group all 1��s present in the array together in any place in the array.
    /// 
    /// Example 1:
    /// Input: [1,0,1,0,1]
    /// Output: 1
    /// Explanation: 
    /// There are 3 ways to group all 1's together:
    /// [1,1,1,0,0] using 1 swap.
    /// [0,1,1,1,0] using 2 swaps.
    /// [0,0,1,1,1] using 1 swap.
    /// The minimum is 1.
    ///
    /// Example 2:
    /// Input: [0,0,0,1,0]
    /// Output: 0
    /// Explanation: 
    /// Since there is only one 1 in the array, no swaps needed.
    ///
    /// Example 3:
    /// Input: [1,0,1,0,1,0,0,1,1,0,1]
    /// Output: 3
    /// Explanation: 
    /// One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
    /// 
    /// Note:
    /// 1. 1 <= data.length <= 10^5
    /// 2. 0 <= data[i] <= 1
    /// </summary>
    int minSwaps(vector<int>& data);

    /// <summary>
    /// Leet code #1186. Maximum Subarray Sum with One Deletion
    /// 
    /// Given an array of integers, return the maximum sum for a non-empty 
    /// subarray (contiguous elements) with at most one element deletion. 
    /// In other words, you want to choose a subarray and optionally delete 
    /// one element from it so that there is still at least one element left 
    /// and the sum of the remaining elements is maximum possible.
    /// Note that the subarray needs to be non-empty after deleting one element.
    /// 
    /// Example 1:
    /// Input: arr = [1,-2,0,3]
    /// Output: 4
    /// Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the 
    /// subarray [1, 0, 3] becomes the maximum value.
    ///
    /// Example 2:
    /// Input: arr = [1,-2,-2,3]
    /// Output: 3
    /// Explanation: We just choose [3] and it's the maximum sum.
    ///
    /// Example 3:
    /// Input: arr = [-1,-1,-1,-1]
    /// Output: -1
    /// Explanation: The final subarray needs to be non-empty. You can't 
    /// choose [-1] and delete -1 from it, then get an empty subarray to make 
    /// the sum equals to 0.
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. -10^4 <= arr[i] <= 10^4
    /// </summary>
    int maximumSum(vector<int>& arr);

    /// <summary>
    /// Leet code #1191. K-Concatenation Maximum Sum
    /// 
    /// Given an integer array arr and an integer k, modify the array by repeating 
    /// it k times.
    /// For example, if arr = [1, 2] and k = 3 then the modified array will 
    /// be [1, 2, 1, 2, 1, 2].
    /// Return the maximum sub-array sum in the modified array. Note that the 
    /// length of the sub-array can be 0 and its sum in that case is 0.
    ///
    /// As the answer can be very large, return the answer modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: arr = [1,2], k = 3
    /// Output: 9
    ///
    /// Example 2:
    /// Input: arr = [1,-2,1], k = 5
    /// Output: 2
    /// Example 3:
    /// Input: arr = [-1,-2], k = 7
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 1 <= k <= 10^5
    /// 3. -10^4 <= arr[i] <= 10^4
    /// </summary>
    int kConcatenationMaxSum(vector<int>& arr, int k);

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
    /// Leet code #238. Product of Array Except Self    
    ///
    /// Given an array of n integers where n > 1, nums, return an array 
    /// output such that output[i] is equal to the product of all the elements 
    /// of nums except nums[i]. 
    ///
    /// Solve it without division and in O(n). 
    /// For example, given [1,2,3,4], return [24,12,8,6]. 
    /// 
    /// Follow up:
    /// Could you solve it with constant space complexity? 
    /// (Note: The output array does not count as extra space for the purpose of 
    /// space complexity analysis.)
    /// </summary>
    vector<int> productExceptSelf(vector<int>& nums);

    /// <summary>
    /// Leet code #1477. Find Two Non-overlapping Sub-arrays Each With 
    ///                  Target Sum
    ///
    /// Medium
    ///
    /// Given an array of integers arr and an integer target.
    ///
    /// You have to find two non-overlapping sub-arrays of arr each with 
    /// sum equal target. There can be multiple answers so you have to 
    /// find an answer where the sum of the lengths of the two sub-arrays 
    /// is minimum.
    ///
    /// Return the minimum sum of the lengths of the two required 
    /// sub-arrays, or return -1 if you cannot find such two sub-arrays.
    ///
    /// Example 1:
    /// Input: arr = [3,2,2,4,3], target = 3
    /// Output: 2
    /// Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The 
    /// sum of their lengths is 2.
    ///
    /// Example 2:
    /// Input: arr = [7,3,4,7], target = 7
    /// Output: 2
    /// Explanation: Although we have three non-overlapping sub-arrays 
    /// of sum = 7 ([7], [3,4] and [7]), but we will choose the first 
    /// and third sub-arrays as the sum of their lengths is 2.
    ///
    /// Example 3:
    /// Input: arr = [4,3,2,6,2,3,4], target = 6
    /// Output: -1
    /// Explanation: We have only one sub-array of sum = 6.
    ///
    /// Example 4:
    /// Input: arr = [5,5,4,4,5], target = 3
    /// Output: -1
    /// Explanation: We cannot find a sub-array of sum = 3.
    ///
    /// Example 5:
    /// Input: arr = [3,1,1,1,5,1,2,1], target = 3
    /// Output: 3
    /// Explanation: Note that sub-arrays [1,2] and [2,1] cannot be an 
    /// answer because they overlap.
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 1 <= arr[i] <= 1000
    /// 3. 1 <= target <= 10^8
    /// </summary> 
    int minSumOfLengths(vector<int>& arr, int target);

#pragma endregion

#pragma region Array Traverse
    /// <summary>
    /// Leet code #48. Rotate Image
    /// 
    /// You are given an n x n 2D matrix representing an image.
    ///
    /// Rotate the image by 90 degrees (clockwise).
    ///
    /// Note:
    ///
    /// You have to rotate the image in-place, which means you have to 
    /// modify the input 2D matrix directly. DO NOT allocate another 2D 
    /// matrix and do the rotation.
    ///
    /// Example 1:
    ///
    /// Given input matrix = 
    /// [
    ///   [1,2,3],
    ///  [4,5,6],
    ///  [7,8,9]
    /// ],
    ///
    /// rotate the input matrix in-place such that it becomes:
    /// [
    ///  [7,4,1],
    ///  [8,5,2],
    ///  [9,6,3]
    /// ]
    ///
    /// Example 2:
    ///
    /// Given input matrix =
    /// [
    ///   [ 5, 1, 9,11],
    ///   [ 2, 4, 8,10],
    ///   [13, 3, 6, 7],
    ///   [15,14,12,16]
    /// ], 
    ///
    /// rotate the input matrix in-place such that it becomes:
    /// [
    ///   [15,13, 2, 5],
    ///   [14, 3, 4, 1],
    //    [12, 6, 8, 9],
    ///   [16, 7,10,11]
    /// ]
    /// </summary>
    void rotate(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #54. Spiral Matrix
    /// 
    /// Given a matrix of m x n elements (m rows, n columns), return all elements 
    /// of the matrix in spiral order.
    ///
    /// Example 1:
    ///
    /// Input:
    /// [
    ///  [ 1, 2, 3 ],
    ///  [ 4, 5, 6 ],
    ///  [ 7, 8, 9 ]
    /// ]
    /// Output: [1,2,3,6,9,8,7,4,5]
    ///
    /// Example 2:
    ///
    /// Input:
    /// [
    ///  [1, 2, 3, 4],
    ///   [5, 6, 7, 8],
    ///  [9,10,11,12]
    /// ]
    /// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    /// You are given an n x n 2D matrix representing an image.
    /// </summary>
    vector<int> spiralOrder(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #59. Spiral Matrix II
    /// 
    /// Given a positive integer n, generate a square matrix filled with elements
    /// from 1 to n2 in spiral order.
    ///
    /// Example:
    ///
    /// Input: 3
    /// Output:
    /// [
    ///  [ 1, 2, 3 ],
    ///  [ 8, 9, 4 ],
    ///  [ 7, 6, 5 ]
    /// ]
    /// </summary>
    vector<vector<int>> generateMatrix(int n);

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
    /// Leet code #1424. Diagonal Traverse II
    /// 
    /// Medium
    ///
    /// Given a list of lists of integers, nums, return all elements of nums 
    /// in diagonal order as shown in the below images.
    /// 
    /// Example 1:
    /// Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
    /// Output: [1,4,2,7,5,3,8,6,9]
    ///
    /// Example 2:
    /// Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
    /// Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
    ///
    /// Example 3:
    /// Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
    /// Output: [1,4,2,5,3,8,6,9,7,10,11]
    ///
    /// Example 4:
    /// Input: nums = [[1,2,3,4,5,6]]
    /// Output: [1,2,3,4,5,6]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i].length <= 10^5
    /// 3. 1 <= nums[i][j] <= 10^9
    /// 4. There at most 10^5 elements in nums.
    /// </summary>
    vector<int> findDiagonalOrderII(vector<vector<int>>& nums);

    /// <summary>
    /// Leet code #1036. Escape a Large Maze
    /// 
    /// In a 1 million by 1 million grid, the coordinates of each grid square
    /// are (x, y) with 0 <= x, y < 10^6.
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
    /// The target square is inaccessible starting from the source square, 
    /// because we can't walk outside the grid.
    ///
    /// Example 2:
    ///
    /// Input: blocked = [], source = [0,0], target = [999999,999999]
    /// Output: true
    /// Explanation: 
    /// Because there are no blocked cells, it's possible to reach the target 
    /// square.
    /// 
    /// Note:
    /// 1. 0 <= blocked.length <= 200
    /// 2. blocked[i].length == 2
    /// 3. 0 <= blocked[i][j] < 10^6
    /// 4. source.length == target.length == 2
    /// 5. 0 <= source[i][j], target[i][j] < 10^6
    /// 6. source != target
    /// </summary>
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target);

    /// <summary>
    /// Leet code #950. Reveal Cards In Increasing Order
    /// 
    /// In a deck of cards, every card has a unique integer. You can order 
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
    /// Note:
    /// 1. 1 <= A.length <= 1000
    /// 2. 1 <= A[i] <= 10^6
    /// 3. A[i] != A[j] for all i != j
    /// </summary>
    vector<int> deckRevealedIncreasing(vector<int>& deck);

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
#pragma endregion

#pragma region Array
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
    /// Leet code #364. Nested List Weight Sum II   
    /// </summary>
    int countDepth(vector<NestedInteger>& nestedList);

    /// <summary>
    /// Leet code #364. Nested List Weight Sum II   
    /// </summary>
    int depthSumInverse(vector<NestedInteger>& nestedList, int depth);

    /// <summary>
    /// Leet code #364. Nested List Weight Sum II  
    /// 
    /// Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
    /// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
    /// Different from the previous question where weight is increasing from root to leaf, now the weight is 
    /// defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
    /// Example 1:
    /// Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
    /// Example 2:
    /// Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27) 
    /// </summary>
    int depthSumInverse(vector<NestedInteger>& nestedList);

    /// <summary>
    /// Leet code #1198. Find Smallest Common Element in All Rows
    /// 
    /// Given a matrix mat where every row is sorted in increasing order, return 
    /// the smallest common element in all rows.
    ///
    /// If there is no common element, return -1.
    ///
    /// Example 1:
    ///
    /// Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
    /// Output: 5
    /// 
    ///
    /// Constraints:
    ///
    /// 1. 1 <= mat.length, mat[i].length <= 500
    /// 2. 1 <= mat[i][j] <= 10^4
    /// 3. mat[i] is sorted in increasing order.
    /// </summary>
    int smallestCommonElement(vector<vector<int>>& mat);

    /// <summary>
    /// Leet code #289. Game of Life 
    ///
    /// According to the Wikipedia's article: "The Game of Life, also known 
    /// simply as Life, is a cellular automaton devised by the British 
    /// mathematician John Horton Conway in 1970." 
    /// Given a board with m by n cells, each cell has an initial state 
    /// live (1) or dead (0). 
    /// Each cell interacts with its eight neighbors (horizontal, vertical, 
    /// diagonal) using the 
    /// following four rules (taken from the above Wikipedia article): 	
    /// 1.Any live cell with fewer than two live neighbors dies, as if caused 
    ///   by under-population.
    /// 2.Any live cell with two or three live neighbors lives on to the next 
    ///   generation.
    /// 3.Any live cell with more than three live neighbors dies, as if by 
    ///   over-population..
    /// 4.Any dead cell with exactly three live neighbors becomes a live cell, 
    ///   as if by reproduction.
    /// Write a function to compute the next state (after one update) of the 
    /// board given its current state.
    /// Follow up: 
    /// 1.Could you solve it in-place? Remember that the board needs to be 
    ///   updated at the same time: You cannot update some cells first and 
    ///   then use their updated values to update other cells.
    /// 2.In this question, we represent the board using a 2D array. In 
    ///   principle, the board is infinite, which would cause problems when 
    ///   the active area encroaches the border of the array. How would you 
    ///   address these problems?
    /// </summary>
    void gameOfLife(vector<vector<int>>& board);

    /// <summary>
    /// Leet code #1208. Get Equal Substrings Within Budget
    ///
    /// You are given two strings s and t of the same length. You want to change
    /// s to t. Changing the i-th character of s to i-th character of t costs 
    /// |s[i] - t[i]| that is, the absolute difference between the ASCII values 
    /// of the characters.
    ///
    /// You are also given an integer maxCost.
    ///
    /// Return the maximum length of a substring of s that can be changed to be 
    /// the same as the corresponding substring of twith a cost less than or equal 
    /// to maxCost.
    ///
    /// If there is no substring from s that can be changed to its corresponding 
    /// substring from t, return 0.
    ///
    /// Example 1:
    ///
    /// Input: s = "abcd", t = "bcdf", maxCost = 3
    /// Output: 3
    /// Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum 
    /// length is 3.
    ///
    /// Example 2:
    /// 
    /// Input: s = "abcd", t = "cdef", maxCost = 3
    /// Output: 1
    /// Explanation: Each character in s costs 2 to change to charactor in t, so 
    /// the maximum length is 1.
    ///
    /// Example 3:
    ///
    /// Input: s = "abcd", t = "acde", maxCost = 0
    /// Output: 1
    /// Explanation: You can't make any change, so the maximum length is 1.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length, t.length <= 10^5
    /// 2. 0 <= maxCost <= 10^6
    /// 3. s and t only contain lower case English letters.
    /// </summary>
    int equalSubstring(string s, string t, int maxCost);

    /// <summary>
    /// Leet code #1221. Split a String in Balanced Strings
    /// 
    /// Balanced strings are those who have equal quantity of 'L' and 'R' 
    /// characters.
    ///
    /// Given a balanced string s split it in the maximum amount of balanced 
    /// strings.
    ///
    /// Return the maximum amount of splitted balanced strings.
    ///
    /// Example 1:
    ///
    /// Input: s = "RLRRLLRLRL"
    /// Output: 4
    /// Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring 
    /// contains same number of 'L' and 'R'.
    ///
    /// Example 2:
    ///
    /// Input: s = "RLLLLRRRLR"
    /// Output: 3
    /// Explanation: s can be split into "RL", "LLLRRR", "LR", each substring 
    /// contains same number of 'L' and 'R'.
    ///
    /// Example 3:
    ///
    /// Input: s = "LLLLRRRR"
    /// Output: 1
    /// Explanation: s can be split into "LLLLRRRR".
    ///  
    /// Constraints:
    /// 
    /// 1. 1 <= s.length <= 1000
    /// 2. s[i] = 'L' or 'R'
    /// </summary>
    int balancedStringSplit(string s);

    /// <summary>
    /// Leet code #1222. Queens That Can Attack the King
    /// 
    /// On an 8x8 chessboard, there can be multiple Black Queens and one 
    /// White King.
    ///
    /// Given an array of integer coordinates queens that represents the 
    /// positions of the Black Queens, and a pair of coordinates king that 
    /// represent the position of the White King, return the coordinates 
    /// of all the queens (in any order) that can attack the King.
    ///
    /// 
    /// Example 1:
    /// 
    /// Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
    /// Output: [[0,1],[1,0],[3,3]]
    /// Explanation:  
    /// The queen at [0,1] can attack the king cause they're in the same row. 
    /// The queen at [1,0] can attack the king cause they're in the same column. 
    /// The queen at [3,3] can attack the king cause they're in the same diagnal.
    /// The queen at [0,4] can't attack the king cause it's blocked by the 
    /// queen at [0,1]. 
    /// The queen at [4,0] can't attack the king cause it's blocked by the 
    /// queen at [1,0]. 
    /// The queen at [2,4] can't attack the king cause it's not in the same 
    /// row/column/diagnal as the king.
    ///
    /// Example 2:
    /// Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
    /// Output: [[2,2],[3,4],[4,4]]
    ///
    /// Example 3:
    /// Input: queens = 
    /// [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],
    /// [0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],
    /// [0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
    /// Output: [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
    /// 
    /// Constraints:
    /// 1. 1 <= queens.length <= 63
    /// 2. queens[0].length == 2
    /// 3. 0 <= queens[i][j] < 8
    /// 4. king.length == 2
    /// 5. 0 <= king[0], king[1] < 8
    /// 6. At most one piece is allowed in a cell.
    /// </summary>
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king);

    /// <summary>
    /// Leet code #1228. Missing Number In Arithmetic Progression
    /// 
    /// In some array arr, the values were in arithmetic progression: the 
    /// values arr[i+1] - arr[i] are all equal for every 
    /// 0 <= i < arr.length - 1.
    ///
    /// Then, a value from arr was removed that was not the first or last 
    /// value in the array.
    ///
    /// Return the removed value.
    ///
    /// Example 1:
    ///
    /// Input: arr = [5,7,11,13]
    /// Output: 9
    /// Explanation: The previous array was [5,7,9,11,13].
    ///
    /// Example 2:
    /// Input: arr = [15,13,12]
    /// Output: 14
    /// Explanation: The previous array was [15,14,13,12].
    ///
    /// Constraints:
    /// 1. 3 <= arr.length <= 1000
    /// 2. 0 <= arr[i] <= 10^5
    /// </summary>
    int missingNumber(vector<int>& arr);

    /// <summary>
    /// Leet code #1243. Array Transformation
    ///  
    /// Given an initial array arr, every day you produce a new array using the 
    /// array of the previous day.
    ///
    /// On the i-th day, you do the following operations on the array of day 
    /// i-1 to produce the array of day i:
    ///
    /// If an element is smaller than both its left neighbor and its right 
    /// neighbor, then this element is incremented.
    /// If an element is bigger than both its left neighbor and its right 
    /// neighbor, then this element is decremented.
    /// The first and last elements never change.
    /// After some days, the array does not change. Return that final array.
    /// 
    /// Example 1:
    /// Input: arr = [6,2,3,4]
    /// Output: [6,3,3,4]
    /// Explanation: 
    /// On the first day, the array is changed from [6,2,3,4] to [6,3,3,4].
    /// No more operations can be done to this array.
    ///
    /// Example 2:
    /// Input: arr = [1,6,3,4,3,5]
    /// Output: [1,4,4,4,4,5]
    /// Explanation: 
    /// On the first day, the array is changed from [1,6,3,4,3,5] 
    /// to [1,5,4,3,4,5].
    /// On the second day, the array is changed from [1,5,4,3,4,5] 
    /// to [1,4,4,4,4,5].
    /// No more operations can be done to this array.
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 100
    /// 2. 1 <= arr[i] <= 100
    /// </summary>
    vector<int> transformArray(vector<int>& arr);

    /// <summary>
    /// Leet code #1248. Count Number of Nice Subarrays
    ///  
    /// Given an array of integers nums and an integer k. A subarray is called 
    /// nice if there are k odd numbers on it.
    ///
    /// Return the number of nice sub-arrays.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,1,2,1,1], k = 3
    /// Output: 2
    /// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] 
    /// and [1,2,1,1].
    ///
    /// Example 2:
    ///
    /// Input: nums = [2,4,6], k = 1
    /// Output: 0
    /// Explanation: There is no odd numbers in the array.
    ///
    /// Example 3:
    ///
    /// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    /// Output: 16
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 50000
    /// 2. 1 <= nums[i] <= 10^5
    /// 3. 1 <= k <= nums.length
    /// </summary>
    int numberOfSubarrays(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #41. First Missing Positive
    /// 
    /// Given an unsorted integer array, find the smallest missing positive 
    /// integer.
    ///
    /// Example 1:
    ///
    /// Input: [1,2,0]
    /// Output: 3
    ///
    /// Example 2:
    ///
    /// Input: [3,4,-1,1]
    /// Output: 2
    ///
    /// Example 3:
    ///
    /// Input: [7,8,9,11,12]
    /// Output: 1
    ///
    /// Note:
    /// 
    /// Your algorithm should run in O(n) time and uses constant extra space.
    /// </summary>
    int firstMissingPositive(vector<int>& nums);

    /// <summary>
    /// Leet code #287. Find the Duplicate Number
    /// 
    /// Given an array nums containing n + 1 integers where each integer is 
    /// between 1 and n (inclusive), prove that at least one duplicate number 
    /// must exist. Assume that there is only one duplicate number, find the 
    /// duplicate one.
    ///
    /// Example 1:
    ///
    /// Input: [1,3,4,2,2]
    /// Output: 2
    ///
    /// Example 2:
    ///
    /// Input: [3,1,3,4,2]
    /// Output: 3
    /// Note:
    ///
    /// You must not modify the array (assume the array is read only).
    /// You must use only constant, O(1) extra space.
    /// Your runtime complexity should be less than O(n2).
    /// There is only one duplicate number in the array, but it could be 
    /// repeated more than once.
    /// </summary>
    int findDuplicate(vector<int>& nums);

    /// <summary>
    /// Leet code #229. Majority Element II
    /// 
    /// Given an integer array of size n, find all elements that appear more than
    /// n/3 times.
    ///
    /// Note: The algorithm should run in linear time and in O(1) space.
    ///
    /// Example 1:
    /// 
    /// Input: [3,2,3]
    /// Output: [3]
    ///
    /// Example 2:
    /// 
    /// Input: [1,1,1,3,3,2,2,2]
    /// Output: [1,2]
    /// </summary>
    vector<int> majorityElementII(vector<int>& nums);

    /// <summary>
    /// Leet code #169. Majority Element
    /// 
    /// Given an array of size n, find the majority element. The majority element
    /// is the element that appears more than n/2 times.
    ///
    /// You may assume that the array is non-empty and the majority element 
    /// always exist in the array.
    ///
    /// Example 1:
    ///
    /// Input: [3,2,3]
    /// Output: 3
    ///
    /// Example 2:
    ///
    /// Input: [2,2,1,1,1,2,2]
    /// Output: 2
    /// </summary>
    int majorityElement(vector<int>& nums);

    /// <summary>
    /// Leet code #1252. Cells with Odd Values in a Matrix
    /// 
    /// Given n and m which are the dimensions of a matrix initialized by zeros 
    /// and given an array indices where indices[i] = [ri, ci]. For each pair 
    /// of [ri, ci] you have to increment all cells in row ri and column ci by 1.
    ///
    /// Return the number of cells with odd values in the matrix after applying 
    /// the increment to all indices.
    /// 
    /// Example 1:
    /// 
    /// Input: n = 2, m = 3, indices = [[0,1],[1,1]]
    /// Output: 6
    /// Explanation: Initial matrix = [[0,0,0],[0,0,0]].
    /// After applying first increment it becomes [[1,2,1],[0,1,0]].
    /// The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.
    ///
    /// Example 2:
    /// 
    /// Input: n = 2, m = 2, indices = [[1,1],[0,0]]
    /// Output: 0
    /// Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the 
    /// final matrix.
    /// 
    /// Constraints:
    ///
    /// 1. 1 <= n <= 50
    /// 2. 1 <= m <= 50
    /// 3. 1 <= indices.length <= 100
    /// 4. 0 <= indices[i][0] < n
    /// 5. 0 <= indices[i][1] < m
    /// </summary>
    int oddCells(int n, int m, vector<vector<int>>& indices);

    /// <summary>
    /// Leet code #1253. Reconstruct a 2-Row Binary Matrix
    /// 
    /// Given the following details of a matrix with n columns and 2 rows :
    ///
    /// The matrix is a binary matrix, which means each element in the matrix 
    /// can be 0 or 1.
    /// The sum of elements of the 0-th(upper) row is given as upper.
    /// The sum of elements of the 1-st(lower) row is given as lower.
    /// The sum of elements in the i-th column(0-indexed) is colsum[i], where 
    /// colsum is given as an integer array with length n.
    /// Your task is to reconstruct the matrix with upper, lower and colsum.
    ///
    /// Return it as a 2-D integer array.
    /// 
    /// If there are more than one valid solution, any of them will be accepted.
    ///
    /// If no valid solution exists, return an empty 2-D array.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: upper = 2, lower = 1, colsum = [1,1,1]
    /// Output: [[1,1,0],[0,0,1]]
    /// Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct 
    /// answers.
    ///
    /// Example 2:
    ///
    /// Input: upper = 2, lower = 3, colsum = [2,2,1,1]
    /// Output: []
    ///
    /// Example 3:
    ///
    /// Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
    /// Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
    ///
    /// Constraints:
    /// 1. 1 <= colsum.length <= 10^5
    /// 2. 0 <= upper, lower <= colsum.length
    /// 3. 0 <= colsum[i] <= 2
    /// </summary>
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum);

    /// <summary>
    /// Leet code #1260. Shift 2D Grid
    /// 
    /// Given a 2D grid of size n * m and an integer k. You need to shift 
    /// the grid k times.
    ///
    /// In one shift operation:
    ///
    /// Element at grid[i][j] becomes at grid[i][j + 1].
    /// Element at grid[i][m - 1] becomes at grid[i + 1][0].
    /// Element at grid[n - 1][m - 1] becomes at grid[0][0].
    /// Return the 2D grid after applying shift operation k times.
    /// 
    /// Example 1:
    ///
    /// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
    /// Output: [[9,1,2],[3,4,5],[6,7,8]]
    ///
    /// Example 2:
    ///
    /// Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
    /// Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
    ///
    /// Example 3:
    ///
    /// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
    /// Output: [[1,2,3],[4,5,6],[7,8,9]]
    /// 
    /// Constraints:
    ///
    /// 1. 1 <= grid.length <= 50
    /// 2. 1 <= grid[i].length <= 50
    /// 3. -1000 <= grid[i][j] <= 1000
    /// 4. 0 <= k <= 100
    /// </summary>
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k);

    /// <summary>
    /// Leet code #1267. Count Servers that Communicate
    /// 
    /// You are given a map of a server center, represented as a m * n integer 
    /// matrix grid, where 1 means that on that cell there is a server and 0 
    /// means that it is no server. Two servers are said to communicate if 
    /// they are on the same row or on the same column.
    ///
    /// Return the number of servers that communicate with any other server.
    ///
    /// Example 1:
    ///
    /// Input: grid = [[1,0],[0,1]]
    /// Output: 0
    /// Explanation: No servers can communicate with others.
    ///
    /// Example 2:
    ///
    /// Input: grid = [[1,0],[1,1]]
    /// Output: 3
    /// Explanation: All three servers can communicate with at least one other 
    /// server.
    ///
    /// Example 3:
    ///
    /// Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
    /// Output: 4
    /// Explanation: The two servers in the first row can communicate with each 
    /// other. The two servers in the third column can communicate with each 
    /// other. The server at right bottom corner can't communicate with any 
    /// other server.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m <= 250
    /// 4. 1 <= n <= 250
    /// 5. grid[i][j] == 0 or 1
    /// </summary>
    int countServers(vector<vector<int>>& grid);

    /// <summary>
    /// Leetcode #1275. Find Winner on a Tic Tac Toe Game
    /// 
    /// Tic-tac-toe is played by two players A and B on a 3 x 3 grid.
    ///
    /// Here are the rules of Tic-Tac-Toe:
    ///
    /// Players take turns placing characters into empty squares (" ").
    /// The first player A always places "X" characters, while the second 
    /// player B always places "O" characters.
    /// "X" and "O" characters are always placed into empty squares, never 
    /// on filled ones.
    /// The game ends when there are 3 of the same (non-empty) character 
    /// filling any row, column, or diagonal.
    /// The game also ends if all squares are non-empty.
    /// No more moves can be played if the game is over.
    /// Given an array moves where each element is another array of size 2 
    /// corresponding to the row and column of the grid where they mark 
    /// their respective character in the order in which A and B play.
    ///
    /// Return the winner of the game if it exists (A or B), in case the 
    /// game ends in a draw return "Draw", if there are still movements 
    /// to play return "Pending".
    ///
    /// You can assume that moves is valid (It follows the rules of 
    /// Tic-Tac-Toe), the grid is initially empty and A will play first.
    ///
    /// Example 1:
    ///
    /// Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
    /// Output: "A"
    /// Explanation: "A" wins, he always plays first.
    /// "X  "    "X  "    "X  "    "X  "    "X  "
    /// "   " -> "   " -> " X " -> " X " -> " X "
    /// "   "    "O  "    "O  "    "OO "    "OOX"
    ///
    /// Example 2:
    ///
    /// Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
    /// Output: "B"
    /// Explanation: "B" wins.
    /// "X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
    /// "   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
    /// "   "    "   "    "   "    "   "    "   "    "O  "
    ///
    /// Example 3:
    ///
    /// Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
    /// Output: "Draw"
    /// Explanation: The game ends in a draw since there are no moves to make.
    /// "XXO"
    /// "OOX"
    /// "XOX"
    ///
    /// Example 4:
    ///
    /// Input: moves = [[0,0],[1,1]]
    /// Output: "Pending"
    /// Explanation: The game has not finished yet.
    /// "X  "
    /// " O "
    /// "   "
    /// 
    /// Constraints:
    /// 1. 1 <= moves.length <= 9
    /// 2. moves[i].length == 2
    /// 3. 0 <= moves[i][j] <= 2
    /// 4. There are no repeated elements on moves.
    /// 5. moves follow the rules of tic tac toe.
    /// </summary>
    string tictactoe(vector<vector<int>>& moves);

    /// <summary>
    /// Leet code #1282. Group the People Given the Group Size They Belong To
    ///
    /// Medium
    ///
    /// There are n people whose IDs go from 0 to n - 1 and each person 
    /// belongs exactly to one group. Given the array groupSizes of 
    /// length n telling the group size each person belongs to, return the 
    /// groups there are and the people's IDs each group includes.
    ///
    /// You can return any solution in any order and the same applies for 
    /// IDs. Also, it is guaranteed that there exists at least one solution. 
    ///
    /// Example 1:
    ///
    /// Input: groupSizes = [3,3,3,3,3,1,3]
    /// Output: [[5],[0,1,2],[3,4,6]]
    /// Explanation: 
    /// Other possible solutions are [[2,1,6],[5],[0,4,3]] 
    /// and [[5],[0,6,2],[4,3,1]].
    ///
    /// Example 2:
    ///
    /// Input: groupSizes = [2,1,3,3,3,2]
    /// Output: [[1],[0,5],[2,3,4]]
    /// 
    /// Constraints:
    /// 1. groupSizes.length == n
    /// 2. 1 <= n <= 500
    /// 3. 1 <= groupSizes[i] <= n
    /// </summary>
    vector<vector<int>> groupThePeople(vector<int>& groupSizes);

    /// <summary>
    /// Leet code #1287. Element Appearing More Than 25% In Sorted Array
    /// 
    /// Easy
    ///
    /// Given an integer array sorted in non-decreasing order, there is 
    /// exactly one integer in the array that occurs more than 25% of the time.
    ///
    /// Return that integer.
    ///
    /// Example 1:
    ///
    /// Input: arr = [1,2,2,6,6,6,6,7,10]
    ///
    /// Output: 6
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^4
    /// 2. 0 <= arr[i] <= 10^5
    /// </summary>
    int findSpecialInteger(vector<int>& arr);

    /// <summary>
    /// Leet code #1292. Maximum Side Length of a Square with Sum Less than 
    /// or Equal to Threshold
    ///
    /// Medium
    ///
    /// Given a m x n matrix mat and an integer threshold. Return the maximum 
    /// side-length of a square with a sum less than or equal to threshold or 
    /// return 0 if there is no such square.
    /// 
    /// Example 1: 
    /// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], 
    /// threshold = 4
    /// Output: 2
    /// Explanation: The maximum side length of square with sum less than 4 
    /// is 2 as shown.
    ///
    /// Example 2:
    /// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],
    /// [2,2,2,2,2]], threshold = 1
    /// Output: 0
    ///
    /// Example 3:
    /// Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
    /// Output: 3
    ///
    /// Example 4:
    /// Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], 
    /// threshold = 40184
    /// Output: 2
    /// </summary>
    int maxSideLength(vector<vector<int>>& mat, int threshold);

    /// <summary>
    /// Leetcode #1296. Divide Array in Sets of K Consecutive Numbers
    /// 
    /// Given an array of integers nums and a positive integer k, find 
    /// whether it's possible to divide this array into sets of k 
    /// consecutive numbers
    /// Return True if its possible otherwise return False.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,2,3,3,4,4,5,6], k = 4
    /// Output: true
    /// Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
    ///
    /// Example 2:
    ///
    /// Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
    /// Output: true
    /// Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] 
    /// and [9,10,11].
    ///
    /// Example 3:
    ///
    /// Input: nums = [3,3,2,2,1,1], k = 3
    /// Output: true
    ///
    /// Example 4:
    ///
    /// Input: nums = [1,2,3,4], k = 3
    /// Output: false
    /// Explanation: Each array should be divided in subarrays of size 3.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= nums.length
    /// </summary>
    bool isPossibleDivide(vector<int>& nums, int k);

    /// <summary>
    /// Leetcode #1299. Replace Elements with Greatest Element on Right Side
    ///
    /// Easy	
    ///
    /// Given an array arr, replace every element in that array with the 
    /// greatest element among the elements to its right, and replace the 
    /// last element with -1.
    ///
    /// After doing so, return the array.
    /// 
    /// Example 1:
    /// Input: arr = [17,18,5,4,6,1]
    /// Output: [18,6,6,6,1,-1]
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^4
    /// 2. 1 <= arr[i] <= 10^5
    /// </summary>
    vector<int> replaceElements(vector<int>& arr);

    /// <summary>
    /// Leetcode #1306. Jump Game III
    ///
    /// Medium
    ///
    /// Given an array of non-negative integers arr, you are initially 
    /// positioned at start index of the array. When you are at index i, 
    /// you can jump to i + arr[i] or i - arr[i], check if you can reach 
    /// to any index with value 0.
    ///
    /// Notice that you can not jump outside of the array at any time.
    /// 
    /// Example 1:
    /// Input: arr = [4,2,3,0,3,1,2], start = 5
    /// Output: true
    /// Explanation: 
    /// All possible ways to reach at index 3 with value 0 are: 
    /// index 5 -> index 4 -> index 1 -> index 3 
    /// index 5 -> index 6 -> index 4 -> index 1 -> index 3 
    ///
    /// Example 2:
    /// Input: arr = [4,2,3,0,3,1,2], start = 0
    /// Output: true 
    /// Explanation: 
    /// One possible way to reach at index 3 with value 0 is: 
    /// index 0 -> index 4 -> index 1 -> index 3
    ///
    /// Example 3:
    /// Input: arr = [3,0,2,1,2], start = 2
    /// Output: false
    /// Explanation: There is no way to reach at index 1 with value 0.
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 5 * 10^4
    /// 2. 0 <= arr[i] < arr.length
    /// 3. 0 <= start < arr.length
    /// </summary>
    bool canReach(vector<int>& arr, int start);

    /// <summary>
    /// Leet code #448. Find All Numbers Disappeared in an Array
    ///
    /// Given an array of integers where 1 �� a[i] �� n (n = size of array), 
    /// some elements appear twice and others appear once.
    /// Find all the elements of [1, n] inclusive that do not appear in this 
    /// array.
    /// Could you do it without extra space and in O(n) runtime? You may 
    /// assume the returned list does not count as extra space.
    ///
    /// Example:
    ///
    /// Input:
    /// [4,3,2,7,8,2,3,1]
    /// Output:
    /// [5,6]
    /// </summary>
    vector<int> findDisappearedNumbers(vector<int>& nums);

    /// <summary>
    /// Leet code #36. Valid Sudoku
    ///
    /// Medium
    ///
    /// Determine if a 9x9 Sudoku board is valid. Only the filled cells need 
    /// to be validated according to the following rules:
    ///
    /// Each row must contain the digits 1-9 without repetition.
    /// Each column must contain the digits 1-9 without repetition.
    /// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 
    /// without repetition.
    /// 
    /// A partially filled sudoku which is valid.
    ///  
    /// The Sudoku board could be partially filled, where empty cells are 
    /// filled with the character '.'.
    ///
    /// Example 1:
    ///
    /// Input:
    /// [
    ///  ["5","3",".",".","7",".",".",".","."],
    ///  ["6",".",".","1","9","5",".",".","."],
    ///  [".","9","8",".",".",".",".","6","."],
    ///  ["8",".",".",".","6",".",".",".","3"],
    ///  ["4",".",".","8",".","3",".",".","1"],
    ///  ["7",".",".",".","2",".",".",".","6"],
    ///  [".","6",".",".",".",".","2","8","."],
    ///  [".",".",".","4","1","9",".",".","5"],
    ///  [".",".",".",".","8",".",".","7","9"]
    /// ]
    /// Output: true
    /// Example 2:
    ///
    /// Input:
    /// [
    ///  ["8","3",".",".","7",".",".",".","."],
    ///  ["6",".",".","1","9","5",".",".","."],
    ///  [".","9","8",".",".",".",".","6","."],
    ///  ["8",".",".",".","6",".",".",".","3"],
    ///  ["4",".",".","8",".","3",".",".","1"],
    ///  ["7",".",".",".","2",".",".",".","6"],
    ///  [".","6",".",".",".",".","2","8","."],
    ///  [".",".",".","4","1","9",".",".","5"],
    ///  [".",".",".",".","8",".",".","7","9"]
    /// ]
    /// Output: false
    /// Explanation: Same as Example 1, except with the 5 in the top left 
    /// corner being modified to 8. Since there are two 8's in the top 
    /// left 3x3 sub-box, it is invalid.
    /// Note:
    ///
    /// A Sudoku board (partially filled) could be valid but is not 
    /// necessarily solvable.
    /// Only the filled cells need to be validated according to the mentioned 
    /// rules.
    /// The given board contain only digits 1-9 and the character '.'.
    /// The given board size is always 9x9.
    /// </summary>
    bool isValidSudoku(vector<vector<char>>& board);

    /// <summary>
    /// Leet code #1310. XOR Queries of a Subarray
    /// 
    /// Medium
    ///
    /// Given the array arr of positive integers and the array queries where 
    /// queries[i] = [Li, Ri], for each query i compute the XOR of elements 
    /// from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
    /// Return an array containing the result for the given queries. 
    /// 
    /// Example 1:
    /// Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
    /// Output: [2,7,14,8] 
    /// Explanation: 
    /// The binary representation of the elements in the array are:
    /// 1 = 0001 
    /// 3 = 0011 
    /// 4 = 0100 
    /// 8 = 1000 
    /// The XOR values for queries are:
    /// [0,1] = 1 xor 3 = 2 
    /// [1,2] = 3 xor 4 = 7 
    /// [0,3] = 1 xor 3 xor 4 xor 8 = 14 
    /// [3,3] = 8
    ///
    /// Example 2:
    /// Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
    /// Output: [8,0,4,4]
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 3 * 10^4
    /// 2. 1 <= arr[i] <= 10^9
    /// 3. 1 <= queries.length <= 3 * 10^4
    /// 4. queries[i].length == 2
    /// 5. 0 <= queries[i][0] <= queries[i][1] < arr.length
    /// </summary>
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code #1313. Decompress Run-Length Encoded List
    ///
    /// Easy
    ///
    /// We are given a list nums of integers representing a list compressed with 
    /// run-length encoding.
    ///
    /// Consider each adjacent pair of elements [a, b] = [nums[2*i], nums[2*i+1]] 
    /// (with i >= 0).  For each such pair, there are a elements with value b in 
    /// the decompressed list.
    ///
    /// Return the decompressed list.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,2,3,4]
    /// Output: [2,4,4,4]
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 100
    /// 2. nums.length % 2 == 0
    /// 3. 1 <= nums[i] <= 100
    /// </summary>
    vector<int> decompressRLElist(vector<int>& nums);

    /// <summary>
    /// Leet code #1314. Matrix Block Sum
    ///
    /// Medium
    ///
    /// Given a m * n matrix mat and an integer K, return a matrix answer where 
    /// each answer[i][j] is the sum of all elements mat[r][c] for 
    /// i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position 
    /// in the matrix. 
    /// 
    /// Example 1:
    /// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
    /// Output: [[12,21,16],[27,45,33],[24,39,28]]
    ///
    /// Example 2:
    /// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
    /// Output: [[45,45,45],[45,45,45],[45,45,45]]
    /// 
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[i].length
    /// 3. 1 <= m, n, K <= 100
    /// 4. 1 <= mat[i][j] <= 100
    /// </summary>
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K);

    /// <summary>
    /// Leet code #413. Arithmetic Slices
    ///
    /// A sequence of number is called arithmetic if it consists of at least 
    /// three elements and if the difference between 
    /// any two consecutive elements is the same
    /// For example, these are arithmetic sequence:
    /// 1, 3, 5, 7, 9
    /// 7, 7, 7, 7
    /// 3, -1, -5, -9
    /// The following sequence is not arithmetic.
    /// 1, 1, 2, 5, 7
    /// A zero-indexed array A consisting of N numbers is given. A 
    /// slice of that array is any pair of integers (P, Q) such that 
    /// 0 <= P < Q < N.
    /// A slice (P, Q) of array A is called arithmetic if the sequence:
    /// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, 
    /// this means that P + 1 < Q.
    /// The function should return the number of arithmetic slices in the 
    /// array A. 
    /// Example: 
    /// A = [1, 2, 3, 4]
    /// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] 
    /// and [1, 2, 3, 4] itself.
    /// </summary>
    int numberOfArithmeticSlices(vector<int>& A);

    /// <summary>
    /// Leet code #485. Max Consecutive Ones  
    /// 
    /// Given a binary array, find the maximum number of consecutive 1s in this array. 
    /// Example 1:
    /// Input: [1,1,0,1,1,1]
    /// Output: 3
    /// Explanation: The first two digits or the last three digits are consecutive 1s.
    /// The maximum number of consecutive 1s is 3.
    /// Note: 
    /// The input array will only contain 0 and 1.
    /// The length of input array is a positive integer and will not exceed 10,000 
    /// </summary>
    int findMaxConsecutiveOnes(vector<int>& nums);

    /// <summary>
    /// Leet code #446. Arithmetic Slices II - Subsequence    
    /// 
    /// A sequence of numbers is called arithmetic if it consists of at 
    /// least three elements and if the difference between any two 
    /// consecutive elements is the same.
    ///
    /// For example, these are arithmetic sequences:
    /// 1, 3, 5, 7, 9
    /// 7, 7, 7, 7
    /// 3, -1, -5, -9
    ///
    /// The following sequence is not arithmetic.
    /// 1, 1, 2, 5, 7
    /// A zero-indexed array A consisting of N numbers is given. A 
    /// subsequence slice of that array is any sequence of integers 
    /// (P0, P1, ..., Pk) such that 0 �� P0 < P1 < ... < Pk < N.
    ///
    /// A subsequence slice (P0, P1, ..., Pk) of array A is called 
    /// arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] 
    /// is arithmetic. In particular, this means that k �� 2.
    /// 
    /// The function should return the number of arithmetic subsequence 
    /// slices in the array A. 
    ///
    /// The input contains N integers. Every integer is in the range of -2^31 
    /// and 2^31-1 and 0 �� N �� 1000. The output is guaranteed to be less than 2^31-1.
    ///
    /// Example: 
    /// Input: [2, 4, 6, 8, 10]
    /// Output: 7
    ///
    /// Explanation:
    /// All arithmetic subsequence slices are:
    /// [2,4,6]
    /// [4,6,8]
    /// [6,8,10]
    /// [2,4,6,8]
    /// [4,6,8,10]
    /// [2,4,6,8,10]
    /// [2,6,10]
    /// </summary>
    int numberOfArithmeticSlicesII(vector<int>& A);

    /// <summary>
    /// Leet code #368. Largest Divisible Subset 
    /// 
    /// Given a set of distinct positive integers, find the largest 
    /// subset such that every pair (Si, Sj) of elements in this subset 
    /// satisfies: Si % Sj = 0 or Sj % Si = 0. 
    ///
    /// If there are multiple solutions, return any subset is fine. 
    ///
    /// Example 1: 
    /// nums: [1,2,3]
    /// Result: [1,2] (of course, [1,3] will also be ok)
    ///
    /// Example 2: 
    /// nums: [1,2,4,8]
    /// Result: [1,2,4,8]
    /// </summary>
    vector<int> largestDivisibleSubset(vector<int>& nums);

    /// <summary>
    /// Leet code #26. Remove Duplicates from Sorted Array
    ///
    /// Given a sorted array, remove the duplicates in place such that 
    /// each element appear only once and return the new length.
    /// Do not allocate extra space for another array, you must do this in 
    /// place with constant memory. 
    /// For example,
    /// Given input array nums = [1,1,2], 
    /// Your function should return length = 2, with the first two elements 
    /// of nums being 1 and 2 respectively. 
    /// It doesn't matter what you leave beyond the new length. 
    /// </summary>
    int removeDuplicateSortedArray(vector<int>& nums);

    /// <summary>
    /// LeetCode #80. Remove Duplicates from Sorted Array II  
    ///
    /// Follow up for "Remove Duplicates": 
    /// What if duplicates are allowed at most twice? 
    /// For example, 
    /// Given sorted array nums = [1,1,1,2,2,3], 
    /// Your function should return length = 5, with the first five elements 
    /// of nums being 1, 1, 2, 2 and 3. 
    /// It doesn't matter what you leave beyond the new length.  
    /// </summary>
    int removeDuplicatesII(vector<int>& nums);

    /// <summary>
    /// LeetCode #73. Set Matrix Zeroes
    ///
    /// Given a m x n matrix, if an element is 0, set its entire row and column 
    /// to 0. Do it in place. 
    /// Did you use extra space?
    /// A straight forward solution using O(mn) space is probably a bad idea.
    /// A simple improvement uses O(m + n) space, but still not the best 
    /// solution.
    /// Could you devise a constant space solution? 
    /// </summary>
    void setZeroes(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #189. Rotate Array
    ///
    /// Rotate an array of n elements to the right by k steps.
    /// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is 
    /// rotated to [5,6,7,1,2,3,4]. 
    /// Note:
    /// Try to come up as many solutions as you can, there are at least 3 
    /// different ways to solve this problem. 
    /// Hint:
    /// Could you do it in-place with O(1) extra space? 
    /// Related problem: Reverse Words in a String II
    /// </summary>
    void rotateArray(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 419. Battleships in a Board
    ///  
    /// Medium
    ///
    /// Given an m x n matrix board where each cell is a battleship 'X' or empty 
    /// '.', return the number of the battleships on board.
    ///
    /// Battleships can only be placed horizontally or vertically on board. In 
    /// other words, they can only be made of the shape 1 x k (1 row, k columns) 
    /// or k x 1 (k rows, 1 column), where k can be of any size. At least one 
    /// horizontal or vertical cell separates between two battleships (i.e., 
    /// there are no adjacent battleships).
    ///
    /// Example 1:
    /// Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
    /// Output: 2
    ///
    /// Example 2:
    /// Input: board = [["."]]
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. m == board.length
    /// 2. n == board[i].length
    /// 3. 1 <= m, n <= 200
    /// 4. board[i][j] is either '.' or 'X'.
    /// Follow up: Could you do it in one-pass, using only O(1) extra memory and 
    /// without modifying the values board?
    /// </summary>    
    int countBattleships(vector<vector<char>>& board);

    /// <summary>
    /// Leet code #442. Find All Duplicates in an Array
    ///
    /// Given an array of integers, 1 �� a[i] �� n (n = size of array), some 
    /// elements appear twice and others appear once.
    /// Find all the elements that appear twice in this array.
    /// Could you do it without extra space and in O(n) runtime?
    /// Example:
    /// Input:
    /// [4,3,2,7,8,2,3,1]
    /// Output:
    /// [2,3]
    /// </summary>
    vector<int> findDuplicates(vector<int>& nums);

    /// <summary>
    /// Leet code #1330. Reverse Subarray To Maximize Array Value 
    /// 
    /// Hard
    ///
    /// You are given an integer array nums. The value of this array is 
    /// defined as the sum of |nums[i]-nums[i+1]| for 
    /// all 0 <= i < nums.length-1.
    ///
    /// You are allowed to select any subarray of the given array and 
    /// reverse it. You can perform this operation only once.
    ///
    /// Find maximum possible value of the final array.
    /// 
    /// Example 1:
    /// Input: nums = [2,3,1,5,4]
    /// Output: 10
    /// Explanation: By reversing the subarray [3,1,5] the array 
    /// becomes [2,5,1,3,4] whose value is 10.
    ///
    /// Example 2:
    /// Input: nums = [2,4,9,24,2,1,10]
    /// Output: 68
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 3*10^4
    /// 2. -10^5 <= nums[i] <= 10^5
    /// </summary>
    int maxValueAfterReverse(vector<int>& nums);

    /// <summary>
    /// Leet code #1329. Sort the Matrix Diagonally 
    /// 
    /// Medium
    ///
    /// Given a m * n matrix mat of integers, sort it diagonally in ascending 
    /// order from the top-left to the bottom-right then return the sorted 
    /// array.
    /// 
    /// Example 1:
    /// Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
    /// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
    /// 
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[i].length
    /// 3. 1 <= m, n <= 100
    /// 4. 1 <= mat[i][j] <= 100
    /// </summary>
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat);

    /// <summary>
    /// Leet code #1333. Filter Restaurants by Vegan-Friendly, Price and Distance
    /// 
    /// Medium
    ///
    /// Given the array restaurants where  restaurants[i] = [idi, ratingi, 
    /// veganFriendlyi, pricei, distancei]. You have to filter the restaurants 
    /// using three filters.
    ///
    /// The veganFriendly filter will be either true (meaning you should only 
    /// include restaurants with veganFriendlyi set to true) or false (meaning 
    /// you can include any restaurant). In addition, you have the filters 
    /// maxPrice and maxDistance which are the maximum value for price and 
    /// distance of restaurants you should consider respectively.
    ///
    /// Return the array of restaurant IDs after filtering, ordered by rating 
    /// from highest to lowest. For restaurants with the same rating, order 
    /// them by id from highest to lowest. For simplicity veganFriendlyi and 
    /// veganFriendly take value 1 when it is true, and 0 when it is false.
    ///
    /// Example 1:
    /// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
    /// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, 
    /// maxDistance = 10
    /// Output: [3,1,5] 
    /// Explanation: 
    /// The restaurants are:
    /// Restaurant 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
    /// Restaurant 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
    /// Restaurant 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
    /// Restaurant 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
    /// Restaurant 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
    /// After filter restaurants with veganFriendly = 1, maxPrice = 50 and 
    /// maxDistance = 10 we have restaurant 3, restaurant 1 and restaurant 5 
    /// (ordered by rating from highest to lowest).
    ///	
    /// Example 2:
    /// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
    /// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, 
    /// maxDistance = 10
    /// Output: [4,3,2,1,5]
    /// Explanation: The restaurants are the same as in example 1, but in 
    /// this case the filter veganFriendly = 0, therefore all restaurants are
    /// considered.
    ///
    /// Example 3:
    /// Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],
    /// [4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, 
    /// maxDistance = 3
    /// Output: [4,5]
    ///
    /// Constraints:
    /// 1. 1 <= restaurants.length <= 10^4
    /// 2. restaurants[i].length == 5
    /// 3. 1 <= id[i], ratingi, pricei, distancei <= 10^5
    /// 4. 1 <= maxPrice, maxDistance <= 10^5
    /// 5. veganFriendlyi and veganFriendly are 0 or 1.
    /// 6. All id[i] are distinct.
    /// </summary>
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, 
        int veganFriendly, int maxPrice, int maxDistance);

    /// <summary>
    /// Leet code #1337. The K Weakest Rows in a Matrix 
    /// 
    /// Easy
    ///
    /// Given a m * n matrix mat of ones (representing soldiers) and zeros 
    /// (representing civilians), return the indexes of the k weakest rows 
    /// in the matrix ordered from the weakest to the strongest.
    /// 
    /// A row i is weaker than row j, if the number of soldiers in row i is 
    /// less than the number of soldiers in row j, or they have the same 
    /// number of soldiers but i is less than j. Soldiers are always stand 
    /// in the frontier of a row, that is, always ones may appear first and 
    /// then zeros.
    /// 
    /// Example 1:
    ///
    /// Input: mat = 
    /// [[1,1,0,0,0],
    ///  [1,1,1,1,0],
    ///  [1,0,0,0,0],
    ///  [1,1,0,0,0],
    ///  [1,1,1,1,1]], 
    /// k = 3
    /// Output: [2,0,3]
    /// Explanation: 
    /// The number of soldiers for each row is: 
    /// row 0 -> 2 
    /// row 1 -> 4 
    /// row 2 -> 1 
    /// row 3 -> 2 
    /// row 4 -> 5 
    /// Rows ordered from the weakest to the strongest are [2,0,3,1,4]
    /// 
    /// Example 2:
    ///
    /// Input: mat = 
    /// [[1,0,0,0],
    ///  [1,1,1,1],
    ///  [1,0,0,0],
    ///  [1,0,0,0]], 
    /// k = 2
    /// Output: [0,2]
    /// Explanation: 
    /// The number of soldiers for each row is: 
    /// row 0 -> 1 
    /// row 1 -> 4 
    /// row 2 -> 1 
    /// row 3 -> 1 
    /// Rows ordered from the weakest to the strongest are [0,2,3,1]
    /// 
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[i].length
    /// 3. 2 <= n, m <= 100
    /// 4. 1 <= k <= m
    /// 5. matrix[i][j] is either 0 or 1.
    /// </summary>
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k);

    /// <summary>
    /// Leet code #1338. Reduce Array Size to The Half 
    /// 
    /// Medium
    ///
    /// Given an array arr.  You can choose a set of integers and remove all 
    /// the occurrences of these integers in the array.
    ///
    /// Return the minimum size of the set so that at least half of the 
    /// integers of the array are removed.
    ///  
    /// Example 1:
    ///
    /// Input: arr = [3,3,3,3,5,5,5,2,2,7]
    /// Output: 2
    /// Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which 
    /// has size 5 (i.e equal to half of the size of the old array).
    /// Possible sets of size 2 are {3,5},{3,2},{5,2}.
    /// Choosing set {2,7} is not possible as it will make the new 
    /// array [3,3,3,3,5,5,5] which has size greater than half of the size of 
    /// the old array.
    ///
    /// Example 2:
    ///
    /// Input: arr = [7,7,7,7,7,7]
    /// Output: 1
    /// Explanation: The only possible set you can choose is {7}. This will make the new array empty.
    ///
    /// Example 3:
    ///
    /// Input: arr = [1,9]
    /// Output: 1
    ///
    /// Example 4:
    ///
    /// Input: arr = [1000,1000,3,7]
    /// Output: 1
    ///
    /// Example 5:
    ///
    /// Input: arr = [1,2,3,4,5,6,7,8,9,10]
    /// Output: 5
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. arr.length is even.
    /// 3. 1 <= arr[i] <= 10^5
    /// </summary>
    int minSetSize(vector<int>& arr);

    /// <summary>
    /// Leet code #1343. Number of Sub-arrays of Size K and Average Greater 
    /// than or Equal to Threshold
    ///
    /// Medium
    ///
    /// Given an array of integers arr and two integers k and threshold.
    ///
    /// Return the number of sub-arrays of size k and average greater than 
    /// or equal to threshold.
    ///
    /// Example 1:
    /// Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
    /// Output: 3
    /// Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have 
    /// averages 4, 5 and 6 respectively. All other sub-arrays of size 3 
    /// have averages less than 4 (the threshold).
    ///
    /// Example 2:
    /// Input: arr = [1,1,1,1,1], k = 1, threshold = 0
    /// Output: 5
    ///
    /// Example 3:
    /// Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
    /// Output: 6
    /// Explanation: The first 6 sub-arrays of size 3 have averages greater 
    /// than 5. Note that averages are not integers.
    ///
    /// Example 4:
    /// Input: arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
    /// Output: 1
    ///
    /// Example 5:
    /// Input: arr = [4,4,4,4], k = 4, threshold = 1
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 1 <= arr[i] <= 10^4
    /// 3. 1 <= k <= arr.length
    /// 4. 0 <= threshold <= 10^4
    /// </summary>
    int numOfSubarrays(vector<int>& arr, int k, int threshold);

    /// <summary>
    /// Leet code #1346. Check If N and Its Double Exist
    ///
    /// Easy
    ///
    /// Given an array arr of integers, check if there exists two integers 
    /// N and M such that N is the double of M ( i.e. N = 2 * M).
    ///
    /// More formally check if there exists two indices i and j such that :
    ///  
    /// i != j
    /// 0 <= i, j < arr.length
    /// arr[i] == 2 * arr[j]
    /// 
    /// Example 1:
    /// Input: arr = [10,2,5,3]
    /// Output: true
    /// Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
    ///
    /// Example 2:
    /// Input: arr = [7,1,14,11]
    /// Output: true
    /// Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
    ///
    /// Example 3:
    /// Input: arr = [3,1,7,11]
    /// Output: false
    /// Explanation: In this case does not exist N and M, such that N = 2 * M.
    ///
    /// Constraints:
    /// 1. 2 <= arr.length <= 500
    /// 2. -10^3 <= arr[i] <= 10^3
    /// </summary>
    bool checkIfExist(vector<int>& arr);

    /// <summary>
    /// Leet code #1200. Minimum Absolute Difference
    /// 
    /// Given an array of distinct integers arr, find all pairs of elements 
    /// with the minimum absolute difference of any two elements. 
    ///
    /// Return a list of pairs in ascending order(with respect to pairs), 
    /// each pair [a, b] follows
    ///
    /// a, b are from arr
    /// a < b
    /// b - a equals to the minimum absolute difference of any two elements in arr
    /// 
    ///
    /// Example 1:
    ///
    /// Input: arr = [4,2,1,3]
    /// Output: [[1,2],[2,3],[3,4]]
    /// Explanation: The minimum absolute difference is 1. List all pairs with 
    /// difference equal to 1 in ascending order.
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,3,6,10,15]
    /// Output: [[1,3]]
    ///
    /// Example 3:
    ///
    /// Input: arr = [3,8,-10,23,19,-4,-14,27]
    /// Output: [[-14,-10],[19,23],[23,27]]
    /// 
    /// Constraints:
    /// 1. 2 <= arr.length <= 10^5
    /// 2. -10^6 <= arr[i] <= 10^6
    /// </summary>
    vector<vector<int>> minimumAbsDifference(vector<int>& arr);

    /// <summary>
    /// Leet code #1184. Distance Between Bus Stops
    /// 
    /// A bus has n stops numbered from 0 to n - 1 that form a circle. We know 
    /// the distance between all pairs of neighboring stops where distance[i] 
    /// is the distance between the stops number i and (i + 1) % n.
    /// The bus goes along both directions i.e. clockwise and counterclockwise.
    /// Return the shortest distance between the given start and destination 
    /// stops.
    /// 
    /// Example 1:
    ///
    /// Input: distance = [1,2,3,4], start = 0, destination = 1
    /// Output: 1
    /// Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
    /// 
    /// Example 2:
    ///
    /// Input: distance = [1,2,3,4], start = 0, destination = 2
    /// Output: 3
    /// Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
    ///  
    /// Example 3:
    ///
    /// Input: distance = [1,2,3,4], start = 0, destination = 3
    /// Output: 4
    /// Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// 2. distance.length == n
    /// 3. 0 <= start, destination < n
    /// 4. 0 <= distance[i] <= 10^4
    /// </summary>
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination);

    /// <summary>
    /// Leet code #1183. Maximum Number of Ones
    /// 
    /// Consider a matrix M with dimensions width * height, such that every cell
    /// has value 0 or 1, and any square sub-matrix of M of size 
    /// sideLength * sideLength has at most maxOnes ones.
    /// Return the maximum possible number of ones that the matrix M can have.
    /// 
    /// Example 1:
    /// Input: width = 3, height = 3, sideLength = 2, maxOnes = 1
    /// Output: 4
    /// Explanation:
    /// In a 3*3 matrix, no 2*2 sub-matrix can have more than 1 one.
    /// The best solution that has 4 ones is:
    /// [1,0,1]
    /// [0,0,0]
    /// [1,0,1]
    ///
    /// Example 2:
    /// Input: width = 3, height = 3, sideLength = 2, maxOnes = 2
    /// Output: 6
    /// Explanation:
    /// [1,0,1]
    /// [1,0,1]
    /// [1,0,1]
    /// 
    /// Constraints:
    /// 1. 1 <= width, height <= 100
    /// 2. 1 <= sideLength <= width, height
    /// 3. 0 <= maxOnes <= sideLength * sideLength
    /// </summary>
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes);

    /// <summary>
    /// Leet code #1176. Diet Plan Performance
    /// 
    /// A dieter consumes calories[i] calories on the i-th day.  For every 
    /// consecutive sequence of k days, they look at T, the total calories 
    /// consumed during that sequence of k days:
    /// If T < lower, they performed poorly on their diet and lose 1 point; 
    /// If T > upper, they performed well on their diet and gain 1 point;
    /// Otherwise, they performed normally and there is no change in points.
    /// Return the total number of points the dieter has after all 
    /// calories.length days.
    ///
    /// Note that: The total points could be negative.
    /// 
    /// Example 1:
    /// Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
    /// Output: 0
    /// Explaination: calories[0], calories[1] < lower and 
    /// calories[3], calories[4] > upper, total points = 0.
    ///
    /// Example 2:
    /// Input: calories = [3,2], k = 2, lower = 0, upper = 1
    /// Output: 1
    /// Explaination: calories[0] + calories[1] > upper, total points = 1.
    ///
    /// Example 3:
    /// Input: calories = [6,5,0,0], k = 2, lower = 1, upper = 5
    /// Output: 0
    /// Explaination: calories[0] + calories[1] > upper, 
    /// calories[2] + calories[3] < lower, total points = 0.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= calories.length <= 10^5
    /// 2. 0 <= calories[i] <= 20000
    /// 3. 0 <= lower <= upper
    /// </summary>
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper);

    /// <summary>
    /// Leet code #1138. Alphabet Board Path
    /// 
    /// On an alphabet board, we start at position (0, 0), corresponding to 
    /// character board[0][0].
    ///
    /// Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], 
    /// as shown in the diagram below.
    ///
    /// We may make the following moves:
    ///
    /// 'U' moves our position up one row, if the position exists on the 
    /// board;
    /// 'D' moves our position down one row, if the position exists on the 
    /// board;
    /// 'L' moves our position left one column, if the position exists on the 
    /// board;
    /// 'R' moves our position right one column, if the position exists on the 
    /// board;
    /// '!' adds the character board[r][c] at our current position (r, c) to the 
    /// answer.
    /// (Here, the only positions that exist on the board are positions with 
    ///  letters on them.)
    ///
    /// Return a sequence of moves that makes our answer equal to target in the 
    /// minimum number of moves.  You may return any path that does so.
    ///
    /// Example 1:
    /// Input: target = "leet"
    /// Output: "DDR!UURRR!!DDD!"
    ///
    /// Example 2:
    /// Input: target = "code"
    /// Output: "RR!DDRR!UUL!R!"
    ///  
    /// Constraints:
    /// 1. 1 <= target.length <= 100
    /// 2. target consists only of English lowercase letters.
    /// </summary>
    string alphabetBoardPath(string target);

    /// <summary>
    /// Leet code #1121. Divide Array Into Increasing Sequences
    /// 
    /// Given a non-decreasing array of positive integers nums and an integer K, 
    /// find out if this array can be divided into one or more disjoint 
    /// increasing subsequences of length at least K.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,2,3,3,4,4], K = 3
    /// Output: true
    /// Explanation: 
    /// The array can be divided into the two subsequences [1,2,3,4] and [2,3,4] 
    /// with lengths at least 3 each.
    ///
    /// Example 2:
    /// Input: nums = [5,6,6,7,8], K = 3
    /// Output: false
    /// Explanation: 
    /// There is no way to divide the array using the conditions required.
    /// 
    /// Note:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= K <= nums.length
    /// 3. 1 <= nums[i] <= 10^5
    /// </summary>
    bool canDivideIntoSubsequences(vector<int>& nums, int K);

    /// <summary>
    /// Leet code #1351. Count Negative Numbers in a Sorted Matrix
    ///
    /// Easy
    ///
    /// Given a m * n matrix grid which is sorted in non-increasing order 
    /// both row-wise and column-wise. 
    ///
    /// Return the number of negative numbers in grid.
    ///
    /// Example 1:
    /// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    /// Output: 8
    /// Explanation: There are 8 negatives number in the matrix.
    ///
    /// Example 2:
    /// Input: grid = [[3,2],[1,0]]
    /// Output: 0
    ///
    /// Example 3:
    /// Input: grid = [[1,-1],[-1,-1]]
    /// Output: 3
    ///
    /// Example 4:
    /// Input: grid = [[-1]]
    /// Output: 1
    /// 
    ///
    /// Constraints:
    ///
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 100
    /// 4. -100 <= grid[i][j] <= 100
    /// </summary>
    int countNegatives(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1380. Lucky Numbers in a Matrix
    ///
    /// Easy
    ///
    /// Given a m * n matrix of distinct numbers, return all lucky numbers 
    /// in the matrix in any order.
    /// A lucky number is an element of the matrix such that it is the 
    /// minimum element in its row and maximum in its column.
    ///
    /// Example 1:
    /// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
    /// Output: [15]
    /// Explanation: 15 is the only lucky number since it is the minimum 
    /// in its row and the maximum in its column
    ///
    /// Example 2:
    /// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
    /// Output: [12]
    /// Explanation: 12 is the only lucky number since it is the minimum in 
    /// its row and the maximum in its column.
    ///
    /// Example 3:
    /// Input: matrix = [[7,8],[1,2]]
    /// Output: [7]
    ///
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n == mat[i].length
    /// 3. 1 <= n, m <= 50
    /// 4. 1 <= matrix[i][j] <= 10^5.
    /// 5. All elements in the matrix are distinct.
    /// </summary>
    vector<int> luckyNumbers(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code #1389. Create Target Array in the Given Order
    /// 
    /// Easy
    ///
    /// Given two arrays of integers nums and index. Your task is to create 
    /// target array under the following rules:
    ///
    /// Initially target array is empty.
    /// From left to right read nums[i] and index[i], insert at index index[i] 
    /// the value nums[i] in target array.
    /// Repeat the previous step until there are no elements to read in nums 
    /// and index.
    /// Return the target array.
    ///
    /// It is guaranteed that the insertion operations will be valid.
    ///
    /// Example 1:
    /// Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
    /// Output: [0,4,1,3,2]
    /// Explanation:
    /// nums       index     target
    /// 0            0        [0]
    /// 1            1        [0,1]
    /// 2            2        [0,1,2] 
    /// 3            2        [0,1,3,2]
    /// 4            1        [0,4,1,3,2]
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
    /// Output: [0,1,2,3,4]
    /// Explanation:
    /// nums       index     target
    /// 1            0        [1]
    /// 2            1        [1,2]
    /// 3            2        [1,2,3]
    /// 4            3        [1,2,3,4]
    /// 0            0        [0,1,2,3,4]
    ///
    /// Example 3:
    /// Input: nums = [1], index = [0]
    /// Output: [1]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length, index.length <= 100
    /// 2. nums.length == index.length
    /// 3. 0 <= nums[i] <= 100
    /// 4. 0 <= index[i] <= i
    /// </summary>
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index);

    /// <summary>
    /// Leet code #1395. Count Number of Teams
    /// 
    /// Medium
    ///
    /// There are n soldiers standing in a line. Each soldier is assigned a 
    /// unique rating value.
    ///
    /// You have to form a team of 3 soldiers amongst them under the following
    /// rules:
    ///
    /// Choose 3 soldiers with index (i, j, k) with rating (rating[i], 
    /// rating[j], rating[k]).
    /// A team is valid if:  (rating[i] < rating[j] < rating[k]) or 
    /// (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
    /// Return the number of teams you can form given the conditions. 
    /// (soldiers can be part of multiple teams).
    /// 
    /// Example 1:
    /// Input: rating = [2,5,3,4,1]
    /// Output: 3
    /// Explanation: We can form three teams given the conditions. 
    /// (2,3,4), (5,4,1), (5,3,1). 
    ///
    /// Example 2:
    /// Input: rating = [2,1,3]
    /// Output: 0
    /// Explanation: We can't form any team given the conditions.
    ///
    /// Example 3:
    /// Input: rating = [1,2,3,4]
    /// Output: 4
    ///
    /// Constraints:
    /// 1. n == rating.length
    /// 2. 1 <= n <= 200
    /// 3. 1 <= rating[i] <= 10^5
    /// </summary>
    int numTeams(vector<int>& rating);

    /// <summary>
    /// Leet code #1409. Queries on a Permutation With Key 
    /// 
    /// Medium
    ///
    /// Given the array queries of positive integers between 1 and m, 
    /// you have to process all queries[i] (from i=0 to 
    /// i=queries.length-1) according to the following rules:
    ///
    /// In the beginning, you have the permutation P=[1,2,3,...,m].
    /// For the current i, find the position of queries[i] in the 
    /// permutation P (indexing from 0) and then move this at the 
    /// beginning of the permutation P. Notice that the position of 
    /// queries[i] in P is the result for queries[i].
    /// Return an array containing the result for the given queries.
    /// 
    /// Example 1:
    /// Input: queries = [3,1,2,1], m = 5
    /// Output: [2,1,2,1] 
    /// Explanation: The queries are processed as follow: 
    /// For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, 
    /// then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
    /// For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, 
    /// then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
    /// For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, 
    /// then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
    /// For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, 
    /// then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
    /// Therefore, the array containing the result is [2,1,2,1].  
    ///
    /// Example 2:
    /// Input: queries = [4,1,2,2], m = 4
    /// Output: [3,1,2,0]
    ///
    /// Example 3:
    /// Input: queries = [7,5,5,8,3], m = 8
    /// Output: [6,5,0,7,5]
    ///
    /// Constraints:
    /// 1. 1 <= m <= 10^3
    /// 2. 1 <= queries.length <= m
    /// 3. 1 <= queries[i] <= m
    /// </summary>
    vector<int> processQueries(vector<int>& queries, int m);

    /// <summary>
    /// Leet code #1413. Minimum Value to Get Positive Step by Step Sum 
    /// 
    /// Easy
    ///
    /// Given an array of integers nums, you start with an initial positive 
    /// value startValue.
    ///
    /// In each iteration, you calculate the step by step sum of startValue 
    /// plus elements in nums (from left to right).
    ///
    /// Return the minimum positive value of startValue such that the step by 
    /// step sum is never less than 1.
    ///
    /// Example 1:
    /// Input: nums = [-3,2,-3,4,2]
    /// Output: 5
    /// Explanation: If you choose startValue = 4, in the third iteration your 
    /// step by step sum is less than 1.
    ///            step by step sum
    ///            startValue = 4 | startValue = 5 | nums
    ///              (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
    ///              (1 +2 ) = 3  | (2 +2 ) = 4    |   2
    ///              (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
    ///              (0 +4 ) = 4  | (1 +4 ) = 5    |   4
    ///              (4 +2 ) = 6  | (5 +2 ) = 7    |   2
    /// Example 2:
    /// Input: nums = [1,2]
    /// Output: 1
    /// Explanation: Minimum start value should be positive. 
    ///
    /// Example 3:
    /// Input: nums = [1,-2,-3]
    /// Output: 5
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. -100 <= nums[i] <= 100
    /// </summary>
    int minStartValue(vector<int>& nums);

    /// <summary>
    /// Leet code #1423. Maximum Points You Can Obtain from Cards
    /// 
    /// Medium
    ///
    /// There are several cards arranged in a row, and each card has an 
    /// associated number of points The points are given in the integer 
    /// array cardPoints.
    ///
    /// In one step, you can take one card from the beginning or from the 
    /// end of the row. You have to take exactly k cards.
    ///
    /// Your score is the sum of the points of the cards you have taken.
    ///
    /// Given the integer array cardPoints and the integer k, return 
    /// the maximum score you can obtain.
    ///
    /// Example 1:
    /// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    /// Output: 12
    /// Explanation: After the first step, your score will 
    /// always be 1. However, choosing the rightmost card first 
    /// will maximize your total score. The optimal strategy is 
    /// to take the three cards on the right, giving a final 
    /// score of 1 + 6 + 5 = 12.
    ///
    /// Example 2:
    /// Input: cardPoints = [2,2,2], k = 2
    /// Output: 4
    /// Explanation: Regardless of which two cards you take, your score will 
    /// always be 4.
    ///
    /// Example 3:
    /// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
    /// Output: 55
    /// Explanation: You have to take all the cards. Your score is the sum of 
    /// points of all cards.
    ///
    /// Example 4:
    /// Input: cardPoints = [1,1000,1], k = 1
    /// Output: 1
    /// Explanation: You cannot take the card in the middle. Your best score 
    /// is 1. 
    ///
    /// Example 5:
    /// Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
    /// Output: 202
    ///
    /// Constraints:
    /// 1. 1 <= cardPoints.length <= 10^5
    /// 2. 1 <= cardPoints[i] <= 10^4
    /// 3. 1 <= k <= cardPoints.length
    /// </summary>
    int maxScore(vector<int>& cardPoints, int k);

    /// <summary>
    /// Leet code #1431. Kids With the Greatest Number of Candies
    /// 
    /// Easy
    ///
    /// Given the array candies and the integer extraCandies, where candies[i] 
    /// represents the number of candies that the ith kid has.
    ///
    /// For each kid check if there is a way to distribute extraCandies among 
    /// the kids such that he or she can have the greatest number of candies 
    /// among them. Notice that multiple kids can have the greatest number of 
    /// candies.
    ///
    /// Example 1:
    /// Input: candies = [2,3,5,1,3], extraCandies = 3
    /// Output: [true,true,true,false,true] 
    /// Explanation: 
    /// Kid 1 has 2 candies and if he or she receives all extra candies (3) 
    /// will have 5 candies --- the greatest number of candies among the kids. 
    /// Kid 2 has 3 candies and if he or she receives at least 2 extra candies 
    /// will have the greatest number of candies among the kids. 
    /// Kid 3 has 5 candies and this is already the greatest number of candies 
    /// among the kids. 
    /// Kid 4 has 1 candy and even if he or she receives all extra candies will
    /// only have 4 candies. 
    /// Kid 5 has 3 candies and if he or she receives at least 2 extra candies 
    /// will have the greatest number of candies among the kids. 
    ///
    /// Example 2:
    /// Input: candies = [4,2,1,1,2], extraCandies = 1
    /// Output: [true,false,false,false,false] 
    /// Explanation: There is only 1 extra candy, therefore only kid 1 will 
    /// have the greatest number of candies among the kids regardless of who 
    /// takes the extra candy.
    ///
    /// Example 3:
    /// Input: candies = [12,1,12], extraCandies = 10
    /// Output: [true,false,true]
    /// Constraints:
    /// 1. 2 <= candies.length <= 100
    /// 2. 1 <= candies[i] <= 100
    /// 3. 1 <= extraCandies <= 50
    /// </summary>
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

    /// <summary>
    /// Leet code #1437. Check If All 1's Are at Least Length K Places Away
    /// 
    /// Medium
    ///
    /// Given an array nums of 0s and 1s and an integer k, return True if 
    /// all 1's are at least k places away from each other, otherwise return 
    /// False.
    ///
    /// Example 1:
    /// Input: nums = [1,0,0,0,1,0,0,1], k = 2
    /// Output: true
    /// Explanation: Each of the 1s are at least 2 places away from each 
    /// other.
    ///
    /// Example 2:
    /// Input: nums = [1,0,0,1,0,1], k = 2
    /// Output: false
    /// Explanation: The second 1 and third 1 are only one apart from each 
    /// other.
    ///
    /// Example 3:
    /// Input: nums = [1,1,1,1,1], k = 0
    /// Output: true
    ///
    /// Example 4:
    /// Input: nums = [0,1,0,1], k = 1
    /// Output: true
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= k <= nums.length
    /// 3. nums[i] is 0 or 1
    /// </summary>
    bool kLengthApart(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #1441. Build an Array With Stack Operations
    ///
    /// Easy
    ///
    /// Given an array target and an integer n. In each iteration, you will read 
    /// a number from  list = {1,2,3..., n}.
    ///
    /// Build the target array using the following operations:
    ///
    /// Push: Read a new element from the beginning list, and push it in the array.
    /// Pop: delete the last element of the array.
    /// If the target array is already built, stop reading more elements.
    /// You are guaranteed that the target array is strictly increasing, only 
    /// containing numbers between 1 to n inclusive.
    ///
    /// Return the operations to build the target array.
    ///
    /// You are guaranteed that the answer is unique.
    /// 
    /// Example 1:
    ///
    /// Input: target = [1,3], n = 3
    /// Output: ["Push","Push","Pop","Push"]
    /// Explanation: 
    /// Read number 1 and automatically push in the array -> [1]
    /// Read number 2 and automatically push in the array then Pop it -> [1]
    /// Read number 3 and automatically push in the array -> [1,3]
    ///
    /// Example 2:
    /// Input: target = [1,2,3], n = 3
    /// Output: ["Push","Push","Push"]
    ///
    /// Example 3:
    /// Input: target = [1,2], n = 4
    /// Output: ["Push","Push"]
    /// Explanation: You only need to read the first 2 numbers and stop.
    ///
    /// Example 4:
    /// Input: target = [2,3,4], n = 4
    /// Output: ["Push","Pop","Push","Push","Push"]
    /// 
    /// Constraints:
    /// 1. 1 <= target.length <= 100
    /// 2. 1 <= target[i] <= 100
    /// 3. 1 <= n <= 100
    /// 4. target is strictly increasing.
    /// </summary>
    vector<string> buildArray(vector<int>& target, int n);

    /// <summary>
    /// Leet code #1442. Count Triplets That Can Form Two Arrays of Equal XOR
    ///
    /// Medium
    ///
    /// Given an array of integers arr.
    ///
    /// We want to select three indices i, j and k where 
    /// (0 <= i < j <= k < arr.length).
    ///
    /// Let's define a and b as follows:
    ///
    /// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
    /// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
    /// Note that ^ denotes the bitwise-xor operation.
    ///
    /// Return the number of triplets (i, j and k) Where a == b.
    /// 
    /// Example 1:
    /// Input: arr = [2,3,1,6,7]
    /// Output: 4
    /// Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
    ///
    /// Example 2:
    /// Input: arr = [1,1,1,1,1]
    /// Output: 10
    ///
    /// Example 3:
    /// Input: arr = [2,3]
    /// Output: 0
    ///
    /// Example 4:
    /// Input: arr = [1,3,5,7,9]
    /// Output: 3
    ///
    /// Example 5:
    /// Input: arr = [7,11,12,9,5,2,7,17,22]
    /// Output: 8
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 300
    /// 2. 1 <= arr[i] <= 10^8
    /// </summary>
    int countTriplets(vector<int>& arr);

    /// <summary>
    /// Leet code #1450. Number of Students Doing Homework at a Given Time
    /// 
    /// Easy
    ///
    /// Given two integer arrays startTime and endTime and given an integer 
    /// queryTime.
    /// 
    /// The ith student started doing their homework at the time startTime[i] 
    /// and finished it at time endTime[i].
    ///
    /// Return the number of students doing their homework at time queryTime. 
    /// More formally, return the number of students where queryTime lays in 
    /// the interval [startTime[i], endTime[i]] inclusive.
    /// 
    /// Example 1:
    /// Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
    /// Output: 1
    /// Explanation: We have 3 students where:
    /// The first student started doing homework at time 1 and finished at 
    /// time 3 and wasn't doing anything at time 4.
    /// The second student started doing homework at time 2 and finished at 
    /// time 2 and also wasn't doing anything at time 4.
    /// The third student started doing homework at time 3 and finished at 
    /// time 7 and was the only student doing homework at time 4.
    ///
    /// Example 2:
    /// Input: startTime = [4], endTime = [4], queryTime = 4
    /// Output: 1
    /// Explanation: The only student was doing their homework at the 
    /// queryTime.
    ///
    /// Example 3:
    /// Input: startTime = [4], endTime = [4], queryTime = 5
    /// Output: 0
    ///
    /// Example 4:
    /// Input: startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
    /// Output: 0
    ///
    /// Example 5:
    /// Input: startTime = [9,8,7,6,5,4,3,2,1], 
    /// endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
    /// Output: 5
    ///
    /// Constraints:
    /// 1. startTime.length == endTime.length
    /// 2. 1 <= startTime.length <= 100
    /// 3. 1 <= startTime[i] <= endTime[i] <= 1000
    /// 4. 1 <= queryTime <= 1000
    /// </summary>
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime);

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
    /// Leet code #566. Reshape the Matrix������ 
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
    /// Leet code #1460. Make Two Arrays Equal by Reversing Sub-arrays
    /// 
    /// Easy
    ///
    /// Given two integer arrays of equal length target and arr.
    ///
    /// In one step, you can select any non-empty sub-array of arr and 
    /// reverse it. You are allowed to make any number of steps.
    ///
    /// Return True if you can make arr equal to target, or False otherwise.
    /// 
    /// Example 1:
    ///
    /// Input: target = [1,2,3,4], arr = [2,4,1,3]
    /// Output: true
    /// Explanation: You can follow the next steps to convert arr to target:
    /// 1- Reverse sub-array [2,4,1], arr becomes [1,4,2,3]
    /// 2- Reverse sub-array [4,2], arr becomes [1,2,4,3]
    /// 3- Reverse sub-array [4,3], arr becomes [1,2,3,4]
    /// There are multiple ways to convert arr to target, this is not the 
    /// only way to do so.
    ///
    /// Example 2:
    /// Input: target = [7], arr = [7]
    /// Output: true
    /// Explanation: arr is equal to target without any reverses.
    ///
    /// Example 3:
    /// Input: target = [1,12], arr = [12,1]
    /// Output: true
    ///
    /// Example 4:
    /// Input: target = [3,7,9], arr = [3,7,11]
    /// Output: false
    /// Explanation: arr doesn't have value 9 and it can never be converted 
    /// to target.
    ///
    /// Example 5:
    /// Input: target = [1,1,1,1,1], arr = [1,1,1,1,1]
    /// Output: true
    ///
    /// Constraints:
    /// 1. target.length == arr.length
    /// 2. 1 <= target.length <= 1000
    /// 3. 1 <= target[i] <= 1000
    /// 4. 1 <= arr[i] <= 1000
    /// </summary>
    bool canBeEqual(vector<int>& target, vector<int>& arr);

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
    /// For a non-negative integer X, the array form of X is an array of its 
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
    /// Note:
    /// 1. 1 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 9
    /// 3. 0 <= K <= 10000
    /// 4. If A.length > 1, then A[0] != 0
    /// </summary>
    vector<int> addToArrayForm(vector<int>& A, int K);

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
    /// Example 1:
    ///
    /// Input: [8,1,5,2,6]
    /// Output: 11
    /// Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
    /// 
    /// Note:
    /// 
    /// 1. 2 <= A.length <= 50000
    /// 2. 1 <= A[i] <= 1000
    /// </summary>
    int maxScoreSightseeingPair(vector<int>& A);

    /// <summary>
    /// Leet code #1470. Shuffle the Array
    ///                
    /// Easy
    /// 
    /// Given the array nums consisting of 2n elements in the form 
    /// [x1,x2,...,xn,y1,y2,...,yn].
    ///
    /// Return the array in the form [x1,y1,x2,y2,...,xn,yn].
    /// 
    /// Example 1:
    /// Input: nums = [2,5,1,3,4,7], n = 3
    /// Output: [2,3,5,4,1,7] 
    /// Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the 
    /// answer is [2,3,5,4,1,7].
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,4,3,2,1], n = 4
    /// Output: [1,4,2,3,3,2,4,1]
    ///
    /// Example 3:
    /// Input: nums = [1,1,2,2], n = 2
    /// Output: [1,2,1,2]
    ///
    /// Constraints:
    /// 1. 1 <= n <= 500
    /// 2. nums.length == 2n
    /// 3. 1 <= nums[i] <= 10^3
    /// </summary>	
    vector<int> shuffle(vector<int>& nums, int n);

    /// <summary>
    /// Leet code #1471. The k Strongest Values in an Array
    ///                
    /// Medium
    /// 
    /// Given an array of integers arr and an integer k.
    /// A value arr[i] is said to be stronger than a value arr[j] 
    /// if |arr[i] - m| > |arr[j] - m| where m is the median of the array.
    /// If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger 
    /// than arr[j] if arr[i] > arr[j].
    ///
    /// Return a list of the strongest k values in the array. return the 
    /// answer in any arbitrary order.
    ///
    /// Median is the middle value in an ordered integer list. More formally, 
    /// if the length of the list is n, the median is the element in 
    /// position ((n - 1) / 2) in the sorted list (0-indexed).
    ///
    /// For arr = [6, -3, 7, 2, 11], n = 5 and the median is obtained by 
    /// sorting the array arr = [-3, 2, 6, 7, 11] and the median is arr[m] 
    /// where m = ((5 - 1) / 2) = 2. The median is 6.
    /// For arr = [-7, 22, 17, 3], n = 4 and the median is obtained by 
    /// sorting the array arr = [-7, 3, 17, 22] and the median is arr[m] 
    /// where m = ((4 - 1) / 2) = 1. The median is 3.
    ///
    /// Example 1:
    /// Input: arr = [1,2,3,4,5], k = 2
    /// Output: [5,1]
    /// Explanation: Median is 3, the elements of the array sorted by the 
    /// strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1]. 
    /// [1, 5] is also accepted answer.
    /// Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 
    /// because 5 > 1.
    ///
    /// Example 2:
    /// Input: arr = [1,1,3,5,5], k = 2
    /// Output: [5,5]
    /// Explanation: Median is 3, the elements of the array sorted by the 
    /// strongest are [5,5,1,1,3]. The strongest 2 elements are [5, 5].
    ///
    /// Example 3:
    /// Input: arr = [6,7,11,7,6,8], k = 5
    /// Output: [11,8,6,6,7]
    /// Explanation: Median is 7, the elements of the array sorted by the 
    /// strongest are [11,8,6,6,7,7].
    /// Any permutation of [11,8,6,6,7] is accepted.
    ///
    /// Example 4:
    /// Input: arr = [6,-3,7,2,11], k = 3
    /// Output: [-3,11,2]
    ///
    /// Example 5:
    /// Input: arr = [-7,22,17,3], k = 2
    /// Output: [22,17]
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. -10^5 <= arr[i] <= 10^5
    /// 3. 1 <= k <= arr.length
    /// </summary>
    vector<int> getStrongest(vector<int>& arr, int k);

    /// <summary>
    /// Leet code #1480. Running Sum of 1d Array
    ///
    /// Easy
    ///
    /// Given an array nums. We define a running sum of an array as 
    /// runningSum[i] = sum(nums[0]�nums[i]).
    ///
    /// Return the running sum of nums.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,4]
    /// Output: [1,3,6,10]
    /// Explanation: Running sum is obtained as follows: 
    /// [1, 1+2, 1+2+3, 1+2+3+4].
    ///
    /// Example 2:
    /// Input: nums = [1,1,1,1,1]
    /// Output: [1,2,3,4,5]
    /// Explanation: Running sum is obtained as follows: [1, 1+1, 
    /// 1+1+1, 1+1+1+1, 1+1+1+1+1].
    ///
    /// Example 3:
    /// Input: nums = [3,1,2,10,1]
    /// Output: [3,4,6,16,17]
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. -10^6 <= nums[i] <= 10^6
    /// </summary> 
    vector<int> runningSum(vector<int>& nums);

    /// <summary>
    /// Leet code #1488. Avoid Flood in The City
    /// 
    /// Medium
    ///
    /// Your country has an infinite number of lakes. Initially, all the 
    /// lakes are empty, but when it rains over the nth lake, the nth lake 
    /// becomes full of water. If it rains over a lake which is full of 
    /// water, there will be a flood. Your goal is to avoid the flood in 
    /// any lake.
    ///
    /// Given an integer array rains where:
    /// rains[i] > 0 means there will be rains over the rains[i] lake.
    /// rains[i] == 0 means there are no rains this day and you can choose 
    /// one lake this day and dry it.
    /// Return an array ans where:
    /// ans.length == rains.length
    /// ans[i] == -1 if rains[i] > 0.
    /// ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
    /// If there are multiple valid answers return any of them. If it is 
    /// impossible to avoid flood return an empty array.
    ///
    /// Notice that if you chose to dry a full lake, it becomes empty, but 
    /// if you chose to dry an empty lake, nothing changes. (see example 4)
    ///
    /// Example 1:
    /// Input: rains = [1,2,3,4]
    /// Output: [-1,-1,-1,-1]
    /// Explanation: After the first day full lakes are [1]
    /// After the second day full lakes are [1,2]
    /// After the third day full lakes are [1,2,3]
    /// After the fourth day full lakes are [1,2,3,4]
    /// There's no day to dry any lake and there is no flood in any lake.
    ///
    /// Example 2:
    /// Input: rains = [1,2,0,0,2,1]
    /// Output: [-1,-1,2,1,-1,-1]
    /// Explanation: After the first day full lakes are [1]
    /// After the second day full lakes are [1,2]
    /// After the third day, we dry lake 2. Full lakes are [1]
    /// After the fourth day, we dry lake 1. There is no full lakes.
    /// After the fifth day, full lakes are [2].
    /// After the sixth day, full lakes are [1,2].
    /// It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is 
    /// another acceptable scenario.
    ///
    /// Example 3:
    /// 1. Input: rains = [1,2,0,1,2]
    /// 2. Output: []
    /// Explanation: After the second day, full lakes are  [1,2]. We have 
    /// to dry one lake in the third day.
    /// After that, it will rain over lakes [1,2]. It's easy to prove that 
    /// no matter which lake you choose to dry in the 3rd day, the other one 
    /// will flood.
    ///
    /// Example 4:
    /// 1. Input: rains = [69,0,0,0,69]
    /// 2. Output: [-1,69,1,1,-1]
    /// 3. Explanation: Any solution on one of the forms [-1,69,x,y,-1], 
    /// 4. [-1,x,69,y,-1] or [-1,x,y,69,-1] is acceptable 
    ///    where 1 <= x,y <= 10^9
    ///
    /// Example 5:
    /// Input: rains = [10,20,20]
    /// Output: []
    /// Explanation: It will rain over lake 20 two consecutive days. 
    /// There is no chance to dry any lake.
    ///
    /// Constraints:
    /// 1. 1 <= rains.length <= 10^5
    /// 2. 0 <= rains[i] <= 10^9
    /// </summary>
    vector<int> avoidFlood(vector<int>& rains);

    /// <summary>
    /// Leet code #1491. Average Salary Excluding the Minimum and Maximum Salary
    /// 
    /// Easy
    ///
    /// Given an array of unique integers salary where salary[i] is the salary 
    /// of the employee i.
    ///
    /// Return the average salary of employees excluding the minimum and maximum 
    /// salary.
    ///  
    /// Example 1:
    /// Input: salary = [4000,3000,1000,2000]
    /// Output: 2500.00000
    /// Explanation: Minimum salary and maximum salary are 1000 and 4000 
    /// respectively.
    /// Average salary excluding minimum and maximum salary is 
    /// (2000+3000)/2= 2500
    ///
    /// Example 2:
    /// Input: salary = [1000,2000,3000]
    /// Output: 2000.00000
    /// Explanation: Minimum salary and maximum salary are 1000 and 3000 
    /// respectively.
    /// Average salary excluding minimum and maximum salary is (2000)/1= 2000
    ///
    /// Example 3:
    /// Input: salary = [6000,5000,4000,3000,2000,1000]
    /// Output: 3500.00000
    /// Example 4:
    /// Input: salary = [8000,9000,2000,3000,6000,1000]
    /// Output: 4750.00000
    /// Constraints:
    /// 1. 3 <= salary.length <= 100
    /// 2. 10^3 <= salary[i] <= 10^6
    /// 3. salary[i] is unique.
    /// 4. Answers within 10^-5 of the actual value will be accepted as correct.
    /// </summary>
    double average(vector<int>& salary);

    /// <summary>
    /// Leet code #1493. Longest Subarray of 1's After Deleting One Element
    /// 
    /// Medium
    ///
    /// Given a binary array nums, you should delete one element from it.
    ///
    /// Return the size of the longest non-empty subarray containing only 1's 
    /// in the resulting array.
    /// Return 0 if there is no such subarray.
    /// Example 1:
    /// Input: nums = [1,1,0,1]
    /// Output: 3
    /// Explanation: After deleting the number in position 2, [1,1,1] 
    /// contains 3 numbers with value of 1's.
    ///
    /// Example 2:
    /// Input: nums = [0,1,1,1,0,1,1,0,1]
    /// Output: 5
    /// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] 
    /// longest subarray with value of 1's is [1,1,1,1,1].
    ///
    /// Example 3:
    /// Input: nums = [1,1,1]
    /// Output: 2
    /// Explanation: You must delete one element.
    /// Example 4:
    /// Input: nums = [1,1,0,0,1,1,1,0,1]
    /// Output: 4
    ///
    /// Example 5:
    /// Input: nums = [0,0,0]
    /// Output: 0
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. nums[i] is either 0 or 1.
    /// </summary>
    int longestSubarray(vector<int>& nums);

    /// <summary>
    /// Leet code #1497. Check If Array Pairs Are Divisible by k
    /// 
    /// Medium
    ///
    /// Given an array of integers arr of even length n and an integer k.
    /// We want to divide the array into exactly n / 2 pairs such that the 
    /// sum of each pair is divisible by k.
    /// Return True If you can find a way to do that or False otherwise.
    /// 
    /// Example 1:
    /// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
    /// Output: true
    /// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
    ///
    /// Example 2:
    /// Input: arr = [1,2,3,4,5,6], k = 7
    /// Output: true
    /// Explanation: Pairs are (1,6),(2,5) and(3,4).
    ///
    /// Example 3:
    /// Input: arr = [1,2,3,4,5,6], k = 10
    /// Output: false
    /// Explanation: You can try all possible pairs to see that there is no 
    /// way to divide arr into 3 pairs each with sum divisible by 10.
    ///
    /// Example 4:
    /// Input: arr = [-10,10], k = 2
    /// Output: true
    ///
    /// Example 5:
    /// Input: arr = [-1,1,-2,2,-3,3,-4,4], k = 3
    /// Output: true
    ///
    /// Constraints:
    /// 1. arr.length == n
    /// 2. 1 <= n <= 10^5
    /// 3. n is even.
    /// 4. -10^9 <= arr[i] <= 10^9
    /// 5. 1 <= k <= 10^5
    /// </summary>
    bool canArrange(vector<int>& arr, int k);

    /// <summary>
    /// Leet code #1498. Number of Subsequences That Satisfy the Given Sum 
    ///                  Condition
    /// 
    /// Medium
    ///
    /// Given an array of integers nums and an integer target.
    /// Return the number of non-empty subsequences of nums such that the 
    /// sum of the minimum and maximum element on it is less or equal than 
    /// target.
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: nums = [3,5,6,7], target = 9
    /// Output: 4
    /// Explanation: There are 4 subsequences that satisfy the condition.
    /// [3] -> Min value + max value <= target (3 + 3 <= 9)
    /// [3,5] -> (3 + 5 <= 9)
    /// [3,5,6] -> (3 + 6 <= 9)
    /// [3,6] -> (3 + 6 <= 9)
    ///
    /// Example 2:
    /// Input: nums = [3,3,6,8], target = 10
    /// Output: 6
    /// Explanation: There are 6 subsequences that satisfy the condition. 
    /// (nums can have repeated numbers).
    /// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
    ///
    /// Example 3:
    /// Input: nums = [2,3,3,4,6,7], target = 12
    /// Output: 61
    /// Explanation: There are 63 non-empty subsequences, two of them don't 
    /// satisfy the condition ([6,7], [7]).
    /// Number of valid subsequences (63 - 2 = 61).
    ///
    /// Example 4:
    /// Input: nums = [5,2,4,1,7,6,8], target = 16
    /// Output: 127
    /// Explanation: All non-empty subset satisfy the condition (2^7 - 1) = 127
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// 3. 1 <= target <= 10^6
    /// </summary>
    int numSubseq(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1502. Can Make Arithmetic Progression From Sequence
    /// 
    /// Easy
    ///
    /// Given an array of numbers arr. A sequence of numbers is called an 
    /// arithmetic progression if the difference between any two consecutive 
    /// elements is the same.
    ///
    /// Return true if the array can be rearranged to form an arithmetic 
    /// progression, otherwise, return false.
    /// 
    /// Example 1:
    /// Input: arr = [3,5,1]
    /// Output: true
    /// Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with 
    /// differences 2 and -2 respectively, between each consecutive elements.
    ///
    /// Example 2:
    /// Input: arr = [1,2,4]
    /// Output: false
    /// Explanation: There is no way to reorder the elements to obtain an 
    /// arithmetic progression.
    ///
    /// Constraints:
    /// 1. 2 <= arr.length <= 1000
    /// 2. -10^6 <= arr[i] <= 10^6
    /// </summary>
    bool canMakeArithmeticProgression(vector<int>& arr);

    /// <summary>
    /// Leet code #1504. Count Submatrices With All Ones
    /// 
    /// Medium
    ///
    /// Given a rows * columns matrix mat of ones and zeros, return how many 
    /// submatrices have all ones.
    /// 
    /// Example 1:
    /// Input: mat = [[1,0,1],
    ///               [1,1,0],
    ///               [1,1,0]]
    /// Output: 13
    /// Explanation:
    /// There are 6 rectangles of side 1x1.
    /// There are 2 rectangles of side 1x2.
    /// There are 3 rectangles of side 2x1.
    /// There is 1 rectangle of side 2x2. 
    /// There is 1 rectangle of side 3x1.
    /// Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
    ///
    /// Example 2:
    ///
    /// Input: mat = [[0,1,1,0],
    ///               [0,1,1,1],
    ///               [1,1,1,0]]
    /// Output: 24
    /// Explanation:
    /// There are 8 rectangles of side 1x1.
    /// There are 5 rectangles of side 1x2.
    /// There are 2 rectangles of side 1x3. 
    /// There are 4 rectangles of side 2x1.
    /// There are 2 rectangles of side 2x2. 
    /// There are 2 rectangles of side 3x1. 
    /// There is 1 rectangle of side 3x2. 
    /// Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
    ///
    /// Example 3:
    /// Input: mat = [[1,1,1,1,1,1]]
    /// Output: 21
    ///
    /// Example 4:
    /// Input: mat = [[1,0,1],[0,1,0],[1,0,1]]
    /// Output: 5
    /// 
    /// Constraints:
    /// 1. 1 <= rows <= 150
    /// 2. 1 <= columns <= 150
    /// 3. 0 <= mat[i][j] <= 1
    /// </summary>
    int numSubmat(vector<vector<int>>& mat);

    /// <summary>
    /// Leet code #1508. Range Sum of Sorted Subarray Sums
    ///
    /// Medium
    ///	
    /// Given the array nums consisting of n positive integers. You computed 
    /// the sum of all non-empty continous subarrays from the array and then 
    /// sort them in non-decreasing order, creating a new array of 
    /// n * (n + 1) / 2 numbers.
    /// Return the sum of the numbers from index left to index right 
    /// (indexed from 1), inclusive, in the new array. Since the answer 
    /// can be a huge number return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
    /// Output: 13 
    /// Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. 
    /// After sorting them in non-decreasing order we have the new array 
    /// [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index 
    /// le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
    /// Output: 6
    /// Explanation: The given array is the same as example 1. We have 
    /// the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the 
    /// numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
    /// Output: 50
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^3
    /// 2. nums.length == n
    /// 3. 1 <= nums[i] <= 100
    /// 4. 1 <= left <= right <= n * (n + 1) / 2
    /// </summary>
    int rangeSum(vector<int>& nums, int n, int left, int right);

    /// <summary>
    /// Leet code #1513. Number of Substrings With Only 1s
    ///
    /// Medium
    ///	
    /// Given a binary string s (a string consisting only of '0' and '1's).
    ///
    /// Return the number of substrings with all characters 1's.
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: s = "0110111"
    /// Output: 9
    /// Explanation: There are 9 substring in total with only 1's characters.
    /// "1" -> 5 times.
    /// "11" -> 3 times.
    /// "111" -> 1 time.
    ///
    /// Example 2:
    /// Input: s = "101"
    /// Output: 2
    /// Explanation: Substring "1" is shown 2 times in s.
    ///
    /// Example 3:
    /// Input: s = "111111"
    /// Output: 21
    /// Explanation: Each substring contains only 1's characters.
    ///
    /// Example 4:
    /// Input: s = "000"
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. s[i] == '0' or s[i] == '1'
    /// 2. 1 <= s.length <= 10^5
    /// </summary>
    int numSub(string s);

    /// <summary>
    /// Leet code #1524. Number of Sub-arrays With Odd Sum
    /// 
    /// Medium
    ///
    /// Given an array of integers arr. Return the number of sub-arrays with 
    /// odd sum.
    ///
    /// As the answer may grow large, the answer must be computed 
    /// modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: arr = [1,3,5]
    /// Output: 4
    /// Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
    /// All sub-arrays sum are [1,4,9,3,8,5].
    /// Odd sums are [1,9,3,5] so the answer is 4.
    ///
    /// Example 2:
    /// Input: arr = [2,4,6]
    /// Output: 0
    /// Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
    /// All sub-arrays sum are [2,6,12,4,10,6].
    /// All sub-arrays have even sum and the answer is 0.
    ///
    /// Example 3:
    /// Input: arr = [1,2,3,4,5,6,7]
    /// Output: 16
    ///
    /// Example 4:
    /// Input: arr = [100,100,99,99]
    /// Output: 4
    ///
    /// Example 5:
    /// Input: arr = [7]
    /// Output: 1
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 1 <= arr[i] <= 100
    /// </summary>
    int numOfSubarrays(vector<int>& arr);

    /// <summary>
    /// Leet code #1526. Minimum Number of Increments on Subarrays to Form a 
    ///                  Target Array
    /// 
    /// Hard
    ///
    /// Given an array of positive integers target and an array initial of 
    /// same size with all zeros.
    ///
    /// Return the minimum number of operations to form a target array from 
    /// initial if you are allowed to do the following operation:
    ///
    /// Choose any subarray from initial and increment each value by one.
    /// The answer is guaranteed to fit within the range of a 32-bit signed 
    /// integer.
    ///
    ///
    /// Example 1:
    ///
    /// Input: target = [1,2,3,2,1]
    /// Output: 3
    /// Explanation: We need at least 3 operations to form the target array 
    /// from the initial array.
    /// [0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
    /// [1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
    /// [1,2,2,2,1] increment 1 at index 2.
    /// [1,2,3,2,1] target array is formed.
    ///
    /// Example 2:
    /// Input: target = [3,1,1,2]
    /// Output: 4
    /// Explanation: (initial)[0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> 
    /// [2,1,1,2] -> [3,1,1,2] (target).
    ///
    /// Example 3:
    /// Input: target = [3,1,5,4,2]
    /// Output: 7
    /// Explanation: (initial)[0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] 
    /// -> [3,1,1,1,1] -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] 
    /// -> [3,1,5,4,2] (target).
    ///
    /// Example 4:
    /// Input: target = [1,1,1,1]
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= target.length <= 10^5
    /// 2. 1 <= target[i] <= 10^5
    /// </summary>
    int minNumberOperations(vector<int>& target);

    /// <summary>
    /// Leet code #1534. Count Good Triplets
    /// 
    /// Easy
    ///
    /// Given an array of integers arr, and three integers a, b and c. You need 
    /// to find the number of good triplets.
    ///
    /// A triplet (arr[i], arr[j], arr[k]) is good if the following conditions 
    /// are true:
    ///
    /// 0 <= i < j < k < arr.length
    /// |arr[i] - arr[j]| <= a
    /// |arr[j] - arr[k]| <= b
    /// |arr[i] - arr[k]| <= c
    /// Where |x| denotes the absolute value of x.
    ///
    /// Return the number of good triplets.
    /// 
    /// Example 1:
    /// Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
    /// Output: 4
    /// Explanation: There are 4 good triplets: 
    /// [(3,0,1), (3,0,1), (3,1,1), (0,1,1)]
    ///
    /// Example 2:
    /// Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
    /// Output: 0
    /// Explanation: No triplet satisfies all conditions.
    ///
    /// Constraints:
    /// 1. 3 <= arr.length <= 100
    /// 2. 0 <= arr[i] <= 1000
    /// 3. 0 <= a, b, c <= 1000
    /// </summary>
    int countGoodTriplets(vector<int>& arr, int a, int b, int c);

    /// <summary>
    /// Leet code #1537. Get the Maximum Score
    /// 
    /// Hard
    ///
    /// You are given two sorted arrays of distinct integers nums1 and nums2.
    ///
    /// A valid path is defined as follows:
    ///
    /// Choose array nums1 or nums2 to traverse (from index-0).
    /// Traverse the current array from left to right.
    /// If you are reading any value that is present in nums1 and nums2 you are 
    /// allowed to change your path to the other array. (Only one repeated value 
    /// is considered in the valid path).
    /// Score is defined as the sum of uniques values in a valid path.
    ///
    /// Return the maximum score you can obtain of all possible valid paths.
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
    /// Output: 30
    /// Explanation: Valid paths:
    /// [2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  
    /// (starting from nums1)
    /// [4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
    /// The maximum is obtained with the path in green [2,4,6,8,10].
    ///
    /// Example 2:
    /// Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
    /// Output: 109
    /// Explanation: Maximum sum is obtained with the path [1,3,5,100].
    ///
    /// Example 3:
    /// Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
    /// Output: 40
    /// Explanation: There are no common elements between nums1 and nums2.
    /// Maximum sum is obtained with the path [6,7,8,9,10].
    ///
    /// Example 4:
    /// Input: nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
    /// Output: 61
    ///  
    /// Constraints:
    /// 1. 1 <= nums1.length <= 10^5
    /// 2. 1 <= nums2.length <= 10^5
    /// 3. 1 <= nums1[i], nums2[i] <= 10^7
    /// 4. nums1 and nums2 are strictly increasing.
    /// </summary>
    int maxSum(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet code #1539. Kth Missing Positive Number
    /// 
    /// Easy
    ///
    /// Given an array arr of positive integers sorted in a strictly increasing
    /// order, and an integer k.
    ///
    /// Find the kth positive integer that is missing from this array.
    ///
    /// Example 1:
    /// Input: arr = [2,3,4,7,11], k = 5
    /// Output: 9
    /// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...].
    /// The 5th missing positive integer is 9.
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,2,3,4], k = 2
    /// Output: 6
    /// Explanation: The missing positive integers are [5,6,7,...]. 
    /// The 2nd missing positive integer is 6.
    /// Constraints:
    /// 1. 1 <= arr.length <= 1000
    /// 2. 1 <= arr[i] <= 1000
    /// 3. 1 <= k <= 1000
    /// 4. arr[i] < arr[j] for 1 <= i < j <= arr.lengthYou are given two sorted 
    ///    arrays of distinct integers nums1 and nums2.
    /// </summary>
    int findKthPositive(vector<int>& arr, int k);

    /// <summary>
    /// Leet code #1550. Three Consecutive Odds
    /// 
    /// Easy
    ///
    /// Given an integer array arr, return true if there are three consecutive 
    /// odd numbers in the array. Otherwise, return false.
    ///
    /// Example 1:
    /// Input: arr = [2,6,4,1]
    /// Output: false
    /// Explanation: There are no three consecutive odds.
    ///
    /// Example 2:
    /// Input: arr = [1,2,34,3,4,5,7,23,12]
    /// Output: true
    /// Explanation: [5,7,23] are three consecutive odds.
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 1000
    /// 2. 1 <= arr[i] <= 1000
    /// </summary>
    bool threeConsecutiveOdds(vector<int>& arr);

    /// <summary>
    /// Leet code #1538. Guess the Majority in a Hidden Array
    /// 
    /// Medium
    ///
    /// We have an integer array nums, where all the integers in nums are 0 
    /// or 1. You will not be given direct access to the array, instead, you 
    /// will have an API ArrayReader which have the following functions:
    /// 
    /// int query(int a, int b, int c, int d): where 0 <= a < b < c < d < 
    /// ArrayReader.length(). The function returns the distribution of the 
    /// value of the 4 elements and returns:
    /// 4 : if the values of the 4 elements are the same (0 or 1).
    /// 2 : if three elements have a value equal to 0 and one element has 
    /// value equal to 1 or vice versa.
    /// 0 : if two element have a value equal to 0 and two elements have a 
    /// value equal to 1.
    /// int length(): Returns the size of the array.
    /// You are allowed to call query() 2 * n times at most where n is equal 
    /// to ArrayReader.length().
    ///
    /// Return any index of the most frequent value in nums, in case of tie, 
    /// return -1.
    /// 
    /// Follow up: What is the minimum number of calls needed to find the 
    /// majority element?
    ///
    /// Example 1:
    /// Input: nums = [0,0,1,0,1,1,1,1]
    /// Output: 5
    /// Explanation: The following calls to the API
    /// reader.length() // returns 8 because there are 8 elements in the hidden
    ///                 // array.
    /// reader.query(0,1,2,3) // returns 2 this is a query that compares the 
    ///                       // elements nums[0], nums[1], nums[2], nums[3]
    ///                       // Three elements have a value equal to 0 and one 
    ///                       // element has value equal to 1 or viceversa.
    /// reader.query(4,5,6,7) // returns 4 because nums[4], nums[5], nums[6], 
    ///                       // nums[7] have the same value.
    ///                       // we can infer that the most frequent value is 
    ///                       // found in the last 4 elements.
    ///                       // Index 2, 4, 6, 7 is also a correct answer.
    ///
    /// Example 2:
    /// Input: nums = [0,0,1,1,0]
    /// Output: 0
    ///
    /// Example 3:
    /// Input: nums = [1,0,1,0,1,0,1,0]
    /// Output: -1
    /// Constraints:
    /// 1. 5 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 1
    /// </summary>
    int guessMajority(ArrayReader& reader);

    /// <summary>
    /// Leet code #1533. Find the Index of the Large Integer
    /// 
    /// Medium
    ///
    /// We have an integer array arr, where all the integers in arr are equal 
    /// except for one integer which is larger than the rest of the integers. 
    /// You will not be given direct access to the array, instead, you will 
    /// have an API ArrayReader which have the following functions:
    /// int compareSub(int l, int r, int x, int y): where 0 <= l, r, x, y < 
    /// ArrayReader.length(), l <= r and x <= y. The function compares the 
    /// sum of sub-array arr[l..r] with the sum of the sub-array arr[x..y] 
    /// and returns:
    /// 1 if arr[l]+arr[l+1]+...+arr[r] > arr[x]+arr[x+1]+...+arr[y].
    /// 0 if arr[l]+arr[l+1]+...+arr[r] == arr[x]+arr[x+1]+...+arr[y].
    /// -1 if arr[l]+arr[l+1]+...+arr[r] < arr[x]+arr[x+1]+...+arr[y].
    /// int length(): Returns the size of the array.
    /// You are allowed to call compareSub() 20 times at most. You can 
    /// assume both functions work in O(1) time.
    ///
    /// Return the index of the array arr which has the largest integer.
    /// Follow-up:
    /// What if there are two numbers in arr that are bigger than all other 
    /// numbers?
    /// What if there is one number that is bigger than other numbers and 
    /// one number that is smaller than other numbers?
    /// 
    /// Example 1: 
    /// Input: arr = [7,7,7,7,10,7,7,7]
    /// Output: 4
    /// Explanation: The following calls to the API
    /// reader.compareSub(0, 0, 1, 1) // returns 0 this is a query comparing 
    /// the sub-array (0, 0) with the sub array (1, 1), (i.e. compares arr[0] 
    /// with arr[1]).
    /// Thus we know that arr[0] and arr[1] doesn't contain the largest 
    /// element.
    /// reader.compareSub(2, 2, 3, 3) // returns 0.
    /// reader.compareSub(4, 4, 5, 5) // returns 1.
    /// Notice that we made only 3 calls, so the answer is valid.
    ///
    /// Example 2:
    /// Input: nums = [6,6,12]
    /// Output: 2
    /// 
    /// Constraints:
    /// 1. 2 <= arr.length <= 5 * 10^5
    /// 2. 1 <= arr[i] <= 100
    /// 3. All elements of arr are equal except for one element which is 
    /// larger than all other elements.
    /// </summary>
    int getIndex(ArrayReader& reader);

    /// <summary>
    /// Leet code #1566. Detect Pattern of Length M Repeated K or More Times
    /// 
    /// Easy
    ///
    /// Given an array of positive integers arr,  find a pattern of length m 
    /// that is repeated k or more times.
    ///
    /// A pattern is a subarray (consecutive sub-sequence) that consists of 
    /// one or more values, repeated multiple times consecutively without 
    /// overlapping. A pattern is defined by its length and the number of 
    /// repetitions.
    ///
    /// Return true if there exists a pattern of length m that is repeated 
    /// k or more times, otherwise return false.
    /// 
    /// Example 1:
    /// Input: arr = [1,2,4,4,4,4], m = 1, k = 3
    /// Output: true
    /// Explanation: The pattern (4) of length 1 is repeated 4 consecutive 
    /// times. Notice that pattern can be repeated k or more times but not 
    /// less.
    ///
    /// Example 2:
    /// Input: arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
    /// Output: true
    /// Explanation: The pattern (1,2) of length 2 is repeated 2 consecutive 
    /// times. Another valid pattern (2,1) is also repeated 2 times.
    ///
    /// Example 3:
    /// Input: arr = [1,2,1,2,1,3], m = 2, k = 3
    /// Output: false
    /// Explanation: The pattern (1,2) is of length 2 but is repeated only 2 
    /// times. There is no pattern of length 2 that is repeated 3 or more 
    /// times.
    ///
    /// Example 4:
    /// Input: arr = [1,2,3,1,2], m = 2, k = 2
    /// Output: false
    /// Explanation: Notice that the pattern (1,2) exists twice but not 
    /// consecutively, so it doesn't count.
    ///
    /// Example 5:
    /// Input: arr = [2,2,2,2], m = 2, k = 3
    /// Output: false
    /// Explanation: The only pattern of length 2 is (2,2) however it's 
    /// repeated only twice. Notice that we do not count overlapping 
    /// repetitions.
    /// 
    /// Constraints:
    /// 1. 2 <= arr.length <= 100
    /// 2. 1 <= arr[i] <= 100
    /// 3. 1 <= m <= 100
    /// 4. 2 <= k <= 100
    /// </summary>
    bool containsPattern(vector<int>& arr, int m, int k);

    /// <summary>
    /// Leet code #1567. Maximum Length of Subarray With Positive Product
    /// 
    /// Medium
    ///
    /// Given an array of integers nums, find the maximum length of a subarray 
    /// where the product of all its elements is positive.
    ///
    /// A subarray of an array is a consecutive sequence of zero or more 
    /// values taken out of that array.
    ///
    /// Return the maximum length of a subarray with positive product.
    ///
    /// Example 1:
    /// Input: nums = [1,-2,-3,4]
    /// Output: 4
    /// Explanation: The array nums already has a positive product of 24.
    ///
    /// Example 2:
    /// Input: nums = [0,1,-2,-3,-4]
    /// Output: 3
    /// Explanation: The longest subarray with positive product is [1,-2,-3] 
    /// which has a product of 6.
    /// Notice that we cannot include 0 in the subarray since that'll make 
    /// the product 0 which is not positive.
    ///
    /// Example 3:
    /// Input: nums = [-1,-2,-3,0,1]
    /// Output: 2
    /// Explanation: The longest subarray with positive product is [-1,-2] 
    /// or [-2,-3].
    ///
    /// Example 4:
    /// Input: nums = [-1,2]
    /// Output: 1
    ///
    /// Example 5:
    /// Input: nums = [1,2,3,5,-6,4,0,10]
    /// Output: 4
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// </summary>
    int getMaxLen(vector<int>& nums);

    /// <summary>
    /// Leet code #1572. Matrix Diagonal Sum
    /// 
    /// Easy
    ///
    /// Given a square matrix mat, return the sum of the matrix diagonals. 
    /// Only include the sum of all the elements on the primary diagonal and 
    /// all the elements on the secondary diagonal that are not part of the 
    /// primary diagonal.
    ///
    /// Example 1:
    /// Input: mat = [[1,2,3],
    ///          [4,5,6],
    ///          [7,8,9]]
    /// Output: 25
    /// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
    /// Notice that element mat[1][1] = 5 is counted only once.
    ///
    /// Example 2:
    /// Input: mat = [[1,1,1,1],
    ///          [1,1,1,1],
    ///          [1,1,1,1],
    ///          [1,1,1,1]]
    /// Output: 8
    ///
    /// Example 3:
    /// Input: mat = [[5]]
    /// Output: 5
    ///
    /// Constraints:
    /// 1. n == mat.length == mat[i].length
    /// 2. 1 <= n <= 100
    /// 3. 1 <= mat[i][j] <= 100
    /// </summary>
    int diagonalSum(vector<vector<int>>& mat);

    /// <summary>
    /// Leet code #1574. Shortest Subarray to be Removed to Make Array Sorted 
    /// 
    /// Medium
    ///
    /// Given an integer array arr, remove a subarray (can be empty) from arr 
    /// such that the remaining elements in arr are non-decreasing.
    ///
    /// A subarray is a contiguous subsequence of the array.
    /// Return the length of the shortest subarray to remove.
    ///
    /// Example 1:
    /// Input: arr = [1,2,3,10,4,2,3,5]
    /// Output: 3
    /// Explanation: The shortest subarray we can remove is [10,4,2] of 
    /// length 3. The remaining elements after that will be [1,2,3,3,5] which 
    /// are sorted.
    /// Another correct solution is to remove the subarray [3,10,4].
    ///
    /// Example 2:
    /// Input: arr = [5,4,3,2,1]
    /// Output: 4
    /// Explanation: Since the array is strictly decreasing, we can only keep 
    /// a single element. Therefore we need to remove a subarray of length 4, 
    /// either [5,4,3,2] or [4,3,2,1].
    ///
    /// Example 3:
    /// Input: arr = [1,2,3]
    /// Output: 0
    /// Explanation: The array is already non-decreasing. We do not need to 
    /// remove any elements.
    ///
    /// Example 4:
    /// Input: arr = [1]
    /// Output: 0
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 10^5
    /// 2. 0 <= arr[i] <= 10^9
    /// </summary>
    int findLengthOfShortestSubarray(vector<int>& arr);

    /// <summary>
    /// Leet code #1582. Special Positions in a Binary Matrix 
    /// 
    /// Easy
    ///
    /// Given a rows x cols matrix mat, where mat[i][j] is either 0 or 1, 
    /// return the number of special positions in mat.
    ///
    /// A position (i,j) is called special if mat[i][j] == 1 and all other 
    /// elements in row i and column j are 0 (rows and columns are 0-indexed).
    ///
    /// Example 1:
    /// Input: mat = [[1,0,0],
    ///          [0,0,1],
    ///          [1,0,0]]
    /// Output: 1
    /// Explanation: (1,2) is a special position because mat[1][2] == 1 and 
    /// all other elements in row 1 and column 2 are 0.
    ///
    /// Example 2:
    /// Input: mat = [[1,0,0],
    ///          [0,1,0],
    ///          [0,0,1]]
    /// Output: 3
    /// Explanation: (0,0), (1,1) and (2,2) are special positions. 
    ///
    /// Example 3:
    /// Input: mat = [[0,0,0,1],
    ///          [1,0,0,0],
    ///          [0,1,1,0],
    ///          [0,0,0,0]]
    /// Output: 2
    ///
    /// Example 4:
    /// Input: mat = [[0,0,0,0,0],
    ///          [1,0,0,0,0],
    ///          [0,1,0,0,0],
    ///          [0,0,1,0,0],
    ///          [0,0,0,1,1]]
    /// Output: 3
    /// Constraints:
    /// 1. rows == mat.length
    /// 2. cols == mat[i].length
    /// 3. 1 <= rows, cols <= 100
    /// 4. mat[i][j] is 0 or 1.
    /// </summary>
    int numSpecial(vector<vector<int>>& mat);

    /// <summary>
    /// Leet code #1583. Count Unhappy Friends
    /// 
    /// Medium
    ///
    /// You are given a list of preferences for n friends, where n is always 
    /// even.
    ///
    /// For each person i, preferences[i] contains a list of friends sorted 
    /// in the order of preference. In other words, a friend earlier in the 
    /// list is more preferred than a friend later in the list. Friends in 
    /// each list are denoted by integers from 0 to n-1.
    ///
    /// All the friends are divided into pairs. The pairings are given in a 
    /// list pairs, where pairs[i] = [xi, yi] denotes xi is paired with yi 
    /// and yi is paired with xi.
    ///
    /// However, this pairing may cause some of the friends to be unhappy. 
    /// A friend x is unhappy if x is paired with y and there exists a 
    /// friend u who is paired with v but:
    ///
    /// x prefers u over y, and
    /// u prefers x over v.
    /// Return the number of unhappy friends.
    /// 
    /// Example 1:
    /// Input: n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], 
    /// [1, 2, 0]], pairs = [[0, 1], [2, 3]]
    /// Output: 2
    /// Explanation:
    /// Friend 1 is unhappy because:
    /// - 1 is paired with 0 but prefers 3 over 0, and
    /// - 3 prefers 1 over 2.
    /// Friend 3 is unhappy because:
    /// - 3 is paired with 2 but prefers 1 over 2, and
    /// - 1 prefers 3 over 0.
    /// Friends 0 and 2 are happy.
    ///
    /// Example 2:
    /// Input: n = 2, preferences = [[1], [0]], pairs = [[1, 0]]
    /// Output: 0
    /// Explanation: Both friends 0 and 1 are happy.
    ///
    /// Example 3:
    /// Input: n = 4, preferences = [[1, 3, 2], [2, 3, 0], [1, 3, 0], 
    /// [0, 2, 1]], pairs = [[1, 3], [0, 2]]
    /// Output: 4
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 500
    /// 2. n is even.
    /// 3. preferences.length == n
    /// 4. preferences[i].length == n - 1
    /// 5. 0 <= preferences[i][j] <= n - 1
    /// 6. preferences[i] does not contain i.
    /// 7. All values in preferences[i] are unique.
    /// 8. pairs.length == n/2
    /// 9. pairs[i].length == 2
    /// 10. xi != yi
    /// 11. 0 <= xi, yi <= n - 1
    /// 12. Each person is contained in exactly one pair.
    /// </summary>
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs);

    /// <summary>
    /// Leet code #1588. Sum of All Odd Length Subarrays 
    /// 
    /// Easy
    ///
    /// Given an array of positive integers arr, calculate the sum of all 
    /// possible odd-length subarrays.
    ///
    /// A subarray is a contiguous subsequence of the array.
    /// Return the sum of all odd-length subarrays of arr.
    ///
    /// Example 1:
    /// Input: arr = [1,4,2,5,3]
    /// Output: 58
    /// Explanation: The odd-length subarrays of arr and their sums are:
    /// [1] = 1
    /// [4] = 4
    /// [2] = 2
    /// [5] = 5
    /// [3] = 3
    /// [1,4,2] = 7
    /// [4,2,5] = 11
    /// [2,5,3] = 10
    /// [1,4,2,5,3] = 15
    /// If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 
    /// 10 + 15 = 58
    /// 
    /// Example 2:
    /// Input: arr = [1,2]
    /// Output: 3
    /// Explanation: There are only 2 subarrays of odd length, [1] 
    /// and [2]. Their sum is 3.
    ///
    /// Example 3:
    /// Input: arr = [10,11,12]
    /// Output: 66
    /// Constraints:
    /// 1. 1 <= arr.length <= 100
    /// 2. 1 <= arr[i] <= 1000
    /// </summary>
    int sumOddLengthSubarrays(vector<int>& arr);

    /// <summary>
    /// Leet code #1590. Make Sum Divisible by P
    /// 
    /// Medium
    ///
    /// Given an array of positive integers nums, remove the smallest subarray 
    /// (possibly empty) such that the sum of the remaining elements is 
    /// divisible by p. It is not allowed to remove the whole array.
    ///
    /// Return the length of the smallest subarray that you need to remove, 
    /// or -1 if it's impossible.
    ///
    /// A subarray is defined as a contiguous block of elements in the array.
    /// 
    /// Example 1:
    /// Input: nums = [3,1,4,2], p = 6
    /// Output: 1
    /// Explanation: The sum of the elements in nums is 10, which is not 
    /// divisible by 6. We can remove the subarray [4], and the sum of the 
    /// remaining elements is 6, which is divisible by 6.
    ///
    /// Example 2:
    /// Input: nums = [6,3,5,2], p = 9
    /// Output: 2
    /// Explanation: We cannot remove a single element to get a sum divisible 
    /// by 9. The best way is to remove the subarray [5,2], leaving us with 
    /// [6,3] with sum 9.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3], p = 3
    /// Output: 0
    /// Explanation: Here the sum is 6. which is already divisible by 3. Thus 
    /// we do not need to remove anything.
    ///
    /// Example 4:
    /// Input: nums = [1,2,3], p = 7
    /// Output: -1
    /// Explanation: There is no way to remove a subarray in order to get a 
    /// sum divisible by 7.
    ///
    /// Example 5:
    /// Input: nums = [1000000000,1000000000,1000000000], p = 3
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= p <= 10^9
    /// </summary>
    int minSubarray(vector<int>& nums, int p);

    /// <summary>
    /// Leet code #1599. Maximum Profit of Operating a Centennial Wheel
    /// 
    /// Medium
    ///
    /// You are the operator of a Centennial Wheel that has four gondolas, 
    /// and each gondola has room for up to four people. You have the ability 
    /// to rotate the gondolas counterclockwise, which costs you runningCost 
    /// dollars.
    ///
    /// You are given an array customers of length n where customers[i] is 
    /// the number of new customers arriving just before the ith rotation 
    /// (0-indexed). This means you must rotate the wheel i times before 
    /// customers[i] arrive. Each customer pays boardingCost dollars when 
    /// they board on the gondola closest to the ground and will exit once 
    /// that gondola reaches the ground again.
    ///
    /// You can stop the wheel at any time, including before serving all 
    /// customers. If you decide to stop serving customers, all subsequent 
    /// rotations are free in order to get all the customers down safely. 
    /// Note that if there are currently more than four customers waiting at 
    /// the wheel, only four will board the gondola, and the rest will wait 
    /// for the next rotation.
    /// 
    /// Return the minimum number of rotations you need to perform to maximize 
    /// your profit. If there is no scenario where the profit is positive, 
    /// return -1.
    ///
    /// Example 1:
    /// 
    /// Input: customers = [8,3], boardingCost = 5, runningCost = 6
    /// Output: 3
    /// Explanation: The numbers written on the gondolas are the number of 
    /// people currently there.
    /// 1. 8 customers arrive, 4 board and 4 wait for the next gondola, the 
    ///    wheel rotates. Current profit is 4 * $5 - 1 * $6 = $14.
    /// 2. 3 customers arrive, the 4 waiting board the wheel and the other 3 
    ///    wait, the wheel rotates. Current profit is 8 * $5 - 2 * $6 = $28.
    /// 3. The final 3 customers board the gondola, the wheel rotates. Current 
    ///    profit is 11 * $5 - 3 * $6 = $37.
    /// 4. The highest profit was $37 after rotating the wheel 3 times.
    ///
    /// Example 2:
    /// Input: customers = [10,9,6], boardingCost = 6, runningCost = 4
    /// Output: 7
    /// Explanation:
    /// 1. 10 customers arrive, 4 board and 6 wait for the next gondola, the 
    ///    wheel rotates. Current profit is 4 * $6 - 1 * $4 = $20.
    /// 2. 9 customers arrive, 4 board and 11 wait (2 originally waiting, 9 
    ///    newly waiting), the wheel rotates. Current profit is 
    ///    8 * $6 - 2 * $4 = $40.
    /// 3. The final 6 customers arrive, 4 board and 13 wait, the wheel 
    ///    rotates. Current profit is 12 * $6 - 3 * $4 = $60.
    /// 4. 4 board and 9 wait, the wheel rotates. Current profit is 
    ///    16 * $6 - 4 * $4 = $80.
    /// 5. 4 board and 5 wait, the wheel rotates. Current profit is 
    ///    20 * $6 - 5 * $4 = $100.
    /// 6. 4 board and 1 waits, the wheel rotates. Current profit is 
    ///    24 * $6 - 6 * $4 = $120.
    /// 7. 1 boards, the wheel rotates. Current profit is 
    ///    25 * $6 - 7 * $4 = $122.
    /// 8. The highest profit was $122 after rotating the wheel 7 times.
    ///
    /// Example 3:
    /// Input: customers = [3,4,0,5,1], boardingCost = 1, runningCost = 92
    /// Output: -1
    /// Explanation:
    /// 1. 3 customers arrive, 3 board and 0 wait, the wheel rotates. Current 
    ///    profit is 3 * $1 - 1 * $92 = -$89.
    /// 2. 4 customers arrive, 4 board and 0 wait, the wheel rotates. Current 
    ///    profit is 7 * $1 - 2 * $92 = -$177.
    /// 3. 0 customers arrive, 0 board and 0 wait, the wheel rotates. Current 
    ///    profit is 7 * $1 - 3 * $92 = -$269.
    /// 4. 5 customers arrive, 4 board and 1 waits, the wheel rotates. Current 
    ///    profit is 12 * $1 - 4 * $92 = -$356.
    /// 5. 1 customer arrives, 2 board and 0 wait, the wheel rotates. Current 
    ///    profit is 13 * $1 - 5 * $92 = -$447.
    /// 6. The profit was never positive, so return -1.
    ///
    /// Example 4:
    /// Input: customers = [10,10,6,4,7], boardingCost = 3, runningCost = 8
    /// Output: 9
    /// Explanation:
    /// 1. 10 customers arrive, 4 board and 6 wait, the wheel rotates. Current 
    ///    profit is 4 * $3 - 1 * $8 = $4.
    /// 2. 10 customers arrive, 4 board and 12 wait, the wheel rotates. Current 
    ///    profit is 8 * $3 - 2 * $8 = $8.
    /// 3. 6 customers arrive, 4 board and 14 wait, the wheel rotates. Current 
    ///    profit is 12 * $3 - 3 * $8 = $12.
    /// 4. 4 customers arrive, 4 board and 14 wait, the wheel rotates. Current 
    ///    profit is 16 * $3 - 4 * $8 = $16.
    /// 5. 7 customers arrive, 4 board and 17 wait, the wheel rotates. Current 
    ///    profit is 20 * $3 - 5 * $8 = $20.
    /// 6. 4 board and 13 wait, the wheel rotates. Current profit 
    ///    is 24 * $3 - 6 * $8 = $24.
    /// 7. 4 board and 9 wait, the wheel rotates. Current profit is 
    ///    28 * $3 - 7 * $8 = $28.
    /// 8. 4 board and 5 wait, the wheel rotates. Current profit is 
    ///    32 * $3 - 8 * $8 = $32.
    /// 9. 4 board and 1 waits, the wheel rotates. Current profit is 
    ///    36 * $3 - 9 * $8 = $36.
    /// 10. 1 board and 0 wait, the wheel rotates. Current profit is 
    ///    37 * $3 - 10 * $8 = $31.
    /// 11. The highest profit was $36 after rotating the wheel 9 times.
    ///
    /// Constraints:
    /// 1. n == customers.length
    /// 2. 1 <= n <= 10^5
    /// 3. 0 <= customers[i] <= 50
    /// 4. 1 <= boardingCost, runningCost <= 100
    /// </summary>
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost);

    /// <summary>
    /// Leet code #1605. Find Valid Matrix Given Row and Column Sums
    /// 
    /// Medium
    ///
    /// You are given two arrays rowSum and colSum of non-negative integers 
    /// where rowSum[i] is the sum of the elements in the ith row and colSum[j] 
    /// is the sum of the elements of the jth column of a 2D matrix. In other 
    /// words, you do not know the elements of the matrix, but you do know the 
    /// sums of each row and column.
    ///
    /// Find any matrix of non-negative integers of size rowSum.length x 
    /// colSum.length that satisfies the rowSum and colSum requirements.
    ///
    /// Return a 2D array representing any matrix that fulfills the 
    /// requirements. It's guaranteed that at least one matrix that fulfills 
    /// the requirements exists.
    ///
    /// Example 1:
    /// Input: rowSum = [3,8], colSum = [4,7]
    /// Output: [[3,0],
    ///          [1,7]]
    /// Explanation:
    /// 0th row: 3 + 0 = 0 == rowSum[0]
    /// 1st row: 1 + 7 = 8 == rowSum[1]
    /// 0th column: 3 + 1 = 4 == colSum[0]
    /// 1st column: 0 + 7 = 7 == colSum[1]
    /// The row and column sums match, and all matrix elements are 
    /// non-negative.
    /// Another possible matrix is: [[1,2],
    ///                              [3,5]]
    /// Example 2:
    /// Input: rowSum = [5,7,10], colSum = [8,6,8]
    /// Output: [[0,5,0],
    ///          [6,1,0],
    ///         [2,0,8]]
    ///
    /// Example 3:
    /// Input: rowSum = [14,9], colSum = [6,9,8]
    /// Output: [[0,9,5],
    ///          [6,0,3]]
    ///
    /// Example 4:
    /// Input: rowSum = [1,0], colSum = [1]
    /// Output: [[1],
    ///          [0]]
    ///
    /// Example 5:
    /// Input: rowSum = [0], colSum = [0]
    /// Output: [[0]]
    ///
    /// Constraints:
    /// 1. 1 <= rowSum.length, colSum.length <= 500
    /// 2. 0 <= rowSum[i], colSum[i] <= 108
    /// 3. sum(rows) == sum(columns)
    /// </summary>
    vector<vector<int>> restoreMatrix(vector<int> rowSum, vector<int> colSum);

    /// <summary>
    /// Leet code #1629. Slowest Key
    /// 
    /// Easy
    ///
    /// A newly designed keypad was tested, where a tester pressed a sequence 
    /// of n keys, one at a time.
    ///
    /// You are given a string keysPressed of length n, where keysPressed[i] 
    /// was the ith key pressed in the testing sequence, and a sorted list 
    /// releaseTimes, where releaseTimes[i] was the time the ith key was 
    /// released. Both arrays are 0-indexed. The 0th key was pressed at the 
    /// time 0, and every subsequent key was pressed at the exact time the 
    /// previous key was released.
    ///
    /// The tester wants to know the key of the keypress that had the longest 
    /// duration. The ith keypress had a duration of releaseTimes[i] - 
    /// releaseTimes[i - 1], and the 0th keypress had a duration of 
    /// releaseTimes[0].
    ///
    /// Note that the same key could have been pressed multiple times during 
    /// the test, and these multiple presses of the same key may not have had 
    /// the same duration.
    ///
    /// Return the key of the keypress that had the longest duration. If there 
    /// are multiple such keypresses, return the lexicographically largest key 
    /// of the keypresses.
    ///
    /// Example 1:
    /// Input: releaseTimes = [9,29,49,50], keysPressed = "cbcd"
    /// Output: "c"
    /// Explanation: The keypresses were as follows:
    /// Keypress for 'c' had a duration of 9 (pressed at time 0 and released 
    /// at time 9).
    /// Keypress for 'b' had a duration of 29 - 9 = 20 (pressed at time 9 
    /// right after the release of the previous character and released at 
    /// time 29).
    /// Keypress for 'c' had a duration of 49 - 29 = 20 (pressed at time 29 
    /// right after the release of the previous character and released at 
    /// time 49).
    /// Keypress for 'd' had a duration of 50 - 49 = 1 (pressed at time 49 
    /// right after the release of the previous character and released at 
    /// time 50).
    /// The longest of these was the keypress for 'b' and the second keypress 
    /// for 'c', both with duration 20.
    /// 'c' is lexicographically larger than 'b', so the answer is 'c'.
    ///
    /// Example 2:
    /// Input: releaseTimes = [12,23,36,46,62], keysPressed = "spuda"
    /// Output: "a"
    /// Explanation: The keypresses were as follows:
    /// Keypress for 's' had a duration of 12.
    /// Keypress for 'p' had a duration of 23 - 12 = 11.
    /// Keypress for 'u' had a duration of 36 - 23 = 13.
    /// Keypress for 'd' had a duration of 46 - 36 = 10.
    /// Keypress for 'a' had a duration of 62 - 46 = 16.
    /// The longest of these was the keypress for 'a' with duration 16.
    ///
    /// Constraints:
    /// 1. releaseTimes.length == n
    /// 2. keysPressed.length == n
    /// 3. 2 <= n <= 1000
    /// 4. 1 <= releaseTimes[i] <= 10^9 
    /// 5. releaseTimes[i] < releaseTimes[i+1]
    /// 6. keysPressed contains only lowercase English letters.
    /// </summary>
    char slowestKey(vector<int>& releaseTimes, string keysPressed);

    /// <summary>
    /// Leet code #1630. Arithmetic Subarrays
    /// 
    /// Medium
    ///
    /// A sequence of numbers is called arithmetic if it consists of at least 
    /// two elements, and the difference between every two consecutive 
    /// elements is the same. More formally, a sequence s is arithmetic if and 
    /// only if s[i+1] - s[i] == s[1] - s[0] for all valid i.
    /// 
    /// For example, these are arithmetic sequences:
    /// 1, 3, 5, 7, 9
    /// 7, 7, 7, 7
    /// 3, -1, -5, -9
    /// The following sequence is not arithmetic:
    /// 
    /// 1, 1, 2, 5, 7
    /// You are given an array of n integers, nums, and two arrays of m 
    /// integers each, l and r, representing the m range queries, where the 
    /// ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
    ///
    /// Return a list of boolean elements answer, where answer[i] is true if 
    /// the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be 
    /// rearranged to form an arithmetic sequence, and false otherwise.
    /// 
    /// Example 1:
    /// Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
    /// Output: [true,false,true]
    /// Explanation:
    /// In the 0th query, the subarray is [4,6,5]. This can be rearranged 
    /// as [6,5,4], which is an arithmetic sequence.
    /// In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged 
    /// as an arithmetic sequence.
    /// In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged 
    /// as [3,5,7,9], which is an arithmetic sequence.
    ///
    /// Example 2:
    /// Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], 
    /// l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
    /// Output: [false,true,false,false,true,true]
    /// 
    /// Constraints:
    ///
    /// 1. n == nums.length
    /// 2. m == l.length
    /// 3. m == r.length
    /// 4. 2 <= n <= 500
    /// 5. 1 <= m <= 500
    /// 6. 0 <= l[i] < r[i] < n
    /// 7. -10^5 <= nums[i] <= 10^5
    /// </summary>
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r);

    /// <summary>
    /// Leet code #1636. Sort Array by Increasing Frequency
    /// 
    /// Easy
    ///
    /// Given an array of integers nums, sort the array in increasing order 
    /// based on the frequency of the values. If multiple values have the 
    /// same frequency, sort them in decreasing order.
    ///
    /// Return the sorted array.
    ///
    /// Example 1:
    /// Input: nums = [1,1,2,2,2,3]
    /// Output: [3,1,1,2,2,2]
    /// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, 
    /// and '2' has a frequency of 3.
    ///
    /// Example 2:
    /// Input: nums = [2,3,1,3,2]
    /// Output: [1,3,3,2,2]
    /// Explanation: '2' and '3' both have a frequency of 2, so they are 
    /// sorted in decreasing order.
    ///
    /// Example 3:
    /// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
    /// Output: [5,-1,4,4,-6,-6,1,1,1]
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. -100 <= nums[i] <= 100
    /// </summary>
    vector<int> frequencySort(vector<int>& nums);

    /// <summary>
    /// Leet code #1640. Check Array Formation Through Concatenation
    /// 
    /// Easy
    ///
    /// You are given an array of distinct integers arr and an array of 
    /// integer arrays pieces, where the integers in pieces are distinct. 
    /// Your goal is to form arr by concatenating the arrays in pieces in 
    /// any order. However, you are not allowed to reorder the integers 
    /// in each array pieces[i].
    /// 
    /// Return true if it is possible to form the array arr from pieces. 
    /// Otherwise, return false.
    ///
    /// Example 1:
    /// Input: arr = [85], pieces = [[85]]
    /// Output: true
    ///
    /// Example 2:
    /// Input: arr = [15,88], pieces = [[88],[15]]
    /// Output: true
    /// Explanation: Concatenate [15] then [88]
    ///
    /// Example 3:
    /// Input: arr = [49,18,16], pieces = [[16,18,49]]
    /// Output: false
    /// Explanation: Even though the numbers match, we cannot reorder pieces[0].
    ///
    /// Example 4:
    /// Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
    /// Output: true
    /// Explanation: Concatenate [91] then [4,64] then [78]
    ///
    /// Example 5:
    /// Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
    /// Output: false
    ///
    /// Constraints:
    /// 1. 1 <= pieces.length <= arr.length <= 100
    /// 2. sum(pieces[i].length) == arr.length
    /// 3. 1 <= pieces[i].length <= arr.length
    /// 4. 1 <= arr[i], pieces[i][j] <= 100
    /// 5. The integers in arr are distinct. 
    /// 6. The integers in pieces are distinct (i.e., If we flatten pieces in a 1D 
    ///    array, all the integers in this array are distinct).
    /// </summary>
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces);

    /// <summary>
    /// Leet code #1637. Widest Vertical Area Between Two Points Containing 
    ///                  No Points
    /// 
    /// Medium
    ///
    /// Given n points on a 2D plane where points[i] = [x[i], y[i]], Return 
    /// the widest vertical area between two points such that no points are 
    /// inside the area.
    ///
    /// A vertical area is an area of fixed-width extending infinitely along 
    /// the y-axis (i.e., infinite height). The widest vertical area is the 
    /// one with the maximum width.
    ///
    /// Note that points on the edge of a vertical area are not considered 
    /// included in the area.
    ///
    /// Example 1:
    /// Input: points = [[8,7],[9,9],[7,4],[9,7]]
    /// Output: 1
    /// Explanation: Both the red and the blue area are optimal.
    ///
    /// Example 2:
    /// Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
    /// Output: 3
    /// Constraints:
    /// 1. n == points.length
    /// 2. 2 <= n <= 10^5
    /// 3. points[i].length == 2
    /// 4. 0 <= x[i], y[i] <= 10^9
    /// </summary>
    int maxWidthOfVerticalArea(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1646. Get Maximum in Generated Array
    /// 
    /// Easy
    ///
    /// You are given an integer n. An array nums of length n + 1 is 
    /// generated in the following way:
    ///
    /// nums[0] = 0
    /// nums[1] = 1
    /// nums[2 * i] = nums[i] when 2 <= 2 * i <= n
    /// nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
    /// Return the maximum integer in the array nums.
    ///
    /// Example 1:
    /// Input: n = 7
    /// Output: 3
    /// Explanation: According to the given rules:
    /// nums[0] = 0
    /// nums[1] = 1
    /// nums[(1 * 2) = 2] = nums[1] = 1
    /// nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
    /// nums[(2 * 2) = 4] = nums[2] = 1
    /// nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
    /// nums[(3 * 2) = 6] = nums[3] = 2
    /// nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
    /// Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is 3.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 1
    /// Explanation: According to the given rules, the maximum between 
    /// nums[0], nums[1], and nums[2] is 1.
    ///
    /// Example 3:
    /// Input: n = 3
    /// Output: 2
    /// Explanation: According to the given rules, the maximum between 
    /// nums[0], nums[1], nums[2], and nums[3] is 2.
    ///
    /// Constraints:
    /// 1. 0 <= n <= 100
    /// </summary>
    int getMaximumGenerated(int n);

    /// <summary>
    /// Leet code #1652. Defuse the Bomb
    /// 
    /// Easy
    ///
    /// You have a bomb to defuse, and your time is running out! Your informer 
    /// will provide you with a circular array code of length of n and a key k.
    ///
    /// To decrypt the code, you must replace every number. All the numbers are 
    /// replaced simultaneously.
    /// 
    /// If k > 0, replace the ith number with the sum of the next k numbers.
    /// If k < 0, replace the ith number with the sum of the previous k numbers.
    /// If k == 0, replace the ith number with 0.
    /// As code is circular, the next element of code[n-1] is code[0], and the 
    /// previous element of code[0] is code[n-1].
    ///
    /// Given the circular array code and an integer key k, return the 
    /// decrypted code to defuse the bomb!
    /// 
    /// Example 1:
    /// Input: code = [5,7,1,4], k = 3
    /// Output: [12,10,16,13]
    /// Explanation: Each number is replaced by the sum of the next 3 numbers. 
    /// The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the 
    /// numbers wrap around.
    ///
    /// Example 2:
    /// Input: code = [1,2,3,4], k = 0
    /// Output: [0,0,0,0]
    /// Explanation: When k is zero, the numbers are replaced by 0. 
    ///
    /// Example 3:
    /// 1. Input: code = [2,4,9,3], k = -2
    /// 2. Output: [12,5,6,13]
    /// Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that 
    /// the numbers wrap around again. If k is negative, the sum is of the 
    /// previous numbers.
    /// Constraints:
    /// 1. n == code.length
    /// 2. 1 <= n <= 100
    /// 3. 1 <= code[i] <= 100
    /// 4. -(n - 1) <= k <= n - 1
    /// </summary>
    vector<int> decrypt(vector<int>& code, int k);

    /// <summary>
    /// Leet code #1656. Design an Ordered Stream
    /// 
    /// Easy
    ///
    /// Given two string arrays word1 and word2, return true if the two arrays 
    /// represent the same string, and false otherwise.
    ///
    /// A string is represented by an array if the array elements concatenated 
    /// in order forms the string.
    ///
    /// Example 1:
    /// Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
    /// Output: true
    /// Explanation:
    /// word1 represents string "ab" + "c" -> "abc"
    /// word2 represents string "a" + "bc" -> "abc"
    /// The strings are the same, so return true.
    ///
    /// Example 2:
    /// Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
    /// Output: false
    ///
    /// Example 3:
    /// Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
    /// Output: true
    ///
    /// Constraints:
    /// 1. 1 <= word1.length, word2.length <= 10^3
    /// 2. 1 <= word1[i].length, word2[i].length <= 10^3
    /// 3. 1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
    /// 4. word1[i] and word2[i] consist of lowercase letters.
    /// </summary>
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2);

    /// <summary>
    /// Leet code #1658. Minimum Operations to Reduce X to Zero
    /// 
    /// Medium
    ///
    /// You are given an integer array nums and an integer x. In one operation, 
    /// you can either remove the leftmost or the rightmost element from the 
    /// array nums and subtract its value from x. Note that this modifies the 
    /// array for future operations.
    ///
    /// Return the minimum number of operations to reduce x to exactly 0 if 
    /// it's possible, otherwise, return -1.
    ///
    /// Example 1:
    /// Input: nums = [1,1,4,2,3], x = 5
    /// Output: 2
    /// Explanation: The optimal solution is to remove the last two elements to 
    /// reduce x to zero.
    ///
    /// Example 2:
    /// Input: nums = [5,6,7,8,9], x = 4
    /// Output: -1
    ///
    /// Example 3:
    /// Input: nums = [3,2,20,1,1,3], x = 10
    /// Output: 5
    /// Explanation: The optimal solution is to remove the last three elements 
    /// and the first two elements (5 operations in total) to reduce x to zero.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^4
    /// 3. 1 <= x <= 10^9
    /// </summary>
    int minOperations(vector<int>& nums, int x);

    /// <summary>
    /// Leet code #1664. Ways to Make a Fair Array
    /// 
    /// Medium
    ///
    /// You are given an integer array nums. You can choose exactly one index 
    /// (0-indexed) and remove the element. Notice that the index of the 
    /// elements may change after the removal.
    ///
    /// For example, if nums = [6,1,7,4,1]:
    ///
    /// Choosing to remove index 1 results in nums = [6,7,4,1].
    /// Choosing to remove index 2 results in nums = [6,1,4,1].
    /// Choosing to remove index 4 results in nums = [6,1,7,4].
    /// An array is fair if the sum of the odd-indexed values equals the sum 
    /// of the even-indexed values.
    ///
    /// Return the number of indices that you could choose such that after 
    /// the removal, nums is fair.
    ///
    /// Example 1:
    /// Input: nums = [2,1,6,4]
    /// Output: 1
    /// Explanation:
    /// Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
    /// Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
    /// Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
    /// Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
    /// There is 1 index that you can remove to make nums fair.
    ///
    /// Example 2:
    /// Input: nums = [1,1,1]
    /// Output: 3
    /// Explanation: You can remove any index and the remaining array is fair.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3]
    /// Output: 0
    /// Explanation: You cannot make a fair array after removing any index.
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^4
    /// </summary>
    int waysToMakeFair(vector<int>& nums);

    /// <summary>
    /// Leet code #1672. Richest Customer Wealth
    /// 
    /// Easy
    /// 
    /// You are given an m x n integer grid accounts where accounts[i][j] 
    /// is the amount of money the ith customer has in the jth bank. Return 
    /// the wealth that the richest customer has.
    ///
    /// A customer's wealth is the amount of money they have in all their 
    /// bank accounts. The richest customer is the customer that has the 
    /// maximum wealth.
    /// 
    /// Example 1:
    ///
    /// Input: accounts = [[1,2,3],[3,2,1]]
    /// Output: 6
    /// Explanation:
    /// 1st customer has wealth = 1 + 2 + 3 = 6
    /// 2nd customer has wealth = 3 + 2 + 1 = 6
    /// Both customers are considered the richest with a wealth of 6 each, 
    /// so return 6.
    ///
    /// Example 2:
    /// Input: accounts = [[1,5],[7,3],[3,5]]
    /// Output: 10
    /// Explanation: 
    /// 1st customer has wealth = 6
    /// 2nd customer has wealth = 10 
    /// 3rd customer has wealth = 8
    /// The 2nd customer is the richest with a wealth of 10.
    ///
    /// Example 3:
    /// Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
    /// Output: 17
    /// Constraints:
    /// 1. m == accounts.length
    /// 2. n == accounts[i].length
    /// 3. 1 <= m, n <= 50
    /// 4. 1 <= accounts[i][j] <= 100
    /// </summary>
    int maximumWealth(vector<vector<int>>& accounts);

    /// <summary>
    /// Leet code #1673. Find the Most Competitive Subsequence
    /// 
    /// Medium
    /// 
    /// Given an integer array nums and a positive integer k, return the most 
    /// competitive subsequence of nums of size k.
    ///
    /// An array's subsequence is a resulting sequence obtained by erasing some 
    /// (possibly zero) elements from the array.
    ///
    /// We define that a subsequence a is more competitive than a subsequence b 
    /// (of the same length) if in the first position where a and b differ, 
    /// subsequence a has a number less than the corresponding number in b. For 
    /// example, [1,3,4] is more competitive than [1,3,5] because the first 
    /// position they differ is at the final number, and 4 is less than 5.
    ///
    /// Example 1:
    /// Input: nums = [3,5,2,6], k = 2
    /// Output: [2,6]
    /// Explanation: Among the set of every possible subsequence: {[3,5], 
    /// [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
    ///
    /// Example 2:
    /// Input: nums = [2,4,3,3,5,4,9,6], k = 4
    /// Output: [2,3,3,4]
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// 3. 1 <= k <= nums.length
    /// </summary>
    vector<int> mostCompetitive(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #1671. Minimum Number of Removals to Make Mountain Array
    /// 
    /// Hard
    /// 
    /// You may recall that an array arr is a mountain array if and only if:
    ///
    /// arr.length >= 3
    /// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such 
    /// that:
    /// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    /// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
    /// Given an integer array nums, return the minimum number of elements to 
    /// remove to make nums a mountain array.
    /// 
    /// Example 1: 
    /// Input: nums = [1,3,1]
    /// Output: 0
    /// Explanation: The array itself is a mountain array so we do not need to 
    /// remove any elements.
    ///
    /// Example 2:
    /// Input: nums = [2,1,1,5,6,2,3,1]
    /// Output: 3
    /// Explanation: One solution is to remove the elements at indices 0, 1, 
    /// and 5, making the array nums = [1,5,6,3,1].
    /// Example 3:
    /// Input: nums = [4,3,2,1,1,2,3,1]
    /// Output: 4
    ///
    /// Example 4:
    /// Input: nums = [1,2,3,4,4,3,2,1]
    /// Output: 1
    /// Constraints:
    /// 1. 3 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. It is guaranteed that you can make a mountain array out of nums.
    /// </summary>
    int minimumMountainRemovals(vector<int>& nums);

    /// <summary>
    /// Leet code #1691. Maximum Height by Stacking Cuboids
    /// 
    /// Hard
    /// 
    /// Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = 
    /// [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and 
    /// place them on each other.
    ///
    /// You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= 
    /// lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions 
    /// by rotating it to put it on another cuboid.
    ///
    /// Return the maximum height of the stacked cuboids.
    /// 
    /// Example 1:
    /// Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
    /// Output: 190
    /// Explanation:
    /// Cuboid 1 is placed on the bottom with the 53x37 side facing down with 
    /// height 95.
    /// Cuboid 0 is placed next with the 45x20 side facing down with height 50.
    /// Cuboid 2 is placed next with the 23x12 side facing down with height 45.
    /// The total height is 95 + 50 + 45 = 190.
    ///
    /// Example 2:
    /// Input: cuboids = [[38,25,45],[76,35,3]]
    /// Output: 76
    /// Explanation:
    /// You can't place any of the cuboids on the other.
    /// We choose cuboid 1 and rotate it so that the 35x3 side is facing down 
    /// and its height is 76.
    ///
    /// Example 3:
    /// Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],
    /// [17,7,11],[17,11,7]]
    /// Output: 102
    /// Explanation:
    /// After rearranging the cuboids, you can see that all cuboids have the 
    /// same dimension.
    /// You can place the 11x7 side down on all cuboids so their heights are 17.
    /// The maximum height of stacked cuboids is 6 * 17 = 102.
    ///
    /// Constraints:
    /// 1. n == cuboids.length
    /// 2. 1 <= n <= 100
    /// 3. 1 <= widthi, lengthi, heighti <= 100
    /// </summary>
    int maxHeight(vector<vector<int>>& cuboids);

    /// <summary>
    /// Leet code #1685. Sum of Absolute Differences in a Sorted Array
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums sorted in non-decreasing order.
    ///
    /// Build and return an integer array result with the same length as nums 
    /// such that result[i] is equal to the summation of absolute differences 
    /// between nums[i] and all the other elements in the array.
    ///
    /// In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 
    /// 0 <= j < nums.length and j != i (0-indexed).
    /// 
    /// Example 1:
    ///
    /// Input: nums = [2,3,5]
    /// Output: [4,3,5]
    /// Explanation: Assuming the arrays are 0-indexed, then
    /// result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
    /// result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
    /// result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
    ///
    /// Example 2:
    /// Input: nums = [1,4,6,8,10]
    /// Output: [24,15,13,15,21]
    /// Constraints:
    /// 1. 2 <= nums.length <= 105
    /// 2. 1 <= nums[i] <= nums[i + 1] <= 104
    /// </summary>
    vector<int> getSumAbsoluteDifferences(vector<int>& nums);

    /// <summary>
    /// Leet code #1695. Maximum Erasure Value
    /// 
    /// Medium
    /// 
    /// You are given an array of positive integers nums and want to erase a 
    /// subarray containing unique elements. The score you get by erasing 
    /// the subarray is equal to the sum of its elements.
    ///
    /// Return the maximum score you can get by erasing exactly one subarray.
    ///
    /// An array b is called to be a subarray of a if it forms a contiguous 
    /// subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] 
    /// for some (l,r).
    /// 
    /// Example 1:
    /// Input: nums = [4,2,4,5,6]
    /// Output: 17
    /// Explanation: The optimal subarray here is [2,4,5,6].
    ///
    /// Example 2:
    /// Input: nums = [5,2,1,2,5,2,1,2,5]
    /// Output: 8
    /// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^4
    /// </summary>
    int maximumUniqueSubarray(vector<int>& nums);

    /// <summary>
    /// Leet code #1700. Number of Students Unable to Eat Lunch
    /// 
    /// Easy
    /// 
    /// The school cafeteria offers circular and square sandwiches at lunch 
    /// break, referred to by numbers 0 and 1 respectively. All students 
    /// stand in a queue. Each student either prefers square or circular 
    /// sandwiches.
    ///
    /// The number of sandwiches in the cafeteria is equal to the number of 
    /// students. The sandwiches are placed in a stack. At each step:
    ///
    /// If the student at the front of the queue prefers the sandwich on the 
    /// top of the stack, they will take it and leave the queue. 
    /// Otherwise, they will leave it and go to the queue's end.
    /// This continues until none of the queue students want to take the top 
    /// sandwich and are thus unable to eat. 
    ///
    /// You are given two integer arrays students and sandwiches where 
    /// sandwiches[i] is the type of the ith sandwich in the stack (i = 0 is 
    /// the top of the stack) and students[j] is the preference of the jth 
    /// student in the initial queue (j = 0 is the front of the queue). 
    /// Return the number of students that are unable to eat.
    ///
    /// Example 1:
    /// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
    /// Output: 0 
    /// Explanation:
    /// - Front student leaves the top sandwich and returns to the end of the 
    ///   line making students = [1,0,0,1].
    /// - Front student leaves the top sandwich and returns to the end of the 
    ///   line making students = [0,0,1,1].
    /// - Front student takes the top sandwich and leaves the line making 
    ///   students = [0,1,1] and sandwiches = [1,0,1].
    /// - Front student leaves the top sandwich and returns to the end of 
    ///   the line making students = [1,1,0].
    /// - Front student takes the top sandwich and leaves the line making 
    ///   students = [1,0] and sandwiches = [0,1].
    /// - Front student leaves the top sandwich and returns to the end of the 
    ///   line making students = [0,1].
    /// - Front student takes the top sandwich and leaves the line making 
    ///   students = [1] and sandwiches = [1].
    /// - Front student takes the top sandwich and leaves the line making 
    ///   students = [] and sandwiches = [].
    /// Hence all students are able to eat.
    ///
    /// Example 2:
    /// Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
    /// Output: 3
    ///
    /// Constraints:
    /// 1. 1 <= students.length, sandwiches.length <= 100
    /// 2. students.length == sandwiches.length
    /// 3. sandwiches[i] is 0 or 1.
    /// 4. students[i] is 0 or 1.
    /// </summary>
    int countStudents(vector<int>& students, vector<int>& sandwiches);

    /// <summary>
    /// Leet code #1701. Average Waiting Time
    /// 
    /// Medium
    /// 
    /// There is a restaurant with a single chef. You are given an array 
    /// customers, where customers[i] = [arrivali, timei]:
    ///
    /// arrivali is the arrival time of the ith customer. The arrival times 
    /// are sorted in non-decreasing order.
    /// timei is the time needed to prepare the order of the ith customer.
    /// When a customer arrives, he gives the chef his order, and the chef 
    /// starts preparing it once he is idle. The customer waits till the chef 
    /// finishes preparing his order. The chef does not prepare food for more 
    /// than one customer at a time. The chef prepares food for customers in 
    /// the order they were given in the input.
    ///
    /// Return the average waiting time of all customers. Solutions within 
    /// 10-5 from the actual answer are considered accepted.
    ///
    /// Example 1:
    /// Input: customers = [[1,2],[2,5],[4,3]]
    /// Output: 5.00000
    /// Explanation:
    /// 1) The first customer arrives at time 1, the chef takes his order and 
    ///   starts preparing it immediately at time 1, and finishes at time 3, 
    ///   so the waiting time of the first customer is 3 - 1 = 2.
    /// 2) The second customer arrives at time 2, the chef takes his order and 
    ///    starts preparing it at time 3, and finishes at time 8, so the 
    ///    waiting time of the second customer is 8 - 2 = 6.
    /// 3) The third customer arrives at time 4, the chef takes his order and 
    ///    starts preparing it at time 8, and finishes at time 11, so the 
    ///    waiting time of the third customer is 11 - 4 = 7.
    /// So the average waiting time = (2 + 6 + 7) / 3 = 5.
    ///
    /// Example 2:
    /// Input: customers = [[5,2],[5,4],[10,3],[20,1]]
    /// Output: 3.25000
    /// Explanation:
    /// 1) The first customer arrives at time 5, the chef takes his order and 
    ///    starts preparing it immediately at time 5, and finishes at time 7, 
    ///    so the waiting time of the first customer is 7 - 5 = 2.
    /// 2) The second customer arrives at time 5, the chef takes his order and 
    ///    starts preparing it at time 7, and finishes at time 11, so the 
    ///    waiting time of the second customer is 11 - 5 = 6.
    /// 3) The third customer arrives at time 10, the chef takes his order and 
    ///    starts preparing it at time 11, and finishes at time 14, so the 
    ///    waiting time of the third customer is 14 - 10 = 4.
    /// 4) The fourth customer arrives at time 20, the chef takes his order 
    ///    and starts preparing it immediately at time 20, and finishes at 
    ///    time 21, so the waiting time of the fourth customer is 21 - 20 = 1.
    /// So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.
    /// 
    /// Constraints:
    /// 1. 1 <= customers.length <= 105
    /// 2. 1 <= arrivali, timei <= 104
    /// 3. arrivali <= arrivali+1
    /// </summary>
    double averageWaitingTime(vector<vector<int>>& customers);

    /// <summary>
    /// Leet code #1703. Minimum Adjacent Swaps for K Consecutive Ones
    /// 
    /// Hard
    /// 
    /// You are given an integer array, nums, and an integer k. nums comprises 
    /// of only 0's and 1's. In one move, you can choose two adjacent indices 
    /// and swap their values.
    ///
    /// Return the minimum number of moves required so that nums has k 
    /// consecutive 1's.
    ///
    /// Example 1:
    /// Input: nums = [1,0,0,1,0,1], k = 2
    /// Output: 1
    /// Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 
    /// 2 consecutive 1's.
    ///
    /// Example 2:
    /// Input: nums = [1,0,0,0,0,0,1,1], k = 3
    /// Output: 5
    /// Explanation: In 5 moves, the leftmost 1 can be shifted right until 
    /// nums = [0,0,0,0,0,1,1,1].
    ///
    /// Example 3:
    /// Input: nums = [1,1,0,1], k = 2
    /// Output: 0
    /// Explanation: nums already has 2 consecutive 1's.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. nums[i] is 0 or 1.
    /// 3. 1 <= k <= sum(nums)
    /// </summary>
    int minMoves(vector<int>& nums, int k);

    /// <summary>
    /// Leet code #1706. Where Will the Ball Fall
    /// 
    /// Medium
    /// 
    /// You have a 2-D grid of size m x n representing a box, and you have n 
    /// balls. The box is open on the top and bottom sides.
    ///
    /// Each cell in the box has a diagonal board spanning two corners of the 
    /// cell that can redirect a ball to the right or to the left.
    ///
    /// A board that redirects the ball to the right spans the top-left corner 
    /// to the bottom-right corner and is represented in the grid as 1.
    /// A board that redirects the ball to the left spans the top-right corner 
    /// to the bottom-left corner and is represented in the grid as -1.
    /// We drop one ball at the top of each column of the box. Each ball can 
    /// get stuck in the box or fall out of the bottom. A ball gets stuck if 
    /// it hits a "V" shaped pattern between two boards or if a board redirects 
    /// the ball into either wall of the box.
    ///
    /// Return an array answer of size n where answer[i] is the column that the 
    /// ball falls out of at the bottom after dropping the ball from the ith 
    /// column at the top, or -1 if the ball gets stuck in the box.
    ///
    /// Example 1:
    /// Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],
    /// [-1,-1,-1,-1,-1]]
    /// Output: [1,-1,-1,-1,-1]
    /// Explanation: This example is shown in the photo.
    /// Ball b0 is dropped at column 0 and falls out of the box at column 1.
    /// Ball b1 is dropped at column 1 and will get stuck in the box between 
    /// column 2 and 3 and row 1.
    /// Ball b2 is dropped at column 2 and will get stuck on the box between 
    /// column 2 and 3 and row 0.
    /// Ball b3 is dropped at column 3 and will get stuck on the box between 
    /// column 2 and 3 and row 0.
    /// Ball b4 is dropped at column 4 and will get stuck on the box between 
    /// column 2 and 3 and row 1.
    ///
    /// Example 2:
    /// Input: grid = [[-1]]
    /// Output: [-1]
    /// Explanation: The ball gets stuck against the left wall.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 100
    /// 4. grid[i][j] is 1 or -1.
    /// </summary>
    vector<int> findBall(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1712. Ways to Split Array Into Three Subarrays
    /// 
    /// Medium
    /// 
    /// A split of an integer array is good if:
    /// The array is split into three non-empty contiguous subarrays - named 
    /// left, mid, right respectively from left to right.
    /// The sum of the elements in left is less than or equal to the sum of 
    /// the elements in mid, and the sum of the elements in mid is less than 
    /// or equal to the sum of the elements in right.
    /// Given nums, an array of non-negative integers, return the number of 
    /// good ways to split nums. As the number may be too large, return it 
    /// modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: nums = [1,1,1]
    /// Output: 1
    /// Explanation: The only good way to split nums is [1] [1] [1].
    ///
    /// Example 2:
    /// Input: nums = [1,2,2,2,5,0]
    /// Output: 3
    /// Explanation: There are three good ways of splitting nums:
    /// [1] [2] [2,2,5,0]
    /// [1] [2,2] [2,5,0]
    /// [1,2] [2,2] [5,0]
    ///
    /// Example 3:
    /// Input: nums = [3,2,1]
    /// Output: 0
    /// Explanation: There is no good way to split nums.
    /// Constraints:
    /// 1. 3 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^4
    /// </summary>
    int waysToSplit(vector<int>& nums);

    /// <summary>
    /// Leet code 1720. Decode XORed Array
    /// 
    /// Easy
    /// 
    /// There is a hidden integer array arr that consists of n non-negative 
    /// integers.
    ///
    /// It was encoded into another integer array encoded of length n - 1, 
    /// such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if 
    /// arr = [1,0,2,1], then encoded = [1,2,3].
    ///
    /// You are given the encoded array. You are also given an integer first, 
    /// that is the first element of arr, i.e. arr[0].
    /// 
    /// Return the original array arr. It can be proved that the answer exists 
    /// and is unique.
    ///
    /// Example 1:
    /// Input: encoded = [1,2,3], first = 1
    /// Output: [1,0,2,1]
    /// Explanation: If arr = [1,0,2,1], then first = 1 and encoded = 
    /// [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
    ///
    /// Example 2:
    /// Input: encoded = [6,2,7,3], first = 4
    /// Output: [4,2,0,7,4]
    ///
    /// Constraints:
    /// 1. 2 <= n <= 10^4
    /// 2. encoded.length == n - 1
    /// 3. 0 <= encoded[i] <= 10^5
    /// 4. 0 <= first <= 10^5
    /// </summary>
    vector<int> decode(vector<int>& encoded, int first);

    /// <summary>
    /// Leet code 1713. Minimum Operations to Make a Subsequence
    /// 
    /// Hard
    /// 
    /// You are given an array target that consists of distinct integers and 
    /// another integer array arr that can have duplicates.
    ///
    /// In one operation, you can insert any integer at any position in arr. 
    /// For example, if arr = [1,4,1,2], you can add 3 in the middle and make 
    /// it [1,4,3,1,2]. Note that you can insert the integer at the very 
    /// beginning or end of the array.
    ///
    /// Return the minimum number of operations needed to make target a 
    /// subsequence of arr.
    /// 
    /// A subsequence of an array is a new array generated from the original 
    /// array by deleting some elements (possibly none) without changing the 
    /// remaining elements' relative order. For example, [2,7,4] is a 
    //// subsequence of [4,2,3,7,2,1,4] (the underlined elements), while 
    /// [2,4,2] is not.
    ///
    /// Example 1:
    /// Input: target = [5,1,3], arr = [9,4,2,3,4]
    /// Output: 2
    /// Explanation: You can add 5 and 1 in such a way that makes 
    /// arr = [5,9,4,1,2,3,4], then target will be a subsequence of arr.
    ///
    /// Example 2:
    /// Input: target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
    /// Output: 3
    /// 
    /// Constraints:
    /// 1. 1 <= target.length, arr.length <= 10^5
    /// 2. 1 <= target[i], arr[i] <= 10^9
    /// 3. target contains no duplicates.
    /// </summary>
    int minOperations(vector<int>& target, vector<int>& arr);

    /// <summary>
    /// Leet code 1725. Number Of Rectangles That Can Form The Largest Square
    /// 
    /// Easy
    /// 
    /// You are given an array rectangles where rectangles[i] = [li, wi] 
    /// represents the ith rectangle of length li and width wi.
    ///
    /// You can cut the ith rectangle to form a square with a side length 
    /// of k if both k <= li and k <= wi. For example, if you have a 
    /// rectangle [4,6], you can cut it to get a square with a side length 
    /// of at most 4.
    ///
    /// Let maxLen be the side length of the largest square you can obtain 
    /// from any of the given rectangles.
    ///
    /// Return the number of rectangles that can make a square with a side 
    /// length of maxLen.
    ///
    /// Example 1:
    /// Input: rectangles = [[5,8],[3,9],[5,12],[16,5]]
    /// Output: 3
    /// Explanation: The largest squares you can get from each rectangle 
    /// are of lengths [5,3,5,5].
    /// The largest possible square is of length 5, and you can get it 
    /// out of 3 rectangles.
    ///
    /// Example 2:
    /// Input: rectangles = [[2,3],[3,7],[4,3],[3,7]]
    /// Output: 3
    ///
    /// Constraints:
    /// 1. 1 <= rectangles.length <= 1000
    /// 2. rectangles[i].length == 2
    /// 3. 1 <= li, wi <= 109
    /// 4. li != wi
    /// </summary>
    int countGoodRectangles(vector<vector<int>>& rectangles);

    /// <summary>
    /// Leet code 1726. Tuple with Same Product
    /// 
    /// Medium
    /// 
    /// Given an array nums of distinct positive integers, return the number 
    /// of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d 
    /// are elements of nums, and a != b != c != d.
    /// Example 1:
    /// Input: nums = [2,3,4,6]
    /// Output: 8
    /// Explanation: There are 8 valid tuples:
    /// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
    /// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
    ///
    /// Example 2:
    /// Input: nums = [1,2,4,5,10]
    /// Output: 16
    /// Explanation: There are 16 valids tuples:
    /// (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
    /// (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
    /// (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
    /// (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
    ///
    /// Example 3:
    /// Input: nums = [2,3,4,6,8,12]
    /// Output: 40
    ///
    /// Example 4:
    /// Input: nums = [2,3,5,7]
    /// Output: 0
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 10^4
    /// 3. All elements in nums are distinct.
    /// </summary>
    int tupleSameProduct(vector<int>& nums);

    /// <summary>
    /// Leet code 1727. Largest Submatrix With Rearrangements
    /// 
    /// Medium
    /// 
    /// You are given a binary matrix matrix of size m x n, and you are 
    /// allowed to rearrange the columns of the matrix in any order.
    ///
    /// Return the area of the largest submatrix within matrix where every 
    /// element of the submatrix is 1 after reordering the columns optimally.
    ///
    /// Example 1:
    /// Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
    /// Output: 4
    /// Explanation: You can rearrange the columns as shown above.
    /// The largest submatrix of 1s, in bold, has an area of 4.
    ///
    /// Example 2:
    /// Input: matrix = [[1,0,1,0,1]]
    /// Output: 3
    /// Explanation: You can rearrange the columns as shown above.
    /// The largest submatrix of 1s, in bold, has an area of 3.
    ///
    /// Example 3:
    /// Input: matrix = [[1,1,0],[1,0,1]]
    /// Output: 2
    /// Explanation: Notice that you must rearrange entire columns, and there 
    /// is no way to make a submatrix of 1s larger than an area of 2.
    ///
    /// Example 4:
    /// Input: matrix = [[0,0],[0,0]]
    /// Output: 0
    /// Explanation: As there are no 1s, no submatrix of 1s can be formed 
    /// and the area is 0.
    /// 
    /// Constraints:
    /// 1. m == matrix.length
    /// 2. n == matrix[i].length
    /// 3. 1 <= m * n <= 10^5
    /// 4. matrix[i][j] is 0 or 1.
    /// </summary>
    int largestSubmatrix(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet code 1708. Largest Subarray Length K
    /// 
    /// Easy
    /// 
    /// An array A is larger than some array B if for the first index i 
    /// where A[i] != B[i], A[i] > B[i].
    ///
    /// For example, consider 0-indexing:
    ///
    /// [1,3,2,4] > [1,2,2,4], since at index 1, 3 > 2.
    /// [1,4,4,4] < [2,1,1,1], since at index 0, 1 < 2.
    /// A subarray is a contiguous subsequence of the array.
    ///
    /// Given an integer array nums of distinct integers, return the largest 
    /// subarray of nums of length k.
    /// 
    /// Example 1:
    /// Input: nums = [1,4,5,2,3], k = 3
    /// Output: [5,2,3]
    /// Explanation: The subarrays of size 3 are: [1,4,5], [4,5,2], 
    /// and [5,2,3].
    /// Of these, [5,2,3] is the largest.
    ///
    /// Example 2: 
    /// Input: nums = [1,4,5,2,3], k = 4
    /// Output: [4,5,2,3]
    /// Explanation: The subarrays of size 4 are: [1,4,5,2], and [4,5,2,3].
    /// Of these, [4,5,2,3] is the largest.
    ///
    /// Example 3:
    /// Input: nums = [1,4,5,2,3], k = 1
    /// Output: [5]
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. All the integers of nums are unique.
    /// Follow up: What if the integers in nums are not distinct?
    /// </summary>
    vector<int> largestSubarray(vector<int>& nums, int k);

    /// <summary>
    /// Leet code 1732. Find the Highest Altitude
    /// 
    /// Easy
    /// 
    /// There is a biker going on a road trip. The road trip consists of 
    /// n + 1 points at different altitudes. The biker starts his trip on 
    /// point 0 with altitude equal 0.
    ///
    /// You are given an integer array gain of length n where gain[i] is 
    /// the net gain in altitude between points i and i + 1 for all 
    /// (0 <= i < n). Return the highest altitude of a point.
    /// 
    /// Example 1:
    /// Input: gain = [-5,1,5,0,-7]
    /// Output: 1
    /// Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
    ///
    /// Example 2:
    /// Input: gain = [-4,-3,-2,-1,4,3,2]
    /// Output: 0
    /// Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. 
    /// The highest is 0.
    /// 
    /// Constraints:
    /// 1. n == gain.length
    /// 2. 1 <= n <= 100
    /// 3. -100 <= gain[i] <= 100
    /// </summary>
    int largestAltitude(vector<int>& gain);

    /// <summary>
    /// Leet code 1738. Find Kth Largest XOR Coordinate Value 
    /// 
    /// Medium
    /// 
    /// You are given a 2D matrix of size m x n, consisting of non-negative 
    /// integers. You are also given an integer k.
    ///
    /// The value of coordinate (a, b) of the matrix is the XOR of all 
    /// matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
    ///
    /// Find the kth largest value (1-indexed) of all the coordinates of 
    /// matrix.
    /// 
    /// Example 1:
    /// Input: matrix = [[5,2],[1,6]], k = 1
    /// Output: 7
    /// Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is 
    /// the largest value.
    ///
    /// Example 2:
    /// Input: matrix = [[5,2],[1,6]], k = 2
    /// Output: 5
    /// Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd 
    /// largest value.
    ///
    /// Example 3:
    /// Input: matrix = [[5,2],[1,6]], k = 3
    /// Output: 4
    /// Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is 
    /// the 3rd largest value.
    ///
    /// Example 4:
    /// Input: matrix = [[5,2],[1,6]], k = 4
    /// Output: 0
    /// Explanation: The value of coordinate (1,1) is 5 XOR 2 XOR 1 XOR 6 = 0, 
    /// which is the 4th largest value.
    /// 
    /// Constraints:
    /// 1. m == matrix.length
    /// 2. n == matrix[i].length
    /// 3. 1 <= m, n <= 1000
    /// 4. 0 <= matrix[i][j] <= 10^6
    /// 5. 1 <= k <= m * n
    /// </summary>
    int kthLargestValue(vector<vector<int>>& matrix, int k);

    /// <summary>
    /// Leet code 1744. Can You Eat Your Favorite Candy on Your Favorite Day?
    /// 
    /// Medium
    /// 
    /// You are given a (0-indexed) array of positive integers candiesCount 
    /// where candiesCount[i] represents the number of candies of the ith type 
    /// you have. You are also given a 2D array queries where queries[i] = 
    /// [favoriteTypei, favoriteDayi, dailyCapi].
    ///
    /// You play a game with the following rules:
    ///
    /// You start eating candies on day 0.
    /// You cannot eat any candy of type i unless you have eaten all candies 
    /// of type i - 1.
    /// You must eat at least one candy per day until you have eaten all the 
    /// candies.
    /// Construct a boolean array answer such that answer.length == 
    /// queries.length and answer[i] is true if you can eat a candy of type 
    /// favoriteTypei on day favoriteDayi without eating more than dailyCapi 
    /// candies on any day, and false otherwise. Note that you can eat 
    /// different types of candy on the same day, provided that you follow 
    /// rule 2.
    ///
    /// Return the constructed array answer.
    ///
    /// Example 1:
    /// Input: candiesCount = [7,4,5,3,8], 
    /// queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
    /// Output: [true,false,true]
    /// Explanation:
    /// 1- If you eat 2 candies (type 0) on day 0 and 2 candies (type 0) on 
    ///    day 1, you will eat a candy of type 0 on day 2.
    /// 2- You can eat at most 4 candies each day.
    /// If you eat 4 candies every day, you will eat 4 candies (type 0) on 
    /// day 0 and 4 candies (type 0 and type 1) on day 1.
    /// On day 2, you can only eat 4 candies (type 1 and type 2), so you 
    ///  cannot eat a candy of type 4 on day 2.
    /// 3- If you eat 1 candy each day, you will eat a candy of type 2 on 
    /// day 13.
    ///
    /// Example 2:
    /// Input: candiesCount = [5,2,6,4,1], queries = [[3,1,2],[4,10,3],
    /// [3,10,100],[4,100,30],[1,3,1]]
    /// Output: [false,true,true,false,false]
    /// 
    /// Constraints:
    /// 1. 1 <= candiesCount.length <= 10^5
    /// 2. 1 <= candiesCount[i] <= 105
    /// 3. 1 <= queries.length <= 105
    /// 4. queries[i].length == 3
    /// 5. 0 <= favoriteTypei < candiesCount.length
    /// 6. 0 <= favoriteDayi <= 10^9
    /// 7. 1 <= dailyCapi <= 10^9
    /// </summary>
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code 1749. Maximum Absolute Sum of Any Subarray
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums. The absolute sum of a subarray 
    /// [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + 
    /// numsr-1 + numsr).
    ///
    /// Return the maximum absolute sum of any (possibly empty) subarray of 
    /// nums.
    ///
    /// Note that abs(x) is defined as follows:
    ///
    /// If x is a negative integer, then abs(x) = -x.
    /// If x is a non-negative integer, then abs(x) = x.
    ///
    /// Example 1:
    /// Input: nums = [1,-3,2,3,-4]
    /// Output: 5
    /// Explanation: The subarray [2,3] has absolute sum = abs(2+3) = 
    /// abs(5) = 5.
    ///
    /// Example 2:
    /// Input: nums = [2,-5,1,-4,3,-2]
    /// Output: 8
    /// Explanation: The subarray [-5,1,-4] has absolute sum = 
    /// abs(-5+1-4) = abs(-8) = 8.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^4 <= nums[i] <= 10^4
    /// </summary>
    int maxAbsoluteSum(vector<int>& nums);

    /// <summary>
    /// Leet code 1769. Minimum Number of Operations to Move All Balls to 
    ///                 Each Box
    /// 
    /// Medium
    /// 
    /// You have n boxes. You are given a binary string boxes of length n, 
    /// where boxes[i] is '0' if the ith box is empty, and '1' if it contains 
    /// one ball.
    ///
    /// In one operation, you can move one ball from a box to an adjacent box. 
    /// Box i is adjacent to box j if abs(i - j) == 1. Note that after doing 
    /// so, there may be more than one ball in some boxes.
    ///
    /// Return an array answer of size n, where answer[i] is the minimum number 
    /// of operations needed to move all the balls to the ith box.
    ///
    /// Each answer[i] is calculated considering the initial state of the boxes.
    /// 
    /// Example 1:
    ///
    /// Input: boxes = "110"
    /// Output: [1,1,3]
    /// Explanation: The answer for each box is as follows:
    /// 1) First box: you will have to move one ball from the second box to 
    ///    the first box in one operation.
    /// 2) Second box: you will have to move one ball from the first box to 
    ///    the second box in one operation.
    /// 3) Third box: you will have to move one ball from the first box to the 
    ///    third box in two operations, and move one ball from the second box 
    ///    to the third box in one operation.
    ///
    /// Example 2:
    /// Input: boxes = "001011"
    /// Output: [11,8,5,4,3,4]
    /// Constraints:
    /// 1. n == boxes.length
    /// 2. 1 <= n <= 2000
    /// 3. boxes[i] is either '0' or '1'.
    /// </summary>
    vector<int> minOperations(string boxes);

    /// <summary>
    /// Leet code 1759. Count Number of Homogenous Substrings
    /// 
    /// Medium
    /// 
    /// Given a string s, return the number of homogenous substrings of s. 
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// A string is homogenous if all the characters of the string are the 
    /// same.
    ///
    /// A substring is a contiguous sequence of characters within a string.
    /// 
    /// Example 1:
    /// Input: s = "abbcccaa"
    /// Output: 13
    /// Explanation: The homogenous substrings are listed as below:
    /// "a"   appears 3 times.
    /// "aa"  appears 1 time.
    /// "b"   appears 2 times.
    /// "bb"  appears 1 time.
    /// "c"   appears 3 times.
    /// "cc"  appears 2 times.
    /// "ccc" appears 1 time.
    /// 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
    ///
    /// Example 2:
    /// Input: s = "xy"
    /// Output: 2
    /// Explanation: The homogenous substrings are "x" and "y".
    /// Example 3:
    /// Input: s = "zzzzz"
    /// Output: 15
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. s consists of lowercase letters.
    /// </summary>
    int countHomogenous(string s);

    /// <summary>
    /// Leet code 1764. Form Array by Concatenating Subarrays of Another Array
    /// 
    /// Medium
    /// 
    /// You are given a 2D integer array groups of length n. You are also 
    /// given an integer array nums.
    ///
    /// You are asked if you can choose n disjoint subarrays from the array 
    /// nums such that the ith subarray is equal to groups[i] (0-indexed), 
    /// and if i > 0, the (i-1)th subarray appears before the ith subarray 
    /// in nums (i.e. the subarrays must be in the same order as groups).
    ///
    /// Return true if you can do this task, and false otherwise.
    /// Note that the subarrays are disjoint if and only if there is no 
    /// index k such that nums[k] belongs to more than one subarray. A 
    /// subarray is a contiguous sequence of elements within an array.
    ///
    /// Example 1:
    /// Input: groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
    /// Output: true
    /// Explanation: You can choose the 0th subarray 
    /// as [1,-1,0,1,-1,-1,3,-2,0] and the 1st one as [1,-1,0,1,-1,-1,3,-2,0].
    /// These subarrays are disjoint as they share no common nums[k] element.
    ///
    /// Example 2:
    /// Input: groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
    /// Output: false
    /// Explanation: Note that choosing the subarrays [1,2,3,4,10,-2] 
    /// and [1,2,3,4,10,-2] is incorrect because they are not in the same 
    /// order as in groups.
    /// [10,-2] must come before [1,2,3,4].
    ///
    /// Example 3:
    /// Input: groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
    /// Output: false
    /// Explanation: Note that choosing the subarrays [7,7,1,2,3,4,7,7] 
    /// and [7,7,1,2,3,4,7,7] is invalid because they are not disjoint.
    /// They share a common elements nums[4] (0-indexed).
    ///
    /// Constraints:
    /// 1. groups.length == n
    /// 2. 1 <= n <= 10^3
    /// 3. 1 <= groups[i].length, sum(groups[i].length) <= 10^3
    /// 4. 1 <= nums.length <= 10^3
    /// 5. -10^7 <= groups[i][j], nums[k] <= 10^7
    /// </summary>
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums);

    /// <summary>
    /// Leet code 1779. Find Nearest Point That Has the Same X or Y Coordinate
    /// 
    /// Easy
    /// 
    /// You are given two integers, x and y, which represent your current 
    /// location on a Cartesian grid: (x, y). You are also given an array 
    /// points where each points[i] = [ai, bi] represents that a point exists 
    /// at (ai, bi). A point is valid if it shares the same x-coordinate or 
    /// the same y-coordinate as your location.
    ///
    /// Return the index (0-indexed) of the valid point with the smallest 
    /// Manhattan distance from your current location. If there are multiple, 
    /// return the valid point with the smallest index. If there are no valid 
    /// points, return -1.
    ///
    /// The Manhattan distance between two points (x1, y1) and (x2, y2) is 
    /// abs(x1 - x2) + abs(y1 - y2).
    ///
    /// Example 1:
    /// Input: x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
    /// Output: 2
    /// Explanation: Of all the points, only [3,1], [2,4] and [4,4] are valid. 
    /// Of the valid points, [2,4] and [4,4] have the smallest Manhattan 
    /// distance from your current location, with a distance of 1. [2,4] has 
    /// the smallest index, so return 2.
    ///
    /// Example 2:
    /// Input: x = 3, y = 4, points = [[3,4]]
    /// Output: 0
    /// Explanation: The answer is allowed to be on the same location as your current location.
    ///
    /// Example 3:
    /// Input: x = 3, y = 4, points = [[2,3]]
    /// Output: -1
    /// Explanation: There are no valid points.
    ///
    /// Constraints:
    /// 1. 1 <= points.length <= 10^4
    /// 2. points[i].length == 2
    /// 3. 1 <= x, y, ai, bi <= 10^4
    /// </summary>
    int nearestValidPoint(int x, int y, vector<vector<int>>& points);

    /// <summary>
    /// Leet code 1793. Maximum Score of a Good Subarray
    /// 
    /// Hard
    /// 
    /// You are given an array of integers nums (0-indexed) and an integer k.
    /// 
    /// The score of a subarray (i, j) is defined as min(nums[i], 
    /// nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray 
    /// where i <= k <= j.
    ///
    /// Return the maximum possible score of a good subarray.
    ///
    /// Example 1:
    /// Input: nums = [1,4,3,7,4,5], k = 3
    /// Output: 15
    /// Explanation: The optimal subarray is (1, 5) with a score of 
    /// min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
    ///
    /// Example 2:
    /// Input: nums = [5,5,4,5,4,1,1,1], k = 0
    /// Output: 20
    /// Explanation: The optimal subarray is (0, 4) with a score of 
    /// min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 2 * 10^4
    /// 3. 0 <= k < nums.length
    /// </summary>
    int maximumScore(vector<int>& nums, int k);

    /// <summary>
    /// Leet code 1800. Maximum Ascending Subarray Sum
    /// 
    /// Easy
    /// 
    /// Given an array of positive integers nums, return the maximum possible 
    /// sum of an ascending subarray in nums.
    ///
    /// A subarray is defined as a contiguous sequence of numbers in an array.
    ///
    /// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for 
    /// all i where l <= i < r, numsi < numsi+1. Note that a subarray of 
    /// size 1 is ascending.
    ///
    /// Example 1:
    /// Input: nums = [10,20,30,5,10,50]
    /// Output: 65
    /// Explanation: [5,10,50] is the ascending subarray with the maximum 
    /// sum of 65.
    ///
    /// Example 2:
    /// Input: nums = [10,20,30,40,50]
    /// Output: 150
    /// Explanation: [10,20,30,40,50] is the ascending subarray with the 
    /// maximum sum of 150.
    ///
    /// Example 3:
    /// Input: nums = [12,17,15,13,10,11,12]
    /// Output: 33
    /// Explanation: [10,11,12] is the ascending subarray with the maximum 
    /// sum of 33.
    ///
    /// Example 4:
    /// Input: nums = [100,10,1]
    /// Output: 100
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// </summary>
    int maxAscendingSum(vector<int>& nums);

    /// <summary>
    /// Leet code 1806. Minimum Number of Operations to Reinitialize a 
    ///                 Permutation
    /// 
    /// Medium
    /// 
    /// You are given an even integer n. You initially have a permutation 
    /// perm of size n where perm[i] == i (0-indexed).
    /// In one operation, you will create a new array arr, and for each i:
    /// If i % 2 == 0, then arr[i] = perm[i / 2].
    /// If i % 2 == 1, then arr[i] = perm[n / 2 + (i - 1) / 2].
    /// You will then assign arr to perm.
    ///
    /// Return the minimum non-zero number of operations you need to perform 
    /// on perm to return the permutation to its initial value.
    ///
    /// Example 1:
    /// Input: n = 2
    /// Output: 1
    /// Explanation: perm = [0,1] initially.
    /// After the 1st operation, perm = [0,1]
    /// So it takes only 1 operation.
    ///
    /// Example 2:
    /// Input: n = 4
    /// Output: 2
    /// Explanation: perm = [0,1,2,3] initially.
    /// After the 1st operation, perm = [0,2,1,3]
    /// After the 2nd operation, perm = [0,1,2,3]
    /// So it takes only 2 operations.
    ///
    /// Example 3:
    /// Input: n = 6
    /// Output: 4
    ///
    /// Constraints:
    /// 1. 2 <= n <= 1000
    /// 2. n is even.
    /// </summary>
    int reinitializePermutation(int n);

    /// <summary>
    /// Leet code 1818. Minimum Absolute Sum Difference
    /// 
    /// Medium
    /// 
    /// You are given two positive integer arrays nums1 and nums2, both of 
    /// length n.
    ///
    /// The absolute sum difference of arrays nums1 and nums2 is defined as 
    /// the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).
    ///
    /// You can replace at most one element of nums1 with any other element 
    /// in nums1 to minimize the absolute sum difference.
    ///
    /// Return the minimum absolute sum difference after replacing at most 
    /// one element in the array nums1. Since the answer may be large, return 
    /// it modulo 10^9 + 7.
    ///
    /// |x| is defined as:
    ///
    /// x if x >= 0, or
    /// -x if x < 0.
    /// 
    /// Example 1:
    /// Input: nums1 = [1,7,5], nums2 = [2,3,5]
    /// Output: 3
    /// Explanation: There are two possible optimal solutions:
    /// - Replace the second element with the first: [1,7,5] => [1,1,5], or
    /// - Replace the second element with the third: [1,7,5] => [1,5,5].
    /// Both will yield an absolute sum difference of 
    /// |1-2| + (|1-3| or |5-3|) + |5-5| = 3.
    ///
    /// Example 2:
    /// Input: nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
    /// Output: 0
    /// Explanation: nums1 is equal to nums2 so no replacement is needed. 
    /// This will result in an 
    /// absolute sum difference of 0.
    ///
    /// Example 3:
    /// Input: nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
    /// Output: 20
    /// Explanation: Replace the first element with the second: 
    /// [1,10,4,4,2,7] => [10,10,4,4,2,7].
    /// This yields an absolute sum difference of 
    /// |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20
    ///
    /// Constraints:
    /// 1. n == nums1.length
    /// 2. n == nums2.length
    /// 3. 1 <= n <= 10^5
    /// 4. 1 <= nums1[i], nums2[i] <= 10^5
    /// </summary>
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet code 1822. Sign of the Product of an Array
    /// 
    /// Easy
    /// 
    /// There is a function signFunc(x) that returns:
    ///
    /// 1 if x is positive.
    /// -1 if x is negative.
    /// 0 if x is equal to 0.
    /// You are given an integer array nums. Let product be the product of 
    /// all values in the array nums.
    ///
    /// Return signFunc(product).
    /// 
    /// Example 1:
    /// Input: nums = [-1,-2,-3,-4,3,2,1]
    /// Output: 1
    /// Explanation: The product of all values in the array is 144, and 
    /// signFunc(144) = 1
    ///
    /// Example 2:
    /// Input: nums = [1,5,0,2,-3]
    /// Output: 0
    /// Explanation: The product of all values in the array is 0, and 
    /// signFunc(0) = 0
    ///
    /// Example 3:
    /// Input: nums = [-1,1,-1,1,-1]
    /// Output: -1
    /// Explanation: The product of all values in the array is -1, and 
    /// signFunc(-1) = -1
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. -100 <= nums[i] <= 100
    /// </summary>
    int arraySign(vector<int>& nums);

    /// <summary>
    /// Leet code 1823. Find the Winner of the Circular Game
    /// 
    /// Medium
    /// 
    /// There are n friends that are playing a game. The friends are sitting 
    /// in a circle and are numbered from 1 to n in clockwise order. More 
    /// formally, moving clockwise from the ith friend brings you to the 
    /// (i+1)th friend for 1 <= i < n, and moving clockwise from the nth 
    /// friend brings you to the 1st friend.
    ///
    /// The rules of the game are as follows:
    /// 
    /// Start at the 1st friend.
    /// Count the next k friends in the clockwise direction including the 
    /// friend you started at. The counting wraps around the circle and may 
    /// count some friends more than once.
    /// The last friend you counted leaves the circle and loses the game.
    /// If there is still more than one friend in the circle, go back to 
    /// step 2 starting from the friend immediately clockwise of the friend 
    /// who just lost and repeat.
    /// Else, the last friend in the circle wins the game.
    /// Given the number of friends, n, and an integer k, return the winner 
    /// of the game.
    /// 
    /// Example 1:
    /// Input: n = 5, k = 2
    /// Output: 3
    /// Explanation: Here are the steps of the game:
    /// 1) Start at friend 1.
    /// 2) Count 2 friends clockwise, which are friends 1 and 2.
    /// 3) Friend 2 leaves the circle. Next start is friend 3.
    /// 4) Count 2 friends clockwise, which are friends 3 and 4.
    /// 5) Friend 4 leaves the circle. Next start is friend 5.
    /// 6) Count 2 friends clockwise, which are friends 5 and 1.
    /// 7) Friend 1 leaves the circle. Next start is friend 3.
    /// 8) Count 2 friends clockwise, which are friends 3 and 5.
    /// 9) Friend 5 leaves the circle. Only friend 3 is left, so they are the 
    ///    winner.
    ///
    /// Example 2:
    /// Input: n = 6, k = 5
    /// Output: 1
    /// Explanation: The friends leave in this order: 5, 4, 6, 2, 3. 
    /// The winner is friend 1.
    ///
    /// Constraints:
    /// 1. 1 <= k <= n <= 500
    /// </summary>
    int findTheWinner(int n, int k);

    /// <summary>
    /// Leet code 1762. Buildings With an Ocean View
    /// 
    /// Medium
    /// 
    /// There are n buildings in a line. You are given an integer array 
    /// heights of size n that represents the heights of the buildings in the 
    /// line.
    ///
    /// The ocean is to the right of the buildings. A building has an ocean 
    /// view if the building can see the ocean without obstructions. Formally, 
    /// a building has an ocean view if all the buildings to its right have a 
    /// smaller height.
    ///
    /// Return a list of indices (0-indexed) of buildings that have an ocean 
    /// view, sorted in increasing order.
    /// 
    /// Example 1:
    /// Input: heights = [4,2,3,1]
    /// Output: [0,2,3]
    /// Explanation: Building 1 (0-indexed) does not have an ocean view 
    /// because building 2 is taller.
    ///
    /// Example 2:
    /// Input: heights = [4,3,2,1]
    /// Output: [0,1,2,3]
    /// Explanation: All the buildings have an ocean view.
    ///
    /// Example 3:
    /// Input: heights = [1,3,2,4]
    /// Output: [3]
    /// Explanation: Only building 3 has an ocean view.
    ///
    /// Example 4:
    /// Input: heights = [2,2,2,2]
    /// Output: [3]
    /// Explanation: Buildings cannot see the ocean if there are 
    /// buildings of the same height to its right.
    /// 
    /// Constraints:
    /// 1. 1 <= heights.length <= 10^5
    /// 2. 1 <= heights[i] <= 10^9
    /// </summary>
    vector<int> findBuildings(vector<int>& heights);

    /// <summary>
    /// Leet code 1827. Minimum Operations to Make the Array Increasing
    /// 
    /// Easy
    /// 
    /// You are given an integer array nums (0-indexed). In one operation, 
    /// you can choose an element of the array and increment it by 1.
    ///
    /// For example, if nums = [1,2,3], you can choose to increment nums[1] 
    /// to make nums = [1,3,3].
    /// Return the minimum number of operations needed to make nums 
    /// strictly increasing.
    ///
    /// An array nums is strictly increasing if nums[i] < nums[i+1] for 
    /// all 0 <= i < nums.length - 1. An array of length 1 is trivially 
    /// strictly increasing.
    /// Example 1:
    ///
    /// Input: nums = [1,1,1]
    /// Output: 3
    /// Explanation: You can do the following operations:
    /// 1) Increment nums[2], so nums becomes [1,1,2].
    /// 2) Increment nums[1], so nums becomes [1,2,2].
    /// 3) Increment nums[2], so nums becomes [1,2,3].
    ///
    /// Example 2:
    /// Input: nums = [1,5,2,4,1]
    /// Output: 14
    ///
    /// Example 3:
    /// Input: nums = [8]
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 5000
    /// 2. 1 <= nums[i] <= 10^4
    /// </summary>
    int minOperations(vector<int>& nums);

    /// <summary>
    /// Leet code 1826. Faulty Sensor
    /// 
    /// Easy
    /// 
    /// An experiment is being conducted in a lab. To ensure accuracy, there 
    /// are two sensors collecting data simultaneously. You are given 2 arrays 
    /// sensor1 and sensor2, where sensor1[i] and sensor2[i] are the ith data 
    /// points collected by the two sensors.
    ///
    /// However, this type of sensor has a chance of being defective, which 
    /// causes exactly one data point to be dropped. After the data is dropped, 
    /// all the data points to the right of the dropped data are shifted one 
    /// place to the left, and the last data point is replaced with some 
    /// random value. It is guaranteed that this random value will not be equal 
    /// to the dropped value.
    ///
    /// For example, if the correct data is [1,2,3,4,5] and 3 is dropped, the 
    /// sensor could return [1,2,4,5,7] (the last position can be any value, 
    /// not just 7).
    /// We know that there is a defect in at most one of the sensors. Return 
    /// the sensor number (1 or 2) with the defect. If there is no defect in 
    /// either sensor or if it is impossible to determine the defective sensor,
    /// return -1.
    ///
    /// Example 1:
    /// Input: sensor1 = [2,3,4,5], sensor2 = [2,1,3,4]
    /// Output: 1
    /// Explanation: Sensor 2 has the correct values.
    /// The second data point from sensor 2 is dropped, and the last value of 
    /// sensor 1 is replaced by a 5.
    ///
    /// Example 2:
    /// Input: sensor1 = [2,2,2,2,2], sensor2 = [2,2,2,2,5]
    /// Output: -1
    /// Explanation: It is impossible to determine which sensor has a defect.
    /// Dropping the last value for either sensor could produce the output 
    /// for the other sensor.
    ///
    /// Example 3:
    /// Input: sensor1 = [2,3,2,2,3,2], sensor2 = [2,3,2,3,2,7]
    /// Output: 2
    /// Explanation: Sensor 1 has the correct values.
    /// The fourth data point from sensor 1 is dropped, and the last value 
    /// of sensor 1 is replaced by a 7.
    /// 
    /// Constraints:
    /// 1. sensor1.length == sensor2.length
    /// 2. 1 <= sensor1.length <= 100
    /// 3. 1 <= sensor1[i], sensor2[i] <= 100
    /// </summary>
    int badSensor(vector<int>& sensor1, vector<int>& sensor2);

    /// <summary>
    /// Leet code 1838. Frequency of the Most Frequent Element
    /// 
    /// Medium
    /// 
    /// The frequency of an element is the number of times it occurs in an 
    /// array.
    ///  
    /// You are given an integer array nums and an integer k. In one 
    /// operation, you can choose an index of nums and increment the 
    /// element at that index by 1.
    ///
    /// Return the maximum possible frequency of an element after performing 
    /// at most k operations.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,4], k = 5
    /// Output: 3
    /// Explanation: Increment the first element three times and the second 
    /// element two times to make nums = [4,4,4].
    /// 4 has a frequency of 3.
    ///
    /// Example 2: 
    /// Input: nums = [1,4,8,13], k = 5
    /// Output: 2
    /// Explanation: There are multiple optimal solutions:
    /// - Increment the first element three times to make nums = [4,4,8,13]. 
    ///   4 has a frequency of 2.
    /// - Increment the second element four times to make nums = [1,8,8,13]. 
    ///   8 has a frequency of 2.
    /// - Increment the third element five times to make nums = [1,4,13,13]. 
    ///   13 has a frequency of 2.
    ///
    /// Example 3:
    /// Input: nums = [3,9,6], k = 2
    /// Output: 1
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// 3. 1 <= k <= 10^5
    /// </summary>
    int maxFrequency(vector<int>& nums, int k);

    /// <summary>
    /// Leet code 1840. Maximum Building Height
    /// 
    /// Hard
    /// 
    /// You want to build n new buildings in a city. The new buildings will 
    /// be built in a line and are labeled from 1 to n.
    ///
    /// However, there are city restrictions on the heights of the new 
    /// buildings:
    ///
    /// The height of each building must be a non-negative integer.
    /// The height of the first building must be 0.
    /// The height difference between any two adjacent buildings cannot 
    /// exceed 1.
    /// Additionally, there are city restrictions on the maximum height of 
    /// specific buildings. These restrictions are given as a 2D integer 
    /// array restrictions where restrictions[i] = [idi, maxHeighti] indicates 
    /// that building idi must have a height less than or equal to maxHeighti.
    ///
    /// It is guaranteed that each building will appear at most once in 
    /// restrictions, and building 1 will not be in restrictions.
    ///
    /// Return the maximum possible height of the tallest building.
    /// 
    /// Example 1:
    /// Input: n = 5, restrictions = [[2,1],[4,1]]
    /// Output: 2
    /// Explanation: The green area in the image indicates the maximum 
    /// allowed height for each building.
    /// We can build the buildings with heights [0,1,2,1,2], and the tallest 
    /// building has a height of 2.
    ///
    /// Example 2:
    /// Input: n = 6, restrictions = []
    /// Output: 5
    /// Explanation: The green area in the image indicates the maximum 
    /// allowed height for each building.
    /// We can build the buildings with heights [0,1,2,3,4,5], and the tallest 
    /// building has a height of 5.
    ///
    /// Example 3:
    /// Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
    /// Output: 5
    /// Explanation: The green area in the image indicates the maximum allowed 
    /// height for each building.
    /// We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the 
    /// tallest building has a height of 5.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 10^9
    /// 2. 0 <= restrictions.length <= min(n - 1, 10^5)
    /// 3. 2 <= idi <= n
    /// 4. idi is unique.
    /// 5. 0 <= maxHeighti <= 10^9
    /// </summary>
    int maxBuilding(int n, vector<vector<int>>& restrictions);

    /// <summary>
    /// Leet code 1848. Minimum Distance to the Target Element
    /// 
    /// Easy
    /// 
    /// Given an integer array nums (0-indexed) and two integers target and 
    /// start, find an index i such that nums[i] == target and abs(i - start) 
    /// is minimized. Note that abs(x) is the absolute value of x.
    /// Return abs(i - start).
    /// It is guaranteed that target exists in nums.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3,4,5], target = 5, start = 3
    /// Output: 1
    /// Explanation: nums[4] = 5 is the only value equal to target, so the 
    /// answer is abs(4 - 3) = 1.
    ///
    /// Example 2:
    /// Input: nums = [1], target = 1, start = 0
    /// Output: 0
    /// Explanation: nums[0] = 1 is the only value equal to target, so the 
    /// answer is abs(0 - 0) = 1.
    ///
    /// Example 3:
    /// Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
    /// Output: 0
    /// Explanation: Every value of nums is 1, but nums[0] minimizes 
    /// abs(i - start), which is abs(0 - 0) = 0.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 104
    /// 3. 0 <= start < nums.length
    /// 4. target is in nums.
    /// </summary>
    int getMinDistance(vector<int>& nums, int target, int start);

    /// <summary>
    /// Leet code 1855. Maximum Distance Between a Pair of Values
    /// 
    /// Medium
    /// 
    /// You are given two non-increasing 0-indexed integer arrays nums1
    /// and nums2.
    ///
    /// A pair of indices (i, j), where 0 <= i < nums1.length and 
    /// 0 <= j < nums2.length, is valid if both i <= j and 
    /// nums1[i] <= nums2[j]. The distance of the pair is j - i.
    ///
    /// Return the maximum distance of any valid pair (i, j). If there are 
    /// no valid pairs, return 0.
    ///
    /// An array arr is non-increasing if arr[i-1] >= arr[i] for 
    /// every 1 <= i < arr.length.
    ///
    /// Example 1:
    /// Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
    /// Output: 2
    /// Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), 
    /// (3,3), (3,4), and (4,4).
    /// The maximum distance is 2 with pair (2,4).
    ///
    /// Example 2:
    /// Input: nums1 = [2,2,2], nums2 = [10,10,1]
    /// Output: 1
    /// Explanation: The valid pairs are (0,0), (0,1), and (1,1).
    /// The maximum distance is 1 with pair (0,1).
    ///
    /// Example 3:
    /// Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
    /// Output: 2
    /// Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
    /// The maximum distance is 2 with pair (2,4).
    ///
    /// Example 4:
    /// Input: nums1 = [5,4], nums2 = [3,2]
    /// Output: 0
    /// Explanation: There are no valid pairs, so return 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums1.length <= 10^5
    /// 2. 1 <= nums2.length <= 10^5
    /// 3. 1 <= nums1[i], nums2[j] <= 10^5
    /// 4. Both nums1 and nums2 are non-increasing.
    /// </summary>
    int maxDistance(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet code 1886. Determine Whether Matrix Can Be Obtained By Rotation
    /// 
    /// Easy
    /// 
    /// Given two n x n binary matrices mat and target, return true if it is 
    /// possible to make mat equal to target by rotating mat in 90-degree 
    /// increments, or false otherwise.
    /// 
    /// Example 1:
    /// Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
    /// Output: true
    /// Explanation: We can rotate mat 90 degrees clockwise to make mat 
    /// equal target.
    ///
    /// Example 2:
    /// Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
    /// Output: false
    /// Explanation: It is impossible to make mat equal to target by rotating 
    /// mat.
    ///
    /// Example 3:
    /// Input: mat = [[0,0,0],[0,1,0],[1,1,1]], 
    /// target = [[1,1,1],[0,1,0],[0,0,0]]
    /// Output: true
    /// Explanation: We can rotate mat 90 degrees clockwise two times to 
    /// make mat equal target.
    ///
    /// Constraints:
    /// 1. n == mat.length == target.length
    /// 2. n == mat[i].length == target[i].length
    /// 2. 1 <= n <= 10
    /// 3. mat[i][j] and target[i][j] are either 0 or 1.
    /// </summary>
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target);

    /// <summary>
    /// Leet code 1861. Rotating the Box
    /// 
    /// Medium
    /// 
    /// You are given an m x n matrix of characters box representing a 
    /// side-view of a box. Each cell of the box is one of the following:
    ///  
    /// A stone '#'
    /// A stationary obstacle '*'
    /// Empty '.'
    /// The box is rotated 90 degrees clockwise, causing some of the stones 
    /// to fall due to gravity. Each stone falls down until it lands on an 
    /// obstacle, another stone, or the bottom of the box. Gravity does not 
    /// affect the obstacles' positions, and the inertia from the box's 
    /// rotation does not affect the stones' horizontal positions.
    ///
    /// It is guaranteed that each stone in box rests on an obstacle, another 
    /// stone, or the bottom of the box.
    ///
    /// Example 1:
    /// Input: box = [["#",".","#"]]
    /// Output: [["."],
    ///         ["#"],
    ///         ["#"]]
    ///
    /// Example 2:
    /// Input: box = [["#",".","*","."],
    ///          ["#","#","*","."]]
    /// Output: [["#","."],
    ///          ["#","#"],
    ///          ["*","*"],
    ///          [".","."]]
    ///
    /// Example 3:
    /// Input: box = [["#","#","*",".","*","."],
    ///           ["#","#","#","*",".","."],
    ///          ["#","#","#",".","#","."]]
    /// Output: [[".","#","#"],
    ///          [".","#","#"],
    ///          ["#","#","*"],
    ///          ["#","*","."],
    ///          ["#",".","*"],
    ///         ["#",".","."]]
    ///
    /// Constraints:
    /// 1. m == box.length
    /// 2. n == box[i].length
    /// 3. 1 <= m, n <= 500
    /// 4. box[i][j] is either '#', '*', or '.'.
    /// </summary>
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box);

    /// <summary>
    /// Leet code 1914. Cyclically Rotating a Grid
    /// 
    /// Medium
    /// 
    /// You are given an m x n integer matrix grid where m and n are both 
    /// even integers, and an integer k.
    ///
    /// The matrix is composed of several layers, which is shown in the 
    /// below image, where each color is its own layer:
    /// 
    /// A cyclic rotation of the matrix is done by cyclically rotating each 
    /// layer in the matrix. To cyclically rotate a layer once, each element 
    /// in the layer will take the place of the adjacent element in the 
    /// counter-clockwise direction. An example rotation is shown below:
    ///
    /// Return the matrix after applying k cyclic rotations to it.
    ///
    /// Example 1:
    /// Input: grid = [[40,10],[30,20]], k = 1
    /// Output: [[10,20],[40,30]]
    /// Explanation: The figures above represent the grid at every state.
    ///
    /// Example 2:
    /// Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
    /// Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
    /// Explanation: The figures above represent the grid at every state.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 2 <= m, n <= 50
    /// 4. Both m and n are even integers.
    /// 5. 1 <= grid[i][j] <= 5000
    /// 6. 1 <= k <= 10^9
    /// </summary>
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k);

    /// <summary>
    /// Leet code 1920. Build Array from Permutation
    /// 
    /// Easy
    /// 
    /// Given a zero-based permutation nums (0-indexed), build an array ans 
    /// of the same length where ans[i] = nums[nums[i]] for each 
    /// 0 <= i < nums.length and return it.
    ///
    /// A zero-based permutation nums is an array of distinct integers from 0 
    /// to nums.length - 1 (inclusive).
    /// 
    /// Example 1:
    /// Input: nums = [0,2,1,5,3,4]
    /// Output: [0,1,2,4,5,3]
    /// Explanation: The array ans is built as follows: 
    /// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], 
    /// nums[nums[4]], nums[nums[5]]]
    /// = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    /// = [0,1,2,4,5,3]
    ///
    /// Example 2:
    /// Input: nums = [5,0,1,2,3,4]
    /// Output: [4,5,0,1,2,3]
    /// Explanation: The array ans is built as follows:
    /// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], 
    /// nums[nums[4]], nums[nums[5]]]
    /// = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    /// = [4,5,0,1,2,3]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 0 <= nums[i] < nums.length
    /// 3. The elements in nums are distinct.
    /// 
    /// Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?
    /// </summary>
    vector<int> buildArray(vector<int>& nums);

    /// <summary>
    /// Leet code 1864. Minimum Number of Swaps to Make the Binary String 
    ///                 Alternating
    /// 
    /// Medium
    /// 
    /// Given a binary string s, return the minimum number of character swaps 
    /// to make it alternating, or -1 if it is impossible.
    ///
    /// The string is called alternating if no two adjacent characters are 
    /// equal. For example, the strings "010" and "1010" are alternating, 
    /// while the string "0100" is not.
    ///
    /// Any two characters may be swapped, even if they are not adjacent.
    /// 
    /// Example 1:
    /// Input: s = "111000"
    /// Output: 1
    /// Explanation: Swap positions 1 and 4: "111000" -> "101010"
    /// The string is now alternating.
    ///
    /// Example 2:
    /// Input: s = "010"
    /// Output: 0
    /// Explanation: The string is already alternating, no swaps are needed.
    ///
    /// Example 3:
    /// Input: s = "1110"
    /// Output: -1
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 1000
    /// 2. s[i] is either '0' or '1'.
    /// </summary>
    int minSwaps(string s);

    /// <summary>
    /// Leet code 1878. Get Biggest Three Rhombus Sums in a Grid
    ///                  
    /// Medium
    /// 
    /// You are given an m x n integer matrix grid. 
    /// A rhombus sum is the sum of the elements that form the border of a 
    /// regular rhombus shape in grid???. The rhombus must have the shape 
    /// of a square rotated 45 degrees with each of the corners centered 
    /// in a grid cell. Below is an image of four valid rhombus shapes 
    /// with the corresponding colored cells that should be included in each 
    /// rhombus sum:
    /// 
    /// Note that the rhombus can have an area of 0, which is depicted by 
    /// the purple rhombus in the bottom right corner.
    ///
    /// Return the biggest three distinct rhombus sums in the grid in 
    /// descending order. If there are less than three distinct values, return 
    /// all of them.
    /// 
    /// Example 1:
    /// Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],
    ///                [1,5,5,4,1],[4,3,2,2,5]]
    /// Output: [228,216,211]
    /// Explanation: The rhombus shapes for the three biggest distinct rhombus 
    /// sums are depicted above.
    /// - Blue: 20 + 3 + 200 + 5 = 228
    /// - Red: 200 + 2 + 10 + 4 = 216
    /// - Green: 5 + 200 + 4 + 2 = 211
    ///
    /// Example 2:
    /// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
    /// Output: [20,9,8]
    /// Explanation: The rhombus shapes for the three biggest distinct 
    /// rhombus sums are depicted above.
    /// - Blue: 4 + 2 + 6 + 8 = 20
    /// - Red: 9 (area 0 rhombus in the bottom right corner)
    /// - Green: 8 (area 0 rhombus in the bottom middle)
    ///
    /// Example 3:
    /// Input: grid = [[7,7,7]]
    /// Output: [7]
    /// Explanation: All three possible rhombus sums are the same, so 
    /// return [7].
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 50
    /// 4. 1 <= grid[i][j] <= 10^5
    /// </summary>
    vector<int> getBiggestThree(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code 1895. Largest Magic Square
    ///                  
    /// Medium
    /// 
    /// A k x k magic square is a k x k grid filled with integers such that 
    /// every row sum, every column sum, and both diagonal sums are all equal. 
    /// The integers in the magic square do not have to be distinct. Every 
    /// 1 x 1 grid is trivially a magic square.
    ///
    /// Given an m x n integer grid, return the size (i.e., the side length k) 
    /// of the largest magic square that can be found within this grid.
    ///
    /// Example 1:
    /// Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
    /// Output: 3
    /// Explanation: The largest magic square has a size of 3.
    /// Every row sum, column sum, and diagonal sum of this magic square is 
    /// equal to 12.
    /// - Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
    /// - Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
    /// - Diagonal sums: 5+4+3 = 6+4+2 = 12
    ///
    /// Example 2:
    /// Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
    /// Output: 2
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 50
    /// 4. 1 <= grid[i][j] <= 10^6
    /// </summary>
    int largestMagicSquare(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code 1888. Minimum Number of Flips to Make the Binary String 
    ///                 Alternating
    ///                  
    /// Medium
    /// 
    /// You are given a binary string s. You are allowed to perform two types 
    /// of operations on the string in any sequence:
    ///
    /// Type-1: Remove the character at the start of the string s and append 
    /// it to the end of the string.
    /// Type-2: Pick any character in s and flip its value, i.e., if its value 
    /// is '0' it becomes '1' and vice-versa.
    /// Return the minimum number of type-2 operations you need to perform 
    /// such that s becomes alternating.
    ///
    /// The string is called alternating if no two adjacent characters are 
    /// equal.
    ///
    /// For example, the strings "010" and "1010" are alternating, while the 
    /// string "0100" is not.
    /// Example 1:
    ///
    /// Input: s = "111000"
    /// Output: 2
    /// Explanation: Use the first operation two times to make s = "100011".
    /// Then, use the second operation on the third and sixth elements to 
    /// make s = "101010".
    ///
    /// Example 2:
    /// Input: s = "010"
    /// Output: 0
    /// Explanation: The string is already alternating.
    ///
    /// Example 3:
    /// Input: s = "1110"
    /// Output: 1
    /// Explanation: Use the second operation on the second element to 
    /// make s = "1010".
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. s[i] is either '0' or '1'.
    /// </summary>
    int minFlips(string s);

    /// <summary>
    /// Leet code 1894. Find the Student that Will Replace the Chalk
    ///                                  
    /// Medium
    /// 
    /// There are n students in a class numbered from 0 to n - 1. The teacher 
    /// will give each student a problem starting with the student number 0, 
    /// then the student number 1, and so on until the teacher reaches the 
    /// student number n - 1. After that, the teacher will restart the process,
    /// starting with the student number 0 again.
    /// You are given a 0-indexed integer array chalk and an integer k. There 
    /// are initially k pieces of chalk. When the student number i is given a 
    /// problem to solve, they will use chalk[i] pieces of chalk to solve that 
    /// problem. However, if the current number of chalk pieces is strictly 
    /// less than chalk[i], then the student number i will be asked to replace 
    /// the chalk.
    ///
    /// Return the index of the student that will replace the chalk.
    /// Example 1:
    /// Input: chalk = [5,1,5], k = 22
    /// Output: 0
    /// Explanation: The students go in turns as follows:
    /// - Student number 0 uses 5 chalk, so k = 17.
    /// - Student number 1 uses 1 chalk, so k = 16.
    /// - Student number 2 uses 5 chalk, so k = 11.
    /// - Student number 0 uses 5 chalk, so k = 6.
    /// - Student number 1 uses 1 chalk, so k = 5.
    /// - Student number 2 uses 5 chalk, so k = 0.
    /// Student number 0 does not have enough chalk, so they will have to 
    /// replace it.
    ///
    /// Example 2:
    /// Input: chalk = [3,4,1,2], k = 25
    /// Output: 1
    /// Explanation: The students go in turns as follows:
    /// - Student number 0 uses 3 chalk so k = 22.
    /// - Student number 1 uses 4 chalk so k = 18.
    /// - Student number 2 uses 1 chalk so k = 17.
    /// - Student number 3 uses 2 chalk so k = 15.
    /// - Student number 0 uses 3 chalk so k = 12.
    /// - Student number 1 uses 4 chalk so k = 8.
    /// - Student number 2 uses 1 chalk so k = 7.
    /// - Student number 3 uses 2 chalk so k = 5.
    /// - Student number 0 uses 3 chalk so k = 2.
    /// Student number 1 does not have enough chalk, so they will have to 
    /// replace it.
    /// 
    /// Constraints:
    /// 1. chalk.length == n
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= chalk[i] <= 10^5
    /// 4. 1 <= k <= 10^9
    /// </summary>
    int chalkReplacer(vector<int>& chalk, int k);

    /// <summary>
    /// Leet code 1929. Concatenation of Array
    ///                                                
    /// Easy
    /// 
    /// Given an integer array nums of length n, you want to create an array 
    /// ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] 
    /// for 0 <= i < n (0-indexed).
    ///
    /// Specifically, ans is the concatenation of two nums arrays.
    ///
    /// Return the array ans.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,1]
    /// Output: [1,2,1,1,2,1]
    /// Explanation: The array ans is formed as follows:
    /// - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
    /// - ans = [1,2,1,1,2,1]
    ///
    /// Example 2:
    /// Input: nums = [1,3,2,1]
    /// Output: [1,3,2,1,1,3,2,1]
    /// Explanation: The array ans is formed as follows:
    /// - ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],
    ///          nums[3]]
    /// - ans = [1,3,2,1,1,3,2,1]
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 1000
    /// 3. 1 <= nums[i] <= 1000
    /// </summary>
    vector<int> getConcatenation(vector<int>& nums);

    /// <summary>
    /// Leet code 2006. Count Number of Pairs With Absolute Difference K
    ///                                                
    /// Easy
    /// 
    /// Given an integer array nums and an integer k, return the number of 
    /// pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
    ///
    /// The value of |x| is defined as:
    ///
    /// x if x >= 0.
    /// -x if x < 0.
    ///
    /// Example 1:
    /// Input: nums = [1,2,2,1], k = 1
    /// Output: 4
    /// Explanation: The pairs with an absolute difference of 1 are:
    /// - [1,2,2,1]
    /// - [1,2,2,1]
    /// - [1,2,2,1]
    /// - [1,2,2,1]
    ///
    /// Example 2:
    /// Input: nums = [1,3], k = 3
    /// Output: 0
    /// Explanation: There are no pairs with an absolute difference of 3.
    ///
    /// Example 3:
    /// Input: nums = [3,2,1,5,4], k = 2
    /// Output: 3
    /// Explanation: The pairs with an absolute difference of 2 are:
    /// - [3,2,1,5,4]
    /// - [3,2,1,5,4]
    /// - [3,2,1,5,4]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 200
    /// 2. 1 <= nums[i] <= 100
    /// 3. 1 <= k <= 99
    /// </summary>
    int countKDifference(vector<int>& nums, int k);

    /// <summary>
    /// Leet code 2016. Maximum Difference Between Increasing Elements
    ///                                                
    /// Easy
    /// 
    /// Given a 0-indexed integer array nums of size n, find the maximum 
    /// difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), 
    /// such that 0 <= i < j < n and nums[i] < nums[j].
    /// Return the maximum difference. If no such i and j exists, return -1.
    /// 
    /// Example 1:
    /// Input: nums = [7,1,5,4]
    /// Output: 4
    /// Explanation:
    /// The maximum difference occurs with i = 1 and j = 2, 
    /// nums[j] - nums[i] = 5 - 1 = 4.
    /// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] 
    /// = 7 - 1 = 6, but i > j, so it is not valid.
    ///
    /// Example 2:
    /// Input: nums = [9,4,3,2]
    /// Output: -1
    /// Explanation:
    /// There is no i and j such that i < j and nums[i] < nums[j].
    ///
    /// Example 3:
    /// Input: nums = [1,5,2,10]
    /// Output: 9
    /// Explanation:
    /// The maximum difference occurs with i = 0 and j = 3, 
    /// nums[j] - nums[i] = 10 - 1 = 9.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 2 <= n <= 1000
    /// 3. 1 <= nums[i] <= 10^9
    /// </summary>
    int maximumDifference(vector<int>& nums);

    /// <summary>
    /// Leet code 2022. Convert 1D Array Into 2D Array
    ///                                                
    /// Easy
    /// 
    /// You are given a 0-indexed 1-dimensional (1D) integer array original, 
    /// and two integers, m and n. You are tasked with creating a 
    /// 2-dimensional (2D) array with m rows and n columns using all the 
    /// elements from original.
    ///
    /// The elements from indices 0 to n - 1 (inclusive) of original should 
    /// form the first row of the constructed 2D array, the elements from 
    /// indices n to 2 * n - 1 (inclusive) should form the second row of 
    /// the constructed 2D array, and so on.
    ///
    /// Return an m x n 2D array constructed according to the above 
    /// procedure, or an empty 2D array if it is impossible.
    /// 
    /// Example 1:
    /// Input: original = [1,2,3,4], m = 2, n = 2
    /// Output: [[1,2],[3,4]]
    /// Explanation:
    /// The constructed 2D array should contain 2 rows and 2 columns.
    /// The first group of n=2 elements in original, [1,2], becomes the first 
    /// row in the constructed 2D array.
    /// The second group of n=2 elements in original, [3,4], becomes the 
    /// second row in the constructed 2D array.
    ///
    /// Example 2:
    /// Input: original = [1,2,3], m = 1, n = 3
    /// Output: [[1,2,3]]
    /// Explanation:
    /// The constructed 2D array should contain 1 row and 3 columns.
    /// Put all three elements in original into the first row of the 
    /// constructed 2D array.
    ///
    /// Example 3:
    /// Input: original = [1,2], m = 1, n = 1
    /// Output: []
    /// Explanation:
    /// There are 2 elements in original.
    /// It is impossible to fit 2 elements in a 1x1 2D array, so return an 
    /// empty 2D array.
    ///
    /// Example 4:
    /// Input: original = [3], m = 1, n = 2
    /// Output: []
    /// Explanation:
    /// There is 1 element in original.
    /// It is impossible to make 1 element fill all the spots in a 1x2 2D 
    /// array, so return an empty 2D array.
    /// 
    /// Constraints:
    /// 1. 1 <= original.length <= 5 * 10^4
    /// 2. 1 <= original[i] <= 10^5
    /// 3. 1 <= m, n <= 4 * 10^4
    /// </summary>
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n);

    /// <summary>
    /// Leet code 2057. Smallest Index With Equal Value
    ///                                                
    /// Easy
    /// 
    /// Given a 0-indexed integer array nums, return the smallest index i of 
    /// nums such that i mod 10 == nums[i], or -1 if such index does not exist.
    /// 
    /// x mod y denotes the remainder when x is divided by y.
    /// Example 1:
    /// Input: nums = [0,1,2]
    /// Output: 0
    /// Explanation: 
    /// i=0: 0 mod 10 = 0 == nums[0].
    /// i=1: 1 mod 10 = 1 == nums[1].
    /// i=2: 2 mod 10 = 2 == nums[2].
    /// All indices have i mod 10 == nums[i], so we return the smallest 
    /// index 0.
    /// Example 2:
    ///
    /// Input: nums = [4,3,2,1]
    /// Output: 2
    /// Explanation: 
    /// i=0: 0 mod 10 = 0 != nums[0].
    /// i=1: 1 mod 10 = 1 != nums[1].
    /// i=2: 2 mod 10 = 2 == nums[2].
    /// i=3: 3 mod 10 = 3 != nums[3].
    /// 2 is the only index which has i mod 10 == nums[i].
    ///
    /// Example 3:
    /// Input: nums = [1,2,3,4,5,6,7,8,9,0]
    /// Output: -1
    /// Explanation: No index satisfies i mod 10 == nums[i].
    ///
    /// Example 4:
    /// Input: nums = [2,1,3,5,2]
    /// Output: 1
    /// Explanation: 1 is the only index with i mod 10 == nums[i].
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 0 <= nums[i] <= 9
    /// </summary>
    int smallestEqual(vector<int>& nums);

    /// <summary>
    /// Leet code 1991. Find the Middle Index in Array
    ///                                                
    /// Easy
    /// 
    /// Given a 0-indexed integer array nums, find the leftmost middleIndex 
    /// (i.e., the smallest amongst all the possible ones).
    ///
    /// A middleIndex is an index where nums[0] + nums[1] + ... + 
    /// nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] 
    /// + ... + nums[nums.length-1].
    ///
    /// If middleIndex == 0, the left side sum is considered to be 0. 
    /// Similarly, if middleIndex == nums.length - 1, the right side sum is 
    /// considered to be 0.
    ///
    /// Return the leftmost middleIndex that satisfies the condition, or -1 
    /// if there is no such index.
    /// 
    /// Example 1:
    /// Input: nums = [2,3,-1,8,4]
    /// Output: 3
    /// Explanation:
    /// The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
    /// The sum of the numbers after index 3 is: 4 = 4
    ///
    /// Example 2:
    /// Input: nums = [1,-1,4]
    /// Output: 2
    /// Explanation:
    /// The sum of the numbers before index 2 is: 1 + -1 = 0
    /// The sum of the numbers after index 2 is: 0
    ///
    /// Example 3:
    /// Input: nums = [2,5]
    /// Output: -1
    /// Explanation:
    /// There is no valid middleIndex.
    ///
    /// Example 4:
    /// Input: nums = [1]
    /// Output: 0
    /// Explantion:
    /// The sum of the numbers before index 0 is: 0
    /// The sum of the numbers after index 0 is: 0
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. -1000 <= nums[i] <= 1000
    /// </summary>
    int findMiddleIndex(vector<int>& nums);

    /// <summary>
    /// Leet code 1930. Unique Length-3 Palindromic Subsequences
    ///                                                                 
    /// Medium
    /// 
    /// Given a string s, return the number of unique palindromes of length 
    /// three that are a subsequence of s.
    ///
    /// Note that even if there are multiple ways to obtain the same 
    /// subsequence, it is still only counted once.
    ///
    /// A palindrome is a string that reads the same forwards and backwards.
    ///
    /// A subsequence of a string is a new string generated from the original 
    /// string with some characters (can be none) deleted without changing 
    /// the relative order of the remaining characters.
    ///
    /// For example, "ace" is a subsequence of "abcde".
    /// Example 1:
    /// Input: s = "aabca"
    /// Output: 3
    /// Explanation: The 3 palindromic subsequences of length 3 are:
    /// - "aba" (subsequence of "aabca")
    /// - "aaa" (subsequence of "aabca")
    /// - "aca" (subsequence of "aabca")
    ///
    /// Example 2:
    /// Input: s = "adc"
    /// Output: 0
    /// Explanation: There are no palindromic subsequences of length 3 
    /// in "adc".
    ///
    /// Example 3:
    /// Input: s = "bbcbaba"
    /// Output: 4
    /// Explanation: The 4 palindromic subsequences of length 3 are:
    /// - "bbb" (subsequence of "bbcbaba")
    /// - "bcb" (subsequence of "bbcbaba")
    /// - "bab" (subsequence of "bbcbaba")
    /// - "aba" (subsequence of "bbcbaba")
    /// 
    /// Constraints:
    /// 1. 3 <= s.length <= 10^5
    /// 2. s consists of only lowercase English letters.
    /// </summary>
    int countPalindromicSubsequence(string s);

    /// <summary>
    /// Leet code 2009. Minimum Number of Operations to Make Array Continuous
    ///                                                                 
    /// Hard
    /// 
    /// You are given an integer array nums. In one operation, you can replace 
    /// any element in nums with any integer.
    ///
    /// nums is considered continuous if both of the following conditions are 
    /// fulfilled:
    ///
    /// All elements in nums are unique.
    /// The difference between the maximum element and the minimum element in 
    /// nums equals nums.length - 1.
    /// For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 
    /// 5, 6] is not continuous.
    ///
    /// Return the minimum number of operations to make nums continuous.
    ///
    /// Example 1:
    /// Input: nums = [4,2,5,3]
    /// Output: 0
    /// Explanation: nums is already continuous.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,5,6]
    /// Output: 1
    /// Explanation: One possible solution is to change the last element to 4.
    /// The resulting array is [1,2,3,5,4], which is continuous.
    ///
    /// Example 3:
    /// Input: nums = [1,10,100,1000]
    /// Output: 3
    /// Explanation: One possible solution is to:
    /// - Change the second element to 2.
    /// - Change the third element to 3.
    /// - Change the fourth element to 4.
    ///
    /// The resulting array is [1,2,3,4], which is continuous.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    int minOperationsII(vector<int>& nums);

    /// <summary>
    /// Leet code 1936. Add Minimum Number of Rungs
    ///                                                                 
    /// Medium
    /// 
    /// You are given a strictly increasing integer array rungs that represents
    /// the height of rungs on a ladder. You are currently on the floor at 
    /// height 0, and you want to reach the last rung.
    ///
    /// You are also given an integer dist. You can only climb to the next 
    /// highest rung if the distance between where you are currently at (the 
    /// floor or on a rung) and the next rung is at most dist. You are able to 
    /// insert rungs at any positive integer height if a rung is not already 
    /// there.
    ///
    /// Return the minimum number of rungs that must be added to the ladder in 
    /// order for you to climb to the last rung.
    /// 
    /// Example 1:
    /// Input: rungs = [1,3,5,10], dist = 2
    /// Output: 2
    /// Explanation:
    /// You currently cannot reach the last rung.
    /// Add rungs at heights 7 and 8 to climb this ladder. 
    /// The ladder will now have rungs at [1,3,5,7,8,10].
    ///
    /// Example 2:
    /// Input: rungs = [3,6,8,10], dist = 3
    /// Output: 0
    /// Explanation:
    /// This ladder can be climbed without adding additional rungs.
    ///
    /// Example 3:
    /// Input: rungs = [3,4,6,7], dist = 2
    /// Output: 1
    /// Explanation:
    /// You currently cannot reach the first rung from the ground.
    /// Add a rung at height 1 to climb this ladder.
    /// The ladder will now have rungs at [1,3,4,6,7].
    ///
    /// Example 4:
    /// Input: rungs = [5], dist = 10
    /// Output: 0
    /// Explanation:
    /// This ladder can be climbed without adding additional rungs.
    /// 
    /// Constraints:
    /// 1. 1 <= rungs.length <= 10^5
    /// 2. 1 <= rungs[i] <= 10^9
    /// 3. 1 <= dist <= 10^9
    /// 4. rungs is strictly increasing.
    /// </summary>
    int addRungs(vector<int>& rungs, int dist);

    /// <summary>
    /// Leet code 2025. Maximum Number of Ways to Partition an Array
    ///                                                                 
    /// Hard
    /// 
    /// You are given a 0-indexed integer array nums of length n. The number 
    /// of ways to partition nums is the number of pivot indices that satisfy 
    /// both conditions:
    ///
    /// 1 <= pivot < n
    /// nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + 
    /// nums[pivot + 1] + ... + nums[n - 1]
    /// You are also given an integer k. You can choose to change the value 
    /// of one element of nums to k, or to leave the array unchanged.
    ///
    /// Return the maximum possible number of ways to partition nums to 
    /// satisfy both conditions after changing at most one element.
    /// 
    /// Example 1:
    /// Input: nums = [2,-1,2], k = 3
    /// Output: 1
    /// Explanation: One optimal approach is to change nums[0] to k. 
    /// The array becomes [3,-1,2].
    /// There is one way to partition the array:
    /// - For pivot = 2, we have the partition [3,-1 | 2]: 3 + -1 == 2.
    ///
    /// Example 2:
    /// 
    /// Input: nums = [0,0,0], k = 1
    /// Output: 2
    /// Explanation: The optimal approach is to leave the array unchanged.
    /// There are two ways to partition the array:
    /// - For pivot = 1, we have the partition [0 | 0,0]: 0 == 0 + 0.
    /// - For pivot = 2, we have the partition [0,0 | 0]: 0 + 0 == 0.
    ///
    /// Example 3:
    /// Input: nums = [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14], k = -33
    /// Output: 4
    /// Explanation: One optimal approach is to change nums[2] to k. The 
    /// array becomes [22,4,-33,-20,-15,15,-16,7,19,-10,0,-13,-14].
    /// There are four ways to partition the array.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 2 <= n <= 10^5
    /// 3. -10^5 <= k, nums[i] <= 10^5
    /// </summary>
    int waysToPartition(vector<int>& nums, int k);

    /// <summary>
    /// Leet 1937. Maximum Number of Points with Cost
    ///                                                                 
    /// Medium
    /// 
    /// You are given an m x n integer matrix points (0-indexed). Starting 
    /// with 0 points, you want to maximize the number of points you can get 
    /// from the matrix.
    ///
    /// To gain points, you must pick one cell in each row. Picking the cell 
    /// at coordinates (r, c) will add points[r][c] to your score.
    ///
    /// However, you will lose points if you pick a cell too far from the cell 
    /// that you picked in the previous row. For every two adjacent rows r and 
    /// r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and 
    /// (r + 1, c2) will subtract abs(c1 - c2) from your score.
    /// 
    /// Return the maximum number of points you can achieve.
    /// abs(x) is defined as:
    /// x for x >= 0.
    /// -x for x < 0.
    ///
    /// Example 1:
    /// Input: points = [[1,2,3],[1,5,1],[3,1,1]]
    /// Output: 9
    /// Explanation:
    /// The blue cells denote the optimal cells to pick, which have 
    /// coordinates (0, 2), (1, 1), and (2, 0).
    /// You add 3 + 5 + 3 = 11 to your score.
    /// However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
    /// Your final score is 11 - 2 = 9.
    ///
    /// Example 2:
    /// Input: points = [[1,5],[2,3],[4,2]]
    /// Output: 11
    /// Explanation:
    /// The blue cells denote the optimal cells to pick, which have 
    /// coordinates (0, 1), (1, 1), and (2, 0).
    /// You add 5 + 3 + 4 = 12 to your score.
    /// However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
    /// Your final score is 12 - 1 = 11.
    /// 
    /// Constraints:
    /// 1. m == points.length
    /// 2. n == points[r].length
    /// 3. 1 <= m, n <= 10^5
    /// 4. 1 <= m * n <= 10^5
    /// 5. 0 <= points[r][c] <= 10^5
    /// </summary>
    long long maxPoints(vector<vector<int>>& points);

    /// <summary>
    /// Leet Code 1788. Maximize the Beauty of the Garden
    ///                                                                 
    /// Hard
    /// 
    /// There is a garden of n flowers, and each flower has an integer beauty 
    /// value. The flowers are arranged in a line. You are given an integer 
    /// array flowers of size n and each flowers[i] represents the beauty of 
    /// the ith flower.
    ///
    /// A garden is valid if it meets these conditions:
    /// 
    /// The garden has at least two flowers.
    /// The first and the last flower of the garden have the same beauty value.
    /// As the appointed gardener, you have the ability to remove any (possibly 
    /// none) flowers from the garden. You want to remove flowers in a way that 
    /// makes the remaining garden valid. The beauty of the garden is the sum 
    /// of the beauty of all the remaining flowers.
    /// Return the maximum possible beauty of some valid garden after you have 
    /// removed any (possibly none) flowers.
    ///
    /// Example 1:
    /// Input: flowers = [1,2,3,1,2]
    /// Output: 8
    /// Explanation: You can produce the valid garden [2,3,1,2] to have a 
    /// total beauty of 2 + 3 + 1 + 2 = 8.
    ///
    /// Example 2:
    /// Input: flowers = [100,1,1,-3,1]
    /// Output: 3
    /// Explanation: You can produce the valid garden [1,1,1] to have a total 
    /// beauty of 1 + 1 + 1 = 3.
    ///
    /// Example 3:
    /// Input: flowers = [-1,-2,0,-1]
    /// Output: -2
    /// Explanation: You can produce the valid garden [-1,-1] to have a total 
    /// beauty of -1 + -1 = -2.
    /// Constraints:
    /// 1. 2 <= flowers.length <= 10^5
    /// 2. -10^4 <= flowers[i] <= 10^4
    /// 3. It is possible to create a valid garden by removing some (possibly 
    ///    none) flowers.
    /// </summary>
    int maximumBeauty(vector<int>& flowers);

    /// <summary>
    /// Leet Code 2088. Count Fertile Pyramids in a Land
    ///                                                                 
    /// Hard
    /// 
    /// A farmer has a rectangular grid of land with m rows and n columns that
    /// can be divided into unit cells. Each cell is either fertile 
    /// (represented by a 1) or barren (represented by a 0). All cells outside 
    /// the grid are considered barren.
    ///
    /// A pyramidal plot of land can be defined as a set of cells with the 
    /// following criteria:
    ///
    /// The number of cells in the set has to be greater than 1 and all cells 
    /// must be fertile.
    /// The apex of a pyramid is the topmost cell of the pyramid. The height 
    /// of a pyramid is the number of rows it covers. Let (r, c) be the apex 
    /// of the pyramid, and its height be h. Then, the plot comprises of 
    /// cells (i, j) where r <= i <= r + h - 1 and c - (i - r) <= j <= c + 
    /// (i - r).
    /// An inverse pyramidal plot of land can be defined as a set of cells 
    /// with similar criteria:
    ///
    /// The number of cells in the set has to be greater than 1 and all 
    /// cells must be fertile.
    /// The apex of an inverse pyramid is the bottommost cell of the 
    /// inverse pyramid. The height of an inverse pyramid is the number of 
    /// rows it covers. Let (r, c) be the apex of the pyramid, and its height 
    /// be h. Then, the plot comprises of cells (i, j) where 
    /// r - h + 1 <= i <= r and c - (r - i) <= j <= c + (r - i).
    /// Some examples of valid and invalid pyramidal (and inverse pyramidal) 
    /// plots are shown below. Black cells indicate fertile cells.
    ///
    /// Given a 0-indexed m x n binary matrix grid representing the farmland, 
    /// return the total number of pyramidal and inverse pyramidal plots that 
    /// can be found in grid.
    ///
    /// Example 1:
    /// Input: grid = [[0,1,1,0],[1,1,1,1]]
    /// Output: 2
    /// Explanation:
    /// The 2 possible pyramidal plots are shown in blue and red respectively.
    /// There are no inverse pyramidal plots in this grid. 
    /// Hence total number of pyramidal and inverse pyramidal plots 
    /// is 2 + 0 = 2.
    ///
    /// Example 2:
    /// Input: grid = [[1,1,1],[1,1,1]]
    /// Output: 2
    /// Explanation:
    /// The pyramidal plot is shown in blue, and the inverse pyramidal plot 
    /// is shown in red. 
    /// Hence the total number of plots is 1 + 1 = 2.
    ///
    /// Example 3:
    /// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
    /// Output: 0
    /// Explanation:
    /// There are no pyramidal or inverse pyramidal plots in the grid.
    ///
    /// Example 4:
    /// Input: grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
    /// Output: 13
    /// Explanation:
    /// There are 7 pyramidal plots, 3 of which are shown in the 2nd 
    /// and 3rd figures.
    /// There are 6 inverse pyramidal plots, 2 of which are shown in the 
    /// last figure.
    /// The total number of plots is 7 + 6 = 13.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 1000
    /// 4. 1 <= m * n <= 10^5
    /// 5. grid[i][j] is either 0 or 1.
    /// </summary>
    int countPyramids(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2090. K Radius Subarray Averages
    ///                                                                 
    /// Medium
    /// 
    /// You are given a 0-indexed array nums of n integers, and an integer k.
    ///
    /// The k-radius average for a subarray of nums centered at some index i 
    /// with the radius k is the average of all elements in nums between the 
    /// indices i - k and i + k (inclusive). If there are less than k elements 
    /// before or after the index i, then the k-radius average is -1.
    ///
    /// Build and return an array avgs of length n where avgs[i] is the 
    /// k-radius average for the subarray centered at index i.
    ///
    /// The average of x elements is the sum of the x elements divided by x, 
    /// using integer division. The integer division truncates toward zero, 
    /// which means losing its fractional part.
    ///
    /// For example, the average of four elements 2, 3, 1, and 5 is 
    /// (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.
    ///
    /// Example 1:
    /// Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
    /// Output: [-1,-1,-1,5,4,4,-1,-1,-1]
    /// Explanation:
    /// - avg[0], avg[1], and avg[2] are -1 because there are less than k 
    ///  elements before each index.
    /// - The sum of the subarray centered at index 3 with radius 3 
    /// is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
    /// Using integer division, avg[3] = 37 / 7 = 5.
    /// - For the subarray centered at index 4, avg[4] = 
    ///  (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
    /// - For the subarray centered at index 5, avg[5] = 
    ///  (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
    /// - avg[6], avg[7], and avg[8] are -1 because there are less than k 
    ///   elements after each index.
    ///
    /// Example 2:
    /// Input: nums = [100000], k = 0
    /// Output: [100000]
    /// Explanation:
    /// - The sum of the subarray centered at index 0 with radius 0 
    ///   is: 100000.
    /// avg[0] = 100000 / 1 = 100000.
    ///
    /// Example 3:
    /// Input: nums = [8], k = 100000
    /// Output: [-1]
    /// Explanation: 
    /// - avg[0] is -1 because there are less than k elements before and 
    ///   after index 0.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^5
    /// 3. 0 <= nums[i], k <= 10^5
    /// </summary>
    vector<int> getAverages(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 1874. Minimize Product Sum of Two Arrays
    ///                                                                 
    /// Medium
    /// 
    /// The product sum of two equal-length arrays a and b is equal to the 
    /// sum of a[i] * b[i] for all 0 <= i < a.length (0-indexed).
    ///
    /// For example, if a = [1,2,3,4] and b = [5,2,3,1], the product sum would 
    /// be 1*5 + 2*2 + 3*3 + 4*1 = 22.
    /// Given two arrays nums1 and nums2 of length n, return the minimum 
    /// product sum if you are allowed to rearrange the order of the elements 
    /// in nums1. 
    /// 
    /// Example 1:
    /// Input: nums1 = [5,3,4,2], nums2 = [4,2,2,5]
    /// Output: 40
    /// Explanation: We can rearrange nums1 to become [3,5,4,2]. The product 
    /// sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.
    ///
    /// Example 2:
    /// Input: nums1 = [2,1,4,5,7], nums2 = [3,2,4,8,6]
    /// Output: 65
    /// Explanation: We can rearrange nums1 to become [5,7,4,1,2]. The product 
    /// sum of [5,7,4,1,2] and [3,2,4,8,6] is 5*3 + 7*2 + 4*4 + 1*8 + 2*6 = 65.
    /// 
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums1[i], nums2[i] <= 100
    /// </summary>
    int minProductSum(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2079. Watering Plants 
    ///                                                                 
    /// Medium
    /// 
    /// You want to water n plants in your garden with a watering can. The 
    /// plants are arranged in a row and are labeled from 0 to n - 1 from 
    /// left to right where the ith plant is located at x = i. There is a 
    /// river at x = -1 that you can refill your watering can at.
    ///
    /// Each plant needs a specific amount of water. You will water the 
    /// plants in the following way:
    /// 
    /// Water the plants in order from left to right.
    /// After watering the current plant, if you do not have enough water 
    /// to completely water the next plant, return to the river to fully 
    /// refill the watering can.
    /// You cannot refill the watering can early.
    /// You are initially at the river (i.e., x = -1). It takes one step 
    /// to move one unit on the x-axis.
    ///  
    /// Given a 0-indexed integer array plants of n integers, where plants[i] 
    /// is the amount of water the ith plant needs, and an integer capacity 
    /// representing the watering can capacity, return the number of steps 
    /// needed to water all the plants.
    /// 
    /// Example 1:
    /// 
    /// Input: plants = [2,2,3,3], capacity = 5
    /// Output: 14
    /// Explanation: Start at the river with a full watering can:
    /// - Walk to plant 0 (1 step) and water it. Watering can has 3 units of 
    ///   water.
    /// - Walk to plant 1 (1 step) and water it. Watering can has 1 unit of 
    ///   water.
    /// - Since you cannot completely water plant 2, walk back to the river 
    ///   to refill (2 steps).
    /// - Walk to plant 2 (3 steps) and water it. Watering can has 2 units 
    ///   of water.
    /// - Since you cannot completely water plant 3, walk back to the river 
    ///   to refill (3 steps).
    /// - Walk to plant 3 (4 steps) and water it.
    /// Steps needed = 1 + 1 + 2 + 3 + 3 + 4 = 14.
    ///
    /// Example 2:
    /// Input: plants = [1,1,1,4,2,3], capacity = 4
    /// Output: 30
    /// Explanation: Start at the river with a full watering can:
    /// - Water plants 0, 1, and 2 (3 steps). Return to river (3 steps).
    /// - Water plant 3 (4 steps). Return to river (4 steps).
    /// - Water plant 4 (5 steps). Return to river (5 steps).
    /// - Water plant 5 (6 steps).
    /// Steps needed = 3 + 3 + 4 + 4 + 5 + 5 + 6 = 30.
    ///
    /// Example 3:
    /// Input: plants = [7,7,7,7,7,7,7], capacity = 8
    /// Output: 49
    /// Explanation: You have to refill before watering each plant.
    /// Steps needed = 1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 + 5 + 5 + 6 + 6 + 7 = 49.
    /// 
    /// Constraints:
    /// 1. n == plants.length
    /// 2. 1 <= n <= 1000
    /// 3. 1 <= plants[i] <= 10^6
    /// 4. max(plants[i]) <= capacity <= 10^9
    /// </summary>
    int wateringPlants(vector<int>& plants, int capacity);

    /// <summary>
    /// Leet Code 2018. Check if Word Can Be Placed In Crossword 
    ///                                                                 
    /// Medium
    /// 
    /// You are given an m x n matrix board, representing the current state 
    /// of a crossword puzzle. The crossword contains lowercase English 
    /// letters (from solved words), ' ' to represent any empty cells, 
    /// and '#' to represent any blocked cells.
    ///
    /// A word can be placed horizontally (left to right or right to left) or 
    /// vertically (top to bottom or bottom to top) in the board if:
    ///
    /// It does not occupy a cell containing the character '#'.
    /// The cell each letter is placed in must either be ' ' (empty) or match 
    /// the letter already on the board.
    /// There must not be any empty cells ' ' or other lowercase letters 
    /// directly left or right of the word if the word was placed horizontally.
    /// There must not be any empty cells ' ' or other lowercase letters directly 
    /// above or below the word if the word was placed vertically.
    /// Given a string word, return true if word can be placed in board, or 
    /// false otherwise.
    /// 
    /// Example 1:
    /// Input: board = [["#", " ", "#"], [" ", " ", "#"], 
    /// ["#", "c", " "]], word = "abc"
    /// Output: true
    /// Explanation: The word "abc" can be placed as shown above 
    /// (top to bottom).
    ///
    /// Example 2:
    /// Input: board = [[" ", "#", "a"], [" ", "#", "c"], 
    /// [" ", "#", "a"]], word = "ac"
    /// Output: false
    /// Explanation: It is impossible to place the word because there will 
    /// always be a space/letter above or below it.
    ///
    /// Example 3:
    /// Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], 
    /// word = "ca"
    /// Output: true
    /// Explanation: The word "ca" can be placed as shown above 
    /// (right to left). 
    ///
    /// Constraints:
    /// 1. m == board.length
    /// 2. n == board[i].length
    /// 3. 1 <= m * n <= 2 * 10^5
    /// 4. board[i][j] will be ' ', '#', or a lowercase English letter.
    /// 5. 1 <= word.length <= max(m, n)
    /// 6. word will contain only lowercase English letters.
    /// </summary>
    bool placeWordInCrossword(vector<vector<char>>& board, string word);

    /// <summary>
    /// Leet Code 2078. Two Furthest Houses With Different Colors 
    ///                                                                 
    /// Easy
    /// 
    /// There are n houses evenly lined up on the street, and each house is 
    /// beautifully painted. You are given a 0-indexed integer array colors 
    /// of length n, where colors[i] represents the color of the ith house.
    ///
    /// Return the maximum distance between two houses with different colors.
    ///
    /// The distance between the ith and jth houses is abs(i - j), where 
    /// abs(x) is the absolute value of x.
    ///  
    /// Example 1:
    /// Input: colors = [1,1,1,6,1,1,1]
    /// Output: 3
    /// Explanation: In the above image, color 1 is blue, and color 6 is red.
    /// The furthest two houses with different colors are house 0 and house 3.
    /// House 0 has color 1, and house 3 has color 6. The distance between 
    /// them is abs(0 - 3) = 3.
    /// Note that houses 3 and 6 can also produce the optimal answer.
    ///
    /// Example 2:
    /// Input: colors = [1,8,3,8,3]
    /// Output: 4
    /// Explanation: In the above image, color 1 is blue, color 8 is yellow, 
    /// and color 3 is green.
    /// The furthest two houses with different colors are house 0 and house 4.
    /// House 0 has color 1, and house 4 has color 3. The distance between 
    /// them is abs(0 - 4) = 4.
    ///
    /// Example 3:
    /// Input: colors = [0,1]
    /// Output: 1
    /// Explanation: The furthest two houses with different colors are 
    /// house 0 and house 1.
    /// House 0 has color 0, and house 1 has color 1. The distance between 
    /// them is abs(0 - 1) = 1.
    /// 
    /// Constraints:
    /// 1. n == colors.length
    /// 2. 2 <= n <= 100
    /// 3. 0 <= colors[i] <= 100
    /// 4. Test data are generated such that at least two houses have different 
    ///    colors.
    /// </summary>
    int maxDistance(vector<int>& colors);

    /// <summary>
    /// Leet Code 2075. Decode the Slanted Ciphertext
    ///                                                                 
    /// Medium
    /// 
    /// A string originalText is encoded using a slanted transposition cipher 
    /// to a string encodedText with the help of a matrix having a fixed 
    /// number of rows rows.
    ///
    /// originalText is placed first in a top-left to bottom-right manner.
    /// The blue cells are filled first, followed by the red cells, then the 
    /// yellow cells, and so on, until we reach the end of originalText. The 
    /// arrow indicates the order in which the cells are filled. All empty 
    /// cells are filled with ' '. The number of columns is chosen such that 
    /// the rightmost column will not be empty after filling in originalText.
    ///
    /// encodedText is then formed by appending all characters of the matrix 
    /// in a row-wise fashion.
    /// 
    /// The characters in the blue cells are appended first to encodedText, 
    /// then the red cells, and so on, and finally the yellow cells. The 
    /// arrow indicates the order in which the cells are accessed.
    ///
    /// For example, if originalText = "cipher" and rows = 3, then we encode 
    /// it in the following manner:
    ///
    /// The blue arrows depict how originalText is placed in the matrix, and 
    /// the red arrows denote the order in which encodedText is formed. In 
    /// the above example, encodedText = "ch ie pr".
    ///
    /// Given the encoded string encodedText and number of rows rows, return 
    /// the original string originalText.
    ///
    /// Note: originalText does not have any trailing spaces ' '. The test 
    /// cases are generated such that there is only one possible 
    /// originalText.
    ///
    /// Example 1:
    /// Input: encodedText = "ch   ie   pr", rows = 3
    /// Output: "cipher"
    /// Explanation: This is the same example described in the problem 
    /// description.
    ///
    /// Example 2:
    /// Input: encodedText = "iveo    eed   l te   olc", rows = 4
    /// Output: "i love leetcode"
    /// Explanation: The figure above denotes the matrix that was used to 
    /// encode originalText. 
    /// The blue arrows show how we can find originalText from encodedText.
    ///
    /// Example 3:
    /// Input: encodedText = "coding", rows = 1
    /// Output: "coding"
    /// Explanation: Since there is only 1 row, both originalText and 
    /// encodedText are the same.
    ///
    /// Example 4:
    /// Input: encodedText = " b  ac", rows = 2
    /// Output: " abc"
    /// Explanation: originalText cannot have trailing spaces, but it may be 
    /// preceded by one or more spaces.
    ///
    /// Constraints:
    /// 1. 0 <= encodedText.length <= 10^6
    /// 2. encodedText consists of lowercase English letters and ' ' only.
    /// 3. encodedText is a valid encoding of some originalText that does not 
    ///    have trailing spaces.
    /// 4. 1 <= rows <= 1000
    /// 5. The testcases are generated such that there is only one possible 
    ///    originalText.
    /// </summary>
    string decodeCiphertext(string encodedText, int rows);

    /// <summary>
    /// Leet Code 2086. Minimum Number of Buckets Required to Collect 
    ///                 Rainwater from Houses
    ///                                                                 
    /// Medium
    /// You are given a 0-indexed string street. Each character in street is 
    /// either 'H' representing a house or '.' representing an empty space.
    ///
    /// You can place buckets on the empty spaces to collect rainwater that 
    /// falls from the adjacent houses. The rainwater from a house at index 
    /// i is collected if a bucket is placed at index i - 1 and/or 
    /// index i + 1. A single bucket, if placed adjacent to two houses, can 
    /// collect the rainwater from both houses.
    ///
    /// Return the minimum number of buckets needed so that for every house, 
    /// there is at least one bucket collecting rainwater from it, or -1 if 
    /// it is impossible.
    /// 
    /// Example 1:
    /// Input: street = "H..H"
    /// Output: 2
    /// Explanation:
    /// We can put buckets at index 1 and index 2.
    /// "H..H" -> "HBBH" ('B' denotes where a bucket is placed).
    /// The house at index 0 has a bucket to its right, and the house at 
    /// index 3 has a bucket to its left.
    /// Thus, for every house, there is at least one bucket collecting 
    /// rainwater from it.
    ///
    /// Example 2:
    /// Input: street = ".H.H."
    /// Output: 1
    /// Explanation:
    /// We can put a bucket at index 2.
    /// ".H.H." -> ".HBH." ('B' denotes where a bucket is placed).
    /// The house at index 1 has a bucket to its right, and the house at 
    /// index 3 has a bucket to its left.
    /// Thus, for every house, there is at least one bucket collecting 
    /// rainwater from it.
    ///
    /// Example 3:
    /// Input: street = ".HHH."
    /// Output: -1
    /// Explanation:
    /// There is no empty space to place a bucket to collect the rainwater 
    /// from the house at index 2.
    /// Thus, it is impossible to collect the rainwater from all the houses.
    ///
    /// Example 4:
    /// Input: street = "H"
    /// Output: -1
    /// Explanation:
    /// There is no empty space to place a bucket.
    /// Thus, it is impossible to collect the rainwater from the house.
    ///
    /// Example 5:
    /// Input: street = "."
    /// Output: 0
    /// Explanation:
    /// There is no house to collect water from.
    /// Thus, 0 buckets are needed.
    ///
    /// Constraints:
    /// 1. 1 <= street.length <= 10^5
    /// 2. street[i] is either'H' or '.'.
    /// </summary>
    int minimumBuckets(string street);

    /// <summary>
    /// Leet Code 2017. Grid Game
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed 2D array grid of size 2 x n, where 
    /// grid[r][c] represents the number of points at position (r, c) 
    /// on the matrix. Two robots are playing a game on this matrix.
    ///
    /// Both robots initially start at (0, 0) and want to reach (1, n-1). 
    /// Each robot may only move to the right ((r, c) to (r, c + 1)) or 
    /// down ((r, c) to (r + 1, c)).
    ///
    /// At the start of the game, the first robot moves from (0, 0) to 
    /// (1, n-1), collecting all the points from the cells on its path. 
    /// For all cells (r, c) traversed on the path, grid[r][c] is set 
    /// to 0. Then, the second robot moves from (0, 0) to (1, n-1), 
    /// collecting the points on its path. Note that their paths may 
    /// intersect with one another.
    /// The first robot wants to minimize the number of points collected 
    /// by the second robot. In contrast, the second robot wants to 
    /// maximize the number of points it collects. If both robots play 
    /// optimally, return the number of points collected by the second robot.
    /// 
    /// Example 1:
    /// Input: grid = [[2,5,4],[1,5,1]]
    /// Output: 4
    /// Explanation: The optimal path taken by the first robot is shown in 
    /// red, and the optimal path taken by the second robot is shown in blue.
    /// The cells visited by the first robot are set to 0.
    /// The second robot will collect 0 + 0 + 4 + 0 = 4 points.
    ///
    /// Example 2:
    /// Input: grid = [[3,3,1],[8,5,2]]
    /// Output: 4
    /// Explanation: The optimal path taken by the first robot is shown in red, 
    /// and the optimal path taken by the second robot is shown in blue.
    /// The cells visited by the first robot are set to 0.
    /// The second robot will collect 0 + 3 + 1 + 0 = 4 points.
    ///
    /// Example 3:
    /// Input: grid = [[1,3,1,15],[1,3,3,1]]
    /// Output: 7
    /// Explanation: The optimal path taken by the first robot is shown in red, 
    /// and the optimal path taken by the second robot is shown in blue.
    /// The cells visited by the first robot are set to 0.
    /// The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
    /// 
    /// Constraints:
    /// 1. grid.length == 2
    /// 2. n == grid[r].length
    /// 3. 1 <= n <= 5 * 10^4
    /// 4. 1 <= grid[r][c] <= 10^5
    /// </summary>
    long long gridGame(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2073. Time Needed to Buy Tickets
    ///                                                                 
    /// Easy
    ///
    /// There are n people in a line queuing to buy tickets, where the 0th 
    /// person is at the front of the line and the (n - 1)th person is at 
    /// the back of the line.
    ///
    /// You are given a 0-indexed integer array tickets of length n where 
    /// the number of tickets that the ith person would like to buy is 
    /// tickets[i].
    ///
    /// Each person takes exactly 1 second to buy a ticket. A person can 
    /// only buy 1 ticket at a time and has to go back to the end of the 
    /// line (which happens instantaneously) in order to buy more tickets. 
    /// If a person does not have any tickets left to buy, the person will 
    /// leave the line.
    ///
    /// Return the time taken for the person at position k (0-indexed) to 
    /// finish buying tickets.
    /// 
    /// Example 1:
    /// Input: tickets = [2,3,2], k = 2
    /// Output: 6
    /// Explanation: 
    /// - In the first pass, everyone in the line buys a ticket and the line 
    /// becomes [1, 2, 1].
    /// - In the second pass, everyone in the line buys a ticket and the 
    /// line becomes [0, 1, 0].
    /// The person at position 2 has successfully bought 2 tickets and it 
    /// took 3 + 3 = 6 seconds.
    ///
    /// Example 2:
    /// Input: tickets = [5,1,1,1], k = 0
    /// Output: 8
    /// Explanation:
    /// - In the first pass, everyone in the line buys a ticket and the line 
    ///   becomes [4, 0, 0, 0].
    /// - In the next 4 passes, only the person in position 0 is buying 
    ///   tickets.
    /// The person at position 0 has successfully bought 5 tickets and it 
    /// took 4 + 1 + 1 + 1 + 1 = 8 seconds.
    ///
    /// Constraints:
    /// 1. n == tickets.length
    /// 2. 1 <= n <= 100
    /// 3. 1 <= tickets[i] <= 100
    /// 4. 0 <= k < n
    /// </summary>
    int timeRequiredToBuy(vector<int>& tickets, int k);

    /// <summary>
    /// Leet Code 1868. Product of Two Run-Length Encoded Arrays
    ///                                                                 
    /// Medium
    ///
    /// Run-length encoding is a compression algorithm that allows for an 
    /// integer array nums with many segments of consecutive repeated 
    /// numbers to be represented by a (generally smaller) 2D array 
    /// encoded. Each encoded[i] = [vali, freqi] describes the ith 
    /// segment of repeated numbers in nums where vali is the value that 
    /// is repeated freqi times.
    ///
    /// For example, nums = [1,1,1,2,2,2,2,2] is represented by the 
    /// run-length encoded array encoded = [[1,3],[2,5]]. Another way to 
    /// read this is "three 1's followed by five 2's".
    /// The product of two run-length encoded arrays encoded1 and encoded2 
    /// can be calculated using the following steps:
    ///
    /// Expand both encoded1 and encoded2 into the full arrays nums1 and 
    /// nums2 respectively.
    /// Create a new array prodNums of length nums1.length and set 
    /// prodNums[i] = nums1[i] * nums2[i].
    /// Compress prodNums into a run-length encoded array and return it.
    /// You are given two run-length encoded arrays encoded1 and encoded2 
    /// representing full arrays nums1 and nums2 respectively. Both nums1 
    /// and nums2 have the same length. Each encoded1[i] = [vali, freqi] 
    /// describes the ith segment of nums1, and each encoded2[j] = 
    /// [valj, freqj] describes the jth segment of nums2.
    ///
    /// Return the product of encoded1 and encoded2.
    ///
    /// Note: Compression should be done such that the run-length encoded 
    /// array has the minimum possible length.
    /// 
    /// Example 1:
    /// Input: encoded1 = [[1,3],[2,3]], encoded2 = [[6,3],[3,3]]
    /// Output: [[6,6]]
    /// Explanation: encoded1 expands to [1,1,1,2,2,2] and encoded2 
    /// expands to [6,6,6,3,3,3].
    /// prodNums = [6,6,6,6,6,6], which is compressed into the run-length 
    /// encoded array [[6,6]].
    ///
    /// Example 2:
    /// Input: encoded1 = [[1,3],[2,1],[3,2]], encoded2 = [[2,3],[3,3]]
    /// Output: [[2,3],[6,1],[9,2]]
    /// Explanation: encoded1 expands to [1,1,1,2,3,3] and encoded2 expands 
    /// to [2,2,2,3,3,3].
    /// prodNums = [2,2,2,6,9,9], which is compressed into the run-length 
    /// encoded array [[2,3],[6,1],[9,2]].
    /// 
    /// Constraints:
    /// 1. 1 <= encoded1.length, encoded2.length <= 10^5
    /// 2. encoded1[i].length == 2
    /// 3. encoded2[j].length == 2
    /// 4. 1 <= vali, freqi <= 10^4 for each encoded1[i].
    /// 5. 1 <= valj, freqj <= 10^4 for each encoded2[j].
    /// 6. The full arrays that encoded1 and encoded2 represent are the same 
    ///    length.
    /// </summary>
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2);

    /// <summary>
    /// Leet Code 1885. Count Pairs in Two Arrays
    ///                                                                 
    /// Medium
    ///
    /// Given two integer arrays nums1 and nums2 of length n, count the pairs 
    /// of indices (i, j) such that i < j and 
    /// nums1[i] + nums1[j] > nums2[i] + nums2[j].
    ///
    /// Return the number of pairs satisfying the condition.
    ///
    /// Example 1:
    /// Input: nums1 = [2,1,2,1], nums2 = [1,2,1,2]
    /// Output: 1
    /// Explanation: The pairs satisfying the condition are:
    /// - (0, 2) where 2 + 2 > 1 + 1.
    ///
    /// Example 2:
    /// Input: nums1 = [1,10,6,2], nums2 = [1,4,1,5]
    /// Output: 5
    /// Explanation: The pairs satisfying the condition are:
    /// - (0, 1) where 1 + 10 > 1 + 4.
    /// - (0, 2) where 1 + 6 > 1 + 1.
    /// - (1, 2) where 10 + 6 > 4 + 1.
    /// - (1, 3) where 10 + 2 > 4 + 5.
    /// - (2, 3) where 6 + 2 > 1 + 5.
    /// 
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums1[i], nums2[i] <= 10^5
    /// </summary>
    long long countPairs(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 1940. Longest Common Subsequence Between Sorted Arrays
    ///                                                                 
    /// Medium
    ///
    /// Given an array of integer arrays arrays where each arrays[i] is 
    /// sorted in strictly increasing order, return an integer array 
    /// representing the longest common subsequence between all the arrays.
    ///
    /// A subsequence is a sequence that can be derived from another 
    /// sequence by deleting some elements (possibly none) without 
    /// changing the order of the remaining elements.
    /// 
    /// Example 1:
    /// Input: arrays = [[1,3,4],
    ///                  [1,4,7,9]]
    /// Output: [1,4]
    /// Explanation: The longest common subsequence in the two arrays 
    ///              is [1,4].
    ///
    /// Example 2:
    /// Input: arrays = [[2,3,6,8],
    ///                  [1,2,3,5,6,7,10],
    ///                  [2,3,4,6,9]]
    /// Output: [2,3,6]
    /// Explanation: The longest common subsequence in all three arrays 
    /// is [2,3,6].
    ///
    /// Example 3:
    /// Input: arrays = [[1,2,3,4,5],
    ///                  [6,7,8]]
    /// Output: []
    /// Explanation: There is no common subsequence between the two arrays.
    ///
    /// Constraints:
    /// 1. 2 <= arrays.length <= 100
    /// 2. 1 <= arrays[i].length <= 100
    /// 3. 1 <= arrays[i][j] <= 100
    /// 4. arrays[i] is sorted in strictly increasing order.
    /// </summary>
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays);

    /// <summary>
    /// Leet Code 2007. Find Original Array From Doubled Array
    ///                                                                 
    /// Medium
    ///
    /// An integer array original is transformed into a doubled array changed 
    /// by appending twice the value of every element in original, and then 
    /// randomly shuffling the resulting array.
    ///
    /// Given an array changed, return original if changed is a doubled array. 
    /// If changed is not a doubled array, return an empty array. The elements 
    /// in original may be returned in any order.
    /// 
    /// Example 1:
    /// Input: changed = [1,3,4,2,6,8]
    /// Output: [1,3,4]
    /// Explanation: One possible original array could be [1,3,4]:
    /// - Twice the value of 1 is 1 * 2 = 2.
    /// - Twice the value of 3 is 3 * 2 = 6.
    /// - Twice the value of 4 is 4 * 2 = 8.
    /// Other original arrays could be [4,3,1] or [3,1,4].
    ///
    /// Example 2:
    /// Input: changed = [6,3,0,1]
    /// Output: []
    /// Explanation: changed is not a doubled array.
    ///
    /// Example 3:
    /// Input: changed = [1]
    /// Output: []
    /// Explanation: changed is not a doubled array.
    /// 
    /// Constraints:
    /// 1. 1 <= changed.length <= 10^5
    /// 2. 0 <= changed[i] <= 10^5
    /// </summary>
    vector<int> findOriginalArray(vector<int>& changed);

    /// <summary>
    /// Leet Code 2099. Find Subsequence of Length K With the Largest Sum 
    ///                                                                 
    /// Easy
    ///
    /// You are given an integer array nums and an integer k. You want to find 
    /// a subsequence of nums of length k that has the largest sum.
    ///
    /// Return any such subsequence as an integer array of length k.
    ///
    /// A subsequence is an array that can be derived from another array by 
    /// deleting some or no elements without changing the order of the 
    /// remaining elements.
    ///
    /// Example 1:
    /// Input: nums = [2,1,3,3], k = 2
    /// Output: [3,3]
    /// Explanation:
    /// The subsequence has the largest sum of 3 + 3 = 6.
    ///
    /// Example 2:
    /// Input: nums = [-1,-2,3,4], k = 3
    /// Output: [-1,3,4]
    /// Explanation: 
    /// The subsequence has the largest sum of -1 + 3 + 4 = 6.
    ///
    /// Example 3:
    /// Input: nums = [3,4,3,3], k = 2
    /// Output: [3,4]
    /// Explanation:
    /// The subsequence has the largest sum of 3 + 4 = 7. 
    /// Another possible subsequence is [4, 3].
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. -10^5 <= nums[i] <= 10^5
    /// 3. 1 <= k <= nums.length
    /// </summary>
    vector<int> maxSubsequence(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2103. Rings and Rods
    ///                                                                 
    /// Easy
    ///
    /// There are n rings and each ring is either red, green, or blue. The 
    /// rings are distributed across ten rods labeled from 0 to 9.
    ///
    /// You are given a string rings of length 2n that describes the n rings 
    /// that are placed onto the rods. Every two characters in rings forms 
    /// a color-position pair that is used to describe each ring where:
    ///
    /// The first character of the ith pair denotes the ith ring's color 
    /// ('R', 'G', 'B').
    /// The second character of the ith pair denotes the rod that the ith 
    /// ring is placed on ('0' to '9').
    /// For example, "R3G2B1" describes n == 3 rings: a red ring placed 
    /// onto the rod labeled 3, a green ring placed onto the rod labeled 2, 
    /// and a blue ring placed onto the rod labeled 1.
    ///
    /// Return the number of rods that have all three colors of rings on them.
    /// 
    /// Example 1:
    /// Input: rings = "B0B6G0R6R0R6G9"
    /// Output: 1 
    /// Explanation: 
    /// - The rod labeled 0 holds 3 rings with all colors: red, green, and 
    ///   blue.
    /// - The rod labeled 6 holds 3 rings, but it only has red and blue.
    /// - The rod labeled 9 holds only a green ring.
    /// Thus, the number of rods with all three colors is 1.
    ///
    /// Example 2:
    /// Input: rings = "B0R0G0R9R0B0G0"
    /// Output: 1
    /// Explanation: 
    /// - The rod labeled 0 holds 6 rings with all colors: red, green, and 
    ///   blue.
    /// - The rod labeled 9 holds only a red ring.
    /// Thus, the number of rods with all three colors is 1.
    ///
    /// Example 3:
    /// Input: rings = "G4"
    /// Output: 0
    /// Explanation: 
    /// Only one ring is given. Thus, no rods have all three colors.
    ///
    /// Constraints:
    /// 1. rings.length == 2 * n
    /// 2. 1 <= n <= 100
    /// 3. rings[i] where i is even is either 'R', 'G', or 'B' (0-indexed).
    /// 4. rings[i] where i is odd is a digit from '0' to '9' (0-indexed).
    /// </summary>
    int countPoints(string rings);

    /// <summary>
    /// Leet Code 1983. Widest Pair of Indices With Equal Range Sum
    ///                                                                 
    /// Medium
    ///
    /// You are given two 0-indexed binary arrays nums1 and nums2. Find the 
    /// widest pair of indices (i, j) such that i <= j and nums1[i] + 
    /// nums1[i+1] + ... + nums1[j] == nums2[i] + nums2[i+1] + ... + nums2[j].
    ///
    /// The widest pair of indices is the pair with the largest distance 
    /// between i and j. The distance between a pair of indices is defined as 
    /// j - i + 1.
    ///
    /// Return the distance of the widest pair of indices. If no pair of 
    /// indices meets the conditions, return 0.
    ///
    /// Example 1:
    /// Input: nums1 = [1,1,0,1], nums2 = [0,1,1,0]
    /// Output: 3
    /// Explanation:
    /// If i = 1 and j = 3:
    /// nums1[1] + nums1[2] + nums1[3] = 1 + 0 + 1 = 2.
    /// nums2[1] + nums2[2] + nums2[3] = 1 + 1 + 0 = 2.
    /// The distance between i and j is j - i + 1 = 3 - 1 + 1 = 3.
    ///
    /// Example 2:
    /// Input: nums1 = [0,1], nums2 = [1,1]
    /// Output: 1
    /// Explanation:
    /// If i = 1 and j = 1:
    /// nums1[1] = 1.
    /// nums2[1] = 1.
    /// The distance between i and j is j - i + 1 = 1 - 1 + 1 = 1.
    ///
    /// Example 3:
    /// Input: nums1 = [0], nums2 = [1]
    /// Output: 0
    /// Explanation:
    /// There are no pairs of indices that meet the requirements.
    ///
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 1 <= n <= 10^5
    /// 3. nums1[i] is either 0 or 1.
    /// 4. nums2[i] is either 0 or 1.
    /// </summary>
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2012. Sum of Beauty in the Array
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums. For each index i 
    /// (1 <= i <= nums.length - 2) the beauty of nums[i] equals:
    /// 2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for 
    /// all i < k <= nums.length - 1.
    /// 1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous 
    /// condition is not satisfied.
    /// 0, if none of the previous conditions holds.
    /// Return the sum of beauty of all nums[i] 
    /// where 1 <= i <= nums.length - 2.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3]
    /// Output: 2
    /// Explanation: For each index i in the range 1 <= i <= 1:
    /// - The beauty of nums[1] equals 2.
    ///
    /// Example 2:
    /// Input: nums = [2,4,6,4]
    /// Output: 1
    /// Explanation: For each index i in the range 1 <= i <= 2:
    /// - The beauty of nums[1] equals 1.
    /// - The beauty of nums[2] equals 0.
    ///
    /// Example 3:
    /// Input: nums = [3,2,1]
    /// Output: 0
    /// Explanation: For each index i in the range 1 <= i <= 1:
    /// - The beauty of nums[1] equals 0.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int sumOfBeauties(vector<int>& nums);

    /// <summary>
    /// Leet Code 2055. Plates Between Candles
    ///                                                                 
    /// Medium
    ///
    /// There is a long table with a line of plates and candles arranged on 
    /// top of it. You are given a 0-indexed string s consisting of 
    /// characters '*' and '|' only, where a '*' represents a plate and 
    /// a '|' represents a candle.
    ///
    /// You are also given a 0-indexed 2D integer array queries where 
    /// queries[i] = [lefti, righti] denotes the substring s[lefti...righti] 
    /// (inclusive). For each query, you need to find the number of plates 
    /// between candles that are in the substring. A plate is considered 
    /// between candles if there is at least one candle to its left and at 
    /// least one candle to its right in the substring.
    ///
    /// For example, s = "||**||**|*", and a query [3, 8] denotes the 
    /// substring "*||**|". The number of plates between candles in this 
    /// substring is 2, as each of the two plates has at least one candle 
    /// in the substring to its left and right.
    /// Return an integer array answer where answer[i] is the answer to the 
    /// ith query.
    ///
    /// Example 1:
    /// Input: s = "**|**|***|", queries = [[2,5],[5,9]]
    /// Output: [2,3]
    /// Explanation:
    /// - queries[0] has two plates between candles.
    /// - queries[1] has three plates between candles.
    ///
    /// Example 2:
    /// Input: s = "***|**|*****|**||**|*", 
    /// queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
    /// Output: [9,0,0,0,0]
    /// Explanation:
    /// - queries[0] has nine plates between candles.
    /// - The other queries have zero plates between candles.
    /// Constraints:
    /// 1. 3 <= s.length <= 10^5
    /// 2. s consists of '*' and '|' characters.
    /// 3. 1 <= queries.length <= 10^5
    /// 4. queries[i].length == 2
    /// 5. 0 <= lefti <= righti < s.length
    /// </summary>
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2028. Find Missing Observations
    ///                                                                 
    /// Medium
    ///
    /// You have observations of n + m 6-sided dice rolls with each face 
    /// numbered from 1 to 6. n of the observations went missing, and you 
    /// only have the observations of m rolls. Fortunately, you have also 
    /// calculated the average value of the n + m rolls.
    ///
    /// You are given an integer array rolls of length m where rolls[i] 
    /// is the value of the ith observation. You are also given the two 
    /// integers mean and n.
    ///
    /// Return an array of length n containing the missing observations 
    /// such that the average value of the n + m rolls is exactly mean. 
    /// If there are multiple valid answers, return any of them. If no 
    /// such array exists, return an empty array.
    ///
    /// The average value of a set of k numbers is the sum of the 
    /// numbers divided by k.
    /// 
    /// Note that mean is an integer, so the sum of the n + m rolls should 
    /// be divisible by n + m.
    /// 
    /// Example 1:
    /// Input: rolls = [3,2,4,3], mean = 4, n = 2
    /// Output: [6,6]
    /// Explanation: The mean of all n + m rolls is 
    /// (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
    ///
    /// Example 2:
    /// Input: rolls = [1,5,6], mean = 3, n = 4
    /// Output: [2,3,2,2]
    /// Explanation: The mean of all n + m rolls is 
    /// (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
    ///
    /// Example 3:
    /// Input: rolls = [1,2,3,4], mean = 6, n = 4
    /// Output: []
    /// Explanation: It is impossible for the mean to be 6 no matter 
    /// what the 4 missing rolls are.
    ///
    /// Example 4:
    /// Input: rolls = [1], mean = 3, n = 1
    /// Output: [5]
    /// Explanation: The mean of all n + m rolls is (1 + 5) / 2 = 3.
    /// 
    /// Constraints:
    /// 1. m == rolls.length
    /// 2. 1 <= n, m <= 10^5
    /// 3. 1 <= rolls[i], mean <= 6
    /// </summary>
    vector<int> missingRolls(vector<int>& rolls, int mean, int n);

    /// <summary>
    /// Leet Code 2091. Removing Minimum and Maximum From Array
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed array of distinct integers nums.
    ///
    /// There is an element in nums that has the lowest value and an element 
    /// that has the highest value. We call them the minimum and maximum 
    /// respectively. Your goal is to remove both these elements from the 
    /// array.
    ///
    /// A deletion is defined as either removing an element from the front of 
    /// the array or removing an element from the back of the array.
    ///
    /// Return the minimum number of deletions it would take to remove both 
    /// the minimum and maximum element from the array.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [2,10,7,5,4,1,8,6]
    /// Output: 5
    /// Explanation: 
    /// The minimum element in the array is nums[5], which is 1.
    /// The maximum element in the array is nums[1], which is 10.
    /// We can remove both the minimum and maximum by removing 2 elements from 
    /// the front and 3 elements from the back.
    /// This results in 2 + 3 = 5 deletions, which is the minimum number 
    /// possible.
    ///
    /// Example 2:
    /// Input: nums = [0,-4,19,1,8,-2,-3,5]
    /// Output: 3
    /// Explanation: 
    /// The minimum element in the array is nums[1], which is -4.
    /// The maximum element in the array is nums[2], which is 19.
    /// We can remove both the minimum and maximum by removing 3 elements 
    /// from the front.
    /// This results in only 3 deletions, which is the minimum number possible.
    ///
    /// Example 3:
    /// Input: nums = [101]
    /// Output: 1
    /// Explanation:  
    /// There is only one element in the array, which makes it both the 
    /// minimum and maximum element.
    /// We can remove it with 1 deletion.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^5 <= nums[i] <= 10^5
    /// 3. The integers in nums are distinct.
    /// </summary>
    int minimumDeletions(vector<int>& nums);

    /// <summary>
    /// Leet Code 2113. Elements in Array After Removing and Replacing Elements
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums. Initially on minute 0, 
    /// the array is unchanged. Every minute, the leftmost element in nums is 
    /// removed until no elements remain. Then, every minute, one element is 
    /// appended to the end of nums, in the order they were removed in, until 
    /// the original array is restored. This process repeats indefinitely.
    ///
    /// For example, the array [0,1,2] would change as follows: [0,1,2] -> 
    /// [1,2] -> [2] -> [] -> [0] -> [0,1] -> [0,1,2] -> [1,2] -> [2] -> 
    /// [] -> [0] -> [0,1] -> [0,1,2] -> ...
    /// You are also given a 2D integer array queries of size n where 
    /// queries[j] = [timej, indexj]. The answer to the jth query is:
    ///
    /// nums[indexj] if indexj < nums.length at minute timej
    /// -1 if indexj >= nums.length at minute timej
    /// Return an integer array ans of size n where ans[j] is the answer 
    /// to the jth query.
    /// 
    /// Example 1:
    /// Input: nums = [0,1,2], queries = [[0,2],[2,0],[3,2],[5,0]]
    /// Output: [2,2,-1,0]
    /// Explanation:
    /// Minute 0: [0,1,2] - All elements are in the nums.
    /// Minute 1: [1,2]   - The leftmost element, 0, is removed.
    /// Minute 2: [2]     - The leftmost element, 1, is removed.
    /// Minute 3: []      - The leftmost element, 2, is removed.
    /// Minute 4: [0]     - 0 is added to the end of nums.
    /// Minute 5: [0,1]   - 1 is added to the end of nums.
    ///
    /// At minute 0, nums[2] is 2.
    /// At minute 2, nums[0] is 2.
    /// At minute 3, nums[2] does not exist.
    /// At minute 5, nums[0] is 0.
    ///
    /// Example 2:
    /// Input: nums = [2], queries = [[0,0],[1,0],[2,0],[3,0]]
    /// Output: [2,-1,2,-1]
    /// Minute 0: [2] - All elements are in the nums.
    /// Minute 1: []  - The leftmost element, 2, is removed.
    /// Minute 2: [2] - 2 is added to the end of nums.
    /// Minute 3: []  - The leftmost element, 2, is removed.
    ///
    /// At minute 0, nums[0] is 2.
    /// At minute 1, nums[0] does not exist.
    /// At minute 2, nums[0] is 2.
    /// At minute 3, nums[0] does not exist.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 0 <= nums[i] <= 100
    /// 3. n == queries.length
    /// 4. 1 <= n <= 10^5
    /// 5. queries[j].length == 2
    /// 6. 0 <= timej <= 10^5
    /// 7. 0 <= indexj < nums.length
    /// </summary>
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2100. Find Good Days to Rob the Bank
    ///                                                                 
    /// Medium
    ///
    /// You and a gang of thieves are planning on robbing a bank. You are 
    /// given a 0-indexed integer array security, where security[i] is the 
    /// number of guards on duty on the ith day. The days are numbered 
    /// starting from 0. You are also given an integer time.
    ///
    /// The ith day is a good day to rob the bank if:
    /// There are at least time days before and after the ith day,
    /// The number of guards at the bank for the time days before i 
    /// are non-increasing, and
    /// The number of guards at the bank for the time days after i are 
    /// non-decreasing.
    /// More formally, this means day i is a good day to rob the bank 
    /// if and only if security[i - time] >= security[i - time + 1] 
    /// >= ... >= security[i] <= ... <= security[i + time - 1] <= 
    /// security[i + time].
    ///
    /// Return a list of all days (0-indexed) that are good days to rob the 
    /// bank. The order that the days are returned in does not matter.
    ///
    /// Example 1:
    /// Input: security = [5,3,3,3,5,6,2], time = 2
    /// Output: [2,3]
    /// Explanation:
    /// On day 2, we have security[0] >= security[1] >= security[2] 
    /// <= security[3] <= security[4].
    /// On day 3, we have security[1] >= security[2] >= security[3] 
    /// <= security[4] <= security[5].
    /// No other days satisfy this condition, so days 2 and 3 are 
    /// the only good days to rob the bank.
    ///
    /// Example 2:
    /// Input: security = [1,1,1,1,1], time = 0
    /// Output: [0,1,2,3,4]
    /// Explanation:
    /// Since time equals 0, every day is a good day to rob the bank, 
    /// so return every day.
    ///
    /// Example 3:
    /// Input: security = [1,2,3,4,5,6], time = 2
    /// Output: []
    /// Explanation:
    /// No day has 2 days before it that have a non-increasing number 
    /// of guards.
    /// Thus, no day is a good day to rob the bank, so return an empty list.
    ///
    /// Constraints:
    /// 1. 1 <= security.length <= 10^5
    /// 2. 0 <= security[i], time <= 10^5
    /// </summary>
    vector<int> goodDaysToRobBank(vector<int>& security, int time);

    /// <summary>
    /// Leet Code 2024. Maximize the Confusion of an Exam
    ///                                                                 
    /// Medium
    ///
    /// A teacher is writing a test with n true/false questions, with 'T' 
    /// denoting true and 'F' denoting false. He wants to confuse the 
    /// students by maximizing the number of consecutive questions with 
    /// the same answer (multiple trues or multiple falses in a row).
    ///
    /// You are given a string answerKey, where answerKey[i] is the 
    /// original answer to the ith question. In addition, you are given 
    /// an integer k, the maximum number of times you may perform the 
    /// following operation:
    ///
    /// Change the answer key for any question to 'T' or 'F' (i.e., 
    /// set answerKey[i] to 'T' or 'F').
    /// Return the maximum number of consecutive 'T's or 'F's in the 
    /// answer key after performing the operation at most k times.
    /// 
    /// Example 1:
    /// Input: answerKey = "TTFF", k = 2
    /// Output: 4
    /// Explanation: We can replace both the 'F's with 'T's to make 
    /// answerKey = "TTTT".
    /// There are four consecutive 'T's.
    ///
    /// Example 2:
    /// Input: answerKey = "TFFT", k = 1
    /// Output: 3
    /// Explanation: We can replace the first 'T' with an 'F' to make 
    /// answerKey = "FFFT".
    /// Alternatively, we can replace the second 'T' with an 'F' to make 
    /// answerKey = "TFFF".
    /// In both cases, there are three consecutive 'F's.
    ///
    /// Example 3:
    /// Input: answerKey = "TTFTTFTT", k = 1
    /// Output: 5
    /// Explanation: We can replace the first 'F' to make 
    /// answerKey = "TTTTTFTT"
    /// Alternatively, we can replace the second 'F' to make 
    /// answerKey = "TTFTTTTT". 
    /// In both cases, there are five consecutive 'T's.
    ///
    /// Constraints:
    /// 1. n == answerKey.length
    /// 2. 1 <= n <= 5 * 10^4
    /// 3. answerKey[i] is either 'T' or 'F'
    /// 4. 1 <= k <= n
    /// </summary>
    int maxConsecutiveAnswers(string answerKey, int k);

    /// <summary>
    /// Leet Code 2031. Count Subarrays With More Ones Than Zeros
    ///                                                                 
    /// Medium
    ///
    /// You are given a binary array nums containing only the integers 0 
    /// and 1. Return the number of subarrays in nums that have more 1's 
    /// than 0's. Since the answer may be very large, return it modulo 
    /// 10^9 + 7.
    ///
    /// A subarray is a contiguous sequence of elements within an array.
    /// 
    /// Example 1:
    /// Input: nums = [0,1,1,0,1]
    /// Output: 9
    /// Explanation:
    /// The subarrays of size 1 that have more ones than zeros 
    /// are: [1], [1], [1]
    /// The subarrays of size 2 that have more ones than zeros 
    /// are: [1,1]
    /// The subarrays of size 3 that have more ones than zeros 
    /// are: [0,1,1], [1,1,0], [1,0,1]
    /// The subarrays of size 4 that have more ones than zeros 
    /// are: [1,1,0,1]
    /// The subarrays of size 5 that have more ones than zeros 
    /// are: [0,1,1,0,1]
    ///
    /// Example 2:
    /// Input: nums = [0]
    /// Output: 0
    /// Explanation:
    /// No subarrays have more ones than zeros.
    /// Example 3:
    /// Input: nums = [1]
    /// Output: 1
    /// Explanation:
    /// The subarrays of size 1 that have more ones than zeros are: [1]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 1
    /// </summary>
    int subarraysWithMoreZerosThanOnes(vector<int>& nums);


    /// <summary>
    /// Leet Code 2063. Vowels of All Substrings
    ///                                                                 
    /// Medium
    ///
    /// Given a string word, return the sum of the number of vowels ('a', 
    /// 'e', 'i', 'o', and 'u') in every substring of word.
    ///
    /// A substring is a contiguous (non-empty) sequence of characters 
    /// within a string.
    ///
    /// Note: Due to the large constraints, the answer may not fit in a 
    /// signed 32-bit integer. Please be careful during the calculations.
    ///
    /// Example 1:
    /// Input: word = "aba"
    /// Output: 6
    /// Explanation: 
    /// All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
    /// - "b" has 0 vowels in it
    /// - "a", "ab", "ba", and "a" have 1 vowel each
    /// - "aba" has 2 vowels in it
    /// Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
    ///
    /// Example 2:
    /// Input: word = "abc"
    /// Output: 3
    /// Explanation: 
    /// All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
    /// - "a", "ab", and "abc" have 1 vowel each
    /// - "b", "bc", and "c" have 0 vowels each
    /// Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3. 
    ///
    /// Example 3:
    /// Input: word = "ltcd"
    /// Output: 0
    /// Explanation: There are no vowels in any substring of "ltcd".
    ///
    /// Example 4:
    /// Input: word = "noosabasboosa"
    /// Output: 237
    /// Explanation: There are a total of 237 vowels in all the substrings.
    /// 
    /// Constraints:
    /// 1. 1 <= word.length <= 10^5
    /// 2. word consists of lowercase English letters.
    /// </summary>
    long long countVowels(string word);

    /// <summary>
    /// Leet Code 2110. Number of Smooth Descent Periods of a Stock
    ///                                                                 
    /// Medium
    ///
    /// You are given an integer array prices representing the daily price 
    /// history of a stock, where prices[i] is the stock price on the ith day.
    ///
    /// A smooth descent period of a stock consists of one or more contiguous 
    /// days such that the price on each day is lower than the price on the 
    /// preceding day by exactly 1. The first day of the period is exempted 
    /// from this rule.
    ///
    /// Return the number of smooth descent periods.
    ///
    /// Example 1:
    /// Input: prices = [3,2,1,4]
    /// Output: 7
    /// Explanation: There are 7 smooth descent periods:
    /// [3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
    /// Note that a period with one day is a smooth descent period by the 
    /// definition.
    ///
    /// Example 2:
    /// Input: prices = [8,6,7,7]
    /// Output: 4
    /// Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
    /// Note that [8,6] is not a smooth descent period as 8 - 6 != 1.
    ///
    /// Example 3:
    /// Input: prices = [1]
    /// Output: 1
    /// Explanation: There is 1 smooth descent period: [1]
    ///
    /// Constraints:
    /// 1. 1 <= prices.length <= 10^5
    /// 2. 1 <= prices[i] <= 10^5
    /// </summary>
    long long getDescentPeriods(vector<int>& prices);


    /// <summary>
    /// Leet Code 2033. Minimum Operations to Make a Uni-Value Grid
    ///                                                                 
    /// Medium
    ///
    /// You are given a 2D integer grid of size m x n and an integer x. In one 
    /// operation, you can add x to or subtract x from any element in the grid.
    ///
    /// A uni-value grid is a grid where all the elements of it are equal.
    /// Return the minimum number of operations to make the grid uni-value. 
    /// If it is not possible, return -1.
    ///
    /// Example 1:
    /// Input: grid = [[2,4],[6,8]], x = 2
    /// Output: 4
    /// Explanation: We can make every element equal to 4 by doing the following: 
    /// - Add x to 2 once.
    /// - Subtract x from 6 once.
    /// - Subtract x from 8 twice.
    /// A total of 4 operations were used.
    ///
    /// Example 2:
    /// Input: grid = [[1,5],[2,3]], x = 1
    /// Output: 5
    /// Explanation: We can make every element equal to 3.
    ///
    /// Example 3:
    /// Input: grid = [[1,2],[3,4]], x = 2
    /// Output: -1
    /// Explanation: It is impossible to make every element equal.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 10^5
    /// 4. 1 <= m * n <= 10^5
    /// 5. 1 <= x, grid[i][j] <= 10^4
    /// </summary>
    int minOperations(vector<vector<int>>& grid, int x);

    /// <summary>
    /// Leet Code 2120. Execution of All Suffix Instructions Staying in a Grid
    ///                                                                 
    /// Medium
    ///
    /// There is an n x n grid, with the top-left cell at (0, 0) and the 
    /// bottom-right cell at (n - 1, n - 1). You are given the integer n and 
    /// an integer array startPos where startPos = [startrow, startcol] 
    /// indicates that a robot is initially at cell (startrow, startcol).
    ///
    /// You are also given a 0-indexed string s of length m where s[i] is 
    /// the ith instruction for the robot: 'L' (move left), 'R' (move right), 
    /// 'U' (move up), and 'D' (move down).
    ///
    /// The robot can begin executing from any ith instruction in s. It 
    /// executes the instructions one by one towards the end of s but it 
    /// stops if either of these conditions is met:
    ///
    /// The next instruction will move the robot off the grid.
    /// There are no more instructions left to execute.
    /// Return an array answer of length m where answer[i] is the number of 
    /// instructions the robot can execute if the robot begins executing 
    /// from the ith instruction in s.
    /// 
    /// Example 1:
    /// Input: n = 3, startPos = [0,1], s = "RRDDLU"
    /// Output: [1,5,4,3,1,0]
    /// Explanation: Starting from startPos and beginning execution from the 
    /// ith instruction:
    /// - 0th: "RRDDLU". Only one instruction "R" can be executed before it 
    ///   moves off the grid.
    /// - 1st:  "RDDLU". All five instructions can be executed while it stays 
    ///   in the grid and ends at (1, 1).
    /// - 2nd:   "DDLU". All four instructions can be executed while it 
    ///   stays in the grid and ends at (1, 0).
    /// - 3rd:    "DLU". All three instructions can be executed while it 
    ///   stays in the grid and ends at (0, 0).
    /// - 4th:     "LU". Only one instruction "L" can be executed 
    ///   before it moves off the grid.
    /// - 5th:      "U". If moving up, it would move off the grid.
    ///
    /// Example 2:
    /// Input: n = 2, startPos = [1,1], s = "LURD"
    /// Output: [4,1,0,0]
    /// Explanation:
    /// - 0th: "LURD".
    /// - 1st:  "URD".
    /// - 2nd:   "RD".
    /// - 3rd:    "D".
    ///
    /// Example 3:
    /// Input: n = 1, startPos = [0,0], s = "LRUD"
    /// Output: [0,0,0,0]
    /// Explanation: No matter which instruction the robot begins execution 
    /// from, it would move off the grid.
    ///
    /// Constraints:
    /// 1. m == s.length
    /// 2. 1 <= n, m <= 500
    /// 3. startPos.length == 2
    /// 4. 0 <= startrow, startcol < n
    /// 5. s consists of 'L', 'R', 'U', and 'D'.
    /// </summary>
    vector<int> executeInstructions(int n, vector<int>& startPos, string s);

    /// <summary>
    /// Leet Code 2122. Recover the Original Array
    ///                                                                 
    /// Hard
    ///
    /// Alice had a 0-indexed array arr consisting of n positive integers. 
    /// She chose an arbitrary positive integer k and created two new 
    /// 0-indexed integer arrays lower and higher in the following manner:
    ///  
    /// lower[i] = arr[i] - k, for every index i where 0 <= i < n
    /// higher[i] = arr[i] + k, for every index i where 0 <= i < n
    /// Unfortunately, Alice lost all three arrays. However, she remembers 
    /// the integers that were present in the arrays lower and higher, but 
    /// not the array each integer belonged to. Help Alice and recover the 
    /// original array.
    ///
    /// Given an array nums consisting of 2n integers, where exactly n of 
    /// the integers were present in lower and the remaining in higher, 
    /// return the original array arr. In case the answer is not unique, 
    /// return any valid array.
    ///
    /// Note: The test cases are generated such that there exists at least 
    /// one valid array arr.
    ///
    /// Example 1:
    /// Input: nums = [2,10,6,4,8,12]
    /// Output: [3,7,11]
    /// Explanation:
    /// If arr = [3,7,11] and k = 1, we get lower = [2,6,10] and 
    /// higher = [4,8,12].
    /// Combining lower and higher gives us [2,6,10,4,8,12], which is a 
    /// permutation of nums.
    /// Another valid possibility is that arr = [5,7,9] and k = 3. In that 
    /// case, lower = [2,4,6] and higher = [8,10,12]. 
    ///
    /// Example 2:
    /// Input: nums = [1,1,3,3]
    /// Output: [2,2]
    /// Explanation:
    /// If arr = [2,2] and k = 1, we get lower = [1,1] and higher = [3,3].
    /// Combining lower and higher gives us [1,1,3,3], which is equal to nums.
    /// Note that arr cannot be [1,3] because in that case, the only possible 
    /// way to obtain [1,1,3,3] is with k = 0.
    /// This is invalid since k must be positive.
    ///
    /// Example 3:
    /// Input: nums = [5,435]
    /// Output: [220]
    /// Explanation:
    /// The only possible combination is arr = [220] and k = 215. Using them, 
    /// we get lower = [5] and higher = [435].
    ///    
    /// Constraints:
    /// 1. 2 * n == nums.length
    /// 2. 1 <= n <= 1000
    /// 3. 1 <= nums[i] <= 10^9
    /// 4. The test cases are generated such that there exists at least
    ///    one valid array arr.
    /// </summary>
    vector<int> recoverArray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2121. Intervals Between Identical Elements
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed array of n integers arr.
    ///
    /// The interval between two elements in arr is defined as the absolute 
    /// difference between their indices. More formally, the interval 
    /// between arr[i] and arr[j] is |i - j|.
    ///
    /// Return an array intervals of length n where intervals[i] is the sum of 
    /// intervals between arr[i] and each element in arr with the same value 
    /// as arr[i].
    /// Note: |x| is the absolute value of x.
    ///
    /// Example 1:
    /// Input: arr = [2,1,3,1,2,3,3]
    /// Output: [4,2,7,2,4,4,5]
    /// Explanation:
    /// - Index 0: Another 2 is found at index 4. |0 - 4| = 4
    /// - Index 1: Another 1 is found at index 3. |1 - 3| = 2
    /// - Index 2: Two more 3s are found at indices 5 and 6. 
    ///   |2 - 5| + |2 - 6| = 7
    /// - Index 3: Another 1 is found at index 1. |3 - 1| = 2
    /// - Index 4: Another 2 is found at index 0. |4 - 0| = 4
    /// - Index 5: Two more 3s are found at indices 2 and 6. 
    ///   |5 - 2| + |5 - 6| = 4
    /// - Index 6: Two more 3s are found at indices 2 and 5. 
    ///   |6 - 2| + |6 - 5| = 5
    ///
    /// Example 2:
    /// Input: arr = [10,5,10,10]
    /// Output: [5,0,3,4]
    /// Explanation:
    /// - Index 0: Two more 10s are found at indices 2 and 3. 
    ///   |0 - 2| + |0 - 3| = 5
    /// - Index 1: There is only one 5 in the array, so its sum of intervals 
    ///   to identical elements is 0.
    /// - Index 2: Two more 10s are found at indices 0 and 3. 
    ///   |2 - 0| + |2 - 3| = 3
    /// - Index 3: Two more 10s are found at indices 0 and 2. 
    ///   |3 - 0| + |3 - 2| = 4
    /// 
    /// Constraints:
    /// 1. n == arr.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= arr[i] <= 10^5
    /// </summary>
    vector<long long> getDistances(vector<int>& arr);

    /// <summary>
    /// Leet Code 2132. Stamping the Grid
    ///                                                                 
    /// Hard
    ///
    /// You are given an m x n binary matrix grid where each cell is either 0 
    /// (empty) or 1 (occupied).
    ///
    /// You are then given stamps of size stampHeight x stampWidth. We want to 
    /// fit the stamps such that they follow the given restrictions and 
    /// requirements:
    ///
    /// Cover all the empty cells.
    /// Do not cover any of the occupied cells.
    /// We can put as many stamps as we want.
    /// Stamps can overlap with each other.
    /// Stamps are not allowed to be rotated.
    /// Stamps must stay completely inside the grid.
    /// Return true if it is possible to fit the stamps while following the 
    /// given restrictions and requirements. Otherwise, return false.
    /// 
    /// Example 1:
    /// Input: grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], 
    /// stampHeight = 4, stampWidth = 3
    /// Output: true
    /// Explanation: We have two overlapping stamps (labeled 1 and 2 in the 
    /// image) that are able to cover all the empty cells.
    ///
    /// Example 2:
    /// Input: grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], 
    /// stampHeight = 2, stampWidth = 2 
    /// Output: false 
    /// Explanation: There is no way to fit the stamps onto all the empty 
    /// cells without the stamps going outside the grid.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[r].length
    /// 3. 1 <= m, n <= 10^5
    /// 4. 1 <= m * n <= 2 * 10^5
    /// 5. grid[r][c] is either 0 or 1.
    /// 6. 1 <= stampHeight, stampWidth <= 105
    /// </summary>
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth);

    /// <summary>
    /// Leet Code 2133. Check if Every Row and Column Contains All Numbers
    ///                                                                 
    /// Easy
    ///
    /// An n x n matrix is valid if every row and every column contains all 
    /// the integers from 1 to n (inclusive).
    ///
    /// Given an n x n integer matrix matrix, return true if the matrix is 
    /// valid. Otherwise, return false.
    /// 
    /// Example 1:
    /// Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
    /// Output: true
    /// Explanation: In this case, n = 3, and every row and column contains 
    /// the numbers 1, 2, and 3.
    /// Hence, we return true.
    ///
    /// Example 2:
    /// Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
    /// Output: false
    /// Explanation: In this case, n = 3, but the first row and the first 
    /// column do not contain the numbers 2 or 3.
    /// Hence, we return false.
    /// 
    /// Constraints:
    /// 1. n == matrix.length == matrix[i].length
    /// 2. 1 <= n <= 100
    /// 3. 1 <= matrix[i][j] <= n
    /// </summary>
    bool checkValid(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet Code 2128. Remove All Ones With Row and Column Flips
    ///                                                                 
    /// Medium
    ///
    /// You are given an m x n binary matrix grid.
    /// In one operation, you can choose any row or column and flip each value 
    /// in that row or column (i.e., changing all 0's to 1's, and all 
    /// 1's to 0's).
    ///
    /// Return true if it is possible to remove all 1's from grid using any 
    /// number of operations or false otherwise.
    /// 
    /// Example 1:
    /// Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
    /// Output: true
    /// Explanation: One possible way to remove all 1's from grid is to:
    /// - Flip the middle row
    /// - Flip the middle column
    ///
    /// Example 2:
    /// Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
    /// Output: false
    /// Explanation: It is impossible to remove all 1's from grid.
    ///
    /// Example 3:
    /// Input: grid = [[0]]
    /// Output: true
    /// Explanation: There are no 1's in grid.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2.  n == grid[i].length
    /// 3. 1 <= m, n <= 300
    /// 4. grid[i][j] is either 0 or 1.
    /// </summary>
    bool removeOnes(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2125. Number of Laser Beams in a Bank
    ///                                                                 
    /// Medium
    ///
    /// Anti-theft security devices are activated inside a bank. You are given 
    /// a 0-indexed binary string array bank representing the floor plan of 
    /// the bank, which is an m x n 2D matrix. bank[i] represents the ith row, 
    /// consisting of '0's and '1's. '0' means the cell is empty, while'1' 
    /// means the cell has a security device.
    ///
    /// There is one laser beam between any two security devices if both 
    /// conditions are met:
    ///
    /// The two devices are located on two different rows: r1 and r2, where 
    /// r1 < r2.
    /// For each row i where r1 < i < r2, there are no security devices in 
    /// the ith row.
    /// Laser beams are independent, i.e., one beam does not interfere nor 
    /// join with another.
    ///
    /// Return the total number of laser beams in the bank.
    /// 
    /// Example 1:
    /// Input: bank = ["011001","000000","010100","001000"]
    /// Output: 8
    /// Explanation: Between each of the following device pairs, there is one 
    /// beam. In total, there are 8 beams:
    /// * bank[0][1] -- bank[2][1]
    /// * bank[0][1] -- bank[2][3]
    /// * bank[0][2] -- bank[2][1]
    /// * bank[0][2] -- bank[2][3]
    /// * bank[0][5] -- bank[2][1]
    /// * bank[0][5] -- bank[2][3]
    /// * bank[2][1] -- bank[3][2]
    /// * bank[2][3] -- bank[3][2]
    /// Note that there is no beam between any device on the 0th row with any 
    /// on the 3rd row.
    /// This is because the 2nd row contains security devices, which breaks 
    /// the second condition.
    ///
    /// Example 2:
    ///
    /// Input: bank = ["000","111","000"]
    /// Output: 0
    /// Explanation: There does not exist two devices located on two different
    /// rows.
    /// 
    /// Constraints:
    /// 1. m == bank.length
    /// 2. n == bank[i].length
    /// 3. 1 <= m, n <= 500
    /// 4. bank[i][j] is either '0' or '1'.
    /// </summary>
    int numberOfBeams(vector<string>& bank);

    /// <summary>
    /// Leet Code 2134. Minimum Swaps to Group All 1's Together II
    ///                                                                 
    /// Medium
    ///
    /// A swap is defined as taking two distinct positions in an array and 
    /// swapping the values in them.
    ///
    /// A circular array is defined as an array where we consider the first 
    /// element and the last element to be adjacent.
    ///
    /// Given a binary circular array nums, return the minimum number of 
    /// swaps required to group all 1's present in the array together at 
    /// any location.
    /// 
    /// Example 1:
    /// Input: nums = [0,1,0,1,1,0,0]
    /// Output: 1
    /// Explanation: Here are a few of the ways to group all the 1's together:
    /// [0,0,1,1,1,0,0] using 1 swap.
    /// [0,1,1,1,0,0,0] using 1 swap.
    /// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the 
    /// array).
    /// There is no way to group all 1's together with 0 swaps.
    /// Thus, the minimum number of swaps required is 1.
    ///
    /// Example 2:
    /// Input: nums = [0,1,1,1,0,0,1,1,0]
    /// Output: 2
    /// Explanation: Here are a few of the ways to group all the 1's together:
    /// [1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the 
    /// array).
    /// [1,1,1,1,1,0,0,0,0] using 2 swaps.
    /// There is no way to group all 1's together with 0 or 1 swaps.
    /// Thus, the minimum number of swaps required is 2.
    ///
    /// Example 3:
    /// Input: nums = [1,1,0,0,1]
    /// Output: 0
    /// Explanation: All the 1's are already grouped together due to the 
    /// circular property of the array.
    /// Thus, the minimum number of swaps required is 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. nums[i] is either 0 or 1.
    /// </summary>
    int minSwapsII(vector<int>& nums);

    /// <summary>
    /// Leet Code 2147. Number of Ways to Divide a Long Corridor
    ///                                                                 
    /// Hard
    ///
    /// Along a long library corridor, there is a line of seats and decorative 
    /// plants. You are given a 0-indexed string corridor of length n 
    /// consisting of letters 'S' and 'P' where each 'S' represents a seat and 
    /// each 'P' represents a plant.
    ///
    /// One room divider has already been installed to the left of index 0, 
    /// and another to the right of index n - 1. Additional room dividers can 
    /// be installed. For each position between indices i - 1 and i 
    /// (1 <= i <= n - 1), at most one divider can be installed.
    ///
    /// Divide the corridor into non-overlapping sections, where each section 
    /// has exactly two seats with any number of plants. There may be multiple 
    /// ways to perform the division. Two ways are different if there is a 
    /// position with a room divider installed in the first way but not in 
    /// the second way.
    ///
    /// Return the number of ways to divide the corridor. Since the answer may 
    /// be very large, return it modulo 109 + 7. If there is no way, return 0.
    ///
    /// Example 1:
    /// Input: corridor = "SSPPSPS"
    /// Output: 3
    /// Explanation: There are 3 different ways to divide the corridor.
    /// The black bars in the above image indicate the two room dividers 
    /// already installed.
    /// Note that in each of the ways, each section has exactly two seats.
    ///
    /// Example 2:
    /// Input: corridor = "PPSPSP"
    /// Output: 1
    /// Explanation: There is only 1 way to divide the corridor, by not 
    /// installing any additional dividers.
    /// Installing any would create some section that does not have exactly 
    /// two seats.
    ///
    /// Example 3:
    /// Input: corridor = "S"
    /// Output: 0
    /// Explanation: There is no way to divide the corridor because there 
    /// will always be a section that does not have exactly two seats.
    /// 
    /// Constraints:
    /// n == corridor.length
    /// 1 <= n <= 10^5
    /// corridor[i] is either 'S' or 'P'.
    /// </summary>
    long long numberOfWays(string corridor);

    /// <summary>
    /// Leet Code 2154. Keep Multiplying Found Values by Two 
    ///                                                                 
    /// Easy
    ///
    /// You are given an array of integers nums. You are also given an integer 
    /// original which is the first number that needs to be searched for in 
    /// nums.
    ///
    /// You then do the following steps:
    /// If original is found in nums, multiply it by two (i.e., set 
    /// original = 2 * original).
    /// Otherwise, stop the process.
    /// Repeat this process with the new number as long as you keep finding 
    /// the number.
    /// Return the final value of original.
    /// 
    /// Example 1:
    /// Input: nums = [5,3,6,1,12], original = 3 
    /// Output: 24
    /// Explanation: 
    /// 1. - 3 is found in nums. 3 is multiplied by 2 to obtain 6.
    /// 2. - 6 is found in nums. 6 is multiplied by 2 to obtain 12.
    /// 3. - 12 is found in nums. 12 is multiplied by 2 to obtain 24.
    /// 4. - 24 is not found in nums. Thus, 24 is returned.
    ///
    /// Example 2:
    /// Input: nums = [2,7,9], original = 4
    /// Output: 4
    /// Explanation:
    /// - 4 is not found in nums. Thus, 4 is returned.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i], original <= 1000
    /// </summary>
    int findFinalValue(vector<int>& nums, int original);

    /// <summary>
    /// Leet Code 2149. Rearrange Array Elements by Sign
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums of even length consisting 
    /// of an equal number of positive and negative integers.
    ///
    /// You should rearrange the elements of nums such that the modified array 
    /// follows the given conditions:
    ///
    /// Every consecutive pair of integers have opposite signs.
    /// For all integers with the same sign, the order in which they were 
    /// present in nums is preserved.
    /// The rearranged array begins with a positive integer.
    /// Return the modified array after rearranging the elements to satisfy 
    /// the aforementioned conditions.
    /// 
    /// Example 1:
    /// Input: nums = [3,1,-2,-5,2,-4]
    /// Output: [3,-2,1,-5,2,-4]
    /// Explanation:
    /// The positive integers in nums are [3,1,2]. The negative integers 
    /// are [-2,-5,-4].
    /// The only possible way to rearrange them such that they satisfy all 
    /// conditions is [3,-2,1,-5,2,-4].
    /// Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], 
    /// [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or 
    /// more conditions.  
    ///
    /// Example 2:
    /// Input: nums = [-1,1]
    /// Output: [1,-1]
    /// Explanation:
    /// 1 is the only positive integer and -1 the only negative integer in 
    /// nums.
    /// So nums is rearranged to [1,-1].
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 2 * 10^5
    /// 2. nums.length is even
    /// 3. 1 <= |nums[i]| <= 105
    /// 4. nums consists of equal number of positive and negative integers.
    /// </summary>
    vector<int> rearrangeArray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2155. All Divisions With the Highest Score of a Binary Array
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed binary array nums of length n. nums can be 
    /// divided at index i (where 0 <= i <= n) into two arrays (possibly 
    /// empty) numsleft and numsright:
    ///
    /// numsleft has all the elements of nums between index 0 and i - 1 
    /// (inclusive), while numsright has all the elements of nums between 
    /// index i and n - 1 (inclusive).
    /// If i == 0, numsleft is empty, while numsright has all the elements 
    /// of nums.
    /// If i == n, numsleft has all the elements of nums, while numsright 
    /// is empty.
    /// The division score of an index i is the sum of the number of 0's 
    /// in numsleft and the number of 1's in numsright.
    ///
    /// Return all distinct indices that have the highest possible division 
    /// score. You may return the answer in any order.
    /// 
    /// Example 1:
    /// Input: nums = [0,0,1,0]
    /// Output: [2,4]
    /// Explanation: Division at index
    /// - 0: numsleft is []. numsright is [0,0,1,0]. The score is 0 + 1 = 1.
    /// - 1: numsleft is [0]. numsright is [0,1,0]. The score is 1 + 1 = 2.
    /// - 2: numsleft is [0,0]. numsright is [1,0]. The score is 2 + 1 = 3.
    /// - 3: numsleft is [0,0,1]. numsright is [0]. The score is 2 + 0 = 2.
    /// - 4: numsleft is [0,0,1,0]. numsright is []. The score is 3 + 0 = 3.
    /// Indices 2 and 4 both have the highest possible division score 3.
    /// Note the answer [4,2] would also be accepted.
    ///
    /// Example 2:
    /// Input: nums = [0,0,0]
    /// Output: [3]
    /// Explanation: Division at index
    /// - 0: numsleft is []. numsright is [0,0,0]. The score is 0 + 0 = 0.
    /// - 1: numsleft is [0]. numsright is [0,0]. The score is 1 + 0 = 1.
    /// - 2: numsleft is [0,0]. numsright is [0]. The score is 2 + 0 = 2.
    /// - 3: numsleft is [0,0,0]. numsright is []. The score is 3 + 0 = 3.
    /// Only index 3 has the highest possible division score 3.
    ///
    /// Example 3:
    /// Input: nums = [1,1]
    /// Output: [0]
    /// Explanation: Division at index
    /// - 0: numsleft is []. numsright is [1,1]. The score is 0 + 2 = 2.
    /// - 1: numsleft is [1]. numsright is [1]. The score is 0 + 1 = 1.
    /// - 2: numsleft is [1,1]. numsright is []. The score is 0 + 0 = 0.
    /// Only index 0 has the highest possible division score 2.
    ///
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^5
    /// 3. nums[i] is either 0 or 1.
    /// </summary>
    vector<int> maxScoreIndices(vector<int>& nums);

    /// <summary>
    /// Leet Code 2161. Partition Array According to Given Pivot
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums and an integer pivot. 
    /// Rearrange nums such that the following conditions are satisfied:
    ///
    /// Every element less than pivot appears before every element greater 
    /// than pivot.
    /// Every element equal to pivot appears in between the elements less 
    /// than and greater than pivot.
    /// The relative order of the elements less than pivot and the elements 
    /// greater than pivot is maintained.
    /// More formally, consider every pi, pj where pi is the new position of 
    /// the ith element and pj is the new position of the jth element. For 
    /// elements less than pivot, if i < j and nums[i] < pivot and 
    /// nums[j] < pivot, then pi < pj. Similarly for elements greater than 
    /// pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
    /// Return nums after the rearrangement.
    ///
    /// Example 1:
    /// Input: nums = [9,12,5,10,14,3,10], pivot = 10
    /// Output: [9,5,3,10,10,12,14]
    /// Explanation: 
    /// The elements 9, 5, and 3 are less than the pivot so they are on the 
    /// left side of the array.
    /// The elements 12 and 14 are greater than the pivot so they are on the 
    /// right side of the array.
    /// The relative ordering of the elements less than and greater than pivot 
    /// is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
    ///
    /// Example 2:
    /// Input: nums = [-3,4,3,2], pivot = 2
    /// Output: [-3,2,4,3]
    /// Explanation: 
    /// The element -3 is less than the pivot so it is on the left side of 
    /// the array.
    /// The elements 4 and 3 are greater than the pivot so they are on the 
    /// right side of the array.
    /// The relative ordering of the elements less than and greater than 
    /// pivot is also maintained. [-3] and [4, 3] are the respective orderings.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^6 <= nums[i] <= 10^6
    /// 3. pivot equals to an element of nums.
    /// </summary>
    vector<int> pivotArray(vector<int>& nums, int pivot);

    /// <summary>
    /// Leet Code 2163. Minimum Difference in Sums After Removal of Elements
    ///                                                                 
    /// Hard
    ///
    /// You are given a 0-indexed integer array nums consisting of 3 * n 
    /// elements.
    ///
    /// You are allowed to remove any subsequence of elements of size exactly 
    /// n from nums. The remaining 2 * n elements will be divided into two 
    /// equal parts:
    ///
    /// The first n elements belonging to the first part and their sum is 
    /// sumfirst.
    /// The next n elements belonging to the second part and their sum is 
    /// sumsecond.
    /// The difference in sums of the two parts is denoted as 
    /// sumfirst - sumsecond.
    ///
    /// For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
    /// Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
    /// Return the minimum difference possible between the sums of the two 
    /// parts after the removal of n elements.
    /// 
    /// Example 1:
    /// Input: nums = [3,1,2]
    /// Output: -1
    /// Explanation: Here, nums has 3 elements, so n = 1. 
    /// Thus we have to remove 1 element from nums and divide the array into 
    /// two equal parts.
    /// - If we remove nums[0] = 3, the array will be [1,2]. The difference in 
    ///   sums of the two parts will be 1 - 2 = -1.
    /// - If we remove nums[1] = 1, the array will be [3,2]. The difference in 
    ///   sums of the two parts will be 3 - 2 = 1.
    /// - If we remove nums[2] = 2, the array will be [3,1]. The difference in 
    ///   sums of the two parts will be 3 - 1 = 2.
    /// The minimum difference between sums of the two parts is 
    /// min(-1,1,2) = -1. 
    ///
    /// Example 2:
    /// Input: nums = [7,9,5,8,1,3]
    /// Output: 1
    /// Explanation: Here n = 2. So we must remove 2 elements and divide the 
    /// remaining array into two parts containing two elements each.
    /// If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be 
    /// [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
    /// To obtain the minimum difference, we should remove nums[1] = 9 and 
    /// nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in 
    /// sums of the two parts is (7+5) - (8+3) = 1.
    /// It can be shown that it is not possible to obtain a difference smaller 
    /// than 1.
    ///
    /// Constraints:
    /// 1. nums.length == 3 * n
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums[i] <= 10^5
    /// </summary>
    long long minimumDifference(vector<int>& nums);

    /// <summary>
    /// Leet Code 2170. Minimum Operations to Make the Array Alternating
    ///                                                                                  
    /// Medium
    ///
    /// You are given a 0-indexed array nums consisting of n positive integers.
    ///
    /// The array nums is called alternating if:
    ///
    /// nums[i - 2] == nums[i], where 2 <= i <= n - 1.
    /// nums[i - 1] != nums[i], where 1 <= i <= n - 1.
    /// In one operation, you can choose an index i and change nums[i] into 
    /// any positive integer.
    ///
    /// Return the minimum number of operations required to make the array 
    /// alternating.
    /// 
    /// Example 1:
    /// Input: nums = [3,1,3,2,4,3]
    /// Output: 3
    /// Explanation:
    /// One way to make the array alternating is by converting it to 
    /// [3,1,3,1,3,1].
    /// The number of operations required in this case is 3.
    /// It can be proven that it is not possible to make the array alternating 
    /// in less than 3 operations. 
    ///
    /// Example 2:
    /// Input: nums = [1,2,2,2,2]
    /// Output: 2
    /// Explanation:
    /// One way to make the array alternating is by converting it to 
    /// [1,2,1,2,1].
    /// The number of operations required in this case is 2.
    /// Note that the array cannot be converted to [2,2,2,2,2] because in this 
    /// case nums[0] == nums[1] which violates the conditions of an 
    /// alternating array.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int minimumOperations(vector<int>& nums);

    /// <summary>
    /// Leet Code 2176. Count Equal and Divisible Pairs in an Array
    ///                                                                                  
    /// Easy
    ///
    /// Given a 0-indexed integer array nums of length n and an integer k, 
    /// return the number of pairs (i, j) where 0 <= i < j < n, such that 
    /// nums[i] == nums[j] and (i * j) is divisible by k.
    ///
    /// Example 1:
    /// Input: nums = [3,1,2,2,2,1,3], k = 2
    /// Output: 4
    /// Explanation:
    /// There are 4 pairs that meet all the requirements:
    /// - nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
    /// - nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
    /// - nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
    /// - nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4], k = 1
    /// Output: 0
    /// Explanation: Since no value in nums is repeated, there are no 
    /// pairs (i,j) that meet all the requirements.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i], k <= 100
    /// </summary>
    int countPairs(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2179. Count Good Triplets in an Array
    ///                                                                                  
    /// Hard
    ///
    /// You are given two 0-indexed arrays nums1 and nums2 of length n, both 
    /// of which are permutations of [0, 1, ..., n - 1].
    ///
    /// A good triplet is a set of 3 distinct values which are present in 
    /// increasing order by position both in nums1 and nums2. In other words, 
    /// if we consider pos1v as the index of the value v in nums1 and pos2v 
    /// as the index of the value v in nums2, then a good triplet will be a 
    /// set (x, y, z) where 0 <= x, y, z <= n - 1, such that 
    /// pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.
    ///
    /// Return the total number of good triplets.
    /// 
    /// Example 1:
    /// Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
    /// Output: 1
    /// Explanation: 
    /// There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They 
    /// are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
    /// Out of those triplets, only the triplet (0,1,3) satisfies 
    /// pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
    ///
    /// Example 2:
    /// Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
    /// Output: 4
    /// Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), 
    /// and (4,1,2).
    /// 
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 3 <= n <= 10^5
    /// 3. 0 <= nums1[i], nums2[i] <= n - 1
    /// 4. nums1 and nums2 are permutations of [0, 1, ..., n - 1].
    /// </summary>
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2190. Most Frequent Number Following Key In an Array
    ///                                                                                   
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums. You are also given an 
    /// integer key, which is present in nums.
    ///
    /// For every unique integer target in nums, count the number of times 
    /// target immediately follows an occurrence of key in nums. In other 
    /// words, count the number of indices i such that:
    ///
    /// 0 <= i <= nums.length - 2,
    /// nums[i] == key and,
    /// nums[i + 1] == target.
    /// Return the target with the maximum count. The test cases will be 
    /// generated such that the target with maximum count is unique.
    /// 
    /// Example 1:
    /// Input: nums = [1,100,200,1,100], key = 1
    /// Output: 100
    /// Explanation: For target = 100, there are 2 occurrences at indices 1 
    /// and 4 which follow an occurrence of key.
    /// No other integers follow an occurrence of key, so we return 100.
    ///
    /// Example 2:
    /// Input: nums = [2,2,2,2,3], key = 2
    /// Output: 2
    /// Explanation: For target = 2, there are 3 occurrences at indices 1, 2, 
    /// and 3 which follow an occurrence of key.
    /// For target = 3, there is only one occurrence at index 4 which follows 
    /// an occurrence of key.
    /// target = 2 has the maximum number of occurrences following an 
    /// occurrence of key, so we return 2.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 1000
    /// 3. The test cases will be generated such that the answer is unique.
    /// </summary>
    int mostFrequent(vector<int>& nums, int key);

    /// <summary>
    /// Leet Code 2200. Find All K-Distant Indices in an Array
    ///                                                                                   
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums and two integers key and 
    /// k. A k-distant index is an index i of nums for which there exists at 
    /// least one index j such that |i - j| <= k and nums[j] == key.
    ///
    /// Return a list of all k-distant indices sorted in increasing order.
    /// 
    /// Example 1:
    /// Input: nums = [3,4,9,1,3,9,5], key = 9, k = 1
    /// Output: [1,2,3,4,5,6]
    /// Explanation: Here, nums[2] == key and nums[5] == key.
    /// - For index 0, |0 - 2| > k and |0 - 5| > k, so there is no j where 
    /// |0 - j| <= k and nums[j] == key. Thus, 0 is not a k-distant index.
    /// - For index 1, |1 - 2| <= k and nums[2] == key, so 1 is a k-distant 
    /// index.
    /// - For index 2, |2 - 2| <= k and nums[2] == key, so 2 is a k-distant 
    /// index.
    /// - For index 3, |3 - 2| <= k and nums[2] == key, so 3 is a k-distant 
    /// index.
    /// - For index 4, |4 - 5| <= k and nums[5] == key, so 4 is a k-distant 
    /// index.
    /// - For index 5, |5 - 5| <= k and nums[5] == key, so 5 is a k-distant 
    /// index.
    /// - For index 6, |6 - 5| <= k and nums[5] == key, so 6 is a k-distant 
    /// index.
    /// Thus, we return [1,2,3,4,5,6] which is sorted in increasing order. 
    ///
    /// Example 2:
    /// Input: nums = [2,2,2,2,2], key = 2, k = 2
    /// Output: [0,1,2,3,4]
    /// Explanation: For all indices i in nums, there exists some index 
    /// j such that |i - j| <= k and nums[j] == key, so every index is a 
    /// k-distant index. 
    /// Hence, we return [0,1,2,3,4].
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 1000
    /// 3. key is an integer from the array nums.
    /// 4. 1 <= k <= nums.length
    /// </summary>
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k);

    /// <summary>
    /// Leet Code 2214. Minimum Health to Beat Game
    ///                                                                                   
    /// Medium
    ///
    /// You are playing a game that has n levels numbered from 0 to n - 1. 
    /// You are given a 0-indexed integer array damage where damage[i] is 
    /// the amount of health you will lose to complete the ith level.
    ///
    /// You are also given an integer armor. You may use your armor ability 
    /// at most once during the game on any level which will protect you 
    /// from at most armor damage.
    ///
    /// You must complete the levels in order and your health must be greater 
    /// than 0 at all times to beat the game.
    ///
    /// Return the minimum health you need to start with to beat the game.
    /// 
    /// Example 1:
    /// Input: damage = [2,7,4,3], armor = 4
    /// Output: 13
    /// Explanation: One optimal way to beat the game starting at 13 health is:
    /// On round 1, take 2 damage. You have 13 - 2 = 11 health.
    /// On round 2, take 7 damage. You have 11 - 7 = 4 health.
    /// On round 3, use your armor to protect you from 4 damage. You 
    /// have 4 - 0 = 4 health.
    /// On round 4, take 3 damage. You have 4 - 3 = 1 health.
    /// Note that 13 is the minimum health you need to start with to beat the 
    /// game.
    ///
    /// Example 2:
    /// Input: damage = [2,5,3,4], armor = 7
    /// Output: 10
    /// Explanation: One optimal way to beat the game starting at 10 health is:
    /// On round 1, take 2 damage. You have 10 - 2 = 8 health.
    /// On round 2, use your armor to protect you from 5 damage. You 
    /// have 8 - 0 = 8 health.
    /// On round 3, take 3 damage. You have 8 - 3 = 5 health.
    /// On round 4, take 4 damage. You have 5 - 4 = 1 health.
    /// Note that 10 is the minimum health you need to start with to beat 
    /// the game.
    ///
    /// Example 3:
    /// Input: damage = [3,3,3], armor = 0
    /// Output: 10
    /// Explanation: One optimal way to beat the game starting at 10 health is:
    /// On round 1, take 3 damage. You have 10 - 3 = 7 health.
    /// On round 2, take 3 damage. You have 7 - 3 = 4 health.
    /// On round 3, take 3 damage. You have 4 - 3 = 1 health.
    /// Note that you did not use your armor ability.
    /// 
    /// Constraints:
    /// 1. n == damage.length
    /// 2. 1 <= n <= 10^5
    /// 3. 0 <= damage[i] <= 10^5
    /// 4. 0 <= armor <= 10^5
    /// </summary>
    long long minimumHealth(vector<int>& damage, int armor);

    /// <summary>
    /// Leet Code 2210. Count Hills and Valleys in an Array
    ///                                                         
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums. An index i is part of a 
    /// hill in nums if the closest non-equal neighbors of i are smaller than 
    /// nums[i]. Similarly, an index i is part of a valley in nums if the 
    /// closest non-equal neighbors of i are larger than nums[i]. Adjacent 
    /// indices i and j are part of the same hill or valley if 
    /// nums[i] == nums[j].
    /// 
    /// Note that for an index to be part of a hill or valley, it must have a 
    /// non-equal neighbor on both the left and right of the index.
    ///
    /// Return the number of hills and valleys in nums.
    /// 
    /// Example 1:
    /// Input: nums = [2,4,1,1,6,5]
    /// Output: 3
    /// Explanation:
    /// At index 0: There is no non-equal neighbor of 2 on the left, so 
    /// index 0 is neither a hill nor a valley.
    /// At index 1: The closest non-equal neighbors of 4 are 2 and 1. 
    /// Since 4 > 2 and 4 > 1, index 1 is a hill. 
    /// At index 2: The closest non-equal neighbors of 1 are 4 and 6. 
    /// Since 1 < 4 and 1 < 6, index 2 is a valley.
    /// At index 3: The closest non-equal neighbors of 1 are 4 and 6. 
    /// Since 1 < 4 and 1 < 6, index 3 is a valley, but note that it 
    /// is part of the same valley as index 2.
    /// At index 4: The closest non-equal neighbors of 6 are 1 and 5. 
    /// Since 6 > 1 and 6 > 5, index 4 is a hill.
    /// At index 5: There is no non-equal neighbor of 5 on the right, so 
    /// index 5 is neither a hill nor a valley. 
    /// There are 3 hills and valleys so we return 3.
    ///
    /// Example 2:
    /// Input: nums = [6,6,5,5,4,1]
    /// Output: 0
    /// Explanation:
    /// At index 0: There is no non-equal neighbor of 6 on the left, so 
    /// index 0 is neither a hill nor a valley.
    /// At index 1: There is no non-equal neighbor of 6 on the left, so 
    /// index 1 is neither a hill nor a valley.
    /// At index 2: The closest non-equal neighbors of 5 are 6 and 4. 
    /// Since 5 < 6 and 5 > 4, index 2 is neither a hill nor a valley.
    /// At index 3: The closest non-equal neighbors of 5 are 6 and 4. 
    /// Since 5 < 6 and 5 > 4, index 3 is neither a hill nor a valley.
    /// At index 4: The closest non-equal neighbors of 4 are 5 and 1. 
    /// Since 4 < 5 and 4 > 1, index 4 is neither a hill nor a valley.
    /// At index 5: There is no non-equal neighbor of 1 on the right, 
    /// so index 5 is neither a hill nor a valley.
    /// There are 0 hills and valleys so we return 0.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// </summary>
    int countHillValley(vector<int>& nums);

    /// <summary>
    /// Leet Code 2207. Maximize Number of Subsequences in a String
    ///                                                                                   
    /// Medium
    ///
    /// You are given a 0-indexed string text and another 0-indexed string 
    /// pattern of length 2, both of which consist of only lowercase English 
    /// letters.
    ///
    /// You can add either pattern[0] or pattern[1] anywhere in text exactly 
    /// once. Note that the character can be added even at the beginning or 
    /// at the end of text.
    ///
    /// Return the maximum number of times pattern can occur as a subsequence 
    /// of the modified text.
    ///
    /// A subsequence is a string that can be derived from another string by 
    /// deleting some or no characters without changing the order of the 
    /// remaining characters.
    /// 
    /// Example 1:
    /// Input: text = "abdcdbc", pattern = "ac"
    /// Output: 4
    /// Explanation:
    /// If we add pattern[0] = 'a' in between text[1] and text[2], we get 
    /// "abadcdbc". Now, the number of times "ac" occurs as a subsequence is 4.
    /// Some other strings which have 4 subsequences "ac" after adding a 
    /// character to text are "aabdcdbc" and "abdacdbc".
    /// However, strings such as "abdcadbc", "abdccdbc", and "abdcdbcc", 
    /// although obtainable, have only 3 subsequences "ac" and are thus 
    /// suboptimal.
    /// It can be shown that it is not possible to get more than 4 
    /// subsequences "ac" by adding only one character.
    ///
    /// Example 2:
    /// Input: text = "aabb", pattern = "ab"
    /// Output: 6
    /// Explanation:
    /// Some of the strings which can be obtained from text and have 6 
    /// subsequences "ab" are "aaabb", "aaabb", and "aabbb".
    ///
    /// Constraints:
    /// 1. 1 <= text.length <= 10^5
    /// 2. pattern.length == 2
    /// 3. text and pattern consist only of lowercase English letters.
    /// </summary>
    long long maximumSubsequenceCount(string text, string pattern);

    /// <summary>
    /// Leet Code 2208. Minimum Operations to Halve Array Sum
    ///                                                                                   
    /// Medium
    ///
    /// You are given an array nums of positive integers. In one operation, 
    /// you can choose any number from nums and reduce it to exactly half 
    /// the number. (Note that you may choose this reduced number in future 
    /// operations.)
    ///
    /// Return the minimum number of operations to reduce the sum of nums by 
    /// at least half.
    ///
    /// Example 1:
    /// Input: nums = [5,19,8,1]
    /// Output: 3
    /// Explanation: The initial sum of nums is equal to 5 + 19 + 8 + 1 = 33.
    /// The following is one of the ways to reduce the sum by at least half:
    /// Pick the number 19 and reduce it to 9.5.
    /// Pick the number 9.5 and reduce it to 4.75.
    /// Pick the number 8 and reduce it to 4.
    /// The final array is [5, 4.75, 4, 1] with a total sum of 
    /// 5 + 4.75 + 4 + 1 = 14.75. 
    /// The sum of nums has been reduced by 33 - 14.75 = 18.25, which is at 
    /// least half of the initial sum, 18.25 >= 33/2 = 16.5.
    /// Overall, 3 operations were used so we return 3.
    /// It can be shown that we cannot reduce the sum by at least half in less 
    /// than 3 operations.
    ///
    /// Example 2:
    /// Input: nums = [3,8,20]
    /// Output: 3
    /// Explanation: The initial sum of nums is equal to 3 + 8 + 20 = 31.
    /// The following is one of the ways to reduce the sum by at least half:
    /// Pick the number 20 and reduce it to 10.
    /// Pick the number 10 and reduce it to 5.
    /// Pick the number 3 and reduce it to 1.5.
    /// The final array is [1.5, 8, 5] with a total sum of 1.5 + 8 + 5 = 14.5. 
    /// The sum of nums has been reduced by 31 - 14.5 = 16.5, which is at 
    /// least half of the initial sum, 16.5 >= 31/2 = 16.5.
    /// Overall, 3 operations were used so we return 3.
    /// It can be shown that we cannot reduce the sum by at least half in less 
    /// than 3 operations.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^7
    /// </summary>
    int halveArray(vector<int>& nums);


    /// <summary>
    /// Leet Code 2216. Minimum Deletions to Make Array Beautiful
    ///                                                                                   
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums. The array nums is 
    /// beautiful if:
    /// nums.length is even.
    /// nums[i] != nums[i + 1] for all i % 2 == 0.
    /// Note that an empty array is considered beautiful.
    /// You can delete any number of elements from nums. When you delete 
    /// an element, all the elements to the right of the deleted element 
    /// will be shifted one unit to the left to fill the gap created and 
    /// all the elements to the left of the deleted element will remain 
    /// unchanged.
    /// 
    /// Return the minimum number of elements to delete from nums to 
    /// make it beautiful.
    /// 
    /// Example 1:
    /// Input: nums = [1,1,2,3,5]
    /// Output: 1
    /// Explanation: You can delete either nums[0] or nums[1] to make 
    /// nums = [1,2,3,5] which is beautiful. It can be proven you 
    /// need at least 1 deletion to make nums beautiful.
    ///
    /// Example 2:
    /// Input: nums = [1,1,2,2,3,3]
    /// Output: 2
    /// Explanation: You can delete nums[0] and nums[5] to make 
    /// nums = [1,2,2,3] which is beautiful. It can be proven you need 
    /// at least 2 deletions to make nums beautiful.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^5
    /// </summary>
    int minDeletion(vector<int>& nums);

    /// <summary>
    /// Leet Code 2219. Maximum Sum Score of Array
    ///                                                                                   
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums of length n.
    ///
    /// The sum score of nums at an index i where 0 <= i < n is the maximum of:
    ///
    /// The sum of the first i + 1 elements of nums.
    /// The sum of the last n - i elements of nums.
    /// Return the maximum sum score of nums at any index.
    /// 
    /// Example 1:
    /// Input: nums = [4,3,-2,5]
    /// Output: 10
    /// Explanation:
    /// The sum score at index 0 is max(4, 4 + 3 + -2 + 5) = max(4, 10) = 10.
    /// The sum score at index 1 is max(4 + 3, 3 + -2 + 5) = max(7, 6) = 7.
    /// The sum score at index 2 is max(4 + 3 + -2, -2 + 5) = max(5, 3) = 5.
    /// The sum score at index 3 is max(4 + 3 + -2 + 5, 5) = max(10, 5) = 10.
    /// The maximum sum score of nums is 10.
    ///
    /// Example 2:
    /// Input: nums = [-3,-5]
    /// Output: -3
    /// Explanation:
    /// The sum score at index 0 is max(-3, -3 + -5) = max(-3, -8) = -3.
    /// The sum score at index 1 is max(-3 + -5, -5) = max(-8, -5) = -5.
    /// The maximum sum score of nums is -3.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^5
    /// 3. -10^5 <= nums[i] <= 10^5
    /// </summary>
    long long maximumSumScore(vector<int>& nums);

    /// <summary>
    /// Leet Code 2221. Find Triangular Sum of an Array
    ///                                                                                   
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums, where nums[i] is a 
    /// digit between 0 and 9 (inclusive).
    ///
    /// The triangular sum of nums is the value of the only element present 
    /// in nums after the following process terminates:
    ///
    /// Let nums comprise of n elements. If n == 1, end the process. 
    /// Otherwise, create a new 0-indexed integer array newNums of length 
    /// n - 1.
    /// For each index i, where 0 <= i < n - 1, assign the value of 
    /// newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo 
    /// operator.
    /// Replace the array nums with newNums.
    /// Repeat the entire process starting from step 1.
    /// Return the triangular sum of nums.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3,4,5]
    /// Output: 8 
    /// Explanation:
    /// The above diagram depicts the process from which we obtain the 
    /// triangular sum of the array.
    /// 
    /// Example 2:
    /// Input: nums = [5]
    /// Output: 5
    /// Explanation:
    /// Since there is only one element in nums, the triangular sum is the 
    /// value of that element itself.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 0 <= nums[i] <= 9
    /// </summary>
    int triangularSum(vector<int>& nums);

    /// <summary>
    /// Leet Code 2225. Find Players With Zero or One Losses
    ///                                                                                   
    /// Medium
    ///
    /// You are given an integer array matches where matches[i] = 
    /// [winneri, loseri] indicates that the player winneri defeated 
    /// player loseri in a match.
    ///
    /// Return a list answer of size 2 where:
    ///
    /// answer[0] is a list of all players that have not lost any matches.
    /// answer[1] is a list of all players that have lost exactly one match.
    /// The values in the two lists should be returned in increasing order.
    ///
    /// Note:
    /// You should only consider the players that have played at least one match.
    /// The testcases will be generated such that no two matches will have the 
    /// same outcome.
    /// 
    /// Example 1:
    /// Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],
    /// [10,4],[10,9]]
    /// Output: [[1,2,10],[4,5,7,8]]
    /// Explanation:
    /// Players 1, 2, and 10 have not lost any matches.
    /// Players 4, 5, 7, and 8 each have lost one match.
    /// Players 3, 6, and 9 each have lost two matches.
    /// Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
    /// 
    /// Example 2:
    /// Input: matches = [[2,3],[1,3],[5,4],[6,4]]
    /// Output: [[1,2,5,6],[]]
    /// Explanation:
    /// Players 1, 2, 5, and 6 have not lost any matches.
    /// Players 3 and 4 each have lost two matches.
    /// Thus, answer[0] = [1,2,5,6] and answer[1] = [].
    /// 
    /// Constraints:
    /// 1. 1 <= matches.length <= 10^5
    /// 2. matches[i].length == 2
    /// 3. 1 <= winneri, loseri <= 10^5
    /// 4. winneri != loseri
    /// 5. All matches[i] are unique.
    /// </summary>
    vector<vector<int>> findWinners(vector<vector<int>>& matches);

    /// <summary>
    /// Leet Code 2229. Check if an Array Is Consecutive
    ///                                                                                   
    /// Easy
    ///
    /// Given an integer array nums, return true if nums is consecutive, 
    /// otherwise return false.
    ///
    /// An array is consecutive if it contains every number in the range 
    /// [x, x + n - 1] (inclusive), where x is the minimum number in the 
    /// array and n is the length of the array.
    ///
    /// Example 1:
    /// Input: nums = [1,3,4,2]
    /// Output: true
    /// Explanation:
    /// The minimum value is 1 and the length of nums is 4.
    /// All of the values in the range [x, x + n - 1] = [1, 1 + 4 - 1] = 
    /// [1, 4] = (1, 2, 3, 4) occur in nums.
    /// Therefore, nums is consecutive.
    ///
    /// Example 2:
    /// Input: nums = [1,3]
    /// Output: false
    /// Explanation:
    /// The minimum value is 1 and the length of nums is 2.
    /// The value 2 in the range [x, x + n - 1] = [1, 1 + 2 - 1], 
    /// = [1, 2] = (1, 2) does not occur in nums.
    /// Therefore, nums is not consecutive.
    ///
    /// Example 3:
    /// Input: nums = [3,5,4]
    /// Output: true
    /// Explanation:
    /// The minimum value is 3 and the length of nums is 3.
    /// All of the values in the range [x, x + n - 1] = [3, 3 + 3 - 1] 
    /// = [3, 5] = (3, 4, 5) occur in nums.
    /// Therefore, nums is consecutive.
    ///  
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^5
    /// </summary>
    bool isConsecutive(vector<int>& nums);

    /// <summary>
    /// Leet Code 2245. Maximum Trailing Zeros in a Cornered Path
    ///                                                                                      
    /// Medium
    /// 
    /// You are given a 2D integer array grid of size m x n, where each cell 
    /// contains a positive integer.
    /// A cornered path is defined as a set of adjacent cells with at most one 
    /// turn. More specifically, the path should exclusively move either 
    /// horizontally or vertically up to the turn (if there is one), without 
    /// returning to a previously visited cell. After the turn, the path will 
    /// then move exclusively in the alternate direction: move vertically if 
    /// it moved horizontally, and vice versa, also without returning to a 
    /// previously visited cell.
    ///
    /// The product of a path is defined as the product of all the values 
    /// in the path.
    ///
    /// Return the maximum number of trailing zeros in the product of a 
    /// cornered path found in grid.
    ///
    /// Note:
    /// Horizontal movement means moving in either the left or right direction.
    /// Vertical movement means moving in either the up or down direction.
    ///
    /// Example 1:
    /// Input: grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],
    ///                [40,9,1,10,6],[22,7,4,5,3]]
    /// Output: 3
    /// Explanation: The grid on the left shows a valid cornered path.
    /// It has a product of 15 * 20 * 6 * 1 * 10 = 18000 which has 3 trailing 
    /// zeros.
    /// It can be shown that this is the maximum trailing zeros in the product 
    /// of a cornered path.
    ///
    /// The grid in the middle is not a cornered path as it has more than 
    /// one turn.
    /// The grid on the right is not a cornered path as it requires a return 
    /// to a previously visited cell.
    ///
    /// Example 2:
    /// Input: grid = [[4,3,2],[7,6,1],[8,8,8]]
    /// Output: 0
    /// Explanation: The grid is shown in the figure above.
    /// There are no cornered paths in the grid that result in a product with 
    /// a trailing zero.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 10^5
    /// 4. 1 <= m * n <= 10^5
    /// 5. 1 <= grid[i][j] <= 1000
    /// </summary>
    int maxTrailingZeros(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2256. Minimum Average Difference
    ///                                                           
    /// Medium
    /// 
    /// You are given a 0-indexed integer array nums of length n.
    ///
    /// The average difference of the index i is the absolute difference 
    /// between the average of the first i + 1 elements of nums and the 
    /// average of the last n - i - 1 elements. Both averages should be 
    /// rounded down to the nearest integer.
    ///
    /// Return the index with the minimum average difference. If there are 
    /// multiple such indices, return the smallest one.
    ///
    /// Note:
    /// The absolute difference of two numbers is the absolute value of their 
    /// difference.
    /// The average of n elements is the sum of the n elements divided (integer 
    /// division) by n.
    /// The average of 0 elements is considered to be 0.
    ///
    /// Example 1:
    /// Input: nums = [2,5,3,9,5,3]
    /// Output: 3
    /// Explanation:
    /// - The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 
    ///   5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
    /// - The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 
    ///   5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
    /// - The average difference of index 2 is: |(2 + 5 + 3) / 3 - 
    ///  (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
    /// - The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - 
    ///   (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
    /// - The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 
    ///   1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
    /// - The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 
    ///   6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
    /// The average difference of index 3 is the minimum average difference 
    /// so return 3.
    ///
    /// Example 2:
    /// Input: nums = [0]
    /// Output: 0
    /// Explanation:
    /// The only index is 0 so return 0.
    /// The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^5
    /// </summary>
    int minimumAverageDifference(vector<int>& nums);

    /// <summary>
    /// Leet Code 2270. Number of Ways to Split Array
    ///                                                           
    /// Medium
    /// 
    /// You are given a 0-indexed integer array nums of length n.
    /// nums contains a valid split at index i if the following are true:
    ///
    /// The sum of the first i + 1 elements is greater than or equal to the 
    /// sum of the last n - i - 1 elements.
    /// There is at least one element to the right of i. That is, 0 <= i < 
    /// n - 1.
    /// Return the number of valid splits in nums.
    /// 
    /// Example 1:
    /// Input: nums = [10,4,-8,7]
    /// Output: 2
    /// Explanation: 
    /// There are three ways of splitting nums into two non-empty parts: 
    /// - Split nums at index 0. Then, the first part is [10], and its sum 
    ///   is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, 
    ///   i = 0 is a valid split.
    /// - Split nums at index 1. Then, the first part is [10,4], and its sum 
    ///   is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, 
    ///   i = 1 is a valid split.
    /// - Split nums at index 2. Then, the first part is [10,4,-8], and its 
    ///   sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, 
    ///   i = 2 is not a valid split.
    /// Thus, the number of valid splits in nums is 2.
    ///
    /// Example 2:
    /// Input: nums = [2,3,1,0]
    /// Output: 2
    /// Explanation: 
    /// There are two valid splits in nums:
    /// - Split nums at index 1. Then, the first part is [2,3], and its sum 
    ///   is 5. The second part is [1,0], and its sum is 1. Since 5 >= 1, 
    ///   i = 1 is a valid split. 
    /// - Split nums at index 2. Then, the first part is [2,3,1], and its 
    ///   sum is 6. The second part is [0], and its sum is 0. Since 6 >= 0, 
    ///   i = 2 is a valid split.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. -10^5 <= nums[i] <= 10^5
    /// </summary>
    int waysToSplitArray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2261. K Divisible Elements Subarrays
    ///                                                           
    /// Medium
    /// 
    /// Given an integer array nums and two integers k and p, return the 
    /// number of distinct subarrays which have at most k elements divisible 
    /// by p.
    ///
    /// Two arrays nums1 and nums2 are said to be distinct if:
    /// They are of different lengths, or
    /// There exists at least one index i where nums1[i] != nums2[i].
    /// A subarray is defined as a non-empty contiguous sequence of elements 
    /// in an array.
    /// 
    /// Example 1:
    /// Input: nums = [2,3,3,2,2], k = 2, p = 2
    /// Output: 11
    /// Explanation:
    /// The elements at indices 0, 3, and 4 are divisible by p = 2.
    /// The 11 distinct subarrays which have at most k = 2 elements divisible 
    /// by 2 are:
    /// [2], [2,3], [2,3,3], [2,3,3,2], [3], [3,3], [3,3,2], [3,3,2,2], [3,2], 
    /// [3,2,2], and [2,2].
    /// Note that the subarrays [2] and [3] occur more than once in nums, but 
    /// they should each be counted only once.
    /// The subarray [2,3,3,2,2] should not be counted because it has 3 
    /// elements that are divisible by 2.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4], k = 4, p = 1
    /// Output: 10
    /// Explanation:
    /// All element of nums are divisible by p = 1.
    /// Also, every subarray of nums will have at most 4 elements that are 
    /// divisible by 1.
    /// Since all subarrays are distinct, the total number of subarrays 
    /// satisfying all the constraints is 10.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 200
    /// 2. 1 <= nums[i], p <= 200
    /// 3. 1 <= k <= nums.length
    /// </summary>
    int countDistinct(vector<int>& nums, int k, int p);

    /// <summary>
    /// Leet Code 2260. Minimum Consecutive Cards to Pick Up
    ///                                                           
    /// Medium
    /// 
    /// You are given an integer array cards where cards[i] represents the 
    /// value of the ith card. A pair of cards are matching if the cards 
    /// have the same value.
    ///
    /// Return the minimum number of consecutive cards you have to pick up 
    /// to have a pair of matching cards among the picked cards. If it is 
    /// impossible to have matching cards, return -1.
    /// 
    /// Example 1:
    /// Input: cards = [3,4,2,3,4,7]
    /// Output: 4
    /// Explanation: We can pick up the cards [3,4,2,3] which contain a 
    /// matching pair of cards with value 3. Note that picking up the 
    /// cards [4,2,3,4] is also optimal.
    ///
    /// Example 2:
    /// Input: cards = [1,0,5,3]
    /// Output: -1
    /// Explanation: There is no way to pick up a set of consecutive cards 
    /// that contain a pair of matching cards.
    /// 
    /// Constraints:
    /// 1. 1 <= cards.length <= 10^5
    /// 2. 0 <= cards[i] <= 10^6
    /// </summary>
    int minimumCardPickup(vector<int>& cards);

    /// <summary>
    /// Leet Code 2293. Min Max Game
    ///                                                           
    /// Easy
    /// 
    /// You are given a 0-indexed integer array nums whose length is a power 
    /// of 2.
    ///
    /// Apply the following algorithm on nums:
    /// 
    /// Let n be the length of nums. If n == 1, end the process. Otherwise, 
    /// create a new 0-indexed integer array newNums of length n / 2.
    /// For every even index i where 0 <= i < n / 2, assign the value of 
    /// newNums[i] as min(nums[2 * i], nums[2 * i + 1]).
    /// For every odd index i where 0 <= i < n / 2, assign the value of 
    /// newNums[i] as max(nums[2 * i], nums[2 * i + 1]).
    /// Replace the array nums with newNums.
    /// Repeat the entire process starting from step 1.
    /// Return the last number that remains in nums after applying the 
    /// algorithm.
    /// 
    /// Example 1:
    /// Input: nums = [1,3,5,2,4,8,2,2]
    /// Output: 1
    /// Explanation: The following arrays are the results of applying the 
    /// algorithm repeatedly.
    /// First: nums = [1,5,4,2]
    /// Second: nums = [1,4]
    /// Third: nums = [1]
    /// 1 is the last remaining number, so we return 1.
    ///
    /// Example 2:
    /// Input: nums = [3]
    /// Output: 3
    /// Explanation: 3 is already the last remaining number, so we return 3.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1024
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. nums.length is a power of 2.
    /// </summary>
    int minMaxGame(vector<int>& nums);

    /// <summary>
    /// Leet Code 2294. Partition Array Such That Maximum Difference Is K
    ///                                                           
    /// Medium
    /// 
    /// You are given an integer array nums and an integer k. You may 
    /// partition nums into one or more subsequences such that each 
    /// element in nums appears in exactly one of the subsequences.
    ///
    /// Return the minimum number of subsequences needed such that the 
    /// difference between the maximum and minimum values in each 
    /// subsequence is at most k.
    ///
    /// A subsequence is a sequence that can be derived from another 
    /// sequence by deleting some or no elements without changing the 
    /// order of the remaining elements.
    /// 
    /// Example 1:
    /// Input: nums = [3,6,1,2,5], k = 2
    /// Output: 2
    /// Explanation:
    /// We can partition nums into the two subsequences [3,1,2] and [6,5].
    /// The difference between the maximum and minimum value in the first 
    /// subsequence is 3 - 1 = 2.
    /// The difference between the maximum and minimum value in the second 
    /// subsequence is 6 - 5 = 1.
    /// Since two subsequences were created, we return 2. It can be shown 
    /// that 2 is the minimum number of subsequences needed.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3], k = 1
    /// Output: 2
    /// Explanation:
    /// We can partition nums into the two subsequences [1,2] and [3].
    /// The difference between the maximum and minimum value in the first 
    /// subsequence is 2 - 1 = 1.
    /// The difference between the maximum and minimum value in the second 
    /// subsequence is 3 - 3 = 0.
    /// Since two subsequences were created, we return 2. Note that another 
    /// optimal solution is to partition nums into the two subsequences [1] 
    /// and [2,3].
    ///
    /// Example 3:
    /// Input: nums = [2,2,4,5], k = 0
    /// Output: 3
    /// Explanation:
    /// We can partition nums into the three subsequences [2,2], [4], and [5].
    /// The difference between the maximum and minimum value in the first 
    /// subsequences is 2 - 2 = 0.
    /// The difference between the maximum and minimum value in the second 
    /// subsequences is 4 - 4 = 0.
    /// The difference between the maximum and minimum value in the third 
    /// subsequences is 5 - 5 = 0.
    /// Since three subsequences were created, we return 3. It can be shown 
    /// that 3 is the minimum number of subsequences needed.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^5
    /// 3. 0 <= k <= 10^5
    /// </summary>
    int partitionArray(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2304. Minimum Path Cost in a Grid
    ///                                                           
    /// Medium
    /// 
    /// You are given a 0-indexed m x n integer matrix grid consisting of 
    /// distinct integers from 0 to m * n - 1. You can move in this matrix 
    /// from a cell to any other cell in the next row. That is, if you are 
    /// in cell (x, y) such that x < m - 1, you can move to any of the 
    /// cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). Note that it is 
    /// not possible to move from cells in the last row.
    ///
    /// Each possible move has a cost given by a 0-indexed 2D array moveCost 
    /// of size (m * n) x n, where moveCost[i][j] is the cost of moving from 
    /// a cell with value i to a cell in column j of the next row. The cost 
    /// of moving from cells in the last row of grid can be ignored.
    ///
    /// The cost of a path in grid is the sum of all values of cells visited 
    /// plus the sum of costs of all the moves made. Return the minimum cost 
    /// of a path that starts from any cell in the first row and ends at any 
    /// cell in the last row.
    /// 
    /// Example 1:
    /// Input: grid = [[5,3],[4,0],[2,1]], 
    /// moveCost = [[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]
    /// Output: 17
    /// Explanation: The path with the minimum possible cost is the 
    /// path 5 -> 0 -> 1.
    /// - The sum of the values of cells visited is 5 + 0 + 1 = 6.
    /// - The cost of moving from 5 to 0 is 3.
    /// - The cost of moving from 0 to 1 is 8.
    /// So the total cost of the path is 6 + 3 + 8 = 17.
    /// Example 2:
    ///
    /// Input: grid = [[5,1,2],[4,0,3]], moveCost = [[12,10,15],[20,23,8],
    /// [21,7,1],[8,1,13],[9,10,25],[5,3,2]]
    /// Output: 6
    /// Explanation: The path with the minimum possible cost is the 
    /// path 2 -> 3.
    /// - The sum of the values of cells visited is 2 + 3 = 5.
    /// - The cost of moving from 2 to 3 is 1.
    /// So the total cost of this path is 5 + 1 = 6.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 2 <= m, n <= 50
    /// 4. grid consists of distinct integers from 0 to m * n - 1.
    /// 5. moveCost.length == m * n
    /// 6. moveCost[i].length == n
    /// 7. 1 <= moveCost[i][j] <= 100
    /// </summary>
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost);

    /// <summary>
    /// Leet Code 2319. Check if Matrix Is X-Matrix
    ///                                                           
    /// Easy
    ///
    /// A square matrix is said to be an X-Matrix if both of the following 
    /// conditions hold:
    ///
    /// All the elements in the diagonals of the matrix are non-zero.
    /// All other elements are 0.
    /// Given a 2D integer array grid of size n x n representing a square 
    /// matrix, return true if grid is an X-Matrix. Otherwise, return false.
    ///
    /// Example 1:
    /// Input: grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
    /// Output: true
    /// Explanation: Refer to the diagram above. 
    /// An X-Matrix should have the green elements (diagonals) be non-zero 
    /// and the red elements be 0.
    /// Thus, grid is an X-Matrix.
    ///
    /// Example 2:
    /// Input: grid = [[5,7,0],[0,3,1],[0,5,0]]
    /// Output: false
    /// Explanation: Refer to the diagram above.
    /// An X-Matrix should have the green elements (diagonals) be non-zero 
    /// and the red elements be 0.
    /// Thus, grid is not an X-Matrix.
    /// 
    /// Constraints:
    /// 1. n == grid.length == grid[i].length
    /// 2. 3 <= n <= 100
    /// 3. 0 <= grid[i][j] <= 10^5
    /// </summary>
    bool checkXMatrix(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2321. Maximum Score Of Spliced Array
    ///                                                           
    /// Hard
    ///
    /// You are given two 0-indexed integer arrays nums1 and nums2, both of 
    /// length n.
    ///
    /// You can choose two integers left and right where 
    /// 0 <= left <= right < n and swap the subarray nums1[left...right] 
    /// with the subarray nums2[left...right].
    ///
    /// For example, if nums1 = [1,2,3,4,5] and nums2 = [11,12,13,14,15] and 
    /// you choose left = 1 and right = 2, nums1 becomes [1,12,13,4,5] and 
    /// nums2 becomes [11,2,3,14,15].
    /// You may choose to apply the mentioned operation once or not do 
    /// anything.
    ///
    /// The score of the arrays is the maximum of sum(nums1) and sum(nums2), 
    /// where sum(arr) is the sum of all the elements in the array arr.
    ///
    /// Return the maximum possible score.
    ///
    /// A subarray is a contiguous sequence of elements within an array. 
    /// arr[left...right] denotes the subarray that contains the elements 
    /// of nums between indices left and right (inclusive).
    /// 
    /// Example 1:
    /// Input: nums1 = [60,60,60], nums2 = [10,90,10]
    /// Output: 210
    /// Explanation: Choosing left = 1 and right = 1, we have 
    /// nums1 = [60,90,60] and nums2 = [10,60,10].
    /// The score is max(sum(nums1), sum(nums2)) = max(210, 80) = 210.
    ///
    /// Example 2:
    /// Input: nums1 = [20,40,20,70,30], nums2 = [50,20,50,40,20]
    /// Output: 220
    /// Explanation: Choosing left = 3, right = 4, we have 
    /// nums1 = [20,40,20,40,20] and nums2 = [50,20,50,70,30].
    /// The score is max(sum(nums1), sum(nums2)) = max(140, 220) = 220.
    ///
    /// Example 3:
    /// Input: nums1 = [7,11,13], nums2 = [1,1,1]
    /// Output: 31
    /// Explanation: We choose not to swap any subarray.
    /// The score is max(sum(nums1), sum(nums2)) = max(31, 3) = 31.
    ///
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums1[i], nums2[i] <= 10^4
    /// </summary>
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2326. Spiral Matrix IV
    ///                                                           
    /// Medium
    ///
    /// You are given two integers m and n, which represent the dimensions of 
    /// a matrix.
    ///
    /// You are also given the head of a linked list of integers.
    ///
    /// Generate an m x n matrix that contains the integers in the linked list 
    /// presented in spiral order (clockwise), starting from the top-left of 
    /// the matrix. If there are remaining empty spaces, fill them with -1.
    ///
    /// Return the generated matrix.
    ///
    /// Example 1:
    /// Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
    /// Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
    /// Explanation: The diagram above shows how the values are printed in the 
    /// matrix.
    /// Note that the remaining spaces in the matrix are filled with -1.
    ///
    /// Example 2:
    /// Input: m = 1, n = 4, head = [0,1,2]
    /// Output: [[0,1,2,-1]]
    /// Explanation: The diagram above shows how the values are printed from 
    /// left to right in the matrix.
    /// The last space in the matrix is set to -1.
    /// 
    /// Constraints:
    /// 1. 1 <= m, n <= 10^5
    /// 2. 1 <= m * n <= 10^5
    /// 3. The number of nodes in the list is in the range [1, m * n].
    /// 4. 0 <= Node.val <= 1000
    /// </summary>
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head);

    /// <summary>
    /// Leet Code 2340. Minimum Adjacent Swaps to Make a Valid Array
    ///                                                           
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums.
    ///
    /// Swaps of adjacent elements are able to be performed on nums.
    ///
    /// A valid array meets the following conditions:
    ///
    /// The largest element (any of the largest elements if there are 
    /// multiple) is at the rightmost position in the array.
    /// The smallest element (any of the smallest elements if there are 
    /// multiple) is at the leftmost position in the array.
    /// Return the minimum swaps required to make nums a valid array.
    ///
    /// Example 1:
    /// Input: nums = [3,4,5,5,3,1]
    /// Output: 6
    /// Explanation: Perform the following swaps:
    /// - Swap 1: Swap the 3rd and 4th elements, nums is then [3,4,5,3,5,1].
    /// - Swap 2: Swap the 4th and 5th elements, nums is then [3,4,5,3,1,5].
    /// - Swap 3: Swap the 3rd and 4th elements, nums is then [3,4,5,1,3,5].
    /// - Swap 4: Swap the 2nd and 3rd elements, nums is then [3,4,1,5,3,5].
    /// - Swap 5: Swap the 1st and 2nd elements, nums is then [3,1,4,5,3,5].
    /// - Swap 6: Swap the 0th and 1st elements, nums is then [1,3,4,5,3,5].
    /// It can be shown that 6 swaps is the minimum swaps required to make a 
    /// valid array.
    ///
    /// Example 2:
    /// Input: nums = [9]
    /// Output: 0
    /// Explanation: The array is already valid, so we return 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int minimumSwaps(vector<int>& nums);

    /// <summary>
    /// Leet Code 2341. Maximum Number of Pairs in Array
    ///                                                           
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums. In one operation, you 
    /// may do the following:
    ///
    /// Choose two integers in nums that are equal.
    /// Remove both integers from nums, forming a pair.
    /// The operation is done on nums as many times as possible.
    ///
    /// Return a 0-indexed integer array answer of size 2 where answer[0] is 
    /// the number of pairs that are formed and answer[1] is the number of 
    /// leftover integers in nums after doing the operation as many times as 
    /// possible.
    ///
    /// Example 1:
    /// Input: nums = [1,3,2,1,3,2,2]
    /// Output: [3,1]
    /// Explanation:
    /// Form a pair with nums[0] and nums[3] and remove them from nums. Now, 
    /// nums = [3,2,3,2,2].
    /// Form a pair with nums[0] and nums[2] and remove them from nums. Now, 
    /// nums = [2,2,2].
    /// Form a pair with nums[0] and nums[1] and remove them from nums. Now, 
    /// nums = [2].
    /// No more pairs can be formed. A total of 3 pairs have been formed, and 
    /// there is 1 number leftover in nums.
    ///
    /// Example 2:
    /// Input: nums = [1,1]
    /// Output: [1,0]
    /// Explanation: Form a pair with nums[0] and nums[1] and remove them 
    /// from nums. Now, nums = [].
    /// No more pairs can be formed. A total of 1 pair has been formed, and 
    /// there are 0 numbers leftover in nums.
    ///
    /// Example 3:
    /// Input: nums = [0]
    /// Output: [0,1]
    /// Explanation: No pairs can be formed, and there is 1 number leftover 
    /// in nums.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 0 <= nums[i] <= 100
    /// </summary>
    vector<int> numberOfPairs(vector<int>& nums);

    /// <summary>
    /// Leet Code 2363. Merge Similar Items
    ///                                                           
    /// Easy
    ///
    /// You are given two 2D integer arrays, items1 and items2, representing 
    /// two sets of items. Each array items has the following properties:
    ///
    /// items[i] = [valuei, weighti] where valuei represents the value and 
    /// weighti represents the weight of the ith item.
    /// The value of each item in items is unique.
    /// Return a 2D integer array ret where ret[i] = [valuei, weighti], with 
    /// weighti being the sum of weights of all items with value valuei.
    ///
    /// Note: ret should be returned in ascending order by value.
    ///
    /// Example 1:
    /// Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
    /// Output: [[1,6],[3,9],[4,5]]
    /// Explanation: 
    /// The item with value = 1 occurs in items1 with weight = 1 and in 
    /// items2 with weight = 5, total weight = 1 + 5 = 6.
    /// The item with value = 3 occurs in items1 with weight = 8 and in 
    /// items2 with weight = 1, total weight = 8 + 1 = 9.
    /// The item with value = 4 occurs in items1 with weight = 5, total 
    /// weight = 5.  
    /// Therefore, we return [[1,6],[3,9],[4,5]].
    ///
    /// Example 2:
    /// Input: items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
    /// Output: [[1,4],[2,4],[3,4]]
    /// Explanation: 
    /// The item with value = 1 occurs in items1 with weight = 1 and in 
    /// items2 with weight = 3, total weight = 1 + 3 = 4.
    /// The item with value = 2 occurs in items1 with weight = 3 and in 
    /// items2 with weight = 1, total weight = 3 + 1 = 4.
    /// The item with value = 3 occurs in items1 with weight = 2 and in 
    /// items2 with weight = 2, total weight = 2 + 2 = 4.
    /// Therefore, we return [[1,4],[2,4],[3,4]].
    ///
    /// Example 3:
    /// Input: items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
    /// Output: [[1,7],[2,4],[7,1]]
    /// Explanation:
    /// The item with value = 1 occurs in items1 with weight = 3 and in 
    /// items2 with weight = 4, total weight = 3 + 4 = 7. 
    /// The item with value = 2 occurs in items1 with weight = 2 and in 
    /// items2 with weight = 2, total weight = 2 + 2 = 4. 
    /// The item with value = 7 occurs in items2 with weight = 1, 
    /// total weight = 1.
    /// Therefore, we return [[1,7],[2,4],[7,1]].
    ///
    /// Constraints:
    /// 1. 1 <= items1.length, items2.length <= 1000
    /// 2. items1[i].length == items2[i].length == 2
    /// 3. 1 <= valuei, weighti <= 1000
    /// 4. Each valuei in items1 is unique.
    /// 5. Each valuei in items2 is unique.
    /// </summary>
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2);

    /// <summary>
    /// Leet Code 2373. Largest Local Values in a Matrix
    ///                                                           
    /// Easy
    ///
    /// You are given an n x n integer matrix grid.
    ///
    /// Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such 
    /// that:
    ///
    /// maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix 
    /// in grid centered around row i + 1 and column j + 1.
    /// In other words, we want to find the largest value in every 
    /// contiguous 3 x 3 matrix in grid.
    ///
    /// Return the generated matrix.
    /// 
    /// Example 1:
    /// Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
    /// Output: [[9,9],[8,6]]
    /// Explanation: The diagram above shows the original matrix 
    /// and the generated matrix.
    /// Notice that each value in the generated matrix corresponds to the 
    /// largest value of a contiguous 3 x 3 matrix in grid.
    ///
    /// Example 2:
    /// Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],
    ///                [1,1,1,1,1]]
    /// Output: [[2,2,2],[2,2,2],[2,2,2]]
    /// Explanation: Notice that the 2 is contained within every 
    /// contiguous 3 x 3 matrix in grid.
    ///
    /// Constraints:
    /// n == grid.length == grid[i].length
    /// 3 <= n <= 100
    /// 1 <= grid[i][j] <= 100
    /// </summary>
    vector<vector<int>> largestLocal(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2383. Minimum Hours of Training to Win a Competition
    ///                                                           
    /// Easy
    ///
    /// You are entering a competition, and are given two positive integers 
    /// initialEnergy and initialExperience denoting your initial energy and 
    /// initial experience respectively.
    /// You are also given two 0-indexed integer arrays energy and 
    /// experience, both of length n.
    /// You will face n opponents in order. The energy and experience of the 
    /// ith opponent is denoted by energy[i] and experience[i] respectively. 
    /// When you face an opponent, you need to have both strictly greater 
    /// experience and energy to defeat them and move to the next opponent 
    /// if available.
    ///
    /// Defeating the ith opponent increases your experience by experience[i], 
    /// but decreases your energy by energy[i].
    ///
    /// Before starting the competition, you can train for some number of 
    /// hours. After each hour of training, you can either choose to increase 
    /// your initial experience by one, or increase your initial energy by 
    /// one.
    ///
    /// Return the minimum number of training hours required to defeat all 
    /// n opponents.
    ///
    /// Example 1:
    /// Input: initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], 
    /// experience = [2,6,3,1]
    /// Output: 8
    /// Explanation: You can increase your energy to 11 after 6 hours of 
    /// training, and your experience to 5 after 2 hours of training.
    /// You face the opponents in the following order:
    /// - You have more energy and experience than the 0th opponent so you win.
    ///   Your energy becomes 11 - 1 = 10, and your experience 
    ///   becomes 5 + 2 = 7.
    /// - You have more energy and experience than the 1st opponent so you win.
    ///   Your energy becomes 10 - 4 = 6, and your experience 
    ///   becomes 7 + 6 = 13.
    /// - You have more energy and experience than the 2nd opponent so you win.
    ///   Your energy becomes 6 - 3 = 3, and your experience 
    ///   becomes 13 + 3 = 16.
    /// - You have more energy and experience than the 3rd opponent so you win.
    ///   Your energy becomes 3 - 2 = 1, and your experience 
    ///   becomes 16 + 1 = 17.
    ///   You did a total of 6 + 2 = 8 hours of training before the 
    ///   competition, so we return 8.
    /// It can be proven that no smaller answer exists.
    ///
    /// Example 2:
    /// Input: initialEnergy = 2, initialExperience = 4, energy = [1], 
    /// experience = [3]
    /// Output: 0
    /// Explanation: You do not need any additional energy or experience to 
    /// win the competition, so we return 0.
    ///
    /// Constraints:
    /// 1. n == energy.length == experience.length
    /// 2. 1 <= n <= 100
    /// 3. 1 <= initialEnergy, initialExperience, energy[i], 
    ///    experience[i] <= 100
    /// </summary>
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience);

    /// <summary>
    /// Leet Code 2352. Equal Row and Column Pairs
    ///                                                           
    /// Medium
    ///
    /// Given a 0-indexed n x n integer matrix grid, return the number of 
    /// pairs (Ri, Cj) such that row Ri and column Cj are equal.
    ///
    /// A row and column pair is considered equal if they contain the same 
    /// elements in the same order (i.e. an equal array).
    ///
    /// Example 1:
    /// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
    /// Output: 1
    /// Explanation: There is 1 equal row and column pair:
    /// - (Row 2, Column 1): [2,7,7]
    /// Example 2:
    /// Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
    /// Output: 3
    /// Explanation: There are 3 equal row and column pairs:
    /// - (Row 0, Column 0): [3,1,2,2]
    /// - (Row 2, Column 2): [2,4,2,2]
    /// - (Row 3, Column 2): [2,4,2,2]
    /// 
    /// Constraints:
    /// 1. n == grid.length == grid[i].length
    /// 2. 1 <= n <= 200
    /// 3. 1 <= grid[i][j] <= 10^5
    /// </summary>
    int equalPairs(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2364. Count Number of Bad Pairs
    ///                                                           
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums. A pair of indices 
    /// (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
    ///
    /// Return the total number of bad pairs in nums.
    ///
    /// Example 1:
    /// Input: nums = [4,1,3,3]
    /// Output: 5
    /// Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
    /// The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
    /// The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
    /// The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
    /// The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
    /// There are a total of 5 bad pairs, so we return 5.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,5]
    /// Output: 0
    /// Explanation: There are no bad pairs.
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    long long countBadPairs(vector<int>& nums);

    /// <summary>
    /// Leet Code 2366. Minimum Replacements to Sort the Array
    ///                                                  
    /// Hard
    ///
    /// You are given a 0-indexed integer array nums. In one operation you 
    /// can replace any element of the array with any two elements that sum 
    /// to it.
    ///
    /// For example, consider nums = [5,6,7]. In one operation, we can 
    /// replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
    /// Return the minimum number of operations to make an array that is 
    /// sorted in non-decreasing order.
    ///
    /// Example 1:
    ///
    /// Input: nums = [3,9,3]
    /// Output: 2
    /// Explanation: Here are the steps to sort the array in non-decreasing 
    /// order:
    /// - From [3,9,3], replace the 9 with 3 and 6 so the array 
    ///   becomes [3,3,6,3]
    /// - From [3,3,6,3], replace the 6 with 3 and 3 so the array 
    ///   becomes [3,3,3,3,3]
    /// There are 2 steps to sort the array in non-decreasing order. 
    /// Therefore, we return 2.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,5]
    /// Output: 0
    /// Explanation: The array is already in non-decreasing order. 
    /// Therefore, we return 0. 
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    long long minimumReplacement(vector<int>& nums);

    /// <summary>
    /// Leet Code 2348. Number of Zero-Filled Subarrays
    ///                                                  
    /// Medium
    ///
    /// Given an integer array nums, return the number of subarrays filled 
    /// with 0.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within 
    /// an array.
    ///
    /// Example 1:
    /// Input: nums = [1,3,0,0,2,0,0,4]
    /// Output: 6
    /// Explanation: 
    /// There are 4 occurrences of [0] as a subarray.
    /// There are 2 occurrences of [0,0] as a subarray.
    /// There is no occurrence of a subarray with a size more than 2 
    /// filled with 0. Therefore, we return 6.
    ///
    /// Example 2:
    /// Input: nums = [0,0,0,2,0,0]
    /// Output: 9
    /// Explanation:
    /// There are 5 occurrences of [0] as a subarray.
    /// There are 3 occurrences of [0,0] as a subarray.
    /// There is 1 occurrence of [0,0,0] as a subarray.
    /// There is no occurrence of a subarray with a size more than 3 
    /// filled with 0. Therefore, we return 9.
    ///
    /// Example 3:
    /// 
    /// Input: nums = [2,10,2019]
    /// Output: 0
    /// Explanation: There is no subarray filled with 0. 
    /// Therefore, we return 0.
    ///
    /// Constraints:
    ///  1. 1 <= nums.length <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// </summary>
    long long zeroFilledSubarray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2391. Minimum Amount of Time to Collect Garbage
    ///                                                  
    /// Medium
    ///
    /// You are given a 0-indexed array of strings garbage where garbage[i] 
    /// represents the assortment of garbage at the ith house. garbage[i] 
    /// consists only of the characters 'M', 'P' and 'G' representing one 
    /// unit of metal, paper and glass garbage respectively. Picking up one 
    /// unit of any type of garbage takes 1 minute.
    ///
    /// You are also given a 0-indexed integer array travel where travel[i] 
    /// is the number of minutes needed to go from house i to house i + 1.
    ///
    /// There are three garbage trucks in the city, each responsible for 
    /// picking up one type of garbage. Each garbage truck starts at house 0 
    /// and must visit each house in order; however, they do not need to 
    /// visit every house.
    ///
    /// Only one garbage truck may be used at any given moment. While one 
    /// truck is driving or picking up garbage, the other two trucks cannot 
    /// do anything.
    ///
    /// Return the minimum number of minutes needed to pick up all the garbage.
    /// 
    /// Example 1:
    ///
    /// Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
    /// Output: 21
    /// Explanation:
    /// The paper garbage truck:
    /// 1. Travels from house 0 to house 1
    /// 2. Collects the paper garbage at house 1
    /// 3. Travels from house 1 to house 2
    /// 4. Collects the paper garbage at house 2
    /// Altogether, it takes 8 minutes to pick up all the paper garbage.
    /// The glass garbage truck:
    /// 1. Collects the glass garbage at house 0
    /// 2. Travels from house 0 to house 1
    /// 3. Travels from house 1 to house 2
    /// 4. Collects the glass garbage at house 2
    /// 5. Travels from house 2 to house 3
    /// 6. Collects the glass garbage at house 3
    /// Altogether, it takes 13 minutes to pick up all the glass garbage.
    /// Since there is no metal garbage, we do not need to consider the 
    /// metal garbage truck.
    /// Therefore, it takes a total of 8 + 13 = 21 minutes to collect 
    /// all the garbage.
    ///
    /// Example 2:
    /// Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
    /// Output: 37
    /// Explanation:
    /// The metal garbage truck takes 7 minutes to pick up all the metal 
    /// garbage.
    /// The paper garbage truck takes 15 minutes to pick up all the paper 
    /// garbage.
    /// The glass garbage truck takes 15 minutes to pick up all the glass 
    /// garbage.
    /// It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.
    ///
    /// Constraints:
    /// 1. 2 <= garbage.length <= 10^5
    /// 2. garbage[i] consists of only the letters 'M', 'P', and 'G'.
    /// 3. 1 <= garbage[i].length <= 10
    /// 4. travel.length == garbage.length - 1
    /// 5. 1 <= travel[i] <= 100
    /// </summary>
    int garbageCollection(vector<string>& garbage, vector<int>& travel);

    /// <summary>
    /// Leet Code 2371. Minimize Maximum Value in a Grid
    ///                                                  
    /// Hard
    ///
    /// You are given an m x n integer matrix grid containing distinct 
    /// positive integers.
    ///
    /// You have to replace each integer in the matrix with a positive 
    /// integer satisfying the following conditions:
    ///
    /// The relative order of every two elements that are in the same 
    /// row or column should stay the same after the replacements.
    /// The maximum number in the matrix after the replacements should 
    /// be as small as possible.
    /// The relative order stays the same if for all pairs of elements 
    /// in the original matrix such that grid[r1][c1] > grid[r2][c2] 
    /// where either r1 == r2 or c1 == c2, then it must be true that 
    /// grid[r1][c1] > grid[r2][c2] after the replacements.
    ///
    /// For example, if grid = [[2, 4, 5], [7, 3, 9]] then a good 
    /// replacement could be either grid = [[1, 2, 3], [2, 1, 4]] or 
    /// grid = [[1, 2, 3], [3, 1, 4]].
    /// Return the resulting matrix. If there are multiple answers, 
    /// return any of them.
    /// 
    /// Example 1:
    /// Input: grid = [[3,1],[2,5]]
    /// Output: [[2,1],[1,2]]
    /// Explanation: The above diagram shows a valid replacement.
    /// The maximum number in the matrix is 2. It can be shown that no 
    /// smaller value can be obtained.
    ///
    /// Example 2:
    /// Input: grid = [[10]]
    /// Output: [[1]]
    /// Explanation: We replace the only number in the matrix with 1.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 1000
    /// 4. 1 <= m * n <= 10^5
    /// 5. 1 <= grid[i][j] <= 10^9
    /// 6. grid consists of distinct integers.
    /// </summary>
    vector<vector<int>> minScore(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2393. Count Strictly Increasing Subarrays
    ///                                                  
    /// Medium
    ///
    /// You are given an array nums consisting of positive integers.
    ///
    /// Return the number of subarrays of nums that are in strictly 
    /// increasing order.
    ///
    /// A subarray is a contiguous part of an array.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [1,3,5,4,4,6]
    /// Output: 10
    /// Explanation: The strictly increasing subarrays are the following:
    /// - Subarrays of length 1: [1], [3], [5], [4], [4], [6].
    /// - Subarrays of length 2: [1,3], [3,5], [4,6].
    /// - Subarrays of length 3: [1,3,5].
    /// The total number of subarrays is 6 + 3 + 1 = 10.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,5]
    /// Output: 15
    /// Explanation: Every subarray is strictly increasing. There 
    /// are 15 possible subarrays that we can take.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    long long countSubarrays(vector<int>& nums);

    /// <summary>
    /// Leet Code 2395. Find Subarrays With Equal Sum
    ///                                                  
    /// Easy
    ///
    /// Given a 0-indexed integer array nums, determine whether there exist 
    /// two subarrays of length 2 with equal sum. Note that the two 
    /// subarrays must begin at different indices.
    ///
    /// Return true if these subarrays exist, and false otherwise.
    /// A subarray is a contiguous non-empty sequence of elements 
    /// within an array.
    ///
    /// Example 1:
    /// Input: nums = [4,2,4]
    /// Output: true
    /// Explanation: The subarrays with elements [4,2] and [2,4] have the 
    /// same sum of 6.
    ///
    /// Example 2:
    ///
    /// Input: nums = [1,2,3,4,5]
    /// Output: false
    /// Explanation: No two subarrays of size 2 have the same sum.
    ///
    /// Example 3:
    /// Input: nums = [0,0,0]
    /// Output: true
    /// Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] 
    /// have the same sum of 0. 
    /// Note that even though the subarrays have the same content, the two 
    /// subarrays are considered different because they are in different 
    /// positions in the original array.
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 1000
    /// 2. -10^9 <= nums[i] <= 10^9
    /// </summary>
    bool findSubarrays(vector<int>& nums);

    /// <summary>
    /// Leet Code 2389. Longest Subsequence With Limited Sum
    ///                                                  
    /// Easy
    ///
    /// You are given an integer array nums of length n, and an integer array 
    /// queries of length m.
    ///
    /// Return an array answer of length m where answer[i] is the maximum 
    /// size of a subsequence that you can take from nums such that the sum 
    /// of its elements is less than or equal to queries[i].
    ///
    /// A subsequence is an array that can be derived from another array by 
    /// deleting some or no elements without changing the order of the 
    /// remaining elements.
    ///
    /// Example 1:
    /// Input: nums = [4,5,2,1], queries = [3,10,21]
    /// Output: [2,3,4]
    /// Explanation: We answer the queries as follows:
    /// - The subsequence [2,1] has a sum less than or equal to 3. It can be 
    ///   proven that 2 is the maximum size of such a subsequence, so 
    ///   answer[0] = 2.
    /// - The subsequence [4,5,1] has a sum less than or equal to 10. It can be 
    ///   proven that 3 is the maximum size of such a subsequence, so 
    ///   answer[1] = 3.
    /// - The subsequence [4,5,2,1] has a sum less than or equal to 21. It can 
    ///   be proven that 4 is the maximum size of such a subsequence, so 
    ///   answer[2] = 4.
    ///
    /// Example 2:
    /// Input: nums = [2,3,4,5], queries = [1]
    /// Output: [0]
    /// Explanation: The empty subsequence is the only subsequence that has a 
    /// sum less than or equal to 1, so answer[0] = 0.
    ///
    /// Constraints:
    /// 1. n == nums.length
    /// 2. m == queries.length
    /// 3. 1 <= n, m <= 1000
    /// 4. 1 <= nums[i], queries[i] <= 10^6
    /// </summary>
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries);

    /// <summary>
    /// Leet Code 2397. Maximum Rows Covered by Columns
    ///                                                  
    /// Medium
    ///
    /// You are given a 0-indexed m x n binary matrix matrix and an integer 
    /// numSelect, which denotes the number of distinct columns you must 
    /// select from matrix.
    ///
    /// Let us consider s = {c1, c2, ...., cnumSelect} as the set of columns 
    /// selected by you. A row row is covered by s if:
    ///
    /// For each cell matrix[row][col] (0 <= col <= n - 1) where 
    /// matrix[row][col] == 1, col is present in s or,
    /// No cell in row has a value of 1.
    /// You need to choose numSelect columns such that the number of rows that 
    /// are covered is maximized.
    ///
    /// Return the maximum number of rows that can be covered by a set of 
    /// numSelect columns.
    /// 
    /// Example 1:
    /// 
    /// Input: matrix = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], numSelect = 2
    /// Output: 3
    /// Explanation: One possible way to cover 3 rows is shown in the diagram 
    /// above.
    /// We choose s = {0, 2}.
    /// - Row 0 is covered because it has no occurrences of 1.
    /// - Row 1 is covered because the columns with value 1, i.e. 0 and 2 are 
    ///   present in s.
    /// - Row 2 is not covered because matrix[2][1] == 1 but 1 is not 
    ///   present in s.
    /// - Row 3 is covered because matrix[2][2] == 1 and 2 is present in s.
    /// Thus, we can cover three rows.
    /// Note that s = {1, 2} will also cover 3 rows, but it can be shown that 
    /// no more than three rows can be covered.
    ///
    /// Example 2:
    /// 
    /// Input: matrix = [[1],[0]], numSelect = 1
    /// Output: 2
    /// Explanation: Selecting the only column will result in both rows being 
    /// covered since the entire matrix is selected.
    /// Therefore, we return 2.
    ///
    /// Constraints:
    /// 1. m == matrix.length
    /// 2. n == matrix[i].length
    /// 3. 1 <= m, n <= 12
    /// 4. matrix[i][j] is either 0 or 1.
    /// 5. 1 <= numSelect <= n
    /// </summary>
    int maximumRows(vector<vector<int>>& matrix, int numSelect);

    /// <summary>
    /// Leet Code 2401. Longest Nice Subarray 
    ///                                                  
    /// Medium
    ///
    /// You are given an array nums consisting of positive integers.
    ///
    /// We call a subarray of nums nice if the bitwise AND of every pair 
    /// of elements that are in different positions in the subarray is 
    /// equal to 0.
    ///
    /// Return the length of the longest nice subarray.
    ///
    /// A subarray is a contiguous part of an array.
    ///
    /// Note that subarrays of length 1 are always considered nice.
    ///
    /// Example 1:
    /// Input: nums = [1,3,8,48,10]
    /// Output: 3
    /// Explanation: The longest nice subarray is [3,8,48]. This subarray 
    /// satisfies the conditions:
    /// - 3 AND 8 = 0.
    /// - 3 AND 48 = 0.
    /// - 8 AND 48 = 0.
    /// It can be proven that no longer nice subarray can be obtained, 
    /// so we return 3.
    ///
    /// Example 2:
    /// Input: nums = [3,1,5,11,13]
    /// Output: 1
    /// Explanation: The length of the longest nice subarray is 1. Any 
    /// subarray of length 1 can be chosen.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    int longestNiceSubarray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2428. Maximum Sum of an Hourglass
    ///                                                  
    /// Medium
    ///
    /// You are given an m x n integer matrix grid.
    ///
    /// We define an hourglass as a part of the matrix with the following form:
    ///
    /// Return the maximum sum of the elements of an hourglass.
    ///
    /// Note that an hourglass cannot be rotated and must be entirely contained 
    /// within the matrix.
    /// 
    ///
    /// Example 1:
    /// Input: grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
    /// Output: 30
    /// Explanation: The cells shown above represent the hourglass with the 
    /// maximum sum: 6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.
    ///
    /// Example 2:
    /// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
    /// Output: 35
    /// Explanation: There is only one hourglass in the matrix, with the 
    /// sum: 1 + 2 + 3 + 5 + 7 + 8 + 9 = 35.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 3 <= m, n <= 150
    /// 4. 0 <= grid[i][j] <= 10^6
    /// </summary>
    int maxSum(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2420. Find All Good Indices
    ///                                                  
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums of size n and a positive 
    /// integer k.
    ///
    /// We call an index i in the range k <= i < n - k good if the following 
    /// conditions are satisfied:
    ///
    /// The k elements that are just before the index i are in non-increasing 
    /// order.
    /// The k elements that are just after the index i are in non-decreasing 
    /// order.
    /// Return an array of all good indices sorted in increasing order.
    ///
    /// Example 1:
    /// Input: nums = [2,1,1,1,3,4,1], k = 2
    /// Output: [2,3]
    /// Explanation: There are two good indices in the array:
    /// - Index 2. The subarray [2,1] is in non-increasing order, and the 
    ///   subarray [1,3] is in non-decreasing order.
    /// - Index 3. The subarray [1,1] is in non-increasing order, and the 
    ///   subarray [3,4] is in non-decreasing order.
    /// Note that the index 4 is not good because [4,1] is not non-decreasing.
    ///
    /// Example 2:
    /// Input: nums = [2,1,1,2], k = 2
    /// Output: []
    /// Explanation: There are no good indices in this array.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 3 <= n <= 10^5
    /// 3. 1 <= nums[i] <= 10^6
    /// 4. 1 <= k <= n / 2
    /// </summary>
    vector<int> goodIndices(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2419. Longest Subarray With Maximum Bitwise AND
    ///                                                  
    /// Medium
    ///
    /// You are given an integer array nums of size n.
    ///
    /// Consider a non-empty subarray from nums that has the maximum possible 
    /// bitwise AND.
    ///
    /// In other words, let k be the maximum value of the bitwise AND of any 
    /// subarray of nums. Then, only subarrays with a bitwise AND equal to k 
    /// should be considered.
    /// Return the length of the longest such subarray.
    ///
    /// The bitwise AND of an array is the bitwise AND of all the numbers in 
    /// it.
    ///
    /// A subarray is a contiguous sequence of elements within an array.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [1,2,3,3,2,2]
    /// Output: 2
    /// Explanation:
    /// The maximum possible bitwise AND of a subarray is 3.
    /// The longest subarray with that value is [3,3], so we return 2.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4]
    /// Output: 1
    /// Explanation:
    /// The maximum possible bitwise AND of a subarray is 4.
    /// The longest subarray with that value is [4], so we return 1.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    int longestSubarrayAnd(vector<int>& nums);

    /// <summary>
    /// Leet Code 2411. Smallest Subarrays With Maximum Bitwise OR
    ///                                                  
    /// Medium
    ///
    /// You are given a 0-indexed array nums of length n, consisting of 
    /// non-negative integers. For each index i from 0 to n - 1, you must 
    /// determine the size of the minimum sized non-empty subarray of nums 
    /// starting at i (inclusive) that has the maximum possible bitwise OR.
    ///
    /// In other words, let Bij be the bitwise OR of the subarray nums[i...j]. 
    /// You need to find the smallest subarray starting at i, such that 
    /// bitwise OR of this subarray is equal to max(Bik) where i <= k <= n - 1.
    /// The bitwise OR of an array is the bitwise OR of all the numbers in it.
    ///
    /// Return an integer array answer of size n where answer[i] is the length 
    /// of the minimum sized subarray starting at i with maximum bitwise OR.
    /// 
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    ///
    /// Example 1:
    /// Input: nums = [1,0,2,1,3]
    /// Output: [3,3,2,2,1]
    /// Explanation:
    /// The maximum possible bitwise OR starting at any index is 3. 
    /// - Starting at index 0, the shortest subarray that yields it is [1,0,2].
    /// - Starting at index 1, the shortest subarray that yields the maximum 
    ///   bitwise OR is [0,2,1].
    /// - Starting at index 2, the shortest subarray that yields the maximum 
    ///   bitwise OR is [2,1].
    /// - Starting at index 3, the shortest subarray that yields the maximum 
    ///   bitwise OR is [1,3].
    /// - Starting at index 4, the shortest subarray that yields the maximum 
    ///   bitwise OR is [3].
    /// Therefore, we return [3,3,2,2,1]. 
    ///
    /// Example 2:
    /// Input: nums = [1,2]
    /// Output: [2,1]
    /// Explanation:
    /// Starting at index 0, the shortest subarray that yields the maximum 
    /// bitwise OR is of length 2.
    /// Starting at index 1, the shortest subarray that yields the maximum 
    /// bitwise OR is of length 1.
    /// Therefore, we return [2,1].
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^5
    /// 3. 0 <= nums[i] <= 10^9
    /// </summary>
    vector<int> smallestSubarraysOr(vector<int>& nums);

    /// <summary>
    /// Leet Code 2426. Number of Pairs Satisfying Inequality
    ///                                                  
    /// Hard
    ///
    /// You are given two 0-indexed integer arrays nums1 and nums2, each of 
    /// size n, and an integer diff. Find the number of pairs (i, j) such that:
    ///
    /// 0 <= i < j <= n - 1 and
    /// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
    /// Return the number of pairs that satisfy the conditions.
    ///
    /// Example 1:
    /// Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
    /// Output: 3
    /// Explanation:
    /// There are 3 pairs that satisfy the conditions:
    /// 1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. 
    ///    Since i < j and 1 <= 1, this pair satisfies the conditions.
    /// 2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. 
    ///    Since i < j and -2 <= 2, this pair satisfies the conditions.
    /// 3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. 
    /// Since i < j and -3 <= 2, this pair satisfies the conditions.
    /// Therefore, we return 3.
    ///
    /// Example 2:
    /// Input: nums1 = [3,-1], nums2 = [-2,2], diff = -1
    /// Output: 0
    /// Explanation:
    /// Since there does not exist any pair that satisfies the conditions, 
    /// we return 0.
    ///
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 2 <= n <= 10^5
    /// 3. -10^4 <= nums1[i], nums2[i] <= 10^4
    /// 4. -10^4 <= diff <= 10^4
    /// </summary>
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff);

    /// <summary>
    /// Leet Code 2432. The Employee That Worked on the Longest Task
    ///                                                  
    /// Easy
    ///
    /// There are n employees, each with a unique id from 0 to n - 1.
    ///
    /// You are given a 2D integer array logs where 
    /// logs[i] = [idi, leaveTimei] where:
    ///
    /// idi is the id of the employee that worked on the ith task, and
    /// leaveTimei is the time at which the employee finished the ith task. 
    /// All the values leaveTimei are unique.
    /// Note that the ith task starts the moment right after the (i - 1)th 
    /// task ends, and the 0th task starts at time 0.
    ///
    /// Return the id of the employee that worked the task with the longest 
    /// time. If there is a tie between two or more employees, return the 
    /// smallest id among them.
    ///
    /// Example 1:
    /// Input: n = 10, logs = [[0,3],[2,5],[0,9],[1,15]]
    /// Output: 1
    /// Explanation: 
    /// Task 0 started at 0 and ended at 3 with 3 units of times.
    /// Task 1 started at 3 and ended at 5 with 2 units of times.
    /// Task 2 started at 5 and ended at 9 with 4 units of times.
    /// Task 3 started at 9 and ended at 15 with 6 units of times.
    /// The task with the longest time is task 3 and the employee with 
    /// id 1 is the one that worked on it, so we return 1.
    ///
    /// Example 2:
    /// Input: n = 26, logs = [[1,1],[3,7],[2,12],[7,17]]
    /// Output: 3
    /// Explanation: 
    /// Task 0 started at 0 and ended at 1 with 1 unit of times.
    /// Task 1 started at 1 and ended at 7 with 6 units of times.
    /// Task 2 started at 7 and ended at 12 with 5 units of times.
    /// Task 3 started at 12 and ended at 17 with 5 units of times.
    /// The tasks with the longest time is task 1. The employees that worked 
    /// on it is 3, so we return 3.
    ///
    /// Example 3:
    /// Input: n = 2, logs = [[0,10],[1,20]]
    /// Output: 0
    /// Explanation: 
    /// Task 0 started at 0 and ended at 10 with 10 units of times.
    /// Task 1 started at 10 and ended at 20 with 10 units of times.
    /// The tasks with the longest time are tasks 0 and 1. The employees that 
    /// worked on them are 0 and 1, so we return the smallest id 0.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 500
    /// 2. 1 <= logs.length <= 500
    /// 3. logs[i].length == 2
    /// 4. 0 <= idi <= n - 1
    /// 5. 1 <= leaveTimei <= 500
    /// 6. idi != idi+1
    /// 7. leaveTimei are sorted in a strictly increasing order.
    /// </summary>
    int hardestWorker(int n, vector<vector<int>>& logs);

    /// <summary>
    /// Leet Code 2445. Number of Nodes With Value One   
    ///                                                  
    /// Hard
    ///
    /// You are given two positive integer arrays nums and target, of the 
    /// same length.
    ///
    /// In one operation, you can choose any two distinct indices i and j 
    /// where 0 <= i, j < nums.length and:
    ///
    /// set nums[i] = nums[i] + 2 and
    /// set nums[j] = nums[j] - 2.
    /// Two arrays are considered to be similar if the frequency of each 
    /// element is the same.
    ///
    /// Return the minimum number of operations required to make nums 
    /// similar to target. The test cases are generated such that nums 
    /// can always be similar to target.
    ///
    /// Example 1:
    ///
    /// Input: nums = [8,12,6], target = [2,14,10]
    /// Output: 2
    /// Explanation: It is possible to make nums similar to target in two 
    /// operations:
    /// - Choose i = 0 and j = 2, nums = [10,12,4].
    /// - Choose i = 1 and j = 2, nums = [10,14,2].
    /// It can be shown that 2 is the minimum number of operations needed.
    ///
    /// Example 2:
    /// Input: nums = [1,2,5], target = [4,1,3]
    /// Output: 1
    /// Explanation: We can make nums similar to target in one operation:
    /// - Choose i = 1 and j = 2, nums = [1,4,3].
    ///
    /// Example 3:
    /// Input: nums = [1,1,1,1,1], target = [1,1,1,1,1]
    /// Output: 0
    /// Explanation: The array nums is already similiar to target.
    /// 
    /// Constraints:
    /// 1. n == nums.length == target.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums[i], target[i] <= 10^6
    /// 4. It is possible to make nums similar to target.
    /// </summary>
    long long makeSimilar(vector<int>& nums, vector<int>& target);

    /// <summary>
    /// Leet Code 2460. Apply Operations to an Array 
    ///                                                  
    /// Easy
    ///
    /// You are given a 0-indexed array nums of size n consisting of non-
    /// negative integers.
    ///
    /// You need to apply n - 1 operations to this array where, in the ith 
    /// operation (0-indexed), you will apply the following on the ith 
    /// element of nums:
    ///
    /// If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set 
    /// nums[i + 1] to 0. Otherwise, you skip this operation.
    /// After performing all the operations, shift all the 0's to the end 
    /// of the array.
    ///
    /// For example, the array [1,0,2,0,0,1] after shifting all its 0's to 
    /// the end, is [1,2,1,0,0,0].
    /// Return the resulting array.
    ///
    /// Note that the operations are applied sequentially, not all at once.
    ///
    /// Example 1:
    /// Input: nums = [1,2,2,1,1,0]
    /// Output: [1,4,2,0,0,0]
    /// Explanation: We do the following operations:
    /// - i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
    /// - i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and 
    /// change nums[2] to 0. The array becomes [1,4,0,1,1,0].
    /// - i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
    /// - i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and 
    /// change nums[4] to 0. The array becomes [1,4,0,2,0,0].
    /// - i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and 
    /// change nums[5] to 0. The array becomes [1,4,0,2,0,0].
    /// After that, we shift the 0's to the end, which gives the array 
    /// [1,4,2,0,0,0].
    ///
    /// Example 2:
    /// Input: nums = [0,1]
    /// Output: [1,0]
    /// Explanation: No operation can be applied, we just shift the 0 to 
    /// the end.
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 2000
    /// 2. 0 <= nums[i] <= 1000
    /// </summary>
    vector<int> applyOperations(vector<int>& nums);

    /// <summary>
    /// Leet Code 2459. Sort Array by Moving Items to Empty Space
    /// 
    /// Hard
    ///	
    /// You are given an integer array nums of size n containing each element 
    /// from 0 to n - 1 (inclusive). Each of the elements from 1 to n - 1 
    /// represents an item, and the element 0 represents an empty space.
    /// 
    /// In one operation, you can move any item to the empty space. nums is 
    /// considered to be sorted if the numbers of all the items are in 
    /// ascending order and the empty space is either at the beginning or 
    /// at the end of the array.
    /// 
    /// For example, if n = 4, nums is sorted if:
    /// 
    /// nums = [0,1,2,3] or
    /// nums = [1,2,3,0]
    /// ...and considered to be unsorted otherwise.
    ///
    /// Return the minimum number of operations needed to sort nums.
    ///
    /// Example 1:
    /// Input: nums = [4,2,0,3,1]
    /// Output: 3
    /// Explanation:
    /// - Move item 2 to the empty space. Now, nums = [4,0,2,3,1].
    /// - Move item 1 to the empty space. Now, nums = [4,1,2,3,0].
    /// - Move item 4 to the empty space. Now, nums = [0,1,2,3,4].
    /// It can be proven that 3 is the minimum number of operations needed.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,0]
    /// Output: 0
    /// Explanation: nums is already sorted so return 0.
    ///
    /// Example 3:
    /// Input: nums = [1,0,2,4,3]
    /// Output: 2
    /// Explanation:
    /// - Move item 2 to the empty space. Now, nums = [1,2,0,4,3].
    /// - Move item 3 to the empty space. Now, nums = [1,2,3,4,0].
    /// It can be proven that 2 is the minimum number of operations needed.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 2 <= n <= 105
    /// 3. 0 <= nums[i] < n
    /// 4. All the values of nums are unique.
    /// </summary>
    int sortArray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2475. Number of Unequal Triplets in Array
    /// 
    /// Easy
    ///	
    /// You are given a 0-indexed array of positive integers nums. Find the 
    /// number of triplets (i, j, k) that meet the following conditions:
    ///
    /// 0 <= i < j < k < nums.length
    /// nums[i], nums[j], and nums[k] are pairwise distinct.
    /// In other words, nums[i] != nums[j], nums[i] != nums[k], and 
    /// nums[j] != nums[k].
    /// Return the number of triplets that meet the conditions.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [4,4,2,4,3]
    /// Output: 3
    /// Explanation: The following triplets meet the conditions:
    /// - (0, 2, 4) because 4 != 2 != 3
    /// - (1, 2, 4) because 4 != 2 != 3
    /// - (2, 3, 4) because 2 != 4 != 3
    /// Since there are 3 triplets, we return 3.
    /// Note that (2, 0, 4) is not a valid triplet because 2 > 0.
    ///
    /// Example 2:
    ///  
    /// Input: nums = [1,1,1,1,1]
    /// Output: 0
    /// Explanation: No triplets meet the conditions so we return 0.
    /// 
    /// Constraints:
    /// 1. 3 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 1000
    /// </summary>
    int unequalTriplets(vector<int>& nums);

    /// <summary>
    /// Leet Code 2465. Number of Distinct Averages
    /// 
    /// Easy
    ///	
    /// You are given a 0-indexed integer array nums of even length.
    ///
    /// As long as nums is not empty, you must repetitively:
    ///
    /// Find the minimum number in nums and remove it.
    /// Find the maximum number in nums and remove it.
    /// Calculate the average of the two removed numbers.
    /// The average of two numbers a and b is (a + b) / 2.
    ///
    /// For example, the average of 2 and 3 is (2 + 3) / 2 = 2.5.
    /// Return the number of distinct averages calculated using the above 
    /// process.
    ///
    /// Note that when there is a tie for a minimum or maximum number, any 
    /// can be removed.
    /// 
    /// Example 1:
    /// Input: nums = [4,1,4,0,3,5]
    /// Output: 2
    /// Explanation:
    /// 1. Remove 0 and 5, and the average is (0 + 5) / 2 = 2.5. Now, 
    ///    nums = [4,1,4,3].
    /// 2. Remove 1 and 4. The average is (1 + 4) / 2 = 2.5, and 
    ///    nums = [4,3].
    /// 3. Remove 3 and 4, and the average is (3 + 4) / 2 = 3.5.
    /// Since there are 2 distinct numbers among 2.5, 2.5, and 3.5, we 
    /// return 2.
    ///
    /// Example 2:
    /// Input: nums = [1,100]
    /// Output: 1
    /// Explanation:
    /// There is only one average to be calculated after removing 1 and 100, 
    /// so we return 1.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 100
    /// 2. nums.length is even.
    /// 3. 0 <= nums[i] <= 100
    /// </summary>
    int distinctAverages(vector<int>& nums);

    /// <summary>
    /// Leet Code 2482. Difference Between Ones and Zeros in Row and Column
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed m x n binary matrix grid.
    ///
    /// A 0-indexed m x n difference matrix diff is created with the following 
    /// procedure:
    ///
    /// Let the number of ones in the ith row be onesRowi.
    /// Let the number of ones in the jth column be onesColj.
    /// Let the number of zeros in the ith row be zerosRowi.
    /// Let the number of zeros in the jth column be zerosColj.
    /// diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
    /// Return the difference matrix diff.
    ///
    /// Example 1:
    /// 
    /// Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
    /// Output: [[0,0,4],[0,0,4],[-2,-2,2]]
    /// Explanation:
    /// - diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 
    ///   2 + 1 - 1 - 2 = 0 
    /// - diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 
    ///   2 + 1 - 1 - 2 = 0 
    /// - diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 
    ///   2 + 3 - 1 - 0 = 4 
    /// - diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 
    ///   2 + 1 - 1 - 2 = 0 
    /// - diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 
    ///   2 + 1 - 1 - 2 = 0 
    /// - diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 
    ///   2 + 3 - 1 - 0 = 4 
    /// - diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 
    ///   1 + 1 - 2 - 2 = -2
    /// - diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 
    ///   1 + 1 - 2 - 2 = -2
    /// - diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 
    ///   1 + 3 - 2 - 0 = 2
    ///
    /// Example 2:
    /// Input: grid = [[1,1,1],[1,1,1]]
    /// Output: [[5,5,5],[5,5,5]]
    /// Explanation:
    /// - diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 
    ///   3 + 2 - 0 - 0 = 5
    /// - diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 
    ///   3 + 2 - 0 - 0 = 5
    /// - diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 
    //    3 + 2 - 0 - 0 = 5
    /// - diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 
    ///   3 + 2 - 0 - 0 = 5
    /// - diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 
    ///   3 + 2 - 0 - 0 = 5
    /// - diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 
    ///   3 + 2 - 0 - 0 = 5
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 105
    /// 4. 1 <= m * n <= 105
    /// 5. grid[i][j] is either 0 or 1.
    /// </summary>
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2483. Minimum Penalty for a Shop
    /// 
    /// Medium
    ///	
    /// You are given the customer visit log of a shop represented by a 
    /// 0-indexed string customers consisting only of characters 'N' and 'Y':
    ///
    /// if the ith character is 'Y', it means that customers come at the ith 
    /// hour
    /// whereas 'N' indicates that no customers come at the ith hour.
    /// If the shop closes at the jth hour (0 <= j <= n), the penalty is 
    /// calculated as follows:
    ///
    /// For every hour when the shop is open and no customers come, the 
    /// penalty increases by 1.
    /// For every hour when the shop is closed and customers come, the 
    /// penalty increases by 1.
    /// Return the earliest hour at which the shop must be closed to incur a 
    /// minimum penalty.
    ///
    /// Note that if a shop closes at the jth hour, it means the shop is 
    /// closed at the hour j.
    /// 
    /// Example 1:
    /// Input: customers = "YYNY"
    /// Output: 2
    /// Explanation: 
    /// - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
    /// - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
    /// - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
    /// - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
    /// - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
    /// Closing the shop at 2nd or 4th hour gives a minimum penalty. 
    /// Since 2 is earlier, the optimal closing time is 2.
    ///
    /// Example 2:
    /// Input: customers = "NNNNN"
    /// Output: 0
    /// Explanation: It is best to close the shop at the 0th hour as no 
    /// customers arrive.
    ///
    /// Example 3:
    /// Input: customers = "YYYY"
    /// Output: 4
    /// Explanation: It is best to close the shop at the 4th hour as 
    /// customers arrive at each hour.
    ///
    /// 
    /// Constraints:
    /// 
    /// 1. 1 <= customers.length <= 10^5
    /// 2. customers consists only of characters 'Y' and 'N'.
    /// </summary>
    int bestClosingTime(string customers);

    /// <summary>
    /// Leet Code 2500. Delete Greatest Value in Each Row
    /// 
    /// Easy
    ///	
    /// You are given an m x n matrix grid consisting of positive integers.
    ///
    /// Perform the following operation until grid becomes empty:
    ///
    /// Delete the element with the greatest value from each row. If multiple 
    /// such elements exist, delete any of them.
    /// Add the maximum of deleted elements to the answer.
    /// Note that the number of columns decreases by one after each operation.
    ///
    /// Return the answer after performing the operations described above.
    /// 
    /// Example 1:
    /// Input: grid = [[1,2,4],[3,3,1]]
    /// Output: 8
    /// Explanation: The diagram above shows the removed values in each step.
    /// - In the first operation, we remove 4 from the first row and 3 from 
    ///   the second row (notice that, there are two cells with value 3 and 
    ///   we can remove any of them). We add 4 to the answer.
    /// - In the second operation, we remove 2 from the first row and 3 from 
    ///   the second row. We add 3 to the answer.
    /// - In the third operation, we remove 1 from the first row and 1 from 
    ///   the second row. We add 1 to the answer.
    /// The final answer = 4 + 3 + 1 = 8.
    ///
    /// Example 2:
    /// Input: grid = [[10]]
    /// Output: 10
    /// Explanation: The diagram above shows the removed values in each step.
    /// - In the first operation, we remove 10 from the first row. We add 10 
    ///   to the answer.
    /// The final answer = 10.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 50
    /// 4. 1 <= grid[i][j] <= 100
    /// </summary>
    int deleteGreatestValue(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2470. Number of Subarrays With LCM Equal to K
    /// 
    /// Medium
    ///	
    /// Given an integer array nums and an integer k, return the number of 
    /// subarrays of nums where the least common multiple of the subarray's 
    /// elements is k.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    ///
    /// The least common multiple of an array is the smallest positive 
    /// integer that is divisible by all the array elements.
    ///
    /// Example 1:
    ///  
    /// Input: nums = [3,6,2,7,1], k = 6
    /// Output: 4
    /// Explanation: The subarrays of nums where 6 is the least common 
    /// multiple of all the subarray's elements are:
    /// - [3,6,2,7,1]
    /// - [3,6,2,7,1]
    /// - [3,6,2,7,1]
    /// - [3,6,2,7,1]
    ///
    /// Example 2:
    /// Input: nums = [3], k = 2
    /// Output: 0
    /// Explanation: There are no subarrays of nums where 2 is the least 
    /// common multiple of all the subarray's elements.
    ///  
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i], k <= 1000
    /// </summary>
    int subarrayLCM(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2489. Number of Substrings With Fixed Ratio
    /// 
    /// Medium
    ///	
    /// You are given a binary string s, and two integers num1 and num2. num1 
    /// and num2 are coprime numbers.
    ///
    /// A ratio substring is a substring of s where the ratio between the 
    /// number of 0's and the number of 1's in the substring is exactly 
    /// num1 : num2.
    ///
    /// For example, if num1 = 2 and num2 = 3, then "01011" and "1110000111" 
    /// are ratio substrings, while "11000" is not.
    /// Return the number of non-empty ratio substrings of s.
    ///
    /// Note that:
    /// A substring is a contiguous sequence of characters within a string.
    /// Two values x and y are coprime if gcd(x, y) == 1 where gcd(x, y) is 
    /// the greatest common divisor of x and y.
    /// 
    /// Example 1:
    /// Input: s = "0110011", num1 = 1, num2 = 2
    /// Output: 4
    /// Explanation: There exist 4 non-empty ratio substrings.
    /// - The substring s[0..2]: "0110011". It contains one 0 and two 1's. 
    ///   The ratio is 1 : 2.
    /// - The substring s[1..4]: "0110011". It contains one 0 and two 1's. 
    ///   The ratio is 1 : 2.
    /// - The substring s[4..6]: "0110011". It contains one 0 and two 1's. 
    ///   The ratio is 1 : 2.
    /// - The substring s[1..6]: "0110011". It contains two 0's and four 1's. 
    ///   The ratio is 2 : 4 == 1 : 2.
    /// It can be shown that there are no more ratio substrings.
    ///
    /// Example 2:
    /// Input: s = "10101", num1 = 3, num2 = 1
    /// Output: 0
    /// Explanation: There is no ratio substrings of s. We return 0.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. 1 <= num1, num2 <= s.length
    /// 3. num1 and num2 are coprime integers.
    /// </summary>
    long long fixedRatio(string s, int num1, int num2);

    /// <summary>
    /// Leet Code 2498. Frog Jump II
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array stones sorted in strictly 
    /// increasing order representing the positions of stones in a river.
    ///
    /// A frog, initially on the first stone, wants to travel to the last 
    /// stone and then return to the first stone. However, it can jump to 
    /// any stone at most once.
    ///
    /// The length of a jump is the absolute difference between the position 
    /// of the stone the frog is currently on and the position of the stone 
    /// to which the frog jumps.
    ///
    /// More formally, if the frog is at stones[i] and is jumping to 
    /// stones[j], the length of the jump is |stones[i] - stones[j]|.
    /// The cost of a path is the maximum length of a jump among all jumps 
    /// in the path.
    /// 
    /// Return the minimum cost of a path for the frog.
    /// Example 1:
    /// Input: stones = [0,2,5,6,7]
    /// Output: 5
    /// Explanation: The above figure represents one of the optimal paths 
    /// the frog can take.
    /// The cost of this path is 5, which is the maximum length of a jump.
    /// Since it is not possible to achieve a cost of less than 5, we return 
    /// it.
    ///
    /// Example 2:
    /// Input: stones = [0,3,9]
    /// Output: 9
    /// Explanation: 
    /// The frog can jump directly to the last stone and come back to the 
    /// first stone. 
    /// In this case, the length of each jump will be 9. The cost for the 
    /// path will be max(9, 9) = 9.
    /// It can be shown that this is the minimum achievable cost.
    /// 
    /// Constraints:
    /// 1. 2 <= stones.length <= 10^5
    /// 2. 0 <= stones[i] <= 10^9
    /// 3. stones[0] == 0
    /// 4. stones is sorted in a strictly increasing order.
    /// </summary>
    int maxJump(vector<int>& stones);

    /// <summary>
    /// Leet Code 2488. Count Subarrays With Median K
    /// 
    /// Hard
    ///	
    /// You are given an array nums of size n consisting of distinct integers 
    /// from 1 to n and a positive integer k.
    ///
    /// Return the number of non-empty subarrays in nums that have a median 
    /// equal to k.
    ///
    /// Note:
    /// The median of an array is the middle element after sorting the array 
    /// in ascending order. If the array is of even length, the median is the 
    /// left middle element.
    /// For example, the median of [2,3,1,4] is 2, and the 
    /// median of [8,4,3,5,1] is 4.
    /// A subarray is a contiguous part of an array.
    /// 
    /// Example 1:
    /// Input: nums = [3,2,1,4,5], k = 4
    /// Output: 3
    /// Explanation: The subarrays that have a median equal to 4 are: [4], 
    /// [4,5] and [1,4,5].
    /// Example 2:
    ///
    /// Input: nums = [2,3,1], k = 3
    /// Output: 1
    /// Explanation: [3] is the only subarray that has a median equal to 3.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums[i], k <= n
    /// 4. The integers in nums are distinct.
    /// </summary>
    int countSubarrays(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2499. Minimum Total Cost to Make Arrays Unequal
    /// 
    /// Hard
    ///	
    /// You are given two 0-indexed integer arrays nums1 and nums2, of equal 
    /// length n.
    ///
    /// In one operation, you can swap the values of any two indices of nums1. 
    /// The cost of this operation is the sum of the indices.
    ///
    /// Find the minimum total cost of performing the given operation any 
    /// number of times such that nums1[i] != nums2[i] for all 
    /// 0 <= i <= n - 1 after performing all the operations.
    ///
    /// Return the minimum total cost such that nums1 and nums2 satisfy 
    /// the above condition. In case it is not possible, return -1.
    ///
    /// Example 1:
    /// Input: nums1 = [1,2,3,4,5], nums2 = [1,2,3,4,5]
    /// Output: 10
    /// Explanation: 
    /// One of the ways we can perform the operations is:
    /// - Swap values at indices 0 and 3, incurring cost = 0 + 3 = 3. 
    ///   Now, nums1 = [4,2,3,1,5]
    /// - Swap values at indices 1 and 2, incurring cost = 1 + 2 = 3. 
    ///   Now, nums1 = [4,3,2,1,5].
    /// - Swap values at indices 0 and 4, incurring cost = 0 + 4 = 4. 
    ///   Now, nums1 =[5,3,2,1,4].
    /// We can see that for each index i, nums1[i] != nums2[i]. 
    /// The cost required here is 10.
    /// Note that there are other ways to swap values, but it can be proven 
    /// that it is not possible to obtain a cost less than 10.
    ///
    /// Example 2:
    /// Input: nums1 = [2,2,2,1,3], nums2 = [1,2,2,3,3]
    /// Output: 10
    /// Explanation: 
    /// One of the ways we can perform the operations is:
    /// - Swap values at indices 2 and 3, incurring cost = 2 + 3 = 5. 
    ///   Now, nums1 = [2,2,1,2,3].
    /// - Swap values at indices 1 and 4, incurring cost = 1 + 4 = 5. 
    ///   Now, nums1 = [2,3,1,2,2].
    /// The total cost needed here is 10, which is the minimum possible.
    ///
    /// Example 3:
    /// Input: nums1 = [1,2,2], nums2 = [1,2,2]
    /// Output: -1
    /// Explanation: 
    /// It can be shown that it is not possible to satisfy the given 
    /// conditions irrespective of the number of operations we perform.
    /// Hence, we return -1.
    ///
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums1[i], nums2[i] <= n
    /// </summary>
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2511. Maximum Enemy Forts That Can Be Captured
    /// 
    /// Easy
    ///	
    /// You are given a 0-indexed integer array forts of length n representing 
    /// the positions of several forts. forts[i] can be -1, 0, or 1 where:
    ///
    /// -1 represents there is no fort at the ith position.
    /// 0 indicates there is an enemy fort at the ith position.
    /// 1 indicates the fort at the ith the position is under your command.
    /// Now you have decided to move your army from one of your forts at 
    /// position i to an empty position j such that:
    ///
    /// 0 <= i, j <= n - 1
    /// The army travels over enemy forts only. Formally, for all k 
    /// where min(i,j) < k < max(i,j), forts[k] == 0.
    /// While moving the army, all the enemy forts that come in the way are 
    /// captured.
    ///
    /// Return the maximum number of enemy forts that can be captured. In 
    /// case it is impossible to move your army, or you do not have any fort 
    /// under your command, return 0.
    /// 
    /// Example 1:
    ///
    /// Input: forts = [1,0,0,-1,0,0,0,0,1]
    /// Output: 4
    /// Explanation:
    /// - Moving the army from position 0 to position 3 captures 2 enemy 
    ///   forts, at 1 and 2.
    /// - Moving the army from position 8 to position 3 captures 4 enemy forts.
    /// Since 4 is the maximum number of enemy forts that can be captured, we 
    /// return 4.
    ///
    /// Example 2:
    /// Input: forts = [0,0,1,-1]
    /// Output: 0
    /// Explanation: Since no enemy fort can be captured, 0 is returned.
    ///
    /// Constraints:
    /// 1. 1 <= forts.length <= 1000
    /// 2. -1 <= forts[i] <= 1
    /// </summary>
    int captureForts(vector<int>& forts);

    /// <summary>
    /// Leet Code 2515. Shortest Distance to Target String in a Circular Array
    /// 
    /// Easy
    ///	
    /// You are given a 0-indexed circular string array words and a string 
    /// target. A circular array means that the array's end connects to the 
    /// array's beginning.
    ///
    /// Formally, the next element of words[i] is words[(i + 1) % n] and the 
    /// previous element of words[i] is words[(i - 1 + n) % n], where n is 
    /// the length of words.
    /// Starting from startIndex, you can move to either the next word or 
    /// the previous word with 1 step at a time.
    ///
    /// Return the shortest distance needed to reach the string target. 
    /// If the string target does not exist in words, return -1.
    ///
    /// Example 1:
    /// Input: words = ["hello","i","am","leetcode","hello"], 
    /// target = "hello", startIndex = 1
    /// Output: 1
    /// Explanation: We start from index 1 and can reach "hello" by
    /// - moving 3 units to the right to reach index 4.
    /// - moving 2 units to the left to reach index 4.
    /// - moving 4 units to the right to reach index 0.
    /// - moving 1 unit to the left to reach index 0.
    /// The shortest distance to reach "hello" is 1.
    /// Example 2:
    /// Input: words = ["a","b","leetcode"], target = "leetcode", 
    /// startIndex = 0
    /// Output: 1
    /// Explanation: We start from index 0 and can reach "leetcode" by
    /// - moving 2 units to the right to reach index 3.
    /// - moving 1 unit to the left to reach index 3.
    /// The shortest distance to reach "leetcode" is 1.
    ///
    /// Example 3:
    /// Input: words = ["i","eat","leetcode"], target = "ate", 
    /// startIndex = 0
    /// Output: -1
    /// Explanation: Since "ate" does not exist in words, we return -1.
    ///
    /// Constraints:
    /// 1. 1 <= words.length <= 100
    /// 2. 1 <= words[i].length <= 100
    /// 3. words[i] and target consist of only lowercase English letters.
    /// 4. 0 <= startIndex < words.length
    /// </summary>
    int closetTarget(vector<string>& words, string target, int startIndex);

    /// <summary>
    /// Leet Code 2444. Count Subarrays With Fixed Bounds      
    ///                                                  
    /// Hard
    ///
    /// You are given an integer array nums and two integers minK and maxK.
    ///
    /// A fixed-bound subarray of nums is a subarray that satisfies the 
    /// following conditions:
    ///
    /// The minimum value in the subarray is equal to minK.
    /// The maximum value in the subarray is equal to maxK.
    /// Return the number of fixed-bound subarrays.
    ///
    /// A subarray is a contiguous part of an array.
    /// 
    /// Example 1:
    /// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
    /// Output: 2
    /// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
    ///
    /// Example 2:
    /// 
    /// Input: nums = [1,1,1,1], minK = 1, maxK = 1
    /// Output: 10
    /// Explanation: Every subarray of nums is a fixed-bound 
    /// subarray. There are 10 possible subarrays.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. 1 <= nums[i], minK, maxK <= 10^6
    /// </summary>
    long long countSubarrays(vector<int>& nums, int minK, int maxK);

    /// <summary>
    /// Leet Code 2535. Difference Between Element Sum and Digit Sum of 
    ///                 an Array
    /// 
    /// Easy
    ///	
    /// You are given a positive integer array nums.
    ///
    /// The element sum is the sum of all the elements in nums.
    /// The digit sum is the sum of all the digits (not necessarily distinct) 
    /// that appear in nums.
    /// Return the absolute difference between the element sum and digit 
    /// sum of nums.
    ///
    /// Note that the absolute difference between two integers x and y is 
    /// defined as |x - y|.
    ///
    /// Example 1:
    /// Input: nums = [1,15,6,3]
    /// Output: 9
    /// Explanation: 
    /// The element sum of nums is 1 + 15 + 6 + 3 = 25.
    /// The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
    /// The absolute difference between the element sum and digit sum 
    /// is |25 - 16| = 9.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4]
    /// Output: 0
    /// Explanation:
    /// The element sum of nums is 1 + 2 + 3 + 4 = 10.
    /// The digit sum of nums is 1 + 2 + 3 + 4 = 10.
    /// The absolute difference between the element sum and digit 
    /// sum is |10 - 10| = 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 2000
    /// 2. 1 <= nums[i] <= 2000
    /// </summary>
    int differenceOfSum(vector<int>& nums);

    /// <summary>
    /// Leet Code 2536. Increment Submatrices by One
    /// 
    /// Medium
    ///	
    /// You are given a positive integer n, indicating that we initially have 
    /// an n x n 0-indexed integer matrix mat filled with zeroes.
    ///
    /// You are also given a 2D integer array query. For each 
    /// query[i] = [row1i, col1i, row2i, col2i], you should do the following 
    /// operation:
    ///
    /// Add 1 to every element in the submatrix with the top left 
    /// corner (row1i, col1i) and the bottom right corner (row2i, col2i). 
    /// That is, add 1 to mat[x][y] for for all row1i <= x <= row2i and 
    /// col1i <= y <= col2i.
    /// Return the matrix mat after performing every query.
    /// 
    /// Example 1:
    /// Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
    /// Output: [[1,1,0],[1,2,1],[0,1,1]]
    /// Explanation: The diagram above shows the initial matrix, the matrix 
    /// after the first query, and the matrix after the second query.
    /// - In the first query, we add 1 to every element in the submatrix with 
    ///    the top left corner (1, 1) and bottom right corner (2, 2).
    /// - In the second query, we add 1 to every element in the submatrix with 
    /// the top left corner (0, 0) and bottom right corner (1, 1).
    ///
    /// Example 2:
    /// Input: n = 2, queries = [[0,0,1,1]]
    /// Output: [[1,1],[1,1]]
    /// Explanation: The diagram above shows the initial matrix and the matrix 
    /// after the first query.
    /// - In the first query we add 1 to every element in the matrix.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 500
    /// 2. 1 <= queries.length <= 10^4
    /// 3. 0 <= row1i <= row2i < n
    /// 4. 0 <= col1i <= col2i < n
    /// </summary>
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2540. Minimum Common Value
    /// 
    /// Easy
    ///	
    /// Given two integer arrays nums1 and nums2, sorted in non-decreasing 
    /// order, return the minimum integer common to both arrays. If there 
    /// is no common integer amongst nums1 and nums2, return -1.
    ///
    /// Note that an integer is said to be common to nums1 and nums2 if both 
    /// arrays have at least one occurrence of that integer.
    ///
    /// Example 1:
    /// Input: nums1 = [1,2,3], nums2 = [2,4]
    /// Output: 2
    /// Explanation: The smallest element common to both arrays is 2, so we 
    /// return 2.
    ///
    /// Example 2:
    /// Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
    /// Output: 2
    /// Explanation: There are two common elements in the array 2 and 3 out 
    /// of which 2 is the smallest, so 2 is returned.
    ///
    /// Constraints:
    /// 1. 1 <= nums1.length, nums2.length <= 10^5
    /// 2. 1 <= nums1[i], nums2[j] <= 10^9
    /// 3. Both nums1 and nums2 are sorted in non-decreasing order.
    /// </summary>
    int getCommon(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2545. Sort the Students by Their Kth Score
    /// 
    /// Medium
    ///	
    /// There is a class with m students and n exams. You are given a 
    /// 0-indexed m x n integer matrix score, where each row represents one 
    /// student and score[i][j] denotes the score the ith student got in the 
    /// jth exam. The matrix score contains distinct integers only.
    ///
    /// You are also given an integer k. Sort the students (i.e., the rows of 
    /// the matrix) by their scores in the kth (0-indexed) exam from the 
    /// highest to the lowest.
    ///
    /// Return the matrix after sorting it.
    /// 
    /// Example 1:
    /// Input: score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
    /// Output: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
    /// Explanation: In the above diagram, S denotes the student, while E 
    /// denotes the exam.
    /// - The student with index 1 scored 11 in exam 2, which is the highest 
    ///   score, so they got first place.
    /// - The student with index 0 scored 9 in exam 2, which is the second 
    ///   highest score, so they got second place.
    /// - The student with index 2 scored 3 in exam 2, which is the lowest 
    ///   score, so they got third place.
    ///
    /// Example 2:
    /// Input: score = [[3,4],[5,6]], k = 0
    /// Output: [[5,6],[3,4]]
    /// Explanation: In the above diagram, S denotes the student, while E 
    /// denotes the exam.
    /// - The student with index 1 scored 5 in exam 0, which is the highest 
    ///   score, so they got first place.
    /// - The student with index 0 scored 3 in exam 0, which is the lowest 
    ///   score, so they got second place.
    ///
    /// Constraints:
    /// 1. m == score.length
    /// 2. n == score[i].length
    /// 3. 1 <= m, n <= 250
    /// 4. 1 <= score[i][j] <= 10^5
    /// 5. score consists of distinct integers.
    /// 6. 0 <= k < n
    /// </summary>
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k);

    /// <summary>
    /// Leet Code 2541. Minimum Operations to Make Array Equal II
    /// 
    /// Medium
    ///	
    /// You are given two integer arrays nums1 and nums2 of equal length n and 
    /// an integer k. You can perform the following operation on nums1:
    ///
    /// Choose two indexes i and j and increment nums1[i] by k and decrement 
    /// nums1[j] by k. In other words, nums1[i] = nums1[i] + k and 
    /// nums1[j] = nums1[j] - k.
    /// nums1 is said to be equal to nums2 if for all indices i such that 
    /// 0 <= i < n, nums1[i] == nums2[i].
    ///
    /// Return the minimum number of operations required to make nums1 equal 
    /// to nums2. If it is impossible to make them equal, return -1.
    ///
    /// Example 1:
    /// Input: nums1 = [4,3,1,4], nums2 = [1,3,7,1], k = 3
    /// Output: 2
    /// Explanation: In 2 operations, we can transform nums1 to nums2.
    /// 1st operation: i = 2, j = 0. After applying the operation, 
    /// nums1 = [1,3,4,4].
    /// 2nd operation: i = 2, j = 3. After applying the operation, 
    /// nums1 = [1,3,7,1].
    /// One can prove that it is impossible to make arrays equal in fewer 
    /// operations.
    ///
    /// Example 2:
    /// Input: nums1 = [3,8,5,2], nums2 = [2,4,1,6], k = 1
    /// Output: -1
    /// Explanation: It can be proved that it is impossible to make the 
    /// two arrays equal.
    ///
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 2 <= n <= 10^5
    /// 3. 0 <= nums1[i], nums2[j] <= 10^9
    /// 4. 0 <= k <= 10^5
    /// </summary>
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k);

    /// <summary>
    /// Leet Code 2552. Count Increasing Quadruplets
    /// 
    /// Hard
    ///	
    /// Given a 0-indexed integer array nums of size n containing all numbers 
    /// from 1 to n, return the number of increasing quadruplets.
    ///
    /// A quadruplet (i, j, k, l) is increasing if:
    ///
    /// 0 <= i < j < k < l < n, and
    /// nums[i] < nums[k] < nums[j] < nums[l].
    ///
    /// Example 1:
    /// Input: nums = [1,3,2,4,5]
    /// Output: 2
    /// Explanation: 
    /// - When i = 0, j = 1, k = 2, and l = 3, nums[i] < nums[k] < 
    //    nums[j] < nums[l].
    /// - When i = 0, j = 1, k = 2, and l = 4, nums[i] < nums[k] < 
    ///   nums[j] < nums[l]. 
    /// There are no other quadruplets, so we return 2.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4]
    /// Output: 0
    /// Explanation: There exists only one quadruplet with i = 0, j = 1, 
    /// k = 2, l = 3, but since nums[j] < nums[k], we return 0.
    ///
    /// Constraints:
    /// 1. 4 <= nums.length <= 4000
    /// 2. 1 <= nums[i] <= nums.length
    /// 3. All the integers of nums are unique. nums is a permutation.
    /// </summary>
    long long countQuadruplets(vector<int>& nums);

    /// <summary>
    /// Leet Code 2559. Count Vowel Strings in Ranges
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed array of strings words and a 2D array of 
    /// integers queries.
    ///
    /// Each query queries[i] = [li, ri] asks us to find the number of strings 
    /// present in the range li to ri (both inclusive) of words that start and 
    /// end with a vowel.
    ///
    /// Return an array ans of size queries.length, where ans[i] is the answer 
    /// to the ith query.
    ///
    /// Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
    ///
    /// Example 1:
    /// Input: words = ["aba","bcb","ece","aa","e"], 
    /// queries = [[0,2],[1,4],[1,1]]
    /// Output: [2,3,0]
    /// Explanation: The strings starting and ending with a vowel are "aba", 
    /// "ece", "aa" and "e".
    /// The answer to the query [0,2] is 2 (strings "aba" and "ece").
    /// to query [1,4] is 3 (strings "ece", "aa", "e").
    /// to query [1,1] is 0.
    /// We return [2,3,0].
    ///
    /// Example 2:
    /// Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
    /// Output: [3,2,1]
    /// Explanation: Every string satisfies the conditions, so we return [3,2,1].
    /// 
    /// Constraints:
    /// 1. 1 <= words.length <= 10^5
    /// 2. 1 <= words[i].length <= 40
    /// 3. words[i] consists only of lowercase English letters.
    /// 4. sum(words[i].length) <= 3 * 10^5
    /// 5. 1 <= queries.length <= 10^5
    /// 6. 0 <= li <= ri < words.length
    /// </summary>
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2562. Find the Array Concatenation Value
    /// 
    /// Easy
    ///	
    /// You are given a 0-indexed integer array nums.
    ///
    /// The concatenation of two numbers is the number formed by concatenating 
    /// their numerals.
    ///
    /// For example, the concatenation of 15, 49 is 1549.
    /// The concatenation value of nums is initially equal to 0. Perform this 
    /// operation until nums becomes empty:
    ///
    /// If there exists more than one number in nums, pick the first element 
    /// and last element in nums respectively and add the value of their 
    /// concatenation to the concatenation value of nums, then delete the 
    /// first and last element from nums.
    /// If one element exists, add its value to the concatenation value of 
    /// nums, then delete it.
    /// Return the concatenation value of the nums.
    /// 
    /// Example 1:
    /// Input: nums = [7,52,2,4]
    /// Output: 596
    /// Explanation: Before performing any operation, nums is [7,52,2,4] and 
    /// concatenation value is 0.
    ///  - In the first operation:
    /// We pick the first element, 7, and the last element, 4.
    /// Their concatenation is 74, and we add it to the concatenation value, 
    /// so it becomes equal to 74.
    /// Then we delete them from nums, so nums becomes equal to [52,2].
    ///  - In the second operation:
    /// We pick the first element, 52, and the last element, 2.
    /// Their concatenation is 522, and we add it to the concatenation value, 
    /// so it becomes equal to 596.
    /// Then we delete them from the nums, so nums becomes empty.
    /// Since the concatenation value is 596 so the answer is 596.
    ///
    /// Example 2:
    /// Input: nums = [5,14,13,8,12]
    /// Output: 673
    /// Explanation: Before performing any operation, nums is [5,14,13,8,12] 
    /// and concatenation value is 0.
    /// - In the first operation:
    /// We pick the first element, 5, and the last element, 12.
    /// Their concatenation is 512, and we add it to the concatenation value, 
    /// so it becomes equal to 512.
    /// Then we delete them from the nums, so nums becomes equal to [14,13,8].
    /// - In the second operation:
    /// We pick the first element, 14, and the last element, 8.
    /// Their concatenation is 148, and we add it to the concatenation value, 
    /// so it becomes equal to 660.
    /// Then we delete them from the nums, so nums becomes equal to [13].
    ///  - In the third operation:
    /// nums has only one element, so we pick 13 and add it to the 
    /// concatenation value, so it becomes equal to 673.
    /// Then we delete it from nums, so nums become empty.
    /// Since the concatenation value is 673 so the answer is 673.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 10^4
    /// </summary>
    long long findTheArrayConcVal(vector<int>& nums);


    /// <summary>
    /// Leet Code 2570. Merge Two 2D Arrays by Summing Values
    /// 
    /// Easy
    ///	
    /// You are given two 2D integer arrays nums1 and nums2.
    ///
    /// nums1[i] = [idi, vali] indicate that the number with the id idi 
    /// has a value equal to vali.
    /// nums2[i] = [idi, vali] indicate that the number with the id idi 
    /// has a value equal to vali.
    /// Each array contains unique ids and is sorted in ascending order by id.
    ///
    /// Merge the two arrays into one array that is sorted in ascending order 
    /// by id, respecting the following conditions:
    ///
    /// Only ids that appear in at least one of the two arrays should be 
    /// included in the resulting array.
    /// Each id should be included only once and its value should be the sum 
    /// of the values of this id in the two arrays. If the id does not exist 
    /// in one of the two arrays then its value in that array is considered 
    /// to be 0.
    /// Return the resulting array. The returned array must be sorted in 
    /// ascending order by id.
    /// 
    /// Example 1:
    /// Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
    /// Output: [[1,6],[2,3],[3,2],[4,6]]
    /// Explanation: The resulting array contains the following:
    /// - id = 1, the value of this id is 2 + 4 = 6.
    /// - id = 2, the value of this id is 3.
    /// - id = 3, the value of this id is 2.
    /// - id = 4, the value of this id is 5 + 1 = 6.
    ///
    /// Example 2:
    /// Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
    /// Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
    /// Explanation: There are no common ids, so we just include each id with 
    /// its value in the resulting list.
    ///
    /// Constraints:
    /// 1. 1 <= nums1.length, nums2.length <= 200
    /// 2. nums1[i].length == nums2[j].length == 2
    /// 3. 1 <= idi, vali <= 1000
    /// 4. Both arrays contain unique ids.
    /// 5. Both arrays are in strictly ascending order by id.
    /// </summary>
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2);

    /// <summary>
    /// Leet Code 2573. Find the String with LCP
    /// 
    /// Hard
    ///	
    /// We define the lcp matrix of any 0-indexed string word of n lowercase 
    /// English letters as an n x n grid such that:
    ///
    /// lcp[i][j] is equal to the length of the longest common prefix between 
    /// the substrings word[i,n-1] and word[j,n-1].
    /// Given an n x n matrix lcp, return the alphabetically smallest string 
    /// word that corresponds to lcp. If there is no such string, return an 
    /// empty string.
    ///
    /// A string a is lexicographically smaller than a string b (of the same 
    /// length) if in the first position where a and b differ, string a has 
    /// a letter that appears earlier in the alphabet than the corresponding 
    /// letter in b. For example, "aabd" is lexicographically smaller than 
    /// "aaca" because the first position they differ is at the third 
    /// letter, and 'b' comes before 'c'.
    ///
    /// Example 1:
    /// Input: lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
    /// Output: "abab"
    /// Explanation: lcp corresponds to any 4 letter string with two 
    /// alternating letters. The lexicographically smallest of them is "abab".
    ///
    /// Example 2:
    /// Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
    /// Output: "aaaa"
    /// Explanation: lcp corresponds to any 4 letter string with a single 
    /// distinct letter. The lexicographically smallest of them is "aaaa". 
    ///
    /// Example 3:
    /// Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
    /// Output: ""
    /// Explanation: lcp[3][3] cannot be equal to 3 since word[3,...,3] 
    /// consists of only a single letter; Thus, no answer exists.
    ///
    /// Constraints:
    /// 1. 1 <= n == lcp.length == lcp[i].length <= 1000
    /// 2. 0 <= lcp[i][j] <= n
    /// </summary>
    string findTheString(vector<vector<int>>& lcp);

    /// <summary>
    /// Leet Code 2574. Left and Right Sum Differences
    /// 
    /// Easy
    ///	
    /// Given a 0-indexed integer array nums, find a 0-indexed integer 
    /// array answer where:
    ///
    /// answer.length == nums.length.
    /// answer[i] = |leftSum[i] - rightSum[i]|.
    /// Where:
    ///
    /// leftSum[i] is the sum of elements to the left of the index i in the 
    /// array nums. If there is no such element, leftSum[i] = 0.
    /// rightSum[i] is the sum of elements to the right of the index i in 
    /// the array nums. If there is no such element, rightSum[i] = 0.
    /// Return the array answer.
    /// 
    /// Example 1:
    /// Input: nums = [10,4,8,3]
    /// Output: [15,1,11,22]
    /// Explanation: The array leftSum is [0,10,14,22] and the array 
    /// rightSum is [15,11,3,0].
    /// The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] 
    /// = [15,1,11,22].
    ///
    /// Example 2:
    /// Input: nums = [1]
    /// Output: [0]
    /// Explanation: The array leftSum is [0] and the array rightSum is [0].
    /// The array answer is [|0 - 0|] = [0].
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    vector<int> leftRigthDifference(vector<int>& nums);

    /// <summary>
    /// Leet Code 2587. Rearrange Array to Maximize Prefix Score
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums. You can rearrange the 
    /// elements of nums to any order (including the given order).
    ///
    /// Let prefix be the array containing the prefix sums of nums after 
    /// rearranging it. In other words, prefix[i] is the sum of the elements 
    /// from 0 to i in nums after rearranging it. The score of nums is the 
    /// number of positive integers in the array prefix.
    ///
    /// Return the maximum score you can achieve.
    /// 
    /// Example 1:
    /// Input: nums = [2,-1,0,1,-3,3,-3]
    /// Output: 6
    /// Explanation: We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
    /// prefix = [2,5,6,5,2,2,-1], so the score is 6.
    /// It can be shown that 6 is the maximum score we can obtain.
    ///
    /// Example 2:
    /// Input: nums = [-2,-3,0]
    /// Output: 0
    /// Explanation: Any rearrangement of the array will result in a score of 0.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. -10^6 <= nums[i] <= 10^6
    /// </summary>
    int maxScore(vector<int>& nums);

    /// <summary>
    /// Leet Code 2588. Count the Number of Beautiful Subarrays
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums. In one operation, you 
    /// can:
    ///
    /// Choose two different indices i and j such that 0 <= i, j < nums.length.
    /// Choose a non-negative integer k such that the kth bit (0-indexed) in 
    /// the binary representation of nums[i] and nums[j] is 1.
    /// Subtract 2k from nums[i] and nums[j].
    /// A subarray is beautiful if it is possible to make all of its elements 
    /// equal to 0 after applying the above operation any number of times.
    ///
    /// Return the number of beautiful subarrays in the array nums.
    /// 
    /// A subarray is a contiguous non-empty sequence of elements within 
    /// an array.
    ///
    /// Example 1:
    /// Input: nums = [4,3,1,2,4]
    /// Output: 2
    /// Explanation: There are 2 beautiful subarrays in nums: [4,3,1,2,4] 
    /// and [4,3,1,2,4].
    /// - We can make all elements in the subarray [3,1,2] equal to 0 in the 
    ///   following way:
    /// - Choose [3, 1, 2] and k = 1. Subtract 21 from both numbers. The subarray 
    ///   becomes [1, 1, 0].
    /// - Choose [1, 1, 0] and k = 0. Subtract 20 from both numbers. The subarray 
    ///   becomes [0, 0, 0].
    /// - We can make all elements in the subarray [4,3,1,2,4] equal to 0 in the 
    ///   following way:
    /// - Choose [4, 3, 1, 2, 4] and k = 2. Subtract 22 from both numbers. The 
    ///   subarray becomes [0, 3, 1, 2, 0].
    /// - Choose [0, 3, 1, 2, 0] and k = 0. Subtract 20 from both numbers. The 
    ///   subarray becomes [0, 2, 0, 2, 0].
    /// - Choose [0, 2, 0, 2, 0] and k = 1. Subtract 21 from both numbers. The 
    ///   subarray becomes [0, 0, 0, 0, 0].
    ///
    /// Example 2:
    /// Input: nums = [1,10,4]
    /// Output: 0
    /// Explanation: There are no beautiful subarrays in nums.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^6
    /// </summary>
    long long beautifulSubarrays(vector<int>& nums);

    /// <summary>
    /// Leet Code 2592. Maximize Greatness of an Array
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums. You are allowed to 
    /// permute nums into a new array perm of your choosing.
    ///
    /// We define the greatness of nums be the number of indices 
    /// 0 <= i < nums.length for which perm[i] > nums[i].
    ///
    /// Return the maximum possible greatness you can achieve after permuting 
    /// nums.
    ///
    /// Example 1:
    /// Input: nums = [1,3,5,2,1,3,1]
    /// Output: 4
    /// Explanation: One of the optimal rearrangements is 
    /// perm = [2,5,1,3,3,1,1].
    /// At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4]
    /// Output: 3
    /// Explanation: We can prove the optimal perm is [2,3,4,1].
    /// At indices = 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// </summary>
    int maximizeGreatness(vector<int>& nums);

    /// <summary>
    /// Leet Code 2593. Find Score of an Array After Marking All Elements
    /// 
    /// Medium
    ///	
    /// You are given an array nums consisting of positive integers.
    ///
    /// Starting with score = 0, apply the following algorithm:
    ///
    /// Choose the smallest integer of the array that is not marked. If 
    /// there is a tie, choose the one with the smallest index.
    /// Add the value of the chosen integer to score.
    /// Mark the chosen element and its two adjacent elements if they exist.
    /// Repeat until all the array elements are marked.
    /// Return the score you get after applying the above algorithm.
    ///
    /// Example 1:
    /// Input: nums = [2,1,3,4,5,2]
    /// Output: 7
    /// Explanation: We mark the elements as follows:
    /// - 1 is the smallest unmarked element, so we mark it and its two 
    ///   adjacent elements: [2,1,3,4,5,2].
    /// - 2 is the smallest unmarked element, so we mark it and its left 
    ///   adjacent element: [2,1,3,4,5,2].
    /// - 4 is the only remaining unmarked element, so we mark 
    ///   it: [2,1,3,4,5,2].
    /// Our score is 1 + 2 + 4 = 7.
    ///
    /// Example 2:
    /// Input: nums = [2,3,5,1,3,2]
    /// Output: 5
    /// Explanation: We mark the elements as follows:
    /// - 1 is the smallest unmarked element, so we mark it and its two 
    ///   adjacent elements: [2,3,5,1,3,2].
    /// - 2 is the smallest unmarked element, since there are two of them, we 
    ///   choose the left-most one, so we mark the one at index 0 and its 
    ///   right adjacent element: [2,3,5,1,3,2].
    /// - 2 is the only remaining unmarked element, so we mark it: 
    ///  [2,3,5,1,3,2].
    /// Our score is 1 + 2 + 2 = 5.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    long long findScore(vector<int>& nums);

    /// <summary>
    /// Leet Code 2596. Check Knight Tour Configuration
    /// 
    /// Medium
    ///	
    /// There is a knight on an n x n chessboard. In a valid configuration, 
    /// the knight starts at the top-left cell of the board and visits every 
    /// cell on the board exactly once.
    ///
    /// You are given an n x n integer matrix grid consisting of distinct 
    /// integers from the range [0, n * n - 1] where grid[row][col] indicates 
    /// that the cell (row, col) is the grid[row][col]th cell that the knight 
    /// visited. The moves are 0-indexed.
    ///
    /// Return true if grid represents a valid configuration of the knight's 
    /// movements or false otherwise.
    ///
    /// Note that a valid knight move consists of moving two squares 
    /// vertically and one square horizontally, or two squares horizontally 
    /// and one square vertically. The figure below illustrates all the 
    /// possible eight moves of a knight from some cell.
    /// 
    /// Example 1:
    /// Input: grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],
    /// [3,18,23,14,9],[24,13,2,7,22]]
    /// Output: true
    /// Explanation: The above diagram represents the grid. It can be 
    /// shown that it is a valid configuration.
    ///
    /// Example 2:
    /// Input: grid = [[0,3,6],[5,8,1],[2,7,4]]
    /// Output: false
    /// Explanation: The above diagram represents the grid. The 8th move of 
    /// the knight is not valid considering its position after the 7th move.
    ///
    /// Constraints:
    /// 1. n == grid.length == grid[i].length
    /// 2. 3 <= n <= 7
    /// 3. 0 <= grid[row][col] < n * n
    /// 4. All integers in grid are unique.
    /// </summary>
    bool checkValidGrid(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2602. Minimum Operations to Make All Array Elements Equal
    /// 
    /// Medium
    ///	
    /// You are given an array nums consisting of positive integers.
    ///
    /// You are also given an integer array queries of size m. For the ith 
    /// query, you want to make all of the elements of nums equal to 
    /// queries[i]. You can perform the following operation on the array 
    /// any number of times:
    ///
    /// Increase or decrease an element of the array by 1.
    /// Return an array answer of size m where answer[i] is the minimum 
    /// number of operations to make all elements of nums equal to queries[i].
    ///
    /// Note that after each query the array is reset to its original state.
    /// 
    /// Example 1:
    /// Input: nums = [3,1,6,8], queries = [1,5]
    /// Output: [14,10]
    /// Explanation: For the first query we can do the following operations:
    /// - Decrease nums[0] 2 times, so that nums = [1,1,6,8].
    /// - Decrease nums[2] 5 times, so that nums = [1,1,1,8].
    /// - Decrease nums[3] 7 times, so that nums = [1,1,1,1].
    /// So the total number of operations for the first query is 
    /// 2 + 5 + 7 = 14.
    /// For the second query we can do the following operations:
    /// - Increase nums[0] 2 times, so that nums = [5,1,6,8].
    /// - Increase nums[1] 4 times, so that nums = [5,5,6,8].
    /// - Decrease nums[2] 1 time, so that nums = [5,5,5,8].
    /// - Decrease nums[3] 3 times, so that nums = [5,5,5,5].
    /// So the total number of operations for the second query is 
    /// 2 + 4 + 1 + 3 = 10.
    ///
    /// Example 2:
    /// Input: nums = [2,9,6,3], queries = [10]
    /// Output: [20]
    /// Explanation: We can increase each value in the array to 10. The total 
    /// number of operations will be 8 + 1 + 4 + 7 = 20.
    ///
    /// Constraints:
    /// 1. n == nums.length
    /// 2. m == queries.length
    /// 3. 1 <= n, m <= 10^5
    /// 4. 1 <= nums[i], queries[i] <= 10^9
    /// </summary>
    vector<long long> minOperationsII(vector<int>& nums, vector<int>& queries);

    /// <summary>
    /// Leet Code 2607. Make K-Subarray Sums Equal
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array arr and an integer k. The 
    /// array arr is circular. In other words, the first element of the 
    /// array is the next element of the last element, and the last element 
    /// of the array is the previous element of the first element.
    ///
    /// You can do the following operation any number of times:
    ///
    /// Pick any element from arr and increase or decrease it by 1.
    /// Return the minimum number of operations such that the sum of each 
    /// subarray of length k is equal.
    ///
    /// A subarray is a contiguous part of the array.
    ///
    ///
    /// Example 1:
    /// Input: arr = [1,4,1,3], k = 2
    /// Output: 1
    /// Explanation: we can do one operation on index 1 to make its value 
    /// equal to 3.
    /// The array after the operation is [1,3,1,3]
    /// - Subarray starts at index 0 is [1, 3], and its sum is 4 
    /// - Subarray starts at index 1 is [3, 1], and its sum is 4 
    /// - Subarray starts at index 2 is [1, 3], and its sum is 4 
    /// - Subarray starts at index 3 is [3, 1], and its sum is 4 
    ///
    /// Example 2:
    /// Input: arr = [2,5,5,7], k = 3
    /// Output: 5
    /// Explanation: we can do three operations on index 0 to make its value 
    /// equal to 5 and two operations on index 3 to make its value equal to 5.
    /// The array after the operations is [5,5,5,5]
    /// - Subarray starts at index 0 is [5, 5, 5], and its sum is 15
    /// - Subarray starts at index 1 is [5, 5, 5], and its sum is 15
    /// - Subarray starts at index 2 is [5, 5, 5], and its sum is 15
    /// - Subarray starts at index 3 is [5, 5, 5], and its sum is 15 
    ///
    /// Constraints:
    /// 1. 1 <= k <= arr.length <= 10^5
    /// 2. 1 <= arr[i] <= 10^9
    /// </summary>
    long long makeSubKSumEqual(vector<int>& arr, int k);

    /// <summary>
    /// Leet Code 2609. Find the Longest Balanced Substring of a Binary String
    /// 
    /// Easy
    ///	
    /// You are given a binary string s consisting only of zeroes and ones.
    /// A substring of s is considered balanced if all zeroes are before ones 
    /// and the number of zeroes is equal to the number of ones inside the 
    /// substring. Notice that the empty substring is considered a balanced 
    /// substring.
    ///
    /// Return the length of the longest balanced substring of s.
    /// A substring is a contiguous sequence of characters within a string.
    /// 
    /// Example 1:
    ///
    /// Input: s = "01000111"
    /// Output: 6
    /// Explanation: The longest balanced substring is "000111", which has 
    /// length 6.
    ///
    /// Example 2:
    /// Input: s = "00111"
    /// Output: 4
    /// Explanation: The longest balanced substring is "0011", which has 
    /// length 4. 
    ///
    /// Example 3:
    /// Input: s = "111"
    /// Output: 0
    /// Explanation: There is no balanced substring except the empty 
    /// substring, so the answer is 0.
    /// Constraints:
    /// 1. 1 <= s.length <= 50
    /// 2. '0' <= s[i] <= '1'
    /// </summary>
    int findTheLongestBalancedSubstring(string s);

    /// <summary>
    /// Leet Code 2610. Convert an Array Into a 2D Array With Conditions
    /// 
    /// Medium
    ///	
    /// You are given an integer array nums. You need to create a 2D array 
    /// from nums satisfying the following conditions:
    /// 
    /// The 2D array should contain only the elements of the array nums.
    /// Each row in the 2D array contains distinct integers.
    /// The number of rows in the 2D array should be minimal.
    /// Return the resulting array. If there are multiple answers, return 
    /// any of them.
    ///
    /// Note that the 2D array can have a different number of elements on each 
    /// row.
    ///
    /// Example 1:
    /// Input: nums = [1,3,4,1,2,3,1]
    /// Output: [[1,3,4,2],[1,3],[1]]
    /// Explanation: We can create a 2D array that contains the following rows:
    /// - 1,3,4,2
    /// - 1,3
    /// - 1
    /// All elements of nums were used, and each row of the 2D array contains 
    /// distinct integers, so it is a valid answer.
    /// It can be shown that we cannot have less than 3 rows in a valid array.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4]
    /// Output: [[4,3,2,1]]
    /// Explanation: All elements of the array are distinct, so we can keep 
    /// all of them in the first row of the 2D array.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 200
    /// 2. 1 <= nums[i] <= nums.length
    /// </summary>
    vector<vector<int>> findMatrix(vector<int>& nums);

    /// <summary>
    /// Leet Code 2612. Minimum Reverse Operations
    /// </summary>
    pair<int, int> getRange(int x, int n, int k);

    /// <summary>
    /// Leet Code 2612. Minimum Reverse Operations
    /// 
    /// Hard
    ///	
    /// You are given an integer n and an integer p in the range [0, n - 1]. 
    /// Representing a 0-indexed array arr of length n where all positions 
    /// are set to 0's, except position p which is set to 1.
    /// 
    /// You are also given an integer array banned containing some positions 
    /// from the array. For the ith position in banned, arr[banned[i]] = 0, 
    /// and banned[i] != p.
    ///
    /// You can perform multiple operations on arr. In an operation, you can 
    /// choose a subarray with size k and reverse the subarray. However, 
    /// the 1 in arr should never go to any of the positions in banned. In 
    /// other words, after each operation arr[banned[i]] remains 0.
    ///
    /// Return an array ans where for each i from [0, n - 1], ans[i] is the 
    /// minimum number of reverse operations needed to bring the 1 to 
    /// position i in arr, or -1 if it is impossible.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    /// The values of ans[i] are independent for all i's.
    /// The reverse of an array is an array containing the values in reverse 
    /// order.
    ///
    /// Example 1:
    /// Input: n = 4, p = 0, banned = [1,2], k = 4
    /// Output: [0,-1,-1,1]
    /// Explanation: In this case k = 4 so there is only one possible reverse 
    /// operation we can perform, which is reversing the whole array. 
    /// Initially, 1 is placed at position 0 so the amount of operations we 
    /// need for position 0 is 0. We can never place a 1 on the banned 
    /// positions, so the answer for positions 1 and 2 is -1. Finally, with 
    /// one reverse operation we can bring the 1 to index 3, so the answer 
    /// for position 3 is 1. 
    ///
    /// Example 2:
    /// Input: n = 5, p = 0, banned = [2,4], k = 3
    /// Output: [0,-1,-1,-1,-1]
    /// Explanation: In this case the 1 is initially at position 0, so the 
    /// answer for that position is 0. We can perform reverse operations of 
    /// size 3. The 1 is currently located at position 0, so we need to 
    /// reverse the subarray [0, 2] for it to leave that position, but 
    /// reversing that subarray makes position 2 have a 1, which shouldn't 
    /// happen. So, we can't move the 1 from position 0, making the result 
    /// for all the other positions -1. 
    ///
    /// Example 3:
    ///
    /// Input: n = 4, p = 2, banned = [0,1,3], k = 1
    /// Output: [-1,-1,0,-1]
    /// Explanation: In this case we can only perform reverse operations 
    /// of size 1. So the 1 never changes its position.
    ///
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. 0 <= p <= n - 1
    /// 3. 0 <= banned.length <= n - 1
    /// 4. 0 <= banned[i] <= n - 1
    /// 5. 1 <= k <= n 
    /// 6. banned[i] != p
    /// 7. all values in banned are unique 
    /// </summary>
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k);

    /// <summary>
    /// Leet Code 2615. Sum of Distances
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums. There exists an array 
    /// arr of length nums.length, where arr[i] is the sum of |i - j| over 
    /// all j such that nums[j] == nums[i] and j != i. If there is no such j, 
    /// set arr[i] to be 0.
    ///
    /// Return the array arr.
    /// Example 1:
    /// Input: nums = [1,3,1,1,2]
    /// Output: [5,0,3,4,0]
    /// Explanation: 
    /// When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, 
    /// arr[0] = |0 - 2| + |0 - 3| = 5. 
    /// When i = 1, arr[1] = 0 because there is no other index with value 3.
    /// When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, 
    /// arr[2] = |2 - 0| + |2 - 3| = 3. 
    /// When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, 
    /// arr[3] = |3 - 0| + |3 - 2| = 4. 
    /// When i = 4, arr[4] = 0 because there is no other index with value 2. 
    ///
    /// Example 2:
    ///
    /// Input: nums = [0,5,3]
    /// Output: [0,0,0]
    /// Explanation: Since each element in nums is distinct, arr[i] = 0 for 
    /// all i.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// </summary>
    vector<long long> distance(vector<int>& nums);

    /// <summary>
    /// Leet Code 2643. Row With Maximum Ones
    /// 
    /// Easy
    ///	
    /// Given a m x n binary matrix mat, find the 0-indexed position of the 
    /// row that contains the maximum count of ones, and the number of ones 
    /// in that row.
    ///
    /// In case there are multiple rows that have the maximum count of ones, 
    /// the row with the smallest row number should be selected.
    ///
    /// Return an array containing the index of the row, and the number of 
    /// ones in it.
    ///
    /// Example 1:
    /// Input: mat = [[0,1],[1,0]]
    /// Output: [0,1]
    /// Explanation: Both rows have the same number of 1's. So we return the 
    /// index of the smaller row, 0, and the maximum count of ones (1). So, 
    /// the answer is [0,1]. 
    ///
    /// Example 2:
    /// Input: mat = [[0,0,0],[0,1,1]]
    /// Output: [1,2]
    /// Explanation: The row indexed 1 has the maximum count of ones (2). So 
    /// we return its index, 1, and the count. So, the answer is [1,2].
    ///
    /// Example 3:
    /// Input: mat = [[0,0],[1,1],[0,0]]
    /// Output: [1,2]
    /// Explanation: The row indexed 1 has the maximum count of ones (2). So 
    /// the answer is [1,2].
    ///
    /// Constraints:
    /// 1. m == mat.length 
    /// 2. n == mat[i].length 
    /// 3. 1 <= m, n <= 100 
    /// 4. mat[i][j] is either 0 or 1.
    /// </summary>
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat);

    /// <summary>
    /// Leet Code 2639. Find the Width of Columns of a Grid
    /// 
    /// Easy
    ///	
    /// You are given a 0-indexed m x n integer matrix grid. The width of a 
    /// column is the maximum length of its integers.
    ///
    /// For example, if grid = [[-10], [3], [12]], the width of the only 
    /// column is 3 since -10 is of length 3.
    /// Return an integer array ans of size n where ans[i] is the width of 
    /// the ith column.
    ///
    /// The length of an integer x with len digits is equal to len if x is 
    /// non-negative, and len + 1 otherwise.
    /// 
    /// Example 1:
    /// Input: grid = [[1],[22],[333]]
    /// Output: [3]
    /// Explanation: In the 0th column, 333 is of length 3.
    ///
    /// Example 2:
    /// Input: grid = [[-15,1,3],[15,7,12],[5,6,-2]]
    /// Output: [3,1,2]
    /// Explanation: 
    /// In the 0th column, only -15 is of length 3.
    /// In the 1st column, all integers are of length 1. 
    /// In the 2nd column, both 12 and -2 are of length 2.
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 100 
    /// 4. -10^9 <= grid[r][c] <= 10^9
    /// </summary>
    vector<int> findColumnWidth(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2640. Find the Score of All Prefixes of an Array
    /// 
    /// Medium
    ///	
    /// We define the conversion array conver of an array arr as follows:
    ///
    /// conver[i] = arr[i] + max(arr[0..i]) where max(arr[0..i]) is the 
    /// maximum value of arr[j] over 0 <= j <= i.
    /// We also define the score of an array arr as the sum of the values 
    /// of the conversion array of arr.
    ///
    /// Given a 0-indexed integer array nums of length n, return an array 
    /// ans of length n where ans[i] is the score of the prefix nums[0..i].
    ///
    /// Example 1:
    /// Input: nums = [2,3,7,5,10]
    /// Output: [4,10,24,36,56]
    /// Explanation: 
    /// For the prefix [2], the conversion array is [4] hence the score is 4
    /// For the prefix [2, 3], the conversion array is [4, 6] hence the 
    /// score is 10
    /// For the prefix [2, 3, 7], the conversion array is [4, 6, 14] hence 
    /// the score is 24
    /// For the prefix [2, 3, 7, 5], the conversion array is [4, 6, 14, 12] 
    /// hence the score is 36
    /// For the prefix [2, 3, 7, 5, 10], the conversion array is [4, 6, 14, 
    /// 12, 20] hence the score is 56
    ///
    /// Example 2:
    /// Input: nums = [1,1,2,4,8,16]
    /// Output: [2,4,8,16,32,64]
    /// Explanation: 
    /// For the prefix [1], the conversion array is [2] hence the score is 2
    /// For the prefix [1, 1], the conversion array is [2, 2] hence the 
    /// score is 4
    /// For the prefix [1, 1, 2], the conversion array is [2, 2, 4] hence 
    /// the score is 8
    /// For the prefix [1, 1, 2, 4], the conversion array is [2, 2, 4, 8] 
    /// hence the score is 16
    /// For the prefix [1, 1, 2, 4, 8], the conversion array is [2, 2, 4, 8, 16] 
    /// hence the score is 32
    /// For the prefix [1, 1, 2, 4, 8, 16], the conversion array is [2, 2, 4, 8, 
    /// 16, 32] hence the score is 64
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    vector<long long> findPrefixScore(vector<int>& nums);

    /// <summary>
    /// Leet Code 2660. Determine the Winner of a Bowling Game
    /// 
    /// Easy
    ///	
    /// You are given two 0-indexed integer arrays player1 and player2, that 
    /// represent the number of pins that player 1 and player 2 hit in a 
    /// bowling game, respectively.
    ///
    /// The bowling game consists of n turns, and the number of pins in each 
    /// turn is exactly 10.
    ///
    /// Assume a player hit xi pins in the ith turn. The value of the ith 
    /// turn for the player is:
    ///
    /// 2xi if the player hit 10 pins in any of the previous two turns.
    /// Otherwise, It is xi.
    /// The score of the player is the sum of the values of their n turns.
    ///
    /// Return
    /// 
    /// 1 if the score of player 1 is more than the score of player 2,
    /// 2 if the score of player 2 is more than the score of player 1, and
    /// 0 in case of a draw.
    /// 
    /// Example 1:
    /// Input: player1 = [4,10,7,9], player2 = [6,5,2,3]
    /// Output: 1
    /// Explanation: The score of player1 is 4 + 10 + 2*7 + 2*9 = 46.
    /// The score of player2 is 6 + 5 + 2 + 3 = 16.
    /// Score of player1 is more than the score of player2, so, player1 is 
    /// the winner, and the answer is 1.
    ///
    /// Example 2:
    /// Input: player1 = [3,5,7,6], player2 = [8,10,10,2]
    /// Output: 2
    /// Explanation: The score of player1 is 3 + 5 + 7 + 6 = 21.
    /// The score of player2 is 8 + 10 + 2*10 + 2*2 = 42.
    /// Score of player2 is more than the score of player1, so, player2 is 
    /// the winner, and the answer is 2.
    ///
    /// Example 3:
    /// Input: player1 = [2,3], player2 = [4,1]
    /// Output: 0
    /// Explanation: The score of player1 is 2 + 3 = 5
    /// The score of player2 is 4 + 1 = 5
    /// The score of player1 equals to the score of player2, so, there is 
    /// a draw, and the answer is 0.
    /// 
    /// Constraints:
    /// 1. n == player1.length == player2.length
    /// 2. 1 <= n <= 1000
    /// 3. 0 <= player1[i], player2[i] <= 10
    /// </summary>
    int isWinner(vector<int>& player1, vector<int>& player2);

    /// <summary>
    /// Leet Code 2661. First Completely Painted Row or Column
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array arr, and an m x n integer 
    /// matrix mat. arr and mat both contain all the integers in the range 
    /// [1, m * n].
    ///
    /// Go through each index i in arr starting from index 0 and paint the 
    /// cell in mat containing the integer arr[i].
    ///
    /// Return the smallest index i at which either a row or a column will 
    /// be completely painted in mat.
    /// 
    /// Example 1:
    /// image explanation for example 1
    /// Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
    /// Output: 2
    /// Explanation: The moves are shown in order, and both the first row 
    /// and second column of the matrix become fully painted at arr[2].
    ///
    /// Example 2:
    /// image explanation for example 2
    /// Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
    /// Output: 3
    /// Explanation: The second column becomes fully painted at arr[3].
    ///
    /// Constraints:
    /// 1. m == mat.length
    /// 2. n = mat[i].length
    /// 3. arr.length == m * n
    /// 4. 1 <= m, n <= 10^5
    /// 5. 1 <= m * n <= 10^5
    /// 6. 1 <= arr[i], mat[r][c] <= m * n
    /// 7. All the integers of arr are unique.
    /// 8. All the integers of mat are unique.
    /// </summary>
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat);

    /// <summary>
    /// Leet Code 2684. Maximum Number of Moves in a Grid
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed m x n matrix grid consisting of positive 
    /// integers.
    ///
    /// You can start at any cell in the first column of the matrix, and 
    /// traverse the grid in the following way:
    ///
    /// From a cell (row, col), you can move to any of the cells: 
    /// (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that 
    /// the value of the cell you move to, should be strictly bigger than 
    /// the value of the current cell.
    /// Return the maximum number of moves that you can perform.
    ///
    /// Example 1:
    /// Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
    /// Output: 3
    /// Explanation: We can start at the cell (0, 0) and make the following 
    /// moves:
    /// - (0, 0) -> (0, 1).
    /// - (0, 1) -> (1, 2).
    /// - (1, 2) -> (2, 3).
    /// It can be shown that it is the maximum number of moves that can be 
    /// made.
    ///
    /// Example 2:
    /// Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
    /// Output: 0
    /// Explanation: Starting from any cell in the first column we cannot 
    /// perform any moves.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 2 <= m, n <= 1000
    /// 4. 4 <= m * n <= 10^5
    /// 5. 1 <= grid[i][j] <= 10^6
    /// </summary>
    int maxMoves(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2681. Power of Heroes
    /// 
    /// Hard
    ///	
    /// You are given a 0-indexed integer array nums representing the strength 
    /// of some heroes. The power of a group of heroes is defined as follows:
    ///
    /// Let i0, i1, ... ,ik be the indices of the heroes in a group. Then, 
    /// the power of this group is max(nums[i0], nums[i1], ... ,nums[ik])^2 * 
    /// min(nums[i0], nums[i1], ... ,nums[ik]).
    /// Return the sum of the power of all non-empty groups of heroes 
    /// possible. Since the sum could be very large, return it modulo 10^9 + 7.
    /// Example 1:
    /// Input: nums = [2,1,4]
    /// Output: 141
    /// Explanation: 
    /// 1st group: [2] has power = 2^2 * 2 = 8.
    /// 2nd group: [1] has power = 1^2 * 1 = 1. 
    /// 3rd group: [4] has power = 4^2 * 4 = 64. 
    /// 4th group: [2,1] has power = 2^2 * 1 = 4. 
    /// 5th group: [2,4] has power = 4^2 * 2 = 32. 
    /// 6th group: [1,4] has power = 4^2 * 1 = 16. 
    /// 7th group: [2,1,4] has power = 4^2 * 1 = 16. 
    /// The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.
    ///
    /// Example 2:
    /// Input: nums = [1,1,1]
    /// Output: 7
    /// Explanation: A total of 7 groups are possible, and the power of each 
    /// group will be 1. Therefore, the sum of the powers of all groups is 7.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    int sumOfPower(vector<int>& nums);

    /// <summary>
    /// Leet Code 2711. Difference of Number of Distinct Values on Diagonals
    /// 
    /// Easy
    ///	
    /// Given a 0-indexed 2D grid of size m x n, you should find the matrix 
    /// answer of size m x n.
    ///
    /// The value of each cell (r, c) of the matrix answer is calculated in 
    /// the following way:
    ///
    /// Let topLeft[r][c] be the number of distinct values in the top-left 
    /// diagonal of the cell (r, c) in the matrix grid.
    /// Let bottomRight[r][c] be the number of distinct values in the 
    /// bottom-right diagonal of the cell (r, c) in the matrix grid. 
    /// Then answer[r][c] = |topLeft[r][c] - bottomRight[r][c]|. 
    ///
    /// Return the matrix answer.
    ///
    /// A matrix diagonal is a diagonal line of cells starting from some 
    /// cell in either the topmost row or leftmost column and going in 
    /// the bottom-right direction until reaching the matrix's end.
    ///
    /// A cell (r1, c1) belongs to the top-left diagonal of the cell (r, c), 
    /// if both belong to the same diagonal and r1 < r. Similarly is defined 
    /// bottom-right diagonal.
    ///
    /// Example 1:
    /// Input: grid = [[1,2,3],[3,1,5],[3,2,1]]
    /// Output: [[1,1,0],[1,0,1],[0,1,1]]
    /// Explanation: The 1st diagram denotes the initial grid. 
    /// The 2nd diagram denotes a grid for cell (0,0), where blue-colored 
    /// cells are cells on its bottom-right diagonal.
    /// The 3rd diagram denotes a grid for cell (1,2), where red-colored 
    /// cells are cells on its top-left diagonal.
    /// The 4th diagram denotes a grid for cell (1,1), where blue-colored 
    /// cells are cells on its bottom-right diagonal and red-colored cells 
    /// are cells on its top-left diagonal.
    /// - The cell (0,0) contains [1,1] on its bottom-right diagonal and [] 
    /// on its top-left diagonal. The answer is |1 - 0| = 1.
    /// - The cell (1,2) contains [] on its bottom-right diagonal and [2] 
    /// on its top-left diagonal. The answer is |0 - 1| = 1.
    /// - The cell (1,1) contains [1] on its bottom-right diagonal and [1] 
    /// on its top-left diagonal. The answer is |1 - 1| = 0.
    /// The answers of other cells are similarly calculated.
    ///
    /// Example 2:
    ///
    /// Input: grid = [[1]]
    /// Output: [[0]]
    /// Explanation: - The cell (0,0) contains [] on its bottom-right diagonal 
    /// and [] on its top-left diagonal. The answer is |0 - 0| = 0.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n, grid[i][j] <= 50
    /// </summary>
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2717. Semi-Ordered Permutation
    /// 
    /// Easy
    ///
    /// You are given a 0-indexed permutation of n integers nums.
    ///
    /// A permutation is called semi-ordered if the first number 
    /// equals 1 and the last number equals n. You can perform the 
    /// below operation as many times as you want until you make 
    /// nums a semi-ordered permutation:
    ///
    /// Pick two adjacent elements in nums, then swap them.
    /// Return the minimum number of operations to make nums a 
    /// semi-ordered permutation.
    ///
    /// A permutation is a sequence of integers from 1 to n of 
    /// length n containing each number exactly once.  
    ///
    /// Example 1:
    ///
    /// Input: nums = [2,1,4,3]
    /// Output: 2
    /// Explanation: We can make the permutation semi-ordered using these 
    /// sequence of operations: 
    /// 1 - swap i = 0 and j = 1. The permutation becomes [1,2,4,3].
    /// 2 - swap i = 2 and j = 3. The permutation becomes [1,2,3,4].
    /// It can be proved that there is no sequence of less than two 
    /// operations that make nums a semi-ordered permutation. 
    ///
    /// Example 2:
    /// Input: nums = [2,4,1,3]
    /// Output: 3
    /// Explanation: We can make the permutation semi-ordered using these 
    /// sequence of operations:
    /// 1 - swap i = 1 and j = 2. The permutation becomes [2,1,4,3].
    /// 2 - swap i = 0 and j = 1. The permutation becomes [1,2,4,3].
    /// 3 - swap i = 2 and j = 3. The permutation becomes [1,2,3,4].
    /// It can be proved that there is no sequence of less than three 
    /// operations that make nums a semi-ordered permutation.
    ///
    /// Example 3:
    /// Input: nums = [1,3,4,2,5]
    /// Output: 0
    /// Explanation: The permutation is already a semi-ordered permutation.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length == n <= 50
    /// 2. 1 <= nums[i] <= 50
    /// 3. nums is a permutation.
    /// </summary>
    int semiOrderedPermutation(vector<int>& nums);

    /// <summary>
    /// Leet Code 2718. Sum of Matrix After Queries
    /// 
    /// Medium
    ///
    /// You are given an integer n and a 0-indexed 2D array queries where 
    /// queries[i] = [typei, indexi, vali].
    ///
    /// Initially, there is a 0-indexed n x n matrix filled with 0's. For 
    /// each query, you must apply one of the following changes:
    ///
    /// if typei == 0, set the values in the row with indexi to vali, 
    /// overwriting any previous values.
    /// if typei == 1, set the values in the column with indexi to vali, 
    /// overwriting any previous values.
    /// Return the sum of integers in the matrix after all queries are applied.
    ///
    /// Example 1:
    /// Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
    /// Output: 23
    /// Explanation: The image above describes the matrix after each query. 
    /// The sum of the matrix after all queries are applied is 23. 
    ///
    /// Example 2:
    /// Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
    /// Output: 17
    /// Explanation: The image above describes the matrix after each query. 
    /// The sum of the matrix after all queries are applied is 17.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// 2. 1 <= queries.length <= 5 * 10^4
    /// 3. queries[i].length == 3
    /// 4. 0 <= typei <= 1
    /// 5. 0 <= indexi < n
    /// 6. 0 <= vali <= 10^5
    /// </summary>
    long long matrixSumQueries(int n, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2733. Neither Minimum nor Maximum
    /// 
    /// Easy
    ///
    /// Given an integer array nums containing distinct positive integers, 
    /// find and return any number from the array that is neither the 
    /// minimum nor the maximum value in the array, or -1 if there is no 
    /// such number.
    ///
    /// Return the selected integer.
    /// 
    /// Example 1:
    /// Input: nums = [3,2,1,4]
    /// Output: 2
    /// Explanation: In this example, the minimum value is 1 and the maximum 
    /// value is 4. Therefore, either 2 or 3 can be valid answers.
    ///
    /// Example 2:
    /// Input: nums = [1,2]
    /// Output: -1
    /// Explanation: Since there is no number in nums that is neither the 
    /// maximum nor the minimum, we cannot select a number that satisfies 
    /// the given condition. Therefore, there is no answer.
    ///
    /// Example 3:
    /// Input: nums = [2,1,3]
    /// Output: 2
    /// Explanation: Since 2 is neither the maximum nor the minimum value in 
    /// nums, it is the only valid answer. 
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// 3. All values in nums are distinct
    /// </summary>
    int findNonMinOrMax(vector<int>& nums);

    /// <summary>
    /// Leet Code 2728. Count Houses in a Circular Street
    /// 
    /// Easy
    ///
    /// You are given an object street of class Street that represents a 
    /// circular street and a positive integer k which represents a 
    /// maximum bound for the number of houses in that street (in other 
    /// words, the number of houses is less than or equal to k). Houses' 
    /// doors could be open or closed initially.
    ///
    /// Initially, you are standing in front of a door to a house on this 
    /// street. Your task is to count the number of houses in the street.
    ///
    /// The class Street contains the following functions which may help you:
    ///
    /// void openDoor(): Open the door of the house you are in front of.
    /// void closeDoor(): Close the door of the house you are in front of.
    /// boolean isDoorOpen(): Returns true if the door of the current house 
    /// is open and false otherwise.
    /// void moveRight(): Move to the right house.
    /// void moveLeft(): Move to the left house.
    /// Return ans which represents the number of houses on this street.
    ///  
    /// Example 1:
    /// Input: street = [0,0,0,0], k = 10
    /// Output: 4
    /// Explanation: There are 4 houses, and all their doors are closed. 
    /// The number of houses is less than k, which is 10.
    ///
    /// Example 2:
    /// Input: street = [1,0,1,1,0], k = 5
    /// Output: 5
    /// Explanation: There are 5 houses, and the doors of the 1st, 3rd, 
    /// and 4th house (moving in the right direction) are open, and the 
    /// rest are closed.
    /// The number of houses is equal to k, which is 5.
    ///
    /// Constraints:
    /// 1. n == number of houses
    /// 2. 1 <= n <= k <= 10^3
    /// </summary>
    int houseCount(Street* street, int k);

    /// <summary>
    /// Leet Code 2731. Movement of Robots
    /// 
    /// Medium
    ///
    /// Some robots are standing on an infinite number line with their initial 
    /// coordinates given by a 0-indexed integer array nums and will start 
    /// moving once given the command to move. The robots will move a unit 
    /// distance each second.
    ///
    /// You are given a string s denoting the direction in which robots will 
    /// move on command. 'L' means the robot will move towards the left side 
    /// or negative side of the number line, whereas 'R' means the robot 
    /// will move towards the right side or positive side of the number line.
    ///
    /// If two robots collide, they will start moving in opposite directions.
    ///
    /// Return the sum of distances between all the pairs of robots d seconds 
    /// after the command. Since the sum can be very large, return it 
    /// modulo 10^9 + 7.
    ///
    /// Note:
    /// For two robots at the index i and j, pair (i,j) and pair (j,i) are 
    /// considered the same pair.
    /// When robots collide, they instantly change their directions without 
    /// wasting any time.
    /// Collision happens when two robots share the same place in a moment.
    /// For example, if a robot is positioned in 0 going to the right and 
    /// another is positioned in 2 going to the left, the next second they'll 
    /// be both in 1 and they will change direction and the next second the 
    /// first one will be in 0, heading left, and another will be in 2, 
    /// heading right.
    /// For example, if a robot is positioned in 0 going to the right and 
    /// another is positioned in 1 going to the left, the next second the 
    /// first one will be in 0, heading left, and another will be in 1, 
    /// heading right.
    ///
    /// Example 1:
    /// Input: nums = [-2,0,2], s = "RLL", d = 3
    /// Output: 8
    /// Explanation: 
    /// After 1 second, the positions are [-1,-1,1]. Now, the robot at 
    /// index 0 will move left, and the robot at index 1 will move right.
    /// After 2 seconds, the positions are [-2,0,0]. Now, the robot at index 1 
    /// will move left, and the robot at index 2 will move right.
    /// After 3 seconds, the positions are [-3,-1,1].
    /// The distance between the robot at index 0 and 1 is abs(-3 - (-1)) = 2.
    /// The distance between the robot at index 0 and 2 is abs(-3 - 1) = 4.
    /// The distance between the robot at index 1 and 2 is abs(-1 - 1) = 2.
    /// The sum of the pairs of all distances = 2 + 4 + 2 = 8.
    ///
    /// Example 2:
    /// Input: nums = [1,0], s = "RL", d = 2
    /// Output: 5
    /// Explanation: 
    /// After 1 second, the positions are [2,-1].
    /// After 2 seconds, the positions are [3,-2].
    /// The distance between the two robots is abs(-2 - 3) = 5.
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. -2 * 10^9 <= nums[i] <= 2 * 10^9
    /// 3. 0 <= d <= 10^9
    /// 4. nums.length == s.length 
    /// 5. s consists of 'L' and 'R' only
    /// 6. nums[i] will be unique.
    /// </summary>
    int sumDistance(vector<int>& nums, string s, int d);

    /// <summary>
    /// Leet Code 	2735. Collecting Chocolates
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums of size n representing 
    /// the cost of collecting different chocolates. The cost of collecting 
    /// the chocolate at the index i is nums[i]. Each chocolate is of a 
    /// different type, and initially, the chocolate at the index i is of 
    /// ith type.
    ///
    /// In one operation, you can do the following with an incurred cost of x:
    /// 
    /// Simultaneously change the chocolate of ith type to ((i + 1) mod n)th 
    /// type for all chocolates.
    /// Return the minimum cost to collect chocolates of all types, given that 
    /// you can perform as many operations as you would like.
    ///
    /// Example 1:
    /// Input: nums = [20,1,15], x = 5
    /// Output: 13
    /// Explanation: Initially, the chocolate types are [0,1,2]. We will buy 
    /// the 1st type of chocolate at a cost of 1.
    /// Now, we will perform the operation at a cost of 5, and the types of 
    /// chocolates will become [1,2,0]. We will buy the 2nd type of chocolate 
    /// at a cost of 1.
    /// Now, we will again perform the operation at a cost of 5, and the 
    /// chocolate types will become [2,0,1]. We will buy the 0th type of 
    /// chocolate at a cost of 1. 
    /// Thus, the total cost will become (1 + 5 + 1 + 5 + 1) = 13. We can 
    /// prove that this is optimal.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3], x = 4
    /// Output: 6
    /// Explanation: We will collect all three types of chocolates at their 
    /// own price without performing any operations. Therefore, the total 
    /// cost is 1 + 2 + 3 = 6.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= x <= 10^9
    /// </summary>
    long long minCost(vector<int>& nums, int x);

    /// <summary>
    /// Leet Code 2750. Ways to Split Array Into Good Subarrays
    /// 
    /// Medium
    ///
    /// You are given a binary array nums.
    ///
    /// A subarray of an array is good if it contains exactly one element 
    /// with the value 1.
    ///
    /// Return an integer denoting the number of ways to split the array 
    /// nums into good subarrays. As the number may be too large, return 
    /// it modulo 10^9 + 7.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within 
    /// an array.
    /// 
    /// Example 1:
    /// Input: nums = [0,1,0,0,1]
    /// Output: 3
    /// Explanation: There are 3 ways to split nums into good subarrays:
    /// - [0,1] [0,0,1]
    /// - [0,1,0] [0,1]
    /// - [0,1,0,0] [1]
    ///
    /// Example 2:
    /// Input: nums = [0,1,0]
    /// Output: 1
    /// Explanation: There is 1 way to split nums into good subarrays:
    /// - [0,1,0]
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 1
    /// </summary>
    int numberOfGoodSubarraySplits(vector<int>& nums);

    /// <summary>
    /// Leet Code 2760. Longest Even Odd Subarray With Threshold
    /// 
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums and an integer threshold.
    ///
    /// Find the length of the longest subarray of nums starting at index l 
    /// and ending at index r (0 <= l <= r < nums.length) that satisfies the 
    /// following conditions:
    ///
    /// nums[l] % 2 == 0
    /// For all indices i in the range [l, r - 1], 
    /// nums[i] % 2 != nums[i + 1] % 2
    /// For all indices i in the range [l, r], nums[i] <= threshold
    /// Return an integer denoting the length of the longest such subarray.
    ///
    /// Note: A subarray is a contiguous non-empty sequence of elements 
    /// within an array.
    ///
    /// Example 1:
    /// Input: nums = [3,2,5,4], threshold = 5
    /// Output: 3
    /// Explanation: In this example, we can select the subarray that 
    /// starts at l = 1 and ends at r = 3 => [2,5,4]. This subarray satisfies 
    /// the conditions.
    /// Hence, the answer is the length of the subarray, 3. We can show 
    /// that 3 is the maximum possible achievable length.
    ///
    /// Example 2:
    /// Input: nums = [1,2], threshold = 2
    /// Output: 1
    /// Explanation: In this example, we can select the subarray that starts 
    /// at l = 1 and ends at r = 1 => [2]. 
    /// It satisfies all the conditions and we can show that 1 is the maximum 
    /// possible achievable length.
    ///
    /// Example 3:
    /// Input: nums = [2,3,4,5], threshold = 4
    /// Output: 3
    /// Explanation: In this example, we can select the subarray that starts 
    /// at l = 0 and ends at r = 2 => [2,3,4]. 
    /// It satisfies all the conditions.
    /// Hence, the answer is the length of the subarray, 3. We can show 
    /// that 3 is the maximum possible achievable length.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100 
    /// 2. 1 <= nums[i] <= 100 
    /// 3. 1 <= threshold <= 100
    /// </summary>
    int longestAlternatingSubarray(vector<int>& nums, int threshold);

    /// <summary>
    /// Leet Code 2753. Count Houses in a Circular Street II
    /// 
    /// Hard
    ///
    /// You are given an object street of class Street that represents a 
    /// circular street and a positive integer k which represents a 
    /// maximum bound for the number of houses in that street (in other 
    /// words, the number of houses is less than or equal to k). Houses' 
    /// doors could be open or closed initially (at least one is open).
    ///
    /// Initially, you are standing in front of a door to a house on this 
    /// street. Your task is to count the number of houses in the street.
    ///
    /// The class Street contains the following functions which may help you:
    ///
    /// void closeDoor(): Close the door of the house you are in front of.
    /// boolean isDoorOpen(): Returns true if the door of the current house 
    /// is open and false otherwise.
    /// void moveRight(): Move to the right house.
    /// Note that by circular street, we mean if you number the houses from 1 
    /// to n, then the right house of housei is housei+1 for i < n, and the 
    /// right house of housen is house1.
    ///
    /// Return ans which represents the number of houses on this street.
    ///
    /// Example 1:
    /// Input: street = [1,1,1,1], k = 10
    /// Output: 4
    /// Explanation: There are 4 houses, and all their doors are open. 
    /// The number of houses is less than k, which is 10.
    ///
    /// Example 2:
    /// Input: street = [1,0,1,1,0], k = 5
    /// Output: 5
    /// Explanation: There are 5 houses, and the doors of the 1st, 3rd, and 
    /// 4th house (moving in the right direction) are open, and the rest 
    /// are closed.
    /// The number of houses is equal to k, which is 5.
    /// 
    /// Constraints:
    /// 1. n == number of houses
    /// 2. 1 <= n <= k <= 10^5
    /// 3. street is circular by definition provided in the statement.
    /// 4. The input is generated such that at least one of the doors is open.
    /// </summary>
    int houseCountII(Street* street, int k);

    /// <summary>
    /// Leet Code 2765. Longest Alternating Subarray
    /// 
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums. A subarray s of length 
    /// m is called alternating if:
    ///
    /// m is greater than 1.
    /// s1 = s0 + 1.
    /// The 0-indexed subarray s looks like [s0, s1, s0, s1,...,s(m-1) % 2]. In
    /// other words, s1 - s0 = 1, s2 - s1 = -1, s3 - s2 = 1, s4 - s3 = -1, and 
    /// so on up to s[m - 1] - s[m - 2] = (-1)m.
    /// Return the maximum length of all alternating subarrays present in 
    /// nums or -1 if no such subarray exists.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    ///
    /// Example 1:
    /// Input: nums = [2,3,4,3,4]
    /// Output: 4
    /// Explanation: The alternating subarrays are [3,4], [3,4,3], and 
    /// [3,4,3,4]. The longest of these is [3,4,3,4], which is of length 4.
    ///
    /// Example 2:
    ///
    /// Input: nums = [4,5,6]
    /// Output: 2
    /// Explanation: [4,5] and [5,6] are the only two alternating subarrays. 
    /// They are both of length 2.
    ///
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 10^4
    /// </summary>
    int alternatingSubarray(vector<int>& nums);

    /// <summary>
    /// Leet Code 2768. Number of Black Blocks
    /// 
    /// Medium
    ///
    /// You are given two integers m and n representing the dimensions of a 
    /// 0-indexed m x n grid.
    ///
    /// You are also given a 0-indexed 2D integer matrix coordinates, where 
    /// coordinates[i] = [x, y] indicates that the cell with coordinates 
    /// [x, y] is colored black. All cells in the grid that do not appear 
    /// in coordinates are white.
    ///
    /// A block is defined as a 2 x 2 submatrix of the grid. More 
    /// formally, a block with cell [x, y] as its top-left corner 
    /// where 0 <= x < m - 1 and 0 <= y < n - 1 contains the coordinates 
    /// [x, y], [x + 1, y], [x, y + 1], and [x + 1, y + 1].
    ///
    /// Return a 0-indexed integer array arr of size 5 such that arr[i] 
    /// is the number of blocks that contains exactly i black cells.
    ///
    /// Example 1:
    /// Input: m = 3, n = 3, coordinates = [[0,0]]
    /// Output: [3,1,0,0,0]
    /// Explanation: The grid looks like this:
    /// 
    /// There is only 1 block with one black cell, and it is the block 
    /// starting with cell [0,0].
    /// The other 3 blocks start with cells [0,1], [1,0] and [1,1]. They all 
    /// have zero black cells.  
    /// Thus, we return [3,1,0,0,0]. 
    ///
    /// Example 2:
    /// Input: m = 3, n = 3, coordinates = [[0,0],[1,1],[0,2]]
    /// Output: [0,2,2,0,0]
    /// Explanation: The grid looks like this:
    /// There are 2 blocks with two black cells (the ones starting with cell 
    /// coordinates [0,0] and [0,1]).
    /// The other 2 blocks have starting cell coordinates of [1,0] and [1,1]. 
    /// They both have 1 black cell.
    /// Therefore, we return [0,2,2,0,0].
    ///  
    /// Constraints:
    /// 1. 2 <= m <= 10^5
    /// 2. 2 <= n <= 10^5
    /// 3. 0 <= coordinates.length <= 10^4
    /// 4. coordinates[i].length == 2
    /// 5. 0 <= coordinates[i][0] < m
    /// 6. 0 <= coordinates[i][1] < n
    /// 7. It is guaranteed that coordinates contains pairwise distinct 
    ///    coordinates.
    /// </summary>
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates);

    /// <summary>
    /// Leet Code 2780. Minimum Index of a Valid Split
    /// 
    /// Medium
    ///
    /// An element x of an integer array arr of length m is dominant if 
    /// freq(x) * 2 > m, where freq(x) is the number of occurrences of x 
    /// in arr. Note that this definition implies that arr can have at 
    /// most one dominant element.
    ///
    /// You are given a 0-indexed integer array nums of length n with one 
    /// dominant element.
    ///
    /// You can split nums at an index i into two arrays nums[0, ..., i] and 
    /// nums[i + 1, ..., n - 1], but the split is only valid if:
    ///
    /// 0 <= i < n - 1
    /// nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant 
    /// element.
    /// Here, nums[i, ..., j] denotes the subarray of nums starting at index i 
    /// and ending at index j, both ends being inclusive. Particularly, 
    /// if j < i then nums[i, ..., j] denotes an empty subarray.
    ///
    /// Return the minimum index of a valid split. If no valid split exists, 
    /// return -1.
    ///
    /// Example 1:
    /// Input: nums = [1,2,2,2]
    /// Output: 2
    /// Explanation: We can split the array at index 2 to obtain 
    /// arrays [1,2,2] and [2]. 
    /// In array [1,2,2], element 2 is dominant since it occurs twice in the 
    /// array and 2 * 2 > 3. 
    /// In array [2], element 2 is dominant since it occurs once in the array 
    /// and 1 * 2 > 1.
    /// Both [1,2,2] and [2] have the same dominant element as nums, so this 
    /// is a valid split. 
    /// It can be shown that index 2 is the minimum index of a valid split. 
    ///
    /// Example 2:
    /// Input: nums = [2,1,3,1,1,1,7,1,2,1]
    /// Output: 4
    /// Explanation: We can split the array at index 4 to obtain arrays 
    /// [2,1,3,1,1] and [1,7,1,2,1].
    /// In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in 
    /// the array and 3 * 2 > 5.
    /// In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in 
    /// the array and 3 * 2 > 5.
    /// Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as 
    /// nums, so this is a valid split.
    /// It can be shown that index 4 is the minimum index of a valid split.
    ///
    /// Example 3:
    /// Input: nums = [3,3,3,3,7,2,2]
    /// Output: -1
    /// Explanation: It can be shown that there is no valid split.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. nums has exactly one dominant element.
    /// </summary>
    int minimumIndex(vector<int>& nums);

    /// <summary>
    /// Leet Code 2772. Apply Operations to Make All Array Elements Equal to 
    ///                 Zero
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums and a positive integer k.
    ///
    /// You can apply the following operation on the array any number of times:
    /// 
    /// Choose any subarray of size k from the array and decrease all its 
    /// elements by 1.
    /// Return true if you can make all the array elements equal to 0, or false 
    /// otherwise.
    ///
    /// A subarray is a contiguous non-empty part of an array.
    ///
    /// Example 1:
    /// Input: nums = [2,2,3,1,1,0], k = 3
    /// Output: true
    /// Explanation: We can do the following operations:
    /// - Choose the subarray [2,2,3]. The resulting array will be 
    ///   nums = [1,1,2,1,1,0].
    /// - Choose the subarray [2,1,1]. The resulting array will be 
    ///   nums = [1,1,1,0,0,0].
    /// - Choose the subarray [1,1,1]. The resulting array will be 
    ///   nums = [0,0,0,0,0,0].
    //
    /// Example 2:
    /// Input: nums = [1,3,1,1], k = 2
    /// Output: false
    /// Explanation: It is not possible to make all the array 
    /// elements equal to 0.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^6
    /// </summary>
    bool checkArray(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2782. Number of Unique Categories
    /// 
    /// Medium
    ///
    /// You are given an integer n and an object categoryHandler of class 
    /// CategoryHandler.
    ///
    /// There are nelements, numbered from 0 to n - 1. Each element has a 
    /// category, and your task is to find the number of unique categories.
    ///
    /// The class CategoryHandler contains the following function, which may 
    /// help you:
    ///
    /// boolean haveSameCategory(integer a, integer b): Returns true if a and 
    /// b are in the same category and false otherwise. Also, if either a or 
    /// b is not a valid number (i.e. it's greater than or equal to nor less 
    /// than 0), it returns false.
    /// Return the number of unique categories.
    /// 
    /// Example 1:
    /// Input: n = 6, catagoryHandler = [1,1,2,2,3,3]
    /// Output: 3
    /// Explanation: There are 6 elements in this example. The first two 
    /// elements belong to category 1, the second two belong to category 2, 
    /// and the last two elements belong to category 3. So there are 3 unique 
    /// categories.
    ///
    /// Example 2:
    /// Input: n = 5, catagoryHandler = [1,2,3,4,5]
    /// Output: 5
    /// Explanation: There are 5 elements in this example. Each element 
    /// belongs to a unique category. So there are 5 unique categories.
    ///
    /// Example 3:
    /// Input: n = 3, catagoryHandler = [1,1,1]
    /// Output: 1
    /// Explanation: There are 3 elements in this example. All of them belong 
    /// to one category. So there is only 1 unique category.
    ///
    ///
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// </summary>
    int numberOfCategories(int n, vector<int>& categoryHandler);

    /// <summary>
    /// Leet Code 2784. Check if Array is Good
    /// 
    /// Easy
    ///
    /// You are given an integer array nums. We consider an array good if it 
    /// is a permutation of an array base[n].
    ///
    /// base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array 
    /// of length n + 1 which contains 1 to n - 1 exactly once, plus two 
    /// occurrences of n). For example, base[1] = [1, 1] and 
    /// base[3] = [1, 2, 3, 3].
    ///
    /// Return true if the given array is good, otherwise return false.
    ///
    /// Note: A permutation of integers represents an arrangement of these 
    /// numbers.
    ///
    /// Example 1:
    /// Input: nums = [2, 1, 3]
    /// Output: false
    /// Explanation: Since the maximum element of the array is 3, the only 
    /// candidate n for which this array could be a permutation of base[n], 
    /// is n = 3. However, base[3] has four elements but array nums has 
    /// three. Therefore, it can not be a permutation of base[3] = 
    /// [1, 2, 3, 3]. So the answer is false.
    ///
    /// Example 2:
    /// Input: nums = [1, 3, 3, 2]
    /// Output: true
    /// Explanation: Since the maximum element of the array is 3, the only 
    /// candidate n for which this array could be a permutation of base[n], 
    /// is n = 3. It can be seen that nums is a permutation of base[3] = 
    /// [1, 2, 3, 3] (by swapping the second and fourth elements in nums, 
    /// we reach base[3]). Therefore, the answer is true.
    ///
    /// Example 3:
    /// Input: nums = [1, 1]
    /// Output: true
    /// Explanation: Since the maximum element of the array is 1, the only 
    /// candidate n for which this array could be a permutation of base[n], 
    /// is n = 1. It can be seen that nums is a permutation of 
    /// base[1] = [1, 1]. Therefore, the answer is true.
    ///
    /// Example 4:
    /// Input: nums = [3, 4, 4, 1, 2, 1]
    /// Output: false
    /// Explanation: Since the maximum element of the array is 4, the only 
    /// candidate n for which this array could be a permutation of base[n], 
    /// is n = 4. However, base[4] has five elements but array nums has six. 
    /// Therefore, it can not be a permutation of base[4] = [1, 2, 3, 4, 4]. 
    /// So the answer is false.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= num[i] <= 200
    /// </summary>
    bool isGood(vector<int>& nums);

    /// <summary>
    /// Leet Code 2789. Largest Element in an Array after Merge Operations
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed array nums consisting of positive integers.
    ///
    /// You can do the following operation on the array any number of times:
    ///
    /// Choose an integer i such that 0 <= i < nums.length - 1 and 
    /// nums[i] <= nums[i + 1]. Replace the element nums[i + 1] with 
    /// nums[i] + nums[i + 1] and delete the element nums[i] from the array.
    /// Return the value of the largest element that you can possibly obtain 
    /// in the final array.
    ///
    /// Example 1:
    /// Input: nums = [2,3,7,9,3]
    /// Output: 21
    /// Explanation: We can apply the following operations on the array:
    /// - Choose i = 0. The resulting array will be nums = [5,7,9,3].
    /// - Choose i = 1. The resulting array will be nums = [5,16,3].
    /// - Choose i = 0. The resulting array will be nums = [21,3].
    /// The largest element in the final array is 21. It can be shown that 
    /// we cannot obtain a larger element.
    ///
    /// Example 2:
    /// Input: nums = [5,3,3]
    /// Output: 11
    /// Explanation: We can do the following operations on the array:
    /// - Choose i = 1. The resulting array will be nums = [5,6].
    /// - Choose i = 0. The resulting array will be nums = [11].
    /// There is only one element in the final array, which is 11.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    long long maxArrayValue(vector<int>& nums);

    /// <summary>
    /// Leet Code 2798. Number of Employees Who Met the Target
    /// 
    /// Easy
    ///
    /// There are n employees in a company, numbered from 0 to n - 1. Each 
    /// employee i has worked for hours[i] hours in the company.
    ///
    /// The company requires each employee to work for at least target hours.
    ///
    /// You are given a 0-indexed array of non-negative integers hours of 
    /// length n and a non-negative integer target.
    ///
    /// Return the integer denoting the number of employees who worked at 
    /// least target hours.
    ///
    /// Example 1:
    /// Input: hours = [0,1,2,3,4], target = 2
    /// Output: 3
    /// Explanation: The company wants each employee to work for at least 2 
    /// hours.
    /// - Employee 0 worked for 0 hours and didn't meet the target.
    /// - Employee 1 worked for 1 hours and didn't meet the target.
    /// - Employee 2 worked for 2 hours and met the target.
    /// - Employee 3 worked for 3 hours and met the target.
    /// - Employee 4 worked for 4 hours and met the target.
    /// There are 3 employees who met the target.
    ///
    /// Example 2:
    /// Input: hours = [5,1,4,2,2], target = 6
    /// Output: 0
    /// Explanation: The company wants each employee to work for at least 6 
    /// hours.
    /// There are 0 employees who met the target.
    ///
    /// Constraints:
    /// 1. 1 <= n == hours.length <= 50
    /// 2. 0 <= hours[i], target <= 10^5
    /// </summary>
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target);

    /// <summary>
    /// Leet Code 2808. Minimum Seconds to Equalize a Circular Array
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed array nums containing n integers.
    ///
    /// At each second, you perform the following operation on the array:
    ///
    /// For every index i in the range [0, n - 1], replace nums[i] with 
    /// either nums[i], nums[(i - 1 + n) % n], or nums[(i + 1) % n].
    /// Note that all the elements get replaced simultaneously.
    ///
    /// Return the minimum number of seconds needed to make all elements 
    /// in the array nums equal.
    ///
    /// Example 1:
    /// Input: nums = [1,2,1,2]
    /// Output: 1
    /// Explanation: We can equalize the array in 1 second in the following 
    /// way:
    /// - At 1st second, replace values at each index with [nums[3],nums[1],
    /// nums[3],nums[3]]. After replacement, nums = [2,2,2,2].
    /// It can be proven that 1 second is the minimum amount of seconds 
    /// needed for equalizing the array.
    ///
    /// Example 2:
    /// Input: nums = [2,1,3,3,2]
    /// Output: 2
    /// Explanation: We can equalize the array in 2 seconds in the following 
    /// way:
    /// - At 1st second, replace values at each index with [nums[0],nums[2],
    ///   nums[2],nums[2],nums[3]]. After replacement, nums = [2,3,3,3,3].
    /// - At 2nd second, replace values at each index with [nums[1],nums[1],
    ///   nums[2],nums[3],nums[4]]. After replacement, nums = [3,3,3,3,3].
    /// It can be proven that 2 seconds is the minimum amount of seconds 
    /// needed for equalizing the array.
    ///
    /// Example 3:
    /// Input: nums = [5,5,5,5]
    /// Output: 0
    /// Explanation: We don't need to perform any operations as all elements 
    /// in the initial array are the same.
    ///
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    int minimumSeconds(vector<int>& nums);

    /// <summary>
    /// Leet Code 2811. Check if it is Possible to Split Array
    /// 
    /// Medium
    ///
    /// You are given an array nums of length n and an integer m. You need to 
    /// determine if it is possible to split the array into n non-empty 
    /// arrays by performing a series of steps.
    ///
    /// In each step, you can select an existing array (which may be the 
    /// result of previous steps) with a length of at least two and split 
    /// it into two subarrays, if, for each resulting subarray, at least 
    /// one of the following holds:
    ///
    /// The length of the subarray is one, or
    /// The sum of elements of the subarray is greater than or equal to m.
    /// Return true if you can split the given array into n arrays, otherwise 
    /// return false.
    ///
    /// Note: A subarray is a contiguous non-empty sequence of elements 
    /// within an array.
    ///  
    /// Example 1:
    /// Input: nums = [2, 2, 1], m = 4
    /// Output: true
    /// Explanation: We can split the array into [2, 2] and [1] in the 
    /// first step. Then, in the second step, we can split [2, 2] into [2] 
    /// and [2]. As a result, the answer is true.
    ///
    /// Example 2:
    /// Input: nums = [2, 1, 3], m = 5 
    /// Output: false
    /// Explanation: We can try splitting the array in two different ways: 
    /// the first way is to have [2, 1] and [3], and the second way is to 
    /// have [2] and [1, 3]. However, both of these ways are not valid. So, 
    /// the answer is false.
    ///
    /// Example 3:
    /// Input: nums = [2, 3, 3, 2, 3], m = 6
    /// Output: true
    /// Explanation: We can split the array into [2, 3, 3, 2] and [3] 
    /// in the first step. Then, in the second step, we can split 
    /// [2, 3, 3, 2] into [2, 3, 3] and [2]. Then, in the third step, 
    /// we can split [2, 3, 3] into [2] and [3, 3]. And in the last 
    /// step we can split [3, 3] into [3] and [3]. As a result, 
    /// the answer is true.
    /// 
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// 3. 1 <= m <= 200
    /// </summary>
    bool canSplitArray(vector<int>& nums, int m);

    /// <summary>
    /// Leet Code 2824. Count Pairs Whose Sum is Less than Target
    /// 
    /// Easy
    ///
    /// Given a 0-indexed integer array nums of length n and an integer 
    /// target, return the number of pairs (i, j) where 0 <= i < j < n and 
    /// nums[i] + nums[j] < target.
    ///
    /// Example 1:
    /// Input: nums = [-1,1,2,3,1], target = 2
    /// Output: 3
    /// Explanation: There are 3 pairs of indices that satisfy the conditions 
    /// in the statement:
    /// - (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
    /// - (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target 
    /// - (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
    /// Note that (0, 3) is not counted since nums[0] + nums[3] is not 
    /// strictly less than the target.
    ///
    /// Example 2:
    /// Input: nums = [-6,2,5,-2,-7,-1,3], target = -2
    /// Output: 10
    /// Explanation: There are 10 pairs of indices that satisfy the conditions 
    /// in the statement:
    /// - (0, 1) since 0 < 1 and nums[0] + nums[1] = -4 < target
    /// - (0, 3) since 0 < 3 and nums[0] + nums[3] = -8 < target
    /// - (0, 4) since 0 < 4 and nums[0] + nums[4] = -13 < target
    /// - (0, 5) since 0 < 5 and nums[0] + nums[5] = -7 < target
    /// - (0, 6) since 0 < 6 and nums[0] + nums[6] = -3 < target
    /// - (1, 4) since 1 < 4 and nums[1] + nums[4] = -5 < target
    /// - (3, 4) since 3 < 4 and nums[3] + nums[4] = -9 < target
    /// - (3, 5) since 3 < 5 and nums[3] + nums[5] = -3 < target
    /// - (4, 5) since 4 < 5 and nums[4] + nums[5] = -8 < target
    /// - (4, 6) since 4 < 6 and nums[4] + nums[6] = -4 < target
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length == n <= 50
    /// 2. -50 <= nums[i], target <= 50
    /// </summary>
    int countPairsII(vector<int>& nums, int target);

    /// <summary>
    /// Leet Code 2836. Maximize Value of Function in a Ball Passing Game
    /// 
    /// Hard
    ///
    /// You are given a 0-indexed integer array receiver of length n and an 
    /// integer k.
    ///
    /// There are n players having a unique id in the range [0, n - 1] who 
    /// will play a ball passing game, and receiver[i] is the id of the 
    /// player who receives passes from the player with id i. Players can 
    /// pass to themselves, i.e. receiver[i] may be equal to i.
    ///
    /// You must choose one of the n players as the starting player for the 
    /// game, and the ball will be passed exactly k times starting from the 
    /// chosen player.
    ///
    /// For a chosen starting player having id x, we define a function f(x) 
    /// that denotes the sum of x and the ids of all players who receive the 
    /// ball during the k passes, including repetitions. In other words, 
    /// f(x) = x + receiver[x] + receiver[receiver[x]] + ... + receiver(k)[x].
    ///
    /// Your task is to choose a starting player having id x that maximizes 
    /// the value of f(x).
    /// 
    /// Return an integer denoting the maximum value of the function.
    ///
    /// Note: receiver may contain duplicates.
    ///
    ///
    ///
    /// Example 1:
    ///
    /// Pass Number Sender ID   Receiver ID x + Receiver IDs
    ///             2
    /// 1   2   1   3
    /// 2   1   0   3
    /// 3   0   2   5
    /// 4   2   1   6
    /// Input: receiver = [2,0,1], k = 4
    /// Output: 6
    /// Explanation: The table above shows a simulation of the game starting 
    /// with the player having id x = 2. 
    /// From the table, f(2) is equal to 6. 
    /// It can be shown that 6 is the maximum achievable value of the function. 
    /// Hence, the output is 6. 
    ///
    /// Example 2:
    ///
    /// Pass Number Sender ID   Receiver ID x + Receiver IDs
    ///             4
    /// 1   4   3   7
    /// 2   3   2   9
    /// 3   2   1   10
    /// Input: receiver = [1,1,1,2,3], k = 3
    /// Output: 10
    /// Explanation: The table above shows a simulation of the game starting 
    /// with the player having id x = 4. 
    /// From the table, f(4) is equal to 10. 
    /// It can be shown that 10 is the maximum achievable value of the 
    /// function. 
    /// Hence, the output is 10. 
    ///
    /// Constraints:
    /// 1. 1 <= receiver.length == n <= 10^5
    /// 2.  0 <= receiver[i] <= n - 1
    /// 3. 1 <= k <= 10^10
    /// </summary>
    long long getMaxFunctionValue(vector<int>& receiver, long long k);

    /// <summary>
    /// Leet Code 2845. Count of Interesting Subarrays
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums, an integer modulo, 
    /// and an integer k.
    ///
    /// Your task is to find the count of subarrays that are interesting.
    ///
    /// A subarray nums[l..r] is interesting if the following condition holds:
    ///
    /// Let cnt be the number of indices i in the range [l, r] such that 
    /// nums[i] % modulo == k. Then, cnt % modulo == k.
    /// Return an integer denoting the count of interesting subarrays.
    ///
    /// Note: A subarray is a contiguous non-empty sequence of elements 
    /// within an array.
    /// 
    /// Example 1:
    /// Input: nums = [3,2,4], modulo = 2, k = 1
    /// Output: 3
    /// Explanation: In this example the interesting subarrays are: 
    /// The subarray nums[0..0] which is [3]. 
    /// - There is only one index, i = 0, in the range [0, 0] that satisfies 
    ///   nums[i] % modulo == k. 
    /// - Hence, cnt = 1 and cnt % modulo == k.  
    /// The subarray nums[0..1] which is [3,2].
    /// - There is only one index, i = 0, in the range [0, 1] that satisfies 
    ///   nums[i] % modulo == k.  
    /// - Hence, cnt = 1 and cnt % modulo == k.
    /// The subarray nums[0..2] which is [3,2,4]. 
    /// - There is only one index, i = 0, in the range [0, 2] that satisfies 
    ///   nums[i] % modulo == k. 
    /// - Hence, cnt = 1 and cnt % modulo == k. 
    /// It can be shown that there are no other interesting subarrays. So, the 
    /// answer is 3.
    ///
    /// Example 2:
    /// Input: nums = [3,1,9,6], modulo = 3, k = 0
    /// Output: 2
    /// Explanation: In this example the interesting subarrays are: 
    /// The subarray nums[0..3] which is [3,1,9,6]. 
    /// - There are three indices, i = 0, 2, 3, in the range [0, 3] that 
    ///   satisfy nums[i] % modulo == k. 
    /// - Hence, cnt = 3 and cnt % modulo == k. 
    /// The subarray nums[1..1] which is [1]. 
    /// - There is no index, i, in the range [1, 1] that satisfies 
    ///   nums[i] % modulo == k. 
    /// - Hence, cnt = 0 and cnt % modulo == k. 
    /// It can be shown that there are no other interesting subarrays. So, 
    /// the answer is 2.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5 
    /// 2. 1 <= nums[i] <= 109
    /// 3. 1 <= modulo <= 109
    /// 4. 0 <= k < modulo
    /// </summary>
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k);

    /// <summary>
    /// Leet Code 2869. Minimum Operations to Collect Elements
    /// 
    /// Easy
    /// 
    /// You are given an array nums of positive integers and an integer k.
    ///
    /// In one operation, you can remove the last element of the array and 
    /// add it to your collection.
    ///
    /// Return the minimum number of operations needed to collect 
    /// elements 1, 2, ..., k.
    /// 
    /// Example 1:
    /// Input: nums = [3,1,5,4,2], k = 2
    /// Output: 4
    /// Explanation: After 4 operations, we collect elements 2, 4, 5, and 1, 
    /// in this order. Our collection contains elements 1 and 2. Hence, the 
    /// answer is 4.
    ///
    /// Example 2:
    /// Input: nums = [3,1,5,4,2], k = 5
    /// Output: 5
    /// Explanation: After 5 operations, we collect elements 2, 4, 5, 1, 
    /// and 3, in this order. Our collection contains elements 1 through 5. 
    /// Hence, the answer is 5.
    ///
    /// Example 3:
    /// Input: nums = [3,2,5,3,1], k = 3
    /// Output: 4
    /// Explanation: After 4 operations, we collect elements 1, 3, 5, and 2, 
    /// in this order. Our collection contains elements 1 through 3. Hence, 
    /// the answer is 4.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 50
    /// 2. 1 <= nums[i] <= nums.length
    /// 3. 1 <= k <= nums.length
    /// 4. The input is generated such that you can collect 
    ///    elements 1, 2, ..., k.
    /// </summary>
    int minOperationsII(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2873. Maximum Value of an Ordered Triplet I
    /// 
    /// Easy
    /// 
    /// You are given a 0-indexed integer array nums.
    ///
    /// Return the maximum value over all triplets of indices (i, j, k) such 
    /// that i < j < k. If all such triplets have a negative value, return 0.
    ///
    /// The value of a triplet of indices (i, j, k) is equal to 
    /// (nums[i] - nums[j]) * nums[k].
    ///
    /// Example 1:
    /// Input: nums = [12,6,1,2,7]
    /// Output: 77
    /// Explanation: The value of the triplet (0, 2, 4) is 
    /// (nums[0] - nums[2]) * nums[4] = 77.
    /// It can be shown that there are no ordered triplets of indices with a 
    /// value greater than 77. 
    ///
    /// Example 2:
    /// Input: nums = [1,10,3,4,19]
    /// Output: 133
    /// Explanation: The value of the triplet (1, 2, 4) is 
    /// (nums[1] - nums[2]) * nums[4] = 133.
    /// It can be shown that there are no ordered triplets of indices 
    /// with a value greater than 133.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3]
    /// Output: 0
    /// Explanation: The only ordered triplet of indices (0, 1, 2) has a 
    /// negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the 
    /// answer would be 0.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    long long maximumTripletValue(vector<int>& nums);

    /// <summary>
    /// Leet Code 2874. Maximum Value of an Ordered Triplet II
    /// 
    /// Medium
    /// 
    /// You are given a 0-indexed integer array nums.
    ///
    /// Return the maximum value over all triplets of indices (i, j, k) such 
    /// that i < j < k. If all such triplets have a negative value, return 0.
    ///
    /// The value of a triplet of indices (i, j, k) is equal to 
    /// (nums[i] - nums[j]) * nums[k].
    ///  
    /// Example 1:
    /// Input: nums = [12,6,1,2,7]
    /// Output: 77
    /// Explanation: The value of the triplet (0, 2, 4) is 
    /// (nums[0] - nums[2]) * nums[4] = 77.
    /// It can be shown that there are no ordered triplets of indices with a 
    /// value greater than 77. 
    ///
    /// Example 2:
    /// Input: nums = [1,10,3,4,19]
    /// Output: 133
    /// Explanation: The value of the triplet (1, 2, 4) is 
    /// (nums[1] - nums[2]) * nums[4] = 133.
    /// It can be shown that there are no ordered triplets of indices with a 
    /// value greater than 133.
    ///
    /// Example 3:
    /// Input: nums = [1,2,3]
    /// Output: 0
    /// Explanation: The only ordered triplet of indices (0, 1, 2) has a 
    /// negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the 
    /// answer would be 0.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    long long maximumTripletValueII(vector<int>& nums);

    /// <summary>
    /// Leet Code 2871. Split Array Into Maximum Number of Subarrays
    /// 
    /// Medium
    /// 
    /// You are given an array nums consisting of non-negative integers.
    ///
    /// We define the score of subarray nums[l..r] such that l <= r as 
    /// nums[l] AND nums[l + 1] AND ... AND nums[r] where AND is the bitwise 
    /// AND operation.
    ///
    /// Consider splitting the array into one or more subarrays such that 
    /// the following conditions are satisfied:
    ///
    /// Each element of the array belongs to exactly one subarray.
    /// The sum of scores of the subarrays is the minimum possible.
    /// Return the maximum number of subarrays in a split that satisfies 
    /// the conditions above.
    ///
    /// A subarray is a contiguous part of an array.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,0,2,0,1,2]
    /// Output: 3
    /// Explanation: We can split the array into the following subarrays:
    /// - [1,0]. The score of this subarray is 1 AND 0 = 0.
    /// - [2,0]. The score of this subarray is 2 AND 0 = 0.
    /// - [1,2]. The score of this subarray is 1 AND 2 = 0.
    /// The sum of scores is 0 + 0 + 0 = 0, which is the minimum possible 
    /// score that we can obtain.
    /// It can be shown that we cannot split the array into more than 3 
    /// subarrays with a total score of 0. So we return 3.
    ///
    /// Example 2:
    /// Input: nums = [5,7,1,3]
    /// Output: 1
    /// Explanation: We can split the array into one subarray: [5,7,1,3] 
    /// with a score of 1, which is the minimum possible score that we can 
    /// obtain.
    /// It can be shown that we cannot split the array into more than 1 
    /// subarray with a total score of 1. So we return 1.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^6
    /// </summary>
    int maxSubarrays(vector<int>& nums);

    /// <summary>
    /// Leet Code 2875. Minimum Size Subarray in Infinite Array
    /// 
    /// Medium
    /// 
    /// You are given a 0-indexed array nums and an integer target.
    ///
    /// A 0-indexed array infinite_nums is generated by infinitely appending 
    /// the elements of nums to itself.
    ///
    /// Return the length of the shortest subarray of the array infinite_nums 
    /// with a sum equal to target. If there is no such subarray return -1.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3], target = 5
    /// Output: 2
    /// Explanation: In this example infinite_nums = [1,2,3,1,2,3,1,2,...].
    /// The subarray in the range [1,2], has the sum equal to target = 5 and 
    /// length = 2.
    /// It can be proven that 2 is the shortest length of a subarray with sum 
    /// equal to target = 5.
    ///
    /// Example 2:
    /// Input: nums = [1,1,1,2,3], target = 4
    /// Output: 2
    /// Explanation: In this example infinite_nums = 
    /// [1,1,1,2,3,1,1,1,2,3,1,1,...].
    /// The subarray in the range [4,5], has the sum equal to target = 4 and 
    /// length = 2.
    /// It can be proven that 2 is the shortest length of a subarray with sum 
    /// equal to target = 4.
    ///
    /// Example 3:
    ///
    /// Input: nums = [2,4,6,8], target = 3
    /// Output: -1
    /// Explanation: In this example infinite_nums = [2,4,6,8,2,4,6,8,...].
    /// It can be proven that there is no subarray with sum equal to 
    /// target = 3.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// 3. 1 <= target <= 10^9
    /// </summary>
    int minSizeSubarray(vector<int>& nums, int target);

    /// <summary>
    /// Leet Code 2892. Minimizing Array After Replacing Pairs With Their 
    ///                 Product
    /// 
    /// Medium
    /// 
    /// Given an integer array nums and an integer k, you can perform the 
    /// following operation on the array any number of times:
    ///
    /// Select two adjacent elements of the array like x and y, such that 
    /// x * y <= k, and replace both of them with a single element with 
    /// value x * y (e.g. in one operation the array [1, 2, 2, 3] with 
    /// k = 5 can become [1, 4, 3] or [2, 2, 3], but can't become [1, 2, 6]).
    /// Return the minimum possible length of nums after any number of 
    /// operations.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [2,3,3,7,3,5], k = 20
    /// Output: 3
    /// Explanation: We perform these operations:
    /// 1. [2,3,3,7,3,5] -> [6,3,7,3,5]
    /// 2. [6,3,7,3,5] -> [18,7,3,5]
    /// 3. [18,7,3,5] -> [18,7,15]
    /// It can be shown that 3 is the minimum length possible to achieve with 
    /// the given operation.
    ///
    /// Example 2:
    /// Input: nums = [3,3,3,3], k = 6
    /// Output: 4
    /// Explanation: We can't perform any operations since the product of 
    /// every two adjacent elements is greater than 6.
    /// Hence, the answer is 4.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// 3. 1 <= k <= 10^9
    /// </summary>
    int minArrayLength(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2898. Maximum Linear Stock Score
    /// 
    /// Medium
    /// 
    /// Given a 1-indexed integer array prices, where prices[i] is the price 
    /// of a particular stock on the ith day, your task is to select some of 
    /// the elements of prices such that your selection is linear.
    ///
    /// A selection indexes, where indexes is a 1-indexed integer array of 
    /// length k which is a subsequence of the array [1, 2, ..., n], is 
    /// linear if:
    ///
    /// For every 1 < j <= k, prices[indexes[j]] - prices[indexes[j - 1]] == 
    /// indexes[j] - indexes[j - 1].
    /// A subsequence is an array that can be derived from another array by 
    /// deleting some or no elements without changing the order of the 
    /// remaining elements.
    ///
    /// The score of a selection indexes, is equal to the sum of the following 
    /// array: [prices[indexes[1]], prices[indexes[2]], ..., 
    /// prices[indexes[k]].
    ///
    /// Return the maximum score that a linear selection can have.
    /// 
    /// Example 1:
    /// Input: prices = [1,5,3,7,8]
    /// Output: 20
    /// Explanation: We can select the indexes [2,4,5]. We show that our 
    /// selection is linear:
    /// For j = 2, we have:
    /// indexes[2] - indexes[1] = 4 - 2 = 2.
    /// prices[4] - prices[2] = 7 - 5 = 2.
    /// For j = 3, we have:
    /// indexes[3] - indexes[2] = 5 - 4 = 1.
    /// prices[5] - prices[4] = 8 - 7 = 1.
    /// The sum of the elements is: prices[2] + prices[4] + prices[5] = 20.
    /// It can be shown that the maximum sum a linear selection can have is 20.
    ///
    /// Example 2:
    /// Input: prices = [5,6,7,8,9]
    /// Output: 35
    /// Explanation: We can select all of the indexes [1,2,3,4,5]. Since each 
    /// element has a difference of exactly 1 from its previous element, our 
    /// selection is linear.
    /// The sum of all the elements is 35 which is the maximum possible some 
    /// out of every selection.
    /// 
    /// Constraints:
    /// 1. 1 <= prices.length <= 10^5
    /// 2. 1 <= prices[i] <= 10^9
    /// </summary>
    long long maxStockScore(vector<int>& prices);

    /// <summary>
    /// Leet Code 2899. Last Visited Integers
    /// 
    /// Easy
    /// 
    /// Given a 0-indexed array of strings words where words[i] is either a 
    /// positive integer represented as a string or the string "prev".
    ///
    /// Start iterating from the beginning of the array; for every "prev" 
    /// string seen in words, find the last visited integer in words which 
    /// is defined as follows:
    ///
    /// Let k be the number of consecutive "prev" strings seen so far 
    /// (containing the current string). Let nums be the 0-indexed array 
    /// of integers seen so far and nums_reverse be the reverse of nums, 
    /// then the integer at (k - 1)th index of nums_reverse will be the 
    /// last visited integer for this "prev".
    /// If k is greater than the total visited integers, then the last 
    /// visited integer will be -1.
    /// Return an integer array containing the last visited integers.
    ///
    /// Example 1:
    /// Input: words = ["1","2","prev","prev","prev"]
    /// Output: [2,1,-1]
    /// Explanation: 
    /// For "prev" at index = 2, last visited integer will be 2 as here 
    /// the number of consecutive "prev" strings is 1, and in the array 
    /// reverse_nums, 2 will be the first element.
    /// For "prev" at index = 3, last visited integer will be 1 as there 
    /// are a total of two consecutive "prev" strings including this 
    /// "prev" which are visited, and 1 is the second last visited integer.
    /// For "prev" at index = 4, last visited integer will be -1 as there 
    /// are a total of three consecutive "prev" strings including this "prev" 
    /// which are visited, but the total number of integers visited is two.
    ///
    /// Example 2:
    /// Input: words = ["1","prev","2","prev","prev"]
    /// Output: [1,2,1]
    /// Explanation:
    /// For "prev" at index = 1, last visited integer will be 1.
    /// For "prev" at index = 3, last visited integer will be 2.
    /// For "prev" at index = 4, last visited integer will be 1 as there are 
    /// a total of two consecutive "prev" strings including this "prev" 
    /// which are visited, and 1 is the second last visited integer.
    ///
    /// Constraints:
    /// 1. 1 <= words.length <= 100
    /// 2. words[i] == "prev" or 1 <= int(words[i]) <= 100
    /// </summary>
    vector<int> lastVisitedIntegers(vector<string>& words);

    /// <summary>
    /// Leet Code 2900. Longest Unequal Adjacent Groups Subsequence I
    /// 
    /// Medium
    /// 
    /// You are given an integer n, a 0-indexed string array words, and a 
    /// 0-indexed binary array groups, both arrays having length n.
    ///
    /// You need to select the longest subsequence from an array of indices 
    /// [0, 1, ..., n - 1], such that for the subsequence denoted as 
    /// [i0, i1, ..., ik - 1] having length k, groups[ij] != groups[ij + 1], 
    /// for each j where 0 < j + 1 < k.
    ///
    /// Return a string array containing the words corresponding to the 
    /// indices (in order) in the selected subsequence. If there are 
    /// multiple answers, return any of them.
    ///
    /// A subsequence of an array is a new array that is formed from the 
    /// original array by deleting some (possibly none) of the elements 
    /// without disturbing the relative positions of the remaining elements.
    ///
    /// Note: strings in words may be unequal in length.
    ///
    /// Example 1:
    /// Input: n = 3, words = ["e","a","b"], groups = [0,0,1]
    /// Output: ["e","b"]
    /// Explanation: A subsequence that can be selected is [0,2] because 
    /// groups[0] != groups[2].
    /// So, a valid answer is [words[0],words[2]] = ["e","b"].
    /// Another subsequence that can be selected is [1,2] because 
    /// groups[1] != groups[2].
    /// This results in [words[1],words[2]] = ["a","b"].
    /// It is also a valid answer.
    /// It can be shown that the length of the longest subsequence of 
    /// indices that satisfies the condition is 2.
    ///
    /// Example 2:
    /// Input: n = 4, words = ["a","b","c","d"], groups = [1,0,1,1]
    /// Output: ["a","b","c"]
    /// Explanation: A subsequence that can be selected is [0,1,2] because 
    /// groups[0] != groups[1] and groups[1] != groups[2].
    /// So, a valid answer is [words[0],words[1],words[2]] = ["a","b","c"].
    /// Another subsequence that can be selected is [0,1,3] because 
    /// groups[0] != groups[1] and groups[1] != groups[3].
    /// This results in [words[0],words[1],words[3]] = ["a","b","d"].
    /// It is also a valid answer.
    /// It can be shown that the length of the longest subsequence of indices 
    /// that satisfies the condition is 3.
    ///
    /// Constraints:
    /// 1. 1 <= n == words.length == groups.length <= 100
    /// 2. 1 <= words[i].length <= 10
    /// 3. 0 <= groups[i] < 2
    /// 4. words consists of distinct strings.
    /// 5. words[i] consists of lowercase English letters.
    /// </summary>
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups);

    /// <summary>
    /// Leet Code 2901. Longest Unequal Adjacent Groups Subsequence II
    /// 
    /// Medium
    /// 
    /// You are given an integer n, a 0-indexed string array words, and a 
    /// 0-indexed array groups, both arrays having length n.
    ///
    /// The hamming distance between two strings of equal length is the number 
    /// of positions at which the corresponding characters are different.
    ///
    /// You need to select the longest subsequence from an array of indices 
    /// [0, 1, ..., n - 1], such that for the subsequence denoted as 
    /// [i0, i1, ..., ik - 1] having length k, the following holds:
    ///
    /// For adjacent indices in the subsequence, their corresponding groups 
    /// are unequal, i.e., groups[ij] != groups[ij + 1], for each j 
    /// where 0 < j + 1 < k.
    /// words[ij] and words[ij + 1] are equal in length, and the hamming 
    /// distance between them is 1, where 0 < j + 1 < k, for all indices in 
    /// the subsequence.
    /// Return a string array containing the words corresponding to the 
    /// indices (in order) in the selected subsequence. If there are multiple 
    /// answers, return any of them.
    ///
    /// A subsequence of an array is a new array that is formed from the 
    /// original array by deleting some (possibly none) of the elements 
    /// without disturbing the relative positions of the remaining elements.
    ///
    /// Note: strings in words may be unequal in length.
    /// 
    /// Example 1:
    /// Input: n = 3, words = ["bab","dab","cab"], groups = [1,2,2]
    /// Output: ["bab","cab"]
    /// Explanation: A subsequence that can be selected is [0,2].
    /// - groups[0] != groups[2]
    /// - words[0].length == words[2].length, and the hamming distance 
    ///   between them is 1.
    /// So, a valid answer is [words[0],words[2]] = ["bab","cab"].
    /// Another subsequence that can be selected is [0,1].
    /// - groups[0] != groups[1]
    /// - words[0].length == words[1].length, and the hamming distance 
    ///   between them is 1.
    /// So, another valid answer is [words[0],words[1]] = ["bab","dab"].
    /// It can be shown that the length of the longest subsequence of indices 
    /// that satisfies the conditions is 2.  
    ///
    /// Example 2:
    /// Input: n = 4, words = ["a","b","c","d"], groups = [1,2,3,4]
    /// Output: ["a","b","c","d"]
    /// Explanation: We can select the subsequence [0,1,2,3].
    /// It satisfies both conditions.
    /// Hence, the answer is [words[0],words[1],words[2],words[3]] = 
    /// ["a","b","c","d"].
    /// It has the longest length among all subsequences of indices that 
    /// satisfy the conditions.
    /// Hence, it is the only answer.
    ///
    /// Constraints:
    /// 1. 1 <= n == words.length == groups.length <= 1000
    /// 2. 1 <= words[i].length <= 10
    /// 3. 1 <= groups[i] <= n
    /// 4. words consists of distinct strings.
    /// 5. words[i] consists of lowercase English letters.
    /// </summary>
    vector<string> getWordsInLongestSubsequenceII(int n, vector<string>& words, vector<int>& groups);

    /// <summary>
    /// Leet Code 2903. Find Indices With Index and Value Difference I
    /// 
    /// Easy
    /// 
    /// You are given a 0-indexed integer array nums having length n, an 
    /// integer indexDifference, and an integer valueDifference.
    ///
    /// Your task is to find two indices i and j, both in the range 
    /// [0, n - 1], that satisfy the following conditions:
    ///
    /// abs(i - j) >= indexDifference, and
    /// abs(nums[i] - nums[j]) >= valueDifference
    /// Return an integer array answer, where answer = [i, j] if there are 
    /// two such indices, and answer = [-1, -1] otherwise. If there are 
    /// multiple choices for the two indices, return any of them.
    ///
    /// Note: i and j may be equal.
    /// 
    /// Example 1:
    /// Input: nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
    /// Output: [0,3]
    /// Explanation: In this example, i = 0 and j = 3 can be selected.
    /// abs(0 - 3) >= 2 and abs(nums[0] - nums[3]) >= 4.
    /// Hence, a valid answer is [0,3].
    /// [3,0] is also a valid answer.
    ///
    /// Example 2:
    /// Input: nums = [2,1], indexDifference = 0, valueDifference = 0
    /// Output: [0,0]
    /// Explanation: In this example, i = 0 and j = 0 can be selected.
    /// abs(0 - 0) >= 0 and abs(nums[0] - nums[0]) >= 0.
    /// Hence, a valid answer is [0,0].
    /// Other valid answers are [0,1], [1,0], and [1,1].
    ///
    /// Example 3:
    /// Input: nums = [1,2,3], indexDifference = 2, valueDifference = 4
    /// Output: [-1,-1]
    /// Explanation: In this example, it can be shown that it is 
    /// impossible to find two indices that satisfy both conditions.
    /// Hence, [-1,-1] is returned.
    /// 
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 100
    /// 2. 0 <= nums[i] <= 50
    /// 3. 0 <= indexDifference <= 100
    /// 4. 0 <= valueDifference <= 50
    /// </summary>
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference);

    /// <summary>
    /// Leet Code 2906. Construct Product Matrix
    /// 
    /// Medium
    /// Given a 0-indexed 2D integer matrix grid of size n * m, we define a 
    /// 0-indexed 2D matrix p of size n * m as the product matrix of grid if 
    /// the following condition is met:
    ///
    /// Each element p[i][j] is calculated as the product of all elements in 
    /// grid except for the element grid[i][j]. This product is then taken 
    /// modulo 12345.
    /// Return the product matrix of grid.
    /// 
    /// Example 1:
    /// Input: grid = [[1,2],[3,4]]
    /// Output: [[24,12],[8,6]]
    /// Explanation: p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] 
    /// = 2 * 3 * 4 = 24
    /// p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
    /// p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
    /// p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
    /// So the answer is [[24,12],[8,6]].
    ///
    /// Example 2:
    /// Input: grid = [[12345],[2],[1]]
    /// Output: [[2],[0],[0]]
    /// Explanation: p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2.
    /// p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 
    /// 12345 % 12345 = 0. So p[0][1] = 0.
    /// p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 
    /// 24690 % 12345 = 0. So p[0][2] = 0.
    /// So the answer is [[2],[0],[0]].
    ///
    /// Constraints:
    /// 1. 1 <= n == grid.length <= 10^5
    /// 2. 1 <= m == grid[i].length <= 10^5
    /// 3. 2 <= n * m <= 10^5
    /// 4. 1 <= grid[i][j] <= 10^9
    /// </summary>
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2905. Find Indices With Index and Value Difference II
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums having length n, an 
    /// integer indexDifference, and an integer valueDifference.
    ///
    /// Your task is to find two indices i and j, both in the range 
    /// [0, n - 1], that satisfy the following conditions:
    ///
    /// abs(i - j) >= indexDifference, and 
    /// abs(nums[i] - nums[j]) >= valueDifference
    /// Return an integer array answer, where answer = [i, j] if there are 
    /// two such indices, and answer = [-1, -1] otherwise. If there are 
    /// multiple choices for the two indices, return any of them.
    ///
    /// Note: i and j may be equal.
    /// 
    /// Example 1:
    /// Input: nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
    /// Output: [0,3]
    /// Explanation: In this example, i = 0 and j = 3 can be selected.
    /// abs(0 - 3) >= 2 and abs(nums[0] - nums[3]) >= 4.
    /// Hence, a valid answer is [0,3].
    /// [3,0] is also a valid answer.
    ///
    /// Example 2:
    /// Input: nums = [2,1], indexDifference = 0, valueDifference = 0
    /// Output: [0,0]
    /// Explanation: In this example, i = 0 and j = 0 can be selected.
    /// abs(0 - 0) >= 0 and abs(nums[0] - nums[0]) >= 0.
    /// Hence, a valid answer is [0,0].
    /// Other valid answers are [0,1], [1,0], and [1,1].
    ///
    /// Example 3:
    /// Input: nums = [1,2,3], indexDifference = 2, valueDifference = 4
    /// Output: [-1,-1]
    /// Explanation: In this example, it can be shown that it is impossible to 
    /// find two indices that satisfy both conditions.
    /// Hence, [-1,-1] is returned.
    /// 
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// 3. 0 <= indexDifference <= 10^5
    /// 4. 0 <= valueDifference <= 10^9
    /// </summary>
    vector<int> findIndicesII(vector<int>& nums, int indexDifference, int valueDifference);

    /// <summary>
    /// Leet Code 2913. Subarrays Distinct Element Sum of Squares I
    /// 
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums.
    ///
    /// The distinct count of a subarray of nums is defined as:
    /// 
    /// Let nums[i..j] be a subarray of nums consisting of all the indices 
    /// from i to j such that 0 <= i <= j < nums.length. Then the number of 
    /// distinct values in nums[i..j] is called the distinct count of 
    /// nums[i..j].
    /// Return the sum of the squares of distinct counts of all subarrays 
    /// of nums.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    ///
    /// Example 1:
    /// Input: nums = [1,2,1]
    /// Output: 15
    /// Explanation: Six possible subarrays are:
    /// [1]: 1 distinct value
    /// [2]: 1 distinct value
    /// [1]: 1 distinct value
    /// [1,2]: 2 distinct values
    /// [2,1]: 2 distinct values
    /// [1,2,1]: 2 distinct values
    /// The sum of the squares of the distinct counts in all subarrays is 
    /// equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
    ///
    /// Example 2:
    /// Input: nums = [1,1]
    /// Output: 3
    /// Explanation: Three possible subarrays are:
    /// [1]: 1 distinct value
    /// [1]: 1 distinct value
    /// [1,1]: 1 distinct value
    /// The sum of the squares of the distinct counts in all subarrays is 
    /// equal to 12 + 12 + 12 = 3.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// </summary>
    int sumCounts(vector<int>& nums);

    /// <summary>
    /// Leet Code 2914. Minimum Number of Changes to Make Binary String 
    ///                 Beautiful
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed binary string s having an even length.
    ///
    /// A string is beautiful if it's possible to partition it into one 
    /// or more substrings such that:
    ///
    /// Each substring has an even length.
    /// Each substring contains only 1's or only 0's.
    /// You can change any character in s to 0 or 1.
    ///
    /// Return the minimum number of changes required to make the string s 
    /// beautiful.
    ///
    /// Example 1:
    /// Input: s = "1001"
    /// Output: 2
    /// Explanation: We change s[1] to 1 and s[3] to 0 to get string "1100".
    /// It can be seen that the string "1100" is beautiful because we can 
    /// partition it into "11|00".
    /// It can be proven that 2 is the minimum number of changes needed to 
    /// make the string beautiful.
    ///
    /// Example 2:
    /// Input: s = "10"
    /// Output: 1
    /// Explanation: We change s[1] to 1 to get string "11".
    /// It can be seen that the string "11" is beautiful because we can 
    /// partition it into "11".
    /// It can be proven that 1 is the minimum number of changes needed to 
    /// make the string beautiful.
    ///
    /// Example 3:
    /// Input: s = "0000"
    /// Output: 0
    /// Explanation: We don't need to make any changes as the string "0000" 
    /// is beautiful already.
    ///  
    /// Constraints:
    /// 1. 2 <= s.length <= 10^5
    /// 2. s has an even length.
    /// 3. s[i] is either '0' or '1'.
    /// </summary>
    int minChanges(string s);

    /// <summary>
    /// Leet Code 2923. Find Champion I
    ///  
    /// Easy
    ///
    /// There are n teams numbered from 0 to n - 1 in a tournament.
    ///
    /// Given a 0-indexed 2D boolean matrix grid of size n * n. For all i, j 
    /// that 0 <= i, j <= n - 1 and i != j team i is stronger than team j if 
    /// grid[i][j] == 1, otherwise, team j is stronger than team i.
    ///
    /// Team a will be the champion of the tournament if there is no team b 
    /// that is stronger than team a.
    ///
    /// Return the team that will be the champion of the tournament.
    ///
    /// Example 1:
    /// Input: grid = [[0,1],[0,0]]
    /// Output: 0
    /// Explanation: There are two teams in this tournament.
    /// grid[0][1] == 1 means that team 0 is stronger than team 1. So team 0 
    /// will be the champion.
    ///
    /// Example 2:
    /// Input: grid = [[0,0,1],[1,0,1],[0,0,0]]
    /// Output: 1
    /// Explanation: There are three teams in this tournament.
    /// grid[1][0] == 1 means that team 1 is stronger than team 0.
    /// grid[1][2] == 1 means that team 1 is stronger than team 2.
    /// So team 1 will be the champion.
    ///
    /// Constraints:
    /// 1. n == grid.length
    /// 2. n == grid[i].length
    /// 3. 2 <= n <= 100
    /// 4. grid[i][j] is either 0 or 1.
    /// 5. For all i, j that i != j, grid[i][j] != grid[j][i].
    /// 6. The input is generated such that if team a is stronger than team b 
    ///    and team b is stronger than team c, then team a is stronger than 
    ///    team c.
    /// </summary>
    int findChampion(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2934. Minimum Operations to Maximize Last Elements in Arrays
    ///  
    /// Medium
    ///
    /// You are given two 0-indexed integer arrays, nums1 and nums2, both 
    /// having length n.
    /// 
    /// You are allowed to perform a series of operations (possibly none).
    ///
    /// In an operation, you select an index i in the range [0, n - 1] and 
    /// swap the values of nums1[i] and nums2[i].
    ///
    /// Your task is to find the minimum number of operations required to 
    /// satisfy the following conditions:
    ///
    /// nums1[n - 1] is equal to the maximum value among all elements of 
    /// nums1, i.e., nums1[n - 1] = max(nums1[0], nums1[1], ..., nums1[n - 1]).
    /// nums2[n - 1] is equal to the maximum value among all elements of 
    /// nums2, i.e., nums2[n - 1] = max(nums2[0], nums2[1], ..., nums2[n - 1]).
    /// Return an integer denoting the minimum number of operations needed to 
    /// meet both conditions, or -1 if it is impossible to satisfy both 
    /// conditions.
    /// 
    /// Example 1:
    /// Input: nums1 = [1,2,7], nums2 = [4,5,3]
    /// Output: 1
    /// Explanation: In this example, an operation can be performed using 
    /// index i = 2.
    /// When nums1[2] and nums2[2] are swapped, nums1 becomes [1,2,3] and 
    /// nums2 becomes [4,5,7].
    /// Both conditions are now satisfied.
    /// It can be shown that the minimum number of operations needed to be 
    /// performed is 1.
    /// So, the answer is 1.
    ///
    /// Example 2:
    /// Input: nums1 = [2,3,4,5,9], nums2 = [8,8,4,4,4]
    /// Output: 2
    /// Explanation: In this example, the following operations can be 
    /// performed:
    /// First operation using index i = 4.
    /// When nums1[4] and nums2[4] are swapped, nums1 becomes [2,3,4,5,4], and 
    /// nums2 becomes [8,8,4,4,9].
    /// Another operation using index i = 3.
    /// When nums1[3] and nums2[3] are swapped, nums1 becomes [2,3,4,4,4], and 
    /// nums2 becomes [8,8,4,5,9].
    /// Both conditions are now satisfied.
    /// It can be shown that the minimum number of operations needed to be 
    /// performed is 2.
    /// So, the answer is 2.   
    ///
    /// Example 3:
    /// Input: nums1 = [1,5,4], nums2 = [2,5,3]
    /// Output: -1
    /// Explanation: In this example, it is not possible to satisfy both 
    /// conditions. 
    /// So, the answer is -1.
    ///
    /// Constraints:
    /// 1. 1 <= n == nums1.length == nums2.length <= 1000
    /// 2. 1 <= nums1[i] <= 10^9
    /// 3. 1 <= nums2[i] <= 10^9
    /// </summary>
    int minOperationsSwap(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2938. Separate Black and White Balls
    ///  
    /// Medium
    ///
    /// There are n balls on a table, each ball has a color black or white.
    ///
    /// You are given a 0-indexed binary string s of length n, where 1 and 0 
    /// represent black and white balls, respectively.
    ///
    /// In each step, you can choose two adjacent balls and swap them.
    ///
    /// Return the minimum number of steps to group all the black balls to the 
    /// right and all the white balls to the left.
    /// 
    /// Example 1:
    /// Input: s = "101"
    /// Output: 1
    /// Explanation: We can group all the black balls to the right in the 
    /// following way:
    /// - Swap s[0] and s[1], s = "011".
    /// Initially, 1s are not grouped together, requiring at least 1 step to 
    /// group them to the right.
    ///
    /// Example 2:
    /// Input: s = "100"
    /// Output: 2
    /// Explanation: We can group all the black balls to the right in the 
    /// following way:
    /// - Swap s[0] and s[1], s = "010".
    /// - Swap s[1] and s[2], s = "001".
    /// It can be proven that the minimum number of steps needed is 2.
    ///
    /// Example 3:
    /// Input: s = "0111"
    /// Output: 0
    /// Explanation: All the black balls are already grouped to the right.
    /// 
    /// Constraints:
    /// 1. 1 <= n == s.length <= 10^5
    /// 2. s[i] is either '0' or '1'.
    /// </summary>
    long long minimumSteps(string s);

    /// <summary>
    /// Leet Code 2946. Matrix Similarity After Cyclic Shifts
    ///  
    /// Easy
    ///
    /// You are given a 0-indexed m x n integer matrix mat and an integer k. You 
    /// have to cyclically right shift odd indexed rows k times and cyclically 
    /// left shift even indexed rows k times.
    ///
    /// Return true if the initial and final matrix are exactly the same and false 
    /// otherwise.
    /// 
    /// Example 1:
    /// Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
    /// Output: true
    /// Explanation:
    /// Initially, the matrix looks like the first figure. 
    /// Second figure represents the state of the matrix after one right and left 
    /// cyclic shifts to even and odd indexed rows.
    /// Third figure is the final state of the matrix after two cyclic shifts 
    /// which is similar to the initial matrix.
    /// Therefore, return true.
    ///
    /// Example 2:
    /// Input: mat = [[2,2],[2,2]], k = 3
    /// Output: true
    /// Explanation: As all the values are equal in the matrix, even after 
    /// performing cyclic shifts the matrix will remain the same. Therefeore, 
    /// we return true.
    ///
    /// Example 3:
    /// Input: mat = [[1,2]], k = 1
    /// Output: false
    /// Explanation: After one cyclic shift, mat = [[2,1]] which is not equal 
    /// to the initial matrix. Therefore we return false.
    /// 
    /// Constraints:
    /// 1. 1 <= mat.length <= 25
    /// 2. 1 <= mat[i].length <= 25
    /// 3. 1 <= mat[i][j] <= 25
    /// 4. 1 <= k <= 50
    /// </summary>
    bool areSimilar(vector<vector<int>>& mat, int k);

    /// <summary>
    /// Leet Code 2945. Find Maximum Non-decreasing Array Length
    ///  
    /// Hard
    ///
    /// You are given a 0-indexed integer array nums.
    ///
    /// You can perform any number of operations, where each operation involves 
    /// selecting a subarray of the array and replacing it with the sum of its 
    /// elements. For example, if the given array is [1,3,5,6] and you select 
    /// subarray [3,5] the array will convert to [1,8,6].
    ///
    /// Return the maximum length of a non-decreasing array that can be made after 
    /// applying operations.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an array.
    ///
    /// Example 1:
    /// Input: nums = [5,2,2]
    /// Output: 1
    /// Explanation: This array with length 3 is not non-decreasing.
    /// We have two ways to make the array length two.
    /// First, choosing subarray [2,2] converts the array to [5,4].
    /// Second, choosing subarray [5,2] converts the array to [7,2].
    /// In these two ways the array is not non-decreasing.
    /// And if we choose subarray [5,2,2] and replace it with [9] it becomes 
    /// non-decreasing. 
    /// So the answer is 1.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4]
    /// Output: 4
    /// Explanation: The array is non-decreasing. So the answer is 4.
    ///
    /// Example 3:
    /// Input: nums = [4,3,2,6]
    /// Output: 3
    /// Explanation: Replacing [3,2] with [5] converts the given array to [4,5,6] 
    /// that is non-decreasing.
    /// Because the given array is not non-decreasing, the maximum possible 
    /// answer is 3.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int findMaximumLength(vector<int>& nums);

    /// <summary>
    /// Leet Code 2950. Number of Divisible Substrings
    ///  
    /// Medium
    ///
    /// Each character of the English alphabet has been mapped to a digit as shown 
    /// below.
    ///
    /// A string is divisible if the sum of the mapped values of its characters is 
    /// divisible by its length.
    ///
    /// Given a string s, return the number of divisible substrings of s.
    ///
    /// A substring is a contiguous non-empty sequence of characters within a string.
    ///
    /// Example 1:
    /// Substring   Mapped  Sum Length  Divisible?
    /// a   1   1   1   Yes
    /// s   7   7   1   Yes
    /// d   2   2   1   Yes
    /// f   3   3   1   Yes
    /// as  1,  7   8   2   Yes
    /// sd  7, 2    9   2   No
    /// df  2, 3    5   2   No
    /// asd 1, 7, 2 10  3   No
    /// sdf 7, 2, 3 12  3   Yes
    /// asdf    1, 7, 2, 3  13  4   No
    /// Input: word = "asdf"
    /// Output: 6
    /// Explanation: The table above contains the details about every substring of 
    /// word, and we can see that 6 of them are divisible.
    ///
    /// Example 2:
    /// Input: word = "bdh"
    /// Output: 4
    /// Explanation: The 4 divisible substrings are: "b", "d", "h", "bdh".
    /// It can be shown that there are no other substrings of word that are 
    /// divisible.
    ///
    /// Example 3:
    /// Input: word = "abcd"
    /// Output: 6
    /// Explanation: The 6 divisible substrings are: "a", "b", "c", "d", "ab", 
    /// "cd".
    /// It can be shown that there are no other substrings of word that are 
    /// divisible.
    /// 
    /// Constraints:
    /// 1. 1 <= word.length <= 2000
    /// </summary>
    int countDivisibleSubstrings(string word);

    /// <summary>
    /// Leet Code 2947. Count Beautiful Substrings I
    ///  
    /// Medium
    ///
    /// You are given a string s and a positive integer k.
    ///
    /// Let vowels and consonants be the number of vowels and consonants in a 
    /// string.
    ///
    /// A string is beautiful if:
    ///
    /// vowels == consonants.
    /// (vowels * consonants) % k == 0, in other terms the multiplication of 
    /// vowels and consonants is divisible by k.
    /// Return the number of non-empty beautiful substrings in the given string s.
    ///
    /// A substring is a contiguous sequence of characters in a string.
    /// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
    /// Consonant letters in English are every letter except vowels.
    ///
    /// Example 1:
    /// Input: s = "baeyh", k = 2
    /// Output: 2
    /// Explanation: There are 2 beautiful substrings in the given string.
    /// - Substring "baeyh", vowels = 2 (["a",e"]), consonants = 2 (["y","h"]).
    /// You can see that string "aeyh" is beautiful as vowels == consonants and 
    /// vowels * consonants % k == 0.
    /// - Substring "baeyh", vowels = 2 (["a",e"]), consonants = 2 (["b","y"]). 
    /// You can see that string "baey" is beautiful as vowels == consonants and 
    /// vowels * consonants % k == 0.
    /// It can be shown that there are only 2 beautiful substrings in the given 
    /// string.
    ///
    /// Example 2:
    /// Input: s = "abba", k = 1
    /// Output: 3
    /// Explanation: There are 3 beautiful substrings in the given string.
    /// - Substring "abba", vowels = 1 (["a"]), consonants = 1 (["b"]). 
    /// - Substring "abba", vowels = 1 (["a"]), consonants = 1 (["b"]).
    /// - Substring "abba", vowels = 2 (["a","a"]), consonants = 2 (["b","b"]).
    /// It can be shown that there are only 3 beautiful substrings in the given 
    /// string.
    ///
    /// Example 3:
    /// Input: s = "bcdf", k = 1
    /// Output: 0
    /// Explanation: There are no beautiful substrings in the given string.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 1000
    /// 2. 1 <= k <= 1000
    /// 3. s consists of only English lowercase letters.
    /// </summary>
    int beautifulSubstrings(string s, int k);

    /// <summary>
    /// Leet Code 2949. Count Beautiful Substrings II
    ///  
    /// Hard
    ///
    /// You are given a string s and a positive integer k.
    /// 
    /// Let vowels and consonants be the number of vowels and consonants in a 
    /// string.
    ///
    /// A string is beautiful if:
    ///
    /// vowels == consonants.
    /// (vowels * consonants) % k == 0, in other terms the multiplication of 
    /// vowels and consonants is divisible by k.
    /// Return the number of non-empty beautiful substrings in the given string s.
    ///
    /// A substring is a contiguous sequence of characters in a string.
    ///
    /// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
    ///
    /// Consonant letters in English are every letter except vowels.
    /// 
    /// Example 1:
    ///
    /// Input: s = "baeyh", k = 2
    /// Output: 2
    /// Explanation: There are 2 beautiful substrings in the given string.
    /// - Substring "baeyh", vowels = 2 (["a",e"]), consonants = 2 (["y","h"]).
    /// You can see that string "aeyh" is beautiful as vowels == consonants and 
    /// vowels * consonants % k == 0.
    /// - Substring "baeyh", vowels = 2 (["a",e"]), consonants = 2 (["b","y"]).
    /// You can see that string "baey" is beautiful as vowels == consonants and 
    /// vowels * consonants % k == 0.
    /// It can be shown that there are only 2 beautiful substrings in the given 
    /// string.
    ///
    /// Example 2:
    /// Input: s = "abba", k = 1
    /// Output: 3
    /// Explanation: There are 3 beautiful substrings in the given string.
    /// - Substring "abba", vowels = 1 (["a"]), consonants = 1 (["b"]).
    /// - Substring "abba", vowels = 1 (["a"]), consonants = 1 (["b"]).
    /// - Substring "abba", vowels = 2 (["a","a"]), consonants = 2 (["b","b"]).
    /// It can be shown that there are only 3 beautiful substrings in the given 
    /// string.
    ///
    /// Example 3:
    /// Input: s = "bcdf", k = 1
    /// Output: 0
    /// Explanation: There are no beautiful substrings in the given string.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 5 * 10^4
    /// 2. 1 <= k <= 1000
    /// 3. s consists of only English lowercase letters.
    /// </summary>
    long long beautifulSubstringsII(string s, int k);

    /// <summary>
    /// Leet Code 2951. Find the Peaks
    ///  
    /// Easy
    /// You are given a 0-indexed array mountain. Your task is to find all the 
    /// peaks in the mountain array.
    ///
    /// Return an array that consists of indices of peaks in the given array in 
    /// any order.
    ///
    /// Notes:
    ///
    /// A peak is defined as an element that is strictly greater than its 
    /// neighboring elements.
    /// The first and last elements of the array are not a peak.
    /// 
    /// Example 1:
    /// Input: mountain = [2,4,4]
    /// Output: []
    /// Explanation: mountain[0] and mountain[2] can not be a peak because they 
    /// are first and last elements of the array.
    /// mountain[1] also can not be a peak because it is not strictly greater than 
    /// mountain[2].
    /// So the answer is [].
    ///
    /// Example 2:
    /// Input: mountain = [1,4,3,8,5]
    /// Output: [1,3]
    /// Explanation: mountain[0] and mountain[4] can not be a peak because they 
    /// are first and last elements of the array.
    /// mountain[2] also can not be a peak because it is not strictly greater 
    /// than mountain[3] and mountain[1].
    /// But mountain [1] and mountain[3] are strictly greater than their 
    /// neighboring elements.
    /// So the answer is [1,3].
    /// 
    /// Constraints:
    /// 1. 3 <= mountain.length <= 100
    /// 2. 1 <= mountain[i] <= 100
    /// </summary>
    vector<int> findPeaks(vector<int>& mountain);

    /// <summary>
    /// Leet Code 2955. Number of Same-End Substrings
    ///  
    /// Medium
    ///
    /// You are given a 0-indexed string s, and a 2D array of integers queries, 
    /// where queries[i] = [li, ri] indicates a substring of s starting from the 
    /// index li and ending at the index ri (both inclusive), i.e. s[li..ri].
    ///
    /// Return an array ans where ans[i] is the number of same-end substrings 
    /// of queries[i].
    ///
    /// A 0-indexed string t of length n is called same-end if it has the same 
    /// character at both of its ends, i.e., t[0] == t[n - 1].
    ///
    /// A substring is a contiguous non-empty sequence of characters within a 
    /// string.
    ///
    /// Example 1:
    /// Input: s = "abcaab", queries = [[0,0],[1,4],[2,5],[0,5]]
    /// Output: [1,5,5,10]
    /// Explanation: Here is the same-end substrings of each query:
    /// 1st query: s[0..0] is "a" which has 1 same-end substring: "a".
    /// 2nd query: s[1..4] is "bcaa" which has 5 same-end substrings: "bcaa", 
    /// "bcaa", "bcaa", "bcaa", "bcaa".
    /// 3rd query: s[2..5] is "caab" which has 5 same-end substrings: "caab", 
    /// "caab", "caab", "caab", "caab".
    /// 4th query: s[0..5] is "abcaab" which has 10 same-end substrings: "abcaab", 
    /// "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", 
    /// "abcaab", "abcaab".
    ///
    /// Example 2:
    /// Input: s = "abcd", queries = [[0,3]]
    /// Output: [4]
    /// Explanation: The only query is s[0..3] which is "abcd". It has 4 same-
    /// end substrings: "abcd", "abcd", "abcd", "abcd".
    /// 
    /// Constraints:
    /// 1. 2 <= s.length <= 3 * 10^4
    /// 2. s consists only of lowercase English letters.
    /// 3. 1 <= queries.length <= 3 * 10^4
    /// 4. queries[i] = [li, ri]
    /// 5. 0 <= li <= ri < s.length
    /// </summary>
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2960. Count Tested Devices After Test Operations
    ///  
    /// Hard
    ///
    /// You are given a 0-indexed integer array batteryPercentages having length 
    /// n, denoting the battery percentages of n 0-indexed devices.
    ///
    /// Your task is to test each device i in order from 0 to n - 1, by performing 
    /// the following test operations:
    ///
    /// If batteryPercentages[i] is greater than 0:
    /// Increment the count of tested devices.
    /// Decrease the battery percentage of all devices with indices j in the 
    /// range [i + 1, n - 1] by 1, ensuring their battery percentage never goes 
    /// below 0, i.e, batteryPercentages[j] = max(0, batteryPercentages[j] - 1).
    /// Move to the next device.
    // Otherwise, move to the next device without performing any test.
    /// Return an integer denoting the number of devices that will be tested after 
    /// performing the test operations in order.
    /// 
    /// Example 1:
    /// Input: batteryPercentages = [1,1,2,1,3]
    /// Output: 3
    /// Explanation: Performing the test operations in order starting from 
    /// device 0:
    /// At device 0, batteryPercentages[0] > 0, so there is now 1 tested device, 
    /// and batteryPercentages becomes [1,0,1,0,2].
    /// At device 1, batteryPercentages[1] == 0, so we move to the next device 
    /// without testing.
    /// At device 2, batteryPercentages[2] > 0, so there are now 2 tested devices, 
    /// and batteryPercentages becomes [1,0,1,0,1].
    /// At device 3, batteryPercentages[3] == 0, so we move to the next device 
    /// without testing.
    /// At device 4, batteryPercentages[4] > 0, so there are now 3 tested devices, 
    /// and batteryPercentages stays the same.
    /// So, the answer is 3.
    ///
    /// Example 2:
    /// Input: batteryPercentages = [0,1,2]
    /// Output: 2
    /// Explanation: Performing the test operations in order starting from 
    /// device 0:
    /// At device 0, batteryPercentages[0] == 0, so we move to the next device 
    /// without testing.
    /// At device 1, batteryPercentages[1] > 0, so there is now 1 tested device, 
    /// and batteryPercentages becomes [0,1,1].
    /// At device 2, batteryPercentages[2] > 0, so there are now 2 tested 
    /// devices, and batteryPercentages stays the same.
    /// So, the answer is 2.
    /// 
    /// Constraints:
    /// 1. 1 <= n == batteryPercentages.length <= 100 
    /// 2. 0 <= batteryPercentages[i] <= 100
    /// </summary>
    int countTestedDevices(vector<int>& batteryPercentages);

    /// <summary>
    /// Leet Code 2962. Count Subarrays Where Max Element Appears at Least K Times
    ///  
    /// Medium
    ///
    /// You are given an integer array nums and a positive integer k.
    ///
    /// Return the number of subarrays where the maximum element of nums appears 
    /// at least k times in that subarray.
    ///
    /// A subarray is a contiguous sequence of elements within an array.
    /// 
    /// Example 1:
    /// Input: nums = [1,3,2,3,3], k = 2
    /// Output: 6
    /// Explanation: The subarrays that contain the element 3 at least 2 times 
    /// are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
    ///
    /// Example 2:
    /// Input: nums = [1,4,2,1], k = 3
    /// Output: 0
    /// Explanation: No subarray contains the element 4 at least 3 times.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// 3. 1 <= k <= 10^5
    /// </summary>
    long long countSubarraysMaxValue(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2963. Count the Number of Good Partitions
    ///  
    /// Hard
    ///
    /// You are given a 0-indexed array nums consisting of positive integers.
    /// 
    /// A partition of an array into one or more contiguous subarrays is called 
    /// good if no two subarrays contain the same number.
    ///
    /// Return the total number of good partitions of nums.
    ///
    /// Since the answer may be large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,4]
    /// Output: 8
    /// Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), 
    /// ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), 
    /// ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
    ///
    /// Example 2:
    /// Input: nums = [1,1,1,1]
    /// Output: 1
    /// Explanation: The only possible good partition is: ([1,1,1,1]).
    ///
    /// Example 3:
    /// Input: nums = [1,2,1,3]
    /// Output: 2
    /// Explanation: The 2 possible good partitions are: ([1,2,1], [3]) 
    /// and ([1,2,1,3]).
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    int numberOfGoodPartitions(vector<int>& nums);

    /// <summary>
    /// Leet Code 2965. Find Missing and Repeated Values
    ///  
    /// Easy
    ///
    /// You are given a 0-indexed 2D integer matrix grid of size n * n with values 
    /// in the range [1, n^2]. Each integer appears exactly once except a which 
    /// appears twice and b which is missing. The task is to find the repeating 
    /// and missing numbers a and b.
    ///
    /// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a 
    /// and ans[1] equals to b.
    ///
    /// Example 1:
    /// Input: grid = [[1,3],[2,2]]
    /// Output: [2,4]
    /// Explanation: Number 2 is repeated and number 4 is missing so the answer 
    /// is [2,4].
    ///
    /// Example 2:
    /// Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
    /// Output: [9,5]
    /// Explanation: Number 9 is repeated and number 5 is missing so the answer 
    /// is [9,5].
    /// 
    /// Constraints:
    /// 1. 2 <= n == grid.length == grid[i].length <= 50
    /// 2. 1 <= grid[i][j] <= n * n
    /// 3. For all x that 1 <= x <= n * n there is exactly one x that is not equal 
    ///    to any of the grid members.
    /// 4. For all x that 1 <= x <= n * n there is exactly one x that is equal to 
    ///    exactly two of the grid members.
    /// 5. For all x that 1 <= x <= n * n except two of them there is exatly one 
    ///    pair of i, j that 0 <= i, j <= n - 1 and grid[i][j] == x.
    /// </summary>
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid);

    /// <summary>
    /// Leet Code 2966. Divide Array Into Arrays With Max Difference
    ///  
    /// Medium
    ///
    /// You are given an integer array nums of size n and a positive integer k.
    /// Divide the array into one or more arrays of size 3 satisfying the 
    /// following conditions:
    ///
    /// Each element of nums should be in exactly one array.
    /// The difference between any two elements in one array is less than or 
    /// equal to k.
    /// Return a 2D array containing all the arrays. If it is impossible to 
    /// satisfy the conditions, return an empty array. And if there are multiple 
    /// answers, return any of them.
    /// 
    /// Example 1:
    /// Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
    /// Output: [[1,1,3],[3,4,5],[7,8,9]]
    /// Explanation: We can divide the array into the following arrays: [1,1,3], 
    /// [3,4,5] and [7,8,9].
    /// The difference between any two elements in each array is less than or 
    /// equal to 2.
    /// Note that the order of elements is not important.
    ///
    /// Example 2:
    /// Input: nums = [1,3,3,2,7,3], k = 3
    /// Output: []
    /// Explanation: It is not possible to divide the array satisfying all the 
    /// conditions.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^5
    /// 3. n is a multiple of 3.
    /// 4. 1 <= nums[i] <= 10^5
    /// 5. 1 <= k <= 10^5
    /// </summary>
    vector<vector<int>> divideArray(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2971. Find Polygon With the Largest Perimeter
    ///  
    /// Medium
    ///
    /// You are given an array of positive integers nums of length n.
    ///
    /// A polygon is a closed plane figure that has at least 3 sides. The longest 
    /// side of a polygon is smaller than the sum of its other sides.
    ///
    /// Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., 
    /// ak where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak, 
    /// then there always exists a polygon with k sides whose lengths are a1, a2, 
    /// a3, ..., ak.
    ///
    /// The perimeter of a polygon is the sum of lengths of its sides.
    ///
    /// Return the largest possible perimeter of a polygon whose sides can be 
    /// formed from nums, or -1 if it is not possible to create a polygon.
    ///
    /// Example 1:
    /// Input: nums = [5,5,5]
    /// Output: 15
    /// Explanation: The only possible polygon that can be made from nums has 3 
    /// sides: 5, 5, and 5. The perimeter is 5 + 5 + 5 = 15.
    ///
    /// Example 2:
    /// Input: nums = [1,12,1,2,5,50,3]
    /// Output: 12
    /// Explanation: The polygon with the largest perimeter which can be made from 
    /// nums has 5 sides: 1, 1, 2, 3, and 5. The perimeter 
    /// is 1 + 1 + 2 + 3 + 5 = 12.
    /// We cannot have a polygon with either 12 or 50 as the longest side because 
    /// it is not possible to include 2 or more smaller sides that have a greater 
    /// sum than either of them.
    /// It can be shown that the largest possible perimeter is 12.
    ///
    /// Example 3:
    /// Input: nums = [5,5,50]
    /// Output: -1
    /// Explanation: There is no possible way to form a polygon from nums, as a 
    /// polygon has at least 3 sides and 50 > 5 + 5.
    /// 
    /// Constraints:
    /// 1. 3 <= n <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    long long largestPerimeter(vector<int>& nums);

    /// <summary>
    /// Leet Code 2974. Minimum Number Game
    ///  
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums of even length and there is 
    /// also an empty array arr. Alice and Bob decided to play a game where in 
    /// every round Alice and Bob will do one move. The rules of the game are as 
    /// follows:
    ///
    /// Every round, first Alice will remove the minimum element from nums, and 
    /// then Bob does the same.
    /// Now, first Bob will append the removed element in the array arr, and then 
    /// Alice does the same.
    /// The game continues until nums becomes empty.
    /// Return the resulting array arr.
    ///
    ///
    /// Example 1:
    /// Input: nums = [5,4,2,3]
    /// Output: [3,2,5,4]
    /// Explanation: In round one, first Alice removes 2 and then Bob removes 3. 
    /// Then in arr firstly Bob appends 3 and then Alice appends 2. So arr = [3,2].
    /// At the begining of round two, nums = [5,4]. Now, first Alice removes 4 and 
    /// then Bob removes 5. Then both append in arr which becomes [3,2,5,4].
    ///
    /// Example 2:
    /// Input: nums = [2,5]
    /// Output: [5,2]
    /// Explanation: In round one, first Alice removes 2 and then Bob removes 5. 
    /// Then in arr firstly Bob appends and then Alice appends. So arr = [5,2].
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// 3. nums.length % 2 == 0
    /// </summary>
    vector<int> numberGame(vector<int>& nums);

    /// <summary>
    /// Leet Code 2975. Maximum Square Area by Removing Fences From a Field
    ///  
    /// Medium
    ///
    /// There is a large (m - 1) x (n - 1) rectangular field with corners 
    /// at (1, 1) and (m, n) containing some horizontal and vertical fences 
    /// given in arrays hFences and vFences respectively.
    ///
    /// Horizontal fences are from the coordinates (hFences[i], 1) to 
    /// (hFences[i], n) and vertical fences are from the coordinates 
    /// (1, vFences[i]) to (m, vFences[i]).
    ///
    /// Return the maximum area of a square field that can be formed by 
    /// removing some fences (possibly none) or -1 if it is impossible to make 
    /// a square field.
    ///
    /// Since the answer may be large, return it modulo 10^9 + 7.
    ///
    /// Note: The field is surrounded by two horizontal fences from the 
    /// coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences 
    /// from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences 
    /// cannot be removed.
    /// 
    /// Example 1:
    /// Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
    /// Output: 4
    /// Explanation: Removing the horizontal fence at 2 and the vertical fence 
    /// at 2 will give a square field of area 4.
    ///
    /// Example 2:
    /// Input: m = 6, n = 7, hFences = [2], vFences = [4]
    /// Output: -1
    /// Explanation: It can be proved that there is no way to create a square 
    /// field by removing fences.
    /// 
    /// Constraints:
    /// 1. 3 <= m, n <= 10^9
    /// 2. 1 <= hFences.length, vFences.length <= 600
    /// 3. 1 < hFences[i] < m
    /// 4. 1 < vFences[i] < n
    /// 5. hFences and vFences are unique.
    /// </summary>
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences);

    /// <summary>
    /// Leet Code 2981. Find Longest Special Substring That Occurs Thrice I
    ///  
    /// Medium
    ///
    /// You are given a string s that consists of lowercase English letters.
    ///
    /// A string is called special if it is made up of only a single character. 
    /// For example, the string "abc" is not special, whereas the strings "ddd", 
    /// "zz", and "f" are special.
    ///
    /// Return the length of the longest special substring of s which occurs 
    /// at least thrice, or -1 if no special substring occurs at least thrice.
    ///
    /// A substring is a contiguous non-empty sequence of characters within a 
    /// string.
    /// 
    /// Example 1:
    /// Input: s = "aaaa"
    /// Output: 2
    /// Explanation: The longest special substring which occurs thrice is "aa": 
    /// substrings "aaaa", "aaaa", and "aaaa".
    /// It can be shown that the maximum length achievable is 2.
    ///
    /// Example 2:
    /// Input: s = "abcdef"
    /// Output: -1
    /// Explanation: There exists no special substring which occurs at least 
    /// thrice. Hence return -1.
    ///
    /// Example 3:
    /// Input: s = "abcaba"
    /// Output: 1
    /// Explanation: The longest special substring which occurs thrice is 
    /// "a": substrings "abcaba", "abcaba", and "abcaba".
    /// It can be shown that the maximum length achievable is 1.
    /// 
    /// Constraints:
    /// 1. 3 <= s.length <= 50
    /// 2. s consists of only lowercase English letters.
    /// </summary>
    int maximumLength(string s);

    /// <summary>
    /// Leet Code 2982. Find Longest Special Substring That Occurs Thrice II
    ///  
    /// Medium
    ///
    /// You are given a string s that consists of lowercase English letters.
    ///
    /// A string is called special if it is made up of only a single character. 
    /// For example, the string "abc" is not special, whereas the strings "ddd", 
    /// "zz", and "f" are special.
    ///
    /// Return the length of the longest special substring of s which occurs at 
    /// least thrice, or -1 if no special substring occurs at least thrice.
    ///
    /// A substring is a contiguous non-empty sequence of characters within a 
    /// string.
    /// 
    /// Example 1:
    /// Input: s = "aaaa"
    /// Output: 2
    /// Explanation: The longest special substring which occurs thrice is "aa": 
    /// substrings "aaaa", "aaaa", and "aaaa".
    /// It can be shown that the maximum length achievable is 2.
    ///
    /// Example 2:
    /// Input: s = "abcdef"
    /// Output: -1
    /// Explanation: There exists no special substring which occurs at least 
    /// thrice. Hence return -1.
    ///
    /// Example 3:
    /// Input: s = "abcaba"
    /// Output: 1
    /// Explanation: The longest special substring which occurs thrice is 
    /// "a": substrings "abcaba", "abcaba", and "abcaba".
    /// It can be shown that the maximum length achievable is 1.
    ///  
    /// Constraints:
    /// 1. 3 <= s.length <= 5 * 10^5
    /// 2. s consists of only lowercase English letters.
    /// </summary>
    int maximumLengthII(string s);

    /// <summary>
    /// Leet Code 2996. Smallest Missing Integer Greater Than Sequential 
    ///                 Prefix Sum
    /// 
    /// Easy
    ///
    /// You are given a 0-indexed array of integers nums.
    ///
    /// A prefix nums[0..i] is sequential if, for all 1 <= j <= i, 
    /// nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only 
    /// of nums[0] is sequential.
    ///
    /// Return the smallest integer x missing from nums such that x is greater 
    /// than or equal to the sum of the longest sequential prefix.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3,2,5]
    /// Output: 6
    /// Explanation: The longest sequential prefix of nums is [1,2,3] with a 
    /// sum of 6. 6 is not in the array, therefore 6 is the smallest missing 
    /// integer greater than or equal to the sum of the longest sequential 
    /// prefix.
    ///
    /// Example 2:
    /// Input: nums = [3,4,5,1,12,14,13]
    /// Output: 15
    /// Explanation: The longest sequential prefix of nums is [3,4,5] with 
    /// a sum of 12. 12, 13, and 14 belong to the array while 15 does not. 
    /// Therefore 15 is the smallest missing integer greater than or equal 
    /// to the sum of the longest sequential prefix.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 50
    /// 2. 1 <= nums[i] <= 50
    /// </summary>
    int missingInteger(vector<int>& nums);

    /// <summary>
    /// Leet Code 3010. Divide an Array Into Subarrays With Minimum Cost I
    ///                 
    /// Easy
    /// 
    /// You are given an array of integers nums of length n.
    /// The cost of an array is the value of its first element. For example, the 
    /// cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
    ///
    /// You need to divide nums into 3 disjoint contiguous subarrays
    /// 
    /// Return the minimum possible sum of the cost of these subarrays.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,12]
    /// Output: 6
    /// Explanation: The best possible way to form 3 subarrays is: [1], [2], 
    /// and [3,12] at a total cost of 1 + 2 + 3 = 6.
    /// The other possible ways to form 3 subarrays are:
    /// - [1], [2,3], and [12] at a total cost of 1 + 2 + 12 = 15.
    /// - [1,2], [3], and [12] at a total cost of 1 + 3 + 12 = 16.
    ///
    /// Example 2:
    /// Input: nums = [5,4,3]
    /// Output: 12
    /// Explanation: The best possible way to form 3 subarrays is: [5], [4], 
    /// and [3] at a total cost of 5 + 4 + 3 = 12.
    /// It can be shown that 12 is the minimum cost achievable.
    ///
    /// Example 3:
    /// Input: nums = [10,3,1,1]
    /// Output: 12
    /// Explanation: The best possible way to form 3 subarrays is: [10,3], 
    /// [1], and [1] at a total cost of 10 + 1 + 1 = 12.
    /// It can be shown that 12 is the minimum cost achievable.
    /// 
    /// Constraints:
    /// 1. 3 <= n <= 50
    /// 2. 1 <= nums[i] <= 50
    /// </summary>
    int minimumCostI(vector<int>& nums);


    /// <summary>
    /// Leet Code 3026. Maximum Good Subarray Sum
    ///
    /// Medium
    ///
    /// You are given an array nums of length n and a positive integer k.
    /// A subarray of nums is called good if the absolute difference between 
    /// its first and last element is exactly k, in other words, the subarray 
    /// nums[i..j] is good if |nums[i] - nums[j]| == k.
    ///
    /// Return the maximum sum of a good subarray of nums. If there are no 
    /// good subarrays, return 0.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,4,5,6], k = 1
    /// Output: 11
    /// Explanation: The absolute difference between the first and last 
    /// element must be 1 for a good subarray. All the good subarrays 
    /// are: [1,2], [2,3], [3,4], [4,5], and [5,6]. The maximum subarray 
    /// sum is 11 for the subarray [5,6].
    ///
    /// Example 2:
    /// Input: nums = [-1,3,2,4,5], k = 3
    /// Output: 11
    /// Explanation: The absolute difference between the first and last 
    /// element must be 3 for a good subarray. All the good subarrays are: 
    /// [-1,3,2], and [2,4,5]. The maximum subarray sum is 11 for the 
    /// subarray [2,4,5].
    ///
    /// Example 3:
    /// Input: nums = [-1,-2,-3,-4], k = 2
    /// Output: -6
    /// Explanation: The absolute difference between the first and last 
    /// element must be 2 for a good subarray. All the good subarrays 
    /// are: [-1,-2,-3], and [-2,-3,-4]. The maximum subarray sum is -6 
    /// for the subarray [-1,-2,-3].
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// 3. 1 <= k <= 10^9
    /// </summary>
    long long maximumSubarraySum(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3030. Find the Grid of Region Average
    ///
    /// Medium
    ///
    /// You are given a 0-indexed m x n grid image which represents a 
    /// grayscale image, where image[i][j] represents a pixel with 
    /// intensity in the range[0..255]. You are also given a non-negative 
    /// integer threshold.
    ///
    /// Two pixels image[a][b] and image[c][d] are said to be adjacent 
    /// if |a - c| + |b - d| == 1.
    ///
    /// A region is a 3 x 3 subgrid where the absolute difference in 
    /// intensity between any two adjacent pixels is less than or equal to 
    /// threshold.
    ///
    /// All pixels in a region belong to that region, note that a pixel 
    /// can belong to multiple regions.
    ///
    /// You need to calculate a 0-indexed m x n grid result, where 
    /// result[i][j] is the average intensity of the region to which 
    /// image[i][j] belongs, rounded down to the nearest integer. If 
    /// image[i][j] belongs to multiple regions, result[i][j] is the average 
    /// of the rounded down average intensities of these regions, rounded 
    /// down to the nearest integer. If image[i][j] does not belong to any 
    /// region, result[i][j] is equal to image[i][j].
    ///
    /// Return the grid result.
    /// 
    /// Example 1:
    /// Input: image = [[5,6,7,10],[8,9,10,10],[11,12,13,10]], threshold = 3
    /// Output: [[9,9,9,9],[9,9,9,9],[9,9,9,9]]
    /// Explanation: There exist two regions in the image, which are shown 
    /// as the shaded areas in the picture. The average intensity of the 
    /// first region is 9, while the average intensity of the second region 
    /// is 9.67 which is rounded down to 9. The average intensity of both of 
    /// the regions is (9 + 9) / 2 = 9. As all the pixels belong to either 
    /// region 1, region 2, or both of them, the intensity of every pixel in 
    /// the result is 9. 
    /// Please note that the rounded-down values are used when calculating 
    /// the average of multiple regions, hence the calculation is done 
    /// using 9 as the average intensity of region 2, not 9.67.
    ///
    /// Example 2:
    /// Input: image = [[10,20,30],[15,25,35],[20,30,40],[25,35,45]], 
    /// threshold = 12
    /// Output: [[25,25,25],[27,27,27],[27,27,27],[30,30,30]]
    /// Explanation: There exist two regions in the image, which are shown as 
    /// the shaded areas in the picture. The average intensity of the first 
    /// region is 25, while the average intensity of the second region is 30. 
    /// The average intensity of both of the regions is (25 + 30) / 2 = 27.5 
    /// which is rounded down to 27. All the pixels in row 0 of the image 
    /// belong to region 1, hence all the pixels in row 0 in the result 
    /// are 25. Similarly, all the pixels in row 3 in the result are 30. The 
    /// pixels in rows 1 and 2 of the image belong to region 1 and region 2, 
    /// hence their assigned value is 27 in the result.
    ///
    /// Example 3:
    /// Input: image = [[5,6,7],[8,9,10],[11,12,13]], threshold = 1
    /// Output: [[5,6,7],[8,9,10],[11,12,13]]
    /// Explanation: There does not exist any region in image, hence 
    /// result[i][j] == image[i][j] for all the pixels.
    /// 
    /// Constraints:
    /// 1. 3 <= n, m <= 500
    /// 2. 0 <= image[i][j] <= 255
    /// 3. 0 <= threshold <= 255
    /// </summary>
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold);

    /// <summary>
    /// Leet Code 3033. Modify the Matrix
    ///
    /// Easy
    ///
    /// Given a 0-indexed m x n integer matrix matrix, create a new 0-indexed 
    /// matrix called answer. Make answer equal to matrix, then replace each 
    /// element with the value -1 with the maximum element in its respective 
    /// column.
    ///
    /// Return the matrix answer.
    ///
    /// Example 1:
    /// Input: matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
    /// Output: [[1,2,9],[4,8,6],[7,8,9]]
    /// Explanation: The diagram above shows the elements that are changed 
    /// (in blue).
    /// - We replace the value in the cell [1][1] with the maximum value in 
    ///   the column 1, that is 8.
    /// - We replace the value in the cell [0][2] with the maximum value in 
    ///   the column 2, that is 9.
    ///
    /// Example 2:
    /// Input: matrix = [[3,-1],[5,2]]
    /// Output: [[3,2],[5,2]]
    /// Explanation: The diagram above shows the elements that are changed 
    /// (in blue).
    /// 
    /// Constraints:
    /// 1. m == matrix.length
    /// 2. n == matrix[i].length
    /// 3. 2 <= m, n <= 50
    /// 4. -1 <= matrix[i][j] <= 100
    /// 5. The input is generated such that each column contains at least 
    ///    one non-negative integer.
    /// </summary>
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet Code 3038. Maximum Number of Operations With the Same Score I
    ///
    /// Easy
    ///
    /// Given an array of integers called nums, you can perform the following 
    /// operation while nums contains at least 2 elements:
    ///
    /// Choose the first two elements of nums and delete them.
    /// The score of the operation is the sum of the deleted elements.
    ///
    /// Your task is to find the maximum number of operations that can be 
    /// performed, such that all operations have the same score.
    ///
    /// Return the maximum number of operations possible that satisfy the 
    /// condition mentioned above.
    /// 
    /// Example 1:
    /// Input: nums = [3,2,1,4,5]
    /// Output: 2
    /// Explanation: We perform the following operations:
    /// - Delete the first two elements, with score 3 + 2 = 5, nums = [1,4,5].
    /// - Delete the first two elements, with score 1 + 4 = 5, nums = [5].
    /// We are unable to perform any more operations as nums contain only 1 
    /// element.
    ///
    /// Example 2:
    /// Input: nums = [3,2,6,1,4]
    /// Output: 1
    /// Explanation: We perform the following operations:
    /// - Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
    /// We are unable to perform any more operations as the score of the next 
    /// operation isn't the same as the previous one.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 1000
    /// </summary>
    int maxOperationsI(vector<int>& nums);


    /// <summary>
    /// Leet Code 3065. Minimum Operations to Exceed Threshold Value I
    ///
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums, and an integer k.
    /// In one operation, you can remove one occurrence of the smallest 
    /// element of nums.
    ///
    /// Return the minimum number of operations needed so that all elements 
    /// of the array are greater than or equal to k.
    ///
    /// Example 1:
    /// Input: nums = [2,11,10,1,3], k = 10
    /// Output: 3
    ///
    /// Explanation: After one operation, nums becomes equal to [2, 11, 10, 3].
    /// After two operations, nums becomes equal to [11, 10, 3].
    /// After three operations, nums becomes equal to [11, 10].
    /// At this stage, all the elements of nums are greater than or equal 
    /// to 10 so we can stop.
    /// It can be shown that 3 is the minimum number of operations needed so 
    /// that all elements of the array are greater than or equal to 10.
    ///
    /// Example 2:
    /// Input: nums = [1,1,2,4,9], k = 1
    /// Output: 0
    /// Explanation: All elements of the array are greater than or equal 
    /// to 1 so we do not need to apply any operations on nums.
    ///
    /// Example 3:
    /// Input: nums = [1,1,2,4,9], k = 9
    /// Output: 4
    /// Explanation: only a single element of nums is greater than or equal 
    /// to 9 so we need to apply the operations 4 times on nums.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 50
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= 10^9
    /// 4. The input is generated such that there is at least one index i 
    ///    such that nums[i] >= k.
    /// </summary>
    int minOperationsI(vector<int>& nums, int k);

    /// <summary>
    /// Leet 3069. Distribute Elements Into Two Arrays I
    ///
    /// Easy
    ///
    /// You are given a 1-indexed array of distinct integers nums of length n.
    /// You need to distribute all the elements of nums between two arrays 
    /// arr1 and arr2 using n operations. In the first operation, append 
    /// nums[1] to arr1. In the second operation, append nums[2] to arr2. 
    /// Afterwards, in the ith operation:
    ///
    /// If the last element of arr1 is greater than the last element of arr2, 
    /// append nums[i] to arr1. Otherwise, append nums[i] to arr2.
    /// The array result is formed by concatenating the arrays arr1 and arr2. 
    /// For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then 
    /// result = [1,2,3,4,5,6].
    ///
    /// Return the array result.
    /// 
    /// Example 1:
    /// Input: nums = [2,1,3]
    /// Output: [2,3,1]
    /// Explanation: After the first 2 operations, arr1 = [2] and arr2 = [1].
    /// In the 3rd operation, as the last element of arr1 is greater than the 
    /// last element of arr2 (2 > 1), append nums[3] to arr1.
    /// After 3 operations, arr1 = [2,3] and arr2 = [1].
    /// Hence, the array result formed by concatenation is [2,3,1].
    ///
    /// Example 2:
    /// Input: nums = [5,4,3,8]
    /// Output: [5,3,4,8]
    /// Explanation: After the first 2 operations, arr1 = [5] and arr2 = [4].
    /// In the 3rd operation, as the last element of arr1 is greater than the 
    /// last element of arr2 (5 > 4), append nums[3] to arr1, hence arr1 
    /// becomes [5,3].
    /// In the 4th operation, as the last element of arr2 is greater than the 
    /// last element of arr1 (4 > 3), append nums[4] to arr2, hence arr2 
    /// becomes [4,8].
    /// After 4 operations, arr1 = [5,3] and arr2 = [4,8].
    /// Hence, the array result formed by concatenation is [5,3,4,8].
    ///
    /// Constraints:
    /// 1. 3 <= n <= 50
    /// 2. 1 <= nums[i] <= 100
    /// 3. All elements in nums are distinct.
    /// </summary>
    vector<int> resultArrayI(vector<int>& nums);


    /// <summary>
    /// Leet 3071. Minimum Operations to Write the Letter Y on a Grid
    ///
    /// Medium
    ///
    /// You are given a 0-indexed n x n grid where n is odd, and 
    /// grid[r][c] is 0, 1, or 2.
    ///
    /// We say that a cell belongs to the Letter Y if it belongs to one of 
    /// the following:
    ///
    /// The diagonal starting at the top-left cell and ending at the center 
    /// cell of the grid.
    /// The diagonal starting at the top-right cell and ending at the center 
    /// cell of the grid.
    /// The vertical line starting at the center cell and ending at the bottom 
    /// border of the grid.
    /// The Letter Y is written on the grid if and only if:
    ///
    /// All values at cells belonging to the Y are equal.
    /// All values at cells not belonging to the Y are equal.
    /// The values at cells belonging to the Y are different from the values 
    /// at cells not belonging to the Y.
    /// Return the minimum number of operations needed to write the letter Y 
    /// on the grid given that in one operation you can change the value at 
    /// any cell to 0, 1, or 2.
    /// 
    /// Example 1:
    /// Input: grid = [[1,2,2],[1,1,0],[0,1,0]]
    /// Output: 3
    /// Explanation: We can write Y on the grid by applying the changes 
    /// highlighted in blue in the image above. After the operations, all 
    /// cells that belong to Y, denoted in bold, have the same value of 1 
    /// while those that do not belong to Y are equal to 0.
    /// It can be shown that 3 is the minimum number of operations needed to 
    /// write Y on the grid.
    ///
    /// Example 2:
    /// Input: grid = [[0,1,0,1,0],[2,1,0,1,2],[2,2,2,0,1],[2,2,2,2,2],
    ///                [2,1,2,2,2]]
    /// Output: 12
    /// Explanation: We can write Y on the grid by applying the changes 
    /// highlighted in blue in the image above. After the operations, all 
    /// cells that belong to Y, denoted in bold, have the same value of 0 
    /// while those that do not belong to Y are equal to 2. 
    /// It can be shown that 12 is the minimum number of operations needed to 
    /// write Y on the grid.
    /// 
    /// Constraints:
    /// 1. 3 <= n <= 49 
    /// 2. n == grid.length == grid[i].length
    /// 3. 0 <= grid[i][j] <= 2
    /// 4. n is odd.
    /// </summary>
    int minimumOperationsToWriteY(vector<vector<int>>& grid);


    /// <summary>
    /// Leet 3078. Match Alphanumerical Pattern in Matrix I
    ///
    /// Medium
    ///
    /// You are given a 2D integer matrix board and a 2D character matrix 
    /// pattern. Where 0 <= board[r][c] <= 9 and each element of pattern 
    /// is either a digit or a lowercase English letter.
    ///
    /// Your task is to find a submatrix of board that matches pattern.
    ///
    /// An integer matrix part matches pattern if we can replace cells 
    /// containing letters in pattern with some digits (each distinct 
    /// letter with a unique digit) in such a way that the resulting matrix 
    /// becomes identical to the integer matrix part. In other words,
    /// 
    /// The matrices have identical dimensions.
    /// If pattern[r][c] is a digit, then part[r][c] must be the same digit.
    /// If pattern[r][c] is a letter x:
    /// For every pattern[i][j] == x, part[i][j] must be the same as 
    /// part[r][c].
    /// For every pattern[i][j] != x, part[i][j] must be different than 
    /// part[r][c].
    /// Return an array of length 2 containing the row number and column 
    /// number of the upper-left corner of a submatrix of board which matches 
    /// pattern. If there is more than one such submatrix, return the 
    /// coordinates of the submatrix with the lowest row index, and in case 
    /// there is still a tie, return the coordinates of the submatrix with 
    /// the lowest column index. If there are no suitable answers, 
    /// return [-1, -1].
    ///
    /// Example 1:
    /// 1	2	2
    /// 2	2	3
    /// 2	3	3
    /// a	b
    /// b	b
    /// Input: board = [[1,2,2],[2,2,3],[2,3,3]], pattern = ["ab","bb"]
    ///
    /// Output: [0,0]
    /// 
    /// Explanation: If we consider this mapping: "a" -> 1 and "b" -> 2; 
    /// the submatrix with the upper-left corner (0,0) is a match as outlined 
    /// in the matrix above.
    ///
    /// Note that the submatrix with the upper-left corner (1,1) is also a 
    /// match but since it comes after the other one, we return [0,0].
    ///
    /// Example 2:
    /// 1	1	2
    /// 3	3	4
    /// 6	6	6
    /// a	b
    /// 6	6
    /// Input: board = [[1,1,2],[3,3,4],[6,6,6]], pattern = ["ab","66"]
    /// Output: [1,1]
    /// Explanation: If we consider this mapping: "a" -> 3 and "b" -> 4; 
    /// the submatrix with the upper-left corner (1,1) is a match as 
    /// outlined in the matrix above.
    /// Note that since the corresponding values of "a" and "b" must 
    /// differ, the submatrix with the upper-left corner (1,0) is not a 
    /// match. Hence, we return [1,1].
    ///
    /// Example 3:
    /// 1	2
    /// 2	1
    /// x	x
    /// Input: board = [[1,2],[2,1]], pattern = ["xx"]
    ///
    /// Output: [-1,-1]
    ///
    /// Explanation: Since the values of the matched submatrix must be the 
    /// same, there is no match. Hence, we return [-1,-1].
    /// 
    /// Constraints:
    /// 1. 1 <= board.length <= 50
    /// 2. 1 <= board[i].length <= 50
    /// 3. 0 <= board[i][j] <= 9
    /// 4. 1 <= pattern.length <= 50
    /// 5. 1 <= pattern[i].length <= 50
    /// 6. pattern[i][j] is either a digit represented as a string or a 
    ///    lowercase English letter.
    /// </summary>
    vector<int> findPattern(vector<vector<int>>& board, vector<string>& pattern);


    /// <summary>
    /// Leet 3086. Minimum Moves to Pick K Ones
    ///
    /// Hard
    ///
    /// You are given a binary array nums of length n, a positive integer k 
    /// and a non-negative integer maxChanges.
    ///
    /// Alice plays a game, where the goal is for Alice to pick up k ones 
    /// from nums using the minimum number of moves. When the game starts, 
    /// Alice picks up any index aliceIndex in the range [0, n - 1] and 
    /// stands there. If nums[aliceIndex] == 1 , Alice picks up the one 
    /// and nums[aliceIndex] becomes 0(this does not count as a move). 
    /// After this, Alice can make any number of moves (including zero) 
    /// where in each move Alice must perform exactly one of the following 
    /// actions:
    ///
    /// Select any index j != aliceIndex such that nums[j] == 0 and set 
    /// nums[j] = 1. This action can be performed at most maxChanges times.
    /// Select any two adjacent indices x and y (|x - y| == 1) such that 
    /// nums[x] == 1, nums[y] == 0, then swap their values (set nums[y] = 1 
    /// and nums[x] = 0). If y == aliceIndex, Alice picks up the one after 
    /// this move and nums[y] becomes 0.
    /// Return the minimum number of moves required by Alice to pick 
    /// exactly k ones.
    ///
    /// Example 1:
    /// Input: nums = [1,1,0,0,0,1,1,0,0,1], k = 3, maxChanges = 1
    /// Output: 3
    ///
    /// Explanation: Alice can pick up 3 ones in 3 moves, if Alice performs 
    /// the following actions in each move when standing at aliceIndex == 1:
    ///
    /// At the start of the game Alice picks up the one and nums[1] becomes 0. 
    /// nums becomes [1,0,1,0,0,1,1,0,0,1].
    /// Select j == 2 and perform an action of the first type. nums 
    /// becomes [1,0,1,0,0,1,1,0,0,1]
    /// Select x == 2 and y == 1, and perform an action of the second type. 
    /// nums becomes [1,1,0,0,0,1,1,0,0,1]. As y == aliceIndex, Alice picks 
    /// up the one and nums becomes [1,0,0,0,0,1,1,0,0,1].
    /// Select x == 0 and y == 1, and perform an action of the second type. 
    /// nums becomes [0,1,0,0,0,1,1,0,0,1]. As y == aliceIndex, Alice picks 
    /// up the one and nums becomes [0,0,0,0,0,1,1,0,0,1].
    /// Note that it may be possible for Alice to pick up 3 ones using some 
    /// other sequence of 3 moves.
    /// 
    /// Example 2:
    /// Input: nums = [0,0,0,0], k = 2, maxChanges = 3
    /// Output: 4
    /// Explanation: Alice can pick up 2 ones in 4 moves, if Alice performs 
    /// the following actions in each move when standing at aliceIndex == 0:
    ///
    /// Select j == 1 and perform an action of the first type. nums 
    /// becomes [0,1,0,0].
    /// Select x == 1 and y == 0, and perform an action of the second type. 
    /// nums becomes [1,0,0,0]. As y == aliceIndex, Alice picks up the one 
    /// and nums becomes [0,0,0,0].
    /// Select j == 1 again and perform an action of the first type. nums 
    /// becomes [0,1,0,0].
    /// Select x == 1 and y == 0 again, and perform an action of the second 
    /// type. nums becomes [1,0,0,0]. As y == aliceIndex, Alice picks up the 
    /// one and nums becomes [0,0,0,0].
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. 0 <= nums[i] <= 1
    /// 3. 1 <= k <= 10^5
    /// 4. 0 <= maxChanges <= 10^5
    /// 5. maxChanges + sum(nums) >= k
    /// </summary>
    long long minimumMoves(vector<int>& nums, int k, int maxChanges);

    /// <summary>
    /// Leet 3101. Count Alternating Subarrays
    ///
    /// Medium
    ///
    /// You are given a binary array nums. 
    /// We call a subarray alternating if no two adjacent elements in the 
    /// subarray have the same value.
    ///
    /// Return the number of alternating subarrays in nums.
    /// 
    /// Example 1:
    /// Input: nums = [0,1,1,1]
    /// Output: 5
    /// Explanation:
    /// The following subarrays are alternating: [0], [1], [1], [1], and [0,1].
    ///
    /// Example 2:
    /// Input: nums = [1,0,1,0]
    /// Output: 10
    /// Explanation:
    /// Every subarray of the array is alternating. There are 10 possible 
    /// subarrays that we can choose.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. nums[i] is either 0 or 1.
    /// </summary>
    long long countAlternatingSubarrays(vector<int>& nums);


    /// <summary>
    /// Leet 3096. Minimum Levels to Gain More Points
    ///
    /// Medium
    ///
    /// You are given a binary array possible of length n.
    ///
    /// Danielchandg and Bob are playing a game that consists of n levels. 
    /// Some of the levels in the game are impossible to clear while others 
    /// can always be cleared. In particular, if possible[i] == 0, then the 
    /// ith level is impossible to clear for both the players. A player 
    /// gains 1 point on clearing a level and loses 1 point if the player 
    /// fails to clear it.
    ///
    /// At the start of the game, Danielchandg will play some levels in the 
    /// given order starting from the 0th level, after which Bob will play 
    /// for the rest of the levels.
    ///
    /// Danielchandg wants to know the minimum number of levels he should 
    /// play to gain more points than Bob, if both players play optimally 
    /// to maximize their points.
    ///
    /// Return the minimum number of levels danielchandg should play to 
    /// gain more points. If this is not possible, return -1.
    ///
    /// Note that each player must play at least 1 level.
    /// 
    /// Example 1:
    /// Input: possible = [1,0,1,0]
    /// Output: 1
    ///
    /// Explanation:
    /// Let's look at all the levels that Danielchandg can play up to:
    ///
    /// If Danielchandg plays only level 0 and Bob plays the rest of the 
    /// levels, Danielchandg has 1 point, while Bob has -1 + 1 - 1 = -1 point.
    /// If Danielchandg plays till level 1 and Bob plays the rest of the 
    /// levels, Danielchandg has 1 - 1 = 0 points, while Bob has 1 - 1 = 0 
    /// points.
    /// If Danielchandg plays till level 2 and Bob plays the rest of the 
    /// levels, Danielchandg has 1 - 1 + 1 = 1 point, while Bob has -1 point.
    /// Danielchandg must play a minimum of 1 level to gain more points.
    ///
    /// Example 2:
    /// Input: possible = [1,1,1,1,1]
    /// Output: 3 
    ///
    /// Explanation:
    /// Let's look at all the levels that Danielchandg can play up to:
    /// If Danielchandg plays only level 0 and Bob plays the rest of the 
    /// levels, Danielchandg has 1 point, while Bob has 4 points.
    /// If Danielchandg plays till level 1 and Bob plays the rest of the 
    /// levels, Danielchandg has 2 points, while Bob has 3 points.
    /// If Danielchandg plays till level 2 and Bob plays the rest of the 
    /// levels, Danielchandg has 3 points, while Bob has 2 points.
    /// If Danielchandg plays till level 3 and Bob plays the rest of the 
    ///  levels, Danielchandg has 4 points, while Bob has 1 point.
    /// Danielchandg must play a minimum of 3 levels to gain more points.
    ///
    /// Example 3:
    /// Input: possible = [0,0]
    /// Output: -1
    /// Explanation:
    /// The only possible way is for both players to play 1 level each. 
    /// Danielchandg plays level 0 and loses 1 point. Bob plays level 1 and 
    /// loses 1 point. As both players have equal points, Danielchandg can't 
    /// gain more points than Bob.
    /// 
    /// Constraints:
    /// 1. 2 <= n == possible.length <= 10^5
    /// 2. possible[i] is either 0 or 1.
    /// </summary>
    int minimumLevels(vector<int>& possible);

    /// <summary>
    /// Leet 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
    ///
    /// Easy
    ///
    /// You are given an array of integers nums. Return the length of the 
    /// longest subarray of nums which is either strictly increasing or
    /// strictly decreasing
    ///
    /// Example 1:
    /// Input: nums = [1,4,3,3,2]
    /// Output: 2
    /// Explanation:
    /// The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], 
    /// and [1,4].
    /// The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], 
    /// [3,2], and [4,3].
    /// Hence, we return 2.
    ///
    /// Example 2:
    /// Input: nums = [3,3,3,3]
    /// Output: 1
    /// Explanation:
    /// The strictly increasing subarrays of nums are [3], [3], [3], and [3].
    /// The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
    /// Hence, we return 1.
    ///
    /// Example 3:
    /// Input: nums = [3,2,1]
    /// Output: 3
    /// Explanation:
    /// The strictly increasing subarrays of nums are [3], [2], and [1].
    /// The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], 
    /// [2,1], and [3,2,1].
    /// Hence, we return 3.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 50
    /// 2. 1 <= nums[i] <= 50
    /// </summary>
    int longestMonotonicSubarray(vector<int>& nums);


    /// <summary>
    /// Leet 3107. Minimum Operations to Make Median of Array Equal to K 
    ///
    /// Medium
    ///
    /// You are given an integer array nums and a non-negative integer k. 
    /// In one operation, you can increase or decrease any element by 1.
    ///
    /// Return the minimum number of operations needed to make the median of 
    /// nums equal to k.
    ///
    /// The median of an array is defined as the middle element of the array 
    /// when it is sorted in non-decreasing order. If there are two choices 
    /// for a median, the larger of the two values is taken.
    ///
    /// Example 1:
    /// Input: nums = [2,5,6,8,5], k = 4
    /// Output: 2
    /// Explanation:
    /// We can subtract one from nums[1] and nums[4] to obtain 
    /// [2, 4, 6, 8, 4]. The median of the resulting array is equal to k.
    /// 
    /// Example 2:
    /// Input: nums = [2,5,6,8,5], k = 7
    /// Output: 3
    /// Explanation:
    /// We can add one to nums[1] twice and add one to nums[2] once to 
    /// obtain [2, 7, 7, 8, 5].
    ///
    /// Example 3:
    /// Input: nums = [1,2,3,4,5,6], k = 4
    /// Output: 0
    /// Explanation:
    /// The median of the array is already equal to k.
    ///  
    /// Constraints:
    /// 1. 1 <= nums.length <= 2 * 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= 10^9
    /// </summary>
    long long minOperationsToMakeMedianK(vector<int>& nums, int k);

    /// <summary>
    /// LeetCode 3127. Make a Square with the Same Color
    ///                
    /// Easy
    ///
    /// You are given a 2D matrix grid of size 3 x 3 consisting only of 
    /// characters 'B' and 'W'. Character 'W' represents the white color, 
    /// and character 'B' represents the black color.
    ///
    /// Your task is to change the color of at most one cell so that the 
    /// matrix has a 2 x 2 square where all cells are of the same color.
    ///
    /// Return true if it is possible to create a 2 x 2 square of the same 
    /// color, otherwise, return false.
    /// 
    /// Example 1:
    /// Input: grid = [["B","W","B"],["B","W","W"],["B","W","B"]]
    /// Output: true
    /// Explanation:
    /// It can be done by changing the color of the grid[0][2].
    ///
    /// Example 2:
    /// Input: grid = [["B","W","B"],["W","B","W"],["B","W","B"]]
    /// Output: false
    /// Explanation:
    /// It cannot be done by changing at most one cell.
    ///
    /// Example 3:
    /// Input: grid = [["B","W","B"],["B","W","W"],["B","W","W"]]
    /// Output: true
    /// Explanation:
    /// The grid already contains a 2 x 2 square of the same color.
    ///
    /// Constraints:
    /// 1. grid.length == 3
    /// 2. grid[i].length == 3
    /// 3. grid[i][j] is either 'W' or 'B'.
    /// </summary>
    bool canMakeSquare(vector<vector<char>>& grid);


    /// <summary>
    /// LeetCode 3128. Right Triangles
    ///                
    /// Medium
    ///
    /// You are given a 2D boolean matrix grid.
    /// Return an integer that is the number of right triangles that can be 
    /// made with the 3 elements of grid such that all of them have a value 
    /// of 1.
    ///
    /// Note:
    /// A collection of 3 elements of grid is a right triangle if one of its
    /// elements is in the same row with another element and in the same 
    /// column with the third element. The 3 elements do not have to be next 
    /// to each other.
    /// 
    /// Example 1:
    /// 0	1	0
    /// 0	1	1
    /// 0	1	0
    ///
    /// Input: grid = [[0,1,0],[0,1,1],[0,1,0]]
    /// Output: 2
    /// Explanation:
    /// There are two right triangles.
    ///
    /// Example 2:
    /// 1	0	0	0
    /// 0	1	0	1
    /// 1	0	0	0
    /// Input: grid = [[1,0,0,0],[0,1,0,1],[1,0,0,0]]
    /// Output: 0
    /// Explanation:
    /// There are no right triangles.
    ////
    /// Example 3:
    /// 1	0	1
    /// 1	0	0
    /// 1	0	0
    /// Input: grid = [[1,0,1],[1,0,0],[1,0,0]]
    /// Output: 2
    /// Explanation:
    /// There are two right triangles.
    ///  
    /// Constraints:
    /// 1. 1 <= grid.length <= 1000
    /// 2. 1 <= grid[i].length <= 1000
    /// 3. 0 <= grid[i][j] <= 1
    /// </summary>
    long long numberOfRightTriangles(vector<vector<int>>& grid);

    /// LeetCode 3131. Find the Integer Added to Array I
    ///                
    /// Easy
    ///
    /// You are given two arrays of equal length, nums1 and nums2.
    /// Each element in nums1 has been increased (or decreased in the case of 
    /// negative) by an integer, represented by the variable x.
    ///
    /// As a result, nums1 becomes equal to nums2. Two arrays are considered 
    /// equal when they contain the same integers with the same frequencies.
    ///
    /// Return the integer x.
    /// 
    /// Example 1:
    /// Input: nums1 = [2,6,4], nums2 = [9,7,5]
    /// Output: 3
    /// Explanation:
    /// The integer added to each element of nums1 is 3.
    ///
    /// Example 2:
    /// Input: nums1 = [10], nums2 = [5]
    /// Output: -5
    /// Explanation:
    /// The integer added to each element of nums1 is -5.
    ///
    /// Example 3:
    /// Input: nums1 = [1,1,1,1], nums2 = [1,1,1,1]
    /// Output: 0
    /// Explanation:
    /// The integer added to each element of nums1 is 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums1.length == nums2.length <= 100
    /// 2. 0 <= nums1[i], nums2[i] <= 1000
    /// 3. The test cases are generated in a way that there is an integer x 
    ///    such that nums1 can become equal to nums2 by adding x to each 
    ///    element of nums1.
    /// </summary>
    int addedIntegerI(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// LeetCode 3132. Find the Integer Added to Array II
    ///                
    /// Medium
    ///
    /// You are given two integer arrays nums1 and nums2.
    /// From nums1 two elements have been removed, and all other elements have 
    /// been increased (or decreased in the case of negative) by an integer, 
    /// represented by the variable x.
    ///
    /// As a result, nums1 becomes equal to nums2. Two arrays are considered 
    /// equal when they contain the same integers with the same frequencies.
    ///
    /// Return the minimum possible integer x that achieves this equivalence.
    ///
    /// Example 1:
    /// Input: nums1 = [4,20,16,12,8], nums2 = [14,18,10]
    /// Output: -2
    /// Explanation:
    /// After removing elements at indices [0,4] and adding -2, nums1 
    /// becomes [18,14,10].
    ///
    /// Example 2:
    /// Input: nums1 = [3,5,5,3], nums2 = [7,7]
    /// Output: 2
    /// Explanation:
    /// After removing elements at indices [0,3] and adding 2, nums1 
    /// becomes [7,7].
    ///
    /// Constraints:
    /// 1. 3 <= nums1.length <= 200
    /// 2. nums2.length == nums1.length - 2
    /// 3. 0 <= nums1[i], nums2[i] <= 1000
    /// 4. The test cases are generated in a way that there is an integer x 
    ///    such that nums1 can become equal to nums2 by removing two elements 
    ///    and adding x to each element of nums1.
    /// </summary>
    int addedIntegerII(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// LeetCode 3142. Check if Grid Satisfies Conditions
    /// 
    /// Easy
    /// 
    /// You are given a 2D matrix grid of size m x n. You need to check if 
    /// each cell grid[i][j] is:
    ///
    /// Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if 
    /// it exists).
    /// Different from the cell to its right, i.e. grid[i][j] != 
    /// grid[i][j + 1] (if it exists).
    /// Return true if all the cells satisfy these conditions, otherwise, 
    /// return false.
    /// 
    /// Example 1:
    /// Input: grid = [[1,0,2],[1,0,2]]
    /// Output: true
    /// Explanation:
    /// All the cells in the grid satisfy the conditions.
    ///
    /// Example 2:
    /// Input: grid = [[1,1,1],[0,0,0]]
    /// Output: false
    /// Explanation:
    /// All cells in the first row are equal.
    ///
    /// Example 3:
    /// Input: grid = [[1],[2],[3]]
    /// Output: false
    /// Explanation:
    /// Cells in the first column have different values.
    ///
    /// Constraints:
    /// 1. 1 <= n, m <= 10
    /// 2. 0 <= grid[i][j] <= 9
    /// </summary>
    bool satisfiesConditions(vector<vector<int>>& grid);

    /// <summary>
    /// LeetCode 3148. Maximum Difference Score in a Grid
    /// 
    /// Medium
    ///
    /// You are given an m x n matrix grid consisting of positive integers. 
    /// You can move from a cell in the matrix to any other cell that is 
    /// either to the bottom or to the right (not necessarily adjacent). 
    /// The score of a move from a cell with the value c1 to a cell with the 
    /// value c2 is c2 - c1.
    ///
    /// You can start at any cell, and you have to make at least one move.
    ///
    /// Return the maximum total score you can achieve.
    /// 
    /// Example 1:
    /// Input: grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]
    /// Output: 9
    /// Explanation: We start at the cell (0, 1), and we perform the following 
    /// moves:
    /// - Move from the cell (0, 1) to (2, 1) with a score of 7 - 5 = 2.
    /// - Move from the cell (2, 1) to (2, 2) with a score of 14 - 7 = 7.
    /// The total score is 2 + 7 = 9.
    ///
    /// Example 2:
    /// Input: grid = [[4,3,2],[3,2,1]]
    /// Output: -1
    /// Explanation: We start at the cell (0, 0), and we perform one move: 
    /// (0, 0) to (0, 1). The score is 3 - 4 = -1.
    /// 
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 2 <= m, n <= 1000
    /// 4. 4 <= m * n <= 10^5
    /// 5. 1 <= grid[i][j] <= 10^5
    /// </summary>
    int maxScore(vector<vector<int>>& grid);

    /// <summary>
    /// LeetCode 3151. Special Array I
    /// 
    /// Easy
    ///
    /// An array is considered special if every pair of its adjacent elements 
    /// contains two numbers with different parity.
    ///
    /// You are given an array of integers nums. Return true if nums is a 
    /// special array, otherwise, return false.
    /// 
    /// Example 1:
    /// Input: nums = [1]
    ///
    /// Output: true
    ///
    /// Explanation:
    /// There is only one element. So the answer is true.
    ///
    /// Example 2:
    /// Input: nums = [2,1,4]
    /// Output: true
    /// Explanation:
    /// There is only two pairs: (2,1) and (1,4), and both of them contain 
    /// numbers with different parity. So the answer is true.
    ///
    /// Example 3:
    /// Input: nums = [4,3,1,6]
    /// Output: false 
    /// Explanation:
    /// nums[1] and nums[2] are both odd. So the answer is false.
    ///
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// </summary>
    bool isArraySpecial(vector<int>& nums);


    /// <summary>
    /// LeetCode 3152. Special Array II
    /// 
    /// Medium
    ///
    /// An array is considered special if every pair of its adjacent elements 
    /// contains two numbers with different parity.
    ///
    /// You are given an array of integer nums and a 2D integer matrix queries, 
    /// where for queries[i] = [fromi, toi] your task is to check that subarray
    /// nums[fromi..toi] is special or not.
    ///
    /// Return an array of booleans answer such that answer[i] is true if 
    /// nums[fromi..toi] is special.
    ///
    /// Example 1:
    /// Input: nums = [3,4,1,2,6], queries = [[0,4]]
    /// Output: [false]
    ///
    /// Explanation:
    /// The subarray is [3,4,1,2,6]. 2 and 6 are both even.
    ///
    /// Example 2: 
    /// Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
    /// Output: [false,true]
    /// Explanation:
    /// The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this 
    /// query is false.
    /// The subarray is [1,6]. There is only one pair: (1,6) and it contains 
    /// numbers with different parity. So the answer to this query is true.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// 3. 1 <= queries.length <= 10^5
    /// 4. queries[i].length == 2
    /// 5. 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
    /// </summary>
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries);

    /// <summary>
    /// LeetCode 3159. Find Occurrences of an Element in an Array
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums, an integer array queries, and an 
    /// integer x.
    ///
    /// For each queries[i], you need to find the index of the queries[i]th 
    /// occurrence of x in the nums array. If there are fewer than queries[i] 
    /// occurrences of x, the answer should be -1 for that query.
    ///
    /// Return an integer array answer containing the answers to all queries.
    ///
    /// Example 1:
    /// Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1
    /// Output: [0,-1,2,-1]
    /// Explanation:
    /// For the 1st query, the first occurrence of 1 is at index 0.
    /// For the 2nd query, there are only two occurrences of 1 in nums, so 
    /// the answer is -1.
    /// For the 3rd query, the second occurrence of 1 is at index 2.
    /// For the 4th query, there are only two occurrences of 1 in nums, so 
    /// the answer is -1.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3], queries = [10], x = 5
    /// Output: [-1]
    /// Explanation:
    /// For the 1st query, 5 doesn't exist in nums, so the answer is -1.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length, queries.length <= 10^5
    /// 2. 1 <= queries[i] <= 10^5
    /// 3. 1 <= nums[i], x <= 10^4
    /// </summary>
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x);
};
#endif  // LeetCodeArray_H
