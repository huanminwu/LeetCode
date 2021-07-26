#pragma once
#ifndef LeetcodeMath_H
#define LeetCodeMath_H
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
/// The class is to implement some math solution 
/// </summary>
class LeetCodeMath
{
public:
    /// <summary>
    /// Leet code #6. ZigZag Conversion
    /// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
    ///  P   A   H   N
    ///  A P L S I I G
    ///  Y   I   R
    ///  And then read line by line : "PAHNAPLSIIGYIR"
    ///  Write the code that will take a string and make this conversion given a number of rows :
    /// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
    /// </summary>
    string convertZigZag(string s, int numRows);

    /// <summary>
    /// Leet code #7. Reverse Integer
    /// 
    /// Given a 32-bit signed integer, reverse digits of an integer.
    /// Example 1:
    /// Input: 123
    /// Output: 321
    ///
    /// Example 2:
    /// Input: -123
    /// Output: -321
    ///
    /// Example 3:
    /// Input: 120
    /// Output: 21
    /// Note:
    /// Assume we are dealing with an environment which could only store integers 
    /// within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose 
    /// of this problem, assume that your function returns 0 when the reversed 
    /// integer overflows.
    /// </summary>
    int reverse(int x);

    /// <summary>
    /// Leet code #8. String to Integer (atoi)
    /// 
    /// Implement atoi which converts a string to an integer.
    /// The function first discards as many whitespace characters as necessary 
    /// until the first non-whitespace character is found. Then, starting from 
    /// this character, takes an optional initial plus or minus sign followed 
    /// by as many numerical digits as possible, and interprets them as a 
    /// numerical value.
    /// The string can contain additional characters after those that form the 
    /// integral number, which are ignored and have no effect on the behavior of 
    /// this function.
    /// If the first sequence of non-whitespace characters in str is not a valid 
    /// integral number, or if no such sequence exists because either str is 
    /// empty or it contains only whitespace characters, no conversion is 
    /// performed.
    /// If no valid conversion could be performed, a zero value is returned.
    /// Note:
    /// Only the space character ' ' is considered as whitespace character.
    /// Assume we are dealing with an environment which could only store integers 
    /// within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the  
    /// numerical value is out of the range of representable values, 
    /// INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
    /// Example 1:
    /// Input: "42"
    /// Output: 42
    ///
    /// Example 2:
    /// Input: "   -42"
    /// Output: -42
    /// Explanation: The first non-whitespace character is '-', which is the minus 
    /// sign. Then take as many numerical digits as possible, which gets 42.
    ///
    /// Example 3:
    /// Input: "4193 with words"
    /// Output: 4193
    /// Explanation: Conversion stops at digit '3' as the next character is not a 
    /// numerical digit.
    ///
    /// Example 4:
    /// Input: "words and 987"
    /// Output: 0
    /// Explanation: The first non-whitespace character is 'w', which is not a 
    /// numerical digit or a +/- sign. Therefore no valid conversion could be 
    /// performed.
    ///
    /// Example 5:
    /// Input: "-91283472332"
    /// Output: -2147483648
    /// Explanation: The number "-91283472332" is out of the range of a 32-bit 
    /// signed integer. Thefore INT_MIN (−231) is returned.
    /// </summary>
    int myAtoi(string str);

    /// <summary>
    /// Leet code #9. Palindrome Number
    /// Determine whether an integer is a palindrome. Do this without extra space.
    /// </summary>
    bool isPalindrome(int x);

    /// <summary>
    /// Leet code #396. Rotate Function 
    ///
    /// Given an array of integers A and let n to be its length. 
    /// Assume Bk to be an array obtained by rotating the array A k positions clock-wise, 
    /// we define a "rotation function" F on A as follow:
    /// F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
    /// Calculate the maximum value of F(0), F(1), ..., F(n-1).
    /// Note:
    ///
    /// Example:
    ///
    /// A = [4, 3, 2, 6]
    /// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
    ///	F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
    /// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
    /// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
    /// So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
    /// </summary>
    int maxRotateFunction(vector<int>& A);

    /// <summary>
    /// Leet code #455. Assign Cookies 
    ///
    /// Assume you are an awesome parent and want to give your children some 
    /// cookies. But, you should give each child at most one cookie. Each 
    //// child i has a greed factor gi, which is the minimum size of a 
    /// cookie that the child will be content with; and each cookie j 
    /// has a size sj. If sj >= gi, we can assign the cookie j to the child i, 
    /// and the child i will be content. Your goal is to maximize the number 
    /// of your content children and output the maximum number. 
    /// Note:
    /// You may assume the greed factor is always positive. 
    /// You cannot assign more than one cookie to one child. 
    ///
    /// Example 1:
    /// Input: [1,2,3], [1,1]
    /// Output: 1
    /// Explanation: You have 3 children and 2 cookies. The greed factors 
    /// of 3 children are 1, 2, 3. 
    /// And even though you have 2 cookies, since their size is both 1, you 
    /// could only make the child whose greed factor is 1 content.
    /// You need to output 1.
    ///
    /// Example 2:
    /// Input: [1,2], [1,2,3]
    /// Output: 2
    /// Explanation: You have 2 children and 3 cookies. The greed factors of 2 
    /// children are 1, 2. 
    /// You have 3 cookies and their sizes are big enough to gratify all of 
    /// the children, 
    /// You need to output 2.
    /// </summary>
    int findContentChildren(vector<int>& g, vector<int>& s);

    /// <summary>
    /// Leet code #507. Perfect Number          
    /// 
    /// We define the Perfect Number is a positive integer that is equal to the 
    /// sum of all its positive divisors except itself. 
    /// Now, given an integer n, write a function that returns true when it is a 
    /// perfect number and false when it is not. 
    ///
    /// Example:
    ///
    /// Input: 28
    /// Output: True
    /// Explanation: 28 = 1 + 2 + 4 + 7 + 14
    /// </summary>
    bool checkPerfectNumber(int num);

    /// <summary>
    /// Leet code #537. Complex Number Multiplication       
    /// </summary>
    void parseComplexNumber(string str, pair<int, int>& complex);

    /// <summary>
    /// Leet code #537. Complex Number Multiplication       
    /// 
    /// Given two strings representing two complex numbers. 
    /// You need to return a string representing their multiplication. 
    /// Note i^2 = -1 according to the definition.
    ///
    /// Example 1:
    /// Input: "1+1i", "1+1i"
    /// Output: "0+2i"
    /// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need 
    /// convert it to the form of 0+2i.
    /// Example 2:
    /// Input: "1+-1i", "1+-1i"
    /// Output: "0+-2i"
    /// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need 
    /// convert it to the form of 0+-2i.
    /// Note:
    ///
    /// The input strings will not have extra blank.
    /// The input strings will be given in the form of a+bi, where the integer 
    /// a and b will both belong to the range of [-100, 100]. And the output 
    /// should be also in this form.	 
    /// </summary>
    string complexNumberMultiply(string a, string b);

    /// <summary>
    /// Leet code #564. Find the Closest Palindrome          
    /// 
    /// Given an integer n, find the closest integer (not including itself), which 
    /// is a palindrome. 
    /// The 'closest' is defined as absolute difference minimized between two 
    /// integers.
    /// Example 1:
    /// Input: "123"
    /// Output: "121"
    /// Note:
    /// 1.The input n is a positive integer represented by string, whose length will not exceed 18.
    /// 2.If there is a tie, return the smaller one as answer.
    /// </summary>
    string nearestPalindromic(string n);

    /// <summary>
    /// Leet code #592. Fraction Addition and Subtraction
    /// </summary>
    long long gcd(long long a, long long b);

    /// <summary>
    /// Leet code #592. Fraction Addition and Subtraction
    /// </summary>
    void parseFraction(string& expression, int& index, int& numerator, int& denominator);

    /// <summary>
    /// Leet code #592. Fraction Addition and Subtraction
    /// </summary>
    void addFraction(int n_a, int d_a, int n_b, int d_b, int& numerator, int& denominator);

    /// <summary>
    /// Leet code #592. Fraction Addition and Subtraction
    /// 
    /// Given a string representing an expression of fraction addition and 
    /// subtraction, you need to return the calculation result in string format. 
    /// The final result should be irreducible fraction. If your final result is 
    /// an integer, say 2, you need to change it to the format of fraction that 
    /// has denominator 1. So in this case, 2 should be converted to 2/1.
    /// Example 1:
    /// Input:"-1/2+1/2"
    /// Output: "0/1"
    /// 
    /// Example 2:
    /// Input:"-1/2+1/2+1/3"
    /// Output: "1/3"
    /// 
    /// Example 3:
    /// Input:"1/3-1/2"
    /// Output: "-1/6"
    ///
    /// Example 4:
    /// Input:"5/3+1/3"
    /// Output: "2/1"
    ///
    /// Note:
    /// 1.The input string only contains '0' to '9', '/', '+' and '-'. So does the 
    ///   output.
    /// 2. Each fraction (input and output) has format ±numerator/denominator. If 
    ///    the first input fraction or the output is positive, then '+' will be 
    ///    omitted.
    /// 3. The input only contains valid irreducible fractions, where the numerator
    ///    and denominator of each fraction will always be in the range [1,10]. If 
    ///    the denominator is 1, it means this fraction is actually an integer in a 
    ///    fraction format defined above.
    /// 4. The number of given fractions will be in the range [1,10].
    /// 5. The numerator and denominator of the final result are guaranteed to be 
    ///    valid and in the range of 32-bit int.
    /// </summary>
    string fractionAddition(string expression);

    /// <summary>
    /// Leet code #672. Bulb Switcher II 
    /// 
    /// There is a room with n lights which are turned on initially and 4 
    /// buttons on the wall. After performing exactly m unknown operations 
    /// towards buttons, you need to return how many different kinds of 
    /// status of the n lights could be.
    ///
    /// Suppose n lights are labeled as number [1, 2, 3 ..., n], function of 
    /// these 4 buttons are given below:
    ///
    /// Flip all the lights.
    /// Flip lights with even numbers.
    /// Flip lights with odd numbers.
    /// Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
    ///
    /// Example 1:
    /// Input: n = 1, m = 1.
    /// Output: 2
    /// Explanation: Status can be: [on], [off]
    ///
    /// Example 2:
    /// Input: n = 2, m = 1.
    /// Output: 3
    /// Explanation: Status can be: [on, off], [off, on], [off, off]
    ///
    /// Example 3:
    /// Input: n = 3, m = 1.
    /// Output: 4
    /// Explanation: Status can be: [off, on, off], [on, off, on], 
    /// [off, off, off], [off, on, on].
    /// Note: n and m both fit in range [0, 1000].
    /// </summary>
    int flipLights(int n, int m);

    /// <summary>
    /// Leet code #780. Reaching Points
    ///
    /// A move consists of taking a point (x, y) and transforming it to either
    /// (x, x+y) or (x+y, y).
    ///
    /// Given a starting point (sx, sy) and a target point (tx, ty), return 
    /// True if and only if a sequence of moves exists to transform the point 
    /// (sx, sy) to (tx, ty). Otherwise, return False.
    ///
    /// Examples:
    /// Input: sx = 1, sy = 1, tx = 3, ty = 5
    /// Output: True
    /// Explanation:
    /// One series of moves that transforms the starting point to the target is:
    /// (1, 1) -> (1, 2)
    /// (1, 2) -> (3, 2)
    /// (3, 2) -> (3, 5)
    ///
    /// Input: sx = 1, sy = 1, tx = 2, ty = 2
    /// Output: False
    ///
    /// Input: sx = 1, sy = 1, tx = 1, ty = 1
    /// Output: True
    ///
    /// Note:
    ///
    /// sx, sy, tx, ty will all be integers in the range [1, 10^9].
    /// </summary>
    bool reachingPoints(int sx, int sy, int tx, int ty);

    /// <summary>
    /// Leet code #878. Nth Magical Number
    /// 
    /// A positive integer is magical if it is divisible by either A or B.
    ///
    /// Return the N-th magical number.  Since the answer may be very large, 
    /// return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: N = 1, A = 2, B = 3
    /// Output: 2
    ///
    /// Example 2:
    /// Input: N = 4, A = 2, B = 3
    /// Output: 6
    ///
    /// Example 3:
    /// Input: N = 5, A = 2, B = 4
    /// Output: 10
    ///
    /// Example 4:
    /// Input: N = 3, A = 6, B = 4
    /// Output: 8
    ///
    /// Note:
    /// 1. 1 <= N <= 10^9
    /// 2. 2 <= A <= 40000
    /// 3. 2 <= B <= 40000
    /// </summary>
    int nthMagicalNumber(int N, int A, int B);

    /// <summary>
    /// Leet code #914. X of a Kind in a Deck of Cards
    /// 
    /// In a deck of cards, each card has an integer written on it.
    ///
    /// Return true if and only if you can choose X >= 2 such that it is possible 
    /// to split the entire deck into 1 or more groups of cards, where:
    ///
    /// Each group has exactly X cards.
    /// All the cards in each group have the same integer.
    /// 
    /// Example 1:
    ///
    /// Input: [1,2,3,4,4,3,2,1]
    /// Output: true
    /// Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
    ///
    /// Example 2:
    ///
    /// Input: [1,1,1,2,2,2,3,3]
    /// Output: false
    /// Explanation: No possible partition.
    ///
    /// Example 3:
    ///
    /// Input: [1]
    /// Output: false
    /// Explanation: No possible partition.
    ///
    /// Example 4:
    ///
    /// Input: [1,1]
    /// Output: true
    /// Explanation: Possible partition [1,1]
    ///
    /// Example 5:
    ///
    /// Input: [1,1,2,2,2,2]
    /// Output: true
    /// Explanation: Possible partition [1,1],[2,2],[2,2]
    ///
    /// Note:
    ///
    /// 1. 1 <= deck.length <= 10000
    /// 2. 0 <= deck[i] < 10000
    /// </summary>
    bool hasGroupsSizeX(vector<int>& deck);

    /// <summary>
    /// Leet code #932. Beautiful Array
    /// </summary>
    vector<int> beautifulArray(int N, unordered_map<int, vector<int>>& memo);

    /// <summary>
    /// Leet code #932. Beautiful Array
    /// 
    /// For some fixed N, an array A is beautiful if it is a permutation of the 
    /// integers 1, 2, ..., N, such that:
    ///
    /// For every i < j, there is no k with i < k < j such that 
    //// A[k] * 2 = A[i] + A[j].
    ///
    /// Given N, return any beautiful array A.  (It is guaranteed that one exists.)
    ///
    /// Example 1:
    /// Input: 4
    /// Output: [2,1,4,3]
    /// Example 2:
    /// 
    /// Input: 5
    /// Output: [3,1,2,5,4]
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= N <= 1000
    /// </summary>
    vector<int> beautifulArray(int N);

    /// <summary>
    /// Leet code #1118. Number of Days in a Month
    /// 
    /// Given a year Y and a month M, return how many days there are in that month.
    /// 
    /// Example 1:
    /// Input: Y = 1992, M = 7
    /// Output: 31
    ///
    /// Example 2:
    /// Input: Y = 2000, M = 2
    /// Output: 29
    /// Example 3:
    ///
    /// Input: Y = 1900, M = 2
    /// Output: 28
    /// 
    /// Note:
    /// 1. 1583 <= Y <= 2100
    /// 2. 1 <= M <= 12
    /// </summary>
    int numberOfDays(int Y, int M);

    /// <summary>
    /// Leet code #1131. Maximum of Absolute Value Expression
    /// 
    /// Given two arrays of integers with equal lengths, return the maximum 
    /// value of:
    ///
    /// |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
    ///
    /// where the maximum is taken over all 0 <= i, j < arr1.length.
    /// 
    ///  
    /// Example 1:
    /// Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
    /// Output: 13
    ///
    /// Example 2:
    /// Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
    /// Output: 20
    /// 
    /// Constraints:
    /// 1. 2 <= arr1.length == arr2.length <= 40000
    /// 2. -10^6 <= arr1[i], arr2[i] <= 10^6
    /// </summary>
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2);

    /// <summary>
    /// Leet code #1137. N-th Tribonacci Number
    /// 
    /// The Tribonacci sequence Tn is defined as follows: 
    ///
    /// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
    ///
    /// Given n, return the value of Tn.
    /// 
    /// Example 1:
    ///
    /// Input: n = 4
    /// Output: 4
    /// Explanation:
    /// T_3 = 0 + 1 + 1 = 2
    /// T_4 = 1 + 1 + 2 = 4
    ///
    /// Example 2:
    ///
    /// Input: n = 25
    /// Output: 1389537
    /// Constraints:
    /// 1. 0 <= n <= 37
    /// 2. The answer is guaranteed to fit within a 32-bit integer, 
    ///    ie. answer <= 2^31 - 1.
    /// </summary>
    int tribonacci(int n);

    /// <summary>
    /// Leet code #1134. Armstrong Number
    /// 
    /// The k-digit number N is an Armstrong number if and only if the k-th 
    /// power of each digit sums to N.
    ///
    /// Given a positive integer N, return true if and only if it is an 
    /// Armstrong number.
    ///
    /// Example 1:
    /// Input: 153
    /// Output: true
    /// Explanation: 
    /// 153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.
    ///
    /// Example 2:
    /// Input: 123
    /// Output: false
    /// Explanation: 
    /// 123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.
    /// 
    /// Note:
    /// 1. 1 <= N <= 10^8
    /// </summary>
    bool isArmstrong(int N);

    /// <summary>
    /// Leet code #1144. Decrease Elements To Make Array Zigzag
    /// 
    /// Given an array nums of integers, a move consists of choosing any 
    /// element and decreasing it by 1.
    ///
    /// An array A is a zigzag array if either:
    ///
    /// Every even-indexed element is greater than adjacent elements, 
    /// ie. A[0] > A[1] < A[2] > A[3] < A[4] > ... OR, every odd-indexed 
    /// element is greater than adjacent elements, ie. 
    /// A[0] < A[1] > A[2] < A[3] > A[4] < ...
    /// Return the minimum number of moves to transform the given array 
    /// nums into a zigzag array.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,2,3]
    /// Output: 2
    /// Explanation: We can decrease 2 to 0 or 3 to 1.
    ///
    /// Example 2:
    /// 
    /// Input: nums = [9,6,1,6,2]
    /// Output: 4
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 1000
    /// </summary>
    int movesToMakeZigzag(vector<int>& nums);

    /// <summary>
    /// Leet code #1154. Day of the Year
    /// 
    /// Given a string date representing a Gregorian calendar date formatted 
    /// as YYYY-MM-DD, return the day number of the year.
    /// Example 1:
    /// Input: date = "2019-01-09"
    /// Output: 9
    /// Explanation: Given date is the 9th day of the year in 2019.
    ///
    /// Example 2:
    /// Input: date = "2019-02-10"
    /// Output: 41
    ///
    /// Example 3:
    /// Input: date = "2003-03-01"
    /// Output: 60
    ///
    /// Example 4:
    /// Input: date = "2004-03-01"
    /// Output: 61
    ///  
    /// Constraints:
    /// 1. date.length == 10
    /// 2. date[4] == date[7] == '-', and all other date[i]'s are digits
    /// 3. date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
    /// </summary>
    int dayOfYear(string date);

    /// <summary>
    /// Leet code #553. Optimal Division
    /// 
    /// Given a list of positive integers, the adjacent integers will perform 
    /// the float division. For example, [2,3,4] -> 2 / 3 / 4.
    /// However, you can add any number of parenthesis at any position to 
    /// change the priority of operations. You should find out how to add 
    /// parenthesis to get the maximum result, and return the corresponding 
    /// expression in string format. Your expression should NOT contain 
    /// redundant parenthesis.
    /// Example:
    /// Input: [1000,100,10,2]
    /// Output: "1000/(100/10/2)"
    /// Explanation:
    /// 1000/(100/10/2) = 1000/((100/10)/2) = 200
    /// However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
    /// since they don't influence the operation priority. So you should return 
    /// "1000/(100/10/2)". 
    ///
    /// Other cases:
    /// 1000/(100/10)/2 = 50
    /// 1000/(100/(10/2)) = 50
    /// 1000/100/10/2 = 0.5
    /// 1000/100/(10/2) = 2
    /// Note: 
    /// 1. The length of the input array is [1, 10].
    /// 2. Elements in the given array will be in range [2, 1000].
    /// 3. There is only one optimal division for each test case.
    /// </summary>
    string optimalDivision(vector<int>& nums);

    /// <summary>
    /// Leet code #1175. Prime Arrangements
    /// 
    /// Return the number of permutations of 1 to n so that prime numbers are 
    /// at prime indices (1-indexed.)
    /// (Recall that an integer is prime if and only if it is greater than 1, 
    /// and cannot be written as a product of two positive integers both 
    /// smaller than it.)
    /// Since the answer may be large, return the answer modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 5
    /// Output: 12
    /// Explanation: For example [1,2,5,4,3] is a valid permutation, but 
    /// [5,2,3,4,1] is not because the prime number 5 is at index 1.
    ///
    /// Example 2:
    /// Input: n = 100
    /// Output: 682289015
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// </summary>
    int numPrimeArrangements(int n);

    /// <summary>
    /// Leet code #1185. Day of the Week
    /// 
    /// Given a date, return the corresponding day of the week for that date.
    /// The input is given as three integers representing the day, month and 
    /// year respectively.
    /// Return the answer as one of the following values {"Sunday", "Monday", 
    /// "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
    /// 
    /// Example 1:
    /// Input: day = 31, month = 8, year = 2019
    /// Output: "Saturday"
    ///
    /// Example 2:
    /// Input: day = 18, month = 7, year = 1999
    /// Output: "Sunday"
    ///
    /// Example 3:
    /// Input: day = 15, month = 8, year = 1993
    /// Output: "Sunday"
    /// 
    /// Constraints:
    /// The given dates are valid dates between the years 1971 and 2100.
    /// </summary>
    string dayOfTheWeek(int day, int month, int year);

    /// <summary>
    /// Leet code #1201. Ugly Number III
    /// 
    /// Write a program to find the n-th ugly number.
    /// Ugly numbers are positive integers which are divisible by a or b or c.
    /// 
    /// Example 1:
    /// Input: n = 3, a = 2, b = 3, c = 5
    /// Output: 4
    /// Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
    /// Example 2:
    /// Input: n = 4, a = 2, b = 3, c = 4
    /// Output: 6
    /// Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
    /// Example 3:
    /// Input: n = 5, a = 2, b = 11, c = 13
    /// Output: 10
    /// Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th 
    /// is 10.
    /// Example 4:
    /// Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
    /// Output: 1999999984
    /// 
    /// Constraints:
    /// 1. 1 <= n, a, b, c <= 10^9
    /// 2. 1 <= a * b * c <= 10^18
    /// 3. It's guaranteed that the result will be in range [1, 2 * 10^9]
    /// </summary>
    int nthUglyNumber(int n, int a, int b, int c);

    /// <summary>
    /// Leet code #1217. Play with Chips      
    ///
    /// There are some chips, and the i-th chip is at position chips[i].
    /// You can perform any of the two following types of moves any number of 
    /// times (possibly zero) on any chip:
    /// Move the i-th chip by 2 units to the left or to the right with a cost of 0.
    /// Move the i-th chip by 1 unit to the left or to the right with a cost of 1.
    /// There can be two or more chips at the same position initially.
    /// Return the minimum cost needed to move all the chips to the same position 
    /// (any position).
    /// 
    /// Example 1:
    /// Input: chips = [1,2,3]
    /// Output: 1
    /// Explanation: Second chip will be moved to positon 3 with cost 1. First 
    /// chip will be moved to position 3 with cost 0. Total cost is 1.
    /// Example 2:
    /// Input: chips = [2,2,2,3,3]
    /// Output: 2
    /// Explanation: Both fourth and fifth chip will be moved to position two 
    /// with cost 1. Total minimum cost will be 2.
    /// 
    /// Constraints:
    /// 1. 1 <= chips.length <= 100
    /// 2. 1 <= chips[i] <= 10^9
    /// </summary>
    int minCostToMoveChips(vector<int>& chips);

    /// <summary>
    /// Leet code #1227. Airplane Seat Assignment Probability
    /// 
    /// n passengers board an airplane with exactly n seats. The first 
    /// passenger has lost the ticket and picks a seat randomly. But 
    /// after that, the rest of passengers will:
    ///
    /// Take their own seat if it is still available, 
    /// Pick other seats randomly when they find their seat occupied 
    /// What is the probability that the n-th person can get his own seat?
    ///
    /// Example 1:
    /// Input: n = 1
    /// Output: 1.00000
    /// Explanation: The first person can only get the first seat.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 0.50000
    /// Explanation: The second person has a probability of 0.5 to get the 
    /// second seat (when first person gets the first seat).
    /// 
    /// 1. Constraints:
    /// 2. 1 <= n <= 10^5
    /// </summary>
    double nthPersonGetsNthSeat(int n);

    /// <summary>
    /// Leet code #1232. Check If It Is a Straight Line
    /// 
    /// You are given an array coordinates, coordinates[i] = [x, y], where 
    /// [x, y] represents the coordinate of a point. Check if these points 
    /// make a straight line in the XY plane.
    /// 
    /// Example 1:
    /// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    /// Output: true
    ///
    /// Example 2:
    /// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    /// Output: false
    /// 
    /// Constraints:
    /// 1. 2 <= coordinates.length <= 1000
    /// 2. coordinates[i].length == 2
    /// 3. -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    /// 4. coordinates contains no duplicate point.
    /// </summary>
    bool checkStraightLine(vector<vector<int>>& coordinates);

    /// <summary>
    /// Leet code #1250. Check If It Is a Good Array
    ///  
    /// Given an array nums of positive integers. Your task is to select some 
    /// subset of nums, multiply each element by an integer and add all these 
    /// numbers. The array is said to be good if you can obtain a sum of 1 from 
    /// the array by any possible subset and multiplicand.
    ///
    /// Return True if the array is good otherwise return False.
    ///
    /// Example 1:
    ///
    /// Input: nums = [12,5,7,23]
    /// Output: true
    /// Explanation: Pick numbers 5 and 7.
    /// 5*3 + 7*(-2) = 1
    ///
    /// Example 2:
    ///
    /// Input: nums = [29,6,10]
    /// Output: true
    /// Explanation: Pick numbers 29, 6 and 10.
    /// 29*1 + 6*(-3) + 10*(-1) = 1
    ///
    /// Example 3:
    /// 
    /// Input: nums = [3,6]
    /// Output: false
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    bool isGoodArray(vector<int>& nums);

    /// <summary>
    /// Leet code #1040. Moving Stones Until Consecutive II
    /// 
    /// On an infinite number line, the position of the i-th stone is given by 
    /// stones[i].  Call a stone an endpoint stone if it has the smallest or 
    /// largest position.
    ///
    /// Each turn, you pick up an endpoint stone and move it to an unoccupied 
    /// position so that it is no longer an endpoint stone.
    ///
    /// In particular, if the stones are at say, stones = [1,2,5], you cannot 
    /// move the endpoint stone at position 5, since moving it to any position 
    /// (such as 0, or 3) will still keep that stone as an endpoint stone.
    ///
    /// The game ends when you cannot make any more moves, ie. the stones are 
    /// in consecutive positions.
    ///
    /// When the game ends, what is the minimum and maximum number of moves that 
    /// you could have made?  Return the answer as an length 2 array: answer = 
    /// [minimum_moves, maximum_moves]
    ///
    /// Example 1:
    ///
    /// Input: [7,4,9]
    /// Output: [1,2]
    /// Explanation: 
    /// We can move 4 -> 8 for one move to finish the game.
    /// Or, we can move 9 -> 5, 4 -> 6 for two moves to finish the game.
    ///
    /// Example 2:
    ///
    /// Input: [6,5,4,3,10]
    /// Output: [2,3]
    /// We can move 3 -> 8 then 10 -> 7 to finish the game.
    /// Or, we can move 3 -> 7, 4 -> 8, 5 -> 9 to finish the game.
    /// Notice we cannot move 10 -> 2 to finish the game, because that would be 
    /// an illegal move.
    ///
    /// Example 3:
    ///
    /// Input: [100,101,104,102,103]
    /// Output: [0,0]
    /// Note:
    ///
    /// 1. 3 <= stones.length <= 10^4
    /// 2. 1 <= stones[i] <= 10^9
    /// 3. stones[i] have distinct values.
    /// </summary>
    vector<int> numMovesStonesII(vector<int>& stones);

    /// <summary>
    /// Leet code #1058. Minimize Rounding Error to Meet Target
    /// 
    /// Given an array of prices [p1,p2...,pn] and a target, round each price 
    /// pi to Roundi(pi) so that the rounded array [Round1(p1),Round2(p2)...,
    /// Roundn(pn)] sums to the given target. Each operation Roundi(pi) could 
    /// be either Floor(pi) or Ceil(pi).
    /// Return the string "-1" if the rounded array is impossible to sum to 
    /// target. Otherwise, return the smallest rounding error, which is 
    /// defined as Σ |Roundi(pi) - (pi)| for i from 1 to n, as a string with 
    /// three places after the decimal.
    ///
    /// Example 1:
    /// Input: prices = ["0.700","2.800","4.900"], target = 8
    /// Output: "1.000"
    /// Explanation: 
    /// Use Floor, Ceil and Ceil operations to get (0.7 - 0) + (3 - 2.8) + 
    /// (5 - 4.9) = 0.7 + 0.2 + 0.1 = 1.0 .
    /// 
    /// Example 2:
    /// Input: prices = ["1.500","2.500","3.500"], target = 10
    /// Output: "-1"
    /// Explanation: 
    /// It is impossible to meet the target.
    ///
    /// Note:
    /// 1. 1 <= prices.length <= 500.
    /// 2. Each string of prices prices[i] represents a real number which 
    ///    is between 0 and 1000 and has exactly 3 decimal places.
    /// 3. target is between 0 and 1000000.
    /// </summary>
    string minRoundError(vector<string>& prices, int target);

    /// <summary>
    /// Leet code #1085. Sum of Digits in the Minimum Number
    /// 
    /// Given an array A of positive integers, let S be the sum of the digits 
    /// of the minimal element of A.
    /// 
    /// Return 0 if S is odd, otherwise return 1.
    ///
    /// Example 1:
    ///
    /// Input: [34,23,1,24,75,33,54,8]
    /// Output: 0
    /// Explanation: 
    /// The minimal element is 1, and the sum of those digits is S = 1 
    /// which is odd, so the answer is 0.
    ///
    /// Example 2:
    ///
    /// Input: [99,77,33,66,55]
    /// Output: 1
    /// Explanation: 
    /// The minimal element is 33, and the sum of those digits is 
    /// S = 3 + 3 = 6 which is even, so the answer is 1.
    ///  
    /// Note:
    /// 1. 1 <= A.length <= 100
    /// 2. 1 <= A[i].length <= 100
    /// </summary>
    int sumOfDigits(vector<int>& A);

    /// <summary>
    /// Leet code #1088. Confusing Number II
    /// </summary>
    int confusingNumberII(string& str_n, int index, int leading, int is_last, vector<vector<int>>& cache);

    /// <summary>
    /// Leet code #1088. Confusing Number II
    /// 
    /// We can rotate digits by 180 degrees to form new digits. When 
    /// 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 
    /// respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they 
    /// become invalid.
    ///
    /// A confusing number is a number that when rotated 180 degrees 
    /// becomes a different number with each digit valid.(Note that the 
    /// rotated number can be greater than the original number.)
    ///
    /// Given a positive integer N, return the number of confusing numbers 
    /// between 1 and N inclusive.
    /// 
    /// Example 1:
    ///
    /// Input: 20
    /// Output: 6
    /// Explanation: 
    /// The confusing numbers are [6,9,10,16,18,19].
    /// 6 converts to 9.
    /// 9 converts to 6.
    /// 10 converts to 01 which is just 1.
    /// 16 converts to 91.
    /// 18 converts to 81.
    /// 19 converts to 61.
    ///
    /// Example 2:
    ///
    /// Input: 100
    /// Output: 19
    /// Explanation: 
    /// The confusing numbers are [6,9,10,16,18,19,60,61,66,68,80,81,86,89,
    /// 90,91,98,99,100].
    ///
    ///
    /// Note:
    ///
    ///  1. 1 <= N <= 10^9
    /// </summary>
    int confusingNumberII(int N);

    /// <summary>
    /// Leet code #1093. Statistics from a Large Sample
    /// 
    /// We sampled integers between 0 and 255, and stored the results in an 
    /// array count:  count[k] is the number of integers we sampled equal to k.
    ///
    /// Return the minimum, maximum, mean, median, and mode of the sample 
    /// respectively, as an array of floating point numbers.  The mode is 
    /// guaranteed to be unique.
    ///
    /// (Recall that the median of a sample is:
    ///
    /// The middle element, if the elements of the sample were sorted and the 
    /// number of elements is odd;
    /// The average of the middle two elements, if the elements of the sample 
    /// were sorted and the number of elements is even.)
    ///
    /// Example 1:
    ///
    /// Input: count = 
    /// [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0]
    /// Output: [1.00000,3.00000,2.37500,2.50000,3.00000]
    /// Example 2:
    /// Input: count = 
    /// [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0]
    /// Output: [1.00000,4.00000,2.18182,2.00000,1.00000]
    /// 
    /// Constraints:
    ///
    /// 1. count.length == 256
    /// 2. 1 <= sum(count) <= 10^9
    /// 3. The mode of the sample that count represents is unique.
    /// 4. Answers within 10^-5 of the true value will be accepted as correct.
    /// </summary>
    vector<double> sampleStats(vector<int>& count);

    /// <summary>
    /// Leet code #1103. Distribute Candies to People
    /// 
    /// We distribute some number of candies, to a row of n = num_people people 
    /// in the following way:
    ///
    /// We then give 1 candy to the first person, 2 candies to the second person, 
    /// and so on until we give n candies to the last person.
    ///
    /// Then, we go back to the start of the row, giving n + 1 candies to the 
    /// first person, n + 2 candies to the second person, and so on until we give 
    /// 2 * n candies to the last person.
    ///
    /// This process repeats (with us giving one more candy each time, and moving 
    /// to the start of the row after we reach the end) until we run out of 
    /// candies.  The last person will receive all of our remaining candies 
    /// (not necessarily one more than the previous gift).
    ///
    /// Return an array (of length num_people and sum candies) that represents the 
    /// final distribution of candies.
    ///
    /// Example 1:
    ///
    /// Input: candies = 7, num_people = 4
    /// Output: [1,2,3,1]
    ///
    /// Explanation:
    /// On the first turn, ans[0] += 1, and the array is [1,0,0,0].
    /// On the second turn, ans[1] += 2, and the array is [1,2,0,0].
    /// On the third turn, ans[2] += 3, and the array is [1,2,3,0].
    /// On the fourth turn, ans[3] += 1 (because there is only one candy left), and
    /// the final array is [1,2,3,1].
    ///
    /// Example 2:
    ///
    /// Input: candies = 10, num_people = 3
    /// Output: [5,2,3]
    /// Explanation: 
    /// On the first turn, ans[0] += 1, and the array is [1,0,0].
    /// On the second turn, ans[1] += 2, and the array is [1,2,0].
    /// On the third turn, ans[2] += 3, and the array is [1,2,3].
    /// On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
    ///  
    /// Constraints:
    /// 1. 1 <= candies <= 10^9
    /// 2. 1 <= num_people <= 1000
    /// </summary>
    vector<int> distributeCandies(int candies, int num_people);

    /// <summary>
    /// Leet code #66. Plus One
    ///  
    /// Given a non-empty array of digits representing a non-negative 
    /// integer, plus one to the integer.
    ///
    /// The digits are stored such that the most significant digit is at 
    /// the head of the list, and each element in the array contain a 
    /// single digit.
    ///
    /// You may assume the integer does not contain any leading zero, 
    /// except the number 0 itself.
    ///
    /// Example 1:
    ///
    /// Input: [1,2,3]
    /// Output: [1,2,4]
    /// Explanation: The array represents the integer 123.
    ///
    /// Example 2:
    ///
    /// Input: [4,3,2,1]
    /// Output: [4,3,2,2]
    /// Explanation: The array represents the integer 4321.
    /// </summary>
    vector<int> plusOne(vector<int>& digits);

    /// <summary>
    /// Leet code #258. Add Digits
    ///  
    /// Given a non-negative integer num, repeatedly add all its digits until
    /// the result has only one digit.
    ///
    /// Example:
    ///
    /// Input: 38
    /// Output: 2 
    /// Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
    ///              Since 2 has only one digit, return it.
    /// Follow up:
    /// Could you do it without any loop/recursion in O(1) runtime?
    /// </summary>
    int addDigits(int num);

    /// <summary>
    /// Leet code #335. Self Crossing
    ///  
    /// You are given an array x of n positive numbers. You start at 
    /// point (0,0) and moves x[0] metres to the north, then x[1] metres 
    /// to the west, x[2] metres to the south, x[3] metres to the east 
    /// and so on. In other words, after each move your direction changes 
    /// counter-clockwise.
    /// 
    /// Write a one-pass algorithm with O(1) extra space to determine, if 
    /// your path crosses itself, or not.
    ///
    /// Example 1:
    /// ┌───┐
    /// │   │
    /// └───┼──>
    ///     │
    /// 
    /// Input: [2,1,1,2]
    /// Output: true
    ///
    /// Example 2:
    /// ┌──────┐
    /// │      │
    /// │
    /// │
    /// └────────────>
    ///
    /// Input: [1,2,3,4]
    /// Output: false 
    /// 
    /// Example 3:
    /// ┌───┐
    /// │   │
    /// └───┼>
    ///
    /// Input: [1,1,1,1]
    /// Output: true 
    /// </summary>
    bool isSelfCrossing(vector<int>& x);

    /// <summary>
    /// Leet code #319. Bulb Switcher
    ///  
    /// There are n bulbs that are initially off. You first turn on all the 
    /// bulbs. Then, you turn off every second bulb. On the third round, 
    /// you toggle every third bulb (turning on if it's off or turning off 
    /// if it's on). For the i-th round, you toggle every i bulb. For the 
    /// n-th round, you only toggle the last bulb. Find how many bulbs are 
    /// on after n rounds.
    ///
    /// Example:
    /// 
    /// Input: 3
    /// Output: 1 
    /// Explanation: 
    /// At first, the three bulbs are [off, off, off].
    /// After first round, the three bulbs are [on, on, on].
    /// After second round, the three bulbs are [on, off, on].
    /// After third round, the three bulbs are [on, off, off]. 
    ///
    /// So you should return 1, because there is only one bulb is on.
    /// </summary>
    int bulbSwitch(int n);

    /// <summary>
    /// Leet code #29. Divide Two Integers
    ///  
    /// Given two integers dividend and divisor, divide two integers without 
    /// using multiplication, division and mod operator.
    ///
    /// Return the quotient after dividing dividend by divisor.
    ///
    /// The integer division should truncate toward zero.
    ///
    /// Example 1:
    ///
    /// Input: dividend = 10, divisor = 3
    /// Output: 3
    ///
    /// Example 2:
    ///
    /// Input: dividend = 7, divisor = -3
    /// Output: -2
    /// Note:
    /// Both dividend and divisor will be 32-bit signed integers.
    /// The divisor will never be 0.
    /// Assume we are dealing with an environment which could only store 
    /// integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
    /// For the purpose of this problem, assume that your function 
    /// returns 2^31 − 1 when the division result overflows.
    /// </summary>
    int divide(int dividend, int divisor);

    /// <summary>
    /// Leet code #149. Max Points on a Line
    ///  
    /// Given n points on a 2D plane, find the maximum number of points that 
    /// lie on the same straight line.
    ///
    /// Example 1:
    ///
    /// Input: [[1,1],[2,2],[3,3]]
    /// Output: 3
    /// Explanation:
    /// ^
    /// |
    /// |        o
    /// |     o
    /// |  o  
    /// +------------->
    /// 0  1  2  3  4
    ///
    /// Example 2:
    ///
    /// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
    /// Output: 4
    /// Explanation:
    /// ^
    /// |
    /// |  o
    /// |     o        o
    /// |        o
    /// |  o        o
    /// +------------------->
    /// 0  1  2  3  4  5  6
    /// NOTE: input types have been changed on April 15, 2019. Please reset 
    /// to default code definition to get new method signature.
    /// </summary>
    int maxPoints(vector<Point>& points);

    /// <summary>
    /// Leet code #172. Factorial Trailing Zeroes
    ///  
    /// Given an integer n, return the number of trailing zeroes in n!.
    ///
    /// Example 1:
    ///
    /// Input: 3
    /// Output: 0
    /// Explanation: 3! = 6, no trailing zero.
    ///
    /// Example 2:
    /// Input: 5
    /// Output: 1
    /// Explanation: 5! = 120, one trailing zero.
    /// Note: Your solution should be in logarithmic time complexity.
    /// </summary>
    int trailingZeroes(int n);

    /// <summary>
    /// Leet code #441. Arranging Coins 
    ///
    /// You have a total of n coins that you want to form in a staircase 
    /// shape, where every k-th row must have exactly k coins.
    /// Given n, find the total number of full staircase rows that can be 
    /// formed.
    /// n is a non-negative integer and fits within the range of a 32-bit 
    /// signed integer.
    ///
    /// Example 1: 
    /// n = 5
    /// The coins can form the following rows:
    /// #
    /// # #
    /// # #
    /// Because the 3rd row is incomplete, we return 2.
    /// 
    /// Example 2: 
    /// n = 8
    /// The coins can form the following rows:
    /// #
    /// # #
    /// # # #
    /// # #
    /// Because the 4th row is incomplete, we return 3.
    /// </summary>
    int arrangeCoins(int n);

    /// <summary>
    /// Leet code #1037. Valid Boomerang
    /// </summary>
    double distance(vector<int>& x, vector<int>& y);

    /// <summary>
    /// Leet code #1037. Valid Boomerang
    /// 
    /// A boomerang is a set of 3 points that are all distinct and not in a 
    /// straight line.
    ///
    /// Given a list of three points in the plane, return whether these points 
    /// are a boomerang.
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: [[1,1],[2,3],[3,2]]
    /// Output: true
    /// Example 2:
    ///
    /// Input: [[1,1],[2,2],[3,3]]
    /// Output: false
    ///  
    /// Note:
    /// 1. points.length == 3
    /// 2. points[i].length == 2
    /// 3. 0 <= points[i][j] <= 100
    /// </summary>
    bool isBoomerang(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1033. Moving Stones Until Consecutive
    /// 
    /// Three stones are on a number line at positions a, b, and c.
    ///
    /// Each turn, let's say the stones are currently at positions x, y, z with 
    /// x < y < z.  You pick up the stone at either position x or position z, and 
    /// move that stone to an integer position k, with x < k < z and k != y.
    ///
    /// The game ends when you cannot make any more moves, ie. the stones are in 
    /// consecutive positions.
    ///
    /// When the game ends, what is the minimum and maximum number of moves that 
    /// you could have made?  Return the answer as an length 2 array: answer = 
    /// [minimum_moves, maximum_moves]
    ///
    /// Example 1:
    /// Input: a = 1, b = 2, c = 5
    /// Output: [1, 2]
    /// Explanation: Move stone from 5 to 4 then to 3, or we can move it directly 
    /// to 3.
    ///
    /// Example 2:
    /// Input: a = 4, b = 3, c = 2
    /// Output: [0, 0]
    /// Explanation: We cannot make any moves.
    ///
    /// Note:
    /// 1. 1 <= a <= 100
    /// 2. 1 <= b <= 100
    /// 3. 1 <= c <= 100
    /// 4. a != b, b != c, c != a
    /// </summary>
    vector<int> numMovesStones(int a, int b, int c);

    /// <summary>
    /// Leet code #1015. Smallest Integer Divisible by K
    /// 
    /// Given a positive integer K, you need find the smallest positive integer 
    /// N such that N is divisible by K, and N only contains the digit 1.
    ///
    /// Return the length of N.  If there is no such N, return -1.
    ///
    /// Example 1:
    /// Input: 1
    /// Output: 1
    /// Explanation: The smallest answer is N = 1, which has length 1.
    ///
    /// Example 2:
    /// Input: 2
    /// Output: -1
    /// Explanation: There is no such positive integer N divisible by 2.
    ///
    /// Example 3:
    /// Input: 3
    /// Output: 3
    /// Explanation: The smallest answer is N = 111, which has length 3.
    /// 
    /// Note:
    ///
    /// 1 <= K <= 10^5
    /// </summary>
    int smallestRepunitDivByK(int K);

    /// <summary>
    /// Leet code #1256. Encode Number
    /// 
    /// Given a non-negative integer num, Return its encoding string.
    /// 
    /// The encoding is done by converting the integer to a string using 
    /// a secret function that you should deduce from the following table:
    ///
    /// Example 1:
    ///
    /// Input: num = 23
    /// Output: "1000"
    ///
    /// Example 2:
    ///
    /// Input: num = 107
    /// Output: "101100"
    /// </summary>
    string encode(int num);

    /// <summary>
    /// Leet code #1262. Greatest Sum Divisible by Three
    /// 
    /// Given an array nums of integers, we need to find the maximum possible 
    /// sum of elements of the array such that it is divisible by three.
    ///
    /// Example 1:
    ///
    /// Input: nums = [3,6,5,1,8]
    /// Output: 18
    /// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum 
    /// divisible by 3).
    ///
    /// Example 2:
    /// 
    /// Input: nums = [4]
    /// Output: 0
    /// Explanation: Since 4 is not divisible by 3, do not pick any number.
    ///
    /// Example 3:
    ///
    /// Input: nums = [1,2,3,4,4]
    /// Output: 12
    /// Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum 
    /// divisible by 3).
    ///
    ///
    /// Constraints:
    ///
    /// 1. 1 <= nums.length <= 4 * 10^4
    /// 2. 1 <= nums[i] <= 10^4
    /// </summary>
    int maxSumDivThree(vector<int>& nums);

    /// <summary>
    /// Leet code #292. Nim Game
    /// 
    /// You are playing the following Nim Game with your friend: There is 
    /// a heap of stones on the table, each time one of you take turns to 
    /// remove 1 to 3 stones. The one who removes the last stone will be 
    /// the winner. You will take the first turn to remove the stones.
    ///
    /// Both of you are very clever and have optimal strategies for the 
    /// game. Write a function to determine whether you can win the game 
    /// given the number of stones in the heap.
    ///
    /// Example:
    ///
    /// Input: 4
    /// Output: false 
    /// Explanation: If there are 4 stones in the heap, then you will never 
    /// win the game; No matter 1, 2, or 3 stones you remove, the last stone 
    /// will always be removed by your friend.
    /// </summary>
    bool canWinNim(int n);

    /// <summary>
    /// Leet code #273. Integer to English Words
    /// 
    /// Convert a non-negative integer to its english words representation. 
    /// Given input is guaranteed to be less than 231 - 1.
    ///
    /// Example 1:
    ///
    /// Input: 123
    /// Output: "One Hundred Twenty Three"
    ///
    /// Example 2:
    ///
    /// Input: 12345
    /// Output: "Twelve Thousand Three Hundred Forty Five"
    ///
    /// Example 3:
    ///
    /// Input: 1234567
    /// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred 
    /// Sixty Seven"
    ///
    /// Example 4:
    ///
    /// Input: 1234567891
    /// Output: "One Billion Two Hundred Thirty Four Million Five Hundred 
    /// Sixty Seven Thousand Eight Hundred Ninety One"
    /// </summary>
    string numberToWords(int num);

    /// <summary>
    /// Leet code #50. Pow(x, n) 
    /// 
    /// Implement pow(x, n), which calculates x raised to the power n (x^n).
    ///
    /// Example 1:
    /// 
    /// Input: 2.00000, 10
    /// Output: 1024.00000
    ///
    /// Example 2:
    ///
    /// Input: 2.10000, 3
    /// Output: 9.26100
    ///
    /// Example 3:
    ///
    /// Input: 2.00000, -2
    /// Output: 0.25000
    /// Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
    ///
    /// Note:
    ///
    /// 1. -100.0 < x < 100.0
    /// 2. n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
    /// </summary>
    double myPow(double x, int n);

    /// <summary>
    /// Leet code #223. Rectangle Area 
    /// 
    /// Find the total area covered by two rectilinear rectangles in a 2D 
    /// plane.
    ///
    /// Each rectangle is defined by its bottom left corner and top right 
    /// corner as shown in the figure.
    ///
    /// Rectangle Area
    ///
    /// Example:
    ///
    /// Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
    /// Output: 45
    /// Note:
    ///
    /// Assume that the total area is never beyond the maximum possible 
    /// value of int.
    /// </summary>
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);

    /// <summary>
    /// Leet code #43. Multiply Strings
    /// 
    /// Given two non-negative integers num1 and num2 represented as strings, 
    /// return the product of num1 and num2, also represented as a string.
    ///
    /// Example 1:
    /// Input: num1 = "2", num2 = "3"
    /// Output: "6"
    ///
    /// Example 2:
    ///
    /// Input: num1 = "123", num2 = "456"
    /// Output: "56088"
    ///
    /// Note:
    ///
    /// 1. The length of both num1 and num2 is < 110.
    /// 2. Both num1 and num2 contain only digits 0-9.
    /// 3. Both num1 and num2 do not contain any leading zero, except the number 
    ///    0 itself.
    /// 4. You must not use any built-in BigInteger library or convert the inputs 
    ///    to integer directly.
    /// </summary>
    string multiply(string num1, string num2);

    /// <summary>
    /// Leet code #365. Water and Jug Problem  
    ///
    /// You are given two jugs with capacities x and y litres. There is an 
    /// infinite amount of water supply available. 
    /// You need to determine whether it is possible to measure exactly z 
    //  litres using these two jugs.
    /// If z liters of water is measurable, you must have z liters of water 
    /// contained within one or both buckets by the end.
    /// Operations allowed: 
    /// Fill any of the jugs completely with water.
    /// Empty any of the jugs.
    /// Pour water from one jug into another till the other jug is completely 
    /// full or the first jug itself is empty.
    ///
    /// Example 1: (From the famous "Die Hard" example)
    /// Input: x = 3, y = 5, z = 4 
    /// Output: True
    /// 
    /// Example 2:
    /// Input: x = 2, y = 6, z = 5
    /// Output: False 	
    /// </summary>
    bool canMeasureWater(int x, int y, int z);

    /// <summary>
    /// Leet code #447. Number of Boomerangs  
    ///
    /// Given n points in the plane that are all pairwise distinct, a 
    /// "boomerang" is a tuple of points (i, j, k) 
    /// such that the distance between i and j equals the distance between 
    /// i and k (the order of the tuple matters).
    ///
    /// Find the number of boomerangs. You may assume that n will be at 
    /// most 500 and coordinates of points are all in the 
    /// range [-10000, 10000] (inclusive).
    ///
    /// Example:
    ///
    /// Input:
    /// [[0,0],[1,0],[2,0]]
    /// Output:
    /// 2
    /// Explanation:
    /// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
    /// </summary>
    int numberOfBoomerangs(vector<pair<int, int>>& points);

    /// <summary>
    /// Leet code #372. Super Pow 
    ///
    /// Your task is to calculate a^b mod 1337 where a is a positive integer 
    /// and b is an extremely large 
    /// positive integer given in the form of an array.  
    ///
    /// Example1: 
    /// a = 2
    /// b = [3]
    /// Result: 8
    /// 
    /// Example2: 
    /// a = 2
    /// b = [1,0]
    /// Result: 1024
    /// </summary>
    int superPow(int a, vector<int>& b);

    /// <summary>
    /// Leet code #356. Line Reflection       
    /// 
    /// Given n points on a 2D plane, find if there is such a line parallel 
    /// to y-axis that reflect the given points.
    ///
    /// Example 1:
    /// Given points = [[1,1],[-1,1]], return true. 
    ///
    /// Example 2:
    /// Given points = [[1,1],[-1,-1]], return false. 
    /// Follow up:
    /// Could you do better than O(n2)? 
    /// Hint:
    /// 1.Find the smallest and largest x-value for all points.
    /// 2.If there is a line then it should be at y = (minX + maxX) / 2.
    /// 3.For each point, make sure that it has a reflected point in the 
    ///   opposite side.
    /// </summary>
    bool isReflected(vector<pair<int, int>>& points);

    /// <summary>
    /// Leet code #469. Convex Polygon 
    /// determinant of 2x2 matrix [point1-point0, point2-point0]
    /// </summary>
    long det2(vector<int>& point0, vector<int>& point1, vector<int>& point2);

    /// <summary>
    /// Leet code #469. Convex Polygon       
    /// 
    /// Given a list of points that form a polygon when joined sequentially, 
    /// find if this polygon is convex 
    /// (Convex polygon definition).
    /// 
    /// Note: 
    /// 1.There are at least 3 and at most 10,000 points.
    /// 2.Coordinates are in the range -10,000 to 10,000.
    /// 3.You may assume the polygon formed by given points is always a simple 
    ///   polygon 
    /// (Simple polygon definition). In other words, we ensure that exactly 
    /// two edges intersect at each vertex, and that edges otherwise don't 
    /// intersect each other. 
    ///
    /// Example 1: 
    /// [[0,0],[0,1],[1,1],[1,0]]
    ///
    /// Answer: True
    /// Example 2: 
    /// [[0,0],[0,10],[10,10],[10,0],[5,5]]
    /// Answer: False
    /// </summary>
    /// Great solution inspired by @Ipeq1! Here is a C++ version with 
    /// extracted determinant calculation.
    /// The key observation for convexity is that vector pi+1-pi always 
    /// turns to the same direction 
    /// to pi+2-pi formed by any 3 sequentially adjacent vertices, i.e., 
    /// cross product (pi+1-pi) x (pi+2-pi) 
    /// does not change sign when traversing sequentially along polygon 
    /// vertices.
    /// Note that for any 2D vectors v1, v2,
    /// v1 x v2 = det([v1, v2])
    /// which is the determinant of 2x2 matrix [v1, v2]. And the sign of 
    /// det([v1, v2]) represents 
    /// the positive z-direction of right-hand system from v1 to v2. 
    /// So det([v1, v2]) ≥ 0 
    /// if and only if v1 turns at most 180 degrees counterclockwise to v2.
    bool isConvex(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #483. Smallest Good Base       
    /// </summary>
    unsigned long long sumBase(unsigned long long base, int digits);

    /// <summary>
    /// Leet code #483. Smallest Good Base       
    /// 
    /// For an integer n, we call k>=2 a good base of n, if all digits of n 
    /// base k are 1. 
    /// Now given a string representing n, you should return the smallest 
    /// good base of n 
    /// in string format.
    /// 
    /// Example 1: 
    /// Input: "13"
    /// Output: "3"
    /// Explanation: 13 base 3 is 111.
    /// 
    /// Example 2:
    /// Input: "4681" 
    /// Output: "8"
    /// Explanation: 4681 base 8 is 11111.
    /// 
    ///
    /// Example 3:
    /// Input: "1000000000000000000" 
    /// Output: "999999999999999999"
    /// Explanation: 1000000000000000000 base 999999999999999999 is 11.
    /// Note:
    /// 1.The range of n is [3, 10^18].
    /// 2.The string representing n is always valid and will not have 
    ///   leading zeros.
    /// </summary>
    string smallestGoodBase(string n);

    /// <summary>
    /// Leet code #360. Sort Transformed Array        
    /// 
    /// Given a sorted array of integers nums and integer values a, b and c. 
    /// Apply a function of the form f(x) = ax2 + bx + c to each element x in 
    /// the array.  
    /// The returned array must be in sorted order. 
    /// Expected time complexity: O(n) 
    ///
    /// Example:
    /// nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5, 
    /// Result: [3, 9, 15, 33]
    /// 
    /// nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5. 
    /// Result: [-23, -5, 1, 7]
    /// </summary>
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c);

    /// <summary>
    /// Leet code #343. Integer Break
    /// 
    /// Given a positive integer n, break it into the sum of at least two 
    /// positive integers and maximize the product of those integers. 
    /// Return the maximum product you can get.
    ///
    /// Example 1:
    ///
    /// Input: 2
    /// Output: 1
    /// Explanation: 2 = 1 + 1, 1 × 1 = 1.
    ///
    /// Example 2:
    ///
    /// Input: 10
    /// Output: 36
    /// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
    /// Note: You may assume that n is not less than 2 and not larger than 58.
    /// </summary>
    int integerBreak(int n);

    /// <summary>
    /// Leet code #38. Count and Say 
    ///
    /// The count-and-say sequence is the sequence of integers beginning as follows:
    /// 1, 11, 21, 1211, 111221, ...  
    /// 1 is read off as "one 1" or 11. 
    /// 11 is read off as "two 1s" or 21.
    /// 21 is read off as "one 2, then one 1" or 1211.
    /// Given an integer n, generate the nth sequence.	
    /// Note: The sequence of integers will be represented as a string. 
    /// </summary>
    string countAndSay(int n);

    /// <summary>
    /// Leet code #391. Perfect Rectangle
    ///
    /// Given N axis-aligned rectangles where N > 0, determine if they all 
    /// together form an exact cover of a rectangular region. 
    /// Each rectangle is represented as a bottom-left point and a top-right point. 
    /// For example, a unit square is represented as [1,1,2,2]. 
    /// (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)). 
    /// Example 1: 
    /// rectangles = 
    /// [
    ///   [1,1,3,3],
    ///   [3,1,4,2],
    ///   [3,2,4,4],
    ///   [1,3,2,4],
    ///   [2,3,3,4]
    /// ]
    /// Return true. All 5 rectangles together form an exact cover of a 
    /// rectangular region.
    /// Example 2: 
    /// rectangles = 
    /// [
    ///   [1,1,2,3],
    ///   [1,3,2,4],
    ///   [3,1,4,2],
    ///   [3,2,4,4]
    /// ]
    /// Return false. Because there is a gap between the two rectangular regions.
    /// Example 3: 
    /// rectangles = 
    /// [
    ///   [1,1,3,3],
    ///   [3,1,4,2],
    ///   [1,3,2,4],
    ///   [3,2,4,4]
    /// ]
    /// Return false. Because there is a gap in the top center.
    /// Example 4: 
    /// rectangles = 
    /// [
    ///   [1,1,3,3],
    ///   [3,1,4,2],
    ///   [1,3,2,4],
    ///   [2,2,4,4]
    /// ]
    /// Return false. Because two of the rectangles overlap with each other.
    /// </summary>
    bool isRectangleCover(vector<vector<int>>& rectangles);

    /// <summary>
    /// Leet code #458. Poor Pigs
    /// 
    /// There are 1000 buckets, one and only one of them is poisonous, while 
    /// the rest are filled with water. They all look identical. If a pig 
    /// drinks the poison it will die within 15 minutes. What is the minimum 
    /// amount of pigs you need to figure out which bucket is poisonous within 
    /// one hour?
    /// 
    /// Answer this question, and write an algorithm for the general case.
    ///
    /// General case:
    ///
    /// If there are n buckets and a pig drinking poison will die within m 
    /// minutes, how many pigs (x) you need to figure out the poisonous bucket 
    /// within p minutes? There is exactly one bucket with poison.
    ///
    /// Note:
    ///
    /// A pig can be allowed to drink simultaneously on as many buckets as one 
    /// would like, and the feeding takes no time.
    /// After a pig has instantly finished drinking buckets, there has to be a 
    /// cool down time of m minutes. During this time, only observation is 
    /// allowed and no feedings at all.
    /// Any given bucket can be sampled an infinite number of times 
    /// (by an unlimited number of pigs).
    /// </summary>
    int poorPigs(int buckets, int minutesToDie, int minutesToTest);

    /// <summary>
    /// Leet code #492. Construct the Rectangle       
    /// 
    /// For a web developer, it is very important to know how to design a 
    /// web page's size. 
    /// So, given a specific rectangular web page’s area, your job by now is 
    /// to design a rectangular web page, whose length L and width W satisfy 
    /// the following requirements:
    ///
    /// 1. The area of the rectangular web page you designed must equal to the 
    ///    given target area.
    /// 2. The width W should not be larger than the length L, which 
    ///    means L >= W.
    ///	3. The difference between length L and width W should be as small as 
    ///   possible.
    /// 
    /// You need to output the length L and the width W of the web page you 
    /// designed in sequence. 
    ///
    /// Example:
    /// 
    /// Input: 4
    /// Output: [2, 2]
    /// Explanation: The target area is 4, and all the possible ways to 
    /// construct it are [1,4], [2,2], [4,1]. 
    /// But according to requirement 2, [1,4] is illegal; according to 
    /// requirement 3, [4,1] is not optimal compared to [2,2]. So the length L 
    /// is 2, and the width W is 2.
    ///
    /// Note:
    /// 1.The given area won't exceed 10,000,000 and is a positive integer
    /// 2.The web page's width and length you designed must be positive integers.
    /// </summary>
    vector<int> constructRectangle(int area);

    /// <summary>
    /// Leet code #504. Base 7         
    /// 
    /// Given an integer, return its base 7 string representation.
    /// Example 1:
    /// Input: 100
    /// Output: "202"
    ///
    /// Example 2:
    /// Input: -7
    /// Output: "-10"
    ///
    /// Note: The input will be in range of [-1e7, 1e7]. 
    /// </summary>
    string convertToBase7(int num);

    /// <summary>
    /// Leet code #509. Fibonacci Number
    /// 
    /// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the 
    /// Fibonacci sequence, such that each number is the sum of the two preceding 
    /// ones, starting from 0 and 1. That is,
    ///
    /// F(0) = 0,   F(1) = 1
    /// F(N) = F(N - 1) + F(N - 2), for N > 1.
    /// Given N, calculate F(N).
    ///
    /// Example 1:
    ///
    /// Input: 2
    /// Output: 1
    /// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
    ///
    /// Example 2:
    /// Input: 3
    /// Output: 2
    /// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
    ///
    /// Example 3:
    /// Input: 4
    /// Output: 3
    /// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
    ///  
    /// Note:
    /// 1. 0 ≤ N ≤ 30.
    /// </summary>
    int fib(int N);

    /// <summary>
    /// Leet code #587. Erect the Fence          
    /// </summary>
    int orientation(Point p, Point q, Point r);

    /// <summary>
    /// Leet code #587. Erect the Fence          
    /// 
    /// There are some trees, where each tree is represented by (x,y) coordinate 
    /// in a two-dimensional garden. Your job is to fence the entire garden 
    /// using the minimum length of rope as it is expensive. The garden is well 
    /// fenced only if all the trees are enclosed. Your task is to help find the 
    /// coordinates of trees which are exactly located on the fence perimeter.
    ///
    /// Example 1:
    /// Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
    /// Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
    /// Explanation:
    ///
    /// Example 2:
    /// Input: [[1,2],[2,2],[4,2]]
    /// Output: [[1,2],[2,2],[4,2]]
    /// Explanation:
    ///
    /// Even you only have trees in a line, you need to use rope to enclose them. 
    ///
    /// Note: 
    /// 1. All trees should be enclosed together. You cannot cut the rope to enclose 
    ///    trees that will separate them in more than one group.
    /// 2. All input integers will range from 0 to 100. 
    /// 3. The garden has at least one tree. 
    /// 4. All coordinates are distinct. 
    /// 5. Input points have NO order. No order required for output.
    /// </summary>
    vector<Point> outerTrees(vector<Point>& points);

    /// <summary>
    /// Leet code #593. Valid Square 
    /// </summary>
    int distance_square(vector<int>& p1, vector<int>& p2);

    /// <summary>
    /// Leet code #593. Valid Square 
    ///
    /// Given the coordinates of four points in 2D space, return whether the 
    /// four points could construct a square.
    /// The coordinate (x,y) of a point is represented by an integer array 
    /// with two integers.
    ///
    /// Example:
    /// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
    /// Output: True
    /// Note:
    /// All the input integers are in the range [-10000, 10000].
    /// A valid square has four equal sides with positive length and four 
    /// equal angles (90-degree angles).
    /// Input points have no order.
    /// </summary>
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4);

    /// <summary>
    /// Leet code #611. Valid Triangle Number
    /// 
    /// Given an array consists of non-negative integers, your task is to 
    /// count the number of triplets chosen from the array that can make 
    /// triangles if we take them as side lengths of a triangle. 
    ///
    /// Example 1:
    ///
    /// Input: [2,2,3,4]
    /// Output: 3
    /// Explanation:
    /// Valid combinations are: 
    /// 2,3,4 (using the first 2)
    /// 2,3,4 (using the second 2)
    /// 2,2,3
    /// Note:
    /// 1.The length of the given array won't exceed 1000.
    /// 2.The integers in the given array are in the range of [0, 1000].
    /// </summary>
    int triangleNumber(vector<int>& nums);

    /// <summary>
    /// Leet code #812. Largest Triangle Area
    /// 
    /// You have a list of points in the plane. Return the area of the largest 
    /// triangle that can be formed by any 3 of the points.
    /// 
    /// Example:
    /// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    /// Output: 2
    /// Explanation: 
    /// The five points are show in the figure below. The red triangle is the 
    /// largest.
    ///
    /// Notes:
    /// 1. 3 <= points.length <= 50.
    /// 2. No points will be duplicated.
    /// 3. -50 <= points[i][j] <= 50.
    /// 4. Answers within 10^-6 of the true value will be accepted as correct.
    /// </summary>
    double largestTriangleArea(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #858. Mirror Reflection
    /// 
    /// There is a special square room with mirrors on each of the four walls.  
    /// Except for the southwest corner, there are receptors on each of the 
    /// remaining corners, numbered 0, 1, and 2.
    ///
    /// The square room has walls of length p, and a laser ray from the southwest 
    /// corner first meets the east wall at a distance q from the 0th receptor.
    ///
    /// Return the number of the receptor that the ray meets first.  (It is 
    /// guaranteed that the ray will meet a receptor eventually.)
    ///
    /// Example 1:
    ///
    /// Input: p = 2, q = 1
    /// Output: 2
    /// Explanation: The ray meets receptor 2 the first time it gets reflected 
    /// back to the left wall.
    ///
    /// Note:
    /// 1. 1 <= p <= 1000
    /// 2. 0 <= q <= p
    /// </summary>
    int mirrorReflection(int p, int q);

    /// <summary>
    /// Leet code #866. Prime Palindrome
    /// </summary>
    bool isPrime(int N);

    /// <summary>
    /// Leet code #866. Prime Palindrome
    /// 
    /// Find the smallest prime palindrome greater than or equal to N.
    ///
    /// Recall that a number is prime if it's only divisors are 1 and itself, 
    /// and it is greater than 1. 
    ///
    /// For example, 2,3,5,7,11 and 13 are primes.
    ///
    /// Recall that a number is a palindrome if it reads the same from left 
    /// to right as it does from right to left. 
    ///
    /// For example, 12321 is a palindrome.
    ///
    /// Example 1:
    /// Input: 6
    /// Output: 7
    ///
    /// Example 2:
    /// Input: 8
    /// Output: 11
    ///
    /// Example 3:
    /// Input: 13
    /// Output: 101
    ///
    /// Note:
    /// 
    /// 1. 1 <= N <= 10^8
    /// 2. The answer is guaranteed to exist and be less than 2 * 10^8.
    /// </summary>
    int primePalindrome(int N);

    /// <summary>
    /// Leet code #869. Reordered Power of 2
    /// 
    /// Starting with a positive integer N, we reorder the digits in any order 
    /// (including the original order) such that the leading digit is not zero.
    ///
    /// Return true if and only if we can do this in a way such that the 
    /// resulting number is a power of 2.
    ///
    /// Example 1:
    /// Input: 1
    /// Output: true
    ///
    /// Example 2:
    /// Input: 10
    /// Output: false
    ///
    /// Example 3:
    /// Input: 16
    /// Output: true
    ///
    /// Example 4:
    /// Input: 24
    /// Output: false
    ///
    /// Example 5:
    /// Input: 46
    /// Output: true
    ///  
    /// Note:
    /// 1. 1 <= N <= 10^9
    /// </summary>
    bool reorderedPowerOf2(int N);

    /// <summary>
    /// Leet code #906. Super Palindromes
    /// 
    /// Let's say a positive integer is a superpalindrome if it is a palindrome, 
    /// and it is also the square of a palindrome.
    ///
    /// Now, given two positive integers L and R (represented as strings), return 
    /// the number of superpalindromes in the inclusive range [L, R].
    /// 
    /// Example 1:
    /// Input: L = "4", R = "1000"
    /// Output: 4
    /// Explanation: 4, 9, 121, and 484 are superpalindromes.
    /// Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a 
    /// palindrome.
    ///  
    /// Note:
    /// 1. 1 <= len(L) <= 18
    /// 2. 1 <= len(R) <= 18
    /// 3. L and R are strings representing integers in the range [1, 10^18).
    /// 4. int(L) <= int(R)
    /// </summary>
    int superpalindromesInRange(string L, string R);

    /// <summary>
    /// Leet code #949. Largest Time for Given Digits
    /// 
    /// Given an array of 4 digits, return the largest 24 hour time that can 
    /// be made.
    ///
    /// The smallest 24 hour time is 00:00, and the largest is 23:59.  
    /// Starting from 00:00, a time is larger if more time has elapsed since 
    /// midnight.
    /// 
    /// Return the answer as a string of length 5.  If no valid time can be 
    /// made, return an empty string.
    ///
    /// Example 1:
    ///
    /// Input: [1,2,3,4]
    /// Output: "23:41"
    ///
    /// Example 2:
    ///
    /// Input: [5,5,5,5]
    /// Output: ""
    /// 
    /// Note:
    ///
    /// 1. A.length == 4
    /// 2. 0 <= A[i] <= 9
    /// </summary>
    string largestTimeFromDigits(vector<int>& A);

    /// <summary>
    /// Leet code #976. Largest Perimeter Triangle
    /// 
    /// Given an array A of positive lengths, return the largest perimeter of a 
    /// triangle with non-zero area, formed from 3 of these lengths.
    ///
    /// If it is impossible to form any triangle of non-zero area, return 0.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: [2,1,2]
    /// Output: 5
    ///
    /// Example 2:
    ///
    /// Input: [1,2,1]
    /// Output: 0
    ///
    /// Example 3:
    ///
    /// Input: [3,2,3,4]
    /// Output: 10
    ///
    /// Example 4:
    ///
    /// Input: [3,6,2,3]
    /// Output: 8
    /// 
    /// Note:
    /// 
    /// 1. 3 <= A.length <= 10000
    /// 2. 1 <= A[i] <= 10^6
    /// </summary>
    int largestPerimeter(vector<int>& A);

    /// <summary>
     /// Leet code #991. Broken Calculator
     /// 
     /// On a broken calculator that has a number showing on its display, 
     /// we can perform two operations:
     ///
     /// Double: Multiply the number on the display by 2, or;
     /// Decrement: Subtract 1 from the number on the display.
     /// Initially, the calculator is displaying the number X.
     ///
     /// Return the minimum number of operations needed to display the number Y.
     /// 
     /// Example 1:
     /// Input: X = 2, Y = 3
     /// Output: 2
     /// Explanation: Use double operation and then decrement 
     /// operation {2 -> 4 -> 3}.
     ///
     /// Example 2:
     /// Input: X = 5, Y = 8
     /// Output: 2
     /// Explanation: Use decrement and then double {5 -> 4 -> 8}.
     ///
     /// Example 3:
     /// Input: X = 3, Y = 10
     /// Output: 3
     /// Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.
     ///
     /// Example 4:
     /// Input: X = 1024, Y = 1
     /// Output: 1023
     /// Explanation: Use decrement operations 1023 times.
     ///
     /// Note:
     /// 1. 1 <= X <= 10^9
     /// 2. 1 <= Y <= 10^9
     /// </summary>
    int brokenCalc(int X, int Y);

    /// <summary>
    /// Leet code #963. Minimum Area Rectangle II
    /// 
    /// Given a set of points in the xy-plane, determine the minimum area of any 
    /// rectangle formed from these points, with sides not necessarily parallel 
    /// to the x and y axes.
    ///
    /// If there isn't any rectangle, return 0.
    /// 
    /// Example 1:
    /// Input: [[1,2],[2,1],[1,0],[0,1]]
    /// Output: 2.00000
    /// Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], 
    /// with an area of 2.
    ///
    /// Example 2:
    /// Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
    /// Output: 1.00000
    /// Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], 
    /// with an area of 1.
    ///
    /// Example 3:
    /// Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
    /// Output: 0
    /// Explanation: There is no possible rectangle to form from these points.
    ///
    /// Example 4:
    /// Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
    /// Output: 2.00000
    /// Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], 
    /// with an area of 2.
    ///
    /// Note:
    /// 1. 1 <= points.length <= 50
    /// 2. 0 <= points[i][0] <= 40000
    /// 3. 0 <= points[i][1] <= 40000
    /// 4. All points are distinct.
    /// 5. Answers within 10^-5 of the actual value will be accepted as correct.
    /// </summary>
    double minAreaFreeRect(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1266. Minimum Time Visiting All Points
    /// 
    /// On a plane there are n points with integer coordinates 
    /// points[i] = [xi, yi]. Your task is to find the minimum time in 
    /// seconds to visit all points.
    ///
    /// You can move according to the next rules:
    ///
    /// In one second always you can either move vertically, horizontally 
    /// by one unit or diagonally (it means to move one unit vertically and 
    /// one unit horizontally in one second).
    /// You have to visit the points in the same order as they appear in the 
    /// array.
    ///
    /// Example 1:
    /// 
    /// Input: points = [[1,1],[3,4],[-1,0]]
    /// Output: 7
    /// Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> 
    /// [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
    /// Time from [1,1] to [3,4] = 3 seconds 
    /// Time from [3,4] to [-1,0] = 4 seconds
    /// Total time = 7 seconds
    ///
    /// Example 2:
    ///
    /// Input: points = [[3,2],[-2,2]]
    /// Output: 5
    /// 
    /// Constraints:
    /// 1. points.length == n
    /// 2. 1 <= n <= 100
    /// 3. points[i].length == 2
    /// 4. -1000 <= points[i][0], points[i][1] <= 1000
    /// </summary>
    int minTimeToVisitAllPoints(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1271. Hexspeak
    /// 
    /// A decimal number can be converted to its Hexspeak representation by 
    /// first converting it to an uppercase hexadecimal string, then 
    /// replacing all occurrences of the digit 0 with the letter O, and the
    /// digit 1 with the letter I.  Such a representation is valid if and 
    /// only if it consists only of the letters in the set {"A", "B", "C",
    /// "D", "E", "F", "I", "O"}.
    ///
    /// Given a string num representing a decimal integer N, return the 
    ///  Hexspeak representation of N if it is valid, otherwise return "ERROR".
    /// 
    /// Example 1:
    ///
    /// Input: num = "257"
    /// Output: "IOI"
    /// Explanation:  257 is 101 in hexadecimal.
    ///
    /// Example 2:
    ///
    /// Input: num = "3"
    /// Output: "ERROR"
    ///
    /// Constraints:
    /// 1. 1 <= N <= 10^12
    /// 2. There are no leading zeros in the given string.
    /// 3. All answers must be in uppercase letters.
    /// </summary>
    string toHexspeak(string num);

    /// <summary>
    /// Leetcode #1276. Number of Burgers with No Waste of Ingredients
    /// 
    /// Given two integers tomatoSlices and cheeseSlices. The ingredients 
    /// of different burgers are as follows:
    ///
    /// Jumbo Burger: 4 tomato slices and 1 cheese slice.
    /// Small Burger: 2 Tomato slices and 1 cheese slice.
    /// Return [total_jumbo, total_small] so that the number of remaining 
    /// tomatoSlices equal to 0 and the number of remaining cheeseSlices 
    /// equal to 0. If it is not possible to make the remaining tomatoSlices 
    /// and cheeseSlices equal to 0 return [].
    ///
    ///
    /// Example 1:
    /// Input: tomatoSlices = 16, cheeseSlices = 7
    /// Output: [1,6]
    /// Explantion: To make one jumbo burger and 6 small burgers we 
    /// need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese. There will be no 
    /// remaining ingredients.
    ///
    /// Example 2:
    ///
    /// Input: tomatoSlices = 17, cheeseSlices = 4
    /// Output: []
    /// Explantion: There will be no way to use all ingredients to make small 
    /// and jumbo burgers.
    ///
    /// Example 3:
    ///
    /// Input: tomatoSlices = 4, cheeseSlices = 17
    /// Output: []
    /// Explantion: Making 1 jumbo burger there will be 16 cheese remaining 
    /// and making 2 small burgers there will be 15 cheese remaining.
    ///
    /// Example 4:
    ///
    /// Input: tomatoSlices = 0, cheeseSlices = 0
    /// Output: [0,0]
    ///
    /// Example 5:
    ///
    /// Input: tomatoSlices = 2, cheeseSlices = 1
    /// Output: [0,1]
    /// 
    /// Constraints:
    /// 1. 0 <= tomatoSlices <= 10^7
    /// 2. 0 <= cheeseSlices <= 10^7
    /// </summary>
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices);

    /// <summary>
    /// Leet code #412. Fizz Buzz 
    /// Write a program that outputs the string representation of numbers from 1 to n.
    /// But for multiples of three it should output 揊izz?instead of the number and for the multiples of five output 揃uzz? 
    /// For numbers which are multiples of both three and five output 揊izzBuzz?
    /// Example: 
    /// Return:
    /// [
    ///    "1",
    ///    "2",
    ///    "Fizz",
    ///    "4",
    ///    "Buzz",
    ///    "Fizz",
    ///    "7",
    ///    "8",
    ///    "Fizz",
    ///    "Buzz",
    ///    "11",
    ///    "Fizz",
    ///    "13",
    ///    "14",
    ///    "FizzBuzz"
    /// ]
    /// </summary>
    vector<string> fizzBuzz(int n);

    /// <summary>
    /// Leet code #453. Minimum Moves to Equal Array Elements
    ///
    /// Given a non-empty integer array of size n, find the minimum number 
    /// of moves required to make all 
    /// array elements equal, where a move is incrementing n - 1 elements by 1. 
    ///
    /// Example: 
    /// Input:
    /// [1,2,3] 
    /// Output:
    /// 3
    /// 
    /// Explanation:
    /// Only three moves are needed (remember each move increments two elements):
    /// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
    /// </summary>
    int minMoves(vector<int>& nums);

    /// <summary>
    /// Leet code #462. Minimum Moves to Equal Array Elements II   
    /// Given a non-empty integer array, find the minimum number of moves 
    /// required to make all 
    /// array elements equal, where a move is incrementing a selected 
    /// element by 1 or decrementing 
    /// a selected element by 1.
    /// You may assume the array's length is at most 10,000.  
    ///
    /// Example: 
    /// Input:
    /// [1,2,3]
    /// Output:
    /// 2
    /// Explanation:
    /// Only two moves are needed (remember each move increments or decrements one element):
    /// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
    /// </summary>
    int minMoves2(vector<int>& nums);

    /// <summary>
    /// Leet code #326. Power of Three    
    /// Given an integer, write a function to determine if it is a power 
    /// of three. 
    /// Follow up:
    /// Could you do it without using any loop / recursion? 
    /// </summary>
    bool isPowerOfThree(int n);

    /// <summary>
    /// Leet code #625. Minimum Factorization
    /// 
    /// Given a positive integer a, find the smallest positive integer b whose 
    /// multiplication of each digit equals to a. 
    ///
    /// If there is no answer or the answer is not fit in 32-bit signed 
    /// integer, then return 0.
    ///
    /// Example 1
    /// Input: 48 
    /// Output: 68
    ///
    /// Example 2
    /// Input: 15
    /// Output: 35
    /// </summary>
    int smallestFactorization(int a);

    /// <summary>
    /// Leet code #633. Sum of Square Numbers
    /// 
    /// Given a non-negative integer c, your task is to decide whether 
    /// there're two integers a and b such that a^2 + b^2 = c. 
    /// Example 1:
    /// Input: 5
    /// Output: True
    ///
    /// Explanation: 1 * 1 + 2 * 2 = 5
    /// Example 2:
    /// Input: 3
    /// Output: False
    /// </summary>
    bool judgeSquareSum(int c);

    /// <summary>
    /// Leet code #479. Largest Palindrome Product 
    /// 
    /// Find the largest palindrome made from the product of two n-digit 
    /// numbers. 
    /// Since the result could be very large, you should return the largest 
    /// palindrome mod 1337.
    /// Example: 
    /// Input: 2
    /// Output: 987
    /// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987 
    ///
    /// Note: 
    /// The range of n is [1,8].
    /// </summary>
    int largestPalindrome(int n);

    /// <summary>
    /// Leet code #657. Judge Route Circle 
    /// 
    /// Initially, there is a Robot at position (0, 0). Given a sequence of 
    /// its moves, judge if this robot makes a circle, which means it moves 
    /// back to the original place. 
    /// The move sequence is represented by a string. And each move is 
    /// represent by a character. The valid robot moves are R (Right), 
    /// L (Left), U (Up) and D (down). The output should be true or false 
    /// representing whether the robot makes a circle. 
    /// Example 1:
    /// Input: "UD"
    /// Output: true
    ///
    /// Example 2:
    /// Input: "LL"
    /// Output: false
    /// </summary>
    bool judgeCircle(string moves);

    /// <summary>
    /// Leet code #754. Reach a Number    
    /// You are standing at position 0 on an infinite number line. There is a 
    /// goal at position target.
    ///
    /// On each move, you can either go left or right. During the n-th move 
    /// (starting from 1), you take n steps.
    /// 
    /// Return the minimum number of steps required to reach the destination.
    ///
    /// Example 1:
    /// Input: target = 3
    /// Output: 2
    /// Explanation:
    /// On the first move we step from 0 to 1.
    /// On the second step we step from 1 to 3.
    /// Example 2:
    /// Input: target = 2
    /// Output: 3
    /// Explanation:
    /// On the first move we step from 0 to 1.
    /// On the second move we step  from 1 to -1.
    /// On the third move we step from -1 to 2.
    /// Note:
    /// 1. target will be a non-zero integer in the range [-10^9, 10^9].
    /// </summary>
    int reachNumber(int target);

    /// <summary>
    /// Leet code #781. Rabbits in Forest    
    ///
    /// In a forest, each rabbit has some color. Some subset of rabbits 
    /// (possibly all of them) tell you how many other rabbits have the 
    /// same color as them. Those answers are placed in an array.
    ///
    /// Return the minimum number of rabbits that could be in the forest.
    ///
    /// Examples:
    /// Input: answers = [1, 1, 2]
    /// Output: 5
    /// Explanation:
    /// The two rabbits that answered "1" could both be the same color, 
    /// say red.
    /// The rabbit than answered "2" can't be red or the answers would be 
    /// inconsistent.
    /// Say the rabbit that answered "2" was blue.
    /// Then there should be 2 other blue rabbits in the forest that didn't 
    /// answer into the array.
    /// The smallest possible number of rabbits in the forest is therefore 
    /// 5: 3 that answered plus 2 that didn't.
    ///
    /// Input: answers = [10, 10, 10]
    /// Output: 11
    ///
    /// Input: answers = []
    /// Output: 0
    /// Note:
    ///
    /// 1. answers will have length at most 1000.
    /// 2. Each answers[i] will be an integer in the range [0, 999].
    /// </summary>
    int numRabbits(vector<int>& answers);

    /// <summary>
    /// Leet code #794. Valid Tic-Tac-Toe State
    ///
    /// A Tic-Tac-Toe board is given as a string array board. Return True if 
    /// and only if it is possible to reach this board position during the 
    /// course of a valid tic-tac-toe game.
    ///
    /// The board is a 3 x 3 array, and consists of characters " ", "X", and 
    /// "O".  The " " character represents an empty square.
    ///
    /// Here are the rules of Tic-Tac-Toe:
    ///
    /// Players take turns placing characters into empty squares (" ").
    /// The first player always places "X" characters, while the second player
    /// always places "O" characters.
    /// "X" and "O" characters are always placed into empty squares, never 
    /// filled ones.
    /// The game ends when there are 3 of the same (non-empty) character 
    /// filling any row, column, or diagonal.
    /// The game also ends if all squares are non-empty.
    /// No more moves can be played if the game is over.
    /// Example 1:
    /// Input: board = ["O  ", "   ", "   "]
    /// Output: false
    /// Explanation: The first player always plays "X".
    ///
    /// Example 2:
    /// Input: board = ["XOX", " X ", "   "]
    /// Output: false
    /// Explanation: Players take turns making moves.
    ///
    /// Example 3:
    /// Input: board = ["XXX", "   ", "OOO"]
    /// Output: false
    ///
    /// Example 4:
    /// Input: board = ["XOX", "O O", "XOX"]
    /// Output: true
    /// Note:
    ///
    /// board is a length-3 array of strings, where each string board[i] has 
    /// length 3.
    /// Each board[i][j] is a character in the set {" ", "X", "O"}.
    /// </summary>
    bool validTicTacToe(vector<string>& board);

    /// <summary>
    /// Leet code #728. Self Dividing Numbers      
    /// 
    /// A self-dividing number is a number that is divisible by every digit it 
    /// contains.
    ///
    /// For example, 128 is a self-dividing number because 128 % 1 == 0, 
    /// 128 % 2 == 0, and 128 % 8 == 0.
    ///
    /// Also, a self-dividing number is not allowed to contain the digit zero.
    ///
    /// Given a lower and upper number bound, output a list of every possible 
    /// self dividing number, including the bounds if possible.
    ///
    /// Example 1:
    /// Input: 
    /// left = 1, right = 22
    /// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
    /// Note:    
    /// 1. The boundaries of each input argument are 1 <= left <= right <= 10000.
    /// </summary>
    vector<int> selfDividingNumbers(int left, int right);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    /// </summary>
    void countBoardPattern(int row, int col, vector<vector<int>>& board, int& pattern, int& one);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    /// </summary>
    bool checkBoardPattern(int one, int N);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    /// </summary>
    bool checkBoardPatternMap(unordered_set<int>& pattern_map);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    /// </summary>
    int calculateBoardPattern(int pattern, int N);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    ///
    /// An N x N board contains only 0s and 1s. In each move, you can swap 
    /// any 2 rows with each other, or any 2 columns with each other.
    ///
    /// What is the minimum number of moves to transform the board into a 
    /// "chessboard" - a board where no 0s and no 1s are 4-directionally 
    /// adjacent? If the task is impossible, return -1.
    ///
    /// Examples:
    /// Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
    /// Output: 2
    /// Explanation:
    /// One potential sequence of moves is shown below, from left to right:
    ///
    /// 0110     1010     1010
    /// 0110 --> 1010 --> 0101
    /// 1001     0101     1010
    /// 1001     0101     0101
    ///
    /// The first move swaps the first and second column.
    /// The second move swaps the second and third row.
    ///
    /// Input: board = [[0, 1], [1, 0]]
    /// Output: 0
    /// Explanation:
    /// Also note that the board with 0 in the top left corner,
    /// 01
    /// 10
    ///
    /// is also a valid chessboard.
    /// 
    /// Input: board = [[1, 0], [1, 0]]
    /// Output: -1
    /// Explanation:
    /// No matter what sequence of moves you make, you cannot end with a valid 
    /// chessboard.
    /// 
    /// Note:
    /// 1. board will have the same number of rows and columns, a number in the 
    ///    range [2, 30].
    /// 2. board[i][j] will be only 0s or 1s.
    /// </summary>
    int movesToChessboard(vector<vector<int>>& board);

    /// <summary>
    /// Leet code #789. Escape The Ghosts
    /// 
    /// You are playing a simplified Pacman game. You start at the point 
    /// (0, 0), and your destination is (target[0], target[1]). There are 
    /// several ghosts on the map, the i-th ghost starts at (ghosts[i][0], 
    /// ghosts[i][1]).
    /// Each turn, you and all ghosts simultaneously *may* move in one of 
    /// 4 cardinal directions: north, east, west, or south, going from the 
    /// previous point to a new point 1 unit of distance away.
    /// You escape if and only if you can reach the target before any ghost 
    /// reaches you (for any given moves the ghosts may take.)  If you reach 
    /// any square (including the target) at the same time as a ghost, it 
    /// doesn't count as an escape.
    /// Return True if and only if it is possible to escape.
    /// Example 1:
    /// Input: 
    /// ghosts = [[1, 0], [0, 3]]
    /// target = [0, 1]
    /// Output: true
    /// Explanation: 
    /// You can directly reach the destination (0, 1) at time 1, while the 
    /// ghosts located at (1, 0) or (0, 3) have no way to catch up with you.
    /// Example 2:
    /// Input: 
    /// ghosts = [[1, 0]]
    /// target = [2, 0]
    /// Output: false
    /// Explanation: 
    /// You need to reach the destination (2, 0), but the ghost at (1, 0) 
    /// lies between you and the destination.
    /// Example 3:
    /// Input: 
    /// ghosts = [[2, 0]]
    /// target = [1, 0]
    /// Output: false
    /// Explanation: 
    /// The ghost can reach the target at the same time as you.
    /// Note:
    /// 1. All points have coordinates with absolute value <= 10000.
    /// 2. The number of ghosts will not exceed 100.
    /// </summary>
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target);

    /// <summary>
    /// Leet code #829. Consecutive Numbers Sum
    /// 
    /// Given a positive integer N, how many ways can we write it as a sum of 
    /// consecutive positive integers?
    ///
    /// Example 1:
    /// Input: 5
    /// Output: 2
    /// Explanation: 5 = 5 = 2 + 3
    ///
    /// Example 2:
    /// Input: 9
    /// Output: 3
    /// Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
    /// 
    /// Example 3:
    /// Input: 15
    /// Output: 4
    /// Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
    ///
    /// 1. Note: 1 <= N <= 10 ^ 9.
    /// </summary>
    int consecutiveNumbersSum(int N);

    /// <summary>
    /// Leet code #836. Rectangle Overlap
    /// 
    /// A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) 
    /// are the coordinates of its bottom-left corner, and (x2, y2) are the 
    /// coordinates of its top-right corner.
    ///
    /// Two rectangles overlap if the area of their intersection is positive.  
    /// To be clear, two rectangles that only touch at the corner or edges do 
    /// not overlap.
    ///
    /// Given two rectangles, return whether they overlap.
    ///
    /// Example 1:
    ///
    /// Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
    /// Output: true
    ///
    /// Example 2:
    ///
    /// Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
    /// Output: false
    /// Notes:
    ///
    /// Both rectangles rec1 and rec2 are lists of 4 integers.
    /// All coordinates in rectangles will be between -10^9 and 10^9.
    /// </summary>
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2);

    /// <summary>
    /// Leet code #910. Smallest Range II
    /// 
    /// Given an array A of integers, for each integer A[i] we need to choose 
    /// either x = -K or x = K, and add x to A[i] (only once).
    ///
    /// After this process, we have some array B.
    ///
    /// Return the smallest possible difference between the maximum value of B 
    /// and the minimum value of B.
    ///
    /// Example 1:
    /// Input: A = [1], K = 0
    /// Output: 0
    /// Explanation: B = [1]
    ///
    /// Example 2:
    /// Input: A = [0,10], K = 2
    /// Output: 6
    /// Explanation: B = [2,8]
    ///
    /// Example 3:
    /// 
    /// Input: A = [1,3,6], K = 3
    /// Output: 3
    /// Explanation: B = [4,6,3]
    /// 
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 10000
    /// 3. 0 <= K <= 10000
    /// </summary>
    int smallestRangeII(vector<int>& A, int K);

    /// <summary>
    /// Leet code #970. Powerful Integers
    /// 
    /// Given two non-negative integers x and y, an integer is powerful if it is 
    /// equal to x^i + y^j for some integers i >= 0 and j >= 0.
    ///
    /// Return a list of all powerful integers that have value less than or equal 
    /// to bound.
    ///
    /// You may return the answer in any order.  In your answer, each value should 
    /// occur at most once.
    ///
    /// Example 1:
    /// Input: x = 2, y = 3, bound = 10
    /// Output: [2,3,4,5,7,9,10]
    /// Explanation: 
    /// 2 = 2^0 + 3^0
    /// 3 = 2^1 + 3^0
    /// 4 = 2^0 + 3^1
    /// 5 = 2^1 + 3^1
    /// 7 = 2^2 + 3^1
    /// 9 = 2^3 + 3^0
    /// 10 = 2^0 + 3^2
    ///
    /// Example 2:
    ///
    /// Input: x = 3, y = 5, bound = 15
    /// Output: [2,4,6,8,10,14]
    ///
    /// Note:
    ///
    /// 1. 1 <= x <= 100
    /// 2. 1 <= y <= 100
    /// 3. 0 <= bound <= 10^6
    /// </summary>
    vector<int> powerfulIntegers(int x, int y, int bound);

    /// <summary>
    /// Leet code #969. Pancake Sorting
    /// 
    /// Given an array A, we can perform a pancake flip: We choose some positive 
    /// integer k <= A.length, then reverse the order of the first k elements of A. 
    /// We want to perform zero or more pancake flips (doing them one after 
    /// another in succession) to sort the array A.
    ///
    /// Return the k-values corresponding to a sequence of pancake flips that 
    /// sort A.  Any valid answer that sorts the array within 10 * A.length flips 
    /// will be judged as correct.
    /// 
    /// Example 1:
    /// Input: [3,2,4,1]
    /// Output: [4,2,4,3]
    /// Explanation: 
    /// We perform 4 pancake flips, with k values 4, 2, 4, and 3.
    /// Starting state: A = [3, 2, 4, 1]
    /// After 1st flip (k=4): A = [1, 4, 2, 3]
    /// After 2nd flip (k=2): A = [4, 1, 2, 3]
    /// After 3rd flip (k=4): A = [3, 2, 1, 4]
    /// After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
    ///
    /// Example 2:
    /// Input: [1,2,3]
    /// Output: []
    /// Explanation: The input is already sorted, so there is no need to flip 
    /// anything.
    /// Note that other answers, such as [3, 3], would also be accepted.
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 100
    /// 2. A[i] is a permutation of [1, 2, ..., A.length]
    /// </summary>
    vector<int> pancakeSort(vector<int>& A);

    /// <summary>
    /// Leet code #1006. Clumsy Factorial
    /// </summary>
    int clumsyFactor(int& N, int& op);

    /// <summary>
    /// Leet code #1006. Clumsy Factorial
    /// 
    /// Normally, the factorial of a positive integer n is the product of all 
    /// positive integers less than or equal to n.  For example, factorial(10) 
    /// = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
    ///
    /// We instead make a clumsy factorial: using the integers in decreasing 
    /// order, we swap out the multiply operations for a fixed rotation of 
    /// operations: multiply (*), divide (/), add (+) and subtract (-) in this 
    /// order.
    ///
    /// For example, clumsy(10) = 10 * 9 / 8 + 7 - 
    /// 6 * 5 / 4 + 3 - 2 * 1.  However, these operations are still applied 
    /// using the usual order of operations of arithmetic: we do all 
    /// multiplication and division steps before any addition or subtraction 
    /// steps, and multiplication and division steps are processed left to 
    /// right.
    ///
    /// Additionally, the division that we use is floor division such that 
    /// 10 * 9 / 8 equals 11.  This guarantees the result is an integer.
    ///
    /// Implement the clumsy function as defined above: given an integer N, 
    /// it returns the clumsy factorial of N.
    ///
    /// Example 1:
    /// 
    /// Input: 4
    /// Output: 7
    /// Explanation: 7 = 4 * 3 / 2 + 1
    ///
    /// Example 2:
    /// 
    /// Input: 10
    /// Output: 12
    /// Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
    /// 
    /// Note:
    /// 1. 1 <= N <= 10000
    /// 2. -2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit 
    ///    within a 32-bit integer.)
    /// </summary>
    int clumsy(int N);

    /// <summary>
    /// Leet code #1056. Confusing Number
    /// 
    /// Given a number N, return true if and only if it is a confusing number, 
    /// which satisfies the following condition:
    ///
    /// We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 
    /// are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 
    /// 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A confusing 
    /// number is a number that when rotated 180 degrees becomes a different 
    /// number with each digit valid.
    ///
    /// Example 1:
    ///
    /// Input: 6
    /// Output: true
    /// Explanation: 
    /// We get 9 after rotating 6, 9 is a valid number and 9!=6.
    ///
    /// Example 2:
    ///
    /// Input: 89
    /// Output: true
    /// Explanation: 
    /// We get 68 after rotating 89, 86 is a valid number and 86!=89.
    ///
    /// Example 3:
    ///
    /// Input: 11
    /// Output: false
    /// Explanation: 
    /// We get 11 after rotating 11, 11 is a valid number but the value remains 
    /// the same, thus 11 is not a confusing number.
    ///
    /// Example 4:
    ///
    /// Input: 25
    /// Output: false
    /// Explanation: 
    /// We get an invalid number after rotating 25.
    ///
    /// Note:
    /// 1. 0 <= N <= 10^9
    /// 2. After the rotation we can ignore leading zeros, for example if after 
    /// rotation we have 0008 then this number is considered as just 8.
    /// </summary>
    bool confusingNumber(int N);

    /// <summary>
    /// Leet code #1281. Subtract the Product and Sum of Digits of an Integer
    ///
    /// Easy
    ///
    /// Given an integer number n, return the difference between the product 
    /// of its digits and the sum of its digits. 
    ///
    /// Example 1:
    /// Input: n = 234
    /// Output: 15 
    /// Explanation: 
    /// Product of digits = 2 * 3 * 4 = 24 
    /// Sum of digits = 2 + 3 + 4 = 9 
    /// Result = 24 - 9 = 15
    ///
    /// Example 2:
    /// Input: n = 4421
    /// Output: 21
    /// Explanation: 
    /// Product of digits = 4 * 4 * 2 * 1 = 32 
    /// Sum of digits = 4 + 4 + 2 + 1 = 11 
    /// Result = 32 - 11 = 21
    /// </summary>
    int subtractProductAndSum(int n);

    /// <summary>
    /// Leet code #1291. Sequential Digits
    ///
    /// Medium
    ///
    /// An integer has sequential digits if and only if each digit in the 
    /// number is one more than the previous digit.
    ///
    /// Return a sorted list of all the integers in the range [low, high] 
    /// inclusive that have sequential digits.
    /// 
    /// Example 1:
    /// Input: low = 100, high = 300
    /// Output: [123,234]
    ///
    /// Example 2:
    /// Input: low = 1000, high = 13000
    /// Output: [1234,2345,3456,4567,5678,6789,12345]
    ///
    /// Constraints:
    /// 1. 10 <= low <= high <= 10^9
    /// </summary>
    vector<int> sequentialDigits(int low, int high);

    /// <summary>
    /// Leetcode #1295. Find Numbers with Even Number of Digits
    /// 
    /// Given an array nums of integers, return how many of them contain an 
    /// even number of digits.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [12,345,2,6,7896]
    /// Output: 2
    /// Explanation: 
    /// 12 contains 2 digits (even number of digits). 
    /// 345 contains 3 digits (odd number of digits). 
    /// 2 contains 1 digit (odd number of digits). 
    /// 6 contains 1 digit (odd number of digits). 
    /// 7896 contains 4 digits (even number of digits). 
    /// Therefore only 12 and 7896 contain an even number of digits.
    ///
    /// Example 2:
    ///  
    /// Input: nums = [555,901,482,1771]
    /// Output: 1 
    /// Explanation: 
    /// Only 1771 contains an even number of digits.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 500
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int findNumbers(vector<int>& nums);

    /// <summary>
    /// Leet code #800. Similar RGB Color
    /// 
    /// In the following, every capital letter represents some hexadecimal 
    /// digit from 0 to f.
    ///
    /// The red-green-blue color "#AABBCC" can be written as "#ABC" in 
    /// shorthand.  For example, "#15c" is shorthand for the color "#1155cc".
    ///
    /// Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" 
    /// is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.
    ///
    /// Given the color "#ABCDEF", return a 7 character color that is most 
    /// similar to #ABCDEF, and has a shorthand (that is, it can be represented
    /// as some "#XYZ"
    ///
    /// Example 1:
    /// Input: color = "#09f166"
    /// Output: "#11ee66"
    /// Explanation:  
    /// The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 
    /// = -64 -9 -0 = -73.
    /// This is the highest among any shorthand color.
    /// Note:
    ///
    /// 1. color is a string of length 7.
    /// 2. color is a valid RGB color: for i > 0, color[i] is a hexadecimal 
    ///    digit from 0 to f
    /// 3. Any answer which has the same (highest) similarity as the best 
    ///    answer will be accepted.
    /// 4. All inputs and outputs should use lowercase letters, and the 
    ///    output is 7 characters.
    /// </summary>
    string similarRGB(string color);

    /// <summary>
    /// Leet code #810. Chalkboard XOR Game
    /// 
    /// We are given non-negative integers nums[i] which are written on a 
    /// chalkboard.  Alice and Bob take turns erasing exactly one number 
    /// from the chalkboard, with Alice starting first.  If erasing a number 
    /// causes the bitwise XOR of all the elements of the chalkboard to become 
    /// 0, then that player loses.  (Also, we'll say the bitwise XOR of one 
    /// element is that element itself, and the bitwise XOR of no elements is 
    /// 0.)
    ///
    /// Also, if any player starts their turn with the bitwise XOR of all the 
    /// elements of the chalkboard equal to 0, then that player wins.
    ///
    /// Return True if and only if Alice wins the game, assuming both players 
    /// play optimally.
    ///
    /// Example:
    /// Input: nums = [1, 1, 2]
    /// Output: false
    /// Explanation: 
    /// Alice has two choices: erase 1 or erase 2. 
    /// If she erases 1, the nums array becomes [1, 2]. The bitwise XOR of all 
    /// the elements of the chalkboard is 1 XOR 2 = 3. Now Bob can remove any 
    /// element he wants, because Alice will be the one to erase the last 
    /// element and she will lose. 
    /// If Alice erases 2 first, now nums becomes [1, 1]. The bitwise XOR of 
    /// all the elements of the chalkboard is 1 XOR 1 = 0. Alice will lose.
    ///
    /// Notes:
    ///
    /// 1. 1 <= N <= 1000. 
    /// 2. 0 <= nums[i] <= 2^16.
    /// </summary>
    bool xorGame(vector<int>& nums);

    /// <summary>
    /// Leetcode #1304. Find N Unique Integers Sum up to Zero
    ///
    /// Easy	
    ///
    /// Given an integer n, return any array containing n unique integers 
    /// such that they add up to 0.
    /// 
    /// Example 1: 
    /// Input: n = 5
    /// Output: [-7,-1,1,3,4]
    /// Explanation: These arrays also are accepted [-5,-1,1,2,3], 
    /// [-3,-1,2,-2,4].
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: [-1,0,1]
    ///
    /// Example 3:
    ///
    /// Input: n = 1
    /// Output: [0]
    ///  
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    vector<int> sumZero(int n);

    /// <summary>
    /// Leet code #1317. Convert Integer to the Sum of Two No-Zero Integers
    ///
    /// Easy
    ///
    /// Given an integer n. No-Zero integer is a positive integer which doesn't 
    /// contain any 0 in its decimal representation.
    ///
    /// Return a list of two integers [A, B] where:
    ///
    /// A and B are No-Zero integers.
    /// A + B = n
    /// It's guarateed that there is at least one valid solution. If there are 
    /// many valid solutions you can return any of them.
    /// 
    /// Example 1:
    /// Input: n = 2
    /// Output: [1,1]
    /// Explanation: A = 1, B = 1. A + B = n and both A and B don't contain 
    /// any 0 in their decimal representation.
    ///
    /// Example 2:
    /// Input: n = 11
    /// Output: [2,9]
    ///
    /// Example 3:
    /// Input: n = 10000
    /// Output: [1,9999]
    ///
    /// Example 4:
    /// Input: n = 69
    /// Output: [1,68]
    //
    /// Example 5:
    /// Input: n = 1010
    /// Output: [11,999]
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^4
    /// </summary>
    vector<int> getNoZeroIntegers(int n);

    /// <summary>
    /// Leet code #1318. Minimum Flips to Make a OR b Equal to c
    ///
    /// Medium
    ///
    /// Given 3 positives numbers a, b and c. Return the minimum flips required 
    /// in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
    /// Flip operation consists of change any single bit 1 to 0 or change the 
    /// bit 0 to 1 in their binary representation.
    /// 
    /// Example 1:
    /// Input: a = 2, b = 6, c = 5
    /// Output: 3
    /// Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
    ///
    /// Example 2:
    /// Input: a = 4, b = 2, c = 7
    /// Output: 1
    ///
    /// Example 3:
    /// Input: a = 1, b = 2, c = 3
    /// Output: 0
    ///
    /// Constraints:
    /// 1. 1 <= a <= 10^9
    /// 2. 1 <= b <= 10^9
    /// 3. 1 <= c <= 10^9
    /// </summary>
    int minFlips(int a, int b, int c);

    /// <summary>
    /// Leet code #1323. Maximum 69 Number
    ///
    /// Easy
    ///
    /// Given a positive integer num consisting only of digits 6 and 9.
    ///
    /// Return the maximum number you can get by changing at most one digit 
    /// (6 becomes 9, and 9 becomes 6).
    ///
    /// Example 1:
    ///
    /// Input: num = 9669
    /// Output: 9969
    /// Explanation: 
    /// Changing the first digit results in 6669.
    /// Changing the second digit results in 9969.
    /// Changing the third digit results in 9699.
    /// Changing the fourth digit results in 9666. 
    /// The maximum number is 9969.
    /// 
    /// Example 2:
    /// Input: num = 9996
    /// Output: 9999
    /// Explanation: Changing the last digit 6 to 9 results in the maximum 
    /// number.
    ///
    /// Example 3:
    /// Input: num = 9999
    /// Output: 9999
    /// Explanation: It is better not to apply any change.
    /// 
    /// Constraints:
    /// 1. 1 <= num <= 10^4
    /// 2. num's digits are 6 or 9.
    /// </summary>
    int maximum69Number(int num);

    /// <summary>
    /// Leet code #204. Count Primes
    /// 
    /// Count the number of prime numbers less than a non - negative number, n.
    /// </summary>
    int countPrimes(int n);

    /// <summary>
    /// Leet code #1342. Number of Steps to Reduce a Number to Zero
    ///
    /// Easy
    ///
    /// Given a non-negative integer num, return the number of steps to 
    /// reduce it to zero. If the current number is even, you have to 
    /// divide it by 2, otherwise, you have to subtract 1 from it.
    /// 
    /// Example 1:
    /// Input: num = 14
    /// Output: 6
    /// Explanation: 
    /// Step 1) 14 is even; divide by 2 and obtain 7. 
    /// Step 2) 7 is odd; subtract 1 and obtain 6.
    /// Step 3) 6 is even; divide by 2 and obtain 3. 
    /// Step 4) 3 is odd; subtract 1 and obtain 2. 
    /// Step 5) 2 is even; divide by 2 and obtain 1. 
    /// Step 6) 1 is odd; subtract 1 and obtain 0.
    ///
    /// Example 2:
    /// Input: num = 8
    /// Output: 4
    /// Explanation: 
    /// Step 1) 8 is even; divide by 2 and obtain 4. 
    /// Step 2) 4 is even; divide by 2 and obtain 2. 
    /// Step 3) 2 is even; divide by 2 and obtain 1. 
    /// Step 4) 1 is odd; subtract 1 and obtain 0.
    ///
    /// Example 3:
    /// Input: num = 123
    /// Output: 12
    ///
    /// Constraints:
    /// 1. 0 <= num <= 10^6
    /// </summary>
    int numberOfSteps(int num);

    /// <summary>
    /// Leet code #1344. Angle Between Hands of a Clock 
    ///
    /// Medium
    ///
    /// Given two numbers, hour and minutes. Return the smaller angle 
    /// (in sexagesimal units) formed between the hour and the minute hand.
    ///
    /// Example 1:
    /// Input: hour = 12, minutes = 30
    /// Output: 165
    ///
    /// Example 2:
    /// Input: hour = 3, minutes = 30
    /// Output: 75
    ///
    /// Example 3:
    /// Input: hour = 3, minutes = 15
    /// Output: 7.5
    ///
    /// Example 4:
    /// Input: hour = 4, minutes = 50
    /// Output: 155
    ///
    /// Example 5:
    /// Input: hour = 12, minutes = 0
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= hour <= 12
    /// 2. 0 <= minutes <= 59
    /// 3. Answers within 10^-5 of the actual value will be accepted as 
    /// correct.
    /// </summary>
    double angleClock(int hour, int minutes);

    /// <summary>
    /// Leet code #1354. Construct Target Array With Multiple Sums
    ///
    /// Hard
    ///
    /// Given an array of integers target. From a starting array, A 
    /// consisting of all 1's, you may perform the following procedure
    ///
    /// let x be the sum of all elements currently in your array.
    /// choose index i, such that 0 <= i < target.size and set the value of 
    /// A at index i to x.
    /// You may repeat this procedure as many times as needed.
    /// Return True if it is possible to construct the target array from A 
    /// otherwise return False.
    ///
    /// Example 1:
    /// Input: target = [9,3,5]
    /// Output: true
    /// Explanation: Start with [1, 1, 1] 
    /// [1, 1, 1], sum = 3 choose index 1
    /// [1, 3, 1], sum = 5 choose index 2
    /// [1, 3, 5], sum = 9 choose index 0
    /// [9, 3, 5] Done
    ///
    /// Example 2:
    /// Input: target = [1,1,1,2]
    /// Output: false
    /// Explanation: Impossible to create target array from [1,1,1,1].
    ///
    /// Example 3:
    /// Input: target = [8,5]
    /// Output: true
    /// 
    /// Constraints:
    /// 1. N == target.length
    /// 2. 1 <= target.length <= 5 * 10^4
    /// 3. 1 <= target[i] <= 10^9
    /// </summary>
    bool isPossible(vector<int>& target);

    /// <summary>
    /// Leet code #1356. Sort Integers by The Number of 1 Bits
    ///
    /// Easy
    ///
    /// Given an integer array arr. You have to sort the integers in the 
    /// array in ascending order by the number of 1's in their binary 
    /// representation and in case of two or more integers have the same 
    /// number of 1's you have to sort them in ascending order.
    ///
    /// Return the sorted array.
    ///
    /// Example 1:
    /// Input: arr = [0,1,2,3,4,5,6,7,8]
    /// Output: [0,1,2,4,8,3,5,6,7]
    /// Explantion: [0] is the only integer with 0 bits.
    /// [1,2,4,8] all have 1 bit.
    /// [3,5,6] have 2 bits.
    /// [7] has 3 bits.
    /// The sorted array by bits is [0,1,2,4,8,3,5,6,7]
    ///
    /// Example 2:
    /// Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
    /// Output: [1,2,4,8,16,32,64,128,256,512,1024]
    /// Explantion: All integers have 1 bit in the binary representation, 
    /// you should just sort them in ascending order.
    ///
    /// Example 3:
    /// Input: arr = [10000,10000]
    /// Output: [10000,10000]
    ///
    /// Example 4:
    /// Input: arr = [2,3,5,7,11,13,17,19]
    /// Output: [2,3,5,17,7,11,13,19]
    ///
    /// Example 5:
    /// Input: arr = [10,100,1000,10000]
    /// Output: [10,100,10000,1000]
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 500
    /// 2. 0 <= arr[i] <= 10^4
    /// </summary>
    vector<int> sortByBits(vector<int>& arr);

    /// <summary>
    /// Leet code #1359. Count All Valid Pickup and Delivery Options
    ///
    /// Hard
    ///
    /// Given n orders, each order consist in pickup and delivery services. 
    ///
    /// Count all valid pickup/delivery possible sequences such that 
    /// delivery(i) is always after of pickup(i). 
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 1
    /// Output: 1
    /// Explanation: Unique order (P1, D1), Delivery 1 always is after of 
    /// Pickup 1.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 6
    /// Explanation: All possible orders: 
    /// (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), 
    /// (P2,P1,D2,D1) and (P2,D2,P1,D1).
    /// This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after 
    /// of Delivery 2.
    ///
    /// Example 3:
    /// Input: n = 3
    /// Output: 90
    ///
    /// Constraints:
    /// 1. 1 <= n <= 500
    /// </summary>
    int countOrders(int n);

     /// <summary>
     /// Leet code #1360. Number of Days Between Two Dates
     /// </summary>
     bool isLeapYear(int year);

    /// <summary>
    /// Leet code #1360. Number of Days Between Two Dates
    ///
    /// Easy
    ///
    /// Write a program to count the number of days between two dates.
    ///
    /// The two dates are given as strings, their format is YYYY-MM-DD as 
    /// shown in the examples.
    ///
    /// Example 1:
    /// Input: date1 = "2019-06-29", date2 = "2019-06-30"
    /// Output: 1
    ///
    /// Example 2:
    /// Input: date1 = "2020-01-15", date2 = "2019-12-31"
    /// Output: 15
    /// 
    /// Constraints:
    /// 1. The given dates are valid dates between the years 1971 and 2100.
    /// </summary>
    int daysBetweenDates(string date1, string date2);

    /// <summary>
    /// Leet code #1363. Largest Multiple of Three
    ///
    /// Hard
    ///
    /// Given an integer array of digits, return the largest multiple of 
    /// three that can be formed by concatenating some of the given 
    /// digits in any order.
    ///
    /// Since the answer may not fit in an integer data type, return the 
    /// answer as a string.
    ///
    /// If there is no answer return an empty string.
    /// 
    /// Example 1:
    /// Input: digits = [8,1,9]
    /// Output: "981"
    ///
    /// Example 2:
    /// Input: digits = [8,6,7,1,0]
    /// Output: "8760"
    ///
    /// Example 3:
    /// Input: digits = [1]
    /// Output: ""
    ///
    /// Example 4:
    /// Input: digits = [0,0,0,0,0,0]
    /// Output: "0"
    /// 
    /// Constraints:
    /// 1. 1 <= digits.length <= 10^4
    /// 2. 0 <= digits[i] <= 9
    /// 3. The returning answer must not contain unnecessary leading zeros.
    /// </summary>
    string largestMultipleOfThree(vector<int>& digits);

    /// <summary>
    /// Leet code #1362. Closest Divisors
    ///
    /// Medium
    ///
    /// Given an integer num, find the closest two integers in absolute 
    /// difference whose product equals num + 1 or num + 2.
    /// 
    /// Return the two integers in any order.
    ///
    /// Example 1:
    /// Input: num = 8
    /// Output: [3,3]
    /// Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for 
    /// num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
    ///
    /// Example 2:
    /// Input: num = 123
    /// Output: [5,25]
    ///
    /// Example 3:
    /// Input: num = 999
    /// Output: [40,25]
    ///
    /// Constraints:
    /// 1. 1 <= num <= 10^9
    /// </summary>
    vector<int> closestDivisors(int num);

    /// <summary>
    /// Leet code #1375. Bulb Switcher III
    ///  
    /// Medium
    ///
    /// There is a room with n bulbs, numbered from 1 to n, arranged in a 
    /// row from left to right. Initially, all the bulbs are turned off.
    ///
    /// At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. 
    /// A bulb change color to blue only if it is on and all the previous 
    /// bulbs (to the left) are turned on too.
    ///
    /// Return the number of moments in which all turned on bulbs are blue.
    /// 
    /// Example 1:
    /// Input: light = [2,1,3,5,4]
    /// Output: 3
    /// Explanation: All bulbs turned on, are blue at the moment 1, 2 and 4.
    ///
    /// Example 2:
    /// Input: light = [3,2,4,1,5]
    /// Output: 2
    /// Explanation: All bulbs turned on, are blue at the moment 3, and 4 
    /// (index-0).
    ///
    /// Example 3:
    /// Input: light = [4,1,2,3]
    /// Output: 1
    /// Explanation: All bulbs turned on, are blue at the moment 3 (index-0).
    /// Bulb 4th changes to blue at the moment 3.
    ///
    /// Example 4:
    /// Input: light = [2,1,4,3,6,5]
    /// Output: 3
    ///
    /// Example 5:
    /// Input: light = [1,2,3,4,5,6]
    /// Output: 6
    /// 
    /// Constraints:
    /// 1. n == light.length
    /// 2. 1 <= n <= 5 * 10^4
    /// 3. light is a permutation of  [1, 2, ..., n]
    /// </summary>
    int numTimesAllBlue(vector<int>& light);

    /// <summary>
    /// Leet code #1390. Four Divisors
    /// 
    /// Medium
    ///
    /// Given an integer array nums, return the sum of divisors of the 
    /// integers in that array that have exactly four divisors.
    /// 
    /// If there is no such integer in the array, return 0.
    /// Example 1:
    /// Input: nums = [21,4,7]
    /// Output: 32
    /// Explanation:
    /// 21 has 4 divisors: 1, 3, 7, 21
    /// 4 has 3 divisors: 1, 2, 4
    /// 7 has 2 divisors: 1, 7
    /// The answer is the sum of divisors of 21 only.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^4
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int sumFourDivisors(vector<int>& nums);

    /// <summary>
    /// Leet code #1399. Count Largest Group
    /// 
    /// Easy
    ///
    /// Given an integer n. Each number from 1 to n is grouped according to 
    /// the sum of its digits. 
    ///
    /// Return how many groups have the largest size.
    /// 
    /// Example 1:
    /// Input: n = 13
    /// Output: 4
    /// Explanation: There are 9 groups in total, they are grouped according 
    /// sum of its digits of numbers from 1 to 13:
    /// [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. 
    /// There are 4 groups with largest size.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 2 
    /// Explanation: There are 2 groups [1], [2] of size 1.
    ///
    /// Example 3:
    /// Input: n = 15
    /// Output: 6
    ///
    /// Example 4:
    /// Input: n = 24
    /// Output: 5
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// </summary>
    int countLargestGroup(int n);

    /// <summary>
    /// Leet code #1401. Circle and Rectangle Overlapping
    /// 
    /// Medium
    ///
    /// Given a circle represented as (radius, x_center, y_center) and an 
    /// axis-aligned rectangle represented as (x1, y1, x2, y2), 
    /// where (x1, y1) are the coordinates of the bottom-left corner, 
    /// and (x2, y2) are the coordinates of the top-right corner of the 
    /// rectangle.
    ///
    /// Return True if the circle and rectangle are overlapped otherwise 
    /// return False.
    /// In other words, check if there are any point (xi, yi) such that 
    /// belongs to the circle and the rectangle at the same time.
    /// 
    /// Example 1:
    /// Input: radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, 
    /// x2 = 3, y2 = 1
    /// Output: true
    /// Explanation: Circle and rectangle share the point (1,0) 
    ///
    /// Example 2:
    /// Input: radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, 
    /// x2 = 0, y2 = 1
    /// Output: true
    ///
    /// Example 3:
    /// Input: radius = 1, x_center = 1, y_center = 1, 
    /// x1 = -3, y1 = -3, x2 = 3, y2 = 3
    /// Output: true
    ///
    /// Example 4: 
    /// Input: radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, 
    /// x2 = 2, y2 = -1
    /// Output: false
    ///
    /// Constraints:
    /// 1. 1 <= radius <= 2000
    /// 2. -10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4
    /// 3. x1 < x2
    /// 4. y1 < y2
    /// </summary>
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2);

    /// <summary>
    /// Leet code #1414. Find the Minimum Number of Fibonacci Numbers Whose 
    ///                  Sum Is K 
    /// 
    /// Medium
    ///
    /// Given the number k, return the minimum number of Fibonacci numbers 
    /// whose sum is equal to k, whether a Fibonacci number could be used 
    /// multiple times.
    ///
    /// The Fibonacci numbers are defined as:
    /// 
    /// F1 = 1
    /// F2 = 1
    /// Fn = Fn-1 + Fn-2 , for n > 2.
    /// It is guaranteed that for the given constraints we can always find 
    /// such fibonacci numbers that sum k.
    /// 
    /// Example 1:
    /// Input: k = 7
    /// Output: 2 
    /// Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
    /// For k = 7 we can use 2 + 5 = 7.
    ///
    /// Example 2:
    /// Input: k = 10
    /// Output: 2 
    /// Explanation: For k = 10 we can use 2 + 8 = 10.
    ///
    /// Example 3:
    /// Input: k = 19
    /// Output: 3 
    /// Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
    ///
    /// Constraints:
    /// 1. 1 <= k <= 10^9
    /// </summary>
    int findMinFibonacciNumbers(int k);

    /// <summary>
    /// Leet code #1415. The k-th Lexicographical String of All Happy Strings 
    ///                  of Length n 
    /// 
    /// Medium
    ///
    /// A happy string is a string that:
    ///
    /// consists only of letters of the set ['a', 'b', 'c'].
    /// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 
    /// (string is 1-indexed).
    /// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy 
    /// strings and strings "aa", "baa" and "ababbc" are not happy strings.
    ///
    /// Given two integers n and k, consider a list of all happy strings of 
    /// length n sorted in lexicographical order.
    ///
    /// Return the kth string of this list or return an empty string if there 
    /// are less than k happy strings of length n.
    ///
    /// Example 1:
    /// Input: n = 1, k = 3
    /// Output: "c"
    /// Explanation: The list ["a", "b", "c"] contains all happy strings of 
    /// length 1. The third string is "c".
    ///
    /// Example 2:
    /// Input: n = 1, k = 4
    /// Output: ""
    /// Explanation: There are only 3 happy strings of length 1.
    ///
    /// Example 3:
    /// Input: n = 3, k = 9
    /// Output: "cab"
    /// Explanation: There are 12 different happy string of length 3 ["aba", 
    /// "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", 
    /// "cbc"]. You will find the 9th string = "cab"
    ///
    /// Example 4:
    /// Input: n = 2, k = 7
    /// Output: ""
    ///
    /// Example 5:
    /// Input: n = 10, k = 100
    /// Output: "abacbabacb"
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10
    /// 2. 1 <= k <= 100
    /// </summary>
    string getHappyString(int n, int k);

    /// <summary>
    /// Leet code #1432. Max Difference You Can Get From Changing an Integer
    /// 
    /// Medium
    ///
    /// You are given an integer num. You will apply the following steps 
    /// exactly two times:
    ///
    /// Pick a digit x (0 <= x <= 9).
    /// Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
    /// Replace all the occurrences of x in the decimal representation of num 
    /// by y.
    /// The new integer cannot have any leading zeros, also the new integer 
    /// cannot be 0.
    /// Let a and b be the results of applying the operations to num the first 
    /// and second times, respectively.
    ///
    /// Return the max difference between a and b.
    /// 
    /// Example 1:
    /// Input: num = 555
    /// Output: 888
    /// Explanation: The first time pick x = 5 and y = 9 and store the new 
    /// integer in a.
    /// The second time pick x = 5 and y = 1 and store the new integer in b.
    /// We have now a = 999 and b = 111 and max difference = 888
    ///
    /// Example 2:
    /// Input: num = 9
    /// Output: 8
    /// Explanation: The first time pick x = 9 and y = 9 and store the new 
    /// integer in a.
    /// The second time pick x = 9 and y = 1 and store the new integer in b.
    /// We have now a = 9 and b = 1 and max difference = 8
    ///
    /// Example 3:
    /// Input: num = 123456
    /// Output: 820000
    ///
    /// Example 4:
    /// Input: num = 10000
    /// Output: 80000
    ///
    /// Example 5:
    /// Input: num = 9288
    /// Output: 8700
    ///
    /// Constraints:
    /// 1. 1 <= num <= 10^8
    /// </summary>
    int maxDiff(int num);

    /// <summary>
    /// Leet code #1447. Simplified Fractions
    ///
    /// Medium
    ///
    /// Given an integer n, return a list of all simplified fractions 
    /// between 0 and 1 (exclusive) such that the denominator is 
    /// less-than-or-equal-to n. The fractions can be in any order.
    ///
    /// Example 1:
    /// Input: n = 2
    /// Output: ["1/2"]
    /// Explanation: "1/2" is the only unique fraction with a denominator 
    /// less-than-or-equal-to 2.
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: ["1/2","1/3","2/3"]
    ///
    /// Example 3:
    /// Input: n = 4
    /// Output: ["1/2","1/3","1/4","2/3","3/4"]
    /// Explanation: "2/4" is not a simplified fraction because it can be 
    /// simplified to "1/2".
    ///
    /// Example 4:
    /// Input: n = 1
    /// Output: []
    ///
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// </summary>
    vector<string> simplifiedFractions(int n);

    /// <summary>
    /// Leet code #1453. Maximum Number of Darts Inside of a Circular Dartboard
    ///                  
    /// Hard
    ///
    /// You have a very large square wall and a circular dartboard placed on 
    /// the wall. You have been challenged to throw darts into the board 
    /// blindfolded. Darts thrown at the wall are represented as an array of 
    /// points on a 2D plane. 
    ///
    /// Return the maximum number of points that are within or lie on any 
    /// circular dartboard of radius r.
    /// 
    /// Example 1: 
    /// Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
    /// Output: 4
    /// Explanation: Circle dartboard with center in (0,0) and radius = 2 
    /// contain all points.
    ///
    /// Example 2:
    /// Input: points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
    /// Output: 5
    /// Explanation: Circle dartboard with center in (0,4) and radius = 5 
    /// contain all points except the point (7,8).
    ///
    /// Example 3:
    /// Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
    /// Output: 1
    ///
    /// Example 4:
    /// Input: points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
    /// Output: 4
    ///
    /// Constraints:
    /// 1. 1 <= points.length <= 100
    /// 2. points[i].length == 2
    /// 3. -10^4 <= points[i][0], points[i][1] <= 10^4
    /// 4. 1 <= r <= 5000
    /// </summary>
    int numPoints(vector<vector<int>>& points, int r);

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
    /// Ugly numbers are positive numbers whose prime factors only include 
    /// 2, 3, 5. For example, 6, 8 are ugly 
    /// while 14 is not ugly since it includes another prime factor 7. 
    /// Note that 1 is typically treated as an ugly number. 
    /// </summary>
    bool isUgly(int num);

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
    /// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
    /// 11, ... is a 0, which is part of the number 10.
    /// </summary>
    int findNthDigit(int n);

    /// <summary>
    /// Leet code #386. Lexicographical Numbers
    ///
    /// Given an integer n, return 1 - n in lexicographical order. 
    /// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9]. 
    /// Please optimize your algorithm to use less time and space. The input 
    /// size may be as large as 5,000,000. 
    /// </summary>
    vector<int> lexicalOrder(int n);

    /// <summary>
    /// Leet code #233. Number of Digit One 
    /// </summary>
    int countDigitOne(string& str_n, int is_last, int index, vector<int> &cache);

    /// <summary>
    /// Leet code #233. Number of Digit One 
    ///
    /// Given an integer n, count the total number of digit 1 appearing 
    /// in all non-negative integers less than or equal to n.
    /// For example: 
    /// Given n = 13,
    /// Return 6, because digit 1 occurred in the following numbers: 
    /// 1, 10, 11, 12, 13. 
    /// Hint: 
    /// 1.Beware of overflow.
    /// </summary>
    int countDigitOne(int n);

    /// <summary>
    /// Leet code #1067. Digit Count in Range
    /// </summary>
    int digitsCount(string& str_n, int d, int is_first, int is_last, int index, vector<int>& cache);

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
    /// Leet code #357. Count Numbers with Unique Digits
    ///
    /// Given a non-negative integer n, count all numbers with unique digits, 
    /// x, where 0 <= x < 10^n.
    ///
    /// Example: 
    /// Given n = 2, return 91. (The answer should be the total numbers in 
    /// the range of 0 <= x < 100, excluding [11,22,33,44,55,66,77,88,99]) 
    /// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13. 
    /// Hint:
    /// 1.A direct way is to use the backtracking approach.
    /// 2.Backtracking should contains three states which are (the current number, number 
    //// of steps to get that number and a bitmask which represent 
    /// which number is marked as visited so far in the current number). Start with state 
    /// (0,0,0) and count all valid number till we reach number of steps equals to 10n.
    /// 3.This problem can also be solved using a dynamic programming approach and some
    /// knowledge of combinatorics.
    /// 4.Let f(k) = count of numbers with unique digits with length equals k.
    /// 5.f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 
    /// because a number cannot start with 0].
    /// </summary>
    int countNumbersWithUniqueDigits(int n);

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
    int pickRandom(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1012. Numbers With Repeated Digits
    /// </summary>
    int numDupDigitsAtMostN(string& str_n, int index, int leading, int is_last, int bit_mask, vector<vector<int>>& cache);

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


    /// <summary>
    /// Leet code #1000. Minimum Cost to Merge Stones
    /// </summary>
    int mergeStones(int i, int j, int m, int K, vector<vector<vector<int>>>& dp, vector<int>& sum);

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
    /// Leet code #964. Least Operators to Express Number
    /// </summary>
    int leastOpsExpressTarget(int exp, int x, int target, unordered_map<int, unordered_map<int, int>>& cache);

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
    /// Leet code # 517. Super Washing Machines 
    ///
    /// You have n super washing machines on a line. Initially, 
    /// each washing machine has some dresses or is empty.
    /// 
    /// For each move, you could choose any m (1 <= m <= n) washing machines, 
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
    /// Leet code #1467. Probability of a Two Boxes Having The Same Number of 
    ///                  Distinct Balls
    /// </summary>
    double getProbability(vector<int>& balls, int index, double sum_count, 
        int left_count, int right_count, int left_color, int right_color, 
        int ball_count);

    /// <summary>
    /// Leet code #1467. Probability of a Two Boxes Having The Same Number of 
    ///                  Distinct Balls
    /// 
    /// Hard
    ///
    /// Given 2n balls of k distinct colors. You will be given an integer 
    /// array balls of size k where balls[i] is the number of balls of 
    /// color i. 
    ///
    /// All the balls will be shuffled uniformly at random, then we will 
    /// distribute the first n balls to the first box and the remaining n 
    /// balls to the other box (Please read the explanation of the second 
    /// example carefully).
    ///
    /// Please note that the two boxes are considered different. For 
    /// example, if we have two balls of colors a and b, and two boxes [] 
    /// and (), then the distribution [a] (b) is considered different than 
    /// the distribution [b] (a) (Please read the explanation of the first 
    /// example carefully).
    ///
    /// We want to calculate the probability that the two boxes have the same 
    /// number of distinct balls.
    /// 
    /// Example 1:
    /// Input: balls = [1,1]
    /// Output: 1.00000
    /// Explanation: Only 2 ways to divide the balls equally:
    /// - A ball of color 1 to box 1 and a ball of color 2 to box 2
    /// - A ball of color 2 to box 1 and a ball of color 1 to box 2
    /// In both ways, the number of distinct colors in each box is equal. 
    /// The probability is 2/2 = 1
    ///
    /// Example 2:
    /// Input: balls = [2,1,1]
    /// Output: 0.66667
    /// Explanation: We have the set of balls [1, 1, 2, 3]
    /// This set of balls will be shuffled randomly and we may have one of 
    /// the 12 distinct shuffles with equale probability (i.e. 1/12):
    /// [1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], 
    /// [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], 
    /// [3,1 / 2,1], [3,2 / 1,1]
    /// After that we add the first two balls to the first box and the 
    /// second two balls to the second box.
    /// We can see that 8 of these 12 possible random distributions have the 
    /// same number of distinct colors of balls in each box.
    /// Probability is 8/12 = 0.66667
    ///
    /// Example 3:
    /// Input: balls = [1,2,1,2]
    /// Output: 0.60000
    /// Explanation: The set of balls is [1, 2, 2, 3, 4, 4]. It is hard to 
    /// display all the 180 possible random shuffles of this set but it is 
    /// easy to check that 108 of them will have the same number of distinct 
    /// colors in each box.
    /// Probability = 108 / 180 = 0.6
    ///
    /// Example 4:
    /// Input: balls = [3,2,1]
    /// Output: 0.30000
    /// Explanation: The set of balls is [1, 1, 1, 2, 2, 3]. It is hard to 
    /// display all the 60 possible random shuffles of this set but it is 
    /// easy to check that 18 of them will have the same number of distinct 
    /// colors in each box.
    /// Probability = 18 / 60 = 0.3
    ///
    /// Example 5:
    /// Input: balls = [6,6,6,6,6,6]
    /// Output: 0.90327
    /// Constraints:
    /// 1. 1 <= balls.length <= 8
    /// 2. 1 <= balls[i] <= 6
    /// 3. sum(balls) is even.
    /// 4. Answers within 10^-5 of the actual value will be accepted as 
    ///    correct.
    /// </summary>
    double getProbability(vector<int>& balls);

    /// <summary>
    /// Leet code #1464. Maximum Product of Two Elements in an Array 
    /// 
    /// Easy
    ///
    /// Given the array of integers nums, you will choose two different 
    /// indices i and j of that array. Return the maximum value of 
    /// (nums[i]-1)*(nums[j]-1).
    /// 
    /// Example 1:
    /// Input: nums = [3,4,5,2]
    /// Output: 12 
    /// Explanation: If you choose the indices i=1 and j=2 
    /// (indexed from 0), you will get the maximum value, that is, 
    /// (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
    ///
    /// Example 2:
    /// Input: nums = [1,5,4,5]
    /// Output: 16
    /// Explanation: Choosing the indices i=1 and j=3 (indexed from 0), 
    /// you will get the maximum value of (5-1)*(5-1) = 16.
    ///
    /// Example 3:
    /// Input: nums = [3,7]
    /// Output: 12
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 500
    /// 2. 1 <= nums[i] <= 10^3
    /// </summary>
    int maxProduct(vector<int>& nums);

    /// <summary>
    /// Leet code #1465. Maximum Area of a Piece of Cake After Horizontal 
    ///                  and Vertical Cuts 
    /// 
    /// Medium
    ///
    /// Given a rectangular cake with height h and width w, and two arrays of 
    /// integers horizontalCuts and verticalCuts where horizontalCuts[i] is 
    /// the distance from the top of the rectangular cake to the ith horizontal
    /// cut and similarly, verticalCuts[j] is the distance from the left of the
    /// rectangular cake to the jth vertical cut.
    ///
    /// Return the maximum area of a piece of cake after you cut at each 
    /// horizontal and vertical position provided in the arrays horizontalCuts 
    /// and verticalCuts. Since the answer can be a huge number, return this 
    /// modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
    /// Output: 4 
    /// Explanation: The figure above represents the given rectangular cake. 
    /// Red lines are the horizontal and vertical cuts. After you cut the cake, 
    /// the green piece of cake has the maximum area.
    ///
    /// Example 2:
    /// Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
    /// Output: 6
    /// Explanation: The figure above represents the given rectangular cake. 
    /// Red lines are the horizontal and vertical cuts. After you cut the 
    /// cake, the green and yellow pieces of cake have the maximum area.
    ///
    /// Example 3:
    /// Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
    /// Output: 9
    ///
    /// Constraints:
    /// 1. 2 <= h, w <= 10^9
    /// 2. 1 <= horizontalCuts.length < min(h, 10^5)
    /// 3. 1 <= verticalCuts.length < min(w, 10^5)
    /// 4. 1 <= horizontalCuts[i] < h
    /// 5. 1 <= verticalCuts[i] < w
    /// 6. It is guaranteed that all elements in horizontalCuts are distinct.
    /// 7. It is guaranteed that all elements in verticalCuts are distinct.
    /// </summary>
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts);

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
    /// Leet code #1492. The kth Factor of n
    /// 
    /// Medium
    ///
    /// Given two positive integers n and k.
    ///
    /// A factor of an integer n is defined as an integer i where n % i == 0.
    ///
    /// Consider a list of all factors of n sorted in ascending order, return 
    /// the kth factor in this list or return -1 if n has less than k factors.
    /// 
    /// Example 1:
    /// Input: n = 12, k = 3
    /// Output: 3
    /// Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
    ///
    /// Example 2:
    /// Input: n = 7, k = 2
    /// Output: 7
    /// Explanation: Factors list is [1, 7], the 2nd factor is 7.
    ///
    /// Example 3:
    /// Input: n = 4, k = 4
    /// Output: -1
    /// Explanation: Factors list is [1, 2, 4], there is only 3 factors. We 
    /// should return -1.
    ///
    /// Example 4:
    /// Input: n = 1, k = 1
    /// Output: 1
    /// Explanation: Factors list is [1], the 1st factor is 1.
    ///
    /// Example 5:
    /// Input: n = 1000, k = 3
    /// Output: 4
    /// Explanation: Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 
    /// 125, 200, 250, 500, 1000].
    ///
    /// Constraints:
    /// 1. 1 <= k <= n <= 1000
    /// </summary>
    int kthFactor(int n, int k);

    /// <summary>
    /// Leet code #1503. Last Moment Before All Ants Fall Out of a Plank
    /// 
    /// Medium
    ///
    /// We have a wooden plank of the length n units. Some ants are walking 
    /// on the plank, each ant moves with speed 1 unit per second. Some of 
    /// the ants move to the left, the other move to the right.
    /// 
    /// When two ants moving in two different directions meet at some point, 
    /// they change their directions and continue moving again. Assume 
    /// changing directions doesn't take any additional time.
    ///
    /// When an ant reaches one end of the plank at a time t, it falls out of 
    /// the plank imediately.
    ///
    /// Given an integer n and two integer arrays left and right, the 
    /// positions of the ants moving to the left and the right. Return the 
    /// moment when the last ant(s) fall out of the plank.
    /// 
    /// Example 1:
    /// Input: n = 4, left = [4,3], right = [0,1]
    /// Output: 4
    /// Explanation: In the image above:
    /// -The ant at index 0 is named A and going to the right.
    /// -The ant at index 1 is named B and going to the right.
    /// -The ant at index 3 is named C and going to the left.
    /// -The ant at index 4 is named D and going to the left.
    /// Note that the last moment when an ant was on the plank is t = 4 
    /// second, after that it falls imediately out of the plank. (i.e. We can 
    /// say that at t = 4.0000000001, there is no ants on the plank).
    ///
    /// Example 2:
    /// Input: n = 7, left = [], right = [0,1,2,3,4,5,6,7]
    /// Output: 7
    /// Explanation: All ants are going to the right, the ant at index 0 
    /// needs 7 seconds to fall.
    ///
    /// Example 3:
    /// 
    /// Input: n = 7, left = [0,1,2,3,4,5,6,7], right = []
    /// Output: 7
    /// Explanation: All ants are going to the left, the ant at index 7 
    /// needs 7 seconds to fall.
    ///
    /// Example 4:
    /// Input: n = 9, left = [5], right = [4]
    /// Output: 5
    /// Explanation: At t = 1 second, both ants will be at the same intial 
    /// position but with different direction.
    ///
    /// Example 5:
    ///
    /// Input: n = 6, left = [6], right = [0]
    /// Output: 6
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// 2. 0 <= left.length <= n + 1
    /// 3. 0 <= left[i] <= n
    /// 4. 0 <= right.length <= n + 1
    /// 5. 0 <= right[i] <= n
    /// 5. 1 <= left.length + right.length <= n + 1
    /// 6. All values of left and right are unique, and each value can appear 
    ///    only in one of the two arrays.
    /// </summary>
    int getLastMoment(int n, vector<int>& left, vector<int>& right); 

    /// <summary>
    /// Leet code #1515. Best Position for a Service Centre
    /// </summary>
    double getMinDistSum(double x, double y, vector<vector<int>>& positions);

    /// <summary>
    /// Leet code #1515. Best Position for a Service Centre
    /// 
    /// Hard
    ///
    /// A delivery company wants to build a new service centre in a new city. 
    /// The company knows the positions of all the customers in this city on 
    /// a 2D-Map and wants to build the new centre in a position such that 
    /// the sum of the euclidean distances to all customers is minimum.
    /// Given an array positions where positions[i] = [xi, yi] is the position 
    /// of the ith customer on the map, return the minimum sum of the 
    /// euclidean distances to all customers.
    ///
    /// In other words, you need to choose the position of the service centre 
    /// [xcentre, ycentre] such that the following formula is minimized:
    /// Answers within 10^-5 of the actual value will be accepted.
    /// 
    /// Example 1:
    /// Input: positions = [[0,1],[1,0],[1,2],[2,1]]
    /// Output: 4.00000
    /// Explanation: As shown, you can see that choosing 
    /// [xcentre, ycentre] = [1, 1] will make the distance to each 
    /// customer = 1, the sum of all distances is 4 which is the minimum 
    /// possible we can achieve.
    ///
    /// Example 2:
    /// Input: positions = [[1,1],[3,3]]
    /// Output: 2.82843
    /// Explanation: The minimum possible sum of distances = 
    /// sqrt(2) + sqrt(2) = 2.82843
    ///
    /// Example 3:
    /// Input: positions = [[1,1]]
    /// Output: 0.00000
    ///
    /// Example 4:
    /// Input: positions = [[1,1],[0,0],[2,0]]
    /// Output: 2.73205
    /// Explanation: At the first glance, you may think that locating the 
    /// centre at [1, 0] will achieve the minimum sum, but locating it 
    /// at [1, 0] will make the sum of distances = 3.
    /// Try to locate the centre at [1.0, 0.5773502711] you will see that 
    /// the sum of distances is 2.73205.
    /// Be careful with the precision!
    ///
    /// Example 5:
    /// Input: positions = [[0,1],[3,2],[4,5],[7,6],[8,9],[11,1],[2,12]]
    /// Output: 32.94036
    /// Explanation: You can use [4.3460852395, 4.9813795505] as the position 
    /// of the centre.
    ///
    /// Constraints:
    /// 1. 1 <= positions.length <= 50
    /// 2. positions[i].length == 2
    /// 3. 0 <= positions[i][0], positions[i][1] <= 100
    /// </summary>
    double getMinDistSum(vector<vector<int>>& positions);

    /// <summary>
    /// Leet code #1518. Water Bottles
    /// 
    /// Easy
    ///
    /// Given numBottles full water bottles, you can exchange numExchange 
    /// empty water bottles for one full water bottle.
    ///
    /// The operation of drinking a full water bottle turns it into an empty 
    /// bottle.
    ///
    /// Return the maximum number of water bottles you can drink.
    /// Example 1:
    /// Input: numBottles = 9, numExchange = 3
    /// Output: 13
    /// Explanation: You can exchange 3 empty bottles to get 1 full water 
    /// bottle.
    /// Number of water bottles you can drink: 9 + 3 + 1 = 13.
    ///
    /// Example 2:
    /// Input: numBottles = 15, numExchange = 4
    /// Output: 19
    /// Explanation: You can exchange 4 empty bottles to get 1 full water 
    /// bottle. 
    /// Number of water bottles you can drink: 15 + 3 + 1 = 19.
    ///
    /// Example 3:
    /// Input: numBottles = 5, numExchange = 5
    /// Output: 6
    ///
    /// Example 4:
    /// Input: numBottles = 2, numExchange = 3
    /// Output: 2
    /// 
    /// Constraints:
    /// 1. 1 <= numBottles <= 100
    /// 2. 2 <= numExchange <= 100
    /// </summary>
    int numWaterBottles(int numBottles, int numExchange);

    /// <summary>
    /// Leet code #1523. Count Odd Numbers in an Interval Range
    /// 
    /// Easy
    ///
    /// Given two non-negative integers low and high. Return the count of odd 
    /// numbers between low and high (inclusive).
    ///
    /// Example 1:
    /// Input: low = 3, high = 7
    /// Output: 3
    /// Explanation: The odd numbers between 3 and 7 are [3,5,7].
    ///
    /// Example 2:
    /// Input: low = 8, high = 10
    /// Output: 1
    /// Explanation: The odd numbers between 8 and 10 are [9].
    /// 
    /// Constraints:
    /// 1. 0 <= low <= high <= 10^9
    /// </summary>
    int countOdds(int low, int high);

    /// <summary>
    /// Leet code #1551. Minimum Operations to Make Array EqualMedium
    /// 
    /// Medium
    ///
    /// You have an array arr of length n where arr[i] = (2 * i) + 1 for 
    /// all valid values of i (i.e. 0 <= i < n).
    ///
    /// In one operation, you can select two indices x and y where 
    /// 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] 
    /// (i.e. perform arr[x] -=1 and arr[y] += 1). The goal is to make all 
    /// the elements of the array equal. It is guaranteed that all the 
    /// elements of the array can be made equal using some operations.
    ///
    /// Given an integer n, the length of the array. Return the minimum 
    /// number of operations needed to make all the elements of arr equal.
    ///
    /// Example 1:
    /// Input: n = 3
    /// Output: 2
    /// Explanation: arr = [1, 3, 5]
    /// First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
    /// In the second operation choose x = 2 and y = 0 again, thus 
    /// arr = [3, 3, 3].
    ///
    /// Example 2:
    /// Input: n = 6
    /// Output: 9
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// </summary>
    int minOperations(int n);

    /// <summary>
    /// Leet code #1558. Minimum Numbers of Function Calls to Make Target Array
    /// 
    /// Medium
    ///
    /// Your task is to form an integer array nums from an initial array of 
    /// zeros arr that is the same size as nums.
    ///
    /// Return the minimum number of function calls to make nums from arr.
    ///
    /// The answer is guaranteed to fit in a 32-bit signed integer.
    /// 
    /// Example 1:
    /// Input: nums = [1,5]
    /// Output: 5
    /// Explanation: Increment by 1 (second element): [0, 0] to 
    /// get [0, 1] (1 operation).
    /// Double all the elements: [0, 1] -> [0, 2] -> [0, 4] (2 operations).
    /// Increment by 1 (both elements)  [0, 4] -> [1, 4] -> [1, 5] 
    /// (2 operations).
    /// Total of operations: 1 + 2 + 2 = 5.
    ///
    /// Example 2:
    /// Input: nums = [2,2]
    /// Output: 3
    /// Explanation: Increment by 1 (both elements) [0, 0] -> [0, 1] -> [1, 1] 
    /// (2 operations).
    /// Double all the elements: [1, 1] -> [2, 2] (1 operation).
    /// Total of operations: 2 + 1 = 3.
    ///
    /// Example 3:
    /// Input: nums = [4,2,5]
    /// Output: 6
    /// Explanation: (initial)[0,0,0] -> [1,0,0] -> [1,0,1] -> [2,0,2] -> 
    /// [2,1,2] -> [4,2,4] -> [4,2,5](nums).
    ///
    /// Example 4:
    /// Input: nums = [3,2,2,4]
    /// Output: 7
    ///
    /// Example 5:
    /// Input: nums = [2,4,8,16]
    /// Output: 8
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// </summary>
    int minOperations(vector<int>& nums);

    /// <summary>
    /// Leet code #1560. Most Visited Sector in a Circular Track
    /// 
    /// Easy
    ///
    /// Given an integer n and an integer array rounds. We have a circular 
    /// track which consists of n sectors labeled from 1 to n. A marathon 
    /// will be held on this track, the marathon consists of m rounds. The 
    /// ith round starts at sector rounds[i - 1] and ends at sector rounds[i]. 
    /// For example, round 1 starts at sector rounds[0] and ends at sector 
    /// rounds[1]
    ///
    /// Return an array of the most visited sectors sorted in ascending order.
    /// Notice that you circulate the track in ascending order of sector 
    /// numbers in the counter-clockwise direction (See the first example).
    /// 
    /// Example 1:
    /// Input: n = 4, rounds = [1,3,1,2]
    /// Output: [1,2]
    /// Explanation: The marathon starts at sector 1. The order of the visited 
    /// sectors is as follows:
    /// 1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2) --> 2 
    /// (end of round 3 and the marathon)
    /// We can see that both sectors 1 and 2 are visited twice and they are the 
    /// most visited sectors. Sectors 3 and 4 are visited only once.
    ///
    /// Example 2:
    /// Input: n = 2, rounds = [2,1,2,1,2,1,2,1,2]
    /// Output: [2]
    ///
    /// Example 3:
    /// Input: n = 7, rounds = [1,3,5,7]
    /// Output: [1,2,3,4,5,6,7]
    /// Constraints:
    /// 1. 2 <= n <= 100
    /// 2. 1 <= m <= 100
    /// 3. rounds.length == m + 1
    /// 4. 1 <= rounds[i] <= n
    /// 5. rounds[i] != rounds[i + 1] for 0 <= i < m
    /// </summary>
    vector<int> mostVisited(int n, vector<int>& rounds);

    /// <summary>
    /// Leet code #1561. Maximum Number of Coins You Can Get
    /// 
    /// Medium
    ///
    /// There are 3n piles of coins of varying size, you and your friends 
    /// will take piles of coins as follows:
    ///
    /// In each step, you will choose any 3 piles of coins (not necessarily 
    /// consecutive).
    /// Of your choice, Alice will pick the pile with the maximum number of 
    /// coins.
    /// You will pick the next pile with maximum number of coins.
    /// Your friend Bob will pick the last pile.
    /// Repeat until there are no more piles of coins.
    /// Given an array of integers piles where piles[i] is the number of coins 
    /// in the ith pile.
    ///
    /// Return the maximum number of coins which you can have.
    /// 
    /// Example 1:
    /// Input: piles = [2,4,1,2,7,8]
    /// Output: 9
    /// Explanation: Choose the triplet (2, 7, 8), Alice Pick the pile with 
    /// 8 coins, you the pile with 7 coins and Bob the last one.
    /// Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you 
    /// the pile with 2 coins and Bob the last one.
    /// The maximum number of coins which you can have are: 7 + 2 = 9.
    /// On the other hand if we choose this arrangement (1, 2, 8), (2, 4, 7) you 
    /// only get 2 + 4 = 6 coins which is not optimal.
    ///
    /// Example 2:
    /// Input: piles = [2,4,5]
    /// Output: 4
    ///
    /// Example 3:   
    /// Input: piles = [9,8,7,6,5,1,2,3,4]
    /// Output: 18
    ///
    /// Constraints:
    /// 1. 3 <= piles.length <= 10^5
    /// 2. piles.length % 3 == 0
    /// 3. 1 <= piles[i] <= 10^4
    /// </summary>
    int maxCoins(vector<int>& piles);

    /// <summary>
    /// Leet code #1610. Maximum Number of Visible Points
    /// 
    /// Hard
    ///
    /// You are given an array points, an integer angle, and your location, 
    /// where location = [pos[x], pos[y]] and points[i] = [x[i], y[i]] both 
    /// denote integral coordinates on the X-Y plane.
    ///
    /// Initially, you are facing directly east from your position. You cannot 
    /// move from your position, but you can rotate. In other words, pos[x] 
    /// and pos[y] cannot be changed. Your field of view in degrees is 
    /// represented by angle, determining how wide you can see from any given 
    /// view direction. Let d be the amount in degrees that you rotate 
    /// counterclockwise. Then, your field of view is the inclusive range of 
    /// angles [d - angle/2, d + angle/2].
    /// 
    /// You can see some set of points if, for each point, the angle formed by 
    /// the point, your position, and the immediate east direction from your 
    /// position is in your field of view.
    ///
    /// There can be multiple points at one coordinate. There may be points at 
    /// your location, and you can always see these points regardless of your 
    /// rotation. Points do not obstruct your vision to other points.
    ///
    /// Return the maximum number of points you can see.
    /// 
    /// Example 1:
    /// Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
    /// Output: 3
    /// Explanation: The shaded region represents your field of view. All 
    /// points can be made visible in your field of view, including [3,3] 
    /// even though [2,2] is in front and in the same line of sight.
    ///
    /// Example 2:
    /// Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
    /// Output: 4
    /// Explanation: All points can be made visible in your field of view, 
    /// including the one at your location.
    ///
    /// Example 3:
    /// Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
    /// Output: 1
    /// Explanation: You can only see one of the two points, as shown above.
    ///
    /// Constraints:
    /// 1. 1 <= points.length <= 10^5
    /// 2. points[i].length == 2
    /// 3. location.length == 2
    /// 4. 0 <= angle < 360
    /// 5. 0 <= pos[x], pos[y], x[i], y[i] <= 10^9
    /// </summary>
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location);

    /// <summary>
    /// Leet code #1611. Minimum One Bit Operations to Make Integers Zero
    /// 
    /// Hard
    ///
    /// Given an integer n, you must transform it into 0 using the following 
    /// operations any number of times:
    ///
    /// Change the rightmost (0th) bit in the binary representation of n.
    /// Change the ith bit in the binary representation of n if the (i-1)th 
    /// bit is set to 1 and the (i-2)th through 0th bits are set to 0.
    /// Return the minimum number of operations to transform n into 0.
    /// 
    /// Example 1:
    /// Input: n = 0
    /// Output: 0
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: 2
    /// Explanation: The binary representation of 3 is "11".
    /// "11" -> "01" with the 2nd operation since the 0th bit is 1.
    /// "01" -> "00" with the 1st operation.
    /// Example 3:
    ///
    /// Input: n = 6
    /// Output: 4
    /// Explanation: The binary representation of 6 is "110".
    /// "110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th 
    /// through 0th bits are 0.
    /// "010" -> "011" with the 1st operation.
    /// "011" -> "001" with the 2nd operation since the 0th bit is 1.
    /// "001" -> "000" with the 1st operation.
    ///
    /// Example 4:
    /// Input: n = 9
    /// Output: 14
    ///
    /// Example 5:
    /// Input: n = 333
    /// Output: 393
    /// 
    /// Constraints:
    /// 1. 0 <= n <= 10^9
    /// </summary>
    int minimumOneBitOperations(int n);

    /// <summary>
    /// Leet code #1619. Mean of Array After Removing Some Elements
    /// 
    /// Easy
    ///
    /// Given an integer array arr, return the mean of the remaining integers 
    /// after removing the smallest 5% and the largest 5% of the elements.
    ///
    /// Answers within 10-5 of the actual answer will be considered accepted.
    /// 
    /// Example 1:
    /// Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
    /// Output: 2.00000
    /// Explanation: After erasing the minimum and the maximum values of this 
    /// array, all elements are equal to 2, so the mean is 2.
    ///
    /// Example 2:
    /// Input: arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
    /// Output: 4.00000
    ///
    /// Example 3:
    ///
    /// Input: arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,
    /// 8,5,10,8,6,6,1,0,6,10,8,2,3,4]
    /// Output: 4.77778
    ///
    /// Example 4:
    /// Input: arr = [9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,
    /// 1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3]
    /// Output: 5.27778
    ///
    /// Example 5:
    /// Input: arr = [4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,
    /// 3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,
    /// 8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1]
    /// Output: 5.29167
    ///
    /// Constraints:
    /// 1. 20 <= arr.length <= 1000
    /// 2. arr.length is a multiple of 20.
    /// 3. 0 <= arr[i] <= 10^5
    /// </summary>
    double trimMean(vector<int>& arr);

    /// <summary>
    /// Leet code #1620. Coordinate With Maximum Network Quality
    /// 
    /// Medium
    ///
    /// You are given an array of network towers towers and an integer radius, 
    /// where towers[i] = [xi, yi, qi] denotes the ith network tower with 
    /// location (xi, yi) and quality factor qi. All the coordinates are 
    /// integral coordinates on the X-Y plane, and the distance between two 
    /// coordinates is the Euclidean distance.
    ///
    /// The integer radius denotes the maximum distance in which the tower is 
    /// reachable. The tower is reachable if the distance is less than or equal 
    /// to radius. Outside that distance, the signal becomes garbled, and the 
    /// tower is not reachable.
    ///
    /// The signal quality of the ith tower at a coordinate (x, y) is 
    /// calculated with the formula (qi / (1 + d)), where d is the distance 
    /// between the tower and the coordinate. The network quality at a 
    /// coordinate is the sum of the signal qualities from all the reachable 
    /// towers.
    /// 
    /// Return the integral coordinate where the network quality is maximum. If 
    /// there are multiple coordinates with the same network quality, return 
    /// the lexicographically minimum coordinate.
    ///
    /// Note:
    /// 1. A coordinate (x1, y1) is lexicographically smaller than (x2, y2) if 
    ///    either x1 < x2 or x1 == x2 and y1 < y2.
    /// 2. (val) is the greatest integer less than or equal to val (the floor 
    ///    function).
    ///
    /// Example 1:
    /// Input: towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
    /// Output: [2,1]
    /// Explanation: 
    /// At coordinate (2, 1) the total quality is 13
    /// - Quality of 7 from (2, 1) results in (7 / (1 + sqrt(0)) = 7
    /// - Quality of 5 from (1, 2) results in (5 / (1 + sqrt(2)) = 2.07 = 2
    /// - Quality of 9 from (3, 1) results in (9 / (1 + sqrt(1)) = 4.5 = 4
    /// No other coordinate has higher quality.
    ///
    /// Example 2:
    /// Input: towers = [[23,11,21]], radius = 9
    /// Output: [23,11]
    ///
    /// Example 3:
    /// Input: towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
    /// Output: [1,2]
    ///
    /// Example 4:
    /// Input: towers = [[2,1,9],[0,1,9]], radius = 2
    /// Output: [0,1]
    /// Explanation: Both (0, 1) and (2, 1) are optimal in terms of quality 
    /// but (0, 1) is lexicograpically minimal.
    ///
    /// Constraints:
    /// 1. 1 <= towers.length <= 50
    /// 2. towers[i].length == 3
    /// 3. 0 <= xi, yi, qi <= 50
    /// 4. 1 <= radius <= 50
    /// </summary>
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius);

    /// <summary>
    /// Leet code #1643. Kth Smallest Instructions
    /// 
    /// Hard
    ///
    /// Bob is standing at cell (0, 0), and he wants to reach destination: 
    /// (row, column). He can only travel right and down. You are going to 
    /// help Bob by providing instructions for him to reach destination.
    ///
    /// The instructions are represented as a string, where each character 
    /// is either:
    ///
    /// 'H', meaning move horizontally (go right), or
    /// 'V', meaning move vertically (go down).
    /// Multiple instructions will lead Bob to destination. For example, if 
    /// destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.
    ///
    /// However, Bob is very picky. Bob has a lucky number k, and he wants the 
    /// kth lexicographically smallest instructions that will lead him to 
    /// destination. k is 1-indexed.
    ///
    /// Given an integer array destination and an integer k, return the kth 
    /// lexicographically smallest instructions that will take Bob to 
    /// destination.
    /// 
    /// Example 1:
    /// Input: destination = [2,3], k = 1
    /// Output: "HHHVV"
    /// Explanation: All the instructions that reach (2, 3) in lexicographic 
    /// order are as follows:
    /// ["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", 
    /// "VHVHH", "VVHHH"].
    ///
    /// Example 2: 
    /// Input: destination = [2,3], k = 2
    /// Output: "HHVHV"
    ///
    /// Example 3:
    /// Input: destination = [2,3], k = 3
    /// Output: "HHVVH"
    /// Constraints:
    /// 1. destination.length == 2
    /// 2. 1 <= row, column <= 15
    /// 3. 1 <= k <= nCr(row + column, row), where nCr(a, b) denotes a choose b​​​​​.
    /// </summary>
    string kthSmallestPath(vector<int>& destination, int k);

    /// <summary>
    /// Leet code #1648. Sell Diminishing-Valued Colored Balls
    /// 
    /// Medium
    ///
    /// You have an inventory of different colored balls, and there is a customer 
    /// that wants orders balls of any color.
    ///
    /// The customer weirdly values the colored balls. Each colored ball's value 
    /// is the number of balls of that color you currently have in your inventory. 
    /// For example, if you own 6 yellow balls, the customer would pay 6 for the 
    /// first yellow ball. After the transaction, there are only 5 yellow balls 
    /// left, so the next yellow ball is then valued at 5 (i.e., the value of the 
    /// balls decreases as you sell more to the customer).
    ///
    /// You are given an integer array, inventory, where inventory[i] represents 
    /// the number of balls of the ith color that you initially own. You are also 
    /// given an integer orders, which represents the total number of balls that 
    /// the customer wants. You can sell the balls in any order.
    ///
    /// Return the maximum total value that you can attain after selling orders 
    /// colored balls. As the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: inventory = [2,5], orders = 4
    /// Output: 14
    /// Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 
    /// times (5 + 4 + 3).
    /// The maximum total value is 2 + 5 + 4 + 3 = 14.
    ///
    /// Example 2:
    /// Input: inventory = [3,5], orders = 6
    /// Output: 19
    /// Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 
    /// times (5 + 4 + 3 + 2).
    /// The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
    ///
    /// Example 3:
    /// Input: inventory = [2,8,4,10,6], orders = 20
    /// Output: 110
    ///
    /// Example 4:
    /// Input: inventory = [1000000000], orders = 1000000000
    /// Output: 21
    /// Explanation: Sell the 1st color 1000000000 times for a total value of 
    /// 500000000500000000. 500000000500000000 modulo 109 + 7 = 21.
    /// 
    /// Constraints:
    /// 1. 1 <= inventory.length <= 10^5
    /// 2. 1 <= inventory[i] <= 10^9
    /// 3. 1 <= orders <= min(sum(inventory[i]), 10^9)
    /// </summary>
    int maxProfit(vector<int>& inventory, int orders);

    /// <summary>
    /// Leet code #1663. Smallest String With A Given Numeric Value
    /// 
    /// Medium
    ///
    /// The numeric value of a lowercase character is defined as its position 
    /// (1-indexed) in the alphabet, so the numeric value of a is 1, the 
    /// numeric value of b is 2, the numeric value of c is 3, and so on.
    ///
    /// The numeric value of a string consisting of lowercase characters is 
    /// defined as the sum of its characters' numeric values. For example, 
    /// the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.
    ///
    /// You are given two integers n and k. Return the lexicographically 
    /// smallest string with length equal to n and numeric value equal to k.
    ///
    /// Note that a string x is lexicographically smaller than string y if x 
    /// comes before y in dictionary order, that is, either x is a prefix of y, 
    /// or if i is the first position such that x[i] != y[i], then x[i] comes 
    /// before y[i] in alphabetic order.
    ///
    /// Example 1:
    /// Input: n = 3, k = 27
    /// Output: "aay"
    /// Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it 
    /// is the smallest string with such a value and length equal to 3.
    ///
    /// Example 2:
    /// Input: n = 5, k = 73
    /// Output: "aaszz"
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. n <= k <= 26 * n
    /// </summary>
    string getSmallestString(int n, int k);

    /// <summary>
    /// Leet code #1680. Concatenation of Consecutive Binary Numbers
    /// 
    /// Medium
    /// 
    /// Given an integer n, return the decimal value of the binary string 
    /// formed by concatenating the binary representations of 1 to n in order, 
    /// modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 1
    /// Output: 1
    /// Explanation: "1" in binary corresponds to the decimal value 1. 
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: 27
    /// Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
    /// After concatenating them, we have "11011", which corresponds to the 
    /// decimal value 27.
    ///
    /// Example 3:
    /// Input: n = 12
    /// Output: 505379714
    /// Explanation: The concatenation results in 
    /// "1101110010111011110001001101010111100".
    /// The decimal value of that is 118505380540.
    /// After modulo 10^9 + 7, the result is 505379714.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// </summary>
    int concatenatedBinary(int n);

    /// <summary>
    /// Leet code #1688. Count of Matches in Tournament
    /// 
    /// Easy
    /// 
    /// You are given an integer n, the number of teams in a tournament that has 
    /// strange rules:
    ///
    /// If the current number of teams is even, each team gets paired with another 
    /// team. A total of n / 2 matches are played, and n / 2 teams advance to the 
    /// next round.
    /// If the current number of teams is odd, one team randomly advances in the 
    /// tournament, and the rest gets paired. A total of (n - 1) / 2 matches are 
    /// played, and (n - 1) / 2 + 1 teams advance to the next round.
    /// Return the number of matches played in the tournament until a winner is 
    /// decided.
    ///
    /// Example 1:
    /// Input: n = 7
    /// Output: 6
    /// Explanation: Details of the tournament: 
    /// - 1st Round: Teams = 7, Matches = 3, and 4 teams advance.
    /// - 2nd Round: Teams = 4, Matches = 2, and 2 teams advance.
    /// - 3rd Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
    /// Total number of matches = 3 + 2 + 1 = 6.
    ///
    /// Example 2:
    /// Input: n = 14
    /// Output: 13
    /// Explanation: Details of the tournament:
    /// - 1st Round: Teams = 14, Matches = 7, and 7 teams advance.
    /// - 2nd Round: Teams = 7, Matches = 3, and 4 teams advance.
    /// - 3rd Round: Teams = 4, Matches = 2, and 2 teams advance.
    /// - 4th Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
    /// Total number of matches = 7 + 3 + 2 + 1 = 13.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 200
    /// </summary>
    int numberOfMatches(int n);

    /// <summary>
    /// Leet code #1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
    /// 
    /// Medium
    /// 
    /// A decimal number is called deci-binary if each of its digits is either 0 
    /// or 1 without any leading zeros. For example, 101 and 1100 are deci-binary,
    /// while 112 and 3001 are not.
    ///
    /// Given a string n that represents a positive decimal integer, return the 
    /// minimum number of positive deci-binary numbers needed so that they sum 
    /// up to n.
    ///
    /// Example 1:
    /// Input: n = "32"
    /// Output: 3
    /// Explanation: 10 + 11 + 11 = 32
    ///
    /// Example 2:
    /// Input: n = "82734"
    /// Output: 8
    ///
    /// Example 3:
    /// Input: n = "27346209830709182346"
    /// Output: 9
    /// 
    /// Constraints:
    /// 1. 1 <= n.length <= 105
    /// 2. n consists of only digits.
    /// 3. n does not contain any leading zeros and represents a positive 
    ///    integer.
    /// </summary>
    int minPartitions(string n);

    /// <summary>
    /// Leet code #1716. Calculate Money in Leetcode Bank
    /// 
    /// Easy
    /// 
    /// Hercy wants to save money for his first car. He puts money in the 
    /// Leetcode bank every day.
    ///
    /// He starts by putting in $1 on Monday, the first day. Every day from 
    /// Tuesday to Sunday, he will put in $1 more than the day before. On 
    /// every subsequent Monday, he will put in $1 more than the previous 
    /// Monday.
    /// Given n, return the total amount of money he will have in the Leetcode 
    /// bank at the end of the nth day.
    /// 
    /// Example 1:
    /// Input: n = 4
    /// Output: 10
    /// Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
    ///
    /// Example 2:
    /// Input: n = 10
    /// Output: 37
    /// Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 
    /// 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy 
    /// only puts in $2.
    ///
    /// Example 3:
    /// Input: n = 20
    /// Output: 96
    /// Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 
    /// 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    int totalMoney(int n);

    /// <summary>
    /// Leet code 1742. Maximum Number of Balls in a Box
    /// 
    /// Easy
    /// 
    /// You are working in a ball factory where you have n balls numbered from
    /// lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), 
    /// and an infinite number of boxes numbered from 1 to infinity.
    /// 
    /// Your job at this factory is to put each ball in the box with a number 
    /// equal to the sum of digits of the ball's number. For example, the ball 
    /// number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball 
    /// number 10 will be put in the box number 1 + 0 = 1.
    ///
    /// Given two integers lowLimit and highLimit, return the number of balls 
    /// in the box with the most balls.
    ///
    /// Example 1:
    /// 
    /// Input: lowLimit = 1, highLimit = 10
    /// Output: 2
    /// Explanation:
    /// Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
    /// Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
    /// Box 1 has the most number of balls with 2 balls.
    ///
    /// Example 2:
    ///
    /// Input: lowLimit = 5, highLimit = 15
    /// Output: 2
    /// Explanation:
    /// Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
    /// Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
    /// Boxes 5 and 6 have the most number of balls with 2 balls in each.
    ///
    /// Example 3:
    /// Input: lowLimit = 19, highLimit = 28
    /// Output: 2
    /// Explanation:
    /// Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
    /// Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
    /// Box 10 has the most number of balls with 2 balls.
    ///
    /// Constraints:
    /// 1. 1 <= lowLimit <= highLimit <= 10^5
    /// </summary>
    int countBalls(int lowLimit, int highLimit);

    /// <summary>
    /// Leet code 1758. Minimum Changes To Make Alternating Binary String
    /// 
    /// Easy
    /// 
    /// You are given a string s consisting only of the characters '0' 
    /// and '1'. In one operation, you can change any '0' to '1' or vice 
    /// versa.
    ///
    /// The string is called alternating if no two adjacent characters are 
    /// equal. For example, the string "010" is alternating, while the 
    /// string "0100" is not.
    ///
    /// Return the minimum number of operations needed to make s alternating.
    /// 
    /// Example 1:
    /// Input: s = "0100"
    /// Output: 1
    /// Explanation: If you change the last character to '1', s will 
    /// be "0101", which is alternating.
    ///
    /// Example 2:
    /// Input: s = "10"
    /// Output: 0
    /// Explanation: s is already alternating.
    ///
    /// Example 3:
    /// Input: s = "1111"
    /// Output: 2
    /// Explanation: You need two operations to reach "0101" or "1010".
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 10^4
    /// 2. s[i] is either '0' or '1'.
    /// </summary>
    int minOperations(string s);

    /// <summary>
    /// Leet code 1735. Count Ways to Make Array With Product
    /// 
    /// Hard
    /// 
    /// You are given a 2D integer array, queries. For each queries[i], 
    /// where queries[i] = [ni, ki], find the number of different ways 
    /// you can place positive integers into an array of size ni such 
    /// that the product of the integers is ki. As the number of ways 
    /// may be too large, the answer to the ith query is the number of 
    /// ways modulo 109 + 7.
    ///
    /// Return an integer array answer where answer.length == 
    /// queries.length, and answer[i] is the answer to the ith query.
    ///
    /// Example 1:
    /// Input: queries = [[2,6],[5,1],[73,660]]
    /// Output: [4,1,50734910]
    /// Explanation: Each query is independent.
    /// [2,6]: There are 4 ways to fill an array of size 2 that 
    /// multiply to 6: [1,6], [2,3], [3,2], [6,1].
    /// [5,1]: There is 1 way to fill an array of size 5 that multiply 
    /// to 1: [1,1,1,1,1].
    /// [73,660]: There are 1050734917 ways to fill an array of size 73 
    /// that multiply to 660. 1050734917 modulo 109 + 7 = 50734910.
    /// Example 2:
    ///
    /// Input: queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
    /// Output: [1,2,3,10,5]
    /// 
    /// Constraints:
    /// 1. 1 <= queries.length <= 10^4
    /// 2. 1 <= ni, ki <= 10^4
    /// </summary>
    vector<int> waysToFillArray(vector<vector<int>>& queries);

    /// <summary>
    /// Leet code 1739. Building Boxes
    /// 
    /// Hard
    /// 
    /// You have a cubic storeroom where the width, length, and height of the 
    /// room are all equal to n units. You are asked to place n boxes in this 
    /// room where each box is a cube of unit side length. There are however 
    /// some rules to placing the boxes:
    ///
    /// You can place the boxes anywhere on the floor.
    /// If box x is placed on top of the box y, then each side of the four 
    /// vertical sides of the box y must either be adjacent to another box or 
    /// to a wall.
    /// Given an integer n, return the minimum possible number of boxes 
    /// touching the floor.
    /// 
    /// Example 1:
    /// Input: n = 3
    /// Output: 3
    /// Explanation: The figure above is for the placement of the three boxes.
    /// These boxes are placed in the corner of the room, where the corner is 
    /// on the left side.
    ///
    /// Example 2:
    /// Input: n = 4
    /// Output: 3
    /// Explanation: The figure above is for the placement of the four boxes.
    /// These boxes are placed in the corner of the room, where the corner is 
    /// on the left side.
    ///
    /// Example 3:
    /// Input: n = 10
    /// Output: 6
    /// Explanation: The figure above is for the placement of the ten boxes.
    /// These boxes are placed in the corner of the room, where the corner is 
    /// on the back side.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^9
    /// </summary>
    int minimumBoxes(int n);

    /// <summary>
    /// Leet code 1753. Maximum Score From Removing Stones
    /// 
    /// Medium
    /// 
    /// You are playing a solitaire game with three piles of stones of sizes 
    /// a, b and c respectively. Each turn you choose two different non-empty
    /// piles, take one stone from each, and add 1 point to your score. The 
    /// game stops when there are fewer than two non-empty piles (meaning 
    /// there are no more available moves).
    ///
    /// Given three integers a, b and c, return the maximum score you can get.
    ///
    /// Example 1:
    /// Input: a = 2, b = 4, c = 6
    /// Output: 6
    /// Explanation: The starting state is (2, 4, 6). One optimal set of 
    /// moves is:
    /// - Take from 1st and 3rd piles, state is now (1, 4, 5)
    /// - Take from 1st and 3rd piles, state is now (0, 4, 4)
    /// - Take from 2nd and 3rd piles, state is now (0, 3, 3)
    /// - Take from 2nd and 3rd piles, state is now (0, 2, 2)
    /// - Take from 2nd and 3rd piles, state is now (0, 1, 1)
    /// - Take from 2nd and 3rd piles, state is now (0, 0, 0)
    /// There are fewer than two non-empty piles, so the game ends. 
    /// Total: 6 points.
    ///
    /// Example 2:
    /// Input: a = 4, b = 4, c = 6
    /// Output: 7
    /// Explanation: The starting state is (4, 4, 6). One optimal set of 
    /// moves is:
    /// - Take from 1st and 2nd piles, state is now (3, 3, 6)
    /// - Take from 1st and 3rd piles, state is now (2, 3, 5)
    /// - Take from 1st and 3rd piles, state is now (1, 3, 4)
    /// - Take from 1st and 3rd piles, state is now (0, 3, 3)
    /// - Take from 2nd and 3rd piles, state is now (0, 2, 2)
    /// - Take from 2nd and 3rd piles, state is now (0, 1, 1)
    /// - Take from 2nd and 3rd piles, state is now (0, 0, 0)
    /// There are fewer than two non-empty piles, so the game ends. 
    /// Total: 7 points.
    ///
    /// Example 3:
    /// Input: a = 1, b = 8, c = 8
    /// Output: 8
    /// Explanation: One optimal set of moves is to take from the 2nd and 
    /// 3rd piles for 8 turns until they are empty.
    /// After that, there are fewer than two non-empty piles, so the game ends.
    /// 
    /// Constraints:
    /// 1. 1 <= a, b, c <= 10^5
    /// </summary>
    int maximumScore(int a, int b, int c);

    /// <summary>
    /// Leet code 1780. Check if Number is a Sum of Powers of Three
    /// 
    /// Medium
    /// 
    /// Given an integer n, return true if it is possible to represent n 
    /// as the sum of distinct powers of three. Otherwise, return false.
    ///  
    /// An integer y is a power of three if there exists an integer x such 
    /// that y == 3x.
    /// 
    /// Example 1:
    /// Input: n = 12
    /// Output: true
    /// Explanation: 12 = 31 + 32
    ///
    /// Example 2:
    /// Input: n = 91
    /// Output: true
    /// Explanation: 91 = 30 + 32 + 34
    ///
    /// Example 3:
    /// Input: n = 21
    /// Output: false
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^7
    /// </summary>
    bool checkPowersOfThree(int n);

    /// <summary>
    /// Leet code 1785. Minimum Elements to Add to Form a Given Sum
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums and two integers limit and goal. 
    /// The array nums has an interesting property that abs(nums[i]) <= limit 
    /// 
    /// You are given an integer array nums and two integers limit and goal. 
    /// The array nums has an interesting property that abs(nums[i]) <= limit.
    ///
    /// Return the minimum number of elements you need to add to make the 
    /// sum of the array equal to goal. The array must maintain its property 
    /// that abs(nums[i]) <= limit.
    ///
    /// Note that abs(x) equals x if x >= 0, and -x otherwise.
    /// 
    /// Example 1:
    /// Input: nums = [1,-1,1], limit = 3, goal = -4
    /// Output: 2
    /// Explanation: You can add -2 and -3, then the sum of the array will 
    /// be 1 - 1 + 1 - 2 - 3 = -4.
    ///
    /// Example 2:
    /// Input: nums = [1,-10,9,1], limit = 100, goal = 0
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= limit <= 10^6
    /// 3. -limit <= nums[i] <= limit
    /// 4. -10^9 <= goal <= 10^9
    /// </summary>
    int minElements(vector<int>& nums, int limit, int goal);

    /// <summary>
    /// Leet code 1798. Maximum Number of Consecutive Values You Can Make
    /// 
    /// Medium
    /// 
    /// You are given an integer array coins of length n which represents the
    /// n coins that you own. The value of the ith coin is coins[i]. You can 
    /// make some value x if you can choose some of your n coins such that 
    /// their values sum up to x.
    ///
    /// Return the maximum number of consecutive integer values that you can 
    /// make with your coins starting from and including 0.
    ///
    /// Note that you may have multiple coins of the same value.
    /// 
    /// Example 1:
    /// Input: coins = [1,3]
    /// Output: 2
    /// Explanation: You can make the following values:
    /// - 0: take []
    /// - 1: take [1]
    /// You can make 2 consecutive integer values starting from 0.
    ///
    /// Example 2:
    /// Input: coins = [1,1,1,4]
    /// Output: 8
    /// Explanation: You can make the following values:
    /// - 0: take []
    /// - 1: take [1]
    /// - 2: take [1,1]
    /// - 3: take [1,1,1]
    /// - 4: take [4]
    /// - 5: take [4,1]
    /// - 6: take [4,1,1]
    /// - 7: take [4,1,1,1]
    /// You can make 8 consecutive integer values starting from 0.
    ///
    /// Example 3:
    /// Input: nums = [1,4,10,3,1]
    /// Output: 20
    /// 
    /// Constraints:
    /// 1. coins.length == n
    /// 2. 1 <= n <= 4 * 10^4
    /// 3. 1 <= coins[i] <= 4 * 10^4
    /// </summary>
    int getMaximumConsecutive(vector<int>& coins);

    /// <summary>
    /// Leet code 1808. Maximize Number of Nice Divisors 
    /// 
    /// Hard
    /// 
    /// You are given a positive integer primeFactors. You are asked to 
    /// construct a positive integer n that satisfies the following 
    /// conditions:
    ///
    /// The number of prime factors of n (not necessarily distinct) is at 
    /// most primeFactors.
    /// The number of nice divisors of n is maximized. Note that a divisor 
    /// of n is nice if it is divisible by every prime factor of n. For 
    /// example, if n = 12, then its prime factors are [2,2,3], then 6 and 12 
    /// are nice divisors, while 3 and 4 are not.
    /// Return the number of nice divisors of n. Since that number can be too 
    /// large, return it modulo 10^9 + 7.
    /// 
    /// Note that a prime number is a natural number greater than 1 that is 
    /// not a product of two smaller natural numbers. The prime factors of a 
    /// number n is a list of prime numbers such that their product equals n.
    ///
    /// Example 1:
    /// Input: primeFactors = 5
    /// Output: 6
    /// Explanation: 200 is a valid value of n.
    /// It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: 
    /// [10,20,40,50,100,200].
    /// There is not other value of n that has at most 5 prime factors and more 
    /// nice divisors.
    ///
    /// Example 2:
    /// Input: primeFactors = 8
    /// Output: 18
    /// 
    /// Constraints:
    /// 1. 1 <= primeFactors <= 10^9
    /// </summary>
    int maxNiceDivisors(int primeFactors);

    /// <summary>
    /// Leet code 1812. Determine Color of a Chessboard Square 
    /// 
    /// Easy
    /// 
    /// You are given coordinates, a string that represents the coordinates 
    /// of a square of the chessboard. Below is a chessboard for your 
    /// reference.
    /// 
    /// Return true if the square is white, and false if the square is black.
    ///
    /// The coordinate will always represent a valid chessboard square. The 
    /// coordinate will always have the letter first, and the number second.
    /// 
    /// Example 1:
    /// Input: coordinates = "a1"
    /// Output: false
    /// Explanation: From the chessboard above, the square with coordinates 
    /// "a1" is black, so return false.
    ///
    /// Example 2:
    /// Input: coordinates = "h3"
    /// Output: true
    /// Explanation: From the chessboard above, the square with coordinates 
    /// "h3" is white, so return true.
    ///
    /// Example 3:
    /// Input: coordinates = "c7"
    /// Output: false
    /// 
    /// Constraints:
    /// 1. coordinates.length == 2
    /// 2. 'a' <= coordinates[0] <= 'h'
    /// 3. '1' <= coordinates[1] <= '8'
    /// </summary>
    bool squareIsWhite(string coordinates);

    /// <summary>
    /// Leet code 1819. Number of Different Subsequences GCDs
    /// 
    /// Hard
    /// 
    /// You are given an array nums that consists of positive integers.
    ///
    /// The GCD of a sequence of numbers is defined as the greatest integer 
    /// that divides all the numbers in the sequence evenly.
    ///
    /// For example, the GCD of the sequence [4,6,16] is 2.
    /// A subsequence of an array is a sequence that can be formed by removing 
    /// some elements (possibly none) of the array.
    ///
    /// For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
    /// Return the number of different GCDs among all non-empty subsequences 
    /// of nums.
    /// 
    /// Example 1:
    /// Input: nums = [6,10,3]
    /// Output: 5
    /// Explanation: The figure shows all the non-empty subsequences and their 
    /// GCDs.
    /// The different GCDs are 6, 10, 3, 2, and 1. 
    ///
    /// Example 2:
    /// Input: nums = [5,15,40,5,6]
    /// Output: 7
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 2 * 10^5
    /// </summary>
    int countDifferentSubsequenceGCDs(vector<int>& nums);

    /// <summary>
    /// Leet code 1828. Queries on Number of Points Inside a Circle
    /// 
    /// Medium
    /// 
    /// You are given an array points where points[i] = [xi, yi] is the 
    /// coordinates of the ith point on a 2D plane. Multiple points can 
    /// have the same coordinates.
    ///
    /// You are also given an array queries where queries[j] = [xj, yj, rj] 
    /// describes a circle centered at (xj, yj) with a radius of rj.
    ///
    /// For each query queries[j], compute the number of points inside the 
    /// jth circle. Points on the border of the circle are considered inside.
    ///
    /// Return an array answer, where answer[j] is the answer to the jth query.
    ///
    /// Example 1:
    /// Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = 
    /// [[2,3,1],[4,3,1],[1,1,2]]
    /// Output: [3,2,2]
    /// Explanation: The points and circles are shown above.
    /// queries[0] is the green circle, queries[1] is the red circle, and 
    /// queries[2] is the blue circle.
    ///
    /// Example 2:
    /// Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = 
    /// [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
    /// Output: [2,3,2,4]
    /// Explanation: The points and circles are shown above.
    /// queries[0] is green, queries[1] is red, queries[2] is blue, and 
    /// queries[3] is purple.
    /// 
    /// Constraints:
    /// 1. 1 <= points.length <= 500
    /// 2. points[i].length == 2
    /// 3. 0 <= x​​​​​​i, y​​​​​​i <= 500
    /// 4. 1 <= queries.length <= 500
    /// 5. queries[j].length == 3
    /// 6. 0 <= xj, yj <= 500
    /// 7. 1 <= rj <= 500
    /// 8. All coordinates are integers.
    /// </summary>
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries);
    
    /// <summary>
    /// Leet code 1830. Minimum Number of Operations to Make String Sorted
    /// </summary>
    int modPow(long long x, long long y, long long m);
    
    /// <summary>
    /// Leet code 1830. Minimum Number of Operations to Make String Sorted
    /// 
    /// Hard
    /// 
    /// You are given a string s (0-indexed). You are asked to perform the 
    /// following operation on s until you get a sorted string:
    /// 
    /// Find the largest index i such that 1 <= i < s.length and 
    /// s[i] < s[i - 1].
    /// Find the largest index j such that i <= j < s.length and 
    /// s[k] < s[i - 1] for all the possible values of k in the range 
    /// [i, j] inclusive.
    /// Swap the two characters at indices i - 1 and j.
    /// Reverse the suffix starting at index i.
    /// Return the number of operations needed to make the string sorted. 
    /// Since the answer can be too large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: s = "cba"
    /// Output: 5
    /// Explanation: The simulation goes as follows:
    /// Operation 1: i=2, j=2. Swap s[1] and s[2] to get s="cab", then reverse 
    /// the suffix starting at 2. Now, s="cab".
    /// Operation 2: i=1, j=2. Swap s[0] and s[2] to get s="bac", then reverse 
    /// the suffix starting at 1. Now, s="bca".
    /// Operation 3: i=2, j=2. Swap s[1] and s[2] to get s="bac", then reverse 
    /// the suffix starting at 2. Now, s="bac".
    /// Operation 4: i=1, j=1. Swap s[0] and s[1] to get s="abc", then reverse 
    /// the suffix starting at 1. Now, s="acb".
    /// Operation 5: i=2, j=2. Swap s[1] and s[2] to get s="abc", then reverse 
    /// the suffix starting at 2. Now, s="abc".
    ///
    /// Example 2:
    /// Input: s = "aabaa"
    /// Output: 2
    /// Explanation: The simulation goes as follows:
    /// Operation 1: i=3, j=4. Swap s[2] and s[4] to get s="aaaab", then reverse 
    /// the substring starting at 3. Now, s="aaaba".
    /// Operation 2: i=4, j=4. Swap s[3] and s[4] to get s="aaaab", then reverse 
    /// the substring starting at 4. Now, s="aaaab".
    ///
    /// Example 3:
    /// Input: s = "cdbea"
    /// Output: 63
    ///
    /// Example 4:
    /// Input: s = "leetcodeleetcodeleetcode"
    /// Output: 982157772
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 3000
    /// 2. s consists only of lowercase English letters.
    /// </summary>
    int makeStringSorted(string s);

    /// <summary>
    /// Leet code 1837. Sum of Digits in Base K
    /// 
    /// Easy
    /// 
    /// Given an integer n (in base 10) and a base k, return the sum of the 
    /// digits of n after converting n from base 10 to base k.
    ///
    /// After converting, each digit should be interpreted as a base 10 
    /// number, and the sum should be returned in base 10.
    ///
    /// Example 1:
    /// Input: n = 34, k = 6
    /// Output: 9
    /// Explanation: 34 (base 10) expressed in base 6 is 54. 5 + 4 = 9.
    ///
    /// Example 2:
    /// Input: n = 10, k = 10
    /// Output: 1
    /// Explanation: n is already in base 10. 1 + 0 = 1.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// 2. 2 <= k <= 10
    /// </summary>
    int sumBase(int n, int k);

    /// <summary>
    /// Leet code 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number
    /// 
    /// Medium
    /// 
    /// You are given a string num, representing a large integer, and an 
    /// integer k.
    ///
    /// We call some integer wonderful if it is a permutation of the digits 
    /// in num and is greater in value than num. There can be many wonderful 
    /// integers. However, we only care about the smallest-valued ones.
    ///
    /// For example, when num = "5489355142":
    /// The 1st smallest wonderful integer is "5489355214".
    /// The 2nd smallest wonderful integer is "5489355241".
    /// The 3rd smallest wonderful integer is "5489355412".
    /// The 4th smallest wonderful integer is "5489355421".
    /// Return the minimum number of adjacent digit swaps that needs to be 
    /// applied to num to reach the kth smallest wonderful integer.
    ///
    /// The tests are generated in such a way that kth smallest wonderful 
    /// integer exists.
    /// 
    /// Example 1:
    /// Input: num = "5489355142", k = 4
    /// Output: 2
    /// Explanation: The 4th smallest wonderful number is "5489355421". To 
    /// get this number:
    /// - Swap index 7 with index 8: "5489355142" -> "5489355412"
    /// - Swap index 8 with index 9: "5489355412" -> "5489355421"
    ///
    /// Example 2:
    /// Input: num = "11112", k = 4
    /// Output: 4
    /// Explanation: The 4th smallest wonderful number is "21111". To get 
    /// this number:
    /// - Swap index 3 with index 4: "11112" -> "11121"
    /// - Swap index 2 with index 3: "11121" -> "11211"
    /// - Swap index 1 with index 2: "11211" -> "12111"
    /// - Swap index 0 with index 1: "12111" -> "21111"
    ///
    /// Example 3:
    /// Input: num = "00123", k = 1
    /// Output: 1
    /// Explanation: The 1st smallest wonderful number is "00132". To get 
    /// this number:
    /// - Swap index 3 with index 4: "00123" -> "00132"
    ///
    /// Constraints:
    /// 1. 2 <= num.length <= 1000
    /// 2. 1 <= k <= 1000
    /// 3. num only consists of digits.
    /// </summary>
    int getMinSwaps(string num, int k);


    /// <summary>
    /// Leet code 1862. Sum of Floored Pairs
    /// 
    /// Hard
    /// 
    /// Given an integer array nums, return the sum of floor(nums[i] / nums[j])
    /// for all pairs of indices 0 <= i, j < nums.length in the array. Since 
    /// the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// The floor() function returns the integer part of the division.
    /// 
    /// Example 1:
    /// Input: nums = [2,5,9]
    /// Output: 10
    /// Explanation:
    /// floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
    /// floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
    /// floor(5 / 2) = 2
    /// floor(9 / 2) = 4
    /// floor(9 / 5) = 1
    /// We calculate the floor of the division for every pair of indices in the array then sum them up.
    ///
    /// Example 2:
    /// Input: nums = [7,7,7,7,7,7,7]
    /// Output: 49
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int sumOfFlooredPairs(vector<int>& nums);

    /// <summary>
    /// Leet code 1860. Incremental Memory Leak
    /// 
    /// Medium
    /// 
    /// You are given two integers memory1 and memory2 representing the 
    /// available memory in bits on two memory sticks. There is currently 
    /// a faulty program running that consumes an increasing amount of memory 
    /// every second.
    ///
    /// At the ith second (starting from 1), i bits of memory are allocated 
    /// to the stick with more available memory (or from the first memory 
    /// stick if both have the same available memory). If neither stick has 
    /// at least i bits of available memory, the program crashes.
    ///
    /// Return an array containing [crashTime, memory1crash, memory2crash], 
    /// where crashTime is the time (in seconds) when the program crashed and 
    /// memory1crash and memory2crash are the available bits of memory in the 
    /// first and second sticks respectively.
    /// 
    /// Example 1:
    /// Input: memory1 = 2, memory2 = 2
    /// Output: [3,1,0]
    /// Explanation: The memory is allocated as follows:
    /// - At the 1st second, 1 bit of memory is allocated to stick 1. The 
    ///   first stick now has 1 bit of available memory.
    /// - At the 2nd second, 2 bits of memory are allocated to stick 2. 
    ///   The second stick now has 0 bits of available memory.
    /// - At the 3rd second, the program crashes. The sticks have 1 and 0 
    ///   bits available respectively.
    ///
    /// Example 2:
    /// Input: memory1 = 8, memory2 = 11
    /// Output: [6,0,4]
    /// Explanation: The memory is allocated as follows:
    /// - At the 1st second, 1 bit of memory is allocated to stick 2. The 
    ///   second stick now has 10 bit of available memory.
    /// - At the 2nd second, 2 bits of memory are allocated to stick 2. The 
    ///   second stick now has 8 bits of available memory.
    /// - At the 3rd second, 3 bits of memory are allocated to stick 1. The 
    ///   first stick now has 5 bits of available memory.
    /// - At the 4th second, 4 bits of memory are allocated to stick 2. The 
    ///   second stick now has 4 bits of available memory.
    /// - At the 5th second, 5 bits of memory are allocated to stick 1. The 
    ///   first stick now has 0 bits of available memory.
    /// - At the 6th second, the program crashes. The sticks have 0 and 4 bits 
    ///   available respectively.
    /// 
    /// Constraints:
    /// 1. 0 <= memory1, memory2 <= 2^31 - 1
    /// 2. You are given an array of strings words (0-indexed).
    /// </summary>
    vector<int> memLeak(int memory1, int memory2);

    /// <summary>
    /// Leet code 1916. Count Ways to Build Rooms in an Ant Colony
    /// </summary>
    int waysToBuildRooms(vector<vector<int>>& tree, int root, long long& product);

    /// <summary>
    /// Leet code 1916. Count Ways to Build Rooms in an Ant Colony
    /// 
    /// Hard
    /// 
    /// You are an ant tasked with adding n new rooms numbered 0 to n-1 to 
    /// your colony. You are given the expansion plan as a 0-indexed integer 
    /// array of length n, prevRoom, where prevRoom[i] indicates that you 
    /// must build room prevRoom[i] before building room i, and these two 
    /// rooms must be connected directly. Room 0 is already built, so 
    /// prevRoom[0] = -1. The expansion plan is given such that once all 
    /// the rooms are built, every room will be reachable from room 0.
    ///
    /// You can only build one room at a time, and you can travel freely 
    /// between rooms you have already built only if they are connected. 
    /// You can choose to build any room as long as its previous room is 
    /// already built.
    ///
    /// Return the number of different orders you can build all the rooms in. 
    /// Since the answer may be large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: prevRoom = [-1,0,1]
    /// Output: 1
    /// Explanation: There is only one way to build the additional 
    /// rooms: 0 -> 1 -> 2
    ///
    /// Example 2:
    ///Input: prevRoom = [-1,0,0,1,2]
    /// Output: 6
    /// Explanation:
    /// The 6 ways are:
    /// 0 -> 1 -> 3 -> 2 -> 4
    /// 0 -> 2 -> 4 -> 1 -> 3
    /// 0 -> 1 -> 2 -> 3 -> 4
    /// 0 -> 1 -> 2 -> 4 -> 3
    /// 0 -> 2 -> 1 -> 3 -> 4
    /// 0 -> 2 -> 1 -> 4 -> 3
    ///
    /// Constraints:
    /// 1. n == prevRoom.length
    /// 2. 2 <= n <= 10^5
    /// 3. prevRoom[0] == -1
    /// 3. 0 <= prevRoom[i] < n for all 1 <= i < n
    /// 4. Every room is reachable from room 0 once all the rooms are built.
    /// </summary>
    int waysToBuildRooms(vector<int>& prevRoom);

    /// <summary>
    /// Leet code 1906. Minimum Absolute Difference Queries
    /// 
    /// Hard
    /// 
    /// The minimum absolute difference of an array a is defined as the 
    /// minimum value of |a[i] - a[j]|, where 0 <= i < j < a.length and 
    /// a[i] != a[j]. If all elements of a are the same, the minimum 
    /// absolute difference is -1.
    ///
    /// For example, the minimum absolute difference of the array 
    /// [5,2,3,7,2] is |2 - 3| = 1. Note that it is not 0 because 
    /// a[i] and a[j] must be different.
    /// You are given an integer array nums and the array queries where 
    /// queries[i] = [li, ri]. For each query i, compute the minimum 
    /// absolute difference of the subarray nums[li...ri] containing the 
    /// elements of nums between the 0-based indices li and ri (inclusive).
    ///
    /// Return an array ans where ans[i] is the answer to the ith query.
    /// 
    /// A subarray is a contiguous sequence of elements in an array.
    ///
    /// The value of |x| is defined as:
    /// 1. x if x >= 0.
    /// 2. -x if x < 0.
    ///
    /// Example 1:
    /// Input: nums = [1,3,4,8], queries = [[0,1],[1,2],[2,3],[0,3]]
    /// Output: [2,1,4,1]
    /// Explanation: The queries are processed as follows:
    /// - queries[0] = [0,1]: The subarray is [1,3] and the minimum absolute 
    ///   difference is |1-3| = 2.
    /// - queries[1] = [1,2]: The subarray is [3,4] and the minimum absolute 
    ///   difference is |3-4| = 1.
    /// - queries[2] = [2,3]: The subarray is [4,8] and the minimum absolute 
    ///   difference is |4-8| = 4.
    /// - queries[3] = [0,3]: The subarray is [1,3,4,8] and the minimum 
    ///   absolute difference is |3-4| = 1.
    ///
    /// Example 2:
    /// Input: nums = [4,5,2,2,7,10], queries = [[2,3],[0,2],[0,5],[3,5]]
    /// Output: [-1,1,1,3]
    /// Explanation: The queries are processed as follows:
    /// - queries[0] = [2,3]: The subarray is [2,2] and the minimum absolute 
    ///   difference is -1 because all the elements are the same.
    /// - queries[1] = [0,2]: The subarray is [4,5,2] and the minimum absolute 
    ///   difference is |4-5| = 1.
    /// - queries[2] = [0,5]: The subarray is [4,5,2,2,7,10] and the minimum 
    ///   absolute difference is |4-5| = 1.
    /// - queries[3] = [3,5]: The subarray is [2,7,10] and the minimum absolute
    ///    difference is |7-10| = 3.
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 100
    /// 3. 1 <= queries.length <= 2 * 10^4
    /// 4. 0 <= li < ri < nums.length
    /// </summary>
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code 1884. Egg Drop With 2 Eggs and N Floors
    ///                  
    /// Medium
    /// 
    /// You are given two identical eggs and you have access to a building 
    /// with n floors labeled from 1 to n.
    ///
    /// You know that there exists a floor f where 0 <= f <= n such that any 
    /// egg dropped at a floor higher than f will break, and any egg dropped 
    /// at or below floor f will not break.
    ///
    /// In each move, you may take an unbroken egg and drop it from any 
    /// floor x (where 1 <= x <= n). If the egg breaks, you can no longer use 
    /// it. However, if the egg does not break, you may reuse it in future 
    /// moves.
    ///
    /// Return the minimum number of moves that you need to determine with 
    /// certainty what the value of f is.
    /// 
    /// Example 1:
    /// Input: n = 2
    /// Output: 2
    /// Explanation: We can drop the first egg from floor 1 and the second 
    /// egg from floor 2.
    /// If the first egg breaks, we know that f = 0.
    /// If the second egg breaks but the first egg didn't, we know that f = 1.
    /// Otherwise, if both eggs survive, we know that f = 2.
    ///
    /// Example 2:
    /// Input: n = 100
    /// Output: 14
    /// Explanation: One optimal strategy is:
    /// - Drop the 1st egg at floor 9. If it breaks, we know f is between 0 
    /// and 8. Drop the 2nd egg starting from floor 1 and going up one at a 
    /// time to find f within 7 more drops. Total drops is 1 + 7 = 8.
    /// - If the 1st egg does not break, drop the 1st egg again at floor 22. 
    /// If it breaks, we know f is between 9 and 21. Drop the 2nd egg starting 
    /// from floor 10 and going up one at a time to find f within 12 more
    /// drops. Total drops is 2 + 12 = 14.
    /// - If the 1st egg does not break again, follow a similar process 
    /// dropping the 1st egg from floors 34, 45,
    /// 55, 64, 72, 79, 85, 90, 94, 97, 99, and 100.
    /// Regardless of the outcome, it takes at most 14 drops to determine f.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    int twoEggDrop(int n);

    /// <summary>
    /// Leet code 1899. Merge Triplets to Form Target Triplet
    ///                                  
    /// Medium
    /// 
    /// 
    /// A triplet is an array of three integers. You are given a 2D integer 
    /// array triplets, where triplets[i] = [ai, bi, ci] describes the ith 
    /// triplet. You are also given an integer array target = [x, y, z] that 
    /// describes the triplet you want to obtain.
    ///
    /// To obtain target, you may apply the following operation on triplets 
    /// any number of times (possibly zero):
    ///
    /// Choose two indices (0-indexed) i and j (i != j) and update triplets[j] 
    /// to become [max(ai, aj), max(bi, bj), max(ci, cj)].
    /// For example, if triplets[i] = [2, 5, 3] and triplets[j] = [1, 7, 5], 
    /// triplets[j] will be updated to [max(2, 1), max(5, 7), 
    /// max(3, 5)] = [2, 7, 5].
    /// Return true if it is possible to obtain the target triplet [x, y, z] 
    /// as an element of triplets, or false otherwise.
    /// 
    /// Example 1:
    /// Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
    /// Output: true
    /// Explanation: Perform the following operations:
    /// - Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update 
    ///  the last triplet to be [max(2,1), max(5,7), max(3,5)] = [2,7,5]. 
    ///  triplets = [[2,5,3],[1,8,4],[2,7,5]]
    /// The target triplet [2,7,5] is now an element of triplets.
    ///
    /// Example 2:
    /// Input: triplets = [[1,3,4],[2,5,8]], target = [2,5,8]
    /// Output: true
    /// Explanation: The target triplet [2,5,8] is already an element of 
    /// triplets.
    ///
    /// Example 3:
    /// Input: triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
    /// Output: true
    /// Explanation: Perform the following operations:
    /// - Choose the first and third triplets [[2,5,3],[2,3,4],[1,2,5],
    /// [5,2,3]]. Update the third triplet to be [max(2,1), max(5,2), max(3,5)]
    /// = [2,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,2,3]].
    /// - Choose the third and fourth triplets [[2,5,3],[2,3,4],[2,5,5],
    /// [5,2,3]]. Update the fourth triplet to be [max(2,5), max(5,2), 
    ///  max(5,3)] = [5,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,5,5]].
    /// The target triplet [5,5,5] is now an element of triplets.
    ///
    /// Example 4:
    /// Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
    /// Output: false
    /// Explanation: It is impossible to have [3,2,5] as an element because 
    /// there is no 2 in any of the triplets.
    /// 
    /// Constraints:
    /// 1. 1 <= triplets.length <= 10^5
    /// 2. triplets[i].length == target.length == 3
    /// 3. 1 <= ai, bi, ci, x, y, z <= 1000
    /// </summary>
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target);
};
#endif
