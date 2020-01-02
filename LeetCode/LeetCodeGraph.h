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

#pragma endregion  
};
#endif  // LeetCodeGraph_H

