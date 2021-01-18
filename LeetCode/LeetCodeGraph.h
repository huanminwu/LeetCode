#pragma once
#ifndef LeetcodeGraph_H
#define LeetCodeGraph_H
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
/// The class is to implement graph based algorithm  
/// </summary>
class LeetCodeGraph
{
public:
#pragma region Graph
    /// <summary>
    /// Helper function which generate an undirected graph node
    /// </summary>
    UndirectedGraphNode* generateGraphNode(vector<pair<int, vector<int>>>& graph_list);

    /// <summary>
    /// Free graph nodes
    /// </summary>
    void freeGraphNodes(UndirectedGraphNode* graph);

    /// <summary>
    /// LeetCode #133. Clone Graph  
    /// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. 
    /// OJ's undirected graph serialization: 
    /// Nodes are labeled uniquely. 
    /// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node. 
    /// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
    /// The graph has a total of three nodes, and therefore contains three parts as separated by #. 
    /// 1.First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    /// 2.Second node is labeled as 1. Connect node 1 to node 2.
    /// 3.Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.	
    /// Visually, the graph looks like the following:
    ///        1
    ///       / \
    ///      /   \
    ///     0 --- 2
    ///          / \
    ///          \_/
    /// </summary>
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node);

    /// <summary>
    /// LeetCode #207. Course Schedule  
    /// There are a total of n courses you have to take, labeled from 0 to 
    /// n - 1. 
    /// Some courses may have prerequisites, for example to take course 0 you 
    /// have to first take course 1, which is expressed as a pair: [0,1] 
    /// Given the total number of courses and a list of prerequisite pairs, 
    /// is it possible for you to finish all courses? 
    /// 
    /// For example: 
    /// 2, [[1,0]]
    /// There are a total of 2 courses to take. To take course 1 you should
    /// have finished course 0. So it is possible.
    ///
    /// 2, [[1,0],[0,1]]
    /// There are a total of 2 courses to take. To take course 1 you should 
    /// have finished course 0, 
    /// and to take course 0 you should also have finished course 1. So it 
    /// is impossible.
    /// Note:
    /// The input prerequisites is a graph represented by a list of edges, 
    /// not adjacency matrices. Read more about how a graph is represented. 
    /// </summary>
    bool canFinishCourse(int numCourses, vector<pair<int, int>>& prerequisites);

    /// <summary>
    /// LeetCode #210. Course Schedule II  
    /// There are a total of n courses you have to take, labeled from 0 to 
    /// n - 1. 
    /// Some courses may have prerequisites, for example to take course 0 you 
    /// have to first take course 1, which is expressed as a pair: [0,1] 
    /// Given the total number of courses and a list of prerequisite pairs, 
    /// return the ordering of courses you should take to finish all courses. 
    /// 
    /// There may be multiple correct orders, you just need to return one of 
    /// them. If it is impossible to finish all courses, return an empty array. 
    /// For example:
    /// 2, [[1,0]]
    ///
    /// There are a total of 2 courses to take. To take course 1 you should 
    /// have finished course 0. So the correct course order is [0,1]
    /// 4, [[1,0],[2,0],[3,1],[3,2]]
    /// There are a total of 4 courses to take. To take course 3 you should 
    /// have finished both courses 1 and 2. 
    /// Both courses 1 and 2 should be taken after you finished course 0. 
    /// So one correct course order is [0,1,2,3]. 
    /// Another correct ordering is[0,2,1,3].
    /// Note:
    /// The input prerequisites is a graph represented by a list of edges, 
    /// not adjacency matrices. Read more about how a graph is represented. 
    /// click to show more hints.
    /// Hints: 
    /// 1.This problem is equivalent to finding the topological order in a 
    ///   directed graph. 
    ///   If a cycle exists, no topological ordering exists and therefore 
    ////  it will be impossible to take all courses.
    /// 2.Topological Sort via DFS - A great video tutorial (21 minutes) on 
    ///   Coursera explaining the basic concepts of Topological Sort.
    /// 3.Topological sort could also be done via BFS.
    /// </summary>
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);

    /// <summary>
    /// Leet code #310. Minimum Height Trees     
    /// 
    /// For a undirected graph with tree characteristics, we can choose any node as the root. 
    /// The result graph is then a rooted tree. Among all possible rooted trees, those with 
    /// minimum height are called minimum height trees (MHTs). 
    /// Given such a graph, write a function to find all the MHTs and return a list of their root labels. 
    ///
    /// Format
    /// The graph contains n nodes which are labeled from 0 to n - 1. You will be given 
    /// the number n and a list of undirected edges (each edge is a pair of labels). 
    ///
    /// You can assume that no duplicate edges will appear in edges. Since all edges are 
    /// undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges. 
    ///
    /// Example 1: 
    /// Given n = 4, edges = [[1, 0], [1, 2], [1, 3]] 
    ///        0
    ///        |
    ///        1
    ///       / \
    ///      2   3
    ///
    /// return  [1] 
    ///
    /// Example 2: 
    /// Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]] 
    ///     0  1  2
    ///      \ | /
    ///        3
    ///        |
    ///        4
    ///        | 
    ///        5
    ///
    /// return  [3, 4] 
    /// Hint:
    /// 1.How many MHTs can a graph have at most?
    /// Note: 
    ///
    /// (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in 
    /// which any two vertices are connected by exactly one path. In other words, any connected 
    /// graph without simple cycles is a tree.” 
    /// (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf. 
    /// </summary>
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges);

    /// <summary>
    /// Leet code #332. Reconstruct Itinerary 
    /// </summary>
    void findItinerary(vector<string>& path, unordered_map<string, map<string, int>>& tickets,
        unordered_map<string, map<string, int>>& visited, int& count);

    /// <summary>
    /// Leet code #332. Reconstruct Itinerary 
    /// 
    /// Given a list of airline tickets represented by pairs of departure and arrival 
    /// airports [from, to], reconstruct the itinerary in order. All of the tickets 
    /// belong to a man who departs from JFK. Thus, the itinerary must begin with JFK. 
    ///
    /// Note:
    /// 1.If there are multiple valid itineraries, you should return the itinerary 
    /// that has the smallest lexical order when read as a single string. For example, 
    /// the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    /// 2.All airports are represented by three capital letters (IATA code).
    /// 3.You may assume all tickets form at least one valid itinerary.
    ///
    /// Example 1:
    /// tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    /// Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
    ///
    /// Example 2:
    /// tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    /// Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
    /// Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. 
    /// But it is larger in lexical order. 
    /// </summary>
    vector<string> findItinerary(vector<pair<string, string>> tickets);

    /// <summary>
    /// Leet code #399. Evaluate Division  
    /// </summary>
    double calcEquation(pair<string, string> equation,
        unordered_map<string, unordered_map<string, double>>& equations_map);

    /// <summary>
    /// Leet code #399. Evaluate Division  
    /// 
    /// Equations are given in the format A / B = k, where A and B are variables 
    /// represented as strings, and k is a real number (floating point number). 
    /// Given some queries, return the answers. If the answer does not exist, return -1.0. 
    ///
    /// Example:
    /// Given  a / b = 2.0, b / c = 3.0. 
    /// queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
    /// return  [6.0, 0.5, -1.0, 1.0, -1.0 ]. 
    ///
    /// The input is:  vector<pair<string, string>> equations, vector<double>& values, 
    /// vector<pair<string, string>> queries , where equations.size() == values.size(), 
    /// and the values are positive. This represents the equations. Return  vector<double>.
    /// According to the example above: 
    /// equations = [ ["a", "b"], ["b", "c"] ],
    /// values = [2.0, 3.0],
    /// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
    /// The input is always valid. You may assume that evaluating the queries 
    /// will result in no division by zero and there is no contradiction. 
    /// </summary>
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values,
        vector<pair<string, string>> queries);

    /// <summary>
    /// Leet code #323. Number of Connected Components in an Undirected Graph
    /// 
    /// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a 
    /// pair of nodes), write a function to find the number of connected components in an undirected graph. 
    /// Example 1:
    ///     0          3
    ///     |          |
    ///     1 --- 2    4
    /// Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2. 
    ///
    /// Example 2:
    ///
    ///     0           4
    ///     |           |
    ///     1 --- 2 --- 3
    /// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1. 
    ///
    /// Note:
    /// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
    /// [0, 1] is the same as [1, 0] and thus will not appear together in edges. 
    /// </summary>
    int countComponents(int n, vector<pair<int, int>>& edges);

    /// <summary>
    /// Leet code #277. Find the Celebrity  
    /// 
    /// Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, 
    /// there may exist one celebrity. The definition of a celebrity is that all the 
    /// other n - 1 people know him/her but he/she does not know any of them. 
    /// Now you want to find out who the celebrity is or verify that there is not one. 
    /// The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" 
    /// to get information of whether A knows B. You need to find out the celebrity 
    /// (or verify there is not one) by asking as few questions as possible (in the asymptotic sense). 
    /// You are given a helper function bool knows(a, b) which tells you whether A knows B. 
    /// Implement a function int findCelebrity(n), your function should minimize the number 
    /// of calls to knows. 
    /// Note: There will be exactly one celebrity if he/she is in the party. 
    /// Return the celebrity's label if there is a celebrity in the party. 
    /// If there is no celebrity, return -1. 
    /// </summary>
    int findCelebrity(int n, vector<vector<bool>>& relation_map);

    /// <summary>
    /// Leet code #286. Walls and Gates 
    /// 
    /// You are given a m x n 2D grid initialized with these three possible values.  
    /// 1.-1 - A wall or an obstacle.
    /// 2.0 - A gate.
    /// 3.INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent 
    ///   INF as you may assume that the distance to a gate is less than 2147483647.
    /// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
    /// For example, given the 2D grid:
    /// INF  -1  0  INF
    /// INF INF INF  -1
    /// INF  -1 INF  -1
    ///  0  -1 INF INF
    /// After running your function, the 2D grid should be:
    ///  3  -1   0   1
    ///  2   2   1  -1
    ///  1  -1   2  -1
    ///  0  -1   3   4
    /// </summary>
    void wallsAndGates(vector<vector<int>>& rooms);

    /// <summary>
    /// Leet code #296. Best Meeting Point 
    /// </summary>
    int minTotalDistance(vector<int>& nums);

    /// <summary>
    /// Leet code #296. Best Meeting Point 
    /// 
    /// A group of two or more people wants to meet and minimize the total travel 
    /// distance. You are given a 2D grid of values 0 or 1, where each 1 marks 
    /// the home of someone in the group. The distance is calculated using 
    /// Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
    /// For example, given three people living at (0,0), (0,4), and (2,2):
    /// 1 - 0 - 0 - 0 - 1
    /// |   |   |   |   |
    /// 0 - 0 - 0 - 0 - 0
    /// |   |   |   |   |
    /// 0 - 0 - 1 - 0 - 0
    /// The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
    ///
    ///        Hint:
    /// 1.Try to solve it in one dimension first. How can this solution apply to the two dimension case?
    /// </summary>
    int minTotalDistance(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #684. Redundant Connection
    /// In this problem, a tree is an undirected graph that is connected and 
    /// has no cycles.
    /// The given input is a graph that started as a tree with N nodes (with 
    /// distinct values 1, 2, ..., N), with one additional edge added. The 
    /// added edge has two different vertices chosen from 1 to N, and was not 
    /// an edge that already existed.
    ///
    /// The resulting graph is given as a 2D-array of edges. Each element of 
    /// edges is a pair [u, v] with u < v, that represents an undirected edge 
    /// connecting nodes u and v.
    /// 
    /// Return an edge that can be removed so that the resulting graph is a 
    /// tree of N nodes. If there are multiple answers, return the answer 
    /// that occurs last in the given 2D-array. The answer edge [u, v] should 
    /// be in the same format, with u < v.
    ///
    /// Example 1:
    /// Input: [[1,2], [1,3], [2,3]]
    /// Output: [2,3]
    /// Explanation: The given undirected graph will be like this:
    ///  1
    /// / \
    /// 2 - 3
    ///
    /// Example 2:
    /// Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
    /// Output: [1,4]
    /// Explanation: The given undirected graph will be like this:
    /// 5 - 1 - 2
    ///    |   |
    ///    4 - 3
    /// Note:
    /// The size of the input 2D-array will be between 3 and 1000.
    /// Every integer represented in the 2D-array will be between 1 and N, 
    /// where N is the size of the input array.
    ///
    /// Update (2017-09-26):
    /// We have overhauled the problem description + test cases and specified 
    /// clearly the graph is an undirected graph. (For the directed graph 
    /// follow up please see Redundant Connection II). We apologize for any 
    /// inconvenience caused.
    /// </summary>
    vector<int> findRedundantConnection(vector<vector<int>>& edges);

    /// <summary>
    /// Leet code #685. Redundant Connection II
    /// 
    /// In this problem, a rooted tree is a directed graph such that, there 
    /// is exactly one node (the root) for which all other nodes are 
    /// descendants of this node, plus every node has exactly one parent, 
    /// except for the root node which has no parents.
    ///
    /// The given input is a directed graph that started as a rooted tree 
    /// with N nodes (with distinct values 1, 2, ..., N), with one additional 
    /// directed edge added. The added edge has two different vertices chosen 
    /// from 1 to N, and was not an edge that already existed.
    ///
    /// The resulting graph is given as a 2D-array of edges. Each element of 
    /// edges is a pair [u, v] that represents a directed edge connecting 
    /// nodes u and v, where u is a parent of child v.
    ///
    /// Return an edge that can be removed so that the resulting graph is a 
    /// rooted tree of N nodes. If there are multiple answers, return the 
    /// answer that occurs last in the given 2D-array.
    ///
    /// Example 1:
    /// Input: [[1,2], [1,3], [2,3]]
    /// Output: [2,3]
    /// Explanation: The given directed graph will be like this:
    ///   1 
    ///  / \
    /// v   v
    /// 2-->3
    ///
    /// Example 2:
    /// Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
    /// Output: [4,1]
    /// Explanation: The given directed graph will be like this:
    /// 5 <- 1 -> 2
    ///      ^    |
    ///      |    v
    ///      4 <- 3
    /// Note:
    /// The size of the input 2D-array will be between 3 and 1000.
    /// Every integer represented in the 2D-array will be between 1 and N, 
    /// where N is the size of the input array.
    /// </summary>
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges);

    /// <summary>
    /// Leet code #9902. Truck delivery 
    /// 
    /// There are a number of houses in a line, the distance between two houses are given in an array.
    /// for example the distance between house(0) and house(1) is in distance[1] and the distance between house(n-2) 
    /// and house(n-1) is given in distance[n-1]. distance[0] is always 0.
    /// A delivery truck stops in front of the houses, and the driver has 
    /// a number of packages to deliver, each with a weight[i], if no package for this house it is 0.
    /// The truck can only stop in front of one house, the driver should minimize the total cost of the delivery. 
    /// 
    /// Note:
    /// 1. The cost is defined by multiply the distance the driver should walk with the weight of package in hand, i.e.
    ///     It is weight[i] * distance[i]. 
    /// 2. If the driver walk back with empty hand the cost is zero. 
    /// 3. The driver is only allowed to carry one package at a time.
    /// </summary>
    int minDeliveryCost(vector<int> distance, vector<int> weight);

    /// <summary>
    /// Leet code #317. Shortest Distance from All Buildings  
    /// </summary>
    bool addDistance(int row, int col, int building_index, int step, vector<vector<int>>& grid, vector<vector<unordered_map<int, int>>>& distance_map);

    /// <summary>
    /// Leet code #317. Shortest Distance from All Buildings  
    /// 
    /// You want to build a house on an empty land which reaches all buildings in the shortest 
    /// amount of distance. You can only move up, down, left and right. You are given a 2D 
    /// grid of values 0, 1 or 2, where:
    /// Each 0 marks an empty land which you can pass by freely.
    /// Each 1 marks a building which you cannot pass through.
    /// Each 2 marks an obstacle which you cannot pass through.
    /// For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
    /// 1 - 0 - 2 - 0 - 1
    /// |   |   |   |   |
    /// 0 - 0 - 0 - 0 - 0
    /// |   |   |   |   |
    /// 0 - 0 - 1 - 0 - 0
    /// The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
    /// 
    /// Note:
    /// There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
    /// </summary>
    int shortestDistance(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #261. Graph Valid Tree  
    /// 
    /// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a 
    /// pair of nodes), write a function to check whether these edges make up a valid tree. 
    /// For example: 
    /// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true. 
    /// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false. 
    /// Hint:
    /// 1.Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? 
    ///   Is this case a valid tree? 
    /// 2.According to the definition of tree on Wikipedia: "a tree is an undirected 
    ///   graph in which any two vertices are connected by exactly one path. 
    ///   In other words, any connected graph without simple cycles is a tree."
    /// </summary>
    bool validTree(int n, vector<pair<int, int>>& edges);

    /// <summary>
    /// Leet code #269. Alien Dictionary
    /// There is a new alien language which uses the latin alphabet. However, the order among 
    /// letters are unknown to you. You receive a list of words from the dictionary, where words 
    /// are sorted lexicographically by the rules of this new language. Derive the 
    /// order of letters in this language. 
    ///
    /// For example,
    /// Given the following words in dictionary, 
    /// [
    ///   "wrt",
    ///   "wrf",
    ///   "er",
    ///   "ett",
    ///   "rftt"
    /// ]
    /// The correct order is: "wertf". 
    /// Note:
    /// 1.You may assume all letters are in lowercase.
    /// 2.If the order is invalid, return an empty string.
    /// 3.There may be multiple valid order of letters, return any one of them is fine.
    /// </summary>
    string alienOrder(vector<string>& words);

    /// <summary>
    /// Leet code #444. Sequence Reconstruction
    /// Check whether the original sequence org can be uniquely reconstructed from 
    /// the sequences in seqs. The org sequence is a permutation of the integers 
    /// from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest 
    /// common supersequence of the sequences in seqs (i.e., a shortest sequence so 
    /// that all sequences in seqs are subsequences of it). Determine whether there 
    /// is only one sequence that can be reconstructed from seqs and it is the 
    /// org sequence.
    ///
    /// Example 1: 
    /// Input: 
    /// org: [1,2,3], seqs: [[1,2],[1,3]] 
    ///
    /// Output:
    /// false 
    /// 
    /// Explanation:
    ///   [1,2,3] is not the only one sequence that can be reconstructed, because 
    ///   [1,3,2] is also a valid sequence that can be reconstructed.
    ///
    /// Example 2: 
    /// Input:
    /// org: [1,2,3], seqs: [[1,2]]
    /// Output:
    /// false
    ///
    /// Explanation:
    /// The reconstructed sequence can only be [1,2].
    ///
    /// Example 3: 
    /// Input:
    /// org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
    ///
    /// Output:
    /// true
    ///
    /// Explanation:
    /// The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the 
    /// original sequence [1,2,3].
    ///
    /// Example 4: 
    /// Input:
    /// org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
    ///
    /// Output:
    /// true
    /// </summary>
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs);

    /// <summary>
    /// Leet code #573. Squirrel Simulation
    /// There's a tree, a squirrel, and several nuts. Positions are represented 
    /// by the cells in a 2D grid. Your goal is to find the minimal distance 
    /// for the squirrel to collect all the nuts and put them under the tree 
    /// one by one. The squirrel can only take at most one nut at one time and 
    /// can move in four directions - up, down, left and right, to the adjacent 
    /// cell. The distance is represented by the number of moves. 
    ///
    /// Example 1:
    /// Input: 
    /// Height : 5
    /// Width : 7
    /// Tree position : [2,2]
    /// Squirrel : [4,4]
    /// Nuts : [[3,0], [2,5]]
    /// Output: 12
    /// Explanation:
    /// Note:
    ///
    /// 1.All given positions won't overlap.
    /// 2.The squirrel can take at most one nut at one time.
    /// 3.The given positions of nuts have no order.
    /// 4.Height and width are positive integers. 3 <= height * width <= 10,000.
    /// 5.The given positions contain at least one nut, only one tree and one 
    ///   squirrel.
    /// </summary>
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts);

    /// <summary>
    /// Leet code #582. Kill Process
    ///
    /// Given n processes, each process has a unique PID (process id) and its 
    /// PPID (parent process id).
    /// Each process only has one parent process, but may have one or more 
    /// children processes. This is just like a tree structure. Only one 
    /// process has PPID that is 0, which means this process has no parent 
    /// process. All the PIDs will be distinct positive integers.
    ///
    /// We use two list of integers to represent a list of processes, where 
    /// the first list contains PID for each process and the second list 
    /// contains the corresponding PPID.
    /// 
    /// Now given the two lists, and a PID representing a process you want 
    /// to kill, return a list of PIDs of processes that will be killed in 
    /// the end. You should assume that when a process is killed, 
    /// all its children processes will be killed. 
    /// No order is required for the final answer.
    /// Example 1:
    /// Input: 
    /// pid =  [1, 3, 10, 5]
    /// ppid = [3, 0, 5, 3]
    /// kill = 5
    /// Output: [5,10]
    /// Explanation: 
    ///           3
    ///         /   \
    ///        1     5
    ///             /
    ///            10
    /// Kill 5 will also kill 10.
    /// Note:
    /// 1. The given kill id is guaranteed to be one of the given PIDs.
    /// 2. n >= 1.
    /// </summary>
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill);

    /// <summary>
    /// Leet code #568. Maximum Vacation Days    
    /// 
    /// LeetCode wants to give one of its best employees the option to travel among
    /// N cities to collect algorithm problems. But all work and no play makes Jack 
    /// a dull boy, you could take vacations in some particular cities and weeks. 
    /// Your job is to schedule the traveling to maximize the number of vacation 
    /// days you could take, but there are certain rules and restrictions you need 
    /// to follow. 
    /// Rules and restrictions:
    /// You can only travel among N cities, represented by indexes from 0 to N-1. 
    /// Initially, you are in the city indexed 0 on Monday.
    /// The cities are connected by flights. The flights are represented as a N*N 
    /// matrix (not necessary symmetrical), called flights representing the airline
    /// status from the city i to the city j. If there is no flight from the city i 
    /// to the city j, flights[i][j] = 0; Otherwise, flights[i][j] = 1. Also, 
    /// flights[i][i] = 0 for all i.
    /// You totally have K weeks (each week has 7 days) to travel. You can only 
    /// take flights at most once per day and can only take flights on each week's 
    /// Monday morning. Since flight time is so short, we don't consider the impact 
    /// of flight time.
    /// For each city, you can only have restricted vacation days in different 
    /// weeks, given an N*K matrix called days representing this relationship. For 
    /// the value of days[i][j], it represents the maximum days you could take 
    /// vacation in the city i in the week j.
    /// 
    /// You're given the flights matrix and days matrix, and you need to output 
    /// the maximum vacation days you could take during K weeks.
    /// Example 1:
    /// Input:flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]]
    /// Output: 12
    /// Explanation: 
    /// Ans = 6 + 3 + 3 = 12. 
    /// One of the best strategies is:
    /// 1st week : fly from city 0 to city 1 on Monday, and play 6 days and work 1 
    /// day. 
    /// (Although you start at city 0, we could also fly to and start at other 
    ///  cities since it is Monday.) 
    /// 2nd week : fly from city 1 to city 2 on Monday, and play 3 days and work 4 
    /// days.
    /// 3rd week : stay at city 2, and play 3 days and work 4 days.
    /// Example 2:
    /// Input:flights = [[0,0,0],[0,0,0],[0,0,0]], days = [[1,1,1],[7,7,7],[7,7,7]]
    /// Output: 3
    /// Explanation: 
    /// Ans = 1 + 1 + 1 = 3. 
    /// Since there is no flights enable you to move to another city, you have to 
    /// stay at city 0 for the whole 3 weeks. 
    /// For each week, you only have one day to play and six days to work. 
    /// So the maximum number of vacation days is 3.
    /// Example 3:
    /// Input:flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[7,0,0],[0,7,0],[0,0,7]]
    /// Output: 21
    /// Explanation:
    /// Ans = 7 + 7 + 7 = 21
    /// One of the best strategies is:
    /// 1st week : stay at city 0, and play 7 days. 
    /// 2nd week : fly from city 0 to city 1 on Monday, and play 7 days.
    /// 3rd week : fly from city 1 to city 2 on Monday, and play 7 days.
    /// 
    /// Note:
    /// 1. N and K are positive integers, which are in the range of [1, 100].
    /// 2. In the matrix flights, all the values are integers in the range of [0, 1].
    /// 3. In the matrix days, all the values are integers in the range [0, 7].
    /// 4. You could stay at a city beyond the number of vacation days, but you should
    ///    work on the extra days, which won't be counted as vacation days.
    /// 5. If you fly from the city A to the city B and take the vacation on that day, 
    ///    the deduction towards vacation days will count towards the vacation days 
    ///    of city B in that week.
    /// 6. We don't consider the impact of flight hours towards the calculation of 
    ///    vacation days.
    /// </summary>
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days);

    /// <summary>
    /// Leet code #694. Number of Distinct Islands
    /// </summary>
    void getDistinctIslands(vector<vector<int>>& grid, vector<vector<int>>& visited, set<pair<int, int>>& island,
        int row, int col, int start_row, int start_col);

    /// <summary>
    /// Leet code #694. Number of Distinct Islands
    ///
    /// Given a non-empty 2D array grid of 0's and 1's, an island is a group 
    /// of 1's (representing land) connected 4-directionally (horizontal or 
    /// vertical.) You may assume all four edges of the grid are surrounded by 
    /// water.
    /// Count the number of distinct islands. An island is considered to be 
    /// the same as another if and only if one island can be translated (and 
    /// not rotated or reflected) to equal the other.
    ///
    /// Example 1:
    /// 11000
    /// 11000
    /// 00011
    /// 00011
    /// Given the above grid map, return 1.
    ///
    /// Example 2:
    /// 11011
    /// 10000
    /// 00001
    /// 11011
    /// Given the above grid map, return 3.
    /// 
    /// Notice that:
    /// 11
    /// 1
    /// and
    ///  1
    /// 11
    /// are considered different island shapes, because we do not consider 
    /// reflection / rotation.
    /// Note: The length of each dimension in the given grid does not 
    /// exceed 50.
    /// </summary>
    int numDistinctIslands(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #711. Number of Distinct Islands II
    /// Get rotated island;
    /// </summary>
    bool getRotateIslands(set<pair<int, int>>& island, set<set<pair<int, int>>>& result);

    /// <summary>
    /// Leet code #711. Number of Distinct Islands II
    /// Get reflect island;
    /// </summary>
    void getReflectIslands(set<pair<int, int>>& island, set<pair<int, int>>& new_island);

    /// <summary>
    /// Leet code #711. Number of Distinct Islands II
    /// Get reflect island;
    /// </summary>
    void adjustIslands(set<pair<int, int>>& island, set<pair<int, int>>& new_island);

    /// <summary>
    /// Leet code #711. Number of Distinct Islands II
    /// 
    /// Given a non-empty 2D array grid of 0's and 1's, an island is a group 
    /// of 1's (representing land) connected 4-directionally (horizontal or 
    /// vertical.) You may assume all four edges of the grid are surrounded 
    /// by water.
    ///
    /// Count the number of distinct islands. An island is considered to be 
    /// the same as another if they have the same shape, or have the same 
    /// shape after rotation (90, 180, or 270 degrees only) or reflection 
    /// (left/right direction or up/down direction).
    ///
    /// Example 1:
    /// 11000
    /// 10000
    /// 00001
    /// 00011
    /// Given the above grid map, return 1. 
    ///
    /// Notice that:
    /// 11
    /// 1
    /// and
    ///  1
    /// 11
    /// are considered same island shapes. Because if we make a 180 degrees 
    /// clockwise rotation on the first island, then two islands will have 
    /// the same shapes.
    /// Example 2:
    /// 11100
    /// 10001
    /// 01001
    /// 01110
    /// Given the above grid map, return 2.
    ///
    /// Here are the two distinct islands: 
    /// 111
    /// 1
    /// and
    /// 1
    /// 1
    ///
    /// Notice that:
    /// 111
    /// 1
    /// and
    /// 1
    /// 111
    /// are considered same island shapes. Because if we flip the first array 
    /// in the up/down direction, then they have the same shapes.
    /// Note: The length of each dimension in the given grid does not exceed 
    /// 50.
    /// </summary>
    int numDistinctIslands2(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #749. Contain Virus
    /// </summary>
    int searchVirus(vector<vector<int>>& grid, vector<vector<int>>& visited,
        set<pair<int, int>>& to_infected, int row, int col);

    /// <summary>
    /// Leet code #749. Contain Virus
    /// </summary>
    void spreadVirus(vector<vector<int>>& grid, vector<set<pair<int, int>>>& to_infect_cells, size_t exception);

    /// <summary>
    /// Leet code #749. Contain Virus
    /// </summary>
    void buildWall(vector<vector<int>>& grid, int row, int col);

    /// <summary>
    /// Leet code #749. Contain Virus
    ///
    /// A virus is spreading rapidly, and your task is to quarantine the 
    /// infected area by installing walls.
    ///
    /// The world is modeled as a 2-D array of cells, where 0 represents 
    /// uninfected cells, and 1 represents cells contaminated with the virus. 
    /// A wall (and only one wall) can be installed between any two 
    /// 4-directionally adjacent cells, on the shared boundary.
    /// 
    /// Every night, the virus spreads to all neighboring cells in all four 
    /// directions unless blocked by a wall. Resources are limited. Each day, 
    /// you can install walls around only one region -- the affected area 
    /// (continuous block of infected cells) that threatens the most 
    /// uninfected cells the following night. There will never be a tie.
    ///
    /// Can you save the day? If so, what is the number of walls required? 
    /// If not, and the world becomes fully infected, return the number of 
    /// walls used.
    ///
    /// Example 1:
    /// Input: grid = 
    /// [
    ///  [0,1,0,0,0,0,0,1],
    ///  [0,1,0,0,0,0,0,1],
    ///  [0,0,0,0,0,0,0,1],
    ///  [0,0,0,0,0,0,0,0]
    /// ]
    /// Output: 10
    /// Explanation:
    /// There are 2 contaminated regions.
    /// On the first day, add 5 walls to quarantine the viral region on the 
    /// left. The board after the virus spreads is:
    ///
    /// [
    ///  [0,1,0,0,0,0,1,1],
    ///  [0,1,0,0,0,0,1,1],
    ///  [0,0,0,0,0,0,1,1],
    ///  [0,0,0,0,0,0,0,1]
    /// ]
    ///
    /// On the second day, add 5 walls to quarantine the viral region on the 
    /// right. The virus is fully contained.
    ///
    /// Example 2:
    /// Input: grid = 
    /// [
    ///   [1,1,1],
    ///   [1,0,1],
    ///   [1,1,1]
    /// ]
    /// Output: 4
    /// Explanation: Even though there is only one cell saved, there are 4 
    /// walls built.
    /// Notice that walls are only built on the shared boundary of two 
    /// different cells.
    ///
    /// Example 3:
    /// Input: grid = 
    /// [
    ///   [1,1,1,0,0,0,0,0,0],
    ///   [1,0,1,0,1,1,1,1,1],
    ///   [1,1,1,0,0,0,0,0,0]
    /// ]
    /// Output: 13
    /// Explanation: The region on the left only builds two new walls.
    /// Note:
    /// 1. The number of rows and columns of grid will each be in the range 
    ///    [1, 50].
    /// 2. Each grid[i][j] will be either 0 or 1.
    /// 3. Throughout the described process, there is always a contiguous viral 
    ///    region that will infect strictly more uncontaminated squares in the 
    ///    next round.
    /// </summary>
    int containVirus(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #765. Couples Holding Hands   
    ///
    /// N couples sit in 2N seats arranged in a row and want to hold hands. 
    /// We want to know the minimum number of swaps so that every couple is 
    /// sitting side by side. A swap consists of choosing any two people, 
    /// then they stand up and switch seats.
    ///
    /// The people and seats are represented by an integer from 0 to 2N-1, 
    /// the couples are numbered in order, the first couple being (0, 1), the 
    /// second couple being (2, 3), and so on with the last couple being 
    /// (2N-2, 2N-1).
    ///
    /// The couples' initial seating is given by row[i] being the value of 
    /// the person who is initially sitting in the i-th seat.
    ///
    /// Example 1:
    ///
    /// Input: row = [0, 2, 1, 3]
    /// Output: 1
    /// Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
    /// Example 2:
    ///
    /// Input: row = [3, 2, 0, 1]
    /// Output: 0
    /// Explanation: All couples are already seated side by side.
    ///
    /// Note:
    /// 1. len(row) is even and in the range of [4, 60].
    /// 2. row is guaranteed to be a permutation of 0...len(row)-1.
    /// </summary>
    int minSwapsCouples(vector<int>& row);

    /// <summary>
    /// Leet code #802. Find Eventual Safe States
    /// 
    /// In a directed graph, we start at some node and every turn, walk along 
    /// a directed edge of the graph.  If we reach a node that is terminal 
    /// (that is, it has no outgoing directed edges), we stop.
    ///
    /// Now, say our starting node is eventually safe if and only if we must 
    /// eventually walk to a terminal node.  More specifically, there exists a 
    /// natural number K so that for any choice of where to walk, we must have 
    /// stopped at a terminal node in less than K steps.
    ///
    /// Which nodes are eventually safe?  Return them as an array in sorted 
    /// order.
    ///
    /// The directed graph has N nodes with labels 0, 1, ..., N-1, where N is 
    /// the length of graph.  The graph is given in the following form: 
    /// graph[i] is a list of labels j such that (i, j) is a directed edge of 
    /// the graph.
    ///
    /// Example:
    /// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    /// Output: [2,4,5,6]
    /// Here is a diagram of the above graph.
    ///
    /// Illustration of graph
    ///
    /// Note:
    ///
    /// 1. graph will have length at most 10000.
    /// 3. The number of edges in the graph will not exceed 32000.
    /// 3. Each graph[i] will be a sorted list of different integers, chosen 
    /// within the range [0, graph.length - 1].
    /// </summary>
    vector<int> eventualSafeNodes(vector<vector<int>>& graph);

    /// <summary>
    /// Leet code #815. Bus Routes
    /// 
    /// We have a list of bus routes. Each routes[i] is a bus route that the 
    /// i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this 
    /// means that the first bus (0-th indexed) travels in the sequence 
    /// 1->5->7->1->5->7->1->... forever.
    ///
    /// We start at bus stop S (initially not on a bus), and we want to go to 
    /// bus stop T. Travelling by buses only, what is the least number of 
    /// buses we must take to reach our destination? Return -1 if it is not 
    /// possible.
    ///
    /// Example:
    /// Input: 
    /// routes = [[1, 2, 7], [3, 6, 7]]
    /// S = 1
    /// T = 6
    /// Output: 2
    /// Explanation: 
    /// The best strategy is take the first bus to the bus stop 7, then take 
    /// the second bus to the bus stop 6.
    /// Note:
    ///
    /// 1. 1 <= routes.length <= 500.
    /// 2. 1 <= routes[i].length <= 500.
    /// 3. 0 <= routes[i][j] < 10 ^ 6.
    /// </summary>
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T);

    /// <summary>
    /// Leet code #841. Keys and Rooms
    /// 
    /// There are N rooms and you start in room 0.  Each room has a distinct 
    /// number in 0, 1, 2, ..., N-1, and each room may have some keys to 
    /// access the next room. 
    ///
    /// Formally, each room i has a list of keys rooms[i], and each key 
    /// rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  
    /// A key rooms[i][j] = v opens the room with number v.
    ///
    /// Initially, all the rooms start locked (except for room 0). 
    /// 
    /// You can walk back and forth between rooms freely.
    ///
    /// Return true if and only if you can enter every room.
    ///
    /// Example 1:
    ///
    /// Input: [[1],[2],[3],[]]
    /// Output: true
    /// Explanation:  
    /// We start in room 0, and pick up key 1.
    /// We then go to room 1, and pick up key 2.
    /// We then go to room 2, and pick up key 3.
    /// We then go to room 3.  Since we were able to go to every room, we 
    /// return true.
    ///
    /// Example 2:
    ///
    /// Input: [[1,3],[3,0,1],[2],[0]]
    /// Output: false
    /// Explanation: We can't enter the room with number 2.
    /// Note:
    ///
    /// 1. 1 <= rooms.length <= 1000
    /// 2. 0 <= rooms[i].length <= 1000
    /// 3. The number of keys in all rooms combined is at most 3000.
    /// </summary>
    bool canVisitAllRooms(vector<vector<int>>& rooms);

    /// <summary>
    /// Leet code #847. Shortest Path Visiting All Nodes
    /// 
    /// An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) 
    /// is given as graph.
    ///
    /// graph.length = N, and j != i is in the list graph[i] exactly once, if 
    /// and only if nodes i and j are connected.
    ///
    /// Return the length of the shortest path that visits every node. You may 
    /// start and stop at any node, you may revisit nodes multiple times, and 
    /// you may reuse edges.
    ///
    /// Example 1:
    ///
    /// Input: [[1,2,3],[0],[0],[0]]
    /// Output: 4
    /// Explanation: One possible path is [1,0,2,0,3]
    ///
    /// Example 2:
    ///
    /// Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
    /// Output: 4
    /// Explanation: One possible path is [0,1,4,2,3]
    ///
    ///
    /// Note:
    /// 1. 1 <= graph.length <= 12
    /// 2. 0 <= graph[i].length < graph.length
    /// </summary>
    int shortestPathLength(vector<vector<int>>& graph);

    /// <summary>
    /// Leet code #851. Loud and Rich
    /// 
    /// In a group of N people (labelled 0, 1, 2, ..., N-1), each person has 
    /// different amounts of money, and different levels of quietness.
    ///
    /// For convenience, we'll call the person with label x, simply "person x".
    ///
    /// We'll say that richer[i] = [x, y] if person x definitely has more money 
    /// than person y.  Note that richer may only be a subset of valid 
    /// observations.
    ///
    /// Also, we'll say quiet[x] = q if person x has quietness q.
    ///
    /// Now, return answer, where answer[x] = y if y is the least quiet person 
    /// (that is, the person y with the smallest value of quiet[y]), among all 
    /// people who definitely have equal to or more money than person x.
    ///
    /// Example 1:
    ///
    /// Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], 
    /// quiet = [3,2,5,4,6,1,7,0]
    /// Output: [5,5,2,5,4,5,6,7]
    /// Explanation: 
    /// answer[0] = 5.
    /// Person 5 has more money than 3, which has more money than 1, which has 
    /// more money than 0.
    /// The only person who is quieter (has lower quiet[x]) is person 7, but
    /// it isn't clear if they have more money than person 0.
    ///
    /// answer[7] = 7.
    /// Among all people that definitely have equal to or more money than person 7
    /// (which could be persons 3, 4, 5, 6, or 7), the person who is the quietest 
    /// (has lower quiet[x]) is person 7.
    ///
    /// The other answers can be filled out with similar reasoning.
    /// Note:
    ///
    /// 1. 1 <= quiet.length = N <= 500
    /// 2. 0 <= quiet[i] < N, all quiet[i] are different.
    /// 3. 0 <= richer.length <= N * (N-1) / 2
    /// 4. 0 <= richer[i][j] < N
    /// 5. richer[i][0] != richer[i][1]
    /// 6. richer[i]'s are all different.
    /// 7. The observations in richer are all logically consistent.
    /// </summary>
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet);

    /// <summary>
    /// Leet code #871. Minimum Number of Refueling Stops
    /// 
    /// A car travels from a starting position to a destination which is 
    /// target miles east of the starting position.
    /// 
    /// Along the way, there are gas stations.  Each station[i] represents 
    /// a gas station that is station[i][0] miles east of the starting 
    /// position, and has station[i][1] liters of gas.
    ///
    /// The car starts with an infinite tank of gas, which initially has 
    /// startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile 
    /// that it drives.
    /// 
    /// When the car reaches a gas station, it may stop and refuel, 
    /// transferring all the gas from the station into the car.
    ///
    /// What is the least number of refueling stops the car must make in order 
    /// to reach its destination?  If it cannot reach the destination, return 
    /// -1.
    ///
    /// Note that if the car reaches a gas station with 0 fuel left, the car 
    /// can still refuel there.  If the car reaches the destination with 0 
    /// fuel left, it is still considered to have arrived.
    ///
    /// Example 1:
    /// Input: target = 1, startFuel = 1, stations = []
    /// Output: 0
    /// Explanation: We can reach the target without refueling.
    ///
    /// Example 2:
    /// Input: target = 100, startFuel = 1, stations = [[10,100]]
    /// Output: -1
    /// Explanation: We can't reach the target (or even the first gas station).
    ///
    /// Example 3:
    /// Input: target = 100, startFuel = 10, stations = 
    /// [[10,60],[20,30],[30,30],[60,40]]
    /// Output: 2
    /// Explanation: 
    /// We start with 10 liters of fuel.
    /// We drive to position 10, expending 10 liters of fuel.  We refuel 
    /// from 0 liters to 60 liters of gas.
    /// Then, we drive from position 10 to position 60 (expending 50 liters 
    /// of fuel), and refuel from 10 liters to 50 liters of gas.  We then 
    /// drive to and reach the target.
    /// We made 2 refueling stops along the way, so we return 2.
    /// 
    /// Note:
    /// 1 <= target, startFuel, stations[i][1] <= 10^9
    /// 0 <= stations.length <= 500
    /// 0 < stations[0][0] < stations[1][0] < ... < 
    /// stations[stations.length-1][0] < target
    /// </summary>
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations);

    /// <summary>
    /// Leet code #913. Cat and Mouse
    /// 
    /// A game on an undirected graph is played by two players, Mouse and Cat, 
    /// who alternate turns.
    ///
    /// The graph is given as follows: graph[a] is a list of all nodes b such 
    /// that ab is an edge of the graph.
    ///
    /// Mouse starts at node 1 and goes first, Cat starts at node 2 and goes 
    /// second, and there is a Hole at node 0.
    ///
    /// During each player's turn, they must travel along one edge of the graph 
    /// that meets where they are.  For example, if the Mouse is at node 1, it 
    /// must travel to any node in graph[1].
    ///
    /// Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)
    ///
    /// Then, the game can end in 3 ways:
    ///
    /// If ever the Cat occupies the same node as the Mouse, the Cat wins.
    /// If ever the Mouse reaches the Hole, the Mouse wins.
    /// If ever a position is repeated (ie. the players are in the same position 
    /// as a previous turn, and it is the same player's turn to move), the game is 
    /// a draw.
    /// Given a graph, and assuming both players play optimally, return 1 if the 
    /// game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a 
    /// draw.
    ///
    /// Example 1:
    ///
    /// Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
    /// Output: 0
    /// Explanation:
    /// 4---3---1
    /// |   |
    /// 2---5
    ///  \ /
    ///   0
    /// 
    /// Note:
    ///
    /// 1. 3 <= graph.length <= 50
    /// 2. It is guaranteed that graph[1] is non-empty.
    /// 3. It is guaranteed that graph[2] contains a non-zero element. 
    /// </summary>
    int catMouseGame(vector<vector<int>>& graph);

    /// <summary>
    /// Leet code #943. Find the Shortest Superstring
    /// </summary>
    string calculateOverlapString(string& string1, string& string2);

    /// <summary>
    /// Leet code #943. Find the Shortest Superstring
    /// 
    /// Given an array A of strings, find any smallest string that contains each 
    /// string in A as a substring.
    ///
    /// We may assume that no string in A is substring of another string in A.
    ///
    /// Example 1:
    /// Input: ["alex","loves","leetcode"]
    /// Output: "alexlovesleetcode"
    /// Explanation: All permutations of "alex","loves","leetcode" would also be 
    /// accepted.
    ///
    /// Example 2:
    /// Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
    /// Output: "gctaagttcatgcatc"
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 12
    /// 2. 1 <= A[i].length <= 20
    /// </summary>
    string shortestSuperstring(vector<string>& A);

    /// <summary>
    /// Leet code #959. Regions Cut By Slashes
    /// 
    /// In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of 
    /// a /, \, or blank space.  These characters divide the square into 
    /// contiguous regions.
    ///
    /// (Note that backslash characters are escaped, so a \ is represented as "\\".)
    /// 
    /// Return the number of regions.
    /// 
    /// Example 1:
    /// 
    /// Input:
    /// [
    ///   " /",
    ///   "/ "
    /// ]
    /// Output: 2
    /// Explanation: The 2x2 grid is as follows:
    ///
    /// Example 2:
    ///
    /// Input:
    /// [
    ///   " /",
    ///   "  "
    /// ]
    /// Output: 1
    /// Explanation: The 2x2 grid is as follows:
    ///
    /// Example 3:
    ///
    /// Input:
    /// [
    ///   "\\/",
    ///   "/\\"
    /// ]
    /// Output: 4
    /// Explanation: (Recall that because \ characters are escaped, "\\/" refers 
    /// to \/, and "/\\" refers to /\.)
    /// The 2x2 grid is as follows:
    ///
    /// Example 4:
    ///
    /// Input:
    /// [
    ///   "/\\",
    ///   "\\/"
    /// ]
    /// Output: 5
    /// Explanation: (Recall that because \ characters are escaped, "/\\" refers 
    /// to /\, and "\\/" refers to \/.)
    /// The 2x2 grid is as follows:
    /// 
    /// Example 5:
    ///
    /// Input:
    /// [
    ///   "//",
    ///   "/ "
    /// ]
    /// Output: 3
    /// Explanation: The 2x2 grid is as follows:
    ///
    /// Note:
    /// 
    /// 1. 1 <= grid.length == grid[0].length <= 30
    /// 2. grid[i][j] is either '/', '\', or ' '.
    /// </summary>
    int regionsBySlashes(vector<string>& grid);

    /// <summary>
    /// Leet code #1057. Campus Bikes
    /// 
    /// On a campus represented as a 2D grid, there are N workers and M bikes, 
    /// with N <= M. Each worker and bike is a 2D coordinate on this grid.
    ///
    /// Our goal is to assign a bike to each worker. Among the available bikes 
    /// and workers, we choose the (worker, bike) pair with the shortest Manhattan 
    /// distance between each other, and assign the bike to that worker. (If there 
    /// are multiple (worker, bike) pairs with the same shortest Manhattan 
    /// distance, we choose the pair with the smallest worker index; if there are 
    /// multiple ways to do that, we choose the pair with the smallest bike 
    /// index). We repeat this process until there are no available workers.
    ///
    /// The Manhattan distance between two points p1 and p2 is 
    /// Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
    ///
    /// Return a vector ans of length N, where ans[i] is the index (0-indexed) of 
    /// the bike that the i-th worker is assigned to.
    /// 
    /// Example 1:
    /// Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
    /// Output: [1,0]
    /// Explanation: 
    /// Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is 
    /// assigned Bike 1. So the output is [1, 0].
    ///
    /// Example 2:
    /// Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
    /// Output: [0,2,1]
    /// Explanation: 
    /// Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same 
    /// distance to Bike 2, thus Worker 1 is assigned to Bike 2, and Worker 2 will 
    /// take Bike 1. So the output is [0,2,1].
    /// 
    /// Note:
    /// 1. 0 <= workers[i][j], bikes[i][j] < 1000
    /// 2. All worker and bike locations are distinct.
    /// 3. 1 <= workers.length <= bikes.length <= 1000
    /// </summary>
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes);

    /// <summary>
    /// Leet code 1059. All Paths from Source Lead to Destination
    /// </summary>
    bool leadsToDestination(vector<vector<int>>& edges, vector<int>& visited,
        int source, int destination);

    /// <summary>
    /// Leet code 1059. All Paths from Source Lead to Destination
    /// 
    /// Given the edges of a directed graph, and two nodes source and destination 
    /// of this graph, determine whether or not all paths starting from source 
    /// eventually end at destination, that is:
    ///
    /// At least one path exists from the source node to the destination node
    /// If a path exists from the source node to a node with no outgoing edges, 
    /// then that node is equal to destination.
    /// The number of possible paths from source to destination is a finite number.
    /// Return true if and only if all roads from source lead to destination.
    /// 
    /// Example 1:
    /// Input: n = 3, edges = [[0,1],[0,2]], source = 0, destination = 2
    /// Output: false
    /// Explanation: It is possible to reach and get stuck on both node 1 and 
    /// node 2.
    ///
    /// Example 2:
    /// Input: n = 4, edges = [[0,1],[0,3],[1,2],[2,1]], source = 0, 
    /// destination = 3
    /// Output: false
    /// Explanation: We have two possibilities: to end at node 3, or to loop 
    /// over node 1 and node 2 indefinitely.
    ///
    /// Example 3:
    /// Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, 
    /// destination = 3
    /// Output: true
    ///
    /// Example 4:
    /// Input: n = 3, edges = [[0,1],[1,1],[1,2]], source = 0, destination = 2
    /// Output: false
    /// Explanation: All paths from the source node end at the destination node, 
    /// but there are an infinite number of paths, such as 0-1-2, 0-1-1-2, 
    /// 0-1-1-1-2, 0-1-1-1-1-2, and so on.
    ///
    /// Example 5:
    /// Input: n = 2, edges = [[0,1],[1,1]], source = 0, destination = 1
    /// Output: false
    /// Explanation: There is infinite self-loop at destination node.
    ///
    /// Note:
    ///
    /// 1. The given graph may have self loops and parallel edges.
    /// 2. The number of nodes n in the graph is between 1 and 10000
    /// 3. The number of edges in the graph is between 0 and 10000
    /// 4. 0 <= edges.length <= 10000
    /// 5. edges[i].length == 2
    /// 6. 0 <= source <= n - 1
    /// 7. 0 <= destination <= n - 1
    /// </summary>
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination);

    /// <summary>
    /// Leet code #1102. Path With Maximum Minimum Value
    /// 
    /// Given a matrix of integers A with R rows and C columns, find the maximum 
    /// score of a path starting at [0,0] and ending at [R-1,C-1].
    ///
    /// The score of a path is the minimum value in that path.  For example, the 
    /// value of the path 8 →  4 →  5 →  9 is 4.
    ///
    /// A path moves some number of times from one visited cell to any neighbouring 
    /// unvisited cell in one of the 4 cardinal directions (north, east, west, 
    /// south).
    ///
    ///
    ///
    /// Example 1: 
    /// Input: [[5,4,5],[1,2,6],[7,4,6]]
    /// Output: 4
    /// Explanation: 
    /// The path with the maximum score is highlighted in yellow. 
    ///
    /// Example 2:
    /// Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
    /// Output: 2
    ///
    /// Example 3:
    ///
    /// Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],
    /// [4,6,5,4,3]]
    /// Output: 3
    /// 
    /// Note:
    /// 1. 1 <= R, C <= 100
    /// 2. 0 <= A[i][j] <= 10^9
    /// </summary>
    int maximumMinimumPath(vector<vector<int>>& A);

    /// <summary>
    /// Leet code #1135. Connecting Cities With Minimum Cost
    /// 
    /// There are N cities numbered from 1 to N.
    /// 
    /// You are given connections, where each connections[i] = 
    /// [city1, city2, cost] represents the cost to connect city1 
    /// and city2 together.  (A connection is bidirectional: 
    /// connecting city1 and city2 is the same as connecting city2 
    /// and city1.)
    ///
    /// Return the minimum cost so that for every pair of cities, 
    /// there exists a path of connections (possibly of length 1) 
    /// that connects those two cities together.  The cost is the 
    /// sum of the connection costs used. If the task is impossible, 
    /// return -1.
    ///
    /// Example 1:
    /// Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
    /// Output: 6
    /// Explanation: 
    /// Choosing any 2 edges will connect all cities so we choose the minimum 2.
    ///
    /// Example 2:
    /// Input: N = 4, connections = [[1,2,3],[3,4,4]]
    /// Output: -1
    /// Explanation: 
    /// There is no way to connect all cities even if all edges are used.
    /// 
    /// Note:
    /// 1. 1 <= N <= 10000
    /// 2. 1 <= connections.length <= 10000
    /// 3. 1 <= connections[i][0], connections[i][1] <= N
    /// 4. 0 <= connections[i][2] <= 10^5
    /// 5. connections[i][0] != connections[i][1]
    /// </summary>
    int minimumCost(int N, vector<vector<int>>& connections);

    /// <summary>
    /// Leet code #1136. Parallel Courses
    /// 
    /// There are N courses, labelled from 1 to N.
    /// 
    /// We are given relations[i] = [X, Y], representing a prerequisite 
    /// relationship between course X and course Y: course X has to be 
    /// studied before course Y.
    ///
    /// In one semester you can study any number of courses as long as 
    /// you have studied all the prerequisites for the course you are 
    /// studying.
    ///
    /// Return the minimum number of semesters needed to study all 
    /// courses.  If there is no way to study all the courses, return -1.
    /// 
    /// Example 1:
    /// Input: N = 3, relations = [[1,3],[2,3]]
    /// Output: 2
    /// Explanation: 
    /// In the first semester, courses 1 and 2 are studied. In the second 
    /// semester, course 3 is studied.
    ///
    /// Example 2:
    /// Input: N = 3, relations = [[1,2],[2,3],[3,1]]
    /// Output: -1
    /// Explanation: 
    /// No course can be studied because they depend on each other.
    ///  
    /// Note:
    /// 1. 1 <= N <= 5000
    /// 2. 1 <= relations.length <= 5000
    /// 3. relations[i][0] != relations[i][1]
    /// 4. There are no repeated relations in the input.
    /// </summary>
    int minimumSemesters(int N, vector<vector<int>>& relations);

    /// <summary>
    /// Leet code #1129. Shortest Path with Alternating Colors
    /// 
    /// Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this 
    /// graph, each edge is either red or blue, and there could be self-edges 
    /// or parallel edges.
    ///
    /// Each [i, j] in red_edges denotes a red directed edge from node i to 
    /// node j.  Similarly, each [i, j] in blue_edges denotes a blue directed 
    /// edge from node i to node j.
    ///
    /// Return an array answer of length n, where each answer[X] is the length 
    /// of the shortest path from node 0 to node X such that the edge colors 
    /// alternate along the path (or -1 if such a path doesn't exist).
    /// 
    /// Example 1:
    /// Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
    /// Output: [0,1,-1]
    ///
    /// Example 2:
    /// Input: n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
    /// Output: [0,1,-1]
    ///
    /// Example 3:
    /// Input: n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
    /// Output: [0,-1,-1]
    ///
    /// Example 4:
    /// Input: n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
    /// Output: [0,1,2]
    ///
    /// Example 5:
    /// Input: n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
    /// Output: [0,1,1]
    /// </summary>
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges,
        vector<vector<int>>& blue_edges);

    /// <summary>
    /// Leet code #1153. String Transforms Into Another String
    /// 
    /// Given two strings str1 and str2 of the same length, determine whether 
    /// you can transform str1 into str2 by doing zero or more conversions.
    /// In one conversion you can convert all occurrences of one character 
    /// in str1 to any other lowercase English character.
    /// Return true if and only if you can transform str1 into str2.
    /// 
    /// Example 1:
    /// Input: str1 = "aabcc", str2 = "ccdee"
    /// Output: true
    /// Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. 
    /// Note that the order of conversions matter.
    ///
    /// Example 2:
    /// Input: str1 = "leetcode", str2 = "codeleet"
    /// Output: false
    /// Explanation: There is no way to transform str1 to str2.
    /// 
    /// Note:
    /// 1. 1 <= str1.length == str2.length <= 10^4
    /// 2. Both str1 and str2 contain only lowercase English letters.
    /// </summary>
    bool canConvert(string str1, string str2);

    /// <summary>
    /// Leet code #1168. Optimize Water Distribution in a Village
    /// 
    /// There are n houses in a village. We want to supply water for all 
    /// the houses by building wells and laying pipes.
    /// For each house i, we can either build a well inside it directly with 
    /// cost wells[i], or pipe in water from another well to it. The costs to 
    /// lay pipes between houses are given by the array pipes, where each 
    /// pipes[i] = [house1, house2, cost] represents the cost to connect house1 
    /// and house2 together using a pipe. Connections are bidirectional.
    /// Find the minimum total cost to supply water to all houses.
    /// 
    /// Example 1:
    ///
    /// Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
    /// Output: 3
    /// Explanation: 
    /// The image shows the costs of connecting houses using pipes.
    /// The best strategy is to build a well in the first house with cost 1 and 
    /// connect the other houses to it with cost 2 so the total cost is 3.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10000
    /// 2. wells.length == n
    /// 3. 0 <= wells[i] <= 10^5
    /// 4. 1 <= pipes.length <= 10000
    /// 5. 1 <= pipes[i][0], pipes[i][1] <= n
    /// 6. 0 <= pipes[i][2] <= 10^5
    /// 7. pipes[i][0] != pipes[i][1]
    /// </summary>
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes);

    /// <summary>
    /// Leet code #778. Swim in Rising Water    
    ///
    /// On an N x N grid, each square grid[i][j] represents the elevation at 
    /// that point (i,j).
    ///
    /// Now rain starts to fall. At time t, the depth of the water everywhere 
    /// is t. You can swim from a square to another 4-directionally adjacent 
    /// square if and only if the elevation of both squares individually are 
    /// at most t. You can swim infinite distance in zero time. Of course, 
    /// you must stay within the boundaries of the grid during your swim.
    /// 
    /// You start at the top left square (0, 0). What is the least time 
    /// until you can reach the bottom right square (N-1, N-1)?
    ///
    /// Example 1:
    ///
    /// Input: [[0,2],[1,3]]
    /// Output: 3
    /// Explanation:
    /// At time 0, you are in grid location (0, 0).
    /// You cannot go anywhere else because 4-directionally adjacent neighbors 
    /// have a higher elevation than t = 0.
    ///
    /// You cannot reach point (1, 1) until time 3.
    /// When the depth of water is 3, we can swim anywhere inside the grid.
    /// Example 2:
    ///
    /// Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],
    ///         [10,9,8,7,6]]
    /// Output: 16
    /// Explanation:
    /// 0  1  2  3  4
    /// 24 23 22 21 5
    /// 12 13 14 15 16
    /// 11 17 18 19 20
    /// 10  9  8  7  6
    ///
    /// The final route is marked in bold.
    /// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
    /// Note:
    ///
    /// 1. 2 <= N <= 50.
    /// 2. grid[i][j] is a permutation of [0, ..., N*N - 1].
    /// </summary>
    int swimInWater(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #886. Possible Bipartition
    /// 
    /// Given a set of N people (numbered 1, 2, ..., N), we would like to split 
    /// everyone into two groups of any size.
    ///
    /// Each person may dislike some other people, and they should not go into the 
    /// same group. 
    ///
    /// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the 
    /// people numbered a and b into the same group.
    ///
    /// Return true if and only if it is possible to split everyone into two groups 
    /// in this way.
    ///
    /// Example 1:
    /// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
    /// Output: true
    /// Explanation: group1 [1,4], group2 [2,3]
    ///
    /// Example 2:
    /// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
    /// Output: false
    ///
    /// Example 3:
    /// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
    /// Output: false
    /// 
    /// Note:
    ///
    /// 1 <= N <= 2000
    /// 0 <= dislikes.length <= 10000
    /// 1 <= dislikes[i][j] <= N
    /// dislikes[i][0] < dislikes[i][1]
    /// There does not exist i != j for which dislikes[i] == dislikes[j].
    /// </summary>
    bool possibleBipartition(int N, vector<vector<int>>& dislikes);

    /// <summary>
    /// Leet code #1192. Critical Connections in a Network
    /// </summary>
    int criticalConnections(int prev, int curr, int& rank, unordered_map<int, unordered_map<int, int>>& graph, vector<int>& dp);

    /// <summary>
    /// Leet code #1192. Critical Connections in a Network
    /// 
    /// There are n servers numbered from 0 to n-1 connected by undirected 
    /// server-to-server connections forming a network where 
    /// connections[i] = [a, b] represents a connection between servers a and b. 
    /// Any server can reach any other server directly or indirectly through the 
    /// network.
    /// A critical connection is a connection that, if removed, will make some 
    /// server unable to reach some other server.
    /// Return all critical connections in the network in any order.
    /// 
    /// Example 1:
    ///
    /// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    /// Output: [[1,3]]
    /// Explanation: [[3,1]] is also accepted.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. n-1 <= connections.length <= 10^5
    /// 3. connections[i][0] != connections[i][1]
    /// 4. There are no repeated connections.
    /// </summary>
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections);

    /// <summary>
    /// Leet code #1203. Sort Items by Groups Respecting Dependencies
    /// 
    /// There are n items each belonging to zero or one of m groups where group[i] 
    /// is the group that the i-th item belongs to and it's equal to -1 if the 
    /// i-th item belongs to no group. The items and the groups are zero indexed. 
    /// A group can have no item belonging to it.
    /// Return a sorted list of the items such that:
    /// The items that belong to the same group are next to each other in the 
    /// sorted list.
    /// There are some relations between these items where beforeItems[i] is a list
    /// containing all the items that should come before the i-th item in the 
    /// sorted array (to the left of the i-th item).
    /// Return any solution if there is more than one solution and return an empty 
    /// list if there is no solution.
    /// 
    /// Example 1:
    ///
    /// Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],
    /// [5],[6],[3,6],[],[],[]]
    /// Output: [6,3,4,1,5,2,0,7]
    ///
    /// Example 2:
    /// Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],
    /// [5],[6],[3],[],[4],[]]
    /// Output: []
    /// Explanation: This is the same as example 1 except that 4 needs to be 
    /// before 6 in the sorted list.
    ///
    /// Constraints:
    /// 1. 1 <= m <= n <= 3*10^4
    /// 2. group.length == beforeItems.length == n
    /// 3. -1 <= group[i] <= m-1
    /// 4. 0 <= beforeItems[i].length <= n-1
    /// 5. 0 <= beforeItems[i][j] <= n-1
    /// 6. i != beforeItems[i][j]
    /// 7. beforeItems[i] does not contain duplicates elements.
    /// </summary>
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems);

    /// <summary>
    /// Leet code #1210. Minimum Moves to Reach Target with Rotations
    ///
    /// In an n*n grid, there is a snake that spans 2 cells and starts moving 
    /// from the top left corner at (0, 0) and (0, 1). The grid has empty cells 
    /// represented by zeros and blocked cells represented by ones. The snake 
    /// wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
    ///
    /// In one move the snake can:
    ///
    /// Move one cell to the right if there are no blocked cells there. This 
    /// move keeps the horizontal/vertical position of the snake as it is.
    /// Move down one cell if there are no blocked cells there. This move keeps 
    /// the horizontal/vertical position of the snake as it is.
    /// Rotate clockwise if it's in a horizontal position and the two cells under 
    /// it are both empty. In that case the snake moves from (r, c) and (r, c+1) 
    /// to (r, c) and (r+1, c).
    /// Rotate counterclockwise if it's in a vertical position and the two cells 
    /// to its right are both empty. In that case the snake moves from (r, c) and 
    /// (r+1, c) to (r, c) and (r, c+1).
    ///
    /// Return the minimum number of moves to reach the target.
    ///
    /// If there is no way to reach the target, return -1.
    /// 
    /// Example 1:
    /// 
    /// Input: grid = [[0,0,0,0,0,1],
    ///               [1,1,0,0,1,0],
    ///               [0,0,0,0,1,1],
    ///               [0,0,1,0,1,0],
    ///               [0,1,1,0,0,0],
    ///               [0,1,1,0,0,0]]
    /// Output: 11
    /// Explanation:
    /// One possible solution is [right, right, rotate clockwise, right, down, down, 
    /// down, down, rotate counterclockwise, right, down].
    ///
    /// Example 2:
    ///
    /// Input: grid = [[0,0,1,1,1,1],
    ///               [0,0,0,0,1,1],
    ///               [1,1,0,0,0,1],
    ///               [1,1,1,0,0,1],
    ///               [1,1,1,0,0,1],
    ///               [1,1,1,0,0,0]]
    /// Output: 9
    ///  
    /// Constraints:
    /// 1. 2 <= n <= 100
    /// 2. 0 <= grid[i][j] <= 1
    /// 3. It is guaranteed that the snake starts at empty cells.
    /// </summary>
    int minimumMoves(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #174. Dungeon Game 
    /// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists 
    /// of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight 
    /// his way through the dungeon to rescue the princess. 
    ///
    /// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 
    /// or below, he dies immediately. 
    /// Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
    /// other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
    /// In order to reach the princess as quickly as possible, the knight decides to move only 
    /// rightward or downward in each step. 
    /// Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
    /// For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path 
    /// RIGHT-> RIGHT -> DOWN -> DOWN.
    /// -2 (K) -3 3 
    /// -5 -10 1 
    /// 10 30 -5 (P) 
    /// Notes: 
    /// The knight's health has no upper bound.
    /// Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
    /// </summary>
    int calculateMinimumHP(vector<vector<int>>& dungeon);

    /// <summary>
    /// Leet code #1245. Tree Diameter
    ///  
    /// Given an undirected tree, return its diameter: the number of edges in a 
    /// longest path in that tree.
    ///
    /// The tree is given as an array of edges where edges[i] = [u, v] is a 
    /// bidirectional edge between nodes u and v.  Each node has labels in the 
    /// set {0, 1, ..., edges.length}.
    /// 
    /// Example 1:
    ///
    /// Input: edges = [[0,1],[0,2]]
    /// Output: 2
    /// Explanation: 
    /// A longest path of the tree is the path 1 - 0 - 2.
    ///
    /// Example 2:
    /// 
    /// Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
    /// Output: 4
    /// Explanation: 
    /// A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
    /// 
    /// Constraints:
    /// 1. 0 <= edges.length < 10^4
    /// 2. edges[i][0] != edges[i][1]
    /// 3. 0 <= edges[i][j] <= edges.length
    /// 4. The given edges form an undirected tree.
    /// </summary>
    int treeDiameter(vector<vector<int>>& edges);

    /// <summary>
    /// Leet code #1254. Number of Closed Islands
    /// </summary>
    bool closedIsland(vector<vector<int>>& grid, int row, int col);

    /// <summary>
    /// Leet code #1254. Number of Closed Islands
    /// 
    /// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a 
    /// maximal 4-directionally connected group of 0s and a closed island is 
    /// an island totally (all left, top, right, bottom) surrounded by 1s.
    ///
    /// Return the number of closed islands.
    /// 
    /// Example 1:
    /// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],
    /// [1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
    /// Output: 2
    /// Explanation: 
    /// Islands in gray are closed because they are completely surrounded by 
    /// water (group of 1s).
    ///
    /// Example 2:
    /// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
    /// Output: 1
    ///
    /// Example 3:
    ///
    /// Input: grid = [[1,1,1,1,1,1,1],
    ///               [1,0,0,0,0,0,1],
    ///               [1,0,1,1,1,0,1],
    ///               [1,0,1,0,1,0,1],
    ///               [1,0,1,1,1,0,1],
    ///               [1,0,0,0,0,0,1],
    ///               [1,1,1,1,1,1,1]]
    /// Output: 2
    /// Constraints:
    /// 1. 1 <= grid.length, grid[0].length <= 100
    /// 2. 0 <= grid[i][j] <=1
    /// </summary>
    int closedIsland(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #529. Minesweeper
    ///
    /// Let's play the minesweeper game (Wikipedia, online game)! 
    /// You are given a 2D char matrix representing the game board. 'M' 
    /// represents an unrevealed mine, 'E' represents an unrevealed empty square, 
    /// 'B' represents a revealed blank square that has no adjacent (above, below, 
    /// left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how 
    /// many mines are adjacent to this revealed square, and finally 'X' represents 
    /// a revealed mine.
    ///
    /// Now given the next click position (row and column indices) among all the 
    /// unrevealed squares ('M' or 'E'), return the board after revealing this 
    /// position according to the following rules:
    ///
    /// If a mine ('M') is revealed, then the game is over - change it to 'X'.
    /// If an empty square ('E') with no adjacent mines is revealed, then change it 
    /// to revealed blank ('B') and all of its adjacent unrevealed squares should be 
    /// revealed recursively.
    /// If an empty square ('E') with at least one adjacent mine is revealed, then 
    /// change it to a digit ('1' to '8') representing the number of adjacent mines.
    /// Return the board when no more squares will be revealed.
    /// Example 1:
    /// Input: 
    ///
    /// [['E', 'E', 'E', 'E', 'E'],
    ///  ['E', 'E', 'M', 'E', 'E'],
    ///  ['E', 'E', 'E', 'E', 'E'],
    /// ['E', 'E', 'E', 'E', 'E']]
    /// Click : [3,0]
    /// Output: 
    /// 
    /// [['B', '1', 'E', '1', 'B'],
    ///  ['B', '1', 'M', '1', 'B'],
    ///  ['B', '1', '1', '1', 'B'],
    ///  ['B', 'B', 'B', 'B', 'B']]
    ///
    /// Explanation:
    ///
    /// Example 2:
    /// Input: 
    /// 
    /// [['B', '1', 'E', '1', 'B'],
    ///  ['B', '1', 'M', '1', 'B'],
    ///  ['B', '1', '1', '1', 'B'],
    ///  ['B', 'B', 'B', 'B', 'B']]
    /// Click : [1,2]
    /// Output: 
    /// 
    /// [['B', '1', 'E', '1', 'B'],
    ///  ['B', '1', 'X', '1', 'B'],
    ///  ['B', '1', '1', '1', 'B'],
    ///  ['B', 'B', 'B', 'B', 'B']]
    ///
    /// Explanation:
    /// Note:
    /// The range of the input matrix's height and width is [1,50].
    /// The click position will only be an unrevealed square ('M' or 'E'), 
    /// which also means the input board contains at least one clickable square.
    /// The input board won't be a stage when game is over (some mines have been revealed).
    /// For simplicity, not mentioned rules should be ignored in this problem. For example, 
    /// you don't need to reveal all the unrevealed mines when the game is over, consider 
    /// any cases that you will win the game or flag any squares.
    /// </summary>
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click);

    /// <summary>
    /// Leet code #1258. Synonymous Sentences
    /// 
    /// Given a list of pairs of equivalent words synonyms and a sentence 
    /// text, Return all possible synonymous sentences sorted 
    /// lexicographically.
    ///
    /// Example 1:
    ///
    /// Input:
    /// synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]],
    /// text = "I am happy today but was sad yesterday"
    /// Output:
    /// ["I am cheerful today but was sad yesterday",
    /// "I am cheerful today but was sorrow yesterday",
    /// "I am happy today but was sad yesterday",
    /// "I am happy today but was sorrow yesterday",
    /// "I am joy today but was sad yesterday",
    /// "I am joy today but was sorrow yesterday"]
    /// 
    /// Constraints:
    /// 1. 0 <= synonyms.length <= 10
    /// 2. synonyms[i].length == 2
    /// 3. synonyms[0] != synonyms[1]
    /// 4. All words consist of at most 10 English letters only.
    /// 5. text is a single space separated sentence of at most 10 words.
    /// </summary>
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text);

    /// <summary>
    /// Leet code #1263. Minimum Moves to Move a Box to Their Target Location
    /// </summary>
    int minPushBox(vector<vector<char>>& grid, int sx, int sy,int tx, int ty);

    /// <summary>
    /// Leet code #1263. Minimum Moves to Move a Box to Their Target Location
    /// 
    /// Storekeeper is a game, in which the player pushes boxes around in a 
    /// warehouse, trying to get them to target locations.
    ///
    /// The game is represented by a grid of size n*m, where each element is 
    /// a wall, floor or a box.
    ///
    /// Your task is move the box 'B' to the target position 'T' under the 
    /// following rules:
    ///
    /// Player is represented by character 'S' and can move up, down, left, 
    /// right in the grid if its a floor (empy cell).
    /// Floor is represented by character '.' that means free cell to walk.
    /// Wall is represented by character '#' that means obstacle  
    /// (impossible to walk there). 
    /// There is only one box 'B' and one target cell 'T' in the grid.
    /// The box can be moved to an adjacent free cell by standing next to 
    /// the box and then moving in the direction of the box. This is a push.
    /// The player cannot walk through the box.
    /// Return the minimum number of pushes to move the box to the target. 
    /// If there is no way to reach the target, return -1.
    ///
    ///
    /// Example 1:
    ///
    /// Input: grid = [["#","#","#","#","#","#"],
    ///           ["#","T","#","#","#","#"],
    ///           ["#",".",".","B",".","#"],
    ///           ["#",".","#","#",".","#"],
    ///           ["#",".",".",".","S","#"],
    ///           ["#","#","#","#","#","#"]]
    /// Output: 3
    /// Explanation: We return only the number of times the box is pushed.
    ///
    /// Example 2:
    /// 
    /// Input: grid = [["#","#","#","#","#","#"],
    ///           ["#","T","#","#","#","#"],
    ///           ["#",".",".","B",".","#"],
    ///           ["#","#","#","#",".","#"],
    ///           ["#",".",".",".","S","#"],
    ///           ["#","#","#","#","#","#"]]
    /// Output: -1
    ///
    /// Example 3:
    /// 
    /// Input: grid = [["#","#","#","#","#","#"],
    ///           ["#","T",".",".","#","#"],
    ///           ["#",".","#","B",".","#"],
    ///           ["#",".",".",".",".","#"],
    ///           ["#",".",".",".","S","#"],
    ///           ["#","#","#","#","#","#"]]
    /// Output: 5
    /// Explanation:  push the box down, left, left, up and up.
    ///
    /// Example 4:
    ///
    /// Input: grid = [["#","#","#","#","#","#","#"],
    ///           ["#","S","#",".","B","T","#"],
    ///           ["#","#","#","#","#","#","#"]]
    /// Output: -1
    /// 
    /// Constraints:
    /// 1. 1 <= grid.length <= 20
    /// 2. 1 <= grid[i].length <= 20
    /// 3. grid contains only characters '.', '#',  'S' , 'T', or 'B'.
    /// 4. There is only one character 'S', 'B' and 'T' in the grid.
    /// </summary>
    int minPushBox(vector<vector<char>>& grid);

    /// <summary>
    /// Leet code #463. Island Perimeter
    /// 
    /// You are given a map in form of a two-dimensional integer grid where 1 
    /// represents land and 0 represents water.
    ///
    /// Grid cells are connected horizontally/vertically (not diagonally). 
    /// The grid is completely surrounded by water, and there is exactly one 
    /// island (i.e., one or more connected land cells).
    ///
    /// The island doesn't have "lakes" (water inside that isn't connected to 
    /// the water around the island). One cell is a square with side length 1. 
    /// The grid is rectangular, width and height don't exceed 100. Determine 
    /// the perimeter of the island.
    ///
    /// Example:
    /// 
    /// Input:
    /// [
    ///  [0,1,0,0],
    ///  [1,1,1,0],
    ///  [0,1,0,0],
    ///  [1,1,0,0]
    /// ]
    ///
    /// Output: 16
    /// Explanation: The perimeter is the 16 yellow stripes in the image below:
    /// </summary>
    int islandPerimeter(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1273. Delete Tree Nodes
    /// 
    /// A tree rooted at node 0 is given as follows:
    ///
    /// The number of nodes is nodes;
    /// The value of the i-th node is value[i];
    /// The parent of the i-th node is parent[i].
    /// Remove every subtree whose sum of values of nodes is zero.
    ///
    /// After doing so, return the number of nodes remaining in the tree.
    ///
    /// Example 1:
    ///
    /// Input: nodes = 7, parent = [-1,0,0,1,2,2,2], 
    /// value = [1,-2,4,0,-2,-1,-1]
    ///
    /// Output: 2
    ///
    /// Constraints:
    /// 1. 1 <= nodes <= 10^4
    /// 2. -10^5 <= value[i] <= 10^5
    /// 3. parent.length == nodes
    /// 4. parent[0] == -1 which indicates that 0 is the root.
    /// </summary>
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value);

    /// <summary>
    /// Leetcode #1293. Shortest Path in a Grid with Obstacles Elimination
    /// 
    /// Given a m * n grid, where each cell is either 0 (empty) or 1 
    /// (obstacle). In one step, you can move up, down, left or right from 
    /// and to an empty cell.
    ///
    /// Return the minimum number of steps to walk from the upper left 
    /// corner (0, 0) to the lower right corner (m-1, n-1) given that you can 
    /// eliminate at most k obstacles. If it is not possible to find such 
    /// walk return -1.
    /// 
    /// Example 1:
    /// Input: 
    /// grid = 
    /// [[0,0,0],
    ///  [1,1,0],
    ///  [0,0,0],
    ///  [0,1,1],
    ///  [0,0,0]], 
    /// k = 1
    /// Output: 6
    /// Explanation: 
    /// The shortest path without eliminating any obstacle is 10. 
    /// The shortest path with one obstacle elimination at position (3,2) 
    /// is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> 
    /// (3,2) -> (4,2).
    ///
    /// Example 2:
    /// Input: 
    /// grid = 
    /// [[0,1,1],
    ///  [1,1,1],
    ///  [1,0,0]], 
    /// k = 1
    /// Output: -1
    /// Explanation: 
    /// We need to eliminate at least two obstacles to find such a walk.
    /// 
    /// Constraints:
    ///
    /// 1. grid.length == m
    /// 2. grid[0].length == n
    /// 3. 1 <= m, n <= 40
    /// 4. 1 <= k <= m*n
    /// 5. grid[i][j] == 0 or 1
    /// 6. grid[0][0] == grid[m-1][n-1] == 0
    /// </summary>
    int shortestPath(vector<vector<int>>& grid, int k);

    /// <summary>
    /// Leetcode #1298. Maximum Candies You Can Get from Boxes
    ///
    /// Hard	
    ///
    /// Given n boxes, each box is given in the format [status, candies, 
    /// keys, containedBoxes] where:
    ///
    /// status[i]: an integer which is 1 if box[i] is open and 0 if box[i] 
    /// is closed.
    /// candies[i]: an integer representing the number of candies in box[i].
    /// keys[i]: an array contains the indices of the boxes you can open with 
    /// the key in box[i].
    /// containedBoxes[i]: an array contains the indices of the boxes found 
    /// in box[i].
    /// You will start with some boxes given in initialBoxes array. You can 
    /// take all the candies in any open box and you can use the keys in it 
    /// to open new boxes and you also can use the boxes you find in it.
    ///
    /// Return the maximum number of candies you can get following the rules 
    /// above.
    /// 
    /// Example 1:
    ///
    /// Input: status = [1,0,1,0], candies = [7,5,4,100], 
    /// keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], 
    /// initialBoxes = [0]
    /// Output: 16
    /// Explanation: You will be initially given box 0. You will find 7 
    /// candies in it and boxes 1 and 2. Box 1 is closed and you don't 
    /// have a key for it so you will open box 2. You will find 4 candies 
    /// and a key to box 1 in box 2.
    /// In box 1, you will find 5 candies and box 3 but you will not find 
    /// a key to box 3 so box 3 will remain closed.
    /// Total number of candies collected = 7 + 4 + 5 = 16 candy.
    ///
    /// Example 2:
    ///
    /// Input: status = [1,0,0,0,0,0], candies = [1,1,1,1,1,1], 
    /// keys = [[1,2,3,4,5],[],[],[],[],[]], 
    /// containedBoxes = [[1,2,3,4,5],[],[],[],[],[]], initialBoxes = [0]
    /// Output: 6
    /// Explanation: You have initially box 0. Opening it you can find 
    /// boxes 1,2,3,4 and 5 and their keys. The total number of candies 
    /// will be 6.
    ///
    /// Example 3:
    /// 
    /// Input: status = [1,1,1], candies = [100,1,100], keys = [[],[0,2],[]], 
    /// containedBoxes = [[],[],[]], initialBoxes = [1]
    /// Output: 1
    ///
    /// Example 4:
    /// 
    /// Input: status = [1], candies = [100], keys = [[]], 
    /// containedBoxes = [[]], initialBoxes = []
    /// Output: 0
    ///
    /// Example 5:
    ///
    /// Input: status = [1,1,1], candies = [2,3,2], keys = [[],[],[]], 
    /// containedBoxes = [[],[],[]], initialBoxes = [2,1,0]
    /// Output: 7
    /// 
    /// Constraints:
    /// 1. 1 <= status.length <= 1000
    /// 2. status.length == candies.length == keys.length == 
    ///    containedBoxes.length == n
    /// 3. status[i] is 0 or 1.
    /// 4. 1 <= candies[i] <= 1000
    /// 5. 0 <= keys[i].length <= status.length
    /// 6. 0 <= keys[i][j] < status.length
    /// 7. All values in keys[i] are unique.
    /// 8. 0 <= containedBoxes[i].length <= status.length
    /// 9. 0 <= containedBoxes[i][j] < status.length
    /// 10. All values in containedBoxes[i] are unique.
    /// 11. Each box is contained in one box at most.
    /// 12. 0 <= initialBoxes.length <= status.length
    /// 13. 0 <= initialBoxes[i] < status.length
    /// </summary>
    int maxCandies(vector<int>& status, vector<int>& candies,
        vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
        vector<int>& initialBoxes);

    /// <summary>
    /// Leet code #505. The Maze II  
    /// </summary>
    void shortestDistance(vector<vector<int>>& maze, vector<vector<int>>& visited,
        vector<int>& start, priority_queue<pair<int, vector<int>>>& process_queue);

    /// <summary>
    /// Leet code #505. The Maze II  
    /// 
    /// There is a ball in a maze with empty spaces and walls. The ball can 
    /// go through empty spaces by rolling up, down, left or right, but it 
    /// won't stop rolling until hitting a wall. When the ball stops, it could 
    /// choose the next direction.
    /// 
    /// Given the ball's start position, the destination and the maze, find the 
    /// shortest distance for the ball to stop at the destination. The distance 
    /// is defined by the number of empty spaces traveled by the ball from the 
    /// start position (excluded) to the destination (included). If the ball 
    /// cannot stop at the destination, return -1.
    ///     
    /// The maze is represented by a binary 2D array. 1 means the wall and 0 
    /// means the empty space. You may assume that the borders of the maze 
    /// are all walls. 
    /// The start and destination coordinates are represented by row and 
    /// column indexes.
    ///
    /// Example 1 
    /// Input 1: a maze represented by a 2D array
    ///
    /// 0 0 1 0 0
    /// 0 0 0 0 0
    /// 0 0 0 1 0
    /// 1 1 0 1 1
    /// 0 0 0 0 0
    /// Input 2: start coordinate (rowStart, colStart) = (0, 4)
    /// Input 3: destination coordinate (rowDest, colDest) = (4, 4)
    ///
    /// Output: 12
    /// Explanation: One shortest way is : 
    /// left -> down -> left -> down -> right -> down -> right.
    /// The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
    ///
    /// Example 2 
    /// Input 1: a maze represented by a 2D array
    ///
    /// 0 0 1 0 0
    /// 0 0 0 0 0
    /// 0 0 0 1 0
    /// 1 1 0 1 1
    /// 0 0 0 0 0
    /// Input 2: start coordinate (rowStart, colStart) = (0, 4)
    /// Input 3: destination coordinate (rowDest, colDest) = (3, 2)
    /// Output: -1
    /// Explanation: There is no way for the ball to stop at the destination.
    /// 
    /// Note:
    /// 1.There is only one ball and one destination in the maze.
    /// 2.Both the ball and the destination exist on an empty space, 
    ///   and they will not be at the same position initially.
    /// 3.The given maze does not contain border (like the red rectangle in 
    ///   the example pictures), but you could assume the border of the maze 
    ///   are all walls.
    /// 4.The maze contains at least 2 empty spaces, and both the width and 
    ///   height of the maze won't exceed 100.
    /// </summary>
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination);

    /// <summary>
    /// Leet code #499. The Maze III   
    /// </summary>
    void findShortestWay(vector<vector<int>>& maze, vector<vector<pair<int, string>>>& visited,
        vector<int>& ball, vector<int>& hole, priority_queue<pair<int, vector<int>>>& process_queue);

    /// <summary>
    /// Leet code #499. The Maze III   
    /// 
    /// There is a ball in a maze with empty spaces and walls. The ball can 
    /// go through empty spaces by rolling up (u), down (d), left (l) or right (r), 
    /// but it won't stop rolling until hitting a wall. When the ball stops, 
    /// it could choose the next direction. There is also a hole in this maze. 
    /// The ball will drop into the hole if it rolls on to the hole.
    /// 
    /// Given the ball position, the hole position and the maze, find out how the 
    /// ball could drop into the hole by moving the shortest distance. The distance 
    /// is defined by the number of empty spaces traveled by the ball from the start 
    /// position (excluded) to the hole (included). Output the moving directions by 
    /// using 'u', 'd', 'l' and 'r'. Since there could be several different shortest 
    /// ways, you should output the lexicographically smallest way. If the ball 
    /// cannot reach the hole, output "impossible".
    ///
    /// The maze is represented by a binary 2D array. 1 means the wall and 0 means the 
    /// empty space. You may assume that the borders of the maze are all walls. 
    /// The ball and the hole coordinates are represented by row and column indexes.
    ///
    /// Example 1 
    /// Input 1: a maze represented by a 2D array
    ///
    /// 0 0 0 0 0
    /// 1 1 0 0 1
    /// 0 0 0 0 0
    /// 0 1 0 0 1
    /// 0 1 0 0 0
    ///
    /// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
    /// Input 3: hole coordinate (rowHole, colHole) = (0, 1)
    ///
    /// Output: "lul"
    /// Explanation: There are two shortest ways for the ball to drop into the hole.
    /// The first way is left -> up -> left, represented by "lul".
    /// The second way is up -> left, represented by 'ul'.
    /// Both ways have shortest distance 6, but the first way is lexicographically 
    /// smaller because 'l' < 'u'. So the output is "lul".
    ///
    /// Example 2 
    /// Input 1: a maze represented by a 2D array
    ///
    /// 0 0 0 0 0
    /// 1 1 0 0 1
    /// 0 0 0 0 0
    /// 0 1 0 0 1
    /// 0 1 0 0 0
    ///
    /// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
    /// Input 3: hole coordinate (rowHole, colHole) = (3, 0)
    /// Output: "impossible"
    /// Explanation: The ball cannot reach the hole.
    ///
    /// Note:
    /// 1.There is only one ball and one hole in the maze.
    /// 2.Both the ball and hole exist on an empty space, and they will not be at 
    ///   the same position initially.
    /// 3.The given maze does not contain border (like the red rectangle in the 
    ///   example pictures), but you could assume the border of the maze are all walls.
    /// 4.The maze contains at least 2 empty spaces, and the width and the height of 
    ///   the maze won't exceed 30.
    /// </summary>
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole);

    /// <summary>
    /// Leet code #490. The Maze  
    /// </summary>
    bool hasPath(vector<vector<int>>& maze, vector<vector<int>>& visited, vector<int>& start, vector<int>& destination);

    /// <summary>
    /// Leet code #490. The Maze 
    /// 
    /// There is a ball in a maze with empty spaces and walls. The ball can 
    /// go through empty spaces by rolling up, down, left or right, but it 
    /// won't stop rolling until hitting a wall. When the ball stops, it could 
    /// choose the next direction.
    /// 
    /// Given the ball's start position, the destination and the maze, determine 
    /// whether the ball could stop at the destination.
    /// The maze is represented by a binary 2D array. 1 means the wall and 0 means 
    /// the empty space. You may assume that the borders of the maze are all walls. 
    /// The start and destination coordinates are represented by row and column indexes.
    ///
    /// Example 1 
    /// Input 1: a maze represented by a 2D array
    ///
    /// 0 0 1 0 0
    /// 0 0 0 0 0
    /// 0 0 0 1 0
    /// 1 1 0 1 1
    /// 0 0 0 0 0
    /// Input 2: start coordinate (rowStart, colStart) = (0, 4)
    /// Input 3: destination coordinate (rowDest, colDest) = (4, 4)
    ///
    /// Output: true
    /// Explanation: One possible way is : 
    /// left -> down -> left -> down -> right -> down -> right.
    ///
    /// Example 2 
    /// Input 1: a maze represented by a 2D array
    ///
    /// 0 0 1 0 0
    /// 0 0 0 0 0
    /// 0 0 0 1 0
    /// 1 1 0 1 1
    /// 0 0 0 0 0
    /// Input 2: start coordinate (rowStart, colStart) = (0, 4)
    /// Input 3: destination coordinate (rowDest, colDest) = (3, 2)
    /// Output: false
    /// Explanation: There is no way for the ball to stop at the destination.
    /// 
    /// Note: 
    /// 1.There is only one ball and one destination in the maze.
    /// 2.Both the ball and the destination exist on an empty space, and they will not 
    ///   be at the same position initially.
    /// 3.The given maze does not contain border (like the red rectangle in the example 
    ///   pictures), but you could assume the border of the maze are all walls.
    /// 4.The maze contains at least 2 empty spaces, and both the width and height of the 
    ///   maze won't exceed 100.
    /// </summary>
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination);

    /// <summary>
    /// Leet code #675. Cut Off Trees for Golf Event
    /// </summary>
    int calculateShortestDistance(vector<vector<int>>& forest, pair<int, int> &source, pair<int, int> &target);

    /// <summary>
    /// Leet code #675. Cut Off Trees for Golf Event
    /// You are asked to cut off trees in a forest for a golf event. The 
    /// forest is represented as a non-negative 2D map, in this map:
    /// 
    /// 0 represents the obstacle can't be reached.
    /// 1 represents the ground can be walked through.
    /// The place with number bigger than 1 represents a tree can be walked 
    /// through, and this positive number represents the tree's height.
    /// You are asked to cut off all the trees in this forest in the order of 
    /// tree's height - always cut off the tree with lowest height first. And 
    /// after cutting, the original place has the tree will become a grass 
    /// (value 1).
    ///
    /// You will start from the point (0, 0) and you should output the minimum
    /// steps you need to walk to cut off all the trees. If you can't cut off 
    /// all the trees, output -1 in that situation.
    ///
    /// You are guaranteed that no two trees have the same height and there is
    /// at least one tree needs to be cut off.
    ///
    /// Example 1:
    /// Input: 
    /// [
    ///   [1,2,3],
    ///   [0,0,4],
    ///   [7,6,5]
    /// ]
    /// Output: 6
    /// Example 2:
    /// Input: 
    /// [
    ///   [1,2,3],
    ///   [0,0,0],
    ///   [7,6,5]
    /// ]
    /// Output: -1
    /// Example 3:
    /// Input: 
    /// [
    ///    [2,3,4],
    ///    [0,0,5],
    ///    [8,7,6]
    /// ]
    /// Output: 6
    /// Explanation: You started from the point (0,0) and you can cut off the 
    /// tree in (0,0) directly without walking.
    /// Hint: size of the given matrix will not exceed 50x50.
    /// </summary>
    int cutOffTree(vector<vector<int>>& forest);

    /// <summary>
    /// Leet code #785. Is Graph Bipartite?    
    ///
    /// Given a graph, return true if and only if it is bipartite.
    ///
    /// Recall that a graph is bipartite if we can split it's set of nodes 
    /// into two independent subsets A and B such that every edge in the 
    /// graph has one node in A and another node in B.
    /// 
    /// The graph is given in the following form: graph[i] is a list of 
    /// indexes j for which the edge between nodes i and j exists.  Each node 
    /// is an integer between 0 and graph.length - 1.  There are no self edges 
    /// or parallel edges: graph[i] does not contain i, and it doesn't contain 
    /// any element twice.
    ///
    /// Example 1:
    /// Input: [[1,3], [0,2], [1,3], [0,2]]
    /// Output: true
    /// Explanation: 
    /// The graph looks like this:
    /// 0----1
    /// |    |
    /// |    |
    /// 3----2
    /// We can divide the vertices into two groups: {0, 2} and {1, 3}.
    ///
    /// Example 2:
    /// Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
    /// Output: false
    /// Explanation: 
    /// The graph looks like this:
    /// 0----1
    /// | \  |
    /// |  \ |
    /// 3----2
    /// We cannot find a way to divide the set of nodes into two independent 
    /// ubsets.
    /// 
    /// Note:
    /// graph will have length in range [1, 100].
    /// graph[i] will contain integers in range [0, graph.length - 1].
    /// graph[i] will not contain i or duplicate values.
    /// </summary>
    bool isBipartite(vector<vector<int>>& graph);

    /// <summary>
    /// Leet code #787. Cheapest Flights Within K Stops    
    ///
    /// There are n cities connected by m flights. Each fight starts from 
    /// city u and arrives at v with a price w.
    ///
    /// Now given all the cities and fights, together with starting city src 
    /// and the destination dst, your task is to find the cheapest price from 
    /// src to dst with up to k stops. If there is no such route, output -1.
    ///
    /// Example 1:
    /// Input: 
    /// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
    /// src = 0, dst = 2, k = 1
    /// Output: 200
    /// Explanation: 
    /// The graph looks like this:
    ///
    /// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, 
    /// as marked red in the picture.
    /// Example 2:
    /// Input: 
    /// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
    /// src = 0, dst = 2, k = 0
    /// Output: 500
    /// Explanation: 
    /// The graph looks like this:
    ///
    /// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, 
    /// as marked blue in the picture.
    /// Note:
    ///
    /// 1. The number of nodes n will be in range [1, 100], with nodes labeled 
    ///    from 0 to n - 1.
    /// 2. The size of flights will be in range [0, n * (n - 1) / 2].
    /// 3. The format of each flight will be (src, dst, price).
    /// 4. The price of each flight will be in the range [1, 10000].
    /// 5. k is in the range of [0, n - 1].
    /// 6. There will not be any duplicated flights or self cycles.
    /// </summary>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K);

    /// <summary>
    /// Leet code #407. Trapping Rain Water II  
    /// 
    /// Given an m x n matrix of positive integers representing the height of each unit cell 
    /// in a 2D elevation map, compute the volume of water it is able to trap after raining. 
    ///
    /// Note:
    /// Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000. 
    /// Example: 
    /// Given the following 3x6 height map:
    /// [
    ///   [1,4,3,1,3,2],
    ///   [3,2,1,3,2,4],
    ///   [2,3,3,2,3,1]
    /// ]
    /// Return 4.
    /// </summary>
    int trapRainWater(vector<vector<int>>& heightMap);

    /// <summary>
    /// Leet code #1311. Get Watched Videos by Your Friends
    /// 
    /// Medium
    ///
    /// There are n people, each person has a unique id between 0 and n-1. 
    /// Given the arrays watchedVideos and friends, where watchedVideos[i] 
    /// and friends[i] contain the list of watched videos and the list of 
    /// friends respectively for the person with id = i.
    /// Level 1 of videos are all watched videos by your friends, level 2 
    /// of videos are all watched videos by the friends of your friends and 
    /// so on. In general, the level k of videos are all watched videos by 
    /// people with the shortest path equal to k with you. Given your id and 
    /// the level of videos, return the list of videos ordered by their 
    /// frequencies (increasing). For videos with the same frequency order 
    /// them alphabetically from least to greatest. 
    ///
    /// Example 1:
    /// Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]],
    /// friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
    /// Output: ["B","C"] 
    /// Explanation: 
    /// You have id = 0 (green color in the figure) and your friends are 
    /// (yellow color in the figure):
    /// Person with id = 1 -> watchedVideos = ["C"] 
    /// Person with id = 2 -> watchedVideos = ["B","C"] 
    /// The frequencies of watchedVideos by your friends are: 
    /// B -> 1 
    /// C -> 2
    /// Example 2:
    ///
    /// Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], 
    /// friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
    /// Output: ["D"]
    /// Explanation: 
    /// You have id = 0 (green color in the figure) and the only friend of 
    /// your friends is the person with id = 3 (yellow color in the figure).
    ///
    /// Constraints:
    /// 1. n == watchedVideos.length == friends.length
    /// 2. 2 <= n <= 100
    /// 3. 1 <= watchedVideos[i].length <= 100
    /// 4. 1 <= watchedVideos[i][j].length <= 8
    /// 5. 0 <= friends[i].length < n
    /// 6. 0 <= friends[i][j] < n
    /// 7. 0 <= id < n
    /// 8. 1 <= level < n
    /// 9. if friends[i] contains j, then friends[j] contains i
    /// </summary>
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id, int level);

    /// <summary>
    /// Leet code #1340. Jump Game V
    /// </summary>
    int maxJumps(vector<int>& arr, vector<int>& path, int index, int d);

    /// <summary>
    /// Leet code #1340. Jump Game V
    /// 
    /// Hard
    ///
    /// Given an array of integers arr and an integer d. In one step you can 
    /// jump from index i to index:
    ///
    /// i + x where: i + x < arr.length and 0 < x <= d.
    /// i - x where: i - x >= 0 and 0 < x <= d.
    /// In addition, you can only jump from index i to index j if 
    /// arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i 
    /// and j (More formally min(i, j) < k < max(i, j)).
    ///
    /// You can choose any index of the array and start jumping. Return 
    /// the maximum number of indices you can visit.
    ///
    /// Notice that you can not jump outside of the array at any time.
    /// 
    /// Example 1:
    /// Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
    /// Output: 4
    /// Explanation: You can start at index 10. You can 
    /// jump 10 --> 8 --> 6 --> 7 as shown.
    /// Note that if you start at index 6 you can only jump to index 7. 
    /// You cannot jump to index 5 because 13 > 9. You cannot jump to 
    /// index 4 because index 5 is between index 4 and 6 and 13 > 9.
    /// Similarly You cannot jump from index 3 to index 2 or index 1.
    ///
    /// Example 2:
    /// Input: arr = [3,3,3,3,3], d = 3
    /// Output: 1
    /// Explanation: You can start at any index. You always cannot jump to 
    /// any index.
    ///
    /// Example 3:
    /// Input: arr = [7,6,5,4,3,2,1], d = 1
    /// Output: 7
    /// Explanation: Start at index 0. You can visit all the indicies. 
    ///
    /// Example 4:
    /// Input: arr = [7,1,7,1,7,1], d = 2
    /// Output: 2
    ///
    /// Example 5:
    /// Input: arr = [66], d = 1
    /// Output: 1
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 1000
    /// 2. 1 <= arr[i] <= 10^5
    /// 3. 1 <= d <= arr.length
    /// </summary>
    int maxJumps(vector<int>& arr, int d);

    /// <summary>
    /// Leet code #1345. Jump Game IV
    ///
    /// Hard
    ///
    /// Given an array of integers arr, you are initially positioned at the 
    /// first index of the array.
    ///
    /// In one step you can jump from index i to index:
    /// i + 1 where: i + 1 < arr.length.
    /// i - 1 where: i - 1 >= 0.
    /// j where: arr[i] == arr[j] and i != j.
    /// Return the minimum number of steps to reach the last index of the 
    /// array.
    ///
    /// Notice that you can not jump outside of the array at any time.
    ///
    /// Example 1:
    /// Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
    /// Output: 3
    /// Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. 
    /// Note that index 9 is the last index of the array.
    ///
    /// Example 2:
    /// Input: arr = [7]
    /// Output: 0
    /// Explanation: Start index is the last index. You don't need to jump.
    ///
    /// Example 3:
    /// Input: arr = [7,6,9,6,9,6,9,7]
    /// Output: 1
    /// Explanation: You can jump directly from index 0 to index 7 which 
    /// is last index of the array.
    ///
    /// Example 4:
    /// Input: arr = [6,1,9]
    /// Output: 2
    ///
    /// Example 5:
    /// Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
    /// Output: 3
    ///
    /// Constraints:
    /// 1. 1 <= arr.length <= 5 * 10^4
    /// 2. -10^8 <= arr[i] <= 10^8
    /// </summary>
    int minJumps(vector<int>& arr);

    /// <summary>
    /// Leet code #1361. Validate Binary Tree Nodes
    ///
    /// Medium
    ///
    /// You have n binary tree nodes numbered from 0 to n - 1 where node i has 
    /// two children leftChild[i] and rightChild[i], return true if and only 
    /// if all the given nodes form exactly one valid binary tree.
    ///
    /// If node i has no left child then leftChild[i] will equal -1, similarly 
    /// for the right child.
    /// Note that the nodes have no values and that we only use the node
    /// numbers in this problem.
    /// 
    /// Example 1:
    /// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
    /// Output: true
    ///
    /// Example 2:
    /// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
    /// Output: false
    ///
    /// Example 3:
    /// Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
    /// Output: false
    ///
    /// Example 4:
    /// Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], 
    /// rightChild = [2,-1,-1,5,-1,-1]
    /// Output: false
    ////
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// 2. leftChild.length == rightChild.length == n
    /// 3. -1 <= leftChild[i], rightChild[i] <= n - 1
    /// </summary>
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild);

    /// <summary>
    /// Leet code #1368. Minimum Cost to Make at Least One Valid Path in a Grid
    ///
    /// Hard
    ///
    /// Given a m x n grid. Each cell of the grid has a sign pointing to the 
    /// next cell you should visit if you are currently in this cell. The sign 
    /// of grid[i][j] can be:
    /// 1 which means go to the cell to the right. (i.e go from grid[i][j] 
    ///   to grid[i][j + 1])
    /// 2 which means go to the cell to the left. (i.e go from grid[i][j] to 
    ///   grid[i][j - 1])
    /// 3 which means go to the lower cell. (i.e go from grid[i][j] to 
    ///   grid[i + 1][j])
    /// 4 which means go to the upper cell. (i.e go from grid[i][j] to 
    ///   grid[i - 1][j])
    /// Notice that there could be some invalid signs on the cells of the 
    /// grid which points outside the grid.
    ///
    /// You will initially start at the upper left cell (0,0). A valid path 
    /// in the grid is a path which starts from the upper left cell (0,0) and 
    /// ends at the bottom-right cell (m - 1, n - 1) following the signs on 
    /// the grid. The valid path doesn't have to be the shortest.
    ///
    /// You can modify the sign on a cell with cost = 1. You can modify the 
    /// sign on a cell one time only.
    ///
    /// Return the minimum cost to make the grid have at least one valid path.
    /// 
    /// Example 1:
    /// 
    /// Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
    /// Output: 3
    /// Explanation: You will start at point (0, 0).
    /// The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> 
    /// (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> 
    /// (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 
    /// 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to 
    /// down with cost = 1 --> (3, 3)
    /// The total cost = 3.
    ///
    /// Example 2:
    /// Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
    /// Output: 0
    /// Explanation: You can follow the path from (0, 0) to (2, 2).
    ///
    /// Example 3:
    /// Input: grid = [[1,2],[4,3]]
    /// Output: 1
    ///
    /// Example 4:
    /// Input: grid = [[2,2,2],[2,2,2]]
    /// Output: 3
    ///
    /// Example 5:
    /// Input: grid = [[4]]
    /// Output: 0
    ///
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m, n <= 100
    /// </summary>
    int minCost(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1376. Time Needed to Inform All Employees
    ///  
    /// Medium
    ///
    /// A company has n employees with a unique ID for each employee from 0 
    /// to n - 1. The head of the company has is the one with headID.
    ///
    /// Each employee has one direct manager given in the manager array where 
    /// manager[i] is the direct manager of the i-th employee, 
    /// manager[headID] = -1. Also it's guaranteed that the subordination 
    /// relationships have a tree structure.
    ///
    /// The head of the company wants to inform all the employees of the 
    /// company of an urgent piece of news. He will inform his direct 
    /// subordinates and they will inform their subordinates and so on until 
    /// all employees know about the urgent news.
    ///
    /// The i-th employee needs informTime[i] minutes to inform all of his 
    /// direct subordinates (i.e After informTime[i] minutes, all his direct 
    /// subordinates can start spreading the news).
    ///
    /// Return the number of minutes needed to inform all the employees about 
    /// the urgent news.
    ///
    /// Example 1:
    /// Input: n = 1, headID = 0, manager = [-1], informTime = [0]
    /// Output: 0
    /// Explanation: The head of the company is the only employee in the 
    /// company.
    ///
    /// Example 2:
    /// Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], 
    /// informTime = [0,0,1,0,0,0]
    /// Output: 1
    /// Explanation: The head of the company with id = 2 is the direct 
    /// manager of all the employees in the company and needs 1 minute to 
    /// inform them all.
    /// The tree structure of the employees in the company is shown.
    ///
    /// Example 3:
    /// Input: n = 7, headID = 6, manager = [1,2,3,4,5,6,-1], 
    /// informTime = [0,6,5,4,3,2,1]
    /// Output: 21
    /// Explanation: The head has id = 6. He will inform employee with 
    /// id = 5 in 1 minute.
    /// The employee with id = 5 will inform the employee with id = 4 
    /// in 2 minutes.
    /// The employee with id = 4 will inform the employee with id = 3 
    /// in 3 minutes.
    /// The employee with id = 3 will inform the employee with id = 2 
    /// in 4 minutes.
    /// The employee with id = 2 will inform the employee with id = 1 
    /// in 5 minutes.
    /// The employee with id = 1 will inform the employee with id = 0 
    /// in 6 minutes.
    /// Needed time = 1 + 2 + 3 + 4 + 5 + 6 = 21.
    ///
    /// Example 4:
    /// Input: n = 15, headID = 0, manager = [-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6], 
    /// informTime = [1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]
    /// Output: 3
    /// Explanation: The first minute the head will inform employees 1 and 2.
    /// The second minute they will inform employees 3, 4, 5 and 6.
    /// The third minute they will inform the rest of employees.
    ///
    /// Example 5:
    /// Input: n = 4, headID = 2, manager = [3,3,-1,2], 
    /// informTime = [0,0,162,914]
    /// Output: 1076
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. 0 <= headID < n
    /// 3. manager.length == n
    /// 4. 0 <= manager[i] < n
    /// 5. manager[headID] == -1
    /// 6. informTime.length == n
    /// 7. 0 <= informTime[i] <= 1000
    /// 8. informTime[i] == 0 if employee i has no subordinates.
    /// 9. It is guaranteed that all the employees can be informed.
    /// </summary>
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime);

    /// <summary>
    /// Leet code #1377. Frog Position After T Seconds
    ///  
    /// Hard
    ///
    /// Given an undirected tree consisting of n vertices numbered from 1 
    /// to n. A frog starts jumping from the vertex 1. In one second, the 
    /// frog jumps from its current vertex to another unvisited vertex if 
    /// they are directly connected. The frog can not jump back to a visited 
    /// vertex. In case the frog can jump to several vertices it jumps 
    /// randomly to one of them with the same probability, otherwise, when 
    /// the frog can not jump to any unvisited vertex it jumps forever on 
    /// the same vertex. 
    /// The edges of the undirected tree are given in the array edges, 
    /// where edges[i] = [from[i], to[i]] means that exists an edge connecting 
    /// directly the vertices from[i] and to[i].
    ///
    /// Return the probability that after t seconds the frog is on the vertex 
    /// target.
    ///
    /// Example 1:
    /// Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, 
    ///  target = 4
    /// Output: 0.16666666666666666 
    /// Explanation: The figure above shows the given graph. The frog starts
    /// at vertex 1, jumping with 1/3 probability to the vertex 2 after 
    /// second 1 and then jumping with 1/2 probability to vertex 4 after 
    /// second 2. Thus the probability for the frog is on the vertex 4 after 2 
    /// seconds is 1/3 * 1/2 = 1/6 = 0.16666666666666666. 
    ///
    /// Example 2:
    /// Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, 
    /// target = 7
    /// Output: 0.3333333333333333
    /// Explanation: The figure above shows the given graph. The frog starts at 
    /// vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the 
    /// vertex 7 after second 1. 
    ///
    /// Example 3:
    /// Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, 
    /// target = 6
    /// Output: 0.16666666666666666
    ///
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// 2. edges.length == n-1
    /// 3. edges[i].length == 2
    /// 4. 1 <= edges[i][0], edges[i][1] <= n
    /// 5. 1 <= t <= 50
    /// 6. 1 <= target <= n
    /// 7. Answers within 10^-5 of the actual value will be accepted as 
    ///    correct.
    /// </summary>
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target);

    /// <summary>
    /// Leet code #1436. Destination City
    /// 
    /// Easy
    ///
    /// You are given the array paths, where paths[i] = [cityAi, cityBi] 
    /// means there exists a direct path going from cityAi to cityBi. 
    /// Return the destination city, that is, the city without any path 
    /// outgoing to another city.
    ///
    /// It is guaranteed that the graph of paths forms a line without any 
    /// loop, therefore, there will be exactly one destination city.
    /// 
    /// Example 1:
    /// Input: paths = [["London","New York"],["New York","Lima"],
    /// ["Lima","Sao Paulo"]]
    /// Output: "Sao Paulo" 
    /// Explanation: Starting at "London" city you will reach "Sao Paulo" 
    /// city which is the destination city. Your trip consist of: 
    /// "London" -> "New York" -> "Lima" -> "Sao Paulo".
    ///
    /// Example 2:
    /// Input: paths = [["B","C"],["D","B"],["C","A"]]
    /// Output: "A"
    /// Explanation: All possible trips are: 
    /// "D" -> "B" -> "C" -> "A". 
    /// "B" -> "C" -> "A". 
    /// "C" -> "A". 
    /// "A". 
    /// Clearly the destination city is "A".
    ///
    /// Example 3:
    /// Input: paths = [["A","Z"]]
    /// Output: "Z"
    /// 
    /// Constraints:
    /// 1. 1 <= paths.length <= 100
    /// 2. paths[i].length == 2
    /// 3. 1 <= cityA[i].length, cityB[i].length <= 10
    /// 4. cityA[i] != cityB[i]
    /// 5. All strings consist of lowercase and uppercase English letters 
    ///   and the space character.
    /// </summary>
    string destCity(vector<vector<string>>& paths);

    /// <summary>
    /// Leet code #1443. Minimum Time to Collect All Apples in a Tree
    ///
    /// Medium
    ///
    /// Given an undirected tree consisting of n vertices numbered from 0 to n-1, 
    /// which has some apples in their vertices. You spend 1 second to walk over 
    /// one edge of the tree. Return the minimum time in seconds you have to spend 
    /// in order to collect all apples in the tree starting at vertex 0 and coming 
    /// back to this vertex.
    ///
    /// The edges of the undirected tree are given in the array edges, where 
    /// edges[i] = [from[i], to[i]] means that exists an edge connecting the 
    /// vertices fromi and toi. Additionally, there is a boolean array hasApple, 
    /// where hasApple[i] = true means that vertex i has an apple, otherwise, it 
    /// does not have any apple.
    /// 
    /// Example 1:
    /// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], 
    /// hasApple = [false,false,true,false,true,true,false]
    /// Output: 8 
    /// Explanation: The figure above represents the given tree where red 
    /// vertices have an apple. One optimal path to collect all apples is 
    /// shown by the green arrows.  
    ///
    /// Example 2:
    /// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], 
    /// hasApple = [false,false,true,false,false,true,false]
    /// Output: 6
    /// Explanation: The figure above represents the given tree where red vertices 
    /// have an apple. One optimal path to collect all apples is shown by the 
    /// green arrows.  
    ///
    /// Example 3:
    /// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], 
    /// hasApple = [false,false,false,false,false,false,false]
    /// Output: 0
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. edges.length == n-1
    /// 3. edges[i].length == 2
    /// 4. 0 <= from[i], to[i] <= n-1
    /// 5. from[i] < to[i]
    /// 6. hasApple.length == n
    /// </summary>
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple);
#pragma endregion  

#pragma region UnionFind
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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions);

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

    /// <summary>
    /// Leet code #1462. Course Schedule IV
    /// 
    /// Medium
    ///
    /// There are a total of n courses you have to take, labeled from 0 to n-1.
    ///
    /// Some courses may have direct prerequisites, for example, to take 
    /// course 0 you have first to take course 1, which is expressed as a 
    /// pair: [1,0]
    ///
    /// Given the total number of courses n, a list of direct prerequisite 
    /// pairs and a list of queries pairs.
    ///
    /// You should answer for each queries[i] whether the course queries[i][0] 
    /// is a prerequisite of the course queries[i][1] or not.
    ///
    /// Return a list of boolean, the answers to the given queries.
    ///
    /// Please note that if course a is a prerequisite of course b and 
    /// course b is a prerequisite of course c, then, course a is a 
    /// prerequisite of course c.
    /// 
    /// Example 1:
    /// Input: n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
    /// Output: [false,true]
    /// Explanation: course 0 is not a prerequisite of course 1 but 
    /// the opposite is true.
    ///
    /// Example 2:
    /// Input: n = 2, prerequisites = [], queries = [[1,0],[0,1]]
    /// Output: [false,false]
    /// Explanation: There are no prerequisites and each course is independent.
    ///
    /// Example 3:
    /// Input: n = 3, prerequisites = [[1,2],[1,0],[2,0]], 
    /// queries = [[1,0],[1,2]]
    /// Output: [true,true]
    /// Example 4:
    /// Input: n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
    /// Output: [false,true]
    ///
    /// Example 5:
    /// Input: n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], 
    /// queries = [[0,4],[4,0],[1,3],[3,0]]
    /// Output: [true,false,true,false]
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 100
    /// 2. 0 <= prerequisite.length <= (n * (n - 1) / 2)
    /// 3. 0 <= prerequisite[i][0], prerequisite[i][1] < n
    /// 4. prerequisite[i][0] != prerequisite[i][1]
    /// 5. The prerequisites graph has no cycles.
    /// 6. The prerequisites graph has no repeated edges.
    /// 7. 1 <= queries.length <= 10^4
    /// 8. queries[i][0] != queries[i][1]
    /// </summary>
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code #1466. Reorder Routes to Make All Paths Lead to the City Zero
    /// 
    /// Medium
    ///
    /// There are n cities numbered from 0 to n-1 and n-1 roads such that 
    /// there is only one way to travel between two different cities (this 
    /// network form a tree). Last year, The ministry of transport decided to 
    /// orient the roads in one direction because they are too narrow.
    ///
    /// Roads are represented by connections where connections[i] = [a, b] 
    /// represents a road from city a to b.
    ///
    /// This year, there will be a big event in the capital (city 0), and 
    /// many people want to travel to this city.
    ///
    /// Your task consists of reorienting some roads such that each city 
    /// can visit the city 0. Return the minimum number of edges changed.
    ///
    /// It's guaranteed that each city can reach the city 0 after reorder.
    ///
    /// Example 1:
    /// Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
    /// Output: 3
    /// Explanation: Change the direction of edges show in red such that 
    /// each node can reach the node 0 (capital).
    ///
    /// Example 2:
    /// Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
    /// Output: 2
    /// Explanation: Change the direction of edges show in red such that 
    /// each node can reach the node 0 (capital).
    ///
    /// Example 3:
    /// Input: n = 3, connections = [[1,0],[2,0]]
    /// Output: 0
    ///
    /// Constraints:
    /// 1. 2 <= n <= 5 * 10^4
    /// 2. connections.length == n-1
    /// 3. connections[i].length == 2
    /// 4. 0 <= connections[i][0], connections[i][1] <= n-1
    /// 5. connections[i][0] != connections[i][1]
    /// </summary>
    int minReorder(int n, vector<vector<int>>& connections);

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
    /// Leet code #1489. Find Critical and Pseudo-Critical Edges in Minimum 
    ///                  Spanning Tree
    /// </summary>
    int get_mst(int n, vector<vector<int>>& edges, int start_edge, int ignore_edge);

    /// <summary>
    /// Leet code #1489. Find Critical and Pseudo-Critical Edges in Minimum 
    ///                  Spanning Tree
    /// 
    /// Hard
    ///
    /// Given a weighted undirected connected graph with n vertices numbered 
    /// from 0 to n-1, and an array edges where edges[i] = [fromi, toi, 
    /// weighti] represents a bidirectional and weighted edge between nodes 
    /// fromi and toi. A minimum spanning tree (MST) is a subset of the edges 
    /// of the graph that connects all vertices without cycles and with the 
    /// minimum possible total edge weight.
    ///
    /// Find all the critical and pseudo-critical edges in the minimum 
    /// spanning tree (MST) of the given graph. An MST edge whose deletion 
    /// from the graph would cause the MST weight to increase is called a 
    /// critical edge. A pseudo-critical edge, on the other hand, is that 
    /// which can appear in some MSTs but not all.
    ///
    /// Note that you can return the indices of the edges in any order.
    /// 
    /// Example 1:
    /// Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],
    /// [3,4,3],[1,4,6]]
    /// Output: [[0,1],[2,3,4,5]]
    /// Explanation: The figure above describes the graph.
    /// The following figure shows all the possible MSTs:
    /// Notice that the two edges 0 and 1 appear in all MSTs, therefore 
    /// they are critical edges, so we return them in the first list of 
    /// the output.
    /// The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they 
    /// are considered pseudo-critical edges. We add them to the second 
    /// list of the output.
    ///
    /// Example 2:
    /// Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
    /// Output: [[],[0,1,2,3]]
    /// Explanation: We can observe that since all 4 edges have equal weight, 
    /// choosing any 3 edges from the given 4 will yield an MST. Therefore 
    /// all 4 edges are pseudo-critical.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 100
    /// 2. 1 <= edges.length <= min(200, n * (n - 1) / 2)
    /// 3. edges[i].length == 3
    /// 4. 0 <= fromi < toi < n
    /// 5. 1 <= weighti <= 1000
    /// 6. All pairs (fromi, toi) are distinct.
    /// </summary>
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges);

    /// <summary>
    /// Leet code #1494. Parallel Courses II
    ///
    /// Hard
    ///
    /// Given the integer n representing the number of courses at some 
    /// university labeled from 1 to n, and the array dependencies where 
    /// dependencies[i] = [xi, yi]  represents a prerequisite relationship, 
    /// that is, the course xi must be taken before the course yi.  Also, 
    /// you are given the integer k.
    /// 
    /// In one semester you can take at most k courses as long as you have 
    /// taken all the prerequisites for the courses you are taking.
    ///
    /// Return the minimum number of semesters to take all courses. It is 
    /// guaranteed that you can take all courses in some way.
    ///
    /// Example 1:
    /// Input: n = 4, dependencies = [[2,1],[3,1],[1,4]], k = 2
    /// Output: 3 
    /// Explanation: The figure above represents the given graph. In this 
    /// case we can take courses 2 and 3 in the first semester, then take 
    /// course 1 in the second semester and finally take course 4 in the 
    /// third semester.
    /// 
    /// Example 2:
    /// Input: n = 5, dependencies = [[2,1],[3,1],[4,1],[1,5]], k = 2
    /// Output: 4 
    /// Explanation: The figure above represents the given graph. In this 
    /// case one optimal way to take all courses is: take courses 2 and 3 
    /// in the first semester and take course 4 in the second semester, then 
    /// take course 1 in the third semester and finally take course 5 in the 
    /// fourth semester.
    ///
    /// Example 3:
    /// Input: n = 11, dependencies = [], k = 2
    /// Output: 6
    /// Constraints:
    /// 1. 1 <= n <= 15 
    /// 2. 1 <= k <= n
    /// 3. 0 <= dependencies.length <= n * (n-1) / 2
    /// 4. dependencies[i].length == 2
    /// 5. 1 <= xi, yi <= n
    /// 6. xi != yi
    /// 7. All prerequisite relationships are distinct, that is, 
    ///    dependencies[i] != dependencies[j].
    /// 8. The given graph is a directed acyclic graph.
    /// </summary>
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k);

    /// <summary>
    /// Leet code #1514. Path with Maximum Probability
    /// 
    /// Medium
    ///
    /// You are given an undirected weighted graph of n nodes (0-indexed), 
    /// represented by an edge list where edges[i] = [a, b] is an undirected 
    /// edge connecting the nodes a and b with a probability of success of 
    /// traversing that edge succProb[i].
    ///
    /// Given two nodes start and end, find the path with the maximum 
    /// probability of success to go from start to end and return its success 
    /// probability.
    ///
    /// If there is no path from start to end, return 0. Your answer will 
    /// be accepted if it differs from the correct answer by at most 1e-5.
    ///
    ///
    /// Example 1:
    /// Input: n = 3, edges = [[0,1],[1,2],[0,2]], 
    /// succProb = [0.5,0.5,0.2], start = 0, end = 2
    /// Output: 0.25000
    /// Explanation: There are two paths from start to end, one having a 
    /// probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
    ///
    /// Example 2:
    /// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], 
    /// start = 0, end = 2
    /// Output: 0.30000
    ///
    /// Example 3:
    /// Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
    /// Output: 0.00000
    /// Explanation: There is no path between 0 and 2.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^4
    /// 2. 0 <= start, end < n
    /// 3. start != end
    /// 4. 0 <= a, b < n
    /// 5. a != b
    /// 6. 0 <= succProb.length == edges.length <= 2*10^4
    /// 7. 0 <= succProb[i] <= 1
    /// 8. There is at most one edge between every two nodes.
    /// </summary>
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end);

    /// <summary>
    /// Leet code #1548. The Most Similar Path in a Graph
    /// 
    /// Hard
    ///
    /// We have n cities and m bi-directional roads where roads[i] = [ai, bi] 
    /// connects city ai with city bi. Each city has a name consisting of 
    /// exactly 3 upper-case English letters given in the string array names. 
    /// Starting at any city x, you can reach any city y where y != x (i.e. 
    /// the cities and the roads are forming an undirected connected graph).
    ///
    /// You will be given a string array targetPath. You should find a path 
    /// in the graph of the same length and with the minimum edit distance 
    /// to targetPath.
    ///
    /// You need to return the order of the nodes in the path with the 
    /// minimum edit distance, The path should be of the same length of 
    /// targetPath and should be valid (i.e. there should be a direct road 
    /// between ans[i] and ans[i + 1]). If there are multiple answers return 
    /// any one of them.
    ///
    /// Follow-up: If each node can be visited only once in the path, What 
    /// should you change in your solution?
    /// 
    /// Example 1:
    /// Input: n = 5, roads = [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]], names = 
    /// ["ATL","PEK","LAX","DXB","HND"], targetPath = ["ATL","DXB","HND","LAX"]
    /// Output: [0,2,4,2]
    /// Explanation: [0,2,4,2], [0,3,0,2] and [0,3,1,2] are accepted answers.
    /// [0,2,4,2] is equivalent to ["ATL","LAX","HND","LAX"] which has edit 
    /// distance = 1 with targetPath.
    /// [0,3,0,2] is equivalent to ["ATL","DXB","ATL","LAX"] which has edit 
    /// distance = 1 with targetPath.
    /// [0,3,1,2] is equivalent to ["ATL","DXB","PEK","LAX"] which has edit 
    /// distance = 1 with targetPath.
    ///
    /// Example 2:
    /// Input: n = 4, roads = [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]], names = 
    /// ["ATL","PEK","LAX","DXB"], targetPath = ["ABC","DEF","GHI","JKL","MNO",
    /// "PQR","STU","VWX"]
    /// Output: [0,1,0,1,0,1,0,1]
    /// Explanation: Any path in this graph has edit distance = 8 with 
    /// targetPath.
    ///
    /// Example 3:
    /// Input: n = 6, roads = [[0,1],[1,2],[2,3],[3,4],[4,5]], names = 
    /// ["ATL","PEK","LAX","ATL","DXB","HND"], targetPath = ["ATL","DXB","HND",
    /// "DXB","ATL","LAX","PEK"]
    /// Output: [3,4,5,4,3,2,1]
    /// Explanation: [3,4,5,4,3,2,1] is the only path with edit distance = 0 
    /// with targetPath.
    /// It's equivalent to ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
    ///
    /// Constraints:
    /// 1. 2 <= n <= 100
    /// 2. m == roads.length
    /// 3. n - 1 <= m <= (n * (n - 1) / 2)
    /// 4. 0 <= ai, bi <= n - 1
    /// 5. ai != bi 
    /// 6. The graph is guaranteed to be connected and each pair of nodes may 
    ///    have at most one direct road.
    /// 7. names.length == n
    /// 8. names[i].length == 3
    /// 9. names[i] consists of upper-case English letters.
    /// 10. There can be two cities with the same name.
    /// 11. 1 <= targetPath.length <= 100
    /// 12. targetPath[i].length == 3
    /// 13. targetPath[i] consists of upper-case English letters.
    /// </summary>
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath);

    /// <summary>
    /// Leet code #1557. Minimum Number of Vertices to Reach All Nodes
    /// 
    /// Medium
    ///
    /// Given a directed acyclic graph, with n vertices numbered from 0 to 
    /// n-1, and an array edges where edges[i] = [fromi, toi] represents 
    /// a directed edge from node fromi to node toi.
    /// Find the smallest set of vertices from which all nodes in the graph 
    /// are reachable. It's guaranteed that a unique solution exists.
    /// 
    /// Notice that you can return the vertices in any order.
    /// 
    /// Example 1:
    /// Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
    /// Output: [0,3]
    /// Explanation: It's not possible to reach all the nodes from a 
    /// single vertex. From 0 we can reach [0,1,2,5]. From 3 we can 
    /// reach [3,4,2,5]. So we output [0,3].
    ///
    /// Example 2:
    /// Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
    /// Output: [0,2,3]
    /// Explanation: Notice that vertices 0, 3 and 2 are not reachable from 
    /// any other node, so we must include them. Also any of these vertices 
    /// can reach nodes 1 and 4.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. 1 <= edges.length <= min(10^5, n * (n - 1) / 2)
    /// 3. edges[i].length == 2
    /// 3. 0 <= fromi, toi < n
    /// 4. All pairs (fromi, toi) are distinct.
    /// </summary>
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges);

    /// <summary>
    /// Leet code #1559. Detect Cycles in 2D Grid
    /// 
    /// Hard
    ///
    /// Given a 2D array of characters grid of size m x n, you need to 
    /// find if there exists any cycle consisting of the same value in 
    /// grid.
    /// A cycle is a path of length 4 or more in the grid that starts and 
    /// ends at the same cell. From a given cell, you can move to one of 
    /// the cells adjacent to it - in one of the four directions (up, down, 
    /// left, or right), if it has the same value of the current cell.
    ///
    /// Also, you cannot move to the cell that you visited in your last 
    /// move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid 
    /// because from (1, 2) we visited (1, 1) which was the last visited cell.
    ///
    /// Return true if any cycle of the same value exists in grid, otherwise, 
    /// return false.
    /// 
    /// Example 1:
    /// Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],
    /// ["a","a","a","a"]]
    /// Output: true
    /// Explanation: There are two valid cycles shown in different colors in 
    /// the image below:
    ///
    /// Example 2:
    /// Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],
    /// ["f","c","c","c"]]
    /// Output: true
    /// Explanation: There is only one valid cycle highlighted in the image 
    /// below:
    ///
    /// Example 3:
    /// Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
    /// Output: false
    /// Constraints:
    /// 1. m == grid.length
    /// 2. n == grid[i].length
    /// 3. 1 <= m <= 500
    /// 4. 1 <= n <= 500
    /// 5. grid consists only of lowercase English letters.
    /// </summary>
    bool containsCycle(vector<vector<char>>& grid);

    /// <summary>
    /// Leet code #1568. Minimum Number of Days to Disconnect Island
    /// </summary>
    int minDays_CountIsland(vector<vector<int>> grid);

    /// <summary>
    /// Leet code #1568. Minimum Number of Days to Disconnect Island
    /// 
    /// Medium
    ///
    /// Given a 2D grid consisting of 1s (land) and 0s (water).  An island is 
    /// a maximal 4-directionally (horizontal or vertical) connected group of 
    /// 1s.
    ///
    /// The grid is said to be connected if we have exactly one island, 
    /// otherwise is said disconnected.
    ///
    /// In one day, we are allowed to change any single land cell (1) into a 
    /// water cell (0).
    ///
    /// Return the minimum number of days to disconnect the grid.
    /// 
    /// Example 1:
    /// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
    /// Output: 2
    /// Explanation: We need at least 2 days to get a disconnected grid.
    /// Change land grid[1][1] and grid[0][2] to water and get 2 disconnected 
    /// island.
    ///
    /// Example 2:
    /// Input: grid = [[1,1]]
    /// Output: 2
    /// Explanation: Grid of full water is also disconnected ([[1,1]] -> 
    /// [[0,0]]), 0 islands.
    ///
    /// Example 3:
    /// Input: grid = [[1,0,1,0]]
    /// Output: 0
    ///
    /// Example 4:
    /// Input: grid = [[1,1,0,1,1],
    ///           [1,1,1,1,1],
    ///           [1,1,0,1,1],
    ///           [1,1,0,1,1]]
    /// Output: 1
    ///
    /// Example 5:
    /// Input: grid = [[1,1,0,1,1],
    ///           [1,1,1,1,1],
    ///           [1,1,0,1,1],
    ///           [1,1,1,1,1]]
    /// Output: 2
    ///
    /// Constraints:
    /// 1. 1 <= grid.length, grid[i].length <= 30
    /// 2. grid[i][j] is 0 or 1.
    /// </summary>
    int minDays(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #1584. Min Cost to Connect All Points
    /// 
    /// Medium
    ///
    /// You are given an array points representing integer coordinates of 
    /// some points on a 2D-plane, where points[i] = [xi, yi].
    ///
    /// The cost of connecting two points [xi, yi] and [xj, yj] is the 
    /// manhattan distance between them: |xi - xj| + |yi - yj|, where 
    /// |val| denotes the absolute value of val.
    ///
    /// Return the minimum cost to make all points connected. All points 
    /// are connected if there is exactly one simple path between any two 
    /// points.
    /// 
    /// Example 1:
    /// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    /// Output: 20
    /// Explanation:
    /// We can connect the points as shown above to get the minimum cost of 20.
    /// Notice that there is a unique path between every pair of points.
    ///
    /// Example 2:
    /// Input: points = [[3,12],[-2,5],[-4,1]]
    /// Output: 18
    ///
    /// Example 3:
    /// Input: points = [[0,0],[1,1],[1,0],[-1,1]]
    /// Output: 4
    ///
    /// Example 4:
    /// Input: points = [[-1000000,-1000000],[1000000,1000000]]
    /// Output: 4000000
    ///
    /// Example 5:
    /// Input: points = [[0,0]]
    /// Output: 0
    /// Constraints:
    /// 1. 1 <= points.length <= 1000
    /// 2. -106 <= xi, yi <= 106
    /// 3. All pairs (xi, yi) are distinct.
    /// </summary>
    int minCostConnectPoints(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1579. Remove Max Number of Edges to Keep Graph Fully 
    ///                  Traversable
    /// </summary>
    int maxNumEdgesToRemove(vector<vector<int>>& edges, vector<int>& parent, int &count, int id);

    /// <summary>
    /// Leet code #1579. Remove Max Number of Edges to Keep Graph Fully 
    ///                  Traversable
    /// 
    /// Hard
    ///
    /// Alice and Bob have an undirected graph of n nodes and 3 types of edges:
    ///
    /// Type 1: Can be traversed by Alice only.
    /// Type 2: Can be traversed by Bob only.
    /// Type 3: Can by traversed by both Alice and Bob.
    /// Given an array edges where edges[i] = [typei, ui, vi] represents a 
    /// bidirectional edge of type typei between nodes ui and vi, find the maximum 
    /// number of edges you can remove so that after removing the edges, the graph 
    /// can still be fully traversed by both Alice and Bob. The graph is fully 
    /// traversed by Alice and Bob if starting from any node, they can reach all 
    /// other nodes.
    ///
    /// Return the maximum number of edges you can remove, or return -1 if it's 
    /// impossible for the graph to be fully traversed by Alice and Bob.
    ///
    /// Example 1:
    /// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
    /// Output: 2
    /// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will 
    /// still be fully traversable by Alice and Bob. Removing any additional edge 
    /// will not make it so. So the maximum number of edges we can remove is 2.
    ///
    /// Example 2:
    /// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
    /// Output: 0
    /// Explanation: Notice that removing any edge will not make the graph fully 
    /// traversable by Alice and Bob.
    ///
    /// Example 3:
    /// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
    /// Output: -1
    /// Explanation: In the current graph, Alice cannot reach node 4 from the 
    /// other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to 
    /// make the graph fully traversable.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. 1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
    /// 3. edges[i].length == 3
    /// 4. 1 <= edges[i][0] <= 3
    /// 5. 1 <= edges[i][1] < edges[i][2] <= n
    /// 6. All tuples (typei, ui, vi) are distinct.
    /// </summary>
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges);

    /// <summary>
    /// Leet code #1575. Count All Possible Routes
    /// 
    /// Hard
    ///
    /// You are given an array of distinct positive integers locations where 
    /// locations[i] represents the position of city i. You are also given 
    /// integers start, finish and fuel representing the starting city, 
    /// ending city, and the initial amount of fuel you have, respectively.
    ///
    /// At each step, if you are at city i, you can pick any city j such 
    /// that j != i and 0 <= j < locations.length and move to city j. Moving 
    /// from city i to city j reduces the amount of fuel you have by 
    /// |locations[i] - locations[j]|. Please notice that |x| denotes the 
    /// absolute value of x.
    ///
    /// Notice that fuel cannot become negative at any point in time, and 
    /// that you are allowed to visit any city more than once (including 
    /// start and finish).
    ///
    /// Return the count of all possible routes from start to finish.
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
    /// Output: 4
    /// Explanation: The following are all possible routes, each uses 5 
    /// units of fuel:
    /// 1 -> 3
    /// 1 -> 2 -> 3
    /// 1 -> 4 -> 3
    /// 1 -> 4 -> 2 -> 3
    ///
    /// Example 2:
    /// Input: locations = [4,3,1], start = 1, finish = 0, fuel = 6
    /// Output: 5
    /// Explanation: The following are all possible routes:
    /// 1 -> 0, used fuel = 1
    /// 1 -> 2 -> 0, used fuel = 5
    /// 1 -> 2 -> 1 -> 0, used fuel = 5
    /// 1 -> 0 -> 1 -> 0, used fuel = 3
    /// 1 -> 0 -> 1 -> 0 -> 1 -> 0, used fuel = 5
    ///
    /// Example 3:
    /// Input: locations = [5,2,1], start = 0, finish = 2, fuel = 3
    /// Output: 0
    /// Explanation: It's impossible to get from 0 to 2 using only 3 units of 
    /// fuel since the shortest route needs 4 units of fuel.
    ///
    /// Example 4:
    /// Input: locations = [2,1,5], start = 0, finish = 0, fuel = 3
    /// Output: 2
    /// Explanation: There are two possible routes, 0 and 0 -> 1 -> 0.
    ///
    /// Example 5:
    /// Input: locations = [1,2,3], start = 0, finish = 2, fuel = 40
    /// Output: 615088286
    /// Explanation: The total number of possible routes is 2615088300. Taking 
    /// this number modulo 10^9 + 7 gives us 615088286.
    /// 
    /// Constraints:
    /// 1. 2 <= locations.length <= 100
    /// 2. 1 <= locations[i] <= 10^9
    /// 3. All integers in locations are distinct.
    /// 4. 0 <= start, finish < locations.length
    /// 5. 1 <= fuel <= 200
    /// </summary>
    int countRoutes(vector<int>& locations, int start, int finish, int fuel);

    /// <summary>
    /// Leet code #1591. Strange Printer II
    /// 
    /// Hard
    ///
    /// There is a strange printer with the following two special requirements:
    /// 
    /// On each turn, the printer will print a solid rectangular pattern of a 
    /// single color on the grid. This will cover up the existing colors in the 
    /// rectangle.
    /// Once the printer has used a color for the above operation, the same 
    /// color cannot be used again.
    /// You are given a m x n matrix targetGrid, where targetGrid[row][col] is 
    /// the color in the position (row, col) of the grid.
    ///
    /// Return true if it is possible to print the matrix targetGrid, 
    /// otherwise, return false.
    /// 
    /// 
    /// Example 1:
    /// 
    /// Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
    /// Output: true
    ///
    /// Example 2:
    /// Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
    /// Output: true
    ///
    /// Example 3:
    /// Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
    /// Output: false
    /// Explanation: It is impossible to form targetGrid because it is not 
    /// allowed to print the same color in different turns.
    ///
    /// Example 4:
    /// Input: targetGrid = [[1,1,1],[3,1,3]]
    /// Output: false
    ///
    /// Constraints:
    /// 1. m == targetGrid.length
    /// 2. n == targetGrid[i].length
    /// 3. 1 <= m, n <= 60
    /// 4. 1 <= targetGrid[row][col] <= 60
    /// </summary>
    bool isPrintable(vector<vector<int>>& targetGrid);

    /// <summary>
    /// Leet code #1615. Maximal Network Rank
    /// 
    /// Medium
    ///
    /// There is an infrastructure of n cities with some number of roads 
    /// connecting these cities. Each roads[i] = [ai, bi] indicates that 
    /// there is a bidirectional road between cities ai and bi.
    ///
    /// The network rank of two different cities is defined as the total 
    /// number of directly connected roads to either city. If a road is 
    /// directly connected to both cities, it is only counted once.
    ///
    /// The maximal network rank of the infrastructure is the maximum network 
    /// rank of all pairs of different cities.
    ///
    /// Given the integer n and the array roads, return the maximal network 
    /// rank of the entire infrastructure.
    ///
    /// Example 1:
    /// Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
    /// Output: 4
    /// Explanation: The network rank of cities 0 and 1 is 4 as there are 4 
    /// roads that are connected to either 0 or 1. The road between 0 and 1 
    /// is only counted once.
    ///
    /// Example 2:
    /// Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
    /// Output: 5
    /// Explanation: There are 5 roads that are connected to cities 1 or 2.
    ///
    /// Example 3:
    /// Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
    /// Output: 5
    /// Explanation: The network rank of 2 and 5 is 5. Notice that all the 
    /// cities do not have to be connected.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 100
    /// 2. 0 <= roads.length <= n * (n - 1) / 2
    /// 3. roads[i].length == 2
    /// 4. 0 <= ai, bi <= n-1
    /// 5. a[i] != b[i]
    /// 6. Each pair of cities has at most one road connecting them.
    /// </summary>
    int maximalNetworkRank(int n, vector<vector<int>>& roads);

    /// <summary>
    /// Leet code #1617. Count Subtrees With Max Distance Between Cities
    /// 
    /// Hard
    ///
    /// There are n cities numbered from 1 to n. You are given an array edges 
    /// of size n-1, where edges[i] = [ui, vi] represents a bidirectional 
    /// edge between cities ui and vi. There exists a unique path between 
    /// each pair of cities. In other words, the cities form a tree.
    /// A subtree is a subset of cities where every city is reachable from 
    /// every other city in the subset, where the path between each pair 
    /// passes through only the cities from the subset. Two subtrees 
    /// are different if there is a city in one subtree that is not present 
    /// in the other.
    ///
    /// For each d from 1 to n-1, find the number of subtrees in which the 
    /// maximum distance between any two cities in the subtree is equal to d.
    ///
    /// Return an array of size n-1 where the dth element (1-indexed) is the 
    /// number of subtrees in which the maximum distance between any two 
    /// cities is equal to d.
    ///
    /// Notice that the distance between the two cities is the number of 
    /// edges in the path between them.
    /// 
    /// Example 1:
    /// Input: n = 4, edges = [[1,2],[2,3],[2,4]]
    /// Output: [3,4,0]
    /// Explanation:
    /// The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance 
    /// of 1.
    /// The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} 
    /// have a max distance of 2.
    /// No subtree has two nodes where the max distance between them is 3.
    ///
    /// Example 2:
    /// Input: n = 2, edges = [[1,2]]
    /// Output: [1]
    ///
    /// Example 3:
    /// Input: n = 3, edges = [[1,2],[2,3]]
    /// Output: [2,1]
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 15
    /// 2. edges.length == n-1
    /// 3. edges[i].length == 2
    /// 4. 1 <= ui, vi <= n
    /// 5. All pairs (ui, vi) are distinct.
    /// </summary>
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges);

    /// <summary>
    /// Leet code #1627. Graph Connectivity With Threshold
    /// 
    /// Hard
    ///
    /// We have n cities labeled from 1 to n. Two different cities with 
    /// labels x and y are directly connected by a bidirectional road if 
    /// and only if x and y share a common divisor strictly greater than 
    /// some threshold. More formally, cities with labels x and y have a 
    /// road between them if there exists an integer z such that all of the
    /// following are true:
    /// x % z == 0,
    /// y % z == 0, and
    /// z > threshold.
    /// Given the two integers, n and threshold, and an array of queries, 
    /// you must determine for each queries[i] = [ai, bi] if cities ai and 
    /// bi are connected (i.e. there is some path between them).
    /// 
    /// Return an array answer, where answer.length == queries.length and 
    /// answer[i] is true if for the ith query, there is a path between ai 
    /// and bi, or answer[i] is false if there is no path.
    ///
    /// Example 1:
    /// Input: n = 6, threshold = 2, queries = [[1,4],[2,5],[3,6]]
    /// Output: [false,false,true]
    /// Explanation: The divisors for each number:
    /// 1:   1
    /// 2:   1, 2
    /// 3:   1, 3
    /// 4:   1, 2, 4
    /// 5:   1, 5
    /// 6:   1, 2, 3, 6
    /// Using the underlined divisors above the threshold, only cities 3 and 
    /// 6 share a common divisor, so they are the only ones directly 
    /// connected. The result of each query:
    /// [1,4]   1 is not connected to 4
    /// [2,5]   2 is not connected to 5
    /// [3,6]   3 is connected to 6 through path 3--6
    ///
    /// Example 2:
    /// Input: n = 6, threshold = 0, queries = [[4,5],[3,4],[3,2],[2,6],[1,3]]
    /// Output: [true,true,true,true,true]
    /// Explanation: The divisors for each number are the same as the previous 
    /// example. However, since the threshold is 0,
    /// all divisors can be used. Since all numbers share 1 as a divisor, all 
    /// cities are connected.
    ///
    /// Example 3:
    /// Input: n = 5, threshold = 1, queries = [[4,5],[4,5],[3,2],[2,3],[3,4]]
    /// Output: [false,false,false,false,false]
    /// Explanation: Only cities 2 and 4 share a common divisor 2 which is 
    /// strictly greater than the threshold 1, so they are the only ones 
    /// directly connected.
    /// Please notice that there can be multiple queries for the same pair of 
    /// nodes [x, y], and that the query [x, y] is equivalent to the 
    /// query [y, x].
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^4
    /// 2. 0 <= threshold <= n
    /// 3. 1 <= queries.length <= 10^5
    /// 4. queries[i].length == 2
    /// 5. 1 <= a[i], b[i] <= cities
    /// 6. a[i] != b[i]
    /// </summary>
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code #1631. Path With Minimum Effort
    /// 
    /// Medium
    ///
    /// You are a hiker preparing for an upcoming hike. You are given heights, 
    /// a 2D array of size rows x columns, where heights[row][col] represents 
    /// the height of cell (row, col). You are situated in the top-left cell, 
    /// (0, 0), and you hope to travel to the bottom-right cell, 
    /// (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or 
    /// right, and you wish to find a route that requires the minimum effort.
    ///
    /// A route's effort is the maximum absolute difference in heights between 
    /// two consecutive cells of the route.
    ///
    /// Return the minimum effort required to travel from the top-left cell to 
    /// the bottom-right cell.
    /// 
    /// Example 1:
    /// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
    /// Output: 2
    /// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference 
    /// of 2 in consecutive cells.
    /// This is better than the route of [1,2,2,2,5], where the maximum absolute 
    /// difference is 3.
    ///
    /// Example 2:
    /// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
    /// Output: 1
    /// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference 
    /// of 1 in consecutive cells, which is better than route [1,3,5,3,5].
    ///
    /// Example 3:
    /// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],
    /// [1,1,1,2,1]]
    /// Output: 0
    /// Explanation: This route does not require any effort.
    ///
    /// Constraints:
    /// 1. rows == heights.length
    /// 2. columns == heights[i].length
    /// 3. 1 <= rows, columns <= 100
    /// 4. 1 <= heights[i][j] <= 10^6
    /// </summary>
    int minimumEffortPath(vector<vector<int>>& heights);

    /// <summary>
    /// Leet code #1654. Minimum Jumps to Reach Home
    /// 
    /// Medium
    ///
    /// A certain bug's home is on the x-axis at position x. Help them get there 
    /// from position 0.
    ///
    /// The bug jumps according to the following rules:
    ///
    /// It can jump exactly a positions forward (to the right).
    /// It can jump exactly b positions backward (to the left).
    /// It cannot jump backward twice in a row.
    /// It cannot jump to any forbidden positions.
    /// The bug may jump forward beyond its home, but it cannot jump to positions 
    /// numbered with negative integers.
    ///
    /// Given an array of integers forbidden, where forbidden[i] means that the 
    /// bug cannot jump to the position forbidden[i], and integers a, b, and x, 
    /// return the minimum number of jumps needed for the bug to reach its home. 
    /// If there is no possible sequence of jumps that lands the bug on position 
    /// x, return -1.
    /// 
    /// Example 1:
    /// Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
    /// Output: 3
    /// Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
    ///
    /// Example 2:
    /// Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
    /// Output: -1
    /// Example 3:
    ///
    /// Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
    /// Output: 2
    /// Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7) 
    /// will get the bug home.
    /// 
    /// Constraints:
    /// 1. 1 <= forbidden.length <= 1000
    /// 2. 1 <= a, b, forbidden[i] <= 2000
    /// 3. 0 <= x <= 2000
    /// 4. All the elements in forbidden are distinct.
    /// 5. Position x is not forbidden.
    /// </summary>
    int minimumJumps(vector<int>& forbidden, int a, int b, int x);

    /// <summary>
    /// Leet code #1697. Checking Existence of Edge Length Limited Paths
    /// 
    /// Hard
    /// 
    /// An undirected graph of n nodes is defined by edgeList, where 
    /// edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and 
    /// vi with distance disi. Note that there may be multiple edges 
    /// between two nodes.
    ///
    /// Given an array queries, where queries[j] = [pj, qj, limitj], 
    /// your task is to determine for each queries[j] whether there is a 
    /// path between pj and qj such that each edge on the path has a 
    /// distance strictly less than limitj .
    ///
    /// Return a boolean array answer, where answer.length == queries.length 
    /// and the jth value of answer is true if there is a path for queries[j] 
    /// is true, and false otherwise.
    ///
    /// Example 1:
    /// Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], 
    /// queries = [[0,1,2],[0,2,5]]
    /// Output: [false,true]
    /// Explanation: The above figure shows the given graph. Note that 
    /// there are two overlapping edges between 0 and 1 with distances 2 
    /// and 16.
    /// For the first query, between 0 and 1 there is no path where each 
    /// distance is less than 2, thus we return false for this query.
    /// For the second query, there is a path (0 -> 1 -> 2) of two edges with 
    /// distances less than 5, thus we return true for this query.
    ///
    /// Example 2:
    /// Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], 
    /// queries = [[0,4,14],[1,4,13]]
    /// Output: [true,false]
    /// Exaplanation: The above figure shows the given graph.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. 1 <= edgeList.length, queries.length <= 10^5
    /// 3. edgeList[i].length == 3
    /// 4. queries[j].length == 3
    /// 5. 0 <= ui, vi, pj, qj <= n - 1
    /// 6. ui != vi
    /// 7. pj != qj
    /// 8. 1 <= disi, limitj <= 10^9
    /// 9. There may be multiple edges between two nodes.
    /// </summary>
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code 1722. Minimize Hamming Distance After Swap Operations
    /// 
    /// Medium
    /// 
    /// You are given two integer arrays, source and target, both of length n. 
    /// You are also given an array allowedSwaps where each allowedSwaps[i] = 
    /// [ai, bi] indicates that you are allowed to swap the elements at index 
    /// ai and index bi (0-indexed) of array source. Note that you can swap 
    /// elements at a specific pair of indices multiple times and in any order.
    ///
    /// The Hamming distance of two arrays of the same length, source and 
    /// target, is the number of positions where the elements are different. 
    /// Formally, it is the number of indices i for 0 <= i <= n-1 where 
    /// source[i] != target[i] (0-indexed).
    ///
    /// Return the minimum Hamming distance of source and target after 
    /// performing any amount of swap operations on array source.
    /// 
    /// Example 1:
    /// Input: source = [1,2,3,4], target = [2,1,4,5], 
    /// allowedSwaps = [[0,1],[2,3]]
    /// Output: 1
    /// Explanation: source can be transformed the following way:
    /// - Swap indices 0 and 1: source = [2,1,3,4]
    /// - Swap indices 2 and 3: source = [2,1,4,3]
    /// The Hamming distance of source and target is 1 as they differ in 1 
    /// position: index 3.
    ///
    /// Example 2:
    /// Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
    /// Output: 2
    /// Explanation: There are no allowed swaps.
    /// The Hamming distance of source and target is 2 as they differ in 2 
    /// positions: index 1 and index 2.
    ///
    /// Example 3:
    /// Input: source = [5,1,2,4,3], target = [1,5,4,2,3], 
    /// allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
    /// Output: 0
    /// Constraints:
    /// 1. n == source.length == target.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= source[i], target[i] <= 10^5
    /// 4. 0 <= allowedSwaps.length <= 10^5
    /// 5. allowedSwaps[i].length == 2
    /// 6. 0 <= ai, bi <= n - 1
    /// 7. ai != bi
    /// </summary>
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps);

    /// <summary>
    /// Leet code 1719. Number Of Ways To Reconstruct A Tree
    /// 
    /// Hard
    /// 
    /// You are given an array pairs, where pairs[i] = [xi, yi], and:
    /// There are no duplicates.
    /// xi < yi
    /// Let ways be the number of rooted trees that satisfy the following 
    /// conditions:
    /// 
    /// The tree consists of nodes whose values appeared in pairs.
    /// A pair [xi, yi] exists in pairs if and only if xi is an ancestor 
    /// of yi or yi is an ancestor of xi.
    /// Note: the tree does not have to be a binary tree.
    /// Two ways are considered to be different if there is at least one 
    /// node that has different parents in both ways.
    /// 
    /// Return:
    /// 0 if ways == 0
    /// 1 if ways == 1
    /// 2 if ways > 1
    /// A rooted tree is a tree that has a single root node, and all 
    /// edges are oriented to be outgoing from the root.
    ///
    /// An ancestor of a node is any node on the path from the root to that 
    /// node (excluding the node itself). The root has no ancestors.
    /// 
    /// Example 1:
    /// Input: pairs = [[1,2],[2,3]]
    /// Output: 1
    /// Explanation: There is exactly one valid rooted tree, which is shown 
    /// in the above figure.
    ///
    /// Example 2:
    /// Input: pairs = [[1,2],[2,3],[1,3]]
    /// Output: 2
    /// Explanation: There are multiple valid rooted trees. Three of them 
    /// are shown in the above figures.
    ///
    /// Example 3:
    /// Input: pairs = [[1,2],[2,3],[2,4],[1,5]]
    /// Output: 0
    /// Explanation: There are no valid rooted trees.
    /// 
    /// Constraints:
    /// 1. 1 <= pairs.length <= 105
    /// 2. 1 <= xi < yi <= 500
    /// 3. The elements in pairs are unique.
    /// </summary>
    int checkWays(vector<vector<int>>& pairs);
#pragma endregion
};
#endif  // LeetCodeGraph_H

