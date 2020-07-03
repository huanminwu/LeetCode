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
};
#endif  // LeetCodeHashtable
