#pragma once
#ifndef LeetCodeUnionFind_H
#define LeetCodeUnionFind_H
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
/// The class is to implement union find algorithm  
/// </summary>
class LeetCodeUnionFind
{
public:
#pragma region UnionFind
    /// <summary>
    /// Leet code #305. Number of Islands II  
    /// </summary>
    int checkIslands(int island_id, int row, int col, vector<vector<int>>& grid_map, vector<int>& island_map);

    /// <summary>
    /// Leet code #305. Number of Islands II  
    /// </summary>
    int mergeIslands(int island1, int island2, vector<vector<int>>& grid_map, vector<int>& island_map);

    /// <summary>
    /// Leet code #305. Number of Islands II  
    /// 
    /// A 2d grid map of m rows and n columns is initially filled with water. We may perform 
    /// an addLand operation which turns the water at position (row, col) into a land. Given 
    /// a list of positions to operate, count the number of islands after each addLand operation. 
    /// An island is surrounded by water and is formed by connecting adjacent lands horizontally 
    /// or vertically. You may assume all four edges of the grid are all surrounded by water.
    ///
    /// Example:
    ///
    /// Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
    /// Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
    /// 0 0 0
    /// 0 0 0
    /// 0 0 0
    /// Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
    /// 1 0 0
    /// 0 0 0   Number of islands = 1
    /// 0 0 0
    /// 
    /// Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
    /// 1 1 0
    /// 0 0 0   Number of islands = 1
    /// 0 0 0
    ///
    /// Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
    /// 1 1 0
    /// 0 0 1   Number of islands = 2
    /// 0 0 0
    ///
    /// 
    /// Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
    /// 1 1 0
    /// 0 0 1   Number of islands = 3
    /// 0 1 0
    ///
    /// We return the result as an array: [1, 1, 2, 3]
    ///
    /// Challenge:
    /// Can you do it in time complexity O(k log mn), where k is the length of the positions?
    /// </summary>
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions);

    /// <summary>
    /// Leet code #547. Friend Circles  
    /// 
    /// There are N students in a class. Some of them are friends, while some 
    /// are not. Their friendship is transitive in nature. For example, if A 
    /// is a direct friend of B, and B is a direct friend of C, then A is an 
    /// indirect friend of C. And we defined a friend circle is a group of 
    /// students who are direct or indirect friends. 
    /// Given a N*N matrix M representing the friend relationship between 
    /// students in the class. If M[i][j] = 1, then the ith and jth students 
    /// are direct friends with each other, otherwise not. And you have to 
    /// output the total number of friend circles among all the students. 
    /// Example 1:
    /// Input: 
    /// [[1,1,0],
    /// [1,1,0],
    /// [0,0,1]]
    /// Output: 2
    /// Explanation:The 0th and 1st students are direct friends, so they are 
    /// in a friend circle. 
    /// The 2nd student himself is in a friend circle. So return 2.
    /// Example 2:
    /// Input: 
    /// [[1,1,0],
    /// [1,1,1],
    /// [0,1,1]]
    /// Output: 1
    /// Explanation:The 0th and 1st students are direct friends, the 1st and 
    /// 2nd students are direct friends, 
    /// so the 0th and 2nd students are indirect friends. All of them are in 
    /// the same friend circle, so return 1.
    ///
    /// Note:
    /// N is in range [1,200].
    /// M[i][i] = 1 for all students.
    /// If M[i][j] = 1, then M[j][i] = 1.
    /// </summary>
    int findCircleNum(vector<vector<int>>& M);

    /// <summary>
    /// Leet code #695. Max Area of Island
    /// </summary>
    int mergeIsland(vector<vector<pair<int, int>>>& grid_map, vector<vector<int>>& grid_count,
        pair<int, int>& source, pair<int, int>& target);

    /// <summary>
    /// Leet code #695. Max Area of Island
    /// 
    /// Given a non-empty 2D array grid of 0's and 1's, an island is a group 
    /// of 1's (representing land) connected 4-directionally (horizontal or 
    /// vertical.) You may assume all four edges of the grid are surrounded 
    /// by water.
    /// 
    /// Find the maximum area of an island in the given 2D array. (If there 
    /// is no island, the maximum area is 0.)
    ///
    /// Example 1:
    /// [
    ///  [0,0,1,0,0,0,0,1,0,0,0,0,0],
    ///  [0,0,0,0,0,0,0,1,1,1,0,0,0],
    ///  [0,1,1,0,1,0,0,0,0,0,0,0,0],
    ///  [0,1,0,0,1,1,0,0,1,0,1,0,0],
    ///  [0,1,0,0,1,1,0,0,1,1,1,0,0],
    ///  [0,0,0,0,0,0,0,0,0,0,1,0,0],
    ///  [0,0,0,0,0,0,0,1,1,1,0,0,0],
    ///  [0,0,0,0,0,0,0,1,1,0,0,0,0]
    /// ]
    /// Given the above grid, return 6. Note the answer is not 11, because the 
    /// island must be connected 4-directionally.
    ///
    /// Example 2:
    /// [
    ///   [0,0,0,0,0,0,0,0]
    /// ]
    /// Given the above grid, return 0.
    /// Note: The length of each dimension in the given grid does not exceed 50.
    /// </summary>
    int maxAreaOfIsland(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #803. Bricks Falling When Hit
    /// </summary>
    int unionBricks(int source, int target, int size, unordered_map<int, pair<int, int>>& union_map);

    /// <summary>
    /// Leet code #803. Bricks Falling When Hit
    /// </summary>
    int unionNeighbors(int row, int col, vector<vector<int>>& grid, unordered_map<int, pair<int, int>>& union_map);

    /// <summary>
    /// Leet code #803. Bricks Falling When Hit
    /// 
    /// We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A 
    /// brick will not drop if and only if it is directly connected to the 
    /// top of the grid, or at least one of its (4-way) adjacent bricks will 
    /// not drop.
    ///
    /// We will do some erasures sequentially. Each time we want to do the 
    /// erasure at the location (i, j), the brick (if it exists) on that 
    /// location will disappear, and then some other bricks may drop because 
    /// of that erasure.
    ///
    /// Return an array representing the number of bricks that will drop after 
    /// each erasure in sequence.
    ///
    /// Example 1:
    /// Input: 
    /// grid = [[1,0,0,0],[1,1,1,0]]
    /// hits = [[1,0]]
    /// Output: [2]
    /// Explanation: 
    /// If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will 
    /// drop. So we should return 2.
    /// Example 2:
    /// Input: 
    /// grid = [[1,0,0,0],[1,1,0,0]]
    /// hits = [[1,1],[1,0]]
    /// Output: [0,0]
    /// Explanation: 
    /// When we erase the brick at (1, 0), the brick at (1, 1) has already 
    /// disappeared due to the last move. So each erasure will cause no bricks 
    /// dropping.  Note that the erased brick (1, 0) will not be counted as a 
    /// dropped brick.
    /// 
    ///
    /// Note:
    ///
    /// 1. The number of rows and columns in the grid will be in the range 
    ///    [1, 200].
    /// 2. The number of erasures will not exceed the area of the grid.
    /// 3. It is guaranteed that each erasure will be different from any other 
    ///    erasure, and located inside the grid.
    /// 4. An erasure may refer to a location with no brick - if it does, 
    ///    no bricks drop.
    /// </summary>
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits);

    /// <summary>
    /// Leet code #827. Making A Large Island
    /// </summary>
    int mergeIsland(int source, int target, unordered_map<int, pair<int, int>>& union_map);

    /// <summary>
    /// Leet code #827. Making A Large Island
    /// 
    /// In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
    ///
    /// After, what is the size of the largest island? (An island is a 
    /// 4-directionally connected group of 1s).
    ///
    /// Example 1:
    ///
    /// Input: [[1, 0], [0, 1]]
    /// Output: 3
    /// Explanation: Change one 0 to 1 and connect two 1s, then we get an 
    /// island with area = 3.
    /// Example 2:
    ///
    /// Input: [[1, 1], [1, 0]]
    /// Output: 4
    /// Explanation: Change the 0 to 1 and make the island bigger, only one 
    /// island with area = 1.
    /// Example 3:
    ///
    /// Input: [[1, 1], [1, 1]]
    /// Output: 4
    /// Explanation: Can't change any 0 to 1, only one island with area = 1.
    /// 
    ///
    /// Notes:
    ///
    /// 1. 1 <= grid.length = grid[0].length <= 50.
    /// 2. 0 <= grid[i][j] <= 1.
    /// </summary>
    int largestIsland(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #9903. Check Radar 
    /// </summary>
    bool checkOverlap(vector<double>radar1, vector<double>radar2);

    /// <summary>
    /// Leet code #9903. Check Radar 
    /// </summary>
    bool checkBlock(int width, double y_min, double y_max);

    /// <summary>
    /// Leet code #9903. Check Radar 
    /// 
    /// Give a road, with width in Y axis, and a list of radar, with x, y, and r which indicates  
    /// the position and radius, assume your car move from left (with x = 0) to right (x = INT_MAX)
    /// and your car can move on any curve as you wish, can you avoid any radar in this road?
    /// </summary>
    bool canAvoidRadar(int width, vector<vector<double>>& radars);

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
    vector<vector<string>> accountsMergeII(vector<vector<string>>& accounts);

    /// <summary>
    /// Leet code #737. Sentence Similarity II
    ///
    /// Given two sentences words1, words2 (each represented as an array of 
    /// strings), and a list of similar word pairs pairs, determine if two 
    /// sentences are similar.
    ///
    /// For example, words1 = ["great", "acting", "skills"] and words2 = 
    /// ["fine", "drama", "talent"] are similar, if the similar word pairs 
    /// are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], 
    /// ["skills","talent"]].
    ///
    /// Note that the similarity relation is transitive. For example, if 
    /// "great" and "good" are similar, and "fine" and "good" are similar, 
    /// then "great" and "fine" are similar.
    ///
    /// Similarity is also symmetric. For example, "great" and "fine" being 
    /// similar is the same as "fine" and "great" being similar.
    /// 
    /// Also, a word is always similar with itself. For example, the sentences 
    /// words1 = ["great"], words2 = ["great"], pairs = [] are similar, even 
    /// though there are no specified similar word pairs.
    ///
    /// Finally, sentences can only be similar if they have the same number of 
    /// words. So a sentence like words1 = ["great"] can never be similar to 
    /// words2 = ["doubleplus","good"].
    ///
    /// Note:
    ///
    /// The length of words1 and words2 will not exceed 1000.
    /// The length of pairs will not exceed 2000.
    /// The length of each pairs[i] will be 2.
    /// The length of each words[i] and pairs[i][j] will be in the range [1, 20].
    /// </summary>
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
        vector<pair<string, string>> pairs);

    /// <summary>
    /// Leet code #947. Most Stones Removed with Same Row or Column
    /// 
    /// On a 2D plane, we place stones at some integer coordinate points.  
    /// Each coordinate point may have at most one stone.
    ///
    /// Now, a move consists of removing a stone that shares a column or 
    /// row with another stone on the grid.
    /// What is the largest possible number of moves we can make?
    ///
    ///
    /// Example 1:
    /// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
    /// Output: 5
    ///
    /// Example 2:
    /// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
    /// Output: 3
    ///
    /// Example 3:
    ///
    /// Input: stones = [[0,0]]
    /// Output: 0
    ///
    /// Note:
    /// 1. 1 <= stones.length <= 1000
    /// 2. 0 <= stones[i][j] < 10000
    /// </summary>
    int removeStones(vector<vector<int>>& stones);

    /// <summary>
    /// Leet code #952. Largest Component Size by Common Factor
    /// 
    /// Given a non-empty array of unique positive integers A, consider the 
    /// following graph:
    ///
    /// There are A.length nodes, labelled A[0] to A[A.length - 1];
    /// There is an edge between A[i] and A[j] if and only if A[i] and A[j] 
    /// share a common factor greater than 1.
    /// Return the size of the largest connected component in the graph.
    /// 
    /// Example 1:
    /// Input: [4,6,15,35]
    /// Output: 4
    ///
    /// Example 2:
    /// Input: [20,50,9,63]
    /// Output: 2
    ///
    /// Example 3:
    /// Input: [2,3,6,7,4,12,21,39]
    /// Output: 8
    ///
    /// Note:
    /// 1. 1 <= A.length <= 20000
    /// 2. 1 <= A[i] <= 100000
    /// </summary>
    int largestComponentSize(vector<int>& A);

    /// <summary>
    /// Leet code #990. Satisfiability of Equality Equations
    /// 
    /// Given an array equations of strings that represent relationships 
    /// between variables, each string equations[i] has length 4 and takes 
    /// one of two different forms: "a==b" or "a!=b".  Here, a and b are 
    /// lowercase letters (not necessarily different) that represent 
    /// one-letter variable names.
    ///
    /// Return true if and only if it is possible to assign integers to 
    /// variable names so as to satisfy all the given equations.
    ///
    /// Example 1:
    ///
    /// Input: ["a==b","b!=a"]
    /// Output: false
    /// Explanation: If we assign say, a = 1 and b = 1, then the first 
    /// equation is satisfied, but not the second.  There is no way to 
    /// assign the variables to satisfy both equations.
    ///
    /// Example 2:
    ///
    /// Input: ["b==a","a==b"]
    /// Output: true
    /// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
    ///
    /// Example 3:
    /// 
    /// Input: ["a==b","b==c","a==c"]
    /// Output: true
    ///
    /// Example 4:
    ///
    /// Input: ["a==b","b!=c","c==a"]
    /// Output: false
    ///
    /// Example 5:
    /// 
    /// Input: ["c==c","b==d","x!=z"]
    /// Output: true
    /// 
    /// Note:
    /// 1. 1 <= equations.length <= 500
    /// 2. equations[i].length == 4
    /// 3. equations[i][0] and equations[i][3] are lowercase letters
    /// 4. equations[i][1] is either '=' or '!'
    /// 5. equations[i][2] is '='
    /// </summary>
    bool equationsPossible(vector<string>& equations);

    /// <summary>
    /// Leet code 1061. Lexicographically Smallest Equivalent String
    /// 
    /// Given strings A and B of the same length, we say A[i] and B[i] are 
    /// equivalent characters. For example, if A = "abc" and B = "cde", then 
    /// we have 'a' == 'c', 'b' == 'd', 'c' == 'e'.
    ///
    /// Equivalent characters follow the usual rules of any equivalence relation:
    ///
    /// Reflexivity: 'a' == 'a'
    /// Symmetry: 'a' == 'b' implies 'b' == 'a'
    /// Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'
    /// For example, given the equivalency information from A and B above, 
    /// S = "eed", "acd", and "aab" are equivalent strings, and "aab" is the 
    /// lexicographically smallest equivalent string of S.
    /// 
    /// Return the lexicographically smallest equivalent string of S by using 
    /// the equivalency information from A and B.
    ///
    ///  
    /// Example 1:
    ///
    /// Input: A = "parker", B = "morris", S = "parser"
    /// Output: "makkek"
    /// Explanation: Based on the equivalency information in A and B, we can 
    /// group their characters as [m,p], [a,o], [k,r,s], [e,i]. The characters 
    /// in each group are equivalent and sorted in lexicographical order. So the 
    /// answer is "makkek".
    /// 
    /// Example 2:
    ///
    /// Input: A = "hello", B = "world", S = "hold"
    /// Output: "hdld"
    /// Explanation:  Based on the equivalency information in A and B, we can 
    /// group their characters as [h,w], [d,e,o], [l,r]. So only the second 
    /// letter 'o' in S is changed to 'd', the answer is "hdld".
    ///
    /// Example 3:
    ///
    /// Input: A = "leetcode", B = "programs", S = "sourcecode"
    /// Output: "aauaaaaada"
    /// Explanation:  We group the equivalent characters in A and B as 
    /// [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in S except 'u' 
    /// and 'd' are transformed to 'a', the answer is "aauaaaaada".
    ///
    /// Note:
    ///
    /// 1. String A, B and S consist of only lowercase English letters from 
    ///    'a' - 'z'.
    /// 2. The lengths of string A, B and S are between 1 and 1000.
    /// 3. String A and B are of the same length.
    /// </summary>
    string smallestEquivalentString(string A, string B, string S);

    /// <summary>
    /// Leet code #1101. The Earliest Moment When Everyone Become Friends
    /// 
    /// In a social group, there are N people, with unique integer ids from 0 to 
    /// N-1.
    /// We have a list of logs, where each logs[i] = [timestamp, id_A, id_B] 
    /// contains a non-negative integer timestamp, and the ids of two different 
    /// people.
    /// Each log represents the time in which two different people became friends.
    /// Friendship is symmetric: if A is friends with B, then B is friends with A.
    /// Let's say that person A is acquainted with person B if A is friends with 
    /// B, or A is a friend of someone acquainted with B.
    /// Return the earliest time for which every person became acquainted with 
    /// every other person. Return -1 if there is no such earliest time.
    ///
    /// Example 1:
    /// Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],
    /// [20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], N = 6
    /// Output: 20190301
    /// Explanation: 
    /// The first event occurs at timestamp = 20190101 and after 0 and 1 become 
    /// friends we have the following friendship groups [0,1], [2], [3], [4], [5].
    /// The second event occurs at timestamp = 20190104 and after 3 and 4 become
    /// friends we have the following friendship groups [0,1], [2], [3,4], [5].
    /// The third event occurs at timestamp = 20190107 and after 2 and 3 become
    /// friends we have the following friendship groups [0,1], [2,3,4], [5].
    /// The fourth event occurs at timestamp = 20190211 and after 1 and 5 become
    /// friends we have the following friendship groups [0,1,5], [2,3,4].
    /// The fifth event occurs at timestamp = 20190224 and as 2 and 4 are already 
    /// friend anything happens.
    /// The sixth event occurs at timestamp = 20190301 and after 0 and 3 become 
    /// friends we have that all become friends.
    /// 
    /// Note:
    /// 1. 1 <= N <= 100
    /// 2. 1 <= logs.length <= 10^4
    /// 3. 0 <= logs[i][0] <= 10^9
    /// 4. 0 <= logs[i][1], logs[i][2] <= N - 1
    /// 5. It's guaranteed that all timestamps in logs[i][0] are different.
    /// 6. Logs are not necessarily ordered by some criteria.
    /// 7. logs[i][1] != logs[i][2]
    /// </summary>
    int earliestAcq(vector<vector<int>>& logs, int N);

    /// <summary>
    /// Leet code #839. Similar String Groups
    /// 
    /// Two strings X and Y are similar if we can swap two letters (in 
    /// different positions) of X, so that it equals Y.
    ///
    /// For example, "tars" and "rats" are similar (swapping at positions 
    /// 0 and 2), and "rats" and "arts" are similar, but "star" is not 
    /// similar to "tars", "rats", or "arts".
    ///
    /// Together, these form two connected groups by similarity: {"tars", 
    /// "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are 
    /// in the same group even though they are not similar.  Formally, each 
    /// group is such that a word is in the group if and only if it is similar 
    /// to at least one other word in the group.
    ///
    /// We are given a list A of unique strings.  Every string in A is an 
    /// anagram of every other string in A.  How many groups are there?
    ///
    /// Example 1:
    ///
    /// Input: ["tars","rats","arts","star"]
    /// Output: 2
    /// Note:
    /// 
    /// 1.A.length <= 2000
    /// 2.A[i].length <= 1000
    /// 3.A.length * A[i].length <= 20000
    /// 4.All words in A consist of lowercase letters only.
    /// 5.All words in A have the same length and are anagrams of each other.
    /// 6.The judging time limit has been increased for this question.
    /// </summary>
    int numSimilarGroups(vector<string>& A);

    /// <summary>
    /// Leet code #1202. Smallest String With Swaps
    /// 
    /// You are given a string s, and an array of pairs of indices in the string 
    /// pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
    /// You can swap the characters at any pair of indices in the given pairs any 
    /// number of times.
    /// Return the lexicographically smallest string that s can be changed to 
    /// after using the swaps.
    /// 
    /// Example 1:
    /// Input: s = "dcab", pairs = [[0,3],[1,2]]
    /// Output: "bacd"
    /// Explaination: 
    /// Swap s[0] and s[3], s = "bcad"
    /// Swap s[1] and s[2], s = "bacd"
    ///
    /// Example 2:
    /// Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
    /// Output: "abcd"
    /// Explaination: 
    /// Swap s[0] and s[3], s = "bcad"
    /// Swap s[0] and s[2], s = "acbd"
    /// Swap s[1] and s[2], s = "abcd"
    ///
    /// Example 3:
    /// Input: s = "cba", pairs = [[0,1],[1,2]]
    /// Output: "abc"
    /// Explaination: 
    /// Swap s[0] and s[1], s = "bca"
    /// Swap s[1] and s[2], s = "bac"
    /// Swap s[0] and s[1], s = "abc"
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. 0 <= pairs.length <= 10^5
    /// 3. 0 <= pairs[i][0], pairs[i][1] < s.length
    /// 4. s only contains lower case English letters.
    /// </summary>
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs);

    /// <summary>
    /// Leet code #1319. Number of Operations to Make Network Connected
    ///
    /// Medium
    ///
    /// There are n computers numbered from 0 to n-1 connected by ethernet 
    /// cables connections forming a network where connections[i] = [a, b] 
    /// represents a connection between computers a and b. Any computer can 
    /// reach any other computer directly or indirectly through the network.
    ///
    /// Given an initial computer network connections. You can extract 
    /// certain cables between two directly connected computers, and place 
    /// them between any pair of disconnected computers to make them directly 
    /// connected. Return the minimum number of times you need to do this in 
    /// order to make all the computers connected. If it's not possible, 
    /// return -1. 
    ///
    /// Example 1:
    /// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    /// Output: 1
    /// Explanation: Remove cable between computer 1 and 2 and place between 
    /// computers 1 and 3.
    ///
    /// Example 2:
    /// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
    /// Output: 2
    ///
    /// Example 3:
    /// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
    /// Output: -1
    /// Explanation: There are not enough cables.
    ///
    /// Example 4:
    /// Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
    /// Output: 0
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. 1 <= connections.length <= min(n*(n-1)/2, 10^5)
    /// 3. connections[i].length == 2
    /// 4. 0 <= connections[i][0], connections[i][1] < n
    /// 5. connections[i][0] != connections[i][1]
    /// 6. There are no repeated connections.
    /// 7. No two computers are connected by more than one cable.
    /// </summary>
    int makeConnected(int n, vector<vector<int>>& connections);

#pragma endregion
};
#endif  // LeetCodeUnionFind_H

