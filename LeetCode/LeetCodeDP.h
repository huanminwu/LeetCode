#pragma once
#ifndef LeetcodeDP_H
#define LeetCodeDP_H
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
class LeetCodeDP
{
public:
    /// <summary>
    /// Leet code #45. Jump Game II
    /// 
    /// Given an array of non-negative integers, you are initially positioned 
    /// at the first index of the array.
    ///
    /// Each element in the array represents your maximum jump length at 
    /// that position.
    ///
    /// Your goal is to reach the last index in the minimum number of jumps.
    ///
    /// Example:
    ///
    /// Input: [2,3,1,1,4]
    /// Output: 2
    /// Explanation: The minimum number of jumps to reach the last index is 2.
    /// Jump 1 step from index 0 to 1, then 3 steps to the last index.
    /// Note:
    /// You can assume that you can always reach the last index.
    /// </summary>
    int jump(vector<int>& nums);

    /// <summary>
    /// Leet code #264. Ugly Number II
    /// 
    /// Write a program to find the n-th ugly number.
    ///
    /// Ugly numbers are positive numbers whose prime factors only 
    /// include 2, 3, 5. 
    ///
    /// Example:
    ///
    /// Input: n = 10
    /// Output: 12
    /// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of 
    /// the first 10 ugly numbers.
    /// Note:  
    ///
    /// 1. 1 is typically treated as an ugly number.
    /// 2. n does not exceed 1690.
    /// </summary>
    int nthUglyNumber(int n);

    /// <summary>
    /// Leet code #313. Super Ugly Number
    /// 
    /// Write a program to find the nth super ugly number.
    ///
    /// Super ugly numbers are positive numbers whose all prime factors 
    /// are in the given prime list primes of size k.
    ///
    /// Example:
    ///
    /// Input: n = 12, primes = [2,7,13,19]
    /// Output: 32 
    /// Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the
    /// first 12 super ugly numbers given primes = [2,7,13,19] of size 4. 
    /// Note:
    ///
    /// 1. 1 is a super ugly number for any given primes.
    /// 2. The given numbers in primes are in ascending order.
    /// 3. 0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.
    /// 4. The nth super ugly number is guaranteed to fit in a 32-bit signed 
    ///    integer.
    /// </summary>
    int nthSuperUglyNumber(int n, vector<int>& primes);

    /// <summary>
    /// Leet code #403. Frog Jump
    /// 
    /// A frog is crossing a river. The river is divided into x units and at 
    /// each unit there may or may not exist a stone. The frog can jump on a 
    /// stone, but it must not jump into the water.
    ///
    /// Given a list of stones' positions (in units) in sorted ascending order, 
    /// determine if the frog is able to cross the river by landing on the 
    /// last stone. Initially, the frog is on the first stone and assume the 
    /// first jump must be 1 unit.
    ///
    /// If the frog's last jump was k units, then its next jump must be either 
    /// k - 1, k, or k + 1 units. Note that the frog can only jump in the 
    /// forward direction.
    ///
    /// Note:
    ///
    /// The number of stones is ¡Ý 2 and is < 1,100.
    /// Each stone's position will be a non-negative integer < 231.
    /// The first stone's position is always 0.
    ///
    /// Example 1:
    ///
    /// [0,1,3,5,6,8,12,17]
    ///
    /// There are a total of 8 stones.
    /// The first stone at the 0th unit, second stone at the 1st unit,
    /// third stone at the 3rd unit, and so on...
    /// The last stone at the 17th unit.
    /// 
    /// Return true. The frog can jump to the last stone by jumping 
    /// 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
    /// 2 units to the 4th stone, then 3 units to the 6th stone, 
    /// 4 units to the 7th stone, and 5 units to the 8th stone.
    ///
    /// Example 2:
    ///
    /// [0,1,2,3,4,8,9,11]
    ///
    /// Return false. There is no way to jump to the last stone as 
    /// the gap between the 5th and 6th stone is too large.
    /// </summary>
    bool canCross(vector<int>& stones);

    /// <summary>
    /// Leet code #494. Target Sum   
    /// 
    /// You are given a list of non-negative integers, a1, a2, ..., an, and a 
    /// target, S. 
    /// Now you have 2 symbols + and -. For each integer, you should choose one 
    /// from + and - as its new symbol. 
    /// Find out how many ways to assign symbols to make sum of integers equal 
    /// to target S. 
    /// Example 1:
    /// Input: nums is [1, 1, 1, 1, 1], S is 3. 
    /// Output: 5
    /// Explanation: 
    ///
    /// -1+1+1+1+1 = 3
    /// +1-1+1+1+1 = 3
    /// +1+1-1+1+1 = 3
    /// +1+1+1-1+1 = 3
    /// +1+1+1+1-1 = 3
    /// 
    /// There are 5 ways to assign symbols to make the sum of nums be target 3.
    ///  
    /// Note:
    /// 1.The length of the given array is positive and will not exceed 20. 
    /// 2.The sum of elements in the given array will not exceed 1000.
    /// 3.Your output answer is guaranteed to be fitted in a 32-bit integer.
    /// </summary>
    int findTargetSumWays(vector<int>& nums, int S);

    /// <summary>
    /// Leet code #514. Freedom Trail
    /// 
    /// In the video game Fallout 4, the quest "Road to Freedom" requires 
    /// players to reach a metal dial called the "Freedom Trail Ring", and 
    /// use the dial to spell a specific keyword in order to open the door.
    ///
    /// Given a string ring, which represents the code engraved on the outer 
    /// ring and another string key, which represents the keyword needs to be 
    /// spelled. You need to find the minimum number of steps in order to 
    /// spell all the characters in the keyword.
    ///
    /// Initially, the first character of the ring is aligned at 12:00 
    /// direction. You need to spell all the characters in the string key one 
    /// by one by rotating the ring clockwise or anticlockwise to make each 
    /// character of the string key aligned at 12:00 direction and then by 
    /// pressing the center button.
    ///
    /// At the stage of rotating the ring to spell the key character key[i]:
    ///
    /// You can rotate the ring clockwise or anticlockwise one place, which 
    /// counts as 1 step. The final purpose of the rotation is to align one 
    /// of the string ring's characters at the 12:00 direction, where this 
    /// character must equal to the character key[i].
    /// If the character key[i] has been aligned at the 12:00 direction, you 
    /// need to press the center button to spell, which also counts as 1 step. 
    /// After the pressing, you could begin to spell the next character in the 
    /// key (next stage), otherwise, you've finished all the spelling.
    ///
    /// Example:
    /// Input: ring = "godding", key = "gd"
    /// Output: 4
    /// Explanation:
    /// For the first key character 'g', since it is already in place, we just 
    /// need 1 step to spell this character. 
    /// For the second key character 'd', we need to rotate the ring "godding" 
    /// anticlockwise by two steps to make it become "ddinggo".
    /// Also, we need 1 more step for spelling.
    /// So the final output is 4.
    ///
    /// Note:
    /// 1. Length of both ring and key will be in range 1 to 100.
    /// 2. There are only lowercase letters in both strings and might be some 
    ///    duplcate characters in both strings.
    /// 3. It's guaranteed that string key could always be spelled by rotating 
    ///    the string ring.
    /// </summary>
    int findRotateSteps(string ring, string key);

    /// <summary>
    /// Leet code #518. Coin Change 2
    /// 
    /// You are given coins of different denominations and a total amount of 
    /// money. Write a function to compute the number of combinations that 
    /// make up that amount. You may assume that you have infinite number of 
    /// each kind of coin.
    ///
    /// Note: You can assume that
    ///
    /// 1. 0 <= amount <= 5000
    /// 2. 1 <= coin <= 5000
    /// 3. the number of coins is less than 500
    /// 4. the answer is guaranteed to fit into signed 32-bit integer
    /// 
    /// Example 1:
    /// Input: amount = 5, coins = [1, 2, 5]
    /// Output: 4
    /// Explanation: there are four ways to make up the amount:
    /// 5=5
    /// 5=2+2+1
    /// 5=2+1+1+1
    /// 5=1+1+1+1+1
    /// 
    ///
    /// Example 2:
    /// Input: amount = 3, coins = [2]
    /// Output: 0
    /// Explanation: the amount of 3 cannot be made up just with coins of 2.
    /// 
    ///
    /// Example 3:
    /// Input: amount = 10, coins = [10] 
    /// Output: 1
    /// </summary>
    int change(int amount, vector<int>& coins);

    /// <summary>
    /// Leet code #879. Profitable Schemes
    /// 
    /// There are G people in a gang, and a list of various crimes they could 
    /// commit.
    ///
    /// The i-th crime generates a profit[i] and requires group[i] gang 
    /// members to participate.
    ///
    /// If a gang member participates in one crime, that member can't 
    /// participate in another crime.
    ///
    /// Let's call a profitable scheme any subset of these crimes that 
    /// generates at least P profit, and the total number of gang members 
    /// participating in that subset of crimes is at most G.
    ///
    /// How many schemes can be chosen?  Since the answer may be very large, 
    /// return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: G = 5, P = 3, group = [2,2], profit = [2,3]
    /// Output: 2
    /// Explanation: 
    /// To make a profit of at least 3, the gang could either commit crimes 
    /// 0 and 1, or just crime 1.
    /// In total, there are 2 schemes.
    ///
    /// Example 2:
    ///
    /// Input: G = 10, P = 5, group = [2,3,5], profit = [6,7,8]
    /// Output: 7
    /// Explanation: 
    /// To make a profit of at least 5, the gang could commit any crimes, as 
    /// long as they commit one.
    /// There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and 
    /// (0,1,2).
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= G <= 100
    /// 2. 0 <= P <= 100
    /// 3. 1 <= group[i] <= 100
    /// 4. 0 <= profit[i] <= 100
    /// 5. 1 <= group.length = profit.length <= 100
    /// </summary>
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit);

    /// <summary>
    /// Leet code #1143. Longest Common Subsequence
    /// 
    /// Given two strings text1 and text2, return the length of their longest 
    /// common subsequence.
    ///
    /// A subsequence of a string is a new string generated from the original 
    /// string with some characters(can be none) deleted without changing the 
    /// relative order of the remaining characters. (eg, "ace" is a 
    /// subsequence of "abcde" while "aec" is not). A common subsequence of 
    /// two strings is a subsequence that is common to both strings.
    /// 
    /// If there is no common subsequence, return 0.
    /// 
    /// Example 1:
    /// Input: text1 = "abcde", text2 = "ace" 
    /// Output: 3  
    /// Explanation: The longest common subsequence is "ace" and its length is 3.
    ///
    /// Example 2:
    /// Input: text1 = "abc", text2 = "abc"
    /// Output: 3
    /// Explanation: The longest common subsequence is "abc" and its length is 3.
    ///
    /// Example 3:
    /// Input: text1 = "abc", text2 = "def"
    /// Output: 0
    /// Explanation: There is no such common subsequence, so the result is 0.
    /// 
    ///
    /// Constraints:
    /// 1. 1 <= text1.length <= 1000
    /// 2. 1 <= text2.length <= 1000
    /// 3. The input strings consist of lowercase English characters only.
    /// </summary>
    int longestCommonSubsequence(string text1, string text2);

    /// <summary>
    /// Leet code #1147. Longest Chunked Palindrome Decomposition
    /// 
    /// Return the largest possible k such that there exists a_1, a_2, ..., a_k
    /// such that:
    ///
    /// Each a_i is a non-empty string;
    /// Their concatenation a_1 + a_2 + ... + a_k is equal to text;
    /// For all 1 <= i <= k,  a_i = a_{k+1 - i}.
    /// 
    /// Example 1:
    /// Input: text = "ghiabcdefhelloadamhelloabcdefghi"
    /// Output: 7
    /// Explanation: We can split the string on 
    /// "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
    ///
    /// Example 2:
    /// Input: text = "merchant"
    /// Output: 1
    /// Explanation: We can split the string on "(merchant)".
    ///
    /// Example 3:
    /// Input: text = "antaprezatepzapreanta"
    /// Output: 11
    /// Explanation: We can split the string on 
    /// "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".
    ///
    /// Example 4:
    /// Input: text = "aaa"
    /// Output: 3
    /// Explanation: We can split the string on "(a)(a)(a)".
    /// 
    /// Constraints:
    /// 1. text consists only of lowercase English characters.
    /// 2. 1 <= text.length <= 1000
    /// </summary>
    int longestDecomposition(string text);

    /// <summary>
    /// Leet code #1155. Number of Dice Rolls With Target Sum
    /// 
    /// You have d dice, and each die has f faces numbered 1, 2, ..., f.
    /// Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 
    /// to roll the dice so the sum of the face up numbers equals target.
    /// 
    /// Example 1:
    /// Input: d = 1, f = 6, target = 3
    /// Output: 1
    /// Explanation: 
    /// You throw one dice with 6 faces.  There is only one way to get a sum of 3.
    ///
    /// Example 2:
    /// Input: d = 2, f = 6, target = 7
    /// Output: 6
    /// Explanation: 
    /// You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
    /// 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
    ///
    /// Example 3:
    /// Input: d = 2, f = 5, target = 10
    /// Output: 1
    /// Explanation: 
    /// You throw two dice, each with 5 faces.  There is only one way to get a sum of 
    /// 10: 5+5.
    ///
    /// Example 4:
    /// Input: d = 1, f = 2, target = 3
    /// Output: 0
    /// Explanation: 
    /// You throw one die with 2 faces.  There is no way to get a sum of 3.
    ///
    /// Example 5:
    /// Input: d = 30, f = 30, target = 500
    /// Output: 222616187
    /// Explanation: 
    /// The answer must be returned modulo 10^9 + 7.
    ///
    /// Constraints:
    /// 1. 1 <= d, f <= 30
    /// 2. 1 <= target <= 1000
    /// </summary>
    int numRollsToTarget(int d, int f, int target);

    /// <summary>
    /// Leet code #1187. Make Array Strictly Increasing
    /// 
    /// Given two integer arrays arr1 and arr2, return the minimum number of 
    /// operations (possibly zero) needed to make arr1 strictly increasing.
    /// In one operation, you can choose two indices 0 <= i < arr1.length and 
    /// 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
    /// If there is no way to make arr1 strictly increasing, return -1.
    /// 
    /// Example 1:
    /// Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
    /// Output: 1
    /// Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
    ///
    /// Example 2:
    /// Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
    /// Output: 2
    /// Explanation: Replace 5 with 3 and then replace 3 with 4. 
    /// arr1 = [1, 3, 4, 6, 7].
    ///
    /// Example 3:
    /// Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
    /// Output: -1
    /// Explanation: You can't make arr1 strictly increasing.
    ///
    /// Constraints:
    /// 1. 1 <= arr1.length, arr2.length <= 2000
    /// 2. 0 <= arr1[i], arr2[i] <= 10^9
    /// </summary>
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2);

    /// <summary>
    /// Leet code #9905. Maximum Interest
    /// 
    /// There are a series of activities with [startTime, endTime, interest]. 
    /// Please arrange the activities to get the maximum total interest.
    ///
    /// Note: You can assume that
    ///
    /// 1. 0 <= startTime < endTime <= 500000
    /// 2. 1 <= interest <= 1000
    /// 
    /// Example 1:
    /// Input: activities = [0,3,1][0,5,5][5,6,1][6,18,2]
    /// Output: 8
    /// Explanation: with [0, 5, 5] => [5, 6, 1] => [6, 8, 2]
    /// 5 + 1 + 2 = 8
    ///
    /// Example 2:
    /// Input: activities = {{8, 9, 5}, {8, 12, 7}, {9, 12, 4}, {12, 14, 2}, 
    ///                      {13, 16, 3}, {14, 15, 4}};
    /// Output: 15
    /// Explanation: {8, 9, 5} => {9, 12 , 4} => {12, 14, 2} => {14, 15, 4}
    ///
    /// Example 3:
    /// Input: activities = {{8, 10, 3}, {9, 12, 2}, {12, 14, 1}}; 
    /// Output: 4
    /// Explanation: {8, 10, 3} => {12, 14, 1}
    /// </summary>
    int maxInterest(vector<vector<int>> activities);

    /// <summary>
    /// Leet code #562. Longest Line of Consecutive One in Matrix
    /// Given a 01 matrix M, find the longest line of consecutive one in the 
    /// matrix. The line could be horizontal, vertical, diagonal or 
    /// anti-diagonal. 
    /// 
    /// Example:
    /// 
    /// Input:
    /// [
    ///   [0,1,1,0],
    ///   [0,1,1,0],
    ///   [0,0,0,1]
    /// ]
    /// Output: 3
    /// Hint: The number of elements in the given matrix will not exceed 10,000. 
    /// </summary>
    int longestLine(vector<vector<int>>& M);

    /// <summary>
    /// Leet code #213. House Robber II
    /// 
    /// You are a professional robber planning to rob houses along a street. 
    /// Each house has a certain amount of money stashed. All houses at this 
    /// place are arranged in a circle. That means the first house is the 
    /// neighbor of the last one. Meanwhile, adjacent houses have security 
    /// system connected and it will automatically contact the police if two 
    /// adjacent houses were broken into on the same night.
    ///
    /// Given a list of non-negative integers representing the amount of money 
    /// of each house, determine the maximum amount of money you can rob 
    /// tonight without alerting the police.
    ///
    /// Example 1:
    ///
    /// Input: [2,3,2]
    /// Output: 3
    /// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 
    /// (money = 2), because they are adjacent houses.
    ///
    /// Example 2:
    /// 
    /// Input: [1,2,3,1]
    /// Output: 4
    /// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    /// Total amount you can rob = 1 + 3 = 4.
    /// </summary>
    int robII(vector<int>& nums);

    /// <summary>
    /// Leet code #118. Pascal's Triangle 
    /// Given numRows, generate the first numRows of Pascal's triangle.
    /// For example, given numRows = 5,
    ///
    /// Return 
    /// [
    ///     [1],
    ///    [1,1],
    ///   [1,2,1],
    ///  [1,3,3,1],
    /// [1,4,6,4,1]
    /// ]
    /// </summary>
    vector<vector<int>> generatePascalTriangle(int numRows);

    /// <summary>
    /// Leet code #119. Pascal's Triangle II 
    /// Given an index k, return the kth row of the Pascal's triangle.
    /// For example, given k = 3,
    /// Return [1,3,3,1]. 
    /// Note:
    /// Could you optimize your algorithm to use only O(k) extra space? 
    /// </summary>
    vector<int> getPascalTriangleRow(int rowIndex);

    /// <summary>
    /// Leet code #322. Coin Change 
    /// You are given coins of different denominations and a total amount 
    /// of money amount. Write a function to 
    /// compute the fewest number of coins that you need to make up that 
    /// amount. If that amount of money cannot 
    /// be made up by any combination of the coins, return -1. 	
    /// Example 1:
    /// coins = [1, 2, 5], amount = 11
    /// return 3 (11 = 5 + 5 + 1) 
    /// Example 2:
    /// coins = [2], amount = 3
    /// return -1. 
    /// Note:
    /// You may assume that you have an infinite number of each kind of coin. 
    /// </summary>
    int coinChange(vector<int>& coins, int amount);

    /// <summary>
    /// Leet code 91. Decode Ways 
    ///
    /// A message containing letters from A-Z is being encoded to numbers using 
    /// the following mapping:
    ///
    /// 'A' -> 1
    /// 'B' -> 2
    /// ...
    /// 'Z' -> 26
    /// Given a non-empty string containing only digits, determine the total 
    /// number of ways to decode it.
    ///
    /// Example 1:
    ///
    /// Input: "12"
    /// Output: 2
    /// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
    ///
    /// Example 2:
    ///
    /// Input: "226"
    /// Output: 3
    /// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" 
    /// (2 2 6).
    /// </summary>
    int numDecodings(string s);

    /// <summary>
    /// Leet code #576. Out of Boundary Paths
    /// 
    /// There is an m by n grid with a ball. Given the start coordinate (i,j) of 
    /// the ball, you can move the ball to adjacent cell or cross the grid boundary 
    /// in four directions (up, down, left, right). However, you can at most move N
    /// times. Find out the number of paths to move the ball out of grid boundary. 
    /// The answer may be very large, return it after mod 10^9 + 7.
    ///
    /// Example 1:
    /// Input:m = 2, n = 2, N = 2, i = 0, j = 0
    /// Output: 6
    /// Explanation:
    ///
    ///
    /// Example 2:
    /// Input:m = 1, n = 3, N = 3, i = 0, j = 1
    /// Output: 12
    /// Explanation:
    /// 
    /// Note:
    /// Once you move the ball out of boundary, you cannot move it back.
    /// The length and height of the grid is in range [1,50].
    /// N is in range [0,50].
    /// </summary>
    int findPaths(int m, int n, int N, int i, int j);

    /// <summary>
    /// Leet code #656. Coin Path
    /// 
    /// Given an array A (index starts at 1) consisting of N integers: A1, A2,
    ///	..., AN and an integer B. The integer B denotes that from any place 
    /// (suppose the index is i) in the array A, you can jump to any one of 
    /// the place in the array A indexed i+1, i+2, ¡­, i+B if this place can 
    /// be jumped to. Also, if you step on the index i, you have to pay Ai 
    /// coins. If Ai is -1, it means you can¡¯t jump to the place indexed i in 
    /// the array.
    ///
    /// Now, you start from the place indexed 1 in the array A, and your aim 
    /// is to reach the place indexed N using the minimum coins. You need to 
    /// return the path of indexes (starting from 1 to N) in the array you 
    /// should take to get to the place indexed N using minimum coins.
    /// 
    /// If there are multiple paths with the same cost, return the 
    /// lexicographically smallest such path.
    ///
    /// If it's not possible to reach the place indexed N then you need to 
    /// return an empty array.
    ///
    /// Example 1:
    /// Input: [1,2,4,-1,2], 2
    /// Output: [1,3,5]
    ///
    /// Example 2:
    /// Input: [1,2,4,-1,2], 1
    /// Output: []
    /// Note:
    /// Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, 
    /// ..., Pbm, if and only if at the first i where Pai and Pbi differ, 
    /// Pai < Pbi; when no such i exists, then n < m.
    /// A1 >= 0. A2, ..., AN (if exist) will in the range of [-1, 100].
    /// Length of A is in the range of [1, 1000].
    /// B is in the range of [1, 100].
    /// </summary>
    vector<int> cheapestJump(vector<int>& A, int B);

    /// <summary>
    /// Leet code #629. K Inverse Pairs Array
    /// 
    /// Given two integers n and k, find how many different arrays consist of 
    /// numbers from 1 to n such that there are exactly k inverse pairs. 
    /// We define an inverse pair as following: For ith and jth element in the 
    /// array, if i < j and a[i] > a[j] then it's an inverse pair; 
    /// Otherwise, it's not. 
    /// Since the answer may very large, the answer should be modulo 10^9 + 7.
    /// Example 1:
    /// Input: n = 3, k = 0
    /// Output: 1
    /// Explanation: 
    /// Only the array [1,2,3] which consists of numbers from 1 to 3 has 
    /// exactly 0 inverse pair.
    ///
    /// Example 2:
    /// Input: n = 3, k = 1
    /// Output: 2
    /// Explanation: 
    /// The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
    /// 
    /// Note:
    /// The integer n is in the range [1, 1000] and k is in the range 
    /// [0, 1000].
    /// </summary>
    int kInversePairs(int n, int k);

    /// <summary>
    /// Leet code #123. Best Time to Buy and Sell Stock III  
    ///
    /// Say you have an array for which the ith element is the price of a given 
    /// stock on day i.
    /// Design an algorithm to find the maximum profit. You may complete at most 
    /// two transactions.
    /// Note: You may not engage in multiple transactions at the same time 
    /// (i.e., you must sell the stock before you buy again).
    ///
    /// Example 1:
    /// Input: [3,3,5,0,0,3,1,4]
    /// Output: 6
    /// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), 
    ///              profit = 3-0 = 3. Then buy on day 7 (price = 1) and sell on 
    ///              day 8 (price = 4), profit = 4-1 = 3.
    ///
    /// Example 2:
    /// Input: [1,2,3,4,5]
    /// Output: 4
    /// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), 
    ///              profit = 5-1 = 4.
    ///
    /// Note that you cannot buy on day 1, buy on day 2 and sell them later, 
    /// as you are engaging multiple transactions at the same time. You must 
    /// sell before buying again.
    ///
    /// Example 3:
    /// Input: [7,6,4,3,1]
    /// Output: 0
    /// Explanation: In this case, no transaction is done, i.e. max profit = 0.
    /// </summary>
    int maxProfitTwoTxns(vector<int>& prices);

    /// <summary>
    /// Leet code #920. Number of Music Playlists
    /// 
    /// Your music player contains N different songs and she wants to listen to L 
    /// (not necessarily different) songs during your trip.  You create a playlist 
    /// so that:
    ///
    /// Every song is played at least once
    /// A song can only be played again only if K other songs have been played
    /// Return the number of possible playlists.  As the answer can be very large, 
    /// return it modulo 10^9 + 7.
    /// 
    /// 
    /// Example 1:
    /// Input: N = 3, L = 3, K = 1
    /// Output: 6
    /// Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], 
    /// [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
    ///
    /// Example 2:
    /// Input: N = 2, L = 3, K = 0
    /// Output: 6
    /// Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], 
    /// [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
    ///
    /// Example 3:
    /// Input: N = 2, L = 3, K = 1
    /// Output: 2
    /// Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
    ///  
    /// Note:
    /// 1. 0 <= K < N <= L <= 100
    /// </summary>
    int numMusicPlaylists(int N, int L, int K);

    /// <summary>
    /// Leet code #923. 3Sum With Multiplicity
    /// 
    /// Given an integer array A, and an integer target, return the number of 
    /// tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.
    ///
    /// As the answer can be very large, return it modulo 10^9 + 7.
    /// 
    //// Example 1:
    ///
    /// Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
    /// Output: 20
    /// Explanation: 
    /// Enumerating by the values (A[i], A[j], A[k]):
    /// (1, 2, 5) occurs 8 times;
    /// (1, 3, 4) occurs 8 times;
    /// (2, 2, 4) occurs 2 times;
    /// (2, 3, 3) occurs 2 times.
    ///
    /// Example 2:
    ///
    /// Input: A = [1,1,2,2,2,2], target = 5
    /// Output: 12
    /// Explanation: 
    /// A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
    /// We choose one 1 from [1,1] in 2 ways,
    /// and two 2s from [2,2,2,2] in 6 ways.
    /// 
    ///
    /// Note:
    /// 
    /// 1. 3 <= A.length <= 3000
    /// 2. 0 <= A[i] <= 100
    /// 3. 0 <= target <= 300
    /// </summary>
    int threeSumMulti(vector<int>& A, int target);

    /// <summary>
    /// Leet code #474. Ones and Zeroes
    ///
    /// In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
    /// For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, 
    /// there is an array with strings consisting of only 0s and 1s.
    /// Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. 
    /// Each 0 and 1 can be used at most once. 
    /// Note:
    /// The given numbers of 0s and 1s will both not exceed 100
    /// The size of given string array won't exceed 600.
    /// Example 1:
    /// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
    /// Output: 4
    ///
    /// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are "10,"0001","1","0"
    ///
    /// Example 2:
    /// Input: Array = {"10", "0", "1"}, m = 1, n = 1
    /// Output: 2
    ///
    /// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
    /// </summary>
    int findMaxOneZeroForm(vector<string>& strs, int m, int n);

    /// <summary>
    /// Leet code #377. Combination Sum IV 
    /// </summary>
    int combinationSum4II(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #377. Combination Sum IV 
    ///
    /// Given an integer array with all positive numbers and no duplicates, 
    /// find the number of possible combinations that add up to a positive integer target.
    /// 
    /// Example: 
    /// nums = [1, 2, 3]
    /// target = 4
    /// The possible combination ways are:
    /// (1, 1, 1, 1)
    /// (1, 1, 2)
    /// (1, 2, 1)
    /// (1, 3)
    /// (2, 1, 1)
    /// (2, 2)
    /// (3, 1)
    /// Note that different sequences are counted as different combinations.
    /// Therefore the output is 7.
    /// Follow up:
    /// What if negative numbers are allowed in the given array?
    /// How does it change the problem?
    /// What limitation we need to add to the question to allow negative numbers? 
    /// </summary>
    int combinationSum4(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1216. Valid Palindrome III
    /// 
    /// Given a string s and an integer k, find out if the given string is a 
    /// K-Palindrome or not.
    ///
    /// A string is K-Palindrome if it can be transformed into a palindrome 
    /// by removing at most k characters from it.
    ///
    /// Example 1:
    ///
    /// Input: s = "abcdeca", k = 2
    /// Output: true
    /// Explanation: Remove 'b' and 'e' characters.
    /// Constraints:
    /// 1. 1 <= s.length <= 1000
    /// 2. s has only lowercase English letters.
    /// 3. 1 <= k <= s.length
    /// </summary>
    bool isValidPalindrome(string s, int k);

    /// <summary>
    /// Leet code #1220. Count Vowels Permutation
    /// 
    /// Given an integer n, your task is to count how many strings of length n 
    /// can be formed under the following rules:
    ///
    /// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
    /// Each vowel 'a' may only be followed by an 'e'.
    /// Each vowel 'e' may only be followed by an 'a' or an 'i'.
    /// Each vowel 'i' may not be followed by another 'i'.
    /// Each vowel 'o' may only be followed by an 'i' or a 'u'.
    /// Each vowel 'u' may only be followed by an 'a'.
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: n = 1
    /// Output: 5
    /// Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
    ///
    /// Example 2:
    ///
    /// Input: n = 2
    /// Output: 10
    /// Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", 
    ///              "io", "iu", "oi", "ou" and "ua".
    /// Example 3: 
    ///
    /// Input: n = 5
    /// Output: 68
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 2 * 10^4
    /// </summary>
    int countVowelPermutation(int n);

    /// <summary>
    /// Leet code #1223. Dice Roll Simulation
    /// 
    /// A die simulator generates a random number from 1 to 6 for each roll. 
    /// You introduced a constraint to the generator such that it cannot roll 
    /// the number i more than rollMax[i] (1-indexed) consecutive times. 
    ///
    /// Given an array of integers rollMax and an integer n, return the number 
    /// of distinct sequences that can be obtained with exact n rolls.
    ///
    /// Two sequences are considered different if at least one element differs 
    /// from each other. Since the answer may be too large, return it 
    /// modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: n = 2, rollMax = [1,1,2,2,2,3]
    /// Output: 34
    /// Explanation: There will be 2 rolls of die, if there are no constraints 
    /// on the die, there are 6 * 6 = 36 possible combinations. In this case, 
    /// looking at rollMax array, the numbers 1 and 2 appear at most once 
    /// consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the 
    /// final answer is 36-2 = 34.
    ///
    /// Example 2:
    ///
    /// Input: n = 2, rollMax = [1,1,1,1,1,1]
    /// Output: 30
    ///
    /// Example 3:
    ///
    /// Input: n = 3, rollMax = [1,1,1,2,2,3]
    /// Output: 181
    ///  
    /// Constraints:
    /// 
    /// 1. 1 <= n <= 5000
    /// 2. rollMax.length == 6
    /// 3. 1 <= rollMax[i] <= 15
    /// </summary>
    int dieSimulator(int n, vector<int>& rollMax);

    /// <summary>
    /// Leet code #1230. Toss Strange Coins
    /// 
    /// You have some coins.  The i-th coin has a probability prob[i] of 
    /// facing heads when tossed.
    ///
    /// Return the probability that the number of coins facing heads equals 
    /// target if you toss every coin exactly once.
    /// 
    /// Example 1:
    ///
    /// Input: prob = [0.4], target = 1
    /// Output: 0.40000
    ///
    /// Example 2:
    ///
    /// Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
    /// Output: 0.03125
    ///
    /// Constraints:
    ///
    /// 1. 1 <= prob.length <= 1000
    /// 2. 0 <= prob[i] <= 1
    /// 3. 0 <= target <= prob.length
    /// 4. Answers will be accepted as correct if they are within 10^-5 of 
    ///    the correct answer.
    /// </summary>
    double probabilityOfHeads(vector<double>& prob, int target);

    /// <summary>
    /// Leet code #1235. Maximum Profit in Job Scheduling
    /// 
    /// We have n jobs, where every job is scheduled to be done from 
    /// startTime[i] to endTime[i], obtaining a profit of profit[i].
    ///
    /// You're given the startTime , endTime and profit arrays, you 
    /// need to output the maximum profit you can take such that 
    /// there are no 2 jobs in the subset with overlapping time range.
    ///
    /// If you choose a job that ends at time X you will be able to 
    /// start another job that starts at time X.
    ///
    /// Example 1:
    /// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], 
    /// profit = [50,10,40,70]
    /// Output: 120
    /// Explanation: The subset chosen is the first and fourth job. 
    /// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
    ///
    /// Example 2:
    /// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], 
    /// profit = [20,20,100,70,60]
    /// Output: 150
    /// Explanation: The subset chosen is the first, fourth and fifth job. 
    /// Profit obtained 150 = 20 + 70 + 60.
    ///
    /// Example 3:
    /// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
    /// Output: 6
    /// 
    /// Constraints:
    ///
    /// 1. 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
    /// 2. 1 <= startTime[i] < endTime[i] <= 10^9
    /// 3. 1 <= profit[i] <= 10^4
    /// </summary>
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);

    /// <summary>
    /// Leet code #1239. Maximum Length of a Concatenated String with 
    ///                  Unique Characters
    /// 
    /// Given an array of strings arr. String s is a concatenation of a 
    /// sub-sequence of arr which have unique characters.
    ///
    /// Return the maximum possible length of s.
    ///
    /// Example 1:
    ///
    /// Input: arr = ["un","iq","ue"]
    /// Output: 4
    /// Explanation: All possible concatenations are "","un","iq","ue","uniq" 
    /// and "ique".
    /// Maximum length is 4.
    ///
    /// Example 2:
    /// Input: arr = ["cha","r","act","ers"]
    /// Output: 6
    /// Explanation: Possible solutions are "chaers" and "acters".
    ///
    /// Example 3:
    ///
    /// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
    /// Output: 26
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 16
    /// 2. 1 <= arr[i].length <= 26
    /// 3. arr[i] contains only lower case English letters.
    /// </summary>
    int maxLength(vector<string>& arr);

    /// <summary>
    /// Leet code #1246. Palindrome Removal
    ///  
    /// Given an integer array arr, in one move you can select a palindromic 
    /// subarray arr[i], arr[i+1], ..., arr[j] where i <= j, and remove that 
    /// subarray from the given array. Note that after removing a subarray, 
    /// the elements on the left and on the right of that subarray move to fill 
    /// the gap left by the removal.
    ///
    /// Return the minimum number of moves needed to remove all numbers from 
    /// the array.
    /// 
    /// Example 1:
    ///
    /// Input: arr = [1,2]
    /// Output: 2
    ///
    /// Example 2:
    ///
    /// Input: arr = [1,3,4,1,5]
    /// Output: 3
    /// Explanation: Remove [4] then remove [1,3,1] then remove [5].
    ///  
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 100
    /// 2. 1 <= arr[i] <= 20
    /// </summary>
    int minimumMoves(vector<int>& arr);

    /// <summary>
    /// Leet code #1255. Maximum Score Words Formed by Letters
    ///  
    /// Given a list of words, list of  single letters (might be repeating) 
    /// and score of every character.
    ///
    /// Return the maximum score of any valid set of words formed by using 
    /// the given letters (words[i] cannot be used two or more times).
    ///
    /// It is not necessary to use all characters in letters and each letter 
    /// can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is 
    /// given by score[0], score[1], ... , score[25] respectively.
    /// 
    /// Example 1:
    ///
    /// Input: words = ["dog","cat","dad","good"], 
    /// letters = ["a","a","c","d","d","d","g","o","o"], 
    /// score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
    /// Output: 23
    /// Explanation:
    /// Score  a=1, c=9, d=5, g=3, o=2
    /// Given letters, we can form the words "dad" (5+1+5) and 
    /// "good" (3+2+2+5) with a score of 23.
    /// Words "dad" and "dog" only get a score of 21.
    ///
    /// Example 2:
    ///
    /// Input: words = ["xxxz","ax","bx","cx"], 
    /// letters = ["z","a","b","c","x","x","x"], 
    /// score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
    /// Output: 27
    /// Explanation:
    /// Score  a=4, b=4, c=4, x=5, z=10
    /// Given letters, we can form the words "ax" (4+5), "bx" (4+5) and 
    /// "cx" (4+5) with a score of 27.
    /// Word "xxxz" only get a score of 25.
    ///
    /// Example 3:
    ///
    /// Input: words = ["leetcode"], 
    /// letters = ["l","e","t","c","o","d"], 
    /// score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
    /// Output: 0
    /// Explanation:
    /// Letter "e" can only be used once.
    ///
    /// Constraints:
    ///
    /// 1. 1 <= words.length <= 14
    /// 2. 1 <= words[i].length <= 15
    /// 3. 1 <= letters.length <= 100
    /// 4. letters[i].length == 1
    /// 5. score.length == 26
    /// 6. 0 <= score[i] <= 10
    /// 7. words[i], letters[i] contains only lower case English letters.
    /// </summary>
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score);

    /// <summary>
    /// Leet code #1259. Handshakes That Don't Cross
    /// 
    /// You are given an even number of people num_people that stand around 
    /// a circle and each person shakes hands with someone else, so that 
    /// there are num_people / 2 handshakes total.
    ///
    /// Return the number of ways these handshakes could occur such that 
    /// none of the handshakes cross.
    ///
    /// Since this number could be very big, return the answer mod 10^9 + 7
    ///
    /// Example 1:
    /// 
    /// Input: num_people = 2
    /// Output: 1
    ///
    /// Example 2:
    ///
    /// Input: num_people = 4
    /// Output: 2
    /// Explanation: There are two ways to do it, the first way is 
    // [(1,2),(3,4)] and the second one is [(2,3),(4,1)].
    ///
    /// Example 3:
    ///
    /// Input: num_people = 6
    /// Output: 5
    ///
    /// Example 4:
    ///
    /// Input: num_people = 8
    /// Output: 14
    ///
    /// Constraints:
    /// 
    /// 1. 2 <= num_people <= 1000
    /// 2. num_people % 2 == 0
    /// </summary>
    int numberOfWays(int num_people);

    /// <summary>
    /// Leet code #1269. Number of Ways to Stay in the Same Place After 
    //  Some Steps
    /// 
    /// You have a pointer at index 0 in an array of size arrLen. At each step, 
    /// you can move 1 position to the left, 1 position to the right in the 
    /// array or stay in the same place  (The pointer should not be placed 
    /// outside the array at any time).
    ///
    /// Given two integers steps and arrLen, return the number of ways such 
    /// that your pointer still at index 0 after exactly steps steps.
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    ///
    /// Input: steps = 3, arrLen = 2
    /// Output: 4
    /// Explanation: There are 4 differents ways to stay at index 0 after 3 
    /// steps.
    /// Right, Left, Stay
    /// Stay, Right, Left
    /// Right, Stay, Left
    /// Stay, Stay, Stay
    /// Example 2:
    ///
    /// Input: steps = 2, arrLen = 4
    /// Output: 2
    /// Explanation: There are 2 differents ways to stay at index 0 after 2 steps
    /// Right, Left
    /// Stay, Stay
    /// Example 3:
    ///
    /// Input: steps = 4, arrLen = 2
    /// Output: 8
    ///
    /// Constraints:
    /// 1. 1 <= steps <= 500
    /// 2. 1 <= arrLen <= 10^6
    /// </summary>
    int numWays(int steps, int arrLen);

    /// <summary>
    /// Leetcode #1277. Count Square Submatrices with All Ones
    /// 
    /// Given a m * n matrix of ones and zeros, return how many square 
    /// submatrices have all ones.
    ///
    /// Example 1:
    ///
    /// Input: matrix =
    /// [
    ///   [0,1,1,1],
    ///   [1,1,1,1],
    ///   [0,1,1,1]
    /// ]
    /// Output: 15
    /// Explanation: 
    /// There are 10 squares of side 1.
    /// There are 4 squares of side 2.
    /// There is  1 square of side 3.
    /// Total number of squares = 10 + 4 + 1 = 15.
    ///
    /// Example 2:
    ///
    /// Input: matrix = 
    /// [
    ///   [1,0,1],
    ///   [1,1,0],
    ///   [1,1,0]
    /// ]
    /// Output: 7
    /// Explanation: 
    /// There are 6 squares of side 1.  
    /// There is 1 square of side 2. 
    /// Total number of squares = 6 + 1 = 7.
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 300
    /// 2. 1 <= arr[0].length <= 300
    /// 3. 0 <= arr[i][j] <= 1
    /// </summary>
    int countSquares(vector<vector<int>>& matrix);

    /// <summary>
    /// Leetcode #1278. Palindrome Partitioning III
    /// </summary>
    int palindromePartition(string s, vector<vector<int>>& dp_change, int first, int last);

    /// <summary>
    /// Leetcode #1278. Palindrome Partitioning III
    /// 
    /// You are given a string s containing lowercase letters and an 
    /// integer k. You need to :
    ///
    /// First, change some characters of s to other lowercase English 
    /// letters.
    /// Then divide s into k non-empty disjoint substrings such that each 
    /// substring is palindrome.
    /// Return the minimal number of characters that you need to change to 
    /// divide the string.
    ///
    /// Example 1:
    ///
    /// Input: s = "abc", k = 2
    /// Output: 1
    /// Explanation: You can split the string into "ab" and "c", and 
    /// change 1 character in "ab" to make it palindrome.
    ///
    /// Example 2:
    ///
    /// Input: s = "aabbc", k = 3
    /// Output: 0
    /// Explanation: You can split the string into "aa", "bb" and "c", all 
    /// of them are palindrome.
    ///
    /// Example 3:
    ///
    /// Input: s = "leetcode", k = 8
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= k <= s.length <= 100.
    /// 2. s only contains lowercase English letters.
    /// </summary>
    int palindromePartition(string s, int k);

    /// <summary>
    /// Leetcode #1289. Minimum Falling Path Sum II
    /// 
    /// Given a square grid of integers arr, a falling path with non-zero 
    /// shifts is a choice of exactly one element from each row of arr, such 
    /// that no two elements chosen in adjacent rows are in the same column.
    ///
    /// Return the minimum sum of a falling path with non-zero shifts.
    /// 
    /// Example 1:
    ///
    /// Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
    /// Output: 13
    /// Explanation: 
    /// The possible falling paths are:
    /// [1,5,9], [1,5,7], [1,6,7], [1,6,8],
    /// [2,4,8], [2,4,9], [2,6,7], [2,6,8],
    /// [3,4,8], [3,4,9], [3,5,7], [3,5,9]
    /// The falling path with the smallest sum is [1,5,7], so the answer is 13.
    ///
    /// Constraints:
    /// 1. 1 <= arr.length == arr[i].length <= 200
    /// 2. -99 <= arr[i][j] <= 99
    /// </summary>
    int minFallingPathSum(vector<vector<int>>& arr);

    /// <summary>
    /// Leetcode #1301. Number of Paths with Max Score
    ///
    /// Hard
    ///
    /// You are given a square board of characters. You can move on the board 
    /// starting at the bottom right square marked with the character 'S'.
    ///
    /// You need to reach the top left square marked with the character 'E'. 
    /// The rest of the squares are labeled either with a numeric 
    /// character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go
    /// up, left or up-left (diagonally) only if there is no obstacle there.
    ///
    /// Return a list of two integers: the first integer is the maximum sum 
    /// of numeric characters you can collect, and the second is the number 
    /// of such paths that you can take to get that maximum sum, taken modulo 
    /// 10^9 + 7.
    ///
    /// In case there is no path, return [0, 0].
    ///
    /// Example 1:
    /// Input: board = ["E23","2X2","12S"]
    /// Output: [7,1]
    /// Example 2:
    ///
    /// Input: board = ["E12","1X1","21S"]
    /// Output: [4,2]
    ///
    /// Example 3:
    ///
    /// Input: board = ["E11","XXX","11S"]
    /// Output: [0,0]
    /// 
    ///
    /// Constraints:
    ///
    /// 1. 2 <= board.length == board[i].length <= 100
    /// </summary>
    vector<int> pathsWithMaxScore(vector<string>& board);

    /// <summary>
    /// Leet code #1312. Minimum Insertion Steps to Make a String Palindrome
    /// 
    /// Hard
    ///
    /// Given a string s. In one step you can insert any character at any 
    /// index of the string.
    /// Return the minimum number of steps to make s palindrome.
    /// A Palindrome String is one that reads the same backward as well as 
    /// forward.
    /// 
    /// Example 1:
    /// Input: s = "zzazz"
    /// Output: 0
    /// Explanation: The string "zzazz" is already palindrome we don't need 
    /// any insertions.
    ///
    /// Example 2:
    /// Input: s = "mbadm"
    /// Output: 2
    /// Explanation: String can be "mbdadbm" or "mdbabdm".
    ///
    /// Example 3:
    /// Input: s = "leetcode"
    /// Output: 5
    /// Explanation: Inserting 5 characters the string becomes "leetcodocteel".
    ///
    /// Example 4:
    /// Input: s = "g"
    /// Output: 0
    ///
    /// Example 5:
    /// Input: s = "no"
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 500
    /// 2. All characters of s are lower case English letters.
    /// </summary>
    int minInsertions(string s);

    /// <summary>
    /// Leet code # 10. Regular Expression Matching
    /// 
    /// Implement regular expression matching with support for '.' and '*'.
    /// 
    /// '.' Matches any single character.
    /// '*' Matches zero or more of the preceding element.
    ///
    /// The matching should cover the entire input string (not partial).
    /// The function prototype should be:
    ///
    /// bool isMatchRegularExpression(const char *s, const char *p)
    ///
    /// Some examples:
    /// isMatch("aa","a")       -> false
    /// isMatch("aa","aa")      -> true
    /// isMatch("aaa","aa")     -> false
    /// isMatch("aa", "a*")     -> true
    /// isMatch("aa", ".*")     -> true
    /// isMatch("ab", ".*")     -> true
    /// isMatch("aab", "c*a*b") -> true
    /// </summary>
    bool isMatchRegularExpression(string s, string p);

    /// <summary>
    /// Leet code #44. Wildcard Matching   
    ///
    /// Implement wildcard pattern matching with support for '?' and '*'.  
    /// '?' Matches any single character.
    /// '*' Matches any sequence of characters (including the empty sequence).
    /// The matching should cover the entire input string (not partial).
    /// The function prototype should be:
    /// bool isWildcardMatch(const char *s, const char *p);
    /// Some examples:
    /// isWildcardMatch("aa","a") -> false
    /// isWildcardMatch("aa","aa") -> true
    /// isWildcardMatch("aaa","aa") -> false
    /// isWildcardMatch("aa", "*") -> true
    /// isWildcardMatch("aa", "a*") -> true
    /// isWildcardMatch("ab", "?*") -> true
    /// isWildcardMatch("aab", "c*a*b") -> false
    /// </summary>
    bool isWildcardMatch(string s, string p);

    /// <summary>
    /// Leet code #70. Climbing Stairs
    ///
    /// You are climbing a stair case. It takes n steps to reach to the top.
    /// Each time you can either climb 1 or 2 steps. In how many distinct ways 
    /// can you climb to the top? 
    /// </summary>
    int climbStairs(int n);

    /// <summary>
    /// Leet code #72. Edit Distance 
    ///
    /// Given two words word1 and word2, find the minimum number of steps 
    /// required to convert word1 to 
    /// word2. (each operation is counted as 1 step.) 
    /// You have the following 3 operations permitted on a word: 
    /// a) Insert a character
    /// b) Delete a character
    /// c) Replace a character
    /// </summary> 
    int minDistance(string word1, string word2);

    /// <summary>
    /// Leet code # 135. Candy
    /// 
    /// There are N children standing in a line. Each child is assigned a rating value.
    /// You are giving candies to these children subjected to the following requirements: 
    /// Each child must have at least one candy.
    /// Children with a higher rating get more candies than their neighbors.
    /// What is the minimum candies you must give?
    /// </summary>
    int candy(vector<int>& ratings);

    /// <summary>
    /// Leet code #115. Distinct Subsequences  
    ///
    /// Given a string S and a string T, count the number of distinct 
    /// subsequences of T in S.
    /// A subsequence of a string is a new string which is formed from the 
    /// original string by deleting some (can be none) 
    /// of the characters without disturbing the relative positions of the 
    /// remaining characters. (ie, "ACE" is a subsequence 
    /// of "ABCDE" while "AEC" is not). For example,
    ///   Here is an example:
    ///   S = "rabbbit", T = "rabbit" 
    /// </summary>
    int numDistinct(string s, string t);

    /// <summary>
    /// Leet code #55. Jump Game 
    ///
    /// Given an array of non-negative integers, you are initially positioned 
    /// at the first index of the array. 
    /// Each element in the array represents your maximum jump length at that 
    /// position. 
    /// Determine if you are able to reach the last index. 
    /// For example:
    /// A = [2,3,1,1,4], return true. 
    /// A = [3,2,1,0,4], return false. 
    /// </summary>
    bool canJump(vector<int>& nums);

    /// <summary>
    /// Leet code #62. Unique Paths 
    ///
    /// A robot is located at the top-left corner of a m x n grid (marked 
    /// 'Start' in the diagram below). 
    /// The robot can only move either down or right at any point in time. 
    /// The robot is trying to reach the bottom-right corner of the grid 
    /// (marked 'Finish' in the diagram below). 
    ///	How many possible unique paths are there?
    /// Above is a 3 x 7 grid. How many possible unique paths are there?  
    /// Note: m and n will be at most 100.
    /// </summary>
    int uniquePaths(int m, int n);

    /// <summary>
    /// Leet code #63. Unique Paths II  
    ///
    /// Follow up for "Unique Paths": 
    /// Now consider if some obstacles are added to the grids. How many unique 
    /// paths would there be? 
    /// An obstacle and empty space is marked as 1 and 0 respectively in the grid. 
    ///	For example,
    /// [
    ///   [0,0,0],
    ///   [0,1,0],
    ///   [0,0,0]
    /// ]
    /// There is one obstacle in the middle of a 3x3 grid as illustrated below.  
    /// The total number of unique paths is 2.
    /// Note: m and n will be at most 100.
    /// </summary>
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

    /// <summary>
    /// Leet code #64. Minimum Path Sum
    ///
    /// Given a m x n grid filled with non-negative numbers, find a path from 
    /// top left to bottom right 
    /// which minimizes the sum of all numbers along its path.
    ///	Note: You can only move either down or right at any point in time. 
    /// </summary>
    int minPathSum(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1139. Largest 1-Bordered Square
    /// 
    /// Given a 2D grid of 0s and 1s, return the number of elements in the 
    /// largest square subgrid that has all 1s on its border, or 0 if such 
    /// a subgrid doesn't exist in the grid.
    /// 
    /// Example 1:
    /// Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
    /// Output: 9
    ///
    /// Example 2:
    /// Input: grid = [[1,1,0,0]]
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= grid.length <= 100
    /// 2. 1 <= grid[0].length <= 100
    /// 3. grid[i][j] is 0 or 1
    /// </summary>
    int largest1BorderedSquare(vector<vector<int>>& grid);
};
#endif  // LeetCodeDP
